#include <math.h>
#include <stdio.h>

#include "../../01/library/library.h"

double calculateEX(int exponential, double tolerance) {
    int i;

    double term = 1;
    double result = term;

    for(i = 1; fabs(term) >= tolerance; i++) {
        term = pow(exponential, i) / factorial(i);
        result += term;
    };

    return result;
}

double getUserInputDouble() {
    double userInput;

    scanf("%lf", &userInput);
    fflush(stdin);

    return userInput;
}
