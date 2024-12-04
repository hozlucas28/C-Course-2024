
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* ---------- Utilities ---------- */

void _swap(void* a, void* b, size_t sizeOfDataType) {
    size_t i;

    char aux;

    for (i = 0; i < sizeOfDataType; i++) {
        aux = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = aux;
    };
}

/* ------------ Slice ------------ */

// Constructor
Slice* newSlice(
    const size_t capacity,
    const float growth,
    const size_t sizeOfDataType
) {
    Slice* slice;

    if (!capacity || !sizeOfDataType) return NULL;

    slice = malloc(sizeof(Slice));
    if (slice == NULL) return NULL;

    slice->arr = malloc(sizeOfDataType * capacity);
    if (slice->arr == NULL) {
        free(slice);
        return NULL;
    };

    slice->capacity = capacity;
    slice->growth = growth;
    slice->length = 0;
    slice->sizeOfDataType = sizeOfDataType;

    return slice;
}

// Destroyers
void destroySlice(Slice* slice) {
    free(slice->arr);
    free(slice);
}

void destroySlice2D(Slice* slice) {
    size_t i;
    Slice* innerSlice;

    for (i = 0; i < slice->length; i++) {
        innerSlice = getElement(slice, 0);
        free(innerSlice->arr);
    };

    destroySlice(slice);
}

// Optimizers
size_t clipSlice(Slice* slice) {
    size_t bytesClipped = 0;

    void* aux;
    size_t newCapacity;

    if (slice->length == slice->capacity) return 0;

    newCapacity = slice->length ? slice->length : 1;

    aux = realloc(slice->arr, newCapacity * slice->sizeOfDataType);
    if (aux == NULL) return 0;

    bytesClipped = (slice->capacity - newCapacity) * slice->sizeOfDataType;

    slice->arr = aux;
    slice->capacity = newCapacity;

    return bytesClipped;
}

size_t clipSlice2D(Slice* slice) {
    size_t bytesClipped = 0;

    size_t i;
    Slice* innerSlice;

    for (i = 0; i < slice->length; i++) {
        innerSlice = getElement(slice, i);
        bytesClipped += clipSlice(innerSlice);
    };

    bytesClipped += clipSlice(slice);

    return bytesClipped;
}

// Getters
size_t getLength(Slice* slice) {
    return slice->length;
}

size_t getGrowth(Slice* slice) {
    return slice->growth;
}

// Setters
void setGrowth(Slice* slice, const size_t newGrowth) {
    slice->growth = newGrowth;
}

// Methods
void* getElement(Slice* slice, const size_t index) {
    if (index < 0 || index > slice->length - 1) return NULL;
    return (char*)slice->arr + index * slice->sizeOfDataType;
}

void* findElement(
    Slice* slice,
    const void* element,
    unsigned char (*cmpMethod)(const void* a, const void* b)
) {
    size_t i;
    void* sliceElement;

    for (i = 0; i < slice->length; i++) {
        sliceElement = getElement(slice, i);
        if (cmpMethod(element, sliceElement)) return sliceElement;
    };

    return NULL;
}

void* findElementBSearch(
    Slice* slice,
    const void* element,
    int (*cmpMethod)(const void* a, const void* b)
) {
    return bsearch(
        element,
        slice->arr,
        slice->length,
        slice->sizeOfDataType,
        cmpMethod
    );
}

unsigned char unshift(Slice* slice, const void* element) {
    size_t i;

    if (slice->length == slice->capacity) {
        if (__growth(slice)) return 1;
    };

    for (i = slice->length; i < 0; i--) {
        _swap(
            (char*)slice->arr + i * slice->sizeOfDataType,
            (char*)slice->arr + (i - 1) * slice->sizeOfDataType,
            slice->sizeOfDataType
        );
    };

    memcpy(
        (char*)slice->arr,
        element,
        slice->sizeOfDataType
    );

    slice->length++;

    return 0;
}

unsigned char push(Slice* slice, const void* element) {
    if (slice->length == slice->capacity) {
        if (__growth(slice)) return 1;
    };

    memcpy(
        (char*)slice->arr + slice->length * slice->sizeOfDataType,
        element,
        slice->sizeOfDataType
    );

    slice->length++;

    return 0;
}

void shift(Slice* slice) {
    size_t i;

    for (i = 0; i < slice->length - 1; i++) {
        _swap(
            (char*)slice->arr + i * slice->sizeOfDataType,
            (char*)slice->arr + (i + 1) * slice->sizeOfDataType,
             slice->sizeOfDataType
        );
    };

    slice->length--;
}

void pop(Slice* slice) {
    slice->length--;
}

size_t _replace(
    Slice* slice,
    const void* element,
    unsigned char (*cmpMethod)(const void* a)
) {
    size_t elementsReplaced = 0;

    size_t i;
    void* sliceElem;

    for (i = 0; i < slice->length; i++) {
        sliceElem = getElement(slice, i);
        if (!cmpMethod(sliceElem)) continue;

        memcpy(
            (char*)slice->arr + i * slice->sizeOfDataType,
            element,
            slice->sizeOfDataType
        );

        elementsReplaced++;
    };

    return 0;
}

size_t filter(Slice* slice, unsigned char (*cmpMethod)(const void* a)) {
    size_t elementsFiltered = 0;

    size_t i;
    size_t j;
    void* element;

    for (i = 0; i < slice->length; i++) {
        element = getElement(slice, i);
        if (!cmpMethod(element)) continue;

        for (j = i; j < slice->length - 1; j++) {
            _swap(
                (char*)slice->arr + i * slice->sizeOfDataType,
                (char*)slice->arr + (i + 1) * slice->sizeOfDataType,
                slice->sizeOfDataType
            );
        };

        slice->length--;
        elementsFiltered++;
        i--;
    };

    return elementsFiltered;
}

void _sort(
    Slice* slice,
    void (*sortMethod)(
        const void* arr,
        const size_t length,
        const size_t sizeOfDataType,
        int (*cmpMethod)(const void* a, const void* b)
    ),
    int (*cmpMethod)(const void* a, const void* b)
) {
    sortMethod(
        slice->arr,
        slice->length,
        slice->sizeOfDataType,
        cmpMethod
    );
}

unsigned char concat(Slice* slice01, Slice* slice02) {
    const size_t newLength = slice01->length + slice02->length;

    void* aux = realloc(slice01->arr, newLength * slice01->sizeOfDataType);
    if (aux == NULL) return 1;

    memcpy(
        (char*)slice01->arr + slice01->length * slice01->sizeOfDataType,
        (char*)slice02->arr,
        slice02->length * slice02->sizeOfDataType
    );

    slice01->arr = aux;
    slice01->length = newLength;
    slice01->capacity = newLength;

    return 0;
}

Slice* clone(Slice* slice) {
    Slice* sliceCloned = newSlice(
        slice->capacity,
        slice->growth,
        slice->sizeOfDataType
    );
    if (sliceCloned == NULL) return NULL;

    memcpy(
        sliceCloned->arr,
        slice->arr,
        slice->length * slice->sizeOfDataType
    );

    sliceCloned->length = slice->length;

    return sliceCloned;
}

unsigned char __growth(Slice* slice) {
    const size_t newCapacity = slice->capacity + slice->growth;

    void* aux = realloc(slice->arr, newCapacity * slice->sizeOfDataType);
    if (aux == NULL) return 1;

    slice->arr = aux;
    slice->capacity= newCapacity;

    return 0;
}
