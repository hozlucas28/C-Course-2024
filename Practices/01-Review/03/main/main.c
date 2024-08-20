#include <math.h>
#include <stdio.h>

#include "../library/library.h"
#include "../../01/library/library.h"

int main()
{
    int exponential;

    double tolerance;
    double calculatedEX;

    printf("> Enter an exponential (integer): ");
    exponential = getUserInput();

    printf("> Enter a tolerance (double): ");
    tolerance = getUserInputDouble();

    calculatedEX = calculateEX(exponential, tolerance);

    printf(
        "> e^%d is equal to %lf (limited by %lf of tolerance).",
        exponential,
        calculatedEX,
        tolerance
    );

    return 0;
}
