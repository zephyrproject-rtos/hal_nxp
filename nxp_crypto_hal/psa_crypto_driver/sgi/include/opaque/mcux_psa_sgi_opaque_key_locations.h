/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_SGI_OPAQUE_KEY_LOCATIONS_H
#define MCUX_PSA_SGI_OPAQUE_KEY_LOCATIONS_H

/**
 * @file  mcux_psa_sgi_opaque_key_locations.h
 * @brief PSA key location definitions for the SGI opaque driver.
 *
 * Location taxonomy (all values in the PSA vendor range 0x800000-0xFFFFFF):
 *
 */

#include "psa/crypto.h"

/* -------------------------------------------------------------------------
 * Base flags
 * PSA_KEY_LOCATION_VENDOR_FLAG = 0x800000  (defined in psa/crypto_values.h)
 * ------------------------------------------------------------------------- */
#define PSA_KEY_LOCATION_NXP_FLAG    (0x400000U)
#define PSA_KEY_LOCATION_SGI_FLAG    (0x000005U)
#define PSA_KEY_LOCATION_COMMON_FLAG (PSA_KEY_LOCATION_VENDOR_FLAG | PSA_KEY_LOCATION_NXP_FLAG | \
                                      PSA_KEY_LOCATION_SGI_FLAG)
// key/data
#define PSA_KEY_LOCATION_KEY_FLAG    (0x000000U)
#define PSA_KEY_LOCATION_DATA_FLAG   (0x008000U)

/*
 * PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE
 *
 * Keys at this location are stored in RAM as an AEAD (AES-CCM) blob encrypted
 * with a DUK-derived 256-bit Secure Storage Root Key (SSRK).
 *
 * Blob format (28 bytes overhead + key data):
 *   [ 8 bytes nonce ][ AES-CCM( metadata(12 B) + key_data ) ][ 8 bytes tag ]
 *
 * Metadata (12 bytes):
 *   key_alg  : uint32_t  (PSA algorithm)
 *   key_usage: uint32_t  (PSA key usage flags)
 *   key_type : uint16_t  (PSA key type)
 *   key_bits : uint16_t  (key length in bits)
 *
 * Supported operations: import, generate, key_derivation, export (blob only)
 */
#define PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE ((psa_key_location_t) (PSA_KEY_LOCATION_COMMON_FLAG \
                                                                        | PSA_KEY_LOCATION_KEY_FLAG))

/* -------------------------------------------------------------------------
 * Helper predicates
 * ------------------------------------------------------------------------- */
#define MCUX_PSA_SGI_IS_DUK_BLOB_LOCATION(location) \
        ((location) == PSA_CRYPTO_SGI_LOCATION_DUK_BLOB_STORAGE)

/** True for any SGI opaque location */
#define MCUX_PSA_SGI_IS_OPAQUE_LOCATION(loc)            \
        (MCUX_PSA_SGI_IS_DUK_BLOB_LOCATION(loc))

#endif /* MCUX_PSA_SGI_OPAQUE_KEY_LOCATIONS_H */
