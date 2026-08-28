/*
 * Copyright 2022-2023, 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_key_generation.c
 *
 * This file contains the implementation of the entry points associated to the
 * key generation (i.e. random generation and extraction of public keys) as
 * described by the PSA Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_init.h" /* ELE Crypto port layer */
#include "mcux_psa_s2xx_opaque_key_generation.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

/* For exporting public keys, we will directly use the internal export wrapper,
 * so that we don't call the public psa_export_public_key() API.
 */
extern psa_status_t psa_export_public_key_internal(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    uint8_t *data,
    size_t data_size,
    size_t *data_length);

static bool ele_s2xx_key_is_likely_non_el2go_blob(psa_key_type_t key_type,
                                                  size_t key_bits,
                                                  size_t data_length)
{
    /* IF ECC keypair, we need a different check */
    if (true == PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type))
    {
        size_t keypair_size = ele_s2xx_get_ecc_keypair_size(key_bits);
        /* CERT INT30-C: guard addition before comparison */
        if (true == mcux_psa_add_size_t_wrapcheck(keypair_size, (size_t)S200_BLOB_OVERHEAD))
        {
            return false;
        }
        return ((keypair_size + S200_BLOB_OVERHEAD) == data_length);
    }
    else
    {
        size_t export_size = PSA_EXPORT_KEY_OUTPUT_SIZE(key_type, key_bits);
        /* CERT INT30-C: guard addition before comparison */
        if (true == mcux_psa_add_size_t_wrapcheck(export_size, (size_t)S200_BLOB_OVERHEAD))
        {
            return false;
        }
        return ((export_size + S200_BLOB_OVERHEAD) == data_length);
    }
}

static bool ele_s2xx_key_is_likely_transparent(psa_key_type_t key_type,
                                               size_t key_bits,
                                               size_t data_length)
{
    return ((PSA_EXPORT_KEY_OUTPUT_SIZE(key_type, key_bits)) == data_length);
}

static psa_status_t transform_plain_key_to_elke_blob(const psa_key_attributes_t *attributes,
                                                     const uint8_t *plain_data,
                                                     size_t plain_data_length,
                                                     uint8_t *opaque_key_buffer,
                                                     size_t opaque_key_buffer_size,
                                                     size_t *opaque_key_buffer_length,
                                                     size_t *bits,
                                                     sss_sscp_object_t *sssKey)
{
    psa_status_t status              = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_key_property_t keyprops = {0};
    sss_key_part_t key_part          = {0};
    sss_cipher_type_t cipher_type    = {0};
    size_t allocation_size           = 0u;
    size_t key_bits                  = psa_get_key_bits(attributes);

    /* Array large enough for a full SECP521 keypair with leading 0x04 Byte */
    uint8_t keypair_data[199]       = {0u};
    const size_t keypair_data_size  = sizeof(keypair_data);
    size_t public_key_length        = 0u;
    size_t public_key_size          = 0u;
    size_t private_key_offset       = 0u;
    size_t final_blob_size          = 0u;

    (void)bits; /* Unused */

    do
    {
        status = ele_s2xx_get_algo_keyprop(attributes, &keyprops,
                                           &key_part, &cipher_type,
                                           &allocation_size);
        if (PSA_SUCCESS != status)
        {
            break;
        }

        if (kSSS_KeyPart_Pair == key_part)
        {
            /* Transparent PSA is giving us only the private part. But we want
             * opaque ECC keypairs as _keypairs_, so we must extract the public
             * key.
             */

            if (plain_data_length != PSA_BITS_TO_BYTES(key_bits))
            {
                status = PSA_ERROR_INVALID_ARGUMENT;
                break;
            }

            public_key_size = keypair_data_size - plain_data_length;

#if defined(ELE200_EXTENDED_FEATURES)
            if (is_fw_loaded() == PSA_SUCCESS)
            {
                /* FW is loaded, so we have the accelerated pubkey export API */

                private_key_offset = ele_s2xx_get_ecc_public_key_size(key_bits);
                (void)memcpy(&keypair_data[private_key_offset], plain_data,
                             plain_data_length);

                /* Set only the private part */
                status = ele_s2xx_set_key(sssKey, S200_KEY_ID_RANDOM,
                                          &keypair_data[private_key_offset],
                                          plain_data_length,
                                          kSSS_KeyPart_Private, cipher_type,
                                          keyprops, allocation_size, key_bits);
                if (PSA_SUCCESS != status)
                {
                    break;
                }

                /* Utilize HW acceleration to retrieve public part */
                status = ele_s2xx_get_ecc_public_key_from_private(sssKey,
                                                                  keypair_data,
                                                                  public_key_size,
                                                                  &public_key_length,
                                                                  NULL);
                if (PSA_SUCCESS != status)
                {
                    break;
                }

                /* Scrap the private key and replace it with the full keypair */
                (void)ele_s2xx_delete_key(sssKey);
                status = ele_s2xx_set_key(sssKey, S200_KEY_ID_RANDOM, keypair_data,
                                          ele_s2xx_get_ecc_keypair_size(key_bits),
                                          key_part, cipher_type, keyprops,
                                          allocation_size, key_bits);
            }
            else
#endif
            {
                /* FW is not loaded, so we defer back to the SW implementation.
                 *
                 * Our goal is to arrange the full keypair as a continuous array
                 * in the following format: [public_x, public_y, private],
                 * so that we can set the pair in the S200 and export as a blob.
                 */

                private_key_offset = ele_s2xx_get_ecc_public_key_size(key_bits) + 1u; /* +1 for the leading 0x04 */

                (void)memcpy(&keypair_data[private_key_offset], plain_data,
                             PSA_BITS_TO_BYTES(key_bits));

                if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
                {
                    return PSA_ERROR_SERVICE_FAILURE;
                }
                status = psa_export_public_key_internal(attributes,
                                                        plain_data,
                                                        plain_data_length,
                                                        keypair_data,
                                                        public_key_size,
                                                        &public_key_length);
                if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
                {
                    return PSA_ERROR_SERVICE_FAILURE;
                }

                if (PSA_SUCCESS != status)
                {
                    break;
                }

                status = ele_s2xx_set_key(sssKey, S200_KEY_ID_RANDOM,
                                          keypair_data + 1u,
                                          ele_s2xx_get_ecc_keypair_size(key_bits),
                                          key_part, cipher_type, keyprops,
                                          allocation_size, key_bits);
            }

            final_blob_size = ele_s2xx_get_ecc_keypair_size(key_bits) + S200_BLOB_OVERHEAD;
        }
        else
        {
            if (true == mcux_psa_add_size_t_wrapcheck(plain_data_length,
                                                      S200_BLOB_OVERHEAD))
            {
                status = PSA_ERROR_INVALID_ARGUMENT;
                break;
            }

            final_blob_size = plain_data_length + S200_BLOB_OVERHEAD;
            status          = ele_s2xx_set_key(sssKey, S200_KEY_ID_RANDOM,
                                               plain_data, plain_data_length,
                                               key_part, cipher_type, keyprops,
                                               allocation_size, key_bits);
        }
        if (PSA_SUCCESS != status)
        {
            break;
        }

        /* Prohibit plain R/W after plain-writing to the slot */
        keyprops = kSSS_KeyProp_NoPlainRead | kSSS_KeyProp_NoPlainWrite;
        if (sss_sscp_key_object_set_properties(sssKey, (uint32_t)keyprops) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_HARDWARE_FAILURE;
            break;
        }

        if (opaque_key_buffer_size < final_blob_size)
        {
            status = PSA_ERROR_BUFFER_TOO_SMALL;
            break;
        }

        status = ele_s2xx_export_key(attributes, opaque_key_buffer,
                                     opaque_key_buffer_size,
                                     opaque_key_buffer_length, sssKey);
    } while (false);

    (void)memset(keypair_data, 0, sizeof(keypair_data));
    return status;
}

psa_status_t ele_s2xx_opaque_import_key(const psa_key_attributes_t *attributes,
    const uint8_t *data, size_t data_length, uint8_t *key_buffer,
    size_t key_buffer_size, size_t *key_buffer_length, size_t *bits)
{
    psa_status_t status         = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey    = {0};
    sss_sscp_tunnel_t tunnelCtx = {0};
    uint32_t resultState        = 0u;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    size_t key_bits             = psa_get_key_bits(attributes);
    psa_key_type_t key_type     = psa_get_key_type(attributes);

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }


    if (true == (MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location)))
    {
        /* Validate blob in software and import to let S200 validate too */
        status = ele_s2xx_import_key(attributes, data, data_length, &sssKey);
        if (PSA_SUCCESS != status)
        {
            goto exit;
        }

        /* Store the blob as-is in the PSA keystore */
        if (key_buffer_size < data_length)
        {
            status = PSA_ERROR_BUFFER_TOO_SMALL;
            goto exit;
        }

        (void)memcpy(key_buffer, data, data_length);
        *key_buffer_length = data_length;

        status = PSA_SUCCESS;
    }
    else if (true == (MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location)))
    {
        if (true == ele_s2xx_key_is_likely_non_el2go_blob(key_type, key_bits,
                                                          data_length))
        {
            /* We likely received a blob; use the import API to validate
             * the blob and enforce no plain read/write flags.
             */
            status = ele_s2xx_import_key(attributes, data, data_length,
                                         &sssKey);
            if (PSA_SUCCESS != status)
            {
                goto exit;
            }

            if (key_buffer_size < data_length)
            {
                status = PSA_ERROR_BUFFER_TOO_SMALL;
                goto exit;
            }

            /* Export the blob to burn in the flags into the PSA-stored
             * blob itself.
             */
            status = ele_s2xx_export_key(attributes, key_buffer,
                                         key_buffer_size, key_buffer_length,
                                         &sssKey);
        }
        else if (true == ele_s2xx_key_is_likely_transparent(key_type, key_bits,
                                                            data_length))
        {
            /* We likely received transparent key material, so set the
             * key with relevant flags and export it to the PSA keystore.
             */
            status = transform_plain_key_to_elke_blob(attributes, data,
                                                      data_length, key_buffer,
                                                      key_buffer_size,
                                                      key_buffer_length, bits,
                                                      &sssKey);
        }
        else
        {
            status = PSA_ERROR_INVALID_ARGUMENT;
        }
    }
    else if (true == (MCUXCLPSADRIVER_IS_S200_DATA_STORAGE(location)))
    {
        /* Open the tunnel */
        if (sss_sscp_tunnel_context_init(&tunnelCtx, &g_ele_ctx.sssSession, kSSS_tunnel_type_EL2GO_Data) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }

        tunnelCtx.buffer     = key_buffer;
        tunnelCtx.bufferSize = key_buffer_size;

        /* Pass the blob */
        /* coverity[misra_c_2012_rule_11_8_violation]: data is const but tunnel API requires non-const buffer */
        if (sss_sscp_tunnel(&tunnelCtx, (uint8_t *)data, data_length, &resultState) !=
            kStatus_SSS_Success)
        {
            (void)sss_sscp_tunnel_context_free(&tunnelCtx);
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }

        /* Free the tunnel */
        if (sss_sscp_tunnel_context_free(&tunnelCtx) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }

        *key_buffer_length = tunnelCtx.bufferSize;

        status = PSA_SUCCESS;
    }
    else
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
    }

exit:
    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location) ||
        true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location))
    {
        /* We won't be keeping the key in S200 keystore */
        (void)ele_s2xx_delete_key(&sssKey);
    }

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_opaque_export_key(const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        uint8_t *data,
                                        size_t data_size,
                                        size_t *data_length)
{
    psa_status_t status         = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    do
    {
        if (MCUXCLPSADRIVER_IS_S200_DATA_STORAGE(location))
        {
            if (data_size < key_buffer_size)
            {
                status = PSA_ERROR_BUFFER_TOO_SMALL;
                break;
            }

            /* At this point the data has already been retrieved from
            * persistent storage and no ELE calls are needed.
            */
            (void)memcpy(data, key_buffer, key_buffer_size);
            *data_length = key_buffer_size;
            status       = PSA_SUCCESS;
        }
        else if (MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
        {
            if (((psa_key_usage_t)0u == psa_get_key_usage_flags(attributes)) &&
                (PSA_ALG_NONE == psa_get_key_algorithm(attributes)) &&
                (PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1) == psa_get_key_type(attributes)))
            {
                /* Reuse public key export */
                status = ele_s2xx_opaque_export_public_key(attributes, key_buffer, key_buffer_size, data, data_size, data_length);
            }
            else
            {
                /* Nothing else supported */
                status = PSA_ERROR_NOT_SUPPORTED;
            }
        }
        else if (MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location))
        {
            if (data_size < key_buffer_size)
            {
                status = PSA_ERROR_BUFFER_TOO_SMALL;
                break;
            }

            /* The only export we support here is a direct blob export, so we
             * just copy the blob. We can't allow exporting from opaque blobs
             * to transparent key material, but we may enable opaqueA-to-opaqueB
             * exports down the line.
             */
            (void)memcpy(data, key_buffer, key_buffer_size);
            *data_length = key_buffer_size;
            status       = PSA_SUCCESS;
        }
        else
        {
            status = PSA_ERROR_NOT_SUPPORTED;
        }

    } while (false);

    return status;
}

psa_status_t ele_s2xx_opaque_export_public_key(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               uint8_t *data,
                                               size_t data_size,
                                               size_t *data_length)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey = {0};
    size_t data_bitlen       = 0u;

    if (false == PSA_KEY_TYPE_IS_ECC(psa_get_key_type(attributes)))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* For an opaque blob, we can't directly export, so we import the key,
     * let the S200 calculate/unwrap the public key and then we retrieve it.
     */

    /* CERT INT30-C: guard subtraction to prevent underflow when data_size == 0 */
    if (0u == data_size)
    {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
        goto exit;
    }

    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    *data_length = data_size - 1u;
    if (sss_sscp_key_store_get_key(&g_ele_ctx.keyStore, &sssKey,
                                   data + 1, data_length,
                                   &data_bitlen, kSSS_KeyPart_Public) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    /* PSA expects 0x04 as the leading byte for uncompressed ECC public keys */
    *data = 0x04u;
    /* CERT INT30-C: guard addition to prevent overflow when incrementing data_length */
    if (true == mcux_psa_add_size_t_wrapcheck(*data_length, 1u))
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }
    *data_length = *data_length + 1u;

    status = PSA_SUCCESS;
exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_opaque_destroy_key(const psa_key_attributes_t *attributes,
                                         uint8_t *key_buffer,
                                         size_t key_buffer_size)
{
    /* At this time, we do not store any key in the S200 keystore beyond
     * the lifetime of any given API operation. This function has no effect
     * until such caching is implemented in some way.
     */
    return PSA_SUCCESS;
}

static psa_status_t ele_s2xx_get_key_buffer_size_from_key_data(const psa_key_attributes_t *attributes,
                                                               const uint8_t *data,
                                                               size_t data_length,
                                                               size_t *key_buffer_length)
{
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    size_t key_bits             = psa_get_key_bits(attributes);
    psa_key_type_t key_type     = psa_get_key_type(attributes);
    psa_status_t status         = PSA_ERROR_CORRUPTION_DETECTED;

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location) ||
        true == MCUXCLPSADRIVER_IS_S200_DATA_STORAGE(location))
    {
        /* If one wants to import EL2GO keys/data, they are already blobbed
         * and cannot be transformed into EL2GO blobs from transparent material.
         * So we get the input data (blob) length and return the same length.
         */
        *key_buffer_length = data_length;
        status             = PSA_SUCCESS;
    }
    else if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location))
    {
        /* Technically, we are able to infer whether the input is transparent
         * key material or already blobbed key material.
         * 1. If it's _likely_ already a blob, we do the same as above.
         * 2. If it's _likely_ transparent key material, we take its length and
         *    add the blob overhead.
         * 3. Error if it's _most likely_ neither.
         */
        if (true == ele_s2xx_key_is_likely_non_el2go_blob(key_type, key_bits, data_length))
        {
            *key_buffer_length = data_length;
            status             = PSA_SUCCESS;
        }
        else if (true == ele_s2xx_key_is_likely_transparent(key_type, key_bits, data_length))
        {
            if (true == PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type))
            {
                /* Because in PSA ECC key pair == ECC private part, but we're
                 * making opaque blobs work as proper keypairs.
                 */
                *key_buffer_length = ele_s2xx_get_ecc_keypair_size(key_bits) + S200_BLOB_OVERHEAD;
            }
            else
            {
                *key_buffer_length = data_length + S200_BLOB_OVERHEAD;
            }
            status = PSA_SUCCESS;
        }
        else
        {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    }
    else
    {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}

size_t ele_s2xx_opaque_size_function(const psa_key_attributes_t *attributes,
                                     const uint8_t *data,
                                     size_t data_length)
{
    size_t key_buffer_size = 0u;
    psa_status_t status    = ele_s2xx_get_key_buffer_size_from_key_data(attributes,
                                                                        data,
                                                                        data_length,
                                                                        &key_buffer_size);
    if (PSA_SUCCESS != status)
    {
        key_buffer_size = 0u;
    }

    return key_buffer_size;
}

size_t ele_s2xx_opaque_get_key_buffer_size(const psa_key_attributes_t *attributes)
{
    size_t bits                 = psa_get_key_bits(attributes);
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    psa_key_type_t type         = psa_get_key_type(attributes);
    size_t key_buffer_size      = 0u;

    do
    {
        if (PSA_KEY_LOCATION_S200_KEY_STORAGE_NON_EL2GO == location)
        {
            /* Wrapcheck for `ele_s2xx_get_ecc_keypair_size(bits)`,
             * or `PSA_BITS_TO_BYTES(bits)`.
             */
            if (true == mcux_psa_add_size_t_wrapcheck(bits, 7u))
            {
                key_buffer_size = 0u;
                break;
            }

            if (true == PSA_KEY_TYPE_IS_ECC(type))
            {
                /* If it's ECC, then it's a key pair, as PSA does not allow
                 * generating only public parts of keys AND for S200 die-unique keys
                 * we blob the full keypair (vs PSA's way of only storing the
                 * private keypart for ECC key pairs).
                 */
                key_buffer_size = ele_s2xx_get_ecc_keypair_size(bits);
            }
            else
            {
                key_buffer_size = PSA_BITS_TO_BYTES(bits);
            }

            /* Wrapcheck for `key_buffer_size += S200_BLOB_OVERHEAD` */
            if (true == mcux_psa_add_size_t_wrapcheck(key_buffer_size, S200_BLOB_OVERHEAD))
            {
                key_buffer_size = 0u;
            }
            else
            {
                key_buffer_size += S200_BLOB_OVERHEAD;
            }
        }
        else
        {
            key_buffer_size = 0u;
        }
    } while (false);

    return key_buffer_size;
}

static psa_status_t translate_psa_key_agreement_to_ele_key_agreement(psa_algorithm_t alg,
                                                                     sss_algorithm_t *ele_alg)
{
    psa_status_t status = PSA_SUCCESS;

    switch (alg)
    {
        case PSA_ALG_ECDH:
            *ele_alg = kAlgorithm_SSS_ECDH;
            break;
        case ALG_S200_ECDH_CKDF:
            *ele_alg = kAlgorithm_SSS_E2E_BLOB;
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }

    return status;
}

static psa_status_t init_shared_secret_key_object(sss_sscp_object_t *sssKey_shared,
                                                  size_t allocation_size)
{
    psa_status_t status                    = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_key_property_t key_properties = {0};

    if (sss_sscp_key_object_init(sssKey_shared, &g_ele_ctx.keyStore) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    /* Disable all operations for this key, except for plain read */
    key_properties = kSSS_KeyProp_NoImportExport | kSSS_KeyProp_NoPlainWrite |
                     kSSS_KeyProp_NoVerify       | kSSS_KeyProp_NoSign;
    if (sss_sscp_key_object_allocate_handle(sssKey_shared, 0u,
                                            kSSS_KeyPart_Default, kSSS_CipherType_SYMMETRIC,
                                            allocation_size,
                                            key_properties) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto exit;
    }

    status = PSA_SUCCESS;
exit:
    /* Not freeing shared key object, leaving it to the caller */

    return status;
}

psa_status_t ele_s2xx_opaque_key_agreement(const psa_key_attributes_t *attributes,
                                           const uint8_t *key_buffer,
                                           size_t key_buffer_size,
                                           psa_algorithm_t alg,
                                           const uint8_t *peer_key,
                                           size_t peer_key_length,
                                           uint8_t *shared_secret,
                                           size_t shared_secret_size,
                                           size_t *shared_secret_length)
{
    psa_status_t status             = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_object_t sssKey        = {0};
    sss_sscp_object_t sssKey_peer   = {0};
    sss_sscp_object_t sssKey_shared = {0};
    sss_algorithm_t ele_alg         = {0};
    size_t bits                     = psa_get_key_bits(attributes);

    /* Only ECC keys for key agreement are supported by S200 */
    if (false == PSA_KEY_TYPE_IS_ECC(psa_get_key_type(attributes)))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Check if alg is supported by S200 */
    status = translate_psa_key_agreement_to_ele_key_agreement(alg, &ele_alg);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* Check curve family support */
    if (psa_get_key_type(attributes) != PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1) &&
        psa_get_key_type(attributes) != PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_MONTGOMERY))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Validations for supported key sizes for the given ECC family / algorithm
     * ECC Families : 224-521 for ECC_FAMILY_SECP_R1,
     *                256     for ECC_FAMILY_MONTGOMERY
     * Algorithms   : 224-521 for ALG_ECDH
     *                256     for ALG_S200_ECDH_CKDF
     */
    status = PSA_ERROR_NOT_SUPPORTED;
    switch (bits)
    {
        case 256u:
            /* 256 supported by all curves and algorithms validated in previous steps */
            status = PSA_SUCCESS;
            break;
        case 224u:
        case 384u:
        case 521u:
            /* 224, 384, and 521 supported only with (ECC_FAMILY_SECP_R1 && ALG_ECDH) */
            if ((PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1) == psa_get_key_type(attributes)) &&
                (PSA_ALG_ECDH == alg))
            {
                status = PSA_SUCCESS;
            }
            break;
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    if (NULL == key_buffer || 0u == key_buffer_size)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == peer_key || 0u == peer_key_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Load our key pair */
    status = ele_s2xx_import_key(attributes, key_buffer, key_buffer_size, &sssKey);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Load the peer key - peer key buffer and size shifted by 1 element,
     * since S200 expects no leading 0x04 Byte
     */
    status = ele_s2xx_set_key(&sssKey_peer, 0u, (peer_key + 1), (peer_key_length - 1u), kSSS_KeyPart_Public,
                              kSSS_CipherType_EC_NIST_P, kSSS_KeyProp_CryptoAlgo_KDF,
                              PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE(bits),
                              bits);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Initialize the shared secret key object */
    status = init_shared_secret_key_object(&sssKey_shared, PSA_BITS_TO_BYTES(bits));
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

    /* Do the key agreement, get the shared secret and set the output size */
    status = ele_s2xx_common_key_agreement(&sssKey, &sssKey_peer, &sssKey_shared,
                                           shared_secret, shared_secret_size, shared_secret_length,
                                           ele_alg);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }

exit:
    /* Delete keys from the S200 keystore */
    (void)ele_s2xx_delete_key(&sssKey_peer);
    (void)ele_s2xx_delete_key(&sssKey_shared);
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_opaque_generate_key(const psa_key_attributes_t *attributes,
                                          uint8_t *key_buffer,
                                          size_t key_buffer_size,
                                          size_t *key_buffer_length)
{
    psa_status_t status           = PSA_SUCCESS;
    psa_key_type_t type           = psa_get_key_type(attributes);
    /* coverity[misra_c_2012_rule_10_4_violation] */
    /* coverity[misra_c_2012_rule_10_8_violation]: PSA_KEY_TYPE_ECC_GET_FAMILY uses signed 0xff mask */
    psa_ecc_family_t ecc_family   = PSA_KEY_TYPE_ECC_GET_FAMILY(type);
    size_t bits                   = psa_get_key_bits(attributes);
    psa_key_lifetime_t lifetime   = psa_get_key_lifetime(attributes);
    psa_key_location_t location   = PSA_KEY_LIFETIME_GET_LOCATION(lifetime);
    sss_sscp_object_t sssKey      = {0u};
    sss_key_part_t key_part       = {0u};
    sss_cipher_type_t cipher_type = {0u};
    size_t allocation_size        = 0u;

    /* Wrapcheck for `PSA_BITS_TO_BYTES(bits)`,
     * and `ele_s2xx_get_ecc_keypair_size(bits)`.
     */
    if (true == mcux_psa_add_size_t_wrapcheck(bits, 7u))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* We disable plain writes and reads to/from this opaque key and limit
     * the allowed algorithms per the key algorithm attribute.
     */
    sss_sscp_key_property_t keyprops = kSSS_KeyProp_NoPlainWrite |
                                       kSSS_KeyProp_NoPlainRead;
    status = translate_psa_algorithm_to_ele_key_property(psa_get_key_algorithm(attributes),
                                                         &keyprops);
    if (PSA_SUCCESS != status)
    {
        return status;
    }

    /* For opaque keygen we support non-EL2GO opaque keys */
    if (false == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location))
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (true == PSA_KEY_TYPE_IS_ASYMMETRIC(type))
    {
        // ASYMMETRIC
        if (false == PSA_KEY_TYPE_IS_ECC(type))
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }

        /* Public part mustn't be generated. For keypair, we can store the whole
         * keypair blob instead of just the private part (PSA quirk with ECC
         * keys) and skip the export_public_key step. This enables PSA support
         * for EdDSA with opaque keys on S200.
         */
        key_part = kSSS_KeyPart_Pair;

        status = translate_psa_ecc_family_to_ele_cipher_type(attributes,
                                                             &cipher_type);
        if (PSA_SUCCESS != status)
        {
            return status;
        }

        /* The S200 expects 256 bitlen for Ed25519, so we update the bits
         * variable for the later call to sss_sscp_key_store_generate_key().
         */
        if ((PSA_ECC_FAMILY_TWISTED_EDWARDS == ecc_family ||
             PSA_ECC_FAMILY_MONTGOMERY == ecc_family) &&
            (true == IS_VALID_ED25519_BITLENGTH(bits)))
        {
            bits = 256u;
        }

        allocation_size = ele_s2xx_get_ecc_keypair_size(bits);
    }
    else
    {
        // UNSTRUCTURED / SYMMETRIC
        if (PSA_KEY_TYPE_AES != type && PSA_KEY_TYPE_HMAC != type)
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }

        key_part        = kSSS_KeyPart_Default;
        cipher_type     = kSSS_CipherType_SYMMETRIC;
        allocation_size = PSA_BITS_TO_BYTES(bits);
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if ((sss_sscp_key_object_init(&sssKey, &g_ele_ctx.keyStore)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if ((sss_sscp_key_object_allocate_handle(&sssKey, 0u, /* key id */
                                             key_part, cipher_type, allocation_size,
                                             (uint32_t)keyprops)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_key_store_generate_key(&g_ele_ctx.keyStore, &sssKey, bits, NULL) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    *key_buffer_length = key_buffer_size;
    if ((sss_sscp_key_store_export_key(&g_ele_ctx.keyStore, &sssKey, key_buffer, key_buffer_length,
                                       kSSS_blobType_ELKE_blob)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

exit:
    (void)ele_s2xx_delete_key(&sssKey);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_opaque_copy_key(psa_key_attributes_t *attributes,
                                      const uint8_t *source_key,
                                      size_t source_key_length,
                                      uint8_t *target_key_buffer,
                                      size_t target_key_buffer_size,
                                      size_t *target_key_buffer_length)
{
    /* NOTE: Once the driver API for copy_key is updated to be able to receive
     *       both the source AND target key's attributes, then the below code
     *       will apply ONLY to the case of source_location == target_location.
     */
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    (void)attributes;

    if (target_key_buffer_size < source_key_length)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* For same-location opaque copies, we just copy the blobs */
    (void)memcpy(target_key_buffer, source_key, source_key_length);
    *target_key_buffer_length = source_key_length;
    status = PSA_SUCCESS;

    return status;
}

/** @} */ // end of psa_key_generation
