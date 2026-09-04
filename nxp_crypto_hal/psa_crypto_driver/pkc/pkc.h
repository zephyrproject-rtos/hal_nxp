/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PKC_H
#define PKC_H

/** \file pkc.h
 *
 * This file includes each module of the pkc driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref pkc_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_PKC is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_PKC)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_PKC */

#if !defined(__ZEPHYR__)
/*
 * Location specific details go in this file which is also exposed to application writers
 * to include when using key from a particular location.
 * Note: For Zephyr OS, we must define these in respectiv SoC defconf.
 */
#include "mcux_psa_defines.h"
#endif

//  #include "pkc_crypto_primitives.h"
#include "mcux_psa_pkc_asymmetric_signature.h"
#include "mcux_psa_pkc_init.h"
#include "mcux_psa_pkc_key_generation.h"

#endif /* PKC_H */
