
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    char str01[] = "Hello JavaScript!";
    char str02[] = "Hello TypeScript!";

    puts("> Before `_memmove` call...");
    printf("> str01 = \"%s\".", str01);
    printf("\n> str02 = \"%s\".", str02);

    _memmove(str01, str02, strlen(str02) * sizeof(char));

    puts("\n\n> Before `_memmove` call...");
    printf("> str01 = \"%s\".", str01);
    printf("\n> str02 = \"%s\".", str02);

    return 0;
}
