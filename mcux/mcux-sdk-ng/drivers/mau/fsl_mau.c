
/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mau.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint32_t MAU_GetInstance(MAU_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to MAU bases for each instance. */
static MAU_Type *const s_mauBases[] = MAU_BASE_PTRS;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to MAU clocks for each instance. */
static const clock_ip_name_t s_mauClocks[] = MAU_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#if defined(MAU_RSTS)
/* Reset array */
static const reset_ip_name_t s_mauResets[] = MAU_RSTS;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
void MAU_Init(MAU_Type *base, mau_config_t *config)
{
    uint32_t enable_interrupt = 0;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock for MAU instance. */
    (void)CLOCK_EnableClock(s_mauClocks[MAU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(MAU_RSTS)
    RESET_ReleasePeripheralReset(s_mauResets[MAU_GetInstance(base)]);
#endif
    if (config->enableRes0Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES0_IE_MASK;
    }
    if (config->enableRes1Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES1_IE_MASK;
    }
    if (config->enableRes2Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES2_IE_MASK;
    }
    if (config->enableRes3Interrupt)
    {
        enable_interrupt |= MAU_RES_STATUS_IE_RES3_IE_MASK;
    }

    base->RES_STATUS_IE = enable_interrupt;
}
void MAU_Deinit(MAU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the clock. */
    (void)CLOCK_DisableClock(s_mauClocks[MAU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

static uint32_t MAU_GetInstance(MAU_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    /*
     * $Branch Coverage Justification$
     * (instance >= ARRAY_SIZE(s_mauBases)) not covered. The peripheral base
     * address is always valid and checked by assert.
     */
    for (instance = 0; instance < ARRAY_SIZE(s_mauBases); instance++)
    {
        /*
         * $Branch Coverage Justification$
         * (s_mauBases[instance] != base) not covered. The peripheral base
         * address is always valid and checked by assert.
         */
        if (MSDK_REG_SECURE_ADDR(s_mauBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_mauBases));

    return instance;
}
