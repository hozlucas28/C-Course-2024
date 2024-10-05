
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    int _int01 = 15;
    int _int02 = 30;

    float _float01 = 1.14;
    float _float02 = 8.95;

    int _intArr01[] = {1, 2, 3, 4};
    int _intArr02[] = {10, 12, 13};

    swap(&_int01, &_int02, sizeof(int));
    swap(&_float01, &_float02, sizeof(float));
    swap(_intArr01, _intArr02, sizeof(*_intArr02) * 3);

    printf("> _int01 = %d", _int01);
    printf("\n> _int02 = %d", _int02);

    printf("\n\n> _float01 = %f", _float01);
    printf("\n> _float02 = %f", _float02);

    printf("\n\n> _intArr01 = [");
    for (i = 0; i < 4; i++) printf(" %d", *(_intArr01 + i));
    printf(" ]");

    printf("\n> _intArr02 = [");
    for (i = 0; i < 3; i++) printf(" %d", *(_intArr02 + i));
    printf(" ]");

    return 0;
}
