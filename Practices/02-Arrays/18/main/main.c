
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rows = 4;
    const size_t cols = 4;

    int** arr = new2DArray(rows, cols);
    int** transposedArr;

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[0][3] = 4;

    arr[1][0] = 5;
    arr[1][1] = 6;
    arr[1][2] = 7;
    arr[1][3] = 8;

    arr[2][0] = 9;
    arr[2][1] = 10;
    arr[2][2] = 11;
    arr[2][3] = 12;

    arr[3][0] = 13;
    arr[3][1] = 14;
    arr[3][2] = 15;
    arr[3][3] = 16;

    transposedArr = transpose2DArray(arr, rows, cols);

    printf("> Original 2D array = ");
    print2DArray(arr, rows, cols);
    destroy2DArray(arr, rows, cols);

    printf("\n\n> Transpose of the original 2D array = ");
    print2DArray(transposedArr, cols, rows);
    destroy2DArray(transposedArr, cols, rows);

    return 0;
}
