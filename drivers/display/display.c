#include <display.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

const uint16_t displayMap[] = {0x0020, 0x0008, 0x0004, 0x0002, 0x0001, 0x0100, 0x0200, 0x0400, 0x0080};
// const uint16_t pinMap[] = {5, 3, 2, 1, 0, 8, 9, 10, 7};

uint8_t displayBuffer[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};//{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t brightness = 0xFF;

void display_init()
{
    TCCR1A = 0x00;
    TCCR1B = 0x00;
    TIMSK1 = 0x00;

    TCCR1B |= 1 << WGM12 | 1 << CS10;

    OCR1AH = 0;//0x03;
    OCR1AL = 100;//0xE8;

    // // Interrupt
    // sei();
    // TIMSK1 |= 1 << OCIE1A;   
}

// ISR(TIM1_COMPA_vect)
// {
//     display_update();
// }

void display_clear()
{
    for(uint8_t i = 0; i < sizeof(displayBuffer); i++){
        displayBuffer[i] = 0x00;
    }
}

void display_resetGpio()
{
    DDRA &= (0x00 | 1 << PA4 | 1 << PA6);
    DDRB &= 0x00;
    PORTA &= (0x00 | 1 << PA4 | 1 << PA6);
    PORTB &= 0x00;
}

// Full display update cycle
void display_display()
{
    for(uint8_t ledNum = 0; ledNum < 72; ledNum++){
        if(displayBuffer[ledNum / 8] & 1 << ledNum % 8){
            display_setLed(ledNum);
            for(uint8_t i = 0; i < brightness; i++)
            {
                _delay_us(1);
            }
        }
        display_resetGpio();
    }
}

// Set One pixel at a time
void display_setLed(uint8_t ledNum)
{
    uint8_t row, col, anode;

    // Clear registers
    display_resetGpio();

    row = ledNum / (PINCOUNT - 1);
    col = ledNum % (PINCOUNT - 1);
    anode = (row + col + 1) % PINCOUNT;

    DDRA |= displayMap[row] | displayMap[anode];    
    DDRB |= (displayMap[row] | displayMap[anode]) >> 8;

    PORTA |= displayMap[anode];
    PORTB |= displayMap[anode] >> 8;
}

// Set single pixel in buffer
void display_drawPoint(uint8_t num)
{
    if(num <= LEDCOUNT)
    {
        displayBuffer[num/8] |= 1 << num % 8;
    }
}

void display_drawLine(uint8_t x1, uint8_t x2)
{
    if(x1 < LEDCOUNT)
    {
        if(x2 >= LEDCOUNT)
        {
            x2 = LEDCOUNT-1;
        }

        if(x2 < x1)
        {
            for(uint8_t i = 0; i < x2; i++)
            {   
                displayBuffer[i/8] |= 1 << i % 8;
            }
            x2 = LEDCOUNT;
        }

        for(uint8_t i = x1; i < x2; i++)
        {   
            displayBuffer[i/8] |= 1 << i % 8;
        }
    }
}

void display_setBrightness(uint8_t brt)
{
    brightness = brt;
}

// // Light next pixel from buffer
// void display_update()
// {
//     static uint16_t ledNum = 0;

//     // Find next pixel to turn on
//     while(!(displayBuffer[ledNum / 8] & 1 << ledNum % 8))
//     {
//         if(ledNum >= LEDCOUNT)
//         {
//             ledNum = 0;
//             return;
//         }
//         ledNum++;
//     }
//     display_setLed(ledNum);
//     ledNum++;
// }