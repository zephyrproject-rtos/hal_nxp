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

/** @file  mcuxClOsccaCipherModes_Internal_Types.h
 *  @brief Internal type definitions for the mcuxClOsccaCipherModes component
 */

#ifndef MCUXCLOSCCACIPHERMODES_INTERNAL_TYPES_H_
#define MCUXCLOSCCACIPHERMODES_INTERNAL_TYPES_H_

#include <stddef.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession.h>
#include <mcuxClCipher.h>
#include <mcuxClPadding.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <internal/mcuxClCipher_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef MCUXCL_FEATURE_CIPHERMODES_SM4
#define MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_ECB 0x00U
#define MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CBC 0x01U
#define MCUXCLOSCCACIPHERPARAM_ALGORITHM_SM4_CTR 0x02U
#define MCUXCLOSCCACIPHER_ENCRYPT  (MCUXCLOSCCASM4_ENCRYPT)
#define MCUXCLOSCCACIPHER_DECRYPT  (MCUXCLOSCCASM4_DECRYPT)

/**
 * @brief Cipher context structure for SM4 modes
 *
 * This structure is used to store the information about the current operation
 * and the relevant internal SM4 state.
 */
typedef struct mcuxClOsccaCipherModes_Context_Sm4
{
  mcuxClCipher_Context_t   common;

  uint32_t roundKeys[128];
  uint8_t  state[3][MCUXCLOSCCASM4_BLOCK_SIZE];     ///< state/intermediate result of the cipher operation
  uint32_t out;                                      ///< out index in state buffer
  uint32_t in;                                       ///< in index in state buffer
  uint32_t iv;                                       ///< iv index in state buffer
} mcuxClOsccaCipherModes_Context_Sm4_t;

/**
 * @brief Cipher mode algorithm descriptor structure for SM4 algorithms
 *
 * This structure captures all the information that the Cipher interfaces need
 * to know about SM4 Cipher mode algorithm.
 */
typedef struct mcuxClCipherModes_AlgorithmDescriptor_SM4
{
  mcuxClPadding_addPaddingMode_t  addPadding;
  uint32_t                       protection_token_addPadding;
  uint32_t                       mode;
  uint32_t                       direction;
  uint32_t                       blockLength;
  uint32_t                       granularity;
} mcuxClCipherModes_AlgorithmDescriptor_SM4_t;

/**
 * @brief Cipher mode algorithm type for SM4 algorithms
 *
 * This type is used to refer to SM4 Cipher mode algorithm.
 */
typedef const mcuxClCipherModes_AlgorithmDescriptor_SM4_t * const mcuxClCipherModes_Algorithm_SM4_t;


#endif /* MCUXCL_FEATURE_CIPHERMODES_SM4 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCACIPHERMODES_INTERNAL_TYPES_H_ */
