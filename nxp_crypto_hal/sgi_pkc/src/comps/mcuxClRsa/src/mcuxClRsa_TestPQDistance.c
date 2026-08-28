/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2026 NXP                                            */
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

/** @file  mcuxClRsa_TestPQDistance.c
 *  @brief mcuxClRsa: function, which is called to test |p - q| <= 2^(nlen/2 - 100).
 *  This is a verification required by FIPS 186-5 (Appendix A.1.3, step 5.5).
 *  Verification is done by checking the 100 MSbits of p and q. If they are equal,
 *  test fail.
 *
 *  The implementation assumes that:
 *  - pLen = qLen = nlen/2 = primeByteLength
 *  - primeByteLength is a multiple of PKC wordsize.
 *  - PKC wordsize is not greater than 128 bits
 *
 *  NOTE: This function will require adaptation if need to support primeByteLength
 *  that is not multiple of PKC word.
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClPrng_Internal_Functions.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_TestPQDistance_FUP.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Macros.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_TestPQDistance)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_TestPQDistance(uint32_t iP_iQ_iT, uint32_t primeByteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_TestPQDistance);

  /* Set init status to ERROR */
  mcuxClRsa_Status_t status = MCUXCLRSA_STATUS_INVALID_INPUT;

  /* Backup Uptrt to recover in the end */
  const uint16_t *pBackupPtrUptrt = MCUXCLPKC_GETUPTRT();

  /* Backup Ps1 length to recover in the end */
  uint32_t backupPs1LenReg = MCUXCLPKC_PS1_GETLENGTH_REG();

  /* Create and set local Uptrt table. */
  uint16_t pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_UPTRT_SIZE];

  const uint32_t pkcOperandLen = 128U / 8U;
  const uint32_t pkcPrimeLen = primeByteLength;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pkcPrimeLen, MCUXCLRSA_MIN_MODLEN / 2U, MCUXCLRSA_MAX_MODLEN / 2U, MCUXCLRSA_STATUS_INVALID_INPUT)

  /* Get iP, iQ and iT indices */
  uint32_t uptrtIndexP = (iP_iQ_iT >> 16) & 0xFFU;
  uint32_t uptrtIndexQ = (iP_iQ_iT >> 8) & 0xFFU;
  uint32_t uptrtIndexT = (iP_iQ_iT) & 0xFFU;

  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_P128MSB] = (uint16_t)((pBackupPtrUptrt[uptrtIndexP] + pkcPrimeLen - pkcOperandLen) & 0xFFFFU); /* offset to the 128 MSbits */
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_Q128MSB] = (uint16_t)((pBackupPtrUptrt[uptrtIndexQ] + pkcPrimeLen - pkcOperandLen) & 0xFFFFU); /* offset to the 128 MSbits */
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1] = pBackupPtrUptrt[uptrtIndexT];
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T2] = (uint16_t)((pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1] + pkcOperandLen) & 0xFFFFU);
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND] = (uint16_t)((pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T2] + pkcOperandLen) & 0xFFFFU);
  /* Set shift value (128b-100b = 27b) */
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_CONSTANT28] = 28U;

  uint8_t * pRand = MCUXCLPKC_OFFSET2PTR(pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND]);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pRand, pkcOperandLen));

  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_SETUPTRT(pOperands);

  /* Set Ps1 length */
  MCUXCLPKC_PS1_SETLENGTH_REG(pkcOperandLen);  /* Don't care mclen @hi16. */

  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_TestPQDistance_FUP,
          mcuxClRsa_TestPQDistance_FUP_LEN);
  uint32_t zeroFlag_check = MCUXCLPKC_WAITFORFINISH_GETZERO();

  /* Check FIPS 186-5 verification (100 MS bits of p and q are not equal) */
  if(MCUXCLPKC_FLAG_NONZERO == zeroFlag_check)
  {
    /* 100 MS bits of p and q are not equal */
    status = MCUXCLRSA_STATUS_KEYGENERATION_OK;
  }

  /* Recover Ps1 length and Uptrt*/
  MCUXCLPKC_PS1_SETLENGTH_REG(backupPs1LenReg);
  MCUXCLPKC_SETUPTRT(pBackupPtrUptrt);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_TestPQDistance, status,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
  );
}
