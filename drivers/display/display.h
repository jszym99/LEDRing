#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint-gcc.h>

#define PINCOUNT 9
#define LEDCOUNT (PINCOUNT * (PINCOUNT - 1)) // 72
#define RESOLUTION (360/LEDCOUNT)

void display_init();
void display_clear();
void display_display();
// void display_update();
void display_drawPoint(uint8_t num);
void display_drawLine(uint8_t x1, uint8_t x2);
void display_setLed(uint8_t pixNum);
void display_setBrightness(uint8_t brt);

#endif /* DISPLAY_H */