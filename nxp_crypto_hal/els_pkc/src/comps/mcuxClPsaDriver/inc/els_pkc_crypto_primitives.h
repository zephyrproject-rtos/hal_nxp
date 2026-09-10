/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELS_PKC_CRYPTO_PRIMITIVES_H
#define ELS_PKC_CRYPTO_PRIMITIVES_H

/** \file els_pkc_crypto_primtives.h
 *
 * This file contains the declaration of the context structures related
 * to the els_pkc driver
 *
 */

/* Include CLNS header files */
#include <mcuxClPsaDriver_MemoryConsumption.h>
#include <mcuxClKey.h>
#include <mcuxClCipher.h>
#include <mcuxClCipherModes.h>
#include <mcuxClHash.h>

typedef struct {
    uint32_t clns_data[MCUXCLPSADRIVER_CLNSDATA_HASH_SIZE / sizeof(uint32_t)];
} els_pkc_hash_operation_t;

typedef struct {
    uint32_t clns_data[MCUXCLPSADRIVER_CLNSDATA_CIPHER_SIZE / sizeof(uint32_t)];

    uint16_t iv_required;
    uint16_t default_iv_length;
} els_pkc_transparent_cipher_operation_t,els_pkc_opaque_cipher_operation_t,els_pkc_cipher_operation_t;

#endif /* ELS_PKC_CRYPTO_PRIMITIVES_H */
