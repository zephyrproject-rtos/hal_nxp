/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxClEcc_KeyTypes.h
 * @brief ECC related definitions to be used for key handling mechanisms of the mcuxClKey component
 */


#ifndef MCUXCLECC_KEYTYPES_H_
#define MCUXCLECC_KEYTYPES_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClEcc_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClEcc_KeyTypeDescriptors mcuxClEcc_KeyTypeDescriptors
 * @brief Definitions of ECC related key type descriptors
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */

#ifdef MCUXCL_FEATURE_ECC_SECPK1_CURVES
/***********************************************/
/* Key types for secp160k1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp160k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp160k1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp160k1.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp160k1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp160k1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp160k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp160k1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp160k1.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp160k1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp160k1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for secp192k1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp192k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp192k1.
 *
 * \implements{REQ_788278}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp192k1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp192k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp192k1.
 *
 * \implements{REQ_788278}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp192k1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp192k1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for secp224k1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp224k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224k1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp224k1.
 *
 * \implements{REQ_788278}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp224k1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp224k1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp224k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224k1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp224k1.
 *
 * \implements{REQ_788278}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp224k1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp224k1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for secp256k1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp256k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp256k1.
 *
 * \implements{REQ_788278}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp256k1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp256k1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp256k1.
 *
 * \implements{REQ_788278}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp256k1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp256k1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* MCUXCL_FEATURE_ECC_SECPK1_CURVES */
#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)
/***********************************************/
/* Key types for secp192r1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp192r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp192r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp192r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp192r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp192r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp192r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for secp224r1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp224r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp224r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp224r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp224r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp224r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp224r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* defined(ECC_SECPR1_CURVES) || defined(ECC_NISTPR1_CURVES) || defined(ECC_ANSIX9P_CURVES) */

#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)
/***********************************************/
/* Key types for secp256r1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp256r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp256r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp256r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp256r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp256r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp256r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* defined(ECC_SECPR1_CURVES) || defined(ECC_NISTPR1_CURVES) || defined(ECC_ANSIX9P_CURVES) || defined(ECC_ECCKI) */

#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)
/***********************************************/
/* Key types for secp384r1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp384r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp384r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp384r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp384r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp384r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp384r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* defined(ECC_SECPR1_CURVES) || defined(ECC_NISTPR1_CURVES) || defined(ECC_ANSIX9P_CURVES) || defined(ECC_ECCKI) */

#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)
/***********************************************/
/* Key types for secp521r1                     */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve secp521r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve secp521r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp521r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve secp521r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve secp521r1.
 *
 * \implements{REQ_788278,REQ_788276}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_secp521r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for NIST P-192                    */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve NIST P-192.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P192_Pub mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Pub

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve NIST P-192.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P192_Pub = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P192_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve NIST P-192.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P192_Priv mcuxClKey_TypeDescriptor_WeierECC_secp192r1_Priv

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve NIST P-256.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P192_Priv = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P192_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for NIST P-224                    */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve NIST P-224.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P224_Pub mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Pub

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve NIST P-224.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P224_Pub = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P224_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve NIST P-224.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P224_Priv mcuxClKey_TypeDescriptor_WeierECC_secp224r1_Priv

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve NIST P-224.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P224_Priv = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P224_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES) */

#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)
/***********************************************/
/* Key types for NIST P-256                    */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve NIST P-256.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P256_Pub mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Pub

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve NIST P-256.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P256_Pub = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P256_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve NIST P-256.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P256_Priv mcuxClKey_TypeDescriptor_WeierECC_secp256r1_Priv

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve NIST P-256.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P256_Priv = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P256_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* defined(ECC_SECPR1_CURVES) || defined(ECC_NISTPR1_CURVES) || defined(ECC_ANSIX9P_CURVES) || defined(ECC_ECCKI) */

#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)

/***********************************************/
/* Key types for NIST P-384                    */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve NIST P-384.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P384_Pub mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Pub

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve NIST P-384.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P384_Pub = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P384_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve NIST P-384.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P384_Priv mcuxClKey_TypeDescriptor_WeierECC_secp384r1_Priv

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve NIST P-384.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P384_Priv = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P384_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES) || defined(MCUXCL_FEATURE_ECC_ECCKI) */

#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)
/***********************************************/
/* Key types for NIST P-521                    */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve NIST P-521.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P521_Pub mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Pub

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve NIST P-521.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P521_Pub = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P521_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve NIST P-521.
 *
 */
#define mcuxClKey_TypeDescriptor_WeierECC_NIST_P521_Priv mcuxClKey_TypeDescriptor_WeierECC_secp521r1_Priv

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve NIST P-521.
 *
 * \implements{REQ_788274}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_NIST_P521_Priv = &mcuxClKey_TypeDescriptor_WeierECC_NIST_P521_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* defined(SECPR1_CURVES) || defined(NISTPR1_CURVES) || defined(ANSIX9P_CURVES) */
#ifdef MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES

/***********************************************/
/* Key types for brainpoolP160r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP160r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP160r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP160r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP160r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP160r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP160r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP192r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP192r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP192r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP192r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP192r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP192r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP192r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP224r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP224r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP224r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP224r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP224r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP224r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP224r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP256r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP256r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP256r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP256r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP256r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP256r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP256r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP320r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP320r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP320r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP320r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP320r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP320r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP320r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP384r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP384r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP384r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP384r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP384r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP384r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP384r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP512r1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP512r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP512r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP512r1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP512r1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP512r1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP512r1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512r1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES */
#ifdef MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES

/***********************************************/
/* Key types for brainpoolP160t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP160t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP160t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP160t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP160t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP160t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP160t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP160t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP192t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP192t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP192t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP192t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP192t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP192t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP192t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP192t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP224t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP224t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP224t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP224t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP224t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP224t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP224t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP224t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP256t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP256t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP256t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP256t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP256t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP256t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP256t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP256t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP320t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP320t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP320t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP320t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP320t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP320t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP320t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP320t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP384t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP384t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP384t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP384t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP384t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP384t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP384t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP384t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for brainpoolP512t1               */
/***********************************************/

/**
 * @brief Key type structure for public ECC keys for Weierstrass curve brainpoolP512t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512t1_Pub;

/**
 * @brief Key type pointer for public ECC Weierstrass keys for Weierstrass curve brainpoolP512t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP512t1_Pub = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512t1_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private ECC keys for Weierstrass curve brainpoolP512t1.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512t1_Priv;

/**
 * @brief Key type pointer for private ECC keys for Weierstrass curve brainpoolP512t1.
 *
 * \implements{REQ_788277}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_WeierECC_brainpoolP512t1_Priv = &mcuxClKey_TypeDescriptor_WeierECC_brainpoolP512t1_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* #ifdef MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES */

/***********************************************/
/* Key types for Ed25519                       */
/***********************************************/

/**
 * @brief Key type structure for ECC EdDSA Ed25519 private keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_EdDSA_Ed25519_Priv;

/**
 * @brief Key type pointer for ECC EdDSA Ed25519 private keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_EdDSA_Ed25519_Priv = &mcuxClKey_TypeDescriptor_EdDSA_Ed25519_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for ECC EdDSA Ed25519 public keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_EdDSA_Ed25519_Pub;

/**
 * @brief Key type pointer for ECC EdDSA Ed25519 public keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_EdDSA_Ed25519_Pub = &mcuxClKey_TypeDescriptor_EdDSA_Ed25519_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef MCUXCL_FEATURE_ECC_CURVE25519

/***********************************************/
/* Key types for Curve25519                    */
/***********************************************/

/**
 * @brief Private key type structure for ECC MontDH Curve25519.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve25519_PrivateKey;

/**
 * @brief Public key type structure for ECC MontDH Curve25519.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve25519_PublicKey;

/**
 * @brief Private key type pointer for ECC MontDH Curve25519.
 *
 * \implements{REQ_788280}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ecc_MontDH_Curve25519_PrivateKey = &mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve25519_PrivateKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/**
 * @brief Public key type pointer for ECC MontDH Curve25519.
 *
 * \implements{REQ_788280}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ecc_MontDH_Curve25519_PublicKey = &mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve25519_PublicKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* MCUXCL_FEATURE_ECC_CURVE25519 */
#ifdef MCUXCL_FEATURE_ECC_CURVE448

/***********************************************/
/* Key types for Curve448                      */
/***********************************************/

/**
 * @brief Private key type structure for ECC MontDH Curve448.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve448_PrivateKey;

/**
 * @brief Public key type structure for ECC MontDH Curve448.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve448_PublicKey;

/**
 * @brief Private key type pointer for ECC MontDH Curve448.
 *
 * \implements{REQ_788280}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ecc_MontDH_Curve448_PrivateKey = &mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve448_PrivateKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Public key type pointer for ECC MontDH Curve448.
 *
 * \implements{REQ_788280}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ecc_MontDH_Curve448_PublicKey = &mcuxClKey_TypeDescriptor_Ecc_MontDH_Curve448_PublicKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_CURVE448 */

/**
 * @}
 */ /* mcuxClEcc_KeyTypeDescriptors */

/**
 * @defgroup mcuxClEcc_KeyGenerationDescriptors mcuxClEcc_KeyGenerationDescriptors
 * @brief Definitions of ECC related key pair generation algorithm descriptors
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */

/**
 * @brief ECDH Key generation algorithm descriptor
 */
extern const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_ECDH;

/**
 * @brief ECDH Key generation algorithm
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Generation_t mcuxClKey_Generation_ECDH =
  &mcuxClKey_GenerationDescriptor_ECDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief ECDSA Key generation algorithm descriptor
 */
extern const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_ECDSA;

/**
 * @brief ECDSA Key generation algorithm
 *
 * \implements{REQ_788266}
}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Generation_t mcuxClKey_Generation_ECDSA =
  &mcuxClKey_GenerationDescriptor_ECDSA;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef MCUXCL_FEATURE_ECC_EDDSA
/**
 * @brief EdDSA Key generation algorithm descriptor
 *
 * This key generation algorithm descriptor shall be used for an EdDSA private and public key pair generation.
 */
extern const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_EdDSA_GeneratePrivKey;

/**
 * @brief EdDSA Key generation algorithm
 *
 * This key generation algorithm shall be used for EdDSA private and public key pair generation.
 *
 * \implements{REQ_788267}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Generation_t mcuxClKey_Generation_EdDSA_GeneratePrivKey =
  &mcuxClKey_GenerationDescriptor_EdDSA_GeneratePrivKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_EDDSA */

#ifdef MCUXCL_FEATURE_ECC_MONTDH
/**
 * @brief MontDH Key generation algorithm descriptor
 *
 * This key generation algorithm descriptor shall be used for an MontDH private and public key pair generation.
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_MontDH;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * @brief MontDH Key generation algorithm
 *
 * This key generation algorithm shall be used for MontDH private and public key pair generation.
 *
 * \implements{REQ_788280}
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Generation_t mcuxClKey_Generation_MontDH =
  &mcuxClKey_GenerationDescriptor_MontDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_MONTDH */

/**
 * @}
 */ /* mcuxClEcc_KeyGenerationDescriptors */

/**
 * @defgroup mcuxClEcc_KeyAgreementDescriptors mcuxClEcc_KeyAgreementDescriptors
 * @brief Definitions of ECC related key agreement algorithm descriptors
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */


/**
 * @brief ECDH Key agreement algorithm descriptor
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("Forward declaration. Hence, it is declared but not defined in this file.")
extern const mcuxClKey_AgreementDescriptor_t mcuxClKey_AgreementDescriptor_ECDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()

/**
 * @brief ECDH Key agreement algorithm
 *
 * \implements{REQ_788280}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Agreement_t mcuxClKey_Agreement_ECDH =
  &mcuxClKey_AgreementDescriptor_ECDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef MCUXCL_FEATURE_ECC_MONTDH
/**
 * @brief MontDH Key agreement algorithm descriptor
 */
extern const mcuxClKey_AgreementDescriptor_t mcuxClKey_AgreementDescriptor_MontDH;

/**
 * @brief MontDH Key agreement algorithm
 *
 * \implements{REQ_788280}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Agreement_t mcuxClKey_Agreement_MontDH =
  &mcuxClKey_AgreementDescriptor_MontDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* MCUXCL_FEATURE_ECC_MONTDH */

/**
 * @}
 */ /* mcuxClEcc_KeyAgreementDescriptors */

/**
 * @defgroup mcuxClEcc_KeyValidationDescriptors mcuxClEcc_KeyValidationDescriptors
 * @brief Definitions of ECC related key validation descriptors
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */

/**
 * @brief Key validation descriptor for a public key used for ECC on a Weierstrass curve
 */
extern const mcuxClKey_ValidationDescriptor_t mcuxClKey_ValidationDesc_WeierECC_PublicKey;

/**
 * @brief Key validation type for a public key used for ECC on a Weierstrass curve
 *
 * \implements{REQ_788283}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Validation_t mcuxClKey_Validation_WeierECC_PublicKey =
  &mcuxClKey_ValidationDesc_WeierECC_PublicKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key validation descriptor for a private key used for ECC on a Weierstrass curve
 */
extern const mcuxClKey_ValidationDescriptor_t mcuxClKey_ValidationDesc_WeierECC_PrivateKey;

/**
 * @brief Key validation type for a private key used for ECC on a Weierstrass curve
 *
 * \implements{REQ_788284}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Validation_t mcuxClKey_Validation_WeierECC_PrivateKey =
  &mcuxClKey_ValidationDesc_WeierECC_PrivateKey;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @}
 */ /* mcuxClEcc_KeyValidationDescriptors */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_KEYTYPES_H_ */
