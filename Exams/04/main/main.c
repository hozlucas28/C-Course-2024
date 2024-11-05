#include <stdio.h>
#include <stdlib.h>

#include "./functions.h"

int main()
{
    size_t i;
    unsigned char error;
    const char* filePath = "./data.csv";

    Arr* distances = newArr(sizeof(BoatTravelDistance), 20);

    error = getBoatsTravelDistance(filePath, distances);
    if (error) {
        printf("Error! An error occurred on get boats travel distance.");
        return 1;
    };

    for (i = 0; i < distances->length; i++) {
        printf(
            "> %s = %f km.\n",
            ((BoatTravelDistance*)(distances->arr) + i)->plate,
            ((BoatTravelDistance*)(distances->arr) + i)->distance
        );
    };

    destroyArr(distances);

    return 0;
}
