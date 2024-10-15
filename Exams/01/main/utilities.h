#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

unsigned char readFile(
    const char* filePath,
    const void* store,
    const size_t storeLength,
    const size_t sizeOfDataType,
    void (*readMethod)(char* line, void* storePos)
);

unsigned char writeFile(
    const char* filePath,
    const void* lines,
    const size_t linesLength,
    const size_t sizeOfDataType,
    void (*writeMethod)(FILE* file, void* line)
);

#endif // UTILITIES_H_INCLUDED
