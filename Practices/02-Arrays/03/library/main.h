#ifndef MAIN_03_H_INCLUDED
#define MAIN_03_H_INCLUDED

#include <stdbool.h>

typedef struct {
    int* array;
    int maxLength;
    int occLength;
} IntArray;

void printIntArray(IntArray* arr);

bool spliceIntArray(IntArray* arr, int index, int count);

#endif // MAIN_03_H_INCLUDED
