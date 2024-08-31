#include <ctype.h>
#include <stdio.h>

#include "main.h"

void deleteExtraSpaces(char* str) {
    int i;
    int j;
    int strLength = getStrLength(str);

    int extraSpaces;

    for (i = 0; i < strLength; i++) {
        if (isspace(*(str + i)) && isspace(*(str + i + 1))) {

            extraSpaces = 1;
            while (isspace(*(str + i + extraSpaces + 1))) extraSpaces++;

            for (j = i + extraSpaces + 1; !isspace(*(str + j)); j++) {
                *(str + i + 1) = *(str + j);
                *(str + j) = ' ';
                i++;
            };

            strLength -= extraSpaces;
        };
    };
}

int getStrLength(char* str) {
    int length = 0;

    while(*str != '\0') {
        length++;
        str++;
    }

    return length;
}

void normalizeStr(char* str) {
    toCapitalize(str);
    trimStr(str);
    deleteExtraSpaces(str);
}

void toCapitalize(char* str) {
    int i;
    int strLenght = getStrLength(str);

    char strChar;
    int leadingSpace;
    int trailingSpace;

    for (i = 0; i < strLenght; i++) {
        strChar = *(str + i);
        leadingSpace = i == 0 || isspace(*(str + i - 1));
        trailingSpace = i == strLenght - 1 || isspace(*(str + i + 1));

        if (leadingSpace && !trailingSpace) {
            *(str + i) = toupper(strChar);
        } else {
            *(str + i) = tolower(strChar);
        };
    };
}

void trimStr(char* str) {
    trimLeftStr(str);
    trimRightStr(str);
}

void trimLeftStr(char* str) {
    int i;
    int j;
    int strLength = getStrLength(str);

    int counter = 0;

    for (i = 0; i < strLength; i++) {
        if (!isspace(*(str + i))) break;
        counter++;
    };

    for (j = 0; j < strLength - counter; j++) {
        *(str + j) = *(str + j + counter);
    };

    *(str + strLength - counter) = '\0';
}

void trimRightStr(char* str) {
    int i;
    int strLength = getStrLength(str);

    int counter = 0;

    for (i = strLength - 1; i >= 0; i--) {
        if (!isspace(*(str + i))) break;
        counter++;
    };

    *(str + strLength - counter) = '\0';
}
