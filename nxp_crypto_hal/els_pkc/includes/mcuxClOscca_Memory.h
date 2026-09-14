/*--------------------------------------------------------------------------*/
/* Copyright 2016, 2021, 2023-2024 NXP                                      */
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
 *
 * @file:  mcuxClOscca_Memory.h
 * @brief: Macros for alignment memory
 *
 */

#ifndef MCUXCLOSCCA_MEMORY_H_
#define MCUXCLOSCCA_MEMORY_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLOSCCA_SIZE_ALIGN_OFFSET  (sizeof(uint32_t) - 1U)

#define mcuxClOscca_alignAddress(address) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("The resulting address is carefully calculated, the cast to a pointer-type is safe.") \
  ((uint8_t *)( (((uint32_t)(address)) + (sizeof(uint32_t) - 1U)) \
      & ((uint32_t)(~(sizeof(uint32_t) - 1U))) )) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

#define mcuxClOscca_alignSize(size) \
    ((uint32_t)(((uint32_t)(size)) + (sizeof(uint32_t) - 1U)) \
        & ((uint32_t)(~(sizeof(uint32_t) - 1U))) )

#define mcuxClOscca_alignAddressWithOffset(address, offset) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("The resulting address is carefully calculated, the cast to a pointer-type is safe.") \
  ((uint8_t *)( (((uint32_t)(address) + (uint32_t)(offset)) + (sizeof(uint32_t) - 1U)) \
      & ((uint32_t)(~(sizeof(uint32_t) - 1U))) )) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

#define mcuxClOscca_alignAddressToBoundary(address, boundary) \
  ((uint8_t *)( (((uint32_t)(address)) + (boundary - 1U)) \
      & ((uint32_t)(~(boundary - 1U))) ))

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOscca_FastSecureXor)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOscca_FastSecureXor(void *pTgt,
        void *pSrc1,
        void *pSrc2,
        uint32_t length);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOscca_switch_endianness)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOscca_switch_endianness(uint32_t *ptr, uint32_t length);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCA_MEMORY_H_ */
