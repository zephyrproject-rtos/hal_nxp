/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClMemory_Copy_Reversed.h
 *  @brief Memory header for reversed copy functions.
 * This header exposes functions that enable using memory reversed copy function.
 */

/**
 * @defgroup mcuxClMemory_Copy_Reversed mcuxClMemory_Copy_Reversed
 * @brief This function copies a memory region from @p src to @p dst reversely.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_COPY_REVERSED_H_
#define MCUXCLMEMORY_COPY_REVERSED_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * Copies a memory buffer to another location reversely.
 *
 * If the destination buffer is too small, i.e. if bufLength < length,
 * then only bufLength bytes are copied reversely.
 *
 * @param[out] pDst        pointer to the buffer to be copied to.
 * @param[in]  pSrc        pointer to the buffer to copy.
 * @param[in]  length      size (in bytes) to be copied.
 * @param[in]  bufLength   buffer size (if bufLength < length, only bufLength bytes are copied reversely).
 *
 */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMemory_copy_reversed)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_copy_reversed (uint8_t *pDst, uint8_t const *pSrc, size_t length, size_t bufLength);


/**********************************************
 * MACROS
 **********************************************/

/** Helper macro to call #mcuxClMemory_copy_reversed with flow protection. */
#define MCUXCLMEMORY_FP_MEMORY_COPY_REVERSED(pTarget, pSource, byteLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed((uint8_t *) (pTarget), (const uint8_t *) (pSource), byteLen, byteLen))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_COPY_REVERSED_H_ */

/**
 * @}
 */
