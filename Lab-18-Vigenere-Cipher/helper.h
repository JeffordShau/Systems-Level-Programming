#ifndef HELPER_H
#define HELPER_H

int encode (char* plaintextfilename, char* keyfilename);
int decode (char* ciphertextfilename, char* keyfilename);
char encodeShift(char character, char key);
char decodeShift(char character, char key);
double* frequency(char* fileName);
double distance(char* text1);
int crack(char* ciphertextfilename, int getKeyTrue);
char* decrypt(char* bucketString);

#endif