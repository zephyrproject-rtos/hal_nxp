/*
 * Copyright 2023 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELS_PKC_DRIVER_H
#define ELS_PKC_DRIVER_H
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)

/** \file els_pkc_driver.h
 *
 * This file includes each module of the els_pkc driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_els_pkc_cipher.h
 *  - Access to ELE for entropy extraction:   mcux_psa_els_pkc_entropy.h
 *  - Hashing:                                mcux_psa_els_pkc_hash.h
 *  - Authenticated Encryption w Assoc. Data: mcux_psa_els_pkc_aead.h
 *  - Asymmetric signature schemes:           mcux_psa_els_pkc_asymmetric_signature.h
 *  - Asymmetric encryption schemes:          mcux_psa_els_pkc_asymmetric_encryption.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref ele4xx_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_ELS_PKC is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */

#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif

#include "mcuxClPsaDriver_Oracle_Interface_key_locations.h"

#define PSA_CRYPTO_ELS_PKC_LOCATION_S50_ENC_STORAGE_KEY   PSA_KEY_LOCATION_S50_ENC_STORAGE_KEY
#define PSA_CRYPTO_ELS_PKC_LOCATION_S50_ENC_STORAGE_DATA  PSA_KEY_LOCATION_S50_ENC_STORAGE_DATA
#define PSA_CRYPTO_ELS_PKC_LOCATION_S50_BLOB_STORAGE      PSA_KEY_LOCATION_S50_BLOB_STORAGE
#define PSA_CRYPTO_ELS_PKC_LOCATION_S50_KEY_GEN_STORAGE   PSA_KEY_LOCATION_S50_KEY_GEN_STORAGE
#define PSA_CRYPTO_ELS_PKC_LOCATION_S50_RFC3394_STORAGE   PSA_KEY_LOCATION_S50_RFC3394_STORAGE

#include "mcux_psa_els_pkc_entropy.h"

#include "mcux_psa_els_pkc_init.h"
#include "mcux_psa_els_pkc_aead.h"
#include "mcux_psa_els_pkc_cipher.h"
#include "mcux_psa_els_pkc_hash.h"
#include "mcux_psa_els_pkc_asymmetric_signature.h"
#include "mcux_psa_els_pkc_key_generation.h"
#include "mcux_psa_els_pkc_mac.h"

#include "mcux_psa_els_pkc_opaque_init.h"
#include "mcux_psa_els_pkc_opaque_key_generation.h"
#include "mcux_psa_els_pkc_opaque_asymmetric_signature.h"
#include "mcux_psa_els_pkc_opaque_cipher.h"
#include "mcux_psa_els_pkc_opaque_aead.h"
#include "mcux_psa_els_pkc_opaque_mac.h"

#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* ELS_PKC_DRIVER_H */
