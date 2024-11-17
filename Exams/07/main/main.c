
#include <stdio.h>
#include <stdlib.h>

#include "./functions.h"

int main() {
    size_t i;
    size_t j;

    size_t counter;

    int* elementFound;
    const int elementToFind = 11;

    int arr[] = {
        1 , 2 , 4 , 0 ,
        5 , 3 , 6 , 7 ,
        9 , 8 , 11, 10
    };

    size_t arr2DRows = 6;
    size_t arr2DCols = arr2DRows / 2;

    int** arr2D = (int**)new2DArray(
        arr2DRows,
        arr2DCols,
        sizeof(int*),
        sizeof(int)
    );
    if (arr2D == NULL) {
        printf("> Error! An error occurred on create 2D array.");
        return 1;
    };

    counter = 1;
    for (i = 0; i < arr2DRows; i++) {
        for (j = 0; j < arr2DCols; j++) {
            arr2D[i][j] = counter;
            counter++;
        };
    };

    qsort(
        arr,
        sizeof(arr) / sizeof(*arr),
        sizeof(*arr),
        &cmpInts
    );

    printf("> arr = ");
    printArr(
        arr,
        sizeof(arr) / sizeof(*arr),
        sizeof(*arr),
        &printInt
    );

    printf("\n> I want to find %d in `arr`.\n", elementToFind);

    elementFound = _bsearch(
        &elementToFind,
        arr,
        sizeof(arr) / sizeof(*arr),
        sizeof(*arr),
        &cmpInts
    );

    if (elementFound == NULL) {
        printf("> %d not found in the array.\n\n", elementToFind);
    } else {
        printf("> %d found in the array.\n\n", *elementFound);
    };

    printf("> arr2D before transposition...\n\n");
    print2DArray(
        (void**)arr2D,
        arr2DRows,
        arr2DCols,
        sizeof(int),
        &printInt
    );

    arr2D = (int**)transpose2DArray(
        (void**)arr2D,
        &arr2DRows,
        &arr2DCols,
        sizeof(int*),
        sizeof(int)
    );
    if (arr2D == NULL) {
        printf("\n> Error! An error occurred on transpose the 2D array.");
        return 1;
    };

    printf("\n> arr2D after transposition...\n\n");
    print2DArray(
        (void**)arr2D,
        arr2DRows,
        arr2DCols,
        sizeof(int),
        &printInt
    );

    destroy2DArray(
        (void**)arr2D,
        arr2DRows
    );

    return 0;
}
