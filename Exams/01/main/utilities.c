
#include <stdio.h>
#include <stdlib.h>

#include "./macros.h"
#include "./utilities.h"

unsigned char readFile(
    const char* filePath,
    const void* store,
    const size_t storeLength,
    const size_t sizeOfDataType,
    void (*readMethod)(char* line, void* storePos)
) {
    size_t i = 0;
    void* storePos;
    char line[MAX_LINE_LENGTH];

    FILE* file = fopen(filePath, "rt");
    if (file == NULL) return 0;

    while(fgets(line, MAX_LINE_LENGTH, file)) {
        storePos = ((char*)store) + (sizeOfDataType * i);
        (*readMethod)(line, storePos);
        i++;
    };

    fclose(file);

    return 1;
}

unsigned char writeFile(
    const char* filePath,
    const void* lines,
    const size_t linesLength,
    const size_t sizeOfDataType,
    void (*writeMethod)(FILE* file, void* line)
) {
    size_t i;
    void* line = (char*)lines;

    FILE* file = fopen(filePath, "wt");
    if (file == NULL) return 0;

    for (i = 0; i < linesLength; i++) {
        line = (char*)lines + sizeOfDataType * i;
        (*writeMethod)(file, line);
    }

    fclose(file);

    return 1;
}
