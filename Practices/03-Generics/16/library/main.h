
#ifndef MAIN_16_H_INCLUDED
#define MAIN_16_H_INCLUDED

#include <stdlib.h>

void* findMinor(
    void* target,
    size_t length,
    size_t sizeOfDataType,
    unsigned short int (*cmpFn)(void* prevMinor, void* currentTarget)
);

#endif // MAIN_16_H_INCLUDED
