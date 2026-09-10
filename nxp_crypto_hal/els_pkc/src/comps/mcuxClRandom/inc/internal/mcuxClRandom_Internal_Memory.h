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

/**
 * @file  mcuxClRandom_Internal_Memory.h
 * @brief Provides macros for usage and FP balancing of memory options depneding on the platform
 */

#ifndef MCUXCLRANDOM_INTERNAL_MEMORY_H_
#define MCUXCLRANDOM_INTERNAL_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <mcuxClMemory.h>
#define MCUXCLRANDOM_SECURECOPY(callerID, errorReturn, pTarget, pSource, length)                 \
    do{                                                                                         \
        MCUXCLMEMORY_FP_MEMORY_COPY(pTarget, pSource, length);                                   \
MCUX_CSSL_ANALYSIS_START_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()                       \
    } while(false)                                                                              \
MCUX_CSSL_ANALYSIS_STOP_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLRANDOM_SECURECLEAR(callerID, errorReturn, pTarget, length)                         \
    do{                                                                                         \
        MCUXCLMEMORY_FP_MEMORY_CLEAR(pTarget, length);                                           \
MCUX_CSSL_ANALYSIS_START_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()                       \
    } while(false)                                                                              \
MCUX_CSSL_ANALYSIS_STOP_PATTERN_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLRANDOM_FP_CALLED_SECURECOPY  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)

#define MCUXCLRANDOM_FP_CALLED_SECURECLEAR  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOM_INTERNAL_TYPES_H_ */
