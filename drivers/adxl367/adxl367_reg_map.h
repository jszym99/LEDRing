#ifndef ADXL367_REG_MAP
#define ADXL367_REG_MAP

/* Device ID / Identification registers */
#define ADXL367_REG_DEVID_AD         0x00 /* Analog Devices device ID ID [R] */
#define ADXL367_REG_DEVID_MST        0x01 /* MEMS device ID [R] */
#define ADXL367_REG_PARTID           0x02 /* Part ID [R] */
#define ADXL367_REG_REVID            0x03 /* Revision ID [R] */

/* Serial number */
#define ADXL367_REG_SERIAL_NUM_2     0x05 /* Serial Number [R] */
#define ADXL367_REG_SERIAL_NUM_1     0x06 /* Serial Number [R] */
#define ADXL367_REG_SERIAL_NUM_0     0x07 /* Serial Number [R] */

/* Primary 8-bit axis data registers (simple 8-bit outputs) */
#define ADXL367_REG_XDATA            0x08 /* XDATA [R] */
#define ADXL367_REG_YDATA            0x09 /* YDATA [R] */
#define ADXL367_REG_ZDATA            0x0A /* ZDATA [R] */

/* Status / FIFO */
#define ADXL367_REG_STATUS           0x0B /* STATUS [R] */
#define ADXL367_REG_FIFO_ENTRIES_L   0x0C /* FIFO_ENTRIES_L [R] */
#define ADXL367_REG_FIFO_ENTRIES_H   0x0D /* FIFO_ENTRIES_H [R] */

/* 14-bit axis data (MSB/LSB pair) */
#define ADXL367_REG_XDATA_H          0x0E /* XDATA [13:6] [R] */
#define ADXL367_REG_XDATA_L          0x0F /* XDATA [5:0]  [R] */
#define ADXL367_REG_YDATA_H          0x10 /* YDATA [13:6] [R] */
#define ADXL367_REG_YDATA_L          0x11 /* YDATA [5:0]  [R] */
#define ADXL367_REG_ZDATA_H          0x12 /* ZDATA [13:6] [R] */
#define ADXL367_REG_ZDATA_L          0x13 /* ZDATA [5:0]  [R] */

/* Temperature and external ADC */
#define ADXL367_REG_TEMP_H           0x14 /* TEMP_DATA [13:6] [R] */
#define ADXL367_REG_TEMP_L           0x15 /* TEMP_DATA [5:0]  [R] */
#define ADXL367_REG_EX_ADC_H         0x16 /* EX_ADC_DATA [13:6] [R] */
#define ADXL367_REG_EX_ADC_L         0x17 /* EX_ADC_DATA [5:0]  [R] */

/* I2C FIFO data (read) */
#define ADXL367_REG_I2C_FIFO_DATA    0x18 /* I2C_FIFO_DATA [R] */

/* Soft reset */
#define ADXL367_REG_SOFT_RESET       0x1F /* SOFT_RESET [W] */

/* Activity / Inactivity thresholds and timing */
#define ADXL367_REG_THRESH_ACT_H     0x20 /* THRESH_ACT_H [R/W] */
#define ADXL367_REG_THRESH_ACT_L     0x21 /* THRESH_ACT_L [R/W] */
#define ADXL367_REG_TIME_ACT         0x22 /* TIME_ACT [R/W] */
#define ADXL367_REG_THRESH_INACT_H   0x23 /* THRESH_INACT_H [R/W] */
#define ADXL367_REG_THRESH_INACT_L   0x24 /* THRESH_INACT_L [R/W] */
#define ADXL367_REG_TIME_INACT_H     0x25 /* TIME_INACT_H [R/W] */
#define ADXL367_REG_TIME_INACT_L     0x26 /* TIME_INACT_L [R/W] */
#define ADXL367_REG_ACT_INACT_CTL    0x27 /* ACT_INACT_CTL [R/W] */

/* FIFO control */
#define ADXL367_REG_FIFO_CONTROL     0x28 /* FIFO_CONTROL [R/W] */
#define ADXL367_REG_FIFO_SAMPLES     0x29 /* FIFO_SAMPLES [R/W] */

/* Interrupt mapping (lower and upper) */
#define ADXL367_REG_INTMAP1_LO       0x2A /* INTMAP1_LO [R/W] */
#define ADXL367_REG_INTMAP2_LO       0x2B /* INTMAP2_LO [R/W] */
#define ADXL367_REG_FILTER_CTL       0x2C /* FILTER_CTL [R/W] */
#define ADXL367_REG_POWER_CTL        0x2D /* POWER_CTL [R/W] */
#define ADXL367_REG_SELF_TEST        0x2E /* SELF_TEST [R/W] */

/* Tap detection and offsets */
#define ADXL367_REG_TAP_THRESH       0x2F /* TAP_THRESH [R/W] */
#define ADXL367_REG_TAP_DUR          0x30 /* TAP_DUR [R/W] */
#define ADXL367_REG_TAP_LATENT       0x31 /* TAP_LATENT [R/W] */
#define ADXL367_REG_TAP_WINDOW       0x32 /* TAP_WINDOW [R/W] */
#define ADXL367_REG_X_OFFSET         0x33 /* X_OFFSET [R/W] */
#define ADXL367_REG_Y_OFFSET         0x34 /* Y_OFFSET [R/W] */
#define ADXL367_REG_Z_OFFSET         0x35 /* Z_OFFSET [R/W] */
#define ADXL367_REG_X_SENS           0x36 /* X_SENS [R/W] */
#define ADXL367_REG_Y_SENS           0x37 /* Y_SENS [R/W] */
#define ADXL367_REG_Z_SENS           0x38 /* Z_SENS [R/W] */

#define ADXL367_REG_TIMER_CTL        0x39 /* TIMER_CTL [R/W] */
#define ADXL367_REG_INTMAP1_UP       0x3A /* INTMAP1_UP [R/W] */
#define ADXL367_REG_INTMAP2_UP       0x3B /* INTMAP2_UP [R/W] */

/* ADC / Temperature control and thresholds */
#define ADXL367_REG_ADC_CTL          0x3C /* ADC_CTL [R/W] */
#define ADXL367_REG_TEMP_CTL         0x3D /* TEMP_CTL [R/W] */
#define ADXL367_REG_TEMP_ADC_OVER_H  0x3E /* TEMP_ADC_OVER_H [R/W] */
#define ADXL367_REG_TEMP_ADC_OVER_L  0x3F /* TEMP_ADC_OVER_L [R/W] */
#define ADXL367_REG_TEMP_ADC_UNDER_H 0x40 /* TEMP_ADC_UNDER_H [R/W] */
#define ADXL367_REG_TEMP_ADC_UNDER_L 0x41 /* TEMP_ADC_UNDER_L [R/W] */
#define ADXL367_REG_TEMP_ADC_TIMER   0x42 /* TEMP_ADC_TIMER [R/W] */

#define ADXL367_REG_AXIS_MASK        0x43 /* AXIS_MASK [R/W] */
#define ADXL367_REG_STATUS_COPY      0x44 /* STATUS_COPY [R] */
#define ADXL367_REG_STATUS_2         0x45 /* STATUS_2 [R] */

#endif /* ADXL367_REG_MAP */