#ifndef ADXL367_H
#define ADXL367_H

#include "adxl367_def.h"
#include <stdint-gcc.h>

struct AccXYZ
{
    int8_t x;
    int8_t y;
    int8_t z;
};


uint8_t adxl367_available();

uint8_t adxl367_getStatusBitmap();
uint8_t adxl367_getStatus2Bitmap();
void adxl367_setMeasMode();

int8_t adxl367_getLowResX();
int8_t adxl367_getLowResY();
int8_t adxl367_getLowResZ();

struct AccXYZ adxl367_getLowResXYZ(); // TODO

/* -------------------------------- TODO: Not yet implemented or verified -------------------------------- */

// typedef enum
// {
//     INACTIVE = 0x00,
//     ABSOLUTE = 0x01,
//     REFERENCED = 0x03,
// } ActDetectMode;

// typedef enum
// {
//     DEFAULT = 0x00,
//     LINK = 0x01,
//     LOOP = 0x03,
// } LinkLoopMode;

// typedef ActDetectMode InactDetectMode;

// int16_t adxl367_getHighResX();
// int16_t adxl367_getHighResY();
// int16_t adxl367_getHighResZ();

// void adxl367_setAutosleepMode();

// void adxl367_setTapThreshold(uint8_t threshold);
// void adxl367_setTapDuration(uint8_t duration);

// void adxl367_setActThreshold(uint16_t threshold);
// void adxl367_setActDuration(uint8_t duration);
// void adxl367_setActMode(ActDetectMode mode);

// void adxl367_setInactThreshold(uint16_t threshold);
// void adxl367_setInactDuration(uint16_t duration);
// void adxl367_setInactMode(InactDetectMode mode);

// void adxl357_setLinkLoopMode(LinkLoopMode mode);

// uint8_t adxl367_getActInactControl();
// void adxl367_setActInactControl(uint8_t bitmap);

// void adxl367_configInt1(uint16_t bitmap);


#endif /* ADXL367_H */