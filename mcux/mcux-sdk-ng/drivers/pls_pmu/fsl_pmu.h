/*
 * Copyright 2025-2026 NXP
 * Copyright 2025-2026 NXP
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
/*! @brief pls_pmu driver version 2.1.0. */
#define FSL_PMU_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
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
        base->PCTRL |= PMU_PCTRL_VDD_CORE_AON_EN_MASK;
    }
    else
    {
        base->PCTRL &= ~PMU_PCTRL_VDD_CORE_AON_EN_MASK;
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
    base->VDD_CORE_AON_CONFIG = ((base->VDD_CORE_AON_CONFIG) & ~(PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG_MASK)) | \
                            PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_ACONFIG(value);
}

/*!
 * @brief Update voltage of VDD_CORE in low power modes.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update, LSB is 9.5mV.
 */
static inline void PMU_UpdateVDDCoreInLpMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_AON_CONFIG = ((base->VDD_CORE_AON_CONFIG) & ~(PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG_MASK)) | \
                            PMU_VDD_CORE_AON_CONFIG_VDD_CORE_AON_DCONFIG(value);
}

/*!
 * @brief Update voltage of VDD_CORE_1P1 in active mode.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update.
 */
static inline void PMU_UpdateVDDCore1P1InActiveMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_MAIN_CONFIG = ((base->VDD_CORE_MAIN_CONFIG) & ~PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG_MASK) | \
                            PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_ACONFIG(value);
}

/*!
 * @brief Update voltage of VDD_CORE_1P1 in low power modes.
 * 
 * @param base PMU peripheral base address.
 * @param value Value to update.
 */
static inline void PMU_UpdateVDDCore1P1InLpMode(PMU_Type *base, uint8_t value)
{
    base->VDD_CORE_MAIN_CONFIG = ((base->VDD_CORE_MAIN_CONFIG) & ~PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR_MASK) | \
    PMU_VDD_CORE_MAIN_CONFIG_VDD_CORE_MAIN_VOUTSEL_LPWR(value);
}

/*!
 * @brief Enable/disable FRO16K.
 * 
 * @param base PMU peripheral base address.
 * @param enable Specify the behavior of FRO16K, true to enable FRO16K, false to disable FRO16K.
 */
static inline void PMU_EnableFRO16K(PMU_Type *base, bool enable)
{
    if (enable == false)
    {
        /* Disable FRO16K clock. */
        base->FRO_CTRL |= PMU_FRO_CTRL_FRO16K_EN_MASK;
    }
    else
    {
        /* Enable FRO16K clock. */
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
    base->PMU_DPD3_CTRL = ((base->PMU_DPD3_CTRL) & ~PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG_MASK) | \
                        PMU_VDD_CORE_AON_WKUP_WDTC_DCDC_AON_WKUP_WDOG(timeoutValue);
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

/*!
 * @brief Update PMU_TRIM4 HVD_LV_TRIM bitfield.
 *
 * This function writes the HVD (High Voltage Detect) low voltage trim value to PMU_TRIM4 register.
 * The trim value should be obtained from IFR1 (Information Flash Region 1) by the caller.
 * This function is typically used during CLOCK mode configuration (standard/mid drive strength).
 *
 * @param base PMU peripheral base address.
 * @param value HVD low voltage trim value to write (4-bit value, 0x0-0xF).
 *
 * @note This function uses read-modify-write operation to preserve other bitfields in PMU_TRIM4.
 * @note The caller is responsible for reading the trim value from IFR1.
 */
static inline void PMU_UpdateHvdLvTrim(PMU_Type *base, uint8_t value)
{
    base->PMU_TRIM4 = ((base->PMU_TRIM4) & ~PMU_PMU_TRIM4_HVD_LV_TRIM_MASK) | \
                      PMU_PMU_TRIM4_HVD_LV_TRIM(value);
}

/*!
 * @brief Update PMU_TRIM4 LVD_LV_TRIM bitfield.
 *
 * This function writes the LVD (Low Voltage Detect) low voltage trim value to PMU_TRIM4 register.
 * The trim value should be obtained from IFR1 (Information Flash Region 1) by the caller.
 * This function is typically used during CLOCK mode configuration (standard/mid drive strength).
 *
 * @param base PMU peripheral base address.
 * @param value LVD low voltage trim value to write (4-bit value, 0x0-0xF).
 *
 * @note This function uses read-modify-write operation to preserve other bitfields in PMU_TRIM4.
 * @note The caller is responsible for reading the trim value from IFR1.
 */
static inline void PMU_UpdateLvdLvTrim(PMU_Type *base, uint8_t value)
{
    base->PMU_TRIM4 = ((base->PMU_TRIM4) & ~PMU_PMU_TRIM4_LVD_LV_TRIM_MASK) | \
                      PMU_PMU_TRIM4_LVD_LV_TRIM(value);
}

#if defined(__cplusplus)
}
#endif


/*!
 * @}
 */
#endif /* __FSL_PMU_H */
