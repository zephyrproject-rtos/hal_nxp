/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2025 NXP                                            */
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
 * @file  mcuxClTrng_Internal_Functions.h
 * @brief Top level APIs of mcuxClTrng component
 */

#ifndef MCUXCLTRNG_INTERNAL_FUNCTIONS_H_
#define MCUXCLTRNG_INTERNAL_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stdint.h>
#include <mcuxClSession.h>

#include <internal/mcuxClTrng_Internal_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* APIs of mcuxClTrng                                      */
/**********************************************************/
/**
 * @defgroup mcuxClTrng_Internal_Functions mcuxClTrng_Internal_Functions
 * @brief Defines all internal functions of @ref mcuxClTrng
 * @ingroup mcuxClTrng
 * @{
 */

/**
 * @brief Function to draw an entropy input string from the TRNG
 *
 * @param[in]   pSession            Handle for the current CL session.
 * @param[out]  pEntropyInput       Pointer to where entropy input string shall be written. Must be word-aligned.
 * @param[in]   entropyInputLength  Number of entropy input bytes to be drawn. Must be a multiple of word size.
 *
 * @return Status of the operation:
 * @retval #MCUXCLTRNG_STATUS_OK             The operation was successful
 * @retval #MCUXCLTRNG_STATUS_ERROR          The operation failed
 * @retval #MCUXCLTRNG_STATUS_FAULT_ATTACK   A fault attack is detected
 *
 * Data Integrity: Expunge (entropyInputLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClTrng_getEntropyInput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClTrng_getEntropyInput(
    mcuxClSession_Handle_t pSession,
    uint32_t *pEntropyInput,
    uint32_t entropyInputLength
    );

/**
 * @brief Function to init TRNG before use.
 * @deprecated This function is deprecated, kept only for backward compatibility.
 *
 * @param[in]   pSession            Handle for the current CL session.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClTrng_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClTrng_Init(mcuxClSession_Handle_t pSession);

#ifdef MCUXCL_FEATURE_TRNG_SA_TRNG
/**
 * @brief Function to check that TRNG is properly configured.
 * @deprecated This function is deprecated, kept only for backward compatibility.
 *
 * @return Status of the operation:
 * @retval #MCUXCLTRNG_STATUS_OK             The check operation was successful
 * @retval #MCUXCLTRNG_STATUS_ERROR          TRNG is not properly configured
 * @retval #MCUXCLTRNG_STATUS_FAULT_ATTACK   A fault attack is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClTrng_checkConfig)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClTrng_checkConfig(mcuxClSession_Handle_t pSession);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * @}
 */ /* mcuxClTrng_Internal_Functions */

#endif /* MCUXCLTRNG_INTERNAL_FUNCTIONS_H_ */
