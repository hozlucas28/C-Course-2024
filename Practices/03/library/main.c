#include <math.h>
#include <stdio.h>
#include "../../01/library/library.h"

double calculateE(int exponential, double tolerance) {
    int i;

    double aux;
    double result;

    aux = 1;
    for(i = 1; aux < tolerance; i++) {
        result = aux;
        aux+=((pow(exponential, i)) / factorial(i));
    };

    return result;
}

float getUserInputFloat() {
    float userInput;

    scanf("%f", &userInput);
    fflush(stdin);

    return userInput;
}
