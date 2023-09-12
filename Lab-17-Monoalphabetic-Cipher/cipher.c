#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include "cipher.h"

double* frequency(char* fileName) {
    char lowercase_letter;
    char BUFF[1000000];
    int index = 0;
    double total_letters = 0;

    // open file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    // used to store frequencies
    double* list = (double*)malloc(26*sizeof(double));
    for (int i = 0; i < 26; i++) {
        list[i] = 0;
    }

    // read input
    while (fgets(BUFF, 999999, file) != NULL) {
        // printf("%s\n", BUFF);
        for (int i = 0; i < strlen(BUFF); i ++) {
            lowercase_letter = tolower(BUFF[i]);
            // printf("%c\n", lowercase);
            index = lowercase_letter - 'a';
            // printf("%d\n", index);
            if (index >= 0 && index <= 26) {
                list[index] += 1;
                total_letters += 1;
            }
        }
    }
    fclose(file);

    // print frequencies
    for (int i = 0; i < 26; i++) {
        if (list[i] == 0) {
            list[i] = 0.0;
        }
        else {
            list[i] = list[i] / total_letters; 
        }
    }   

    return list;
}

double distance(char* text1, char* text2) {
        double *list1 = frequency(text1);
        double *list2 = frequency(text2);

        double total_distance = 0;
        double difference = 0;

        for (int i = 0; i < 26; i++) {
            // printf("%f\n", list1[i]);
            // printf("%f\n", list2[i]);
            // printf("%f\n", pow(list1[i] - list2[i], 2));
            total_distance += pow(list1[i] - list2[i], 2);
        }

        return sqrt(total_distance);
}