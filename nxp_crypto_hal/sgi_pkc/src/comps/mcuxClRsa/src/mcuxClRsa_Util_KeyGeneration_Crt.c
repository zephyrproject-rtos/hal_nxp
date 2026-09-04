/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

/** @file  mcuxClRsa_Util_KeyGeneration_Crt.c
 *  @brief mcuxClRsa: implementation of RSA key generation function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClKey.h>
#include <mcuxCsslDataIntegrity.h>

#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMath_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Util_KeyGeneration_Crt_FUP.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Util_KeyGeneration_Crt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_Util_KeyGeneration_Crt(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Generation_t generation,
  mcuxClKey_Handle_t privKey,
  mcuxClKey_Handle_t pubKey)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Util_KeyGeneration_Crt);

  /* Step 1: Protect key handles. This will be balanced when calling MCUXCLKEY_STORE_FP.  */
  MCUX_CSSL_DI_RECORD(keyStore_private, privKey);
  MCUX_CSSL_DI_RECORD(keyStore_public, pubKey);

  /*
   * Step 2: Initialization process to Check entropy provided by RNG and if E is FIPS compliant
   */
  const uint32_t bitLenKey = mcuxClKey_getSize(pubKey);
  const uint32_t byteLenKey = bitLenKey / 8U;

  const mcuxClRsa_KeyGeneration_ProtocolDescriptor_t * pProtocolDescriptor = (const mcuxClRsa_KeyGeneration_ProtocolDescriptor_t *) generation->pProtocolDescriptor;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to set the generic pointer.")
    mcuxClRsa_KeyEntry_t * pPublicExponent = (mcuxClRsa_KeyEntry_t *) &pProtocolDescriptor->pubExp;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

  uint32_t byteLenE = 0U;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(
    mcuxClRsa_Util_KeyGeneration_Init_CrtKey(
      pSession,
      pubKey,
      generation,
      &byteLenE,
      privKey));

  /* Initialize PKC. */
  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, mcuxClRsa_Util_KeyGeneration_Crt);

  /* The CPU WA layout is:
  * +-------------+------------------------+
  * | Math UPTRT  | RSA Allocated Memory   |
  * +-------------+------------------------+
  */
  /* Setup mcuxClMath UPTRT buffer at beginning of PKC/CPU depending on MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM and update session info */
  MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pMathUptrt, mcuxClSession_allocateWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t)));
  /* Update session info for pMathUptrt location in PKC WA */
  pSession->pMathUptrt = pMathUptrt;

  /*
   * Step 3: Allocate buffers in PKC RAM
   *  - size aligned to PKC word
   *  - they are be stored in little-endian byte order
   */
  const uint32_t pkcByteLenKey = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenKey);
  const uint32_t byteLenPrime = byteLenKey / 2U;
  const uint32_t pkcByteLenPrime = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenPrime);
  const uint32_t blindLen = MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE;  // length in bytes of the random value used for blinding
  const uint32_t blindAlignLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindLen);
  const uint32_t blindSquaredAlignLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindLen * 2U);
  const uint32_t blindedPrimeAlignLen = pkcByteLenPrime + blindAlignLen;
  const uint32_t blindedModAlignLen = 2U * blindedPrimeAlignLen;

  /* Allocate space in session for e, p, q, T1, T2 and T3 for now */
  uint32_t pkcWaSizeWord = (pkcByteLenPrime                                  /* e */
                            + (pkcByteLenPrime + MCUXCLRSA_PKC_WORDSIZE) * 2U /* p and q */) /
                           sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord));

  uint8_t * pPkcBufferE = pPkcWorkarea;
  uint8_t * pPkcBufferP = pPkcBufferE + pkcByteLenPrime + MCUXCLRSA_PKC_WORDSIZE /* offset for Ndash before p */;
  uint8_t * pPkcBufferQ = pPkcBufferP + pkcByteLenPrime + MCUXCLRSA_PKC_WORDSIZE /* offset for Ndash before q */;
  uint8_t * pPkcBufferT1 = NULL;

  /* Protect the lengths and pointers to the prime candidates, that will be balanced when calling mcuxClRsa_GenerateProbablePrime */
  MCUX_CSSL_DI_RECORD(generateProbablePrimeParams, pPkcBufferP);
  MCUX_CSSL_DI_RECORD(generateProbablePrimeParams, pPkcBufferQ);
  MCUX_CSSL_DI_RECORD(generateProbablePrimeParams, 2U * byteLenPrime);

  /* Setup UPTR table. */
  const uint32_t cpuWaSizeWord = MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE_IN_WORDS;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("16-bit UPTRT table is assigned in CPU workarea")
  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t*, pOperands, mcuxClSession_allocateWords_cpuWa(pSession, cpuWaSizeWord));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_SETUPTRT(pOperands);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_E] = MCUXCLPKC_PTR2OFFSET(pPkcBufferE);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P] = MCUXCLPKC_PTR2OFFSET(pPkcBufferP);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q] = MCUXCLPKC_PTR2OFFSET(pPkcBufferQ);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT0] = 0U;
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT1] = 1U;

  /*
   * Step 4: Copy E to PKC RAM.
   * It is stored in little-endian byte order (copied with reverse order and without leading zeros).
   *
   *  Used functions: mcuxClPkc_ImportBigEndianToPkc
   */
  MCUXCLPKC_PS1_SETLENGTH(pkcByteLenPrime, pkcByteLenPrime);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pPublicExponent has a compatible type and the access to keyEntryLength is valid")
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pPublicExponent->keyEntryLength, 3U, 32U, MCUXCLRSA_STATUS_INVALID_INPUT /* e is in the range 2^16 < e < 2^256 */)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(byteLenE, 0U, pPublicExponent->keyEntryLength, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
  uint32_t leadingZerosE = pPublicExponent->keyEntryLength - byteLenE;
  MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_DI_BALANCED(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_E, pPublicExponent->pKeyEntryData + leadingZerosE, byteLenE, pkcByteLenPrime);

  /*
   * Step 5: Generate prime p.
   * Continue if mcuxClRsa_GenerateProbablePrime returns MCUXCLRSA_STATUS_KEYGENERATION_OK.
   * In case of errors, the mcuxClRsa_GenerateProbablePrime function would do an early-exit via session.
   *
   * Used functions: mcuxClRsa_GenerateProbablePrime
   */
  mcuxClRsa_KeyEntry_t e;
  e.keyEntryLength = byteLenE;
  e.pKeyEntryData = pPkcBufferE;
  const uint32_t eAlignLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(e.keyEntryLength);

  mcuxClRsa_KeyEntry_t p;
  p.keyEntryLength = byteLenPrime;
  p.pKeyEntryData = pPkcBufferP;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_GenerateProbablePrime(pSession, &e, &p, bitLenKey, MCUXCLRSA_MAX_LOOP_ITER_P));

  /* Step 6: Generate prime q and test prime p and q distance.
   * This test will fail if at least 100 most significant bits of p and q are identical. This can happen
   * with a very low probability. We generate a new q when the test fails. */
  MCUX_CSSL_FP_COUNTER_STMT(uint32_t loopCounter = 0;)

  do
  {
    MCUX_CSSL_FP_COUNTER_STMT(++loopCounter;)

    /*
     * Generate prime q.
     * Continue if mcuxClRsa_GenerateProbablePrime returns MCUXCLRSA_STATUS_KEYGENERATION_OK.
     * In case of errors, the mcuxClRsa_GenerateProbablePrime function would do an early-exit via session.
     *
     * Used functions: mcuxClRsa_GenerateProbablePrime
     */
    mcuxClRsa_KeyEntry_t q;
    q.pKeyEntryData = pPkcBufferQ;
    q.keyEntryLength = byteLenPrime;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_GenerateProbablePrime(pSession, &e, &q, bitLenKey, MCUXCLRSA_MAX_LOOP_ITER_Q));

    /*
     * Allocate space for T1, T2 and T3 for mcuxClRsa_TestPQDistance. The space will be reused outside the while-loop; in steps 10-13.
     */
    const uint32_t pkcWaSizeWord2 = ((blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE) * 3U) / sizeof(uint32_t); /* T1, T2 and T3 */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pkcWaSizeWord += pkcWaSizeWord2 can't wrap")
    pkcWaSizeWord += pkcWaSizeWord2;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea2, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord2));
    pPkcBufferT1 = pPkcWorkarea2; /* pPkcBufferT2 and pPkcBufferT3 will be initialized later */
    pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1] = MCUXCLPKC_PTR2OFFSET(pPkcBufferT1);

    /*
     * Check if |p - q| <= 2^(nlen/2 - 100)
     * Continuation if mcuxClRsa_TestPQDistance function returns MCUXCLRSA_STATUS_KEYGENERATION_OK
     *  otherwise function goes back to generating prime q.
     *
     * Used functions: mcuxClRsa_TestPQDistance
     */
    MCUX_CSSL_FP_FUNCTION_CALL(
      retVal_TestPQDistance,
      mcuxClRsa_TestPQDistance(
        MCUXCLPKC_PACKARGS4(
          0,
          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P,
          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q,
          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1 /* T1 + T2 + T3 size > 3 * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(16) */
        ),
        pkcByteLenPrime
      )
    );

    if(MCUXCLRSA_STATUS_KEYGENERATION_OK == retVal_TestPQDistance)
    {
      /* The mcuxClRsa_TestPQDistance can return MCUXCLRSA_STATUS_KEYGENERATION_OK or MCUXCLRSA_STATUS_INVALID_INPUT */
      break;
    }
    else /* MCUXCLRSA_STATUS_INVALID_INPUT */
    {
      /* According to FIPS186.5, retry prime q generation if |p - q| <= 2^(nlen/2 - 100) */
      /* pointer/length of Q will be expunged again when calling mcuxClRsa_GenerateProbablePrime */
      MCUX_CSSL_DI_RECORD(generateProbablePrimeParams, pPkcBufferQ);
      MCUX_CSSL_DI_RECORD(generateProbablePrimeParams, byteLenPrime);

      /* Free up the space allocated for T1 + T2 + T3 */
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pkcWaSizeWord += pkcWaSizeWord3 can't wrap")
      pkcWaSizeWord -= pkcWaSizeWord2;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
      mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord2);

      /* Go back to prime q generation */
    }
  }
  while(true);

  /* Step 7: Initialize variables for T2, T3, dp, dq, qInv and N computation */
  const uint32_t pkcWaSizeWord3 = (2U * (blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE) // dp, dq
                                  + (blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE) // qInv
                                  + pkcByteLenKey + 2U * MCUXCLRSA_PKC_WORDSIZE // n, and one extra 2 PKC words for mcuxClMath_ExactDivideOdd
                                  + blindAlignLen // rand
                                  + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE // p_b, and one extra PKC word for NDash
                                  + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE // q_b, and one extra PKC word for mcuxClMath_ModInv
                                  + blindSquaredAlignLen + MCUXCLRSA_PKC_WORDSIZE // randSquare
                                  ) / sizeof(uint32_t);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pkcWaSizeWord += pkcWaSizeWord3 can't wrap")
  pkcWaSizeWord += pkcWaSizeWord3;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  uint8_t * pPkcBufferT2 = pPkcBufferT1 + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE;
  uint8_t * pPkcBufferT3 = pPkcBufferT2 + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE;

  /* Step 8: Allocate the remaining space for computing N */
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea3, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord3));
  uint8_t * pPkcBufferDp = pPkcWorkarea3;
  uint8_t * pPkcBufferDq = pPkcBufferDp + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE;
  uint8_t * pPkcBufferQinv = pPkcBufferDq + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE;
  uint8_t * pPkcBufferN = pPkcBufferQinv + blindedPrimeAlignLen + MCUXCLRSA_PKC_WORDSIZE;
  uint8_t * pPkcBufferRand = pPkcBufferN + pkcByteLenKey + 2U* MCUXCLRSA_PKC_WORDSIZE;
  uint8_t * pPkcBufferPb = pPkcBufferRand + blindAlignLen + MCUXCLRSA_PKC_WORDSIZE; // Skip the extra PKC word for NDash
  uint8_t * pPkcBufferQb = pPkcBufferPb + blindedPrimeAlignLen;
  uint8_t * pPkcBufferRandSquare = pPkcBufferQb + blindedPrimeAlignLen;

  MCUX_CSSL_DI_RECORD(modinvParams, pPkcBufferDp); /* Protect pPkcBufferDp with DI, it will be balanced in mcuxClRsa_ModInv */
  MCUX_CSSL_DI_RECORD(modinvParams, pPkcBufferDq); /* Protect pPkcBufferDq with DI, it will be balanced in mcuxClRsa_ModInv */

  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS2_SETLENGTH(pkcByteLenPrime, blindAlignLen);

  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2] = MCUXCLPKC_PTR2OFFSET(pPkcBufferT2);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3] = MCUXCLPKC_PTR2OFFSET(pPkcBufferT3);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DP] = MCUXCLPKC_PTR2OFFSET(pPkcBufferDp);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DQ] = MCUXCLPKC_PTR2OFFSET(pPkcBufferDq);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV] = MCUXCLPKC_PTR2OFFSET(pPkcBufferQinv);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N] = MCUXCLPKC_PTR2OFFSET(pPkcBufferN);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND] = MCUXCLPKC_PTR2OFFSET(pPkcBufferRand);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B] = MCUXCLPKC_PTR2OFFSET(pPkcBufferPb);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q_B] = MCUXCLPKC_PTR2OFFSET(pPkcBufferQb);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N_B] = MCUXCLPKC_PTR2OFFSET(pPkcBufferT1); // reuse T1+T2
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND_SQUARE] = MCUXCLPKC_PTR2OFFSET(pPkcBufferRandSquare);

  /* Step 9: Generate random number r32 used for blinding and set LSB to 1, to ensure it is odd and non-null */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pPkcBufferRand is 32-bit aligned.")
  uint32_t *pR32 = (uint32_t *) pPkcBufferRand;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_FP_FUNCTION_CALL(random32, mcuxClPrng_generate_word());
  pR32[0] = random32 | 0x1U;
  pR32[1] = 0U;

  /*
   * Step 10: Compute dp := e^(-1) mod (p-1)
   *
   * Used functions: mcuxClRsa_ModInv
   */
  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP,
          mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP_LEN);
  MCUXCLPKC_WAITFORREADY();
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(
    mcuxClRsa_ModInv(
      pSession,
      MCUXCLPKC_PACKARGS4(
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DP,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND),
      MCUXCLPKC_PACKARGS2(
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV), // as temp buffer
      eAlignLen, blindedPrimeAlignLen));

  /*
   * Step 11: Compute dq := e^(-1) mod (q-1)
   *
   * Used functions: mcuxClRsa_ModInv
   */
  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP,
          mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP_LEN);
  MCUXCLPKC_WAITFORREADY();
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(
    mcuxClRsa_ModInv(
      pSession,
      MCUXCLPKC_PACKARGS4(
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DQ,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND),
      MCUXCLPKC_PACKARGS2(
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV), // as temp buffer
      eAlignLen, blindedPrimeAlignLen));

  /*
   * Step 12: Compute n := p*q in a blinded way.
   */

  /* Compute pb = p * r32 and qb = q * r32 */
  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP,
          mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP_LEN);

  /* Compute blinded modulus: Nb = pb * qb and square of blinding value:  (r32)^2 */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS1_SETLENGTH(0U, blindAlignLen);
  MCUXCLPKC_PS2_SETLENGTH(blindedPrimeAlignLen, blindedPrimeAlignLen);

  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP,
          mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP_LEN);


  /* Compute modulus N = Nb / ((r32)^2). Note that (r32)^2 is non-null and odd. */
  MCUXCLMATH_FP_EXACTDIVIDEODD(pSession,
                              MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N,
                              MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N_B,
                              MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND_SQUARE,
                              MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
                              blindedModAlignLen,
                              blindSquaredAlignLen);

  /*
   * Step 13: Compute qInvb := qb^(-1) mod pb
   *
   * Used functions: mcuxClMath_ModInv
   */

  /* Compute NDash of pb */
  MCUXCLMATH_FP_NDASH(pSession,
                     MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B,
                     MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2);

  /* Compute qInvb */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS1_SETLENGTH(blindedPrimeAlignLen, blindedPrimeAlignLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(
    mcuxClMath_ModInv(
      pSession,
      MCUXCLPKC_PACKARGS4(
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1, /* qInvb */
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2),
        MCUXCLMATH_XN_NOT_COPRIME));

  /* Compute Q^2 */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLMATH_FP_SHIFTMODULUS(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3, /* shift modulus */
                            MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B);
  MCUXCLPKC_WAITFORREADY();
  MCUXCLMATH_FP_QSQUARED(pSession,
                        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2,   /* Q^2 */
                        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,   /* shift modulus */
                        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B,
                        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV  /* as temp buffer */
                       );

  /* Convert qInvb to Montgomery representation: qInvb_m = qInvb * Q^2 */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_FP_CALC_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3, /* qInvb_m */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1, /* qInvb */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2, /* Q^2 */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B);

  /* Compute qInv */
  MCUXCLPKC_WAITFORREADY();
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_RemoveBlinding(
    pSession,
    MCUXCLPKC_PACKARGS4(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,   /* qInvb_m */
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND),
    MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1),
    blindedPrimeAlignLen,
    blindAlignLen));

  MCUXCLPKC_WAITFORFINISH();

  /*
   * Step 14: Write public key (computed n, e) to the buffer pointed by pPubData.
   * This buffer contains RSA key (mcuxClRsa_KeyData_Plain_t data type, i.e. key entries)
   * followed by the key data, i.e.: n, e.
   * Key entries stored in big-endian byte order (copy with reverse order).
   *
   * Used functions: MCUXCLKEY_STORE_FP (to export n and e).
   */
  mcuxClRsa_KeyData_Plain_t rsaPubKeySrc = {
                              .modulus.pKeyEntryData = pPkcBufferN,
                              .modulus.keyEntryLength = byteLenKey,
                              .exponent.pKeyEntryData = pPkcBufferE,
                              .exponent.keyEntryLength = byteLenE
  };
  MCUXCLKEY_STORE_FP(pSession, pubKey, (uint8_t*)&rsaPubKeySrc, 0u);  // RSA Key_store function always returns OK

  /*
   * Step 15: Write RSA CRT key (p, q, qInv, dp, dq) to the buffer pointed by pPrivData.
   * This buffer contains RSA key (mcuxClRsa_KeyData_Crt_t data type, i.e.key entries)
   * followed by the key data, i.e.: p, q, qInv, dp, dq and e (in case DFA).
   * Key entries stored in big-endian byte order (copy with reverse order).
   *
   * Used functions: MCUXCLKEY_STORE_FP
   */
  mcuxClRsa_KeyData_Crt_t rsaPrivKeySrc = {
                              .p.pKeyEntryData = pPkcBufferP,
                              .p.keyEntryLength = byteLenPrime,
                              .q.pKeyEntryData = pPkcBufferQ,
                              .q.keyEntryLength = byteLenPrime,
                              .qInv.pKeyEntryData = pPkcBufferQinv,
                              .qInv.keyEntryLength = byteLenPrime,
                              .dp.pKeyEntryData = pPkcBufferDp,
                              .dp.keyEntryLength = byteLenPrime,
                              .dq.pKeyEntryData = pPkcBufferDq,
                              .dq.keyEntryLength = byteLenPrime,
                              .e.pKeyEntryData = pPkcBufferE,
                              .e.keyEntryLength = byteLenE,
  };

  MCUXCLKEY_STORE_FP(pSession, privKey, (uint8_t*)&rsaPrivKeySrc, 0u);  // RSA Key_store function always returns OK

  /* Create link between private and public key handles */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_linkKeyPair(pSession, privKey, pubKey));

  /* Step 16: Clean up. Free PKC WA.
   * If MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_MASK is set, PKC WA will be re-used by the key verification.
   * Otherwise, the maximum PKC WA that has been used in mcuxClRsa_Util_KeyGeneration_Crt and its subfunctions will be cleared by mcuxClRsa_VerifyKey. */
  mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);

  /* If MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_MASK is set, it will verify the generated private key.
   * Otherwise it will only clear PKC workarea. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_VerifyKey(
          pSession,
          privKey,
          pubKey,
          pPublicExponent,
          pPkcWorkarea));

  /* Release PKC and exit */
  MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);
  mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

  /* Free Math UPTRT allocated WA */
  mcuxClSession_freeWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_Util_KeyGeneration_Crt,
    /* Step 2 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_KeyGeneration_Init_CrtKey),
    MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
    /* Step 3 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    /* Step 4 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
    /* Step 5 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
    /* Step 6 */
    loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_GenerateProbablePrime),
    loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_TestPQDistance),
    loopCounter * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    /* Step 8 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    /* Step 9 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    /* Step 10 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_ModInv),
    /* Step 11 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_ModInv),
    /* Step 12 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ExactDivideOdd),
    /* Step 13 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared),
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_RemoveBlinding),
    /* Step 14 */
    MCUXCLKEY_STORE_FP_CALLED(pubKey),
    /* Step 15 */
    MCUXCLKEY_STORE_FP_CALLED(privKey),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_linkKeyPair),
    /* Step 16 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_VerifyKey),
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}
