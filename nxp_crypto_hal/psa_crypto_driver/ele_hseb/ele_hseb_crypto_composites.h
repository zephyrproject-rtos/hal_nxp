/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELE_HSEB_CRYPTO_COMPOSITES_H
#define ELE_HSEB_CRYPTO_COMPOSITES_H

/** \file ele_hseb_crypto_composites.h
 *
 * This file contains the declaration of the composite context structures
 * related to the ELE HSEB driver.
 *
 */

#include <stddef.h>
#include "psa/crypto_types.h"
#include "hse_interface.h"

#define HSEB_MAX_MAC_KEY_SIZE (HSE_MAX_HMAC_KEY_BITS_LEN / 8u)

typedef struct {
    psa_algorithm_t alg; /*!< \brief The algorithm being used. */
    psa_key_type_t  key_type; /*!< \brief Keep the key type, as they behave differently. */
    uint8_t         key[HSEB_MAX_MAC_KEY_SIZE]; /*!< \brief Key for the multipart operation. */
    size_t          key_bits; /*!< \brief Bitsize of the key. */
    hseAuthDir_t    auth_direction; /*!< \brief MAC generation or verification. */
    uint8_t         chunk[128]; /*!< \brief An incomplete block of input data (largest block length is for SHA512 at 128 Bytes). */
    size_t          chunk_length; /*!< \brief The current length of the cached chunk. */
    size_t          chunk_size; /*!< \brief Max chunk size for the given alg (i.e. block length for the current algorithm). */
    bool            is_mac_started; /*!< \brief Helper for MAC FINISH edge cases (streaming MACs can't compute the MAC with 0-input). */
    hseHashAlgo_t   hash_alg; /*!< \brief If we are doing HMAC, this holds the hash algo. */
} ele_hseb_transparent_mac_operation_t;

typedef struct {
    uint8_t dummy; // Prepared for future support of multipart AEAD
} ele_hseb_transparent_aead_operation_t;

#endif /* ELE_HSEB_CRYPTO_COMPOSITES_H */
