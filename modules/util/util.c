#include <util.h>

uint16_t fixAngle(int16_t angle)
{
    if(angle < 0)
    {
        angle = 360 + angle;
    }
    angle = angle % 360;
    return angle;
}

uint16_t getRoll(int8_t x, int8_t y, int8_t z)
{
    return fixAngle(toDegrees(-atan2(x,y))+90);
}

uint16_t getPitch(int8_t x, int8_t y, int8_t z)
{
    float g = sqrt(x*x + y*y + z*z);
    return toDegrees(asinf(z/g));
}