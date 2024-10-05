
#ifndef MAIN_12_H_INCLUDED
#define MAIN_12_H_INCLUDED

#include <stdlib.h>

#define LENGTH 4

int getSumElementsAboveMainDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
);

int getSumElementsAboveSecondaryDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
);

int getSumElementsBelowMainDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
);

int getSumElementsBelowSecondaryDiagonal(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
);

void print2DArray(
    int arr[][LENGTH],
    size_t rows,
    size_t cols
);

#endif // MAIN_12_H_INCLUDED
