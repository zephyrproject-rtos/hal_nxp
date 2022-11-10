/*
 * Copyright 2021-2022 NXP.
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
#include "OsIf_Interrupts.h"

#if defined(USING_OS_ZEPHYR)
#include <zephyr/kernel.h>

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_INTERRUPTS_VENDOR_ID_C                    43
#define OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION_C     4
#define OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION_C     7
#define OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION_C  0
#define OSIF_INTERRUPTS_SW_MAJOR_VERSION_C             0
#define OSIF_INTERRUPTS_SW_MINOR_VERSION_C             9
#define OSIF_INTERRUPTS_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against OsIf.h */
#if (OSIF_INTERRUPTS_VENDOR_ID_C != OSIF_VENDOR_ID)
    #error "OsIf_Interrupts.c and OsIf.h have different vendor ids"
#endif
#if ((OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION_C != OSIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Interrupts.c and OsIf.h are different"
#endif
#if ((OSIF_INTERRUPTS_SW_MAJOR_VERSION_C != OSIF_SW_MAJOR_VERSION) || \
     (OSIF_INTERRUPTS_SW_MINOR_VERSION_C != OSIF_SW_MINOR_VERSION) || \
     (OSIF_INTERRUPTS_SW_PATCH_VERSION_C != OSIF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Interrupts.c and OsIf.h are different"
#endif

/* Checks against OsIf_Interrupts.h */
#if (OSIF_INTERRUPTS_VENDOR_ID_C != OSIF_INTERRUPTS_VENDOR_ID)
    #error "OsIf_Interrupts.c and OsIf_Interrupts.h have different vendor ids"
#endif
#if ((OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION_C    != OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION_C != OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Interrupts.c and OsIf_Interrupts.h are different"
#endif
#if ((OSIF_INTERRUPTS_SW_MAJOR_VERSION_C != OSIF_INTERRUPTS_SW_MAJOR_VERSION) || \
     (OSIF_INTERRUPTS_SW_MINOR_VERSION_C != OSIF_INTERRUPTS_SW_MINOR_VERSION) || \
     (OSIF_INTERRUPTS_SW_PATCH_VERSION_C != OSIF_INTERRUPTS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Interrupts.c and OsIf_Interrupts.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == OSIF_ENABLE_MULTICORE_SUPPORT)
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
#define BASENXP_START_SEC_VAR_CLEARED_32
#include "BaseNXP_MemMap.h"

static uint32 OsIf_au32OldIrqMask[OSIF_MAX_COREIDX_SUPPORTED];
static uint32 OsIf_au32SuspendLevel[OSIF_MAX_COREIDX_SUPPORTED];

#define BASENXP_STOP_SEC_VAR_CLEARED_32
#include "BaseNXP_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

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

void OsIf_Interrupts_SuspendAllInterrupts(void)
{
    uint32 CoreId = OsIfCoreID();

    if (OsIf_au32SuspendLevel[CoreId]++ == 0U)
    {
        OsIf_au32OldIrqMask[CoreId] = arch_irq_lock();
    }
}

void OsIf_Interrupts_ResumeAllInterrupts(void)
{
    uint32 CoreId = OsIfCoreID();

    if (--OsIf_au32SuspendLevel[CoreId] == 0U)
    {
       arch_irq_unlock(OsIf_au32OldIrqMask[CoreId]);
    }
}

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#endif /* defined(USING_OS_ZEPHYR) */

#ifdef __cplusplus
}
#endif

/** @} */
