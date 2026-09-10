/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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

/** @file  mcuxClRsa_Sign_NoEMSA.c
 *  @brief mcuxClRsa: function, which is called in case of no encoding message for signature
 */


#include <stdint.h>
#include <mcuxClToolchain.h>

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClPkc.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_ImportExport.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>

/**********************************************************/
/* Specification of no-encode mode structure              */
/**********************************************************/
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_NoEncode =
{
  .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Sign_NoEMSA),
  .pHashAlgo1 = NULL,
  .pHashAlgo2 = NULL,
  .pPaddingFunction = mcuxClRsa_Sign_NoEMSA
};

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Sign_NoEMSA, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_Sign_NoEMSA(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength UNUSED_PARAM,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo UNUSED_PARAM,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength UNUSED_PARAM,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Sign_NoEMSA);

  /* Setup UPTR table. */
  const uint32_t cpuWaSizeWord = (((sizeof(uint16_t)) * MCUXCLRSA_INTERNAL_SIGN_NOEMSA_UPTRT_SIZE) + (sizeof(uint32_t)) - 1u) / (sizeof(uint32_t));
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("16-bit UPTRT table is assigned in CPU workarea")
  uint16_t * pOperands = (uint16_t *) mcuxClSession_allocateWords_cpuWa(pSession, cpuWaSizeWord);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()
  if (NULL == pOperands)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Sign_NoEMSA, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  uint8_t *pOutputPointer = MCUXCLBUFFER_GET(pOutput);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_SIGN_NOEMSA_OUT] = MCUXCLPKC_PTR2OFFSET(pOutputPointer);

  /* Set UPTRT table */
  MCUXCLPKC_SETUPTRT(pOperands);

  /* Export message of size BYTE_LENGTH(keyBitLength) from pInput to pOutput in reverse order. */

  uint32_t keyByteLength = keyBitLength / 8U; /* keyBitLength is a multiple of 8 */
  const uint32_t ps1OpLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength); /* PS1 length = key byte length rounded up to PKC word size */
  MCUXCLPKC_PS1_SETLENGTH(0u, ps1OpLen);

  MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClRsa_Sign_NoEMSA, MCUXCLRSA_INTERNAL_UPTRTINDEX_SIGN_NOEMSA_OUT, pInput, keyByteLength);

  mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

  /* Return error code MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK. */
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Sign_NoEMSA, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
          MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER);
}
