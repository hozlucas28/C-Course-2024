
#include "./main.h"

#include <stdio.h>
#include <stdlib.h>

void print2DArray(
    int arr[][LENGTH],
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

void transpose2DArray(
    int arr[][LENGTH],
    size_t rowsAndCols
) {
    size_t i;
    size_t j;

    int aux;

    for (i = 0; i < rowsAndCols - 1; i++) {
        for (j = i + 1; j < rowsAndCols; j++) {
            aux = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = aux;
        };
    };
}
