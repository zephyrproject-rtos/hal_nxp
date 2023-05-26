/*
 * Copyright 2020-2023 M4_SRC_COPYRIGHTED_TOs
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DEVASSERT_H
#define DEVASSERT_H

#include "PlatformTypes.h"
#include "Mcal.h"

/*
    Drivers can use a mechanism to validate data coming from upper software layers (application code) by performing
    a number of checks on input parameters' range or other invariants that can be statically checked (not dependent on
    runtime conditions). A failed validation is indicative of a software bug in application code, therefore it is important
    to use this mechanism during development.
*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEVASSERT_VENDOR_ID                    43
#define DEVASSERT_AR_RELEASE_MAJOR_VERSION     4
#define DEVASSERT_AR_RELEASE_MINOR_VERSION     7
#define DEVASSERT_AR_RELEASE_REVISION_VERSION  0
#define DEVASSERT_SW_MAJOR_VERSION             3
#define DEVASSERT_SW_MINOR_VERSION             0
#define DEVASSERT_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Devassert.h and PlatformTypes.h are of the same version */
    #if ((DEVASSERT_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (DEVASSERT_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AUTOSAR Version Numbers of Devassert.h and PlatformTypes.h are different"
    #endif
    /* Check if the files Devassert.h and Mcal.h are of the same version */
    #if ((DEVASSERT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (DEVASSERT_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AUTOSAR Version Numbers of Devassert.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef CCOV_ENABLE
    #define DevAssert(x)
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

/* Implement default assert macro */
static inline void DevAssert(volatile boolean x)
{
    if(x) { } else { for(;;) {ASM_KEYWORD(BREAKPOINT_INSTR);} }
}
#endif

#endif /* DEVASSERT_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
