/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClRsa_RemoveBlinding.c
 *  @brief mcuxClRsa: function, which is called to remove modulus blinding
 */

#include <stdint.h>
#include <mcuxClToolchain.h>

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClPkc.h>
#include <mcuxClMath_Functions.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_RemoveBlinding_FUP.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_RemoveBlinding)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_RemoveBlinding(uint32_t iR_iX_iNb_iB,
  uint16_t iT2_iT1,
  uint32_t nbPkcByteLength,
  uint32_t bPkcByteLength)
{

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_RemoveBlinding);

  /* Prepare local UPTRT. */
  uint16_t pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_UPTRT_SIZE];
  const uint16_t *backupPtrUptrt;
  /* mcuxClMath_InitLocalUptrt always returns _OK. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_InitLocalUptrt(iR_iX_iNb_iB, (uint32_t) iT2_iT1, pOperands, 6u, &backupPtrUptrt));
  pOperands[MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_ZERO] = 0x0u;

  /* Call the FUP program to convert result of the exponentiation to normal representation modulo Nb */
  MCUXCLPKC_FP_CALCFUP(mcuxClRsa_RemoveBlinding_FUP,
    mcuxClRsa_RemoveBlinding_FUP_LEN);
  
  /* Calculate R=T1/b */
  MCUXCLMATH_FP_EXACTDIVIDE(MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_R,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T1,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_B,
    MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T2,
    nbPkcByteLength,
    bPkcByteLength);

  /* Restore pUptrt. */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_SETUPTRT(backupPtrUptrt);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_RemoveBlinding,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ExactDivide));
}
