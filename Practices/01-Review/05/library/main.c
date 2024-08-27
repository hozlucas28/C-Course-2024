#include <stdio.h>

int isFibonacci(int number) {
    int rtn = 0;

    int i;
    int aux;
    int pair[2] = {1, 1};

    if (pair[1] == number) {
        return 1;
    };

    for (i=0; pair[1]<number; i++) {
        aux = pair[0];
        pair[0] = pair[1];
        pair[1] = pair[1] + aux;

        if (pair[1] == number) {
            rtn = 1;
            break;
        };
    };

    return rtn;
}
