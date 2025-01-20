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

#ifndef FSL_RNG_H_
#define FSL_RNG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "fsl_common.h"

/*!
 * @addtogroup jn_rng
 * @{
 */

/*! @file */

/**
 * RNG return status types
 */

/**
 * RNG operating modes
 */
typedef enum _trng_mode
{
    trng_UpdateOnce  = 0x1, /*!< TRNG update once & disable */
    trng_FreeRunning = 0x2, /*!< TRNG updates continuously */
} trng_mode_t;

typedef struct _trng_config
{
    uint8_t shift4x;   /*!< Used to add precision to clock ratio & entropy refill - range from 0 to 4 */
    uint8_t clock_sel; /*!< Internal clock on which to compute statistics */
                       /*!< 0 - XOR results from all clocks */
                       /*!< 1 - First clock */
                       /*!< 2 - Second clock */
    trng_mode_t mode;  /*!< TRNG mode select */
} trng_config_t;

/*!
 * @brief Gets Default config of TRNG.
 *
 * This function initializes the TRNG configuration structure.
 *
 * @param userConfig Pointer to TRNG configuration structure
 */
status_t TRNG_GetDefaultConfig(trng_config_t *userConfig);

/*!
 * @brief Initializes the TRNG.
 *
 * This function initializes the TRNG.
 *
 * @param base TRNG base address
 * @param userConfig The configuration of TRNG
 * @return  kStatus_Success - Success
 *          kStatus_InvalidArgument - Invalid parameter
 */
status_t TRNG_Init(RNG_Type *base, const trng_config_t *userConfig);

/*!
 * @brief Shuts down the TRNG.
 *
 * This function shuts down the TRNG.
 *
 * @param base TRNG base address
 */
void TRNG_Deinit(RNG_Type *base);

/*!
 * @brief Gets random data.
 *
 * This function gets random data from the TRNG.
 *
 * @param base TRNG base address
 * @param data pointer to user buffer to be filled by random data
 * @param data_size size of data in bytes
 * @return TRNG status
 */
status_t TRNG_GetRandomData(RNG_Type *base, void *data, size_t data_size);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* __RNG_JN518X_H_*/
