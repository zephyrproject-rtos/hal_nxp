/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_slcd.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.slcd_split"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get the SLCD instance from peripheral base address.
 *
 * @param base SLCD peripheral base address.
 * @return SLCD instance.
 */
static uint32_t SLCD_GetInstance(SLCD_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to slcd clocks for each instance. */
static const clock_ip_name_t s_slcdControlClock[FSL_FEATURE_SOC_LCD_COUNT] = SLCD_CONTROL_CLOCKS;
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
static const clock_ip_name_t s_slcdFaultClock[FSL_FEATURE_SOC_LCD_COUNT]   = SLCD_FAULT_DETECT_CLOCKS;
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Pointers to slcd bases for each instance. */
static SGLCD_CONTROL_Type *const s_slcdBases[] = SGLCD_CONTROL_BASE_PTRS;

/*! @brief Pointers to slcd irqs. */
static const IRQn_Type s_slcdControlIRQ[] = SGLCD_CONTROL_IRQS;
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
static const IRQn_Type s_slcdFaultIRQ[]   = SGLCD_FAULT_DETECT_IRQS;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t SLCD_GetInstance(SLCD_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_slcdBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_slcdBases[instance]) == MSDK_REG_SECURE_ADDR(base->control))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_slcdBases));

    return instance;
}

/*!
 * brief Initializes the SLCD, ungates the module clock, initializes the power
 * setting, enables all used plane pins, and sets with interrupt and work mode
 * with the configuration.
 *
 * param base  SLCD peripheral base address.
 * param configure SLCD configuration pointer.
 *   For the configuration structure, many parameters have the default setting
 *   and the SGLCD_Getdefaultconfig() is provided to get them. Use it
 *   verified for their applications.
 *   The others have no default settings, such as "clkConfig", and must be provided
 *   by the application before calling the SGLCD_Init() API.
 */
void SLCD_Init(SLCD_Type *base, const slcd_config_t *configure)
{
    assert(configure != NULL);

    uint32_t gcrReg   = 0;
    uint32_t regNum   = 0;
    uint32_t instance = SLCD_GetInstance(base);

    /* Bit mask of the SGLCD_CONTROL_GCR to modify in this function. */
    uint32_t gcrMsk = 0;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Un-gate the SLCD clock. */
    CLOCK_EnableClock(s_slcdControlClock[instance]);
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    CLOCK_EnableClock(s_slcdFaultClock[instance]);
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    gcrMsk = SGLCD_CONTROL_GCR_DUTY_MASK | SGLCD_CONTROL_GCR_LCDSTP_MASK | SGLCD_CONTROL_GCR_LCLK_MASK | SGLCD_CONTROL_GCR_SHCYCLE_MASK |
             SGLCD_CONTROL_GCR_SHEN_MASK | SGLCD_CONTROL_GCR_VLL2TRIM_MASK | SGLCD_CONTROL_GCR_VLL1TRIM_MASK | SGLCD_CONTROL_GCR_LCDLP_MASK |
             SGLCD_CONTROL_GCR_LCDDOZE_MASK | SGLCD_CONTROL_GCR_LCDIEN_MASK;

    /* Configure the duty and set the work for low power wait and stop mode. Configure clock divider
       sample and hold setting, voltage trim, low power waveform, doze mode, and frame frequency interrupt. */
    gcrReg = SGLCD_CONTROL_GCR_DUTY(configure->dutyCycle) | SGLCD_CONTROL_GCR_LCDSTP((uint32_t)configure->lowPowerBehavior & 0x1U) |
             SGLCD_CONTROL_GCR_LCLK(configure->clkPrescaler) | SGLCD_CONTROL_GCR_SHCYCLE(configure->sampleHold & 0x1U) |
             SGLCD_CONTROL_GCR_SHEN((configure->sampleHold & 0x2U) >> 1U) | SGLCD_CONTROL_GCR_VLL2TRIM(configure->voltageTrimVLL2) |
             SGLCD_CONTROL_GCR_VLL1TRIM(configure->voltageTrimVLL1) | SGLCD_CONTROL_GCR_LCDLP(configure->lowPowerWaveform) |
             SGLCD_CONTROL_GCR_LCDDOZE(((uint32_t)configure->lowPowerBehavior >> 1U) & 0x1U) |
             SGLCD_CONTROL_GCR_LCDIEN(configure->frameFreqIntEnable);

    base->control->GCR = (base->control->GCR & ~gcrMsk) | gcrReg;

    /* Set display mode. */
    base->control->AR = SGLCD_CONTROL_AR_ALT((uint32_t)configure->displayMode & 0x1U) |
               SGLCD_CONTROL_AR_BLANK(((uint32_t)configure->displayMode >> 1U) & 0x1U);

    /* Configure the front plane and back plane pin setting. */
    base->control->BPEN[0] = configure->backPlaneLowPin;
    base->control->BPEN[1] = configure->backPlaneHighPin;
    base->control->PEN[0]  = configure->slcdLowPinEnabled;
    base->control->PEN[1]  = configure->slcdHighPinEnabled;

    /* Set the fault frame detection. */
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    base->fault->FDCR = 0;
    if ((NULL != configure->faultConfig) && (base->fault != NULL))
    {
        /* If fault configure structure is not NULL, the fault detection is enabled. */
        base->fault->FDCR = SGLCD_FAULT_DETECT_FDCR_FDPRS(configure->faultConfig->faultPrescaler) |
                     SGLCD_FAULT_DETECT_FDCR_FDSWW(configure->faultConfig->width) |
                     SGLCD_FAULT_DETECT_FDCR_FDBPEN(configure->faultConfig->faultDetectBackPlaneEnable ? 1U : 0U) |
                     SGLCD_FAULT_DETECT_FDCR_FDPINID(configure->faultConfig->faultDetectPinIndex) | SGLCD_FAULT_DETECT_FDCR_FDEN_MASK;
        if (configure->faultConfig->faultDetectIntEnable)
        {
            base->fault->FDCR |= SGLCD_FAULT_DETECT_FDCR_FDCIEN_MASK;
            (void)EnableIRQ(s_slcdFaultIRQ[instance]);
        }
    }
#endif

    /* Initialize the Waveform. */
    for (regNum = 0; regNum < SGLCD_CONTROL_WF_ACCESS_WF8BIT_WF8B_COUNT; regNum++)
    {
        base->control->WF8B[regNum] = 0;
    }

    /* Enable the NVIC. */
    if (configure->frameFreqIntEnable)
    {
        (void)EnableIRQ(s_slcdControlIRQ[instance]);
    }
}

/*!
 * brief Deinitializes the SLCD module, gates the module clock, disables an interrupt,
 * and displays the SLCD.
 *
 * param base  SLCD peripheral base address.
 */
void SLCD_Deinit(SLCD_Type *base)
{
    uint32_t instance = SLCD_GetInstance(base);

    /* Stop SLCD display. */
    SLCD_StopDisplay(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the SLCD clock. */
    CLOCK_DisableClock(s_slcdControlClock[instance]);
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    CLOCK_DisableClock(s_slcdFaultClock[instance]);
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Disable NVIC. */
    (void)DisableIRQ(s_slcdControlIRQ[instance]);

#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    (void)DisableIRQ(s_slcdFaultIRQ[instance]);
#endif
}

/*!
 * brief Gets the SLCD default configuration structure. The
 * purpose of this API is to get default parameters of the configuration structure
 * for the SGLCD_Init(). Use these initialized parameters unchanged in SGLCD_Init()
 * or modify fields of the structure before the calling SGLCD_Init().
 * All default parameters of the configure structuration are listed.
 * code
   config.displayMode        = kSLCD_NormalMode;
   config.powerSupply        = kSLCD_InternalVll3UseChargePump;
   config.voltageTrim        = kSLCD_RegulatedVolatgeTrim00;
   config.lowPowerBehavior   = kSLCD_EnabledInWaitStop;
   config.interruptSrc       = 0;
   config.faultConfig        = NULL;
   config.frameFreqIntEnable =  false;
   endcode
 * param configure The SLCD configuration structure pointer.
 */
void SLCD_GetDefaultConfig(slcd_config_t *configure)
{
    assert(configure);

    /* Initializes the configure structure to zero. */
    (void)memset(configure, 0, sizeof(*configure));

    /* Get Default parameters for the configuration structure. */
    configure->displayMode = kSLCD_NormalMode;
    configure->voltageTrimVLL1 = kSLCD_VolatgeTrimNo;
    configure->voltageTrimVLL2 = kSLCD_VolatgeTrimNo;
    configure->lowPowerWaveform = false;
    configure->sampleHold = kSLCD_SampleHoldNone;
    /* Work in low power mode. */
    configure->lowPowerBehavior = kSLCD_EnabledInWaitStop;
    /* No interrupt source is enabled. */
    configure->frameFreqIntEnable = false;
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    /* Fault detection is disabled. */
    configure->faultConfig = NULL;
#endif
}

/*!
 * brief Starts the SLCD blink mode.
 *
 * param base  SLCD peripheral base address.
 * param mode  SLCD blink mode.
 * param rate  SLCD blink rate.
 */
void SLCD_StartBlinkMode(SLCD_Type *base, slcd_blink_mode_t mode, slcd_blink_rate_t rate)
{
    uint32_t mask  = SGLCD_CONTROL_AR_BMODE_MASK | SGLCD_CONTROL_AR_BRATE_MASK | SGLCD_CONTROL_AR_LCDIF_MASK;
    uint32_t arReg = base->control->AR;

    /* Set blink mode and blink rate. */
    arReg = (arReg & ~mask) | SGLCD_CONTROL_AR_BMODE(mode) | SGLCD_CONTROL_AR_BRATE(rate);
    base->control->AR = arReg;

    /* Enable Blink after setting the blink rate to meet some hardware requirement. */
    arReg |= SGLCD_CONTROL_AR_BLINK_MASK;
    base->control->AR = arReg;
}

/*!
 * brief Enables the SLCD interrupt.
 * For example, to enable fault detect complete interrupt and frame frequency interrupt,
 * do the following.
 * code
 *     SGLCD_EnableInterrupts(LCD,kSLCD_FaultDetectCompleteInterrupt | kSLCD_FrameFreqInterrupt);
 * endcode
 *
 * param base  SLCD peripheral base address.
 * param mask  SLCD interrupts to enable. This is a logical OR of the
 *             enumeration :: slcd_interrupt_enable_t.
 */
void SLCD_EnableInterrupts(SLCD_Type *base, uint32_t mask)
{
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    base->fault->FDCR |= SGLCD_FAULT_DETECT_FDCR_FDCIEN(mask & 0x1U);
#endif

    base->control->GCR |= SGLCD_CONTROL_GCR_LCDIEN((mask >> 1U) & 0x1U);
}

/*!
 * brief Disables the SLCD interrupt.
 * For example, to disable fault detect complete interrupt and frame frequency interrupt,
 * do the following.
 * code
 *     SGLCD_DisableInterrupts(LCD,kSLCD_FaultDetectCompleteInterrupt | kSLCD_FrameFreqInterrupt);
 * endcode
 *
 * param base  SLCD peripheral base address.
 * param mask  SLCD interrupts to disable. This is a logical OR of the
 *             enumeration :: slcd_interrupt_enable_t.
 */
void SLCD_DisableInterrupts(SLCD_Type *base, uint32_t mask)
{
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    /*!< SLCD fault detection complete interrupt source. */
    if (0U != (mask & (uint32_t)kSLCD_FaultDetectCompleteInterrupt))
    {
        base->fault->FDCR &= ~SGLCD_FAULT_DETECT_FDCR_FDCIEN_MASK;
    }
#endif

    /*!< SLCD frame frequency interrupt source. */
    if (0U != (mask & (uint32_t)kSLCD_FrameFreqInterrupt))
    {
         base->control->GCR &= ~SGLCD_CONTROL_GCR_LCDIEN_MASK;
    }
}

/*!
 * brief Clears the SLCD interrupt events status flag.
 *
 * param base  SLCD peripheral base address.
 * param mask  SLCD interrupt source to be cleared.
 * This is the logical OR of members of the enumeration :: slcd_interrupt_enable_t.
 */
void SLCD_ClearInterruptStatus(SLCD_Type *base, uint32_t mask)
{
#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    /*!< SLCD fault detection complete interrupt source. */
    if (0U != (mask & (uint32_t)kSLCD_FaultDetectCompleteInterrupt))
    {
        base->fault->FDSR |= SGLCD_FAULT_DETECT_FDSR_FDCF_MASK;
    }
#endif

    /*!< SLCD frame frequency interrupt source. */
    if (0U != (mask & (uint32_t)kSLCD_FrameFreqInterrupt))
    {
        base->control->AR |= SGLCD_CONTROL_AR_LCDIF_MASK;
    }
}

/*!
 * brief Gets the SLCD interrupt status flag.
 *
 * param base  SLCD peripheral base address.
 * return The event status of the interrupt source. This is the logical OR of members
 *         of the enumeration :: slcd_interrupt_enable_t.
 */
uint32_t SLCD_GetInterruptStatus(SLCD_Type *base)
{
    /* Get the frame frequency interrupt status. */
    uint32_t status = ((base->control->AR & SGLCD_CONTROL_AR_LCDIF_MASK) >> (SGLCD_CONTROL_AR_LCDIF_SHIFT - 1U));

#if defined(FSL_FEATURE_LCD_HAS_FAULT_DETECT) && FSL_FEATURE_LCD_HAS_FAULT_DETECT
    /* Get the frame detect complete interrupt status. */
    status |= ((base->fault->FDSR & SGLCD_FAULT_DETECT_FDSR_FDCF_MASK) >> SGLCD_FAULT_DETECT_FDSR_FDCF_SHIFT);
#endif

    return status;
}
