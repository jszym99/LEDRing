#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#include <stdint-gcc.h>

inline double toDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

uint16_t fixAngle(int16_t angle);
uint16_t getRoll(int8_t x, int8_t y, int8_t z);
uint16_t getPitch(int8_t x, int8_t y, int8_t z);

#endif /* UTIL_H */