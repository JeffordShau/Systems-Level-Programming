#ifndef write_h
#define write_h
union semun {
  int val; // used for SETVAL
  struct semid_ds *buf; // used for IPC_STAT and IPC_SET
  unsigned short *array;  // used for SETALL
  struct seminfo *_buf;
};
#endif
