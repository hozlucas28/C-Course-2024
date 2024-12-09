
#include <stdio.h>
#include <stdlib.h>

void printIntegers(const void* arr, const size_t arrLength) {
    int* _slice = (int*)arr;

    size_t i;

    printf("[");
    for (i = 0; i < arrLength; i++) {
        printf(" %d", *(_slice + i));
    };
    printf(" ]");
}
