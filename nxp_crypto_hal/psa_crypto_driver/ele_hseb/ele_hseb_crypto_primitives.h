/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELE_HSEB_CRYPTO_PRIMITIVES_H
#define ELE_HSEB_CRYPTO_PRIMITIVES_H

/** \file ele_hseb_crypto_primitives.h
 *
 * This file contains the declaration of the context structures related
 * to the ELE HSEB driver.
 *
 */

#include <stddef.h>
#include "hse_interface.h"
#include "hse_srv_utils.h"


typedef struct {
    hseHashAlgo_t alg; /*!< @brief The HSE hash algorithm. */
    uint8_t       chunk[144];  /*!< @brief An incomplete hash block of input data (largest block length is for SHA3_224 at 144 Bytes). */
    size_t        chunk_length; /*!< @brief The current length of the cached hash block. */
    size_t        chunk_size; /*!< @brief Max chunk size for the given alg (i.e. block length for the current algorithm). */
    uint8_t       ctx[MAX_STREAMING_CONTEXT_SIZE]; /*!< @brief Context blob. */
} ele_hseb_hash_operation_t;

typedef struct {
    hseCipherBlockMode_t cipher_mode;
    hseCipherDir_t       cipher_direction;
    uint8_t              key[32]; /*!< @brief Store the cipher operation key, as we need it during each step. */
    size_t               key_bits;
    uint8_t              iv[16];
    uint8_t              chunk[16];  /*!< @brief An incomplete AES block of input data. */
    size_t               chunk_length; /*!< @brief The current length of the cached AES block. */
    bool                 need_full_block; /*!< @brief Flag for whether or not the current algorithm requires full-block-length inputs. */
} ele_hseb_transparent_cipher_operation_t;

#endif /* ELE_HSEB_CRYPTO_PRIMITIVES_H */
