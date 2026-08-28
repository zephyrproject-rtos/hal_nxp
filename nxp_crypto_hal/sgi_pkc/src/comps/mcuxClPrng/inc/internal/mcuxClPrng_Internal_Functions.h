/*--------------------------------------------------------------------------*/
/* Copyright 2022, 2024-2025 NXP                                            */
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
 * @file  mcuxClPrng_Internal_Functions.h
 * @brief Top level APIs of mcuxClPrng component
 */

#ifndef MCUXCLPRNG_INTERNAL_FUNCTIONS_H_
#define MCUXCLPRNG_INTERNAL_FUNCTIONS_H_

#include <internal/mcuxClPrng_Internal_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>
#include <mcuxClSession.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* APIs of mcuxClPrng                                      */
/**********************************************************/

/**
 * @brief Non-cryptographic PRNG data generation internal function.
 *
 * This function generates non-cryptographic random data
 *
 * mcuxClPrng_generate_Internal should only be used for applications with low quality requirements for the random numbers, e.g. countermeasures like randomization or masking, or filling buffers with random numbers.
 * It MUST not be used for any crypto operation, e.g. key generation or nonce generation. If in doubt don’t use it!
 *
 * @param [out]    pOut      Pointer to the location in which the generated random data must be
 *                           written.
 * @param [in]     outLength Number of random data bytes that must be written in the
 *                           @p pOut buffer.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPrng_generate_Internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPrng_generate_Internal(
  uint8_t*              pOut,
  uint32_t              outLength
);

/**
 * @brief Non-cryptographic PRNG reseed function.
 *
 * This function performs the reseeding of the non-cryptographic random number generator.
 *
 * @param [in]     pSession  Handle for the current CL session.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPrng_reseed)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPrng_reseed(mcuxClSession_Handle_t pSession);

/**
 * @brief Non-cryptographic PRNG data generation function.
 *
 * This function generates non-cryptographic random data
 *
 * mcuxClPrng_generate should only be used for applications with low quality requirements for the random numbers, e.g. countermeasures like randomization or masking, or filling buffers with random numbers.
 * It MUST not be used for any crypto operation, e.g. key generation or nonce generation. If in doubt don’t use it!
 *
 * @param [in]     pSession  Handle for the current CL session.
 * @param [out]    pOut      Buffer in which the generated random data must be
 *                           written.
 * @param [in]     outLength Number of random data bytes that must be written in the
 *                           @p pOut buffer.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPrng_generate)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPrng_generate(
  mcuxClSession_Handle_t pSession,
  mcuxCl_Buffer_t        pOut,
  uint32_t              outLength
);


#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * @}
 */ /* mcuxClPrng_Internal_Functions */

#endif /* MCUXCLPRNG_INTERNAL_FUNCTIONS_H_ */
