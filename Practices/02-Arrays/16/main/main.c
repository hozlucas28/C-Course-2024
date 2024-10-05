
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rows = LENGTH;
    const size_t cols = LENGTH;

    int arr[][LENGTH] = {
        {1 , 2 , 3 , 4 },
        {2 , 6 , 7 , 8 },
        {3 , 7 , 11, 12},
        {4 , 8 , 12, 16}
    };

    printf(
        "> Is `arr` a symmetrical matrix? %s.",
        isSymmetrical(arr, rows, cols) ? "Yes" : "No"
    );

    return 0;
}
