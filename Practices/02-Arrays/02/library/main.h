#ifndef MAIN_02_H_INCLUDED
#define MAIN_02_H_INCLUDED

typedef struct {
    int* array;
    int maxLength;
    int occLength;
} IntArray;

int getUserInputInt(char* message);

int addIntToIntArray(IntArray* arr, int element);

void printReprIntArray(IntArray* arr);

void sortAscIntArray(IntArray* arr);

#endif // MAIN_02_H_INCLUDED
