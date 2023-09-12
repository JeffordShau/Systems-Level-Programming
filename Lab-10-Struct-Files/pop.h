#ifndef POP_H
#define POP_H
struct pop_entry { int year; int population; char boro[15]; };
int stringToInt(char *input);
void readCsv(char *csvFile, char *dataFile);
void readData(char *dataFile);
void addData(char *dataFile);
void updateData(char *dataFile);
#endif
