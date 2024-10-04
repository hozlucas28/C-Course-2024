
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* str = "Hello world!";
    char* strcopy = _strcpy(str);

    int _int = 20;
    int* _intCpy = cpy(&_int, sizeof(int));
    _int -= 10;

    float _float = 02.2002;
    float* _floatCpy = cpy(&_float, sizeof(float));
    _float -= 01.4004;

    char _char = 'L';
    char* _charCpy = cpy(&_char, sizeof(char));
    _char = 'H';

    printf("> str = %s", str);
    printf("\n> strcopy = %s", strcopy);

    free(strcopy);

    printf("\n\n> _int = %d", _int);
    printf("\n> _intCpy = %d", *_intCpy);

    free(_intCpy);

    printf("\n\n> _float = %f", _float);
    printf("\n> _floatCpy = %f", *_floatCpy);

    free(_floatCpy);

    printf("\n\n> _char = %c", _char);
    printf("\n> _charCpy = %c", *_charCpy);

    free(_charCpy);

    return 0;
}
