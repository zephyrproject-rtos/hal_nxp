/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

#ifndef MCUXCLOSCCAMACMODES_SM4_CMAC_H_
#define MCUXCLOSCCAMACMODES_SM4_CMAC_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxClMac_Types.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClOsccaMacModes_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Engine functions
 */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, mcuxClOsccaMac_ComputeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Oneshot(
    mcuxClSession_Handle_t session,                          /*! CMAC session handle */
    mcuxClMac_Mode_t mode,
    mcuxClKey_Handle_t key,
    mcuxCl_InputBuffer_t pIn,                                /*! CMAC input */
    uint32_t inLength,                                      /*! Input size */
    mcuxCl_Buffer_t pOut,                                    /*! CMAC output */
    uint32_t *const pOutLength                              /*! Output size */
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_Engine_CMAC_Init, mcuxClOsccaMac_InitEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Init(
    mcuxClSession_Handle_t session,                          /*! CMAC session handle */
    mcuxClOsccaMacModes_Context_t * const pContext           /*! CMAC context */
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_Engine_CMAC_Update, mcuxClOsccaMac_UpdateEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Update(
    mcuxClSession_Handle_t session,                          /*! CMAC session handle */
    mcuxClOsccaMacModes_Context_t * const pContext,          /*! CMAC context */
    mcuxCl_InputBuffer_t pIn,                                /*! CMAC input */
    uint32_t inLength                                       /*! Input size */
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_Engine_CMAC_Finalize, mcuxClOsccaMac_FinishEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Finalize(
    mcuxClSession_Handle_t session,                          /*! CMAC session handle */
    mcuxClOsccaMacModes_Context_t * const pContext,          /*! CMAC context */
    mcuxCl_Buffer_t pOut,                                    /*! CMAC output */
    uint32_t *const pOutLength                              /*! Output size */
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCAMACMODES_SM4_CMAC_H_ */
