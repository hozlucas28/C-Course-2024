#include <stdio.h>

#include "../library/library.h"

int main()
{
    const int maxLength = 10;
    const int fillUpTo = 8;

    int i;
    int j = 10;

    int arr[maxLength];

    IntArray intArr;

    intArr.array = arr;
    intArr.maxLength = maxLength;
    intArr.occLength = 0;

    for (i = 0; i < fillUpTo; i++) {
        if (insertIntAt(&intArr, i, j)) {
            intArr.occLength += 1;
            j--;
        };
    };

    printReprIntArray(&intArr);

    return 0;
}
