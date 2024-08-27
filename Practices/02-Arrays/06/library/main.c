#include <ctype.h>
#include <stdbool.h>

int getStrLength(char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}

int isPalindrome(char* str) {
    int i;
    char aux01;
    char aux02;
    int strLength = getStrLength(str);

    for (i = 0; (str + i) != (str + strLength - i - 1); i++) {
        aux01 = tolower(*(str + i));
        aux02 = tolower(*(str + strLength - i - 1));

        if (aux01 != aux02) return 0;
    };

    return 1;
}
