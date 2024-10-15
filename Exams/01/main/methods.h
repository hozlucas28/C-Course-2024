#ifndef METHODS_H_INCLUDED
#define METHODS_H_INCLUDED

#include <stdio.h>

void parseSensor(char* line, void* storePos);

void fWriteSensor(FILE* file, void* line);

#endif // METHODS_H_INCLUDED
