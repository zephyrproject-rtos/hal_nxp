/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @file  mcuxClPadding_Functions_Internal.h
 * @brief Functions of the padding component.
 */

#ifndef MCUXCLPADDING_FUNCTIONS_INTERNAL_H
#define MCUXCLPADDING_FUNCTIONS_INTERNAL_H

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClPadding_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif



/**
 * @brief No-padding function, which adds no padding at all
 * @api
 *
 * This function throws an error if @p lastBlockLength is anything other than zero,
 * and does nothing (adding no padding) and returns OK otherwise.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block that will
 *                              be padded.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn. Must be 0.
 * @param[in]  totalInputLength Total number of plaintext/ciphertext bytes.
 *
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_addPadding_None, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_None(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief No-padding removal function, which removes no padding
 * @api
 *
 * This function copies @p blockLength bytes to the output buffer.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block which needs
 *                              the padding removed.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn. Must be equal to @p blockLength.
 * @param[out] pOut             Pointer to the output buffer where the data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_removePadding_None, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_removePadding_None(
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Default adding removal function.
 * @api
 *
 * This function copies @p lastBlockLength bytes to @p pOut.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block which needs
 *                              the padding removed.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes in
 *                              @p pIn. Must be greater than 0 and less than or equal to @p blockLength.
 * @param[out] pOut             Pointer to the output buffer where the data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_removePadding_Default)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_removePadding_Default(
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Zero-padding function, which pads a block with zeroes in the end.
 * @api
 *
 * This function copies @p lastBlockLength bytes to @p pOut and fills the
 * remainder with zeroes.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block that will
 *                              be padded.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn. Must be smaller than @p blockLength.
 * @param[in]  totalInputLength Total number of plaintext/ciphertext bytes.
 *
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_addPadding_ISO9797_1_Method1, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_ISO9797_1_Method1(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief ISO/IEC 9797-1 padding method 2 function.
 * @api
 *
 * This function adds a single bit with value 1 after the data and fills the
 * remaining block with zeroes.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block that will
 *                              be padded.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn. Must be smaller than @p blockLength.
 * @param[in]  totalInputLength Total number of plaintext/ciphertext bytes.
 *
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_addPadding_ISO9797_1_Method2, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_ISO9797_1_Method2(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief ISO/IEC 9797-1 padding method 2 function.
 * @api
 *
 * This function adds a single bit with value 1 after the data and fills the
 * remaining block with zeroes for CMAC and XCBCMAC mode using.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block that will
 *                              be padded.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn. Must be smaller than or equal to @p blockLength.
 * @param[in]  totalInputLength Total number of plaintext/ciphertext bytes.
 *
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_MAC_ISO9797_1_Method2(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);
/**
 * @brief PKCS7 padding function.
 * @api
 *
 * This function adds PKCS7 padding according to rfc2315, it adds the remaning
 * bytes in the block with the value equal to the total number of added bytes.
 * The random masking byte depends on a call to @ref mcuxClRandom_ncInit.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block that will
 *                              be padded.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn. Must be smaller than @p blockLength.
 * @param[in]  totalInputLength Total number of plaintext/ciphertext bytes.
 *
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_addPadding_PKCS7, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_PKCS7(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Random-padding function, which pads a block with random bytes in the end.
 * @api
 *
 * This function copies @p lastBlockLength bytes to @p pOut and fills the
 * remainder with random bytes.
 * The random bytes depend on a call to @ref mcuxClRandom_ncInit.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block that will
 *                              be padded.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes in
 *                              @p pIn. Must be greater than 0 and less than or equal to @p blockLength.
 * @param[in]  totalInputLength Total number of plaintext/ciphertext bytes.
 *
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_addPadding_Random, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_Random(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Padding removal function for block ciphers in streaming mode.
 * @api
 *
 * This function copies @p lastBlockLength bytes to @p pOut, as streaming
 * modes do not have any padding to remove.
 *
 * @param[in]  blockLength      The block length of the used block cipher.
 *
 * @param[in]  pIn              Pointer to the input buffer of the block which needs
 *                              the padding removed.
 * @param[in]  lastBlockLength  Number of bytes in the last block, i.e. the number of bytes in
 *                              @p pIn. Must be greater than 0 and less than or equal to @p blockLength.
 * @param[out] pOut             Pointer to the output buffer where the data
 *                              needs to be written.
 * @param[out] pOutLength       Length of the data written to @p pOut.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPadding_removePadding_Stream, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_removePadding_Stream(
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPADDING_FUNCTIONS_INTERNAL_H */

