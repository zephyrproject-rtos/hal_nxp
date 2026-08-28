/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

/** @file  mcuxClAeadModes_Sgi_Ctx.h
 *  @brief Internal structure of the context for the mcuxClAeadModes component
 */

#ifndef MCUXCLAEADMODES_SGI_CTX_H_
#define MCUXCLAEADMODES_SGI_CTX_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <internal/mcuxClAead_Ctx.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Internal_Constants.h>
#include <internal/mcuxClAeadModes_Common_Constants.h>
#include <internal/mcuxClAeadModes_Sgi_Types.h>
#include <internal/mcuxClAes_Ctx.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>

#define MCUXCLAEAD_INTEGRITY_PROTECTION_CONTEXT   \
  mcuxClAead_Context_t common;                   \
  uint32_t encDecMode;                          \
  uint8_t  counter0[MCUXCLAES_BLOCK_SIZE];       \
  uint32_t inSize;     /* input bytes left */   \
  uint32_t adataSize;  /* size of all adata */  \
  uint32_t adataCumulativeSize;                 \
  uint32_t tagSize;


/**
 * @brief AeadModes integrity protected context structure for SGI modes
 *
 * This struct is used to calculate the size of the integrity protected context
 */
typedef struct
{
  MCUXCLAEAD_INTEGRITY_PROTECTION_CONTEXT
} mcuxClAeadModes_IntegrityProtectionContext_t;

#define MCUXCLAEADMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE (sizeof(mcuxClAeadModes_IntegrityProtectionContext_t))

struct mcuxClAeadModes_Context
{
  /* Integrity protected Context */
  MCUXCLAEAD_INTEGRITY_PROTECTION_CONTEXT

  mcuxClCipherModes_Context_Aes_Sgi_t cipherCtx;
  mcuxClMacModes_Context_t macCtx;
  mcuxClAeadModes_alg_process_t process;
  uint32_t protectionToken_process;

};

#endif /* MCUXCLAEADMODES_SGI_CTX_H_ */
