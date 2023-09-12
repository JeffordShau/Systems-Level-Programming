#ifndef CONTROL_H
#define CONTROL_H
union semun {
  int val; // used for SETVAL
  struct semid_ds *buf; // used for IPC_STAT and IPC_SET
  unsigned short *array;  // used for SETALL
  struct seminfo *_buf;
};
int createMem(int key, char *fileName);
int removeMem(int key, char *fileName);
int viewMem(char *fileName);
int viewLastLine(char *fileName, int byteSize);
int writeToFile(char *fileName, char *data, int size);
#endif
