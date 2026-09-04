/*--------------------------------------------------------------------------*/
/* Copyright 2020, 2022-2025 NXP                                            */
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

/** @file  mcuxClAes_KeyTypes.c
 *  @brief Instantiation of the key types supported by the mcuxClAes component. */

#include <mcuxClAes.h>
#include <mcuxClKey.h>
#include <mcuxClCore_Platform.h>

#include <internal/mcuxClAes_Internal_Constants.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>

// fully supported AES key types

const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Aes128                 = {.algoId = MCUXCLKEY_ALGO_ID_AES + MCUXCLKEY_ALGO_ID_SYMMETRIC_KEY, .size = MCUXCLAES_AES128_KEY_SIZE, .info = NULL, .plainEncoding = &mcuxClKey_EncodingDescriptor_Plain};


const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Aes256                 = {.algoId = MCUXCLKEY_ALGO_ID_AES + MCUXCLKEY_ALGO_ID_SYMMETRIC_KEY, .size = MCUXCLAES_AES256_KEY_SIZE, .info = NULL, .plainEncoding = &mcuxClKey_EncodingDescriptor_Plain};


#ifdef MCUXCL_FEATURE_AES192

// AES key types supported by key from memory only
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Aes192                 = {.algoId = MCUXCLKEY_ALGO_ID_AES + MCUXCLKEY_ALGO_ID_SYMMETRIC_KEY, .size = MCUXCLAES_AES192_KEY_SIZE, .info = NULL, .plainEncoding = &mcuxClKey_EncodingDescriptor_Plain};

#endif /* MCUXCL_FEATURE_AES192 */
