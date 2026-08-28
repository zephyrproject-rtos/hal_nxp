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

/**
 * @file  mcuxClEcc_KeyEncodingMechanisms.h
 * @brief Definition of internal key types in mcuxClEcc component
 */

#ifndef MCUXCLECC_KEYENCODINGMECHANISMS_H_
#define MCUXCLECC_KEYENCODINGMECHANISMS_H_

#include <mcuxClKey_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Key encoding types are provided as external API for the user/customer, and never used internally.")

/**********************************************************/
/* WeierECC key encoding                                  */
/**********************************************************/

/**
 * @brief Key encoding descriptor for a WeierECC private key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClEcc_EncodingDescriptor_WeierECC_PrivateKey_Plain;
/**
 * @brief Key encoding for a WeierECC private key.
 */
#define mcuxClEcc_Encoding_WeierECC_PrivateKey_Plain &mcuxClEcc_EncodingDescriptor_WeierECC_PrivateKey_Plain

/**
 * @brief Key encoding descriptor for a WeierECC public key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClEcc_EncodingDescriptor_WeierECC_PublicKey_Plain;
/**
 * @brief Key encoding for a WeierECC public key.
 */
#define mcuxClEcc_Encoding_WeierECC_PublicKey_Plain &mcuxClEcc_EncodingDescriptor_WeierECC_PublicKey_Plain

#ifdef MCUXCL_FEATURE_ECC_MONTDH
/**********************************************************/
/* MontDH key encoding                                    */
/**********************************************************/

/**
 * @brief Key encoding descriptor for a MontDH private key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClEcc_EncodingDescriptor_MontDH_PrivateKey_Plain;
/**
 * @brief Key encoding for a MontDH private key.
 */
#define mcuxClEcc_Encoding_MontDH_PrivateKey_Plain &mcuxClEcc_EncodingDescriptor_MontDH_PrivateKey_Plain

/**
 * @brief Key encoding descriptor for a MontDH public key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClEcc_EncodingDescriptor_MontDH_PublicKey_Plain;
/**
 * @brief Key encoding for a MontDH public key.
 */
#define mcuxClEcc_Encoding_MontDH_PublicKey_Plain &mcuxClEcc_EncodingDescriptor_MontDH_PublicKey_Plain
#endif /* MCUXCL_FEATURE_ECC_MONTDH */

/**********************************************************/
/* EdDSA key encoding                                    */
/**********************************************************/

/**
 * @brief Key encoding descriptor for a EdDSA private key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClEcc_EncodingDescriptor_EdDSA_PrivateKey_Plain;
/**
 * @brief Key encoding for a EdDSA private key.
 */
#define mcuxClEcc_Encoding_EdDSA_PrivateKey_Plain &mcuxClEcc_EncodingDescriptor_EdDSA_PrivateKey_Plain

/**
 * @brief Key encoding descriptor for a EdDSA public key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClEcc_EncodingDescriptor_EdDSA_PublicKey_Plain;
/**
 * @brief Key encoding for a EdDSA public key.
 */
#define mcuxClEcc_Encoding_EdDSA_PublicKey_Plain &mcuxClEcc_EncodingDescriptor_EdDSA_PublicKey_Plain

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_KEYENCODINGMECHANISMS_H_ */
