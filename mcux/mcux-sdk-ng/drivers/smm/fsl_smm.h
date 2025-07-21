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
/*! @brief smm driver version 2.0.0. */
#define FSL_SMM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

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
    base->WKUP_MAIN = SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU(1UL << wakeupSources);
}

/*!
 * @brief Disable wakeup sources to the main CPU.
 * 
 * @param base SMM base address.
 * @param wakeupSources Mask value of wakeup sources.
 */
static inline void SMM_DisableWakeupSourceToMainCpu(SMM_Type *base, uint32_t wakeupSources)
{
    base->WKUP_MAIN &= ~SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU(1UL<< wakeupSources);
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
    base->AON_CPU = SMM_AON_CPU_WKUP_SRC_AON_CPU(1UL << wakeupSources);
}

/*!
 * @brief Disable wakeup sources to AON CPU.
 *
 * @param base SMM base address.
 * @param wakeupSources The mask value of wakeup sources.
 */
static inline void SMM_DisableWakeupSourceToAonCpu(SMM_Type *base, uint32_t wakeupSources)
{
    base->AON_CPU &= ~SMM_AON_CPU_WKUP_SRC_AON_CPU(1UL << wakeupSources);
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
    base->MEMORY_RTN  = ((base->MEMORY_RTN & ~SMM_MEMORY_RTN_CPU_RAM_PWD_MASK) | SMM_MEMORY_RTN_CPU_RAM_PWD(sramCuts));
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
    base->CNFG &= ~(SMM_CNFG_MAIN_ISO_DSBL_MASK);
}

/*!
 * @brief Disable the AON CPU I/O signals.
 * 
 * @param base SMM base address.
 */
static inline void SMM_DisableAonCpuIso(SMM_Type *base)
{
    base->CNFG |= (SMM_CNFG_AON_ISO_DSBL_MASK);
    base->CNFG &= ~(SMM_CNFG_AON_ISO_DSBL_MASK);
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
 * @param base 
 */
static inline void SMM_ClearAonCpuWakeupSources(SMM_Type *base)
{
    base->AON_CPU &= ~SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK;
}


#if defined(__cplusplus)
}
#endif


/*!
 * @}
 */
#endif /* __FSL_SMM_H */
