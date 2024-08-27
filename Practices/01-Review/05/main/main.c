#include <stdio.h>

#include "../library/library.h"
#include "../../01/library/library.h"

int main()
{
    int userInput;
    int isFibo;
    char* msg;

    printf("> Enter an integer: ");
    userInput = getUserInput();

    isFibo = isFibonacci(userInput);
    msg = isFibo ? "> %d is a Fibonacci number!" : "> %d is not a Fibonacci number!";

    printf(msg, userInput);
    return 0;
}
