/*
 * Copyright 2024-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ELE_S2XX_CRYPTO_PRIMITIVES_H
#define ELE_S2XX_CRYPTO_PRIMITIVES_H

/** \file ele_s2xx_crypto_primtives.h
 *
 * This file contains the declaration of the context structures related
 * to the ele driver
 *
 */

#include "fsl_sscp_mu.h"
#include "fsl_sss_sscp.h"

#if defined(ELE_FEATURE_MAC_CONTEXT_BLOB_SIZE_IN_BYTES)
#define ELE_S2XX_MULTIPART_MAC_BLOB_SIZE (ELE_FEATURE_MAC_CONTEXT_BLOB_SIZE_IN_BYTES)
#else
/* Never used in this case, but this eases portability between KW4x families */
#define ELE_S2XX_MULTIPART_MAC_BLOB_SIZE (1u)
#endif

#if defined(ELE_FEATURE_DIGEST_CONTEXT_BLOB_SIZE_IN_BYTES)
#define ELE_S2XX_MULTIPART_HASH_BLOB_SIZE (ELE_FEATURE_DIGEST_CONTEXT_BLOB_SIZE_IN_BYTES)
#else
/* Never used in this case, but this eases portability between KW4x families */
#define ELE_S2XX_MULTIPART_HASH_BLOB_SIZE (1u)
#endif

/* Hash operation */
typedef struct
{
    sss_sscp_digest_t ctx;
    uint8_t           context_blob[ELE_S2XX_MULTIPART_HASH_BLOB_SIZE];
} ele_s2xx_hash_operation_t;

typedef struct {
    sss_sscp_object_t key_object;
    sss_algorithm_t   algorithm;
    uint8_t           context_blob[ELE_S2XX_MULTIPART_MAC_BLOB_SIZE];
} ele_s2xx_transparent_mac_operation_t,ele_s2xx_opaque_mac_operation_t,ele_s2xx_mac_operation_t;


#endif /* ELE_S2XX_CRYPTO_PRIMITIVES_H */
