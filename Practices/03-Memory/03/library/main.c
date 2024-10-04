
#include <stdlib.h>

void* make(int length, size_t sizeOfType) {
    void* reservedMemory = malloc(sizeOfType * length);
    return reservedMemory;
}
