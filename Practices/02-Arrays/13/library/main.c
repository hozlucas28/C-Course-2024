
#include "./main.h"

#include <stdlib.h>

int getSumMainDiagonal(int arr[][LENGTH], size_t rowsAndCols) {
    size_t i;

    int total = 0;

    for (i = 0; i < rowsAndCols; i++) {
        total += arr[i][i];
    };

    return total;
}

int getSumSecondaryDiagonal(int arr[][LENGTH], size_t rowsAndCols) {
    int i;
    size_t counter = 0;

    int total = 0;

    for (i = rowsAndCols - 1; i >= 0; i--) {
       total += arr[i][counter];
       counter++;
    };

    return total;
}
