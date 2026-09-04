/*
 * Copyright 2025 - 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_sgi_mac.c
 *
 * This file contains the implementation of the entry points associated to the
 * mac capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_sgi_mac.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "tf-psa-crypto/build_info.h"
#else
/* This is for backwards compatibility with MbedTLS 3.x. Post-MbedTLS 3.x this
 * include would only work iff we forced MbedTLS to be built with TF PSA Crypto,
 * which is not a given, since PSA core (TF PSA Crypto) no longer has a hard
 * dependency on MbedTLS >= 4.
 */
#include "mbedtls/build_info.h"
#endif

#include "mcux_psa_sgi_common_key_management.h"

#include <mcuxClKey.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>

#if defined(PSA_WANT_ALG_HMAC)
#include <mcuxClHmac.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#endif /* PSA_WANT_ALG_HMAC */

/* Session CPU work-area size for the multipart MAC paths. The multipart
 * entry points serve both CMAC and (when enabled) HMAC. HMAC requires a
 * considerably larger work area than CMAC, so size the session for the
 * larger of the two when HMAC is compiled in. */
#if defined(PSA_WANT_ALG_HMAC)
#define SGI_MAC_MAX_CPU_WA_BUFFER_SIZE                                         \
    ((MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE > MCUXCLHMAC_MAX_CPU_WA_BUFFER_SIZE)     \
         ? MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE                                     \
         : MCUXCLHMAC_MAX_CPU_WA_BUFFER_SIZE)
#else
#define SGI_MAC_MAX_CPU_WA_BUFFER_SIZE MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE
#endif /* PSA_WANT_ALG_HMAC */

/* Largest supported MAC output. The composite MCUXCLMAC_MAX_OUTPUT_SIZE macro
 * lives in an internal mcuxClMac header not exposed to the PSA driver, so
 * recreate the same maximum from the public per-mode macros: CMAC/MacModes use
 * MCUXCLMACMODES_MAX_OUTPUT_SIZE (16B), HMAC (when enabled) uses the larger
 * MCUXCLHMAC_MAX_OUTPUT_SIZE. */
#if defined(PSA_WANT_ALG_HMAC)
#define SGI_MAC_MAX_OUTPUT_SIZE                                                \
    ((MCUXCLMACMODES_MAX_OUTPUT_SIZE > MCUXCLHMAC_MAX_OUTPUT_SIZE)              \
         ? MCUXCLMACMODES_MAX_OUTPUT_SIZE                                       \
         : MCUXCLHMAC_MAX_OUTPUT_SIZE)
#else
#define SGI_MAC_MAX_OUTPUT_SIZE MCUXCLMACMODES_MAX_OUTPUT_SIZE
#endif /* PSA_WANT_ALG_HMAC */



/*
 * Entry points for MAC computation and verification as described by the PSA
 *  Cryptoprocessor Driver interface specification
 */

/* Convert PSA Algorithm to SGI Algorithm */
static inline mcuxClMac_Mode_t get_mac_sgi_mode(const psa_key_attributes_t *attributes,
                                                psa_algorithm_t alg)
{
    switch (PSA_ALG_FULL_LENGTH_MAC(alg)) {
    /*AES based algorithms and paddings */
#if defined(PSA_WANT_ALG_CMAC)
        case PSA_ALG_CMAC:
            return mcuxClMac_Mode_CMAC;
#endif /* PSA_WANT_ALG_CMAC */
        default:
            return NULL;
    }
}

#if defined(PSA_WANT_ALG_HMAC)
/* Map the hash used by a PSA HMAC algorithm to a mcuxCl hash algorithm
 * descriptor. Returns NULL for unsupported hashes. */
static inline mcuxClHash_Algo_t get_hmac_hash_algo(psa_algorithm_t alg)
{
    switch (PSA_ALG_HMAC_GET_HASH(alg)) {
#if defined(PSA_WANT_ALG_SHA_224)
        case PSA_ALG_SHA_224:
            return mcuxClHash_Algorithm_Sha224;
#endif /* PSA_WANT_ALG_SHA_224 */
#if defined(PSA_WANT_ALG_SHA_256)
        case PSA_ALG_SHA_256:
            return mcuxClHash_Algorithm_Sha256;
#endif /* PSA_WANT_ALG_SHA_256 */
#if defined(PSA_WANT_ALG_SHA_384)
        case PSA_ALG_SHA_384:
            return mcuxClHash_Algorithm_Sha384;
#endif /* PSA_WANT_ALG_SHA_384 */
#if defined(PSA_WANT_ALG_SHA_512)
        case PSA_ALG_SHA_512:
            return mcuxClHash_Algorithm_Sha512;
#endif /* PSA_WANT_ALG_SHA_512 */
        default:
            return NULL;
    }
}

/* One-shot HMAC computation. The HMAC mode descriptor is constructed at
 * runtime from the requested hash algorithm via mcuxClHmac_createHmacMode(). */
static psa_status_t sgi_mac_compute_hmac(const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         psa_algorithm_t alg,
                                         const uint8_t *input,
                                         size_t input_length,
                                         uint8_t *mac,
                                         size_t mac_size,
                                         size_t *mac_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    mcuxClHash_Algo_t hashAlgo = get_hmac_hash_algo(alg);
    if (hashAlgo == NULL) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, MCUXCLHMAC_MAX_CPU_WA_BUFFER_SIZE, 0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Build the HMAC mode descriptor for the requested hash. */
    uint32_t hmacModeDescBuffer[MCUXCLHMAC_HMAC_MODE_DESCRIPTOR_SIZE_IN_WORDS] = { 0u };
    mcuxClMac_CustomMode_t hmacMode = (mcuxClMac_CustomMode_t) hmacModeDescBuffer;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cm_status, cm_token,
                                     mcuxClHmac_createHmacMode(hmacMode, hashAlgo));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_createHmacMode) != cm_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != cm_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    mcuxClKey_Descriptor_t keyDesc;

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    uint32_t mac_length_tmp = (uint32_t) mac_size;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mc_status, mc_token,
                                     mcuxClMac_compute(session,
                                                       (mcuxClKey_Handle_t) &keyDesc,
                                                       hmacMode,
                                                       input,
                                                       input_length,
                                                       mac,
                                                       &mac_length_tmp));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute) != mc_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != mc_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *mac_length = mac_length_tmp;
    status = PSA_SUCCESS;

cleanup:
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}
#endif /* PSA_WANT_ALG_HMAC */

psa_status_t sgi_mac_compute(const psa_key_attributes_t *attributes,
                             const uint8_t *key_buffer,
                             size_t key_buffer_size,
                             psa_algorithm_t alg,
                             const uint8_t *input,
                             size_t input_length,
                             uint8_t *mac,
                             size_t mac_size,
                             size_t *mac_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t key_bits = psa_get_key_bits(attributes);
    psa_key_type_t key_type = psa_get_key_type(attributes);

#if defined(PSA_WANT_ALG_HMAC)
    /* HMAC uses a runtime-constructed mode descriptor and a dedicated
     * one-shot path (see sgi_mac_compute_hmac). */
    if (PSA_ALG_IS_HMAC(alg)) {
        return sgi_mac_compute_hmac(attributes, key_buffer, key_buffer_size, alg,
                                    input, input_length, mac, mac_size, mac_length);
    }
#endif /* PSA_WANT_ALG_HMAC */

    /* Get the correct MAC mode based on the given algorithm. */
    const mcuxClMac_ModeDescriptor_t *mode;

    mode = get_mac_sgi_mode(attributes, alg);
    if (mode == NULL) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    mac_size = PSA_MAC_LENGTH(key_type, key_bits, alg);

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE, 0u);

    mcuxClKey_Descriptor_t keyDesc;

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    uint32_t mac_length_tmp = mac_size;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mc_status, mc_token,
                                     mcuxClMac_compute(session,
                                                       (mcuxClKey_Handle_t) &keyDesc,
                                                       mode,
                                                       input,
                                                       input_length,
                                                       mac,
                                                       &mac_length_tmp));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute) != mc_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != mc_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *mac_length = mac_length_tmp;
    status = PSA_SUCCESS;

cleanup:
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_mac_sign_setup(sgi_mac_operation_t *operation,
                                const psa_key_attributes_t *attributes,
                                const uint8_t *key_buffer,
                                size_t key_buffer_size, psa_algorithm_t alg)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Resolve the MAC mode for the requested algorithm.
     *
     * CMAC uses a static, const mode descriptor. HMAC has no static mode; its
     * descriptor is constructed at runtime from the requested hash. Because
     * the multipart MAC context only stores a pointer to the mode descriptor
     * (see mcuxClMac_init), the HMAC descriptor must be built in storage that
     * outlives this function. It is therefore built into the persistent
     * operation object (operation->hmacModeDesc), not on the stack. */
    const mcuxClMac_ModeDescriptor_t *mode = NULL;

#if defined(PSA_WANT_ALG_HMAC)
    if (PSA_ALG_IS_HMAC(alg) == true) {
        mcuxClHash_Algo_t hashAlgo = get_hmac_hash_algo(alg);
        if (hashAlgo == NULL) {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    } else
#endif /* PSA_WANT_ALG_HMAC */
    {
        /* Get the correct MAC mode based on the given algorithm. */
        mode = get_mac_sgi_mode(attributes, alg);
        if (mode == NULL) {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, SGI_MAC_MAX_CPU_WA_BUFFER_SIZE, 0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

#if defined(PSA_WANT_ALG_HMAC)
    if (PSA_ALG_IS_HMAC(alg) == true) {
        /* Build the HMAC mode descriptor into the persistent operation object
         * so it stays valid for the whole multipart operation. */
        mcuxClMac_CustomMode_t hmacMode = (mcuxClMac_CustomMode_t) operation->hmacModeDesc;

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cm_status, cm_token,
                                         mcuxClHmac_createHmacMode(hmacMode,
                                                                   get_hmac_hash_algo(alg)));

        if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_createHmacMode) != cm_token) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
            goto cleanup;
        }

        if (MCUXCLMAC_STATUS_OK != cm_status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
            goto cleanup;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        mode = (const mcuxClMac_ModeDescriptor_t *) hmacMode;
    }
#endif /* PSA_WANT_ALG_HMAC */

    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size,
                                       (mcuxClKey_Descriptor_t *) &operation->keyDesc);
    if (PSA_SUCCESS != status) {
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mi_status, mi_token,
                                     mcuxClMac_init(session,
                                                    (mcuxClMac_Context_t *) operation->ctx,
                                                    (mcuxClKey_Handle_t) &operation->keyDesc,
                                                    mode));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init) != mi_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != mi_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    status = PSA_SUCCESS;

cleanup:
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_mac_verify_setup(sgi_mac_operation_t *operation,
                                  const psa_key_attributes_t *attributes,
                                  const uint8_t *key_buffer,
                                  size_t key_buffer_size, psa_algorithm_t alg)
{
    return sgi_mac_sign_setup(operation, attributes, key_buffer, key_buffer_size, alg);
}

psa_status_t sgi_mac_update(sgi_mac_operation_t *operation,
                            const uint8_t *input, size_t input_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, SGI_MAC_MAX_CPU_WA_BUFFER_SIZE, 0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mp1_status, mp1_token,
                                     mcuxClMac_process(session,
                                                       (mcuxClMac_Context_t *) operation->ctx,
                                                       input, input_length));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process) != mp1_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != mp1_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_mac_sign_finish(sgi_mac_operation_t *operation,
                                 uint8_t *mac, size_t mac_size,
                                 size_t *mac_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, SGI_MAC_MAX_CPU_WA_BUFFER_SIZE, 0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    mcuxClMac_Context_t * const ctx = (mcuxClMac_Context_t *) operation->ctx;

    uint32_t outputSize = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mf_status, mf_token,
                                     mcuxClMac_finish(session, ctx, mac, &outputSize));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish) != mf_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != mf_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *mac_length = outputSize;
    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_mac_verify_finish(sgi_mac_operation_t *operation,
                                   const uint8_t *mac, size_t mac_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    /* Buffer must hold the largest supported MAC output. HMAC-SHA-512 (64B)
     * is larger than the CMAC/AES block output (16B), so use the MAC-wide
     * maximum which accounts for both. */
    uint8_t macCalc[SGI_MAC_MAX_OUTPUT_SIZE];


    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session, SGI_MAC_MAX_CPU_WA_BUFFER_SIZE, 0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    mcuxClMac_Context_t * const ctx = (mcuxClMac_Context_t *) operation->ctx;

    uint32_t outputSize = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(mf_status, mf_token,
                                     mcuxClMac_finish(session, ctx, macCalc, &outputSize));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish) != mf_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLMAC_STATUS_OK != mf_status) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED(compare_result, token,
                                         mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u,
                                                                                               mac,
                                                                                               macCalc,
                                                                                               mac_length),
                                                                mac, macCalc, mac_length));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (compare_result != MCUXCSSLMEMORY_STATUS_EQUAL) {
        status = PSA_ERROR_INVALID_SIGNATURE;
        goto cleanup;
    }

    status = PSA_SUCCESS;

cleanup:
    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

psa_status_t sgi_mac_abort(sgi_mac_operation_t *operation)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Clear operation ctx */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(token,
                                          mcuxClMemory_clear((uint8_t *) operation,
                                                             sizeof(sgi_mac_operation_t),
                                                             sizeof(sgi_mac_operation_t)));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    status = PSA_SUCCESS;

cleanup:
    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}
/** @} */ // end of psa_mac
