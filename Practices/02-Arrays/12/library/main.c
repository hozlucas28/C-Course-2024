
#include "./main.h"

#include <stdio.h>
#include <stdlib.h>

int getSumElementsAboveMainDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
) {
    size_t i;
    size_t j;

    int total = 0;

    for (i = 0; i < rows - 1; i++) {
        for (j = i + 1; j < cols; j++) {
            total += arr[i][j];
        };
    };

    return total;
}

int getSumElementsAboveSecondaryDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
) {
    size_t i;
    size_t j;

    int total = 0;

    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < (cols - (i + 1)); j++) {
            total += arr[i][j];
        };
    };

    return total;
}

int getSumElementsBelowMainDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
) {
    size_t i;
    size_t j;

    int total = 0;

    for (i = 0; i < rows - 1; i++) {
        for (j = i + 1; j < cols; j++) {
            total += arr[j][i];
        };
    };

    return total;
}

int getSumElementsBelowSecondaryDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
) {
    size_t i;
    size_t j;

    int total = 0;

    for (i = 1; i < rows; i++) {
        for (j = cols - 1; j > (cols - i - 1); j--) {
            total += arr[i][j];
        };
    };

    return total;
}

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
