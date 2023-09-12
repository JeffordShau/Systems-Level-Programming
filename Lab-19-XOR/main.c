#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"

int main (int argc, char *argv[]) {
    if (strcmp(argv[1], "encode") == 0) {
        encode(argv[2], argv[3], argv[4]);
        // printf("%s, %s, %s\n", argv[2], argv[3], argv[4]);
        // inputTextfile keyfile, outputCiphertextfile
    }
    else if (strcmp(argv[1], "decode") == 0) {
        decode(argv[2], argv[3]);
        // inputCiphertextfile keyfile
    }
    else if (strcmp(argv[1], "hexdump") == 0) {
        hexdump(argv[2]);
        // filename
    }
}