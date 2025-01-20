/*
 * Copyright 2021-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_MSCAN_H_
#define FSL_MSCAN_H_

#include "fsl_common.h"

/*!
 * @defgroup mscan MSCAN: Modular/Scalable Controller Area Network
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief MsCAN driver version. */
#define FSL_MSCAN_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup mscan_driver_log The Driver Change Log
 * @ingroup mscan
 * @{
 * The current MSCAN driver version is 2.1.0.
 *
 * - 2.1.0
 *   - Improvements
 *     - Added wrong data length code(DLC) detection, report kStatus_MSCAN_DataLengthError
 *       when DLC is wrong.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of MISRA C-2012 rule 10.3.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @brief MsCAN Rx Message Buffer Mask helper macro. */
#define MSCAN_RX_MB_STD_MASK(id)               \
    ((uint32_t)((((uint32_t)(id)&0x7) << 21) | \
                ((((uint32_t)(id) >> 3) & 0xFF) << 24))) /*!< Standard Rx Message Buffer Mask helper macro. */
#define MSCAN_RX_MB_EXT_MASK(id)                                                                   \
    ((uint32_t)(((((uint32_t)(id) >> 21) & 0xFF) << 24) | ((((uint32_t)(id) >> 18) & 0x7) << 21) | \
                ((((uint32_t)(id) >> 15) & 0x7) << 16) | (((((uint32_t)(id) >> 7) & 0xFF)) << 8) | \
                (((uint32_t)(id)&0x7F) << 1))) /* !< Extend Rx Message Buffer Mask helper macro. */

/*! @brief MsCAN SRR bit. */
#define MSCAN_R_TSRR (1U)

/*! @brief MsCAN IDE bit. */
#define MSCAN_R_TEIDE (1U)

/*! @brief FlexCAN transfer status. */
enum
{
    kStatus_MSCAN_TxBusy       = MAKE_STATUS(kStatusGroup_MSCAN, 0), /*!< Tx Message Buffer is Busy. */
    kStatus_MSCAN_TxIdle       = MAKE_STATUS(kStatusGroup_MSCAN, 1), /*!< Tx Message Buffer is Idle. */
    kStatus_MSCAN_TxSwitchToRx = MAKE_STATUS(
        kStatusGroup_MSCAN, 2), /*!< Remote Message is send out and Message buffer changed to Receive one. */
    kStatus_MSCAN_RxBusy          = MAKE_STATUS(kStatusGroup_MSCAN, 3),  /*!< Rx Message Buffer is Busy. */
    kStatus_MSCAN_RxIdle          = MAKE_STATUS(kStatusGroup_MSCAN, 4),  /*!< Rx Message Buffer is Idle. */
    kStatus_MSCAN_RxOverflow      = MAKE_STATUS(kStatusGroup_MSCAN, 5),  /*!< Rx Message Buffer is Overflowed. */
    kStatus_MSCAN_RxFifoBusy      = MAKE_STATUS(kStatusGroup_MSCAN, 6),  /*!< Rx Message FIFO is Busy. */
    kStatus_MSCAN_RxFifoIdle      = MAKE_STATUS(kStatusGroup_MSCAN, 7),  /*!< Rx Message FIFO is Idle. */
    kStatus_MSCAN_RxFifoOverflow  = MAKE_STATUS(kStatusGroup_MSCAN, 8),  /*!< Rx Message FIFO is overflowed. */
    kStatus_MSCAN_RxFifoWarning   = MAKE_STATUS(kStatusGroup_MSCAN, 9),  /*!< Rx Message FIFO is almost overflowed. */
    kStatus_MSCAN_ErrorStatus     = MAKE_STATUS(kStatusGroup_MSCAN, 10), /*!< FlexCAN Module Error and Status. */
    kStatus_MSCAN_UnHandled       = MAKE_STATUS(kStatusGroup_MSCAN, 11), /*!< UnHadled Interrupt asserted. */
    kStatus_MSCAN_DataLengthError = MAKE_STATUS(kStatusGroup_MSCAN, 12), /*!< Frame data length is wrong. */
};

/*! @brief MsCAN frame format. */
typedef enum _mscan_frame_format
{
    kMSCAN_FrameFormatStandard = 0x0U, /*!< Standard frame format attribute. */
    kMSCAN_FrameFormatExtend   = 0x1U, /*!< Extend frame format attribute. */
} mscan_frame_format_t;

/*! @brief MsCAN frame type. */
typedef enum _mscan_frame_type
{
    kMSCAN_FrameTypeData   = 0x0U, /*!< Data frame type attribute. */
    kMSCAN_FrameTypeRemote = 0x1U, /*!< Remote frame type attribute. */
} mscan_frame_type_t;

/*! @brief MsCAN clock source. */
typedef enum _mscan_clock_source
{
    kMSCAN_ClkSrcOsc = 0x0U, /*!< MsCAN Protocol Engine clock from Oscillator. */
    kMSCAN_ClkSrcBus = 0x1U, /*!< MsCAN Protocol Engine clock from Bus Clock. */
} mscan_clock_source_t;

/*! @brief MsCAN bus-off recovery mode. */
typedef enum _mscan_busoffrec_mode
{
    kMSCAN_BusoffrecAuto = 0x0U, /*!< MsCAN automatic bus-off recovery. */
    kMSCAN_BusoffrecUsr  = 0x1U, /*!< MsCAN bus-off recovery upon user request. */
} mscan_busoffrec_mode_t;

/*! @brief MsCAN Tx buffer empty flag. */
enum _mscan_tx_buffer_empty_flag
{
    kMSCAN_TxBuf0Empty = 0x1U, /*!< MsCAN Tx Buffer 0 empty. */
    kMSCAN_TxBuf1Empty = 0x2U, /*!< MsCAN Tx Buffer 1 empty. */
    kMSCAN_TxBuf2Empty = 0x4U, /*!< MsCAN Tx Buffer 2 empty. */
    kMSCAN_TxBufFull   = 0x0U, /*!< MsCAN Tx Buffer all not empty. */
};

/*! @brief MsCAN id filter mode. */
typedef enum _mscan_id_filter_mode
{
    kMSCAN_Filter32Bit = 0x0U, /*!< Two 32-bit acceptance filters. */
    kMSCAN_Filter16Bit = 0x1U, /*!< Four 16-bit acceptance filters. */
    kMSCAN_Filter8Bit  = 0x2U, /*!< Eight 8-bit acceptance filters. */
    kMSCAN_FilterClose = 0x3U, /*!< Filter closed. */
} mscan_id_filter_mode_t;

/*!
 * @brief MsCAN interrupt configuration structure, default settings all disabled.
 *
 * This structure contains the settings for all of the MsCAN Module interrupt configurations.
 */
enum _mscan_interrupt_enable
{
    kMSCAN_WakeUpInterruptEnable         = CAN_RIER_WUPIE_MASK,  /*!< Wake Up interrupt. */
    kMSCAN_StatusChangeInterruptEnable   = CAN_RIER_CSCIE_MASK,  /*!< Status change interrupt. */
    kMSCAN_RxStatusChangeInterruptEnable = CAN_RIER_RSTATE_MASK, /*!< Rx status change interrupt. */
    kMSCAN_TxStatusChangeInterruptEnable = CAN_RIER_TSTATE_MASK, /*!< Tx status change interrupt. */
    kMSCAN_OverrunInterruptEnable        = CAN_RIER_OVRIE_MASK,  /*!< Overrun interrupt. */
    kMSCAN_RxFullInterruptEnable         = CAN_RIER_RXFIE_MASK,  /*!< Rx buffer full interrupt. */
    kMSCAN_TxEmptyInterruptEnable        = CAN_TIER_TXEIE_MASK,  /*!< Tx buffer empty interrupt. */
};

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/*! @brief MSCAN IDR1 struct. */
typedef struct
{
    uint8_t EID17_15 : 3;           /*!< Extended Format Identifier 17-15*/
    uint8_t R_TEIDE : 1;            /*!< ID Extended */
    uint8_t R_TSRR : 1;             /*!< Substitute Remote Request */
    uint8_t EID20_18_OR_SID2_0 : 3; /*!< Extended Format Identifier 18-20 or standard format bit 0-2*/
} MSCAN_IDR1Type;

/*! @brief MSCAN IDR3 struct. */
typedef struct
{
    uint8_t ERTR : 1;   /*!< Remote Transmission Request*/
    uint8_t EID6_0 : 7; /*!< Extended Format Identifier 6-0*/
} MSCAN_IDR3Type;

/*! @brief MSCAN idr1 and idr3 union. */
typedef union
{
    MSCAN_IDR1Type IDR1; /*!< structure for identifier 1 */
    MSCAN_IDR3Type IDR3; /*!< structure for identifier 3 */
    uint8_t Bytes;       /*!< bytes */
} IDR1_3_UNION;

/*! @brief MSCAN extend ID struct. */
typedef struct
{
    uint32_t EID6_0 : 7;   /*!< ID[0:6] */
    uint32_t EID14_7 : 8;  /*!< ID[14:7] */
    uint32_t EID17_15 : 3; /*!< ID[17:15] */
    uint32_t EID20_18 : 3; /*!< ID[20:18] */
    uint32_t EID28_21 : 8; /*!< ID[28:21] */
    uint32_t rsvd : 3;
} MSCAN_ExtendIDType;

/*! @brief MSCAN standard ID struct. */
typedef struct
{
    uint32_t EID2_0 : 3;  /*!< ID[0:2] */
    uint32_t EID10_3 : 8; /*!< ID[10:3] */
    uint32_t rsvd : 21;
} MSCAN_StandardIDType;

/*! @brief MsCAN message buffer structure. */
typedef struct _mscan_mb
{
    uint8_t EIDR0;   /*!< Extended Identifier Register 0 */
    uint8_t EIDR1;   /*!< Extended Identifier Register 1 */
    uint8_t EIDR2;   /*!< Extended Identifier Register 2 */
    uint8_t EIDR3;   /*!< Extended Identifier Register 3 */
    uint8_t EDSR[8]; /*!< Extended Data Segment Register */
    uint8_t DLR;     /*!< data length field */
    uint8_t BPR;     /*!< Buffer Priority Register */
    uint8_t TSRH;    /*!< Time Stamp Register High */
    uint8_t TSRL;    /*!< Time Stamp Register Low */
} mscan_mb_t;

/*! @brief MsCAN frame structure. */
typedef struct _mscan_frame
{
    union
    {
        MSCAN_StandardIDType StdID; /*!< standard format */
        MSCAN_ExtendIDType ExtID;   /*!< extend format */
        uint32_t ID;                /*!< Identifire with 32 bit format */
    } ID_Type;                      /*!< identifier union */
    union
    {
        uint8_t DSR[8]; /*!< data segment */
        struct
        {
            uint32_t dataWord0; /*!< MSCAN Frame payload word0. */
            uint32_t dataWord1; /*!< MSCAN Frame payload word1. */
        };
        struct
        {
            uint8_t dataByte0; /*!< MSCAN Frame payload byte0. */
            uint8_t dataByte1; /*!< MSCAN Frame payload byte1. */
            uint8_t dataByte2; /*!< MSCAN Frame payload byte2. */
            uint8_t dataByte3; /*!< MSCAN Frame payload byte3. */
            uint8_t dataByte4; /*!< MSCAN Frame payload byte4. */
            uint8_t dataByte5; /*!< MSCAN Frame payload byte5. */
            uint8_t dataByte6; /*!< MSCAN Frame payload byte6. */
            uint8_t dataByte7; /*!< MSCAN Frame payload byte7. */
        };
    };
    uint8_t DLR;                 /*!< data length */
    uint8_t BPR;                 /*!< transmit buffer priority */
    mscan_frame_type_t type;     /*!< remote frame or data frame */
    mscan_frame_format_t format; /*!< extend frame or standard frame */
    uint8_t TSRH;                /*!< time stamp high byte */
    uint8_t TSRL;                /*!< time stamp low byte */
} mscan_frame_t;

/*! @brief MsCAN module acceptance filter configuration structure. */
typedef struct _mscan_idfilter_config
{
    mscan_id_filter_mode_t filterMode; /*!< MSCAN Identifier Acceptance Filter Mode */
    uint32_t u32IDAR0;                 /*!< MSCAN Identifier Acceptance Register n of First Bank */
    uint32_t u32IDAR1;                 /*!< MSCAN Identifier Acceptance Register n of Second Bank */
    uint32_t u32IDMR0;                 /*!< MSCAN Identifier Mask Register n of First Bank */
    uint32_t u32IDMR1;                 /*!< MSCAN Identifier Mask Register n of Second Bank */
} mscan_idfilter_config_t;

/*! @brief MsCAN protocol timing characteristic configuration structure. */
typedef struct _mscan_timing_config
{
    uint8_t priDiv;     /*!< Baud rate prescaler. */
    uint8_t sJumpwidth; /*!< Sync Jump Width. */
    uint8_t timeSeg1;   /*!< Time Segment 1. */
    uint8_t timeSeg2;   /*!< Time Segment 2. */
    uint8_t samp;       /*!< Number of samples per bit time. */
} mscan_timing_config_t;

/*!
 * @brief MsCAN module configuration structure.
 *
 * @note The baudRate/sourceClock and timingConfig members will not participate in configuration at the same time. The
 *       user can decide to use one of them by configuring the enableTimingCalc parameter value.
 */
typedef struct _mscan_config
{
    bool enableTimer;                     /*!< Enable or Disable free running timer. */
    bool enableWakeup;                    /*!< Enable or Disable Wakeup Mode. */
    mscan_clock_source_t clkSrc;          /*!< Clock source for MsCAN Protocol Engine. */
    bool enableLoopBack;                  /*!< Enable or Disable Loop Back Self Test Mode. */
    bool enableListen;                    /*!< Enable or Disable Listen Only Mode. */
    mscan_busoffrec_mode_t busoffrecMode; /*!< Bus-Off Recovery Mode. */
    mscan_idfilter_config_t filterConfig; /*!< MsCAN acceptance filter configuration. */
    bool enableTimingCalc; /*!< Enable or Disable automatically calculate bit timing during initialization. */
    uint32_t baudRate;     /*!< MsCAN baud rate in bps. Only meaningful when the enableTimingCalc is true. */
    uint32_t sourceClock;  /*!< MsCAN peripheral clock in HZ. Only meaningful when the enableTimingCalc is true. */
    mscan_timing_config_t timingConfig; /*!< User's precise MsCAN protocol timing characteristic configuration. Only
                                           meaningful when the enableTimingCalc is false.*/
} mscan_config_t;

/*! @brief MSCAN Message Buffer transfer. */
typedef struct _mscan_mb_transfer
{
    mscan_frame_t *frame; /*!< The buffer of CAN Message to be transfer. */
    uint8_t mask;         /*!< The mask of Tx buffer. */
} mscan_mb_transfer_t;

/*! @brief MsCAN handle structure definition. */
typedef struct _mscan_handle mscan_handle_t;

/*! @brief MsCAN transfer callback function.
 *
 *  The MsCAN transfer callback returns a value from the underlying layer.
 *  If the status equals to kStatus_MSCAN_ErrorStatus, the result parameter is the Content of
 *  MsCAN status register which can be used to get the working status(or error status) of MsCAN module.
 *  If the status equals to other MsCAN Message Buffer transfer status, the result is the index of
 *  Message Buffer that generate transfer event.
 *  If the status equals to other MsCAN Message Buffer transfer status, the result is meaningless and should be
 *  Ignored.
 *  If the status equals kStatus_MSCAN_DataLengthError, it means the received frame data length code (DLC) is wrong.
 */
typedef void (*mscan_transfer_callback_t)(CAN_Type *base, mscan_handle_t *handle, status_t status, void *userData);

/*! @brief MsCAN handle structure. */
struct _mscan_handle
{
    mscan_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                     /*!< MsCAN callback function parameter.*/
    mscan_frame_t *volatile mbFrameBuf;
    /*!< The buffer for received data from Message Buffers. */
    volatile uint8_t mbStateTx; /*!< Message Buffer transfer state. */
    volatile uint8_t mbStateRx; /*!< Message Buffer transfer state. */
};

/******************************************************************************
 * API
 *****************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes a MsCAN instance.
 *
 * This function initializes the MsCAN module with user-defined settings. This example shows how to set up the
 * mscan_config_t parameters and how to call the MSCAN_Init function by passing in these parameters.When
 * mscanConfig.enableTimingCalc is true and the clock and baudrate parameters are not completely matched, there will be
 * a certain error in the automatically calculated bit timing value. The user can know whether the clock and baudrate
 * match by calling MSCAN_CalculateImprovedTimingValues() API, and get the calculated bit timing.
 *  @code
 *   mscan_config_t mscanConfig;
 *   mscanConfig.clkSrc            = kMSCAN_ClkSrcBus;
 *   mscanConfig.sourceClock       = 40000000U;
 *   mscanConfig.baudRate          = 500000U;
 *   mscanConfig.enableTimingCalc  = true;
 *   mscanConfig.enableTimer       = false;
 *   mscanConfig.enableLoopBack    = false;
 *   mscanConfig.enableWakeup      = false;
 *   mscanConfig.enableListen      = false;
 *   mscanConfig.busoffrecMode     = kMSCAN_BusoffrecAuto;
 *   mscanConfig.filterConfig.filterMode = kMSCAN_Filter32Bit;
 *   MSCAN_Init(MSCAN, &mscanConfig);
 *  @endcode
 *
 * param base MsCAN peripheral base address.
 * param config Pointer to the user-defined configuration structure.
 */
void MSCAN_Init(CAN_Type *base, const mscan_config_t *config);

/*!
 * @brief De-initializes a MsCAN instance.
 *
 * This function disables the MsCAN module clock and sets all register values
 * to the reset value.
 *
 * @param base MsCAN peripheral base address.
 */
void MSCAN_Deinit(CAN_Type *base);

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the MsCAN configuration structure to default values. User is requested to provide the clock
 * frequency for the peripheral.
 *
 * @param config Pointer to the MsCAN configuration structure.
 * @param sourceClock_Hz MsCAN peripheral clock
 */
void MSCAN_GetDefaultConfig(mscan_config_t *config, uint32_t sourceClock_Hz);

/*! @} */

/*!
 * @name Configuration.
 * @{
 */

/*!
 * @brief Get the transmit buffer empty status.
 *
 * This flag indicates that the associated transmit message buffer is empty.
 *
 * @param base MsCAN peripheral base address.
 */
static inline uint8_t MSCAN_GetTxBufferEmptyFlag(CAN_Type *base)
{
    return (uint8_t)(base->TFLG & CAN_TFLG_TXE_MASK);
}

/*!
 * @brief The selection of the actual transmit message buffer.
 *
 * To get the next available transmit buffer, read the TFLG
 * register and write its value back into the TBSEL register.
 *
 * @param base MsCAN peripheral base address.
 * @param txBuf The value read from TFLG.
 */
static inline void MSCAN_TxBufferSelect(CAN_Type *base, uint8_t txBuf)
{
    base->TBSEL = CAN_TBSEL_TX(txBuf);
}

/*!
 * @brief Get the actual transmit message buffer.
 *
 * After write TFLG value back into the TBSEL register, read again CANBSEL
 * to get the actual trasnsmit message buffer.
 *
 * @param base MsCAN peripheral base address.
 */
static inline uint8_t MSCAN_GetTxBufferSelect(CAN_Type *base)
{
    return (uint8_t)(base->TBSEL & CAN_TBSEL_TX_MASK);
}

/*!
 * @brief Clear TFLG to schedule for transmission.
 *
 * The CPU must clear the flag after a message is set up in the
 * transmit buffer and is due for transmission.
 *
 * @param base MsCAN peripheral base address.
 * @param txBuf Message buffer(s) to be cleared.
 */
static inline void MSCAN_TxBufferLaunch(CAN_Type *base, uint8_t txBuf)
{
    base->TFLG = (uint16_t)CAN_TFLG_TXE_MASK & txBuf;
}

/*!
 * @brief Get Tx buffer status flag.
 *
 * The bit is set after successful transmission.
 *
 * @param base MsCAN peripheral base address.
 * @param mask Message buffer(s) mask.
 */
static inline uint8_t MSCAN_GetTxBufferStatusFlags(CAN_Type *base, uint8_t mask)
{
    return (uint8_t)(base->TFLG & mask);
}

/*!
 * @brief Check Receive Buffer Full Flag.
 *
 * RXF is set by the MSCAN when a new message is shifted in the receiver FIFO.
 * This flag indicates whether the shifted buffer is loaded with a correctly received message.
 *
 * @param base MsCAN peripheral base address.
 */
static inline uint8_t MSCAN_GetRxBufferFullFlag(CAN_Type *base)
{
    return (uint8_t)(base->RFLG & CAN_RFLG_RXF_MASK);
}

/*!
 * @brief Clear Receive buffer Full flag.
 *
 * After the CPU has read that message from the RxFG buffer in the receiver FIFO
 * The RXF flag must be cleared to release the buffer.
 *
 * @param base MsCAN peripheral base address.
 */
static inline void MSCAN_ClearRxBufferFullFlag(CAN_Type *base)
{
    base->RFLG |= CAN_RFLG_RXF_MASK;
}

static inline uint8_t MSCAN_ReadRIDR0(CAN_Type *base)
{
    return (uint8_t)base->RXFG_IDR0_EXT;
}

static inline uint8_t MSCAN_ReadRIDR1(CAN_Type *base)
{
    return (uint8_t)base->RXFG_IDR1_EXT;
}

static inline uint8_t MSCAN_ReadRIDR2(CAN_Type *base)
{
    return (uint8_t)base->RXFG_IDR2_EXT;
}

static inline uint8_t MSCAN_ReadRIDR3(CAN_Type *base)
{
    return (uint8_t)base->RXFG_IDR3_EXT;
}

static inline void MSCAN_WriteTIDR0(CAN_Type *base, uint8_t id)
{
    base->TXFG_IDR0_EXT = (uint16_t)id;
}

static inline void MSCAN_WriteTIDR1(CAN_Type *base, uint8_t id)
{
    base->TXFG_IDR1_EXT = (uint16_t)id;
}

static inline void MSCAN_WriteTIDR2(CAN_Type *base, uint8_t id)
{
    base->TXFG_IDR2_EXT = (uint16_t)id;
}

static inline void MSCAN_WriteTIDR3(CAN_Type *base, uint8_t id)
{
    base->TXFG_IDR3_EXT = (uint16_t)id;
}

static inline void MSCAN_SetIDFilterMode(CAN_Type *base, mscan_id_filter_mode_t mode)
{
    base->IDAC |= CAN_IDAC_IDAM((uint8_t)mode);
}

static inline void MSCAN_WriteIDAR0(CAN_Type *base, uint8_t *pID)
{
    base->IDAR_BANK_0[0] = pID[3];
    base->IDAR_BANK_0[1] = pID[2];
    base->IDAR_BANK_0[2] = pID[1];
    base->IDAR_BANK_0[3] = pID[0];
}

static inline void MSCAN_WriteIDAR1(CAN_Type *base, uint8_t *pID)
{
    base->IDAR_BANK_1[0] = pID[3];
    base->IDAR_BANK_1[1] = pID[2];
    base->IDAR_BANK_1[2] = pID[1];
    base->IDAR_BANK_1[3] = pID[0];
}

static inline void MSCAN_WriteIDMR0(CAN_Type *base, uint8_t *pID)
{
    base->IDMR_BANK_0[0] = pID[3];
    base->IDMR_BANK_0[1] = pID[2];
    base->IDMR_BANK_0[2] = pID[1];
    base->IDMR_BANK_0[3] = pID[0];
}

static inline void MSCAN_WriteIDMR1(CAN_Type *base, uint8_t *pID)
{
    base->IDMR_BANK_1[0] = pID[3];
    base->IDMR_BANK_1[1] = pID[2];
    base->IDMR_BANK_1[2] = pID[1];
    base->IDMR_BANK_1[3] = pID[0];
}
/*!
 * @brief Calculates the improved timing values by specific baudrates for classical MSCAN
 *
 * @param baudRate  The classical MSCAN speed in bps defined by user
 * @param sourceClock_Hz The Source clock frequency in Hz.
 * @param pconfig Pointer to the MSCAN timing configuration structure.
 *
 * @return TRUE if timing configuration found, FALSE if failed to find configuration
 */
bool MSCAN_CalculateImprovedTimingValues(uint32_t baudRate, uint32_t sourceClock_Hz, mscan_timing_config_t *pconfig);
/*!
 * @brief Sets the MsCAN protocol timing characteristic.
 *
 * This function gives user settings to CAN bus timing characteristic. The function is for an experienced user. For less
 * experienced users, call the MSCAN_GetDefaultConfig() and the MSCAN_Init() to fill the baud rate field with
 * auto-calculates values (base on the default baud rate). This provides the default timing characteristics to the
 * module. Users also can call MSCAN_SetBaudRate() to set auto-calculates timing values base on the desired baud rate.
 *
 * @note that calling MSCAN_SetTimingConfig() overrides the baud rate set in MSCAN_Init() or MSCAN_SetBaudRate().
 *
 * @param base MsCAN peripheral base address.
 * @param config Pointer to the timing configuration structure.
 */

void MSCAN_SetTimingConfig(CAN_Type *base, const mscan_timing_config_t *config);
/*!
 * @brief Set Baud Rate of MsCAN.
 *
 * This function calculation and configuration the protocol timing characteristic of MsCAN based on the peripheral clock
 * and target bit rate.
 *
 * @param base MsCAN peripheral base address.
 * @param sourceClock_Hz Source Clock in Hz.
 * @param baudRate_Bps Baud Rate in Bps.
 *
 * @retval kStatus_Success Set baud rate success.
 * @retval kStatus_Fail    Set baud rate fail.
 */
status_t MSCAN_SetBaudRate(CAN_Type *base, uint32_t sourceClock_Hz, uint32_t baudRate_Bps);

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the MsCAN Tx buffer empty flags.
 *
 * This function gets MsCAN Tx buffer empty flags. It's returned as the
 * value of the enumerators @ref _mscan_tx_buffer_empty_flag.
 *
 * @param base MsCAN peripheral base address.
 * @return Tx buffer empty flags in the _mscan_tx_buffer_empty_flag.
 */
static inline uint8_t MSCAN_GetTxBufEmptyFlags(CAN_Type *base)
{
    return (uint8_t)(base->TFLG & CAN_TFLG_TXE_MASK);
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables MsCAN Transmitter interrupts according to the provided mask.
 *
 * This function enables the MsCAN Tx empty interrupts according to the mask.
 *
 * @param base MsCAN peripheral base address.
 * @param mask The Tx interrupts mask to enable.
 */
static inline void MSCAN_EnableTxInterrupts(CAN_Type *base, uint8_t mask)
{
    base->TIER |= mask;
}

/*!
 * @brief Disables MsCAN Transmitter interrupts according to the provided mask.
 *
 * This function disables the MsCAN Tx emtpy interrupts according to the mask.
 *
 * @param base MsCAN peripheral base address.
 * @param mask The Tx interrupts mask to disable.
 */
static inline void MSCAN_DisableTxInterrupts(CAN_Type *base, uint8_t mask)
{
    base->TIER &= ~((uint16_t)mask);
}

/*!
 * @brief Enables MsCAN Receiver interrupts according to the provided mask.
 *
 * This function enables the MsCAN Rx interrupts according to the provided mask
 * which is a logical OR of enumeration members, see @ref _mscan_interrupt_enable.
 *
 * @param base MsCAN peripheral base address.
 * @param mask The interrupts to enable. Logical OR of @ref _mscan_interrupt_enable.
 */
static inline void MSCAN_EnableRxInterrupts(CAN_Type *base, uint8_t mask)
{
    base->RIER |= mask;
}

/*!
 * @brief Disables MsCAN Receiver interrupts according to the provided mask.
 *
 * This function disables the MsCAN Rx interrupts according to the provided mask
 * which is a logical OR of enumeration members, see @ref _mscan_interrupt_enable.
 *
 * @param base MsCAN peripheral base address.
 * @param mask The interrupts to disable. Logical OR of @ref _mscan_interrupt_enable.
 */
static inline void MSCAN_DisableRxInterrupts(CAN_Type *base, uint8_t mask)
{
    base->RIER &= ~((uint16_t)mask);
}

/*!
 * @brief Abort MsCAN Tx request.
 *
 * This function allows abort request of queued messages.
 *
 * @param base MsCAN peripheral base address.
 * @param mask The Tx mask to abort.
 */
static inline void MSCAN_AbortTxRequest(CAN_Type *base, uint8_t mask)
{
    base->TARQ |= mask;
}

/*! @} */

/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Enables or disables the MsCAN module operation.
 *
 * This function enables or disables the MsCAN module.
 *
 * @param base MsCAN base pointer.
 * @param enable true to enable, false to disable.
 */
static inline void MSCAN_Enable(CAN_Type *base, bool enable)
{
    if (enable)
    {
        base->CTL1 |= CAN_CTL1_CANE_MASK;
    }
    else
    {
        base->CTL1 &= ~((uint16_t)CAN_CTL1_CANE_MASK);
    }
}

/*!
 * @brief Writes a MsCAN Message to the Transmit Message Buffer.
 *
 * This function writes a CAN Message to the specified Transmit Message Buffer
 * and changes the Message Buffer state to start CAN Message transmit. After
 * that the function returns immediately.
 *
 * @param base MsCAN peripheral base address.
 * @param pTxFrame Pointer to CAN message frame to be sent.
 * @retval kStatus_Success - Write Tx Message Buffer Successfully.
 * @retval kStatus_Fail    - Tx Message Buffer is currently in use.
 * @retval kStatus_MSCAN_DataLengthError - Tx Message Buffer data length is wrong.
 */
status_t MSCAN_WriteTxMb(CAN_Type *base, mscan_frame_t *pTxFrame);

/*!
 * @brief Reads a MsCAN Message from Receive Message Buffer.
 *
 * This function reads a CAN message from a specified Receive Message Buffer.
 * The function fills a receive CAN message frame structure with
 * just received data and activates the Message Buffer again.
 * The function returns immediately.
 *
 * @param base MsCAN peripheral base address.
 * @param pRxFrame Pointer to CAN message frame structure for reception.
 * @retval kStatus_Success            - Rx Message Buffer is full and has been read successfully.
 * @retval kStatus_Fail               - Rx Message Buffer is empty.
 * @retval kStatus_MSCAN_DataLengthError - Rx Message data length is wrong.
 */
status_t MSCAN_ReadRxMb(CAN_Type *base, mscan_frame_t *pRxFrame);

/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the MsCAN handle.
 *
 * This function initializes the MsCAN handle, which can be used for other MsCAN
 * transactional APIs. Usually, for a specified MsCAN instance,
 * call this API once to get the initialized handle.
 *
 * @param base MsCAN peripheral base address.
 * @param handle MsCAN handle pointer.
 * @param callback The callback function.
 * @param userData The parameter of the callback function.
 */
void MSCAN_TransferCreateHandle(CAN_Type *base,
                                mscan_handle_t *handle,
                                mscan_transfer_callback_t callback,
                                void *userData);

/*!
 * @brief Performs a polling send transaction on the CAN bus.
 *
 * Note that a transfer handle does not need to be created before calling this API.
 *
 * @param base MsCAN peripheral base pointer.
 * @param pTxFrame Pointer to CAN message frame to be sent.
 * @retval kStatus_Success - Write Tx Message Buffer Successfully.
 * @retval kStatus_Fail    - Tx Message Buffer is currently in use.
 * @retval kStatus_MSCAN_DataLengthError - Tx Message Buffer data length is wrong.
 */
status_t MSCAN_TransferSendBlocking(CAN_Type *base, mscan_frame_t *pTxFrame);

/*!
 * @brief Performs a polling receive transaction on the CAN bus.
 *
 * Note that a transfer handle does not need to be created before calling this API.
 *
 * @param base MsCAN peripheral base pointer.
 * @param pRxFrame Pointer to CAN message frame to be received.
 * @retval kStatus_Success - Read Rx Message Buffer Successfully.
 * @retval kStatus_Fail    - Tx Message Buffer is currently in use.
 * @retval kStatus_MSCAN_DataLengthError - Rx Message data length is wrong.
 */
status_t MSCAN_TransferReceiveBlocking(CAN_Type *base, mscan_frame_t *pRxFrame);

/*!
 * @brief Sends a message using IRQ.
 *
 * This function sends a message using IRQ. This is a non-blocking function, which returns
 * right away. When messages have been sent out, the send callback function is called.
 *
 * @param base MsCAN peripheral base address.
 * @param handle MsCAN handle pointer.
 * @param xfer MsCAN Message Buffer transfer structure. See the #mscan_mb_transfer_t.
 * @retval kStatus_Success        Start Tx Message Buffer sending process successfully.
 * @retval kStatus_Fail           Write Tx Message Buffer failed.
 * @retval kStatus_MSCAN_DataLengthError - Tx Message Buffer data length is wrong.
 */
status_t MSCAN_TransferSendNonBlocking(CAN_Type *base, mscan_handle_t *handle, mscan_mb_transfer_t *xfer);

/*!
 * @brief Receives a message using IRQ.
 *
 * This function receives a message using IRQ. This is non-blocking function, which returns
 * right away. When the message has been received, the receive callback function is called.
 *
 * @param base MsCAN peripheral base address.
 * @param handle MsCAN handle pointer.
 * @param xfer MsCAN Message Buffer transfer structure. See the #mscan_mb_transfer_t.
 * @retval kStatus_Success        - Start Rx Message Buffer receiving process successfully.
 * @retval kStatus_MSCAN_RxBusy - Rx Message Buffer is in use.
 */
status_t MSCAN_TransferReceiveNonBlocking(CAN_Type *base, mscan_handle_t *handle, mscan_mb_transfer_t *xfer);

/*!
 * @brief Aborts the interrupt driven message send process.
 *
 * This function aborts the interrupt driven message send process.
 *
 * @param base MsCAN peripheral base address.
 * @param handle MsCAN handle pointer.
 * @param mask The MsCAN Tx Message Buffer mask.
 */
void MSCAN_TransferAbortSend(CAN_Type *base, mscan_handle_t *handle, uint8_t mask);

/*!
 * @brief Aborts the interrupt driven message receive process.
 *
 * This function aborts the interrupt driven message receive process.
 *
 * @param base MsCAN peripheral base address.
 * @param handle MsCAN handle pointer.
 * @param mask The MsCAN Rx Message Buffer mask.
 */
void MSCAN_TransferAbortReceive(CAN_Type *base, mscan_handle_t *handle, uint8_t mask);

/*!
 * @brief MSCAN IRQ handle function.
 *
 * This function handles the MSCAN Error, the Message Buffer, and the Rx FIFO IRQ request.
 *
 * @param base MSCAN peripheral base address.
 * @param handle MSCAN handle pointer.
 */
void MSCAN_TransferHandleIRQ(CAN_Type *base, mscan_handle_t *handle);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_MSCAN_H_ */
