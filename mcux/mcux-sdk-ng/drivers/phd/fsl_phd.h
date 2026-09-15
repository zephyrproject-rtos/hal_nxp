/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_PHD_H_
#define FSL_PHD_H_

#include "fsl_common.h"

/*!
 * @addtogroup phd_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief PHD driver version 2.0.0. */
#define FSL_PHD_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief PHD comparator hysteresis level.
 *
 * Selects the internally generated hysteresis for the comparator hard block
 * (PHASECTRL[HYSTCTR]).
 * See chip data sheet to get the actual hysteresis value with each level.
 */
typedef enum _phd_hysteresis
{
    kPHD_HysteresisLevel0 = 0U, /*!< Analog comparator hysteresis level 0. */
    kPHD_HysteresisLevel1 = 1U, /*!< Analog comparator hysteresis level 1. */
    kPHD_HysteresisLevel2 = 2U, /*!< Analog comparator hysteresis level 2. */
    kPHD_HysteresisLevel3 = 3U, /*!< Analog comparator hysteresis level 3. */
} phd_hysteresis_t;

/*!
 * @brief PHD functional clock source (PHASECTRL[FUNC_CLK_SEL]).
 *
 * See the chip-specific PHD information for the clock assigned to each source.
 */
typedef enum _phd_clock_source
{
    kPHD_FuncClockSource0 = 0U, /*!< Functional clock source 0. */
    kPHD_FuncClockSource1 = 1U, /*!< Functional clock source 1. */
    kPHD_FuncClockSource2 = 2U, /*!< Functional clock source 2. */
    kPHD_FuncClockSource3 = 3U, /*!< Functional clock source 3. */
} phd_clock_source_t;

/*!
 * @brief PHD filter sample count (PHASECTRL[FILT_CNT]).
 *
 * Number of consecutive matching samples required before the filter propagates
 * a state change. Zero bypasses the filter (COUT = COUTA).
 */
typedef enum _phd_filter_count
{
    kPHD_FilterCountBypass = 0U, /*!< Filter bypassed: COUT = COUTA. */
    kPHD_FilterCount1      = 1U, /*!< 1 consecutive sample. */
    kPHD_FilterCount2      = 2U, /*!< 2 consecutive samples. */
    kPHD_FilterCount3      = 3U, /*!< 3 consecutive samples. */
    kPHD_FilterCount4      = 4U, /*!< 4 consecutive samples. */
    kPHD_FilterCount5      = 5U, /*!< 5 consecutive samples. */
    kPHD_FilterCount6      = 6U, /*!< 6 consecutive samples. */
    kPHD_FilterCount7      = 7U, /*!< 7 consecutive samples. */
} phd_filter_count_t;

/*!
 * @brief Comparator output path selection (PHCMPnCR[COUT_SEL]).
 */
typedef enum _phd_comparator_output_select
{
    kPHD_OutputFiltered   = 0U, /*!< Use COUT (filtered output) for CMPO. */
    kPHD_OutputUnfiltered = 1U, /*!< Use COUTA (unfiltered output) for CMPO. */
} phd_comparator_output_select_t;

/*!
 * @brief PHD IBIAS trim value selection (PHASECTRL[IBIAS_TRIM]).
 */
typedef enum _phd_ibias_trim
{
    kPHD_IbiasTrimValue0 = 0U, /*!< IBIAS trim value 0. */
    kPHD_IbiasTrimValue1 = 1U, /*!< IBIAS trim value 1. */
} phd_ibias_trim_t;

/*!
 * @brief PHD phase selection mask for PHD_SetPhaseSelect() (PHASECTRL[PHSEL0/1/2]).
 *
 * OR together the phases to be connected to the virtual neutral network.
 */
typedef enum _phd_phase_select
{
    kPHD_Phase0 = PHD_PHASECTRL_PHSEL0_MASK, /*!< Virtual network phase 0 (PHSEL0). */
    kPHD_Phase1 = PHD_PHASECTRL_PHSEL1_MASK, /*!< Virtual network phase 1 (PHSEL1). */
    kPHD_Phase2 = PHD_PHASECTRL_PHSEL2_MASK, /*!< Virtual network phase 2 (PHSEL2). */
} phd_phase_select_t;

/*!
 * @brief PHD module configuration structure (PHASECTRL).
 *
 * Covers the static PHASECTRL fields set at initialisation. CMP_EN is
 * controlled by PHD_EnableComparator() / PHD_DisableComparator().
 * PHSEL0/1/2 are runtime-dynamic and controlled by PHD_SetPhaseSelect().
 */
typedef struct _phd_config
{
    bool enableComparatorInStopMode;  /*!< Allow comparator to run in stop/deep-sleep mode (CMP_STOP_EN). */
    phd_hysteresis_t hysteresisLevel; /*!< Comparator hysteresis level (HYSTCTR). */
    phd_clock_source_t clockSource;   /*!< Functional clock source for window/filter logic (FUNC_CLK_SEL). */
    bool enableExternalNeutral;       /*!< Connect virtual neutral to external reference pin (EXTSEL). */
    bool enableInternalNeutral;       /*!< Connect virtual neutral to on-chip 8-bit DAC (INTSEL). */
    bool enableVirtualNetwork;        /*!< Enable virtual resistor network circuit (VNEN). */
    phd_ibias_trim_t ibiasTrim;       /*!< IBIAS trim value selection (IBIAS_TRIM). */
    phd_filter_count_t filterCount;   /*!< Filter sample count; kPHD_FilterCountBypass disables filter (FILT_CNT). */
    uint8_t filterPeriod;             /*!< Filter sample period in functional clock cycles (FILT_PER).
                                           0 bypasses filter. No effect when SAMPLE_EN = 1. */
} phd_config_t;

/*!
 * @brief Per-comparator configuration structure (PHCMPnCR).
 *
 * Shared by PHD_ConfigComparator0(), PHD_ConfigComparator1(), and
 * PHD_ConfigComparator2(). SAMPLE_EN takes precedence over WINDOW_EN when
 * both are set (hardware behavior).
 */
typedef struct _phd_comparator_config
{
    bool enableOutputPin;                        /*!< Make comparator output available on external pin (COUT_PEN). */
    phd_comparator_output_select_t outputSelect; /*!< Select COUT (filtered) or COUTA (unfiltered) for CMPO (COUT_SEL). */
    bool invertOutput;                           /*!< Invert comparator output polarity (COUT_INV). */
    bool enableWindowMode;                       /*!< Enable windowed-comparator mode (WINDOW_EN).
                                                      Valid only when enableSampleMode is false. */
    bool enableSampleMode;                       /*!< Enable sampled-comparator mode (SAMPLE_EN).
                                                      Takes precedence over enableWindowMode. */
} phd_comparator_config_t;

/*!
 * @brief PHD comparator interrupt enable mask (PHCMPnSCR bits 4–5).
 *
 * OR together the desired interrupt sources and pass to
 * PHD_EnableComparatorNInterrupts() / PHD_DisableComparatorNInterrupts().
 */
typedef enum _phd_comparator_interrupt
{
    kPHD_ComparatorFallingInterruptEnable = PHD_PHCMP0SCR_CFF_IE_MASK, /*!< Falling-edge interrupt enable (CFF_IE). */
    kPHD_ComparatorRisingInterruptEnable  = PHD_PHCMP0SCR_CFR_IE_MASK, /*!< Rising-edge interrupt enable (CFR_IE). */
} phd_comparator_interrupt_t;

/*!
 * @brief PHD comparator status flag mask (PHCMPnSCR bits 0–2).
 *
 * OR together the desired flags and pass to
 * PHD_GetComparatorNStatusFlags() / PHD_ClearComparatorNStatusFlags().
 * COUT is read-only; CFF and CFR are write-1-to-clear (W1C).
 */
typedef enum _phd_comparator_status_flag
{
    kPHD_ComparatorOutputFlag  = PHD_PHCMP0SCR_COUT_MASK, /*!< Current comparator output value (read-only). */
    kPHD_ComparatorFallingFlag = PHD_PHCMP0SCR_CFF_MASK,  /*!< Falling edge detected on comparator output (W1C). */
    kPHD_ComparatorRisingFlag  = PHD_PHCMP0SCR_CFR_MASK,  /*!< Rising edge detected on comparator output (W1C). */
} phd_comparator_status_flag_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and de-initialization
 * @{
 */

/*!
 * @brief Get the instance for PHD module.
 *
 * @param base PHD base address
 * @return Instance number if valid base address is provided, otherwise returns 0xFFFFFFFF
 */
uint32_t PHD_GetInstance(PHD_Type *base);

/*!
 * @brief Fills a phd_config_t with safe power-on defaults.
 *
 * @code
 *   config->enableComparatorInStopMode = false;
 *   config->hysteresisLevel            = kPHD_HysteresisLevel0;
 *   config->clockSource                = kPHD_FuncClockSource0;
 *   config->enableExternalNeutral      = false;
 *   config->enableInternalNeutral      = false;
 *   config->enableVirtualNetwork       = false;
 *   config->ibiasTrim                  = kPHD_IbiasTrimValue0;
 *   config->filterCount                = kPHD_FilterCountBypass;
 *   config->filterPeriod               = 0U;
 * @endcode
 *
 * @param config Pointer to a phd_config_t structure. Must not be NULL.
 */
void PHD_GetDefaultConfig(phd_config_t *config);

/*!
 * @brief Initialises the PHD module.
 *
 * Enables the peripheral clock, releases reset, and programs PHASECTRL from
 * @p config via read-modify-write. CMP_EN is forced to 0 regardless of any
 * prior register state. Call PHD_ConfigComparator0/1/2() to set up individual
 * channels, then PHD_EnableComparator() to start the module.
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_config_t structure. Must not be NULL.
 * @retval kStatus_Success         Initialisation successful.
 * @retval kStatus_InvalidArgument @p base is not a valid PHD address.
 */
status_t PHD_Init(PHD_Type *base, const phd_config_t *config);

/*!
 * @brief Deinitialize the PHD module.
 *
 * Clears CMP_EN, then gates the peripheral clock and asserts reset.
 *
 * @param base PHD peripheral base address.
 * @retval kStatus_Success if deinitialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t PHD_DeInit(PHD_Type *base);

/*! @} */

/*!
 * @name Per-comparator configuration
 * @{
 */

/*!
 * @brief Fills a phd_comparator_config_t with power-on defaults.
 *
 * @code
 *   config->enableOutputPin  = false;
 *   config->outputSelect     = kPHD_OutputFiltered;
 *   config->invertOutput     = false;
 *   config->enableWindowMode = false;
 *   config->enableSampleMode = false;
 * @endcode
 *
 * @param config Pointer to a phd_comparator_config_t structure. Must not be NULL.
 */
void PHD_GetDefaultComparatorConfig(phd_comparator_config_t *config);

/*!
 * @brief Configures phase comparator 0 (PHCMP0CR).
 *
 * Clears any startup-glitch flags (CFF, CFR) in PHCMP0SCR, then writes
 * PHCMP0CR via read-modify-write. Call this before asserting CMP_EN.
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_comparator_config_t structure. Must not be NULL.
 */
void PHD_ConfigComparator0(PHD_Type *base, const phd_comparator_config_t *config);

/*!
 * @brief Configures phase comparator 1 (PHCMP1CR).
 *
 * Clears any startup-glitch flags (CFF, CFR) in PHCMP1SCR, then writes
 * PHCMP1CR via read-modify-write. Call this before asserting CMP_EN.
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_comparator_config_t structure. Must not be NULL.
 */
void PHD_ConfigComparator1(PHD_Type *base, const phd_comparator_config_t *config);

/*!
 * @brief Configures phase comparator 2 (PHCMP2CR).
 *
 * Clears any startup-glitch flags (CFF, CFR) in PHCMP2SCR, then writes
 * PHCMP2CR via read-modify-write. Call this before asserting CMP_EN.
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_comparator_config_t structure. Must not be NULL.
 */
void PHD_ConfigComparator2(PHD_Type *base, const phd_comparator_config_t *config);

/*! @} */

/*!
 * @name Module enable
 * @{
 */

/*!
 * @brief Enables the PHD comparator analog block (PHASECTRL[CMP_EN]).
 *
 * Call this after PHD_Init() and all PHD_ConfigComparatorN() calls are complete.
 *
 * @param base PHD peripheral base address.
 */
static inline void PHD_EnableComparator(PHD_Type *base)
{
    base->PHASECTRL |= PHD_PHASECTRL_CMP_EN_MASK;
}

/*!
 * @brief Disables the PHD comparator analog block (PHASECTRL[CMP_EN]).
 *
 * Disabling CMP_EN automatically clears all CFF/CFR flags in hardware.
 *
 * @param base PHD peripheral base address.
 */
static inline void PHD_DisableComparator(PHD_Type *base)
{
    base->PHASECTRL &= MCUX_MASK_INVERT_32(PHD_PHASECTRL_CMP_EN_MASK);
}

/*!
 * @brief Selects which phase windings are connected to the virtual neutral network.
 *
 * @param base      PHD peripheral base address.
 * @param phaseMask OR-combination of @ref phd_phase_select_t values.
 *                  Pass 0 to disconnect all phases.
 */
static inline void PHD_SetPhaseSelect(PHD_Type *base, uint32_t phaseMask)
{
    uint32_t reg = base->PHASECTRL;
    reg &= MCUX_MASK_INVERT_32(PHD_PHASECTRL_PHSEL0_MASK | PHD_PHASECTRL_PHSEL1_MASK |
                               PHD_PHASECTRL_PHSEL2_MASK);
    reg |= (phaseMask & (PHD_PHASECTRL_PHSEL0_MASK | PHD_PHASECTRL_PHSEL1_MASK |
                         PHD_PHASECTRL_PHSEL2_MASK));
    base->PHASECTRL = reg;
}

/*! @} */

/*!
 * @name Interrupt enable and disable
 * @{
 */

/*!
 * @brief Enables interrupts for phase comparator 0 (PHCMP0SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref phd_comparator_interrupt_t values.
 */
static inline void PHD_EnableComparator0Interrupts(PHD_Type *base, uint32_t mask)
{
    base->PHCMP0SCR |= (mask & (PHD_PHCMP0SCR_CFF_IE_MASK | PHD_PHCMP0SCR_CFR_IE_MASK));
}

/*!
 * @brief Disables interrupts for phase comparator 0 (PHCMP0SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref phd_comparator_interrupt_t values.
 */
static inline void PHD_DisableComparator0Interrupts(PHD_Type *base, uint32_t mask)
{
    base->PHCMP0SCR &= MCUX_MASK_INVERT_32(mask & (PHD_PHCMP0SCR_CFF_IE_MASK | PHD_PHCMP0SCR_CFR_IE_MASK));
}

/*!
 * @brief Enables interrupts for phase comparator 1 (PHCMP1SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref phd_comparator_interrupt_t values.
 */
static inline void PHD_EnableComparator1Interrupts(PHD_Type *base, uint32_t mask)
{
    base->PHCMP1SCR |= (mask & (PHD_PHCMP1SCR_CFF_IE_MASK | PHD_PHCMP1SCR_CFR_IE_MASK));
}

/*!
 * @brief Disables interrupts for phase comparator 1 (PHCMP1SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref phd_comparator_interrupt_t values.
 */
static inline void PHD_DisableComparator1Interrupts(PHD_Type *base, uint32_t mask)
{
    base->PHCMP1SCR &= MCUX_MASK_INVERT_32(mask & (PHD_PHCMP1SCR_CFF_IE_MASK | PHD_PHCMP1SCR_CFR_IE_MASK));
}

/*!
 * @brief Enables interrupts for phase comparator 2 (PHCMP2SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref phd_comparator_interrupt_t values.
 */
static inline void PHD_EnableComparator2Interrupts(PHD_Type *base, uint32_t mask)
{
    base->PHCMP2SCR |= (mask & (PHD_PHCMP2SCR_CFF_IE_MASK | PHD_PHCMP2SCR_CFR_IE_MASK));
}

/*!
 * @brief Disables interrupts for phase comparator 2 (PHCMP2SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref phd_comparator_interrupt_t values.
 */
static inline void PHD_DisableComparator2Interrupts(PHD_Type *base, uint32_t mask)
{
    base->PHCMP2SCR &= MCUX_MASK_INVERT_32(mask & (PHD_PHCMP2SCR_CFF_IE_MASK | PHD_PHCMP2SCR_CFR_IE_MASK));
}

/*! @} */

/*!
 * @name Status flags
 * @{
 */

/*!
 * @brief Returns the status flags for phase comparator 0 (PHCMP0SCR).
 *
 * @param base PHD peripheral base address.
 * @return OR-combination of @ref phd_comparator_status_flag_t values currently asserted.
 */
static inline uint32_t PHD_GetComparator0StatusFlags(PHD_Type *base)
{
    return base->PHCMP0SCR & (PHD_PHCMP0SCR_COUT_MASK | PHD_PHCMP0SCR_CFF_MASK | PHD_PHCMP0SCR_CFR_MASK);
}

/*!
 * @brief Clears W1C status flags for phase comparator 0 (PHCMP0SCR).
 *
 * COUT is read-only and is masked out; only CFF and CFR are cleared.
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref kPHD_ComparatorFallingFlag and/or @ref kPHD_ComparatorRisingFlag.
 */
static inline void PHD_ClearComparator0StatusFlags(PHD_Type *base, uint32_t mask)
{
    uint32_t reg = base->PHCMP0SCR;

    reg &= MCUX_MASK_INVERT_32(PHD_PHCMP0SCR_CFF_MASK | PHD_PHCMP0SCR_CFR_MASK);
    reg |= (mask & (PHD_PHCMP0SCR_CFF_MASK | PHD_PHCMP0SCR_CFR_MASK));
    base->PHCMP0SCR = reg;
}

/*!
 * @brief Returns the status flags for phase comparator 1 (PHCMP1SCR).
 *
 * @param base PHD peripheral base address.
 * @return OR-combination of @ref phd_comparator_status_flag_t values currently asserted.
 */
static inline uint32_t PHD_GetComparator1StatusFlags(PHD_Type *base)
{
    return base->PHCMP1SCR & (PHD_PHCMP1SCR_COUT_MASK | PHD_PHCMP1SCR_CFF_MASK | PHD_PHCMP1SCR_CFR_MASK);
}

/*!
 * @brief Clears W1C status flags for phase comparator 1 (PHCMP1SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref kPHD_ComparatorFallingFlag and/or @ref kPHD_ComparatorRisingFlag.
 */
static inline void PHD_ClearComparator1StatusFlags(PHD_Type *base, uint32_t mask)
{
    uint32_t reg = base->PHCMP1SCR;

    reg &= MCUX_MASK_INVERT_32(PHD_PHCMP1SCR_CFF_MASK | PHD_PHCMP1SCR_CFR_MASK);
    reg |= (mask & (PHD_PHCMP1SCR_CFF_MASK | PHD_PHCMP1SCR_CFR_MASK));
    base->PHCMP1SCR = reg;
}

/*!
 * @brief Returns the status flags for phase comparator 2 (PHCMP2SCR).
 *
 * @param base PHD peripheral base address.
 * @return OR-combination of @ref phd_comparator_status_flag_t values currently asserted.
 */
static inline uint32_t PHD_GetComparator2StatusFlags(PHD_Type *base)
{
    return base->PHCMP2SCR & (PHD_PHCMP2SCR_COUT_MASK | PHD_PHCMP2SCR_CFF_MASK | PHD_PHCMP2SCR_CFR_MASK);
}

/*!
 * @brief Clears W1C status flags for phase comparator 2 (PHCMP2SCR).
 *
 * @param base PHD peripheral base address.
 * @param mask OR-combination of @ref kPHD_ComparatorFallingFlag and/or @ref kPHD_ComparatorRisingFlag.
 */
static inline void PHD_ClearComparator2StatusFlags(PHD_Type *base, uint32_t mask)
{
    uint32_t reg = base->PHCMP2SCR;

    reg &= MCUX_MASK_INVERT_32(PHD_PHCMP2SCR_CFF_MASK | PHD_PHCMP2SCR_CFR_MASK);
    reg |= (mask & (PHD_PHCMP2SCR_CFF_MASK | PHD_PHCMP2SCR_CFR_MASK));
    base->PHCMP2SCR = reg;
}

/*!
 * @brief Returns the current phase detector output word (PHASESTAT[PHASE]).
 *
 * Each bit corresponds to one comparator's filtered output (COUT):
 * bit 0 = PHCMP0, bit 1 = PHCMP1, bit 2 = PHCMP2.
 *
 * @param base PHD peripheral base address.
 * @return 3-bit phase status value.
 */
static inline uint8_t PHD_GetPhaseStatus(PHD_Type *base)
{
    return (uint8_t)(base->PHASESTAT & PHD_PHASESTAT_PHASE_MASK);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_PHD_H_ */
