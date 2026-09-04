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

/** @file  mcuxClRsa_GenerateProbablePrime.c
 *  @brief mcuxClRsa: function, which is called to generates probably prime number
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslDataIntegrity.h>

#include <mcuxClRsa.h>
#include <mcuxClKey.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClMemory_Copy_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_GenerateProbablePrime)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_GenerateProbablePrime(
  mcuxClSession_Handle_t           pSession,
  mcuxClRsa_KeyEntry_t *           pE,
  mcuxClRsa_KeyEntry_t *           pPrimeCandidate,
  const uint32_t                  keyBitLength,
  const uint32_t                  maxIter)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_GenerateProbablePrime,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST);

    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)pSession);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keyBitLength, 8U * MCUXCLRSA_MIN_MODLEN, 8U * MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(maxIter, MCUXCLRSA_MAX_LOOP_ITER_P, MCUXCLRSA_MAX_LOOP_ITER_Q, MCUXCLRSA_STATUS_INVALID_INPUT)

    mcuxClRsa_Status_t status = MCUXCLKEY_STATUS_FAILURE;
    uint32_t loopCounter = 0U;
    uint32_t loopMax = maxIter*keyBitLength;
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t cntRandomGen = 0U);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t cntTestPrime = 0U);

    /* Little-endian representation of 0xb504f333f9de6485U, which is 64 most significant bits of sqrt(2)(2^(nlen/2)-1) rounded up */
    static const uint8_t numToCompare[] = {0x85U, 0x64U, 0xDEU, 0xF9U, 0x33U, 0xF3U, 0x04U, 0xB5U};
    /* Little-endian representation of 0xC0CFD797U, which is the product of the first 9 prime numbers starting from 3*/
    static const uint8_t a0[] = {0x97U, 0xD7U, 0xCFU, 0xC0U};

    /*
    * Initialization:
    * - allocate buffers in PKC RAM
    * - copy 0xb504f333f9de6485U value into buffer located in PKC RAM
    * - copy A0 value into buffer located in PKC RAM
    * - update session (PKC workarea used...)
    */

    const uint32_t pkcWaSizeWord = MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WO_TESTPRIMECANDIDATE_WAPKC_SIZE / sizeof(uint32_t);
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord));
    uint32_t *pNumToCompare = pPkcWorkarea;
    uint32_t *pA0 = pPkcWorkarea + (MCUXCLRSA_PKC_WORDSIZE/sizeof(uint32_t));
    uint32_t *pConst3 = pA0 + (MCUXCLRSA_PKC_WORDSIZE/sizeof(uint32_t));

    /* Setup UPTR table */
    const uint32_t cpuWaSizeWord =  MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE_IN_WORDS_WO_TESTPRIME_AND_MILLERRABIN(keyBitLength/8U/2U);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("16-bit UPTRT table is assigned in CPU workarea")
    MCUX_CSSL_FP_FUNCTION_CALL(uint16_t*, pOperands, mcuxClSession_allocateWords_cpuWa(pSession, cpuWaSizeWord));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

    MCUXCLPKC_WAITFORREADY();
    pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_NUMTOCOMPARE] = MCUXCLPKC_PTR2OFFSET((const uint8_t*)pNumToCompare);
    pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_A0] = MCUXCLPKC_PTR2OFFSET((const uint8_t*)pA0);
    pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_CANDIDATE_LSWORD] = MCUXCLPKC_PTR2OFFSET(pPrimeCandidate->pKeyEntryData);
    pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_WORD_CONST3] = MCUXCLPKC_PTR2OFFSET((const uint8_t*)pConst3);

    const uint32_t iNumToCmp_iA0 = ((uint32_t)MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_NUMTOCOMPARE << 8U) | MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_A0;

    /* Backup Ps1 length and UPTRT, restore them when returning */
    uint16_t *bakUPTRT = MCUXCLPKC_GETUPTRT();
    uint32_t bakPs1LenReg = MCUXCLPKC_PS1_GETLENGTH_REG();
    uint32_t bakPs2LenReg = MCUXCLPKC_PS2_GETLENGTH_REG();

    /* Set UPTRT table */
    MCUXCLPKC_SETUPTRT(pOperands);

    MCUXCLPKC_PS1_SETLENGTH(0U, MCUXCLRSA_PKC_WORDSIZE);
    MCUXCLPKC_FP_CALC_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_NUMTOCOMPARE, 0U);
    MCUXCLPKC_FP_CALC_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_A0, 0U);
    MCUXCLPKC_FP_CALC_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_WORD_CONST3, 0U);
    MCUXCLPKC_WAITFORFINISH();

    pConst3[0] = 3U;

    /* Balance DI for call to mcuxClMemory_copy_int */
    MCUX_CSSL_DI_RECORD(memCopyNumToCompare, ((uint8_t*)pNumToCompare + MCUXCLRSA_PKC_WORDSIZE));
    MCUX_CSSL_DI_RECORD(memCopyNumToCompare, numToCompare);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
      (uint8_t*)pNumToCompare + MCUXCLRSA_PKC_WORDSIZE - sizeof(numToCompare),
      numToCompare,
      sizeof(numToCompare)
    ));

    /* Balance DI for call to mcuxClMemory_copy_int */
    MCUX_CSSL_DI_RECORD(memCopyA0, pA0);
    MCUX_CSSL_DI_RECORD(memCopyA0, a0);
    MCUX_CSSL_DI_RECORD(memCopyA0, sizeof(a0));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int((uint8_t*)pA0, a0, sizeof(a0)));

    MCUXCLBUFFER_INIT(pBufKeyEntryData, NULL, pPrimeCandidate->pKeyEntryData, pPrimeCandidate->keyEntryLength);
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)pBufKeyEntryData);

    /* Protect the input length and pointer to the prime candidate, by expunging them from DI.
     * Note that pPrimeCandidate->keyEntryLength is not explicitly expunged, as this is already
     * done by the first call to mcuxClRandom_generate_internal, for which pPrimeCandidate->keyEntryLength
     * is not RECORDded in this function. */
    MCUX_CSSL_DI_EXPUNGE(primeCandidate, pPrimeCandidate->pKeyEntryData);

    /* Get number of Miller-Rabin test iterations */
    /* Returns the number of Miller-Rabin test iterations for given prime bit length */
    MCUX_CSSL_FP_FUNCTION_CALL(numberMillerRabinTestIterations, mcuxClRsa_getMillerRabinTestIterations(keyBitLength / 2U));

    do
    {
        /*
        * Generate a random prime candidate for given key size using DRBG:
        *    - Ensure that prime candidate is odd;
        *    - Ensure that prime candidate is congruent 3 mod 4 (this deviation from FIPS 186-5 has been approved).
        *
        *    The session pointed to by pSession shall be initialized with the entropy level (security strength)
        *    in accordance with the value of keyBitLength, as specified in SP 800-57, Part 1.
        *
        * Used functions: RNG provided through the pSession
        */
        MCUX_CSSL_FP_COUNTER_STMT(cntRandomGen++);

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_generate_internal(pSession, pBufKeyEntryData, pPrimeCandidate->keyEntryLength, NULL));

        MCUX_CSSL_FP_COUNTER_STMT(cntTestPrime++);
        MCUXCLPKC_FP_CALC_OP1_OR(MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_CANDIDATE_LSWORD,
                                MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_CANDIDATE_LSWORD,
                                MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_WORD_CONST3);

        /*mcuxClRsa_TestPrimeCandidate can return MCUXCLRSA_STATUS_KEYGENERATION_OK or other return values where the prime test failed */
        MCUX_CSSL_FP_FUNCTION_CALL(retTest, mcuxClRsa_TestPrimeCandidate(pSession, pE, pPrimeCandidate, keyBitLength, iNumToCmp_iA0, numberMillerRabinTestIterations));
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(MISRA_C_2012_Rule_15_7, "There is a non-empty terminating else statement")

        if (MCUXCLRSA_STATUS_KEYGENERATION_OK == retTest)
        {
            status = retTest;
            loopCounter++;
            break;
        }
        else if (MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_CMP_FAILED != retTest)
        {
            loopCounter++;
        }
        else
        {
            /* Record parameters for the call to mcuxClRandom_generate_internal */
            MCUX_CSSL_DI_RECORD(randomGenerateParams, pSession);
            MCUX_CSSL_DI_RECORD(randomGenerateParams, pBufKeyEntryData);
            MCUX_CSSL_DI_RECORD(randomGenerateParams, pPrimeCandidate->keyEntryLength);
        }
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(MISRA_C_2012_Rule_15_7)
    } while(loopCounter < loopMax);

    /* Balance DI for the calls to mcuxClRandom_generate_internal */
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)pSession * (loopCounter - 1U));
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)pBufKeyEntryData * (loopCounter - 1U));
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)pPrimeCandidate->keyEntryLength * (loopCounter - 1U));

    /* Recover session, Ps1 length and Uptrt */
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);
    MCUXCLPKC_PS1_SETLENGTH_REG(bakPs1LenReg);
    MCUXCLPKC_PS2_SETLENGTH_REG(bakPs2LenReg);
    MCUXCLPKC_SETUPTRT(bakUPTRT);

    /* If generate probable prime is not successful, return MCUXCLKEY_STATUS_ITERATIONS_EXCEEDED to caller, through session */
    if (MCUXCLRSA_STATUS_KEYGENERATION_OK != status)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ITERATIONS_EXCEEDED);
    }

    /* Check define outside of macro so the MISRA rule 20.6 does not get violated */
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_GenerateProbablePrime,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_getMillerRabinTestIterations),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal) * cntRandomGen,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR * cntTestPrime,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_TestPrimeCandidate) * cntTestPrime
    );

}

