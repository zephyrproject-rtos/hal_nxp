/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file    Devassert.h
*   @version 0.8.0
*
*   @brief   BaseNXP - Devassert.
*   @details
*
*   @addtogroup
*   @{
*/
#ifndef DEVASSERT_H
#define DEVASSERT_H

#ifdef __cplusplus
extern "C"{
#endif


/*
    Drivers can use a mechanism to validate data coming from upper software layers (application code) by performing
    a number of checks on input parameters' range or other invariants that can be statically checked (not dependent on
    runtime conditions). A failed validation is indicative of a software bug in application code, therefore it is important
    to use this mechanism during development.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEVASSERT_VENDOR_ID                    43
#define DEVASSERT_AR_RELEASE_MAJOR_VERSION     4
#define DEVASSERT_AR_RELEASE_MINOR_VERSION     9
#define DEVASSERT_AR_RELEASE_REVISION_VERSION  0
#define DEVASSERT_SW_MAJOR_VERSION             0
#define DEVASSERT_SW_MINOR_VERSION             8
#define DEVASSERT_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Devassert.h and Platform_Types.h are of the same version */
    #if ((DEVASSERT_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (DEVASSERT_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AUTOSAR Version Numbers of Devassert.h and Platform_Types.h are different"
    #endif
    /* Check if the files Devassert.h and Mcal.h are of the same version */
    #if ((DEVASSERT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (DEVASSERT_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AUTOSAR Version Numbers of Devassert.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef CCOV_ENABLE
    #define DevAssert(x)
#else


 #ifdef MCAL_PLATFORM_ZENV
#define BREAKPOINT_INSTR        "EBREAK"
#else
#if ((MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64) || \
     (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH32) || \
     (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH))
    #define BREAKPOINT_INSTR        "HLT #0"
#elif (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)
    #define BREAKPOINT_INSTR        "BKPT #0"
#else
    #error "Unsupported architecture!"
#endif
#endif
    #if defined (CUSTOM_DEVASSERT)
        /* If the CUSTOM_DEVASSERT symbol is defined, then add the custom implementation */
        #include CUSTOM_DEVASSERT
    #elif !defined(DevAssert)
        /* Implement default assert macro */
        static inline void DevAssert(volatile boolean x)
        {
            if(x) { } else { for(;;) {ASM_KEYWORD(BREAKPOINT_INSTR);} }
        }
    #endif
#endif


#ifdef __cplusplus
}
#endif

#endif /* DEVASSERT_H */

/** @} */


/*******************************************************************************
 * EOF
 ******************************************************************************/
