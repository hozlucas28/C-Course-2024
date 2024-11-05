
#include <math.h>

#include "./utilities.h"

float toRadians(float degree) {
    return degree * (M_PI / 180.0f);
}

float haversine(float lat1, float lon1, float lat2, float lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    float dlat = lat2 - lat1;
    float dlon = lon2 - lon1;

    float a = sinf(dlat / 2) * sinf(dlat / 2) + cosf(lat1) * cosf(lat2) * sinf(dlon / 2) * sinf(dlon / 2);
    float c = 2 * atan2f(sqrtf(a), sqrtf(1 - a));

    float distance = R * c;

    return distance;
}
