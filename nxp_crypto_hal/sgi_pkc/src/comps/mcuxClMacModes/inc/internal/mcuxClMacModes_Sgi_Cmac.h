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

#ifndef MCUXCLMACMODES_SGI_CMAC_H_
#define MCUXCLMACMODES_SGI_CMAC_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>

#include <internal/mcuxClSession_Internal.h>
#include <mcuxClMac_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

/* Used as option for mcuxClMacModes_CmacGenerateSubKeys */
#define MCUXCLMACMODES_AES_CMAC_K1_ONLY    (0xA5A5U)
#define MCUXCLMACMODES_AES_CMAC_K1_AND_K2  (0x5A5AU)

/* Internal CMAC defines */
#define MCUXCLMACMODES_AES_CMAC_MSB_MASK (0x80000000U)
#define MCUXCLMACMODES_AES_CMAC_RB_CONST (0x87U)

/* Internal CMAC functions */

/**
 * @brief Internal function, which processes an entire CMAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  mode      Mac mode that should be used during the computation.
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength  Size of input buffer pointed to by pIn.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_computeCMAC, mcuxClMacModes_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_computeCMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
);


/**
 * @brief Internal function, which processes an entire CMAC computation.
 *        All input data will be copied with the DMA.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  mode      Mac mode that should be used during the computation.
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength  Size of input buffer pointed to by pIn.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_computeCMAC_nonBlocking, mcuxClMacModes_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_computeCMAC_nonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
);

/**
 * @brief This function handles the processing of the last block for CMAC oneshot.
 *
 * This function handles the processing of the last block (remaining bytes) for
 * a CMAC oneshot (compute/compare) operation. It completes the engine operation.
 *
 * @param      session         Handle for the current CL session.
 * @param      pWa             pointer to mac wa for data sharing across interrupts (word-aligned)
 *
 * @pre Full input blocks where already processed (either blocking or non-blocking)
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_handleLastBlock_cmac_oneshot, mcuxClMacModes_handleLastBlock_oneshot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_handleLastBlock_cmac_oneshot(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * pWa,
  mcuxClMacModes_Algorithm_t pAlgo,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t totalInputLength,
  uint32_t remainingBytes
);

/**
 * @brief Internal function, which processes input to a CMAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength    Size of input buffer pointed to by @p pIn.
 * @param[out] pProcessedBytes  Number of bytes processed from @p pIn. RFU.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_updateCMAC, mcuxClMacModes_UpdateFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_updateCMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
);


/**
 * @brief Internal function, which processes input to a CMAC computation.
 *        All input data will be copied with the DMA.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength    Size of input buffer pointed to by @p pIn.
 * @param[out] pProcessedBytes  Number of bytes processed from @p pIn.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_updateCMAC_nonBlocking, mcuxClMacModes_UpdateFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_updateCMAC_nonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea UNUSED_PARAM,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
);


/**
 * @brief Internal function, which finalizes a CMAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_finalizeCMAC, mcuxClMacModes_FinalizeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeCMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext);


/* Internal CMAC helper functions */

/**
 * @brief Internal function, which generates the subkeys K1 and K2.
 *
 * @pre The key has been loaded to SGI.
 * @post The selected subkey is present in DATOUT
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  pWa       Pointer to the workarea (word-aligned), where subkeys will be stored.
 * @param[in]  option    Option to compute or skip the computation of K2.
 *                       Either MCUXCLMACMODES_AES_CMAC_K1_ONLY
 *                       or MCUXCLMACMODES_AES_CMAC_K1_AND_K2.
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_CmacGenerateSubKeys)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_CmacGenerateSubKeys(mcuxClSession_Handle_t session, mcuxClMacModes_WorkArea_t* pWa, uint32_t option);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_SGI_CMAC_H_ */
