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

/** @file  mcuxClRsa_PrivatePlain.c
 *  @brief mcuxClRsa: implementation of RSA private plain key operation
 */

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClPkc.h>
#include <mcuxClMath.h>
#include <mcuxClMemory.h>
#include <mcuxClRandom.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_privatePlain)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_privatePlain(
  mcuxClSession_Handle_t      pSession,
  const mcuxClRsa_Key * const pKey,
  uint8_t                   *pInput,
  mcuxCl_Buffer_t             pOutput)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_privatePlain);

  /************************************************************************************************/
  /* Check the key type and key data;                                                             */
  /* if they are incorrect, MCUXCLRSA_STATUS_INVALID_INPUT is returned                             */
  /************************************************************************************************/
  if(MCUXCLRSA_KEY_PRIVATEPLAIN != pKey->keytype)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  const uint8_t* const pExp = pKey->pExp1->pKeyEntryData;

  /************************************************************************************************/
  /* Check that modulus is odd and that 64 < pKey->pMod1->keyEntryLength < 512 or 1024;           */
  /* otherwise return MCUXCLRSA_STATUS_INVALID_INPUT.                                              */
  /************************************************************************************************/

  const uint32_t byteLenN = pKey->pMod1->keyEntryLength;
  const uint32_t byteLenD = pKey->pExp1->keyEntryLength;

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(byteLenN, 64U, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  if(0U == (pKey->pMod1->pKeyEntryData[byteLenN - 1U] & 0x01U))
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /************************************************************************************************/
  /* Initialization                                                                               */
  /************************************************************************************************/

  /* Prepare buffers in PKC workarea and clear PKC workarea */
  const uint32_t blindLen = MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE;  // length in bytes of the random value used for blinding
  const uint32_t operandSize = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenN);
  const uint32_t blindAlignLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindLen);
  const uint32_t blindOperandSize = operandSize + blindAlignLen;

  const uint32_t bufferSizeR = blindOperandSize + MCUXCLRSA_PKC_WORDSIZE;  // size of the result of the exponentiation
  const uint32_t bufferSizeN = blindOperandSize + MCUXCLRSA_PKC_WORDSIZE;  // size of N + PKC word in front of the modulus buffer for NDash
  const uint32_t bufferSizeT0 = blindOperandSize + MCUXCLRSA_PKC_WORDSIZE;  // size of temp buffer T0
  const uint32_t bufferSizeT1 = blindOperandSize + MCUXCLRSA_PKC_WORDSIZE;  // size of temp buffer T1
  const uint32_t bufferSizeT2 = blindOperandSize + MCUXCLRSA_PKC_WORDSIZE;  // size of temp buffer T2
  const uint32_t bufferSizeT3 = blindOperandSize + MCUXCLRSA_PKC_WORDSIZE;  // size of temp buffer T3
  const uint32_t bufferSizeTE = 6u*MCUXCLRSA_PKC_WORDSIZE;                  // size of temp buffer TE
  const uint32_t bufferSizeRand = blindAlignLen;  // size of buffer for random multiplicative blinding

  /* Setup session. */
  const uint32_t bufferSizeTotal = bufferSizeR + bufferSizeN + bufferSizeT0 + bufferSizeT1 + bufferSizeT2 + bufferSizeT3 + bufferSizeTE + bufferSizeRand;
  const uint32_t pkcWaSizeWord = bufferSizeTotal / (sizeof(uint32_t));
  uint32_t *pPkcWorkarea = mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord);
  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }
  uint8_t *pPkcWorkarea8 = (uint8_t *)pPkcWorkarea;

  /* Setup UPTR table. */
  const uint32_t cpuWaSizeWord = (((sizeof(uint16_t)) * MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE) + (sizeof(uint32_t)) - 1u) / (sizeof(uint32_t));
  uint32_t * pOperands32 = mcuxClSession_allocateWords_cpuWa(pSession, cpuWaSizeWord);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("16-bit UPTRT table is assigned in CPU workarea")
  uint16_t * pOperands = (uint16_t *) pOperands32;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()
  if (NULL == pOperands)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X] = MCUXCLPKC_PTR2OFFSET(pInput);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8 + bufferSizeR + MCUXCLRSA_PKC_WORDSIZE /* for NDash stored in the PKC word in front of the modulus */);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8 + bufferSizeR + bufferSizeN);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T1] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8 + bufferSizeR + bufferSizeN + bufferSizeT0);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T2] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8 + bufferSizeR + bufferSizeN + bufferSizeT0 + bufferSizeT1);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T3] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8 + bufferSizeR + bufferSizeN + bufferSizeT0 + bufferSizeT1 + bufferSizeT2);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_TE] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea8 + bufferSizeR + bufferSizeN + bufferSizeT0 + bufferSizeT1 + bufferSizeT2 + bufferSizeT3);
  uint32_t *pBlind = (pPkcWorkarea + (bufferSizeR + bufferSizeN + bufferSizeT0 + bufferSizeT1 + bufferSizeT2 + bufferSizeT3 + bufferSizeTE)/sizeof(uint32_t));
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_RAND] = MCUXCLPKC_PTR2OFFSET((uint8_t *) pBlind);

  /* Set UPTRT table */
  MCUXCLPKC_SETUPTRT(pOperands);

  /* Clear PKC workarea after input */
  // TODO CLNS-6350: analyze what should be cleared
  MCUXCLMEMORY_FP_MEMORY_CLEAR(pInput + byteLenN, MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(byteLenN) - byteLenN);

  MCUXCLPKC_PS1_SETLENGTH(0u, bufferSizeTotal);
  MCUXCLPKC_FP_CALC_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R, 0u);
  MCUXCLPKC_WAITFORREADY();

  /* Prepare expTemp buffer in CPU workarea - aligned to CPU word, length=MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(byteLenExp) */
  uint32_t * pExpTemp = pOperands32 + MCUXCLCORE_NUM_OF_CPUWORDS_CEIL((MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE * sizeof(uint16_t))); /* Cast to CPU word aligned. */
  /************************************************************************************************/
  /* Copy (with reverse order) key material to target buffer in PKC workarea                     */
  /************************************************************************************************/

  /* Import N. */
  MCUXCLPKC_PS1_SETLENGTH(0u, operandSize);
  MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0, pKey->pMod1->pKeyEntryData, byteLenN);

  /************************************************************************************************/
  /* Check that Input < pKey->pMod1;  otherwise return MCUXCLRSA_STATUS_INVALID_INPUT              */
  /* If input is zero or one, return zero or one respectively                                     */
  /************************************************************************************************/

  MCUXCLPKC_FP_CALC_OP1_CMP(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0);
  MCUXCLPKC_WAITFORFINISH();

  uint32_t carryFlag = MCUXCLPKC_GETCARRY();

  if(MCUXCLPKC_FLAG_CARRY != carryFlag)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_INVALID_INPUT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST);
  }

  /* Compare input to 1. Note that in order to do that in one operation, result has to be written to a temporary buffer */
  MCUXCLPKC_FP_CALC_OP1_SUB_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T2, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X, 1u);
  MCUXCLPKC_WAITFORFINISH();

  carryFlag = MCUXCLPKC_GETCARRY();
  uint32_t zeroFlag = MCUXCLPKC_GETZERO();

  /* CARRY=1 ==> input=0, and ZERO=1 ==> input=1. In both cases, return input */
  if((MCUXCLPKC_FLAG_CARRY == carryFlag) || (MCUXCLPKC_FLAG_ZERO == zeroFlag))
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER(mcuxClRsa_privatePlain, pOutput, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X, byteLenN);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_INTERNAL_KEYOP_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER);
  }

  /* Generate random number used for blinding */
  MCUXCLBUFFER_INIT(pBufBlind, NULL, (uint8_t *) pBlind, blindLen);
  MCUX_CSSL_FP_FUNCTION_CALL(ret_Random_ncGenerate1, mcuxClRandom_ncGenerate(pSession, pBufBlind, blindLen));
  if (MCUXCLRANDOM_STATUS_OK != ret_Random_ncGenerate1)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_ERROR);
  }
  /* Make it odd */
  pBlind[0] |= 0x1u;

  /* Blind modulus n */
  MCUXCLPKC_FP_CALC_OP1_MUL( MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N /* n_b */, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_RAND /* blind */, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0 /* n */);

  /************************************************************************************************/
  /* Prepare Montgomery parameters and convert parameters to Montgomery representation.           */
  /************************************************************************************************/

  /* Calculate Ndash of N */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS1_SETLENGTH(blindOperandSize, blindOperandSize);
  MCUXCLMATH_FP_NDASH(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0);

  /* Calculate QSquared */
  MCUXCLMATH_FP_SHIFTMODULUS(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T3, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N); //shift modulus
  MCUXCLMATH_FP_QSQUARED(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R /* QSquared */, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T3,
      MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0);

  /* Convert input to Montgomery representation i.e. M*QSquared mod N */
  MCUXCLPKC_FP_CALC_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T2 /* Mm */, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X /* M */,
      MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R /* QSquared */, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N);

  MCUXCLPKC_WAITFORFINISH();

  /************************************************************************************************/
  /* Perform secure exponentiation.                                                               */
  /************************************************************************************************/

  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecModExp,
      MCUXCLMATH_SECMODEXP(pSession,
                          pExp,
                          pExpTemp,
                          byteLenD,
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R,  /* Result */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T2, /* Montgomery representation of base number */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N,  /* Modulus */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_TE, /* Temporary buffers */
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0,
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T1,
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X,
                          MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T3) );
  if (MCUXCLMATH_STATUS_OK != ret_SecModExp)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_ERROR);
  }

  /************************************************************************************************/
  /* Convert result back to normal representation and store result in pOutput.                    */
  /************************************************************************************************/
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_RemoveBlinding(
    MCUXCLPKC_PACKARGS4(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X /* R */,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R /* Rb */,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N /* Nb */,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_RAND /* b */),
    MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T2,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T1),
    blindOperandSize,
    blindAlignLen));

  /* Copy result to the output buffer */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS1_SETLENGTH(0u, operandSize);
  MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER(mcuxClRsa_privatePlain, pOutput, MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X, byteLenN);

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
  mcuxClSession_freeWords_cpuWa(pSession, cpuWaSizeWord);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_privatePlain, MCUXCLRSA_STATUS_INTERNAL_KEYOP_OK,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
      MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),
      MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
      MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
      MCUXCLPKC_FP_CALLED_CALC_OP1_MUL,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared),
      MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_SecModExp),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_RemoveBlinding),
      MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER);

}

