/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSS_CONFIG_H
#define FSL_SSS_CONFIG_H

/* clang-format off */
#define SSS_SESSION_MAX_CONTEXT_SIZE        (16)
#define SSS_KEY_STORE_MAX_CONTEXT_SIZE      (16 + 80)
#define SSS_KEY_OBJECT_MAX_CONTEXT_SIZE     (16)
#define SSS_SYMMETRIC_MAX_CONTEXT_SIZE      (16 + 80)
#define SSS_AEAD_MAX_CONTEXT_SIZE           (16)
#define SSS_DIGEST_MAX_CONTEXT_SIZE         (16 + 80)
#define SSS_MAC_MAX_CONTEXT_SIZE            (16 + 16)
#define SSS_ASYMMETRIC_MAX_CONTEXT_SIZE     (16)
#define SSS_TUNNEL_MAX_CONTEXT_SIZE         (16)
#define SSS_DERIVE_KEY_MAX_CONTEXT_SIZE     (16)
#define SSS_RNG_MAX_CONTEXT_SIZE            (16)
#define SSS_PH_CLSHA_CTX_MAX_CONTEXT_SIZE   (216)
/* clang-format on */

#endif /* FSL_SSS_CONFIG_H */
