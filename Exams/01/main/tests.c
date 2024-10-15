
#include <stdlib.h>

#include "./methods.h"
#include "./structs.h"
#include "./utilities.h"
#include "./tests.h"

unsigned char createTestFile(const char* filePath) {
    const size_t fileLinesLength = 13;

    Sensor fileLines[] = {
        {
            .code = "DEV08",
            .state = "OFFLINE",
            .temperature = 16.50,
            .unixTimeStamp = 1719077360,
        },
        {
            .code = "DEV08",
            .state = "BUSY",
            .temperature = 21.20,
            .unixTimeStamp = 1719077367,
        },
        {
            .code = "DEV08",
            .state = "READY",
            .temperature = 33.50,
            .unixTimeStamp = 1719077371,
        },
        {
            .code = "DEV01",
            .state = "READY",
            .temperature = 17.90,
            .unixTimeStamp = 1719077371,
        },
        {
            .code = "DEV01",
            .state = "READY",
            .temperature = 23.50,
            .unixTimeStamp = 1719077380,
        },
        {
            .code = "DEV01",
            .state = "READY",
            .temperature = 15.90,
            .unixTimeStamp = 1719077384,
        },
        {
            .code = "DEV01",
            .state = "BUSY",
            .temperature = 20.80,
            .unixTimeStamp = 1719077392,
        },
        {
            .code = "DEV03",
            .state = "READY",
            .temperature = 16.50,
            .unixTimeStamp = 1719077400,
        },
        {
            .code = "DEV09",
            .state = "READY",
            .temperature = 21.30,
            .unixTimeStamp = 1719077402,
        },
        {
            .code = "DEV03",
            .state = "READY",
            .temperature = 18.10,
            .unixTimeStamp = 1719077406,
        },
        {
            .code = "DEV07",
            .state = "BUSY",
            .temperature = 31.50,
            .unixTimeStamp = 1719077411,
        },
        {
            .code = "DEV05",
            .state = "READY",
            .temperature = 16.00,
            .unixTimeStamp = 1719077416,
        },
        {
            .code = "DEV05",
            .state = "OFFLINE",
            .temperature = 17.50,
            .unixTimeStamp = 1719077417,
        },
    };

    return writeFile(
        filePath,
        fileLines,
        fileLinesLength,
        sizeof(*fileLines),
        &fWriteSensor
    );
}
