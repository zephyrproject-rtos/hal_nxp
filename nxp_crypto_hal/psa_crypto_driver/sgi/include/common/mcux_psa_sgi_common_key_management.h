/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_SGI_COMMON_KEY_MANAGEMENT_H
#define MCUX_PSA_SGI_COMMON_KEY_MANAGEMENT_H

/**
 * @file  mcux_psa_sgi_common_key_management.h
 * @brief Common SGI key management utilities shared between transparent and
 *        opaque PSA crypto drivers.
 *
 * This header provides helper functions that create and configure SGI key
 * descriptors from PSA key attributes, eliminating code duplication across
 * the transparent and opaque driver entry points.
 */

#include "psa/crypto.h"

#include <mcuxClKey.h>
#include <mcuxClSession.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create and initialize an SGI key descriptor from PSA key attributes.
 *
 * For LOCAL_STORAGE keys, the key material is set as loaded-in-place.
 * For opaque key locations, the key data pointers are configured but
 * loading is deferred (the caller or an oracle is responsible).
 *
 * The PSA key attributes pointer is stored as auxiliary data in the
 * descriptor for downstream use by crypto operations.
 *
 * @param[in]  attributes         PSA key attributes (type, bits, usage, lifetime).
 * @param[in]  key_buffer         Pointer to raw key material.
 * @param[in]  key_buffer_size    Size of @p key_buffer in bytes.
 * @param[out] out_key_descriptor Pointer to a key descriptor to populate.
 *
 * @retval PSA_SUCCESS              Key descriptor configured successfully.
 * @retval PSA_ERROR_INVALID_ARGUMENT  @p out_key_descriptor is NULL.
 * @retval PSA_ERROR_NOT_SUPPORTED  Key type or size is not supported by SGI.
 */
psa_status_t sgi_create_key_descriptor(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    mcuxClKey_Descriptor_t *out_key_descriptor);

/**
 * @brief Derive the raw ECC public key Q = d * G on-chip from a private scalar.
 *
 * In PSA an ECC key pair is represented only by the private scalar d. Several
 * accelerator paths (e.g. ECDSA verify with a key-pair handle) require the
 * public key Q. This helper computes Q = d * G entirely on the SGI/PKC crypto
 * accelerator via a secured scalar multiplication, avoiding the mbedTLS
 * software public-key export that is compiled out in accelerator-only builds.
 *
 * All Weierstrass curve families are supported (secp_r1, secp_k1,
 * brainpool_p_r1); the curve is resolved from @p attributes and its base point
 * G is taken from the ECC domain-parameter descriptor. This is the single
 * shared secure derivation used by both the opaque and transparent (PKC)
 * export paths.
 *
 * The public key is written to @p out_public_key as the raw concatenation
 * X || Y (big endian, no leading 0x04 uncompressed-format byte), each
 * coordinate being byteLen(p) bytes.
 *
 * The caller must provide an initialized session whose CPU/PKC workareas are
 * large enough for a secured scalar multiplication on the requested curve
 * (see MCUXCLECC_ARITHMETICOPERATION_SECURESCALARMULT_WACPU_SIZE /
 * _WAPKC_SIZE_640). The session PRNG must already be initialized.
 *
 * @param[in]  session               Initialized CL session (PRNG initialized).
 * @param[in]  attributes            PSA key attributes describing the key pair
 *                                   (used to resolve the ECC family and bits).
 * @param[in]  private_key           Pointer to the raw private scalar d.
 * @param[in]  private_key_size      Size of @p private_key in bytes.
 * @param[out] out_public_key        Buffer receiving the raw X || Y public key.
 * @param[in]  out_public_key_size   Capacity of @p out_public_key in bytes.
 * @param[out] out_public_key_length Number of bytes written to @p out_public_key.
 *
 * @retval PSA_SUCCESS              Public key derived successfully.
 * @retval PSA_ERROR_INVALID_ARGUMENT  A required pointer is NULL.
 * @retval PSA_ERROR_BUFFER_TOO_SMALL  @p out_public_key is too small.
 * @retval PSA_ERROR_NOT_SUPPORTED  The curve/key size is not supported.
 * @retval PSA_ERROR_GENERIC_ERROR  The on-chip derivation failed.
 */
psa_status_t sgi_ecc_derive_public_key(
    mcuxClSession_Handle_t session,
    const psa_key_attributes_t *attributes,
    const uint8_t *private_key,
    size_t private_key_size,
    uint8_t *out_public_key,
    size_t out_public_key_size,
    size_t *out_public_key_length);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_SGI_COMMON_KEY_MANAGEMENT_H */
