#include <stdio.h>

#include "../../01/library/library.h"
#include "../../03/library/library.h"

#include "../library/library.h"

int main()
{
    double userInput;
    double tolerance;
    double result;

    printf("> Enter a float: ");
    userInput = getUserInputDouble();

    printf("> Enter a float (tolerance): ");
    tolerance = getUserInputDouble();

    result = calculateSin(userInput, tolerance);
    printf("> sin(%lf) is equal to %lf with %lf of tolerance.", userInput, result, tolerance);

    return 0;
}
