/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025-2026 NXP                                            */
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

/** @file  mcuxClXof_Functions.h
 *  @brief Top-level API of the mcuxClXof component */

#ifndef MCUXCLXOF_FUNCTIONS_H_
#define MCUXCLXOF_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxClXof_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClXof_Functions mcuxClXof_Functions
 * @brief Defines all functions of @ref mcuxClXof
 * @ingroup mcuxClXof
 * @{
 */

/**********************************************************************/
/* ONE-SHOT                                                           */
/**********************************************************************/

/**
 * @brief One-shot Xof computation function
 *
 * This function performs an Xof (eXtendable Output Function) computation over the input message \p pIn, using the Xof function provided by the
 * \p algorithm input parameter, in one shot. Up to 2^32 bytes of data can be handled with this function.
 * The optional \p pCustomization buffer can be used to customize the output for some Xof functions. If none is used, \p customizationSize shall be set to 0.
 *
 * For example, to perform a cSHAKE128 computation, the following needs to be provided:
 *  - cSHAKE128 algorithm
 *  - Input data
 *  - (Optional) customization data
 *  - Output buffer
 *  - Requested output size

 *
 * The input parameter \p session has to be initialized by the function mcuxClSession_init prior to calling this function.
 *
 * @param[in,out]   session             Handle for the current CL session.
 * @param[in]       algorithm           Xof algorithm that should be used during the computation.
 * @param[in]       pIn                 Pointer to the input buffer that contains the data that needs to be handled.
 * @param[in]       inSize              Number of bytes of data in the \p pIn buffer.
 * @param[in]       pCustomization      Pointer to the customization buffer that contains additional data to be used in the computation (Optional)
 * @param[in]       customizationSize   Number of bytes of data in the \p pCustomization buffer.
 * @param[out]      pOut                Pointer to the output buffer where the computed Xof value is written.
 * @param[in]       outSize             Indicates the requested byte length of the output
 *
 * @return status
 * @retval MCUXCLXOF_STATUS_OK               Xof operation successful
 * @retval MCUXCLXOF_STATUS_FAILURE          Error occured during Xof operation
 * @retval MCUXCLXOF_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * \implements{REQ_788297}
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_compute)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_compute(
    mcuxClSession_Handle_t session,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
);

/**********************************************************************/
/* MULTIPART                                                          */
/**********************************************************************/

/**
 * @brief Multi-part Xof initialization function
 *
 * This function performs the initialization for a multi-part Xof operation.
 *
 * @param[in,out]   session             Handle for the current CL session.
 * @param[out]      pContext            Xof context (word-aligned) which is used to maintain the state and store other relevant information about the operation.
 * @param[in]       algorithm           Xof algorithm that should be used during the computation operation.
 * @param[in]       pCustomization      Pointer to the customization buffer that contains additional data to be used in the computation (Optional)
 * @param[in]       customizationSize   Number of bytes of data in the \p pCustomization buffer.
 *
 * @return status
 * @retval MCUXCLXOF_STATUS_OK               Initialization successful
 * @retval MCUXCLXOF_STATUS_FAILURE          Error occurred during initialization function
 * @retval MCUXCLXOF_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * \implements{REQ_788296}
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_init(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize
);

/**
 * @brief Multi-part Xof processing function
 *
 * This function performs the processing of (a part of) a data stream for a
 * Xof operation. The algorithm to be used will be determined based on the
 * context that is provided. It can be called several times but before the first call,
 * mcuxClXof_init needs to be called to prepare a context.
 *
 * @param[in,out]   session    Handle for the current CL session.
 * @param[in,out]   pContext   Xof context (word-aligned) which is used to maintain the state and
 *                             store other relevant information about the operation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data that
 *                             needs to be processed.
 * @param[in]       inSize     Number of bytes of data in the \p pIn buffer.
 *
 * @return status
 * @retval MCUXCLXOF_STATUS_OK               Xof operation successful
 * @retval MCUXCLXOF_STATUS_FAILURE          Error occurred during Xof operation
 * @retval MCUXCLXOF_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * \implements{REQ_788296}
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_process(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
);

/**
 * @brief Multi-part Xof generation function
 *
 * This function is used to obtain (part of) a data stream for a
 * Xof operation after all input has been processed. The algorithm to be used will be determined based on the
 * context that is provided. It can be called several times but before the first call,
 * mcuxClXof_init needs to be called to prepare a context.
 * After the first call to mcuxClXof_generate, adding additional data with mcuxClXof_process
 * will result in an error.
 *
 * @param[in,out]   session         Handle for the current CL session.
 * @param[in,out]   pContext        Xof context (word-aligned) which is used to maintain the state and store other relevant information about the operation.
 * @param[out]      pOut            Pointer to the output buffer where the computed Xof value is written.
 * @param[in]       outSize         Indicates the requested byte length of the output
 *
 * @return status
 * @retval MCUXCLXOF_STATUS_OK               Xof operation successful
 * @retval MCUXCLXOF_STATUS_FAILURE          Error occurred during Xof operation
 * @retval MCUXCLXOF_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * \implements{REQ_788296}
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_generate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_generate(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
);

/**
 * @brief Multi-part Xof computation cleanup function
 *
 * This function performs the cleanup of a multi-part Xof computation operation.
 * It should be called after all required output has been generated using mcuxClXof_generate.
 * The given Xof context is destroyed and can no longer be used to output additional data.
 *
 * @param[in,out]   session    Handle for the current CL session.
 * @param[in,out]   pContext   Xof context (word-aligned) which is used to maintain the state and
 *                             store other relevant information about the operation.
 *
 * @return status
 * @retval MCUXCLXOF_STATUS_OK               Xof cleanup successful
 * @retval MCUXCLXOF_STATUS_FAILURE          Error occurred during Xof cleanup
 * @retval MCUXCLXOF_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * \implements{REQ_788296}
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_finish(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext
);

/**
 * @}
 */ /* mcuxClXof_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLXOF_FUNCTIONS_H_ */

