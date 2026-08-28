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
 * @file  mcuxClEcc_FeatureConfig.h
 * @brief Internal feature flag configurations for mcuxClEcc features
 */

#ifndef MCUXCLECC_FEATURECONFIG_H_
#define MCUXCLECC_FEATURECONFIG_H_

#include <mcuxClConfig.h> // Exported features flags header

/*
 * This file collects all dependencies of mcuxClEcc functionality
 * to other components and checks the platform's feature flags config
 * for consistency in the mcuxClEcc domain.
 * Public feature flags are translated into internal mcuxClEcc features
 * which are used for guarding functions. This is needed to avoid the
 * inclusion of Ecc object fields and functions, which are not used
 * at all in the current platform's feature scope, in the build.
 * The aim of these internally defined feature flags is to have
 * sounding names for inclusion guards, and to have a single
 * point of translation from public features to all internal
 * usages.
 */

/**********************************************************************/
/* Internal mcuxClEcc object features depending on available features  */
/**********************************************************************/

/*
 * Internal coprocessor feature flag config
 */

/*
 * Internal feature flags for generic ECC point operations
 */
#if defined(MCUXCL_FEATURE_ECC_EDDSA) || defined(MCUXCL_FEATURE_ECC_MONTDH)
/* Inclusion of the internal Ecc mcuxClEcc_GenerateMultiplicativeBlinding function. */
#define MCUXCLECC_FEATURE_INTERNAL_GENMULTBLINDING
#endif /* defined(MCUXCL_FEATURE_ECC_EDDSA) || defined(MCUXCL_FEATURE_ECC_MONTDH) || defined(MCUXCL_FEATURE_ECC_WEIERECC_KEYDERIVATION) */

/*
 * Internal feature flags for ECC Weierstrass curves
 */
#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES) || defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES) || defined(MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES) || defined(MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES)
/* Inclusion of the internal Ecc Weierstrass curves. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIERSTRASS_CURVES
#endif /* defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES) || defined(MCUXCL_FEATURE_ECC_SECPK1_CURVES) || defined(MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES) || defined(MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES) */

/*
 * Internal feature flags for ECC Weierstrass key types/functions
 */
/* Inclusion of the internal Ecc Weierstrass public key store operation. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_PUBKEY_STORAGE

/* Inclusion of the internal Ecc Weierstrass private key store operation. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_PRIVKEY_STORAGE

/*
 * Internal feature flags for ECC Weierstrass point arithmetic operations
 */
/* Inclusion of the internal Ecc Weierstrass point conversion operations. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_POINT_CONVERSION

/* Inclusion of the internal Ecc Weierstrass secure point mult operations. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_SECUREPOINTMULT

/* Inclusion of the internal Ecc Weierstrass mcuxClEcc_IntegrityCheckPN function. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_INTEGRITYCHECK_PN

/* Inclusion of the internal Ecc Weierstrass mcuxClEcc_Weier_PointCheckJacMR and mcuxClEcc_Weier_SecureConvertPoint_JacToAffine functions. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_JACOBIAN_POINT_CHECK

/* Inclusion of the internal Ecc Weierstrass mcuxClEcc_SecurePointMult function. */
#define MCUXCLECC_FEATURE_INTERNAL_WEIER_SECPOINTMULT


#endif /* MCUXCLECC_FEATURECONFIG_H_ */
