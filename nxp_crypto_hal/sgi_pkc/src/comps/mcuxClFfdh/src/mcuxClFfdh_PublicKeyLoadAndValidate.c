/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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

/**
 * @file  mcuxClFfdh_PublicKeyLoadAndValidate.c
 * @brief FFDH key agreement function
 */

#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClFfdh.h>
#include <mcuxClKey.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClFfdh_Internal.h>
#include <internal/mcuxClFfdh_Internal_PkcDefs.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

/**
 * @brief FFDH Public Key Load and Validate
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClFfdh_PublicKeyLoadAndValidate)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClFfdh_PublicKeyLoadAndValidate(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Handle_t publicKey,
  mcuxClFfdh_CpuWa_t* pCpuWorkarea,
  uint32_t* pExpTemp
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClFfdh_PublicKeyLoadAndValidate);

  mcuxClFfdh_DomainParams_t* pDomainParameters = (mcuxClFfdh_DomainParams_t*)mcuxClKey_getTypeInfo(publicKey);
  const uint32_t lenP = pDomainParameters->lenP;
  const uint32_t expOperandSize = pCpuWorkarea->expOperandSize;
  uint16_t* pOperands = MCUXCLPKC_GETUPTRT();

  /* Load public key to PKC buffer FFDH_UPTRTINDEX_T2 */
  uint8_t* pPublicKeyData = MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_T2]);
  MCUXCLPKC_WAITFORFINISH();
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in the code")
  MCUXCLKEY_LOAD_FP(pSession, publicKey, &pPublicKeyData, NULL, MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()

  /* Public Key Validation (PKV) routine according to RFC2631 section 2.1.5.
   * 1. Verify that y lies within the interval [2,p-1]. If it does not,
   *    the key is invalid.
   * 2. Compute y^q mod p. If the result == 1, the key is valid.
   *    Otherwise the key is invalid. */

  /* PKV 1a) Public key lower range check */
  MCUXCLPKC_FP_CALC_OP1_SUB_CONST(FFDH_UPTRTINDEX_T3, FFDH_UPTRTINDEX_T2, 2U);
  if(MCUXCLPKC_FLAG_CARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  /* PKV 1b) Public key upper range check */
  MCUXCLPKC_FP_CALC_OP1_CMP(FFDH_UPTRTINDEX_T2, FFDH_UPTRTINDEX_P);
  if(MCUXCLPKC_FLAG_CARRY != MCUXCLPKC_WAITFORFINISH_GETCARRY())
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  /* Convert public key to Montgomery representation */
  MCUXCLPKC_FP_CALC_MC1_MM(FFDH_UPTRTINDEX_BASE, FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_T2, FFDH_UPTRTINDEX_P);
  uint8_t* pBase = MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_BASE]);

  /* Clear garbage above pBase */
  MCUXCLPKC_WAITFORFINISH();
  MCUX_CSSL_DI_RECORD(memoryClear, (uint32_t)&pBase[lenP] + expOperandSize - lenP);
  MCUXCLMEMORY_CLEAR_INT(&pBase[lenP], expOperandSize - lenP);

#ifdef MCUXCL_FEATURE_FFDH_RFC2631_EXTENDED_PUBLIC_KEY_VALIDATION
  /* The primes in supported RFC7919 finite field groups are all safe primes.
   * This means a prime p is a safe prime when q = (p-1)/2.
   * Therefore we can calculate q = p/2. */
  MCUXCLPKC_FP_CALC_OP1_SHR(FFDH_UPTRTINDEX_EXP, FFDH_UPTRTINDEX_P, 1U);
  /* Clear garbage above exp buffer */
  uint8_t* pExp = MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_EXP]);
  MCUX_CSSL_DI_RECORD(memoryClear, (uint32_t)&pExp[lenP] + expOperandSize - lenP);
  MCUXCLPKC_WAITFORFINISH();
  MCUXCLMEMORY_CLEAR_INT(&pExp[lenP], expOperandSize - lenP);
  /* PKV 2) Compute y^q mod p */
  MCUX_CSSL_DI_RECORD(exponentiation, pDomainParameters->lenQ);
  MCUXCLPKC_PS1_SETLENGTH(expOperandSize, expOperandSize);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_SECMODEXP(
    pSession,
    pExpTemp,
    pDomainParameters->lenQ, /* Length of exponent  */
    FFDH_UPTRTINDEX_EXP,     /* Output -> result, input -> private exponent */
    FFDH_UPTRTINDEX_BASE,    /* Montgomery representation of base */
    FFDH_UPTRTINDEX_P,       /* Modulus */
    FFDH_UPTRTINDEX_T5,      /* iTE - last buffer 6FW */
    FFDH_UPTRTINDEX_T1,      /* Remaining temporary buffers */
    FFDH_UPTRTINDEX_T2,
    FFDH_UPTRTINDEX_T3,
    FFDH_UPTRTINDEX_T4
  ));

  /* Bring result back to normal representation */
  MCUXCLPKC_FP_CALC_MC1_MR(FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_EXP, FFDH_UPTRTINDEX_P);
  MCUXCLPKC_FP_CALC_MC1_MS(FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_P, FFDH_UPTRTINDEX_P);

  /* Check if result == 1 then the key is valid */
  MCUXCLPKC_FP_CALC_OP1_SUB_CONST(FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_T1, 1U);
  if(MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
  }
#endif /* MCUXCL_FEATURE_FFDH_RFC2631_EXTENDED_PUBLIC_KEY_VALIDATION */

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(
    mcuxClFfdh_PublicKeyLoadAndValidate,
    MCUXCLKEY_LOAD_FP_CALLED(publicKey),
    MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST,
    MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT
#ifdef MCUXCL_FEATURE_FFDH_RFC2631_EXTENDED_PUBLIC_KEY_VALIDATION
      ,
    MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_SecModExp),
    MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
    MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
    MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST
#endif /* MCUXCL_FEATURE_FFDH_RFC2631_EXTENDED_PUBLIC_KEY_VALIDATION */
  );
}
