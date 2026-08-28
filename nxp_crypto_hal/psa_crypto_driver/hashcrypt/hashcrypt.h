/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef HASHCRYPT_H
#define HASHCRYPT_H

/** \file hashcrypt.h
 *
 * This file includes each module of the hashcrypt driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_hashcrypt_cipher.h
 *  - Access to ELE for entropy extraction:   mcux_psa_hashcrypt_entropy.h
 *  - Hashing:                                mcux_psa_hashcrypt_hash.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref hashcrypt_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_HASHCRYPT is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */

#if !defined(__ZEPHYR__)
/*
 * Location specific details go in this file which is also exposed to application writers
 * to include when using key from a particular location.
 * Note: For Zephyr OS, we must define these in respective SoC defconf.
 */
#include "mcux_psa_defines.h"
#endif

#include "hashcrypt_crypto_primitives.h"
#include "mcux_psa_hashcrypt_common_cipher.h"
#include "mcux_psa_hashcrypt_common_init.h"
#include "mcux_psa_hashcrypt_hash.h"
#include "mcux_psa_hashcrypt_init.h"

#endif /* HASHCRYPT_H */
