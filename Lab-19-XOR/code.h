#ifndef CODE_H
#define CODE_H

int encode (char *inputTextfile, char *keyfile, char *outputCiphertextfile);
int decode(char *inputCiphertextfile, char *keyfile);
int hexdump(char *fileName);

#endif