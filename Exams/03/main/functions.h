#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdlib.h>

char* mstrcat(char* s1, const char* s2);

int sumTrianInfEntreDiag(
    int** arr,
    const size_t rowsAndCols
);

void* mbsearch(
    const void* key,
    void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    int (*cmp)(const void* key, const void* element)
);

int cmpInts(const void* key, const void* element);

void destroy2DArray(int** arr, const size_t cols);

int** new2DArray(const size_t rows, const size_t cols);

void printArr(int** arr, const size_t rows, const size_t cols);

#endif // FUNCTIONS_H_INCLUDED
