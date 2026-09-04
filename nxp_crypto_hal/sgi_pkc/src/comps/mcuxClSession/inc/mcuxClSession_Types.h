/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/**
 * @file  mcuxClSession_Types.h
 * @brief Type definitions for the mcuxClSession component
 */

#ifndef MCUXCLSESSION_TYPES_H_
#define MCUXCLSESSION_TYPES_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>

#include <mcuxClRandom_Types.h>
#include <mcuxClResource_Types.h>

/**********************************************
 * CONSTANTS
 **********************************************/
/**
 * @defgroup mcuxClSession_Constants mcuxClSession_Constants
 * @brief Defines all constants of @ref mcuxClSession
 * @ingroup mcuxClSession
 * @{
 */

#define MCUXCLSESSION_STATUS_OK                          ((mcuxClSession_Status_t) 0x0EEE2E03u)  ///< Session operation successful
#define MCUXCLSESSION_STATUS_ERROR                       ((mcuxClSession_Status_t) 0x0EEE5330u)  ///< Error occurred during Session operation
#define MCUXCLSESSION_STATUS_ERROR_MEMORY_ALLOCATION     ((mcuxClSession_Status_t) 0x0EEE534Fu)  ///< Error occurred during Session operation (Not enough memory)
#define MCUXCLSESSION_STATUS_FAULT_ATTACK                ((mcuxClSession_Status_t) 0x0EEEF0F0u)  ///< Fault attack

#define MCUXCLSESSION_DMACHANNEL_INVALID  ((mcuxClSession_Channel_t) 0xFFFFu)    ///< dma channel is not specified



/**
 * @}
 */
/* mcuxClSession_Constants */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClSession_Types mcuxClSession_Types
 * @brief Defines all types of @ref mcuxClSession
 * @ingroup mcuxClSession
 * @{
 */

/**
 * @brief Type for mcuxClSession status codes
 */
typedef uint32_t mcuxClSession_Status_t;

/**
 * @brief Deprecated type for mcuxClSession protected status codes
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_Status_Protected_t;

/**
 * @brief Type for mcuxClSession workareas flags
 */
typedef struct mcuxClSession_WorkArea
{
  uint32_t * buffer;            ///< Pointer to the starting address of the workarea buffer
  uint32_t size;                ///< Size of the workarea buffer in words (uint32_t)
  uint32_t used;                ///< Used portion of the workarea buffer in words (uint32_t)
  uint32_t dirty;               ///< Maximum used portion of the workarea buffer in words (uint32_t)
} mcuxClSession_WorkArea_t;

/**
 * @brief Type for Session security options
 */
typedef uint32_t mcuxClSession_SecurityOptions_t;

/**
 * @brief Type for mcuxClSession Descriptor
 */
struct mcuxClSession_Descriptor;  /* forward declaration */
typedef struct mcuxClSession_Descriptor mcuxClSession_Descriptor_t;

/**
 * @brief Type for mcuxClSession Handle
 */
typedef mcuxClSession_Descriptor_t * const mcuxClSession_Handle_t;

/**
 * @brief Session channel type
 *
 * This type identifies DMA channel to be used during non-blocking operations.
 */
typedef uint16_t mcuxClSession_Channel_t;

/**
 * @brief Session channels type
 *
 * This type identifies DMA channels to be used during non-blocking operations.
 */
typedef struct
{
  mcuxClSession_Channel_t input;
  mcuxClSession_Channel_t output;
} mcuxClSession_Channels_t;

/**
 * @brief Session callback function pointer type
 *
 * This type is used to pass callback functions to be triggered by the Session.
 */
typedef void (*mcuxClSession_Callback_t)(uint32_t status, void * data);

/**
 * @brief HW interrupt handler function pointer type
 *
 * This type is used to pass HW interrupt handler (callback function)
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSession_HwInterruptHandler_t,
  typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClSession_HwInterruptHandler_t)(mcuxClSession_Handle_t session)
);

/**
 * @brief Table recording HW preempted from this session
 */
typedef struct mcuxClSession_HwTable mcuxClSession_HwTable_t;

/**
 * @brief Type for mcuxClSession non-blocking job context
 */
typedef struct
{
  mcuxClSession_Channels_t dmaChannels;
  mcuxClSession_Callback_t pUserCallback;
  void *pUserData;
  mcuxClSession_HwInterruptHandler_t pCallBackDMA;
  uint32_t                          protectionToken_pCallBackDMA;
  mcuxClSession_HwInterruptHandler_t pCallBackCopro;
  uint32_t                          protectionToken_pCallBackCopro;
  void *pClWorkarea; /* Used for non blocking flow to handover cl data to the interrupt */
} mcuxClSession_JobContext_t;

/**
 * @brief Type for mcuxClSession API calls
 */
typedef struct mcuxClSession_apiCall mcuxClSession_apiCall_t;

/**
 * @brief Structure for mcuxClSession Descriptor
 */
struct mcuxClSession_Descriptor
{
  mcuxClSession_WorkArea_t cpuWa;    ///< Workarea for the CPU
  mcuxClSession_WorkArea_t pkcWa;    ///< Workarea for the PKC
  mcuxClRandom_Config_t randomCfg;   ///< Configuration of the Rng (contexts and mode)
  mcuxClResource_Context_t * pResourceCtx;  ///< Pointer to global resource context
  mcuxClSession_JobContext_t jobContext;    ///< Context of non-blocking job
  mcuxClSession_apiCall_t * apiCall;  ///< Context for API calls
  uint32_t *pMathUptrt; ///< UPTRT table pointer for math operations
};


/**
 * @}
 */ /* mcuxClSession_Types */

#endif /* MCUXCLSESSION_TYPES_H_ */
