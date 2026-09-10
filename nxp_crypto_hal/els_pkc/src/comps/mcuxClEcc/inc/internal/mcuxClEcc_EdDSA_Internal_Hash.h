/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

#include <internal/mcuxClSession_Internal.h>


/******************************************************************************/
/* Macro to compute private key hash and store it in PKC workarea.            */
/* Since the parameter b of both Ed25519 and Ed448 is a multiple of 8,        */
/* byte length of private key hash (= 2b/8) can be derived from               */
/* byte length of private key (= b/8).                                        */
/******************************************************************************/
#define MCUXCLECC_FP_EDDSA_KEYGEN_HASH_PRIVKEY(pSession, hashAlg, buffPrivKey, buffPrivKeyHash, privKeyLen)  \
    do{                                                                \
        uint32_t outLength = 0u;                                       \
        MCUXCLPKC_WAITFORFINISH();                                      \
        MCUX_CSSL_FP_FUNCTION_CALL(retHash,                             \
            mcuxClHash_compute(pSession,                                \
                              hashAlg,                                 \
                              buffPrivKey,                             \
                              privKeyLen,                              \
                              buffPrivKeyHash,                         \
                              &outLength) );                           \
        if (MCUXCLHASH_STATUS_OK != retHash)                            \
        {                                                              \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateKeyPair,  \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);   \
        }                                                              \
MCUX_CSSL_ANALYSIS_START_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while(false)                                                     \
MCUX_CSSL_ANALYSIS_STOP_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()


#define MCUXCLECC_FP_CALLED_EDDSA_KEYGEN_HASH_PRIVKEY  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute)


/******************************************************************************/
/* Macros to compute the hash H(prefix || (h_b,...,h_{2b-1}) || m') using     */
/*   - the hash function algoSecHash to hash the blocks containing the secret */
/*     (h_b,\dots,h_{2b-1}), and                                              */
/*   - the hash function algoHash to hash the remaining part of the input     */
/* hashOutputBufferSize shall be provided to create Buffer for pOutput.       */
/* The minimal size is: 64 for Ed25519;                                       */
/*                      MCUXCLHASH_OUTPUT_SIZE_SHA3_SHAKE_256 for Ed448.       */
/******************************************************************************/
#define MCUXCLECC_FP_EDDSA_SIGN_CALC_SCALAR(pSession, pCtx, algoHash, algoSecHash, pHashPrefix, hashPrefixLen, pPrivKeyHalfHash, privKeyHalfHashLength, buffIn, inSize, pOutput, hashOutputBufferSize) \
    do{                                                                     \
        uint32_t outLength = 0u;                                            \
                                                                            \
        (void) (algoHash); /* TODO: Use algoHash for blocks with not sensitive data (CLNS-7002) */ \
                                                                            \
        /* Initialize the hash context */                                   \
        MCUX_CSSL_FP_FUNCTION_CALL(retInitHash,                              \
            mcuxClHash_init(pSession,                                        \
                           pCtx,                                            \
                           algoSecHash) );                                  \
        if (MCUXCLHASH_STATUS_OK != retInitHash)                             \
        {                                                                   \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateSignature,     \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);        \
        }                                                                   \
                                                                            \
        /* Update hash context with prefix */                               \
        {                                                                   \
            MCUXCLBUFFER_INIT_RO(buffHashPrefix, NULL, pHashPrefix, hashPrefixLen); \
            MCUX_CSSL_FP_FUNCTION_CALL(retProcess1Hash,                      \
                mcuxClHash_process(pSession,                                 \
                                  pCtx,                                     \
                                  buffHashPrefix,                           \
                                  hashPrefixLen) );                         \
            if (MCUXCLHASH_STATUS_OK != retProcess1Hash)                     \
            {                                                               \
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateSignature, \
                                          MCUXCLECC_STATUS_FAULT_ATTACK);    \
            }                                                               \
        }                                                                   \
        /* Update hash context with (h_b,...,h_{2b-1}) */                   \
        {                                                                   \
            MCUXCLBUFFER_INIT_RO(buffPrivKeyHalfHash, NULL, pPrivKeyHalfHash, privKeyHalfHashLength); \
            MCUX_CSSL_FP_FUNCTION_CALL(retProcess2Hash,                      \
                mcuxClHash_process(pSession,                                 \
                                  pCtx,                                     \
                                  buffPrivKeyHalfHash,                      \
                                  privKeyHalfHashLength) );                 \
            if (MCUXCLHASH_STATUS_OK != retProcess2Hash)                     \
            {                                                               \
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateSignature, \
                                          MCUXCLECC_STATUS_FAULT_ATTACK);    \
            }                                                               \
        }                                                                   \
        /* Update hash context with m' */                                   \
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess3Hash,                          \
            mcuxClHash_process(pSession,                                     \
                              pCtx,                                         \
                              buffIn,                                       \
                              inSize) );                                    \
        if (MCUXCLHASH_STATUS_OK != retProcess3Hash)                         \
        {                                                                   \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateSignature,     \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);        \
        }                                                                   \
        /* Finalize hash computation */                                     \
        MCUXCLPKC_WAITFORFINISH();                                           \
        {                                                                   \
            MCUXCLBUFFER_INIT(buffOutput, NULL, pOutput, hashOutputBufferSize); \
            MCUX_CSSL_FP_FUNCTION_CALL(retFinishHash,                        \
                mcuxClHash_finish(pSession,                                  \
                                 pCtx,                                      \
                                 buffOutput,                                \
                                 &outLength) );                             \
            if (MCUXCLHASH_STATUS_OK != retFinishHash)                       \
            {                                                               \
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateSignature, \
                                          MCUXCLECC_STATUS_FAULT_ATTACK);    \
            }                                                               \
        }                                                                   \
MCUX_CSSL_ANALYSIS_START_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()   \
    } while(false)                                                          \
MCUX_CSSL_ANALYSIS_STOP_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLECC_FP_CALLED_EDDSA_SIGN_CALC_SCALAR   \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),    \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish)


/******************************************************************************/
/* Macro to compute input hash and store it in PKC workarea.                  */
/* Since the parameter b of both Ed25519 and Ed448 is a multiple of 8,        */
/* byte length of hash (= 2b/8) can be derived from                           */
/* byte length of encoded public key (= b/8).                                 */
/******************************************************************************/
#define MCUXCLECC_FP_EDDSA_SIGN_VERIFY_CALC_HASH(pSession, pCtx, hashAlg, pHashPrefix, hashPrefixLen, buffSignatureR, signatureRLen, pPubKey, pubKeyLen, buffIn, inSize, buffOutput) \
    do{                                                                     \
        uint32_t outLength = 0u;                                            \
                                                                            \
        /* Initialize the hash context */                                   \
        MCUX_CSSL_FP_FUNCTION_CALL(retInitHash,                              \
            mcuxClHash_init(pSession,                                        \
                            pCtx,                                           \
                            hashAlg) );                                     \
        if (MCUXCLHASH_STATUS_OK != retInitHash)                             \
        {                                                                   \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_CalcHashModN,          \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);        \
        }                                                                   \
                                                                            \
        /* Update hash context with prefix */                               \
        {                                                                   \
            MCUXCLBUFFER_INIT_RO(buffHashPrefix, NULL, pHashPrefix, hashPrefixLen); \
            MCUX_CSSL_FP_FUNCTION_CALL(retProcess1Hash,                      \
                mcuxClHash_process(pSession,                                 \
                                pCtx,                                       \
                                buffHashPrefix,                             \
                                hashPrefixLen) );                           \
            if (MCUXCLHASH_STATUS_OK != retProcess1Hash)                     \
            {                                                               \
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_CalcHashModN,      \
                                        MCUXCLECC_STATUS_FAULT_ATTACK);      \
            }                                                               \
        }                                                                   \
        /* Update hash context with Renc */                                 \
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess2Hash,                          \
            mcuxClHash_process(pSession,                                     \
                              pCtx,                                         \
                              buffSignatureR,                               \
                              signatureRLen) );                             \
        if (MCUXCLHASH_STATUS_OK != retProcess2Hash)                         \
        {                                                                   \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_CalcHashModN,          \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);        \
        }                                                                   \
        /* Update hash context with Qenc */                                 \
        {                                                                   \
            MCUXCLBUFFER_INIT_RO(buffPubKey, NULL, pPubKey, pubKeyLen);      \
            MCUX_CSSL_FP_FUNCTION_CALL(retProcess3Hash,                      \
                mcuxClHash_process(pSession,                                 \
                                  pCtx,                                     \
                                  buffPubKey,                               \
                                  pubKeyLen) );                             \
            if (MCUXCLHASH_STATUS_OK != retProcess3Hash)                     \
            {                                                               \
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_CalcHashModN,      \
                                          MCUXCLECC_STATUS_FAULT_ATTACK);    \
            }                                                               \
        }                                                                   \
        /* Update hash context with m' */                                   \
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess4Hash,                          \
            mcuxClHash_process(pSession,                                     \
                              pCtx,                                         \
                              buffIn,                                       \
                              inSize) );                                    \
        if (MCUXCLHASH_STATUS_OK != retProcess4Hash)                         \
        {                                                                   \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_CalcHashModN,          \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);        \
        }                                                                   \
                                                                            \
        MCUXCLPKC_WAITFORFINISH();                                           \
        /* Finalize hash computation */                                     \
        MCUX_CSSL_FP_FUNCTION_CALL(retFinishHash,                            \
            mcuxClHash_finish(pSession,                                      \
                              pCtx,                                         \
                              buffOutput,                                   \
                              &outLength) );                                \
        if (MCUXCLHASH_STATUS_OK != retFinishHash)                           \
        {                                                                   \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_CalcHashModN,          \
                                      MCUXCLECC_STATUS_FAULT_ATTACK);        \
        }                                                                   \
MCUX_CSSL_ANALYSIS_START_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()   \
    } while(false)                                                          \
MCUX_CSSL_ANALYSIS_STOP_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLECC_FP_CALLED_EDDSA_SIGN_VERIFY_CALC_HASH                  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),                        \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),                     \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),                     \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),                     \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),                     \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish)

#endif /* MCUXCLECC_EDDSA_INTERNAL_HASH_H_ */
