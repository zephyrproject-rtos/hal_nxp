/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_I2C_H_
#define FSL_I2C_H_

#include <stddef.h>
#include "fsl_device_registers.h"
#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Macro gate for enable/disable I2C transactional APIs, 1 for enable, 0 for disable. */
#ifndef FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS
#define FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS 1
#endif

#define I2C_CFG_MASK 0x1fUL

/*!
 * @addtogroup i2c_driver
 * @{
 */

/*! @file */

/*! @name Driver version */
/*! @{ */
/*! @brief I2C driver version. */
#define FSL_I2C_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*! @} */

/*! @brief Retry times for waiting flag. */
#ifndef I2C_RETRY_TIMES
#define I2C_RETRY_TIMES 0U /* Define to zero means keep waiting until the flag is assert/deassert. */
#endif

/* definitions for MSTCODE bits in I2C Status register STAT */
#define I2C_STAT_MSTCODE_IDLE    (0)   /*!< Master Idle State Code */
#define I2C_STAT_MSTCODE_RXREADY (1UL) /*!< Master Receive Ready State Code */
#define I2C_STAT_MSTCODE_TXREADY (2UL) /*!< Master Transmit Ready State Code */
#define I2C_STAT_MSTCODE_NACKADR (3UL) /*!< Master NACK by slave on address State Code */
#define I2C_STAT_MSTCODE_NACKDAT (4UL) /*!< Master NACK by slave on data State Code */

/* definitions for SLVSTATE bits in I2C Status register STAT */
#define I2C_STAT_SLVST_ADDR (0)
#define I2C_STAT_SLVST_RX   (1)
#define I2C_STAT_SLVST_TX   (2)

/*! @brief I2C status return codes. */
enum
{
    kStatus_I2C_Busy = MAKE_STATUS(kStatusGroup_LPC_I2C, 0), /*!< The master is already performing a transfer. */
    kStatus_I2C_Idle = MAKE_STATUS(kStatusGroup_LPC_I2C, 1), /*!< The slave driver is idle. */
    kStatus_I2C_Nak  = MAKE_STATUS(kStatusGroup_LPC_I2C, 2), /*!< The slave device sent a NAK in response to a byte. */
    kStatus_I2C_InvalidParameter =
        MAKE_STATUS(kStatusGroup_LPC_I2C, 3), /*!< Unable to proceed due to invalid parameter. */
    kStatus_I2C_BitError        = MAKE_STATUS(kStatusGroup_LPC_I2C, 4), /*!< Transferred bit was not seen on the bus. */
    kStatus_I2C_ArbitrationLost = MAKE_STATUS(kStatusGroup_LPC_I2C, 5), /*!< Arbitration lost error. */
    kStatus_I2C_NoTransferInProgress =
        MAKE_STATUS(kStatusGroup_LPC_I2C, 6), /*!< Attempt to abort a transfer when one is not in progress. */
    kStatus_I2C_DmaRequestFail  = MAKE_STATUS(kStatusGroup_LPC_I2C, 7),  /*!< DMA request failed. */
    kStatus_I2C_StartStopError  = MAKE_STATUS(kStatusGroup_LPC_I2C, 8),  /*!< Start and stop error. */
    kStatus_I2C_UnexpectedState = MAKE_STATUS(kStatusGroup_LPC_I2C, 9),  /*!< Unexpected state. */
    kStatus_I2C_Addr_Nak        = MAKE_STATUS(kStatusGroup_LPC_I2C, 10), /*!< NAK received during the address probe. */
    kStatus_I2C_Timeout         = MAKE_STATUS(kStatusGroup_LPC_I2C, 11), /*!< Timeout polling status flags. */
    kStatus_I2C_EventTimeout    = MAKE_STATUS(kStatusGroup_LPC_I2C, 12), /*!< Timeout waiting for bus event. */
    kStatus_I2C_SclLowTimeout   = MAKE_STATUS(kStatusGroup_LPC_I2C, 13), /*!< Timeout SCL signal remains low. */
};

/*!
 * @addtogroup i2c_master_driver
 * @{
 */
/*!
 * @brief I2C master peripheral flags.
 *
 * @note These enums are meant to be OR'd together to form a bit mask.
 */
enum _i2c_master_flags
{
    kI2C_MasterPendingFlag = I2C_STAT_MSTPENDING_MASK, /*!< The I2C module is waiting for software interaction. */
    kI2C_MasterArbitrationLostFlag =
        I2C_STAT_MSTARBLOSS_MASK, /*!< The arbitration of the bus was lost. There was collision on the bus */
    kI2C_MasterStartStopErrorFlag =
        I2C_STAT_MSTSTSTPERR_MASK, /*!< There was an error during start or stop phase of the transaction. */
#if (defined(FSL_FEATURE_I2C_MASTER_SUPPORT_EVENT_TIMEOUT) && FSL_FEATURE_I2C_MASTER_SUPPORT_EVENT_TIMEOUT)
    kI2C_EventTimeoutFlag = I2C_STAT_EVENTTIMEOUT_MASK, /*!< The bus event timeout interrupt. */
#endif
#if (defined(FSL_FEATURE_I2C_MASTER_SUPPORT_SCL_TIMEOUT) && FSL_FEATURE_I2C_MASTER_SUPPORT_SCL_TIMEOUT)
    kI2C_SclTimeoutFlag = I2C_STAT_SCLTIMEOUT_MASK, /*!< The SCL timeout interrupt. */
#endif
};

/*! @brief Direction of master and slave transfers. */
typedef enum _i2c_direction
{
    kI2C_Write = 0U, /*!< Master transmit. */
    kI2C_Read  = 1U  /*!< Master receive. */
} i2c_direction_t;

/*! @brief Desired baud-rates of Master. */
typedef enum
{
    kI2C_Baudrate100kHz = 100000U,  /*!< Baudrate100kHz  */
    kI2C_Baudrate400kHz = 400000U,  /*!< Baudrate400kHz  */
    kI2C_Baudrate1MHz   = 1000000U, /*!< Baudrate1MHz    */
    kI2C_Baudrate3P4MHz = 3400000U  /*!< Baudrate3P4MHz  */
} i2c_baudrate_t;
/*!
 * @brief Structure with settings to initialize the I2C master module.
 *
 * This structure holds configuration settings for the I2C peripheral. To initialize this
 * structure to reasonable defaults, call the I2C_MasterGetDefaultConfig() function and
 * pass a pointer to your configuration structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _i2c_master_config
{
    bool enableMaster;     /*!< Whether to enable master mode. */
    uint32_t baudRate_Bps; /*!< Desired baud rate in bits per second. */
    bool enableTimeout;    /*!< Enable internal timeout function. */
} i2c_master_config_t;

/*! @} */

/*!
 * @addtogroup i2c_slave_driver
 * @{
 */

/*!
 * @brief I2C slave peripheral flags.
 *
 * @note These enums are meant to be OR'd together to form a bit mask.
 */
enum _i2c_slave_flags
{
    kI2C_SlavePendingFlag = I2C_STAT_SLVPENDING_MASK, /*!< The I2C module is waiting for software interaction. */
    kI2C_SlaveNotStretching =
        I2C_STAT_SLVNOTSTR_MASK, /*!< Indicates whether the slave is currently stretching clock (0 = yes, 1 = no). */
    kI2C_SlaveSelected = I2C_STAT_SLVSEL_MASK, /*!< Indicates whether the slave is selected by an address match. */
    kI2C_SaveDeselected =
        I2C_STAT_SLVDESEL_MASK /*!< Indicates that slave was previously deselected (deselect event took place, w1c). */
};

/*! @brief I2C slave address register. */
typedef enum _i2c_slave_address_register
{
    kI2C_SlaveAddressRegister0 = 0U, /*!< Slave Address 0 register. */
    kI2C_SlaveAddressRegister1 = 1U, /*!< Slave Address 1 register. */
    kI2C_SlaveAddressRegister2 = 2U, /*!< Slave Address 2 register. */
    kI2C_SlaveAddressRegister3 = 3U, /*!< Slave Address 3 register. */
} i2c_slave_address_register_t;

/*! @brief Data structure with 7-bit Slave address and Slave address disable. */
typedef struct _i2c_slave_address
{
    uint8_t address;     /*!< 7-bit Slave address SLVADR. */
    bool addressDisable; /*!< Slave address disable SADISABLE. */
} i2c_slave_address_t;

/*! @brief I2C slave address match options. */
typedef enum _i2c_slave_address_qual_mode
{
    kI2C_QualModeMask = 0U, /*!< The SLVQUAL0 field (qualAddress) is used as a logical mask for matching address0. */
    kI2C_QualModeExtend =
        1U, /*!< The SLVQUAL0 (qualAddress) field is used to extend address 0 matching in a range of addresses. */
} i2c_slave_address_qual_mode_t;

/*! @brief I2C slave bus speed options. */
typedef enum _i2c_slave_bus_speed
{
    kI2C_SlaveStandardMode = 0U,
    kI2C_SlaveFastMode     = 1U,
    kI2C_SlaveFastModePlus = 2U,
    kI2C_SlaveHsMode       = 3U,
} i2c_slave_bus_speed_t;

/*!
 * @brief Structure with settings to initialize the I2C slave module.
 *
 * This structure holds configuration settings for the I2C slave peripheral. To initialize this
 * structure to reasonable defaults, call the I2C_SlaveGetDefaultConfig() function and
 * pass a pointer to your configuration structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _i2c_slave_config
{
    i2c_slave_address_t address0;           /*!< Slave's 7-bit address and disable. */
    i2c_slave_address_t address1;           /*!< Alternate slave 7-bit address and disable. */
    i2c_slave_address_t address2;           /*!< Alternate slave 7-bit address and disable. */
    i2c_slave_address_t address3;           /*!< Alternate slave 7-bit address and disable. */
    i2c_slave_address_qual_mode_t qualMode; /*!< Qualify mode for slave address 0. */
    uint8_t qualAddress;                    /*!< Slave address qualifier for address 0. */
    i2c_slave_bus_speed_t
        busSpeed; /*!< Slave bus speed mode. If the slave function stretches SCL to allow for software response, it must
                       provide sufficient data setup time to the master before releasing the stretched clock.
                       This is accomplished by inserting one clock time of CLKDIV at that point.
                       The #busSpeed value is used to configure CLKDIV
                       such that one clock time is greater than the tSU;DAT value noted
                       in the I2C bus specification for the I2C mode that is being used.
                       If the #busSpeed mode is unknown at compile time, use the longest data setup time
                       kI2C_SlaveStandardMode (250 ns) */
    bool enableSlave; /*!< Enable slave mode. */
} i2c_slave_config_t;

/*! @} */
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Array of I2C IRQ number. */
extern const IRQn_Type s_i2cIRQ[];

/*! @brief Typedef for interrupt handler. */
typedef void (*i2c_isr_t)(I2C_Type *base, void *i2cHandle);

#if defined(FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS) && (FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS)
/*! @brief Pointers to i2c handles for each instance. */
extern void *s_i2cHandle[FSL_FEATURE_SOC_I2C_COUNT];

/*! @brief Pointer to master IRQ handler for each instance. */
extern i2c_isr_t s_i2cMasterIsr;

/*! @brief Pointer to slave IRQ handler for each instance. */
extern i2c_isr_t s_i2cSlaveIsr;
#endif /* FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS */

/*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @addtogroup i2c_master_driver
 * @{
 */

/*! @name Initialization and de-initialization */
/*! @{ */

/*!
 * @brief Provides a default configuration for the I2C master peripheral.
 *
 * This function provides the following default configuration for the I2C master peripheral:
 * @code
 *  masterConfig->enableMaster            = true;
 *  masterConfig->baudRate_Bps            = 100000U;
 *  masterConfig->enableTimeout           = false;
 * @endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the master driver with I2C_MasterInit().
 *
 * @param[out] masterConfig User provided configuration structure for default values. Refer to #i2c_master_config_t.
 */
void I2C_MasterGetDefaultConfig(i2c_master_config_t *masterConfig);

/*!
 * @brief Initializes the I2C master peripheral.
 *
 * This function enables the peripheral clock and initializes the I2C master peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration.
 *
 * @param base The I2C peripheral base address.
 * @param masterConfig User provided peripheral configuration. Use I2C_MasterGetDefaultConfig() to get a set of
 * defaults
 *      that you can override.
 * @param srcClock_Hz Frequency in Hertz of the I2C functional clock. Used to calculate the baud rate divisors,
 *      filter widths, and timeout periods.
 * @retval kStatus_Success Master init Success.
 * @retval kStatus_InvalidArgument 	 Master init fail.
 */
status_t I2C_MasterInit(I2C_Type *base, const i2c_master_config_t *masterConfig, uint32_t srcClock_Hz);

/*!
 * @brief De-initializes the I2C master peripheral.
 *
 * This function disables the I2C master peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The I2C peripheral base address.
 */
void I2C_MasterDeinit(I2C_Type *base);

/*!
 * @brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * @param base The I2C peripheral base address.
 * @return I2C instance number starting from 0.
 */
uint32_t I2C_GetInstance(I2C_Type *base);

/*!
 * @brief Performs a software reset.
 *
 * Restores the I2C master peripheral to reset conditions.
 *
 * @param base The I2C peripheral base address.
 */
static inline void I2C_MasterReset(I2C_Type *base)
{
}

/*!
 * @brief Enables or disables the I2C module as master.
 *
 * @param base The I2C peripheral base address.
 * @param enable Pass true to enable or false to disable the specified I2C as master.
 */
static inline void I2C_MasterEnable(I2C_Type *base, bool enable)
{
    if (enable)
    {
        base->CFG = (base->CFG & I2C_CFG_MASK) | (uint32_t)I2C_CFG_MSTEN_MASK;
    }
    else
    {
        base->CFG = (base->CFG & I2C_CFG_MASK) & (~(uint32_t)I2C_CFG_MSTEN_MASK);
    }
}

/*! @} */

/*! @name Status */
/*! @{ */

/*!
 * @brief Gets the I2C status flags.
 *
 * A bit mask with the state of all I2C status flags is returned. For each flag, the corresponding bit
 * in the return value is set if the flag is asserted.
 *
 * @param base The I2C peripheral base address.
 * @return State of the status flags:
 *         - 1: related status flag is set.
 *         - 0: related status flag is not set.
 * @see _i2c_master_flags
 */
static inline uint32_t I2C_GetStatusFlags(I2C_Type *base)
{
    return base->STAT;
}

/*!
 * @brief Clears the I2C master status flag state.
 *
 * The following status register flags can be cleared:
 * - #kI2C_MasterArbitrationLostFlag
 * - #kI2C_MasterStartStopErrorFlag
 *
 * Attempts to clear other flags has no effect.
 *
 * @param base The I2C peripheral base address.
 * @param statusMask A bitmask of status flags that are to be cleared. The mask is composed of
 *  #_i2c_master_flags enumerators OR'd together. You may pass the result of a previous call to
 *  I2C_GetStatusFlags().
 * @see _i2c_master_flags.
 */
static inline void I2C_MasterClearStatusFlags(I2C_Type *base, uint32_t statusMask)
{
    /* Allow clearing just master status flags */
    base->STAT = statusMask & (I2C_STAT_MSTARBLOSS_MASK | I2C_STAT_MSTSTSTPERR_MASK);
}

/*! @} */

/*! @name Interrupts */
/*! @{ */

/*!
 * @brief Enables the I2C master interrupt requests.
 *
 * @param base The I2C peripheral base address.
 * @param interruptMask Bit mask of interrupts to enable. See #_i2c_master_flags for the set
 *      of constants that should be OR'd together to form the bit mask.
 */
static inline void I2C_EnableInterrupts(I2C_Type *base, uint32_t interruptMask)
{
    base->INTENSET = interruptMask;
}

/*!
 * @brief Disables the I2C master interrupt requests.
 *
 * @param base The I2C peripheral base address.
 * @param interruptMask Bit mask of interrupts to disable. See #_i2c_master_flags for the set
 *      of constants that should be OR'd together to form the bit mask.
 */
static inline void I2C_DisableInterrupts(I2C_Type *base, uint32_t interruptMask)
{
    base->INTENCLR = interruptMask;
}

/*!
 * @brief Returns the set of currently enabled I2C master interrupt requests.
 *
 * @param base The I2C peripheral base address.
 * @return A bitmask composed of #_i2c_master_flags enumerators OR'd together to indicate the
 *      set of enabled interrupts.
 */
static inline uint32_t I2C_GetEnabledInterrupts(I2C_Type *base)
{
    return base->INTSTAT;
}

/*! @} */

/*! @name Bus operations */
/*! @{ */

/*!
 * @brief Sets the I2C bus frequency for master transactions.
 *
 * The I2C master is automatically disabled and re-enabled as necessary to configure the baud
 * rate. Do not call this function during a transfer, or the transfer is aborted.
 *
 * @param base The I2C peripheral base address.
 * @param srcClock_Hz I2C functional clock frequency in Hertz.
 * @param baudRate_Bps Requested bus frequency in bits per second.
 * @retval kStatus_Success baud-rate set Successfully.
 * @retval kStatus_Fail Invalid selection of baud-rate or srcClock_Hz.
 */
status_t I2C_MasterSetBaudRate(I2C_Type *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz);

/*!
 * @brief Returns whether the bus is idle.
 *
 * Requires the master mode to be enabled.
 *
 * @param base The I2C peripheral base address.
 * @retval true Bus is busy.
 * @retval false Bus is idle.
 */
static inline bool I2C_MasterGetBusIdleState(I2C_Type *base)
{
    /* True if MSTPENDING flag is set and MSTSTATE is zero == idle */
    return ((base->STAT & (I2C_STAT_MSTPENDING_MASK | I2C_STAT_MSTSTATE_MASK)) == I2C_STAT_MSTPENDING_MASK);
}

/*!
 * @brief Sends a START on the I2C bus.
 *
 * This function is used to initiate a new master mode transfer by sending the START signal.
 * The slave address is sent following the I2C START signal.
 *
 * @param base I2C peripheral base pointer
 * @param address 7-bit slave device address.
 * @param direction Master transfer directions(transmit/receive).
 * @retval kStatus_Success Successfully send the start signal.
 * @retval kStatus_I2C_Busy Current bus is busy.
 */
status_t I2C_MasterStart(I2C_Type *base, uint8_t address, i2c_direction_t direction);

/*!
 * @brief Sends a STOP signal on the I2C bus.
 *
 * @retval kStatus_Success Successfully send the stop signal.
 * @retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterStop(I2C_Type *base);

/*!
 * @brief Sends a REPEATED START on the I2C bus.
 *
 * @param base I2C peripheral base pointer
 * @param address 7-bit slave device address.
 * @param direction Master transfer directions(transmit/receive).
 * @retval kStatus_Success Successfully send the start signal.
 * @retval kStatus_I2C_Busy Current bus is busy but not occupied by current I2C master.
 */
static inline status_t I2C_MasterRepeatedStart(I2C_Type *base, uint8_t address, i2c_direction_t direction)
{
    return I2C_MasterStart(base, address, direction);
}

/*! @} */

/*! @} */ /* end of i2c_master_driver */

/*!
 * @addtogroup i2c_slave_driver
 * @{
 */

/*! @name Slave initialization and deinitialization */
/*! @{ */

/*!
 * @brief Provides a default configuration for the I2C slave peripheral.
 *
 * This function provides the following default configuration for the I2C slave peripheral:
 * @code
 *  slaveConfig->enableSlave = true;
 *  slaveConfig->address0.disable = false;
 *  slaveConfig->address0.address = 0u;
 *  slaveConfig->address1.disable = true;
 *  slaveConfig->address2.disable = true;
 *  slaveConfig->address3.disable = true;
 *  slaveConfig->busSpeed = kI2C_SlaveStandardMode;
 * @endcode
 *
 * After calling this function, override any settings  to customize the configuration,
 * prior to initializing the master driver with I2C_SlaveInit(). Be sure to override at least the @a
 * address0.address member of the configuration structure with the desired slave address.
 *
 * @param[out] slaveConfig User provided configuration structure that is set to default values. Refer to
 *      #i2c_slave_config_t.
 */
void I2C_SlaveGetDefaultConfig(i2c_slave_config_t *slaveConfig);

/*!
 * @brief Initializes the I2C slave peripheral.
 *
 * This function enables the peripheral clock and initializes the I2C slave peripheral as described by the user
 * provided configuration.
 *
 * @param base The I2C peripheral base address.
 * @param slaveConfig User provided peripheral configuration. Use I2C_SlaveGetDefaultConfig() to get a set of defaults
 *      that you can override.
 * @param srcClock_Hz Frequency in Hertz of the I2C functional clock. Used to calculate CLKDIV value to provide
 * enough
 *                       data setup time for master when slave stretches the clock.
 */
status_t I2C_SlaveInit(I2C_Type *base, const i2c_slave_config_t *slaveConfig, uint32_t srcClock_Hz);

/*!
 * @brief Configures Slave Address n register.
 *
 * This function writes new value to Slave Address register.
 *
 * @param base The I2C peripheral base address.
 * @param addressRegister The module supports multiple address registers. The parameter determines which one shall be
 * changed.
 * @param address The slave address to be stored to the address register for matching.
 * @param addressDisable Disable matching of the specified address register.
 */
void I2C_SlaveSetAddress(I2C_Type *base,
                         i2c_slave_address_register_t addressRegister,
                         uint8_t address,
                         bool addressDisable);

/*!
 * @brief Deinitializes the I2C slave peripheral.
 *
 * This function disables the I2C slave peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The I2C peripheral base address.
 */
void I2C_SlaveDeinit(I2C_Type *base);

/*!
 * @brief Enables or disables the I2C module as slave.
 *
 * @param base The I2C peripheral base address.
 * @param enable True to enable or flase to disable.
 */
static inline void I2C_SlaveEnable(I2C_Type *base, bool enable)
{
    /* Set or clear the SLVEN bit in the CFG register. */
    base->CFG = I2C_CFG_SLVEN(enable);
}

/*! @} */ /* end of Slave initialization and deinitialization */

/*! @name Slave status */
/*! @{ */

/*!
 * @brief Clears the I2C status flag state.
 *
 * The following status register flags can be cleared:
 * - slave deselected flag
 *
 * Attempts to clear other flags has no effect.
 *
 * @param base The I2C peripheral base address.
 * @param statusMask A bitmask of status flags that are to be cleared. The mask is composed of
 *  #_i2c_slave_flags enumerators OR'd together. You may pass the result of a previous call to
 *  I2C_SlaveGetStatusFlags().
 * @see _i2c_slave_flags.
 */
static inline void I2C_SlaveClearStatusFlags(I2C_Type *base, uint32_t statusMask)
{
    /* Allow clearing just slave status flags */
    base->STAT = statusMask & I2C_STAT_SLVDESEL_MASK;
}

/*! @} */ /* end of Slave status */

/*! @} */ /* end of i2c_slave_driver */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_I2C_H_ */
