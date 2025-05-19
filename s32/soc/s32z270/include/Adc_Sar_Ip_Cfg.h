/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_CFG_H
#define ADC_SAR_IP_CFG_H

/**
*   @file
*
*   @addtogroup adc_sar_ip_config Adc Sar IPL Configuration
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
#include "Adc_Sar_Ip_Types.h"
#include "Adc_Sar_Ip_Init_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_SAR_IP_VENDOR_ID_CFG                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFG       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFG       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFG    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_CFG               2
#define ADC_SAR_IP_SW_MINOR_VERSION_CFG               0
#define ADC_SAR_IP_SW_PATCH_VERSION_CFG               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_Cfg.h file and Adc_Sar_Ip_Types.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_CFG != ADC_SAR_IP_VENDOR_ID_TYPES)
    #error "Adc_Sar_Ip_Cfg.h and Adc_Sar_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Cfg.h file and Adc_Sar_Ip_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFG != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFG != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFG != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Cfg.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Sar_Ip_Cfg.h file and Adc_Sar_Ip_Types.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_CFG != ADC_SAR_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_CFG != ADC_SAR_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_CFG != ADC_SAR_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Cfg.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Sar_Ip_Cfg.h file and Adc_Sar_Ip_Init_PBcfg.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_CFG != ADC_SAR_IP_VENDOR_ID_INIT_PBCFG)
    #error "Adc_Sar_Ip_Cfg.h and Adc_Sar_Ip_Init_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Cfg.h file and Adc_Sar_Ip_Init_PBcfg.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFG != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFG != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFG != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Cfg.h and Adc_Sar_Ip_Init_PBcfg.h are different"
#endif

/* Check if Adc_Sar_Ip_Cfg.h file and Adc_Sar_Ip_Init_PBcfg.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_CFG != ADC_SAR_IP_SW_MAJOR_VERSION_INIT_PBCFG) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_CFG != ADC_SAR_IP_SW_MINOR_VERSION_INIT_PBCFG) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_CFG != ADC_SAR_IP_SW_PATCH_VERSION_INIT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Cfg.h and Adc_Sar_Ip_Init_PBcfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_CFG_H */

