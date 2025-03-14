/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_I2C_H_
#define FSL_I2C_H_

#include "fsl_common.h"

/*!
 * @defgroup i2c I2C: Inter-Integrated Circuit Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief I2C driver version. */
#define FSL_I2C_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * I2C peripheral driver change log
 ******************************************************************************/
/*!
 * @defgroup i2c_driver_log The Driver Change Log
 * @ingroup i2c
 * @{
 * The current I2C driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup i2c_intro I2C Peripheral and Driver Overview
 * @ingroup i2c
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral feature and how this peripheral works
 * =================================================
 * The inter-integrated circuit(I2C) module provides a method of communication between a number of devices.
 *
 * Features
 * --------------------------
 *   + Protocol level support
 *      - Compatible with The I2C-Bus Specification
 *      - Support for System Management Bus (SMBus) Specification, version 2
 *   + Multiple power modes
 *      - Run mode, basic operation mode
 *      - Wait mode, the module continues to operate when the core is in wait mode and can generate wakeup interrupt
 *      - Stop mode, the module is inactive in stop mode with low power consumption, its registers remain unchanged
 *        unless stop mode wakeup on slave address match is enabled and address match happens which waking up MCU
 *   + Support bus events generation and bus events detection with interrupt signals
 *      - Bus busy/idle detection
 *      - One byte transfer finish detection
 *      - Acknowledge bit generation and detection
 *      - START and STOP signal generation for master mode, detection for slave mode
 *      - Repeated START signal generation for master mode, detection for slave mode
 *      - Arbitration lost detection for master mode
 *      - Address match, general call and alert response detection for slave mode
 *   + Master operation
 *      - If more than one master try to control I2C bus at the same time, clock synchronization procedure determines
 *        the clock frequency on SCL, data arbitration procedure on SDA determines masters' relative priority
 *      - When arbitration lost happens during addressing, I2C module will switch to slave mode.
 *   + Slave operation
 *      - Flexible slave addressing mode, including 7-bit address, 10-bit address, secondary address and range address
 *        match
 *      - Low power mode wakeup on slave address match
 *      - General call listening
 *      - Alert address listening for SMBus operation
 *   + Software programmable features
 *      - Software controlled ACK bit
 *      - For I2C master mode, support up to 192 clock rate divider
 *      - For I2C slave mode, support up to 192 SDA hold time and SCL start/stop hold time setting
 *      - Programmable input glitch filter. Support up to 15 module clock cycles of signal glitch filter
 *      - Optional high drive capacity of I2C pads
 *      - Support holding off the enter to stop mode untll data transfer finishes on certain platforms
 *      - Optional double buffer mode which disables the clock strech for high-speed mode on certain platforms
 *   + DMA support
 *
 * How this peripheral works
 * -------------------------
 * Once I2C module configuration is finished, and its clock is ungated, the I2C module is ready to initiate I2C transfer
 * on bus as master or process bus events as slave.
 *
 * When MCU is in stop mode, if a primary/range/general call address match occurs, and also the I2C module's low power
 * wakeup is enabled, the 'addressed as slave' interrupt will be generated that wakes up the MCU.
 *
 * How this driver is designed to make this peripheral works
 * =========================================================
 * On abstraction level, the I2C driver provides 2 parallel layers for different users with different requirements on
 * flexibility: Functional layer and Transactional layer. Do not mix the usage of these 2 layers.
 *  + Functional Layer is provided with highly optimized implementation and highly flexible usage of the peripheral
 *    features. All hardware features' configuration are supported. It requires user to have decent understanding of the
 *    hardware detail to know how to organize these functional APIs together to meet application requirement.
 *  + Transactional layer is provided with high abstraction, limited flexibility/optimization, and not all features are
 *    covered. Their aim is to let user implement I2C transaction with least knowledge requirement of this specific I2C
 *    peripheral and least coding effort. It achieves this goal by hiddening the setup of interrupt processing inside
 *    driver and implementing complete software state machine for I2C transaction.
 * To distinguish Transactional layer from Functional layer easily, all Transactional APIs have 'Transfer' in API name.
 *
 * Functional Layer
 * ----------------
 * + Preface
 *   - Design purpose
 *       To provide various peripheral configuration and bus operation interfaces, covering all hardware features. Users
 *       can customize their code freely with functional APIs, especially when application has critical requirements of
 *       code size and performance.
 *   - Advantages:
 *       + Functional APIs are simple and optimized, with proper usage user can customize their code to be highly
 *         optimized
 *   - Disadvantages:
 *       + It requires user to have deep understanding of peripheral features, in order to organize functional APIs to
 *         meet the application requirements
 *       + The functional APIs that each driver provides are peripheral specific, which adds the work load porting
 *         application to another platform
 *
 * + Sub API Groups
 *   - Module Init/Deinit Sub-group
 *       + Provide interfaces to initialize I2C module.
 *         @note For peripherals whose operations can be classified as master or slave, 3 Init APIs are provided. For
 *         use cases when I2C only operates as either master or slave, out of consideration of decreasing code size and
 *         better execution efficiency, user can call either @ref I2C_MasterInit or @ref I2C_SlaveInit to only configure
 *         master/slave related features. Otherwise, call @ref I2C_Init to configure all features.
 *       + Structure list
 *           - @ref i2c_config_t covers all I2C features' configuration
 *           - @ref i2c_master_config_t covers only master related features' configuration
 *           - @ref i2c_slave_config_t covers only slave related features' configuration
 *   - Hardware Status Flags Sub-group
 *       + Provide interfaces to get and clear hardware status flags, such as address match flag, interrupt pending flag
 *       + Enumeration list
 *           -@ref _i2c_status_flags covers all I2C hardware status
 *   - Interrupt Sub-group
 *       + Provide interfaces to enable, disable or get the enabled interrupt source, such as start detect interrupt.
 *   - Peripheral Configuration Sub-group
 *       + Common Peripheral configuration: Provide interfaces to configure I2C peripheral hardware features used in
 *            both master and slave operation, such as high drive, stop hold.
 *       + Master Peripheral configuration: Provide interfaces to configure I2C peripheral hardware features used only
 *            in master operation, such as baudrate configuration.
 *       + Slave Peripheral configuration: Provide interfaces to configure I2C peripheral hardware features used only in
 *            slave operation, such as low power wake up.
 *   - Bus Operation Sub-group
 *       + Common Bus Operation: Provide interfaces to execute bus operations applied in both master and slave mode,
 *            such send an ACK signal.
 *       + Master Bus Operation: Provide interfaces to execute master bus operations, such as send a start/stop.
 *       + Slave Bus Operation: Provide interfaces to execute slave operations, such as send a piece of data after
 *            address matched.
 *
 * Transactional Layer
 * -------------------
 * + Preface
 *   - Design purpose
 *       To let user set up and carry out transfer quickly from the begining without worring about detailed hardware
 *       features and software operations. After transactional APIs are called, the whole transfer process is handled by
 *       driver internally without further operation from user until transfer ends.
 *   - Advantages:
 *       + User can perform transfer with these APIs without peripheral specific knowledge
 *       + They are totally state retained, all bus operations and configurations are handled inside the driver which
 *         simplifies the user application code
 *       + Transactional APIs use common programming model, different peripherals of same bus protocol have same usage
 *         on application level. This makes code integration and porting simplier
 *   - Disadvantages:
 *       + Transactional APIs are based on common programming model of I2C protocol, they are of little peripheral
 *         specific so they have average optimization on performance and code size
 *       + Transactional APIs is provided with high abstraction with limited flexibility/optimization, so not all
 *         features are covered. For instance, 10-bit addressing mode is not supported
 *
 * + Software Implementation Logic
 *   - Double Weak Mechanism
 *     One of the key features of Transactional layer compared to Functional layer is user need not setup interrupt
 *     handling codes, but can still get IRQ service function executed when interrupt happens. This is achieved by the
 *     'double weak' mechanism. Refer to the general section of API Reference Manual for detail.
 *     In breif, SDK place a weak function A for this peripheral's vector entry. The default implementation of this
 *     function calls another weak function B. By default, when a interrupt happen, the code will be executed as
 *     A (Weak) -> B (Weak). This driver implements the function B as non-weak inside, thus once user gets the driver
 *     file into the application project, when interrupt happens, code will be executed as
 *     A (Weak) -> B (Non-Weak, in this driver). If user wants to implement his/her own IRQ service routine, just define
 *     A in application as non-weak.
 *   - Transfer handle
 *     In transactional layer, transfer handle(defined as @ref i2c_master_transfer_handle_t for master and defined as
 *     @ref i2c_slave_transfer_handle_t for slave)is used to represent the instance. It contains not only the instance’s
 *     base pointer and user callback, but also the configuration for the transfer and transfer context. So each time
 *     when entering the ISR, the program would know what to do according to last transfer state stored in the handle.
 *     Transactional layer is state retained thus user should not try to modify its member in application level. User
 *     need to initialize the handle before initiating any transfer by calling @ref I2C_MasterTransferCreateHandle or
 *     @ref I2C_SlaveTransferCreateHandle.
 *     Due to the handle’s special role for transactional layer, after user allocates the transfer handle and installs
 *     it using create handle API, user should maintain the handle’s memory section so it is active during the I2C’s
 *     life cycle.
 *   - User callback and Transfer Handling Framework
 *     The Transactional Layer's IRQ service routine is hidden inside the driver, but user can still insert his/her own
 *     processing logic inside IRQ service using callback. User can code his/her own logic inside the callback function
 *     and register it into the transfer handle when calling @ref I2C_MasterTransferCreateHandle or
 *     @ref I2C_SlaveTransferCreateHandle.
 *       + Master transfer.
 *         I2C master initiates and controls the I2C transfer on bus, so the Transactional layer helps user to do a full
 *         transaction using a strict software transfer state machine. The transfer state is maintained by transfer
 *         handle to indicate which state the transfer is at. During the transfer the bus event is driven by master
 *         itself so all hardware status and bus events are handled internally without user's involvement. Only when the
 *         transfer finishes the callback is invoked.
 *       + Slave transfer. I2C slave monitors the I2C bus events, so unlike the master transfer logic, the Transactional
 *         layer helps user to do transaction in reactions to the detected bus event. Only a loose transfer state is
 *         maintained by transfer handle to indicate whether the bus is idle. A event-driven framework is implemented
 *         meaning callback is invoked to expose the event to user anytime a bus event is detected. User is expected to
 *         get involved in the transfer using call back, by deciding the following steps in reaction to the event.
 *
 * + Sub API Groups
 *   - Master Transfer Sub-group
 *       Provide interaces to initiate an I2C transfer as master, in polling way or interrupt way. They all have same
 *       Prefix 'I2C_MasterTransfer'
 *       + API list
 *         Polling transfer: @ref I2C_MasterTransferBlocking
 *         Interrupt transfer: @ref I2C_MasterTransferCreateHandle @ref I2C_MasterTransferNonBlocking
 *                             @ref I2C_MasterTransferGetCount     @ref I2C_MasterTransferAbort
 *       + Structure list
 *           - @ref i2c_master_transfer_t covers master transfer configuration
 *           - @ref i2c_master_transfer_handle_t defines the sturcture of the handle that stores the state, result,
 *                  configuration etc only for master interrupt transfer. Driver use this handle internaly to control
 *                  master's interrupt transfer process, thus it shall be read-only for user application.
 *   - Slave Transfer Sub-group
 *       Provide interaces to set I2C ready to monitor and handle any bus events as slave. Unlike master, as slave I2C
 *       must be ready to detect bus events at any time, we only provide I2C transfer in interrupt way as slave. They
 *       all have same prefix 'I2C_SlaveTransfer'
 *       + API list
 *         Interrupt transfer: @ref I2C_SlaveTransferCreateHandle @ref I2C_SlaveTransferNonBlocking
 *                             @ref I2C_SlaveTransferGetCount     @ref I2C_SlaveTransferAbort
 *       + Structure/Enumeration list
 *           - @ref i2c_slave_transfer_t covers slave transfer configuration
 *           - @ref i2c_slave_transfer_handle_t defines the stureture of the handle that stores slave transfer's state,
 *                  results, configuration etc. Same as master, the handle shall be read-only for user application.
 *           - @ref i2c_slave_transfer_event_t covers all bus events that I2C may encounter working as slave
 *
 * How to use this driver
 * ======================
 * API Return Types
 * ----------------
 * APIs with non-void return have 3 return types: uint8_t/uint32_t, bool and status_t. All APIs that issue bus event
 * during execution, including Functional APIs from Bus Operation Sub-group and all transactional APIs, all use status_t
 * as their return type. The return tells user the bus's current status as the result of API's execution.
 *
 * General Control Macro
 * ---------------------
 * + FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL
 *     SDK genneral Macro, controls whether to ungate/gate peripheral's clock source inside driver. Set it to none-zero
 *     value then driver will not ungate/gate clock source during initialization/de-initialization.
 * + I2C_RETRY_TIMES
 *     I2C specific Macro, controls the retry times when checking the module's status flags. During I2C transfer, at
 *     certain stages program needs to wait for some flag to be set/cleared then folowing steps can proceed. Set it to
 *     non-zero value then driver retries the check I2C_RETRY_TIMES. If it counts down to zero but the flag remains
 *     unchanged, API returns kStatus_I2C_Timeout. Set it to zero then the driver keeps waiting until the flag changes.
 * + I2C_SMBUS_ENABLE
 *     I2C specific Macro, controls whether to use this driver in SMBus mode. Set it to zero if user wish to use driver
 *     for simple I2C transfer.
 * + I2C_MASTER_FACK_CONTROL
 *     I2C specific Macro, controls whether to enable FACK feature in simple I2C transfer. For MCUs whose I2C has double
 *     buffer support and its double buffer is enabled, set it to non-zero value can lower the transfer speed by clock
 *     stretch.
 *
 * Configuration Items Before Calling I2C Driver APIs
 * --------------------------------------------------
 *  + Mux the I2C SDA/SCL signals to on-board pins, and configure them with expected feature.
 *  + Select and attach proper clock source to I2C module.
 *  + Ungate the I2C clock if user wish to do it outside driver by setting FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL to
 *    non-zero value.
 *  + If user wish to use interrupt for I2C transfer while other modules' interrupt sources are also enabled, set proper
 *    interrupt priority before initiating I2C transfer, so that I2C IRQ service can be properly executed.
 *
 * Functional layer usage model
 * ----------------------------
 *  - Configuration Items Before Calling Driver APIs
 *      + Except the items described in the general part, define the I2C interrupt entry in the application code
 *        if interrupt is needed for this peripheral usage.
 *  - Call flow
 *      + Init the module with @ref I2C_MasterInit or @ref I2C_SlaveInit. Note @ref I2C_MasterGetDefaultConfig or
 *        @ref I2C_SlaveGetDefaultConfig can help user to get a ready-to-use init data structure.
 *      + Do the I2C transaction with other functional layer APIs
 *
 * Transactional layer usage model
 * ------------------------------
 *  - Call flow for polling master transfer
 *      + Init the module
 *      + Do the transfer with @ref I2C_MasterTransferBlocking
 *  - Call flow for interrupt transfer
 *      + Master
 *          - Init the module
 *          - Init the handle with @ref I2C_MasterTransferCreateHandle
 *          - Initiate I2C transfer with @ref I2C_MasterTransferNonBlocking
 *          - During active transfer
 *              + User can query how many data are transferred by @ref I2C_MasterTransferGetCount
 *              + User can abort transaction @ref I2C_MasterTransferAbort
 *      + Slave
 *          - Init the module
 *          - Init the handle with @ref I2C_SlaveTransferCreateHandle
 *          - Set I2C ready to process I2C event with @ref I2C_SlaveTransferNonBlocking
 *          - During active transfer
 *              + User can query how many data are transferred by @ref I2C_SlaveTransferGetCount
 *              + User can abort transaction @ref I2C_SlaveTransferAbort
 *
 * Typical Use Cases
 * =================
 * These code snipets shows the general calling sequence to use functional APIs and transactional APIs. For detail usage
 * on appilcation level, refer to I2C driver examples in SDK package under boards/\<board_name\>/driver_examples/i2c.
 *
 * + Functional APIs
 *   @code
 *      // Module initialization
 *      i2c_config_t sConfig;
 *      I2C_GetDefaultConfig(&sConfig, 0x2AU, 12000000U);
 *      I2C_Init(I2C0, &sConfig);
 *
 *      // Transmit data as master
 *      uint8_t master_txData[3] = {1,2,3};
 *      while (0U != (I2C_MasterGetStatusFlags(I2C0) & (uint32_t)kI2C_BusBusyFlag));
 *      I2C_MasterStart(I2C0, 0x7EU, kI2C_MasterReceive);
 *      while (0U == (I2C_MasterGetStatusFlags(I2C0) & (uint32_t)kI2C_InterruptPendingFlag));
 *      if (0U == (I2C_MasterGetStatusFlags(I2C0) & (uint32_t)(kI2C_ArbitrationLostInterruptFlag |
 * kI2C_ReceiveNakFlag)))
 *      {
 *          result = I2C_MasterWriteBlocking(I2C0, master_txData, 3U, kI2C_TransferStartStopFlag);
 *      }
 *      else
 *      {
 *          I2C_MasterClearStatusFlags(I2C0, (uint32_t)(kI2C_ArbitrationLostInterruptFlag | kI2C_ReceiveNakFlag));
 *      }
 *
 *      // Receive data as slave
 *      uint8_t slave_rxData[3] = {};
 *      status = I2C_SlaveReadBlocking(I2C0, slave_rxData, 3);
 *   @endcode
 *
 * + Transactional APIs
 *     - Master transfer
 *     @code
 *        // Module initialization
 *        i2c_master_config_t sConfig;
 *        I2C_MasterGetDefaultConfig(&sConfig, 12000000U);
 *        I2C_MasterInit(I2C0, &sConfig);
 *
 *        // Set up master transfer configuration
 *        uint8_t master_txBuff[32];
 *        i2c_master_transfer_t sMasterTransfer;
 *        sMasterTransfer.u8SlaveAddress    = 0x7EU;
 *        sMasterTransfer.eDirection        = kI2C_MasterTransmit;
 *        sMasterTransfer.u32Command        = NULL;
 *        sMasterTransfer.u8CommandSize     = 0;
 *        sMasterTransfer.pu8Data           = master_txBuff;
 *        sMasterTransfer.dataSize          = 32;
 *        sMasterTransfer.u8ControlFlagMask = kI2C_TransferStartStopFlag;
 *
 *        // Master polling transfer
 *        I2C_MasterTransferBlocking(I2C0, &sMasterTransfer);
 *
 *        // Master interrupt transfer
 *        i2c_master_transfer_handle_t master_handle;
 *        I2C_MasterTransferCreateHandle(I2C0, &master_handle, i2c_master_callback, NULL);
 *        I2C_MasterTransferNonBlocking(&master_handle, &sMasterTransfer);
 *     @endcode
 *
 *     - Slave transfer
 *     @code
 *        // Module initialization
 *        i2c_slave_config_t sConfig;
 *        I2C_SlaveGetDefaultConfig(&sConfig, 0x2AU, 12000000U);
 *        I2C_SlaveInit(I2C0, &sConfig);
 *
 *        // Set up slave transfer configuration
 *        uint8_t slave_Buff[32];
 *        i2c_slave_transfer_t sSlaveTransfer;
 *        sSlaveTransfer.pu8Data     = slave_Buff;
 *        sSlaveTransfer.dataSize    = 32;
 *        sSlaveTransfer.u8EventMask = kI2C_SlaveOutofTransmitDataEvent | kI2C_SlaveOutofReceiveSpaceEvent |
 * kI2C_SlaveGenaralcallEvent;
 *
 *        // Slave interrupt transfer
 *        i2c_slave_transfer_handle_t slave_handle;
 *        I2C_SlaveTransferCreateHandle(I2C0, &slave_handle, i2c_slave_callback, NULL);
 *        I2C_SlaveTransferNonBlocking(&slave_handle, &sSlaveTransfer);
 *     @endcode
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if (defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT || \
     defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT)
#define I2C_HAS_STOP_DETECT
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT / FSL_FEATURE_I2C_HAS_STOP_DETECT */

/* ============================================= General Control Macro ============================================== */
/*! @brief Retry times when checking status flags. */
#ifndef I2C_RETRY_TIMES
#define I2C_RETRY_TIMES 0U /* Default defines to zero, driver keeps checking status flag untill it changes. */
#endif

/*! @brief Control whether to use SMBus featues. */
#ifndef I2C_SMBUS_ENABLE
#define I2C_SMBUS_ENABLE 0U /* Default defines to zero, driver uses simple I2C transfer. */
#endif

/*!
 * @brief Control whether to enable FACK for master read operation in non SMBus tranfer. This is used to lower transfer
 * speed by clock stretch for MCU with FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING supported and enabled.
 */
#ifndef I2C_MASTER_FACK_CONTROL
#define I2C_MASTER_FACK_CONTROL 0U /* Default defines to zero means master will send ack automatically. */
#endif

/* ================================================ Callback Macro ================================================== */
#define I2C_GET_TRANSFER_COMPLETION_STATUS(psHandle) (psHandle)->completionStatus
#define I2C_GET_TRANSFER_USER_DATA(psHandle)         (psHandle)->pUserData

#define I2C_GET_SLAVE_TRANSFER_EVENT(psHandle)        (psHandle)->sTransfer.eEvent
#define I2C_GET_SLAVE_TRANSFER_DATA_POINTER(psHandle) (psHandle)->sTransfer.pu8Data
#define I2C_GET_SLAVE_TRANSFER_DATASIZE(psHandle)     (psHandle)->sTransfer.u16DataSize
#define I2C_GET_SLAVE_TRANSFERRED_COUNT(psHandle)     (psHandle)->u16TransferredCount
/* ========================================== End of General Control Macro ========================================== */

/*!
 * @brief I2C API status codes, used by bus operation APIs and transactional APIs as return value to indicate the bus's
 * current status as the API's execution result, or used in the callback to indicate transfer results.
 */
enum
{
    kStatus_I2C_Busy = MAKE_STATUS(kStatusGroup_I2C, 0), /*!< I2C bus is busy. */
    kStatus_I2C_Idle = MAKE_STATUS(kStatusGroup_I2C, 1), /*!< I2C Bus is idle. */
    kStatus_I2C_Nak  = MAKE_STATUS(kStatusGroup_I2C, 2), /*!< I2C detected NACK on bus. When in SMBus mode, this means
                                                            the receiver nacks transmitter before PEC byte. */
    kStatus_I2C_ArbitrationLost = MAKE_STATUS(kStatusGroup_I2C, 3), /*!< I2C lost arbitration during addressing. */
    kStatus_I2C_Timeout =
        MAKE_STATUS(kStatusGroup_I2C, 4), /*!< Timeout happens when waiting for status flags to change. */
    kStatus_I2C_Addr_Nak = MAKE_STATUS(kStatusGroup_I2C, 5), /*!< NACK was detected during the address probe. */
#ifdef I2C_SMBUS_ENABLE
    kStatus_I2C_Pec_Error = MAKE_STATUS(kStatusGroup_I2C, 6), /*!< Detected NACK for the PEC byte in transmit, or the
                                                                 received PEC does not match with the calculated CRC. */
#endif                                                        /* I2C_SMBUS_ENABLE */
};

/* ================================== Functional Group Structure/Enumeration List =================================== */
/* ---------------------------------------- Hardware Status Flags Sub-group ----------------------------------------- */

/*!
 * @brief I2C hardware status flags
 *
 * These enumerations can be ORed together to form bit masks. The masks can be used as parameter by
 * @ref I2C_MasterClearStatusFlags and @ref I2C_SlaveClearStatusFlags, or as return value by
 * @ref I2C_MasterGetStatusFlags and @ref I2C_SlaveGetStatusFlags.
 */
enum _i2c_status_flags
{
    kI2C_ReceiveNakFlag       = I2C_S_RXAK_MASK,  /*!< I2C reveived none ack flag */
    kI2C_InterruptPendingFlag = I2C_S_IICIF_MASK, /*!< I2C interrupt pending flag. Byte transfer complete, address
                                                     match, arbitration lost, start/stop detection and SMBus timeout can
                                                     all cause this status bit to set. This flag can be cleared. */
    kI2C_SlaveTransmitFlag = I2C_S_SRW_MASK,      /*!< I2C slave write/read status flag */
    kI2C_RangeAddressMatchInterruptFlag =
        I2C_S_RAM_MASK, /*!< Received address is within address range. This flag can be cleared. */
    kI2C_ArbitrationLostInterruptFlag = I2C_S_ARBL_MASK, /*!< This flag can be cleared. */
    kI2C_BusBusyFlag                  = I2C_S_BUSY_MASK, /*!< I2C bus busy flag. */
    kI2C_AddressAsSlaveInterruptFlag =
        I2C_S_IAAS_MASK, /*!< Addressed as slave, including general call, alert response, primary/secondary address and
                            range address match. This flag can be cleared. */
    kI2C_ByteTransferCompleteInterruptFlag = I2C_S_TCF_MASK, /*!< I2C trasfer complete flag. */
#ifdef I2C_HAS_STOP_DETECT
    kI2C_StopDetectInterruptFlag = I2C_FLT_STOPF_MASK << 8, /*!< This flag can be cleared. */
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT / FSL_FEATURE_I2C_HAS_STOP_DETECT */

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    kI2C_StartDetectInterruptFlag = I2C_FLT_STARTF_MASK << 8, /*!< This flag can be cleared. */
#endif                                                        /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

    kI2C_SclLowTimeoutFlag = I2C_SMB_SLTF_MASK << 8, /*!< I2C SCL signal low timeout flag. This flag can be cleared. */
    kI2C_BusIdleFlag = I2C_SMB_SHTF1_MASK << 8,      /*!< I2C SCL and SDA both high timeout flag indicating bus idle. */
    kI2C_SdaLowTimeoutInterruptFlag = I2C_SMB_SHTF2_MASK
                                      << 8, /*!< I2C SDA signal low timeout flag. This flag can be cleared. */
    kI2C_StatusAllFlags = (int)(
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
        kI2C_StartDetectInterruptFlag | kI2C_StopDetectInterruptFlag |
#elif defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
        kI2C_StopDetectInterruptFlag |
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT/FSL_FEATURE_I2C_HAS_STOP_DETECT */
        kI2C_InterruptPendingFlag | kI2C_RangeAddressMatchInterruptFlag | kI2C_ArbitrationLostInterruptFlag |
        kI2C_AddressAsSlaveInterruptFlag | kI2C_SclLowTimeoutFlag |
        kI2C_SdaLowTimeoutInterruptFlag), /*!< All flags which are clearable. */
};
/* -------------------------------------- End of Hardware Status Flags Sub-group ------------------------------------ */

/* ----------------------------------------------- Interrupt Sub-group ---------------------------------------------- */
/*!
 * @brief I2C interrupt enable/disable source.
 *
 * These enumerations can be ORed together to form bit masks. The masks can be used as parameter by
 * @ref I2C_EnableInterrupts, @ref I2C_DisableInterrupts, or as return value by @ref I2C_GetEnabledInterrupts.
 */
enum _i2c_interrupt_enable
{
    kI2C_GlobalInterruptEnable = I2C_C1_IICIE_MASK, /*!< I2C global interrupt. */

#if defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
    kI2C_StopDetectInterruptEnable = I2C_FLT_STOPIE_MASK, /*!< I2C stop detect interrupt. */
#endif                                                    /* FSL_FEATURE_I2C_HAS_STOP_DETECT */

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    kI2C_StartStopDetectInterruptEnable = I2C_FLT_SSIE_MASK, /*!< I2C start&stop detect interrupt. */
#endif                                                       /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

    kI2C_SdaLowTimeoutInterruptEnable = I2C_SMB_SHTF2IE_MASK, /*!< I2C SDA low timeout interrupt. */

    kI2C_AllInterruptEnable = kI2C_GlobalInterruptEnable
#if I2C_SMBUS_ENABLE
//| kI2C_SdaLowTimeoutInterruptEnable
#endif /* I2C_SMBUS_ENABLE */
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
                              | kI2C_StartStopDetectInterruptEnable
#elif defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
                              | kI2C_StopDetectInterruptEnable
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT/FSL_FEATURE_I2C_HAS_STOP_DETECT */
    ,
};
/* ------------------------------------------- End of Interrupt Sub-group ------------------------------------------- */

/* ------------------------------------------ Module Init/Deinit Sub-group ------------------------------------------ */
/*!
 * @brief I2C master configuration structure.
 *
 * This structure includes all the master operation needed features, user can configure these features one by one
 * manually, or call @ref I2C_MasterGetDefaultConfig to set the structure to default value. Then, call
 * @ref I2C_MasterInit to initialize I2C module. After initialization, the I2C module can only operate as master. To
 * deinitialize I2C, call @ref I2C_MasterDeinit.
 */
typedef struct _i2c_master_config
{
    bool bEnableModule; /*!< Enable the I2C peripheral during initialization. */

    bool bEnableHighDrive; /* Enable I2C pads high drive capability. I2C_C2_HDRS */
#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    bool bEnableDoubleBuffering; /*!< Control double buffer enable. Notice that enabling the double buffer disables
                                        the clock stretch. It is not supported in SMBus system. I2C_S2_DFEN */
#endif                           /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    bool bEnableStopHold;        /*!< Control the stop hold enable. I2C_FLT_SHEN */
#endif                           /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    uint8_t u8GlitchFilterWidth; /*!< Control the width of the glitch filter. I2C_FLT_FLT */
#if I2C_SMBUS_ENABLE
    uint16_t u16SclTimout_Ms; /* SCL high/low time out value. I2C_SMB_TCKSEL, I2C_SLTH_SSLT[8], I2C_SLTL_SSLT[8] */
#endif                        /* I2C_SMBUS_ENABLE */

    uint8_t u8Interrupts;    /*!< Mask of the interrupts to be enabled in the init function. */
    uint32_t u32BaudRateBps; /*!< Baud rate value in bits-per-second. I2C_F_MULT, I2C_F_ICR */
    uint32_t u32SrcClockHz;  /*!< The clock source frequency for I2C module. */
} i2c_master_config_t;

/*! @brief Slave addressing mode, address match or range address match. */
typedef enum _i2c_slave_address_mode
{
    kI2C_AddressMatch      = 0x0U, /*!< 7-bit addressing mode. */
    kI2C_AddressRangeMatch = 0X1U, /*!< Range address match addressing mode. */
    kI2C_AddressMatch10bit = 0X2U, /*!< 10-bit addressing mode. */
} i2c_slave_address_mode_t;

/*!
 * @brief I2C slave configuration structure.
 *
 * This structure includes all the slave operation needed features, user can configure these features one by one
 * manually, or call @ref I2C_SlaveGetDefaultConfig to set the structure to default value. Then, call
 * @ref I2C_SlaveInit to initialize I2C module. After initialization, the I2C module can only operate as slave. To
 * deinitialize I2C, call @ref I2C_SlaveDeinit.
 */
typedef struct _i2c_slave_config
{
    bool bEnableModule; /*!< Enable the I2C peripheral during initialization. */

    bool bEnableHighDrive; /* Enable I2C pads high drive capability. I2C_C2_HDRS */
#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    bool bEnableDoubleBuffering; /*!< Control double buffer enable. Notice that enabling the double buffer disables
                                        the clock stretch. It is not supported in SMBus system. I2C_S2_DFEN */
#endif                           /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    bool bEnableStopHold;        /*!< Control the stop hold enable. I2C_FLT_SHEN */
#endif                           /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    uint8_t u8GlitchFilterWidth; /*!< Control the width of the glitch filter. I2C_FLT_FLT */
#if I2C_SMBUS_ENABLE
    uint16_t u16SclTimout_Ms; /* SCL high/low time out value. I2C_SMB_TCKSEL, I2C_SLTH_SSLT[8], I2C_SLTL_SSLT[8] */
#endif                        /* I2C_SMBUS_ENABLE */

    bool bEnableWakeUp; /*!< Enable/disable waking up MCU from low-power mode. I2C_C1_WUEN */
#if !(defined(FSL_FEATURE_I2C_NO_SBRC) && FSL_FEATURE_I2C_NO_SBRC)
    bool bEnableBaudRateCtl; /*!< Enable/disable independent slave baud rate on SCL in very fast I2C modes.
                                        I2C_C2_SBRC */
#endif                       /* FSL_FEATURE_I2C_NO_SBRC */
    bool bEnableGeneralCall; /*!< Enable the general call addressing mode, not affected by address length.
                                        General call address is 0x00. I2C_C2_GCAEN */
    i2c_slave_address_mode_t
        eAddressingMode; /*!< Addressing mode chosen from @ref i2c_slave_address_mode_t. I2C_C2_ADEXT I2C_C2_RMEN */
    uint16_t bitsPrimaryAddress : 10; /*!< Primary Slave address. I2C_A1_AD[7] I2C_C2_AD[3] */
    uint16_t bitsMaxAddress : 7; /*!< The maximum boundary of slave address used in a range address match addressing. In
                                  range address match, address greater than primary address and less than or equal to
                                  upper address is marked as matched. I2C_RA_RAD[7] */
#if I2C_SMBUS_ENABLE
    bool bEnableAlertResponse;         /*!< Enable the alert response addressing mode. Alert response address is
                                                  0b0001100X. I2C_SMB_ALERTEN */
    bool bEnableSecondaryAddress;      /*!< Enable the secondary address for SMBus. I2C_SMB_SIICAEN. */
    uint16_t bitsSecondaryAddress : 7; /*!< Secondary Slave address. I2C_A2_SAD[7] */
#endif                                 /* I2C_SMBUS_ENABLE */
    uint8_t u8Interrupts;              /*!< Mask of the interrupts to be enabled in the init function. */
    uint32_t u32SclStopHoldTime_ns;    /*!< the delay from the rising edge of SCL (I2C clock) to the rising edge of SDA
                                       (I2C data) while SCL is high (stop condition), SDA hold time and SCL start hold time
                                       are also configured according to the SCL stop hold time. */
    uint32_t u32SrcClockHz;            /*!< The clock source frequency for I2C module. */
} i2c_slave_config_t;

/*!
 * @brief I2C configuration structure.
 *
 * This structure includes all I2C features, user can configure user can configure these features one by one manually,
 * or call @ref I2C_GetDefaultConfig to set the structure to default value. Then, call @ref I2C_Init to initialize I2C
 * module. To deinitialize I2C, call @ref I2C_Deinit.
 */
typedef struct _i2c_config
{
    bool bEnableModule; /*!< Enable the I2C peripheral during initialization. */

    bool bEnableHighDrive; /* Enable I2C pads high drive capability. I2C_C2_HDRS */
#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    bool bEnableDoubleBuffering; /*!< Control double buffer enable. Notice that enabling the double buffer disables
                                        the clock stretch. It is not supported in SMBus system. I2C_S2_DFEN */
#endif                           /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    bool bEnableStopHold;        /*!< Control the stop hold enable. I2C_FLT_SHEN */
#endif                           /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    uint8_t u8GlitchFilterWidth; /*!< Control the width of the glitch filter. I2C_FLT_FLT */
#if I2C_SMBUS_ENABLE
    uint16_t u16SclTimout_Ms; /* SCL high/low time out value. I2C_SMB_TCKSEL, I2C_SLTH_SSLT[8], I2C_SLTL_SSLT[8] */
#endif                        /* I2C_SMBUS_ENABLE */

    bool bEnableWakeUp; /*!< Enable/disable waking up MCU from low-power mode. I2C_C1_WUEN */
#if !(defined(FSL_FEATURE_I2C_NO_SBRC) && FSL_FEATURE_I2C_NO_SBRC)
    bool bEnableBaudRateCtl; /*!< Enable/disable independent slave baud rate on SCL in very fast I2C modes.
                                        I2C_C2_SBRC */
#endif                       /* FSL_FEATURE_I2C_NO_SBRC */
    bool bEnableGeneralCall; /*!< Enable the general call addressing mode, not affected by address length.
                                        General call address is 0x00. I2C_C2_GCAEN */
    i2c_slave_address_mode_t
        eAddressingMode; /*!< Addressing mode chosen from @ref i2c_slave_address_mode_t. I2C_C2_ADEXT I2C_C2_RMEN */
    uint16_t bitsPrimaryAddress : 10; /*!< Primary Slave address. I2C_A1_AD[7] I2C_C2_AD[3] */
    uint16_t bitsMaxAddress : 7; /*!< The maximum boundary of slave address used in a range address match addressing. In
                                  range address match, address greater than primary address and less than or equal to
                                  upper address is marked as matched. I2C_RA_RAD[7] */
#if I2C_SMBUS_ENABLE
    bool bEnableAlertResponse;         /*!< Enable the alert response addressing mode. Alert response address is
                                                  0b0001100X. I2C_SMB_ALERTEN */
    bool bEnableSecondaryAddress;      /*!< Enable the secondary address for SMBus. I2C_SMB_SIICAEN. */
    uint16_t bitsSecondaryAddress : 7; /*!< Secondary Slave address. I2C_A2_SAD[7] */
#endif                                 /* I2C_SMBUS_ENABLE */
    uint8_t u8Interrupts;              /*!< Mask of the interrupts to be enabled in the init function. */
    uint32_t u32BaudRateBps;           /*!< Baud rate value in bits-per-second. I2C_F_MULT, I2C_F_ICR */
    uint32_t u32SrcClockHz;            /*!< The clock source frequency for I2C module. */
} i2c_config_t;

/* --------------------------------------- End of Module Init/Deinit Sub-group -------------------------------------- */

/* ----------------------------------------- Module Configuration Sub-group ----------------------------------------- */
/*! @brief Peripheral data direction. */
typedef enum _i2c_data_direction
{
    kI2C_Read  = 0x0U, /*!< I2C read data from bus. */
    kI2C_Write = 0x1U, /*!< I2C write data to bus. */
} i2c_data_direction_t;
/* -------------------------------------- End of Module Configuration Sub-group ------------------------------------- */

/* ================================= Transactional Group Structure/Enumeration List  ================================ */
/* -------------------------------------------- Master Transfer Sub-group ------------------------------------------- */
/*!
 * @brief I2C master transfer control flags
 *
 * These flags can be ORed together to form bit mask. The mask is used to configure master transfer's start/stop
 * condition in i2c_master_transfer_t::u8ControlFlagMask.
 */
enum _i2c_master_transfer_control_flags
{
    kI2C_TransferStartStopFlag = 0x0U,     /*!< A transfer starts with a start signal, stops with a stop signal. */
    kI2C_TransferNoStartFlag   = 0x1U,     /*!< A transfer starts without a start signal, only support write only or
                                        write+read with no start flag, do not support read only with no start flag. */
    kI2C_TransferRepeatedStartFlag = 0x2U, /*!< A transfer starts with a repeated start signal. */
    kI2C_TransferNoStopFlag        = 0x4U, /*!< A transfer ends without a stop signal. */
};

/*! @brief Master transfer direction. */
typedef enum _i2c_master_transfer_direction
{
    kI2C_MasterTransmit = 0x0U, /*!< Master transmits data to slave. */
    kI2C_MasterReceive  = 0x1U, /*!< Master receives data from slave. */
} i2c_master_transfer_direction_t;

/*!
 * @brief I2C master transfer configuration structure.
 *
 * This structure definition includes all the user configurable features, that are used to control single I2C transfer
 * of master mode, in polling way or in interrupt way.
 */
typedef struct _i2c_master_transfer
{
    uint8_t u8ControlFlagMask; /*!< The transfer flag which controls the transfer start/stop signal, refer @ref
                          _i2c_master_transfer_flags. */
    uint8_t u8SlaveAddress;    /*!< 7-bit slave address. */
#if I2C_SMBUS_ENABLE
    uint8_t u8RetryTimes;                       /*!< The retry times when master lost arbitration during addressing. */
#endif                                          /* I2C_SMBUS_ENABLE */
    i2c_master_transfer_direction_t eDirection; /*!< Transfer direction, #kI2C_MasterTransmit or #kI2C_MasterReceive. */
    uint8_t *pu8Command;                        /*!< Pointer to command code. */
    uint8_t u8CommandSize;                      /*!< Size of the command code, max value 4. */
    uint8_t *volatile pu8Data;                  /*!< Pointer to the send/receive data buffer. */
    volatile uint16_t u16DataSize;              /*!< Transfer size. */
} i2c_master_transfer_t;

/*!
 * @brief Forward declaration of the I2C master transfer handle structure.
 * @anchor i2c_master_transfer_handle_t
 */
typedef struct _i2c_master_transfer_handle i2c_master_transfer_handle_t;

/*!
 * @brief I2C master transfer callback function definition
 *
 * Defines the interface of user callback function used in master interrupt transfer. The callback function shall be
 * defined and declared in application level by user. Before starting master transfer by calling
 * @ref I2C_MasterTransferNonBlocking, call @ref I2C_MasterTransferCreateHandle to install the user callback. When
 * master transfer ends successfully or failed due to any event like arbitration lost or nacked by slave, user callback
 * will be invoked by driver. And then user can decide what to do next in the callback according to its parameter
 * completionStatus which indicates how the transfer ends.
 *
 * @param psHandle I2C transfer handle, which contains the information of base pointer, completionStatus and user data.
 */
typedef void (*i2c_master_transfer_callback_t)(i2c_master_transfer_handle_t *psHandle);

/*!
 * @brief I2C master transfer handle
 *
 * @note If user wants to use the transactional API to transfer data in interrupt way in master mode, one I2C instance
 * should and can only be allocated one master handle.
 * @note The handle is maintained by I2C driver internally, which means the transfer state is retained and user shall
 * not modify its state #u8State in application level. If user only wish to use transactional APIs without understanding
 * its machanism, it is not necessary to understand these members.
 */
struct _i2c_master_transfer_handle
{
    I2C_Type *base;                  /*!< I2C base pointer to the I2C instance that assigned to this handle. */
    i2c_master_transfer_t sTransfer; /*!< I2C master transfer structure. */
    uint16_t u16TransferSize;        /*!< Total bytes to be transferred. */
    uint8_t u8State;                 /*!< A transfer state maintained during transfer. */
    i2c_master_transfer_callback_t
        pfCompletionCallback;  /*!< Callback function invoked when the transfer is finished. */
    status_t completionStatus; /*!< I2C master transfer complete status, indicating how the transfer ends. */
    void *pUserData; /*!< User configurable pointer to any data, function, structure etc that user wish to use in the
                        callback */
};
/* ----------------------------------------- End of Master Transfer Sub-group --------------------------------------- */

/* --------------------------------------------- Slave Transfer Sub-group ------------------------------------------- */
/*!
 * @brief Set of slave transfer events.
 *
 * This enumeration lists all the protocol level events that may happen during slave transfer. They can be used for two
 * related purposes:
 *  1. User can select certain events and combined them by OR operation to form a mask, and use the mask to configure
 * slave transfer configuration stucture i2c_slave_transfer_t::u8EventMask. If any of these selected events happens,
 * driver will alert user by invoking callback.
 *  2. When slave callback is invoked, user has to know which specific event occured. Callback uses slave transfer
 * configuration structure i2c_slave_transfer_t as 2nd parameter, its member i2c_slave_transfer_t::eEvent shows which
 * event just happened.
 */
typedef enum _i2c_slave_transfer_event
{
    kI2C_SlaveAddressMatchEvent =
        0x01U, /*!< Slave detects general call or alert response address, or primary/secondary/range address is matched
                  after a start or repeated start. */
    kI2C_SlaveOutofTransmitDataEvent = 0x02U, /*!< Slave runs out of data to transmit, request a new data buffer. */
    kI2C_SlaveOutofReceiveSpaceEvent =
        0x04U, /*!< Slave runs out of space to store received data, request a new data buffer. */
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    kI2C_SlaveStartEvent = 0x08U, /*!< A start/repeated start was detected. */
#endif                            /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */
    kI2C_SlaveCompletionEvent =
        0x10U, /*!< Slave detects a stop signal, or slave is nacked by master during master-receive,
                or slave has finished transmit/receive previously configured amount of data. */
    kI2C_SlaveGenaralcallEvent = 0x20U, /*!< Received the general call address after a start or repeated start. */
#if I2C_SMBUS_ENABLE
    kI2C_SlaveAlertResponseEvent = 0x40U, /*!< Received the alert response address after a start or repeated start. */
#endif                                    /* I2C_SMBUS_ENABLE */
    /*! A bit mask of all available events. */
    kI2C_SlaveAllEvents = kI2C_SlaveAddressMatchEvent | kI2C_SlaveOutofTransmitDataEvent |
                          kI2C_SlaveOutofReceiveSpaceEvent
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
                          | kI2C_SlaveStartEvent
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */
                          | kI2C_SlaveCompletionEvent | kI2C_SlaveGenaralcallEvent
#if I2C_SMBUS_ENABLE
                          | kI2C_SlaveAlertResponseEvent
#endif /* I2C_SMBUS_ENABLE */

    ,
} i2c_slave_transfer_event_t;

/*!
 * @brief I2C slave transfer configuration structure.
 *
 * Covers slave transfer data buffer pointer, data size and the events user want driver to alert.
 * @note Unlike master who controls the transfer flow, slave has to monitor any bus event and change its configuration
 * accordingly. So this slave transfer configuration structure is also used as second parameter of callback, for user
 * to change the transfer configuration in the callback. The read-only member eEvent shows which event occured that
 * causes the callback being invoked.
 */
typedef struct _i2c_slave_transfer
{
    uint8_t u8EventMask; /*!< Mask of the events. When these enents occur during transfer driver will alert user using
                            callback. */
    uint8_t *volatile pu8Data;         /*!< Pointer to the buffer of data to send, or to store received data. */
    volatile uint16_t u16DataSize;     /*!< Transfer size. */
    i2c_slave_transfer_event_t eEvent; /*!< The event that caused the callback being invoked. Read-only. */
} i2c_slave_transfer_t;

/*!
 * @brief Forward declaration of the I2C slave transfer handle structure.
 * @anchor i2c_slave_transfer_handle_t
 */
typedef struct _i2c_slave_transfer_handle i2c_slave_transfer_handle_t;

/*!
 * @brief I2C slave transfer callback function definition
 *
 * Defines the interface of slave user callback function. The callback function shall be defined and declared in
 * application level by user. Before calling @ref I2C_SlaveTransferNonBlocking to let I2C slave ready to process bus
 * events, call @ref I2C_SlaveTransferCreateHandle first to install the user callback to slave handle. When I2C slave
 * meets user selected events, callback will be invoked and user can decide the following steps in the callback.
 * All the events that can trigger callback are listed in #i2c_slave_transfer_event_t.
 *
 * @param psHandle I2C transfer handle, which contains the information of base pointer, completionStatus transfer data,
 * data length and user data.
 */
typedef void (*i2c_slave_transfer_callback_t)(i2c_slave_transfer_handle_t *psHandle);

/*!
 * @brief I2C slave transfer handle
 *
 * @note If user wants to use the transactional API to transfer data in slave mode, one I2C instance should and can only
 * be allocated one handle.
 * @note The handle is maintained by I2C driver internally, which means the transfer state is retained and user shall
 * not modify its state #u8State in application level. If user only wish to use transactional APIs without understanding
 * its machanism, it is not necessary to understand these members.
 */
struct _i2c_slave_transfer_handle
{
    I2C_Type *base;                           /*!< I2C base pointer to the I2C instance that assigned to this handle. */
    i2c_slave_transfer_t sTransfer;           /*!< I2C slave transfer structure. */
    uint16_t u16TransferredCount;             /*!< The number of bytes actually transferred for curent data buffer. */
    uint8_t u8State;                          /*!< A transfer state maintained during transfer. */
    i2c_slave_transfer_callback_t pfCallback; /*!< Callback function invoked at the transfer event. */
    status_t completionStatus; /*!< I2C slave transfer complete status, indicating how the transfer ends, such as
    #kStatus_I2C_Nak indicates the slave was nacked by master before all the data was sent. This parameter is only
    useful when eEvent is #kI2C_SlaveCompletionEvent. */
    void *pUserData; /*!< User configurable pointer to any data, function, structure etc that user wish to use in the
                        callback. */
};
/* --------------------------------------------- Slave Transfer Sub-group ------------------------------------------- */
/* ========================================= End of Transactional API Group ======================================== */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus. */

/* =========================================== Functional Group API List ============================================ */
/*!
 * @name Module Init/Deinit Sub-group
 * @{
 */
/*!
 * @brief Sets the I2C master configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref I2C_MasterInit to use.
 * Use the unchanged structure in @ref I2C_MasterInit or modify the structure before calling @ref I2C_MasterInit.
 * This is an example:
 * @code
 *   i2c_master_config_t config;
 *   I2C_MasterGetDefaultConfig(&config, 12000000U);
 *   config.u32BaudRateBps = 100000;
 *   I2C_MasterInit(I2C0, &config);
 * @endcode
 *
 * @param psMasterConfig Pointer to the master configuration structure.
 * @param u32SrcClockHz The clock source frequency for I2C module.
 */
void I2C_MasterGetDefaultConfig(i2c_master_config_t *psMasterConfig, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the I2C peripheral to operate as master.
 *
 * This API initialize the I2C module for master operation, including the feature configuration of high drive capacity,
 * doubble buffer, glitch filter, SCL timeout value, stop hold off enable and transfer baudrate. User can also configure
 * whether to enable the module in the function.
 *
 * @note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enbaled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the API
 *
 * The configuration structure can be filled manully or be set with default values by calling
 * @ref I2C_MasterGetDefaultConfig. This is an example.
 * @code
 *   I2C_MasterGetDefaultConfig(&config, 12000000U);
 *   I2C_MasterInit(I2C0, &config);
 * @endcode
 *
 * @param base I2C base pointer
 * @param psMasterConfig Pointer to the master configuration structure
 */
void I2C_MasterInit(I2C_Type *base, const i2c_master_config_t *psMasterConfig);

/*!
 * @brief De-initializes the I2C peripheral. Call this API to disable the I2C module.
 *
 * @param base I2C base pointer
 */
void I2C_MasterDeinit(I2C_Type *base);

/*!
 * @brief Sets the I2C slave configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure for @ref I2C_SlaveInit to use. Use the unchanged
 * initialized structure in @ref I2C_SlaveInit or modify the structure before calling @ref I2C_SlaveInit.
 * This is an example.
 * @code
 *   i2c_slave_config_t config;
 *   I2C_SlaveGetDefaultConfig(&config, 0x23U, 12000000U);
 * @endcode
 *
 * @param psSlaveConfig Pointer to the slave configuration structure.
 * @param u16PrimaryAddress For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * @param u32SrcClockHz The clock source frequency for I2C module.
 */
void I2C_SlaveGetDefaultConfig(i2c_slave_config_t *psSlaveConfig, uint16_t u16PrimaryAddress, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the I2C peripheral to operate as slave.
 *
 * This API initialize the I2C module for slave operation, including the feature configuration of high drive capacity,
 * doubble buffer, glitch filter, SCL timeout value, stop hold off enable, addressing mode, alert response/general call
 * minitoring, auto baudrate control, low power mode wake up, SCL/SDA setup and hold time. User can also configure
 * whether to enable the module in the function.
 *
 * @note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enbaled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the API
 *
 * The configuration structure can be filled manully or be set with default values by calling
 * @ref I2C_SlaveGetDefaultConfig. This is an example.
 * @code
 *    i2c_slave_config_t sConfig;
 *    I2C_SlaveGetDefaultConfig(&sConfig, 12000000U);
 *    sConfig.u8PrimaryAddress = 0x2AU;
 *    I2C_SlaveInit(I2C0, &sConfig);
 * @endcode
 *
 * @param base I2C base pointer
 * @param psSlaveConfig Pointer to the slave configuration structure
 */
void I2C_SlaveInit(I2C_Type *base, const i2c_slave_config_t *psSlaveConfig);

/*!
 * @brief De-initializes the I2C peripheral. Call this API to disable the I2C module.
 *
 * @param base I2C base pointer
 */
static inline void I2C_SlaveDeinit(I2C_Type *base)
{
    I2C_MasterDeinit(base);
}

/*!
 * @brief Sets the I2C configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure for @ref I2C_Init to use. Use the unchanged
 * initialized structure in @ref I2C_Init or modify the structure before calling @ref I2C_Init.
 * This is an example.
 * @code
 *   i2c_config_t config;
 *   I2C_GetDefaultConfig(&config, 0x23U, 12000000U);
 * @endcode
 *
 * @param psConfig Pointer to the slave configuration structure.
 * @param u16PrimaryAddress For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * @param u32SrcClockHz The clock source frequency for I2C module.
 */
void I2C_GetDefaultConfig(i2c_config_t *psConfig, uint16_t u16PrimaryAddress, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the I2C peripheral.
 *
 * This API initialize the I2C module, including the feature configuration of high drive capacity, doubble buffer,
 * glitch filter, SCL timeout value, stop hold off enable, addressing mode, alert response/general call minitoring, auto
 * baudrate control, low power mode wake up and baudrate. User can also configure whether to enable the module in the
 * function.
 *
 * @note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enbaled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the API
 *
 * The configuration structure can be filled manully or be set with default values by calling @ref I2C_GetDefaultConfig.
 * This is an example.
 * @code
 *   i2c_config_t sConfig;
 *   I2C_GetDefaultConfig(&sConfig, 0x23U, 12000000U);
 *   I2C_Init(I2C0, &sConfig);
 * @endcode
 *
 * @param base I2C base pointer
 * @param psConfig Pointer to the I2C configuration structure
 */
void I2C_Init(I2C_Type *base, const i2c_config_t *psConfig);

/*!
 * @brief De-initializes the I2C peripheral. Call this API to disable the I2C module.
 *
 * @param base I2C base pointer
 */
static inline void I2C_Deinit(I2C_Type *base)
{
    I2C_MasterDeinit(base);
}
/*! @} */

/*!
 * @name Hardware Status Flags Sub-group
 * @{
 */
/*!
 * @brief Gets the I2C master hardware status flags.
 *
 * @param base I2C base pointer
 * @return the mask of status flags, can be a single flag or several flags in #_i2c_status_flags ORed together.
 */
uint16_t I2C_MasterGetStatusFlags(I2C_Type *base);

/*!
 * @brief Clears the I2C master status flags.
 *
 * @param base I2C base pointer
 * @param u16StatusFlags The status flag mask, can be a single flag or several flags in #_i2c_status_flags ORed
 * together. These flags among #_i2c_status_flags can be cleared:
 *          @arg kI2C_StartDetectInterruptFlag (only supported on certain SoCs)
 *          @arg kI2C_StopDetectInterruptFlag (only supported on certain SoCs)
 *          @arg kI2C_ArbitrationLostInterruptFlag
 *          @arg kI2C_InterruptPendingFlag
 *          @arg kI2C_RangeAddressMatchInterruptFlag
 *          @arg kI2C_AddressAsSlaveInterruptFlag
 *          @arg kI2C_SclLowTimeoutFlag
 *          @arg kI2C_SdaLowTimeoutInterruptFlag
 */
static inline void I2C_MasterClearStatusFlags(I2C_Type *base, uint16_t u16StatusFlags)
{
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    /* Must clear the STARTF bits prior to clearing IICIF */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_StartDetectInterruptFlag))
    {
        base->FLT |= I2C_FLT_STARTF_MASK;
    }
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

#ifdef I2C_HAS_STOP_DETECT
    /* Must clear the STOPF bits prior to clearing IICIF */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_StopDetectInterruptFlag))
    {
        base->FLT |= I2C_FLT_STOPF_MASK;
    }
#endif

    /* Clear the SCL low timeout flags. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_SclLowTimeoutFlag))
    {
        base->SMB |= (uint8_t)I2C_SMB_SLTF_MASK;
    }

    /* Clear the SDA low timeout flags. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_SdaLowTimeoutInterruptFlag))
    {
        base->SMB |= (uint8_t)I2C_SMB_SHTF2_MASK;
    }

    /* Clear interrupt pending and arbitration lost flag by writing 1 to these bits. */
    if (0U != (u16StatusFlags & ((uint16_t)kI2C_InterruptPendingFlag | (uint16_t)kI2C_ArbitrationLostInterruptFlag)))
    {
        base->S |= (uint8_t)u16StatusFlags;
    }

    /* Clear address match flags by writing any value to C1. */
    if (0U !=
        (u16StatusFlags & ((uint16_t)kI2C_RangeAddressMatchInterruptFlag | (uint16_t)kI2C_AddressAsSlaveInterruptFlag)))
    {
        base->C1 = base->C1;
    }
}

/*!
 * @brief Gets the I2C slave hardware status flags.
 *
 * @param base I2C base pointer
 * @return the mask of status flags, can be a single flag or several flags in #_i2c_status_flags ORed together.
 */
static inline uint16_t I2C_SlaveGetStatusFlags(I2C_Type *base)
{
    return I2C_MasterGetStatusFlags(base);
}

/*!
 * @brief Clears the I2C slave status flags.
 *
 * @param base I2C base pointer
 * @param u16StatusFlags The status flag mask, can be a single flag or several flags in #_i2c_status_flags ORed
 * together. These flags among #_i2c_status_flags can be cleared:
 *          @arg kI2C_StartDetectInterruptFlag (only supported on certain SoCs)
 *          @arg kI2C_StopDetectInterruptFlag (only supported on certain SoCs)
 *          @arg kI2C_ArbitrationLostInterruptFlag
 *          @arg kI2C_InterruptPendingFlag
 *          @arg kI2C_RangeAddressMatchInterruptFlag
 *          @arg kI2C_AddressAsSlaveInterruptFlag
 *          @arg kI2C_SclLowTimeoutFlag
 *          @arg kI2C_SdaLowTimeoutInterruptFlag
 */
static inline void I2C_SlaveClearStatusFlags(I2C_Type *base, uint16_t u16StatusFlags)
{
    I2C_MasterClearStatusFlags(base, u16StatusFlags);
}
/*! @} */

/*!
 * @name Interrupt Sub-group
 * @{
 */
/*!
 * @brief Enables I2C interrupt source.
 *
 * @note Before enabling kI2C_GlobalInterruptEnable, check kI2C_RangeAddressMatchInterruptFlag and
 * kI2C_AddressAsSlaveInterruptFlag first, because any write operation on C1 will clear these 2 bits.
 *
 * @param base I2C base pointer
 * @param u8Interrupts The interrupt source mask, can be a single source or several sources in #_i2c_interrupt_enable
 * ORed together.
 */
void I2C_EnableInterrupts(I2C_Type *base, uint8_t u8Interrupts);

/*!
 * @brief Disables I2C interrupt source.
 *
 * @note Before disabling kI2C_GlobalInterruptEnable, check kI2C_RangeAddressMatchInterruptFlag and
 * kI2C_AddressAsSlaveInterruptFlag first, because any write operation on C1 will clear these 2 bits.
 *
 * @param base I2C base pointer
 * @param u8Interrupts The interrupt source mask, can be a single source or several sources in #_i2c_interrupt_enable
 * ORed together.
 */
void I2C_DisableInterrupts(I2C_Type *base, uint8_t u8Interrupts);

/*!
 * @brief Get all the enabled interrupt sources.
 *
 * @param base I2C base pointer
 * @return The interrupt source mask, can be a single source or several sources in #_i2c_interrupt_enable ORed
 * together.
 */
uint8_t I2C_GetEnabledInterrupts(I2C_Type *base);
/*! @} */

/*!
 * @name Common Peripheral Configuration Sub-group
 * @{
 */
/*!
 * @brief Returns whether the I2C module is in master mode.
 *
 * @param base I2C base pointer
 * @return True for master mode, false for slave mode.
 */
static inline bool I2C_IsMaster(I2C_Type *base)
{
    return (0U != (base->C1 & (uint8_t)I2C_C1_MST_MASK));
}

/*!
 * @brief Sets the I2C register value to reset value.
 *
 * @param base I2C base pointer
 */
static inline void I2C_Reset(I2C_Type *base)
{
    base->A1 = 0;
    base->F  = 0;
    base->C1 = 0;
    base->S  = 0xFFU;
    base->C2 = 0;
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    base->FLT = 0x50U;
#elif defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
    base->FLT = 0x40U;
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */
    base->RA  = 0;
    base->SMB = 0;
    base->A2  = 0xC2;
}

/*!
 * @brief Enables or disables the I2C peripheral operation.
 *
 * @param base I2C base pointer
 * @param bEnable Pass true to enable and false to disable the module.
 */
static inline void I2C_Enable(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->C1 |= I2C_C1_IICEN_MASK;
    }
    else
    {
        base->C1 &= ~(uint8_t)I2C_C1_IICEN_MASK;
    }
}

/*!
 * @brief Enables/Disables fast NACK/ACK feature.
 *
 * When enbled, writing 0/1 to TXAK generates an ACK/NACK after receiving a data byte, when disabled, writing 0/1 to
 * TXAK generates an ACK/NACK on the following receiving data byte.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_EnableFastAck(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SMB |= (uint8_t)I2C_SMB_FACK_MASK;
    }
    else
    {
        base->SMB &= ~(uint8_t)I2C_SMB_FACK_MASK;
    }
}

/*!
 * @brief Enables/Disables high drive.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_EnableHighDrive(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->C2 |= (uint8_t)I2C_C2_HDRS_MASK;
    }
    else
    {
        base->C2 &= ~(uint8_t)I2C_C2_HDRS_MASK;
    }
}

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
/*!
 * @brief Enables/Disables double buffer.
 *
 * @param base I2C base pointer
 * @param True to bEnable, false to disable.
 */
static inline void I2C_EnableDoubleBuffer(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->S2 |= (uint8_t)I2C_S2_DFEN_MASK;
    }
    else
    {
        base->S2 &= ~(uint8_t)I2C_S2_DFEN_MASK;
    }
}
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */

#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
/*!
 * @brief Enables/Disables double buffer.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_EnableStopHold(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->FLT |= (uint8_t)I2C_FLT_SHEN_MASK;
    }
    else
    {
        base->FLT &= ~(uint8_t)I2C_FLT_SHEN_MASK;
    }
}
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */

/*!
 * @brief Sets I2C module data direction.
 *
 * @param base I2C base pointer
 * @param eDataDirection #kI2C_Write to write data to bus, #kI2C_Read to read data from bua
 */
static inline void I2C_SetTransferDirection(I2C_Type *base, i2c_data_direction_t eDataDirection)
{
    if (kI2C_Write == eDataDirection)
    {
        base->C1 |= (uint8_t)I2C_C1_TX_MASK;
    }
    else
    {
        base->C1 &= ~(uint8_t)(I2C_C1_TX_MASK | I2C_C1_TXAK_MASK);
    }
}

/*!
 * brief Sets the I2C SCL timeout value.
 *
 * After the I2C module is initialized, user can call this function to change the timeout value.
 *
 * param base I2C base pointer.
 * param u16SclTimout_Ms The SCL timeout value in ms.
 * param u32SrcClockHz I2C peripheral clock frequency in Hz
 */
void I2C_SetSclTimeoutValue(I2C_Type *base, uint16_t u16SclTimout_Ms, uint32_t u32SrcClockHz);

/*!
 * brief Sets the I2C master glitch filter width.
 *
 * After the I2C module is initialized as master, user can call this function to change the glitch filter width.
 *
 * param base I2C base pointer.
 * param u16GlitchFilter_Ns The GLitch filter length in nano seconds.
 * param u32SrcClockHz I2C peripheral clock frequency in Hz
 */
void I2C_SetGlitchFilter(I2C_Type *base, uint16_t u16GlitchFilter_Ns, uint32_t u32SrcClockHz);

#if defined(FSL_FEATURE_I2C_HAS_DMA_SUPPORT) && FSL_FEATURE_I2C_HAS_DMA_SUPPORT
/*!
 * @brief Enables/disables the I2C DMA request.
 *
 * @param base I2C base pointer
 * @param bEnable true to enable, false to disable
 */
static inline void I2C_EnableDMA(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->C1 |= I2C_C1_DMAEN_MASK;
    }
    else
    {
        base->C1 &= ~(uint8_t)I2C_C1_DMAEN_MASK;
    }
}

/*!
 * @brief Gets the I2C data register address. This API is used to provide the transfer address for I2C DMA transfer.
 *
 * @param base I2C base pointer
 * @return data register address
 */
static inline uint32_t I2C_GetDataRegAddr(I2C_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(I2C_Type, base, D);
}
#endif /* FSL_FEATURE_I2C_HAS_DMA_SUPPORT */
/*! @} */

/*!
 * @name Slave Peripheral Configuration Sub-group
 * @{
 */
/*!
 * @brief Enables/Disables alert response.
 *
 * When enbled, I2C slave will monitor the bus line, and when alert response address is received address match status
 * flag will be set.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_SlaveEnableAlertResponse(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SMB |= (uint8_t)I2C_SMB_ALERTEN_MASK;
    }
    else
    {
        base->SMB &= ~(uint8_t)I2C_SMB_ALERTEN_MASK;
    }
}

/*!
 * @brief Enables/Disables secondary address.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_SlaveEnableSecondaryAddress(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SMB |= (uint8_t)I2C_SMB_SIICAEN_MASK;
    }
    else
    {
        base->SMB &= ~(uint8_t)I2C_SMB_SIICAEN_MASK;
    }
}

/*!
 * @brief Enables/Disables general call.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_SlaveEnableGeneralCall(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->C2 |= (uint8_t)I2C_C2_GCAEN_MASK;
    }
    else
    {
        base->C2 &= ~(uint8_t)I2C_C2_GCAEN_MASK;
    }
}

/*!
 * @brief Enables/Disables slave low power wakeup.
 *
 * @param base I2C base pointer
 * @param bEnable True to enable, false to disable.
 */
static inline void I2C_SlaveEnableWakeUp(I2C_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->C1 |= (uint8_t)I2C_C1_WUEN_MASK;
    }
    else
    {
        base->C1 &= ~(uint8_t)I2C_C1_WUEN_MASK;
    }
}

/*!
 * @brief Configure the slave addressing mode.
 *
 * After the I2C module is initialized as slave, user can call this function to change the configuration of slave
 * addressing mode.
 *
 * @param base I2C base pointer.
 * @param eAddressingMode The slave addressing mode, single address or range address.
 * @param u16Address I2C slave address. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * @param u8MaxAddress The maximum boundary of slave address used in a range address match.
 */
void I2C_SlaveSetAddressingMode(I2C_Type *base,
                                i2c_slave_address_mode_t eAddressingMode,
                                uint16_t u16Address,
                                uint8_t u8MaxAddress);
/*! @} */

/*!
 * @name Master Peripheral Configuration Sub-group
 * @{
 */
/*!
 * @brief Sets the I2C master transfer baud rate.
 *
 * After the I2C module is initialized as master, user can call this function to change the transfer baud rate.
 *
 * @param base I2C base pointer.
 * @param u32BaudRateBps the baud rate value in bits-per-second.
 * @param u32SrcClockHz I2C peripheral clock frequency in Hz
 */
void I2C_MasterSetBaudRate(I2C_Type *base, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz);
/*! @} */

/*!
 * @name Common Bus Operation Sub-Group
 * @{
 */
/*!
 * @brief Reads one byte from data register directly.
 *
 * @param base I2C base pointer
 * @return The data read from data register.
 */
static inline uint8_t I2C_ReadByte(I2C_Type *base)
{
    return (uint8_t)base->D;
}

/*!
 * @brief Writes one byte to the data register directly.
 *
 * @param base I2C base pointer
 * @param u8Data The byte to write.
 */
static inline void I2C_WriteByte(I2C_Type *base, uint8_t u8Data)
{
    base->D = u8Data;
}

/*!
 * @brief Sends an acknowledge/non-acknowledge signal to the bus on the following receiving byte
 * if SMB[FACK] is cleared, or on the current receiving byte if SMB[FACK] is set.
 *
 * @param base I2C base pointer
 * @param bIsAck True to send ACK signal, false to send NACK signal
 */
static inline void I2C_SendAck(I2C_Type *base, bool bIsAck)
{
    if (bIsAck)
    {
        base->C1 &= ~(uint8_t)I2C_C1_TXAK_MASK;
    }
    else
    {
        base->C1 |= (uint8_t)I2C_C1_TXAK_MASK;
    }
}
/*! @} */

/*!
 * @name Master Bus Operation Sub-Group
 * @{
 */
/*!
 * @brief Sends a START signal on the I2C bus then the 7-bit slave address with transmit/receive bit
 *
 * This function is used to initiate a new transfer in master mode, by sending a START signal, then the slave address
 * with transmit/receive bit to I2C bus.
 *
 * @note The return value of this API only indicates whether the start signal is sent to bus, user has to check
 * #kI2C_ArbitrationLostInterruptFlag and #kI2C_ReceiveNakFlag using @ref I2C_MasterClearStatusFlags to see if
 * valid slave device is avaliable or the aribitration is lost.
 *
 * @param base I2C base pointer
 * @param u8Address 7-bit slave device address.
 * @param eDirection Master transfer directions(transmit/receive).
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * @retval kStatus_Success Successfully send the start signal.
 * @retval kStatus_I2C_Busy Current bus is busy.
 */
status_t I2C_MasterStart(I2C_Type *base, uint8_t u8Address, i2c_master_transfer_direction_t eDirection);

/*!
 * @brief Sends a repeated START signal, then the 7-bit slave address with transmit/receive bit to I2C bus.
 *
 * @param base I2C peripheral base pointer
 * @param u8Address 7-bit slave device address.
 * @param eDirection Master transfer directions(transmit/receive).
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * @retval kStatus_Success Successfully send the start signal.
 * @retval kStatus_I2C_Busy Current bus is busy but not occupied by current I2C master.
 */
status_t I2C_MasterRepeatedStart(I2C_Type *base, uint8_t u8Address, i2c_master_transfer_direction_t eDirection);

/*!
 * @brief Sends a STOP signal on the I2C bus.
 *
 * @param base I2C base pointer
 * @retval kStatus_Success Successfully send the stop signal.
 * @retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterStop(I2C_Type *base);

/*!
 * @brief Sends a piece of data to I2C bus in master mode in blocking way.
 *
 * Call this function when using I2C as master to send certain bytes of data to bus when start signal is already sent.
 * User can specify whether to send a stop siganl after the data. This function uses the blocking way, which means it
 * does not return until all the data is sent to bus and stop signal is successfully issued(if user configures the stop
 * signal).
 *
 * @param base I2C base pointer.
 * @param pu8Data The pointer to the data to be transmitted.
 * @param txSize The length in bytes of the data to be transmitted.
 * @param bSendStop Whether to send stop signal after the data transfer.
 * @retval #kStatus_Success Successfully complete the data transmission.
 * @retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval #kStatus_I2C_Nak Transfer error, receive NAK during transfer.
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 */
status_t I2C_MasterWriteBlocking(I2C_Type *base, const uint8_t *pu8Data, uint16_t txSize, bool bSendStop);

/*!
 * @brief Receives a piece of data from I2C bus in master mode in blocking way.
 *
 * Call this function when using I2C as master to receive certain bytes of data from bus when start signal is already
 * sent. User can specify whether to send a stop siganl after the data. This function uses the blocking way, which means
 * it does not return until all the data has been received and stop signal is successfully issued(if user configures the
 * stop signal).
 *
 * @note If user configures to send stop signal after the data, this function stops the bus before reading the final
 * byte from data register. Without stopping the bus prior to the final read, the bus will issue another read, resulting
 * in garbage data being read into the data register.
 *
 * @param base I2C base pointer.
 * @param pu8RxBuff The pointer to the data to store the received data.
 * @param rxSize The length in bytes of the data to be received.
 * @param bSendStop Whether to send stop signal after the data transfer.
 * @retval kStatus_Success Successfully complete the data transmission.
 * @retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterReadBlocking(I2C_Type *base, uint8_t *pu8RxBuff, uint16_t rxSize, bool bSendStop);

/*! @} */

/*!
 * @name Slave Bus Operation Sub-Group
 * @{
 */
/*!
 * @brief Sends a piece of data to I2C bus in slave mode in blocking way.
 *
 * Call this funtion to let I2C slave poll register status until it is addressed, then slave sends txSize of data to bus
 * until all the data has been sent to bus or untill it is nacked.
 *
 * @param base I2C base pointer.
 * @param pu8TxBuff The pointer to the data to be transferred.
 * @param txSize The length in bytes of the data to be transferred.
 * @retval #kStatus_Success Successfully complete the data transmission.
 * @retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval #kStatus_I2C_Nak Transfer error, receive NAK during transfer.
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 */
status_t I2C_SlaveWriteBlocking(I2C_Type *base, const uint8_t *pu8TxBuff, uint16_t txSize);

/*!
 * @brief Receives a piece of data from I2C bus in slave mode in blocking way.
 *
 * Call this funtion to let I2C slave poll register status until it is addressed, then slave receives rxSize of data
 * until all the data has been received.
 *
 * @param base I2C base pointer.
 * @param pu8RxBuff The pointer to the data to store the received data.
 * @param rxSize The length in bytes of the data to be received.
 * @retval kStatus_Success Successfully complete data receive.
 * @retval kStatus_I2C_Timeout Wait status flag timeout.
 */
status_t I2C_SlaveReadBlocking(I2C_Type *base, uint8_t *pu8RxBuff, uint16_t rxSize);

/*! @} */
/* =========================================== End of Functional API Group ========================================== */

/* ============================================ Transactional API Group ============================================= */
/*!
 * @name Master Transfer Sub-group
 * @{
 */
/*!
 * @brief Performs a master polling transfer on the I2C bus.
 *
 * @note The API does not return until the transfer succeeds or fails due to arbitration lost or receiving a NAK.
 *
 * @param base I2C peripheral base address.
 * @param psTransferConfig Pointer to the transfer configuration structure.
 * @retval kStatus_Success Successfully complete the data transmission.
 * @retval #kStatus_I2C_Busy Previous transmission still not finished.
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flagsto change.
 * @retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval #kStatus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferBlocking(I2C_Type *base, i2c_master_transfer_t *psTransferConfig);

/*!
 * @brief Initializes the I2C master transfer in interrupt way.
 *
 * This function is responsible for initializig master transfer psHandle, installing user callback, registering master
 * IRQ handling function and opening global interrupt.
 *
 * @param base I2C base pointer.
 * @param psHandle pointer to @ref i2c_master_transfer_handle_t structure to store the transfer state.
 * @param pfCallback pointer to user callback function.
 * @param pUserData User configurable pointer to any data, function, structure etc that user wish to use in the callback
 */
void I2C_MasterTransferCreateHandle(I2C_Type *base,
                                    i2c_master_transfer_handle_t *psHandle,
                                    i2c_master_transfer_callback_t pfCallback,
                                    void *pUserData);

/*!
 * @brief Initiates a master transfer on the I2C bus in interrupt way.
 *
 * @note Transfer in interrupt way is non-blocking which means this API returns immediately after transfer initiates.
 * User can call @ref I2C_MasterTransferGetCount to get the count of data that master has transmitted/received and check
 * transfer status. If the return status is kStatus_NoTransferInProgress, the transfer is finished. Also if user
 * installs a user callback when calling @ref I2C_MasterTransferCreateHandle before, the callback will be invoked when
 * transfer finishes.
 *
 * @param psHandle pointer to @ref i2c_master_transfer_handle_t structure which stores the transfer state.
 * @param psTransferConfig Pointer to the transfer configuration structure.
 * @retval kStatus_Success Successfully start the data transmission.
 * @retval #kStatus_I2C_Busy Previous transmission still not finished.
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flagsto change.
 */
status_t I2C_MasterTransferNonBlocking(i2c_master_transfer_handle_t *psHandle, i2c_master_transfer_t *psTransferConfig);

/*!
 * @brief Gets the master transfer count and status during a interrupt transfer.
 *
 * @param psHandle pointer to @ref i2c_master_transfer_handle_t structure which stores the transfer state.
 * @param count Pointer to number of bytes transferred so far by the non-blocking transaction.
 * @retval kStatus_InvalidArgument count is Invalid.
 * @retval kStatus_NoTransferInProgress Curent no transfer is in progress.
 * @retval kStatus_Success Successfully obtained the count.
 */
status_t I2C_MasterTransferGetCount(i2c_master_transfer_handle_t *psHandle, uint16_t *count);

/*!
 * @brief Aborts an in-process transfer in interrupt way.
 *
 * @note This API can be called at any time after a transfer of interrupt way initiates and before it finishes to abort
 * the transfer early.
 *
 * @param psHandle pointer to @ref i2c_master_transfer_handle_t structure which stores the transfer state
 * @retval #kStatus_I2C_Busy Master lost arbitration, bus is in use by other master.
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * @retval kStatus_Success Successfully abort the transfer.
 */
status_t I2C_MasterTransferAbort(i2c_master_transfer_handle_t *psHandle);
/*! @} */

/*!
 * @name Slave Transfer Sub-group
 * @{
 */
/*!
 * @brief Initializes the I2C slave transfer in interrupt way.
 *
 * This function is responsible for initializig slave transfer handle, installing user callback, registering slave IRQ
 * handling function and opening global interrupt.
 *
 * @param base I2C base pointer.
 * @param psHandle pointer to @ref i2c_slave_transfer_handle_t structure to store the transfer state.
 * @param pfCallback pointer to user callback function.
 * @param pUserData User configurable pointer to any data, function, structure etc that user wish to use in the callback
 */
void I2C_SlaveTransferCreateHandle(I2C_Type *base,
                                   i2c_slave_transfer_handle_t *psHandle,
                                   i2c_slave_transfer_callback_t pfCallback,
                                   void *pUserData);

/*!
 * @brief Sets I2C slave ready to process bus events.
 *
 * Call this API to let I2C start monitoring bus events driven by I2C master on bus. When user specified event occurs,
 * callback will be invoked passes event information to the callback.
 *
 * @note When #kI2C_SlaveOutofTransmitDataEvent and #kI2C_SlaveOutofReceiveSpaceEvent occured, slave callback will
 * always be revoked regardless which events user choose to enable. This means user need not configure them in the
 * psTransferConfig. If user wants to enable all the events, use #kI2C_SlaveAllEvents for convenience.
 *
 * @param psHandle Pointer to @ref i2c_slave_transfer_handle_t structure which stores the transfer state.
 * @param psTransferConfig I2C transfer configuration.
 * @retval kStatus_Success I2C slave set to standby state successfully and ready to process events.
 * @retval kStatus_I2C_Busy I2C slave has already been started on this handle.
 */
status_t I2C_SlaveTransferNonBlocking(i2c_slave_transfer_handle_t *psHandle, i2c_slave_transfer_t *psTransferConfig);

/*!
 * @brief Gets how many bytes slave have transferred in curent data buffer.
 *
 * @param psHandle pointer to i2c_slave_transfer_handle_t structure.
 * @param count Number of bytes slave have transferred after the last start/repeated start.
 * @retval kStatus_InvalidArgument count is Invalid.
 * @retval kStatus_NoTransferInProgress Curent no transfer is in progress.
 * @retval kStatus_Success Successfully obtained the count.
 */
status_t I2C_SlaveTransferGetCount(i2c_slave_transfer_handle_t *psHandle, uint16_t *count);

/*!
 * @brief Aborts the slave transfer.
 *
 * @note This API can be called at any time to stop slave for handling further bus events.
 *
 * @param psHandle pointer to @ref i2c_slave_transfer_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferAbort(i2c_slave_transfer_handle_t *psHandle);
/*! @} */
/* ========================================= End of Transactional API Group ========================================= */

/*!
 * @brief Gets instance number for I2C module.
 *
 * @param base I2C base pointer.
 * @retval The number of the instance.
 */
uint32_t I2C_GetInstance(I2C_Type *base);

#if defined(__cplusplus)
}
#endif /*_cplusplus. */

/*! @}*/

#endif /* FSL_I2C_H_*/
