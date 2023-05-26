/*
 * Copyright 2020-2023 NXP
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

#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
/* Defines the Hw Timer functions to be implemented in OS-specific environments */
#include "OsIf_Timer_System.h"
#endif /* (OSIF_USE_SYSTEM_TIMER == STD_ON) */

#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
/* API functions to be implemented by user */
#include "OsIf_Timer_Custom.h"
#endif /* (OSIF_USE_CUSTOM_TIMER == STD_ON) */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_TIMER_VENDOR_ID_C                    43
#define OSIF_TIMER_AR_RELEASE_MAJOR_VERSION_C     4
#define OSIF_TIMER_AR_RELEASE_MINOR_VERSION_C     7
#define OSIF_TIMER_AR_RELEASE_REVISION_VERSION_C  0
#define OSIF_TIMER_SW_MAJOR_VERSION_C             3
#define OSIF_TIMER_SW_MINOR_VERSION_C             0
#define OSIF_TIMER_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against OsIf.h */
#if (OSIF_TIMER_VENDOR_ID_C != OSIF_VENDOR_ID)
    #error "OsIf_Timer.c and OsIf.h have different vendor ids"
#endif
#if ((OSIF_TIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer.c and OsIf.h are different"
#endif
#if ((OSIF_TIMER_SW_MAJOR_VERSION_C != OSIF_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SW_MINOR_VERSION_C != OSIF_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SW_PATCH_VERSION_C != OSIF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer.c and OsIf.h are different"
#endif

/* Checks against OsIf_Cfg.h */
#if (OSIF_TIMER_VENDOR_ID_C != OSIF_CFG_VENDOR_ID)
    #error "OsIf_Timer.c and OsIf_Cfg.h have different vendor ids"
#endif
#if ((OSIF_TIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer.c and OsIf_Cfg.h are different"
#endif
#if ((OSIF_TIMER_SW_MAJOR_VERSION_C != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SW_MINOR_VERSION_C != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SW_PATCH_VERSION_C != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer.c and OsIf_Cfg.h are different"
#endif

/* Checks against OsIf_Cfg_TypesDef.h */
#if (OSIF_TIMER_VENDOR_ID_C != OSIF_CFG_TYPESDEF_VENDOR_ID)
    #error "OsIf_Timer.c and OsIf_Cfg_TypesDef.h have different vendor ids"
#endif
#if ((OSIF_TIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_CFG_TYPESDEF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System.c and OsIf_Cfg_TypesDef.h are different"
#endif
#if ((OSIF_TIMER_SW_MAJOR_VERSION_C != OSIF_CFG_TYPESDEF_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SW_MINOR_VERSION_C != OSIF_CFG_TYPESDEF_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SW_PATCH_VERSION_C != OSIF_CFG_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer.c and OsIf_Cfg_TypesDef.h are different"
#endif

#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
/* Checks against OsIf_Timer_System.h */
#if (OSIF_TIMER_VENDOR_ID_C != OSIF_TIMER_SYSTEM_VENDOR_ID)
    #error "OsIf_Timer.c and OsIf_Timer_System.h have different vendor ids"
#endif
#if ((OSIF_TIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_SYSTEM_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_SYSTEM_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_SYSTEM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer.c and OsIf_Timer_System.h are different"
#endif
#if ((OSIF_TIMER_SW_MAJOR_VERSION_C != OSIF_TIMER_SYSTEM_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SW_MINOR_VERSION_C != OSIF_TIMER_SYSTEM_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SW_PATCH_VERSION_C != OSIF_TIMER_SYSTEM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer.c and OsIf_Timer_System.h are different"
#endif
#endif /* (OSIF_USE_SYSTEM_TIMER == STD_ON) */

#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
/* Checks against OsIf_Timer_Custom.h */
#if (OSIF_TIMER_VENDOR_ID_C != OSIF_TIMER_CUSTOM_VENDOR_ID)
    #error "OsIf_Timer.c and OsIf_Timer_Custom.h have different vendor ids"
#endif
#if ((OSIF_TIMER_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_CUSTOM_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_CUSTOM_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_CUSTOM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer.c and OsIf_Timer_Custom.h are different"
#endif
#if ((OSIF_TIMER_SW_MAJOR_VERSION_C != OSIF_TIMER_CUSTOM_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SW_MINOR_VERSION_C != OSIF_TIMER_CUSTOM_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SW_PATCH_VERSION_C != OSIF_TIMER_CUSTOM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer.c and OsIf_Timer_Custom.h are different"
#endif
#endif /* (OSIF_USE_CUSTOM_TIMER == STD_ON) */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

static inline uint32 OsIf_Timer_Dummy_GetCounter(void);
static inline uint32 OsIf_Timer_Dummy_GetElapsed(const uint32 * const CurrentRef);
static inline void OsIf_Timer_Dummy_SetTimerFrequency(uint32 Freq);
static inline uint32 OsIf_Timer_Dummy_MicrosToTicks(uint32 Micros);

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

/* OsIf_Timer_Dummy_GetCounter_Activity */
static inline uint32 OsIf_Timer_Dummy_GetCounter(void)
{
    return 0u;
}

/* OsIf_Timer_Dummy_GetElapsed_Activity */
static inline uint32 OsIf_Timer_Dummy_GetElapsed(const uint32 * const CurrentRef)
{
    (void)CurrentRef;
    return 1u;
}

/* OsIf_Timer_Dummy_SetTimerFrequency_Activity */
static inline void OsIf_Timer_Dummy_SetTimerFrequency(uint32 Freq)
{
    (void)Freq;
}

/* OsIf_Timer_Dummy_MicrosToTicks_Activity */
static inline uint32 OsIf_Timer_Dummy_MicrosToTicks(uint32 Micros)
{
    return Micros;
}

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

/* @implements OsIf_Init_Activity */
void OsIf_Init(const void* Config)
{

#if (STD_ON == OSIF_DEV_ERROR_DETECT)
    if (Config != NULL_PTR)
    {
        #if defined(USING_OS_AUTOSAROS)
        (void)Det_ReportError(OSIF_MODULE_ID, OSIF_DRIVER_INSTANCE, OSIF_SID_INIT, OSIF_E_INIT_FAILED);
        #else
        OSIF_DEV_ASSERT(FALSE);
        #endif
    }
#else
    (void)Config;
#endif

#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
    OsIf_Timer_System_Init();
#endif
#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
    OsIf_Timer_Custom_Init();
#endif
}

/* @implements OsIf_GetCounter_Activity */
uint32 OsIf_GetCounter(OsIf_CounterType SelectedCounter)
{
    uint32 Value = 0u;
    switch (SelectedCounter){
        case OSIF_COUNTER_DUMMY:
            Value = OsIf_Timer_Dummy_GetCounter();
            break;
#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
        case OSIF_COUNTER_SYSTEM:
            Value = OsIf_Timer_System_GetCounter();
            break;
#endif
#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
        case OSIF_COUNTER_CUSTOM:
            Value = OsIf_Timer_Custom_GetCounter();
            break;
#endif
        default: /* impossible */ break;
    }
    return Value;
}


/* @implements OsIf_GetElapsed_Activity */
uint32 OsIf_GetElapsed(uint32 * const CurrentRef, OsIf_CounterType SelectedCounter)
{
    uint32 Value = 0u;
    switch (SelectedCounter){
        case OSIF_COUNTER_DUMMY:
            Value = OsIf_Timer_Dummy_GetElapsed(CurrentRef);
            break;
#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
        case OSIF_COUNTER_SYSTEM:
            Value = OsIf_Timer_System_GetElapsed(CurrentRef);
            break;
#endif
#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
        case OSIF_COUNTER_CUSTOM:
            Value = OsIf_Timer_Custom_GetElapsed(CurrentRef);
            break;
#endif
        default: /* impossible */ break;
    }
    return Value;
}


/* @implements OsIf_SetTimerFrequency_Activity */
void OsIf_SetTimerFrequency(uint32 Freq, OsIf_CounterType SelectedCounter)
{
    switch (SelectedCounter){
        case OSIF_COUNTER_DUMMY:
            OsIf_Timer_Dummy_SetTimerFrequency(Freq);
            break;
#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
        case OSIF_COUNTER_SYSTEM:
            OsIf_Timer_System_SetTimerFrequency(Freq);
            break;
#endif
#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
        case OSIF_COUNTER_CUSTOM:
            OsIf_Timer_Custom_SetTimerFrequency(Freq);
            break;
#endif
        default: /* impossible */ break;
    }
}

/* @implements OsIf_MicrosToTicks_Activity */
uint32 OsIf_MicrosToTicks(uint32 Micros, OsIf_CounterType SelectedCounter)
{
    uint32 Value = 0u;
    switch (SelectedCounter){
        case OSIF_COUNTER_DUMMY:
            Value = OsIf_Timer_Dummy_MicrosToTicks(Micros);
            break;
#if (OSIF_USE_SYSTEM_TIMER == STD_ON)
        case OSIF_COUNTER_SYSTEM:
            Value = OsIf_Timer_System_MicrosToTicks(Micros);
            break;
#endif
#if (OSIF_USE_CUSTOM_TIMER == STD_ON)
        case OSIF_COUNTER_CUSTOM:
            Value = OsIf_Timer_Custom_MicrosToTicks(Micros);
            break;
#endif
        default: /* impossible */ break;
    }
    return Value;
}

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
