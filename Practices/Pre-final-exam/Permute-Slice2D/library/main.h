
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* --------------- Slice2D --------------- */

typedef struct {
    void** arr;
    size_t rows;
    size_t cols;
    size_t sizeOfDataType;
} Slice2D;

// Constructor
Slice2D* newSlice2D(
    const size_t rows,
    const size_t cols,
    const size_t sizeOfDataType
);

// Destroyer
void destroySlice2D(Slice2D* slice);

// Getters
size_t getRows(Slice2D* slice);
size_t getCols(Slice2D* slice);

// Methods
void* getRow(Slice2D* slice, const size_t row);

void insertAt(
    Slice2D* slice,
    const int row,
    const int col,
    const void* element
);

unsigned char permute(Slice2D* slice);

void printSlice2D(
    Slice2D* slice,
    void (*printMethod)(const void* row, const size_t rowLength)
);

#endif // MAIN_LIBRARY_H_INCLUDED
