/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  fxls8962_normal_spi.c
 *  @brief The fxls8962_normal_spi.c file implements the ISSDK FXLS8962 SPI sensor driver
 *         example demonstration for SPI Mode with polling.
 */

//-----------------------------------------------------------------------
// SDK Includes
//-----------------------------------------------------------------------
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"

//-----------------------------------------------------------------------
// ISSDK Includes
//-----------------------------------------------------------------------
#include "issdk_hal.h"
#include "gpio_driver.h"
#include "fxls8962_drv.h"
#include "systick_utils.h"

//-----------------------------------------------------------------------
// CMSIS Includes
//-----------------------------------------------------------------------
#include "Driver_SPI.h"

//-----------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------
#define FXLS8962_DATA_SIZE (6)

//-----------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------
/*! @brief Register settings for Normal (non buffered) mode. */
const registerwritelist_t cFxls8962ConfigNormal[] = {
    /* Set Full-scale range as 2G. */
    {FXLS8962_SENS_CONFIG1, FXLS8962_SENS_CONFIG1_FSR_2G, FXLS8962_SENS_CONFIG1_FSR_MASK},
    /* Set Wake Mode ODR Rate as 6.25Hz. */
    {FXLS8962_SENS_CONFIG3, FXLS8962_SENS_CONFIG3_WAKE_ODR_6_25HZ, FXLS8962_SENS_CONFIG3_WAKE_ODR_MASK},
    __END_WRITE_DATA__};

/*! @brief Address of DATA Ready Status Register. */
const registerreadlist_t cFxls8962DRDYEvent[] = {{.readFrom = FXLS8962_INT_STATUS, .numBytes = 1}, __END_READ_DATA__};

/*! @brief Address of Raw Accel Data in Normal Mode. */
const registerreadlist_t cFxls8962OutputNormal[] = {{.readFrom = FXLS8962_OUT_X_LSB, .numBytes = FXLS8962_DATA_SIZE},
                                                    __END_READ_DATA__};

//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------
/*! -----------------------------------------------------------------------
 *  @brief       This is the The main function implementation.
 *  @details     This function invokes board initializes routines, then then brings up the sensor and
 *               finally enters an endless loop to continuously read available samples.
 *  @param[in]   void This is no input parameter.
 *  @return      void  There is no return value.
 *  @constraints None
 *  @reeentrant  No
 *  -----------------------------------------------------------------------*/
int main(void)
{
    int32_t status;
    uint8_t whoami;
    uint8_t gFxls8962DataReady;
    uint8_t data[FXLS8962_DATA_SIZE];
    fxls8962_acceldata_t rawData;

    ARM_DRIVER_SPI *pSPIdriver = &SPI_S_DRIVER;
    fxls8962_spi_sensorhandle_t fxls8962Driver;

    /*! Initialize the MCU hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_SystickEnable();
    BOARD_InitDebugConsole();

    PRINTF("\r\n ISSDK FXLS896x sensor driver example demonstration for SPI with Poll Mode.\r\n");

    /*! Initialize the SPI driver. */
    status = pSPIdriver->Initialize(SPI_S_SIGNAL_EVENT);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n SPI Initialization Failed\r\n");
        return -1;
    }

    /*! Set the SPI Power mode. */
    status = pSPIdriver->PowerControl(ARM_POWER_FULL);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n SPI Power Mode setting Failed\r\n");
        return -1;
    }

    /*! Set the SPI Slave speed. */
    status = pSPIdriver->Control(ARM_SPI_MODE_MASTER | ARM_SPI_CPOL0_CPHA0, SPI_S_BAUDRATE);
    if (ARM_DRIVER_OK != status)
    {
        PRINTF("\r\n SPI Control Mode setting Failed\r\n");
        return -1;
    }

    /*! Initialize the fxls8962 sensor driver. */
    status = FXLS8962_SPI_Initialize(&fxls8962Driver, &SPI_S_DRIVER, SPI_S_DEVICE_INDEX, &FXLS8962_CS,
    		&whoami);
    if (SENSOR_ERROR_NONE != status)
    {
        PRINTF("\r\n FXLS896x Sensor Initialization Failed\r\n");
        return -1;
    }
    if ((FXLS8964_WHOAMI_VALUE == whoami) || (FXLS8967_WHOAMI_VALUE == whoami))
    {
    	PRINTF("\r\n Successfully Initialized Gemini with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else if (FXLS8974_WHOAMI_VALUE == whoami)
    {
    	PRINTF("\r\n Successfully Initialized Timandra with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else if (FXLS8962_WHOAMI_VALUE == whoami)
    {
    	PRINTF("\r\n Successfully Initialized Newstein with WHO_AM_I = 0x%X\r\n", whoami);
    }
    else
    {
    	PRINTF("\r\n Bad WHO_AM_I = 0x%X\r\n", whoami);
    }

    /*!  Set the task to be executed while waiting for SPI transactions to complete. */
    FXLS8962_SPI_SetIdleTask(&fxls8962Driver, (registeridlefunction_t)SMC_SetPowerModeVlpr, SMC);

    /*! Configure the FXLS8962 sensor driver. */
    status = FXLS8962_SPI_Configure(&fxls8962Driver, cFxls8962ConfigNormal);
    if (SENSOR_ERROR_NONE != status)
    {
        PRINTF("\r\n FXLS896x Sensor Configuration Failed, Err = %d\r\n", status);
        return -1;
    }
    PRINTF("\r\n Successfully Applied FXLS896x Sensor Configuration\r\n");

    for (;;) /* Forever loop */
    {
        /*! Wait for data ready from the FXLS8962. */
        status = FXLS8962_SPI_ReadData(&fxls8962Driver, cFxls8962DRDYEvent, &gFxls8962DataReady);
        if (0 == (gFxls8962DataReady & FXLS8962_INT_STATUS_SRC_DRDY_MASK))
        { /* Loop, if new sample is not available. */
            continue;
        }

        /*! Read the raw sensor data from the FXLS8962. */
        status = FXLS8962_SPI_ReadData(&fxls8962Driver, cFxls8962OutputNormal, data);
        if (ARM_DRIVER_OK != status)
        {
            PRINTF("\r\nRead Failed.\r\n");
            return -1;
        }

        /*! Convert the raw sensor data for display to the debug port. */
        rawData.accel[0] = ((int16_t)data[1] << 8) | data[0];
        rawData.accel[1] = ((int16_t)data[3] << 8) | data[2];
        rawData.accel[2] = ((int16_t)data[5] << 8) | data[4];

        /* NOTE: PRINTF is relatively expensive in terms of CPU time, specially when used with-in execution loop. */
        PRINTF("\r\n X=%5d Y=%5d Z=%5d\r\n", rawData.accel[0], rawData.accel[1], rawData.accel[2]);
    }
}
