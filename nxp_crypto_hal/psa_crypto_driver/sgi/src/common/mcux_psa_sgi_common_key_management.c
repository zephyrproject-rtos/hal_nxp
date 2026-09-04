/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file  mcux_psa_sgi_common_key_management.c
 * @brief Implementation of common SGI key management utilities.
 *
 * Provides sgi_create_key_descriptor() which populates a mcuxClKey_Descriptor_t
 * from PSA key attributes. Shared between the transparent, opaque, and PKC PSA crypto drivers.
 */

#include "mcux_psa_sgi_common_key_management.h"
#include "mcux_psa_sgi_common_init.h"

#include <mcuxClKey.h>
#include <mcuxClKey_Types.h>
#include <mcuxClKey_Functions.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>
#include <mcuxClAes.h>
#include <mcuxClEcc.h>
#include <mcuxClHmac.h>
#include <mcuxClBuffer.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClEcc_Weier_Internal.h>

/* =========================================================================
 * Internal: map PSA ECC key pair type + bits to mcuxClKey_TypeDescriptor_t
 * ========================================================================= */

#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC)
static psa_status_t get_ecc_key_pair_type_descriptor(
    const psa_key_attributes_t *attributes,
    mcuxClKey_TypeDescriptor_t *out_type_desc)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    size_t key_bits = psa_get_key_bits(attributes);
    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
            case 192u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
            case 224u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
            case 256u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
            case 384u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
            case 521u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
            case 256u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
            case 384u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
            case 512u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#if defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES)
    } else if (PSA_ECC_FAMILY_SECP_K1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_K1_192)
            case 192u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
            case 256u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Priv;
                status = PSA_SUCCESS;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#endif /* MCUXCL_FEATURE_ECC_SECPK1_CURVES */
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}
#endif /* PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC */

/* =========================================================================
 * Internal: map PSA ECC public key type + bits to mcuxClKey_TypeDescriptor_t
 * ========================================================================= */

#if defined(PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY)
static psa_status_t get_ecc_public_key_type_descriptor(
    const psa_key_attributes_t *attributes,
    mcuxClKey_TypeDescriptor_t *out_type_desc)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    size_t key_bits = psa_get_key_bits(attributes);
    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
            case 192u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
            case 224u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
            case 256u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
            case 384u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
            case 521u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
            case 256u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
            case 384u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
            case 512u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#if defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES)
    } else if (PSA_ECC_FAMILY_SECP_K1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_K1_192)
            case 192u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
            case 256u:
                *out_type_desc = mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Pub;
                status = PSA_SUCCESS;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#endif /* MCUXCL_FEATURE_ECC_SECPK1_CURVES */
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}
#endif /* PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY */

/* =========================================================================
 * Internal: map PSA key type + size to mcuxClKey_TypeDescriptor_t
 * ========================================================================= */

static psa_status_t get_key_type_descriptor(
    const psa_key_attributes_t *attributes,
    size_t key_buffer_size,
    mcuxClKey_TypeDescriptor_t *out_type_desc)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
        case PSA_KEY_TYPE_AES:
            switch (key_buffer_size) {
                case 16u:
                    *out_type_desc = mcuxClKey_TypeDescriptor_Aes128;
                    status = PSA_SUCCESS;
                    break;
#if defined(MCUXCL_FEATURE_AES192)
                case 24u:
                    *out_type_desc = mcuxClKey_TypeDescriptor_Aes192;
                    status = PSA_SUCCESS;
                    break;
#endif /* MCUXCL_FEATURE_AES192 */
                case 32u:
                    *out_type_desc = mcuxClKey_TypeDescriptor_Aes256;
                    status = PSA_SUCCESS;
                    break;
                default:
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
            }
            break;
#endif /* PSA_WANT_KEY_TYPE_AES */

        case PSA_KEY_TYPE_RAW_DATA:
        {
            mcuxClKey_TypeDescriptor_t type = { 0u, (mcuxClKey_Size_t) key_buffer_size, NULL,
                                                NULL };
            *out_type_desc = type;
            status = PSA_SUCCESS;
        }
        break;

        case PSA_KEY_TYPE_HMAC:
        {
            /* The shared variable-length HMAC type descriptor carries a
             * default key size of 0. Copy it and record the actual key byte
             * length, otherwise consumers (e.g. mcuxClMac_compute for HMAC)
             * would operate on a zero-length key and produce an incorrect MAC. */
            *out_type_desc = mcuxClKey_TypeDescriptor_Hmac_variableLength;
            out_type_desc->size = (mcuxClKey_Size_t) key_buffer_size;
            status = PSA_SUCCESS;
        }
        break;

        default:
            /* Check if it's an ECC key pair */
            if (PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type)) {
#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC)
                status = get_ecc_key_pair_type_descriptor(attributes, out_type_desc);
#else
                status = PSA_ERROR_NOT_SUPPORTED;
#endif
            }
            /* Check if it's an ECC public key */
            else if (PSA_KEY_TYPE_IS_ECC_PUBLIC_KEY(key_type)) {
#if defined(PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY)
                status = get_ecc_public_key_type_descriptor(attributes, out_type_desc);
#else
                status = PSA_ERROR_NOT_SUPPORTED;
#endif
            } else {
                status = PSA_ERROR_NOT_SUPPORTED;
            }
            break;
    }

    return status;
}


/* =========================================================================
 * sgi_create_key_descriptor
 * ========================================================================= */

psa_status_t sgi_create_key_descriptor(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    mcuxClKey_Descriptor_t *out_key_descriptor)
{
    psa_status_t status;
    psa_key_location_t location;
    mcuxClKey_TypeDescriptor_t keyTypeDesc;

    if (out_key_descriptor == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Reject keys whose bit-length exceeds the PSA key-size ceiling. The PSA
     * core enforces "bits > PSA_MAX_KEY_BITS" from the value the driver import
     * entry reports */
    if (key_buffer_size > PSA_BITS_TO_BYTES(PSA_MAX_KEY_BITS)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    /* Configure key data pointers */
    mcuxClKey_setKeyData(out_key_descriptor, (uint8_t *) key_buffer);
    mcuxClKey_setKeyContainerSize(out_key_descriptor, (uint32_t) key_buffer_size);
    mcuxClKey_setKeyContainerUsedSize(out_key_descriptor, (uint32_t) key_buffer_size);
    mcuxClKey_setAuxData(out_key_descriptor, (void *) attributes);
    mcuxClKey_setLinkedData(out_key_descriptor, NULL);
    mcuxClKey_setParentKey(out_key_descriptor, NULL);

    /* Configure load state based on key location */
    if (PSA_KEY_LOCATION_LOCAL_STORAGE == location) {
        /* LOCAL_STORAGE: key material is directly accessible in memory */
        mcuxClKey_setLoadedKeyData(out_key_descriptor, (uint32_t *) key_buffer);
        mcuxClKey_setLoadedKeyLength(out_key_descriptor, (uint32_t) key_buffer_size);
        mcuxClKey_setLoadedKeySlot(out_key_descriptor, MCUXCLKEY_LOADOPTION_SLOT_INVALID);
        mcuxClKey_setLoadStatus(out_key_descriptor, MCUXCLKEY_LOADSTATUS_NOTLOADED);
    } else {
        /* Opaque location: key data pointers are set, but load is deferred.
         * The caller or oracle is responsible for loading into coprocessor. */
        mcuxClKey_setLoadedKeyData(out_key_descriptor, (uint32_t *) key_buffer);
        mcuxClKey_setLoadedKeyLength(out_key_descriptor, (uint32_t) key_buffer_size);
        mcuxClKey_setLoadedKeySlot(out_key_descriptor, MCUXCLKEY_LOADOPTION_SLOT_INVALID);
        mcuxClKey_setLoadStatus(out_key_descriptor, MCUXCLKEY_LOADSTATUS_NOTLOADED);
    }

    /* Map PSA key type to SGI key type descriptor */
    status = get_key_type_descriptor(attributes, key_buffer_size, &keyTypeDesc);
    if (PSA_SUCCESS != status) {
        return status;
    }

    mcuxClKey_setTypeDescriptor(out_key_descriptor, keyTypeDesc);
    mcuxClKey_setEncodingType(out_key_descriptor, keyTypeDesc.plainEncoding);

    return PSA_SUCCESS;
}

/* =========================================================================
 * Internal: resolve the Weierstrass domain-parameter descriptor for a curve.
 *
 * Maps the PSA ECC curve family and key size to the mcuxClEcc Weierstrass
 * domain-parameter descriptor provided by the ECC component. Only the
 * Weierstrass families (secp_r1, secp_k1, brainpool_p_r1) are handled;
 * anything else returns NULL.
 * ========================================================================= */

static const mcuxClEcc_Weier_DomainParams_t *sgi_get_weier_domain_params(
    psa_ecc_family_t ecc_family, size_t key_bits)
{
    const mcuxClEcc_Weier_DomainParams_t *pParams = NULL;

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
            case 192u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp192r1;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
            case 224u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp224r1;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
            case 256u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp256r1;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
            case 384u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp384r1;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
            case 521u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp521r1;
                break;
#endif
            default:
                pParams = NULL;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_160)
            case 160u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP160r1;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_192)
            case 192u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP192r1;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_224)
            case 224u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP224r1;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
            case 256u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP256r1;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_320)
            case 320u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP320r1;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
            case 384u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP384r1;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
            case 512u:
                pParams = &mcuxClEcc_Weier_DomainParams_brainpoolP512r1;
                break;
#endif
            default:
                pParams = NULL;
                break;
        }
#if defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES)
    } else if (PSA_ECC_FAMILY_SECP_K1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_K1_192)
            case 192u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp192k1;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_224)
            case 224u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp224k1;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
            case 256u:
                pParams = &mcuxClEcc_Weier_DomainParams_secp256k1;
                break;
#endif
            default:
                pParams = NULL;
                break;
        }
#endif /* MCUXCL_FEATURE_ECC_SECPK1_CURVES */
    } else {
        /* Unsupported ECC family; pParams stays NULL. */
    }

    return pParams;
}

/* =========================================================================
 * sgi_ecc_derive_public_key
 *
 * Derive Q = d * G on-chip via a secured scalar multiplication. This is the
 * single shared secure derivation used by both the opaque export path and the
 * transparent (PKC) export path.
 *
 * ========================================================================= */

psa_status_t sgi_ecc_derive_public_key(
    mcuxClSession_Handle_t session,
    const psa_key_attributes_t *attributes,
    const uint8_t *private_key,
    size_t private_key_size,
    uint8_t *out_public_key,
    size_t out_public_key_size,
    size_t *out_public_key_length)
{
    if ((NULL == session) || (NULL == attributes) || (NULL == private_key) ||
        (NULL == out_public_key) || (NULL == out_public_key_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_key_type_t key_type = psa_get_key_type(attributes);
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    size_t key_bits = psa_get_key_bits(attributes);

    const mcuxClEcc_Weier_DomainParams_t *pDomainParams =
        sgi_get_weier_domain_params(ecc_family, key_bits);
    if (NULL == pDomainParams) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    const uint32_t byteLenP = pDomainParams->common.byteLenP;
    const uint32_t byteLenN = pDomainParams->common.byteLenN;
    const size_t point_size = (size_t) byteLenP * 2u;

    if (out_public_key_size < point_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* The scalar length passed to the operation must not exceed byteLen(n). */
    size_t scalar_size = private_key_size;
    if (scalar_size > byteLenN) {
        scalar_size = byteLenN;
    }

    /* Extract the base point G (x || y) in big endian, as expected by the ECC
     * ScalarMult operation. The domain-parameter constants are stored little
     * endian, so reverse the byte order while copying. */
    ALIGNED uint8_t pG[2u * MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP];
    for (uint32_t i = 0u; i < byteLenP; i++) {
        pG[i]            = pDomainParams->common.pGx[byteLenP - i - 1u];
        pG[byteLenP + i] = pDomainParams->common.pGy[byteLenP - i - 1u];
    }

    /* Derive Q = d * G. The scalar is the private key; the point is the curve
     * base point G given as X||Y. The result is written as X||Y (no leading
     * 0x04) into out_public_key. */
    uint32_t derivedSize = 0u;

    MCUXCLBUFFER_INIT_RO(buffScalar, NULL, private_key, scalar_size);
    MCUXCLBUFFER_INIT_RO(buffPointG, NULL, pG, point_size);
    MCUXCLBUFFER_INIT(buffResult, NULL, out_public_key, point_size);

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(sm_status, sm_token,
        mcuxClEcc_ArithmeticOperation(
            session,
            mcuxClEcc_ArithmeticOperation_SecureScalarMult,
            (mcuxClEcc_Weier_DomainParams_t *) pDomainParams,
            buffScalar,
            (uint32_t) scalar_size,
            buffPointG,
            (uint32_t) point_size,
            buffResult,
            &derivedSize)
    );

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithmeticOperation) != sm_token) ||
        (MCUXCLECC_STATUS_OK != sm_status) || (point_size != derivedSize)) {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *out_public_key_length = point_size;

    return PSA_SUCCESS;
}
