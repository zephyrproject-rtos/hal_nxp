/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup osif_drv
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
#include "OsIf.h"
#include "OsIf_Cfg.h"
#include "OsIf_Cfg_TypesDef.h"
#include "OsIf_Timer_System.h"

#if (OSIF_USE_SYSTEM_TIMER == STD_ON)

#if defined(USING_OS_AUTOSAROS)
#include "Os.h"
#elif defined(USING_OS_FREERTOS)
#include "FreeRTOSConfig.h"
#elif defined(USING_OS_ZEPHYR)
#include <zephyr/kernel.h>
#else
    /* Baremetal, make sure USING_OS_BAREMETAL is defined */
#ifndef USING_OS_BAREMETAL
#define USING_OS_BAREMETAL
#endif /* ifndef USING_OS_BAREMETAL */
#endif /* defined(USING_OS_AUTOSAROS) */

/* Timer specific includes to define:
 - OsIf_Timer_System_Internal_Init
 - OsIf_Timer_System_Internal_GetCounter
 - OsIf_Timer_System_Internal_GetElapsed
 */
#if defined(OSIF_USE_SYSTICK)
#if (OSIF_USE_SYSTICK == STD_ON)
#include "OsIf_Timer_System_Internal_Systick.h"
#endif /* OSIF_USE_SYSTICK == STD_ON */
#endif /* defined(OSIF_USE_SYSTICK) */

#if defined(OSIF_USE_GENERICTIMER)
#if (OSIF_USE_GENERICTIMER == STD_ON)
#include "OsIf_Timer_System_Internal_GenericTimer.h"
#endif /* OSIF_USE_GENERICTIMER == STD_ON */
#endif /* defined(OSIF_USE_GENERICTIMER) */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_TIMER_SYSTEM_VENDOR_ID_C                    43
#define OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C     4
#define OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C     7
#define OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C  0
#define OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C             0
#define OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C             9
#define OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against OsIf.h */
#if (OSIF_TIMER_SYSTEM_VENDOR_ID_C != OSIF_VENDOR_ID)
    #error "OsIf_Timer_System.c and OsIf.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C != OSIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf.h are different"
#endif
#if ((OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C != OSIF_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C != OSIF_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C != OSIF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System.c and OsIf.h are different"
#endif

/* Checks against OsIf_Cfg.h */
#if (OSIF_TIMER_SYSTEM_VENDOR_ID_C != OSIF_CFG_VENDOR_ID)
    #error "OsIf_Timer_System.c and OsIf_Cfg.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf_Cfg.h are different"
#endif
#if ((OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System.c and OsIf_Cfg.h are different"
#endif

/* Checks against OsIf_Cfg_TypesDef.h */
#if (OSIF_TIMER_SYSTEM_VENDOR_ID_C != OSIF_CFG_TYPESDEF_VENDOR_ID)
    #error "OsIf_Timer_System.c and OsIf_Cfg_TypesDef.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C    != OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C    != OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C != OSIF_CFG_TYPESDEF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf_Cfg_TypesDef.h are different"
#endif
#if ((OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C != OSIF_CFG_TYPESDEF_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C != OSIF_CFG_TYPESDEF_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C != OSIF_CFG_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System.c and OsIf_Cfg_TypesDef.h are different"
#endif

/* Checks against OsIf_Timer_System.h */
#if (OSIF_TIMER_SYSTEM_VENDOR_ID_C != OSIF_TIMER_SYSTEM_VENDOR_ID)
    #error "OsIf_Timer_System.c and OsIf_Timer_System.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf_Timer_System.h are different"
#endif
#if ((OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C != OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C != OSIF_TIMER_SYSTEM_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C != OSIF_TIMER_SYSTEM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System.c and OsIf_Timer_System.h are different"
#endif

#if defined(OSIF_USE_SYSTICK)
#if (OSIF_USE_SYSTICK == STD_ON)
/* Checks against OsIf_Timer_System_Internal_Systick.h */
#if (OSIF_TIMER_SYSTEM_VENDOR_ID_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_VENDOR_ID)
    #error "OsIf_Timer_System.c and OsIf_Timer_System_Internal_Systick.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf_Timer_System_Internal_Systick.h are different"
#endif
#if ((OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System.c and OsIf_Timer_System_Internal_Systick.h are different"
#endif
#endif /* OSIF_USE_SYSTICK == STD_ON */
#endif /* defined(OSIF_USE_SYSTICK) */

#if defined(OSIF_USE_GENERICTIMER)
#if OSIF_USE_GENERICTIMER == STD_ON
/* Checks against OsIf_Timer_System_Internal_GenericTimer.h */
#if (OSIF_TIMER_SYSTEM_VENDOR_ID_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_VENDOR_ID)
    #error "OsIf_Timer_System.c and OsIf_Timer_System_Internal_GenericTimer.h have different vendor ids"
#endif
#if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf_Timer_System_Internal_GenericTimer.h are different"
#endif
#if ((OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_MINOR_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_SW_PATCH_VERSION_C != OSIF_TIMER_SYS_INTER_GENERICTIMER_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System.c and OsIf_Timer_System_Internal_GenericTimer.h are different"
#endif
#endif /* OSIF_USE_GENERICTIMER == STD_ON */
#endif /* defined(OSIF_USE_GENERICTIMER) */

#if defined(USING_OS_AUTOSAROS)
/* Checks against Os.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION_C != OS_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION_C != OS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Timer_System.c and Os.h are different"
    #endif
#endif
#endif /* defined(USING_OS_AUTOSAROS) */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == OSIF_ENABLE_USER_MODE_SUPPORT)
    #define Trusted_OsIf_Timer_System_Internal_Init(Freq)               OsIf_Trusted_Call1param(OsIf_Timer_System_Internal_Init, (Freq))
    #define Trusted_OsIf_Timer_System_Internal_GetCounter()             OsIf_Trusted_Call_Return(OsIf_Timer_System_Internal_GetCounter)
    #define Trusted_OsIf_Timer_System_Internal_GetElapsed(CurrentRef)   OsIf_Trusted_Call_Return1param(OsIf_Timer_System_Internal_GetElapsed, (CurrentRef))
    #define Trusted_k_cycle_get_32()                                    OsIf_Trusted_Call_Return(k_cycle_get_32)
#else
    #define Trusted_OsIf_Timer_System_Internal_Init(Freq)               OsIf_Timer_System_Internal_Init(Freq)
    #define Trusted_OsIf_Timer_System_Internal_GetCounter()             OsIf_Timer_System_Internal_GetCounter()
    #define Trusted_OsIf_Timer_System_Internal_GetElapsed(CurrentRef)   OsIf_Timer_System_Internal_GetElapsed(CurrentRef)
    #define Trusted_k_cycle_get_32()                                    k_cycle_get_32()
#endif

#if STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT
    #define OsIfCoreID()        (OsIf_GetCoreID())
#else
    #define OsIfCoreID()        (0U)
#endif
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if STD_ON == OSIF_DEV_ERROR_DETECT
#define BASENXP_START_SEC_VAR_CLEARED_BOOLEAN
#include "BaseNXP_MemMap.h"

static boolean OsIf_abMdlInit[OSIF_MAX_COREIDX_SUPPORTED];

#define BASENXP_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "BaseNXP_MemMap.h"
#endif /* STD_ON == OSIF_DEV_ERROR_DETECT */

#if (defined(USING_OS_AUTOSAROS) || (STD_ON == OSIF_DEV_ERROR_DETECT))
#define BASENXP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BaseNXP_MemMap.h"

static const OsIf_ConfigType *OsIf_apxInternalCfg[OSIF_MAX_COREIDX_SUPPORTED];

#define BASENXP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BaseNXP_MemMap.h"
#endif /* (defined(USING_OS_AUTOSAROS) || (STD_ON == OSIF_DEV_ERROR_DETECT)) */

#define BASENXP_START_SEC_VAR_CLEARED_32
#include "BaseNXP_MemMap.h"

static uint32 OsIf_au32InternalFrequencies[OSIF_MAX_COREIDX_SUPPORTED];

#define BASENXP_STOP_SEC_VAR_CLEARED_32
#include "BaseNXP_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define BASENXP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BaseNXP_MemMap.h"

extern const OsIf_ConfigType *const OsIf_apxPredefinedConfig[OSIF_MAX_COREIDX_SUPPORTED];

#define BASENXP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BaseNXP_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

void OsIf_Timer_System_Init(void)
{
    uint32 CoreId = OsIfCoreID();

#if (STD_ON == OSIF_DEV_ERROR_DETECT)
#if (STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT)
    if ((CoreId >= OSIF_MAX_COREIDX_SUPPORTED) || (NULL_PTR == OsIf_apxPredefinedConfig[CoreId]))
#else
    if (NULL_PTR == OsIf_apxPredefinedConfig[CoreId])
#endif
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_INIT, OSIF_E_INV_CORE_IDX);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
    OsIf_abMdlInit[CoreId] = TRUE;
#endif

#if (defined(USING_OS_AUTOSAROS) || (STD_ON == OSIF_DEV_ERROR_DETECT))
    OsIf_apxInternalCfg[CoreId] = OsIf_apxPredefinedConfig[CoreId];
#endif
#if (!defined(USING_OS_FREERTOS) && !defined(USING_OS_ZEPHYR))
    OsIf_au32InternalFrequencies[CoreId] = OsIf_apxPredefinedConfig[CoreId]->counterFrequency;
#endif

#if defined(USING_OS_FREERTOS)
    /* FreeRTOS */
    OsIf_au32InternalFrequencies[CoreId] = configCPU_CLOCK_HZ;
#elif defined(USING_OS_ZEPHYR)
    /* ZephyrOS */
    OsIf_au32InternalFrequencies[CoreId] = sys_clock_hw_cycles_per_sec();
#elif defined(USING_OS_BAREMETAL)
    /* Baremetal */
    Trusted_OsIf_Timer_System_Internal_Init(OsIf_au32InternalFrequencies[CoreId]);
#endif
}


uint32 OsIf_Timer_System_GetCounter(void)
{
    uint32 Counter = 0u;
    uint32 CoreId = OsIfCoreID();

#if STD_ON == OSIF_DEV_ERROR_DETECT
    if (TRUE != OsIf_abMdlInit[CoreId])
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_GETCOUNTER, OSIF_E_UNINIT);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
#if (STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT)
    else if ((CoreId >= OSIF_MAX_COREIDX_SUPPORTED) || (NULL_PTR == OsIf_apxInternalCfg[CoreId]))
#else
    else if (NULL_PTR == OsIf_apxInternalCfg[CoreId])
#endif
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_GETCOUNTER, OSIF_E_INV_CORE_IDX);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
    else
    {
#endif /* OSIF_DEV_ERROR_DETECT  */

#if defined(USING_OS_AUTOSAROS)
    StatusType Status;
    TickType value;
    Status = GetCounterValue(OsIf_apxInternalCfg[CoreId]->counterId, &value);
    OSIF_DEV_ASSERT(Status == E_OK);
    Counter = (uint32)value;
#elif defined(USING_OS_ZEPHYR)
    /* ZephyrOS */
    (void)CoreId;
    Counter = Trusted_k_cycle_get_32();
#elif defined(USING_OS_FREERTOS) || defined(USING_OS_BAREMETAL)
    /* FreeRTOS and Baremetal*/
    (void)CoreId;
    Counter = Trusted_OsIf_Timer_System_Internal_GetCounter();
#endif

#if STD_ON == OSIF_DEV_ERROR_DETECT
    }
#endif

    return Counter;
}


uint32 OsIf_Timer_System_GetElapsed(uint32 * const CurrentRef)
{
    uint32 Elapsed = 0u;
    uint32 CoreId = OsIfCoreID();

#if STD_ON == OSIF_DEV_ERROR_DETECT
    if (TRUE != OsIf_abMdlInit[CoreId])
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_GETELAPSED, OSIF_E_UNINIT);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
#if (STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT)
    else if ((CoreId >= OSIF_MAX_COREIDX_SUPPORTED) || (NULL_PTR == OsIf_apxInternalCfg[CoreId]))
#else
    else if (NULL_PTR == OsIf_apxInternalCfg[CoreId])
#endif
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_GETELAPSED, OSIF_E_INV_CORE_IDX);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
    else
    {
#endif /* OSIF_DEV_ERROR_DETECT  */

#if defined(USING_OS_AUTOSAROS)
    TickType ElapsedTickType;
    StatusType Status;
    Status = GetElapsedValue(OsIf_apxInternalCfg[CoreId]->counterId, (TickType*)CurrentRef, &ElapsedTickType);
    OSIF_DEV_ASSERT(Status == E_OK);
    Elapsed = (uint32)ElapsedTickType;
#elif defined(USING_OS_ZEPHYR)
    /* No need for additional logic. The hardware clock is represented as a 32-bit counter */
    uint32 CurrentVal = Trusted_k_cycle_get_32();
    Elapsed = CurrentVal - *CurrentRef;
    *CurrentRef = CurrentVal;
    (void)CoreId;
#elif defined(USING_OS_FREERTOS) || defined(USING_OS_BAREMETAL)
    /* FreeRTOS and Baremetal*/
    (void)CoreId;
    Elapsed = Trusted_OsIf_Timer_System_Internal_GetElapsed(CurrentRef);
#endif

#if STD_ON == OSIF_DEV_ERROR_DETECT
    }
#endif

    return Elapsed;
}


void OsIf_Timer_System_SetTimerFrequency(uint32 Freq)
{
    uint32 CoreId = OsIfCoreID();
#if STD_ON == OSIF_DEV_ERROR_DETECT

    if (TRUE != OsIf_abMdlInit[CoreId])
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_SETTIMERFREQ, OSIF_E_UNINIT);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
#if (STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT)
    else if ((CoreId >= OSIF_MAX_COREIDX_SUPPORTED) || (NULL_PTR == OsIf_apxInternalCfg[CoreId]))
#else
    else if (NULL_PTR == OsIf_apxInternalCfg[CoreId])
#endif
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_SETTIMERFREQ, OSIF_E_INV_CORE_IDX);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
    else
    {
#endif /* OSIF_DEV_ERROR_DETECT  */

#if defined(USING_OS_AUTOSAROS)
    (void)CoreId;
    (void)Freq;
#elif defined(USING_OS_ZEPHYR)
    (void)CoreId;
    (void)Freq;
    /* As of 2.6.0: "The frequency of this counter is required to be steady over time" */
#elif defined(USING_OS_FREERTOS) || defined(USING_OS_BAREMETAL)
    /* FreeRTOS and Baremetal*/
    OsIf_au32InternalFrequencies[CoreId] = Freq;
#endif

#if STD_ON == OSIF_DEV_ERROR_DETECT
    }
#endif
}


uint32 OsIf_Timer_System_MicrosToTicks(uint32 Micros)
{
    uint64 interim;
    uint32 ticks = 0u;
    uint32 CoreId = OsIfCoreID();

#if STD_ON == OSIF_DEV_ERROR_DETECT
    if (TRUE != OsIf_abMdlInit[CoreId])
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_US2TICKS, OSIF_E_UNINIT);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
#if (STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT)
    else if ((CoreId >= OSIF_MAX_COREIDX_SUPPORTED) || (NULL_PTR == OsIf_apxInternalCfg[CoreId]))
#else
    else if (NULL_PTR == OsIf_apxInternalCfg[CoreId])
#endif
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_US2TICKS, OSIF_E_INV_CORE_IDX);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
    else
    {
#endif /* OSIF_DEV_ERROR_DETECT  */

    interim = Micros * (uint64)OsIf_au32InternalFrequencies[CoreId];
    interim /= 1000000u;
    OSIF_DEV_ASSERT(interim <= 0xFFFFFFFFu); /* check that computed value fits in 32 bits */
    ticks = (uint32)(interim & 0xFFFFFFFFu);

#if STD_ON == OSIF_DEV_ERROR_DETECT
    }
#endif

    return ticks;
}

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#endif /* (OSIF_USE_SYSTEM_TIMER == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
