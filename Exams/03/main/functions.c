
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char* mstrcat(char* s1, const char* s2) {
    size_t i;

    size_t s1Length = strlen(s1);
    size_t s2Length = strlen(s2);

    size_t s1NewLength = s1Length + s2Length;

    for (i = 0; i < s2Length; i++) {
        *(s1 + s1Length + i) = *(s2 + i);
    };

    *(s1 + s1NewLength) = '\0';

    return s1;
}

int sumTrianInfEntreDiag(
    int** arr,
    const size_t rowsAndCols
) {
    int total = 0;

    size_t i;
    size_t j;

    size_t iStart = rowsAndCols / 2 + 1;

    size_t jStart;
    size_t jStop;
    size_t jOffset = rowsAndCols % 2 == 0 ? 1 : 0;

    for (i = iStart; i < rowsAndCols; i++) {
        jStart = rowsAndCols / 2 - jOffset;
        jStop = rowsAndCols / 2 + jOffset;
        if (rowsAndCols % 2 != 0) jStop++;

        for (j = jStart; j < jStop; j++) {
            total += arr[i][j];
        };

        jOffset++;
    };

    return total;
}

void* mbsearch(
    const void* key,
    void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    int (*cmp)(const void* key, const void* element)
) {

    char* left = (char*)arr;
    char* mid = left + sizeOfDataType * (arrLength / 2);
    char* right = mid + (arrLength % 2 == 0 ? 0 : sizeOfDataType);

    int cmpValue;

    while (left != mid) {
        cmpValue = cmp(key, mid);

        if (cmpValue < 0) {
            return mbsearch(
                key,
                left,
                arrLength / 2,
                sizeOfDataType,
                cmp
            );

        } else if (cmpValue > 0) {
            return mbsearch(
                key,
                right,
                arrLength / 2,
                sizeOfDataType,
                cmp
            );

        };

        return mid;
    };

    return arrLength == 1 && cmp(key, left) == 0 ? left : NULL;
}

int cmpInts(const void* key, const void* element) {
    int* _key = (int*) key;
    int* _element = (int*) element;

    return (*_key) - (*_element);
}

void destroy2DArray(int** arr, const size_t cols) {
    size_t i;

    for (i = 0; i < cols; i++) free(*(arr + i));
    free(arr);
}

int** new2DArray(const size_t rows, const size_t cols) {
    size_t i;
    size_t j;

    int** arr = malloc(sizeof(int*) * rows);
    if (arr == NULL) return NULL;

    for (i = 0; i < rows; i++) {
        *(arr + i) = malloc(sizeof(int) * cols);

        if (*(arr + i) == NULL) {
            for (j = 0; j < i; j++) free(*(arr + j));
            return NULL;
        };
    };

    return arr;
}

void printArr(int** arr, const size_t rows, const size_t cols) {
    size_t i;
    size_t j;

    for (i = 0; i < rows; i++) {
        printf("[");
        for (j = 0; j < cols; j++) printf(" %3d", arr[i][j]);
        printf(" ]\n");
    };
}
