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

/** @file  mcuxClRsa_pkcs1v15Encode_encrypt.c
 *  @brief mcuxClRsa: function, which is called to execute EME-PKCS1-v1_5
 *  encoding method used for RSAES-PKCS1-V1_5-ENCRYPT encryption operation
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClMemory.h>
#include <mcuxClRandom.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClBuffer_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Encode_encrypt, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Encode_encrypt(
  mcuxClSession_Handle_t       pSession,
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
  const uint32_t keyLen = keyBitLength / 8u; //key bit length is always multiple of 8 bits
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(keyBitLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("False positive, 'keyLen' is larger than 11u, so cannot wrap")
  if(inputLength > (keyLen - 11u))
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_encrypt, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /******************************************************************/
  /* Generate an octet string PS of length keyLen - inputLength - 3 */
  /* consisting of pseudo-randomly generated nonzero octets.        */
  /*******************************************************************/

  /* Length of the PS. */
  const uint32_t psLen = keyLen - inputLength - 3u;
  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  uint8_t *pEM = MCUXCLBUFFER_GET(pOutput);
  uint8_t *pPS = pEM + 2u;

  MCUXCLBUFFER_INIT(pBufPs, NULL, pPS, psLen);
  MCUX_CSSL_FP_FUNCTION_CALL(ret_Prng_GetRandom1, mcuxClRandom_ncGenerate(pSession, pBufPs, psLen));
  if(MCUXCLRANDOM_STATUS_OK != ret_Prng_GetRandom1)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_encrypt, MCUXCLRSA_STATUS_ERROR);
  }

  /* Ensuring that all octets are non-zero */
  uint32_t i = 0;
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t cntPrngGetRandom = 0u);
  while(i < psLen)
  {
    /* If there is zero octet generate new one */
    while(0u == pPS[i])
    {
      MCUXCLBUFFER_SET(pBufPs, pPS + i, psLen);
      MCUX_CSSL_FP_FUNCTION_CALL(ret_Prng_GetRandom2, mcuxClRandom_ncGenerate(pSession, pBufPs, 1u));
      MCUX_CSSL_FP_COUNTER_STMT(++cntPrngGetRandom);
      if(MCUXCLRANDOM_STATUS_OK != ret_Prng_GetRandom2)
      {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_encrypt, MCUXCLRSA_STATUS_ERROR);
      }
    }
    ++i;
  }

  /************************************************************/
  /* Concatenate PS, the message M, and other padding to form */
  /* an encoded message EM of length keyLen octets as         */
  /* EM = 0x00 || 0x02 || PS || 0x00 || M                     */
  /************************************************************/

  pEM[0] = 0x0u;
  pEM[1] = 0x02u;
  pEM[2u + psLen] = 0x0u;
  uint8_t *pM = pEM + 2u + psLen + 1u;

  /* Concatenate message */
  /* TODO Shall be replaced under CLNS-6350 or CLNS-4506: secure (robust) copy shall be used when available */
  MCUX_CSSL_FP_FUNCTION_CALL(read_result, mcuxClBuffer_read(pInput, 0u, (uint8_t *) pM,  inputLength));
  if(MCUXCLBUFFER_STATUS_OK != read_result)
  {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_encrypt, read_result,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
        (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate) * cntPrngGetRandom),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
  }

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_encrypt, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
    (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate) * cntPrngGetRandom),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}
