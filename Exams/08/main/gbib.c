
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./gbib.h"


/* -------------------------------------------------------------------------- */
/*                                   CLASSES                                  */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- Slice --------------------------------- */

Slice* newSlice(
    const size_t initialMaxLength,
    const float growthPercentage,
    const size_t sizeOfDataType
) {
    Slice* slice = malloc(sizeof(Slice));
    if (slice == NULL) return NULL;

    slice->arr = malloc(sizeOfDataType * initialMaxLength);
    if (slice->arr == NULL) return NULL;

    slice->length = 0;
    slice->maxLength = initialMaxLength;
    slice->initialMaxLength = initialMaxLength;
    slice->growthPercentage = growthPercentage;
    slice->sizeOfDataType = sizeOfDataType;

    return slice;
}

void destroySlice(Slice* slice) {
    free(slice->arr);
    free(slice);
}

void destroySlice2D(Slice* slice) {
    size_t i;

    Slice* row;

    for (i = 0; i < slice->length; i++) {
        row = getElement(slice, i);
        if (row == NULL) break;

        free(row->arr);
    };

    free(slice->arr);
    free(slice);
}

// Getters
void* getElement(Slice* slice, const size_t index) {
    if (isBetween(index, 0, slice->length - 1)) {
        return (char*)slice->arr + index * slice->sizeOfDataType;
    };

    return NULL;
}

// Setters
unsigned char __setMaxLength(Slice* slice, const size_t newMaxLength) {
    void* aux;

    if (newMaxLength == slice->maxLength) return 1;

    aux = realloc(slice->arr, newMaxLength);
    if (aux == NULL) return 1;

    slice->arr = aux;
    slice->maxLength = newMaxLength;

    return 0;
}

// Methods
unsigned char appendElement(Slice* slice, const void* element) {
    unsigned char error;
    size_t newMaxLength;

    if (slice->length == slice->maxLength) {
        newMaxLength = _max(1, slice->initialMaxLength * slice->growthPercentage + slice->maxLength);
        error = __setMaxLength(slice, newMaxLength);
        if (error) return 1;
    };

    memcpy(
        (char*)slice->arr + slice->length * slice->sizeOfDataType,
        element,
        slice->sizeOfDataType
    );

    slice->length++;

    return 0;
}

void printSlice(Slice* slice, void (*printMethod)(const void* element, const size_t i, Slice* slice)) {
    size_t i;

    void* element;

    for (i = 0; i < slice->length; i++) {
        element = getElement(slice, i);
        if (element == NULL) break;

        printMethod(element, i, slice);
    };
}


/* -------------------------------------------------------------------------- */
/*                             UTILITIES FUNCTIONS                            */
/* -------------------------------------------------------------------------- */

unsigned char isBetween(const int number, const int a, const int b) {
    return number >= a && number <= b;
}

int _min(const int a, const int b) {
    return a < b ? a : b;
}

int _max(const int a, const int b) {
    return a > b ? a : b;
}

void _swap(const void* a, const void* b, const size_t sizeOfDataType) {
    size_t i;

    char aux;

    for (i = 0; i < sizeOfDataType; i++) {
        aux = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = aux;
    };
}

int parseToRecord(char* line, Slice* record) {
    int numberOfScans = 0;

    float field;
    char* sep = strchr(line, FIELD_SEPARATOR);

    while (sep != NULL) {
        if (sscanf(line, "%f", &field) == 1) {
            numberOfScans++;
            appendElement(record, &field);
        };

        line = sep + 1;
        sep = strchr(line, FIELD_SEPARATOR);
    };

    if (!isspace(*line)) {
        if (sscanf(line, "%f", &field) == 1) {
            numberOfScans++;
            appendElement(record, &field);
        };
    };

    return numberOfScans;
}

int parseToPermutation(char* line, Permutation* permutation) {
    int numberOfScans = 0;

    int index01;
    int index02;

    numberOfScans += sscanf(line, "%d%d", &index01, &index02);

    permutation->index01 = index01;
    permutation->index02 = index02;

    return numberOfScans;
}

void printFloat(const void* element, const size_t i, Slice* slice) {
    float* _element = (float*)element;
    const int padding = 6;

    if (i == 0) {
        printf("[ %*.2f", padding, *_element);
    } else if (i == slice->length - 1) {
        printf(" %*.2f ]", padding, *_element);
    } else {
        printf(" %*.2f", padding, *_element);
    };
}

void printPermutation(Permutation* permutation) {
    printf(
        "{ index01: %d, index02: %d }",
        (int)permutation->index01,
        (int)permutation->index02
    );
}

void printRow(const void* element, const size_t i, Slice* slice) {
    Slice* _element = (Slice*)element;
    printSlice(_element, &printFloat);
    puts("");
}

/* -------------------------------------------------------------------------- */
/*                             ORIGINAL FUNCTIONS                             */
/* -------------------------------------------------------------------------- */

int restaurarColumnaALU(
    const char* archOri,
    const char* archDes,
    unsigned campo
){
    size_t i;
    size_t j;

    FILE* fArchOri;
    FILE* fArchDes;
    FILE* fPerm;

    const char permPath[] = "./perm.txt";

    size_t recordLineLength = MAXIMUM_RECORD_LINE;
    char recordLine[recordLineLength];

    Slice* row;
    Slice* records;

    size_t permutationLineLength = MAXIMUM_PERMUTATION_LINE;
    char permutationLine[permutationLineLength];

    Permutation permutation;
    Slice* permutations;

    Permutation* permutationAux;
    Slice* record01;
    Slice* record02;
    void* record01Field;
    void* record02Field;

    float* field;
    int lineOffset;

    if (!isBetween(campo, MINIMUM_FIELD_PERMUTATION, MAXIMUM_FIELD_PERMUTATION)) return 0;

    fArchOri = fopen(archOri, "rt");
    if (fArchOri == NULL) return 0;

    records = newSlice(MAXIMUM_RECORDS, 0.1, sizeof(Slice));
    if (records == NULL) {
        fclose(fArchOri);
        return 0;
    };

    while (fgets(recordLine, recordLineLength, fArchOri)) {
        row = newSlice(MAXIMUM_FIELDS_PER_RECORD, 0.1, sizeof(RECORD_FIELD_DATA_TYPE));
        if (row == NULL) return 0;

        if (parseToRecord(recordLine, row) <= MAXIMUM_FIELDS_PER_RECORD) {
            appendElement(records, row);
        };
    };

    fclose(fArchOri);

    fPerm = fopen(permPath, "rt");
    if (fPerm == NULL) {
        destroySlice2D(records);
        return 0;
    };

    permutations = newSlice(MAXIMUM_RECORD_PERMUTATION, 0.1, sizeof(Permutation));
    if (permutations == NULL ) {
        destroySlice2D(records);
        fclose(fPerm);
        return 0;
    };

    while (fgets(permutationLine, permutationLineLength, fPerm)) {
        if (parseToPermutation(permutationLine, &permutation) == 2) {
            appendElement(permutations, &permutation);
        };
    };

    fclose(fPerm);

    for (i = permutations->length - 1; i >= 0; i--) {
        permutationAux = getElement(permutations, i);
        if (permutationAux == NULL) break;

        record01 = getElement(records, permutationAux->index01);
        if (record01 == NULL) continue;

        record02 = getElement(records, permutationAux->index02);
        if (record02 == NULL) continue;

        record01Field = getElement(record01, campo);
        if (record01Field == NULL) continue;

        record02Field = getElement(record02, campo);
        if (record02Field == NULL) continue;

        _swap(record01Field, record02Field, record01->sizeOfDataType);
    };

    destroySlice(permutations);

    fArchDes = fopen(archDes, "wt");
    if (fArchDes == NULL) {
        destroySlice2D(records);
        return 0;
    };

    for (i = 0; i < records->length; i++) {
        row = getElement(records, i);
        if (row == NULL) break;

        lineOffset = 0;

        for (j = 0; j < row->length; j++) {
            field = getElement(row, j);
            if (field == NULL) break;

            lineOffset += (j == 0) ?
                sprintf(recordLine + lineOffset, "%.2f", *field) :
                sprintf(recordLine + lineOffset, "%c%.2f", FIELD_SEPARATOR, *field);
        };

        fprintf(fArchDes, "%s\n", recordLine);
    };

    fclose(fArchDes);
    destroySlice2D(records);

    return 1;
}

