#include <stdio.h>

#include "../library/main.h"

int main()
{
    char* str01 = "Hello World!";
    char* str02 = "Bears loves bears!";
    char* str03 = "I would like a coffee, when I wake up at the morning.";

    int nWords01;
    int nWords02;
    int nWords03;

    nWords01 = countWord(str01, "world");
    printf("> '%s' has %d '%s' words.", str01, nWords01, "world");

    nWords02 = countWord(str02, "bEars");
    printf("\n> '%s' has %d '%s' words.", str02, nWords02, "bEars");

    nWords03 = countWord(str03, "coffee");
    printf("\n> '%s' has %d '%s' words.", str03, nWords03, "coffee");

    return 0;
}
