/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/** @file  mcuxClRsa_Public.c
 *  @brief mcuxClRsa: implementation of RSA Public function
 */

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslDataIntegrity.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMemory_Set_Internal.h>

#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_public, mcuxClRsa_PublicExpEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_public(
  mcuxClSession_Handle_t      pSession,
  mcuxClKey_Handle_t          key,
  mcuxCl_InputBuffer_t        pInput,
  uint8_t *                  pOutput)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_public);

  /************************************************************************************************/
  /* Set up the RSA key                                                                           */
  /************************************************************************************************/

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting opaque types of workarea-like buffer objects. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Plain_t * pRsaKeyData = (mcuxClRsa_KeyData_Plain_t *) mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
  /* SREQI_RSA_0: DI protect the byte length of the exponent. Will be balanced in the call to mcuxClMath_ModExp_SqrMultL2R() called in mcuxClRsa_publicExp() . */
  MCUX_CSSL_DI_RECORD(protectExpLength, pRsaKeyData->exponent.keyEntryLength);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

  const uint32_t byteLenN = pRsaKeyData->modulus.keyEntryLength;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(byteLenN, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  /************************************************************************************************/
  /* Initialization                                                                               */
  /************************************************************************************************/

  /* Prepare buffers in PKC workarea and clear PKC workarea */
  const uint32_t operandSize = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenN);
  const uint32_t bufferSizeX = MCUXCLRSA_INTERNAL_BUFF_SIZE(byteLenN);
  const uint32_t bufferSizeN = MCUXCLRSA_INTERNAL_BUFF_SIZE(byteLenN); // PKC word in front of the modulus buffer for NDash
  const uint32_t bufferSizeT1 = MCUXCLRSA_INTERNAL_BUFF_SIZE(byteLenN);
  const uint32_t bufferSizeT2 = MCUXCLRSA_INTERNAL_BUFF_SIZE(byteLenN);

  /* The CPU WA layout is:
  * +-------------+------------------------+
  * | Math UPTRT  | RSA Allocated Memory   |
  * +-------------+------------------------+
  */
  /* Setup UPTR table. */
  const uint32_t uptrtSizeWord = MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_BYTESIZE / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t*, pOperands, mcuxClSession_allocateWords_uptrt(pSession, uptrtSizeWord));

  /* Setup PKC workarea */
  const uint32_t bufferSizeTotal = MCUXCLRSA_INTERNAL_PUBLIC_OPERANDS_WAPKC_SIZE(byteLenN);
  const uint32_t bufferWordSizeTotal = MCUXCLRSA_INTERNAL_PUBLIC_OPERANDS_WAPKC_SIZE(byteLenN) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, bufferWordSizeTotal));

  /* Prepare buffers in PKC workarea */
  uint8_t *pX = pPkcWorkarea;
  uint8_t *pN = pX + bufferSizeX + MCUXCLRSA_PKC_WORDSIZE; // one extra PKC word for NDash in front of the modulus
  uint8_t *pT1 = pN + bufferSizeN - MCUXCLRSA_PKC_WORDSIZE;  // size of NDash is included in bufferSizeN
  uint8_t *pT2 = pT1 + bufferSizeT1;
  uint8_t *pBlind = pT2 + bufferSizeT2;

  MCUXCLPKC_WAITFORREADY();
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X] = MCUXCLPKC_PTR2OFFSET(pX);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_N] = MCUXCLPKC_PTR2OFFSET(pN);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T1] = MCUXCLPKC_PTR2OFFSET(pT1);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T2] = MCUXCLPKC_PTR2OFFSET(pT2);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_RAND] = MCUXCLPKC_PTR2OFFSET(pBlind);
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_OUTPUT] = MCUXCLPKC_PTR2OFFSET(pOutput);

  /* Set UPTRT table */
  MCUXCLPKC_SETUPTRT(pOperands);

  /* bufferSizeTotal is not smaller than byteLenN */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(bufferSizeTotal, byteLenN, bufferSizeTotal, MCUXCLRSA_STATUS_INVALID_INPUT)

  /* Clear PKC workarea after the input, which is located at the beginning of the workarea and has a size of byteLenN */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_set_int_AfterInput, pPkcWorkarea + byteLenN);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_set_int_AfterInput, bufferSizeTotal - byteLenN);
  MCUXCLMEMORY_SET_INT(pPkcWorkarea + byteLenN, 0x00U, bufferSizeTotal - byteLenN);

  /************************************************************************************************/
  /* Import in LE the input and modulus to respective buffers in PKC workarea                     */
  /* Check that modulus is odd; otherwise return MCUXCLRSA_STATUS_INVALID_INPUT.                   */
  /************************************************************************************************/

  /* Balance DI for the calls to MCUXCLKEY_LOAD_FP in this function - constant key specs */
  MCUX_CSSL_DI_RECORD(Key_load, MCUXCLKEY_ENCODING_SPEC_RSA_N  + MCUXCLKEY_ENCODING_SPEC_RSA_E);

  /* Import the modulus N */
  MCUXCLPKC_PS1_SETLENGTH(0U, operandSize);
  MCUX_CSSL_DI_RECORD(Key_load, key);
  MCUX_CSSL_DI_RECORD(Key_load, &pN);
  MCUXCLKEY_LOAD_FP(pSession, key, (uint8_t**)&pN, NULL, MCUXCLKEY_ENCODING_SPEC_RSA_N );  // RSA Key_load function always returns OK

  /* Check that the modulus is odd */
  if(0U == (pN[0U] & 0x01U))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /* Import input. */
  MCUXCLPKC_FP_SECUREIMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X,
                                                            pInput, byteLenN, operandSize);

  /************************************************************************************************/
  /* Check that input < modulus;  otherwise return MCUXCLRSA_STATUS_INVALID_INPUT                  */
  /************************************************************************************************/
  MCUXCLPKC_FP_CALC_OP1_CMP(MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X, MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_N);
  MCUXCLPKC_WAITFORFINISH();
  uint32_t carryFlag = MCUXCLPKC_GETCARRY();

  if(1U != carryFlag)
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /* Compare input to 0. Note that in order to do that in one operation, result has to be written to a temporary buffer */
  MCUXCLPKC_FP_CALC_OP1_SUB_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T2, MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X, 1U);
  MCUXCLPKC_WAITFORFINISH();

  carryFlag = MCUXCLPKC_GETCARRY();

  /* CARRY=1 ==> input=0, return input */
  if(MCUXCLPKC_FLAG_CARRY == carryFlag)
  {
    MCUXCLPKC_FP_CALC_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_OUTPUT, 0U);

    MCUXCLPKC_WAITFORFINISH();
    mcuxClSession_freeWords_pkcWa(pSession, bufferWordSizeTotal);
    mcuxClSession_freeWords_uptrt(pSession, uptrtSizeWord);

    /* Expunge parameters added outside this branch */
    MCUX_CSSL_DI_EXPUNGE(protectExpLength, pRsaKeyData->exponent.keyEntryLength);
    MCUX_CSSL_DI_EXPUNGE(Key_load, MCUXCLKEY_ENCODING_SPEC_RSA_E);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_public,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
        MCUXCLMEMORY_SET_INT_FP_EXPECT,
        MCUXCLKEY_LOAD_FP_CALLED(key),
        MCUXCLPKC_FP_CALLED_SECUREIMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST
    );
  }

  uint8_t *pPubExp = NULL;
  MCUX_CSSL_DI_RECORD(Key_load, key);
  MCUX_CSSL_DI_RECORD(Key_load, &pPubExp);

  MCUXCLKEY_LOAD_FP(pSession, key, (uint8_t**)&pPubExp, NULL, MCUXCLKEY_ENCODING_SPEC_RSA_E);  // RSA Key_load function always returns OK
  MCUX_CSSL_DI_RECORD(protectExpPointer, pPubExp);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_publicExp(pSession,
    MCUXCLPKC_PACKARGS4(MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_OUTPUT,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_N,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T1),
    MCUXCLPKC_PACKARGS4(0, MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T2,
                       MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_RAND),
    pRsaKeyData->exponent.keyEntryLength,
    pPubExp));

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/

  mcuxClSession_freeWords_pkcWa(pSession, bufferWordSizeTotal);
  mcuxClSession_freeWords_uptrt(pSession, uptrtSizeWord);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_public,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
      MCUXCLMEMORY_SET_INT_FP_EXPECT,
      MCUXCLKEY_LOAD_FP_CALLED(key),
      MCUXCLPKC_FP_CALLED_SECUREIMPORTBIGENDIANTOPKC_BUFFER,
      MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
      MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
      MCUXCLKEY_LOAD_FP_CALLED(key),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_publicExp)
  );

}
