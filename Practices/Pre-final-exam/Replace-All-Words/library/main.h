
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* -------- String -------- */

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

// Getters
char* getStr(String* _string);
size_t getLength(String* _string);
size_t getCapacity(String* _string);
size_t getGrowth(String* _string);

// Setters
size_t setStr(String* _string, char* newStr);
unsigned char setCapacity(String* _string);
void setGrowth(String* _string, const size_t newGrowth);

// Methods
unsigned char pushChar(String* _string, const char _char);
unsigned char pushStr(String* _string, char* _stringToPush);

unsigned char _replaceAllWords(
    String* _string,
    char* target,
    char* newValue,
    char* wordSeparators
);

void rewindString(String* _string);

#endif // MAIN_LIBRARY_H_INCLUDED
