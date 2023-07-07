/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup GMAC_DRIVER GMAC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip.h"
#include "Gmac_Ip_Hw_Access.h"
#include "Gmac_Ip_TrustedFunctions.h"

#if (STD_ON == GMAC_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == GMAC_IP_DEV_ERROR_DETECT) */

#if (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
#endif /* (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE) */

#if(GMAC_HAS_CACHE_MANAGEMENT == STD_ON)
    #include "Cache_Ip.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_VENDOR_ID_C                      43
#define GMAC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define GMAC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define GMAC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define GMAC_IP_SW_MAJOR_VERSION_C               3
#define GMAC_IP_SW_MINOR_VERSION_C               0
#define GMAC_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip.h */
#if (GMAC_IP_VENDOR_ID_C !=  GMAC_IP_VENDOR_ID)
    #error "Gmac_Ip.c and Gmac_Ip.h have different vendor ids"
#endif
#if (( GMAC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  GMAC_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_MINOR_VERSION_C    !=  GMAC_IP_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_REVISION_VERSION_C !=  GMAC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip.c and Gmac_Ip.h are different"
#endif
#if (( GMAC_IP_SW_MAJOR_VERSION_C !=  GMAC_IP_SW_MAJOR_VERSION) || \
     ( GMAC_IP_SW_MINOR_VERSION_C !=  GMAC_IP_SW_MINOR_VERSION) || \
     ( GMAC_IP_SW_PATCH_VERSION_C !=  GMAC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip.c and Gmac_Ip.h are different"
#endif

/* Checks against Gmac_Ip_Hw_Access.h */
#if (GMAC_IP_VENDOR_ID_C !=  GMAC_IP_HW_ACCESS_VENDOR_ID)
    #error "Gmac_Ip.c and Gmac_Ip_Hw_Access.h have different vendor ids"
#endif
#if (( GMAC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_MINOR_VERSION_C    !=  GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_REVISION_VERSION_C !=  GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip.c and Gmac_Ip_Hw_Access.h are different"
#endif
#if (( GMAC_IP_SW_MAJOR_VERSION_C !=  GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     ( GMAC_IP_SW_MINOR_VERSION_C !=  GMAC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     ( GMAC_IP_SW_PATCH_VERSION_C !=  GMAC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip.c and Gmac_Ip_Hw_Access.h are different"
#endif

/* Checks against Gmac_Ip_TrustedFunctions.h */
#if (GMAC_IP_VENDOR_ID_C !=  GMAC_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Gmac_Ip.c and Gmac_Ip_TrustedFunctions.h have different vendor ids"
#endif
#if (( GMAC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_MINOR_VERSION_C    !=  GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_REVISION_VERSION_C !=  GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip.c and Gmac_Ip_TrustedFunctions.h are different"
#endif
#if (( GMAC_IP_SW_MAJOR_VERSION_C !=  GMAC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     ( GMAC_IP_SW_MINOR_VERSION_C !=  GMAC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     ( GMAC_IP_SW_PATCH_VERSION_C !=  GMAC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip.c and Gmac_Ip_TrustedFunctions.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        /* Checks against RegLockMacros.h */
        #if ((GMAC_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (GMAC_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Gmac_Ip.h and RegLockMacros.h are different"
        #endif
    #endif /* (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE) */

     /* Checks against Devassert.h*/
    #if (STD_ON == GMAC_IP_DEV_ERROR_DETECT)
        #if (( GMAC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            ( GMAC_IP_AR_RELEASE_MINOR_VERSION_C    !=  DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Gmac_Ip.c and Devassert.h are different"
        #endif
    #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define GMAC_TX_STAT_ERR_MASK    (0x00007F0DU)
#define GMAC_TX_STAT_TTSS_MASK   (0x00020000U)
#define GMAC_RX_STAT_ERR_MASK    (0x01F80000U)

#define GMAC_TDES3_CPC(x)       (((uint32)(((uint32)(x)) << 26U)) & 0x0C000000U)
#define GMAC_TDES3_CIC(x)       (((uint32)(((uint32)(x)) << 16U)) & 0x00030000U)
#define GMAC_TDES3_OWN_MASK     (0x80000000U)
#define GMAC_TDES3_FD_MASK      (0x20000000U)
#define GMAC_TDES3_LD_MASK      (0x10000000U)

#define GMAC_TDES2_IOC_MASK     (0x80000000U)
#define GMAC_TDES2_TTSE_MASK    (0x40000000U)

#define GMAC_RDES0_IVT_MASK     (0xFFFF0000U)
#define GMAC_RDES0_IVT_SHIFT    (16U)
#define GMAC_RDES0_OVT_MASK     (0x0000FFFFU)

#define GMAC_RDES1_TSA_MASK     (0x00004000U)
#define GMAC_RDES1_IPCE_MASK    (0x00000080U)
#define GMAC_RDES1_IPV6_MASK    (0x00000020U)
#define GMAC_RDES1_IPV4_MASK    (0x00000010U)
#define GMAC_RDES1_IPHE_MASK    (0x00000008U)
#define GMAC_RDES1_PT_MASK      (0x00000007U)

#define GMAC_RDES3_PL_MASK      (0x00007FFFU)
#define GMAC_RDES3_OWN_MASK     (0x80000000U)
#define GMAC_RDES3_INTE_MASK    (0x40000000U)
#define GMAC_RDES3_BUF1V_MASK   (0x01000000U)
#define GMAC_RDES3_RS1V_MASK    (0x04000000U)
#define GMAC_RDES3_RS0V_MASK    (0x02000000U)

#define GMAC_RDES3_CTXT_MASK    (0x40000000U)

#define GMAC_INFO1_CONSUMED_MASK  (0x01000000U)
#define GMAC_INFO1_LOCKED_MASK    (0x10000000U)
#define GMAC_INFO1_LENGTH_MASK    (0x00003FFFU)

#define GMAC_BYTE_5_IN_ADDR_SHIFT   (8U)
#define GMAC_BYTE_4_IN_ADDR_SHIFT   (0U)
#define GMAC_BYTE_3_IN_ADDR_SHIFT   (24U)
#define GMAC_BYTE_2_IN_ADDR_SHIFT   (16U)
#define GMAC_BYTE_1_IN_ADDR_SHIFT   (8U)
#define GMAC_BYTE_0_IN_ADDR_SHIFT   (0U)

#define GMAC_GCRA_LOWER_BTR         ((uint16)0U)
#define GMAC_GCRA_UPPER_BTR         ((uint16)1U)
#define GMAC_GCRA_LOWER_CTR         ((uint16)2U)
#define GMAC_GCRA_UPPER_CTR         ((uint16)3U)
#define GMAC_GCRA_TER               ((uint16)4U)
#define GMAC_GCRA_LLR               ((uint16)5U)

#define GMAC_MAC_HW_ADDRESS1_HIGH_RESET_MASK    (0x0000FFFFU)
#define GMAC_MAC_HW_ADDRESS1_LOW_RESET_MASK     (0xFFFFFFFFU)

#define GMAC_SYS_TIME_SEC_MAX_VALUE      (0x100000000U)
#define GMAC_SYS_TIME_NANOSEC_MAX_VALUE  (0x03B9ACA00U)

#define GMAC_MAX_WEIGHT_VALUE            (0x64U)

#define GMAC_BYTE_MASK                   (0xFFU)

#define GMAC_MDIO_CSR_NO                 (9U)

#define GMAC_BUFFDESCR_IS_ALIGNED(x)         (((uint32)(x) & (FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BYTES - 1UL)) == 0UL)
#define GMAC_BUFF_IS_ALIGNED(x)              (((uint32)(x) & (FEATURE_GMAC_BUFF_ALIGNMENT_BYTES - 1UL)) == 0UL)
#define GMAC_BUFFLEN_IS_ALIGNED(x)           (((uint32)(x) & (FEATURE_GMAC_BUFFLEN_ALIGNMENT_BYTES - 1UL)) == 0UL)
#define GMAC_TXRINGLEN_IS_BLOCK_ALIGNED(x)   (((uint32)(x) & (FEATURE_GMAC_TXRINGLEN_ALIGNMENT_BYTES - 1UL)) == 0UL)
#define GMAC_RXRINGLEN_IS_BLOCK_ALIGNED(x)   (((uint32)(x) & (FEATURE_GMAC_RXRINGLEN_ALIGNMENT_BYTES - 1UL)) == 0UL)

#define GMAC_CH_NORMAL_INTERRUPTS   ((uint32)GMAC_DMA_CH0_STATUS_TI_MASK | (uint32)GMAC_DMA_CH0_STATUS_TBU_MASK | (uint32)GMAC_DMA_CH0_STATUS_RI_MASK | \
        (uint32)GMAC_DMA_CH0_STATUS_ERI_MASK)
#define GMAC_CH_ABNORMAL_INTERRUPTS ((uint32)GMAC_DMA_CH0_STATUS_TPS_MASK | (uint32)GMAC_DMA_CH0_STATUS_RBU_MASK | (uint32)GMAC_DMA_CH0_STATUS_RPS_MASK | \
        (uint32)GMAC_DMA_CH0_STATUS_ETI_MASK | (uint32)GMAC_DMA_CH0_STATUS_FBE_MASK | (uint32)GMAC_DMA_CH0_STATUS_CDE_MASK)

#if (GMAC_IP_DEV_ERROR_DETECT == STD_ON)
    #define GMAC_DEV_ASSERT(x)      DevAssert(x)
#else
    #define GMAC_DEV_ASSERT(x)
#endif

#if (GMAC_IP_DEV_ERROR_DETECT == STD_ON)
    #define DEFINE_ERROR_VAR(type, var_name)    type var_name
#else
    #define DEFINE_ERROR_VAR(type, var_name)
#endif

#define FEATURE_GMAC_NUM_COUNTER_REG                (uint32)(GMAC_CTR_NUMBER_OF_COUNTERS)
/*******************************************************************************
 * Variables
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"


/*! @brief Pointers to GMAC internal driver state for each Instance. */
Gmac_Ip_StateType *Gmac_apxState[FEATURE_GMAC_NUM_INSTANCES] = {NULL_PTR};


#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

#if (STD_ON == GMAC_IP_HAS_EXTERNAL_TX_BUFFERS)
#define ETH_43_GMAC_START_SEC_CONST_BOOLEAN
#include "Eth_43_GMAC_MemMap.h"

/** @brief Table storing information related to the method of Tx Data Buffers Management.*/
static const boolean Gmac_Ip_InstHasExternalTxBufferManagement[FEATURE_GMAC_NUM_INSTANCES] = GMAC_IP_INST_HAS_EXTERNAL_TX_BUFFERS;

#define ETH_43_GMAC_STOP_SEC_CONST_BOOLEAN
#include "Eth_43_GMAC_MemMap.h"
#endif

#if (GMAC_HAS_CACHE_MANAGEMENT == STD_ON)
/*  FEATURE_GMAC_CACHABLE_BUFFERS_LMEM and FEATURE_GMAC_CACHABLE_BUFFERS_CORE are generated based on the
platform and the core type in case both cache IPs are supported.
    These macros must be both defined for the driver when the cache management feature is enabled.
    They must not be simultaneosly enabled at runtime.*/
    #ifdef FEATURE_GMAC_CACHABLE_BUFFERS_LMEM
        #ifdef FEATURE_GMAC_CACHABLE_BUFFERS_CORE
#define ETH_43_GMAC_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"
            #if (FEATURE_GMAC_CACHABLE_BUFFERS_LMEM > 0U)
/** @brief Global variable which contains the type of CACHE Type used on the current platform.
 *          CACHE_IP_LMEM is using LMEM peripheral.
 *          CACHE_IP_CORE is using SCB peripheral.
*/
static const Cache_Ip_Type CacheType = CACHE_IP_LMEM;
            #elif (FEATURE_GMAC_CACHABLE_BUFFERS_CORE > 0U)
/** @brief Global variable which contains the type of CACHE Type used on the current platform.
 *          CACHE_IP_LMEM is using LMEM peripheral.
 *          CACHE_IP_CORE is using SCB peripheral.
*/
static const Cache_Ip_Type CacheType = CACHE_IP_CORE;
            #endif
#define ETH_43_GMAC_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"
        #endif /* defined (FEATURE_GMAC_CACHABLE_BUFFERS_CORE) */
    #endif /* defined (FEATURE_GMAC_CACHABLE_BUFFERS_LMEM) */
#endif /*GMAC_HAS_CACHE_MANAGEMENT == STD_ON */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

static uint32 Gmac_Ip_ComputeCRC32(const uint8 *Mac, uint8 Size);

static Gmac_Ip_StatusType Gmac_Ip_InitDMA(uint8 Instance,
                                          const Gmac_CtrlConfigType *Config);
static void Gmac_Ip_InitStateStructure(uint8 Instance,
                                       const Gmac_CtrlConfigType *Config);
static void Gmac_Ip_InitTxBD(uint8 Instance,
                            const Gmac_Ip_ConfigType *Config,
                            const Gmac_Ip_TxRingConfigType TxRingConfig[]
                            );
static void Gmac_Ip_InitRxBD(uint8 Instance,
                            const Gmac_Ip_ConfigType *Config,
                            const Gmac_Ip_RxRingConfigType RxRingConfig[]
                            );

#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
static void Gmac_Ip_InitSafetyEvents(GMAC_Type *Base,
                                     const Gmac_Ip_ConfigType *Config);
#endif

static uint8 Gmac_Ip_WriteGateControlList(
                                    uint8 Instance,
                                    uint16 AddrGateList,
                                    uint32 Data,
                                    boolean IsGCLA
                                        );

static void Gmac_Ip_InitMTL(uint8 Instance, const Gmac_CtrlConfigType *Config);

static void Gmac_Ip_InitMAC(GMAC_Type *Base,
                            const Gmac_CtrlConfigType *Config);

static void Gmac_Ip_GetTimestamp(const GMAC_Type *Base,
                                 const Gmac_Ip_BufferDescriptorType * Bd,
                                 Gmac_Ip_TimestampType * Timestamp);

static boolean Gmac_Ip_RestoreRxCtxtDescr(Gmac_Ip_BufferDescriptorType *Bd);

static void Gmac_Ip_RestoreTxDescr(uint8 Instance);

static void Gmac_Ip_RestoreRxDescr(uint8 Instance);

static Gmac_Ip_StatusType Gmac_Ip_CheckMTLEmpty(
                                            uint8 Instance,
                                            uint16 NumQueues,
                                            boolean IsTransmit
                                            );

static Gmac_Ip_PayloadType Gmac_Ip_GetPayloadType(uint32 PayloadTypeVal);

static void Gmac_Ip_ReadTimeStampInfo(uint8 Instance,
                                      uint8 Ring,
                                      Gmac_Ip_RxInfoType * Info
                                      );

/*******************************************************************************
 * Private functions
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ComputeCRC32
 * Description   : Computes the CRC32 of a given MAC address.
 *
 *END**************************************************************************/
static uint32 Gmac_Ip_ComputeCRC32(const uint8 *Mac, uint8 Size)
{
    uint32 Crc = 0xFFFFFFFFUL;
    uint32 i, j;

    for (i = 0; i < Size; i++)
    {
        Crc = Crc ^ Mac[i];
        for (j = 0; j < 8U; j++)
        {
            if ((Crc & 0x1U) != 0U)
            {
                Crc = (Crc >> 1U) ^ 0xEDB88320U;
            }
            else
            {
                Crc = (Crc >> 1U);
            }
        }
    }

    return ~Crc;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ReadTimeStampInfo
 * Description   : Read timestamp value
 *
 *END**************************************************************************/
static void Gmac_Ip_ReadTimeStampInfo(uint8 Instance,
                                      uint8 Ring,
                                      Gmac_Ip_RxInfoType * Info
                                      )
{
    const GMAC_Type *Base;
    const Gmac_Ip_BufferDescriptorType *Bd;
    uint16 CurrTimeSecHi;
    uint32 CurrTimeSec;
    uint32 BdSec;

    Base = Gmac_apxBases[Instance];
    Bd = Gmac_apxState[Instance]->RxCurrentDesc[Ring];

    if ((Bd->Des1 & GMAC_RDES1_TSA_MASK) != 0U)
    {
        Bd++;
        Gmac_apxState[Instance]->RxCurrentDesc[Ring]++;

        CurrTimeSec = (uint32)(Base->MAC_SYSTEM_TIME_SECONDS);
        CurrTimeSecHi = (uint16)(Base->MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS);
        BdSec = (uint32)(Bd->Des1);

        if (BdSec <= CurrTimeSec)
        {
            Info->Timestamp.secondsHi = CurrTimeSecHi;
        }
        else
        {
            Info->Timestamp.secondsHi = (uint16)(CurrTimeSecHi - 1U);
        }
        Info->Timestamp.seconds = BdSec;
        Info->Timestamp.nanoseconds = (uint32)(Bd->Des0);
    }
    else
    {
        Info->Timestamp.secondsHi = 0U;
        Info->Timestamp.seconds = 0U;
        Info->Timestamp.nanoseconds = 0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitDMA
 * Description   : Initializes the DMA subsystem
 *
 * Warning       : DMA_CHx_CONTROL_DSL will fail miserably on platforms with
 *                 128-bit Data bus width. If such a platform is encountered,
 *                 Gmac_Ip_BufferDescriptorType will have to use four Info
 *                 fields instead of just two.
 *
 *END**************************************************************************/
static Gmac_Ip_StatusType Gmac_Ip_InitDMA(uint8 Instance,
                                          const Gmac_CtrlConfigType *Config)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Base = Gmac_apxBases[Instance];

    /* Provide a software reset. */
    Base->DMA_MODE |= GMAC_DMA_MODE_SWR_MASK;

    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);

    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_DMA_BUSY);
    #endif

    do
    {
        if ((Base->DMA_MODE & GMAC_DMA_MODE_SWR_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    if (Status == GMAC_STATUS_SUCCESS)
    {
        /* Initialize the global DMA registers. */
    #if FEATURE_GMAC_DATA_BUS_AXI
        Base->DMA_MODE = GMAC_DMA_MODE_INTM(1) | GMAC_DMA_MODE_DSPW(1);

        /* Workaround for Errata ERR050614 */
        #if defined(ERR_IPV_GMAC_E050614)
            #if (STD_ON == ERR_IPV_GMAC_E050614)
                Base->DMA_MODE &= ~GMAC_DMA_MODE_DSPW(1);
            #endif
        #endif

    #else
        Base->DMA_MODE = GMAC_DMA_MODE_INTM(1);
    #endif

    #if FEATURE_GMAC_DATA_BUS_AXI
        /* Each Tx DMA channel can have 2 outstanding read requests per channel */
        /* All Rx DMA channels can have 1 oustanding write request to avoid loss of bandwidth in early burst termination scenarios */
        Base->DMA_SYSBUS_MODE = GMAC_DMA_SYSBUS_MODE_RD_OSR_LMT(((uint32)Config->Gmac_pCtrlConfig->TxRingCount * 2U) - 1U) |
                                GMAC_DMA_SYSBUS_MODE_WR_OSR_LMT(0U) |
                                GMAC_DMA_SYSBUS_MODE_AAL(1U) |
                                GMAC_DMA_SYSBUS_MODE_BLEN32(1U);
    #else
        Base->DMA_SYSBUS_MODE = GMAC_DMA_SYSBUS_MODE_AAL(1U);
    #endif

        Gmac_Ip_InitTxBD(Instance, Config->Gmac_pCtrlConfig, Config->Gmac_paCtrlTxRingConfig);
        Gmac_Ip_InitRxBD(Instance, Config->Gmac_pCtrlConfig, Config->Gmac_paCtrlRxRingConfig);
    }

    return Status;
}

#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitSafetyEvents
 * Description   : Initializes the safety events
 *
 *END**************************************************************************/
static void Gmac_Ip_InitSafetyEvents(GMAC_Type *Base,
                                     const Gmac_Ip_ConfigType *Config)
{
    /* Mask correctable error IRQs */
    Base->MTL_ECC_INTERRUPT_ENABLE = 0U;

    /* Configure ECC Protection */
    if ((Config->SafetyInterrupts & (uint32)GMAC_SAF_ERR_ECC) != 0U)
    {
        Base->MTL_ECC_CONTROL |= GMAC_MTL_ECC_CONTROL_MESTEE_MASK | GMAC_MTL_ECC_CONTROL_MRXEE_MASK | GMAC_MTL_ECC_CONTROL_MTXEE_MASK;
    }
    else
    {
        Base->MTL_ECC_CONTROL &= ~(GMAC_MTL_ECC_CONTROL_MESTEE_MASK | GMAC_MTL_ECC_CONTROL_MRXEE_MASK | GMAC_MTL_ECC_CONTROL_MTXEE_MASK);
    }

#if FEATURE_GMAC_ASP_ALL
    /* Configure Datapath Parity Protection */
    if ((Config->SafetyInterrupts & (uint32)GMAC_SAF_ERR_DATA_PATH_PARITY) != 0U)
    {
        Base->MTL_DPP_CONTROL |= GMAC_MTL_DPP_CONTROL_OPE_MASK | GMAC_MTL_DPP_CONTROL_EDPP_MASK;
    }
    else
    {
        Base->MTL_DPP_CONTROL &= ~(GMAC_MTL_DPP_CONTROL_OPE_MASK | GMAC_MTL_DPP_CONTROL_EDPP_MASK);
    }

    /* Configure FSM State Parity Protection */
    if ((Config->SafetyInterrupts & (uint32)GMAC_SAF_ERR_FSM_STATE_PARITY) != 0U)
    {
        Base->MAC_FSM_CONTROL |= GMAC_MAC_FSM_CONTROL_PRTYEN_MASK;
    }
    else
    {
        Base->MAC_FSM_CONTROL &= ~GMAC_MAC_FSM_CONTROL_PRTYEN_MASK;
    }

    /* Configure FSM Timeout Protection */
    if ((Config->SafetyInterrupts & (uint32)GMAC_SAF_ERR_FSM_TIMEOUT) != 0U)
    {
        Base->MAC_FSM_ACT_TIMER &= ~GMAC_MAC_FSM_ACT_TIMER_LTMRMD_MASK;
        /* TBD: Get the actual module clock frequency for the TMR field */
        Base->MAC_FSM_ACT_TIMER |= GMAC_MAC_FSM_ACT_TIMER_NTMRMD(2U) | GMAC_MAC_FSM_ACT_TIMER_TMR(80U);
        Base->MAC_FSM_CONTROL   |= GMAC_MAC_FSM_CONTROL_TMOUTEN_MASK;
    }
    else
    {
        Base->MAC_FSM_CONTROL &= ~GMAC_MAC_FSM_CONTROL_TMOUTEN_MASK;
    }
#endif
}
#endif /* #if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC) */
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_WriteGateControlList
 * Description   : Initializes value to Gate Control List.
 *
 *END**************************************************************************/
static uint8 Gmac_Ip_WriteGateControlList(
                                    uint8 Instance,
                                    uint16 AddrGateList,
                                    uint32 Data,
                                    boolean IsGCLA
                                        )
{
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint8 u8ErrorNum = 0U;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Gmac_apxBases[Instance]->MTL_EST_GCL_DATA = GMAC_MTL_EST_GCL_DATA_GCD(Data);

    Gmac_apxBases[Instance]->MTL_EST_GCL_CONTROL = GMAC_MTL_EST_GCL_CONTROL_ADDR(AddrGateList);

    if ((boolean)FALSE == IsGCLA)
    {
        Gmac_apxBases[Instance]->MTL_EST_GCL_CONTROL |= GMAC_MTL_EST_GCL_CONTROL_GCRR_MASK;
    }
    else
    {
        Gmac_apxBases[Instance]->MTL_EST_GCL_CONTROL &= ~GMAC_MTL_EST_GCL_CONTROL_GCRR_MASK;
    }

    Gmac_apxBases[Instance]->MTL_EST_GCL_CONTROL |= GMAC_MTL_EST_GCL_CONTROL_R1W0(0U);

    Gmac_apxBases[Instance]->MTL_EST_GCL_CONTROL |= GMAC_MTL_EST_GCL_CONTROL_SRWO_MASK;

    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);

    /* Add fault label for testing */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_WRITE_GATE_CONTROLIST_TIMEOUT);
    #endif

    do
    {
        if ((Gmac_apxBases[Instance]->MTL_EST_GCL_CONTROL & GMAC_MTL_EST_GCL_CONTROL_SRWO_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    u8ErrorNum = ((GMAC_STATUS_TIMEOUT == Status) ? ((uint8)1U) : ((uint8)0U));

    return u8ErrorNum;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitMTL
 * Description   : Initializes the MTL subsystem
 *
 *END**************************************************************************/
static void Gmac_Ip_InitMTL(uint8 Instance,
                            const Gmac_CtrlConfigType *Config)
{
    uint32 FifoSize;
    uint8 i;

    /* Set the global Tx Scheduling Algorithm affecting all Tx Queues */
    Gmac_apxBases[Instance]->MTL_OPERATION_MODE = GMAC_MTL_OPERATION_MODE_SCHALG((uint32)(Config->Gmac_pCtrlConfig->TxSchedAlgo));

    /* Configure MTL Tx Queues */
    for (i = 0U; i < Config->Gmac_pCtrlConfig->TxRingCount; ++i)
    {
        FifoSize = (uint32)Config->Gmac_paCtrlTxRingConfig[i].RingSize * Config->Gmac_paCtrlTxRingConfig[i].BufferLen;

        if ((GMAC_OP_MODE_DCB_GEN == Config->Gmac_paCtrlTxRingConfig[i].QueueOpMode) && (Config->Gmac_pCtrlConfig->TxRingCount > 0U))
        {
            GMAC_SetTxQueueQuantumWeight(Gmac_apxQueueBases[Instance][i], Config->Gmac_paCtrlTxRingConfig[i].Weight);
        }
        else if ((GMAC_OP_MODE_AVB == Config->Gmac_paCtrlTxRingConfig[i].QueueOpMode) && (i > 0U))
        {
            GMAC_SetTxQueueQuantumWeight(Gmac_apxQueueBases[Instance][i], Config->Gmac_paCtrlTxRingConfig[i].IdleSlopeCredit);
            GMAC_SetTxQueueCreditBasedShaper(Gmac_apxQueueBases[Instance][i],
                                             Config->Gmac_paCtrlTxRingConfig[i].SendSlopeCredit,
                                             Config->Gmac_paCtrlTxRingConfig[i].HiCredit,
                                             Config->Gmac_paCtrlTxRingConfig[i].LoCredit);
        }
        else
        {
            /* do nothing */
        }

        /* Enable the Tx Queue in the given mode and set its size  */
        GMAC_SetTxQueueOperationMode(Gmac_apxQueueBases[Instance][i], Config->Gmac_paCtrlTxRingConfig[i].QueueOpMode, FifoSize);
    }


    /* Set default scheduling algorithm for Rx as Strict priority. */
    Gmac_apxBases[Instance]->MTL_OPERATION_MODE &= ~GMAC_MTL_OPERATION_MODE_RAA_MASK;

    /* Set 1:1 mapping between Rx Queues and Rx DMA Channels */
    GMAC_SetRxQueuesDmaChMap(Gmac_apxBases[Instance], Config->Gmac_pCtrlConfig->RxRingCount);

    /* Configure MTL Rx Queues */
    for (i = 0U; i < Config->Gmac_pCtrlConfig->RxRingCount; ++i)
    {
        FifoSize = (uint32)Config->Gmac_paCtrlRxRingConfig[i].RingSize * Config->Gmac_paCtrlRxRingConfig[i].BufferLen;

        /* Set the size of the Rx Queue */
        GMAC_SetRxQueueOperationMode(Gmac_apxQueueBases[Instance][i], FifoSize);

        /* Enable the Rx Queue for generic traffic with the given VLAN priorities */
        GMAC_EnableRxQueue(Gmac_apxBases[Instance], Config->Gmac_paCtrlRxRingConfig[i].PriorityMask, i);
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitMAC
 * Description   : Initializes the MAC subsystem
 *
 *END**************************************************************************/
static void Gmac_Ip_InitMAC(GMAC_Type *Base,
                            const Gmac_CtrlConfigType *Config)
{
    Base->MAC_Q0_TX_FLOW_CTRL = 0U;

    Base->MAC_INTERRUPT_ENABLE = Config->Gmac_pCtrlConfig->Interrupts;

    Base->MAC_CONFIGURATION = Config->Gmac_pCtrlConfig->MacConfig;
    Base->MAC_CONFIGURATION |= (uint32)(((uint32)Config->Gmac_pCtrlConfig->Speed) << GMAC_MAC_CONFIGURATION_FES_SHIFT);
    Base->MAC_CONFIGURATION |= GMAC_MAC_CONFIGURATION_DM(Config->Gmac_pCtrlConfig->Duplex);
    if (Config->Gmac_pCtrlConfig->EnableCtrl)
    {
        Base->MAC_CONFIGURATION |= GMAC_MAC_CONFIGURATION_TE_MASK | GMAC_MAC_CONFIGURATION_RE_MASK;
    }

    /* Set MAC packet filter. */
    Base->MAC_PACKET_FILTER = Config->Gmac_pCtrlConfig->MacPktFilterConfig;

    /* Disable common interrupt from MMC */
    Base->MMC_TX_INTERRUPT_MASK = 0x03FFFFFFU;
    Base->MMC_RX_INTERRUPT_MASK = 0x03FFFFFFU;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitStateStructure
 * Description   : Initializes State Structure
 *
 *END**************************************************************************/
static void Gmac_Ip_InitStateStructure(uint8 Instance,
                                       const Gmac_CtrlConfigType *Config)
{
    uint8 i;

    /* Initialize state structure. */
#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
    Config->Gmac_pCtrlState->SafetyCallback = Config->Gmac_pCtrlConfig->SafetyCallback;
#endif
    Config->Gmac_pCtrlState->Callback    = Config->Gmac_pCtrlConfig->Callback;
    Config->Gmac_pCtrlState->RxRingCount = Config->Gmac_pCtrlConfig->RxRingCount;
    Config->Gmac_pCtrlState->TxRingCount = Config->Gmac_pCtrlConfig->TxRingCount;
    for (i = 0; i < Config->Gmac_pCtrlConfig->RxRingCount; i++)
    {
        Config->Gmac_pCtrlState->RxChCallback[i]  = Config->Gmac_paCtrlRxRingConfig[i].Callback;
        Config->Gmac_pCtrlState->RxCurrentDesc[i] = Config->Gmac_paCtrlRxRingConfig[i].RingDesc;
        Config->Gmac_pCtrlState->RxAllocDesc[i]   = Config->Gmac_paCtrlRxRingConfig[i].RingDesc;
    }
    for (i = 0; i < Config->Gmac_pCtrlConfig->TxRingCount; i++)
    {
        Config->Gmac_pCtrlState->TxChCallback[i]  = Config->Gmac_paCtrlTxRingConfig[i].Callback;
        Config->Gmac_pCtrlState->TxCurrentDesc[i] = Config->Gmac_paCtrlTxRingConfig[i].RingDesc;
    }

    Gmac_apxState[Instance] = Config->Gmac_pCtrlState;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitTxBD
 * Description   : Initializes Tx Buffer Descriptor
 *
 *END**************************************************************************/
static void Gmac_Ip_InitTxBD(uint8 Instance,
                            const Gmac_Ip_ConfigType *Config,
                            const Gmac_Ip_TxRingConfigType TxRingConfig[]
                            )
{
    uint8 i;
    uint16 j;

    /* Configure Transmit Ring */
    for (i = 0U; i < Config->TxRingCount; i++)
    {
        for (j = 0U; j < TxRingConfig[i].RingSize; j++)
        {
            TxRingConfig[i].RingDesc[j].Des0  = (TxRingConfig[i].Buffer != NULL_PTR)? (uint32)(&TxRingConfig[i].Buffer[TxRingConfig[i].BufferLen * j]) : 0U;
            TxRingConfig[i].RingDesc[j].Des1  = 0U;
            TxRingConfig[i].RingDesc[j].Des2  = 0U;
            TxRingConfig[i].RingDesc[j].Des3  = 0U;
            TxRingConfig[i].RingDesc[j].Info0 = 0U;
            TxRingConfig[i].RingDesc[j].Info1 = (uint32)((uint32)TxRingConfig[i].BufferLen & GMAC_INFO1_LENGTH_MASK);
        }

        /* Initialize transmit descriptor list address and tail pointer */
        Gmac_apxChBases[Instance][i]->DMA_TXDESC_TAIL_POINTER = (uint32)TxRingConfig[i].RingDesc;
        Gmac_apxChBases[Instance][i]->DMA_TXDESC_LIST_ADDRESS = (uint32)TxRingConfig[i].RingDesc;

        /* Program the Transmit Ring length register */
        Gmac_apxChBases[Instance][i]->DMA_TXDESC_RING_LENGTH = ((uint32)TxRingConfig[i].RingSize) - 1UL;

        /* Program the settings of the following registers for the parameters like maximum burst-length (PBL)
            initiated by DMA, descriptor skip lengths, OSP, and so on */
        if (32U < TxRingConfig[i].DmaBurstLength)
        {
            Gmac_apxChBases[Instance][i]->DMA_CONTROL = GMAC_DMA_CH0_CONTROL_DSL((FEATURE_GMAC_SW_BUFFDESCR_SIZE_BYTES - FEATURE_GMAC_HW_BUFFDESCR_SIZE_BYTES) / FEATURE_GMAC_DATA_BUS_WIDTH_BYTES) | GMAC_DMA_CH0_CONTROL_PBLx8(1);
            Gmac_apxChBases[Instance][i]->DMA_TX_CONTROL = GMAC_DMA_CH0_TX_CONTROL_TxPBL((uint32)TxRingConfig[i].DmaBurstLength / 8U) | GMAC_DMA_CH0_TX_CONTROL_OSF(1);
        }
        else
        {
            Gmac_apxChBases[Instance][i]->DMA_CONTROL = GMAC_DMA_CH0_CONTROL_DSL((FEATURE_GMAC_SW_BUFFDESCR_SIZE_BYTES - FEATURE_GMAC_HW_BUFFDESCR_SIZE_BYTES) / FEATURE_GMAC_DATA_BUS_WIDTH_BYTES);
            Gmac_apxChBases[Instance][i]->DMA_TX_CONTROL = GMAC_DMA_CH0_TX_CONTROL_TxPBL(TxRingConfig[i].DmaBurstLength) | GMAC_DMA_CH0_TX_CONTROL_OSF(1);
        }

        /* Enable the interrupts */
        Gmac_apxChBases[Instance][i]->DMA_INTERRUPT_ENABLE = TxRingConfig[i].Interrupts |
                (((TxRingConfig[i].Interrupts & GMAC_CH_NORMAL_INTERRUPTS) != 0U) ? (uint32)GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK : 0U) |
                (((TxRingConfig[i].Interrupts & GMAC_CH_ABNORMAL_INTERRUPTS) != 0U) ? (uint32)GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK : 0U);

        if (Config->EnableCtrl)
        {
            /* Start the Transmit DMA */
            Gmac_apxChBases[Instance][i]->DMA_TX_CONTROL |= GMAC_DMA_CH0_TX_CONTROL_ST_MASK;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitRxBD
 * Description   : Initializes Rx Buffer Descriptor
 *
 *END**************************************************************************/
static void Gmac_Ip_InitRxBD(uint8 Instance,
                            const Gmac_Ip_ConfigType *Config,
                            const Gmac_Ip_RxRingConfigType RxRingConfig[]
                            )
{
    uint8 i;
    uint16 j;

    /* Configure Receive Ring */
    for (i = 0U; i < Config->RxRingCount; i++)
    {
        for (j = 0U; j < RxRingConfig[i].RingSize; j++)
        {
            if (RxRingConfig[i].Buffer != NULL_PTR)
            {
                RxRingConfig[i].RingDesc[j].Des0  = (uint32)(&RxRingConfig[i].Buffer[RxRingConfig[i].BufferLen * j]);
                RxRingConfig[i].RingDesc[j].Des1  = 0U;
                RxRingConfig[i].RingDesc[j].Des2  = 0U;
                RxRingConfig[i].RingDesc[j].Info0 = RxRingConfig[i].RingDesc[j].Des0;
                RxRingConfig[i].RingDesc[j].Info1 = (uint32)((uint32)RxRingConfig[i].BufferLen & GMAC_INFO1_LENGTH_MASK);
                RxRingConfig[i].RingDesc[j].Des3  = GMAC_RDES3_OWN_MASK | GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK;
            }
            else
            {
                RxRingConfig[i].RingDesc[j].Des0  = 0U;
                RxRingConfig[i].RingDesc[j].Des1  = 0U;
                RxRingConfig[i].RingDesc[j].Des2  = 0U;
                RxRingConfig[i].RingDesc[j].Info0 = 0U;
                RxRingConfig[i].RingDesc[j].Info1 = (uint32)((uint32)RxRingConfig[i].BufferLen & GMAC_INFO1_LENGTH_MASK);
                RxRingConfig[i].RingDesc[j].Des3  = GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK;
            }
        }

        /* Initialize transmit descriptor list address and tail pointer */
        Gmac_apxChBases[Instance][i]->DMA_RXDESC_TAIL_POINTER = (uint32)(&RxRingConfig[i].RingDesc[RxRingConfig[i].RingSize]);
        Gmac_apxChBases[Instance][i]->DMA_RXDESC_LIST_ADDRESS = (uint32)RxRingConfig[i].RingDesc;

        /* Program the Transmit Ring length register */
        Gmac_apxChBases[Instance][i]->DMA_RXDESC_RING_LENGTH = ((uint32)RxRingConfig[i].RingSize) - 1UL;

        /* Program the settings of the following registers for the parameters like maximum burst-length (PBL)
            initiated by DMA, descriptor skip lengths, RBSZ, and so on */
        if (32U < RxRingConfig[i].DmaBurstLength)
        {
            Gmac_apxChBases[Instance][i]->DMA_CONTROL = GMAC_DMA_CH0_CONTROL_DSL((FEATURE_GMAC_SW_BUFFDESCR_SIZE_BYTES - FEATURE_GMAC_HW_BUFFDESCR_SIZE_BYTES) / FEATURE_GMAC_DATA_BUS_WIDTH_BYTES) | GMAC_DMA_CH0_CONTROL_PBLx8(1);
            Gmac_apxChBases[Instance][i]->DMA_RX_CONTROL = GMAC_DMA_CH0_RX_CONTROL_RxPBL((uint32)RxRingConfig[i].DmaBurstLength / 8U) | GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y(((uint32)RxRingConfig[i].BufferLen) >> FEATURE_GMAC_LOG2_DATA_BUS_WIDTH_BYTES);
        }
        else
        {
            Gmac_apxChBases[Instance][i]->DMA_CONTROL = GMAC_DMA_CH0_CONTROL_DSL((FEATURE_GMAC_SW_BUFFDESCR_SIZE_BYTES - FEATURE_GMAC_HW_BUFFDESCR_SIZE_BYTES) / FEATURE_GMAC_DATA_BUS_WIDTH_BYTES);
            Gmac_apxChBases[Instance][i]->DMA_RX_CONTROL = GMAC_DMA_CH0_RX_CONTROL_RxPBL(RxRingConfig[i].DmaBurstLength) | GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y(((uint32)RxRingConfig[i].BufferLen) >> FEATURE_GMAC_LOG2_DATA_BUS_WIDTH_BYTES);
        }

        /* Enable the interrupts */
        Gmac_apxChBases[Instance][i]->DMA_INTERRUPT_ENABLE |= RxRingConfig[i].Interrupts |
                (((RxRingConfig[i].Interrupts & GMAC_CH_NORMAL_INTERRUPTS) != 0U) ? (uint32)GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK : 0U) |
                (((RxRingConfig[i].Interrupts & GMAC_CH_ABNORMAL_INTERRUPTS) != 0U) ? (uint32)GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK : 0U);

        if (Config->EnableCtrl)
        {
            /* Start the Receive DMA */
            Gmac_apxChBases[Instance][i]->DMA_RX_CONTROL |= GMAC_DMA_CH0_RX_CONTROL_SR_MASK;
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetTimestamp
 * Description   : Gets the Timestamp from a buffer descriptor
 *
 *END**************************************************************************/
static void Gmac_Ip_GetTimestamp(const GMAC_Type *Base,
                                 const Gmac_Ip_BufferDescriptorType * Bd,
                                 Gmac_Ip_TimestampType * Timestamp)
{
    uint16 CurrTimeSecHi;
    uint32 CurrTimeSec;
    uint32 BdSec;

    if ((Bd->Des3 & GMAC_TX_STAT_TTSS_MASK) != 0U)
    {
        CurrTimeSec = (uint32)(Base->MAC_SYSTEM_TIME_SECONDS);
        CurrTimeSecHi = (uint16)(Base->MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS);
        BdSec = (uint32)(Bd->Des1);

        if (BdSec <= CurrTimeSec)
        {
            Timestamp->secondsHi = CurrTimeSecHi;
        }
        else
        {
            Timestamp->secondsHi = (uint16)(CurrTimeSecHi - 1U);
        }
        Timestamp->seconds = BdSec;
        Timestamp->nanoseconds = (uint32)(Bd->Des0);
    }
    else
    {
        Timestamp->secondsHi = 0U;
        Timestamp->seconds = 0U;
        Timestamp->nanoseconds = 0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_RestoreRxCtxtDescr
 * Description   : Restores an Rx descriptor to be used for reception.
 *
 *END**************************************************************************/
static boolean Gmac_Ip_RestoreRxCtxtDescr(Gmac_Ip_BufferDescriptorType *Bd)
{
    boolean restored = FALSE;

    GMAC_DEV_ASSERT((Bd->Des3 & GMAC_RDES3_OWN_MASK)  == 0U);
    GMAC_DEV_ASSERT((Bd->Des3 & GMAC_RDES3_CTXT_MASK) != 0U);

    if (Bd->Info0 != 0U)
    {
        Bd->Des0  = Bd->Info0;
        Bd->Des1  = 0U;
        Bd->Des2  = 0U;
        Bd->Info1 &= ~GMAC_INFO1_CONSUMED_MASK;
        Bd->Des3  = GMAC_RDES3_OWN_MASK | GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK;

        restored = TRUE;
    }

    return restored;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_RestoreTxDescr
 * Description   : Restores a Tx descriptor to be used for transmit.
 *
 *END**************************************************************************/
static void Gmac_Ip_RestoreTxDescr(uint8 Instance)
{
    Gmac_Ip_BufferDescriptorType *ListBd;
    uint32 i;
    uint32 j;

    for (i = 0U; i < Gmac_apxState[Instance]->TxRingCount; i++)
    {
        ListBd = (Gmac_Ip_BufferDescriptorType *)Gmac_apxChBases[Instance][i]->DMA_TXDESC_LIST_ADDRESS;
        for (j = 0U; j <= Gmac_apxChBases[Instance][i]->DMA_TXDESC_RING_LENGTH; ++j)
        {
            if (0U != ListBd[j].Info0)
            {
                ListBd[j].Des0  = ListBd[j].Info0;
                ListBd[j].Info0 = 0U;
            }

            ListBd[j].Des3  &= ~GMAC_TDES3_OWN_MASK;
            ListBd[j].Info1 &= ~GMAC_INFO1_LOCKED_MASK;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_RestoreRxDescr
 * Description   : Restores an Rx descriptor to be used for reception.
 *
 *END**************************************************************************/
static void Gmac_Ip_RestoreRxDescr(uint8 Instance)
{
    Gmac_Ip_BufferDescriptorType *ListBd;
    uint32 i;
    uint32 j;

    for (i = 0U; i < Gmac_apxState[Instance]->RxRingCount; i++)
    {
        ListBd = (Gmac_Ip_BufferDescriptorType *)Gmac_apxChBases[Instance][i]->DMA_RXDESC_LIST_ADDRESS;
        for (j = 0U; j <= Gmac_apxChBases[Instance][i]->DMA_RXDESC_RING_LENGTH; ++j)
        {
            ListBd[j].Des0   = ListBd[j].Info0;
            ListBd[j].Info1 &= ~GMAC_INFO1_CONSUMED_MASK;
            ListBd[j].Des3   = (ListBd[j].Info0 != 0U)?
                               (GMAC_RDES3_OWN_MASK | GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK):
                               (                      GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_CheckMTLEmpty
 * Description   : Check MTL Tx/Rx empty or not.
 *
 *END**************************************************************************/
static Gmac_Ip_StatusType Gmac_Ip_CheckMTLEmpty(
                                                uint8 Instance,
                                                uint16 NumQueues,
                                                boolean IsTransmit
                                                )
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred;
    boolean QueueEmpty;
    uint16 i;

    TimeoutOccurred = FALSE;

    for (i = 0U; (i < NumQueues) && !TimeoutOccurred; i++)
    {
        GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);
        do
        {
            /* Check MTL queue is empty */
            if (IsTransmit)
            {
                QueueEmpty      = ((Gmac_apxQueueBases[Instance][i]->MTL_TXQ_DEBUG & GMAC_MTL_TXQ0_DEBUG_TXQSTS_MASK) == 0U);
            }
            else
            {
                QueueEmpty      = ((Gmac_apxQueueBases[Instance][i]->MTL_RXQ_DEBUG & GMAC_MTL_RXQ0_DEBUG_RXQSTS_MASK) == 0U);
            }
            TimeoutOccurred = GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while (!QueueEmpty && !TimeoutOccurred);
    }

    return ((TimeoutOccurred == TRUE)? (GMAC_STATUS_TIMEOUT) : (GMAC_STATUS_SUCCESS));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetPayloadType
 * Description   : Get payload type of Rx frame.
 *
 *END**************************************************************************/
static Gmac_Ip_PayloadType Gmac_Ip_GetPayloadType(uint32 PayloadTypeVal)
{
    Gmac_Ip_PayloadType PayloadType;

    if (1U == PayloadTypeVal)
    {
        PayloadType = GMAC_IP_PAYLOAD_TYPE_UDP;
    }
    else if (2U == PayloadTypeVal)
    {
        PayloadType = GMAC_IP_PAYLOAD_TYPE_TCP;
    }
    else if (3U == PayloadTypeVal)
    {
        PayloadType = GMAC_IP_PAYLOAD_TYPE_ICMP;
    }
    else
    {
        PayloadType = GMAC_IP_PAYLOAD_TYPE_UNKNOWN;
    }

    return PayloadType;
}
#if (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the Instance accessible in user mode.
 *
 *END**************************************************************************/
void Gmac_Ip_SetUserAccessAllowed(const GMAC_Type *Base)
{
    SET_USER_ACCESS_ALLOWED((uint32)Base, GMAC_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the Instance accessible in user mode.
 *
 *END**************************************************************************/
void Gmac_Ip_ClrUserAccessAllowed(const GMAC_Type *Base)
{
    CLR_USER_ACCESS_ALLOWED((uint32)Base, GMAC_PROT_MEM_U32);
}
#endif


/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_Init
 * Description   : Initializes the GMAC module
 * implements     Gmac_Ip_Init_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_Init(uint8 Instance,
                                const Gmac_CtrlConfigType *Config)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status;
#if (GMAC_IP_DEV_ERROR_DETECT == STD_ON)
    uint32 i;
#endif
    DEFINE_ERROR_VAR(uint32, PoolSize);

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Config                          != NULL_PTR);
    GMAC_DEV_ASSERT(Config->Gmac_pCtrlState         != NULL_PTR);
    GMAC_DEV_ASSERT(Config->Gmac_pCtrlConfig        != NULL_PTR);
    GMAC_DEV_ASSERT(Config->Gmac_paCtrlRxRingConfig != NULL_PTR);
    GMAC_DEV_ASSERT(Config->Gmac_paCtrlTxRingConfig != NULL_PTR);
    GMAC_DEV_ASSERT(Config->Gmac_pau8CtrlPhysAddr   != NULL_PTR);
    GMAC_DEV_ASSERT((Config->Gmac_pCtrlConfig->RxRingCount > 0U) && (Config->Gmac_pCtrlConfig->RxRingCount <= FEATURE_GMAC_NUM_CHANNELS));
    GMAC_DEV_ASSERT((Config->Gmac_pCtrlConfig->TxRingCount > 0U) && (Config->Gmac_pCtrlConfig->TxRingCount <= FEATURE_GMAC_NUM_CHANNELS));

#if (GMAC_IP_DEV_ERROR_DETECT == STD_ON)
    PoolSize = 0U;

    for (i = 0U; i < Config->Gmac_pCtrlConfig->RxRingCount; ++i)
    {
        GMAC_DEV_ASSERT(Config->Gmac_paCtrlRxRingConfig[i].RingDesc != NULL_PTR);
        GMAC_DEV_ASSERT(Config->Gmac_paCtrlRxRingConfig[i].RingSize > 1U);
        GMAC_DEV_ASSERT(GMAC_BUFFDESCR_IS_ALIGNED(Config->Gmac_paCtrlRxRingConfig[i].RingDesc));
        GMAC_DEV_ASSERT((Config->Gmac_paCtrlRxRingConfig[i].Buffer == NULL_PTR) || GMAC_BUFF_IS_ALIGNED(Config->Gmac_paCtrlRxRingConfig[i].Buffer));
        GMAC_DEV_ASSERT(GMAC_BUFFLEN_IS_ALIGNED(Config->Gmac_paCtrlRxRingConfig[i].BufferLen));
        GMAC_DEV_ASSERT(GMAC_RXRINGLEN_IS_BLOCK_ALIGNED((uint32)Config->Gmac_paCtrlRxRingConfig[i].RingSize * Config->Gmac_paCtrlRxRingConfig[i].BufferLen));

        PoolSize += ((uint32)Config->Gmac_paCtrlRxRingConfig[i].RingSize * Config->Gmac_paCtrlRxRingConfig[i].BufferLen);
    }

    GMAC_DEV_ASSERT(PoolSize <= FEATURE_GMAC_MTL_RX_POOL_SIZE);

    PoolSize = 0U;

    for (i = 0U; i < Config->Gmac_pCtrlConfig->TxRingCount; ++i)
    {
        GMAC_DEV_ASSERT(Config->Gmac_paCtrlTxRingConfig[i].RingDesc != NULL_PTR);
        GMAC_DEV_ASSERT(Config->Gmac_paCtrlTxRingConfig[i].RingSize > 1U);
        GMAC_DEV_ASSERT(GMAC_BUFFDESCR_IS_ALIGNED(Config->Gmac_paCtrlTxRingConfig[i].RingDesc));
        GMAC_DEV_ASSERT((Config->Gmac_paCtrlTxRingConfig[i].Buffer == NULL_PTR) || GMAC_BUFF_IS_ALIGNED(Config->Gmac_paCtrlTxRingConfig[i].Buffer));
        GMAC_DEV_ASSERT(GMAC_BUFFLEN_IS_ALIGNED(Config->Gmac_paCtrlTxRingConfig[i].BufferLen));
        GMAC_DEV_ASSERT(GMAC_TXRINGLEN_IS_BLOCK_ALIGNED((uint32)Config->Gmac_paCtrlTxRingConfig[i].RingSize * Config->Gmac_paCtrlTxRingConfig[i].BufferLen));

        PoolSize += ((uint32)Config->Gmac_paCtrlTxRingConfig[i].RingSize * Config->Gmac_paCtrlTxRingConfig[i].BufferLen);
    }

    GMAC_DEV_ASSERT(PoolSize <= FEATURE_GMAC_MTL_TX_POOL_SIZE);
#endif

    Base   = Gmac_apxBases[Instance];

    if (Instance < 1U)
    {
      #if (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        /* Set the UAA bit in REG_PROT to make the Instance accessible in user mode */
        OsIf_Trusted_Call1param(Gmac_Ip_SetUserAccessAllowed, Base);
      #endif
    }

    /* Initialize hardware module. */
    Status = Gmac_Ip_InitDMA(Instance, Config);

    if (Status == GMAC_STATUS_SUCCESS)
    {
#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
        Gmac_Ip_InitSafetyEvents(Base, Config->Gmac_pCtrlConfig);
#endif
        Gmac_Ip_InitMTL(Instance, Config);
        Gmac_Ip_SetMacAddr(Instance, Config->Gmac_pau8CtrlPhysAddr);
        Gmac_Ip_InitMAC(Base, Config);
        Gmac_Ip_InitStateStructure(Instance, Config);
    }

    return Status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_TxTimeAwareShaperInit
 * Description   : Install duration time for transmit frame
 *
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_TxTimeAwareShaperInit(uint8 Instance,
                                const Gmac_CtrlConfigType *Config
                                )
{
    uint8 ErrorCnt = 0U;
    uint16 GateListNum;
    uint32 WriteData;
    Gmac_Ip_StatusType Status;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Config != NULL_PTR);
    GMAC_DEV_ASSERT(Config->Gmac_pCtrlTxTimeAwareShaper != NULL_PTR);

    /*Check Preemption supported or not*/
    if ((uint16)0U != Config->Gmac_pCtrlTxTimeAwareShaper->ReleaseAdvanceTime)
    {
        Gmac_apxBases[Instance]->MAC_FPE_CTRL_STS = GMAC_MAC_FPE_CTRL_STS_EFPE_MASK;

        Gmac_apxBases[Instance]->MTL_FPE_CTRL_STS = GMAC_MTL_FPE_CTRL_STS_PEC(Config->Gmac_pCtrlTxTimeAwareShaper->PreemptionClassic);

        Gmac_apxBases[Instance]->MTL_FPE_ADVANCE = GMAC_MTL_FPE_ADVANCE_HADV(Config->Gmac_pCtrlTxTimeAwareShaper->HoldAdvanceTime) | GMAC_MTL_FPE_ADVANCE_RADV(Config->Gmac_pCtrlTxTimeAwareShaper->ReleaseAdvanceTime);
    }

    for (GateListNum = 0U; GateListNum < Config->Gmac_pCtrlTxTimeAwareShaper->GateControlDepth; GateListNum++)
    {
        WriteData = ((uint32)Config->Gmac_pCtrlTxTimeAwareShaper->GateControlList[GateListNum].GateControl << 24U) | Config->Gmac_pCtrlTxTimeAwareShaper->GateControlList[GateListNum].TimeInterval;
        /* Write value to Gate Control List*/
        ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GateListNum, WriteData, (boolean)TRUE);
    }

    /* Write value to BTR (upper Base Time register)*/
    ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GMAC_GCRA_UPPER_BTR, Config->Gmac_pCtrlTxTimeAwareShaper->BaseTimeSecond, (boolean)FALSE);

    /* Write value to BTR (lower Base Time register)*/
    ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GMAC_GCRA_LOWER_BTR, Config->Gmac_pCtrlTxTimeAwareShaper->BaseTimeNanoSecond, (boolean)FALSE);

    /* Write value to CTR (upper Cycle Time register)*/
    ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GMAC_GCRA_UPPER_CTR, Config->Gmac_pCtrlTxTimeAwareShaper->CycleTimeSecond, (boolean)FALSE);

    /* Write value to CTR (lower Cycle Time register)*/
    ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GMAC_GCRA_LOWER_CTR, Config->Gmac_pCtrlTxTimeAwareShaper->CycleTimeNanoSecond, (boolean)FALSE);

    /* Write value to TER (Time extension register)*/
    ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GMAC_GCRA_TER, Config->Gmac_pCtrlTxTimeAwareShaper->ExtendedTime, (boolean)FALSE);

    /* Write value to LLR (List Length register)*/
    ErrorCnt += Gmac_Ip_WriteGateControlList(Instance, GMAC_GCRA_LLR, (uint32)Config->Gmac_pCtrlTxTimeAwareShaper->GateControlDepth, (boolean)FALSE);

    Gmac_apxBases[Instance]->MTL_EST_CONTROL = GMAC_MTL_EST_CONTROL_SSWL_MASK | GMAC_MTL_EST_CONTROL_EEST_MASK;

    /* Workaround for Errata ERR050705*/
#if defined(ERR_IPV_GMAC_E050705)
    #if (STD_ON == ERR_IPV_GMAC_E050705)
        Gmac_apxBases[Instance]->MTL_EST_CONTROL |= GMAC_MTL_EST_CONTROL_DDBF(1U);
    #endif
#endif

    Status = ((ErrorCnt > 0U) ? ((Gmac_Ip_StatusType)GMAC_STATUS_TIMEOUT) : ((Gmac_Ip_StatusType)GMAC_STATUS_SUCCESS));

    return Status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_Deinit
 * Description   : Deinitializes the GMAC module
 * implements     Gmac_Ip_Deinit_Activity
 *END**************************************************************************/
void Gmac_Ip_Deinit(uint8 Instance)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    /* Reset controller */
    Base->DMA_MODE |= GMAC_DMA_MODE_SWR_MASK;

    if (Instance < 1U)
    {
      #if (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        /* Clear the UAA bit in REG_PROT to reset the elevation requirement */
        OsIf_Trusted_Call1param(Gmac_Ip_ClrUserAccessAllowed, Base);
      #endif
    }

    /* Reset state variables */
    Gmac_apxState[Instance] = NULL_PTR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetPowerState
 * Description   : Gets the current power state of the GMAC module
 *END**************************************************************************/
Gmac_Ip_PowerStateType Gmac_Ip_GetPowerState(uint8 Instance)
{
    const GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];
    return GMAC_GetPowerState(Base);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetPowerState
 * Description   : Sets the power state of the GMAC module
 *END**************************************************************************/
void Gmac_Ip_SetPowerState(uint8 Instance, Gmac_Ip_PowerStateType PowerState)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];
    GMAC_SetPowerState(Base, PowerState);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_EnableController
 * Description   : Enables all Configured transmit and receive buffers and then enables the controller
 *END**************************************************************************/
void Gmac_Ip_EnableController(uint8 Instance)
{
    uint32 i;

    /* Start all configured TxDMA channels */
    for (i = 0U; i < Gmac_apxState[Instance]->TxRingCount; i++)
    {
        Gmac_apxChBases[Instance][i]->DMA_TX_CONTROL |= GMAC_DMA_CH0_TX_CONTROL_ST_MASK;
    }

    /* Start all configured RxDMA channels */
    for (i = 0U; i < Gmac_apxState[Instance]->RxRingCount; i++)
    {
        Gmac_apxChBases[Instance][i]->DMA_RX_CONTROL |= GMAC_DMA_CH0_RX_CONTROL_SR_MASK;
    }

    /* Enable the MAC transmitter and receiver */
    Gmac_apxBases[Instance]->MAC_CONFIGURATION |= (GMAC_MAC_CONFIGURATION_TE_MASK | GMAC_MAC_CONFIGURATION_RE_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_DisableController
 * Description   : Disables the controller and resets all the configured transmit and receive buffers
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_DisableController(uint8 Instance)
{
    Gmac_Ip_StatusType Status;
    uint32 i;

    /* Stop all configured TxDMA channels and flush the corresponding MTL queues */
    for (i = 0U; i < Gmac_apxState[Instance]->TxRingCount; i++)
    {
        /* Stop the TxDMA channel (This will set flag DMA_CHi_Status[TPS]) */
        Gmac_apxChBases[Instance][i]->DMA_TX_CONTROL &= ~GMAC_DMA_CH0_TX_CONTROL_ST_MASK;

        /* Flush the corresponding MTL Tx Queue (Channels and queues are mapped 1:1) */
        Gmac_apxQueueBases[Instance][i]->MTL_TXQ_OPERATION_MODE |= GMAC_MTL_TXQ0_OPERATION_MODE_FTQ_MASK;
    }

    /* Make sure all configured MTL queues are now empty */
    Status = Gmac_Ip_CheckMTLEmpty(Instance, Gmac_apxState[Instance]->TxRingCount, (boolean)TRUE);

    if (GMAC_STATUS_SUCCESS == Status)
    {
        /* Disable the MAC transmitter and receiver */
        Gmac_apxBases[Instance]->MAC_CONFIGURATION &= ~(GMAC_MAC_CONFIGURATION_TE_MASK | GMAC_MAC_CONFIGURATION_RE_MASK);

        /* Stop all configured RxDMA channels and flush the corresponding MTL queues */
        for (i = 0U; i < Gmac_apxState[Instance]->RxRingCount; i++)
        {
            /* Stop the RxDMA channel (This will set flag DMA_CHi_Status[RPS]) */
            Gmac_apxChBases[Instance][i]->DMA_RX_CONTROL &= ~GMAC_DMA_CH0_RX_CONTROL_SR_MASK;

            /* Flush the corresponding MTL Rx Queue (Channels and queues are not necessarily mapped 1:1) */
            Gmac_apxChBases[Instance][i]->DMA_RX_CONTROL |= GMAC_DMA_CH0_RX_CONTROL_RPF_MASK;
        }

        Status = Gmac_Ip_CheckMTLEmpty(Instance, Gmac_apxState[Instance]->RxRingCount, (boolean)FALSE);

        if (GMAC_STATUS_SUCCESS == Status)
        {
            /* Restore all Tx buffer addresses, clear all pending Tx requests and unlock all Tx buffers */
            Gmac_Ip_RestoreTxDescr(Instance);

            /* Restore all Rx buffer addreses and clear all pending Rx requests */
            Gmac_Ip_RestoreRxDescr(Instance);
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetSpeed
 * Description   : Sets the speed of the MII interface
 * implements     Gmac_Ip_SetSpeed_Activity
 *END**************************************************************************/
void Gmac_Ip_SetSpeed(uint8 Instance, Gmac_Ip_SpeedType Speed)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];
    GMAC_SetSpeed(Base, Speed);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetTxBuff
 * Description   : Provides a transmit buffer to be used by the application for transmission.
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_GetTxBuff(uint8 Instance,
                                     uint8 Ring,
                                     Gmac_Ip_BufferType * Buff,
                                     uint16 * BuffId)
{
    Gmac_Ip_BufferDescriptorType *Bd;
    const Gmac_Ip_ChannelType *ChBase;
    Gmac_Ip_BufferDescriptorType * ListBd;
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);
    GMAC_DEV_ASSERT(Buff != NULL_PTR);

    ChBase = Gmac_apxChBases[Instance][Ring];

    Bd = Gmac_apxState[Instance]->TxCurrentDesc[Ring];
    ListBd = (Gmac_Ip_BufferDescriptorType *)ChBase->DMA_TXDESC_LIST_ADDRESS;

    if (((Bd->Des3 & GMAC_TDES3_OWN_MASK) != 0U) ||
        ((Bd->Info1 & GMAC_INFO1_LOCKED_MASK) != 0U))
    {
        Status = GMAC_STATUS_TX_BUFF_BUSY;
    }
    else
    {
        if (Buff->Length > (Bd->Info1 & GMAC_INFO1_LENGTH_MASK))
        {
            Status = GMAC_STATUS_TX_BUFF_OVERFLOW;
            Buff->Length = (uint16)(Bd->Info1 & GMAC_INFO1_LENGTH_MASK);
        }
        else
        {
#if (GMAC_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON)
            if (!Gmac_Ip_InstHasExternalTxBufferManagement[Instance])
            {
#endif
                /* Relies on function "Gmac_Ip_GetTransmitStatus" to restore the Buffer address pointer */
                Buff->Data   = (uint8 *)Bd->Des0;
                Buff->Length = (uint16)(Bd->Info1 & GMAC_INFO1_LENGTH_MASK);
#if (GMAC_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON)
            }
#endif
            Bd->Info1 |= GMAC_INFO1_LOCKED_MASK;

            if (BuffId != NULL_PTR)
            {
                *BuffId = (uint16)((sint32)(Bd - ListBd));
            }

            Gmac_apxState[Instance]->TxCurrentDesc[Ring]++;
            if ((uint32)Gmac_apxState[Instance]->TxCurrentDesc[Ring] >=
                (uint32)&ListBd[ChBase->DMA_TXDESC_RING_LENGTH + 1UL])
            {
                Gmac_apxState[Instance]->TxCurrentDesc[Ring] = ListBd;
            }
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetTxMultiBuff
 * implements     
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_GetTxMultiBuff(uint8 Instance,
                                                  uint8 ring,
                                                  uint16 NumBuffers,
                                                  const uint16 BufferLength[],
                                                  uint16 *buffId)
{
    Gmac_Ip_BufferDescriptorType *Bd;
    const Gmac_Ip_ChannelType *ChBase;
    Gmac_Ip_BufferDescriptorType * ListBd;
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;
    uint16 FreeBuffers = 0U;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(buffId != NULL_PTR);
    GMAC_DEV_ASSERT(ring < Gmac_apxState[Instance]->TxRingCount);

    ChBase = Gmac_apxChBases[Instance][ring];
    Bd = Gmac_apxState[Instance]->TxCurrentDesc[ring];
    ListBd = (Gmac_Ip_BufferDescriptorType *)ChBase->DMA_TXDESC_LIST_ADDRESS;

    while ((FreeBuffers < NumBuffers) && (GMAC_STATUS_SUCCESS == Status))
    {
        if (((Bd->Des3 & GMAC_TDES3_OWN_MASK) != 0U) ||
            ((Bd->Info1 & GMAC_INFO1_LOCKED_MASK) != 0U))
        {
            Status = GMAC_STATUS_TX_BUFF_BUSY;
        }
        else
        {
            if (BufferLength[FreeBuffers] > (Bd->Info1 & GMAC_INFO1_LENGTH_MASK))
            {
                Status = GMAC_STATUS_TX_BUFF_OVERFLOW;
            }
            else
            {
                FreeBuffers++;
                Bd++;
                if ((uint32)Bd >= (uint32)&ListBd[ChBase->DMA_TXDESC_RING_LENGTH + 1UL])
                {
                    Bd = ListBd;
                }
            }
        }
    }

    if (FreeBuffers == NumBuffers)
    {
        *buffId = (uint16)((sint32)(Gmac_apxState[Instance]->TxCurrentDesc[ring] - ListBd));
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SendFrame
 * Description   : Sends an Ethernet frame
 * implements     Gmac_Ip_SendFrame_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_SendFrame(uint8 Instance,
                                     uint8 Ring,
                                     const Gmac_Ip_BufferType * Buff,
                                     const Gmac_Ip_TxOptionsType * Options)
{
    Gmac_Ip_ChannelType *Base;
    Gmac_Ip_BufferDescriptorType *Bd;
    Gmac_Ip_BufferDescriptorType *ListBd;
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
#endif
    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);
    GMAC_DEV_ASSERT(Buff != NULL_PTR);
    GMAC_DEV_ASSERT(Buff->Data != NULL_PTR);
    GMAC_DEV_ASSERT(Buff->Length > 0U);

    Base = Gmac_apxChBases[Instance][Ring];

    Bd = (Gmac_Ip_BufferDescriptorType *)Base->DMA_TXDESC_TAIL_POINTER;
    ListBd = (Gmac_Ip_BufferDescriptorType *)Base->DMA_TXDESC_LIST_ADDRESS;

    if ((Bd->Des3 & GMAC_TDES3_OWN_MASK) != 0U)
    {
        Status = GMAC_STATUS_TX_QUEUE_FULL;
    }
    else
    {
        Bd->Des0 = (uint32)Buff->Data;
        Bd->Des2 = (uint32)Buff->Length | GMAC_TDES2_IOC_MASK | GMAC_TDES2_TTSE_MASK;
        Bd->Info0 = (uint32)Buff->Data;


        Bd->Des3 = GMAC_TDES3_FD_MASK | GMAC_TDES3_LD_MASK |
                   (uint32)Buff->Length | GMAC_TDES3_OWN_MASK;

        if (Options != NULL_PTR)
        {
            if (Options->NoInt)
            {
                Bd->Des2 &= ~GMAC_TDES2_IOC_MASK;
            }
            Bd->Des3 |= GMAC_TDES3_CPC(Options->CrcPadIns) |
                        GMAC_TDES3_CIC(Options->ChecksumIns);
        }

        Bd++;

        /* Issued DMB Before */
        MCAL_DATA_SYNC_BARRIER();

#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
        /* Before sending, Flush + Invalidate cache in order write back the contents to main memory and mark the cache lines as invalid so that
        the future reads will be done from the memory. */
        CacheStatus = Cache_Ip_CleanByAddr(CacheType, CACHE_IP_DATA, TRUE,(uint32) Buff->Data, Buff->Length);

        if (E_NOT_OK == CacheStatus)
        {
            Status = GMAC_STATUS_CACHE_ERROR;
        }
        else
        {
#endif
        Base->DMA_TXDESC_TAIL_POINTER = (uint32)(((uint32)Bd >= (uint32)&ListBd[Base->DMA_TXDESC_RING_LENGTH + 1UL])? ListBd : Bd);
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
        }/* E_NOT_OK == CacheStatus */
#endif
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SendMultiBufferFrame
 * Description   : Sends an Ethernet frame composed out of multiple buffers (not necessarily contiguous)
 * implements
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_SendMultiBufferFrame(uint8 Instance,
                                                uint8 Ring,
                                                const Gmac_Ip_BufferType Buffers[],
                                                const Gmac_Ip_TxOptionsType *Options,
                                                uint32 NumBuffers)
{
    Gmac_Ip_ChannelType *Base;
    Gmac_Ip_BufferDescriptorType *Bd;
    Gmac_Ip_BufferDescriptorType *ListBd;
    Gmac_Ip_BufferDescriptorType *FirstBd, *LastBd;
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;
    uint32 i = 0U;
    uint32 RingLength = 0U;
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
#endif
    boolean DeAllocate = FALSE;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);
    GMAC_DEV_ASSERT(Buffers != NULL_PTR);
    GMAC_DEV_ASSERT(Options != NULL_PTR);
    GMAC_DEV_ASSERT(NumBuffers > 0U);

    Base       = Gmac_apxChBases[Instance][Ring];
    Bd         = (Gmac_Ip_BufferDescriptorType *)Base->DMA_TXDESC_TAIL_POINTER;
    ListBd     = (Gmac_Ip_BufferDescriptorType *)Base->DMA_TXDESC_LIST_ADDRESS;
    RingLength = Base->DMA_TXDESC_RING_LENGTH;

    GMAC_DEV_ASSERT(NumBuffers <= RingLength);


    FirstBd = Bd;
    LastBd  = Bd;
    while (i < NumBuffers)
    {
        GMAC_DEV_ASSERT(Buffers[i].Data != NULL_PTR);
        GMAC_DEV_ASSERT(Buffers[i].Length > 0U);

        if ((Bd->Des3 & GMAC_TDES3_OWN_MASK) != 0U)
        {
            Status = GMAC_STATUS_TX_QUEUE_FULL;
            break;
        }
        else
        {
            Bd->Des0  = (uint32)Buffers[i].Data;
            Bd->Des2  = (uint32)Buffers[i].Length;
            Bd->Info0 = (uint32)Buffers[i].Data;
            Bd->Des3  = (uint32)Buffers[i].Length | ((Bd == FirstBd)? 0U : GMAC_TDES3_OWN_MASK);

            LastBd = Bd;
            ++Bd;
        }

        Bd = ((uint32)Bd >= (uint32)&ListBd[RingLength + 1UL])? ListBd : Bd;

        ++i;
    }

    if (i == NumBuffers)
    {
        LastBd->Des2  |= GMAC_TDES2_TTSE_MASK | ((Options->NoInt == TRUE)? 0U : GMAC_TDES2_IOC_MASK);
        LastBd->Des3  |= GMAC_TDES3_LD_MASK;
        FirstBd->Des3 |= GMAC_TDES3_FD_MASK |
                         GMAC_TDES3_OWN_MASK |
                         GMAC_TDES3_CPC(Options->CrcPadIns) |
                         GMAC_TDES3_CIC(Options->ChecksumIns);

        /* Issued DMB Before */
        MCAL_DATA_SYNC_BARRIER();
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
        /* Before sending, Flush + Invalidate cache in order write back the contents to main memory and mark the cache lines as invalid so that
        the future reads will be done from the memory. */
        for (i = 0U; i < NumBuffers; i++)
        {
            CacheStatus = Cache_Ip_CleanByAddr(CacheType, CACHE_IP_DATA, TRUE,(uint32)Buffers[i].Data, (uint32)Buffers[i].Length);
            if (E_NOT_OK == CacheStatus)
            {
                DeAllocate = TRUE;
                break;
            }

        }

        if (E_NOT_OK == CacheStatus)
        {
            Status = GMAC_STATUS_CACHE_ERROR;
        }
        else
        {
#endif
        Base->DMA_TXDESC_TAIL_POINTER = (uint32)Bd;
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
        }
#endif
    }
    else
    {
        DeAllocate = TRUE;
    }
    
    /* This operation can happen when there are no enough descriptors for all the buffers or when cache operation failed */
    if (DeAllocate)
    {
        /* Clear the previously set OWN bits when the ring is full. Otherwise, future calls
         * on this ring will always (erroneously) believe that it is full. */
        while (Bd != FirstBd)
        {
            --Bd;

            Bd = ((uint32)Bd < (uint32)ListBd)? &ListBd[RingLength] : Bd;

            Bd->Des3 &= ~GMAC_TDES3_OWN_MASK;
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ReadFrame
 * Description   : Reads a received Ethernet frame
 * implements     Gmac_Ip_ReadFrame_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_ReadFrame(uint8 Instance,
                                     uint8 Ring,
                                     Gmac_Ip_BufferType * Buff,
                                     Gmac_Ip_RxInfoType * Info)
{
    const Gmac_Ip_ChannelType *ChBase;
    Gmac_Ip_BufferDescriptorType *Bd;
    Gmac_Ip_BufferDescriptorType *ListBd;
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
#endif

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->RxRingCount);
    GMAC_DEV_ASSERT(Buff != NULL_PTR);

    ChBase = Gmac_apxChBases[Instance][Ring];

    Bd = Gmac_apxState[Instance]->RxCurrentDesc[Ring];
    ListBd = (Gmac_Ip_BufferDescriptorType *)ChBase->DMA_RXDESC_LIST_ADDRESS;

    if (((Bd->Des3 & GMAC_RDES3_OWN_MASK) != 0U) ||
        ((Bd->Info1 & GMAC_INFO1_CONSUMED_MASK) != 0U) ||
         (Bd->Info0 == 0U))
    {
        Status = GMAC_STATUS_RX_QUEUE_EMPTY;
    }
    else
    {
      
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
        /* Mark the cache lines where external data buffers are placed as invalid in order to get the new data from data buffers from memory. */
        CacheStatus =  Cache_Ip_InvalidateByAddr(CacheType, CACHE_IP_DATA, (uint32)Bd->Info0, Bd->Info1 & GMAC_INFO1_LENGTH_MASK);
        if (E_NOT_OK == CacheStatus)
        {
            Status = GMAC_STATUS_CACHE_ERROR;
        }
        else
        {
#endif
            Buff->Data = (uint8 *)Bd->Info0;
            Buff->Length = (uint16)(Bd->Des3 & GMAC_RDES3_PL_MASK);
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_CHANGE_BUffER_LENGTH_FIP_1);
    #endif

            /* According to requirement CPR_RTD_00284.eth */
            if (Buff->Length > (uint16)(Bd->Info1 & GMAC_INFO1_LENGTH_MASK))
            {
                Buff->Length = (uint16)(Bd->Info1 & GMAC_INFO1_LENGTH_MASK);
            }

            Bd->Info0  = 0U;
            Bd->Info1 |= GMAC_INFO1_CONSUMED_MASK;

            if (Info != NULL_PTR)
            {
                Info->ErrMask = Bd->Des3 & GMAC_RX_STAT_ERR_MASK;
                Info->PktLen = Buff->Length;

                if ((Bd->Des3 & GMAC_RDES3_RS1V_MASK) != 0U)
                {
                    Info->IpHeaderErr = ((Bd->Des1 & GMAC_RDES1_IPHE_MASK) != 0U);
                    Info->IpPayloadErr = ((Bd->Des1 & GMAC_RDES1_IPCE_MASK) != 0U);
                    Info->Ipv4 = ((Bd->Des1 & GMAC_RDES1_IPV4_MASK) != 0U);
                    Info->Ipv6 = ((Bd->Des1 & GMAC_RDES1_IPV6_MASK) != 0U);
                    Info->PayloadType = Gmac_Ip_GetPayloadType(Bd->Des1 & GMAC_RDES1_PT_MASK);
                }

                if ((Bd->Des3 & GMAC_RDES3_RS0V_MASK) != 0U)
                {
                    Info->OuterVlanTag = (uint16)(Bd->Des0 & GMAC_RDES0_OVT_MASK);
                    Info->InnerVlanTag = (uint16)((Bd->Des0 & GMAC_RDES0_IVT_MASK) >>
                                        GMAC_RDES0_IVT_SHIFT);
                }
                else
                {
                    Info->OuterVlanTag = 0U;
                    Info->InnerVlanTag = 0U;
                }

                Gmac_Ip_ReadTimeStampInfo(Instance, Ring, Info);
            }

            Gmac_apxState[Instance]->RxCurrentDesc[Ring]++;
            if ((uint32)Gmac_apxState[Instance]->RxCurrentDesc[Ring] >=
                (uint32)&ListBd[ChBase->DMA_RXDESC_RING_LENGTH + 1UL])
            {
                Gmac_apxState[Instance]->RxCurrentDesc[Ring] = ListBd;
            }
#if (STD_ON == GMAC_HAS_CACHE_MANAGEMENT)
        }
#endif
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetRxExternalBuffer
 * Description   : Provides a receive Buffer to be used by the driver for external buffer.
 * implements     Gmac_Ip_SetRxExternalBuffer
 *END**************************************************************************/
void Gmac_Ip_SetRxExternalBuffer(uint8 Instance,
                           uint8 Ring,
                           const Gmac_Ip_BufferType * Buff)
{
    Gmac_Ip_ChannelType *Base;
    Gmac_Ip_BufferDescriptorType *Bd;
    Gmac_Ip_BufferDescriptorType *CtxtBd;
    Gmac_Ip_BufferDescriptorType *ListBd;
    uint32 RingLength;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->RxRingCount);
    GMAC_DEV_ASSERT(Buff != NULL_PTR);
    GMAC_DEV_ASSERT(Buff->Data != NULL_PTR);

    Base = Gmac_apxChBases[Instance][Ring];

    Bd = Gmac_apxState[Instance]->RxAllocDesc[Ring];
    ListBd = (Gmac_Ip_BufferDescriptorType *)Base->DMA_RXDESC_LIST_ADDRESS;
    RingLength = Base->DMA_RXDESC_RING_LENGTH + 1UL;
        if ((Bd->Des1 & GMAC_RDES1_TSA_MASK) != 0U)
    {
        CtxtBd = ((uint32)&Bd[1U] >= (uint32)&ListBd[RingLength])? ListBd : &Bd[1U];

        if (Gmac_Ip_RestoreRxCtxtDescr(CtxtBd) == TRUE)
        {
            Gmac_apxState[Instance]->RxAllocDesc[Ring] = CtxtBd;
        }
    }
    Bd->Des0 = (uint32)Buff->Data;
    Bd->Des1 = 0U;
    Bd->Des2 = 0U;
    Bd->Info0 = (uint32)Buff->Data;
    Bd->Info1 = (uint32)((uint32)Buff->Length & GMAC_INFO1_LENGTH_MASK);
    Bd->Des3  = GMAC_RDES3_OWN_MASK | GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK;
   
    Gmac_apxState[Instance]->RxAllocDesc[Ring]++;

     if ((uint32)Gmac_apxState[Instance]->RxAllocDesc[Ring] >= (uint32)&ListBd[RingLength])
    {
        Gmac_apxState[Instance]->RxAllocDesc[Ring] = ListBd;
    }


}
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ProvideRxBuff
 * Description   : Provides a receive Buffer to be used by the driver for reception.
 * implements     Gmac_Ip_ProvideRxBuff_Activity
 *END**************************************************************************/
void Gmac_Ip_ProvideRxBuff(uint8 Instance,
                           uint8 Ring,
                           const Gmac_Ip_BufferType * Buff)
{
    Gmac_Ip_ChannelType *Base;
    Gmac_Ip_BufferDescriptorType *Bd;
    Gmac_Ip_BufferDescriptorType *CtxtBd;
    Gmac_Ip_BufferDescriptorType *ListBd;
    uint32 TailPtr;
    uint32 RingLength;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->RxRingCount);
    GMAC_DEV_ASSERT(Buff != NULL_PTR);
    GMAC_DEV_ASSERT(Buff->Data != NULL_PTR);

    Base = Gmac_apxChBases[Instance][Ring];

    Bd = Gmac_apxState[Instance]->RxAllocDesc[Ring];
    ListBd = (Gmac_Ip_BufferDescriptorType *)Base->DMA_RXDESC_LIST_ADDRESS;
    TailPtr = Base->DMA_RXDESC_TAIL_POINTER;
    RingLength = Base->DMA_RXDESC_RING_LENGTH + 1UL;

    GMAC_DEV_ASSERT((Bd->Des3 & GMAC_RDES3_OWN_MASK) == 0U);

    if ((Bd->Des1 & GMAC_RDES1_TSA_MASK) != 0U)
    {
        CtxtBd = ((uint32)&Bd[1U] >= (uint32)&ListBd[RingLength])? ListBd : &Bd[1U];

        if (Gmac_Ip_RestoreRxCtxtDescr(CtxtBd) == TRUE)
        {
            Gmac_apxState[Instance]->RxAllocDesc[Ring] = CtxtBd;
        }
    }

    Bd->Des0 = (uint32)Buff->Data;
    Bd->Des1 = 0U;
    Bd->Des2 = 0U;
    Bd->Info0 = (uint32)Buff->Data;
    Bd->Info1 &= ~GMAC_INFO1_CONSUMED_MASK;
    Bd->Des3 = GMAC_RDES3_OWN_MASK | GMAC_RDES3_INTE_MASK | GMAC_RDES3_BUF1V_MASK;

    Gmac_apxState[Instance]->RxAllocDesc[Ring]++;
    if ((uint32)Gmac_apxState[Instance]->RxAllocDesc[Ring] >= (uint32)&ListBd[RingLength])
    {
        Gmac_apxState[Instance]->RxAllocDesc[Ring] = ListBd;
    }

    MCAL_DATA_SYNC_BARRIER();

    Base->DMA_RXDESC_TAIL_POINTER = TailPtr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_IsFrameAvailable
 * Description   : Checks if there are more frames available in the given queue
 *END**************************************************************************/
boolean Gmac_Ip_IsFrameAvailable(uint8 Instance,
                                 uint8 Ring)
{
    const Gmac_Ip_BufferDescriptorType *Bd;
    boolean IsFrameAvailable = FALSE;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->RxRingCount);

    Bd = Gmac_apxState[Instance]->RxCurrentDesc[Ring];

    if (((Bd->Des3 & GMAC_RDES3_OWN_MASK) == 0U) &&
        ((Bd->Info1 & GMAC_INFO1_CONSUMED_MASK) == 0U) &&
         (Bd->Info0 != 0U))
    {
        IsFrameAvailable = TRUE;
    }

    return IsFrameAvailable;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetTransmitStatus
 * Description   : Checks if the transmission of a Buffer is complete.
 * implements     Gmac_Ip_GetTransmitStatus_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_GetTransmitStatus(uint8 Instance,
                                             uint8 Ring,
                                             const Gmac_Ip_BufferType * Buff,
                                             Gmac_Ip_TxInfoType * Info)
{
    const GMAC_Type *Base;
    const Gmac_Ip_ChannelType *ChBase;
    Gmac_Ip_BufferDescriptorType *ListBd;
    Gmac_Ip_BufferDescriptorType *Bd;
    const Gmac_Ip_BufferDescriptorType *StartBd;
    Gmac_Ip_StatusType Status = GMAC_STATUS_BUFF_NOT_FOUND;
    uint32 i;
    uint32 RingLength;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Gmac_apxState[Instance] != NULL_PTR);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);
    GMAC_DEV_ASSERT(Buff != NULL_PTR);

    Base   = Gmac_apxBases[Instance];
    ChBase = Gmac_apxChBases[Instance][Ring];

    ListBd     = (Gmac_Ip_BufferDescriptorType *)ChBase->DMA_TXDESC_LIST_ADDRESS;
    Bd         = ListBd;
    RingLength = ChBase->DMA_TXDESC_RING_LENGTH;
    /* Add fault label for testing */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_READ_BUffER_ADDRESS_FIP);
    #endif
    /* Search for the Buffer descriptor associated with the given Buffer. */
    for (i = 0; i <= RingLength; i++)
    {
        if (Bd->Info0 == ((uint32)Buff->Data))
        {
            StartBd = Bd;   /* Prevent endless loop */
            while (((Bd->Des3 & GMAC_TDES3_LD_MASK) == 0U) && ((Bd->Des3 & GMAC_TDES3_OWN_MASK) == 0U))
            {
                /* Restore Buffer address pointer and clear intermediary descriptor */
                /* The writes to Des0 and Info1 are relevant only for internal buffers */
                Bd->Des0  = Bd->Info0;
                Bd->Info0 = 0U;
                Bd->Info1 &= ~GMAC_INFO1_LOCKED_MASK;

                ++Bd;
                if ((uint32)Bd >= (uint32)&ListBd[RingLength + 1UL])
                {
                    Bd = ListBd;
                }

                /* This guarantees that the loop will be terminated even if the HW malfunctions.
                 * In normal working conditions, this check will never be true. */
                if (Bd == StartBd) { break; }
            }

            /* Check if the last Buffer descriptor is still in use. */
            if (((Bd->Des3 & GMAC_TDES3_LD_MASK) != 0U) && ((Bd->Des3 & GMAC_TDES3_OWN_MASK) == 0U))
            {
                Status = GMAC_STATUS_SUCCESS;
                if (Info != NULL_PTR)
                {
                    Info->ErrMask = Bd->Des3 & GMAC_TX_STAT_ERR_MASK;
                    Gmac_Ip_GetTimestamp(Base, Bd, &Info->Timestamp);
                }

                /* Restore Buffer address pointer and clear the last descriptor after the Status was read. */
                /* The writes to Des0 and Info1 are relevant only for internal buffers */
                Bd->Des0  = Bd->Info0;
                Bd->Info0 = 0U;
                Bd->Info1 &= ~GMAC_INFO1_LOCKED_MASK;
            }
            else
            {
                Status = GMAC_STATUS_BUSY;
            }

            break;
        }
        Bd++;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetCounter
 * Description   : Gets statistics from the specified counter.
 * implements     Gmac_Ip_GetCounter_Activity
 *END**************************************************************************/
uint32 Gmac_Ip_GetCounter(uint8 Instance,
                             Gmac_Ip_CounterType Counter)
{
    const GMAC_Type *Base;
    volatile uint32 CounterAddr;
    volatile uint32 (*Count_Reg)[FEATURE_GMAC_NUM_COUNTER_REG];

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];
    CounterAddr = (uint32)(&Base->TX_OCTET_COUNT_GOOD_BAD);
    Count_Reg = (volatile uint32 (*)[FEATURE_GMAC_NUM_COUNTER_REG])CounterAddr;

    return (*Count_Reg)[Counter];
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_EnableMDIO
 * Description   : Enables the MDIO interface
 * implements     Gmac_Ip_EnableMDIO_Activity
 *END**************************************************************************/
void Gmac_Ip_EnableMDIO(uint8 Instance,
                         boolean MiiPreambleDisabled,
                         uint32 ModuleClk)
{
    static const uint32 Freq[GMAC_MDIO_CSR_NO] = { 20000000UL,  35000000UL,
                                                   60000000UL,  100000000UL,
                                                   150000000UL, 250000000UL,
                                                   300000000UL, 500000000UL,
                                                   800000000UL};
    static const uint8 CsrValues[GMAC_MDIO_CSR_NO] = { 2U, 2U, 3U, 0U, 1U, 4U, 5U, 6U, 7U };

    GMAC_Type *Base;
    uint8 Csr, i;

    GMAC_DEV_ASSERT(Instance < FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    GMAC_DEV_ASSERT(ModuleClk != 0U);

    Csr = 0U;

    for (i = 0U; i < GMAC_MDIO_CSR_NO; i++)
    {
        if (ModuleClk <= Freq[i])
        {
            Csr = CsrValues[i];
            break;
        }

    }

    Base->MAC_MDIO_ADDRESS = GMAC_MAC_MDIO_ADDRESS_PSE(MiiPreambleDisabled ? 1UL : 0UL) | GMAC_MAC_MDIO_ADDRESS_CR(Csr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_MDIORead
 * Description   : Reads the selected register of the PHY
 * implements     Gmac_Ip_MDIORead_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_MDIORead(uint8 Instance,
                                    uint8 PhyAddr,
                                    uint8 PhyReg,
                                    uint16 *Data,
                                    uint32 TimeoutMs)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status;
    Gmac_Ip_ManagementInfo ManageInfo;

    GMAC_DEV_ASSERT(Instance < FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Data != NULL_PTR);

    Base = Gmac_apxBases[Instance];
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = 0U;
    ManageInfo.OpFrameType = GMAC_MMFR_OP_READ;
    ManageInfo.FrameData = 0U;
    ManageInfo.SupportedClause45 = FALSE;

    /* Write management frame */
    Status = GMAC_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

    if (Status == GMAC_STATUS_SUCCESS)
    {
        *Data = GMAC_ReadManagementFrameData(Base);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_MDIOWrite
 * Description   : Writes the selected register of the PHY
 * implements     Gmac_Ip_MDIOWrite_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_MDIOWrite(uint8 Instance,
                                     uint8 PhyAddr,
                                     uint8 PhyReg,
                                     uint16 Data,
                                     uint32 TimeoutMs)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status;
    Gmac_Ip_ManagementInfo ManageInfo;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = 0U;
    ManageInfo.OpFrameType = GMAC_MMFR_OP_WRITE;
    ManageInfo.FrameData = Data;
    ManageInfo.SupportedClause45 = FALSE;

    /* Write management frame */
    Status = GMAC_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_MDIOReadMMD
 * Description   : Reads a register of the specified MMD in a PHY device
 * implements     Gmac_Ip_MDIOReadMMD_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_MDIOReadMMD(uint8 Instance,
                                       uint8 PhyAddr,
                                       uint8 Mmd,
                                       uint16 PhyReg,
                                       uint16 *Data,
                                       uint32 TimeoutMs)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status;
    Gmac_Ip_ManagementInfo ManageInfo;

    GMAC_DEV_ASSERT(Instance < FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Data != NULL_PTR);

    Base = Gmac_apxBases[Instance];
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = Mmd;
    ManageInfo.OpFrameType = GMAC_MMFR_OP_READ;
    ManageInfo.FrameData = 0U;
    ManageInfo.SupportedClause45 = TRUE;

    /* Write management frame */
    Status = GMAC_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

    if (Status == GMAC_STATUS_SUCCESS)
    {
        *Data = GMAC_ReadManagementFrameData(Base);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_MDIOWriteMMD
 * Description   : Writes a register of the specified MMD in a PHY device
 * implements     Gmac_Ip_MDIOWriteMMD_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_MDIOWriteMMD(uint8 Instance,
                                        uint8 PhyAddr,
                                        uint8 Mmd,
                                        uint16 PhyReg,
                                        uint16 Data,
                                        uint32 TimeoutMs)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status;
    Gmac_Ip_ManagementInfo ManageInfo;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = Mmd;
    ManageInfo.OpFrameType = GMAC_MMFR_OP_WRITE;
    ManageInfo.FrameData = Data;
    ManageInfo.SupportedClause45 = TRUE;

    /* Write management frame */
    Status = GMAC_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetMacAddr
 * Description   : Configures the physical address of the MAC
 * implements     Gmac_Ip_SetMacAddr_Activity
 *END**************************************************************************/
void Gmac_Ip_SetMacAddr(uint8 Instance,
                        const uint8 *MacAddr)
{
    uint32 Address;
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Gmac_apxBases[Instance];

    /* Set physical address high register. */
    Base->MAC_ADDRESS0_HIGH = ((uint32)MacAddr[5] << GMAC_BYTE_5_IN_ADDR_SHIFT) |
                              ((uint32)MacAddr[4] << GMAC_BYTE_4_IN_ADDR_SHIFT) |
                              GMAC_MAC_ADDRESS0_HIGH_AE_MASK;

    /* Set physical address lower register. */
    Address = ((uint32)MacAddr[3] << GMAC_BYTE_3_IN_ADDR_SHIFT) |
              ((uint32)MacAddr[2] << GMAC_BYTE_2_IN_ADDR_SHIFT) |
              ((uint32)MacAddr[1] << GMAC_BYTE_1_IN_ADDR_SHIFT) |
              ((uint32)MacAddr[0] << GMAC_BYTE_0_IN_ADDR_SHIFT);
    Base->MAC_ADDRESS0_LOW = Address;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetMacAddr
 * Description   : Gets the physical Address of the MAC
 * implements     Gmac_Ip_GetMacAddr_Activity
 *END**************************************************************************/
void Gmac_Ip_GetMacAddr(uint8 Instance,
                         uint8 *MacAddr)
{
    const GMAC_Type *Base;
    uint32 Address;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Gmac_apxBases[Instance];

    /* Get from physical Address lower register. */
    Address = Base->MAC_ADDRESS0_LOW;
    MacAddr[0] = (uint8)(GMAC_BYTE_MASK & (Address >> GMAC_BYTE_0_IN_ADDR_SHIFT));
    MacAddr[1] = (uint8)(GMAC_BYTE_MASK & (Address >> GMAC_BYTE_1_IN_ADDR_SHIFT));
    MacAddr[2] = (uint8)(GMAC_BYTE_MASK & (Address >> GMAC_BYTE_2_IN_ADDR_SHIFT));
    MacAddr[3] = (uint8)(GMAC_BYTE_MASK & (Address >> GMAC_BYTE_3_IN_ADDR_SHIFT));

    /* Get from physical Address high register. */
    Address = Base->MAC_ADDRESS0_HIGH & GMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK;
    MacAddr[4] = (uint8)(GMAC_BYTE_MASK & (Address >> GMAC_BYTE_4_IN_ADDR_SHIFT));
    MacAddr[5] = (uint8)(GMAC_BYTE_MASK & (Address >> GMAC_BYTE_5_IN_ADDR_SHIFT));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetInterruptFlags
 * Description   : Gets a mask of the common interrupt events which occurred.
 *END**************************************************************************/
uint32 Gmac_Ip_GetInterruptFlags(uint8 Instance)
{
    const GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    return Base->MAC_INTERRUPT_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetChInterruptFlags
 * Description   : Gets a mask of the interrupt events associated to a channel
 * which occurred.
 *END**************************************************************************/
uint32 Gmac_Ip_GetChInterruptFlags(uint8 Instance,
                                      uint8 Channel)
{
    const Gmac_Ip_ChannelType *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxChBases[Instance][Channel];

    return Base->DMA_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetBroadcastForwardAll
 * Description   : Enables/Disables forwarding of the broadcast traffic.
 * implements     Gmac_Ip_SetBroadcastForwardAll_Activity
 *END**************************************************************************/
void Gmac_Ip_SetBroadcastForwardAll(uint8 Instance,
                                     boolean Enable)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable)
    {
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_DBF_MASK;
    }
    else
    {
        /* Disable receive all and promiscuous modes. */
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_RA_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_PR_MASK;

        Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_DBF_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetMulticastForwardAll
 * Description   : Enables/Disables forwarding of the multicast traffic,
 * irrespective of the destination MAC Address.
 * implements     Gmac_Ip_SetMulticastForwardAll_Activity
 *END**************************************************************************/
void Gmac_Ip_SetMulticastForwardAll(uint8 Instance,
                                     boolean Enable)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable)
    {
        /* Set Pass Multicast bit. */
        Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_PM_MASK;
    }
    else
    {
        /* Disable receive all and promiscuous modes. */
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_RA_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_PR_MASK;

        /* Reset Pass Multicast and Hash Multicast bits. */
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_PM_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_HMC_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetUnicastHashFilter
 * Description   : Enables/Disables hash filteRing for unicast traffic.
 * implements     Gmac_Ip_SetUnicastHashFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_SetUnicastHashFilter(uint8 Instance,
                                   boolean Enable)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable)
    {
        /* Disable receive all and promiscuous modes. */
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_RA_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_PR_MASK;

        Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_HUC_MASK;
    }
    else
    {
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_HUC_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetMulticastHashFilter
 * Description   : Enables/Disables hash filtering for multicast traffic.
 * implements     Gmac_Ip_SetMulticastHashFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_SetMulticastHashFilter(uint8 Instance,
                                     boolean Enable)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable)
    {
        /* Disable receive all and promiscuous modes. */
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_RA_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_PR_MASK;

        Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_HMC_MASK;
    }
    else
    {
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_HMC_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetHashOrPerfectFilter
 * Description   : Enables/Disables either hash or perfect filters.
 * implements     Gmac_Ip_SetHashOrPerfectFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_SetHashOrPerfectFilter(uint8 Instance,
                                     boolean Enable)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable)
    {
        /* Disable receive all and promiscuous modes. */
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_RA_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_PR_MASK;

        Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_HPF_MASK;
    }
    else
    {
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_HPF_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_AddDstAddrToHashFilter
 * Description   : Adds a hardware Address to the hash filter.
 * implements     Gmac_Ip_AddDstAddrToHashFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_AddDstAddrToHashFilter(uint8 Instance,
                                     const uint8 *MacAddr)
{
    const GMAC_Type *Base;
    uint32 Crc;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Gmac_apxBases[Instance];
    Crc = Gmac_Ip_ComputeCRC32(MacAddr, 6U);

    GMAC_AddToHashTable(Base, Crc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_RemoveDstAddrFromHashFilter
 * Description   : Removes a hardware Address from the hash filter.
 * implements     Gmac_Ip_RemoveDstAddrFromHashFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_RemoveDstAddrFromHashFilter(uint8 Instance,
                                          const uint8 *MacAddr)
{
    const GMAC_Type *Base;
    uint32 Crc;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Gmac_apxBases[Instance];
    Crc = Gmac_Ip_ComputeCRC32(MacAddr, 6U);

    GMAC_RemoveFromHashTable(Base, Crc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetAddrPerfectFilter
 * Description   : Sets the second destination/source Address perfect filter.
 * implements     Gmac_Ip_SetAddrPerfectFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_SetAddrPerfectFilter(uint8 Instance,
                                   const uint8 *MacAddr,
                                   const uint8 Mask,
                                   const Gmac_Ip_MacAddrFilterType AddrType,
                                   boolean Enable)
{
    uint32 Address;
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable) {
        GMAC_DEV_ASSERT(MacAddr != NULL_PTR);

        /* Set destination/source Address filtering. */
        if (AddrType != GMAC_DST_ADRR_FILTER)
        {
            Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_SAF_MASK;

            /* Enable source Address inverse filter. */
            if (AddrType == GMAC_SRC_ADDR_INV_FILTER)
            {
                Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_SAIF_MASK;
            }

            /* Enable MAC Address to be used to compare source Address of received packet. */
            Base->MAC_ADDRESS1_HIGH = GMAC_MAC_ADDRESS1_HIGH_SA(1);
        }
        else
        {
            Base->MAC_ADDRESS1_HIGH = GMAC_MAC_ADDRESS1_HIGH_SA(0);
        }

        /* Set the mask for group Address filtering. */
        Base->MAC_ADDRESS1_HIGH |= GMAC_MAC_ADDRESS1_HIGH_MBC(Mask);

        /* Set physical Address high register. */
        Base->MAC_ADDRESS1_HIGH |= ((uint32)MacAddr[5] << GMAC_BYTE_5_IN_ADDR_SHIFT) |
                                   ((uint32)MacAddr[4] << GMAC_BYTE_4_IN_ADDR_SHIFT) |
                                    GMAC_MAC_ADDRESS1_HIGH_AE_MASK;

        /* Set physical Address lower register. */
        Address = ((uint32)MacAddr[3] << GMAC_BYTE_3_IN_ADDR_SHIFT) |
                  ((uint32)MacAddr[2] << GMAC_BYTE_2_IN_ADDR_SHIFT) |
                  ((uint32)MacAddr[1] << GMAC_BYTE_1_IN_ADDR_SHIFT) |
                  ((uint32)MacAddr[0] << GMAC_BYTE_0_IN_ADDR_SHIFT);
        Base->MAC_ADDRESS1_LOW = Address;
    }
    else
    {
        Base->MAC_ADDRESS1_HIGH = GMAC_MAC_HW_ADDRESS1_HIGH_RESET_MASK;
        Base->MAC_ADDRESS1_LOW = GMAC_MAC_HW_ADDRESS1_LOW_RESET_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_SAF_MASK;
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_SAIF_MASK;
    }
}


#if FEATURE_GMAC_ARP_EN
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetArpOffloading
 * Description   : Enables/Disables recognition of ARP requests and automatic
 * transmission of ARP responses.
 * implements     Gmac_Ip_SetArpOffloading_Activity
 *END**************************************************************************/
void Gmac_Ip_SetArpOffloading(uint8 Instance,
                               const uint8 *DstAddr,
                               boolean Enable)
{
    GMAC_Type *Base;
    uint32 Address;

   GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

   Base = Gmac_apxBases[Instance];

   if (Enable)
   {
       GMAC_DEV_ASSERT(DstAddr != NULL_PTR);

       Base->MAC_CONFIGURATION |= GMAC_MAC_CONFIGURATION_ARPEN_MASK;

       Address = ((uint32)DstAddr[0] << GMAC_BYTE_3_IN_ADDR_SHIFT) |
                 ((uint32)DstAddr[1] << GMAC_BYTE_2_IN_ADDR_SHIFT) |
                 ((uint32)DstAddr[2] << GMAC_BYTE_1_IN_ADDR_SHIFT) |
                 ((uint32)DstAddr[3] << GMAC_BYTE_0_IN_ADDR_SHIFT);
       Base->MAC_ARP_ADDRESS = Address;
   }
   else
   {
       Base->MAC_CONFIGURATION &= ~GMAC_MAC_CONFIGURATION_ARPEN_MASK;
   }
}
#endif /* FEATURE_GMAC_ARP_EN */

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_EnableVlan
 * Description   : Enables and configures VLAN for transmitted and received
 * packets.
 * implements     Gmac_Ip_EnableVlan_Activity
 *END**************************************************************************/
void Gmac_Ip_EnableVlan(uint8 Instance,
                         const Gmac_Ip_VlanConfigType * VlanConfig)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(VlanConfig != NULL_PTR);

    Base = Gmac_apxBases[Instance];

    Base->MAC_VLAN_TAG_CTRL_REG = GMAC_MAC_VLAN_TAG_CTRL_EDVLP((VlanConfig->EnDoubleVlan) ? 1UL : 0UL) |
                              GMAC_MAC_VLAN_TAG_CTRL_ESVL((VlanConfig->EnSvlan) ? 1UL : 0UL) |
                              GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS(1U) |
                              GMAC_MAC_VLAN_TAG_CTRL_EIVLS(VlanConfig->InnerVlanStrip) |
                              GMAC_MAC_VLAN_TAG_CTRL_EVLRXS(1U) |
                              GMAC_MAC_VLAN_TAG_CTRL_EVLS(VlanConfig->OuterVlanStrip);
    Base->MAC_VLAN_INCL_REG = GMAC_MAC_VLAN_INCL_VLTI(0U) |
                          GMAC_MAC_VLAN_INCL_VLP(1U) |
                          ((uint32)(((uint32)VlanConfig->OuterVlanIns) <<
                           GMAC_MAC_VLAN_INCL_VLC_SHIFT));

    if (VlanConfig->OuterVlanIns == GMAC_VLAN_TAG_INSERTION)
    {
        Base->MAC_VLAN_INCL_REG |= GMAC_MAC_VLAN_INCL_CBTI_MASK;
    }

    Base->MAC_INNER_VLAN_INCL = GMAC_MAC_INNER_VLAN_INCL_VLTI(0U) |
                                GMAC_MAC_INNER_VLAN_INCL_VLP(1U) |
                                ((uint32)(((uint32)VlanConfig->InnerVlanIns) <<
                                 GMAC_MAC_INNER_VLAN_INCL_VLC_SHIFT));

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetTxOuterVlanTagForInsertion
 * Description   : Sets outer VLAN type and tag to be inserted for a
 * particular transmission ring.
 * implements     Gmac_Ip_SetTxOuterVlanTagForInsertion_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_SetTxOuterVlanTagForInsertion(uint8 Instance,
                                                         uint8 Ring,
                                                         Gmac_Ip_VlanType VlanType,
                                                         uint16 VlanTag)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);

    Base = Gmac_apxBases[Instance];

    if (((uint32)((Base->MAC_VLAN_INCL_REG & GMAC_MAC_VLAN_INCL_VLC_MASK) >>
        GMAC_MAC_VLAN_INCL_VLC_SHIFT)) ==
        ((uint32)GMAC_VLAN_TAG_INSERTION))
    {
        /* Add fault label for testing */
        #ifdef MCAL_ENABLE_FAULT_INJECTION
            MCAL_FAULT_INJECTION_POINT(ETH_VLAN_TAG_INSERTION_BUSY);
        #endif
        /* Check if the Ring is being updated. */
        if ((Base->MAC_VLAN_INCL_REG & GMAC_MAC_VLAN_INCL_BUSY_MASK) != 0U)
        {
            Status =  GMAC_STATUS_BUSY;
        }
        else
        {
            Base->MAC_VLAN_INCL_REG &= ~GMAC_MAC_VLAN_INCL_ADDR_MASK;

            /* Initiate indirect write access for the selected Ring. */
            Base->MAC_VLAN_INCL_REG |= (uint32)(((uint32)Ring) <<
                                   GMAC_MAC_VLAN_INCL_ADDR_SHIFT);

            /* Enable write access. */
            Base->MAC_VLAN_INCL_REG |= GMAC_MAC_VLAN_INCL_RDWR(1U);

            Base->MAC_VLAN_INCL_REG &= ~(GMAC_MAC_VLAN_INCL_CSVL_MASK |
                                     GMAC_MAC_VLAN_INCL_VLT_MASK);

            /* Set the VLAN type and tag to be inserted/replaced. */
            Base->MAC_VLAN_INCL_REG |= ((uint32)(((uint32)VlanType) <<
                                    GMAC_MAC_VLAN_INCL_CSVL_SHIFT)) |
                                   ((uint32)(((uint32)VlanTag) <<
                                    GMAC_MAC_VLAN_INCL_VLT_SHIFT));

            /* Disable write access. */
            Base->MAC_VLAN_INCL_REG &= ~GMAC_MAC_VLAN_INCL_RDWR_MASK;
            /* Add fault label for testing */
            #ifdef MCAL_ENABLE_FAULT_INJECTION
                MCAL_FAULT_INJECTION_POINT(ETH_VLAN_TAG_INSERTION_TIMEOUT);
            #endif
            GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);
            do
            {
                if ((Base->MAC_VLAN_INCL_REG & GMAC_MAC_VLAN_INCL_BUSY_MASK) == 0U)
                {
                    Status = GMAC_STATUS_SUCCESS;
                    break;
                }
            }
            while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));
        }
    }
    else
    {
        Status = GMAC_STATUS_UNSUPPORTED;
    }

   return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetTxOuterVlanTagForReplacement
 * Description   : Sets outer VLAN tag to be replaced for all transmission
 * rings.
 * implements     Gmac_Ip_SetTxOuterVlanTagForReplacement_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_SetTxOuterVlanTagForReplacement(uint8 Instance,
                                                           Gmac_Ip_VlanType VlanType,
                                                           uint16 VlanTag)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (((uint32)((Base->MAC_VLAN_INCL_REG & GMAC_MAC_VLAN_INCL_VLC_MASK) >>
        GMAC_MAC_VLAN_INCL_VLC_SHIFT)) ==
        ((uint32)GMAC_VLAN_TAG_REPLACEMENT))
    {
        Base->MAC_VLAN_INCL_REG &= ~(GMAC_MAC_VLAN_INCL_CSVL_MASK |
                               GMAC_MAC_VLAN_INCL_VLT_MASK);

        /* Set the VLAN type and tag to be inserted/replaced. */
        Base->MAC_VLAN_INCL_REG |= ((uint32)(((uint32)VlanType) <<
                                GMAC_MAC_VLAN_INCL_CSVL_SHIFT)) |
                               ((uint32)(((uint32)VlanTag) <<
                                GMAC_MAC_VLAN_INCL_VLT_SHIFT));
    }
    else
    {
        Status = GMAC_STATUS_UNSUPPORTED;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetTxInnerVlanTag
 * Description   : Sets inner VLAN type and tag to be inserted/replaced on
 * transmission.
 * implements     Gmac_Ip_SetTxInnerVlanTag_Activity
 *END**************************************************************************/
void Gmac_Ip_SetTxInnerVlanTag(uint8 Instance,
                              Gmac_Ip_VlanType VlanType,
                              uint16 VlanTag)
{
   GMAC_Type *Base;

   GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

   Base = Gmac_apxBases[Instance];

   Base->MAC_INNER_VLAN_INCL &= ~(GMAC_MAC_INNER_VLAN_INCL_CSVL_MASK |
                                  GMAC_MAC_INNER_VLAN_INCL_VLT_MASK);

   /* Set the VLAN type and tag to be inserted/replaced. */
   Base->MAC_INNER_VLAN_INCL |= ((uint32)(((uint32)VlanType) <<
                                 GMAC_MAC_INNER_VLAN_INCL_CSVL_SHIFT)) |
                                ((uint32)(((uint32)VlanTag) <<
                                 GMAC_MAC_INNER_VLAN_INCL_VLT_SHIFT));
}

#if (FEATURE_GMAC_VLAN_RX_FILTERS_NUM > 0U)
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetVlanTagRxFilter
 * Description   : Enables/disables and configures the Rx filters for VLAN tag.
 * implements     Gmac_Ip_SetVlanTagRxFilter_Activity
 *END**************************************************************************/
void Gmac_Ip_SetVlanTagRxFilter(uint8 Instance,
                                 boolean Enable,
                                 const Gmac_Ip_VlanRxFilterType * RxFilter)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (Enable)
    {
        GMAC_DEV_ASSERT(RxFilter != NULL_PTR);

        Base->MAC_PACKET_FILTER |= GMAC_MAC_PACKET_FILTER_VTFE_MASK;
        Base->MAC_VLAN_TAG_CTRL_REG |= GMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK;

        GMAC_SetVlanTagInvMatch(Base, RxFilter->EnInverseMatch);
        Base->MAC_VLAN_TAG_CTRL_REG |= GMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK;
        GMAC_SetVlanTagDataRxMatch(Base,
                                   RxFilter->EnInnerVlanMatch,
                                   RxFilter->EnSvlanMatch,
                                   RxFilter->DisVlanTypeMatch,
                                   RxFilter->En12bitMatch);
    }
    else
    {
        Base->MAC_PACKET_FILTER &= ~GMAC_MAC_PACKET_FILTER_VTFE_MASK;
        Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_AddVlanTagToRxFilter
 * Description   : Adds a VLAN Tag to the Rx filter
 *
 * Note: The acceptance criteria depend on the options configured for the Rx
 * filters. To enable and configure the Rx filter, please see the documentation
 * for Gmac_Ip_SetVlanTagRxFilter() function.
 * implements     Gmac_Ip_AddVlanTagToRxFilter_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_AddVlanTagToRxFilter(uint8 Instance,
                                                uint8 FilterIdx,
                                                uint16 VlanTag)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint16 Tag;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(FilterIdx < FEATURE_GMAC_VLAN_RX_FILTERS_NUM);

    Base = Gmac_apxBases[Instance];

    /* Clear VLAN tag. */
    Base->MAC_VLAN_TAG_DATA_REG &= ~GMAC_MAC_VLAN_TAG_DATA_VID_MASK;
    /* Clear filter offset. */
    Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_OFS_MASK;

    /* Set the VLAN tag. */
    Base->MAC_VLAN_TAG_DATA_REG |= ((uint32)(((uint32)VlanTag) <<
                               GMAC_MAC_VLAN_TAG_DATA_VID_SHIFT)) |
                               GMAC_MAC_VLAN_TAG_DATA_VEN_MASK;

    /* Set filter offset. */
    Base->MAC_VLAN_TAG_CTRL_REG |= (uint32)(((uint32)FilterIdx) <<
                               GMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT);
    /* Enable write operation. */
    Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_CT_MASK;
    /* Set busy bit. */
    Base->MAC_VLAN_TAG_CTRL_REG |= GMAC_MAC_VLAN_TAG_CTRL_OB_MASK;
    /* Add fault label for testing */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_ADD_VLAN_TAG_TIMEOUT);
    #endif
    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);
    do
    {
        if ((Base->MAC_VLAN_TAG_CTRL_REG & GMAC_MAC_VLAN_TAG_CTRL_OB_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    /* Read filter contents. */
    (void)GMAC_ReadVlanTagRxFilter(Base, FilterIdx, &Tag);
    (void)Tag;

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ReadVlanTagRxFilter
 * Description   : Reads a VLAN Tag Rx filter.
 * implements     Gmac_Ip_ReadVlanTagRxFilter_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_ReadVlanTagRxFilter(uint8 Instance,
                                               uint8 FilterIdx,
                                               uint16 * VlanTag)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(FilterIdx < FEATURE_GMAC_VLAN_RX_FILTERS_NUM);

    Base = Gmac_apxBases[Instance];

    return GMAC_ReadVlanTagRxFilter(Base, FilterIdx, VlanTag);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_ClearVlanTagRxFilter
 * Description   : Clears a VLAN Tag Rx filter.
 * implements     Gmac_Ip_ClearVlanTagRxFilter_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_ClearVlanTagRxFilter(uint8 Instance,
                                                uint8 FilterIdx)
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime, ElapsedTime, TimeoutTicks;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(FilterIdx < FEATURE_GMAC_VLAN_RX_FILTERS_NUM);

    Base = Gmac_apxBases[Instance];

    /* Clear and disable the VLAN Tag. */
    Base->MAC_VLAN_TAG_DATA_REG &= ~(GMAC_MAC_VLAN_TAG_DATA_VID_MASK |
                                            GMAC_MAC_VLAN_TAG_DATA_VEN_MASK);

    /* Clear filter offset. */
    Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_OFS_MASK;
    /* Set filter offset. */
    Base->MAC_VLAN_TAG_CTRL_REG |= (uint32)(((uint32)FilterIdx) <<
                               GMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT);
    /* Enable write operation. */
    Base->MAC_VLAN_TAG_CTRL_REG &= ~GMAC_MAC_VLAN_TAG_CTRL_CT_MASK;
    /* Set busy bit. */
    Base->MAC_VLAN_TAG_CTRL_REG |= GMAC_MAC_VLAN_TAG_CTRL_OB_MASK;

#ifdef MCAL_ENABLE_FAULT_INJECTION
    MCAL_FAULT_INJECTION_POINT(ETH_CLEAR_VLAN_TAG_RX_FILTER_TIMEOUT);
#endif

    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);
    do
    {
        if ((Base->MAC_VLAN_TAG_CTRL_REG & GMAC_MAC_VLAN_TAG_CTRL_OB_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_AddVlanTagToHashTable
 * Description   : Adds a VLAN Tag to the hash table
 *
 * Note: The hash table filter only applies to 16-bit outer VLAN tag. The
 * options configured via Gmac_Ip_SetVlanTagRxFilter() do not apply as
 * acceptance criteria for Hash Table filter.
 * implements     Gmac_Ip_AddVlanTagToHashTable_Activity
 *END**************************************************************************/
void Gmac_Ip_AddVlanTagToHashTable(uint8 Instance,
                                   uint16 VlanTag)
{
    GMAC_Type *Base;
    uint32 crc;
    uint32 tag32;
    const uint8 *tag;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    tag32 = (uint32)VlanTag;
    tag   = (uint8 *)&tag32;

    crc = Gmac_Ip_ComputeCRC32(tag, 2U);
    GMAC_AddVlanToHashTable(Base, crc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_RemoveVlanTagFromHashTable
 * Description   : Adds a VLAN Tag to the hash table
 * implements     Gmac_Ip_RemoveVlanTagFromHashTable_Activity
 *END**************************************************************************/
void Gmac_Ip_RemoveVlanTagFromHashTable(uint8 Instance,
                                        uint16 VlanTag)
{
    GMAC_Type *Base;
    uint32 Crc;
    uint32 Tag32;
    const uint8 *Tag;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    Tag32 = (uint32)VlanTag;
    Tag   = (uint8 *)&Tag32;

    Crc = Gmac_Ip_ComputeCRC32(Tag, 2U);
    GMAC_RemoveVlanFromHashTable(Base, Crc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_InitSysTime
 * Description   : Initializes the system time.
 * implements     Gmac_Ip_InitSysTime_Activity
 *END**************************************************************************/
void Gmac_Ip_InitSysTime(uint8 Instance,
                         const Gmac_Ip_SysTimeConfigType * SysTimeConfig)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(SysTimeConfig != NULL_PTR);
    GMAC_DEV_ASSERT(SysTimeConfig->InitialTimestamp != NULL_PTR);

    Base = Gmac_apxBases[Instance];

    /* Set sub-second and sub-nanosecond increments. */
    Base->MAC_SUB_SECOND_INCREMENT = GMAC_MAC_SUB_SECOND_INCREMENT_SSINC(SysTimeConfig->SubSecondInc) |
                                     GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC(SysTimeConfig->SubNanoSecondsInc);
    /* Enable digital rollover, enable Timestamping for all packets, enable Timestamp. */
    Base->MAC_TIMESTAMP_CONTROL = GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK |
                                  GMAC_MAC_TIMESTAMP_CONTROL_TSENALL_MASK |
                                  GMAC_MAC_TIMESTAMP_CONTROL_TSENA_MASK;
    /* Set initial value for system time. */
    Base->MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS = SysTimeConfig->InitialTimestamp->secondsHi;
    Base->MAC_SYSTEM_TIME_SECONDS_UPDATE = SysTimeConfig->InitialTimestamp->seconds;
    Base->MAC_SYSTEM_TIME_NANOSECONDS_UPDATE = (SysTimeConfig->InitialTimestamp->nanoseconds) &
                                               GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK;
    /* Initialize the Timestamp. */
    Base->MAC_TIMESTAMP_CONTROL |= GMAC_MAC_TIMESTAMP_CONTROL_TSINIT_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetSysTimeCorr
 * Description   : Sets the system time correction by either adding or subtracting
 *                 the selected value from the current system time.
 * implements     Gmac_Ip_SetSysTimeCorr_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_SetSysTimeCorr(uint8 Instance,
                                          Gmac_Ip_SysTimeCorrOffsetType Offset,
                                          uint32 SecondsUpdate,
                                          uint32 NanoSecondsUpdate)
{
    GMAC_Type *Base;
    uint32 seconds, Nanoseconds;
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    if (((uint32)Offset) != 0U)
    {
        seconds = (uint32)(GMAC_SYS_TIME_SEC_MAX_VALUE - SecondsUpdate);
        Nanoseconds = (uint32)(GMAC_SYS_TIME_NANOSEC_MAX_VALUE -
                      NanoSecondsUpdate);
    }
    else
    {
        seconds = SecondsUpdate;
        Nanoseconds = NanoSecondsUpdate;
    }

    Base->MAC_SYSTEM_TIME_NANOSECONDS_UPDATE = GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB(Offset) |
                                               GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS(Nanoseconds);
    Base->MAC_SYSTEM_TIME_SECONDS_UPDATE = GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS(seconds);

    Base->MAC_TIMESTAMP_CONTROL |= GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK;

    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);

    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_SETSYSTIMECORR);
    #endif

    do
    {
        if ((Base->MAC_TIMESTAMP_CONTROL & GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetRateRatioCorr
 * Description   : Sets the system time correction by rate ratio
 *                 the selected value from the current system time.
 *
 * Implements    : Gmac_Ip_SetRateRatioCorr_Activity
 *END**************************************************************************/
Gmac_Ip_StatusType Gmac_Ip_SetRateRatioCorr(uint8 Instance,
                                            float64 RateRatio
                                           )
{
    GMAC_Type *Base;
    Gmac_Ip_StatusType Status = GMAC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Base = Gmac_apxBases[Instance];

    Base->MAC_TIMESTAMP_ADDEND = GMAC_MAC_TIMESTAMP_ADDEND_TSAR((uint32)((float64)0x100000000ULL / RateRatio));

    Base->MAC_TIMESTAMP_CONTROL |= GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK;
    /* Add fault label for testing */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_RATE_RATIO_TIMEOUT);
    #endif
    GMAC_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, GMAC_TIMEOUT_VALUE_US);

    do
    {
        if ((Base->MAC_TIMESTAMP_CONTROL & GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK) == 0U)
        {
            Status = GMAC_STATUS_SUCCESS;
            break;
        }
    }
    while (!GMAC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    Base->MAC_TIMESTAMP_CONTROL |= GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK;

    return Status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_GetSysTime
 * Description   : Gets the current system time.
 * implements     Gmac_Ip_GetSysTime_Activity
 *END**************************************************************************/
void Gmac_Ip_GetSysTime(uint8 Instance, Gmac_Ip_TimestampType * Timestamp)
{
    const GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Timestamp != NULL_PTR);

    Base = Gmac_apxBases[Instance];

    Timestamp->secondsHi = (uint16)(Base->MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS);
    Timestamp->seconds = (uint32)(Base->MAC_SYSTEM_TIME_SECONDS);
    Timestamp->nanoseconds = (uint32)(Base->MAC_SYSTEM_TIME_NANOSECONDS);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetTxSchedAlgo
 * Description   : Sets the transmitter scheduling algorithm.
 * implements     Gmac_Ip_SetTxSchedAlgo_Activity
 *END**************************************************************************/
void Gmac_Ip_SetTxSchedAlgo(uint8 Instance, Gmac_Ip_TxSchedAlgoType SchedAlgo)
{
    GMAC_Type *Base;

    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);

    Base = Gmac_apxBases[Instance];

    GMAC_SetSchedAlg(Base, SchedAlgo);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetTxRingWeight
 * Description   : Sets the Weight (in WRR scheduling algorithm) for a
 *                 particular Tx ring.
 *
 * If multiple rings are configured and the WWR scheduling algorithm is
 * selected, the Weight must be programmed with a non-zero value. The maximum
 * value for the Weight is 0x64.
 * implements     Gmac_Ip_SetTxRingWeight_Activity
 *END**************************************************************************/
void Gmac_Ip_SetTxRingWeight(uint8 Instance, uint8 Ring, uint32 Weight)
{
    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);
    GMAC_DEV_ASSERT((Weight > 0U) && (Weight <= GMAC_MAX_WEIGHT_VALUE));

    if (Gmac_apxState[Instance]->TxRingCount > 1U)
    {
        GMAC_SetTxQueueQuantumWeight(Gmac_apxQueueBases[Instance][Ring], Weight);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_EnableTxStoreAndForward
 * Description   : Enables the store and forward feature on the transmit path.
 * implements     Gmac_Ip_EnableTxStoreAndForward_Activity
 *END**************************************************************************/
void Gmac_Ip_EnableTxStoreAndForward(uint8 Instance, uint8 Ring)
{
    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);

    GMAC_SetTxStoreAndForward(Gmac_apxQueueBases[Instance][Ring]);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Gmac_Ip_SetTxThreshold
 * Description   : Sets transmit threshold levels.
 *
 * The transmission starts when the packet size within the Tx Queue is larger
 * than the threshold. In addition, full packets with length less than the
 * threshold are also transmitted.
 * implements     Gmac_Ip_SetTxThreshold_Activity
 *END**************************************************************************/
void Gmac_Ip_SetTxThreshold(uint8 Instance,
                             uint8 Ring,
                             Gmac_Ip_TxThresholdType ThresholdValue)
{
    GMAC_DEV_ASSERT(Instance <  FEATURE_GMAC_NUM_INSTANCES);
    GMAC_DEV_ASSERT(Ring < Gmac_apxState[Instance]->TxRingCount);

    GMAC_SetTxThreshold(Gmac_apxQueueBases[Instance][Ring], ThresholdValue);
}

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
