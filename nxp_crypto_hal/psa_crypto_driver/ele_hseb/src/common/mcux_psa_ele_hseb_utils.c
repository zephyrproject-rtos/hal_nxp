/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/** \file mcux_psa_ele_hseb_utils.c
 *
 * This file contains the definitions of the entry points associated
 * with common utility functions utilized by the ELE HSEB PSA port driver.
 */

#include "mcux_psa_ele_hseb_utils.h"

#include "hse_common_types.h"
#include "hse_b_config.h"

size_t ele_hseb_get_chunk_overflow(size_t chunk_size,
                                   size_t chunk_used_length,
                                   size_t input_length)
{
    /* Avoid unsigned wrap: compute available space first, then compare */
    const size_t available = chunk_size - chunk_used_length;

    if (input_length > available) {
        return input_length - available;
    }
    return 0u;
}

size_t ele_hseb_manage_chunk(uint8_t *chunk,
                             size_t chunk_size,
                             size_t *chunk_length,
                             const uint8_t *input,
                             size_t input_length,
                             bool *is_chunk_full,
                             size_t *overflow)
{
    bool is_chunk_full_internal = false;
    size_t overflow_internal    = 0u;

    overflow_internal = ele_hseb_get_chunk_overflow(chunk_size,
                                                    *chunk_length,
                                                    input_length);

    const size_t copy_length_without_overflow = input_length - overflow_internal;
    (void) memcpy((chunk + *chunk_length),
                  input,
                  copy_length_without_overflow);

    *chunk_length += copy_length_without_overflow;
    if (*chunk_length >= chunk_size) {
        is_chunk_full_internal = true;
    } else {
        is_chunk_full_internal = false;
    }

    if (is_chunk_full != NULL) {
        *is_chunk_full = is_chunk_full_internal;
    }

    if (overflow != NULL) {
        *overflow = overflow_internal;
    }

    return copy_length_without_overflow;
}

bool is_mac_length_supported(const psa_key_attributes_t *attributes,
                             psa_algorithm_t alg)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);
    size_t mac_length       = PSA_MAC_LENGTH(key_type, key_bits, alg);

    /* Defensive: unknown/invalid derived length */
    if (mac_length == 0u) {
        return false;
    }

    /* Full length MAC always supported */
    if (PSA_ALG_FULL_LENGTH_MAC(alg) == alg) {
        return true;
    }

    /* HSEB requires tags >= 8 bytes */
    if (mac_length < 8u) {
        return false;
    }

    if (true == PSA_ALG_IS_HMAC(alg)) {
        return mac_length <= PSA_HASH_LENGTH(alg);
    }

    if (true == PSA_ALG_IS_BLOCK_CIPHER_MAC(alg)) {
        return mac_length <= PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type);
    }

    return false;
}

bool is_mac_key_size_supported(psa_key_type_t key_type, size_t key_bits)
{
    if (PSA_KEY_TYPE_AES == key_type) {
        if ((128u == key_bits) || (192u == key_bits) || (256u == key_bits)) {
            return true;
        }
    }

    if (PSA_KEY_TYPE_HMAC == key_type) {
        if ((HSE_MIN_HMAC_KEY_BITS_LEN <= key_bits) &&
            (HSE_MAX_HMAC_KEY_BITS_LEN >= key_bits)) {
            return true;
        }
    }

    return false;
}

void ele_hseb_read_key_handle_from_buffer(const uint8_t *key_buffer,
                                          hseKeyHandle_t *hseb_key_handle)
{
    (void) memcpy(hseb_key_handle, key_buffer, sizeof(hseKeyHandle_t));
}

void ele_hseb_write_key_handle_to_buffer(uint8_t *key_buffer,
                                         size_t *key_buffer_length,
                                         const hseKeyHandle_t *hseb_key_handle)
{
    (void) memcpy(key_buffer, hseb_key_handle, sizeof(hseKeyHandle_t));
    *key_buffer_length = sizeof(hseKeyHandle_t);
}
