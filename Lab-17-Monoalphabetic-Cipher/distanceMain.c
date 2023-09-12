#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"

int main(int argc, char *argv[]) {
    double total_distance = distance(argv[1], argv[2]);

    printf("Total Distance: %.6f\n", total_distance);
}