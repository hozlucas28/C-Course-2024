
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* ---------- Utilities ---------- */

void _swap(void* a, void* b, size_t sizeOfDataType);



/* ------------ Slice ------------ */

typedef struct {
    void* arr;
    size_t capacity;
    size_t growth;
    size_t length;
    size_t sizeOfDataType;
} Slice;

// Constructor
Slice* newSlice(
    const size_t capacity,
    const float growth,
    const size_t sizeOfDataType
);

// Destroyers
void destroySlice(Slice* slice);
void destroySlice2D(Slice* slice);

// Optimizers
size_t clipSlice(Slice* slice);
size_t clipSlice2D(Slice* slice);

// Getters
size_t getLength(Slice* slice);
size_t getGrowth(Slice* slice);

// Setters
void setGrowth(Slice* slice, const size_t newGrowth);

// Methods
void* getElement(Slice* slice, const size_t index);

void* findElement(
    Slice* slice,
    const void* element,
    unsigned char (*cmpMethod)(const void* a, const void* b)
);

void* findElementBSearch(
    Slice* slice,
    const void* element,
    int (*cmpMethod)(const void* a, const void* b)
);

unsigned char unshift(Slice* slice, const void* element);
unsigned char push(Slice* slice, const void* element);

void shift(Slice* slice);
void pop(Slice* slice);

size_t _replace(
    Slice* slice,
    const void* element,
    unsigned char (*cmpMethod)(const void* a)
);

size_t filter(Slice* slice, unsigned char (*cmpMethod)(const void* a));

void _sort(
    Slice* slice,
    void (*sortMethod)(
        const void* arr,
        const size_t length,
        const size_t sizeOfDataType,
        int (*cmpMethod)(const void* a, const void* b)
    ),
    int (*cmpMethod)(const void* a, const void* b)
);

unsigned char concat(Slice* slice01, Slice* slice02);

Slice* clone(Slice* slice);

unsigned char __growth(Slice* slice);

#endif // MAIN_LIBRARY_H_INCLUDED
