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

/** @file  mcuxClHashModes_Core_els_sha2.h
 *  @brief Internal definitions and declarations of the *CORE* layer dedicated to ELS
 */

#ifndef MCUXCLHASHMODES_CORE_ELS_SHA2_H_
#define MCUXCLHASHMODES_CORE_ELS_SHA2_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>
#include <mcuxClHash_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************
 * Type declarations
 **********************************************************/

/**
 * @brief Hash Core function type
 *
 * This function will process one or more blocks of the Hash algorithm
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHashModes_els_AlgoCore_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) (*mcuxClHashModes_els_AlgoCore_t)(
                        uint32_t options,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut));

/**********************************************************
 * Function declarations
 **********************************************************/

/**
 * @brief ELS hash processing
 *
 * This function calls mcuxClEls_Hash_Async to call ELS to process input data. Note
 * it does not perform padding. This has to be done before calling the function.
 *
 * @param options   ELS options
 * @param in        Pointer to the input message
 * @param out       Result of processed input data
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 * @retval MCUXCLHASH_STATUS_FAILURE          Error occured during Hash operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_els_core_sha2, mcuxClHashModes_els_AlgoCore_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_els_core_sha2(
                        uint32_t options,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut);

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT
/**
 * @brief ELS hash processing in direct mode
 *
 * This function calls mcuxClEls_Hash_ShaDirect to call ELS in direct mode to process input
 * data. Note it does not perform padding. This has to be done before calling the function.
 *
 * Precondition: SHA-direct mode has been enabled
 *
 * @param options   ELS options
 * @param in        Pointer to the input message
 * @param out       Result of processed input data
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 * @retval MCUXCLHASH_STATUS_INVALID_PARAMS   The provided function parameters do not fulfill requirements
 * @retval MCUXCLHASH_STATUS_FAILURE          Error occured during Hash operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_els_core_sha2_direct, mcuxClHashModes_els_AlgoCore_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_els_core_sha2_direct(
                        uint32_t options,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut);
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_CORE_ELS_SHA2_H_ */
