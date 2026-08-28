/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef MCUX_PSA_S2XX_KEY_GENERATION_H
#define MCUX_PSA_S2XX_KEY_GENERATION_H

/** \file mcux_psa_s2xx_key_generation.h
 *
 * This file contains the declaration of the entry points associated to the
 * key generation capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */
#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

psa_status_t ele_s2xx_transparent_generate_key(const psa_key_attributes_t *attributes,
                                               uint8_t *key_buffer, size_t key_buffer_size,
                                               size_t *key_buffer_length);

psa_status_t ele_s2xx_transparent_export_public_key(const psa_key_attributes_t *attributes,
                                                    const uint8_t *key_buffer,
                                                    size_t key_buffer_size,
                                                    uint8_t *data,
                                                    size_t data_size,
                                                    size_t *data_length);

psa_status_t ele_s2xx_transparent_key_agreement(const psa_key_attributes_t *attributes,
                                                const uint8_t *key_buffer,
                                                size_t key_buffer_size,
                                                psa_algorithm_t alg,
                                                const uint8_t *peer_key,
                                                size_t peer_key_length,
                                                uint8_t *shared_secret,
                                                size_t shared_secret_size,
                                                size_t *shared_secret_length);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_S2XX_KEY_GENERATION_H */
