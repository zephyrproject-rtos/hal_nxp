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

#ifndef MCUXCLRANDOMMODES_PRIVATE_CTRDRBG_H_
#define MCUXCLRANDOMMODES_PRIVATE_CTRDRBG_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClAes.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Mode descriptor related defines for CTR_DRBGs */


#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES256 (256u)
#define MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES256 (48u)
#define MCUXCLRANDOMMODES_RESEED_INTERVAL_CTR_DRBG_AES256 (0x0001000000000000u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#if defined(MCUXCL_FEATURE_RANDOMMODES_DERIVATION_FUNCTION)


#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256 (71u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES256  (55u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#endif // MCUXCL_FEATURE_RANDOMMODES_NO_DERIVATION_FUNCTION



#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
/* Internal structure of a CTR_DRBG AES256 random context */
#define MCUXCLRANDOMMODES_CONTEXT_CTR_DRBG_AES256_SIZE_KEY_IN_WORDS (8u)
typedef struct
{
    MCUXCLRANDOMMODES_CONTEXT_DRBG_ENTRIES
    uint32_t key[MCUXCLRANDOMMODES_CONTEXT_CTR_DRBG_AES256_SIZE_KEY_IN_WORDS];
    uint32_t counterV[MCUXCLAES_BLOCK_SIZE_IN_WORDS];
} mcuxClRandomModes_Context_CtrDrbg_Aes256_t;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#define MCUXCLRANDOMMODES_CONTEXT_CTR_DRBG_MAX_SIZE_KEY_IN_WORDS (8u)
typedef struct
{
    MCUXCLRANDOMMODES_CONTEXT_DRBG_ENTRIES
    uint32_t state[MCUXCLRANDOMMODES_CONTEXT_CTR_DRBG_MAX_SIZE_KEY_IN_WORDS + MCUXCLAES_BLOCK_SIZE_IN_WORDS];
} mcuxClRandomModes_Context_CtrDrbg_Generic_t;

/* Internal function prototypes */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_instantiateAlgorithm, mcuxClRandomModes_instantiateAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_instantiateAlgorithm(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    uint8_t *pEntropyInputAndNonce);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_reseedAlgorithm, mcuxClRandomModes_reseedAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_reseedAlgorithm(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    uint8_t *pEntropyInput);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_generateAlgorithm, mcuxClRandomModes_generateAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_generateAlgorithm(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    mcuxCl_Buffer_t pOut,
    uint32_t outLength);

/* Refer to the NIST SP 800-90A 10.3.2 Derivation function using a block cipher algorithm */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_df)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_df(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    uint8_t *pInputString,
    uint32_t inputStringLen,
    uint32_t outputLen);

/* Refer to the NIST SP 800-90A 10.3.3 BCC and Block_Encrypt */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_bcc)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_bcc(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    uint32_t const *pKey,
    uint32_t * const pData,
    uint32_t dataLen,
    uint32_t *pOut);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_UpdateState)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_UpdateState(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    uint32_t *pProvidedData
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_generateOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_CtrDrbg_generateOutput(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    mcuxCl_Buffer_t pOut,
    uint32_t outLength);



#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
extern const mcuxClRandomModes_DrbgVariantDescriptor_t mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES256;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_PRIVATE_CTRDRBG_H_ */
