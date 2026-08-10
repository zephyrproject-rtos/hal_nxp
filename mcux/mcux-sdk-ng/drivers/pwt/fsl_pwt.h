/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_PWT_H_
#define FSL_PWT_H_

#include "fsl_common.h"

/*!
 * @addtogroup pwt_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define FSL_PWT_DRIVER_VERSION (MAKE_VERSION(2, 0, 3)) /*!< Version 2.0.3 */

/*! @brief PWT clock source selection */
typedef enum _pwt_clock_source
{
    kPWT_BusClock = 0U,   /*!< The Bus clock is used as the clock source of PWT counter */
    kPWT_AlternativeClock /*!< Alternative clock is used as the clock source of PWT counter */
} pwt_clock_source_t;

/*! @brief PWT prescaler factor selection for clock source */
typedef enum _pwt_clock_prescale
{
    kPWT_Prescale_Divide_1 = 0U, /*!< PWT clock divided by 1 */
    kPWT_Prescale_Divide_2,      /*!< PWT clock divided by 2 */
    kPWT_Prescale_Divide_4,      /*!< PWT clock divided by 4 */
    kPWT_Prescale_Divide_8,      /*!< PWT clock divided by 8 */
    kPWT_Prescale_Divide_16,     /*!< PWT clock divided by 16 */
    kPWT_Prescale_Divide_32,     /*!< PWT clock divided by 32 */
    kPWT_Prescale_Divide_64,     /*!< PWT clock divided by 64 */
    kPWT_Prescale_Divide_128     /*!< PWT clock divided by 128 */
} pwt_clock_prescale_t;

/*! @brief PWT input port selection */
typedef enum _pwt_input_select
{
    kPWT_InputPort_0 = 0U, /*!< PWT input comes from PWTIN[0] */
    kPWT_InputPort_1,      /*!< PWT input comes from PWTIN[1] */
    kPWT_InputPort_2,      /*!< PWT input comes from PWTIN[2] */
    kPWT_InputPort_3       /*!< PWT input comes from PWTIN[3] */
} pwt_input_select_t;

/*!
 * @brief List of PWT interrupts
 */
enum _pwt_interrupt_enable
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    kPWT_PulseWidthReadyInterruptEnable = PWT_R1_PRDYIE_MASK, /*!< Pulse width data ready interrupt */
    kPWT_CounterOverflowInterruptEnable = PWT_R1_POVIE_MASK    /*!< Counter overflow interrupt */
#else
    kPWT_PulseWidthReadyInterruptEnable = PWT_CS_PRDYIE_MASK, /*!< Pulse width data ready interrupt */
    kPWT_CounterOverflowInterruptEnable = PWT_CS_POVIE_MASK   /*!< Counter overflow interrupt */
#endif
};

/*!
 * @brief List of PWT flags
 */
enum _pwt_status_flags
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    kPWT_CounterOverflowFlag = PWT_R1_PWTOV_MASK,  /*!< Counter overflow flag */
    kPWT_PulseWidthValidFlag = PWT_R1_PWTRDY_MASK, /*!< Pulse width valid flag */
    kPWT_InputToggleFlag     = PWT_R1_TGL_MASK,     /*!< PWTIN toggle flag (write-1-to-clear) */
#else
    kPWT_CounterOverflowFlag = PWT_CS_PWTOV_MASK,  /*!< Counter overflow flag */
    kPWT_PulseWidthValidFlag = PWT_CS_PWTRDY_MASK, /*!< Pulse width valid flag */
    kPWT_InputToggleFlag     = (PWT_CR_TGL_MASK << 8),  /*!< PWTIN toggle flag (write-1-to-clear) */
#endif
};

/*!
 * @brief PWT configuration structure
 *
 * This structure holds the configuration settings for the PWT peripheral. To initialize this
 * structure to reasonable defaults, call the PWT_GetDefaultConfig() function and pass a
 * pointer to the configuration structure instance.
 *
 * The configuration structure can be made constant so as to reside in flash.
 */
typedef struct _pwt_config
{
    pwt_clock_source_t clockSource; /*!< Clock source for the counter */
    pwt_clock_prescale_t prescale;  /*!< Pre-scaler to divide down the clock */
    pwt_input_select_t inputSelect; /*!< PWT Pulse input port selection */
    bool enableFirstCounterLoad;    /*!< true: Load the first counter value to registers;
                                         false: Do not load first counter value */
} pwt_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Ungates the PWT clock and configures the peripheral for basic operation.
 *
 * @note This API should be called at the beginning of the application using the PWT driver.
 *
 * @param base   PWT peripheral base address
 * @param config Pointer to the user configuration structure.
 */
void PWT_Init(PWT_Type *base, const pwt_config_t *config);

/*!
 * @brief Gates the PWT clock.
 *
 * @param base PWT peripheral base address
 */
void PWT_Deinit(PWT_Type *base);

/*!
 * @brief  Fills in the PWT configuration structure with the default settings.
 *
 * The default values are:
 * @code
 *   config->clockSource = kPWT_BusClock;
 *   config->prescale = kPWT_Prescale_Divide_1;
 *   config->inputSelect = kPWT_InputPort_0;
 *   config->enableFirstCounterLoad = false;
 * @endcode
 * @param config Pointer to the user configuration structure.
 */
void PWT_GetDefaultConfig(pwt_config_t *config);

/*! @}*/

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Enables the selected PWT interrupts.
 *
 * @param base PWT peripheral base address
 * @param mask The interrupts to enable. This is a logical OR of members of the
 *             enumeration pwt_interrupt_enable_t
 */
static inline void PWT_EnableInterrupts(PWT_Type *base, uint32_t mask)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    uint32_t reg = base->R1;
    reg |= mask;
    /* These bits are cleared by writing 0, set in case clear by mistake */
    reg |= (PWT_R1_PWTOV_MASK | PWT_R1_PWTRDY_MASK);
    /* Preserve TGL (w1c) by writing 0 */
    reg &= ~PWT_R1_TGL_MASK;
    base->R1 = reg;
#else
    base->CS |= (uint8_t)(mask & 0xFFU);
#endif
}

/*!
 * @brief Disables the selected PWT interrupts.
 *
 * @param base PWT peripheral base address
 * @param mask The interrupts to enable. This is a logical OR of members of the
 *             enumeration pwt_interrupt_enable_t
 */
static inline void PWT_DisableInterrupts(PWT_Type *base, uint32_t mask)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    uint32_t reg = base->R1;
    reg &= ~mask;
    /* These bits are cleared by writing 0, set in case clear by mistake */
    reg |= (PWT_R1_PWTOV_MASK | PWT_R1_PWTRDY_MASK);
    /* Preserve TGL (w1c) by writing 0 */
    reg &= ~PWT_R1_TGL_MASK;
    base->R1 = reg;
#else
    base->CS &= (uint8_t)(~mask & 0xFFU);
#endif
}

/*!
 * @brief Gets the enabled PWT interrupts.
 *
 * @param base PWT peripheral base address
 *
 * @return The enabled interrupts. This is the logical OR of members of the
 *         enumeration pwt_interrupt_enable_t
 */
static inline uint32_t PWT_GetEnabledInterrupts(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    return (base->R1 & (PWT_R1_PRDYIE_MASK | PWT_R1_POVIE_MASK));
#else
    return ((uint32_t)base->CS & (PWT_CS_PRDYIE_MASK | PWT_CS_POVIE_MASK));
#endif
}

/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Gets the PWT status flags.
 *
 * @param base PWT peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration pwt_status_flags_t
 */
static inline uint32_t PWT_GetStatusFlags(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    return (base->R1 & (PWT_R1_PWTRDY_MASK | PWT_R1_PWTOV_MASK | PWT_R1_TGL_MASK));
#else
    uint32_t flags = (uint32_t)base->CS & (PWT_CS_PWTRDY_MASK | PWT_CS_PWTOV_MASK);
    if ((base->CR & PWT_CR_TGL_MASK) != 0U)
    {
        flags |= (uint32_t)kPWT_InputToggleFlag;
    }
    return flags;
#endif
}

/*!
 * @brief Clears the PWT status flags.
 *
 * @param base PWT peripheral base address
 * @param mask The status flags to clear. This is a logical OR of members of the
 *             enumeration pwt_status_flags_t
 */
static inline void PWT_ClearStatusFlags(PWT_Type *base, uint32_t mask)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    uint32_t reg = base->R1;

    /* These bits are cleared by writing 0, set in case clear by mistake */
    reg |= (PWT_R1_PWTOV_MASK | PWT_R1_PWTRDY_MASK);
    /* Preserve TGL (w1c) by writing 0 unless clearing it */
    reg &= ~PWT_R1_TGL_MASK;

    /* Clear requested w0c flags (PWTOV, PWTRDY) by writing 0 */
    reg &= ~(mask & (PWT_R1_PWTOV_MASK | PWT_R1_PWTRDY_MASK));
    /* Clear TGL (w1c) by writing 1 if requested */
    reg |= (mask & PWT_R1_TGL_MASK);

    base->R1 = reg;
#else
    /* Clear w0c flags (PWTOV, PWTRDY) in CS register */
    uint8_t csClearMask = (uint8_t)(mask & (PWT_CS_PWTOV_MASK | PWT_CS_PWTRDY_MASK));
    uint8_t reg;
    if (csClearMask != 0U)
    {
        reg = base->CS;
        /* These bits are cleared by writing 0, set in case clear by mistake */
        reg |= (PWT_CS_PWTOV_MASK | PWT_CS_PWTRDY_MASK);
        reg &= (uint8_t)(~csClearMask);
        base->CS = reg;
    }
    /* Clear TGL (w1c) in CR register by writing 1 */
    if ((mask & (uint32_t)kPWT_InputToggleFlag) != 0U)
    {
        base->CR |= PWT_CR_TGL_MASK;
    }
#endif
}

/*! @}*/

/*!
 * @name Timer Start and Stop
 * @{
 */

/*!
 * @brief Starts the PWT counter.
 *
 * @param base PWT peripheral base address
 */
static inline void PWT_StartTimer(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    uint32_t reg = base->R1;
    reg |= PWT_R1_PWTEN_MASK;
    base->R1 = reg;
#else
    base->CS |= PWT_CS_PWTEN_MASK;
#endif
}

/*!
 * @brief Stops the PWT counter.
 *
 * @param base PWT peripheral base address
 */
static inline void PWT_StopTimer(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    uint32_t reg = base->R1;
    reg &= ~PWT_R1_PWTEN_MASK;
    base->R1 = reg;
#else
    base->CS &= (uint8_t)(~PWT_CS_PWTEN_MASK & 0xFFU);
#endif
}

/*! @}*/

/*!
 * @brief Reads the current counter value.
 *
 * This function returns the timer counting value
 *
 * @param base    PWT peripheral base address
 *
 * @return Current 16-bit timer counter value
 */
static inline uint16_t PWT_GetCurrentTimerCount(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    return (uint16_t)((base->R2 & (PWT_R2_PWTCH_MASK | PWT_R2_PWTCL_MASK)) >> PWT_R2_PWTCH_SHIFT);
#else
    return ((uint16_t)(((uint16_t)base->CNTH << 8))) | base->CNTL;
#endif
}
/*!
 * @brief Reads the positive pulse width.
 *
 * This function reads the low and high registers and returns the 16-bit positive pulse width
 *
 * @param base PWT peripheral base address.
 *
 * @return The 16-bit positive pulse width.
 */
static inline uint16_t PWT_ReadPositivePulseWidth(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    return (uint16_t)((base->R1 & (PWT_R1_PPWH_MASK | PWT_R1_PPWL_MASK)) >> PWT_R1_PPWH_SHIFT);
#else
    return ((uint16_t)(((uint16_t)base->PPH) << 8)) | base->PPL;
#endif
}

/*!
 * @brief Reads the negative pulse width.
 *
 * This function reads the low and high registers and returns the 16-bit negative pulse width
 *
 * @param base PWT peripheral base address.
 *
 * @return The 16-bit negative pulse width.
 */
static inline uint16_t PWT_ReadNegativePulseWidth(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    return (uint16_t)((base->R2 & (PWT_R2_NPWH_MASK | PWT_R2_NPWL_MASK)) >> PWT_R2_NPWH_SHIFT);
#else
    return ((uint16_t)(((uint16_t)base->NPH) << 8)) | base->NPL;
#endif
}

/*!
 * @brief Performs a software reset on the PWT module.
 *
 * @param base PWT peripheral base address
 */
static inline void PWT_Reset(PWT_Type *base)
{
    /* Ignore the status bits protection, they will be cleared by reset. */
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    uint32_t reg = base->R1;
    reg |= PWT_R1_PWTSR_MASK;
    base->R1 = reg;
#else
    base->CS |= PWT_CS_PWTSR_MASK;
#endif
}

/*!
 * @brief Gets the current PWTIN input level.
 *
 * This function returns the level of the selected PWTIN input at the point when counter overflow occurs.
 *
 * @param base PWT peripheral base address.
 *
 * @return The PWTIN input level: 0 for low, 1 for high.
 */
static inline uint8_t PWT_GetInputLevel(PWT_Type *base)
{
#if defined(FSL_FEATURE_PWT_REG_WIDTH) && (FSL_FEATURE_PWT_REG_WIDTH == 32)
    return (uint8_t)((base->R1 & PWT_R1_LVL_MASK) >> PWT_R1_LVL_SHIFT);
#else
    return (uint8_t)((base->CR & PWT_CR_LVL_MASK) >> PWT_CR_LVL_SHIFT);
#endif
}

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_PWT_H_*/
