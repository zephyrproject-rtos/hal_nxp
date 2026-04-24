/*
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
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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

#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}


/*!
 * @brief Keep FRO16K active in DPD3 and SD modes.
 * 
 * @param base PMU peripheral base address.
 * @param keepActive Specify whether to keep FRO16K active, true to keep active, false otherwise.
 */
static inline void PMU_KeepFRO16KActiveInDpd3AndSD(PMU_Type *base, bool keepActive)
{
    if (keepActive)
    {
        base->PMU_DPD3_CTRL |= PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_MASK;
    }
    else
    {
        base->PMU_DPD3_CTRL &= ~PMU_PMU_DPD3_CTRL_FRO16KHZ_ACT_MASK;
    }

#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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

#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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

#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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

#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
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

#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}

/*!
 * @brief Enable or disable high voltage glitch detection.
 *
 * This function enables or disables the high voltage glitch detector by setting or clearing
 * the AGDET_HV_EN bit in the AGDET_HV_CTRL register.
 *
 * @param base PMU peripheral base address.
 * @param enable True to enable high voltage glitch detection, false to disable.
 *
 * @note This function includes a delay after the register write if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL is configured.
 */
static inline void PMU_EnableHighVolGlitchDetect(PMU_Type *base, bool enable)
{
    if (enable)
    {
        base->AGDET_HV_CTRL |= PMU_AGDET_HV_CTRL_AGDET_HV_EN_MASK;
    }
    else
    {
        base->AGDET_HV_CTRL &= ~PMU_AGDET_HV_CTRL_AGDET_HV_EN_MASK;
    }
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
   SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}

/*!
 * @brief Clear the high voltage glitch detection reset flag.
 *
 * This function clears the high voltage glitch detector reset flag by toggling
 * the AGDET_HV_RES bit in the AGDET_HV_CTRL register. The bit is first set and
 * then cleared to reset the detection status.
 *
 * @param base PMU peripheral base address.
 *
 * @note This function includes delays after register writes if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL is configured.
 */
static inline void PMU_CleanHighVolGlitchDetectReset(PMU_Type *base)
{
    base->AGDET_HV_CTRL |= PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK;
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
    base->AGDET_HV_CTRL &= ~PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK;
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}

/*!
 * @brief Check if the high voltage glitch detection reset flag is asserted.
 *
 * This function checks whether the high voltage glitch detector reset flag is set
 * by reading the AGDET_HV_RES bit in the AGDET_HV_CTRL register.
 *
 * @param base PMU peripheral base address.
 *
 * @retval true The high voltage glitch detection reset flag is asserted.
 * @retval false The high voltage glitch detection reset flag is not asserted.
 */
static inline bool PMU_IsHighVolGlitchDetectResetAsserted(PMU_Type *base)
{
    return (bool)((base->AGDET_HV_CTRL & PMU_AGDET_HV_CTRL_AGDET_HV_RES_MASK) != 0UL);
}

/*!
 * @brief Enable or disable the low voltage glitch detection.
 *
 * This function enables or disables the low voltage glitch detector by setting
 * or clearing the AGDET_LV_EN bit in the AGDET_LV_CTRL register.
 *
 * @param base PMU peripheral base address.
 * @param enable Enable or disable the low voltage glitch detection.
 *               - true: Enable low voltage glitch detection.
 *               - false: Disable low voltage glitch detection.
 *
 * @note This function includes a delay after register write if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL is configured.
 */
static inline void PMU_EnableLowVolGlitchDetect(PMU_Type *base, bool enable)
{
    if (enable)
    {
        base->AGDET_LV_CTRL |= PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK;
    }
    else
    {
        base->AGDET_LV_CTRL &= ~PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK;
    }
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}

/*!
 * @brief Clear the low voltage glitch detection reset flag.
 *
 * This function clears the low voltage glitch detector reset flag by performing
 * a write sequence to the AGDET_LV_RES bit in the AGDET_LV_CTRL register.
 * The flag is first set and then cleared to complete the reset operation.
 *
 * @param base PMU peripheral base address.
 *
 * @note This function includes delays after register writes if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL is configured.
 */
static inline void PMU_CleanLowVolGlitchDetectReset(PMU_Type *base)
{
    base->AGDET_LV_CTRL |= PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK;
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
    base->AGDET_LV_CTRL &= ~PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK;
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}

/*!
 * @brief Check if low voltage glitch detection has occurred.
 *
 * This function checks the low voltage glitch detector reset flag by reading
 * the AGDET_LV_RES bit in the AGDET_LV_CTRL register.
 *
 * @param base PMU peripheral base address.
 *
 * @retval true Low voltage glitch has been detected.
 * @retval false Low voltage glitch has not been detected.
 */
static inline bool PMU_IsLowVolGlitchDetect(PMU_Type *base)
{
    return (bool)((base->AGDET_LV_CTRL & PMU_AGDET_LV_CTRL_AGDET_LV_RES_MASK) != 0UL);
}

/*!
 * @brief Apply handshake between PMU and PAC after PMU register update.
 * 
 * @param base PMU peripheral base address.
 */
static inline void PMU_DoHandshakeBetweenPMUAndPAC(PMU_Type *base)
{
    uint32_t tmp32 = base->AWK_UP_TIME;
    base->AWK_UP_TIME = tmp32;
#if CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL
    SDK_DelayAtLeastUs(CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL, SystemCoreClock);
#endif /* CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL */
}
#if defined(__cplusplus)
}
#endif


/*!
 * @}
 */
#endif /* __FSL_PMU_H */
