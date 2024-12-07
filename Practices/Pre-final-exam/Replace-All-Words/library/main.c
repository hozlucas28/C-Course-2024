
#include <string.h>

#include "./main.h"

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

void destroyString(String* _string) {
    free(_string->str);
    free(_string);
}

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

size_t setStr(String* _string, char* newStr) {
    const size_t newStrLength = strlen(newStr);
    const size_t newLength = _string->length + newStrLength;

    size_t newCapacity;
    char* aux;

    size_t i;

    if (newLength > _string->capacity) {
        newCapacity = _string->capacity;

        while (newLength > newCapacity) {
            newCapacity += _string->growth;
        };

        aux = realloc(_string->str, newCapacity + 1);
        if (aux == NULL) return 1;

        _string->str = aux;

        for (i = _string->capacity + 1; i < newCapacity + 1; i++) {
            *(_string->str + i) = '\0';
        };

        _string->capacity = newCapacity;
    };

    for (i = 0; i < newStrLength; i++) {
        *(_string->str + i) = *(newStr + i);
    };

    _string->length = newLength;

    return 0;
}

unsigned char setCapacity(String* _string) {
    size_t i;

    char* aux;
    const size_t newCapacity = _string->capacity + _string->growth;

    aux = realloc(_string->str, sizeof(char) * (newCapacity + 1));
    if (aux == NULL) return 1;

    _string->str = aux;

    for (i = _string->capacity; i < newCapacity; i++) {
        *(_string->str + i) = '\0';
    };

    _string->capacity = newCapacity;

    return 0;
}

void setGrowth(String* _string, size_t newGrowth) {
    _string->growth = newGrowth;
}

unsigned char pushChar(String* _string, const char _char) {
    unsigned char error;

    if (_string->length == _string->capacity) {
        error = setCapacity(_string);
        if (error) return 1;
    };

    *(_string->str + _string->length) = _char;
    _string->length++;

    return 0;
}

unsigned char pushStr(String* _string, char* _stringToPush) {
    const size_t _stringToPushLength = strlen(_stringToPush);
    const size_t newLength = _string->length + _stringToPushLength;

    size_t newCapacity;
    char* aux;

    size_t i;

    if (newLength > _string->capacity) {
        newCapacity = _string->capacity;

        while (newLength > newCapacity) {
            newCapacity += _string->growth;
        };

        aux = realloc(_string->str, newCapacity + 1);
        if (aux == NULL) return 1;

        _string->str = aux;

        for (i = _string->capacity + 1; i < newCapacity + 1; i++) {
            *(_string->str + i) = '\0';
        };

        _string->capacity = newCapacity;
    };

    for (i = 0; i < _stringToPushLength; i++) {
        *(_string->str + _string->length + i) = *(_stringToPush + i);
    };

    _string->length = newLength;

    return 0;
}

unsigned char _replaceAllWords(
    String* _string,
    char* target,
    char* newValue,
    char* wordSeparators
) {
    String* aux;

    size_t i;
    size_t j;

    char* headChar;
    char* tailChar;
    char* separator;

    char targetChar;

    aux = newString(_string->capacity, _string->growth);
    if (aux == NULL) return 1;

    for (i = 0; i < _string->length; i++) {
        headChar = _string->str + i;

        separator= strchr(wordSeparators, *headChar);
        if (separator != NULL) {
            pushChar(aux, *headChar);
            continue;
        };

        for (j = 0; *(target + j) != '\0'; j++) {
            tailChar = _string->str + i + j;
            targetChar = *(target + j);
            if (*tailChar != targetChar) break;
        };

        if (*(target + j) == '\0') {
            tailChar = _string->str + i + j - 1;

            separator = strchr(wordSeparators, *(tailChar + 1));
            if (separator == NULL) {
                pushChar(aux, *headChar);
                continue;
            };

            separator = strchr(wordSeparators, *(headChar - 1));
            if (separator == NULL) {
                pushChar(aux, *headChar);
                continue;
            };

            i += (j - 1);

            for (j = 0; *(newValue + j) != '\0'; j++) {
                pushChar(aux, *(newValue + j));
            };

            continue;
        };

        pushChar(aux, *headChar);
    };

    free(_string->str);

    _string->str = aux->str;
    _string->length = aux->length;
    _string->capacity = aux->capacity;

    free(aux);

    return 0;
}

void rewindString(String* _string) {
    size_t i;

    for (i = 0; i < _string->length; i++) {
        *(_string->str + i) = '\0';
    };

    _string->length = 0;
}
