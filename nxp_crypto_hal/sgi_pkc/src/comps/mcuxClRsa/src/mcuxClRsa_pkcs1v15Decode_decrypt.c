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

/** @file  mcuxClRsa_pkcs1v15Decode_decrypt.c
 *  @brief mcuxClRsa: function, which is called to execute EME-PKCS1-v1_5
 *  decoding method used for RSAES-PKCS1-V1_5-DECRYPT decryption operation
 */

#include <mcuxClCore_Platform.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClMemory_Internal.h>

#include <mcuxClBuffer.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClPrng_Internal.h>

#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>

/**
 * Definitions for constant values
 */
#define MCUXCLRSA_CHECK1_OK        (0x0001UL)
#define MCUXCLRSA_CHECK1_NOT_OK    (0x0004UL)
#define MCUXCLRSA_CHECK2_OK        (0x0010UL)
#define MCUXCLRSA_CHECK2_NOT_OK    (0x0040UL)
#define MCUXCLRSA_CHECK3_OK        (0x0100UL)
#define MCUXCLRSA_CHECK3_NOT_OK    (0x0400UL)
#define MCUXCLRSA_CHECK4_OK        (0x1000UL)
#define MCUXCLRSA_CHECK4_NOT_OK    (0x4000UL)

#define MCUXCLRSA_ALL_BITS_OK      (MCUXCLRSA_CHECK1_OK | MCUXCLRSA_CHECK2_OK | MCUXCLRSA_CHECK3_OK | MCUXCLRSA_CHECK4_OK)
#define MCUXCLRSA_MASK_CHECK_BITS  (~(MCUXCLRSA_CHECK1_OK | MCUXCLRSA_CHECK1_NOT_OK | MCUXCLRSA_CHECK2_OK | MCUXCLRSA_CHECK2_NOT_OK  \
                                  | MCUXCLRSA_CHECK3_OK | MCUXCLRSA_CHECK3_NOT_OK | MCUXCLRSA_CHECK4_OK | MCUXCLRSA_CHECK4_NOT_OK))


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Decode_decrypt, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Decode_decrypt(
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
  uint32_t * const            pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pkcs1v15Decode_decrypt);

  /* Encoded message */
  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  const uint8_t *pEM = (const uint8_t *)MCUXCLBUFFER_GET(pInput);

  /* Size Encoded message */
  const uint32_t emLen = keyBitLength / 8U; //key bit length is always multiple of 8 bits
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  /* Results accumulated of the four checks whether verification passed or failed */
  volatile uint32_t check = 0x0UL;

  /************************************************************************************************/
  /* Secure computation of PS length and value 0x00 location                                      */
  /************************************************************************************************/

  /* Generate a random byte not equal to 0x1 for XOR with the whole encoded message pEM */
  MCUX_CSSL_FP_FUNCTION_CALL(random32, mcuxClPrng_generate_word());
  uint8_t rndByte = (uint8_t)(random32 & 0xFFU);
  rndByte |= 0x02U;

  /* XOR the encoded message with the random byte and place it in the PKC RAM */
  const uint32_t wordSizePkcWa = MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WAPKC_SIZE(emLen);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pMaskedEMTemp, mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa / sizeof(uint32_t)));

  MCUX_CSSL_DI_RECORD(mcuxClMemory_XORWithConst_secure_int, (uint32_t) pMaskedEMTemp + (uint32_t) pEM + (uint32_t) emLen);
  MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pMaskedEMTemp, pEM, rndByte, emLen);

  const uint8_t* pMaskedEM = (const uint8_t*) pMaskedEMTemp;
  const uint8_t* pPS = pMaskedEM + 2U;
  uint8_t T[2] = {1U, 1U};
  uint32_t messageLen[2] = {0}; /* messageLen[0] - will contains length of message, messageLen[1] - will contains PS length + 1 */

  for(uint32_t i = 0U; i < (emLen - 2U); ++i)
  {
    uint8_t index = (T[1] != rndByte) ? 1U : 0U;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(messageLen[index], 0U, emLen - 2U, MCUXCLRSA_STATUS_INVALID_INPUT)
    messageLen[index] += 1U;
    T[index] = pPS[i * index];
  }

  /************************************************************************************************/
  /* There should be octet with hexadecimal value 0x00 to separate PS from M                      */
  /************************************************************************************************/

  uint32_t psLen = messageLen[1] - 1U;
  check |= (rndByte == pPS[psLen]) ? MCUXCLRSA_CHECK1_OK : MCUXCLRSA_CHECK1_NOT_OK;

  /************************************************************************************************/
  /* The length of PS should be at least eight octets                                             */
  /************************************************************************************************/

  check |= (7U < psLen) ? MCUXCLRSA_CHECK2_OK : MCUXCLRSA_CHECK2_NOT_OK;

  /************************************************************************************************/
  /* Check if the first octet of EM has hexadecimal value 0x00 (rndByte=0x00^rndByte)             */
  /************************************************************************************************/

  check |= (rndByte == pMaskedEM[0]) ? MCUXCLRSA_CHECK3_OK : MCUXCLRSA_CHECK3_NOT_OK;

  /************************************************************************************************/
  /* Check if the second octet of EM has hexadecimal value 0x02                                   */
  /************************************************************************************************/

  check |= ((0x2U^rndByte) == pMaskedEM[1]) ? MCUXCLRSA_CHECK4_OK : MCUXCLRSA_CHECK4_NOT_OK;

  /* Verify that all checks passed, and no failure */
  MCUX_CSSL_DI_RECORD(verifyDecodeChecks, check);
  if(0U != (MCUXCLRSA_MASK_CHECK_BITS & check))
  {
    MCUXCLSESSION_FAULT(pSession, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }
  else if(MCUXCLRSA_ALL_BITS_OK != check)
  {
    /* Free session area */
    mcuxClSession_freeWords_pkcWa(pSession, emLen / sizeof(uint32_t));
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }
  else
  {
    /* Empty else-statement */
  }


  /* Copy message to the output buffer */
  *pOutLength = messageLen[0];
  const uint8_t *pM = pEM + 2U + messageLen[1];

  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure, pOutput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure, pM);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure, messageLen[0]);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write_secure(pOutput, 0U, pM, messageLen[0]));

  /* Free session area */
  mcuxClSession_freeWords_pkcWa(pSession, emLen / sizeof(uint32_t));

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/

  MCUX_CSSL_DI_EXPUNGE(verifyDecodeChecks, MCUXCLRSA_ALL_BITS_OK);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Decode_decrypt, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_secure));
}
