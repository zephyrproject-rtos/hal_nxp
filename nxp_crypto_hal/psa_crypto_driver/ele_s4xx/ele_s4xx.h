/*
 * Copyright 2022-2023 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELE_S4XX_H
#define ELE_S4XX_H

/** \file ele4xx.h
 *
 * This file includes each module of the ele4xx driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_s4xx_cipher.h
 *  - Access to ELE for entropy extraction:  mcux_psa_s4xx_entropy.h
 *  - Hashing:                                mcux_psa_s4xx_hash.h
 *  - Authenticated Encryption w Assoc. Data: mcux_psa_s4xx_aead.h
 *  - Asymmetric signature schemes:           mcux_psa_s4xx_asymmetric_signature.h
 *  - Asymmetric encryption schemes:          mcux_psa_s4xx_asymmetric_encryption.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref ele4xx_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_ELE_S4XX is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */

#define PSA_CRYPTO_ELE_S4XX_LOCATION 0xC00002

#include "mcux_psa_s4xx_entropy.h"

#include "mcux_psa_s4xx_init.h"
#include "mcux_psa_s4xx_aead.h"
#include "mcux_psa_s4xx_cipher.h"
#include "mcux_psa_s4xx_hash.h"
#include "mcux_psa_s4xx_asymmetric_encryption.h"
#include "mcux_psa_s4xx_asymmetric_signature.h"
#include "mcux_psa_s4xx_key_agreement.h"

#include "mcux_psa_s4xx_opaque_init.h"
#include "mcux_psa_s4xx_opaque_key_generation.h"
#include "mcux_psa_s4xx_opaque_asymmetric_signature.h"
#include "mcux_psa_s4xx_opaque_cipher.h"
#include "mcux_psa_s4xx_opaque_aead.h"
#include "mcux_psa_s4xx_opaque_mac.h"

#endif /* ELE_S4XX_H */
