/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CAAM_H
#define CAAM_H

/** \file caam.h
 *
 * This file includes each module of the caam driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_caam_cipher.h
 *  - Access to CAAM for entropy extraction:  mcux_psa_caam_entropy.h
 *  - Hashing:                                mcux_psa_caam_hash.h
 *  - Authenticated Encryption w Assoc. Data: mcux_psa_caam_aead.h
 *  - Asymmetric signature schemes:           mcux_psa_caam_asymmetric_signature.h
 *  - Asymmetric encryption schemes:          mcux_psa_caam_asymmetric_encryption.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref caam_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_CAAM is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_CAAM */

#define PSA_CRYPTO_CAAM_LOCATION 0x000001

#include "caam_crypto_primitives.h"
#include "mcux_psa_caam_common_aead.h"
#include "mcux_psa_caam_common_asymmetric_encryption.h"
#include "mcux_psa_caam_common_asymmetric_signature.h"
#include "mcux_psa_caam_common_cipher.h"
#include "mcux_psa_caam_hash.h"
#include "mcux_psa_caam_common_init.h"
#include "mcux_psa_caam_common_key_generation.h"
#include "mcux_psa_caam_common_mac.h"
#include "mcux_psa_caam_entropy.h"
#include "mcux_psa_caam_init.h"

#endif /* CAAM_H */
