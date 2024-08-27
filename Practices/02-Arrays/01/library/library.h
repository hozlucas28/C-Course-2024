#ifndef LIBRARY_01_H_INCLUDED
#define LIBRARY_01_H_INCLUDED

typedef struct {
    int* array;
    int maxLength;
    int occLength;
} IntArray;

int insertIntAt(IntArray* arr, int index, int element);
void printReprIntArray(IntArray* arr);

#endif // LIBRARY_01_H_INCLUDED
