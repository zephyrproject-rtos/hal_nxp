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

/** @file  mcuxClOsccaMacModes_Modes.c
 *  @brief Definition of the mode descriptors for all provided MAC modes
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <mcuxClOsccaMacModes_Constants.h>
#include <internal/mcuxClOsccaMacModes_Internal_Functions.h>
#include <internal/mcuxClOsccaMacModes_Types.h>
#include <internal/mcuxClOsccaMacModes_Algorithms.h>
#include <mcuxClOsccaMacModes_Modes.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
#ifdef MCUXCL_FEATURE_MACMODES_CMAC_SM4
const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CMAC = {
  .common = {
    .compute = mcuxClOsccaMacModes_compute,
    .protectionToken_compute = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_compute),
    .init = mcuxClOsccaMacModes_init,
    .protectionToken_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_init),
    .process = mcuxClOsccaMacModes_process,
    .protectionToken_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_process),
    .finish = mcuxClOsccaMacModes_finish,
    .protectionToken_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_finish),
    .macByteSize = MCUXCLOSCCASM4_CMAC_OUTPUT_SIZE,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaMacModes_AlgorithmDescriptor_CMAC_SM4
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  },
  .pCustom = NULL
};
#endif /* MCUXCL_FEATURE_MACMODES_CMAC_SM4 */

#ifdef MCUXCL_FEATURE_MACMODES_CBCMAC_SM4
const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_NoPadding = {
  .common = {
    .compute = mcuxClOsccaMacModes_compute,
    .protectionToken_compute = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_compute),
    .init = mcuxClOsccaMacModes_init,
    .protectionToken_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_init),
    .process = mcuxClOsccaMacModes_process,
    .protectionToken_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_process),
    .finish = mcuxClOsccaMacModes_finish,
    .protectionToken_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_finish),
    .macByteSize = MCUXCLOSCCASM4_CBCMAC_OUTPUT_SIZE,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaMacModes_AlgorithmDescriptor_CBCMAC_SM4_NoPadding
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  },
  .pCustom = NULL
};

const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1 = {
  .common = {
    .compute = mcuxClOsccaMacModes_compute,
    .protectionToken_compute = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_compute),
    .init = mcuxClOsccaMacModes_init,
    .protectionToken_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_init),
    .process = mcuxClOsccaMacModes_process,
    .protectionToken_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_process),
    .finish = mcuxClOsccaMacModes_finish,
    .protectionToken_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_finish),
    .macByteSize = MCUXCLOSCCASM4_CBCMAC_OUTPUT_SIZE,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaMacModes_AlgorithmDescriptor_CBCMAC_SM4_PaddingISO9797_1_Method1
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  },
  .pCustom = NULL
};

const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method2 = {
  .common = {
    .compute = mcuxClOsccaMacModes_compute,
    .protectionToken_compute = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_compute),
    .init = mcuxClOsccaMacModes_init,
    .protectionToken_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_init),
    .process = mcuxClOsccaMacModes_process,
    .protectionToken_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_process),
    .finish = mcuxClOsccaMacModes_finish,
    .protectionToken_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_finish),
    .macByteSize = MCUXCLOSCCASM4_CBCMAC_OUTPUT_SIZE,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaMacModes_AlgorithmDescriptor_CBCMAC_SM4_PaddingISO9797_1_Method2
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  },
  .pCustom = NULL
};
const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_Padding_PKCS7 = {
  .common = {
    .compute = mcuxClOsccaMacModes_compute,
    .protectionToken_compute = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_compute),
    .init = mcuxClOsccaMacModes_init,
    .protectionToken_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_init),
    .process = mcuxClOsccaMacModes_process,
    .protectionToken_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_process),
    .finish = mcuxClOsccaMacModes_finish,
    .protectionToken_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_finish),
    .macByteSize = MCUXCLOSCCASM4_CBCMAC_OUTPUT_SIZE,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithm = (void *) &mcuxClOsccaMacModes_AlgorithmDescriptor_CBCMAC_SM4_PaddingPKCS7
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  },
  .pCustom = NULL
};
#endif /* MCUXCL_FEATURE_MACMODES_CBCMAC_SM4 */

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
