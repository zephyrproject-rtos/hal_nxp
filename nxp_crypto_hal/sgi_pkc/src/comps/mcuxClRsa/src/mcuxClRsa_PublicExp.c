/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/** @file  mcuxClRsa_publicExp.c
 *  @brief mcuxClRsa: implementation of RSA Public expo with N blinded
 */

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClRandom.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRandom_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_publicExp)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_publicExp(
  mcuxClSession_Handle_t      pSession,
  uint32_t iR_iX_iN_iT1,
  uint32_t iT2_iT3_iT4,
  uint32_t byteLenExp,
  const uint8_t* const pExp)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_publicExp);

  uint8_t iT1 = (uint8_t)(iR_iX_iN_iT1 & 0xFFU);
  uint8_t iN = (uint8_t)((iR_iX_iN_iT1 >> 8) & 0xFFU);
  uint8_t iX = (uint8_t)((iR_iX_iN_iT1 >> 16) & 0xFFU);
  uint8_t iR = (uint8_t)((iR_iX_iN_iT1 >> 24) & 0xFFU);
  uint8_t iRnd = (uint8_t)(iT2_iT3_iT4 & 0xFFU);
  uint8_t iT3 = (uint8_t)((iT2_iT3_iT4 >> 8) & 0xFFU);
  uint8_t iT2 = (uint8_t)((iT2_iT3_iT4 >> 16) & 0xFFU);

  const uint16_t *pUptrt = MCUXCLPKC_GETUPTRT();
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("operand buffer is always word aligned in PKC workarea.")
  uint32_t *pBlind = (uint32_t *)MCUXCLPKC_OFFSET2PTR(pUptrt[iRnd]);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
  const uint32_t blindAlignLen = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE);
  const uint32_t blindOperandSize = operandSize + blindAlignLen;
  uint32_t ps1LenBackup = MCUXCLPKC_PS1_GETLENGTH_REG();

  /* Generate random number used for blinding */
  pBlind[0] = mcuxClRandom_ncGenerateWord_Internal(pSession);

  /* Make it odd */
  pBlind[0] |= 0x1U;

  /* Blind modulus n */
  MCUXCLPKC_FP_CALC_OP1_MUL( iN/* n_b */, iRnd/* blind */, iN/* n */);

  /************************************************************************************************/
  /* Prepare Montgomery parameters and convert parameters to Montgomery representation.           */
  /************************************************************************************************/

  /* Calculate Ndash of N */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS1_SETLENGTH(blindOperandSize, blindOperandSize);
  MCUXCLMATH_FP_NDASH(pSession, iN, iT3);

  /* Calculate QSquared */
  MCUXCLMATH_FP_SHIFTMODULUS(iT3, iN); //shift modulus
  MCUXCLMATH_FP_QSQUARED(pSession, iT1/* QSquared */, iT3, iN, iR);

  /* Convert input to Montgomery representation i.e. M*QSquared mod N */
  MCUXCLPKC_FP_CALC_MC1_MM(iT3/* Mm */, iX/* M */, iT1/* QSquared */, iN);

  /************************************************************************************************/
  /* Call mcuxClMath_ModExp_SqrMultL2R                                                             */
  /* Return checking is unnecessary, because it always returns OK.                                */
  /************************************************************************************************/

  //mcuxClMath_ModExp_SqrMultL2R(pExp, byteLenExp, iR_iX_iN_iT);
  //T2 -> size lenN + PKC wordsize
  //T1 -> size lenX
  //N -> size lenN + PKC word in front of the modulus buffer for NDash
  //R -> size lenN + PKC wordsize
  MCUXCLMATH_FP_MODEXP_SQRMULTL2R(pExp, byteLenExp, iT2, iT3, iN, iT1);

  MCUXCLPKC_WAITFORFINISH();

  /************************************************************************************************/
  /* Convert result back to normal representation and store result in pOutput.                    */
  /************************************************************************************************/
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_RemoveBlinding(
    pSession,
    MCUXCLPKC_PACKARGS4(iR/* R */,
                       iT2/* Rb */,
                       iN/* Nb */,
                       iRnd/* b */),
    MCUXCLPKC_PACKARGS2(iT1,
                       iT3),
    blindOperandSize,
    blindAlignLen));

  MCUXCLPKC_WAITFORFINISH();

  /* Restore the PS1 len */
  MCUXCLPKC_PS1_SETLENGTH_REG(ps1LenBackup);
  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_publicExp, MCUXCLPKC_FP_CALLED_CALC_OP1_MUL,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared),
      MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModExp_SqrMultL2R),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_RemoveBlinding)
  );
}
