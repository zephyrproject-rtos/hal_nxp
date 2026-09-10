/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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

/** @file  mcuxClMemory_Xor.h
 *  @brief Memory header for xor functions.
 * This header exposes functions that enable using memory xor function.
 */

/**
 * @defgroup mcuxClMemory_xor mcuxClMemory_xor
 * @brief This function performs xor between @p src1 and @p src2, and saves result to @p dst.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_XOR_H_
#define MCUXCLMEMORY_XOR_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClMemory_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * Perform xor for 2 memory buffers.
 *
 * Operation in place is allowed - one of the input buffer can also be the output buffer.
 *
 *
 * @param[out] pDst        pointer to the destination buffer.
 * @param[in]  pSrc1       pointer to the first source buffer.
 * @param[in]  pSrc2       pointer to the second source buffer.
 * @param[in]  length      size (in bytes) to be operated
 * @param[in]  bufLength   buffer size (if bufLength < length, only bufLength bytes are operated).
 *
 */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMemory_xor)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_xor(uint8_t *pDst, const uint8_t *pSrc1, const uint8_t *pSrc2, uint32_t length, size_t bufLength);


/**********************************************
 * MACROS
 **********************************************/

/** Helper macro to call #mcuxClMemory_xor with flow protection. */
#define MCUXCLMEMORY_FP_MEMORY_XOR(pDst, pSrc1, pSrc2, length)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_xor(pDst, pSrc1, pSrc2, length, length))

/** Helper macro to call #mcuxClMemory_xor with flow protection with buffer. */
#define MCUXCLMEMORY_FP_MEMORY_XOR_WITH_BUFF(pDst, pSrc1, pSrc2, length, bufLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_xor(pDst, pSrc1, pSrc2, length, bufLen))


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_XOR_H_ */

/**
 * @}
 */
