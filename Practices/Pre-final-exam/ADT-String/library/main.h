
#ifndef MAIN_XX_H_INCLUDED
#define MAIN_XX_H_INCLUDED

#include <stdlib.h>

/* -------- Utilities -------- */

unsigned char inArr(
    void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    const void* target,
    unsigned char (*cmpMethod)(const void* target, const void* element)
);



/* -------- String ---------- */

typedef struct {
    char* str;
    size_t length;
    size_t capacity;
    size_t growth;
} String;

// Constructor
String* newString(const size_t capacity, const size_t growth);

// Destructor
void destroyString(String* _string);

// Optimizer
size_t clipString(String* _string);

// Getters
char* getStr(String* _string);
size_t getLength(String* _string);
size_t getCapacity(String* _string);
size_t getGrowth(String* _string);

// Setters
unsigned char setStr(String* _string, const char* newStr);
void setGrowth(String* _string, const size_t newGrowth);

// Methods
unsigned char _replace(
    String* _string,
    const char* target,
    const char* newValue
);

size_t _replaceChar(
    String* _string,
    const char target,
    const char newValue
);

unsigned char _replaceAll(
    String* _string,
    const char* target,
    const char* newValue
);

size_t _replaceAllChar(
    String* _string,
    const char target,
    const char newValue
);

char* _findSubString(String* _string, const char* target);
char* _findChar(String* _string, const char target);

size_t capitalize(String* _string, char separators[]);

size_t trim(String* _string);
size_t trimLeft(String* _string);
size_t trimRight(String* _string);

size_t removeExtraSpaces(String* _string);

#endif // MAIN_XX_H_INCLUDED
