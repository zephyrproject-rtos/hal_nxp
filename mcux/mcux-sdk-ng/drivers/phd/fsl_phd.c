/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_phd.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.phd"
#endif

#if defined(PHD_RSTS)
#define PHD_RESETS_ARRAY PHD_RSTS
#elif defined(PHD_RSTS_N)
#define PHD_RESETS_ARRAY PHD_RSTS_N
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map PHD instance number to base pointer. */
static PHD_Type *const s_phdBases[] = PHD_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to PHD clocks for each PHD instance. */
static const clock_ip_name_t s_phdClocks[] = PHD_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(PHD_RESETS_ARRAY)
/*! @brief Pointers to PHD resets for each instance. */
static const reset_ip_name_t s_phdResets[] = PHD_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Get the instance for PHD module.
 *
 * @param base PHD base address
 * @return Instance number if valid base address is provided, otherwise returns 0xFFFFFFFF
 */
uint32_t PHD_GetInstance(PHD_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_phdBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_phdBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    if (instance == ARRAY_SIZE(s_phdBases))
    {
        instance = 0xFFFFFFFFU; /* Return 0xFFFFFFFF if invalid base address is provided. */
    }

    return instance;
}

/*!
 * @brief Fills a phd_config_t with safe power-on defaults.
 *
 * @param config Pointer to a phd_config_t structure.
 */
void PHD_GetDefaultConfig(phd_config_t *config)
{
    assert(NULL != config);

    (void)memset(config, 0, sizeof(*config));

    config->enableComparatorInStopMode = false;
    config->hysteresisLevel            = kPHD_HysteresisLevel0;
    config->clockSource                = kPHD_FuncClockSource0;
    config->enableExternalNeutral      = false;
    config->enableInternalNeutral      = false;
    config->enableVirtualNetwork       = false;
    config->ibiasTrim                  = kPHD_IbiasTrimValue0;
    config->filterCount                = kPHD_FilterCountBypass;
    config->filterPeriod               = 0U;
}

/*!
 * @brief Initialize the PHD module.
 *
 * @param base PHD peripheral base address.
 * @retval kStatus_Success if initialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t PHD_Init(PHD_Type *base, const phd_config_t *config)
{
    assert(NULL != config);

    uint32_t instance = PHD_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_phdBases))
    {
        /* Invalid instance, do not attempt to initialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_phdClocks[instance]);
#endif

#if defined(PHD_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_phdResets[instance]);
#endif

    /*
     * Configure PHASECTRL via RMW. CMP_EN is forced to 0; use PHD_EnableComparator()
     * after all comparator channels are configured.
     */
    uint32_t reg = base->PHASECTRL;

    reg &= MCUX_MASK_INVERT_32(PHD_PHASECTRL_CMP_EN_MASK | PHD_PHASECTRL_CMP_STOP_EN_MASK |
                               PHD_PHASECTRL_HYSTCTR_MASK | PHD_PHASECTRL_FUNC_CLK_SEL_MASK |
                               PHD_PHASECTRL_EXTSEL_MASK | PHD_PHASECTRL_INTSEL_MASK |
                               PHD_PHASECTRL_VNEN_MASK | PHD_PHASECTRL_IBIAS_TRIM_MASK |
                               PHD_PHASECTRL_FILT_CNT_MASK | PHD_PHASECTRL_FILT_PER_MASK);

    /*
     * CMP_EN and PHSEL0/1/2 intentionally omitted: use PHD_EnableComparator()
     * and PHD_SetPhaseSelect() at runtime.
     */
    reg |= (config->enableComparatorInStopMode) ? PHD_PHASECTRL_CMP_STOP_EN_MASK : 0U;
    reg |= PHD_PHASECTRL_HYSTCTR(config->hysteresisLevel);
    reg |= PHD_PHASECTRL_FUNC_CLK_SEL(config->clockSource);
    reg |= (config->enableExternalNeutral) ? PHD_PHASECTRL_EXTSEL_MASK : 0U;
    reg |= (config->enableInternalNeutral) ? PHD_PHASECTRL_INTSEL_MASK : 0U;
    reg |= (config->enableVirtualNetwork) ? PHD_PHASECTRL_VNEN_MASK : 0U;
    reg |= PHD_PHASECTRL_IBIAS_TRIM(config->ibiasTrim);
    reg |= PHD_PHASECTRL_FILT_CNT(config->filterCount);
    reg |= PHD_PHASECTRL_FILT_PER(config->filterPeriod);

    base->PHASECTRL = reg;

    return kStatus_Success;
}

/*!
 * @brief Deinitialize the PHD module.
 *
 * @param base PHD peripheral base address.
 * @retval kStatus_Success if deinitialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t PHD_DeInit(PHD_Type *base)
{
    uint32_t instance = PHD_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_phdBases))
    {
        /* Invalid instance, do not attempt to deinitialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_phdClocks[instance]);
#endif

#if defined(PHD_RESETS_ARRAY)
    RESET_PeripheralReset(s_phdResets[instance]);
#endif

    return kStatus_Success;
}

/*!
 * @brief Fills a phd_comparator_config_t with power-on defaults.
 *
 * @param config Pointer to a phd_comparator_config_t structure.
 */
void PHD_GetDefaultComparatorConfig(phd_comparator_config_t *config)
{
    assert(NULL != config);

    (void)memset(config, 0, sizeof(*config));

    config->outputSelect     = kPHD_OutputFiltered;
    config->enableOutputPin  = false;
    config->invertOutput     = false;
    config->enableWindowMode = false;
    config->enableSampleMode = false;
}

/*!
 * @brief Configures phase comparator 0 (PHCMP0CR).
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_comparator_config_t structure.
 */
void PHD_ConfigComparator0(PHD_Type *base, const phd_comparator_config_t *config)
{
    assert(NULL != config);

    uint32_t reg;

    /* Clear CFF/CFR glitch flags before configuring (W1C). */
    base->PHCMP0SCR |= (PHD_PHCMP0SCR_CFF_MASK | PHD_PHCMP0SCR_CFR_MASK);

    /* Configure PHCMP0CR via RMW. */
    reg = base->PHCMP0CR;

    reg &= MCUX_MASK_INVERT_32(PHD_PHCMP0CR_COUT_PEN_MASK | PHD_PHCMP0CR_COUT_SEL_MASK |
                               PHD_PHCMP0CR_COUT_INV_MASK | PHD_PHCMP0CR_WINDOW_EN_MASK |
                               PHD_PHCMP0CR_SAMPLE_EN_MASK);

    reg |= PHD_PHCMP0CR_COUT_SEL(config->outputSelect);
    reg |= (config->enableOutputPin) ? PHD_PHCMP0CR_COUT_PEN_MASK : 0U;
    reg |= (config->invertOutput) ? PHD_PHCMP0CR_COUT_INV_MASK : 0U;
    reg |= (config->enableWindowMode) ? PHD_PHCMP0CR_WINDOW_EN_MASK : 0U;
    reg |= (config->enableSampleMode) ? PHD_PHCMP0CR_SAMPLE_EN_MASK : 0U;

    base->PHCMP0CR = reg;
}

/*!
 * @brief Configures phase comparator 1 (PHCMP1CR).
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_comparator_config_t structure.
 */
void PHD_ConfigComparator1(PHD_Type *base, const phd_comparator_config_t *config)
{
    assert(NULL != config);

    uint32_t reg;

    /* Clear CFF/CFR glitch flags before configuring (W1C). */
    base->PHCMP1SCR |= (PHD_PHCMP1SCR_CFF_MASK | PHD_PHCMP1SCR_CFR_MASK);

    /* Configure PHCMP1CR via RMW. */
    reg = base->PHCMP1CR;

    reg &= MCUX_MASK_INVERT_32(PHD_PHCMP1CR_COUT_PEN_MASK | PHD_PHCMP1CR_COUT_SEL_MASK |
                               PHD_PHCMP1CR_COUT_INV_MASK | PHD_PHCMP1CR_WINDOW_EN_MASK |
                               PHD_PHCMP1CR_SAMPLE_EN_MASK);

    reg |= PHD_PHCMP1CR_COUT_SEL(config->outputSelect);
    reg |= (config->enableOutputPin) ? PHD_PHCMP1CR_COUT_PEN_MASK : 0U;
    reg |= (config->invertOutput) ? PHD_PHCMP1CR_COUT_INV_MASK : 0U;
    reg |= (config->enableWindowMode) ? PHD_PHCMP1CR_WINDOW_EN_MASK : 0U;
    reg |= (config->enableSampleMode) ? PHD_PHCMP1CR_SAMPLE_EN_MASK : 0U;

    base->PHCMP1CR = reg;
}

/*!
 * @brief Configures phase comparator 2 (PHCMP2CR).
 *
 * @param base   PHD peripheral base address.
 * @param config Pointer to a phd_comparator_config_t structure.
 */
void PHD_ConfigComparator2(PHD_Type *base, const phd_comparator_config_t *config)
{
    assert(NULL != config);

    uint32_t reg;

    /* Clear CFF/CFR glitch flags before configuring (W1C). */
    base->PHCMP2SCR |= (PHD_PHCMP2SCR_CFF_MASK | PHD_PHCMP2SCR_CFR_MASK);

    /* Configure PHCMP2CR via RMW. */
    reg = base->PHCMP2CR;

    reg &= MCUX_MASK_INVERT_32(PHD_PHCMP2CR_COUT_PEN_MASK | PHD_PHCMP2CR_COUT_SEL_MASK |
                               PHD_PHCMP2CR_COUT_INV_MASK | PHD_PHCMP2CR_WINDOW_EN_MASK |
                               PHD_PHCMP2CR_SAMPLE_EN_MASK);

    reg |= PHD_PHCMP2CR_COUT_SEL(config->outputSelect);
    reg |= (config->enableOutputPin) ? PHD_PHCMP2CR_COUT_PEN_MASK : 0U;
    reg |= (config->invertOutput) ? PHD_PHCMP2CR_COUT_INV_MASK : 0U;
    reg |= (config->enableWindowMode) ? PHD_PHCMP2CR_WINDOW_EN_MASK : 0U;
    reg |= (config->enableSampleMode) ? PHD_PHCMP2CR_SAMPLE_EN_MASK : 0U;

    base->PHCMP2CR = reg;
}
