#include "adxl367.h"
#include "adxl367_reg_map.h"
#include "i2c_master.h"

// Helper macros to simplify i2c calls
#define i2c_write(a, d) (i2c_master_write(ADXL367_I2C_ADDR, a, d))
#define i2c_read(a) (i2c_master_read(ADXL367_I2C_ADDR, a))

/**
 * @brief Get device ID
 * 
 * @details Reads device id from device register
 * @return uint8_t Device ID
 */
uint8_t adxl367_getDevId()
{
    return i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_DEVID_AD);
}

/**
 * @brief Check if device is available
 * 
 * @details Reads device ID from the its register and compares it to the expected ID (specified in the datasheet)
 * @return uint8_t 
 */
uint8_t adxl367_available()
{
    if(adxl367_getDevId() != ADXL367_DEVID_AD)
    {
        return 0;
    }
    return 1;
}

uint8_t adxl367_getStatusBitmap()
{
    return i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_STATUS);
}

uint8_t adxl367_getStatus2Bitmap()
{
    return i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_STATUS_2);
}

/**
 * @brief Set device into measurement mode
 * 
 */
void adxl367_setMeasMode()
{
    uint8_t powerCtrl = i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_POWER_CTL); // Read current
    powerCtrl &= ~(0x03U); // Clear measure mode bits
    powerCtrl |= 0x02; // Set to measurement mode
    i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_POWER_CTL, powerCtrl);
}

/**
 * @brief Get low resolution acceleration on X axis
 * 
 * @return int8_t X axis 8 most significant bits
 */
int8_t adxl367_getLowResX()
{
    return i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_XDATA);
}

/**
 * @brief Get low resolution acceleration on Y axis
 * 
 * @return int8_t Y axis 8 most significant bits
 */
int8_t adxl367_getLowResY()
{
    return i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_YDATA);
}

/**
 * @brief Get low resolution acceleration on Z axis
 * 
 * @return int8_t Z axis 8 most significant bits
 */
int8_t adxl367_getLowResZ()
{
    return i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_ZDATA);
}

struct AccXYZ adxl367_getLowResXYZ()
{
    uint8_t buff[3];
    struct AccXYZ out;

    i2c_master_readMulti(ADXL367_I2C_ADDR, ADXL367_REG_XDATA, buff, 3);

    out.x = buff[0];
    out.y = buff[1];
    out.z = buff[2];

    return out;
}

/* -------------------------------- TODO: Not yet implemented or verified -------------------------------- */

// void adxl367_setAutosleepMode()
// {
//     uint8_t powerCtrl = i2c_master_read(ADXL367_I2C_ADDR, ADXL367_REG_POWER_CTL); // Read current
//     powerCtrl &= ~(0X04); // Clear measure mode bits
//     powerCtrl |= 0x04; // Set to measurement mode
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_POWER_CTL, powerCtrl);
// }

// void adxl367_setTapThreshold(uint8_t threshold)
// {
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_TAP_THRESH, threshold);
// }

// void adxl367_setTapDuration(uint8_t duration)
// {
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_TAP_DUR, duration);
// }

// void adxl367_setActThreshold(uint16_t threshold)
// {
//     uint8_t buf[2];
//     buf[0] = threshold << 2u;
//     buf[1] = threshold >> 6u;

//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_THRESH_ACT_L, buf[0]);
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_THRESH_ACT_H, buf[1]);
// }

// void adxl367_setActDuration(uint8_t duration)
// {
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_TIME_ACT, duration);
// }

// void adxl367_setActMode(ActDetectMode mode)
// {
//     uint8_t buf = i2c_read(ADXL367_REG_ACT_INACT_CTL);

//     buf &= ~(0x03); // Clear ACT_EN bits
//     buf |= mode;

//     i2c_write(ADXL367_REG_ACT_INACT_CTL, buf);
// }

// void adxl367_setInactThreshold(uint16_t threshold)
// {
//     uint8_t buf[2];
//     buf[0] = threshold << 2u;
//     buf[1] = threshold >> 6u;

//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_THRESH_INACT_L, buf[0]);
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_THRESH_INACT_H, buf[1]);
// }

// void adxl367_setInactDuration(uint16_t duration)
// {
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_TIME_INACT_L, duration);
//     i2c_master_write(ADXL367_I2C_ADDR, ADXL367_REG_TIME_INACT_H, duration >> 8u);
// }

// void adxl367_setInactMode(InactDetectMode mode)
// {
//     uint8_t buf = i2c_read(ADXL367_REG_ACT_INACT_CTL);

//     buf &= ~(0x0C); // Clear INACT_EN bits
//     buf |= (mode << 2);

//     i2c_write(ADXL367_REG_ACT_INACT_CTL, buf);
// }

// void adxl357_setLinkLoopMode(LinkLoopMode mode)
// {
//     i2c_write(ADXL367_REG_ACT_INACT_CTL, mode << 4);
// }

// void adxl367_setActInactControl(uint8_t bitmap)
// {
//     i2c_write(ADXL367_REG_ACT_INACT_CTL, bitmap);
// }

// void adxl367_configInt1(uint16_t bitmap)
// {
//     i2c_write(ADXL367_REG_INTMAP1_LO, bitmap);
//     i2c_write(ADXL367_REG_INTMAP1_UP, bitmap > 8u);
// }