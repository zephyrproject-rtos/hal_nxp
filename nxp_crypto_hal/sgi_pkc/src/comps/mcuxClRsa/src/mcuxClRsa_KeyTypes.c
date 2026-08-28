/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClRsa_KeyTypes.c
 *  @brief Instantiation of the key types supported by the mcuxClRsa component. */

#include <mcuxCsslAnalysis.h>
#include <mcuxClKey_Constants.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <mcuxClRsa_KeyTypes.h>
#include <internal/mcuxClRsa_Internal_Types.h>


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_1024 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC, .size = MCUXCLKEY_SIZE_1024, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_2048 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC, .size = MCUXCLKEY_SIZE_2048, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_3072 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC, .size = MCUXCLKEY_SIZE_3072, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_4096 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC, .size = MCUXCLKEY_SIZE_4096, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain};
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_6144 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC, .size = MCUXCLKEY_SIZE_6144, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_8192 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC, .size = MCUXCLKEY_SIZE_8192, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain};
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/* TODO CLNS-15273: the condition of defined(MCUXCL_FEATURE_CIPHER_RSA_SWONLY) shall be removed after SIGNATURE_RSA_SIGN or CIPHER_RSA_DECRYPT is enabled for NCCL */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_1024 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN, .size = MCUXCLKEY_SIZE_1024, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_2048 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN, .size = MCUXCLKEY_SIZE_2048, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_3072 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN, .size = MCUXCLKEY_SIZE_3072, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_4096 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN, .size = MCUXCLKEY_SIZE_4096, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain};
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_6144 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN, .size = MCUXCLKEY_SIZE_6144, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_8192 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN, .size = MCUXCLKEY_SIZE_8192, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain};
#endif

const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_1024 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT, .size = MCUXCLKEY_SIZE_1024, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_2048 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT, .size = MCUXCLKEY_SIZE_2048, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_3072 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT, .size = MCUXCLKEY_SIZE_3072, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_4096 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT, .size = MCUXCLKEY_SIZE_4096, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_6144 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT, .size = MCUXCLKEY_SIZE_6144, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_8192 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT, .size = MCUXCLKEY_SIZE_8192, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_1024 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA, .size = MCUXCLKEY_SIZE_1024, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_2048 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA, .size = MCUXCLKEY_SIZE_2048, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_3072 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA, .size = MCUXCLKEY_SIZE_3072, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_4096 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA, .size = MCUXCLKEY_SIZE_4096, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_6144 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA, .size = MCUXCLKEY_SIZE_6144, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_8192 = {.algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA, .size = MCUXCLKEY_SIZE_8192, .info = NULL, .plainEncoding = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain};
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
