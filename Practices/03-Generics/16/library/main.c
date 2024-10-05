
#include <stdlib.h>

void* findMinor(
    void* target,
    size_t length,
    size_t sizeOfDataType,
    unsigned short int (*cmpFn)(void* prevMinor, void* currentTarget)
) {
    unsigned int i;

    void* minor = ((char*)target + sizeOfDataType);
    void* currentTarget;

    for (i = 1; i < length; i++) {
        currentTarget = ((char*)target + sizeOfDataType * i);

        if ((*cmpFn)(minor, currentTarget)) {
            minor = currentTarget;
        };
    };

    return minor;
}
