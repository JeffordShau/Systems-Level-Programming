#include <stdio.h>

int main() {
    char charValue = 97;
    int intValue = 103;
    long longValue = 60000;

    printf("charValue hex, charValue decimal: %p %d\nintValue hex and intValue decimal: %p, %d\nlongValue hex and longValue decimal: %p, %ld\n\n", &charValue, &charValue, &intValue, &intValue, &longValue, &longValue);
    // The address of the values in hex start with 0x7fff

    printf("Pointer Values\n");
    char *charPtr = &charValue;
    int *intPtr = &intValue;
    long *longPtr = &longValue;
    printf("value of charPtr: %c\nvalue of intPtr: %d\nvalue of longPtr: %ld\n\n", *charPtr, *intPtr, *longPtr);

    printf("Changing Pointer Values\n");
    *charPtr = 50;
    *intPtr = 73;
    *longPtr = 3000;
    printf("value of charPtr: %c\nvalue of intPtr: %d\nvalue of longPtr: %ld\n\n", *charPtr, *intPtr, *longPtr);

    printf("Unsigned int with two pointers\n");
    unsigned int ui = 1+2+4+256+512+1024;
    char *unPtr1 = &ui;
    int *unPtr2 = &ui;

    printf("Dereferncing pointer\n");
    printf("p: %p p points to: %d \np: %p p points to: %d\n\n", unPtr1, *unPtr1, unPtr2, *unPtr2);

    printf("Unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    int byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+1 unsigned int decimal bytes\n");
    printf("Unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 1;
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    ui = 1+2+4+256+512+1024;
    printf("Unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+1 unsigned int hex bytes\n");
    printf("Unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 1;
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    ui = 1+2+4+256+512+1024;
    printf("Unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+16 unsigned int decimal bytes\n");
    printf("Unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 16;
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    ui = 1+2+4+256+512+1024;
    printf("Unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+16 unsigned int hex bytes\n");
    printf("Unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 16;
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    ui = 999999;
    printf("Large unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+16 large unsigned int decimal bytes\n");
    printf("Unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 16;
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    ui = 999999;
    printf("Large unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+16 large unsigned int hex bytes\n");
    printf("Unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 16;
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    int si = 999999;
    printf("Signed int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+16 signed int decimal bytes\n");
    printf("Unsigned int decimal: %u\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 16;
      printf("%hhu ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");

    si = 999999;
    printf("Signed int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    while(byteCounter < 4) {
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n");

    printf("+16 signed int hex bytes\n");
    printf("Unsigned int hex: %x\n", ui);
    printf("Bytes: ");
    byteCounter = 0;
    for (int i = 0; i < 4; i++) {
      unPtr1[byteCounter] += 16;
      printf("%hhx ", unPtr1[byteCounter]);
      byteCounter += 1;
    }
    printf("\n\n");
}
