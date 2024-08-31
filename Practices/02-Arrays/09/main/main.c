#include <stdio.h>

#include "../library/main.h"

int main()
{
    char str01[] = "  mY   Title:  amaZing    titlE   ";

    printf("> '%s'", str01);
    normalizeStr(str01);
    printf("\n> '%s'", str01);

    return 0;
}
