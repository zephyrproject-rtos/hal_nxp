/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *   @file Netc_EthSwt_Ip.c
 *   @internal
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
#include "Netc_EthSwt_Ip.h"
#include "SchM_EthSwt_43_NETC.h"
#include "Netc_EthSwt_Ip_Types.h"
#include "Netc_EthSwt_Ip_Cfg_Defines.h"
#include "OsIf.h"        /* Used for timeouts. */

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_VENDOR_ID_C                      43
#define NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION_C       7
#define NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION_C    0
#define NETC_ETHSWT_IP_SW_MAJOR_VERSION_C               2
#define NETC_ETHSWT_IP_SW_MINOR_VERSION_C               0
#define NETC_ETHSWT_IP_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_EthSwt_Ip.h */
#if (NETC_ETHSWT_IP_VENDOR_ID_C !=  NETC_ETHSWT_IP_VENDOR_ID)
    #error "Netc_EthSwt_Ip.c and Netc_EthSwt_Ip.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION_C    !=  NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION_C    !=  NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION_C !=  NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip.c and Netc_EthSwt_Ip.h are different"
#endif
#if (( NETC_ETHSWT_IP_SW_MAJOR_VERSION_C !=  NETC_ETHSWT_IP_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_MINOR_VERSION_C !=  NETC_ETHSWT_IP_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_PATCH_VERSION_C !=  NETC_ETHSWT_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip.c and Netc_EthSwt_Ip.h are different"
#endif

/* Checks against Netc_EthSwt_Ip_Types.h */
#if (NETC_ETHSWT_IP_VENDOR_ID_C !=  NETC_ETHSWT_IP_TYPES_VENDOR_ID)
    #error "Netc_EthSwt_Ip.c and Netc_EthSwt_Ip_Types.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION_C    !=  NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION_C    !=  NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION_C !=  NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip.c and Netc_EthSwt_Ip_Types.h are different"
#endif
#if (( NETC_ETHSWT_IP_SW_MAJOR_VERSION_C !=  NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_MINOR_VERSION_C !=  NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_PATCH_VERSION_C !=  NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip.c and Netc_EthSwt_Ip_Types.h are different"
#endif

/* Checks against Netc_EthSwt_Ip_Cfg_Defines.h */
#if (NETC_ETHSWT_IP_VENDOR_ID_C !=  NETC_ETHSWT_IP_CFG_DEFINES_VENDOR_ID)
    #error "Netc_EthSwt_Ip.c and Netc_EthSwt_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( NETC_ETHSWT_IP_AR_RELEASE_MAJOR_VERSION_C    !=  NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_MINOR_VERSION_C    !=  NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_AR_RELEASE_REVISION_VERSION_C !=  NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip.c and Netc_EthSwt_Ip_Cfg_Defines.h are different"
#endif
#if (( NETC_ETHSWT_IP_SW_MAJOR_VERSION_C !=  NETC_ETHSWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_MINOR_VERSION_C !=  NETC_ETHSWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( NETC_ETHSWT_IP_SW_PATCH_VERSION_C !=  NETC_ETHSWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip.c and Netc_EthSwt_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum
{
    NETC_ETHSWT_IP_FDB_STATIC_ENTRY_QUERY_SEARCH,
    NETC_ETHSWT_IP_FDB_DYNAMIC_ENTRY_QUERY_SEARCH,
    NETC_ETHSWT_IP_FDB_DONE_ENTRY_QUERY_SEARCH
}Netc_EthSwt_Ip_FdbEntryQuerying;


typedef struct
{
    boolean SrcMacAddrFilterEnabled;
    boolean DstMacAddrFilterEnabled;
}Netc_EthSwt_Ip_IngressPortFilterSrcDestAddrFilter;

typedef struct
{
    boolean MatchedEntryFound;
    uint32 PortBitMap;
    const uint8 * MacAddr;
}Netc_EthSwt_Ip_PortMacAddrEntry;

typedef struct
{
    uint32 ResumeEntryId;
    uint32 EntryId;
}Netc_EthSwt_Ip_ResumeEntryEntryId;


typedef struct
{
    uint8 SwitchIdx;
    uint8 SwitchPortIdx;
}Netc_EthSwt_Ip_SwitchIdxSwitchPort;


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE (1U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE (3U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE (4U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_SGMII_MODE (5U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_100MBIT (0U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_10MBIT (1U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT (2U)

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define NETC_ETHSWT_IP_FIELD_REP_IN_4BITS (4U)
#define NETC_ETHSWT_IP_FIELD_REP_IN_TOP_OF_32BITS (16U)

#define NETC_ETHSWT_IP_RXTAGA_ACCEPT_UNTAGGED (1U)
#define NETC_ETHSWT_IP_RXTAGA_ACCEPT_PRIO_TAGGED (2U)
#define NETC_ETHSWT_IP_RXTAGA_ACCEPT_SINGLE_TAGGED (4U)
#define NETC_ETHSWT_IP_RXTAGA_ACCEPT_DOUBLE_TAGGED (8U)

/* Formula for speed: 10Mbps * (PSPEED+1) */
#define NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS (0U)
#define NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS (9U)
#define NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS (99U)
#define NETC_ETHSWT_IP_SHAPING_PSPEED_2500MBITS (249U)

#define NETC_ETHSWT_IP_NUM_SHAPING_CLASS (8U)

#define NETC_ETHSWT_IP_NUM_AGING_CYCLE (127U)
#define NETC_ETHSWT_IP_NUM_AGING_CYCLE_FLOAT (127.0F)

#define NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID (0xFFFFU)

#define NETC_ETHSWT_IP_ONE_FLOAT (1.0F)

#define MAX_32BIT ((uint32)0xFFFFFFFFUL)

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define ETHSWT_43_NETC_START_SEC_VAR_INIT_BOOLEAN
#include "EthSwt_43_NETC_MemMap.h"

/* Flag to determine if mirroring is active or not */
static boolean MirrorConfigurationDone = FALSE;
/* Flag to determine if there is any VLAN configuration or the default entry will be used */
static boolean Netc_EthSwt_Ip_PortVlanEnable[NETC_ETHSWT_IP_NUMBER_OF_PORTS] = {(boolean)FALSE, (boolean)FALSE, (boolean)FALSE};

#if defined(ERR_IPV_NETC_051587)
    #if (STD_ON == ERR_IPV_NETC_051587)
static boolean Netc_EthSwt_Ip_TGSAdminListRegistered[NETC_ETHSWT_IP_NUMBER_OF_PORTS];
    #endif
#endif

#define ETHSWT_43_NETC_STOP_SEC_VAR_INIT_BOOLEAN
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_BOOLEAN
#include "EthSwt_43_NETC_MemMap.h"

/* Enabled status for Time Aware Shaper of each port */
static boolean PortTimeAwareShaperEnabled[NETC_ETHSWT_IP_NUMBER_OF_PORTS];

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_INIT_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

/* Base address of the registers for the MAC Ports */
static Netc_EthSwt_Ip_PortBaseType* Netc_EthSwt_Ip_PortBaseTable[] = { (Netc_EthSwt_Ip_PortBaseType*)IP_NETC__SW0_ETH_MAC_PORT0_BASE, (Netc_EthSwt_Ip_PortBaseType*)IP_NETC__SW0_ETH_MAC_PORT1_BASE };

/* Base address of the registers for the pseudo Port */
static Netc_EthSwt_Ip_PseudoPortBaseType* Netc_EthSwt_Ip_PseudoPortBaseTable[] = { IP_NETC__SW0_PSEUDO_MAC_PORT2 };
SW_PORT0_Type *Netc_EthSwt_Ip_SW0_PortxBaseAddr[NETC_ETHSWT_IP_NUMBER_OF_PORTS] = {(SW_PORT0_Type*)IP_NETC__SW0_PORT0_BASE, (SW_PORT0_Type*)IP_NETC__SW0_PORT1_BASE, (SW_PORT0_Type*)IP_NETC__SW0_PORT2_BASE};
#define ETHSWT_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

/* Table entries for Time Aware Shaping configuration of each Port */
static Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType TimeGateSchedulingEntryData[NETC_ETHSWT_IP_NUMBER_OF_PORTS];

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_INIT_32
#include "EthSwt_43_NETC_MemMap.h"

/* reference clock for 1588 timer. 0x0UL means the 1588 timer is not enabled. */
static uint32 TimerOriginalRefClk = 0x0UL;
/* reference clcok for clock correction and set ratio */
static uint32 TimerRefClk = 0x0UL;

/* Ingress Port Filter Entry ID for mirroing */
static uint32 MirroringIngressPortFilterEntryId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;

/* Steps used to skip cycles that will not incress the FDB aging counters. */
static uint32 Netc_EthSwt_Ip_MainFunctionCycle[FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS] =  {0UL};

#define ETHSWT_43_NETC_STOP_SEC_VAR_INIT_32
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_32
#include "EthSwt_43_NETC_MemMap.h"

/* The frequency of the NETC module for computing CBS parameters */
static uint32 Netc_EthSwt_Ip_NetcClockFrequency;

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_32
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_16
#include "EthSwt_43_NETC_MemMap.h"

/* The timeout set for FDB aging */
static uint16 Netc_EthSwt_Ip_FdbTableEntryTimeout[FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS];

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_16
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "EthSwt_43_NETC_MemMap.h"

/* A shadow buffer for the mirroring configuration to be used when the application is reading the active configuration */
VAR_SEC_NOCACHE(MirrorCfgBackup) static Netc_EthSwt_Ip_SwitchMirrorCfgType MirrorCfgBackup;

/* Structure used for filling in the actual command buffer descriptor used in table operations */
VAR_SEC_NOCACHE(CmdBDRConfig) static volatile Netc_EthSwt_Ip_CmdBDType CmdBDRConfig[NETC_ETHSWT_IP_CBDR_NUM];

 /* Key element data for ingress port filter table */
VAR_SEC_NOCACHE(Netc_EthSwt_Ip_IPFKeyeData) static volatile uint32 Netc_EthSwt_Ip_IPFKeyeData[NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN];

/* a 128 bytes aligned command ring descriptor buffer */
VAR_SEC_NOCACHE(SwtcommandRingDescriptor0) VAR_ALIGN(static Netc_EthSwt_Ip_NTMPMessageHeaderFormatType SwtcommandRingDescriptor0[NETC_ETHSWT_IP_ACTUAL_CBDR0_LENGTH], NETC_ETHSWT_IP_CBD_ALIGNED_SIZE)

/* a 16 bytes aligned FDB table request data buffer */
VAR_SEC_NOCACHE(TableDataBuffer) VAR_ALIGN(static volatile Netc_EthSwt_Ip_SwitchTableDataType TableDataBuffer, NETC_ETHSWT_IP_TABLE_ALIGNED_SIZE)

/* a 16 bytes aligned request header table data buffer */
VAR_SEC_NOCACHE(Netc_EthSwt_Ip_OperationData) VAR_ALIGN(static Netc_EthSwt_Ip_ReqHeaderTableOperationDataType Netc_EthSwt_Ip_OperationData, NETC_ETHSWT_IP_TABLE_ALIGNED_SIZE)

/* Local copy of the pointer to the configuration data. */
VAR_SEC_NOCACHE(Netc_EthSwt_Ip_ConfigPtr) static const Netc_EthSwt_Ip_ConfigType * Netc_EthSwt_Ip_ConfigPtr[FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS];

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "EthSwt_43_NETC_MemMap.h"


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETHSWT_43_NETC_START_SEC_CODE
#include "EthSwt_43_NETC_MemMap.h"

/*!
 * @brief   : Function for accessing 64 bits counters.
 * @details : Function for extracting the counter value using base/offset
 *
 * @param[in] baseAddressValue base address in uint32
 * @param[in] offsetAddressValue offset from the base
 *
 * @return Register value
 */
static inline uint64 Netc_EthSwt_Ip_Extract64bitsFrom32bitsReg(const uint32 baseAddressValue, const uint32 offsetAddressValue);

/**
 * @brief   : Function for accessing counter in a table.
 * @details : Function for getting the counters using an offset
 *
 * @param[in]        base: Base address of the table.
 * @param[in]        offset: Offset the table.
 *
 * @return           Result the counter value
 */
static inline uint64 Netc_EthSwt_Ip_ComputedRegisterValueExtractionSingleCounter(const Netc_EthSwt_Ip_PortBaseType* base, const Netc_EthSwt_Ip_SingleCounterType offset);

/**
 * @brief   : Function for accessing counter in a table.
 * @details : Function for getting the counters using an offset
 *
 * @param[in]        base: Base address of the table.
 * @param[in]        offset: Offset the table.
 *
 * @return           Result the counter value
 */
static inline uint64 Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(const Netc_EthSwt_Ip_PseudoPortBaseType* base, const Netc_EthSwt_Ip_PseudoPortCounterType offset);

/**
 * @brief   : Function for accessing 64 bits counters in a table.
 * @details : Function for getting the 64 bits counters using two 32 bits accesses.
 *
 * @param[in]        reg: 64bits register pointer.
 *
 * @return           Result the counter value
 */
static inline uint64 Netc_EthSwt_Ip_GetCounterLocal(const volatile uint64 *Reg);

/**
 * @brief            Command BD Rings initialization function
 * @details          Initialize command ring for switch
 *
 * @param[in]        cbdrIndex: Index of switch command BD rings. There are only two switch command BD rings.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           1 : NETC_ETHSWT_IP_CBDRSTATUS_INDEX_ERROR, fail
 */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_InitCommandBDR(uint8 SwitchIdx, uint8 cbdrIndex);

/**
 * @brief            Command request function
 * @details          Add one entry with different commands to command ring
 *
 * @param[in]        cbdrIndex:        Index of switch command BD rings
 *                   OperationData:    a pointer points to a structure with elements table id, access method, and cmd
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           2 : NETC_ETHSWT_IP_CBDRSTATUS_RINGFULL, fail
 */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SendCommand(uint8 SwitchIdx, uint8 cbdrIndex, const Netc_EthSwt_Ip_ReqHeaderTableOperationDataType *OperationData);

/**
 * @brief            Get Matched table entries function
 * @details          Check how many table entry exist
 *
 * @param[in]        cbdrIndex:     Index of switch command BD rings
 *
  * @param[out]      NumOfEntry:    Number of matched entry found
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           others: fail
 */
static void Netc_EthSwt_Ip_GetMatchedEntries(uint8 cbdrIndex, uint32 *NumOfEntry);

/**
 * @brief            FDB table initialization function
 * @details          Fill in the FDB table request data buffer
 *
 * @param[in]        ActionsData: The data of Action Field of FDB table request data buffer
 *                   pAccessKey:  A pointer points the data of Access Key field of FDB table request data buffer
 *                   pCfgeData:   A pointer points the data of Cfge field of FDB table request data buffer
 *                   accessMethod: The value of ACCESS_METHOD. it determins the content of the Access Key field
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           6 : NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR, fail
 */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(uint32 ActionsData, const uint32 *pAccessKey, const Netc_EthSwt_Ip_FDBTableCFGEDataType *pCfgeData, Netc_EthSwt_Ip_AccessMethodType accessMethod);

/**
 * @brief            Vlan Filter table initialization function
 * @details          Fill in the Vlan Filter table request data buffer
 *
 * @param[in]        ActionsData: The data of Action Field of Vlan Filter table request data buffer
 *                   AccessKeyData:  The data of Access Key field in Vlan Filter table request data buffer, it could be Entry_Id, VID, Resume_Entry_Id according to different Access Method.
 *                   pCfgeData:   A pointer points the data of Cfge field of Vlan Filter table request data buffer
 *                   accessMethod: The value of ACCESS_METHOD. it determins the content of the Access Key field
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS, success
 * @retval           6 : NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR, fail
 */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(uint32 ActionsData, uint32 AccessKeyData, const Netc_EthSwt_Ip_VlanFilterTableCFGEDataType *pCfgeData, Netc_EthSwt_Ip_AccessMethodType accessMethod);

static inline void Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable_FoundAMatchedEntry(uint32 * const EntryId, uint32 * const agingCount,  boolean * const FoundEntry, const uint32 NumOfElement);

static inline void Netc_EthSwt_Ip_QueryFdbTableEntry_FoundAMatchedEntry(const uint32 MatchedEntries, Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry);

static inline void Netc_EthSwt_Ip_WriteMirrorConfiguration_EnablePortMirror(const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr);

static Std_ReturnType Netc_EthSwt_Ip_MacPortConfig( Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort,
                                                    Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType,
                                                    EthTrcv_BaudRateType EthSwtPortMacLayerSpeed,
                                                    Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                  );

static inline Netc_EthSwt_Ip_CBDRStatusType  Netc_EthSwt_Ip_GetPortMacAddr_SecondPart(uint8 SwitchIdx,
                                                                                      uint32* const NumOfMatchedElement,
                                                                                      Netc_EthSwt_Ip_FdbEntryDataType* const FdbTableEntry,
                                                                                      Netc_EthSwt_Ip_PortMacAddrEntry* const PortMacAddrEntry);



static inline Std_ReturnType Netc_EthSwt_Ip_ConfigIngressPortFilterForPortMirroring(const uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_IngressPortFilterSrcDestAddrFilter IngressPortFilterSrcDestAddrFilter,
                                                                 const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr,
                                                                 Netc_EthSwt_Ip_IngressPortFilterEntryDataType *IngressPortFilterTableEntry
                                                                );

static inline Std_ReturnType Netc_EthSwt_Ip_ConfigEgressFrameModificationForPortMirroring(uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr);

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_PortConfigIngresStreamLookUp
 * Description   : Internal function for configuring the Ingress Stream look up for a specific port.
 *
 *END**************************************************************************/
static inline void Netc_EthSwt_Ip_PortConfigIngresStreamLookUp(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port);

static inline void Netc_EthSwt_Ip_CheckMacAddressFilterEnableFlag(Netc_EthSwt_Ip_IngressPortFilterSrcDestAddrFilter* const IngressPortFilterSrcDestAddrFilter, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr);
/**
 * @brief Prepare to use a timeout.
 *
 * @param StartTimeOut Current value of selected counter.
 * @param ElapsedTimeOut Reset elapsed time to 0.
 * @param TimeoutTicksOut TimeoutUs converted from microsecond units to ticks units.
 * @param TimeoutUs Timeout value in microsecond.
 */
static inline void Netc_EthSwt_Ip_StartTimeOut( uint32 *StartTimeOut,
                                                uint32 *ElapsedTimeOut,
                                                uint32 *TimeoutTicksOut,
                                                uint32 TimeoutUs
                                              );

/**
 * @brief Checks for timeout expiration condition.
 *
 * @param StartTimeInOut Initial value of the counter.
 * @param ElapsedTimeInOut Current ticks passed.
 * @param TimeoutTicks Number of ticks after timout will be activated.
 *
 * @return boolean TRUE  - timout activated.
 *                 FALSE - timeout is not yet reached.
 */
static inline boolean Netc_EthSwt_Ip_TimeoutExpired( uint32 *StartTimeInOut,
                                                     uint32 *ElapsedTimeInOut,
                                                     uint32 TimeoutTicks
                                                   );

#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
/**
 * @brief            FDB table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigFDBTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES > 0U)
/**
 * @brief            IPF table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigIPFTable(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
/**
 * @brief            IngressStreamIdentification table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigISITable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES > 0U)
/**
 * @brief            IngressSequenceGeneration table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigSeqGenTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES > 0U)
/**
 * @brief            EgressSequenceRecovery table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigSeqRecTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES > 0U)
/**
 * @brief            FrameModification table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigFrmModificationTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES > 0U)
/**
 * @brief            EgressTreatment table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigEgressTreatmentTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
/**
 * @brief            IngressStream table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigIngressStreamTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES > 0U)
/**
 * @brief            Ingress Stream Filter table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigIngressStreamFilterTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_STREAMCOUNT_ENTRIES > 0U)
/**
 * @brief            IngressStreamCount table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigIngressStreamCountTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
/**
 * @brief            VLAN filter table configuration function
 *
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigVLANFilterTable(const Netc_EthSwt_Ip_ConfigType * Config);
#endif

/**
 * @brief            Time aware shaper configuration function
 *
 * @param[in]        SwitchIdx: Switch ID
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigTAS(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);

/**
 * @brief            Switch registers and ports configuration function
 *
 * @param[in]        SwitchIdx: Switch ID
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigSwt(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);

/**
 * @brief inline function for enabling PCIE access for the timer, MDIO, switch and ENETC
 *
 * @return Std_ReturnType
 * @retval E_OK: success
 * @retval E_NOT_OK: timeout has occured
 */
static inline void Netc_EthSwt_Ip_EnablePCIE(void);

static inline Std_ReturnType Netc_EthSwt_Ip_PortRateEnumToRate(EthTrcv_BaudRateType baudRate, uint64 *portTxRate);

static Std_ReturnType Netc_EthSwt_Ip_IerbReady(void);

static inline void Netc_EthSwt_Ip_FillInTableDataBuffForSearchingFDBTable(const uint32 * ActionsData, const uint32 * ResumeEntryId, const Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType * SearchCriteriaData);

static inline Std_ReturnType Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable( uint8 SwitchIdx,
                                                                         Netc_EthSwt_Ip_ResumeEntryEntryId * ResumeEntryEntryId, uint32 * agingCount, boolean * FoundEntry
                                                                       );

static inline Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteFdbTableEntryById( uint8 SwitchIdx,
                                                                                    uint32 EntryId
                                                                                  );

#if(NETC_ETHSWT_IP_CONFIG_LINK_PROTOCOL == STD_ON)
/**
 * @brief            Config link protocol for switch mac ports.
 * @details
 *
 * @param[in]        SwitchIdx                      Index of the switch within the context of the Ethernet Switch Driver
 * @param[in]        SwitchPortIdx                  Index of the port at the addressed switch
 * @param[in]        EthSwtPortPhysicalLayerType    Supported MII protocol: 0 MII, 1 RMII, 2 RGMII
 *
 */
static void Netc_EthSwt_Ip_ConfigLinkProtocol(uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType);
#endif

#if (NETC_ETHSWT_NUMBER_OF_RP_ENTRIES > 0U)
/**
 * @brief            Rate policer configuration function
 *
 * @param[in]        SwitchIdx: Switch ID
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigRP(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES > 0U)
/**
 * @brief            Stream Gate Control List configuration function
 *
 * @param[in]        SwitchIdx: Switch ID
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigSGCL(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES > 0U)
/**
 * @brief            Stream Gate Instance configuration function
 *
 * @param[in]        SwitchIdx: Switch ID
 * @param[in]        Config: Pointer to the configuration of one Ethernet Switch for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Std_ReturnType Netc_EthSwt_Ip_ConfigSGI(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config);
#endif

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static inline void Netc_EthSwt_Ip_StartTimeOut( uint32 *StartTimeOut,
                                                uint32 *ElapsedTimeOut,
                                                uint32 *TimeoutTicksOut,
                                                uint32 TimeoutUs
                                              )
{
    *StartTimeOut    = OsIf_GetCounter(NETC_ETHSWT_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, NETC_ETHSWT_IP_TIMEOUT_TYPE);
}

static inline boolean Netc_EthSwt_Ip_TimeoutExpired( uint32 *StartTimeInOut,
                                                     uint32 *ElapsedTimeInOut,
                                                     uint32 TimeoutTicks
                                                   )
{
    uint32 elapsedTime;

    /* get elapsed ticks */
    elapsedTime = OsIf_GetElapsed(StartTimeInOut, NETC_ETHSWT_IP_TIMEOUT_TYPE);

    /* Need to verify overflow of addition */
    if(((uint64)elapsedTime + *ElapsedTimeInOut) < ((uint32)MAX_32BIT))
    {
        *ElapsedTimeInOut += elapsedTime;
    }
    else
    {
        *ElapsedTimeInOut = ((uint32)MAX_32BIT);
    }

    return ((*ElapsedTimeInOut >= TimeoutTicks) ? TRUE : FALSE);
}

/**
 * @brief Internal function used by Netc_EthSwt_Ip_AddStreamGateControlListTableEntry function
*
*  @param SGCLTableEntry Pointer points to a Stream Gate Control List entry structure Netc_EthSwt_Ip_SGCLTableDataType
 */
static inline void Netc_EthSwt_Ip_AddStreamGateControlListTableEntry_FillListEntriesData(const Netc_EthSwt_Ip_SGCLTableDataType* SGCLTableEntry)
{
    uint8 ListIdx;
    if (SGCLTableEntry->Cfge_ListLength > 0U)
    {
        for (ListIdx = 0U; ListIdx < SGCLTableEntry->Cfge_ListLength; ListIdx++)
        {
            TableDataBuffer.TableDataField[(uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2 + (2U * ListIdx)] = SGCLTableEntry->ListEntries[ListIdx].SGCL_TimeInterval;
            TableDataBuffer.TableDataField[(uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3 + (2U * ListIdx)] = NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM(SGCLTableEntry->ListEntries[ListIdx].SGCL_IntervalOctetsMax) \
                                                                                                        | NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV(SGCLTableEntry->ListEntries[ListIdx].SGCL_Ipv) \
                                                                                                        | NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV((SGCLTableEntry->ListEntries[ListIdx].SGCL_Oipv) ? 1U : 0U) \
                                                                                                        | NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD((SGCLTableEntry->ListEntries[ListIdx].SGCL_Ctd) ? 1U : 0U) \
                                                                                                        | NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN((SGCLTableEntry->ListEntries[ListIdx].SGCL_IntervalOctetMaxEnable) ? 1U : 0U) \
                                                                                                        | NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST(SGCLTableEntry->ListEntries[ListIdx].SGCL_GateState);
        }
    }
}
/**
 * @brief Internal function used by Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry function
*
 * @param[in]        ResumeEntryId          resume entry id for searching
 * @param[inout]     IngressStreamFilterTableEntry A pointer that returns the data of a matched entry by "search" operation
 *                                            The data is valid only when MatchedEntry equals 1.
 */
static inline void Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry_FoundAMatchedEntry(uint32 * ResumeEntryId,
                                                                                         Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                        )
{
    uint8 SduType;
    uint32 CfgeConfigBits;

    /* fill in "Netc_EthSwt_Ip_IngressStreamFilterEntryDataType" structure with data in response data buffer */
    *ResumeEntryId = TableDataBuffer.TableDataField[0U];        /* update the resume entry id for next search */
    IngressStreamFilterTableEntry->IngressStreamFilterEntryId = TableDataBuffer.TableDataField[1U];
    /* fill in KEYE_DATA */
    IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.IngressStream_EID = TableDataBuffer.TableDataField[2U];
    IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.Pcp = (uint8)(TableDataBuffer.TableDataField[3U] & NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_MASK);
    /* fill in CFGE data */
    CfgeConfigBits = TableDataBuffer.TableDataField[4U];
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.InternalPriorityValue = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_SHIFT);
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideIPV = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.DropResilience = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_SHIFT);
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideDR = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.IngressMirroringEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.TimeStampCaptureEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideRatePolicerInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideStreamGateInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.CutThrDisable = (CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_SHIFT;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.MaximumServiceDataUnit = (uint16)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_SHIFT);

    SduType = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_SHIFT);
    switch (SduType)
    {
        case 0U:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_PPDU;
            break;
        case 1U:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_MPDU;
            break;
        case 2U:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_MSDU;
            break;
        default:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_RSDTYPE;
            break;
    }

    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.RatePolicer_EID = TableDataBuffer.TableDataField[5U];
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.StreamGateInstance_EID = TableDataBuffer.TableDataField[6U];
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.IngressStreamCounter_EID = TableDataBuffer.TableDataField[7U];
}

/**
 * @brief Internal function used by Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry function
*
 * @param[inout]       SGCLTableEntryRspData  A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 */
static inline void Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry_FoundAMatchedEntry(Netc_EthSwt_Ip_SGCLTableDataType* SGCLTableEntryRspData)
{
    uint32 ConfigBits;
    uint8 ListIdx;
    /* fill in "Netc_EthSwt_Ip_SGCLTableDataType" structure with data in response data buffer */
    SGCLTableEntryRspData->SGCLEntryId = TableDataBuffer.TableDataField[0U];
    /* fill in SGCLSE_DATA */
    SGCLTableEntryRspData->Sgclse_RefCount = (TableDataBuffer.TableDataField[1U] & NETC_ETHSWT_IP_SGCLTABLE_SGCLSE_REFCOUNT_MASK);
    /* fill in CFGE data */
    SGCLTableEntryRspData->Cfge_CycleTime = TableDataBuffer.TableDataField[2U];
    ConfigBits = TableDataBuffer.TableDataField[3U];
    SGCLTableEntryRspData->Cfge_ListLength = (uint8)(ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN_MASK) + 1U;
    SGCLTableEntryRspData->Cfge_ExtIpv = (uint8)((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV_MASK) >> NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV_SHIFT);
    SGCLTableEntryRspData->Cfge_ExtOIPV = ((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV_MASK) == 0x0UL) ? FALSE : TRUE;
    SGCLTableEntryRspData->Cfge_ExtCtd = ((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD_MASK) == 0x0UL) ? FALSE : TRUE;
    SGCLTableEntryRspData->Cfge_ExtGtst = (ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST_MASK) >> NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST_SHIFT;

    if (SGCLTableEntryRspData->Cfge_ListLength > 0U)
    {
        for (ListIdx = 0U; ListIdx < SGCLTableEntryRspData->Cfge_ListLength; ListIdx++)
        {
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_TimeInterval = TableDataBuffer.TableDataField[4U + (2U * ListIdx)];
            ConfigBits = TableDataBuffer.TableDataField[5U + (2U * ListIdx)];
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_IntervalOctetsMax = ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOM_MASK;
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_Ipv = (uint8)((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV_MASK) >> NETC_ETHSWT_IP_SGCLTABLE_CFGE_IPV_SHIFT);
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_Oipv = ((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_OIPV_MASK) == 0x0UL) ?  FALSE : TRUE;
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_Ctd = ((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_CTD_MASK) == 0x0UL) ?  FALSE : TRUE;
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_IntervalOctetMaxEnable = ((ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_IOMEN_MASK) == 0x0UL) ?  FALSE : TRUE;
            SGCLTableEntryRspData->ListEntries[ListIdx].SGCL_GateState = (ConfigBits & NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST_MASK) >> NETC_ETHSWT_IP_SGCLTABLE_CFGE_GTST_SHIFT;
        }
    }
}

/**
 * @brief Internal function used by Netc_EthSwt_Ip_QueryRatePolicerTableEntry function
 *
 * @param[inout]       RatePolicerTableEntry  A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 */
static inline void Netc_EthSwt_Ip_QueryRatePolicerTableEntry_FoundAMatchedEntry(Netc_EthSwt_Ip_RatePolicerEntryRspDataType * RatePolicerTableEntry)
{
    uint32 CfgeConfigBits;
    uint8 SduType;

    /* fill in "Netc_EthSwt_Ip_RatePolicerEntryDataType" structure with data in response data buffer */
    RatePolicerTableEntry->RatePolicerEntryId = TableDataBuffer.TableDataField[0U];
    /* fill in STSE data */
    RatePolicerTableEntry->RatePolicerStseData.Stse_ByteCount = (((uint64)TableDataBuffer.TableDataField[2U]) << NETC_ETHSWT_IP_32BIT_SHIFT);
    RatePolicerTableEntry->RatePolicerStseData.Stse_ByteCount |= (uint64)(TableDataBuffer.TableDataField[1U]);
    RatePolicerTableEntry->RatePolicerStseData.Stse_DropFrames = TableDataBuffer.TableDataField[3U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_Dr0GrnFrames = TableDataBuffer.TableDataField[5U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_Dr1GrnFrames = TableDataBuffer.TableDataField[7U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_Dr2YlwFrames = TableDataBuffer.TableDataField[9U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_RemarkYlwFrames = TableDataBuffer.TableDataField[11U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_Dr3RedFrames = TableDataBuffer.TableDataField[13U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_RemarkRedFrames = TableDataBuffer.TableDataField[15U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_Lts = TableDataBuffer.TableDataField[17U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_CommittedTokenBucketInteger = TableDataBuffer.TableDataField[18U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_CommittedTokenBucketFractional = TableDataBuffer.TableDataField[19U];   /* 1 sign bit + 31 bits fractional */
    RatePolicerTableEntry->RatePolicerStseData.Stse_ExcessTokenBucketInteger = TableDataBuffer.TableDataField[20U];
    RatePolicerTableEntry->RatePolicerStseData.Stse_ExcessTokenBucketFractional = TableDataBuffer.TableDataField[21U];     /* 1 sign bit + 31 bits fractional */
    /* fill in CFGE data */
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cir = TableDataBuffer.TableDataField[22U];
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cbs = TableDataBuffer.TableDataField[23U];
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Eir = TableDataBuffer.TableDataField[24U];
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ebs = TableDataBuffer.TableDataField[25U];
    CfgeConfigBits = TableDataBuffer.TableDataField[26U];
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Mren = ((CfgeConfigBits & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK) == 0U) ? FALSE : TRUE;
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Doy = ((CfgeConfigBits & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_MASK) == 0U) ? FALSE : TRUE;
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cm = ((CfgeConfigBits & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM_MASK) == 0U) ? FALSE : TRUE;
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cf = ((CfgeConfigBits & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF_MASK) == 0U) ? FALSE : TRUE;
    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ndor = ((CfgeConfigBits & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_MASK) == 0U) ? FALSE : TRUE;
    SduType = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_MASK) >> NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_SHIFT);
    switch (SduType)
    {
        case 0U:
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETHSWT_IP_PPDU;
            break;
        case 1U:
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETHSWT_IP_MPDU;
            break;
        case 2U:
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETHSWT_IP_MSDU;
            break;
        default:
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETHSWT_IP_RSDTYPE;
            break;
    }
    /* fill FEE data */
    RatePolicerTableEntry->RatePolicerFunctionEnable = (((CfgeConfigBits >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN_MASK) == 0U) ? FALSE : TRUE;
    /* fill PSE data */
    RatePolicerTableEntry->MarkRedFlag = (((CfgeConfigBits >> NETC_ETHSWT_IP_24BIT_SHIFT) & NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK) == 0U) ? FALSE : TRUE;
}

/**
 * @brief Internal function used by Netc_EthSwt_Ip_QueryIngressStreamTableEntry function
 *
 * @param[inout]       IngressStreamTableEntry  A pointer that returns the data of a matched entry by "search" operation
 *                                            The data is valid only when MatchedEntry equals 1.
 */
static inline void Netc_EthSwt_Ip_QueryIngressStreamTableEntry_FoundAMatchedEntry(Netc_EthSwt_Ip_IngressStreamEntryDataType* IngressStreamTableEntry)
{
    uint32 CfgeConfigBits;
    uint8 SduType;
    /* fill in "Netc_EthSwt_Ip_IngressStreamEntryDataType" structure with data in response data buffer */
    IngressStreamTableEntry->IngressStreamEntryId = TableDataBuffer.TableDataField[0U];
    /* fill in CFGE data */
    CfgeConfigBits = TableDataBuffer.TableDataField[1U];
    IngressStreamTableEntry->IngressStreamCfgeData.StreamFilteringEnable = ((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE_MASK) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.InternalPriorityValue = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.OverrideIPV = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.DropResilience = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.OverrideDR = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.IngressMirroringEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.TimeStampCaptureEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.SrcPortPruningDisable = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.IngressSeqAction = ((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.OverrideRatePolicerInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.OverrideStreamGateInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamTableEntry->IngressStreamCfgeData.HostReason = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.ForwardingActions = ((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA_SHIFT);
    SduType = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_SHIFT);
    switch (SduType)
    {
        case 0U:
            IngressStreamTableEntry->IngressStreamCfgeData.SduType = NETC_ETHSWT_IP_PPDU;
            break;
        case 1U:
            IngressStreamTableEntry->IngressStreamCfgeData.SduType = NETC_ETHSWT_IP_MPDU;
            break;
        case 2U:
            IngressStreamTableEntry->IngressStreamCfgeData.SduType = NETC_ETHSWT_IP_MSDU;
            break;
        default:
            IngressStreamTableEntry->IngressStreamCfgeData.SduType = NETC_ETHSWT_IP_RSDTYPE;
            break;
    }

    CfgeConfigBits = TableDataBuffer.TableDataField[2U];
    IngressStreamTableEntry->IngressStreamCfgeData.MaximumServiceDataUnit = (uint16)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.IngressFrmModiEntryFrmLenChange = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.EgressPort = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.OverrideET_EID = ((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID_SHIFT);
    IngressStreamTableEntry->IngressStreamCfgeData.CutThrDisable = ((CfgeConfigBits & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD_MASK) >> NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD_SHIFT);

    IngressStreamTableEntry->IngressStreamCfgeData.IngressSeqGeneration_EID = TableDataBuffer.TableDataField[3U];
    IngressStreamTableEntry->IngressStreamCfgeData.RatePolicer_EID = TableDataBuffer.TableDataField[4U];
    IngressStreamTableEntry->IngressStreamCfgeData.StreamGateInstance_EID = TableDataBuffer.TableDataField[5U];
    IngressStreamTableEntry->IngressStreamCfgeData.IngressFrmModification_EID = TableDataBuffer.TableDataField[6U];
    IngressStreamTableEntry->IngressStreamCfgeData.EgressTreatment_EID = TableDataBuffer.TableDataField[7U];
    IngressStreamTableEntry->IngressStreamCfgeData.IngressStreamCounter_EID = TableDataBuffer.TableDataField[8U];
    IngressStreamTableEntry->IngressStreamCfgeData.EgressPortBitMap = TableDataBuffer.TableDataField[9U] & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_MASK;
    IngressStreamTableEntry->IngressStreamCfgeData.StationInterfaceMap = (uint16)(TableDataBuffer.TableDataField[10U] & NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_MASK);
}

/**
 * @brief Internal function used by Netc_EthSwt_Ip_QueryIngressStreamTableEntry function
 *
 * @param[inout]       IngressStreamFilterTableEntry  A pointer that returns the data of a matched entry by "search" operation
 *                                            The data is valid only when MatchedEntry equals 1.
 */
static inline void Netc_EthSwt_Ip_QueryIngressStreamFilterTableEntry_FoundAMatchedEntry(Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry)
{
    uint32 CfgeConfigBits;
    uint8 SduType;
    /* fill in "Netc_EthSwt_Ip_IngressStreamFilterEntryDataType" structure with data in response data buffer */
    IngressStreamFilterTableEntry->IngressStreamFilterEntryId = TableDataBuffer.TableDataField[1U];
    /* fill in KEYE_DATA */
    IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.IngressStream_EID = TableDataBuffer.TableDataField[2U];
    IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.Pcp = (uint8)(TableDataBuffer.TableDataField[3U] & NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_MASK);
    /* fill in CFGE data */
    CfgeConfigBits = TableDataBuffer.TableDataField[4U];
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.InternalPriorityValue = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_SHIFT);
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideIPV = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.DropResilience = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_SHIFT);
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideDR = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.IngressMirroringEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.TimeStampCaptureEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideRatePolicerInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideStreamGateInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_SHIFT) > 0U) ? TRUE : FALSE;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.CutThrDisable = (CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_SHIFT;
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.MaximumServiceDataUnit = (uint16)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_SHIFT);

    SduType = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_SHIFT);
    switch (SduType)
    {
        case 0U:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_PPDU;
            break;
        case 1U:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_MPDU;
            break;
        case 2U:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_MSDU;
            break;
        default:
            IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_RSDTYPE;
            break;
    }

    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.RatePolicer_EID = TableDataBuffer.TableDataField[5U];
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.StreamGateInstance_EID = TableDataBuffer.TableDataField[6U];
    IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.IngressStreamCounter_EID = TableDataBuffer.TableDataField[7U];
}

/**
 * @brief            Internal function used by Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntry function
 *
 * @param[in]        RatePolicerTableEntry  Pointer points to a Rate policer entry structure Netc_EthSwt_Ip_RatePolicerEntryDataType
 * @return uint32 action data
 *
 */
static inline uint32 Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntryGetActionsData(const Netc_EthSwt_Ip_RatePolicerEntryDataType * RatePolicerTableEntry)
{
    uint32 ActionsData;
    ActionsData = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(RatePolicerTableEntry->ConfigurationElementUpdate ? 1U : 0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_FEEU(RatePolicerTableEntry->FunctionalEnableElementUpdate ? 1U : 0U)) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_PSEU(RatePolicerTableEntry->PolicerStateElementUpdate ? 1U : 0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_STSEU(RatePolicerTableEntry->StatisticsElementUpdate ? 1U : 0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);
    return ActionsData;
}


/**
 * @brief            Internal function used by Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntryInitTableRequest function
 *
 * @param[in]        RatePolicerTableEntry  Pointer points to a Rate policer entry structure Netc_EthSwt_Ip_RatePolicerEntryDataType
 * @param[in]        ActionsData
 *
 */
static inline void Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntryInitTableRequest(const Netc_EthSwt_Ip_RatePolicerEntryDataType * RatePolicerTableEntry, uint32 ActionsData)
{
/* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = RatePolicerTableEntry->RatePolicerEntryId;        /* fill in Entry_ID field (Access Key) */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cir;  /* CFGE CIR field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cbs;  /* CFGE CBS field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Eir;  /* CFGE EIR field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ebs;  /* CFGE EBS field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_MREN((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Mren) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_DOY((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Doy) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CM((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cm) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_CF((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cf) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ndor) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE(RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType);
        /* fill in Functional Enable Element Data */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] |= (NETC_ETHSWT_IP_RATEPOLICERTABLE_FEE_DATA_FEN(RatePolicerTableEntry->RatePolicerFunctionEnable ? 1U : 0U) << NETC_ETHSWT_IP_16BIT_SHIFT);
}

/**
 * @brief            Internal function used by Netc_EthSwt_Ip_SetPortSpeed function
 *
 * @param[in]        BaudRate                       ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection
 *                                                  ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
 *                                                  ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
 * @param[inout]       interfaceModeConfig            used for shaping of the port
 * @param[inout]       shapingPSpeedConfig            used for shaping of the port
 * @retval           E_OK        success
 * @retval           E_NOT_OK    Baud rate of the indexed switch port could not be changed
 *
 */
static inline Std_ReturnType Netc_EthSwt_Ip_SetPortSpeed_MII_RMII_Mode(EthTrcv_BaudRateType BaudRate, uint32* const interfaceModeConfig, uint32* const shapingPSpeedConfig)
{
    Std_ReturnType status = E_OK;
    if(BaudRate == ETHTRCV_BAUD_RATE_10MBIT)
    {
        *interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK;
        *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
    }
    else if(BaudRate == ETHTRCV_BAUD_RATE_100MBIT)
    {
        *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK);
        *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
    }
    else
    {
        status = E_NOT_OK;
    }
    return status;
}

/**
 * @brief            Internal function used by Netc_EthSwt_Ip_SetPortSpeed function
 *
 * @param[in]        BaudRate                       ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection
 *                                                  ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
 *                                                  ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
 * @param[inout]       interfaceModeConfig            used for shaping of the port
 * @param[inout]       shapingPSpeedConfig            used for shaping of the port
 * @retval           E_OK        success
 * @retval           E_NOT_OK    Baud rate of the indexed switch port could not be changed
 *
 */
static inline Std_ReturnType Netc_EthSwt_Ip_SetPortSpeed_RGMII_Mode(EthTrcv_BaudRateType BaudRate, uint32* const interfaceModeConfig, uint32* const shapingPSpeedConfig)
{
    Std_ReturnType status = E_OK;
    switch(BaudRate)
    {
        case ETHTRCV_BAUD_RATE_10MBIT: /* 10Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_10MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_100MBIT: /* 100Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_100MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_1000MBIT: /* 1000Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS;
            break;
        }
        default:
        {
            status = E_NOT_OK;
            break;
        }
    }
    return status;
}


/**
 * @brief            Internal function used by Netc_EthSwt_Ip_SetPortSpeed function
 *
 * @param[in]        BaudRate                       ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection
 *                                                  ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
 *                                                  ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
 * @param[inout]       interfaceModeConfig            used for shaping of the port
 * @param[inout]       shapingPSpeedConfig            used for shaping of the port
 * @retval           E_OK        success
 * @retval           E_NOT_OK    Baud rate of the indexed switch port could not be changed
 *
 */
static inline Std_ReturnType Netc_EthSwt_Ip_SetPortSpeed_SGMII_Mode(EthTrcv_BaudRateType BaudRate, uint32* const interfaceModeConfig, uint32* const shapingPSpeedConfig)
{
    Std_ReturnType status = E_OK;
    switch(BaudRate)
    {
        case ETHTRCV_BAUD_RATE_10MBIT: /* 10Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_10MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_100MBIT: /* 100Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_100MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_1000MBIT: /* 1000Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_2500MBIT: /* 2500Mbps */
        {
            *interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
            *interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT));
            *shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_2500MBITS;
            break;
        }
        default:
        {
            status = E_NOT_OK;
            break;
        }
    }
    return status;
}

static inline void Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable_FoundAMatchedEntry(uint32 * const EntryId, uint32 * const agingCount,  boolean * const FoundEntry, const uint32 NumOfElement)
{
    uint32 TableEntryId;
    uint32 ActionsDataResponse;

    /* found a matched entry */
    TableEntryId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
    if ((1U == NumOfElement) && (TableEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
    {
        *EntryId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_ENTRYID];
        ActionsDataResponse = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_ACTEDATA];
        *agingCount = (ActionsDataResponse & NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_CNT_MASK);
        /* Predicting the update action effect after the search */
        if(NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG_INACTIVE_FIELD ==
           (ActionsDataResponse & NETC_ETHSWT_IP_FDBTABLE_REPFMT_ACTE_DATA_FIELD_ACT_FLAG_MASK))
        {
            if(*agingCount<=NETC_ETHSWT_IP_NUM_AGING_CYCLE)
            {
                *agingCount += 1U;
            }
        }
        else
        {
            *agingCount = 0U;
        }
        *FoundEntry = TRUE;
    }
}

static inline void Netc_EthSwt_Ip_QueryFdbTableEntry_FoundAMatchedEntry(const uint32 MatchedEntries, Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry)
{
    uint32 MacAddrL;
    uint32 MacAddrH;
    uint32 CfgeData;
    uint8 MacByteIdx;

    /* found a matched entry */
    if (1U == MatchedEntries)
    {
        /* fill in "Netc_EthSwt_Ip_FdbEntryDataType" structure with data in response data buffer */
        MacAddrL = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_L];
        MacAddrH = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_H];
        for (MacByteIdx = 0U; MacByteIdx < 4U; MacByteIdx++ )
        {
            FdbTableEntry->MacAddr[MacByteIdx] = (uint8)(MacAddrL & NETC_ETHSWT_IP_0XFF_MASK);
            MacAddrL >>= 8U;
        }
        FdbTableEntry->MacAddr[4U] = (uint8)(MacAddrH & NETC_ETHSWT_IP_0XFF_MASK);
        FdbTableEntry->MacAddr[5U] = (uint8)((MacAddrH >> 8U) & NETC_ETHSWT_IP_0XFF_MASK);

        FdbTableEntry->FID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_FID] & NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_MASK);
        FdbTableEntry->SwitchPortEgressBitMask = (TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_PORTBITMAP] & NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_MASK);

        CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_CFGECONFIG];
        FdbTableEntry->TimeStampCapture = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_SHIFT) != 0x0UL) ? TRUE : FALSE;
        FdbTableEntry->DynamicEntry = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_SHIFT) != 0x0UL) ? TRUE : FALSE;
        FdbTableEntry->CutThroughDisable = (uint8)((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_SHIFT);
        FdbTableEntry->IngressMirroringEnable = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_SHIFT) != 0x0UL) ? TRUE : FALSE;
        FdbTableEntry->EgressPort = (uint8)((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_SHIFT);
        FdbTableEntry->OverridETEID = (uint8)(CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_MASK);

        FdbTableEntry->ET_EID = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_ETEID];
    }
}

static inline void Netc_EthSwt_Ip_WriteMirrorConfiguration_EnablePortMirror(const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr)
{
    uint32 IngressBitMask;
    uint8 PortIdx;
    /* Enable port mirroring according to TrafficDirectionIngressBitMask */
    IngressBitMask = MirrorConfigurationPtr->TrafficDirectionIngressBitMask;
    for(PortIdx = 0U; PortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS; PortIdx++)
    {
        if((IngressBitMask & 0x1U) == 0x1U)
        {
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIdx]->PMCR = (uint32)0x1U;
        }
        IngressBitMask >>= 1U;
    }
}


static inline void Netc_EthSwt_Ip_WriteMirrorConfiguration_SecondPart(uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr, Std_ReturnType* Status)
{
    Netc_EthSwt_Ip_IngressPortFilterSrcDestAddrFilter IngressPortFilterSrcDestAddrFilter = {FALSE, FALSE};
    Netc_EthSwt_Ip_IngressPortFilterEntryDataType IngressPortFilterTableEntry = {0};
    /* check if Mac Address Filter enabled */
    Netc_EthSwt_Ip_CheckMacAddressFilterEnableFlag(&IngressPortFilterSrcDestAddrFilter, MirrorConfigurationPtr);

    /* Start writing mirroring configuration */
    /* #1 */
    if ((MirrorConfigurationPtr->VlanIdFilter == NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID) && (IngressPortFilterSrcDestAddrFilter.DstMacAddrFilterEnabled == FALSE) && (IngressPortFilterSrcDestAddrFilter.SrcMacAddrFilterEnabled == FALSE))
    {
        /* Enable port mirroring according to TrafficDirectionIngressBitMask */
        Netc_EthSwt_Ip_WriteMirrorConfiguration_EnablePortMirror(MirrorConfigurationPtr);
    }
    else    /* #2 ingress port filtering */
    {
        /* Config and add the ingress port filter table entry for ingress frames filtering */
        *Status |= Netc_EthSwt_Ip_ConfigIngressPortFilterForPortMirroring(MirroredSwitchIdx, IngressPortFilterSrcDestAddrFilter, MirrorConfigurationPtr, &IngressPortFilterTableEntry);
    }

    /* #3 egress frame modification */
    *Status |= Netc_EthSwt_Ip_ConfigEgressFrameModificationForPortMirroring(MirroredSwitchIdx, MirrorConfigurationPtr);
}


static Std_ReturnType Netc_EthSwt_Ip_IerbReady(void)
{
    Std_ReturnType Status = E_NOT_OK;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    /* Verify ready and IERB is valid */
    /* Setup timeout timer */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do
    {
        #ifdef MCAL_ENABLE_FAULT_INJECTION
            MCAL_FAULT_INJECTION_POINT(ETHSWT_CHECK_OSR_STATE_TIMEOUT);
        #endif
        if (
             (0UL == (IP_NETC__SW0_COMMON->OSR & NETC_F2_COMMON_OSR_STATE_MASK)) &&
             (0UL == (IP_NETC__SW0_COMMON->OSR & NETC_F2_COMMON_OSR_ITM_STATE_MASK))
           )
        {
            Status = E_OK;
            break;
        }
    }while(!Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

static inline Std_ReturnType Netc_EthSwt_Ip_PortRateEnumToRate(EthTrcv_BaudRateType baudRate, uint64 *portTxRate)
{
    Std_ReturnType status = E_OK;
    /* Translate enum in uint32 for calculations and PSPEED config */
    switch(baudRate) {
    case ETHTRCV_BAUD_RATE_10MBIT:
        *portTxRate = 10000000UL;
        break;
    case ETHTRCV_BAUD_RATE_100MBIT:
        *portTxRate = 100000000UL;
        break;
    case ETHTRCV_BAUD_RATE_1000MBIT:
        *portTxRate = 1000000000UL;
        break;
    default:
        *portTxRate = 1000000000UL;
        status = E_NOT_OK;
        break;
    };
    return status;
}

static inline Netc_EthSwt_Ip_CBDRStatusType  Netc_EthSwt_Ip_GetPortMacAddr_SecondPart(uint8 SwitchIdx,
                                                                                      uint32* const NumOfMatchedElement,
                                                                                      Netc_EthSwt_Ip_FdbEntryDataType* const FdbTableEntry,
                                                                                      Netc_EthSwt_Ip_PortMacAddrEntry* const PortMacAddrEntry)
{
    Netc_EthSwt_Ip_CBDRStatusType QueryStatus;
    Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType SearchCriteriaData = {0U};
    uint32 ResumeEntryId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;
    uint8 MacByteIdx;

    do
    {
        *NumOfMatchedElement = 1;    /* set the flag for finding a matched entry */
        SearchCriteriaData.SearchMatchCriteria = NETC_ETHSWT_IP_FDBTABLE_MATCH_ANY_CRITERIA;
        QueryStatus = Netc_EthSwt_Ip_SearchFdbTable(SwitchIdx, &ResumeEntryId, &SearchCriteriaData, FdbTableEntry);

        /* check if we found a matched entry */
        for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
        {
            if (FdbTableEntry->MacAddr[MacByteIdx] != PortMacAddrEntry->MacAddr[MacByteIdx])
            {
                *NumOfMatchedElement = 0U;
                break;
            }
        }

        /* find a matched entry */
        if (1U == *NumOfMatchedElement)
        {
            PortMacAddrEntry->MatchedEntryFound = TRUE;
            /* get the port bitmap value from Fdb table response data buffer. */
            PortMacAddrEntry->PortBitMap |= FdbTableEntry->SwitchPortEgressBitMask;    /* for those FDB entries that have same mac address but different bit mask and FID, we will do the 'or' operation for bit mask */
        }
    } while (ResumeEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID);
    return QueryStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EMDIOConfiguration
 * Description   : function for configuring the EMDIO
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_EMDIOConfiguration( uint8 SwitchIdx );

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable
 * Description   : Ethernet Switch search entry ID in FDB table and increment aging count.
 *END**************************************************************************/
static inline Std_ReturnType Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable( uint8 SwitchIdx,
                                                                         Netc_EthSwt_Ip_ResumeEntryEntryId * ResumeEntryEntryId, uint32 * agingCount, boolean * FoundEntry
                                                                       )
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 NumOfElement = 0U;
    uint32 ActionsData;

    Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType SearchCriteriaData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif
    *FoundEntry = FALSE;
    SearchCriteriaData.SearchResumeEntryId=0U;
    SearchCriteriaData.SearchActeData.ActivityCounter=0U;
    SearchCriteriaData.SearchActeData.ActivityFlag=FALSE;
    SearchCriteriaData.SearchCfgeData.SearchPortBitMap=0U;
    SearchCriteriaData.SearchKeyeData.SearchFid=0U;
    SearchCriteriaData.SearchKeyeData.SearchMulticastMacAddr=FALSE;

    SearchCriteriaData.SearchMatchCriteria = (NETC_ETHSWT_IP_FDBTABLE_MATCH_CFGE_DYNAMIC_FIELD);    /* Match DYNAMIC field */
    SearchCriteriaData.SearchCfgeData.SearchDynamicEntry = TRUE;                                   /* Search DYNAMIC entry */

    /* +++ fill in FdbTabeDataBuffer for request +++ */
    /* set the query options with full query */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(1U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(0U);
    Netc_EthSwt_Ip_FillInTableDataBuffForSearchingFDBTable(&ActionsData, &(ResumeEntryEntryId->ResumeEntryId), &SearchCriteriaData);
    /* --- fill in FdbTabeDataBuffer for request --- */

    /* do the full query with Search Method */
    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_FOLLOWEDBY_UPDATE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_REQBUFFER_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_FDBTABLE_RESBUFFER_LEN);           /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        /* check if found a matched entry */
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* found a matched entry */
        Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable_FoundAMatchedEntry(&(ResumeEntryEntryId->EntryId), agingCount, FoundEntry, NumOfElement);

        /* get the resume_entry_id and be ready for the next query operation */
        /* [notes]: if the searching is completed, or there is no matched entry found, then TableDataBuffer.TableDataField[0U] will be writen with MAX_32BIT by hardware */
        ResumeEntryEntryId->ResumeEntryId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteFdbTableEntryById
 * Description   : Ethernet Switch use the entry ID in FDB table and delete it.
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteFdbTableEntryById( uint8 SwitchIdx,
                                                                             uint32 EntryId
                                                                           )
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 NumOfElement = 0U;
    uint32 EntryStatus;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_42();
    /* +++ fill in FdbTabeDataBuffer for request +++ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = \
                NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(0U);

    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_42();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

    /* send the "Delete" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        /* check if found a matched entry */
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* found a matched entry */
        EntryStatus = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
        if (!((1U == NumOfElement) && (EntryStatus != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID)))
        {
            status = E_NOT_OK;
        }
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

#if (NETC_ETHSWT_NUMBER_OF_RP_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigRP
 * Description   : function for configuring the Rate Policer for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigRP(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint32 RPIndex = 0U;
    uint32 MatchedEntries = 0UL;
    Netc_EthSwt_Ip_RatePolicerEntryDataType RPTableEntry = {0};

    for (RPIndex = 0U; RPIndex < Config->NumberOfRPEntries; RPIndex++)
    {
        RPTableEntry = (*(Config->EthSwtRatePolicerEntries))[RPIndex];
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntry(SwitchIdx, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &RPTableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigSGCL
 * Description   : function for configuring the Stream Gate Control Lists for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigSGCL(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint32 SGCLIndex = 0U;
    uint32 MatchedEntries = 0UL;
    Netc_EthSwt_Ip_SGCLTableDataType SGCLTableEntry = {0};

    for (SGCLIndex = 0U; SGCLIndex < Config->NumberOfSGCLEntries; SGCLIndex++)
    {
        SGCLTableEntry = (*(Config->StreamGateControlListEntries))[SGCLIndex];
        CBDRStatus = Netc_EthSwt_Ip_AddStreamGateControlListTableEntry(SwitchIdx, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &SGCLTableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigSGI
 * Description   : function for configuring the Stream Gate Instance Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigSGI(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint32 SGIIndex = 0U;
    uint32 MatchedEntries = 0UL;
    Netc_EthSwt_Ip_StreamGateInstanceEntryDataType SGITableEntry = {0};

    for (SGIIndex = 0U; SGIIndex < Config->NumberOfSGIEntries; SGIIndex++)
    {
        SGITableEntry = (*(Config->StreamGateInstanceEntries))[SGIIndex];
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateStreamGateInstanceTableEntry(SwitchIdx, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &SGITableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetPortMode
 * Description   : function for setting the port mode
 * implements Netc_EthSwt_Ip_SetPortMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetPortMode(uint8 SwitchIdx,
                                          uint8 SwitchPortIdx,
                                          boolean PortEnable)
{
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void) SwitchIdx;

    if(TRUE == PortEnable)
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_07();
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->POR &= ~(SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK);

        /* Write the PM0_COMMAND_CONFIG only for the MAC ports */
        if (SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
        {
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG |= (SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK | \
                                                                                SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK);
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM1_COMMAND_CONFIG |= (SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_MASK | \
                                                                                SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_MASK);
        }
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_07();

        if (FALSE == Netc_EthSwt_Ip_PortVlanEnable[SwitchPortIdx])
        {
            /* Configure the VLAN filter hash default settings */
            IP_NETC__SW0_BASE->VFHTDECR0 |= (uint32)(1LU << ((uint32)SwitchPortIdx)); /* Add enabled ports to the default VLAN */
        }
    }
    else
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_07();
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->POR |= (SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK);

        /* Write the PM0_COMMAND_CONFIG only for the MAC ports */
        if (SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
        {
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG &= ~(SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK | \
                                                                                 SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK);
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM1_COMMAND_CONFIG &= ~(SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_MASK | \
                                                                                 SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_MASK);
        }
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_07();
    }

    return E_OK;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPortMode
 * Description   : function for getting the port mode
 * implements Netc_EthSwt_Ip_GetPortMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPortMode(uint8 SwitchIdx,
                                          uint8 SwitchPortIdx,
                                          boolean *PortEnable)
{
    uint32 macPortConfig;
    Std_ReturnType status = E_OK;

    (void) SwitchIdx;
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    if (SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        macPortConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG;

        if ( (((SW_ETH_MAC_PORT1_PM0_COMMAND_CONFIG_TX_EN_MASK & macPortConfig) >> SW_ETH_MAC_PORT1_PM0_COMMAND_CONFIG_TX_EN_SHIFT) ^ \
              ((SW_ETH_MAC_PORT1_PM0_COMMAND_CONFIG_RX_EN_MASK & macPortConfig) >> SW_ETH_MAC_PORT1_PM0_COMMAND_CONFIG_RX_EN_SHIFT)) == 1UL
           ) /* Test for different mode for RX and TX with XOR */
        {
            *PortEnable = FALSE;
            status = E_NOT_OK;
        }
        else
        {
            if((macPortConfig & SW_ETH_MAC_PORT1_PM0_COMMAND_CONFIG_TX_EN_MASK) == SW_ETH_MAC_PORT1_PM0_COMMAND_CONFIG_TX_EN_MASK)
            {
                *PortEnable = TRUE;
            }
            else
            {
                *PortEnable = FALSE;
            }
        }
    }
    else
    {
        if (0UL == (Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->POR & (SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK)))
        {
            *PortEnable = TRUE;
        }
        else
        {
            *PortEnable = FALSE;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPortSpeed
 * Description   : Ethernet Switch get baud rate function.
 * implements Netc_EthSwt_Ip_GetPortSpeed_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPortSpeed( uint8 SwitchIdx,
                                            uint8 SwitchPortIdx,
                                            EthTrcv_BaudRateType * BaudRate
                                          )
{
    Std_ReturnType status = E_OK;
    uint32 shapingPSpeedConfig = 0UL; /* used for shaping of the port */

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    shapingPSpeedConfig = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR;

    switch((shapingPSpeedConfig & SW_PORT0_PCR_PSPEED_MASK) >> SW_PORT0_PCR_PSPEED_SHIFT)
    {
        case NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS:
            *BaudRate = ETHTRCV_BAUD_RATE_10MBIT;
            break;
        case NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS:
            *BaudRate = ETHTRCV_BAUD_RATE_100MBIT;
            break;
        case NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS:
            *BaudRate = ETHTRCV_BAUD_RATE_1000MBIT;
            break;
        case NETC_ETHSWT_IP_SHAPING_PSPEED_2500MBITS:
            *BaudRate = ETHTRCV_BAUD_RATE_2500MBIT;
            break;
        default:
            status = E_NOT_OK;
            break;
    }

    (void)SwitchIdx;

    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetPortSpeed
 * Description   : Ethernet Switch set baud rate function.
 * implements Netc_EthSwt_Ip_SetPortSpeed_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetPortSpeed( uint8 SwitchIdx,
                                            uint8 SwitchPortIdx,
                                            EthTrcv_BaudRateType BaudRate
                                          )
{
    Std_ReturnType status = E_OK;
    uint32 interfaceType;
    uint32 interfaceModeConfig = 0UL;
    uint32 shapingPSpeedConfig = 0UL; /* used for shaping of the port */

    (void) SwitchIdx;
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_01();
        interfaceModeConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE;

        interfaceType = ((interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_MASK) >> SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_SHIFT) ;
        switch(interfaceType)
        {
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE: /* MII mode */
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE: /* RMII mode */
            {
                status = Netc_EthSwt_Ip_SetPortSpeed_MII_RMII_Mode(BaudRate, &interfaceModeConfig, &shapingPSpeedConfig);
                break;
            }
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE: /* RGMII mode */
            {
                status = Netc_EthSwt_Ip_SetPortSpeed_RGMII_Mode(BaudRate, &interfaceModeConfig, &shapingPSpeedConfig);
                break;
            }
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_SGMII_MODE: /* SGMII mode */
            {
                status = Netc_EthSwt_Ip_SetPortSpeed_SGMII_Mode(BaudRate, &interfaceModeConfig, &shapingPSpeedConfig);
                break;
            }
            default:
            {
                status = E_NOT_OK;
                break;
            }
        }
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE = interfaceModeConfig;
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM1_IF_MODE = interfaceModeConfig;

        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(shapingPSpeedConfig);
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_01();
    }
    else
    {
    /* pseudo port */
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_01();
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        switch(BaudRate)
        {
            case ETHTRCV_BAUD_RATE_10MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS);
                break;
            case ETHTRCV_BAUD_RATE_100MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS);
                break;
            case ETHTRCV_BAUD_RATE_1000MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS);
                break;
            case ETHTRCV_BAUD_RATE_2500MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_2500MBITS);
                break;
            default:
                status = E_NOT_OK;
                break;
        }
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_01();
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetDuplexMode
 * Description   : Ethernet Switch get duplex mode function.
 * implements Netc_EthSwt_Ip_GetDuplexMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetDuplexMode( uint8 SwitchIdx,
                                             uint8 SwitchPortIdx,
                                             EthTrcv_DuplexModeType * DuplexMode
                                           )
{
    Std_ReturnType status = E_OK;
    uint32 interfaceModeConfig;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void) SwitchIdx;
    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        interfaceModeConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE;

        /* Full duplex is 0 in HD field */
        if (SW_ETH_MAC_PORT1_PM0_IF_MODE_HD_MASK == (interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_HD_MASK))
        {
            *DuplexMode = ETHTRCV_DUPLEX_MODE_HALF;
        }
        else /* ETHTRCV_DUPLEX_MODE_HALF */
        {
            *DuplexMode = ETHTRCV_DUPLEX_MODE_FULL;
        }
    }
    else
    {
        *DuplexMode = ETHTRCV_DUPLEX_MODE_FULL;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetMacAddr
 * Description   : This function sets the MAC address of a certain port of switch
 * implements Netc_EthSwt_Ip_SetMacAddr_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetMacAddr(uint8 SwitchIdx, uint8 PortIndex, const uint8 *MacAddr)
{
    Std_ReturnType status = E_OK;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(PortIndex < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
    DevAssert(MacAddr != NULL_PTR);
#endif

    (void)SwitchIdx;

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PMAR0 = (uint32)(MacAddr[0U]) | ((uint32)(MacAddr[1U]) << 8U) | ((uint32)(MacAddr[2U]) << 16U) | ((uint32)(MacAddr[3U]) << 24U);
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PMAR1 = (uint32)(MacAddr[4U]) | ((uint32)(MacAddr[5U]) << 8U);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetMacAddr
 * Description   : This function reads the MAC address of a certain port
 * implements Netc_EthSwt_Ip_GetMacAddr_Activity
 *END**************************************************************************/
void Netc_EthSwt_Ip_GetMacAddr(uint8 SwitchIdx, uint8 PortIndex, uint8 *MacAddr)
{
    uint32 msbMacAddr;
    uint32 lsbMacAddr;
    uint8 macAddrIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(PortIndex < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
    DevAssert(MacAddr != NULL_PTR);
#endif

    (void)SwitchIdx;

    /* read data from registers */
    msbMacAddr = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PMAR0;
    lsbMacAddr = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PMAR1;

    /* copy mac address in the correct order */
    for (macAddrIdx = 0U; macAddrIdx < 4U; macAddrIdx++)
    {
        MacAddr[macAddrIdx] = (uint8)(msbMacAddr & NETC_ETHSWT_IP_0XFF_MASK);
        msbMacAddr >>= 8U;
    }

    MacAddr[4U] = (uint8)(lsbMacAddr & NETC_ETHSWT_IP_0XFF_MASK);
    lsbMacAddr >>= 8U;
    MacAddr[5U] = (uint8)(lsbMacAddr & NETC_ETHSWT_IP_0XFF_MASK);

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPortMacAddr
 * Description   : Ethernet Switch get port MAC address function.
 * implements Netc_EthSwt_Ip_GetPortMacAddr_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPortMacAddr( uint8 SwitchIdx, uint16 Fid, const uint8 * MacAddr, uint8 * PortIdx )
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType QueryStatus;
    uint8 PortIndex;
    uint8 NumOfMatchedPorts = 0U;
    uint8 MacByteIdx;
    uint32 NumOfMatchedElement = 0x0UL;
    Netc_EthSwt_Ip_FdbEntryDataType FdbTableEntry = {0U};
    Netc_EthSwt_Ip_PortMacAddrEntry PortMacAddrEntry = {FALSE, 0x00UL, MacAddr};

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MacAddr != NULL_PTR);
    DevAssert(PortIdx != NULL_PTR);
#endif

    for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
    {
        FdbTableEntry.MacAddr[MacByteIdx] = MacAddr[MacByteIdx];
    }
    FdbTableEntry.FID = Fid;

    if (FdbTableEntry.FID == NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID)
    {
        QueryStatus = Netc_EthSwt_Ip_GetPortMacAddr_SecondPart(SwitchIdx, &NumOfMatchedElement, &FdbTableEntry, &PortMacAddrEntry);;
    }
    else
    {
        QueryStatus = Netc_EthSwt_Ip_QueryFdbTableEntry(SwitchIdx, &NumOfMatchedElement, &FdbTableEntry);

        /* find a matched entry */
        if (1U == NumOfMatchedElement)
        {
            PortMacAddrEntry.MatchedEntryFound = TRUE;
            /* get the port bitmap value from Fdb table response data buffer */
            PortMacAddrEntry.PortBitMap = FdbTableEntry.SwitchPortEgressBitMask;
        }
    }

    if (QueryStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
        /* find a matched entry */
        if (TRUE == PortMacAddrEntry.MatchedEntryFound)
        {
            /* check matched port number */
            for (PortIndex = 0U; PortIndex < NETC_ETHSWT_IP_BITMAPLEN; PortIndex++)
            {
                if (1U == (PortMacAddrEntry.PortBitMap & (0x1U)))
                {
                    NumOfMatchedPorts += 1U;
                    *PortIdx = PortIndex;
                }
                PortMacAddrEntry.PortBitMap >>= 1U;
            }

            /* no matched ports found */
            if (0U == NumOfMatchedPorts)
            {
                *PortIdx = NETC_ETHSWT_IP_NOMATCHEDPORTMACADDR;
            }

            /* multiple matched ports found */
            if (NumOfMatchedPorts > 1U)
            {
                status = E_NOT_OK;
                *PortIdx = NETC_ETHSWT_IP_NOMATCHEDPORTMACADDR;
            }
        }
        else
        {
            /* no entry found */
            *PortIdx = NETC_ETHSWT_IP_NOMATCHEDPORTMACADDR;
        }
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryFdbTableEntry
 * Description   : Ethernet Switch query FDB table entry function.
 * implements Netc_EthSwt_Ip_QueryFdbTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryFdbTableEntry( uint8 SwitchIdx,
                                                                 uint32 *MatchedEntries,
                                                                 Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                                               )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 KeyeData[3U];
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FdbTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);

    KeyeData[0U] = ((uint32)(FdbTableEntry->MacAddr[0U]) | ((uint32)(FdbTableEntry->MacAddr[1U]) << 8U) | ((uint32)(FdbTableEntry->MacAddr[2U]) << 16U) | ((uint32)(FdbTableEntry->MacAddr[3U]) << 24U));
    KeyeData[1U] = ((uint32)(FdbTableEntry->MacAddr[4U]) | ((uint32)(FdbTableEntry->MacAddr[5U]) << 8U));
    KeyeData[2U] = FdbTableEntry->FID;

    /* no need CFGE_DATA and only use "NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH" as the access method */
    status = Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;       /* for query command, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN);           /* set request data buffer length */
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_FDBTABLE_RESBUFFER_LEN);           /* set response data buffer with normal length */

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

            /* found a matched entry */
            Netc_EthSwt_Ip_QueryFdbTableEntry_FoundAMatchedEntry(*MatchedEntries, FdbTableEntry);
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }


    return status;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteFdbTableEntry
 * Description   : Ethernet Switch delete FDB table entry function.
 * implements Netc_EthSwt_Ip_DeleteFdbTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteFdbTableEntry( uint8 SwitchIdx,
                                                                  uint32 *MatchedEntries,
                                                                  const Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 KeyeData[3U];
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FdbTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* Delete command will ignore ActionsData data field */
    KeyeData[0U] = ((uint32)(FdbTableEntry->MacAddr[0U]) | ((uint32)(FdbTableEntry->MacAddr[1U]) << 8U) | ((uint32)(FdbTableEntry->MacAddr[2U]) << 16U) | ((uint32)(FdbTableEntry->MacAddr[3U]) << 24U));
    KeyeData[1U] = ((uint32)(FdbTableEntry->MacAddr[4U]) | ((uint32)(FdbTableEntry->MacAddr[5U]) << 8U));
    KeyeData[2U] = FdbTableEntry->FID;

    /* no need CFGE_DATA and only use "NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH" as the access method */
    status = Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;       /* for delete command, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN);           /* set request data buffer length */
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

        /* send the "Delete" command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }


    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateFdbTableEntry
 * Description   : Ethernet Switch Add or Update FDB table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateFdbTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateFdbTableEntry( uint8 SwitchIdx,
                                                                       Netc_EthSwt_Ip_CommandsType Cmd,
                                                                       uint32 *MatchedEntries,
                                                                       const Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                                                     )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 KeyeData[3U];
    uint32 ActionsData;
    Netc_EthSwt_Ip_FDBTableCFGEDataType CfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(FdbTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set ACTEU and CFGEU flag */
        ActionsData = (NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U));

        KeyeData[0U] = ((uint32)(FdbTableEntry->MacAddr[0U]) | ((uint32)(FdbTableEntry->MacAddr[1U]) << 8U) | ((uint32)(FdbTableEntry->MacAddr[2U]) << 16U) | ((uint32)(FdbTableEntry->MacAddr[3U]) << 24U));
        KeyeData[1U] = ((uint32)(FdbTableEntry->MacAddr[4U]) | ((uint32)(FdbTableEntry->MacAddr[5U]) << 8U));
        KeyeData[2U] = FdbTableEntry->FID;

        CfgeData.Cfge_PortBitmap = NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP(FdbTableEntry->SwitchPortEgressBitMask);
        CfgeData.Cfge_ConfigField = (NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE(FdbTableEntry->TimeStampCapture ? 1U : 0U) \
                                | NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(FdbTableEntry->DynamicEntry ? 1U : 0U) \
                                | NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD(FdbTableEntry->CutThroughDisable) \
                                | NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE(FdbTableEntry->IngressMirroringEnable ? 1U : 0U) \
                                | NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT(FdbTableEntry->EgressPort) \
                                | NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID(FdbTableEntry->OverridETEID));

        CfgeData.Cfge_EtEid = FdbTableEntry->ET_EID;

        /* only supports "NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH" access method */
        status = Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(ActionsData, &KeyeData[0U], &CfgeData, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
        if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
        {
            /* fill in operation data for config field of Request Header*/
            Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
            Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
            Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
            Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;       /* for Add, Update, or AddorUpdate command, the Access Method should only be NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH */
            Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
            Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_REQBUFFER_LEN);
            Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

            /* send command */
            status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
            #if defined(ERR_IPV_NETC_051243)
                #if (STD_ON == ERR_IPV_NETC_051243)
            /* Error code 0x8A is not a real error. check it on Errata. */
            if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            {
                #endif
            #else
            if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            {
            #endif
                status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
                Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            }
        }
        else
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
        }
    }

    return status;
}

/* inline function for verifying conditions in function Netc_EthSwt_Ip_FillInFdbTableListData() */
static inline void Netc_EthSwt_Ip_VerifyFillInFdbTableListDataFuncCond(const uint32 *ResumeId, Netc_EthSwt_Ip_FdbEntryQuerying* const FdbEntryQuerying)
{
    if ((NETC_ETHSWT_IP_BD_NULL_ENTRY_ID == *ResumeId) && (NULL_PTR != FdbEntryQuerying))
    {
        switch (*FdbEntryQuerying)
        {
            case NETC_ETHSWT_IP_FDB_STATIC_ENTRY_QUERY_SEARCH:
            {
                *FdbEntryQuerying = NETC_ETHSWT_IP_FDB_DYNAMIC_ENTRY_QUERY_SEARCH;
                break;
            }
            case NETC_ETHSWT_IP_FDB_DYNAMIC_ENTRY_QUERY_SEARCH:
            {
                *FdbEntryQuerying = NETC_ETHSWT_IP_FDB_DONE_ENTRY_QUERY_SEARCH;
                break;
            }
            default:
            {
                *FdbEntryQuerying = NETC_ETHSWT_IP_FDB_DONE_ENTRY_QUERY_SEARCH;
                break;
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SearchAndFillInFdbTableList
 * Description   : inline function for searching and filling in FdbTableList data in function Netc_EthSwt_Ip_GetFdbTable().
 *
 *END**************************************************************************/
static inline Std_ReturnType Netc_EthSwt_Ip_SearchAndFillInFdbTableList(uint32 *ResumeId, uint16 *NumOfExistingEntry, Netc_EthSwt_Ip_FdbEntryDataType *FdbTableList,
                                                         Netc_EthSwt_Ip_FdbEntryQuerying* const FdbEntryQuerying)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 NumOfElement = 0U;
    uint32 MacAddrL;
    uint32 MacAddrH;
    uint32 CfgeData;
    uint8 MacAddrByteIdx;
    uint32 ActionsData;

    /* set the query options with full query */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_46();
    /* fill in FdbTabeDataBuffer for request */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;
    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_RESUMEENTRYID] = *ResumeId;    /* resume entry id */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_L] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_H] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_FID] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_PORTBITMAP] = 0U;
    /* search static entries first then dynamic entries. set CFGE_DATA[DYNAMIC] to 0x0 meaning it will match static entries, set CFGE_DATA[DYNAMIC] to 0x1 meaning it will match dynamic entries */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGECONFIG] = (NETC_ETHSWT_IP_FDB_STATIC_ENTRY_QUERY_SEARCH == *FdbEntryQuerying) ? NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(0U) : NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(1U);

    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ETEID] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC(1U);    /* 0x1: Match CFGE_DATA[DYNAMIC] field */

    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_46();
    /* do the full query with Search Method */
    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;           /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_FDBTABLE_RESBUFFER_LEN);             /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(0U, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* check the status of query command */
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
        /* ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED */
        /* found a matched entry */
        if ((1U == NumOfElement) && (*ResumeId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
            /* fill in "Netc_EthSwt_Ip_FdbEntryDataType" structure with data in response data buffer */
            MacAddrL = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_L];
            MacAddrH = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_H];
            for (MacAddrByteIdx = 0U; MacAddrByteIdx < 4U; MacAddrByteIdx++ )
            {
                FdbTableList[(*NumOfExistingEntry)].MacAddr[MacAddrByteIdx] = (uint8)(MacAddrL & NETC_ETHSWT_IP_0XFF_MASK);
                MacAddrL >>= 8U;
            }
            FdbTableList[(*NumOfExistingEntry)].MacAddr[4U] = (uint8)(MacAddrH & NETC_ETHSWT_IP_0XFF_MASK);
            FdbTableList[(*NumOfExistingEntry)].MacAddr[5U] = (uint8)((MacAddrH >> 8U) & NETC_ETHSWT_IP_0XFF_MASK);

            FdbTableList[(*NumOfExistingEntry)].FID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_FID] & NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_MASK);
            FdbTableList[(*NumOfExistingEntry)].SwitchPortEgressBitMask = (TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_PORTBITMAP] & NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_MASK);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_CFGECONFIG];
            FdbTableList[(*NumOfExistingEntry)].TimeStampCapture = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_SHIFT) != 0x0UL) ? TRUE : FALSE;
            FdbTableList[(*NumOfExistingEntry)].DynamicEntry = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_SHIFT) != 0x0UL) ? TRUE : FALSE;
            FdbTableList[(*NumOfExistingEntry)].CutThroughDisable = (uint8)((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_SHIFT);
            FdbTableList[(*NumOfExistingEntry)].IngressMirroringEnable = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_SHIFT) != 0x0UL) ? TRUE : FALSE;
            FdbTableList[(*NumOfExistingEntry)].EgressPort = (uint8)((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_SHIFT);
            FdbTableList[(*NumOfExistingEntry)].OverridETEID = (uint8)(CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_MASK);

            FdbTableList[(*NumOfExistingEntry)].ET_EID = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_ETEID];

            /* increase the NumOfExistingEntry */
            (*NumOfExistingEntry) += 1U;
        }

        Netc_EthSwt_Ip_VerifyFillInFdbTableListDataFuncCond(ResumeId, FdbEntryQuerying);
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetFdbTable
 * Description   : Ethernet Switch get FDB table function.
 * implements Netc_EthSwt_Ip_GetFdbTable_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetFdbTable( uint8 SwitchIdx,
                                           uint16 * NumberOfElements,
                                           Netc_EthSwt_Ip_FdbEntryDataType * FdbTableList
                                         )
{
    Std_ReturnType status = E_OK;
    uint16 NumOfExistingEntry = 0U;
    uint16 NumOfInUseEntry;
    uint32 ResumeId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;

    Netc_EthSwt_Ip_FdbEntryQuerying FdbEntryQuerying = NETC_ETHSWT_IP_FDB_STATIC_ENTRY_QUERY_SEARCH;

    /* [notes]: we will have to read entries one by one because of the errata ERR051048.
     - ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED
     - Description: The NUM_MATCHED field in the command NTMP response header may be incorrect when
       the search access method is used for the following tables: FDB table 15, L2 IPv4 Multicast
       Filter table 16, VLAN Filter table 18, Ingress Stream Identification table 30, or Ingress Stream
       Filter table 32.
     - Workaround: For the query command, limit the message response buffer size (RESPONSE_LENGTH field in the request header)
       so that NETC returns no more than one entry at a time. Under this condition, the NUM_MATCHED field value is correct
    */

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(NumberOfElements != NULL_PTR);
    if (*NumberOfElements > 0U)
    {
        DevAssert(FdbTableList != NULL_PTR);
    }
#endif

    (void)SwitchIdx;
    /*
    * Number of static FDB entries in-use (hash-based and CAM-based entries) is indicated in FDBHTOR0[STATIC_ENTRIES].
    * Number of dynamic FDB entries in-use (hash-based and CAMbased entries) is indicated in FDBHTOR1[DYN_ENTRIES].
    */
    NumOfInUseEntry = (uint16)(IP_NETC__SW0_BASE->FDBHTOR0 & NETC_ETHSWT_IP_0XFFFF_MASK) + (uint16)(IP_NETC__SW0_BASE->FDBHTOR1 & NETC_ETHSWT_IP_0XFFFF_MASK);    /* get how many entries exist in module */

    /* if *NumberOfElements == 0U or NumOfInUseEntry == 0U, return the NumOfInUseEntry directly and will not do the query and fill in the structure */
    if ((*NumberOfElements == 0U) || (NumOfInUseEntry == 0U))
    {
        NumOfExistingEntry = NumOfInUseEntry;
    }
    else    /* if *NumberOfElements > 0, do the query and fill in the structure */
    {
        do
        {
            /* check if the FdbTableList is full or we get all existing entries */
            if ((NumOfExistingEntry >= *NumberOfElements) || (NumOfExistingEntry >= NumOfInUseEntry) || (status == (uint8)(E_NOT_OK)))
            {
                break;
            }

            status = Netc_EthSwt_Ip_SearchAndFillInFdbTableList(&ResumeId, &NumOfExistingEntry, FdbTableList, &FdbEntryQuerying);

        } while ((TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS] != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID) || (NETC_ETHSWT_IP_FDB_DONE_ENTRY_QUERY_SEARCH != FdbEntryQuerying));      /* Status == MAX_32BIT means the query operation is completed */
    }

    /* return the Number of elements which are currently available in the EthSwitch module or number of elements copied to FdbTableList*/
    *NumberOfElements = NumOfExistingEntry;

    return status;
}

/* inline function for filling in TableDataBuff in Netc_EthSwt_Ip_SearchFdbTable() function. */
static inline void Netc_EthSwt_Ip_FillInTableDataBuffForSearchingFDBTable(const uint32 * ActionsData, const uint32 * ResumeEntryId, const Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType * SearchCriteriaData)
{
    uint8 MatchCriteriaData;

    /* +++ fill in FdbTabeDataBuffer for request +++ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = *ActionsData;

    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_RESUMEENTRYID] = *ResumeEntryId;    /* ResumeEntryId should start from MAX_32BIT */
    /* no need to fill in ETEID data for searching purpose */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ETEID] = 0U;

    /* remap and fill in Match Criteria flag */
    if (SearchCriteriaData->SearchMatchCriteria >= NETC_ETHSWT_IP_FDBTABLE_MATCH_KEYE_FID_FIELD)
    {
        MatchCriteriaData = ((uint8)(SearchCriteriaData->SearchMatchCriteria) - NETC_ETHSWT_IP_FDBTABLE_KEYE_MATCH_CRITERIA_ADJUSTING_FACTOR);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_KEYEMC(MatchCriteriaData);

        /* fill in Key Element Match Criteria data */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_L] = NETC_ETHSWT_IP_MULTICASTBIT_OF_MAC_ADDRESS(SearchCriteriaData->SearchKeyeData.SearchMulticastMacAddr ? 1U : 0U);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_FID] = SearchCriteriaData->SearchKeyeData.SearchFid;
    }
    else if (SearchCriteriaData->SearchMatchCriteria >= NETC_ETHSWT_IP_FDBTABLE_MATCH_CFGE_DYNAMIC_FIELD)
    {
        MatchCriteriaData = ((uint8)(SearchCriteriaData->SearchMatchCriteria) - NETC_ETHSWT_IP_FDBTABLE_CFGE_MATCH_CRITERIA_ADJUSTING_FACTOR);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC(MatchCriteriaData);

        /* fill in CFGE Match Criteria data*/
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_PORTBITMAP] = SearchCriteriaData->SearchCfgeData.SearchPortBitMap;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGECONFIG] = NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(SearchCriteriaData->SearchCfgeData.SearchDynamicEntry ? 1U : 0U);
    }
    else if (SearchCriteriaData->SearchMatchCriteria == NETC_ETHSWT_IP_FDBTABLE_MATCH_ACTE_DATA_FIELD)
    {
        MatchCriteriaData = (uint8)(SearchCriteriaData->SearchMatchCriteria);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTEMC(MatchCriteriaData);
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_08();
        /* fill in ACTE Match Criteria data*/
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] |= (NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT(SearchCriteriaData->SearchActeData.ActivityCounter) \
                                                                                                | NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG(SearchCriteriaData->SearchActeData.ActivityFlag ? 1U : 0U));
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_08();
    }
    else
    {
        /* MATCH_ANY_CRITERIA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = 0x0UL;
    }

    /* --- fill in FdbTabeDataBuffer for request --- */
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SearchFdbTable
 * Description   : Ethernet Switch search FDB table one by one.
 * implements Netc_EthSwt_Ip_SearchFdbTable_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SearchFdbTable( uint8 SwitchIdx,
                                              uint32 * ResumeEntryId,
                                              const Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType * SearchCriteriaData,
                                              Netc_EthSwt_Ip_FdbEntryDataType * FdbTableEntry
                                            )
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint8 MacBeyteIdx;
    uint32 MacAddrL;
    uint32 MacAddrH;
    uint32 CfgeData;
    uint32 NumOfElement = 0U;
    uint32 TableEntryId;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SearchCriteriaData != NULL_PTR);
    DevAssert(SearchCriteriaData->SearchMatchCriteria <= (NETC_ETHSWT_IP_FDBTABLE_MATCH_KEYE_FID_AND_MULTICAST_BIT_OF_MACADDR));
    DevAssert(FdbTableEntry != NULL_PTR);
#endif

    /* +++ fill in FdbTabeDataBuffer for request +++ */
    /* set the query options with full query */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(0U);
    Netc_EthSwt_Ip_FillInTableDataBuffForSearchingFDBTable(&ActionsData, ResumeEntryId, SearchCriteriaData);
    /* --- fill in FdbTabeDataBuffer for request --- */

    /* do the full query with Search Method */
    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_FDBTABLE_RESBUFFER_LEN);           /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        /* check if found a matched entry */
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* found a matched entry */
        TableEntryId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
        if ((1U == NumOfElement) && (TableEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
            /* fill in "Netc_EthSwt_Ip_FdbEntryDataType" structure with data in response data buffer */
            MacAddrL = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_L];
            MacAddrH = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_MACADDRESS_H];
            for (MacBeyteIdx = 0U; MacBeyteIdx < 4U; MacBeyteIdx++ )
            {
                FdbTableEntry->MacAddr[MacBeyteIdx] = (uint8)(MacAddrL & NETC_ETHSWT_IP_0XFF_MASK);
                MacAddrL >>= 8U;
            }
            FdbTableEntry->MacAddr[4U] = (uint8)(MacAddrH & NETC_ETHSWT_IP_0XFF_MASK);
            FdbTableEntry->MacAddr[5U] = (uint8)((MacAddrH >> 8U) & NETC_ETHSWT_IP_0XFF_MASK);

            FdbTableEntry->FID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_FID] & NETC_ETHSWT_IP_FDBTABLE_KEYE_DATA_FID_MASK);
            FdbTableEntry->SwitchPortEgressBitMask = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_PORTBITMAP] & NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_MASK;

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_CFGECONFIG];
            FdbTableEntry->TimeStampCapture = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_TIMECAPE_SHIFT) == 0x0UL) ? FALSE : TRUE;
            FdbTableEntry->DynamicEntry = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC_SHIFT) == 0x0UL) ? FALSE : TRUE;
            FdbTableEntry->CutThroughDisable = (uint8)((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_CTD_SHIFT);
            FdbTableEntry->IngressMirroringEnable = (((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_IMIRE_SHIFT) == 0x0UL) ? FALSE : TRUE;
            FdbTableEntry->EgressPort = (uint8)((CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_MASK) >> NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_EPORT_SHIFT);
            FdbTableEntry->OverridETEID = (uint8)(CfgeData & NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_OETEID_MASK);

            FdbTableEntry->ET_EID = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_ETEID];
        }

        /* get the resume_entry_id and be ready for the next query operation */
        /* [notes]: if the searching is completed, or there is no matched entry found, then TableDataBuffer.TableDataField[0U] will be writen with MAX_32BIT by hardware */
        *ResumeEntryId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/* inline function for searching and filling in VlanFilterTableList in function Netc_EthSwt_Ip_GetVlanFilterTable() */
static inline Std_ReturnType Netc_EthSwt_Ip_SearchAndFIllInVlanFilterTableList(uint32 *ResumeId, uint16 *NumOfExistingEntry, Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableList)
{
    Std_ReturnType status = E_OK;
    uint32 ActionsData;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 NumOfElement = 0U;
    uint32 CfgeData;

    /* set the query options with full query */
    ActionsData = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U));
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_48();

    /* fill in TabeDataBuffer for request */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;
    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_RESUMEENTRYID_FIELD] = *ResumeId;    /* resume entry id */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_48();

    /* do the full query with Search Method */
    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_VLANFILTERTABLE_RESBUFFER_LEN);           /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(0U, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* check the status of query command */
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeId = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_RSPDATA_STATUS];

        /* ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED */
        /* found a matched entry */
        if ((1U == NumOfElement) && (*ResumeId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
            /* fill in "Netc_EthSwt_Ip_VlanFilterEntryDataType" structure with data in response data buffer */
            VlanFilterTableList[(*NumOfExistingEntry)].VlanID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_VID] & NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_MASK);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0];
            VlanFilterTableList[(*NumOfExistingEntry)].SpanningTreeGroupMemberId = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
            VlanFilterTableList[(*NumOfExistingEntry)].PortMembershipBitmap = (CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1];
            VlanFilterTableList[(*NumOfExistingEntry)].FID = (uint16)(CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_MASK);
            VlanFilterTableList[(*NumOfExistingEntry)].MacLearningOptions = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
            VlanFilterTableList[(*NumOfExistingEntry)].MacForwardingOptions = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
            VlanFilterTableList[(*NumOfExistingEntry)].IpMulticastFilteringEnable = (((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) == 0x0UL) ? FALSE : TRUE;
            VlanFilterTableList[(*NumOfExistingEntry)].IpMulticastFloodingEnable = (((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) == 0x0UL) ? FALSE : TRUE;

            VlanFilterTableList[(*NumOfExistingEntry)].EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
            VlanFilterTableList[(*NumOfExistingEntry)].BaseEgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3];

            /* increase the NumOfExistingEntry */
            (*NumOfExistingEntry) += 1U;
        }
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetVlanFilterTable
 * Description   : Ethernet Switch get Vlan Filter table function.
 * implements Netc_EthSwt_Ip_GetVlanFilterTable_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetVlanFilterTable( uint8 SwitchIdx,
                                                  uint16 * NumberOfElements,
                                                  Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableList
                                                )
{
    Std_ReturnType status = E_OK;
    uint16 NumOfExistingEntry = 0U;
    uint16 NumOfInUseEntry;
    uint32 ResumeId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;

    /* [notes]: we will have to read entries one by one because of the errata ERR051048.
     - ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED
     - Description: The NUM_MATCHED field in the command NTMP response header may be incorrect when
       the search access method is used for the following tables: FDB table 15, L2 IPv4 Multicast
       Filter table 16, VLAN Filter table 18, Ingress Stream Identification table 30, or Ingress Stream
       Filter table 32.
     - Workaround: For the query command, limit the message response buffer size (RESPONSE_LENGTH field in the request header)
       so that NETC returns no more than one entry at a time. Under this condition, the NUM_MATCHED field value is correct
    */

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(NumberOfElements != NULL_PTR);
    if (*NumberOfElements > 0U)
    {
        DevAssert(VlanFilterTableList != NULL_PTR);
    }
#endif

    (void)SwitchIdx;
    /* Number of entries in-use by the VLAN Filter table is indicated in VFHTOR[NUM_ENTRIES]. */
    NumOfInUseEntry = (uint16)(IP_NETC__SW0_BASE->VFHTOR & NETC_ETHSWT_IP_0XFFFF_MASK);    /* get how many entries exist in module */

    /* if *NumberOfElements == 0U or NumOfInUseEntry == 0U, return the NumOfInUseEntry directly and will not do the query and fill in the structure */
    if ((*NumberOfElements == 0U) || (NumOfInUseEntry == 0U))
    {
        NumOfExistingEntry = NumOfInUseEntry;
    }
    else    /* if *NumberOfElements > 0, do the query and fill in the structure */
    {
        do {
            /* check if the VlanFilterTableList is full or we get all existing entries */
            if ((NumOfExistingEntry >= *NumberOfElements) || (NumOfExistingEntry >= NumOfInUseEntry) || (status == (uint8)(E_NOT_OK)))
            {
                break;
            }

            status = Netc_EthSwt_Ip_SearchAndFIllInVlanFilterTableList(&ResumeId, &NumOfExistingEntry, VlanFilterTableList);
        } while (TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_RSPDATA_STATUS] != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID);      /* Status == MAX_32BIT means the query operation is completed */
    }

    /* return the Number of elements which are currently available in the EthSwitch module or number of elements copied to VlanFilterTableList*/
    *NumberOfElements = NumOfExistingEntry;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry
 * Description   : Ethernet Switch add, update or addorupdate Vlan Filter table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry( uint8 SwitchIdx,
                                                                              Netc_EthSwt_Ip_CommandsType Cmd,
                                                                              uint32 *MatchedEntries,
                                                                              const Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableEntry
                                                                            )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 AccessKeyData;
    uint32 ActionsData;
    Netc_EthSwt_Ip_VlanFilterTableCFGEDataType VlanFilterCfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(VlanFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* fill in Vlan Filter Table Request Data Buffer */
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);

        AccessKeyData = VlanFilterTableEntry->VlanID;

        VlanFilterCfgeData.Cfge_Data[0U] = (NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID(VlanFilterTableEntry->SpanningTreeGroupMemberId) \
                                        | NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP(VlanFilterTableEntry->PortMembershipBitmap));
        VlanFilterCfgeData.Cfge_Data[1U] = (NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE(VlanFilterTableEntry->IpMulticastFloodingEnable ? 1U :0U) \
                                        | NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE(VlanFilterTableEntry->IpMulticastFilteringEnable ? 1U : 0U) \
                                        | NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO(VlanFilterTableEntry->MacForwardingOptions) \
                                        | NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO(VlanFilterTableEntry->MacLearningOptions) \
                                        | NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID(VlanFilterTableEntry->FID));
        VlanFilterCfgeData.Cfge_Data[2U] = NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP(VlanFilterTableEntry->EgressTreatmentApplicabilityPortBitmap);
        VlanFilterCfgeData.Cfge_Data[3U] = NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID(VlanFilterTableEntry->BaseEgressTreatmentEntryID);

        /* For Add, Update and AddOrUpdate commands, we only provide NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method for users */
        status = Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(ActionsData, AccessKeyData, &VlanFilterCfgeData, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
        if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
        {
            /* fill in operation data for config field of Request Header*/
            Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
            Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
            Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
            Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;        /* for Add command, the Access Method should only be NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH */
            Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
            Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_VLANFILTERTABLE_REQBUFFER_LEN);
            Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

            /* send the command */
            status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
            #if defined(ERR_IPV_NETC_051243)
                #if (STD_ON == ERR_IPV_NETC_051243)
            /* Error code 0x8A is not a real error. check it on Errata. */
            if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            {
                #endif
            #else
            if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            {
            #endif
                status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
                Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            }
        }
        else
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryVlanFilterTableEntry
 * Description   : Ethernet Switch query Vlan Filter table entry function.
 * implements Netc_EthSwt_Ip_QueryVlanFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryVlanFilterTableEntry( uint8 SwitchIdx,
                                                                        uint32 *MatchedEntries,
                                                                        Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableEntry
                                                                      )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 AccessKeyData;
    uint32 ActionsData;
    uint32 CfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* fill in Vlan Filter Table Request Data Buffer */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);        /* for "query" command we only provide "full query" for users */

    AccessKeyData = VlanFilterTableEntry->VlanID;

    /* for query command, we don't need the CFGE_DATA field */
    status = Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(ActionsData, AccessKeyData, NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of NTMP Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);            /* set request data buffer length */
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_VLANFILTERTABLE_RESBUFFER_LEN);            /* set response data buffer length */

        /* send the "Query" command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

            /* found a matched entry */
            if (1U == *MatchedEntries)
            {
                /* fill in "Netc_EthSwt_Ip_VlanFilterEntryDataType" structure with data in response data buffer */
                VlanFilterTableEntry->VlanID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_VID] & NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_MASK);

                CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0];
                VlanFilterTableEntry->SpanningTreeGroupMemberId = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
                VlanFilterTableEntry->PortMembershipBitmap = (CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK);

                CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1];
                VlanFilterTableEntry->FID = (uint16)(CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_MASK);
                VlanFilterTableEntry->MacLearningOptions = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
                VlanFilterTableEntry->MacForwardingOptions = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
                VlanFilterTableEntry->IpMulticastFilteringEnable = (((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) != 0x0UL) ? TRUE : FALSE;
                VlanFilterTableEntry->IpMulticastFloodingEnable = (((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) != 0x0UL) ? TRUE : FALSE;

                VlanFilterTableEntry->EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
                VlanFilterTableEntry->BaseEgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3];
            }
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteVlanFilterTableEntry
 * Description   : Ethernet Switch delete Vlan Filter table entry function.
 * implements Netc_EthSwt_Ip_DeleteVlanFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteVlanFilterTableEntry( uint8 SwitchIdx,
                                                                         uint32 *MatchedEntries,
                                                                         uint32 VlanFilterTableEntryId
                                                                       )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 AccessKeyData;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* fill in Vlan Filter Table Request Data Buffer */
    AccessKeyData = VlanFilterTableEntryId;

    /* for delete command, we don't need the CFGE_DATA field */
    status = Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(ActionsData, AccessKeyData, NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of NTMP Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;        /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

        /* send the "Delete" command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryEgressCountTableEntry
 * Description   : Ethernet Switch query Egress count table entry function.
 * implements Netc_EthSwt_Ip_QueryEgressCountTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryEgressCountTableEntry( uint8 SwitchIdx,
                                                                        uint32 EntryId,
                                                                        uint32 *MatchedEntries,
                                                                        Netc_EthSwt_Ip_ECTableStatisticsDataType *StatisticsData
                                                                       )
{
    Netc_EthSwt_Ip_CBDRStatusType status;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(StatisticsData != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert((EntryId > 0U) && (EntryId <= (IP_NETC__SW0_COMMON->ECTCAPR & NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK)));
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_44();

    /* fill in Egress Count Table Request Data Buffer */
    /* fill in Actions field. only support "full query" action and no need to update Statistics Element */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                                                                                    | NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(NETC_ETHSWT_EGRESSCOUNTTABLE_NO_UPDATE_STATISTICS_ELEMENT));
    /* fill in Access Key field, only support Entry ID Match method */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_44();

    /* fill in operation data for config field of NTMP Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;           /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_COUNT_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                        /* only support Entry ID Match method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);  /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_EGRESSCOUNTTABLE_RSPBUFFER_LEN);  /* set response data buffer length */

    /* send the "Query" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        /* found a matched entry */
        if (*MatchedEntries == 1U)
        {
            /* get the Enqueued Frame Count data */
            StatisticsData->EnqueuedFrmCnt = ((uint64)(TableDataBuffer.TableDataField[NETC_ETHSWT_ECTABLE_RSPDATA_ENQFRMCNT_H]) << NETC_ETHSWT_IP_32BIT_SHIFT);
            StatisticsData->EnqueuedFrmCnt |= (uint64)(TableDataBuffer.TableDataField[NETC_ETHSWT_ECTABLE_RSPDATA_ENQFRMCNT_L]);

            /* get the Rejected Frame Count */
            StatisticsData->RejectedFrmCnt = ((uint64)(TableDataBuffer.TableDataField[NETC_ETHSWT_ECTABLE_RSPDATA_REJFRMCNT_H]) << NETC_ETHSWT_IP_32BIT_SHIFT);
            StatisticsData->RejectedFrmCnt |= (uint64)(TableDataBuffer.TableDataField[NETC_ETHSWT_ECTABLE_RSPDATA_REJFRMCNT_L]);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ResetEgressCountTableEntry
 * Description   : Ethernet Switch reset Egress count table entry function.
 * implements Netc_EthSwt_Ip_ResetEgressCountTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_ResetEgressCountTableEntry( uint8 SwitchIdx,
                                                                         uint32 EntryId,
                                                                         uint32 *MatchedEntries
                                                                       )
{
    Netc_EthSwt_Ip_CBDRStatusType status;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert((EntryId > 0U) && (EntryId <= (IP_NETC__SW0_COMMON->ECTCAPR & NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK)));
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_49();
    /* fill in Egress Count Table Request Data Buffer */
    /* fill in Actions field. only support "full query" action and set STSEU to reset Statistics Element */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD] = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                                                                                         | NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(NETC_ETHSWT_EGRESSCOUNTTABLE_RESET_STATISTICS_ELEMENT));
    /* fill in Access Key field, only support Entry ID Match method */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD] = EntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_49();

    /* fill in operation data for config field of NTMP Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;           /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_COUNT_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                        /* only support Entry ID Match method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_UPDATE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);  /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

    /* send the "Update" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateEgressTreatmentTableEntry
 * Description   : Ethernet Switch add, update or addorupdate Egress Treatment table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateEgressTreatmentTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateEgressTreatmentTableEntry( uint8 SwitchIdx,
                                                                                   Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                   uint32 *MatchedEntries,
                                                                                   const Netc_EthSwt_Ip_EgressTreatmentEntryDataType * EgressTreatmentTableEntry
                                                                                 )
{
    Netc_EthSwt_Ip_CBDRStatusType status;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(EgressTreatmentTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
         SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_50();
        /* fill in Egress Treatment Table Request Data Buffer */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EgressTreatmentTableEntry->EgressTreatmentEntryID;

        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = (NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN(EgressTreatmentTableEntry->EgressFrmModificationDataLength) \
                                                                                    | NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE(EgressTreatmentTableEntry->EgressFrmModificationLengthChange) \
                                                                                    | NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION(EgressTreatmentTableEntry->EgressCounterAction) \
                                                                                    | NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION(EgressTreatmentTableEntry->EgressSequenceAction) \
                                                                                    | NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE(EgressTreatmentTableEntry->EgressFrmModificationMode));
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = EgressTreatmentTableEntry->EgressFrmModificationEID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = EgressTreatmentTableEntry->EgressCountTableEID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = EgressTreatmentTableEntry->EgressSeqActionsTargetEID;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_50();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ETMTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send the command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryEgressTreatmentTableEntry
 * Description   : Ethernet Switch query Egress Treatment table entry function.
 * implements Netc_EthSwt_Ip_QueryEgressTreatmentTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryEgressTreatmentTableEntry( uint8 SwitchIdx,
                                                                             uint32 *MatchedEntries,
                                                                             Netc_EthSwt_Ip_EgressTreatmentEntryDataType * EgressTreatmentTableEntry
                                                                           )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 CfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_51();
    /* fill in Egress Treatment Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);     /* only supports Full Query */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EgressTreatmentTableEntry->EgressTreatmentEntryID;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_51();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_EGRESSTREAMENTTABLE_RESBUFFER_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_EthSwt_Ip_EgressTreatmentEntryDataType" structure with data in response data buffer */
            EgressTreatmentTableEntry->EgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_ENTRYID_FIELD];

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA0];
            EgressTreatmentTableEntry->EgressFrmModificationDataLength = (uint16)((CfgeData & NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN_MASK) >> NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_DATA_LEN_SHIFT);
            EgressTreatmentTableEntry->EgressFrmModificationLengthChange = (uint8)((CfgeData & NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE_MASK) >> NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_LEN_CHANGE_SHIFT);
            EgressTreatmentTableEntry->EgressCounterAction = ((CfgeData & NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION_MASK) >> NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_COUNTER_ACTION_SHIFT);
            EgressTreatmentTableEntry->EgressSequenceAction = ((CfgeData & NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION_MASK) >> NETC_ETHSWT_IP_ETTABLE_CFGE_EGRESS_SEQUENCE_ACTION_SHIFT);
            EgressTreatmentTableEntry->EgressFrmModificationMode = (CfgeData & NETC_ETHSWT_IP_ETTABLE_CFGE_FRM_MODIFICATION_MODE_MASK);

            EgressTreatmentTableEntry->EgressFrmModificationEID = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA1];         /* fill in EFM_EID field */
            EgressTreatmentTableEntry->EgressCountTableEID = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA2];              /* fill in EC_EID field */
            EgressTreatmentTableEntry->EgressSeqActionsTargetEID = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSTREATMENTTABLE_RSPFMT_CFGEDATA3];        /* fill in ESQA_TGT_EID field */
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteEgressTreatmentTableEntry
 * Description   : Ethernet Switch delete Egress Treatment table entry function.
 * implements Netc_EthSwt_Ip_DeleteEgressTreatmentTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteEgressTreatmentTableEntry( uint8 SwitchIdx,
                                                                              uint32 EgressTreatmentTableEntryId,
                                                                              uint32 *MatchedEntries
                                                                            )
{
    Netc_EthSwt_Ip_CBDRStatusType status;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_52();

    /* fill in Egress Treatment Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = 0U;     /* no need to fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EgressTreatmentTableEntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_52();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry
 * Description   : Ethernet Switch add, update or addorupdate Frame Modification table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry( uint8 SwitchIdx,
                                                                                   Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                   uint32 *MatchedEntries,
                                                                                   const Netc_EthSwt_Ip_FrmModificationEntryDataType * FrmModificationTableEntry
                                                                                 )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 MacAddrH = 0x0UL;
    uint32 MacAddrL = 0x0UL;
    uint8 MacByteIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FrmModificationTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_53();
        /* fill in Frame Modification Table Request Data Buffer */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);        /* Configuration Element Update */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = FrmModificationTableEntry->FrmModificationEntryID;                /* Entry ID */

        /* big endian */
        for(MacByteIdx = 0U; MacByteIdx < 6U; MacByteIdx++)
        {
            if(MacByteIdx < 2U)
            {
                MacAddrH |= ((uint32)(FrmModificationTableEntry->DestMacAddr[MacByteIdx]) << (MacByteIdx * 8U));
            }
            else
            {
                MacAddrL |= ((uint32)(FrmModificationTableEntry->DestMacAddr[MacByteIdx]) << ((MacByteIdx - 2U) * 8U));
            }
        }

        /* fill in CFGE Data */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = (NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H(MacAddrH) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT(FrmModificationTableEntry->SrcMacAddrRegisterPort) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION(FrmModificationTableEntry->SequenceTagAction) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION(FrmModificationTableEntry->OuterVidActions) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION(FrmModificationTableEntry->L2HeaderVlanActions) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION(FrmModificationTableEntry->L2HeaderMacActions) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION(FrmModificationTableEntry->L2Actions));
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = MacAddrL;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = (NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION(FrmModificationTableEntry->PayloadActions) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION(FrmModificationTableEntry->OuterDeiAction) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION(FrmModificationTableEntry->OuterPcpAction) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION(FrmModificationTableEntry->OuterTpidAction) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI(FrmModificationTableEntry->OuterVlanDei) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP(FrmModificationTableEntry->OuterVlanPcp) \
                                                                                    | NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID(FrmModificationTableEntry->OuterVlanVID));
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET(FrmModificationTableEntry->PayloadOffset);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES(FrmModificationTableEntry->FrmModificationDataBytes);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA5] = FrmModificationTableEntry->FrmModificationDataEntryID;        /* Frame Modification Data Tabel Entry ID */
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_53();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support "Entry ID" match method */
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FRMTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send the command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryFrmModificationTableEntry
 * Description   : Ethernet Switch query Frame Modification table entry function.
 * implements Netc_EthSwt_Ip_QueryFrmModificationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryFrmModificationTableEntry( uint8 SwitchIdx,
                                                                             uint32 *MatchedEntries,
                                                                             Netc_EthSwt_Ip_FrmModificationEntryDataType * FrmModificationTableEntry
                                                                            )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint16 MacAddrH;
    uint32 MacAddrL;
    uint8 MacByteIdx;
    uint32 CfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FrmModificationTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_54();

    /* fill in Frame Modification Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);        /* only support "Full Query" */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = FrmModificationTableEntry->FrmModificationEntryID;                /* Entry ID */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_54();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support "Entry ID" match method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_FRMTABLE_RSPBUFFER_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in structure Netc_EthSwt_Ip_FrmModificationEntryDataType with data in response data buffer */
            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA0];
            MacAddrH = (uint16)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H_SHIFT);
            MacAddrL = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA1];
            for (MacByteIdx = 0U; MacByteIdx < 4U; MacByteIdx++)
            {
                FrmModificationTableEntry->DestMacAddr[MacByteIdx] = (uint8)(MacAddrL & NETC_ETHSWT_IP_0XFF_MASK);
                MacAddrL >>= 8U;
            }
            FrmModificationTableEntry->DestMacAddr[4U] = (uint8)(MacAddrH & NETC_ETHSWT_IP_0XFF_MASK);
            FrmModificationTableEntry->DestMacAddr[5U] = (uint8)(MacAddrH >> 8U);

            FrmModificationTableEntry->SrcMacAddrRegisterPort = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SRC_MAC_ADDR_PORT_SHIFT);
            FrmModificationTableEntry->SequenceTagAction      = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_SHIFT);
            FrmModificationTableEntry->OuterVidActions        = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_SHIFT);
            FrmModificationTableEntry->L2HeaderVlanActions    = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_SHIFT);
            FrmModificationTableEntry->L2HeaderMacActions     = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_SHIFT);
            FrmModificationTableEntry->L2Actions              = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_SHIFT);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA2];
            FrmModificationTableEntry->PayloadActions  = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_SHIFT);
            FrmModificationTableEntry->OuterDeiAction  = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_SHIFT);
            FrmModificationTableEntry->OuterPcpAction  = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_SHIFT);
            FrmModificationTableEntry->OuterTpidAction = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_SHIFT);
            FrmModificationTableEntry->OuterVlanDei    = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_SHIFT);
            FrmModificationTableEntry->OuterVlanPcp    = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_SHIFT);
            FrmModificationTableEntry->OuterVlanVID    = (uint16)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_SHIFT);

            FrmModificationTableEntry->PayloadOffset              = (uint8)(TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA3] & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET_MASK);
            FrmModificationTableEntry->FrmModificationDataBytes   = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA4] & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES_MASK);
            FrmModificationTableEntry->FrmModificationDataEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA5];
        }
    }


    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteFrmModificationTableEntry
 * Description   : Ethernet Switch delete Frame Modification table entry function.
 * implements Netc_EthSwt_Ip_DeleteFrmModificationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteFrmModificationTableEntry( uint8 SwitchIdx,
                                                                              uint32 FrmModificationEntryID,
                                                                              uint32 *MatchedEntries
                                                                            )
{
    Netc_EthSwt_Ip_CBDRStatusType status;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_55();

    /* fill in Frame Modification Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = 0U;                               /* no need to fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = FrmModificationEntryID;           /* Entry ID */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_55();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support "Entry ID" match method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EnableIngressPortFiltering
 * Description   : Ethernet switch enables the ingress port filtering lookup function.
 * implements Netc_EthSwt_Ip_EnableIngressPortFiltering_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_EnableIngressPortFiltering( uint8 SwitchIdx, uint8 SwitchPortIdx, boolean Enable )
{
    Std_ReturnType Status = E_OK;
    uint32 RegVal;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void)SwitchIdx;

    /* Convert the value */
    RegVal = (Enable) ? (0x1UL) : (0x0UL);

    /* write the PIPFCR[EN] bit */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PIPFCR = RegVal;

    return Status;
}

/* inline function for filling in Access Keye data in function Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff() */
static inline Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInAccessKeyeData(const Netc_EthSwt_Ip_AccessMethodType accessMethod, const volatile uint32 *pAccessKey)
{
    uint8 ItemIdx;
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;

    switch (accessMethod)
    {
        case NETC_ETHSWT_ENTRY_ID_MATCH:
            /* fill in Entry_ID field */
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = pAccessKey[0U];
            break;
        case NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH:
            /* Not Applicable for Ingress Port Filter table*/
            status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
        case NETC_ETHSWT_SEARCH_METHOD:
            /* fill in Resume_Entry_ID field */
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = pAccessKey[0U];
            break;
        case NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH:
            /* fill in keye_data field */
            for (ItemIdx = 1U; ItemIdx <= NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN; ItemIdx++)
            {
                TableDataBuffer.TableDataField[ItemIdx] = pAccessKey[ItemIdx - 1U];
            }
            break;
        default:
            /* Not Applicable for Ingress Port Filter table*/
            status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff
 * Description   : Internal function for initializing the Ingress Port Filter Table Request Data Buffer.
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff( uint32 ActionsData,
                                                                                             const volatile uint32 *pAccessKey,
                                                                                             const Netc_EthSwt_Ip_IngressPortFilterCfgeDataType *pCfgeData,
                                                                                             Netc_EthSwt_Ip_AccessMethodType accessMethod
                                                                                           )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_56();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;  /* fill in Actions field */

    /* initialize ACCESS_KEY */
    status = Netc_EthSwt_Ip_FillInAccessKeyeData(accessMethod, pAccessKey);

    /* initialize CFGE_DATA. This portion is present only for commands which perform an update or add. */
    if (pCfgeData != NULL_PTR)
    {
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSPORTFILTER_CFGE_CONFIG_FIELD] = (NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV(pCfgeData->CfgeIpv) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV(pCfgeData->CfgeOverrideIpv ? 1U : 0U) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR(pCfgeData->CfgeDr) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR(pCfgeData->CfgeOverrideDr ? 1U : 0U) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA(pCfgeData->CfgeFilterForwardingAction) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE(pCfgeData->CfgeIngressMirroringEnable ? 1U : 0U) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE(pCfgeData->CfgeWakeOnLanTriggerEnable ? 1U : 0U) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA(pCfgeData->CfgeFilterAction) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR(pCfgeData->CfgeRelativePrecedentResolution) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD(pCfgeData->CfgeCutThroughDisable? 1U : 0U) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR(pCfgeData->CfgeHostReason) \
                                                                                            | NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP(pCfgeData->CfgeTimestampCaptureEable ? 1U : 0U));
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSPORTFILTER_CFGE_FLTATGT_FIELD] = pCfgeData->CfgeTargetForSelectedFilterAction;
    }
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_56();

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddIngressPortFilterTableEntry
 * Description   : Ethernet Switch adds Ingress Port Filter table entry function.
 * implements Netc_EthSwt_Ip_AddIngressPortFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddIngressPortFilterTableEntry( uint8 SwitchIdx,
                                                                             uint32 *MatchedEntries,
                                                                             Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                           )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint8 ByteIdx;
    uint8 CfgeDataIdx;
    uint8 PayloadIdx;
    uint16 AuxWord[2U];

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressPortFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* set STSEU and CFGEU flag */
    ActionsData = (NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU(1U) | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U));

    /* inialize KEYE_DATA */
    Netc_EthSwt_Ip_IPFKeyeData[0U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence;
    Netc_EthSwt_Ip_IPFKeyeData[2U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.keyeFrmAttributeFlags;
    Netc_EthSwt_Ip_IPFKeyeData[3U] = NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortIDMask) \
                 | NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortID) \
                 | NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask) \
                 | NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint);
    AuxWord[0U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask);
    AuxWord[1U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation);
    Netc_EthSwt_Ip_IPFKeyeData[4U] = ((uint32)AuxWord[0U] << NETC_ETHSWT_IP_16BIT_SHIFT) | (uint32)AuxWord[1U]; /* big endian for TCI */
    Netc_EthSwt_Ip_IPFKeyeData[5U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[2U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[3U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    Netc_EthSwt_Ip_IPFKeyeData[6U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[4U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[5U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | (((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT)) << NETC_ETHSWT_IP_16BIT_SHIFT);
    Netc_EthSwt_Ip_IPFKeyeData[7U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[2U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[3U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[4U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[5U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    Netc_EthSwt_Ip_IPFKeyeData[8U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[2U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[3U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    Netc_EthSwt_Ip_IPFKeyeData[9U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[4U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[5U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | (((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT)) << NETC_ETHSWT_IP_16BIT_SHIFT);
    Netc_EthSwt_Ip_IPFKeyeData[10U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[2U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[3U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[4U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[5U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    AuxWord[0U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask);
    AuxWord[1U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation);
    Netc_EthSwt_Ip_IPFKeyeData[11U] = ((uint32)AuxWord[0U] << NETC_ETHSWT_IP_16BIT_SHIFT) | (uint32)AuxWord[1U];
    AuxWord[0U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask);
    AuxWord[1U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherType);
    Netc_EthSwt_Ip_IPFKeyeData[12U] = ((uint32)AuxWord[0U] << NETC_ETHSWT_IP_16BIT_SHIFT) | (uint32)AuxWord[1U];
    Netc_EthSwt_Ip_IPFKeyeData[13U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask) << NETC_ETHSWT_IP_8BIT_SHIFT) | (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocol);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        Netc_EthSwt_Ip_IPFKeyeData[ByteIdx + 17U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddress[ByteIdx];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        Netc_EthSwt_Ip_IPFKeyeData[ByteIdx + 23U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[ByteIdx];
    }
    AuxWord[0U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask);
    AuxWord[1U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort);
    Netc_EthSwt_Ip_IPFKeyeData[27U] = ((uint32)AuxWord[0U] << NETC_ETHSWT_IP_16BIT_SHIFT) | (uint32)AuxWord[1U];
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        Netc_EthSwt_Ip_IPFKeyeData[ByteIdx + 29U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[ByteIdx];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        Netc_EthSwt_Ip_IPFKeyeData[ByteIdx + 35U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[ByteIdx];
    }
    AuxWord[0U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask);
    AuxWord[1U] = NETC_ETHSWT_IP_16BIT_BYTE_SWAP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort);
    Netc_EthSwt_Ip_IPFKeyeData[39U] = ((uint32)AuxWord[0U] << NETC_ETHSWT_IP_16BIT_SHIFT) | (uint32)AuxWord[1U];

    CfgeDataIdx = 0U;
    PayloadIdx = 0U;
    for (ByteIdx = 0U; ByteIdx < 12U; ByteIdx++)
    {
        Netc_EthSwt_Ip_IPFKeyeData[CfgeDataIdx + 41U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx]) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx + 1U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx + 1U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
        PayloadIdx++;
        CfgeDataIdx++;
    }

    /* only supports "NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH" access method */
    status = Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &Netc_EthSwt_Ip_IPFKeyeData[0U], &(IngressPortFilterTableEntry->IngressPortFilterCfgeData), NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH;       /* for Adding an ingress port filter entry, the Access Method should only be NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH */
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_ADD_FOLLOWEDBY_QUERY_CMD;                       /* can only use "Add followed by a Query" command to add an ingress port filter table entry */
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            /* It's an "Add followed by a Query", but even if this entry is added successfully, the MatchedEntry is still 0. So here we can not check the MatchedEntries parameter. */
            IngressPortFilterTableEntry->IngressPortFilterEntryID = TableDataBuffer.TableDataField[1U];     /* Get the Entry_ID from response data buffer */
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/* inline function for filling in part of keye data in function Netc_EthSwt_Ip_FillInIPFTableEntryData() */
static inline void Netc_EthSwt_Ip_FillInKeyeDataForIPF(Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry)
{
    uint8 ByteIdx;
    uint8 PayloadIdx;
    uint8 CfgeDataIdx;
    uint32 AuxWord;

    for (ByteIdx = 2U; ByteIdx < 6U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[ByteIdx] = (uint8)(TableDataBuffer.TableDataField[12U] & NETC_ETHSWT_IP_0XFF_MASK);
        TableDataBuffer.TableDataField[12U] >>= NETC_ETHSWT_IP_8BIT_SHIFT;
    }
    AuxWord = TableDataBuffer.TableDataField[13U] & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    AuxWord = (TableDataBuffer.TableDataField[13U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    AuxWord = TableDataBuffer.TableDataField[14U] & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherType = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    AuxWord = (TableDataBuffer.TableDataField[14U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocol = (uint8)(TableDataBuffer.TableDataField[15U] & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask = (uint8)((TableDataBuffer.TableDataField[15U] >> NETC_ETHSWT_IP_8BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddress[ByteIdx] = TableDataBuffer.TableDataField[ByteIdx + 19U];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[ByteIdx] = TableDataBuffer.TableDataField[ByteIdx + 25U];
    }
    AuxWord = TableDataBuffer.TableDataField[29U] & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    AuxWord = (TableDataBuffer.TableDataField[29U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[ByteIdx] = TableDataBuffer.TableDataField[ByteIdx + 31U];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[ByteIdx] = TableDataBuffer.TableDataField[ByteIdx + 37U];
    }
    AuxWord = TableDataBuffer.TableDataField[41U] & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    AuxWord = (TableDataBuffer.TableDataField[41U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);

    CfgeDataIdx = 0U;
    PayloadIdx = 0U;
    for (ByteIdx = 0U; ByteIdx < 12U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx] = (uint8)(TableDataBuffer.TableDataField[CfgeDataIdx + 43U] & NETC_ETHSWT_IP_0XFF_MASK);
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx + 1U] = (uint8)((TableDataBuffer.TableDataField[CfgeDataIdx + 43U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx] = (uint8)((TableDataBuffer.TableDataField[CfgeDataIdx + 43U] >> NETC_ETHSWT_IP_8BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx + 1U] = (uint8)((TableDataBuffer.TableDataField[CfgeDataIdx + 43U] >> NETC_ETHSWT_IP_24BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
        PayloadIdx++;
        CfgeDataIdx++;
    }
}

/* inline function for filling in IngressPortFilterTableEntry data in function Netc_EthSwt_Ip_QueryIngressPortFilterTableEntry() */
static inline void Netc_EthSwt_Ip_FillInIPFTableEntryData(Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry)
{
    uint8 ByteIdx;
    uint32 CfgeData;
    uint32 AuxWord;

    /* fill in structure Netc_EthSwt_Ip_IngressPortFilterEntryDataType with data from response data buffer */
    IngressPortFilterTableEntry->IngressPortFilterEntryID = TableDataBuffer.TableDataField[1U];         /* Entry_ID */

    /* KEYE_DATA */
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence = (uint16)(TableDataBuffer.TableDataField[2U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.keyeFrmAttributeFlags = (uint16)(TableDataBuffer.TableDataField[4U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask = (uint16)((TableDataBuffer.TableDataField[4U] & NETC_ETHSWT_IP_0XFFFF0000_MASK) >> NETC_ETHSWT_IP_16BIT_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint = (uint8)(TableDataBuffer.TableDataField[5U] & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask = (uint8)((TableDataBuffer.TableDataField[5U] & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK_MASK) \
                                                                                                    >> NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortID = (uint8)((TableDataBuffer.TableDataField[5U] & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID_MASK) \
                                                                                    >> NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortIDMask = (uint8)((TableDataBuffer.TableDataField[5U] & NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_MASK) \
                                                                                    >> NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_SHIFT);
    AuxWord = TableDataBuffer.TableDataField[6U] & NETC_ETHSWT_IP_0XFFFF_MASK;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    AuxWord = (TableDataBuffer.TableDataField[6U] & NETC_ETHSWT_IP_0XFFFF0000_MASK) >> NETC_ETHSWT_IP_16BIT_SHIFT;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = (uint16)NETC_ETHSWT_IP_16BIT_BYTE_SWAP(AuxWord);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[ByteIdx] = (uint8)(TableDataBuffer.TableDataField[7U] & NETC_ETHSWT_IP_0XFF_MASK);
        TableDataBuffer.TableDataField[7U] >>= NETC_ETHSWT_IP_8BIT_SHIFT;
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[4U] = (uint8)(TableDataBuffer.TableDataField[8U] & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[5U] = (uint8)((TableDataBuffer.TableDataField[8U] >> NETC_ETHSWT_IP_8BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[0U] = (uint8)((TableDataBuffer.TableDataField[8U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[1U] = (uint8)((TableDataBuffer.TableDataField[8U] >> NETC_ETHSWT_IP_24BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
    for (ByteIdx = 2U; ByteIdx < 6U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[ByteIdx] = (uint8)(TableDataBuffer.TableDataField[9U] & NETC_ETHSWT_IP_0XFF_MASK);
        TableDataBuffer.TableDataField[9U] >>= NETC_ETHSWT_IP_8BIT_SHIFT;
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[ByteIdx] = (uint8)(TableDataBuffer.TableDataField[10U] & NETC_ETHSWT_IP_0XFF_MASK);
        TableDataBuffer.TableDataField[10U] >>= NETC_ETHSWT_IP_8BIT_SHIFT;
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[4U] = (uint8)(TableDataBuffer.TableDataField[11U] & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[5U] = (uint8)((TableDataBuffer.TableDataField[11U] >> NETC_ETHSWT_IP_8BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[0U] = (uint8)((TableDataBuffer.TableDataField[11U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[1U] = ((uint8)(TableDataBuffer.TableDataField[11U] >> NETC_ETHSWT_IP_24BIT_SHIFT) & NETC_ETHSWT_IP_0XFF_MASK);

    Netc_EthSwt_Ip_FillInKeyeDataForIPF(IngressPortFilterTableEntry);  /* fill in the rest part of the KEYE_DATA */

    /* Match Count data */
    IngressPortFilterTableEntry->IngressPortFilterMatchCount = (uint64)(TableDataBuffer.TableDataField[55U]);
    IngressPortFilterTableEntry->IngressPortFilterMatchCount |= ((uint64)(TableDataBuffer.TableDataField[56U]) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* CFGE_DATA */
    CfgeData = TableDataBuffer.TableDataField[57U];             /* config field in CFGE_DATA */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeIpv = (uint8)(CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IPV_MASK);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideIpv = (((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_OIPV_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeDr = (uint8)((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_DR_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideDr = (((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_ODR_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterForwardingAction = ((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTFA_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeIngressMirroringEnable = (((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_IMIRE_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeWakeOnLanTriggerEnable = (((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_WOLTE_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterAction = ((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_FLTA_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeRelativePrecedentResolution = (uint8)((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_RPR_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeCutThroughDisable = (((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_CTD_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeHostReason = (uint8)((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_HR_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeTimestampCaptureEable = (((CfgeData & NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP_MASK) >> NETC_ETHSWT_IP_IPFTABLE_CFGE_CONFIG_TIMECAP_SHIFT) != 0x0UL) ? TRUE : FALSE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryIngressPortFilterTableEntry
 * Description   : Ethernet Switch querys Ingress Port Filter table entry function.
 * implements Netc_EthSwt_Ip_QueryIngressPortFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressPortFilterTableEntry( uint8 SwitchIdx,
                                                                               uint32 *MatchedEntries,
                                                                               Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                             )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 KeyeData[NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN];
    uint32 ActionsData;


#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressPortFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support "full query" */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);

    /* inialize KEYE_DATA with Entry_ID */
    KeyeData[0U] = IngressPortFilterTableEntry->IngressPortFilterEntryID;

    status = Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_ENTRY_ID_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            /* if found a matched entry, then fill in the structure */
            if (1U == *MatchedEntries)
            {
                Netc_EthSwt_Ip_FillInIPFTableEntryData(IngressPortFilterTableEntry);
            }
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteIngressPortFilterTableEntry
 * Description   : Ethernet Switch deletes Ingress Port Filter table entry function.
 * implements Netc_EthSwt_Ip_DeleteIngressPortFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressPortFilterTableEntry( uint8 SwitchIdx,
                                                                                uint32 *MatchedEntries,
                                                                                uint32 IngressPortFilterEntry
                                                                              )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 KeyeData[1U];
    uint32 ActionsData = 0x0UL;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* inialize KEYE_DATA with Entry_ID */
    KeyeData[0U] = IngressPortFilterEntry;

    status = Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_ENTRY_ID_MATCH);
    if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigPortTimeGateScheduling
 * Description   : Ethernet Switch enables or disables Time Gate Scheduling function on a port.
 * implements Netc_EthSwt_Ip_ConfigPortTimeGateScheduling_Activity
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_ConfigPortTimeGateScheduling( uint8 SwitchIdx,
                                                                           uint8 SwitchPortIdx,
                                                                           boolean Enable
                                                                         )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint32 RegValue;
    uint32 GateControlListState;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void)SwitchIdx;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_60();
    /* read the reg value first */
    RegValue = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTGSCR;
    if ((RegValue & SW_PORT0_PTGSCR_TGE_MASK) != SW_PORT0_PTGSCR_TGE_MASK)      /* time gating is disabled */
    {
        if (TRUE == Enable)
        {
            /* Software must also wait until PTGAGLSR[TG] is deasserted before re-enabling. */
            Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
            do {
                /* get the state of gate control list */
                GateControlListState = (Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTGAGLSR & SW_PORT0_PTGAGLSR_TG_MASK);
                TimeExpired = Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                #ifdef MCAL_ENABLE_FAULT_INJECTION
                    MCAL_FAULT_INJECTION_POINT(ETHSWT_CHECK_TG_TIMEOUT);
                #endif
            } while ((GateControlListState != 0x0U) && (FALSE == TimeExpired));

            if (GateControlListState == 0x0U)
            {
                RegValue |= SW_PORT0_PTGSCR_TGE(1U);    /* Enable time gating */
            }
            else
            {
                status = E_NOT_OK;  /* fail to enable time gating because Operational gate control list is active */
            }
        }
    }
    else    /* time gating is enabled */
    {
        if (FALSE == Enable)
        {
            RegValue &= ~SW_PORT0_PTGSCR_TGE(1U);    /* Disable time gating */
        }
    }

    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
        /* write it back. */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTGSCR = RegValue;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_60();

        /* if time gate scheduling is enabled, and entry data is configured, then adds the entry */
        if ((TRUE == Enable) && (TRUE == PortTimeAwareShaperEnabled[SwitchPortIdx]))
        {
            status = Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry(0U, &TimeGateSchedulingEntryData[SwitchPortIdx]);
            /* fail to add or update the time gate schedulling table entry */
            if (status != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            {
                status = E_NOT_OK;
            }
        }
    }
    else
    {
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_60();
    }

    return status;
}

static inline void Netc_EthSwt_Ip_FillInGateControlListData(const uint8 *OperationTimeIdx, const Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry)
{
    uint8 CFGEDataIdx;
    uint16 GateEntryIdx;
    uint8 HostRequest;

    if (*OperationTimeIdx == 1U)
    {
        CFGEDataIdx = 0U;
#if (NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES > 0U)
        for (GateEntryIdx = 0U; GateEntryIdx < TimeGateSchedulingTableEntry->AdminControlListLength; GateEntryIdx++)
        {
            TableDataBuffer.TableDataField[(uint8)(NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA5) + CFGEDataIdx] = TimeGateSchedulingTableEntry->GateEntryAdminControlListData[GateEntryIdx].AdminTimeInterval;
            /* convert gate operation type */
            switch (TimeGateSchedulingTableEntry->GateEntryAdminControlListData[GateEntryIdx].AdminGateOperationType)
            {
                case ETHSWT_HOST_REQUEST_UNCHANGED:
                    HostRequest = 0U;
                    break;
                case ETHSWT_HOST_REQUEST_HOLD:
                    HostRequest = 1U;
                    break;
                case ETHSWT_HOST_REQUEST_RELEASE:
                    HostRequest = 2U;
                    break;
                default:
                    HostRequest = 0U;
                    break;
            }
            TableDataBuffer.TableDataField[(uint8)(NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA6) + CFGEDataIdx] = NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_TC_STATES(TimeGateSchedulingTableEntry->GateEntryAdminControlListData[GateEntryIdx].AdminTrafficClassGateStates) \
                                                                                                        | NETC_ETHSWT_IP_TGSTABLE_CFGE_ADMIN_HR_CB(HostRequest);

            CFGEDataIdx += 2U;      /* CFGE data field index increased by 2 */
        }
#endif
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry
 * Description   : Ethernet Switch adds or updates Time Gate Scheduling table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry_Activity
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry( uint8 SwitchIdx,
                                                                                      const Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry
                                                                                    )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint8 OperationTimes;
    uint8 OperationTimeIdx;
    volatile uint64 CurrentTime = 0;
    uint64 CycleFactor;
    uint64 NewBaseTime;
    uint64 LookaheadTime;
    uint64 ComparisonValue;
#if defined(ERR_IPV_NETC_051587)
    #if (STD_ON == ERR_IPV_NETC_051587)
    uint64 AdminCtrlListLength;
    uint64 CmdProccesingTime;
    uint32 NetcClkPeriod;
    #endif
#endif

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(TimeGateSchedulingTableEntry != NULL_PTR);
#endif

    /* AdminControlListLength = 0U means to reset the gate control list or add the time gate scheduling entry without gate control list */
    OperationTimes = (TimeGateSchedulingTableEntry->AdminControlListLength > 0U) ? 2U : 1U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_43();

    /* for adding or updating gate control list, we'll have to remove the gate control list firstly */
    for (OperationTimeIdx = 0U; OperationTimeIdx < OperationTimes; OperationTimeIdx++)
    {

        /* ++++++ initialize the table request data buffer ++++++ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);    /* fill in Actions field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = TimeGateSchedulingTableEntry->TimeGateSchedulingTable_EID;    /* fill in Entry ID */
        /* fill in CFGE_DATA */
        /* get the current time from 1588 timer */
        CurrentTime = Netc_EthSwt_Ip_TimerBase->TMR_CUR_TIME_L;      /* should read the Lower register first */
        CurrentTime |= ((uint64)(Netc_EthSwt_Ip_TimerBase->TMR_CUR_TIME_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;
        /* get lookaheadtime */
        LookaheadTime = IP_NETC__NETC_IERB->CFG_SW_INST[0U].STGSLR; /* [Ricky]TODO: this register is not available for now + Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->RESERVED_7; */

        /* calculate the NewBaseTime */
#if defined(ERR_IPV_NETC_051587)
    #if (STD_ON == ERR_IPV_NETC_051587)
        NetcClkPeriod = (Netc_EthSwt_Ip_TimerBase->TMR_CTRL & TMR0_BASE_TMR_CTRL_TCLK_PERIOD_MASK) >> TMR0_BASE_TMR_CTRL_TCLK_PERIOD_SHIFT;
        AdminCtrlListLength = (uint64)(TimeGateSchedulingTableEntry->AdminControlListLength);
        CmdProccesingTime = (300UL + (AdminCtrlListLength*7UL) + (AdminCtrlListLength*AdminCtrlListLength*5UL)) * ((uint64)NetcClkPeriod);

        ComparisonValue = CurrentTime + LookaheadTime + CmdProccesingTime + ((uint64)2U * (uint64)TimeGateSchedulingTableEntry->AdminCycleTime);
        if ((Netc_EthSwt_Ip_TGSAdminListRegistered[TimeGateSchedulingTableEntry->TimeGateSchedulingTable_EID] == (boolean)FALSE) || \
        (TimeGateSchedulingTableEntry->AdminBaseTime >= ComparisonValue))
    #else
        ComparisonValue = CurrentTime + LookaheadTime;
        if (TimeGateSchedulingTableEntry->AdminBaseTime >= ComparisonValue)
    #endif
#else
        ComparisonValue = CurrentTime + LookaheadTime;
        if (TimeGateSchedulingTableEntry->AdminBaseTime >= ComparisonValue)
#endif
        {
            NewBaseTime = TimeGateSchedulingTableEntry->AdminBaseTime;
        }
        else
        {
#if defined(ERR_IPV_NETC_051587)
    #if (STD_ON == ERR_IPV_NETC_051587)
            CycleFactor = ((CurrentTime + LookaheadTime + CmdProccesingTime - TimeGateSchedulingTableEntry->AdminBaseTime) / ((uint64)TimeGateSchedulingTableEntry->AdminCycleTime)) + 2U;
    #else
            CycleFactor = (CurrentTime + LookaheadTime - TimeGateSchedulingTableEntry->AdminBaseTime) / ((uint64)TimeGateSchedulingTableEntry->AdminCycleTime);
    #endif
#else
            CycleFactor = (CurrentTime + LookaheadTime - TimeGateSchedulingTableEntry->AdminBaseTime) / (TimeGateSchedulingTableEntry->AdminCycleTime);
#endif
            NewBaseTime = TimeGateSchedulingTableEntry->AdminBaseTime + ((CycleFactor + 1UL) * (uint64)(TimeGateSchedulingTableEntry->AdminCycleTime));
        }
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = (uint32)(NewBaseTime & (NETC_ETHSWT_IP_BD_NULL_ENTRY_ID));
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = (uint32)(NewBaseTime >> NETC_ETHSWT_IP_32BIT_SHIFT);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = TimeGateSchedulingTableEntry->AdminCycleTime;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = TimeGateSchedulingTableEntry->AdminCycleTimeExt;
        /* set Administrative Control List Length to 0 for removing the admin gate control list or adding an entry with no administrative gate control list */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = (OperationTimeIdx == 0U) ? 0x0UL : (uint32)(TimeGateSchedulingTableEntry->AdminControlListLength);

        Netc_EthSwt_Ip_FillInGateControlListData(&OperationTimeIdx, TimeGateSchedulingTableEntry);
        /* ------ initialize the table request data buffer ------ */

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_TIME_GATE_SCHEDULING_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support NETC_ETHSWT_ENTRY_ID_MATCH method */
        Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_UPDATE_CMD;                                   /* can only use "update" command to add or update an time gate scheduling table entry */
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TGSTABLE_ADD_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TGSTABLE_RSPBUFFER_LEN);

        /* send "update" command to add/remove gate control list */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

        #if defined(ERR_IPV_NETC_051254)
            #if (STD_ON == ERR_IPV_NETC_051254)
        if (NETC_ETHSWT_IP_CBDRSTATUS_ADMIN_BASE_TIME_IS_MORE_THAN_1S == status)
        {
            /* set Administrative Control List Length to 0 for removing the admin gate control list */
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = 0x0UL;

            Netc_EthSwt_Ip_FillInGateControlListData(&OperationTimeIdx, TimeGateSchedulingTableEntry);
            /* send "update" command to remove gate control list */
            (void)Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        }
            #endif
        #endif

        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        }
    }

#if defined(ERR_IPV_NETC_051587)
    #if (STD_ON == ERR_IPV_NETC_051587)
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
        Netc_EthSwt_Ip_TGSAdminListRegistered[TimeGateSchedulingTableEntry->TimeGateSchedulingTable_EID] = (boolean)TRUE;
    }
    #endif
#endif

    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_43();

    return status;
}

/*!
 * @brief   : Function for accessing 64 bits counters.
 * @details : Function for extracting the counter value using base/offset
 *
 * @param[in] baseAddressValue base address in uint32
 * @param[in] offsetAddressValue offset from the base
 *
 * @return Register value
 */
static inline uint64 Netc_EthSwt_Ip_Extract64bitsFrom32bitsReg(const uint32 baseAddressValue, const uint32 offsetAddressValue)
{
    uint32 lessSignificantPtrValue;
    const volatile uint32 *ptrToLessSignificantData;
    uint64 lessSignificantAddressData, mostSignificantAddressData;

    /* The 64bits counter are in two chunk of 32bits */
    /* We will need to make some arithmitic on the pointers */

    /* The most significant is higher in memory, the next address to get the next 32 bits */
    lessSignificantPtrValue = baseAddressValue + offsetAddressValue;

    /* Convert back the numbers in pointers */
    ptrToLessSignificantData = (volatile uint32 *) lessSignificantPtrValue;
#if defined(ERR_IPV_NETC_050679)
    /*
    Workaround for ERR050679:
    Accesses to 64-bit stats registers must be performed atomically
    */
    #if (STD_ON == ERR_IPV_NETC_050679)
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_00();
    #endif
#endif

    /* Extract the two 32 bits of data, lower address must be read first, this will lock the higher part */
    /* Note that there is only one higher value buffer, should be exclusive... semaphore, what about the other cores? High level problem to be aware of */
    lessSignificantAddressData = ptrToLessSignificantData[0U]; /* must be first */
    mostSignificantAddressData = ptrToLessSignificantData[1U];

#if defined(ERR_IPV_NETC_050679)
    #if (STD_ON == ERR_IPV_NETC_050679)
    /*
    Workaround for ERR050679:
    Accesses to 64-bit stats registers must be performed atomically
    */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_00();
    #endif
#endif

    /* putting it all together */
    return ((mostSignificantAddressData << NETC_ETHSWT_IP_32BIT_SHIFT) | lessSignificantAddressData);
}

/*!
 * @brief   : Function for accessing 64 bits counters in a table.
 * @details : Function for getting the 64 bits counters using two 32 bits accesses.
 *
 * @param[in] Reg 64bits register pointer
 *
 * @return Register value
 */
static inline uint64 Netc_EthSwt_Ip_GetCounterLocal(const volatile uint64 *Reg)
{
    return Netc_EthSwt_Ip_Extract64bitsFrom32bitsReg((uint32) Reg, 0U);
}

/*!
 * @brief Ethernet Switch get port index counter values function.
 *
 * @param[in] SwitchIdx
 * @param[in] PortIndex
 * @param[in] Counter
 *
 * @return Std Error
 */
static Std_ReturnType Netc_EthSwt_Ip_GetSwtPortCounters( uint8 SwitchIdx, uint8 PortIndex, Netc_EthSwt_Ip_CounterType *Counter )
{
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    /* Receive */
    /* Port MAC index Receive Ethernet Octets Counter(etherStatsOctetsn) */
    Counter->rxEtherOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_REOCTN));
    Counter->rxEtherOctetCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_REOCTN));


    /* Port MAC index Receive Octets Counter(iflnOctetsn)  */
    Counter->rxOctetCounter =  Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_ROCTN));
    Counter->rxOctetCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_ROCTN));

    /* Port MAC index Receive Alignment Error Counter Register(aAlignmentErrorsn) */
    /* Reserved */

    /* Port MAC index Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
    Counter->rxValidPauseFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RXPFN);
    Counter->rxValidPauseFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RXPFN));

    /* Port MAC index Receive Frame Counter */
    Counter->rxFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RFRMN);
    Counter->rxFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RFRMN));

    /* Port MAC index Receive Frame Check Sequence Error Counter */
    Counter->rxFrameCheckSequenceErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RFCSN);
    Counter->rxFrameCheckSequenceErrorCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RFCSN));

    /* Port MAC index Receive VLAN Frame Counter */
    Counter->rxVlanFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RVLANN);
    Counter->rxVlanFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RVLANN));

    /* Port MAC index Receive Frame Error Counter Register(ifInErrorsn) */
    Counter->rxFrameErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RERRN);
    Counter->rxFrameErrorCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RERRN));

    /* Port MAC index Receive Unicast Frame Counter */
    Counter->rxUnicastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RUCAN);
    Counter->rxUnicastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RUCAN));

    /* Port MAC index Receive Multicast Frame Counter */
    Counter->rxMulticastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RMCAN);
    Counter->rxMulticastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RMCAN));

    /* Port MAC index Receive Broadcast Frame Counter */
    Counter->rxBroadcastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RBCAN);
    Counter->rxBroadcastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RBCAN));

    /* Port MAC index Receive Dropped Packets Counter Register(etherStatsDropEventsn) */
    Counter->rxDroppedPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RDRPN);
    Counter->rxDroppedPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RDRPN));

    /* Port MAC index Receive Packets Counter Register(etherStatsPktsn) */
    Counter->rxPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RPKTN);
    Counter->rxPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RPKTN));

    /* Port MAC index Receive Undersized Packet Counter */
    Counter->rxUndersizePacketCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RUNDN);
    Counter->rxUndersizePacketCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RUNDN));

    /* Port MAC index Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) */
    Counter->rx64OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R64N);
    Counter->rx64OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R64N));

    /* Port MAC index Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) */
    Counter->rx65to127OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R127N);
    Counter->rx65to127OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R127N));

    /* Port MAC index Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) */
    Counter->rx128to255OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R255N);
    Counter->rxBroadcastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R255N));

    /* Port MAC index Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) */
    Counter->rx256to511OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R511N);
    Counter->rx256to511OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R511N));

    /* Port MAC index Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) */
    Counter->rx512to1023OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R1023N);
    Counter->rx512to1023OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R1023N));

    /* Port MAC index Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) */
    Counter->rx1024to1522OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R1522N);
    Counter->rx1024to1522OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R1522N));

    /* Port MAC index Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) */
    Counter->rx1523toMaxOctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R1523XN);
    Counter->rx1523toMaxOctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R1523XN));

    /* Port MAC index Receive Oversized Packet Counter */
    Counter->rxOversizedPacketsCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_ROVRN);
    Counter->rxOversizedPacketsCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_ROVRN));

    /* Port MAC index Receive Jabber Packet Counter Register(etherStatsJabbersn) */
    Counter->rxJabberPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RJBRN);
    Counter->rxJabberPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RJBRN));

    /* Port MAC index Receive Fragment Packet Counter Register(etherStatsFragmentsn) */
    Counter->rxFragmentPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RFRGN);
    Counter->rxFragmentPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RFRGN));

    /* Port MAC index Receive Control Packet Counter Register */
    Counter->rxControlPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RCNPN);
    Counter->rxControlPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RCNPN));

    /* Port MAC index Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) */
    Counter->rxDroppedNTruncatedPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RDRNTPN);
    Counter->rxDroppedNTruncatedPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RDRNTPN));

    /* Port Rx discard count register */
    Counter->rxDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PRXDCR;

    /* Transmit */
    /* Port MAC index Transmit Ethernet Octets Counter(etherStatsOctetsn) */
    Counter->txEtherOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TEOCTN);
    Counter->txEtherOctetCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TEOCTN));

    /* Port MAC index Transmit Octets Counter Register(ifOutOctetsn) */
    Counter->txOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TOCTN);
    Counter->txOctetCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TOCTN));

    /* Port MAC index Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
    Counter->txValidPauseFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TXPFN);
    Counter->txValidPauseFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TXPFN));

    /* Port MAC index Transmit Frame Counter */
    Counter->txFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TFRMN);
    Counter->txFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TFRMN));

    /* Port MAC index Transmit Frame Check Sequence Error Counter */
    Counter->txFrameCheckSequenceErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TFCSN);
    Counter->txFrameCheckSequenceErrorCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TFCSN));

    /* Port MAC index Transmit VLAN Frame Counter */
    Counter->txVlanFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TVLANN);
    Counter->txVlanFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TVLANN));

    /* Port MAC index Transmit Frame Error Counter Register(ifOutErrorsn) */
    Counter->txFrameErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TERRN);
    Counter->txFrameErrorCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TERRN));

    /* Port MAC index Transmit Unicast Frame Counter */
    Counter->txUnicastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TUCAN);
    Counter->txUnicastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TUCAN));

    /* Port MAC index Transmit Multicast Frame Counter */
    Counter->txMulticastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TMCAN);
    Counter->txMulticastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TMCAN));

    /* Port MAC index Transmit Broadcast Frame Counter */
    Counter->txBroadcastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TBCAN);
    Counter->txBroadcastFrmCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TBCAN));

    /* Port MAC index Transmit Packets Counter Register(etherStatsPktsN; */
    Counter->txPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TPKTN);
    Counter->txPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TPKTN));

    /* Port MAC index Transmit Undersized Packet Counter */
    Counter->txUndersizePacketCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TUNDN);
    Counter->txUndersizePacketCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TUNDN));

    /* Port MAC index Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) */
    Counter->tx64OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T64N);
    Counter->tx64OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T64N));

    /* Port MAC index Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) */
    Counter->tx65to127OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T127N);
    Counter->tx65to127OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T127N));

    /* Port MAC index Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) */
    Counter->tx128to255OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T255N);
    Counter->tx128to255OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T255N));

    /* Port MAC index Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) */
    Counter->tx256to511OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T511N);
    Counter->tx256to511OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T511N));

    /* Port MAC index Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) */
    Counter->tx512to1023OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T1023N);
    Counter->tx512to1023OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T1023N));

    /* Port MAC index Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) */
    Counter->tx1024to1522OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T1522N);
    Counter->tx1024to1522OctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T1522N));

    /* Port MAC index Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) */
    Counter->tx1523toMaxOctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T1523XN);
    Counter->tx1523toMaxOctetPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T1523XN));

    /* Port MAC index Transmit Control Packet Counter Register */
    Counter->txControlPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TCNPN);
    Counter->txControlPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TCNPN));

    /* Port MAC index Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) */
    Counter->txDeferredPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TDFRN);
    Counter->txDeferredPktCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TDFRN));

    /* Port MAC index Transmit Multiple Collisions Counter Register */
    Counter->txMultiCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TMCOLN);
    Counter->txMultiCollisionCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TMCOLN));

    /* Port MAC index Transmit Single Collision Counter Register */
    Counter->txSingleCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TSCOLN);
    Counter->txSingleCollisionCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TSCOLN));

    /* Port MAC index Transmit Late Collision Counter(aLateCollisions) Register */
    Counter->txLateCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TLCOLN);
    Counter->txLateCollisionCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TLCOLN));

    /* Port MAC index Transmit Excessive Collisions Counter Register */
    Counter->txExcessiveCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TECOLN);
    Counter->txExcessiveCollisionCounter += Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TECOLN));

#if defined(ERR_IPV_NETC_E051023)
    #if (STD_ON == ERR_IPV_NETC_E051023)
    /* ERR051023: NETC: Excessive collisions are counted as late collisions */
    Counter->txLateCollisionCounter -= Counter->txExcessiveCollisionCounter;
    #endif
#endif

    /* Port Tx discard count register */
    Counter->txDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PTXDCR;

#if defined(ERR_IPV_NETC_E051129)
    #if (STD_ON == ERR_IPV_NETC_E051129)
    /* Errata ERR051129: Uncorrectable non-fatal integrity error count register */
    Counter->unIntegrityErrorCounter = IP_NETC__SW0_COMMON->UNIECTR;
    Counter->unIntegrityErrorCounter &= ((uint32)NETC_F2_COMMON_UNIECTR_COUNT_MASK);
    #endif
#endif

    return E_OK;
}


/*!
 * @brief Ethernet Switch function to get counter values for individual MAC (MAC0 - EMAC / MAC1 - PMAC) on a port.
 *
 * @param[in] SwitchIdx
 * @param[in] PortIndex
 * @param[in] MacIndex
 * @param[in] Counter
 *
 * @return Std Error
 */
static Std_ReturnType Netc_EthSwt_Ip_GetSwtPortIndividualMacCounters( uint8 SwitchIdx, uint8 PortIndex, boolean MacIndex, Netc_EthSwt_Ip_CounterType *Counter )
{
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    if (MacIndex == (boolean)0U)
    {
        /* Receive */
        /* Port MAC index Receive Ethernet Octets Counter(etherStatsOctetsn) */
        Counter->rxEtherOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_REOCTN));


        /* Port MAC index Receive Octets Counter(iflnOctetsn)  */
        Counter->rxOctetCounter =  Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_ROCTN));

        /* Port MAC index Receive Alignment Error Counter Register(aAlignmentErrorsn) */
        /* Reserved */

        /* Port MAC index Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
        Counter->rxValidPauseFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RXPFN);

        /* Port MAC index Receive Frame Counter */
        Counter->rxFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RFRMN);

        /* Port MAC index Receive Frame Check Sequence Error Counter */
        Counter->rxFrameCheckSequenceErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RFCSN);

        /* Port MAC index Receive VLAN Frame Counter */
        Counter->rxVlanFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RVLANN);

        /* Port MAC index Receive Frame Error Counter Register(ifInErrorsn) */
        Counter->rxFrameErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RERRN);

        /* Port MAC index Receive Unicast Frame Counter */
        Counter->rxUnicastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RUCAN);

        /* Port MAC index Receive Multicast Frame Counter */
        Counter->rxMulticastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RMCAN);

        /* Port MAC index Receive Broadcast Frame Counter */
        Counter->rxBroadcastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RBCAN);

        /* Port MAC index Receive Dropped Packets Counter Register(etherStatsDropEventsn) */
        Counter->rxDroppedPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RDRPN);

        /* Port MAC index Receive Packets Counter Register(etherStatsPktsn) */
        Counter->rxPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RPKTN);

        /* Port MAC index Receive Undersized Packet Counter */
        Counter->rxUndersizePacketCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RUNDN);

        /* Port MAC index Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) */
        Counter->rx64OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R64N);

        /* Port MAC index Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) */
        Counter->rx65to127OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R127N);

        /* Port MAC index Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) */
        Counter->rx128to255OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R255N);

        /* Port MAC index Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) */
        Counter->rx256to511OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R511N);

        /* Port MAC index Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) */
        Counter->rx512to1023OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R1023N);

        /* Port MAC index Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) */
        Counter->rx1024to1522OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R1522N);

        /* Port MAC index Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) */
        Counter->rx1523toMaxOctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_R1523XN);

        /* Port MAC index Receive Oversized Packet Counter */
        Counter->rxOversizedPacketsCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_ROVRN);

        /* Port MAC index Receive Jabber Packet Counter Register(etherStatsJabbersn) */
        Counter->rxJabberPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RJBRN);

        /* Port MAC index Receive Fragment Packet Counter Register(etherStatsFragmentsn) */
        Counter->rxFragmentPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RFRGN);

        /* Port MAC index Receive Control Packet Counter Register */
        Counter->rxControlPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RCNPN);

        /* Port MAC index Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) */
        Counter->rxDroppedNTruncatedPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_RDRNTPN);

        /* Port Rx discard count register */
        Counter->rxDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PRXDCR;

        /* Transmit */
        /* Port MAC index Transmit Ethernet Octets Counter(etherStatsOctetsn) */
        Counter->txEtherOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TEOCTN);

        /* Port MAC index Transmit Octets Counter Register(ifOutOctetsn) */
        Counter->txOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TOCTN);

        /* Port MAC index Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
        Counter->txValidPauseFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TXPFN);

        /* Port MAC index Transmit Frame Counter */
        Counter->txFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TFRMN);

        /* Port MAC index Transmit Frame Check Sequence Error Counter */
        Counter->txFrameCheckSequenceErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TFCSN);

        /* Port MAC index Transmit VLAN Frame Counter */
        Counter->txVlanFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TVLANN);

        /* Port MAC index Transmit Frame Error Counter Register(ifOutErrorsn) */
        Counter->txFrameErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TERRN);

        /* Port MAC index Transmit Unicast Frame Counter */
        Counter->txUnicastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TUCAN);

        /* Port MAC index Transmit Multicast Frame Counter */
        Counter->txMulticastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TMCAN);

        /* Port MAC index Transmit Broadcast Frame Counter */
        Counter->txBroadcastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TBCAN);

        /* Port MAC index Transmit Packets Counter Register(etherStatsPktsN; */
        Counter->txPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TPKTN);

        /* Port MAC index Transmit Undersized Packet Counter */
        Counter->txUndersizePacketCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TUNDN);

        /* Port MAC index Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) */
        Counter->tx64OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T64N);

        /* Port MAC index Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) */
        Counter->tx65to127OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T127N);

        /* Port MAC index Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) */
        Counter->tx128to255OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T255N);

        /* Port MAC index Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) */
        Counter->tx256to511OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T511N);

        /* Port MAC index Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) */
        Counter->tx512to1023OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T1023N);

        /* Port MAC index Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) */
        Counter->tx1024to1522OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T1522N);

        /* Port MAC index Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) */
        Counter->tx1523toMaxOctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_T1523XN);

        /* Port MAC index Transmit Control Packet Counter Register */
        Counter->txControlPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TCNPN);

        /* Port MAC index Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) */
        Counter->txDeferredPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TDFRN);

        /* Port MAC index Transmit Multiple Collisions Counter Register */
        Counter->txMultiCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TMCOLN);

        /* Port MAC index Transmit Single Collision Counter Register */
        Counter->txSingleCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TSCOLN);

        /* Port MAC index Transmit Late Collision Counter(aLateCollisions) Register */
        Counter->txLateCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TLCOLN);

        /* Port MAC index Transmit Excessive Collisions Counter Register */
        Counter->txExcessiveCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM0_TECOLN);
    }
    else
    {
        /* Receive */
        /* Port MAC index Receive Ethernet Octets Counter(etherStatsOctetsn) */
        Counter->rxEtherOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_REOCTN));


        /* Port MAC index Receive Octets Counter(iflnOctetsn)  */
        Counter->rxOctetCounter =  Netc_EthSwt_Ip_GetCounterLocal(&(Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_ROCTN));

        /* Port MAC index Receive Alignment Error Counter Register(aAlignmentErrorsn) */
        /* Reserved */

        /* Port MAC index Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
        Counter->rxValidPauseFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RXPFN);

        /* Port MAC index Receive Frame Counter */
        Counter->rxFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RFRMN);

        /* Port MAC index Receive Frame Check Sequence Error Counter */
        Counter->rxFrameCheckSequenceErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RFCSN);

        /* Port MAC index Receive VLAN Frame Counter */
        Counter->rxVlanFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RVLANN);

        /* Port MAC index Receive Frame Error Counter Register(ifInErrorsn) */
        Counter->rxFrameErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RERRN);

        /* Port MAC index Receive Unicast Frame Counter */
        Counter->rxUnicastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RUCAN);

        /* Port MAC index Receive Multicast Frame Counter */
        Counter->rxMulticastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RMCAN);

        /* Port MAC index Receive Broadcast Frame Counter */
        Counter->rxBroadcastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RBCAN);

        /* Port MAC index Receive Dropped Packets Counter Register(etherStatsDropEventsn) */
        Counter->rxDroppedPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RDRPN);

        /* Port MAC index Receive Packets Counter Register(etherStatsPktsn) */
        Counter->rxPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RPKTN);

        /* Port MAC index Receive Undersized Packet Counter */
        Counter->rxUndersizePacketCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RUNDN);

        /* Port MAC index Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) */
        Counter->rx64OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R64N);

        /* Port MAC index Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) */
        Counter->rx65to127OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R127N);

        /* Port MAC index Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) */
        Counter->rx128to255OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R255N);

        /* Port MAC index Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) */
        Counter->rx256to511OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R511N);

        /* Port MAC index Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) */
        Counter->rx512to1023OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R1023N);

        /* Port MAC index Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) */
        Counter->rx1024to1522OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R1522N);

        /* Port MAC index Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) */
        Counter->rx1523toMaxOctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_R1523XN);

        /* Port MAC index Receive Oversized Packet Counter */
        Counter->rxOversizedPacketsCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_ROVRN);

        /* Port MAC index Receive Jabber Packet Counter Register(etherStatsJabbersn) */
        Counter->rxJabberPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RJBRN);

        /* Port MAC index Receive Fragment Packet Counter Register(etherStatsFragmentsn) */
        Counter->rxFragmentPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RFRGN);

        /* Port MAC index Receive Control Packet Counter Register */
        Counter->rxControlPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RCNPN);

        /* Port MAC index Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) */
        Counter->rxDroppedNTruncatedPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_RDRNTPN);

        /* Port Rx discard count register */
        Counter->rxDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PRXDCR;

        /* Transmit */
        /* Port MAC index Transmit Ethernet Octets Counter(etherStatsOctetsn) */
        Counter->txEtherOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TEOCTN);

        /* Port MAC index Transmit Octets Counter Register(ifOutOctetsn) */
        Counter->txOctetCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TOCTN);

        /* Port MAC index Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
        Counter->txValidPauseFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TXPFN);

        /* Port MAC index Transmit Frame Counter */
        Counter->txFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TFRMN);

        /* Port MAC index Transmit Frame Check Sequence Error Counter */
        Counter->txFrameCheckSequenceErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TFCSN);

        /* Port MAC index Transmit VLAN Frame Counter */
        Counter->txVlanFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TVLANN);

        /* Port MAC index Transmit Frame Error Counter Register(ifOutErrorsn) */
        Counter->txFrameErrorCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TERRN);

        /* Port MAC index Transmit Unicast Frame Counter */
        Counter->txUnicastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TUCAN);

        /* Port MAC index Transmit Multicast Frame Counter */
        Counter->txMulticastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TMCAN);

        /* Port MAC index Transmit Broadcast Frame Counter */
        Counter->txBroadcastFrmCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TBCAN);

        /* Port MAC index Transmit Packets Counter Register(etherStatsPktsN; */
        Counter->txPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TPKTN);

        /* Port MAC index Transmit Undersized Packet Counter */
        Counter->txUndersizePacketCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TUNDN);

        /* Port MAC index Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) */
        Counter->tx64OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T64N);

        /* Port MAC index Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) */
        Counter->tx65to127OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T127N);

        /* Port MAC index Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) */
        Counter->tx128to255OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T255N);

        /* Port MAC index Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) */
        Counter->tx256to511OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T511N);

        /* Port MAC index Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) */
        Counter->tx512to1023OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T1023N);

        /* Port MAC index Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) */
        Counter->tx1024to1522OctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T1522N);

        /* Port MAC index Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) */
        Counter->tx1523toMaxOctetPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_T1523XN);

        /* Port MAC index Transmit Control Packet Counter Register */
        Counter->txControlPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TCNPN);

        /* Port MAC index Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) */
        Counter->txDeferredPktCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TDFRN);

        /* Port MAC index Transmit Multiple Collisions Counter Register */
        Counter->txMultiCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TMCOLN);

        /* Port MAC index Transmit Single Collision Counter Register */
        Counter->txSingleCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TSCOLN);

        /* Port MAC index Transmit Late Collision Counter(aLateCollisions) Register */
        Counter->txLateCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TLCOLN);

        /* Port MAC index Transmit Excessive Collisions Counter Register */
        Counter->txExcessiveCollisionCounter = Netc_EthSwt_Ip_GetCounterLocal(&Netc_EthSwt_Ip_PortBaseTable[PortIndex]->PM1_TECOLN);
    }

#if defined(ERR_IPV_NETC_E051023)
    #if (STD_ON == ERR_IPV_NETC_E051023)
    /* ERR051023: NETC: Excessive collisions are counted as late collisions */
    Counter->txLateCollisionCounter -= Counter->txExcessiveCollisionCounter;
    #endif
#endif

    /* Port Tx discard count register */
    Counter->txDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->PTXDCR;

#if defined(ERR_IPV_NETC_E051129)
    #if (STD_ON == ERR_IPV_NETC_E051129)
    /* Errata ERR051129: Uncorrectable non-fatal integrity error count register */
    Counter->unIntegrityErrorCounter = IP_NETC__SW0_COMMON->UNIECTR;
    Counter->unIntegrityErrorCounter &= ((uint32)NETC_F2_COMMON_UNIECTR_COUNT_MASK);
    #endif
#endif

    return E_OK;
}

/*!
 * @brief Ethernet Switch get pseudo port counter values function.
 *
 * @param[in]
 * @param[out]
 * @return
 */
static Std_ReturnType Netc_EthSwt_Ip_GetSwtPseudoPortCounters( uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_CounterType *Counter )
{
    uint32 xCR0Value;
    uint8 PseudoPortIdx;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    /* pseudo port indexes are starting after the mac ports. */
    PseudoPortIdx = 0U;

    /* Receive */
    /* Port pseudo MAC receive octets counter  */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMROCR[0];
    Counter->rxOctetCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMROCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);
    /* Port pseudo MAC receive unicast frame counter register */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMRUFCR[0];
    Counter->rxUnicastFrmCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMRUFCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);
    /* Port pseudo MAC receive multicast frame counter register */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMRMFCR[0];
    Counter->rxMulticastFrmCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMRMFCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);
    /*  Port pseudo MAC receive broadcast frame counter register */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMRBFCR[0];
    Counter->rxBroadcastFrmCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMRBFCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* unsupported rx counters */
    Counter->rxPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxFrmCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxVlanFrmCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxFrameErrorCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxUndersizePacketCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxOversizedPacketsCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxFrameCheckSequenceErrorCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxEtherOctetCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxValidPauseFrmCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxDroppedPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx64OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx65to127OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx128to255OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx256to511OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx512to1023OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx1024to1522OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rx1523toMaxOctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxJabberPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxFragmentPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxControlPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->rxDroppedNTruncatedPktCounter = 0xFFFFFFFFFFFFFFFFULL;

    /* Port Rx discard count register */
    Counter->rxDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PRXDCR;

    /*  Transmit */
    /*  Port pseudo MAC transmit octets counter  */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTOCR[0];
    Counter->txOctetCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTOCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);
    /*  Port pseudo MAC transmit unicast frame counter register */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTUFCR[0];
    Counter->txUnicastFrmCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTUFCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);
    /*  Port pseudo MAC transmit multicast frame counter register */
    xCR0Value = Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTMFCR[0];
    Counter->txMulticastFrmCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTMFCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);
    /*  Port pseudo MAC transmit broadcast frame counter register */
    xCR0Value = IP_NETC__SW0_PSEUDO_MAC_PORT2->PPMTBFCR[0];
    Counter->txBroadcastFrmCounter = xCR0Value | ((uint64)((uint32)(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx]->PPMTBFCR[1])) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port Tx discard count register */
    Counter->txDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTXDCR;

    /* unsupported tx counters */
    Counter->txPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txFrmCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txVlanFrmCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txFrameErrorCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txUndersizePacketCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txSingleCollisionCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txMultiCollisionCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txFrameCheckSequenceErrorCounter = 0xFFFFFFFFFFFFFFFFULL;

    Counter->txEtherOctetCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txValidPauseFrmCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx64OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx65to127OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx128to255OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx256to511OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx512to1023OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx1024to1522OctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->tx1523toMaxOctetPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txControlPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txDeferredPktCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txLateCollisionCounter = 0xFFFFFFFFFFFFFFFFULL;
    Counter->txExcessiveCollisionCounter = 0xFFFFFFFFFFFFFFFFULL;

#if defined(ERR_IPV_NETC_E051129)
    #if (STD_ON == ERR_IPV_NETC_E051129)
    /* Errata ERR051129: Uncorrectable non-fatal integrity error count register */
    Counter->unIntegrityErrorCounter = IP_NETC__SW0_COMMON->UNIECTR & NETC_F2_COMMON_UNIECTR_COUNT_MASK;
    #endif
#endif
    return E_OK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EnableVlan
 * Description   : Ethernet switch enable VLAN function.
 * implements Netc_EthSwt_Ip_EnableVlan_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_EnableVlan( uint8 SwitchIdx, uint8 SwitchPortIdx, uint16 VlanId, boolean Enable )
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    Netc_EthSwt_Ip_VlanFilterEntryDataType VlanFilterTableEntry;
    uint32 MatchedEntries = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    /* Query the entry with VlanId */
    VlanFilterTableEntry.VlanID = VlanId;
    CBDRStatus = Netc_EthSwt_Ip_QueryVlanFilterTableEntry(SwitchIdx, &MatchedEntries, &VlanFilterTableEntry);
    if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (MatchedEntries == 0U))
    {
        Status = E_NOT_OK;        /* Query command error or no mached Vlan ID entry found */
    }
    else
    {
        /* Get the CFGE data of a mached entry */
        VlanFilterTableEntry.SpanningTreeGroupMemberId = (uint8)((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
        VlanFilterTableEntry.PortMembershipBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK;
        VlanFilterTableEntry.IpMulticastFloodingEnable = (((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) != 0x0UL) ? TRUE : FALSE;
        VlanFilterTableEntry.IpMulticastFilteringEnable = (((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) != 0x0UL) ? TRUE : FALSE;
        VlanFilterTableEntry.MacForwardingOptions = (uint8)((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
        VlanFilterTableEntry.MacLearningOptions = (uint8)((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
        VlanFilterTableEntry.FID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_MASK);
        VlanFilterTableEntry.EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
        VlanFilterTableEntry.BaseEgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_MASK;

        /* Modify port membership bitmap data */
        if (TRUE == Enable)
        {
            VlanFilterTableEntry.PortMembershipBitmap |= (uint32)(0x1UL << SwitchPortIdx);            /* add the port to the portmembershipbitmap */
        }
        else
        {
            VlanFilterTableEntry.PortMembershipBitmap &= ~((uint32)(0x1UL << SwitchPortIdx));        /* remove the port from the portmembershipbitmap */
        }

        /* Update the entry */
        VlanFilterTableEntry.VlanID = VlanId;
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry(SwitchIdx, NETC_ETHSWT_UPDATE_CMD, &MatchedEntries, &VlanFilterTableEntry);
        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            Status = E_NOT_OK;        /* Update command error */
        }

    }

    return Status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ResetConfiguration
 * Description   : Ethernet switch reset configuration function.
 * implements Netc_EthSwt_Ip_ResetConfiguration_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_ResetConfiguration(uint8 SwitchIdx)
{
    /*
     * [notes]: implemented this function with singel delete command and Search Method.
    */
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    /* set the query options with ENTRY_ID only query */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(1U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_45();

    /*+++ fill in FdbTabeDataBuffer for Request Data Buffer +++ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;    /* fill in the Actions field */
    /* fill in Access Key data field with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_RESUMEENTRYID] = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;  /* resume entry id */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_L] = 0U;            /* clear other unuse data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_H] = 0U;            /* clear other unuse data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_FID] = 0U;            /* clear other unuse data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_PORTBITMAP] = 0U;            /* clear other unuse data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGECONFIG] = NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(1U);   /* set CFGE_DATA[DYNAMIC] to 0x1 meaning it will match dynamic entries */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ETEID] = 0U;            /* clear other unuse data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC(1U);      /* 0x1: Match CFGE_DATA[DYNAMIC] field */
    /*--- fill in FdbTabeDataBuffer for Request Data Buffer --- */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_45();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;        /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;                        /* delete all matched entries with Search Method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

    /* send the "Delete" command */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
        status = E_NOT_OK;
    }

    return status;
}

static inline Std_ReturnType Netc_EthSwt_Ip_SearchAndFIllInVlanFilterTableEntry(uint32 * ResumeId,
                                                                                uint16 * NumOfExistingEntry,
                                                                                Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableEntry)
{
    Std_ReturnType status = E_OK;
    uint32 ActionsData;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 NumOfElement = 0U;
    uint32 CfgeData;

    /* set the query options with full query */
    ActionsData = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U));

    /* fill in TabeDataBuffer for request */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;
    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_RESUMEENTRYID_FIELD] = *ResumeId;    /* resume entry id */

    /* do the full query with Search Method */
    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_VLANFILTERTABLE_RESBUFFER_LEN);           /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(0U, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);

    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* check the status of query command */
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeId = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_RSPDATA_STATUS];
        /* ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED */
        /* found a matched entry */
        if ((1U == NumOfElement) && (*ResumeId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
                        /* fill in "Netc_EthSwt_Ip_VlanFilterEntryDataType" structure with data in response data buffer */
            VlanFilterTableEntry->VlanID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_VID] & NETC_ETHSWT_IP_VLANFILTERTABLE_KEYEDATA_VID_MASK);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0];
            VlanFilterTableEntry->SpanningTreeGroupMemberId = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
            VlanFilterTableEntry->PortMembershipBitmap = (CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1];
            VlanFilterTableEntry->FID = (uint16)(CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_FID_MASK);
            VlanFilterTableEntry->MacLearningOptions = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
            VlanFilterTableEntry->MacForwardingOptions = (uint8)((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
            VlanFilterTableEntry->IpMulticastFilteringEnable = (((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) == 0x0UL) ? FALSE : TRUE;
            VlanFilterTableEntry->IpMulticastFloodingEnable = (((CfgeData & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) == 0x0UL) ? FALSE : TRUE;

            VlanFilterTableEntry->EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_IP_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
            VlanFilterTableEntry->BaseEgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3];
            /* increase the NumOfExistingEntry */
            (*NumOfExistingEntry) += 1U;
        }
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

static inline Std_ReturnType Netc_EthSwt_Ip_SyncVlanFilterTableMLO( uint8 SwitchIdx,
                                                                    Netc_EthSwt_Ip_MacLearningOptionType MacLearningMode
                                                                  )
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;

    uint16 NumOfExistingEntry = 0U;
    static uint16 NumOfInUseEntry;
    uint32 ResumeId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;
    Netc_EthSwt_Ip_VlanFilterEntryDataType VlanFilterTableEntry = {0U};
    Netc_EthSwt_Ip_CommandsType Cmd = NETC_ETHSWT_UPDATE_CMD;
    uint32 MatchedEntries;

    /* [notes]: we will have to read entries one by one because of the errata ERR051048.
     - ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED
     - Description: The NUM_MATCHED field in the command NTMP response header may be incorrect when
       the search access method is used for the following tables: FDB table 15, L2 IPv4 Multicast
       Filter table 16, VLAN Filter table 18, Ingress Stream Identification table 30, or Ingress Stream
       Filter table 32.
     - Workaround: For the query command, limit the message response buffer size (RESPONSE_LENGTH field in the request header)
       so that NETC returns no more than one entry at a time. Under this condition, the NUM_MATCHED field value is correct
    */

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;
    /* Number of entries in-use by the VLAN Filter table is indicated in VFHTOR[NUM_ENTRIES]. */
    NumOfInUseEntry = (uint16)(IP_NETC__SW0_BASE->VFHTOR & NETC_ETHSWT_IP_0XFFFF_MASK);    /* get how many entries exist in module */

    /* if NumOfInUseEntry == 0U, return the NumOfInUseEntry directly and will not do the query and fill in the structure */
    if (NumOfInUseEntry > 0U)  /* if *NumberOfElements > 0, do the query and fill in the structure */
    {
        do {
            status = Netc_EthSwt_Ip_SearchAndFIllInVlanFilterTableEntry((uint32 *) &ResumeId, (uint16 *) &NumOfExistingEntry, &VlanFilterTableEntry);

            if (status == (uint8)(E_NOT_OK))
            {
                break;
            }

            /*Update MLO, for the current entry, if necessary*/
            if ((VlanFilterTableEntry.MacLearningOptions != (uint8)MacLearningMode))
            {
                VlanFilterTableEntry.MacLearningOptions = (uint8)MacLearningMode;
                CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry( SwitchIdx, Cmd, (uint32 *) &MatchedEntries, (const Netc_EthSwt_Ip_VlanFilterEntryDataType *)  &VlanFilterTableEntry );
                if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != CBDRStatus)
                {
                    status = E_NOT_OK;
                }
            }

        } while ((TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_RSPDATA_STATUS] != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID) && (status == (uint8)(E_OK)) && (NumOfExistingEntry < NumOfInUseEntry));

    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetMacLearningMode
 * Description   : Ethernet switch set MAC learning mode function.
 * implements Netc_EthSwt_Ip_SetMacLearningMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetMacLearningMode( uint8 SwitchIdx,
                                                  Netc_EthSwt_Ip_MacLearningOptionType MacLearningMode
                                                )
{
    Std_ReturnType status;
    uint32 MacLearningOption;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    MacLearningOption = IP_NETC__SW0_BASE->VFHTDECR2;
    MacLearningOption &= ~NETC_F2_VFHTDECR2_MLO_MASK;

    status = Netc_EthSwt_Ip_SyncVlanFilterTableMLO(SwitchIdx, MacLearningMode);

    if (E_OK == status)
    {
        switch (MacLearningMode)
        {
            case ETHSWT_MACLEARNINGOPTION_HWDISABLED:
                MacLearningOption |= NETC_F2_VFHTDECR2_MLO(ETHSWT_MACLEARNINGOPTION_HWDISABLED);
                break;
            case ETHSWT_MACLEARNINGOPTION_HWENABLED:
                MacLearningOption |= NETC_F2_VFHTDECR2_MLO(ETHSWT_MACLEARNINGOPTION_HWENABLED);
                break;
            case ETHSWT_MACLEARNINGOPTION_SWSECUREENABLED:
                MacLearningOption |= NETC_F2_VFHTDECR2_MLO(ETHSWT_MACLEARNINGOPTION_SWSECUREENABLED);
                break;
            case ETHSWT_MACLEARNINGOPTION_SWUNSECUREENABLED:
                MacLearningOption |= NETC_F2_VFHTDECR2_MLO(ETHSWT_MACLEARNINGOPTION_SWUNSECUREENABLED);
                break;
            case ETHSWT_MACLEARNINGOPTION_DISABLEDWITHSWVALIDATION:
                MacLearningOption |= NETC_F2_VFHTDECR2_MLO(ETHSWT_MACLEARNINGOPTION_DISABLEDWITHSWVALIDATION);
                break;
            default:
                /* log error */
                status = E_NOT_OK;
                break;
        }
    }

    IP_NETC__SW0_BASE->VFHTDECR2 = MacLearningOption;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetMacLearningMode
 * Description   : Ethernet switch get MAC learning mode function.
 * implements Netc_EthSwt_Ip_GetMacLearningMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetMacLearningMode( uint8 SwitchIdx,
                                                  Netc_EthSwt_Ip_MacLearningOptionType * MacLearningMode
                                                )
{
    Std_ReturnType status = E_OK;
    uint32 MacLearningOption;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MacLearningMode != NULL_PTR);
#endif

    (void)SwitchIdx;

    MacLearningOption = IP_NETC__SW0_BASE->VFHTDECR2;
    MacLearningOption = ((MacLearningOption & NETC_F2_VFHTDECR2_MLO_MASK) >> NETC_F2_VFHTDECR2_MLO_SHIFT);
    switch (MacLearningOption)
    {
        case 0x1UL:
            *MacLearningMode = ETHSWT_MACLEARNINGOPTION_HWDISABLED;
            break;
        case 0x2UL:
            *MacLearningMode = ETHSWT_MACLEARNINGOPTION_HWENABLED;
            break;
        case 0x3UL:
            *MacLearningMode = ETHSWT_MACLEARNINGOPTION_SWSECUREENABLED;
            break;
        case 0x4UL:
            *MacLearningMode = ETHSWT_MACLEARNINGOPTION_SWUNSECUREENABLED;
            break;
        case 0x5UL:
            *MacLearningMode = ETHSWT_MACLEARNINGOPTION_DISABLEDWITHSWVALIDATION;
            break;
        default:
            /* log error */
            status = E_NOT_OK;
            break;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetSwitchIdentifier
 * Description   : Ethernet switch hardware version function.
 * implements Netc_EthSwt_Ip_GetSwitchIdentifier_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetSwitchIdentifier(uint8 SwitchIdx, uint32 *HwVersion)
{
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    /* This dummy cast is done to support scalability in futures platforms. */
    (void)SwitchIdx;
    /* Hardware revision. */
    *HwVersion = IP_NETC__SW0_GLOBAL->IPBRR0;

    return E_OK;
}

/*FUNCTION**********************************************************************
 * Function Name : Netc_EthSwt_Ip_InitCommandBDR
 * Description   : Internal function for initializing the command ring.
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_InitCommandBDR(uint8 SwitchIdx, uint8 cbdrIndex)
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    /* check the index of command ring */
    if (cbdrIndex >= NETC_ETHSWT_IP_CBDR_NUM)
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INDEX_ERROR;
    }
    else
    {   /* initialize memory and length for command ring 0 */
        CmdBDRConfig[NETC_ETHSWT_IP_CBDR_0].CmdBDAddr = &SwtcommandRingDescriptor0[0U];
        CmdBDRConfig[NETC_ETHSWT_IP_CBDR_0].lengthCBDR = (NETC_ETHSWT_IP_CBDR0_LENGTH);

        /* configure the CBDR base address register where the address of a switch table is stored*/
        IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRBAR0 = (uint32)(CmdBDRConfig[cbdrIndex].CmdBDAddr);

        /* set the index of producer and consumer register to 0. The ring is empty now. */
        IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRPIR = NETC_F2_CBDRPIR_BDR_INDEX(0U);
        IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRCIR = NETC_F2_CBDRCIR_BDR_INDEX(0U);

        /* set the size of command ring. Size of ring in sets of 8 BDs. Maximum ring size is 1K. */
        IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRLENR = NETC_F2_CBDRLENR_LENGTH(CmdBDRConfig[cbdrIndex].lengthCBDR);

        /* enable CBDR. When the ring is non-empty, command buffer descriptors will be processed */
        IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRMR = NETC_F2_CBDRMR_EN(1U);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_FillInFdbTableReqDataBuff
 * Description   : Internal function for initializing the FDB Table Request Data Buffer.
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(uint32 ActionsData, const uint32 *pAccessKey, const Netc_EthSwt_Ip_FDBTableCFGEDataType *pCfgeData, Netc_EthSwt_Ip_AccessMethodType accessMethod)
{
    uint8 ItemIdx;
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_47();

    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;  /* fill in Actions field */

    /* initialize ACCESS_KEY */
    switch (accessMethod)
    {
        case NETC_ETHSWT_ENTRY_ID_MATCH:
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = pAccessKey[0U];        /* fill in Entry_ID field */
            break;
        case NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH:
            for (ItemIdx = 1U; ItemIdx <= NETC_ETHSWT_IP_FDB_KEYE_DATA_ITEMS; ItemIdx++)
            {
                TableDataBuffer.TableDataField[ItemIdx] = pAccessKey[ItemIdx - 1U];  /* fill in keye data field */
            }
            break;
        case NETC_ETHSWT_SEARCH_METHOD:
            for (ItemIdx = 1U; ItemIdx <= NETC_ETHSWT_IP_FDB_SEARCH_CRITERIA_DATA_ITEMS; ItemIdx++)
            {
                TableDataBuffer.TableDataField[ItemIdx] = pAccessKey[ItemIdx - 1U];  /* fill in search criteria data field */
            }
            break;
        default:
            /* Not Applicable for FDB table*/
            status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
    }

    /* initialize CFGE_DATA. This portion is present only for commands which perform an update or add. */
    if (pCfgeData != NULL_PTR)
    {
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_FIELD] = pCfgeData->Cfge_PortBitmap;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD] = pCfgeData->Cfge_ConfigField;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_CFGE_ETEID_FIELD] = pCfgeData->Cfge_EtEid;
    }
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_47();

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff
 * Description   : Internal function for initializing the Vlan Filter Table Request Data Buffer.
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(uint32 ActionsData, uint32 AccessKeyData, const Netc_EthSwt_Ip_VlanFilterTableCFGEDataType *pCfgeData, Netc_EthSwt_Ip_AccessMethodType accessMethod)
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_12();

    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;  /* fill in Actions field */

    /* initialize ACCESS_KEY Data */
    switch (accessMethod)
    {
        case NETC_ETHSWT_ENTRY_ID_MATCH:
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = AccessKeyData;        /* fill in Entry_ID field */
            break;
        case NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH:
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_VID_FIELD] = AccessKeyData;              /* fill in VID field of KEYE Data */
            break;
        case NETC_ETHSWT_SEARCH_METHOD:
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_RESUMEENTRYID_FIELD] = AccessKeyData;  /* fill in RESUME_ENTRY_ID of search criteria data */
            break;
        default:
            /* Not Applicable for Vlan Filter table*/
            status = NETC_ETHSWT_IP_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
    }

    /* initialize CFGE_DATA. This portion is present only for commands which perform an update or add. */
    if (pCfgeData != NULL_PTR)
    {
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = pCfgeData->Cfge_Data[0U];
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = pCfgeData->Cfge_Data[1U];
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = pCfgeData->Cfge_Data[2U];
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = pCfgeData->Cfge_Data[3U];

    }
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_12();

    return status;
}

static inline void Netc_EthSwt_Ip_PortConfigIngresStreamLookUp(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    const Netc_EthSwt_Ip_PortIngresStreamLookUpDataType *PortConfig = &port->iPort->EthSwtPortIngressStreamLookUpConfig;
    if(TRUE == PortConfig->PortIngressStreamEnableLookUp)
    {
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PISIDCR = SW_PORT2_PISIDCR_ISEID(PortConfig->PortIngressStreamDefaultEntryID)        |
                                                                   SW_PORT2_PISIDCR_KC0EN((uint8)PortConfig->PortIngressStreamUseFirstLookUp) |
                                                                   SW_PORT2_PISIDCR_KC1EN((uint8)PortConfig->PortIngressStreamUseSecondLookUp);

        if(TRUE == PortConfig->PortIngressStreamUseSecondKeyConstructionPair)
        {
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PISIDCR |= SW_PORT2_PISIDCR_KCPAIR(1U);
        }
        else
        {
            /* Use the first pair of Key Construction rules.  */
        }
    }
    else
    {
        /* Stream filtering is bypassed. */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PISIDCR = 0xFFFFFFFFUL;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SendCommand
 * Description   : Internal function for table operations with different commands like add, query, delete etc..
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SendCommand(uint8 SwitchIdx, uint8 cbdrIndex, const Netc_EthSwt_Ip_ReqHeaderTableOperationDataType *OperationData)
{
    uint32 producerIdx;
    uint32 consumerIdx;
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint32 PreviousProducerIdx;
    uint32 statusField;
    uint32 rrBit;
    uint32 errorField;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    /* read the producer and consumer index register */
    producerIdx = IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRPIR;
    consumerIdx = IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRCIR;

    /* check if the ring is full */
    if (((producerIdx + 0x1UL) % ((uint32)(CmdBDRConfig[cbdrIndex].lengthCBDR) * NETC_ETHSWT_IP_SET_OF_BD)) == consumerIdx)
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_RINGFULL;  /* the ring is full */
    }
    else
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_04();
        /* +++ fill in the NTMP request message header +++ */
        /* set the table address */
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_ADDR_L] = (uint32)(&TableDataBuffer);

        /* set the length of request and response data buffer */
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_LENGTHFIELD] = (NETC_ETHSWT_IP_CMDBD_REQFMT_REQUEST_LENGTH(OperationData->ReqBuffLength) | NETC_ETHSWT_IP_CMDBD_REQFMT_RESPONSE_LENGTH(OperationData->RspBuffLength));

        /* set RR = 0, CCI = 0, protocol version = 2, table id, access method and cmd */
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] = 0x0; /* clear this field first */
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] |= NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD(OperationData->Cmd);
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] |= NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD(OperationData->AccessMethod);
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] |= NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID(OperationData->TableId);
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] |= NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION(OperationData->Version);
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] |= NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI(OperationData->CmdCompletionInt);
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_CONFIGFIELD] |= NETC_ETHSWT_IP_CMDBD_REQFMT_CONFIG_FIELD_RR(0U);        /* RR bit has to be set to 0 */

        /* set NTMP version to 2.0*/
        CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_REQHEADER_NPFFIELD] = NETC_ETHSWT_IP_CMDBD_REQFMT_NPF_FIELD(NETC_ETHSWT_IP_CMDBD_REQFMT_NTMP_PROTOCOL_VERSION);
        /* --- fill in the NTMP request message header --- */
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_04();

        /* +++ write the produce index register and enable hardware to consume the command +++ */
        PreviousProducerIdx = producerIdx;        /* save the produce index before incrementing it manually */
        if ((producerIdx + 0x1UL) == ((uint32)(CmdBDRConfig[cbdrIndex].lengthCBDR) * NETC_ETHSWT_IP_SET_OF_BD))        /* adjust producer index */
        {
            producerIdx = 0x0UL;    /* when producerIdx equals ACTUAL_CBDR_LENGTH minus 1, then it would start from 0 again */
        }
        else
        {
            producerIdx += 0x1UL;   /* increase the producer index manually */
        }

        /* This is needed to make sure the descriptor gets updated with the latest values, before
           incrementing the producer index to start the actual operation */
        MCAL_DATA_SYNC_BARRIER();

        IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRPIR = NETC_F2_CBDRPIR_BDR_INDEX(producerIdx);
        /* --- write the produce index register and enable hardware to consume the command --- */

        /* +++ to make sure the hardware consumes and processes the command completely +++ */
        /* Setup timeout timer */
        Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
        do {
            statusField = CmdBDRConfig[cbdrIndex].CmdBDAddr[PreviousProducerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_RSPHEADER_STATUS_FIELD_INDEX];    /* get status field in the response data buffer */
            rrBit = ((statusField & (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_MASK)) >> (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_SHIFT));        /* get the value of RR bit in the response data buffer */
            TimeExpired = Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            #ifdef MCAL_ENABLE_FAULT_INJECTION
                MCAL_FAULT_INJECTION_POINT(ETHSWT_CHECK_RR_TIMEOUT);
            #endif
        } while ((rrBit != 0x1U) && (FALSE == TimeExpired));        /* wait the hardware consume the command and check RR bit to see if the processing is completed (rrBit = 1). */
        /* --- to make sure the hardware consumes and processes the command completely --- */

        /* the command sent was executed successfully and timely by hardware. */
        if (FALSE == TimeExpired)
        {
            /* return the value of ERROR field in response data buffer indicating if there is an error for processing the command */
            errorField = ((statusField & (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_MASK)) >> (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_SHIFT));
            if (errorField != 0U)
            {
                status = errorField;     /* ERROR field should be 0. */
            }
        }
        else    /* table operation timeout. */
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_TABLE_OPERATION_TIMEOUT;   /* either NETC_ETHSWT_IP_TIMEOUT_VALUE_US is not big enough or something wrong with the entry configuration. */
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetMatchedEntries
 * Description   : Function for getting matched table entries. Num_Matched field indicates if it matches an entry.
 *
 *END**************************************************************************/
static void Netc_EthSwt_Ip_GetMatchedEntries(uint8 cbdrIndex, uint32 *NumOfEntry)
{
    uint32 producerIdx;
    uint32 statusField;

    producerIdx = IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRPIR;

    /* the value stored in producer index register indicates the index of next entry */
    if (producerIdx == 0UL) /* producerIdx increased from 15 to 0, will set it to 15, or length minus 1 */
    {
        producerIdx = ((uint32)(CmdBDRConfig[cbdrIndex].lengthCBDR) * NETC_ETHSWT_IP_SET_OF_BD);
    }

    producerIdx -= 1UL;

    /* get status field in the response data buffer for the matched fdb entry */
    statusField = CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_RSPHEADER_STATUS_FIELD_INDEX];

    /* NUM_MATCHED should equal or greater than 1 if the entry exists for any commands. */
    *NumOfEntry = (statusField & (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_MASK));

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetCounters
 * Description   : Function for getting the counters of a port
 * For MAC counters that are 64bits, the access must be atomic.
 * implements Netc_EthSwt_Ip_GetCounters_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetCounters( uint8 SwitchIdx,
                                           uint8 SwitchPortIdx,
                                           Netc_EthSwt_Ip_CounterType *Counter
                                         )
{
    Std_ReturnType status = E_OK;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
    DevAssert(Counter != NULL_PTR);
#endif

    (void)SwitchIdx;

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        status = Netc_EthSwt_Ip_GetSwtPortCounters(SwitchIdx, SwitchPortIdx, Counter);
    }
    else
    {
        status = Netc_EthSwt_Ip_GetSwtPseudoPortCounters(SwitchIdx, SwitchPortIdx, Counter);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetAllCounters
 * Description   : Function for getting the counters from every MAC of a port.
 * For MAC counters that are 64bits, the access must be atomic.
 * implements Netc_EthSwt_Ip_GetAllCounters_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetAllCounters(uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_CounterType Counters[2U])
{
    Std_ReturnType status;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
    DevAssert(Counters != NULL_PTR);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        /* Extract counters from MAC0 */
        status = Netc_EthSwt_Ip_GetSwtPortIndividualMacCounters(SwitchIdx, SwitchPortIdx, (boolean)0U, Counters);
        if (status == E_OK)
        {
            /* Extract counters from MAC1 */
            status = Netc_EthSwt_Ip_GetSwtPortIndividualMacCounters(SwitchIdx, SwitchPortIdx, (boolean)1U, &(Counters[1U]));
        }
    }
    else
    {
        status = Netc_EthSwt_Ip_GetSwtPseudoPortCounters(SwitchIdx, SwitchPortIdx, Counters);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ComputedRegisterValueExtractionSingleCounter
 * Description   : Function for extracting the counter value using base/offset
 *END**************************************************************************/
static inline uint64 Netc_EthSwt_Ip_ComputedRegisterValueExtractionSingleCounter(const Netc_EthSwt_Ip_PortBaseType* base, const Netc_EthSwt_Ip_SingleCounterType offset)
{
    return Netc_EthSwt_Ip_Extract64bitsFrom32bitsReg((uint32) base, (uint32) offset);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter
 * Description   : Function for extracting the counter value using base/offset
 *END**************************************************************************/
static inline uint64 Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(const Netc_EthSwt_Ip_PseudoPortBaseType* base, const Netc_EthSwt_Ip_PseudoPortCounterType offset)
{
    return Netc_EthSwt_Ip_Extract64bitsFrom32bitsReg((uint32) base, (uint32) offset);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetCounter
 * Description   : Function for getting a counter from the pseudo-MAC or from one of the MACs of a port.
 * For MAC counters that are 64bits, the access must be atomic.
 * implements Netc_EthSwt_Ip_GetCounter_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CounterValueType Netc_EthSwt_Ip_GetCounter(uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_SingleCounterType Counter)
{
    uint8 PseudoPortIdx;
    uint64 CounterValue = 0UL;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void)SwitchIdx;

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        /* Compute address of the counter. for port 0 and port 1*/
        CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionSingleCounter(Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx], Counter);
    }
    else
    {
        /* pseudo port indexes are starting after the mac ports. */
        PseudoPortIdx = (uint8)0U;
        switch (Counter)
        {
            case NETC_ETHSWT_IP_RX_OCTETS_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMROCR0);
                break;
            case NETC_ETHSWT_IP_RX_UNICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMRUFCR0);
                break;
            case NETC_ETHSWT_IP_RX_MULTICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMRMFCR0);
                break;
            case NETC_ETHSWT_IP_RX_BROADCAST_FRM_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMRBFCR0);
                break;
            case NETC_ETHSWT_IP_TX_OCTETS_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMTOCR0);
                break;
            case NETC_ETHSWT_IP_TX_UNICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMTUFCR0);
                break;
            case NETC_ETHSWT_IP_TX_MULTICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMTMFCR0);
                break;
            case NETC_ETHSWT_IP_TX_BROADCAST_FRM_COUNT:
                /* Compute addres of the counter. */
                CounterValue = Netc_EthSwt_Ip_ComputedRegisterValueExtractionPseudoCounter(Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx], NETC_ETHSWT_IP_PPMTBFCR0);
                break;
            default:
                CounterValue = 0xFFFFFFFFFFFFFFFFULL;
                break;
        }

    }

    return CounterValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_PortGetLoopbackMode
 * Description   : Function for getting the loopback mode of a port
 * implements Netc_EthSwt_Ip_PortGetLoopbackMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_PortGetLoopbackMode( uint8 SwitchIdx,
                                                   uint8 SwitchPortIdx,
                                                   boolean *LoopbackEnable
                                                 )
{
    Std_ReturnType status = E_NOT_OK;
    uint32 portCommandConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;


    /* Get the loop back mode value */
    if (SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        /* Read the register */
        portCommandConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG;
        *LoopbackEnable = ((SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK & portCommandConfig) == 0U) ? FALSE : TRUE;
        status = E_OK;
    }
    else
    {
        *LoopbackEnable = FALSE;    /* pseudo port does not have loop back mode */
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_PortSetLoopbackMode
 * Description   : Function for setting the loopback mode of a port
 * implements Netc_EthSwt_Ip_PortSetLoopbackMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_PortSetLoopbackMode( uint8 SwitchIdx,
                                                   uint8 SwitchPortIdx,
                                                   boolean LoopbackEnable
                                                  )
{
    Std_ReturnType status = E_NOT_OK;
    uint32 portCommandConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS);
#endif

    (void)SwitchIdx;
    if (SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_57();
        portCommandConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG
                            & ~SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK;

        /* Configure the loopback mode in the PM0_COMMAND_CONFIG */
        if (TRUE == LoopbackEnable)
        {
            portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK;
        }

        /* Write the PM0_COMMAND_CONFIG with the computed value */
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG = portCommandConfig;
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM1_COMMAND_CONFIG = portCommandConfig;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_57();

        status = E_OK;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetPortMacLayerDuplexMode
 * Description   : Function for enabling or disabling Time Gate Scheduling on a switch port.
 * implements Netc_EthSwt_Ip_SetPortMacLayerDuplexMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetPortMacLayerDuplexMode( uint8 SwitchIdx, uint8 SwitchPortIdx,
                                                         Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                        )
{
    Std_ReturnType status = E_OK;
    uint32 interfaceModeConfig = 0UL;

    (void) SwitchIdx;
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_58();

        interfaceModeConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE;

        /* Full duplex is 0 in HD field */
        if(EthSwtPortMacLayerDuplexMode == NETC_ETHSWT_PORT_FULL_DUPLEX)
        {
            interfaceModeConfig &= ~SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_MASK;
        }
        else /* ETHTRCV_DUPLEX_MODE_HALF */
        {
            switch ((interfaceModeConfig & SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_MASK) >> SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_SHIFT)
            {
                case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE:
                case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE:
                case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE:
                    interfaceModeConfig |= SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_MASK;
                    break;
                default:
                    status = E_NOT_OK;
                    break;
            }
        }

        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE = interfaceModeConfig;
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM1_IF_MODE = interfaceModeConfig;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_58();

    }

    return status;
}


static inline Std_ReturnType Netc_EthSwt_Ip_MacPortConfigSetInterface( Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort,
                                                                Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType,
                                                                EthTrcv_BaudRateType EthSwtPortMacLayerSpeed,
                                                                Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                               )
{
    Std_ReturnType status = E_OK;
    uint32 interfaceModeConfig = 0UL;
    uint32 shapingPSpeedConfig = 0UL; /* used for shaping of the port */

    /* Set the interface type */
    switch (EthSwtPortPhysicalLayerType)
    {
        case NETC_ETHSWT_MII_MODE:
        case NETC_ETHSWT_RMII_MODE:
            interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE((NETC_ETHSWT_RMII_MODE == EthSwtPortPhysicalLayerType) ? SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE : SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE);
            status = Netc_EthSwt_Ip_SetPortSpeed_MII_RMII_Mode(EthSwtPortMacLayerSpeed, &interfaceModeConfig, &shapingPSpeedConfig);
            break;
        case NETC_ETHSWT_RGMII_MODE:
            interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE(SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE);
            status = Netc_EthSwt_Ip_SetPortSpeed_RGMII_Mode(EthSwtPortMacLayerSpeed, &interfaceModeConfig, &shapingPSpeedConfig);
            break;
        case NETC_ETHSWT_SGMII_MODE:
            interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE(SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_SGMII_MODE);
            status = Netc_EthSwt_Ip_SetPortSpeed_SGMII_Mode(EthSwtPortMacLayerSpeed, &interfaceModeConfig, &shapingPSpeedConfig);
            break;
        default:
            status = E_NOT_OK;
            break;
    }

    if (status == E_OK)
    {
        /* Write the interface mode configuration in the register */
        Netc_EthSwt_Ip_PortBaseTable[SwitchIdxSwitchPort.SwitchPortIdx]->PM0_IF_MODE = interfaceModeConfig;
        Netc_EthSwt_Ip_PortBaseTable[SwitchIdxSwitchPort.SwitchPortIdx]->PM1_IF_MODE = interfaceModeConfig;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(shapingPSpeedConfig);

        status = Netc_EthSwt_Ip_SetPortMacLayerDuplexMode(SwitchIdxSwitchPort.SwitchIdx, SwitchIdxSwitchPort.SwitchPortIdx, EthSwtPortMacLayerDuplexMode);
    }

    return status;
}

static Std_ReturnType Netc_EthSwt_Ip_MacPortConfig( Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort,
                                                    Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType,
                                                    EthTrcv_BaudRateType EthSwtPortMacLayerSpeed,
                                                    Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                  )
{
    Std_ReturnType status = E_OK;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdxSwitchPort.SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif


    if(SwitchIdxSwitchPort.SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        status = Netc_EthSwt_Ip_MacPortConfigSetInterface(SwitchIdxSwitchPort, EthSwtPortPhysicalLayerType, EthSwtPortMacLayerSpeed, EthSwtPortMacLayerDuplexMode);
    }
    else
    {
    /* pseudo port */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        switch(EthSwtPortMacLayerSpeed)
        {
            case ETHTRCV_BAUD_RATE_10MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS);
                break;
            case ETHTRCV_BAUD_RATE_100MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS);
                break;
            case ETHTRCV_BAUD_RATE_1000MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS);
                break;
            case ETHTRCV_BAUD_RATE_2500MBIT:
                Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_2500MBITS);
                break;
            default:
                status = E_NOT_OK;
                break;
        }
    }

    return status;
}

/* inline function for configuring BPDVR */
static inline void Netc_EthSwt_Ip_ConfigBridgePortDefaultVlanReg(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    uint32 bridgePortDefaultVlan = 0UL;

    /* Bridge VLAN port defaults, bits in this section use reverse logic, TRUE==0 */
    if(TRUE != port->iPort->EthSwtDropDoubleTagged)
    {
        bridgePortDefaultVlan  |= SW_PORT0_BPDVR_RXTAGA(NETC_ETHSWT_IP_RXTAGA_ACCEPT_DOUBLE_TAGGED);
    }
    if(TRUE != port->iPort->EthSwtPortIngressDropUntagged)
    {
        bridgePortDefaultVlan  |= SW_PORT0_BPDVR_RXTAGA(NETC_ETHSWT_IP_RXTAGA_ACCEPT_UNTAGGED);
    }
    if(TRUE != port->iPort->EthSwtPortIngressDropSingleTagged)
    {
        bridgePortDefaultVlan  |= SW_PORT0_BPDVR_RXTAGA(NETC_ETHSWT_IP_RXTAGA_ACCEPT_SINGLE_TAGGED);
    }
    if(TRUE != port->iPort->EthSwtPortIngressDropPriorityTagged)
    {
        bridgePortDefaultVlan  |= SW_PORT0_BPDVR_RXTAGA(NETC_ETHSWT_IP_RXTAGA_ACCEPT_PRIO_TAGGED);
    }
    if(TRUE != port->iPort->vlanEnable)
    {
        bridgePortDefaultVlan  |= SW_PORT0_BPDVR_RXVAM(1);
    }

    if(TRUE == port->iPort->SentUntaggedFrames)
    {
        bridgePortDefaultVlan  |= SW_PORT0_BPDVR_TXTAGA(1);    /* Delete outer VLAN tag */
    }
    /* default vlan id */
    bridgePortDefaultVlan |= SW_PORT0_BPDVR_VID(port->iPort->EthSwtPortIngressDefaultVlan);
    /* default priority */
    bridgePortDefaultVlan |= SW_PORT0_BPDVR_PCP(port->iPort->EthSwtPortIngressDefaultPriority);
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->BPDVR = bridgePortDefaultVlan;
}

/* inline function for configuring credit base shaper registers */
static inline void Netc_EthSwt_Ip_ConfigCreditBaseShaperReg(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    uint8 shapingClass;
    uint32 localPtcTmSDUR;

    if(port->ePort->portShaper != NULL_PTR)
    {
        for(shapingClass = 0U; shapingClass < NETC_ETHSWT_IP_NUM_SHAPING_CLASS; shapingClass++)
        {
            /* Coonfigure the maximum frame size per shaping class, Max 2000 */
            localPtcTmSDUR = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[shapingClass].PTCTMSDUR;
            localPtcTmSDUR &= ~SW_PORT0_PTCTMSDUR_MAXSDU_MASK;
            localPtcTmSDUR |= SW_PORT0_PTCTMSDUR_MAXSDU(port->ePort->portShaper[shapingClass]->EthSwtPortMaxSizedFrame);
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[shapingClass].PTCTMSDUR = localPtcTmSDUR;

            Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[shapingClass].PTCCBSR0 = SW_PORT0_PTCCBSR0_CBSE(port->ePort->portShaper[shapingClass]->EthSwtPortEgressCBShaperEnable ? 1U : 0U)
                                                                                            | SW_PORT0_PTCCBSR0_BW(port->ePort->portShaper[shapingClass]->EthSwtPortEgressCBShaperBandwidth);
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[shapingClass].PTCCBSR1 = SW_PORT0_PTCCBSR1_HI_CREDIT(port->ePort->portShaper[shapingClass]->EthSwtPortEgressHiCredit);
        }
    }
}

/* inline function for configuring egress frame preemption registers */
static inline void Netc_EthSwt_Ip_ConfigEgressPreemptionReg(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    /* The pseudoport does not have the following options */
    if (SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        if(port->ePort->enablePreemption == (boolean)TRUE)
        {
#if defined(ERR_IPV_NETC_051025)
    #if (STD_ON == ERR_IPV_NETC_051025)
            /* Default is 10, for 10ms, for timer @400MHz. But if errata applies, timer is at @330MHz.
               To achieve 10ms, replace 10 with 330MHz/400MHz * 10 = 8.25, aproximated to 8 */
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->MAC_MERGE_MMCSR |= SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT(8U);
    #endif
#endif
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->MAC_MERGE_MMCSR |= SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME(1U); /* Set ME bits to 1 to enable preemption on any byte boundary. */
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PFPCR = port->ePort->preemptionTCprofiles;
        }
        else
        {
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->MAC_MERGE_MMCSR &= ~SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME(1U); /* Set ME bits to 0 to disable preemption. */
        }
    }
}

/* inline function for configuring PM0_COMMAND register */
static inline Std_ReturnType Netc_EthSwt_Ip_ConfigPMCommandReg(Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort, const Netc_EthSwt_Ip_PortType *port)
{
    Std_ReturnType status = E_OK;
    uint32 portCommandConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdxSwitchPort.SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    /* Start the PM0_COMMAND_CONFIG value with the TX padding option */
    portCommandConfig = SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_MASK;

    /* Construct several values to be used later based on whether the port is enabled or not */
    if (TRUE == port->EthSwtPortMacLayerPortEnable)
    {
        /* The pseudoport does not have the PMa_COMMAND_CONFIG register */
        if (SwitchIdxSwitchPort.SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
        {
            portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK | SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK;
        }

        /* Enable Rx and Tx Path for port */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->POR &= ~(SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK);
    }
    else
    {
        /* Disable the port in POR register */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->POR |= SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK;
    }

    /* The pseudoport does not have the following options */
    if (SwitchIdxSwitchPort.SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        if(TRUE == port->EthSwtPortEnableMagicPacketDetection)
        {
            portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG(1U);
        }

        /* Configure the loopback mode in the PM0_COMMAND_CONFIG */
        if (TRUE == port->EthSwtPortLoopbackEnable)
        {
            portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK;
        }

        /* set TS_MODE bit if is needed, by default TS_MODE is 0*/
        if(TRUE == port->EthSwtEnableFreeRunningTimer)
        {
            portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE(1);
        }

        /* Write the PMa_COMMAND_CONFIG with the computed value */
        Netc_EthSwt_Ip_PortBaseTable[SwitchIdxSwitchPort.SwitchPortIdx]->PM0_COMMAND_CONFIG = portCommandConfig;
        Netc_EthSwt_Ip_PortBaseTable[SwitchIdxSwitchPort.SwitchPortIdx]->PM1_COMMAND_CONFIG = portCommandConfig;

#if(NETC_ETHSWT_IP_CONFIG_LINK_PROTOCOL == STD_ON)
        /* Config link protocol for mac ports */
        Netc_EthSwt_Ip_ConfigLinkProtocol(SwitchIdxSwitchPort.SwitchIdx, SwitchIdxSwitchPort.SwitchPortIdx, port->EthSwtPortPhysicalLayerType);
#endif
    }

    /* Configure the interface mode, the speed and the duplex mode */
    status |= Netc_EthSwt_Ip_MacPortConfig(SwitchIdxSwitchPort, port->EthSwtPortPhysicalLayerType,
                                           port->EthSwtPortMacLayerSpeed, port->EthSwtPortMacLayerDuplexMode);

    return status;
}

static inline void Netc_EthSwt_Ip_SetIngressCutThroughPortx(uint8 SwitchPortIdx)
{
    if( (0U == SwitchPortIdx) || (1U == SwitchPortIdx) )
    {
        /* Set Ingress Cut-through frame State*/
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCTFCR |= SW_PORT0_PCTFCR_ICTS(1U);
    }
}

static inline void Netc_EthSwt_Ip_SetEgressCutThroughPortx(uint8 SwitchPortIdx)
{
    if( (0U == SwitchPortIdx) || (1U == SwitchPortIdx) )
    {
        /* Set Egress Cut-through frame State*/
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCTFCR |= SW_PORT0_PCTFCR_ECTS(1U);
    }
}

static inline void Netc_EthSwt_Ip_InitPort_ConfigIngressEgressCutThroughSettings(Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort, const Netc_EthSwt_Ip_PortType *port)
{
    /* Configure the ingress/egress cut through settings */
    if (TRUE == (port->ePort->portEgressAllowCutThroughFrames) )
    {
        Netc_EthSwt_Ip_SetEgressCutThroughPortx(SwitchIdxSwitchPort.SwitchPortIdx);
    }

    if (TRUE == (port->iPort->portIngressAllowCutThroughFrames) )
    {
        Netc_EthSwt_Ip_SetIngressCutThroughPortx(SwitchIdxSwitchPort.SwitchPortIdx);
    }
}

static inline Std_ReturnType Netc_EthSwt_Ip_ConfigPortScheduler (uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    /* Configure the number of WBFS Queues and Strict Priority queues, by assigning the Traffic Classes to a specific scheduler input. */
    const Netc_EthSwt_Ip_PortSchedulerType *SchedulerType = port->ePort->portScheduler;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    Std_ReturnType status = E_OK;
    uint32 MatchedEntries;

    if(SchedulerType != NULL_PTR)
    {
        /* Entry ID value represents the ETM Class Scheduler instance and each entry corresponds
        to a class queue scheduler on given switch port (there is one scheduler per port) */
        CBDRStatus = Netc_EthSwt_Ip_UpdateEgressSchedulerTableEntry(0U, SwitchPortIdx, &MatchedEntries, SchedulerType);
        status = ((CBDRStatus == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) ? E_OK : E_NOT_OK);
    }
    else
    {
        /* In case there is no configuration for Port Scheduler mapping profile, the variables declared at
           the begining of the function will not be used, thus it will be generated an warning at compilation. */
        (void)CBDRStatus;
        (void)MatchedEntries;
    }

    return status;
}

static Std_ReturnType Netc_EthSwt_Ip_ConfigPortAdvancedFeatures(Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort, const Netc_EthSwt_Ip_PortType *port)
{
    Std_ReturnType status = E_OK;

    /* Configure egress frame preemption. */
    Netc_EthSwt_Ip_ConfigEgressPreemptionReg(SwitchIdxSwitchPort.SwitchPortIdx, port);

    /* Configure the credit base shaper. */
    Netc_EthSwt_Ip_ConfigCreditBaseShaperReg(SwitchIdxSwitchPort.SwitchPortIdx, port);

    /* Configure the scheduler for a specific port. */
    status |= Netc_EthSwt_Ip_ConfigPortScheduler(SwitchIdxSwitchPort.SwitchPortIdx, port);

    /* Configure the Ingress Stream look up for a specific port. */
    Netc_EthSwt_Ip_PortConfigIngresStreamLookUp(SwitchIdxSwitchPort.SwitchPortIdx, port);

    return status;
}

static Std_ReturnType Netc_EthSwt_Ip_InitPort(Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort, const Netc_EthSwt_Ip_PortType *port)
{
    Std_ReturnType status = E_OK;
    uint32 bridgePortConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdxSwitchPort.SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchIdxSwitchPort.SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    /* Port QOS mode */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PQOSMR = SW_PORT0_PQOSMR_VS(1U)
        | SW_PORT0_PQOSMR_VE(port->iPort->vlanEnable?1U:0U)
        | SW_PORT0_PQOSMR_DIPV(port->iPort->vlanDefaultIpv)
        | SW_PORT0_PQOSMR_DDR(port->iPort->vlanDefaultDr)
#if defined(ERR_IPV_NETC_051649)
    #if (STD_ON != ERR_IPV_NETC_051649)
        | SW_PORT0_PQOSMR_VQMP(port->iPort->vlanMappingProfile)
    #endif /* If ERR051649 is applicable, then only the VLAN to IPV mapping profile 0 shall be used. */
#endif
        | SW_PORT0_PQOSMR_QVMP(port->ePort->vlanMappingProfile);

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->PPCPDEIMR = SW_PORT0_PPCPDEIMR_IPCPMPV(port->iPort->vlanEnableIngressPcpToPcpMapping?1U:0U)
        | SW_PORT0_PPCPDEIMR_IPCPMP(port->iPort->vlanIngressPcpToPcpProfile)
        | SW_PORT0_PPCPDEIMR_EPCPMPV(port->ePort->vlanEnableEgressPcpToPcpMapping?1U:0U)
        | SW_PORT0_PPCPDEIMR_EPCPMP(port->ePort->vlanEgressPcpToPcpProfile)
        | SW_PORT0_PPCPDEIMR_DRME(port->ePort->updateEgressDr?1U:0U)
        | SW_PORT0_PPCPDEIMR_DR0DEI((*port->ePort->vlanDrToDei)[0U])
        | SW_PORT0_PPCPDEIMR_DR1DEI((*port->ePort->vlanDrToDei)[1U])
        | SW_PORT0_PPCPDEIMR_DR2DEI((*port->ePort->vlanDrToDei)[2U])
        | SW_PORT0_PPCPDEIMR_DR3DEI((*port->ePort->vlanDrToDei)[3U]);

    /* Bridge Port Default Vlan register configuration */
    Netc_EthSwt_Ip_ConfigBridgePortDefaultVlanReg(SwitchIdxSwitchPort.SwitchPortIdx, port);

    /* PM0_COMMAND_CONFIG configuration */
    status = Netc_EthSwt_Ip_ConfigPMCommandReg(SwitchIdxSwitchPort, port);

    Netc_EthSwt_Ip_InitPort_ConfigIngressEgressCutThroughSettings(SwitchIdxSwitchPort, port);

    /* Bridge port configuration */
    if(port->EthSwtPortDisallowMacStationMove)
    {
        bridgePortConfig = SW_PORT1_BPCR_STAMVD(1U);
    }

    bridgePortConfig |= SW_PORT0_BPCR_DYN_LIMIT(port->EthSwtPortMaxDynamicEntries);

    /* Configure the pruning setting for each port */
    if (FALSE == port->EthSwtPortPruningEnable)
    {
        bridgePortConfig |= SW_PORT0_BPCR_SRCPRND_MASK;
    }

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchIdxSwitchPort.SwitchPortIdx]->BPCR = bridgePortConfig;

    status |= Netc_EthSwt_Ip_ConfigPortAdvancedFeatures(SwitchIdxSwitchPort, port);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigureEgressFramePreemption
 * Description   : Function for configuring the frame preemption feature on egress
 * implements Netc_EthSwt_Ip_ConfigureEgressFramePreemption_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_ConfigureEgressFramePreemption(uint8 SwitchIdx, const uint8 SwitchPortIdx, const boolean TrafficClass[8U])
{
    uint8 tcIndex;
    uint32 localPFPCR = 0U;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS);
#endif
    (void) SwitchIdx;

    for(tcIndex = 0U; tcIndex < NETC_ETHSWT_IP_NUM_SHAPING_CLASS; tcIndex++)
    {
        localPFPCR |= ((uint32)(TrafficClass[tcIndex] ? 1U : 0U)) << tcIndex;
    }


    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_62();
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PFPCR = localPFPCR;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_62();

    return E_OK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EnableEgressFramePreemption
 * Description   : Function for enabling/disabling the frame preemption feature on egress
 * implements Netc_EthSwt_Ip_EnableEgressFramePreemption_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_EnableEgressFramePreemption(uint8 SwitchIdx, const uint8 SwitchPortIdx, const boolean Enable)
{
    Std_ReturnType status = E_OK;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_63();

        if(Enable == (boolean)TRUE)
        {
#if defined(ERR_IPV_NETC_051025)
    #if (STD_ON == ERR_IPV_NETC_051025)
            /* Default is 10, for 10ms, for timer @400MHz. But if errata applies, timer is at @330MHz.
               To achieve 10ms, replace 10 with 330MHz/400MHz * 10 = 8.25, aproximated to 8 */
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->MAC_MERGE_MMCSR |= SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT(8U);
    #endif
#endif
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->MAC_MERGE_MMCSR |= SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME(1U); /* Set ME bits to 1 to enable preemption on any byte boundary. */
        }
        else
        {
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->MAC_MERGE_MMCSR &= ~SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME(1U); /* Set ME bits to 0 to disable preemption. */
        }
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_63();
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigureCreditBasedShaper
 * Description   : function for configuring the CBS
 * implements Netc_EthSwt_Ip_ConfigureCreditBasedShaper_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_ConfigureCreditBasedShaper(uint8 SwitchIdx, const uint8 SwitchPortIdx, const uint8 TrafficClass, const uint64 idleSlope)
{
    Std_ReturnType status = E_OK;
    uint64 portTxRate;
    EthTrcv_BaudRateType baudRate = ETHTRCV_BAUD_RATE_10MBIT;
    uint64 largeBandwidth;
    uint32 bandwidth;
    uint64 largeEgressHiCredit;
    uint32 egressHiCredit;
    uint32 Netc_EthSwt_Ip_MaxFrameSize;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    /* A Slope of zero would cause a bandwidth of zero and this would cause a buffer leak */
    DevAssert(idleSlope > 0U);
    DevAssert(TrafficClass < NETC_ETHSWT_IP_NUM_SHAPING_CLASS);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        status = Netc_EthSwt_Ip_GetPortSpeed( SwitchIdx, SwitchPortIdx, &baudRate);
        status |= Netc_EthSwt_Ip_PortRateEnumToRate(baudRate, &portTxRate);
    }
    else
    {
        portTxRate = 2000000UL;
    };

    largeBandwidth = idleSlope / (portTxRate / 10000UL); /* bandwidth is in % and 100th precision, so need to divide by 10000 */
    if( largeBandwidth < 100UL )
    {
        largeBandwidth = 100UL; /* Min of 1% bandwidth, otherwise frames would get stuck in the switch */
    }
    /* Round and convert to uint32 */
    bandwidth = (uint32)(largeBandwidth/100UL);
    bandwidth = ((uint64)((((uint64)bandwidth)*100UL)+50UL)>largeBandwidth)?bandwidth:(bandwidth+1UL);

    /* High Credit in credits
           hiCredit (bits) = maxSizedFrame * (idleSlope/portTxRate)
           bandwidth = idleSlope / portTxRate
           Then:
               hiCredit (bits) = maxSizedFrame * bandwidth

           hiCredit (credits) = hiCredit (bits) * (ClockFrequency/portRate)
           Then:
               hiCredit (credits) = maxSizedFrame * bandwidth * (ClockFrequency / portRate)
    */
    Netc_EthSwt_Ip_MaxFrameSize = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCTMSDUR;
    largeEgressHiCredit = largeBandwidth * Netc_EthSwt_Ip_MaxFrameSize * (Netc_EthSwt_Ip_NetcClockFrequency / (portTxRate)) / 100UL; /* Bandwidth is in %, need to div by 100 */
    /* Round and convert to uint32 */
    egressHiCredit = (uint32)(largeEgressHiCredit/100UL);
    egressHiCredit = (((egressHiCredit*100UL)+50UL)>egressHiCredit)?egressHiCredit:(egressHiCredit+1UL);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_05();
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 &= ~SW_PORT0_PTCCBSR0_BW_MASK;
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 |= SW_PORT0_PTCCBSR0_BW(bandwidth);
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR1 = SW_PORT0_PTCCBSR1_HI_CREDIT(egressHiCredit);
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_05();

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EnableCreditBasedShaper
 * Description   : function for enabling a CBS
 * implements Netc_EthSwt_Ip_EnableCreditBasedShaper_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_EnableCreditBasedShaper(uint8 SwitchIdx, const uint8 SwitchPortIdx, const uint8 TrafficClass, const boolean Enable)
{
    Std_ReturnType status = E_OK;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(TrafficClass < NETC_ETHSWT_IP_NUM_SHAPING_CLASS);
#endif

    (void)SwitchIdx;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_10();
    /* clear the bit first */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 &= ~SW_PORT0_PTCCBSR0_CBSE_MASK;
    /* write the bit */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 |= SW_PORT0_PTCCBSR0_CBSE((TRUE==Enable)?1U:0U);
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_10();

    return status;
}


/* inline function for configuring VlanIpvDr2PcpProfile */
static inline void Netc_EthSwt_Ip_ConfigVlanIpvDr2PcpProfile(const uint8 *IndexProfile, const Netc_EthSwt_Ip_ConfigType * Config)
{
    /* QOS to PCP mapping is done trough 4 for registers. */
    if(NULL_PTR != Config->vlanIpvDr2PcpProfile)
    {

        /* Register 0 --> IPV 0 - 1 and DR 0-3 */
        IP_NETC__SW0_BASE->MAP_PCP[(*IndexProfile)].QOSVLANMPR[0] |= NETC_F2_QOSVLANMPR_IPV0_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][0][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV0_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][0][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV0_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][0][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV0_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][0][3]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV1_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][1][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV1_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][1][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV1_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][1][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV1_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][1][3]) ;

        /* Register 1 --> IPV 2 - 3 and DR 0-3 */
        IP_NETC__SW0_BASE->MAP_PCP[(*IndexProfile)].QOSVLANMPR[1] |= NETC_F2_QOSVLANMPR_IPV2_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][2][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV2_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][2][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV2_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][2][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV2_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][2][3]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV3_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][3][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV3_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][3][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV3_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][3][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV3_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][3][3]) ;
        /* Register 2 --> IPV 4 - 5 and DR 0-3 */
        IP_NETC__SW0_BASE->MAP_PCP[(*IndexProfile)].QOSVLANMPR[2] |= NETC_F2_QOSVLANMPR_IPV4_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][4][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV4_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][4][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV4_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][4][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV4_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][4][3]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV5_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][5][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV5_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][5][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV5_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][5][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV5_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][5][3]) ;
        /* Register 3 --> IPV 6 - 7 and DR 0-3 */
        IP_NETC__SW0_BASE->MAP_PCP[(*IndexProfile)].QOSVLANMPR[3] |= NETC_F2_QOSVLANMPR_IPV6_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][6][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV6_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][6][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV6_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][6][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV6_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][6][3]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV7_DR0((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][7][0]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV7_DR1((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][7][1]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV7_DR2((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][7][2]) | \
                                                                     NETC_F2_QOSVLANMPR_IPV7_DR3((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][7][3]) ;
    }
}

static inline void Netc_EthSwt_Ip_InitMappingProfilePartTwo(uint8 IndexProfile, const Netc_EthSwt_Ip_ConfigType * Config)
{
    /* As per ERR051649, VLANIPVMPR and VLANDRMPR accept only the instance 0 of all profile mappings, due to the decoding of instance 1 is not corect. */

    /* Configure PCP-DEI to IPV mapping profiles. */
#if defined(ERR_IPV_NETC_051649)
    #if (STD_ON == ERR_IPV_NETC_051649)
    if((NULL_PTR != Config->vlanPcpDei2IpvProfile) && (0U == IndexProfile))
    {
    #endif
#else
    if(NULL_PTR != Config->vlanPcpDei2IpvProfile)
    {
#endif

        IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANIPVMPR0 |= NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][0U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][1U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][2U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][3U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][4U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][5U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][6U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][7U]) ;

        IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANIPVMPR1 |= NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][8U])   | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][9U])   | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][10U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][11U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][12U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][13U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][14U]) | \
                                                                      NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][15U]) ;
    }

    /* Configure PCP-DEI to DR mapping profiles. */
#if defined(ERR_IPV_NETC_051649)
    #if (STD_ON == ERR_IPV_NETC_051649)
    if((Config->vlanPcpDei2DrProfile != NULL_PTR) && (0U == IndexProfile))
    {
    #endif
#else
    if(Config->vlanPcpDei2DrProfile != NULL_PTR)
    {
#endif
        IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANDRMPR |= NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0((*(Config->vlanPcpDei2DrProfile))[IndexProfile][0U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1((*(Config->vlanPcpDei2DrProfile))[IndexProfile][1U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2((*(Config->vlanPcpDei2DrProfile))[IndexProfile][2U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3((*(Config->vlanPcpDei2DrProfile))[IndexProfile][3U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4((*(Config->vlanPcpDei2DrProfile))[IndexProfile][4U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5((*(Config->vlanPcpDei2DrProfile))[IndexProfile][5U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6((*(Config->vlanPcpDei2DrProfile))[IndexProfile][6U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7((*(Config->vlanPcpDei2DrProfile))[IndexProfile][7U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8((*(Config->vlanPcpDei2DrProfile))[IndexProfile][8U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9((*(Config->vlanPcpDei2DrProfile))[IndexProfile][9U])   | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10((*(Config->vlanPcpDei2DrProfile))[IndexProfile][10U]) | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11((*(Config->vlanPcpDei2DrProfile))[IndexProfile][11U]) | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12((*(Config->vlanPcpDei2DrProfile))[IndexProfile][12U]) | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13((*(Config->vlanPcpDei2DrProfile))[IndexProfile][13U]) | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14((*(Config->vlanPcpDei2DrProfile))[IndexProfile][14U]) | \
                                                                    NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15((*(Config->vlanPcpDei2DrProfile))[IndexProfile][15U]) ;
    }

    /* Configure PCP to PCP mapping profiles. */
    if(NULL_PTR != Config->vlanPcp2PcpProfile)
    {
        IP_NETC__SW0_BASE->PCP2PCPMPR[IndexProfile] |= NETC_F2_PCP2PCPMPR_PCP0((*(Config->vlanPcp2PcpProfile))[IndexProfile][0U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP1((*(Config->vlanPcp2PcpProfile))[IndexProfile][1U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP2((*(Config->vlanPcp2PcpProfile))[IndexProfile][2U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP3((*(Config->vlanPcp2PcpProfile))[IndexProfile][3U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP4((*(Config->vlanPcp2PcpProfile))[IndexProfile][4U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP5((*(Config->vlanPcp2PcpProfile))[IndexProfile][5U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP6((*(Config->vlanPcp2PcpProfile))[IndexProfile][6U]) | \
                                                       NETC_F2_PCP2PCPMPR_PCP7((*(Config->vlanPcp2PcpProfile))[IndexProfile][7U]) ;
    }
}

/* inline function for initializing Mapping profile */
static inline void Netc_EthSwt_Ip_InitMappingProfile(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint8 IndexProfile;
    /* Initialize the clasification mapping */
    for (IndexProfile=0U; IndexProfile < NETC_ETHSWT_IP_NUMBER_OF_PROFILES; IndexProfile++)
    {
        /* Initializing the different arrays */
        IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANIPVMPR0 = 0U;
        IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANIPVMPR1 = 0U;
        IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANDRMPR = 0U;
        IP_NETC__SW0_BASE->PCP2PCPMPR[IndexProfile] = 0U;
        IP_NETC__SW0_BASE->MAP_PCP[IndexProfile].QOSVLANMPR[0] = 0U;
        IP_NETC__SW0_BASE->MAP_PCP[IndexProfile].QOSVLANMPR[1] = 0U;
        IP_NETC__SW0_BASE->MAP_PCP[IndexProfile].QOSVLANMPR[2] = 0U;
        IP_NETC__SW0_BASE->MAP_PCP[IndexProfile].QOSVLANMPR[3] = 0U;

        Netc_EthSwt_Ip_InitMappingProfilePartTwo(IndexProfile, Config);

        Netc_EthSwt_Ip_ConfigVlanIpvDr2PcpProfile(&IndexProfile, Config);
    }
}

/* inline function for initializing 1588 timer */
static inline void Netc_EthSwt_Ip_InitTimer1588(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint16 TimerClkPeriod;
    float64 ClkAddendData;
    uint32 TimerClkAddend;
    float64 TimerClkAddendRaw;
    uint32 TimerClkAddendRawInt;

    if (Config->Timer1588ClkSrc == ETHSWT_EXTERNAL_REFERENCE_CLOCK)
    {
        TimerOriginalRefClk = Config->netcExternalClockFrequency;
        TimerRefClk = Config->netcExternalClockFrequency;
        Netc_EthSwt_Ip_TimerBase->TMR_CTRL &= ~TMR0_BASE_TMR_CTRL_CK_SEL(1U);         /* select the external 200MHz clock for 1588 timer */
    }
    else if (Config->Timer1588ClkSrc == ETHSWT_MODULE_REFERENCE_CLOCK)
    {
        TimerOriginalRefClk = Config->netcClockFrequency;
        TimerRefClk = Config->netcClockFrequency;
        Netc_EthSwt_Ip_TimerBase->TMR_CTRL |= TMR0_BASE_TMR_CTRL_CK_SEL(1U);          /* select NETC system clock (default setting) for 1588 timer */
    }
    else    /* reference clock is disabled, will not use 1588 timer */
    {
        TimerOriginalRefClk = 0x0UL;
        TimerRefClk = 0x0UL;
    }

    /* config and eanble the 1588 timer */
    if (TimerOriginalRefClk != 0x0UL)
    {
        TimerClkPeriod = (uint16)(1000000000UL / TimerRefClk);                             /* the integer portion of timer clock period (1/f) */

        ClkAddendData = (((float64)1000000000UL) / ((float64)TimerRefClk)) - ((float64)TimerClkPeriod);
        TimerClkAddendRaw = ((float64)0x100000000UL) * ((float64)ClkAddendData);
        TimerClkAddendRawInt = (uint32)TimerClkAddendRaw;
        TimerClkAddend = TimerClkAddendRawInt + ((TimerClkAddendRaw > (float64)TimerClkAddendRawInt) ? 1U : 0U);  /* the fractional part of the timer clock period. */

        /* Timer addend register holds the fractional part of the timer clock period */
        Netc_EthSwt_Ip_TimerBase->TMR_ADD = TMR0_BASE_TMR_ADD_ADDEND(TimerClkAddend);
        /* clear CLK_PERIOD data field first */
        Netc_EthSwt_Ip_TimerBase->TMR_CTRL &= ~TMR0_BASE_TMR_CTRL_TCLK_PERIOD(0x3FF);
        Netc_EthSwt_Ip_TimerBase->TMR_CTRL |= TMR0_BASE_TMR_CTRL_TCLK_PERIOD(TimerClkPeriod);
        /* Enable timer */
        Netc_EthSwt_Ip_TimerBase->TMR_CTRL |= TMR0_BASE_TMR_CTRL_TE(1U);
    }

}

/* inline function for initializing time gate scheduling table entries data during switch init */
static inline void Netc_EthSwt_Ip_InitTimeGateSchedulingTableEntryData(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint8 PortIndex;
    uint8 GateControlListIdx;

    for (PortIndex = 0U; PortIndex < NETC_ETHSWT_IP_NUMBER_OF_PORTS; PortIndex++)
    {
        if ((*((*(Config)).port))[PortIndex].ePort->portTimeAwareShaperEnable == TRUE)
        {
            /* set the flag for ports */
            PortTimeAwareShaperEnabled[PortIndex] = TRUE;

            /* write register PTGSATOR. [Ricky}: not supported for now. follow up ticket needed. */
            /* TODO: Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIndex]->RESERVED_7 should be equal to (*((*(Config)).port))[PortIndex].ePort->portTimeGateSchedulingAdvanceTimeOffsetReg; */

            /* Fill in the data structure for time gate scheduling */
            TimeGateSchedulingEntryData[PortIndex].TimeGateSchedulingTable_EID = PortIndex;
            TimeGateSchedulingEntryData[PortIndex].AdminBaseTime = (*((*(Config)).port))[PortIndex].ePort->portEgressAdminBaseTime;
            TimeGateSchedulingEntryData[PortIndex].AdminCycleTime = (*((*(Config)).port))[PortIndex].ePort->portEgressAdminCycleTime;
            TimeGateSchedulingEntryData[PortIndex].AdminCycleTimeExt = (*((*(Config)).port))[PortIndex].ePort->portEgressAdminCycleTimeExt;
#if (NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES > 0U)
            TimeGateSchedulingEntryData[PortIndex].AdminControlListLength = (*((*(Config)).port))[PortIndex].ePort->numberOfGateControlListEntries;
            for (GateControlListIdx = 0U; GateControlListIdx < TimeGateSchedulingEntryData[PortIndex].AdminControlListLength; GateControlListIdx++)
            {
                TimeGateSchedulingEntryData[PortIndex].GateEntryAdminControlListData[GateControlListIdx].AdminTimeInterval = (*((*((*(Config)).port))[PortIndex].ePort->TimeGateControlListEntries))[GateControlListIdx].AdminTimeInterval;
                TimeGateSchedulingEntryData[PortIndex].GateEntryAdminControlListData[GateControlListIdx].AdminTrafficClassGateStates = (*((*((*(Config)).port))[PortIndex].ePort->TimeGateControlListEntries))[GateControlListIdx].AdminTrafficClassGateStates;
                TimeGateSchedulingEntryData[PortIndex].GateEntryAdminControlListData[GateControlListIdx].AdminGateOperationType = (*((*((*(Config)).port))[PortIndex].ePort->TimeGateControlListEntries))[GateControlListIdx].AdminGateOperationType;
            }
#endif
        }
    }
}

#if defined(ERR_IPV_NETC_E051130)
    #if (STD_ON == ERR_IPV_NETC_E051130)
/*  Workaround for ERR051130:
    Egress time gate scheduling can get corrupted when functional level reset is applied or when time gating is disabled
*/
/* Added 2 fake time gate control list entries for clearing the internal context for time gate scheduling feature */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_InitTimeGateSchedulingFeature(uint8 SwitchIdx, uint8 SwitchPortIdx)
{
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    volatile uint64 CurrentTime = 0;
    uint8 EntryIdx;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    /* fill in struct Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType */
    TimeGateSchedulingEntryData[0U].TimeGateSchedulingTable_EID = SwitchPortIdx;
    TimeGateSchedulingEntryData[0U].AdminCycleTime = 4000000U;           /* it should be greater than the sum of time interval */
    TimeGateSchedulingEntryData[0U].AdminCycleTimeExt = 100000U;
    TimeGateSchedulingEntryData[0U].AdminControlListLength = 2U;         /* 2 entries */

    /* get the current time from 1588 timer */
    CurrentTime = Netc_EthSwt_Ip_TimerBase->TMR_CUR_TIME_L;      /* should read the Lower register first */
    CurrentTime |= ((uint64)(Netc_EthSwt_Ip_TimerBase->TMR_CUR_TIME_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;
    TimeGateSchedulingEntryData[0U].AdminBaseTime = CurrentTime;        /* set base time to current time */

#if (NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES > 0U)
    /* fill in gate control list entries data */
    for (EntryIdx = 0U; EntryIdx < TimeGateSchedulingEntryData[0U].AdminControlListLength; EntryIdx++)
    {
        TimeGateSchedulingEntryData[0U].GateEntryAdminControlListData[EntryIdx].AdminTimeInterval = 2000000U;        /* the value is equal to transmit 128bytes + 20 bytes (header) frame with port speed 10M */
        TimeGateSchedulingEntryData[0U].GateEntryAdminControlListData[EntryIdx].AdminTrafficClassGateStates = 0xFFU;      /* all open */
        TimeGateSchedulingEntryData[0U].GateEntryAdminControlListData[EntryIdx].AdminGateOperationType = ETHSWT_HOST_REQUEST_UNCHANGED;
    }
#endif

    /* add these 2 gate control list entries */
    CBDRStatus = Netc_EthSwt_Ip_ConfigPortTimeGateScheduling(SwitchIdx, SwitchPortIdx, TRUE);

    return CBDRStatus;
}
    #endif
#endif

static inline void Netc_EthSwt_Ip_EnablePCIE(void)
{
    /* Enable PCIE for the TIMER */
    IP_NETC__NETC_F0_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
    /* Enable PCIE for the MDIO */
    IP_NETC__NETC_F1_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
    /* Enable PCIE for the Switch */
    IP_NETC__NETC_F2_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
#if defined(ERR_IPV_NETC_051260)
    #if (STD_ON == ERR_IPV_NETC_051260)
    /* Enable PCIE for the ENETC */
    IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
    #endif
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigSwt
 * Description   : function for configuring the switch registers and ports
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigSwt(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status = E_OK;
    uint8 enabledPortMask = 0U;
    Netc_EthSwt_Ip_SwitchIdxSwitchPort SwitchIdxSwitchPort;

    SwitchIdxSwitchPort.SwitchIdx = SwitchIdx;

    Netc_EthSwt_Ip_NetcClockFrequency = Config->netcClockFrequency;

    if(Config->EthSwtEnableSharedLearning)
    {
        /* VL = 1 - Shared VLAN learning: Use the FID specified in this register */
        IP_NETC__SW0_BASE->VFHTDECR1 = NETC_F2_VFHTDECR1_VL_MODE(1U) | NETC_F2_VFHTDECR1_FID(0U);
    }
    else
    {
        /* VL = 0 - Shared VLAN learning: FID is set to the VID assigned o the frame */
        IP_NETC__SW0_BASE->VFHTDECR1 = NETC_F2_VFHTDECR1_VL_MODE(0U);
    }

    IP_NETC__SW0_BASE->FDBHTMCR = NETC_F2_FDBHTMCR_DYN_LIMIT(Config->EthSwtMaxDynamicEntries);

    /* Initialize Custom VLAN Ethertype 1 (C-VLAN) */
    IP_NETC__SW0_COMMON->CVLANR1 = Config->EthSwtCustomVlanEtherType1;
    /* Initialize Custom VLAN Ethertype 2 (S-VLAN) */
    IP_NETC__SW0_COMMON->CVLANR2 = Config->EthSwtCustomVlanEtherType2;

    /* Mapping profile initialization */
    Netc_EthSwt_Ip_InitMappingProfile(Config);

    /* Initialize the ports of the switch */
    for (SwitchIdxSwitchPort.SwitchPortIdx = 0U; SwitchIdxSwitchPort.SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS; SwitchIdxSwitchPort.SwitchPortIdx++)
    {
        status = Netc_EthSwt_Ip_InitPort(SwitchIdxSwitchPort, &(*((*(Config)).port))[SwitchIdxSwitchPort.SwitchPortIdx]);
        /* Save the vlan configuration */
        Netc_EthSwt_Ip_PortVlanEnable[SwitchIdxSwitchPort.SwitchPortIdx] = (*((*(Config)).port))[SwitchIdxSwitchPort.SwitchPortIdx].iPort->vlanEnable;

        if ( (TRUE == (*((*(Config)).port))[SwitchIdxSwitchPort.SwitchPortIdx].EthSwtPortMacLayerPortEnable) && (FALSE == (*((*(Config)).port))[SwitchIdxSwitchPort.SwitchPortIdx].iPort->vlanEnable ))
        {
            enabledPortMask |= (1U << SwitchIdxSwitchPort.SwitchPortIdx);
        }
    }

    status |= Netc_EthSwt_Ip_EMDIOConfiguration(0U);  /* init EMDIO configuration register */

    /* Configure the VLAN filter hash default settings */
    IP_NETC__SW0_BASE->VFHTDECR0 = enabledPortMask; /* Add enabled ports to the default VLAN */
    /* To add Shared learning setting in EBT */
    /* set configured learning and forwarding options */
    IP_NETC__SW0_BASE->VFHTDECR2 = NETC_F2_VFHTDECR2_MLO(Config->MacLearningOption) | NETC_F2_VFHTDECR2_MFO(Config->MacForwardingOption);

    /* used for port aging, value in sec */
    Netc_EthSwt_Ip_FdbTableEntryTimeout[SwitchIdxSwitchPort.SwitchIdx] = Config->EthSwtArlTableEntryTimeout;

    /* +++ initialize 1588 timer for time gate scheduling +++ */
    Netc_EthSwt_Ip_InitTimer1588(Config);
    /* --- initialize 1588 timer for time gate scheduling --- */

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigTAS
 * Description   : function for configuring the Time Aware Shaper for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigTAS(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;

    /* Avoid MISRA violation */
    (void)CBDRStatus;
    (void)SwitchIdx;

    /* check if TAS is enabled or not */
    PortTimeAwareShaperEnabled[0U] = ((*((*(Config)).port))[0U].ePort->portTimeAwareShaperEnable ||
                                        (*((*(Config)).port))[1U].ePort->portTimeAwareShaperEnable ||
                                        (*((*(Config)).port))[2U].ePort->portTimeAwareShaperEnable) ? TRUE : FALSE;

    if (TRUE ==  PortTimeAwareShaperEnabled[0U])
    {
#if defined(ERR_IPV_NETC_E051130)
    #if (STD_ON == ERR_IPV_NETC_E051130)
        /* Default time gate scheduling conditions on the port 0 */
        CBDRStatus = Netc_EthSwt_Ip_InitTimeGateSchedulingFeature(SwitchIdx, 0U);
        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
        }
        else
        {
    #endif
#endif
            /* Add time gate scheduling table entries data */
            Netc_EthSwt_Ip_InitTimeGateSchedulingTableEntryData(Config);
#if defined(ERR_IPV_NETC_E051130)
    #if (STD_ON == ERR_IPV_NETC_E051130)
        }
    #endif
#endif
    }
    return status;
}

#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigFDBTable
 * Description   : function for configuring the FDB Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigFDBTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 MacAddrByteIdx;
    uint8 FdbEntryIdx;
    Netc_EthSwt_Ip_FdbEntryDataType FdbTableEntry = {0};

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    /* Add static FDB entries */
    for (FdbEntryIdx = 0U; FdbEntryIdx < Config->NumberOfFdbEntries; FdbEntryIdx++)
    {
        /* fill in data of Mac Address */
        for (MacAddrByteIdx = 0U; MacAddrByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacAddrByteIdx++)
        {
            FdbTableEntry.MacAddr[MacAddrByteIdx] = (*(Config->FdbEntries))[FdbEntryIdx].macAddr[MacAddrByteIdx];
        }

        FdbTableEntry.FID = 0U; /* fill in data of FID */
        FdbTableEntry.SwitchPortEgressBitMask = (*(Config->FdbEntries))[FdbEntryIdx].ePortMask; /* fill in data of port bitmask */
        FdbTableEntry.DynamicEntry = FALSE; /* static entry */

        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateFdbTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &FdbTableEntry);
        /* fail to add the static FDB entry */
        if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (MatchedEntries != 0U))
        {
            status = E_NOT_OK;
            break;
        }

    }
    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigIPFTable
 * Description   : function for configuring the FDB Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigIPFTable(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 IpftEntryIdx;
    Netc_EthSwt_Ip_IngressPortFilterEntryDataType IngrPortFilterTableEntry = {0};

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    for (IpftEntryIdx = 0U; IpftEntryIdx < Config->NumberOfIpftEntries; IpftEntryIdx++)
    {
        IngrPortFilterTableEntry = (*(Config->IngressPortFilterEntries))[IpftEntryIdx];
        CBDRStatus = Netc_EthSwt_Ip_AddIngressPortFilterTableEntry(SwitchIdx, &MatchedEntries, &IngrPortFilterTableEntry);
        /* fail to add the static FDB entry */
        if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (MatchedEntries != 0U))
        {
            status = E_NOT_OK;
            break;
        }

    }
    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigISITable
 * Description   : function for configuring the IngressStreamIdentification Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigISITable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 FrmKeyWordIdx;
    uint8 IsiEntryIdx;
    Netc_EthSwt_Ip_IngrStremIdentificationTableDataType IsiTableEntry = {0};

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    /* Add payload field values */
    IP_NETC__SW0_COMMON->ISIDKC0PF0CR = (*(Config->EthSwtKeyConstruction))[0U].EthSwtPayloadField0RegValue;
    IP_NETC__SW0_COMMON->ISIDKC0PF1CR = (*(Config->EthSwtKeyConstruction))[0U].EthSwtPayloadField1RegValue;
    IP_NETC__SW0_COMMON->ISIDKC1PF0CR = (*(Config->EthSwtKeyConstruction))[1U].EthSwtPayloadField0RegValue;
    IP_NETC__SW0_COMMON->ISIDKC1PF1CR = (*(Config->EthSwtKeyConstruction))[1U].EthSwtPayloadField1RegValue;
    IP_NETC__SW0_COMMON->ISIDKC2PF0CR = (*(Config->EthSwtKeyConstruction))[2U].EthSwtPayloadField0RegValue;
    IP_NETC__SW0_COMMON->ISIDKC2PF1CR = (*(Config->EthSwtKeyConstruction))[2U].EthSwtPayloadField1RegValue;
    IP_NETC__SW0_COMMON->ISIDKC3PF0CR = (*(Config->EthSwtKeyConstruction))[3U].EthSwtPayloadField0RegValue;
    IP_NETC__SW0_COMMON->ISIDKC3PF1CR = (*(Config->EthSwtKeyConstruction))[3U].EthSwtPayloadField1RegValue;

    /* Add key construction rules */
    IP_NETC__SW0_COMMON->ISIDKC0CR0 = (*(Config->EthSwtKeyConstruction))[0U].EthSwtKeyConstructionRegValue;
    IP_NETC__SW0_COMMON->ISIDKC1CR0 = (*(Config->EthSwtKeyConstruction))[1U].EthSwtKeyConstructionRegValue;
    IP_NETC__SW0_COMMON->ISIDKC2CR0 = (*(Config->EthSwtKeyConstruction))[2U].EthSwtKeyConstructionRegValue;
    IP_NETC__SW0_COMMON->ISIDKC3CR0 = (*(Config->EthSwtKeyConstruction))[3U].EthSwtKeyConstructionRegValue;

    /* Add static IngressStreamIdentification entries */
    for (IsiEntryIdx = 0U; IsiEntryIdx < Config->NumberOfIsiEntries; IsiEntryIdx++)
    {
        IsiTableEntry.IngrStreamIdenResumeEntryId = (*(Config->IsiEntries))[IsiEntryIdx].IngrStreamIdenResumeEntryId;
        IsiTableEntry.IngrStreamIdenEntryId = (*(Config->IsiEntries))[IsiEntryIdx].IngrStreamIdenEntryId;
        IsiTableEntry.IngrStreamEntryId = (*(Config->IsiEntries))[IsiEntryIdx].IngrStreamEntryId;
        IsiTableEntry.Keye_Keytype = (*(Config->IsiEntries))[IsiEntryIdx].Keye_Keytype;
        IsiTableEntry.Keye_SrcPortId = (*(Config->IsiEntries))[IsiEntryIdx].Keye_SrcPortId;
        IsiTableEntry.Keye_Spm = (*(Config->IsiEntries))[IsiEntryIdx].Keye_Spm;
        for(FrmKeyWordIdx = 0; FrmKeyWordIdx < 4; FrmKeyWordIdx++)
        {
            IsiTableEntry.Keye_FrmKey[FrmKeyWordIdx] = (*(Config->IsiEntries))[IsiEntryIdx].Keye_FrmKey[FrmKeyWordIdx];
        }
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateIngrStreamIdentificationTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &IsiTableEntry);
        /* fail to add the static IngressStreamIdentification entry */
        if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (MatchedEntries != 0U))
        {
            status = E_NOT_OK;
            break;
        }

    }
    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigISITable
 * Description   : function for configuring the IngressStreamIdentification Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigSeqGenTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 SeqTagEntryIdx;
    Netc_EthSwt_Ip_ISQGTableDataType SeqTagTableEntry = {0};

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    /* Add static SequenceTag entries */
    for (SeqTagEntryIdx = 0U; SeqTagEntryIdx < Config->NumberOfSeqTagEntries; SeqTagEntryIdx++)
    {
        SeqTagTableEntry.ISQGEntryId = (*(Config->SeqTagEntries))[SeqTagEntryIdx].ISQGEntryId;
        SeqTagTableEntry.Cfge_SQTagType = (*(Config->SeqTagEntries))[SeqTagEntryIdx].Cfge_SQTagType;
        SeqTagTableEntry.Sgse_SQGNum = (*(Config->SeqTagEntries))[SeqTagEntryIdx].Sgse_SQGNum;
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateIngressSeqGenerationTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &SeqTagTableEntry);
        /* fail to add the static SequenceGeneration entry */
        if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (MatchedEntries != 0U))
        {
            status = E_NOT_OK;
            break;
        }

    }
    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigISITable
 * Description   : function for configuring the IngressStreamIdentification Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigSeqRecTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 SeqRecEntryIdx;
    Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType SeqRecTableEntry = {0};

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    /* Add static SequenceRecovery entries */
    for (SeqRecEntryIdx = 0U; SeqRecEntryIdx < Config->NumberOfSeqRecoveryEntries; SeqRecEntryIdx++)
    {
        SeqRecTableEntry.EgrSeqRecEntryId = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].EgrSeqRecEntryId;
        SeqRecTableEntry.Cfge_SQTag = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SQTag;
        SeqRecTableEntry.Cfge_SQRHisLen = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SQRHisLen;
        SeqRecTableEntry.Cfge_SQRFutureWinLen = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SQRFutureWinLen;
        SeqRecTableEntry.Cfge_SQRTimeOutPeriod = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SQRTimeOutPeriod;
        SeqRecTableEntry.Cfge_SqrTnsq = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SqrTnsq;
        SeqRecTableEntry.Cfge_SqrAlg = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SqrAlg;
        SeqRecTableEntry.Cfge_SqrType = (*(Config->SeqRecoveryEntries))[SeqRecEntryIdx].Cfge_SqrType;
        CBDRStatus = Netc_EthSwt_Ip_UpdateEgressSeqRecoveryTableEntry(0U, &MatchedEntries, &SeqRecTableEntry);
        /* fail to add the static SequenceRecovery entry */
        if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (MatchedEntries != 1U))
        {
            status = E_NOT_OK;
            break;
        }

    }
    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigFrmModificationTable
 * Description   : function for configuring the FrameModification Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigFrmModificationTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 FrmModifEntryIdx = 0U;

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    Netc_EthSwt_Ip_FrmModificationEntryDataType FrmModifTableEntry = {0};

    for (FrmModifEntryIdx = 0U; FrmModifEntryIdx < Config->NumberOfFrmModifEntries; FrmModifEntryIdx++)
    {
        FrmModifTableEntry = (*(Config->FrameModificationEntries))[FrmModifEntryIdx];
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &FrmModifTableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigEgressTreatmentTable
 * Description   : function for configuring the EgressTreatment Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigEgressTreatmentTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 EgrTrtEntryIdx = 0U;

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    Netc_EthSwt_Ip_EgressTreatmentEntryDataType EgrTrtTableEntry = {0};

    for (EgrTrtEntryIdx = 0U; EgrTrtEntryIdx < Config->NumberOfEgrTreatmentEntries; EgrTrtEntryIdx++)
    {
        EgrTrtTableEntry = (*(Config->EgressTreatmentEntries))[EgrTrtEntryIdx];
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateEgressTreatmentTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &EgrTrtTableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}

Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_GetEgressCountTable(uint8 SwitchIdx, uint32 * MatchedEntries, Netc_EthSwt_Ip_ECTableStatisticsDataType * EgressCountTable)
{
    uint8 EgrTrtEntryIdx = 0U;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint8 EgressCountTableEntriesNb = IP_NETC__SW0_COMMON->ECTCAPR & NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK;

    for (EgrTrtEntryIdx = 0U; EgrTrtEntryIdx < EgressCountTableEntriesNb; EgrTrtEntryIdx++)
    {
        CBDRStatus = Netc_EthSwt_Ip_QueryEgressCountTableEntry(SwitchIdx, EgrTrtEntryIdx, MatchedEntries, &(EgressCountTable[EgrTrtEntryIdx]));

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            break;
        }
    }

    return CBDRStatus;
}



#endif

#if (NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigIngressStreamTable
 * Description   : function for configuring the IngressStream Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigIngressStreamTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 IngrStrEntryIdx = 0U;

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    Netc_EthSwt_Ip_IngressStreamEntryDataType IngrStrTableEntry = {0};

    for (IngrStrEntryIdx = 0U; IngrStrEntryIdx < Config->NumberOfIngrStreamEntries; IngrStrEntryIdx++)
    {
        IngrStrTableEntry = (*(Config->IngressStreamEntries))[IngrStrEntryIdx];

        /*Add Ingress Stream Table entry*/
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateIngressStreamTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &IngrStrTableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }

    }

    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigIngressStreamFilterTable
 * Description   : function for configuring the Ingress Stream Filter Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigIngressStreamFilterTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint8 IngrStrFilterEntryIdx = 0U;

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    Netc_EthSwt_Ip_IngressStreamFilterEntryDataType IngrStrFilterTableEntry = {0};

    for (IngrStrFilterEntryIdx = 0U; IngrStrFilterEntryIdx < Config->NumberOfIngrStreamFilterEntries; IngrStrFilterEntryIdx++)
    {
        IngrStrFilterTableEntry = (*(Config->IngressStreamFilterEntries))[IngrStrFilterEntryIdx];
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateIngressStreamFilterTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &IngrStrFilterTableEntry);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_STREAMCOUNT_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigIngressStreamCountTable
 * Description   : function for configuring the IngressStreamCount Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigIngressStreamCountTable(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 MatchedEntries = 0U;
    uint32 IngrStrCountIdx = 0U;

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    for (IngrStrCountIdx = 0U; IngrStrCountIdx < Config->NumberOfIngrStreamCountEntries; IngrStrCountIdx++)
    {

        /*Add Ingress Stream Count Table entry*/
        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateIngressStreamCountTableEntry(0U, NETC_ETHSWT_ADD_CMD, &MatchedEntries, IngrStrCountIdx);

        if (CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
            status = E_NOT_OK;
            break;
        }
    }

    return status;
}
#endif

#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigVLANFilterTable
 * Description   : function for configuring the VLAN Filter Table for the switch
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_ConfigVLANFilterTable(const Netc_EthSwt_Ip_ConfigType * Config)
{

    uint32 VlanMatchedEntries = 0U;
    uint8 VlanEntryIdx;
    Netc_EthSwt_Ip_VlanFilterEntryDataType VlanFilterEntryData = {0};

    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;

    /* Add Vlan Filter entries */
    for (VlanEntryIdx = 0U; VlanEntryIdx < Config->NumberOfVlanFilterEntries; VlanEntryIdx++)
    {
        /* fill in VlanFilterEntryData structure  */
        VlanFilterEntryData.VlanID = (*(Config->VlanFilterEntries))[VlanEntryIdx].vlanId;
        VlanFilterEntryData.PortMembershipBitmap = (*(Config->VlanFilterEntries))[VlanEntryIdx].iPortMask;

        if (Config->EthSwtEnableSharedLearning == FALSE)
        {
            VlanFilterEntryData.FID = VlanFilterEntryData.VlanID;   /* for independent vlan learning, the FID should be equal to TCI */
        }
        else
        {
            VlanFilterEntryData.FID = (0U);                         /* for shared vlan learning, the FID should be always equal to 0 */
        }

        VlanFilterEntryData.MacLearningOptions = Config->MacLearningOption;                  /* enable mac learning */
        VlanFilterEntryData.MacForwardingOptions = Config->MacForwardingOption;                /* FDB lookup, if there is no match, then frame is flooded */
        VlanFilterEntryData.IpMulticastFloodingEnable = FALSE;          /* IP multicast flooding disable */
        VlanFilterEntryData.IpMulticastFilteringEnable = FALSE;         /* IP multicast filtering disable */
        VlanFilterEntryData.BaseEgressTreatmentEntryID = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;    /* egress treatment processing is by-passed */

        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry(0U, NETC_ETHSWT_ADD_CMD, &VlanMatchedEntries, &VlanFilterEntryData);
        /* fail to add the Vlan Filter entry */
        if ((CBDRStatus != NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) || (VlanMatchedEntries != 0U))
        {
            status = E_NOT_OK;
            break;
        }
    }
    return status;
}
#endif


/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_Init
 * Description   : function for initializing a switch
 * implements Netc_EthSwt_Ip_Init_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_Init(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status;
    uint8 portIdx = 0U;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(Config != NULL_PTR);
#endif

    /* enable PCIE for the timer, MDIO, switch, and ENETC */
    Netc_EthSwt_Ip_EnablePCIE();
    status = Netc_EthSwt_Ip_IerbReady();

    if(status == (uint8)(E_OK))
    {
        /* intialize command ring 0 */
        CBDRStatus = Netc_EthSwt_Ip_InitCommandBDR(0U, NETC_ETHSWT_IP_CBDR_0);
        if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == CBDRStatus)
        {
             /* configure switch registers and ports */
            status = Netc_EthSwt_Ip_ConfigSwt(SwitchIdx,Config);
#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
            /* Configure FDB table */
            status |= Netc_EthSwt_Ip_ConfigFDBTable(Config);
#endif

#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
            /* Configure VLAN Filter table */
            status |= Netc_EthSwt_Ip_ConfigVLANFilterTable(Config);
#endif
            /* Enable Ingress Port Filtering for ports
            (for PTP and Mirroring)
            PTP traffic from PSI is injected as Tx management on desired external port and therefore not passing as Rx through pseudo-ports.
            PTP frames sent to external devices from PSI will not be filtered when filtering on pseudo-ports is enabled.
            Only PTP frames from VSIs will be redirected to Ingress on PSI when filtering is enabled on pseudo-ports. */
            for (portIdx = 0U; portIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS; portIdx++)
            {
                status |= Netc_EthSwt_Ip_EnableIngressPortFiltering(SwitchIdx, portIdx, TRUE);
            }
            Netc_EthSwt_Ip_ConfigPtr[SwitchIdx] = Config;

#if (NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES > 0U)
            status |= Netc_EthSwt_Ip_ConfigIPFTable(SwitchIdx, Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
        }
        else
        {
            status = E_NOT_OK;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_StartTSN
 * Description   : function for starting the Time Sensitive Networking functionality
 * implements Netc_EthSwt_Ip_StartTSN_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_StartTSN(uint8 SwitchIdx)
{
    Std_ReturnType status = E_OK;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx] != NULL_PTR);
#endif

#if (NETC_ETHSWT_NUMBER_OF_RP_ENTRIES > 0U)
    status |= Netc_EthSwt_Ip_ConfigRP(SwitchIdx,Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES > 0U)
    status |= Netc_EthSwt_Ip_ConfigSGCL(SwitchIdx,Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES > 0U)
    status |= Netc_EthSwt_Ip_ConfigSGI(SwitchIdx,Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
    /* Configure Time Aware Shaper */
    status |= Netc_EthSwt_Ip_ConfigTAS(SwitchIdx, Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);

#if (NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
    /* Configure IngressStreamIdentification table */
    status |= Netc_EthSwt_Ip_ConfigISITable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES > 0U)
    /* Configure IngressSequenceGeneration table */
    status |= Netc_EthSwt_Ip_ConfigSeqGenTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif

#if (NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES > 0U)
    /* Configure EgressSequenceRecovery table */
    status |= Netc_EthSwt_Ip_ConfigSeqRecTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
#if (NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES > 0U)
    /* Configure EgressTreatment table */
    status |= Netc_EthSwt_Ip_ConfigEgressTreatmentTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
#if (NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES > 0U)
    /* Configure FrameModification table */
    status |= Netc_EthSwt_Ip_ConfigFrmModificationTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
#if (NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
    /* Configure IngressStream table */
    status |= Netc_EthSwt_Ip_ConfigIngressStreamTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
#if (NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES > 0U)
    /* Configure Ingress Stream Filter table */
    status |= Netc_EthSwt_Ip_ConfigIngressStreamFilterTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif
#if (NETC_ETHSWT_NUMBER_OF_STREAMCOUNT_ENTRIES > 0U)
    /* Configure IngressStreamCount table */
    status |= Netc_EthSwt_Ip_ConfigIngressStreamCountTable(Netc_EthSwt_Ip_ConfigPtr[SwitchIdx]);
#endif

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EMDIOConfiguration
 * Description   : function for configuring the EMDIO
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_EMDIOConfiguration( uint8 SwitchIdx )
{
    Std_ReturnType Status = E_OK;
    uint32 CfgData;

    (void)SwitchIdx;
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    CfgData = NETC_F1_EMDIO_CFG_CMP(0U) | NETC_F1_EMDIO_CFG_CIM(0U) | NETC_F1_EMDIO_CFG_NEG(1U) \
            | NETC_F1_EMDIO_CFG_EHOLD(0U) | NETC_F1_EMDIO_CFG_MDIO_CLK_DIV(NETC_ETHSWT_IP_MDIO_CLK_DIV) \
            | NETC_F1_EMDIO_CFG_ENC45(0U) | NETC_F1_EMDIO_CFG_PRE_DIS(0U) | NETC_F1_EMDIO_CFG_MDIO_HOLD(4U);

    /* config EMDIO_CFG register */
    IP_NETC__EMDIO_BASE->EMDIO_CFG = CfgData;

    return Status;
}

/* implements Netc_EthSwt_Ip_ReadTrcvRegister_Activity */
Std_ReturnType Netc_EthSwt_Ip_ReadTrcvRegister( uint8 SwitchIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 * RegVal )
{
    Std_ReturnType Status = E_NOT_OK;
    uint32 CtrlData;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(NULL_PTR != RegVal);
#endif

    (void)SwitchIdx;

    CtrlData = NETC_F1_EMDIO_CTL_PORT_ADDR(TrcvIdx) | NETC_F1_EMDIO_CTL_DEV_ADDR(RegIdx) \
             | NETC_F1_EMDIO_CTL_READ(1U);

    /* config EMDIO_CTL register */
    IP_NETC__EMDIO_BASE->EMDIO_CTL = CtrlData;

    /* Wait till MDIO transaction is occuring and no read error is detected */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do
    {
        #ifdef MCAL_ENABLE_FAULT_INJECTION
            MCAL_FAULT_INJECTION_POINT(ETHSWT_CHECK_EMDIO_READ_TIMEOUT);
        #endif
        if ((IP_NETC__EMDIO_BASE->EMDIO_CFG & NETC_ETHSWT_IP_MDIO_REG_READ_FLAG) == 0x0U)
        {
            Status = E_OK;
            break;
        }
    } while (!Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    /* Read the Data */
    if ((uint8)(E_OK) == Status)
    {
        *RegVal = (uint16)(IP_NETC__EMDIO_BASE->EMDIO_DATA & NETC_F1_EMDIO_DATA_MDIO_DATA_MASK);
    }

    return Status;
}

/* implements Netc_EthSwt_Ip_WriteTrcvRegister_Activity */
Std_ReturnType Netc_EthSwt_Ip_WriteTrcvRegister( uint8 SwitchIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal )
{
    Std_ReturnType Status = E_NOT_OK;
    uint32 CtrlData;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;

    CtrlData = NETC_F1_EMDIO_CTL_PORT_ADDR(TrcvIdx) | NETC_F1_EMDIO_CTL_DEV_ADDR(RegIdx);

    /* config EMDIO_CTL register */
    IP_NETC__EMDIO_BASE->EMDIO_CTL = CtrlData;

    /* Write MDIO_DATA for initiating write transaction to PHY */
    IP_NETC__EMDIO_BASE->EMDIO_DATA = RegVal;

    /* Wait till MDIO transaction is occuring */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do
    {
        #ifdef MCAL_ENABLE_FAULT_INJECTION
            MCAL_FAULT_INJECTION_POINT(ETHSWT_CHECK_EMDIO_WRITE_TIMEOUT);
        #endif
        if ((IP_NETC__EMDIO_BASE->EMDIO_CFG & NETC_ETHSWT_IP_MDIO_REG_WRITE_FLAG) == 0x0U)
        {
            Status = E_OK;
            break;
        }
    } while (!Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPortMirrorState
 * Description   : External function for obtaining the current status of mirroring for the indexed Ethernet switch
 * implements Netc_EthSwt_Ip_GetMirrorState_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetMirrorState( uint8 SwitchIdx, Netc_EthSwt_Ip_SwitchMirrorStateType *MirrorStatePtr )
{
    Std_ReturnType Status = E_OK;
    uint32 MirrorState;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MirrorStatePtr != NULL_PTR);
#endif

    (void)SwitchIdx;

    MirrorState = (IP_NETC__SW0_BASE->IMDCR0) & NETC_F2_IMDCR0_MIREN_MASK;
    *MirrorStatePtr = (MirrorState == 0U) ? (NETC_ETHSWT_MIRROR_DISABLED) : (NETC_ETHSWT_MIRROR_ENABLED);

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetMirrorState
 * Description   : External function for requesting to set the mirroring state of the given Ethernet switch.
 * implements Netc_EthSwt_Ip_SetMirrorState_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetMirrorState( uint8 SwitchIdx, Netc_EthSwt_Ip_SwitchMirrorStateType MirrorState )
{
    Std_ReturnType Status = E_OK;
    uint32 RegIMDCR0 = 0x0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    (void)SwitchIdx;
    RegIMDCR0 = IP_NETC__SW0_BASE->IMDCR0;
    if (NETC_ETHSWT_MIRROR_ENABLED == MirrorState)
    {
        RegIMDCR0 |= NETC_F2_IMDCR0_MIREN(NETC_ETHSWT_MIRROR_ENABLED);
    }
    else
    {
        RegIMDCR0 &= ~NETC_F2_IMDCR0_MIREN(NETC_ETHSWT_MIRROR_ENABLED);
    }

    IP_NETC__SW0_BASE->IMDCR0 = RegIMDCR0;

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteMirrorConfiguration
 * Description   : External function for deleting the mirror configuration of the given Ethernet switch..
 * implements Netc_EthSwt_Ip_DeleteMirrorConfiguration_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_DeleteMirrorConfiguration( uint8 MirroredSwitchIdx )
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint16 EFMEntryId;
    uint8 MIRDestBit;
    uint32 MatchedEntries = 0U;
    uint32 LocalImdCr1 = 0U;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_06();
    if (TRUE == MirrorConfigurationDone)
    {
        if (MirroringIngressPortFilterEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID)
        {
            /* Delete ingress port filter entry */
            CBDRStatus = Netc_EthSwt_Ip_DeleteIngressPortFilterTableEntry(MirroredSwitchIdx, &MatchedEntries, MirroringIngressPortFilterEntryId);
            if ((NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != CBDRStatus) || (0UL == MatchedEntries))
            {
                Status = E_NOT_OK;
            }
            else
            {
                /* Set ingress port filter entry to NULL again */
                MirroringIngressPortFilterEntryId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;
                Status = E_OK;
            }
        }

        /* Delete Frame modificatin entry */
        MIRDestBit = (uint8)((IP_NETC__SW0_BASE->IMDCR0 & NETC_F2_IMDCR0_MIRDEST_MASK) >> NETC_F2_IMDCR0_MIRDEST_SHIFT);
        /* Read the register value in a local variable since it should have been read more than once. */
        LocalImdCr1 = IP_NETC__SW0_BASE->IMDCR1;
        EFMEntryId = (uint16)(LocalImdCr1 & NETC_F2_IMDCR1_EFMEID_MASK);
        if ((EFMEntryId != NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID) && (MIRDestBit == (uint8)0U))
        {
            CBDRStatus = Netc_EthSwt_Ip_DeleteFrmModificationTableEntry(MirroredSwitchIdx, EFMEntryId, &MatchedEntries);
            if ((NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != CBDRStatus) || (0U == MatchedEntries))
            {
                Status = E_NOT_OK;
            }
            else
            {
                EFMEntryId = (uint16)(NETC_F2_IMDCR1_EFMEID(NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID));        /* set frame modification table entry ID to NULL */
                LocalImdCr1 |= EFMEntryId;
                IP_NETC__SW0_BASE->IMDCR1 = LocalImdCr1;
                Status = E_OK;
            }
        }
        if ((uint8)(E_OK) == Status)
        {
            Status = Netc_EthSwt_Ip_SetMirrorState(MirroredSwitchIdx, NETC_ETHSWT_MIRROR_DISABLED);

            /* Disable ingress mirroring on all ports */
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[0U]->PMCR = 0x0U;
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[1U]->PMCR = 0x0U;
            Netc_EthSwt_Ip_SW0_PortxBaseAddr[2U]->PMCR = 0x0U;

            MirrorConfigurationDone = FALSE;
        }
    }

    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_06();

    return Status;
}

/* inline function for checking if mac address filter enabled or not */
static inline void Netc_EthSwt_Ip_CheckMacAddressFilterEnableFlag(Netc_EthSwt_Ip_IngressPortFilterSrcDestAddrFilter* const IngressPortFilterSrcDestAddrFilter, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr)
{
    uint8 MacByteIdx;

    for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
    {
        if (MirrorConfigurationPtr->SrcMacAddrFilter[MacByteIdx] != 0x0U)
        {
            IngressPortFilterSrcDestAddrFilter->SrcMacAddrFilterEnabled = TRUE;
            break;
        }
    }
    for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
    {
        if (MirrorConfigurationPtr->DstMacAddrFilter[MacByteIdx] != 0x0U)
        {
            IngressPortFilterSrcDestAddrFilter->DstMacAddrFilterEnabled = TRUE;
            break;
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigIngressPortFilterForTimestamping
 * implements Netc_EthSwt_Ip_ConfigIngressPortFilterForTimestamping_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_ConfigIngressPortFilterForTimestamping(uint8 SwitchIdx)
{

    Netc_EthSwt_Ip_IngressPortFilterEntryDataType IngressPortFilterTableEntry = {0};
    uint8 Index;
    uint32 MatchedEntries;
    Std_ReturnType Status;

    /* CFGE Data */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeOverrideIpv = FALSE;  /* Leave IPV as-is */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeOverrideDr = FALSE;   /* Leave DR as-is */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeFilterForwardingAction = NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REDIRECTFRAMES; /* Redirect frame to management port*/
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeIngressMirroringEnable = FALSE;   /* Ingress Mirroring disabled */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeWakeOnLanTriggerEnable = FALSE;   /* Wake-On-LAN triggering disabled */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeFilterAction = NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_NOACTION; /* Not routing to any RP/Ingress Stream */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeHostReason = (uint8)NETC_ETHSWT_IP_HOSTREASON_SW_PTP;   /* Software-defined hostreason to mark frame as PTP-specific */
    IngressPortFilterTableEntry.IngressPortFilterCfgeData.CfgeTargetForSelectedFilterAction = 0xFFFFFFFFUL; /* RP/Ingress Stream by-passed */

    /* KEYE Data */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyePrecedence = 0xFFFFU; /* Set highest priority for filter */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask = 0x0U; /* Mask all frame attribute flags (Do not filter based on them) */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask = 0x0U; /* Do not filter based on Differentiated Services Code Point */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeSourcePortIDMask = 0x0U;  /* Do not filter based on Source Port */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = 0x0U;    /* Do not filter based on Outer VLAN Tag Control Information */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask = 0x0U;    /* Do not filter based on Inner VLAN Tag Control Information */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeEtherTypeMask = 0x0U; /* Do not filter based on EtherType */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeIPProtocolMask = 0x0U;    /* Do not filter based on IP Protocol field */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeL4SourcePortMask = 0x0U; /* Do not filter based on L4 Source Port */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeL4DestinationPortMask = 0x0U;  /* Do not filter based on L4 Destination Port */

    for (Index = 0; Index < 6U; Index++)
    {
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddrMask[Index] = 0xFFU; /* Filter based on Destination MAC Address */
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeSrcMacAddrMask[Index] = 0x0U; /* Do not filter based on Source MAC Address */
    }
    for (Index = 0; Index < 4U; Index++)
    {
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeIPSourceAddressMask[Index] = 0x0U;        /* Do not filter based on IP Source Address */
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[Index] = 0x0U;   /* Do not filter based on IP Destination Address */
    }
    for (Index = 0; Index < 24U; Index++)
    {
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyePayloadBytesMask[Index] = 0x0U;   /* Do not filter based on Payload Bytes */
    }

    /* Generic PTP messages DMAC: 01-1B-19-00-00-00 */
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[0U] = 0x01U;
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[1U] = 0x1BU;
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[2U] = 0x19U;
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[3U] = 0x00U;
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[4U] = 0x00U;
    IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[5U] = 0x00U;
    Status = (Netc_EthSwt_Ip_AddIngressPortFilterTableEntry(SwitchIdx, &MatchedEntries, &IngressPortFilterTableEntry) == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) ? E_OK : E_NOT_OK;

    if (Status == E_OK)
    {
        /* Peer delay message DMAC: 01-80-C2-00-00-0E */
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[1U] = 0x80U;
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[2U] = 0xC2U;
        IngressPortFilterTableEntry.IngressPortFilterkeyeData.KeyeDstMacAddr[5U] = 0x0EU;
        Status = (Netc_EthSwt_Ip_AddIngressPortFilterTableEntry(SwitchIdx, &MatchedEntries, &IngressPortFilterTableEntry) == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS) ? E_OK : E_NOT_OK;
    }

    return Status;
}

/* inline function for enabling mac address filtering for port mirroring*/
static inline Std_ReturnType Netc_EthSwt_Ip_ConfigIngressPortFilterForPortMirroring(const uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_IngressPortFilterSrcDestAddrFilter IngressPortFilterSrcDestAddrFilter,
                                                                 const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr,
                                                                 Netc_EthSwt_Ip_IngressPortFilterEntryDataType *IngressPortFilterTableEntry
                                                                )
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint8 MacByteIdx;
    uint8 PayloadByteIdx;
    uint32 MatchedEntries;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    /* config and add one ingress port filter table entry */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideIpv = FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideDr = FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeIngressMirroringEnable = TRUE;    /* enable mirroring */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeWakeOnLanTriggerEnable = FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeCutThroughDisable = TRUE;         /* shoudl disable CTD */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeTimestampCaptureEable = FALSE;
    /* permit frames */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterForwardingAction = NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_PERMITFRAMES;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterAction = NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_NOACTION;

    /* enable mac address filtering */
    for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
    {
        if (IngressPortFilterSrcDestAddrFilter.DstMacAddrFilterEnabled == TRUE)
        {
            IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[MacByteIdx] = 0xFFU;
            IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[MacByteIdx] = MirrorConfigurationPtr->DstMacAddrFilter[MacByteIdx];
            MirrorCfgBackup.DstMacAddrFilter[MacByteIdx] = MirrorConfigurationPtr->DstMacAddrFilter[MacByteIdx];
        }
        else
        {
            IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[MacByteIdx] = 0x0U;
            MirrorCfgBackup.DstMacAddrFilter[MacByteIdx] = 0x0U;
        }

        if (IngressPortFilterSrcDestAddrFilter.SrcMacAddrFilterEnabled == TRUE)
        {
            IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[MacByteIdx] = 0xFFU;
            IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[MacByteIdx] = MirrorConfigurationPtr->SrcMacAddrFilter[MacByteIdx];
            MirrorCfgBackup.SrcMacAddrFilter[MacByteIdx] = MirrorConfigurationPtr->SrcMacAddrFilter[MacByteIdx];
        }
        else
        {
            IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[MacByteIdx] = 0x0U;
            MirrorCfgBackup.SrcMacAddrFilter[MacByteIdx] = 0x0U;
        }
    }

    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask = 0U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortIDMask = 0U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask = 0U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask = 0U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask = 0U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask = 0U;
    for (MacByteIdx = 0U; MacByteIdx < 4U; MacByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[MacByteIdx] = 0x0U;
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[MacByteIdx] = 0x0U;
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask = 0U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask = 0U;
    for (PayloadByteIdx = 0U; PayloadByteIdx < 24U; PayloadByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[PayloadByteIdx] = 0x0U;
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence = NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID;      /* precedence, maximum priority */

    if (MirrorConfigurationPtr->VlanIdFilter != NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID)
    {
        MirrorCfgBackup.VlanIdFilter = MirrorConfigurationPtr->VlanIdFilter;

        /* vlan id filter */
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = 0xFFF0U;
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation = (MirrorConfigurationPtr->VlanIdFilter);
    }
    else
    {
        MirrorCfgBackup.VlanIdFilter = NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID;
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = 0x0U;
    }

    CBDRStatus = Netc_EthSwt_Ip_AddIngressPortFilterTableEntry(MirroredSwitchIdx, &MatchedEntries, IngressPortFilterTableEntry);
    if ((NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != CBDRStatus) || (1U == MatchedEntries))
    {
        Status = E_NOT_OK;
    }
    else
    {
        /* Store the ingress port filter entry id */
        MirroringIngressPortFilterEntryId = IngressPortFilterTableEntry->IngressPortFilterEntryID;
    }

    return Status;
}

/* inline function for retagging /double tagging egress frames with frame modification table entry */
static inline Std_ReturnType Netc_EthSwt_Ip_ConfigEgressFrameModificationForPortMirroring(uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr)
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 RegIMDCR1 = 0x0UL;
    uint32 MatchedEntries = 0x0UL;
    Netc_EthSwt_Ip_FrmModificationEntryDataType FrmModificationEntry = {0};

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    if (MirrorConfigurationPtr->MirroringMode != NETC_ETHSWT_NO_VLAN_RETAGGING)
    {
        /* config and add one frame modification table entry for modifying the dest mac address */
        FrmModificationEntry.FrmModificationEntryID = NETC_ETHSWT_IP_EFMEID_FOR_MIRRORING;                   /* default frame modification table entry ID for mirroring */
        FrmModificationEntry.L2Actions = 0U;
        FrmModificationEntry.L2HeaderMacActions = 0U;                       /*  no actions for Header Mac */
        FrmModificationEntry.L2HeaderVlanActions = (MirrorConfigurationPtr->MirroringMode > NETC_ETHSWT_VLAN_RETAGGING) ? (2U) : (3U);
        FrmModificationEntry.OuterVidActions = 1U;                          /*  Use the VID specified in the OUTER_VLAN_VID field of this entry */
        FrmModificationEntry.OuterVlanVID = MirrorConfigurationPtr->VlanId;
        FrmModificationEntry.OuterTpidAction = 0U;                          /* Use TPID, PCP and DEI from outer VLAN header */
        FrmModificationEntry.OuterDeiAction = 0U;                           /* Use TPID, PCP and DEI from outer VLAN header */
        FrmModificationEntry.OuterPcpAction = 0U;                           /* Use TPID, PCP and DEI from outer VLAN header */
        FrmModificationEntry.SequenceTagAction = 0U;
        FrmModificationEntry.PayloadActions = 0U;
        FrmModificationEntry.FrmModificationDataEntryID = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;     /* frame modification data table entry id */

        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry(MirroredSwitchIdx, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &FrmModificationEntry);
        if (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS == CBDRStatus)
        {
            /* [IMDCR0]: keep IPV and DR default in IMDCR0 register */
            /* [IMDCR1] */
            RegIMDCR1 = NETC_F2_IMDCR1_EFM_LEN_CHANGE(NETC_ETHSWT_IP_EFM_LEN_CHANGE_FOR_MIRRORING);
            RegIMDCR1 |= NETC_F2_IMDCR1_EFMEID(NETC_ETHSWT_IP_EFMEID_FOR_MIRRORING);        /* default frame modification table entry ID for mirroring */
            IP_NETC__SW0_BASE->IMDCR1 = RegIMDCR1;
        }
        else
        {
            Status = E_NOT_OK;
        }
    }

    return Status;
}

static inline void Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable_SecondPart(uint8 SwitchIdx, Netc_EthSwt_Ip_ResumeEntryEntryId ResumeEntryEntryId, float64 AgingTimeout, Std_ReturnType* Status)
{
    Netc_EthSwt_Ip_CBDRStatusType DeleteStatus;
    if(AgingTimeout >= (float64) (Netc_EthSwt_Ip_FdbTableEntryTimeout[SwitchIdx])) /* Check if FDB entry is older than accepted */
    {   /* Try and delete the aged FDB entry */
        DeleteStatus = Netc_EthSwt_Ip_DeleteFdbTableEntryById(SwitchIdx, ResumeEntryEntryId.EntryId);
        if(NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != DeleteStatus)
        {
            *Status = E_NOT_OK;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_WriteMirrorConfiguration
 * Description   : Function used for writing a mirroring configuration
 * implements Netc_EthSwt_Ip_WriteMirrorConfiguration_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_WriteMirrorConfiguration( uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr )
{
    Std_ReturnType Status = E_OK;
    uint32 RegIMDCR0 = 0x0UL;
    uint32 RegIMDCR1 = 0x0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MirrorConfigurationPtr != NULL_PTR);
    DevAssert(MirrorConfigurationPtr->CapturePortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
    DevAssert(MirrorConfigurationPtr->MirroringMode <= NETC_ETHSWT_VLAN_DOUBLE_TAGGING);
#endif

    /* If a mirroring configuration is already in place, delete it */
    Status = Netc_EthSwt_Ip_DeleteMirrorConfiguration(MirroredSwitchIdx);
    if ((uint8)(E_OK) == Status)
    {
        /* Indicates the mirror destination */
        RegIMDCR0 = IP_NETC__SW0_BASE->IMDCR0;
        RegIMDCR0 &= ~(NETC_F2_IMDCR0_MIRDEST_MASK);
        RegIMDCR0 |= NETC_F2_IMDCR0_MIRDEST(0U);         /* 0: Port as specified by PORT field; 1: Switch management port */
        RegIMDCR0 &= ~(NETC_F2_IMDCR0_PORT_MASK);
        RegIMDCR0 |= NETC_F2_IMDCR0_PORT(MirrorConfigurationPtr->CapturePortIdx);
        /* Write IMDCR0 register */
        IP_NETC__SW0_BASE->IMDCR0 = RegIMDCR0;

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_11();
        RegIMDCR1 = IP_NETC__SW0_BASE->IMDCR1;
        RegIMDCR1 |= NETC_F2_IMDCR1_EFMEID(NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID);        /* set frame modification table entry ID to NULL */
        IP_NETC__SW0_BASE->IMDCR1 = RegIMDCR1;

        Netc_EthSwt_Ip_WriteMirrorConfiguration_SecondPart(MirroredSwitchIdx, MirrorConfigurationPtr, &Status);

        if ((uint8)(E_OK) == Status)
        {
            /* Set the mirror configuration done flag */
            MirrorConfigurationDone = TRUE;

            /* store the mirror configuration data */
            MirrorCfgBackup.MirroringMode = MirrorConfigurationPtr->MirroringMode;
            MirrorCfgBackup.VlanId = MirrorConfigurationPtr->VlanId;
            MirrorCfgBackup.CapturePortIdx = MirrorConfigurationPtr->CapturePortIdx;
            MirrorCfgBackup.TrafficDirectionIngressBitMask = MirrorConfigurationPtr->TrafficDirectionIngressBitMask;
        }
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_11();

    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ReadMirrorConfiguration
 * Description   : External function for obtaining the mirror configuration of the given Ethernet switch..
 * implements Netc_EthSwt_Ip_ReadMirrorConfiguration_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_ReadMirrorConfiguration( uint8 MirroredSwitchIdx, Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr )
{
    Std_ReturnType Status = E_OK;
    uint8 MacByteIdx;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MirrorConfigurationPtr != NULL_PTR);
#endif

    (void)MirroredSwitchIdx;
    if (TRUE == MirrorConfigurationDone)    /* The mirror configuration is in place */
    {
        for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
        {
            MirrorConfigurationPtr->SrcMacAddrFilter[MacByteIdx] = MirrorCfgBackup.SrcMacAddrFilter[MacByteIdx];
            MirrorConfigurationPtr->DstMacAddrFilter[MacByteIdx] = MirrorCfgBackup.DstMacAddrFilter[MacByteIdx];
        }
        MirrorConfigurationPtr->VlanIdFilter = MirrorCfgBackup.VlanIdFilter;
        MirrorConfigurationPtr->MirroringMode = MirrorCfgBackup.MirroringMode;
        MirrorConfigurationPtr->VlanId = MirrorCfgBackup.VlanId;
        MirrorConfigurationPtr->CapturePortIdx = MirrorCfgBackup.CapturePortIdx;
        MirrorConfigurationPtr->TrafficDirectionIngressBitMask = MirrorCfgBackup.TrafficDirectionIngressBitMask;
    }
    else        /* no mirror configuration exists */
    {
        for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
        {
            MirrorConfigurationPtr->SrcMacAddrFilter[MacByteIdx] = 0x0U;
            MirrorConfigurationPtr->DstMacAddrFilter[MacByteIdx] = 0x0U;
        }
        MirrorConfigurationPtr->VlanIdFilter = NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID;
        MirrorConfigurationPtr->MirroringMode = NETC_ETHSWT_NO_VLAN_RETAGGING;
        MirrorConfigurationPtr->VlanId = NETC_ETHSWT_IP_UINT16_NULL_ENTRY_ID;
        MirrorConfigurationPtr->CapturePortIdx = 0U;
        MirrorConfigurationPtr->TrafficDirectionIngressBitMask = 0x0UL;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_MainFunction
 * Description   : Periodically called function to age FDB entries
 * implements Netc_EthSwt_Ip_MainFunction_Activity
 *END**************************************************************************/
void Netc_EthSwt_Ip_MainFunction( uint8 SwitchIdx )
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_ResumeEntryEntryId ResumeEntryEntryId;
    boolean FoundEntry;
    uint32 HwAgingCount;
    float32 MainFunctionCycleSteps;
    float32 CalNumAgingCycle;
    float64 AgingTimeout;
    float32 mainPeriod;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    mainPeriod = (float32)NETC_ETHSWT_IP_MAIN_FUNCTION_PERIOD;

    /* Calculating the number of MAIN_FUNCTION_PERIOD we needed to skip to fit in the limited number of hardware steps the hardware aging counter can accommodate. */
    CalNumAgingCycle = (float32)Netc_EthSwt_Ip_FdbTableEntryTimeout[SwitchIdx];
    CalNumAgingCycle /= mainPeriod;
    if (CalNumAgingCycle < NETC_ETHSWT_IP_NUM_AGING_CYCLE_FLOAT)
    {
        /* The number of steps is 1 if we number of Netc_EthSwt_Ip_FdbTableEntryTimeout/NETC_ETHSWT_IP_MAIN_FUNCTION_PERIOD give us a Number of steps less than the number of steps the hardware can accommodate. */
        MainFunctionCycleSteps = NETC_ETHSWT_IP_ONE_FLOAT;
    }
    else
    {
        /* In the case there is not a sufficient number of steps in hardware, we skip a number of MAIN_FUNCTION_PERIOD before we increment the hardware aging counter.
           The number of skip cycle is deternimned by a round up of the number of steps we would like to have (Netc_EthSwt_Ip_FdbTableEntryTimeout/NETC_ETHSWT_IP_MAIN_FUNCTION_PERIOD)
           divided by the number of steps supported by hardware. Note that (Netc_EthSwt_Ip_FdbTableEntryTimeout/NETC_ETHSWT_IP_MAIN_FUNCTION_PERIOD) is padded to give a rounded up result. */
        /* Extract the number of funtion period */
        MainFunctionCycleSteps = (float32)(Netc_EthSwt_Ip_FdbTableEntryTimeout[SwitchIdx]);
        MainFunctionCycleSteps /= mainPeriod;
        /* Rounding up the number of aging cycles steps */
        MainFunctionCycleSteps += NETC_ETHSWT_IP_NUM_AGING_CYCLE_FLOAT - NETC_ETHSWT_IP_ONE_FLOAT;
        /* Extract the number of steps */
        MainFunctionCycleSteps /= NETC_ETHSWT_IP_NUM_AGING_CYCLE_FLOAT;
        /* Convert float32 to uint32, missing lroundf from C99 */
        if(MainFunctionCycleSteps <= NETC_ETHSWT_IP_ONE_FLOAT)
        {
            MainFunctionCycleSteps = (float32)NETC_ETHSWT_IP_ONE_FLOAT;
        }
    }
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_61();
    Netc_EthSwt_Ip_MainFunctionCycle[SwitchIdx]++;

    if(((float64)Netc_EthSwt_Ip_MainFunctionCycle[SwitchIdx]) >= (float64)MainFunctionCycleSteps)
    {
        /* Aging action */
        /* Activity update, ACT_CNT++ if no ACT_FLAG otherwise 0 */
        ResumeEntryEntryId.ResumeEntryId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;
        do
        {
            Status |= Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable(SwitchIdx, &ResumeEntryEntryId,  &HwAgingCount, &FoundEntry);
            if(((Std_ReturnType)E_OK == Status) && (TRUE == FoundEntry))
            {
                AgingTimeout = (float64)HwAgingCount;
                AgingTimeout *= (float64)MainFunctionCycleSteps;
                AgingTimeout *= (float64)mainPeriod;
                Netc_EthSwt_Ip_SearchAndAgeEntryInFdbTable_SecondPart(SwitchIdx, ResumeEntryEntryId, AgingTimeout, &Status);
            }
        } while (((Std_ReturnType)E_OK == Status)
          && ((uint32)NETC_ETHSWT_IP_BD_NULL_ENTRY_ID != ResumeEntryEntryId.ResumeEntryId) );
        Netc_EthSwt_Ip_MainFunctionCycle[SwitchIdx] = 0UL;
    }
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_61();

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetPruningMode
 * Description   : External function for setting the pruning mode for ports.
 * implements Netc_EthSwt_Ip_SetPruningMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetPruningMode(uint8 SwitchIdx, uint8 SwitchPortIdx, boolean PruningEnable)
{
    Std_ReturnType Status = E_OK;
    uint32 bridgePortConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void)SwitchIdx;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_59();

    /* read the BPCR configurate data first */
    bridgePortConfig = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->BPCR;

    /* Configure the pruning setting for the port */
    if (FALSE == PruningEnable)
    {
        bridgePortConfig |= SW_PORT0_BPCR_SRCPRND_MASK;
    }
    else
    {
        bridgePortConfig &= ~SW_PORT0_BPCR_SRCPRND_MASK;
    }

    /* write the BPCR configuration back */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->BPCR = bridgePortConfig;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_59();

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPruningMode
 * Description   : External function for getting the pruning mode of ports.
 * implements Netc_EthSwt_Ip_GetPruningMode_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPruningMode(uint8 SwitchIdx, uint8 SwitchPortIdx, boolean *PruningEnablePtr)
{
    Std_ReturnType Status = E_OK;
    uint32 bridgePortConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
    DevAssert(PruningEnablePtr != NULL_PTR);
#endif

    (void)SwitchIdx;

    /* read the BPCR configurate data first */
    bridgePortConfig = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->BPCR;

    /* get the pruning mode data for the port */
    *PruningEnablePtr = ((bridgePortConfig & SW_PORT0_BPCR_SRCPRND_MASK) == 0x0UL) ? TRUE : FALSE;

    return Status;
}

#if(NETC_ETHSWT_IP_CONFIG_LINK_PROTOCOL == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigLinkProtocol
 * Description   : External function for configuring the MII protocol for ethernet ports.
 *
 *END**************************************************************************/
static void Netc_EthSwt_Ip_ConfigLinkProtocol(uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType)
{
    uint32 Netcc1Reg;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    (void)SwitchIdx;

    if(SwitchPortIdx < NETC_ETHSWT_IP_NUMBER_OF_MAC_PORTS)
    {
        /* read NETCC1 register first */
        Netcc1Reg = IP_GPR1->NETCC1;

        /* modify the value for NETCC1 */
        if ((uint8)NETC_ETHSWT_PORT0 == SwitchPortIdx)     /* link 0 */
        {
            Netcc1Reg |= GPR1_NETCC1_LINK0MIIP(EthSwtPortPhysicalLayerType);
        }
        else if ((uint8)NETC_ETHSWT_PORT1 == SwitchPortIdx)    /* link 1 */
        {
            Netcc1Reg |= GPR1_NETCC1_LINK1MIIP(EthSwtPortPhysicalLayerType);
        }
        else
        {
            /* avoid MISRA violation */
        }

        /* write it back */
        IP_GPR1->NETCC1 = Netcc1Reg;
    }

}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConvertToPtpTime
 * Description   : Convert 64-bit clock value (ns) to PTP ptpTime (secondsHi,seconds, nanoseconds)
 *END**************************************************************************/
static void Netc_EthSwt_Ip_ConvertToPtpTime(const uint64 clk, Netc_EthSwt_Ip_PtpTimeType *ptpTime)
{
    uint64 seconds64;

    /* convert the ns to seconds */
    seconds64 = clk / 1000000000UL;
    ptpTime->seconds   = (uint32) seconds64;
    ptpTime->secondsHi = (uint16) (seconds64 >> 32U);

    /* convert the portion that is less than 1s to ns */
    ptpTime->nanoseconds = (uint32) (clk - (uint64) (seconds64 * 1000000000UL));

    return;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPtpTSClk
 * Description   : External function for getting current ptpTime of free running (ptpTime stamp) clock.
 * implements Netc_EthSwt_Ip_GetPtpTSClk_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPtpTSClk( uint8 SwitchIdx, Netc_EthSwt_Ip_PtpTimeType *PtpTime)
{
    Std_ReturnType Status = E_OK;
    volatile uint64 FreeRunningTicks;
    float64 clkFloat;
    uint64 clk;

    (void)SwitchIdx;

    if (TimerOriginalRefClk != 0x0UL)
    {
        /* Read free running time registers */
        FreeRunningTicks = Netc_EthSwt_Ip_TimerBase->TMR_FRT_L;      /* should read the Lower register first */
        FreeRunningTicks |= ((uint64)(Netc_EthSwt_Ip_TimerBase->TMR_FRT_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;

        /* Convert free running ticks to nano seconds */
        clkFloat = (float64)FreeRunningTicks * (((float64)1000000000U)/((float64)(TimerOriginalRefClk)));
        clk = (uint64)clkFloat;

        /* Convert ns time to PTP time */
        Netc_EthSwt_Ip_ConvertToPtpTime(clk, PtpTime);
    }
    else
    {
        Status = E_NOT_OK;      /* 1588 timer is not enabled. */
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPtpClk
 * Description   : External function for getting current ptpTime of corrected clock (PTP_CLK).
 * implements Netc_EthSwt_Ip_GetPtpClk_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPtpClk( uint8 SwitchIdx, Netc_EthSwt_Ip_PtpTimeType *PtpTime)
{
    Std_ReturnType Status = E_OK;
    volatile uint64 FreeRunningTicks;
    volatile uint64 CorrectedTime;

    (void)SwitchIdx;

    if (TimerRefClk != 0x0UL)
    {
        /* Read Timer synchronous time registers */
        FreeRunningTicks = Netc_EthSwt_Ip_TimerBase->TMR_FRT_L;      /* A read to TMR_FRT_L captures all 64b of FRT_H/L and 64b of SRT_H/L, for an atomic read of all 4 registers. */
        (void)FreeRunningTicks;                                /* The cast is necessary to avoid the compiler warning. The register read is needed in order to trigger an atomic read of all 4 timer registers. */
        CorrectedTime = Netc_EthSwt_Ip_TimerBase->TMR_SRT_L;
        CorrectedTime |= (((uint64)(Netc_EthSwt_Ip_TimerBase->TMR_SRT_H)) << NETC_ETHSWT_IP_32BIT_SHIFT);

        /* Convert ns time to PTP time */
        Netc_EthSwt_Ip_ConvertToPtpTime(CorrectedTime, PtpTime);
    }
    else
    {
        Status = E_NOT_OK;      /* 1588 timer is not enabled. */
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetPtpTimes
 * Description   : External function for retrieving an atomic snapshot of both clocks in the switch.
 * implements Netc_EthSwt_Ip_GetPtpTimes_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_GetPtpTimes( uint8 SwitchIdx, Netc_EthSwt_Ip_PtpTimeType *FreeRunTime, Netc_EthSwt_Ip_PtpTimeType *CorrTime)
{
    Std_ReturnType Status = E_OK;
    volatile uint64 FreeRunningTicks;
    volatile uint64 CorrectedTime;
    float64 clkFloat;
    uint64 clk;

    (void)SwitchIdx;

    if (TimerRefClk != 0x0UL)
    {
        /* A read to TMR_FRT_L captures all 64b of FRT_H/L and 64b of SRT_H/L, for an atomic read of all 4 registers. */
        FreeRunningTicks = Netc_EthSwt_Ip_TimerBase->TMR_FRT_L;
        FreeRunningTicks |= ((uint64)(Netc_EthSwt_Ip_TimerBase->TMR_FRT_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;
        CorrectedTime = Netc_EthSwt_Ip_TimerBase->TMR_SRT_L;
        CorrectedTime |= ((uint64)(Netc_EthSwt_Ip_TimerBase->TMR_SRT_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;

        /* Convert free running ticks to nano seconds */
        clkFloat = (float64)FreeRunningTicks * (((float64)1000000000U)/((float64)(TimerOriginalRefClk)));
        clk = (uint64)clkFloat;

        /* Convert free running ns time to PTP time */
        Netc_EthSwt_Ip_ConvertToPtpTime(clk, FreeRunTime);

        /* Convert synced ns time to PTP time */
        Netc_EthSwt_Ip_ConvertToPtpTime(CorrectedTime, CorrTime);
    }
    else
    {
        Status = E_NOT_OK;      /* 1588 timer is not enabled. */
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetPtpClkRatio
 * Description   : External function for adjusting the clock rate of the PTP clock.
 * implements Netc_EthSwt_Ip_SetPtpClkRatio_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetPtpClkRatio( uint8 SwitchIdx, uint32 ClkRatio )
{
    Std_ReturnType Status = E_OK;
    float64 ConvertedClkRatio;
    uint16 TimerClkPeriod;
    float64 ClkAddendData;
    uint32 TimerClkAddend;
    float64 TimerClkAddendRaw;
    uint32 TimerClkAddendRawInt;
    uint32 IntegerPortion;
    float64 FractionalPortion;
    uint32 ClkRatioTemp;
    float64 TimerRefClkFloat;

    (void)SwitchIdx;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_02();
    if (TimerRefClk != 0x0UL)
    {
        /* convert uint32 ClkRatio to a float */
        IntegerPortion = (uint32)((ClkRatio & 0x80000000U) >> 31U);
        ClkRatioTemp = ClkRatio & 0x7FFFFFFFUL;
        FractionalPortion = (float64)ClkRatioTemp/(float64)0x80000000UL;
        ConvertedClkRatio = (float64)((float64)IntegerPortion + FractionalPortion);

        /* modify the clock frequency */
        TimerRefClkFloat = ((float64)TimerRefClk) * (ConvertedClkRatio * (((float64)TimerOriginalRefClk)/((float64)(TimerRefClk))));
        TimerRefClk = ((uint32)TimerRefClkFloat);

        TimerClkPeriod = (uint16)(1000000000UL / TimerRefClk);                             /* the integer portion of timer clock period (1/f) */
        ClkAddendData = (((float64)1000000000UL) / ((float64)TimerRefClk)) - ((float64)TimerClkPeriod);
        TimerClkAddendRaw = (float64)(0x100000000UL) * ClkAddendData;
        TimerClkAddendRawInt = (uint32)TimerClkAddendRaw;
        TimerClkAddend = TimerClkAddendRawInt + ((TimerClkAddendRaw > (float64)TimerClkAddendRawInt) ? 1U : 0U);  /* the fractional part of the timer clock period. */

        /* Timer addend register holds the fractional part of the timer clock period */
        Netc_EthSwt_Ip_TimerBase->TMR_ADD = TMR0_BASE_TMR_ADD_ADDEND(TimerClkAddend);

        uint32 TMR_CTRL_temp = Netc_EthSwt_Ip_TimerBase->TMR_CTRL;
        /* clear CLK_PERIOD data field first */
        TMR_CTRL_temp &= ~TMR0_BASE_TMR_CTRL_TCLK_PERIOD(0x3FF);
        /* set new period */
        TMR_CTRL_temp |= TMR0_BASE_TMR_CTRL_TCLK_PERIOD(TimerClkPeriod);
        Netc_EthSwt_Ip_TimerBase->TMR_CTRL = TMR_CTRL_temp;
    }
    else
    {
        Status = E_NOT_OK;      /* 1588 timer is not enabled. */
    }
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_02();

    return Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_CorrectPtpClk
 * Description   : External function for adding/subtracting an offset to/from the corrected clock (PTP_CLK).
 * implements Netc_EthSwt_Ip_CorrectPtpClk_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_CorrectPtpClk( uint8 SwitchIdx, sint64 Offset )
{
    Std_ReturnType Status = E_OK;
    uint64 OriginOffset;
    uint64 NewOffset;

    (void)SwitchIdx;

    /* get the existing offset first */
    OriginOffset = Netc_EthSwt_Ip_TimerBase->TMROFF_L;
    OriginOffset |= (uint64)(Netc_EthSwt_Ip_TimerBase->TMROFF_H) << NETC_ETHSWT_IP_32BIT_SHIFT;

    /* modify the offset */
    NewOffset = OriginOffset + ((uint64) (Offset));    /* the offset could be positive or negative */

    /* write the new offset back */
    Netc_EthSwt_Ip_TimerBase->TMROFF_L = (uint32)NewOffset;
    Netc_EthSwt_Ip_TimerBase->TMROFF_H = (uint32)(NewOffset >> NETC_ETHSWT_IP_32BIT_SHIFT);

    return Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntry
 * Description   : Ethernet Switch Add or Update rate policer table entry function.Netc_EthSwt_Ip_ConvertToPtpTime
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntry( uint8 SwitchIdx,
                                                                               Netc_EthSwt_Ip_CommandsType Cmd,
                                                                               uint32 *MatchedEntries,
                                                                               const Netc_EthSwt_Ip_RatePolicerEntryDataType * RatePolicerTableEntry
                                                                             )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(RatePolicerTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and CFGEU, FEEU, ... flag */
        ActionsData = Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntryGetActionsData(RatePolicerTableEntry);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_03();
        Netc_EthSwt_Ip_AddOrUpdateRatePolicerTableEntryInitTableRequest(RatePolicerTableEntry, ActionsData);
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_03();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_RATE_POLICER_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;       /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_RATEPOLICERTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryRatePolicerTableEntry
 * Description   : Ethernet Switch query Rate policer table entry function.
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryRatePolicerTableEntry( uint8 SwitchIdx,
                                                                         uint32 *MatchedEntries,
                                                                         uint32 RatePolicerEntryId,
                                                                         Netc_EthSwt_Ip_RatePolicerEntryRspDataType * RatePolicerTableEntry
                                                                       )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(RatePolicerTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_13();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = RatePolicerEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_13();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_RATE_POLICER_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                     /* for query command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_RATEPOLICERTABLE_RSPBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            Netc_EthSwt_Ip_QueryRatePolicerTableEntry_FoundAMatchedEntry(RatePolicerTableEntry);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteRatePolicerTableEntry
 * Description   : Ethernet Switch delete Rate policer table entry function.
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteRatePolicerTableEntry( uint8 SwitchIdx,
                                                                          uint32 *MatchedEntries,
                                                                          uint32 RatePolicerEntryId
                                                                        )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_14();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = RatePolicerEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_14();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_RATE_POLICER_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);           /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateIngressStreamTableEntry
 * Description   : Ethernet Switch Add or Update ingress stream table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateIngressStreamTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressStreamTableEntry( uint8 SwitchIdx,
                                                                                 Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                 uint32 *MatchedEntries,
                                                                                 const Netc_EthSwt_Ip_IngressStreamEntryDataType * IngressStreamTableEntry
                                                                               )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(IngressStreamTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and CFGEU flag */
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_15();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = IngressStreamTableEntry->IngressStreamEntryId;        /* fill in Entry_ID field (Access Key) */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SFE((IngressStreamTableEntry->IngressStreamCfgeData.StreamFilteringEnable) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IPV(IngressStreamTableEntry->IngressStreamCfgeData.InternalPriorityValue) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OIPV((IngressStreamTableEntry->IngressStreamCfgeData.OverrideIPV) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_DR(IngressStreamTableEntry->IngressStreamCfgeData.DropResilience) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ODR((IngressStreamTableEntry->IngressStreamCfgeData.OverrideDR) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IMIRE((IngressStreamTableEntry->IngressStreamCfgeData.IngressMirroringEnable) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE((IngressStreamTableEntry->IngressStreamCfgeData.TimeStampCaptureEnable) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SPPD((IngressStreamTableEntry->IngressStreamCfgeData.SrcPortPruningDisable) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ISQA(IngressStreamTableEntry->IngressStreamCfgeData.IngressSeqAction) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_ORP((IngressStreamTableEntry->IngressStreamCfgeData.OverrideRatePolicerInstanceEID) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OSGI((IngressStreamTableEntry->IngressStreamCfgeData.OverrideStreamGateInstanceEID) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_HR(IngressStreamTableEntry->IngressStreamCfgeData.HostReason) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_FA(IngressStreamTableEntry->IngressStreamCfgeData.ForwardingActions) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE(IngressStreamTableEntry->IngressStreamCfgeData.SduType);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_MSDU(IngressStreamTableEntry->IngressStreamCfgeData.MaximumServiceDataUnit) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG(IngressStreamTableEntry->IngressStreamCfgeData.IngressFrmModiEntryFrmLenChange) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EPORT(IngressStreamTableEntry->IngressStreamCfgeData.EgressPort) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_OETEID(IngressStreamTableEntry->IngressStreamCfgeData.OverrideET_EID) \
                                                                                    | NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_CTD(IngressStreamTableEntry->IngressStreamCfgeData.CutThrDisable);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = IngressStreamTableEntry->IngressStreamCfgeData.IngressSeqGeneration_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = IngressStreamTableEntry->IngressStreamCfgeData.RatePolicer_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = IngressStreamTableEntry->IngressStreamCfgeData.StreamGateInstance_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA5] = IngressStreamTableEntry->IngressStreamCfgeData.IngressFrmModification_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA6] = IngressStreamTableEntry->IngressStreamCfgeData.EgressTreatment_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA7] = IngressStreamTableEntry->IngressStreamCfgeData.IngressStreamCounter_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA8] = NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP(IngressStreamTableEntry->IngressStreamCfgeData.EgressPortBitMap);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA9] = NETC_ETHSWT_IP_INGRESSSTREAMTABLE_CFGE_SIMAP(IngressStreamTableEntry->IngressStreamCfgeData.StationInterfaceMap);
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_15();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_TABLE_ID;
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;       /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSSTREAMTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryIngressStreamTableEntry
 * Description   : Ethernet Switch query Ingress Stream table entry function.
 * implements Netc_EthSwt_Ip_QueryIngressStreamTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressStreamTableEntry( uint8 SwitchIdx,
                                                                           uint32 *MatchedEntries,
                                                                           uint32 IngressStreamEntryId,
                                                                           Netc_EthSwt_Ip_IngressStreamEntryDataType * IngressStreamTableEntry
                                                                         )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressStreamTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_16();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = IngressStreamEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_16();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                     /* for query command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSSTREAMTABLE_RSPBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            Netc_EthSwt_Ip_QueryIngressStreamTableEntry_FoundAMatchedEntry(IngressStreamTableEntry);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteIngressStreamTableEntry
 * Description   : Ethernet Switch delete Ingress Stream table entry function.
 * implements Netc_EthSwt_Ip_DeleteIngressStreamTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressStreamTableEntry( uint8 SwitchIdx,
                                                                            uint32 *MatchedEntries,
                                                                            uint32 IngressStreamEntryId
                                                                          )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_17();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = IngressStreamEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_17();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);           /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateIngressStreamCountTableEntry
 * Description   : Ethernet Switch Add or Update ingress stream count table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateIngressStreamCountTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressStreamCountTableEntry( uint8 SwitchIdx,
                                                                                       Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                       uint32 *MatchedEntries,
                                                                                       uint32 IngressStreamCountId
                                                                                     )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and CFGEU flag */
        ActionsData = NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_18();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        /* fill in KEYE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD] = IngressStreamCountId;     /* fill in ISC_ID field */
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_18();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_COUNT_TABLE_ID;
        /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISCTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryIngressStreamCountTableEntry
 * Description   : Ethernet Switch query Ingress Stream Count table entry function.
 * implements Netc_EthSwt_Ip_QueryIngressStreamCountTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressStreamCountTableEntry( uint8 SwitchIdx,
                                                                         uint32 *MatchedEntries,
                                                                         uint32 IngressStreamCountEntryId,
                                                                         Netc_EthSwt_Ip_IngressStreamCountTableRspDataType * IngressStreamCountTableEntry
                                                                       )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressStreamCountTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_19();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;                      /* fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD] = IngressStreamCountEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_19();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_COUNT_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                     /* for query command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);    /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISCTABLE_RSPBUFFER_LEN);              /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_EthSwt_Ip_RatePolicerEntryDataType" structure with data in response data buffer */
            IngressStreamCountTableEntry->IngressStreamCountId = TableDataBuffer.TableDataField[0U];
            /* fill in STSE data */
            IngressStreamCountTableEntry->IngressStreamCountStseData.RxCount = TableDataBuffer.TableDataField[1U];
            IngressStreamCountTableEntry->IngressStreamCountStseData.MSduDropCount = TableDataBuffer.TableDataField[3U];
            IngressStreamCountTableEntry->IngressStreamCountStseData.PolicerDropCount = TableDataBuffer.TableDataField[5U];
            IngressStreamCountTableEntry->IngressStreamCountStseData.StreamGateDropCount = TableDataBuffer.TableDataField[7U];
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteIngressStreamCountTableEntry
 * Description   : Ethernet Switch delete Ingress Stream table entry function.
 * implements Netc_EthSwt_Ip_DeleteIngressStreamCountTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressStreamCountTableEntry( uint8 SwitchIdx,
                                                                                  uint32 *MatchedEntries,
                                                                                  uint32 IngressStreamCountId
                                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_20();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    /* fill in KEYE_DATA field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_INGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD] = IngressStreamCountId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_20();
    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_COUNT_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISCTABLE_RSPBUFFER_LEN);                 /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateIngressStreamFilterTableEntry
 * Description   : Ethernet Switch Add or Update ingress stream filter table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateIngressStreamFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                       Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                       uint32 *MatchedEntries,
                                                                                       const Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                     )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(IngressStreamFilterTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and CFGEU flag */
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);
        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_21();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        /* fill in KEYE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.IngressStream_EID;     /* fill in IS_EID field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.Pcp;                       /* fill in PCP field */
        /* fill in CFGE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV(IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.InternalPriorityValue) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV((IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideIPV) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR(IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.DropResilience) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR((IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideDR) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE((IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.IngressMirroringEnable) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE((IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.TimeStampCaptureEnable) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP((IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideRatePolicerInstanceEID) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI((IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.OverrideStreamGateInstanceEID) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE(IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.SduType) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD(IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.CutThrDisable) \
                                                                                    | NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU(IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.MaximumServiceDataUnit);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.RatePolicer_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.StreamGateInstance_EID;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = IngressStreamFilterTableEntry->IngressStreamFilterCfgeData.IngressStreamCounter_EID;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_21();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_FILTER_TABLE_ID;
        /* for Add and Update command, the Access Method should only be NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH */
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryIngressStreamFilterTableEntry
 * Description   : Ethernet Switch query Ingress Stream Filter table entry function.
 * implements Netc_EthSwt_Ip_QueryIngressStreamFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                 uint32 *MatchedEntries,
                                                                                 Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                               )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressStreamFilterTableEntry != NULL_PTR);
#endif
    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_22();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in KEYE_DATA field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.IngressStream_EID;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.Pcp;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_22();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_FILTER_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_OTHER_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_RSPBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            Netc_EthSwt_Ip_QueryIngressStreamFilterTableEntry_FoundAMatchedEntry(IngressStreamFilterTableEntry);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteIngressStreamFilterTableEntry
 * Description   : Ethernet Switch delete Ingress Stream table entry function.
 * implements Netc_EthSwt_Ip_DeleteIngressStreamFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                  uint32 *MatchedEntries,
                                                                                  const Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressStreamFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_23();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    /* fill in KEYE_DATA field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.IngressStream_EID;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = IngressStreamFilterTableEntry->IngressStreamFilterKeyeData.Pcp;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_23();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_FILTER_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;                      /* for delete command, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_OTHER_REQBUFFER_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);                 /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry
 * Description   : Ethernet Switch search Ingress Stream Filter table entry one by one.
 * implements Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry( uint8 SwitchIdx,
                                                                                  uint32 * ResumeEntryId,
                                                                                  uint32 * MatchedEntry,
                                                                                  Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(ResumeEntryId != NULL_PTR);
    DevAssert(MatchedEntry != NULL_PTR);
    DevAssert(IngressStreamFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntry first */
    *MatchedEntry = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_24();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in KEYE_DATA field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = *ResumeEntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_24();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_FILTER_TABLE_ID;
    /* query function with NETC_ETHSWT_SEARCH_METHOD method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_OTHER_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_RSPBUFFER_LEN);            /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntry);

        /* found a matched entry */
        if (1U == *MatchedEntry)
        {
            Netc_EthSwt_Ip_SearchIngressStreamFilterTableEntry_FoundAMatchedEntry(ResumeEntryId, IngressStreamFilterTableEntry);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SearchAndFillIngressStreamFilterTable
 * Description   : inline function for searching and filling Ingress Stream Filter table entries.
 *END**************************************************************************/
static inline Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SearchAndFillIngressStreamFilterTable( uint8 SwitchIdx,
                                                                                                  uint32 * ResumeEntryId,
                                                                                                  uint16 * NumOfExistingEntry,
                                                                                                  Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableEntry
                                                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint32 CfgeConfigBits;
    uint8 SduType;
    uint32 MatchedEntries = 0x0UL;
    uint8 TableMemIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(ResumeEntryId != NULL_PTR);
    DevAssert(IngressStreamFilterTableEntry != NULL_PTR);
#endif

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_25();

    /* clear the memory for searching, otherwise will get 0x89 error code */
    for (TableMemIdx = (uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD; TableMemIdx <= (uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA9; TableMemIdx++)
    {
        TableDataBuffer.TableDataField[TableMemIdx] = 0U;
    }

    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in KEYE_DATA field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = *ResumeEntryId;

    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_25();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_FILTER_TABLE_ID;
    /* query function with NETC_ETHSWT_SEARCH_METHOD method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_OTHER_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISFILTERTABLE_RSPBUFFER_LEN);            /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &MatchedEntries);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeEntryId = TableDataBuffer.TableDataField[0U];

        /* ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED */
        /* found a matched entry */
        if ((1U == MatchedEntries) && (*ResumeEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
            /* fill in "Netc_EthSwt_Ip_IngressStreamFilterEntryDataType" structure with data in response data buffer */
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterEntryId = TableDataBuffer.TableDataField[1U];
            /* fill in KEYE_DATA */
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterKeyeData.IngressStream_EID = TableDataBuffer.TableDataField[2U];
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterKeyeData.Pcp = (uint8)(TableDataBuffer.TableDataField[3U] & NETC_ETHSWT_IP_ISFILTERTABLE_KEYE_PCP_MASK);
            /* fill in CFGE data */
            CfgeConfigBits = TableDataBuffer.TableDataField[4U];
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.InternalPriorityValue = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IPV_SHIFT);
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.OverrideIPV = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OIPV_SHIFT) > 0U) ? TRUE : FALSE;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.DropResilience = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_DR_SHIFT);
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.OverrideDR = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ODR_SHIFT) > 0U) ? TRUE : FALSE;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.IngressMirroringEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_IMIRE_SHIFT) > 0U) ? TRUE : FALSE;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.TimeStampCaptureEnable = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_TIMECAPE_SHIFT) > 0U) ? TRUE : FALSE;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.OverrideRatePolicerInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_ORP_SHIFT) > 0U) ? TRUE : FALSE;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.OverrideStreamGateInstanceEID = (((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_OSGI_SHIFT) > 0U) ? TRUE : FALSE;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.CutThrDisable = (CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_CTD_SHIFT;
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.MaximumServiceDataUnit = (uint16)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_MSDU_SHIFT);

            SduType = (uint8)((CfgeConfigBits & NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_MASK) >> NETC_ETHSWT_IP_ISFILTERTABLE_CFGE_SDUTYPE_SHIFT);
            switch (SduType)
            {
                case 0U:
                    IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_PPDU;
                    break;
                case 1U:
                    IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_MPDU;
                    break;
                case 2U:
                    IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_MSDU;
                    break;
                default:
                    IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.SduType = NETC_ETHSWT_IP_RSDTYPE;
                    break;
            }

            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.RatePolicer_EID = TableDataBuffer.TableDataField[5U];
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.StreamGateInstance_EID = TableDataBuffer.TableDataField[6U];
            IngressStreamFilterTableEntry[*NumOfExistingEntry].IngressStreamFilterCfgeData.IngressStreamCounter_EID = TableDataBuffer.TableDataField[7U];

            /* increase the NumOfExistingEntry */
            (*NumOfExistingEntry) += 1U;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetIngressStreamFilterTable
 * Description   : Ethernet Switch get ingress stream filter table function.
 * implements Netc_EthSwt_Ip_GetIngressStreamFilterTable_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_GetIngressStreamFilterTable( uint8 SwitchIdx,
                                                                          uint16 * NumberOfElements,
                                                                          Netc_EthSwt_Ip_IngressStreamFilterEntryDataType * IngressStreamFilterTableList
                                                                        )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint16 NumOfExistingEntry = 0U;
    uint32 ResumeId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;

    /* [notes]: we will have to read entries one by one because of the errata ERR051048.
     - ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED
     - Description: The NUM_MATCHED field in the command NTMP response header may be incorrect when
       the search access method is used for the following tables: FDB table 15, L2 IPv4 Multicast
       Filter table 16, VLAN Filter table 18, Ingress Stream Identification table 30, or Ingress Stream
       Filter table 32.
     - Workaround: For the query command, limit the message response buffer size (RESPONSE_LENGTH field in the request header)
       so that NETC returns no more than one entry at a time. Under this condition, the NUM_MATCHED field value is correct
    */

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(NumberOfElements != NULL_PTR);
    DevAssert(*NumberOfElements != 0U);
    DevAssert(IngressStreamFilterTableList != NULL_PTR);
#endif

    do
    {
        /* check if the IngressStreamFilterTableList is full or we get all existing entries */
        if ((NumOfExistingEntry >= *NumberOfElements) || (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != status))
        {
            break;
        }

        status = Netc_EthSwt_Ip_SearchAndFillIngressStreamFilterTable(SwitchIdx, &ResumeId, &NumOfExistingEntry, IngressStreamFilterTableList);

    } while (ResumeId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID);      /* ResumeId == NETC_ETHSWT_IP_BD_NULL_ENTRY_ID means the query operation is completed */

    /* return the Number of elements which are currently available in the EthSwitch module or number of elements copied to IngressStreamFilterTableList*/
    *NumberOfElements = NumOfExistingEntry;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateStreamGateInstanceTableEntry
 * Description   : Ethernet Switch Add or Update Stream Gate Instance table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateStreamGateInstanceTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateStreamGateInstanceTableEntry( uint8 SwitchIdx,
                                                                                      Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                      uint32 *MatchedEntries,
                                                                                      const Netc_EthSwt_Ip_StreamGateInstanceEntryDataType * StreamGateInstanceTableEntry
                                                                                    )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(StreamGateInstanceTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and update actions*/
        ActionsData = NETC_ETHSWT_IP_SGITABLE_REQFMT_ACFGEU(1U) \
                    | NETC_ETHSWT_IP_SGITABLE_REQFMT_CFGEU(1U) \
                    | NETC_ETHSWT_IP_SGITABLE_REQFMT_SGISEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_26();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        /* fill in KEYE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = StreamGateInstanceTableEntry->SGIEntryId;     /* fill in Entry_ID */
        /* fill in ACFGE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = StreamGateInstanceTableEntry->AdminSGCLEntryId;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = (uint32)(StreamGateInstanceTableEntry->AdminBaseTime & 0xFFFFFFFFUL);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = (uint32)(StreamGateInstanceTableEntry->AdminBaseTime >> NETC_ETHSWT_IP_32BIT_SHIFT);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = StreamGateInstanceTableEntry->AdminCycleTimeExt;
        /* fill in CFGE_DATA and ICFGE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = (NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN(StreamGateInstanceTableEntry->Cfge_Oexen ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN(StreamGateInstanceTableEntry->Cfge_Irxen ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE(StreamGateInstanceTableEntry->SduType) \
                                                                                    | (NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV(StreamGateInstanceTableEntry->Icfge_Ipv) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                                                                                    | (NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV(StreamGateInstanceTableEntry->Icfge_Oipv ? 1U : 0U) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                                                                                    | (NETC_ETHSWT_IP_SGITABLE_ICFGE_GST(StreamGateInstanceTableEntry->Icfge_Gst) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                                                                                    | (NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD(StreamGateInstanceTableEntry->Icfge_Ctd ? 1U : 0U) << NETC_ETHSWT_IP_8BIT_SHIFT)) & 0xFFFFU;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_26();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_STREAM_GATE_INSTANCE_TABLE_ID;
        /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_SGITABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryStreamGateInstanceTableEntry
 * Description   : Ethernet Switch query Ingress Stream Filter table entry function.
 * implements Netc_EthSwt_Ip_QueryStreamGateInstanceTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryStreamGateInstanceTableEntry( uint8 SwitchIdx,
                                                                                uint32 *MatchedEntries,
                                                                                uint32 SGIEntryId,
                                                                                Netc_EthSwt_Ip_StreamGateInstanceEntryRspDataType * SGITableEntryRspData
                                                                              )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint32 ConfigBits;
    uint8 SduType;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(SGITableEntryRspData != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_27();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in ACCESS_KEY field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = SGIEntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_27();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_STREAM_GATE_INSTANCE_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_SGITABLE_RSPBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_EthSwt_Ip_StreamGateInstanceEntryRspDataType" structure with data in response data buffer */
            SGITableEntryRspData->SGIEntryId = TableDataBuffer.TableDataField[0U];
            /* fill in SGISE_DATA */
            SGITableEntryRspData->OperationalSGCLEntryID = TableDataBuffer.TableDataField[1U];
            SGITableEntryRspData->ConfigChangeTime = ((uint64)(TableDataBuffer.TableDataField[3U]) << NETC_ETHSWT_IP_32BIT_SHIFT);
            SGITableEntryRspData->ConfigChangeTime |= (uint64)(TableDataBuffer.TableDataField[2U]);
            SGITableEntryRspData->OperationalBaseTime = ((uint64)(TableDataBuffer.TableDataField[5U]) << NETC_ETHSWT_IP_32BIT_SHIFT);
            SGITableEntryRspData->OperationalBaseTime |= (uint64)(TableDataBuffer.TableDataField[4U]);
            SGITableEntryRspData->OperationalCycleTimeExt = TableDataBuffer.TableDataField[6U];
            ConfigBits = TableDataBuffer.TableDataField[7U];
            SGITableEntryRspData->SGISEOex = (uint8)(ConfigBits & NETC_ETHSWT_IP_SGITABLE_SGISE_OEX_MASK);
            SGITableEntryRspData->SGISEIrx = (uint8)((ConfigBits & NETC_ETHSWT_IP_SGITABLE_SGISE_IRX_MASK) >> NETC_ETHSWT_IP_SGITABLE_SGISE_IRX_SHIFT);
            SGITableEntryRspData->SGISEState = (uint8)((ConfigBits & NETC_ETHSWT_IP_SGITABLE_SGISE_STATE_MASK) >> NETC_ETHSWT_IP_SGITABLE_SGISE_STATE_SHIFT);

            /* fill in CFGE data */
            ConfigBits = TableDataBuffer.TableDataField[7U] >> NETC_ETHSWT_IP_8BIT_SHIFT;
            SGITableEntryRspData->Cfge_Oexen = ((ConfigBits & NETC_ETHSWT_IP_SGITABLE_CFGE_OEXEN_MASK) == 0U) ? FALSE : TRUE;
            SGITableEntryRspData->Cfge_Irxen = ((ConfigBits & NETC_ETHSWT_IP_SGITABLE_CFGE_IRXEN_MASK) == 0U) ? FALSE : TRUE;
            SduType = (uint8)((ConfigBits & NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE_MASK) >> NETC_ETHSWT_IP_SGITABLE_CFGE_SDUTYPE_SHIFT);
            switch (SduType)
            {
                case 0U:
                    SGITableEntryRspData->SduType = NETC_ETHSWT_IP_PPDU;
                    break;
                case 1U:
                    SGITableEntryRspData->SduType = NETC_ETHSWT_IP_MPDU;
                    break;
                case 2U:
                    SGITableEntryRspData->SduType = NETC_ETHSWT_IP_MSDU;
                    break;
                default:
                    SGITableEntryRspData->SduType = NETC_ETHSWT_IP_RSDTYPE;
                    break;
            }

            /* fill in ICFGE data */
            ConfigBits = TableDataBuffer.TableDataField[7U] >> NETC_ETHSWT_IP_16BIT_SHIFT;
            SGITableEntryRspData->Icfge_Ipv = (uint8)(ConfigBits & NETC_ETHSWT_IP_SGITABLE_ICFGE_IPV_MASK);
            SGITableEntryRspData->Icfge_Oipv = ((ConfigBits & NETC_ETHSWT_IP_SGITABLE_ICFGE_OIPV_MASK) == 0U) ? FALSE : TRUE;
            SGITableEntryRspData->Icfge_Gst = (ConfigBits & NETC_ETHSWT_IP_SGITABLE_ICFGE_GST_MASK) >> NETC_ETHSWT_IP_SGITABLE_ICFGE_GST_SHIFT;
            SGITableEntryRspData->Icfge_Ctd = ((ConfigBits & NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD_MASK) >> NETC_ETHSWT_IP_SGITABLE_ICFGE_CTD_SHIFT)!=0U;

            /* fill in ACFGE data */
            SGITableEntryRspData->AdminSGCLEntryId = TableDataBuffer.TableDataField[8U];
            SGITableEntryRspData->AdminBaseTime = (((uint64)(TableDataBuffer.TableDataField[10U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            SGITableEntryRspData->AdminBaseTime |= (uint64)(TableDataBuffer.TableDataField[9U]);
            SGITableEntryRspData->AdminCycleTimeExt = TableDataBuffer.TableDataField[11U];
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteStreamGateInstanceTableEntry
 * Description   : Ethernet Switch delete Stream Gate Instance table entry function.
 * implements Netc_EthSwt_Ip_DeleteStreamGateInstanceTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteStreamGateInstanceTableEntry( uint8 SwitchIdx,
                                                                                 uint32 *MatchedEntries,
                                                                                 uint32 SGIEntryId
                                                                               )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_28();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = SGIEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_28();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_STREAM_GATE_INSTANCE_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);           /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddStreamGateControlListTableEntry
 * Description   : Ethernet Switch Add Stream Gate Control List table entry function.
 * implements Netc_EthSwt_Ip_AddStreamGateControlListTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddStreamGateControlListTableEntry( uint8 SwitchIdx,
                                                                                 Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                 uint32 *MatchedEntries,
                                                                                 const Netc_EthSwt_Ip_SGCLTableDataType * SGCLTableEntry
                                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SGCLTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
    if (SGCLTableEntry->Cfge_ListLength > 0U)
    {
        DevAssert(SGCLTableEntry->ListEntries != NULL_PTR);
    }
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add commands */
    if (NETC_ETHSWT_ADD_CMD != Cmd)
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version*/
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_29();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        /* fill in ACCESS_KEY */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = SGCLTableEntry->SGCLEntryId;     /* fill in Entry_ID */
        /* fill in CFGE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = SGCLTableEntry->Cfge_CycleTime;
        /* Software must set LIST_LENGTH to N-1, where N is the size of the list being configured LIST_LENGTH=(N-1). will do it reversely when querying */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = NETC_ETHSWT_IP_SGCLTABLE_CFGE_LISTLEN((uint8)(SGCLTableEntry->Cfge_ListLength - 1U)) \
                                                                                    | NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTOIPV((SGCLTableEntry->Cfge_ExtOIPV) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTIPV(SGCLTableEntry->Cfge_ExtIpv) \
                                                                                    | NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTCTD((SGCLTableEntry->Cfge_ExtCtd) ? 1U : 0U) \
                                                                                    | NETC_ETHSWT_IP_SGCLTABLE_CFGE_EXTGTST(SGCLTableEntry->Cfge_ExtGtst);

        /* fill in list entries data */
        Netc_EthSwt_Ip_AddStreamGateControlListTableEntry_FillListEntriesData(SGCLTableEntry);
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_29();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_STREAM_GATE_CTRL_LIST_TABLE_ID;
        /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        /* the request and response data buffer length are variable based on the length of control list*/
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (uint16)((uint8)(16U + (8U * SGCLTableEntry->Cfge_ListLength)));
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry
 * Description   : Ethernet Switch query Ingress Stream Control List table entry function.
 * implements Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry( uint8 SwitchIdx,
                                                                                   uint32 *MatchedEntries,
                                                                                   uint32 SGCLEntryId,
                                                                                   uint8 ListLen,
                                                                                   Netc_EthSwt_Ip_SGCLTableDataType * SGCLTableEntryRspData
                                                                                 )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(SGCLTableEntryRspData != NULL_PTR);
    if (ListLen > 0U)
    {
        DevAssert(SGCLTableEntryRspData->ListEntries != NULL_PTR);
    }
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_30();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in ACCESS_KEY field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = SGCLEntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_30();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_STREAM_GATE_CTRL_LIST_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (uint16)((uint8)(16U + (8U * ListLen)));           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            Netc_EthSwt_Ip_QueryStreamGateControlListTableEntry_FoundAMatchedEntry(SGCLTableEntryRspData);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteStreamGateControlListTableEntry
 * Description   : Ethernet Switch delete Stream Gate Instance table entry function.
 * implements Netc_EthSwt_Ip_DeleteStreamGateControlListTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteStreamGateControlListTableEntry( uint8 SwitchIdx,
                                                                                    uint32 *MatchedEntries,
                                                                                    uint32 SGCLEntryId
                                                                                  )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_31();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = SGCLEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_31();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_STREAM_GATE_CTRL_LIST_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);           /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateIngressSeqGenerationTableEntry
 * Description   : Ethernet Switch Add or Update Ingress Sequence Generation table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateIngressSeqGenerationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngressSeqGenerationTableEntry( uint8 SwitchIdx,
                                                                                        Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                        uint32 *MatchedEntries,
                                                                                        const Netc_EthSwt_Ip_ISQGTableDataType * ISQGTableEntry
                                                                                      )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(ISQGTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and update actions*/
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U) \
                    | NETC_ETHSWT_IP_ISQGTABLE_REQFMT_ACTIONS_FIELD_SGSEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_32();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        /* fill in KEYE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = ISQGTableEntry->ISQGEntryId;     /* fill in Entry_ID */
        /* fill in ACFGE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = ISQGTableEntry->Cfge_SQTagType;
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_32();

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_SEQ_GENERATION_TABLE_ID;
        /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISQGTABLE_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryIngressSeqGenerationTableEntry
 * Description   : Ethernet Switch query Ingress Sequence Generation table entry function.
 * implements Netc_EthSwt_Ip_QueryIngressSeqGenerationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngressSeqGenerationTableEntry( uint8 SwitchIdx,
                                                                                  uint32 *MatchedEntries,
                                                                                  uint32 ISQGEntryId,
                                                                                  Netc_EthSwt_Ip_ISQGTableDataType * ISQGRspData
                                                                                )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint32 ConfigBits;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(ISQGRspData != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_33();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in ACCESS_KEY field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = ISQGEntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_33();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_SEQ_GENERATION_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISQGTABLE_RSPBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_EthSwt_Ip_ISQGTableDataType" structure with data in response data buffer */
            ISQGRspData->ISQGEntryId = TableDataBuffer.TableDataField[0U];

            /* fill in CFGE data */
            ConfigBits = TableDataBuffer.TableDataField[1U];
            ISQGRspData->Cfge_SQTagType = (ConfigBits & NETC_ETHSWT_IP_ISQGTABLE_CFGE_SQTAG_MASK);
            ISQGRspData->Sgse_SQGNum = (uint16)((ConfigBits >> NETC_ETHSWT_IP_16BIT_SHIFT) & 0xFFFFU);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteIngressSeqGenerationTableEntry
 * implements Netc_EthSwt_Ip_DeleteIngressSeqGenerationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngressSeqGenerationTableEntry( uint8 SwitchIdx,
                                                                                   uint32 *MatchedEntries,
                                                                                   uint32 ISQGEntryId
                                                                                 )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_34();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = ISQGEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_34();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_SEQ_GENERATION_TABLE_ID;
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);           /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_UpdateEgressSeqRecoveryTableEntry
 * Description   : Ethernet Switch Add or Update Ingress Sequence Generation table entry function.
 * implements Netc_EthSwt_Ip_UpdateEgressSeqRecoveryTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_UpdateEgressSeqRecoveryTableEntry( uint8 SwitchIdx,
                                                                                uint32 *MatchedEntries,
                                                                                const Netc_EthSwt_Ip_EgrSeqRecoveryTableDataType * EgrSQRTableEntry
                                                                              )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(EgrSQRTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* set table version and update actions*/
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U) \
                | NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_STSEU(1U) \
                | NETC_ETHSWT_IP_ESQRTABLE_REQFMT_ACTIONS_FIELD_SRSEU(1U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_35();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in ACCESS_KEY */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EgrSQRTableEntry->EgrSeqRecEntryId;     /* fill in Entry_ID */
    /* fill in CFGE_DATA */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG(EgrSQRTableEntry->Cfge_SQTag) \
                                                                                | NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ(EgrSQRTableEntry->Cfge_SqrTnsq) \
                                                                                | NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG(EgrSQRTableEntry->Cfge_SqrAlg) \
                                                                                | NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE(EgrSQRTableEntry->Cfge_SqrType) \
                                                                                | NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL(EgrSQRTableEntry->Cfge_SQRHisLen) \
                                                                                | NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL(EgrSQRTableEntry->Cfge_SQRFutureWinLen);
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP(EgrSQRTableEntry->Cfge_SQRTimeOutPeriod);
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_35();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_SEQ_RECOVERY_TABLE_ID;
    /* for Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_UPDATE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_EGRSQRTABLE_REQBUFFER_LEN);
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryEgressSeqRecoveryTableEntry
 * Description   : Ethernet Switch query Ingress Sequence Generation table entry function.
 * implements Netc_EthSwt_Ip_QueryEgressSeqRecoveryTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryEgressSeqRecoveryTableEntry( uint8 SwitchIdx,
                                                                               uint32 *MatchedEntries,
                                                                               uint32 ESQREntryId,
                                                                               Netc_EthSwt_Ip_EgrSeqRecoveryTableRspDataType * ESQRRspData
                                                                             )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint32 ConfigBits;
    uint8 HisIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(ESQRRspData != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_36();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in ACCESS_KEY field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = ESQREntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_36();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_EGRESS_SEQ_RECOVERY_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_ENTRY_ID_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_EGRSQRTABLE_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_EGRSQRTABLE_RSPBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_EthSwt_Ip_EgrSeqRecoveryTableRspDataType" structure with data in response data buffer */
            ESQRRspData->EgrSeqRecEntryId = TableDataBuffer.TableDataField[0U];

            /* fill in STSE_DATA */
            ESQRRspData->Stse_InOrderPkts = (((uint64)(TableDataBuffer.TableDataField[2U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            ESQRRspData->Stse_InOrderPkts |= (uint64)(TableDataBuffer.TableDataField[1U]);
            ESQRRspData->Stse_OutOfOrderPkts = (((uint64)(TableDataBuffer.TableDataField[4U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            ESQRRspData->Stse_OutOfOrderPkts |= (uint64)(TableDataBuffer.TableDataField[3U]);
            ESQRRspData->Stse_RoguePkts = (((uint64)(TableDataBuffer.TableDataField[6U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            ESQRRspData->Stse_RoguePkts |= (uint64)(TableDataBuffer.TableDataField[5U]);
            ESQRRspData->Stse_DuplicatePkts = (((uint64)(TableDataBuffer.TableDataField[8U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            ESQRRspData->Stse_DuplicatePkts |= (uint64)(TableDataBuffer.TableDataField[7U]);
            ESQRRspData->Stse_LostPkts = (((uint64)(TableDataBuffer.TableDataField[10U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            ESQRRspData->Stse_LostPkts |= (uint64)(TableDataBuffer.TableDataField[9U]);
            ESQRRspData->Stse_TaglessPkts = (((uint64)(TableDataBuffer.TableDataField[12U])) << NETC_ETHSWT_IP_32BIT_SHIFT);
            ESQRRspData->Stse_TaglessPkts |= (uint64)(TableDataBuffer.TableDataField[11U]);
            ESQRRspData->Stse_SeqRecResets = TableDataBuffer.TableDataField[13U];

            /* fill in CFGE data */
            ConfigBits = TableDataBuffer.TableDataField[14U];
            ESQRRspData->Cfge_SQTag = (uint8)(ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQTAG_MASK);
            ESQRRspData->Cfge_SqrTnsq = (ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTNSQ_SHIFT;
            ESQRRspData->Cfge_SqrAlg = (ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRALG_SHIFT;
            ESQRRspData->Cfge_SqrType = (ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTYPE_SHIFT;
            ESQRRspData->Cfge_SQRHisLen = (uint8)((ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRHL_SHIFT);
            ESQRRspData->Cfge_SQRFutureWinLen = (uint16)((ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRFWL_SHIFT);
            ESQRRspData->Cfge_SQRTimeOutPeriod = (uint16)(TableDataBuffer.TableDataField[15U] & NETC_ETHSWT_IP_EGRSQRTABLE_CFGE_SQRTP_MASK);

            /* fill in SRSE data */
            ConfigBits = TableDataBuffer.TableDataField[16U];
            ESQRRspData->Srse_SqrNum = (uint16)(ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRNUM_MASK);
            ESQRRspData->Srse_TakeAny = (uint8)((ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_TAKEANY_SHIFT);
            ESQRRspData->Srse_LostCntEnable = ((ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_LCE_MASK) == 0U) ? FALSE : TRUE;
            ESQRRspData->Srse_SqrTimeStamp = (uint16)((ConfigBits & NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS_MASK) >> NETC_ETHSWT_IP_EGRSQRTABLE_SRSE_SQRTS_SHIFT);

            for (HisIdx = 0U; HisIdx < 4U; HisIdx++)
            {
                ESQRRspData->Srse_SqrHistory[HisIdx] = TableDataBuffer.TableDataField[17U + HisIdx];
            }
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateIngrStreamIdentificationTableEntry
 * Description   : Ethernet Switch Add or Update Ingress Stream Identification table entry function.
 * implements Netc_EthSwt_Ip_AddOrUpdateIngrStreamIdentificationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateIngrStreamIdentificationTableEntry( uint8 SwitchIdx,
                                                                                            Netc_EthSwt_Ip_CommandsType Cmd,
                                                                                            uint32 *MatchedEntries,
                                                                                            const Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                          )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint8 FrmKeyIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(ISITableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* set table version and update actions*/
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U) \
                    | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_37();
        /* ------initialize the table request data buffer------ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        /* fill in KEYE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE(ISITableEntry->Keye_Keytype) \
                                                                                        | NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID(ISITableEntry->Keye_SrcPortId) \
                                                                                        | NETC_ETHSWT_IP_ISITABLE_KEYE_SPM(ISITableEntry->Keye_Spm);
        SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_37();

        for (FrmKeyIdx = 0U; FrmKeyIdx < 4U; FrmKeyIdx++)
        {
            TableDataBuffer.TableDataField[(uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0 + FrmKeyIdx] = ISITableEntry->Keye_FrmKey[FrmKeyIdx];    /* [Ricky]TODO: need to check the data format, big endian */
        }
        /* fill in CFGE_DATA */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = ISITableEntry->IngrStreamEntryId;     /* IS_EID */

        /* fill in operation data for config field of Request Header*/
        Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_IDEN_TABLE_ID;
        /* for Add and Update command, the Access Method should only be NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH */
        Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
        Netc_EthSwt_Ip_OperationData.Cmd = Cmd;
        Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISITABLE_ADD_REQBUFFER_LEN);
        Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
        #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
        {
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        {
        #endif
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_QueryIngrStreamIdentificationTableEntry
 * Description   : Ethernet Switch query Ingress Stream Identification table entry function.
 * implements Netc_EthSwt_Ip_QueryIngrStreamIdentificationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_QueryIngrStreamIdentificationTableEntry( uint8 SwitchIdx,
                                                                                      uint32 *MatchedEntries,
                                                                                      Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                    )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint32 ConfigBits;
    uint8 FrmKeyIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(ISITableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_38();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in KEYE_DATA */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE(ISITableEntry->Keye_Keytype) \
                                                                                    | NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID(ISITableEntry->Keye_SrcPortId) \
                                                                                    | NETC_ETHSWT_IP_ISITABLE_KEYE_SPM(ISITableEntry->Keye_Spm);
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_38();

    for (FrmKeyIdx = 0U; FrmKeyIdx < 4U; FrmKeyIdx++)
    {
        TableDataBuffer.TableDataField[(uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0 + FrmKeyIdx] = ISITableEntry->Keye_FrmKey[FrmKeyIdx];    /* [Ricky]TODO: need to check the data format, big endian */
    }

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_IDEN_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISITABLE_QUERY_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISITABLE_RSQBUFFER_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_EthSwt_Ip_IngrStremIdentificationTableDataType" structure with data in response data buffer */
            ISITableEntry->IngrStreamIdenEntryId = TableDataBuffer.TableDataField[1U];

            /* fill in KEYE data */
            ConfigBits = TableDataBuffer.TableDataField[2U];
            ISITableEntry->Keye_Keytype = (ConfigBits & NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE_MASK);
            ISITableEntry->Keye_SrcPortId = (uint8)((ConfigBits & NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_MASK) >> NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_SHIFT);
            ISITableEntry->Keye_Spm = (ConfigBits & NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_MASK) >> NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_SHIFT;

            for (FrmKeyIdx = 0U; FrmKeyIdx < 4U; FrmKeyIdx++)
            {
                ISITableEntry->Keye_FrmKey[FrmKeyIdx] = TableDataBuffer.TableDataField[3U + FrmKeyIdx];
            }

            /* fill in CFGE data */
            ISITableEntry->IngrStreamEntryId = TableDataBuffer.TableDataField[7U];
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_DeleteIngrStreamIdentificationTableEntry
 * Description   : Ethernet Switch delete Ingress Stream Identification table entry function.
 * implements Netc_EthSwt_Ip_DeleteIngrStreamIdentificationTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_DeleteIngrStreamIdentificationTableEntry( uint8 SwitchIdx,
                                                                                       uint32 *MatchedEntries,
                                                                                       const Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                     )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData = 0U;
    uint8 FrmKeyIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(ISITableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_39();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in KEYE_DATA */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE(ISITableEntry->Keye_Keytype) \
                                                                                    | NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID(ISITableEntry->Keye_SrcPortId) \
                                                                                    | NETC_ETHSWT_IP_ISITABLE_KEYE_SPM(ISITableEntry->Keye_Spm);
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_39();

    for (FrmKeyIdx = 0U; FrmKeyIdx < 4U; FrmKeyIdx++)
    {
        TableDataBuffer.TableDataField[(uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0 + FrmKeyIdx] = ISITableEntry->Keye_FrmKey[FrmKeyIdx];    /* [Ricky]TODO: need to check the data format, big endian */
    }

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_IDEN_TABLE_ID;
    /* for query function, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISITABLE_QUERY_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);           /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
            #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
            #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
            #endif
        #else
        if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
        #endif
        {
            status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SearchAndFillIngrStreamIdentificationTable
 * Description   : inline function for searching and filling Ingress Stream Filter table entries.
 *END**************************************************************************/
static inline Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SearchAndFillIngrStreamIdentificationTable( uint8 SwitchIdx,
                                                                                                       uint32 * ResumeEntryId,
                                                                                                       uint16 * NumOfExistingEntry,
                                                                                                       Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                                     )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;
    uint32 ConfigBits;
    uint32 MatchedEntries = 0x0UL;
    uint8 FrmKeyIdx;
    uint8 TableMemIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(ResumeEntryId != NULL_PTR);
    DevAssert(ISITableEntry != NULL_PTR);
#endif

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_40();
    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    /* fill in KEYE_DATA field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = *ResumeEntryId;
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_40();

    /* clear the memory for searching, otherwise will get 0x89 error code */
    for (TableMemIdx = 0U; TableMemIdx < 6U; TableMemIdx++)
    {
        TableDataBuffer.TableDataField[(uint8)NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0 + TableMemIdx] = 0U;
    }

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_INGRESS_STREAM_IDEN_TABLE_ID;
    /* query function with NETC_ETHSWT_SEARCH_METHOD method */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = (NETC_ETHSWT_IP_ISITABLE_QUERY_REQBUFFER_LEN);     /* set request data buffer length */
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_ISITABLE_RSQBUFFER_LEN);            /* set response data buffer length */

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
    #if defined(ERR_IPV_NETC_051243)
        #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
    {
        #endif
    #else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
    {
    #endif
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &MatchedEntries);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeEntryId = TableDataBuffer.TableDataField[0U];

        /* ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED */
        /* found a matched entry */
        if ((1U == MatchedEntries) && (*ResumeEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
            /* fill in "Netc_EthSwt_Ip_IngrStremIdentificationTableDataType" structure with data in response data buffer */
            ISITableEntry[*NumOfExistingEntry].IngrStreamIdenEntryId = TableDataBuffer.TableDataField[1U];

            /* fill in KEYE data */
            ConfigBits = TableDataBuffer.TableDataField[2U];
            ISITableEntry[*NumOfExistingEntry].Keye_Keytype = (ConfigBits & NETC_ETHSWT_IP_ISITABLE_KEYE_KEYTYPE_MASK);
            ISITableEntry[*NumOfExistingEntry].Keye_SrcPortId = (uint8)((ConfigBits & NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_MASK) >> NETC_ETHSWT_IP_ISITABLE_KEYE_SRCPORTID_SHIFT);
            ISITableEntry[*NumOfExistingEntry].Keye_Spm = (ConfigBits & NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_MASK) >> NETC_ETHSWT_IP_ISITABLE_KEYE_SPM_SHIFT;

            for (FrmKeyIdx = 0U; FrmKeyIdx < 4U; FrmKeyIdx++)
            {
                ISITableEntry[*NumOfExistingEntry].Keye_FrmKey[FrmKeyIdx] = TableDataBuffer.TableDataField[3U + FrmKeyIdx];
            }

            /* fill in CFGE data */
            ISITableEntry[*NumOfExistingEntry].IngrStreamEntryId = TableDataBuffer.TableDataField[7U];

            /* increase the NumOfExistingEntry */
            (*NumOfExistingEntry) += 1U;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetIngrStreamIdentificationTable
 * Description   : Ethernet Switch get ingress stream filter table function.
 * implements Netc_EthSwt_Ip_GetIngrStreamIdentificationTable_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_GetIngrStreamIdentificationTable( uint8 SwitchIdx,
                                                                               uint16 * NumberOfElements,
                                                                               Netc_EthSwt_Ip_IngrStremIdentificationTableDataType * ISITableList
                                                                             )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
    uint16 NumOfExistingEntry = 0U;
    uint32 ResumeId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;

    /* [notes]: we will have to read entries one by one because of the errata ERR051048.
     - ERR051048: NETC: Management command with search action responds with incorrect NUM_MATCHED
     - Description: The NUM_MATCHED field in the command NTMP response header may be incorrect when
       the search access method is used for the following tables: FDB table 15, L2 IPv4 Multicast
       Filter table 16, VLAN Filter table 18, Ingress Stream Identification table 30, or Ingress Stream
       Filter table 32.
     - Workaround: For the query command, limit the message response buffer size (RESPONSE_LENGTH field in the request header)
       so that NETC returns no more than one entry at a time. Under this condition, the NUM_MATCHED field value is correct
    */

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(NumberOfElements != NULL_PTR);
    DevAssert(*NumberOfElements != 0U);
    DevAssert(ISITableList != NULL_PTR);
#endif

    do
    {
        /* check if the ISITableList is full or we get all existing entries */
        if ((NumOfExistingEntry >= *NumberOfElements) || (NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS != status))
        {
            break;
        }

        status = Netc_EthSwt_Ip_SearchAndFillIngrStreamIdentificationTable(SwitchIdx, &ResumeId, &NumOfExistingEntry, ISITableList);

    } while (ResumeId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID);      /* ResumeId == NETC_ETHSWT_IP_BD_NULL_ENTRY_ID means the query operation is completed */

    /* return the Number of elements which are currently available in the EthSwitch module or number of elements copied to ISITableList*/
    *NumberOfElements = NumOfExistingEntry;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_UpdateEgressSchedulerTableEntry
 * Description   : Ethernet Switch Update Egress Class Scheduler table entry function.
 * implements Netc_EthSwt_Ip_UpdateEgressSchedulerTableEntry_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_UpdateEgressSchedulerTableEntry( uint8 SwitchIdx,
                                                                            uint32 EntryId,
                                                                            uint32 *MatchedEntries,
                                                                            const Netc_EthSwt_Ip_PortSchedulerType * SchedulerTableEntry
                                                                        )
{
    Netc_EthSwt_Ip_CBDRStatusType status;
    uint32 ActionsData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SchedulerTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(EntryId < NETC_ETHSWT_IP_NUMBER_OF_PORTS);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* set table version*/
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);
    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_41();

    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */

    /* fill in Access Key field, only support Entry ID Match method */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EntryId;

    /* fill in CFGE_DATA */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_CQ_ASSG(SchedulerTableEntry->numberOfWBFSQueues) \
                                                                                | NETC_ETHSWT_IP_SCHTABLE_CFGE_DATA_OAL(SchedulerTableEntry->overheadAccountingLength);

    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_0(SchedulerTableEntry->portEgressSchedulerWeightList[0U]) \
                                                                                | NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_1(SchedulerTableEntry->portEgressSchedulerWeightList[1U]) \
                                                                                | NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_2(SchedulerTableEntry->portEgressSchedulerWeightList[2U]) \
                                                                                | NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_3(SchedulerTableEntry->portEgressSchedulerWeightList[3U]);

    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_4(SchedulerTableEntry->portEgressSchedulerWeightList[4U]) \
                                                                                | NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_5(SchedulerTableEntry->portEgressSchedulerWeightList[5U]) \
                                                                                | NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_6(SchedulerTableEntry->portEgressSchedulerWeightList[6U]) \
                                                                                | NETC_ETHSWT_IP_SGCLTABLE_CFGE_DATA_WBFS_WEIGHT_7(SchedulerTableEntry->portEgressSchedulerWeightList[7U]);
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_41();

    /* fill in operation data for config field of Request Header*/
    Netc_EthSwt_Ip_OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    Netc_EthSwt_Ip_OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    Netc_EthSwt_Ip_OperationData.TableId = NETC_ETHSWT_IP_CLASS_SCHEDULER_TABLE_ID;
    /* for Add and Update command, the Access Method should only be NETC_ETHSWT_ENTRY_ID_MATCH */
    Netc_EthSwt_Ip_OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    Netc_EthSwt_Ip_OperationData.Cmd = NETC_ETHSWT_UPDATE_CMD;

    /* the request and response data buffer length are variable based on the length of control list*/
    Netc_EthSwt_Ip_OperationData.ReqBuffLength = NETC_ETHSWT_IP_EGRSCHTABLE_REQBUFFER_LEN ;
    Netc_EthSwt_Ip_OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

    /* send command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &Netc_EthSwt_Ip_OperationData);
#if defined(ERR_IPV_NETC_051243)
#if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS))
#else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
#endif
#else
    if (status == NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS)
#endif
    {
        status = NETC_ETHSWT_IP_CBDRSTATUS_SUCCESS;
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
    }

    return status;
}

/* @implements Netc_EthSwt_Ip_SetSyncState_Activity */
Std_ReturnType Netc_EthSwt_Ip_SetSyncState(uint8 SwitchIdx, boolean SyncState)
{
    Std_ReturnType Status = E_OK;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#else
    (void)SwitchIdx; /*Cast to void because there might be cases when NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_OFF and SwitchIdx will be unused */
#endif

    SchM_Enter_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_09();
    if(TRUE == SyncState)
    {
        Netc_EthSwt_Ip_TimerBase->TMR_PARAM |= NETC_ETHSWT_TIMER_SYNC_MASK;
    }
    else
    {
        Netc_EthSwt_Ip_TimerBase->TMR_PARAM &= ~NETC_ETHSWT_TIMER_SYNC_MASK;
    }
    SchM_Exit_EthSwt_43_NETC_ETHSWT_EXCLUSIVE_AREA_09();

    return Status;
}

#define ETHSWT_43_NETC_STOP_SEC_CODE
#include "EthSwt_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
