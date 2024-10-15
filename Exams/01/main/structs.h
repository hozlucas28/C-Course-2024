#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "./macros.h"

typedef unsigned long int UnixTimeStamp;

typedef struct {
    char code[SENSOR_CODE_MAX_LENGTH];
    char state[SENSOR_STATE_MAX_LENGTH];
    float temperature;
    UnixTimeStamp unixTimeStamp;
} Sensor;

#endif // STRUCT_H_INCLUDED
