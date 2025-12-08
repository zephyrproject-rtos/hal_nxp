/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_IRQ_H
#define ADC_SAR_IP_IRQ_H

/**
*   @file
*
*   @addtogroup adc_sar_ip Adc Sar IPL
*   @{
*/
#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Adc_Sar_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_IRQ                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ       9
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_IRQ               0
#define ADC_SAR_IP_SW_MINOR_VERSION_IRQ               8
#define ADC_SAR_IP_SW_PATCH_VERSION_IRQ               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Sar_Ip_Irq.h file and Std_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Irq.h and Std_Types.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Adc_Sar_Ip_Irq.h file and Adc_Sar_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_IRQ != ADC_SAR_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Sar_Ip_Irq.h and Adc_Sar_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Irq.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Irq.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Sar_Ip_Irq.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_IRQ != ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_IRQ != ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_IRQ != ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Irq.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

#if (ADC_SAR_IP_IS_USED == STD_ON)

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
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_SAR_IP_INSTANCE_COUNT >= 1U)
ISR(Adc_Sar_0_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 1U) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 2U)
ISR(Adc_Sar_1_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 2U) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 3U)
ISR(Adc_Sar_2_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 3U) */


void Adc_Sar_Ip_IRQHandler(const uint32 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#endif /* (ADC_SAR_IP_IS_USED == STD_ON) */

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* ADC_SAR_IP_IRQ_H */
