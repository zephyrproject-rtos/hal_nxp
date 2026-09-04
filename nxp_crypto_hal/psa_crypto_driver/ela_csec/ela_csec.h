/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELA_CSEC_H
#define ELA_CSEC_H

/** \file ela_csec.h
 *
 * This file includes each module of the ela_csec driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. The list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_ela_csec_cipher.h
 *  - Message authentication codes:           mcux_psa_ela_csec_mac.h
 *  - Entropy extraction:                     mcux_psa_ela_csec_entropy.h
 *
 * \note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through \ref ela_csec_crypto_primitives.h which is included, when
 * \ref PSA_CRYPTO_DRIVER_ELA_CSEC is defined, in turn by \ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS module.
 */
#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_ELA_CSEC */

/*
 * Location specific details go in this file which is also exposed to application writers
 * to include when using key from a particular location.
 */
#include "mcux_psa_ela_csec_init.h"
#include "mcux_psa_ela_csec_entropy.h"
#include "mcux_psa_ela_csec_cipher.h"
#include "mcux_psa_ela_csec_mac.h"

#endif /* ELA_CSEC_H */
