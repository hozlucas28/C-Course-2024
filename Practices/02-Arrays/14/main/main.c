
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rows = LENGTH;
    const size_t cols = LENGTH;

    int arr[][LENGTH] = {
        {1 , 0 , 0 , 0 },
        {0 , 6 , 0 , 0 },
        {0 , 0 , 11, 0 },
        {0 , 0 , 0 , 16}
    };

    printf(
        "> Is `arr` a diagonal matrix? %s.",
        isDiagonal(arr, rows, cols) ? "Yes" : "False"
    );

    return 0;
}
