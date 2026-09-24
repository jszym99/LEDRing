#include <i2c_master.h>
#include <USI_TWI_Master.h>

void i2c_master_init()
{
    USI_TWI_Master_Initialise();
}

uint8_t i2c_master_sendByte(uint8_t msgByte)
{
    /* If transmission failed return error code. */
    if(USI_TWI_Start_Transceiver_With_Data(&msgByte, 1) == FALSE)
    {
        return (USI_TWI_Get_State_Info() + 1);
    }
    else
        return 0;
}

/**
 * @brief Write to single register of I2C device
 * 
 * @param slaveAddress Address of the slave device to write to
 * @param registerAddress Address of the slave device's register to write to
 * @param data Data byte to write to the register
 * @return uint8_t 0 if transmission was successful
 */
uint8_t i2c_master_write(uint8_t slaveAddress, uint8_t registerAddress, uint8_t data){
    uint8_t msgBuffer[3] = {(slaveAddress << 1), registerAddress, data};

    /* If transmission failed return error code. */
    if(USI_TWI_Start_Transceiver_With_Data(msgBuffer, 3) == FALSE)
    {
        return (USI_TWI_Get_State_Info() + 1);
    }
    else
        return 0;
}

/**
 * @brief Read data from single register in I2C device
 * 
 * @param slaveAddress Address of the slave device to read from
 * @param registerAddress Address of the slave device's register to read from
 * @return uint8_t Contents of the register (single byte)
 */
uint8_t i2c_master_read(uint8_t slaveAddress, uint8_t registerAddress){
    uint8_t msgBuffer[2] = {(slaveAddress << 1), registerAddress};

    /* Send data request. */
    if(USI_TWI_Start_Transceiver_With_Data(msgBuffer, 2) == TRUE)
    {
        /* Set R/W bit. */
        msgBuffer[0] = (msgBuffer[0] | 0x01);

        if(USI_TWI_Start_Transceiver_With_Data(msgBuffer, 2) != TRUE)
        {
            // TODO: Report error
        }
    }
    else
    {
        // TODO: Report error
    }

    return msgBuffer[1];
}
/**
 * @brief Write to multiple registers of I2C device
 * 
 * @param slaveAddress Address of the slave device to write to
 * @param registerAddress Address of the slave device's first register to start writing to
 * @param dataPtr Pointer to data to be written
 * @param dataSize Size (in bytes) of the data to write (equal to number of registers)
 * @return uint8_t 0 if transmission was successful
 */
uint8_t i2c_master_writeMulti(uint8_t slaveAddress, uint8_t registerAddress, uint8_t *dataPtr, uint8_t dataSize){
    uint8_t msgBuffer[2] = {(slaveAddress << 1), registerAddress};

    // Send device and register address
    if(USI_TWI_Start_Transceiver_With_Data(msgBuffer, 2) == TRUE)
    {
        // Send data
        if(USI_TWI_Start_Transceiver_With_Data(dataPtr, dataSize) != TRUE)
        {
            // TODO: Report error
        }
    }
    else
    {        
        /* If transmission failed return error code. */
        return (USI_TWI_Get_State_Info() + 1);
    }
    return 0;
}

/**
 * @brief Read data from multiple registers in I2C device
 * 
 * @param slaveAddress Address of the slave device to write to
 * @param registerAddress Address of the slave device's first register to start reading from
 * @param dataPtr Pointer to read data buffer
 * @param dataSize Size (in bytes) of the data to read (equal to number of registers)
 * @return uint8_t 0 if transmission was successful
 */
uint8_t i2c_master_readMulti(uint8_t slaveAddress, uint8_t registerAddress, uint8_t *dataPtr, uint8_t dataSize){
    uint8_t msgBuffer[2] = {(slaveAddress << 1), registerAddress};

    /* Send data request (slave address and register address). */
    if(USI_TWI_Start_Transceiver_With_Data(msgBuffer, 2) == TRUE)
    {
        /* Set R/W bit. */
        msgBuffer[0] = (msgBuffer[0] | 0x01);

        // Send device address
        if(USI_TWI_Start_Transceiver_With_Data(msgBuffer, 1) == TRUE)
        {
            // Read given number of registers starting with registerAddress
            if(USI_TWI_Start_Transceiver_With_Data(dataPtr, dataSize) != TRUE)
            {
                return 1; // Indicate error
            }
        }
        else
        {
            return 1; // Indicate error
        }
    }
    else
    {
        return 1; // Indicate error
    }

    return 0;
}