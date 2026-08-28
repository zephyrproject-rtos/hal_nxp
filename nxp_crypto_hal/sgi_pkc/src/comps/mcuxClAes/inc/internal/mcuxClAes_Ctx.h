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

#ifndef MCUXCLAES_CTX_H_
#define MCUXCLAES_CTX_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClAes_Internal_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Context for internal keys */
typedef struct mcuxClAes_HKeyContext_Sgi
{
  uint32_t keySeed;                                                     /* Key seed of SFR-masked key */
  uint32_t keyMasked[MCUXCLAES_GCM_H_KEY_SIZE_IN_WORDS];                 /* Buffer to store the key in SFR-masked format */
  uint32_t sgiCtrlKey;                                                  /* SGI configuration (depending on key type) */
  mcuxClKey_KeyChecksum_t keyChecksums;                                  /* Buffer to store the key checksum info */
} mcuxClAes_HKeyContext_Sgi_t;

/* Context for external keys */
typedef struct mcuxClAes_KeyContext_Sgi
{
  mcuxClKey_Descriptor_t* key;                                           /* Key handle of the external key. */
  uint32_t sfrSeed;                                                     /* Seed for SFR masking */
  uint32_t sgiCtrlKey;                                                  /* SGI configuration (depending on key type) */
  mcuxClKey_KeyChecksum_t  keyChecksums;                                 /* Buffer to store the key checksum info */
} mcuxClAes_KeyContext_Sgi_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAES_CTX_H_ */
