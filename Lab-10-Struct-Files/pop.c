#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <sys/stat.h>
#include "pop.h"

void readCsv(char *csvFile, char *dataFile) {
  FILE *filePtr = fopen(csvFile, "rb");
  if (filePtr == NULL) {
    printf("%s\n", strerror(errno));
    exit(errno);
    fclose(filePtr);
    exit(0);
  }

  struct pop_entry *array = calloc(500, sizeof(struct pop_entry));
  struct pop_entry *temp = malloc(sizeof(struct pop_entry));
  char data[1024];
  int idx = 0;
  fgets(data, 1024, filePtr);
  if (ferror(filePtr) != 0) {
    printf("Error: Could not read file successfully.\n");
    free(array);
    free(temp);
    fclose(filePtr);
    exit(0);
  }
  while (fgets(data, 1024, filePtr)) {
    int yr = 0;
    int manhattanPop = 0;
    int brooklynPop = 0;
    int queensPop = 0;
    int bronxPop = 0;
    int statenIslandPop = 0;
    sscanf(data, "%d, %d, %d, %d, %d, %d", &yr, &manhattanPop, &brooklynPop, &queensPop, &bronxPop, &statenIslandPop);

    temp->year = yr;
    temp->population = manhattanPop;
    strcpy(temp->boro, "Manhattan");
    array[idx] = *temp;
    // printf("%d, %d, %s\n", temp->year, temp->population, temp->boro);
    idx += 1;

    temp->year = yr;
    temp->population = brooklynPop;
    strcpy(temp->boro, "Brooklyn");
    array[idx] = *temp;
    // printf("%d, %d, %s\n", temp->year, temp->population, temp->boro);
    idx += 1;

    temp->year = yr;
    temp->population = queensPop;
    strcpy(temp->boro, "Queens");
    array[idx] = *temp;
    // printf("%d, %d, %s\n", temp->year, temp->population, temp->boro);
    idx += 1;

    temp->year = yr;
    temp->population = bronxPop;
    strcpy(temp->boro, "Bronx");
    array[idx] = *temp;
    // printf("%d, %d, %s\n", temp->year, temp->population, temp->boro);
    idx += 1;

    temp->year = yr;
    temp->population = statenIslandPop;
    strcpy(temp->boro, "Staten Island");
    array[idx] = *temp;
    // printf("%d, %d, %s\n", temp->year, temp->population, temp->boro);
    idx += 1;
  }
  if (ferror(filePtr) != 0) {
    printf("Error: Could not read file successfully.\n");
    fclose(filePtr);
    exit(0);
  }

  FILE *newfilePtr = fopen(dataFile, "w+");
  fwrite(array, sizeof(struct pop_entry), idx, newfilePtr);
  if (ferror(newfilePtr) != 0) {
    printf("Error: Could not write file successfully.\n");
    fclose(filePtr);
    exit(0);
  }

  fclose(filePtr);
  fclose(newfilePtr);
  free(array);
  free(temp);
}

void readData(char *dataFile) {
  FILE *dataPtr = fopen(dataFile, "rb");
  struct stat *statBuff = calloc(1, sizeof(struct stat));
  stat(dataFile, statBuff);
  int structCount = statBuff->st_size / sizeof(struct pop_entry);
  // printf("%d", structCount);
  struct pop_entry *array = calloc(structCount, sizeof(struct pop_entry));
  fread(array, sizeof(struct pop_entry), structCount, dataPtr);
  if (ferror(dataPtr) != 0) {
    printf("Error: Could not read file successfully.\n");
    free(statBuff);
    free(array);
    fclose(dataPtr);
    exit(0);
  }
  for (int i = 0; i < structCount; i++) {
    printf("%d: year: %d, boro: %s, pop: %d\n", i, array[i].year, array[i].boro, array[i].population);
  }

  free(statBuff);
  free(array);
  fclose(dataPtr);
}

void addData(char *dataFile) {
  printf("Enter year boro pop: ");
  int yearNum = 0;
  char borough[15];
  int popNum = 0;
  scanf("%d %s %d", &yearNum, borough, &popNum);
  printf("%d, %s, %d\n\n", yearNum, borough, popNum);

  FILE *filePtr = fopen(dataFile, "a");
  if (filePtr == NULL) {
    printf("%s\n", strerror(errno));
    exit(errno);
    fclose(filePtr);
    exit(0);
  }

  struct pop_entry *temp = malloc(sizeof(struct pop_entry));
  temp->year = yearNum;
  temp->population = popNum;
  strcpy(temp->boro, borough);

  fwrite(temp, sizeof(struct pop_entry), 1, filePtr);
  if (ferror(filePtr) != 0) {
    printf("Error: Could not write file successfully.\n");
    fclose(filePtr);
    exit(0);
  }
  free(temp);
  fclose(filePtr);
}

void updateData(char * dataFile) {
  readData("nyc_pop.dat");
  printf("entry to update: ");
  int idx = 0;
  scanf("%d", &idx);
  printf("Enter year boro pop: ");
  int yearNum = 0;
  char borough[15];
  int popNum = 0;
  scanf("%d %s %d", &yearNum, borough, &popNum);
  printf("%d, %s, %d\n\n", yearNum, borough, popNum);

  FILE *filePtr = fopen(dataFile, "rb");
  if (filePtr == NULL) {
    printf("%s\n", strerror(errno));
    exit(errno);
    fclose(filePtr);
    exit(0);
  }

  struct stat *statBuff = calloc(1, sizeof(struct stat));
  stat(dataFile, statBuff);
  int structCount = statBuff->st_size / sizeof(struct pop_entry);
  struct pop_entry *array = calloc(structCount, sizeof(struct pop_entry));
  fread(array, sizeof(struct pop_entry), structCount, filePtr);
  if (ferror(filePtr) != 0) {
    printf("Error: Could not read file successfully.\n");
    exit(0);
  }
  fclose(filePtr);

  for (int i = 0; i < structCount; i++) {
    if (i == idx) {
      array[i].year = yearNum;
      array[i].population = popNum;
      strcpy(array[i].boro, borough);
      break;
    }
    if (i == structCount - 1) {
      if (array[i].year != yearNum && strcmp(array[i].boro, borough) != 0 && array[i].population != popNum) {
        printf("Could not find entry.\n");
        free(statBuff);
        free(array);
        fclose(filePtr);
        exit(0);
      }
    }
  }

  FILE *newfilePtr = fopen(dataFile, "wb");
  fseek(newfilePtr, 0, SEEK_SET);
  fwrite(array, sizeof(struct pop_entry), structCount, newfilePtr);
  if (ferror(newfilePtr) != 0) {
    printf("Error: Could not write file successfully.\n");
    free(statBuff);
    free(array);
    fclose(newfilePtr);
    exit(0);
  }

  free(statBuff);
  free(array);
  fclose(newfilePtr);

}
