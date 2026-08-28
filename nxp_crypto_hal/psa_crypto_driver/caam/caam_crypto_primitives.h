/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CAAM_CRYPTO_PRIMITIVES_H
#define CAAM_CRYPTO_PRIMITIVES_H

/** \file caam_crypto_primtives.h
 *
 * This file contains the declaration of the context structures related
 * to the ele driver
 *
 */

#include "fsl_caam.h"

typedef struct {
    caam_hash_ctx_t ctx;
    caam_handle_t handle;
    uint32_t psa_mode;
    caam_hash_algo_t caam_mode;
} mcux_caam_hash_operation_t;

#endif /* CAAM_CRYPTO_PRIMITIVES_H */
