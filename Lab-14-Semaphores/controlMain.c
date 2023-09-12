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

int main(int argc, char *argv[]) {
  int key = 8917651;
  char *temp = "temp.txt";
  char *fileName = "output.txt";
  union semun data;
  struct sembuf operation;
  operation.sem_num = 0;

  if (strcmp(argv[1], "-create") == 0) {
    int semID = semget(key, 1, 0);
    if (semID == -1) {
      createMem(key, fileName);
      exit(0);
    }
    int semVal = semctl(semID, 0, GETVAL);
    if (semVal == 0) {
      printf("Waiting for resources...\n");
      while (semVal == 0) {
        semVal = semctl(semID, 0, GETVAL);
      }
      data.val = 0;
      semVal = semctl(semID, 0, SETVAL, data);
    }
    createMem(key, fileName);
    operation.sem_op = 1;
    semop(semID, &operation, 1);
  }

  else if (strcmp(argv[1], "-remove") == 0) {
    int semID = semget(key, 1, 0);
    if (semID == -1) {
      createMem(key, fileName);
      exit(0);
    }
    int semVal = semctl(semID, 0, GETVAL);
    if (semVal == 0) {
      printf("Waiting for resources...\n");
      while (semVal == 0) {
        semVal = semctl(semID, 0, GETVAL);
      }
      data.val = 0;
      semVal = semctl(semID, 0, SETVAL, data);
    }
    removeMem(key, fileName);
    operation.sem_op = 1;
    semop(semID, &operation, 1);
  }

  else if (strcmp(argv[1], "-view") == 0) {
    viewMem(fileName);
  }
}
