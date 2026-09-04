/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/** @file  mcuxClMac_Internal_Types.h
 *  @brief Internal header for MAC types
 */

#ifndef MCUXCLMAC_INTERNAL_TYPES_H_
#define MCUXCLMAC_INTERNAL_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMac_Types.h>
#include <mcuxClMac_Constants.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClResource_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Mode/Skeleton function types
 */

/**
 * @brief Mac Oneshot Compute function type
 *
 * This function will perform the actual MAC compute operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMac_ComputeFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (*mcuxClMac_ComputeFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
));

/**
 * @brief Mac Multipart Init function type
 *
 * This function will perform the actual MAC init operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMac_InitFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClMac_InitFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxClKey_Handle_t pKey
));

/**
 * @brief Mac Multipart Process function type
 *
 * This function will perform the actual MAC process operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMac_ProcessFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (*mcuxClMac_ProcessFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength
));

/**
 * @brief Mac Multipart Finish function type
 *
 * This function will perform the actual MAC finish operation based on the given mode
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMac_FinishFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClMac_FinishFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
));



/**
 * Internal structures
 */

/**
 * @brief Mac common mode descriptor structure
 *
 * This structure captures all the information that the MAC interfaces need
 * to know about a particular MAC mode/algorithm.
 */
typedef struct mcuxClMac_CommonModeDescriptor
{
  mcuxClMac_ComputeFunc_t     compute;
  uint32_t                   protectionToken_compute;
  mcuxClMac_InitFunc_t        init;
  uint32_t                   protectionToken_init;
  mcuxClMac_ProcessFunc_t     process;
  uint32_t                   protectionToken_process;
  mcuxClMac_FinishFunc_t      finish;
  uint32_t                   protectionToken_finish;
  uint32_t                   macByteSize; /* output size of the MAC computation in bytes */
  void *                     pAlgorithm;  /* pointer to algorithm specifics, individual structures can be assigned here */

} mcuxClMac_CommonModeDescriptor_t;

/**
 * @brief Mac top-level mode/algorithm descriptor structure
 *
 * This structure contains common information for all MAC modes.
 */
struct mcuxClMac_ModeDescriptor
{
  mcuxClMac_CommonModeDescriptor_t common;   /* top-level mode information */
  void * pCustom;                           /* additional mode-specific data structure */
};

#ifdef MCUXCL_FEATURE_MAC_SELFTEST
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMac_SelfTestFct_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClMac_SelfTestFct_t) (
  mcuxClSession_Handle_t session,
  mcuxClMac_Mode_t mode
));

/**
 * @brief Mac selftest mode descriptor structure
 * @ingroup clMacModes
 *
 * This structure captures all the information that the Mac selftest interfaces need
 * to know about a particular Mac selftest mode.
 */
struct mcuxClMac_TestDescriptor
{
  mcuxClMac_SelfTestFct_t pSelfTestFct;
  uint32_t               protection_token_selftest;
};
#endif /* MCUXCL_FEATURE_MAC_SELFTEST */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMAC_INTERNAL_TYPES_H_ */
