/*
 * Copyright 2021-2025 NXP
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
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_TYPES_VENDOR_ID                    43
#define NETC_ETHSWT_IP_TYPES_MODULE_ID                    89
#define NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION             2
#define NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION             0
#define NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION             1

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
    /* Check if header file and StandardTypes.h are of the same AUTOSAR version */
    #if ((NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Netc_EthSwt_Ip_Types.h and Eth_GeneralTypes.h are different"
    #endif
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Types.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

#define NETC_ETHSWT_IP_NUMBER_OF_PSEUDO_PORT (1U)  /*!< number of pseudoport */
#define NETC_ETHSWT_IP_NUMBER_OF_PORTS       3  /*!< number of ports */
#define NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS   (2U)  /*!< number of mac ports*/
#define NETC_ETHSWT_IP_NUMBER_OF_VID_PER_PORT (255U)   /*!< 3 number of vid per port */

#define NETC_ETHSWT_IP_FDB_KEYE_DATA_ITEMS                 (3U)      /*!< 3 uint32 items of FDB table KEYE DATA Format */
#define NETC_ETHSWT_IP_FDB_SEARCH_CRITERIA_DATA_ITEMS      (8U)      /*!< 8 uint32 items of FDB table SEARCH CRITERIA Format */

#define NETC_ETHSWT_IP_TABLE_CFGEDATA_ITEMS                   (4U)      /*!< 4 uint32 items of CFGE_DATA Format for Tables */

#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN      (53U)      /*!< 53 uint32 items of Ingress Port Filter Table KEYE_DATA Format */

#define NETC_ETHSWT_IP_NUMBER_OF_PROFILES (2U)
#define NETC_ETHSWT_IP_NUMBER_OF_PCP_DEI (16U)
#define NETC_ETHSWT_IP_NUMBER_OF_PCP     (8U)
#define NETC_ETHSWT_IP_NUMBER_OF_IPV     (8U)
#define NETC_ETHSWT_IP_NUMBER_OF_DR      (4U)

#define NETC_ETHSWT_IP_EFMEID_FOR_MIRRORING                (0U)        /* Default egress frame modification entry id for mirroring */
#define NETC_ETHSWT_IP_EFM_LEN_CHANGE_FOR_MIRRORING        (4U)        /* EFM_LEN_CHANGE value for double tagging when modifying mirrored egress frames */
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
 * @implements Netc_EthSwt_Ip_FdbEntryDataType_struct
 */
typedef struct
{
    uint8 MacAddr[6];                                   /*!< MAC Address - This field is defined in network byte order(big-endian). Most significant byte of the MAC address is stored at the lowest byte offset of this field.*/
    uint16 FID;                                         /*!< Filtering ID - used to connect the FDB table with the VLAN Filter Table.*/
                                                        /*!<              - it can be set to 0 when shared learning is used.*/
    uint32 SwitchPortEgressBitMask;                     /*!< Port Bitmap - This field identifies the destination port(s) to which the frame is to be forwarded.*/
                                                        /*!<             - The destination port(s) are represented as a bitmap, where each bit of the bitmap corresponds to a port on the switch.*/
                                                        /*!<             - Least significant bit of the bitmap corresponds to the smallest port number; */
                                                        /*!<             - i.e. bit offset 0 of the bitmap corresponds to port numbered 0, bit offset 1 to port numbered 1, and so on. */
    uint32 ET_EID;                                      /*!< Egress Treatment Table Entry ID - This field specifies the index (or base index) to be used when accessing the Egress Treatment table.*/
                                                        /*!<                                 - This field is valid if the OETEID Option field is set to value other than 00b.*/
                                                        /*!<                                 - When no egress treatment needed - set entry ID to 0xFFFFFFFFUL. */
    uint8 CutThroughDisable;                            /*!< CTD - 00b = Do not override cut-through state.*/
                                                        /*!<     - 01b = Disable cut-through for the outgoing port specified in the EPORT. Cut-through is not disabled for the other ports specified in destination port bitmap.*/
                                                        /*!<     - 10b = Disable cut-through for all ports specified in the destination port bitmap.*/
                                                        /*!<     - 11b = Reserved.*/
                                                        /*!<     - Note: Cut-through should be disabled for any outgoing port where its Egress Treatment table entry specifies an Egress Sequence Recovery action. */
    uint8 OverridETEID;                                 /*!< OETEID - 00b = No egress packet processing actions specified. Do not override ET_EID (and associated applicability port bitmap).*/
                                                        /*!<        - 01b = Single-port Egress Treatment table access. Only one port requires egress packet processing. That port identifier is specified in the EPORT field of this entry. */
                                                        /*!<              = The applicability port bitmap is set with a 1 for the port that is been identified in the EPORT field of this entry. For other ports, the applicability port bitmap is set to 0. */
                                                        /*!<              = The group assigned to packets matching this entry will have a single Egress Treatment table entry, for the port identified in the EPORT field of this entry. */
                                                        /*!<        - 10b = Multi-port packed Egress Treatment table access. Applicability port bitmap is set to the port bitmap specified in PORT_BITMAP field of this entry.*/
                                                        /*!<              = The group assigned to packets matching this entry will have an Egress Treatment table entry for each port set to 1 in the applicability port bitmap.*/
                                                        /*!<        - 11b = Multi-port absolute Egress Treatment table access. Applicability port bitmap is set with 1 for all ports. */
                                                        /*!<              = The group assigned to packets matching this entry will have Egress Treatment table entries for all ports on the switch. */
    uint8 EgressPort;                                   /*!< EPORT - This field specifies the identifier of the port requiring egress packet processing when the Override ET_EID Option field is set to 01b (single-port Egress Treatment table access option). */
                                                        /*!<       - The port is expressed as an integer value, and must correspond to a port that is set in the destination port bitmap.*/
                                                        /*!<       - Valid if OETEID = 1 or CTD = 1.*/
    boolean IngressMirroringEnable;                     /*!< IMIRE - 0b = No ingress mirroring action specified in this entry.*/
                                                        /*!<       - 1b = The frame is mirrored to the mirror destination specified in the IMDCR0 register. */
                                                        /*!<       - Mirroring should never be handled from the entries if the AUTOSAR mirroring is used.*/
    boolean DynamicEntry;                               /*!< DYNAMIC - This field determines whether the entry is static or dynamic. */
                                                        /*!<         - 0b = Static entry, */
                                                        /*!<         - 1b = Dynamic entry */
    boolean TimeStampCapture;                           /*!< TIMECAPE - set allways to 'false' */
} Netc_EthSwt_Ip_FdbEntryDataType;

/*!
 * @brief defines Vlan Filter entries.
 * @implements Netc_EthSwt_Ip_VlanFilterEntryDataType_struct
 */
typedef struct
{
    uint32 PortMembershipBitmap;                        /*!< Port Membership Bitmap - on this field are set the memberships of certain ports to a specified VLAN ID. */
    uint16 VlanID;                                      /*!< Vlan ID */
    uint16 FID;                                         /*!< Filtering ID - The Filtering ID (FID) is a locally significant identifier (global to the switch), */
                                                        /*!<              - that is used as a key value when hardware performs a lookup into the FDB table and the L2 IPV4 Multicast Filter table.*/
                                                        /*!<              - The FID is used to identify a set of VIDs, which in turn allows sharing of the same address (MAC, IP) between multiple VIDs during lookups into the FDB table and L2 IPV4 Multicast Filter table.*/
                                                        /*!<              - This allows the support of the independent and shared learning modes.*/
    uint32 EgressTreatmentApplicabilityPortBitmap;      /*!< ETA_PORT_BITMAP - This field specifies the Egress Treatment applicability port bitmap. See BASE_ET_EID field for more details. */
                                                        /*!<                 - All ports that have their bit set to 1 in the Egress Treatment applicability port bitmap must member of this VLAN.*/
                                                        /*!<                 - Valid if BASE_ET_EID is not NULL.*/
                                                        /*!<                 - Note: Bits beyond the valid range of switch ports will be ignored.*/
    uint32 BaseEgressTreatmentEntryID;                  /*!< BASE_ET_EID - This field is used to convey the egress packet processing actions to be applied to packets matching this entry.*/
                                                        /*!<             - The egress packet processing actions are specified in the Egress Treatment table, where each table entry contains the egress packet   */
                                                        /*!<             - processing actions to be applied to a scope of packets (e.g. packets from a particular VLAN) exiting on a particular egress port of the switch.*/
                                                        /*!<             - The means by which one specifies the Egress Treatment table entries to be accessed, is through the Egress Treatment group.*/
                                                        /*!<             - Within the hardware, an Egress Treatment group is determined by a base index (first Egress Treatment table entry of the group) and */
                                                        /*!<             - an applicability port bitmap (a bitmap corresponding to all ports of the switch) which indicates (with a 1) which ports */
                                                        /*!<             - have Egress Treatment table entries present.*/
    uint8 SpanningTreeGroupMemberId;                    /*!< STG_ID - This field specifies the spanning tree protocol group to which this VLAN belongs.*/
                                                        /*!<        - The value in this field is expressed as an integer and is used to index the spanning tree protocol per-port state register (BPSTGSR) to */
                                                        /*!<        - obtain the port spanning tree protocol state. The BPSTGSR register maintains spanning tree protocol port states for every spanning tree protocol group.*/
                                                        /*!<        - The information retrieved from this register is used to perform spanning tree protocol (STP) port state checking */
                                                        /*!<        - during ingress VLAN filtering processing and egress VLAN filtering processing.*/
    uint8 MacForwardingOptions;                         /*!< MFO - 00b = Reserved.*/
                                                        /*!<     - 01b = No FDB lookup is performed, the frame is flooded.*/
                                                        /*!<     - 10b = FDB lookup is performed, and if there is no match, the frame is flooded.*/
                                                        /*!<     - 11b = FDB lookup is performed, and if there is no match, the frame is discarded.*/
    uint8 MacLearningOptions;                           /*!< MLO - 000b = Reserved. */
                                                        /*!<     - 001b = Disable MAC learing. Mac learning is not performed during the forwarding processing.*/
                                                        /*!<     - 010b = Hardware MAC learning is performed.*/
                                                        /*!<     - 011b = Software MAC learning secure. A MAC learning lookup is performed into the FDB table. */
                                                        /*!<            = If there is no match, no attempt is made to add a new entry, and the frame is redirect to the switch management port. */
                                                        /*!<            = If there is match, and the entry's port number does not match frame ingress port number,  */
                                                        /*!<            = the frame is redirected to the switch management port if station move is allowed, otherwise the frame is discarded. */
                                                        /*!<     - 101b = Disable MAC learning with SMAC validation. A MAC learning lookup is performed into the FDB table.*/
                                                        /*!<            = If there is no match or there is a match but the ingress port is not a member of the FDB entry,*/
                                                        /*!<            = the frame is discarded and counted against the bridge port discard count register (BPDCR) with discard reason BPDCRR0[MACLNFDR] set to 1.*/
    boolean IpMulticastFloodingEnable;                  /*!< IPMFLE - If IP multicast filtering is performed (IPMFE = 1b, and the frame is identified as a multicast IP packet), and there was no match found,*/
                                                        /*!<        - then the frame is forwarded according to this field.*/
                                                        /*!<        - 0b = IP Multicast Flooding disabled, frame is discarded.*/
                                                        /*!<        - 1b = IP Multicast Flooding enabled, frame is flooded.*/
                                                        /*!<        - If IP multicast filtering is disabled (IPMFE = 0b), this field is ignored by hardware.*/
    boolean IpMulticastFilteringEnable;                 /*!< IPMFE - This field specifies whether IP multicast filtering is to be performed. */
                                                        /*!<       - IP multicast filtering is accomplished by executing one or two exact match lookups: Source Specific Multicast (SSM) exact match lookup (if at least one entry added) */
                                                        /*!<       - utilizing both source IP address and destination IP address,and if there is no match, followed by Any Source Multicast (ASM) exact match lookup (if at least one entry added) */
                                                        /*!<       - utilizing destination IP address only. If an entry is found, the frame is forwarded according to the matched table entry. */
                                                        /*!<       - If no entry is found, then the frame will be forwarded according to IPMFLE.*/
                                                        /*!<       - 0b = No IP multicast filtering is performed.*/
                                                        /*!<       - 1b = If the frame is identified as a multicast IP packet, then IP multicast filtering isperformed.*/
                                                        /*!<            = If the frame is not identified as an IP multicast packet, the IP multicast filtering is not performed.*/
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
#define NETC_ETHSWT_IP_RATE_POLICER_TABLE_ID            (10U)    /*!< Rate Policer table id */
#define NETC_ETHSWT_IP_INGRESS_STREAM_IDEN_TABLE_ID     (30U)    /*!< Ingress Stream Identification table id */
#define NETC_ETHSWT_IP_INGRESS_STREAM_TABLE_ID          (31U)    /*!< Ingress Stream table id */
#define NETC_ETHSWT_IP_INGRESS_STREAM_FILTER_TABLE_ID   (32U)    /*!< Ingress Stream Filter table id */
#define NETC_ETHSWT_IP_INGRESS_SEQ_GENERATION_TABLE_ID  (34U)    /*!< Ingress Sequence Generation table id */
#define NETC_ETHSWT_IP_EGRESS_SEQ_RECOVERY_TABLE_ID     (35U)    /*!< Egress Sequence Recovery table id */
#define NETC_ETHSWT_IP_STREAM_GATE_INSTANCE_TABLE_ID    (36U)    /*!< Stream Gate Instance table id */
#define NETC_ETHSWT_IP_STREAM_GATE_CTRL_LIST_TABLE_ID   (37U)    /*!< Stream Gate Control List table id */
#define NETC_ETHSWT_IP_CLASS_SCHEDULER_TABLE_ID         (23U)    /*!< ETM Class Scheduler table id */
#define NETC_ETHSWT_IP_INGRESS_STREAM_COUNT_TABLE_ID    (38U)    /*!< INgress Stream Count table id */

#define NETC_ETHSWT_IP_BD_ENTRY_EXIST              (1U)     /*!< BD entry exist */
#define NETC_ETHSWT_IP_BD_ENTRY_NOT_EXIST          (0U)     /*!< BD entry not exist*/

#define NETC_ETHSWT_IP_BD_NULL_ENTRY_ID            (0xFFFFFFFFUL)       /*!< BD null entry */

/*!
 * @brief defines CBDR status type.
 */
typedef uint32 Netc_EthSwt_Ip_CBDRStatusType;
#define NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS                                           (0x0UL)     /*!< cbdr status success */
#define NETC_ETHSWT_IP_CBDRSTATUS_INDEX_ERROR                                      (0x1UL)     /*!< index of ring should be 0 or 1 */
#define NETC_ETHSWT_IP_CBDRSTATUS_RINGFULL                                         (0x2UL)     /*!< Ring is full */
#define NETC_ETHSWT_IP_CBDRSTATUS_RR_ERROR                                         (0x3UL)     /*!< The hardware does not consume the command, or the operation has not finished by hardware. */
#define NETC_ETHSWT_IP_CBDRSTATUS_NUMMATCHED_ERROR                                 (0x4UL)     /*!< The NUM_MATCHED field should be 1 when the entry exists for any commands */
#define NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR                               (0x5UL)     /*!< Access_method should be 0, 1, or 2, or the command is not supported by this access method */
#define NETC_ETHSWT_IP_CBDRSTATUS_TABLE_OPERATION_TIMEOUT                          (0x6UL)     /*!< Table operations timeout for commands like add, query, delete etc. */
#define NETC_ETHSWT_IP_CBDRSTATUS_INVALID_TABLE_ID                                 (0x080UL)   /*!< Invalid table ID */
#define NETC_ETHSWT_IP_CBDRSTATUS_NOT_SUPPORTED_ACCESS_METHOD                      (0x081UL)   /*!< Access method specified is not supported */
#define NETC_ETHSWT_IP_CBDRSTATUS_TABLE_INDEX_OUTOFRANGE                           (0x082UL)   /*!< Table index out of range */
#define NETC_ETHSWT_IP_CBDRSTATUS_BUFFER_NOT_SUFFICIENT                            (0x083UL)   /*!< Request data buffer size or response data buffer size is not sufficient */
#define NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD                                      (0x084UL)   /*!< Invalid command */
#define NETC_ETHSWT_IP_CBDRSTATUS_REQUEST_DATA_BUFFER_ERROR                        (0x085UL)   /*!< Request Data buffer error */
#define NETC_ETHSWT_IP_CBDRSTATUS_ECC_OR_PARITY_ERROR                              (0x086UL)   /*!< Multi-bit ECC or parity error observed during command processing */
#define NETC_ETHSWT_IP_CBDRSTATUS_EXCEEDED_HASH_ENTRY_LIMIT                        (0x087UL)   /*!< Exceeded hash entry limit */
#define NETC_ETHSWT_IP_CBDRSTATUS_EXCEEDED_MAXIMUM_HASH_COLLISION_CHAIN_LIMIT      (0x088UL)   /*!< Exceeded maximum hash collision chain limit */
#define NETC_ETHSWT_IP_CBDRSTATUS_INVALID_ENTRY_ID                                 (0x089UL)   /*!< Invalid ENTRY_ID for HW Managed tables (hash, TCAM) */
#define NETC_ETHSWT_IP_CBDRSTATUS_SEARCH_CMD_FILLED_THE_RESPONSE_DATA_BUFFER       (0x08AUL)   /*!< Search command filled the response data buffer before completing the command */
#define NETC_ETHSWT_IP_CBDRSTATUS_CMD_FOR_INDEX_TABLE_BEFORE_OSR                   (0x08BUL)   /*!< Command for index table before OSR[ITM_STATE]=0 */
#define NETC_ETHSWT_IP_CBDRSTATUS_INVALID_QUERRY_ACTION                            (0x08CUL)   /*!< Query action specifed is invalid */
#define NETC_ETHSWT_IP_CBDRSTATUS_INVALID_TABLE_ACCESS_PRIVILEGE                   (0x08DUL)   /*!< Invalid table access privilege */
#define NETC_ETHSWT_IP_CBDRSTATUS_SYSTEM_BUS_READ_ERROR                            (0x08EUL)   /*!< System Bus Read Error encountered while processing the command. */
#define NETC_ETHSWT_IP_CBDRSTATUS_SYSTEM_BUS_WRITE_ERROR                           (0x08FUL)   /*!< System Bus Write Error encountered while processing the command. */
#define NETC_ETHSWT_IP_CBDRSTATUS_CLIENT_FAULT                                     (0x090UL)   /*!< Client encountered a fault while processing the command. */
#define NETC_ETHSWT_IP_CBDRSTATUS_RESERVED_ERROR                                   (0x091UL)   /*!< 0x091 to 0x0FF = reserved */
#define NETC_ETHSWT_IP_CBDRSTATUS_TABLE_SPECIFIC_ERROR                             (0x100UL)   /*!< 0x100 to 0xFFF = Table specific error codes */
#define NETC_ETHSWT_IP_CBDRSTATUS_UPTATE_EXISTING_ADMIN_GATE_CONTROL               (0x0D1UL)   /* Update action attempted on an existing admin gate control. An existing admin gate control list cannot be modified, Delete admin gate control list first before creating a new admin list. (Use update action with ADMIN_CONTROL_LIST_LENGTH =0 to perform delete). */
#define NETC_ETHSWT_IP_CBDRSTATUS_UPDATE_ACTION_EXCEED_MAX_GCL_LEN                 (0x0D2UL)   /* Update action attempted exceeds TGSTCAPR[MAX_GCL_LEN]. */
#define NETC_ETHSWT_IP_CBDRSTATUS_UPDATE_ACTION_EXCEED_NUM_WORDS                   (0x0D3UL)   /* Update action attempted exceeds TGSTCAPR[NUM_WORDS]. */
#define NETC_ETHSWT_IP_CBDRSTATUS_INSUFFICIENT_RESOURCES                           (0x0D4UL)   /* Insufficient resources to perform the requested operation (not enough free time gate list entries) */
#define NETC_ETHSWT_IP_CBDRSTATUS_TRANSMITTING_TIME_NOT_SUFFICIENT                 (0x0D5UL)   /* Update action attempted with ADMIN_CYCLE_TIME, ADMIN_TIME_INTERVAL_GE_i or truncated ADMIN_TIME_INTERVAL_GE_n due ADMIN_CYCLE_TIME specified is not sufficient to transmit 64 byte of frame data + header overhead. Where header overhead = PTXSDUOR[PTXSDUOR] + PTXSDUOR[PPDU_BCO]. */
#define NETC_ETHSWT_IP_CBDRSTATUS_ADMIN_BASE_TIME_IS_MORE_THAN_1S                  (0x0D6UL)   /* Update action attempted with ADMIN_BASE_TIME specified is more than one second in the past from tcs advance time. */
#define NETC_ETHSWT_IP_CBDRSTATUS_ADMIN_CYCLE_TIME_OVERFLOW                        (0x0D7UL)   /* Update action attempted with ADMIN_CYCLE_TIME + ADMIN_CYCLE_TIME_EXT is greater than 2^32-1. */
#define NETC_ETHSWT_IP_CBDRSTATUS_RETRY_QUERY                                      (0x0D8UL)   /* Query action issued when config change occurred. Retry query. */
#define NETC_ETHSWT_IP_CBDRSTATUS_INVALID_ADMIN_HR_CB_GE                           (0x0D9UL)   /* Update action attempted with ADMIN_HR_CB_GE_i set to an invalid value. */

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
 * @implements Netc_EthSwt_Ip_CommandsType_enum
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
* @brief Rate Policer Table FEE_DATA Format
*/
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN_SHIFT              (0U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN_MASK               (0x00000001UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN_MASK)

/*!
* @brief Rate Policer Table CFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_SHIFT            (0U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK             (0x00000001UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK)

#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_SHIFT             (1U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_MASK              (0x00000002UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_MASK)

#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM_SHIFT              (2U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM_MASK               (0x00000004UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM_MASK)

#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF_SHIFT              (3U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF_MASK               (0x00000008UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF_MASK)

#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_SHIFT            (4U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_MASK             (0x00000010UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_MASK)

#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_SHIFT        (5U)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_MASK         (0x00000060UL)
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE(x)           (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_SHIFT)) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_MASK)

/*!
* @brief Ingress Stream Table CFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE_SHIFT                (0U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE_MASK                 (0x00000001UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV_SHIFT                (4U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV_MASK                 (0x000000F0UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV_SHIFT               (8U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV_MASK                (0x00000100UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR_SHIFT                 (9U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR_MASK                  (0x00000600UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR_SHIFT                (11U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR_MASK                 (0x00000800UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_SHIFT              (12U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_MASK               (0x00001000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_SHIFT           (13U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_MASK            (0x00002000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD_SHIFT               (15U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD_MASK                (0x00008000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA_SHIFT               (16U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA_MASK                (0x00030000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP_SHIFT                (18U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP_MASK                 (0x00040000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI_SHIFT               (19U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI_MASK                (0x00080000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR_SHIFT                 (20U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR_MASK                  (0x00F00000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA_SHIFT                 (24U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA_MASK                  (0x07000000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_SHIFT            (27U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_MASK             (0x18000000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU_SHIFT               (0U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU_MASK                (0x0000FFFFUL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_SHIFT         (16U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_MASK          (0x007F0000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG(x)            (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT_SHIFT              (23U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT_MASK               (0x0F800000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID_SHIFT             (28U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID_MASK              (0x30000000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD_SHIFT                (30U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD_MASK                 (0xC0000000UL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_SHIFT      (0U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_MASK       (0x00FFFFFFUL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP(x)         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_MASK)

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_SHIFT              (0U)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_MASK               (0x0000FFFFUL)
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_SHIFT)) & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_MASK)

/*!
* @brief Ingress Stream Filter Table KEYE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_SHIFT          (0U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_MASK           (0x00000007UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_MASK)

/*!
* @brief Ingress Stream Filter Table CFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_SHIFT                (0U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_MASK                 (0x0000000FUL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_SHIFT               (4U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_MASK                (0x00000010UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_SHIFT                 (5U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_MASK                  (0x00000060UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_SHIFT                (7U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_MASK                 (0x00000080UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_SHIFT              (8U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_MASK               (0x00000100UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_SHIFT           (9U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_MASK            (0x00000200UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_SHIFT               (10U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_MASK                (0x00000400UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_SHIFT                (11U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_MASK                 (0x00000800UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_SHIFT                (12U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_MASK                 (0x00001000UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_SHIFT            (13U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_MASK             (0x00006000UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_MASK)

#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_SHIFT               (16U)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_MASK                (0xFFFF0000UL)
#define NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_SHIFT)) & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_MASK)

/*!
 * @brief Stream Gate Instance Table Request Data Buffer ACFGEU (Admin Configuration Element Update.) field.
 */
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_ACFGEU_SHIFT                 (0U)
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_ACFGEU_MASK                  (0x00000001UL)
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_ACFGEU(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_REQFMT_ACFGEU_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_REQFMT_ACFGEU_MASK)

/*!
 * @brief Stream Gate Instance Table Request Data Buffer CFGEU (Configuration Element Update) field.
 */
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_CFGEU_SHIFT                  (1U)
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_CFGEU_MASK                   (0x00000002UL)
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_CFGEU(x)                     (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_REQFMT_CFGEU_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_REQFMT_CFGEU_MASK)

/*!
 * @brief Stream Gate Instance Table Request Data Buffer SGISEU (Stream Gate Instance State Element Update) field.
 */
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_SGISEU_SHIFT                 (2U)
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_SGISEU_MASK                  (0x00000004UL)
#define NETC_ETHSWT_IP_SGITABLE_REQFMT_SGISEU(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_REQFMT_SGISEU_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_REQFMT_SGISEU_MASK)

/*!
* @brief Stream Gate Instance Table CFGE_DATA config bits Format
*/
/* Octets Exceeded Enable */
#define NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN_SHIFT            (0U)
#define NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN_MASK             (0x00000001UL)
#define NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN_MASK)

/* Invalid Receive Enable */
#define NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN_SHIFT            (1U)
#define NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN_MASK             (0x00000002UL)
#define NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN_MASK)

/* Protocol/Service Data Unit */
#define NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE_SHIFT          (2U)
#define NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE_MASK           (0x0000000CUL)
#define NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE_MASK)

/*!
* @brief Stream Gate Instance Table ICFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV_SHIFT             (0U)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV_MASK              (0x0000000FUL)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV_MASK)

#define NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV_SHIFT            (4U)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV_MASK             (0x00000010UL)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV_MASK)

/* Gate State */
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_GST_SHIFT             (5U)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_GST_MASK              (0x00000020UL)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_GST(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_ICFGE_GST_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_ICFGE_GST_MASK)

/* Cut Through Disabled */
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD_SHIFT             (6U)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD_MASK              (0x00000040UL)
#define NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD_MASK)

/*!
 * @brief ICFGE_DATA Gate State data format enum type.
 * This field specifies the gate state to use before the administrative stream gate control list takes affect.
 */
typedef uint32 Netc_EthSwt_Ip_SGITABLE_GateStateType;
#define NETC_ETHSWT_IP_SGITABLE_GATE_CLOSE                  (0x0U)      /*!< 0b = Closed; frames are not permitted to pass through. */
#define NETC_ETHSWT_IP_SGITABLE_GATE_OPEN                   (0x1U)      /*!< 1b = Open; frames are permitted to pass through. */

/*!
* @brief Stream Gate Instance Table SGISE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_SGITABLE_SGISE_OEX_SHIFT                 (0U)
#define NETC_ETHSWT_IP_SGITABLE_SGISE_OEX_MASK                  (0x00000001UL)
#define NETC_ETHSWT_IP_SGITABLE_SGISE_OEX(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_SGISE_OEX_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_SGISE_OEX_MASK)

#define NETC_ETHSWT_IP_SGITABLE_SGISE_IRX_SHIFT                 (1U)
#define NETC_ETHSWT_IP_SGITABLE_SGISE_IRX_MASK                  (0x00000002UL)
#define NETC_ETHSWT_IP_SGITABLE_SGISE_IRX(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_SGISE_IRX_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_SGISE_IRX_MASK)

#define NETC_ETHSWT_IP_SGITABLE_SGISE_STATE_SHIFT               (2U)
#define NETC_ETHSWT_IP_SGITABLE_SGISE_STATE_MASK                (0x0000001CUL)
#define NETC_ETHSWT_IP_SGITABLE_SGISE_STATE(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGITABLE_SGISE_STATE_SHIFT)) & NETC_ETHSWT_IP_SGITABLE_SGISE_STATE_MASK)

/*!
* @brief Stream Gate Control List Table CFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN_SHIFT             (0U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN_MASK              (0x000000FFUL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV_SHIFT             (16U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV_MASK              (0x00010000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV_SHIFT              (17U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV_MASK               (0x001E0000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD_SHIFT              (21U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD_MASK               (0x00200000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST_SHIFT             (22U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST_MASK              (0x00400000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM_SHIFT                 (0U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM_MASK                  (0x00FFFFFFUL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV_SHIFT                 (24U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV_MASK                  (0x0F000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV_SHIFT                (28U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV_MASK                 (0x10000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD_SHIFT                 (29U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD_MASK                  (0x20000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD(x)                    (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN_SHIFT               (30U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN_MASK                (0x40000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN_MASK)

#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST_SHIFT                (31U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST_MASK                 (0x80000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST(x)                   (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST_MASK)

/*!
 * @brief Stream Gate Control List Table SGCLSE_DATA format enum type.
 * This field indicates whether or not a stream gate control list (SGCL) is in-use in a Stream Gate Instance (SGI).
 */
typedef uint32 Netc_EthSwt_Ip_SGCLTABLE_RefCountType;
#define NETC_ETHSWT_IP_SGCLTABLE_NOT_INUSE_BYSGI                (0x00U)      /*!< Not in-use by an SGI. */
#define NETC_ETHSWT_IP_SGCLTABLE_INUSE_BYSGI                    (0x01U)      /*!< In-use by an SGI. */
#define NETC_ETHSWT_IP_SGCLTABLE_REFCOUNT_RESERVED              (0x02U)      /*!< others reserved. */

/*!
* @brief Stream Gate Control List Table SGCLSE_DATA Format*/
#define NETC_ETHSWT_IP_SGCLTABLE_SGCLSE_REFCOUNT_SHIFT          (0U)
#define NETC_ETHSWT_IP_SGCLTABLE_SGCLSE_REFCOUNT_MASK           (0x000000FFUL)
#define NETC_ETHSWT_IP_SGCLTABLE_SGCLSE_REFCOUNT(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_SGCLSE_REFCOUNT_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_SGCLSE_REFCOUNT_MASK)

typedef uint32 Netc_EthSwt_Ip_ISQGTABLE_SQTagType;
#define NETC_ETHSWT_IP_ISQGTABLE_RSVDTYPE                       (0x00U)      /*!< reserved. */
#define NETC_ETHSWT_IP_ISQGTABLE_DRAFT20_RTAG                   (0x01U)      /*!< 802.1CB draft 2.0 R-TAG. */
#define NETC_ETHSWT_IP_ISQGTABLE_RTAG                           (0x02U)      /*!< 802.1CB R-TAG.. */
#define NETC_ETHSWT_IP_ISQGTABLE_HSRTAG                         (0x03U)      /*!< HSR Tag. */

#define NETC_ETHSWT_IP_ESQRTABLE_ANYTAG                         (0x00U)     /*!< Accept ANY tag. */
#define NETC_ETHSWT_IP_ESQRTABLE_DRAFT20_RTAG                   (0x01U)     /*!< Accept 802.1CB draft 2.0 R-TAG. */
#define NETC_ETHSWT_IP_ESQRTABLE_RTAG                           (0x02U)     /*!< Accept 802.1CB R-TAG. */
#define NETC_ETHSWT_IP_ESQRTABLE_HSRTAG                         (0x03U)     /*!< Accept HSR Tag. */

/*!
* @brief Ingress Sequence Generation Table CFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_ISQGTABLE_CFGE_SQTAG_SHIFT               (0U)
#define NETC_ETHSWT_IP_ISQGTABLE_CFGE_SQTAG_MASK                (0x00000007UL)
#define NETC_ETHSWT_IP_ISQGTABLE_CFGE_SQTAG(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISQGTABLE_CFGE_SQTAG_SHIFT)) & NETC_ETHSWT_IP_ISQGTABLE_CFGE_SQTAG_MASK)

/*!
* @brief Egress Sequence Recovery Table CFGE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG_SHIFT             (0U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG_MASK              (0x00000007UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ_SHIFT           (3U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ_MASK            (0x00000008UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG_SHIFT            (4U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG_MASK             (0x00000010UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE_SHIFT           (5U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE_MASK            (0x00000020UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL_SHIFT             (8U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL_MASK              (0x00007F00UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL_SHIFT            (16U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL_MASK             (0x0FFF0000UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP_SHIFT             (0U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP_MASK              (0x00000FFFUL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP_MASK)

/*!
* @brief Egress Sequence Recovery Table SRSE_DATA config bits Format
*/
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRNUM_SHIFT            (0U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRNUM_MASK             (0x0000FFFFUL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRNUM(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRNUM_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRNUM_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY_SHIFT           (16U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY_MASK            (0x00010000UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_LCE_SHIFT               (17U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_LCE_MASK                (0x00020000UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_LCE(x)                  (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_LCE_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_LCE_MASK)

#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS_SHIFT             (18U)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS_MASK              (0x3FFC0000UL)
#define NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS_SHIFT)) & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS_MASK)

/*!
* @brief Ingres Stream Identification (ISI) Table KEYE_DATA bits Format
*/
#define NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE_SHIFT          (0U)
#define NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE_MASK           (0x00000003UL)
#define NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE_SHIFT)) & NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE_MASK)

#define NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_SHIFT        (2U)
#define NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_MASK         (0x0000007CUL)
#define NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID(x)           (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_SHIFT)) & NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_MASK)

#define NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_SHIFT              (7U)
#define NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_MASK               (0x00000080UL)
#define NETC_ETHSWT_IP_ISITABLE_KEYE_SPM(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_SHIFT)) & NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_MASK)

typedef uint32 Netc_EthSwt_Ip_KeyTypeIdxType;
#define NETC_ETHSWT_IP_SWT_KEYTYPE_0                        (0x00U)         /* Switch function, key construction is specified in ISIDKC0CR0 */
#define NETC_ETHSWT_IP_SWT_KEYTYPE_1                        (0x01U)         /* Switch function, key construction is specified in ISIDKC1CR0 */
#define NETC_ETHSWT_IP_SWT_KEYTYPE_2                        (0x02U)         /* Switch function, key construction is specified in ISIDKC2CR0 */
#define NETC_ETHSWT_IP_SWT_KEYTYPE_3                        (0x03U)         /* Switch function, key construction is specified in ISIDKC3CR0 */
#define NETC_ETHSWT_IP_ENETC_KEYTYPE_0                      (0x00U)         /* Enetc function, key construction is specified in ISIDKC0CR0 */
#define NETC_ETHSWT_IP_ENETC_KEYTYPE_1                      (0x01U)         /* Enetc function, key construction is specified in ISIDKC1CR0 */

typedef uint32 Netc_EthSwt_Ip_SrcPortMasqIdxType;
#define NETC_ETHSWT_IP_MATCH_FROM_SWT_PORTS                 (0x00U)         /* Match frames from switch port(s). */
#define NETC_ETHSWT_IP_MATCH_FROM_SWT_MANAGEMENT_PORTS      (0x01U)         /* Match frame from switch management port(s) that has switch port masquerading. */

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
} Netc_EthSwt_Ip_ReqHeaderTableOperationDataType;

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
 * @brief Rate policer Table Service Data Unit enum type.
 */
typedef enum
{
    NETC_ETHSWT_IP_PPDU = 0U,       /*!< Physical Layer PDU */
    NETC_ETHSWT_IP_MPDU = 1U,       /*!< MAC PDU */
    NETC_ETHSWT_IP_MSDU = 2U,       /*!< MAC SDU */
    NETC_ETHSWT_IP_RSDTYPE = 3U     /* reservered type */
}Netc_EthSwt_Ip_SDUType;

/*!
 * @brief Rate Policer Table CFGE_DATA Format.
 */
typedef struct {
    uint32 Cfge_Cir;            /*!< Committed Information Rate (CIR) field */
    uint32 Cfge_Cbs;            /*!< Committed Burst SizeExpressed (CBS) field */
    uint32 Cfge_Eir;            /*!< Excess Information Rate (EIR) field */
    uint32 Cfge_Ebs;            /*!< Excess Burst Size (EBS) field */
    boolean Cfge_Mren;          /*!< Mark All Frames Red Enable, 0:disable, 1:enable */
    boolean Cfge_Doy;           /*!< Drop on Yellow, 0:not dropped, 1:dropped */
    boolean Cfge_Cm;            /*!< Color mode, 0:color blind, 1:color aware */
    boolean Cfge_Cf;            /*!< Coupling flag, 0:C and E token buckets are not coupled. 1:C and E token buckets are coupled*/
    boolean Cfge_Ndor;          /*!< No Drop on Red, 0:frames marded "red" are alwayts dropped, 1: not dropped */
    Netc_EthSwt_Ip_SDUType Cfge_SduType;     /*!< Service Data Unit Type */
} Netc_EthSwt_Ip_RatePolicerTableCFGEDataType;

/*!
 * @brief Rate Policer Table STSE_DATA Format.
 */
typedef struct {
    uint64 Stse_ByteCount;            /*!< Number of bytes received by the rate policer instance */
    uint32 Stse_DropFrames;           /*!< Number of frames dropped by the rate policer instance */
    uint32 Stse_Dr0GrnFrames;         /*!< Number of frames marked green with DR=0 by the rate policer instance */
    uint32 Stse_Dr1GrnFrames;         /*!< Number of frames marked green with DR=1 by the rate policer instance */
    uint32 Stse_Dr2YlwFrames;         /*!< Number of frames marked yellow with DR=2 by the rate policer instance */
    uint32 Stse_RemarkYlwFrames;      /*!< Number of frames re-marked from green to yellow by the rate policer instance */
    uint32 Stse_Dr3RedFrames;         /*!< Number of frames marked red (DR=3) by the rate policer instance */
    uint32 Stse_RemarkRedFrames;      /*!< Number of frames re-marked from green or yellow to red by the rate policer instance */
    uint32 Stse_Lts;                  /*!< Last timestamp */
    uint32 Stse_CommittedTokenBucketInteger;    /*!< Committed token bucket contents, integer portion */
    uint32 Stse_CommittedTokenBucketFractional; /*!< Committed token bucket contents, fractional portion (31 bits) + sign bit (1 bit, BCS) */
    uint32 Stse_ExcessTokenBucketInteger;       /*!< Excess token bucket contents, integer portion (32 bits)*/
    uint32 Stse_ExcessTokenBucketFractional;   /*!< Excess token bucket contents, fractional portion (31 bits) + sign bit (1 bit, BES) */
} Netc_EthSwt_Ip_RatePolicerTableSTSEDataType;

/*!
 * @brief defines Rate Policer entries.
 *
 */
typedef struct
{
    uint32 RatePolicerEntryId;                  /* Entry ID */
    Netc_EthSwt_Ip_RatePolicerTableCFGEDataType RatePolicerCfgeData;    /* CFGE Data */
    boolean ConfigurationElementUpdate;         /* Update Actions, CFGEU */
    boolean FunctionalEnableElementUpdate;      /* Update Actions, FEEU */
    boolean PolicerStateElementUpdate;          /* Update Actions, PSEU */
    boolean StatisticsElementUpdate;            /* Update Actions, STSEU */
    boolean RatePolicerFunctionEnable;          /* False = The rate policer instance is disabled; True 1b = The rate policer instance is enabled */
} Netc_EthSwt_Ip_RatePolicerEntryDataType;

/*!
 * @brief defines Rate Policer entrie response data.
 *
 */
typedef struct
{
    uint32 RatePolicerEntryId;                  /* Entry ID */
    Netc_EthSwt_Ip_RatePolicerTableSTSEDataType RatePolicerStseData;    /* Statistics Element Data */
    Netc_EthSwt_Ip_RatePolicerTableCFGEDataType RatePolicerCfgeData;    /* CFGE Data */
    boolean RatePolicerFunctionEnable;          /* False = The rate policer instance is disabled; True 1b = The rate policer instance is enabled */
    boolean MarkRedFlag;                        /* 0b = Indicates that the rate policer blocking "mark all frames red" function has not been triggered */
                                                /* 1b = Indicates that all frames arriving at this rate policer are marked red by the rate policer blocking "mark all frames red" function. */
} Netc_EthSwt_Ip_RatePolicerEntryRspDataType;

/*!
 * @brief Forwarding Action data type definitions for Ingress Stream Table.
 */
typedef uint32 Netc_EthSwt_Ip_SwtForwardingActionDataType;
#define NETC_ETHSWT_IP_SWT_DISCARDFRAMES                (0x0U)           /*!< discard frames */
#define NETC_ETHSWT_IP_SWT_REDIRECTFRAMES               (0x1U)           /*!< Re-direct frame to switch management port without any frame modification */
#define NETC_ETHSWT_IP_SWT_STREAMFORWARDING             (0x2U)           /*!< Stream forwarding */
#define NETC_ETHSWT_IP_SWT_BRIDGEFORWARDING             (0x3U)           /*!< 802.1Q bridge forwarding */
#define NETC_ETHSWT_IP_SWT_COPYANDSTREAMFORWARDING      (0x4U)           /*!< Copy to switch management port with specified HR and stream forwarding */
#define NETC_ETHSWT_IP_SWT_COPYANDBRIDGEFORWARDING      (0x5U)           /*!< Copy to switch management port with specified HR and Bridge forwarding */

typedef uint32 Netc_EthSwt_Ip_EnetcForwardingActionDataType;
#define NETC_ETHSWT_IP_ENETC_DISCARDFRAMES                (0x0U)           /*!< discard frames */
#define NETC_ETHSWT_IP_ENETC_ALLOWWITHOUTSIBITMAP         (0x1U)           /*!< Allow without setting the pre L2 filtering SI bitmap. */
#define NETC_ETHSWT_IP_SWT_ALLOWWITHSIBITMAP              (0x2U)           /*!< Allow with setting the pre L2 filtering SI bitmap to the value configured in the SI_MAP field of this entry. */

/*!
 * @brief Override ET_EID data type.
 */
typedef uint32 Netc_EthSwt_Ip_OETEIDIdxType;
#define NETC_ETHSWT_IP_NO_EGRESS_PKT_PROCESSING_ACTIONS_SPECIFIED  (0x0U)      /*!< No egress packet processing actions specified */
#define NETC_ETHSWT_IP_SINGLEPORT_EGRESS_TREATMENT_TABLE_ACCESS     (0x1U)      /*!< Single-port Egress Treatment table access. */
#define NETC_ETHSWT_IP_MULTIPORT_PKT_EGRESS_TREATMENT_TABLE_ACCESS  (0x2U)      /*!< Multi-port packet Egress Treatment table access */
#define NETC_ETHSWT_IP_MULTIPORT_ABS_EGRESS_TREATMENT_TABLE_ACCESS  (0x3U)      /*!< Multi-port absolute Egress Treatment table access */

/*!
 * @brief Cut-Through Disable data type.
 */
typedef uint32 Netc_EthSwt_Ip_CutThroughtDisableIdxType;
#define NETC_ETHSWT_IP_DONOT_OVERRIDE_CUTTHROUGH_STATE          (0x0U)      /*!< Do not override cut-through state */
#define NETC_ETHSWT_IP_DISABLE_CUTTHROUGH_FOR_OUTGOING_PORT     (0x1U)      /*!< Disable cut-through for the outgoing port specified in the EPORT field */
#define NETC_ETHSWT_IP_DISABLE_CUTTHROUGH_FOR_ALL_PORTS         (0x2U)      /*!< Disable cut-through for all ports specified in the destination port bitmap */
#define NETC_ETHSWT_IP_DISABLE_CUTTHROUGH_RESERVED              (0x3U)      /*!< Reserved */

/*!
 * @brief Ingress Sequence Action data type.
 */
typedef uint32 Netc_EthSwt_Ip_IngressSeqActionIdxType;
#define NETC_ETHSWT_IP_FRER_SEQ_GENERATION_FUNC_NOT_PERFORMED   (0x0U)      /*!< FRER sequence generation function is not performed. */
#define NETC_ETHSWT_IP_FRER_SEQ_GENERATION_FUNC_PERFORMED       (0x1U)      /*!< FRER sequence generation function is performed. */

/*!
 * @brief Egress Sequence Recovery Table CFGE_DATA type.
 */
typedef uint32 Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRTnsqIdxType;
#define NETC_ETHSWT_IP_ESQRTABLE_DISCARD_FRAME_AND_COUNT        (0x0U)      /*!< Discard frame and count in both the TAGLESS_PACKETS counter and in the port's PTXDCR register. */
#define NETC_ETHSWT_IP_ESQRTABLE_ACCEPT_FRAME_AND_NORECOVERY    (0x1U)      /*!< Accept frame and do not perform recovery function. */

typedef uint32 Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRAlgIdxType;
#define NETC_ETHSWT_IP_ESQRTABLE_VECTOR_ALGORITHM               (0x0U)      /*!< Vector algorithm. */
#define NETC_ETHSWT_IP_ESQRTABLE_MATCH_ALGORITHM                (0x1U)      /*!< Match algorithm. */

typedef uint32 Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRTypeIdxType;
#define NETC_ETHSWT_IP_ESQRTABLE_SEQUENCY_REC_FUNC              (0x0U)      /*!< Sequence recovery function. */
#define NETC_ETHSWT_IP_ESQRTABLE_INDIVIDUAL_REC_FUNC            (0x1U)      /*!< Individual recovery function. */

/*!
 * @brief Ingress Stream Table CFGE_DATA Format.
 */
typedef struct {
    uint32 IngressSeqGeneration_EID;                         /*!< Ingress Sequence Generation Entry ID */
    uint32 RatePolicer_EID;                                  /*!< Rate Policer Entry ID */
    uint32 StreamGateInstance_EID;                           /*!< Stream Gate Instance Entry ID */
    uint32 IngressFrmModification_EID;                       /*!< Ingress Frame Modification Entry ID */
    uint32 EgressTreatment_EID;                              /*!< Egress Treatment Entry ID */
    uint32 IngressStreamCounter_EID;                         /*!< Ingress Stream counter Index */
    uint32 EgressPortBitMap;                                 /*!< Egress Port bitmap */
    uint16 StationInterfaceMap;                              /*!< Station Interface Map */
    uint16 MaximumServiceDataUnit;                           /*!< Maximum Service Data Unit */
    uint8 IngressFrmModiEntryFrmLenChange;                   /*!< Ingress Frame Modification Entry Frame Length Change */
    uint8 EgressPort;                                        /*!< Egress Port */
    Netc_EthSwt_Ip_OETEIDIdxType OverrideET_EID;             /*!< Override ET_EID */
    Netc_EthSwt_Ip_CutThroughtDisableIdxType CutThrDisable;  /*!< Cut-Trought disable */
    Netc_EthSwt_Ip_SDUType SduType;                          /*!< Service Data Unit type to use for MSDU (Maximum Service Data Unit) field. */
    Netc_EthSwt_Ip_SwtForwardingActionDataType ForwardingActions;   /*!< Forwarding actions */
    uint8 HostReason;                                               /*!< Host reason */
    uint8 DropResilience;                                           /*!< New Drop Resilience (DR) to be assigned to the frame, if ODR is 1. */
    uint8 InternalPriorityValue;                                    /*!< Internal Priority Value (IPV) */
    boolean OverrideStreamGateInstanceEID;                          /*!< Override Stream Gate Instance Entry ID */
    boolean OverrideRatePolicerInstanceEID;                         /*!< Override Rate Policer (instance) ID. */
    Netc_EthSwt_Ip_IngressSeqActionIdxType IngressSeqAction;        /*!< Ingress Sequence Action */
    boolean SrcPortPruningDisable;                                  /*!< Source Port Pruning Disable. */
    boolean TimeStampCaptureEnable;                                 /*!< Timestamp Capture Enable */
    boolean IngressMirroringEnable;                                 /*!< Ingress Mirroring Enable */
    boolean OverrideDR;                                             /*!< Override Drop Resilience (DR) */
    boolean OverrideIPV;                                            /*!< Override Internal Priority Value (IPV) */
    boolean StreamFilteringEnable;                                  /*!< Stream Filtering Enable */
} Netc_EthSwt_Ip_IngressStreamTableCFGEDataType;

/*!
 * @brief defines Ingress Stream entries.
 * @implements Netc_EthSwt_Ip_IngressStreamEntryDataType_struct
 */
typedef struct
{
    uint32 IngressStreamEntryId;                  /* Entry ID */
    Netc_EthSwt_Ip_IngressStreamTableCFGEDataType IngressStreamCfgeData;    /* CFGE Data */
} Netc_EthSwt_Ip_IngressStreamEntryDataType;

/*!
 * @brief Ingress Stream Filter Table CFGE_DATA Format.
 */
typedef struct {
    uint32 RatePolicer_EID;                                         /*!< Rate Policer Entry ID */
    uint32 StreamGateInstance_EID;                                  /*!< Stream Gate Instance Entry ID */
    uint32 IngressStreamCounter_EID;                                /*!< Ingress Stream counter Index */
    uint16 MaximumServiceDataUnit;                                  /*!< Maximum Service Data Unit */
    uint8 InternalPriorityValue;                                    /*!< Internal Priority Value (IPV) */
    uint8 DropResilience;                                           /*!< New Drop Resilience (DR) to be assigned to the frame, if ODR is 1. */
    Netc_EthSwt_Ip_CutThroughtDisableIdxType CutThrDisable;         /*!< Cut-Trought disable */
    Netc_EthSwt_Ip_SDUType SduType;                                 /*!< Service Data Unit type to use for MSDU (Maximum Service Data Unit) field. */
    boolean OverrideIPV;                                            /*!< Override Internal Priority Value (IPV) */
    boolean OverrideDR;                                             /*!< Override Drop Resilience (DR) */
    boolean TimeStampCaptureEnable;                                 /*!< Timestamp Capture Enable */
    boolean IngressMirroringEnable;                                 /*!< Ingress Mirroring Enable */
    boolean OverrideStreamGateInstanceEID;                          /*!< Override Stream Gate Instance Entry ID */
    boolean OverrideRatePolicerInstanceEID;                         /*!< Override Rate Policer (instance) ID. */
} Netc_EthSwt_Ip_IngressStreamFilterTableCFGEDataType;


/*!
 * @brief Define Ingress Stream Counter entries
 */
typedef struct
{
    uint32 RxCount;                                                 /*!< Receive Count. */
    uint32 MSduDropCount;                                           /*!< MSDU (Maximum Service Data Unit) Drop Count. */
    uint32 PolicerDropCount;                                        /*!< Policer Drop Count. */
    uint32 StreamGateDropCount;                                     /*!< Stream Gating Drop Count. */
} Netc_EthSwt_Ip_IngressStreamCountTableSTSEDataType;

/*!
 * @implements Netc_EthSwt_Ip_IngressStreamCountTableRspDataType_struct
 */
typedef struct
{
    uint32 IngressStreamCountId;
    Netc_EthSwt_Ip_IngressStreamCountTableSTSEDataType IngressStreamCountStseData;
} Netc_EthSwt_Ip_IngressStreamCountTableRspDataType;

/*!
 * @brief Ingress Stream Filter Table KEYE_DATA Format.
 */
typedef struct {
    uint32 IngressStream_EID;                           /*!< Ingress Stream Entry ID */
    uint8 Pcp;                                          /*!< Priority Code Point. Outer VLAN TAG PCP of the received frame */
} Netc_EthSwt_Ip_IngressStreamFilterTableKEYEDataType;

/*!
 * @brief defines Ingress Stream Filter entries.
 * @implements Netc_EthSwt_Ip_IngressStreamFilterEntryDataType_struct
 */
typedef struct
{
    Netc_EthSwt_Ip_IngressStreamFilterTableCFGEDataType IngressStreamFilterCfgeData;    /* CFGE Data */
    Netc_EthSwt_Ip_IngressStreamFilterTableKEYEDataType IngressStreamFilterKeyeData;    /* KEYE Data */
    uint32 IngressStreamFilterEntryId;                  /* Entry ID */
} Netc_EthSwt_Ip_IngressStreamFilterEntryDataType;

/*!
 * @brief defines Stream Gate Instance entries.
 * @implements Netc_EthSwt_Ip_StreamGateInstanceEntryDataType_struct
 */
typedef struct
{
    uint32 SGIEntryId;                                      /* Stream Gate Instance Entry ID */
    uint32 AdminSGCLEntryId;                                /* Administrative Stream Gate Control List Entry ID */
    uint64 AdminBaseTime;                                   /* Admin Base Time */
    uint32 AdminCycleTimeExt;                               /* Admin Cycle Time Extension */
    Netc_EthSwt_Ip_SGITABLE_GateStateType Icfge_Gst;        /* Gate State */
    boolean Icfge_Ctd;                                      /* Cut-Through Disable Flag */
    uint8 Icfge_Ipv;                                        /* Internal Priority Value (IPV) */
    Netc_EthSwt_Ip_SDUType SduType;                         /* Protocol/Service Data Unit) */
    boolean Icfge_Oipv;                                     /* Override Internal Priority Value (IPV) */
    boolean Cfge_Oexen;                                     /* Octets Exceeded Enable */
    boolean Cfge_Irxen;                                     /* Invalid Receive Enable */
} Netc_EthSwt_Ip_StreamGateInstanceEntryDataType;

/*!
 * @brief defines Stream Gate Instance entries response data type.
 * @implements Netc_EthSwt_Ip_StreamGateInstanceEntryRspDataType_struct
 */
typedef struct
{
    uint32 SGIEntryId;                                      /* Stream Gate Instance Entry ID */
    uint32 OperationalSGCLEntryID;                          /* Operational Stream Gate Control List Entry ID */
    uint64 ConfigChangeTime;                                /* Configuration Change Time */
    uint64 OperationalBaseTime;                             /* Operational Base Time */
    uint32 OperationalCycleTimeExt;                         /* Oper Cycle Time Extension */
    uint8 SGISEOex;                                         /* Octets Exceeded Flag */
    uint8 SGISEIrx;                                         /* Invalid Receive Flag */
    uint8 SGISEState;                                       /* Current Gate Instance State */
    uint32 AdminSGCLEntryId;                                /* Administrative Stream Gate Control List Entry ID */
    uint64 AdminBaseTime;                                   /* Admin Base Time */
    uint32 AdminCycleTimeExt;                               /* Admin Cycle Time Extension */
    Netc_EthSwt_Ip_SGITABLE_GateStateType Icfge_Gst;        /* Gate State */
    boolean Icfge_Ctd;                                      /* Cut-Through Disable Flag */
    uint8 Icfge_Ipv;                                        /* Internal Priority Value (IPV) */
    Netc_EthSwt_Ip_SDUType SduType;                         /* Protocol/Service Data Unit) */
    boolean Icfge_Oipv;                                     /* Override Internal Priority Value (IPV) */
    boolean Cfge_Oexen;                                     /* Octets Exceeded Enable */
    boolean Cfge_Irxen;                                     /* Invalid Receive Enable */
} Netc_EthSwt_Ip_StreamGateInstanceEntryRspDataType;

/*!
 * @brief defines Stream Gate Control List entries data type.
 */
typedef struct
{
    uint32 SGCL_TimeInterval;                               /* Time Interval for Gate Entry i */
    uint32 SGCL_IntervalOctetsMax;                          /* Interval Octets Maximum for Gate Entry i, */
    uint8 SGCL_Ipv;                                         /* Internal Priority Value for Gate Entry i */
    boolean SGCL_Oipv;                                      /* Override Internal Priority Value for Gate Entry i */
    boolean SGCL_Ctd;                                       /* Cut Through Disable for Gate Entry i */
    boolean SGCL_IntervalOctetMaxEnable;                    /* Interval Octet Maximum Enabled for Gate Entry i, */
    Netc_EthSwt_Ip_SGITABLE_GateStateType SGCL_GateState;   /* Gate State for Gate Entry i, */
} Netc_EthSwt_Ip_SGCLEntriesDataType;

/*!
 * @brief defines Stream Gate Control List table data type.
 * @implements Netc_EthSwt_Ip_SGCLTableDataType_struct
 */
typedef struct
{
    uint32 SGCLEntryId;                                     /* Stream Gate Control List Entry ID */
    uint32 Cfge_CycleTime;                                  /* This field specifies the cycle time of the stream gate control list. */
    uint8 Cfge_ListLength;                                  /* This field indicates the number of entries in the stream gate control list. */
    uint8 Cfge_ExtIpv;                                      /* List Extension Internal Priority Value */
    boolean Cfge_ExtOIPV;                                   /* Extension Override Internal Priority Value */
    boolean Cfge_ExtCtd;                                    /* Extension Cut Through Disabled. 0b = No action. 1b = Cut-through disabled. */
    Netc_EthSwt_Ip_SGITABLE_GateStateType Cfge_ExtGtst;     /* Extension Gate State */
    Netc_EthSwt_Ip_SGCLEntriesDataType *ListEntries;        /* Stream Gate Control List entries pointer */
    Netc_EthSwt_Ip_SGCLTABLE_RefCountType Sgclse_RefCount;  /* Ref count, an element in response data buffer */
} Netc_EthSwt_Ip_SGCLTableDataType;

/*!
 * @brief defines Ingress Sequence Generation table data type.
 * @implements Netc_EthSwt_Ip_ISQGTableDataType_struct
 */
typedef struct
{
    uint32 ISQGEntryId;                                     /* Ingress Sequence Generation table Entry ID */
    Netc_EthSwt_Ip_ISQGTABLE_SQTagType Cfge_SQTagType;      /* This field specifies the sequence tag type to insert for sequence generation. */
    uint16 Sgse_SQGNum;                                     /* This field specifies the next sequence number value to be used in the tag to be added to the frame. */
} Netc_EthSwt_Ip_ISQGTableDataType;

/*!
 * @brief defines Egress Sequence Recovery table request data type.
 * @implements Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType_struct
 */
typedef struct
{
    uint32 EgrSeqRecEntryId;                                        /* egress sequence recovery table Entry ID */
    uint8 Cfge_SQTag;                                               /* Sequence Tag */
    uint8 Cfge_SQRHisLen;                                           /* Sequence Recovery History Length */
    uint16 Cfge_SQRFutureWinLen;                                    /* Sequence Recovery Future Window LengthThis */
    uint16 Cfge_SQRTimeOutPeriod;                                   /* Sequence Timeout Period */
    Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRTnsqIdxType Cfge_SqrTnsq;      /* Sequence Recovery Take No Sequence */
    Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRAlgIdxType Cfge_SqrAlg;        /* Sequence Recovery Algorithm */
    Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRTypeIdxType Cfge_SqrType;      /* Sequence Recovery Function type */
} Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType;

/*!
 * @brief defines Egress Sequence Recovery table response data type.
 * @implements Netc_EthSwt_Ip_EgrSeqRecoveryTableRspDataType_struct
 */
typedef struct
{
    uint32 EgrSeqRecEntryId;                                        /* egress sequence recovery table Entry ID */
    uint64 Stse_InOrderPkts;                                        /* In Order Packets */
    uint64 Stse_OutOfOrderPkts;                                     /* Out of Order Packets */
    uint64 Stse_RoguePkts;                                          /* Rogue Packets */
    uint64 Stse_DuplicatePkts;                                      /* Duplicate Packets */
    uint64 Stse_LostPkts;                                           /* Lost Packets */
    uint64 Stse_TaglessPkts;                                        /* Tag-Less Packets */
    uint32 Stse_SeqRecResets;                                        /* Sequence Recovery Resets */
    uint32 Srse_SqrHistory[4U];                                     /* Recovery History */
    uint16 Srse_SqrNum;                                             /* Sequence Recovery Number */
    uint16 Srse_SqrTimeStamp;                                       /* Sequence Recovery Timestamp */
    boolean Srse_LostCntEnable;                                     /* Lost Count Enable */
    uint8 Srse_TakeAny;                                             /* This field is set to 1 when the recovery function is reset, and cleared after the first frame is received. */
    uint8 Cfge_SQTag;                                               /* Sequence Tag */
    uint8 Cfge_SQRHisLen;                                           /* Sequence Recovery History Length */
    uint16 Cfge_SQRFutureWinLen;                                    /* Sequence Recovery Future Window LengthThis */
    uint16 Cfge_SQRTimeOutPeriod;                                   /* Sequence Timeout Period */
    Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRTnsqIdxType Cfge_SqrTnsq;      /* Sequence Recovery Take No Sequence */
    Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRAlgIdxType Cfge_SqrAlg;        /* Sequence Recovery Algorithm */
    Netc_EthSwt_Ip_ESQRTABLE_CFGE_SQRTypeIdxType Cfge_SqrType;      /* Sequence Recovery Function type */
} Netc_EthSwt_Ip_EgrSeqRecoveryTableRspDataType;

/*!
 * @brief defines Ingress Stream Identification table request/response data type.
 * @implements Netc_EthSwt_Ip_IngrStremIdentificationTableDataType_struct
 */
typedef struct
{
    uint32 IngrStreamIdenResumeEntryId;                             /* Ingress Stream Identification tabel Resume Entry ID */
    uint32 IngrStreamIdenEntryId;                                   /* Ingress Stream Identification tabel Entry ID */
    uint32 IngrStreamEntryId;                                       /* Ingress Stream table Entry ID */
    Netc_EthSwt_Ip_KeyTypeIdxType Keye_Keytype;                     /* Key type for key construction */
    uint8 Keye_SrcPortId;                                           /* Source port Id */
    Netc_EthSwt_Ip_SrcPortMasqIdxType Keye_Spm;                     /* Source port masquerading */
    uint32 Keye_FrmKey[4U];                                         /* Frame portion of the Key */
}Netc_EthSwt_Ip_IngrStremIdentificationTableDataType;

/*!
 * @brief defines Ingress Stream Look Up table data type.
 */
typedef struct
{
    boolean PortIngressStreamEnableLookUp;                   /* This field shows the enablement of Ingress Stream look up. */
    uint16  PortIngressStreamDefaultEntryID;                 /* This field is used for choosing the default Ingress Stream ID. When there is no match in the
                                                                First or Second ISI look up, the default IS entry ID will be used to determine the action that has to
                                                                be done to the specific Stream. */
    boolean PortIngressStreamUseFirstLookUp;                 /* This field shows the usage of the first rule from the selected pair of key contruction rule set. */
    boolean PortIngressStreamUseSecondLookUp;                /* This field shows the usage of the second rule from the selected pair of key contruction rule set. */
    boolean PortIngressStreamUseSecondKeyConstructionPair;   /* This field shows the usage of the latter 2 entries of the EthSwtKeyConstruction list of rules. */
}Netc_EthSwt_Ip_PortIngresStreamLookUpDataType;

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
 * @brief Rate Policer Table Request Data Buffer FEEU field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_FEEU_SHIFT          (1U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_FEEU_MASK           (0x00000002UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_FEEU(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_FEEU_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_FEEU_MASK)

/*!
 * @brief Rate Policer Table Request Data Buffer PSEU field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_PSEU_SHIFT          (2U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_PSEU_MASK           (0x00000004UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_PSEU(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_PSEU_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_PSEU_MASK)

/*!
 * @brief Rate Policer Table Request Data Buffer STSEU field.
 */
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT          (3U)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK           (0x00000008UL)
#define NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief FDB table Request Data Buffer ACTEU field.
 */
#define NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_SHIFT            (1U)
#define NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_MASK             (0x00000002UL)
#define NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_SHIFT)) & NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU_MASK)

/*!
 * @brief Ingress Sequence Generation Table Request Data Buffer SGSEU field.
 */
#define NETC_ETHSWT_IP_ISQGTABLE_REQFMT_ACTIONS_FIELD_SGSEU_SHIFT           (1U)
#define NETC_ETHSWT_IP_ISQGTABLE_REQFMT_ACTIONS_FIELD_SGSEU_MASK            (0x00000002UL)
#define NETC_ETHSWT_IP_ISQGTABLE_REQFMT_ACTIONS_FIELD_SGSEU(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ISQGTABLE_REQFMT_ACTIONS_FIELD_SGSEU_SHIFT)) & NETC_ETHSWT_IP_ISQGTABLE_REQFMT_ACTIONS_FIELD_SGSEU_MASK)

/*!
 * @brief Egress Sequence Recovery Table Request Data Buffer STSEU field.
 */
#define NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT           (1U)
#define NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK            (0x00000002UL)
#define NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief Egress Sequence Recovery Table Request Data Buffer SRSEU field.
 */
#define NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_SRSEU_SHIFT           (2U)
#define NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_SRSEU_MASK            (0x00000004UL)
#define NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_SRSEU(x)              (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_SRSEU_SHIFT)) & NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_SRSEU_MASK)

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

/* index of Ingress Count Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD                        (0U)        /*!< first uint32 item of Ingress Count Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD                      (1U)        /*!< second uint32 item of Ingress Count Table Request Data Buffer Format */

/*!
 * @brief Data fields in Ingress Count Table Request Data Buffer Format.
 */
#define NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT            (0U)
#define NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK             (0x00000001UL)
#define NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/* index of Egress Count Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD                        (0U)        /*!< first uint32 item of Egress Count Table Request Data Buffer Format */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD                      (1U)        /*!< second uint32 item of Egress Count Table Request Data Buffer Format */

/*!
 * @brief Data fields in Egress Count Table Request Data Buffer Format.
 */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT            (0U)
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK             (0x00000001UL)
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/* index of data fields in FDB Table Response Action Buffer Format, ACT_FLAG */
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG_INACTIVE_FIELD                    (0U)        /*!< FDB table entry was not active during this time period */
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG_ACTIVE_FIELD                      (1U)        /*!< FDB table entry was active during this time period */

/*!
 * @brief Data fields in FDB Table Response Action Buffer Format, ACT_FLAG.
 */
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG_SHIFT            (7U)
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG_MASK             (0x00000080UL)
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief Data fields in FDB Table Response Action Buffer Format, ACT_CNT.
 */
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_CNT_SHIFT            (0U)
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_CNT_MASK             (0x0000007FUL)
#define NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_CNT(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief Egress Count Table update actions data type enumeration. Netc_EthSwt_Ip_ECTableUpdateActionsDataType
 */
typedef enum {
    NETC_ETHSWT_EGRESSCOUNTTABLE_NO_UPDATE_STATISTICS_ELEMENT = 0U,                 /*!< No update performed to the Statistics Element  */
    NETC_ETHSWT_EGRESSCOUNTTABLE_RESET_STATISTICS_ELEMENT                           /*!< All counters within the Statistics Element are reset  */
} Netc_EthSwt_Ip_ECTableUpdateActionsDataType;

typedef enum {
    NETC_ETHSWT_INGRESSCOUNTTABLE_NO_UPDATE_STATISTICS_ELEMENT = 0U,                 /*!< No update performed to the Statistics Element  */
    NETC_ETHSWT_INGRESSCOUNTTABLE_RESET_STATISTICS_ELEMENT                           /*!< All counters within the Statistics Element are reset  */
} Netc_EthSwt_Ip_ICTableUpdateActionsDataType;

/*!
 * @brief Statistics data of Egress Count Table in response data buffer. Netc_EthSwt_Ip_ECTableStatisticsDataType
 * @implements Netc_EthSwt_Ip_ECTableStatisticsDataType_struct
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
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_NOT_INCREMENT_EGRESSFRMCOUNTER         (0x0U)   /*!< Do not increment egress frame counter  */
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_INCREMENT_EGRESSFRMCOUNTER             (0x1U)   /*!< Increment egress frame counter  */

/*!
 * @brief Egress Treatment Table egress sequence actions data type definitions.
 */
typedef uint32 Netc_EthSwt_Ip_EgressTreatmentTableSequenceActionType;
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_NO_SEQUENCE_ACTION_REQUIRED            (0x0U)   /*!< No Sequence Action required  */
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_SEQUENCE_RECOVERY_ACTION               (0x2U)   /*!< Sequence Recovery action  */

/*!
 * @brief Egress Treatment Table egress frame modification mode data type definitions.
 */
typedef uint32 Netc_EthSwt_Ip_EgressTreatmentTableFrmModificationModeType;
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_DEFAULT_FRM_MODIFICATION_MODE          (0x0U)    /*!< Normal/Default mode  */
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_L2ACTION_FRM_MODIFICATION_MODE         (0x1U)    /*!< When EFM_EID[L2_ACT]=1b  */
#define NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_PAYLOADACTION_FRM_MODIFICATION_MODE    (0x2U)    /*!< When EFM_EID[PLD_ACT]=001b  */

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
 * @implements Netc_EthSwt_Ip_EgressTreatmentEntryDataType_struct
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
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H(x)               (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_SHIFT)) & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_MASK)

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
 * @brief Frame Modification Table PCP action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PCPACT_USE_EXISTING       (0x0U)  /* Use existing PCP in the frame. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PCPACT_USE_SPECIFIED      (0x1U)  /* Use the specified PCP. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PCPACT_PCPTOPCP_PROFILE   (0x2U)  /* Use PCP to PCP mapping profile. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PCPACT_QOSTOPCP_PROFILE   (0x3U)  /* Use QOS to PCP mapping profile. */

/*!
 * @brief Frame Modification Table DEI action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_DEIACT_USE_EXISTING      (0x0U) /* Use existing DEI in the frame. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_DEIACT_USE_SPECIFIED     (0x1U) /* Use the specified DEI. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_DEIACT_DRTODEI_PROFILE   (0x2U)  /* Use DR to DEI mapping profile. */

/*!
 * @brief Frame Modification Table Sequence Tag action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_SQ_TAG_NO_ACTION      (0x0U)   /* Redundancy tag is kept at egress. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_SQ_TAG_REMOVE_RTAG    (0x1U)   /* Redundancy tag is removed at egress. */

/*!
 * @brief Frame Modification Table Outer VID action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_VIDACT_USE_EXISTING   (0x0U)   /* No frame modification is performed on VID of the received frame. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_VIDACT_USE_SPECIFIED  (0x1U)   /* VID value of the received frame will be changed according to Frame Modification entry. */

/*!
 * @brief Frame Modification Table VLAN header action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_VLAN_HEADER_ACT_NO_ACTION                  (0x0U)    /* No frame modification is performed on the VLAN header of the frame. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_VLAN_HEADER_ACT_DELETE_OUTER_VLAN_HEADER   (0x1U)    /* Frame Modification Table entry will delete the Outer VLAN header of the frame. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_VLAN_HEADER_ACT_ADD_OUTER_VLAN_HEADER      (0x2U)    /* Frame Modification Table will add a VLAN header to the frame.
                                                                                                  If the frame already has already a VLAN header, the resulted frame will be double tagged. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_VLAN_HEADER_ACT_REPLACE_OUTER_VLAN_HEADER  (0x3U)    /* VLAN header of the frame will be replaced with new specified values of the selected Frame Modification Table entry. */

/*!
 * @brief Frame Modification Table MAC header action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_MAC_HEADER_ACTION_NO_ACTION                                         (0x0U) /* No action is performed on the MAC header. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_MAC_HEADER_ACTION_REPLACE_SMAC_FROM_REGISTER                        (0x2U) /* Replace SMAC with the contents of the PMAR0/1 register where port=SMAC_PORT. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_MAC_HEADER_ACTION_REPLACE_SMAC_FROM_REGISTER_DMAC_FROM_FIELD        (0x3U) /* Replace SMAC with the contents of the PMAR0/1 register where port=SMAC_PORT, and DMAC by specified DEST_MAC_ADDR field value. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_MAC_HEADER_ACTION_REPLACE_SMAC_FROM_REGISTER_DMAC_FROM_FRAME_SMAC   (0x4U) /* Replace SMAC with the contents of the PMAR0/1 register where port=SMAC_PORT, and DMAC by frame's SMAC. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_MAC_HEADER_ACTION_REPLACE_DMAC_FROM_FIELD                           (0x5U) /* Replace DMAC with specified DEST_MAC_ADDR field value. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_MAC_HEADER_ACTION_SWAP_DMAC_SMAC                                    (0x6U)  /* Swap DMAC and SMAC. */

/*!
 * @brief Frame Modification Table Layer 2 action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_L2ACTION_USE_L2_HEADER_ACTIONS  (0x0U)   /* L2 actions are specified in L2 header action fields of this entry; i.e. MAC_HDR_ACT, VLAN_HDR_ACT and SQT_HDR_ACT. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_L2ACTION_USE_REPLACE_L2_PDU     (0x1U)   /* The entire L2 PDU (or frame) is replaced with new L2 PDU of length FMD_BYTES
                                                                                       specified by FMD_EID (FCS not present in the new L2 PDU). No L2 header actions
                                                                                       or payload action in this */

/*!
 * @brief Frame Modification Table Payload action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PAYLOADACTION_NO_ACTION                    (0x0U)   /* No action on payload. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PAYLOADACTION_REPLACE_WITH_FRM_MODIF_DATA  (0x1U)   /* Remove entire Ethernet payload including the payload Ethertype and insert with FMD_BYTES of data
                                                                                                  specified in FMD_EID. The the Ethernet payload (including the payload Ethertype) begins in the
                                                                                                  received frame immediately after source MAC address or VLAN tag(s) (up to 2) or R-TAG/HSR tag (if any). */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_PAYLOADACTION_REPLACE_DATA_FROM_OFFSET     (0x2U)   /* Replace FMD_BYTES of raw data in the Ethernet payload starting at PLD_OFFSET. Data is specified in FMD_EID.
                                                                                                  The maximum number of bytes that can be replaced is 128 bytes. If the frame is too short to replace all of
                                                                                                  the bytes specified by this replacement action, the Ethernet payload of the frame is replaced up to its last byte,
                                                                                                  and then the new calculated FCS is appended to the frame. The transmission of the frame completes without error. */

/*!
 * @brief Frame Modification Table Outer TPID action defines.
 */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_TPIDACTION_USE_EXISTING          (0x0U)  /* Use TPID from outer VLAN header, if no outer VLANheader is present then a misconfiguration event will be
                                                                                      generated and handled according to the port's PFMCR register. The outer VLAN header in a received frame
                                                                                      is considered present if VLAN classification has deemed the outer VLAN header valid. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_TPIDACTION_SET_TO_0X8100         (0x1U) /* Set TPID to 0x8100. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_TPIDACTION_SET_TO_0X88A8         (0x2U) /* Set TPID to 0x88A8. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_TPIDACTION_SET_TO_CVLAN          (0x3U) /* Set TPID to C-VLAN. */
#define NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_TPIDACTION_SET_TO_CUSTOM_SVLAN   (0x4U) /* Set TPID to Custom S-VLAN. */


/*!
 * @brief defines Frame Modification Table entries.
 * @implements Netc_EthSwt_Ip_FrmModificationEntryDataType_struct
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
 * @implements Netc_EthSwt_Ip_IngressPortFilterEntryDataType_struct
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
 * @implements Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType_struct
 */
typedef struct
{
    uint32 TimeGateSchedulingTable_EID;                 /*!< Time Gate Scheduling Table Entry ID, which is actually the port index of switch */
    uint64 AdminBaseTime;                               /*!< Administrative Base Time */
    uint32 AdminCycleTime;                              /*!< Administrative Cycle Time */
    uint32 AdminCycleTimeExt;                           /*!< Administrative Cycle Time Extension */
    uint16 AdminControlListLength;                      /*!< Administrative Control List Length */
#if (NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES > 0U)
    Netc_EthSwt_Ip_GateEntryAdminControlListDataType GateEntryAdminControlListData[NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES];
#endif
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
    NETC_ETHSWT_SGMII_MODE          = 3U,    /**< SGMII interface mode */
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
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA6,                    /*!< seventh item of CFGEDATA but ninth item of Switch Tables Request Data Buffer Format */
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA7,
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA8,
    NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA9
} Netc_EthSwt_Ip_SwitchTableRequestDataIndexType;

/* bits field for Vlan Filter Table CFGE_DATA Format */
/*!
 * @brief Vlan Filter Table Config Data STG_ID field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT                   (24U)
/*!
 * @brief Vlan Filter Table Config Data STG_ID field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK                    (0x0F000000UL)
/*!
 * @brief Vlan Filter Table Config Data STG_ID.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID(x)                      (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK)

/*!
 * @brief Vlan Filter Table Config Data PORT membership field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_SHIFT          (0U)
/*!
 * @brief Vlan Filter Table Config Data PORT membership field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK           (0x00FFFFFFUL)
/*!
 * @brief Vlan Filter Table Config Data PORT membership.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK)

/*!
 * @brief Vlan Filter Table Config Data IPMFLE field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT                   (23U)
/*!
 * @brief Vlan Filter Table Config Data IPMFLE field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK                    (0x00800000UL)
/*!
 * @brief Vlan Filter Table Config Data IPMFLE.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE(x)                      (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK)

/*!
 * @brief Vlan Filter Table Config Data IPMFE field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT                    (22U)
/*!
 * @brief Vlan Filter Table Config Data IPMFE field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK                     (0x00400000UL)
/*!
 * @brief Vlan Filter Table Config Data IPMFE.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE(x)                       (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK)

/*!
 * @brief Vlan Filter Table Config Data MFO field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT                      (19U)
/*!
 * @brief Vlan Filter Table Config Data MFO field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_MASK                       (0x00180000UL)
/*!
 * @brief Vlan Filter Table Config Data MFO.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_MASK)

/*!
 * @brief Vlan Filter Table Config Data MLO field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT                      (16U)
/*!
 * @brief Vlan Filter Table Config Data MLO field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_MASK                       (0x00070000UL)
/*!
 * @brief Vlan Filter Table Config Data MLO.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_MASK)

/*!
 * @brief Vlan Filter Table Config Data FID field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_SHIFT                      (0U)
/*!
 * @brief Vlan Filter Table Config Data FID field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_MASK                       (0x00000FFFUL)
/*!
 * @brief Vlan Filter Table Config Data FID.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_MASK)

/*!
 * @brief Vlan Filter Table Config Data ETA port bitmap field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_SHIFT          (0U)
/*!
 * @brief Vlan Filter Table Config Data ETA port bitmap field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK           (0x00FFFFFFUL)
/*!
 * @brief Vlan Filter Table Config Data ETA port bitmap.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP(x)             (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK)

/*!
 * @brief Vlan Filter Table Config Data base ET_EID field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_SHIFT              (0U)
/*!
 * @brief Vlan Filter Table Config Data base ET_EID field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_MASK               (0xFFFFFFFFUL)
/*!
 * @brief Vlan Filter Table Config Data base ET_EID.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID(x)                 (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_MASK)

/*!
 * @brief Vlan Filter Table Config Data KEY_DATA bits field.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_SHIFT                      (0U)
/*!
 * @brief Vlan Filter Table Config Data KEY_DATA bits field mask.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_MASK                       (0x00000FFFUL)
/*!
 * @brief Vlan Filter Table Config Data KEY_DATA bits.
 */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID(x)                         (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_SHIFT)) & NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_MASK)

/*!
 * @brief Vlan Filter Table response data type enumeration. Netc_EthSwt_Ip_VlanFilterTable_ResponsDataIndexType
 */
typedef enum {
    NETC_ETHSWT_IP_VLANFILTERTABLE_RSPDATA_STATUS = 0x0U,     /*!< Status Field In Vlan Filter Table Response Data Buffer */
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
    uint32 Cfge_Data[NETC_ETHSWT_IP_TABLE_CFGEDATA_ITEMS]; /*!< Config data for Vlan Filtre Table */
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
    uint64 rxEtherOctetCounter;                  /*!< Port Receive Ethernet Octets Counter(etherStatsOctetsn) (PM0_REOCTn) */
    uint64 rxOctetCounter;                       /*!< Supported by pseudo port. Port Receive Octets Counter(iflnOctetsn) (PM0_ROCTn) */
    uint64 rxValidPauseFrmCounter;               /*!< Port Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_RXPFn) */
    uint64 rxFrmCounter;                         /*!< Receive Frame Counter Register(aFramesReceivedOKn) (PM0_RFRMn) */
    uint64 rxFrameCheckSequenceErrorCounter;     /*!< Port Receive Frame Check Sequence Error Counter Register() (PM0_RFCSn) */
    uint64 rxVlanFrmCounter;                     /*!< Port Receive VLAN Frame Counter Register(VLANReceivedOKn) (PM0_RVLANn) */
    uint64 rxFrameErrorCounter;                  /*!< Port Receive Frame Error Counter Register(ifInErrorsn) (PM0_RERRn) */
    uint64 rxUnicastFrmCounter;                  /*!< Supported by pseudo port. Port Receive Unicast Frame Counter Register(ifInUcastPktsn) (PM0_RUCAn) */
    uint64 rxMulticastFrmCounter;                /*!< Supported by pseudo port. Port Receive Multicast Frame Counter Register(ifInMulticastPktsn) (PM0_RMCAn) */
    uint64 rxBroadcastFrmCounter;                /*!< Supported by pseudo port. Port Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) (PM0_RBCAn) */
    uint64 rxDroppedPktCounter;                  /*!< Port Receive Dropped Packets Counter Register(etherStatsDropEventsn) (PM0_RDRPn) */
    uint64 rxPktCounter;                         /*!< Port Receive Packets Counter Register(etherStatsPktsn) (PM0_RPKTn) */
    uint64 rxUndersizePacketCounter;             /*!< Port Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_RUNDn) */
    uint64 rx64OctetPktCounter;                  /*!< Port Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) (PM0_R64n) */
    uint64 rx65to127OctetPktCounter;             /*!< Port Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) (PM0_R127n) */
    uint64 rx128to255OctetPktCounter;            /*!< Port Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) (PM0_R255n) */
    uint64 rx256to511OctetPktCounter;            /*!< Port Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) (PM0_R511n) */
    uint64 rx512to1023OctetPktCounter;           /*!< Port Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) (PM0_R1023n) */
    uint64 rx1024to1522OctetPktCounter;          /*!< Port Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) (PM0_R1522n) */
    uint64 rx1523toMaxOctetPktCounter;           /*!< Port Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) (PM0_R1523Xn) */
    uint64 rxOversizedPacketsCounter;            /*!< Port Receive Oversized Packet Counter Register(etherStatsOversizePktsn) (PM0_ROVRn) */
    uint64 rxJabberPktCounter;                   /*!< Port Receive Jabber Packet Counter Register(etherStatsJabbersn) (PM0_RJBRn) */
    uint64 rxFragmentPktCounter;                 /*!< Port Receive Fragment Packet Counter Register(etherStatsFragmentsn (PM0_RFRGn) */
    uint64 rxControlPktCounter;                  /*!< Port Receive Control Packet Counter Register (PM0_RCNPn) */
    uint64 rxDroppedNTruncatedPktCounter;        /*!< Port Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) (PM0_RDRNTPn) */

    uint64 txEtherOctetCounter;                  /*!< Transmit Ethernet Octets Counter(etherStatsOctetsn) (PM0_TEOCTn) */
    uint64 txOctetCounter;                       /*!< Supported by pseudo port. Port Transmit Octets Counter Register(ifOutOctetsn) (PM0_TOCTn) */
    uint64 txValidPauseFrmCounter;               /*!< Port Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_TXPFn) */
    uint64 txFrmCounter;                         /*!< Port Transmit Frame Counter Register(aFramesTransmittedOKn) (PM0_TFRMn) */
    uint64 txFrameCheckSequenceErrorCounter;     /*!< Port Transmit Frame Check Sequence Error Counter Register() (PM0_TFCSn) */
    uint64 txVlanFrmCounter;                     /*!< Port Transmit VLAN Frame Counter Register(VLANTransmittedOKn) (PM0_TVLANn) */
    uint64 txFrameErrorCounter;                  /*!< Port Transmit Frame Error Counter Register(ifOutErrorsn) (PM0_TERRn) */
    uint64 txUnicastFrmCounter;                  /*!< Supported by pseudo port. Port Transmit Unicast Frame Counter Register(ifOutUcastPktsn) (PM0_TUCAn) */
    uint64 txMulticastFrmCounter;                /*!< Supported by pseudo port. Port Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) (PM0_TMCAn) */
    uint64 txBroadcastFrmCounter;                /*!< Supported by pseudo port. Port Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) (PM0_TBCAn) */
    uint64 txPktCounter;                         /*!< Port Transmit Packets Counter Register(etherStatsPktsn) (PM0_TPKTn) */
    uint64 txUndersizePacketCounter;             /*!< Port Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_TUNDn) */
    uint64 tx64OctetPktCounter;                  /*!< Port Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) (PM0_T64n) */
    uint64 tx65to127OctetPktCounter;             /*!< Port Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) (PM0_T127n) */
    uint64 tx128to255OctetPktCounter;            /*!< Port Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) (PM0_T255n) */
    uint64 tx256to511OctetPktCounter;            /*!< Port Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) (PM0_T511n) */
    uint64 tx512to1023OctetPktCounter;           /*!< Port Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) (PM0_T1023n) */
    uint64 tx1024to1522OctetPktCounter;          /*!< Port Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) (PM0_T1522n) */
    uint64 tx1523toMaxOctetPktCounter;           /*!< Port Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) (PM0_T1523Xn) */
    uint64 txControlPktCounter;                  /*!< Port Transmit Control Packet Counter Register (PM0_TCNPn) */
    uint64 txDeferredPktCounter;                 /*!< Port Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) (PM0_TDFRn) */
    uint64 txMultiCollisionCounter;              /*!< Port Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) (PM0_TMCOLn) */
    uint64 txSingleCollisionCounter;             /*!< Port Transmit Single Collision Counter(aSingleCollisionFrames) Register (PM0_TSCOLn) */
    uint64 txLateCollisionCounter;               /*!< Port Transmit Late Collision Counter(aLateCollisions) Register (PM0_TLCOLn) */
    uint64 txExcessiveCollisionCounter;          /*!< Port Transmit Excessive Collisions Counter Register (PM0_TECOLn) */

    uint32 rxDiscardCounter;                     /*!< Port Rx discard count register (PRXDCR) */
    uint32 txDiscardCounter;                     /*!< Port Tx discard count register (PTXDCR) */
    uint32 unIntegrityErrorCounter;              /* Uncorrectable non-fatal integrity error count register (UNIECTR) which tracks how many events have been detected. */
} Netc_EthSwt_Ip_CounterType;

/* Netc_EthSwt_Ip_CounterValueType_typedef */
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
    Netc_EthSwt_Ip_PortIngresStreamLookUpDataType EthSwtPortIngressStreamLookUpConfig; /*!< Ingress Stream look up configuration. */
} Netc_EthSwt_Ip_PortIngressType;


/*!
 * @brief Port Egress Class Scheduler table CFGE_DATA config field.
 */
/* CQ_ASSG field */
#define NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_CQ_ASSG_SHIFT             (0U)
#define NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_CQ_ASSG_MASK              (0x0000000FUL)
#define NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_CQ_ASSG(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_CQ_ASSG_SHIFT)) & NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_CQ_ASSG_MASK)

/* OAL field */
#define NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_OAL_SHIFT             (16U)
#define NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_OAL_MASK              (0x7FF0000UL)
#define NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_OAL(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_OAL_SHIFT)) & NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_OAL_MASK)

/* WBFS_WEIGHT_0 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_0_SHIFT             (0U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_0_MASK              (0x000000FFUL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_0(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_0_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_0_MASK)

/* WBFS_WEIGHT_1 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_1_SHIFT             (8U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_1_MASK              (0x0000FF00UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_1(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_1_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_1_MASK)

/* WBFS_WEIGHT_2 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_2_SHIFT             (16U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_2_MASK              (0x00FF0000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_2(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_2_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_2_MASK)

/* WBFS_WEIGHT_3 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_3_SHIFT             (24U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_3_MASK              (0xFF000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_3(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_3_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_3_MASK)

/* WBFS_WEIGHT_4 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_4_SHIFT             (0U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_4_MASK              (0x000000FFUL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_4(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_4_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_4_MASK)

/* WBFS_WEIGHT_5 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_5_SHIFT             (8U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_5_MASK              (0x0000FF00UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_5(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_5_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_5_MASK)

/* WBFS_WEIGHT_6 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_6_SHIFT             (16U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_6_MASK              (0x00FF0000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_6(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_6_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_6_MASK)

/* WBFS_WEIGHT_7 field */
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_7_SHIFT             (24U)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_7_MASK              (0xFF000000UL)
#define NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_7(x)                (((uint32)(((uint32)(x)) << NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_7_SHIFT)) & NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_7_MASK)

/*!
 * @brief Defines the port egress class scheduler.
 * @implements Netc_EthSwt_Ip_PortSchedulerType_struct
 */
typedef struct {
    uint8  numberOfWBFSQueues; /* Number of queues using the weighted fair share algorithm */
    uint16 overheadAccountingLength; /* Added to the actual length of each frame when performing class scheduler WBFS calculations */
    uint8  portEgressSchedulerWeightList[NETC_ETHSWT_WBFS_QUEUES_NB]; /* Array holding the queue weights for WBFS (weighted fair share) scheduler inputs  */
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
    boolean enablePreemption; /*!< Enable egress frame preemption */
    uint8 preemptionTCprofiles;  /*!< Mark trafic classes as preemptable or express */
    boolean updateEgressDr; /*!< If there is frame modification and enable DEI change */
    uint8 (*vlanDrToDei)[NETC_ETHSWT_IP_NUMBER_OF_DR]; /*!< If there is frame modification and enable map DR to DEI */
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
#if (NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES > 0U)
    uint8 numberOfGateControlListEntries; /*!< Number of entries in Administrative Gate Control list. */
    Netc_EthSwt_Ip_GateEntryAdminControlListDataType (*TimeGateControlListEntries)[NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES]; /*!< Pointer to an array containing the gate control list for port. */
#endif
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
    boolean EthSwtEnableFreeRunningTimer; /*!< Enable/Disable free running timer. */
    boolean EthSwtPortLoopbackEnable; /*!< Enable loopback mode for current port */
    boolean EthSwtPortDisallowMacStationMove; /*!< MAC station move disallowed.*/
} Netc_EthSwt_Ip_PortType;

/*!
 * @brief Key Construction Rule
 * @implements : Netc_EthSwt_Ip_KeyConstructionRuleType_struct
*/
typedef struct
{
    uint32 EthSwtKeyConstructionRegValue;  /**<  Value to be added in the Key Construction Register*/
    uint32 EthSwtPayloadField0RegValue;  /**<  Value to be added in the Payload Field 0 Register*/
    uint32 EthSwtPayloadField1RegValue;  /**<  Value to be added in the Payload Field 0 Register*/
} Netc_EthSwt_Ip_KeyConstructionRuleType;

/*!
 * @brief Configuration of one Ethernet Switch for initalisation
 */
typedef struct {
    Netc_EthSwt_Ip_MacLearningOptionType MacLearningOption; /*!< specifies the Mac learning mode */
    Netc_EthSwt_Ip_MacForwardingOptionType MacForwardingOption; /*!< specifies the Mac forwarding option */
    uint16 EthSwtMaxDynamicEntries; /*!< This field specifies the maximum number of dynamic entries allowed in the FDB table for the entire switch. A value of 0 implies no global switch limit imposed for dynamic entries.*/
    uint16 EthSwtArlTableEntryTimeout; /*!< specifies the timeout in seconds for removing unused entries. */
    boolean EthSwtEnableSharedLearning; /*!< Used to determine the FID when doing a lookup in the FDB table. 0: Independent VLAN learning: FID is set to to the VID assigned to the frame 1: Shared VLAN learning: Use the FID specified in this register */
    uint32 EthSwtCustomVlanEtherType1;  /*!< Custom VLAN Ethertype 1 (C-VLAN) */
    uint32 EthSwtCustomVlanEtherType2;  /*!< Custom VLAN Ethertype 2 (S-VLAN) */
    Netc_EthSwt_Ip_PortType (*port)[NETC_ETHSWT_IP_NUMBER_OF_PORTS]; /*!< Port description. */
    Netc_EthSwt_Ip_KeyConstructionRuleType (*EthSwtKeyConstruction)[4U]; /*!< Represents a Key Construction Rule. */
#if (NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
    uint8 NumberOfIsiEntries; /*!< Number of Ingress Stream Identification entries. */
    const Netc_EthSwt_Ip_IngrStremIdentificationTableDataType (*IsiEntries)[NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES]; /*!< Pointer to an array containing the StreamIdentification configuration. */
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES > 0U)
    uint8 NumberOfSeqTagEntries; /*!< Number of Sequence tag entries. */
    const Netc_EthSwt_Ip_ISQGTableDataType (*SeqTagEntries)[NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES]; /*!< Pointer to an array containing the SequenceTag configuration. */
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES > 0U)
    uint8 NumberOfSeqRecoveryEntries; /*!< Number of Sequence tag entries. */
    const Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType (*SeqRecoveryEntries)[NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES]; /*!< Pointer to an array containing the SequenceRecovery configuration. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES > 0U)
    uint8 NumberOfIpftEntries; /*!< Number of Ingress Port Filter entries. */
    const Netc_EthSwt_Ip_IngressPortFilterEntryDataType (*IngressPortFilterEntries)[NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES]; /*!< Pointer to an array containing the Ingress Port Filter table configuration. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_RP_ENTRIES > 0U)
    uint8 NumberOfRPEntries; /*!< Number of Rate Policer/Flow Meter entries */
    const Netc_EthSwt_Ip_RatePolicerEntryDataType (*EthSwtRatePolicerEntries)[NETC_ETHSWT_NUMBER_OF_RP_ENTRIES]; /*!< Pointer to an array containing entries for the rate policer table. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES > 0U)
    uint8 NumberOfSGCLEntries; /*!< Number of Stream Gate Instance entries */
    const Netc_EthSwt_Ip_SGCLTableDataType (*StreamGateControlListEntries)[NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES]; /*!< Pointer to an array containing configurations for Stream Gate Control Lists. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES > 0U)
    uint8 NumberOfSGIEntries; /*!< Number of Stream Gate Instance entries */
    const Netc_EthSwt_Ip_StreamGateInstanceEntryDataType (*StreamGateInstanceEntries)[NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES]; /*!< Pointer to an array containing configurations for Stream Gate Instances. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES > 0U)
    uint8 NumberOfFrmModifEntries; /*!< Number of Frame Modification entries */
    const Netc_EthSwt_Ip_FrmModificationEntryDataType (*FrameModificationEntries)[NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES]; /*!< Pointer to an array containing configurations for Frame Modification. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES > 0U)
    uint8 NumberOfEgrTreatmentEntries; /*!< Number of Egress Treatment entries */
    const Netc_EthSwt_Ip_EgressTreatmentEntryDataType (*EgressTreatmentEntries)[NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES]; /*!< Pointer to an array containing configurations for Egress Treatment. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
    uint8 NumberOfIngrStreamEntries; /*!< Number of Ingress Stream entries */
    const Netc_EthSwt_Ip_IngressStreamEntryDataType (*IngressStreamEntries)[NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES]; /*!< Pointer to an array containing configurations for Ingress Stream. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES > 0U)
    uint8 NumberOfIngrStreamFilterEntries; /*!< Number of Ingress Stream Filter entries */
    const Netc_EthSwt_Ip_IngressStreamFilterEntryDataType (*IngressStreamFilterEntries)[NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES]; /*!< Pointer to an array containing configurations for Ingress Stream Filter. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_STREAMCOUNT_ENTRIES > 0U)
    uint8 NumberOfIngrStreamCountEntries; /*!< Number of Ingress Stream Count entries */
#endif
#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
    uint8 NumberOfFdbEntries; /*!< Number of FDB entries. */
    const Netc_EthSwt_Ip_FdbEntryType (*FdbEntries)[NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES]; /*!< Pointer to an array containing the FDB configuration. */
#endif
#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
    uint8 NumberOfVlanFilterEntries; /*!< Number of Vlan Filter entries. */
    const Netc_EthSwt_Ip_VlanFilterEntryType (*VlanFilterEntries)[NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES]; /*!< Pointer to an array containing the Vlan configuration. */
#endif
    uint8 (*vlanPcpDei2IpvProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_PCP_DEI]; /*!< Profiles for PCP_DEI to IPV ingress mapping. */
    uint8 (*vlanPcpDei2DrProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_PCP_DEI]; /*!< Profiles for PCP_DEI to DR ingress mapping. */
    uint8 (*vlanPcp2PcpProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_PCP]; /*!< Profiles for PCP to PCP frame modification. */
    uint8 (*vlanIpvDr2PcpProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_IPV][NETC_ETHSWT_IP_NUMBER_OF_DR]; /*!< Profiles for egress IPV/DR to PCP frame modification. */
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

/*!
 * @brief PTP time
 * @implements Netc_EthSwt_Ip_PtpTimeType_struct
*/
typedef struct
{
    uint32 nanoseconds;  /**< Nanoseconds */
    uint32 seconds;      /**< Lower 32-bit of seconds */
    uint16 secondsHi;    /**< Upper 16-bit of seconds */
} Netc_EthSwt_Ip_PtpTimeType;

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
