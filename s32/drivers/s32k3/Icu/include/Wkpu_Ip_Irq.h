/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WKPU_IP_IRQ_H
#define WKPU_IP_IRQ_H

/**
 *     @file
 *
 *     @addtogroup wkpu_icu_ip WKPU IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Wkpu_Ip_Cfg.h"
#include "Wkpu_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WKPU_IP_IRQ_VENDOR_ID                      43

#define WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION    0

#define WKPU_IP_IRQ_SW_MAJOR_VERSION               3
#define WKPU_IP_IRQ_SW_MINOR_VERSION               0
#define WKPU_IP_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* TO DO Check if header file and OsIf.h file are of the same Autosar version */

/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_IRQ_VENDOR_ID != WKPU_IP_CFG_VENDOR_ID)
    #error "Wkpu_Ip_Irq.h and Wkpu_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION  != WKPU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION  != WKPU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION   != WKPU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Irq.h and Wkpu_Ip_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_IRQ_SW_MAJOR_VERSION  != WKPU_IP_CFG_SW_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_SW_MINOR_VERSION  != WKPU_IP_CFG_SW_MINOR_VERSION) || \
     (WKPU_IP_IRQ_SW_PATCH_VERSION  != WKPU_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip_Irq.h and Wkpu_Ip_Cfg.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_IRQ_VENDOR_ID != WKPU_IP_TYPES_VENDOR_ID)
    #error "Wkpu_Ip_Irq.h and Wkpu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION  != WKPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION  != WKPU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION   != WKPU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Irq.h and Wkpu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_IRQ_SW_MAJOR_VERSION  != WKPU_IP_TYPES_SW_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_SW_MINOR_VERSION  != WKPU_IP_TYPES_SW_MINOR_VERSION) || \
     (WKPU_IP_IRQ_SW_PATCH_VERSION  != WKPU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip_Irq.h and Wkpu_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wkpu_Ip_Irq.h and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
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
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == WKPU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#ifdef WKPU_IP_SUPPORT_INTERRUPT_REQUEST

#if (defined(WKPU_ICU_SINGLE_INTERRUPT) && (WKPU_ICU_SINGLE_INTERRUPT == STD_ON))

/**
 * @brief     Interrupt handler for WKPU channels: 0 to 31.
 * @details   Process the interrupt of WKPU channels 0 to 31 for platforms with only one interrupt line.
 *
 * @remarks   This will be defined only if any of WKPU channels 0 to 31 are configured.
 */
ISR(WKPU_EXT_IRQ_SINGLE_ISR);
#endif /*defined WKPU_ICU_SINGLE_INTERRUPT*/

#endif /* #ifdef WKPU_IP_SUPPORT_INTERRUPT_REQUEST */

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/**@}*/

#endif  /* WKPU_IP_IRQ_H */
