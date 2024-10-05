
#include "./utilities.h"
#include "./structs.h"

#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    int intArr[] = {1, 3, 2, 0, -5, -1, 10, 12, -10};
    float floatArr[] = {0.25, 0.10, 0.50, 0.80, -0.05, -1.25, 0.2, 2, -3.75};

    Student students[] = {
        {8.32, "Lucas Hoz", 1000},
        {7.21, "Miguel Gomez", 950},
        {8.32, "Jose Gimenez", 1101}
    };

    int* minorInt = findMinor(intArr, 9, sizeof(int), &cmpInts);
    float* minorFloat = findMinor(floatArr, 9, sizeof(float), &cmpFloats);

    Student* minorStudentByAverage =
        findMinor(
            students,
            3,
            sizeof(Student),
            &cmpStudentsByAverage
        );

    Student* minorStudentByFullName =
        findMinor(
            students,
            3,
            sizeof(Student),
            &cmpStudentsByFullName
        );

    Student* minorStudentByDNI =
        findMinor(
            students,
            3,
            sizeof(Student),
            &cmpStudentsByDNI
        );

    printf("> Minor integer = %d.", *minorInt);
    printf("\n> Minor float = %f.", *minorFloat);

    printf(
        "\n> Minor student by average field = {average: %f, fullName: %s, dni: %d}.",
        minorStudentByAverage->average,
        minorStudentByAverage->fullName,
        minorStudentByAverage->dni
    );

    printf(
        "\n> Minor student by fullName field = {average: %f, fullName: %s, dni: %d}.",
        minorStudentByFullName->average,
        minorStudentByFullName->fullName,
        minorStudentByFullName->dni
    );

    printf(
        "\n> Minor student by dni field = {average: %f, fullName: %s, dni: %d}.",
        minorStudentByDNI->average,
        minorStudentByDNI->fullName,
        minorStudentByDNI->dni
    );

    return 0;
}
