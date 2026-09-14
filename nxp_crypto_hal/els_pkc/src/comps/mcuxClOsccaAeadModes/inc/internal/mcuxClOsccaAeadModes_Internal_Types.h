/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClOsccaAeadModes_Internal_Types.h
 *  @brief Internal type definitions for the mcuxClOsccaAeadModes component */


#ifndef MCUXCLOSCCAAEADMODES_INTERNAL_TYPES_H_
#define MCUXCLOSCCAAEADMODES_INTERNAL_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClAead_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>
#include <mcuxClSession_Types.h>
#include <internal/mcuxClAead_Ctx.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup MCUXCLOSCCAAEADMODES_OPTION_ MCUXCLOSCCAAEADMODES_OPTION_
 * @brief Options for the skeleton function
 * @ingroup mcuxClAead_Internal_Types
 * @{
 */

/* Options for the skeleton function */
#define MCUXCLOSCCAAEADMODES_OPTION_ONESHOT_ENCRYPT      0x0000000FU
#define MCUXCLOSCCAAEADMODES_OPTION_ONESHOT_DECRYPT      0x00000017U
#define MCUXCLOSCCAAEADMODES_OPTION_INIT                 0x00000001U
#define MCUXCLOSCCAAEADMODES_OPTION_PROCESS_AAD          0x00000002U
#define MCUXCLOSCCAAEADMODES_OPTION_PROCESS              0x00000004U
#define MCUXCLOSCCAAEADMODES_OPTION_FINISH_ENCRYPT       0x00000008U
#define MCUXCLOSCCAAEADMODES_OPTION_VERIFY_DECRYPT       0x00000010U

/* Options for the engine function */
#define MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AUTH              0x00000001U
#define MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC               0x00000002U
#define MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AEAD              0x00000003U
#define MCUXCLOSCCAAEADMODES_ENGINE_OPTION_INIT              0x00000008U

/**
 * @brief AEAD context structure
 *
 * This structure is used in the multi-part interfaces to store the
 * information about the current operation and the relevant internal state.
 */
typedef struct mcuxClOsccaAeadModes_Context{
    mcuxClAead_Context_t common;
    uint8_t     partialData[16u];
    uint32_t    partialDataLength;
    uint32_t    aadLength;
    uint32_t    dataLength;
    uint32_t    tagLength;
    uint8_t     state[80u];
    uint32_t    processedDataLength;
    uint32_t    direction;
    mcuxClKey_Descriptor_t            *key;
} mcuxClOsccaAeadModes_Context_t;


/**
 * @brief Function type for an AEAD mode skeleton function
 *
 * An AEAD mode skeleton function encrypts or decrypts the input message @p pIn to the output @p pOut according to the @p mode.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaAeadModes_Skeleton_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) (*mcuxClOsccaAeadModes_Skeleton_t) (
  mcuxClSession_Handle_t session,
  mcuxClOsccaAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag,
  uint32_t tagLength,
  uint32_t options  //!< 15: oneshot, 1: init, 2: update aad, 4: update, 8: finish, 16: verify
));

/**
 * @brief Function type for an AEAD mode engine function
 *
 * An AEAD mode engine function encrypts or decrypts a single block @p pIn to the output @p pOut.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaAeadModes_Engine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) (*mcuxClOsccaAeadModes_Engine_t) (
  mcuxClSession_Handle_t session,
  mcuxClOsccaAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t options  //!< 1: auth, 2: enc, 3: aead, 4: init, 8: finish
));

/**
 * @brief AEAD mode/algorithm descriptor structure
 *
 * This structure captures all the information that the AEAD interfaces need
 * to know about a particular AEAD mode/algorithm.
 */
typedef struct mcuxClOsccaAead_AlgorithmDescriptor {
    mcuxClOsccaAeadModes_Skeleton_t  pSkeleton;
    mcuxClOsccaAeadModes_Engine_t    pEngine;
    uint32_t                  protection_token_skeleton;
    uint32_t                  protection_token_engine;
    uint32_t                  direction;
} mcuxClOsccaAeadModes_algorithm_t;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCAAEADMODES_INTERNAL_TYPES_H_ */
