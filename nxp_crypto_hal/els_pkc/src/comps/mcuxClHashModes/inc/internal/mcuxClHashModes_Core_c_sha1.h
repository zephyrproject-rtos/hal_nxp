/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

/** @file  mcuxClHashModes_Core_c_sha1.h
 *  @brief Internal definitions and declarations of the *CORE* layer dedicated
 *         to the software implementation of SHA-1
 */

#ifndef MCUXCLHASHMODES_CORE_C_SHA1_H_
#define MCUXCLHASHMODES_CORE_C_SHA1_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClHash_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * CONSTANTS
 **********************************************/
#define MCUXCLHASHMODES_SHA_1_NO_OF_ROUNDS           (80U) ///< Number of rounds for SHA-1 algorithm

/**********************************************************
 * Type declarations
 **********************************************************/

/**********************************************************
 * Function declarations
 **********************************************************/

/**
 * @brief Sha-1 core hash processing
 *
 * This function processes one block of input data with the SHA-1 algorithm. Note
 * it does not perform padding. This has to be done before calling the function.
 *
 * @param[in/out] pState   Pointer to the state
 * @param[in/out] pAccBuf  Pointer to the accumulation buffer
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_core_c_sha1)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_core_c_sha1(
                                  uint32_t *pState,
                                  uint32_t *pAccBuf);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_CORE_C_SHA1_H_ */
