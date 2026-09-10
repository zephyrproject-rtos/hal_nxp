/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023 NXP                                                 */
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
 *  This is a verification required by FIPS 186-4 (Appendix B.3.3, step 5.4).
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

#include <mcuxClMath_Functions.h>
#include <internal/mcuxClPkc_Operations.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_TestPQDistance_FUP.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_TestPQDistance)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_TestPQDistance(uint32_t iP_iQ_iT, uint32_t primeByteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_TestPQDistance);

  /* Set init status to ERROR */
  mcuxClRsa_Status_t status = MCUXCLRSA_STATUS_INVALID_INPUT;

  /* Backup Uptrt to recover in the end */
  const uint16_t *backupPtrUptrt = MCUXCLPKC_GETUPTRT();

  /* Backup Ps1 length to recover in the end */
  uint32_t backupPs1LenReg = MCUXCLPKC_PS1_GETLENGTH_REG();

  /* Create and set local Uptrt table. */
  uint16_t pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_UPTRT_SIZE];

  const uint32_t pkcOperandLen = 128 / 8;
  const uint32_t pkcPrimeLen = primeByteLength;

  /* Get iP, iQ and iT indices */
  uint32_t uptrtIndexP = (iP_iQ_iT >> 16) & 0xFFu;
  uint32_t uptrtIndexQ = (iP_iQ_iT >> 8) & 0xFFu;
  uint32_t uptrtIndexT = (iP_iQ_iT) & 0xFFu;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("cannot wrap because the operandLen (= 128/8) is always <= the prime length (=byteKeyLength / 2, where byteKeyLength is a minimum of MCUXCLKEY_SIZE_1024/8=128)")
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_P128MSB] = (backupPtrUptrt[uptrtIndexP] + (uint16_t)((pkcPrimeLen - pkcOperandLen) & 0xFFFFU)) & 0xFFFFU; /* ofset to the 128 MSbits */;
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_Q128MSB] = (backupPtrUptrt[uptrtIndexQ] + (uint16_t)((pkcPrimeLen - pkcOperandLen) & 0xFFFFU)) & 0xFFFFU; /* ofset to the 128 MSbits */;
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_P100MSB] = backupPtrUptrt[uptrtIndexT];
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_Q100MSB] = (pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_P100MSB] + (uint16_t)(pkcOperandLen & 0xFFFFU)) & 0xFFFFU;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  /* Set shift value (128b-100b = 27b) */
  pOperands[MCUXCLRSA_INTERNAL_TESTPQDISTANCE_CONSTANT28] = 28u;

  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_SETUPTRT(pOperands);

  /* Set Ps1 length */
  MCUXCLPKC_PS1_SETLENGTH_REG(pkcOperandLen);  /* Don't care mclen @hi16. */

  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_TestPQDistance_FUP,
          mcuxClRsa_TestPQDistance_FUP_LEN);
  uint32_t zeroFlag_check = MCUXCLPKC_WAITFORFINISH_GETZERO();
  if(MCUXCLPKC_FLAG_NONZERO == zeroFlag_check)
  {
    /* 100 MS bits of p and q are not equal */
    status = MCUXCLRSA_STATUS_KEYGENERATION_OK;
  }

  /* Recover Ps1 length and Uptrt*/
  MCUXCLPKC_PS1_SETLENGTH_REG(backupPs1LenReg);
  MCUXCLPKC_SETUPTRT(backupPtrUptrt);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_TestPQDistance,
                            status,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
                            );
}
