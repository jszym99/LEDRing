#define F_CPU 8000000
#define __DELAY_BACKWARD_COMPATIBLE__

#include <util/delay.h>
#include <avr/io.h>
#include <math.h>
#include <display.h>
#include <i2c_master.h>
#include <adxl367.h>
#include <timer.h>
#include <util.h>
#include <sim.h>

// #define LEDCOUNT 72
// #define NUM 9

#define ADXL367 0x53

// static uint16_t lines[] = {0x0020, 0x0008, 0x0004, 0x0002, 0x0001, 0x0100, 0x0200, 0x0400, 0x0080};
// static uint8_t map[NUM] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

int main()
{
    display_init();
    display_clear();
    display_setBrightness(10);
    for(uint8_t i = 0; i < LEDCOUNT; i++)
    {
        display_drawPoint(i);
        display_display();
    }
    for(uint8_t i = 0; i < 100; i++)
    {
        display_display();
        _delay_us(10);
    }

    i2c_master_init();

    adxl367_setMeasMode();

    _delay_ms(100);

    timer_init();

    if(adxl367_available())
    {
        // Run simulation
        while(1)
        {
            // Startup animation
            // if(!(adxl367_getStatusBitmap() & ADXL367_STATUS_AWAKE))
            // {
            //     display_drawLine(0,72);
            //     for(uint8_t i = 0; i < 100; i++)
            //     {
            //         display_display();
            //         _delay_us(10);
            //     }
            //     continue;
            // }
            timer_clear();

            int8_t x = adxl367_getLowResX();
            int8_t y = adxl367_getLowResY();
            int8_t z = adxl367_getLowResZ();

            // struct AccXYZ acc = adxl367_getLowResXYZ();

            // int8_t x = acc.x;
            // int8_t y = acc.y;
            // int8_t z = acc.z;

            double g_x = x/6.4;
            double g_y = y/6.4;

            double alpha = atan2(x,y);

            int16_t angle = toDegrees(-alpha) + 90 + 2.5;
            // y < 0 ? angle += 180 : angle;
            if(angle < 0)
            {
                angle = 360 + angle;
            }

            double millis = timer_read()/1000000.0;
            timer_clear();

            // uint8_t led = pendulum(millis, alpha + toRadians(180));
            // uint8_t led = pendulumSimp(millis, g_y, g_x);
            // uint8_t led = artificialHorizon(x, y, z);
            // display_setLed(led);

            // Simulate artificial horizon

            // Calculate line start and end
            int16_t start = fixAngle(getRoll(x,y,z) - getPitch(x,y,z) - 90)/RESOLUTION;
            int16_t end = fixAngle(getRoll(x,y,z) + getPitch(x,y,z) + 90)/RESOLUTION;

            display_clear();
            
            display_drawLine(start, end);

            display_display();
            _delay_us(10);
        }
    }
    else
    {
        // Run mockup
        display_init();
        display_clear();
        display_drawPoint(0);
        // display_update();
        display_display();
        display_drawPoint(LEDCOUNT/2-1);

        static uint8_t cycles = 0;
        uint8_t led = 0;

        while(1)
        {
            if(cycles >= 10)
            {
                display_clear();
                display_drawPoint(led);
                // display_drawPoint(0);
                cycles = 0;
            }
            else
            {
                cycles++;
            }
            
            // Update and wait
            // display_update();
            display_display();
            // led = pendulum(0.001, toRadians(90));
            led = pendulumSimp(0.001, 0, -10);
            _delay_us(100);
        }
    }
}