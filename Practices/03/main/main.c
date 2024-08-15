#include <math.h>
#include <stdio.h>

#include "../library/library.h"
#include "../../01/library/library.h"

int main()
{
    int exponential;

    double tolerance;
    double calculatedE;

    printf("> Enter an exponential (integer): ");
    exponential = getUserInput();

    printf("> Enter a tolerance (double): ");
    tolerance = getUserInputFloat();

    calculatedE = calculateE(exponential, tolerance);

    printf(
        "> e^%d is equal to %f (limited by %f of tolerance).",
        exponential,
        calculatedE,
        tolerance
    );

    return 0;
}
