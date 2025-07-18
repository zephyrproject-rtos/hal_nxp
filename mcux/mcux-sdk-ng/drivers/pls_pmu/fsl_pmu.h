/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef _FSL_PMU_H
#define _FSL_PMU_H


#include "fsl_common.h"


/*!
 * @addtogroup pls_pmu
 * @{
 */


/*******************************************************************************
* Definitions
******************************************************************************/


/*! @name Driver version */
/*@{*/
/*! @brief pls_pmu driver version 2.0.0. */
#define FSL_PMU_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief The enumeration of FRO16K output frequency.
 */
typedef enum _pmu_fro16k_output_freq
{
    kPMU_FRO16KOutput16KHz = 0x0U,  /*!< FRM16K output 16KHz. */
    kPMU_FRO16KOutput8KHz,          /*!< FRM16K output 8KHz. */
} pmu_fro16k_output_freq_t;


/*******************************************************************************
* API
******************************************************************************/


#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Enable/disable Fixed DCDC in active mode.
 * 
 * @param base PMU peripheral base address.
 * @param enable Specify the behavior of Fixed DCDC, true to enable, false to disable.
 */
static inline void PMU_EnableFixedDCDC(PMU_Type *base, bool enable)
{
    if (enable)
    {
        base->PCTRL |= PMU_PCTRL_VDDP_EN_MASK;
    }
    else
    {
        base->PCTRL &= ~PMU_PCTRL_VDDP_EN_MASK;
    }
}

/*!
 * @brief Update voltage of VDD_CORE in active mode.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update, LSB is 9.5mV.
 */
static inline void PMU_UpdateVDDCoreInActiveMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_PCONFIG = ((base->VDD_CORE_PCONFIG) & ~(PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_ACONFIG_MASK)) | \
                            PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_ACONFIG(value);
}

/*!
 * @brief Update voltage of VDD_CORE in low power modes.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update, LSB is 9.5mV.
 */
static inline void PMU_UpdateVDDCoreInLpMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_PCONFIG = ((base->VDD_CORE_PCONFIG) & ~(PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_VOUTSEL_LPWR_MASK)) | \
                            PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_VOUTSEL_LPWR(value);
}

/*!
 * @brief Update voltage of VDD_CORE_1P1 in active mode.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update.
 */
static inline void PMU_UpdateVDDCore1P1InActiveMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_1P1_CONFIG = ((base->VDD_CORE_1P1_CONFIG) & ~PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_ACONFIG_MASK) | \
                            PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_ACONFIG(value);
}

/*!
 * @brief Update voltage of VDD_CORE_1P1 in low power modes.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update.
 */
static inline void PMU_UpdateVDDCore1P1InLpMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_1P1_CONFIG = ((base->VDD_CORE_1P1_CONFIG) & ~PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_VOUTSEL_LPWR_MASK) | \
    PMU_VDD_CORE_1P1_CONFIG_VDD_CORE_1P1_VOUTSEL_LPWR(value);
}

/*!
 * @brief Enable/disable FRO16K.
 * 
 * @param base PMU peripheral base address.
 * @param enable Specify the behavior of FRO16K, true to enable FRO16K, false to disable FRO16K.
 */
static inline void PMU_EnableFRO16K(PMU_Type *base, bool enable)
{
    if (enable)
    {
        base->FRO_CTRL |= PMU_FRO_CTRL_FRO16K_EN_MASK;
    }
    else
    {
        base->FRO_CTRL &= ~PMU_FRO_CTRL_FRO16K_EN_MASK;
    }
}

/*!
 * @brief Update FRO16K output frequency.
 * 
 * @param base PMU peripheral base address.
 * @param freq The target frequency to update, please refer to @ref pmu_fro16k_output_freq_t for details.
 */
static inline void PMU_UpdateFRO16KFreq(PMU_Type *base, pmu_fro16k_output_freq_t freq)
{
    if (freq == kPMU_FRO16KOutput16KHz)
    {
        base->FRO_CTRL &= ~PMU_FRO_CTRL_CLOCK_SEL_MASK;
    }
    else
    {
        base->FRO_CTRL |= PMU_FRO_CTRL_CLOCK_SEL_MASK;
    }
}

/*!
 * @brief Update DCDC watchdog counter value.
 * 
 * @param base PMU peripheral base address.
 * @param timeoutValue DCDC watchdog counter value.
 */
static inline void PMU_UpdateDCDCWakeupWatchdogCounterValue(PMU_Type *base, uint16_t timeoutValue)
{
    base->VDD_WKUP_WDTC = ((base->VDD_WKUP_WDTC) & ~PMU_VDD_WKUP_WDTC_DCDC_WKUP_WDOG_MASK) | \
                        PMU_VDD_WKUP_WDTC_DCDC_WKUP_WDOG(timeoutValue);
}

/*!
 * @brief Update wakeup time of the PMU analog from POR reset to ext_reset release.
 * 
 * @param base PMU peripheral base address.
 * @param wakeupTime Specify the wakeup time.
 */
static inline void PMU_UpdateWakeupTime(PMU_Type *base, uint16_t wakeupTime)
{
    base->AWK_UP_TIME = ((base->AWK_UP_TIME) & ~PMU_AWK_UP_TIME_WKUP_TIME_MASK) | PMU_AWK_UP_TIME_WKUP_TIME(wakeupTime);
}

/*!
 * @brief Get wakeup time of the PMU analog from POR reset to ext_reset release.
 * 
 * @param base PMU peripheral base address.
 *
 * @return The wakeup time of the PMU analog from POR reset to ext_reset release.
 */
static inline uint32_t PMU_GetWakeupTime(PMU_Type *base)
{
    return (base->AWK_UP_TIME);
}

#if defined(__cplusplus)
}
#endif


/*!
 * @}
 */
#endif /* __FSL_PMU_H */
