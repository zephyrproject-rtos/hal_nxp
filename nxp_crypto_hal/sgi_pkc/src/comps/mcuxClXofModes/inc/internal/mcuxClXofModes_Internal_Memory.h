/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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

/** @file  mcuxClXofModes_Internal_Memory.h
 *  @brief Internal memory consumption definitions of the mcuxClXofModes component
 */

#ifndef MCUXCLXOFMODES_INTERNAL_MEMORY_H_
#define MCUXCLXOFMODES_INTERNAL_MEMORY_H_

#include <internal/mcuxClHashModes_Internal_Memory.h>
#include <internal/mcuxClXof_Internal.h>

/* CPU WA size for the Xof Shake */
#if defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256)
#define MCUXCLXOF_INTERNAL_WACPU_SIZE_C_SHAKE        MCUXCLCORE_MAX (MCUXCLCORE_MAX(MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA3_ONESHOT, \
                                                                    MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA3_PROCESS), \
                                                                MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA3_FINISH)
#else
#define MCUXCLXOF_INTERNAL_WACPU_SIZE_C_SHAKE (4u)
#endif /* defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256) */

#define MCUXCLXOF_INTERNAL_WACPU_SIZE_LTC_SHAKE (4u)

#define MCUXCLXOF_INTERNAL_WACPU_SIZE_SECSHAKE (4u)

#define MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE   (MCUXCLCORE_MAX(MCUXCLXOF_INTERNAL_WACPU_SIZE_C_SHAKE,       \
                                              MCUXCLCORE_MAX(MCUXCLXOF_INTERNAL_WACPU_SIZE_LTC_SHAKE,       \
                                                            MCUXCLXOF_INTERNAL_WACPU_SIZE_SECSHAKE)))

/* Context size */
#if defined(MCUXCL_FEATURE_XOF_C_SHAKE_128)
#define MCUXCLXOFMODES_SHAKE128_CONTEXT_SIZE_INTERNAL (sizeof(mcuxClXof_ContextDescriptor_t) + MCUXCLHASHMODES_SHAKE128_CONTEXT_SIZE_INTERNAL)
#else
#define MCUXCLXOFMODES_SHAKE128_CONTEXT_SIZE_INTERNAL (4u)
#endif /* defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_LTC_SHAKE_128) */

#if defined(MCUXCL_FEATURE_XOF_C_SHAKE_256)
#define MCUXCLXOFMODES_SHAKE256_CONTEXT_SIZE_INTERNAL (sizeof(mcuxClXof_ContextDescriptor_t) + MCUXCLHASHMODES_SHAKE256_CONTEXT_SIZE_INTERNAL)
#else
#define MCUXCLXOFMODES_SHAKE256_CONTEXT_SIZE_INTERNAL (4u)
#endif /* defined(MCUXCL_FEATURE_XOF_C_SHAKE_256) || defined(MCUXCL_FEATURE_XOF_LTC_SHAKE_256) */

#define MCUXCLXOFMODES_SECSHAKE128_CONTEXT_SIZE_INTERNAL (4u)

#define MCUXCLXOFMODES_SECSHAKE256_CONTEXT_SIZE_INTERNAL (4u)

#define MCUXCLXOFMODES_CONTEXT_MAX_SIZE_INTERNAL                                                   \
                  MCUX_CSSL_ANALYSIS_START_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()    \
                  (MCUXCLCORE_MAX(MCUXCLXOFMODES_SHAKE128_CONTEXT_SIZE_INTERNAL,                    \
                   MCUXCLCORE_MAX(MCUXCLXOFMODES_SHAKE256_CONTEXT_SIZE_INTERNAL,                    \
                   MCUXCLCORE_MAX(MCUXCLXOFMODES_SECSHAKE128_CONTEXT_SIZE_INTERNAL,                 \
                                MCUXCLXOFMODES_SECSHAKE256_CONTEXT_SIZE_INTERNAL))))               \
                  MCUX_CSSL_ANALYSIS_STOP_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()

#endif /* MCUXCLXOFMODES_INTERNAL_MEMORY_H_ */
