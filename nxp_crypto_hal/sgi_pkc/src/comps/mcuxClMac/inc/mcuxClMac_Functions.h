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
 * @file  mcuxClMac_Functions.h
 * @brief Top-level API of the mcuxClMac component
 */

#ifndef MCUXCLMAC_FUNCTIONS_H_
#define MCUXCLMAC_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClMac_Types.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClMac_Functions mcuxClMac_Functions
 * @brief Defines all functions of @ref mcuxClMac
 * @ingroup mcuxClMac
 * @{
*/

/****************************************************************************/
/* ONESHOT                                                                  */
/****************************************************************************/

/**
 * @defgroup mcuxClMac_OneShot One-shot MAC interfaces
 * @brief Interfaces to perform MAC operations in one shot.
 * @ingroup mcuxClMac_Functions
 * @{
 */

/**
 * @brief One-shot message authentication code (MAC) computation function.
 *
 * This function performs a MAC computation in one shot. The algorithm to be
 * used will be determined based on the key that is provided.
 *
 * For example, to perform an AES MAC computation with a 128-bit key in CMAC
 * mode on padded data, the following needs to be provided:
 *  - AES128 key
 *  - CMAC mode
 *  - Input data
 *  - Output data buffer, at least the size of a single AES block
 *
 * @attention In some cases restrictions may apply, e.g. the input buffer must
 * be prepared for padding. Please refer to mcuxClMacModes_Modes.h to find further
 * details and restrictions for each specific mode.
 */
/**
 * This function supports non-blocking operation modes. If a non-blocking mode
 * is used, this function starts the operation and returns while coprocessors
 * are still operating, unblocking the CPU in the meantime. Interrupt handlers
 * need to be installed appropriately to retrieve the information that the
 * coprocessors finished processing the data.
 * Call @ref mcuxClResource_handle_interrupt to complete this operation.
 */
/**
 * @param[in]  session     Handle for the current CL session.
 * @param[in]  key         Key to be used to authenticate the data (word-aligned).
 * @param[in]  mode        Mode that should be used during the MAC operation.
 * @param[in]  pIn         Pointer to the input buffer that contains the data that
 *                         needs to be authenticated.
 * @param[in]  inLength    Number of bytes of data in the @p pIn buffer.
 * @param[out] pMac        Pointer to the output buffer where the MAC needs to be written.
 * @param[out] pMacLength  Will be set to the number of bytes of data that
 *                         have been written to the @p pMac buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLMAC_STATUS_OK             Mac operation successful
 * @retval MCUXCLMAC_STATUS_ERROR          Error occurred during Mac operation
 * @retval MCUXCLMAC_STATUS_INVALID_PARAM  An invalid parameter was given to the function
 * @retval MCUXCLMAC_STATUS_FAULT_ATTACK   Fault attack detected */
/**
 * @retval MCUXCLSGI_STATUS_UNWRAP_ERROR   Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains a RFC3394 wrapped key which was not pre-loaded yet, this operation
 * will unwrap the key material. This can potentially lead to a MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
/**
 * @attention For GMAC, the H-key is created and always loaded to SGI KEY2. 
 * It is caller's responsibility to not have a preloaded key in SGI KEY2 when calling a GMAC operation. 
 */
/**
 * @retval MCUXCLMAC_STATUS_JOB_STARTED    Non-blocking operation started successfully
 * @retval MCUXCLMAC_STATUS_JOB_COMPLETED  Non-blocking operation successful
 *
 * @attention For non-blocking modes:
 * The @p inLength has an upper limit of 0x7fff0 bytes.
 * Also, if the @p inLength is small (only a few blocks of data), this
 * function is not guaranteed to return in a non-blocking matter, but might
 * return after all data was already processed. The status code shall
 * be used as an indicator, where only @ref MCUXCLMAC_STATUS_JOB_STARTED
 * indicates that a non-blocking operation has started.
 */
/**
 * @implements{REQ_788244}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMac_compute)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_compute(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
);

/**
 * @}
 */ /* mcuxClMac_OneShot */

#ifdef MCUXCL_FEATURE_MAC_SELFTEST
/**
 * @brief message authentication code (MAC) selftest function
 * @api
 *
 * This function performs a mac selftest operation.
 * The algorithm to be used will be determined based on the mode and test types that are provided.
 *
 * For example, to perform an SM4 CBCMAC selftest operation, the following needs to be provided:
 *  - SM4 CBCMAC mode
 *  - mcuxClMac_Test_SM4_CBCMAC for test descriptor
 *
 * @param[in]      session       Handle for the current CL session.
 * @param[in]      mode          Mode that should be used during the MAC selftest operation.
 * @param[in]      test          MAC selftest type that should be used during the selftest operation.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLMAC_STATUS_OK            Mac operation successful
 * @retval MCUXCLMAC_STATUS_ERROR         Error occurred during Mac operation
 * @retval MCUXCLMAC_STATUS_INVALID_PARAM An invalid parameter was given to the function
 * @retval MCUXCLMAC_STATUS_FAULT_ATTACK  Fault attack detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMac_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_selftest(
  mcuxClSession_Handle_t session,
  mcuxClMac_Mode_t mode,
  mcuxClMac_Test_t test
); /* selftest */
#endif /* MCUXCL_FEATURE_MAC_SELFTEST */

/****************************************************************************/
/* MULTIPART                                                                */
/****************************************************************************/

/**
 * @defgroup mcuxClMac_MultiPart Multi part MAC interfaces
 * @brief Interfaces to perform MAC operations in multi part.
 * @ingroup mcuxClMac_Functions
 * @{
 */

/**
 * @brief Initialization for a multipart MAC computation.
 *
 * This function performs the initialization of a context for a multipart MAC
 * computation. The algorithm to be used will be determined based on the key
 * that is provided. After init operation, a pointer to the whole key handle
 * is stored in context. The user of the Crypto Library needs to keep the keyHandle
 * alive until the mcuxClMac_finish/mcuxClMac_verify phase of mac multipart operation.
 *
 * This function should only be called once, as the first step for a multipart
 * computation.
 *
 * For example, to perform a multipart AES MAC computation with a 128-bit key
 * in CMAC mode on padded data, the following needs to be provided in this step:
 *  - AES128 key
 *  - CMAC mode
 *
 * The size of the context depends on the mode used
 * (see @ref mcuxClMac_MemoryConsumption).
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  pContext  MAC context which is used to maintain the state and
 *                       store other relevant information about the operation (word-aligned).
 * @param[in]  key       Key to be used to MAC the data (word-aligned).
 * @param[in]  mode      Mode that should be used during the MAC operation.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLMAC_STATUS_OK            Mac operation successful
 * @retval MCUXCLMAC_STATUS_ERROR         Error occurred during Mac operation
 * @retval MCUXCLMAC_STATUS_INVALID_PARAM An invalid parameter was given to the function
 * @retval MCUXCLMAC_STATUS_FAULT_ATTACK  Fault attack detected
 */
/**
 * @retval MCUXCLSGI_STATUS_UNWRAP_ERROR  Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains a RFC3394 wrapped key which was not pre-loaded yet, this operation
 * will unwrap the key material. This can potentially lead to a MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
/**
 * @attention For GMAC, the H-key is created and always loaded to SGI KEY2. 
 * It is caller's responsibility to not have a preloaded key in SGI KEY2 when calling a GMAC operation. 
 */
/**
 * 
 * @implements{REQ_788243}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMac_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_init(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode
); /* init */

/**
 * @brief Data processing for a multipart MAC computation.
 *
 * This function performs the data processing for a multipart MAC computation.
 * The algorithm and key to be used will be determined based on the context that is provided.
 * The user of the Crypto Library needs to keep the keyHandle alive until the mcuxClMac_finish/
 * mcuxClMac_verify phase of mac multipart operation.

 * This function can be called multiple times, after the multipart context
 * initialization.
 *
 * For example, to perform a multipart AES MAC computation with a 128-bit key
 * in CMAC mode on padded data, the following needs to be provided in this step:
 *  - Input data
 */
/**
 * This function supports non-blocking operation modes. If a non-blocking mode
 * was used during @ref mcuxClMac_init, this function starts the operation
 * and returns while coprocessors are still operating, unblocking the CPU in
 * the meantime. Interrupt handlers need to be installed appropriately to retrieve
 * the information that the coprocessors finished processing the data.
 * Call @ref mcuxClResource_handle_interrupt to complete this operation.
 */
/**
 * The size of the context depends on the mode used
 * (see @ref mcuxClMac_MemoryConsumption).
 *
 * @see mcuxClMac_init
 *
 * @param      session   Handle for the current CL session.
 * @param[in]  pContext  MAC context which is used to maintain the state and
 *                       store other relevant information about the operation (word-aligned).
 * @param[in]  pIn       Pointer to the input buffer that contains the data that
 *                       need to be processed.
 * @param[in]  inLength  Number of bytes of data in the @p in buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLMAC_STATUS_OK             Mac operation successful
 * @retval MCUXCLMAC_STATUS_ERROR          Error occurred during Mac operation
 * @retval MCUXCLMAC_STATUS_INVALID_PARAM  An invalid parameter was given to the function
 * @retval MCUXCLMAC_STATUS_FAULT_ATTACK   Fault attack detected */
/**
 * @retval MCUXCLMAC_STATUS_JOB_STARTED    Non-blocking Mac operation started successfully
 * @retval MCUXCLMAC_STATUS_JOB_COMPLETED  Non-blocking Mac operation successful
 *
 * @attention For non-blocking modes:
 * The @p inLength has an upper limit of 0x7fff0 bytes.
 * Also, if the @p inLength is small (only a few blocks of data), this
 * function is not guaranteed to return in a non-blocking matter, but might
 * return after all data was already processed. The status code shall
 * be used as an indicator, where only @ref MCUXCLMAC_STATUS_JOB_STARTED
 * indicates that a non-blocking operation has started.
 */
/**
 * @implements{REQ_788243}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMac_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_process(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength
); /* update */

/**
 * @brief Finalize a MAC generation for a multipart MAC computation.
 *
 * This function performs the final MAC generation step for a multipart MAC
 * computation.
 * The algorithm and key to be used will be determined based on the context that is provided.
 * The user of the Crypto Library needs to keep the keyHandle alive until the mcuxClMac_finish
 * phase of mac multipart operation.
 *
 * This function should only be called once, as the last step for a multipart
 * computation.
 *
 * For example, to perform a multipart AES MAC computation with a 128-bit key
 * in CMAC mode on padded data, the following needs to be provided in this step:
 *  - Output data buffer, at least the size of a single AES block
 *
 * The size of the context depends on the mode used
 * (see @ref mcuxClMac_MemoryConsumption).
 *
 * @see mcuxClMac_init
 * @see mcuxClMac_process
 *
 * @param[in]  session     Handle for the current CL session.
 * @param[in]  pContext    MAC context which is used to maintain the state and
 *                         store other relevant information about the operation (word-aligned).
 * @param[out] pMac        Pointer to the output buffer where the MAC needs to be written.
 * @param[out] pMacLength  Will be set to the number of bytes of data that
 *                         have been written to the @p pMac buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLMAC_STATUS_OK            Mac operation successful
 * @retval MCUXCLMAC_STATUS_ERROR         Error occurred during Mac operation
 * @retval MCUXCLMAC_STATUS_INVALID_PARAM An invalid parameter was given to the function
 * @retval MCUXCLMAC_STATUS_FAULT_ATTACK  Fault attack detected
 * 
 * @implements{REQ_788243}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMac_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_finish(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
); /* finalize compute */

/**
 * @}
 */ /* mcuxClMac_MultiPart */

/**
 * @}
 */ /* mcuxClMac_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMAC_FUNCTIONS_H_ */
