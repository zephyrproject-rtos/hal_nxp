/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef OSIF_INTERRUPTS_H
#define OSIF_INTERRUPTS_H

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
#include "OsIf_Cfg.h"

#if defined(USING_OS_ZEPHYR)
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_INTERRUPTS_VENDOR_ID                    43
#define OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION     7
#define OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION  0
#define OSIF_INTERRUPTS_SW_MAJOR_VERSION             3
#define OSIF_INTERRUPTS_SW_MINOR_VERSION             0
#define OSIF_INTERRUPTS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

void OsIf_Interrupts_ResumeAllInterrupts(void);
void OsIf_Interrupts_SuspendAllInterrupts(void);

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#endif /* defined(USING_OS_ZEPHYR) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OSIF_INTERRUPTS_H */
