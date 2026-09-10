/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClRsa_PssVerify.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PSS-VERIFY
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClMemory.h>
#include <mcuxClBuffer.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>

#include <internal/mcuxClHash_Internal.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslMemory.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>

#include <internal/mcuxClBuffer_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>


/**********************************************************/
/* Specification of PSS-verify mode structures            */
/**********************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_224 =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify),
  .pHashAlgo1 = &mcuxClHash_AlgorithmDescriptor_Sha224,
  .pHashAlgo2 = NULL,
  .pPaddingFunction = mcuxClRsa_pssVerify
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_256 =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify),
  .pHashAlgo1 = &mcuxClHash_AlgorithmDescriptor_Sha256,
  .pHashAlgo2 = NULL,
  .pPaddingFunction = mcuxClRsa_pssVerify
};
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_384 =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify),
  .pHashAlgo1 = &mcuxClHash_AlgorithmDescriptor_Sha384,
  .pHashAlgo2 = NULL,
  .pPaddingFunction = mcuxClRsa_pssVerify
};
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_512 =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify),
  .pHashAlgo1 = &mcuxClHash_AlgorithmDescriptor_Sha512,
  .pHashAlgo2 = NULL,
  .pPaddingFunction = mcuxClRsa_pssVerify
};

/* Define to avoid preprocessor directives inside the function exit macro,
   as this would violate the MISRA rule 20.6 otherwise. */
#define FP_RSA_PSSVERIFY_SWITCHENDIANNESS \
  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness)

/* Macros to switch endianness */
#define MCUXCLRSA_INTERNAL_SWITCHENDIANNESS(ptr, length)  MCUXCLPKC_FP_SWITCHENDIANNESS(ptr, length)


/**
 * @brief This function calculate mHash = Hash(M), an octet string of length hLen.
 *
 * @param[in]   pSession            Handle for the current CL session.
 * @param[in]   pInput              Pointer to input
 * @param[in]   inputLength         Size of Input
 * @param[out]  pHashAlgo           Pointer to hash algorithm information
 * @param[in]   pMHash              Pointer to the buffer for the mHash in the M
 * @param[in]   options             Options field
 *
 * @return statusCode
 * @retval MCUXCLRSA_STATUS_OK             Is returned when checks are passing.
 * @retval MCUXCLRSA_STATUS_ERROR          n error occurred during the execution. In that case, expectations for the flow protection are not balanced.
 * @retval MCUXCLRSA_STATUS_VERIFY_FAILED  Is returned when checks are not passing.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pssVerify_Hash_modulo_m)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssVerify_Hash_modulo_m(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  mcuxClHash_Algo_t            pHashAlgo,
  uint8_t *                   pMHash,
  const uint32_t              options)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pssVerify_Hash_modulo_m);

  const uint32_t hLen = pHashAlgo->hashSize;

  if(MCUXCLRSA_OPTION_MESSAGE_PLAIN == (options & MCUXCLRSA_OPTION_MESSAGE_MASK))
  {
    /* Call hash function on pInput (Hash(pInput)) and store result in buffer mHash */
    uint32_t hashOutputSize = 0u;

    MCUXCLBUFFER_INIT(pMHashBuf, NULL, pMHash, hLen);
    MCUX_CSSL_FP_FUNCTION_CALL(hash_result1, mcuxClHash_compute(pSession,
                                                              pHashAlgo,
                                                              pInput,
                                                              inputLength,
                                                              pMHashBuf,
                                                              &hashOutputSize
    ));

    if(MCUXCLHASH_STATUS_OK != hash_result1)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify_Hash_modulo_m, MCUXCLRSA_STATUS_ERROR);
    }
  }
  else if (MCUXCLRSA_OPTION_MESSAGE_DIGEST == (options & MCUXCLRSA_OPTION_MESSAGE_MASK))
  {
    /* Copy pInput to buffer mHash */
    MCUX_CSSL_FP_FUNCTION_CALL(read_result, mcuxClBuffer_read(pInput, 0u, pMHash, hLen));
    if(MCUXCLBUFFER_STATUS_OK != read_result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify_Hash_modulo_m, read_result,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
    }
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify_Hash_modulo_m, MCUXCLRSA_STATUS_ERROR);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify_Hash_modulo_m, MCUXCLRSA_STATUS_OK,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_OPTION_MESSAGE_PLAIN == (options & MCUXCLRSA_OPTION_MESSAGE_MASK)),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute)),
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_OPTION_MESSAGE_DIGEST == (options & MCUXCLRSA_OPTION_MESSAGE_MASK)),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)));
}

/**
 * @brief This function checks the lengths of pssVerify inputs, as well as the value of the first padding bytes.
 *
 * @param       keyBitLength        Key length in bit
 * @param[in]   hLen                Hash function output length
 * @param[out]  sLen                EMSA-PSS salt length
 * @param[in]   emLen               Encoded message length
 * @param[in]   em                  First byte of encoded message
 *
 * @return statusCode
 * @retval MCUXCLRSA_STATUS_OK             Is returned when checks are passing.
 * @retval MCUXCLRSA_STATUS_VERIFY_FAILED  Is returned when checks are not passing.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pssVerify_sizeAndBytes_check)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssVerify_sizeAndBytes_check(const uint32_t keyBitLength,
                                                                                            const uint32_t hLen,
                                                                                            const uint32_t sLen,
                                                                                            const uint32_t emLen,
                                                                                            const uint8_t em)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pssVerify_sizeAndBytes_check);

  /* Step 3: If BYTE_LENGTH(keyBitLength) < (pHashAlgo->hashSize + saltlabelLength + 2)
  *  return MCUXCLRSA_STATUS_VERIFY_FAILED else continue operation. */
  /* Additional checks on salt-length for FIPS 186-4 compliance */
  /* The constraint on sLen for FIPS186.5 is always met, so no additional check is needed. In step 10, we check that the zero-padding has the expected length w.r.t. sLen. */
  /* Step 4: Check if the leftmost octet of Em (before endianess switch) has hexadecimal value 0xbc.*/
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Because 'hLen' = 'hashSize' is lower than key size will not case result wrapping even after multiplying by 8u.")
  if((((1024U == keyBitLength) && (512U == (8U * hLen)) && ((hLen - 2U) < sLen)) || (hLen < sLen))
          || (emLen < (hLen + sLen + 2U)) || (0xbcU != em))
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify_sizeAndBytes_check, MCUXCLRSA_STATUS_VERIFY_FAILED);
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify_sizeAndBytes_check, MCUXCLRSA_STATUS_OK);
  }
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pssVerify, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssVerify(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput UNUSED_PARAM,
  uint32_t * const            pOutLength UNUSED_PARAM)
{

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pssVerify);

  /* Setup session. */

  /* Length of the encoded message. */
  const uint32_t emLen = keyBitLength / 8U; /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  /* Length of padding with 8 zero bytes. */
  const uint32_t padding1Length = MCUXCLRSA_PSS_PADDING1_LEN;
  /* Length of the output of hash function. */
  const uint32_t hLen = pHashAlgo->hashSize;
  /* Length of the EMSA-PSS salt. */
  const uint32_t sLen = saltlabelLength;
  /* Length of DB (and maskedDB). */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Because 'keyBitLength' is larger than 'hashSize', won't wrap")
  const uint32_t dbLen = emLen - hLen - 1U;

  const uint16_t wordSizePkcWa = (uint16_t)(MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WAPKC_SIZE_WO_MGF1(emLen) / sizeof(uint32_t));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa);
  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /*
   * Set buffers in PKC workarea
   * PKC = | M'= (padding | mHash | salt) || dbMask (and DB) || H' |
   */
  /* Pointer to the encoded message */
  uint8_t *pEm = pVerificationInput;
  /* Pointer to the buffer for the M' = | padding_1 | mHash | salt | */
  uint8_t *pMprim = pPkcWorkarea;
  /* Pointer to the buffer for the mHash in the M'*/
  uint8_t *pMHash = pMprim + padding1Length;
  /* Pointer to the buffer for the salt in the M'*/
  uint8_t *pSalt = pMHash + hLen;

  /* Pointer to the buffer for the dbMask' (must be aligned to CPU word size)*/
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("After aligned, the 'sLen' will not wrapped.")
  uint8_t *pDbMask = pSalt + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sLen);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  /* Pointer to the buffer for the H' */
  uint8_t *pHprim = pDbMask + dbLen;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Sum of operation will not wrapped.")
  const uint32_t mprimLen = padding1Length + hLen + sLen;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  /* Step 2: Let mHash = Hash(M), an octet string of length hLen. */
  MCUX_CSSL_FP_FUNCTION_CALL(ret_Hash_modulo, mcuxClRsa_pssVerify_Hash_modulo_m(pSession,
                                                                              pInput,
                                                                              inputLength,
                                                                              pHashAlgo,
                                                                              pMHash,
                                                                              options));

  if(MCUXCLRSA_STATUS_OK != ret_Hash_modulo)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, ret_Hash_modulo,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_Hash_modulo_m));
  }

  /* Step 3: If BYTE_LENGTH(keyBitLength) < (pHashAlgo->hashSize + saltlabelLength + 2)
  *  return MCUXCLRSA_STATUS_VERIFY_FAILED else continue operation. */
  /* Additional checks on salt-length for FIPS 186-4 compliance */
  /* The constraint on sLen for FIPS186.5 is always met, so no additional check is needed. In step 10, we check that the zero-padding has the expected length w.r.t. sLen. */
  /* Step 4: Check if the leftmost octet of Em (before endianess switch) has hexadecimal value 0xbc.*/
  MCUX_CSSL_FP_FUNCTION_CALL(ret_sizeAndBytes_check, mcuxClRsa_pssVerify_sizeAndBytes_check(keyBitLength,
                                                                                          hLen,
                                                                                          sLen,
                                                                                          emLen,
                                                                                          *pEm));

  if(MCUXCLRSA_STATUS_OK != ret_sizeAndBytes_check)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_VERIFY_FAILED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_Hash_modulo_m),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_sizeAndBytes_check));
  }

  /* Switch endianess of EM buffer to big-endian byte order in place */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting is needed by API function.")
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("the pEm PKC buffer is CPU word aligned.")
  MCUXCLRSA_INTERNAL_SWITCHENDIANNESS((uint32_t *) pEm, emLen);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  /* Step 5: Let maskedDB be the leftmost emLen-hLen-1 octets of EM and let H be the next hLen octets. */
  uint8_t *maskedDB = pEm;
  uint8_t *pH = pEm + dbLen;

  /* Step 6: Check if 8*emLen-emBits leftmost bits equal to zero. Note that, as keyBitLength is a multiple of 8, 8 * emLen - emBits = 1 bit.*/
  if(0U != ((*maskedDB) & 0x80u))
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_VERIFY_FAILED,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_Hash_modulo_m),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_sizeAndBytes_check),
          FP_RSA_PSSVERIFY_SWITCHENDIANNESS);
  }

  /* Step 7: dbMask = MGF(H, BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - 1) */

  MCUX_CSSL_FP_FUNCTION_CALL(retVal_mcuxClRsa_mgf1, mcuxClRsa_mgf1(pSession, pHashAlgo, pH, hLen, dbLen, pDbMask));

  if(MCUXCLRSA_STATUS_INTERNAL_MGF_OK != retVal_mcuxClRsa_mgf1)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_ERROR);
  }

  /* Step 8: DB = pOutput(0 : BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - 1) XOR dbMask.*/
  uint8_t *pDB = pDbMask; // reuse the space of DbMask

  MCUX_CSSL_FP_LOOP_DECL(loop1);
  for(uint32_t i = 0u; i < dbLen; ++i)
  {
    *(pDB + i) = *(maskedDB + i) ^ *(pDbMask + i);
     MCUX_CSSL_FP_LOOP_ITERATION(loop1);
  }

  /* Step 9: Set the leftmost 8emLen - emBits bits of the leftmost octet in DB to zero. */
  pDB[0] &= 0x7Fu;

  /* Step 10 */
  /* Check (DB(0 : BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - saltlabelLength - 2) == [0x00, ..., 0x00])
   * and that (DB(BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - saltlabelLength - 1) == 0x01) ? */
  uint32_t counterZeros = 0u;
  const uint32_t padding2Length = emLen - hLen - sLen - 2u;

  MCUX_CSSL_FP_LOOP_DECL(loop2);
  for(uint32_t i = 0u; i < padding2Length; ++i)
  {
    if(0u == pDB[i])
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Because 'padding2Length'is less then 2^32 than counterZeros won't wrap")
        ++counterZeros;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }
    MCUX_CSSL_FP_LOOP_ITERATION(loop2);
  }
  if((counterZeros != padding2Length) || (0x01u != pDB[padding2Length]))
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_VERIFY_FAILED,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_Hash_modulo_m),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_sizeAndBytes_check),
          FP_RSA_PSSVERIFY_SWITCHENDIANNESS,
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
          MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, dbLen),
          MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, padding2Length));
  }

  /* Step 11: Copy salt to mPrime buffer */
  MCUXCLMEMORY_FP_MEMORY_COPY(pSalt, pDB + dbLen - sLen, sLen);

  /* Step 12 */
  /* mPrime = [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 || mHash || DB(BYTE_LENGTH(keyBitLength) - saltlabelLength: BYTE_LENGTH(keyBitLength))] */
  MCUXCLMEMORY_FP_MEMORY_CLEAR(pMprim, padding1Length);

  /* Step 13: HPrime = Hash(mPrime) */
  uint32_t hashOutputSize = 0u;
  MCUXCLBUFFER_INIT_RO(pMprimBuf, NULL, pMprim, padding1Length);
  MCUXCLBUFFER_INIT(pHprimBuf, NULL, pHprim, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL(hash_result_2, mcuxClHash_compute(pSession,
                                                             pHashAlgo,
                                                             pMprimBuf,
                                                             mprimLen,
                                                             pHprimBuf,
                                                             &hashOutputSize
    ));

  if(MCUXCLHASH_STATUS_OK != hash_result_2)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_ERROR);
  }

  /* Step 14 verify5 = (HPrime == H) ? true : false. */
#ifndef MCUXCL_FEATURE_PKC_PKCRAM_NO_UNALIGNED_ACCESS
  MCUX_CSSL_FP_FUNCTION_CALL(compare_result, mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u, pH, pHprim, hLen),
                                                                  pH,
                                                                  pHprim,
                                                                  hLen));

  mcuxClRsa_Status_t pssVerifyStatus1 = MCUXCLRSA_STATUS_VERIFY_FAILED;
  if(compare_result == MCUXCSSLMEMORY_STATUS_EQUAL)
  {
    pssVerifyStatus1 = MCUXCLRSA_STATUS_VERIFY_OK;
  }
#else
  /* Becasue pH and pHprim are unaligned and taking into account the properties:
   * - dbLen = emLen - hLen - 1U
   * - emLen % CpuWord = 0
   * - hLen % CpuWord = 0
   * - pEm % CpuWord = 0
   * - pDbMask % CpuWord = 0
   * - pH % CpuWord = CpuWord-unalignedBytes
   * - pHprim  % CpuWord = CpuWord-unalignedBytes
   * - unalignedBytes = (CpuWord - dbLen) & (CpuWord - 1) <- it is unaligned part of pH and pHprim
   * , the first unalignedBytes bytes will be compared separately (byte-wise) then the rest will be compared with aligned address.
   */
  uint32_t unalignedBytes = ((sizeof(uint32_t)) - dbLen) & ((sizeof(uint32_t)) - 1u);
  MCUX_CSSL_FP_FUNCTION_CALL(compare_result1, mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u, pH, pHprim, unalignedBytes),
                                                                  pH,
                                                                  pHprim,
                                                                  unalignedBytes));

  MCUX_CSSL_FP_FUNCTION_CALL(compare_result2, mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u, pH + unalignedBytes,
                                                                  pHprim + unalignedBytes, hLen - unalignedBytes),
                                                                  pH + unalignedBytes,
                                                                  pHprim + unalignedBytes,
                                                                  hLen - unalignedBytes));

  mcuxClRsa_Status_t pssVerifyStatus1 = MCUXCLRSA_STATUS_VERIFY_FAILED;
  if((compare_result1 == MCUXCSSLMEMORY_STATUS_EQUAL) && (compare_result2 == MCUXCSSLMEMORY_STATUS_EQUAL))
  {
    pssVerifyStatus1 = MCUXCLRSA_STATUS_VERIFY_OK;
  }
#endif


  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

/* Use temporary defines to avoid preprocessor directives inside the function exit macro below,
   as this would violate the MISRA rule 20.6 otherwise. */
#if defined(MCUXCL_FEATURE_PKC_PKCRAM_NO_UNALIGNED_ACCESS)
  #define FP_RSA_PSSVERIFY_COMPARISON_1 \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)
#else
  #define FP_RSA_PSSVERIFY_COMPARISON_1 \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)
#endif

  #define FP_RSA_PSSVERIFY_COMPARISON FP_RSA_PSSVERIFY_COMPARISON_1


  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, pssVerifyStatus1,

    FP_RSA_PSSVERIFY_SWITCHENDIANNESS,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_Hash_modulo_m),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify_sizeAndBytes_check),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
    MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, dbLen),
    MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, padding2Length),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
    FP_RSA_PSSVERIFY_COMPARISON
  );

#undef FP_RSA_PSSVERIFY_COMPARISON

}
