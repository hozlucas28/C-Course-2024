#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getStrLength(char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}

char* getUserInputStr(char* message, int strLength) {
    char* userInput = malloc(strLength * sizeof(char));

    printf("%s", message);
    scanf("%s", userInput);
    fflush(stdin);

    return userInput;
}

double strToDouble(char* str) {
    double rtn = 0;
    sscanf(str, "%lf", &rtn);
    return rtn;
}
