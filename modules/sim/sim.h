#ifndef SIM_H
#define SIM_H

#include <stdint-gcc.h>

#define G 10 // 1g ~ 9.81 m/s^2

uint8_t pendulum(double time, double g_angle);

uint8_t pendulumSimp(double time, double g_x, double g_y);

uint8_t artificialHorizon(int8_t x, int8_t y, int8_t z);

#endif /* SIM_H */