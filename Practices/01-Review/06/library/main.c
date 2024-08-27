#include "math.h"

#include "../../01/library/library.h"

double calculateSin(double number, double tolerance) {
    double term = number;
    double result = term;

    int i;
    int flag = 0;

    for (i = 3; fabs(term) > tolerance; i += 2) {
        term = pow(number, i) / factorial(i);
        result += flag ? +term : -term;
        flag = !flag;
    };

    return result;
}
