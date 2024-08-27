#include <stdio.h>

#include "../library/main.h"

int (*pCMPFn)(int element, int index);

int cmpFn(int element, int index) {
    return element % 2 == 0;
}

int main()
{
    const int maxLength = 10;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    IntArray intArray;

    intArray.array = arr;
    intArray.maxLength = maxLength;
    intArray.occLength = 10;

    printIntArray(&intArray);

    pCMPFn = &cmpFn;
    deleteFuncIntArray(&intArray, pCMPFn);

    printf("\n");
    printIntArray(&intArray);

    return 0;
}
