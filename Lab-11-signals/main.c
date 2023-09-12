#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "signal.h"

static void sighandler(int signalNum) {
  if (signalNum == SIGINT) {
    char *message = "Program exited from SIGINT.\n";
    int newfile = open("output.txt", O_WRONLY | O_APPEND | O_CREAT, 0700);
    if (newfile == -1) {
      printf("%s", strerror(errno));
      exit(errno);
      exit(0);
    }
    write(newfile, message, strlen(message) );
    close(newfile);
    exit(0);
  }
  else if (signalNum == SIGUSR1) {
    printf("Parent PID: %d\n", getppid());
    // type in second terminal:
    // kill -SIGUSR1, PID
  }
}

int main() {
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);

  while (1) {
    printf("Running process %d\n", getpid());
    sleep(1);
  }
}
