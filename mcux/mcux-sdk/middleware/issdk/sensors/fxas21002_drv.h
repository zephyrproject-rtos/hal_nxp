/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file fxas21002_drv.h
 * @brief The fxas21002_drv.h file describes the fxas21002 driver interface and structures.
 */

#ifndef FXAS21002_DRV_H_
#define FXAS21002_DRV_H_

/* Standard C Includes */
#include <stdint.h>

/* ISSDK Includes */
#include "fxas21002.h"
#include "sensor_io_i2c.h"
#include "sensor_io_spi.h"
#include "register_io_i2c.h"
#include "register_io_spi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief This defines the sensor specific information for SPI.
 */
typedef struct
{
    registerDeviceInfo_t deviceInfo;      /*!< SPI device context. */
    ARM_DRIVER_SPI *pCommDrv;             /*!< Pointer to the spi driver. */
    bool isInitialized;                   /*!< Whether sensor is intialized or not.*/
    spiSlaveSpecificParams_t slaveParams; /*!< Slave Specific Params.*/
} fxas21002_spi_sensorhandle_t;

/*!
 * @brief This defines the sensor specific information for I2C.
 */
typedef struct
{
    registerDeviceInfo_t deviceInfo; /*!< I2C device context. */
    ARM_DRIVER_I2C *pCommDrv;        /*!< Pointer to the i2c driver. */
    bool isInitialized;              /*!< whether sensor is intialized or not.*/
    uint16_t slaveAddress;           /*!< slave address.*/
} fxas21002_i2c_sensorhandle_t;

/*! @brief This structure defines the fxas21002 raw data buffer.*/
typedef struct
{
    uint32_t timestamp; /*! The time, this sample was recorded.  */
    int16_t gyro[3];    /*!< The gyro data */
} fxas21002_gyrodata_t;

/*! @def    FXAS21002_GYRO_DATA_SIZE
 *  @brief  The size of the FXAS21002 gyro data. */
#define FXAS21002_GYRO_DATA_SIZE (0x06) /* Size of the accel data*/

/*! @def    FXAS21002_SPI_MAX_MSG_SIZE
 *  @brief  The MAX size of SPI message. */
#define FXAS21002_SPI_MAX_MSG_SIZE (64)

/*! @def    FXAS21002_SPI_CMD_LEN
 *  @brief  The size of the Sensor specific SPI Header. */
#define FXAS21002_SPI_CMD_LEN (1)

/*! @def    FXAS21002_SS_ACTIVE_VALUE
 *  @brief  Is the Slave Select Pin Active Low or High. */
#define FXAS21002_SS_ACTIVE_VALUE SPI_SS_ACTIVE_LOW

/*******************************************************************************
 * APIs
 ******************************************************************************/
/*! @brief       The interface function to initialize the sensor.
 *  @details     This function initialize the sensor and sensor handle.
 *  @param[in]   pSensorHandle  handle to the sensor.
 *  @param[in]   pBus           pointer to the CMSIS API compatible I2C bus object.
 *  @param[in]   index          the I2C device number.
 *  @param[in]   sAddress       slave address of the device on the bus.
 *  @param[in]   whoami         WHO_AM_I value of the device.
 *  @constraints This should be the first API to be called.
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_I2C_Initialize() returns the status .
 */
int32_t FXAS21002_I2C_Initialize(fxas21002_i2c_sensorhandle_t *pSensorHandle,
                                 ARM_DRIVER_I2C *pBus,
                                 uint8_t index,
                                 uint16_t sAddress,
                                 uint8_t whoAmi);

/*! @brief      :  The interface function to set the I2C Idle Task.
 *  @param[in]  :  fxas21002_i2c_sensorhandle_t *pSensorHandle, handle to the sensor handle.
 *  @param[in]  :  registeridlefunction_t idleTask, function pointer to the function to execute on I2C Idle Time.
 *  @param[in]  :  void *userParam, the pointer to the user idle ftask parameters.
 *  @return        void.
 *  @constraints   This can be called any number of times only after FXAS21002_I2C_Initialize().
 *                 Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant    No
 */
void FXAS21002_I2C_SetIdleTask(fxas21002_i2c_sensorhandle_t *pSensorHandle,
                               registeridlefunction_t idleTask,
                               void *userParam);

/*! @brief       The interface function to configure he sensor.
 *  @details     This function configure the sensor with requested ODR, Range and registers in the regsiter pair array.
 *  @param[in]   pSensorHandle      handle to the sensor.
 *  @param[in]   pRegWriteList      pointer to the register list.
 *  @constraints This can be called any number of times only after FXAS21002_I2C_Initialize().
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_I2C_Configure() returns the status .
 */
int32_t FXAS21002_I2C_Configure(fxas21002_i2c_sensorhandle_t *pSensorHandle, const registerwritelist_t *pRegWriteList);

/*! @brief       The interface function to read the sensor data.
 *  @details     This function read the sensor data out from the device and returns raw data in a byte stream.
 *  @param[in]   pSensorHandle  handle to the sensor.
 *  @param[in]   pReadList      pointer to the list of device registers and values to read.
 *  @param[out]  pBuffer        buffer which holds raw sensor data.This buffer may be back to back databuffer based
 *                              command read in the list.
 *  @constraints This can be called any number of times only after FXAS21002_I2C_Initialize().
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_I2C_ReadData() returns the status .
 */
int32_t FXAS21002_I2C_ReadData(fxas21002_i2c_sensorhandle_t *pSensorHandle,
                               const registerreadlist_t *pReadList,
                               uint8_t *pBuffer);

/*! @brief       The interface function to De Initialize sensor..
 *  @details     This function made sensor in a power safe state and de initialize its handle.
 *  @param[in]   pSensorHandle      handle to the sensor.
 *  @constraints This can be called only after FXAS21002_I2C_Initialize().
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_I2C_Deinit() returns the status .
 */
int32_t FXAS21002_I2C_Deinit(fxas21002_i2c_sensorhandle_t *pSensorHandle);

/*! @brief       The interface function to initialize the sensor.
 *  @details     This function initializes the sensor and sensor handle.
 *  @param[in]   pSensorHandle handle to the sensor.
 *  @param[in]   pBus          pointer to the CMSIS API compatible SPI bus object.
 *  @param[in]   index         the I2C device number.
 *  @param[in]   pSlaveSelect  slave select hndle of the device on the bus.
 *  @param[in]   whoami        WHO_AM_I value of the device.
 *  @constraints This should be the first API to be called.
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_SPI_Initialize() returns the status .
 */
int32_t FXAS21002_SPI_Initialize(fxas21002_spi_sensorhandle_t *pSensorHandle,
                                 ARM_DRIVER_SPI *pBus,
                                 uint8_t index,
                                 void *pSlaveSelect,
                                 uint8_t whoAmi);

/*! @brief      :  The interface function to set the SPI Idle Task.
 *  @param[in]  :  fxas21002_spi_sensorhandle_t *pSensorHandle, handle to the sensor handle.
 *  @param[in]  :  registeridlefunction_t idleTask, function pointer to the function to execute on SPI Idle Time.
 *  @param[in]  :  void *userParam, the pointer to the user idle ftask parameters.
 *  @return        void.
 *  @constraints   This can be called any number of times only after FXAS21002_SPI_Initialize().
 *                 Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant    No
 */
void FXAS21002_SPI_SetIdleTask(fxas21002_spi_sensorhandle_t *pSensorHandle,
                               registeridlefunction_t idleTask,
                               void *userParam);

/*! @brief       The interface function to configure he sensor.
 *  @details     This function configure the sensor with requested ODR, Range and registers in the regsiter pair array.
 *  @param[in]   pSensorHandle handle to the sensor.
 *  @param[in]   pRegWriteList pointer to the register list.
 *  @constraints This can be called any number of times only after FXAS21002_SPI_Initialize().
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_SPI_Configure() returns the status .
 */
int32_t FXAS21002_SPI_Configure(fxas21002_spi_sensorhandle_t *pSensorHandle, const registerwritelist_t *pRegWriteList);

/*! @brief       The interface function to read the sensor data.
 *  @details     This function read the sensor data out from the device and returns raw data in a byte stream.
 *  @param[in]   pSensorHandle handle to the sensor.
 *  @param[in]   pReadList     pointer to the list of device registers and values to read.
 *  @param[out]  pBuffer       buffer which holds raw sensor data.This buffer may be back to back databuffer based
 *               command read in the list.
 *  @constraints This can be called any number of times only after FXAS21002_SPI_Initialize().
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_SPI_ReadData() returns the status .
 */
int32_t FXAS21002_SPI_ReadData(fxas21002_spi_sensorhandle_t *pSensorHandle,
                               const registerreadlist_t *pReadList,
                               uint8_t *pBuffer);

/*! @brief       The interface function to De Initialize sensor..
 *  @details     This function made sensor in a power safe state and de initialize its handle.
 *  @param[in]   pSensorHandle      handle to the sensor.
 *  @constraints This can be called only after after FXAS21002_SPI_Initialize().
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      ::FXAS21002_SPI_Deinit() returns the status .
 */
int32_t FXAS21002_SPI_Deinit(fxas21002_spi_sensorhandle_t *pSensorHandle);

/*! @brief       The SPI Read Pre-Process function to generate Sensor specific SPI Message Header.
 *  @details     This function prepares the SPI Read Command Header with register address and
 *               R/W bit encoded as the Sensor.
 *  @param[out]  pCmdOut  handle to the output buffer.
 *  @param[in]   offset   the address of the register to start reading from.
 *  @param[in]   size     number of bytes to read.
 *  @constraints None
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      :: None.
 */
void FXAS21002_SPI_ReadPreprocess(void *pCmdOut, uint32_t offset, uint32_t size);

/*! @brief       The SPI Write Pre-Process function to generate Sensor specific SPI Message Header.
 *  @details     This function prepares the SPI Write Command Header with register address and
 *               R/W bit encoded as the Sensor.
 *  @param[out]  pCmdOut  handle to the output buffer.
 *  @param[in]   offset   the address of the register to start writing from.
 *  @param[in]   size     number of bytes to write.
 *  @constraints None
 *               Application has to ensure that previous instances of these APIs have exited before invocation.
 *  @reeentrant  No
 *  @return      :: None.
 */
void FXAS21002_SPI_WritePreprocess(void *pCmdOut, uint32_t offset, uint32_t size, void *pWritebuffer);

#endif // FXAS21002_DRV_H_
