/*
 * Copyright 2022-2023, 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** @file  mcux_psa_s2xx_key_locations.h
 *  @brief Macros used by for el2go, Utils functions and psa_crypto_driver */

#ifndef _MCUX_PSA_S2XX_KEY_LOCATIONS_
#define _MCUX_PSA_S2XX_KEY_LOCATIONS_

// common flags
#define PSA_KEY_LOCATION_NXP_FLAG       (0x400000U)
#define PSA_KEY_LOCATION_EL2GO_FLAG     (0x200000U)
#define PSA_KEY_LOCATION_S200_FLAG      (0x000003U)
#define PSA_KEY_LOCATION_COMMON_FLAG    (PSA_KEY_LOCATION_VENDOR_FLAG | PSA_KEY_LOCATION_NXP_FLAG | PSA_KEY_LOCATION_EL2GO_FLAG | PSA_KEY_LOCATION_S200_FLAG)
#define PSA_KEY_LOCATION_NON_EL2GO_FLAG (PSA_KEY_LOCATION_VENDOR_FLAG | PSA_KEY_LOCATION_NXP_FLAG | PSA_KEY_LOCATION_S200_FLAG)
// key/data
#define PSA_KEY_LOCATION_KEY_FLAG    (0x000000U)
#define PSA_KEY_LOCATION_DATA_FLAG   (0x008000U)

// Final value of 0xE00003
#define PSA_KEY_LOCATION_S200_KEY_STORAGE           ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_KEY_FLAG))
// Final value of 0xE08003
#define PSA_KEY_LOCATION_S200_DATA_STORAGE          ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_DATA_FLAG))
// Final value of 0xC00003
#define PSA_KEY_LOCATION_S200_KEY_STORAGE_NON_EL2GO ((psa_key_location_t)(PSA_KEY_LOCATION_NON_EL2GO_FLAG | PSA_KEY_LOCATION_KEY_FLAG))

/*! Size of the S200 die-unique key blob overhead added to the actual key. */
#define PSA_S200_NON_EL2GO_BLOB_OVERHEAD (24u)
/*! Export size calculation for S200 non-EL2GO key blobs. ECC pairs are
 *  blobbed as key pairs instead of just the private key part.
*/
#define PSA_S200_NON_EL2GO_BLOB_EXPORT_SIZE(key_type, bits) (                            \
    ((true == PSA_KEY_TYPE_IS_ECC_KEY_PAIR(key_type)) ?                                  \
        ((((bits + 7u) / 8u) * 3u) + PSA_S200_NON_EL2GO_BLOB_OVERHEAD) :                 \
        (PSA_EXPORT_KEY_OUTPUT_SIZE(key_type, bits) + PSA_S200_NON_EL2GO_BLOB_OVERHEAD)) \
    )


#define MCUXCLPSADRIVER_IS_LOCAL_STORAGE(location)              ((location) == PSA_KEY_LOCATION_LOCAL_STORAGE)
#define MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location)           ((location) == PSA_KEY_LOCATION_S200_KEY_STORAGE)
#define MCUXCLPSADRIVER_IS_S200_DATA_STORAGE(location)          ((location) == PSA_KEY_LOCATION_S200_DATA_STORAGE)
#define MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location) ((location) == PSA_KEY_LOCATION_S200_KEY_STORAGE_NON_EL2GO)

#define PSA_KEY_LOCATION_EXTERNAL_STORAGE ((psa_key_location_t)(PSA_KEY_LOCATION_VENDOR_FLAG | 0x00U))

#endif /*_MCUX_PSA_S2XX_KEY_LOCATIONS_ */

