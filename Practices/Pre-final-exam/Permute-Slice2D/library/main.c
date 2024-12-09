
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

// Constructor
Slice2D* newSlice2D(
    const size_t rows,
    const size_t cols,
    const size_t sizeOfDataType
) {
    Slice2D* slice;

    size_t i;
    size_t j;

    if (!rows || !cols) return NULL;

    slice = malloc(sizeof(Slice2D));
    if (slice == NULL) return NULL;

    slice->arr = malloc(rows * sizeof(void*));
    if (slice->arr == NULL) {
        free(slice);
        return NULL;
    };

    for (i = 0; i < rows; i++) {
        *((char**)slice->arr + i) = malloc(cols * sizeOfDataType);

        if (*((char**)slice->arr + i) == NULL) {
            for (j = 0; j < i; j++) free(*((char**)slice->arr + j));
            free(slice->arr);
            free(slice);
            return NULL;
        };
    };

    slice->rows = rows;
    slice->cols = cols;
    slice->sizeOfDataType = sizeOfDataType;

    return slice;
}

// Destroyer
void destroySlice2D(Slice2D* slice) {
    size_t i;

    void* row;

    for (i = 0; i < slice->rows; i++) {
        row = getRow(slice, i);
        free(row);
    };

    free(slice->arr);
    free(slice);
}

// Getters
size_t getRows(Slice2D* slice) {
    return slice->rows;
}

size_t getCols(Slice2D* slice) {
    return slice->cols;
}

// Methods
void* getRow(Slice2D* slice, const size_t row) {
    if (row < 0 || row > slice->rows - 1) return NULL;
    return *((char**)slice->arr + row);
}

void insertAt(
    Slice2D* slice,
    const int row,
    const int col,
    const void* element
) {
    const size_t realRow = ((row % slice->rows) + slice->rows) % slice->rows;
    const size_t realCol = ((col % slice->cols) + slice->cols) % slice->cols;

    void* targetRow = getRow(slice, realRow);

    memcpy(
        (char*)targetRow + realCol * slice->sizeOfDataType,
        element,
        slice->sizeOfDataType
    );
}

unsigned char permute(Slice2D* slice) {
    Slice2D* aux;

    size_t  j;
    size_t  i;

    void* row;
    void* auxRow;

    aux = newSlice2D(slice->cols, slice->rows, slice->sizeOfDataType);
    if (aux == NULL) return 1;

    for (j = 0; j < slice->cols; j++) {
        for (i = 0; i < slice->rows; i++) {
            row = getRow(slice, i);
            auxRow = getRow(aux, j);

            memcpy(
                (char*)auxRow + i * aux->sizeOfDataType,
                (char*)row + j * slice->sizeOfDataType,
                slice->sizeOfDataType
            );
        };
    };

    for (i = 0; i < slice->rows; i++) {
        row = getRow(slice, i);
        free(row);
    };

    free(slice->arr);

    slice->arr = aux->arr;
    slice->rows = aux->rows;
    slice->cols = aux->cols;

    free(aux);

    return 0;
}

void printSlice2D(
    Slice2D* slice,
    void (*printMethod)(const void* row, const size_t rowLength)
) {
    size_t i;

    void* row;

    for (i = 0; i < slice->rows; i++)  {
        row = getRow(slice, i);

        printf("\n");
        printMethod(row, slice->cols);
    };
}
