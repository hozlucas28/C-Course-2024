#include <stdio.h>

#include "../library/main.h"

int main()
{
    char str01[] = "gjlq";
    char str02[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";

    char decodingHash[] = "abcdghijkoqtuv";

    printf("> '%s'", str01);
    decode(str01, decodingHash);
    printf("\n> '%s'", str01);

    printf("\n> '%s'", str02);
    decode(str02, decodingHash);
    printf("\n> '%s'", str02);

    return 0;
}
