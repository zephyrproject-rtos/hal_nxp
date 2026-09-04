/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

/** @file  mcuxClCipherModes_EncryptDecrypt_Sgi_Modes.c
 *  @brief Definition of the SGI mode descriptors for all provided Cipher modes
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxClCipherModes_Modes.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipher_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

/*
 * Encrypt/Decrypt Modes using the SGI
 */
static const mcuxClCipher_ModeFunctions_t mcuxClCipher_ModeFunctions_CipherModes = {
  .encrypt = mcuxClCipherModes_encrypt_Sgi,
  .decrypt = mcuxClCipherModes_decrypt_Sgi,
  .protection_token_encrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_encrypt_Sgi),
  .protection_token_decrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_decrypt_Sgi),
  .initEncrypt = mcuxClCipherModes_init_encrypt_Sgi,
  .initDecrypt = mcuxClCipherModes_init_decrypt_Sgi,
  .process =     mcuxClCipherModes_process_Sgi,
  .finish  =     mcuxClCipherModes_finish_Sgi,
  .protection_token_initencrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_init_encrypt_Sgi),
  .protection_token_initdecrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_init_decrypt_Sgi),
  .protection_token_process =     MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_process_Sgi),
  .protection_token_finish  =     MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_finish_Sgi),
};

#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
static const mcuxClCipher_ModeFunctions_t mcuxClCipher_ModeFunctions_CipherModes_dmaDriven = {
  .encrypt = mcuxClCipherModes_encrypt_Sgi_dmaDriven,
  .decrypt = mcuxClCipherModes_decrypt_Sgi_dmaDriven,
  .protection_token_encrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_encrypt_Sgi_dmaDriven),
  .protection_token_decrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_decrypt_Sgi_dmaDriven),
  .initEncrypt = mcuxClCipherModes_init_encrypt_Sgi,
  .initDecrypt = mcuxClCipherModes_init_decrypt_Sgi,
  .process =     mcuxClCipherModes_process_Sgi_dmaDriven,
  .finish  =     mcuxClCipherModes_finish_Sgi_dmaDriven,
  .protection_token_initencrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_init_encrypt_Sgi),
  .protection_token_initdecrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_init_decrypt_Sgi),
  .protection_token_process =     MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_process_Sgi_dmaDriven),
  .protection_token_finish  =     MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_finish_Sgi_dmaDriven),
};
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/*
 * Encrypt/Decrypt Modes using the SGI
 */
const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_NoPadding_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method1_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method2_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingPKCS7_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};


#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_NoPadding_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_NoPadding_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method1_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method1_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingISO9797_1_Method2_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingISO9797_1_Method2_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_ECB_PaddingPKCS7_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_ECB_PaddingPKCS7_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_NoPadding_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method1_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method2_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7 = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingPKCS7_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_NoPadding_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_NoPadding_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method1_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method1_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingISO9797_1_Method2_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method2_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CBC_PaddingPKCS7_NonBlocking =
{
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingPKCS7_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CTR = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
const mcuxClCipher_ModeDescriptor_t mcuxClCipher_ModeDescriptor_AES_CTR_NonBlocking = {
  .pModeFunctions = (const void *) &mcuxClCipher_ModeFunctions_CipherModes_dmaDriven,
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
  .pAlgorithm = (void *) &mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi_NonBlocking
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */



MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
