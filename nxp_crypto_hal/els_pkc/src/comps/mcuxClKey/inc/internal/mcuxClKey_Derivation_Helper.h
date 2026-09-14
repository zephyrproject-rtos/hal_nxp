/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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
 * @file  mcuxClKey_Derivation_Helper.h
 * @brief Internal helper constants and functions for the KDF algorithms
 */

#ifndef MCUXCLKEY_DERIVATION_HELPER_H_
#define MCUXCLKEY_DERIVATION_HELPER_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClKey_Types_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Inline functions for proper type casts */

/**
 * @brief Cast a pointer to word-aligned data to a pointer to the mcuxClKeyDerivation_WorkArea_t type.
 *
 * @param pWa    The pointer to cast to a proper Wa type. Must be aligned. Must point to an area of enough size.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_castToKeyDerivationWorkarea)
static inline mcuxClKeyDerivation_WorkArea_t* mcuxClKey_castToKeyDerivationWorkarea(uint32_t* pWa)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClKeyDerivation_WorkArea_t*) pWa;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

/**
 * @brief Cast a pointer to word-aligned data to a pointer to the mcuxClKey_DerivationMode_t type.
 *
 * @param pMode   The pointer to cast to a proper derivationMode type. Must be aligned.
 *                Must point to an area of enough size, see @ref MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_castToKeyDerivationMode)
static inline mcuxClKey_DerivationMode_t* mcuxClKey_castToKeyDerivationMode(uint32_t* pMode)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClKey_DerivationMode_t*) pMode;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKEY_DERIVATION_HELPER_H_ */
