#include <stdio.h>

#include "../../01/library/library.h"

int requestUserInput(
    char* msg,
    char* failValidationMsg,
    int (*validationFn)(int)
){
    int userInput;

    printf(msg);
    userInput = getUserInput();

    while (!(*validationFn)(userInput)) {
        printf(failValidationMsg);
        printf(msg);
        userInput = getUserInput();
    };

    return userInput;
}
