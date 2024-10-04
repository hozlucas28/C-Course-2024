
#include "./main.h"

#include <stdlib.h>

void* cpy(void* element, size_t sizeOfElement) {
    void* _cpy = malloc(sizeOfElement);
    *((float*) _cpy) = *((float*) element);
    return _cpy;
}

int getStrLength(const char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}

char* _strcpy(const char* str) {
    int i;
    int strLength = getStrLength(str) + 1;

    char* _cpy = malloc(sizeof(char) * strLength);

    for (i = 0; i < strLength; i++) {
        *(_cpy + i) = *(str + i);
    };

    return _cpy;
}

