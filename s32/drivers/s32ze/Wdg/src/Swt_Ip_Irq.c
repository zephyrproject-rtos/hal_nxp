/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

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

#include "Swt_Ip_Irq.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_IRQ_VENDOR_ID_C                      43
#define SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define SWT_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define SWT_IP_IRQ_SW_MAJOR_VERSION_C               1
#define SWT_IP_IRQ_SW_MINOR_VERSION_C               0
#define SWT_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Irq configuration header file are of the same vendor */
#if (SWT_IP_IRQ_VENDOR_ID_C != SWT_IP_IRQ_VENDOR_ID)
#error "Swt_Ip_Irq.c and Swt_Ip_Irq.h have different vendor ids"
#endif

#if ((SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != SWT_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Swt_Ip_Irq.c and Swt_Ip_Irq.h are different"
#endif

#if ((SWT_IP_IRQ_SW_MAJOR_VERSION_C != SWT_IP_IRQ_SW_MAJOR_VERSION) || \
     (SWT_IP_IRQ_SW_MINOR_VERSION_C != SWT_IP_IRQ_SW_MINOR_VERSION) || \
     (SWT_IP_IRQ_SW_PATCH_VERSION_C != SWT_IP_IRQ_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Swt_Ip_Irq.c and Swt_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
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


/**
* @brief   Swt handler for initial timeout interrupt.
* @details This function implements the ISR occurring on the first SWT timeout.
*
* @isr
*
*/
#ifdef SWT_IP_ISR0_USED
#if (SWT_IP_ISR0_USED == STD_ON)
    ISR(Swt_Ip_Swt0_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(0U);
    }
#endif
#endif

#ifdef SWT_IP_ISR1_USED
#if (SWT_IP_ISR1_USED == STD_ON)
    ISR(Swt_Ip_Swt1_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(1U);
    }
#endif
#endif

#ifdef SWT_IP_ISR2_USED
#if (SWT_IP_ISR2_USED == STD_ON)
    ISR(Swt_Ip_Swt2_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(2U);
    }
#endif
#endif

#ifdef SWT_IP_ISR3_USED
#if (SWT_IP_ISR3_USED == STD_ON)
    ISR(Swt_Ip_Swt3_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(3U);
    }
#endif
#endif

#ifdef SWT_IP_ISR4_USED
#if (SWT_IP_ISR4_USED == STD_ON)
    ISR(Swt_Ip_Swt4_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(4U);
    }
#endif
#endif

#ifdef SWT_IP_ISR5_USED
#if (SWT_IP_ISR5_USED == STD_ON)
    ISR(Swt_Ip_Swt5_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(5U);
    }
#endif
#endif

#ifdef SWT_IP_ISR6_USED
#if (SWT_IP_ISR6_USED == STD_ON)
    ISR(Swt_Ip_Swt6_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(6U);
    }
#endif
#endif

#ifdef SWT_IP_ISR7_USED
#if (SWT_IP_ISR7_USED == STD_ON)
    ISR(Swt_Ip_Swt7_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(7U);
    }
#endif
#endif

#ifdef SWT_IP_ISR8_USED
#if (SWT_IP_ISR8_USED == STD_ON)
    ISR(Swt_Ip_Swt8_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(8U);
    }
#endif
#endif

#ifdef SWT_IP_ISR9_USED
#if (SWT_IP_ISR9_USED == STD_ON)
    ISR(Swt_Ip_Swt9_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(9U);
    }
#endif
#endif

#ifdef SWT_IP_ISR10_USED
#if (SWT_IP_ISR10_USED == STD_ON)
    ISR(Swt_Ip_Swt10_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(10U);
    }
#endif
#endif

#ifdef SWT_IP_ISR11_USED
#if (SWT_IP_ISR11_USED == STD_ON)
    ISR(Swt_Ip_Swt11_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(11U);
    }
#endif
#endif

#ifdef SWT_IP_ISR12_USED
#if (SWT_IP_ISR12_USED == STD_ON)
    ISR(Swt_Ip_Swt12_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(12U);
    }
#endif
#endif

#ifdef SWT_IP_ISR13_USED
#if (SWT_IP_ISR13_USED == STD_ON)
    ISR(Swt_Ip_Swt13_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(13U);
    }
#endif
#endif

#ifdef SWT_IP_ISR14_USED
#if (SWT_IP_ISR14_USED == STD_ON)
    ISR(Swt_Ip_Swt14_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(14U);
    }
#endif
#endif

#ifdef SWT_IP_ISR15_USED
#if (SWT_IP_ISR15_USED == STD_ON)
    ISR(Swt_Ip_Swt15_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(15U);
    }
#endif
#endif

#ifdef SWT_IP_ISR16_USED
#if (SWT_IP_ISR16_USED == STD_ON)
    ISR(Swt_Ip_Swt16_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(16U);
    }
#endif
#endif

#ifdef SWT_IP_ISR17_USED
#if (SWT_IP_ISR17_USED == STD_ON)
    ISR(Swt_Ip_Swt17_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(17U);
    }
#endif
#endif

#ifdef SWT_IP_ISR18_USED
#if (SWT_IP_ISR18_USED == STD_ON)
    ISR(Swt_Ip_Swt18_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(18U);
    }
#endif
#endif

#ifdef SWT_IP_ISR19_USED
#if (SWT_IP_ISR19_USED == STD_ON)
    ISR(Swt_Ip_Swt19_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(19U);
    }
#endif
#endif

#ifdef SWT_IP_ISR20_USED
#if (SWT_IP_ISR20_USED == STD_ON)
    ISR(Swt_Ip_Swt20_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(20U);
    }
#endif
#endif

#ifdef SWT_IP_ISR21_USED
#if (SWT_IP_ISR21_USED == STD_ON)
    ISR(Swt_Ip_Swt21_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(21U);
    }
#endif
#endif

#ifdef SWT_IP_ISR22_USED
#if (SWT_IP_ISR22_USED == STD_ON)
    ISR(Swt_Ip_Swt22_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(22U);
    }
#endif
#endif

#ifdef SWT_IP_ISR23_USED
#if (SWT_IP_ISR23_USED == STD_ON)
    ISR(Swt_Ip_Swt23_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(23U);
    }
#endif
#endif

#ifdef SWT_IP_ISR24_USED
#if (SWT_IP_ISR24_USED == STD_ON)
    ISR(Swt_Ip_Swt24_Isr)
    {
        /* Call handler function */
        Swt_Ip_IrqHandler(24U);
    }
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
