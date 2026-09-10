/*--------------------------------------------------------------------------*/
/* Copyright 2020-2022, 2024 NXP                                            */
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

#ifndef MCUXCLMACMODES_ELS_CMAC_H_
#define MCUXCLMACMODES_ELS_CMAC_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession_Types.h>

#include <mcuxClMac_Types.h>
#include <internal/mcuxClMacModes_Els_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Internal function which processes complete CMAC blocks.
 *
 * @Pre: @p pContext->cmac_options.bits must be configured to match the desired CMAC step
 *
 * @param[in]  pContext       CMAC context
 * @param[in]  pIn            CMAC input padded to full blocks if necessary
 * @param[in]  inputLen       Input length, length before padding if padding is applied
 * @param[in/out]  pOut       CMAC output
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_Engine_CMAC_ProcessBlocks)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_Engine_CMAC_ProcessBlocks(
    mcuxClMacModes_Context_t * const pContext, /*! CMAC context */
    const uint8_t *const pIn,                 /*! CMAC input */
    uint32_t inputLen,                        /*! Input size must be full blocks */
    uint8_t *const pOut);                     /*! CMAC output */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_Engine_CMAC_Oneshot)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_Engine_CMAC_Oneshot(
  mcuxClSession_Handle_t session,           /*! CMAC session handle */
  mcuxClMacModes_Context_t * const pContext,/*! CMAC context */
  const uint8_t *const pIn,                /*! CMAC input */
  uint32_t inLength,                       /*! Input size */
  uint8_t *const pOut,                     /*! CMAC output */
  uint32_t *const pOutLength               /*! Output size */
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_Engine_CMAC_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_Engine_CMAC_Init(
  mcuxClSession_Handle_t session,           /*! CMAC session handle */
  mcuxClMacModes_Context_t * const pContext /*! CMAC context */
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_Engine_CMAC_Update)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_Engine_CMAC_Update(
  mcuxClSession_Handle_t session,           /*! CMAC session handle */
  mcuxClMacModes_Context_t * const pContext,/*! CMAC context */
  mcuxCl_InputBuffer_t pIn,                 /*! CMAC input */
  uint32_t inLength                        /*! Input size */
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_Engine_CMAC_Finalize)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_Engine_CMAC_Finalize(
  mcuxClSession_Handle_t session,           /*! CMAC session handle */
  mcuxClMacModes_Context_t * const pContext,/*! CMAC context */
  mcuxCl_Buffer_t pOut,                     /*! CMAC output */
  uint32_t *const pOutLength               /*! Output size */
);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_ELS_CMAC_H_ */
