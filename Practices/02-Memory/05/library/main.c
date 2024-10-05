
#include <stdlib.h>

void* _memmove(void* dest, void* src, size_t totalSizeOf) {
    size_t i;

    for (i = 0; i < totalSizeOf; i++) {
        *((char*)dest + i) = *((char*)src + i);
    };

    return dest;
}
