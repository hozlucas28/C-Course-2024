
#include <stdio.h>

#include "./macros.h"
#include "./methods.h"
#include "./structs.h"
#include "./tests.h"
#include "./utilities.h"

int main()
{
    char* filePath = "./data.txt";
    unsigned char error = 0;

    Sensor contentRead[MAX_SENSORS];

    error = !createTestFile(filePath);
    if (error) return 1;

    // TODO: Read and store file content.
    error = !readFile(
        filePath,
        contentRead,
        MAX_SENSORS,
        sizeof(Sensor),
        &parseSensor
    );
    if (error) return 1;

    //printf("%s", contentRead->code);

    // remove(filePath);
    printf("dadas");

    return 0;
}
