#ifndef LIBRARY_02_H_INCLUDED
#define LIBRARY_02_H_INCLUDED

#include <stdbool.h>

int requestUserInput(
    char* msg,
    char* failValidationMsg,
    bool (*validationFn)(int)
);

#endif // LIBRARY_02_H_INCLUDED
