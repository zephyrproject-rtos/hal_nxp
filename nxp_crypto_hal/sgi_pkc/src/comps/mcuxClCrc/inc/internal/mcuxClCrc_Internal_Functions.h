/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

/**
 * @file  mcuxClCrc_Internal_Functions.h
 * @brief CRC internal functions of the mcuxClCrc component
 */

#ifndef MCUXCLCRC_INTERNAL_FUNCTIONS_H_
#define MCUXCLCRC_INTERNAL_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClCrc_Internal_Constants.h>
#include <internal/mcuxClSession_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClCrc_Internal_Functions mcuxClCrc_Internal_Functions
 * @brief Driver layer of the @ref mcuxClCrc component
 * @ingroup mcuxClCrc
 * @{
 */

/**
 * @defgroup mcuxClCrc_Internal_Functions mcuxClCrc_Internal_Functions
 * @brief Defines the CRC internal functions of component @ref mcuxClCrc
 * @ingroup mcuxClCrc_Internal_Functions
 * @{
 */

/**
 * @brief Compute 16-bit CRC checksum of a given byte string with a given seed
 *        and the platform-specified 16-bit CRC polynomial
 *
 * @param[in] pBytes  pointer to the byte string
 * @param     length  length (in bytes) of the string
 * @param     seed16  16-bit seed
 *
 * @post
 *  - Data Integrity: Expunge(pBytes + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  16-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Internal_updateCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Internal_updateCRC16(const uint8_t *pBytes, uint32_t length, uint16_t seed16);

#ifdef MCUXCL_FEATURE_INTERNAL_CRC_BUFFER
/**
 * @brief Compute 16-bit CRC checksum of a given byte string with a given seed
 *        and the platform-specified 16-bit CRC polynomial
 *
 * @param[in] bufSrc  Pointer to the buffer that contains the string.
 * @param     length  length (in bytes) of the string
 * @param     seed16  16-bit seed
 *
 * @post
 *  -  Data Integrity: Expunge(bufSrc + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  16-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Internal_updateCRC16_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Internal_updateCRC16_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length, uint16_t seed16);
#endif /* MCUXCL_FEATURE_INTERNAL_CRC_BUFFER */

/**
 * @brief Identical as mcuxClCrc_Internal_updateCRC16 except, the CRC module has to be preconfigured by the caller.
 *
 * @param[in] pBytes  pointer to the byte string
 * @param     length  length (in bytes) of the string
 *
 * @pre
 *  - The CRC module is already configured.
 * @post
 *  - Data Integrity: Expunge(pBytes + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  16-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Drv_updateCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Drv_updateCRC16(const uint8_t *pBytes, uint32_t length);

#ifdef MCUXCL_FEATURE_INTERNAL_CRC_BUFFER
/**
 * @brief Identical as mcuxClCrc_Internal_updateCRC16 except, the CRC module has to be preconfigured by the caller.
 *
 * @param[in] bufSrc  Pointer to the buffer that contains the string.
 * @param     length  length (in bytes) of the string
 *
 * @pre
 *  - The CRC module is already configured.
 * @post
 *  - Data Integrity: Expunge(bufSrc + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  16-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Drv_updateCRC16_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Drv_updateCRC16_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length);
#endif /* MCUXCL_FEATURE_INTERNAL_CRC_BUFFER */

/**
 * @brief Compute 32-bit CRC checksum of a given byte string with a given seed
 *        and the platform-specified 32-bit CRC polynomial
 *
 * @param[in] pBytes  pointer to the byte string
 * @param     length  length (in bytes) of the string
 * @param     seed16  32-bit seed
 *
 * @post
 *  - Data Integrity: Expunge(pBytes + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  32-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Internal_updateCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Internal_updateCRC32(const uint8_t *pBytes, uint32_t length, uint32_t seed32);

#ifdef MCUXCL_FEATURE_INTERNAL_CRC_BUFFER
/**
 * @brief Compute 32-bit CRC checksum of a given byte string with a given seed
 *        and the platform-specified 32-bit CRC polynomial
 *
 * @param[in] bufSrc  Pointer to the buffer that contains the string.
 * @param     length  length (in bytes) of the string
 * @param     seed16  32-bit seed
 *
 * @post
 *  - Data Integrity: Expunge(bufSrc + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  32-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Internal_updateCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Internal_updateCRC32_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length, uint32_t seed32);
#endif /* MCUXCL_FEATURE_INTERNAL_CRC_BUFFER */

/**
 * @brief Identical as mcuxClCrc_Internal_updateCRC32 except, the CRC module has to be preconfigured by the caller.
 *
 * @param[in] pBytes  pointer to the byte string
 * @param     length  length (in bytes) of the string
 *
 * @pre
 *  - The CRC module is already configured.
 * @post
 *  - Data Integrity: Expunge(pBytes + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  32-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Drv_updateCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Drv_updateCRC32(const uint8_t *pBytes, uint32_t length);

#ifdef MCUXCL_FEATURE_INTERNAL_CRC_BUFFER
/**
 * @brief Identical as mcuxClCrc_Internal_updateCRC32_buffer except, the CRC module has to be preconfigured by the caller.
 *
 * @param[in] bufSrc  Pointer to the buffer that contains the string.
 * @param     length  length (in bytes) of the string
 *
 * @pre
 *  - The CRC module is already configured.
 * @post
 *  - Data Integrity: Expunge(bufSrc + length)
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #crcResult  32-bit CRC checksum  (without applying the output mask)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Drv_updateCRC32_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Drv_updateCRC32_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length);
#endif /* MCUXCL_FEATURE_INTERNAL_CRC_BUFFER */

/**
 * @brief Computes the CRC for a context struct (without the CRC value member) and saves it in the struct.
 *
 * @param[in,out]  pCtx            Pointer to the context struct (word-aligned).
 * @param          contextSize     Size of the context struct in bytes (including the CRC value member).
 *
 * @pre
 *  -  CRC member needs to be first member of a struct with size of 32 bits.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_computeContextCrc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_computeContextCrc(void* pCtx, uint32_t contextSize);

/**
 * @brief Verifies the CRC of a context struct.
 *
 * The function computes the CRC for a context struct (without the CRC value member) and checks if it is equal
 * to the saved CRC value within the struct.
 *
 * @param[in]  session         Session handle
 * @param[in]  pCtx            Pointer to the context struct (word-aligned).
 * @param      contextSize     Size of the context struct in bytes (including the CRC value member).
 *
 * @pre
 *  -  CRC member needs to be first member of a struct with size of 32 bits.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_verifyContextCrc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_verifyContextCrc(mcuxClSession_Handle_t session, void* pCtx, uint32_t contextSize);


/**
 * @}
 */ /* mcuxClCrc_Internal_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCRC_INTERNAL_FUNCTIONS_H_ */
