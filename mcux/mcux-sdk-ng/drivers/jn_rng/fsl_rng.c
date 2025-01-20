/*
 * The Clear BSD License
 * Copyright 2014, NXP
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_rng.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.jn_rng"
#endif

#define TRNG_MODE_SEL_BIT_NUM   (0)
#define TRNG_MODE_SEL_BIT_MASK  (0x3 << TRNG_MODE_SEL_BIT_NUM)
#define TRNG_CLOCK_SEL_BIT_NUM  (2)
#define TRNG_CLOCK_SEL_BIT_MASK (0x7 << TRNG_CLOCK_SEL_BIT_NUM)
#define TRNG_SHIFT4X_BIT_NUM    (5)
#define TRNG_SHIFT4X_BIT_MASK   (0x7 << TRNG_SHIFT4X_BIT_NUM)

/*******************************************************************************
 * Public APIs
 ******************************************************************************/

status_t TRNG_GetDefaultConfig(trng_config_t *userConfig)
{
    /* Check if valid parameters */
    if (userConfig == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* Initialise configuration structure */
    userConfig->shift4x   = 0;
    userConfig->clock_sel = 0;
    userConfig->mode      = trng_FreeRunning;
    return kStatus_Success;
}

status_t TRNG_Init(RNG_Type *base, const trng_config_t *userConfig)
{
    /* Check if valid parameters are passed */
    if ((base == NULL) || (userConfig == NULL))
    {
        return kStatus_InvalidArgument;
    }

    /* Check if valid parameters are passed */
    if ((userConfig->mode != trng_UpdateOnce) && (userConfig->mode != trng_FreeRunning))
    {
        return kStatus_InvalidArgument;
    }

    /* Enable RNG peripheral clock for register access */
    /* Make sure that the XTAL 32MHz clock is enabled before this */
    CLOCK_EnableClock(kCLOCK_Xtal32M);
    CLOCK_EnableClock(kCLOCK_Rng);

    /* Enable Analog clocks for RNG module */
    SYSCON->RNGCLKCTRL = 1;

    /* Configure TRNG module */
    base->COUNTER_CFG &= ~(TRNG_CLOCK_SEL_BIT_MASK | TRNG_SHIFT4X_BIT_MASK | TRNG_MODE_SEL_BIT_MASK);
    base->COUNTER_CFG |=
        ((userConfig->clock_sel << TRNG_CLOCK_SEL_BIT_NUM) | (userConfig->shift4x << TRNG_SHIFT4X_BIT_NUM));

    /* Set mode */
    base->COUNTER_CFG |= userConfig->mode;

    /* Start RNG generation */
    SYSCON->RNGCTRL = 1;

    return kStatus_Success;
}

void TRNG_Deinit(RNG_Type *base)
{
    /* Stop RNG generation */
    SYSCON->RNGCTRL = 0;

    /* Disable Analog clocks for RNG module */
    SYSCON->RNGCLKCTRL = 0;

    /* Disable RNG clock */
    CLOCK_DisableClock(kCLOCK_Rng);
    return;
}

status_t TRNG_GetRandomData(RNG_Type *base, void *data, size_t data_size)
{
    uint32_t random_32;
    uint8_t *random_p;
    uint32_t random_size;
    uint8_t *data_p = (uint8_t *)data;
    uint32_t i;

    /* Check if valid parameters */
    if ((base == NULL) || (data == NULL) || (data_size == 0))
    {
        return kStatus_InvalidArgument;
    }

    /* Read random data as per user request */
    do
    {
        /* Read random data from register Entropy.*/
        random_32 = base->RANDOM_NUMBER;

        /* Extract required bytes */
        random_p = (uint8_t *)&random_32;

        if (data_size < sizeof(random_32))
        {
            random_size = data_size;
        }
        else
        {
            random_size = sizeof(random_32);
        }

        for (i = 0U; i < random_size; i++)
        {
            *data_p++ = *random_p++;
        }

        data_size -= random_size;
    } while (data_size > 0);

    return kStatus_Success;
}
