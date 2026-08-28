/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClEcc_EdDSA_InitPrivKeyInputMode.c
 * @brief implementation of mcuxClEcc_EdDSA_InitPrivKeyInputMode function
 */


#include <stdint.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_InitPrivKeyInputMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_InitPrivKeyInputMode(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_GenerationDescriptor_t *generationMode,
    const uint8_t *pPrivKey)
{
   MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_InitPrivKeyInputMode);
   (void) pSession;

  /* The struct EdDSA_GenerateKeyPairDescriptor needs to be initialized as well, as it contains the private key information together with the required option flag.
   * This struct will be put in memory directly after the struct Key_GenerationDescriptor.
   * The customer will provide enough memory for both structures by using MCUXCLECC_EDDSA_GENERATEKEYPAIR_DESCRIPTOR_SIZE to allocate the buffer for the output-param of this function.
   */
   MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Reinterpret structure for mode type, change uint8_t * to mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t *")
   mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t *mode = (mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t *) ((uint8_t *)generationMode + sizeof(mcuxClKey_GenerationDescriptor_t));
   MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
   MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer mode has compatible type and cast was valid")
   mode->options = MCUXCLECC_EDDSA_PRIVKEY_INPUT;
   mode->pPrivKeyInput = pPrivKey;
   MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
   generationMode->pKeyGenFct = mcuxClEcc_EdDSA_GenerateKeyPair;
   generationMode->protectionTokenKeyGenFct = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateKeyPair);
   generationMode->pProtocolDescriptor = (const void *) mode;

   MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(
     mcuxClEcc_EdDSA_InitPrivKeyInputMode,
     MCUXCLECC_STATUS_OK,
     MCUXCLECC_STATUS_FAULT_ATTACK
   );
}

