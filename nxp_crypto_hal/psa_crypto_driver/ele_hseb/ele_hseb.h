/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELE_HSEB_H
#define ELE_HSEB_H

/** \file ele_hseb.h
 *
 * This file includes each module of the ele_hseb driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. The list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_ele_hseb_cipher.h
 *  - Message authentication codes:           mcux_psa_ele_hseb_mac.h
 *  - Authenticated encryption with AD:       mcux_psa_ele_hseb_aead.h
 *  - Entropy extraction:                     mcux_psa_ele_hseb_entropy.h
 *  - Asymmetric signatures:                  mcux_psa_ele_hseb_asymmetric_signature.h
 *  - Hashing:                                mcux_psa_ele_hseb_hash.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref ele_hseb_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_ELE_HSEB is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

/*
 * Location specific details go in this file which is also exposed to application writers
 * to include when using key from a particular location.
 */
#include "mcux_psa_defines.h"

#include "ele_hseb_crypto_composites.h"
#include "ele_hseb_crypto_primitives.h"
#include "mcux_psa_ele_hseb_init.h"
#include "mcux_psa_ele_hseb_entropy.h"
#include "mcux_psa_ele_hseb_cipher.h"
#include "mcux_psa_ele_hseb_mac.h"
#include "mcux_psa_ele_hseb_aead.h"
#include "mcux_psa_ele_hseb_hash.h"
#include "mcux_psa_ele_hseb_asymmetric_signature.h"
#include "mcux_psa_ele_hseb_opaque_key_generation.h"
#include "mcux_psa_ele_hseb_opaque_asymmetric_signature.h"

#endif /* ELE_HSEB_H */
