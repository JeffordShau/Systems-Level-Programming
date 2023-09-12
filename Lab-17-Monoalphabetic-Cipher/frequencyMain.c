#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"

int main(int argc, char *argv[]) {
    double *list = frequency(argv[1]);

    double letter_frequency = 0;
    char lowercase_letter;

    // print frequencies
    for (int i = 0; i < 26; i++) {
        lowercase_letter = 'A' + i; 
        printf("%c %.2g\n", lowercase_letter, list[i]);
    }
}