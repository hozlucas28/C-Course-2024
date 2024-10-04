
#include <stdlib.h>

int* make(int length) {
    int* arr = malloc(sizeof(int) * length);
    return arr;
}
