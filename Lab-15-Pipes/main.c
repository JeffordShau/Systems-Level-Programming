#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {

  // create named pipe
  mkfifo("namedPipe", 0777);

  // create unnamed pipes
  int fd[4][2];

  while (1) {
    // generate number of child processes
    srand(time(NULL));
    int totalChildren = rand() % 3 + 2;
    printf("NumChildren: %d\n", totalChildren);

    // create pipes for parent to child
    for (int i = 0; i < totalChildren; i++) {
      pipe(fd[i]);
    }

    // open named pipe for read and write
    int file = open("namedPipe", O_RDWR);

    // creating child processes and initializing childID
    int childID = -1;
    int forkVal = fork();
    if (forkVal == 0) {
      childID = 0;
    }
    for (int i = 0; i < totalChildren - 1; i++) {
      if (forkVal > 0) {
        forkVal = fork();
      }
      if (forkVal == 0 && childID == -1) {
        childID = i + 1;
      }
    }

    // child process
    if (forkVal == 0) {
      // allocate memory for buffers
      char *childMessage = calloc(256, sizeof(char));
      char *childReadBuff = calloc(256, sizeof(char));

      // reading from parent to child
      close(fd[childID][1]);
      read(fd[childID][0], childMessage, 256);
      close(fd[childID][0]);

      // sleep child
      srand(getpid());
      int sleepMicro = rand() % 3000000 + 1000000;
      printf("Child %d waiting.. %f microseconds\n", getpid(), sleepMicro / 1000000.0);
      usleep(sleepMicro);

      // toLower function
      for (int i = 0; i < strlen(childMessage); i++) {
        childMessage[i] = tolower(childMessage[i]);
      }

      // adding child pid
      sprintf(childReadBuff, "Result from process %d is '%s'", getpid(), childMessage);

      // writing from child to parent
      write(file, childReadBuff, strlen(childReadBuff));
      close(file);
      free(childReadBuff);
      free(childMessage);
      // stop child processes from continue looping
      exit(0);
    }

    // parent process
    else if (forkVal > 0) {
      // ask for user input
      printf("Enter a string: \n");
      char input[256];
      fgets(input, 256, stdin);
      input[strlen(input) - 1] = '\0';

      // writing from parent to child
      for (int i = 0; i < totalChildren; i++) {
        close(fd[i][0]);
        write(fd[i][1], input, strlen(input));
        close(fd[i][1]);
      }

      // allocate memory for buff
      char *parentReadBuff = calloc(256, sizeof(char));

      // reading from child to parentToChild
      for (int i = 0; i < totalChildren; i++) {
        read(file, parentReadBuff, 256);
        printf("%s\n", parentReadBuff);
      }
      close(file);
      free(parentReadBuff);
    }
  }
  return 0;
}
