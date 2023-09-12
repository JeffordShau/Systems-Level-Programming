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

int createMem(int key, char *fileName) {
  union semun data;
  // create the file
  int file = open(fileName, O_CREAT | O_TRUNC, 0644);
  if (file == -1) {
    printf("%s\n", strerror(errno));
  }
  // create the shared memory
  int shmID = shmget(key, sizeof(int), IPC_CREAT | 0644);
  if (shmID == -1) {
    printf("%s\n", strerror(errno));
  }
  // create the semaphore
  int semID = semget(key, 1, IPC_CREAT | 0644);
  if (semID == -1) {
    printf("%s\n", strerror(errno));
  }
  data.val = 1;
  semctl(semID, 0, SETVAL, data);
  close(file);
}

int removeMem(int key, char *fileName) {
  int semID = semget(key, 1, 0);
  if (semID == -1) {
    printf("%s\n", strerror(errno));
  }
  int shmID = shmget(key, sizeof(int), 0);
  if (shmID == -1) {
    printf("%s\n", strerror(errno));
  }
  int retVal = semctl(semID, 1, IPC_RMID);
  if (retVal == -1) {
    printf("%s\n", strerror(errno));
  }
  retVal = shmctl(shmID, IPC_RMID, 0);
  if (retVal == -1) {
    printf("%s\n", strerror(errno));
  }
  viewMem(fileName);
}

int viewMem(char *fileName) {
  struct stat *statBuff = calloc(1, sizeof(struct stat));
  stat(fileName, statBuff);
  int fileSize = statBuff->st_size;
  FILE *file;
  file = fopen(fileName, "r");
  if (file == NULL) {
    printf("%s\n", strerror(errno));
  }
  char* dataBuff = calloc(1, fileSize * sizeof(char));
  int retVal = fread(dataBuff, sizeof(char), fileSize - 1, file);
  if (retVal == -1) {
    printf("%s\n", strerror(errno));
  }
  else {
    printf("%s\n", dataBuff);
  }
  free(statBuff);
  free(dataBuff);
  fclose(file);
}

int viewLastLine(char *fileName, int byteSize) {

  int file = open(fileName, O_RDONLY, 0644);
  lseek(file, -byteSize, SEEK_END);
  char* dataBuff = calloc(1, byteSize * sizeof(char));
  int retVal = read(file, dataBuff, byteSize);
  if (retVal == 0) {
    printf("Read nothing.\n");
  }
  else {
    printf("%s\n", dataBuff);
  }
  free(dataBuff);
  close(file);
}

int writeToFile(char *fileName, char *data, int size) {
  int file = open(fileName, O_WRONLY | O_APPEND, 0644);
  if (file == -1) {
    printf("%s\n", strerror(errno));
  }
  int retVal = write(file, data, size);
  if (retVal == -1) {
    printf("%s\n", strerror(errno));
  }
  close(file);
}
