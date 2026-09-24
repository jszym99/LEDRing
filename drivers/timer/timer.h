#ifndef TIMER_H
#define TIMER_H

#include <stdint-gcc.h>

void timer_init();
void timer_clear();
uint16_t timer_read();

#endif /* TIMER_H */