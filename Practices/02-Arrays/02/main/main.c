#include <stdio.h>

#include "../library/main.h"

int main()
{
    const int maxLength = 10;

    int userInput;
    char userInputMsg[] = "\n\n> Enter an integer: ";
    int outOfMaxLength = 0;

    int arr[maxLength];

    IntArray intArr;

    intArr.array = arr;
    intArr.array[0] = 5;
    intArr.array[1] = 2;
    intArr.array[2] = 3;
    intArr.array[3] = 10;
    intArr.array[4] = 8;
    intArr.occLength = 5;
    intArr.maxLength = maxLength;

    sortAscIntArray(&intArr);
    printReprIntArray(&intArr);

    userInput = getUserInputInt(userInputMsg);
    printf("\n");
    addIntToIntArray(&intArr, userInput);
    printReprIntArray(&intArr);

    while (userInput != -1 && !outOfMaxLength) {
        userInput = getUserInputInt(userInputMsg);
        printf("\n");
        outOfMaxLength = !addIntToIntArray(&intArr, userInput);
        printReprIntArray(&intArr);
    };

    return 0;
}
