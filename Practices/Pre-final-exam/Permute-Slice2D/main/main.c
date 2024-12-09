
#include <stdio.h>
#include <stdlib.h>

#include "../library/main.h"

#include "./utilities.h"

int main() {
    Slice2D* slice2D;
    const size_t rows = 2;
    const size_t cols = 3;

    size_t i;
    size_t j;

    size_t counter;

    unsigned char error;

    slice2D = newSlice2D(rows, cols, sizeof(int));
    if (slice2D == NULL) return 1;

    counter = 0;
    for (i = 0; i < getRows(slice2D); i++) {
        for (j = 0; j < getCols(slice2D); j++) {
            counter += 1;
            insertAt(slice2D, i, j, &counter);
        };
    };

    printf("> slice2D (before permutation)...\n");
    printSlice2D(slice2D, &printIntegers);

    error = permute(slice2D);
    if (error) {
        printf("\n\n> Error! An error occurred on permutation.");
    } else {
        printf("\n\n> slice2D (after permutation)...\n");
        printSlice2D(slice2D, &printIntegers);
    };

    error = permute(slice2D);
    if (error) {
        printf("\n\n> Error! An error occurred on permutation.");
    } else {
        printf("\n\n> slice2D (after permutation)...\n");
        printSlice2D(slice2D, &printIntegers);
    };

    destroySlice2D(slice2D);

    return 0;
}
