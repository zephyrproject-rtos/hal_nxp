/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

/** @file  mcuxClRsa_pkcs1v15Encode_encrypt.c
 *  @brief mcuxClRsa: function, which is called to execute EME-PKCS1-v1_5
 *  encoding method used for RSAES-PKCS1-V1_5-ENCRYPT encryption operation
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClBuffer.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClRandom_Internal_Functions.h>

#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Encode_encrypt, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Encode_encrypt(
  mcuxClSession_Handle_t       pSession UNUSED_PARAM,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo UNUSED_PARAM,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength UNUSED_PARAM,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pkcs1v15Encode_encrypt);

  /***********************************************************/
  /* Length checking: If inputLength > keyLen - 11, return   */
  /* MCUXCLRSA_STATUS_INVALID_INPUT.                          */
  /***********************************************************/
  const uint32_t keyLen = keyBitLength / 8U; //key bit length is always multiple of 8 bits
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keyLen, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  if(inputLength > (keyLen - 11U))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inputLength, 0U, keyLen - 11U, MCUXCLRSA_STATUS_INVALID_INPUT)

  /******************************************************************/
  /* Generate an octet string PS of length keyLen - inputLength - 3 */
  /* consisting of pseudo-randomly generated nonzero octets.        */
  /*******************************************************************/

  /* Length of the PS. */
  const uint32_t psLen = keyLen - inputLength - 3U;
  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  uint8_t *pEM = MCUXCLBUFFER_GET(pOutput);
  uint8_t *pPS = pEM + 2U;

  MCUXCLBUFFER_INIT(pBufPs, NULL, pPS, psLen);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, pSession);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, pBufPs);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, psLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_generate_internal(pSession, pBufPs, psLen, NULL));

  /* Ensuring that all octets are non-zero */
  uint32_t i = 0;
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t loopCounterRandGen = 0U);
  while(i < psLen)
  {
    /* If there is zero octet generate new one */
    while(0U == pPS[i])
    {
      MCUX_CSSL_FP_COUNTER_STMT(loopCounterRandGen++);

      MCUXCLBUFFER_INIT(pBufPsI, NULL, &pPS[i], 1U);
      MCUX_CSSL_DI_RECORD(randomGenerateParams, pSession);
      MCUX_CSSL_DI_RECORD(randomGenerateParams, pBufPsI);
      MCUX_CSSL_DI_RECORD(randomGenerateParams, 1U);
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_generate_internal(pSession, pBufPsI, 1U, NULL));
    }
    ++i;
  }

  /************************************************************/
  /* Concatenate PS, the message M, and other padding to form */
  /* an encoded message EM of length keyLen octets as         */
  /* EM = 0x00 || 0x02 || PS || 0x00 || M                     */
  /************************************************************/

  pEM[0] = 0x0U;
  pEM[1] = 0x02U;
  pEM[2U + psLen] = 0x0U;
  uint8_t *pM = pEM + 2U + psLen + 1U;

  /* Concatenate message */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pInput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pM);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inputLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_secure(pInput, 0U, pM, inputLength));

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_encrypt, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal),
    loopCounterRandGen * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_secure));
}
