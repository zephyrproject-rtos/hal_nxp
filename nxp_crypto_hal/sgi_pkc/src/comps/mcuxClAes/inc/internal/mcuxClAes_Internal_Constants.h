/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

#ifndef MCUXCLAES_INTERNAL_CONSTANTS_H_
#define MCUXCLAES_INTERNAL_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClAes_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************/
/* Internal constants for subkeys             */
/**********************************************/
#define MCUXCLAES_GCM_H_KEY_SIZE                (16U)
#define MCUXCLAES_GCM_H_KEY_SIZE_IN_WORDS       (MCUXCLAES_GCM_H_KEY_SIZE / sizeof(uint32_t))
#define MCUXCLAES_MAC_SUB_KEY_SIZE              (16U)


/**********************************************/
/* Internal constants for key encodings       */
/**********************************************/
#define MCUXCLAES_KEYCHECKSUM_CRC_REFERENCE_INDEX   (0) //reference CRC index in mcuxClKey_KeyChecksum.data
#define MCUXCLAES_KEYCHECKSUM_CRC_SFRMASK_INDEX     (1) //sfrseed index in mcuxClKey_KeyChecksum.data


/* default 32-bit SGI SFR mask constant */
#define MCUXCLAES_KEY_CHECKSUM_SFRMASKING_SEED             (0xF0F0F0F0U)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAES_INTERNAL_CONSTANTS_H_ */
