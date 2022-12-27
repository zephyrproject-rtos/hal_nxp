/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETHSWT_IP_TYPES_H
#define NETC_ETHSWT_IP_TYPES_H

/**
 *   @file Netc_EthSwt_Ip_Types.h
 *   @addtogroup NETC_ETHSWT_IP NETC_ETHSWT Driver
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
#include "Netc_EthSwt_Ip_Cfg.h"
#include "Netc_EthSwt_Ip_Cfg_Defines.h"
#include "Eth_GeneralTypes.h"
#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_TYPES_VENDOR_ID                    43
#define NETC_ETHSWT_IP_TYPES_MODULE_ID                    89
#define NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION             0
#define NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION             9
#define NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Netc_EthSwt_Ip_Cfg.h */
#if (NETC_ETHSWT_IP_TYPES_VENDOR_ID !=  NETC_ETHSWT_IP_CFG_VENDOR_ID)
    #error "Netc_EthSwt_Ip_Types.h and Netc_EthSwt_Ip_Cfg.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION    !=  NETC_ETHSWT_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION    !=  NETC_ETHSWT_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION !=  NETC_ETHSWT_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Types.h and Netc_EthSwt_Ip_Cfg.h are different"
#endif
#if (( NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION !=  NETC_ETHSWT_IP_CFG_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION !=  NETC_ETHSWT_IP_CFG_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION !=  NETC_ETHSWT_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip_Types.h and Netc_EthSwt_Ip_Cfg.h are different"
#endif

/* Checks against Netc_EthSwt_Ip_Cfg_Defines.h */
#if (NETC_ETHSWT_IP_TYPES_VENDOR_ID !=  NETC_ETHSWT_IP_CFG_DEFINES_VENDOR_ID)
    #error "Netc_EthSwt_Ip_Types.c and Netc_EthSwt_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION    !=  NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION    !=  NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION !=  NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Types.c and Netc_EthSwt_Ip_Cfg_Defines.h are different"
#endif
#if (( NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION !=  NETC_ETHSWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION !=  NETC_ETHSWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION !=  NETC_ETHSWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip_Types.c and Netc_EthSwt_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
	#if ((NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
		 (NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
		)
		#error "AutoSar Version Numbers of Netc_EthSwt_Ip_Types.h and Eth_GeneralTypes.h are different"
	#endif
    /* Check if header file and StandardTypes.h are of the same AUTOSAR version */
    #if ((NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

#define NETC_ETHSWT_NUMBER_OF_PSEUDO_PORT (1U)  /*!< number of pseudoport */
#define NETC_ETHSWT_NUMBER_OF_PORTS       3  /*!< number of ports */
#define NETC_ETHSWT_NUMBER_OF_MAC_PORTS   (2U)  /*!< number of mac ports*/
#define NETC_ETHSWT_NUMBER_OF_VID_PER_PORT (255U)   /*!< 3 number of vid per port */

#define NETC_ETHSWT_IP_FDB_KEYE_DATA_ITEMS                 (3U)      /*!< 3 uint32 items of FDB table KEYE DATA Format */
#define NETC_ETHSWT_IP_FDB_SEARCH_CRITERIA_DATA_ITEMS      (8U)      /*!< 8 uint32 items of FDB table SEARCH CRITERIA Format */

#define NETC_ETHSWT_TABLE_CFGEDATA_ITEMS                   (4U)      /*!< 4 uint32 items of CFGE_DATA Format for Tables */

#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN      (53U)      /*!< 53 uint32 items of Ingress Port Filter Table KEYE_DATA Format */

#define NETC_ETHSWT_NUMBER_OF_PROFILES (2U)
#define NETC_ETHSWT_NUMBER_OF_PCP_DEI (16U)
#define NETC_ETHSWT_NUMBER_OF_PCP     (8U)
#define NETC_ETHSWT_NUMBER_OF_IPV     (8U)
#define NETC_ETHSWT_NUMBER_OF_DR      (4U)

#define NETC_ETHSWT_EFMEID_FOR_MIRRORING                (0U)        /* Default egress frame modification entry id for mirroring */
#define NETC_ETHSWT_EFM_LEN_CHANGE_FOR_MIRRORING        (4U)        /* EFM_LEN_CHANGE value for double tagging when modifying mirrored egress frames */
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*!
 * @brief Ingress congestion management priority. Used for congestion management.
 */
typedef enum
{
    NETC_ETHSWT_IP_ICM_LOW_PRIORITY  = 0U,    /*!< ICM low priority */
    NETC_ETHSWT_IP_ICM_HIGH_PRIORITY = 1U     /*!< ICM high priority */
} Netc_EthSwt_Ip_ICMType;

/*!
 * @brief Callback function invoked when a general event is encountered
 */
typedef void (*Netc_EthSwt_Ip_CallbackType)(uint8 Instance);

/*!
 * @brief Callback function invoked when a channel event is encountered
 */
typedef void (*Netc_EthSwt_Ip_ChCallbackType)(uint8 Instance, uint8 Channel);

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Query action enum types for tables in Switch.
 */
typedef enum {
    NETC_ETHSWT_TABLES_FULL_QUERY = 0x0U,               /*!< Full Query */
    NETC_ETHSWT_TABLES_ENTRY_ID_QUERY = 0x1U            /*!< Entry_Id query only */
} Netc_EthSwt_Ip_TablesQueryActionType;

/*!
 * @brief defines FDB entries.
 */
typedef struct
{
    uint8 MacAddr[6];                                   /*!< MAC Address */
    uint16 FID;                                         /*!< Filtering ID */
    uint32 SwitchPortEgressBitMask;                     /*!< Port Bitmap */
    uint32 ET_EID;                                      /*!< Egress Treatment Table Entry ID */
    uint8 CutThroughDisable;                            /*!< CTD */
    uint8 OverridETEID;                                 /*!< OETEID */
    uint8 EgressPort;                                   /*!< EPORT */
    boolean IngressMirroringEnable;                     /*!< IMIRE */
    boolean DynamicEntry;                               /*!< 0b = Static entry, 1b = Dynamic entry */
    boolean TimeStampCapture;                           /*!< TIMECAPE */
} Netc_EthSwt_Ip_FdbEntryDataType;

/*!
 * @brief defines Vlan Filter entries.
 */
typedef struct
{
    uint32 PortMembershipBitmap;                        /*!< Port Membership Bitmap */
    uint32 VlanID;                                      /*!< Vlan ID */
    uint16 FID;                                         /*!< Filtering ID */
    uint32 EgressTreatmentApplicabilityPortBitmap;      /*!< Egress Treatment Applicability Port Bitmap */
    uint32 BaseEgressTreatmentEntryID;                  /*!< Base Egress Treatment Entry ID */
    uint8 SpanningTreeGroupMemberId;                    /*!< STG_ID */
    uint8 MacForwardingOptions;                         /*!< MFO */
    uint8 MacLearningOptions;                           /*!< MLO */
    boolean IpMulticastFloodingEnable;                  /*!< IP Multicast Flooding Enable */
    boolean IpMulticastFilteringEnable;                 /*!< IP Multicast Filtering Enable */
} Netc_EthSwt_Ip_VlanFilterEntryDataType;

/******************************************************************************
* Definitions
*****************************************************************************/
#define NETC_ETHSWT_IP_FDB_TABLE_ID                     (15U)    /*!< FDB table id */
#define NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID             (18U)    /*!< Vlan filter table id */
#define NETC_ETHSWT_IP_EGRESS_COUNT_TABLE_ID            (39U)    /*!< Egress Count table id */
#define NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID        (33U)    /*!< Egress Treatment table id */
#define NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID        (40U)    /*!< Frame Modification table id */
#define NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID     (13U)    /*!< Ingress Port Filter table id */
#define NETC_ETHSWT_IP_TIME_GATE_SCHEDULING_TABLE_ID    (5U)     /*!< Ingress Port Filter table id */

#define NETC_ETHSWT_IP_BD_ENTRY_EXIST              (1U)     /*!< BD entry exist */
#define NETC_ETHSWT_IP_BD_ENTRY_NOT_EXIST          (0U)     /*!< BD entry not exist*/

#define NETC_ETHSWT_IP_BD_NULL_ENTRY_ID            (0xFFFFFFFFUL)       /*!< BD null entry */

/*!
 * @brief defines CBDR status type.
 */
typedef uint32 Netc_EthSwt_Ip_CBDRStatusType;
#define NETC_ETHSWT_CBDRSTATUS_SUCCES                                           (0x0UL)     /*!< cbdr status success */
#define NETC_ETHSWT_CBDRSTATUS_INDEX_ERROR                                      (0x1UL)     /*!< index of ring should be 0 or 1 */
#define NETC_ETHSWT_CBDRSTATUS_RINGFULL                                         (0x2UL)     /*!< Ring is full */
#define NETC_ETHSWT_CBDRSTATUS_RR_ERROR                                         (0x3UL)     /*!< The hardware does not consume the command, or the operation has not finished by hardware. */
#define NETC_ETHSWT_CBDRSTATUS_NUMMATCHED_ERROR                                 (0x4UL)     /*!< The NUM_MATCHED field should be 1 when the entry exists for any commands */
#define NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR                               (0x5UL)     /*!< Access_method should be 0, 1, or 2, or the command is not supported by this access method */
#define NETC_ETHSWT_CBDRSTATUS_INVALID_TABLE_ID                                 (0x080UL)   /*!< Invalid table ID */
#define NETC_ETHSWT_CBDRSTATUS_NOT_SUPPORTED_ACCESS_METHOD                      (0x081UL)   /*!< Access method specified is not supported */
#define NETC_ETHSWT_CBDRSTATUS_TABLE_INDEX_OUTOFRANGE                           (0x082UL)   /*!< Table index out of range */
#define NETC_ETHSWT_CBDRSTATUS_BUFFER_NOT_SUFFICIENT                            (0x083UL)   /*!< Request data buffer size or response data buffer size is not sufficient */
#define NETC_ETHSWT_CBDRSTATUS_INVALID_CMD                                      (0x084UL)   /*!< Invalid command */
#define NETC_ETHSWT_CBDRSTATUS_REQUEST_DATA_BUFFER_ERROR                        (0x085UL)   /*!< Request Data buffer error */
#define NETC_ETHSWT_CBDRSTATUS_ECC_OR_PARITY_ERROR                              (0x086UL)   /*!< Multi-bit ECC or parity error observed during command processing */
#define NETC_ETHSWT_CBDRSTATUS_EXCEEDED_HASH_ENTRY_LIMIT                        (0x087UL)   /*!< Exceeded hash entry limit */
#define NETC_ETHSWT_CBDRSTATUS_EXCEEDED_MAXIMUM_HASH_COLLISION_CHAIN_LIMIT      (0x088UL)   /*!< Exceeded maximum hash collision chain limit */
#define NETC_ETHSWT_CBDRSTATUS_INVALID_ENTRY_ID                                 (0x089UL)   /*!< Invalid ENTRY_ID for HW Managed tables (hash, TCAM) */
#define NETC_ETHSWT_CBDRSTATUS_SEARCH_CMD_FILLED_THE_RESPONSE_DATA_BUFFER       (0x08AUL)   /*!< Search command filled the response data buffer before completing the command */
#define NETC_ETHSWT_CBDRSTATUS_CMD_FOR_INDEX_TABLE_BEFORE_OSR                   (0x08BUL)   /*!< Command for index table before OSR[ITM_STATE]=0 */
#define NETC_ETHSWT_CBDRSTATUS_INVALID_QUERRY_ACTION                            (0x08CUL)   /*!< Query action specifed is invalid */
#define NETC_ETHSWT_CBDRSTATUS_INVALID_TABLE_ACCESS_PRIVILEGE                   (0x08DUL)   /*!< Invalid table access privilege */
#define NETC_ETHSWT_CBDRSTATUS_SYSTEM_BUS_READ_ERROR                            (0x08EUL)   /*!< System Bus Read Error encountered while processing the command. */
#define NETC_ETHSWT_CBDRSTATUS_SYSTEM_BUS_WRITE_ERROR                           (0x08FUL)   /*!< System Bus Write Error encountered while processing the command. */
#define NETC_ETHSWT_CBDRSTATUS_CLIENT_FAULT                                     (0x090UL)   /*!< Client encountered a fault while processing the command. */
#define NETC_ETHSWT_CBDRSTATUS_RESERVED_ERROR                                   (0x091UL)   /*!< 0x091 to 0x0FF = reserved */
#define NETC_ETHSWT_CBDRSTATUS_TABLE_SPECIFIC_ERROR                             (0x100UL)   /*!< 0x100 to 0xFFF = Table specific error codes */
#define NETC_ETHSWT_CBDRSTATUS_UPTATE_EXISTING_ADMIN_GATE_CONTROL               (0x0D1UL)   /* Update action attempted on an existing admin gate control. An existing admin gate control list cannot be modified, Delete admin gate control list first before creating a new admin list. (Use update action with ADMIN_CONTROL_LIST_LENGTH =0 to perform delete). */
#define NETC_ETHSWT_CBDRSTATUS_UPDATE_ACTION_EXCEED_MAX_GCL_LEN                 (0x0D2UL)   /* Update action attempted exceeds TGSTCAPR[MAX_GCL_LEN]. */
#define NETC_ETHSWT_CBDRSTATUS_UPDATE_ACTION_EXCEED_NUM_WORDS                   (0x0D3UL)   /* Update action attempted exceeds TGSTCAPR[NUM_WORDS]. */
#define NETC_ETHSWT_CBDRSTATUS_INSUFFICIENT_RESOURCES                           (0x0D4UL)   /* Insufficient resources to perform the requested operation (not enough free time gate list entries) */
#define NETC_ETHSWT_CBDRSTATUS_TRANSMITTING_TIME_NOT_SUFFICIENT                 (0x0D5UL)   /* Update action attempted with ADMIN_CYCLE_TIME, ADMIN_TIME_INTERVAL_GE_i or truncated ADMIN_TIME_INTERVAL_GE_n due ADMIN_CYCLE_TIME specified is not sufficient to transmit 64 byte of frame data + header overhead. Where header overhead = PTXSDUOR[PTXSDUOR] + PTXSDUOR[PPDU_BCO]. */
#define NETC_ETHSWT_CBDRSTATUS_ADMIN_BASE_TIME_IS_MORE_THAN_1S                  (0x0D6UL)   /* Update action attempted with ADMIN_BASE_TIME specified is more than one second in the past from tcs advance time. */
#define NETC_ETHSWT_CBDRSTATUS_ADMIN_CYCLE_TIME_OVERFLOW                        (0x0D7UL)   /* Update action attempted with ADMIN_CYCLE_TIME + ADMIN_CYCLE_TIME_EXT is greater than 2^32-1. */
#define NETC_ETHSWT_CBDRSTATUS_RETRY_QUERY                                      (0x0D8UL)   /* Query action issued when config change occurred. Retry query. */
#define NETC_ETHSWT_CBDRSTATUS_INVALID_ADMIN_HR_CB_GE                           (0x0D9UL)   /* Update action attempted with ADMIN_HR_CB_GE_i set to an invalid value. */

/*!
 * @brief defines access method type.
 */
typedef enum {
    NETC_ETHSWT_ENTRY_ID_MATCH = 0x0U,                  /*!< if entry id match */
    NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH,          /*!< if exact match key element match */
    NETC_ETHSWT_SEARCH_METHOD,                          /*!< search method */
    NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH         /*!< if ternary match key element */
} Netc_EthSwt_Ip_AccessMethodType;

/*!
 * @brief defines commands type.
 */
typedef enum {
    NETC_ETHSWT_DELETE_CMD = 0x1U,                                  /*!< delete command */
    NETC_ETHSWT_UPDATE_CMD = 0x2U,                                  /*!< update command */
    NETC_ETHSWT_QUERY_CMD = 0x4U,                                   /*!< query command*/
    NETC_ETHSWT_QUERY_FOLLOWEDBY_DELETE_CMD = 0x5U,                 /*!< query followed by delete command */
    NETC_ETHSWT_QUERY_FOLLOWEDBY_UPDATE_CMD = 0x6U,                 /*!< query followed by update command */
    NETC_ETHSWT_ADD_CMD = 0x8U,                                     /*!< add a command */
    NETC_ETHSWT_ADD_OR_UPDATE_CMD = 0xAU,                           /*!< add or update a command */
    NETC_ETHSWT_ADD_FOLLOWEDBY_QUERY_CMD = 0xCU,                    /*!< add followed by query command */
    NETC_ETHSWT_ADD_FOLLOWEDBY_QUERY_FOLLOWEDBY_UPDATE_CMD = 0xEU   /*!< add followed by query followed by update command */
} Netc_EthSwt_Ip_CommandsType;

/*!
 * @brief CMBDR requeste length field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_REQUEST_LENGTH_SHIFT               (20U)
/*!
 * @brief CMBDR requeste length field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_REQUEST_LENGTH_MASK                (0xFFF00000UL)
/*!
 * @brief CMBDR requeste lengtht.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_REQUEST_LENGTH(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_REQUEST_LENGTH_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_REQUEST_LENGTH_MASK)

/*!
 * @brief CMBDR response length field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_RESPONSE_LENGTH_SHIFT               (0U)
/*!
 * @brief CMBDR response length field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_RESPONSE_LENGTH_MASK                (0x000FFFFFUL)
/*!
 * @brief CMBDR response length.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_RESPONSE_LENGTH(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_RESPONSE_LENGTH_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_RESPONSE_LENGTH_MASK)

/** @brief CMD field */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_SHIFT              (0U)
/** @brief CMD field mask */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_MASK               (0x0000000FUL)
/** @brief CMD field set */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_MASK)

/*!
 * @brief CMBDR request config access method field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_SHIFT    (12U)
/*!
 * @brief CMBDR request config access method field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_MASK     (0x00003000UL)
/*!
 * @brief CMBDR request config field access method.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD(x)       (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_MASK)

/*!
 * @brief CMBDR request config field table id.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_SHIFT         (16U)
/*!
 * @brief CMBDR request config field table id mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_MASK          (0x00FF0000UL)
/*!
 * @brief CMBDR request config table id.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_MASK)

/*!
 * @brief CMBDR request version field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_SHIFT          (24U)
/*!
 * @brief CMBDR request version field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_MASK           (0x3F000000UL)
/*!
 * @brief CMBDR request version.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_MASK)

/*!
 * @brief CMBDR request config field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_SHIFT              (30U)
/*!
 * @brief CMBDR request config field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_MASK               (0x4F000000UL)
/*!
 * @brief CMBDR request config.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_MASK)

/*!
 * @brief CMBDR request RR field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_SHIFT                (31U)
/*!
 * @brief CMBDR request RR field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_MASK                 (0x80000000UL)
/*!
 * @brief CMBDR request RR.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_RR(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_MASK)

/*!
 * @brief CMBDR request NPF field.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_NPF_FIELD_SHIFT                      (15U)
/*!
 * @brief CMBDR request NPF field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_NPF_FIELD_MASK                       (0x00008000UL)
/*!
 * @brief CMBDR request NPF.
 */
#define NETC_ETHSWT_IP_CMDBD_REQFMT_NPF_FIELD(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_CMDBD_REQFMT_NPF_FIELD_SHIFT)) & NETC_ETHSWT_IP_CMDBD_REQFMT_NPF_FIELD_MASK)

/*!
 * @brief NTMP request and response message header format for buffer descriptors of command rings.
 */
typedef struct {
    uint32 MessageHeaderDataField[8U];                 /*!< used for both request and response message header data format */
} Netc_EthSwt_Ip_NTMPMessageHeaderFormatType;

/*!
 * @brief NTMP request message header format index enum for buffer descriptors of command rings.
 */
typedef enum {
    NETC_ETHSWT_IP_REQHEADER_ADDR_L = 0x0U,            /*!< a 16-byte aligned low part of memory address for a table, offset: 0x0 */
    NETC_ETHSWT_IP_REQHEADER_ADDR_H = 0x1U,            /*!< a 16-byte aligned high part of memory address for a table, offset: 0x1 */
    NETC_ETHSWT_IP_REQHEADER_LENGTHFIELD = 0x2U,       /*!< request and response buffer length in Request Header, offset: 0x2 */
    NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD = 0x3U,       /*!< config field includes Table id, access method, command etc. in Request Header, offset: 0x3 */
    NETC_ETHSWT_IP_REQHEADER_NPFFIELD = 0x7U           /*!< NPF field in Request Header, offsext: 0x7 */
} Netc_EthSwt_Ip_NTMPReqHeaderFormatIndexType;

#define NETC_ETHSWT_IP_RSPHEADER_STATUS_FIELD_INDEX     (0x3U)  /*!< status field includes RR bit, ERROR field and NUM_MATCHED field in Response Header Format */

/*!
 * @brief NTMP request message header format index enum for buffer descriptors of command rings.
 */
typedef struct {
    uint16 ReqBuffLength;                               /*!< Table Request data buffer length field of NTMP Request Message Header Data Format */
    uint16 RspBuffLength;                               /*!< Table Response data buffer length field of NTMP Request Message Header Data Format */
    uint8 CmdCompletionInt;                             /*!< CCI (Command Completion Interrupt) in config field of Request Message Header Data Format */
    uint8 Version;                                      /*!< Protocol Version in config field of Request Message Header Data Format */
    uint8 TableId;                                      /*!< TABLE_ID in config field of Request Message Header Data Format */
    Netc_EthSwt_Ip_AccessMethodType AccessMethod;       /*!< ACCESS_METHOD in config field of Request Message Header Data Format */
    Netc_EthSwt_Ip_CommandsType Cmd;                    /*!< COMMAND in config field of Request Message Header Data Format */
} NetcEthSwt_Ip_ReqHeaderTableOperationDataType;

/*!
 * @brief buffer descriptors of command rings.
 */
typedef struct {
    Netc_EthSwt_Ip_NTMPMessageHeaderFormatType  *CmdBDAddr;      /*!< Address where command buffer descriptor will be saved. The address must be 128 byte aligned. */
    uint8 lengthCBDR;      /*!< the length of command ring. */
} Netc_EthSwt_Ip_CmdBDType;
/* ---bits field for NTMP request message--- */

/* +++bits field for NTMP response message+++ */
/*!
 * @brief CMBDR RR status field.
 */
#define NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_SHIFT             (31U)
/*!
 * @brief CMBDR RR status field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_MASK              (0x80000000UL)

/*!
 * @brief CMBDR error status field.
 */
#define NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_SHIFT          (16U)
/*!
 * @brief CMBDR error status field mask.
 */
#define NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_MASK           (0x0FFF0000UL)

/*!
 * @brief CMBDR status field num matched.
 */
#define NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_SHIFT     (0U)
/*!
 * @brief CMBDR status field num matched mask.
 */
#define NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_MASK      (0x0000FFFFUL)
/* ---bits field for NTMP response message--- */

/* +++bits field and structure for CFGE_DATA format+++ */
/*!
 * @brief FDB table config port bitmap field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_SHIFT                (0U)
/*!
 * @brief FDB table config port bitmap map mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_MASK                 (0x00FFFFFFUL)
/*!
 * @brief FDB table config port bitmap.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_MASK)

/*!
 * @brief FDB table config port OETEID field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_SHIFT        (0U)
/*!
 * @brief FDB table config port OETEID field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_MASK         (0x00000003UL)
/*!
 * @brief FDB table config port OETEID.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID(x)           (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_MASK)

/*!
 * @brief FDB table config port EPORT field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_SHIFT         (2U)
/*!
 * @brief FDB table config port EPORT field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_MASK          (0x0000007CUL)
/*!
 * @brief FDB table config port EPORT.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_MASK)

/*!
 * @brief FDB table config port IMIRE field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_SHIFT         (7U)
/*!
 * @brief FDB table config port IMIRE field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_MASK          (0x00000080UL)
/*!
 * @brief FDB table config port IMIRE.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_MASK)

/*!
 * @brief FDB table config port CTD field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_SHIFT           (9U)
/*!
 * @brief FDB table config port CTD field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_MASK            (0x00000600UL)
/*!
 * @brief FDB table config port CTD.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_MASK)

/*!
 * @brief FDB table config port DYNAMIC field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_SHIFT       (11U)
/*!
 * @brief FDB table config port DYNAMIC field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_MASK        (0x00000800UL)
/*!
 * @brief FDB table config port DYNAMIC.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(x)          (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_MASK)

/*!
 * @brief FDB table config port TIMECAPE field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_SHIFT      (12U)
/*!
 * @brief FDB table config port TIMECAPE field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_MASK       (0x00001000UL)
/*!
 * @brief FDB table config port TIMECAPE field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE(x)         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_MASK)

/*!
 * @brief FDB Table CFGE_DATA format.
 */
typedef struct {
    uint32 Cfge_PortBitmap;        /*!< FDB table config port bitmap */
    uint32 Cfge_ConfigField;       /*!< FDB table config field */
    uint32 Cfge_EtEid;             /*!< FDB table eid */
} Netc_EthSwt_Ip_FDBTableCFGEDataType;

/*!
 * @brief FDB Table CFGE_DATA format enum type.
 */
typedef enum {
    NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_FIELD = 9U,               /*!< PORT_BITMAP field in FDB Table CFGE_DATA Format */
    NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD = 10U,                   /*!< CONFIG field includes TIMECAPE, DYNAMIC etc in FDB Table CFGE_DATA Format */
    NETC_ETHSWT_IP_FDBTABLE_CFGE_ETEID_FIELD = 11U                     /*!< ET_EID field in FDB Table CFGE_DATA Format */
} Netc_EthSwt_Ip_FDBTableCFGEDataIndexType;
/* +++bits field and structure for CFGE_DATA format+++ */

/* +++bits field for KEYE_DATA format+++ */
/*!
 * @brief FDB table config MACC_ADDR_L field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_L_SHIFT            (0U)
/*!
 * @brief FDB table config MACC_ADDR_L field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_L_MASK             (0xFFFFFFFFUL)
/*!
 * @brief FDB table config MACC_ADDR_L.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_L(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_L_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_L_MASK)

/*!
 * @brief FDB table config MACC_ADDR_H field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_H_SHIFT            (0U)
/*!
 * @brief FDB table config MACC_ADDR_H field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_H_MASK             (0x0000FFFFUL)
/*!
 * @brief FDB table config MACC_ADDR_H.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_H(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_H_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_MAC_ADDR_H_MASK)

/*!
 * @brief FDB table config FID field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_SHIFT                   (0U)
/*!
 * @brief FDB table config FID field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_MASK                    (0x00000FFFUL)
/*!
 * @brief FDB table config FID.
 */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID(x)                      (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_MASK)

/*!
 * @brief FDB Table KEYE_DATA format. Netc_EthSwt_Ip_FDBTableKEYEDataType
 */
typedef struct {
    uint32 MacAddrL;                        /*!< FDB Mac addr L where the most significant byte of the MAC address is stored */
    uint32 MacAddrH;                        /*!< FDB Mac addr H */ /* [notice]: just 16 bits */
    uint32 Fid;                             /*!< FDB Fid */    /* [notice]: just 12 bits */
} Netc_EthSwt_Ip_FDBTableKEYEDataType;
/* ---bits field for KEYE_DATA format--- */

/* +++bits field for SEARCH_CRITERIA format+++ */
/*!
 * @brief FDB table search criteria ACTE_MC field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTEMC_SHIFT           (24U)
/*!
 * @brief FDB table search criteria ACTE_MC field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTEMC_MASK            (0x01000000UL)
/*!
 * @brief FDB table search criteria ACTE_MC.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTEMC(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTEMC_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTEMC_MASK)

/*!
 * @brief FDB table search criteria CFGE_MC field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC_SHIFT           (16U)
/*!
 * @brief FDB table search criteria CFGE_MC field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC_MASK            (0x00070000UL)
/*!
 * @brief FDB table search criteria CFGE_MC.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC_MASK)

/*!
 * @brief FDB table search criteria KEYE_MC field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_KEYEMC_SHIFT           (8U)
/*!
 * @brief FDB table search criteria KEYE_MC field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_KEYEMC_MASK            (0x00000300UL)
/*!
 * @brief FDB table search criteria KEYE_MC.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_KEYEMC(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_KEYEMC_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_KEYEMC_MASK)

/*!
 * @brief FDB table search criteria ACTF_LAG field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG_SHIFT          (7U)
/*!
 * @brief FDB table search criteria ACTF_LAG field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG_MASK           (0x00000080UL)
/*!
 * @brief FDB table search criteria ACTF_LAG.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG_MASK)

/*!
 * @brief FDB table search criteria ACT_CNT field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT_SHIFT           (0U)
/*!
 * @brief FDB table search criteria ACT_CNT field mask.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT_MASK            (0x0000007FUL)
/*!
 * @brief FDB table search criteria ACT_CNT.
 */
#define NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT_MASK)

/*!
 * @brief FDB Table Match Criteria field data type enumeration. Netc_EthSwt_Ip_FDBTableMatchCriteriaDataType
 */
typedef enum {
    NETC_ETHSWT_IP_FDBTABLE_MATCH_ANY_CRITERIA = 0U,                    /*!< 0x0 = Match Any Criteria. */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_ACTE_DATA_FIELD,                      /*!< 0x1 = Exact match with ACTE_DATA. */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_CFGE_DYNAMIC_FIELD,                   /*!< 0x2: Match CFGE_DATA[DYNAMIC] field, will be remapped to 0x1 */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_CFGE_PORTBITMSP_FIELD,                /*!< 0x3: Match CFGE_DATA[PORT_BITMAP] field, will be remapped to 0x2 */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_CFGE_DYNAMIC_AND_PORTBITMAP_FIELD,    /*!< 0x4: Match CFGE_DATA[DYNAMIC & PORT_BITMAP] field, will be remapped to 0x3 */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_KEYE_FID_FIELD,                       /*!< 0x5: Match KEYE_DATA[FID] provided, will be remapped to 0x1 */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_KEYE_MULTICAST_BIT_OF_MACADDR,        /*!< 0x6: Match KEYE_DATA[MAC_ADDR][MULTICAST], will be remapped to 0x2.
                                                                        Where the MAC Multicast bit is least significant bit of the most significant byte of the destination MAC address.
                                                                        KEYE_DATA[MAC_ADDR][MULTICAST] = 0b1, matching entries with multicast mac address
                                                                        KEYE_DATA[MAC_ADDR][MULTICAST] = 0b0, matching entries with unicast mac address */
    NETC_ETHSWT_IP_FDBTABLE_MATCH_KEYE_FID_AND_MULTICAST_BIT_OF_MACADDR /*!< 0x7: Match KEYE_DATA[FID] and KEYE_DATA[MAC_ADDR][MULTICAST], will be remapped to 0x3. */
} Netc_EthSwt_Ip_FDBTableMatchCriteriaDataType;

#define NETC_ETHSWT_IP_FDBTABLE_CFGE_MATCH_CRITERIA_ADJUSTING_FACTOR        (1U)    /*!< for remapping CFGE match criteria flag */
#define NETC_ETHSWT_IP_FDBTABLE_KEYE_MATCH_CRITERIA_ADJUSTING_FACTOR        (4U)    /*!< for remapping KEYE match criteria flag */

/*!
 * @brief Multicast bit of Mac Address field.
 */
#define NETC_ETHSWT_IP_MULTICASTBIT_OF_MAC_ADDRESS_SHIFT            (0U)
/*!
 * @brief Multicast bit of Mac Address field mask.
 */
#define NETC_ETHSWT_IP_MULTICASTBIT_OF_MAC_ADDRESS_MASK             (0x00000001UL)
/*!
 * @brief Multicast bit of Mac Address.
 */
#define NETC_ETHSWT_IP_MULTICASTBIT_OF_MAC_ADDRESS(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_MULTICASTBIT_OF_MAC_ADDRESS_SHIFT)) & NETC_ETHSWT_IP_MULTICASTBIT_OF_MAC_ADDRESS_MASK)

/*!
 * @brief FDB Table CFGE Match Criteria format in SEARCH_CRITERIA. Netc_EthSwt_Ip_FDBTableCFGEMatchDataType
 */
typedef struct {
    uint32 SearchPortBitMap;                                    /*!< Fdb table search port bitmap data */
    boolean SearchDynamicEntry;                                 /*!< Fdb table search dynamic field in CFGE_DATA */
} Netc_EthSwt_Ip_FDBTableCFGEMatchDataType;

/*!
 * @brief FDB Table KEYE Match Criteria format in SEARCH_CRITERIA. Netc_EthSwt_Ip_FDBTableKEYEMatchDataType
 */
typedef struct {
    uint32 SearchFid;                                           /*!< Fdb table search FID data */
    boolean SearchMulticastMacAddr;                             /*!< TRUE: search Multicast Mac Address Entries
                                                                    FALSE: search Unicast Mac Address Entries */
} Netc_EthSwt_Ip_FDBTableKEYEMatchDataType;

/*!
 * @brief FDB Table ACTE_DATA (Activity Element Data) format. Netc_EthSwt_Ip_FDBTableACTEDataType
 */
typedef struct {
    uint8 ActivityCounter;                                      /*!< Activity Counter data in ACTE_DATA format */
    boolean ActivityFlag;                                       /*!< Activity Flag data in ACTE_DATA format */
} Netc_EthSwt_Ip_FDBTableACTEDataType;

/*!
 * @brief FDB Table SEARCH_CRITERIA format. Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType
 */
typedef struct {
    uint32 SearchResumeEntryId;                                                 /*!< Fdb table search criteria resume entry id */
    Netc_EthSwt_Ip_FDBTableMatchCriteriaDataType SearchMatchCriteria;           /*!< Fdb table search Match Criteria */
    Netc_EthSwt_Ip_FDBTableACTEDataType SearchActeData;                         /*!< Fdb table search ACTE data */
    Netc_EthSwt_Ip_FDBTableCFGEMatchDataType SearchCfgeData;                    /*!< Fdb table search CFGE data */
    Netc_EthSwt_Ip_FDBTableKEYEMatchDataType SearchKeyeData;                    /*!< Fdb table search KEYE data */
} Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType;

/*!
 * @brief FDB Table SEARCH_CRITERIA format enum type.
 * [notes:] the enum starts from 1U because it is the second item in FDB table request data buffer format
 */
typedef enum {
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_RESUMEENTRYID = 1U,            /*!< RESUME_ENTRY_ID field in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_L,                  /*!< Low part of Mac Address Field of KEYE DATA in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_H,                  /*!< High part of Mac Address Field of KEYE DATA in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_FID,                           /*!< FID Field of KEYE DATA in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_PORTBITMAP,                    /*!< Port_Bitmap Field of CFGE DATA in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGECONFIG,                    /*!< Config Field of CFGE DATA in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ETEID,                         /*!< ET_EID Field of CFGE DATA in Search Criteria Format */
    NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA                  /*!< Match Criteria Field includes ACTE_MC, CFGE_MC etc in Search Criteria Format */
} Netc_EthSwt_Ip_FDBTableSearchCriteriaDataIndexType;
/* ---bits field for SEARCH_CRITERIA format--- */

/* +++bits field and structure for FDB Table Request Data Buffer Format+++ */
/*!
 * @brief Switch Tables Request Data Buffer CFGEU field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU_SHIFT         (0U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU_MASK          (0x00000001UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU_MASK)
/*!
 * @brief FDB table Request Data Buffer ACTEU field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_SHIFT            (1U)
#define NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_MASK             (0x00000002UL)
#define NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_MASK)
/*!
 * @brief Switch Tables Request Data Buffer DEBUG_OPTIONS field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS_SHIFT (16U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS_MASK  (0x00FF0000UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(x)    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS_MASK)
/*!
 * @brief Switch Tables Request Data Buffer QUERY_ACTIONS field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_SHIFT (24U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_MASK  (0x0F000000UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(x)    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_MASK)

/*!
 * @brief Switch Tables Request Data Buffer TABLE_VERSION field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_SHIFT (28U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_MASK  (0xF0000000UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(x)   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_MASK)

/*!
 * @brief Request and Response Data Buffer Format of Tables supported by Switch.
 */
typedef struct {
    uint32 TableDataField[NETC_ETHSWT_IP_TABLEDATA_BUFFER_LENGTH];  /*!< the request and response data buffer share the same memory */
} Netc_EthSwt_Ip_SwitchTableDataType;


/*!
 * @brief FDB Table response data type enumeration. Netc_EthSwt_Ip_FDBTable_ResponsDataIndexType
 */
typedef enum {
    NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS = 0x0U,     /*!< Status Field In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_ENTRYID,           /*!< Entry_ID Field In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_L,      /*!< Low part of Mac Address Field of KEYE DATA In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_H,      /*!< High part of Mac Address Field of KEYE DATA  In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_FID,               /*!< FID Field of KEYE DATA In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_PORTBITMAP,        /*!< Port_Bitmap Field of CFGE DATA In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_CFGECONFIG,        /*!< Config Field of CFGE DATA In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_ETEID,             /*!< ET_EID Field of CFGE DATA In FDB Table Response Data Buffer */
    NETC_ETHSWT_FDBTABLE_RSPDATA_ACTEDATA           /*!< ACTE Data Field In FDB Table Response Data Buffer */
} Netc_EthSwt_Ip_FDBTable_ResponsDataIndexType;
/* ---bits field and structure for FDB Table Request Data Buffer Format--- */

/* index of Egress Count Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD                        (0U)        /*!< first uint32 item of Egress Count Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD                      (1U)        /*!< second uint32 item of Egress Count Table Request Data Buffer Format */

/*!
 * @brief Data fields in Egress Count Table Request Data Buffer Format.
 */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT            (0U)
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK             (0x00000001UL)
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief Egress Count Table update actions data type enumeration. Netc_EthSwt_Ip_ECTableUpdateActionsDataType
 */
typedef enum {
    NETC_ETHSWT_EGRESSCOUNTTABLE_NO_UPDATE_STATISTICS_ELEMENT = 0U,                 /*!< No update performed to the Statistics Element  */
    NETC_ETHSWT_EGRESSCOUNTTABLE_RESET_STATISTICS_ELEMENT                           /*!< All counters within the Statistics Element are reset  */
} Netc_EthSwt_Ip_ECTableUpdateActionsDataType;

/*!
 * @brief Statistics data of Egress Count Table in response data buffer. Netc_EthSwt_Ip_ECTableStatisticsDataType
 */
typedef struct {
    uint64 EnqueuedFrmCnt;       /*!< Enqueued Frame Count data, the number of frames enqueued on egress class queues */
    uint64 RejectedFrmCnt;       /*!< Rejected Frame Count data, he number of frames rejected in egress class queues, due to tail drop */
} Netc_EthSwt_Ip_ECTableStatisticsDataType;

/*!
 * @brief Egress Count Table response data type enumeration. Netc_EthSwt_Ip_EgressCountTable_RspDataIndexType
 */
typedef enum {
    NETC_ETHSWT_ECTABLE_RSPDATA_ENTRYID = 0x0U,     /*!< Entry Id Field In Egress Count Table Response Data Buffer */
    NETC_ETHSWT_ECTABLE_RSPDATA_ENQFRMCNT_L,        /*!< Lower 32bits of Enqueued Frame Count Field In Egress Count Table Response Data Buffer */
    NETC_ETHSWT_ECTABLE_RSPDATA_ENQFRMCNT_H,        /*!< Higher 32bits of Enqueued Frame Count Field In Egress Count Table Response Data Buffer */
    NETC_ETHSWT_ECTABLE_RSPDATA_REJFRMCNT_L,        /*!< Lower 32bits of Rejected Frame Count Field In Egress Count Table Response Data Buffer */
    NETC_ETHSWT_ECTABLE_RSPDATA_REJFRMCNT_H         /*!< Higher 32bits of Rejected Frame Count Field In Egress Count Table Response Data Buffer */
} Netc_EthSwt_Ip_EgressCountTable_RspDataIndexType;

/*!
 * @brief EFM_DATA_LEN field in Egress Treatment Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN_SHIFT     (16U)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN_MASK      (0x07FF0000UL)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN(x)        (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN_SHIFT)) & NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN_MASK)

/*!
 * @brief EFM_LEN_CHANGE field in Egress Treatment Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE_SHIFT   (9U)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE_MASK    (0x0000FE00UL)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE(x)      (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE_SHIFT)) & NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE_MASK)

/*!
 * @brief ECA field in Egress Treatment Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION_SHIFT         (6U)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION_MASK          (0x000001C0UL)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION_SHIFT)) & NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION_MASK)

/*!
 * @brief ESQA field in Egress Treatment Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION_SHIFT        (4U)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION_MASK         (0x00000030UL)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION(x)           (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION_SHIFT)) & NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION_MASK)

/*!
 * @brief EFM_MODE field in Egress Treatment Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE_SHIFT         (0U)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE_MASK          (0x00000003UL)
#define NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE_SHIFT)) & NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE_MASK)

/*!
 * @brief Egress Treatment Table egress counter action data type definitions.
 */
typedef uint32 Netc_EthSwt_Ip_EgressTreatmentTableCounterActionType;
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_NOT_INCREMENT_EGRESSFRMCOUNTER         (0x0U)   /*!< Do not increment egress frame counter  */
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_INCREMENT_EGRESSFRMCOUNTER             (0x1U)   /*!< Increment egress frame counter  */

/*!
 * @brief Egress Treatment Table egress sequence actions data type definitions.
 */
typedef uint32 Netc_EthSwt_Ip_EgressTreatmentTableSequenceActionType;
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_NO_SEQUENCE_ACTION_REQUIRED            (0x0U)   /*!< No Sequence Action required  */
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_SEQUENCE_RECOVERY_ACTION               (0x2U)   /*!< Sequence Recovery action  */

/*!
 * @brief Egress Treatment Table egress frame modification mode data type definitions.
 */
typedef uint32 Netc_EthSwt_Ip_EgressTreatmentTableFrmModificationModeType;
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_DEFAULT_FRM_MODIFICATION_MODE          (0x0U)    /*!< Normal/Default mode  */
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_L2ACTION_FRM_MODIFICATION_MODE         (0x1U)    /*!< When EFM_EID[L2_ACT]=1b  */
#define NETC_ETHSWT_EGRESSTREATMENTTABLE_PAYLOADACTION_FRM_MODIFICATION_MODE    (0x2U)    /*!< When EFM_EID[PLD_ACT]=001b  */

/*!
 * @brief Egress Treatment Table response data type enumeration. Netc_EthSwt_Ip_EgressTreatmentTable_RspDataIndexType
 */
typedef enum {
    NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_ENTRYID_FIELD = 0U,                  /*!< first uint32 item of Egress Treatment Table Response Data Buffer Format */
    NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA0,                           /*!< first item of CFGEDATA but second item of Egress Treatment Table Response Data Buffer Format */
    NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA1,                           /*!< second item of CFGEDATA but third item of Egress Treatment Table Response Data Buffer Format */
    NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA2,                           /*!< third item of CFGEDATA but forth item of Egress Treatment Table Response Data Buffer Format */
    NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA3                            /*!< forth item of CFGEDATA but fifth item of Egress Treatment Table Response Data Buffer Format */
} Netc_EthSwt_Ip_EgressTreatmentTable_RspDataIndexType;

/*!
 * @brief defines Egress Treatment Table entries.
 */
typedef struct
{
    uint32 EgressTreatmentEntryID;                                                  /*!< Egress Treatment Table Entry ID */
    uint32 EgressSeqActionsTargetEID;                                               /*!< Egress Sequence Actions Target Entry ID */
    uint32 EgressCountTableEID;                                                     /*!< Egress Count Table Entry ID */
    uint32 EgressFrmModificationEID;                                                /*!< Egress Frame Modification Entry ID */
    uint16 EgressFrmModificationDataLength;                                         /*!< Egress Frame Modification Data Length */
    uint8 EgressFrmModificationLengthChange;                                        /*!< Egress Frame Modification Length Change */
    Netc_EthSwt_Ip_EgressTreatmentTableCounterActionType EgressCounterAction;       /*!< Egress Counter Action */
    Netc_EthSwt_Ip_EgressTreatmentTableSequenceActionType EgressSequenceAction;     /*!< Egress Sequence Actions */
    Netc_EthSwt_Ip_EgressTreatmentTableFrmModificationModeType EgressFrmModificationMode;   /*!< Egress Frame Modification Mode */
} Netc_EthSwt_Ip_EgressTreatmentEntryDataType;

/*!
 * @brief DEST_MAC_ADDR (most significant portion) field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_SHIFT              (16U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_MASK               (0xFFFF0000UL)
#define NENETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_MASK)

/*!
 * @brief SMAC_PORT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT_SHIFT   (11U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT_MASK    (0x0000F800UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT(x)      (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT_MASK)

/*!
 * @brief SQT_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_SHIFT      (8U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_MASK       (0x00000700UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION(x)         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_MASK)

/*!
 * @brief OUTER_VID_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_SHIFT         (6U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_MASK          (0x000000C0UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_MASK)

/*!
 * @brief VLAN_HDR_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_SHIFT       (4U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_MASK        (0x00000030UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION(x)          (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_MASK)

/*!
 * @brief MAC_HDR_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_SHIFT        (1U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_MASK         (0x0000000EUL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION(x)           (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_MASK)

/*!
 * @brief L2_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_SHIFT            (0U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_MASK             (0x00000001UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_MASK)

/*!
 * @brief PLD_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_SHIFT           (24U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_MASK            (0x07000000UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_MASK)

/*!
 * @brief OUTER_DEI_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_SHIFT          (22U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_MASK           (0x00C00000UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_MASK)

/*!
 * @brief OUTER_PCP_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_SHIFT          (19U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_MASK           (0x00380000UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_MASK)

/*!
 * @brief OUTER_TPID_ACT field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_SHIFT         (16U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_MASK          (0x00070000UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_MASK)

/*!
 * @brief OUTER_VLAN_DEI field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_SHIFT            (15U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_MASK             (0x00008000UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_MASK)

/*!
 * @brief OUTER_VLAN_PCP field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_SHIFT             (12U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_MASK              (0x00007000UL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_MASK)

/*!
 * @brief OUTER_VLAN_VID field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_SHIFT              (0U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_MASK               (0x00000FFFUL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_MASK)

/*!
 * @brief PLD_OFFSET field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET_SHIFT               (0U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET_MASK                (0x000000FFUL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET_MASK)

/*!
 * @brief FMD_BYTES field in Frame Modification Table CFGE_DATA format.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES_SHIFT       (0U)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES_MASK        (0x0000FFFFUL)
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES(x)          (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES_MASK)

/*!
 * @brief Frame Modification Table response data type enumeration. Netc_EthSwt_Ip_FrmModificationTable_RspDataIndexType
 */
typedef enum {
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_ENTRYID_FIELD = 0U,                  /*!< first uint32 item of Frame modification Table Response Data Buffer Format */
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA0,                           /*!< first item of CFGEDATA but second item of Frame Modification Table Response Data Buffer Format */
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA1,                           /*!< second item of CFGEDATA but third item of Frame Modification Table Response Data Buffer Format */
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA2,                           /*!< third item of CFGEDATA but forth item of Frame Modification Table Response Data Buffer Format */
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA3,                           /*!< forth item of CFGEDATA but fifth item of Frame Modification Table Response Data Buffer Format */
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA4,                           /*!< fifth item of CFGEDATA but sixth item of Frame Modification Table Response Data Buffer Format */
    NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA5                            /*!< sixth item of CFGEDATA but seventh item of Frame Modification Table Response Data Buffer Format */
} Netc_EthSwt_Ip_FrmModificationTable_RspDataIndexType;

/*!
 * @brief defines Frame Modification Table entries.
 */
typedef struct
{
    uint32 FrmModificationEntryID;                    /*!< Frame Modification Table Entry ID */
    uint32 FrmModificationDataEntryID;                /*!< Frame Modification Data Table Entry ID */
    uint16 FrmModificationDataBytes;                  /*!< Frame Modification Data Bytes */
    uint8 DestMacAddr[6U];                            /*!< Destination Mac Address, big-endian order */
    uint8 SrcMacAddrRegisterPort;                     /*!< Source Mace Address Register Port */
    uint8 SequenceTagAction;                          /*!< Sequence Tag Action */
    uint8 OuterVidActions;                            /*!< Outer VID Actions */
    uint8 L2HeaderVlanActions;                        /*!< Layer 2 VLAN Actions */
    uint8 L2HeaderMacActions;                         /*!< Layer 2 Header Mac Actions */
    uint8 L2Actions;                                  /*!< Layer 2 Actions */
    uint8 PayloadActions;                             /*!< Payload Actions */
    uint8 OuterDeiAction;                             /*!< Outer DEI Action */
    uint8 OuterPcpAction;                             /*!< Outer PCP Action */
    uint8 OuterTpidAction;                            /*!< Outer TPID Action */
    uint8 OuterVlanDei;                               /*!< Outer VLAN DEI */
    uint8 OuterVlanPcp;                               /*!< Outer VLAN PCP */
    uint16 OuterVlanVID;                              /*!< Outer VLAN VID */
    uint8 PayloadOffset;                              /*!< Payload Offset */
} Netc_EthSwt_Ip_FrmModificationEntryDataType;

/*!
 * @brief Ingress Port Filter Table CFGE_DATA format enum type. Netc_EthSwt_Ip_IngressPortFilterTableCFGEDataIndexType
 */
typedef enum {
    NETC_ETHSWT_IP_INGRESSPORTFILTER_CFGE_CONFIG_FIELD = 54U,             /*!< CONFIG field includes IPV, DR, FLTFA etc in Ingress Port Filter Table CFGE_DATA Format */
    NETC_ETHSWT_IP_INGRESSPORTFILTER_CFGE_FLTATGT_FIELD = 55U             /*!< FLTA_TGT (Target For Selected Filter Action) field in Ingress Port Filter Table CFGE_DATA Format */
} Netc_EthSwt_Ip_IngressPortFilterTableCFGEDataIndexType;

/*!
 * @brief Ingress Port Filter table CFGE_DATA config field.
 */
/* IPV field */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV_SHIFT             (0U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV_MASK              (0x0000000FUL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV_MASK)

/* OIPV */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV_SHIFT            (4U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV_MASK             (0x00000010UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV_MASK)

/* DR */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR_SHIFT              (5U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR_MASK               (0x00000060UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR_MASK)

/* ODR */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR_SHIFT             (7U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR_MASK              (0x00000080UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR_MASK)

/* FLTFA */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA_SHIFT            (8U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA_MASK             (0x00000300UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA_MASK)

/* IMIRE */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE_SHIFT            (11U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE_MASK             (0x00000800UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE_MASK)

/* WOLTE */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE_SHIFT            (12U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE_MASK             (0x00001000UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE_MASK)

/* FLTA */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA_SHIFT              (13U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA_MASK               (0x00006000UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA_MASK)

/* RPR */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR_SHIFT               (15U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR_MASK                (0x00018000UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR_MASK)

/* CTD */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD_SHIFT               (17U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD_MASK                (0x00020000UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD_MASK)

/* HR */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR_SHIFT                (18U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR_MASK                 (0x003C0000UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR_MASK)

/* TIMECAP */
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP_SHIFT           (22U)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP_MASK            (0x00400000UL)
#define NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP_MASK)

/*!
 * @brief Ingress Port Filter table KEYE_DATA field.
 */
/* DSCP field */
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP_SHIFT               (0U)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP_MASK                (0x0000003FUL)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP_MASK)

/* DSCP Mask field */
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK_SHIFT           (6U)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK_MASK            (0x00000FC0UL)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK_MASK)

/* SRC_PORT field */
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID_SHIFT             (16U)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID_MASK              (0x001F0000UL)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID_MASK)

/* SRC_PORT Mask field */
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_SHIFT         (21U)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_MASK          (0x03E00000UL)
#define NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_MASK)

/*!
 * @brief Ingress Port Filter table Request Data Buffer STSEU field.
 */
#define NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT    (1U)
#define NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK     (0x00000002UL)
#define NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)       (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief Filter Forwarding Action data type definitions for Ingress Port Filter Table.
 */
typedef uint32 Netc_EthSwt_Ip_CfgeFilterForwardingActionDataType;
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_DISCARDFRAMES     (0x0U)           /*!< discard frames */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_PERMITFRAMES      (0x1U)           /*!< permit frames */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REDIRECTFRAMES    (0x2U)           /*!< Redirect frame to switch management port without any frame modification */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_COPYFRAMES        (0x3U)           /*!< Copy frame to switch management port without any frame modification */

/*!
 * @brief Filter Action data type definitions for Ingress Port Filter Table.
 */
typedef uint32 Netc_EthSwt_Ip_CfgeFilterActionDataType;
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_NOACTION                              (0x0U) /*!< no action */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RATEACTION                            (0x1U) /*!< Rate action with the Rate Policer Entry ID (RP_EID) set to the value configured in the FLTA_TGT field of this entry */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_INGRESSSTREAMIDENTIFICATIONACTION     (0x2U) /*!< Ingress stream identification action where the Ingress Stream Entry ID (IS_EID) is set to the value configured in the FLTA_TGT field of this entry */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_SETTINGL2FILTERINGSIBITMAP            (0x3U) /*!< valid on ENETC side. Setting a pre L2 filtering SI bitmap that will be used by the L2 filtering function to determine the final SI bitmap */

/*!
 * @brief defines Ingress Port Filter Table CFGE_DATA type.
 */
typedef struct
{
    uint32 CfgeTargetForSelectedFilterAction;                                       /*!< FLTA_TGT filed in CFGE_DATA format */
    uint8 CfgeIpv;                                                                  /*!< IPV  (internal priority value) filed in CFGE_DATA format */
    uint8 CfgeDr;                                                                   /*!< DR (drop resilience) field in CFGE_DATA format */
    uint8 CfgeRelativePrecedentResolution;                                          /*!< RPR field in CFGE_DATA format */
    uint8 CfgeHostReason;                                                           /*!< HR field in CFGE_DATA format */
    boolean CfgeOverrideIpv;                                                        /*!< OIPV (override internal priority value)  field in CFGE_DATA format*/
    boolean CfgeOverrideDr;                                                         /*!< ODR (override drop resilience) field in CFGE_DATA format */
    boolean CfgeIngressMirroringEnable;                                             /*!< IMIRE field in CFGE_DATA format */
    boolean CfgeWakeOnLanTriggerEnable;                                             /*!< WOLTE filed in CFGE_DATA format */
    boolean CfgeCutThroughDisable;                                                  /*!< CTD field in CFGE_DATA format */
    boolean CfgeTimestampCaptureEable;                                              /*!< TIMECAPE field in CFGE_DATA format */
    Netc_EthSwt_Ip_CfgeFilterForwardingActionDataType CfgeFilterForwardingAction;   /*!< FLTFA field in CFGE_DATA format */
    Netc_EthSwt_Ip_CfgeFilterActionDataType CfgeFilterAction;                       /*!< FLTA field in CFGE_DATA format */
} Netc_EthSwt_Ip_IngressPortFilterCfgeDataType;

/*!
 * @brief defines Ingress Port Filter Table KEYE_DATA type.
 */
typedef struct
{
    uint16 KeyePrecedence;                                      /*!< Precedence field */
    uint16 keyeFrmAttributeFlags;                               /*!< Frame Attribute Flags field */
    uint16 KeyeFrmAttributeFlagsMask;                           /*!< Frame Attribute Flags Mask field */
    uint8 KeyeDifferentiatedServicesCodePoint;                  /*!< Differentiated Services Code Point field */
    uint8 KeyeDifferentiatedServicesCodePointMask;              /*!< Differentiated Services Code Point Mask field */
    uint8 KeyeSourcePortID;                                     /*!< Source Port ID field */
    uint8 KeyeSourcePortIDMask;                                 /*!< Source Port ID Mask field */
    uint16 KeyeOuterVLANTagControlInformation;                  /*!< Outer VLAN Tag Control Information field */
    uint16 KeyeOuterVLANTagControlInformationMask;              /*!< Outer VLAN Tag Control Information Mask field */
    uint8 KeyeDstMacAddr[6U];                                   /*!< Destination MAC Address field */
    uint8 KeyeDstMacAddrMask[6U];                               /*!< Destination MAC Address Mask field */
    uint8 KeyeSrcMacAddr[6U];                                   /*!< Source MAC Address field */
    uint8 KeyeSrcMacAddrMask[6U];                               /*!< Source MAC Address Mask field */
    uint16 KeyeInnerVLANTagControlInformation;                  /*!< Inner VLAN Tag Control Information field */
    uint16 KeyeInnerVLANTagControlInformationMask;              /*!< Inner VLAN Tag Control Information Mask field */
    uint16 KeyeEtherType;                                       /*!< EtherType field */
    uint16 KeyeEtherTypeMask;                                   /*!< EtherType Mask field */
    uint8 KeyeIPProtocol;                                       /*!< IP Protocol field */
    uint8 KeyeIPProtocolMask;                                   /*!< IP Protocol Mask field */
    uint32 KeyeIPSourceAddress[4U];                             /*!< IP Source Address field */
    uint32 KeyeIPSourceAddressMask[4U];                         /*!< IP Source Address Mask field */
    uint16 KeyeL4SourcePort;                                    /*!< L4 Source Port field */
    uint16 KeyeL4SourcePortMask;                                /*!< L4 Source Port Mask field */
    uint32 KeyeIPDestinationAddress[4U];                        /*!< IP Destination Address field */
    uint32 KeyeIPDestinationAddressMask[4U];                    /*!< IP Destination Address Mask field */
    uint16 KeyeL4DestinationPort;                               /*!< L4 Destination Port field */
    uint16 KeyeL4DestinationPortMask;                           /*!< L4 Destination Port Mask field */
    uint8 KeyePayloadBytes[24U];                                /*!< Payload Bytes field */
    uint8 KeyePayloadBytesMask[24U];                            /*!< Payload Bytes Mask field */
} Netc_EthSwt_Ip_IngressPortFilterKeyeDataType;

/*!
 * @brief defines Ingress Port Filter Table entries.
 */
typedef struct
{
    uint32 IngressPortFilterEntryID;                                            /*!< Ingress Port Filter Table Entry ID */
    Netc_EthSwt_Ip_IngressPortFilterCfgeDataType IngressPortFilterCfgeData;     /*!< Ingress Port Filter Table CFGE_DATA format */
    Netc_EthSwt_Ip_IngressPortFilterKeyeDataType IngressPortFilterkeyeData;     /*!< Ingress Port Filter Table KEYE_DATA format */
    uint64 IngressPortFilterMatchCount;                                         /*!< Ingress Port Filter Table Match Count Data */
} Netc_EthSwt_Ip_IngressPortFilterEntryDataType;

/*!
 * @brief enum type for administrative gate operation type (as per IEEE 802.1Q-2018) field for gate control list entry.
 */
typedef enum {
    ETHSWT_HOST_REQUEST_UNCHANGED,          /*!< 0x0: SetGateStates. HoldRequest is unchanged. */
    ETHSWT_HOST_REQUEST_HOLD,               /*!< 0x1: Set-And-Hold-MAC. HoldRequest is set to value hold (1). */
    ETHSWT_HOST_REQUEST_RELEASE             /*!< 0x2: Set-And-Release-MAC. HoldRequest is set to value release (0). */
} Netc_EthSwt_Ip_AdminGateOperationType;

/*!
 * @brief enum type for Administrative Traffic Class Gate States.
 */
typedef enum {
    ETHSWT_TRAFFIC_CLASS_GATE_CLOSED,       /*!< 0x0: Gate closed. */
    ETHSWT_TRAFFIC_CLASS_GATE_OPEN          /*!< 0x1: Gate open. */
} Netc_EthSwt_Ip_AdminTrafficClassGateStateType;

/*!
 * @brief Time Gate Scheduling Table CFGE_DATA field.
 */
/* Administrative Traffic Class Gate States for Gate Entry */
#define NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_SHIFT          (0U)
#define NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_MASK           (0x000000FFUL)
#define NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_TC_STATES(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_SHIFT)) & NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_MASK)

/* Administrative gate operation type (as per IEEE 802.1Q-2018) field for gate control list entry */
#define NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_HR_CB_SHIFT              (16U)
#define NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_HR_CB_MASK               (0x000F0000UL)
#define NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_HR_CB(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_HR_CB_SHIFT)) & NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_HR_CB_MASK)

/*!
 * @brief defines Gate Entry Admin Control List Data type for Time Gate Scheduling Table.
 */
typedef struct
{
    uint32 AdminTimeInterval;                                           /*!< Administrative Time Interval for Gate Entry */
    uint8 AdminTrafficClassGateStates;                                  /*!< Administrative Traffic Class Gate States for Gate Entry */
    Netc_EthSwt_Ip_AdminGateOperationType AdminGateOperationType;       /*!< Administrative gate operation type (as per IEEE 802.1Q-2018) field for gate control list entry */
} Netc_EthSwt_Ip_GateEntryAdminControlListDataType;

/*!
 * @brief defines Time Gate Scheduling Table entries.
 */
typedef struct
{
    uint32 TimeGateSchedulingTable_EID;                 /*!< Time Gate Scheduling Table Entry ID, which is actually the port index of switch */
    uint64 AdminBaseTime;                               /*!< Administrative Base Time */
    uint32 AdminCycleTime;                              /*!< Administrative Cycle Time */
    uint32 AdminCycleTimeExt;                           /*!< Administrative Cycle Time Extension */
    uint16 AdminControlListLength;                      /*!< Administrative Control List Length */
    Netc_EthSwt_Ip_GateEntryAdminControlListDataType GateEntryAdminControlListData[NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES];
} Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType;

/**
* @brief  MAC learning optoin type enumeration.
* @implements Netc_EthSwt_Ip_MacLearningOptionType_enum
*/
typedef enum {
    ETHSWT_MACLEARNINGOPTION_HWDISABLED               = (uint8)0x1U, /*!< @brief If hardware learning disabled, the switch must not learn new MAC addresses */
    ETHSWT_MACLEARNINGOPTION_HWENABLED                = (uint8)0x2U, /*!< @brief If hardware learning enabled, the switch learns new MAC addresses */
    ETHSWT_MACLEARNINGOPTION_SWSECUREENABLED          = (uint8)0x3U, /*!< @brief If software learning secure enabled, A MAC learning lookup is performed into the FDB table.
                                                                If there is no match, no attempt is made to add a new entry, and the frame is redirect to the switch management port.
                                                                If there is match, and the entry's port number does not match frame ingress port number, the frame is redirected to the switch management port. */
    ETHSWT_MACLEARNINGOPTION_SWUNSECUREENABLED        = (uint8)0x4U, /*!< @brief If software learning unsecure enabled,  A MAC learning lookup is performed into the FDB table.
                                                                If there is no match, no attempt is made to add a new entry, and a copy of the frame is sent to the switch management port.
                                                                If there is match, and the entry's port number does not match frame ingress port number, the frame is copied to the switch management port.*/
    ETHSWT_MACLEARNINGOPTION_DISABLEDWITHSWVALIDATION = (uint8)0x5U  /*!< @brief if Disable MAC learning with SMAC validation. A MAC learning lookup is performed into the FDB table.
                                                                If there is no match or there is a match but the ingress port is not a member of the FDB entry,
                                                                the frame is discarded and counted against the bridge port discard count register (BPDCR) with discard reason BPDCRR0[MACLNFDR]. */
} Netc_EthSwt_Ip_MacLearningOptionType;

typedef enum{
    ETHSWT_NO_FDB_LOOKUP_FLOOD_FRAME                   = (uint8)0x1U, /**< @brief No FDB lookup is performed, the frame is flooded */
    ETHSWT_FDB_LOOKUP_FLOOD_FRAME                      = (uint8)0x2U, /**< @brief FDB lookup is performed, and if there is no match, the frame is flooded. */
    ETHSWT_FDB_LOOKUP_DISCARD_FRAME                    = (uint8)0x3U  /**< @brief FDB lookup is performed, and if there is no match, the frame is discarded */
} Netc_EthSwt_Ip_MacForwardingOptionType;

typedef enum{
    ETHSWT_EXTERNAL_REFERENCE_CLOCK                    = (uint8)0x0U,       /**< @brief external reference clock is selected for 1588 timer */
    ETHSWT_MODULE_REFERENCE_CLOCK                      = (uint8)0x1U,       /**< @brief module reference clock (NETC system clock) is selected for 1588 timer */
    ETHSWT_REFERENCE_CLOCK_DISABLED                    = (uint8)0x2U        /**< @brief No reference clock selected for 1588 timer, means the timer is disabled */
} Netc_EthSwt_Ip_1588ClockSourceOptionType;

/*!
 * @brief Port selection enumeration Netc_EthSwt_Ip_PortSelectionType_Class
 */
typedef enum
{
    NETC_ETHSWT_PORT2 = 2U,    /**< Pseudo port 2 */
    NETC_ETHSWT_PORT1 = 1U,    /**< Switch port 1 */
    NETC_ETHSWT_PORT0 = 0U     /**< Switch port 0 */
} Netc_EthSwt_Ip_PortSelectionType;

/*!
 * @brief XMII mode of port Netc_EthSwt_Ip_XmiiModeType_Enumeration
 */
typedef enum
{
    NETC_ETHSWT_MII_MODE            = 0U,    /**< MII interface mode */
    NETC_ETHSWT_RMII_MODE           = 1U,    /**< RMII interface mode */
    NETC_ETHSWT_RGMII_MODE          = 2U,    /**< RGMII interface mode */
} Netc_EthSwt_Ip_XmiiModeType;

/*!
 * @brief Link duplex.
 * Netc_EthSwt_Ip_PortDuplexType_Class
 */
typedef enum
{
    NETC_ETHSWT_PORT_FULL_DUPLEX = 1,  /**< full duplex mode */
    NETC_ETHSWT_PORT_HALF_DUPLEX  = 0,  /**< half duplex mode */
} Netc_EthSwt_Ip_PortDuplexType;

/*!
 * @brief Link speed.
 * Netc_EthSwt_Ip_PortSpeedType_Class
 */
typedef enum
{
    NETC_ETHSWT_PORT_SPEED_100_MBPS = 1,  /**< 100 Mbps */
    NETC_ETHSWT_PORT_SPEED_10_MBPS  = 0,  /**< 10 Mbps */
} Netc_EthSwt_Ip_PortSpeedType;

/*!
 * @brief Direction selection enumeration Netc_EthSwt_Ip_DirectionType_Class
 */
typedef enum
{
    NETC_ETHSWT_DIRECTION_INGRESS = 1U,    /**< Ingress direction */
    NETC_ETHSWT_DIRECTION_EGRESS  = 0U     /**< Egress direction */
} Netc_EthSwt_Ip_DirectionType;

/*!
 * @brief Mode of the port Netc_EthSwt_Ip_PortModeType_Class
 */
typedef enum
{
    NETC_ETHSWT_PORT_MODE_INGRESS = 4U,  /**< Port is enabled, ingress communication only */
    NETC_ETHSWT_PORT_MODE_EGRESS  = 3U,  /**< Port is enabled, egress communication only */
    NETC_ETHSWT_PORT_MODE_FULL    = 1U,  /**< Port is enabled, ingress and egress communication possible */
    NETC_ETHSWT_PORT_MODE_OFF     = 0U   /**< Port is off, no communication possible */
} Netc_EthSwt_Ip_PortModeType;

/*!
 * @brief Interrupt flags shifts Netc_EthSwt_Ip_IrqType_Class
 */
typedef enum
{
    NETC_ETHSWT_IRQ_CBTX            = 14U, /**< 100BASETX */
    NETC_ETHSWT_IRQ_SGMII4          = 13U, /**< SGMII 4 */
    NETC_ETHSWT_IRQ_SGMII3          = 12U, /**< SGMII 3 */
    NETC_ETHSWT_IRQ_SGMII2          = 11U, /**< SGMII 2 */
    NETC_ETHSWT_IRQ_SGMII1          = 10U, /**< SGMII 1 */
    NETC_ETHSWT_IRQ_CBT1_COMB       = 9U,  /**< 100BASE-T1 SubSystem Combined */
    NETC_ETHSWT_IRQ_CBT1_PHY6       = 8U,  /**< 100BASE-T1 SubSystem PHY # 6 */
    NETC_ETHSWT_IRQ_CBT1_PHY5       = 7U,  /**< 100BASE-T1 SubSystem PHY # 5 */
    NETC_ETHSWT_IRQ_CBT1_PHY4       = 6U,  /**< 100BASE-T1 SubSystem PHY # 4 */
    NETC_ETHSWT_IRQ_CBT1_PHY3       = 5U,  /**< 100BASE-T1 SubSystem PHY # 3 */
    NETC_ETHSWT_IRQ_CBT1_PHY2       = 4U,  /**< 100BASE-T1 SubSystem PHY # 2 */
    NETC_ETHSWT_IRQ_CBT1_PHY1       = 3U,  /**< 100BASE-T1 SubSystem PHY # 1 */
    NETC_ETHSWT_IRQ_CBT1_PHYSS      = 2U,  /**< 100BASE-T1 SubSystem PHY Common module */
    NETC_ETHSWT_IRQ_NETC_ETHSWTCORE1     = 1U,  /**< Ethernet Netc_EthSwt SubSystem Automotive Netc_EthSwt Interrupt 1 */
    NETC_ETHSWT_IRQ_NETC_ETHSWTCORE0     = 0U   /**< Ethernet Netc_EthSwt SubSystem Automotive Netc_EthSwt Interrupt 0 */
} Netc_EthSwt_Ip_IrqType;

/* ---bits field and structure for Vlan Filter Table Data Buffer Format--- */

/* index of Vlan Filter Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_VID_FIELD                     (1U)        /*!< second uint32 item of Vlan Filter Table Request Data Buffer Format when ACCESS_METHOD = 0x1 (Key Element Match) */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_RESUMEENTRYID_FIELD           (1U)        /*!< second uint32 item of Vlan Filter Table Request Data Buffer Format when ACCESS_METHOD = 0x2 (Search) */

typedef enum {
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD = 0U,           /*!< first uint32 item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD,                /*!< second uint32 item of Switch Tables Request Data Buffer Format when ACCESS_METHOD = 0x0 (ENTRY_ID Match) */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0,                    /*!< first item of CFGEDATA but third item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1,                    /*!< second item of CFGEDATA but forth item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2,                    /*!< third item of CFGEDATA but fifth item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3,                    /*!< forth item of CFGEDATA but sixth item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4,                    /*!< fifth item of CFGEDATA but seventh item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA5,                    /*!< sixth item of CFGEDATA but eighth item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA6                     /*!< seventh item of CFGEDATA but ninth item of Switch Tables Request Data Buffer Format */
} Netc_EthSwt_Ip_SwitchTableRequestDataIndexType;

/* bits field for Vlan Filter Table CFGE_DATA Format */
/*!
 * @brief Vlan Filter Table Config Data STG_ID field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT                   (24U)
/*!
 * @brief Vlan Filter Table Config Data STG_ID field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK                    (0x0F000000UL)
/*!
 * @brief Vlan Filter Table Config Data STG_ID.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID(x)                      (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK)

/*!
 * @brief Vlan Filter Table Config Data PORT membership field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_SHIFT          (0U)
/*!
 * @brief Vlan Filter Table Config Data PORT membership field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK           (0x00FFFFFFUL)
/*!
 * @brief Vlan Filter Table Config Data PORT membership.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK)

/*!
 * @brief Vlan Filter Table Config Data IPMFLE field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT                   (23U)
/*!
 * @brief Vlan Filter Table Config Data IPMFLE field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK                    (0x00800000UL)
/*!
 * @brief Vlan Filter Table Config Data IPMFLE.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE(x)                      (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK)

/*!
 * @brief Vlan Filter Table Config Data IPMFE field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT                    (22U)
/*!
 * @brief Vlan Filter Table Config Data IPMFE field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK                     (0x00400000UL)
/*!
 * @brief Vlan Filter Table Config Data IPMFE.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE(x)                       (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK)

/*!
 * @brief Vlan Filter Table Config Data MFO field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT                      (19U)
/*!
 * @brief Vlan Filter Table Config Data MFO field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_MASK                       (0x00180000UL)
/*!
 * @brief Vlan Filter Table Config Data MFO.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_MASK)

/*!
 * @brief Vlan Filter Table Config Data MLO field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT                      (16U)
/*!
 * @brief Vlan Filter Table Config Data MLO field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_MASK                       (0x00070000UL)
/*!
 * @brief Vlan Filter Table Config Data MLO.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_MASK)

/*!
 * @brief Vlan Filter Table Config Data FID field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_SHIFT                      (0U)
/*!
 * @brief Vlan Filter Table Config Data FID field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_MASK                       (0x00000FFFUL)
/*!
 * @brief Vlan Filter Table Config Data FID.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_MASK)

/*!
 * @brief Vlan Filter Table Config Data ETA port bitmap field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_SHIFT          (0U)
/*!
 * @brief Vlan Filter Table Config Data ETA port bitmap field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK           (0x00FFFFFFUL)
/*!
 * @brief Vlan Filter Table Config Data ETA port bitmap.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK)

/*!
 * @brief Vlan Filter Table Config Data base ET_EID field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_SHIFT              (0U)
/*!
 * @brief Vlan Filter Table Config Data base ET_EID field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_MASK               (0xFFFFFFFFUL)
/*!
 * @brief Vlan Filter Table Config Data base ET_EID.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_MASK)

/*!
 * @brief Vlan Filter Table Config Data KEY_DATA bits field.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID_SHIFT                      (0U)
/*!
 * @brief Vlan Filter Table Config Data KEY_DATA bits field mask.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID_MASK                       (0x00000FFFUL)
/*!
 * @brief Vlan Filter Table Config Data KEY_DATA bits.
 */
#define NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID_SHIFT)) & NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID_MASK)

/*!
 * @brief Vlan Filter Table response data type enumeration. Netc_EthSwt_Ip_VlanFilterTable_ResponsDataIndexType
 */
typedef enum {
    NETC_ETHSWT_VLANFILTERTABLE_RSPDATA_STATUS = 0x0U,     /*!< Status Field In Vlan Filter Table Response Data Buffer */
    NETC_ETHSWT_VLANFILTERTABL_RSPDATA_ENTRYID,            /*!< Entry_ID Field In Vlan Filter Table Response Data Buffer */
    NETC_ETHSWT_VLANFILTERTABL_RSPDATA_VID,                /*!< VID field of KEYE DATA In Vlan Filter Table Response Data Buffer */
    NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0,          /*!< The first element of CFGE DATA In Vlan Filter Table Response Data Buffer */
    NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1,          /*!< The second element of CFGE DATA In Vlan Filter Table Response Data Buffer */
    NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2,          /*!< The third element of CFGE DATA In Vlan Filter Table Response Data Buffer */
    NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3           /*!< The last element of CFGE DATA In Vlan Filter Table Response Data Buffer */
} Netc_EthSwt_Ip_VlanFilterTable_ResponsDataIndexType;

/*!
 * @brief Vlan Filter Table CFGE_DATA format.
 */
typedef struct {
    uint32 Cfge_Data[NETC_ETHSWT_TABLE_CFGEDATA_ITEMS]; /*!< Config data for Vlan Filtre Table */
} Netc_EthSwt_Ip_VlanFilterTableCFGEDataType;
/* ---bits field and structure for Vlan Filter Table Data Buffer Format--- */

/*!
 * @brief VLAN Tag Netc_EthSwt_Ip_VlanTagType_Class
 */
typedef struct
{
    uint16 id;     /*!< Specifies the VLAN address 0..65535 */
    uint8  pcp;    /*!< Priority to be added in the tag 0..7 */
    uint8  dei;    /*!< 1 bit field - drop eligible indicator */
} Netc_EthSwt_Ip_VlanTagType;

/*!
 * @brief PHY configuration of a port Netc_EthSwt_Ip_FdbEntryType_Class
 */
typedef struct
{
    uint16                  ePortMask;     /*!< Mask of the egress ports */
    uint8                   macAddr[6U];    /*!< Array containing the MAC addresses of the port */
} Netc_EthSwt_Ip_FdbEntryType;

/*!
 * @brief PHY configuration of a port Netc_EthSwt_Ip_VlanFilterEntryType
 */
typedef struct
{
    uint16                  iPortMask;     /*!< Mask of the ingress ports */
    uint16                  vlanId;        /*!< VLAN ID, VlanMembershipId */
} Netc_EthSwt_Ip_VlanFilterEntryType;

/*!
 * @brief Netc_EthSwt counter structure Netc_EthSwt_Ip_CounterType
 */
typedef struct {
    uint64 rxEtherOctetCounter;                  /*!< Port MAC 0 Receive Ethernet Octets Counter(etherStatsOctetsn) (PM0_REOCTn) */
    uint64 rxOctetCounter;                       /*!< Supported by pseudo port. Port MAC 0 Receive Octets Counter(iflnOctetsn) (PM0_ROCTn) */
    uint64 rxValidPauseFrmCounter;               /*!< Port MAC 0 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_RXPFn) */
    uint64 rxFrmCounter;                         /*!< MAC 0 Receive Frame Counter Register(aFramesReceivedOKn) (PM0_RFRMn) */
    uint64 rxFrameCheckSequenceErrorCounter;     /*!< Port MAC 0 Receive Frame Check Sequence Error Counter Register() (PM0_RFCSn) */
    uint64 rxVlanFrmCounter;                     /*!< Port MAC 0 Receive VLAN Frame Counter Register(VLANReceivedOKn) (PM0_RVLANn) */
    uint64 rxFrameErrorCounter;                  /*!< Port MAC 0 Receive Frame Error Counter Register(ifInErrorsn) (PM0_RERRn) */
    uint64 rxUnicastFrmCounter;                  /*!< Supported by pseudo port. Port MAC 0 Receive Unicast Frame Counter Register(ifInUcastPktsn) (PM0_RUCAn) */
    uint64 rxMulticastFrmCounter;                /*!< Supported by pseudo port. Port MAC 0 Receive Multicast Frame Counter Register(ifInMulticastPktsn) (PM0_RMCAn) */
    uint64 rxBroadcastFrmCounter;                /*!< Supported by pseudo port. Port MAC 0 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) (PM0_RBCAn) */
    uint64 rxDroppedPktCounter;                  /*!< Port MAC 0 Receive Dropped Packets Counter Register(etherStatsDropEventsn) (PM0_RDRPn) */
    uint64 rxPktCounter;                         /*!< Port MAC 0 Receive Packets Counter Register(etherStatsPktsn) (PM0_RPKTn) */
    uint64 rxUndersizePacketCounter;             /*!< Port MAC 0 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_RUNDn) */
    uint64 rx64OctetPktCounter;                  /*!< Port MAC 0 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) (PM0_R64n) */
    uint64 rx65to127OctetPktCounter;             /*!< Port MAC 0 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) (PM0_R127n) */
    uint64 rx128to255OctetPktCounter;            /*!< Port MAC 0 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) (PM0_R255n) */
    uint64 rx256to511OctetPktCounter;            /*!< Port MAC 0 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) (PM0_R511n) */
    uint64 rx512to1023OctetPktCounter;           /*!< Port MAC 0 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) (PM0_R1023n) */
    uint64 rx1024to1522OctetPktCounter;          /*!< Port MAC 0 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) (PM0_R1522n) */
    uint64 rx1523toMaxOctetPktCounter;           /*!< Port MAC 0 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) (PM0_R1523Xn) */
    uint64 rxOversizedPacketsCounter;            /*!< Port MAC 0 Receive Oversized Packet Counter Register(etherStatsOversizePktsn) (PM0_ROVRn) */
    uint64 rxJabberPktCounter;                   /*!< Port MAC 0 Receive Jabber Packet Counter Register(etherStatsJabbersn) (PM0_RJBRn) */
    uint64 rxFragmentPktCounter;                 /*!< Port MAC 0 Receive Fragment Packet Counter Register(etherStatsFragmentsn (PM0_RFRGn) */
    uint64 rxControlPktCounter;                  /*!< Port MAC 0 Receive Control Packet Counter Register (PM0_RCNPn) */
    uint64 rxDroppedNTruncatedPktCounter;        /*!< Port MAC 0 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) (PM0_RDRNTPn) */

    uint64 txEtherOctetCounter;                  /*!< MAC 0 Transmit Ethernet Octets Counter(etherStatsOctetsn) (PM0_TEOCTn) */
    uint64 txOctetCounter;                       /*!< Supported by pseudo port. Port MAC 0 Transmit Octets Counter Register(ifOutOctetsn) (PM0_TOCTn) */
    uint64 txValidPauseFrmCounter;               /*!< Port MAC 0 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_TXPFn) */
    uint64 txFrmCounter;                         /*!< Port MAC 0 Transmit Frame Counter Register(aFramesTransmittedOKn) (PM0_TFRMn) */
    uint64 txFrameCheckSequenceErrorCounter;     /*!< Port MAC 0 Transmit Frame Check Sequence Error Counter Register() (PM0_TFCSn) */
    uint64 txVlanFrmCounter;                     /*!< Port MAC 0 Transmit VLAN Frame Counter Register(VLANTransmittedOKn) (PM0_TVLANn) */
    uint64 txFrameErrorCounter;                  /*!< Port MAC 0 Transmit Frame Error Counter Register(ifOutErrorsn) (PM0_TERRn) */
    uint64 txUnicastFrmCounter;                  /*!< Supported by pseudo port. Port MAC 0 Transmit Unicast Frame Counter Register(ifOutUcastPktsn) (PM0_TUCAn) */
    uint64 txMulticastFrmCounter;                /*!< Supported by pseudo port. Port MAC 0 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) (PM0_TMCAn) */
    uint64 txBroadcastFrmCounter;                /*!< Supported by pseudo port. Port MAC 0 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) (PM0_TBCAn) */
    uint64 txPktCounter;                         /*!< Port MAC 0 Transmit Packets Counter Register(etherStatsPktsn) (PM0_TPKTn) */
    uint64 txUndersizePacketCounter;             /*!< Port MAC 0 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_TUNDn) */
    uint64 tx64OctetPktCounter;                  /*!< Port MAC 0 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) (PM0_T64n) */
    uint64 tx65to127OctetPktCounter;             /*!< Port MAC 0 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) (PM0_T127n) */
    uint64 tx128to255OctetPktCounter;            /*!< Port MAC 0 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) (PM0_T255n) */
    uint64 tx256to511OctetPktCounter;            /*!< Port MAC 0 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) (PM0_T511n) */
    uint64 tx512to1023OctetPktCounter;           /*!< Port MAC 0 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) (PM0_T1023n) */
    uint64 tx1024to1522OctetPktCounter;          /*!< Port MAC 0 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) (PM0_T1522n) */
    uint64 tx1523toMaxOctetPktCounter;           /*!< Port MAC 0 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) (PM0_T1523Xn) */
    uint64 txControlPktCounter;                  /*!< Port MAC 0 Transmit Control Packet Counter Register (PM0_TCNPn) */
    uint64 txDeferredPktCounter;                 /*!< Port MAC 0 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) (PM0_TDFRn) */
    uint64 txMultiCollisionCounter;              /*!< Port MAC 0 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) (PM0_TMCOLn) */
    uint64 txSingleCollisionCounter;             /*!< Port MAC 0 Transmit Single Collision Counter(aSingleCollisionFrames) Register (PM0_TSCOLn) */
    uint64 txLateCollisionCounter;               /*!< Port MAC 0 Transmit Late Collision Counter(aLateCollisions) Register (PM0_TLCOLn) */
    uint64 txExcessiveCollisionCounter;          /*!< Port MAC 0 Transmit Excessive Collisions Counter Register (PM0_TECOLn) */

    uint32 rxDiscardCounter;                     /*!< Port Rx discard count register (PRXDCR) */
    uint32 txDiscardCounter;                     /*!< Port Tx discard count register (PTXDCR) */
    uint32 unIntegrityErrorCounter;              /* Uncorrectable non-fatal integrity error count register (UNIECTR) which tracks how many events have been detected. */
} Netc_EthSwt_Ip_CounterType;

/*!
 * @brief Netc_EthSwt counter enum Netc_EthSwt_Ip_SingleCounterType
 */
typedef enum {
    NETC_ETHSWT_IP_RX_ETH_OCTETS_COUNT                 = 0x1100U,  /*!< Port MAC 0 Receive Ethernet Octets Counter(etherStatsOctetsn) (PM0_REOCTn) */
    NETC_ETHSWT_IP_RX_OCTETS_COUNT                     = 0x1108U,  /*!< Supported by pseudo port. Port MAC 0 Receive Octets Counter(iflnOctetsn) (PM0_ROCTn) */
    NETC_ETHSWT_IP_RX_VALID_PAUSE_FRM_COUNT            = 0x1118U,  /*!< Port MAC 0 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_RXPFn) */
    NETC_ETHSWT_IP_RX_FRM_COUNT                        = 0x1120U,  /*!< Port MAC 0 Receive Frame Counter Register(aFramesReceivedOKn) (PM0_RFRMn)  */
    NETC_ETHSWT_IP_RX_FRM_CHK_SEQUENCE_COUNT           = 0x1128U,  /*!< Port MAC 0 Receive Frame Check Sequence Error Counter Register() (PM0_RFCSn)  */
    NETC_ETHSWT_IP_RX_VLAN_FRM_COUNT                   = 0x1130U,  /*!< Port MAC 0 Receive VLAN Frame Counter Register(VLANReceivedOKn) (PM0_RVLANn)  */
    NETC_ETHSWT_IP_RX_FRM_ERROR_COUNT                  = 0x1138U,  /*!< Port MAC 0 Receive Frame Error Counter Register(ifInErrorsn) (PM0_RERRn)  */
    NETC_ETHSWT_IP_RX_UNICAST_FRM_COUNT                 = 0x1140U,  /*!< Supported by pseudo port. Port MAC 0 Receive Unicast Frame Counter Register(ifInUcastPktsn) (PM0_RUCAn)  */
    NETC_ETHSWT_IP_RX_MULTICAST_FRM_COUNT              = 0x1148U,  /*!< Supported by pseudo port. Port MAC 0 Receive Multicast Frame Counter Register(ifInMulticastPktsn) (PM0_RMCAn)  */
    NETC_ETHSWT_IP_RX_BROADCAST_FRM_COUNT              = 0x1150U,  /*!< Supported by pseudo port. Port MAC 0 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) (PM0_RBCAn)  */
    NETC_ETHSWT_IP_RX_DROPPED_PKTS_COUNT               = 0x1158U,  /*!< Port MAC 0 Receive Dropped Packets Counter Register(etherStatsDropEventsn) (PM0_RDRPn)  */
    NETC_ETHSWT_IP_RX_PKTS_COUNT                       = 0x1160U,  /*!< Port MAC 0 Receive Packets Counter Register(etherStatsPktsn) (PM0_RPKTn)  */
    NETC_ETHSWT_IP_RX_UNDERSIZED_PKT_COUNT             = 0x1168U,  /*!< Port MAC 0 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_RUNDn)  */
    NETC_ETHSWT_IP_RX_64_OCTETS_PKT_COUNT              = 0x1170U,  /*!< Port MAC 0 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) (PM0_R64n)  */
    NETC_ETHSWT_IP_RX_127_OCTETS_PKT_COUNT             = 0x1178U,  /*!< Port MAC 0 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) (PM0_R127n)  */
    NETC_ETHSWT_IP_RX_255_OCTETS_PKT_COUNT             = 0x1180U,  /*!< Port MAC 0 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) (PM0_R255n)  */
    NETC_ETHSWT_IP_RX_511_OCTETS_PKT_COUNT             = 0x1188U,  /*!< Port MAC 0 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) (PM0_R511n)  */
    NETC_ETHSWT_IP_RX_1023_OCTETS_PKT_COUNT            = 0x1190U,  /*!< Port MAC 0 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) (PM0_R1023n)  */
    NETC_ETHSWT_IP_RX_1522_OCTETS_PKT_COUNT            = 0x1198U,  /*!< Port MAC 0 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) (PM0_R1522n)  */
    NETC_ETHSWT_IP_RX_1523_TOMAXOCTETS_PKT_COUNT       = 0x11A0U,  /*!< Port MAC 0 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) (PM0_R1523Xn)  */
    NETC_ETHSWT_IP_RX_OVERSIZED_PKT_COUNT              = 0x11A8U,  /*!< Port MAC 0 Receive Oversized Packet Counter Register(etherStatsOversizePktsn) (PM0_ROVRn)  */
    NETC_ETHSWT_IP_RX_JABBER_PKT_COUNT                 = 0x11B0U,  /*!< Port MAC 0 Receive Jabber Packet Counter Register(etherStatsJabbersn) (PM0_RJBRn)  */
    NETC_ETHSWT_IP_RX_FRAGMENT_PKT_COUNT               = 0x11B8U,  /*!< Port MAC 0 Receive Fragment Packet Counter Register(etherStatsFragmentsn (PM0_RFRGn)  */
    NETC_ETHSWT_IP_RX_CONTROL_PKT_COUNT                = 0x11C0U,  /*!< Port MAC 0 Receive Control Packet Counter Register (PM0_RCNPn)  */
    NETC_ETHSWT_IP_RX_DROPPED_NOT_TRUNCATED_PKT_COUNT  = 0x11C8U,  /*!< Port MAC 0 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) (PM0_RDRNTPn)  */

    NETC_ETHSWT_IP_TX_ETH_OCTETS_COUNT                 = 0x1200U,  /*!< Port MAC 0 Transmit Ethernet Octets Counter(etherStatsOctetsn) (PM0_TEOCTn)  */
    NETC_ETHSWT_IP_TX_OCTETS_COUNT                     = 0x1208U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Octets Counter Register(ifOutOctetsn) (PM0_TOCTn)  */
    NETC_ETHSWT_IP_TX_VALID_PAUSE_FRM_COUNT            = 0x1218U,  /*!< Port MAC 0 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_TXPFn)  */
    NETC_ETHSWT_IP_TX_FRM_COUNT                        = 0x1220U,  /*!< Port MAC 0 Transmit Frame Counter Register(aFramesTransmittedOKn) (PM0_TFRMn)  */
    NETC_ETHSWT_IP_TX_FRM_CHK_SEQUENCE_COUNT           = 0x1228U,  /*!< Port MAC 0 Transmit Frame Check Sequence Error Counter Register() (PM0_TFCSn)  */
    NETC_ETHSWT_IP_TX_VLAN_FRM_COUNT                   = 0x1230U,  /*!< Port MAC 0 Transmit VLAN Frame Counter Register(VLANTransmittedOKn) (PM0_TVLANn)  */
    NETC_ETHSWT_IP_TX_FRM_ERROR_COUNT                  = 0x1238U,  /*!< Port MAC 0 Transmit Frame Error Counter Register(ifOutErrorsn) (PM0_TERRn)  */
    NETC_ETHSWT_IP_TX_UNICAST_FRM_COUNT                 = 0x1240U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Unicast Frame Counter Register(ifOutUcastPktsn) (PM0_TUCAn)  */
    NETC_ETHSWT_IP_TX_MULTICAST_FRM_COUNT              = 0x1248U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) (PM0_TMCAn)  */
    NETC_ETHSWT_IP_TX_BROADCAST_FRM_COUNT              = 0x1250U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) (PM0_TBCAn)  */
    NETC_ETHSWT_IP_TX_PKTS_COUNT                       = 0x1260U,  /*!< Port MAC 0 Transmit Packets Counter Register(etherStatsPktsn) (PM0_TPKTn)  */
    NETC_ETHSWT_IP_TX_UNDERSIZED_PKT_COUNT             = 0x1268U,  /*!< Port MAC 0 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_TUNDn)  */
    NETC_ETHSWT_IP_TX_64_OCTETS_PKT_COUNT              = 0x1270U,  /*!< Port MAC 0 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) (PM0_T64n)  */
    NETC_ETHSWT_IP_TX_127_OCTETS_PKT_COUNT             = 0x1278U,  /*!< Port MAC 0 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) (PM0_T127n)  */
    NETC_ETHSWT_IP_TX_255_OCTETS_PKT_COUNT             = 0x1280U,  /*!< Port MAC 0 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) (PM0_T255n)  */
    NETC_ETHSWT_IP_TX_511_OCTETS_PKT_COUNT             = 0x1288U,  /*!< Port MAC 0 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) (PM0_T511n)  */
    NETC_ETHSWT_IP_TX_1023_OCTETS_PKT_COUNT            = 0x1290U,  /*!< Port MAC 0 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) (PM0_T1023n)  */
    NETC_ETHSWT_IP_TX_1522_OCTETS_PKT_COUNT            = 0x1298U,  /*!< Port MAC 0 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) (PM0_T1522n)  */
    NETC_ETHSWT_IP_TX_1523_TOMAXOCTETS_PKT_COUNT       = 0x12A0U,  /*!< Port MAC 0 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) (PM0_T1523Xn)  */
    NETC_ETHSWT_IP_TX_CONTROL_PKT_COUNT                = 0x12C0U,  /*!< Port MAC 0 Transmit Control Packet Counter Register (PM0_TCNPn)  */
    NETC_ETHSWT_IP_TX_DEFERRED_PKT_COUNT               = 0x12D0U,  /*!< Port MAC 0 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) (PM0_TDFRn)  */
    NETC_ETHSWT_IP_TX_MULTIPLE_COLLISIONS_COUNT        = 0x12D8U,  /*!< Port MAC 0 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) (PM0_TMCOLn)  */
    NETC_ETHSWT_IP_TX_SINGLE_COLLISION_COUNT           = 0x12E0U,  /*!< Port MAC 0 Transmit Single Collision Counter(aSingleCollisionFrames) Register (PM0_TSCOLn)  */
    NETC_ETHSWT_IP_TX_LATE_COLLISION_COUNT             = 0x12E8U,  /*!< Port MAC 0 Transmit Late Collision Counter(aLateCollisions) Register (PM0_TLCOLn)  */
    NETC_ETHSWT_IP_TX_EXCESSIVE_COLLISIONS_COUNT       = 0x12F0U   /*!< Port MAC 0 Transmit Excessive Collisions Counter Register (PM0_TECOLn)  */
} Netc_EthSwt_Ip_SingleCounterType;

typedef enum {
    NETC_ETHSWT_IP_PPMROCR0 = 0x1080U,  /*!< Port pseudo MAC receive octets counter PPMROCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMROCR1 = 0x1084U,  /*!< Port pseudo MAC receive octets counter PPMROCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRUFCR0 = 0x1088U, /*!< Port pseudo MAC receive unicast frame counter register PPMRUFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRUFCR1 = 0x108CU, /*!< Port pseudo MAC receive unicast frame counter register PPMRUFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRMFCR0 = 0x1090U, /*!< Port pseudo MAC receive multicast frame counter register PPMRMFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRMFCR1 = 0x1094U, /*!< Port pseudo MAC receive multicast frame counter register PPMRMFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRBFCR0 = 0x1098U, /*!< Port pseudo MAC receive broadcast frame counter register PPMRBFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRBFCR1 = 0x109CU, /*!< Port pseudo MAC receive broadcast frame counter register PPMRBFCR1. The upper 32bits of the counter.  */

    NETC_ETHSWT_IP_PPMTOCR0 = 0x10C0U, /*!< Port pseudo MAC transmit octets counter PPMTOCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTOCR1 = 0x10C4U, /*!< Port pseudo MAC transmit octets counter PPMTOCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTUFCR0 = 0x10C8U, /*!< Port pseudo MAC transmit unicast frame counter register PPMTUFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTUFCR1 = 0x10CCU, /*!< Port pseudo MAC transmit unicast frame counter register PPMTUFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTMFCR0 = 0x10D0U, /*!< Port pseudo MAC transmit multicast frame counter register PPMTMFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTMFCR1 = 0x10D4U, /*!< Port pseudo MAC transmit multicast frame counter register PPMTMFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTBFCR0 = 0x10D8U, /*!< Port pseudo MAC transmit broadcast frame counter register PPMTBFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTBFCR1 = 0x10DCU, /*!< Port pseudo MAC transmit broadcast frame counter register PPMTBFCR1. The upper 32bits of the counter.  */
} Netc_EthSwt_Ip_PseudoPortCounterType;

typedef uint64 Netc_EthSwt_Ip_CounterValueType;

/*!
 * @brief Action to be taken when the rate policy criteria defined for this EthSwtPortPolicer are met.
 */
typedef enum {
    NETC_ETHSWT_BLOCK_SOURCE, /*!< Eth Switch rate violation block source. */
    NETC_ETHSWT_DROP_FRAME    /*!< Eth Switch rate violation  drop frame. */
} Netc_EthSwt_Ip_RateViolationActionType;

/*!
 * @brief How the message with a specific VLAN Id shall be handled.
 */
typedef enum {
    NETC_ETHSWT_NOT_SENT,          /*!< Eth Switch vlan frame not sent. */
    NETC_ETHSWT_SENT_TAGGED,        /*!< Eth Switch vlan frame sent tagged. */
    NETC_ETHSWT_SENT_UNTAGGED       /*!< Eth Switch vlan frame sent untagged. */
} Netc_EthSwt_Ip_VlanHandlingType;

/*!
 * @brief Message priority the incoming message will be tagged with.
 */
typedef struct {
    uint8 EthSwtPriorityRegenerationIngressPriority; /*!< Message priority of the incoming message. */
    uint8 EthSwtPriorityRegenerationRegeneratedPriority; /*!< Message priority the incoming message will be tagged with. */
} Netc_EthSwt_Ip_PriorityRegenerationType;

/*!
 * @brief Priority based traffic class assignment.
 */
typedef struct {
    uint8 EthSwtPriorityTrafficClassAssignmentTrafficClass[8U]; /*!< Traffic Class value. */
} Netc_EthSwt_Ip_PriorityTrafficClassAssignmentType;

/*!
 * @brief Rate Policing parameters.
 */
typedef struct {
    Netc_EthSwt_Ip_PriorityRegenerationType priorityRegeneration[8U]; /*!< Message priority the incoming message will be tagged with. */
    uint8 EthSwtPortRatePolicedPriority; /*!< The priority which this rate policy shall be limited on. */
    Netc_EthSwt_Ip_RateViolationActionType EthSwtPortRateViolationAction; /*!< Action to be taken when the rate policy criteria defined for this EthSwtPortPolicer are met. */
    uint32 EthSwtPriorityTrafficClassAssignmentType[8U]; /*!< Message priority. */
} Netc_EthSwt_Ip_PortPolicerType;

/*!
 * @brief Port ingress description
 */
typedef struct {
    uint8 EthSwtPortIngressDefaultPriority; /*!< Default priority for ingress. */
    uint16 EthSwtPortIngressDefaultVlan; /*!< Default VLAN for ingress. */
    boolean SentUntaggedFrames; /* EthSwtPortVlanForwardingType for the default VLAN */
    boolean portIngressAllowCutThroughFrames; /*!< Allow cut through frames */
    boolean EthSwtPortIngressDropUntagged; /*!< Defines the ingress behavior for untagged frames. */
    boolean EthSwtDropDoubleTagged; /*!< if a switch shall drop double tagged frames. */
    boolean EthSwtPortIngressDropSingleTagged; /*!< if a switch shall drop single tagged frames. */
    boolean EthSwtPortIngressDropPriorityTagged; /*!< if a switch shall drop priority tagged frames. */
    uint16 EthSwtPortIngressVlanModification; /*!< Tagged all frames with this VLAN Id. */
    uint8 EthSwtPortTrafficClassAssignment; /*!< Priority based traffic class assignment. */
    Netc_EthSwt_Ip_PortPolicerType *policer; /*!< Rate Policing parameters. */
    Netc_EthSwt_Ip_PriorityRegenerationType (*priorityRegeneration)[8U]; /*!< Priority of the incoming message. */
    Netc_EthSwt_Ip_PriorityTrafficClassAssignmentType PriorityTrafficClassAssignment[8U]; /*!< Priority based traffic class assignment. */
    boolean vlanEnable; /*!< Use the IVP and DR from the frame or use port default */
    uint8 vlanDefaultIpv; /*!< Default for untaged frames or when vlan is disable */
    uint8 vlanDefaultDr; /*!< Default for untaged frames or when vlan is disable */
    uint8 vlanMappingProfile; /*!< Select the VLANIPV profile 0/1 using the PCP and DEI */
    boolean vlanEnableIngressPcpToPcpMapping; /*!< If there is frame modification enable the PCP change */
    uint8 vlanIngressPcpToPcpProfile; /*!< If there is frame modification and enable use this profile */
} Netc_EthSwt_Ip_PortIngressType;

/*!
 * @brief Defines the scheduler algorithm.
 */
typedef struct {
    uint32 EthSwtPortSchedulerPredecessorOrder; /*!< The order of the scheduler predecessors. */
} Netc_EthSwt_Ip_PortSchedulerType;

/*!
 * @brief Represents a Shaper in the egress port.
 */
typedef struct {
    /* To improve the speed of the init of the drivers, Bandwidth and hiCredit are calculated in the upper layes */
    boolean EthSwtPortEgressCBShaperEnable; /*!< Enable the Credit-Based Shaper. */
    uint32 EthSwtPortEgressCBShaperBandwidth; /*!< Bandwidth of the Credit-Based Shaper. Bandwidth = (idleSlope/portTxRate) * 100, Note: total CBS bandwidth on a port should be less the 75% */
    uint32 EthSwtPortEgressHiCredit; /*!< HiCredit if the Credit-Based Shaper. (hiCredit on credit) = maxSizedFrame * Bandwidth * (enetClockFrequency / portTxRate) */
    uint32 EthSwtPortMaxSizedFrame; /*!< Max Frame Size, should be less the 2000 bytes */
} Netc_EthSwt_Ip_PortShaperType;

/*!
 * @brief Port egress description
 */
typedef struct {
    Netc_EthSwt_Ip_PortSchedulerType *portScheduler; /*!< Defines the scheduler algorithm. */
    Netc_EthSwt_Ip_PortShaperType (*portShaper)[8U]; /*!< Represents a Shaper in the egress port. */
    boolean portEgressAllowCutThroughFrames; /*!< Allow cut through frames */
    boolean updateEgressDr; /*!< If there is frame modification and enable DEI change */
    uint8 (*vlanDrToDei)[NETC_ETHSWT_NUMBER_OF_DR]; /*!< If there is frame modification and enable map DR to DEI */
    uint8 vlanMappingProfile; /*!< Select the VLANIPV profile 0/1 using the PCP and DEI */
    boolean vlanEnableEgressPcpToPcpMapping; /*!< If there is frame modification enable the PCP change */
    uint8 vlanEgressPcpToPcpProfile; /*!< If there is frame modification and enable use this profile */
    uint8 portPPDUByteCountOverhead;    /* PPDU Byte count overhead which includes IPG, SFD and Preamble. */
    uint8 portMACSecByteCountOverhead;  /* Number of bytes of overhead due to MACSec encapsulation */
    uint32 portTimeGateSchedulingAdvanceTimeOffsetReg;  /* This is the port time gate scheduling advance time offset register */
    boolean portTimeAwareShaperEnable;  /*!< If the data for time gate scheduling talbe is configured  */
    uint64 portEgressAdminBaseTime;  /*!< Administrative Base Time */
    uint32 portEgressAdminCycleTime; /*!< Administrative Cycle Time */
    uint32 portEgressAdminCycleTimeExt; /*!< Administrative Cycle Time Extension */
    uint8 numberOfGateControlListEntries; /*!< Number of entries in Administrative Gate Control list. */
    Netc_EthSwt_Ip_GateEntryAdminControlListDataType (*TimeGateControlListEntries)[NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES]; /*!< Pointer to an array containing the gate control list for port. */
} Netc_EthSwt_Ip_PortEgressType;

/*!
 * @brief Port description for initalisation
 */
typedef struct {
    boolean EthSwtPortMacLayerPortEnable; /*!< enable/disable port mac layer */
    Netc_EthSwt_Ip_PortEgressType *ePort; /*!< Configuration of one Ethernet Switch Port Egress behavior. */
    Netc_EthSwt_Ip_PortIngressType *iPort; /*!< Configuration of one Ethernet Switch Port Ingress behavior. */
    EthTrcv_BaudRateType EthSwtPortMacLayerSpeed; /**< Defines the baud rate of the MAC layer. */
    Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode; /*!< Defines the duplex mode of switch mac layer duplex mode*/
    Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType; /*!< Defines the physical layer type of this EthSwtPort. */
    uint8 EthSwtPortMacAddresses[6U]; /*!< Default MAC address. */
    uint16 EthSwtPortMaxDynamicEntries; /*!< Specifies for a given port, the maximium number of dynamic entries in the FDB table.*/
    boolean EthSwtPortEnableMagicPacketDetection; /*!< Enable/Disable packet magic detection*/
    boolean EthSwtPortTimeStampSupport; /*!< Activates egress time stamping. */
    boolean EthSwtPortPruningEnable; /*!< A received frame is not allowed to be transmitted on same port it was recceived. */
    boolean EthSwtPortLoopbackEnable; /*!< Enable loopback mode for current port */
    boolean EthSwtPortDisallowMacStationMove; /*!< MAC station move disallowed.*/
} Netc_EthSwt_Ip_PortType;

/*!
 * @brief Configuration of one Ethernet Switch for initalisation
 */
typedef struct {
    Netc_EthSwt_Ip_MacLearningOptionType MacLearningOption; /*!< specifies the Mac learning mode */
    Netc_EthSwt_Ip_MacForwardingOptionType MacForwardingOption; /*!< specifies the Mac forwarding option */
    uint16 EthSwtMaxDynamicEntries; /*!< This field specifies the maximum number of dynamic entries allowed in the FDB table for the entire switch. A value of 0 implies no global switch limit imposed for dynamic entries.*/
    uint16 EthSwtArlTableEntryTimeout; /*!< specifies the timeout in seconds for removing unused entries. */
    boolean EthSwtEnableSharedLearning; /*!< Used to determine the FID when doing a lookup in the FDB table. 0: Independent VLAN learning: FID is set to to the VID assigned to the frame 1: Shared VLAN learning: Use the FID specified in this register */
    uint16 EthSwtCustomVlanEtherType1;  /*!< Custom VLAN */
    uint16 EthSwtCustomVlanEtherType2;  /*!< Custom VLAN */
    Netc_EthSwt_Ip_PortType (*port)[NETC_ETHSWT_NUMBER_OF_PORTS]; /*!< Port description. */
#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
    uint8 NumberOfFdbEntries; /*!< Number of FDB entries. */
    const Netc_EthSwt_Ip_FdbEntryType (*FdbEntries)[NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES]; /*!< Pointer to an array containing the FDB configuration. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
    uint8 NumberOfVlanFilterEntries; /*!< Number of Vlan Filter entries. */
    const Netc_EthSwt_Ip_VlanFilterEntryType (*VlanFilterEntries)[NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES]; /*!< Pointer to an array containing the Vlan configuration. */
#endif
    uint8 (*vlanPcpDei2IpvProfile)[NETC_ETHSWT_NUMBER_OF_PROFILES][NETC_ETHSWT_NUMBER_OF_PCP_DEI]; /*!< Profiles for PCP_DEI to IPV ingress mapping. */
    uint8 (*vlanPcpDei2DrProfile)[NETC_ETHSWT_NUMBER_OF_PROFILES][NETC_ETHSWT_NUMBER_OF_PCP_DEI]; /*!< Profiles for PCP_DEI to DR ingress mapping. */
    uint8 (*vlanPcp2PcpProfile)[NETC_ETHSWT_NUMBER_OF_PROFILES][NETC_ETHSWT_NUMBER_OF_PCP]; /*!< Profiles for PCP to PCP frame modification. */
    uint8 (*vlanIpvDr2PcpProfile)[NETC_ETHSWT_NUMBER_OF_PROFILES][NETC_ETHSWT_NUMBER_OF_IPV][NETC_ETHSWT_NUMBER_OF_DR]; /*!< Profiles for egress IPV/DR to PCP frame modification. */
	uint32 netcClockFrequency;  /*!< Netc system clock */
    uint32 netcExternalClockFrequency;  /*!< extern reference clock */
    Netc_EthSwt_Ip_1588ClockSourceOptionType Timer1588ClkSrc;   /*!< reference clock source for 1588 timer */
} Netc_EthSwt_Ip_ConfigType;

/**
* @brief Type to request or obtain the mirroring state (enable/disable) for a particular Ethernet switch.
* @implements     Netc_EthSwt_Ip_SwitchMirrorStateType_enum
*/
typedef enum
{
    NETC_ETHSWT_MIRROR_DISABLED = 0x0U,      /*!< @brief switch mirroring disabled. */
    NETC_ETHSWT_MIRROR_ENABLED  = 0x1U       /*!< @brief switch mirroring enabled. */
} Netc_EthSwt_Ip_SwitchMirrorStateType;

/**
* @brief Switch Mirroring Mode Type
*/
typedef enum
{
    NETC_ETHSWT_NO_VLAN_RETAGGING = 0x0U,        /*!< @brief No VLAN retagging. */
    NETC_ETHSWT_VLAN_RETAGGING = 0x1U,           /*!< @brief VLAN retagging. */
    NETC_ETHSWT_VLAN_DOUBLE_TAGGING  = 0x2U      /*!< @brief VLAN Double tagging. */
} Netc_EthSwt_Ip_SwitchMirroringModeType;

/** @brief The Netc_EthSwt_Ip_SwitchMirrorCfgType specify the mirror configuration which is set up per Ethernet switch. 
*   @implements Netc_EthSwt_Ip_SwitchMirrorCfgType_struct
* */
typedef struct
{
    uint8    SrcMacAddrFilter[6U];              /*!< @brief Specifies the source MAC address [0..255,0..255,0..255,0..255,0..255,0..255] that should be mirrored. If set to 0,0,0,0,0,0, no source MAC address filtering shall take place. */
    uint8    DstMacAddrFilter[6U];              /*!< @brief Specifies the destination MAC address [0..255,0..255,0..255,0..255,0..255,0..255] that should be mirrored. If set to 0,0,0,0,0,0, no destination MAC address filtering shall take place. */
    uint16   VlanIdFilter;                      /*!< @brief Specifies the VLAN address 0..4094 that should be mirrored. If set to 65535, no VLAN filtering shall take place. */
    uint32   TrafficDirectionIngressBitMask;    /*!< @brief Specifies the bit mask of Ethernet switch ingress port traffic direction to be mirrored. The bit mask is calculated depending of the values of EthSwtPortIdx. (e.g. set EthSwtPortIdx == 2 => TrafficDirectionIngressBitMask = 0b0000 0000 0000 0000 0000 0000 0000 0100).
                                                0b0 == disable ingress port mirroring 0b1 == enable ingress port mirroring Example: TrafficDirectionIngressBitMask = 0b0000 0000 0000 0000 0000 0000 0000 0100 => Ingress traffic mirroring is enabled of Ethernet switch port with EthSwtPortIdx=2 */
    uint8    CapturePortIdx;                    /*!< @brief Specifies the Ethernet switch port which capture the mirrored traffic */
    uint16   VlanId;                            /*!< @brief Specifies the VLAN address 0..4094 which shall be used for re-tagging or double-tagging if MirroringMode is set to 0x01 (VLAN re-tagging) or 0x02 (VLAN double tagging).
                                                If the value is set to 65535, the value shall be ignored */
    Netc_EthSwt_Ip_SwitchMirroringModeType    MirroringMode;     /*!< @brief specifies the mode how the mirrored traffic should be tagged : 0x00 == No VLAN retagging; 0x01 == VLAN retagging; 0x03 == VLAN Double tagging */
} Netc_EthSwt_Ip_SwitchMirrorCfgType;

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

#endif /* NETC_ETHSWT_IP_TYPES_H */
