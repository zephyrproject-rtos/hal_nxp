/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

/** @file  mcuxClRsa_KeyGeneration_Plain.c
 *  @brief mcuxClRsa: implementation of RSA key generation function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>
#include <mcuxClMath.h>
#include <mcuxClMemory.h>
#include <mcuxClPkc.h>
#include <mcuxClRandom.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_Types.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyGeneration_Plain)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_KeyGeneration_Plain(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Type_t type,
  mcuxClKey_Protection_t protection,
  mcuxClKey_Handle_t privKey,
  uint8_t * pPrivData,
  uint32_t * const pPrivDataLength,
  mcuxClKey_Handle_t pubKey,
  uint8_t * pPubData,
  uint32_t * const pPubDataLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyGeneration_Plain);

  uint32_t byteLenE = 0u;
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_KeyGenInit, mcuxClRsa_KeyGeneration_Init(
    pSession,
    type,
    &byteLenE));

  if(MCUXCLRSA_STATUS_OK != retVal_KeyGenInit)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, retVal_KeyGenInit,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyGeneration_Init));
  }

  /* 4. Initialize PKC. */
  mcuxClPkc_State_t pkcStateBackup;
  mcuxClPkc_State_t *pPkcStateBackup = &pkcStateBackup;
  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, pPkcStateBackup, mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);

  /*
   * 5. Allocate buffers in PKC RAM
   *    - size aligned to PKC word
   *    - they are be stored in little-endian byte order
   *    Memory layout: | nDash (FW) | P (pkcByteLenPrime) | nDash (FW) | Q (pkcByteLenPrime) | E (pkcByteLenKey) |
   */
  const uint32_t bitLenKey = type->size;
  const uint32_t byteLenKey = bitLenKey / 8u;
  const uint32_t pkcByteLenKey = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenKey);
  const uint32_t byteLenPrime = byteLenKey / 2u;
  const uint32_t pkcByteLenPrime = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenPrime);

  /* Allocate space in session for p, q and e for now */
  const uint32_t pkcWaSizeWord = (2u * (pkcByteLenPrime + MCUXCLRSA_PKC_WORDSIZE) + pkcByteLenKey) / (sizeof(uint32_t));
  uint8_t * pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord);
  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  uint8_t * pPkcBufferP = pPkcWorkarea + MCUXCLRSA_PKC_WORDSIZE; /* offset for NDash */
  uint8_t * pPkcBufferQ = pPkcBufferP + pkcByteLenPrime + MCUXCLRSA_PKC_WORDSIZE; /* offset for NDash */
  uint8_t * pPkcBufferE = pPkcBufferQ + pkcByteLenPrime;
  uint8_t * pPkcBufferD = pPkcBufferE + pkcByteLenKey;
  uint8_t * pPkcBufferN = pPkcBufferD + pkcByteLenKey;

  mcuxClRsa_KeyEntry_t e;
  e.keyEntryLength = byteLenE;
  e.pKeyEntryData = pPkcBufferE;
  mcuxClRsa_KeyEntry_t p;
  p.keyEntryLength = byteLenPrime;
  p.pKeyEntryData = pPkcBufferP;
  mcuxClRsa_KeyEntry_t q;
  q.keyEntryLength = byteLenPrime;
  q.pKeyEntryData = pPkcBufferQ;
  mcuxClRsa_KeyEntry_t d;
  d.keyEntryLength = 0; /* it will be computed by mcuxClRsa_ComputeD */
  d.pKeyEntryData = pPkcBufferD;

  /* Setup UPTR table. */
  const uint32_t uptrtSizeWord = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_UPTRT_SIZE * (sizeof(uint16_t)));
  uint32_t cpuWaSizeWord = uptrtSizeWord;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("16-bit UPTRT table is assigned in CPU workarea")
  uint16_t * pOperands = (uint16_t *) mcuxClSession_allocateWords_cpuWa(pSession, uptrtSizeWord);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()
  if (NULL == pOperands)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  MCUXCLPKC_SETUPTRT(pOperands);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P] = MCUXCLPKC_PTR2OFFSET(pPkcBufferP);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_Q] = MCUXCLPKC_PTR2OFFSET(pPkcBufferQ);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_E] = MCUXCLPKC_PTR2OFFSET(pPkcBufferE);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N] = MCUXCLPKC_PTR2OFFSET(pPkcBufferN);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_D] = MCUXCLPKC_PTR2OFFSET(pPkcBufferD);

  /*
   * 6. Copy E to PKC RAM.
   *    It is stored in little-endian byte order (copied with reverse order and without leading zeros).
   *
   *  Used functions: mcuxClPkc_ImportBigEndianToPkc
   */
  MCUXCLPKC_PS1_SETLENGTH(pkcByteLenPrime, pkcByteLenPrime);
  mcuxClRsa_KeyEntry_t * pPublicExponent = (mcuxClRsa_KeyEntry_t *) type->info;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(pPublicExponent->keyEntryLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(byteLenE, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  uint32_t leadingZerosE = pPublicExponent->keyEntryLength - byteLenE;
  MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_E, pPublicExponent->pKeyEntryData + leadingZerosE, byteLenE);

  /*
   * 7. Generate prime p.
   *    Continuation if mcuxClRsa_GenerateProbablePrime returns MCUXCLRSA_STATUS_KEYGENERATION_OK,
   *    otherwise function ends with MCUXCLRSA_STATUS_KEYGENERATION_ITERATIONSEXCEEDED or error.
   *
   * Used functions: mcuxClRsa_GenerateProbablePrime
   */
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_GenerateProbablePrime_P, mcuxClRsa_GenerateProbablePrime(pSession, &e, &p, bitLenKey));
  if(MCUXCLRSA_STATUS_KEYGENERATION_OK != retVal_GenerateProbablePrime_P)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pPkcStateBackup,
            mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain,
      retVal_GenerateProbablePrime_P,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyGeneration_Init),
      MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
      MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
  }

  MCUX_CSSL_FP_COUNTER_STMT(uint32_t loopCounter = 0;)

  do{
    MCUX_CSSL_FP_COUNTER_STMT(++loopCounter;)

    /*
     * 8. Generate prime q.
     *    Continuation if mcuxClRsa_GenerateProbablePrime returns MCUXCLRSA_STATUS_KEYGENERATION_OK,
     *    otherwise function ends with MCUXCLRSA_STATUS_KEYGENERATION_ITERATIONSEXCEEDED or error.
     *
     * Used functions: mcuxClRsa_GenerateProbablePrime
     */
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_GenerateProbablePrime_Q, mcuxClRsa_GenerateProbablePrime(pSession, &e, &q, bitLenKey));
    if(MCUXCLRSA_STATUS_KEYGENERATION_OK != retVal_GenerateProbablePrime_Q)
    {
      mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
      MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pPkcStateBackup,
              mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);

      mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain,
        retVal_GenerateProbablePrime_Q,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyGeneration_Init),
        MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
        loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
        (loopCounter - 1u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_TestPQDistance),
        (loopCounter - 1u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_ComputeD),
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /*
     * 9. Check if |p - q| <= 2^(nlen/2 - 100).
     *    Continuation if mcuxClRsa_TestPQDistance function returns MCUXCLRSA_STATUS_KEYGENERATION_OK
     *    otherwise function ends with MCUXCLRSA_STATUS_ERROR error code.
     *
     * Used functions: mcuxClRsa_TestPQDistance
     *
     * NOTE: This is a deviation from the method specified in the FIPS 186-4, where this check is performed while generating the prime q
     *       (see step 5.4 in Appendix B.3.3).
     *       The @ref mcuxClRsa_GenerateProbablePrime function does not perform this check, it is done after generating p and q.
     *       For this reason, if p and q does not meet this FIPS requirements, no new prime q number will be generated. Instead
     *       of function ends with error.
     *       Rationale of this deviation:
     *       This check will fail if at least 100 most significant bits of p and q are identical. This can happen
     *       with very low probability and it's usually treated as a hardware failure.
     */
    MCUX_CSSL_FP_FUNCTION_CALL(
      retVal_TestPQDistance,
      mcuxClRsa_TestPQDistance(
        MCUXCLPKC_PACKARGS4(
          0,
          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P,
          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_Q,
          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N /* used as a temporary buffer, it is > 2 * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(16) */),
        pkcByteLenPrime));
    if(MCUXCLRSA_STATUS_KEYGENERATION_OK != retVal_TestPQDistance)
    {
      mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
      MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pPkcStateBackup,
              mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);

      mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_ERROR);
    }

    /*
     * 10. Compute d := e^(-1) mod lcm(p-1, q-1)
     *     If mcuxClRsa_ComputeD function returns MCUXCLRSA_STATUS_INVALID_INPUT, then go to step 7 (new q must be generated).
     *
     * Used functions: mcuxClRsa_ComputeD
     * Memory layout: | nDash (FW) | P (pkcByteLenPrime) | nDash (FW) | Q (pkcByteLenPrime) | E (pkcByteLenKey) | D (pkcByteLenKey + FW) |
     */
    if (NULL == mcuxClSession_allocateWords_pkcWa(pSession, (pkcByteLenKey + MCUXCLRSA_PKC_WORDSIZE) / (sizeof(uint32_t))))  // allocate space for the D (additional FW for D is required by mcuxClRsa_ComputeD)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);
    }
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_ComputeD, mcuxClRsa_ComputeD(pSession, &e, &p, &q, &d, bitLenKey));

    if(MCUXCLRSA_STATUS_KEYGENERATION_OK == retVal_ComputeD)
    {
      break;
    }
    else
    {
      mcuxClSession_freeWords_pkcWa(pSession, (pkcByteLenKey + MCUXCLRSA_PKC_WORDSIZE) / (sizeof(uint32_t)));  // free up space used for the D
    }

 }while(true);

  /*
   * 11. Compute n := p*q.
   *
   * Used functions: PKC Plain Multiplication
   *
   * Memory layout: | nDash (FW) | P (pkcByteLenPrime) | nDash (FW) | Q (pkcByteLenPrime) | E (pkcByteLenKey) | D (pkcByteLenKey) | N (pkcByteLenKey) |
   */
  if (NULL == mcuxClSession_allocateWords_pkcWa(pSession, (pkcByteLenKey - MCUXCLRSA_PKC_WORDSIZE) / (sizeof(uint32_t))))  // allocate space for the N and release additional FW need to compute D
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }
  MCUXCLPKC_PS1_SETLENGTH(pkcByteLenPrime, pkcByteLenPrime);
  MCUXCLPKC_FP_CALC_MC1_PM(
    MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_Q);
  MCUXCLPKC_WAITFORFINISH();

  /*
   * 12. Write public key (computed n, e) to the buffer pointed by pPubData.
   *     This buffer contains RSA key (mcuxClRsa_Key data type, i.e.: key type and key entries)
   *     followed by the key data, i.e.: n, e.
   *     Key entries stored in big-endian byte order (copy with reverse order).
   *
   * Used functions: mcuxClPkc_ExportBigEndianFromPkc (to export n and e).
   */
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Key *pRsaPubKey = (mcuxClRsa_Key *) pPubData;
  pRsaPubKey->keytype = MCUXCLRSA_KEY_PUBLIC;
  *pPubDataLength = sizeof(mcuxClRsa_Key);

  pRsaPubKey->pMod1 = (mcuxClRsa_KeyEntry_t *) (pPubData + *pPubDataLength);
  *pPubDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPubKey->pMod2 = NULL;
  pRsaPubKey->pQInv = NULL;

  pRsaPubKey->pExp1 = (mcuxClRsa_KeyEntry_t *) (pPubData + *pPubDataLength);

  *pPubDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
  pRsaPubKey->pExp2 = NULL;
  pRsaPubKey->pExp3 = NULL;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPubKey->pMod1->pKeyEntryData = pPubData + *pPubDataLength;
  pRsaPubKey->pMod1->keyEntryLength = byteLenKey;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC(
    pRsaPubKey->pMod1->pKeyEntryData,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N,
    pRsaPubKey->pMod1->keyEntryLength);
  *pPubDataLength += pRsaPubKey->pMod1->keyEntryLength;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPubKey->pExp1->pKeyEntryData = pPubData + *pPubDataLength;
  pRsaPubKey->pExp1->keyEntryLength = e.keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC(
    pRsaPubKey->pExp1->pKeyEntryData,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_E,
    pRsaPubKey->pExp1->keyEntryLength);
  *pPubDataLength += pRsaPubKey->pExp1->keyEntryLength;


  MCUX_CSSL_FP_FUNCTION_CALL(retVal_storePlain, mcuxClRsa_KeyGeneration_StorePrivatePlain(
    pSession,
    pPrivData,
    pPrivDataLength,
    pPubData,
    d.keyEntryLength));

  if (MCUXCLRSA_STATUS_OK != retVal_storePlain)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord + 2u * pkcByteLenKey / sizeof(uint32_t));
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pPkcStateBackup,
            mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, retVal_storePlain);
  }

  /*
   * 14. Initialization of key handles for public and private key
   *     a. copy key protection into handle
   *     b. initialize the key type in handle:
   *     -set type->algoId to RSA + public/private
   *     -set length of the key in type->size
   *     -set type->info to NULL
   *     c. set pSrcKeyData to point to the start of the provided buffer
   *     d. set dstKey.loadLocation to mcuxClKey_LoadLocation_NOTLOADED
   *     e. set other fields of dstKey to zero
   */
  mcuxClKey_Descriptor_t * pPubKey = (mcuxClKey_Descriptor_t *) pubKey;
  mcuxClKey_setProtectionType(pPubKey, protection);
  // TODO CLNS-5165: move the generation of these types into the key component
  mcuxClKey_TypeDescriptor_t keyType_public = { MCUXCLKEY_ALGO_ID_RSA ^ MCUXCLKEY_ALGO_ID_PUBLIC_KEY, type->size, NULL };
  mcuxClKey_setTypeDescriptor(pPubKey, keyType_public);
  mcuxClKey_setKeyData(pPubKey, pPubData);
  mcuxClKey_setLoadStatus(pPubKey, MCUXCLKEY_LOADSTATUS_NOTLOADED);
  mcuxClKey_setLoadedKeyData(pPubKey, NULL);
  mcuxClKey_setLoadedKeySlot(pPubKey, 0u);

  mcuxClKey_Descriptor_t * pPrivKey = (mcuxClKey_Descriptor_t *) privKey;
  mcuxClKey_setProtectionType(pPrivKey, protection);
  // TODO CLNS-5165: move the generation of these types into the key component
  mcuxClKey_TypeDescriptor_t keyType_private = { MCUXCLKEY_ALGO_ID_RSA ^ MCUXCLKEY_ALGO_ID_PRIVATE_KEY, type->size, NULL };
  mcuxClKey_setTypeDescriptor(pPrivKey, keyType_private);
  mcuxClKey_setKeyData(pPrivKey, pPrivData);
  mcuxClKey_setLoadStatus(pPrivKey, MCUXCLKEY_LOADSTATUS_NOTLOADED);
  mcuxClKey_setLoadedKeyData(pPrivKey, NULL);
  mcuxClKey_setLoadedKeySlot(pPrivKey, 0u);

  /* Create link between private and public key handles */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_linkKeyPair(pSession, privKey, pubKey));

  /* Clear PKC workarea. */
  uint32_t pkcWaSize = MCUXCLRSA_KEYGENERATION_PLAIN_WAPKC_SIZE(bitLenKey);
  MCUXCLPKC_PS1_SETLENGTH(0u, pkcWaSize);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea);
  MCUXCLPKC_FP_CALC_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P, 0u);

  mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord + 2u * pkcByteLenKey / sizeof(uint32_t));
  MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pPkcStateBackup,
          mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_FAULT_ATTACK);

  mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_KeyGeneration_Plain,
    MCUXCLRSA_STATUS_KEYGENERATION_OK,
    MCUXCLRSA_STATUS_FAULT_ATTACK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyGeneration_Init),
    MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
    loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
    loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_TestPQDistance),
    loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_ComputeD),
    MCUXCLPKC_FP_CALLED_CALC_MC1_PM,
    2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportBigEndianFromPkc),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyGeneration_StorePrivatePlain),
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_linkKeyPair),
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}
