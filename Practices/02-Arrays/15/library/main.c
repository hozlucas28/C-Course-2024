
#include "./main.h"

#include <stdlib.h>

unsigned short int isIdentity(int arr[][LENGTH], size_t rows, size_t cols) {
    size_t i;
    size_t j;

    if (rows != cols) return 0;

    for (i = 0; i < rows; i++) {
        if (arr[i][i] != 1) return 0;
    };

    for (i = 0; i < rows - 1; i++) {
        for (j = i + 1; j < cols; j++) {
            if (arr[i][j] != 0 || arr[j][i] != 0) {
                return 0;
            };
        };
    };

    return 1;
}
