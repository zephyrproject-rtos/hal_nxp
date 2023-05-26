/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_IRQ_H
#define SIUL2_ICU_IP_IRQ_H

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
#include "OsIf.h"
#include "Siul2_Icu_Ip_Cfg.h"
#include "Siul2_Icu_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_IRQ_VENDOR_ID                    43
#define SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION     4
#define SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION     7
#define SIUL2_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION  0
#define SIUL2_ICU_IP_IRQ_SW_MAJOR_VERSION             3
#define SIUL2_ICU_IP_IRQ_SW_MINOR_VERSION             0
#define SIUL2_ICU_IP_IRQ_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and OsIf.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.h and OsIf.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_IRQ_VENDOR_ID != SIUL2_ICU_IP_TYPES_VENDOR_ID)
    #error "Siul2_Icu_Ip_Irq.h and Siul2_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.h and Siul2_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_IRQ_SW_MAJOR_VERSION  != SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_SW_MINOR_VERSION  != SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_SW_PATCH_VERSION  != SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip_Irq.h and Siul2_Icu_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_IRQ_VENDOR_ID != SIUL2_ICU_IP_CFG_VENDOR_ID)
    #error "Siul2_Icu_Ip_Irq.h and Siul2_Icu_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.h and Siul2_Icu_Ip_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_IRQ_SW_MAJOR_VERSION  != SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_SW_MINOR_VERSION  != SIUL2_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_IRQ_SW_PATCH_VERSION  != SIUL2_ICU_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip_Irq.h and Siul2_Icu_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

/** @brief SIUL2 External Interrupt Channels defines. */
#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED))

#define SIUL2_ICU_IRQ_0    ((uint8) 0U)

#endif 

#if ((defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED))
   
#define SIUL2_ICU_IRQ_8    ((uint8) 8U)

#endif

#if ((defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED))

#define SIUL2_ICU_IRQ_16   ((uint8)16U)

#endif

#if ((defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))

#define SIUL2_ICU_IRQ_24   ((uint8)24U)

#endif

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
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (defined(SIUL2_0_ICU_EIRQ_SINGLE_INT))
/**
 * @brief     Interrupt handler for SIUL2 instance 0.
 * @details   Process the interrupt of SIUL2 instance 0.
 * @isr
 * @note   This will be defined only if the single interrupt mode is configured.
 */
ISR(SIUL2_0_ICU_EIRQ_SINGLE_INT_HANDLER);
#endif /* SIUL2_0_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_1_ICU_EIRQ_SINGLE_INT))
/**
 * @brief     Interrupt handler for SIUL2 instance 1.
 * @details   Process the interrupt of SIUL2 instance 1.
 * @isr
 * @note   This will be defined only if the single interrupt mode is configured.
 */
ISR(SIUL2_1_ICU_EIRQ_SINGLE_INT_HANDLER);
#endif /* SIUL2_1_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_4_ICU_EIRQ_SINGLE_INT))
/**
 * @brief     Interrupt handler for SIUL2 instance 4.
 * @details   Process the interrupt of SIUL2 instance 4.
 * @isr
 * @note   This will be defined only if the single interrupt mode is configured.
 */
ISR(SIUL2_4_ICU_EIRQ_SINGLE_INT_HANDLER);
#endif /* SIUL2_4_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_5_ICU_EIRQ_SINGLE_INT))
/**
 * @brief     Interrupt handler for SIUL2 instance 5.
 * @details   Process the interrupt of SIUL2 instance 5.
 * @isr
 * @note   This will be defined only if the single interrupt mode is configured.
 */
ISR(SIUL2_5_ICU_EIRQ_SINGLE_INT_HANDLER);
#endif /* SIUL2_5_ICU_EIRQ_SINGLE_INT */

#if (defined(SIUL2_AE_ICU_EIRQ_SINGLE_INT))
/**
* @brief     Interrupt handler for SIUL2 instance AE.
* @details   Process the interrupt of SIUL2 instance AE.
* @isr
* @note   This will be defined only if the single interrupt mode is configured.
*/
ISR(SIUL2_AE_ICU_EIRQ_SINGLE_INT_HANDLER);
#endif /* SIUL2_AE_ICU_EIRQ_SINGLE_INT */

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED))
/**
 * @brief    Interrupt handler for SIUL2 channels: 0 to 7
 * @details  Process the interrupt of SIUL2 channels: 0 to 7
 *
 * @note     This will be defined only if any of SIUL2 channels 0 to 7 is configured.
 */
ISR(SIUL2_EXT_IRQ_0_7_ISR);
#endif

#if ((defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED))
/**
 * @brief    Interrupt handler for SIUL2 channels: 8 to 15.
 * @details  Process the interrupt of SIUL2 channels 8 to 15.
 *
 * @note     This will be defined only if any of SIUL channels 8 to 15 is configured.
 */
ISR(SIUL2_EXT_IRQ_8_15_ISR);
#endif

#if ((defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED))
/**
 * @brief    Interrupt handler for SIUL2 channels: 16 to 23.
 * @details  Process the interrupt of SIUL2 channels 16 to 23.
 *
 * @note     This will be defined only if any of SIUL2 channels 16 to 23 was configured.
 */
ISR(SIUL2_EXT_IRQ_16_23_ISR);
#endif

#if ((defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
/**
 * @brief   Interrupt handler for SIUL2 channels: 24 to 31.
 * @details Process the interrupt of SIUL2 channels 24 to 31
 *
 * @note    This will be defined only if any of SIUL2 channels 24 to 31 was configured.
 */
ISR(SIUL2_EXT_IRQ_24_31_ISR);
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_H */
