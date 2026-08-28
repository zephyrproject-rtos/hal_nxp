/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxClFfdh_KeyTypes.c
 * @brief mcuxClFfdh: implementation of FFDH related key type descriptors
 */

#include <mcuxClKey.h>
#include <mcuxClFfdh.h>
#include <mcuxClFfdh_Types.h>

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClKey_Types_Internal.h>


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the key parameters.")

/* Key type structure for private and public FFDH key for RFC7919 ffdhe2048 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe2048_Pub  =
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PUBLIC_KEY,
  .size = MCUXCLFFDH_FFDHE2048_SIZE_PUBLICKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe2048,
  .plainEncoding = mcuxClFfdh_Encoding_PublicKey_Plain
};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe2048_Priv = 
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PRIVATE_KEY,
  .size = MCUXCLFFDH_FFDHE2048_SIZE_PRIVATEKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe2048,
  .plainEncoding = mcuxClFfdh_Encoding_PrivateKey_Plain
};

/* Key type structure for private and public FFDH key for RFC7919 ffdhe3072 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe3072_Pub  = 
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PUBLIC_KEY,
  .size = MCUXCLFFDH_FFDHE3072_SIZE_PUBLICKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe3072,
  .plainEncoding = mcuxClFfdh_Encoding_PublicKey_Plain
};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe3072_Priv = {.algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLFFDH_FFDHE3072_SIZE_PRIVATEKEY, .info = (void *) &mcuxClFfdh_domainParams_ffdhe3072, .plainEncoding = mcuxClFfdh_Encoding_PrivateKey_Plain};

/* Key type structure for private and public FFDH key for RFC7919 ffdhe4096 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe4096_Pub  = 
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PUBLIC_KEY,
  .size = MCUXCLFFDH_FFDHE4096_SIZE_PUBLICKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe4096,
  .plainEncoding = mcuxClFfdh_Encoding_PublicKey_Plain
};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe4096_Priv = 
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PRIVATE_KEY,
  .size = MCUXCLFFDH_FFDHE4096_SIZE_PRIVATEKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe4096,
  .plainEncoding = mcuxClFfdh_Encoding_PrivateKey_Plain
};

#ifdef MCUXCL_FEATURE_FFDH_RFC7919_FFDHE6144
/* Key type structure for private and public FFDH key for RFC7919 ffdhe6144 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe6144_Pub  = 
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PUBLIC_KEY,
  .size = MCUXCLFFDH_FFDHE6144_SIZE_PUBLICKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe6144,
  .plainEncoding = mcuxClFfdh_Encoding_PublicKey_Plain
};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe6144_Priv = {.algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLFFDH_FFDHE6144_SIZE_PRIVATEKEY, .info = (void *) &mcuxClFfdh_domainParams_ffdhe6144, .plainEncoding = mcuxClFfdh_Encoding_PrivateKey_Plain};
#endif /* MCUXCL_FEATURE_FFDH_RFC7919_FFDHE6144 */

#ifdef MCUXCL_FEATURE_FFDH_RFC7919_FFDHE8192
/* Key type structure for private and public FFDH key for RFC7919 ffdhe8192 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe8192_Pub  =
{
  .algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PUBLIC_KEY,
  .size = MCUXCLFFDH_FFDHE8192_SIZE_PUBLICKEY,
  .info = (void *) &mcuxClFfdh_domainParams_ffdhe8192,
  .plainEncoding = mcuxClFfdh_Encoding_PublicKey_Plain
};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe8192_Priv = {.algoId = MCUXCLKEY_ALGO_ID_FFDH + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLFFDH_FFDHE8192_SIZE_PRIVATEKEY, .info = (void *) &mcuxClFfdh_domainParams_ffdhe8192, .plainEncoding = mcuxClFfdh_Encoding_PrivateKey_Plain};
#endif /* MCUXCL_FEATURE_FFDH_RFC7919_FFDHE8192 */

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
