#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdlib.h>

#include "./structs.h"

/* Main functions */

unsigned char getBoatsTravelDistance(const char* filePath, Arr* distances);

unsigned char parseToBoatPos(char* line, BoatPos* boatPos);

/* Abstract Data Type (ADT) functions */

Arr* newArr(const size_t sizeOfDataType, const size_t maxLenght);

void destroyArr(Arr* arr);

unsigned char append(Arr* arr, void* element);

void* _find(
    Arr* arr,
    void* target,
    unsigned char (*cmp)(const void* target, const void* element)
);

/* Comparison functions */

unsigned char cmpBoatPlates(const void* boatA, const void* boatB);

#endif // FUNCTIONS_H_INCLUDED
