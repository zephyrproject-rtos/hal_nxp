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

#ifndef MCUXCLCIPHERMODES_COMMON_WA_H_
#define MCUXCLCIPHERMODES_COMMON_WA_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <mcuxClBuffer.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClCipher_Types.h>
#include <internal/mcuxClCipherModes_Common_Constants.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Wa.h>
#include <internal/mcuxClAes_Internal_Constants.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClKey_Types_Internal.h>

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/* Forward declaration for type */
struct mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi;
struct mcuxClCipherModes_Context_Aes_Sgi;

/** Non-blocking workarea containing all information/fields that need to be handed over to the interrupt callback
    that is triggered once AUTO mode is done.
    This information will be part of the workarea in the session, which is available during interrupt handlers. */
typedef struct mcuxClCipherModes_nonBlockingWa
{
  const struct mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi * pAlgo; /* Algorithm descriptor as provided by the user */
  struct mcuxClCipherModes_Context_Aes_Sgi * pContext;                /* Context needed to wrap-up multipart flows， and must be word-aligned */
  uint8_t direction;                /* Indicates encryption or decryption for oneshot operations */
  uint32_t lastBlockRemainingBytes; /* Number of bytes in the last block [1..16] for multipart operations */
  uint32_t totalInputLength;        /* Total number of input in bytes */
  uint32_t *pOutputLength;          /* Pointer to outputLength counter */
  mcuxCl_InputBuffer_t pIn;          /* User input buffer */
  uint32_t inOffset;                /* Offset of input buffer */
  mcuxCl_Buffer_t pOut;              /* User output buffer */
  uint32_t outOffset;               /* Offset of output buffer */
} mcuxClCipherModes_nonBlockingWa_t;
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */


typedef struct mcuxClCipherModes_WorkArea
{
  mcuxClAes_Workarea_Sgi_t sgiWa;
  uint32_t *pIV;
  uint32_t ctrSize;
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
  mcuxClCipherModes_nonBlockingWa_t nonBlockingWa;
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
} mcuxClCipherModes_WorkArea_t;



#endif /* MCUXCLCIPHERMODES_COMMON_WA_H_ */
