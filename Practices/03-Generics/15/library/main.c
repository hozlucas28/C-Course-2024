
#include <stdlib.h>

void swap(void* a, void* b, size_t totalSize) {
    int i;

    char aux;

    for (i = 0; i < totalSize; i++) {
        aux = *((char*)b + i);
        *((char*)b + i) = *((char*)a + i);
        *((char*)a + i) = aux;
    };
}
