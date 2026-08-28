/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2024-2026 NXP                                            */
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

/** @file  mcuxClRsa_VerifyE.c
 *  @brief mcuxClRsa: function, which is called to check if E is FIPS compliant
 *  (i.e., is odd values in the range 2^16 < e < 2^256) and determines its
 *  length without leading zeros..
 */


#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_VerifyE)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_VerifyE(mcuxClSession_Handle_t pSession, mcuxClRsa_KeyEntry_t *pE, uint32_t *exactLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_VerifyE);

  mcuxClRsa_Status_t status = MCUXCLKEY_STATUS_INVALID_INPUT;

  /* Determine the exact length of e */
  uint32_t eLength = pE->keyEntryLength;

  while(eLength > 0U)
  {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pE->keyEntryLength >= e, so pE->keyEntryLength - eLength can't be negatie")
    if(0u != pE->pKeyEntryData[pE->keyEntryLength - eLength])
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    {
      break;
    }
    --eLength;
  }

  /* Check if it is the range 2^16 < e < 2^256 */
  if((eLength > 2U)  && (eLength < 33U))
  {
    /* Check if E is odd */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pE->keyEntryLength must be bigger than 1u when enter this branch")
    if(0x1u == (pE->pKeyEntryData[pE->keyEntryLength - 1U] % 2U))
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    {
      /* Set exact length of E */
      *exactLength = eLength;
      status = MCUXCLKEY_STATUS_OK;
    }
  }

  /* If the exponent E is not FIPS compliant, return MCUXCLKEY_STATUS_INVALID_INPUT */
  if(MCUXCLKEY_STATUS_OK != status)
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_VerifyE);
}
