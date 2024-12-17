
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* -------- Utilities -------- */

unsigned char inArr(
    void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    const void* target,
    unsigned char (*cmpMethod)(const void* target, const void* element)
) {

}



/* -------- String ---------- */

// Constructor
String* newString(const size_t capacity, const size_t growth) {
    String* _string;

    if (!capacity || !growth) return NULL;

    _string = malloc(sizeof(String));
    if (_string == NULL) return NULL;

    _string->str = calloc(capacity + 1, sizeof(char));
    if (_string->str == NULL) {
        free(_string);
        return NULL;
    };

    _string->length = 0;
    _string->capacity = capacity;
    _string->growth = growth;

    return _string;
}

// Destructor
void destroyString(String* _string) {
    free(_string->str);
    free(_string);
}

// Optimizer
size_t clipString(String* _string) {

}

// Getters
char* getStr(String* _string) {
    return _string->str;
}

size_t getLength(String* _string) {
    return _string->length;
}

size_t getCapacity(String* _string) {
    return _string->capacity;
}

size_t getGrowth(String* _string) {
    return _string->growth;
}

// Setters
unsigned char setStr(String* _string, const char* newStr) {
    // TODO
}

void setGrowth(String* _string, const size_t newGrowth) {
    _string->growth = newGrowth;
}

// Methods
unsigned char _replace(
    String* _string,
    const char* target,
    const char* newValue
) {
    // TODO
}

size_t _replaceChar(
    String* _string,
    const char target,
    const char newValue
) {
    // TODO
}

unsigned char _replaceAll(
    String* _string,
    const char* target,
    const char* newValue
) {
    // TODO
}

size_t _replaceAllChar(
    String* _string,
    const char target,
    const char newValue
) {
    // TODO
}

char* _findSubString(String* _string, const char* target) {
    // TODO
}

char* _findChar(String* _string, const char target) {
    // TODO
}

size_t capitalize(String* _string, char separators[]) {
    // TODO
}

size_t trim(String* _string) {
    // TODO
}

size_t trimLeft(String* _string) {
    // TODO
}

size_t trimRight(String* _string) {
    // TODO
}

size_t removeExtraSpaces(String* _string) {
    // TODO
}
