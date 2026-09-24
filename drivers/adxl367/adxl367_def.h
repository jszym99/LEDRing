#ifndef ADXL367_DEF_H
#define ADXL367_DEF_H

#define ADXL367_I2C_ADDR             0x53 /* Device address */
#define ADXL367_DEVID_AD             0xAD /* Analog Devices device ID value*/
#define ADXL367_DEVID_MST            0x1D /* MEMS device ID value */

/* Status masks */
#define ADXL367_STATUS_DATA_READY       0x01
#define ADXL367_STATUS_FIFO_READY       0x02
#define ADXL367_STATUS_FIFO_WATER_MARK  0x04
#define ADXL367_STATUS_FIFO_OVER_RUN    0x08
#define ADXL367_STATUS_ACT              0x10 // Activity detection triggered
#define ADXL367_STATUS_INACT            0x20 // Inactivity detection triggered
#define ADXL367_STATUS_AWAKE            0x40
#define ADXL367_STATUS_ERROR_USER_REGS  0x80

/* Activity/Inactivity masks */
#define ADXL367_ACT_ENABLE          0x01 // Activity detection enabled
#define ADXL367_ACT_REFERENCED      0x02 // Activity detection referenced mode (activity detection must be enabled)
#define ADXL367_INACT_ENABLE        0x04 // Inactivity detection enabled
#define ADXL367_INACT_REFERENCED    0x08 // Inactivity detection referenced mode (inactivity detection must be enabled)
#define ADXL367_LINK_ENABLE         0x10 // Activity and inactivity detection linked sequentially (only one enabled at a time)
#define ADXL367_LOOP_ENABLE         0x20 // Activity and inactivity detection linked sequentially and cleared internally (link mode must be enabled)

/* Interrupt enables masks */
#define ADXL367_INTMAP_DATA_RDY 0x0001
#define ADXL367_INTMAP_FIFO_RDY 0x0002
#define ADXL367_INTMAP_FIFO_WATERMARK 0x0004
#define ADXL367_INTMAP_FIFO_OVERRUN 0x0008
#define ADXL367_INTMAP_ACT 0x0010
#define ADXL367_INTMAP_INACT 0x0020
#define ADXL367_INTMAP_AWAKE 0x0040
#define ADXL367_INTMAP_INT_HIGH 0x0080
#define ADXL367_INTMAP_INT_TAP_ONE 0x0100
#define ADXL367_INTMAP_INT_TAP_TWO 0x0200
#define ADXL367_INTMAP_INT_TEMP_ADC_LOW 0x0400
#define ADXL367_INTMAP_INT_TEMP_ADC_HI 0x0800
#define ADXL367_INTMAP_INT_KPALV_TIMER 0x1000
#define ADXL367_INTMAP_INT_ERR_USER_REGS 0x4000
#define ADXL367_INTMAP_INT_ERR_FUSE 0x8000

// STATUS 2 Register bit masks
#define ADXL367_TAP_ONE 0x01
#define ADXL367_TAP_TWO 0x02
// TODO: other bits

#endif /* ADXL367_DEF_H */