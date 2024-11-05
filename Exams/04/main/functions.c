
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "./functions.h"
#include "./structs.h"
#include "./utilities.h"

unsigned char getBoatsTravelDistance(
    const char* filePath,
    Arr* distances
) {
    const size_t lineMaxLength = 128;
    char line[lineMaxLength];

    BoatPos boatPos;

    BoatTravelDistance newBoatDistance;
    BoatTravelDistance* boatDistanceFound;

    float newDistance;

    FILE* file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    while (fgets(line, lineMaxLength, file)) {
        parseToBoatPos(line, &boatPos);

        boatDistanceFound = _find(distances, &boatPos, cmpBoatPlates);
        if (boatDistanceFound == NULL) {
            newBoatDistance.distance = 0;
            newBoatDistance.lastLatitude = boatPos.latitude;
            newBoatDistance.lastLongitude= boatPos.longitude;

            strcpy(newBoatDistance.plate, boatPos.plate);

            append(distances, &newBoatDistance);
        } else {
            newDistance = haversine(
                boatPos.latitude,
                boatPos.longitude,
                boatDistanceFound->lastLatitude,
                boatDistanceFound->lastLongitude
            );

            if (boatDistanceFound->distance == 0 || newDistance < boatDistanceFound->distance) {
                boatDistanceFound->distance = newDistance;
            };

            boatDistanceFound->lastLatitude = boatPos.latitude;
            boatDistanceFound->lastLongitude= boatPos.longitude;
        };
    };

    return 0;
}

unsigned char parseToBoatPos(char* line, BoatPos* boatPos) {
    char *_line;
    const char sep = ',';

    // Get plate
    _line = strrchr(line, sep);
    if (_line == NULL) return 1;

    _line++;
    sscanf(_line, "%s", boatPos->plate);
    _line--;
    *_line = '\0';

    // Get longitude
    _line = strrchr(line, sep);
    if (_line == NULL) return 1;

    _line++;
    sscanf(_line, "%f", &(boatPos->longitude));
    _line--;
    *_line = '\0';

    // Get latitude
    sscanf(line, "%f", &(boatPos->latitude));

    return 0;
}

Arr* newArr(const size_t sizeOfDataType, const size_t maxLenght) {
    Arr* arr = malloc(sizeof(Arr));

    arr->arr = malloc(sizeOfDataType * maxLenght);
    arr->length = 0;
    arr->maxLength = maxLenght;
    arr->sizeOfDataType = sizeOfDataType;

    return arr;
}

void destroyArr(Arr* arr) {
    free(arr->arr);
    free(arr);
}

unsigned char append(Arr* arr, void* element) {
    if (arr->length == arr->maxLength) {
        realloc(arr->arr, arr->sizeOfDataType * (arr->length + 1));
        arr->maxLength++;
    };

    memcpy(
        (char*)(arr->arr) + arr->sizeOfDataType * arr->length,
        element,
        arr->sizeOfDataType
    );

    arr->length++;

    return 0;
}

void* _find(
    Arr* arr,
    void* target,
    unsigned char (*cmp)(const void* target, const void* element)
) {
    size_t i;
    void* element;

    for (i = 0; i < arr->length; i++) {
        element = ((char*)arr->arr) + arr->sizeOfDataType * i;
        if (cmp(target, element) == 0) return element;
    };

    return NULL;
}

unsigned char cmpBoatPlates(const void* boatA, const void* boatB) {
    BoatPos* _boatA = (BoatPos*)boatA;
    BoatTravelDistance* _boatB = (BoatTravelDistance*)boatB;

    return strcmp(_boatA->plate, _boatB->plate);
}
