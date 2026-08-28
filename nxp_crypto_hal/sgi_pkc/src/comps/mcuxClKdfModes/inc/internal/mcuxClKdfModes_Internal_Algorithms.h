/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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
 * @file  mcuxClKdfModes_Internal_Algorithms.h
 * @brief Declarations and definitions for the KDF
 */

#ifndef MCUXCLKDFMODES_INTERNAL_ALGORITHMS_H_
#define MCUXCLKDFMODES_INTERNAL_ALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession.h>
#include <mcuxClKey_Types.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClHashModes_Internal_Memory.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mcuxClKdfModes_WorkArea {
  uint8_t input_Wa[8u];
  uint32_t context_Wa[MCUXCLMAC_MAX_CONTEXT_SIZE_IN_WORDS];
  uint8_t macResult_Wa[MCUXCLCORE_MAX(MCUXCLMAC_MAX_OUTPUT_SIZE, MCUXCLHASH_BLOCK_SIZE_MAX_WITHOUT_MASK)];
} mcuxClKdfModes_WorkArea_t;

/**
 * @brief Key derivation engine function for NIST SP800-108.
 *
 * @param[in]     pSession          Session handle.
 * @param         derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key (word-aligned).
 * @param         inputs            The first element contains the label, the second contains the context and the third contains IV (only for Feedback mode).
 * @param         numberOfInputs    Fixed to 3 for Feedback mode and 2 for other modes.
 * @param[out]    derivedKey        Output key handle (word-aligned).
 *
 * @return mcuxClKey_Status_t
 * @retval MCUXCLKEY_STATUS_OK              If the key derivation was succesful.
 * @retval MCUXCLKEY_STATUS_INVALID_INPUT
 * @retval MCUXCLKEY_STATUS_ERROR           If the key derivation was not succesful.
 * @retval MCUXCLKEY_STATUS_INVALID_INPUT
 * @retval MCUXCLKEY_STATUS_FAULT_ATTACK    In case of a fault attack
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_derivationEngine_NIST_SP800_108, mcuxClKey_DerivationEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_derivationEngine_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[],
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKDFMODES_INTERNAL_ALGORITHMS_H_ */
