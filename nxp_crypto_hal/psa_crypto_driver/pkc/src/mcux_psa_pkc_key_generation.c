/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_pkc_key_generation.c
 *
 * This file contains the implementation of the entry points associated to the
 * key generation (i.e. random generation and extraction of public keys) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */
#include "mcux_psa_pkc_key_generation.h"
#include "mcux_psa_sgi_common_key_management.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClEcc_Weier_Internal.h>

#define RSA_PUBLIC_EXP_BYTE_LENGTH (3u)
#define RSA_MAX_KEYSIZE MCUXCLKEY_SIZE_4096

/* Named constants for point formats */
#define ECC_POINT_FORMAT_UNCOMPRESSED 0x04u
#define ECC_POINT_FORMAT_COMPRESSED_EVEN 0x02u
#define ECC_POINT_FORMAT_COMPRESSED_ODD 0x03u

#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
static const uint8_t pubExp[RSA_PUBLIC_EXP_BYTE_LENGTH] __attribute__((aligned(4))) = {
    0x01u, 0x00u, 0x01u
};

/* Helper function to encode ASN.1 DER length */
static size_t der_encode_length(uint8_t *buffer, size_t length)
{
    if (buffer == NULL) {
        return 0;
    }

    if (length < 128u) { // short form
        buffer[0] = (uint8_t) length;
        return 1u;
    } else { // long form
        uint8_t h3_byte = (uint8_t) ((length & 0xFF000000u) >> 24u);
        uint8_t h2_byte = (uint8_t) ((length & 0xFF0000u) >> 16u);
        uint8_t h1_byte = (uint8_t) ((length & 0xFF00u) >> 8u);
        uint8_t h0_byte = (uint8_t) (length & 0xFFu);

        if (h3_byte != 0u) {
            buffer[0] = 0x84u;
            buffer[1] = h3_byte;
            buffer[2] = h2_byte;
            buffer[3] = h1_byte;
            buffer[4] = h0_byte;
            return 5u;
        } else if (h2_byte != 0u) {
            buffer[0] = 0x83u;
            buffer[1] = h2_byte;
            buffer[2] = h1_byte;
            buffer[3] = h0_byte;
            return 4u;
        } else if (h1_byte != 0u) {
            buffer[0] = 0x82u;
            buffer[1] = h1_byte;
            buffer[2] = h0_byte;
            return 3u;
        } else {
            buffer[0] = 0x81u;
            buffer[1] = h0_byte;
            return 2u;
        }
    }
}

/* Helper function to encode ASN.1 DER integer */
static size_t der_encode_integer(uint8_t *buffer, const uint8_t *value, size_t value_len)
{
    if (buffer == NULL || value == NULL || value_len == 0u) {
        return 0;
    }

    size_t offset = 0;
    const uint8_t *val_ptr = value;
    size_t len = value_len;

    /* Skip leading zeros, but keep at least one byte */
    /* Also ensure we don't skip a zero that prevents negative interpretation */
    while (len > 1u && val_ptr[0] == 0x00u && (val_ptr[1] & 0x80u) == 0u) {
        val_ptr++;
        len--;
    }

    /* Check if padding byte needed (MSB set means negative in DER) */
    bool needs_padding = (val_ptr[0] & 0x80u) != 0u;
    size_t total_len = len + (needs_padding ? 1u : 0u);

    /* INTEGER tag */
    buffer[offset++] = 0x02u;

    /* Length */
    offset += der_encode_length(&buffer[offset], total_len);

    /* Padding byte if needed */
    if (needs_padding) {
        buffer[offset++] = 0x00u;
    }

    /* Value */
    (void) memcpy(&buffer[offset], val_ptr, len);
    if (mcux_psa_add_size_t_wrapcheck(offset, len))
    {
        return 0;
    }
    offset += len;

    return offset;
}

static psa_status_t get_rsa_key_types(size_t key_bits,
                                      mcuxClKey_Type_t *priv_type,
                                      mcuxClKey_Type_t *pub_type,
                                      size_t *priv_data_size)
{
    psa_status_t psa_status = PSA_ERROR_GENERIC_ERROR;

    switch (key_bits) {
        case MCUXCLKEY_SIZE_2048:
            *priv_type = mcuxClKey_Type_Rsa_PrivatePlain_2048;
            *pub_type = mcuxClKey_Type_Rsa_Public_2048;
            *priv_data_size = MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_2048_SIZE;
            psa_status = PSA_SUCCESS;
            break;
        case MCUXCLKEY_SIZE_3072:
            *priv_type = mcuxClKey_Type_Rsa_PrivatePlain_3072;
            *pub_type = mcuxClKey_Type_Rsa_Public_3072;
            *priv_data_size = MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_3072_SIZE;
            psa_status = PSA_SUCCESS;
            break;
        case MCUXCLKEY_SIZE_4096:
            *priv_type = mcuxClKey_Type_Rsa_PrivatePlain_4096;
            *pub_type = mcuxClKey_Type_Rsa_Public_4096;
            *priv_data_size = MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_4096_SIZE;
            psa_status = PSA_SUCCESS;
            break;
        default:
            psa_status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }

    return psa_status;
}

static psa_status_t pkc_internal_generate_rsa_key(const psa_key_attributes_t *attributes,
                                                  uint8_t *key_buffer,
                                                  size_t key_buffer_size,
                                                  size_t *key_buffer_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t key_bits;
    size_t key_bytes;
    mcuxClKey_Type_t key_type_priv;
    mcuxClKey_Type_t key_type_pub;
    size_t privKeyDataSize;

    key_bits = psa_get_key_bits(attributes);
    /* Validate key size BEFORE any session work */
    if ((key_bits != MCUXCLKEY_SIZE_2048) &&
        (key_bits != MCUXCLKEY_SIZE_3072) &&
        (key_bits != MCUXCLKEY_SIZE_4096)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }
    key_bytes = PSA_BITS_TO_BYTES(key_bits);

    status = get_rsa_key_types(key_bits, &key_type_priv, &key_type_pub, &privKeyDataSize);
    if (PSA_SUCCESS != status) {
        return status;
    }

    /* Setup one session to be used by all functions called */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE,
                                                  MCUXCLRSA_KEYGENERATION_PLAIN_4096_WAPKC_SIZE);

    /* Initialize the RNG context and initialize the PRNG */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(session,
                                              MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
                                              mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3);

    /* Allocate space for and initialize RSA private key handle */
    uint32_t privKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
    mcuxClKey_Handle_t privKey = (mcuxClKey_Handle_t) &privKeyDesc;

    /* Allocate private key data with correct size */
    ALIGNED uint8_t pPrivKeyData[MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_4096_SIZE];

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ki_priv_status, ki_priv_token, mcuxClKey_init(
                                         session,
                                         privKey,
                                         key_type_priv,
                                         pPrivKeyData,
                                         privKeyDataSize
                                         ));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != ki_priv_token) ||
        (MCUXCLKEY_STATUS_OK != ki_priv_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Allocate space for and initialize RSA public key handle */
    uint32_t pubKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
    mcuxClKey_Handle_t pubKey = (mcuxClKey_Handle_t) &pubKeyDesc;

    ALIGNED uint8_t pPubKeyData[MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_SIZE(512, 3)];
    size_t pubKeyDataSize = MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_SIZE(key_bytes, sizeof(pubExp));

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ki_pub_status, ki_pub_token, mcuxClKey_init(
                                         session,
                                         pubKey,
                                         key_type_pub,
                                         pPubKeyData,
                                         pubKeyDataSize
                                         ));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != ki_pub_token) ||
        (MCUXCLKEY_STATUS_OK != ki_pub_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Setup RSA key generation mode */
    ALIGNED uint8_t keyGenModeBytes[MCUXCLRSA_KEYGEN_MODE_SIZE];
    mcuxClKey_GenerationDescriptor_t *pKeyGeneration_RSA_Mode =
        (mcuxClKey_GenerationDescriptor_t *) keyGenModeBytes;

    mcuxClRsa_KeyGeneration_ModeConstructor(
        pKeyGeneration_RSA_Mode,
        pubExp,
        sizeof(pubExp)
        );

    /* Key pair generation */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(kgp_status, kgp_token, mcuxClKey_generate_keypair(
                                         session,
                                         pKeyGeneration_RSA_Mode,
                                         privKey,
                                         pubKey
                                         ));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_generate_keypair) != kgp_token) ||
        (MCUXCLKEY_STATUS_OK != kgp_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Export the generated key to ASN.1 DER format */
    mcuxClRsa_KeyData_Plain_t *privKeyDataStruct = (mcuxClRsa_KeyData_Plain_t *) pPrivKeyData;

    /* Get modulus and private exponent */
    uint8_t *pModulus = privKeyDataStruct->modulus.pKeyEntryData;
    uint32_t modulusLen = privKeyDataStruct->modulus.keyEntryLength;
    uint8_t *pPrivExp = privKeyDataStruct->exponent.pKeyEntryData;
    uint32_t privExpLen = privKeyDataStruct->exponent.keyEntryLength;

    /* Encode to ASN.1 DER format (PKCS#1 RSAPrivateKey) */
    size_t der_offset = 0;
    /* Reserve space for SEQUENCE header */
    static const uint8_t zero = 0x00u;
    const struct { const uint8_t *val; size_t len; } fields[] = {
        { pModulus, modulusLen },    /* n     */
        { pubExp,   sizeof(pubExp) },/* e     */
        { pPrivExp, privExpLen },    /* d     */
        { &zero,    1u },            /* p     */
        { &zero,    1u },            /* q     */
        { &zero,    1u },            /* dp    */
        { &zero,    1u },            /* dq    */
        { &zero,    1u },            /* qInv  */
    };
    size_t encoded_size;
    /* Reserve SEQUENCE header + version (0). required (checked above) proves
       the buffer holds all of this, so der_offset stays <= key_buffer_size. */
    size_t seq_start = der_offset;
    der_offset += 10u;               /* Reserve max header size*/
    key_buffer[der_offset++] = 0x02; /* INTEGER tag */
    key_buffer[der_offset++] = 0x01; /* length */
    key_buffer[der_offset++] = 0x00; /* version 0 */

    for (size_t i = 0u; i < (sizeof(fields) / sizeof(fields[0])); i++) {
        if(der_offset > key_buffer_size)
        {
            status = PSA_ERROR_BUFFER_TOO_SMALL;
            goto exit;
        }
        encoded_size = der_encode_integer(&key_buffer[der_offset],
                                         fields[i].val, fields[i].len);
        if (mcux_psa_add_size_t_wrapcheck(der_offset, encoded_size))
        {
            status = PSA_ERROR_CORRUPTION_DETECTED;
            goto exit;
        }
        der_offset += encoded_size;
    }
    if (mcux_psa_sub_size_t_wrapcheck(der_offset, seq_start + 10u))
    {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto exit;
    }
    size_t content_len = der_offset - seq_start - 10u;

    /* Write SEQUENCE header */
    size_t header_pos = seq_start;
    key_buffer[header_pos++] = 0x30; /* SEQUENCE tag */
    size_t len_size = der_encode_length(&key_buffer[header_pos], content_len);
    /* Shift content if needed */
    size_t actual_header_size = 1u + len_size;
    if (actual_header_size < 10u) {
        size_t shift = 10u - actual_header_size;
        (void) memmove(&key_buffer[seq_start + actual_header_size],
                       &key_buffer[seq_start + 10u],
                       content_len);
        der_offset -= shift;
    }

    /* Check buffer size */
    if (der_offset > key_buffer_size) {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
        goto exit;
    }

    *key_buffer_length = der_offset;
    status = PSA_SUCCESS;

exit:
    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) ||
        (MCUXCLSESSION_STATUS_OK != result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return status;
}
#endif /* PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE */

static psa_status_t pkc_internal_generate_ecp_key(const psa_key_attributes_t *attributes,
                                                  uint8_t *key_buffer,
                                                  size_t key_buffer_size,
                                                  size_t *key_buffer_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    mcuxClKey_Type_t key_type_priv = { NULL };
    mcuxClKey_Type_t key_type_pub = { NULL };
    size_t priv_key_size = 0;
    size_t pub_key_size = 0;

    /* Get mcuxCl key types BEFORE session setup */
    status = psa_to_pkc_asym_alg_priv(attributes, &key_type_priv);
    if (PSA_SUCCESS != status) {
        return status;
    }

    status = psa_to_pkc_asym_alg_pub(attributes, &key_type_pub);
    if (PSA_SUCCESS != status) {
        return status;
    }

    /* Get actual key sizes for this curve */
    status = get_ecc_key_sizes(attributes, &priv_key_size, &pub_key_size);
    if (PSA_SUCCESS != status) {
        return status;
    }

    /* Check buffer size */
    if (key_buffer_size < priv_key_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Setup one session to be used by all functions called */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLKEY_GENERATEKEYPAIR_WEIERECC_WACPU_SIZE,
                                                  MCUXCLKEY_GENERATEKEYPAIR_WEIERECC_WAPKC_SIZE_640);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Initialize the RNG context and initialize the PRNG */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(session,
                                              MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
                                              mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3);

    /* Allocate private key descriptor and data buffer */
    uint32_t privKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
    mcuxClKey_Handle_t privKey = (mcuxClKey_Handle_t) &privKeyDesc;
    ALIGNED uint8_t pPrivKeyData[MCUXCLECC_WEIERECC_MAX_SIZE_PRIVATEKEY];

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ki_priv_status, ki_priv_token, mcuxClKey_init(
                                         session,
                                         privKey,
                                         key_type_priv,
                                         pPrivKeyData,
                                         priv_key_size));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != ki_priv_token) ||
        (MCUXCLKEY_STATUS_OK != ki_priv_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Allocate public key descriptor and data buffer */
    uint32_t pubKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
    mcuxClKey_Handle_t pubKey = (mcuxClKey_Handle_t) &pubKeyDesc;
    ALIGNED uint8_t pPubKeyData[MCUXCLECC_WEIERECC_MAX_SIZE_PUBLICKEY];

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ki_pub_status, ki_pub_token, mcuxClKey_init(
                                         session,
                                         pubKey,
                                         key_type_pub,
                                         pPubKeyData,
                                         pub_key_size));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != ki_pub_token) ||
        (MCUXCLKEY_STATUS_OK != ki_pub_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Generate key pair */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(kgp_status, kgp_token, mcuxClKey_generate_keypair(
                                         session,
                                         mcuxClKey_Generation_ECDSA,
                                         privKey,
                                         pubKey));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_generate_keypair) != kgp_token) ||
        (MCUXCLKEY_STATUS_OK != kgp_status)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Copy private key to output buffer */
    (void) memcpy(key_buffer, pPrivKeyData, priv_key_size);
    *key_buffer_length = priv_key_size;

    status = PSA_SUCCESS;

exit:
    /* Clean up session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) ||
        (MCUXCLSESSION_STATUS_OK != result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_CORRUPTION_DETECTED;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return status;
}

psa_status_t pkc_generate_key(const psa_key_attributes_t *attributes,
                              uint8_t *key_buffer, size_t key_buffer_size,
                              size_t *key_buffer_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t type;

    /* Validate parameters BEFORE dereferencing attributes or acquiring mutex */
    if (NULL == attributes || NULL == key_buffer ||
        NULL == key_buffer_length || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    type = psa_get_key_type(attributes);

    /* Acquire mutex */
    if (mcux_mutex_lock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Allocate storage for a key to be generated */
    mcuxClKey_Descriptor_t key = { 0u };
    /* Initialize the key container */
    mcuxClKey_setKeyData(&key, (uint8_t *) key_buffer);
    mcuxClKey_setKeyContainerSize(&key, (uint32_t) key_buffer_size);
    mcuxClKey_setAuxData(&key, (void *) attributes);

    /* Local storage - setup loaded key with buffer from caller */
    mcuxClKey_setLoadedKeyData(&key, (uint32_t *) key_buffer);
    mcuxClKey_setLoadedKeyLength(&key, (uint32_t) key_buffer_size);
    mcuxClKey_setLoadStatus(&key, MCUXCLKEY_LOADSTATUS_NOTLOADED);

    if (PSA_KEY_TYPE_IS_UNSTRUCTURED(type)) {
        size_t estimate_bits = 0u;
        status = sgi_get_entropy(0u,
                                 &estimate_bits,
                                 mcuxClKey_getLoadedKeyData(&key),
                                 mcuxClKey_getLoadedKeyLength(&key));
        if (status != PSA_SUCCESS) {
            goto exit;
        }
        *key_buffer_length = mcuxClKey_getLoadedKeyLength(&key);
#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
    } else if (type == PSA_KEY_TYPE_RSA_KEY_PAIR) {
        status = pkc_internal_generate_rsa_key(attributes,
                                               mcuxClKey_getLoadedKeyData(&key),
                                               mcuxClKey_getLoadedKeyLength(&key),
                                               key_buffer_length);
        if (status != PSA_SUCCESS) {
            goto exit;
        }
#endif /* PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE */
    } else if (PSA_KEY_TYPE_IS_ECC(type) && PSA_KEY_TYPE_IS_KEY_PAIR(type)) {
        status = pkc_internal_generate_ecp_key(attributes,
                                               mcuxClKey_getLoadedKeyData(&key),
                                               mcuxClKey_getLoadedKeyLength(&key),
                                               key_buffer_length);
        if (status != PSA_SUCCESS) {
            goto exit;
        }
    } else {
        (void) key_buffer_length;
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }

exit:
    if (mcux_mutex_unlock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t pkc_key_agreement(const psa_key_attributes_t *attributes,
                               const uint8_t *key_buffer,
                               size_t key_buffer_size,
                               psa_algorithm_t alg,
                               const uint8_t *peer_key,
                               size_t peer_key_length,
                               uint8_t *shared_secret,
                               size_t shared_secret_size,
                               size_t *shared_secret_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t bits             = psa_get_key_bits(attributes);
    psa_ecc_family_t curve_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);

    /* Validate all input parameters BEFORE acquiring mutex */
    if (key_buffer == NULL || peer_key == NULL ||
        shared_secret == NULL || shared_secret_length == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check if algorithm is ECDH */
    if (!PSA_ALG_IS_ECDH(alg)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (!PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check if curve is supported type */
    if ((curve_family != PSA_ECC_FAMILY_SECP_R1) &&
        (curve_family != PSA_ECC_FAMILY_SECP_K1) &&
        (curve_family != PSA_ECC_FAMILY_BRAINPOOL_P_R1)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Check whether the peer key is valid for the given private key. */
    if (PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(bits) != peer_key_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check peer key format */
    if (peer_key[0] == ECC_POINT_FORMAT_UNCOMPRESSED) {
        /* format == uncompressed - OK */
    } else if ((peer_key[0] == ECC_POINT_FORMAT_COMPRESSED_EVEN) ||
               (peer_key[0] == ECC_POINT_FORMAT_COMPRESSED_ODD)) {
        /* format == compressed */
        return PSA_ERROR_NOT_SUPPORTED;
    } else {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Acquire mutex */
    if (mcux_mutex_lock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLKEY_AGREEMENT_ECDH_WACPU_SIZE,
                                                  MCUXCLKEY_AGREEMENT_ECDH_WAPKC_SIZE_640);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Create private key descriptor using the common key management utility */
    mcuxClKey_Descriptor_t privKeyDesc;
    status = sgi_create_key_descriptor(attributes, key_buffer, key_buffer_size, &privKeyDesc);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    /* Create public key descriptor for peer key using the common utility.
     * Skip the leading byte (0x04) indicating uncompressed format. */
    const uint8_t *pOtherPublic = peer_key + 1u;
    size_t peer_pub_data_size = peer_key_length - 1u;

    psa_key_attributes_t pub_attributes = *attributes;
    psa_set_key_type(&pub_attributes, PSA_KEY_TYPE_ECC_PUBLIC_KEY(curve_family));

    mcuxClKey_Descriptor_t peerPubKeyDesc;
    status = sgi_create_key_descriptor(&pub_attributes,
                                       pOtherPublic,
                                       peer_pub_data_size,
                                       &peerPubKeyDesc);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    /* Perform ECDH key agreement */
    uint32_t outputLength = 0u;
    uint32_t numberOfInputs = 0u;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(keyagreement_result, keyagreement_token,
                                     mcuxClKey_agreement(session,
                                                         mcuxClKey_Agreement_ECDH,
                                                         (mcuxClKey_Handle_t) &privKeyDesc,
                                                         (mcuxClKey_Handle_t) &peerPubKeyDesc,
                                                         NULL,
                                                         numberOfInputs,
                                                         shared_secret,
                                                         &outputLength));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_agreement) != keyagreement_token) ||
        (MCUXCLKEY_STATUS_OK != keyagreement_result)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Verify output size */
    size_t expected_shared_secret = 0u;
    status = psa_to_pkc_asym_shared_secret_size(attributes, &expected_shared_secret);

    if (outputLength != expected_shared_secret ||
        outputLength > shared_secret_size) {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
        goto exit;
    }

    *shared_secret_length = outputLength;
    status = PSA_SUCCESS;

exit:
    /* Cleanup session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(session_cleanup_result, session_cleanup_token,
                                     mcuxClSession_cleanup(session));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != session_cleanup_token) ||
        (MCUXCLSESSION_STATUS_OK != session_cleanup_result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(session_destroy_result, session_destroy_token,
                                     mcuxClSession_destroy(session));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != session_destroy_token) ||
        (MCUXCLSESSION_STATUS_OK != session_destroy_result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_HARDWARE_FAILURE;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if (mcux_mutex_unlock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t pkc_internal_export_ecp_public_key(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    uint8_t *data,
    size_t data_size,
    size_t *data_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Standard private-scalar length for the curve; sgi_ecc_derive_public_key
     * clamps it to byteLen(n) internally. */
    size_t private_key_size = PSA_BITS_TO_BYTES(psa_get_key_bits(attributes));

    /* Raw derived point X||Y (no leading tag). The largest supported coordinate
     * pair is secp521r1 (2 * 66 bytes); one extra byte holds the 0x04 tag. */
    uint8_t raw_point[2u * MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP] = { 0u };
    size_t raw_point_length = 0u;

    /* Setup one session to be used by all functions called */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLECC_ARITHMETICOPERATION_SECURESCALARMULT_WACPU_SIZE,
                                                  MCUXCLECC_ARITHMETICOPERATION_SECURESCALARMULT_WAPKC_SIZE_640);

    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);

    /* Derive Q = d*G on-chip using the single shared secure helper. It resolves
     * the curve from the attributes, extracts the base point G, and performs the
     * scalar multiplication, returning the raw X||Y point. */
    status = sgi_ecc_derive_public_key(session,
                                       attributes,
                                       key_buffer,
                                       private_key_size,
                                       raw_point,
                                       sizeof(raw_point),
                                       &raw_point_length);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    if (0u == raw_point_length) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* Prepend the SEC1 uncompressed-format tag: 0x04 || X || Y. */
    if (data_size < (raw_point_length + 1u)) {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
        goto exit;
    }

    data[0] = ECC_POINT_FORMAT_UNCOMPRESSED;
    (void) memcpy(&data[1], raw_point, raw_point_length);
    *data_length = raw_point_length + 1u;
    status = PSA_SUCCESS;

exit:
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token,
                                     mcuxClSession_cleanup(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token) ||
        (MCUXCLSESSION_STATUS_OK != cleanup_result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(destroy_result, destroy_token,
                                     mcuxClSession_destroy(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != destroy_token) ||
        (MCUXCLSESSION_STATUS_OK != destroy_result)) {
        if (PSA_SUCCESS == status) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return status;
}

psa_status_t pkc_transparent_export_public_key(const psa_key_attributes_t *attributes,
                                   const uint8_t *key_buffer,
                                   size_t key_buffer_size,
                                   uint8_t *data,
                                   size_t data_size,
                                   size_t *data_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t type;

    /* Validate parameters BEFORE acquiring mutex */
    if (NULL == attributes || NULL == key_buffer || 0u == key_buffer_size ||
        NULL == data || 0u == data_size || NULL == data_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    type = psa_get_key_type(attributes);

    /* Only ECC keys are supported by this driver */
    if (!PSA_KEY_TYPE_IS_ECC(type)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* If the key is already a public key, the export is a straight copy.
     * A stored ECC public key must be in the SEC1 uncompressed point format
     * (0x04 || X || Y); reject any other/compressed encoding to stay
     * consistent with the verify path that assumes the leading 0x04 tag. */
    if (PSA_KEY_TYPE_IS_PUBLIC_KEY(type)) {
        if (key_buffer[0] != ECC_POINT_FORMAT_UNCOMPRESSED) {
            return PSA_ERROR_NOT_SUPPORTED;
        }
        if (key_buffer_size > data_size) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
        (void) memcpy(data, key_buffer, key_buffer_size);
        *data_length = key_buffer_size;
        return PSA_SUCCESS;
    }

    /* Otherwise it must be a key pair from which we derive the public part */
    if (!PSA_KEY_TYPE_IS_KEY_PAIR(type)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Acquire mutex */
    if (mcux_mutex_lock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = pkc_internal_export_ecp_public_key(attributes,
                                                key_buffer,
                                                data,
                                                data_size,
                                                data_length);

    if (mcux_mutex_unlock(&pkc_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
/** @} */ // end of psa_key_generation