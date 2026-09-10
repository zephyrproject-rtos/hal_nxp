/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023 NXP                                            */
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

/** @file  mcuxClMemory_Set.h
 *  @brief Memory header for set function.
 * This header exposes functions that enable using memory set functions.
 */

/**
 * @defgroup mcuxClMemory_Set mcuxClMemory_Set
 * @brief This function sets all bytes in a memory region to a specified value.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_SET_H_
#define MCUXCLMEMORY_SET_H_

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
 * Sets all bytes of a memory buffer to a specified value.
 * 
 * If the destination buffer is too small, i.e. if bufLength < length, 
 * (length-bufLength) is added to the Flow Protection token (see @ref mcuxCsslFlowProtection).
 *  
 * @param[out]  pDst       pointer to the buffer to be set.
 * @param[in]   val        byte value to be set.
 * @param[in]   length     size (in bytes) to be set.
 * @param[in]   bufLength  buffer size (if bufLength < length, only bufLength bytes are set).
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMemory_set)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_set (uint8_t *pDst, uint8_t val, size_t length, size_t bufLength);

/**********************************************
 * MACROS
 **********************************************/

/** Helper macro to call #mcuxClMemory_set with flow protection. */
#define MCUXCLMEMORY_FP_MEMORY_SET(pTarget, val, byteLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_set((uint8_t *) (pTarget), val, byteLen, byteLen))

/** Helper macro to call #mcuxClMemory_set with flow protection with buffer. */
#define MCUXCLMEMORY_FP_MEMORY_SET_WITH_BUFF(pTarget, val, byteLen, buffLen)  \
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_set((uint8_t *) (pTarget), val, byteLen, buffLen))


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_SET_H_ */

/**
 * @}
 */
