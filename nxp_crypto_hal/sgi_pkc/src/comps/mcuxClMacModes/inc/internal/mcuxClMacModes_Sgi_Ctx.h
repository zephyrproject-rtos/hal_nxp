/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

#ifndef MCUXCLMACMODES_SGI_CTX_H_
#define MCUXCLMACMODES_SGI_CTX_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClAes.h>

#include <internal/mcuxClAes_Ctx.h>
#include <internal/mcuxClAes_Internal_Constants.h>
#include <internal/mcuxClMac_Ctx.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMacModes_Common_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLMAC_GMAC_INTERNAL_CONTEXT                                                                    \
  mcuxClAes_HKeyContext_Sgi_t HkeyContext;               /* Common H-key context */                        \
  uint32_t counter0[MCUXCLAES_BLOCK_SIZE_IN_WORDS];      /* Buffer for the first counter for GMAC, J0 */

#define MCUXCLMAC_INTEGRITY_PROTECTION_CONTEXT                                                                                  \
  mcuxClMac_Context_t common;                            /* Common field of the context, for all modes */                      \
  uint32_t blockBuffer[MCUXCLAES_BLOCK_SIZE_IN_WORDS];   /* Buffer of size block-size, to accumulate input data */             \
  mcuxClAes_KeyContext_Sgi_t keyContext;                 /* Common key context; sfr seed will be re-used for preTag masking */ \
  uint32_t dataProcessed;                               /* Indicate, whether data has been processed */                       \
  uint32_t totalInput;                                  /* Total number of input bytes */                                     \
  MCUXCLMAC_GMAC_INTERNAL_CONTEXT

/**
 * @brief MacModes integrity protected context structure for SGI modes
 *
 * This struct is used to calculate the size of the integrity protected context
 */
typedef struct
{
  MCUXCLMAC_INTEGRITY_PROTECTION_CONTEXT
} mcuxClMacModes_IntegrityProtectionContext_t;

#define MCUXCLMACMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE   (sizeof(mcuxClMacModes_IntegrityProtectionContext_t))

/**
 * @brief Mac context structure for modes using SGI HW
 *
 * This structure captures all the information that the Mac interface needs to
 * know for a particular Mac mode/algorithm to work.
 */
typedef struct mcuxClMacModes_Context
{
  /* Integrity protected Context */
  MCUXCLMAC_INTEGRITY_PROTECTION_CONTEXT

  uint32_t blockBufferUsed;                             /* How many bytes in mode-specific blockBuffer are used */
  uint32_t maskedPreTag[MCUXCLAES_BLOCK_SIZE_IN_WORDS];  /* Intermediate result of CMAC operation (masked) */
} mcuxClMacModes_Context_t;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_SGI_CTX_H_ */
