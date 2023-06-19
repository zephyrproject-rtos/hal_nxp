/*
 * Copyright 2020-2023 NXP
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
#include "StandardTypes.h"
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
#define ADC_SAR_IP_SW_MAJOR_VERSION_HWACCESS               3
#define ADC_SAR_IP_SW_MINOR_VERSION_HWACCESS               0
#define ADC_SAR_IP_SW_PATCH_VERSION_HWACCESS               0

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
/* Check if Adc_Sar_Ip_HwAccess.h file and StandardTypes.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and StandardTypes.h are different"
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
extern ADC_Type * const Adc_Sar_Ip_apxAdcBase[ADC_INSTANCE_COUNT];
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
extern SAR_ADC_AE_Type * const Adc_Sar_AE_Ip_apxAdcBase[SAR_ADC_AE_INSTANCE_COUNT];
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
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

/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_Powerup
 * Description   : Turning on power to the analog portion of ADC
 *
 *END*************************************************************************/
static inline void Adc_Sar_Powerup(const uint32 Instance)
{
    ADC_Type * AdcBasePtr = NULL_PTR;
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    SAR_ADC_AE_Type * AdcAEBasePtr = NULL_PTR;
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */

#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    if (Instance >= ADC_INSTANCE_COUNT)
    {
        AdcAEBasePtr = Adc_Sar_AE_Ip_apxAdcBase[Instance - ADC_INSTANCE_COUNT];
        AdcAEBasePtr->MCR &= ~(ADC_MCR_PWDN(1u));
    }
    else
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    {
        AdcBasePtr = Adc_Sar_Ip_apxAdcBase[Instance];
        AdcBasePtr->MCR &= ~(ADC_MCR_PWDN(1u));
    }
}

/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_Powerdown
 * Description   : Turning off power to the analog portion of ADC
 *
 *END*************************************************************************/
static inline void Adc_Sar_Powerdown(const uint32 Instance)
{
    ADC_Type * AdcBasePtr = NULL_PTR;
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    SAR_ADC_AE_Type * AdcAEBasePtr = NULL_PTR;
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */

#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    if (Instance >= ADC_INSTANCE_COUNT)
    {
        AdcAEBasePtr = Adc_Sar_AE_Ip_apxAdcBase[Instance - ADC_INSTANCE_COUNT];
        AdcAEBasePtr->MCR |= ADC_MCR_PWDN(1u);
    }
    else
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    {
        AdcBasePtr = Adc_Sar_Ip_apxAdcBase[Instance];
        AdcBasePtr->MCR |= ADC_MCR_PWDN(1u);
    }
}

#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
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
    Amsio &= ~(ADC_AMSIO_HSEN_MASK);
    Amsio |= ADC_AMSIO_HSEN(Enable ? 3u : 0u);
    Base->AMSIO = Amsio;
}
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */

/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_WriteThresholds
 * Description   : Write Watchdog low, high thresholds for a wdog register
 *
 *END*************************************************************************/
static inline void Adc_Sar_WriteThresholds(const uint32 Instance,
                                           const uint8 RegisterNumber,
                                           const uint16 HighThreshold,
                                           const uint16 LowThreshold)
{
    ADC_Type * AdcBasePtr = NULL_PTR;
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    SAR_ADC_AE_Type * AdcAEBasePtr = NULL_PTR;
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
#if !ADC_SAR_IP_HAS_THRHLR_ARRAY
    volatile uint32 * THRHLR0Addr = NULL_PTR;
    volatile uint32 * THRHLR1Addr = NULL_PTR;
    volatile uint32 * THRHLR2Addr = NULL_PTR;
    volatile uint32 * THRHLR3Addr = NULL_PTR;
    volatile uint32 * THRHLR4Addr = NULL_PTR;
    volatile uint32 * THRHLR5Addr = NULL_PTR;
#if ((ADC_SAR_IP_THRHLR_COUNT > 6U) || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
    volatile uint32 * THRHLR6Addr = NULL_PTR;
    volatile uint32 * THRHLR7Addr = NULL_PTR;
#if ((ADC_SAR_IP_THRHLR_COUNT > 8U) || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
    volatile uint32 * THRHLR8Addr = NULL_PTR;
    volatile uint32 * THRHLR9Addr = NULL_PTR;
    volatile uint32 * THRHLR10Addr = NULL_PTR;
    volatile uint32 * THRHLR11Addr = NULL_PTR;
#if ((ADC_SAR_IP_THRHLR_COUNT > 12U) || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
    volatile uint32 * THRHLR12Addr = NULL_PTR;
    volatile uint32 * THRHLR13Addr = NULL_PTR;
    volatile uint32 * THRHLR14Addr = NULL_PTR;
    volatile uint32 * THRHLR15Addr = NULL_PTR;
#endif /* ((ADC_SAR_IP_THRHLR_COUNT > 12U) || ...) */
#endif /* ((ADC_SAR_IP_THRHLR_COUNT > 8U) || ...) */
#endif /* ((ADC_SAR_IP_THRHLR_COUNT > 6U) || ...) */
#endif /* !ADC_SAR_IP_HAS_THRHLR_ARRAY */

#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    if (Instance >= ADC_INSTANCE_COUNT)
    {
        AdcAEBasePtr = Adc_Sar_AE_Ip_apxAdcBase[Instance - ADC_INSTANCE_COUNT];
    }
    else
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    {
        AdcBasePtr = Adc_Sar_Ip_apxAdcBase[Instance];
    }

#if !ADC_SAR_IP_HAS_THRHLR_ARRAY
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    if (Instance >= ADC_INSTANCE_COUNT)
    {
        THRHLR0Addr = &(AdcAEBasePtr->THRHLR0);
        THRHLR1Addr = &(AdcAEBasePtr->THRHLR1);
        THRHLR2Addr = &(AdcAEBasePtr->THRHLR2);
        THRHLR3Addr = &(AdcAEBasePtr->THRHLR3);
        THRHLR4Addr = &(AdcAEBasePtr->THRHLR4);
        THRHLR5Addr = &(AdcAEBasePtr->THRHLR5);
        THRHLR6Addr = &(AdcAEBasePtr->THRHLR6);
        THRHLR7Addr = &(AdcAEBasePtr->THRHLR7);
        THRHLR8Addr = &(AdcAEBasePtr->THRHLR8);
        THRHLR9Addr = &(AdcAEBasePtr->THRHLR9);
        THRHLR10Addr = &(AdcAEBasePtr->THRHLR10);
        THRHLR11Addr = &(AdcAEBasePtr->THRHLR11);
        THRHLR12Addr = &(AdcAEBasePtr->THRHLR12);
        THRHLR13Addr = &(AdcAEBasePtr->THRHLR13);
        THRHLR14Addr = &(AdcAEBasePtr->THRHLR14);
        THRHLR15Addr = &(AdcAEBasePtr->THRHLR15);
    }
    else
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    {
        THRHLR0Addr = &(AdcBasePtr->THRHLR0);
        THRHLR1Addr = &(AdcBasePtr->THRHLR1);
        THRHLR2Addr = &(AdcBasePtr->THRHLR2);
        THRHLR3Addr = &(AdcBasePtr->THRHLR3);
        THRHLR4Addr = &(AdcBasePtr->THRHLR4);
        THRHLR5Addr = &(AdcBasePtr->THRHLR5);
#if (ADC_SAR_IP_THRHLR_COUNT > 6U)
        THRHLR6Addr = &(AdcBasePtr->THRHLR6);
        THRHLR7Addr = &(AdcBasePtr->THRHLR7);
#if (ADC_SAR_IP_THRHLR_COUNT > 8U)
        THRHLR8Addr = &(AdcBasePtr->THRHLR8);
        THRHLR9Addr = &(AdcBasePtr->THRHLR9);
        THRHLR10Addr = &(AdcBasePtr->THRHLR10);
        THRHLR11Addr = &(AdcBasePtr->THRHLR11);
#if (ADC_SAR_IP_THRHLR_COUNT > 12U)
        THRHLR12Addr = &(AdcBasePtr->THRHLR12);
        THRHLR13Addr = &(AdcBasePtr->THRHLR13);
        THRHLR14Addr = &(AdcBasePtr->THRHLR14);
        THRHLR15Addr = &(AdcBasePtr->THRHLR15);
#endif /* (ADC_SAR_IP_THRHLR_COUNT > 12U) */
#endif /* (ADC_SAR_IP_THRHLR_COUNT > 8U) */
#endif /* (ADC_SAR_IP_THRHLR_COUNT > 6U) */
    }
#endif /* ADC_SAR_IP_HAS_THRHLR_ARRAY */

#if ADC_SAR_IP_HAS_THRHLR_ARRAY
#if (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(RegisterNumber < ADC_SAR_IP_THRHLR_COUNT);
#endif /* (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON) */
    uint32 Value = ADC_THRHLR_THRH(HighThreshold) |
                     ADC_THRHLR_THRL(LowThreshold);
    AdcBasePtr->THRHLR[RegisterNumber] = Value;

#else /* ADC_SAR_IP_HAS_THRHLR_ARRAY == 0 */

    uint32 Value = ADC_THRHLR0_THRH(HighThreshold) |
                     ADC_THRHLR0_THRL(LowThreshold);
    switch (RegisterNumber)
    {
        case 0:
            *THRHLR0Addr = Value;
            break;
        case 1:
            *THRHLR1Addr = Value;
            break;
        case 2:
            *THRHLR2Addr = Value;
            break;
        case 3:
            *THRHLR3Addr = Value;
            break;
        case 4:
            *THRHLR4Addr = Value;
            break;
        case 5:
            *THRHLR5Addr = Value;
            break;
#if ((ADC_SAR_IP_THRHLR_COUNT > 6U) || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
        case 6:
            *THRHLR6Addr = Value;
            break;
        case 7:
            *THRHLR7Addr = Value;
            break;
#if ((ADC_SAR_IP_THRHLR_COUNT > 8U) || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
        case 8:
            *THRHLR8Addr = Value;
            break;
        case 9:
            *THRHLR9Addr = Value;
            break;
        case 10:
            *THRHLR10Addr = Value;
            break;
        case 11:
            *THRHLR11Addr = Value;
            break;
#if ((ADC_SAR_IP_THRHLR_COUNT > 12U) || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
        case 12:
            *THRHLR12Addr = Value;
            break;
        case 13:
            *THRHLR13Addr = Value;
            break;
        case 14:
            *THRHLR14Addr = Value;
            break;
        case 15:
            *THRHLR15Addr = Value;
            break;
#endif /* ((ADC_SAR_IP_THRHLR_COUNT > 12U) || ...) */
#endif /* ((ADC_SAR_IP_THRHLR_COUNT > 8U) || ...) */
#endif /* ((ADC_SAR_IP_THRHLR_COUNT > 6U) || ...) */
        default:
            ; /* no-op */
            break;
    }
#endif /* ADC_SAR_IP_HAS_THRHLR_ARRAY */
}

#if (ADC_SAR_IP_HAS_CWSELR_UNROLLED == 1u)
/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_GetChannelWatchdogAddress
 * Description   : Returns the address of the specified CWSELR register
 *
 *END*************************************************************************/
static inline volatile uint32 * Adc_Sar_GetChannelWatchdogAddress(const uint32 Instance,
                                                                  const uint32 RegisterNumber)
{
    ADC_Type * AdcBasePtr = NULL_PTR;
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    SAR_ADC_AE_Type * AdcAEBasePtr = NULL_PTR;
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    volatile uint32 * CwselrAddr = NULL_PTR;
#if (ADC_SAR_IP_HAS_CWSELR0 || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
    volatile uint32 * CWSELR0Addr = NULL_PTR;
#endif /* (ADC_SAR_IP_HAS_CWSELR0 || FEATURE_ADC_HAS_APPLICATION_EXTENSION) */
#if (ADC_SAR_IP_HAS_CWSELR1 || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
    volatile uint32 * CWSELR1Addr = NULL_PTR;
#endif /* (ADC_SAR_IP_HAS_CWSELR1 || FEATURE_ADC_HAS_APPLICATION_EXTENSION) */
#if (ADC_SAR_IP_HAS_CWSELR2 || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
    volatile uint32 * CWSELR2Addr = NULL_PTR;
#endif /* (ADC_SAR_IP_HAS_CWSELR2 || FEATURE_ADC_HAS_APPLICATION_EXTENSION) */

#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    if (Instance >= ADC_INSTANCE_COUNT)
    {
        AdcAEBasePtr = Adc_Sar_AE_Ip_apxAdcBase[Instance - ADC_INSTANCE_COUNT];
        CWSELR0Addr = &(AdcAEBasePtr->CWSELR0);
        CWSELR1Addr = &(AdcAEBasePtr->CWSELR1);
        CWSELR2Addr = &(AdcAEBasePtr->CWSELR2);
    }
    else
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    {
        AdcBasePtr = Adc_Sar_Ip_apxAdcBase[Instance];
#if ADC_SAR_IP_HAS_CWSELR0
        CWSELR0Addr = &(AdcBasePtr->CWSELR0);
#endif /* ADC_SAR_IP_HAS_CWSELR0 */
#if ADC_SAR_IP_HAS_CWSELR1
        CWSELR1Addr = &(AdcBasePtr->CWSELR1);
#endif /* ADC_SAR_IP_HAS_CWSELR1 */
#if ADC_SAR_IP_HAS_CWSELR2
        CWSELR2Addr = &(AdcBasePtr->CWSELR2);
#endif /* ADC_SAR_IP_HAS_CWSELR2 */
    }

    switch (RegisterNumber)
    {
#if (ADC_SAR_IP_HAS_CWSELR0 || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
        case 0u:
            CwselrAddr = CWSELR0Addr;
            break;
#endif /* (ADC_SAR_IP_HAS_CWSELR0 || FEATURE_ADC_HAS_APPLICATION_EXTENSION) */
#if (ADC_SAR_IP_HAS_CWSELR1 || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
        case 1u:
            CwselrAddr = CWSELR1Addr;
            break;
#endif /* (ADC_SAR_IP_HAS_CWSELR1 || FEATURE_ADC_HAS_APPLICATION_EXTENSION) */
#if (ADC_SAR_IP_HAS_CWSELR2 || FEATURE_ADC_HAS_APPLICATION_EXTENSION)
        case 2u:
            CwselrAddr = CWSELR2Addr;
            break;
#endif /* (ADC_SAR_IP_HAS_CWSELR2 || FEATURE_ADC_HAS_APPLICATION_EXTENSION) */
#if ADC_SAR_IP_HAS_CWSELR3
        case 3u:
            CwselrAddr = &(AdcBasePtr->CWSELR3);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR3 */
#if ADC_SAR_IP_HAS_CWSELR4
        case 4u:
            CwselrAddr = &(AdcBasePtr->CWSELR4);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR4 */
#if ADC_SAR_IP_HAS_CWSELR5
        case 5u:
            CwselrAddr = &(AdcBasePtr->CWSELR5);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR5 */
#if ADC_SAR_IP_HAS_CWSELR6
        case 6u:
            CwselrAddr = &(AdcBasePtr->CWSELR6);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR6 */
#if ADC_SAR_IP_HAS_CWSELR7
        case 7u:
            CwselrAddr = &(AdcBasePtr->CWSELR7);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR7 */
#if ADC_SAR_IP_HAS_CWSELR8
        case 8u:
            CwselrAddr = &(AdcBasePtr->CWSELR8);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR8 */
#if ADC_SAR_IP_HAS_CWSELR9
        case 9u:
            CwselrAddr = &(AdcBasePtr->CWSELR9);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR9 */
#if ADC_SAR_IP_HAS_CWSELR10
        case 10u:
            CwselrAddr = &(AdcBasePtr->CWSELR10);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR10 */
#if ADC_SAR_IP_HAS_CWSELR11
        case 11u:
            CwselrAddr = &(AdcBasePtr->CWSELR11);
            break;
#endif /* ADC_SAR_IP_HAS_CWSELR11 */
        default:
            ; /* the RegisterNumber does not exist */
#if (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }

    return CwselrAddr;
}
#endif /* ADC_SAR_IP_HAS_CWSELR_UNROLLED == 1 */

#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_WriteChannelMapping
 * Description   :
 *
 *END*************************************************************************/
static inline void Adc_Sar_WriteChannelMapping(const uint32 Instance,
                                               const uint32 RegisterNumber,
                                               const uint32 FieldPosition,
                                               const uint32 Value)
{
    uint32 CwselrVal;
    uint32 CwselrMask;
    uint32 CwselrShift;

#if (ADC_SAR_IP_HAS_CWSELR_UNROLLED == 1u)
    volatile uint32 * Cwselr = Adc_Sar_GetChannelWatchdogAddress(Instance, RegisterNumber);

    /* Each CWSELR register contains 8 watchdog selections according to 8 channels
       Each watchdog selection possibly needs maximum 4 bits for setting */
    CwselrShift = FieldPosition * ADC_CWSELR0_WSEL_CH1_SHIFT;
    CwselrMask = (uint32)ADC_CWSELR0_WSEL_CH0_MASK << CwselrShift;
    CwselrVal  = (*Cwselr) & (~CwselrMask);
    CwselrVal |= ADC_CWSELR0_WSEL_CH0(Value) << CwselrShift;
    *Cwselr      = CwselrVal;
#else /* ADC_SAR_IP_HAS_CWSELR_UNROLLED == 0 */
    ADC_Type * const AdcBasePtr = Adc_Sar_Ip_apxAdcBase[Instance];

    CwselrShift = FieldPosition * ADC_CWSELR_WSEL_CH1_SHIFT;
    CwselrMask = (uint32)ADC_CWSELR_WSEL_CH0_MASK << CwselrShift;
    CwselrVal  = CWSELR(AdcBasePtr, RegisterNumber) & (~CwselrMask);
    CwselrVal |= ADC_CWSELR_WSEL_CH0(Value) << CwselrShift;
    CWSELR(AdcBasePtr, RegisterNumber) = CwselrVal;
#endif /* (ADC_SAR_IP_HAS_CWSELR_UNROLLED == 1u) */
}
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */

static inline void Adc_Sar_ResetWdogCWSELR(const uint32 Instance, const uint8 RegisterNumber)
{
#if (ADC_SAR_IP_HAS_CWSELR_UNROLLED == 1u)
    volatile uint32 * Cwselr = Adc_Sar_GetChannelWatchdogAddress(Instance, (uint32)RegisterNumber);

    *Cwselr = 0U;
#else /* ADC_SAR_IP_HAS_CWSELR_UNROLLED == 0 */
    ADC_Type * const AdcBasePtr = Adc_Sar_Ip_apxAdcBase[Instance];

    CWSELR(AdcBasePtr, RegisterNumber) = 0u;
#endif /* (ADC_SAR_IP_HAS_CWSELR_UNROLLED == 1u) */
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_HW_ACCESS_H */
