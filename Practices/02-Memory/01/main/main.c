
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int arrLength = 10;

    int* arr = make(arrLength);

    int i;

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
