/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_QSPI_H_
#define FSL_QSPI_H_

#include "fsl_common.h"

/*!
 * @defgroup qspi_driver QSPI: Queued SPI Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief QSPI driver version. */
#define FSL_QSPI_DRIVER_VERSION (MAKE_VERSION(2, 1, 1))
/*! @} */

/*!
 * @defgroup queuedspi_driver_log The Driver Change Log
 * @ingroup qspi_driver
 * @{
 * The current QueueSpi driver version is 2.1.1.
 *
 * - 2.1.1
 *   - Bug Fixes
 *     - Fixed wrong baudrate calculation method.
 * - 2.1.0
 *   - Bug Fixes
 *     - Fixed wrong definitions of interrupt enable/disable masks.
 *     - Fixed wrong usage of QSPI_DisableInterrupts.
 *     - Fixed wrong type casts.
 *     - Fixed bug for master blocking transfer of rx FIFO overflow.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*!
 * @defgroup qspi_driver_intro QSPI Peripheral and Driver Overview
 * @ingroup qspi_driver
 * @brief Content including 1) peripheral features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral feature
 * =================================================
 * The serial peripheral interface (SPI) module enables full-duplex, synchronous, serial
 * communication between the chip and peripheral devices, including other chips. Software
 * can poll the SPI status flags or SPI operation can be interrupt driven. The block contains
 * six 16-bit memory mapped registers for control parameters, status, and data transfer.
 *
 * Features of the SPI module include the following:
 *  - Full-duplex operation
 *  - Master and slave modes
 *  - Double-buffered operation with separate transmit and receive registers
 *  - Programmable Length Transactions (2 to 16 bits)
 *  - Programmable transmit and receive shift order (MSB or LSB first)
 *  - Fourteen master mode frequencies (maximum = bus frequency / 2)
 *  - Maximum slave mode frequency = bus frequency / 4
 *  - Serial clock with programmable polarity and phase
 *  - Two separately enabled interrupts:
 *    + SPRF (SPI receiver full)
 *    + SPTE (SPI transmitter empty)
 *  - Mode fault error flag with interrupt capability
 *  - Overflow error flag with interrupt capability
 *  - Wired OR mode functionality enabling connection to multiple SPIs
 *  - Stop mode holdoff
 *  - Separate RX and TX FIFO capable of handling 4 transactions
 *
 * Signals
 *  - MOSI : Master-Output Slave-Input Pad Pin
 *  - MISO : Master-Input Slave-Output Pad Pin
 *  - SCLK : Slave clock pad pin
 *  - SS   : Slave select pad pin (Active Low)
 *
 * How this driver is designed to make this peripheral works
 * =========================================================
 *
 * The Queued SPI driver is provided with 2 parallel layers for different users with different requirements on
 * flexibility, abstraction level: Functional layer and Transactional layer. Do not mix the usage of these layers with
 * one exception that transactional layer need the QSPI_MasterInit and QSPI_SlaveInit. See detail in section
 * transactional- layer-usage-model.
 *  - Functional Layer is provided with highly optimized implementation and highly flexible usage of the peripheral
 * features. All hardware features are supported while requiring user get a decent understanding of the hardware detail
 * so that user know how to organize these functional API together to meet the requirement of application.
 *  - Transactional layer is provided with high abstraction level, limited flexibility / optimization and not all
 * features are covered. It aims at getting user implement Queued SPI transaction with least knowledge requirement of
 * this specific Queued SPI peripheral and least coding effort. It achieves this goal by hiddening the interrupt
 * processing setup inside driver and providing functionaly from transaction level. To distinguish transactional layer
 * for functional layer easily, all transactional API get 'Transfer' in API name.
 *
 * SPI peripheral is working either as the role of Master or Slave. Functions in both layers get the Master/Slave inside
 * meaning they are prepared for Master or Slave, other wise it apply for both Master/Slave mode.
 *
 * Functional Layer
 * --------------------
 *
 * This layer provider multiple function API sorted in groups
 *  - Module Init/Deinit
 *      + Module Initialization function for Master or Slave with their help function QSPI_MasterGetDefault and
 * QSPI_SlaveGetDefault.
 *      + Deinitialization is for both Master or Salve.
 *  - FIFO Configuration
 *      + APIs for FIFO relevant features.
 *  - DMA Configuration
 *      + APIs for DMA relevant features.
 *  - Slave Select(SS) Configuration
 *      + APIs for Slave Select (SS) related features.
 *  - Status Flags Get/Clear
 *      + APIs to Get/Clear all supported status flags.
 *  - Interrupt Configuration
 *      + APIs to Enable/Disable interrupts.
 *  - Bus Operation
 *      + APIs for SPI data transfer.
 *  - General Configuration
 *      + APIs for features not covered in above groups.
 *
 * Transactional Layer
 * --------------------
 *
 * Transactional layer is state retained thus it use the @ref qspi_master_transfer_handle_t or
 * @ref qspi_slave_transfer_handle_t to specify the peripheral. User need to initialize the handle by calling
 * QSPI_MasterTransferCreateHandle or QSPI_SlaveTransferCreateHandle.
 *
 * Transactional layer abstract the provided functionality in transaction level rather than peripheral register level.
 * The background knowledgement requested from user is the common SPI transaction model with optional peripheral
 * specific transfer configuration for transaction. This layer use the data structure @ref qspi_transfer_t to describe a
 * transfer
 *  - Tranmit data buffer if applicable
 *  - Receive data buffer if applicable
 *  - Size of Transmit/Receive buffer
 *  - Peripheral specific configuration from @ref _qspi_master_transfer_flag
 *
 * Transaction get 2 modes: Blocking and NonBlocking. Blocking is using the polling mode while NonBlocking using the
 * interrupt or DMA. In Blocking mode, not context need to be kept on return of the function calling thus handle
 * parameter is not needed.
 *
 * Transactional layer greatly simplify the interrupt handling coding efforts
 *   - Interrupt handling codes are automatically active when user get this driver files into application project. This
 *     is provided by the 'double weak' mechanism. You can find the detail in the general section of API Reference
 * Manual. In breif, SDK place a weak function A in the vector entry for this periperhal. The default implementation of
 * this function call another weak function B. By default, when a interrupt happen, the code will be executed as A
 * (Weak) -> B (Weak). This driver provide the function B thus once user get the driver file into the application
 * project, when interrupt happend, code will be executed as A (Weak) -> B (Non-Weak, in this driver) thus user is no
 * longer need to do with the interrupt handling himself. If user get his/her own requirement of interrupt handling,
 * define the A in the application and interrupt will be routed to his/her own interrupt function.
 *   - Hidden interrupt handling doesn't mean user get no chance to insert his/her processing logic in the interrupt
 * handling. User is requested to provide the callback function on QSPI_MasterCreateHandle or
 * QSPI_SlaveTransferCreateHandle and when interrupt happens, callback will be invoked immediately that user codes can
 * be executed when interrupt happens. In the callback, user code will be notified about status code from @ref
 * _qspi_status or generic status of the transaction requested.
 *
 * This layer provider multiple function API sorted in groups
 *  - Master Transaction
 *      + APIs for transaction as Master
 *  - Slave Transaction
 *      + APIs for transaction as Slave
 *
 * How to use this driver
 * ======================
 *
 * General Preprocessor Configuraiton Macros
 * -----------------------------------------
 * - FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL
 *     SDK genneral Macro, controls whether to ungate/gate peripheral's clock source inside driver. Set it to none-zero
 *     value then driver will not ungate/gate clock source during initialization/de-initialization.
 * - QSPI_DUMMY_DATA
 *      For transaction receiving with no Transmit data needed, DUMMY data specify the data to be put in the MOSI as
 * master or MISO as slave. By default, it is all 0 bit.
 *
 * Configuration Items Before Calling Driver APIs
 * --------------------------------------------------
 *  - Mux the QUEUESPI MISO/MOSI/SCLK/SS signals to on-board pins, and configure them with expected port pin feature.
 *  - Select and attach proper clock source to this module.
 *  - Ungate the QUEUESPI clock if user wish to do it outside driver by setting FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL to
 *    non-zero value.
 *  - Set the priority base for the IRQ needed by the SPI module.
 *
 * Functional layer usage model
 * ------------------------------
 *  - Configuration Items Before Calling Driver APIs
 *      + Except the items described in the general part, define the QUEUEDSPI interrupt entry in the application code
 *        if interrupt is needed for this peripheral usage.
 *  - Call flow
 *      + Init the module with QSPI_MasterInit or QSPI_SlaveInit. Note QSPI_MasterGetDefaultConfig or
 *        QSPI_SlaveGetDefaultConfig can help user to get a ready-to-use init data structure.
 *      + Do the QUEUEDSPI transaction with other functional layer APIs
 *
 * Transactional layer usage model
 * ------------------------------
 *  - Call flow for Polling-Based Master Transaction
 *      + Init the module with QSPI_MasterInit or QSPI_SlaveInit. Note QSPI_MasterGetDefaultConfig or
 *        QSPI_SlaveGetDefaultConfig can help user to get a ready-to-use init data structure.
 *      + Do the transfer with QSPI_MasterTransferBlocking
 *  - Call flow for Polling-Based transaction
 *      + Init the module with QSPI_MasterInit or QSPI_SlaveInit. Note QSPI_MasterGetDefaultConfig or
 *        QSPI_SlaveGetDefaultConfig can help user to get a ready-to-use init data structure.
 *      + Init the handle with QSPI_MasterCreateHandle or QSPI_SlaveTransferCreateHandle with callback function
 *        registered if applicable
 *      + Do transaction with QSPI_MasterTransferNonBlocking or QSPI_SlaveTransferNonBlocking if applicable
 *      + User can query how many data are transferred by QSPI_MasterGetTranferGetCount or QSPI_SlaveTransferGetCount
 *      + User can abort transaction by QSPI_MasterGetTranferAbort or QSPI_SlaveTransferAbort
 *
 * Typical Use Cases
 * -----------------
 * NA
 *
 * @}
 */

/**********************************************************************************************************************
 * Definitions
 *********************************************************************************************************************/

#ifndef QSPI_DUMMY_DATA
/*! @brief User Configuraiton item dummy data filled into Output signal if there is no Tx data.*/
#define QSPI_DUMMY_DATA (0x00U) /*!< Dummy data used for Tx if there is no txData. */
#endif

/*!
 * @brief Status return code for the QUEUEDSPI driver. Only used in transactional layer in this driver.
 * @anchor _qspi_status
 */
enum
{
    kStatus_QSPI_Busy       = MAKE_STATUS(kStatusGroup_QUEUEDSPI, 0), /*!< QUEUEDSPI transfer is busy.*/
    kStatus_QSPI_Error      = MAKE_STATUS(kStatusGroup_QUEUEDSPI, 1), /*!< QUEUEDSPI driver error. */
    kStatus_QSPI_Idle       = MAKE_STATUS(kStatusGroup_QUEUEDSPI, 2), /*!< QUEUEDSPI is idle.*/
    kStatus_QSPI_OutOfRange = MAKE_STATUS(kStatusGroup_QUEUEDSPI, 3)  /*!< QUEUEDSPI transfer out of range. */
};

/*! @brief QUEUEDSPI peripheral status flags.*/
enum _qspi_status_flags
{
    kQSPI_TxEmptyFlag    = QSPI_SPSCR_SPTE_MASK, /*!< Transmitter Empty Flag. */
    kQSPI_ModeFaultFlag  = QSPI_SPSCR_MODF_MASK, /*!< Mode Fault Flag. */
    kQSPI_RxOverflowFlag = QSPI_SPSCR_OVRF_MASK, /*!< Receiver Overflow Flag. */
    kQSPI_RxFullFlag     = QSPI_SPSCR_SPRF_MASK, /*!< Receiver Full Flag. */
    kQSPI_AllStatusFlags = kQSPI_TxEmptyFlag | kQSPI_ModeFaultFlag | kQSPI_RxOverflowFlag | kQSPI_RxFullFlag
};

/*! @brief QUEUEDSPI interrupt source */
enum _qspi_interrupt_enable
{
    kQSPI_TxInterruptEnable         = (QSPI_SPSCR_SPTIE_MASK >> 4U), /*!< SPTE interrupt enable.*/
    kQSPI_RxInterruptEnable         = (QSPI_SPSCR_SPRIE_MASK >> 4U), /*!< SPRF interrupt enable.*/
    kQSPI_RxOverFlowInterruptEnable = (QSPI_SPSCR_ERRIE_MASK >> 4U), /*!< Bus error interrupt enable.*/
    kQSPI_AllInterrupts = kQSPI_TxInterruptEnable | kQSPI_RxInterruptEnable | kQSPI_RxOverFlowInterruptEnable
};

/*! @brief options for Slave Select (SSB) signal direction. */
typedef enum _qspi_ss_direction
{
    kQSPI_SlaveSelectDirectionInput =
        0U, /*!< SSB signal as input for slave mode or master mode with Mode fault enabled. */
    kQSPI_SlaveSelectDIrectionOutput = 1U, /*!< SSB signal as output. */
} qspi_ss_direction_t;

/*! @brief logical level for Slave Select (SSB) signal data */
typedef enum _qspi_ss_data_logic_level
{
    kQSPI_SlaveSelectLogicLow  = 0U, /*!< Slave select logic level low */
    kQSPI_SlaveSelectLogicHigh = 1U  /*!< Slave select logic level high */
} qspi_ss_data_logic_level_t;

/*! @brief QUEUEDSPI Transmit FIFO watermark settings.*/
typedef enum _qspi_txfifo_watermark
{
    kQSPI_TxFifoWatermarkEmpty   = 0U, /*!< Transmit interrupt active when Tx FIFO is empty */
    kQSPI_TxFifoWatermarkOneWord = 1U, /*!< Transmit interrupt active when Tx FIFO has one or fewer words available */
    kQSPI_TxFifoWatermarkTwoWord = 2U, /*!< Transmit interrupt active when Tx FIFO has two or fewer words available */
    kQSPI_TxFifoWatermarkThreeWord =
        3U /*!< Transmit interrupt active when Tx FIFO has three or fewer words available */
} qspi_txfifo_watermark_t;

/*! @brief QUEUEDSPI Receive FIFO watermark settings.*/
typedef enum _qspi_rxfifo_watermark
{
    kQSPI_RxFifoWatermarkOneWord   = 0U, /*!< Receive interrupt active when Rx FIFO has at least one word used */
    kQSPI_RxFifoWatermarkTwoWord   = 1U, /*!< Receive interrupt active when Rx FIFO has at least two words used */
    kQSPI_RxFifoWatermarkThreeWord = 2U, /*!< Receive interrupt active when Rx FIFO has at least three words used */
    kQSPI_RxFifowatermarkFull      = 3U  /*!< Receive interrupt active when Rx FIFO is full */
} qspi_rxfifo_watermark_t;

/*! @brief Transfer data width in each frame */
typedef enum _qspi_data_width
{
    kQSPI_Data2Bits  = 1U,  /*!< 2 bits data width */
    kQSPI_Data3Bits  = 2U,  /*!< 3 bits data width */
    kQSPI_Data4Bits  = 3U,  /*!< 4 bits data width */
    kQSPI_Data5Bits  = 4U,  /*!< 5 bits data width */
    kQSPI_Data6Bits  = 5U,  /*!< 6 bits data width */
    kQSPI_Data7Bits  = 6U,  /*!< 7 bits data width */
    kQSPI_Data8Bits  = 7U,  /*!< 8 bits data width */
    kQSPI_Data9Bits  = 8U,  /*!< 9 bits data width */
    kQSPI_Data10Bits = 9U,  /*!< 10 bits data width */
    kQSPI_Data11Bits = 10U, /*!< 11 bits data width */
    kQSPI_Data12Bits = 11U, /*!< 12 bits data width */
    kQSPI_Data13Bits = 12U, /*!< 13 bits data width */
    kQSPI_Data14Bits = 13U, /*!< 14 bits data width */
    kQSPI_Data15Bits = 14U, /*!< 15 bits data width */
    kQSPI_Data16Bits = 15U, /*!< 16 bits data width */
} qspi_data_width_t;

/*! @brief QUEUEDSPI DMA configuration for Transmit and Receive.*/
enum _qspi_dma_enable_flags
{
    kQSPI_DmaRx = 1U, /*!< Receive DMA Enable Flag. */
    kQSPI_DmaTx = 2U, /*!< Transmit DMA Enable Flag. */
};

/*! @brief QUEUEDSPI master or slave mode configuration.*/
typedef enum _qspi_master_slave_mode
{
    kQSPI_Slave  = 0U, /*!< QUEUEDSPI peripheral operates in slave mode.*/
    kQSPI_Master = 1U, /*!< QUEUEDSPI peripheral operates in master mode.*/
} qspi_master_slave_mode_t;

/*! @brief QUEUEDSPI clock polarity configuration.*/
typedef enum _qspi_clock_polarity
{
    kQSPI_ClockPolarityActiveRisingEdge =
        0U, /*!< CPOL=0. Active-high QUEUEDSPI clock (idles low), rising edge of SCLK starts transaction.*/
    kQSPI_ClockPolarityActiveFallingEdge =
        1U /*!< CPOL=1. Active-low QUEUEDSPI clock (idles high), falling edge of SCLK starts transaction.*/
} qspi_clock_polarity_t;

/*! @brief QUEUEDSPI clock phase configuration.*/
typedef enum _qspi_clock_phase
{
    kQSPI_ClockPhaseSlaveSelectHighBetweenWords = 0U, /*!< CPHA=0, Slave Select toggle high during data frames. */
    kQSPI_ClockPhaseSlaveSelectLowBetweenWords  = 1U  /*!< CPHA=1, Slave Select keep low during data frames.*/
} qspi_clock_phase_t;

/*! @brief QUEUEDSPI data shifter direction options for a given CTAR.*/
typedef enum _qspi_data_shift_direction
{
    kQSPI_MsbFirst = 0U, /*!< Data transfers start with most significant bit.*/
    kQSPI_LsbFirst = 1U  /*!< Data transfers start with least significant bit.*/
} qspi_data_shift_direction_t;

/*! @brief QUEUEDSPI master configuration structure with all master configuration fields covered. */
typedef struct _qspi_master_config
{
    /* Baud rate in bit per second */
    uint32_t u32BaudRateBps;      /*!< Baud Rate for QUEUEDSPI. */
    uint32_t u32ClockFrequencyHz; /*<! Clock frequency for peripheral */

    /* Transfer configuration */
    qspi_data_width_t eDataWidth : 4;                /*!< Data width in SPI transfer */
    qspi_clock_polarity_t eClkPolarity : 1;          /*!< Clock polarity. */
    qspi_clock_phase_t eClkPhase : 1;                /*!< Clock phase. */
    qspi_data_shift_direction_t eShiftDirection : 1; /*!< MSB or LSB data shift direction. */
    bool bEnableWiredOrMode : 1; /*!< SPI pin configuration, when enabled the SPI pins are configured as open-drain
                                drivers with the pull-ups disabled. */

    /* Slave Select signal configuration */
    bool bEnableModeFault : 1; /*!< Enable/Disable mode fault detect for Slave Select Signal */
    bool bEnableStrobe : 1;    /*!< Enable/Disable strobe between data frames irrespective of clock pahse setting */
    bool bEnableSlaveSelAutoMode : 1;   /*!< Enable/Disable Slave Select Auto mode.*/
    bool bEnableSlaveSelOpenDrain : 1;  /*!< Enable the open-drain mode of SPI Pins, otherwise Push-Pull */
    uint16_t u16DelayBetweenFrameInCLK; /*!< The delay between frame.*/

    /* FIFO Configuration */
    bool bEnableFIFO : 1;                         /*!< Enable / Disable FIFO for Transmit/Receive */
    qspi_txfifo_watermark_t eTxFIFOWatermark : 2; /*!< Watermark config for Transmit FIFO */
    qspi_txfifo_watermark_t eRxFIFOWatermark : 2; /*!< Watermark config for Receive FIFO */

    /* Power Control */
    bool bEnableStopModeHoldOff : 1; /*<! Enable/Disable hold off stop mode on data transmitting/receiving */

    /* General Configuraiton */
    bool bEnableModule : 1; /*!< Enable / Disable module */

    /* Interrupt / DMA COnfig */
    uint8_t u8Interrupts : 8;     /*!< Interrupt enabled ORed from @ref _qspi_interrupt_enable */
    uint8_t u8DmaEnableFlags : 8; /*!< Configure DMA Enable/Disable for Transmit/Receive */
} qspi_master_config_t;

/*! @brief QUEUEDSPI slave configuration structure with all slave configuration fields covered.*/
typedef struct _qspi_slave_config
{
    /* Transfer configuration */
    qspi_data_width_t eDataWidth : 4;                /*!< Data width in SPI transfer */
    qspi_clock_polarity_t eClkPolarity : 1;          /*!< Clock polarity. */
    qspi_clock_phase_t eClkPhase : 1;                /*!< Clock phase. */
    qspi_data_shift_direction_t eShiftDirection : 1; /*!< MSB or LSB data shift direction. */
    bool bEnableWiredOrMode : 1; /*!< SPI pin configuration, when enabled the SPI pins are configured as open-drain
                                drivers with the pull-ups disabled. */
    bool bEnableModeFault : 1;   /*!< Enable/Disable mode fault detect for Slave Select Signal */

    /* Slave Select Signal */
    bool bEnableSlaveSelOverride : 1; /*!< Enable/Disble override Slave Select (SS) singal with Master/Slave Mode config
                                       */

    /* FIFO Configuration */
    bool bEnableFIFO : 1;                         /*!< Enable / Disable FIFO for Transmit/Receive */
    qspi_txfifo_watermark_t eTxFIFOWatermark : 2; /*!< Watermark config for Transmit FIFO */
    qspi_txfifo_watermark_t eRxFIFOWatermark : 2; /*!< Watermark config for Receive FIFO */

    /* Power Control */
    bool bEnableStopModeHoldOff : 1; /*<! Enable/Disable hold off stop mode on data transmitting/receiving */
    bool bEnableModule : 1;          /*!< Enable/Disable Module */

    /* Interrupt/DMA configuration */
    uint8_t u8Interrupts;
    uint8_t u8DmaEnableFlags; /*!< Configure DMA Enable/Disable for Transmit/Receive */
} qspi_slave_config_t;

/* ==================== Start Of Transactional Layer Definition =================== */
/*! @brief QUEUEDSPI Peripheral Chip Select Polarity configuration.*/
typedef enum _qspi_pcs_polarity_config
{
    kQSPI_PcsActiveHigh = 0U, /*!< Pcs Active High (idles low). */
    kQSPI_PcsActiveLow  = 1U  /*!< Pcs Active Low (idles high). */
} qspi_pcs_polarity_config_t;

/*!
 * @brief transaction layer configuration options for each transaction
 */
enum _qspi_master_transfer_flag
{
    kQSPI_MasterPCSContinous = 1U, /*!< Indicates whether the PCS signal de-asserts during transfer between frames, note
                                 this flag should not be used when CPHA is 0. */
    kQSPI_MasterActiveAfterTransfer = 2U /*!< Indicates whether the PCS signal is active after the last frame transfer,
                                         note 1. this flag should not be used when CPHA is 0, 2. this flag can only be
                                       used when kQSPI_MasterPCSContinous is used. */
};

/*! @brief QUEUEDSPI transfer state, used internally for transactional layer. */
enum _qspi_transfer_state
{
    kQSPI_Idle = 0x0U, /*!< Nothing in the transmitter/receiver. */
    kQSPI_Busy,        /*!< Transfer queue is not finished. */
    kQSPI_Error        /*!< Transfer error. */
};

/*! @brief QUEUEDSPI master/slave transfer structure.*/
typedef struct _qspi_transfer
{
    void *pTxData;                 /*!< Transmit buffer. */
    void *pRxData;                 /*!< Receive buffer. */
    volatile uint16_t u16DataSize; /*!< Transfer bytes. */
    uint8_t u8ConfigFlags; /*!< Transfer configuration flags; set from @ref _qspi_master_transfer_flag. This is not used
                              in slave transfer. */
} qspi_transfer_t;

/*!
 * @brief Forward declaration of the _qspi_master_handle typedefs.
 * @anchor qspi_master_transfer_handle_t
 */
typedef struct _qspi_master_handle qspi_master_transfer_handle_t;

/*!
 * @brief Completion callback function pointer type.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param psHandle Pointer to the handle for the QUEUEDSPI master.
 * @param eCompletionStatus Success or error code describing whether the transfer completed.
 * @param pUserData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*qspi_master_transfer_callback_t)(qspi_master_transfer_handle_t *psHandle,
                                                status_t eCompletionStatus,
                                                void *pUserData);

/*! @brief QUEUEDSPI master transfer handle structure used for transactional API. */
struct _qspi_master_handle
{
    QSPI_Type *base;                         /*!< Base address for the QSPI peripheral */
    qspi_data_width_t eDataWidth;            /*!< The desired number of bits per frame. */
    volatile bool bIsPcsActiveAfterTransfer; /*!< Indicates whether the PCS signal is active after the last frame
                                                 transfer, This is not used in slave transfer.*/

    uint8_t *volatile pu8TxData;                    /*!< Send buffer. */
    uint8_t *volatile pu8RxData;                    /*!< Receive buffer. */
    volatile uint16_t u16RemainingSendByteCount;    /*!< A number of bytes remaining to send.*/
    volatile uint16_t u16RemainingReceiveByteCount; /*!< A number of bytes remaining to receive.*/
    uint16_t u16TotalByteCount;                     /*!< A number of transfer bytes*/

    volatile uint8_t u8State;                   /*!< QUEUEDSPI transfer state, see _qspi_transfer_state.*/
    qspi_master_transfer_callback_t pfCallback; /*!< Completion callback. */
    void *pUserData;                            /*!< Callback user data. */

    volatile uint16_t u16ErrorCount; /*!< Error count for slave transfer, this is not used in master transfer.*/
};

/*!
 * @brief Forward declaration of the _qspi_master_handle typedefs.
 * @anchor qspi_slave_transfer_handle_t
 */
typedef struct _qspi_master_handle qspi_slave_transfer_handle_t;

/*!
 * @brief Completion callback function pointer type.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param handle Pointer to the handle for the QUEUEDSPI slave.
 * @param status Success or error code describing whether the transfer completed.
 * @param pUserData Arbitrary pointer-dataSized value passed from the application.
 */
typedef void (*qspi_slave_transfer_callback_t)(qspi_slave_transfer_handle_t *psHandle,
                                               status_t eCompletionStatus,
                                               void *pUserData);
/* ==================== End   Of Transactional Layer Definition =================== */

/**********************************************************************************************************************
 * API
 *********************************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*!
 * @name Module Initialization/Deinitialization
 * @{
 */
/*!
 * @brief Initializes the QUEUEDSPI as Master.
 *
 * Use helpher function QSPI_MasterGetDefaultConfig to get ready-to-use structure.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param psConfig Pointer to the structure qspi_master_config_t.
 */
void QSPI_MasterInit(QSPI_Type *base, const qspi_master_config_t *psConfig);

/*!
 * @brief Helper function to create ready-to-user maste init structure.
 *
 * The purpose of this API is to get the configuration structure initialized for the QSPI_MasterInit.
 * Users may use the initialized structure unchanged in the QSPI_MasterInit or modify the structure
 * before calling the QSPI_MasterInit.
 * Example:
 * @code
 *  qspi_master_config_t sMasterConfig;
 *  QSPI_MasterGetDefaultConfig(&sMasterConfig);
 * @endcode
 * The default values are:
 * Example:
 * @code
    // Parameter provided by user
    psConfig->u32BaudRateBps = u32BaudRateBps;
    psConfig->u32ClockFrequencyHz = u32ClockFreqHz;
    psConfig->eDataWidth = eDataWidth;

    // Default configuration
    psConfig->eClkPolarity = kQSPI_ClockPolarityActiveRisingEdge;
    psConfig->eClkPhase = kQSPI_ClockPhaseSlaveSelectHighBetweenWords;
    psConfig->eShiftDirection = kQSPI_MsbFirst;
    psConfig->u16DelayBetweenFrameInCLK = 1U;
    psConfig->bEnableWiredOrMode = false;
    psConfig->bEnableModeFault = false;
    psConfig->u8DmaEnableFlags = 0U;    // Disable TX/RX Dma
    psConfig->bEnableFIFO = false;
    psConfig->bEnableStopModeHoldOff = false;
    psConfig->u8Interrupts = 0U;
    psConfig->bEnableModule = false;
 * @todo To be added
 * @endcode
 *
 * @param psConfig    pointer to qspi_master_config_t structure.
 * @param u32ClockFreqHz Peripheral clock frequency in Hz
 */
void QSPI_MasterGetDefaultConfig(qspi_master_config_t *psConfig, uint32_t u32ClockFreqHz);

/*!
 * @brief Initializes the QUEUEDSPI as slave.
 *
 * Use helpher function QSPI_SlaveGetDefaultConfig to get ready-to-use structure.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param psConfig Pointer to the structure qspi_slave_config_t.
 */
void QSPI_SlaveInit(QSPI_Type *base, const qspi_slave_config_t *psConfig);

/*!
 * @brief Set the qspi_slave_config_t structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for the QSPI_SlaveInit.
 * Users may use the initialized structure unchanged in the QSPI_SlaveInit or modify the structure
 * before calling the QSPI_SlaveInit.
 * Example:
 * @code
 *  qspi_slave_config_t slaveConfig;
 *  QSPI_SlaveGetDefaultConfig(&slaveConfig);
 * @endcode
 * The default values are:
 * Example:
 * @code
 * @todo
 * @endcode
 *
 * @param psConfig Pointer to the qspi_slave_config_t structure.
 */
void QSPI_SlaveGetDefaultConfig(qspi_slave_config_t *psConfig);

/*!
 * @brief De-initialize the QUEUEDSPI peripheral for either Master or Slave.
 *
 * @param base QUEUEDSPI peripheral address.
 */
void QSPI_Deinit(QSPI_Type *base);

/*! @} */

/*!
 * @name Interrupt APIs
 * @{
 */

/*!
 * @brief Enable one or multiple interrupts.
 *
 * This function enable one or multiple interrupts.
 *
 * @note for TX and RX requests, while enabling the interrupt request the DMA request will be disabled as well.
 * Do not use this API while QUEUEDSPI is in running state.
 *
 * @param base          QUEUEDSPI peripheral address.
 * @param u8Interrupts The interrupt mask which is ORed by the @ref _qspi_interrupt_enable.
 */
static inline void QSPI_EnableInterrupts(QSPI_Type *base, uint8_t u8Interrupts)
{
    if (u8Interrupts != 0U)
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) | (((uint16_t)u8Interrupts) << 4U);
    }
}

/*!
 * @brief Disable one or multiple interrupts.
 *
 * This function
 *
 * @param base QUEUEDSPI peripheral address.
 * @param u8Interrupts The interrupt mask which is ORed by the @ref _qspi_interrupt_enable.
 */
static inline void QSPI_DisableInterrupts(QSPI_Type *base, uint8_t u8Interrupts)
{
    if (u8Interrupts != 0U)
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) & (~(((uint16_t)u8Interrupts) << 4U));
    }
}

/*! @} */

/*!
 * @name DMA Operation APIs
 * @{
 */

/*!
 * @brief Enable one or multiple DMA
 *
 * Note that if the DMA is enabled for Transmit or Receive, make sure the interurpt is disabled for Transmit or Receive.
 *
 * @param base      QUEUEDSPI peripheral address.
 * @param u8DmaFlags DMA Flags ORed from @ref _qspi_dma_enable_flags.
 */
static inline void QSPI_EnableDMA(QSPI_Type *base, uint8_t u8DmaFlags)
{
    base->SPDSR = base->SPDSR | (((uint16_t)u8DmaFlags) << QSPI_SPDSR_RDMAEN_SHIFT);
}

/*!
 * @brief Enable one or multiple DMA
 *
 * Note that if the DMA is enabled for Transmit or Receive, make sure the interurpt is disabled for Transmit or Receive.
 *
 * @param base      QUEUEDSPI peripheral address.
 * @param u8DmaFlags DMA Flags ORed from @ref _qspi_dma_enable_flags.
 */
static inline void QSPI_DisableDMA(QSPI_Type *base, uint8_t u8DmaFlags)
{
    base->SPDSR = base->SPDSR & (~(((uint16_t)u8DmaFlags) << QSPI_SPDSR_RDMAEN_SHIFT));
}

/*!
 * @brief Get the QUEUEDSPI transmit data register address for the DMA operation.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return The QUEUEDSPI master PUSHR data register address.
 */
static inline uint32_t QSPI_GetTxRegisterAddress(QSPI_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(QSPI_Type, base, SPDTR);
}

/*!
 * @brief Get the QUEUEDSPI receive data register address for the DMA operation.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return The QUEUEDSPI POPR data register address.
 */
static inline uint32_t QSPI_GetRxRegisterAddress(QSPI_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(QSPI_Type, base, SPDRR);
}

/*! @} */

/*!
 * @name Status Get/Clear APIs
 * @{
 */

/*!
 * @brief Get the QUEUEDSPI status flag state.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return QUEUEDSPI status.
 */
static inline uint16_t QSPI_GetStatusFlags(QSPI_Type *base)
{
    return base->SPSCR & ((uint16_t)kQSPI_AllStatusFlags);
}

/*!
 * @brief Clear the status flag only for the mode fault
 *
 * Clear the status flag only for mode fault. @note only kQSPI_ModeFaultFlag can be cleared by this
 * API.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param u16StatusFlags status flags ORed from @ref _qspi_status_flags
 */
static inline void QSPI_ClearStatusFlags(QSPI_Type *base, uint16_t u16StatusFlags)
{
    assert(u16StatusFlags == (uint16_t)kQSPI_ModeFaultFlag);

    base->SPSCR |= (uint16_t)kQSPI_ModeFaultFlag;
}
/*! @} */

/*!
 * @name QUEUESPI Configuration
 * @{
 */
/*!
 * @brief Enable or disable the QUEUEDSPI peripheral.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable true to enable module, otherwise disable module
 */
static inline void QSPI_Enable(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) | QSPI_SPSCR_SPE_MASK;
    }
    else
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) & (~QSPI_SPSCR_SPE_MASK);
    }
}

/*!
 * @brief Set the QUEUEDSPI baud rate in bits-per-second.
 *
 * This function takes in the desired baud rate, calculates the nearest possible baud rate,
 * and returns the calculated baud rate in bits-per-second.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param u32BaudRateBps The desired baud rate in bits-per-second.
 * @param u32SrcClockHz Module source input clock in Hertz.
 * @return The actual calculated baud rate.
 */
uint32_t QSPI_MasterSetBaudRate(QSPI_Type *base, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz);

/*!
 * @brief Set the QUEUEDSPI as master or slave.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param eMode Mode setting of type qspi_master_slave_mode_t.
 */
static inline void QSPI_SetMasterSlaveMode(QSPI_Type *base, qspi_master_slave_mode_t eMode)
{
    base->SPSCR = base->SPSCR & (~(QSPI_SPSCR_SPMSTR_MASK | QSPI_SPSCR_MODF_MASK)) | QSPI_SPSCR_SPMSTR((uint16_t)eMode);
}

/*!
 * @brief Return whether the QUEUEDSPI module is in master mode.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return Returns true if the module is in master mode or false if the module is in slave mode.
 */
static inline bool QSPI_IsMaster(QSPI_Type *base)
{
    return (0U != ((base->SPSCR) & QSPI_SPSCR_SPMSTR_MASK));
}

/*!
 * @brief Set Data Shift Order as MSB first or LSB first
 *
 * @param base QUEUEDSPI peripheral address.
 * @param eDataShiftOrder MSB or LSB first from @ref qspi_data_shift_direction_t
 */
static inline void QSPI_SetDataShiftOrder(QSPI_Type *base, qspi_data_shift_direction_t eDataShiftOrder)
{
    if (eDataShiftOrder == kQSPI_MsbFirst)
    {
        base->SPSCR &= ~(QSPI_SPSCR_MODF_MASK | QSPI_SPSCR_DSO_MASK);
    }
    else
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) | QSPI_SPSCR_DSO_MASK;
    }
}

/*!
 * @brief Enable/Disable mode fault detection
 *
 * If enable, allows the kQSPI_ModeFaultFlag flag to be set. If the kQSPI_ModeFaultFlag flag is set,
 * disable the Mod detection does not clear the flag. If the mod detection is disabled, the level of the SS_B
 * pin does not affect the operation of an enabled SPI configured as a master. If configured as a master and
 * mod fault detection is enabled, a transaction in progress will stop if SS_B goes low.
 * For an enabled SPI configured as a slave, having this feature disabled only prevents the flag from being
 * set. It does not affect any other part of SPI operation
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable true to enable Mode Fault detection, false to disable
 */
static inline void QSPI_EnableModeFault(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) | QSPI_SPSCR_MODFEN_MASK;
    }
    else
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) & (~QSPI_SPSCR_MODFEN_MASK);
    }
}

/*!
 * @brief Set clock polarity
 *
 * @note module shall be disabled before change the polarity by calling QSPI_Enable.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param ePolarity clock polarity option
 */
static inline void QSPI_SetClockPolarity(QSPI_Type *base, qspi_clock_polarity_t ePolarity)
{
    if (ePolarity == kQSPI_ClockPolarityActiveFallingEdge)
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) | QSPI_SPSCR_CPOL_MASK;
    }
    else
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) & (~QSPI_SPSCR_CPOL_MASK);
    }
}

/*!
 * @brief Set clock phase
 *
 * Configure whether get the Slave Select signal toggle high during 2 data frames. Get the SS toggle high
 * between data frames will lead to SPI to be trigged with transaction for the falling edge of SS signal.
 * Otherwise, the data transaction is started on the first active SCLK edge.
 *
 * @note module shall be disabled before change the polarity by calling QSPI_Enable.
 * @note Do not use kQSPI_ClockPhaseSlaveSelectHighBetweenWords in DMA mode.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param eClockPhase Option for clock phase
 */
static inline void QSPI_SetClockPhase(QSPI_Type *base, qspi_clock_phase_t eClockPhase)
{
    if (eClockPhase == kQSPI_ClockPhaseSlaveSelectHighBetweenWords)
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) & (~QSPI_SPSCR_CPHA_MASK);
    }
    else
    {
        base->SPSCR = base->SPSCR & (~QSPI_SPSCR_MODF_MASK) | QSPI_SPSCR_CPHA_MASK;
    }
}

/*!
 * @brief Enable/Disable Wired OR mode for SPI pins which means open-drain when enabled and push-pull when disabled
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable true to configure SPI pins as open-drain, false to configure as push-pull
 */
static inline void QSPI_EnableWiredORMode(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPDSR |= QSPI_SPDSR_WOM_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_WOM_MASK;
    }
}

/*!
 * @brief Set the transaction data width
 *
 * @param base QUEUEDSPI peripheral address.
 * @param eDataWidth datawidth for bits in each data frame.
 */
static inline void QSPI_SetTransactionDataSize(QSPI_Type *base, qspi_data_width_t eDataWidth)
{
    base->SPDSR = base->SPDSR & (~QSPI_SPDSR_DS_MASK) | ((uint16_t)eDataWidth);
}

/*!
 * @brief For master mode, set wait delay in clock cycle with delay is set value + 1 peripheral bus clock
 *
 * This controls the time between data transactions in master mode. Delay will not be added if no word is waiting
 * for transmitting.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param u16WaitDelayInPeriClockCount Clock count for the delay during data frames
 */
static inline void QSPI_MasterSetWaitDelay(QSPI_Type *base, uint16_t u16WaitDelayInPeriClockCount)
{
    base->SPWAIT = u16WaitDelayInPeriClockCount;
}

/*!
 * @brief Enable/Disable hold off entry to stop mode is a word is being transmitted/received for Master Mode
 *
 * When enabled, this bit allows the SPI module to hold off entry to chip level stop mode if a word is being
 * transmitted or received. Stop mode will be entered after the SPI finishes transmitting/receiving. This bit
 * does not allow the SPI to wake the chip from stop mode in any way. The SHEN bit can only delay the
 * entry into stop mode. This bit should not be set in slave mode because the state of SS_B (which would be
 * controlled by an external master device) may cause the logic to hold off stop mode entry forever.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable true to enable hold-off entrying stop mode if there is transmitting/receiving
 */
static inline void QSPI_EnableStopModeHoldOff(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPCTL2 = 1U;
    }
    else
    {
        base->SPCTL2 = 0U;
    }
}

/*!
 * @brief Helper function exported for QSPI DMA driver
 *
 * Get the instance index from the base address. User need not understand this function.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return uint32_t Index of the peripheral instance for given base address.
 */
uint32_t QSPI_GetInstance(QSPI_Type *base);

/*! @} */

/*!
 * @name Slave Select (SS) singal
 * @{
 */

/*!
 * @brief For master mode, get the SS_B input logic level while true means drive High and false means drive Low
 *
 * Get the value to drive on the SS_B pin. This bit is disabled when SSB_AUTO=1 or SSB_STRB=1. Only apply for Master
 * mode.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return true SS_B input level High
 * @return false  SS_B input level Low
 */
static inline qspi_ss_data_logic_level_t QSPI_MasterGetSlaveSelectLogicLevel(QSPI_Type *base)
{
    return ((base->SPDSR & QSPI_SPDSR_SSB_IN_MASK) == 0U) ? kQSPI_SlaveSelectLogicLow : kQSPI_SlaveSelectLogicHigh;
}

/*!
 * @brief for master mode, drive Slave Select pin logic high or low
 *
 * This feature is disabled if Slave Select automatic mode is enabled or Slave Select Strobe feature is enabled
 *
 * @param base QUEUEDSPI peripheral address.
 * @param eLogicLevel  logic level
 */
static inline void QSPI_MasterSetSlaveSelectLogicLevel(QSPI_Type *base, qspi_ss_data_logic_level_t eLogicLevel)
{
    if (eLogicLevel == kQSPI_SlaveSelectLogicHigh)
    {
        base->SPDSR |= QSPI_SPDSR_SSB_DATA_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_DATA_MASK;
    }
}

/*!
 * @brief For master mode, Enable open drain in SSB pad pin
 *
 * Enable it means SS_B is configured for high and low drive. This mode is generally used in single master systems.
 * Disable it means SS_B is configured as an open drain pin (only drives low output level). This mode is useful for
 * multiple master systems
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable Enable/Disable option.
 */
static inline void QSPI_MasterEnableSlaveSelectOpenDrainMode(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPDSR |= QSPI_SPDSR_SSB_ODM_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_ODM_MASK;
    }
}

/*!
 * @brief For master mode, Enable/Disable Slave Select pin automatic mode
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable Enable/Disable option.
 */
static inline void QSPI_MasterEnableSlaveSelectAutomaticMode(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPDSR |= QSPI_SPDSR_SSB_AUTO_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_AUTO_MASK;
    }
}

/*!
 * @brief Set Input/Output mode for SSB signal
 *
 * @param base QUEUEDSPI peripheral address.
 * @param eDirection options from @ref qspi_ss_direction_t
 */
static inline void QSPI_SetSlaveSelectDirection(QSPI_Type *base, qspi_ss_direction_t eDirection)
{
    if (eDirection == kQSPI_SlaveSelectDIrectionOutput)
    {
        base->SPDSR |= QSPI_SPDSR_SSB_DDR_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_DDR_MASK;
    }
}

/*!
 * @brief For master, set strobe mode for SSB signal
 *
 * If enabled, Slave select pulse high during data frames irrespective of Clock Phase configuration
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable Enable/Disable option.
 */
static inline void QSPI_MasterEnableSlaveSelectStrobe(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPDSR |= QSPI_SPDSR_SSB_STRB_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_STRB_MASK;
    }
}

/*!
 * @brief Enable / Disable SSB signal from Master/Slave configuration or GPIO pin state
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable Enable/Disable option.
 */
static inline void QSPI_EnableSlaveSelectOverride(QSPI_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->SPDSR |= QSPI_SPDSR_SSB_OVER_MASK;
    }
    else
    {
        base->SPDSR &= ~QSPI_SPDSR_SSB_OVER_MASK;
    }
}

/*! @} */

/*!
 * @name Transmit/Receive Bus Operation
 * @{
 */

/*!
 * @brief Set up the dummy data used when there is not transmit data provided.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param u8DummyData Data to be transferred when tx buffer is NULL.
 */
void QSPI_SetDummyData(QSPI_Type *base, uint8_t u8DummyData);

/*!
 * @brief Get the dummy data for each peripheral
 *
 * @param base QUEUEDSPI peripheral base address.
 */
uint8_t QSPI_GetDummyData(QSPI_Type *base);

/*!
 * @brief Write data into the transmit data register without polling the status of shifting
 *
 * @param base QUEUEDSPI peripheral address.
 * @param data The data to send.
 */
static inline void QSPI_WriteData(QSPI_Type *base, uint16_t data)
{
    base->SPDTR = data;
}

/*!
 * @brief Read data from the receive data register
 *
 * @param base QUEUEDSPI peripheral address.
 * @return The data from the receive data register.
 */
static inline uint16_t QSPI_ReadData(QSPI_Type *base)
{
    return base->SPDRR;
}

/*! @} */

/*!
 * @name FIFO Operation APIs
 * @{
 */

/*!
 * @brief Enable or disable the QUEUEDSPI FIFOs.
 *
 * This function allows the caller to disable or enable the TX and RX FIFOs together.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param bEnable Pass true to enable, pass false to disable
 */
static inline void QSPI_EnableFifo(QSPI_Type *base, bool bEnable)
{
    base->SPFIFO = (base->SPFIFO & (~QSPI_SPFIFO_FIFO_ENA_MASK)) | QSPI_SPFIFO_FIFO_ENA((uint16_t)bEnable);
}

/*!
 * @brief Get TX FIFO level.
 *
 * This function gets how many words are in the TX FIFO.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return TX FIFO word count.
 */
static inline uint16_t QSPI_GetTxFIFOCount(QSPI_Type *base)
{
    return ((base->SPFIFO & QSPI_SPFIFO_TFCNT_MASK) >> QSPI_SPFIFO_TFCNT_SHIFT);
}

/*!
 * @brief Get RX FIFO level.
 *
 * This function gets how many words are in the RX FIFO.
 *
 * @param base QUEUEDSPI peripheral address.
 * @return RX FIFO word count.
 */
static inline uint16_t QSPI_GetRxFIFOCount(QSPI_Type *base)
{
    return ((base->SPFIFO & QSPI_SPFIFO_RFCNT_MASK) >> QSPI_SPFIFO_RFCNT_SHIFT);
}

/*!
 * @brief Set the transmit and receive FIFO watermark values.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param txWatermark The TX FIFO watermark value. Refer to qspi_txfifo_watermark_t for available values.
 * @param rxWatermark The RX FIFO watermark value. Refer to qspi_rxfifo_watermark_t for available values.
 */
static inline void QSPI_SetFifoWatermarks(QSPI_Type *base, uint16_t txWatermark, uint16_t rxWatermark)
{
    base->SPFIFO = (base->SPFIFO & (~(QSPI_SPFIFO_RFWM_MASK | QSPI_SPFIFO_TFWM_MASK))) |
                   (QSPI_SPFIFO_TFWM(txWatermark) | QSPI_SPFIFO_RFWM(rxWatermark));
}

/*!
 * @brief Get the transmit and receive FIFO watermark values.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param pu8TxWatermark The TX FIFO watermark value.
 * @param pu8RxWatermark The RX FIFO watermark value.
 */
static inline void QSPI_GetFifoWatermarks(QSPI_Type *base, uint8_t *pu8TxWatermark, uint8_t *pu8RxWatermark)
{
    assert((NULL != pu8RxWatermark) || (NULL != pu8TxWatermark));

    *pu8TxWatermark = (uint8_t)((base->SPFIFO & QSPI_SPFIFO_TFWM_MASK) >> QSPI_SPFIFO_TFWM_SHIFT);
    *pu8RxWatermark = (uint8_t)((base->SPFIFO & QSPI_SPFIFO_RFWM_MASK) >> QSPI_SPFIFO_RFWM_SHIFT);
}

/*!
 * @brief Empty the QUEUEDSPI RX FIFO.
 *
 * @param base QUEUEDSPI peripheral address.
 */
static inline void QSPI_EmptyRxFifo(QSPI_Type *base)
{
    while ((base->SPFIFO & QSPI_SPFIFO_RFCNT_MASK) != 0U)
    {
        (void)base->SPDRR;
    }
}

/*! @} */

/*!
 * @name Transactional Helper Apis to extract information from handle
 * @{
 */

/*!
 * @brief Extract Base Address from handle for master or slave handle
 *
 */
#define QSPI_TRANSFER_GET_BASE(handle) (handle->base)

/*!
 * @brief Extract user data from handle for master or slave handle
 *
 */
#define QSPI_TRANSFER_GET_USER_DATA(handle) (handle->pUserData)

/*! @} */

/*!
 * @name Transactional Master
 * @{
 */

/*!
 * @brief Initialize the QUEUEDSPI master handle.
 *
 * This function initializes the QUEUEDSPI handle, which can be used for other QUEUEDSPI transactional APIs. Usually,
 * for a specified QUEUEDSPI instance, call this API once to get the initialized handle.
 *
 * @note If only use the QSPI_MasterTransferBlocking, this API is not necessary be called.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param psHandle QUEUEDSPI handle pointer to qspi_master_transfer_handle_t.
 * @param pfCallback QUEUEDSPI callback.
 * @param pUserData Callback function parameter.
 */
void QSPI_MasterTransferCreateHandle(QSPI_Type *base,
                                     qspi_master_transfer_handle_t *psHandle,
                                     qspi_master_transfer_callback_t pfCallback,
                                     void *pUserData);

/*!
 * @brief Polling method of QUEUEDSPI master transfer.
 *
 * This function transfers data using a polling method for master. This is a blocking function,
 * which does not return until all transfers have been completed.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param psXfer Pointer to the qspi_transfer_t structure.
 * @return status of status_t.
 */
status_t QSPI_MasterTransferBlocking(QSPI_Type *base, qspi_transfer_t *psXfer);

/*!
 * @brief Interrupt method of QUEUEDSPI master transfer.
 *
 * This function transfers data using interrupts for master. This is a non-blocking function,
 * which returns right away. When all data is transferred, the callback function is called.
 *
 * @param psHandle QUEUEDSPI handle pointer to qspi_master_transfer_handle_t.
 * @param psXfer Pointer to the qspi_transfer_t structure.
 * @return status of status_t.
 */
status_t QSPI_MasterTransferNonBlocking(qspi_master_transfer_handle_t *psHandle, qspi_transfer_t *psXfer);

/*!
 * @brief Get the master transfer count.
 *
 * @param psHandle QUEUEDSPI handle pointer to qspi_master_transfer_handle_t.
 * @param pu16Count The number of bytes transferred by using the non-blocking transaction.
 * @return status of status_t.
 */
status_t QSPI_MasterTransferGetCount(qspi_master_transfer_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Abort a transfer that uses interrupts for master.
 *
 * @param psHandle QUEUEDSPI handle pointer to qspi_master_transfer_handle_t.
 */
void QSPI_MasterTransferAbort(qspi_master_transfer_handle_t *psHandle);

/*!
 * @brief QUEUEDSPI Master IRQ handler function.
 *
 * This function processes the QUEUEDSPI transmit and receive IRQ.
 *
 * @param psHandle QUEUEDSPI handle pointer to qspi_master_transfer_handle_t.
 */
void QSPI_MasterTransferHandleIRQ(qspi_master_transfer_handle_t *psHandle);

/*! @} */

/*!
 * @name Transactional Slave
 * @{
 */

/*!
 * @brief Initialize the QUEUEDSPI slave handle.
 *
 * This function initializes the QUEUEDSPI handle, which can be used for other QUEUEDSPI transactional APIs. Usually,
 * for a specified QUEUEDSPI instance, call this API once to get the initialized handle.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle QUEUEDSPI handle pointer to the qspi_slave_transfer_handle_t.
 * @param pfCallback QUEUEDSPI callback.
 * @param pUserData Callback function parameter.
 */
void QSPI_SlaveTransferCreateHandle(QSPI_Type *base,
                                    qspi_slave_transfer_handle_t *psHandle,
                                    qspi_slave_transfer_callback_t pfCallback,
                                    void *pUserData);

/*!
 * @brief Interrupt driven method of QUEUEDSPI slave transfer with completion will be notified by registered callback.
 *
 * This function transfers data using interrupts for slave. This is a non-blocking function,
 * which returns right away. When all data is transferred, the callback function is called.
 *
 * @param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 * @param psXfer Pointer to the qspi_transfer_t structure.
 * @return status of status_t.
 */
status_t QSPI_SlaveTransferNonBlocking(qspi_slave_transfer_handle_t *psHandle, qspi_transfer_t *psXfer);

/*!
 * @brief Get the slave transfer count already transmitted/received.
 *
 * @param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 * @param pu16Count The number of bytes transferred by using the non-blocking transaction.
 * @return status of status_t.
 */
status_t QSPI_SlaveTransferGetCount(qspi_slave_transfer_handle_t *psHandle, uint16_t *pu16Count);

/*!
 * @brief Abort a transaction.
 *
 * @param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferAbort(qspi_slave_transfer_handle_t *psHandle);

/*!
 * @brief QUEUEDSPI slave IRQ handler function.
 *
 * This function processes the QUEUEDSPI transmit and receive IRQ.
 *
 * @param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferHandleIRQ(qspi_slave_transfer_handle_t *psHandle);

/*! @} */

#if defined(__cplusplus)
}
#endif /*_cplusplus*/

/*! @}*/

#endif /*FSL_QSPI_H_*/
