/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef OSIF_INTERNAL_H
#define OSIF_INTERNAL_H

/**
*   @file
*   @implements OsIf_Internal.h_Artifact
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
#include "StandardTypes.h"
#include "Soc_Ips.h"
#include "OsIf_Cfg.h"

#if defined(USING_OS_AUTOSAROS)
#include "Os.h"
#endif /* defined(USING_OS_AUTOSAROS) */

#if defined(USING_OS_ZEPHYR)
#include "OsIf_Interrupts.h"
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#include "rtd.h"    /* System calls for RTD */
#endif
#endif /* defined(USING_OS_ZEPHYR) */

#if !defined(USING_OS_AUTOSAROS)
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (MCAL_PLATFORM_ARM  == MCAL_ARM_MARCH)
/* prototypes defined in system.h*/
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);
uint32 Sys_GoToSupervisor(void);
uint32 Sys_GoToUser(void);
#else
/*import inline function for switch context from system.h */
#include "system.h"
#endif
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);
#endif /* def MCAL_ENABLE_USER_MODE_SUPPORT */
uint8 Sys_GetCoreID(void);
#endif /* !defined(USING_OS_AUTOSAROS) */

#if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH32) || (MCAL_PLATFORM_ARM  == MCAL_ARM_RARCH) 
void Sys_EL1SuspendInterrupts(void);
void Sys_EL1ResumeInterrupts(void);
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_INTERNAL_VENDOR_ID                    43
#define OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION     7
#define OSIF_INTERNAL_AR_RELEASE_REVISION_VERSION  0
#define OSIF_INTERNAL_SW_MAJOR_VERSION             0
#define OSIF_INTERNAL_SW_MINOR_VERSION             9
#define OSIF_INTERNAL_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against StandardTypes.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Internal.h and StandardTypes.h are different"
    #endif
#endif

/* Checks against Soc_Ips.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Internal.h and Soc_Ips.h are different"
    #endif
#endif

#if defined(USING_OS_AUTOSAROS)
/* Checks against Os.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION != OS_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION != OS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Internal.h and Os.h are different"
    #endif
#endif
#endif /* defined(USING_OS_AUTOSAROS) */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*
 * OsIf_Trusted_Call*
 */
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (defined(USING_OS_AUTOSAROS) || defined(USING_OS_ZEPHYR))
#define OsIf_Trusted_Call(name)                                                  Call_##name##_TRUSTED()
#define OsIf_Trusted_Call1param(name,param)                                      Call_##name##_TRUSTED(param)
#define OsIf_Trusted_Call2params(name,param1,param2)                             Call_##name##_TRUSTED(param1,param2)
#define OsIf_Trusted_Call3params(name,param1,param2,param3)                      Call_##name##_TRUSTED(param1,param2,param3)
#define OsIf_Trusted_Call4params(name,param1,param2,param3,param4)               Call_##name##_TRUSTED(param1,param2,param3,param4)
#define OsIf_Trusted_Call5params(name,param1,param2,param3,param4,param5)        Call_##name##_TRUSTED(param1,param2,param3,param4,param5)
#define OsIf_Trusted_Call6params(name,param1,param2,param3,param4,param5,param6) Call_##name##_TRUSTED(param1,param2,param3,param4,param5,param6)

#define OsIf_Trusted_Call_Return(name)                                                 Call_##name##_TRUSTED()
#define OsIf_Trusted_Call_Return1param(name,param1)                                    Call_##name##_TRUSTED(param1)
#define OsIf_Trusted_Call_Return2param(name,param1,param2)                             Call_##name##_TRUSTED(param1,param2)
#define OsIf_Trusted_Call_Return3param(name,param1,param2,param3)                      Call_##name##_TRUSTED(param1,param2,param3)
#define OsIf_Trusted_Call_Return4param(name,param1,param2,param3,param4)               Call_##name##_TRUSTED(param1,param2,param3,param4)
#define OsIf_Trusted_Call_Return5param(name,param1,param2,param3,param4,param5)        Call_##name##_TRUSTED(param1,param2,param3,param4,param5)
#define OsIf_Trusted_Call_Return6param(name,param1,param2,param3,param4,param5,param6) Call_##name##_TRUSTED(param1,param2,param3,param4,param5,param6)

#else /* USING_OS_AUTOSAROS */
/* Baremetal and FreeRTOS */
#define OsIf_Trusted_Call(name)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(), (void)Sys_GoToUser()) : (name(),(void)0U))
#define OsIf_Trusted_Call1param(name,param)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param), (void)Sys_GoToUser()) : (name(param),(void)0U))
#define OsIf_Trusted_Call2params(name,param1,param2)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2), (void)Sys_GoToUser()) : (name(param1,param2),(void)0U))
#define OsIf_Trusted_Call3params(name,param1,param2,param3)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3), (void)Sys_GoToUser()) : (name(param1,param2,param3),(void)0U))
#define OsIf_Trusted_Call4params(name,param1,param2,param3,param4)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4),(void)0U))
#define OsIf_Trusted_Call5params(name,param1,param2,param3,param4,param5)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4,param5), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4,param5),(void)0U))
#define OsIf_Trusted_Call6params(name,param1,param2,param3,param4,param5,param6)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4,param5,param6), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4,param5,param6),(void)0U))

#define OsIf_Trusted_Call_Return(name)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name()) :  Sys_GoToUser_Return(0U, name()))
#define OsIf_Trusted_Call_Return1param(name,param)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param)) :  Sys_GoToUser_Return(0U, name(param)))
#define OsIf_Trusted_Call_Return2param(name,param1,param2)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2)) : Sys_GoToUser_Return(0U, name(param1,param2)))
#define OsIf_Trusted_Call_Return3param(name,param1,param2,param3)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3)))
#define OsIf_Trusted_Call_Return4param(name,param1,param2,param3,param4)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4)))
#define OsIf_Trusted_Call_Return5param(name,param1,param2,param3,param4,param5)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4,param5)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4,param5)))
#define OsIf_Trusted_Call_Return6param(name,param1,param2,param3,param4,param5,param6)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4,param5,param6)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4,param5,param6)))
#endif /* USING_OS_AUTOSAROS */
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

/*
 * OsIf_GetCoreID
 */
#ifdef USING_OS_AUTOSAROS
        #define OsIf_GetCoreID()    GetCoreID()
#else /* USING_OS_AUTOSAROS */
    /* Baremetal and FreeRTOS and ZephyrOS */
    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        #define OsIf_GetCoreID()    OsIf_Trusted_Call_Return(Sys_GetCoreID)
    #else
        /* @implements OsIf_GetCoreID_define */
        #define OsIf_GetCoreID()    Sys_GetCoreID()
    #endif
#endif

/*
 * OsIf_SuspendAllInterrupts
 * OsIf_ResumeAllInterrupts
 */
#if (!defined(USING_OS_AUTOSAROS) && !defined(USING_OS_ZEPHYR))
    #ifndef MCAL_ENABLE_USER_MODE_SUPPORT   /*Bare metal not enable user mode*/
        /* Baremetal or FreeRTOS case */
        #if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
            #define ResumeAllInterrupts()   ASM_KEYWORD(" msr DAIFClr,#0x3")
            #define SuspendAllInterrupts()  ASM_KEYWORD(" msr DAIFSet,#0x3")
        #elif (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH32) || (MCAL_PLATFORM_ARM  == MCAL_ARM_RARCH) 
            #define ResumeAllInterrupts()   Sys_EL1ResumeInterrupts()
            #define SuspendAllInterrupts()  Sys_EL1SuspendInterrupts()
        #else
            #define ResumeAllInterrupts()   ASM_KEYWORD(" cpsie i")
            #define SuspendAllInterrupts()  ASM_KEYWORD(" cpsid i")
        #endif /* MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64 */
    #else  
        #if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH32) || (MCAL_PLATFORM_ARM  == MCAL_ARM_RARCH) 
            #define ResumeAllInterrupts()  OsIf_Trusted_Call(Sys_EL1ResumeInterrupts)
            #define SuspendAllInterrupts() OsIf_Trusted_Call(Sys_EL1SuspendInterrupts)
        #else
            #define ResumeAllInterrupts()   Sys_ResumeInterrupts()
            #define SuspendAllInterrupts()  Sys_SuspendInterrupts()
        #endif  
    #endif /*MCAL_ENABLE_USER_MODE_SUPPORT */
#elif defined(USING_OS_ZEPHYR)
    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        #define ResumeAllInterrupts()   OsIf_Trusted_Call(OsIf_Interrupts_ResumeAllInterrupts)
        #define SuspendAllInterrupts()  OsIf_Trusted_Call(OsIf_Interrupts_SuspendAllInterrupts)
    #else
        #define ResumeAllInterrupts()   OsIf_Interrupts_ResumeAllInterrupts()
        #define SuspendAllInterrupts()  OsIf_Interrupts_SuspendAllInterrupts()
    #endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* !defined(USING_OS_AUTOSAROS) && !defined(USING_OS_ZEPHYR) */

/* @implements OsIf_SuspendAllInterrupts_define */
#define OsIf_SuspendAllInterrupts()     SuspendAllInterrupts()
/* @implements OsIf_ResumeAllInterrupts_define */
#define OsIf_ResumeAllInterrupts()      ResumeAllInterrupts()

/*
 * ISR macro definition
 */
#ifdef USING_OS_AUTOSAROS
/* ISR() macro defined by Autosar OS*/
#else
/* Baremetal or FreeRTOS case */
#if defined (USE_SW_VECTOR_MODE)
    #define ISR(IsrName)       void IsrName(void)
#else
    #define ISR(IsrName)       INTERRUPT_FUNC void IsrName(void)
#endif /* defined (USE_SW_VECTOR_MODE) */
#endif /* USING_OS_AUTOSAROS */

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /* OSIF_INTERNAL_H */
