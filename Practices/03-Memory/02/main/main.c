
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    int* arr;
    int arrLength;

    printf("> Enter the length of the array to construct: ");
    scanf("%d", &arrLength);

    arr = make(arrLength);

    for (i = 0; i < arrLength; i++) {
        *(arr + i) = i;
    };

    printf("[");
    for (i = 0; i < arrLength; i++) {
        printf(" %d", *(arr + i));
    };
    printf(" ]");

    free(arr);

    return 0;
}
