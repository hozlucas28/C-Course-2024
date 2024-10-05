
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rowsAndCols = 4;

    int arr[][LENGTH] = {
        {1 , 2 , 3 , 4 },
        {5 , 6 , 7 , 8 },
        {9 , 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("> `arr` before transposition: ");
    print2DArray(arr, rowsAndCols, rowsAndCols);

    transpose2DArray(arr, rowsAndCols);

    printf("\n\n> `arr` after transposition: ");
    print2DArray(arr, rowsAndCols, rowsAndCols);

    return 0;
}
