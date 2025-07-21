/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_stm.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.stm"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Gets the instance from the base address
 *
 * @param base STM peripheral base address
 *
 * @return The STM instance
 */
static uint32_t STM_GetInstance(STM_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to STM bases for each instance. */
static STM_Type *const s_stmBases[] = STM_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to stm clocks for each instance. */
static const clock_ip_name_t s_stmClocks[] = STM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/* TODO Update when reset driver ready */

/*! @brief Pointers real ISRs installed by drivers for each instance. */
static stm_callback_t s_stmCallback[ARRAY_SIZE(s_stmBases)] = {0};

/*! @brief Array to map timer instance to IRQ number. */
static const IRQn_Type s_stmIRQ[] = STM_IRQS;

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t STM_GetInstance(STM_Type *base)
{
    uint32_t instance;
    uint32_t stmArrayCount = ARRAY_SIZE(s_stmBases);

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < stmArrayCount; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_stmBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < stmArrayCount);

    return instance;
}

/*!
 * brief Initializes STM configure structure.
 *
 * This function initializes the STM configure structure to default value. The default
 * value are:
 * code
 *  config->enableRunInDebug = true;
 *  config->enableIRQ = true;
 *  config->prescale = 0U;
 * endcode
 *
 * param config Pointer to STM config structure.
 * see stm_config_t
 */
void STM_GetDefaultConfig(stm_config_t *config)
{
    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));
    /*  Timer runs in Debug mode */
    config->enableRunInDebug = true;
    /* Enable interrupt */
    config->enableIRQ = true;
    /* Set Counter prescale */
    config->prescale = 0U;
}

/*!
 * brief Initializes the STM.
 *
 * This function configures the peripheral for basic operation.
 *
 * param base   STM peripheral base address
 * param config The configuration of STM
 */
void STM_Init(STM_Type *base, const stm_config_t *config)
{
    assert(NULL != config);
    uint32_t instance = STM_GetInstance(base);
    uint32_t reg = 0U;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the STM clock */
    CLOCK_EnableClock(s_stmClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Freeze timer in Debug mode*/
    if(!config->enableRunInDebug)
    {
        reg |= STM_CR_FRZ_MASK;
    }
    /* Configure prescale*/
    reg |= STM_CR_CPS(config->prescale);

    base->CR = reg;
    /* Clear counter */
    base->CNT = 0U;
    /* Enable interrupt */
    if (config->enableIRQ)
    {
        (void)EnableIRQ(s_stmIRQ[instance]);
    }
}

/*!
 * brief Shuts down the STM.
 *
 * This function shuts down the STM.
 *
 * param base STM peripheral base address
 */
void STM_Deinit(STM_Type *base)
{
    /* Stop the timer */
    STM_StopTimer(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the STM clock */
    CLOCK_DisableClock(s_stmClocks[STM_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
* brief Set compare value for specific channel of the STM module and enable the channel.
*
* param base             STM peripheral base address
* param channel          The compare channel to be configured. @see stm_channel_t
* param value            Compare value, range from 0 to 0xFFFFFFFF
*/
void STM_SetCompare(STM_Type *base, stm_channel_t channel, uint32_t value) {
    /* Clear Channel Interrupt Flag */
    STM_ClearStatusFlags(base, channel);
    /* set compare value*/
    base->CHANNEL[channel].CMP = value;
    /* Enable channel */
    base->CHANNEL[channel].CCR = STM_CCR_CEN_MASK;
}

/*!
 * brief Register callback.
 *
 * param base      STM peripheral base address
 * param cb_func   callback function
 */
void STM_RegisterCallBack(STM_Type *base, stm_callback_t cb_func)
{
    uint32_t index         = STM_GetInstance(base);
    s_stmCallback[index]   = cb_func;
}

/* IRQ handler functions overloading weak symbols in the startup */
void STM_DriverIRQHandler(uint32_t index)
{
    uint32_t int_stat = 0U;
    uint32_t i;

    if (index > ARRAY_SIZE(s_stmBases))
    {
        return;
    }
    
    for (i = 0U; i < STM_CHANNEL_COUNT; i++)
    {
        /* Collect interrupt flag from all channels */
        int_stat |= STM_GetStatusFlags(s_stmBases[index], (stm_channel_t)i) << i;
        /* Clear interrupt flag before calling callback */
        STM_ClearStatusFlags(s_stmBases[index], (stm_channel_t)i);
    }
    
    if(s_stmCallback[index] != NULL)
    {
        s_stmCallback[index](int_stat);
    }

    SDK_ISR_EXIT_BARRIER;
}