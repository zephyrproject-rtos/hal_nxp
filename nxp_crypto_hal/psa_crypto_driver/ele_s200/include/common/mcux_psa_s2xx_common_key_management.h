/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_S2XX_COMMON_KEY_MANAGEMENT_H
#define MCUX_PSA_S2XX_COMMON_KEY_MANAGEMENT_H

/** \file mcux_psa_s2xx_common_key_management.h
 *
 * This file contains the declaration of the entry points associated to
 * common S2XX key management procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"

#include "fsl_sss_mgmt.h"
#include "fsl_sss_sscp.h"
#include "fsl_sscp_mu.h"

#include "mcux_psa_s2xx_common_init.h"

/*! Size of the S200 die-unique key blob overhead added to the actual key. */
#define S200_BLOB_OVERHEAD (PSA_S200_NON_EL2GO_BLOB_OVERHEAD)

/*! A new S200 key object may use a random key ID. */
#define S200_KEY_ID_RANDOM (0u)

#ifdef __cplusplus
extern "C" {
#endif

psa_status_t ele_s2xx_import_key(const psa_key_attributes_t *attributes,
                                 const uint8_t *key_buffer,
                                 size_t key_buffer_size,
                                 sss_sscp_object_t *sssKey);

psa_status_t ele_s2xx_validate_blob_attributes(const psa_key_attributes_t *attributes,
                                               const uint8_t *psa_import_blob,
                                               size_t psa_import_blob_size);

psa_status_t ele_s2xx_set_key(sss_sscp_object_t *sssKey,
                              uint32_t key_id,
                              const uint8_t *key_buffer,
                              size_t key_buffer_size,
                              sss_key_part_t key_part,
                              sss_cipher_type_t cipher_type,
                              sss_sscp_key_property_t key_properties,
                              size_t allocation_size,
                              size_t key_bitlen);

psa_status_t ele_s2xx_get_key(sss_sscp_object_t *sssKey,
                              uint8_t *key_buffer,
                              size_t key_buffer_size,
                              size_t *key_buffer_length,
                              sss_key_part_t key_part,
                              size_t *key_bitlen);

psa_status_t ele_s2xx_get_ecc_public_key_from_private(sss_sscp_object_t *sssKey,
                                                      uint8_t *data,
                                                      size_t data_size,
                                                      size_t *data_length,
                                                      size_t *key_bitlen);


/** Erase and delete a key from the S200.
 *
 * The key is first erased and then the key object is deleted with keystore
 * defragmentation enabled.
 *
 * @note The caller should know if the key to be deleted is present in
 *       the keystore.
 *
 * @param sssKey pointer to a key object present in the S200.
 *
 * @retval PSA_SUCCESS.
 * @retval PSA_ERROR_HARDWARE_FAILURE if key object free fails.
 */
psa_status_t ele_s2xx_delete_key(sss_sscp_object_t *sssKey);

psa_status_t ele_s2xx_export_key(const psa_key_attributes_t *attributes,
                                 uint8_t *data,
                                 size_t data_size,
                                 size_t *data_length,
                                 sss_sscp_object_t *sssKey);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_S2XX_COMMON_KEY_MANAGEMENT_H */
