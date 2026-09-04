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

#ifndef MCUXCLMACMODES_COMMON_WA_H_
#define MCUXCLMACMODES_COMMON_WA_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Macros.h>
#include <mcuxClMac_Types.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClCipherModes_Common_Wa.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Wa.h>
#include <internal/mcuxClAes_Ctx.h>
#include <internal/mcuxClAes_Internal_Constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Non-blocking workarea containing all information/fields that need to be handed over to the interrupt callback
    that is triggered once AUTO mode is done.
    This information will be part of the workarea in the session, which is available during interrupt handlers. */
typedef struct mcuxClMacModes_nonBlockingWa
{
  const mcuxClMac_ModeDescriptor_t * pMode;                /* Mode descriptor as provided by the user */
  mcuxClMacModes_Context_t * pContext;                     /* Context needed to wrap-up multipart flows, which must be word-aligned */
  uint32_t inLength;                                      /* inLength as provided by the user */
  mcuxCl_InputBuffer_t pIn;                                /* Pointer to input data*/
  uint32_t inputOffset;                                   /* Offset for input data*/
  uint32_t processedBytes;                                /* Currently processed bytes*/
  union
  {
    mcuxCl_Buffer_t output;                                /* Pointer to buffer for compute MAC*/
    mcuxCl_InputBuffer_t input;                            /* Pointer to input buffer for compare MAC*/
  } pMac;

  uint32_t macLength;                                    /* Length of the mac */
  uint32_t *pOutputLength;                               /* Pointer to outputLength counter */

} mcuxClMacModes_nonBlockingWa_t;

typedef struct mcuxClMacModes_WorkArea
{
  mcuxClAes_Workarea_Sgi_t sgiWa;                           /* SGI configuration (depending on key type) */
  mcuxClMacModes_nonBlockingWa_t nonBlockingWa;
  union
  {
#ifndef MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS
    uint32_t subKey[MCUXCLMACMODES_SUBKEY_WORD_SIZE];       /* Buffer to store generated subkey */
#endif
  } algoWa;

} mcuxClMacModes_WorkArea_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_COMMON_WA_H_ */
