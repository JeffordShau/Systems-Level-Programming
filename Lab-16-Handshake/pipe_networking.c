#include "pipe_networking.h"

/*=========================
  server_setup
  args:
  creates the WKP (upstream) and opens it, waiting for a
  connection.
  removes the WKP once a connection has been made
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_setup() {

  // creates WKP
  if (mkfifo(WKP, 0777) == -1) {
    printf("%s\n", strerror(errno));
    exit(errno);
  }

  // open read only end
  printf("waiting for connection...\n");
  // blocks until client connect to WKP
  int from_client = open(WKP, O_RDONLY);
  remove(WKP);
  return from_client;
}

/*=========================
  server_connect
  args: int from_client
  handles the subserver portion of the 3 way handshake
  returns the file descriptor for the downstream pipe.
  =========================*/
int server_connect(int from_client) {

  // reads PP name from client
  char buff[1025];
  read(from_client, buff, BUFFER_SIZE);
  printf("PP received from client\n");
  remove(WKP);

  // send secret message to client
  int to_client = open(buff, O_WRONLY);
  char message[10];
  strcat(message, "SECRET");
  write(to_client, message, strlen(message));
  printf("SYN_ACK sent to client\n");
  remove(WKP);

  // read response message from client
  read(from_client, buff, BUFFER_SIZE);
  printf("ACK received from client, %s\n", buff);

  while(1) {
    write(to_client, buff, strlen(buff));
    sleep(1);
  }

  return to_client;
}


/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  int from_client;
  int forkVal;

  // continous to accept clients
  while(1) {
    // waiting for client
    from_client = server_setup();
    // when connection esstablished, create subserver to handle client
    forkVal = fork();
    // if child
    if (forkVal == 0) {
      *to_client = server_connect(from_client);
      return from_client;
    }
    else {
        remove(WKP);
    }
    sleep(1);
  }

  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {

  // creates PP
  char pid[50];
  sprintf(pid, "%d", getpid());
  int file = mkfifo(pid, 0777);
  if (file == -1) {
    printf("%s\n", strerror(errno));
    exit(errno);
  }

  // connects to WKP
  *to_server = open(WKP, O_WRONLY);

  // sends PP name through WKP to server
  write(*to_server, pid, strlen(pid));
  printf("PP sent to server\n");
  remove(WKP);

  // blocks on connection to PP
  char buff[1025];
  int from_server = open(pid, O_RDONLY);
  if (from_server == -1) {
    printf("%s\n", strerror(errno));
    exit(errno);
  }
  read(from_server, buff, BUFFER_SIZE);
  printf("SYN_ACK received from server: %s\n", buff);

  // modify message
  strcat(buff, " MESSAGE!");

  // send ACK to server
  write(*to_server, buff, strlen(buff));
  printf("ACK sent to server\n");
  remove(pid);

  while(1) {
    read(from_server, buff, BUFFER_SIZE);
    printf("%s\n", buff);
  }

  return from_server;
}
