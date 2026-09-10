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

/** @file  mcuxClOsccaMacModes_Internal_Functions.h
 *  @brief Internal definitions of helper functions for the mcuxClOsccaMacModes component
 */

#ifndef MCUXCLOSCCAMACMODES_INTERNAL_FUNCTIONS_H_
#define MCUXCLOSCCAMACMODES_INTERNAL_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMac_Types.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession_Types.h>

/**
 * @brief Skeleton functions for the MAC modes
 */

/**
 * @brief Mac Oneshot Compute function type
 *
 * This function will perform the actual MAC compute operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_compute, mcuxClMac_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_compute(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
);



/**
 * @brief MacModes Multipart Init function type
 *
 * This function will perform the actual MAC init operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_init, mcuxClMac_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_init(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxClKey_Handle_t key
);

/**
 * @brief MacModes Multipart Process function type
 *
 * This function will perform the actual MAC process operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_process, mcuxClMac_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_process(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength
);

/**
 * @brief MacModes Multipart Finish function type
 *
 * This function will perform the actual MAC finish operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_finish, mcuxClMac_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_finish(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
);


#ifdef MCUXCL_FEATURE_MACMODES_CMAC_SM4
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaMacModes_SM4_Gen_K1K2)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaMacModes_SM4_Gen_K1K2(uint8_t *output, uint8_t * input);
#endif /* MCUXCL_FEATURE_MACMODES_CMAC_SM4 */

#endif /* MCUXCLOSCCAMACMODES_INTERNAL_FUNCTIONS_H_ */
