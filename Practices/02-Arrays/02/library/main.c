#include <stdio.h>

#include "main.h"

int getUserInputInt(char* message) {
    int userInput;

    printf(message);
    scanf("%d", &userInput);
    fflush(stdin);

    return userInput;
}

int addIntToIntArray(IntArray* arr, int element) {
    int index = arr->occLength;

    if (arr->occLength >= arr->maxLength) {
        return 0;
    };

    arr->array[index] = element;
    arr->occLength += 1;

    sortAscIntArray(arr);
    return 1;
}

void printReprIntArray(IntArray* arr) {
    int i;

    printf("> array = [ ");
    for (i = 0; i < arr->occLength; i++) {
        printf("%d ", arr->array[i]);
    };
    printf("]");

    printf("\n> maxLength = %d", arr->maxLength);
    printf("\n> occLength = %d", arr->occLength);
}

void sortAscIntArray(IntArray* arr) {
    int i;
    int j;
    int anchorElem;
    int nextElem;
    int cmp;

    for (i = 0; i < arr->occLength; i++) {
        anchorElem = arr->array[i];

        for (j = arr->occLength - 1; j > i; j--) {
            nextElem = arr->array[j];
            cmp = anchorElem - nextElem;

            if (cmp > 0) {
                arr->array[i] = nextElem;
                arr->array[j] = anchorElem;
                anchorElem = nextElem;
            };
        };
    };
}
