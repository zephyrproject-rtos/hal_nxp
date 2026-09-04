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

/** @file  mcuxClMacModes_Sgi_Types.h
 *  @brief Internal header for MAC types for modes using the SGI HW
 */


#ifndef MCUXCLMACMODES_SGI_TYPES_H_
#define MCUXCLMACMODES_SGI_TYPES_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClMac_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClPadding.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClMacModes_Common_Wa.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Forwards declarations for internal types
 */

struct mcuxClMacModes_AlgorithmDescriptor;

typedef struct mcuxClMacModes_AlgorithmDescriptor mcuxClMacModes_AlgorithmDescriptor_t;

/**
 * @brief MAC mode algorithm type for algorithms using SGI
 *
 * This type is used to refer to a SGI-based MAC mode algorithm.
 */
typedef const mcuxClMacModes_AlgorithmDescriptor_t * const mcuxClMacModes_Algorithm_t;


/**
 * Engine function types
 */

/**
 * @brief Internal engine function, which processes an entire MAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  mode      Mac mode that should be used during the computation.
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength  Length of input buffer pointed to by @p pIn.
 * @param[out] pProcessedBytes  Number of bytes processed from @p pIn.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_ComputeFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (* mcuxClMacModes_ComputeFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
));

/**
 * @brief Internal engine function, which initializes the context for a MAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_InitFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClMacModes_InitFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMacModes_Context_t * const pContext
));

/**
 * @brief Internal engine function, which processes input to a MAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength  Length of input buffer pointed to by @p pIn.
 * @param[out] pProcessedBytes  Number of bytes processed from @p pIn.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_UpdateFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) (* mcuxClMacModes_UpdateFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
));

/**
 * @brief Internal engine function, which finalizes a MAC computation.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 *
 * @return void
 */

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_FinalizeFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClMacModes_FinalizeFunc_t)(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMacModes_Context_t * const pContext
));

/**
 * Helper function types
 */

/**
 * @brief Internal function to calculate a pre-tag over the given data.
 *
 * @param[in]  pInput         Pointer to the input buffer data to be authenticated
 * @param[in]  inOffset       Offset of the @p pInput buffer
 * @param[in]  inLength       Length of the data in the @p pInput buffer
 * @param[in]  operation      SGI operation configuration
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_ComputePreTagFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClMacModes_ComputePreTagFunc_t)(
  mcuxCl_InputBuffer_t pInput,
  uint32_t inputOffset,
  uint32_t inLength,
  uint32_t operation
));

/**
 * @brief Internal function, which copies out the result from the SGI to the output buffer.
 *
 * @param[in]  session         Handle for the current CL session.
 * @param[in]  dataProcessed   Indicates whether data has been processed.
 * @param[out] pMac            Pointer to result buffer, which the MAC result will be written to.
 * @param[out] pOutLength      Pointer to length of output data.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_CopyOutputFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClMacModes_CopyOutputFunc_t)(
  mcuxClSession_Handle_t session,
  uint32_t dataProcessed,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pOutLength
));


/**
 * @brief Function type to handle the last input block for DMA-driven oneshot modes
 *
 * @param[in]      session           Handle for the current CL session
 * @param[in]      pWa               Handle for the current workarea (word-aligned)
 * @param[in]      pAlgo             Pointer to the algorithm descriptor
 * @param[in]      pIn               Pointer to last block input data
 * @param[in]      inOffset          Offset of the @p pIn buffer
 * @param[in]      totalInputLength  Total input size in bytes
 * @param[in]      remainingBytes    Number of remaining bytes in buffer @p pIn
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClMacModes_handleLastBlock_oneshot_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClMacModes_handleLastBlock_oneshot_t)(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * pWa,
  mcuxClMacModes_Algorithm_t pAlgo,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t totalInputLength,
  uint32_t remainingBytes
));

/**
 * Internal structures / types
 */

/**
 * @brief MAC mode algorithm descriptor structure for algorithms using SGI
 *
 * This structure captures all the information that the MAC interfaces need
 * to know about a SGI MAC modes.
 */
struct mcuxClMacModes_AlgorithmDescriptor
{
  /* Function pointers */
  mcuxClMacModes_ComputeFunc_t       compute;
  uint32_t                          protectionToken_compute;
  mcuxClMacModes_handleLastBlock_oneshot_t   handleLastBlock_oneshot;
  uint32_t                                  protectionToken_handleLastBlock_oneshot;
  mcuxClMacModes_InitFunc_t          init;
  uint32_t                          protectionToken_init;
  mcuxClMacModes_UpdateFunc_t        update;
  uint32_t                          protectionToken_update;
  mcuxClMacModes_FinalizeFunc_t      finalize;
  uint32_t                          protectionToken_finalize;
  mcuxClMacModes_CopyOutputFunc_t    copyOut;
  uint32_t                          protectionToken_copyOut;
  /* Padding options */
  mcuxClPadding_addPaddingMode_t     addPadding;
  uint32_t                          protectionToken_addPadding;
};



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_SGI_TYPES_H_ */
