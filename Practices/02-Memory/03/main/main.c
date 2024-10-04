
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    char* _str = make(sizeof(char), 13);
    int* _int = make(sizeof(int), 1);
    float* _float = make(sizeof(float), 1);
    char* _char = make(sizeof(char), 1);

    strcpy(_str, "Hello world!");
    *_int = 12;
    *_float = 1.18;
    *_char = 'A';

    printf("> _str = \"%s\"", _str);
    printf("\n> _int = %d", *_int);
    printf("\n> _float = %f", *_float);
    printf("\n> _char = '%c'", *_char);

    free(_str);
    free(_int);
    free(_float);
    free(_char);

    return 0;
}
