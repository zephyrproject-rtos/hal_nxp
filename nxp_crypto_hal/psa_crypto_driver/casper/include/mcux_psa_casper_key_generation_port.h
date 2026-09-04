/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#ifndef MCUX_PSA_CASPER_KEY_GENERATION_PORT_H
#define MCUX_PSA_CASPER_KEY_GENERATION_PORT_H

/** \file mcux_psa_casper_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "mbedtls/error.h"
#include "mbedtls/private_access.h"

#include <psa/crypto.h>
#include "mbedtls/psa_util.h"

#include "mcux_psa_casper_ecp_port.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C) && \
    ( defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || \
      defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || \
      defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED) )
psa_status_t casper_mbedtls_psa_ecp_generate_key(const psa_key_attributes_t *attributes,
                                                 uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 size_t *key_buffer_length);
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ECP_C && curve enabled */

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_CASPER_INIT_H */
