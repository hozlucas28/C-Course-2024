
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./functions.h"

void* _bsearch(
    const void* key,
    const void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    int (*cmp)(const void* key, const void* element)
) {
    void* elementFound = NULL;

    char* left = (char*)arr;
    char* middle = left + (arrLength / 2) * sizeOfDataType;
    char* right = middle + sizeOfDataType;

    int cmpValue;

    if (arrLength == 1) {
        cmpValue = cmp(key, left);
        return cmpValue == 0 ? left : elementFound;
    };

    cmpValue = cmp(key, middle);

    if (cmpValue < 0) {
        return _bsearch(
            key,
            left,
            arrLength / 2,
            sizeOfDataType,
            cmp
        );

    } else if (cmpValue > 0) {
        return _bsearch(
            key,
            right,
            (arrLength / 2) - !(arrLength % 2),
            sizeOfDataType,
            cmp
        );

    } else if (cmpValue == 0) {
        elementFound = middle;
    };

    return elementFound;
}

void** new2DArray(
    const size_t rows,
    const size_t cols,
    const size_t pSizeOfDataType,
    const size_t sizeOfDataType
) {
    size_t i;
    size_t j;

    void** arr2D = malloc(pSizeOfDataType * rows);

    for (i = 0; i < rows; i++) {
        *((char**)arr2D + i) = malloc(sizeOfDataType * cols);
        if (*((char**)arr2D + i) == NULL) {
            for (j = 0; j < i; j++) free(*((char**)arr2D + i));
            return NULL;
        };
    };

    return arr2D;
}

void destroy2DArray(
    void** arr2D,
    const size_t rows
) {
    size_t i;
    char* row;

    for (i = 0; i < rows; i++) {
        row = *((char**)arr2D + i);
        free(row);
    };

    free(arr2D);
}

void print2DArray(
    void** arr2D,
    const size_t rows,
    const size_t cols,
    const size_t sizeOfDataType,
    void (*printMethod)(const void* element)
) {
    size_t i;
    size_t j;

    char* row;
    char* element;

    for (i = 0; i < rows; i++) {
        row = *((char**)arr2D + i);

        printf("[");
        for (j = 0; j < cols; j++) {
            element = (row + j * sizeOfDataType);
            printMethod(element);
        };
        printf(" ]\n");
    };
}

void** transpose2DArray(
    void** arr2D,
    size_t* rows,
    size_t* cols,
    const size_t pSizeOfDataType,
    const size_t sizeOfDataType
) {
    size_t i;
    size_t j;

    void** transposed2DArr;

    if (*rows > 50 || *cols > 50) return NULL;

    transposed2DArr = new2DArray(
        *cols,
        *rows,
        pSizeOfDataType,
        sizeOfDataType
    );
    if (transposed2DArr == NULL) return NULL;

    for (j = 0; j < *cols; j++) {
        for (i = 0; i < *rows; i++) {
            memcpy(
                (*((char**)transposed2DArr + j)) + i * sizeOfDataType,
                (*((char**)arr2D + i)) + j * sizeOfDataType,
                sizeOfDataType
            );
        };
    };

    destroy2DArray(arr2D, *rows);

    arr2D = transposed2DArr;
    _swap(rows, cols, sizeof(rows));

    return arr2D;
}

void printArr(
    void* arr,
    const size_t arrLenght,
    const size_t sizeOfDataType,
    void (*printMethod)(const void* element)
) {
    size_t i;

    void* element;

    printf("[");
    for (i = 0; i < arrLenght; i++) {
        element = (char*)arr + i * sizeOfDataType;
        printMethod(element);
    };
    printf(" ]\n");
}

void _swap(
    void* a,
    void* b,
    const size_t sizeOfDataType
) {
    size_t i;
    char aux;

    for (i = 0; i < sizeOfDataType; i++) {
        aux = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = aux;
    };
}

void printInt(const void* element) {
    int* _element = (int*)element;
    printf(" %2d", *_element);
}

int cmpInts(const void* a, const void* b) {
    int* _a = (int*)a;
    int* _b = (int*)b;

    return *_a - *_b;
}
