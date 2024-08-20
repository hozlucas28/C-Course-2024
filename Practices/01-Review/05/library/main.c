#include <stdbool.h>
#include <stdio.h>

bool isFibonacci(int number) {
    bool rtn = false;

    int i;
    int aux;
    int pair[2] = {1, 1};

    if (pair[1] == number) {
        return true;
    };

    for (i=0; pair[1]<number; i++) {
        aux = pair[0];
        pair[0] = pair[1];
        pair[1] = pair[1] + aux;

        if (pair[1] == number) {
            rtn = true;
            break;
        };
    };

    return rtn;
}
