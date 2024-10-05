
#include "../library/main.c"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rowsAndCols = LENGTH;

    int arr[][LENGTH] = {
        {1 , 2 , 3 , 4 },
        {5 , 6 , 7 , 8 },
        {9 , 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf(
        "> Sum of the elements in the main diagonal: %d.",
        getSumMainDiagonal(arr, rowsAndCols)
    );

    printf(
        "\n> Sum of the elements in the secondary diagonal: %d.",
        getSumSecondaryDiagonal(arr, rowsAndCols)
    );

    return 0;
}
