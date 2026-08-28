/*
 * Copyright 2024-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELE_S2XX_H
#define ELE_S2XX_H

/** \file ele2xx.h
 *
 * This file includes each module of the ele2xx driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_s2xx_cipher.h
 *  - Access to ELE for entropy extraction:   mcux_psa_s2xx_entropy.h
 *  - Hashing:                                mcux_psa_s2xx_hash.h
 *  - Authenticated Encryption w Assoc. Data: mcux_psa_s2xx_aead.h
 *  - Asymmetric signature schemes:           mcux_psa_s2xx_asymmetric_signature.h
 *  - Key generation:                         mcux_psa_s2xx_key_generation.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref ele2xx_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_ELE_S2XX is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */

#include "mcux_psa_s2xx_key_locations.h"

/* S2XX key locations */
#define PSA_CRYPTO_LOCATION_S200_KEY_STORAGE           PSA_KEY_LOCATION_S200_KEY_STORAGE
#define PSA_CRYPTO_LOCATION_S200_DATA_STORAGE          PSA_KEY_LOCATION_S200_DATA_STORAGE
#define PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO PSA_KEY_LOCATION_S200_KEY_STORAGE_NON_EL2GO

/* S2XX vendor-defined algorithms */
#define PSA_ALG_NXP_ALL_CIPHER      ALG_NXP_ALL_CIPHER
#define PSA_ALG_NXP_ALL_AEAD        ALG_NXP_ALL_AEAD
#define PSA_ALG_S200_ECBKDF_OR_CKDF ALG_S200_ECBKDF_OR_CKDF
#define PSA_ALG_S200_ECDH_CKDF      ALG_S200_ECDH_CKDF

#if !defined(__ZEPHYR__)
/*
 * Location specific details go in this file which is also exposed to application writers
 * to include when using key from a particular location.
 * Note: For Zephyr OS, we must define these in respective SoC defconf.
 */
#include "mcux_psa_defines.h"
#endif

#include "mcux_psa_s2xx_entropy.h"

#include "mcux_psa_s2xx_init.h"
#include "mcux_psa_s2xx_aead.h"
#include "mcux_psa_s2xx_cipher.h"
#include "mcux_psa_s2xx_hash.h"
#include "mcux_psa_s2xx_mac.h"
#include "mcux_psa_s2xx_asymmetric_signature.h"
#include "mcux_psa_s2xx_key_generation.h"

#include "mcux_psa_s2xx_opaque_key_generation.h"
#include "mcux_psa_s2xx_opaque_asymmetric_signature.h"
#include "mcux_psa_s2xx_opaque_cipher.h"
#include "mcux_psa_s2xx_opaque_aead.h"
#include "mcux_psa_s2xx_opaque_mac.h"

#endif /* ELE_S2XX_H */
