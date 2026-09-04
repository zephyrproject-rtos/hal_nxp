/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_pkc_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * asymmetric signature capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */
#include "mcux_psa_pkc_asymmetric_signature.h"
#include "mcux_psa_sgi_common_key_management.h"
#include "mcux_psa_pkc_key_generation.h"

/* Uncompressed public key = 0x04 tag byte + X and Y coordinates, each up to
 * MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP bytes (the largest supported prime field).
 * The pair buffer additionally holds the private scalar, whose length is also
 * bounded by MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP. Using the CL constant keeps
 * these buffers in sync with the raw point buffer used during export. */
#define MAX_PUB_KEY_SIZE_IN_BYTES  ((2u * MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP) + 1u)
#define MAX_PAIR_KEY_SIZE_IN_BYTES (MAX_PUB_KEY_SIZE_IN_BYTES + MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP)

psa_status_t pkc_sign_hash(const psa_key_attributes_t *attributes,
                           const uint8_t *key_buffer,
                           size_t key_buffer_size,
                           psa_algorithm_t alg, const uint8_t *input,
                           size_t input_length, uint8_t *signature,
                           size_t signature_size, size_t *signature_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t output_size = 0;
    uint32_t signatureSize = 0u;

    /* Validate all parameters BEFORE acquiring mutex */
    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Deterministic ECDSA not supported */
    if (true == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Validate key type is ECC key pair */
    if (!PSA_KEY_TYPE_IS_ECC_KEY_PAIR(psa_get_key_type(attributes))) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    output_size = PSA_SIGN_OUTPUT_SIZE(psa_get_key_type(attributes),
                                       psa_get_key_bits(attributes),
                                       alg);
    if (output_size > signature_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Acquire mutex */
    if (mcux_mutex_lock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Setup one session to be used by all functions called */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLSIGNATURE_SIGN_ECDSA_WACPU_SIZE,
                                                  MCUXCLSIGNATURE_SIGN_ECDSA_WAPKC_SIZE_640);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Create private key descriptor using the common key management utility */
    mcuxClKey_Descriptor_t privKeyDesc;
    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &privKeyDesc);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    /* Initialize the RNG context and Initialize the PRNG */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(session,
                                              MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
                                              mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ss_status, ss_token, mcuxClSignature_sign(
                                         session,
                                         (mcuxClKey_Handle_t) &privKeyDesc,
                                         mcuxClSignature_Mode_ECDSA,
                                         input,
                                         input_length,
                                         signature,
                                         &signatureSize)
                                     );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSignature_sign) != ss_token) ||
        (MCUXCLSIGNATURE_STATUS_OK != ss_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *signature_length = signatureSize;
    status = PSA_SUCCESS;

exit:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) ||
        (MCUXCLSESSION_STATUS_OK != result)) {
        /* Don't override previous success/error, but if we were successful, report corruption */
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t pkc_verify_hash(const psa_key_attributes_t *attributes,
                             const uint8_t *key_buffer,
                             size_t key_buffer_size,
                             psa_algorithm_t alg, const uint8_t *hash,
                             size_t hash_length, const uint8_t *signature,
                             size_t signature_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (PSA_ALG_IS_ECDSA(alg) != true) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }


    if ((PSA_KEY_TYPE_IS_KEY_PAIR(psa_get_key_type(attributes)) != true)
        && (PSA_KEY_TYPE_IS_PUBLIC_KEY(psa_get_key_type(attributes)) != true)) {
        /* Invalid key type detected, The response shall be PSA_ERROR_NOT_SUPPORTED */
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Acquire mutex */
    if (mcux_mutex_lock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Setup one session to be used by all functions called */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLSIGNATURE_VERIFY_ECDSA_WACPU_SIZE,
                                                  MCUXCLSIGNATURE_VERIFY_ECDSA_WAPKC_SIZE_640);

    const uint8_t *key_data_pub = NULL;
    size_t key_data_size = 0u;

    /* For exporting the public part of the key */
    uint8_t public_key_data[MAX_PAIR_KEY_SIZE_IN_BYTES] = { 0u };
    size_t public_key_data_length = 0u;

    if (true == PSA_KEY_TYPE_IS_KEY_PAIR(psa_get_key_type(attributes))) {
        /* In PSA, an ECC key pair is represented by the secret value,
         * so we need to also export the public part and position them
         * correctly in memory [pub_x, pub_y, private] */
        status = pkc_internal_export_ecp_public_key(attributes,
                                       key_buffer,
                                       public_key_data,
                                       MAX_PAIR_KEY_SIZE_IN_BYTES,
                                       &public_key_data_length);

        if (PSA_SUCCESS != status) {
            goto exit;
        }

        if (0u == public_key_data_length) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }

        /* Need to move 1byte for leading byte (0x04) which is indicating uncompressed format. */
        key_data_pub = public_key_data + 1;
        key_data_size = public_key_data_length - 1u;
    } else if (true == PSA_KEY_TYPE_IS_PUBLIC_KEY(psa_get_key_type(attributes))) {

        /* Need to move 1byte for leading byte (0x04) which is indicating uncompressed format. */
        key_data_pub = (const uint8_t *) key_buffer + 1;
        key_data_size = key_buffer_size - 1u;
    } else {
        /* Expecting public key or keypair */
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Create public key descriptor using the common key management utility.
     * Construct public-key attributes from the original attributes so that
     * sgi_create_key_descriptor resolves the correct public ECC type. */
    psa_key_attributes_t pub_attributes = *attributes;

    psa_key_type_t orig_type = psa_get_key_type(attributes);
    if (PSA_KEY_TYPE_IS_KEY_PAIR(orig_type)) {
        /* Convert key pair type to corresponding public key type */
        psa_ecc_family_t family = PSA_KEY_TYPE_ECC_GET_FAMILY(orig_type);
        psa_set_key_type(&pub_attributes, PSA_KEY_TYPE_ECC_PUBLIC_KEY(family));
    }

    mcuxClKey_Descriptor_t pubKeyDesc;
    status = sgi_create_key_descriptor(&pub_attributes, key_data_pub, key_data_size, &pubKeyDesc);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    /* Initialize the RNG context and Initialize the PRNG */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(session,
                                              MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
                                              mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3);

    /**************************************************************************/
    /* ECDSA signature verification                                            */
    /**************************************************************************/
    /* Record critical parameters for additional protection */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(rp_status, rp_token, mcuxClSignature_verify_recordParam(
                                         session,
                                         mcuxClSignature_Mode_ECDSA,
                                         hash,
                                         hash_length)
                                     );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSignature_verify_recordParam) != rp_token) ||
        (MCUXCLSIGNATURE_STATUS_OK != rp_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(sv_status, sv_token, mcuxClSignature_verify(
                                         session,
                                         (mcuxClKey_Handle_t) &pubKeyDesc,
                                         mcuxClSignature_Mode_ECDSA,
                                         hash,
                                         hash_length,
                                         signature,
                                         signature_length)
                                     );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSignature_verify) != sv_token) ||
        (MCUXCLSIGNATURE_STATUS_OK != sv_status)) {
        status = PSA_ERROR_INVALID_SIGNATURE;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    status = PSA_SUCCESS;

exit:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) ||
        (MCUXCLSESSION_STATUS_OK != result)) {
        /* Don't override previous success/error, but if we were successful, report corruption */
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}


/** @} */ // end of psa_asym_sign
