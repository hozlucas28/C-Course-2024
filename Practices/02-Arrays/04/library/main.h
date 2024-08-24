#ifndef MAIN_04_H_INCLUDED
#define MAIN_04_H_INCLUDED

#include <stdbool.h>

typedef struct {
    int* array;
    int maxLength;
    int occLength;
} IntArray;

void deleteFuncIntArray(IntArray* arr, bool (*cmpFn)(int element, int index));

void printIntArray(IntArray* arr);

bool spliceIntArray(IntArray* arr, int index, int count);

#endif // MAIN_04_H_INCLUDED
