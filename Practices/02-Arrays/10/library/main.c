#include <ctype.h>
#include <math.h>

#include "main.h"

void decode(char* str, char* decodingHash) {
    int i;
    int strLength = getStrLength(str);

    char _char;
    int indexOfChar;
    int letterCounter = 0;
    int offset;
    int decodingHashLength = getStrLength(decodingHash);

    for (i = 0; i < strLength; i++) {
        _char = *(str + i);

        letterCounter = isalpha(_char) ? letterCounter + 1 : 0;

        indexOfChar = getIndexOfCharStr(decodingHash, _char);
        if (indexOfChar < 0) continue;

        offset = indexOfChar + letterCounter;
        if (offset > decodingHashLength - 1) {
            offset = fabs(decodingHashLength - offset);
        };

        *(str + i) = *(decodingHash + offset);
    };
}

int getIndexOfCharStr(char* str, char _char) {
    int i;
    int strLength = getStrLength(str);

    for (i = 0; i < strLength; i++) {
        if (toupper(*(str + i)) == toupper(_char)) {
            return i;
        };
    };

    return -1;
}

int getStrLength(char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}

