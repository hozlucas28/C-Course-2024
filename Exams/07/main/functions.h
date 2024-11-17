#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdlib.h>

void* _bsearch(
    const void* key,
    const void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    int (*cmp)(const void* key, const void* element)
);

void** new2DArray(
    const size_t rows,
    const size_t cols,
    const size_t pSizeOfDataType,
    const size_t sizeOfDataType
);

void destroy2DArray(
    void** arr2D,
    const size_t rows
);

void print2DArray(
    void** arr2D,
    const size_t rows,
    const size_t cols,
    const size_t sizeOfDataType,
    void (*printMethod)(const void* element)
);

void** transpose2DArray(
    void** arr2D,
    size_t* rows,
    size_t* cols,
    const size_t pSizeOfDataType,
    const size_t sizeOfDataType
);

void printArr(
    void* arr,
    const size_t arrLenght,
    const size_t sizeOfDataType,
    void (*printMethod)(const void* element)
);

void _swap(
    void* a,
    void* b,
    const size_t sizeOfDataType
);

void printInt(const void* element);

int cmpInts(const void* a, const void* b);

#endif // FUNCTIONS_H_INCLUDED
