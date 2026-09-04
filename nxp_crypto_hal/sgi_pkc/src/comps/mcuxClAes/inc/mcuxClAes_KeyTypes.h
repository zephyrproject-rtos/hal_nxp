/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023, 2026 NXP                                            */
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
 * @file  mcuxClAes_KeyTypes.h
 * @brief Definition of supported key types in mcuxClAes component, see also @ref mcuxClKey component
 */

#ifndef MCUXCLAES_KEYTYPES_H_
#define MCUXCLAES_KEYTYPES_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <stdint.h>
#include <stdbool.h>

#include <mcuxClKey_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

/**
 * @defgroup mcuxClAes_KeyTypes mcuxClAes_KeyTypes
 * @brief Defines of supported key types of @ref mcuxClAes, see @ref mcuxClKey
 * @ingroup mcuxClAes
 * @{
 */

/**
 * @brief Key type structure for AES-128 based keys.
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Aes128;

/**
 * @brief Key type pointer for AES-128 based keys.
 * @implements{REQ_788207}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Aes128 = &mcuxClKey_TypeDescriptor_Aes128;
#ifdef MCUXCL_FEATURE_AES192

/**
 * @brief Key type structure for AES-192 based keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Aes192;

/**
 * @brief Key type pointer for AES-192 based keys.
 * @implements{REQ_788208}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Aes192 = &mcuxClKey_TypeDescriptor_Aes192;
#endif /* MCUXCL_FEATURE_AES192 */

/**
 * @brief Key type structure for AES-256 based keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Aes256;

/**
 * @brief Key type pointer for AES-256 based keys.
 * @implements{REQ_788209}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Aes256 = &mcuxClKey_TypeDescriptor_Aes256;

/**
 * @}
 */ /* mcuxClAes_KeyTypes */

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAES_KEYTYPES_H_ */
