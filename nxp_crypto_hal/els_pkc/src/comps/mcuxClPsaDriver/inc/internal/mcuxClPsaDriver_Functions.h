/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClPsaDriver_Functions.h
 *  @brief Helper function definitions for the mcuxClPsaDriver component
 */

#ifndef MCUXCLPSADRIVER_FUNCTIONS_H_
#define MCUXCLPSADRIVER_FUNCTIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <mcuxClAeadModes.h>
#include <mcuxClCipherModes.h>
#include <mcuxClMacModes.h>
#include <mcuxClPsaDriver.h>
#include <mcuxClRsa_Types.h>

#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClPsaDriver_ExternalMacroWrappers.h>

#include "els_pkc_crypto_composites.h"
#include "els_pkc_crypto_primitives.h"

/**
 * @defgroup mcuxClPsaDriver_Functions mcuxClPsaDriver_Functions
 * @brief Defines all internal functions of @ref mcuxClPsaDriver
 * @ingroup mcuxClPsaDriver
 * @{
 */

static inline bool key_type_is_raw_bytes( psa_key_type_t type )
{
    return( PSA_KEY_TYPE_IS_UNSTRUCTURED( type ) );
}

static inline bool mcuxClPsaDriver_psa_driver_wrapper_aead_doesKeyPolicySupportAlg(const psa_key_attributes_t *attributes, psa_algorithm_t alg)
{
    return (MCUXCLPSADRIVER_PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(psa_get_key_algorithm(attributes)) == MCUXCLPSADRIVER_PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg));
}

static inline bool mcuxClPsaDriver_psa_driver_wrapper_aead_isAlgSupported(const psa_key_attributes_t *attributes)
{
    return ((psa_get_key_type(attributes) == PSA_KEY_TYPE_AES)
                && (PSA_ALG_IS_AEAD_ON_BLOCK_CIPHER(psa_get_key_algorithm(attributes))));
}

static inline mcuxClAead_Mode_t mcuxClPsaDriver_psa_driver_wrapper_aead_selectModeEnc(const psa_algorithm_t alg)
{
    /* Recover default algorithm (could be CCM with changed tag size) */
    const psa_algorithm_t algDefault = MCUXCLPSADRIVER_PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);

    const mcuxClAead_ModeDescriptor_t * mode = NULL;
    switch(algDefault)
    {
        case PSA_ALG_CCM:
        case PSA_ALG_CCM_STAR_NO_TAG:
            mode = mcuxClAead_Mode_AES_CCM_ENC;
            break;
        case PSA_ALG_GCM:
            mode = mcuxClAead_Mode_AES_GCM_ENC;
            break;
        default:
            mode = NULL;
            break;
    }
    return (mcuxClAead_Mode_t) mode;
}

static inline bool mcuxClPsaDriver_psa_driver_wrapper_cipher_isAlgSupported(const psa_key_attributes_t *attributes)
{
    psa_algorithm_t alg = psa_get_key_algorithm(attributes);
    if( PSA_KEY_TYPE_AES == psa_get_key_type(attributes)
               && (   PSA_ALG_ECB_NO_PADDING == alg
                   || PSA_ALG_CBC_NO_PADDING == alg
                   || PSA_ALG_CTR            == alg ))
    {
        return true;
    }

    return false;
}

static inline bool mcuxClPsaDriver_psa_driver_wrapper_cipher_doesKeyPolicySupportAlg(const psa_key_attributes_t *attributes, psa_algorithm_t alg)
{
    return (psa_get_key_algorithm(attributes) == alg);
}

static inline uint8_t mcuxClPsaDriver_psa_driver_wrapper_cipher_modeSelectEnc(const psa_algorithm_t alg,
                                                   const mcuxClCipher_ModeDescriptor_t **mode)
{
    uint8_t iv_required = 1u;
    switch (alg)
    {
    case PSA_ALG_ECB_NO_PADDING:
        *mode = mcuxClCipher_Mode_AES_ECB_Enc_NoPadding;
        iv_required = 0u;
        break;
    case PSA_ALG_CBC_NO_PADDING:
        *mode = mcuxClCipher_Mode_AES_CBC_Enc_NoPadding;
        break;
    case PSA_ALG_CTR:
        *mode = mcuxClCipher_Mode_AES_CTR;
        break;
    default:
        *mode = NULL;
        iv_required = 0u;
        break;
    }

    return iv_required;
}

static inline mcuxClAead_Mode_t mcuxClPsaDriver_psa_driver_wrapper_aead_selectModeDec(const psa_algorithm_t alg)
{
    /* Recover default algorithm (could be CCM with changed tag size) */
    const psa_algorithm_t algDefault = MCUXCLPSADRIVER_PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);

    const mcuxClAead_ModeDescriptor_t *mode = NULL;
    switch (algDefault)
    {
    case PSA_ALG_CCM:
    case PSA_ALG_CCM_STAR_NO_TAG:
        mode = &mcuxClAead_ModeDescriptor_AES_CCM_DEC;
        break;
    case PSA_ALG_GCM:
        mode = &mcuxClAead_ModeDescriptor_AES_GCM_DEC;
        break;
    default:
        mode = NULL;
        break;
    }
    return (mcuxClAead_Mode_t)mode;
}

static inline uint8_t mcuxClPsaDriver_psa_driver_wrapper_cipher_modeSelectDec(const psa_algorithm_t alg,
                                                   const mcuxClCipher_ModeDescriptor_t **mode)
{
    uint8_t iv_required = 1u;
    switch (alg)
    {
    case PSA_ALG_ECB_NO_PADDING:
        *mode = mcuxClCipher_Mode_AES_ECB_Dec_NoPadding;
        iv_required = 0u;
        break;
    case PSA_ALG_CBC_NO_PADDING:
        *mode = mcuxClCipher_Mode_AES_CBC_Dec_NoPadding;
        break;
    case PSA_ALG_CTR:
        *mode = mcuxClCipher_Mode_AES_CTR;
        break;
    default:
        *mode = NULL;
        iv_required = 0u;
        break;
    }

    return iv_required;
}

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_abort(
    els_pkc_aead_operation_t  *operation);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_decrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *nonce_,
    size_t nonce_length,
    const uint8_t *additional_data_,
    size_t additional_data_length,
    const uint8_t *ciphertext,
    size_t ciphertext_length,
    uint8_t *plaintext_,
    size_t plaintext_size,
    size_t *plaintext_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_decrypt_setup(
   els_pkc_aead_operation_t  *operation,
   const psa_key_attributes_t *attributes,
   const uint8_t *key_buffer,
   size_t key_buffer_size,
   psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_encrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
	size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *nonce_,
    size_t nonce_length,
    const uint8_t *additional_data_,
    size_t additional_data_length,
    const uint8_t *plaintext_,
    size_t plaintext_length,
    uint8_t *ciphertext,
    size_t ciphertext_size,
    size_t *ciphertext_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_encrypt_setup(
   els_pkc_aead_operation_t  *operation,
   const psa_key_attributes_t *attributes,
   const uint8_t *key_buffer,
   size_t key_buffer_size,
   psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_finish(
   els_pkc_aead_operation_t  *operation,
   uint8_t *ciphertext,
   size_t ciphertext_size,
   size_t *ciphertext_length,
   uint8_t *tag,
   size_t tag_size,
   size_t *tag_length);

psa_status_t mcuxClPsaDriver_psa_driver_get_tag_len(
    els_pkc_aead_operation_t  *operation,
    uint8_t *tag_len);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_set_lengths(
   els_pkc_aead_operation_t  *operation,
   size_t ad_length,
   size_t plaintext_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_set_nonce(
   els_pkc_aead_operation_t  *operation,
   const uint8_t *nonce_,
   size_t nonce_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_update_ad(
   els_pkc_aead_operation_t  *operation,
   const uint8_t *input,
   size_t input_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_verify(
   els_pkc_aead_operation_t  *operation,
   uint8_t *plaintext_,
   size_t plaintext_size,
   size_t *plaintext_length,
   const uint8_t *tag,
   size_t tag_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_aead_update(
   els_pkc_aead_operation_t  *operation,
   const uint8_t *input,
   size_t input_length,
   uint8_t *output,
   size_t output_size,
   size_t *output_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *iv_data,
    size_t iv_length,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_abort(
    els_pkc_cipher_operation_t *operation);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt_setup(
    els_pkc_cipher_operation_t *operation,
    const psa_key_attributes_t * attributes,
    const uint8_t * key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt_setup(
    els_pkc_cipher_operation_t *operation,
    const psa_key_attributes_t * attributes,
    const uint8_t * key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_finish(
    els_pkc_cipher_operation_t *operation,
    uint8_t *output,
    size_t output_size,
    size_t *output_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt(
    const psa_key_attributes_t * attributes,
    const uint8_t * key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_set_iv(
    els_pkc_cipher_operation_t *operation,
    const uint8_t *iv_data,
    size_t iv_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_update(
    els_pkc_cipher_operation_t *operation,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_createClKey(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    mcuxClKey_Descriptor_t *out_key_descriptor
);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_der_updatePointerTag(
    const uint8_t **p,
    uint8_t tag);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_der_get_integer(
    const uint8_t **p,
    mcuxClRsa_KeyEntry_t  * key);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_der_integer(
    uint8_t **p,
    mcuxClRsa_KeyEntry_t  * key);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_export_public_key(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    uint8_t *data,
    size_t data_size,
    size_t *data_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_generate_ecp_key(
    const psa_key_attributes_t *attributes,
    uint8_t *key_buffer,
    size_t key_buffer_size,
    size_t *key_buffer_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_rsa_key(
    const psa_key_attributes_t *attributes,
    uint8_t *key_buffer,
    size_t key_buffer_size,
    size_t *key_buffer_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_key_generate(
    const psa_key_attributes_t *attributes,
    uint8_t *key_buffer,
    size_t key_buffer_size,
    size_t *key_buffer_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_key_agreement(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *peer_key,
    size_t peer_key_length,
    uint8_t *shared_secret,
    size_t shared_secret_size,
    size_t *shared_secret_length);

const mcuxClEcc_Weier_DomainParams_t* mcuxClPsaDriver_psa_driver_wrapper_getEccDomainParams(
    const psa_key_attributes_t *attributes);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_abort(
    els_pkc_hash_operation_t *operation);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_clone(
    const els_pkc_hash_operation_t *source_operation,
    els_pkc_hash_operation_t *target_operation);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_compute(
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *hash_,
    size_t hash_size,
    size_t *hash_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_finish(
    els_pkc_hash_operation_t *operation,
    uint8_t *hash_,
    size_t hash_size,
    size_t *hash_length);

const mcuxClHash_AlgorithmDescriptor_t * mcuxClPsaDriver_psa_driver_wrapper_hash_set_algorithmDescriptor(
    psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_setup(
    els_pkc_hash_operation_t *operation,
    psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_update(
    els_pkc_hash_operation_t *operation,
    const uint8_t *input,
    size_t input_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_mac_computeLayer(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *mac,
    size_t mac_size,
    size_t *mac_length);

const mcuxClMac_ModeDescriptor_t * mcuxClPsaDriver_psa_driver_wrapper_mac_getMode(
    const psa_key_attributes_t *attributes,
    psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_mac_finalizeLayer(
    els_pkc_mac_operation_t *operation,
    uint8_t *mac,
    size_t mac_size,
    size_t *mac_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_mac_setupLayer(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    els_pkc_mac_operation_t *operation,
    psa_algorithm_t alg);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_mac_updateLayer(
    els_pkc_mac_operation_t *operation,
    const uint8_t *input,
    size_t input_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_mac_abort(els_pkc_mac_operation_t *operation);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_sign_message(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *signature,
    size_t signature_size,
    size_t *signature_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_sign_hash(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input_hash,
    size_t hash_length,
    uint8_t *signature,
    size_t signature_size,
    size_t *signature_length);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_sign(
    mcuxClKey_Descriptor_t *pKey,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *signature,
    size_t signature_size,
    size_t *signature_length,
    bool isHash);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusSuspend(
    mcuxClKey_Descriptor_t *key_descriptor);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusResume(
    mcuxClKey_Descriptor_t *key_descriptor);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusUnload(
    mcuxClKey_Descriptor_t *key_descriptor);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_verify(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    const uint8_t *signature,
    size_t signature_length,
    bool isHash);

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_exportKey(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    uint8_t *data,
    size_t data_size,
    size_t *data_length);


/* Inline functions for proper type casts */

/**
 * @brief Cast a key decriptor's auxilary data pointer to a pointer to psa_key_attributes_t.
 *
 * @param pKey    Pointer to the key descriptor.
 */
static inline psa_key_attributes_t* mcuxClPsaDriver_castAuxDataToKeyAttributes(mcuxClKey_Descriptor_t *pKey)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    return (psa_key_attributes_t *) mcuxClKey_getAuxData(pKey);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
}

/**
 * @}
 */ /* mcuxClPsaDriver_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPSADRIVER_FUNCTIONS_H_ */

