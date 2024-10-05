
#include "./structs.h"
#include "./utilities.h"

#include "../library/main.c"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i;

    int arrInt[] = {1, 3, 5, 2, 1, 10, 9, 9};

    Student students[] = {
        {
            .age = 22,
            .fullName = "Lucas Hoz"
        },
        {
            .age = 16,
            .fullName = "Juan Gimenez"
        },
        {
            .age = 21,
            .fullName = "Gustavo Oliveres"
        },
        {
            .age = 22,
            .fullName = "Miguel Garcia"
        }
    };

    sort(arrInt, 8, sizeof(int), &cmpAscInt);

    printf("> arrInt (ascendant sorted) = [");
    for (i = 0; i < 8; i++) {
        printf(" %d", *(arrInt + i));
    };
    printf(" ]");

    sort(arrInt, 8, sizeof(int), &cmpDesInt);

    printf("\n> arrInt (descendant sorted) = [");
    for (i = 0; i < 8; i++) {
        printf(" %d", *(arrInt + i));
    };
    printf(" ]");

    sort(students, 4, sizeof(Student), &cmpAscStudentByAge);

    printf("\n> students (ascendant sorted by `age` field) = [");
    for (i = 0; i < 4; i++) {
        printf(
            " {age: %d, fullName: %s}",
            (students + i)->age,
            (students + i)->fullName
        );
    };
    printf(" ]");

    sort(students, 4, sizeof(Student), &cmpDesStudentByAge);

    printf("\n> students (descendant sorted by `age` field) = [");
    for (i = 0; i < 4; i++) {
        printf(
            " {age: %d, fullName: %s}",
            (students + i)->age,
            (students + i)->fullName
        );
    };
    printf(" ]");

    return 0;
}
