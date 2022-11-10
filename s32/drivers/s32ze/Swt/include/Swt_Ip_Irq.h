/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SWT_IP_IRQ_H
#define SWT_IP_IRQ_H

/**
*   @file
*
*   @addtogroup Swt
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "StandardTypes.h"
#include "Swt_Ip_Cfg_Defines.h"
#include "OsIf.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_IRQ_VENDOR_ID                      43
#define SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define SWT_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define SWT_IP_IRQ_SW_MAJOR_VERSION               0
#define SWT_IP_IRQ_SW_MINOR_VERSION               9
#define SWT_IP_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Types header file are of the same vendor */
/* Check if current file and Swt_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (SWT_IP_IRQ_VENDOR_ID != SWT_IP_CFG_DEFINES_VENDOR_ID)
#error "Swt_Ip_Irq.h and Swt_Ip_Cfg_Defines.h have different vendor ids"
#endif

#if ((SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION    != SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_IRQ_AR_RELEASE_REVISION_VERSION != SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip_Irq.h and Swt_Ip_Cfg_Defines.h are different"
#endif

#if ((SWT_IP_IRQ_SW_MAJOR_VERSION != SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (SWT_IP_IRQ_SW_MINOR_VERSION != SWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (SWT_IP_IRQ_SW_PATCH_VERSION != SWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip_Irq.h and Swt_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Osif header file are of the same Autosar version */
    #if ((SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION     != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Swt_Ip_Irq.h and Osif.h are different"
    #endif
    
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Swt_Ip_Irq.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"


void Swt_Ip_IrqHandler(uint32 Instance);

#ifdef SWT_IP_ISR0_USED
#if (SWT_IP_ISR0_USED == STD_ON)
    ISR(Swt_Ip_Swt0_Isr);
#endif
#endif

#ifdef SWT_IP_ISR1_USED
#if (SWT_IP_ISR1_USED == STD_ON)
    ISR(Swt_Ip_Swt1_Isr);
#endif
#endif

#ifdef SWT_IP_ISR2_USED
#if (SWT_IP_ISR2_USED == STD_ON)
    ISR(Swt_Ip_Swt2_Isr);
#endif
#endif

#ifdef SWT_IP_ISR3_USED
#if (SWT_IP_ISR3_USED == STD_ON)
    ISR(Swt_Ip_Swt3_Isr);
#endif
#endif

#ifdef SWT_IP_ISR4_USED
#if (SWT_IP_ISR4_USED == STD_ON)
    ISR(Swt_Ip_Swt4_Isr);
#endif
#endif

#ifdef SWT_IP_ISR5_USED
#if (SWT_IP_ISR5_USED == STD_ON)
    ISR(Swt_Ip_Swt5_Isr);
#endif
#endif

#ifdef SWT_IP_ISR6_USED
#if (SWT_IP_ISR6_USED == STD_ON)
    ISR(Swt_Ip_Swt6_Isr);
#endif
#endif

#ifdef SWT_IP_ISR7_USED
#if (SWT_IP_ISR7_USED == STD_ON)
    ISR(Swt_Ip_Swt7_Isr);
#endif
#endif

#ifdef SWT_IP_ISR8_USED
#if (SWT_IP_ISR8_USED == STD_ON)
    ISR(Swt_Ip_Swt8_Isr);
#endif
#endif

#ifdef SWT_IP_ISR9_USED
#if (SWT_IP_ISR9_USED == STD_ON)
    ISR(Swt_Ip_Swt9_Isr);
#endif
#endif

#ifdef SWT_IP_ISR10_USED
#if (SWT_IP_ISR10_USED == STD_ON)
    ISR(Swt_Ip_Swt10_Isr);
#endif
#endif

#ifdef SWT_IP_ISR11_USED
#if (SWT_IP_ISR11_USED == STD_ON)
    ISR(Swt_Ip_Swt11_Isr);
#endif
#endif

#ifdef SWT_IP_ISR12_USED
#if (SWT_IP_ISR12_USED == STD_ON)
    ISR(Swt_Ip_Swt12_Isr);
#endif
#endif

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif


#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SWT_IP_IRQ_H */

