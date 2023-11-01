/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Stm_Ip.c
*
*   @addtogroup stm_ip Stm IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Stm_Ip.h"

#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STM_IP_ENABLE_USER_MODE_SUPPORT)
    #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define STM_IP_VENDOR_ID_C                    43
#define STM_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define STM_IP_AR_RELEASE_MINOR_VERSION_C     7
#define STM_IP_AR_RELEASE_REVISION_VERSION_C  0
#define STM_IP_SW_MAJOR_VERSION_C             1
#define STM_IP_SW_MINOR_VERSION_C             0
#define STM_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != STM_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != STM_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and Stm_Ip.c are different"
    #endif
#endif
#endif

#if (STM_IP_VENDOR_ID != STM_IP_VENDOR_ID_C)
    #error "Stm_Ip.h and Stm_Ip.c have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION != STM_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION != STM_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION != STM_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Stm_Ip.h and Stm_Ip.c are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION != STM_IP_SW_MAJOR_VERSION_C) || \
     (STM_IP_SW_MINOR_VERSION != STM_IP_SW_MINOR_VERSION_C) || \
     (STM_IP_SW_PATCH_VERSION != STM_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Stm_Ip.h and Stm_Ip.c are different"
#endif
/*==================================================================================================
*                                          LOCAL DEFINIES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (STM_IP_USED == STD_ON)

#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/** @brief Global array variable used to store the runtime target time value. */
uint32 Stm_Ip_u32TargetValue[GPT_STM_INSTANCE_COUNT][STM_CHANNEL_COUNT];
#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )
uint32 Stm_Ip_u32NextTargetValue[GPT_STM_INSTANCE_COUNT][STM_CHANNEL_COUNT];
#endif

#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (defined(CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED) && (CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED == STD_ON))
/** @brief Table of base addresses for STM instances. */
#define IP_STM_BASE_PTRS_CONCATENATED   { IP_CRS__STM, IP_FSS__COSS_STM_0, IP_FSS__COSS_STM_1, IP_FSS__COSS_STM_2, IP_FSS__COSS_STM_3, IP_FSS__STM_0, IP_FSS__STM_1, IP_FSS__STM_AUX_0, IP_FSS__STM_AUX_1, IP_FSS__STM_AUX_2, (STM_Type *)IP_RTU0__RTU_STM0_BASE, (STM_Type *)IP_RTU0__RTU_STM1_BASE, (STM_Type *)IP_RTU0__RTU_STM2_BASE, (STM_Type *)IP_RTU0__RTU_STM3_BASE, (STM_Type *)IP_RTU1__RTU_STM0_BASE, (STM_Type *)IP_RTU1__RTU_STM1_BASE, (STM_Type *)IP_RTU1__RTU_STM2_BASE, (STM_Type *)IP_RTU1__RTU_STM3_BASE, (STM_Type *)IP_RTU2__RTU_STM0_BASE, (STM_Type *)IP_RTU2__RTU_STM1_BASE, (STM_Type *)IP_RTU2__RTU_STM2_BASE, (STM_Type *)IP_RTU2__RTU_STM3_BASE, (STM_Type *)IP_RTU3__RTU_STM0_BASE, (STM_Type *)IP_RTU3__RTU_STM1_BASE, (STM_Type *)IP_RTU3__RTU_STM2_BASE, (STM_Type *)IP_RTU3__RTU_STM3_BASE  }
STM_Type * const stmBase[GPT_STM_INSTANCE_COUNT] = IP_STM_BASE_PTRS_CONCATENATED;
#else
/** @brief Table of base addresses for STM instances. */
STM_Type * const stmBase[GPT_STM_INSTANCE_COUNT] = IP_STM_BASE_PTRS;
#endif

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )
/** @brief Global array variable used to channel state for process common interrupt */
static Stm_Ip_ChState Stm_Ip_u32ChState[GPT_STM_INSTANCE_COUNT][STM_CHANNEL_COUNT] =  {
                                                                                    {
                                                                                        {
                                                                                            (boolean)FALSE,
                                                                                            NULL_PTR,
                                                                                            0U,
                                                                                            STM_IP_CH_MODE_CONTINUOUS
                                                                                        }
                                                                                    }
                                                                                };
#endif
#if (STM_IP_SET_CLOCK_MODE == STD_ON)
static Stm_Ip_InstanceState Stm_Ip_u32InstanceState[GPT_STM_INSTANCE_COUNT] =   {
                                                                                {
                                                                                    0U,
                                                                                    0U
                                                                                }
                                                                            };
#endif
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

static inline void Stm_Ip_SetDebugMode(uint8 instance, boolean stopRun);
static inline void Stm_Ip_TimerEnable(uint8 instance, boolean enable);
static inline uint32 Stm_Ip_GetTimerEnableBit(uint8 instance);
static inline void Stm_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue);
static inline void Stm_Ip_SetInterruptEnableFlag(uint8 instance, uint8 channel, boolean enable);
static inline void Stm_Ip_ClearInterruptStatusFlag(uint8 instance, uint8 channel);
static inline void Stm_Ip_SetCmpValue(uint8 instance, uint8 channel, uint32 compareValue);
static inline uint32 Stm_Ip_GetCmpValue(uint8 instance, uint8 channel);
static inline void Stm_Ip_SetCntValue(uint8 instance, uint32 counterValue);
static inline uint32 Stm_Ip_GetCntValue(uint8 instance);

#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )
static void Stm_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel);
static inline boolean Stm_Ip_GetInterruptEnableFlag(uint8 instance, uint8 channel);
#endif
/*=============================================================================== )===================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
    void Stm_Ip_SetUserAccessAllowed(uint32 StmBaseAddr);
#endif

#if (defined(MCAL_STM_REG_PROT_AVAILABLE) && (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT))
    #define Call_Stm_Ip_SetUserAccessAllowed(BaseAddr) OsIf_Trusted_Call1param(Stm_Ip_SetUserAccessAllowed,(BaseAddr))
#else
    #define Call_Stm_Ip_SetUserAccessAllowed(BaseAddr)
#endif

#if ((STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS))

#if defined(RTU0_STM_0_ISR_USED)
ISR(RTU0_STM_0_ISR);
#endif
#if defined(RTU0_STM_1_ISR_USED)
ISR(RTU0_STM_1_ISR);
#endif
#if defined(RTU0_STM_2_ISR_USED)
ISR(RTU0_STM_2_ISR);
#endif
#if defined(RTU0_STM_3_ISR_USED)
ISR(RTU0_STM_3_ISR);
#endif
#if defined(RTU1_STM_0_ISR_USED)
ISR(RTU1_STM_0_ISR);
#endif
#if defined(RTU1_STM_1_ISR_USED)
ISR(RTU1_STM_1_ISR);
#endif
#if defined(RTU1_STM_2_ISR_USED)
ISR(RTU1_STM_2_ISR);
#endif
#if defined(RTU1_STM_3_ISR_USED)
ISR(RTU1_STM_3_ISR);
#endif
#if defined(RTU2_STM_0_ISR_USED)
ISR(RTU2_STM_0_ISR);
#endif
#if defined(RTU2_STM_1_ISR_USED)
ISR(RTU2_STM_1_ISR);
#endif
#if defined(RTU2_STM_2_ISR_USED)
ISR(RTU2_STM_2_ISR);
#endif
#if defined(RTU2_STM_3_ISR_USED)
ISR(RTU2_STM_3_ISR);
#endif
#if defined(RTU3_STM_0_ISR_USED)
ISR(RTU3_STM_0_ISR);
#endif
#if defined(RTU3_STM_1_ISR_USED)
ISR(RTU3_STM_1_ISR);
#endif
#if defined(RTU3_STM_2_ISR_USED)
ISR(RTU3_STM_2_ISR);
#endif
#if defined(RTU3_STM_3_ISR_USED)
ISR(RTU3_STM_3_ISR);
#endif

#if (STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS)

#if defined(CRS_STM_0_ISR_USED)
ISR(CRS_STM_0_ISR);
#endif
#if defined(RTU0_COS_STM_0_CH_0_ISR_USED)
ISR(RTU0_COS_STM_0_CH_0_ISR);
#endif
#if defined(RTU0_COS_STM_0_CH_1_ISR_USED)
ISR(RTU0_COS_STM_0_CH_1_ISR);
#endif
#if defined(RTU0_COS_STM_0_CH_2_ISR_USED)
ISR(RTU0_COS_STM_0_CH_2_ISR);
#endif
#if defined(RTU0_COS_STM_0_CH_3_ISR_USED)
ISR(RTU0_COS_STM_0_CH_3_ISR);
#endif
#if defined(RTU0_COS_STM_1_CH_0_ISR_USED)
ISR(RTU0_COS_STM_1_CH_0_ISR);
#endif
#if defined(RTU0_COS_STM_1_CH_1_ISR_USED)
ISR(RTU0_COS_STM_1_CH_1_ISR);
#endif
#if defined(RTU0_COS_STM_1_CH_2_ISR_USED)
ISR(RTU0_COS_STM_1_CH_2_ISR);
#endif
#if defined(RTU0_COS_STM_1_CH_3_ISR_USED)
ISR(RTU0_COS_STM_1_CH_3_ISR);
#endif
#if defined(RTU0_COS_STM_2_CH_0_ISR_USED)
ISR(RTU0_COS_STM_2_CH_0_ISR);
#endif
#if defined(RTU0_COS_STM_2_CH_1_ISR_USED)
ISR(RTU0_COS_STM_2_CH_1_ISR);
#endif
#if defined(RTU0_COS_STM_2_CH_2_ISR_USED)
ISR(RTU0_COS_STM_2_CH_2_ISR);
#endif
#if defined(RTU0_COS_STM_2_CH_3_ISR_USED)
ISR(RTU0_COS_STM_2_CH_3_ISR);
#endif
#if defined(RTU0_COS_STM_3_CH_0_ISR_USED)
ISR(RTU0_COS_STM_3_CH_0_ISR);
#endif
#if defined(RTU0_COS_STM_3_CH_1_ISR_USED)
ISR(RTU0_COS_STM_3_CH_1_ISR);
#endif
#if defined(RTU0_COS_STM_3_CH_2_ISR_USED)
ISR(RTU0_COS_STM_3_CH_2_ISR);
#endif
#if defined(RTU0_COS_STM_3_CH_3_ISR_USED)
ISR(RTU0_COS_STM_3_CH_3_ISR);
#endif

#if defined(RTU1_COS_STM_0_CH_0_ISR_USED)
ISR(RTU1_COS_STM_0_CH_0_ISR);
#endif
#if defined(RTU1_COS_STM_0_CH_1_ISR_USED)
ISR(RTU1_COS_STM_0_CH_1_ISR);
#endif
#if defined(RTU1_COS_STM_0_CH_2_ISR_USED)
ISR(RTU1_COS_STM_0_CH_2_ISR);
#endif
#if defined(RTU1_COS_STM_0_CH_3_ISR_USED)
ISR(RTU1_COS_STM_0_CH_3_ISR);
#endif
#if defined(RTU1_COS_STM_1_CH_0_ISR_USED)
ISR(RTU1_COS_STM_1_CH_0_ISR);
#endif
#if defined(RTU1_COS_STM_1_CH_1_ISR_USED)
ISR(RTU1_COS_STM_1_CH_1_ISR);
#endif
#if defined(RTU1_COS_STM_1_CH_2_ISR_USED)
ISR(RTU1_COS_STM_1_CH_2_ISR);
#endif
#if defined(RTU1_COS_STM_1_CH_3_ISR_USED)
ISR(RTU1_COS_STM_1_CH_3_ISR);
#endif
#if defined(RTU1_COS_STM_2_CH_0_ISR_USED)
ISR(RTU1_COS_STM_2_CH_0_ISR);
#endif
#if defined(RTU1_COS_STM_2_CH_1_ISR_USED)
ISR(RTU1_COS_STM_2_CH_1_ISR);
#endif
#if defined(RTU1_COS_STM_2_CH_2_ISR_USED)
ISR(RTU1_COS_STM_2_CH_2_ISR);
#endif
#if defined(RTU1_COS_STM_2_CH_3_ISR_USED)
ISR(RTU1_COS_STM_2_CH_3_ISR);
#endif

#if defined(RTU1_COS_STM_3_CH_0_ISR_USED)
ISR(RTU1_COS_STM_3_CH_0_ISR);
#endif
#if defined(RTU1_COS_STM_3_CH_1_ISR_USED)
ISR(RTU1_COS_STM_3_CH_1_ISR);
#endif
#if defined(RTU1_COS_STM_3_CH_2_ISR_USED)
ISR(RTU1_COS_STM_3_CH_2_ISR);
#endif
#if defined(RTU1_COS_STM_3_CH_3_ISR_USED)
ISR(RTU1_COS_STM_3_CH_3_ISR);
#endif

#if defined(RTU2_COS_STM_0_CH_0_ISR_USED)
ISR(RTU2_COS_STM_0_CH_0_ISR);
#endif
#if defined(RTU2_COS_STM_0_CH_1_ISR_USED)
ISR(RTU2_COS_STM_0_CH_1_ISR);
#endif
#if defined(RTU2_COS_STM_0_CH_2_ISR_USED)
ISR(RTU2_COS_STM_0_CH_2_ISR);
#endif
#if defined(RTU2_COS_STM_0_CH_3_ISR_USED)
ISR(RTU2_COS_STM_0_CH_3_ISR);
#endif

#if defined(RTU2_COS_STM_1_CH_0_ISR_USED)
ISR(RTU2_COS_STM_1_CH_0_ISR);
#endif
#if defined(RTU2_COS_STM_1_CH_1_ISR_USED)
ISR(RTU2_COS_STM_1_CH_1_ISR);
#endif
#if defined(RTU2_COS_STM_1_CH_2_ISR_USED)
ISR(RTU2_COS_STM_1_CH_2_ISR);
#endif
#if defined(RTU2_COS_STM_1_CH_3_ISR_USED)
ISR(RTU2_COS_STM_1_CH_3_ISR);
#endif

#if defined(RTU2_COS_STM_2_CH_0_ISR_USED)
ISR(RTU2_COS_STM_2_CH_0_ISR);
#endif
#if defined(RTU2_COS_STM_2_CH_1_ISR_USED)
ISR(RTU2_COS_STM_2_CH_1_ISR);
#endif
#if defined(RTU2_COS_STM_2_CH_2_ISR_USED)
ISR(RTU2_COS_STM_2_CH_2_ISR);
#endif
#if defined(RTU2_COS_STM_2_CH_3_ISR_USED)
ISR(RTU2_COS_STM_2_CH_3_ISR);
#endif

#if defined(RTU2_COS_STM_3_CH_0_ISR_USED)
ISR(RTU2_COS_STM_3_CH_0_ISR);
#endif
#if defined(RTU2_COS_STM_3_CH_1_ISR_USED)
ISR(RTU2_COS_STM_3_CH_1_ISR);
#endif
#if defined(RTU2_COS_STM_3_CH_2_ISR_USED)
ISR(RTU2_COS_STM_3_CH_2_ISR);
#endif
#if defined(RTU2_COS_STM_3_CH_3_ISR_USED)
ISR(RTU2_COS_STM_3_CH_3_ISR);
#endif
#if defined(RTU3_COS_STM_0_CH_0_ISR_USED)
ISR(RTU3_COS_STM_0_CH_0_ISR);
#endif
#if defined(RTU3_COS_STM_0_CH_1_ISR_USED)
ISR(RTU3_COS_STM_0_CH_1_ISR);
#endif
#if defined(RTU3_COS_STM_0_CH_2_ISR_USED)
ISR(RTU3_COS_STM_0_CH_2_ISR);
#endif
#if defined(RTU3_COS_STM_0_CH_3_ISR_USED)
ISR(RTU3_COS_STM_0_CH_3_ISR);
#endif

#if defined(RTU3_COS_STM_1_CH_0_ISR_USED)
ISR(RTU3_COS_STM_1_CH_0_ISR);
#endif
#if defined(RTU3_COS_STM_1_CH_1_ISR_USED)
ISR(RTU3_COS_STM_1_CH_1_ISR);
#endif
#if defined(RTU3_COS_STM_1_CH_2_ISR_USED)
ISR(RTU3_COS_STM_1_CH_2_ISR);
#endif
#if defined(RTU3_COS_STM_1_CH_3_ISR_USED)
ISR(RTU3_COS_STM_1_CH_3_ISR);
#endif

#if defined(RTU3_COS_STM_2_CH_0_ISR_USED)
ISR(RTU3_COS_STM_2_CH_0_ISR);
#endif
#if defined(RTU3_COS_STM_2_CH_1_ISR_USED)
ISR(RTU3_COS_STM_2_CH_1_ISR);
#endif
#if defined(RTU3_COS_STM_2_CH_2_ISR_USED)
ISR(RTU3_COS_STM_2_CH_2_ISR);
#endif
#if defined(RTU3_COS_STM_2_CH_3_ISR_USED)
ISR(RTU3_COS_STM_2_CH_3_ISR);
#endif

#if defined(RTU3_COS_STM_3_CH_0_ISR_USED)
ISR(RTU3_COS_STM_3_CH_0_ISR);
#endif
#if defined(RTU3_COS_STM_3_CH_1_ISR_USED)
ISR(RTU3_COS_STM_3_CH_1_ISR);
#endif
#if defined(RTU3_COS_STM_3_CH_2_ISR_USED)
ISR(RTU3_COS_STM_3_CH_2_ISR);
#endif
#if defined(RTU3_COS_STM_3_CH_3_ISR_USED)
ISR(RTU3_COS_STM_3_CH_3_ISR);
#endif

#endif  /* STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS */

#if (STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT)
#if defined(STM_0_ISR_USED)
ISR(STM_0_ISR);
#endif
#if defined(STM_1_ISR_USED)
ISR(STM_1_ISR);
#endif
#if defined(STM_2_ISR_USED)
ISR(STM_2_ISR);
#endif
#if defined(STM_3_ISR_USED)
ISR(STM_3_ISR);
#endif
#if defined(STM_4_ISR_USED)
ISR(STM_4_ISR);
#endif
#if defined(STM_5_ISR_USED)
ISR(STM_5_ISR);
#endif
#if defined(STM_6_ISR_USED)
ISR(STM_6_ISR);
#endif
#if defined(STM_7_ISR_USED)
ISR(STM_7_ISR);
#endif
#if defined(STM_8_ISR_USED)
ISR(STM_8_ISR);
#endif
#if defined(STM_9_ISR_USED)
ISR(STM_9_ISR);
#endif
#if defined(STM_10_ISR_USED)
ISR(STM_10_ISR);
#endif
#if defined(STM_11_ISR_USED)
ISR(STM_11_ISR);
#endif
#if defined(STM_12_ISR_USED)
ISR(STM_12_ISR);
#endif
#if defined(CE_STM_0_ISR_USED)
ISR(CE_STM_0_ISR);
#endif
#if defined(CE_STM_1_ISR_USED)
ISR(CE_STM_1_ISR);
#endif
#if defined(CE_STM_2_ISR_USED)
ISR(CE_STM_2_ISR);
#endif
#if defined(SMU_STM_0_ISR_USED)
ISR(SMU_STM_0_ISR);
#endif
#if defined(SMU_STM_2_ISR_USED)
ISR(SMU_STM_2_ISR);
#endif

#endif /* STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT */

#endif /* (STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

static inline void Stm_Ip_SetDebugMode(uint8 instance, boolean stopRun)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29();
    /* Enable DebugMode */
    if (TRUE == stopRun)
    {
        stmBase[instance]->CR |= STM_CR_FRZ_MASK;
    }
    else
    {
        stmBase[instance]->CR &= ~STM_CR_FRZ_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29();
}

static inline void Stm_Ip_TimerEnable(uint8 instance, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30();
    /* Enable TEN */
    if (TRUE == enable)
    {
        stmBase[instance]->CR |= STM_CR_TEN_MASK;
    }
    else
    {
        stmBase[instance]->CR &= ~STM_CR_TEN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30();
}

static inline uint32 Stm_Ip_GetTimerEnableBit(uint8 instance)
{
    uint32 flag = 0;
    /* Get TimerEnableBit value*/
    flag = (stmBase[instance]->CR & STM_CR_TEN_MASK) >> STM_CR_TEN_SHIFT;

    return flag;
}

static inline void Stm_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue)
{
    /* SetPrescaler value*/
    stmBase[instance]->CR = (stmBase[instance]->CR & (~STM_CR_CPS_MASK)) | STM_CR_CPS(prescalerValue);

}

/**
 * @brief
 * Function Name : Stm_Ip_SetInterruptEnableFlag
 * Description   : Set the Channel Interrupt Enable Flag (CEN): channel interrupt enable registers (CCR0 - CCR3)
 *
 * @param[in]   instance    STM hw instance number
 * @param[in]   channel     STM hw channel number
 * @param[in]   enable      enable/disable the STM Interrupt
 *
 * @return  void
 * @pre     The driver needs to be initialized.
 */
static inline void Stm_Ip_SetInterruptEnableFlag(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31();
    /* Enable ChannelEnable */
    if (TRUE == enable)
    {
        stmBase[instance]->CHANNEL[channel].CCR |= STM_CCR_CEN_MASK;
    }
    else
    {
        stmBase[instance]->CHANNEL[channel].CCR &= ~STM_CCR_CEN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31();
}

/**
 * @brief
 * Function Name : Stm_Ip_ClearInterruptStatusFlag
 * Description   : Clear the Channel Interrupt Status Flag (CIF): channel interrupt registers (CIR0 - CIR3)
 *
 * @param[in]   instance    STM hw instance number
 * @param[in]   channel     STM hw channel number
 *
 * @return  void
 * @pre     The driver needs to be initialized.
 */
static inline void Stm_Ip_ClearInterruptStatusFlag(uint8 instance, uint8 channel)
{
    /* Clear Channel Interrupt Status Flag */
    stmBase[instance]->CHANNEL[channel].CIR = STM_CIR_CIF_MASK;
}

#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )

/**
 * @brief
 * Function Name : Stm_Ip_GetInterruptEnableFlag
 * Description   : Get the state of Channel Interrupt Enable Flag (CEN): channel interrupt enable registers (CCR0 - CCR3)
 *
 * @param[in]   instance    STM hw instance number
 * @param[in]   channel     STM hw channel number
 *
 * @return  TRUE if a Channel Interrupt is enabled, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Stm_Ip_GetInterruptEnableFlag(uint8 instance, uint8 channel)
{
    return (0U != (stmBase[instance]->CHANNEL[channel].CCR & STM_CCR_CEN_MASK)) ? TRUE : FALSE;
}
#endif

static inline void Stm_Ip_SetCmpValue(uint8 instance, uint8 channel, uint32 compareValue)
{
    /* Set compareValue */
    stmBase[instance]->CHANNEL[channel].CMP = compareValue;
}

static inline uint32 Stm_Ip_GetCmpValue(uint8 instance, uint8 channel)
{
    uint32 currentCmpValue;
    /* Get compareValue */
    currentCmpValue = stmBase[instance]->CHANNEL[channel].CMP;
    return currentCmpValue;
}

static inline void Stm_Ip_SetCntValue(uint8 instance, uint32 counterValue)
{
    /* Set counterValue */
    stmBase[instance]->CNT = counterValue;
}

static inline uint32 Stm_Ip_GetCntValue(uint8 instance)
{
    uint32 currentCntValue;
    /* Get counterValue */
    currentCntValue = stmBase[instance]->CNT;
    return currentCntValue;
}

#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )
/**
* @brief   Driver routine to process all the interrupts of STM.
* @details Support function used by interrupt service routines to implement STM specific operations
*          and call the upper layer handler to implement non-hardware specific operations.
*
* @param[in]     instance     STM hw instance number
* @param[in]     channel      STM hw channel number
*
* @implements       Stm_Ip_ProcessCommonInterrupt_Activity
*/
static void Stm_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel)
{
    uint32 oldCmpValue;
    uint32 targetValue;

    boolean IsChEvEnabled;
    boolean HasChEvOccurred;

    boolean                 chInit;
    Stm_Ip_CallbackType     callback;
    uint8                   callbackParam;
    Stm_Ip_ChannelModeType  channelMode;

    if ((instance < GPT_STM_INSTANCE_COUNT) && (channel < STM_CHANNEL_COUNT))
    {
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11();
        {
            /* check if channel event is enabled */
            IsChEvEnabled = Stm_Ip_GetInterruptEnableFlag(instance, channel);

            /* check if channel event has occurred */
            HasChEvOccurred = Stm_Ip_GetInterruptStatusFlag(instance, channel);

            if (IsChEvEnabled && HasChEvOccurred)
            {
                /* Clear pending interrupts */
                Stm_Ip_ClearInterruptStatusFlag(instance, channel);
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11();

        /* Check for spurious interrupts */
        if (IsChEvEnabled && HasChEvOccurred)
        {
            chInit          = Stm_Ip_u32ChState[instance][channel].chInit;
            callback        = Stm_Ip_u32ChState[instance][channel].callback;
            channelMode     = Stm_Ip_u32ChState[instance][channel].channelMode;
            callbackParam   = Stm_Ip_u32ChState[instance][channel].callbackParam;
            
#if (STM_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
            if(0x0U != Stm_Ip_u32NextTargetValue[instance][channel])
            {
                Stm_Ip_u32TargetValue[instance][channel] = Stm_Ip_u32NextTargetValue[instance][channel];
                Stm_Ip_u32NextTargetValue[instance][channel] = 0x0U;
            }
#endif
            /* Check if channel mode is ONE-SHOT */
            if(STM_IP_CH_MODE_ONESHOT == channelMode)
            {
                Stm_Ip_DisableChannel(instance, channel);
            }
            else
            {
                /*Get current CMP value*/
                oldCmpValue = Stm_Ip_GetCmpValue(instance, channel);
                /*Get current target value*/
                targetValue = Stm_Ip_u32TargetValue[instance][channel];
                /*Set new CMP value*/
                Stm_Ip_SetCmpValue(instance, channel, (oldCmpValue + targetValue));
            }

            /* Call GPT upper layer handler */
            if ((TRUE == chInit) && (NULL_PTR != callback))
            {
                callback(callbackParam);
            }
        }
    }
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (defined(MCAL_STM_REG_PROT_AVAILABLE) && (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief        Enables STM registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the STM IP allowing STM registers writing in User Mode
 *
 * @param[in]    StmBaseAddr
 *
 * @return       none
 *
 * @pre          Should be executed in supervisor mode
 */
void Stm_Ip_SetUserAccessAllowed(uint32 StmBaseAddr)
{
    SET_USER_ACCESS_ALLOWED(StmBaseAddr, STM_PROT_MEM_U32);
}
#endif


/**
* @brief         Function Name : Stm_Ip_Init
* @details       Initializes the STM instance. This functions is called for each STM hw Instance and:
*                    - sets the counter value
*                    - configures the freeze mode
*                    - sets the prescaler value
*                    - enables the STM counter
*
* @param[in]     instance     STM hw instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Stm_Ip_Init_Activity
*/
void Stm_Ip_Init(uint8 instance, const Stm_Ip_InstanceConfigType *configPtr)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != configPtr);
#endif

    /* Enable register access from user mode, if enabled from configuration file */
    Call_Stm_Ip_SetUserAccessAllowed((uint32)stmBase[instance]);
    Stm_Ip_SetCntValue(instance, 0U);
    Stm_Ip_SetDebugMode(instance, configPtr->stopInDebugMode);
    Stm_Ip_SetPrescaler(instance, configPtr->clockPrescaler);
    Stm_Ip_TimerEnable(instance, TRUE);
#if (STM_IP_SET_CLOCK_MODE == STD_ON)
    Stm_Ip_u32InstanceState[instance].clockPrescaler = configPtr->clockPrescaler;
    Stm_Ip_u32InstanceState[instance].clockAlternatePrescaler = configPtr->clockAlternatePrescaler;
#endif
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_InitChannel
* @details       Initializes the STM channels. This functions is called for each STM hw channel and:
*                    - disables hw channel
*                    - clears interrupt clear
*                    - sets compare value to 0
*                    - initializes the state sructure for common process interrupt
*
* @param[in]     instance     STM hw instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Stm_Ip_InitChannel_Activity
*/
void Stm_Ip_InitChannel(uint8 instance, const Stm_Ip_ChannelConfigType *configPtr)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != configPtr);
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > configPtr->hwChannel);
#endif

    /* Disable Channel Interrupt */
    Stm_Ip_SetInterruptEnableFlag(instance, configPtr->hwChannel, FALSE);
    /* Clear Channel Interrupt Status Flag */
    Stm_Ip_ClearInterruptStatusFlag(instance, configPtr->hwChannel);
    /*Set compare value to 0*/
    Stm_Ip_SetCmpValue(instance, configPtr->hwChannel, 0U);
#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].chInit = TRUE;
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].callback = configPtr->callback;
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].callbackParam = configPtr->callbackParam;
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].channelMode = configPtr->channelMode;
#endif
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_Deinit
* @details      De-Initializes the STM module. This functions is called for each STM hw instance and:
*                    - resets all channels to default
*                    - sets to default prescaler bits
*                    - disables the STM counter
*
* @param[in]     instance     STM hw instance number
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
* @implements    Stm_Ip_Deinit_Activity
*/
void Stm_Ip_Deinit(uint8 instance)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
#endif

    uint8 channelIndex;

    /* Reset all channels to default */
    for (channelIndex = 0; channelIndex < STM_CHANNEL_COUNT; channelIndex++)
    {
        /* Disable Channel Interrupt */
        Stm_Ip_SetInterruptEnableFlag(instance, channelIndex, FALSE);
        /* Clear Channel Interrupt Status Flag */
        Stm_Ip_ClearInterruptStatusFlag(instance, channelIndex);
        /* Sets compare value to 0 */
        Stm_Ip_SetCmpValue(instance, channelIndex, 0x0U);
    }

    /* Set to default prescaler bits */
    Stm_Ip_SetPrescaler(instance, 0x0U);

    /* Disable counter */
    Stm_Ip_TimerEnable(instance, FALSE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_StartCounting
* @details      This function is called for starting the Stm timer channel
*                    - reads the current counter register value and sets the compare register to the sum of
*                      counter register value plus the timeout value
*                    - enables the STM channel
*
* @param[in]     instance        STM hw instance number
* @param[in]     channel         Stm channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_StartCounting_Activity
*/
void Stm_Ip_StartCounting(uint8 instance, uint8 channel, uint32 compareValue)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    uint32 currentCntValue;

    /* enter critical section */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39();
    {
        currentCntValue = Stm_Ip_GetCntValue(instance);
        Stm_Ip_SetCmpValue(instance, channel, (currentCntValue + compareValue));
    }
    /* exit critical section */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39();

    Stm_Ip_u32TargetValue[instance][channel] = compareValue;

    /* Enable Channel Interrupt */
    Stm_Ip_SetInterruptEnableFlag(instance, channel, TRUE);
}
/*================================================================================================*/
#if STM_IP_ABSOLUTE_COUNTING_API  == STD_ON
/**
* @brief        Function Name : Stm_Ip_StartCountingAbsolute
* @details      This function is called for starting the Stm timer channel
*                    - sets the compare value without adding the current counter value to the timeout value
*                    - enables the STM channel
*
* @param[in]     instance        STM hw instance number
* @param[in]     channel         Stm channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_StartCountingAbsolute_Activity
*/
void Stm_Ip_StartCountingAbsolute(uint8 instance, uint8 channel, uint32 compareValue)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    Stm_Ip_u32TargetValue[instance][channel] = 0U;
    Stm_Ip_SetCmpValue(instance, channel, compareValue);
    /* Enable Channel Interrupt */
    Stm_Ip_SetInterruptEnableFlag(instance, channel, TRUE);
}
#endif
/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_StartTimer
* @details       This function is called for setting a new start counter value and enables the STM counter:
*                   - sets the new counter value
*                   - enables the STM counter
*
* @param[in]     instance       Stm hw instance
* @param[in]     startValue     counter value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_StartTimer_Activity
*/
void Stm_Ip_StartTimer(uint8 instance, uint32 startValue)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
#endif

    Stm_Ip_SetCntValue(instance, startValue);
    Stm_Ip_TimerEnable(instance, TRUE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_StopTimer
* @details      Gpt driver function for stopping the Stm counter.
*                   - disables the STM counter
*
* @param[in]     instance       Stm hw instance
* @return        void
* @pre           The driver needs to be initialized. This function is called for stoping the STM timer channel.
* @implements    Stm_Ip_StopTimer_Activity
*/
void Stm_Ip_StopTimer(uint8 instance)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
#endif

    Stm_Ip_TimerEnable(instance, FALSE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_EnableChannel
* @details      Enables the channel selected.
*
* @param[in]     instance       Stm hw instance
* @param[in]     channel        Stm hw channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Stm_Ip_EnableChannel_Activity
*/
void Stm_Ip_EnableChannel(uint8 instance, uint8 channel)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    Stm_Ip_ClearInterruptStatusFlag(instance, channel);
    Stm_Ip_SetInterruptEnableFlag(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_DisableChannel
* @details       Disables the channel selected.
*
* @param[in]     instance       Stm hw instance
* @param[in]     channel        Stm hw channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Stm_Ip_DisableChannel_Activity
*/
void Stm_Ip_DisableChannel(uint8 instance, uint8 channel)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    Stm_Ip_SetInterruptEnableFlag(instance, channel, FALSE);
    Stm_Ip_ClearInterruptStatusFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_GetCounterValue
* @details       Gets the counter value.
*
* @param[in]     instance                  Stm hw instance
*
* @return        currentCounterValue       current counter value
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_GetCounterValue_Activity
*/
uint32 Stm_Ip_GetCounterValue(uint8 instance)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
#endif

    uint32 currentCounterValue = 0;

    currentCounterValue = Stm_Ip_GetCntValue(instance);

    return currentCounterValue;
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_GetCompareValue
* @details       Gets the compare value for selected channel
*
* @param[in]     instance                  Stm hw instance
* @param[in]     channel                   Stm hw channel
*
* @return        currentCompareValue       compare value for selected channel
* @pre           The driver needs to be initialized.
* @implements    Stm_Ip_GetCompareValue_Activity
*/
uint32 Stm_Ip_GetCompareValue(uint8 instance,  uint8 channel)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    uint32 currentCompareValue = 0;

    currentCompareValue = Stm_Ip_GetCmpValue(instance, channel);

    return currentCompareValue;
}

#if (STM_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the Stm compare register value.
* @details This function:
*          - Write next timeout to local variable
*
* @param[in]     instance        Stm hw instance
* @param[in]     channel         Channel
* @param[in]     value           Channel timeout value
* @return        void
* @pre           The driver needs to be initialized.
* @implements       Stm_Ip_ChangeNextTimeoutValue_Activity
*/
void Stm_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif
#if (   defined(STM_0_ISR_USED) || defined(STM_1_ISR_USED) || defined(STM_2_ISR_USED)  || defined(STM_3_ISR_USED)  || \
        defined(STM_4_ISR_USED) || defined(STM_5_ISR_USED) || defined(STM_6_ISR_USED)  || defined(STM_7_ISR_USED)  || \
        defined(STM_8_ISR_USED) || defined(STM_9_ISR_USED) || defined(STM_10_ISR_USED) || defined(STM_11_ISR_USED) || \
        defined(STM_12_ISR_USED)|| defined(SMU_STM_0_ISR_USED) || defined(SMU_STM_2_ISR_USED) || \
        defined(CE_STM_0_ISR_USED) || defined(CE_STM_1_ISR_USED) || defined(CE_STM_2_ISR_USED) || \
        defined(RTU0_STM_0_ISR_USED) || defined(RTU0_STM_1_ISR_USED) || defined(RTU0_STM_2_ISR_USED) || defined(RTU0_STM_3_ISR_USED) || \
        defined(RTU1_STM_0_ISR_USED) || defined(RTU1_STM_1_ISR_USED) || defined(RTU1_STM_2_ISR_USED) || defined(RTU1_STM_3_ISR_USED) || \
        defined(RTU2_STM_0_ISR_USED) || defined(RTU2_STM_1_ISR_USED) || defined(RTU2_STM_2_ISR_USED) || defined(RTU2_STM_3_ISR_USED) || \
        defined(RTU3_STM_0_ISR_USED) || defined(RTU3_STM_1_ISR_USED) || defined(RTU3_STM_2_ISR_USED) || defined(RTU3_STM_3_ISR_USED) || \
        defined(CRS_STM_0_ISR_USED) || \
        defined(RTU0_COS_STM_0_CH_0_ISR_USED) || defined(RTU0_COS_STM_0_CH_1_ISR_USED) || defined(RTU0_COS_STM_0_CH_2_ISR_USED) || defined(RTU0_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_1_CH_0_ISR_USED) || defined(RTU0_COS_STM_1_CH_1_ISR_USED) || defined(RTU0_COS_STM_1_CH_2_ISR_USED) || defined(RTU0_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_2_CH_0_ISR_USED) || defined(RTU0_COS_STM_2_CH_1_ISR_USED) || defined(RTU0_COS_STM_2_CH_2_ISR_USED) || defined(RTU0_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU0_COS_STM_3_CH_0_ISR_USED) || defined(RTU0_COS_STM_3_CH_1_ISR_USED) || defined(RTU0_COS_STM_3_CH_2_ISR_USED) || defined(RTU0_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_0_CH_0_ISR_USED) || defined(RTU1_COS_STM_0_CH_1_ISR_USED) || defined(RTU1_COS_STM_0_CH_2_ISR_USED) || defined(RTU1_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_1_CH_0_ISR_USED) || defined(RTU1_COS_STM_1_CH_1_ISR_USED) || defined(RTU1_COS_STM_1_CH_2_ISR_USED) || defined(RTU1_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_2_CH_0_ISR_USED) || defined(RTU1_COS_STM_2_CH_1_ISR_USED) || defined(RTU1_COS_STM_2_CH_2_ISR_USED) || defined(RTU1_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU1_COS_STM_3_CH_0_ISR_USED) || defined(RTU1_COS_STM_3_CH_1_ISR_USED) || defined(RTU1_COS_STM_3_CH_2_ISR_USED) || defined(RTU1_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_0_CH_0_ISR_USED) || defined(RTU2_COS_STM_0_CH_1_ISR_USED) || defined(RTU2_COS_STM_0_CH_2_ISR_USED) || defined(RTU2_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_1_CH_0_ISR_USED) || defined(RTU2_COS_STM_1_CH_1_ISR_USED) || defined(RTU2_COS_STM_1_CH_2_ISR_USED) || defined(RTU2_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_2_CH_0_ISR_USED) || defined(RTU2_COS_STM_2_CH_1_ISR_USED) || defined(RTU2_COS_STM_2_CH_2_ISR_USED) || defined(RTU2_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU2_COS_STM_3_CH_0_ISR_USED) || defined(RTU2_COS_STM_3_CH_1_ISR_USED) || defined(RTU2_COS_STM_3_CH_2_ISR_USED) || defined(RTU2_COS_STM_3_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_0_CH_0_ISR_USED) || defined(RTU3_COS_STM_0_CH_1_ISR_USED) || defined(RTU3_COS_STM_0_CH_2_ISR_USED) || defined(RTU3_COS_STM_0_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_1_CH_0_ISR_USED) || defined(RTU3_COS_STM_1_CH_1_ISR_USED) || defined(RTU3_COS_STM_1_CH_2_ISR_USED) || defined(RTU3_COS_STM_1_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_2_CH_0_ISR_USED) || defined(RTU3_COS_STM_2_CH_1_ISR_USED) || defined(RTU3_COS_STM_2_CH_2_ISR_USED) || defined(RTU3_COS_STM_2_CH_3_ISR_USED) || \
        defined(RTU3_COS_STM_3_CH_0_ISR_USED) || defined(RTU3_COS_STM_3_CH_1_ISR_USED) || defined(RTU3_COS_STM_3_CH_2_ISR_USED) || defined(RTU3_COS_STM_3_CH_3_ISR_USED) )

    /* Update the target time value to be used on next cycle */
    Stm_Ip_u32NextTargetValue[instance][channel] = value;
#endif
}
#endif

#if (STM_IP_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the STM prescaler value.
* @details    This function sets the STM prescaler based on the input mode.
*
* @param[in]  instance     Stm hw instance
* @param[in]  clockMode    STM_IP_CLOCKMODE_NORMAL or STM_IP_CLOCKMODE_ALTERNATE
*
* @return     void
* @pre        The driver needs to be initialized. On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
* @implements Stm_Ip_SetClockMode_Activity
*/
void Stm_Ip_SetClockMode(uint8 instance, Stm_Ip_ClockModeType clockMode)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(GPT_STM_INSTANCE_COUNT > instance);
#endif

    if(STM_IP_CLOCKMODE_NORMAL == clockMode)
    {
        Stm_Ip_SetPrescaler(instance, Stm_Ip_u32InstanceState[instance].clockPrescaler);
    }
    else
    {
        Stm_Ip_SetPrescaler(instance, Stm_Ip_u32InstanceState[instance].clockAlternatePrescaler);
    }

}
#endif

/*================================================================================================*/
/**
* @brief      This function sets the STM prescaler, freeze bit and enables counter
* @details    This function start counting with predefined values(like a free running timer)
*
* @param[in]  instance        Stm hw instance
* @param[in]  prescaler       Prescaler value
* @param[in]  freezeEnable    Freeze value
* @return     void
* @pre        The driver needs to be initialized
* @implements Stm_Ip_PredefCounting_Activity
*/
void Stm_Ip_PredefCounting(uint8 instance, uint8 prescaler, boolean freezeEnable)
{
    /* Enable register access from user mode, if enabled from configuration file */
    Call_Stm_Ip_SetUserAccessAllowed((uint32)stmBase[instance]);
    /* check if the timer is not enabled - TEN bit*/
    if(1U != Stm_Ip_GetTimerEnableBit(instance))
    {
        /* clear counter */
        Stm_Ip_SetCntValue(instance, 0x0000U);
        /* Set prescaler for stm timer */
        Stm_Ip_SetPrescaler(instance, prescaler);
        if (TRUE == freezeEnable)
        {
            Stm_Ip_SetDebugMode(instance, TRUE);
        }
        else
        {
            Stm_Ip_SetDebugMode(instance, FALSE);
        }
        /*Enable counting*/
        Stm_Ip_TimerEnable(instance, TRUE);
    }
}

#if ((STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS))

#if defined(RTU0_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU0_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU0_STM_0_ISR){
    uint8 channel;
#if defined(RTU0_STM_0_IP_EXISTS)
    uint8 instance = RTU0_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU0_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU0_STM_1_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU0_STM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU0_STM_1_ISR){
    uint8 channel;
#if defined(RTU0_STM_1_IP_EXISTS)
    uint8 instance = RTU0_STM_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU0_STM_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU0_STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU0_STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU0_STM_2_ISR){
    uint8 channel;
#if defined(RTU0_STM_2_IP_EXISTS)
    uint8 instance = RTU0_STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU0_STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU0_STM_3_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU0_STM_3 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU0_STM_3_ISR){
    uint8 channel;
#if defined(RTU0_STM_3_IP_EXISTS)
    uint8 instance = RTU0_STM_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU0_STM_3_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU1_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU1_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU1_STM_0_ISR){
    uint8 channel;
#if defined(RTU1_STM_0_IP_EXISTS)
    uint8 instance = RTU1_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU1_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU1_STM_1_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU1_STM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU1_STM_1_ISR){
    uint8 channel;
#if defined(RTU1_STM_1_IP_EXISTS)
    uint8 instance = RTU1_STM_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU1_STM_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU1_STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU1_STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU1_STM_2_ISR){
    uint8 channel;
#if defined(RTU1_STM_2_IP_EXISTS)
    uint8 instance = RTU1_STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU1_STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU1_STM_3_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU1_STM_3 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU1_STM_3_ISR){
    uint8 channel;
#if defined(RTU1_STM_3_IP_EXISTS)
    uint8 instance = RTU1_STM_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU1_STM_3_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU2_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU2_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU2_STM_0_ISR){
    uint8 channel;
#if defined(RTU2_STM_0_IP_EXISTS)
    uint8 instance = RTU2_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU2_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU2_STM_1_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU2_STM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU2_STM_1_ISR){
    uint8 channel;
#if defined(RTU2_STM_1_IP_EXISTS)
    uint8 instance = RTU2_STM_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU2_STM_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU2_STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU2_STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU2_STM_2_ISR){
    uint8 channel;
#if defined(RTU2_STM_2_IP_EXISTS)
    uint8 instance = RTU2_STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU2_STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU2_STM_3_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU2_STM_3 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU2_STM_3_ISR){
    uint8 channel;
#if defined(RTU2_STM_3_IP_EXISTS)
    uint8 instance = RTU2_STM_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU2_STM_3_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU3_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU3_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU3_STM_0_ISR){
    uint8 channel;
#if defined(RTU3_STM_0_IP_EXISTS)
    uint8 instance = RTU3_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU3_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU3_STM_1_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU3_STM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU3_STM_1_ISR){
    uint8 channel;
#if defined(RTU3_STM_1_IP_EXISTS)
    uint8 instance = RTU3_STM_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU3_STM_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU3_STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU3_STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU3_STM_2_ISR){
    uint8 channel;
#if defined(RTU3_STM_2_IP_EXISTS)
    uint8 instance = RTU3_STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU3_STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU3_STM_3_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common RTU3_STM_3 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(RTU3_STM_3_ISR){
    uint8 channel;
#if defined(RTU3_STM_3_IP_EXISTS)
    uint8 instance = RTU3_STM_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < RTU3_STM_3_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if (STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS)

#if defined(CRS_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common CRS_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(CRS_STM_0_ISR){
    uint8 channel;
#if defined(CRS_STM_0_IP_EXISTS)
    uint8 instance = CRS_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < CRS_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(RTU0_COS_STM_0_CH_0_ISR_USED)
ISR(RTU0_COS_STM_0_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_0_CH_1_ISR_USED)
ISR(RTU0_COS_STM_0_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_0_CH_2_ISR_USED)
ISR(RTU0_COS_STM_0_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_0_CH_3_ISR_USED)
ISR(RTU0_COS_STM_0_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_1_CH_0_ISR_USED)
ISR(RTU0_COS_STM_1_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_1_CH_1_ISR_USED)
ISR(RTU0_COS_STM_1_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_1_CH_2_ISR_USED)
ISR(RTU0_COS_STM_1_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_1_CH_3_ISR_USED)
ISR(RTU0_COS_STM_1_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_2_CH_0_ISR_USED)
ISR(RTU0_COS_STM_2_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_2_CH_1_ISR_USED)
ISR(RTU0_COS_STM_2_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_2_CH_2_ISR_USED)
ISR(RTU0_COS_STM_2_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_2_CH_3_ISR_USED)
ISR(RTU0_COS_STM_2_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_3_CH_0_ISR_USED)
ISR(RTU0_COS_STM_3_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_3_CH_1_ISR_USED)
ISR(RTU0_COS_STM_3_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_3_CH_2_ISR_USED)
ISR(RTU0_COS_STM_3_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU0_COS_STM_3_CH_3_ISR_USED)
ISR(RTU0_COS_STM_3_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU0_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_0_CH_0_ISR_USED)
ISR(RTU1_COS_STM_0_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_0_CH_1_ISR_USED)
ISR(RTU1_COS_STM_0_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_0_CH_2_ISR_USED)
ISR(RTU1_COS_STM_0_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_0_CH_3_ISR_USED)
ISR(RTU1_COS_STM_0_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_1_CH_0_ISR_USED)
ISR(RTU1_COS_STM_1_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_1_CH_1_ISR_USED)
ISR(RTU1_COS_STM_1_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_1_CH_2_ISR_USED)
ISR(RTU1_COS_STM_1_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_1_CH_3_ISR_USED)
ISR(RTU1_COS_STM_1_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_2_CH_0_ISR_USED)
ISR(RTU1_COS_STM_2_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_2_CH_1_ISR_USED)
ISR(RTU1_COS_STM_2_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_2_CH_2_ISR_USED)
ISR(RTU1_COS_STM_2_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_2_CH_3_ISR_USED)
ISR(RTU1_COS_STM_2_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_3_CH_0_ISR_USED)
ISR(RTU1_COS_STM_3_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_3_CH_1_ISR_USED)
ISR(RTU1_COS_STM_3_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_3_CH_2_ISR_USED)
ISR(RTU1_COS_STM_3_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU1_COS_STM_3_CH_3_ISR_USED)
ISR(RTU1_COS_STM_3_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU1_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_0_CH_0_ISR_USED)
ISR(RTU2_COS_STM_0_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_0_CH_1_ISR_USED)
ISR(RTU2_COS_STM_0_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_0_CH_2_ISR_USED)
ISR(RTU2_COS_STM_0_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_0_CH_3_ISR_USED)
ISR(RTU2_COS_STM_0_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_1_CH_0_ISR_USED)
ISR(RTU2_COS_STM_1_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_1_CH_1_ISR_USED)
ISR(RTU2_COS_STM_1_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_1_CH_2_ISR_USED)
ISR(RTU2_COS_STM_1_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_1_CH_3_ISR_USED)
ISR(RTU2_COS_STM_1_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_2_CH_0_ISR_USED)
ISR(RTU2_COS_STM_2_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_2_CH_1_ISR_USED)
ISR(RTU2_COS_STM_2_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_2_CH_2_ISR_USED)
ISR(RTU2_COS_STM_2_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_2_CH_3_ISR_USED)
ISR(RTU2_COS_STM_2_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_3_CH_0_ISR_USED)
ISR(RTU2_COS_STM_3_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_3_CH_1_ISR_USED)
ISR(RTU2_COS_STM_3_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_3_CH_2_ISR_USED)
ISR(RTU2_COS_STM_3_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU2_COS_STM_3_CH_3_ISR_USED)
ISR(RTU2_COS_STM_3_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU2_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_0_CH_0_ISR_USED)
ISR(RTU3_COS_STM_0_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_0_CH_1_ISR_USED)
ISR(RTU3_COS_STM_0_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_0_CH_2_ISR_USED)
ISR(RTU3_COS_STM_0_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_0_CH_3_ISR_USED)
ISR(RTU3_COS_STM_0_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_0_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_1_CH_0_ISR_USED)
ISR(RTU3_COS_STM_1_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_1_CH_1_ISR_USED)
ISR(RTU3_COS_STM_1_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_1_CH_2_ISR_USED)
ISR(RTU3_COS_STM_1_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_1_CH_3_ISR_USED)
ISR(RTU3_COS_STM_1_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_1_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_2_CH_0_ISR_USED)
ISR(RTU3_COS_STM_2_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_2_CH_1_ISR_USED)
ISR(RTU3_COS_STM_2_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_2_CH_2_ISR_USED)
ISR(RTU3_COS_STM_2_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_2_CH_3_ISR_USED)
ISR(RTU3_COS_STM_2_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_2_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_3_CH_0_ISR_USED)
ISR(RTU3_COS_STM_3_CH_0_ISR){
    uint8 channel = 0U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_3_CH_1_ISR_USED)
ISR(RTU3_COS_STM_3_CH_1_ISR){
    uint8 channel = 1U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_3_CH_2_ISR_USED)
ISR(RTU3_COS_STM_3_CH_2_ISR){
    uint8 channel = 2U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif
#if defined(RTU3_COS_STM_3_CH_3_ISR_USED)
ISR(RTU3_COS_STM_3_CH_3_ISR){
    uint8 channel = 3U;
    Stm_Ip_ProcessCommonInterrupt(RTU3_COS_STM_3_IP_INSTANCE_NUMBER, channel);
}
#endif

#endif  /* STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS */

/*================================================================================================*/
#if (STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT)
#if defined(STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_0_ISR){
    uint8 channel;
#if defined(STM_0_IP_EXISTS)
    uint8 instance = STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_1_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_1_ISR){
    uint8 channel;
#if defined(STM_1_IP_EXISTS)
    uint8 instance = STM_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_2_ISR){
    uint8 channel;
#if defined(STM_2_IP_EXISTS)
    uint8 instance = STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_3_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_3 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_3_ISR){
    uint8 channel;
#if defined(STM_3_IP_EXISTS)
    uint8 instance = STM_3_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_3_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif
#if defined(STM_4_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_4 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_4_ISR){
    uint8 channel;
#if defined(STM_4_IP_EXISTS)
    uint8 instance = STM_4_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_4_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_5_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_5 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_5_ISR){
    uint8 channel;
#if defined(STM_5_IP_EXISTS)
    uint8 instance = STM_5_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_5_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_6_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_6 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_6_ISR){
    uint8 channel;
#if defined(STM_6_IP_EXISTS)
    uint8 instance = STM_6_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_6_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_7_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_7 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_7_ISR){
    uint8 channel;
#if defined(STM_7_IP_EXISTS)
    uint8 instance = STM_7_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_7_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif
#if defined(STM_8_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_8 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_8_ISR){
    uint8 channel;
#if defined(STM_8_IP_EXISTS)
    uint8 instance = STM_8_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_8_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_9_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_9 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_9_ISR){
    uint8 channel;
#if defined(STM_9_IP_EXISTS)
    uint8 instance = STM_9_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_9_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_10_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_10 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_10_ISR){
    uint8 channel;
#if defined(STM_10_IP_EXISTS)
    uint8 instance = STM_10_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_10_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_11_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_11 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_11_ISR){
    uint8 channel;
#if defined(STM_11_IP_EXISTS)
    uint8 instance = STM_11_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_11_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(STM_12_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
* @param[in] none
* @return   none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_12_ISR){
    uint8 channel;
#if defined(STM_12_IP_EXISTS)
    uint8 instance = STM_12_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < STM_12_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif
/*================================================================================================*/
#if defined(CE_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common CE_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(CE_STM_0_ISR){
    uint8 channel;
#if defined(CE_STM_0_IP_EXISTS)
    uint8 instance = CE_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < CE_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(CE_STM_1_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common CE_STM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(CE_STM_1_ISR){
    uint8 channel;
#if defined(CE_STM_1_IP_EXISTS)
    uint8 instance = CE_STM_1_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < CE_STM_1_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(CE_STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common CE_STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(CE_STM_2_ISR){
    uint8 channel;
#if defined(CE_STM_2_IP_EXISTS)
    uint8 instance = CE_STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < CE_STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(SMU_STM_0_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common SMU_STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(SMU_STM_0_ISR){
    uint8 channel;
#if defined(SMU_STM_0_IP_EXISTS)
    uint8 instance = SMU_STM_0_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < SMU_STM_0_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#if defined(SMU_STM_2_ISR_USED)
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common SMU_STM_2 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(SMU_STM_2_ISR){
    uint8 channel;
#if defined(SMU_STM_2_IP_EXISTS)
    uint8 instance = SMU_STM_2_IP_INSTANCE_NUMBER;
#else
    #error "undefined STM instance number"
#endif
    for (channel = 0U; channel < SMU_STM_2_IP_CHANNELS_NUMBER; ++channel)
    {
        Stm_Ip_ProcessCommonInterrupt(instance, channel);
    }
}
#endif

#endif /* STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT */

#endif /* (STD_ON == STM_GPT_IP_MODULE_SINGLE_INTERRUPT) || (STD_ON == STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS) */

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* STM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif  /*STM_IP_C*/
/** @} */

