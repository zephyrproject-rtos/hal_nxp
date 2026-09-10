/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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

/** @file  mcuxClCipherModes_Crypt_Els_Modes.c
 *  @brief Definition of the ELS mode descriptors for all provided Cipher modes
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxClCipherModes_Modes.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipher_Internal.h>


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const mcuxClCipher_ModeFunctions_t mcuxClCipher_ModeFunctions_CipherModes = {
  .crypt = mcuxClCipherModes_SkeletonAes,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes)
};

/*
 * Crypt Modes using the ELS
 */
const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_NoPadding = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_NoPadding_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method1 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method1_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method2 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_PaddingISO9797_1_Method2_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};


const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Dec = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Dec_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_Enc_PaddingPKCS7 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_ECB_Enc_PaddingPKCS7_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_NoPadding = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_NoPadding_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method1 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method1_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method2 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_PaddingISO9797_1_Method2_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};


const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Enc_PaddingPKCS7 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Enc_PaddingPKCS7_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_Dec = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_CBC_Dec_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CTR = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_AES_CTR_Els
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
