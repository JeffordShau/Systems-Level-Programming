#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_args (char *input) {
  char **buff = calloc(11, sizeof(char*));
  int idx = 0;
  char *temp;
  while (temp = strsep(&input, " ")) {
    buff[idx] = temp;
    idx += 1;
  }
  buff[idx] = NULL;
  return buff;
}
