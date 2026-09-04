/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_S2XX_COMMON_COMPUTE_H
#define MCUX_PSA_S2XX_COMMON_COMPUTE_H

/** \file mcux_psa_s2xx_common_compute.h
 *
 * This file contains the implementation of the entry points for the
 * driver-specific functions for crypto operations
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_s2xx_common_init.h"

/** Ed25519 seems to have inconsistencies across implementations in which of
 *  these bitlengths is correct. We will mimic PSA in that we accept 255 and 256
 *  during validations, but we must pass 256 bit length to the S200,
 *  as per RFC 8032.
 */
#define IS_VALID_ED25519_BITLENGTH(key_bits) ((255u == (key_bits)) || (256u == (key_bits)))

#ifdef __cplusplus
extern "C" {
#endif

/*  AEAD  */

psa_status_t ele_s2xx_common_aead(const uint8_t *nonce, size_t nonce_length,
                                  const uint8_t *additional_data, size_t additional_data_length,
                                  const uint8_t *input, size_t input_size,
                                  uint8_t *output,
                                  uint8_t *tag, size_t *tag_length,
                                  sss_mode_t mode, sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg);

/*  MAC  */

psa_status_t ele_s2xx_common_mac(const uint8_t *input, size_t input_length,
                                 uint8_t *mac, size_t mac_size, size_t *mac_length,
                                 sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg);

/*  CIPHER  */

psa_status_t ele_s2xx_common_cipher(sss_sscp_object_t *sssKey,
                                    const uint8_t *iv, size_t iv_length,
                                    const uint8_t *input, uint8_t *output,
                                    size_t input_length,
                                    sss_algorithm_t ele_algo, sss_mode_t mode);

/*  ASYMMETRIC  */

psa_status_t ele_s2xx_common_sign_digest(uint8_t *digest, size_t digest_len,
                                         uint8_t *signature, size_t *signature_len,
                                         sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg);

psa_status_t ele_s2xx_common_verify_digest(uint8_t *digest, size_t digest_len,
                                           uint8_t *signature, size_t signature_len,
                                           sss_sscp_object_t *sssKey, sss_algorithm_t ele_alg);

/*  KEY AGREEMENT  */

psa_status_t ele_s2xx_common_key_agreement(sss_sscp_object_t *sssKey,
                                           sss_sscp_object_t *sssKey_peer,
                                           sss_sscp_object_t *sssKey_shared,
                                           uint8_t *shared_secret,
                                           size_t shared_secret_size,
                                           size_t *shared_secret_length,
                                           sss_algorithm_t ele_alg);

/* UTILITIES */

psa_status_t is_fw_loaded(void);

int ele_s2xx_util_ct_memcmp(const void *a,
                            const void *b,
                            size_t n);

/*!
 * Based on bit size of an ECC key, return the byte size of the private part.
 */
size_t ele_s2xx_get_ecc_private_key_size(size_t key_bits);

/*!
 * Based on bit size of an ECC key, return the byte size of the public part.
 */
size_t ele_s2xx_get_ecc_public_key_size(size_t key_bits);

/*!
 * Based on bit size of an ECC key, return the byte size of the full keypair.
 */
size_t ele_s2xx_get_ecc_keypair_size(size_t key_bits);

psa_status_t translate_psa_ecc_family_to_ele_cipher_type(const psa_key_attributes_t *attributes,
                                                         sss_cipher_type_t *cipher_type);

psa_status_t translate_psa_algorithm_to_ele_key_property(psa_algorithm_t alg,
                                                         sss_sscp_key_property_t *prop);

/*!
 * An all-in-one translation function for S200.
 *
 * NOTE: May only be comfortably used for opaque key locations due to PSA's
 *       handling of private ECC keys
 *       (see static psa_status_t transform_plain_key_to_elke_blob()).
 */
psa_status_t ele_s2xx_get_algo_keyprop(const psa_key_attributes_t *attributes,
                                       sss_sscp_key_property_t *s2xx_algo_prop,
                                       sss_key_part_t *s2xx_key_part,
                                       sss_cipher_type_t *s2xx_cipher_type,
                                       size_t *allocation_size);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_S2XX_COMMON_COMPUTE_H */
