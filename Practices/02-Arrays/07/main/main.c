#include <stdio.h>

#include "../library/main.h"

int main()
{
    char* userInputStr;
    char* userInputMsg = "> Enter a number (it is going to be cast from a string to a float): ";

    double userInputDouble;

    userInputStr = getUserInputStr(userInputMsg, 100);
    userInputDouble = strToDouble(userInputStr);

    printf("> '%s' (string) converted to %f (float).", userInputStr, userInputDouble);

    return 0;
}
