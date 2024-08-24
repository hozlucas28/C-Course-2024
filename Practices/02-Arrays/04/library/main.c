#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void deleteFuncIntArray(IntArray* arr, bool (*cmpFn)(int element, int index)) {
    int i;
    bool cmp;

    for (i = 0; i < arr->occLength; i++) {
        cmp = (*cmpFn)(arr->array[i], i);
        if (cmp) {
            spliceIntArray(arr, i, 1);
        };
    };
}

void printIntArray(IntArray* arr) {
    int i;

    printf("[");
    for (i = 0; i < arr->occLength; i++) {
        printf(" %d", arr->array[i]);
    }
    printf(" ]");
}

bool spliceIntArray(IntArray* arr, int index, int count) {
    int i;
    int j;
    int* sanitizedArr = malloc(arr->maxLength * sizeof(int));

    if (!sanitizedArr) {
        return false;
    }

    if (index < 0 || index > (arr->occLength - 1) || count <= 0) {
        free(sanitizedArr);
        return false;
    }

    for (i = 0; i < index; i++) {
        sanitizedArr[i] = arr->array[i];
    };

    i = index;
    for (j = index + count; j < arr->occLength; j++) {
        sanitizedArr[i] = arr->array[j];
        i++;
    };

    arr->array = sanitizedArr;
    arr->occLength -= count;

    return true;
}
