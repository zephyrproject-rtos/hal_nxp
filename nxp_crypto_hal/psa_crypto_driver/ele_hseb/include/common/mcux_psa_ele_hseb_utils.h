/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_UTILS_H
#define MCUX_PSA_ELE_HSEB_UTILS_H

/** \file mcux_psa_ele_hseb_utils.h
 *
 * This file contains the declaration of the entry points associated
 * with common utility functions utilized by the ELE HSEB PSA port driver.
 *
 * \note This header should not be included by ele_hseb.h, as it is internal
 *       only.
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "psa/crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief HSE bool_t is typedef'd to uint8_t; takes care of bool-to-bool_t conversion */
#define HSE_BOOL_TO_UINT(bool_val) ((bool_val) ? 1u   : 0u)

/**
 * \brief Given a chunk size, an already used chunk length and some input size,
 *        return the remainder of the input length that does not fit into chunk
 *
 * \param[in] chunk_size        Size of the chunk buffer
 * \param[in] chunk_used_length Already used length of the buffer
 * \param[in] input_length      Length of the input to be moved into the buffer
 *
 * \retval Byte length of overflowing (i.e. not moved) input if it were moved
 *         to the buffer
 */
size_t ele_hseb_get_chunk_overflow(size_t chunk_size,
                                   size_t chunk_used_length,
                                   size_t input_length);

/**
 * \brief Unprocessed chunk management for multipart operations
 *
 * Takes the \ref chunk buffer with its parameters and moves as much
 * of the \ref input as possible. If the \ref input_length to be moved is
 * longer than the available size of the \ref chunk, the overflow is returned
 * in \ref overflow.
 *
 * \param[in,out] chunk         The chunk buffer
 * \param[in]     chunk_size    Size of the chunk buffer
 * \param[in,out] chunk_length  Already used length of the buffer as input,
 *                              and the resulting length of the chunk as
 *                              output
 * \param[in]     input         Input to be moved to the chunk buffer
 * \param[in]     input_length  Length of the input to be moved into the
 *                              buffer
 * \param[out]    is_chunk_full Flag whether the chunk buffer is full
 * \param[out]    overflow      Byte length of input not moved to the chunk
 *
 * \retval Byte length of the input that has been moved to the chunk buffer
 */
size_t ele_hseb_manage_chunk(uint8_t *chunk,
                             size_t chunk_size,
                             size_t *chunk_length,
                             const uint8_t *input,
                             size_t input_length,
                             bool *is_chunk_full,
                             size_t *overflow);

/**
 * \brief Validate if MAC length is supported for a given key and algorithm
 *
 * Takes into account truncation and the key type to determine if the MAC
 * length is directly supported by HSEB for the given algorithm.
 *
 * \note This function expects that the algorithm support itself was already
 * validated.
 *
 * \param[in] attributes Key attributes
 * \param[in] alg        MAC algorithm
 *
 * \retval true if the MAC length is supported, false otherwise
 */
bool is_mac_length_supported(const psa_key_attributes_t *attributes,
                             psa_algorithm_t alg);

/**
 * \brief Validate if the key size is supported for a given MAC key type.
 *
 * Checks whether \p key_bits is a valid and supported key size for the
 * specified \p key_type when used in a MAC operation on HSE-B. For example,
 * verifies that an HMAC key length falls within the range accepted by the
 * hardware.
 *
 * \param[in] key_type PSA key type.
 * \param[in] key_bits Key size in bits to validate.
 *
 * \retval true if the key size is supported for the given type, false otherwise.
 */
bool is_mac_key_size_supported(psa_key_type_t key_type, size_t key_bits);

/**
 * \brief Read an HSE-B key handle from an opaque key buffer.
 *
 * Deserialises the \c hseKeyHandle_t value previously stored by
 * \ref ele_hseb_write_key_handle_to_buffer from the first
 * \c sizeof(hseKeyHandle_t) bytes of \p key_buffer.
 *
 * \param[in]  key_buffer      Opaque key buffer containing the serialised
 *                             key handle.
 * \param[out] hseb_key_handle Destination for the deserialised handle.
 */
void ele_hseb_read_key_handle_from_buffer(const uint8_t *key_buffer,
                                          hseKeyHandle_t *hseb_key_handle);

/**
 * \brief Write an HSE-B key handle into an opaque key buffer.
 *
 * Serialises \p hseb_key_handle into the first \c sizeof(hseKeyHandle_t)
 * bytes of \p key_buffer and sets \p key_buffer_length accordingly. This is
 * the counterpart to \ref ele_hseb_read_key_handle_from_buffer and is called
 * after a successful key generation or import to record the allocated slot
 * handle for the PSA core.
 *
 * \param[out] key_buffer        Buffer to receive the serialised key handle.
 * \param[out] key_buffer_length Set to \c sizeof(hseKeyHandle_t) on return.
 * \param[in]  hseb_key_handle   Handle to serialise into \p key_buffer.
 */
void ele_hseb_write_key_handle_to_buffer(uint8_t *key_buffer,
                                         size_t *key_buffer_length,
                                         const hseKeyHandle_t *hseb_key_handle);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_UTILS_H */
