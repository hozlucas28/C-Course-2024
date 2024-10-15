
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "./macros.h"
#include "./methods.h"
#include "./structs.h"

void parseSensor(char* line, void* storePos) {
    Sensor sensor;

    line += MAX_LINE_LENGTH;

    *line = '\0';
    line -= SENSOR_STATE_MAX_LENGTH;
    sscanf(line, "%s", sensor.state);

    *line = '\0';
    line -= SENSOR_TEMPERATURE_MAX_LENGTH;
    sscanf(line, "%f", &(sensor.temperature));

    *line = '\0';
    line -= SENSOR_CODE_MAX_LENGTH;
    sscanf(line, "%s", sensor.code);

    *line = '\0';
    line -= SENSOR_UNIX_TIMESTAMP_MAX_LENGTH;
    sscanf(line, "%lu", &(sensor.unixTimeStamp));

    memcpy(storePos, &sensor, sizeof(Sensor));
}

void fWriteSensor(FILE* file, void* line) {
    Sensor* sensor = (Sensor*)line;

    fprintf(
        file,
        "%*lu%*s%*.*f%*s\n",
        SENSOR_UNIX_TIMESTAMP_MAX_LENGTH,
        sensor->unixTimeStamp,
        SENSOR_CODE_MAX_LENGTH,
        sensor->code,
        SENSOR_TEMPERATURE_MAX_LENGTH - 2,
        2,
        sensor->temperature,
        SENSOR_STATE_MAX_LENGTH,
        sensor->state
    );
}
