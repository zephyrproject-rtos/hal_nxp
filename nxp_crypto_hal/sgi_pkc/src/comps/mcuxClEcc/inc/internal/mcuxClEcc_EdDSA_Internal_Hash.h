/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClEcc_EdDSA_Internal_Hash.h
 * @brief internal header for abstracting hash calls in mcuxClEcc EdDSA
 */


#ifndef MCUXCLECC_EDDSA_INTERNAL_HASH_H_
#define MCUXCLECC_EDDSA_INTERNAL_HASH_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClHash_Types.h>
#include <mcuxClHash_Functions.h>
#include <mcuxClHash_Constants.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClHash_Internal.h>


/**
 * @brief Compute private key hash and store it in PKC workarea
 *        Function to compute private key hash and store it in PKC workarea.
 *        Since the parameter b of both Ed25519 and Ed448 is a multiple of 8,
 *        byte length of private key hash (= 2b/8) can be derived from
 *        byte length of private key (= b/8).
 *
 * @param pSession Session handle
 * @param pDomainParams EdDSA domain parameters
 * @param buffPrivKey Buffer containing private key
 * @param buffPrivKeyHash Buffer to store hash result
 * @param privKeyLen Length of private key in bytes
 *
 * @note Data Integrity: EXPUNGE: buffPrivKey + buffPrivkeyHash + privkeyLen
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_KeyGen_HashPrivKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_KeyGen_HashPrivKey(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxCl_InputBuffer_t buffPrivKey,
    mcuxCl_Buffer_t buffPrivKeyHash,
    uint32_t privKeyLen);


/**
 * @brief Calculate hash for EdDSA sign/verify operations
 * Function to compute input hash and store it in PKC workarea.
 * Since the parameter b of both Ed25519 and Ed448 is a multiple of 8,
 * byte length of hash (= 2b/8) can be derived from
 * byte length of encoded public key (= b/8).
 *
 * Computes hash of: prefix || signatureR || pubKey || input message
 *
 * @param pSession Session handle
 * @param pDomainParams EdDSA domain parameters
 * @param pCtx Hash context
 * @param hashAlg Hash algorithm to use
 * @param pHashPrefix Pointer to hash prefix data
 * @param hashPrefixLen Length of hash prefix
 * @param buffSignatureR Buffer containing signature R component
 * @param signatureRLen Length of signature R
 * @param pPubKey Pointer to public key
 * @param pubKeyLen Length of public key
 * @param buffIn Buffer containing input message
 * @param inSize Size of input message
 * @param buffOutput Buffer to store hash output
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_SignVerify_CalcHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_SignVerify_CalcHash(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxClHash_Context_t pCtx,
    const uint8_t *pHashPrefix,
    uint32_t hashPrefixLen,
    mcuxCl_InputBuffer_t buffSignatureR,
    uint32_t signatureRLen,
    const uint8_t *pPubKey,
    uint32_t pubKeyLen,
    mcuxCl_InputBuffer_t buffIn,
    uint32_t inSize,
    mcuxCl_Buffer_t buffOutput);

#endif /* MCUXCLECC_EDDSA_INTERNAL_HASH_H_ */
