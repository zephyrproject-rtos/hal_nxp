/*
 * Copyright 2021-2022 NXP
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
#define NETC_ETHSWT_IP_SW_MAJOR_VERSION_C               0
#define NETC_ETHSWT_IP_SW_MINOR_VERSION_C               9
#define NETC_ETHSWT_IP_SW_PATCH_VERSION_C               0

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

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE (1U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE (3U)
#define SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE (4U)
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
#define NETC_ETHSWT_IP_SHAPING_PSPEED_2000MBITS (199U)

#define NETC_ETHSWT_IP_NUM_SHAPING_CLASS (8U)

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

/* Enabled status for Time Aware Shaper of each port */
static boolean PortTimeAwareShaperEnabled[NETC_ETHSWT_NUMBER_OF_PORTS] = {(boolean)FALSE, (boolean)FALSE, (boolean)FALSE};

/* Flag to determine if mirroring is active or not */
static boolean MirrorConfigurationDone = FALSE;

#define ETHSWT_43_NETC_STOP_SEC_VAR_INIT_BOOLEAN
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_INIT_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

/* Base address of the registers for the MAC Ports */
Netc_EthSwt_Ip_PortBaseType* Netc_EthSwt_Ip_PortBaseTable[] = { (Netc_EthSwt_Ip_PortBaseType*)IP_NETC__SW0_ETH_MAC_PORT0_BASE, (Netc_EthSwt_Ip_PortBaseType*)IP_NETC__SW0_ETH_MAC_PORT1_BASE };

/* Base address of the registers for the pseudo Port */
Netc_EthSwt_Ip_PseudoPortBaseType* Netc_EthSwt_Ip_PseudoPortBaseTable[] = { (Netc_EthSwt_Ip_PseudoPortBaseType*)IP_NETC__SW0_PSEUDO_MAC_PORT2_BASE };
SW_PORT0_Type *Netc_EthSwt_Ip_SW0_PortxBaseAddr[NETC_ETHSWT_NUMBER_OF_PORTS] = {(SW_PORT0_Type*)IP_NETC__SW0_PORT0_BASE, (SW_PORT0_Type*)IP_NETC__SW0_PORT1_BASE, (SW_PORT0_Type*)IP_NETC__SW0_PORT2_BASE};
#define ETHSWT_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

/* Table entries for Time Aware Shaping configuration of each Port */
static Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType TimeGateSchedulingEntryData[NETC_ETHSWT_NUMBER_OF_PORTS] = {0U};

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_INIT_32
#include "EthSwt_43_NETC_MemMap.h"

/* Ingress Port Filter Entry ID for mirroing */
uint32 MirroringIngressPortFilterEntryId = 0xFFFFFFFFUL;

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
static uint16 Netc_EthSwt_Ip_FdbTableEntryTimeout;

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_16
#include "EthSwt_43_NETC_MemMap.h"

#define ETHSWT_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "EthSwt_43_NETC_MemMap.h"

/* A shadow buffer for the mirroring configuration to be used when the application is reading the active configuration */
static Netc_EthSwt_Ip_SwitchMirrorCfgType MirrorCfgBackup;

/* Structure used for filling in the actual command buffer descriptor used in table operations */
volatile Netc_EthSwt_Ip_CmdBDType CmdBDRConfig[NETC_ETHSWT_IP_CBDR_NUM];

 /* Key element data for ingress port filter table */
static volatile uint32 IPFKeyeData[NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN];

/* a 128 bytes aligned command ring descriptor buffer */
VAR_ALIGN(Netc_EthSwt_Ip_NTMPMessageHeaderFormatType SwtcommandRingDescriptor0[NETC_ETHSWT_IP_ACTUAL_CBDR0_LENGTH], NETC_ETHSWT_IP_CBD_ALIGNED_SIZE)
VAR_ALIGN(Netc_EthSwt_Ip_NTMPMessageHeaderFormatType SwtcommandRingDescriptor1[NETC_ETHSWT_IP_ACTUAL_CBDR1_LENGTH], NETC_ETHSWT_IP_CBD_ALIGNED_SIZE)

/* a 16 bytes aligned FDB table request data buffer */
VAR_ALIGN(volatile Netc_EthSwt_Ip_SwitchTableDataType TableDataBuffer, NETC_ETHSWT_IP_TABLE_ALIGNED_SIZE)

#define ETHSWT_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "EthSwt_43_NETC_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETHSWT_43_NETC_START_SEC_CODE
#include "EthSwt_43_NETC_MemMap.h"

/**
 * @brief            Command BD Rings initialization function
 * @details          Initialize command ring for switch
 *
 * @param[in]        cbdrIndex: Index of switch command BD rings. There are only two switch command BD rings.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_CBDRSTATUS_SUCCES, success
 * @retval           1 : NETC_ETHSWT_CBDRSTATUS_INDEX_ERROR, fail
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
 * @retval           0 : NETC_ETHSWT_CBDRSTATUS_SUCCES, success
 * @retval           2 : NETC_ETHSWT_CBDRSTATUS_RINGFULL, fail
 */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SendCommand(uint8 SwitchIdx, uint8 cbdrIndex, const NetcEthSwt_Ip_ReqHeaderTableOperationDataType *OperationData);

/**
 * @brief            Get Matched table entries function
 * @details          Check how many table entry exist
 *
 * @param[in]        cbdrIndex:     Index of switch command BD rings
 *
  * @param[out]      NumOfEntry:    Number of matched entry found
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETHSWT_CBDRSTATUS_SUCCES, success
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
 * @retval           0 : NETC_ETHSWT_CBDRSTATUS_SUCCES, success
 * @retval           6 : NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR, fail
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
 * @retval           0 : NETC_ETHSWT_CBDRSTATUS_SUCCES, success
 * @retval           6 : NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR, fail
 */
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(uint32 ActionsData, uint32 AccessKeyData, const Netc_EthSwt_Ip_VlanFilterTableCFGEDataType *pCfgeData, Netc_EthSwt_Ip_AccessMethodType accessMethod);

static Std_ReturnType Netc_EthSwt_Ip_MacPortConfig( uint8 SwitchIdx, uint8 SwitchPortIdx,
                                                    Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType,
                                                    EthTrcv_BaudRateType EthSwtPortMacLayerSpeed,
                                                    Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                  );
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

static inline Std_ReturnType Netc_EthSwt_Ip_PortRateEnumToRate(EthTrcv_BaudRateType baudRate, uint64 *portTxRate);

static Std_ReturnType Netc_EthSwt_Ip_IerbReady(void);
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
    /* get elapsed ticks */
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, NETC_ETHSWT_IP_TIMEOUT_TYPE);

    return ((*ElapsedTimeInOut >= TimeoutTicks) ? TRUE : FALSE);
}

static Std_ReturnType Netc_EthSwt_Ip_IerbReady(void)
{
    Std_ReturnType status = E_OK;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    /* Verify ready and IERB is valid */
    /* Setup timeout timer */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do
    {
        if (
             (0UL == (IP_NETC__SW0_COMMON->OSR & NETC_F2_COMMON_OSR_STATE_MASK)) &&
             (0UL == (IP_NETC__SW0_COMMON->OSR & NETC_F2_COMMON_OSR_ITM_STATE_MASK))
           )
        {
            status = E_OK;
            break;
        }
        else
        {
            status = E_NOT_OK;
        }
    }while(!Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return status;
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

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_EMDIOConfiguration
 * Description   : function for configuring the EMDIO
 *
 *END**************************************************************************/
static Std_ReturnType Netc_EthSwt_Ip_EMDIOConfiguration( uint8 SwitchIdx );

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
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    (void) SwitchIdx;

    if(TRUE == PortEnable)
    {
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->POR &= ~(SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK);

        /* Write the PM0_COMMAND_CONFIG only for the MAC ports */
        if (SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
        {
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG |= (SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK | \
                                                                                SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK);
        }
    }
    else
    {
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->POR |= (SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK);

        /* Write the PM0_COMMAND_CONFIG only for the MAC ports */
        if (SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
        {
            Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG &= ~(SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK | \
                                                                                 SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK);
        }
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
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    if (SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
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
    uint32 interfaceModeConfig;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    (void) SwitchIdx;
    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        interfaceModeConfig = (Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE);

        switch((interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_MASK) >> SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_SHIFT)
        {
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE: /* MII mode */
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE: /* RMII mode */
                if((interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK) == SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK)
                {
                    *BaudRate = ETHTRCV_BAUD_RATE_10MBIT;
                }
                else
                {
                    *BaudRate = ETHTRCV_BAUD_RATE_100MBIT;
                }
                break;
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE: /* RGMII mode */
                switch((interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK) >> SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_SHIFT)
                {
                    case SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT: /* 1000Mbps */
                        *BaudRate = ETHTRCV_BAUD_RATE_1000MBIT;
                        break;
                    case SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_100MBIT: /* 100Mbps */
                        *BaudRate = ETHTRCV_BAUD_RATE_100MBIT;
                        break;
                    case SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_10MBIT: /* 10Mbps */
                        *BaudRate = ETHTRCV_BAUD_RATE_10MBIT;
                        break;
                    default:
                        status = E_NOT_OK;
                        break;
                }
                break;
            default:
                status = E_NOT_OK;
                break;
        }
    }
    else
    {
        *BaudRate = ETHTRCV_BAUD_RATE_1000MBIT;
    }

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
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        interfaceModeConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE;

        interfaceType = ((interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_MASK) >> SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_SHIFT) ;
        switch(interfaceType)
        {
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_MII_MODE: /* MII mode */
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RMII_MODE: /* RMII mode */
            {
                if(BaudRate == ETHTRCV_BAUD_RATE_10MBIT)
                {
                    interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK;
		    shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
                }
                else if(BaudRate == ETHTRCV_BAUD_RATE_100MBIT)
                {
                    interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK);
		    shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
                }
                else
                {
                    status = E_NOT_OK;
                }
                break;
            }
            case SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE: /* RGMII mode */
            {
                switch(BaudRate)
                {
                    case ETHTRCV_BAUD_RATE_10MBIT: /* 10Mbps */
                    {
                        interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
                        interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_10MBIT));
		    	shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
                        break;
                    }
                    case ETHTRCV_BAUD_RATE_100MBIT: /* 100Mbps */
                    {
                        interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
                        interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_100MBIT));
		    	shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
                        break;
                    }
                    case ETHTRCV_BAUD_RATE_1000MBIT: /* 1000Mbps */
                    {
                        interfaceModeConfig &= ~(SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP_MASK);
                        interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT));
		    	shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS;
                        break;
                    }
                    default:
                    {
                        status = E_NOT_OK;
                        break;
                    }
                }
                break;
            }
            default:
            {
                status = E_NOT_OK;
                break;
            }
        }
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE = interfaceModeConfig;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(shapingPSpeedConfig);
    }
    else
    {
	/* pseudo port */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_2000MBITS);
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
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    (void) SwitchIdx;
    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        interfaceModeConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE;

        /* Is this RGMII mode == 4U */
        if ( SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE ==
             ((interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_MASK) >> SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE_SHIFT)
            )
        {
        /* Full duplex is 1 in SFD field */
            if(SW_ETH_MAC_PORT1_PM0_IF_MODE_SFD_MASK == (interfaceModeConfig & SW_ETH_MAC_PORT1_PM0_IF_MODE_SFD_MASK))
            {
                *DuplexMode = ETHTRCV_DUPLEX_MODE_FULL;
            }
            else /* ETHTRCV_DUPLEX_MODE_HALF */
            {
                *DuplexMode = ETHTRCV_DUPLEX_MODE_HALF;
            }
        }
        else
        {
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
    }
    else
    {
    }
        *DuplexMode = ETHTRCV_DUPLEX_MODE_FULL;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SetMacAddr
 * Description   : This function sets the MAC address of a certain port of switch
 *
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_SetMacAddr(uint8 SwitchIdx, uint8 portIndex, const uint8 *macAddr)
{
    Std_ReturnType status = E_OK;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(portIndex < NETC_ETHSWT_NUMBER_OF_PORTS);
    DevAssert(macAddr != NULL_PTR);
#endif

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->PMAR0 = (uint32)(macAddr[0U]) | ((uint32)(macAddr[1U]) << 8U) | ((uint32)(macAddr[2U]) << 16U) | ((uint32)(macAddr[3U]) << 24U);
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->PMAR1 = (uint32)(macAddr[4U]) | ((uint32)(macAddr[5U]) << 8U);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetMacAddr
 * Description   : This function reads the MAC address of a certain port
 *
 *END**************************************************************************/
void Netc_EthSwt_Ip_GetMacAddr(uint8 SwitchIdx, uint8 portIndex, uint8 *macAddr)
{
    uint32 msbMacAddr;
    uint32 lsbMacAddr;
    uint8 macAddrIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(portIndex < NETC_ETHSWT_NUMBER_OF_PORTS);
    DevAssert(macAddr != NULL_PTR);
#endif

    /* read data from registers */
    msbMacAddr = Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->PMAR0;
    lsbMacAddr = Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->PMAR1;

    /* copy mac address in the correct order */
    for (macAddrIdx = 0U; macAddrIdx < 4U; macAddrIdx++)
    {
        macAddr[macAddrIdx] = (uint8)(msbMacAddr & NETC_ETHSWT_IP_0XFF_MASK);
        msbMacAddr >>= 8U;
    }

    macAddr[4U] = (uint8)(lsbMacAddr & NETC_ETHSWT_IP_0XFF_MASK);
    lsbMacAddr >>= 8U;
    macAddr[5U] = (uint8)(lsbMacAddr & NETC_ETHSWT_IP_0XFF_MASK);

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
    uint32 NumOfMatchedElement = 0;
    Netc_EthSwt_Ip_FdbEntryDataType FdbTableEntry;
    uint32 PortBitMap;

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

    QueryStatus = Netc_EthSwt_Ip_QueryFdbTableEntry(SwitchIdx, &NumOfMatchedElement, &FdbTableEntry);
    if (QueryStatus == NETC_ETHSWT_CBDRSTATUS_SUCCES)
    {
        /* find a matched entry */
        if (1U == NumOfMatchedElement)
        {
            /* get the port bitmap value from Fdb table response data buffer */
            PortBitMap = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_PORTBITMAP];

            /* check matched port number */
            for (PortIndex = 0U; PortIndex < NETC_ETHSWT_IP_BITMAPLEN; PortIndex++)
            {
                if (1U == (PortBitMap & (0x1U)))
                {
                    NumOfMatchedPorts += 1U;
                    *PortIdx = PortIndex;
                }
                PortBitMap >>= 1U;
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
    uint32 MacAddrL;
    uint32 MacAddrH;
    uint32 CfgeData;
    uint8 MacByteIdx;
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FdbTableEntry != NULL_PTR);
#endif

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);

    KeyeData[0U] = ((uint32)(FdbTableEntry->MacAddr[0U]) | ((uint32)(FdbTableEntry->MacAddr[1U]) << 8U) | ((uint32)(FdbTableEntry->MacAddr[2U]) << 16U) | ((uint32)(FdbTableEntry->MacAddr[3U]) << 24U));
    KeyeData[1U] = ((uint32)(FdbTableEntry->MacAddr[4U]) | ((uint32)(FdbTableEntry->MacAddr[5U]) << 8U));
    KeyeData[2U] = FdbTableEntry->FID;

    /* no need CFGE_DATA and only use "NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH" as the access method */
    status = Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;       /* for query command, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
        OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);           /* set request data buffer length */
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);           /* set response data buffer with normal length */

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

            /* found a matched entry */
            if (1U == *MatchedEntries)
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
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FdbTableEntry != NULL_PTR);
#endif

    /* Delete command will ignore ActionsData data field */
    KeyeData[0U] = ((uint32)(FdbTableEntry->MacAddr[0U]) | ((uint32)(FdbTableEntry->MacAddr[1U]) << 8U) | ((uint32)(FdbTableEntry->MacAddr[2U]) << 16U) | ((uint32)(FdbTableEntry->MacAddr[3U]) << 24U));
    KeyeData[1U] = ((uint32)(FdbTableEntry->MacAddr[4U]) | ((uint32)(FdbTableEntry->MacAddr[5U]) << 8U));
    KeyeData[2U] = FdbTableEntry->FID;

    /* no need CFGE_DATA and only use "NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH" as the access method */
    status = Netc_EthSwt_Ip_FillInFdbTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;       /* for delete command, always uses NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method */
        OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);           /* set request data buffer length */
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);           /* set response data buffer with normal length */

        /* send the "Delete" command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(FdbTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FdbTableEntry->DynamicEntry == FALSE);    /* users should not be allowed to add dynamic entries */
#endif

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_CBDRSTATUS_INVALID_CMD;    /* not supported command */
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
        if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
        {
            /* fill in operation data for config field of Request Header*/
            OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
            OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
            OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
            OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;       /* for Add, Update, or AddorUpdate command, the Access Method should only be NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH */
            OperationData.Cmd = Cmd;
            OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
            OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

            /* send command */
            status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
            /* Erroe code 0x8A is not a real error. check it on Errata. */
            if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
            {
                Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            }
        }
        else
        {
            status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
        }
    }

    return status;
}

/* inline function for verifying conditions in function FillInFdbTableListData() */
static inline void VerifyFillInFdbTableListDataFuncCond(const uint32 *ResumeId, boolean *StatciEntryQuerying, boolean *QueryDone)
{
    if (NETC_ETHSWT_IP_BD_NULL_ENTRY_ID == *ResumeId)
    {
        if (TRUE == *StatciEntryQuerying)
        {
            *StatciEntryQuerying = FALSE;
        }
        else
        {
            *QueryDone = TRUE;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SearchAndFillInFdbTableList
 * Description   : inline function for searching and filling in FdbTableList data in function Netc_EthSwt_Ip_GetFdbTable().
 *
 *END**************************************************************************/
static inline Std_ReturnType SearchAndFillInFdbTableList(uint32 *ResumeId, uint16 *NumOfExistingEntry, Netc_EthSwt_Ip_FdbEntryDataType *FdbTableList,
                                                         boolean *StatciEntryQuerying, boolean *QueryDone)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData = {0U};
    uint32 NumOfElement = 0U;
    uint32 MacAddrL;
    uint32 MacAddrH;
    uint32 CfgeData;
    uint8 MacAddrByteIdx;
    uint32 ActionsData;

    /* set the querry options with full querry */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(0U);

    /* fill in FdbTabeDataBuffer for request */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;
    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_RESUMEENTRYID] = *ResumeId;    /* resume entry id */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_L] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MACADDRESS_H] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_FID] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_PORTBITMAP] = 0U;
    /* search static entries first then dynamic entries. set CFGE_DATA[DYNAMIC] to 0x0 meaning it will match static entries, set CFGE_DATA[DYNAMIC] to 0x1 meaning it will match dynamic entries */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGECONFIG] = (TRUE == *StatciEntryQuerying) ? NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(0U) : NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD_DYNAMIC(1U);

    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ETEID] = 0U;
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] = NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_CFGEMC(1U);    /* 0x1: Match CFGE_DATA[DYNAMIC] field */

    /* do the full querry with Search Method */
    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;           /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);             /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(0U, NETC_ETHSWT_IP_CBDR_0, &OperationData);

    /* check the status of querry command */
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];

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

        VerifyFillInFdbTableListDataFuncCond(ResumeId, StatciEntryQuerying, QueryDone);
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
    boolean StatciEntryQuerying = TRUE;
    boolean QueryDone = FALSE;

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
        do {
            /* check if the FdbTableList is full or we get all existing entries */
            if ((NumOfExistingEntry >= *NumberOfElements) || (NumOfExistingEntry >= NumOfInUseEntry) || (status == (uint8)(E_NOT_OK)) || (QueryDone == TRUE))
            {
                break;
            }

            status = SearchAndFillInFdbTableList(&ResumeId, &NumOfExistingEntry, FdbTableList, &StatciEntryQuerying, &QueryDone);

        } while ((TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS] != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID) || (FALSE == StatciEntryQuerying));      /* Status == 0xFFFFFFFF means the query operation is completed */
    }

    /* return the Number of elements which are currently available in the EthSwitch module or number of elements copied to FdbTableList*/
    *NumberOfElements = NumOfExistingEntry;

    return status;
}

/* inline function for filling in TableDataBuff in Netc_EthSwt_Ip_SearchFdbTable() function. */
static inline void FillInTableDataBuffForSearchingFDBTable(const uint32 * ResumeEntryId, const Netc_EthSwt_Ip_FDBTableSearchCriteriaDataType * SearchCriteriaData)
{
    uint32 ActionsData;
    uint8 MatchCriteriaData;

    /* set the querry options with full querry */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(0U);

    /* +++ fill in FdbTabeDataBuffer for request +++ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;

    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_RESUMEENTRYID] = *ResumeEntryId;    /* ResumeEntryId should start from 0xFFFFFFFF */
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

        /* fill in ACTE Match Criteria data*/
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_MATCHCRITERIA] |= (NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTCNT(SearchCriteriaData->SearchActeData.ActivityCounter) \
                                                                                                | NETC_ETHSWT_IP_FDBTABLE_SEARCH_CRITERIA_ACTFLAG(SearchCriteriaData->SearchActeData.ActivityFlag ? 1U : 0U));
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 NumOfElement = 0U;
    uint32 TableEntryId;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SearchCriteriaData != NULL_PTR);
    DevAssert(SearchCriteriaData->SearchMatchCriteria <= (NETC_ETHSWT_IP_FDBTABLE_MATCH_KEYE_FID_AND_MULTICAST_BIT_OF_MACADDR));
    DevAssert(FdbTableEntry != NULL_PTR);
#endif

    /* +++ fill in FdbTabeDataBuffer for request +++ */
    FillInTableDataBuffForSearchingFDBTable(ResumeEntryId, SearchCriteriaData);
    /* --- fill in FdbTabeDataBuffer for request --- */

    /* do the full querry with Search Method */
    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);           /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);

    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
        /* [notes]: if the searching is completed, or there is no matched entry found, then TableDataBuffer.TableDataField[0U] will be writen with 0xFFFFFFFF by hardware */
        *ResumeEntryId = TableDataBuffer.TableDataField[NETC_ETHSWT_FDBTABLE_RSPDATA_STATUS];
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/* inline function for searching and filling in VlanFilterTableList in function Netc_EthSwt_Ip_GetVlanFilterTable() */
static inline Std_ReturnType SearchAndFIllInVlanFilterTableList(uint32 *ResumeId, uint16 *NumOfExistingEntry, Netc_EthSwt_Ip_VlanFilterEntryDataType * VlanFilterTableList)
{
    Std_ReturnType status = E_OK;
    uint32 ActionsData;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData = {0U};
    uint32 NumOfElement = 0U;
    uint32 CfgeData;

    /* set the querry options with full querry */
    ActionsData = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U));

    /* fill in TabeDataBuffer for request */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;
    /* fill in Access Key data with search criteria data format */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_VLANFILTERTABLE_REQFMT_RESUMEENTRYID_FIELD] = *ResumeId;    /* resume entry id */

    /* do the full querry with Search Method */
    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;
    OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);           /* full query needs more space for response data */

    /* send the "Query" command */
    /* [notes]: there is an error "0x8A" in NTMP response header during this query operation but it is not a real error. there should be another errata for "0x8A" later. */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(0U, NETC_ETHSWT_IP_CBDR_0, &OperationData);

    /* check the status of querry command */
    if ((CBDRStatus == 0x8AU) || (CBDRStatus == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
        Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, &NumOfElement);

        /* get the resume_entry_id and be ready for the next query operation */
        *ResumeId = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABLE_RSPDATA_STATUS];

        /* found a matched entry */
        if ((1U == NumOfElement) && (*ResumeId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID))
        {
            /* fill in "Netc_EthSwt_Ip_VlanFilterEntryDataType" structure with data in response data buffer */
            VlanFilterTableList[(*NumOfExistingEntry)].VlanID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_VID] & NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID_MASK;

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0];
            VlanFilterTableList[(*NumOfExistingEntry)].SpanningTreeGroupMemberId = (uint8)((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
            VlanFilterTableList[(*NumOfExistingEntry)].PortMembershipBitmap = (CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1];
            VlanFilterTableList[(*NumOfExistingEntry)].FID = (uint16)(CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_MASK);
            VlanFilterTableList[(*NumOfExistingEntry)].MacLearningOptions = (uint8)((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
            VlanFilterTableList[(*NumOfExistingEntry)].MacForwardingOptions = (uint8)((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
            VlanFilterTableList[(*NumOfExistingEntry)].IpMulticastFilteringEnable = (((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) == 0x0UL) ? FALSE : TRUE;
            VlanFilterTableList[(*NumOfExistingEntry)].IpMulticastFloodingEnable = (((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) == 0x0UL) ? FALSE : TRUE;

            VlanFilterTableList[(*NumOfExistingEntry)].EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
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

            status = SearchAndFIllInVlanFilterTableList(&ResumeId, &NumOfExistingEntry, VlanFilterTableList);
        } while (TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABLE_RSPDATA_STATUS] != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID);      /* Status == 0xFFFFFFFF means the query operation is completed */
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(VlanFilterTableEntry != NULL_PTR);
#endif

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* fill in Vlan Filter Table Request Data Buffer */
        ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);

        AccessKeyData = VlanFilterTableEntry->VlanID;

        VlanFilterCfgeData.Cfge_Data[0U] = (NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID(VlanFilterTableEntry->SpanningTreeGroupMemberId) \
                                        | NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP(VlanFilterTableEntry->PortMembershipBitmap));
        VlanFilterCfgeData.Cfge_Data[1U] = (NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE(VlanFilterTableEntry->IpMulticastFloodingEnable ? 1U :0U) \
                                        | NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE(VlanFilterTableEntry->IpMulticastFilteringEnable ? 1U : 0U) \
                                        | NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO(VlanFilterTableEntry->MacForwardingOptions) \
                                        | NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO(VlanFilterTableEntry->MacLearningOptions) \
                                        | NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID(VlanFilterTableEntry->FID));
        VlanFilterCfgeData.Cfge_Data[2U] = NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP(VlanFilterTableEntry->EgressTreatmentApplicabilityPortBitmap);
        VlanFilterCfgeData.Cfge_Data[3U] = NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID(VlanFilterTableEntry->BaseEgressTreatmentEntryID);

        /* For Add, Update and AddOrUpdate commands, we only provide NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH method for users */
        status = Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(ActionsData, AccessKeyData, &VlanFilterCfgeData, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
        if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
        {
            /* fill in operation data for config field of Request Header*/
            OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
            OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
            OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
            OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;        /* for Add command, the Access Method should only be NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH */
            OperationData.Cmd = Cmd;
            OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
            OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

            /* send the command */
            status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
            /* Erroe code 0x8A is not a real error. check it on Errata. */
            if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
            {
                Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            }
        }
        else
        {
            status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* fill in Vlan Filter Table Request Data Buffer */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);        /* for "query" command we only provide "full query" for users */

    AccessKeyData = VlanFilterTableEntry->VlanID;

    /* for query command, we don't need the CFGE_DATA field */
    status = Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(ActionsData, AccessKeyData, NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of NTMP Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
        OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);            /* set request data buffer length */
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);            /* set response data buffer length */

        /* send the "Query" command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);

            /* found a matched entry */
            if (1U == *MatchedEntries)
            {
                /* fill in "Netc_EthSwt_Ip_VlanFilterEntryDataType" structure with data in response data buffer */
                VlanFilterTableEntry->VlanID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_VID] & NETC_ETHSWT_VLANFILTERTABLE_KEYEDATA_VID_MASK;

                CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0];
                VlanFilterTableEntry->SpanningTreeGroupMemberId = (uint8)((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
                VlanFilterTableEntry->PortMembershipBitmap = (CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK);

                CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1];
                VlanFilterTableEntry->FID = (uint16)(CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_MASK);
                VlanFilterTableEntry->MacLearningOptions = (uint8)((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
                VlanFilterTableEntry->MacForwardingOptions = (uint8)((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
                VlanFilterTableEntry->IpMulticastFilteringEnable = (((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) != 0x0UL) ? TRUE : FALSE;
                VlanFilterTableEntry->IpMulticastFloodingEnable = (((CfgeData & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) != 0x0UL) ? TRUE : FALSE;

                VlanFilterTableEntry->EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
                VlanFilterTableEntry->BaseEgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3];
            }
        }
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* fill in Vlan Filter Table Request Data Buffer */
    AccessKeyData = VlanFilterTableEntryId;

    /* for delete command, we don't need the CFGE_DATA field */
    status = Netc_EthSwt_Ip_FillInVlanFilterTableReqDataBuff(ActionsData, AccessKeyData, NULL_PTR, NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of NTMP Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;        /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_VLAN_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH;
        OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

        /* send the "Delete" command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(StatisticsData != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert((EntryId > 0U) && (EntryId <= (IP_NETC__SW0_COMMON->ECTCAPR & NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK)));
#endif

    /* fill in Egress Count Table Request Data Buffer */
    /* fill in Actions field. only support "full query" action and no need to update Statistics Element */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                                                                                    | NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(NETC_ETHSWT_EGRESSCOUNTTABLE_NO_UPDATE_STATISTICS_ELEMENT));
    /* fill in Access Key field, only support Entry ID Match method */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EntryId;

    /* fill in operation data for config field of NTMP Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;           /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_EGRESS_COUNT_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                        /* only support Entry ID Match method */
    OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQBUFFER_LEN);  /* set request data buffer length */
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_EGRESSCOUNTTABLE_RSPBUFFER_LEN);  /* set response data buffer length */

    /* send the "Query" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    /* Erroe code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert((EntryId > 0U) && (EntryId <= (IP_NETC__SW0_COMMON->ECTCAPR & NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK)));
#endif

    /* fill in Egress Count Table Request Data Buffer */
    /* fill in Actions field. only support "full query" action and set STSEU to reset Statistics Element */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD] = (NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY) \
                                                                                         | NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACTIONS_FIELD_STSEU(NETC_ETHSWT_EGRESSCOUNTTABLE_RESET_STATISTICS_ELEMENT));
    /* fill in Access Key field, only support Entry ID Match method */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQFMT_ACCESSKEY_FIELD] = EntryId;

    /* fill in operation data for config field of NTMP Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;           /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_EGRESS_COUNT_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                        /* only support Entry ID Match method */
    OperationData.Cmd = NETC_ETHSWT_UPDATE_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQBUFFER_LEN);  /* set request data buffer length */
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_EGRESSCOUNTTABLE_RSPBUFFER_LEN);  /* set response data buffer length */

    /* send the "Update" command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    /* Erroe code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(EgressTreatmentTableEntry != NULL_PTR);
#endif

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
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

        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        OperationData.Cmd = Cmd;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

        /* send the command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 CfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* fill in Egress Treatment Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);     /* only supports Full Query */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EgressTreatmentTableEntry->EgressTreatmentEntryID;

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    /* Erroe code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* fill in Egress Treatment Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = 0U;     /* no need to fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = EgressTreatmentTableEntryId;

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_EGRESS_TREATMENT_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
    OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    /* Erroe code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint16 MacAddrH;
    uint32 MacAddrL = 0x0UL;
    uint8 MacByteIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FrmModificationTableEntry != NULL_PTR);
#endif

    /* only support Add, Update and AddOrUpdate commands */
    if ((NETC_ETHSWT_ADD_CMD != Cmd) && (NETC_ETHSWT_UPDATE_CMD != Cmd) && (NETC_ETHSWT_ADD_OR_UPDATE_CMD != Cmd))
    {
        status = NETC_ETHSWT_CBDRSTATUS_INVALID_CMD;    /* not supported command */
    }
    else
    {
        /* fill in Frame Modification Table Request Data Buffer */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);        /* Configuration Element Update */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = FrmModificationTableEntry->FrmModificationEntryID;                /* Entry ID */

        /* be careful to the order of dest mac address, it is in big endian */
        for (MacByteIdx = 5U; MacByteIdx > 2U; MacByteIdx-- )       /* Get the Dest Mac Address */
        {
            MacAddrL |= FrmModificationTableEntry->DestMacAddr[MacByteIdx];
            MacAddrL <<= 8U;
        }
        MacAddrL |= FrmModificationTableEntry->DestMacAddr[2U];
        MacAddrH = ((uint16)(FrmModificationTableEntry->DestMacAddr[1U]) << 8U) | FrmModificationTableEntry->DestMacAddr[0U];

        /* fill in CFGE Data */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = (NENETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_DEST_MAC_ADDR_H(MacAddrH) \
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

        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support "Entry ID" match method */
        OperationData.Cmd = Cmd;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

        /* send the command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint16 MacAddrH;
    uint32 MacAddrL;
    uint8 MacByteIdx;
    uint32 CfgeData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(FrmModificationTableEntry != NULL_PTR);
#endif

    /* fill in Frame Modification Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);        /* only support "Full Query" */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = FrmModificationTableEntry->FrmModificationEntryID;                /* Entry ID */

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support "Entry ID" match method */
    OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    /* Erroe code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
            FrmModificationTableEntry->SequenceTagAction = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_SEQUENCE_TAG_ACTION_SHIFT);
            FrmModificationTableEntry->OuterVidActions = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VID_ACTION_SHIFT);
            FrmModificationTableEntry->L2HeaderVlanActions = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_VLAN_HEADER_ACTION_SHIFT);
            FrmModificationTableEntry->L2HeaderMacActions = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_MAC_HEADER_ACTION_SHIFT);
            FrmModificationTableEntry->L2Actions = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_LAYER2_ACTION_SHIFT);

            CfgeData = TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA2];
            FrmModificationTableEntry->PayloadActions = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_ACTION_SHIFT);
            FrmModificationTableEntry->OuterDeiAction = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_DEI_ACTION_SHIFT);
            FrmModificationTableEntry->OuterPcpAction = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_PCP_ACTION_SHIFT);
            FrmModificationTableEntry->OuterTpidAction = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_TPID_ACTION_SHIFT);
            FrmModificationTableEntry->OuterVlanDei = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_DEI_SHIFT);
            FrmModificationTableEntry->OuterVlanPcp = (uint8)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_PCP_SHIFT);
            FrmModificationTableEntry->OuterVlanVID = (uint16)((CfgeData & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_MASK) >> NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_OUTER_VLAN_VID_SHIFT);

            FrmModificationTableEntry->PayloadOffset = (uint8)(TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA3] & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_PAYLOAD_OFFSET_MASK);
            FrmModificationTableEntry->FrmModificationDataBytes = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_RSPFMT_CFGEDATA4] & NETC_ETHSWT_IP_FRMMODIFICATIONTABLE_CFGE_FRM_MODI_BYTES_MASK);
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* fill in Frame Modification Table Request Data Buffer */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = 0U;                               /* no need to fill in Actions field */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = FrmModificationEntryID;           /* Entry ID */

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_FRM_MODIFICATION_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support "Entry ID" match method */
    OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

    /* send the command */
    status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    /* Erroe code 0x8A is not a real error. check it on Errata. */
    if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
    {
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
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    /* Convert the value */
    RegVal = (Enable) ? (0x1UL) : (0x0UL);

    /* write the PIPFCR[EN] bit */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PIPFCR = RegVal;

    return Status;
}

/* inline function for filling in Access Keye data in function Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff() */
static inline Netc_EthSwt_Ip_CBDRStatusType FillInAccessKeyeData(const Netc_EthSwt_Ip_AccessMethodType accessMethod, const volatile uint32 *pAccessKey)
{
    uint8 ItemIdx;
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;

    switch (accessMethod)
    {
        case NETC_ETHSWT_ENTRY_ID_MATCH:
            /* fill in Entry_ID field */
            TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = pAccessKey[0U];
            break;
        case NETC_ETHSWT_EXACT_MATCH_KEY_ELEMENT_MATCH:
            /* Not Applicable for Ingress Port Filter table*/
            status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
            status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;

    /* ------initialize the table request data buffer------ */
    TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;  /* fill in Actions field */

    /* initialize ACCESS_KEY */
    status = FillInAccessKeyeData(accessMethod, pAccessKey);

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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 ActionsData;
    uint8 ByteIdx;
    uint8 CfgeDataIdx;
    uint8 PayloadIdx;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressPortFilterTableEntry != NULL_PTR);
#endif

    /* set STSEU and CFGEU flag */
    ActionsData = (NETC_ETHSWT_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU(1U) | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U));

    /* inialize KEYE_DATA */
    IPFKeyeData[0U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence;
    IPFKeyeData[2U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.keyeFrmAttributeFlags;
    IPFKeyeData[3U] = NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortIDMask) \
                 | NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_SRCPRTID(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSourcePortID) \
                 | NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DSCPMASK(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask) \
                 | NETC_ETHSWT_IP_IPFTABLE_KEYE_DATA_DIFFSCP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint);
    IPFKeyeData[4U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | (IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation << NETC_ETHSWT_IP_8BIT_SHIFT);        /* big endian for TCI */
    IPFKeyeData[5U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[2U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[3U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    IPFKeyeData[6U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[4U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[5U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | (((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT)) << NETC_ETHSWT_IP_16BIT_SHIFT);
    IPFKeyeData[7U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[2U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[3U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[4U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[5U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    IPFKeyeData[8U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[2U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[3U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    IPFKeyeData[9U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[4U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[5U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | (((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[1U]) << NETC_ETHSWT_IP_8BIT_SHIFT)) << NETC_ETHSWT_IP_16BIT_SHIFT);
    IPFKeyeData[10U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[2U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[3U]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[4U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[5U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
    IPFKeyeData[11U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation;
    IPFKeyeData[12U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask;
    IPFKeyeData[13U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask) << NETC_ETHSWT_IP_8BIT_SHIFT) | (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocol);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 17U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddress[ByteIdx];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 23U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[ByteIdx];
    }
    IPFKeyeData[27U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask) << NETC_ETHSWT_IP_16BIT_SHIFT) | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort;
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 29U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[ByteIdx];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 35U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[ByteIdx];
    }
    IPFKeyeData[39U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask) << NETC_ETHSWT_IP_16BIT_SHIFT) | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort;

    CfgeDataIdx = 0U;
    PayloadIdx = 0U;
    for (ByteIdx = 0U; ByteIdx < 12U; ByteIdx++)
    {
        IPFKeyeData[CfgeDataIdx + 41U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx]) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx]) << NETC_ETHSWT_IP_8BIT_SHIFT) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx + 1U]) << NETC_ETHSWT_IP_16BIT_SHIFT) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx + 1U]) << NETC_ETHSWT_IP_24BIT_SHIFT);
        PayloadIdx++;
        CfgeDataIdx++;
    }

    /* only supports "NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH" access method */
    status = Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &IPFKeyeData[0U], &(IngressPortFilterTableEntry->IngressPortFilterCfgeData), NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH;       /* for Adding an ingress port filter entry, the Access Method should only be NETC_ETHSWT_TERNARY_MATCH_KEY_ELEMENT_MATCH */
        OperationData.Cmd = NETC_ETHSWT_ADD_FOLLOWEDBY_QUERY_CMD;                       /* can only use "Add followed by a Query" command to add an ingress port filter table entry */
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            /* It's an "Add followed by a Query", but even if this entry is added successfully, the MatchedEntry is still 0. So here we can not check the MatchedEntries parameter. */
            IngressPortFilterTableEntry->IngressPortFilterEntryID = TableDataBuffer.TableDataField[1U];     /* Get the Entry_ID from response data buffer */
        }
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/* inline function for filling in part of keye data in function FillInIPFTableEntryData() */
static inline void FillInKeyeDataForIPF(Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry)
{
    uint8 ByteIdx;
    uint8 PayloadIdx;
    uint8 CfgeDataIdx;

    for (ByteIdx = 2U; ByteIdx < 6U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[ByteIdx] = (uint8)(TableDataBuffer.TableDataField[12U] & NETC_ETHSWT_IP_0XFF_MASK);
        TableDataBuffer.TableDataField[12U] >>= NETC_ETHSWT_IP_8BIT_SHIFT;
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation = (uint16)(TableDataBuffer.TableDataField[13U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask = (uint16)((TableDataBuffer.TableDataField[13U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherType = (uint16)(TableDataBuffer.TableDataField[14U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask = (uint16)((TableDataBuffer.TableDataField[14U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK);
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
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort = (uint16)(TableDataBuffer.TableDataField[29U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask = (uint16)((TableDataBuffer.TableDataField[29U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[ByteIdx] = TableDataBuffer.TableDataField[ByteIdx + 31U];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[ByteIdx] = TableDataBuffer.TableDataField[ByteIdx + 37U];
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort = (uint16)(TableDataBuffer.TableDataField[41U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask = (uint16)((TableDataBuffer.TableDataField[41U] >> NETC_ETHSWT_IP_16BIT_SHIFT) & NETC_ETHSWT_IP_0XFFFF_MASK);

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
static inline void FillInIPFTableEntryData(Netc_EthSwt_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry)
{
    uint8 ByteIdx;
    uint32 CfgeData;

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
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation = (uint16)(TableDataBuffer.TableDataField[6U] & NETC_ETHSWT_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = (uint16)((TableDataBuffer.TableDataField[6U] & NETC_ETHSWT_IP_0XFFFF0000_MASK) >> NETC_ETHSWT_IP_16BIT_SHIFT);
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

    FillInKeyeDataForIPF(IngressPortFilterTableEntry);  /* fill in the rest part of the KEYE_DATA */

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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 KeyeData[NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN];
    uint32 ActionsData;


#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressPortFilterTableEntry != NULL_PTR);
#endif

    /* only support "full query" */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETHSWT_TABLES_FULL_QUERY);

    /* inialize KEYE_DATA with Entry_ID */
    KeyeData[0U] = IngressPortFilterTableEntry->IngressPortFilterEntryID;

    status = Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_ENTRY_ID_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        OperationData.Cmd = NETC_ETHSWT_QUERY_CMD;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
            /* if found a matched entry, then fill in the structure */
            if (1U == *MatchedEntries)
            {
                FillInIPFTableEntryData(IngressPortFilterTableEntry);
            }
        }
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 KeyeData[1U];
    uint32 ActionsData = 0x0UL;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* inialize KEYE_DATA with Entry_ID */
    KeyeData[0U] = IngressPortFilterEntry;

    status = Netc_EthSwt_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETHSWT_ENTRY_ID_MATCH);
    if (NETC_ETHSWT_CBDRSTATUS_SUCCES == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_INGRESS_PORT_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;
        OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            Netc_EthSwt_Ip_GetMatchedEntries(NETC_ETHSWT_IP_CBDR_0, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ConfigPortTimeGateScheduling
 * Description   : Ethernet Switch enables or disables Time Gate Scheduling function on a port.
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_ConfigPortTimeGateScheduling( uint8 SwitchIdx,
                                                                           uint8 SwitchPortIdx,
                                                                           boolean Enable
                                                                         )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;
    uint32 RegValue;
    uint32 GateControlListState;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    /* Software must also wait until PTGAGLSR[TG] is deasserted before re-enabling. */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do {
        /* get the state of gate control list */
        GateControlListState = (Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTGAGLSR & SW_PORT0_PTGAGLSR_TG_MASK);
        TimeExpired = Netc_EthSwt_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    } while ((GateControlListState != 0x0U) && (FALSE == TimeExpired));

    if (GateControlListState == 0x0U)
    {
        /* read the reg value first */
        RegValue = Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTGSCR;

        if (TRUE == Enable)
        {
            RegValue |= SW_PORT0_PTGSCR_TGE(1U);    /* Enable time gating */
        }
        else
        {
            RegValue &= ~SW_PORT0_PTGSCR_TGE(1U);    /* Disable time gating */
        }

        /* write it back. */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PTGSCR = RegValue;

        /* if time gate scheduling is enabled, and entry data is configured, then adds the entry */
        if ((TRUE == Enable) && (TRUE == PortTimeAwareShaperEnabled[SwitchPortIdx]))
        {
            status = Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry(0U, &TimeGateSchedulingEntryData[SwitchPortIdx]);
            /* fail to add or update the time gate schedulling table entry */
            if (status != NETC_ETHSWT_CBDRSTATUS_SUCCES)
            {
                status = E_NOT_OK;
            }
        }
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

static inline void FillInGateControlListData(const uint8 *OperationTimeIdx, const Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry)
{
    uint8 CFGEDataIdx;
    uint16 GateEntryIdx;
    uint8 HostRequest;

    if (*OperationTimeIdx == 1U)
    {
        CFGEDataIdx = 0U;
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
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry
 * Description   : Ethernet Switch adds or updates Time Gate Scheduling table entry function.
 *
 *END**************************************************************************/
Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_AddOrUpdateTimeGateSchedulingTableEntry( uint8 SwitchIdx,
                                                                                      const Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry
                                                                                    )
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;
    uint8 OperationTimes;
    uint8 OperationTimeIdx;
    volatile uint64 CurrentTime = 0;
    uint32 CycleFactor;
    uint64 NewBaseTime;
    uint32 LookaheadTime;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(TimeGateSchedulingTableEntry != NULL_PTR);
#endif

    /* AdminControlListLength = 0U means to reset the gate control list or add the time gate scheduling entry without gate control list */
    OperationTimes = (TimeGateSchedulingTableEntry->AdminControlListLength > 0U) ? 2U : 1U;

    /* for adding or updating gate control list, we'll have to remove the gate control list firstly */
    for (OperationTimeIdx = 0U; OperationTimeIdx < OperationTimes; OperationTimeIdx++)
    {
        /* ++++++ initialize the table request data buffer ++++++ */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);    /* fill in Actions field */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ENTRYID_FIELD] = TimeGateSchedulingTableEntry->TimeGateSchedulingTable_EID;    /* fill in Entry ID */
        /* fill in CFGE_DATA */
        /* get the current time from 1588 timer */
        CurrentTime = IP_NETC__TMR0_BASE->TMR_CUR_TIME_L;      /* should read the Lower register first */
        CurrentTime |= ((uint64)(IP_NETC__TMR0_BASE->TMR_CUR_TIME_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;
        /* get lookaheadtime */
        LookaheadTime = IP_NETC__NETC_IERB->CFG_SW_INST[0U].STGSLR; /* [Ricky]TODO: this register is not available for now + Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->RESERVED_7; */

        /* calculate the NewBaseTime */
        if (TimeGateSchedulingTableEntry->AdminBaseTime >= (CurrentTime + LookaheadTime))
        {
            NewBaseTime = TimeGateSchedulingTableEntry->AdminBaseTime;
        }
        else
        {
            CycleFactor = (uint32)(CurrentTime + LookaheadTime - TimeGateSchedulingTableEntry->AdminBaseTime) / (TimeGateSchedulingTableEntry->AdminCycleTime);
            NewBaseTime = TimeGateSchedulingTableEntry->AdminBaseTime + (((uint64)CycleFactor + 1UL) * (uint64)(TimeGateSchedulingTableEntry->AdminCycleTime));
        }
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA0] = (uint32)(NewBaseTime & (0xFFFFFFFFUL));
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA1] = (uint32)(NewBaseTime >> NETC_ETHSWT_IP_32BIT_SHIFT);
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA2] = TimeGateSchedulingTableEntry->AdminCycleTime;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA3] = TimeGateSchedulingTableEntry->AdminCycleTimeExt;
        /* set Administrative Control List Length to 0 for removing the admin gate control list or adding an entry with no administrative gate control list */
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_CFGEDATA4] = (OperationTimeIdx == 0U) ? 0x0UL : (uint32)(TimeGateSchedulingTableEntry->AdminControlListLength);

        FillInGateControlListData(&OperationTimeIdx, TimeGateSchedulingTableEntry);
        /* ------ initialize the table request data buffer ------ */

        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETHSWT_IP_TIME_GATE_SCHEDULING_TABLE_ID;
        OperationData.AccessMethod = NETC_ETHSWT_ENTRY_ID_MATCH;                      /* only support NETC_ETHSWT_ENTRY_ID_MATCH method */
        OperationData.Cmd = NETC_ETHSWT_UPDATE_CMD;                                   /* can only use "update" command to add or update an time gate scheduling table entry */
        OperationData.ReqBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);    /* [Ricky]TODO: follow-up work needs to do. */
        OperationData.RspBuffLength = (NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send "update" command to add/remove gate control list */
        status = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
        /* Erroe code 0x8A is not a real error. check it on Errata. */
        if ((status == 0x8AU) || (status == NETC_ETHSWT_CBDRSTATUS_SUCCES))
        {
            status = NETC_ETHSWT_CBDRSTATUS_SUCCES;
        }
    }

    return status;
}

/*!
 * @brief Ethernet Switch get port index counter values function.
 *
 * @param[in]
 * @param[out]
 * @return
 */
static Std_ReturnType Netc_EthSwt_Ip_GetSwtPortCounters( uint8 SwitchIdx, uint8 portIndex, Netc_EthSwt_Ip_CounterType *Counter )
{
    volatile uint32 *xCR0Value;
    volatile uint32 *xCR1Value;

    (void)SwitchIdx;

    /* Receive */
    /* Port MAC index Receive Ethernet Octets Counter(etherStatsOctetsn) */
    xCR0Value = (volatile uint32 *)(&(Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_REOCTN));
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_REOCTN) + 1U;
    Counter->rxEtherOctetCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);


    /* Port MAC index Receive Octets Counter(iflnOctetsn)  */
    xCR0Value = (volatile uint32 *)(&(Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_ROCTN));
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_ROCTN) + 1U;
    Counter->rxOctetCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Alignment Error Counter Register(aAlignmentErrorsn) */
    /* Reserved */

    /* Port MAC index Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RXPFN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RXPFN) + 1U;
    Counter->rxValidPauseFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RFRMN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RFRMN) + 1U;
    Counter->rxFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Frame Check Sequence Error Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RFCSN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RFCSN) + 1U;
    Counter->rxFrameCheckSequenceErrorCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive VLAN Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RVLANN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RVLANN) + 1U;
    Counter->rxVlanFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Frame Error Counter Register(ifInErrorsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RERRN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RERRN) + 1U;
    Counter->rxFrameErrorCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Unicast Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RUCAN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RUCAN) + 1U;
    Counter->rxUnicastFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Multicast Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RMCAN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RMCAN) + 1U;
    Counter->rxMulticastFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Broadcast Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RBCAN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RBCAN) + 1U;
    Counter->rxBroadcastFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Dropped Packets Counter Register(etherStatsDropEventsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RDRPN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RDRPN) + 1U;
    Counter->rxDroppedPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Packets Counter Register(etherStatsPktsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RPKTN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RPKTN) + 1U;
    Counter->rxPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Undersized Packet Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RUNDN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RUNDN) + 1U;
    Counter->rxUndersizePacketCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R64N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R64N) + 1U;
    Counter->rx64OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R127N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R127N) + 1U;
    Counter->rx65to127OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R255N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R255N) + 1U;
    Counter->rx128to255OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R511N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R511N) + 1U;
    Counter->rx256to511OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R1023N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R1023N) + 1U;
    Counter->rx512to1023OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R1522N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R1522N) + 1U;
    Counter->rx1024to1522OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R1523XN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_R1523XN) + 1U;
    Counter->rx1523toMaxOctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Oversized Packet Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_ROVRN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_ROVRN) + 1U;
    Counter->rxOversizedPacketsCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Jabber Packet Counter Register(etherStatsJabbersn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RJBRN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RJBRN) + 1U;
    Counter->rxJabberPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Fragment Packet Counter Register(etherStatsFragmentsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RFRGN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RFRGN) + 1U;
    Counter->rxFragmentPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Control Packet Counter Register */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RCNPN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RCNPN) + 1U;
    Counter->rxControlPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RDRNTPN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_RDRNTPN) + 1U;
    Counter->rxDroppedNTruncatedPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port Rx discard count register */
    Counter->rxDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->PRXDCR;

    /* Transmit */
    /* Port MAC index Transmit Ethernet Octets Counter(etherStatsOctetsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TEOCTN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TEOCTN) + 1U;
    Counter->txEtherOctetCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Octets Counter Register(ifOutOctetsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TOCTN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TOCTN) + 1U;
    Counter->txOctetCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TXPFN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TXPFN) + 1U;
    Counter->txValidPauseFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TFRMN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TFRMN) + 1U;
    Counter->txFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Frame Check Sequence Error Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TFCSN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TFCSN) + 1U;
    Counter->txFrameCheckSequenceErrorCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit VLAN Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TVLANN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TVLANN) + 1U;
    Counter->txVlanFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Frame Error Counter Register(ifOutErrorsn) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TERRN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TERRN) + 1U;
    Counter->txFrameErrorCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Unicast Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TUCAN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TUCAN) + 1U;
    Counter->txUnicastFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Multicast Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TMCAN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TMCAN) + 1U;
    Counter->txMulticastFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Broadcast Frame Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TBCAN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TBCAN) + 1U;
    Counter->txBroadcastFrmCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Packets Counter Register(etherStatsPktsN; */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TPKTN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TPKTN) + 1U;
    Counter->txPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Undersized Packet Counter */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TUNDN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TUNDN) + 1U;
    Counter->txUndersizePacketCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T64N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T64N) + 1U;
    Counter->tx64OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T127N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T127N) + 1U;
    Counter->tx65to127OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T255N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T255N) + 1U;
    Counter->tx128to255OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T511N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T511N) + 1U;
    Counter->tx256to511OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T1023N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T1023N) + 1U;
    Counter->tx512to1023OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T1522N);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T1522N) + 1U;
    Counter->tx1024to1522OctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T1523XN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_T1523XN) + 1U;
    Counter->tx1523toMaxOctetPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Control Packet Counter Register */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TCNPN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TCNPN) + 1U;
    Counter->txControlPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TDFRN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TDFRN) + 1U;
    Counter->txDeferredPktCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Multiple Collisions Counter Register */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TMCOLN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TMCOLN) + 1U;
    Counter->txMultiCollisionCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Single Collision Counter Register */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TSCOLN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TSCOLN) + 1U;
    Counter->txSingleCollisionCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Late Collision Counter(aLateCollisions) Register */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TLCOLN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TLCOLN) + 1U;
    Counter->txLateCollisionCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* Port MAC index Transmit Excessive Collisions Counter Register */
    xCR0Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TECOLN);
    xCR1Value = (volatile uint32 *)(&Netc_EthSwt_Ip_PortBaseTable[portIndex]->PM0_TECOLN) + 1U;
    Counter->txExcessiveCollisionCounter = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);

    /* ERR051023: NETC: Excessive collisions are counted as late collisions */
    Counter->txLateCollisionCounter -= Counter->txExcessiveCollisionCounter;

    /* Port Tx discard count register */
    Counter->txDiscardCounter = Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->PTXDCR;

    /* Errata ERR051129: Uncorrectable non-fatal integrity error count register */
    Counter->unIntegrityErrorCounter = IP_NETC__SW0_COMMON->UNIECTR & NETC_F2_COMMON_UNIECTR_COUNT_MASK;

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

    (void)SwitchIdx;

    /* pseudo port indexes are starting after the mac ports. */
    PseudoPortIdx = SwitchPortIdx - NETC_ETHSWT_NUMBER_OF_MAC_PORTS;

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
    Counter->rxPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxFrmCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxVlanFrmCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxFrameErrorCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxUndersizePacketCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxOversizedPacketsCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxFrameCheckSequenceErrorCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxEtherOctetCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxValidPauseFrmCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxDroppedPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx64OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx65to127OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx128to255OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx256to511OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx512to1023OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx1024to1522OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rx1523toMaxOctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxJabberPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxFragmentPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxControlPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->rxDroppedNTruncatedPktCounter = 0xFFFFFFFFFFFFFFFFU;

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
    Counter->txPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txFrmCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txVlanFrmCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txFrameErrorCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txUndersizePacketCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txSingleCollisionCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txMultiCollisionCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txFrameCheckSequenceErrorCounter = 0xFFFFFFFFFFFFFFFFU;

    Counter->txEtherOctetCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txValidPauseFrmCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx64OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx65to127OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx128to255OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx256to511OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx512to1023OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx1024to1522OctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->tx1523toMaxOctetPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txControlPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txDeferredPktCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txLateCollisionCounter = 0xFFFFFFFFFFFFFFFFU;
    Counter->txExcessiveCollisionCounter = 0xFFFFFFFFFFFFFFFFU;

    /* Errata ERR051129: Uncorrectable non-fatal integrity error count register */
    Counter->unIntegrityErrorCounter = IP_NETC__SW0_COMMON->UNIECTR & NETC_F2_COMMON_UNIECTR_COUNT_MASK;

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
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_CBDRSTATUS_SUCCES;
    Netc_EthSwt_Ip_VlanFilterEntryDataType VlanFilterTableEntry;
    uint32 MatchedEntries = 0U;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    /* Query the entry with VlanId */
    VlanFilterTableEntry.VlanID = VlanId;
    CBDRStatus = Netc_EthSwt_Ip_QueryVlanFilterTableEntry(SwitchIdx, &MatchedEntries, &VlanFilterTableEntry);
    if ((CBDRStatus != NETC_ETHSWT_CBDRSTATUS_SUCCES) || (MatchedEntries == 0U))
    {
        Status = E_NOT_OK;        /* Query command error or no mached Vlan ID entry found */
    }
    else
    {
        /* Get the CFGE data of a mached entry */
        VlanFilterTableEntry.SpanningTreeGroupMemberId = (uint8)((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_STG_ID_SHIFT);
        VlanFilterTableEntry.PortMembershipBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA0] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_PORT_MEMBERSHIP_MASK;
        VlanFilterTableEntry.IpMulticastFloodingEnable = (((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFLE_SHIFT) != 0x0UL) ? TRUE : FALSE;
        VlanFilterTableEntry.IpMulticastFilteringEnable = (((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_IPMFE_SHIFT) != 0x0UL) ? TRUE : FALSE;
        VlanFilterTableEntry.MacForwardingOptions = (uint8)((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MFO_SHIFT);
        VlanFilterTableEntry.MacLearningOptions = (uint8)((TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_MASK) >> NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_MLO_SHIFT);
        VlanFilterTableEntry.FID = (uint16)(TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA1] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_FID_MASK);
        VlanFilterTableEntry.EgressTreatmentApplicabilityPortBitmap = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA2] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_ETA_PORT_BITMAP_MASK;
        VlanFilterTableEntry.BaseEgressTreatmentEntryID = TableDataBuffer.TableDataField[NETC_ETHSWT_VLANFILTERTABL_RSPDATA_CFGEDATA3] & NETC_ETHSWT_VLANFILTERTABLE_CFGEDATA_BASE_ET_EID_MASK;

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
        if (CBDRStatus != NETC_ETHSWT_CBDRSTATUS_SUCCES)
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
    NetcEthSwt_Ip_ReqHeaderTableOperationDataType OperationData;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    /* set the querry options with ENTRY_ID only querry */
    ActionsData = NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(1U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_DEBUG_OPTIONS(0U) \
                | NETC_ETHSWT_IP_FDBTABLE_REQFMT_ACTIONS_FIELD_ACTEU(0U) \
                | NETC_ETHSWT_IP_SWITCHTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);

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

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETHSWT_IP_CMDBD_REQFMT_PROTOCOL_VERSION;        /* protocol version = 2 */
    OperationData.TableId = NETC_ETHSWT_IP_FDB_TABLE_ID;
    OperationData.AccessMethod = NETC_ETHSWT_SEARCH_METHOD;                        /* delete all matched entries with Search Method */
    OperationData.Cmd = NETC_ETHSWT_DELETE_CMD;
    OperationData.ReqBuffLength = (NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN);
    OperationData.RspBuffLength = (NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN);

    /* send the "Delete" command */
    CBDRStatus = Netc_EthSwt_Ip_SendCommand(SwitchIdx, NETC_ETHSWT_IP_CBDR_0, &OperationData);
    if (CBDRStatus != NETC_ETHSWT_CBDRSTATUS_SUCCES)
    {
        status = E_NOT_OK;
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
    Std_ReturnType status = E_OK;
    uint32 MacLearningOption;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    MacLearningOption = IP_NETC__SW0_BASE->VFHTDECR2;
    MacLearningOption &= ~NETC_F2_VFHTDECR2_MLO_MASK;
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
    /* This dummy cast is done to support scalability in futures platforms. */
    (void)SwitchIdx;
    /* Hardware revision. */
    *HwVersion = IP_NETC__SW0_GLOBAL->IPBRR0;

    return E_OK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_InitCommandBDR
 * Description   : Internal function for initializing the command ring.
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_InitCommandBDR(uint8 SwitchIdx, uint8 cbdrIndex)
{
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;

    (void)SwitchIdx;

    /* check the index of command ring */
    if (cbdrIndex >= NETC_ETHSWT_IP_CBDR_NUM)
    {
        status = NETC_ETHSWT_CBDRSTATUS_INDEX_ERROR;
    }
    else
    {
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
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;

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
            status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
    }

    /* initialize CFGE_DATA. This portion is present only for commands which perform an update or add. */
    if (pCfgeData != NULL_PTR)
    {
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_CFGE_PORT_BITMAP_FIELD] = pCfgeData->Cfge_PortBitmap;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_CFGE_CONFIG_FIELD] = pCfgeData->Cfge_ConfigField;
        TableDataBuffer.TableDataField[NETC_ETHSWT_IP_FDBTABLE_CFGE_ETEID_FIELD] = pCfgeData->Cfge_EtEid;
    }

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
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;

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
            status = NETC_ETHSWT_CBDRSTATUS_ACCESSMETHOD_ERROR;
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

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_SendCommand
 * Description   : Internal function for adding an entry with different commands to command ring.
 *
 *END**************************************************************************/
static Netc_EthSwt_Ip_CBDRStatusType Netc_EthSwt_Ip_SendCommand(uint8 SwitchIdx, uint8 cbdrIndex, const NetcEthSwt_Ip_ReqHeaderTableOperationDataType *OperationData)
{
    uint32 producerIdx;
    uint32 consumerIdx;
    Netc_EthSwt_Ip_CBDRStatusType status = NETC_ETHSWT_CBDRSTATUS_SUCCES;
    uint32 PreviousProducerIdx;
    uint32 statusField;
    uint32 rrBit;
    uint32 errorField;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

    (void)SwitchIdx;

    /* read the producer and consumer index register */
    producerIdx = IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRPIR;
    consumerIdx = IP_NETC__SW0_BASE->NUM_CBDR[cbdrIndex].CBDRCIR;

    /* check if the ring is full */
    if (((producerIdx + 0x1UL) % ((uint32)(CmdBDRConfig[cbdrIndex].lengthCBDR) * NETC_ETHSWT_IP_SET_OF_BD)) == consumerIdx)
    {
        status = NETC_ETHSWT_CBDRSTATUS_RINGFULL;  /* the ring is full */
    }
    else
    {
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
        } while ((rrBit != 0x1U) && (FALSE == TimeExpired));        /* wait the hardware consume the command and check RR bit to see if the processing is completed (rrBit = 1). */
        /* --- to make sure the hardware consumes and processes the command completely --- */

        /* return the value of ERROR field in response data buffer indicating if there is an error for processing the command */
        errorField = ((statusField & (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_MASK)) >> (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_SHIFT));
        if (errorField != 0U)
        {
            status = errorField;     /* ERROR field should be 0. */
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
    if (producerIdx > 0U)
    {
        producerIdx -= 1U;
    }
    else /* producerIdx increased from 15 to 0, will set it to 15, or length minus 1 */
    {
        producerIdx = ((uint32)(CmdBDRConfig[cbdrIndex].lengthCBDR) * NETC_ETHSWT_IP_SET_OF_BD) - 0x1UL;
    }

    /* get status field in the response data buffer for the matched fdb entry */
    statusField = CmdBDRConfig[cbdrIndex].CmdBDAddr[producerIdx].MessageHeaderDataField[NETC_ETHSWT_IP_RSPHEADER_STATUS_FIELD_INDEX];

    /* NUM_MATCHED should equal or greater than 1 if the entry exists for any commands. */
    *NumOfEntry = (statusField & (NETC_ETHSWT_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_MASK));

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_GetCounters
 * Description   : Function for getting the counters of a port
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
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
    DevAssert(Counter != NULL_PTR);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
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
 * Function Name : Netc_EthSwt_Ip_GetCounters
 * Description   : Function for getting the counters of a port
 * implements Netc_EthSwt_Ip_GetCounter_Activity
 *END**************************************************************************/
Netc_EthSwt_Ip_CounterValueType Netc_EthSwt_Ip_GetCounter(uint8 SwitchIdx, uint8 SwitchPortIdx, Netc_EthSwt_Ip_SingleCounterType Counter)
{
    volatile uint32 *xCR0Value;
    volatile uint32 *xCR1Value;
    uint8 PseudoPortIdx;
    uint64 CounterValue = 0UL;

#if (STD_ON == NETC_ETHSWT_IP_DEV_ERROR_DETECT)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        /* Compute addres of the counter. for port 0 and port 1*/
        xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx] + (uint32)Counter);
        xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx] + (uint32)Counter) + 1U;
        CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
    }
    else
    {
        /* pseudo port indexes are starting after the mac ports. */
        PseudoPortIdx = SwitchPortIdx - NETC_ETHSWT_NUMBER_OF_MAC_PORTS;
        switch (Counter)
        {
            case NETC_ETHSWT_IP_RX_OCTETS_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMROCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMROCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_RX_UNICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMRUFCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMROCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_RX_MULTICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMRMFCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMRMFCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_RX_BROADCAST_FRM_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMRBFCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMRBFCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_TX_OCTETS_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTOCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTOCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_TX_UNICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTUFCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTUFCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_TX_MULTICAST_FRM_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTMFCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTMFCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            case NETC_ETHSWT_IP_TX_BROADCAST_FRM_COUNT:
                /* Compute addres of the counter. */
                xCR0Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTBFCR0));
                xCR1Value = (volatile uint32 *)((uint32)Netc_EthSwt_Ip_PseudoPortBaseTable[PseudoPortIdx] + (uint32)(NETC_ETHSWT_IP_PPMTBFCR1));
                CounterValue = (*xCR0Value) | ((uint64)(*xCR1Value) << NETC_ETHSWT_IP_32BIT_SHIFT);
                break;
            default:
                CounterValue = 0xFFFFFFFFFFFFFFFFU;
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
    Std_ReturnType status = E_OK;
    uint32 portCommandConfig = 0UL;

    (void)SwitchIdx;

    /* Read the register */
    portCommandConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG;

    /* Get the loop back mode value */
    if (SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        *LoopbackEnable = ((SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK & portCommandConfig) == 0U) ? FALSE : TRUE;
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
    Std_ReturnType status = E_OK;
    uint32 portCommandConfig = 0UL;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS);
#endif

    portCommandConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG
                        & ~SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK;

    /* Configure the loopback mode in the PM0_COMMAND_CONFIG */
    if (TRUE == LoopbackEnable)
    {
        portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK;
    }

    /* Write the PM0_COMMAND_CONFIG with the computed value */
    Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG = portCommandConfig;
    return status;
}

Std_ReturnType Netc_EthSwt_Ip_SetPortMacLayerDuplexMode( uint8 SwitchIdx, uint8 SwitchPortIdx,
                                                         Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                        )
{
    Std_ReturnType status = E_OK;
    uint32 interfaceModeConfig = 0UL;

    (void) SwitchIdx;
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        interfaceModeConfig = Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE;

        /* Is this RGMII mode == 4U */
        if ( SW_ETH_MAC_PORT_PM0_IF_MODE_IFMODE_RGMII_MODE == \
             ((interfaceModeConfig & SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_MASK) >> SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_SHIFT)
           )
        {
            /* Full duplex is 1 in SFD field */
            if(EthSwtPortMacLayerDuplexMode == NETC_ETHSWT_PORT_FULL_DUPLEX)
            {
                interfaceModeConfig |= SW_ETH_MAC_PORT0_PM0_IF_MODE_SFD_MASK;
            }
            else /* ETHTRCV_DUPLEX_MODE_HALF */
            {
                interfaceModeConfig &= ~SW_ETH_MAC_PORT0_PM0_IF_MODE_SFD_MASK;
            }
        }
        else
        {
            /* Full duplex is 0 in HD field */
            if(EthSwtPortMacLayerDuplexMode == NETC_ETHSWT_PORT_FULL_DUPLEX)
            {
                interfaceModeConfig &= ~SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_MASK;
            }
            else /* ETHTRCV_DUPLEX_MODE_HALF */
            {
                interfaceModeConfig |= SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_MASK;
            }
        }

        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE = interfaceModeConfig;
    }

    return status;
}

static inline Std_ReturnType RGMIIModeConfig(uint32 *interfaceModeConfig, uint32 *shapingPSpeedConfig, EthTrcv_BaudRateType EthSwtPortMacLayerSpeed, Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode)
{
    Std_ReturnType status = E_OK;

    /* Full duplex is 1 in SFD field */
    if (EthSwtPortMacLayerDuplexMode == NETC_ETHSWT_PORT_FULL_DUPLEX)
    {
        (*interfaceModeConfig) |= SW_ETH_MAC_PORT1_PM0_IF_MODE_SFD_MASK;
    }

    switch(EthSwtPortMacLayerSpeed)
    {
        case ETHTRCV_BAUD_RATE_10MBIT: /* 10Mbps */
        {
            (*interfaceModeConfig) |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_10MBIT));
            (*shapingPSpeedConfig) = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_100MBIT: /* 100Mbps */
        {
            (*interfaceModeConfig) |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_100MBIT));
            (*shapingPSpeedConfig) = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
            break;
        }
        case ETHTRCV_BAUD_RATE_1000MBIT: /* 1000Mbps */
        {
            (*interfaceModeConfig) |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_SSP(SW_ETH_MAC_PORT_PM0_IF_MODE_SSP_BAUD_RATE_1000MBIT));
            (*shapingPSpeedConfig) = NETC_ETHSWT_IP_SHAPING_PSPEED_1000MBITS;
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

static Std_ReturnType Netc_EthSwt_Ip_MacPortConfig( uint8 SwitchIdx, uint8 SwitchPortIdx,
                                                    Netc_EthSwt_Ip_XmiiModeType EthSwtPortPhysicalLayerType,
                                                    EthTrcv_BaudRateType EthSwtPortMacLayerSpeed,
                                                    Netc_EthSwt_Ip_PortDuplexType EthSwtPortMacLayerDuplexMode
                                                  )
{
    Std_ReturnType status = E_OK;
    uint32 interfaceModeConfig = 0UL;
    uint32 shapingPSpeedConfig = 0UL; /* used for shaping of the port */

    (void) SwitchIdx;

    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
    {
        /* Set the interface type */
        if (NETC_ETHSWT_RGMII_MODE == EthSwtPortPhysicalLayerType)
        {
            interfaceModeConfig |= (SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE(4U));
            status = RGMIIModeConfig(&interfaceModeConfig, &shapingPSpeedConfig, EthSwtPortMacLayerSpeed, EthSwtPortMacLayerDuplexMode);
        }
        else if (NETC_ETHSWT_RMII_MODE == EthSwtPortPhysicalLayerType)
        {
            interfaceModeConfig = (SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE(3U));
            /* Full duplex is 0 in HD field */
            if (EthSwtPortMacLayerDuplexMode == NETC_ETHSWT_PORT_FULL_DUPLEX)
            {
                interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_HD_MASK;
            }
            if(ETHTRCV_BAUD_RATE_10MBIT == EthSwtPortMacLayerSpeed)
            {
                interfaceModeConfig |= SW_ETH_MAC_PORT1_PM0_IF_MODE_M10_MASK;
                shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_10MBITS;
            }
        }
        else if (NETC_ETHSWT_MII_MODE == EthSwtPortPhysicalLayerType)
        {
            interfaceModeConfig = (SW_ETH_MAC_PORT1_PM0_IF_MODE_IFMODE(1U));
            shapingPSpeedConfig = NETC_ETHSWT_IP_SHAPING_PSPEED_100MBITS;
        }
        else
        {
            /* type error */
            status = E_NOT_OK;
        }

        /* Write the interface mode configuration in the register */
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_IF_MODE = interfaceModeConfig;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(shapingPSpeedConfig);
    }
    else
    {
	/* pseudo port */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR &= ~SW_PORT0_PCR_PSPEED_MASK;
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PCR |= SW_PORT0_PCR_PSPEED(NETC_ETHSWT_IP_SHAPING_PSPEED_2000MBITS);
    }

    return status;
}

/* inline function for configuring BPDVR */
static inline void ConfigBridgePortDefaultVlanReg(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
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
static inline void ConfigCreditBaseShaperReg(uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    uint8 shapingClass;
    uint32 localPtcTmSDUR;

    if(port->ePort->portShaper != NULL)
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

/* inline function for configuring PM0_COMMAND register */
static inline Std_ReturnType ConfigPM0CommandReg(uint8 SwitchIdx, uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    Std_ReturnType status = E_OK;
    uint32 portCommandConfig = 0UL;

    /* Start the PM0_COMMAND_CONFIG value with the TX padding option */
    portCommandConfig = SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_MASK;

    /* Construct several values to be used later based on whether the port is enabled or not */
    if (TRUE == port->EthSwtPortMacLayerPortEnable)
    {
        /* The pseudoport does not have the PM0_COMMAND_CONFIG register */
        if (SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
        {
            portCommandConfig |= SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK | SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK;
        }
    }
    else
    {
        /* Disable the port in POR register */
        Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->POR |= SW_PORT0_POR_TXDIS_MASK | SW_PORT0_POR_RXDIS_MASK;
    }

    /* The pseudoport does not have the following options */
    if (SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
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

        /* Write the PM0_COMMAND_CONFIG with the computed value */
        Netc_EthSwt_Ip_PortBaseTable[SwitchPortIdx]->PM0_COMMAND_CONFIG = portCommandConfig;

        /* Configure the interface mode, the speed and the duplex mode */
        status |= Netc_EthSwt_Ip_MacPortConfig( SwitchIdx, SwitchPortIdx, port->EthSwtPortPhysicalLayerType,
                                                port->EthSwtPortMacLayerSpeed, port->EthSwtPortMacLayerDuplexMode
                                                );
    }

    return status;
}

static Std_ReturnType Netc_EthSwt_Ip_InitPort(uint8 SwitchIdx, uint8 SwitchPortIdx, const Netc_EthSwt_Ip_PortType *port)
{
    Std_ReturnType status = E_OK;
    uint32 bridgePortConfig = 0UL;


    (void) SwitchIdx;
#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
#endif

    /* Port QOS mode */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PQOSMR = SW_PORT0_PQOSMR_VS(1U)
        | SW_PORT0_PQOSMR_VE(port->iPort->vlanEnable?1U:0U)
        | SW_PORT0_PQOSMR_DIPV(port->iPort->vlanDefaultIpv)
        | SW_PORT0_PQOSMR_DDR(port->iPort->vlanDefaultDr)
        | SW_PORT0_PQOSMR_VQMP(port->iPort->vlanMappingProfile)
        | SW_PORT0_PQOSMR_QVMP(port->ePort->vlanMappingProfile);

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->PPCPDEIMR = SW_PORT0_PPCPDEIMR_IPCPMPV(port->iPort->vlanEnableIngressPcpToPcpMapping?1U:0U)
        | SW_PORT0_PPCPDEIMR_IPCPMP(port->iPort->vlanIngressPcpToPcpProfile)
        | SW_PORT0_PPCPDEIMR_EPCPMPV(port->ePort->vlanEnableEgressPcpToPcpMapping?1U:0U)
        | SW_PORT0_PPCPDEIMR_EPCPMP(port->ePort->vlanEgressPcpToPcpProfile)
        | SW_PORT0_PPCPDEIMR_DRME(port->ePort->updateEgressDr?1U:0U)
        | SW_PORT0_PPCPDEIMR_DR0DEI(port->ePort->vlanDrToDei[0U])
        | SW_PORT0_PPCPDEIMR_DR1DEI(port->ePort->vlanDrToDei[1U])
        | SW_PORT0_PPCPDEIMR_DR2DEI(port->ePort->vlanDrToDei[2U])
        | SW_PORT0_PPCPDEIMR_DR3DEI(port->ePort->vlanDrToDei[3U]);

    /* Bridge Port Default Vlan register configuration */
    ConfigBridgePortDefaultVlanReg(SwitchPortIdx, port);

    /* PM0_COMMAND_CONFIG configuration */
    status = ConfigPM0CommandReg(SwitchIdx, SwitchPortIdx, port);

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

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->BPCR = bridgePortConfig;

    /* configure the credit base shaper */
    ConfigCreditBaseShaperReg(SwitchPortIdx, port);

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

    if(SwitchPortIdx < NETC_ETHSWT_NUMBER_OF_MAC_PORTS)
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

    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 &= ~SW_PORT0_PTCCBSR0_BW_MASK;
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 |= SW_PORT0_PTCCBSR0_BW(bandwidth);
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR1 = SW_PORT0_PTCCBSR1_HI_CREDIT(egressHiCredit);

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

    /* clear the bit first */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 &= ~SW_PORT0_PTCCBSR0_CBSE_MASK;
    /* write the bit */
    Netc_EthSwt_Ip_SW0_PortxBaseAddr[SwitchPortIdx]->TCT_NUM[TrafficClass].PTCCBSR0 |= SW_PORT0_PTCCBSR0_CBSE((TRUE==Enable)?1U:0U);

    return status;
}

/* inline function for configuring VlanIpvDr2PcpProfile */
static inline void ConfigVlanIpvDr2PcpProfile(const uint8 *IndexProfile, const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint8 IndexIpv;
    uint8 IndexDr;

    if(NULL_PTR != Config->vlanIpvDr2PcpProfile)
    {
        for (IndexDr=0U; IndexDr<NETC_ETHSWT_NUMBER_OF_DR; IndexDr++)
        { /* Shifted by NETC_ETHSWT_IP_FIELD_REP_IN_4BITS for each DR index */
            for (IndexIpv=0; IndexIpv<NETC_ETHSWT_NUMBER_OF_IPV; IndexIpv++)
            {
                /* Settings are divied in 4 registers by groups of 2 */
                if((IndexIpv % 2U) == 0U)
                { /* even IPV in lower bits */
                    IP_NETC__SW0_BASE->MAP_PCP[(*IndexProfile)].QOSVLANMPR[IndexIpv/2U] |= (uint32)((uint32)((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][IndexIpv][IndexDr])
                    & NETC_F2_QOSVLANMPR_IPV0_DR0_MASK)<<(IndexDr*NETC_ETHSWT_IP_FIELD_REP_IN_4BITS);
                }
                else
                {
                    IP_NETC__SW0_BASE->MAP_PCP[(*IndexProfile)].QOSVLANMPR[IndexIpv/2U] |= (uint32)((uint32)((*(Config->vlanIpvDr2PcpProfile))[(*IndexProfile)][IndexIpv][IndexDr])
                    & NETC_F2_QOSVLANMPR_IPV0_DR0_MASK)<<((IndexDr*NETC_ETHSWT_IP_FIELD_REP_IN_4BITS)+NETC_ETHSWT_IP_FIELD_REP_IN_TOP_OF_32BITS);
                }
            }
        }
    }
}

/* inline function for initializing Mapping profile */
static inline void InitMappingProfile(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint8 IndexProfile;
    uint8 IndexPcpDei;
    uint8 IndexPcp;

    /* Initialize the clasification mapping */
    for (IndexProfile=0U; IndexProfile<NETC_ETHSWT_NUMBER_OF_PROFILES; IndexProfile++)
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

        if(NULL_PTR != Config->vlanPcpDei2IpvProfile )
        {
            for (IndexPcpDei=0U; IndexPcpDei<NETC_ETHSWT_NUMBER_OF_PCP_DEI; IndexPcpDei++)
            {
                if(IndexPcpDei < (NETC_ETHSWT_NUMBER_OF_PCP_DEI/2U)) /* Setting are divided in 2 registers */
                {
                    IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANIPVMPR0 |= (((uint32)((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][IndexPcpDei]) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_MASK)<<(IndexPcpDei*NETC_ETHSWT_IP_FIELD_REP_IN_4BITS));
                }
                else
                {
                    IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANIPVMPR1 |= (((uint32)((*(Config->vlanPcpDei2IpvProfile))[IndexProfile][IndexPcpDei]) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_MASK)<<(IndexPcpDei/2U*NETC_ETHSWT_IP_FIELD_REP_IN_4BITS));
                }
            }
        }
        if(Config->vlanPcpDei2DrProfile != NULL_PTR)
        {
            for (IndexPcpDei=0U; IndexPcpDei<NETC_ETHSWT_NUMBER_OF_PCP_DEI; IndexPcpDei++)
            {
                IP_NETC__SW0_COMMON->NUM_PROFILE[IndexProfile].VLANDRMPR |= (((uint32)((*(Config->vlanPcpDei2DrProfile))[IndexProfile][IndexPcpDei]) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_MASK)<<(IndexPcpDei*NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_WIDTH));
            }
        }
        if(NULL_PTR != Config->vlanPcp2PcpProfile)
        {
            for (IndexPcp=0U; IndexPcp<NETC_ETHSWT_NUMBER_OF_PCP; IndexPcp++)
            {
                    IP_NETC__SW0_BASE->PCP2PCPMPR[IndexProfile] |= (((uint32)((*(Config->vlanPcp2PcpProfile))[IndexProfile][IndexPcp]) & NETC_F2_PCP2PCPMPR_PCP0_MASK)<<(IndexPcp*NETC_ETHSWT_IP_FIELD_REP_IN_4BITS));
            }
        }

        ConfigVlanIpvDr2PcpProfile(&IndexProfile, Config);
    }
}

/* inline function for initializing 1588 timer */
static inline void InitTimer1588(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint32 TimerRefClk;
    uint16 TimerClkPeriod;
    uint32 ClkAddendData;
    uint32 TimerClkAddend;

    if (Config->Timer1588ClkSrc == ETHSWT_EXTERNAL_REFERENCE_CLOCK)
    {
        TimerRefClk = Config->netcExternalClockFrequency;
        IP_NETC__TMR0_BASE->TMR_CTRL &= ~TMR0_BASE_TMR_CTRL_CK_SEL(1U);         /* select the external 200MHz clock for 1588 timer */
    }
    else
    {
        TimerRefClk = Config->netcClockFrequency;
        IP_NETC__TMR0_BASE->TMR_CTRL |= TMR0_BASE_TMR_CTRL_CK_SEL(1U);          /* select NETC system clock (default setting) for 1588 timer */
    }

    TimerClkPeriod = (uint16)(1000U/(TimerRefClk/1000000U));                              /* clock period = 1/200000000 = 5ns */
    ClkAddendData = (1000000U/(TimerRefClk/1000000U)) - (1000U * TimerClkPeriod);
    TimerClkAddend = (uint32)((((uint64)0x1U << NETC_ETHSWT_IP_32BIT_SHIFT) * ClkAddendData) / 1000U);

    /* FunctionTimer addend register holds the fractional part of the timer clock period */
    IP_NETC__TMR0_BASE->TMR_ADD = TMR0_BASE_TMR_ADD_ADDEND(TimerClkAddend);
    /* clear CLK_PERIOD data field first */
    IP_NETC__TMR0_BASE->TMR_CTRL &= ~TMR0_BASE_TMR_CTRL_TCLK_PERIOD(0x3FFF);
    IP_NETC__TMR0_BASE->TMR_CTRL |= TMR0_BASE_TMR_CTRL_TCLK_PERIOD(TimerClkPeriod);
    /* Enable timer */
    IP_NETC__TMR0_BASE->TMR_CTRL |= TMR0_BASE_TMR_CTRL_TE(1U);        /* FunctionTimer addend register holds the fractional part of the timer clock period */
    IP_NETC__TMR0_BASE->TMR_ADD = TMR0_BASE_TMR_ADD_ADDEND(TimerClkAddend);
    /* clear CLK_PERIOD data field first */
    IP_NETC__TMR0_BASE->TMR_CTRL &= ~TMR0_BASE_TMR_CTRL_TCLK_PERIOD(0x3FFF);
    IP_NETC__TMR0_BASE->TMR_CTRL |= TMR0_BASE_TMR_CTRL_TCLK_PERIOD(TimerClkPeriod);
    /* Enable timer */
    IP_NETC__TMR0_BASE->TMR_CTRL |= TMR0_BASE_TMR_CTRL_TE(1U);
}

/* inline function for initializing time gate scheduling table entries data during switch init */
static inline void InitTimeGateSchedulingTableEntryData(const Netc_EthSwt_Ip_ConfigType * Config)
{
    uint8 portIndex;
    uint8 GateControlListIdx;

    for (portIndex = 0U; portIndex < NETC_ETHSWT_NUMBER_OF_PORTS; portIndex++)
    {
        if ((*((*(Config)).port))[portIndex].ePort->portTimeAwareShaperEnable == TRUE)
        {
            /* set the flag for ports */
            PortTimeAwareShaperEnabled[portIndex] = TRUE;

            /* write register PTGSATOR. [Ricky}: not supported for now. follow up ticket needed. */
            /* TODO: Netc_EthSwt_Ip_SW0_PortxBaseAddr[portIndex]->RESERVED_7 should be equal to (*((*(Config)).port))[portIndex].ePort->portTimeGateSchedulingAdvanceTimeOffsetReg; */

            /* Fill in the data structure for time gate scheduling */
            TimeGateSchedulingEntryData[portIndex].TimeGateSchedulingTable_EID = portIndex;
            TimeGateSchedulingEntryData[portIndex].AdminBaseTime = (*((*(Config)).port))[portIndex].ePort->portEgressAdminBaseTime;
            TimeGateSchedulingEntryData[portIndex].AdminCycleTime = (*((*(Config)).port))[portIndex].ePort->portEgressAdminCycleTime;
            TimeGateSchedulingEntryData[portIndex].AdminCycleTimeExt = (*((*(Config)).port))[portIndex].ePort->portEgressAdminCycleTimeExt;
            TimeGateSchedulingEntryData[portIndex].AdminControlListLength = (*((*(Config)).port))[portIndex].ePort->numberOfGateControlListEntries;
            for (GateControlListIdx = 0U; GateControlListIdx < TimeGateSchedulingEntryData[portIndex].AdminControlListLength; GateControlListIdx++)
            {
                TimeGateSchedulingEntryData[portIndex].GateEntryAdminControlListData[GateControlListIdx].AdminTimeInterval = (*((*((*(Config)).port))[portIndex].ePort->TimeGateControlListEntries))[GateControlListIdx].AdminTimeInterval;
                TimeGateSchedulingEntryData[portIndex].GateEntryAdminControlListData[GateControlListIdx].AdminTrafficClassGateStates = (*((*((*(Config)).port))[portIndex].ePort->TimeGateControlListEntries))[GateControlListIdx].AdminTrafficClassGateStates;
                TimeGateSchedulingEntryData[portIndex].GateEntryAdminControlListData[GateControlListIdx].AdminGateOperationType = (*((*((*(Config)).port))[portIndex].ePort->TimeGateControlListEntries))[GateControlListIdx].AdminGateOperationType;
            }
        }
    }
}

/*  Workaround for ERR051130: 
    Egress time gate scheduling can get corrupted when functional level reset is applied or when time gating is disabled 
*/
/* Added 2 fake time gate control list entries for clearing the internal context for time gate scheduling feature */
static Netc_EthSwt_Ip_CBDRStatusType InitTimeGateSchedulingFeature(uint8 SwitchIdx, uint8 SwitchPortIdx)
{
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus = NETC_ETHSWT_CBDRSTATUS_SUCCES;
    volatile uint64 CurrentTime = 0;
    uint8 EntryIdx;

    /* fill in struct Netc_EthSwt_Ip_TimeGateSchedulingEntryDataType */
    TimeGateSchedulingEntryData[0U].TimeGateSchedulingTable_EID = SwitchPortIdx;
    TimeGateSchedulingEntryData[0U].AdminCycleTime = 4000000U;           /* it should be greater than the sum of time interval */
    TimeGateSchedulingEntryData[0U].AdminCycleTimeExt = 100000U;
    TimeGateSchedulingEntryData[0U].AdminControlListLength = 2U;         /* 2 entries */

    /* get the current time from 1588 timer */
    CurrentTime = IP_NETC__TMR0_BASE->TMR_CUR_TIME_L;      /* should read the Lower register first */
    CurrentTime |= ((uint64)(IP_NETC__TMR0_BASE->TMR_CUR_TIME_H)) << NETC_ETHSWT_IP_32BIT_SHIFT;
    TimeGateSchedulingEntryData[0U].AdminBaseTime = CurrentTime;        /* set base time to current time */

    /* fill in gate control list entries data */
    for (EntryIdx = 0U; EntryIdx < TimeGateSchedulingEntryData[0U].AdminControlListLength; EntryIdx++)
    {
        TimeGateSchedulingEntryData[0U].GateEntryAdminControlListData[EntryIdx].AdminTimeInterval = 2000000U;        /* the value is equal to transmit 128bytes + 20 bytes (header) frame with port speed 10M */
        TimeGateSchedulingEntryData[0U].GateEntryAdminControlListData[EntryIdx].AdminTrafficClassGateStates = 0xFFU;      /* all open */
        TimeGateSchedulingEntryData[0U].GateEntryAdminControlListData[EntryIdx].AdminGateOperationType = ETHSWT_HOST_REQUEST_UNCHANGED;
    }

    /* add these 2 gate control list entries */
    CBDRStatus = Netc_EthSwt_Ip_ConfigPortTimeGateScheduling(SwitchIdx, SwitchPortIdx, TRUE);
    
    return CBDRStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_Init
 * Description   : function for initializing a switch
 * implements Netc_EthSwt_Ip_Init_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_Init(uint8 SwitchIdx, const Netc_EthSwt_Ip_ConfigType * Config)
{
    Std_ReturnType status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint8 portIndex;
    uint8 enabledPortMask = 0U;

#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
    uint32 MatchedEntries = 0U;
    uint8 MacAddrByteIdx;
    uint8 FdbEntryIdx;
    Netc_EthSwt_Ip_FdbEntryDataType FdbTableEntry = {0};
#endif
#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
    uint32 VlanMatchedEntries = 0U;
    uint8 VlanEntryIdx;
    Netc_EthSwt_Ip_VlanFilterEntryDataType VlanFilterEntryData = {0};
#endif

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(Config != NULL_PTR);
#endif

    /* Enable PCIE for the TIMER */
    IP_NETC__NETC_F0_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
    /* Enable PCIE for the MDIO */
    IP_NETC__NETC_F1_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
    /* Enable PCIE for the Switch */
    IP_NETC__NETC_F2_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);
    /* Enable PCIE for the ENETC */
    IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);

    status = Netc_EthSwt_Ip_IerbReady();

    if(status == (uint8)(E_OK))
    {
        Netc_EthSwt_Ip_NetcClockFrequency = Config->netcClockFrequency;

        if(Config->EthSwtEnableSharedLearning)
        {
            IP_NETC__SW0_BASE->VFHTDECR1 = NETC_F2_VFHTDECR1_VL_MODE(1U) | NETC_F2_VFHTDECR1_FID(0U);
        }
        else
        {
            IP_NETC__SW0_BASE->VFHTDECR1 = NETC_F2_VFHTDECR1_VL_MODE(0U);
        }

        IP_NETC__SW0_BASE->FDBHTMCR = NETC_F2_FDBHTMCR_DYN_LIMIT(Config->EthSwtMaxDynamicEntries);
        IP_NETC__SW0_COMMON->CVLANR1 = NETC_F2_COMMON_CVLANR1_V(Config->EthSwtCustomVlanEtherType1);
        IP_NETC__SW0_COMMON->CVLANR2 = NETC_F2_COMMON_CVLANR2_ETYPE(Config->EthSwtCustomVlanEtherType2);

        /* Mapping profile initialization */
        InitMappingProfile(Config);

        /* Initialize the ports of the switch */
        for (portIndex = 0U; portIndex < NETC_ETHSWT_NUMBER_OF_PORTS; portIndex++)
        {
            status = Netc_EthSwt_Ip_InitPort(SwitchIdx, portIndex, &(*((*(Config)).port))[portIndex]);

            if (TRUE == (*((*(Config)).port))[portIndex].EthSwtPortMacLayerPortEnable)
            {
                enabledPortMask |= (1U << portIndex);
            }
        }

        status |= Netc_EthSwt_Ip_EMDIOConfiguration(0U);  /* init EMDIO configuration register */

        /* Configure the VLAN filter hash default settings */
        IP_NETC__SW0_BASE->VFHTDECR0 = enabledPortMask; /* Add enabled ports to the default VLAN */
        /* To add Shared learning setting in EBT */
        /* set configured learning and forwarding options */
        IP_NETC__SW0_BASE->VFHTDECR2 = NETC_F2_VFHTDECR2_MLO(Config->MacLearningOption) | NETC_F2_VFHTDECR2_MFO(Config->MacForwardingOption);

        /* used for port aging, value in sec */
        Netc_EthSwt_Ip_FdbTableEntryTimeout = Config->EthSwtArlTableEntryTimeout;

        /* +++ initialize 1588 timer for time gate scheduling +++ */
        InitTimer1588(Config);
        /* --- initialize 1588 timer for time gate scheduling --- */

        /* initialize memory and length for command ring 0 and 1 */
        CmdBDRConfig[NETC_ETHSWT_IP_CBDR_0].CmdBDAddr = &SwtcommandRingDescriptor0[0U];
        CmdBDRConfig[NETC_ETHSWT_IP_CBDR_0].lengthCBDR = (NETC_ETHSWT_IP_CBDR0_LENGTH);
        CmdBDRConfig[NETC_ETHSWT_IP_CBDR_1].CmdBDAddr = &SwtcommandRingDescriptor1[0U];
        CmdBDRConfig[NETC_ETHSWT_IP_CBDR_1].lengthCBDR = (NETC_ETHSWT_IP_CBDR1_LENGTH);

        /* intialize command ring 0 */
        CBDRStatus = Netc_EthSwt_Ip_InitCommandBDR(0U, NETC_ETHSWT_IP_CBDR_0);
        if (NETC_ETHSWT_CBDRSTATUS_SUCCES == CBDRStatus)
        {
#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
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
                if ((CBDRStatus != NETC_ETHSWT_CBDRSTATUS_SUCCES) || (MatchedEntries != 0U))
                {
                    status = E_NOT_OK;
                    break;
                }

            }
#endif

#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
            /* Add Vlan Filter entries */
            for (VlanEntryIdx = 0U; VlanEntryIdx < Config->NumberOfVlanFilterEntries; VlanEntryIdx++)
            {
                /* fill in VlanFilterEntryData structure  */
                VlanFilterEntryData.VlanID = (*(Config->VlanFilterEntries))[VlanEntryIdx].vlanId;
                VlanFilterEntryData.PortMembershipBitmap = (*(Config->VlanFilterEntries))[VlanEntryIdx].iPortMask;

                VlanFilterEntryData.FID = (0U);
                VlanFilterEntryData.MacLearningOptions = (2U);                  /* enable mac learning */
                VlanFilterEntryData.MacForwardingOptions = (2U);                /* FDB lookup, if there is no match, then frame is flooded */
                VlanFilterEntryData.IpMulticastFloodingEnable = FALSE;          /* IP multicast flooding disable */
                VlanFilterEntryData.IpMulticastFilteringEnable = FALSE;         /* IP multicast filtering disable */
                VlanFilterEntryData.BaseEgressTreatmentEntryID = 0xFFFFFFFFUL;    /* egress treatment processing is by-passed */

                CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateVlanFilterTableEntry(0U, NETC_ETHSWT_ADD_CMD, &VlanMatchedEntries, &VlanFilterEntryData);
                /* fail to add the Vlan Filter entry */
                if ((CBDRStatus != NETC_ETHSWT_CBDRSTATUS_SUCCES) || (VlanMatchedEntries != 0U))
                {
                    status = E_NOT_OK;
                    break;
                }
            }
#endif

            /* check if TAS is enabled or not */
            PortTimeAwareShaperEnabled[0U] = ((*((*(Config)).port))[0U].ePort->portTimeAwareShaperEnable || 
                                              (*((*(Config)).port))[1U].ePort->portTimeAwareShaperEnable ||
                                              (*((*(Config)).port))[2U].ePort->portTimeAwareShaperEnable) ? TRUE : FALSE;

            if (TRUE ==  PortTimeAwareShaperEnabled[0U])
            {
                /* Default time gate scheduling conditions on the port 0 */
                CBDRStatus = InitTimeGateSchedulingFeature(SwitchIdx, 0U);
                if (CBDRStatus != NETC_ETHSWT_CBDRSTATUS_SUCCES)
                {
                    status = E_NOT_OK;
                }
                else
                {
                    /* Add time gate scheduling table entries data */
                    InitTimeGateSchedulingTableEntryData(Config);
                }
            }
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

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ReadTrcvRegister
 * Description   : External function for reading the content of a transceiver register
 * implements Netc_EthSwt_Ip_ReadTrcvRegister_Activity
 *END**************************************************************************/
Std_ReturnType Netc_EthSwt_Ip_ReadTrcvRegister( uint8 SwitchIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 * RegVal )
{
    Std_ReturnType Status = E_NOT_OK;
    uint32 CtrlData;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    CtrlData = NETC_F1_EMDIO_CTL_PORT_ADDR(TrcvIdx) | NETC_F1_EMDIO_CTL_DEV_ADDR(RegIdx) \
             | NETC_F1_EMDIO_CTL_READ(1U);

    /* config EMDIO_CTL register */
    IP_NETC__EMDIO_BASE->EMDIO_CTL = CtrlData;

    /* Wait till MDIO transaction is occuring and no read error is detected */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do
    {
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

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_EthSwt_Ip_ReadTrcvRegister
 * Description   : External function for writing the content of a transceiver register
 * implements Netc_EthSwt_Ip_WriteTrcvRegister_Activity
 *END**************************************************************************/
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

    CtrlData = NETC_F1_EMDIO_CTL_PORT_ADDR(TrcvIdx) | NETC_F1_EMDIO_CTL_DEV_ADDR(RegIdx);

    /* config EMDIO_CTL register */
    IP_NETC__EMDIO_BASE->EMDIO_CTL = CtrlData;

    /* Write MDIO_DATA for initiating write transaction to PHY */
    IP_NETC__EMDIO_BASE->EMDIO_DATA = RegVal;

    /* Wait till MDIO transaction is occuring */
    Netc_EthSwt_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETHSWT_IP_TIMEOUT_VALUE_US);
    do
    {
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

#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
#endif

    if (TRUE == MirrorConfigurationDone)
    {
        if (MirroringIngressPortFilterEntryId != NETC_ETHSWT_IP_BD_NULL_ENTRY_ID)
        {
            /* Delete ingress port filter entry */
            CBDRStatus = Netc_EthSwt_Ip_DeleteIngressPortFilterTableEntry(MirroredSwitchIdx, &MatchedEntries, MirroringIngressPortFilterEntryId);
            if ((NETC_ETHSWT_CBDRSTATUS_SUCCES != CBDRStatus) || (0U == MatchedEntries))
            {
                Status = E_NOT_OK;
            }
            else
            {
                /* Set ingress port filter entry to NULL again */
                MirroringIngressPortFilterEntryId = NETC_ETHSWT_IP_BD_NULL_ENTRY_ID;
            }
        }

        /* Delete Frame modificatin entry */
        MIRDestBit = (uint8)((IP_NETC__SW0_BASE->IMDCR0 & NETC_F2_IMDCR0_MIRDEST_MASK) >> NETC_F2_IMDCR0_MIRDEST_SHIFT);
        EFMEntryId = (uint16)(IP_NETC__SW0_BASE->IMDCR1 & NETC_F2_IMDCR1_EFMEID_MASK);
        if ((EFMEntryId != 0xFFFFU) && (MIRDestBit == 0U))
        {
            CBDRStatus = Netc_EthSwt_Ip_DeleteFrmModificationTableEntry(MirroredSwitchIdx, EFMEntryId, &MatchedEntries);
            if ((NETC_ETHSWT_CBDRSTATUS_SUCCES != CBDRStatus) || (0U == MatchedEntries))
            {
                Status = E_NOT_OK;
            }
            else
            {
                EFMEntryId = (uint16)(NETC_F2_IMDCR1_EFMEID(0xFFFFU));        /* set frame modification table entry ID to NULL */
                IP_NETC__SW0_BASE->IMDCR1 |= EFMEntryId;
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

    return Status;
}

/* inline function for checking if mac address filter enabled or not */
static inline void CheckMacAddressFilterEnableFlag(boolean *SrcMacAddrFilterEnabled, boolean *DstMacAddrFilterEnabled, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr)
{
    uint8 MacByteIdx;

    for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
    {
        if (MirrorConfigurationPtr->SrcMacAddrFilter[MacByteIdx] != 0x0U)
        {
            *SrcMacAddrFilterEnabled = TRUE;
            break;
        }
    }
    for (MacByteIdx = 0U; MacByteIdx < NETC_ETHSWT_IP_MACADDRLEN; MacByteIdx++)
    {
        if (MirrorConfigurationPtr->DstMacAddrFilter[MacByteIdx] != 0x0U)
        {
            *DstMacAddrFilterEnabled = TRUE;
            break;
        }
    }
}

/* inline function for enabling mac address filtering */
static inline Std_ReturnType ConfigAndEnableIngressPortFiltering(uint8 MirroredSwitchIdx, const boolean *SrcMacAddrFilterEnabled,
                                                                 const boolean *DstMacAddrFilterEnabled,
                                                                 const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr,
                                                                 Netc_EthSwt_Ip_IngressPortFilterEntryDataType *IngressPortFilterTableEntry
                                                                )
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint8 MacByteIdx;
    uint8 PayloadByteIdx;
    uint32 MatchedEntries;

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
        if (*DstMacAddrFilterEnabled == TRUE)
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

        if (*SrcMacAddrFilterEnabled == TRUE)
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
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence = 0xFFFFU;      /* precedence, maximum priority */

    if (MirrorConfigurationPtr->VlanIdFilter != 0xFFFFU)
    {
        MirrorCfgBackup.VlanIdFilter = MirrorConfigurationPtr->VlanIdFilter;

        /* vlan id filter */
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = 0xFFF0U;
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation = (MirrorConfigurationPtr->VlanIdFilter);
    }
    else
    {
        MirrorCfgBackup.VlanIdFilter = 0xFFFFU;
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = 0x0U;
    }

    CBDRStatus = Netc_EthSwt_Ip_AddIngressPortFilterTableEntry(MirroredSwitchIdx, &MatchedEntries, IngressPortFilterTableEntry);
    if ((NETC_ETHSWT_CBDRSTATUS_SUCCES != CBDRStatus) || (1U == MatchedEntries))
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
static inline Std_ReturnType ConfigAndEnableEgressFramesModification(uint8 MirroredSwitchIdx, const Netc_EthSwt_Ip_SwitchMirrorCfgType* MirrorConfigurationPtr)
{
    Std_ReturnType Status = E_OK;
    Netc_EthSwt_Ip_CBDRStatusType CBDRStatus;
    uint32 RegIMDCR1 = 0x0UL;
    uint32 MatchedEntries = 0x0UL;
    Netc_EthSwt_Ip_FrmModificationEntryDataType FrmModificationEntry = {0};

    if (MirrorConfigurationPtr->MirroringMode != NETC_ETHSWT_NO_VLAN_RETAGGING)
    {
        /* config and add one frame modification table entry for modifying the dest mac address */
        FrmModificationEntry.FrmModificationEntryID = NETC_ETHSWT_EFMEID_FOR_MIRRORING;                   /* default frame modification table entry ID for mirroring */
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
        FrmModificationEntry.FrmModificationDataEntryID = 0xFFFFFFFFUL;     /* frame modification data table entry id */

        CBDRStatus = Netc_EthSwt_Ip_AddOrUpdateFrmModificationTableEntry(MirroredSwitchIdx, NETC_ETHSWT_ADD_CMD, &MatchedEntries, &FrmModificationEntry);
        if (NETC_ETHSWT_CBDRSTATUS_SUCCES == CBDRStatus)
        {
            /* [IMDCR0]: keep IPV and DR default in IMDCR0 register */
            /* [IMDCR1] */
            RegIMDCR1 = NETC_F2_IMDCR1_EFM_LEN_CHANGE(NETC_ETHSWT_EFM_LEN_CHANGE_FOR_MIRRORING);
            RegIMDCR1 |= NETC_F2_IMDCR1_EFMEID(NETC_ETHSWT_EFMEID_FOR_MIRRORING);        /* default frame modification table entry ID for mirroring */
            IP_NETC__SW0_BASE->IMDCR1 = RegIMDCR1;
        }
        else
        {
            Status = E_NOT_OK;
        }
    }

    return Status;
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
    uint8 PortIdx;
    uint32 IngressBitMask;
    boolean DstMacAddrFilterEnabled = FALSE;
    boolean SrcMacAddrFilterEnabled = FALSE;
    Netc_EthSwt_Ip_IngressPortFilterEntryDataType IngressPortFilterTableEntry = {0};


#if(NETC_ETHSWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(MirroredSwitchIdx < FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS);
    DevAssert(MirrorConfigurationPtr != NULL_PTR);
    DevAssert(MirrorConfigurationPtr->CapturePortIdx < NETC_ETHSWT_NUMBER_OF_PORTS);
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

        RegIMDCR1 = NETC_F2_IMDCR1_EFMEID(0xFFFFU);        /* set frame modification table entry ID to NULL */
        IP_NETC__SW0_BASE->IMDCR1 |= RegIMDCR1;

        /* check if Mac Address Filter enabled */
        CheckMacAddressFilterEnableFlag(&SrcMacAddrFilterEnabled, &DstMacAddrFilterEnabled, MirrorConfigurationPtr);

        /* Start writing mirroring configuration */
        /* #1 */
        if ((MirrorConfigurationPtr->VlanIdFilter == 0xFFFFU) && (DstMacAddrFilterEnabled == FALSE) && (SrcMacAddrFilterEnabled == FALSE))
        {
            /* Enable port mirroring according to TrafficDirectionIngressBitMask */
            IngressBitMask = MirrorConfigurationPtr->TrafficDirectionIngressBitMask;
            for(PortIdx = 0U; PortIdx < NETC_ETHSWT_NUMBER_OF_PORTS; PortIdx++)
            {
                if((IngressBitMask & 0x1U) == 0x1U)
                {
                    Netc_EthSwt_Ip_SW0_PortxBaseAddr[PortIdx]->PMCR = (uint32)0x1U;
                }
                IngressBitMask >>= 1U;
            }
        }
        else    /* #2 ingress port filtering */
        {
            /* using bitmask to enable port filtering */
            IngressBitMask = MirrorConfigurationPtr->TrafficDirectionIngressBitMask;
            for(PortIdx = 0U; PortIdx < NETC_ETHSWT_NUMBER_OF_PORTS; PortIdx++)
            {
                if((IngressBitMask & 0x1U) == 0x1U)
                {
                    /* Enable ingress port filter table lookup function for ports */
                    Status = Netc_EthSwt_Ip_EnableIngressPortFiltering(MirroredSwitchIdx, PortIdx, TRUE);
                }
                IngressBitMask >>= 1U;
            }

            /* Config and add the ingress port filter table entry for ingress frames filtering */
            Status |= ConfigAndEnableIngressPortFiltering(MirroredSwitchIdx, &SrcMacAddrFilterEnabled, &DstMacAddrFilterEnabled, MirrorConfigurationPtr, &IngressPortFilterTableEntry);
        }

        /* #3 egress frame modification */
        Status |= ConfigAndEnableEgressFramesModification(MirroredSwitchIdx, MirrorConfigurationPtr);

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
        MirrorConfigurationPtr->VlanIdFilter = 0xFFFFU;
        MirrorConfigurationPtr->MirroringMode = NETC_ETHSWT_NO_VLAN_RETAGGING;
        MirrorConfigurationPtr->VlanId = 0xFFFFU;
        MirrorConfigurationPtr->CapturePortIdx = 0U;
        MirrorConfigurationPtr->TrafficDirectionIngressBitMask = 0x0UL;
    }

    return Status;
}

#define ETHSWT_43_NETC_STOP_SEC_CODE
#include "EthSwt_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
