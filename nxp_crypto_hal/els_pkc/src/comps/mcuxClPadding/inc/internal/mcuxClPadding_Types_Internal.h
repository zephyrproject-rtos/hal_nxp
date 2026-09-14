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

/** @file  mcuxClPadding_Types_Internal.h
 *  @brief Internal type definitions for the mcuxClPadding component
 */

#ifndef MCUXCLPADDING_TYPES_INTERNAL_H_
#define MCUXCLPADDING_TYPES_INTERNAL_H_

#include <stdint.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClPadding_Functions_Internal.h>

#include <mcuxClPadding_Types.h>
#include <mcuxClPadding_Constants.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Function type for a padding function
 *
 * A padding function padds the last block of a message. It will copy the incomplete last
 * block of the message @p pIn into the output buffer @p pOut and apply padding to it.
 * The function will return an error in case the input block does not meet the requirements
 * for the padding mode.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClPadding_addPaddingMode_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) (*mcuxClPadding_addPaddingMode_t)(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
));

/**
 * @brief Function type for a padding removal function
 *
 * A padding removal function checks and removes padding in the input @p pIn, if possible,
 * and only copies the remaining bytes of the block to the output buffer @p pOut.
 * The function will return an error in case the input block does not meet the requirements
 * for the padding mode, or NOT_OK if the padding is incorrect.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClPadding_removePaddingMode_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) (*mcuxClPadding_removePaddingMode_t)(
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength
));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPADDING_TYPES_INTERNAL_H_ */
