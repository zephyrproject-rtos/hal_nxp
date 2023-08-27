/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

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
#include "Std_Types.h"
#include "Wkpu_Ip.h"
#include "Wkpu_Ip_Irq.h"

#include "SchM_Icu.h"
/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define WKPU_IP_IRQ_VENDOR_ID_C                    43
#define WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C     7
#define WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C  0
#define WKPU_IP_IRQ_SW_MAJOR_VERSION_C             3
#define WKPU_IP_IRQ_SW_MINOR_VERSION_C             0
#define WKPU_IP_IRQ_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wkpu_Ip_Irq.c and Std_Types.h are different"
    #endif
    /* Check if this header file and SchM_Icu.h file are of the same Autosar version */
    #if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
        (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wkpu_Ip_Irq.c and SchM_Icu.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_IRQ_VENDOR_ID_C != WKPU_IP_VENDOR_ID)
    #error "Wkpu_Ip_Irq.c and Wkpu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C  != WKPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C  != WKPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C   != WKPU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Irq.c and Wkpu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_IRQ_SW_MAJOR_VERSION_C  != WKPU_IP_SW_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_SW_MINOR_VERSION_C  != WKPU_IP_SW_MINOR_VERSION) || \
     (WKPU_IP_IRQ_SW_PATCH_VERSION_C  != WKPU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip_Irq.c and Wkpu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_IRQ_VENDOR_ID_C != WKPU_IP_IRQ_VENDOR_ID)
    #error "Wkpu_Ip_Irq.c and Wkpu_Ip_Irq.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C  != WKPU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C  != WKPU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C   != WKPU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Irq.c and Wkpu_Ip_Irq.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_IRQ_SW_MAJOR_VERSION_C  != WKPU_IP_IRQ_SW_MAJOR_VERSION) || \
     (WKPU_IP_IRQ_SW_MINOR_VERSION_C  != WKPU_IP_IRQ_SW_MINOR_VERSION) || \
     (WKPU_IP_IRQ_SW_PATCH_VERSION_C  != WKPU_IP_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip_Irq.c and Wkpu_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == WKPU_IP_USED)

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"
/* Table of initilized Wkpu channels */
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
/* Table of initilized WKPU channels */
extern Wkpu_Ip_State Wkpu_Ip_u32ChState[WKPU_IP_NUM_OF_CHANNELS_USED];
#endif /* WKPU_DERIVATIVE_SUPPORT_ONLY_NMI */
#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_8
#include "Icu_MemMap.h"
/* This array stores the positions in the Wkpu_Ip_u32ChState array of the configured Wkpu channels. */
extern uint8 Wkpu_Ip_IndexInChState[WKPU_IP_NUM_OF_CHANNELS];
#define ICU_STOP_SEC_VAR_INIT_8
#include "Icu_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)

#if (defined(WKPU_ICU_SINGLE_INTERRUPT) && (WKPU_ICU_SINGLE_INTERRUPT == STD_ON))
static inline void Wkpu_Ip_Callback(uint8 hwChannel);
#endif

#endif /* WKPU_DERIVATIVE_SUPPORT_ONLY_NMI */

#if (defined(WKPU_ICU_SINGLE_INTERRUPT) && (WKPU_ICU_SINGLE_INTERRUPT == STD_ON))

static inline void Wkpu_Icu_Ip_ProcessSingleInterrupt(void);

#endif /*defined WKPU_ICU_SINGLE_INTERRUPT*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if (defined(WKPU_ICU_SINGLE_INTERRUPT) && (WKPU_ICU_SINGLE_INTERRUPT == STD_ON))
/*==================================================================================================*/
/**
* @brief      Wkpu_Icu_Ip_ProcessSingleInterrupt
* @details
*
* @param[in]      u8FirstHwChannel - first IRQ HW Channel from the HW group
*
* @retval None
* @implements Wkpu_Ip_ProcessSingleInterrupt_Activity
*/
static inline void Wkpu_Icu_Ip_ProcessSingleInterrupt(void)
{
    uint8  u8WkpuChannel    = 0x0U;
    uint32 u32ChannelMask   = 0x1U;
    uint32 u32reg_WKPU_WISR = Wkpu_Ip_pBase[0U]->WISR;
    uint32 u32reg_WKPU_WIER = Wkpu_Ip_pBase[0U]->IRER;
    
    /* Select which channels will be serviced - only the enabled irq ones*/
    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for (u8WkpuChannel = 0; u8WkpuChannel < (uint32)WKPU_IP_NUM_OF_CHANNELS_IN_ONE_REG; u8WkpuChannel++)
    {
        if (0x0U != (u32reg_WKPU_WISR & u32ChannelMask))
        {
            /* Clear pending interrupt serviced */
            Wkpu_Ip_pBase[0U]->WISR = u32reg_WKPU_WISR & u32ChannelMask;
            
            Wkpu_Ip_Callback(u8WkpuChannel);
        }
        u32ChannelMask <<= (uint32)1U;
    }

#ifdef WKPU_IP_64_CH_USED
    /*Get  WKPU32 - WKPU63 interrupt status flag*/
    u8WkpuChannel = 0x0U;
    u32ChannelMask   = 0x1U;
    u32reg_WKPU_WISR = Wkpu_Ip_pBase[0U]->WISR_64;
    u32reg_WKPU_WIER = Wkpu_Ip_pBase[0U]->IRER_64;

    /* Select which channels will be serviced - only the enabled irq ones*/
    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for (u8WkpuChannel = 0; u8WkpuChannel < (uint32)WKPU_IP_NUM_OF_CHANNELS_IN_ONE_REG; u8WkpuChannel++)
    {
        if (0x0U != (u32reg_WKPU_WISR & u32ChannelMask))
        {
            /* Clear pending interrupt serviced */
            Wkpu_Ip_pBase[0U]->WISR_64 = u32reg_WKPU_WISR & u32ChannelMask;
    
            Wkpu_Ip_Callback(u8WkpuChannel+ 32U);
        }
        u32ChannelMask <<= (uint32)1U;
    }
#endif
}
#endif /*defined WKPU_ICU_SINGLE_INTERRUPT*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (defined(WKPU_ICU_SINGLE_INTERRUPT) && (WKPU_ICU_SINGLE_INTERRUPT == STD_ON))
/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 0 to 31
* @details   Process the interrupt of WKPU channels 0 to 31 for platforms with only one interrupt line
*
* @remarks   This will be defined only if any of WKPU channels 0 to 31 are configured
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_SINGLE_ISR)
{
    Wkpu_Icu_Ip_ProcessSingleInterrupt();
}
#endif   /* defined WKPU_ICU_SINGLE_INTERRUPT */

#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)

#if (defined(WKPU_ICU_SINGLE_INTERRUPT) && (WKPU_ICU_SINGLE_INTERRUPT == STD_ON))
static inline void Wkpu_Ip_Callback(uint8 hwChannel)
{
    if(((boolean)TRUE == Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].chInit) && \
       (NULL_PTR != Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].callback))
    {
        Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].callback(Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].callbackParam, FALSE);
    }
    else
    {
        /* Calling Notification for the IPL channel */
        if (((boolean)TRUE == Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].chInit) && \
            (NULL_PTR != Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[(uint8)hwChannel]].WkpuChannelNotification) && \
            ((boolean)TRUE == Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].notificationEnable))
        {
            Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[(uint8)hwChannel]].WkpuChannelNotification();
        }
    }
}
#endif
#endif /* WKPU_DERIVATIVE_SUPPORT_ONLY_NMI */

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

