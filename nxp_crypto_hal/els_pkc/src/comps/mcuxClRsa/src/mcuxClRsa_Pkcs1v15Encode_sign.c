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

/** @file  mcuxClRsa_Pkcs1v15Encode_sign.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PKCS1-v1_5-ENCODE
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClMemory.h>
#include <mcuxClBuffer.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClBuffer_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>


/**********************************************************/
/* Hash algorithm identifiers as DigestInfo types         */
/**********************************************************/
static const uint8_t mcuxClRsa_oidSha2_224[] = {0x30, 0x2d, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
                                       0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x04, 0x05,
                                       0x00, 0x04, 0x1c};

static const uint8_t mcuxClRsa_oidSha2_256[] = {0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
                                       0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
                                       0x00, 0x04, 0x20};

static const uint8_t mcuxClRsa_oidSha2_384[] = {0x30, 0x41, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
                                       0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02, 0x05,
                                       0x00, 0x04, 0x30};

static const uint8_t mcuxClRsa_oidSha2_512[] = {0x30, 0x51, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
                                       0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03, 0x05,
                                       0x00, 0x04, 0x40};

struct mcuxClRsa_oid_t {
  size_t length;
  const uint8_t * value;
};

static const struct mcuxClRsa_oid_t mcuxClRsa_oidTable[] = {
  { sizeof(mcuxClRsa_oidSha2_224), mcuxClRsa_oidSha2_224 },
  { sizeof(mcuxClRsa_oidSha2_256), mcuxClRsa_oidSha2_256 },
  { sizeof(mcuxClRsa_oidSha2_384), mcuxClRsa_oidSha2_384 },
  { sizeof(mcuxClRsa_oidSha2_512), mcuxClRsa_oidSha2_512 }
};

#define DIGESTSIZE_TO_INDEX(len) (((len) - 16u) / 16u)
  ///< Formula for calculating the OID table index from the digest size

/**********************************************************/
/* Specifications of PKCS#1 v1.5 mode structures          */
/**********************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_224 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha224,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Encode_sign
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_256 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha256,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Encode_sign
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_384 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha384,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Encode_sign
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_512 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha512,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Encode_sign
};


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Encode_sign, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Encode_sign(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength UNUSED_PARAM,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pkcs1v15Encode_sign);
  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Length of the encoded message. */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(keyBitLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(pHashAlgo->hashSize, MCUXCLHASH_OUTPUT_SIZE_MD5, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)

  const uint32_t emLen = (keyBitLength + 7u) / 8u; /* byte length, rounded up */
  /* Length of the output of hash function. */
  const uint32_t hLength = pHashAlgo->hashSize;

  /* Length of the T-padding containing the hash algorithm identifier. */
  uint8_t const * phashAlgorithmIdentifier     = mcuxClRsa_oidTable[DIGESTSIZE_TO_INDEX(hLength)].value;
  /* Length of the T-padding DigestInfo containing the hash algorithm identifier. */
  const uint32_t hashAlgorithmIdentifierLength = mcuxClRsa_oidTable[DIGESTSIZE_TO_INDEX(hLength)].length;

  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(hashAlgorithmIdentifierLength, 19u, 19u, MCUXCLRSA_STATUS_INVALID_INPUT)

  /* Number of required padding bytes */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("'emLen' is larger than 'hashAlgorithmIdentifierLength' result cannot overflow.")
  const uint32_t paddingLength = emLen - hashAlgorithmIdentifierLength - hLength - 3u;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  /*****************************************************/
  /* If emLen < tLen + 11, return 'invalid input'.     */
  /*****************************************************/
  if(emLen < (hashAlgorithmIdentifierLength + hLength + 11u))
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /*****************************************************/
  /* Prepare the padding                               */
  /*****************************************************/
  /* Setup session. */
  const uint32_t wordSizePkcWa = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(emLen) / (sizeof(uint32_t));
  uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa);
  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /*
   * Set buffers in PKC workarea
   * PKC = | 0x00 || 0x01 || PS || 0x00 | T || H |
   */
  /* General pointer to encoded message at the beginning of the buffer */
  uint8_t *pEm = pPkcWorkarea;
  /* Pointer to the buffer for the padding bytes PS */
  uint8_t *pPs = pEm + 2u;
  /* Pointer to the buffer for the algorithm identifier T */
  uint8_t *pT = pPs + paddingLength + 1u;

  /* Pointer to the buffer for the hash H */
  uint8_t *pH = pT + hashAlgorithmIdentifierLength;


  /* Write 0x00 0x01 prefix */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Because 'pEm' has allocated 2 bytes, 'pEm + 1u' still inside area")
  *(pEm)     = (uint8_t) 0x00;
  *(pEm + 1u) = (uint8_t) 0x01;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  /* Write padding bytes */
  MCUXCLMEMORY_FP_MEMORY_SET_WITH_BUFF(pPs, 0xFFU, paddingLength, emLen - 2u);

  /* Write 0x00 divider */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Because 'pPs' has size 'paddingLength' area access will be not out of array")
  *(pPs + paddingLength) = (uint8_t) 0x00;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  /* Write DigestInfo T */
  MCUXCLMEMORY_FP_MEMORY_COPY(pT, phashAlgorithmIdentifier, hashAlgorithmIdentifierLength);

  /*****************************************************/
  /* Perform hash operation or just copy the digest    */
  /*****************************************************/
  if(MCUXCLRSA_OPTION_MESSAGE_PLAIN == (options & MCUXCLRSA_OPTION_MESSAGE_MASK))
  {
    /* Call hash function on pInput and store the result in the buffer at pH */
    uint32_t hashOutputSize = 0u;

    MCUXCLBUFFER_INIT(pHBuf, NULL, pH, hLength);
    MCUX_CSSL_FP_FUNCTION_CALL(hash_result, mcuxClHash_compute(pSession,
                                                             pHashAlgo,
                                                             pInput,
                                                             inputLength,
                                                             pHBuf,
                                                             &hashOutputSize

    ));
    if(MCUXCLHASH_STATUS_OK != hash_result)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_ERROR);
    }
  }
  else if (MCUXCLRSA_OPTION_MESSAGE_DIGEST == (options & MCUXCLRSA_OPTION_MESSAGE_MASK))
  {
    /* Copy pInput to buffer at pH (located at the end of the buffer) */
    MCUX_CSSL_FP_FUNCTION_CALL(read_result, mcuxClBuffer_read(pInput, 0u, pH, hLength));
    if(MCUXCLBUFFER_STATUS_OK != read_result)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, read_result,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
    }
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_ERROR);
  }

  /*****************************************************/
  /* Prepare the encoded message for output            */
  /*****************************************************/

  /* Copy encoded message to pOutput and switch the endianness */
  MCUX_CSSL_FP_FUNCTION_CALL(writeStatus, mcuxClBuffer_write_reverse(pOutput, 0u, pPkcWorkarea, emLen));

  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

  if(MCUXCLBUFFER_STATUS_OK != writeStatus)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_OPTION_MESSAGE_PLAIN == (options & MCUXCLRSA_OPTION_MESSAGE_MASK)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute)),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_OPTION_MESSAGE_DIGEST == (options & MCUXCLRSA_OPTION_MESSAGE_MASK)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_reverse));
  }

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_OPTION_MESSAGE_PLAIN == (options & MCUXCLRSA_OPTION_MESSAGE_MASK)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute)),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_OPTION_MESSAGE_DIGEST == (options & MCUXCLRSA_OPTION_MESSAGE_MASK)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_reverse));
}
