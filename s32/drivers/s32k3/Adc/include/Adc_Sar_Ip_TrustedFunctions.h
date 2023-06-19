/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_TRUSTEDFUNCTIONS_H
#define ADC_SAR_IP_TRUSTEDFUNCTIONS_H

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
#include "Adc_Sar_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_TRUSTEDFUNCTIONS                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS               3
#define ADC_SAR_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS               0
#define ADC_SAR_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_TrustedFunctions.h file and Adc_Sar_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_TRUSTEDFUNCTIONS != ADC_SAR_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Sar_Ip_TrustedFunctions.h and Adc_Sar_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_TrustedFunctions.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_TrustedFunctions.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Sar_Ip_TrustedFunctions.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS != ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS != ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS != ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_TrustedFunctions.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_SAR_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief        Sets the UAA bit in REG_PROT to make the instance accessible in user mode
* @details      Sets the UAA bit in REG_PROT to make the instance accessible in user mode
*
* @param[in]    Instance    Adc instance index
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void Adc_Sar_Ip_SetUserAccessAllowed(const uint32 Instance);

/**
* @brief        Clears the UAA bit in REG_PROT to make the instance inaccessible in user mode.
* @details      Clears the UAA bit in REG_PROT to make the instance inaccessible in user mode.
*
* @param[in]    Instance    Adc instance index
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void Adc_Sar_Ip_ClrUserAccessAllowed(const uint32 Instance);

#endif /* (STD_ON == ADC_SAR_IP_ENABLE_USER_MODE_SUPPORT) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_TRUSTEDFUNCTIONS_H */
