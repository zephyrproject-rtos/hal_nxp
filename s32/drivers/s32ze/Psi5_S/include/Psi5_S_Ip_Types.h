/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_S_IP_TYPES_H
#define PSI5_S_IP_TYPES_H

/**
*   @file Psi5_S_Ip_Types.h
*
*   @addtogroup PSI5_S_IP PSI5_S IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Mcal.h"

/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define PSI5_S_IP_TYPES_VENDOR_ID                        43
#define PSI5_S_IP_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define PSI5_S_IP_TYPES_AR_RELEASE_MINOR_VERSION         7
#define PSI5_S_IP_TYPES_AR_RELEASE_REVISION_VERSION      0
#define PSI5_S_IP_TYPES_SW_MAJOR_VERSION                 2
#define PSI5_S_IP_TYPES_SW_MINOR_VERSION                 0
#define PSI5_S_IP_TYPES_SW_PATCH_VERSION                 0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((PSI5_S_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PSI5_S_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Psi5_S_Ip_Types.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*!
 * @brief PSI5_S instance id type
 *
 * Type for holding instance id
 *
 * Implements : psi5s_instanceId_class
 */
typedef enum
{
    PSI5_S_INSTANCE0 = 0u, /*!< Instance 0*/
    PSI5_S_INSTANCE1       /*!< Instance 1*/
} Psi5_S_Ip_InstanceIdType;

/*!
 * @brief PSI5_S channel mode
 *
 * Possible values for setting the reception mode
 *
 * Implements : psi5s_channel_mode_class
 */
typedef enum
{
    PSI5_S_SYNCHRONOUS = 0u, /*!< Synchronous mode (Rx and Tx)*/
    PSI5_S_ASYNCHRONOUS     /*!< Asynchronous mode (Rx only)*/
} Psi5_S_Ip_ChannelModeType;

/*!
 * @brief PSI5_S channel time stamp 
 *
 * Possible values for selecting the time stamp counter
 *
 * Implements : psi5s_channel_timestamp_class
 */
typedef enum
{
    PSI5_S_TIME_STAMP_A = 0, /*!< Timestamp counter A */
    PSI5_S_TIME_STAMP_B      /*!< Timestamp counter B */
} Psi5_S_Ip_ChannelTimeStampType;

/*!
 * @brief PSI5_S Tx mode
 *
 * Possible values for setting the transmission mode
 *
 * Implements : psi5s_tx_mode_class
 */
typedef enum
{
    PSI5_S_TX_MODE_0 = 0, /*!< Short Frame(V1.3) with 31 "1s" as the start condition */
    PSI5_S_TX_MODE_1,     /*!< Short Frame(V1.3) with 5 "0s" as the start condition */
    PSI5_S_TX_MODE_2,     /*!< Long Frame(V1.3) with 31 "1s" as the start condition */
    PSI5_S_TX_MODE_3,     /*!< Long Frame(V1.3) with 5 "0s" as the start condition */
    PSI5_S_TX_MODE_4,     /*!< X-Long Frame(V1.3) with 31 "1s" as the start condition */
    PSI5_S_TX_MODE_5,     /*!< X-Long Frame(V1.3) with 5 "0s" as the start condition */
    PSI5_S_TX_MODE_6,     /*!< XX-Long (V2.0) */
    PSI5_S_TX_MODE_7      /*!< Non Standard Length */
} Psi5_S_Ip_TxModeType;

/*!
 * @brief PSI5_S Sync state
 *
 * Possible values for setting the pulse generation state
 *
 * Implements : psi5s_sync_state_class
 */
typedef enum
{
    IPG_CLK_PS_DDTRIG = 0, /*!< ipg_clk_ps_ddtrig clock. */
    GTM_TRIG               /*!< gtm_trig is selected as the clock. */
} Psi5_S_Ip_ClockSourceType;

/**
 * @brief PSI5S event structure
 *
 * Contains data of event flags.
 */
typedef struct
{
    /* UART event flags */
    boolean Psi5S_UartTX;               /*!< UART Transmit Event */
    boolean Psi5S_UartRX;               /*!< UART Received Event */
    boolean Psi5S_UartERR;              /*!< UART Errors Present Event */
    /* Global event flags */
    boolean Psi5S_GlobalTrigger;        /*!< PSI5 Global Trigger Event */
    /* Rx event flags */
    boolean Psi5S_MessageReceived;      /*!< PSI5 Message Received Event */
    boolean Psi5S_MessageOverwrite;     /*!< PSI5 Message Overwrite Event */
    boolean Psi5S_MessageErrorsPresent; /*!< PSI5 Message Errors Present Event */
    /* Tx event flags */
    boolean Psi5S_TxDataOverwrite;      /*!< Data register overwrite */
    boolean Psi5S_ReadyToTransmit;      /*!< Driver is ready to transmit new data */
} Psi5_S_Ip_EventType;

/*!
 * @brief PSI5_S Uart baudrate configuration
 *
 * Contains configuration uart baudrate value.
 *
 * Implements : psi5s_uart_baudrate_class
 */
typedef enum
{
    PSI5_S_UART_BAUDRATE_1200    = 1200U,
    PSI5_S_UART_BAUDRATE_2400    = 2400U,
    PSI5_S_UART_BAUDRATE_4800    = 4800U,
    PSI5_S_UART_BAUDRATE_7200    = 7200U,
    PSI5_S_UART_BAUDRATE_9600    = 9600U,
    PSI5_S_UART_BAUDRATE_14400   = 14400U,
    PSI5_S_UART_BAUDRATE_19200   = 19200U,
    PSI5_S_UART_BAUDRATE_28800   = 28800U,
    PSI5_S_UART_BAUDRATE_38400   = 38400U,
    PSI5_S_UART_BAUDRATE_57600   = 57600U,
    PSI5_S_UART_BAUDRATE_115200  = 115200U,
    PSI5_S_UART_BAUDRATE_230400  = 230400U,
    PSI5_S_UART_BAUDRATE_460800  = 460800U,
    PSI5_S_UART_BAUDRATE_921600  = 921600U,
    PSI5_S_UART_BAUDRATE_1843200 = 1843200U
}Psi5_S_Ip_UartBaudrateType;

/*!
 * @brief PSI5_S MailBox Error
 *
 * Contains define mailbox error
 *
 * Implements : psi5s_mailbox_err_class
 */
typedef enum
{
    XCRC_ERR = 0,  /*!< XCRC error (1 bit) */
    CRC_ERR_P_ERR, /*!< CRC error (1 bit) */
    HD_ERR,        /*!< ERR occurs error (1 bit) */
    SCI_P_ERRE,    /*!< UART message parity error (1 bit) */
    SCI_F_ERR,     /*!< UART framing error (1 bit) */
    SCI_O_ERR,     /*!< UART overrun error (1 bit) */
    F_WD_ERR,      /*!< Frame watchdog error (1 bit) */
    R_OVL_ERR,     /*!< Message overflow (1 bit) */
    N_ERR,         /*!< UART packet does not match  (1 bit) */
    R_UVL_ERR      /*!< Message underflow (1 bit) */
}Psi5_S_Ip_MailBoxErrType;

/*!
 * @brief PSI5_S event type needed for callback
 *
 * Workaround because notification is defined in IP layer
 *
 * Implements : psi5s_event_class
*/
typedef Psi5_S_Ip_EventType Psi5_S_EventType;

typedef uint8 Psi5_S_Ip_HwChannelIdType;

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Get PSI5_S Instance Id */
#define PSI5_S_GET_HW_INSTANCE(internalMappingCh)           (((((uint8)internalMappingCh) >> ((uint8)4u)) == 0u) ? PSI5_S_INSTANCE0 : PSI5_S_INSTANCE1)

/* Get PSI5_S channel Id */
#define PSI5_S_GET_HW_CHANNEL(internalMappingCh)            ((uint8)(((uint8)internalMappingCh) & (uint8)0x0Fu))

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief Callback function
 *
 * PSI5_S callback prototype. Called from IRQ.
 *
 * Implements : psi5s_callback_func_class
 */
typedef void(* Psi5_S_Ip_CallbackType)(Psi5_S_EventType Event);

/*!
 * @brief Raw data frame
 *
 * A raw PSI5_S frame. Contains hardware specific fields. Needs conversion.
 *
 * Implements : psi5s_raw_frame_class
 */
typedef uint32 Psi5_S_Ip_RawPsi5SFrameType[4u];

/*!
 * @brief PSI5_S slot data type
 *
 * Slot configuration structure
 *
 * Implements : psi5s_slot_config_class
 */
typedef struct
{
    uint8    slotId;      /*!< Slot id number (1-6) */
    boolean  useCRC;      /*!< Controls the local parity/CRC option for the message */
    uint8    payloadSize; /*!< Payload region length */
} Psi5_S_Ip_SlotConfigType;

/*!
 * @brief PSI5_S data frame
 *
 * A PSI5_S frame. Contains specific fields.
 *
 * Implements : psi5s_psi5frame_class
 */
typedef struct
{
    uint32 TIME_STAMP;    /*!< Time stamp value (24 bits) */
    uint32 PS_DATA;       /*!< PSI5 data (28 bits) */
    uint8  DCI1;          /*!< Data Consistency Indicator MRU_BUF2_REG1 (4 bits) */
    uint8  DCI2;          /*!< Data Consistency Indicator MRU_BUF2_REG2 (4 bits) */
    uint8  DCI3;          /*!< Data Consistency Indicator MRU_BUF2_REG3 (4 bits) */
    uint8  XCRC;          /*!< XCRC value Parity (6 bits, 1 bit parity in C[5] if configured) */
    uint8  CRC;           /*!< CRC value Parity (3 bits, 1 bit parity in C[2] if configured) */
    uint8  FID;           /*!< Indicates Frame ID (3 bit) */
    uint8  CHID;          /*!< Indicates Channel ID (3 bit) */
    uint8  ERR;           /*!< Transceiver error (2 bit) */
    uint8  F_OV;          /*!< Message overwrite (1 bit) */
    uint16 F_ERR;         /*!< Message error (10 bit) */
} Psi5_S_Ip_Psi5SFrameStructType;

typedef Psi5_S_Ip_Psi5SFrameStructType Psi5_S_Ip_Psi5SFrameType;

/*!
 * @brief Callback function
 *
 * PSI5_S callback prototype. Called from IRQ.
 *
 * Implements : psi5s_callback_rx_func_class
 */
typedef void(* Psi5_S_Ip_CallbackRxType)(Psi5_S_Ip_InstanceIdType Psi5SInstanceId, Psi5_S_Ip_Psi5SFrameType Psi5SFramePtr);

/*!
 * @brief Channel rx configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5s_channel_rx_config_class
 */
typedef struct
{
    const Psi5_S_Ip_SlotConfigType        *slotConfig;              /*!< Pointer to a slot configuration list */
    const uint8                            numOfSlotConfigs;        /*!< Number of configurations in the slot configuration list */  
} Psi5_S_Ip_ChannelRxConfigType;

/*!
 * @brief Channel tx configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5s_channel_tx_config_class
 */
typedef struct
{    
    const boolean                   syncGlobal;   /*!< Sync the global shift trigger of all the DDSRs */
    const Psi5_S_Ip_ClockSourceType clockSel;     /*!< Select clock source */
    const uint16                    initCMD;      /*!< Initial reset reload value for the integrated "CMD" format */
    const uint16                    initACMD;     /*!< Initial reset reload value for the integrated "ACMD" format */
    const uint16                    targetPeriod; /*!< Subsequent reload values for the integrated period generator */
    const uint16                    counterDelay; /*!< Time in us for which the manchester decoder is disabled after the falling edge of a sync pulse */
    const Psi5_S_Ip_TxModeType      txMode;       /*!< Transmitter mode, please refer to RM */
    const boolean                   txDefault1;   /*!< All bits in Tx registers will default to "1" */
} Psi5_S_Ip_ChannelTxConfigType;

/*!
 * @brief PSI5_S Uart configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5s_uart_config_class
 */
typedef struct
{
    const uint32  Uart_baud_clock;
    const boolean Uart_transmit_MSB;
    const boolean Uart_received_MSB;
    const boolean Uart_baud_rate_cus_enable;
    const Psi5_S_Ip_UartBaudrateType  Uart_baud_rate;
    const uint32  Uart_baud_rate_cus;
    const boolean Uart_tx_parity_enable;
    const boolean Uart_rx_parity_enable;
    const boolean Uart_tx_data_level_inversion;
    const boolean Uart_rx_data_level_inversion;
    const uint16  Uart_preset_timeout;
    const boolean Uart_tx_idle_delay_time_enable;
    const uint8   Uart_tx_idle_delay_time;
    const boolean Uart_reduced_over_sampling_enable;
    const uint8   Uart_over_sampling_rate;
    const uint8   Uart_sampling_point;
    const boolean Uart_loop_back_enable;
}Psi5_S_Ip_UartConfigType;

/*!
 * @brief Psi5_S Dma configuration structure
 *
 * Contains configuration data for one channel.
 *
 */
typedef struct
{
    const uint8 channelId; /*!< Assigned DMA logical channel for PSI5_S frames */
} Psi5_S_Ip_DmaConfigType;

/*!
 * @brief PSI5_S channel configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5s_channel_config_class
 */
typedef struct
{
    const uint8                           channelId;  /*!< Channel id number (0-7) */
    const Psi5_S_Ip_ChannelModeType       mode;       /*!< Communication mode */
    const Psi5_S_Ip_CallbackRxType        callbackRx; /*!< Callback Rx data */
    const Psi5_S_Ip_CallbackType          callbackTx; /*!< Callback Tx data */
    const Psi5_S_Ip_ChannelTimeStampType  timestamp;  /*!< Capture time-stamp at A or B, otherwise at sync */
    const boolean                         wdEnable;   /*!< The watchdog counter for each channel */
    const uint32                          wdTimeout;  /*!< The watchdog time out value */
    const boolean                         LocalCtrl;  /*!< Local set controlled globally on a channel basis or locally on a per frame basis */
    const boolean                         useCRC;     /*!< Selects the Parity or the CRC option for all the Frames of that particular channel */
    const Psi5_S_Ip_ChannelRxConfigType * rxConfig;   /*!< Rx Configuration */
    const Psi5_S_Ip_ChannelTxConfigType * txConfig;   /*!< Tx Configuration */
} Psi5_S_Ip_ChannelConfigType;

/*!
 * @brief Channel new message flags
 *
 * Implements : psi5s_channel_flag_class
 */
typedef struct
{
    uint32 psi5SNewMessageAvailable; /*!< Pending buffer flags for PSI5_S frames. (internal use) */
} Psi5_S_Ip_ChannelFlagType;

/*!
 * @brief Instance configuration structure
 *
 * PSI5_S instance configuration structure. Contains all data required to configure the instance.
 *
 * Implements : psi5s_instance_class
 */
typedef struct
{
    const Psi5_S_Ip_InstanceIdType      instanceId;               /*!< PSI5_S instance id */
    const Psi5_S_Ip_ChannelConfigType * channelConfig;            /*!< Pointer to a channel configuration list */
    const uint8                         numOfChannels;            /*!< Number of channels configured */
    const uint8                       * chHwIdToIndexArrayConfig; /*!< Array with mapping of channel hw id to the index in channel config array */
    const Psi5_S_Ip_UartConfigType    * uartConfig;               /*!< Pointer to a uart configuration list*/
    const Psi5_S_Ip_DmaConfigType     * dmaConfig;                /*!< Assigned DMA config for frame */
    const Psi5_S_Ip_CallbackType        callback;                 /*!< Callback data */
} Psi5_S_Ip_InstanceType;

/*!
 * @brief configuration structure
 *
 * PSI5_S configuration structure. Contains all data required to configure if IP.
 *
 * Implements : psi5s_config_class
 */
typedef struct
{
    const Psi5_S_Ip_InstanceType * instancesConfig; /*!< Pointer to instances configuration list */
    const uint8                    numOfInstances;  /*!< Number of instances configured */
    const uint8                  * logicalChToHwCh; /*!< Pointer to array mapping logical channel to hardware channel */
} Psi5_S_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PSI5_S_IP_TYPES_H */

