#include <stdio.h>
#include <stdlib.h>

#include "./functions.h"

int main()
{
    char s1[15] = "Hello ";
    char s2[7] = "world!";

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const size_t arrLength = 10;

    int** arr2D;
    const size_t rowsAndCols = 7;

    size_t i;
    size_t j;
    size_t counter;

    int totalTrianInf;

    int itemToFind = 2;
    int* itemFound;

    arr2D = new2DArray(rowsAndCols, rowsAndCols);
    if (arr2D == NULL) {
        printf("\nError! An error occurred on create 2D array.");
        return 1;
    };

    counter = 1;
    for (i = 0; i < rowsAndCols; i++) {
        for (j = 0; j < rowsAndCols; j++) {
            arr2D[i][j] = counter;
            counter++;
        };
    };

    printf("> arr2D: \n");
    printArr(arr2D, rowsAndCols, rowsAndCols);

    totalTrianInf = sumTrianInfEntreDiag(arr2D, rowsAndCols);
    printf("\n> totalTrianInf = %d.", totalTrianInf);

    destroy2DArray(arr2D, rowsAndCols);

    itemFound = mbsearch(
        &itemToFind,
        arr,
        arrLength,
        sizeof(int),
        &cmpInts
    );

    if (itemFound == NULL) {
        printf(
            "\n\n> %d not found.",
            itemToFind
        );
    } else {
        printf(
            "\n\n> %d found at %p memory address (%d).",
            itemToFind,
            (void*)itemFound,
            *itemFound
        );
    };

    printf("\n\n> s1 (before mstrcat): \"%s\".", s1);
    printf("\n> s2 (before mstrcat): \"%s\".", s2);

    mstrcat(s1, s2);

    printf("\n\n> s1 (after mstrcat): \"%s\".", s1);
    printf("\n> s2 (after mstrcat): \"%s\".", s2);

    return 0;
}
