
#include "./main.h"

#include <stdio.h>
#include <stdlib.h>

void destroy2DArray(int** arr, size_t rows, size_t cols) {
    size_t i;

    for (i = 0; i < rows; i++) {
        free(*(arr + i));
    };

    free(arr);
}

int** new2DArray(size_t rows, size_t cols) {
    size_t i;
    size_t j;

    int** arr = (int**)malloc(sizeof(int*) * rows);
    if (arr == NULL) return NULL;

    for (i = 0; i < rows; i++) {
        *(arr + i) = (int*)malloc(sizeof(int) * cols);
        if (*(arr + i) == NULL) {
            for (j = 0; j <= i; j++) free(*(arr + j));
            return NULL;
        };
    };

    return arr;
}

void print2DArray(
    int** arr,
    size_t rows,
    size_t cols
) {
    size_t i;
    size_t j;

    printf("[");
    for (i = 0; i < rows; i++) {
        printf("\n  ");
        for (j = 0; j < cols; j++) {
            printf("%-4d ", arr[i][j]);
        };
    };
    printf("\n]");
}

int** transpose2DArray(int** arr, size_t rows, size_t cols) {
    size_t i;
    size_t j;

    int** transposedArr = new2DArray(cols, rows);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transposedArr[j][i] = arr[i][j];
        };
    };

    return transposedArr;
}
