#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include "cipher.h"

int main(int argc, char *argv[]) {
    char encrypted[1000000];
    char lowercase_encrypted[1000000];
    char decrypted[1000000];
    char aliceBUFF[1000000];
    char aliceTEXT[1000000];
    char BUFF[1000000];

    double lowest_distance = 1000000;
    double temp_distance = 0;
    double temp_reversed_distance = 0;
    FILE *file;

    // open encrypted text file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }

    // read input
    while (fgets(BUFF, 999999, file) != NULL) {
        // printf("%s\n", BUFF);
        strcat(encrypted, BUFF);
    }
    fclose(file);
    // printf("%s\n", encrypted);

    // 26 forward rotational shift
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < strlen(encrypted); j++) {
            if (ispunct(encrypted[j]) || isspace(encrypted[j]) || isdigit(encrypted[j])) {
                continue;
            }
            encrypted[j] += 1;
            if (encrypted[j] > 90 && encrypted[j] < 97) {
                encrypted[j] -= 26;
            }
            else if (encrypted[j] > 122) {
                encrypted[j] -= 26;
            }
        }
        // printf("%s\n", encrypted);
        file = fopen(argv[1], "w");
        if (file == NULL) {
            printf("%s\n", strerror(errno));
            exit(errno);
            return 0;
        }
        fseek(file, 0, SEEK_SET);
        fwrite(encrypted, sizeof(char), strlen(encrypted), file);
        fclose(file);

        // printf("%s\n", lowercase_encrypted);
        temp_distance = distance("alice.txt", argv[1]);
        // printf("%f\n\n", temp_distance);
        if (temp_distance < lowest_distance) {
            lowest_distance = temp_distance;
            // printf("%s\n", encrypted);
            strcpy(decrypted, encrypted);
        }
    }

    // printf("BACKWARDS\n\n");
    // format encrypted message to reverse alphabet
    for (int i = 0; i < strlen(encrypted); i ++) {
        if (ispunct(encrypted[i]) || isspace(encrypted[i]) || isdigit(encrypted[i])) {
            continue;
        }
        else {
            if (encrypted[i] <= 90) {
                encrypted[i] = 'Z' - (encrypted[i] - 'A');
            }
            else {
                encrypted[i] = 'z' - (encrypted[i] - 'a');
            }
        }
    }
    // printf("%s\n", encrypted);

    // open encrypted text file
    file = fopen("reversed_encrypted.txt", "w");
    if (file == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }

    // write to file
    fwrite(encrypted, sizeof(char), strlen(encrypted), file);
    fclose(file);

    // 26 backward rotational shift
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < strlen(encrypted); j++) {
            if (ispunct(encrypted[j]) || isspace(encrypted[j]) || isdigit(encrypted[j])) {
                continue;
            }
            encrypted[j] += 1;
            if (encrypted[j] > 90 && encrypted[j] < 97) {
                encrypted[j] -= 26;
            }
            else if (encrypted[j] > 122) {
                encrypted[j] -= 26;
            }
        }
        // printf("%s\n", encrypted);

        file = fopen("reversed_encrypted.txt", "w");
        if (file == NULL) {
            printf("%s\n", strerror(errno));
            exit(errno);
            return 0;
        }
        fseek(file, 0, SEEK_SET);
        fwrite(encrypted, sizeof(char), strlen(encrypted), file);
        fclose(file);

        for (int i = 0; i < strlen(encrypted); i ++) {
            lowercase_encrypted[i] = tolower(encrypted[i]);
        }
        // printf("%s\n", lowercase_encrypted);
        temp_distance = distance("alice.txt", "reversed_encrypted.txt");
        // printf("%f\n\n", temp_distance);
        if (temp_distance < lowest_distance) {
            lowest_distance = temp_distance;
            // printf("%s\n", encrypted);
            strcpy(decrypted, encrypted);
        }
    }

    file = fopen(argv[1], "w");
        if (file == NULL) {
            printf("%s\n", strerror(errno));
            exit(errno);
            return 0;
        }
        fseek(file, 0, SEEK_SET);
        fwrite(BUFF, sizeof(char), strlen(decrypted), file);
        fclose(file);

    printf("%s\n", decrypted);
}