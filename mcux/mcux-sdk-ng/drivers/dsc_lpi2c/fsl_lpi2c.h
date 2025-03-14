/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LPI2C_H_
#define FSL_LPI2C_H_

#include "fsl_common.h"

/*!
 * @defgroup lpi2c LPI2C: Low Power Inter-Integrated Circuit Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief LPI2C driver version. */
#define FSL_LPI2C_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup lpi2c_driver_log The Driver Change Log
 * @ingroup lpi2c
 * @{
 * The current LPI2C driver version is 2.0.2.
 *
 * - 2.0.2
 *   - Bug Fixes
 *     - Fixed bug in eDMA transfer for SoCs whose rx and tx have different eDMA requests.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*****************************************************************************
 * Introduction of peripheral and driver
 *****************************************************************************/
/*!
 * @defgroup lpi2c_intro LPI2C Peripheral and Driver Overview
 * @ingroup lpi2c
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral feature and how this peripheral works
 * ================================================
 * The LPI2C is a low power Inter-Integrated Circuit(I2C) module that supports an efficient
 * interface to an I2C bus as a master and/or as a slave.
 *
 * Features
 * --------
 *   + Communication
 *     - Standard, Fast, Fast+ and Ultra Fast modes are supported
 *     - Clock stretching and arbitration
 *   + Master operation
 *     - 4words Command/transmit FIFO
 *     - 4words receive FIFO
 *     - Host request input to trigger the start of an I2C bus transfer
 *     - Data match feature with flexible setting to discard unwanted data
 *     - Configurable bus idle timeout and pin-stuck-low timeout
 *     - Multi-master support, including synchronization and arbitration. Multi-master means any number
 *       of master nodes can be present. Additionally, master and slave roles may be changed between
 *       messages(after a STOP is sent)
 *   + Slave operation
 *     - Separate I2C slave registers to minimise software overhead because of master/slave switching
 *     - Software-controllable ACK or NACK, with optional clock stretching on ACK/NACK bit
 *     - Configurable clock stretching, to avoid transmit FIFO underrun and receive FIFO overrun errors
 *
 * How this driver is designed to make this peripheral works
 * =========================================================
 * On abstraction level, the LPI2C driver provides two parallel layers for various cases with different
 * requirements on flexibility: Functional layer and Transactional layer. Do not mix the usage of the data
 * transfer APIs in these 2 layers, check the transaction APIs introduction in 'How to use this driver' part.
 * To distinguish Transactional layer from Functional layer easily, all Transactional APIs take 'Transfer'
 * in API name.
 *
 * Functional Layer
 * ----------------
 * It's provided with highly optimized implementation and highly flexible usage of the hardware details.
 * User needs to know how to organize these functional APIs together to meet application requirement.
 * The LPI2C driver provides master and slave feature enabling APIs named as LPI2C_MasterXxx and LPI2C_SlaveXxx,
 * user can choose which needed in their application and use related interfaces. These APIs implement to
 * configure basic features of LPI2C, they're highly separated according to different features. Application
 * just needs to combine them on demand. For data transfer, there're also multiple APIs to finish the whole
 * I2C transfer: START/REPEAT_START, SEND/RECEIVE and STOP.
 *
 * Transactional Layer
 * -------------------
 * It's provided with high abstraction, limited flexibility/optimization, and not all features are covered.
 * It aims to let user implement LPI2C transaction with least knowledge requirement of this specific I2C
 * peripheral and least coding effort. It achieves this goal by hiding the setup of interrupt processing
 * inside driver and implementing software state machine for LPI2C transaction.
 *
 * + Software Implementation Logic
 *   - Double Weak Mechanism
 *     One of the key features of Transactional layer compared to Functional layer is user need not setup interrupt
 *     handling codes, but can still get IRQ service function executed when interrupt happens. This is achieved by the
 *     'double weak' mechanism. Refer to the general section of API Reference Manual for detail.
 *     In brief, SDK place a weak function A for this peripheral's vector entry. The default implementation of this
 *     function calls another weak function B. By default, when a interrupt happen, the code will be executed as
 *     A (Weak) -> B (Weak). This driver implements the function B as non-weak inside, thus once user gets the driver
 *     file into the application project, when interrupt happens, code will be executed as
 *     A (Weak) -> B (Non-Weak, in this driver). If user wants to implement customized IRQ service routine, just define
 *     function A in application as non-weak.
 *   - Transfer handle
 *     In transactional layer, transfer handle(defined as @ref lpi2c_master_transfer_handle_t for master and defined as
 *     @ref lpi2c_slave_transfer_handle_t for slave is used to represent the instance. It contains not only the
 * instance's base pointer and user callback, but also the configuration for the transfer and transfer context. So each
 * time when entering the ISR, the program would know what to do according to last transfer state stored in the handle.
 *     Transactional layer is state retained thus user should not try to modify its member in application level. User
 *     need to initialize the handle before initiating any transfer by calling @ref LPI2C_MasterTransferCreateHandle or
 *     @ref LPI2C_SlaveTransferCreateHandle.
 *     Due to the handle's special role for transactional layer, after user allocates the transfer handle and installs
 *     it using create handle API, user should maintain the handle's memory section so it is active during the LPI2C's
 *     life cycle.
 *
 * How to use this driver
 * ======================
 *
 * General Control Macro
 * ---------------------
 * + FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL
 *     SDK general Macro, controls whether to ungate/gate peripheral's clock source inside driver. Set it
 *     non-zero value then driver will not ungate/gate clock source during init/deinit. User needs to handle
 *     clock configuration in application code.
 *
 * + I2C_RETRY_TIMES
 *     When LPI2C transmit/receive data, need to wait for status flags. Set I2C_RETRY_TIMES as a non-zero
 *     value to return kStatus_LPI2C_Timeout if wait flags for setting times and flags have no changed.
 *     Driver will always wait certain flag if I2C_RETRY_TIMES is zero as default.
 *
 * + I2C_SMBUS_ENABLE
 *     Set this macro to 1 to enable SMBus supporting.
 *
 * Configuration Items Before Calling LPI2C Driver APIs
 * ----------------------------------------------------
 * + Configure LPI2C peripheral clock tree.
 * + LPI2C pin mux and pad attribute should be set on demand.
 * + Disable the LPI2C clock control in driver through define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL as 1
 *   if user wants to enable/disable LPI2C clock outside driver.
 * + Set appropriate LPI2C interrupt priority in the project environment of lots of peripherals enabling
 *   their interrupts and needing to execute handler code.
 *
 * The General Steps To Use LPI2C Driver
 * ----------------------
 * <b>Common:</b>\n
 * Function @ref LPI2C_Init initialises I2C master and slave operations together, user can
 * call @ref LPI2C_GetDefaultConfig to get default setting and give this to @ref LPI2C_Init
 * to enable basic features for master and slave. If user only wants to use one of master/slave,
 * please call @ref LPI2C_MasterInit or @ref LPI2C_SlaveInit to finish specified initialization
 * work. Two similar LPI2C_xxxGetDefaultConfig APIs are also ready for master and slave, more
 * information is in the following comments. If user wants to disable master or/and slave,
 * there're @ref LPI2C_Deinit, @ref LPI2C_MasterDeinit and @ref LPI2C_SlaveDeinit to do it.
 * @note If #FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is not enabled, LPI2C clock will be disabled
 * in Master/Slave Deinit function.
 *
 * <b>Master Operation:</b>
 * 1. Set suitable value in structure @ref lpi2c_master_config_t to configure basic feature of
 *    LPI2C master mode, please check the comments in this structure to get more details.
 *    There's an API @ref LPI2C_MasterGetDefaultConfig to get default setting covering
 *    conventional demand. User should set it according to specific application.
 * 2. Call @ref LPI2C_MasterInit to initialise LPI2C peripheral which should enable features
 *    based on @ref lpi2c_master_config_t.
 * 3. Driver provides more APIs to configure special features except what @ref LPI2C_MasterInit
 *    has done. Such as @ref LPI2C_MasterSetDataMatch and @ref LPI2C_MasterSetBaudRate,
 *    please read separate function description to know more. The benefit is these APIs can
 *    be used to enable or disable related features after LPI2C has been initialised. \par
 *    @note Just be careful these APIs will disable LPI2C master before setting peripheral
 *    register and enable after that, should call them when LPI2C master is idle.
 * 4. For transaction, LPI2C driver provides three ways in two layers to transmit/receive I2C data with master.
 *    + Functional layer \n
 *    A group of APIs @ref LPI2C_MasterStart, @ref LPI2C_MasterRepeatedStart, @ref LPI2C_MasterReceive,
 *    @ref LPI2C_MasterSend and @ref LPI2C_MasterStop to implement each procedure of I2C transfer.
 *      - @ref LPI2C_MasterStart
 *        It will check whether the I2C bus is busy(SCL low level) and wait for enough space in LPI2C
 *        Tx FIFO. If all transfer conditions are OK, SDA line will pull low to start I2C transfer and
 *        send out 7-bit slave address + 1-bit read/write direct.
 *      - @ref LPI2C_MasterRepeatedStart
 *        It just encapsulates @ref LPI2C_MasterStart with a new name. It's better to use this API when
 *        starting a new transfer without stopping last one, this name is easier to understand.
 *      - @ref LPI2C_MasterReceive, @ref LPI2C_MasterSend
 *        They will check FIFO space situation, and start to send or receive a bundle of data with I2C.
 *      - @ref LPI2C_MasterStop
 *        It releases SCL to high level to stop the I2C transfer.
 *
 *    + Transactional layer Blocking Transfer
 *      - @ref LPI2C_MasterTransferBlocking
 *        It sends/receives data according the parameters in @ref lpi2c_master_transfer_t, it returns
 *        after the transfer is over or getting errors.
 *        - @ref lpi2c_master_transfer_t
 *           Member           | Comment
 *           -----------------| -----------------------------------------
 *           u8ControlFlagMask| @ref _lpi2c_master_transfer_control_flags
 *           u8SlaveAddress   | The 7-bit slave address
 *           eDirection       | Read or write @ref lpi2c_data_direction_t
 *           pu8Command       | Pointer to command code
 *           u8CommandSize    | Length of command buffer to send in bytes
 *           pData            | I2C transfer data buffer address
 *           u16DataSize      | Number of bytes to transfer
 *
 *        Uses u8ControlFlagMask, control to add/remove start/stop operation in this transfer. The eDirection
 *        indicates transfer is reading or writing. They make this API flexible to be used for sending or
 *        receiving. The u8SlaveAddress is I2C slave device address following the start flag. The pu8Command
 *        is usually used when user reads/writes I2C data from/to an external device such as EEPROM.
 *        If use Functional layer API to send this external device address, need to populate it into
 *        data buffer. With this API user can store it in pu8Command, it's more intuitive and easier
 *        to use. It can also take other commands for various I2C device. The u8CommandSize indicates
 *        byte size in pu8Command address. The pData and u16DataSize are the most parameters needed by
 *        any transfer without more mention.
 *
 *    + Transactional layer NonBlocking Transfer
 *      - @ref LPI2C_MasterTransferNonBlocking
 *        It also uses @ref lpi2c_master_transfer_t to set transfer information, this part of usage is
 *        same as @ref LPI2C_MasterTransferBlocking. But this API returns immediately without waiting the
 *        transfer over, it just starts the transfer and let interrupt handler in driver to finish transfer.
 *        Another difference is an extra parameter @ref lpi2c_master_transfer_handle_t is used by this API, interrupt
 *        handler code needs this structure, but user needn't care about it and only need to call
 *        @ref LPI2C_MasterTransferCreateHandle to initialize it then give it to @ref LPI2C_MasterTransferNonBlocking.
 *        Meanwhile @ref lpi2c_master_transfer_callback_t should be defined and given to
 *        @ref LPI2C_MasterTransferCreateHandle if user hopes to get the transfer over status. Interrupt
 *        handler in driver will call this callback after the transfer is over or getting errors, please
 *        check related code snippet in Typical Use Case below to know more.
 *
 *      - @ref LPI2C_MasterTransferAbort
 *        This API can be used when user wants to abort on-going transfer in Transactional layer NonBlocking Transfer.
 *
 *    @note If system enters debug mode when I2C transfer is on-going, this transfer will abort.
 *    If want to debug LPI2C and not stop normal transfer, need to set \#bDebugEnable as true.
 *
 * <b>Slave Operation:</b>
 * 1. Set suitable value in structure @ref lpi2c_slave_config_t to configure basic feature of LPI2C
 *    slave mode, please check the comments in this structure to get more details. There's an API
 *    @ref LPI2C_SlaveGetDefaultConfig to get default setting covering conventional demand. User
 *    should set it according to specific application.
 * 2. Call @ref LPI2C_SlaveInit to initialise LPI2C peripheral which should enable features based
 *    on @ref lpi2c_master_config_t.
 * 3. For transaction, this LPI2C driver provides two ways in two layers to transmit/receive I2C data with slave.
 *    + Functional layer \n
 *    A group of APIs @ref LPI2C_SlaveSend, @ref LPI2C_SlaveReceive to implement I2C slave feature.
 *      - @ref LPI2C_SlaveGetStatusFlags
 *        Uses it to check whether the #kLPI2C_SlaveAddressValidInterruptFlag is set which means master
 *        device start a transfer with this slave device address.
 *      - @ref LPI2C_SlaveSend
 *        It will send a bundle of data with I2C when master side is ready to receive.
 *      - @ref LPI2C_SlaveReceive
 *        It will receive a bundle of data with I2C when master side is ready to send.
 *
 *    + Transactional layer
 *      - @ref LPI2C_SlaveTransferNonBlocking
 *        This function returns immediately without waiting the transfer over, it just starts the
 *        transfer and let interrupt handler code in driver to manage transfer. Before using this
 *        API, @ref LPI2C_SlaveTransferCreateHandle needs to be called to initialise the handler
 *        structure @ref lpi2c_slave_transfer_handle_t and callback @ref lpi2c_slave_transfer_callback_t.
 *        The actual transfer is on-going in @ref LPI2C_SlaveTransferHandleIRQ and will call callback
 *        function according to transfer states, so then user needs to put important transfer information
 *        into @ref lpi2c_slave_transfer_t in this user-defined callback function to finish transfer.
 *
 *        -- @ref lpi2c_slave_transfer_t
 *           eEvent              @ref lpi2c_slave_transfer_event_t, reason the callback is invoked
 *           u16ReceivedAddress  Matching address send by master.
 *           pu8Data             Transfer buffer
 *           u16DataSize         Transfer size
 *           completionStatus    Success or error code after transfer completed.
 *           u16TransferredCount Number of bytes actually transferred since start or last repeated start
 *        In callback, check eEvent to know various event in whole transfer then handle them. The
 *        u16ReceivedAddress stores the slave address sent by master when eEvent is #kLPI2C_SlaveAddressMatchEvent
 *        The pu8Data and u16DataSize are the most important information in slave transfer, they indicate
 *        ready sent data buffer when eEvent is #kLPI2C_SlaveTransmitEvent, indicate received data buffer
 *        when eEvent is #kLPI2C_SlaveReceiveEvent. There're other events like #kLPI2C_SlaveCompletionEvent,
 *        user need to manage these events according to specific situation to implement whole transfer, please
 *        check related code snippet about this API in 'Typical Use Case' below to know general usage.
 *
 *      - @ref LPI2C_SlaveTransferAbort
 *        This API can be used when user wants to abort on-going transfer in Transactional layer.
 *
 * Typical Use Case
 * ====================
 * <b>Master Operation:</b>
 *   + Functional layer
 *   @code
 *     lpi2c_master_config_t sMasterConfig = {0};
 *     uint8_t master_txbuff[10] = {0};
 *     uint8_t master_rxbuff[10] = {0};
 *     LPI2C_MasterGetDefaultConfig(&sMasterConfig, LPI2C_MASTER_CLOCK_FREQUENCY);
 *     LPI2C_MasterInit(LPI2C1, &sMasterConfig);
 *     LPI2C_MasterStart(LPI2C1, LPI2C_MASTER_SLAVE_ADDR_7BIT, kLPI2C_Write);
 *     LPI2C_MasterSend(LPI2C1, &master_txbuff[0], 10, false);
 *     LPI2C_MasterRepeatedStart(LPI2C1, LPI2C_MASTER_SLAVE_ADDR_7BIT, kLPI2C_Read);
 *     LPI2C_MasterReceive(LPI2C1, &master_rxbuff[0], 10, false);
 *     LPI2C_MasterStop(LPI2C1);
 *   @endcode
 *
 *   + Transactional layer Blocking Transfer
 *   @code
 *     lpi2c_master_config_t sMasterConfig = {0};
 *     lpi2c_master_transfer_t sMasterXfer = {0};
 *     uint8_t master_txbuff[10] = {0};
 *     uint8_t master_rxbuff[10] = {0};
 *     LPI2C_MasterGetDefaultConfig(&sMasterConfig, LPI2C_MASTER_CLOCK_FREQUENCY);
 *     LPI2C_MasterInit(LPI2C1, &sMasterConfig);
 *     sMasterXfer.u8SlaveAddress    = I2C_MASTER_SLAVE_ADDR_7BIT;
 *     sMasterXfer.eDirection        = kLPI2C_Write;
 *     sMasterXfer.pu8Command        = NULL;
 *     sMasterXfer.u8CommandSize     = 0;
 *     sMasterXfer.pData             = master_txbuff;
 *     sMasterXfer.u16DataSize       = 10;
 *     sMasterXfer.u8ControlFlagMask = kLPI2C_TransferStartStopFlag;
 *     LPI2C_MasterTransferBlocking(LPI2C1, &sMasterXfer);
 *     sMasterXfer.eDirection = kLPI2C_Read;
 *     sMasterXfer.pData = master_rxbuff;
 *     LPI2C_MasterTransferBlocking(LPI2C1, &sMasterXfer);
 *   @endcode
 *
 *   + Transactional layer NonBlocking Transfer
 *   @code
 *     lpi2c_master_transfer_handle_t g_m_handle;
 *     static void lpi2c_master_callback(lpi2c_master_transfer_handle_t *psHandle)
 *     {
 *         g_MasterCompletionFlag = true;
 *     }
 *
 *     App_Function
 *     {
 *       lpi2c_master_config_t sMasterConfig = {0};
 *       lpi2c_master_transfer_t sMasterXfer = {0};
 *       uint8_t master_txbuff[10] = {0};
 *       uint8_t master_rxbuff[10] = {0};
 *       LPI2C_MasterGetDefaultConfig(&sMasterConfig, LPI2C_MASTER_CLOCK_FREQUENCY);
 *       LPI2C_MasterInit(LPI2C1, &sMasterConfig);
 *       LPI2C_MasterTransferCreateHandle(LPI2C1, &g_m_handle, lpi2c_master_callback, NULL);
 *       sMasterXfer.u8SlaveAddress    = I2C_MASTER_SLAVE_ADDR_7BIT;
 *       sMasterXfer.eDirection        = kLPI2C_Write;
 *       sMasterXfer.pu8Command        = NULL;
 *       sMasterXfer.u8CommandSize     = 0;
 *       sMasterXfer.pData             = master_txbuff;
 *       sMasterXfer.u16DataSize       = 10;
 *       sMasterXfer.u8ControlFlagMask = kLPI2C_TransferStartStopFlag;
 *       LPI2C_MasterTransferNonBlocking(&g_m_handle, &sMasterXfer);
 *       while (!g_MasterCompletionFlag)
 *       {
 *       }
 *     }
 *   @endcode
 *
 * <b>Slave Operation:</b>
 *   + Functional layer
 *   @code
 *     LPI2C_SlaveGetDefaultConfig(&sSlaveConfig, LPI2C_SLAVE_CLOCK_FREQUENCY);
 *     sSlaveConfig.u8Address0 = I2C_MASTER_SLAVE_ADDR_7BIT;
 *     LPI2C_SlaveInit(LPI2C1, &sSlaveConfig);
 *     while (!(LPI2C_SlaveGetStatusFlags(LPI2C1) & kLPI2C_SlaveAddressValidInterruptFlag))
 *     {
 *     }
 *     LPI2C_SlaveGetReceivedAddress(LPI2C1);
 *     LPI2C_SlaveReceive(LPI2C1, g_slave_buff, 10, 0);
 *     while (!(LPI2C_SlaveGetStatusFlags(LPI2C1) & kLPI2C_SlaveAddressValidInterruptFlag))
 *     {
 *     }
 *     LPI2C_SlaveGetReceivedAddress(LPI2C1);
 *     LPI2C_SlaveSend(LPI2C1, &g_slave_buff[2], g_slave_buff[1], 0);
 *   @endcode
 *
 *   + Transactional layer
 *   @code
 *     volatile bool g_SlaveCompletionFlag = false;
 *     lpi2c_slave_transfer_handle_t g_s_handle = {0};
 *
 *     static void lpi2c_slave_callback(lpi2c_slave_transfer_handle_t *psHandle)
 *     {
 *         switch (LPI2C_GET_SLAVE_TRANSFER_EVENT(psHandle))
 *         {
 *             case kLPI2C_SlaveAddressMatchEvent:
 *                 LPI2C_GET_SLAVE_TRANSFER_DATA_POINTER(psHandle) = NULL;
 *                 LPI2C_GET_SLAVE_TRANSFER_DATASIZE(psHandle) = 0;
 *                 break;
 *             case kLPI2C_SlaveTransmitEvent:
 *                 LPI2C_GET_SLAVE_TRANSFER_DATA_POINTER(psHandle) = &g_slave_buff[2];
 *                 LPI2C_GET_SLAVE_TRANSFER_DATASIZE(psHandle) = g_slave_buff[1];
 *                 break;
 *             case kLPI2C_SlaveReceiveEvent:
 *                 LPI2C_GET_SLAVE_TRANSFER_DATA_POINTER(psHandle) = g_slave_buff;
 *                 LPI2C_GET_SLAVE_TRANSFER_DATASIZE(psHandle) = I2C_DATA_LENGTH;
 *                 break;
 *             case kLPI2C_SlaveCompletionEvent:
 *                 g_SlaveCompletionFlag = true;
 *                 LPI2C_GET_SLAVE_TRANSFER_DATA_POINTER(psHandle) = NULL;
 *                 LPI2C_GET_SLAVE_TRANSFER_DATASIZE(psHandle) = 0;
 *                 break;
 *             default:
 *                 g_SlaveCompletionFlag = false;
 *                 break;
 *         }
 *     }
 *
 *     App_Function
 *     {
 *       lpi2c_slave_config_t sSlaveConfig;
 *       LPI2C_SlaveGetDefaultConfig(&sSlaveConfig, LPI2C_SLAVE_CLOCK_FREQUENCY);
 *       sSlaveConfig.u8Address0 = I2C_MASTER_SLAVE_ADDR_7BIT;
 *       LPI2C_SlaveInit(LPI2C1, &sSlaveConfig);
 *       LPI2C_SlaveTransferCreateHandle(LPI2C1, &g_s_handle, lpi2c_slave_callback, NULL);
 *       LPI2C_SlaveTransferNonBlocking(&g_s_handle, kLPI2C_SlaveCompletionEvent |
 *                                      kLPI2C_SlaveAddressMatchEvent);
 *       while (!g_SlaveCompletionFlag)
 *       {
 *       }
 *     }
 *   @endcode
 *
 *  EXCEPTION: SMBus is not supported in this driver.
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Clock enable/disable controlled by driver or not. */
#ifndef FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0U
#endif

/*! @brief Retry times for waiting flag. */
#ifndef I2C_RETRY_TIMES
#define I2C_RETRY_TIMES 0U /* Define to zero means keep waiting until the flag is assert/deassert. */
#endif

/*! @brief Control whether to use SMBus features. */
#ifndef I2C_SMBUS_ENABLE
#define I2C_SMBUS_ENABLE 0U /* Default defines to zero, driver uses simple I2C transfer. */
#endif

/* ================================================ Callback Macro ================================================== */
#define LPI2C_GET_TRANSFER_COMPLETION_STATUS(psHandle) (psHandle)->completionStatus
#define LPI2C_GET_TRANSFER_USER_DATA(psHandle)         (psHandle)->pUserData

#define LPI2C_GET_SLAVE_TRANSFER_EVENT(psHandle)        (psHandle)->sTransfer.eEvent
#define LPI2C_GET_SLAVE_TRANSFER_DATA_POINTER(psHandle) (psHandle)->sTransfer.pu8Data
#define LPI2C_GET_SLAVE_TRANSFER_DATASIZE(psHandle)     (psHandle)->sTransfer.u16DataSize
#define LPI2C_GET_SLAVE_TRANSFERRED_COUNT(psHandle)     (psHandle)->u16TransferredCount
/* ========================================== End of Callback Macro ========================================== */

/*! @brief LPI2C status return codes. */
enum
{
    kStatus_LPI2C_Busy = MAKE_STATUS(kStatusGroup_LPI2C, 0), /*!< The master is already performing a transfer. */
    kStatus_LPI2C_Idle = MAKE_STATUS(kStatusGroup_LPI2C, 1), /*!< The slave driver is idle. */
    kStatus_LPI2C_Nak  = MAKE_STATUS(kStatusGroup_LPI2C, 2), /*!< The slave device sent a NAK in response to a byte. */
    kStatus_LPI2C_FifoError       = MAKE_STATUS(kStatusGroup_LPI2C, 3), /*!< FIFO under run or overrun. */
    kStatus_LPI2C_BitError        = MAKE_STATUS(kStatusGroup_LPI2C, 4), /*!< Transferred bit was not seen on the bus. */
    kStatus_LPI2C_ArbitrationLost = MAKE_STATUS(kStatusGroup_LPI2C, 5), /*!< Arbitration lost error. */
    kStatus_LPI2C_PinLowTimeout =
        MAKE_STATUS(kStatusGroup_LPI2C, 6), /*!< SCL or SDA were held low longer than the timeout. */
    kStatus_LPI2C_NoTransferInProgress =
        MAKE_STATUS(kStatusGroup_LPI2C, 7), /*!< Attempt to abort a transfer when one is not in progress. */
    kStatus_LPI2C_DmaRequestFail = MAKE_STATUS(kStatusGroup_LPI2C, 8), /*!< DMA request failed. */
    kStatus_LPI2C_Timeout        = MAKE_STATUS(kStatusGroup_LPI2C, 9), /*!< Timeout polling status flags. */
#if I2C_SMBUS_ENABLE
    /*!< Detected NACK for PEC byte in transmit, or received PEC doesn't match received data CRC value. */
    kStatus_LPI2C_Pec_Error = MAKE_STATUS(kStatusGroup_LPI2C, 10),
#endif
};

/* ---------------------------------------- Hardware Status Flags Sub-group ----------------------------------------- */
/*! @name Hardware Status Flags Sub-group */
/*! @{ */

/*!
 * @brief LPI2C master peripheral flags.
 *
 * The following status register flags can be cleared:
 * - #kLPI2C_MasterEndOfPacketInterruptFlag
 * - #kLPI2C_MasterStopDetectInterruptFlag
 * - #kLPI2C_MasterNackDetectInterruptFlag
 * - #kLPI2C_MasterArbitrationLostInterruptFlag
 * - #kLPI2C_MasterFifoErrInterruptFlag
 * - #kLPI2C_MasterPinLowTimeoutInterruptFlag
 * - #kLPI2C_MasterDataMatchInterruptFlag
 *
 * All flags except #kLPI2C_MasterBusyFlag and #kLPI2C_MasterBusBusyFlag can be enabled as
 * interrupts.
 *
 * @note These enums are meant to be OR'd together to form a bit mask.
 */
enum _lpi2c_master_status_flags
{
    kLPI2C_MasterTxReadyInterruptFlag         = LPI2C_MSR_TDF_MASK,  /*!< Transmit data interrupt flag */
    kLPI2C_MasterRxReadyInterruptFlag         = LPI2C_MSR_RDF_MASK,  /*!< Receive data interrupt flag */
    kLPI2C_MasterEndOfPacketInterruptFlag     = LPI2C_MSR_EPF_MASK,  /*!< End Packet interrupt flag */
    kLPI2C_MasterStopDetectInterruptFlag      = LPI2C_MSR_SDF_MASK,  /*!< Stop detect interrupt flag */
    kLPI2C_MasterNackDetectInterruptFlag      = LPI2C_MSR_NDF_MASK,  /*!< NACK detect interrupt flag */
    kLPI2C_MasterArbitrationLostInterruptFlag = LPI2C_MSR_ALF_MASK,  /*!< Arbitration lost interrupt flag */
    kLPI2C_MasterFifoErrInterruptFlag         = LPI2C_MSR_FEF_MASK,  /*!< FIFO error interrupt flag */
    kLPI2C_MasterPinLowTimeoutInterruptFlag   = LPI2C_MSR_PLTF_MASK, /*!< Pin low timeout interrupt flag */
    kLPI2C_MasterDataMatchInterruptFlag       = LPI2C_MSR_DMF_MASK,  /*!< Data match interrupt flag */
    kLPI2C_MasterBusyFlag                     = LPI2C_MSR_MBF_MASK,  /*!< Master busy flag */
    kLPI2C_MasterBusBusyFlag                  = LPI2C_MSR_BBF_MASK,  /*!< Bus busy flag */
    /*!< All flags */
    kLPI2C_MasterStatusAllFlags =
        (kLPI2C_MasterTxReadyInterruptFlag | kLPI2C_MasterRxReadyInterruptFlag | kLPI2C_MasterEndOfPacketInterruptFlag |
         kLPI2C_MasterStopDetectInterruptFlag | kLPI2C_MasterNackDetectInterruptFlag |
         kLPI2C_MasterArbitrationLostInterruptFlag | kLPI2C_MasterFifoErrInterruptFlag |
         kLPI2C_MasterPinLowTimeoutInterruptFlag | kLPI2C_MasterDataMatchInterruptFlag | kLPI2C_MasterBusyFlag |
         kLPI2C_MasterBusBusyFlag),

    /*! All flags which are cleared by the driver upon starting a transfer. */
    kLPI2C_MasterClearInterruptFlags = kLPI2C_MasterEndOfPacketInterruptFlag | kLPI2C_MasterStopDetectInterruptFlag |
                                       kLPI2C_MasterNackDetectInterruptFlag |
                                       kLPI2C_MasterArbitrationLostInterruptFlag | kLPI2C_MasterFifoErrInterruptFlag |
                                       kLPI2C_MasterPinLowTimeoutInterruptFlag | kLPI2C_MasterDataMatchInterruptFlag,
    /*! IRQ sources enabled by the non-blocking transactional API. */
    kLPI2C_MasterIrqFlags = kLPI2C_MasterArbitrationLostInterruptFlag | kLPI2C_MasterTxReadyInterruptFlag |
                            kLPI2C_MasterRxReadyInterruptFlag | kLPI2C_MasterStopDetectInterruptFlag |
                            kLPI2C_MasterNackDetectInterruptFlag | kLPI2C_MasterPinLowTimeoutInterruptFlag |
                            kLPI2C_MasterFifoErrInterruptFlag,
    /*! Errors to check for. */
    kLPI2C_MasterErrorInterruptFlags = kLPI2C_MasterNackDetectInterruptFlag |
                                       kLPI2C_MasterArbitrationLostInterruptFlag | kLPI2C_MasterFifoErrInterruptFlag |
                                       kLPI2C_MasterPinLowTimeoutInterruptFlag,
};

/*!
 * @brief LPI2C slave peripheral flags.
 *
 * The following status register flags can be cleared:
 * - #kLPI2C_SlaveRepeatedStartDetectInterruptFlag
 * - #kLPI2C_SlaveStopDetectInterruptFlag
 * - #kLPI2C_SlaveBitErrInterruptFlag
 * - #kLPI2C_SlaveFifoErrInterruptFlag
 *
 * All flags except #kLPI2C_SlaveBusyFlag and #kLPI2C_SlaveBusBusyFlag can be enabled as
 * interrupts.
 *
 * @note These enumerations are meant to be OR'd together to form a bit mask.
 */
enum _lpi2c_slave_status_flags
{
    kLPI2C_SlaveTxReadyInterruptFlag             = LPI2C_SSR_TDF_MASK,  /*!< Transmit data interrupt flag */
    kLPI2C_SlaveRxReadyInterruptFlag             = LPI2C_SSR_RDF_MASK,  /*!< Receive data interrupt flag */
    kLPI2C_SlaveAddressValidInterruptFlag        = LPI2C_SSR_AVF_MASK,  /*!< Address valid interrupt flag */
    kLPI2C_SlaveTransmitAckInterruptFlag         = LPI2C_SSR_TAF_MASK,  /*!< Transmit ACK interrupt flag */
    kLPI2C_SlaveRepeatedStartDetectInterruptFlag = LPI2C_SSR_RSF_MASK,  /*!< Repeated start detect interrupt flag */
    kLPI2C_SlaveStopDetectInterruptFlag          = LPI2C_SSR_SDF_MASK,  /*!< Stop detect interrupt flag */
    kLPI2C_SlaveBitErrInterruptFlag              = LPI2C_SSR_BEF_MASK,  /*!< Bit error interrupt flag */
    kLPI2C_SlaveFifoErrInterruptFlag             = LPI2C_SSR_FEF_MASK,  /*!< FIFO error interrupt flag */
    kLPI2C_SlaveAddressMatch0InterruptFlag       = LPI2C_SSR_AM0F_MASK, /*!< Address match 0 interrupt flag */
    kLPI2C_SlaveAddressMatch1InterruptFlag       = LPI2C_SSR_AM1F_MASK, /*!< Address match 1 interrupt flag */
    kLPI2C_SlaveGeneralCallInterruptFlag         = LPI2C_SSR_GCF_MASK,  /*!< General call interrupt flag */
    kLPI2C_SlaveSmbusAlertRespInterruptFlag      = LPI2C_SSR_SARF_MASK, /*!< SMBus alert response interrupt flag */
    kLPI2C_SlaveBusyFlag                         = LPI2C_SSR_SBF_MASK,  /*!< Master busy flag */
    kLPI2C_SlaveBusBusyFlag                      = LPI2C_SSR_BBF_MASK,  /*!< Bus busy flag */
    /*!< All flags */
    kLPI2C_SlaveStatusAllFlags =
        (kLPI2C_SlaveTxReadyInterruptFlag | kLPI2C_SlaveRxReadyInterruptFlag | kLPI2C_SlaveAddressValidInterruptFlag |
         kLPI2C_SlaveTransmitAckInterruptFlag | kLPI2C_SlaveRepeatedStartDetectInterruptFlag |
         kLPI2C_SlaveStopDetectInterruptFlag | kLPI2C_SlaveBitErrInterruptFlag | kLPI2C_SlaveFifoErrInterruptFlag |
         kLPI2C_SlaveAddressMatch0InterruptFlag | kLPI2C_SlaveAddressMatch1InterruptFlag |
         kLPI2C_SlaveGeneralCallInterruptFlag | kLPI2C_SlaveSmbusAlertRespInterruptFlag | kLPI2C_SlaveBusyFlag |
         kLPI2C_SlaveBusBusyFlag),
    /*! All flags which are cleared by the driver upon starting a transfer. */
    kLPI2C_SlaveClearInterruptFlags = kLPI2C_SlaveRepeatedStartDetectInterruptFlag |
                                      kLPI2C_SlaveStopDetectInterruptFlag | kLPI2C_SlaveBitErrInterruptFlag |
                                      kLPI2C_SlaveFifoErrInterruptFlag,
    /*! IRQ sources enabled by the non-blocking transactional API. */
    kLPI2C_SlaveIrqFlags = kLPI2C_SlaveTxReadyInterruptFlag | kLPI2C_SlaveRxReadyInterruptFlag |
                           kLPI2C_SlaveStopDetectInterruptFlag | kLPI2C_SlaveRepeatedStartDetectInterruptFlag |
                           kLPI2C_SlaveFifoErrInterruptFlag | kLPI2C_SlaveBitErrInterruptFlag |
                           kLPI2C_SlaveTransmitAckInterruptFlag | kLPI2C_SlaveAddressValidInterruptFlag,
    /*! Errors to check for. */
    kLPI2C_SlaveErrorInterruptFlags = kLPI2C_SlaveFifoErrInterruptFlag | kLPI2C_SlaveBitErrInterruptFlag,
};

/*! @} */

/* ----------------------------------- End of Hardware Status Flags Sub-group ------------------------------------ */

/* ---------------------------------------- Module Init/Deinit Sub-group ----------------------------------------- */
/*! @name Module Init/Deinit Sub-group */
/*! @{ */

/*!
 * @brief Structure with settings to initialize the LPI2C master module.
 *
 * This structure holds configuration settings for the LPI2C peripheral. To initialize this
 * structure to reasonable defaults, call the LPI2C_MasterGetDefaultConfig() function and
 * pass a pointer to your configuration structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _lpi2c_master_config
{
    bool bEnableMaster;      /*!< Whether to enable master mode. */
    bool bEnableDoze;        /*!< Whether master is enabled in doze mode. */
    bool bDebugEnable;       /*!< Enable transfers to continue when halted in debug mode. */
    bool bIgnoreAck;         /*!< Whether to ignore ACK/NACK. */
    uint16_t ePinConfig : 5; /*!< The pin configuration option chosen from @ref lpi2c_master_pin_config_t. */
    struct
    {
        bool bEnable;             /*!< Whether to enable host request. */
        uint16_t eSource : 3;     /*!< Host request source chosen from @ref lpi2c_host_request_source_t. */
        uint16_t ePolarity : 3;   /*!< Host request pin polarity chosen from @ref lpi2c_host_request_polarity_t. */
    } hostRequest;                /*!< Host request options. */
    uint32_t u32SrcClockHz;       /*!< Frequency in Hertz of the LPI2C functional clock. */
    uint32_t u32BaudRateBps;      /*!< Desired baud rate in Hertz. */
    uint32_t u32BusIdleTimeoutNs; /*!< Bus idle timeout in nanoseconds. Set to 0 to disable. */
    uint32_t u32PinLowTimeoutNs;  /*!< Pin low timeout in nanoseconds. Set to 0 to disable. */
    uint32_t u32SdaGlitchFilterWidthNs; /*!< Width in nanoseconds of glitch filter on SDA pin. Set to 0 to disable. */
    uint32_t u32SclGlitchFilterWidthNs; /*!< Width in nanoseconds of glitch filter on SCL pin. Set to 0 to disable. */
} lpi2c_master_config_t;

/*!
 * @brief Structure with settings to initialize the LPI2C slave module.
 *
 * This structure holds configuration settings for the LPI2C slave peripheral. To initialize this
 * structure to reasonable defaults, call the LPI2C_SlaveGetDefaultConfig() function and
 * pass a pointer to your configuration structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _lpi2c_slave_config
{
    bool bEnableSlave;      /*!< Enable slave mode. */
    bool bFilterDozeEnable; /*!< Enable digital glitch filter in doze mode. */
    bool bFilterEnable;     /*!< Enable digital glitch filter. */
    bool bIgnoreAck;        /*!< Continue transfers after a NACK is detected. */
    struct
    {
        bool bEnableAck;     /*!< Enables SCL clock stretching during slave-transmit address byte(s)
                                        and slave-receiver address and data byte(s) to allow software to
                                        write the Transmit ACK Register before the ACK or NACK is transmitted.
                                        Clock stretching occurs when transmitting the 9th bit. When
                                        enableAckSCLStall is enabled, there is no need to set either
                                        enableRxDataSCLStall or enableAddressSCLStall. */
        bool bEnableTx;      /*!< Enables SCL clock stretching when the transmit data flag is set
                                         during a slave-transmit transfer. */
        bool bEnableRx;      /*!< Enables SCL clock stretching when receive data flag is set during
                                         a slave-receive transfer. */
        bool bEnableAddress; /*!< Enables SCL clock stretching when the address valid flag is asserted. */
    } sSclStall;
    bool bEnableGeneralCall;            /*!< Enable general call address matching. */
    bool bEnableSmbusAlert;             /*!< Enable SMBus Alert. */
    bool bEnableReceivedAddressRead;    /*!< Enable reading the address received address as the first byte of data. */
    uint16_t eAddressMatchMode : 3;     /*!< Address matching options chosen from @ref lpi2c_slave_address_match_t. */
    uint16_t u16Address0;               /*!< Slave's 7-bit address. */
    uint16_t u16Address1;               /*!< Alternate slave 7-bit address. */
    uint32_t u32SdaGlitchFilterWidthNs; /*!< Width in nanoseconds of the digital filter on the SDA signal. */
    uint32_t u32SclGlitchFilterWidthNs; /*!< Width in nanoseconds of the digital filter on the SCL signal. */
    uint32_t u32DataValidDelayNs;       /*!< Width in nanoseconds of the data valid delay. */
    uint32_t u32ClockHoldTimeNs;        /*!< Width in nanoseconds of the clock hold time. */
    uint32_t u32SrcClockHz;             /*!< Frequency in Hertz of the LPI2C functional clock. */
} lpi2c_slave_config_t;

/*!
 * @brief Structure with settings to initialize the LPI2C module.
 *
 * This structure holds configuration settings for the LPI2C peripheral. To initialize this
 * structure to reasonable defaults, call the @ref LPI2C_GetDefaultConfig function and
 * pass a pointer to your configuration structure instance.
 *
 * The configuration structure can be made constant so it resides in flash.
 */
typedef struct _lpi2c_config
{
    /*!< Master configuration. */
    bool bEnableMaster;      /*!< Whether to enable master mode. */
    bool bEnableDoze;        /*!< Whether master is enabled in doze mode. */
    bool bDebugEnable;       /*!< Enable transfers to continue when halted in debug mode. */
    bool bMasterIgnoreAck;   /*!< Whether to ignore ACK/NACK. */
    uint16_t ePinConfig : 5; /*!< The pin configuration option chosen from @ref lpi2c_master_pin_config_t. */
    struct
    {
        bool bEnable;             /*!< Whether to enable host request. */
        uint16_t eSource : 3;     /*!< Host request source chosen from @ref lpi2c_host_request_source_t. */
        uint16_t ePolarity : 3;   /*!< Host request pin polarity chosen from @ref lpi2c_host_request_polarity_t. */
    } hostRequest;                /*!< Host request options. */
    uint32_t u32BaudRateBps;      /*!< Desired baud rate in Hertz. */
    uint32_t u32BusIdleTimeoutNs; /*!< Bus idle timeout in nanoseconds. Set to 0 to disable. */
    uint32_t u32PinLowTimeoutNs;  /*!< Pin low timeout in nanoseconds. Set to 0 to disable. */
    uint32_t
        u32MasterSdaGlitchFilterWidthNs; /*!< Width in nanoseconds of glitch filter on SDA pin. Set to 0 to disable. */
    uint32_t
        u32MasterSclGlitchFilterWidthNs; /*!< Width in nanoseconds of glitch filter on SCL pin. Set to 0 to disable. */

    /*!< Slave configuration. */
    bool bEnableSlave;      /*!< Enable slave mode. */
    bool bFilterDozeEnable; /*!< Enable digital glitch filter in doze mode. */
    bool bFilterEnable;     /*!< Enable digital glitch filter. */
    bool bSlaveIgnoreAck;   /*!< Continue transfers after a NACK is detected. */
    struct
    {
        bool bEnableAck;     /*!< Enables SCL clock stretching during slave-transmit address byte(s)
                                        and slave-receiver address and data byte(s) to allow software to
                                        write the Transmit ACK Register before the ACK or NACK is transmitted.
                                        Clock stretching occurs when transmitting the 9th bit. When
                                        enableAckSCLStall is enabled, there is no need to set either
                                        enableRxDataSCLStall or enableAddressSCLStall. */
        bool bEnableTx;      /*!< Enables SCL clock stretching when the transmit data flag is set
                                         during a slave-transmit transfer. */
        bool bEnableRx;      /*!< Enables SCL clock stretching when receive data flag is set during
                                         a slave-receive transfer. */
        bool bEnableAddress; /*!< Enables SCL clock stretching when the address valid flag is asserted. */
    } sSclStall;
    bool bEnableGeneralCall;         /*!< Enable general call address matching. */
    bool bEnableSmbusAlert;          /*!< Enable SMBus Alert. */
    bool bEnableReceivedAddressRead; /*!< Enable reading the address received address as the first byte of data. */
    uint16_t eAddressMatchMode : 3;  /*!< Address matching options chosen from @ref lpi2c_slave_address_match_t. */
    uint16_t u16Address0;            /*!< Slave's 7-bit address. */
    uint16_t u16Address1;            /*!< Alternate slave 7-bit address. */
    uint32_t u32SlaveSdaGlitchFilterWidthNs; /*!< Width in nanoseconds of the digital filter on the SDA signal. */
    uint32_t u32SlaveSclGlitchFilterWidthNs; /*!< Width in nanoseconds of the digital filter on the SCL signal. */
    uint32_t u32DataValidDelayNs;            /*!< Width in nanoseconds of the data valid delay. */
    uint32_t u32ClockHoldTimeNs;             /*!< Width in nanoseconds of the clock hold time. */
    uint32_t u32SrcClockHz;                  /*!< Frequency in Hertz of the LPI2C functional clock. */
} lpi2c_config_t;

/*! @} */

/* -------------------------------------- End of Module Init/Deinit Sub-group -------------------------------------- */

/* ------------------------------------- Master Module Configuration Sub-group ------------------------------------- */
/*! @name Master Module Configuration Sub-group */
/*! @{ */

/*! @brief LPI2C pin configuration. */
typedef enum _lpi2c_master_pin_config
{
    kLPI2C_2PinOpenDrain  = 0x0U, /*!< LPI2C Configured for 2-pin open drain mode */
    kLPI2C_2PinOutputOnly = 0x1U, /*!< LPI2C Configured for 2-pin output only mode (ultra-fast mode) */
    kLPI2C_2PinPushPull   = 0x2U, /*!< LPI2C Configured for 2-pin push-pull mode */
    kLPI2C_4PinPushPull   = 0x3U, /*!< LPI2C Configured for 4-pin push-pull mode */
    kLPI2C_2PinOpenDrainWithSeparateSlave =
        0x4U, /*!< LPI2C Configured for 2-pin open drain mode with separate LPI2C slave */
    kLPI2C_2PinOutputOnlyWithSeparateSlave =
        0x5U, /*!< LPI2C Configured for 2-pin output only mode(ultra-fast mode) with separate LPI2C slave */
    kLPI2C_2PinPushPullWithSeparateSlave =
        0x6U, /*!< LPI2C Configured for 2-pin push-pull mode with separate LPI2C slave */
    kLPI2C_4PinPushPullWithInvertedOutput = 0x7U /*!< LPI2C Configured for 4-pin push-pull mode(inverted outputs) */
} lpi2c_master_pin_config_t;

/*! @brief LPI2C master host request selection. */
typedef enum _lpi2c_host_request_source
{
    kLPI2C_HostRequestExternalPin  = 0x0U, /*!< Select the LPI2C_HREQ pin as the host request input */
    kLPI2C_HostRequestInputTrigger = 0x1U, /*!< Select the input trigger as the host request input */
} lpi2c_host_request_source_t;

/*! @brief LPI2C master host request pin polarity configuration. */
typedef enum _lpi2c_host_request_polarity
{
    kLPI2C_HostRequestPinActiveLow  = 0x0U, /*!< Configure the LPI2C_HREQ pin active low */
    kLPI2C_HostRequestPinActiveHigh = 0x1U  /*!< Configure the LPI2C_HREQ pin active high */
} lpi2c_host_request_polarity_t;

/*! @brief LPI2C master data match configuration modes. */
typedef enum _lpi2c_data_match_config_mode
{
    kLPI2C_MatchDisabled       = 0x0U, /*!< LPI2C Match Disabled */
    kLPI2C_1stWordEqualsM0OrM1 = 0x2U, /*!< LPI2C Match Enabled and 1st data word equals MATCH0 OR MATCH1 */
    kLPI2C_AnyWordEqualsM0OrM1 = 0x3U, /*!< LPI2C Match Enabled and any data word equals MATCH0 OR MATCH1 */
    kLPI2C_1stWordEqualsM0And2ndWordEqualsM1 =
        0x4U, /*!< LPI2C Match Enabled and 1st data word equals MATCH0, 2nd data equals MATCH1 */
    kLPI2C_AnyWordEqualsM0AndNextWordEqualsM1 =
        0x5U, /*!< LPI2C Match Enabled and any data word equals MATCH0, next data equals MATCH1 */
    kLPI2C_1stWordAndM1EqualsM0AndM1 =
        0x6U, /*!< LPI2C Match Enabled and 1st data word and MATCH0 equals MATCH0 and MATCH1 */
    kLPI2C_AnyWordAndM1EqualsM0AndM1 =
        0x7U /*!< LPI2C Match Enabled and any data word and MATCH0 equals MATCH0 and MATCH1 */
} lpi2c_data_match_config_mode_t;

/*! @brief LPI2C master data match configuration structure. */
typedef struct _lpi2c_match_config
{
    lpi2c_data_match_config_mode_t eMatchMode; /*!< Data match configuration setting. */
    bool bRxDataMatchOnly; /*!< When set to true, received data is ignored until a successful match. */
    uint8_t u8Match0;      /*!< Match value 0. */
    uint8_t u8Match1;      /*!< Match value 1. */
} lpi2c_data_match_config_t;

/*! @} */

/* --------------------------------- End of Master Module Configuration Sub-group --------------------------------- */

/* ------------------------------------- Slave Module Configuration Sub-group ------------------------------------- */
/*! @name Slave Module Configuration Sub-group */
/*! @{ */

/*! @brief LPI2C slave address match options. */
typedef enum _lpi2c_slave_address_match
{
    kLPI2C_Match7BitAddress0                 = 0U, /*!< Match only 7 bit address 0. */
    kLPI2C_Match10BitAddress0                = 1U, /*!< Match only 10 bit address 0. */
    kLPI2C_Match7BitAddress0Or7BitAddress1   = 2U, /*!< Match either 7 bit address 0 or 7 bit address 1. */
    kLPI2C_Match10BitAddress0Or10BitAddress1 = 3U, /*!< Match either 10 bit address 0 or 10 bit address 1. */
    kLPI2C_Match7BitAddress0Or10BitAddress1  = 4U, /*!< Match either 7 bit address 0 or 10 bit address 1. */
    kLPI2C_Match10BitAddress0Or7BitAddress1  = 5U, /*!< Match either 10 bit address 0 or 7 bit address 1. */
    kLPI2C_Match7BitAddress0Through7BitAddress1 =
        6U, /*!< Match a range of slave addresses from 7 bit address 0 through 7 bit address 1. */
    kLPI2C_Match10BitAddress0Through10BitAddress1 =
        7U, /*!< Match a range of slave addresses from 10 bit address 0 through 10 bit address 1. */
} lpi2c_slave_address_match_t;

/*! @} */

/* --------------------------------- End of Slave Module Configuration Sub-group ---------------------------------- */

/* ------------------------------------- Master Bus operations Sub-Group ------------------------------------------ */
/*! @name Master Bus operations Sub-Group */
/*! @{ */
/*! @brief Direction of master and slave transfers. */
typedef enum _lpi2c_data_direction
{
    kLPI2C_Write = 0U, /*!< Master transmit. */
    kLPI2C_Read  = 1U  /*!< Master receive. */
} lpi2c_data_direction_t;
/*! @} */
/* --------------------------------- End of Master Bus operations Sub-Group --------------------------------------- */

/* ---------------------------------------- Master Transfer Sub-group --------------------------------------------- */
/*! @name Master Transfer Sub-group */
/*! @{ */

/*!
 * @brief lpi2c_master_transfer_t forward definition.
 * @anchor lpi2c_master_transfer_t
 */
typedef struct _lpi2c_master_transfer lpi2c_master_transfer_t;

/*!
 * @brief lpi2c_master_transfer_handle_t forward definition.
 * @anchor lpi2c_master_transfer_handle_t
 */
typedef struct _lpi2c_master_transfer_handle lpi2c_master_transfer_handle_t;

/*!
 * @brief Master completion callback function pointer type.
 *
 * This callback is used only for the non-blocking master transfer API. Specify the callback you wish to use
 * in the call to LPI2C_MasterTransferCreateHandle().
 *
 * @param psHandle Pointer to the LPI2C master driver handle.
 */
typedef void (*lpi2c_master_transfer_callback_t)(lpi2c_master_transfer_handle_t *psHandle);

/*!
 * @brief Transfer option flags.
 *
 * @note These enumerations are intended to be OR'd together to form a bit mask of options for
 * the #_lpi2c_master_transfer::u8ControlFlagMask field.
 */
enum _lpi2c_master_transfer_control_flags
{
    kLPI2C_TransferStartStopFlag     = 0x00U, /*!< Transfer starts with a start signal, stops with a stop signal. */
    kLPI2C_TransferNoStartFlag       = 0x01U, /*!< Don't send a start condition, address, and sub address */
    kLPI2C_TransferRepeatedStartFlag = 0x02U, /*!< Send a repeated start condition */
    kLPI2C_TransferNoStopFlag        = 0x04U, /*!< Don't send a stop condition. */
};

/*!
 * @brief Non-blocking transfer descriptor structure.
 *
 * This structure is used to pass transaction parameters to the LPI2C_MasterTransferNonBlocking() API.
 */
struct _lpi2c_master_transfer
{
    uint8_t u8ControlFlagMask;         /*!< Bit mask of options for the transfer. See enumeration
                                          #_lpi2c_master_transfer_control_flags for available options. Set to 0 or
                                          #kLPI2C_TransferStartStopFlag for normal transfers. */
    uint16_t u8SlaveAddress;           /*!< The 7-bit slave address. */
    lpi2c_data_direction_t eDirection; /*!< Either #kLPI2C_Read or #kLPI2C_Write. */
    uint8_t *pu8Command;               /*!< Pointer to command code. */
    uint8_t u8CommandSize;             /*!< Length of sub address to send in bytes. */
    void *pData;                       /*!< Pointer to data to transfer. */
    uint16_t u16DataSize;              /*!< Number of bytes to transfer. */
};

/*!
 * @brief Driver handle for master non-blocking APIs.
 * @note The contents of this structure are private and subject to change.
 */
struct _lpi2c_master_transfer_handle
{
    LPI2C_Type *base;                                      /*!< The peripheral register address base. */
    uint8_t u8State;                                       /*!< Transfer state machine current state. */
    uint16_t u16RemainingBytes;                            /*!< Remaining byte count in current state. */
    uint8_t *pu8Buf;                                       /*!< Buffer pointer for current state. */
    uint16_t u16CommandBuffer[7];                          /*!< LPI2C command sequence. */
    lpi2c_master_transfer_t sTransfer;                     /*!< Copy of the current transfer info. */
    lpi2c_master_transfer_callback_t pfCompletionCallback; /*!< Callback function pointer. */
    status_t completionStatus; /*!< Master transfer complete status indicating how the transfer ends. */
    void *pUserData;           /*!< Application data passed to callback. */
};

/*! @} */

/* ------------------------------------ End of Master Transfer Sub-group ------------------------------------------ */

/* ----------------------------------------- Slave Transfer Sub-group --------------------------------------------- */
/*! @name Slave Transfer Sub-group */
/*! @{ */

/*!
 * @brief lpi2c_slave_transfer_t forward definition.
 * @anchor lpi2c_slave_transfer_t
 */
typedef struct _lpi2c_slave_transfer lpi2c_slave_transfer_t;

/*!
 * @brief lpi2c_slave_transfer_handle_t forward definition.
 * @anchor lpi2c_slave_transfer_handle_t
 */
typedef struct _lpi2c_slave_transfer_handle lpi2c_slave_transfer_handle_t;

/*!
 * @brief Slave event callback function pointer type.
 *
 * This callback is used only for the slave non-blocking transfer API. To install a callback,
 * use the LPI2C_SlaveSetCallback() function after you have created a handle.
 *
 * @param psHandle Pointer to the LPI2C slave driver handle.
 */
typedef void (*lpi2c_slave_transfer_callback_t)(lpi2c_slave_transfer_handle_t *psHandle);

/*!
 * @brief Set of events sent to the callback for non blocking slave transfers.
 *
 * These event enumerations are used for two related purposes. First, a bit mask created by OR'ing together
 * events is passed to LPI2C_SlaveTransferNonBlocking() in order to specify which events to enable.
 * Then, when the slave callback is invoked, it is passed the current event through its @a transfer
 * parameter.
 *
 * @note These enumerations are meant to be OR'd together to form a bit mask of events.
 */
typedef enum _lpi2c_slave_transfer_event
{
    kLPI2C_SlaveAddressMatchEvent = 0x01U,  /*!< Received the slave address after a start or repeated start. */
    kLPI2C_SlaveTransmitEvent     = 0x02U,  /*!< Callback is requested to provide data to transmit
                                                 (slave-transmitter role). */
    kLPI2C_SlaveReceiveEvent = 0x04U,       /*!< Callback is requested to provide a buffer in which to place received
                                                  data (slave-receiver role). */
    kLPI2C_SlaveTransmitAckEvent   = 0x08U, /*!< Callback needs to either transmit an ACK or NACK. */
    kLPI2C_SlaveRepeatedStartEvent = 0x10U, /*!< A repeated start was detected. */
    kLPI2C_SlaveCompletionEvent    = 0x20U, /*!< A stop was detected, completing the transfer. */

    /*! Bit mask of all available events. */
    kLPI2C_SlaveAllEvents = kLPI2C_SlaveAddressMatchEvent | kLPI2C_SlaveTransmitEvent | kLPI2C_SlaveReceiveEvent |
                            kLPI2C_SlaveTransmitAckEvent | kLPI2C_SlaveRepeatedStartEvent | kLPI2C_SlaveCompletionEvent,
} lpi2c_slave_transfer_event_t;

/*! @brief LPI2C slave transfer structure */
struct _lpi2c_slave_transfer
{
    uint8_t u8EventMask; /*!< Mask of enabled events, set correspond bit if user wants to handle this event. */
    lpi2c_slave_transfer_event_t eEvent; /*!< Reason the callback is being invoked lpi2c_slave_transfer_event_t. */
    uint16_t u16ReceivedAddress;         /*!< Matching address send by master. */
    uint8_t *pu8Data;                    /*!< Transfer buffer */
    uint16_t u16DataSize;                /*!< Transfer size */
    status_t completionStatus;    /*!< Success or error code describing how the transfer completed. Only applies for
                                     #kLPI2C_SlaveCompletionEvent. */
    uint16_t u16TransferredCount; /*!< Number of bytes actually transferred since start or last repeated start. */
};

/*!
 * @brief LPI2C slave handle structure.
 * @note The contents of this structure are private and subject to change.
 */
struct _lpi2c_slave_transfer_handle
{
    LPI2C_Type *base;                           /*!< The peripheral register address base. */
    lpi2c_slave_transfer_t sTransfer;           /*!< LPI2C slave transfer copy. */
    bool bIsBusy;                               /*!< Whether transfer is busy. */
    bool bWasTransmit;                          /*!< Whether the last transfer was a transmit. */
    uint8_t u8State;                            /*!< A transfer state maintained during transfer. */
    uint16_t u16TransferredCount;               /*!< Count of bytes transferred. */
    lpi2c_slave_transfer_callback_t pfCallback; /*!< Callback function called at transfer event. */
    void *pUserData;                            /*!< Callback parameter passed to callback. */
};

/*! @} */
/* ------------------------------------- End of Slave Transfer Sub-group ------------------------------------------ */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/* ========================================== Functional Group API List =========================================== */

/*! @name Module Init/Deinit Sub-group */
/*! @{ */

/*!
 * @brief Provides a default configuration for the LPI2C peripheral, including master and slave.
 *
 * This is an example:
 * @code
 *   lpi2c_config_t sConfig;
 *   LPI2C_GetDefaultConfig(&sConfig, u16SlaveAddress, u32SrcClockHz);
 *   sConfig.u32BaudRateBps = 100000U;
 *   LPI2C_Init(LPI2C0, &sConfig);
 * @endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the driver with LPI2C_Init().
 *
 * @param psConfig User provided configuration structure for default values. Refer to #lpi2c_config_t.
 * @param u16SlaveAddress Slave address raw value, driver will shift it.
 * @param u32SrcClockHz Frequency in Hertz of the LPI2C functional clock. Used to calculate the baud rate divisors,
 *      filter widths, and timeout periods.
 */
void LPI2C_GetDefaultConfig(lpi2c_config_t *psConfig, uint16_t u16SlaveAddress, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the LPI2C peripheral, including master and slave.
 *
 * This function enables the peripheral clock and initializes the LPI2C peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration. This function can enable master
 * and slave together. If only want to use one of them, please call LPI2C_MasterInit or LPI2C_SlaveInit.
 *
 * @note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enabled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the
 * API.
 *
 * @param base The LPI2C peripheral base address.
 * @param psConfig User provided peripheral configuration. Use LPI2C_GetDefaultConfig to get a set of
 * defaults that you can override.
 */
void LPI2C_Init(LPI2C_Type *base, const lpi2c_config_t *psConfig);

/*!
 * @brief Deinitializes the LPI2C peripheral, including master and slave.
 *
 * This function disables the LPI2C peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The LPI2C peripheral base address.
 */
void LPI2C_Deinit(LPI2C_Type *base);

/*!
 * @brief Provides a default configuration for the LPI2C master peripheral.
 *
 * This is an example:
 * @code
 *   lpi2c_master_config_t sConfig;
 *   LPI2C_MasterGetDefaultConfig(&sConfig, 12000000U);
 *   sConfig.u32BaudRateBps = 100000U;
 *   LPI2C_MasterInit(LPI2C1, &sConfig);
 * @endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the master driver with LPI2C_MasterInit().
 *
 * @param psMasterConfig User provided configuration structure for default values. Refer to #lpi2c_master_config_t.
 * @param u32SrcClockHz Frequency in Hertz of the LPI2C functional clock. Used to calculate the baud rate divisors,
 *      filter widths, and timeout periods.
 */
void LPI2C_MasterGetDefaultConfig(lpi2c_master_config_t *psMasterConfig, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the LPI2C master peripheral.
 *
 * This function enables the peripheral clock and initializes the LPI2C master peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration. User just needs to call this function
 * to enable LPI2C master if only use I2C master operation.
 *
 * @note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enabled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the
 * API.
 *
 * @param base The LPI2C peripheral base address.
 * @param psMasterConfig User provided peripheral configuration. Use LPI2C_MasterGetDefaultConfig() to get a set of
 * defaults that you can override.
 */
void LPI2C_MasterInit(LPI2C_Type *base, const lpi2c_master_config_t *psMasterConfig);

/*!
 * @brief Deinitializes the LPI2C master peripheral.
 *
 * This function disables the LPI2C master peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The LPI2C peripheral base address.
 */
void LPI2C_MasterDeinit(LPI2C_Type *base);

/*!
 * @brief Provides a default configuration for the LPI2C slave peripheral.
 *
 * This is an example:
 * @code
 *   lpi2c_slave_config_t sConfig;
 *   LPI2C_SlaveGetDefaultConfig(&sConfig, u16SlaveAddress, u32SrcClockHz);
 *   LPI2C_SlaveInit(LPI2C1, &sConfig);
 * @endcode
 *
 * After calling this function, override any settings to customize the configuration,
 * prior to initializing the master driver with LPI2C_SlaveInit(). Be sure to override at least the \a
 * u8Address0 member of the configuration structure with the desired slave address.
 *
 * @param psSlaveConfig User provided configuration structure that is set to default values. Refer to
 *      #lpi2c_slave_config_t.
 * @param u16SlaveAddress Slave address raw value, driver will shift it.
 * @param u32SrcClockHz Frequency in Hertz of the LPI2C functional clock. Used to calculate the filter widths,
 *      data valid delay, and clock hold time.
 */
void LPI2C_SlaveGetDefaultConfig(lpi2c_slave_config_t *psSlaveConfig, uint16_t u16SlaveAddress, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the LPI2C slave peripheral.
 *
 * This function enables the peripheral clock and initializes the LPI2C slave peripheral as described by the user
 * provided configuration. User just needs to call this function to enable LPI2C slave if only use I2C slave operation.
 *
 * @note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enabled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the
 * API.
 *
 * @param base The LPI2C peripheral base address.
 * @param psSlaveConfig User provided peripheral configuration. Use LPI2C_SlaveGetDefaultConfig() to get a set of
 * defaults that you can override.
 */
void LPI2C_SlaveInit(LPI2C_Type *base, const lpi2c_slave_config_t *psSlaveConfig);

/*!
 * @brief Deinitializes the LPI2C slave peripheral.
 *
 * This function disables the LPI2C slave peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * @param base The LPI2C peripheral base address.
 */
void LPI2C_SlaveDeinit(LPI2C_Type *base);

/*! @} */

/*! @name Hardware Status Flags Sub-group */
/*! @{ */

/*!
 * @brief Gets the LPI2C master status flags.
 *
 * A bit mask with the state of all LPI2C master status flags is returned. For each flag, the corresponding bit
 * in the return value is set if the flag is asserted.
 *
 * @param base The LPI2C peripheral base address.
 * @return State of the status flags:
 *         - 1: related status flag is set.
 *         - 0: related status flag is not set.
 * @see _lpi2c_master_status_flags
 */
static inline uint16_t LPI2C_MasterGetStatusFlags(LPI2C_Type *base)
{
    return base->MSR;
}

/*!
 * @brief Clears the LPI2C master status flag state.
 *
 * The following status register flags can be cleared:
 * - #kLPI2C_MasterEndOfPacketInterruptFlag
 * - #kLPI2C_MasterStopDetectInterruptFlag
 * - #kLPI2C_MasterNackDetectInterruptFlag
 * - #kLPI2C_MasterArbitrationLostInterruptFlag
 * - #kLPI2C_MasterFifoErrInterruptFlag
 * - #kLPI2C_MasterPinLowTimeoutInterruptFlag
 * - #kLPI2C_MasterDataMatchInterruptFlag
 *
 * Attempts to clear other flags has no effect.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16StatusFlags A bitmask of status flags that are to be cleared. The mask is composed of
 *  #_lpi2c_master_status_flags enumerators OR'd together. You may pass the result of a previous call to
 *  LPI2C_MasterGetStatusFlags().
 * @see _lpi2c_master_status_flags.
 */
static inline void LPI2C_MasterClearStatusFlags(LPI2C_Type *base, uint16_t u16StatusFlags)
{
    base->MSR = u16StatusFlags;
}

/*!
 * @brief Gets the LPI2C slave status flags.
 *
 * A bit mask with the state of all LPI2C slave status flags is returned. For each flag, the corresponding bit
 * in the return value is set if the flag is asserted.
 *
 * @param base The LPI2C peripheral base address.
 * @return State of the status flags:
 *         - 1: related status flag is set.
 *         - 0: related status flag is not set.
 * @see _lpi2c_slave_status_flags
 */
static inline uint16_t LPI2C_SlaveGetStatusFlags(LPI2C_Type *base)
{
    return base->SSR;
}

/*!
 * @brief Clears the LPI2C status flag state.
 *
 * The following status register flags can be cleared:
 * - #kLPI2C_SlaveRepeatedStartDetectInterruptFlag
 * - #kLPI2C_SlaveStopDetectInterruptFlag
 * - #kLPI2C_SlaveBitErrInterruptFlag
 * - #kLPI2C_SlaveFifoErrInterruptFlag
 *
 * Attempts to clear other flags has no effect.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16StatusFlags A bitmask of status flags that are to be cleared. The mask is composed of
 *  #_lpi2c_slave_status_flags enumerators OR'd together. You may pass the result of a previous call to
 *  LPI2C_SlaveGetStatusFlags().
 * @see _lpi2c_slave_status_flags.
 */
static inline void LPI2C_SlaveClearStatusFlags(LPI2C_Type *base, uint16_t u16StatusFlags)
{
    base->SSR = u16StatusFlags;
}

/*! @} */

/*! @name Interrupt Sub-group */
/*! @{ */

/*!
 * @brief Enables the LPI2C master interrupt requests.
 *
 * All flags except #kLPI2C_MasterBusyFlag and #kLPI2C_MasterBusBusyFlag can be enabled as
 * interrupts.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16Interrupts Bit mask of interrupts to enable. See #_lpi2c_master_status_flags for the set
 *      of constants that should be OR'd together to form the bit mask.
 */
static inline void LPI2C_MasterEnableInterrupts(LPI2C_Type *base, uint16_t u16Interrupts)
{
    base->MIER |= u16Interrupts;
}

/*!
 * @brief Disables the LPI2C master interrupt requests.
 *
 * All flags except #kLPI2C_MasterBusyFlag and #kLPI2C_MasterBusBusyFlag can be enabled as
 * interrupts.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16Interrupts Bit mask of interrupts to disable. See #_lpi2c_master_status_flags for the set
 *      of constants that should be OR'd together to form the bit mask.
 */
static inline void LPI2C_MasterDisableInterrupts(LPI2C_Type *base, uint16_t u16Interrupts)
{
    base->MIER &= ~u16Interrupts;
}

/*!
 * @brief Returns the set of currently enabled LPI2C master interrupt requests.
 *
 * @param base The LPI2C peripheral base address.
 * @return A bitmask composed of #_lpi2c_master_status_flags enumerators OR'd together to indicate the
 *      set of enabled interrupts.
 */
static inline uint16_t LPI2C_MasterGetEnabledInterrupts(LPI2C_Type *base)
{
    return base->MIER;
}

/*!
 * @brief Enables the LPI2C slave interrupt requests.
 *
 * All flags except #kLPI2C_SlaveBusyFlag and #kLPI2C_SlaveBusBusyFlag can be enabled as
 * interrupts.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16Interrupts Bit mask of interrupts to enable. See #_lpi2c_slave_status_flags for the set
 *      of constants that should be OR'd together to form the bit mask.
 */
static inline void LPI2C_SlaveEnableInterrupts(LPI2C_Type *base, uint16_t u16Interrupts)
{
    base->SIER |= u16Interrupts;
}

/*!
 * @brief Disables the LPI2C slave interrupt requests.
 *
 * All flags except #kLPI2C_SlaveBusyFlag and #kLPI2C_SlaveBusBusyFlag can be enabled as
 * interrupts.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16Interrupts Bit mask of interrupts to disable. See #_lpi2c_slave_status_flags for the set
 *      of constants that should be OR'd together to form the bit mask.
 */
static inline void LPI2C_SlaveDisableInterrupts(LPI2C_Type *base, uint16_t u16Interrupts)
{
    base->SIER &= ~u16Interrupts;
}

/*!
 * @brief Returns the set of currently enabled LPI2C slave interrupt requests.
 * @param base The LPI2C peripheral base address.
 * @return A bitmask composed of #_lpi2c_slave_status_flags enumerators OR'd together to indicate the
 *      set of enabled interrupts.
 */
static inline uint16_t LPI2C_SlaveGetEnabledInterrupts(LPI2C_Type *base)
{
    return base->SIER;
}

/*! @} */

/*! @name Master Module Configuration Sub-group */
/*! @{ */

/*!
 * @brief Sets the I2C bus frequency for master transactions.
 *
 * The LPI2C master is automatically disabled and re-enabled as necessary to configure the baud
 * rate. Do not call this function during a transfer, or the transfer is aborted.
 *
 * @note Please note that the second parameter is the clock frequency of LPI2C module, the third
 * parameter means user configured bus baudrate, this implementation is different from other I2C drivers
 * which use baudrate configuration as second parameter and source clock frequency as third parameter.
 *
 * @param base The LPI2C peripheral base address.
 * @param u32SrcClockHz LPI2C functional clock frequency in Hertz.
 * @param u32BaudRateBps Requested bus frequency in Hertz.
 */
void LPI2C_MasterSetBaudRate(LPI2C_Type *base, uint32_t u32SrcClockHz, uint32_t u32BaudRateBps);

/*!
 * @brief Sets the LPI2C master glitch filter width.
 *
 * After the LPI2C module is initialized as master, user can call this function to change the glitch filter width.
 *
 * @param base The LPI2C peripheral base address.
 * @param u32SdaFilterWidthNs The SDA glitch filter length in nano seconds.
 * @param u32SclFilterWidthNs The SCL glitch filter length in nano seconds.
 * @param u32SrcClockHz LPI2C peripheral clock frequency in Hz
 */
void LPI2C_MasterSetGlitchFilter(LPI2C_Type *base,
                                 uint32_t u32SdaFilterWidthNs,
                                 uint32_t u32SclFilterWidthNs,
                                 uint32_t u32SrcClockHz);

/*!
 * @brief Configures LPI2C master data match feature.
 *
 * @param base The LPI2C peripheral base address.
 * @param psConfig Settings for the data match feature.
 */
void LPI2C_MasterSetDataMatch(LPI2C_Type *base, const lpi2c_data_match_config_t *psConfig);

/*!
 * @brief Performs a software reset.
 *
 * Restores the LPI2C master peripheral to reset conditions.
 *
 * @param base The LPI2C peripheral base address.
 */
static inline void LPI2C_MasterReset(LPI2C_Type *base)
{
    base->MCR = LPI2C_MCR_RST_MASK;
    base->MCR = 0;
}

/*!
 * @brief Enables or disables the LPI2C module as master.
 *
 * @param base The LPI2C peripheral base address.
 * @param bEnable Pass true to enable or false to disable the specified LPI2C as master.
 */
static inline void LPI2C_MasterEnable(LPI2C_Type *base, bool bEnable)
{
    base->MCR = (base->MCR & ~LPI2C_MCR_MEN_MASK) | LPI2C_MCR_MEN(bEnable);
}

/*!
 * @brief Sets the watermarks for LPI2C master FIFOs.
 *
 * @param base The LPI2C peripheral base address.
 * @param u16TxWords Transmit FIFO watermark value in words. The #kLPI2C_MasterTxReadyInterruptFlag flag is set whenever
 *      the number of words in the transmit FIFO is equal or less than @a u16TxWords. Writing a value equal or
 *      greater than the FIFO size is truncated.
 * @param u16RxWords Receive FIFO watermark value in words. The #kLPI2C_MasterRxReadyInterruptFlag flag is set whenever
 *      the number of words in the receive FIFO is greater than @a u16RxWords. Writing a value equal or greater
 *      than the FIFO size is truncated.
 */
static inline void LPI2C_MasterSetWatermarks(LPI2C_Type *base, uint16_t u16TxWords, uint16_t u16RxWords)
{
    base->MFCR = LPI2C_MFCR_TXWATER(u16TxWords) | LPI2C_MFCR_RXWATER(u16RxWords);
}

/*!
 * @brief Gets the current number of words in the LPI2C master FIFOs.
 *
 * @param base The LPI2C peripheral base address.
 * @param pu16RxCount Pointer through which the current number of words in the transmit FIFO is returned.
 *      Pass NULL if this value is not required.
 * @param pu16TxCount Pointer through which the current number of words in the receive FIFO is returned.
 *      Pass NULL if this value is not required.
 */
static inline void LPI2C_MasterGetFifoCounts(LPI2C_Type *base, uint16_t *pu16RxCount, uint16_t *pu16TxCount)
{
    if (NULL != pu16TxCount)
    {
        *pu16TxCount = (base->MFSR & LPI2C_MFSR_TXCOUNT_MASK) >> LPI2C_MFSR_TXCOUNT_SHIFT;
    }
    if (NULL != pu16RxCount)
    {
        *pu16RxCount = (base->MFSR & LPI2C_MFSR_RXCOUNT_MASK) >> LPI2C_MFSR_RXCOUNT_SHIFT;
    }
}

/*! @} */

/*! @name Slave Module Configuration Sub-group */
/*! @{ */

/*!
 * @brief Sets the LPI2C slave glitch filter width.
 *
 * After the LPI2C module is initialized as slave, user can call this function to change the glitch filter width.
 *
 * @param base The LPI2C peripheral base address.
 * @param u32SdaFilterWidthNs The SDA glitch filter length in nano seconds.
 * @param u32SclFilterWidthNs The SCL glitch filter length in nano seconds.
 * @param u32SrcClockHz LPI2C peripheral clock frequency in Hz
 */
void LPI2C_SlaveSetGlitchFilter(LPI2C_Type *base,
                                uint32_t u32SdaFilterWidthNs,
                                uint32_t u32SclFilterWidthNs,
                                uint32_t u32SrcClockHz);

/*!
 * @brief Configure the slave addressing mode.
 *
 * After the LPI2C module is initialized as slave, user can call this function to change the configuration of slave
 * addressing mode.
 *
 * @param base The LPI2C peripheral base address.
 * @param eAddressMatchMode The slave addressing match mode.
 * @param u16Address0 LPI2C slave address 0. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * @param u16Address1 LPI2C slave address 1. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 */
void LPI2C_SlaveSetAddressingMode(LPI2C_Type *base,
                                  lpi2c_slave_address_match_t eAddressMatchMode,
                                  uint16_t u16Address0,
                                  uint16_t u16Address1);

/*!
 * @brief Performs a software reset of the LPI2C slave peripheral.
 *
 * @param base The LPI2C peripheral base address.
 */
static inline void LPI2C_SlaveReset(LPI2C_Type *base)
{
    base->SCR = LPI2C_SCR_RST_MASK;
    base->SCR = 0;
}

/*!
 * @brief Enables or disables the LPI2C module as slave.
 *
 * @param base The LPI2C peripheral base address.
 * @param bEnable Pass true to enable or false to disable the specified LPI2C as slave.
 */
static inline void LPI2C_SlaveEnable(LPI2C_Type *base, bool bEnable)
{
    base->SCR = (base->SCR & ~LPI2C_SCR_SEN_MASK) | LPI2C_SCR_SEN(bEnable);
}

/*! @} */

/*! @name Master DMA control Sub-group */
/*! @{ */

/*!
 * @brief Enables or disables LPI2C master DMA requests.
 *
 * @param base The LPI2C peripheral base address.
 * @param bEnableTx Enable flag for transmit DMA request. Pass true for enable, false for disable.
 * @param bEnableRx Enable flag for receive DMA request. Pass true for enable, false for disable.
 */
static inline void LPI2C_MasterEnableDMA(LPI2C_Type *base, bool bEnableTx, bool bEnableRx)
{
    base->MDER = LPI2C_MDER_TDDE(bEnableTx) | LPI2C_MDER_RDDE(bEnableRx);
}

/*!
 * @brief Gets LPI2C master transmit data register address for DMA transfer.
 *
 * @param base The LPI2C peripheral base address.
 * @return The LPI2C Master Transmit Data Register address.
 */
static inline uint32_t LPI2C_MasterGetTxFifoAddress(LPI2C_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(LPI2C_Type, base, MTDR);
}

/*!
 * @brief Gets LPI2C master receive data register address for DMA transfer.
 *
 * @param base The LPI2C peripheral base address.
 * @return The LPI2C Master Receive Data Register address.
 */
static inline uint32_t LPI2C_MasterGetRxFifoAddress(LPI2C_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(LPI2C_Type, base, MRDR);
}

/*! @} */

/*! @name Slave DMA control Sub-group */
/*! @{ */

/*!
 * @brief Enables or disables the LPI2C slave peripheral DMA requests.
 *
 * @param base The LPI2C peripheral base address.
 * @param bEnableAddressValid Enable flag for the address valid DMA request. Pass true for enable, false for disable.
 *      The address valid DMA request is shared with the receive data DMA request.
 * @param bEnableRx Enable flag for the receive data DMA request. Pass true for enable, false for disable.
 * @param bEnableTx Enable flag for the transmit data DMA request. Pass true for enable, false for disable.
 */
static inline void LPI2C_SlaveEnableDMA(LPI2C_Type *base, bool bEnableAddressValid, bool bEnableRx, bool bEnableTx)
{
    base->SDER = (base->SDER & ~(LPI2C_SDER_AVDE_MASK | LPI2C_SDER_RDDE_MASK | LPI2C_SDER_TDDE_MASK)) |
                 LPI2C_SDER_AVDE(bEnableAddressValid) | LPI2C_SDER_RDDE(bEnableRx) | LPI2C_SDER_TDDE(bEnableTx);
}

/*! @} */

/*! @name Master Bus operations Sub-Group */
/*! @{ */

/* Not static so it can be used from fsl_lpi2c_edma.c. */
status_t LPI2C_MasterCheckAndClearError(LPI2C_Type *base, uint16_t u16Status);

/* Not static so it can be used from fsl_lpi2c_edma.c. */
status_t LPI2C_MasterCheckForBusyBus(LPI2C_Type *base);

/* Function to send I2C START signal according to START/REPEART_START status, mainly to decide whether reset PEC value
 * in SMBus mode. */
status_t LPI2C_MasterStartInternal(LPI2C_Type *base,
                                   uint8_t u8Address,
                                   lpi2c_data_direction_t eDir,
                                   bool bIsRepeatedStart);

/*!
 * @brief Sends a START signal and slave address on the I2C bus.
 *
 * This function is used to initiate a new master mode transfer. First, the bus state is checked to ensure
 * that another master is not occupying the bus. Then a START signal is transmitted, followed by the
 * 7-bit address specified in the @a address parameter. Note that this function does not actually wait
 * until the START and address are successfully sent on the bus before returning.
 *
 * @param base The LPI2C peripheral base address.
 * @param u8Address 7-bit slave device address, in bits [6:0].
 * @param eDir Master transfer direction, either #kLPI2C_Read or #kLPI2C_Write. This parameter is used to set
 *      the R/w bit (bit 0) in the transmitted slave address.
 * @retval #kStatus_Success START signal and address were successfully enqueued in the transmit FIFO.
 * @retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 */
static inline status_t LPI2C_MasterStart(LPI2C_Type *base, uint8_t u8Address, lpi2c_data_direction_t eDir)
{
    return LPI2C_MasterStartInternal(base, u8Address, eDir, false);
}

/*!
 * @brief Sends a repeated START signal and slave address on the I2C bus.
 *
 * This function is used to send a Repeated START signal when a transfer is already in progress. Like
 * LPI2C_MasterStart(), it also sends the specified 7-bit address.
 *
 * @note This function exists primarily to maintain compatible APIs between LPI2C and I2C drivers,
 *      as well as to better document the intent of code that uses these APIs.
 *
 * @param base The LPI2C peripheral base address.
 * @param u8Address 7-bit slave device address, in bits [6:0].
 * @param eDir Master transfer direction, either #kLPI2C_Read or #kLPI2C_Write. This parameter is used to set
 *      the R/w bit (bit 0) in the transmitted slave address.
 * @retval #kStatus_Success Repeated START signal and address were successfully enqueued in the transmit FIFO.
 * @retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 */
static inline status_t LPI2C_MasterRepeatedStart(LPI2C_Type *base, uint8_t u8Address, lpi2c_data_direction_t eDir)
{
    return LPI2C_MasterStartInternal(base, u8Address, eDir, true);
}

/*!
 * @brief Sends a STOP signal on the I2C bus.
 *
 * This function does not return until the STOP signal is seen on the bus, or an error occurs.
 *
 * @param base The LPI2C peripheral base address.
 * @retval #kStatus_Success The STOP signal was successfully sent on the bus and the transaction terminated.
 * @retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * @retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * @retval #kStatus_LPI2C_FifoError FIFO under run or overrun.
 * @retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * @retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterStop(LPI2C_Type *base);

/*!
 * @brief Performs a polling send transfer on the I2C bus.
 *
 * Sends up to @a u16TxSize number of bytes to the previously addressed slave device. The slave may
 * reply with a NAK to any byte in order to terminate the transfer early. If this happens, this
 * function returns #kStatus_LPI2C_Nak.
 *
 * @param base  The LPI2C peripheral base address.
 * @param pTxBuff The pointer to the data to be transferred.
 * @param u16TxSize The length in bytes of the data to be transferred.
 * @param bPecEnable It decides whether one byte PEC is needed to send.
 *
 * @retval #kStatus_Success Data was sent successfully.
 * @retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * @retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * @retval #kStatus_LPI2C_FifoError FIFO under run or over run.
 * @retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * @retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterSend(LPI2C_Type *base, void *pTxBuff, uint16_t u16TxSize, bool bPecEnable);

/*!
 * @brief Performs a polling receive transfer on the I2C bus.
 *
 * @param base  The LPI2C peripheral base address.
 * @param pRxBuff The pointer to the data to be transferred.
 * @param u16RxSize The length in bytes of the data to be transferred.
 * @param bPecEnable It decides whether one byte PEC is needed to receive.
 *
 * @retval #kStatus_Success Data was received successfully.
 * @retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * @retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * @retval #kStatus_LPI2C_FifoError FIFO under run or overrun.
 * @retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * @retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterReceive(LPI2C_Type *base, void *pRxBuff, uint16_t u16RxSize, bool bPecEnable);

/*! @} */

/*! @name Slave Bus operations Sub-Group */
/*! @{ */

/*!
 * @brief Returns whether the bus is idle.
 *
 * Requires the slave mode to be enabled.
 *
 * @param base The LPI2C peripheral base address.
 * @retval true Bus is busy.
 * @retval false Bus is idle.
 */
static inline bool LPI2C_SlaveGetBusIdleState(LPI2C_Type *base)
{
    return ((base->SSR & LPI2C_SSR_BBF_MASK) >> LPI2C_SSR_BBF_SHIFT) == 1U ? true : false;
}

/*!
 * @brief Transmits either an ACK or NAK on the I2C bus in response to a byte from the master.
 *
 * Use this function to send an ACK or NAK when the #kLPI2C_SlaveTransmitAckInterruptFlag is asserted. This
 * only happens if you enable the sclStall.enableAck field of the ::lpi2c_slave_config_t configuration
 * structure used to initialize the slave peripheral.
 *
 * @param base The LPI2C peripheral base address.
 * @param bSendAck Pass true for an ACK or false for a NAK.
 */
static inline void LPI2C_SlaveTransmitAck(LPI2C_Type *base, bool bSendAck)
{
    base->STAR = LPI2C_STAR_TXNACK(!bSendAck);
}

/*!
 * @brief Returns the slave address sent by the I2C master.
 *
 * This function should only be called if the #kLPI2C_SlaveAddressValidInterruptFlag is asserted.
 *
 * @param base The LPI2C peripheral base address.
 * @return The 8-bit address matched by the LPI2C slave. Bit 0 contains the R/w direction bit, and
 *      the 7-bit slave address is in the upper 7 bits.
 */
static inline uint16_t LPI2C_SlaveGetReceivedAddress(LPI2C_Type *base)
{
    return base->SASR & LPI2C_SASR_RADDR_MASK;
}

/*!
 * @brief Performs a polling send transfer on the I2C bus.
 *
 * @param base  The LPI2C peripheral base address.
 * @param pTxBuff The pointer to the data to be transferred.
 * @param u16TxSize The length in bytes of the data to be transferred.
 * @param pu16ActualTxSize
 * @return Error or success status returned by API.
 */
status_t LPI2C_SlaveSend(LPI2C_Type *base, void *pTxBuff, uint16_t u16TxSize, uint16_t *pu16ActualTxSize);

/*!
 * @brief Performs a polling receive transfer on the I2C bus.
 *
 * @param base  The LPI2C peripheral base address.
 * @param pRxBuff The pointer to the data to be transferred.
 * @param u16RxSize The length in bytes of the data to be transferred.
 * @param pu16ActualRxSize
 * @return Error or success status returned by API.
 */
status_t LPI2C_SlaveReceive(LPI2C_Type *base, void *pRxBuff, uint16_t u16RxSize, uint16_t *pu16ActualRxSize);

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
 * @note The API does not return until the transfer succeeds or fails due
 * to error happens during transfer.
 *
 * @param base The LPI2C peripheral base address.
 * @param psTransfer Pointer to the transfer structure.
 * @retval #kStatus_Success Data was received successfully.
 * @retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * @retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * @retval #kStatus_LPI2C_FifoError FIFO under run or overrun.
 * @retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * @retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterTransferBlocking(LPI2C_Type *base, lpi2c_master_transfer_t *psTransfer);

/*!
 * @brief Creates a new handle for the LPI2C master non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the LPI2C_MasterTransferAbort() API shall be called.
 *
 *
 * @note The function also enables the NVIC IRQ for the input LPI2C. Need to notice
 * that on some SoCs the LPI2C IRQ is connected to INTMUX, in this case user needs to
 * enable the associated INTMUX IRQ in application.
 *
 * @param base The LPI2C peripheral base address.
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @param pfCallback User provided pointer to the asynchronous callback function.
 * @param pUserData User provided pointer to the application callback data.
 */
void LPI2C_MasterTransferCreateHandle(LPI2C_Type *base,
                                      lpi2c_master_transfer_handle_t *psHandle,
                                      lpi2c_master_transfer_callback_t pfCallback,
                                      void *pUserData);

/*!
 * @brief Performs a non-blocking transaction on the I2C bus.
 *
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @param psTransfer The pointer to the transfer descriptor.
 * @retval #kStatus_Success The transaction was started successfully.
 * @retval #kStatus_LPI2C_Busy Either another master is currently utilizing the bus, or a non-blocking
 *      transaction is already in progress.
 */
status_t LPI2C_MasterTransferNonBlocking(lpi2c_master_transfer_handle_t *psHandle, lpi2c_master_transfer_t *psTransfer);

/*!
 * @brief Returns number of bytes transferred so far.
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @param pu16Count Number of bytes transferred so far by the non-blocking transaction.
 * @retval #kStatus_Success
 * @retval #kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t LPI2C_MasterTransferGetCount(lpi2c_master_transfer_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Terminates a non-blocking LPI2C master transmission early.
 *
 * @note It is not safe to call this function from an IRQ handler that has a higher priority than the
 *      LPI2C peripheral's IRQ priority.
 *
 * @param psHandle Pointer to the LPI2C master driver handle.
 * @retval #kStatus_Success A transaction was successfully aborted.
 * @retval #kStatus_LPI2C_Idle There is not a non-blocking transaction currently in progress.
 */
void LPI2C_MasterTransferAbort(lpi2c_master_transfer_handle_t *psHandle);

/*!
 * @brief Reusable routine to handle master interrupts.
 * @note This function does not need to be called unless you are reimplementing the
 *  nonblocking API's interrupt handler routines to add special functionality.
 * @param psHandle Pointer to the LPI2C master driver handle.
 */
void LPI2C_MasterTransferHandleIRQ(lpi2c_master_transfer_handle_t *psHandle);

/*! @}*/

/*! @name Slave Transfer Sub-group */
/*! @{ */

/*!
 * @brief Creates a new handle for the LPI2C slave non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the LPI2C_SlaveTransferAbort() API shall be called.
 *
 * @note The function also enables the NVIC IRQ for the input LPI2C. Need to notice
 * that on some SoCs the LPI2C IRQ is connected to INTMUX, in this case user needs to
 * enable the associated INTMUX IRQ in application.

 * @param base The LPI2C peripheral base address.
 * @param psHandle Pointer to the LPI2C slave driver handle.
 * @param pfCallback User provided pointer to the asynchronous callback function.
 * @param pUserData User provided pointer to the application callback data.
 */
void LPI2C_SlaveTransferCreateHandle(LPI2C_Type *base,
                                     lpi2c_slave_transfer_handle_t *psHandle,
                                     lpi2c_slave_transfer_callback_t pfCallback,
                                     void *pUserData);

/*!
 * @brief Starts accepting slave transfers.
 *
 * Call this API after calling I2C_SlaveInit() and LPI2C_SlaveTransferCreateHandle() to start processing
 * transactions driven by an I2C master. The slave monitors the I2C bus and pass events to the
 * callback that was passed into the call to LPI2C_SlaveTransferCreateHandle(). The callback is always invoked
 * from the interrupt context.
 *
 * The set of events received by the callback is customizable. To do so, set the @a eventMask parameter to
 * the OR'd combination of #lpi2c_slave_transfer_event_t enumerators for the events you wish to receive.
 * The #kLPI2C_SlaveTransmitEvent and #kLPI2C_SlaveReceiveEvent events are always enabled and do not need
 * to be included in the mask. Alternatively, you can pass 0 to get a default set of only the transmit and
 * receive events that are always enabled. In addition, the #kLPI2C_SlaveAllEvents constant is provided as
 * a convenient way to enable all events.
 *
 * @param psHandle Pointer to @ref lpi2c_slave_transfer_handle_t structure which stores the transfer state.
 * @param u8EventMask Bit mask formed by OR'ing together #lpi2c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. Other accepted values are 0 to get a default set of
 *      only the transmit and receive events, and #kLPI2C_SlaveAllEvents to enable all events.
 *
 * @retval #kStatus_Success Slave transfers were successfully started.
 * @retval #kStatus_LPI2C_Busy Slave transfers have already been started on this handle.
 */
status_t LPI2C_SlaveTransferNonBlocking(lpi2c_slave_transfer_handle_t *psHandle, uint8_t u8EventMask);

/*!
 * @brief Gets the slave transfer status during a non-blocking transfer.
 *
 * @param psHandle Pointer to i2c_slave_handle_t structure.
 * @param pu16Count Pointer to a value to hold the number of bytes transferred. May be NULL if the count is not
 *      required.
 * @retval #kStatus_Success
 * @retval #kStatus_NoTransferInProgress
 */
status_t LPI2C_SlaveTransferGetCount(lpi2c_slave_transfer_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Aborts the slave non-blocking transfers.
 * @note This API could be called at any time to stop slave for handling the bus events.
 *
 * @param psHandle Pointer to @ref lpi2c_slave_transfer_handle_t structure which stores the transfer state.
 * @retval #kStatus_Success
 * @retval #kStatus_LPI2C_Idle
 */
void LPI2C_SlaveTransferAbort(lpi2c_slave_transfer_handle_t *psHandle);

/*!
 * @brief Reusable routine to handle slave interrupts.
 * @note This function does not need to be called unless you are reimplementing the
 *         non blocking API's interrupt handler routines to add special functionality.
 *
 * @param psHandle Pointer to @ref lpi2c_slave_transfer_handle_t structure which stores the transfer state.
 */
void LPI2C_SlaveTransferHandleIRQ(lpi2c_slave_transfer_handle_t *psHandle);

/*! @} */

/* ========================================= End of Transactional API Group ========================================= */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_LPI2C_H_ */
