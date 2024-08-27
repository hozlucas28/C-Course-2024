#include <stdio.h>
#include <stdlib.h>

#include "../library/library.h"
#include "../../01/library/library.h"

int n;

int (*mValFn)(int userInput);

int mValidationFn(int userInput) {
    return userInput >= n;
}

int (*nValFn)(int userInput);

int nValidationFn(int userInput) {
    return userInput >= 0;
}

int main()
{
    int m;

    char* nMsg;
    char* nFailValidationMsg;

    char mMsg[127];
    char mfailValidationMsg[127];

    int result;
    char resultStr[127];

    nMsg = "> Enter a number (greater or equal to zero): ";
    nFailValidationMsg = "> The number can not be less than zero! Try again...\n";
    nValFn = &nValidationFn;

    n = requestUserInput(
        nMsg,
        nFailValidationMsg,
        nValFn
    );

    sprintf(mMsg, "> Enter a number (greater or equal to %d): ", n);
    sprintf(mfailValidationMsg, "> The number can not be less than %d! Try again...\n", n);
    mValFn = &mValidationFn;

    m = requestUserInput(
        mMsg,
        mfailValidationMsg,
        mValFn
    );

    result = (factorial(m)) / (factorial(n) * factorial(m - n));
    sprintf(resultStr, "[ %d! ] / [ %d! * (%d - %d)! ]", m, n, m, n);

    printf(
        "> The combinatorial number of %s is equal to %d.",
        resultStr,
        result
    );

    return 0;
}
