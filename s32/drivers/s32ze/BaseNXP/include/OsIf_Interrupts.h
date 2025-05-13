/*
 * Copyright 2021-2025 NXP
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

#if (defined(USING_OS_ZEPHYR) || defined(USING_OS_FREERTOS))
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_INTERRUPTS_VENDOR_ID                    43
#define OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION     7
#define OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION  0
#define OSIF_INTERRUPTS_SW_MAJOR_VERSION             2
#define OSIF_INTERRUPTS_SW_MINOR_VERSION             0
#define OSIF_INTERRUPTS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if OsIf_Interrupts.h file and OsIf_Cfg.h file are of the same vendor */
#if (OSIF_INTERRUPTS_VENDOR_ID != OSIF_CFG_VENDOR_ID)
    #error "OsIf_Interrupts.h and OsIf_Cfg.h have different vendor ids"
#endif
/* Check if OsIf_Interrupts.h file and OsIf_Cfg.h file are of the same Autosar version */
#if ((OSIF_INTERRUPTS_AR_RELEASE_MAJOR_VERSION    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_INTERRUPTS_AR_RELEASE_MINOR_VERSION    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_INTERRUPTS_AR_RELEASE_REVISION_VERSION != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Interrupts.h and OsIf_Cfg.h are different"
#endif
/* Check if OsIf_Interrupts.h file and OsIf_Cfg.h file are of the same Software version */
#if ((OSIF_INTERRUPTS_SW_MAJOR_VERSION != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_INTERRUPTS_SW_MINOR_VERSION != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_INTERRUPTS_SW_PATCH_VERSION != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Interrupts.h and OsIf_Cfg.h are different"
#endif

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
/*!
 * @brief Resume all interrupts.
 *
 * This function resume all interrupts.
 */
void OsIf_Interrupts_ResumeAllInterrupts(void);

/*!
 * @brief Suspend all interrupts.
 *
 * This function suspend all interrupts.
 */
void OsIf_Interrupts_SuspendAllInterrupts(void);

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#endif /* defined(USING_OS_ZEPHYR) || defined(USING_OS_FREERTOS) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OSIF_INTERRUPTS_H */
