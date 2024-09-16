/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_IP_TYPES_H
#define PSI5_IP_TYPES_H

/**
*   @file Psi5_Ip_Types.h
*
*   @addtogroup PSI5_IP PSI5 IPV Driver
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
#include "Std_Types.h"
#include "Psi5_Ip_Cfg_Defines.h"
/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define PSI5_IP_TYPES_VENDOR_ID                        43
#define PSI5_IP_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define PSI5_IP_TYPES_AR_RELEASE_MINOR_VERSION         7
#define PSI5_IP_TYPES_AR_RELEASE_REVISION_VERSION      0
#define PSI5_IP_TYPES_SW_MAJOR_VERSION                 2
#define PSI5_IP_TYPES_SW_MINOR_VERSION                 0
#define PSI5_IP_TYPES_SW_PATCH_VERSION                 1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Psi5_Ip_Cfg_Defines.h */
#if (PSI5_IP_TYPES_VENDOR_ID != PSI5_IP_CFG_DEFINES_VENDOR_ID)
    #error "Psi5_Ip_Types.h and Psi5_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((PSI5_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_TYPES_AR_RELEASE_MINOR_VERSION    != PSI5_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_TYPES_AR_RELEASE_REVISION_VERSION != PSI5_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Psi5_Ip_Types.h and Psi5_Ip_Cfg_Defines.h are different"
#endif
#if ((PSI5_IP_TYPES_SW_MAJOR_VERSION != PSI5_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (PSI5_IP_TYPES_SW_MINOR_VERSION != PSI5_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (PSI5_IP_TYPES_SW_PATCH_VERSION != PSI5_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_Ip_Types.h and Psi5_Ip_Cfg_Defines.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h file are of the same Autosar version */
    #if ((PSI5_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PSI5_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Psi5_Ip_Types.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*!
 * @brief PSI5 Rx mode
 *
 * Possible values for setting the reception mode
 *
 * Implements : psi5_rx_mode_Class
 */
typedef enum
{
    PSI5_ASYNCHRONOUS = 0, /*!< Asynchronous mode (Rx only)*/
    PSI5_SYNCHRONOUS       /*!< Synchronous mode (Rx and Tx)*/
} Psi5_Ip_ChannelModeType;

/*!
 * @brief PSI5 Tx mode
 *
 * Possible values for setting the transmission mode
 *
 * Implements : psi5x_mode_Class
 */
typedef enum
{
    PSI5_TX_MODE_0 = 0, /*!< Short Frame(V1.3) with 31 "1s" as the start condition */
    PSI5_TX_MODE_1,     /*!< Short Frame(V1.3) with 5 "0s" as the start condition */
    PSI5_TX_MODE_2,     /*!< Long Frame(V1.3) with 31 "1s" as the start condition */
    PSI5_TX_MODE_3,     /*!< Long Frame(V1.3) with 5 "0s" as the start condition */
    PSI5_TX_MODE_4,     /*!< X-Long Frame(V1.3) with 31 "1s" as the start condition */
    PSI5_TX_MODE_5,     /*!< X-Long Frame(V1.3) with 5 "0s" as the start condition */
    PSI5_TX_MODE_6,     /*!< XX-Long (V2.0) */
    PSI5_TX_MODE_7      /*!< Non Standard Length */
} Psi5_Ip_TxModeType;

/*!
 * @brief PSI5 Sync state
 *
 * Possible values for setting the pulse generation state
 *
 * Implements : psi5_sync_state_Class
 */
typedef enum
{
    PSI5_SYNC_STATE_2 = 1, /*!< Periodic Sync Pulse Generation with ECU-to-sensor Communication */
    PSI5_SYNC_STATE_1 = 3, /*!< Periodic Sync Pulse Generation (without pulse length modulation) */
    PSI5_SYNC_STATE_4 = 5, /*!< Event triggered sync pulse, including ECU-to-sensor communication */
    PSI5_SYNC_STATE_3 = 7  /*!< Event triggered (e.g. angle synchronous) sync pulses */
} Psi5_Ip_SyncStateType;

/*!
 * @brief PSI5 instance id type
 *
 * Type for holding instance id
 *
 * Implements : Psi5_InstanceType_Class
 */
typedef enum
{
    PSI5_INSTANCE0 = 0u, /*!< Instance 0*/
    PSI5_INSTANCE1      /*!< Instance 1*/
} Psi5_Ip_InstanceIdType;

/*!
 * @brief PSI5 DMA mode type
 *
 * Type for holding Dma mode
 *
 */
typedef enum
{
    PSI5_DMA_MODE_CONF1 = 0u, /*!< DMA rewquest is disable*/
    PSI5_DMA_MODE_CONF2 = 1u, /*!< DMA request transfer for PSI5 message and diagnostic*/
    PSI5_DMA_MODE_CONF3 = 2u, /*!< DMA request transfer for PSI5 message only*/
    PSI5_DMA_MODE_CONF4 = 3u, /*!< DMA request transfer for PSI5 diagnostic only*/
} Psi5_Ip_Psi5DmaModeType;


typedef uint8 Psi5_Ip_HwChannelIdType;

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Get PSI5 hw Instance Id */
#define PSI5_GET_HW_INSTANCE(internalMappingCh)           (((((uint8)internalMappingCh) >> ((uint8)4u)) == 0u) ? PSI5_INSTANCE0 : PSI5_INSTANCE1)

/* Get PSI5 hw channel Id */
#define PSI5_GET_HW_CHANNEL(internalMappingCh)            ((uint8)(((uint8)internalMappingCh) & (uint8)0x0Fu))

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief PSI5 event structure
 *
 * Contains data of event flags.
 */
typedef struct
{
    /* PSI5 event flags */
    boolean Psi5_Psi5MessageReceived;      /*!< PSI5 Message Received Event */
    boolean Psi5_Psi5MessageOverwrite;     /*!< PSI5 Message Overwrite Event */
    boolean Psi5_Psi5MessageErrorsPresent; /*!< PSI5 Message Errors Present Event */

    /* SMC event flags */
    boolean Psi5_SmcMessageReceived;      /*!< SMC Message Received Event */
    boolean Psi5_SmcMessageOverwrite;     /*!< SMC Message Overwrite Event */
    boolean Psi5_SmcMessageCRCError;      /*!< SMC Message CRC Error Event */

    /* Tx event flags */
    boolean Psi5_TxDataOverwrite;         /*!< Data register overwrite */
    boolean Psi5_DriverReadyToTransmit;   /*!< Driver is ready to transmit new data */

    /* PSI5 DMA event flags */
    boolean Psi5_Psi5DmaOverflow;         /*!< DMA FIFO is FULL */
    boolean Psi5_Psi5DmaUnderflow;        /*!< Underflow happens when the software reads the PSI5 message/error FIFO though the DPMR/DDSR, beyond the available message */
    boolean Psi5_Psi5DmaTransferComplete; /*!< DMA Transfer is complete */

    /* SMC DMA event flags */
    boolean Psi5_SmcDmaUnderflow;          /*!< This happens when the DSFR has been read without a proper DMA request being asserted. The DSFR is empty and it is read with DMA */
    boolean Psi5_SmcDmaTransferComplete;   /*!< DMA Transfer is complete */
} Psi5_Ip_EventType;

/*!
 * @brief Psi5 event type needed for callback
 *
 * Workaround because notification is defined in IP layer
 *
 * Implements : Psi5_EventType_Class
*/
typedef Psi5_Ip_EventType Psi5_EventType;

/*!
 * @brief Callback function
 *
 * PSI5 callback prototype. Called from IRQ.
 *
 * Implements : Psi5_CallbackType_func_Class
 */
typedef void(* Psi5_Ip_CallbackType)(Psi5_EventType Event);

/*!
 * @brief PSI5 slot data type
 *
 * Slot configuration structure
 *
 * Implements : psi5_slot_config_Class
 */
typedef struct
{
    uint8       slotId;     /*!< Slot id number (1-6) */
    uint16      slotLen;    /*!< Slot size (in us) */
    uint16      startOffs;  /*!< Slot start offset (from sync pulse, in us) */
    uint8       dataSize;   /*!< Data region length */
    boolean     msbFirst;   /*!< Data is interpreted as MSB first */
    boolean     hasSMC;     /*!< Contains a Slow Message Channel in bits M0/M1 */
    boolean     tsCapS0;    /*!< Capture time-stamp at S0, otherwise at sync */
    boolean     hasParity;  /*!< Contains parity error detection, CRC otherwise */
} Psi5_Ip_SlotConfigType;

/*!
 * @brief Raw data frame
 *
 * A raw PSI5/SMC frame. Contains hardware specific fields. Needs conversion.
 *
 * Implements : psi5_raw_frame_Class
 */
typedef uint32 Psi5_Ip_RawFrameType[2u];

/*!
 * @brief PSI5 data frame
 *
 * A PSI5 frame. Contains specific fields.
 *
 * Implements : Psi5_Ip_Psi5FrameType_Class
 */
typedef struct
{
    uint32 DATA_REGION;  /*!< Data region (28 bits) */
    uint32 TIME_STAMP;   /*!< Time stamp value (24 bits) */
    uint8  CRC;          /*!< CRC value Parity (3 bits, 1 bit parity in C[2] if configured) */
    uint8  C;            /*!< CRC error (1 bit) */
    uint8  F;            /*!< No Frame error (1 bit) */
    uint8  EM;           /*!< M0/1 Error (1 bit) */
    uint8  E;            /*!< Electrical error (1 bit) */
    uint8  T;            /*!< Timing error (1 bit) */
    uint8  SLOT_COUNTER; /*!< Slot number (3 bits) */
} Psi5_Ip_Psi5FrameType;

/*!
 * @brief SMC data frame
 *
 * A SMC frame. Contains specific fields.
 *
 * Implements : Psi5_SmcFrameType_Class
 */
typedef struct
{
    uint16 DATA;         /*!< DATA payload */
    uint8  SLOT_NO;      /*!< Slot number (3 bit)*/
    uint8  CER;          /*!< CRC error (1 bit) */
    uint8  OW;           /*!< Overwrite status (1 bit) */
    uint8  CRC;          /*!< CRC (6 bit) */
    uint8  C;            /*!< Configuration bit (1 bit) */
    uint8  ID;           /*!< Message ID: If C = '0' indicates ID[7:4], if C = '1' indicates ID[3:0] */
    uint8  IDDATA;       /*!< Message ID/DATA: If C = '0' indicates ID[3:0], if C = '1' indicates DATA[15:12] */
} Psi5_Ip_SmcFrameType;

typedef Psi5_Ip_RawFrameType Psi5_RawFrameType;

/*!
 * @brief Channel rx Psi5 Dmaconfiguration structure
 *
 * Contains configuration data for one channel.
 *
 */
typedef struct
{
    Psi5_Ip_Psi5DmaModeType             psi5DmaMode;                       /*!< Mode of PSI5 DMA Frame*/
    const uint32                        psi5DmaWatermarkDmaTrigger;        /*!< Interrupt request enabled when any new message (fault-free/with fault) is received in the RAM buffer Register 'x' location [x: 0 to 31] */
    Psi5_Ip_Psi5FrameType               *psi5DmaUserBuffer;                 /*!< DMA user data buffer for PSI5 messages */
    uint32                              *psi5DmaUserDiagnosticBuffer;       /*!< DMA user diagnostic buffer for PSI5 messages */
    Psi5_Ip_RawFrameType                *psi5DmaInternalBuffer;             /*!< DMA raw internal buffer for PSI5 messages */
    const uint8                         psi5DmaChannel;                    /*!< Assigned DMA channel for PSI5 frames */
} Psi5_Ip_ChannelRxPsi5DmaConfigType;

/*!
 * @brief Channel rx Smc Dmaconfiguration structure
 *
 * Contains configuration data for one channel.
 *
 */
typedef struct
{
    Psi5_Ip_SmcFrameType                *smcDmaUserBuffer;                  /*!< DMA user data buffer for Smc messages */
    Psi5_Ip_RawFrameType                *smcDmaInternalBuffer;              /*!< DMA raw internal buffer for PSI5 messages */
    const uint8                         smcDmaChannel;                     /*!< Assigned DMA channel for SMC frames */
} Psi5_Ip_ChannelRxSmcDmaConfigType;

/*!
 * @brief Channel rx configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5_channel_rx_config_Class
 */
typedef struct
{
    const uint8                                     rxBufSize;                  /*!< Size of RX buffer for PSI5 messages (1 - 32) */
    const uint32                                    watermarkInterruptLevel;    /*!< Interrupt request enabled when any new message (fault-free/with fault) is received in the RAM buffer Register 'x' location [x: 0 to 31] */
    const uint8                                     bitRate;                    /*!< 0 - 125 Kbit/s bit rate, 1 - 189 Kbit/s bit rate*/
    const Psi5_Ip_ChannelRxPsi5DmaConfigType        *psi5DmaConfig;              /*!< DMA buffer for PSI5 messages */
    const Psi5_Ip_ChannelRxSmcDmaConfigType         *smcDmaConfig;               /*!< DMA buffer for SMC messages */
    const Psi5_Ip_SlotConfigType                    *slotConfig;                 /*!< Pointer to a slot configuration list */
    const uint8                                     numOfSlotConfigs;           /*!< Number of configurations in the slot configuration list */
} Psi5_Ip_ChannelRxConfigType;

/*!
 * @brief Channel tx configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5_channel_tx_config_Class
 */
typedef struct
{
    const boolean                     syncGlobal;     /*!< Sync generator controlled by the instance */
    const boolean                     asyncReset;     /*!< GTM reset is treated asynchronous */
    const uint16                      initialPulse;   /*!< Initial reset reload value for the integrated pulse generator */
    const uint16                      targetPulse;    /*!< Subsequent reload values for the integrated pulse generator */
    const uint8                       decoderOffset;  /*!< Time in us for which the manchester decoder is disabled after the falling edge of a sync pulse */
    const uint8                       pulse0Width;    /*!< Width (in us) for a "0" output pulse */
    const uint8                       pulse1Width;    /*!< Width (in us) for a "1" output pulse */
    const Psi5_Ip_TxModeType          txMode;         /*!< Transmitter mode, please refer to RM */
    const Psi5_Ip_SyncStateType       syncState;      /*!< Pulse generator state, please refer to RM */
    const uint8                       txSize;         /*!< Tx data length (only for TX_MODE_7) */
    const boolean                     txDefault1;     /*!< All bits in Tx registers will default to "1" */
} Psi5_Ip_ChannelTxConfigType;

typedef struct
{
    const boolean                     errorSelect0;
    const boolean                     errorSelect1;
    const boolean                     errorSelect2;
    const boolean                     errorSelect3;
    const boolean                     errorSelect4;
} Psi5_Ip_ErrorSelectConfigType;


/*!
 * @brief Channel configuration structure
 *
 * Contains configuration data for one channel.
 *
 * Implements : psi5_channel_config_Class
 */
typedef struct
{
    const uint8                         channelId;                /*!< Channel id number (0-3) */
    const Psi5_Ip_ChannelModeType       channelMode;              /*!< Communication mode */
    const boolean                       debugEnable;              /*!< Enable/Disable debug mode */
    const boolean                       debugFreeze;              /*!< Enable/Disable debug freeze */
    const Psi5_Ip_CallbackType          callback;                 /*!< Callback data */
    const Psi5_Ip_ChannelRxConfigType   *rxConfig;                /*!< Rx Configuration */
    const Psi5_Ip_ChannelTxConfigType   *txConfig;                /*!< Tx Configuration */
    const Psi5_Ip_ErrorSelectConfigType *errorSelectConfig;       /*!< Error Select Configuration */
} Psi5_Ip_ChannelConfigType;

/*!
 * @brief Instance configuration structure
 *
 * PSI5 instance configuration structure. Contains all data required to configure the instance.
 *
 * Implements : psi5_driver_user_config_Class
 */
typedef struct
{
    const Psi5_Ip_InstanceIdType      instanceId;               /*!< PSI5 instance id */
    const boolean                     globalCtcEn;              /*!< Pulse generation automatically starts at init (outcome depends on channel configuration) */
    const Psi5_Ip_ChannelConfigType   *channelConfig;            /*!< Pointer to a channel configuration list */
    const uint8                       numOfChannels;            /*!< Number of channels configured */
    const uint8                       *chHwIdToIndexArrayConfig; /*!< Array with mapping of channel hw id to the index in channel config array */
} Psi5_Ip_InstanceType;
/*!
 * @brief Channels configuration structure
 *
 * PSI5 instance configuration structure. Contains all data required to configure the channels of an instance.
 *
 * Implements : psi5_driver_user_config_Class
 */
typedef struct
{
    const Psi5_Ip_InstanceType   *instancesConfig; /*!< Pointer to instances configuration list */
    const uint8                  numOfInstances;  /*!< Number of instances configured */
    const uint8                  *logicalChToHwCh; /*!< Pointer to array mapping logical channel to hardware channel */
} Psi5_Ip_ConfigType;

/*!
 * @brief Two arrays for both types of psi5 message format (psi5 and  smc)
 *
 * Both arrays are used in FILO mode. Contains position of received messages.
 * Last value from array different than 0 correspond with position of last received message.
 *
 * Implements : psi5_channel_config_Class
 */
typedef struct
{
    uint8 psi5CurrentIndex;                                    /*!< Index of last position filled in messages array */
    uint8 psi5PosMsgAvailable[PSI5_CHANNEL_CH_PMR_COUNT];  /*!< Buffer with locations of PSI5 messages available for reading. 0xFF - default, no message aavailable. Value != 0 means Position in reg NDSR. (internal use) */
    uint8 smcCurrentIndex;                                 /*!< Index of last position filled in array */
    uint8 smcPosMsgAvailable[PSI5_CHANNEL_CH_SFR_COUNT];   /*!< Buffer with locations of SMC messages available for reading. 0xFF - default, no message aavailable. Value != 0 means Position in reg (GISR & IS_NVSM_MASK). (internal use) */
} Psi5_Ip_AvailableMessagesType;

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

#endif /* PSI5_IP_TYPES_H */

