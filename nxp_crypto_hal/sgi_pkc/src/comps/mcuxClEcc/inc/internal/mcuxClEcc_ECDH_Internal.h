/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClEcc_ECDH_Internal.h
 * @brief internal header for ECDH
 */


#ifndef MCUXCLECC_ECDH_INTERNAL_H_
#define MCUXCLECC_ECDH_INTERNAL_H_


#include <mcuxClCore_Platform.h>
#include <mcuxClKey_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ECDH key agreement.
 * @api
 *
 * This function performs an ECDH key agreement to compute a shared secret between two parties.
 *
 * @param[in] pSession             pointer to #mcuxClSession_Descriptor.
 * @param[in] agreement            Key agreement algorithm specifier.
 * @param[in] key                  private key handling structure (word-aligned)
 * @param[in] otherKey             public key handling structure (word-aligned)
 * @param[in] additionalInputs     Key agreement additional input pointers (unused parameter)
 * @param[in] numberOfInputs       number of additional inputs (unused parameter)
 * @param[out] pOut                buffer for shared secret
 * @param[out] pOutLength          shared secret length
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ECDH_KeyAgreement, mcuxClKey_AgreementFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_ECDH_KeyAgreement(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Agreement_t agreement,
    mcuxClKey_Handle_t key,
    mcuxClKey_Handle_t otherKey,
    mcuxClKey_Agreement_AdditionalInput_t additionalInputs[],
    uint32_t numberOfInputs,
    uint8_t * pOut,
    uint32_t * const pOutLength
    );


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_ECDH_INTERNAL_H_ */
