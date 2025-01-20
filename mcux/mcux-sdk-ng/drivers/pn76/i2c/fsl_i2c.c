/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_i2c.h"
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_i2c"
#endif

/*! @brief Common sets of flags used by the driver. */
enum _i2c_flag_constants
{
    kI2C_MasterIrqFlags = I2C_INTSTAT_MSTPENDING_MASK | I2C_INTSTAT_MSTARBLOSS_MASK | I2C_INTSTAT_MSTSTSTPERR_MASK,
    kI2C_SlaveIrqFlags  = I2C_INTSTAT_SLVPENDING_MASK | I2C_INTSTAT_SLVDESEL_MASK,
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static status_t I2C_SlaveDivVal(uint32_t srcClock_Hz, i2c_slave_bus_speed_t busSpeed, uint32_t *divVal);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map i2c instance number to base address. */
static I2C_Type *const s_i2cBases[] = I2C_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to i2c clocks for each instance. */
static const clock_ip_name_t s_i2cClocks[] = I2C_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_RESET) && FSL_FEATURE_I2C_HAS_NO_RESET)
static const reset_ip_name_t s_i2cResets[] = I2C_RSTS_N;
#endif

/* Array of I2C IRQ number. */
const IRQn_Type s_i2cIRQ[] = I2C_IRQS;

#if defined(FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS) && (FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS)
/*! @brief Pointers to i2c handles for each instance. */
void *s_i2cHandle[FSL_FEATURE_SOC_I2C_COUNT];

/*! @brief Pointer to master IRQ handler for each instance. */
i2c_isr_t s_i2cMasterIsr;

/*! @brief Pointer to slave IRQ handler for each instance. */
i2c_isr_t s_i2cSlaveIsr;
#endif /* FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * @param base The I2C peripheral base address.
 * @return I2C instance number starting from 0.
 */
/*!
 * brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * param base The I2C peripheral base address.
 * return I2C instance number starting from 0.
 */
uint32_t I2C_GetInstance(I2C_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0U; instance < ARRAY_SIZE(s_i2cBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_i2cBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_i2cBases));

    return instance;
}

/*!
 * brief Provides a default configuration for the I2C master peripheral.
 *
 * This function provides the following default configuration for the I2C master peripheral:
 * code
 *  masterConfig->enableMaster            = true;
 *  masterConfig->baudRate_Bps            = 100000U;
 *  masterConfig->enableTimeout           = false;
 * endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the master driver with I2C_MasterInit().
 *
 * param[out] masterConfig User provided configuration structure for default values. Refer to #i2c_master_config_t.
 */
void I2C_MasterGetDefaultConfig(i2c_master_config_t *masterConfig)
{
    /* Initializes the configure structure to zero. */
    (void)memset(masterConfig, 0, sizeof(*masterConfig));

    masterConfig->enableMaster  = true;
    masterConfig->baudRate_Bps  = 100000U;
    masterConfig->enableTimeout = false;
}

/*!
 * brief Initializes the I2C master peripheral.
 *
 * This function enables the peripheral clock and initializes the I2C master peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration.
 *
 * param base The I2C peripheral base address.
 * param masterConfig User provided peripheral configuration. Use I2C_MasterGetDefaultConfig() to get a set of
 * defaults
 *      that you can override.
 * param srcClock_Hz Frequency in Hertz of the I2C functional clock. Used to calculate the baud rate divisors,
 *      filter widths, and timeout periods.
 */
status_t I2C_MasterInit(I2C_Type *base, const i2c_master_config_t *masterConfig, uint32_t srcClock_Hz)
{
    uint32_t instance = I2C_GetInstance(base);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_i2cClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_RESET) && FSL_FEATURE_I2C_HAS_NO_RESET)
    RESET_PeripheralReset(s_i2cResets[instance]);
#endif

    I2C_MasterEnable(base, masterConfig->enableMaster);
    return I2C_MasterSetBaudRate(base, masterConfig->baudRate_Bps, srcClock_Hz);
}

/*!
 * brief Deinitializes the I2C master peripheral.
 *
 * This function disables the I2C master peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The I2C peripheral base address.
 */
void I2C_MasterDeinit(I2C_Type *base)
{
    uint32_t instance = I2C_GetInstance(base);

    I2C_MasterEnable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_i2cClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    NVIC_ClearPendingIRQ(s_i2cIRQ[instance]);
}

/*!
 * brief Sets the I2C bus frequency for master transactions.
 *
 * The I2C master is automatically disabled and re-enabled as necessary to configure the baud
 * rate. Do not call this function during a transfer, or the transfer is aborted.
 *
 * param base The I2C peripheral base address.
 * param srcClock_Hz I2C functional clock frequency in Hertz.
 * param baudRate_Bps Requested bus frequency in bits per second.
 * retval Success, Successfully set the baud rate .
 * retval Fail, no valid baud rate or invalid srcClock_Hz.
 */
status_t I2C_MasterSetBaudRate(I2C_Type *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz)
{

    switch (baudRate_Bps)
    {
        case ((uint32_t)(kI2C_Baudrate100kHz)):
            base->CLKDIV  = ((srcClock_Hz != 45000000U) ? 49U : 24U); /* 49 for 90MHz, 24 for 45MHz */
            base->MSTTIME = 119U;
            break;

        case ((uint32_t)(kI2C_Baudrate400kHz)):
            base->CLKDIV  = ((srcClock_Hz != 45000000U) ? 13U : 6U); /* 13 for 90MHz, 6 for 45MHz */
            base->MSTTIME = 102;
            break;

        case ((uint32_t)(kI2C_Baudrate1MHz)):
            base->CLKDIV  = ((srcClock_Hz != 45000000U) ? 4U : 10U);  /* 4 for 90MHz, 10 for 45MHz */
            base->MSTTIME = ((srcClock_Hz != 45000000U) ? 119U : 0U); /* 119 for 90MHz, 0 for 45MHz */
            break;

        case ((uint32_t)(kI2C_Baudrate3P4MHz)):
            /* Note:  Enable the CLOCK_HFO_FREQ_HZ for maximum baudrate 3.2MHz  */
            if (srcClock_Hz == 90000000U)
            {
                base->CLKDIV  = 1U;
                base->MSTTIME = 2U;
                break;
            }
            else
            {
                return kStatus_InvalidArgument;
            }
        default:
            return kStatus_Fail;
    }

    return kStatus_Success;
}

static uint32_t I2C_PendingStatusWait(I2C_Type *base)
{
    uint32_t status;

#if I2C_RETRY_TIMES
    uint32_t waitTimes = I2C_RETRY_TIMES;
#endif

    do
    {
        status = I2C_GetStatusFlags(base);
#if I2C_RETRY_TIMES
    } while (((status & I2C_STAT_MSTPENDING_MASK) == 0) && (0U != --waitTimes));

    if (0U == waitTimes)
    {
        return (uint32_t)kStatus_I2C_Timeout;
    }
#else
    } while ((status & I2C_STAT_MSTPENDING_MASK) == 0U);
#endif

    /* Clear controller state. */
    I2C_MasterClearStatusFlags(base, I2C_STAT_MSTARBLOSS_MASK | I2C_STAT_MSTSTSTPERR_MASK);

    return status;
}

/*!
 * brief Sends a START on the I2C bus.
 *
 * This function is used to initiate a new master mode transfer by sending the START signal.
 * The slave address is sent following the I2C START signal.
 *
 * param base I2C peripheral base pointer
 * param address 7-bit slave device address.
 * param direction Master transfer directions(transmit/receive).
 * retval kStatus_Success Successfully send the start signal.
 * retval kStatus_I2C_Busy Current bus is busy.
 */
status_t I2C_MasterStart(I2C_Type *base, uint8_t address, i2c_direction_t direction)
{
    if (I2C_PendingStatusWait(base) == (uint32_t)kStatus_I2C_Timeout)
    {
        return kStatus_I2C_Timeout;
    }

    /* Write Address and RW bit to data register */
    base->MSTDAT = ((uint32_t)address << 1) | ((uint32_t)direction & 1u);
    /* Start the transfer */
    base->MSTCTL = I2C_MSTCTL_MSTSTART_MASK;

    return kStatus_Success;
}

/*!
 * brief Sends a STOP signal on the I2C bus.
 *
 * retval kStatus_Success Successfully send the stop signal.
 * retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterStop(I2C_Type *base)
{
    if (I2C_PendingStatusWait(base) == (uint32_t)kStatus_I2C_Timeout)
    {
        return kStatus_I2C_Timeout;
    }

    base->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;
    return kStatus_Success;
}

/*!
 * @brief Compute CLKDIV
 *
 * This function computes CLKDIV value according to the given bus speed and Flexcomm source clock frequency.
 * This setting is used by hardware during slave clock stretching.
 *
 * @param base The I2C peripheral base address.
 * @return status of the operation
 */
static status_t I2C_SlaveDivVal(uint32_t srcClock_Hz, i2c_slave_bus_speed_t busSpeed, uint32_t *divVal)
{
    uint32_t dataSetupTime_ns;

    switch (busSpeed)
    {
        case kI2C_SlaveStandardMode:
            dataSetupTime_ns = 250u;
            break;

        case kI2C_SlaveFastMode:
            dataSetupTime_ns = 100u;
            break;

        case kI2C_SlaveFastModePlus:
            dataSetupTime_ns = 50u;
            break;

        case kI2C_SlaveHsMode:
            dataSetupTime_ns = 10u;
            break;

        default:
            dataSetupTime_ns = 0;
            break;
    }

    if (0U == dataSetupTime_ns)
    {
        return kStatus_InvalidArgument;
    }

    /* divVal = (sourceClock_Hz / 1000000) * (dataSetupTime_ns / 1000) */
    *divVal = srcClock_Hz / 1000u;
    *divVal = (*divVal) * dataSetupTime_ns;
    *divVal = (*divVal) / 1000000u;

    if ((*divVal) > I2C_CLKDIV_DIVVAL_MASK)
    {
        *divVal = I2C_CLKDIV_DIVVAL_MASK;
    }

    return kStatus_Success;
}

/*!
 * brief Configures Slave Address n register.
 *
 * This function writes new value to Slave Address register.
 *
 * param base The I2C peripheral base address.
 * param addressRegister The module supports multiple address registers. The parameter determines which one shall be
 * changed.
 * param address The slave address to be stored to the address register for matching.
 * param addressDisable Disable matching of the specified address register.
 */
void I2C_SlaveSetAddress(I2C_Type *base,
                         i2c_slave_address_register_t addressRegister,
                         uint8_t address,
                         bool addressDisable)
{
    base->SLVADR[addressRegister] = I2C_SLVADR_SLVADR(address) | I2C_SLVADR_SADISABLE(addressDisable);
}

/*!
 * brief Provides a default configuration for the I2C slave peripheral.
 *
 * This function provides the following default configuration for the I2C slave peripheral:
 * code
 *  slaveConfig->enableSlave = true;
 *  slaveConfig->address0.disable = false;
 *  slaveConfig->address0.address = 0U;
 *  slaveConfig->address1.disable = true;
 *  slaveConfig->address2.disable = true;
 *  slaveConfig->address3.disable = true;
 *  slaveConfig->busSpeed = kI2C_SlaveStandardMode;
 * endcode
 *
 * After calling this function, override any settings  to customize the configuration,
 * prior to initializing the master driver with I2C_SlaveInit(). Be sure to override at least the a
 * address0.address member of the configuration structure with the desired slave address.
 *
 * param[out] slaveConfig User provided configuration structure that is set to default values. Refer to
 *      #i2c_slave_config_t.
 */
void I2C_SlaveGetDefaultConfig(i2c_slave_config_t *slaveConfig)
{
    assert(slaveConfig != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(slaveConfig, 0, sizeof(*slaveConfig));

    i2c_slave_config_t mySlaveConfig = {0};

    /* default config enables slave address 0 match to general I2C call address zero */
    mySlaveConfig.enableSlave             = true;
    mySlaveConfig.address1.addressDisable = true;
    mySlaveConfig.address2.addressDisable = true;
    mySlaveConfig.address3.addressDisable = true;

    *slaveConfig = mySlaveConfig;
}

/*!
 * brief Initializes the I2C slave peripheral.
 *
 * This function enables the peripheral clock and initializes the I2C slave peripheral as described by the user
 * provided configuration.
 *
 * param base The I2C peripheral base address.
 * param slaveConfig User provided peripheral configuration. Use I2C_SlaveGetDefaultConfig() to get a set of defaults
 *      that you can override.
 * param srcClock_Hz Frequency in Hertz of the I2C functional clock. Used to calculate CLKDIV value to provide
 * enough
 *                       data setup time for master when slave stretches the clock.
 */
status_t I2C_SlaveInit(I2C_Type *base, const i2c_slave_config_t *slaveConfig, uint32_t srcClock_Hz)
{
    status_t status;
    uint32_t divVal   = 0;
    uint32_t instance = I2C_GetInstance(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_i2cClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_RESET) && FSL_FEATURE_I2C_HAS_NO_RESET)
    RESET_PeripheralReset(s_i2cResets[instance]);
#endif

    /* configure data setup time used when slave stretches clock */
    status = I2C_SlaveDivVal(srcClock_Hz, slaveConfig->busSpeed, &divVal);
    if (kStatus_Success != status)
    {
        return status;
    }

    /* I2C Clock Divider register */
    base->CLKDIV = divVal;

    /* set Slave address */
    I2C_SlaveSetAddress(base, kI2C_SlaveAddressRegister0, slaveConfig->address0.address,
                        slaveConfig->address0.addressDisable);
    I2C_SlaveSetAddress(base, kI2C_SlaveAddressRegister1, slaveConfig->address1.address,
                        slaveConfig->address1.addressDisable);
    I2C_SlaveSetAddress(base, kI2C_SlaveAddressRegister2, slaveConfig->address2.address,
                        slaveConfig->address2.addressDisable);
    I2C_SlaveSetAddress(base, kI2C_SlaveAddressRegister3, slaveConfig->address3.address,
                        slaveConfig->address3.addressDisable);

    /* set Slave address 0 qual */
    base->SLVQUAL0 = I2C_SLVQUAL0_QUALMODE0(slaveConfig->qualMode) | I2C_SLVQUAL0_SLVQUAL0(slaveConfig->qualAddress);

    /* set Slave enable */
    base->CFG = I2C_CFG_SLVEN(slaveConfig->enableSlave);

    return status;
}

/*!
 * brief Deinitializes the I2C slave peripheral.
 *
 * This function disables the I2C slave peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The I2C peripheral base address.
 */
void I2C_SlaveDeinit(I2C_Type *base)
{
    uint32_t instance = I2C_GetInstance(base);

    I2C_SlaveEnable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_i2cClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    NVIC_ClearPendingIRQ(s_i2cIRQ[instance]);
}

static void I2C_TransferCommonIRQHandler(I2C_Type *base, void *handle)
{
    /* Check if master interrupt. */
    if ((base->CFG & I2C_CFG_MSTEN_MASK) != 0U)
    {
        s_i2cMasterIsr(base, handle);
    }
    else
    {
        s_i2cSlaveIsr(base, handle);
    }
    SDK_ISR_EXIT_BARRIER;
}

#if defined(I2C_BASE)
void I2C_DriverIRQHandler(void);
void I2C_DriverIRQHandler(void)
{
    I2C_TransferCommonIRQHandler(I2C, s_i2cHandle[0]);
}
#endif
