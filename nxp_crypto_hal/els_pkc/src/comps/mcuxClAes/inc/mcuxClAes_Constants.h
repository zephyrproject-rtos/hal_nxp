/*--------------------------------------------------------------------------*/
/* Copyright 2022 NXP                                                       */
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

/** @file  mcuxClAes_Constants.h
 *  @brief Constants for use with the mcuxClAes component */

#ifndef MCUXCLAES_CONSTANTS_H_
#define MCUXCLAES_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClKey_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClAes_Constants mcuxClAes_Constants
 * @brief Defines of constants associated with @ref mcuxClAes component
 * @ingroup mcuxClAes
 * @{
 */

/* Error codes */
#define MCUXCLAES_STATUS_ERROR              ((mcuxClAes_Status_t) 0x0FF95330u)
#define MCUXCLAES_STATUS_OK                 ((mcuxClAes_Status_t) 0x0FF92E03u)

/* Block size */
#define MCUXCLAES_BLOCK_SIZE                (16u)                                    ///< AES block size in bytes
#define MCUXCLAES_BLOCK_SIZE_IN_WORDS       (MCUXCLAES_BLOCK_SIZE / sizeof(uint32_t)) ///< AES block size in words

/* Key sizes */
#define MCUXCLAES_AES128_KEY_SIZE           (MCUXCLKEY_SIZE_128)            ///< AES-128 key size in bytes
#define MCUXCLAES_AES128_KEY_SIZE_IN_WORDS  (MCUXCLKEY_SIZE_128_IN_WORDS)   ///< AES-128 key size in words
#define MCUXCLAES_AES192_KEY_SIZE           (MCUXCLKEY_SIZE_192)            ///< AES-192 key size in bytes
#define MCUXCLAES_AES192_KEY_SIZE_IN_WORDS  (MCUXCLKEY_SIZE_192_IN_WORDS)   ///< AES-192 key size in words
#define MCUXCLAES_AES256_KEY_SIZE           (MCUXCLKEY_SIZE_256)            ///< AES-256 key size in bytes
#define MCUXCLAES_AES256_KEY_SIZE_IN_WORDS  (MCUXCLKEY_SIZE_256_IN_WORDS)   ///< AES-256 key size in words

/**@}*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAES_CONSTANTS_H_ */
