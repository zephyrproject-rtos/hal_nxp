/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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

/** @file  mcuxClPadding_Types_Internal.h
 *  @brief Internal type definitions for the mcuxClPadding component
 */

#ifndef MCUXCLPADDING_TYPES_INTERNAL_H_
#define MCUXCLPADDING_TYPES_INTERNAL_H_

#include <stdint.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClPadding_Functions_Internal.h>

#include <mcuxClBuffer.h>
#include <mcuxClPadding_Types.h>
#include <mcuxClPadding_Constants.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Function type for a padding functions
 *
 * A padding function padds the last block of a message. If padding is needed, it will copy
 * the incomplete last block of the message @p pIn into the output buffer @p pOut and
 * apply padding to it.
 * The function will trigger an error in case the input block does not meet the requirements
 * for the padding mode.
 *
 * @param      blockLength      The block length of the used block cipher.
 * @param[in]  pIn              Pointer to the input buffer of the block that will be padded.
 * @param      inOffset         Offset in bytes for the input buffer.
 * @param      lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn that contain the last block.
 * @param      totalInputLength Total number of plaintext bytes.
 * @param[out] pOut             Pointer to the output buffer where the padded data
 *                              will be written.
 * @param[out] pOutLength       Length of the data written to @p pOut, including the padding.
 *                              This will either be 0 or @p blockLength.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClPadding_addPaddingMode_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClPadding_addPaddingMode_t)(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
));

/**
 * @brief Function type for a padding removal functions
 *
 * A padding removal function checks and removes padding in the input @p pIn, if possible,
 * and only copies the remaining bytes of the block to the output buffer @p pOut.
 * The function will trigger an error in case the input block does not meet the requirements
 * for the padding mode, or NOT_OK if the padding is incorrect.
 *
 * @param      blockLength      The block length of the used block cipher.
 * @param[in]  pIn              Pointer to the input buffer of the block which needs
 *                              the padding removed.
 * @param      lastBlockLength  Number of bytes in the last block, i.e. the number of bytes
 *                              in @p pIn that contain the last block (including padding).
 * @param[out] pOut             Pointer to the output buffer where the data
 *                              will be written.
 * @param      outOffset        Offset in bytes for the output buffer.
 * @param[out] pOutLength       Length of the data written to @p pOut.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClPadding_removePaddingMode_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClPadding_removePaddingMode_t)(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength
));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPADDING_TYPES_INTERNAL_H_ */
