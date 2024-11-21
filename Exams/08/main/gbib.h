#ifndef GBIB_H_INCLUDED
#define GBIB_H_INCLUDED

#include <math.h>

/* --------------------------------- Records -------------------------------- */

#define MAXIMUM_RECORDS 80000
#define MAXIMUM_FIELDS_PER_RECORD 30

#define FIELD_SEPARATOR '|'
#define RECORD_FIELD_DATA_TYPE float

#define MAXIMUM_RECORD_LINE pow(2, sizeof(RECORD_FIELD_DATA_TYPE)) * MAXIMUM_FIELDS_PER_RECORD\
    + MAXIMUM_FIELDS_PER_RECORD - 1\
    + 2

/* ------------------------------ Permutations ------------------------------ */

#define MINIMUM_RECORD_PERMUTATION 0
#define MAXIMUM_RECORD_PERMUTATION MAXIMUM_RECORDS - 1

#define MINIMUM_FIELD_PERMUTATION 0
#define MAXIMUM_FIELD_PERMUTATION MAXIMUM_FIELDS_PER_RECORD - 1

#define PERMUTATION_FIELD_LENGTH 5

#define MAXIMUM_PERMUTATION_LINE PERMUTATION_FIELD_LENGTH * 2 + 2


/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */

typedef struct {
    size_t index01;
    size_t index02;
} Permutation;


/* -------------------------------------------------------------------------- */
/*                                   CLASSES                                  */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- Slice --------------------------------- */

typedef struct {
    void* arr;
    size_t length;
    size_t maxLength;
    size_t initialMaxLength;
    float growthPercentage;
    size_t sizeOfDataType;
} Slice;

Slice* newSlice(
    const size_t initialMaxLength,
    const float growthPercentage,
    const size_t sizeOfDataType
);

void destroySlice(Slice* slice);
void destroySlice2D(Slice* slice);

// Getters
void* getElement(Slice* slice, const size_t index);

// Setters
unsigned char __setMaxLength(Slice* slice, const size_t newMaxLength);

// Methods
unsigned char appendElement(Slice* slice, const void* element);
void printSlice(Slice* slice, void (*printMethod)(const void* element, const size_t i, Slice* slice));


/* -------------------------------------------------------------------------- */
/*                             UTILITIES FUNCTIONS                            */
/* -------------------------------------------------------------------------- */

unsigned char isBetween(const int number, const int a, const int b);

int _min(const int a, const int b);
int _max(const int a, const int b);
void _swap(const void* a, const void* b, const size_t sizeOfDataType);

int parseToRecord(char* line, Slice* record);
int parseToPermutation(char* line, Permutation* permutation);

void printFloat(const void* element, const size_t i, Slice* slice);
void printPermutation(Permutation* permutation);
void printRow(const void* element, const size_t i, Slice* slice);


/* -------------------------------------------------------------------------- */
/*                             ORIGINAL FUNCTIONS                             */
/* -------------------------------------------------------------------------- */

int crearLotePrueba(const char* nomArchivo);

int permutarColumna(
    const char* archOri,
    const char* archDes,
    unsigned campo
);

int restaurarColumna(
    const char* archOri,
    const char* archDes,
    unsigned campo
);

int restaurarColumnaALU(
    const char* archOri,
    const char* archDes,
    unsigned campo
);

#endif // GBIB_H_INCLUDED
