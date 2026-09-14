/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

#ifndef MCUXCLOSCCASM4_INTERNAL_FUNCTONS_H_
#define MCUXCLOSCCASM4_INTERNAL_FUNCTONS_H_

#include <internal/mcuxClOsccaSm4_Internal_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Core functions
 * */

/**
 * @brief This function encrypts/decrypts one block of data using algorithm OSCCA SM4
 *
 * @param pRoundKeys   Pointer to round keys, not used in SGI implementation
 * @param pIn          Pointer to the input (plaintext)
 * @param pOut         Pointer to the result (ciphertext)
 * @param direction    Encryption or decryption

 * @return status
 * @retval #MCUXCLOSCCASM4_STATUS_CRYPT_OK    pOut generated successfully;
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm4_Engine)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm4_Status_t) mcuxClOsccaSm4_Engine(
  uint32_t * const pRoKeys,
  const uint8_t * const pIn,
  uint8_t * const pOut,
  uint32_t direction
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm4_ScheduleSM4Key)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm4_Status_t) mcuxClOsccaSm4_ScheduleSM4Key(
    uint32_t *pRoundKeys, uint8_t const *pMKey, uint32_t direction);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm4_Tau)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClOsccaSm4_Tau(uint32_t in);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM4_INTERNAL_FUNCTONS_H_ */
