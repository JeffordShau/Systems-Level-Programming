#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pop.h"

int main(int argc, char *argv[]) {
  // printf("%s", argv[1]);
  if (strcmp(argv[1], "-read_csv") == 0) {
    readCsv("nyc_pop.csv", "nyc_pop.dat");
  }
  else if (strcmp(argv[1], "-read_data") == 0) {
    readData("nyc_pop.dat");
  }
  else if (strcmp(argv[1], "-add_data") == 0) {
    addData("nyc_pop.dat");
  }
  else if (strcmp(argv[1], "-update_data") == 0) {
    updateData("nyc_pop.dat");
  }
}
