/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

/** @file  mcuxClAeadModes_Common_Constants.h
 *  @brief Internal definitions for the mcuxClAeadModes component */


#ifndef MCUXCLAEADMODES_COMMON_CONSTANTS_H_
#define MCUXCLAEADMODES_COMMON_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClMemory_Constants.h>

#define MCUXCLAEADMODES_ENCRYPTION (1u)
#define MCUXCLAEADMODES_DECRYPTION (2u)

/* Buffer B0 contains the first block B0, l(a), and the first AAD bytes */
#define MCUXCLAEADMODES_CCM_B0_SIZE     (32u)

/* The maximum lengths for tag and nonce are given by the limitations from CCM:
 * The only possible lengths are:
 *    nonce: 7,8,9,10,11,12,13
 *    tag: 4,6,8,10,12,14,16
 */
#define MCUXCLAEADMODES_TAGLEN_MAX           (16u)
#define MCUXCLAEADMODES_NONCELEN_MAX         (13u)

/* For DI protection of the comparison status and the AEAD return code */
#define MCUXCLAEADMODES_INTERNAL_COMP_OK     \
            (MCUXCLAEAD_STATUS_OK + MCUXCLMEMORY_STATUS_EQUAL)
#define MCUXCLAEADMODES_INTERNAL_COMP_NOT_OK \
            (MCUXCLAEAD_STATUS_INVALID_TAG + MCUXCLMEMORY_STATUS_NOT_EQUAL)

#endif /* MCUXCLAEADMODES_COMMON_CONSTANTS_H_ */
