#include <ctype.h>
#include <stdbool.h>

#include "main.h"

int countWord(char* str, char* word) {
    int i;
    int j;
    int counter = 0;

    char strChar;
    char wordChar;

    int strLength = getStrLength(str);
    int wordLength = getStrLength(word);

    int leadingSpace;
    int trailingSpace;

    for (i = 0; i < strLength && i + wordLength < strLength; i++) {
        strChar = toupper(*(str + i));
        wordChar = toupper(*word);

        leadingSpace = i == 0 || !isalnum(*(str + i - 1));

        if (strChar == wordChar && leadingSpace) {
            for (j = 1; j < wordLength; j++) {
                i++;
                strChar = toupper(*(str + i));
                wordChar = toupper(*(word + j));
                if (strChar != wordChar) break;
            };

            trailingSpace = i == strLength - 1 || !isalnum(*(str + i + 1));

            if (j == wordLength && trailingSpace) counter++;
        };
    };

    return counter;
}

int getStrLength(char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}
