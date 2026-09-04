/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/** \file mcux_psa_pkc_utils.c
 *
 * This file contains the definitions of the entry points associated
 * with common utility functions utilized by the PKC PSA port driver.
 */

#include "mcux_psa_pkc_utils.h"

/**
 * \brief Map PSA key attributes to PKC private key type
 *
 * Converts PSA ECC curve family and key size to the corresponding
 * PKC private key type identifier.
 *
 * \param[in]  attributes  PSA key attributes
 * \param[out] pkc_alg     PKC private key type
 *
 * \return PSA_SUCCESS on success
 * \return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 */
psa_status_t psa_to_pkc_asym_alg_priv(
    const psa_key_attributes_t *attributes,
    mcuxClKey_Type_t *pkc_alg)
{
    /* Validate input parameters */
    if (attributes == NULL || pkc_alg == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_status_t status         = PSA_SUCCESS;
    psa_key_type_t key_type     = psa_get_key_type(attributes);
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    size_t key_bits             = psa_get_key_bits(attributes);

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
            case 192:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp192r1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
            case 224:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp224r1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
            case 256:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp256r1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
            case 384:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp384r1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
            case 521:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp521r1_Priv;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
            case 256:
                *pkc_alg = mcuxClKey_Type_WeierECC_brainpoolP256r1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
            case 384:
                *pkc_alg = mcuxClKey_Type_WeierECC_brainpoolP384r1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
            case 512:
                *pkc_alg = mcuxClKey_Type_WeierECC_brainpoolP512r1_Priv;
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
            case 192:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp192k1_Priv;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
            case 256:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp256k1_Priv;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#endif /* defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES) */
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

/**
 * \brief Map PSA key attributes to PKC public key type
 *
 * Converts PSA ECC curve family and key size to the corresponding
 * PKC public key type identifier.
 *
 * \param[in]  attributes  PSA key attributes
 * \param[out] pkc_alg     PKC public key type
 *
 * \return PSA_SUCCESS on success
 * \return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 * \return PSA_ERROR_INVALID_ARGUMENT if parameters are NULL
 */
psa_status_t psa_to_pkc_asym_alg_pub(
    const psa_key_attributes_t *attributes,
    mcuxClKey_Type_t *pkc_alg)
{
    /* Validate input parameters */
    if (attributes == NULL || pkc_alg == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_status_t status         = PSA_SUCCESS;
    psa_key_type_t key_type     = psa_get_key_type(attributes);
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    size_t key_bits             = psa_get_key_bits(attributes);

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
            case 192:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp192r1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
            case 224:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp224r1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
            case 256:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp256r1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
            case 384:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp384r1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
            case 521:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp521r1_Pub;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
            case 256:
                *pkc_alg = mcuxClKey_Type_WeierECC_brainpoolP256r1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
            case 384:
                *pkc_alg = mcuxClKey_Type_WeierECC_brainpoolP384r1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
            case 512:
                *pkc_alg = mcuxClKey_Type_WeierECC_brainpoolP512r1_Pub;
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
            case 192:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp192k1_Pub;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
            case 256:
                *pkc_alg = mcuxClKey_Type_WeierECC_secp256k1_Pub;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#endif /* defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES) */
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

/**
 * \brief Get ECC key sizes based on PSA key attributes
 *
 * Retrieves the private and public key sizes in bytes for the
 * specified ECC curve.
 *
 * \param[in]  attributes     PSA key attributes
 * \param[out] priv_key_size  Private key size in bytes
 * \param[out] pub_key_size   Public key size in bytes
 *
 * \return PSA_SUCCESS on success
 * \return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 * \return PSA_ERROR_INVALID_ARGUMENT if parameters are NULL
 */
psa_status_t get_ecc_key_sizes(const psa_key_attributes_t *attributes,
                               size_t *priv_key_size,
                               size_t *pub_key_size)
{
    /* Validate input parameters */
    if (attributes == NULL || priv_key_size == NULL || pub_key_size == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_status_t status         = PSA_SUCCESS;
    psa_key_type_t key_type     = psa_get_key_type(attributes);
    psa_ecc_family_t ecc_family = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);
    size_t key_bits             = psa_get_key_bits(attributes);

    if (PSA_ECC_FAMILY_SECP_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
            case 192:
                *priv_key_size = MCUXCLECC_WEIERECC_SECP192R1_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_SECP192R1_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
            case 224:
                *priv_key_size = MCUXCLECC_WEIERECC_NIST_P224_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_NIST_P224_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
            case 256:
                *priv_key_size = MCUXCLECC_WEIERECC_NIST_P256_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_NIST_P256_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
            case 384:
                *priv_key_size = MCUXCLECC_WEIERECC_NIST_P384_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_NIST_P384_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
            case 521:
                *priv_key_size = MCUXCLECC_WEIERECC_NIST_P521_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_NIST_P521_SIZE_PUBLICKEY;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
    } else if (PSA_ECC_FAMILY_BRAINPOOL_P_R1 == ecc_family) {
        switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
            case 256:
                *priv_key_size = MCUXCLECC_WEIERECC_BRAINPOOLP256R1_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_BRAINPOOLP256R1_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
            case 384:
                *priv_key_size = MCUXCLECC_WEIERECC_BRAINPOOLP384R1_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_BRAINPOOLP384R1_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
            case 512:
                *priv_key_size = MCUXCLECC_WEIERECC_BRAINPOOLP512R1_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_BRAINPOOLP512R1_SIZE_PUBLICKEY;
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
            case 192:
                *priv_key_size = MCUXCLECC_WEIERECC_SECP192K1_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_SECP192K1_SIZE_PUBLICKEY;
                break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
            case 256:
                *priv_key_size = MCUXCLECC_WEIERECC_SECP256K1_SIZE_PRIVATEKEY;
                *pub_key_size  = MCUXCLECC_WEIERECC_SECP256K1_SIZE_PUBLICKEY;
                break;
#endif
            default:
                status = PSA_ERROR_NOT_SUPPORTED;
                break;
        }
#endif /* defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES) */
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}
/**
 * @brief Get the shared secret size based on key attributes
 *
 * @param[in]  attributes  PSA key attributes containing curve family and key bits
 * @param[out] secret_size Pointer to store the shared secret size in bytes
 *
 * @return PSA_SUCCESS on success
 * @return PSA_ERROR_NOT_SUPPORTED if curve is not supported
 * @return PSA_ERROR_INVALID_ARGUMENT if parameters are NULL
 */
psa_status_t psa_to_pkc_asym_shared_secret_size(const psa_key_attributes_t *attributes,
                                                size_t *secret_size)
{
    /* Validate input parameters */
    if (attributes == NULL || secret_size == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;
    psa_ecc_family_t family =
        (psa_ecc_family_t) PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes));
    size_t key_bits = psa_get_key_bits(attributes);

    switch (family) {
        case PSA_ECC_FAMILY_SECP_R1:
            switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_R1_192)
                case 192:
                    *secret_size = MCUXCLECC_WEIERECC_SECP192R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_224)
                case 224:
                    *secret_size = MCUXCLECC_WEIERECC_SECP224R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256)
                case 256:
                    *secret_size = MCUXCLECC_WEIERECC_SECP256R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384)
                case 384:
                    *secret_size = MCUXCLECC_WEIERECC_SECP384R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521)
                case 521:
                    *secret_size = MCUXCLECC_WEIERECC_SECP521R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
                default:
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
            }
            break;

        case PSA_ECC_FAMILY_BRAINPOOL_P_R1:
            switch (key_bits) {
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
                case 256:
                    *secret_size = MCUXCLECC_WEIERECC_BRAINPOOLP256R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
                case 384:
                    *secret_size = MCUXCLECC_WEIERECC_BRAINPOOLP384R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
                case 512:
                    *secret_size = MCUXCLECC_WEIERECC_BRAINPOOLP512R1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
                default:
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
            }
            break;

#if defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES)
        case PSA_ECC_FAMILY_SECP_K1:
            switch (key_bits) {
#if defined(PSA_WANT_ECC_SECP_K1_192)
                case 192:
                    *secret_size = MCUXCLECC_WEIERECC_SECP192K1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
#if defined(PSA_WANT_ECC_SECP_K1_256)
                case 256:
                    *secret_size = MCUXCLECC_WEIERECC_SECP256K1_SIZE_SHAREDSECRET;
                    status = PSA_SUCCESS;
                    break;
#endif
                default:
                    status = PSA_ERROR_NOT_SUPPORTED;
                    break;
            }
            break;
#endif /* defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES) */

        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }

    return status;
}
/** @} */ // end of psa_pkc_utils
