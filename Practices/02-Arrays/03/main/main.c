#include <stdio.h>

#include "../library/main.h"

int main()
{
    const int maxLength = 10;

    int arr[] = {2,4,6,8,10,12,14,16};

    IntArray intArr;
    intArr.array = arr;
    intArr.maxLength = maxLength;
    intArr.occLength = 8;

    printIntArray(&intArr);

    spliceIntArray(&intArr, 3, 4);

    printf("\n");
    printIntArray(&intArr);

    return 0;
}
