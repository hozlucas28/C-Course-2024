
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const size_t rows = LENGTH;
    const size_t cols = LENGTH;

    int arr[][LENGTH] = {
        {1 , 0 , 0 , 0 },
        {0 , 1 , 0 , 0 },
        {0 , 0 , 1 , 0 },
        {0 , 0 , 0 , 1 }
    };

    printf(
        "> Is `arr` a indentity matrix? %s.",
        isIdentity(arr, rows, cols) ? "Yes" : "No"
    );

    return 0;
}
