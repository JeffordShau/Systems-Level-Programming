#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "control.h"

int main() {
  int key = 8917651;
  char *fileName = "output.txt";
  struct sembuf operation;
  operation.sem_num = 0;
  operation.sem_flg = IPC_NOWAIT;

  // create file, access shared memory and semaphore
  int semID = semget(key, 1, 0);
  if (semID == -1) {
    createMem(key, fileName);
  }
  int shmID = shmget(key, sizeof(int), 0);
  // get semaphore value
  operation.sem_op = -1;
  int semVal = semop(semID, &operation, 1);

  // if semaphore value is 1, wait
  if (semVal == -1) {
    printf("Waiting for resources...\n");
    while (semVal == -1) {
        operation.sem_op = -1;
        semVal = semop(semID, &operation, 1);
      }
  }

  // attach shared memory block to pointer
  int *dataBuff = shmat(shmID, NULL, 0);
  if (dataBuff == NULL) {
    printf("%s\n", strerror(errno));
  }
  // if there is last line, print it
  else if (*dataBuff != 0) {
    printf("Previous input: ");
    viewLastLine(fileName, *dataBuff);
  }

  // prompt user input
  char* input = calloc(1, 256 * sizeof(char));
  printf("Your input: ");
  fgets(input, 256, stdin);
  writeToFile(fileName, input, strlen(input));
  *dataBuff =  strlen(input);
  shmdt(dataBuff);

  // free program
  operation.sem_op = 1;
  semop(semID, &operation, 1);
  free(input);
}
