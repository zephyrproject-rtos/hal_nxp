/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_HW_ACCESS_H
#define ADC_SAR_IP_HW_ACCESS_H

/**
*   @file
*
*   @internal
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
#include "Std_Types.h"
#include "Adc_Sar_Ip_CfgDefines.h"

#if (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif /* (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_HWACCESS                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HWACCESS    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_HWACCESS               2
#define ADC_SAR_IP_SW_MINOR_VERSION_HWACCESS               0
#define ADC_SAR_IP_SW_PATCH_VERSION_HWACCESS               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_HwAccess.h file and Adc_Sar_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_HWACCESS != ADC_SAR_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Sar_Ip_HwAccess.h and Adc_Sar_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_HwAccess.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HWACCESS != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Sar_Ip_HwAccess.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_HWACCESS != ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_HWACCESS != ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_HWACCESS != ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_HwAccess.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Sar_Ip_HwAccess.h file and Std_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and Std_Types.h are different"
#endif

#if (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON)
/* Check if Adc_Sar_Ip_HwAccess.h and Devassert.h are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and Devassert.h are different"
#endif
#endif /* (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Define the hardware register size when calculating bit positions */
#define ADC_SAR_IP_HW_REG_SIZE (32u)

/* Definitions to compute bit positions from channel index */
#define ADC_SAR_IP_CHAN_2_VECT(CHNIDX) ((CHNIDX) / ADC_SAR_IP_HW_REG_SIZE)
#define ADC_SAR_IP_CHAN_2_BIT(CHNIDX)  ((CHNIDX) % ADC_SAR_IP_HW_REG_SIZE)
/*==================================================================================================
                                     FUNCTION DEFINITIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if ADC_SAR_IP_HIGH_SPEED_ENABLE_AVAILABLE
/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_EnableHighSpeed
 * Description   : Enable a high-speed calibration or a high-speed conversion
 *
 *END*************************************************************************/
static inline void Adc_Sar_EnableHighSpeed(ADC_Type * const Base,
                                           boolean Enable)
{
    uint32 Amsio = Base->AMSIO;

    Amsio &= ~(ADC_AMSIO_HSEN_MASK | ADC_AMSIO_CMPCTRL0_MASK);
    if (TRUE == Enable)
    {
        Amsio |= (ADC_AMSIO_HSEN(1u) | ADC_AMSIO_CMPCTRL0(1u));
    }

    Base->AMSIO = Amsio;
}
#endif /* ADC_SAR_IP_HIGH_SPEED_ENABLE_AVAILABLE */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_HW_ACCESS_H */
