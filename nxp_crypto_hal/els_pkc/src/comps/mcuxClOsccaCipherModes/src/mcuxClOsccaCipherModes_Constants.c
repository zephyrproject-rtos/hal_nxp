/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

/** @file  mcuxClOsccaCipherModes_Constants.c
 *  @brief Definition of the constants descriptors for all provided Cipher modes */

#include <mcuxCsslAnalysis.h>
#include <mcuxClOsccaCipherModes_Constants.h>
#include <internal/mcuxClOsccaCipherModes_Internal_Types.h>
#include <internal/mcuxClOsccaCipherModes_Internal_Functions.h>
#include <internal/mcuxClOsccaCipherModes_Algorithms.h>
#include <internal/mcuxClCipher_Internal.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
#ifdef MCUXCL_FEATURE_CIPHERMODES_SM4

static const mcuxClCipher_ModeFunctions_t mcuxClOscca_CipherModeFunctions_OsccaCipherModes = {
  .crypt = mcuxClOsccaCipherModes_SkeletonSM4,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaCipherModes_SkeletonSM4),
};


const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_NoPadding = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_NoPadding
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingISO9797_1_Method1 = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingISO9797_1_Method1
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingISO9797_1_Method2 = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingISO9797_1_Method2
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingPKCS7 = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Enc_PaddingPKCS7
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_DEC = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_ECB_Dec
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_NoPadding = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_NoPadding
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingISO9797_1_Method1 = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingISO9797_1_Method1
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingISO9797_1_Method2 = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingISO9797_1_Method2
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingPKCS7 = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Enc_PaddingPKCS7
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_DEC = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CBC_Dec
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CTR_ENC = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CTR_Enc
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CTR_DEC = {
    .pModeFunctions = (const void *) &mcuxClOscca_CipherModeFunctions_OsccaCipherModes,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaCipherModes_AlgorithmDescriptor_SM4_CTR_Dec
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};



#endif /* MCUXCL_FEATURE_CIPHERMODES_SM4 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
