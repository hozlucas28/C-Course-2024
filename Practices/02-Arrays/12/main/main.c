
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rows = LENGTH;
    const size_t cols = LENGTH;

    int arr[][LENGTH] = {
        {1 , 2 , 3 , 4 },
        {5 , 6 , 7 , 8 },
        {9 , 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("> arr = ");
    print2DArray(arr, rows, cols);

    printf(
        "\n\n> Sum of the elements above the main diagonal: %d.",
        getSumElementsAboveMainDiagonal(arr, rows, cols)
    );

    printf(
        "\n> Sum of the elements above the secondary diagonal: %d.",
        getSumElementsAboveSecondaryDiagonal(arr, rows, cols)
    );

    printf(
        "\n> Sum of the elements below the main diagonal: %d.",
        getSumElementsBelowMainDiagonal(arr, rows, cols)
    );

    printf(
        "\n> Sum of the elements below the secondary diagonal: %d.",
        getSumElementsBelowSecondaryDiagonal(arr, rows, cols)
    );

    return 0;
}
