/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
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
#include "SchM_Icu.h"
#include "StandardTypes.h"
#include "Siul2_Icu_Ip.h"
#include "Siul2_Icu_Ip_Irq.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IRQ_VENDOR_ID_C                      43
#define SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define SIUL2_ICU_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define SIUL2_ICU_IRQ_SW_MAJOR_VERSION_C               0
#define SIUL2_ICU_IRQ_SW_MINOR_VERSION_C               8
#define SIUL2_ICU_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and StandardTypes.h are different"
    #endif

    /* Check if header file and SchM_Icu.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and SchM_Icu.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IRQ_VENDOR_ID_C != SIUL2_ICU_IP_VENDOR_ID)
    #error "Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IRQ_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IRQ_VENDOR_ID_C != SIUL2_ICU_IP_IRQ_VENDOR_ID)
    #error "Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip_Irq.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip_Irq.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IRQ_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_IRQ_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_IRQ_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

extern Siul2_Icu_Ip_State Siul2_Icu_Ip_aChannelState[SIUL2_ICU_IP_NUM_OF_INSTANCES][SIUL2_ICU_IP_NUM_OF_CHANNELS];

#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if ( (defined SIUL2_0_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_1_ICU_EIRQ_SINGLE_INT) || \
      (defined SIUL2_4_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_5_ICU_EIRQ_SINGLE_INT) || \
      (defined SIUL2_AE_ICU_EIRQ_SINGLE_INT))
/**
 * @brief 
 * 
 * @param instance 
 * @implements Siul2_Icu_Ip_ProcessSingleInterrupt_Activity
 */
static inline void Siul2_Icu_Ip_ProcessSingleInterrupt(uint8 instance);
#endif

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED)  || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
static inline void Siul2_Icu_Ip_ProcessInterrupt(uint8 instance, uint8 firstHwChannel);
#endif

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED)  || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED) \
    || (defined SIUL2_0_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_1_ICU_EIRQ_SINGLE_INT) \
    || (defined SIUL2_4_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_5_ICU_EIRQ_SINGLE_INT) \
    || (defined SIUL2_AE_ICU_EIRQ_SINGLE_INT))
/**
 * @brief 
 * 
 * @param instance 
 * @param hwChannel 
 */
static inline void Siul2_Icu_Ip_ReportEvents(uint8 instance, uint8 hwChannel);
#endif
/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#if ( (defined SIUL2_0_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_1_ICU_EIRQ_SINGLE_INT) || \
      (defined SIUL2_4_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_5_ICU_EIRQ_SINGLE_INT) || \
      (defined SIUL2_AE_ICU_EIRQ_SINGLE_INT))
static inline void Siul2_Icu_Ip_ProcessSingleInterrupt(uint8 instance)
{
    uint8  u8IrqChannel    = 0U;
    uint32 u32RegIrqMask   = 0U;
    uint32 u32ChannelMask  = 1U;
    uint32 u32RegFlags = Siul2_Icu_Ip_pBase[instance]->DISR0;
    uint32 u32RegIrqEn = Siul2_Icu_Ip_pBase[instance]->DIRER0;
    
    /* Select which channels will be serviced - only the enabled irq ones*/
    u32RegIrqMask = u32RegFlags & u32RegIrqEn;

    for (u8IrqChannel = 0; u8IrqChannel < SIUL2_ICU_IP_NUM_OF_CHANNELS; u8IrqChannel++)
    {
        if (0x0U != (u32RegIrqMask & u32ChannelMask))
        {
            /* Clear pending interrupt serviced */
            Siul2_Icu_Ip_pBase[instance]->DISR0 = u32RegFlags;
    
            Siul2_Icu_Ip_ReportEvents(instance, u8IrqChannel);
        }
        u32ChannelMask <<= (uint32)1U;
    }
}
#endif /* All single interrupt cases. */

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED)  || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
/** @implements Siul2_Icu_Ip_ProcessInterrupt_Activity */
static inline void Siul2_Icu_Ip_ProcessInterrupt(uint8 instance, uint8 firstHwChannel)
{
    uint8  u8IrqChannel    = firstHwChannel;
    uint32 u32RegIrqMask   = (uint32)0xFFU << (uint32)firstHwChannel;
    uint32 u32ChannelMask  = (uint32)1U << (uint32)firstHwChannel;

    uint32 u32RegFlags = (Siul2_Icu_Ip_pBase[instance])->DISR0;
    uint32 u32RegIrqEn = (Siul2_Icu_Ip_pBase[instance])->DIRER0;

    /* Select which channels will be serviced - only the enabled irq ones*/
    u32RegIrqMask = u32RegFlags & u32RegIrqEn & u32RegIrqMask;

    for (u8IrqChannel = firstHwChannel; u8IrqChannel < (firstHwChannel + 8U); u8IrqChannel++)
    {
        if (0x0U != (u32RegIrqMask & u32ChannelMask))
        {
            /* Clear pending interrupt serviced */
            (Siul2_Icu_Ip_pBase[instance])->DISR0 = u32RegFlags & u32RegIrqMask;
            
            Siul2_Icu_Ip_ReportEvents(instance, u8IrqChannel);
        }
        u32ChannelMask <<= (uint32)1U;
    }
}
#endif

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED)  || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED) \
    || (defined SIUL2_0_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_1_ICU_EIRQ_SINGLE_INT) \
    || (defined SIUL2_4_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_5_ICU_EIRQ_SINGLE_INT) \
    || (defined SIUL2_AE_ICU_EIRQ_SINGLE_INT))
static inline void Siul2_Icu_Ip_ReportEvents(uint8 instance, uint8 hwChannel)
{
    /* Calling HLD Report Events for the logical channel. */
    if (Siul2_Icu_Ip_aChannelState[instance][hwChannel].callback != NULL_PTR)
    {
        Siul2_Icu_Ip_aChannelState[instance][hwChannel].callback(Siul2_Icu_Ip_aChannelState[instance][hwChannel].callbackParam, FALSE);
    }
    else
    {
        /* Calling Notification for the IPL channel. */
        if ((NULL_PTR != Siul2_Icu_Ip_aChannelState[instance][hwChannel].Siul2ChannelNotification) && \
            ((boolean)TRUE == Siul2_Icu_Ip_aChannelState[instance][hwChannel].notificationEnable))
        {
            Siul2_Icu_Ip_aChannelState[instance][hwChannel].Siul2ChannelNotification();
        }
    }
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if (defined(SIUL2_0_ICU_EIRQ_SINGLE_INT))
ISR(SIUL2_0_ICU_EIRQ_SINGLE_INT_HANDLER)
{
    /*calling process interrupt function of corressponding instance*/
    Siul2_Icu_Ip_ProcessSingleInterrupt(0U);
}
#endif /* SIUL2_0_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_1_ICU_EIRQ_SINGLE_INT))
ISR(SIUL2_1_ICU_EIRQ_SINGLE_INT_HANDLER)
{
    /*calling process interrupt function of corressponding instance*/
    Siul2_Icu_Ip_ProcessSingleInterrupt(1U);
}
#endif /* SIUL2_1_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_4_ICU_EIRQ_SINGLE_INT))
ISR(SIUL2_4_ICU_EIRQ_SINGLE_INT_HANDLER)
{
    /*calling process interrupt function of corressponding instance*/
    Siul2_Icu_Ip_ProcessSingleInterrupt(4U);
}
#endif /* SIUL2_4_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_5_ICU_EIRQ_SINGLE_INT))
ISR(SIUL2_5_ICU_EIRQ_SINGLE_INT_HANDLER)
{
    /*calling process interrupt function of corressponding instance*/
    Siul2_Icu_Ip_ProcessSingleInterrupt(5U);
}
#endif /* SIUL2_5_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_AE_ICU_EIRQ_SINGLE_INT))
ISR(SIUL2_AE_ICU_EIRQ_SINGLE_INT_HANDLER)
{
    /*calling process interrupt function of corressponding instance*/
    Siul2_Icu_Ip_ProcessSingleInterrupt(6U);
}
#endif /* SIUL2_AE_ICU_EIRQ_SINGLE_INT */

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED))
ISR(SIUL2_EXT_IRQ_0_7_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_0);
}
#endif  /* IRQ 0 - 7 */

#if ((defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED))
ISR(SIUL2_EXT_IRQ_8_15_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_8);
}
#endif  /* IRQ 8 - 15 */

#if ((defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED))
ISR(SIUL2_EXT_IRQ_16_23_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_16);
}
#endif

#if ((defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
ISR(SIUL2_EXT_IRQ_24_31_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_24);
}
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
