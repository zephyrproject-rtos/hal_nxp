/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup adc_sar_ip Adc Sar IPL
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
#include "OsIf.h"
#include "Adc_Sar_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_IRQ_C                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       9
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_IRQ_C               0
#define ADC_SAR_IP_SW_MINOR_VERSION_IRQ_C               8
#define ADC_SAR_IP_SW_PATCH_VERSION_IRQ_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Sar_Ip_Irq.c file and OsIf.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Irq.c and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Adc_Sar_Ip_Irq.c file and Adc_Sar_Ip_Irq.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_IRQ_C != ADC_SAR_IP_VENDOR_ID_IRQ)
    #error "Adc_Sar_Ip_Irq.c and Adc_Sar_Ip_Irq.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Irq.c file and Adc_Sar_Ip_Irq.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Irq.c and Adc_Sar_Ip_Irq.h are different"
#endif

/* Check if Adc_Sar_Ip_Irq.c file and Adc_Sar_Ip_Irq.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_IRQ_C != ADC_SAR_IP_SW_MAJOR_VERSION_IRQ) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_IRQ_C != ADC_SAR_IP_SW_MINOR_VERSION_IRQ) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_IRQ_C != ADC_SAR_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Irq.c and Adc_Sar_Ip_Irq.h are different"
#endif

#if (ADC_SAR_IP_IS_USED == STD_ON)

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_SAR_IP_INSTANCE_COUNT >= 1U)
ISR(Adc_Sar_0_Isr)
{
    /* Call IRQ handler with the correct instance */
    Adc_Sar_Ip_IRQHandler(0UL);
}
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 1U) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 2U)
ISR(Adc_Sar_1_Isr)
{
    /* Call IRQ handler with the correct instance */
    Adc_Sar_Ip_IRQHandler(1UL);
}
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 2U) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 3U)
ISR(Adc_Sar_2_Isr)
{
    /* Call IRQ handler with the correct instance */
    Adc_Sar_Ip_IRQHandler(2UL);
}
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 3U) */


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#endif /* (ADC_SAR_IP_IS_USED == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
