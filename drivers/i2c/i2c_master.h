#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include <stdint-gcc.h>

void i2c_master_init();
uint8_t i2c_master_sendByte(uint8_t msgByte);
uint8_t i2c_master_write(uint8_t slaveAddress, uint8_t registerAddress, uint8_t data);
uint8_t i2c_master_read(uint8_t slaveAddress, uint8_t registerAddress);

uint8_t i2c_master_writeMulti(uint8_t slaveAddress, uint8_t registerAddress, uint8_t *dataPtr, uint8_t dataLen);
uint8_t i2c_master_readMulti(uint8_t slaveAddress, uint8_t registerAddress, uint8_t *dataPtr, uint8_t dataLen);

#endif /* I2C_MASTER_H */