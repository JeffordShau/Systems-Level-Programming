#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "code.h"

int encode (char *inputTextfile, char *keyfile, char *outputCiphertextfile) {
    unsigned char inputBuff[10000];
    unsigned char keyBuff[10000];
    unsigned char outputFileName[10000];

    FILE *inputFile;
    FILE *keyFile;
    int outputFile;

    inputFile = fopen(inputTextfile, "rb");
    keyFile = fopen(keyfile, "rb");
    outputFile = open(outputCiphertextfile, O_WRONLY | O_CREAT);

    fseek(inputFile, 0, SEEK_END);
    int inputLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    // printf("InputLength: %d\n", inputLength);

    fseek(keyFile, 0, SEEK_END);
    int keyLength = ftell(keyFile);
    fseek(keyFile, 0, SEEK_SET);

    int keyCounter = 0;
    unsigned char* outputBuff = malloc(sizeof(unsigned char));

    fread(keyBuff, sizeof(char), keyLength, keyFile);
    // printf("Key: %s\n", keyBuff);

    while (fread(inputBuff, sizeof(char), 1, inputFile) != 0) {
        outputBuff[0] = inputBuff[0] ^ keyBuff[keyCounter]; 
        keyCounter++;
        if (keyCounter >= keyLength) {
            keyCounter = 0;
        }
        write(outputFile, outputBuff, sizeof(unsigned char));
    }
    // printf("Counter End: %d\n", outputCounter);

    fclose(inputFile);
    fclose(keyFile);
    close(outputFile);
    free(outputBuff);

    return 0;
}

int decode(char *inputCiphertextfile, char *keyfile) {
    unsigned char inputBuff[10000];
    unsigned char keyBuff[10000];

    FILE *inputFile;
    FILE *keyFile;

    inputFile = fopen(inputCiphertextfile, "rb");
    keyFile = fopen(keyfile, "rb");

    fseek(inputFile, 0, SEEK_END);
    int inputLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    // printf("%d\n", inputLength);

    fseek(keyFile, 0, SEEK_END);
    int keyLength = ftell(keyFile);
    fseek(keyFile, 0, SEEK_SET);

    int outputCounter = 0;
    int keyCounter = 0;
    unsigned char* outputBuff = malloc(inputLength * sizeof(char));

    fread(keyBuff, sizeof(char), keyLength, keyFile);
    // printf("Key: %s\n", keyBuff);

    while (fread(inputBuff, sizeof(unsigned char), 1, inputFile) != 0) {
        outputBuff[outputCounter] = inputBuff[0] ^ keyBuff[keyCounter]; 
        // printf("%d\n", outputBuff[outputCounter]); 
        outputCounter++;
        keyCounter++;
        if (keyCounter >= keyLength) {
            keyCounter = 0;
        }
    }

    printf("%s\n", outputBuff);

    fclose(inputFile);
    fclose(keyFile);
    free(outputBuff);

    return 0;
}

int hexdump(char* fileName) {
    unsigned char inputBuff[10000];
    unsigned char outputBuff[10000];
    unsigned char tempBuff[4];

    FILE *inputFile;

    inputFile = fopen(fileName, "rb");

    fseek(inputFile, 0, SEEK_END);
    int inputLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // printf("%d\n", inputLength);

    fread(inputBuff, sizeof(char), inputLength, inputFile);

    for(int i = 0; i < inputLength; i++) {
        sprintf(tempBuff, "%02x ", inputBuff[i]);
        strcat(outputBuff, tempBuff);

    }

    printf("%s\n", outputBuff);
    
    return 0;
}