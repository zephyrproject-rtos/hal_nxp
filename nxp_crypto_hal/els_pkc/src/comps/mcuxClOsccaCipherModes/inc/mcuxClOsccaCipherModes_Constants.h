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

/** @file  mcuxClOsccaCipherModes_Constants.h
 *  @brief Supported constants for the mcuxClOsccaCipherModes component
 */

#ifndef MCUXCLOSCCACIPHERMODES_CONSTANTS_H_
#define MCUXCLOSCCACIPHERMODES_CONSTANTS_H_

#include <mcuxCsslAnalysis.h>
#include <mcuxClCipher_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClOsccaCipherModes_Constants mcuxClOsccaCipherModes_Constants
 * @brief Constants used by the Cipher operations.
 * @ingroup mcuxClOsccaCipherModes
 * @{
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_NoPadding;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_ECB_ENC_NoPadding =
  &mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_NoPadding;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingISO9797_1_Method1;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_ECB_ENC_PaddingISO9797_1_Method1 =
  &mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingISO9797_1_Method1;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingISO9797_1_Method2;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_ECB_ENC_PaddingISO9797_1_Method2 =
  &mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingISO9797_1_Method2;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingPKCS7;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_ECB_ENC_PaddingPKCS7 =
  &mcuxClOscca_Cipher_ModeDesc_SM4_ECB_ENC_PaddingPKCS7;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_ECB_DEC;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_ECB_DEC =
  &mcuxClOscca_Cipher_ModeDesc_SM4_ECB_DEC;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_NoPadding;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CBC_ENC_NoPadding =
  &mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_NoPadding;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingISO9797_1_Method1;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CBC_ENC_PaddingISO9797_1_Method1 =
  &mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingISO9797_1_Method1;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingISO9797_1_Method2;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CBC_ENC_PaddingISO9797_1_Method2 =
  &mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingISO9797_1_Method2;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingPKCS7;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CBC_ENC_PaddingPKCS7=
  &mcuxClOscca_Cipher_ModeDesc_SM4_CBC_ENC_PaddingPKCS7;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CBC_DEC;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CBC_DEC =
  &mcuxClOscca_Cipher_ModeDesc_SM4_CBC_DEC;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CTR_ENC;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CTR_ENC =
  &mcuxClOscca_Cipher_ModeDesc_SM4_CTR_ENC;

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM4_CTR_DEC;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
static mcuxClCipher_Mode_t mcuxClOscca_Cipher_Mode_SM4_CTR_DEC =
  &mcuxClOscca_Cipher_ModeDesc_SM4_CTR_DEC;


MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCACIPHERMODES_CONSTANTS_H_ */
