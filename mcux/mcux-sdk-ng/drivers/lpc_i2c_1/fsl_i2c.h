/*
 * Copyright 2018-2020 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_I2C_H_
#define FSL_I2C_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @addtogroup i2c_driver
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief I2C driver version 2.0.1. */
#define FSL_I2C_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief Retry times for waiting flag. */
#ifndef I2C_RETRY_TIMES
#define I2C_RETRY_TIMES 0U /* Define to zero means keep waiting until the flag is assert/deassert. */
#endif

#define I2C_COMMONCODE_ERROR (0x00U) /*!< MASTER/SLAVE: Bus error happens. */

/*! @brief I2C status return codes. */
enum _i2c_status
{
    kStatus_I2C_Busy = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 0), /*!< The master is already performing a transfer. */
    kStatus_I2C_Nak = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 1), /*!< The slave device sent a NAK in response to a byte. */
    kStatus_I2C_Addr_Nak = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 2), /*!< NAK received during the address probe. */
    kStatus_I2C_BusError = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 3), /*!< Transferred bit was not seen on the bus. */
    kStatus_I2C_ArbitrationLost = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 4), /*!< Arbitration lost error. */
    kStatus_I2C_Timeout         = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 5), /*!< Timeout polling status flags. */
    kStatus_I2C_StateError      = MAKE_STATUS(kStatusGroup_LPC_I2C_1, 6), /*!< Polling state error. */
};

/*!
 * @brief I2C peripheral flags.
 *
 * The following status register flags can be set/cleared:
 * - #kI2C_InterruptFlag -> Clear to continue I2C state change.
 * - #kI2C_AssertACKFlag -> Set/Clear to issue an ACK/NACK.
 * - #kI2C_StartFlag -> Set/Clear to issue/clear START signal.
 * - #kI2C_StopFlag -> Set to issue STOP signal, clear automatically.
 *
 * @note These enums are meant to be OR'd together to form a bit mask.
 */
enum _i2c_flags
{
    kI2C_InterruptFlag = I2C0_CONCLR_SIC_MASK, /*!< Clear to continue I2C state change. */
    kI2C_AssertACKFlag = I2C0_CONSET_AA_MASK,  /*!< Set/Clear to issue an ACK/NACK. */
    kI2C_StartFlag     = I2C0_CONSET_STA_MASK, /*!< Set/Clear to issue/clear START signal. */
    kI2C_StopFlag      = I2C0_CONSET_STO_MASK, /*!< Set to issue STOP signal. */
    kI2C_AllFlags      = (I2C0_CONCLR_SIC_MASK | I2C0_CONSET_AA_MASK | I2C0_CONSET_STA_MASK |
                     I2C0_CONSET_STO_MASK), /*!< All CON flags. */
};

/*! @} */

/*!
 * @addtogroup i2c_master_driver
 * @{
 */

/*! @brief Definitions for MSTCODE in I2C Status register STAT */
enum _i2c_master_state
{
    kI2C_Master_StartReady    = 0x08U, /*!< MASTER: A START condition has been transmitted */
    kI2C_Master_RestartReady  = 0x10U, /*!< MASTER: A Repeated-START condition has been transmitted */
    kI2C_Master_TxAckAddress  = 0x18U, /*!< MASTER: SLA+W has been transmitted, ACK has been received */
    kI2C_Master_TxNackAddress = 0x20U, /*!< MASTER: SLA+W has been transmitted, NACK has been received */
    kI2C_Master_TxAckData     = 0x28U, /*!< MASTER: Data byte in I2DAT has been transmitted, ACK has been received. */
    kI2C_Master_TxNackData    = 0x30U, /*!< MASTER: Data byte in I2DAT has been transmitted, NACK has been received. */
    kI2C_Master_ArbitrationLost = 0x38U, /*!< MASTER: Arbitration lost. */
    kI2C_Master_RxAckaddress    = 0x40U, /*!< MASTER: SLA+R has been transmitted, ACK has been received */
    kI2C_Master_RxNackaddress   = 0x48U, /*!< MASTER: SLA+R has been transmitted, NACK has been received */
    kI2C_Master_RxAckData       = 0x50U, /*!< MASTER: Data byte in I2DAT has been transmitted, ACK has been returned. */
    kI2C_Master_RxNackData = 0x58U, /*!< MASTER: Data byte in I2DAT has been transmitted, NACK has been returned. */
};

/*! @brief Direction of master and slave transfers. */
typedef enum _i2c_direction
{
    kI2C_Write = 0U, /*!< Master transmit. */
    kI2C_Read  = 1U  /*!< Master receive. */
} i2c_direction_t;

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
} i2c_master_config_t;

/* Forward declaration of the transfer descriptor and handle typedefs. */
/*! @brief I2C master transfer typedef */
typedef struct _i2c_master_transfer i2c_master_transfer_t;

/*! @brief I2C master handle typedef */
typedef struct _i2c_master_handle i2c_master_handle_t;

/*!
 * @brief Master completion callback function pointer type.
 *
 * This callback is used only for the non-blocking master transfer API. Specify the callback you wish to use
 * in the call to I2C_MasterTransferCreateHandle().
 *
 * @param base The I2C peripheral base address.
 * @param completionStatus Either kStatus_Success or an error code describing how the transfer completed.
 * @param userData Arbitrary pointer-sized value passed from the application.
 */
typedef void (*i2c_master_transfer_callback_t)(I2C0_Type *base,
                                               i2c_master_handle_t *handle,
                                               status_t completionStatus,
                                               void *userData);

/*!
 * @brief Transfer option flags.
 *
 * @note These enumerations are intended to be OR'd together to form a bit mask of options for
 * the #_i2c_master_transfer::flags field.
 */
enum _i2c_master_transfer_flags
{
    kI2C_TransferDefaultFlag       = 0x00U, /*!< Transfer starts with a start signal, stops with a stop signal. */
    kI2C_TransferNoStartFlag       = 0x01U, /*!< Don't send a start condition, address, and sub address */
    kI2C_TransferRepeatedStartFlag = 0x02U, /*!< Send a repeated start condition */
    kI2C_TransferNoStopFlag        = 0x04U, /*!< Don't send a stop condition. */
};

/*! @brief States for the state machine used by transactional APIs. */
enum _i2c_transfer_states
{
    kIdleState = 0,
    kBusyState,
};

/*!
 * @brief Non-blocking transfer descriptor structure.
 *
 * This structure is used to pass transaction parameters to the I2C_MasterTransferNonBlocking() API.
 */
struct _i2c_master_transfer
{
    uint32_t flags; /*!< Bit mask of options for the transfer. See enumeration #_i2c_master_transfer_flags for available
                         options. Set to 0 or #kI2C_TransferDefaultFlag for normal transfers. */
    uint16_t slaveAddress;     /*!< The 7-bit slave address. */
    i2c_direction_t direction; /*!< Either #kI2C_Read or #kI2C_Write. */
    uint32_t subaddress;       /*!< Sub address. Transferred MSB first. */
    size_t subaddressSize;     /*!< Length of sub address to send in bytes. Maximum size is 4 bytes. */
    uint8_t *data;             /*!< Pointer to data to transfer. */
    size_t dataSize;           /*!< Number of bytes to transfer. */
};

/*!
 * @brief Driver handle for master non-blocking APIs.
 * @note The contents of this structure are private and subject to change.
 */
struct _i2c_master_handle
{
    uint8_t state;                                     /*!< Transfer state machine current state. */
    uint32_t transferSize;                             /*!< Indicates progress of the transfer */
    i2c_master_transfer_t transfer;                    /*!< Copy of the current transfer info. */
    i2c_master_transfer_callback_t completionCallback; /*!< Callback function pointer. */
    void *userData;                                    /*!< Application data passed to callback. */
};

/*! @} */

/*!
 * @addtogroup i2c_slave_driver
 * @{
 */

/*! @brief Definitions for SLVCODE in I2C Status register STAT */
enum _i2c_slave_state
{
    kI2C_Slave_AddressWriteAck = 0x60U, /*!< SLAVE: Receive mode, own SLA+W has been received, ACK has been returned. */
    kI2C_Slave_MasterArbitrationLostAddressWriteAck = 0x68U, /*!< SLAVE: Receive mode, arbitration lost in SLA+R/W as
                                                                master, own SLA+W has been received, ACK returned. */
    kI2C_Slave_GeneralCallAck =
        0x70U, /*!< SLAVE: Receive mode, general Call address(0x00) has been received, ACK has been returned. */
    kI2C_Slave_MasterArbitrationLostGeneralCallAck =
        0x78U, /*!< SLAVE: Receive mode, arbitration lost in SLA+R/W as master, General Call address(0x00) has been
                  received, ACK has been returned. */
    kI2C_Slave_AddressRxAckData = 0x80U,      /*!< SLAVE: Previously addressed with own Slave address, DATA has been
                                                 received, ACK has been returned. */
    kI2C_Slave_AddressRxNackData = 0x88U,     /*!< SLAVE: Previously addressed with own Slave address, DATA has been
                                                 received, NACK has been returned. */
    kI2C_Slave_GeneralCallRxAckData = 0x90U,  /*!< SLAVE: Previously addressed with General Call address, DATA has been
                                                 received, ACK has been returned. */
    kI2C_Slave_GeneralCallRxNackData = 0x98U, /*!< SLAVE: Previously addressed with General Call address, DATA has been
                                                 received, NACK has been returned. */
    kI2C_Slave_RxRestartStop = 0xA0U,  /*!< SLAVE: A STOP condition or Repeated-START condition has been received while
                                          still addressed as slave receiver or slave transmitter. */
    kI2C_Slave_AddressReadAck = 0xA8U, /*!< SLAVE: Transmit mode, own SLA+R has been received, ACK has been returned. */
    kI2C_Slave_MasterArbitrationLostAddressReadAck = 0xB0U, /*!< SLAVE: Transmit mode, arbitration lost in SLA+R/W as
                                                               master, own SLA+W has been received, ACK returned. */
    kI2C_Slave_TxAckData  = 0xB8U, /*!< SLAVE: Data byte in I2DAT has been transmitted, ACK has been received. */
    kI2C_Slave_TxNackData = 0xC0U, /*!< SLAVE: Data byte in I2DAT has been transmitted, NACK has been received. */
    kI2C_Slave_TxAckLastData =
        0xC8U, /*!< SLAVE: last dataa byte in I2DAT has been transmitted (AA = 0), ACK has been received. */
};

/*! @brief I2C slave address register. */
typedef enum _i2c_slave_address_register
{
    kI2C_SlaveAddressRegister0 = 0U, /*!< Slave Address 0 register. */
    kI2C_SlaveAddressRegister1 = 1U, /*!< Slave Address 1 register. */
    kI2C_SlaveAddressRegister2 = 2U, /*!< Slave Address 2 register. */
    kI2C_SlaveAddressRegister3 = 3U, /*!< Slave Address 3 register. */
} i2c_slave_address_register_t;

/*! @brief Data structure for slave address configuration. */
typedef struct _i2c_slave_address
{
    uint8_t address;        /*!< 7-bit Slave address . */
    uint8_t addressMask;    /*!< Slave address mask. */
    bool enableGeneralCall; /*!< Enable general call. */
} i2c_slave_address_t;

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
    i2c_slave_address_t address0; /*!< Slave address0 configuration. */
    i2c_slave_address_t address1; /*!< Slave address1 configuration. */
    i2c_slave_address_t address2; /*!< Slave address2 configuration. */
    i2c_slave_address_t address3; /*!< Slave address3 configuration. */
    bool enableSlave;             /*!< Enable slave mode. */
} i2c_slave_config_t;

/*!
 * @brief Set of events sent to the callback for non blocking slave transfers.
 *
 * These event enumerations are used for two related purposes. First, a bit mask created by OR'ing together
 * events is passed to I2C_SlaveTransferNonBlocking() in order to specify which events to enable.
 * Then, when the slave callback is invoked, it is passed the current event through its @a transfer
 * parameter.
 *
 * @note These enumerations are meant to be OR'd together to form a bit mask of events.
 */
typedef enum _i2c_slave_transfer_event
{
    kI2C_SlaveTransmitEvent = 0x02U,   /*!< Callback is requested to provide data to transmit
                                              (slave-transmitter role). */
    kI2C_SlaveReceiveEvent = 0x04U,    /*!< Callback is requested to provide a buffer in which to place received
                                               data (slave-receiver role). */
    kI2C_SlaveCompletionEvent = 0x20U, /*!< All data in the active transfer have been consumed. */
    /*! Bit mask of all available events. */
    kI2C_SlaveAllEvents = kI2C_SlaveTransmitEvent | kI2C_SlaveReceiveEvent | kI2C_SlaveCompletionEvent,
} i2c_slave_transfer_event_t;

/*! @brief I2C slave handle typedef. */
typedef struct _i2c_slave_handle i2c_slave_handle_t;

/*! @brief I2C slave transfer structure */
typedef struct _i2c_slave_transfer
{
    i2c_slave_transfer_event_t event; /*!< Reason the callback is being invoked. */
    uint8_t receivedAddress;          /*!< Matching address send by master. 7-bits plus R/nW bit0 */
    uint32_t eventMask;               /*!< Mask of enabled events. */
    uint8_t *rxData;                  /*!< Transfer buffer for receive data */
    const uint8_t *txData;            /*!< Transfer buffer for transmit data */
    size_t txSize;                    /*!< Transfer size */
    size_t rxSize;                    /*!< Transfer size */
    size_t transferredCount;          /*!< Number of bytes transferred during this transfer. */
    status_t completionStatus;        /*!< Success or error code describing how the transfer completed. Only applies for
                                         #kI2C_SlaveCompletionEvent. */
} i2c_slave_transfer_t;

/*!
 * @brief Slave event callback function pointer type.
 *
 * This callback is used only for the slave non-blocking transfer API. To install a callback,
 * use the I2C_SlaveSetCallback() function after you have created a handle.
 *
 * @param base Base address for the I2C instance on which the event occurred.
 * @param transfer Pointer to transfer descriptor containing values passed to and/or from the callback.
 * @param userData Arbitrary pointer-sized value passed from the application.
 */
typedef void (*i2c_slave_transfer_callback_t)(I2C0_Type *base, volatile i2c_slave_transfer_t *transfer, void *userData);

/*!
 * @brief I2C slave handle structure.
 * @note The contents of this structure are private and subject to change.
 */
struct _i2c_slave_handle
{
    volatile i2c_slave_transfer_t transfer; /*!< I2C slave transfer. */
    volatile bool isBusy;                   /*!< Whether transfer is busy. */
    i2c_slave_transfer_callback_t callback; /*!< Callback function called at transfer event. */
    void *userData;                         /*!< Callback parameter passed to callback. */
};

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

/*! @name Initialization and deinitialization */
/*! @{ */

/*!
 * @brief Provides a default configuration for the I2C master peripheral.
 *
 * This function provides the following default configuration for the I2C master peripheral:
 * @code
 *  masterConfig->enableMaster            = true;
 *  masterConfig->baudRate_Bps            = 100000U;
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
 */
void I2C_MasterInit(I2C0_Type *base, const i2c_master_config_t *masterConfig, uint32_t srcClock_Hz);

/*!
 * @brief Deinitializes the I2C master peripheral.
 *
 * This function disables the I2C master peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The I2C peripheral base address.
 */
void I2C_MasterDeinit(I2C0_Type *base);

/*!
 * @brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * @param base The I2C peripheral base address.
 * @return I2C instance number starting from 0.
 */
uint32_t I2C_GetInstance(I2C0_Type *base);

/*!
 * @brief Enables or disables the I2C module as master.
 *
 * @param base The I2C peripheral base address.
 * @param enable Pass true to enable or false to disable the specified I2C as master.
 */
static inline void I2C_MasterEnable(I2C0_Type *base, bool enable)
{
    if (enable)
    {
        base->CONSET = I2C0_CONSET_I2EN_MASK;
    }
    else
    {
        base->CONCLR = I2C0_CONCLR_I2ENC_MASK;
    }
}

/*! @} */

/*! @name Status */
/*! @{ */

/*!
 * @brief Gets the I2C master status flags.
 *
 * A bit mask with the state of all I2C control flags is returned. For each flag, the corresponding bit
 * in the return value is set if the flag is asserted.
 *
 * @param base The I2C peripheral base address.
 * @return State of the status flags:
 *         - 1: related status flag is set.
 *         - 0: related status flag is not set.
 * @see _i2c_flags
 */
static inline uint32_t I2C_MasterGetStatusFlags(I2C0_Type *base)
{
    return base->CONSET;
}

/*!
 * @brief Clears the I2C master status flag state.
 *
 * The following status register flags can be cleared:
 * - #kI2C_InterruptFlag
 * - #kI2C_StartFlag
 * - #kI2C_AssertACKFlag
 *
 * Attempts to clear other flags has no effect.
 *
 * @param base The I2C peripheral base address.
 * @param statusMask A bitmask of status flags that are to be cleared. The mask is composed of
 *  #_i2c_flags enumerators OR'd together. You may pass the result of a previous call to
 *  I2C_GetStatusFlags().
 * @see _i2c_flags.
 */
static inline void I2C_MasterClearStatusFlags(I2C0_Type *base, uint32_t statusMask)
{
    /* Allow clearing just master status flags */
    base->CONCLR = statusMask & (kI2C_InterruptFlag | kI2C_StartFlag | kI2C_AssertACKFlag);
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
 */
void I2C_MasterSetBaudRate(I2C0_Type *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz);

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
 * @retval kStatus_I2C_Timeout Send start signal failed, timeout.
 */
status_t I2C_MasterStart(I2C0_Type *base, uint8_t address, i2c_direction_t direction);

/*!
 * @brief Sends a STOP signal on the I2C bus.
 *
 * @retval kStatus_Success Successfully send the stop signal.
 * @retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterStop(I2C0_Type *base);

/*!
 * @brief Sends a REPEATED START on the I2C bus.
 *
 * @param base I2C peripheral base pointer
 * @param address 7-bit slave device address.
 * @param direction Master transfer directions(transmit/receive).
 * @retval kStatus_Success Successfully send the start signal.
 * @retval kStatus_I2C_Timeout Send repeated-start signal failed, timeout.
 */
status_t I2C_MasterRepeatedStart(I2C0_Type *base, uint8_t address, i2c_direction_t direction);

/*!
 * @brief Performs a polling send transfer on the I2C bus.
 *
 * Sends up to @a txSize number of bytes to the previously addressed slave device. The slave may
 * reply with a NAK to any byte in order to terminate the transfer early. If this happens, this
 * function returns #kStatus_I2C_Nak.
 *
 * @param base  The I2C peripheral base address.
 * @param txBuff The pointer to the data to be transferred.
 * @param txSize The length in bytes of the data to be transferred.
 * @param flags Transfer control flag to control special behavior like suppressing start or stop, for normal transfers
 * use kI2C_TransferDefaultFlag
 * @retval kStatus_Success Data was sent successfully.
 * @retval #kStatus_I2C_Busy Another master is currently utilizing the bus.
 * @retval #kStatus_I2C_Nak The slave device sent a NAK in response to a byte.
 * @retval #kStatus_I2C_ArbitrationLost Arbitration lost error.
 */
status_t I2C_MasterWriteBlocking(I2C0_Type *base, const void *txBuff, size_t txSize, uint32_t flags);

/*!
 * @brief Performs a polling receive transfer on the I2C bus.
 *
 * @param base  The I2C peripheral base address.
 * @param rxBuff The pointer to the data to be transferred.
 * @param rxSize The length in bytes of the data to be transferred.
 * @param flags Transfer control flag to control special behavior like suppressing start or stop, for normal transfers
 * use kI2C_TransferDefaultFlag
 * @retval kStatus_Success Data was received successfully.
 * @retval #kStatus_I2C_Busy Another master is currently utilizing the bus.
 * @retval #kStatus_I2C_Nak The slave device sent a NAK in response to a byte.
 * @retval #kStatus_I2C_ArbitrationLost Arbitration lost error.
 */
status_t I2C_MasterReadBlocking(I2C0_Type *base, void *rxBuff, size_t rxSize, uint32_t flags);

/*!
 * @brief Performs a master polling transfer on the I2C bus.
 *
 * @note The API does not return until the transfer succeeds or fails due
 * to arbitration lost or receiving a NAK.
 *
 * @param base I2C peripheral base address.
 * @param xfer Pointer to the transfer structure.
 * @retval kStatus_Success Successfully complete the data transmission.
 * @retval kStatus_I2C_Busy Previous transmission still not finished.
 * @retval kStatus_I2C_Timeout Transfer error, wait signal timeout.
 * @retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval kStataus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferBlocking(I2C0_Type *base, i2c_master_transfer_t *xfer);

/*! @} */

/*! @name Non-blocking */
/*! @{ */

/*!
 * @brief Creates a new handle for the I2C master non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I2C_MasterTransferAbort() API shall be called.
 *
 * @param base The I2C peripheral base address.
 * @param[out] handle Pointer to the I2C master driver handle.
 * @param callback User provided pointer to the asynchronous callback function.
 * @param userData User provided pointer to the application callback data.
 */
void I2C_MasterTransferCreateHandle(I2C0_Type *base,
                                    i2c_master_handle_t *handle,
                                    i2c_master_transfer_callback_t callback,
                                    void *userData);

/*!
 * @brief Performs a non-blocking transaction on the I2C bus.
 *
 * @param base The I2C peripheral base address.
 * @param handle Pointer to the I2C master driver handle.
 * @param xfer The pointer to the transfer descriptor.
 * @retval kStatus_Success The transaction was started successfully.
 * @retval #kStatus_I2C_Busy Either another master is currently utilizing the bus, or a non-blocking
 *      transaction is already in progress.
 */
status_t I2C_MasterTransferNonBlocking(I2C0_Type *base, i2c_master_handle_t *handle, i2c_master_transfer_t *xfer);

/*!
 * @brief Returns number of bytes transferred so far.
 * @param base The I2C peripheral base address.
 * @param handle Pointer to the I2C master driver handle.
 * @param[out] count Number of bytes transferred so far by the non-blocking transaction.
 * @retval kStatus_Success
 * @retval #kStatus_I2C_Busy
 */
status_t I2C_MasterTransferGetCount(I2C0_Type *base, i2c_master_handle_t *handle, size_t *count);

/*!
 * @brief Terminates a non-blocking I2C master transmission early.
 *
 * @note It is not safe to call this function from an IRQ handler that has a higher priority than the
 *      I2C peripheral's IRQ priority.
 *
 * @param base The I2C peripheral base address.
 * @param handle Pointer to the I2C master driver handle.
 * @retval kStatus_Success A transaction was successfully aborted.
 * @retval #kStatus_I2C_Timeout Abort failure due to flags polling timeout.
 */
status_t I2C_MasterTransferAbort(I2C0_Type *base, i2c_master_handle_t *handle);

/*! @} */

/*! @name IRQ handler */
/*! @{ */

/*!
 * @brief Reusable routine to handle master interrupts.
 * @note This function does not need to be called unless you are reimplementing the
 *  nonblocking API's interrupt handler routines to add special functionality.
 * @param base The I2C peripheral base address.
 * @param i2cHandle Pointer to the I2C master driver handle i2c_master_handle_t.
 */
void I2C_MasterTransferHandleIRQ(I2C0_Type *base, void *i2cHandle);

/*! @} */

/*! @} */ /* end of i2c_master */

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
 * slaveConfig->address0 = 0x0U;
 * slaveConfig->address1 = 0x0U;
 * slaveConfig->address2 = 0x0U;
 * slaveConfig->address3 = 0x0U;
 * slaveConfig->enableGeneralCall = false;
 * slaveConfig->enableSlave = true;
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
 *
 */
status_t I2C_SlaveInit(I2C0_Type *base, const i2c_slave_config_t *slaveConfig);

/*!
 * @brief Configures Slave Address n register.
 *
 * This function writes new value to Slave Address register.
 *
 * @param base The I2C peripheral base address.
 * @param addressRegister The module supports multiple address registers. The parameter determines which one shall be
 * changed.
 * @param addressConfig The slave address configuration.
 */
void I2C_SlaveSetAddress(I2C0_Type *base,
                         i2c_slave_address_register_t addressRegister,
                         i2c_slave_address_t *addressConfig);

/*!
 * @brief Deinitializes the I2C slave peripheral.
 *
 * This function disables the I2C slave peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The I2C peripheral base address.
 */
void I2C_SlaveDeinit(I2C0_Type *base);

/*!
 * @brief Enables or disables the I2C module as slave.
 *
 * @param base The I2C peripheral base address.
 * @param enable True to enable or flase to disable.
 */
static inline void I2C_SlaveEnable(I2C0_Type *base, bool enable)
{
    if (enable)
    {
        base->CONSET = I2C0_CONSET_I2EN_MASK | I2C0_CONSET_AA_MASK;
    }
    else
    {
        base->CONCLR = I2C0_CONCLR_I2ENC_MASK | I2C0_CONCLR_AAC_MASK;
    }
}

/*! @} */ /* end of Slave initialization and deinitialization */

/*! @name Slave status */
/*! @{ */

/*!
 * @brief Gets the I2C slave status flags.
 *
 * A bit mask with the state of all I2C control flags is returned. For each flag, the corresponding bit
 * in the return value is set if the flag is asserted.
 *
 * @param base The I2C peripheral base address.
 * @return State of the status flags:
 *         - 1: related status flag is set.
 *         - 0: related status flag is not set.
 * @see _i2c_flags
 */
static inline uint32_t I2C_SlaveGetStatusFlags(I2C0_Type *base)
{
    return I2C_MasterGetStatusFlags(base);
}

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
 *  _i2c_slave_flags enumerators OR'd together. You may pass the result of a previous call to
 *  I2C_SlaveGetStatusFlags().
 * @see _i2c_flags.
 */
static inline void I2C_SlaveClearStatusFlags(I2C0_Type *base, uint32_t statusMask)
{
    I2C_MasterClearStatusFlags(base, statusMask);
}

/*! @} */ /* end of Slave status */

/*! @name Slave bus operations */
/*! @{ */

/*!
 * @brief Performs a polling send transfer on the I2C bus.
 *
 * The function executes blocking address phase and blocking data phase.
 *
 * @param base  The I2C peripheral base address.
 * @param txBuff The pointer to the data to be transferred.
 * @param txSize The length in bytes of the data to be transferred.
 * @return kStatus_Success Data has been sent.
 * @return kStatus_Fail Unexpected slave state (master data write while master read from slave is expected).
 */
status_t I2C_SlaveWriteBlocking(I2C0_Type *base, const uint8_t *txBuff, size_t txSize);

/*!
 * @brief Performs a polling receive transfer on the I2C bus.
 *
 * The function executes blocking address phase and blocking data phase.
 *
 * @param base  The I2C peripheral base address.
 * @param rxBuff The pointer to the data to be transferred.
 * @param rxSize The length in bytes of the data to be transferred.
 * @return kStatus_Success Data has been received.
 * @return kStatus_Fail Unexpected slave state (master data read while master write to slave is expected).
 */
status_t I2C_SlaveReadBlocking(I2C0_Type *base, uint8_t *rxBuff, size_t rxSize);

/*! @} */ /* end of Slave bus operations */

/*! @name Slave non-blocking */
/*! @{ */

/*!
 * @brief Creates a new handle for the I2C slave non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I2C_SlaveTransferAbort() API shall be called.
 *
 * @param base The I2C peripheral base address.
 * @param[out] handle Pointer to the I2C slave driver handle.
 * @param callback User provided pointer to the asynchronous callback function.
 * @param userData User provided pointer to the application callback data.
 */
void I2C_SlaveTransferCreateHandle(I2C0_Type *base,
                                   i2c_slave_handle_t *handle,
                                   i2c_slave_transfer_callback_t callback,
                                   void *userData);

/*!
 * @brief Starts accepting slave transfers.
 *
 * Call this API after calling I2C_SlaveInit() and I2C_SlaveTransferCreateHandle() to start processing
 * transactions driven by an I2C master. The slave monitors the I2C bus and pass events to the
 * callback that was passed into the call to I2C_SlaveTransferCreateHandle(). The callback is always invoked
 * from the interrupt context.
 *
 * If no slave Tx transfer is busy, a master read from slave request invokes #kI2C_SlaveTransmitEvent callback.
 * If no slave Rx transfer is busy, a master write to slave request invokes #kI2C_SlaveReceiveEvent callback.
 *
 * The set of events received by the callback is customizable. To do so, set the @a eventMask parameter to
 * the OR'd combination of #i2c_slave_transfer_event_t enumerators for the events you wish to receive.
 * The #kI2C_SlaveTransmitEvent and #kI2C_SlaveReceiveEvent events are always enabled and do not need
 * to be included in the mask. Alternatively, you can pass 0 to get a default set of only the transmit and
 * receive events that are always enabled. In addition, the #kI2C_SlaveAllEvents constant is provided as
 * a convenient way to enable all events.
 *
 * @param base The I2C peripheral base address.
 * @param handle Pointer to i2c_slave_handle_t structure which stores the transfer state.
 * @param eventMask Bit mask formed by OR'ing together #i2c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. Other accepted values are 0 to get a default set of
 *      only the transmit and receive events, and #kI2C_SlaveAllEvents to enable all events.
 *
 * @retval kStatus_Success Slave transfers were successfully started.
 * @retval #kStatus_I2C_Busy Slave transfers have already been started on this handle.
 */
status_t I2C_SlaveTransferNonBlocking(I2C0_Type *base, i2c_slave_handle_t *handle, uint32_t eventMask);

/*!
 * @brief Aborts the slave non-blocking transfers.
 * @note This API could be called at any time to stop slave for handling the bus events.
 * @param base The I2C peripheral base address.
 * @param handle Pointer to i2c_slave_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferAbort(I2C0_Type *base, i2c_slave_handle_t *handle);

/*!
 * @brief Gets the slave transfer remaining bytes during a interrupt non-blocking transfer.
 *
 * @param base I2C base pointer.
 * @param handle pointer to i2c_slave_handle_t structure.
 * @param count Number of bytes transferred so far by the non-blocking transaction.
 * @retval kStatus_InvalidArgument count is Invalid.
 * @retval kStatus_Success Successfully return the count.
 */
status_t I2C_SlaveTransferGetCount(I2C0_Type *base, i2c_slave_handle_t *handle, size_t *count);

/*! @} */ /* end of Slave non-blocking */

/*! @name Slave IRQ handler */
/*! @{ */

/*!
 * @brief Reusable routine to handle slave interrupts.
 * @note This function does not need to be called unless you are reimplementing the
 *  non blocking API's interrupt handler routines to add special functionality.
 * @param base The I2C peripheral base address.
 * @param i2cHandle Pointer to i2c_slave_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferHandleIRQ(I2C0_Type *base, void *i2cHandle);

/*! @} */ /* end of Slave IRQ handler */

/*! @} */ /* end of i2c_slave_driver */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_I2C_H_ */
