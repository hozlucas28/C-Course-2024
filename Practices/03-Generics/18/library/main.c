
#include "./main.h"

#include <stdlib.h>

void sort(
    void* arr,
    size_t arrLength,
    size_t sizeOfDataType,
    unsigned short int (cmpFn)(void* anchor, void* next)
) {
    size_t i;
    size_t j;

    void* anchor;
    void* cmpAnchor;
    void* next;

    for (i = 0; i < arrLength - 1; i++) {
        anchor = (char*)arr + sizeOfDataType * i;
        cmpAnchor = anchor;

        for (j = i + 1; j < arrLength; j++) {
            next = (char*)arr + sizeOfDataType * j;
            if ((*cmpFn)(cmpAnchor, next)) cmpAnchor = next;
        };

        if (anchor != cmpAnchor) {
            swap(anchor, cmpAnchor, sizeOfDataType);
        };
    };
}

void swap(void* a, void* b, size_t totalSize) {
    size_t i;

    char aux;

    for (i = 0; i < totalSize; i++) {
        aux = *((char*)b + i);
        *((char*)b + i) = *((char*)a + i);
        *((char*)a + i) = aux;
    };
}
