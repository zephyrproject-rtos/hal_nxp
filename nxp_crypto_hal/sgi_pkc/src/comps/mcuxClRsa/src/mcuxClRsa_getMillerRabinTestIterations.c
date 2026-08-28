/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025-2026 NXP                                            */
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

/** @file  mcuxClRsa_getMillerRabinTestIterations.c
 *  @brief Function returns the minimum number of Miller-Rabin test iterations for given
 *  prime bit length.
 *
 */

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_getMillerRabinTestIterations)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClRsa_getMillerRabinTestIterations(const uint32_t primeBitLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_getMillerRabinTestIterations);

  uint32_t numberMillerRabinTestIterations = 11U; /* init value for 512b prime */
  if(1024U == primeBitLength)
  {
    numberMillerRabinTestIterations = 6U;
  }
  if(1536U == primeBitLength)
  {
    numberMillerRabinTestIterations = 4U;
  }
  else if(2048U == primeBitLength)
  {
    numberMillerRabinTestIterations = 3U;
  }
#if defined(MCUXCL_FEATURE_RSA_8K_KEYS)  //Required only for bigger key sizes (as the prime p/q will be > 2048)
  else if(3072U == primeBitLength)
  {
    numberMillerRabinTestIterations = 2U;
  }
  else if(4096U == primeBitLength)
  {
    numberMillerRabinTestIterations = 2U;
  }
#endif /* defined(MCUXCL_FEATURE_RSA_8K_KEYS) */
  else
  {
    /* intentionally do nothing */
  }
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_getMillerRabinTestIterations, numberMillerRabinTestIterations);
}
