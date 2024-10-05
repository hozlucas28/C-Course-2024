
#ifndef MAIN_18_H_INCLUDED
#define MAIN_18_H_INCLUDED

#include <stdlib.h>

void sort(
    void* arr,
    size_t arrLength,
    size_t sizeOfDataType,
    unsigned short int (cmpFn)(void* anchor, void* next)
);

void swap(void* a, void* b, size_t totalSize);

#endif // MAIN_18_H_INCLUDED
