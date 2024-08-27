#ifndef MAIN_04_H_INCLUDED
#define MAIN_04_H_INCLUDED

typedef struct {
    int* array;
    int maxLength;
    int occLength;
} IntArray;

void deleteFuncIntArray(IntArray* arr, int (*cmpFn)(int element, int index));

void printIntArray(IntArray* arr);

int spliceIntArray(IntArray* arr, int index, int count);

#endif // MAIN_04_H_INCLUDED
