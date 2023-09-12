#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

int encode (char* plaintextfilename, char* keyfilename) {
    char plaintext[100000];
    char keytext[100000];
    char encrypted[100000];
    char BUFF[100000];

    FILE *plaintextfile;
    FILE *keytextfile;

    // read plaintext file
    plaintextfile = fopen(plaintextfilename, "r");
    if (plaintextfile == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }
    while (fgets(BUFF, 999999, plaintextfile) != NULL) {
        strcat(plaintext, BUFF);
    }
    fclose(plaintextfile);
    // printf("%s\n", plaintext);

    // read keytext file
    keytextfile = fopen(keyfilename, "r");
    if (keytextfile == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }
    while (fgets(BUFF, 999999, keytextfile) != NULL) {
        strcat(keytext, BUFF);
    }
    fclose(keytextfile);
    // printf("%s\n", keytext);

    // trim spaces from plaintext
    int notAlphabetChar = 0;
    for (int i = 0; i < strlen(plaintext); i++) {
        if (ispunct(plaintext[i]) || isspace(plaintext[i]) || isdigit(plaintext[i])) {
            continue;
        }
        else {
            plaintext[notAlphabetChar] = plaintext[i];
            notAlphabetChar += 1;
        }    
    }
    plaintext[notAlphabetChar] = '\0';

    // printf("Length %ld\n", strlen(plaintext));
    // printf("No space %s\n", plaintext);

    // shift the plaintext to encrypt
    for (int i = 0; i < strlen(plaintext); i++) {
        encrypted[i] = encodeShift(plaintext[i], keytext[i % strlen(keytext)]);
        // if (i > 2733) {
        //     printf("%d, %c\n", i, encrypted[i]); 
        // }
    }
    printf("%s\n", encrypted);
}

char encodeShift(char character, char key) {
    char rotationChar;
    int rotationNumber = 0;

    // find the rotational number
    if (key <= 90) {
        rotationChar = key - 'A';
    }
    else if (key <= 122) {
        rotationChar = key - 'a';
    }
    rotationNumber = rotationChar;

    // printf("Char %c, ", character);
    // printf("Rotation %d,", rotationNumber);
    
    // encrypt the plaintext
    if (character >= 97 && character <= 122) {
        character = character - 26;
        rotationChar = character + rotationNumber;
        if (rotationChar < 97) {
            rotationChar = rotationChar + 26;
        }
    }
    else {
        rotationChar = character + rotationNumber;
        if (character >= 65 && character <= 90 && rotationChar > 90) {
            rotationChar = rotationChar - 26;
        }
    }
    rotationChar = toupper(rotationChar);

    // printf("Encrypted %c\n", rotationChar);

    return rotationChar;
}

int decode (char* ciphertextfilename, char* keyfilename) {
    char ciphertext[100000];
    char keytext[100000];
    char decrypted[100000];
    char BUFF[100000];

    FILE *ciphertextfile;
    FILE *keytextfile;

    // read plaintext file
    ciphertextfile = fopen(ciphertextfilename, "r");
    if (ciphertextfile == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }
    while (fgets(BUFF, 999999, ciphertextfile) != NULL) {
        strcat(ciphertext, BUFF);
    }
    fclose(ciphertextfile);
    // printf("%s\n", plaintext);

    // read keytext file
    keytextfile = fopen(keyfilename, "r");
    if (keytextfile == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }
    while (fgets(BUFF, 999999, keytextfile) != NULL) {
        strcat(keytext, BUFF);
    }
    fclose(keytextfile);
    // printf("%s\n", keytext);

    // shift the plaintext to encrypt
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ispunct(ciphertext[i]) || isspace(ciphertext[i]) || isdigit(ciphertext[i])) {
            continue;
        }
        decrypted[i] = decodeShift(ciphertext[i], keytext[i % strlen(keytext)]);
    }
    printf("%s\n", decrypted);
}

char decodeShift(char character, char key) {
    char rotationChar;
    int rotationNumber = 0;

    // find the rotational number
    if (key <= 90) {
        rotationChar = key - 'A';
    }
    else if (key <= 122) {
        rotationChar = key - 'a';
    }
    rotationNumber = rotationChar;

    // printf("Char %c, ", character);
    // printf("Rotation %d,", rotationNumber);
    
    // encrypt the plaintext
    rotationChar = character - rotationNumber;
    if (rotationChar < 65) {
        rotationChar = rotationChar + 26;
    }

    // printf("Encrypted %c\n", rotationChar);

    return rotationChar;
}

double* frequency(char* fileName) {
    char lowercase_letter;
    char BUFF[100000];
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
    while (fgets(BUFF, 99999, file) != NULL) {
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

double distance(char* text1) {
        double *list1 = frequency(text1);
        // alice frequency list
        double list2[26] = {0.082, 0.014,0.022, 0.046, 0.13, 0.019, 0.023, 0.068, 0.07, 0.0014, 0.011, 0.044, 0.02, 0.065, 0.076, 0.014, 0.0019, 0.05, 0.06, 0.099, 0.032, 0.0079, 0.025, 0.0014, 0.021, 0.00072};

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

int crack(char* ciphertextfilename, int getKeyTrue) {
    char ciphertext[100000];
    char buckets[16][100000];
    char tmp[16][100000];
    char decrypted[16][100000];
    char final[100000];
    char BUFF[100000];
    char key[16];

    FILE *file;

    // read plaintext file
    file = fopen(ciphertextfilename, "r");
    if (file == NULL) {
        printf("%s\n", strerror(errno));
        exit(errno);
        return 0;
    }
    while (fgets(BUFF, 999999, file) != NULL) {
        strcat(ciphertext, BUFF);
    }
    fclose(file);
    // printf("%s\n", ciphertext);

    int keysize = 10;
    double lowest_distance = 10000;
    double temp_distance = 0;
    char* filename = "encryptedfile.txt";
    int counter = 0;
    char oneChar[2];
    oneChar[1] = '\0';
    // brute force 16 key sizes
    for(int i = 1; i <= keysize; i++) {
        // printf("\n\n%d keysize\n", i);
        // create buckets of about equal size length
        for(int j = 0; j < strlen(ciphertext); j++) {
           oneChar[0] = ciphertext[j];
        //    printf("%d, %s\n", j % i, oneChar);
           strcat(buckets[j % i], oneChar);
        //    printf("Act bucket[%d]: %s\n", j % i, buckets[j%i]);
        }
        // call decode
        for (int j = 0; j < i; j++) {
            strcpy(tmp[j], decrypt(buckets[j]));
            file = fopen(filename, "w");
            // if (file == NULL) {
            //     printf("%s\n", strerror(errno));
            //     exit(errno);
            //     return 0;
            // }
            fseek(file, 0, SEEK_SET);
            fwrite(tmp[j], sizeof(char), strlen(tmp[j]), file);
            fclose(file);
            temp_distance += distance(filename);
            temp_distance /= i;
            // printf("%f\n", temp_distance);
        }
        if (temp_distance < lowest_distance) {
            lowest_distance = temp_distance;
            for (int j = 0; j < i; j++) {
                strcpy(decrypted[j], tmp[j]);
            }
            counter = i;
        }
        // reset everything
        for (int j = 0; j < i; j++) {
            strcpy(buckets[j], "");
            strcpy(tmp[j], "");
        }
    }
    for (int i = 0; i < 16; i++) {
            // printf("%d: %s\n", i, buckets[i]);
            // printf("%d: %s\n", i, tmp[i]);
            // printf("%d: %s\n", i, decrypted[i]);
    }
    // printf("Counter %d\n", counter);
    for (int i = 0; i < floor(strlen(ciphertext) / keysize); i++) {
        for (int j = 0; j < keysize; j++) {
            oneChar[0] = decrypted[j][i];
            strcat(final, oneChar);
        }
    }
    for (int i = 0; i < strlen(ciphertext) % (keysize); i++) {
        oneChar[0] = decrypted[i][strlen(decrypted[i]) - 1];
        strcat(final, oneChar);
    }
    if (getKeyTrue == 0) {
        printf("%s\n", final);
    }
    else if (getKeyTrue == 1) {
        for (int i = 0; i < counter; i++) {
            // printf("Buckets %c\n", ciphertext[i]);
            // printf("Decrypted %c\n", decrypted[i][0]);
            if (ciphertext[i] < decrypted[i][0]) {
                oneChar[0] = ciphertext[i] - decrypted[i][0] + 26 + 'A';
            }
            else if (ciphertext[i] > decrypted[i][0]) {
                oneChar[0] = ciphertext[i] - decrypted[i][0] + 'A';
            }
            strcat(key, oneChar);
        }
    printf("%s\n", key);
    }
}

char* decrypt(char* bucketString) {
    char encrypted[100000];
    char lowercase_encrypted[100000];
    char* decrypted = malloc(100000 * sizeof(char));
    // char decrypted[100000];
    char aliceBUFF[100000];
    char aliceTEXT[100000];
    char BUFF[100000];
    char* filename = "encryptedfile.txt";

    double lowest_distance = 10000;
    double temp_distance = 0;
    double temp_reversed_distance = 0;
    FILE *file;

    strcpy(encrypted, bucketString);
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
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("%s\n", strerror(errno));
            exit(errno);
            return 0;
        }
        fseek(file, 0, SEEK_SET);
        fwrite(encrypted, sizeof(char), strlen(encrypted), file);
        fclose(file);

        // printf("%s\n", lowercase_encrypted);
        temp_distance = distance(filename);
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
        temp_distance = distance("reversed_encrypted.txt");
        // printf("%f\n\n", temp_distance);
        if (temp_distance < lowest_distance) {
            lowest_distance = temp_distance;
            // printf("%s\n", encrypted);
            strcpy(decrypted, encrypted);
        }
    }

    // file = fopen(filename, "w");
    //     if (file == NULL) {
    //         printf("%s\n", strerror(errno));
    //         exit(errno);
    //         return 0;
    //     }
    //     fseek(file, 0, SEEK_SET);
    //     fwrite(BUFF, sizeof(char), strlen(decrypted), file);
    //     fclose(file);

    return decrypted;
}