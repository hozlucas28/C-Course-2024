#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define PLATE_LENGTH 9

typedef struct {
    float latitude;
    float longitude;
    char plate[PLATE_LENGTH];
} BoatPos;

typedef struct {
    float distance;
    float lastLatitude;
    float lastLongitude;
    char plate[PLATE_LENGTH];
} BoatTravelDistance;

typedef struct {
    void* arr;
    size_t length;
    size_t maxLength;
    size_t sizeOfDataType;
} Arr;

#endif // STRUCTS_H_INCLUDED
