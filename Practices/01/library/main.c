#include <stdio.h>

int getUserInput() {
    int userInput;

    scanf("%d", &userInput);
    fflush(stdin);

    return userInput;
}

int factorial(int number) {
    int rtn = 1;

    int i = 1;
    for (i = 1; i <= number; i++) {
        rtn *= i;
    };

    return rtn;
}
