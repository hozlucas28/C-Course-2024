#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void deleteFuncIntArray(IntArray* arr, int (*cmpFn)(int element, int index)) {
    int i;
    int cmp;

    for (i = 0; i < arr->occLength; i++) {
        cmp = (*cmpFn)(*(arr->array + i), i);
        if (cmp) {
            spliceIntArray(arr, i, 1);
        };
    };
}

void printIntArray(IntArray* arr) {
    int i;
    int element;

    printf("[");
    for (i = 0; i < arr->occLength; i++) {
        element = *(arr->array + i);
        printf(" %d", element);
    }
    printf(" ]");
}

int spliceIntArray(IntArray* arr, int index, int count) {
    int i;
    int j;
    int* sanitizedArr = malloc(arr->maxLength * sizeof(int));

    if (!sanitizedArr) {
        return 0;
    }

    if (index < 0 || index > (arr->occLength - 1) || count <= 0) {
        free(sanitizedArr);
        return 0;
    }

    for (i = 0; i < index; i++) {
        *(sanitizedArr + i) = *(arr->array + i);
    };

    i = index;
    for (j = index + count; j < arr->occLength; j++) {
        *(sanitizedArr + i) = *(arr->array + j);
        i++;
    };

    arr->array = sanitizedArr;
    arr->occLength -= count;

    return 1;
}
