#include <stdio.h>

#include "library.h"

bool insertIntAt(IntArray* arr, int index, int element) {
    if (index > arr->maxLength - 1) {
        return false;
    };

    arr->array[index] = element;
    return true;
}

void printReprIntArray(IntArray* arr) {
    int i;

    printf("> array = ");
    printf("[ ");
    for (i = 0; i < arr->occLength; i++) {
        printf("%d ", arr->array[i]);
    };
    printf("]");

    printf("\n> maxLength = %d", arr->maxLength);
    printf("\n> occLength = %d", arr->occLength);
}
