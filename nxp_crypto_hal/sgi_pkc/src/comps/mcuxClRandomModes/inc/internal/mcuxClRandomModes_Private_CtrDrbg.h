/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#define MCUXCLRANDOMMODES_BITSIZE_OF_WORD (sizeof(uint32_t) * 8u)

/* Security strengths for CTR_DRBGs */
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#define MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES128 (128u)
#define MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES128 (32u)
#define MCUXCLRANDOMMODES_RESEED_INTERVAL_CTR_DRBG_AES128 (0x0001000000000000u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
#define MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES192 (192u)
#define MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES192 (40u)
#define MCUXCLRANDOMMODES_RESEED_INTERVAL_CTR_DRBG_AES192 (0x0001000000000000u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES256 (256u)
#define MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES256 (48u)
#define MCUXCLRANDOMMODES_RESEED_INTERVAL_CTR_DRBG_AES256 (0x0001000000000000u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256


#ifdef MCUXCL_FEATURE_TRNG_SA_TRNG
/*
 * Seed sizes for CTR_DRBGs chosen as follows:
 *  - Let the initial min seed size values be given by
 *      - INIT: at least (1.5 * security strength / 0.75)
 *      - RESEED: at least (security strength / 0.75)
 *    Here, 0.75 is the assumed min-entropy level for the SA_TRNG, and the values are chosen to comply with
 *    NIST SP800-90A in case the TRNG doesn't provide full entropy and nonce and derivation function must be used
 *  - To add a security cushion without major impact on performance, these min seed sizes are increased
 *    to the max values which
 *      - require the same number of TRNG entropy generation windows, and
 *      - result in the same number of AES block operations during the block cipher derivation function
 *      - ensure that the difference between INIT and RESEED seed sizes is at least 0.5 * security strength to ensure CAVP compatibility. */
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG_512)
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES128 (39u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES128  (23u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES192 (55u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES192  (39u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256 (64u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES256  (48u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#elif defined(MCUXCL_FEATURE_TRNG_SA_TRNG_256)
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES128 (32u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES128  (23u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES192 (55u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES192  (32u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256 (64u)
#define MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES256  (48u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#else // MCUXCL_FEATURE_TRNG_SA_TRNG_256 || MCUXCL_FEATURE_TRNG_SA_TRNG_512
#error "When feature TRNG_SA_TRNG is included in the makefile, a variant TRNG_SA_TRNG_256 or TRNG_SA_TRNG_512 needs to be chosen."
#endif // MCUXCL_FEATURE_TRNG_SA_TRNG_256 || MCUXCL_FEATURE_TRNG_SA_TRNG_512

#else  // MCUXCL_FEATURE_TRNG_SA_TRNG || MCUXCL_FEATURE_TRNG_DIGI_TRNG
#error "No supported TRNG variant is included in the makefile."
#endif // MCUXCL_FEATURE_TRNG_SA_TRNG



/* Internal context structures for CTR_DRBGs */
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
/* Internal structure of a CTR_DRBG AES128 random context */
typedef struct
{
    MCUXCLRANDOMMODES_CONTEXT_DRBG_ENTRIES
    uint32_t key[MCUXCLAES_AES128_KEY_SIZE_IN_WORDS];
    uint32_t counterV[MCUXCLAES_BLOCK_SIZE_IN_WORDS];
} mcuxClRandomModes_Context_CtrDrbg_Aes128_t;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
/* Internal structure of a CTR_DRBG AES192 random context */
#define MCUXCLRANDOMMODES_CONTEXT_CTR_DRBG_AES192_SIZE_KEY_IN_WORDS (6u)
typedef struct
{
    MCUXCLRANDOMMODES_CONTEXT_DRBG_ENTRIES
    uint32_t key[MCUXCLRANDOMMODES_CONTEXT_CTR_DRBG_AES192_SIZE_KEY_IN_WORDS];
    uint32_t counterV[MCUXCLAES_BLOCK_SIZE_IN_WORDS];
} mcuxClRandomModes_Context_CtrDrbg_Aes192_t;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

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
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_instantiateAlgorithm(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    uint8_t *pEntropyInputAndNonce);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_reseedAlgorithm, mcuxClRandomModes_reseedAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_reseedAlgorithm(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    uint8_t *pEntropyInput);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_generateAlgorithm, mcuxClRandomModes_generateAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_generateAlgorithm(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    mcuxCl_Buffer_t pOut,
    uint32_t outLength,
    const uint32_t *pXorMask);

/* Refer to the NIST SP 800-90A 10.3.2 Derivation function using a block cipher algorithm */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_df)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_df(
    mcuxClSession_Handle_t pSession,
    uint32_t securityStrength,
    uint8_t *pInputString,
    uint32_t inputStringLen,
    uint32_t outputLen);

/* Refer to the NIST SP 800-90A 10.3.3 BCC and Block_Encrypt */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_bcc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_bcc(
    mcuxClSession_Handle_t pSession,
    uint32_t securityStrength,
    uint32_t * const pData,
    uint32_t dataLen,
    uint32_t *pOut);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_UpdateState)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_UpdateState(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    uint32_t *pProvidedData
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_generateOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_generateOutput(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context,
    mcuxCl_Buffer_t pOut,
    uint32_t outLength,
    const uint32_t *pXorMask);

/*
 * Potentially hardware specififc implementations. As these functions might be differently implemented for
 * different plattforms the comments might sound generic. For further details take a look at the concrete implementations.
 * e.g. the implemenation for the SGI in mcuxClRandomModes_CtrDrbg_Sgi.c
 */

/**
 * @brief Function to request HW for drbg internal operations
 *
 * This function requests HW for drbg internal operations
 *
 * @param      pSession         Handle for the session
 *
 * Check implementation comments for further details
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_requestHW)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_requestHW(mcuxClSession_Handle_t pSession);

/**
 * @brief Function to release HW used for drbg internal operations
 *
 * This function releases HW used for drbg internal operations
 * Check implementation comments for further details
 *
 * @param      pSession         Handle for the session
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_releaseHW)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_releaseHW(mcuxClSession_Handle_t pSession);

/**
 * @brief Function to clean up HW used for drbg internal operations
 *
 * This function cleans up HW used for drbg internal operations
 * Check implementation comments for further details
 *
 * @param void
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_cleanUpHW)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_cleanUpHW(void);

/**
 * @brief Function to load and input block for blockcipher operation
 *
 * This function loads an input block for the blockcipher operation
 * Check implementation comments for further details
 *
 * Data Integrity: Record(MCUXCLAES_BLOCK_SIZE_IN_WORDS)
 *
 * @param      pInputBlock  Pointer to block to load
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadInput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadInput(
    uint32_t *pInputBlock
);

/**
 * @brief Function to load key for blockcipher operation
 *
 * This function loads key for the blockcipher operation
 * Check implementation comments for further details
 *
 * @param      pKey         Pointer to the key
 * @param      keyLength    Length of the key
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadKey(
    uint32_t const *pKey,
    uint32_t keyLength
);

/**
 * @brief Function to start to encrypt one block of data
 *
 * This function starts to encrypt one block of data.
 * Check implementation comments for further details
 *
 * Data Integrity: Record(keyLength)
 *
 * @param      pSession     Handle for the session
 * @param[in]  keyLength    Length of the key
 *
 * @return void
 *
 * @note Function uses early-exit mechanism with following return codes:
 *      - #MCUXCLRANDOM_STATUS_FAULT_ATTACK when invalid keyLength is provided
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt(
    mcuxClSession_Handle_t pSession,
    uint32_t keyLength
);

/**
 * @brief Function to complete an encryption of one block of data
 *
 * This function completes an encryption of one block of data.
 * Check implementation comments for further details
 *
 * Data Integrity: Expunge(keyLength)
 *
 * @param      pSession     Handle for the session
 * @param[in]  pOut         Pointer to the buffer to hold the encrypted block
 * @param[in]  pXorMask     Pointer to mask value(if not NULL, stores a 128-bit block of data using masking
 *                          from the specified SGI data register bank to pOut)
 * @param[in]  keyLength    Length of the key
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt(
    mcuxClSession_Handle_t pSession,
    uint8_t*  pOut,
    const uint32_t *pXorMask,
    uint32_t keyLength
);

/**
 * @brief Function to increment the counter V
 *
 * This functions increments the counter V
 * Check implementation comments for further details
 *
 * Note: this function can be called between mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt and mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt without impacting the result
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_CtrDrbg_incV)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_incV(mcuxClSession_Handle_t pSession);

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
extern const mcuxClRandomModes_DrbgVariantDescriptor_t mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES128;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
extern const mcuxClRandomModes_DrbgVariantDescriptor_t mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES192;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
extern const mcuxClRandomModes_DrbgVariantDescriptor_t mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES256;
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_PRIVATE_CTRDRBG_H_ */
