/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DCP_H
#define DCP_H

/** \file dcp.h
 *
 * This file includes each module of the dcp driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      mcux_psa_dcp_cipher.h
 *  - Hashing:                                mcux_psa_dcp_hash.h
 *  - Entropy extraction:                     mcux_psa_dcp_entropy.h
 */
#if defined(PSA_CRYPTO_DRIVER_DCP)
#ifndef PSA_CRYPTO_DRIVER_PRESENT
#define PSA_CRYPTO_DRIVER_PRESENT
#endif
#ifndef PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#define PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT
#endif
#endif /* PSA_CRYPTO_DRIVER_DCP */

/*
 * Location specific details go in this file which is also exposed to application writers
 * to iunclude when using key from a particular location.
 */
#include "dcp_crypto_primitives.h"
#include "mcux_psa_dcp_cipher.h"
#include "mcux_psa_dcp_hash.h"
#include "mcux_psa_dcp_common_init.h"
#include "mcux_psa_dcp_init.h"
#include "mcux_psa_dcp_entropy.h"


#endif /* DCP_H */
