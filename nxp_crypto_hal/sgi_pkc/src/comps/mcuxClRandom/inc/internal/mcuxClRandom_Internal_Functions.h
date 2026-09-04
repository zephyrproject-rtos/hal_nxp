/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/**
 * @file  mcuxClRandom_Internal_Functions.h
 * @brief Internal functions definitions of mcuxClRandom component
 */

#ifndef MCUXCLRANDOM_INTERNAL_FUNCTIONS_H_
#define MCUXCLRANDOM_INTERNAL_FUNCTIONS_H_

#include <mcuxClSession.h>
#include <mcuxClRandom.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <mcuxClCrc.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Random data generation function (internal).
 * This function should be used instead of mcuxClRandom_generate() if called
 * from within the CL. This should be done in order to allow cross-function DI protection.
 *
 * This function generates random data based on the information contained in
 * the Random context referenced in the session handle.
 *
 * @param [in]     pSession  Handle for the current CL session.
 * @param [out]    pOut      Buffer in which the generated random data must be
 *                           written.
 * @param [in]     outLength Number of random data bytes that must be written in the
 *                           @p pOut buffer.
 * @param [in]     pXorMask  Pointer to boolean masking used for masking DRBG output (CtrDrbg mode only)
 *
 * @return void
 *
 * Data Integrity: Expunge(pSession + pOut + outLength + pXorMask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandom_generate_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandom_generate_internal(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t        pOut,
    uint32_t              outLength,
    const uint32_t        *pXorMask
);

/**
 * @brief Non-cryptographic PRNG data generation function (internal).
 *
 * This function should be called instead of mcuxClRandom_ncGenerate() if called
 * within CL.
 *
 * mcuxClRandom_ncGenerate_Internal should only be used for applications with low quality requirements for the random numbers,
 * e.g. countermeasures like randomization or masking, or filling buffers with random numbers.
 * It MUST not be used for any crypto operation, e.g. key generation or nonce generation. If in doubt don’t use it!
 *
 * @param [in]     pSession  Handle for the current CL session.
 * @param [out]    pOut      Pointer to the location where the generated random data must be
 *                           written.
 * @param [in]     outLength Number of random data bytes that must be written in the
 *                           @p pOut buffer.
 *
 * @return void
 *
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandom_ncGenerate_Internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandom_ncGenerate_Internal(
    mcuxClSession_Handle_t pSession,
    uint8_t*              pOut,
    uint32_t              outLength
);


/**
 * @brief Word only non-cryptographic PRNG data generation function (internal).
 *
 * This function should be called instead of mcuxClRandom_ncGenerate() if called
 * within CL and only a single word of random data is needed.
 *
 * mcuxClRandom_ncGenerateWord_Internal should only be used for applications with low quality requirements for the random numbers,
 * e.g. countermeasures like randomization or masking, or filling buffers with random numbers.
 * It MUST not be used for any crypto operation, e.g. key generation or nonce generation. If in doubt don’t use it!
 *
 * @param [in]     pSession  Handle for the current CL session.
 *
 * @return random word
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandom_ncGenerateWord_Internal)
uint32_t mcuxClRandom_ncGenerateWord_Internal(mcuxClSession_Handle_t pSession);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOM_INTERNAL_FUNCTIONS_H_ */
