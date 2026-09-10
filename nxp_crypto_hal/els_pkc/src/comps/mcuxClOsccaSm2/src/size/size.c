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

/**
 *
 * @file:   size.c
 * @brief:  This file contains objects which will be used to measure size of particular types.
 *
 */

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClOsccaSm2_Types.h>
#include <mcuxClOsccaSm2_Constants.h>
#include <mcuxClOsccaSm3_Constants.h>
#include <internal/mcuxClOsccaSm3_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClOsccaSm2_Internal_Types.h>
#include <internal/mcuxClOsccaSm2_Internal_PkcWaLayout.h>
#include <mcuxClOscca_Types.h>
#include <mcuxClOscca_Memory.h>
#include <mcuxClOsccaPkc.h>
#include <internal/mcuxClOsccaPkc_Macros.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClOsccaSm3_Internal.h>

#ifdef MCUXCL_FEATURE_SM2_INTERNAL
#include <internal/mcuxClOsccaSm2_Internal_ConstructTypes.h>
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
/*********************************************************************************************/
/** @brief  Definition of CPU workarea size in bytes for SM2 API functions                   */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Common_WaCPU[mcuxClOscca_alignSize(sizeof(mcuxClOsccaPkc_State_t) + (MCUXCLOSCCASM2_NO_OF_BUFFERS + \
        MCUXCLOSCCASM2_NO_OF_VIRTUALS) * sizeof(uint16_t))];

/*********************************************************************************************/
/** @brief  Definition of CPU workarea size in bytes for SM2 invert private key              */
/*********************************************************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
volatile uint8_t mcuxClOsccaSm2_InvertPrivateKey_WaCPU[sizeof(mcuxClOsccaSm2_Common_WaCPU)];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 signature generation             */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Sign_WaCPU[MCUXCLCORE_MAX(sizeof(mcuxClOsccaSm2_Common_WaCPU), \
                                          sizeof(mcuxClOsccaSm2_InvertPrivateKey_WaCPU))];

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 pre-hash calculation             */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Compute_Prehash_Cpu[(mcuxClOscca_alignSize(sizeof(mcuxClHash_ContextDescriptor_t) + \
                      MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + MCUXCLOSCCASM3_STATE_SIZE_SM3) + \
                      mcuxClOscca_alignSize(MCUXCLOSCCASM3_STATE_SIZE_SM3))];

/*************************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 key generation through internal call */
/*************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Key_GenerateKeyPair_WaCPU[sizeof(mcuxClOsccaSm2_Common_WaCPU)];

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 signature verification           */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Verify_WaCPU[sizeof(mcuxClOsccaSm2_Common_WaCPU)];


/*********************************************************************************************/
/** @brief Definition (constant part) of CPU workarea size in bytes for SM2 encryption       */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Encrypt_Fixed_WaCPU[sizeof(mcuxClOsccaSm2_Common_WaCPU)];

/*********************************************************************************************/
/** @brief Definition (constant part) of CPU workarea size in bytes for SM2 decryption       */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Decrypt_Fixed_WaCPU[sizeof(mcuxClOsccaSm2_Common_WaCPU)];

/*********************************************************************************************/
/** @brief Definition (constant part) of context size in bytes for SM2 encryption decryption */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Encrypt_Decrypt_Ctx_Fixed_WaCPU[mcuxClOscca_alignSize(sizeof(mcuxClOsccaSm2_Internal_EncDecCtx_t))];

/******************************************************************************************************/
/** @brief Platform-independent definition of CPU workarea sizes in bytes for SM2 encryption          */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Encrypt_WaCPU[sizeof(mcuxClOsccaSm2_Encrypt_Fixed_WaCPU) \
        + mcuxClOscca_alignSize(MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + 2u * MCUXCLOSCCASM3_STATE_SIZE_SM3)];

/******************************************************************************************************/
/** @brief Platform-independent definition of CPU workarea sizes in bytes for SM2 decryption          */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Decrypt_WaCPU[sizeof(mcuxClOsccaSm2_Decrypt_Fixed_WaCPU) \
        + mcuxClOscca_alignSize(MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + 2u * MCUXCLOSCCASM3_STATE_SIZE_SM3)];

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 selftest through internal call   */
/*********************************************************************************************/
#if defined(MCUXCL_FEATURE_SM2_SIGNATURE) && defined (MCUXCL_FEATURE_SIGNATURE_SELFTEST)
volatile uint8_t mcuxClOsccaSm2_Signature_Selftest_WaCPU[MCUXCLCORE_MAX((sizeof(mcuxClOsccaSm2_Compute_Prehash_Cpu) + MCUXCLOSCCASM3_OUTPUT_SIZE_SM3),\
                                                          MCUXCLCORE_MAX((sizeof(mcuxClOsccaSm2_Sign_WaCPU) + MCUXCLOSCCASM2_SM2P256_SIZE_BASEPOINTORDER),\
                                                                            sizeof(mcuxClOsccaSm2_Verify_WaCPU))) \
                                                        + 2u * mcuxClOscca_alignSize(sizeof(mcuxClKey_Descriptor_t)) + MCUXCLOSCCASM2_SM2P256_SIZE_SIGNATURE\
                                                        + MCUXCLOSCCASM3_OUTPUT_SIZE_SM3];
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE &&  MCUXCL_FEATURE_SIGNATURE_SELFTEST */

/******************************************************************************************************/
/** @brief Platform-independent definition of context size in bytes for SM2 Encryption and Decryption */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Enc_Dec_Ctx_WaCPU[sizeof(mcuxClOsccaSm2_Encrypt_Decrypt_Ctx_Fixed_WaCPU)];

/******************************************************************************************************/
/** @brief Platform-dependent definition of parameter size in bytes for SM2 Cipher Enc and Dec        */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_EncDecParamsMax[mcuxClOscca_alignSize(MCUXCLCORE_MAX(sizeof(mcuxClOsccaSm2_Encrypt_Param_t),sizeof(mcuxClOsccaSm2_Decrypt_Param_t)))];

/******************************************************************************************************/
/** @brief Platform-dependent definition of context size in bytes for SM2 Cipher Enc and Dec          */
/******************************************************************************************************/
#ifdef MCUXCL_FEATURE_SM2_CIPHER
volatile uint8_t mcuxClOsccaSm2_Cipher_Context_WaCPU[mcuxClOscca_alignSize(sizeof(mcuxClOsccaSm2_Cipher_Context_t))];

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 enc/dec through internal call    */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Cipher_EncDec_fixed_WaCPU[sizeof(mcuxClOsccaSm2_EncDecParamsMax)];

#endif /* MCUXCL_FEATURE_SM2_CIPHER */

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 sign/verify selftest             */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_SignVerify_Selftest_WaCPU[mcuxClOscca_alignSize(sizeof(mcuxClHash_ContextDescriptor_t) +                      \
                                                               MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + MCUXCLOSCCASM3_STATE_SIZE_SM3) +             \
                                                         2U * MCUXCLOSCCASM3_OUTPUT_SIZE_SM3 +                                              \
                                                         2U * MCUXCLOSCCASM2_SM2P256_SIZE_BASEPOINTORDER +                                  \
                                                         2u * mcuxClOscca_alignSize(sizeof(mcuxClKey_Descriptor_t)) +                        \
                                                         MCUXCLCORE_MAX(MCUXCLCORE_MAX(sizeof(mcuxClOsccaSm2_Compute_Prehash_Cpu),    \
                                                                       (sizeof(mcuxClOsccaSm2_Sign_WaCPU)+                                  \
                                                                        mcuxClOscca_alignSize(MCUXCLOSCCASM2_SM2P256_SIZE_BASEPOINTORDER))), \
                                                                        sizeof(mcuxClOsccaSm2_Verify_WaCPU))];

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 enc/dec selftest                 */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_EncDec_Selftest_WaCPU[2U * 128U + mcuxClOscca_alignSize(2u * MCUXCLOSCCASM2_SM2P256_SIZE_PRIMEP + 1u) +     \
                                                     MCUXCLOSCCASM3_OUTPUT_SIZE_SM3 +                                                     \
                                                     mcuxClOscca_alignSize(sizeof(mcuxClOsccaSm2_Encrypt_Decrypt_Ctx_Fixed_WaCPU) +        \
                                                     MCUXCLOSCCASM2_SM2P256_SIZE_PRIMEP) +                                                \
                                                     MCUXCLCORE_MAX((sizeof(mcuxClOsccaSm2_Encrypt_WaCPU)+                             \
                                                                        mcuxClOscca_alignSize(3u * MCUXCLOSCCASM2_SM2P256_SIZE_PRIMEP + 1u)),\
                                                                       (sizeof(mcuxClOsccaSm2_Decrypt_WaCPU)+                             \
                                                                        mcuxClOscca_alignSize(MCUXCLOSCCASM2_SM2P256_SIZE_PRIMEP)))];

/*********************************************************************************************/
/** @brief Definition (constant part) of CPU workarea size in bytes for SM2 key exchange     */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_KeyExchange_Fixed_WaCPU[mcuxClOscca_alignSize(sizeof(mcuxClOsccaSm2_KeyExchg_WaCpu_t)) + \
                                                       mcuxClOscca_alignSize(sizeof(mcuxClOsccaSm2_Common_WaCPU)) +     \
                                                       mcuxClOscca_alignSize(sizeof(mcuxClHash_ContextDescriptor_t) +   \
                                                        MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + MCUXCLOSCCASM3_STATE_SIZE_SM3) +\
                                                       MCUXCLOSCCASM3_STATE_SIZE_SM3];

/******************************************************************************************************/
/** @brief Platform-independent definition of CPU workarea sizes in bytes for SM2 key exchange        */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_KeyExchange_WaCPU[sizeof(mcuxClOsccaSm2_KeyExchange_Fixed_WaCPU)];

/************************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 key agreement through internal call */
/************************************************************************************************/
#ifdef MCUXCL_FEATURE_SM2_KEYAGREEMENT
volatile uint8_t mcuxClOsccaSm2_KeyAgreement_WaCPU[sizeof(mcuxClOsccaSm2_KeyExchange_Fixed_WaCPU)];

/* 16U is the length of pCommonSecret used in keyagreement selftest */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
volatile uint8_t mcuxClOsccaSm2_KeyAgreement_Selftest_WaCPU[sizeof(mcuxClOsccaSm2_KeyExchange_Fixed_WaCPU) + \
                                                           2U * MCUXCLOSCCASM3_OUTPUT_SIZE_SM3 +            \
                                                           16U + 2U * mcuxClOscca_alignSize(sizeof(mcuxClKey_Descriptor_t))];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
#endif /* MCUXCL_FEATURE_SM2_KEYAGREEMENT */

/*********************************************************************************************/
/** @brief Definition of CPU workarea size in bytes for SM2 Keyexchange selftest             */
/*********************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_KeyEx_Selftest_WaCPU[2U * MCUXCLOSCCASM3_OUTPUT_SIZE_SM3 + \
                                                    16U + sizeof(mcuxClOsccaSm2_KeyExchange_WaCPU)];

/******************************************************************************************************/
/** @brief Macro to determine PKC workarea size for arbitrary byte lengths of p and n and defines    */
/** @brief for PKC workarea sizes for standard key lengths                                           */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_PKC_wordsize[MCUXCLOSCCAPKC_WORD_SIZE];
volatile uint8_t mcuxClOsccaSm2_Internal_WaPKC_NoOfBuffers[MCUXCLOSCCASM2_NO_OF_BUFFERS];
volatile uint8_t mcuxClOsccaSm2_Internal_InvertPrivateKey_WaPKC_NoOfBuffers[MCUXCLOSCCASM2_INVERTPRIVATEKEY_NO_OF_BUFFERS];

/******************************************************************************************************/
/** @brief  Definition of PKC workarea size in bytes for pre-hashing                                  */
/******************************************************************************************************/
volatile uint8_t mcuxClOsccaSm2_Compute_PreHash_WaPKC[4U];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
