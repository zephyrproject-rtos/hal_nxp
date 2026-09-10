/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxClMath_Internal_Functions.h
 * @brief Internal APIs of mcuxClMath component
 */


#ifndef MCUXCLMATH_INTERNAL_FUNCTIONS_H_
#define MCUXCLMATH_INTERNAL_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>

#include <mcuxClSession.h>

#include <mcuxClMath_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClMath_Internal_Functions mcuxClMath_Internal_Functions
 * @brief Defines all functions of @ref mcuxClMath
 * @ingroup mcuxClMath
 * @{
 */

/**
 * @brief Calculates secure modular multiplication in Montgomery representation: [R] = [X] * [Y] * Q-1 mod N.
 *
 * This function computes secure modular multiplication in Montgomery representation
 * temporary buffer of T2 could be set to buffer X to save memory
 *
 * @param[in] pSession  handle for the current CL session.
 * @param[out,in,in,in] iR_iN_iY_iX  indices of PKC operands
 * @param[temp,temp] iT2_iT1  indices of temporary buffers for PKC operation
 * @param[in] length  length of N in bytes
 *
 * @pre
 * - This function uses PRNG which has to be initialized prior to calling the function.
 * - @p pSession  The session pointed to by pSession has to be initialized prior to a call to this function.
 * - @p iX        (bits 0~7): index of X (PKC operand), size = length.
 * - @p iY        (bits 8~15): index of Y (PKC operand), size = length.
 * - @p iN        (bits 16~23): index of modulus (PKC operand), size = length.
 * - @p iR        (bits 24~31): index of result (PKC operand), size = length + 1 PKC word.
 * - @p iT1       (bits 0~7): index of T1 (PKC operand), size = length + 1 PKC word.
 * - @p iT2       (bits 8~15): index of T2 (PKC operand), size = length.
 * - @p length shall be nonzero and a multiple of PKC word size. A zero length will cause undefined behavior.
 * - PKC PS1 OPLEN = MCLEN = length.
 *
 * @post
 *  - Data Integrity: Expunge(iR_iN_iY_iX)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #MCUXCLMATH_STATUS_OK     function executed successfully
 * @retval #MCUXCLMATH_STATUS_ERROR  error occurred during operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_SecModMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMath_Status_t) mcuxClMath_SecModMult(
    mcuxClSession_Handle_t pSession,
    uint32_t iR_iN_iY_iX,
    uint16_t iT2_iT1,
    uint16_t length
    );
/** Helper macro for #mcuxClMath_SecModMult. */
#define MCUXCLMATH_SECMODMULT(pSession, iR, iN, iY, iX, iT2, iT1, len)  \
    mcuxClMath_SecModMult(pSession, MCUXCLPKC_PACKARGS4(iR, iN, iY, iX), MCUXCLPKC_PACKARGS2(iT2, iT1), len)

/**
 * @}
 */ /* mcuxClMath_Internal_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMATH_INTERNAL_FUNCTIONS_H_ */
