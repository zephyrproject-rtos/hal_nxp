/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef HASHCRYPT_CRYPTO_PRIMITIVES_H
#define HASHCRYPT_CRYPTO_PRIMITIVES_H

/** \file hashcrypt_crypto_primtives.h
 *
 * This file contains the declaration of the context structures related
 * to the ele driver
 *
 */

#include "fsl_hashcrypt.h"

typedef struct {
    hashcrypt_hash_ctx_t ctx;
    uint32_t psa_mode;
    hashcrypt_algo_t hashcrypt_mode;
} mcux_hashcrypt_hash_operation_t;

#endif /* HASHCRYPT_CRYPTO_PRIMITIVES_H */
