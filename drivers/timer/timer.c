#include "time.h"
#include <avr/io.h>

void timer_init()
{
    // Clear timer registers
    TCCR1A = 0x00;
    TCCR1B = 0x00;
    TIMSK1 = 0x00;

    TCCR1B |= 1 << CS11; // Set devider /8
}

void timer_clear()
{
    TCNT1 = 0x0000;
}

uint16_t timer_read()
{
    return TCNT1;
}