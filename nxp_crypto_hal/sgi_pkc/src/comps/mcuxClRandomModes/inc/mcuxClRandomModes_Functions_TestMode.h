/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

#ifndef MCUXCLRANDOM_FUNCTIONS_TESTMODE_H_
#define MCUXCLRANDOM_FUNCTIONS_TESTMODE_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClSession.h>
#include <mcuxClRandom_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mcuxClRandomModes_Functions_TestMode mcuxClRandomModes_Functions_TestMode
 * \brief Random operations in TEST_MODE.
 * \ingroup mcuxClRandomModes
 * @{
 */

/**
 * \brief This function creates a TEST_MODE descriptor from an existing NORMAL_MODE one
 *
 * This function creates a TEST_MODE descriptor from an existing NORMAL_MODE one.
 * The function expects as input a pointer to a buffer to which the user of the CL shall write a custom seed to be used for (re)seeding the DRBG.
 * The function shall be called prior to an mcuxClRandom_init call.
 *
 * \param  testMode[out]                Pointer to TEST_MODE descriptor to be initialized
 * \param  normalMode[in]               Pointer to NORMAL_MODE descriptor to be used as basis for the initialization
 * \param  pCustomSeed[in]              Pointer to memory buffer containing a custom seed for DRBG (re)seeding
 *
 * \return status
 */
// TODO: Create defines for custom seed sizes using object size filler
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_createTestFromNormalMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_createTestFromNormalMode(
    mcuxClRandom_ModeDescriptor_t *pTestMode,
    mcuxClRandom_Mode_t normalMode,
    const uint32_t * const pCustomSeed
);

/**
 * \brief This function updates the custom seed pointer in a TEST_MODE descriptor
 *
 * \param  testMode[in]         Pointer to TEST_MODE descriptor
 * \param  pCustomSeed[in]      Pointer to memory buffer containing custom seed for DRBG (re)seeding
 *
 * \return
 *   - MCUXCLRANDOM_STATUS_OK         if the TEST_MODE descriptor generation was successful
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_updateEntropyInput)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_updateEntropyInput(
    mcuxClRandom_ModeDescriptor_t *pTestMode,
    const uint32_t * const pCustomSeed
);

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOM_FUNCTIONS_TESTMODE_H_ */
