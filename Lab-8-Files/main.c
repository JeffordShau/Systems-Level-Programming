#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int randGen() {
  int file = open("/dev/random", O_RDONLY);
  if (file == -1) {
    printf("%s\n", strerror(errno));
    exit(errno);
  }
  int BUFF_SIZE = sizeof(int);
  int buff;
  int result = read(file, &buff, BUFF_SIZE);
  if (result == -1) {
    printf("\nCould not read successfully.");
    close(file);
    return -1;
  }
  close(file);
  return buff;
}

int main() {
  printf("Generating random numbers:\n");
  int x = randGen();
  printf("x : %d\n", x);
  int y = randGen();
  printf("y : %d\n", y);

  int ARR_SIZE = 8;
  int arry1[8];
  for (int i = 0; i < ARR_SIZE; i++) {
    arry1[i] = randGen();
    printf("arry1[%d]: %d\n", i, arry1[i]);
  }

  printf("\n");

  int newfile = open("newFile.txt", O_CREAT | O_RDWR, 0700);
  write(newfile, &x, sizeof(int));
  write(newfile, &y, sizeof(int));
  write(newfile, arry1, 8 * sizeof(int));

  lseek(newfile, 0, SEEK_SET);

  int BUFF_SIZE = sizeof(int);
  int a;
  int result = read(newfile, &a, BUFF_SIZE);
  if (result == -1) {
    printf("\nCould not read successfully.");
  }
  printf("a : %d\n", a);
  int b;
  result = read(newfile, &b, BUFF_SIZE);
  if (result == -1) {
    printf("\nCould not read successfully.");
  }
  printf("b : %d\n", b);
  int arry2[8];
  result = read(newfile, arry2, ARR_SIZE * sizeof(int));
  if (result == -1) {
    printf("\nCould not read successfully.");
  }
  for (int i = 0; i < ARR_SIZE; i++) {
    printf("arry2[%d]: %d\n", i, arry2[i]);
  }
}
