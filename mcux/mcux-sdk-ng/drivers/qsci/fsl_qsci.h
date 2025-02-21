/*
 * Copyright 2020,2021,2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_QSCI_H_
#define FSL_QSCI_H_

#include "fsl_common.h"

/*!
 * @defgroup qsci QSCI: Queued Serial Communications Interface Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief QSCI driver version. */
#define FSL_QSCI_DRIVER_VERSION (MAKE_VERSION(2, 0, 4))
/*! @} */

/*******************************************************************************
 * QSCI peripheral driver change log
 ******************************************************************************/
/*!
 * @defgroup qsci_driver_log The Driver Change Log
 * @ingroup qsci
 * @{
 * The current QSCI driver version is 2.0.4.
 *
 * - 2.0.4
 *   - Bug Fixes
 *     - Fixed DMA transfer blocking issue by enabling tx idle interrupt after DMA transmission finishes, and
 *       invoke completion callback after tx idle interrupt occurs.
 *
 * - 2.0.3
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.2
 *   - Improvements
 *     - Supported QSCI which has 13-bit integer and 3-bit fractional baud rate selection.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed bug that when starting the non-blocking receive, the rx idle interrupt is not enabled, and when
 *       receiving is done the rx idle interrupt is not disabled.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup qsci_intro QSCI Peripheral and Driver Overview
 * @ingroup qsci
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral feature and how this peripheral works
 * =================================================
 * The QSCI allows asynchronous serial communications with peripheral devices.
 *
 * Features
 * --------------------------
 *   + Full-duplex or single-wire operation
 *   + Standard mark/space non-return-to-zero (NRZ) format
 *   + 16-bit integer and 3-bit fractional baud rate selection
 *   + Separately enabled and separate DSC core interrupt request for transmitter and receiver
 *   + Configurable data formats
 *       - Programmable 8-bit or 9-bit data format
 *       - Programmable polarity for transmitter and receiver
 *   + Interrupt-driven operation with multiple flags
 *       - Transmitter empty
 *       - Transmitter idle
 *       - Receiver full
 *       - Receiver idle
 *       - Receiver input edge
 *   + Error detection with multiple flags
 *       - Receiver overrun
 *       - 1/16 bit-time noise error detection
 *       - Receiver framing error detection
 *       - Receiver parity checking
 *   + Receiver Wakeup
 *       - Two receiver wake-up methods: idle line or address mark
 *       - Clockless receiver wake-up on active input edge
 *   + DMA support
 *   + Supports Local Interconnect Network (LIN)
 *
 * How this driver is designed to make this peripheral works
 * =========================================================
 * On abstraction level, the QSCI driver provides 2 parallel layers for different users with different requirements on
 * flexibility: Functional layer and Transactional layer. Do not mix the usage of these 2 layers.
 *  + Functional Layer is provided with highly optimized implementation and highly flexible usage of the peripheral
 *    features. All hardware features' configuration are supported. It requires user to have decent understanding of the
 *    hardware detail to know how to organize these functional APIs together to meet application requirement.
 *  + Transactional layer is provided with high abstraction, limited flexibility/optimization, and not all features are
 *    covered. Their aim is to let user implement QSCI transaction with least knowledge requirement of this specific
 * QSCI peripheral and least coding effort. It achieves this goal by hiddening the setup of interrupt processing inside
 *    driver and implementing complete software state machine for QSCI transaction.
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
 *       + APIs to initialize and de-initialize QSCI module.
 *   - Hardware Status Flags Sub-group
 *       + APIs to get/clear status flags.
 *   - Interrupt Sub-group
 *       + APIs to enable, disable or get the enabled interrupt source.
 *   - Peripheral Configuration Sub-group
 *       + General Peripheral configuration:
 *           APIs for QSCI general configuration, such as parity, data bits.
 *       + FIFO Configuration Sub-group:
 *           APIs for FIFO relevant features.
 *       + DMA Configuration Sub-group:
 *           APIs for DMA relevant features.
 *   - Bus Operation Sub-group
 *       + APIs for QSCI transfer.
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
 *       + Transactional APIs are based on common programming model of QSCI protocol, they are of little peripheral
 *         specific so they have average optimization on performance and code size
 *
 * + Software Implementation Logic
 *   - Double Weak Mechanism
 *     One of the key features of Transactional layer compared to Functional layer is user need not setup interrupt
 *     handling codes, but can still get IRQ service function executed when interrupt happens. This is achieved by the
 *     'double weak' mechanism. Refer to the general section of API Reference Manual for detail. In breif, SDK place a
 *     weak function A for this peripheral's vector entry. The default implementation of this function calls another
 *     weak function B. By default, when a interrupt happen, the code will be executed as A (Weak) -> B (Weak). This
 *     driver implements the function B as non-weak inside, thus once user gets the driver file into the application
 *     project, when interrupt happens, code will be executed as A (Weak) -> B (Non-Weak, in this driver). If user wants
 *     to implement his/her own IRQ service routine, just define A in application as non-weak.
 *   - Transfer Handling Framework
 *     The Transactional Layer's IRQ service routine is hidden inside the driver, but user can still insert his/her own
 *     processing logic inside IRQ service using callback. User can code his/her own logic inside the callback function
 *     and register it when calling @ref QSCI_TransferCreateHandle to initialize the transfer using Transactional API.
 *     When transfer ends or module detects certain hardware error like receiver overrun, callback will be invoked and
 *     user's logic will be executed.
 *
 *
 * + Structure list
 *   - @ref qsci_transfer_t describes a transfer, the data buffer pointer and the transferred data count
 *   - @ref qsci_transfer_handle_t
 *     refer to qsci_(e)dma_transfer_handle_t
 *        Transactional layer is state retained thus it use the @ref qsci_transfer_handle_t or
 *        qsci_(e)dma_transfer_handle_t to specify the peripheral. User need to initialize the handle by calling
 *        @ref QSCI_TransferCreateHandle or QSCI_TransferCreateHandle(E)DMA.
 *
 * + Sub API Groups
 *   - Transmiter Sub-group
 *       @ref QSCI_TransferSendNonBlocking or QSCI_TransferSend(E)DMA initiates data transmit
 *       @ref QSCI_TransferAbortSend or QSCI_TransferAbortSend(E)DMA aborts active transmit
 *       @ref QSCI_TransferGetSendCount or QSCI_TransferGetSendCount(E)DMA gets the transmitted data count
 *   - Receiver Sub-group
 *       @ref QSCI_TransferReceiveNonBlocking or QSCI_TransferReceive(E)DMA initiates data receive
 *       @ref QSCI_TransferAbortReceive or QSCI_TransferAbortReceive(E)DMA aborts active receive
 *       @ref QSCI_TransferGetReceivedCount or QSCI_TransferGetReceivedCount(E)DMA gets the received data count
 *   - Receiver ring buffer
 *      When using the interrupt way for transfer, if the timing and amout of the data that the QSCI receives are
 *      random and hard to anticipate, to avoid receiver overrun, user can call @ref QSCI_TransferStartRingBuffer to
 *      register user's own pre-allocated buffer. Any data received will be put there first. Call
 *      @ref QSCI_TransferStopRingBuffer to stop the ring buffer, call @ref QSCI_TransferGetRxRingBufferLength to get
 *      how many bytes are stored in the ring buffer.
 *
 * How to use this driver
 * ======================
 * General Control Macro
 * ---------------------
 * + FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL
 *     SDK genneral Macro, controls whether to ungate/gate peripheral's clock source inside driver. Set it to none-zero
 *     value then driver will not ungate/gate clock source during initialization/de-initialization.
 *
 * + QSCI_RETRY_TIMES
 *     QSCI specific Macro, controls the retry times when checking the module's status flags. During transfer, at
 *     certain stages program needs to wait for some flag to be set/cleared then folowing steps can proceed. Set it to
 *     non-zero value then driver retries the check QSCI_RETRY_TIMES. If it counts down to zero but the flag remains
 *     unchanged, API returns kStatus_QSCI_Timeout. Set it to zero then the driver keeps waiting until the flag changes.
 *
 * Callback Macro
 * --------------
 * For efficiency's sake, user callback interface is designed to have only one parameter psHandle defined as
 * @ref qsci_transfer_handle_t. Since the handle shall not be modified by user application, macros are provided for
 * user to get bus status or user data.
 * + QSCI_GET_BUS_STATUS
 *     Returns the bus status in result of the transfer.
 * + QSCI_GET_TRANSFER_USER_DATA
 *     Returns the user data passed to transational layer when creating handle.
 *
 * Configuration Items Before Calling QSCI Driver APIs
 * --------------------------------------------------
 *  + Mux the QSCI TXD/RXD signals to on-board pins, and configure them with expected port pin feature.
 *  + Select and attach proper clock source to QSCI module.
 *  + Ungate the QSCI clock if user wish to do it outside driver by setting FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL to
 *    non-zero value.
 *  + If user wish to use interrupt for QSCI transfer while other modules' interrupt sources are also enabled, set
 * proper interrupt priority before initiating QSCI transfer, so that QSCI IRQ service can be properly executed.
 *
 * Functional layer usage model
 * ------------------------------
 *  - Configuration Items Before Calling Driver APIs
 *      + Except the items described in the general part, define the QSCI interrupt entry in the application code
 *        if interrupt is needed for this peripheral usage.
 *  - Call flow
 *      + Init the module with @ref QSCI_Init. Note @ref QSCI_GetDefaultConfig can help user to get a ready-to-use init
 *        data structure.
 *      + Do the QSCI transaction with other functional layer APIs
 *
 * Transactional layer usage model
 * ------------------------------
 *  + Init the module with @ref QSCI_Init. Note @ref QSCI_GetDefaultConfig can help user to get a ready-to-use init data
 *    structure.
 *  + Init the handle with @ref QSCI_TransferCreateHandle with callback function(optional).
 *  + Data transmit
 *      - Transmit data with @ref QSCI_TransferSendNonBlocking
 *      - User can query how many data are transmitted by @ref QSCI_TransferGetSendCount
 *      - User can abort transmit by @ref QSCI_TransferAbortSend
 *  + Data Receive
 *      - Receive data with @ref QSCI_TransferReceiveNonBlocking
 *      - User can query how many data are received by @ref QSCI_TransferGetReceivedCount
 *      - User can abort receive by @ref QSCI_TransferAbortReceive
 *      - Optionally, call @ref QSCI_TransferStartRingBuffer to register user's own pre-allocated buffer, call
 *        @ref QSCI_TransferStopRingBuffer to stop the ring buffer if not needed any more, call
 *        @ref QSCI_TransferGetRxRingBufferLength to get how many bytes are stored.
 *
 * Typical Use Cases
 * ==================
 * These code snipets shows the general calling sequence to use functional APIs and transactional APIs. For detail usage
 * on appilcation level, refer to QSCI driver examples in SDK package under boards/\<board_name\>/driver_examples/QSCI.
 *
 * //TODO
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* ============================================= General Control Macro ============================================== */
/*! @brief Retry times when checking status flags. */
#ifndef QSCI_RETRY_TIMES
#define QSCI_RETRY_TIMES 0U /* Default defines to zero, driver keeps checking status flag untill it changes. */
#endif

/* ================================================ Callback Macro ================================================== */
/*! @brief Macros to be used inside user callback. */
#define QSCI_GET_BUS_STATUS(psHandle)         (psHandle)->busStatus
#define QSCI_GET_TRANSFER_USER_DATA(psHandle) (psHandle)->pUserData

/*! @brief Status codes for the QSCI driver. */
enum
{
    kStatus_QSCI_TxBusy = MAKE_STATUS(kStatusGroup_QSCI, 0U), /*!< Transmitter is busy. */
    kStatus_QSCI_RxBusy = MAKE_STATUS(kStatusGroup_QSCI, 1U), /*!< Receiver is busy. */
    kStatus_QSCI_TxIdle = MAKE_STATUS(kStatusGroup_QSCI, 2U), /*!< Transmitter is idle. */
    kStatus_QSCI_RxIdle = MAKE_STATUS(kStatusGroup_QSCI, 3U), /*!< Receiver is idle. */
    kStatus_QSCI_FlagCannotClearManually =
        MAKE_STATUS(kStatusGroup_QSCI, 4), /*!< Status flag can't be manually cleared. */
    kStatus_QSCI_RxRingBufferOverrun = MAKE_STATUS(kStatusGroup_QSCI, 5U), /*!< QSCI RX software ring buffer overrun. */
    kStatus_QSCI_RxHardwareOverrun   = MAKE_STATUS(kStatusGroup_QSCI, 6U), /*!< QSCI receiver hardware overrun. */
    kStatus_QSCI_NoiseError          = MAKE_STATUS(kStatusGroup_QSCI, 7U), /*!< QSCI noise error. */
    kStatus_QSCI_FramingError        = MAKE_STATUS(kStatusGroup_QSCI, 8U), /*!< QSCI framing error. */
    kStatus_QSCI_ParityError         = MAKE_STATUS(kStatusGroup_QSCI, 9U), /*!< QSCI parity error. */
    kStatus_QSCI_BaudrateNotSupport =
        MAKE_STATUS(kStatusGroup_QSCI, 10), /*!< Baudrate is not supported in current clock source */
    kStatus_QSCI_IdleLineDetected = MAKE_STATUS(kStatusGroup_QSCI, 11), /*!< QSCI IDLE line detected. */
    kStatus_QSCI_Timeout =
        MAKE_STATUS(kStatusGroup_QSCI, 12), /*!< Timeout happens when waiting for status flags to change. */
};

/* ================================== Functional Group Structure/Enumeration List =================================== */
/* ---------------------------------------- Hardware Status Flags Sub-group ----------------------------------------- */
/*!
 * @brief QSCI hardware status flags.
 *
 * These enumerations can be ORed together to form bit masks.
 */
enum _qsci_status_flags
{
    kQSCI_TxDataRegEmptyFlag = QSCI_STAT_TDRE_MASK,  /*!< TX data register empty flag. */
    kQSCI_TxIdleFlag         = QSCI_STAT_TIDLE_MASK, /*!< Transmission idle flag. */
    kQSCI_RxDataRegFullFlag  = QSCI_STAT_RDRF_MASK,  /*!< RX data register full flag. */
    kQSCI_RxIdleLineFlag     = QSCI_STAT_RIDLE_MASK, /*!< Rx Idle line flag. */

    kQSCI_RxOverrunFlag    = QSCI_STAT_OR_MASK, /*!< RX overrun flag. */
    kQSCI_RxNoiseFlag      = QSCI_STAT_NF_MASK, /*!< RX detect noise on Rx input. */
    kQSCI_RxFrameErrorFlag = QSCI_STAT_FE_MASK, /*!< Rx frame error flag, sets if logic 0 was detected for stop bit*/
    kQSCI_RxParityErrorFlag =
        QSCI_STAT_PF_MASK, /*!< Rx parity error if parity enabled, sets upon parity error detection */

    kQSCI_RxInputEdgeFlag =
        QSCI_STAT_RIEF_MASK, /*!< RX pin active edge interrupt flag, sets when active edge detected */
    kQSCI_LINSyncErrorFlag = QSCI_STAT_LSE_MASK,  /*!< Only for LIN mode. */
    kQSCI_TxDMARequestFlag = QSCI_STAT_TDMA_MASK, /*!< Tx DMA request is ongoing. */
    kQSCI_RxDMARequestFlag = QSCI_STAT_RDMA_MASK, /*!< Rx DMA request is ongoing. */
    kQSCI_RxActiveFlag     = QSCI_STAT_RAF_MASK,  /*/< Rx reception is in progress. */

    kQSCI_Group0Flags = kQSCI_TxDataRegEmptyFlag | kQSCI_TxIdleFlag | kQSCI_RxDataRegFullFlag | kQSCI_TxDMARequestFlag |
                        kQSCI_RxDMARequestFlag | kQSCI_RxActiveFlag, /*!< Members in kQSCI_Group0Flags can't
                                                 be cleared by QSCI_ClearStatusFlags, they are handled by HW. */
    kQSCI_Group1Flags = kQSCI_RxOverrunFlag | kQSCI_RxNoiseFlag | kQSCI_RxFrameErrorFlag | kQSCI_RxParityErrorFlag |
                        kQSCI_LINSyncErrorFlag, /*!< Whole kQSCI_Group1Flags will be cleared if trying to clear any
                                                   member in kQSCI_Group1Flags or kQSCI_Group2Flags in the mask. */
    kQSCI_Group2Flags =
        kQSCI_RxInputEdgeFlag | kQSCI_RxIdleLineFlag, /*!< Member in kQSCI_Group2Flags can be cleared individually */
    kQSCI_StatusAllFlags = kQSCI_Group1Flags | kQSCI_Group2Flags
};
/* -------------------------------------- End of Hardware Status Flags Sub-group ------------------------------------ */

/* ----------------------------------------------- Interrupt Sub-group ---------------------------------------------- */
/*!
 * @brief QSCI interrupt enable/disable source.
 *
 * These enumerations can be ORed together to form bit masks.
 */
enum _qsci_interrupt_enable
{
    kQSCI_TxEmptyInterruptEnable     = QSCI_CTRL1_TEIE_MASK,        /*!< Transmit data register empty interrupt. */
    kQSCI_TxIdleInterruptEnable      = QSCI_CTRL1_TIIE_MASK,        /*!< Transmission idle interrupt. */
    kQSCI_RxFullInterruptEnable      = QSCI_CTRL1_RFIE_MASK,        /*!< Receive data register full interrupt. */
    kQSCI_RxErrorInterruptEnable     = QSCI_CTRL1_REIE_MASK,        /*!< Receive error interrupt. */
    kQSCI_RxInputEdgeInterruptEnable = QSCI_CTRL2_RIEIE_MASK >> 2U, /*!< Receive input edge interrupt. */
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
    kQSCI_RxIdleLineInterruptEnable = QSCI_CTRL2_RIIE_MASK >> 2U, /*!< Receive idle interrupt. */
#endif
    kQSCI_AllInterruptEnable = kQSCI_TxEmptyInterruptEnable | kQSCI_TxIdleInterruptEnable |
                               kQSCI_RxFullInterruptEnable | kQSCI_RxErrorInterruptEnable |
                               kQSCI_RxInputEdgeInterruptEnable
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
                               | kQSCI_RxIdleLineInterruptEnable
#endif
};
/* ------------------------------------------- End of Interrupt Sub-group ------------------------------------------- */

/* --------------------------------------- Peripheral Configuration Sub-group --------------------------------------- */
/*! @brief QSCI transmiter/receiver loop mode. */
typedef enum _qsci_transfer_mode
{
    kQSCI_Normal       = 0U, /*!< Normal mode, 2 signal pins, no loop. */
    kQSCI_LoopInternal = 1U, /*!< Loop mode with internal TXD fed back to RXD. */
    kQSCI_SingleWire   = 2U  /*!< Use tx pin as input and output half-duplex transfer. */
} qsci_transfer_mode_t;

/*! @brief QSCI data bit count. */
typedef enum _qsci_data_bit_mode
{
    kQSCI_Data8Bit = 0U, /*!< 1 start bit, 8 data bit, 1 stop bit */
    kQSCI_Data9Bit =
        1U /*!< 1 start bit, 9 data bit, 1 stop bit. This mode actually is not supported yet in driver. */ // TODO
} qsci_data_bit_mode_t;

/*! @brief QSCI wakeup mode. */
typedef enum _qsci_wakeup_mode
{
    kQSCI_WakeupOnIdleLine    = 0U, /*!< Idle condition wakes the QSCI module. */
    kQSCI_WakeupOnAddressMark = 1U  /*!< Address mark wakes the QSCI module. */
} qsci_wakeup_mode_t;

/*! @brief QSCI signal polarity mode. */
typedef enum _qsci_polarity_mode
{
    kQSCI_PolarityNormal = 0U, /*!< Normal mode, no inversion. */
    kQSCI_PolarityInvert = 1U  /*!< Invert transmit and receive data bits. */
} qsci_polarity_mode_t;

/*! @brief QSCI parity mode. */
typedef enum _qsci_parity_mode
{
    kQSCI_ParityDisabled = 0x0U, /*!< Parity disabled */
    kQSCI_ParityEven     = 0x1U, /*!< Parity enabled, type even, bit setting: PE|PT = 10 */
    kQSCI_ParityOdd      = 0x2U  /*!< Parity enabled, type odd,  bit setting: PE|PT = 11 */
} qsci_parity_mode_t;

/*! @brief QSCI transmitter watermark level. */
typedef enum _qsci_tx_water
{
    kQSCI_TxWater0Word = 0x0U, /*!< Tx interrupt sets when tx fifo empty. */
    kQSCI_TxWater1Word = 0x1U, /*!< Tx interrupt sets when tx fifo has 1 or few word. */
    kQSCI_TxWater2Word = 0x2U, /*!< Tx interrupt sets when tx fifo has 2 or few words. */
    kQSCI_TxWater3Word = 0x3U  /*!< Tx interrupt sets when tx fifo not full. */
} qsci_tx_water_t;

/*! @brief QSCI receiver watermark level. */
typedef enum _qsci_rx_water
{
    kQSCI_RxWater1Word = 0x0U, /*!< Rx interrupt sets when rx fifo not empty. */
    kQSCI_RxWater2Word = 0x1U, /*!< Rx interrupt sets when rx fifo has at least 1 word. */
    kQSCI_RxWater3Word = 0x2U, /*!< Rx interrupt sets when rx fifo has at least 2 words. */
    kQSCI_RxWater4Word = 0x3U  /*!< Rx interrupt sets when rx fifo full. */
} qsci_rx_water_t;
/* ----------------------------------- End of Peripheral Configuration Sub-group ------------------------------------ */

/* ----------------------------------- Module Initialize/De-initialize Sub-group ------------------------------------ */
/*! @brief QSCI configuration structure. */
typedef struct _qsci_config
{
    qsci_transfer_mode_t eTransferMode : 2; /*!< Transmitter/receiver loop mode. */
    bool bStopInWaitEnable : 1;             /*!< Enable/disable module stops working in wait mode. */
    qsci_data_bit_mode_t eDataBitMode : 1;  /*!< Number of data bits. */
    qsci_wakeup_mode_t eWakeupMode : 1;     /*!< Receiver wakeup mode, idle line or addressmark. */
    qsci_polarity_mode_t ePolarityMode : 1; /*!< Polarity of transmit/receive data. */
    qsci_parity_mode_t eParityMode : 2;     /*!< Parity mode, disabled (default), even, odd. */
    bool bEnableStopHold : 1;               /*!< Control the stop hold enable. */
    bool bEnableTx : 1;                     /*!< Enable TX */
    bool bEnableRx : 1;                     /*!< Enable RX */
    bool bEnableFifo : 1;                   /*!< Enable Tx/Rx FIFO */
    bool bEnableTxDMA : 1;                  /*!< Enable Tx DMA */
    bool bEnableRxDMA : 1;                  /*!< Enable Rx DMA */
    qsci_tx_water_t eTxFifoWatermark : 2;   /*!< TX FIFO watermark */
    qsci_rx_water_t eRxFifoWatermark : 2;   /*!< RX FIFO watermark */
    uint8_t u8Interrupts;                   /*!< Mask of QSCI interrupt sources to enable. */
    uint32_t u32BaudRateBps;                /*!< QSCI baud rate  */
    uint32_t u32SrcClockHz;                 /*!< The clock source frequency for QSCI module. */
} qsci_config_t;
/* -------------------------------- End of Module Initialize/De-initialize Sub-group -------------------------------- */

/* ================================= Transactional Group Structure/Enumeration List  ================================ */
/*!
 * @brief Forward declaration of the handle typedef
 * @anchor qsci_transfer_handle_t
 */
typedef struct _qsci_transfer_handle_t qsci_transfer_handle_t;

/*!
 * @brief QSCI interrupt transfer callback function definition
 *
 * Defines the interface of user callback function used in QSCI interrupt transfer using transactional APIs. The
 * callback function shall be defined and declared in application level by user. Before starting QSCI transmiting or
 * receiving by calling @ref QSCI_TransferSendNonBlocking or @ref QSCI_TransferReceiveNonBlocking, call
 * @ref QSCI_TransferCreateHandle to install the user callback. When the transmiting or receiving ends or any bus error
 * like hardware overrun occurs, user callback will be invoked by driver.
 *
 * @param psHandle Transfer handle that contains bus status, user data.
 */
typedef void (*qsci_transfer_callback_t)(qsci_transfer_handle_t *psHandle);

/*!
 * @brief QSCI transfer handle
 *
 * @note If user wants to use the transactional API to transfer data in interrupt way, one QSCI instance should and can
 * only be allocated one handle.
 * @note The handle is maintained by QSCI driver internally, which means the transfer state is retained and user shall
 * not modify its state #u8TxState or #u8RxState in application level. If user only wish to use transactional APIs
 * without understanding its machanism, it is not necessary to understand these members.
 */
struct _qsci_transfer_handle_t
{
    QSCI_Type *base; /*!< QSCI base pointer to the instance belongs to this handle. */

    uint8_t *pu8TxData;                   /*!< Address of remaining data to send. */
    volatile uint32_t u32TxRemainingSize; /*!< Size of the remaining data to send. */
    uint32_t u32TxDataSize;               /*!< Size of the data to send out. */
    uint8_t *pu8RxData;                   /*!< Address of remaining data to receive. */
    volatile uint32_t u32RxRemainingSize; /*!< Size of the remaining data to receive. */
    uint32_t u32RxDataSize;               /*!< Size of the data to receive. */

    uint8_t *pu8RxRingBuffer;              /*!< Start address of the receiver ring buffer. */
    uint16_t u16RxRingBufferSize;          /*!< Size of the ring buffer. */
    volatile uint16_t u16RxRingBufferHead; /*!< Index for the driver to store received data into ring buffer. */
    volatile uint16_t u16RxRingBufferTail; /*!< Index for the user to get data from the ring buffer. */

    qsci_transfer_callback_t pfCallback; /*!< Callback function. */
    void *pUserData;                     /*!< QSCI callback function parameter.*/

    volatile uint8_t u8TxState; /*!< TX transfer state. */
    volatile uint8_t u8RxState; /*!< RX transfer state */

    status_t busStatus; /*!< QSCI bus status. */
};

/*! @brief QSCI transfer structure. */
typedef struct _qsci_transfer
{
    uint8_t *pu8Data;     /*!< The buffer pointer of data to be transferred.*/
    uint32_t u32DataSize; /*!< The byte count to be transferred. */
} qsci_transfer_t;

/* Typedef for QSCI interrupt handler. */
typedef void (*qsci_isr_t)(void *handle);

/* Array of QSCI handle. */
extern qsci_isr_t s_pfQsciIsr;
extern void *s_psQsciHandles[];

/* Array of QSCI TX IDLE IRQ number. */
extern IRQn_Type const s_eQsciTXIdleIRQs[];

/* ============================== End of Transactional Group Structure/Enumeration List  ============================ */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif
/* =========================================== Functional Group API List ============================================ */
/*!
 * @name Module Init/Deinit Sub-group
 * @{
 */
/*!
 * @brief Sets the QSCI configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref QSCI_Init to use.
 * Use the unchanged structure in @ref QSCI_Init or modify the structure before calling @ref QSCI_Init.
 * This is an example:
 * @code
 *   qsci_config_t sConfig;
 *   QSCI_GetDefaultConfig(&sConfig, 115200, 12000000U);
 *   QSCI_Init(QSCI0, &config);
 * @endcode
 *
 * @param psConfig Pointer to configuration structure.
 * @param u32BaudRateBps Baudrate setting.
 * @param u32SrcClockHz The clock source frequency for QSCI module.
 */
void QSCI_GetDefaultConfig(qsci_config_t *psConfig, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz);

/*!
 * @brief Initializes the QSCI instance with a user configuration structure.
 *
 * This function configures the QSCI module with the customed settings. User can configure the configuration structure
 * manually or get the default configuration by using the @ref QSCI_GetDefaultConfig function.
 * The example below shows how to use this API to configure QSCI.
 * @code
 *   qsci_config_t sConfig;
 *   QSCI_GetDefaultConfig(&sConfig, 115200, 12000000U);
 *   QSCI_Init(QSCI0, &sConfig);
 * @endcode
 *
 * @param base QSCI peripheral base address.
 * @param psConfig Pointer to the user-defined configuration structure.
 * @retval kStatus_QSCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * @retval kStatus_Success Set baudrate succeeded.
 */
status_t QSCI_Init(QSCI_Type *base, qsci_config_t *psConfig);

/*!
 * @brief Deinitializes a QSCI instance.
 *
 * This function waits for transmiting complete, then disables TX and RX.
 *
 * @param base QSCI peripheral base address.
 */
void QSCI_Deinit(QSCI_Type *base);
/*! @} */

/*!
 * @name Hardware Status Flags Sub-group
 * @{
 */
/*!
 * @brief Gets QSCI hardware status flags.
 *
 * @param base QSCI peripheral base address.
 * @return QSCI status flags, can be a single flag or several flags in #_qsci_status_flags combined by OR.
 */
static inline uint16_t QSCI_GetStatusFlags(QSCI_Type *base)
{
    return (uint16_t)base->STAT;
}

/*!
 * @brief Clears QSCI status flags.
 *
 * This function clears QSCI status flags. Members in kQSCI_Group0Flags can't be cleared by this function, they are
 * cleared or set by hardware.
 *
 * @param base QSCI peripheral base address.
 * @param u16StatusFlags The status flag mask, can be a single flag or several flags in #_qsci_status_flags combined by
 * OR.
 */
void QSCI_ClearStatusFlags(QSCI_Type *base, uint16_t u16StatusFlags);
/*! @} */

/*!
 * @name Interrupt Sub-group
 * @{
 */
/*!
 * @brief Enables QSCI interrupts according to the provided mask.
 *
 * This function enables the QSCI interrupts according to the provided mask. The mask is a logical OR of enumeration
 * members in #_qsci_interrupt_enable.
 *
 * @param base QSCI peripheral base address.
 * @param u8Interrupts The interrupt source mask, can be a single source or several sources in #_qsci_interrupt_enable
 * combined by OR.
 */
void QSCI_EnableInterrupts(QSCI_Type *base, uint8_t u8Interrupts);

/*!
 * @brief Disables QSCI interrupts according to the provided mask.
 *
 * This function disables the QSCI interrupts according to the provided mask. The mask is a logical OR of enumeration
 * members in #_qsci_interrupt_enable.
 *
 * @param base QSCI peripheral base address.
 * @param u8Interrupts The interrupt source mask, can be a single source or several sources in #_qsci_interrupt_enable
 * combined by OR.
 */
void QSCI_DisableInterrupts(QSCI_Type *base, uint8_t u8Interrupts);

/*!
 * @brief Gets the enabled QSCI interrupts.
 *
 * This function gets the enabled QSCI interrupts. The enabled interrupts are returned as the logical OR value of the
 * enumerators #_qsci_interrupt_enable.
 *
 * @param base QSCI peripheral base address.
 * @return The interrupt source mask, can be a single source or several sources in #_qsci_interrupt_enable combined
 * by OR.
 */
uint8_t QSCI_GetEnabledInterrupts(QSCI_Type *base);
/*! @} */

/*!
 * @name General Peripheral Configuration Sub-group
 * @{
 */
/*!
 * @brief Sets the QSCI register value to reset value.
 *
 * @param base QSCI peripheral base address.
 */
static inline void QSCI_Reset(QSCI_Type *base)
{
    base->RATE  = 0x200U;
    base->CTRL1 = 0U;
    base->CTRL2 = 0U;
    base->CTRL3 = 0U;
}

/*!
 * @brief Enables or disables the QSCI transmitter.
 *
 * This function enables or disables the QSCI transmitter.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable True to enable, false to disable.
 */
static inline void QSCI_EnableTx(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL1 |= QSCI_CTRL1_TE_MASK;
    }
    else
    {
        base->CTRL1 &= ~QSCI_CTRL1_TE_MASK;
    }
}

/*!
 * @brief Enables or disables the QSCI receiver.
 *
 * This function enables or disables the QSCI receiver.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable True to enable, false to disable.
 */
static inline void QSCI_EnableRx(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL1 |= QSCI_CTRL1_RE_MASK;
    }
    else
    {
        base->CTRL1 &= ~QSCI_CTRL1_RE_MASK;
    }
}

/*!
 * @brief Enables/disables stop in wait.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable true to enable, QSCI stops working in wait mode, false to disable, QSCI keeps working in wait mode
 */
static inline void QSCI_EnableStopInWait(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL1 |= QSCI_CTRL1_SWAI_MASK;
    }
    else
    {
        base->CTRL1 &= ~(uint8_t)QSCI_CTRL1_SWAI_MASK;
    }
}

/*!
 * @brief Enables/Disables 9-bit data mode for QSCI.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable true to enable, false to disable.
 */
static inline void QSCI_Enable9bitMode(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL1 |= QSCI_CTRL1_M_MASK;
    }
    else
    {
        base->CTRL1 &= ~QSCI_CTRL1_M_MASK;
    }
}

/*!
 * @brief Enables/Disables standby mode.
 *
 * When QSCI is in standby mode, further receiver interrupt requests are inhibited waiting to be wake up. The wakeup
 * mode can be configured by @ref QSCI_SetWakeupMode. Hardware wakes the receiver by automatically disabling standby.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable true to enable, false to disable.
 */
static inline void QSCI_EnableStandbyMode(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL1 |= QSCI_CTRL1_RWU_MASK;
    }
    else
    {
        base->CTRL1 &= ~QSCI_CTRL1_RWU_MASK;
    }
}

/*!
 * @brief Enable/Disable LIN slave mode.
 *
 * If enabled QSCI is in LIN slave mode. When break is detected, the baudrate register is
 * automatically adjusted to match the value measured from the sync character that follows.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable true to enable, false to disable.
 */
static inline void QSCI_EnableLINSlaveMode(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL2 |= QSCI_CTRL2_LINMODE_MASK;
    }
    else
    {
        base->CTRL2 &= ~QSCI_CTRL2_LINMODE_MASK;
    }
}

/*!
 * @brief Enable/Disable stop mode hold off.
 *
 * When enabled, if chip level stop mode occurs and transmiter or receiver is still busy,
 * QSCI will hold off stop mode until both transmiter and receiver are idle.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable true to enable, false to disable.
 */
static inline void QSCI_EnableStopHold(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL3 |= QSCI_CTRL3_SHEN_MASK;
    }
    else
    {
        base->CTRL3 &= ~QSCI_CTRL3_SHEN_MASK;
    }
}

/*!
 * @brief Sets the QSCI transfer mode.
 *
 * @param base QSCI peripheral base address.
 * @param eTransferMode The QSCI tx/rx loop mode, #kQSCI_Normal to use normal transfer, #kQSCI_LoopInternal to let
 * internal tx feed back to rx, #kQSCI_SingleWire to use single wire mode using tx pin as tx and rx.
 */
static inline void QSCI_SetTransferMode(QSCI_Type *base, qsci_transfer_mode_t eTransferMode)
{
    if (eTransferMode == kQSCI_Normal)
    {
        base->CTRL1 &= ~QSCI_CTRL1_LOOP_MASK;
    }
    else
    {
        base->CTRL1 |= QSCI_CTRL1_LOOP_MASK;
        if (eTransferMode == kQSCI_LoopInternal)
        {
            base->CTRL1 &= ~QSCI_CTRL1_RSRC_MASK;
        }
        else
        {
            base->CTRL1 |= QSCI_CTRL1_RSRC_MASK;
        }
    }
}

/*!
 * @brief Sets wakeup mode for QSCI.
 *
 * @param base QSCI peripheral base address.
 * @param eWakeupMode Wakeup mode, #kQSCI_WakeupOnIdleLine or #kQSCI_WakeupOnAddressMark.
 */
static inline void QSCI_SetWakeupMode(QSCI_Type *base, qsci_wakeup_mode_t eWakeupMode)
{
    if (eWakeupMode == kQSCI_WakeupOnAddressMark)
    {
        base->CTRL1 |= QSCI_CTRL1_WAKE_MASK;
    }
    else
    {
        base->CTRL1 &= ~QSCI_CTRL1_WAKE_MASK;
    }
}

/*!
 * @brief Sets polarity mode for QSCI.
 *
 * @param base QSCI peripheral base address.
 * @param ePolarityMode Polarity mode, #kQSCI_PolarityNormal or #kQSCI_PolarityInvert.
 */
static inline void QSCI_SetPolarityMode(QSCI_Type *base, qsci_polarity_mode_t ePolarityMode)
{
    if (ePolarityMode == kQSCI_PolarityInvert)
    {
        base->CTRL1 |= QSCI_CTRL1_POL_MASK;
    }
    else
    {
        base->CTRL1 &= ~QSCI_CTRL1_POL_MASK;
    }
}

/*!
 * @brief Sets parity mode for QSCI.
 *
 * @param base QSCI peripheral base address.
 * @param eParityMode Polarity mode, #kQSCI_ParityDisabled, #kQSCI_ParityEven or #kQSCI_ParityOdd.
 */
static inline void QSCI_SetParityMode(QSCI_Type *base, qsci_parity_mode_t eParityMode)
{
    if (eParityMode == kQSCI_ParityDisabled)
    {
        base->CTRL1 &= ~QSCI_CTRL1_PE_MASK;
    }
    else
    {
        base->CTRL1 |= QSCI_CTRL1_PE_MASK;
        if (eParityMode == kQSCI_ParityEven)
        {
            base->CTRL1 &= ~QSCI_CTRL1_PT_MASK;
        }
        else
        {
            base->CTRL1 |= QSCI_CTRL1_PT_MASK;
        }
    }
}

/*!
 * @brief Sets the QSCI instance baud rate.
 *
 * This function configures the QSCI module baud rate. This function can be used to update QSCI module baud rate after
 * the QSCI module is initialized by the @ref QSCI_Init.
 *
 * @param base QSCI peripheral base address.
 * @param u32BaudRateBps QSCI baudrate to be set.
 * @param u32SrcClockHz QSCI clock source frequency in Hz.
 * @retval #kStatus_QSCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * @retval #kStatus_Success Set baudrate succeeded.
 */
status_t QSCI_SetBaudRate(QSCI_Type *base, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz);
/*! @} */

/*!
 * @name FIFO Configuration Sub-group
 * @{
 */
/*!
 * @brief Enables/Disables transmitter/receiver FIFO.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable true to enable, false to disable.
 */
static inline void QSCI_EnableFifo(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL2 |= QSCI_CTRL2_FIFO_EN_MASK;
    }
    else
    {
        base->CTRL2 &= ~QSCI_CTRL2_FIFO_EN_MASK;
    }
}

/*!
 * @brief Sets transmitter watermark.
 *
 * @param base QSCI peripheral base address.
 * @param eTxFifoWatermark Tx water mark level.
 */
static inline void QSCI_SetTxWaterMark(QSCI_Type *base, qsci_tx_water_t eTxFifoWatermark)
{
    base->CTRL2 = base->CTRL2 & (~QSCI_CTRL2_TFWM_MASK) | QSCI_CTRL2_TFWM(eTxFifoWatermark);
}

/*!
 * @brief Sets receiver watermark.
 *
 * @param base QSCI peripheral base address.
 * @param eRxFifoWatermark Rx water mark level.
 */
static inline void QSCI_SetRxWaterMark(QSCI_Type *base, qsci_rx_water_t eRxFifoWatermark)
{
    base->CTRL2 = base->CTRL2 & (~QSCI_CTRL2_RFWM_MASK) | QSCI_CTRL2_RFWM(eRxFifoWatermark);
}
/*! @} */

/*!
 * @name DMA Configuration Sub-group
 * @{
 */
/*!
 * @brief Enables or disables the QSCI transmitter DMA request.
 *
 * This function enables or disables CTRL2[TDE], to generate the DMA requests when Tx data register is empty.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable True to enable, false to disable.
 */
static inline void QSCI_EnableTxDMA(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL2 |= QSCI_CTRL2_TDE_MASK;
    }
    else
    {
        base->CTRL2 &= ~QSCI_CTRL2_TDE_MASK;
    }
}

/*!
 * @brief Enables or disables the QSCI receiver DMA request.
 *
 * This function enables or disables CTRL2[RDE], to generate DMA requests when receiver data register is full.
 *
 * @param base QSCI peripheral base address.
 * @param bEnable True to enable, false to disable.
 */
static inline void QSCI_EnableRxDMA(QSCI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL2 |= QSCI_CTRL2_RDE_MASK;
    }
    else
    {
        base->CTRL2 &= ~QSCI_CTRL2_RDE_MASK;
    }
}

/*!
 * @brief Gets the QSCI data register byte address.
 *
 * This function returns the QSCI data register address, which is mainly used by DMA/eDMA.
 *
 * @param base QSCI peripheral base address.
 * @return QSCI data register byte addresses which are used both by the transmitter and the receiver.
 */
static inline uint32_t QSCI_GetDataRegisterAddress(QSCI_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(QSCI_Type, base, DATA);
}
/*! @} */

/*!
 * @name Bus Operation Sub-group
 * @{
 */

/*!
 * @brief Writes to the TX register.
 *
 * This function writes data to the TX register directly. The upper layer must ensure
 * that the TX register is empty or TX FIFO has room before calling this function.
 *
 * @param base QSCI peripheral base address.
 * @param u8Data The byte to write.
 */
static inline void QSCI_WriteByte(QSCI_Type *base, uint8_t u8Data)
{
    base->DATA = u8Data;
}

/*!
 * @brief Sends an address frame in 9-bit data mode.
 *
 * @param base QSCI peripheral base address.
 * @param u8Address QSCI slave address.
 */
static inline void QSCI_SendAddress(QSCI_Type *base, uint8_t u8Address)
{
    uint16_t u16Data = 0x100U | (uint16_t)u8Address;
    base->DATA       = u16Data;
}

/*!
 * @brief Reads the RX register directly.
 *
 * This function reads data from the RX register directly. The upper layer must
 * ensure that the RX register is full or that the TX FIFO has data before calling this function.
 *
 * @param base QSCI peripheral base address.
 * @return The byte read from QSCI data register.
 */
static inline uint8_t QSCI_ReadByte(QSCI_Type *base)
{
    return (uint8_t)(base->DATA);
}

/*!
 * @brief Writes TX register using a blocking method.
 *
 * This function polls the TX register, waits TX register to be empty or TX FIFO
 * have room then writes data to the TX buffer.
 *
 * @param base QSCI peripheral base address.
 * @param pu8Data Start address of the data to write.
 * @param u32Length Size of the data to write.
 */
void QSCI_WriteBlocking(QSCI_Type *base, const uint8_t *pu8Data, uint32_t u32Length);

/*!
 * @brief Reads RX data register using a blocking method.
 *
 * This function polls the RX register, waits RX register to be full or RX FIFO
 * have data, then reads data from the RX register.
 *
 * @param base QSCI peripheral base address.
 * @param pu8Data Start address of the buffer to store the received data.
 * @param u32Length Size of the buffer.
 * @retval #kStatus_Fail Receiver error occurred while receiving data.
 * @retval #kStatus_QSCI_RxHardwareOverrun Receiver overrun occurred while receiving data
 * @retval #kStatus_QSCI_NoiseError Noise error occurred while receiving data
 * @retval #kStatus_QSCI_FramingError error occurred while receiving data
 * @retval #kStatus_QSCI_ParityError Parity error occurred while receiving data
 * @retval #kStatus_Success Successfully received all data.
 */
status_t QSCI_ReadBlocking(QSCI_Type *base, uint8_t *pu8Data, uint32_t u32Length);

/*!
 * @brief Sends one break character (10 or 11 bits of zeroes).
 *
 * @param base QSCI peripheral base address.
 */
static inline void QSCI_SendBreak(QSCI_Type *base)
{
    base->CTRL1 |= QSCI_CTRL1_SBK_MASK;
    base->CTRL1 &= ~QSCI_CTRL1_SBK_MASK;
}
/*! @} */

/*!
 * @name Transactional APIs
 * @{
 */
/*!
 * @brief Initializes the QSCI handle.
 *
 * This function initializes the QSCI handle which can be used for other QSCI transactional APIs. Usually, for a
 * specified QSCI instance, call this API once to get the initialized handle.
 *
 * @param base QSCI peripheral base address.
 * @param psHandle QSCI handle pointer.
 * @param pfCallback The callback function.
 * @param pUserData The parameter of the callback function.
 */
void QSCI_TransferCreateHandle(QSCI_Type *base,
                               qsci_transfer_handle_t *psHandle,
                               qsci_transfer_callback_t pfCallback,
                               void *pUserData);

/*!
 * @brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific QSCI handle.
 *
 * When the RX ring buffer is used, data received are stored into the ring buffer even when the
 * user doesn't call the QSCI_TransferReceiveNonBlocking() API. If data is already received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 *
 * @note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if @p ringBufferSize is 32, only 31 bytes are used for saving data.
 *
 * @param psHandle QSCI handle pointer.
 * @param pu8RxRingBuffer Start address of the ring buffer for background receiving. Pass NULL to disable the ring
 * buffer.
 * @param u16RxRingBufferSize Size of the ring buffer.
 */
void QSCI_TransferStartRingBuffer(qsci_transfer_handle_t *psHandle,
                                  uint8_t *pu8RxRingBuffer,
                                  uint16_t u16RxRingBufferSize);

/*!
 * @brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * @param psHandle QSCI handle pointer.
 */
void QSCI_TransferStopRingBuffer(qsci_transfer_handle_t *psHandle);

/*!
 * @brief Get the ring buffer valid data length.
 *
 * @param psHandle QSCI handle pointer.
 * @return Valid data length in ring buffer.
 */
uint16_t QSCI_TransferGetRxRingBufferLength(qsci_transfer_handle_t *psHandle);

/*!
 * @brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using an interrupt method. This is a non-blocking function, which
 * returns directly without waiting for all data to be written to the TX register. When
 * all data is sent out, the QSCI driver calls the callback function and passes the
 * @ref kStatus_QSCI_TxIdle as status parameter.
 *
 * @param psHandle QSCI handle pointer.
 * @param psTransfer QSCI transfer structure. See #qsci_transfer_t.
 * @retval #kStatus_Success Successfully start the data transmission.
 * @retval #kStatus_QSCI_TxBusy Previous transmission still not finished; data not all written to TX register yet.
 */
status_t QSCI_TransferSendNonBlocking(qsci_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer);

/*!
 * @brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt-driven data sending. The user can get the remainBytes to find out
 * how many bytes are not sent out.
 *
 * @param psHandle QSCI handle pointer.
 */
void QSCI_TransferAbortSend(qsci_transfer_handle_t *psHandle);

/*!
 * @brief Gets the number of bytes sent out to bus.
 *
 * This function gets the number of bytes sent out to bus by using the interrupt method.
 *
 * @param psHandle QSCI handle pointer.
 * @param pu32Count Send bytes count.
 * @retval #kStatus_NoTransferInProgress No send in progress.
 * @retval #kStatus_Success Get successfully through the parameter \p count;
 */
status_t QSCI_TransferGetSendCount(qsci_transfer_handle_t *psHandle, uint32_t *pu32Count);

/*!
 * @brief Receives a buffer of data using an interrupt method.
 *
 * This function receives data using an interrupt method. This is a non-blocking function, which
 *  returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in the ring buffer is copied and
 * the parameter @p pu32ReceivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in the ring buffer is not enough to read, the receive
 * request is saved by the QSCI driver. When the new data arrives, the receive request
 * is serviced first. When all data is received, the QSCI driver notifies the upper layer
 * through a callback function and passes the status parameter @ref kStatus_QSCI_RxIdle.
 * For example, the upper layer needs 10 bytes but there are only 5 bytes in the ring buffer.
 * The 5 bytes are copied to the psTransfer->data and this function returns with the
 * parameter @p pu32ReceivedBytes set to 5. For the left 5 bytes, newly arrived data is
 * saved from the psTransfer->data[5]. When 5 bytes are received, the QSCI driver notifies the upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to the psTransfer->data. When all data is received, the upper layer is notified.
 *
 * @param psHandle QSCI handle pointer.
 * @param psTransfer QSCI transfer structure, see #qsci_transfer_t.
 * @param pu32ReceivedBytes Bytes received from the ring buffer directly.
 * @retval #kStatus_Success Successfully queue the transfer into transmit queue.
 * @retval #kStatus_QSCI_RxBusy Previous receive request is not finished.
 */
status_t QSCI_TransferReceiveNonBlocking(qsci_transfer_handle_t *psHandle,
                                         qsci_transfer_t *psTransfer,
                                         uint32_t *pu32ReceivedBytes);

/*!
 * @brief Aborts the interrupt-driven data receiving.
 *
 * This function aborts the interrupt-driven data receiving. The user can get the remainBytes to know
 * how many bytes are not received yet.
 *
 * @param psHandle QSCI handle pointer.
 */
void QSCI_TransferAbortReceive(qsci_transfer_handle_t *psHandle);

/*!
 * @brief Gets the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * @param psHandle QSCI handle pointer.
 * @param pu32Count Receive bytes count.
 * @retval #kStatus_NoTransferInProgress No receive in progress.
 * @retval #kStatus_InvalidArgument Parameter is invalid.
 * @retval #kStatus_Success Get successfully through the parameter \p pu32Count;
 */
status_t QSCI_TransferGetReceivedCount(qsci_transfer_handle_t *psHandle, uint32_t *pu32Count);
/*! @} */

/*!
 * @brief Get the QSCI instance from peripheral base address.
 *
 * @param base QSCI peripheral base address.
 * @return QSCI instance.
 */
uint16_t QSCI_GetInstance(QSCI_Type *base);

#if defined(__cplusplus)
}
#endif;

/*! @}*/

#endif /* FSL_QSCI_H_*/
