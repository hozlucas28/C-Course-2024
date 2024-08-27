#ifndef LIBRARY_02_H_INCLUDED
#define LIBRARY_02_H_INCLUDED

int requestUserInput(
    char* msg,
    char* failValidationMsg,
    int (*validationFn)(int)
);

#endif // LIBRARY_02_H_INCLUDED
