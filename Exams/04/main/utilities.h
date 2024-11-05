#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <math.h>

// Radius of the Earth in kilometers
#define R 6371.0f

float toRadians(float degree);

// Calculate distance using the Haversine formula
float haversine(float lat1, float lon1, float lat2, float lon2);

#endif // UTILITIES_H_INCLUDED
