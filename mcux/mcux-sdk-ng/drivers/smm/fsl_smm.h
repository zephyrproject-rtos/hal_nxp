/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef _FSL_SMM_H
#define _FSL_SMM_H


#include "fsl_common.h"


/*!
 * @addtogroup smm
 * @{
 */


/*******************************************************************************
* Definitions
******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief smm driver version 2.1.0. */
#define FSL_SMM_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*@}*/

/*!
 * @brief The enumeration of interrupt to enable.
 * @anchor smm_interrupt_enable_t.
 */
enum _smm_interrupt_enable
{
    kSMM_QChannelTimeoutInt = 1UL << 12UL,
    kSMM_QChannelDenyInt = 1UL << 14UL,
    kSMM_DeepSleepCounterInt = 1UL << 9UL,
    kSMM_ComparatorMatchInt = 1UL << 8UL,
    kSMM_AllSupportedInts = (kSMM_QChannelTimeoutInt | kSMM_QChannelDenyInt | \
                            kSMM_DeepSleepCounterInt | kSMM_ComparatorMatchInt),
};

/*!
 * @brief The enumeration of interrupt flag.
 * @anchor smm_interrupt_flag_t
 */
enum _smm_interrupt_flag
{
    kSMM_QChannelTimeoutIntFlag = 1UL << 13UL,
    kSMM_QChannelDenyIntFlag = 1UL << 15UL,

    kSMM_AllIntFlags = kSMM_QChannelTimeoutIntFlag | kSMM_QChannelDenyIntFlag,
};

/*!
 * @brief The enumeration of external interrupt polarity.
 */
typedef enum _smm_ext_int_polarity
{
    kSMM_ExtIntRisingEdge = 0U, /*!< Detect rising edge of External Interrupt Pin. */
    kSMM_ExtIntFallingEdge,     /*!< Detect falling edge of External Interrupt Pin. */
} smm_ext_int_polarity_t;

/*!
 * @brief Configuration definition of external interrupt.
 */
typedef struct _smm_ext_int_config
{
    bool maskExtIntPin; /*!< True to mask external interrupt pin, false to unmask. */
    smm_ext_int_polarity_t extIntPolarity; /*!< External interrupt polarity. */
} smm_ext_int_config_t;

/*!
 * @brief The definition of backend register content.
 */
typedef struct _smm_backup_reg_content
{
    uint32_t word1; /* The first word of backend register 1. */
    uint32_t word2; /* The second word of backend register 2. */
} smm_backup_reg_content_t;

/*!
 * @brief Watchdog alarm use enumeration.
 */
typedef enum _smm_watchdog_alarm_use
{
    kSMM_WatchdogAlarmAsReset = 0U,       /*!< Watchdog alarm as reset. */
    kSMM_WatchdogAlarmAsInterrupt = 1U    /*!< Watchdog alarm as interrupt. */
} smm_watchdog_alarm_use_t;

/*******************************************************************************
* API
******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Set external interrupt configuration.
 * 
 * @param base SMM base address.
 * @param ptrConfig Pointer to configuration in type of @ref smm_ext_int_config_t.
 */
void SMM_SetExtInterruptConfig(SMM_Type *base, const smm_ext_int_config_t *ptrConfig);

/*!
 * @brief Disable the AON CPU I/O signals on exist from DPD2.
 * 
 * @param base SMM base address.
 */
static inline void SMM_DisableAonCpuIsoSingal(SMM_Type *base)
{
    base->CNFG |= SMM_CNFG_AON_ISO_DSBL_MASK;
}

/*!
 * @brief Disable the Main CPU I/O signals on exist from DPD1.
 * 
 * @param base SMM base address.
 */
static inline void SMM_DisableMainCpuIsoSingal(SMM_Type *base)
{
    base->CNFG |= SMM_CNFG_MAIN_ISO_DSBL_MASK;
}

/*!
 * @brief Enable wakeup sources to the main CPU.
 * 
 * @param base SMM base address.
 * @param wakeupSources Mask value of wakeup sources.
 */
static inline void SMM_EnableWakeupSourceToMainCpu(SMM_Type *base, uint32_t wakeupSources)
{
    base->WKUP_MAIN = SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU(wakeupSources);
}

/*!
 * @brief Disable wakeup sources to the main CPU.
 * 
 * @param base SMM base address.
 * @param wakeupSources Mask value of wakeup sources.
 */
static inline void SMM_DisableWakeupSourceToMainCpu(SMM_Type *base, uint32_t wakeupSources)
{
    base->WKUP_MAIN &= ~SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU(wakeupSources);
}

/*!
 * @brief Get enabled wakeup sources to main CPU.
 * 
 * @param base SMM base address.
 *
 * @return Masked value of all enabled wakeup sources to main CPU.
 */
static inline uint32_t SMM_GetEnabledWakeupSourceToMainCpu(SMM_Type *base)
{
    return ((base->WKUP_MAIN) & SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_MASK);
}

/*!
 * @brief Enable wakeup sources to AON CPU.
 * 
 * @param base SMM base address.
 * @param wakeupSources The mask value of wakeup sources.
 */
static inline void SMM_EnableWakeupSourceToAonCpu(SMM_Type *base, uint32_t wakeupSources)
{
    base->AON_CPU = SMM_AON_CPU_WKUP_SRC_AON_CPU(wakeupSources);
}

/*!
 * @brief Disable wakeup sources to AON CPU.
 *
 * @param base SMM base address.
 * @param wakeupSources The mask value of wakeup sources.
 */
static inline void SMM_DisableWakeupSourceToAonCpu(SMM_Type *base, uint32_t wakeupSources)
{
    base->AON_CPU &= ~SMM_AON_CPU_WKUP_SRC_AON_CPU(wakeupSources);
}

/*!
 * @brief Get enabled wakeup sources to AON CPU.
 *
 * @param base SMM base address.
 *
 * @return Masked value of all enabled wakeup sources to AON CPU.
 */
static inline uint32_t SMM_GetEnabledWakeupSourceToAonCpu(SMM_Type *base)
{
    return ((base->AON_CPU) & SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK);
}

/*!
 * @brief Get wakeup source status.
 *
 * @param base SMM base address.
 *
 * @return Masked value of all enabled wakeup sources.
 */
static inline uint32_t SMM_GetWakeupSourceStatus(SMM_Type *base)
{
    return (uint32_t)(base->WKUP_STAT & SMM_WKUP_STAT_WKUP_SRCS_MASK);
}

/*!
 * @brief Shutdown bangdap in low power modes.
 * 
 * @param base SMM base address.
 * @param shutdown True to disable bandgap, false to keep enabled.
 */
static inline void SMM_ShutDownBandgapInLowPowerModes(SMM_Type *base, bool shutdown)
{
    if (shutdown)
    {
        base->PWDN_CONFIG |= SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD_MASK;
        base->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC_MASK;
    }
    else
    {
        base->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD_MASK;
        base->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC_MASK;
    }
}

/*!
 * @brief Start the power down sequence.
 * 
 * @param base SMM base address.
 */
static inline void SMM_StartPowerDownSequence(SMM_Type *base)
{
    base->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD_STRT_MASK;
}

/*!
 * @brief Start the DPD2 sequence.
 *
 * @param base SMM base address.
 */
static inline void SMM_StartAonDPD2Sequence(SMM_Type *base)
{
    base->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD2_AON_MASK;
}

/*!
 * @brief Start the AON shutdown/DPD3 sequence.
 * 
 * @param base SMM base address.
 */
static inline void SMM_StartAonShutDownSequence(SMM_Type *base)
{
    base->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD3_SHTDWN_MASK;
}

/*!
 * @brief Abort any start of low power modes sequence.
 * 
 * @param base SMM base address.
 */
static inline void SMM_AbortLowPowerModeSequence(SMM_Type *base)
{
    base->PWDN_CONFIG |= SMM_PWDN_CONFIG_DPD_ABRT_MASK;
}

/*!
 * @brief Switch to XTAL32 in DPD2 mode.
 * 
 * @param base SMM base address
 * @param enable True means switch to 32k clock, false means remain at AON_CLK.
 */
static inline void SMM_SwitchToXTAL32(SMM_Type *base, bool enable)
{
    if (enable)
    {
        base->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_AON_DPD_SL_CLK_MASK;
    }
    else
    {
        base->PWDN_CONFIG |= SMM_PWDN_CONFIG_AON_DPD_SL_CLK_MASK;
    }
}

/*!
 * @brief Power off selected AON SRAM cuts manually.
 * 
 * @param base SMM base address.
 * @param sramCuts The mask of AON SRAM cuts.
 */
static inline void SMM_PowerOffAonSramManually(SMM_Type *base, uint8_t sramCuts)
{
    base->PWDN_CONFIG |= SMM_PWDN_CONFIG_SRAM_CNTRL(sramCuts);
}

/*!
 * @brief Power on selected AON SRAM cuts manually.
 * 
 * @param base SMM base address.
 * @param sramCuts The mask of AON SRAM cuts.
 */
static inline void SMM_PowerOnAonSramManually(SMM_Type *base, uint8_t sramCuts)
{
    base->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_SRAM_CNTRL(sramCuts);
}

/*!
 * @brief Power off selected AON SRAM cuts when enter into low power mode.
 * 
 * @param base SMM base address.
 * @param sramCuts The mask of AON SRAM cuts.
 */
static inline void SMM_PowerOffAonSramAutomatically(SMM_Type *base, uint8_t sramCuts)
{
    base->PWDN_CONFIG |=  SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_MASK;
    base->MEMORY_RTN  = ((base->MEMORY_RTN & ~SMM_MEMORY_RTN_CPU_SRAMBn_PWD_MASK) | SMM_MEMORY_RTN_CPU_SRAMBn_PWD(sramCuts));
}

/*!
 * @brief Keep selected AON SRAM keep powered when enter into low power mode.
 * 
 * @param base SMM base address.
 * @param sramCuts The mask of AON SRAM cuts.
 */
static inline void SMM_DisableAonSramAutoControl(SMM_Type *base, uint8_t sramCuts)
{
    base->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_MASK;
}

/*!
 * @brief Write data to backup registers.
 * 
 * @param base SMM base address.
 * @param[in] ptrBackupRegContent Pointer of the content will write to backup registers.
 */
void SMM_WriteToBackupReg(SMM_Type *base, const smm_backup_reg_content_t *ptrBackupRegContent);

/*!
 * @brief Read data from backup registers.
 * 
 * @param base SMM base address.
 * @param[out] ptrBackupRegContent Pointer of the content will read from backup registers.
 */
void SMM_ReadFromBackupReg(SMM_Type *base, smm_backup_reg_content_t *ptrBackupRegContent);

/*!
 * @brief Enable memory retention at low power modes for main CPU.
 * 
 * @param base SMM base address.
 * @param sramCuts Mask of sram cuts to retained.
 */
void SMM_EnableMainDomainSramRetention(SMM_Type *base, uint16_t sramCuts);

/*!
 * @brief Disable memory retention at low power modes for main CPU.
 * 
 * @param base SMM base address.
 */
static inline void SMM_DisableMainDomainSramRetention(SMM_Type *base)
{
    base->MEMORY_RTN &= ~SMM_MEMORY_RTN_RETAIN_EN_MASK;
}

/*!
 * @brief Enable/disable IVS Mode for the SRAM retention.
 * 
 * @param base SMM base address.
 * @param enable True to enable IVS mode, false to disable.
 */
static inline void SMM_EnableIvsModeForSramRetention(SMM_Type *base, bool enable)
{
    if (enable)
    {
        base->MEMORY_RTN |= SMM_MEMORY_RTN_IVS_EN_MASK;
    }
    else
    {
        base->MEMORY_RTN &= ~SMM_MEMORY_RTN_IVS_EN_MASK;
    }
}

/*!
 * @brief Get the power state.
 * 
 * @param base SMM base address.
 * 
 * @return Value of power state. 
 */
static inline uint8_t SMM_GetPowerState(SMM_Type *base)
{
    return (uint8_t)((base->STAT & SMM_STAT_DPD_STATE_MASK) >> SMM_STAT_DPD_STATE_SHIFT);
}

/*!
 * @brief Wakeup the main domain CPU from low power mode.
 * 
 * @param base SMM base address.
 */
static inline void SMM_WakeupMainDomain(SMM_Type *base)
{
    base->PWDN_CONFIG |= SMM_PWDN_CONFIG_WKUP_CPU_M_MASK;
    base->PWDN_CONFIG &= ~SMM_PWDN_CONFIG_WKUP_CPU_M_MASK;
}

/*!
 * @brief Check if the external interrupt flag is asserted.
 * 
 * @param base SMM base address.
 *
 * @return True if external interrupt is active, false otherwise. 
 */
static inline bool SMM_CheckExternalIntActive(SMM_Type *base)
{
    return (bool)((base->STAT & SMM_STAT_EXT_INT_A_MASK) != 0UL);
}

/*!
 * @brief Clear the external interrupt flag.
 * 
 * @param base SMM base address.
 */
static inline void SMM_ClearExternalIntFlag(SMM_Type *base)
{
    base->STAT = SMM_STAT_EXT_INT_A_MASK;
}

/*!
 * @brief Disable the main CPU I/O signals.
 * 
 * @param base SMM base address.
 */
static inline void SMM_DisableMainCpuIso(SMM_Type *base)
{
    base->CNFG |= (SMM_CNFG_MAIN_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG &= ~(SMM_CNFG_MAIN_ISO_DSBL_MASK);
    
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG |= (SMM_CNFG_MAIN_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG &= ~(SMM_CNFG_MAIN_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
}

/*!
 * @brief Disable the AON CPU I/O signals.
 * 
 * @param base SMM base address.
 */
static inline void SMM_DisableAonCpuIso(SMM_Type *base)
{
    base->CNFG |= (SMM_CNFG_AON_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG &= ~(SMM_CNFG_AON_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG |= (SMM_CNFG_AON_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG &= ~(SMM_CNFG_AON_ISO_DSBL_MASK);
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
}

/*!
 * @brief Clear all low power sequence settings.
 * 
 * @param base SMM base address.
 */
static inline void SMM_ClearAllLowPowerSequence(SMM_Type *base)
{
    base->PWDN_CONFIG &= ~(SMM_PWDN_CONFIG_DPD_STRT_MASK | SMM_PWDN_CONFIG_DPD3_SHTDWN_MASK | SMM_PWDN_CONFIG_DPD2_AON_MASK);
}

/*!
 * @brief Clear all wakeup sources to main domain.
 * 
 * @param base 
 */
static inline void SMM_ClearMainCpuWakeupSources(SMM_Type *base)
{
    base->WKUP_MAIN &= ~SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_MASK;
}

/*!
 * @brief Clear all wakeup sources to AON domain.
 * 
 * @param base SMM base address.
 */
static inline void SMM_ClearAonCpuWakeupSources(SMM_Type *base)
{
    base->AON_CPU &= ~SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK;
}

/*!
 * @brief Config the watchdog alarm use.
 *
 * @param base SMM base address.
 * @param alarmUse The watchdog alarm use.
 */
static inline void SMM_ConfigWatchdogAlarmUse(SMM_Type *base, smm_watchdog_alarm_use_t alarmUse)
{
    base->CNFG &= ~(SMM_CNFG_WTCHDG_USE_INT_MASK);
    base->CNFG |= SMM_CNFG_WTCHDG_USE_INT(alarmUse);
}

/*!
 * @brief Use the deep sleep counter for general software needs.
 * 
 * @param base SMM base address.
 */
static inline void SMM_UseDeepSleepCounterInSoftwareMethod(SMM_Type *base)
{
    base->CNFG |= SMM_CNFG_DSLP_COUNT_USE_MASK;
}

/*!
 * @brief Use the deep sleep counter by hardware to wakeup from low power mode.
 * 
 * @param base SMM base address.
 */
static inline void SMM_UseDeepSleepCounterInHardwareMethod(SMM_Type *base)
{
    base->CNFG &= ~SMM_CNFG_DSLP_COUNT_USE_MASK;
}

/*!
 * @brief Reset the deep sleep counter and disable count.
 * 
 * @param base SMM base address.
 */
static inline void SMM_ResetAndDisableDeepSleepCounter(SMM_Type *base)
{
    base->CNFG |= SMM_CNFG_DSLP_COUNT_RST_MASK;
    for (uint32_t i = 0UL; i < 1000UL; i++)
    {
        i++;
    }
    base->CNFG &= ~SMM_CNFG_DSLP_COUNT_RST_MASK;
}

/*!
 * @brief Enable the countdown start of the deep sleep counter when at sofware use.
 * 
 * @param base SMM base address.
 */
static inline void SMM_StartDeepSleepCounter(SMM_Type *base)
{
    base->CNFG |= SMM_CNFG_DSLP_COUNT_STRT_MASK;
}

/*!
 * @brief Update the deep sleep counter, the counter is counting the AON clocks.
 * 
 * @param base SMM base address.
 * @param value Value to update the deep sleep counter.
 */
static inline void SMM_UpdateDeepSleepCounter(SMM_Type *base, uint16_t value)
{
    base->DPSLP_COUNT = SMM_DPSLP_COUNT_DPSLP_CNT(value);
}

/*!
 * @brief Read value of deep sleep counter.
 * 
 * @param base SMM base address.
 *
 * @return Count of deep sleep counter.
 */
static inline uint16_t SMM_ReadDeepSleepCounter(SMM_Type *base)
{
    return (uint16_t)(base->DPSLP_COUNT);
}

/*!
 * @brief Enable specific interrupts.
 * 
 * @param base SMM base address.
 * @param masks The mask of interrupts to enable, should be OR'ed value of @ref smm_interrupt_enable_t.
 */
static inline void SMM_EnableInterrupts(SMM_Type *base, uint32_t masks)
{
    uint32_t tmp32 = base->STAT;

    tmp32 &= ~(kSMM_AllSupportedInts);
    base->STAT = (tmp32 | (masks & kSMM_AllSupportedInts));
}

/*!
 * @brief Disable specific interrupts.
 * 
 * @param base SMM base address.
 * @param masks The mask of interrupts to disable, should be OR'ed value of @ref smm_interrupt_enable_t.
 */
static inline void SMM_DisableInterrupts(SMM_Type *base, uint32_t masks)
{
    uint32_t tmp32 = base->STAT;

     tmp32 &= ~(kSMM_AllSupportedInts);
    base->STAT = tmp32 & (~(masks & kSMM_AllSupportedInts));
}

/*!
 * @brief Get interrupt flags.
 * 
 * @param base SMM base address.
 *
 * @return The mask of all asserted interrupt flags, should be the OR'ed value of @ref smm_interrupt_flag_t.
 */
static inline uint32_t SMM_GetInterruptFlags(SMM_Type *base)
{
    return ((base->STAT) & kSMM_AllIntFlags);
}

/*!
 * @brief Clear interrupt flags.
 * 
 * @param base SMM base address.
 * @param flags The mask of interrupt flags to clear, should be the OR'ed value of @ref smm_interrupt_flag_t.
 */
static inline void SMM_ClearInterruptFlags(SMM_Type *base, uint32_t flags)
{
    base->STAT = (flags & kSMM_AllIntFlags);
}

/*!
 * @brief Check if deep sleep counter reach zero at software use.
 * 
 * @param base SMM base address.
 *
 * @retval false Deep sleep counter do not reach zero.
 * @retval true Deep sleep counter reach zero.
 */
static inline bool SMM_CheckDeepSleepCounterMatch(SMM_Type *base)
{
    return ((base->STAT & SMM_STAT_DPSLP_CNTR_M_MASK) != 0UL);
}

/*!
 * @brief Clear deep sleep counter match flag.
 * 
 * @param base SMM base address.
 */
static inline void SMM_ClearDeepSleepCounterMatchFlag(SMM_Type *base)
{
    base->STAT = SMM_STAT_DPSLP_CNTR_M_MASK;
}

/*!
 * @brief Check if comparator match was active.
 * 
 * @param base SMM base address.
 *
 * @retval false Comparator match is not active.
 * @retval true Comparator match is active.
 */
static inline bool SMM_CheckComparatorMatch(SMM_Type *base)
{
    return ((base->STAT & SMM_STAT_COMP_MATCH_MASK) != 0UL);
}

/*!
 * @brief Clear comparator match flag.
 * 
 * @param base SMM base address.
 */
static inline void SMM_ClearComparatorMatchFlag(SMM_Type *base)
{
    base->STAT = SMM_STAT_COMP_MATCH_MASK;
}

#if defined(__cplusplus)
}
#endif


/*!
 * @}
 */
#endif /* __FSL_SMM_H */
