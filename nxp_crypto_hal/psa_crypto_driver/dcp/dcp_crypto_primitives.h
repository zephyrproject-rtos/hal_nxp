/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DCP_CRYPTO_PRIMITIVES_H
#define DCP_CRYPTO_PRIMITIVES_H

/** \file dcp_crypto_primtives.h
 *
 * This file contains the declaration of the context structures related
 * to the dcp driver
 *
 */

#include "fsl_dcp.h"

typedef struct {
    dcp_hash_ctx_t ctx;
    dcp_handle_t handle;
    uint32_t psa_mode;
    dcp_hash_algo_t dcp_mode;
} mcux_dcp_hash_operation_t;

#endif /* DCP_CRYPTO_PRIMITIVES_H */
