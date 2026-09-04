/*--------------------------------------------------------------------------*/
/* Copyright 2020-2022, 2024 NXP                                            */
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
 * @file  mcuxClKey_EncodingMechanisms.h
 * @brief Provide API of the mcuxClKey_Encoding functions
 */

#ifndef MCUXCLKEY_ENCODINGMECHANISMS_H_
#define MCUXCLKEY_ENCODINGMECHANISMS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClKey_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

/**
 * @defgroup mcuxClKey_EncodingMechanisms mcuxClKey_EncodingMechanisms
 * @brief Mechanisms used by the Key operations.
 * @ingroup mcuxClKey
 * @{
 */

#if 0
/**
 * @brief Key encoding descriptor for using XOR masking
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClKey_EncodingDescriptor_XorMasked;

/**
 * @brief Key encoding using XOR masking
 */
static const mcuxClKey_Encoding_t mcuxClKey_Encoding_XorMasked =
  &mcuxClKey_EncodingDescriptor_XorMasked;
#endif

/** @} */

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKEY_ENCODINGMECHANISMS_H_ */

