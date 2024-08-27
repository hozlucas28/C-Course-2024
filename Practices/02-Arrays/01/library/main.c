#include <stdio.h>

#include "library.h"

int insertIntAt(IntArray* arr, int index, int element) {
    int* array = arr->array;

    if (index > arr->maxLength - 1) {
        return 0;
    };

    *(array + index) = element;
    return 1;
}

void printReprIntArray(IntArray* arr) {
    int i;
    int element;

    printf("> array = ");
    printf("[ ");
    for (i = 0; i < arr->occLength; i++) {
        element = *(arr->array + i);
        printf("%d ", element);
    };
    printf("]");

    printf("\n> maxLength = %d", arr->maxLength);
    printf("\n> occLength = %d", arr->occLength);
}
