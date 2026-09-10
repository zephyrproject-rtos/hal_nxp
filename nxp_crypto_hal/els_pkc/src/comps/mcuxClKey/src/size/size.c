/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

#include <mcuxClCore_Macros.h>
#include <internal/mcuxClKey_Types_Internal.h>

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108
#include <internal/mcuxClMacModes_Common_Memory.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Common_Types.h>
#include <internal/mcuxClHmac_Internal_Memory.h>
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108 */

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C
#include <mcuxClHashModes_Constants.h>
#include <mcuxClAes_Constants.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClHmac_Internal_Memory.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClHashModes_Internal_Memory.h>
#include <internal/mcuxClHash_Internal_Memory.h>
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C */


/* *********************** */
/* *** Structure sizes *** */
/* *********************** */

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
volatile uint8_t mcuxClKey_DescriptorSize[sizeof(mcuxClKey_Descriptor_t)];
volatile uint8_t mcuxClKey_TypeDescriptorSize[sizeof(mcuxClKey_TypeDescriptor_t)];

#ifdef MCUXCL_FEATURE_KEY_DERIVATION
volatile uint8_t mcuxClKey_DerivationModeDescriptorSize[sizeof(mcuxClKey_DerivationMode_t)];

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108
volatile uint8_t mcuxClKey_derivationEngine_NIST_SP800_108_wa_cpu[MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKeyDerivation_WorkArea_t))
                                                               + MCUXCLCORE_MAX(MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLMACMODES_INTERNAL_WASIZE),
                                                                              MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHMAC_INTERNAL_MAX_WACPU))
                                                                              ];
#else
volatile uint8_t mcuxClKey_derivationEngine_NIST_SP800_108_wa_cpu[1];
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108 */

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C
volatile uint8_t mcuxClKey_derivationEngine_NIST_SP800_56C_wa_cpu[
    MCUXCLCORE_MAX(
        /* one step calculations */
        MCUXCLCORE_MAX(   (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHASH_INTERNAL_WACPU_MAX)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHASHMODES_CONTEXT_MAX_SIZE_INTERNAL_NO_SECSHA) /* pContext */
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHASH_MAX_OUTPUT_SIZE)),                        /* pTempOutBuffer */
                         (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHMAC_INTERNAL_MAX_WACPU)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKeyDerivation_WorkArea_t))              /* pWa */
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_Descriptor_t)))),                   /* hmacKeyHandle */
        /* two step calculations */
        MCUXCLCORE_MAX(   (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLAES_AES256_KEY_SIZE)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_Descriptor_t))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLAES_AES128_KEY_SIZE)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_Descriptor_t))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLMACMODES_INTERNAL_WASIZE)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_DerivationMode_t))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_derivationEngine_NIST_SP800_108_wa_cpu))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLAES_AES128_KEY_SIZE)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLAES_AES256_KEY_SIZE)
                        ),                                                                                             /* mode = CMAC */
                         (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_Descriptor_t))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHASH_MAX_OUTPUT_SIZE)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHMAC_INTERNAL_MAX_WACPU)
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_Descriptor_t))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_DerivationMode_t))
                        + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_derivationEngine_NIST_SP800_108_wa_cpu))))   /* mode = HMAC */
    )
    ];
#else
volatile uint8_t mcuxClKey_derivationEngine_NIST_SP800_56C_wa_cpu[1];
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C */

volatile uint8_t mcuxClKey_derivationEngine_ISOIEC_18033_2_wa_cpu[1];

volatile uint8_t mcuxClKey_derivationEngine_ANSI_X9_63_wa_cpu[1];

volatile uint8_t mcuxClKey_derivationEngine_RFC5246_PRF_wa_cpu[1];

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_HKDF
volatile uint8_t mcuxClKey_derivationEngine_HKDF_wa_cpu[MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKeyDerivation_WorkArea_t))
                                                            + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClKey_Descriptor_t))
                                                            + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHMAC_INTERNAL_MAX_WACPU)];
#else
volatile uint8_t mcuxClKey_derivationEngine_HKDF_wa_cpu[1];
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_HKDF */

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_PBKDF2
/*  For pBigEndianI, pMacOutput, pT_i_buffer in mcuxClKey_derivationEngine_PBKDF2
    For hmacContext and hmac multipart calls in mcuxClKey_derivation_pbkdf2_computeHmac */
volatile uint8_t mcuxClKey_derivationEngine_PBKDF2_wa_cpu[sizeof(uint32_t)
                                                            + 2u * MCUXCLHMAC_MAX_OUTPUT_SIZE
                                                            + MCUXCLHMAC_INTERNAL_MAX_WACPU
                                                            + MCUXCLHMAC_INTERNAL_MAX_CONTEXT_SIZE];
#else
volatile uint8_t mcuxClKey_derivationEngine_PBKDF2_wa_cpu[1];
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_PBKDF2 */

volatile uint8_t mcuxClKey_derivationEngine_IKEv2_wa_cpu[1];

volatile uint8_t mcuxClKey_derivation_max_wa_cpu[MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_NIST_SP800_108_wa_cpu),
                                                MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_NIST_SP800_56C_wa_cpu),
                                                MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_ANSI_X9_63_wa_cpu),
                                                MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_ISOIEC_18033_2_wa_cpu),
                                                MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_RFC5246_PRF_wa_cpu),
                                                MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_HKDF_wa_cpu),
                                                MCUXCLCORE_MAX(sizeof(mcuxClKey_derivationEngine_PBKDF2_wa_cpu),
                                                             sizeof(mcuxClKey_derivationEngine_IKEv2_wa_cpu))))))))];

#endif /* MCUXCL_FEATURE_KEY_DERIVATION */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
