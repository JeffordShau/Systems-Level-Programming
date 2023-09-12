#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directory.h"

int main(int argc, char *argv[]) {
  char *dr = calloc(50, sizeof(char));
  if(argc == 2) {
    strcpy(dr, argv[1]);
  }
  if (argc == 1) {
    strcpy(dr, "./");
  }
  directoryInfo(dr);
  free(dr);
  return 0;
}
