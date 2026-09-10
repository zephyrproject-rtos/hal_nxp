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

/** @file  mcuxClOsccaMacModes_Types.h
 *  @brief Internal header for MAC types for modes using the SM4
 */

#ifndef MCUXCLOSCCAMACMODES_TYPES_H_
#define MCUXCLOSCCAMACMODES_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMac_Types.h>
#include <mcuxClMac_Constants.h>
#include <mcuxClSession_Types.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClOsccaSm4_Internal_Constants.h>
#include <internal/mcuxClOsccaMacModes_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLOSCCAMACMODES_MAX_OUTPUT_SIZE (MCUXCLOSCCASM4_BLOCK_SIZE)
/**
 * Engine function types
 */

/**
 * @brief Mac engine function type for the oneshot computation
 *
 * This function will perform the actual MAC operation
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaMac_ComputeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (*mcuxClOsccaMac_ComputeEngine_t)(
  mcuxClSession_Handle_t session,
  mcuxClMac_Mode_t mode,
  mcuxClKey_Handle_t key,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t *const outLength
));

/**
 * @brief Mac engine function type for the init phase of a multi-part computation
 *
 * This function will perform the actual MAC init operation
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaMac_InitEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (*mcuxClOsccaMac_InitEngine_t)(
  mcuxClSession_Handle_t session,
  mcuxClOsccaMacModes_Context_t * const pContext
));

/**
 * @brief Mac engine function type for the update phase of a multi-part computation
 *
 * This function will perform the actual MAC update operation
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaMac_UpdateEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (*mcuxClOsccaMac_UpdateEngine_t)(
  mcuxClSession_Handle_t session,
  mcuxClOsccaMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength
));

/**
 * @brief Mac engine function type for the finish phase of a multi-part computation
 *
 * This function will perform the actual MAC finish operation
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaMac_FinishEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (*mcuxClOsccaMac_FinishEngine_t)(
  mcuxClSession_Handle_t session,
  mcuxClOsccaMacModes_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t *const outLength
));



/**
 * Internal structures / types
 */

/**
 * @brief Mac Mode structure
 *
 * This internal structure provides all implementation details for a SM4-based mode to the top level mcuxClOsccaMacMode functions.
 * It consists of Init, Update, Finalize and Oneshot engines and the output size.
 *
 */
typedef struct mcuxClOsccaMacModes_AlgorithmDescriptor
{
  mcuxClOsccaMac_InitEngine_t engineInit;           ///< engine function to perform the init operation
  uint32_t protectionToken_engineInit;             ///< protection token of the engine function to perform the init operation
  mcuxClOsccaMac_UpdateEngine_t engineUpdate;       ///< engine function to perform the update operation
  uint32_t protectionToken_engineUpdate;           ///< protection token of the engine function to perform the update operation
  mcuxClOsccaMac_FinishEngine_t engineFinalize;     ///< engine function to perform the finalize operation
  uint32_t protectionToken_engineFinalize;         ///< protection token of the engine function to perform the finalize operation
  mcuxClOsccaMac_ComputeEngine_t engineOneshot;     ///< engine function to perform the Mac operation in one shot
  uint32_t protectionToken_engineOneshot;          ///< protection token of the engine function to perform the Mac operation in one shot
  mcuxClPadding_addPaddingMode_t addPadding;   ///< padding function to be used. One of mcuxClPaddingMode
  uint32_t protectionToken_addPadding;        ///< protection token of the padding funtion
} mcuxClOsccaMacModes_AlgorithmDescriptor_t;

/**
 * @brief MAC mode algorithm type for algorithms using SM4
 *
 * This type is used to refer to a SM4-based MAC mode algorithm.
 */
typedef const mcuxClOsccaMacModes_AlgorithmDescriptor_t * const mcuxClOsccaMacModes_Algorithm_t;


#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* MCUXCLOSCCAMACMODES_TYPES_H_ */
