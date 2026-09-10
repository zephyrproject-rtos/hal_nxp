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

/** @file  mcuxClAeadModes_Els_Modes.c
 *  @brief Definition of the mode descriptors for all provided Cipher modes
 */

#include <internal/mcuxClAeadModes_Els_Algorithms.h>
#include <internal/mcuxClAead_Descriptor.h>
#include <internal/mcuxClAeadModes_Els_Types.h>
#include <internal/mcuxClAeadModes_Common_Functions.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClAeadModes_Modes.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClAead_ModeDescriptor_t mcuxClAead_ModeDescriptor_AES_GCM_ENC = {
  .crypt = mcuxClAeadModes_crypt,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_crypt),

  .init = mcuxClAeadModes_init,
  .protection_token_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_init),
  .processAad = mcuxClAeadModes_process_adata,
  .protection_token_processAad = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process_adata),
  .process = mcuxClAeadModes_process,
  .protection_token_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process),
  .finish = mcuxClAeadModes_finish,
  .protection_token_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_finish),
  .verify = mcuxClAeadModes_verify,
  .protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_verify),
  .algorithm = &mcuxClAeadModes_AlgorithmDescriptor_Aes_Gcm_enc
};

const mcuxClAead_ModeDescriptor_t mcuxClAead_ModeDescriptor_AES_GCM_DEC = {
  .crypt = mcuxClAeadModes_crypt,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_crypt),

  .init = mcuxClAeadModes_init,
  .protection_token_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_init),
  .processAad = mcuxClAeadModes_process_adata,
  .protection_token_processAad = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process_adata),
  .process = mcuxClAeadModes_process,
  .protection_token_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process),
  .finish = mcuxClAeadModes_finish,
  .protection_token_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_finish),
  .verify = mcuxClAeadModes_verify,
  .protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_verify),
  .algorithm = &mcuxClAeadModes_AlgorithmDescriptor_Aes_Gcm_dec
};


const mcuxClAead_ModeDescriptor_t mcuxClAead_ModeDescriptor_AES_CCM_ENC = {
  .crypt = mcuxClAeadModes_crypt,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_crypt),

  .init = mcuxClAeadModes_init,
  .protection_token_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_init),
  .processAad = mcuxClAeadModes_process_adata,
  .protection_token_processAad = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process_adata),
  .process = mcuxClAeadModes_process,
  .protection_token_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process),
  .finish = mcuxClAeadModes_finish,
  .protection_token_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_finish),
  .verify = mcuxClAeadModes_verify,
  .protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_verify),
  .algorithm = &mcuxClAeadModes_AlgorithmDescriptor_Aes_Ccm_enc
};

const mcuxClAead_ModeDescriptor_t mcuxClAead_ModeDescriptor_AES_CCM_DEC = {
  .crypt = mcuxClAeadModes_crypt,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_crypt),

  .init = mcuxClAeadModes_init,
  .protection_token_init = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_init),
  .processAad = mcuxClAeadModes_process_adata,
  .protection_token_processAad = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process_adata),
  .process = mcuxClAeadModes_process,
  .protection_token_process = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_process),
  .finish = mcuxClAeadModes_finish,
  .protection_token_finish = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_finish),
  .verify = mcuxClAeadModes_verify,
  .protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_verify),
  .algorithm = &mcuxClAeadModes_AlgorithmDescriptor_Aes_Ccm_dec
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
