/*
 * Copyright 2025 - 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SGI_H
#define SGI_H

/** \file sgi.h
 *
 * This file includes each module of the SGI accelerator that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_sgi_cipher.h
 *  - Access to SGI for entropy extraction:   mcux_psa_sgi_entropy.h
 *  - Hashing:                                mcux_psa_sgi_hash.h
 *  - Authenticated Encryption w Assoc. Data: mcux_psa_sgi_aead.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref sgi_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_SGI is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_SGI)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_SGI */

#include "mcux_psa_sgi_opaque_key_locations.h"

#if !defined(__ZEPHYR__)
/*
 * Location specific details go in this file which is also exposed to application writers
 * to include when using key from a particular location.
 * Note: For Zephyr OS, we must define these in respectiv SoC defconf.
 */
#include "mcux_psa_defines.h"
#endif

#include "sgi_crypto_primitives.h"
#include "mcux_psa_sgi_cipher.h"
#include "mcux_psa_sgi_common_init.h"
#include "mcux_psa_sgi_hash.h"
#include "mcux_psa_sgi_aead.h"
#include "mcux_psa_sgi_mac.h"
#include "mcux_psa_sgi_init.h"

/* Opaque driver entry points */
#include "mcux_psa_sgi_opaque_key_generation.h"

#endif /* SGI_H */
