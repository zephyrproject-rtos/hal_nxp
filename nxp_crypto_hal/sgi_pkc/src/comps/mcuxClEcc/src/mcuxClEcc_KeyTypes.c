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

/**
 * @file  mcuxClEcc_KeyTypes.c
 * @brief mcuxClEcc: implementation of ECC related key type descriptors
 */

#include <mcuxClKey.h>
#include <mcuxClEcc.h>

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClKey_Types_Internal.h>
#ifdef MCUXCL_FEATURE_ECC_MONTDH
#include <internal/mcuxClEcc_Mont_Internal.h>
#endif /* MCUXCL_FEATURE_ECC_MONTDH */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the key parameters.")

#ifdef MCUXCL_FEATURE_ECC_SECPK1_CURVES

/* Key type structure for private and public ECC keys for Weierstrass curve secp160k1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp160k1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP160K1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp160k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp160k1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP160K1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp160k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp192k1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP192K1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp192k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP192K1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp192k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp224k1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224k1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP224K1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp224k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224k1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP224K1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp224k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp256k1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP256K1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp256k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP256K1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp256k1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};
#endif /* MCUXCL_FEATURE_ECC_SECPK1_CURVES */


#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)

/* Key type structure for private and public ECC keys for Weierstrass curve secp192r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP192R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp192r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP192R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp192r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp224r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP224R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp224r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP224R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp224r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp256r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP256R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp256r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP256R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp256r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp384r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP384R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp384r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP384R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp384r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve secp521r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_SECP521R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp521r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_SECP521R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_secp521r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

#endif /* if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES) elif defined(ECC_ECCKI) */


#ifdef MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP160r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP160R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP160r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP160R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP160r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP192r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP192R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP192r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP192R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP192r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP224r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP224R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP224r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP224R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP224r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP256r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP256R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP256r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP256R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP256r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP320r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP320R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP320r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP320R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP320r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP384r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP384R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP384r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP384R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP384r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP512r1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP512R1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP512r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP512R1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP512r1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};
#endif /* MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES */


#ifdef MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP160t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP160T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP160t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP160T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP160t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP192t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP192T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP192t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP192T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP192t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP224t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP224T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP224t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP224T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP224t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP256t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP256T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP256t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP256T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP256t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP320t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP320T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP320t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP320T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP320t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP384t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP384T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP384t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP384T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP384t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};

/* Key type structure for private and public ECC keys for Weierstrass curve brainpoolP512t1 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512t1_Pub  = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP512T1_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP512t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PublicKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512t1_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP + MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_WEIERECC_BRAINPOOLP512T1_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_Weier_DomainParams_brainpoolP512t1, .plainEncoding = mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain};
#endif /* #ifdef MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES */

/* Key type structure for private and public EdDSA keys for twisted Edwards curve Ed25519 */
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_EdDSA_Ed25519_Priv = {.algoId = MCUXCLKEY_ALGO_ID_ECC_EDDSA | MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_EDDSA_ED25519_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_EdDSA_DomainParams_Ed25519, .plainEncoding = mcuxClEcc_Encoding_EdDSA_PrivateKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_EdDSA_Ed25519_Pub = {.algoId = MCUXCLKEY_ALGO_ID_ECC_EDDSA | MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_EDDSA_ED25519_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_EdDSA_DomainParams_Ed25519, .plainEncoding = mcuxClEcc_Encoding_EdDSA_PublicKey_Plain};
#ifdef MCUXCL_FEATURE_ECC_CURVE25519

const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve25519_PrivateKey = {.algoId = MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_MONTDH_CURVE25519_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_MontDH_DomainParams_Curve25519, .plainEncoding = mcuxClEcc_Encoding_MontDH_PrivateKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve25519_PublicKey = {.algoId = MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_MONTDH_CURVE25519_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_MontDH_DomainParams_Curve25519, .plainEncoding = mcuxClEcc_Encoding_MontDH_PublicKey_Plain};
#endif /* MCUXCL_FEATURE_ECC_CURVE25519 */
#ifdef MCUXCL_FEATURE_ECC_CURVE448

const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve448_PrivateKey = {.algoId = MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PRIVATE_KEY, .size = MCUXCLECC_MONTDH_CURVE448_SIZE_PRIVATEKEY, .info = (void *) &mcuxClEcc_MontDH_DomainParams_Curve448, .plainEncoding = mcuxClEcc_Encoding_MontDH_PrivateKey_Plain};
const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve448_PublicKey = {.algoId = MCUXCLKEY_ALGO_ID_ECC_MONTDH | MCUXCLKEY_ALGO_ID_PUBLIC_KEY, .size = MCUXCLECC_MONTDH_CURVE448_SIZE_PUBLICKEY, .info = (void *) &mcuxClEcc_MontDH_DomainParams_Curve448, .plainEncoding = mcuxClEcc_Encoding_MontDH_PublicKey_Plain};
#endif /* MCUXCL_FEATURE_ECC_CURVE448 */

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
