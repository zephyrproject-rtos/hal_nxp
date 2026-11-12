/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2023, 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pint.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pint"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined(GPIOINT_RSTS_N)
#define PINT_RESETS_ARRAY GPIOINT_RSTS_N
#elif defined(PINT_RSTS)
#define PINT_RESETS_ARRAY PINT_RSTS
#elif defined(GPIO_RSTS_N)
#define PINT_RESETS_ARRAY GPIO_RSTS_N
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map PINT instance number to base pointer. */
static PINT_Type *const s_pintBases[] = PINT_BASE_PTRS;

#if defined(PINT_RESETS_ARRAY)
/*! @brief Reset array */
static const reset_ip_name_t s_pintResets[] = PINT_RESETS_ARRAY;
#endif

/*! @brief Irq number array, sized from the PINT_IRQS initializer so it fits any
 * combination of PINT instances and per-instance interrupt counts. */
static const IRQn_Type s_pintIRQ[] = PINT_IRQS;

/*! @brief Array to map PINT instance number to clock name. */
static const clock_ip_name_t s_pintClocks[] = PINT_CLOCKS;

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
/*! @brief Deprecated per-event callback array, one slot per connected output across
 * all PINT instances. */
static pint_cb_t s_pintCallback[ARRAY_SIZE(s_pintIRQ)];
#else
static pint_cb_t s_pintCallback[ARRAY_SIZE(s_pintBases)];
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * @param base The PINT peripheral base address.
 * @return PINT instance number starting from 0.
 */
static uint32_t PINT_GetInstance(PINT_Type *base)
{
    uint32_t instance;
    for (instance = 0; instance < ARRAY_SIZE(s_pintBases); ++instance)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_pintBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_pintBases));

    return instance;
}

/*!
 * @brief Returns the number of connected outputs (pin interrupts) for a PINT base.
 *
 * @param base The PINT peripheral base address.
 * @return Connected-output count for that base, clamped to a non-negative value.
 */
static uint32_t PINT_GetIRQCount(PINT_Type *base)
{
    int32_t count = (int32_t)FSL_FEATURE_PINT_NUMBER_OF_CONNECTED_OUTPUTSn(base);

    return (count > 0) ? (uint32_t)count : 0U;
}

/*!
 * @brief Returns the offset of a PINT instance's first IRQ within s_pintIRQ[].
 *
 * @param instance PINT instance number.
 * @return Index of the instance's IRQ 0 in s_pintIRQ[].
 */
static uint32_t PINT_GetIRQBaseIndex(uint32_t instance)
{
    uint32_t index = 0U;

    assert(instance < ARRAY_SIZE(s_pintBases));

    for (uint32_t i = 0U; i < instance; i++)
    {
        index += PINT_GetIRQCount(s_pintBases[i]);
    }

    return index;
}

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
/*!
 * @brief Returns a base instance's flat slot in the legacy per-event s_pintCallback[] array.
 *
 * @param base The PINT peripheral base address.
 * @param idx Pin/bit-slice index local to that instance.
 * @return Flat index into s_pintCallback[], unique across all instances.
 */
static uint32_t PINT_GetCbIdx(PINT_Type *base, uint32_t idx)
{
    return PINT_GetIRQBaseIndex(PINT_GetInstance(base)) + idx;
}
#endif /* PINT_USE_LEGACY_CALLBACK */

/*!
 * brief Initialize PINT peripheral.

 * This function initializes the PINT peripheral and enables the clock.
 *
 * param base Base address of the PINT peripheral.
 *
 * retval None.
 */
void PINT_Init(PINT_Type *base)
{
    assert(base != NULL);

    uint32_t irqCount = 0U;
    uint32_t pmcfg    = 0;
    uint32_t instance;
    uint32_t i;

    instance = PINT_GetInstance(base);
    irqCount = PINT_GetIRQCount(base);
#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    uint32_t irqBase = PINT_GetIRQBaseIndex(instance);
    for (i = 0; i < irqCount; i++)
    {
        s_pintCallback[irqBase + i] = NULL;
    }
#else
    s_pintCallback[instance] = NULL;
#endif /* PINT_USE_LEGACY_CALLBACK */

    /* Disable all bit slices for pint*/
    for (i = 0; i < irqCount; i++)
    {
        pmcfg = pmcfg | ((uint32_t)kPINT_PatternMatchNever << (PININT_BITSLICE_CFG_START + (i * 3U)));
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    if (instance < ARRAY_SIZE(s_pintClocks))
    {
        CLOCK_EnableClock(s_pintClocks[instance]);
    }
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(PINT_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_pintResets[instance]);
#endif /* PINT_RESETS_ARRAY */

    /* Disable all pattern match bit slices */
    base->PMCFG = pmcfg;
}

#if (defined(PINT_USE_LEGACY_CALLBACK) && (!PINT_USE_LEGACY_CALLBACK))
void PINT_SetCallback(PINT_Type *base, pint_cb_t callback)
{
    uint32_t instance = PINT_GetInstance(base);

    s_pintCallback[instance] = callback;
}
#endif

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
/*!
 * brief	Configure PINT peripheral pin interrupt.

 * This function configures a given pin interrupt.
 *
 * param base Base address of the PINT peripheral.
 * param intr Pin interrupt.
 * param enable Selects detection logic.
 * param callback Callback.
 *
 * retval None.
 */
void PINT_PinInterruptConfig(PINT_Type *base, pint_pin_int_t intr, pint_pin_enable_t enable, pint_cb_t callback)
#else
/*!
 * brief	Configure PINT peripheral pin interrupt.

 * This function configures a given pin interrupt.
 *
 * param base Base address of the PINT peripheral.
 * param intr Pin interrupt.
 * param enable Selects detection logic.
 *
 * retval None.
 */
void PINT_PinInterruptConfig(PINT_Type *base, pint_pin_int_t intr, pint_pin_enable_t enable)
#endif
{
    assert(base != NULL);
    assert((uint32_t)intr < PINT_GetIRQCount(base));

    /* Clear Rise and Fall flags first */
    PINT_PinInterruptClrRiseFlag(base, intr);
    PINT_PinInterruptClrFallFlag(base, intr);

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    s_pintCallback[PINT_GetCbIdx(base, (uint32_t)intr)] = callback;
#endif

    /* select level or edge sensitive */
    base->ISEL = (base->ISEL & ~(1UL << (uint32_t)intr)) |
                 ((((uint32_t)enable & PINT_PIN_INT_LEVEL) != 0U) ? (1UL << (uint32_t)intr) : 0U);

    /* enable rising or level interrupt */
    if (((unsigned)enable & (PINT_PIN_INT_LEVEL | PINT_PIN_INT_RISE)) != 0U)
    {
        base->SIENR = 1UL << (uint32_t)intr;
    }
    else
    {
        base->CIENR = 1UL << (uint32_t)intr;
    }

    /* Enable falling or select high level */
    if (((unsigned)enable & PINT_PIN_INT_FALL_OR_HIGH_LEVEL) != 0U)
    {
        base->SIENF = 1UL << (uint32_t)intr;
    }
    else
    {
        base->CIENF = 1UL << (uint32_t)intr;
    }
}

/*!
 * brief	Get PINT peripheral pin interrupt configuration.

 * This function returns the configuration of a given pin interrupt.
 *
 * param base Base address of the PINT peripheral.
 * param pintr Pin interrupt.
 * param enable Pointer to store the detection logic.
 * param callback Callback.
 *
 * retval None.
 */
#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
void PINT_PinInterruptGetConfig(PINT_Type *base, pint_pin_int_t pintr, pint_pin_enable_t *enable, pint_cb_t *callback)
#else
void PINT_PinInterruptGetConfig(PINT_Type *base, pint_pin_int_t pintr, pint_pin_enable_t *enable)
#endif
{
    assert(base != NULL);
    assert((uint32_t)pintr < PINT_GetIRQCount(base));

    uint32_t mask;
    bool level;

    *enable = kPINT_PinIntEnableNone;
    level   = false;

    mask = 1UL << (uint32_t)pintr;
    if ((base->ISEL & mask) != 0U)
    {
        /* Pin interrupt is level sensitive */
        level = true;
    }

    if ((base->IENR & mask) != 0U)
    {
        if (level)
        {
            /* Level interrupt is enabled */
            *enable = kPINT_PinIntEnableLowLevel;
        }
        else
        {
            /* Rising edge interrupt */
            *enable = kPINT_PinIntEnableRiseEdge;
        }
    }

    if ((base->IENF & mask) != 0U)
    {
        if (level)
        {
            /* Level interrupt is active high */
            *enable = kPINT_PinIntEnableHighLevel;
        }
        else
        {
            /* Either falling or both edge */
            if (*enable == kPINT_PinIntEnableRiseEdge)
            {
                /* Rising and faling edge */
                *enable = kPINT_PinIntEnableBothEdges;
            }
            else
            {
                /* Falling edge */
                *enable = kPINT_PinIntEnableFallEdge;
            }
        }
    }

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    *callback = s_pintCallback[PINT_GetCbIdx(base, (uint32_t)pintr)];
#endif
}

/*!
 * brief	Configure PINT pattern match.

 * This function configures a given pattern match bit slice.
 *
 * param base Base address of the PINT peripheral.
 * param bslice Pattern match bit slice number.
 * param cfg Pointer to bit slice configuration.
 *
 * retval None.
 */
void PINT_PatternMatchConfig(PINT_Type *base, pint_pmatch_bslice_t bslice, pint_pmatch_cfg_t *cfg)
{
    uint32_t src_shift;
    uint32_t cfg_shift;
    uint32_t pmcfg;
    uint32_t tmp_src_shift = PININT_BITSLICE_SRC_MASK;
    uint32_t tmp_cfg_shift = PININT_BITSLICE_CFG_MASK;

    assert(base != NULL);

    src_shift = PININT_BITSLICE_SRC_START + ((uint32_t)bslice * 3UL);
    cfg_shift = PININT_BITSLICE_CFG_START + ((uint32_t)bslice * 3UL);

    /* Input source selection for selected bit slice */
    base->PMSRC = (base->PMSRC & ~(tmp_src_shift << src_shift)) | ((uint32_t)(cfg->bs_src) << src_shift);

    /* Bit slice configuration */
    pmcfg = base->PMCFG;
    pmcfg = (pmcfg & ~(tmp_cfg_shift << cfg_shift)) | ((uint32_t)(cfg->bs_cfg) << cfg_shift);

    /* If end point is true, enable the bits */
    if ((uint32_t)bslice != 7UL)
    {
        if (cfg->end_point)
        {
            pmcfg |= (1UL << (uint32_t)bslice);
        }
        else
        {
            pmcfg &= ~(1UL << (uint32_t)bslice);
        }
    }

    base->PMCFG = pmcfg;

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    /* Save callback pointer */
    if ((uint32_t)bslice < PINT_GetIRQCount(base))
    {
        s_pintCallback[PINT_GetCbIdx(base, (uint32_t)bslice)] = cfg->callback;
    }
#endif
}

/*!
 * brief	Get PINT pattern match configuration.

 * This function returns the configuration of a given pattern match bit slice.
 *
 * param base Base address of the PINT peripheral.
 * param bslice Pattern match bit slice number.
 * param cfg Pointer to bit slice configuration.
 *
 * retval None.
 */
void PINT_PatternMatchGetConfig(PINT_Type *base, pint_pmatch_bslice_t bslice, pint_pmatch_cfg_t *cfg)
{
    uint32_t src_shift;
    uint32_t cfg_shift;
    uint32_t tmp_src_shift = PININT_BITSLICE_SRC_MASK;
    uint32_t tmp_cfg_shift = PININT_BITSLICE_CFG_MASK;

    assert(base != NULL);

    src_shift = PININT_BITSLICE_SRC_START + ((uint32_t)bslice * 3UL);
    cfg_shift = PININT_BITSLICE_CFG_START + ((uint32_t)bslice * 3UL);

    cfg->bs_src = (pint_pmatch_input_src_t)(uint32_t)(((base->PMSRC & (tmp_src_shift << src_shift)) >> src_shift) &
                                                      PININT_BITSLICE_SRC_MASK);
    cfg->bs_cfg = (pint_pmatch_bslice_cfg_t)(uint32_t)(((base->PMCFG & (tmp_cfg_shift << cfg_shift)) >> cfg_shift) &
                                                       PININT_BITSLICE_CFG_MASK);

    if ((uint32_t)bslice == 7U)
    {
        cfg->end_point = true;
    }
    else
    {
        cfg->end_point = (((base->PMCFG & (1UL << (uint32_t)bslice)) >> (uint32_t)bslice) != 0U) ? true : false;
    }

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    if ((uint32_t)bslice < PINT_GetIRQCount(base))
    {
        cfg->callback = s_pintCallback[PINT_GetCbIdx(base, (uint32_t)bslice)];
    }
#endif
}

/*!
 * brief	Reset pattern match detection logic.

 * This function resets the pattern match detection logic if any of the product term is matching.
 *
 * param base Base address of the PINT peripheral.
 *
 * retval pmstatus Each bit position indicates the match status of corresponding bit slice.
 * = 0 Match was detected.  = 1 Match was not detected.
 */
uint32_t PINT_PatternMatchResetDetectLogic(PINT_Type *base)
{
    uint32_t pmctrl;
    uint32_t pmstatus;
    uint32_t pmsrc;

    pmctrl   = base->PMCTRL;
    pmstatus = pmctrl >> PINT_PMCTRL_PMAT_SHIFT;
    if (pmstatus != 0UL)
    {
        /* Reset Pattern match engine detection logic */
        pmsrc       = base->PMSRC;
        base->PMSRC = pmsrc;
    }
    return (pmstatus);
}

/*!
 * @brief	Clear Selected pin interrupt status only when the pin was triggered by edge-sensitive.

 * This function clears the selected pin interrupt status.
 *
 * @param base Base address of the PINT peripheral.
 * @param pintr Pin interrupt.
 *
 * @retval None.
 */
void PINT_PinInterruptClrStatus(PINT_Type *base, pint_pin_int_t pintr)
{
    assert(base != NULL);
    assert((uint32_t)pintr < PINT_GetIRQCount(base));

    uint32_t pinIntMode   = base->ISEL & (1UL << (uint32_t)pintr);
    uint32_t pinIntStatus = base->IST & (1UL << (uint32_t)pintr);

    /* Edge sensitive and pin interrupt that is currently requesting an interrupt. */
    if ((pinIntMode == 0x0UL) && (pinIntStatus != 0x0UL))
    {
        base->IST = (1UL << (uint32_t)pintr);
    }
}

/*!
 * @brief	Clear all pin interrupts status only when pins were triggered by edge-sensitive.

 * This function clears the status of all pin interrupts.
 *
 * @param base Base address of the PINT peripheral.
 *
 * @retval None.
 */
void PINT_PinInterruptClrStatusAll(PINT_Type *base)
{
    uint32_t pinIntMode   = 0;
    uint32_t pinIntStatus = 0;
    uint32_t pinIntCount  = 0;
    uint32_t mask         = 0;
    uint32_t i;

    pinIntCount = PINT_GetIRQCount(base);

    for (i = 0; i < pinIntCount; i++)
    {
        pinIntMode   = base->ISEL & (1UL << i);
        pinIntStatus = base->IST & (1UL << i);

        /* Edge sensitive and pin interrupt that is currently requesting an interrupt. */
        if ((pinIntMode == 0x0UL) && (pinIntStatus != 0x0UL))
        {
            mask |= 1UL << i;
        }
    }

    base->IST = mask;
}

/*!
 * brief	Enable callback.

 * This function enables the interrupt for the selected PINT peripheral. Although the pin(s) are monitored
 * as soon as they are enabled, the callback function is not enabled until this function is called.
 *
 * param base Base address of the PINT peripheral.
 *
 * retval None.
 */
void PINT_EnableCallback(PINT_Type *base)
{
    uint32_t instance = PINT_GetInstance(base);
    uint32_t count    = PINT_GetIRQCount(base);
    uint32_t irqBase  = PINT_GetIRQBaseIndex(instance);
    uint32_t i;

    assert(base != NULL);

#if defined(FSL_FEATURE_PINT_INTERRUPT_COMBINE) && (FSL_FEATURE_PINT_INTERRUPT_COMBINE == 1)
    /* All outputs of the instance share a single IRQ line. */
    for (i = 0; i < count; i++)
    {
        PINT_PinInterruptClrStatus(base, (pint_pin_int_t)i);
    }
    NVIC_ClearPendingIRQ(s_pintIRQ[irqBase]);
    (void)EnableIRQ(s_pintIRQ[irqBase]);
#else
    for (i = 0; i < count; i++)
    {
        PINT_PinInterruptClrStatus(base, (pint_pin_int_t)i);
        NVIC_ClearPendingIRQ(s_pintIRQ[irqBase + i]);
        (void)EnableIRQ(s_pintIRQ[irqBase + i]);
    }
#endif
}

/*!
 * brief	enable callback by pin index.

 * This function  enables callback by pin index instead of enabling all pins.
 *
 * param base Base address of the peripheral.
 * param pinIdx pin index.
 *
 * retval None.
 */
void PINT_EnableCallbackByIndex(PINT_Type *base, pint_pin_int_t pintIdx)
{
    assert(base != NULL);
    assert((uint32_t)pintIdx < PINT_GetIRQCount(base));

    PINT_PinInterruptClrStatus(base, (pint_pin_int_t)pintIdx);

    uint32_t irqBase = PINT_GetIRQBaseIndex(PINT_GetInstance(base));
#if defined(FSL_FEATURE_PINT_INTERRUPT_COMBINE) && (FSL_FEATURE_PINT_INTERRUPT_COMBINE == 1)
    uint32_t irqIndex = irqBase;
#else
    uint32_t irqIndex = irqBase + (uint32_t)pintIdx;
#endif
    NVIC_ClearPendingIRQ(s_pintIRQ[irqIndex]);
    (void)EnableIRQ(s_pintIRQ[irqIndex]);
}

/*!
 * brief	Disable callback.

 * This function disables the interrupt for the selected PINT peripheral. Although the pins are still
 * being monitored but the callback function is not called.
 *
 * param base Base address of the peripheral.
 *
 * retval None.
 */
void PINT_DisableCallback(PINT_Type *base)
{
    assert(base != NULL);

    uint32_t instance = PINT_GetInstance(base);
    uint32_t count    = PINT_GetIRQCount(base);
    uint32_t irqBase  = PINT_GetIRQBaseIndex(instance);
    uint32_t i;

#if defined(FSL_FEATURE_PINT_INTERRUPT_COMBINE) && (FSL_FEATURE_PINT_INTERRUPT_COMBINE == 1)
    /* All outputs of the instance share a single IRQ line. */
    (void)DisableIRQ(s_pintIRQ[irqBase]);
    for (i = 0; i < count; i++)
    {
        PINT_PinInterruptClrStatus(base, (pint_pin_int_t)i);
    }
    NVIC_ClearPendingIRQ(s_pintIRQ[irqBase]);
#else
    for (i = 0; i < count; i++)
    {
        (void)DisableIRQ(s_pintIRQ[irqBase + i]);
        PINT_PinInterruptClrStatus(base, (pint_pin_int_t)i);
        NVIC_ClearPendingIRQ(s_pintIRQ[irqBase + i]);
    }
#endif
}

/*!
 * brief disable callback by pin index.

 * This function disables callback by pin index instead of disabling all pins.
 *
 * param base Base address of the peripheral.
 * param pinIdx pin index.
 *
 * retval None.
 */
void PINT_DisableCallbackByIndex(PINT_Type *base, pint_pin_int_t pintIdx)
{
    assert(base != NULL);
    assert((uint32_t)pintIdx < PINT_GetIRQCount(base));

    uint32_t instance = PINT_GetInstance(base);
    uint32_t irqBase  = PINT_GetIRQBaseIndex(instance);
#if defined(FSL_FEATURE_PINT_INTERRUPT_COMBINE) && (FSL_FEATURE_PINT_INTERRUPT_COMBINE == 1)
    uint32_t irqIndex = irqBase;
#else
    uint32_t irqIndex = irqBase + (uint32_t)pintIdx;
#endif
    (void)DisableIRQ(s_pintIRQ[irqIndex]);
    PINT_PinInterruptClrStatus(base, (pint_pin_int_t)pintIdx);
    NVIC_ClearPendingIRQ(s_pintIRQ[irqIndex]);
}

/*!
 * brief enable interrupt in NVIC by pin index.

 * This function enables the interrupt in the NVIC. The difference with
 * PINT_EnableCallbackByIndex() is that PINT_EnableCallbackByIndex() not
 * only enables the interrupt in the NVIC but also clears pending interrupts.
 * Use this function together with PINT_DisableInterruptByIndex() to
 * temporarily disable/enable the pin interrupt.
 * Use PINT_EnableCallbackByIndex() to enable the interrupt after installing
 * the callback.
 *
 * param base Base address of the peripheral.
 * param pinIdx pin index.
 *
 * retval None.
 */
void PINT_EnableInterruptByIndex(PINT_Type *base, pint_pin_int_t pintIdx)
{
    assert(base != NULL);
    assert((uint32_t)pintIdx < PINT_GetIRQCount(base));

    uint32_t irqBase = PINT_GetIRQBaseIndex(PINT_GetInstance(base));
#if defined(FSL_FEATURE_PINT_INTERRUPT_COMBINE) && (FSL_FEATURE_PINT_INTERRUPT_COMBINE == 1)
    (void)EnableIRQ(s_pintIRQ[irqBase]);
#else
    (void)EnableIRQ(s_pintIRQ[irqBase + (uint32_t)pintIdx]);
#endif
}

/*!
 * brief disable interrupt in NVIC by pin index.

 * This function disables the interrupt in the NVIC. The difference with
 * PINT_DisableCallbackByIndex() is that PINT_DisableCallbackByIndex() not
 * only disables the interrupt in the NVIC but also clears pending interrupts.
 * Use this function together with PINT_EnableInterruptByIndex() to
 * temporarily disable/enable the pin interrupt.
 * Use PINT_DisableCallbackByIndex() to disable the interrupt in a de-init function.
 *
 * param base Base address of the peripheral.
 * param pinIdx pin index.
 *
 * retval None.
 */
void PINT_DisableInterruptByIndex(PINT_Type *base, pint_pin_int_t pintIdx)
{
    assert(base != NULL);
    assert((uint32_t)pintIdx < PINT_GetIRQCount(base));

    uint32_t instance = PINT_GetInstance(base);
    uint32_t irqBase  = PINT_GetIRQBaseIndex(instance);
#if defined(FSL_FEATURE_PINT_INTERRUPT_COMBINE) && (FSL_FEATURE_PINT_INTERRUPT_COMBINE == 1)
    (void)DisableIRQ(s_pintIRQ[irqBase]);
#else
    (void)DisableIRQ(s_pintIRQ[irqBase + (uint32_t)pintIdx]);
#endif
}

/*!
 * brief	Deinitialize PINT peripheral.

 * This function disables the PINT clock.
 *
 * param base Base address of the PINT peripheral.
 *
 * retval None.
 */
void PINT_Deinit(PINT_Type *base)
{
    assert(base != NULL);

    uint32_t instance = PINT_GetInstance(base);

    /* Bypass unused warning. */
    (void)instance;

    /* Cleanup */
    PINT_DisableCallback(base);

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    /* Clear PINT callback array */
    uint32_t irqBase = PINT_GetIRQBaseIndex(instance);
    for (uint32_t i = 0; i < (uint32_t)PINT_GetIRQCount(base); i++)
    {
        s_pintCallback[irqBase + i] = NULL;
    }
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    if (instance < ARRAY_SIZE(s_pintClocks))
    {
        CLOCK_DisableClock(s_pintClocks[instance]);
    }
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

static void PINT_CommonIRQHandler(uint32_t instance, pint_pin_int_t pintr)
{
    PINT_Type *base          = s_pintBases[instance];
    pint_status_t pintStatus = {0};

    pintStatus.pmstatus        = PINT_PatternMatchResetDetectLogic(base);
    pintStatus.riseFlag        = (bool)PINT_PinInterruptGetRiseFlag(base, pintr);
    pintStatus.fallFlag        = (bool)PINT_PinInterruptGetFallFlag(base, pintr);
    pintStatus.activeLevelFlag = (bool)PINT_PinInterruptGetStatus(base, pintr);

    if (pintStatus.riseFlag)
    {
        PINT_PinInterruptClrRiseFlag(base, pintr);
    }
    if (pintStatus.fallFlag)
    {
        PINT_PinInterruptClrFallFlag(base, pintr);
    }

#if (defined(PINT_USE_LEGACY_CALLBACK) && PINT_USE_LEGACY_CALLBACK)
    uint32_t cbIdx = PINT_GetIRQBaseIndex(instance) + (uint32_t)pintr;
    if (s_pintCallback[cbIdx] != NULL)
    {
        s_pintCallback[cbIdx](pintr, &pintStatus);
    }
#else
    if (s_pintCallback[instance] != NULL)
    {
        s_pintCallback[instance](pintr, &pintStatus);
    }
#endif
}

void PINT_DriverIRQHandler(uint32_t instance)
{
    if (instance < ARRAY_SIZE(s_pintBases))
    {
        uint32_t flags =
            (s_pintBases[instance]->IST & PINT_IST_PSTAT_MASK) | PINT_PatternMatchGetStatusAll(s_pintBases[instance]);
        uint32_t count = PINT_GetIRQCount(s_pintBases[instance]);
        for (uint32_t i = 0U; i < count; i++)
        {
            if ((flags & (1UL << i)) != 0UL)
            {
                PINT_CommonIRQHandler(instance, (pint_pin_int_t)i);
            }
        }
    }
    SDK_ISR_EXIT_BARRIER;
}

void PINT0_DriverIRQHandler(void);
void PINT0_DriverIRQHandler(void)
{
    PINT_DriverIRQHandler(0);
}

#if defined(SECPINT)
/* For devices with secure PINT instance. */
void SEC_GPIO_INT0_IRQ0_DriverIRQHandler(void);
void SEC_GPIO_INT0_IRQ0_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(1U, kPINT_SecPinInt0);
    SDK_ISR_EXIT_BARRIER;
}

void SEC_GPIO_INT0_IRQ1_DriverIRQHandler(void);
void SEC_GPIO_INT0_IRQ1_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(1U, kPINT_SecPinInt1);
    SDK_ISR_EXIT_BARRIER;
}
#endif /* SECPINT */

/* IRQ handler functions overloading weak symbols in the startup */
void PIN_INT0_DriverIRQHandler(void);
void PIN_INT0_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(0, kPINT_PinInt0);
    SDK_ISR_EXIT_BARRIER;
}

void PIN_INT1_DriverIRQHandler(void);
void PIN_INT1_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(0, kPINT_PinInt1);
    SDK_ISR_EXIT_BARRIER;
}

void PIN_INT2_DriverIRQHandler(void);
void PIN_INT2_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(0, kPINT_PinInt2);
    SDK_ISR_EXIT_BARRIER;
}

void PIN_INT3_DriverIRQHandler(void);
void PIN_INT3_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(0, kPINT_PinInt3);
    SDK_ISR_EXIT_BARRIER;
}

void PIN_INT4_DriverIRQHandler(void);
void PIN_INT4_DriverIRQHandler(void)
{
    PINT_CommonIRQHandler(0, kPINT_PinInt4);
    SDK_ISR_EXIT_BARRIER;
}

#if defined(FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER) && FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER
void PIN_INT5_DAC1_IRQHandler(void);
void PIN_INT5_DAC1_IRQHandler(void)
#else
void PIN_INT5_DriverIRQHandler(void);
void PIN_INT5_DriverIRQHandler(void)
#endif /* FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER */
{
    PINT_CommonIRQHandler(0, kPINT_PinInt5);
    SDK_ISR_EXIT_BARRIER;
}

#if defined(FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER) && FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER
void PIN_INT6_USART3_IRQHandler(void);
void PIN_INT6_USART3_IRQHandler(void)
#else
void PIN_INT6_DriverIRQHandler(void);
void PIN_INT6_DriverIRQHandler(void)
#endif /* FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER */
{
    PINT_CommonIRQHandler(0, kPINT_PinInt6);
    SDK_ISR_EXIT_BARRIER;
}

#if defined(FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER) && FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER
void PIN_INT7_USART4_IRQHandler(void);
void PIN_INT7_USART4_IRQHandler(void)
#else
void PIN_INT7_DriverIRQHandler(void);
void PIN_INT7_DriverIRQHandler(void)
#endif /* FSL_FEATURE_NVIC_HAS_SHARED_INTERTTUPT_NUMBER */
{
    PINT_CommonIRQHandler(0, kPINT_PinInt7);
    SDK_ISR_EXIT_BARRIER;
}

#if defined(PINT0) && defined(PINT1)
/* Per-instance IRQ handlers for devices whose vector table names interrupts as
 * PINT<instance>_INT<pin>. */
#define PINT_DEFINE_IRQ_HANDLER(inst, pin)                    \
    void PINT##inst##_INT##pin##_DriverIRQHandler(void);      \
    void PINT##inst##_INT##pin##_DriverIRQHandler(void)       \
    {                                                         \
        PINT_CommonIRQHandler((inst), (pint_pin_int_t)(pin)); \
        SDK_ISR_EXIT_BARRIER;                                 \
    }

PINT_DEFINE_IRQ_HANDLER(0, 0)
PINT_DEFINE_IRQ_HANDLER(0, 1)
PINT_DEFINE_IRQ_HANDLER(0, 2)
PINT_DEFINE_IRQ_HANDLER(0, 3)
PINT_DEFINE_IRQ_HANDLER(0, 4)
PINT_DEFINE_IRQ_HANDLER(0, 5)
PINT_DEFINE_IRQ_HANDLER(0, 6)
PINT_DEFINE_IRQ_HANDLER(0, 7)
PINT_DEFINE_IRQ_HANDLER(1, 0)
PINT_DEFINE_IRQ_HANDLER(1, 1)
PINT_DEFINE_IRQ_HANDLER(1, 2)
PINT_DEFINE_IRQ_HANDLER(1, 3)

#endif /* defined(PINT0) && defined(PINT1) */
