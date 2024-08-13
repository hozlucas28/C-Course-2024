#include <stdio.h>
#include <stdlib.h>
#include "../library/library.h"

int main()
{
    int userInput;
    int factorialResult;

    printf("> Enter an integer: ");
    userInput = getUserInput();

    factorialResult = factorial(userInput);

    printf("> Factorial of %d is equal to %d.", userInput, factorialResult);
    return 0;
}
