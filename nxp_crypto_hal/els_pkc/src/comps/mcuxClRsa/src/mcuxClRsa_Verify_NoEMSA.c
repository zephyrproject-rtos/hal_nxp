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

/** @file  mcuxClRsa_Verify_NoEMSA.c
 *  @brief mcuxClRsa: function, which is called in case of no encoding message for signature verification
 */


#include <stdint.h>
#include <mcuxClToolchain.h>

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClPkc.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_ImportExport.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>


/**********************************************************/
/* Specification of no-verify mode structure              */
/**********************************************************/
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_NoVerify =
{
  .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Verify_NoEMSA),
  .pHashAlgo1 = NULL,
  .pHashAlgo2 = NULL,
  .pPaddingFunction = mcuxClRsa_Verify_NoEMSA
};


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Verify_NoEMSA, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_Verify_NoEMSA(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput UNUSED_PARAM,
  const uint32_t              inputLength UNUSED_PARAM,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo UNUSED_PARAM,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength UNUSED_PARAM,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Verify_NoEMSA);

  /* Setup UPTR table. */
  const uint32_t cpuWaSizeWord = (((sizeof(uint16_t)) * MCUXCLRSA_INTERNAL_VERIFY_NOEMSA_UPTRT_SIZE) + (sizeof(uint32_t)) - 1u) / (sizeof(uint32_t));
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("16-bit UPTRT table is assigned in CPU workarea")
  uint16_t * pOperands = (uint16_t *) mcuxClSession_allocateWords_cpuWa(pSession, cpuWaSizeWord);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

  const uint32_t keyByteLength = keyBitLength / 8U; /* keyBitLength is a multiple of 8 */
  const uint32_t pkcWaSizeWord = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) / (sizeof(uint32_t));
  uint8_t *pPkcWa = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord);
  if ((NULL == pOperands) || (NULL == pPkcWa))
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Verify_NoEMSA, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFY_NOEMSA_IN] = MCUXCLPKC_PTR2OFFSET(pVerificationInput);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFY_NOEMSA_TMP] = MCUXCLPKC_PTR2OFFSET(pPkcWa);

  /* Set UPTRT table */
  MCUXCLPKC_SETUPTRT(pOperands);

  /* Export result of size BYTE_LENGTH(keyBitLength) from pInput to pOutput in reverse order. */
  const uint32_t ps1OpLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength); /* PS1 length = key byte length rounded up to PKC word size */
  MCUXCLPKC_PS1_SETLENGTH(0u, ps1OpLen);

  MCUXCLPKC_FP_SECUREEXPORTBIGENDIANFROMPKC_BUFFER(mcuxClRsa_noVerify, ret_SecExport, pSession,
                                                               pOutput,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFY_NOEMSA_IN,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFY_NOEMSA_TMP,
                                                               keyByteLength);
  if (MCUXCLPKC_STATUS_OK != ret_SecExport)
  {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Verify_NoEMSA, MCUXCLRSA_STATUS_ERROR);
  }

  mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
  mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

  /* Return error code MCUXCLRSA_STATUS_VERIFYPRIMITIVE_OK. */
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Verify_NoEMSA, MCUXCLRSA_STATUS_VERIFYPRIMITIVE_OK,
      MCUXCLPKC_FP_CALLED_SECUREEXPORTBIGENDIANFROMPKC_BUFFER);
}
