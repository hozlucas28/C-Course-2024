#ifndef MAIN_03_H_INCLUDED
#define MAIN_03_H_INCLUDED

typedef struct {
    int* array;
    int maxLength;
    int occLength;
} IntArray;

void printIntArray(IntArray* arr);

int spliceIntArray(IntArray* arr, int index, int count);

#endif // MAIN_03_H_INCLUDED
