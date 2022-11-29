/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_TYPES_H
#define NETC_ETH_IP_TYPES_H

/**
*   @file Netc_Eth_Ip_Types.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Netc_Eth_Ip_Cfg_Defines.h"
#include "Netc_Eth_Ip_Features.h"
#include "Netc_Eth_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_TYPES_VENDOR_ID                    43
#define NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_TYPES_SW_MAJOR_VERSION             0
#define NETC_ETH_IP_TYPES_SW_MINOR_VERSION             9
#define NETC_ETH_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Cfg_Defines.h */
#if (NETC_ETH_IP_TYPES_VENDOR_ID != NETC_ETH_IP_CFG_DEFINES_VENDOR_ID)
    #error "Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg_Defines.h are different"
#endif
#if ((NETC_ETH_IP_TYPES_SW_MAJOR_VERSION != NETC_ETH_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_MINOR_VERSION != NETC_ETH_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_PATCH_VERSION != NETC_ETH_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg_Defines.h are different"
#endif

/* Checks against Netc_Eth_Ip_Features.h */
#if (NETC_ETH_IP_TYPES_VENDOR_ID != NETC_ETH_IP_FEATURES_VENDOR_ID)
    #error "Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Features.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Features.h are different"
#endif
#if ((NETC_ETH_IP_TYPES_SW_MAJOR_VERSION != NETC_ETH_IP_FEATURES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_MINOR_VERSION != NETC_ETH_IP_FEATURES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_PATCH_VERSION != NETC_ETH_IP_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Features.h are different"
#endif

/* Checks against Netc_Eth_Ip_Cfg.h */
#if (NETC_ETH_IP_TYPES_VENDOR_ID != NETC_ETH_IP_CFG_VENDOR_ID)
    #error "Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg.h are different"
#endif
#if ((NETC_ETH_IP_TYPES_SW_MAJOR_VERSION != NETC_ETH_IP_CFG_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_MINOR_VERSION != NETC_ETH_IP_CFG_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_PATCH_VERSION != NETC_ETH_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/** @brief Controller power state indication. */
typedef enum
{
    NETC_ETH_STATE_INACTIVE = 0U, /*!< Controller is powered on and Transmitter/Receiver are disabled */
    NETC_ETH_STATE_ACTIVE   = 1U  /*!< Controller is powered on and Transmitter/Receiver are enabled */
} Netc_Eth_Ip_PowerStateType;

/** @brief Type of the SI. */
typedef enum
{
    NETC_ETH_IP_PHYSICAL_SI = 0U,   /*!< Phyisical SI. */
    NETC_ETH_IP_VIRTUAL_SI  = 1U    /*!< Virtual SI. */
} Netc_Eth_Ip_StationInterfaceType;

/** @brief Ingress congestion management priority. Used for congestion management.
 *  TODO: Not in use.
 */
typedef enum
{
    ICM_LOW_PRIORITY  = 0U,    /*!< ICM low priority */
    ICM_HIGH_PRIORITY = 1U     /*!< ICM high priority */
} Netc_Eth_Ip_ICMType;

/** @brief Return values. */
typedef enum
{
    /* Generic error codes */
    NETC_ETH_IP_STATUS_SUCCESS                    = 0x000U,   /*!< Generic operation success status */
    NETC_ETH_IP_STATUS_ERROR                      = 0x001U,   /*!< Generic operation failure status */
    NETC_ETH_IP_STATUS_TIMEOUT                    = 0x003U,   /*!< Generic operation timeout status */
    NETC_ETH_IP_STATUS_UNSUPPORTED             = 0x004U,   /*!< Generic operation unsupported status. */
    NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND      = 0x005U,   /*!< The current searched MAC address is not used. */
    NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL     = 0x006U,   /*!< Table of MAC address is full. */
    NETC_ETH_IP_STATUS_DELETE_MAC_ADDR         = 0x007U,   /*!< MAC address was removed with success. */

    NETC_ETH_IP_STATUS_HOSTREASON_UNKNOWN      = 0x100U,
    NETC_ETH_IP_STATUS_HOSTREASON_TIMESTAMP    = 0x101U,


    NETC_ETH_IP_STATUS_TX_MANAGEMENT_BUFF_BUSY = 0x904U,   /*!< All internal TX buffers are currently in use */
    /* Specific error codes */
    NETC_ETH_IP_STATUS_RX_QUEUE_EMPTY             = 0xA01U,   /*!< There is no available frame in the receive queue */
    NETC_ETH_IP_STATUS_TX_QUEUE_FULL              = 0xA02U,   /*!< There is no available space for the frame in the transmit queue */
    NETC_ETH_IP_STATUS_BUFF_NOT_FOUND             = 0xA03U,   /*!< The specified buffer was not found in the queue */
    NETC_ETH_IP_STATUS_TX_BUFF_BUSY               = 0xA04U,   /*!< All internal TX buffers are currently in use */
    NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW           = 0xA05U,   /*!< The requested TX buffer length is not supported. */
    NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH       = 0xA06U,   /*!< The length of the frame should be minimum 16 bytes. */
#if(NETC_ETH_IP_HAS_CACHE_MANAGEMENT == STD_ON)
    NETC_ETH_IP_STATUS_CACHE_ERROR                = 0xA07U    /*!< Cache operation failed. */
#endif
} Netc_Eth_Ip_StatusType;

/** @brief Counters supported by ENETC. */
typedef enum
{
    NETC_ETH_IP_SIROCT0 = 0x300U, /*!< All bytes received (without frame errors) by the SI except preamble, SFD and CRC (if the CRC has been removed from the
                                       frame by the MAC). */
    NETC_ETH_IP_SIRFRM0 = 0x308U, /*!< Number of frames received by the SI without errors. */
    NETC_ETH_IP_SIRFRM1 = 0x30CU, /*!< Number of frames received by the SI with errors. */
    NETC_ETH_IP_SIRUCA0 = 0x310U, /*!< Number of unicast frames received by the SI without errors. */
    NETC_ETH_IP_SIRMCA0 = 0x318U, /*!< Number of multicast frames received by the SI without errors. */
    NETC_ETH_IP_SITOCT0 = 0x320U, /*!< All bytes transmitted (without errors) by the SI except preamble, SFD and CRC. */
    NETC_ETH_IP_SITFRM0 = 0x328U, /*!< Number of frames transmitted by the SI without errors with the exception of frames with error (BD status code point)
                                       0x020 (frame dropped due to port reset) or 0x0A0 (multi-bit ECC error), which will be counted in this counter.*/
    NETC_ETH_IP_SITFRM1 = 0x32CU, /*!< Total frames transmitted including frames with an error, including PAUSE frames. */
    NETC_ETH_IP_SITMCA0 = 0x338U, /*!< Number of multicast frames transmitted by the SI without errors. */
    NETC_ETH_IP_SITUCA1 = 0x334U  /*!< Number of unicast frames transmitted by the SI without errors. */
} Netc_Eth_Ip_CounterType;

/** @brief VLAN Protocol Identifier, which can be inserted in transmission and are acceptable for VLAN removal in reception.
 */
typedef enum
{
    NETC_ETH_IP_STANDARD_CVLAN   = 0x00U,       /*!< Standard C-VLAN 0x8100 */
    NETC_ETH_IP_STANDARD_SVLAN   = 0x01U,       /*!< Standard S-VLAN 0x88A8 */
    NETC_ETH_IP_CUSTOM_VLAN1     = 0x02U,       /*!< Custom VLAN as defined by CVLANR1[ETYPE] */
    NETC_ETH_IP_CUSTOM_VLAN2     = 0x03U        /*!< Custom VLAN as defined by CVLANR2[ETYPE] */
} Netc_Eth_Ip_VlanProtocolIdentifierType;

/** @brief Error type returned when transmit status is unsuccessfully. */
typedef enum
{
    NETC_ETH_TX_NO_ERR                 = 0x000U, /*!< No error detected after transmit. */
    NETC_ETH_TX_PROGRM_ERR             = 0x001U, /*!< An error exists in either the Tx BD, the Tx ring registers, or some combination of these. */
    NETC_ETH_TX_TSDD                   = 0x002U, /*!< TSDD - Time specific departure drop. */
    NETC_ETH_TX_FRAME_SIZE_ERROR       = 0x008U, /*!< Frame size error - consult the RM to get all possibilities. */
    NETC_ETH_TX_NULL_ADDR              = 0x009U, /*!< Null address */
    NETC_ETH_TX_INVALID_FBC_LENGTH     = 0x00AU, /*!< Invalid frame/buffer/chain length */
    NETC_ETH_TX_MAC_SPOOFING           = 0x010U, /*!< Source MAC address spoofing detected */
    NETC_ETH_TX_FRM_DROP_PORT_RESET    = 0x020U, /*!< Frame dropped due to port reset. */
    NETC_ETH_TX_FRM_DROP_PORT_DISABLE  = 0x021U, /*!< Frame dropped due to port disabled. */
    NETC_ETH_TX_VLAN_TPID_NOTALLOWED   = 0x040U, /*!< VLAN TPID not allowed. */
    NETC_ETH_TX_PROGRM_ERR_IN_BDR      = 0x060U, /*!< Programming error in buffer descriptor used for direct switch enqueue */
    NETC_ETH_TX_FRM_TOO_LARGE          = 0x080U, /*!< Frame too large for time gating window.  */
    NETC_ETH_TX_AXI_READ_ERR           = 0x090U, /*!< Frame not transmitted (dropped) due to an AXI read error detected. */
    NETC_ETH_TX_AXI_WRITE_ERR          = 0x091U, /*!< Frame not transmitted (dropped) due to an AXI write error detected. */
    NETC_ETH_TX_MULTIBIT_ECC_ERR       = 0x0A0U, /*!< Frame not transmitted (dropped) due to a multi-bit ECC error detected. */
    NETC_ETH_TX_PARITY_ERR             = 0x0F0U, /*!< Frame not transmitted (dropped) due to a parity write error detected. */
    NETC_ETH_TX_FRM_DROP_SW_CONGESTION = 0x100U  /*!< Frame dropped due to switch congestion */
} Netc_Eth_Ip_TxStatusType;

/** @brief Error type returned when receive status is unsuccessfully. */
typedef enum
{
    NETC_ETH_RX_NO_RECEIVE_ERR          = 0x00U, /*!< No error detected. */
    NETC_ETH_RX_FRM_CRC_FAIL            = 0x20U, /*!< Frame CRC (FCS) validation failed. */
    NETC_ETH_RX_L3_CKSUM_FAIL           = 0x40U, /*!< L3 (IPv4) Header Checksum validation failed. */
    NETC_ETH_RX_L4_CKSUM_FAIL           = 0x41U, /*!< L4 (TCP or UDP) Checksum validation failed. */
    NETC_ETH_RX_LGCPARITY_SRAM_MISMATCH = 0x80U, /*!< Internal logic parity or SRAM (ECC) mismatch detected. */
    NETC_ETH_RX_SYSBUS_READ_ERR         = 0x88U, /*!< System Bus Read Error detected during processing of the frame. */
    NETC_ETH_RX_SYSBUS_WRITE_ERR        = 0x89U  /*!< System Bus Write Error detected during processing of the frame. */
} Netc_Eth_Ip_RxStatusType;

/** @brief Shall represent the host reason for a received frame.
 *         Valid only in the first descriptor of a chain.
 */
typedef enum
{
    NETC_ETH_IP_REGULAR_FRAME          = 0U, /* Regular forwarded frame */
    NETC_ETH_IP_INGRESS_MIRRORING      = 1U, /* Ingress mirroring */
    NETC_ETH_IP_MAC_LEARNING           = 2U, /* MAC learning */
    NETC_ETH_IP_TIMESTAMP_RESPONSE     = 3U, /* Timestamp Response */
    NETC_ETH_IP_SW_DEFINED_HOST_REASON = 8U  /* Software defined Host Reason */
} Netc_Eth_Ip_HostReasonType;

/** @brief This flag will indicate the presence of what additional fields in TX descriptor.
 *         Valid only in the first descriptor of a chain.
 */
typedef enum
{
    NETC_ETH_IP_SWT_MANAGEMNT = 0x00U, /*!< Switch management optional fields are present. */
    NETC_ETH_IP_RESERVED_FLAG = 0x01U, /*!< Reserved value of the flag field. */
    NETC_ETH_IP_TXSTART       = 0x02U  /*!< TX_START field is present in the descriptor. */
} Netc_Eth_Ip_TxOptionsFlagType;

/**
 * @brief Action type which can be done through VSI to PSI messaging.
 *        0x1234 -> first byte(12)  - CLASS
 *               -> second byte(32) - COMMAND
 * @internal
 */
typedef enum
{
    NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET              = 0x0000U, /*!< VSI sent a set MAC command. */
    NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_FILTER    = 0x0100U, /*!< VSI sent an add filter for a MAC command. */
    NETC_ETH_IP_VSITOPSI_DELETE_RX_MAC_ADDR_FILTER = 0x0101U, /*!< VSI sent a delete filter MAC command. */
    NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST          = 0x1000U, /*!< VSI sent a request to enable multicast promiscuous mode. */
    NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST         = 0x1010U, /*!< VSI sent a request to disable multicast promiscuous mode. */
    NETC_ETH_IP_VSITOPSI_CLOSE_FILTER              = 0x1020U  /*!< VSI sent a request to stop all multicast traffic. */
} Netc_Eth_Ip_VsiToPsiMsgActionType;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Callback function invoked when a general event is encountered. */
typedef void (*Netc_Eth_Ip_CallbackType)(uint8 Controller);

/** @brief Signature of the callback function invoked when a specific queue event is encountered */
typedef void (*Netc_Eth_Ip_ChCallbackType)(uint8 Controller, uint8 Ring);

/** @brief  Station interface command buffer description. */
typedef struct
{
    void  *commandBDAddr; /*!< Address where command buffer descriptor will be saved. The address must be 128 byte aligned. */
    uint8 lengthCBDR;     /*!< Number of command buffer descriptors ring. */
} Netc_Eth_Ip_CommandBDType;

/** @brief Message configuration structure.Should be a multiple of 32 bytes. */
typedef struct
{
    uint8 Class;        /*!< Class of the command. */
    uint8 Command;      /*!< Type of command. */
    uint8 Data[30U];    /*!< Data. */
} Netc_Eth_Ip_VsiToPsiMsgType;

/** @brief CBD generic format. */
typedef struct
{
    uint32 addrL;         /*!< Address low. */
    uint32 addrH;         /*!< Address high. */
    uint32 data[4U];      /*!< The content of this data depends on the class and command type. */
    uint16 length;        /*!< The length field specifies the effective number of bytes in the data buffer pointed to by ADDR field. */
    uint16 index;         /*!< The index refers to an entry location within a table. */
    uint16 commandConfig; /*!< Set of flags. */
    uint8  classCommand;  /*!< Class of command. See CMD field to determine operation. */
    uint8  cmd;           /*!< Used with class to determine operation. */
} Netc_Eth_Ip_CommandBDFormatType;

/** @brief Transmit buffer descriptor. */
typedef struct
{
    uint32 dataBuffAddr;     /*!< Address where the data for transmit operation is stored. */
    const uint32 RESERVED_0; /*!< UNUSED! Only used for the system with address spaces on 64 bits. */
    uint32 length;           /*!< Length of data buffer(it will be in bytes). */
    uint32 buffConfig;       /*!< Buffer descriptor configuration for a normal descriptor. */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint32 timestamp;            /*!< Timestamp value used to update packet header field on transmission. */
    uint32 extendVlanBuffConfig; /*!< VLAN specific configuration. */
    const uint32 RESERVED_1;     /*!< UNUSED! Not configured by hardware! */
    uint32 extendBuffConfig;     /*!< Buffer descriptor configuration for an extended descriptor. */
#endif
} Netc_Eth_Ip_TxBDRType;

/** @brief Transmit buffer descriptor writeback. */
typedef struct
{
    const uint32 Timestamp;       /*!< Address where the data for transmit operation is stored. */
    const uint16 TxTimestampID;   /*!< UNUSED! Only used for the system with address spaces on 64 bits. */
    const uint16 RESERVED_0;      /*!< UNUSED! */
    const uint32 RESERVED_1;      /*!< UNUSED! */
    const uint16 RESERVED_2;      /*!< UNUSED! */
    const uint16 FlagsAndStatus;  /*!< Buffer descriptor configuration for a normal descriptor. */
} Netc_Eth_Ip_TxBDRWritebackType;


/** @brief Transmit Timestamp Reference Response Buffer Descriptor Format. */
typedef struct
{
    const uint32 Timestamp;          /*!< Timestamp; synchronized timestamp or a free running timestamp */
    const uint32 RESERVED_0;         /*!< UNUSED! */
    const uint16 TxTimestampID;      /*!< Transmit Timestamp Identifier. */
    const uint16 RESERVED_1;         /*!< UNUSED! */
    const uint16 HostReason;         /*!< Host Reason 0: Regular forwarded frame
                                                      1: Ingress mirroring
                                                      2: MAC learning
                                                      3: Timestamp Response
                                                      4-7: Reserved
                                                      8-15: Software defined Host Reason */
    const uint16 FlagsAndErrorStat;  /*!< Final flag + Ready flag + Error status code for the received frame. */
} Netc_Eth_Ip_TxTimestampResponseType;

/**
 * @brief   Transmit internal buffer descriptor.
 * @details The fildes of this stucture are generic.
 *  - at initialization the first 2 words are used to store the location in which the receive frame will be stored;
 *  - after a frame is received information will be conform with the reference manual.
 */
typedef struct
{
    uint32 configRxBD[4]; /*!< Generic configuration of a Rx BDR. */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint32 extendConfigRxBD[4]; /*!< Extended generic configuration of a Rx BDR. */
#endif
} Netc_Eth_Ip_RxBDRType;

/**
 * @cond DRIVER_INTERNAL_USE_ONLY
 * @brief Internal driver state structure
 */
typedef struct
{
    uint8 CtrlLogicalIndex;                    /*!< This member keep the value of controller index for the callback function. */
    Netc_Eth_Ip_CallbackType Callback;                      /*!< Callback function for general interrupts. */
    /* --------------------- RX ------------------- */
    Netc_Eth_Ip_ChCallbackType RxCallback[FEATURE_NETC_RX_BDR_COUNT]; /*!< Callback function for current Rx channel. */
    /** TODO: Make the value store in this pointer array a const, if there is any possibility. */
    Netc_Eth_Ip_RxBDRType *FirstRxRingDescAddr[FEATURE_NETC_RX_BDR_COUNT]; /*!< Array with starting address of each ring of descriptors for a SI. */
    Netc_Eth_Ip_RxBDRType *RxCurrentDesc[FEATURE_NETC_RX_BDR_COUNT];            /*!< The current available receive buffer descriptor pointer array. */
    uint8  *FirstRxDataBufferAddr[FEATURE_NETC_RX_BDR_COUNT];                   /*!< Array with starting address of each data buffer used to store RX data by ring. */
    uint16 RxRingSize[FEATURE_NETC_RX_BDR_COUNT];
    uint16 rxCurrentIndex[FEATURE_NETC_RX_BDR_COUNT];                           /*!< Index of the current decriptor in ring. */
    uint16 RxDataBuffMaxLenAddr[FEATURE_NETC_RX_BDR_COUNT];
    uint16 LogicRxConsumerIndex[FEATURE_NETC_RX_BDR_COUNT];                     /*!< Store reception consumer index for each ring. */

    /* --------------------- TX ------------------- */
    Netc_Eth_Ip_ChCallbackType TxCallback[FEATURE_NETC_TX_BDR_COUNT]; /*!< Callback function for current Tx channel. */
    uint16 LogicTxProducerIndex[FEATURE_NETC_TX_BDR_COUNT]; /*!< Store transmission producer index for each ring. */
    boolean LockTxBuffDescr[FEATURE_NETC_TX_BDR_COUNT][NETC_ETH_MAX_NUMBER_OF_TXBD]; /*!< This flag will show the state of the data buffer ready(= FALSE)/busy(= TRUE). */
    uint32  lastTxDataBuffAddrIdx[FEATURE_NETC_TX_BDR_COUNT];                        /*!< Last buffer address status checked. */
    uint8   *TxDataBuffAddr[FEATURE_NETC_TX_BDR_COUNT][NETC_ETH_MAX_NUMBER_OF_TXBD]; /*!< Store address of the transmitted buffer for each descriptor. */
    uint16 TxRingSize[FEATURE_NETC_TX_BDR_COUNT];                           /*!< Number of buffers descriptors for the current ring. */
    uint16 TxBufferLength[FEATURE_NETC_TX_BDR_COUNT];                       /*!< Length of each individual buffer in a pool. */
    Netc_Eth_Ip_TxBDRType *FirstTxRingDescAddr[FEATURE_NETC_TX_BDR_COUNT];  /*!< Buffer descriptor ring start address. */
    uint8 *FirstTxDataBufferAddr[FEATURE_NETC_TX_BDR_COUNT];                /*!< Array with starting address of each data buffer used to store TX data by ring. */
    uint16 TxDataBuffMaxLenAddr[FEATURE_NETC_TX_BDR_COUNT];                 /*!<  */

    Netc_Eth_Ip_TxBDRType *TxNextDesc[FEATURE_NETC_TX_BDR_COUNT];      /*!< The next available transmit buffer descriptor pointer array. */
    Netc_Eth_Ip_VsiToPsiMsgType *VSItoPSIMsgCommand;                   /*!< The VSI command sends to PSI. */
    uint8 NumberOfRxBDR;                       /*!< The number of configured RX BDR */
    uint8 NumberOfTxBDR;                       /*!< The number of configured TX BDR */
    Netc_Eth_Ip_StationInterfaceType SiType;          /*!< The type of the SI (PSI or VSI). */
    uint8 MACFilterTableMaxNumOfEntries; /*!< Maximum number of entries in the MAC filter table. */
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    uint32   *RxDataBuffAddr;                                         /*!< Store address of the received external buffer for each descriptor. */
#endif
    uint32 TxTimerThreshold[FEATURE_NETC_TX_BDR_COUNT];               /*!< Timer threshold, specified in units of NETC clock cycles. 
                                              This value determines the maximum amount of
                                              time allowed between a first transmitted packet until the TBaICR0[ICPT] 
                                              (no. of packets) threshold is reached. */
    uint8 TxPacketsThreshold[FEATURE_NETC_TX_BDR_COUNT];              /*!< This value determines the minimum number of packets transmitted before 
                                              raising an interrupt. 2^(PacketsThreshold-1) packets*/
    uint32 RxTimerThreshold[FEATURE_NETC_RX_BDR_COUNT];               /*!< Timer threshold, specified in units of NETC clock cycles. 
                                              This value determines the maximum amount of
                                              time allowed between a first transmitted packet until the TBaICR0[ICPT] 
                                              (no. of packets) threshold is reached. */
    uint16 RxPacketsThreshold[FEATURE_NETC_RX_BDR_COUNT];              /*!< This value determines the minimum number of packets received before raising an interrupt. */
    uint32 RxInterrupts;                    /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
    uint32 TxInterrupts;                    /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */

} Netc_Eth_Ip_StateType;
/** @endcond DRIVER_INTERNAL_USE_ONLY */

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
/**
 * @brief VLAN specific configuration.
 */
typedef struct Netc_Eth_Ip_VlanType
{
    Netc_Eth_Ip_VlanProtocolIdentifierType ProtocolIdentifier; /*! Tag protocol identifier. */
    uint8  PriorityCodePoint; /*! Priority code. */
    boolean  DropIndicator;     /*! Indicate frames eligible to be dropped in the presence of congestion. */
    uint16 VlanIdentifier;    /*! The VLAN identifier is a 12-bit field specifying the VLAN to which the frame belongs. */
} Netc_Eth_Ip_VlanType;
#endif

/**
 * @brief   Everything that can be configured by the PSI for itself(also Port) or for the VSIs.
 * @details This structure contains general configuration of the NETC for Ethernet driver.
 * This will affect also every VSI configured aftwareds in other projects. Please, be aware that this will affect all other cotrollers used.
 */
typedef struct Netc_Eth_Ip_GeneralSIConfigType
{
    /* General configurations of SI. */
    uint8 siId;          /*< The index of the SI */
    boolean enableSi;    /*< Enable/disable the SI. */
    uint8 NumberOfRxBDR; /*< The number of allowed RX BDR */
    uint8 NumberOfTxBDR; /*< The number of allowed TX BDR */
    uint8 numberOfMSIs;  /*< The number of assigned MSIs */
    uint8 priorityToTrafficClassMapping[NETC_ETH_IP_NUMBER_OF_PRIORITIES]; /*< Port station interface a configuration register 1 (PSI1CFGR1 - PSI7CFGR1).
                                                                        The field will not be used for PSI0 */
    /** TODO: other fields from Port station interface 0 configuration register 0 (PSI0CFGR0) */
    /* MAC configurations */
    uint8   primaryMACAddress[6U];  /*< The primary MAC address of the SI. For PSI0 this actually gets written in PMAR0 and PMAR1 */
    /* TODO: Permission to change MAC address Boolean */
    /* TODO: MAC filtering configuration */

    /* VLAN configurations */
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    boolean EnableSIVlan;                 /*! SI-based VLAN information is added on transmit and removed on receive if matched (PSIaVLANR). */
    Netc_Eth_Ip_VlanType SiVLANConfig;              /*!< Vlan configuration for each SI-based */
    boolean EnableSoftwareVlanInsert;               /*!< Enable Software VLAN Insertion (PSICFGR0[SIVIE]) */
    uint8 SIVlanControl;   /*!< Determines which VLAN Ethertypes can be inserted by the SI driver (PSICFGR0[SIVC]) */
    boolean EnableVLANTagExtract; /*!< Controls whether SI-based VLAN tag is removed from the frame before delivery to the SI(PSICFGR0[VTE]) */
#endif
    boolean enableAntiSpoofing;  /*< Enable or disable the Anti-Spoofing */

    /* boolean enableMulticastVLANPromiscuosMode; */ /* Enable or disable the Multicast VLAN Promiscuos Mode */
    /* boolean enableUnicastVLANPromiscuosMode; */   /* Enable or disable the Unicast VLAN Promiscuos Mode */
    /* TODO: Permission to change VLAN membership Boolean */
    /* TODO: VLAN filtering configuration */
} Netc_Eth_Ip_GeneralSIConfigType;

/**
 * @brief Credit based shaper configuration.
 * @note Not supported yet.
 */
typedef struct Netc_Eth_Ip_CreditBasedShaperConfigType
{
    uint8  trafficClass; /*!< The traffic class on which the CBS is used for. (Range: 0 to 7) */
    uint8  cbsIndex;     /*!< The index of the CBS. For each traffic class a certain number of CBSs can be configured. */
    uint8  bandwith;     /*!< The bandwith which will be calculated based on the port rate and the idle slope */
    uint32 hiCredit;     /*!< */
} Netc_Eth_Ip_CreditBasedShaperConfigType;

/*! @brief Enetc general configuration. To be applied by the PSI for the whole Enetc controller part. */
typedef struct Netc_Eth_Ip_EnetcGeneralConfigType
{
    uint8 numberOfConfiguredSis; /*!< The number of enabled SIs */
    const Netc_Eth_Ip_GeneralSIConfigType (*stationInterfaceGeneralConfig)[FEATURE_NETC_ETH_NUMBER_OF_CTRLS]; /*!< The general configuration for all the enabled SIs */
    const Netc_Eth_Ip_VsiToPsiMsgType *RxVsiMsgCmdToPsi[FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS]; /*!< Array of addresses where PSI will store the receive message from VSI. */
    /* boolean enablePortOuterVlan; */            /* PONVLANR */ /** SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* boolean useNativePortOuterVlan; */         /* PONVLANR - PNE bitfield */ /*! SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* Netc_Eth_Ip_VlanType *portInnerVLANConfig; */ /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* boolean enableInnerOuterVlan; */           /* PINVLANR */ /*! SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* boolean useNativePortInnerVlan; */         /* PINVLANR - PNE bitfield */ /*! SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* Netc_Eth_Ip_VlanType *portOuterVLANConfig; */ /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* TBD: Port VLAN classification control register (PVCLCTR) */
    /* TBD: Parse configuration (several registers) */
    /* TBD: Port pause configuration */
    /* TBD: Port station interface VLAN filtering mode register (PSIVLANFMR) */
    Netc_Eth_Ip_ICMType priorityToICM[NETC_ETH_IP_NUMBER_OF_PRIORITIES];  /*!< Mapping of internal priority to ICM. Receive IPV to ICM priority mapping register 0 (IPV2ICMPMR0) */
    uint8 priorityToTrafficClassic[NETC_ETH_IP_NUMBER_OF_PRIORITIES];     /*!< Mapping of transmit BD rings priority to traffic class. Transmit priority to traffic class mapping register 0 (PRIO2TCMR0) */
    uint8 pcpToIpv[NETC_ETH_IP_NUMBER_OF_PRIORITIES];                     /*!< Mapping of Pcp from VLAN Tag to internal priority. VLAN to IPV mapping profile a register 0 (VLANIPVMP0R0 - VLANIPVMP1R0) */
    /* TBD: VLAN to DR mapping profile a register (VLANDRMP0R - VLANDRMP1R) */
    /* TBD: All the tables */
    /* ------------ Port configuration ------------- */
    /* TBD: Port configuration register (PCR)   - low priority for basic driver */
    /* TBD: Port TPID acceptance register (PTAR) - low priority for basic driver */
    /* TBD: Port QoS mode register (PQOSMR) - low priority for basic driver */
    /* TBD: Port parser configuration register (PPCR) - low priority for basic driver */
    /* TBD: Port ingress port filter configuration register (PIPFCR) - low priority for basic driver */
    /* TBD: Port stream gate configuration register (PSGCR) - low priority for basic driver */
    /* TBD: A lot of other stream gate and frame preemption settings - low priority for basic driver */
    uint8 numberOfConfiguredCbs; /*!< Number of configured CBS. */
    Netc_Eth_Ip_CreditBasedShaperConfigType *cbsConfig[16U]; /*!< Configuration of each CBS used. */
    uint16 maskMACPromiscuousMulticastEnable; /*!< Enable/Disable promiscuous multicast for all controllers. */
    uint16 maskMACPromiscuousUnicastEnable;   /*!< Enable/Disable promiscuous unicast for all controllers. */
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    uint32 CustomVlanEthertype1;              /*!< Configure for custom VLAN Ethertype 1 register (CVLANR1). */
    uint32 CustomVlanEthertype2;              /*!< Configure for custom VLAN Ethertype 1 register (CVLANR2). */
#endif
    /** TODO: other fields from Port station interface 0 configuration register 0 (PSI0CFGR0) */
} Netc_Eth_Ip_EnetcGeneralConfigType;

/** @brief The station interface configuration. This applies to all SIs either PSI or VSI. */
typedef struct Netc_Eth_Ip_StationInterfaceConfigType
{
    boolean enableVlanToIpvMapping;            /*!< V2IPVE - enables the mapping of PCP+DEI to IPV. */
    boolean discardBroadcastFrames;            /*!< RNBM - enables or disables discarding all broadcast frames */
    boolean discardMulticastFrames;            /*!< RNMM - enables or disables discarding all multicast frames */
    boolean discardUnicastFrames;              /*!< RNUM - enables or disables discarding all unicast frames */
    uint8 vlanToIpv[16U];                      /*!< Station interface VLAN to IPV mapping register 0 (SIVLANIPVMR0). PCP+DEI mapping to IPV */
    uint8 ipvToBDR[8U];                        /*!< Station interface IPV to ring mapping register (SIIPVBDRMR0). Mapping of IPV to BDR */
    uint8 NumberOfRxBDR;                       /*!< The number of configured RX BDR */
    uint8 NumberOfTxBDR;                       /*!< The number of configured TX BDR */
    Netc_Eth_Ip_CommandBDType commandBDConfig; /*!< This will store the configuration of the command BDR. */
    Netc_Eth_Ip_VsiToPsiMsgType *VSItoPSIMsgCommand; /*!< Address of the command message sent from VSI to PSI. */
    uint8 CtrlLogicalIndex;                    /*!< This member keep the value of controller index for the callback function. */

    /* TODO: This information will be added temporary until MRU driver will be created. */
    uint32 *txMruMailboxAddr;    /*!< Mailbox address for TX. */
    uint32 *rxMruMailboxAddr;    /*!< Mailbox address for RX. */
    uint32 *siMsgMruMailboxAddr; /*!< Mailbox address for VSI to PSI messenging. */

    uint8 MACFilterTableMaxNumOfEntries; /*!< Maximum number of entries in the MAC filter table. */
    uint32 RxInterrupts;                   /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
    uint32 TxInterrupts;                   /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
} Netc_Eth_Ip_StationInterfaceConfigType;

/** @brief Specialization of ring configuration for Tx Rings. */
typedef struct
{
    Netc_Eth_Ip_TxBDRType *RingDesc;     /*!< Buffer descriptor ring start address. */
    Netc_Eth_Ip_ChCallbackType Callback; /*!< Callback function for current channel. */
    uint8 *Buffer;                       /*!< Buffer data pool start address */
    uint16 ringSize;                     /*!< Number of buffers descriptors for the current ring. */
    uint16 maxRingSize;                  /*!< The maximum number of descriptors for the current ring between all variants.
                                              It is used for AUTOSAR specification. */
    uint16 bufferLen;                    /*!< Length of each individual buffer in a pool. */
    uint16 maxBuffLen;                   /*!< Maximum buffer size length supported by a transmit buffer for curent ring.
                                              This member is variant aware, it is used for AUTOSAR specification. */
    uint8 Weight;                        /*!< Weight value. (0 to 7) */
    uint8 Priority;                      /*!< Priority. 0 is lowest, 7 is highest */
    uint32 TimerThreshold;               /*!< Timer threshold, specified in units of NETC clock cycles. 
                                              This value determines the maximum amount of
                                              time allowed between a first transmitted packet until the TBaICR0[ICPT] 
                                              (no. of packets) threshold is reached. */
    uint8 PacketsThreshold;              /*!< This value determines the minimum number of packets transmitted before 
                                              raising an interrupt. 2^(PacketsThreshold-1) packets*/
} Netc_Eth_Ip_TxRingConfigType;

/** @brief RX ring configuration */
typedef struct
{
    Netc_Eth_Ip_RxBDRType      *RingDesc; /*!< Buffer descriptor ring start address. */
    Netc_Eth_Ip_ChCallbackType Callback;  /*!< Callback function for current channel. */
    uint8 *Buffer;                        /*!< Buffer data pool start address */
    uint16 ringSize;                      /*!< Number of buffers descriptors for the current ring. */
    uint16 maxRingSize;                   /*!< The maximum number of descriptors for the current ring between all variants.
                                               It is used for AUTOSAR specification. */
    uint16 bufferLen;                     /*!< Length of each individual buffer in a pool */
    uint16 maxBuffLen;                    /*!< Maximum buffer size length supported by a receive buffer for curent ring.
                                               This member is variant aware, it is used for AUTOSAR specification. */
    uint32 TimerThreshold;               /*!< Timer threshold, specified in units of NETC clock cycles. 
                                             This value determines the maximum amount of
                                             time allowed between a first received packet until RBaICR0[ICPT] (no. of packets)
                                             threshold is reached. */
    uint16 PacketsThreshold;              /*!< This value determines the minimum number of packets received before 
                                              raising an interrupt. 1 -> 16384*/
} Netc_Eth_Ip_RxRingConfigType;

/**
 * @brief Controller configuration for a SI from ENETC.
 * @details This will be used for Netc_Eth_Init. The SI type will generate the specific configuration.
 */
typedef struct
{
    Netc_Eth_Ip_StationInterfaceType             SiType;          /*!< The type of the SI (PSI or VSI). */
    const Netc_Eth_Ip_EnetcGeneralConfigType     *generalConfig;  /*!< ENETC Base Register configuration. Only used for PSI, NULL_PTR for VSI. */
    const Netc_Eth_Ip_StationInterfaceConfigType *siConfig;       /*!< ENETC Station Interface Register configuration. */
    Netc_Eth_Ip_StateType                        *stateStructure; /*!< State structure for current controller. */
    const Netc_Eth_Ip_RxRingConfigType           (*paCtrlRxRingConfig)[]; /*!< Address of the array where RX rings are configured. */
    const Netc_Eth_Ip_TxRingConfigType           (*paCtrlTxRingConfig)[]; /*!< Address of the array where TX rings are configured. */
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    uint32 *rxExternalBuffersAddr;                                  /*!< Array that will keep the addresses of the external rx buffers. */
#endif
} Netc_Eth_Ip_ConfigType;

/*!
 * @brief User buffer type.
 * @implements Netc_Eth_Ip_BufferType_structure
 */
typedef struct
{
    uint8  *data;   /*!< Pointer to data buffer */
    uint16 length;  /*!< Length of the data buffer */
} Netc_Eth_Ip_BufferType;

/*!
 * @brief Defines the timestamp.
 * @implements Netc_Eth_Ip_TimestampType_structure
 */
typedef struct
{
    uint32 nanoseconds;  /*!< Nanoseconds part of the time. */
    uint32 seconds;      /*!< The 32 least significant bits of the 48 bits seconds part of the time. */
    uint16 secondsHi;    /*!< The 16 most significant bits of the 48 bit seconds part of the time. */
} Netc_Eth_Ip_TimestampType;

/** @brief Transmit options for a particular frame. */
typedef struct
{
    Netc_Eth_Ip_TxOptionsFlagType Flag; /*!< This option will set the usage of the additional fields. */
    uint8 SwtMgSendingOpt;              /*!< Select between: 0 - Switch Port Masquerading
                                                             1 - Direct Switch Enqueue */
    uint8 TimestampRefReq;              /*!< Valid when SwtMgSendingOpt = 1. Request to capture the timestamp
                                             when the frame's SFD is transmitted by the switch's Ethernet MAC. */
    uint8 IngrOrEgrPortNumber;          /*!< Ingress or Egress switch port number this frame is to be injected towards.
                                             Ingress - SwtMgSendingOpt = 0; Egress - SwtMgSendingOpt = 1 */
    uint8 InternalPriority;             /*!< Used to determine switch egress queue and buffer pool. SwtMgSendingOpt = 1 */
    uint8 DiscardResilience;            /*!< This field is used for congestion management handling within the switch. */
    uint8 TxStartEnable;                /*!< Transmit start enable */
    uint32 TxStartTime;                 /*!< Transmit start time */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint8 PriorityCodePoint;            /*!< Contains the PCP value of the VLAN tag to be inserted in the packet during transmission. */
    uint8 DropEligible;                 /*!< Contains the DEI value of the VLAN tag to be inserted in the packet during transmission. */
    uint8 ExtensionFlags;               /*!< Indicates what offloads are enabled for this frame. */
    uint8 TagProtocolID;                /*!< Contains the TPID of the VLAN tag to be inserted in the packet during transmission. */
    uint16 VlanID;                      /*!< Identifier of the VLAN tag to be inserted in the packet during transmission. */
    uint32 Timestamp;                   /*!< Timestamp value used to update packet header field on transmission. */
#endif
} Netc_Eth_Ip_TxOptionsType;

/*!
 * @brief Detailed status of a transmit buffer descriptor.
 * TODO: Update when VLAN info will be added.
 * @implements Netc_Eth_Ip_TxInfoType_structure
 */
typedef struct
{
    Netc_Eth_Ip_TimestampType timestamp;  /*!< The timestamp of the transmitted packet. */
    Netc_Eth_Ip_TxStatusType  txStatus;   /*!< Error status in the descriptor to be transmitted. */
} Netc_Eth_Ip_TxInfoType;

/*!
 * @brief Structure to store detailed status of a receive buffer descriptor.
 * TODO: Update when VLAN info will be added.
 * @implements Netc_Eth_Ip_RxInfoType_structure
 */
typedef struct
{
    Netc_Eth_Ip_RxStatusType     rxStatus;          /*!< The error code in case of frame not received correct.*/
    boolean                      L4cksum;           /*!< L4 (TCP or UDP) Checksum was validated and found to be correct. */
    boolean                      L3cksum;           /*!< L3 (IPv4) Header Checksum was validated and found to be correct. */
    boolean                      timestampReceived; /*!< Timestamp received */
    boolean                      vlanHeaderAvl;     /*!< VLAN header extracted */
    uint16                       pktLen;            /*!< Length of the received packet. */
    Netc_Eth_Ip_HostReasonType   hostReason;        /*!< Host Reason.*/
    boolean                      finalDes;          /*!< Determines the last buffer descriptor in a chain.*/
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    Netc_Eth_Ip_VlanType         VlanInfo;          /*!< Informations of VLAN frames.*/
#endif
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint32                       PacketTimestamp;   /*!< The timestamp of the received packet. */
#endif
} Netc_Eth_Ip_RxInfoType;

/** @brief MSI(message interrupt) table type. */
typedef struct
{
    /* this type of structure is saved in NETC device memory which not supports burst writes and it will rise a bus hardfault in that case
     * volatile was added because otherwise compiler optimize writes on memory */
    volatile uint32 *msgAddr;      /*!< Address of the mailbox. */
    volatile uint32 RESERVED_0;    /*!< NOT USED. */
    volatile uint32 msgData;       /*!< Data transmitted by the interrupt event. */
    volatile uint32 controlVector; /*!< */
} Netc_Eth_Ip_MSITableEntry;

/** @brief MSI table for each SI. */
typedef struct
{
    Netc_Eth_Ip_MSITableEntry msiTable[3U]; /*!< Array with all entries in table. */
} Netc_Eth_Ip_MSITable;

/** @brief Entry type for MAC filter hash table. */
typedef struct
{
    boolean EntryStatus; /*!< Status of the entry. TRUE - entry in use; FALSE - entry not used yet or deleted. */
    uint8   HashValue;   /*!< Hash value for the MAC address. */
    uint8   MACAddr[6U]; /*!< MAC address. */
} Netc_Eth_Ip_MACFilterHashTableEntryType;

/** @brief Store the counter values for time. */
typedef struct
{
    uint32 nanosecondsL;    /*!< Nanoseconds low part of the time. */
    uint32 nanosecondsH;    /*!< Nanoseconds high part of the time. */
} Netc_Eth_Ip_TimeType;

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
/** @brief Timestamps information. */
typedef struct
{
    boolean TxTimestampFlag;
    boolean ManagementFrameFlag;
    uint8   CtrlIdx;
    uint8   SwitchIndex;
    uint8   PortIndex;
    uint16  TxTimeStampID;
    uint16  TxBuffId;
    Netc_Eth_Ip_TxBDRType *TxBuffAddr;
    Netc_Eth_Ip_TimeType   TimestampValue;
} Netc_Eth_Ip_TxTimestampInfoType;
#endif /* NETC_ETH_0_USED */

/** @brief Timestamp received frame information. */
typedef struct
{
    uint8                RingIdx;
    uint8               *ReceivedDataPtr;
    boolean              TimestampValueInvalidForEth;  /*!< Mark if the current timestamp is invalid. */
    boolean              TimestampValueInvalidForSwt;  /*!< Mark if the current timestamp is invalid. */
    uint32               TimestampID;                  /*!< This represents a uniq ID inside a Netc_Eth_Ip_RxTimestampInfo buffer. */
    Netc_Eth_Ip_TimeType TimestampValue;
} Netc_Eth_Ip_RxTimestampInfoType;

#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif
