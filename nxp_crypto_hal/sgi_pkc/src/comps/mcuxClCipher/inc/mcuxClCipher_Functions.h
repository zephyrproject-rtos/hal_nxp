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

/** @file  mcuxClCipher_Functions.h
 *  @brief Top-level API of the mcuxClCipher component */

#ifndef MCUXCLCIPHER_FUNCTIONS_H_
#define MCUXCLCIPHER_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClCipher_Types.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClCipher_Functions mcuxClCipher_Functions
 * @brief Interfaces to perform Cipher operations.
 * @ingroup mcuxClCipher
 * @{
 */



/**
 * @brief One-shot encryption function
 * @api
 *
 * This function performs an encryption operation in one shot. The algorithm
 * to be used will be determined based on the key and mode that are provided.
 *
 * For example, to perform an AES encryption operation with a 128-bit key in
 * CBC mode on padded data, the following needs to be provided:
 *  - AES128 key
 *  - CBC mode, without padding
 *  - IV, same size as the AES block size
 *  - Plain input data, size must be a multiple of the AES block size
 *  - Output data buffer, with the same size as the input data
 *  - Output size buffer, to store the amount of written bytes
 */
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * This function supports non-blocking operation modes. If a non-blocking mode
 * is used, this function starts the operation and returns while coprocessors
 * are still operating, unblocking the CPU in the meantime. Interrupt handlers
 * need to be installed appropriately to retrieve the information that the
 * coprocessors finished processing the data.
 * Call @ref mcuxClResource_handle_interrupt to complete this operation.
 */
#endif
/**
 * @param      session    Handle for the current CL session.
 * @param      key        Key to be used to encrypt the data (word-aligned).
 * @param      mode       Cipher mode that should be used during the encryption
 *                        operation.
 * @param[in]  pIv        Pointer to the buffer that contains the IV or salt,
 *                        if needed for the chosen @p mode, otherwise ignored.
 * @param      ivLength   Number of bytes of data in the @p pIv buffer.
 * @param[in]  pIn        Pointer to the input buffer that contains the plain
 *                        data that needs to be encrypted.
 * @param      inLength   Number of bytes of plain data in the @p pIn buffer.
 * @param[out] pOut       Pointer to the output buffer where the encrypted data
 *                        needs to be written.
 * @param[out] pOutLength Will be set to the number of bytes of encrypted
 *                        data that have been written to the @p pOut buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLCIPHER_STATUS_OK              Cipher operation successful
 * @retval MCUXCLCIPHER_STATUS_ERROR           Error occurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_FAILURE         Functional failure ocurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_INVALID_INPUT   An invalid parameter was given to the function
 * @retval MCUXCLCIPHER_STATUS_FAULT_ATTACK    Fault attack detected */
/**
 * @retval MCUXCLSGI_STATUS_UNWRAP_ERROR       Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains a RFC3394 wrapped key which was not pre-loaded yet, this operation
 * will unwrap the key material. This can potentially lead to a MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @retval MCUXCLCIPHER_STATUS_JOB_STARTED     Non-blocking Cipher operation started successfully
 * @retval MCUXCLCIPHER_STATUS_JOB_COMPLETED   Non-blocking Cipher operation successful
 *
 * @attention For non-blocking modes:
 * The @p inLength has an upper limit of 0x7fff0 bytes.
 * Also, if the @p inLength is small (only a few blocks of data), this
 * function is not guaranteed to return in a non-blocking matter, but might
 * return after all data was already processed. The Cipher status code shall
 * be used as an indicator, where only @ref MCUXCLCIPHER_STATUS_JOB_STARTED
 * indicates that a non-blocking operation has started.
 */
#endif
/**
 * @attention When used with stream modes or RSA modes, the function uses PRNG, which has to be initialized prior to calling the function.
 * @implements{REQ_788206}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_encrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_encrypt(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

/**
 * @brief One-shot decryption function
 * @api
 *
 * This function performs a decryption operation in one shot. The algorithm to
 * be used will be determined based on the key and mode that are provided.
 *
 * For example, to perform an AES decryption operation with a 128-bit key in
 * CBC mode on padded data, the following needs to be provided::
 *  - AES128 key
 *  - CBC mode, without padding
 *  - IV, same size as the AES block size
 *  - Encrypted input data, size must be a multiple of the AES block size
 *  - Output data buffer, with the same size as the input data
 *  - Output size buffer, to store the amount of written bytes
 */
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * This function supports non-blocking operation modes. If a non-blocking mode
 * is used, this function starts the operation and returns while coprocessors
 * are still operating, unblocking the CPU in the meantime. Interrupt handlers
 * need to be installed appropriately to retrieve the information that the
 * coprocessors finished processing the data.
 * Call @ref mcuxClResource_handle_interrupt to complete this operation.
 */
#endif
/**
 * @param      session    Handle for the current CL session.
 * @param      key        Key to be used to decrypt the data (word-aligned).
 * @param      mode       Cipher mode that should be used during the decryptionu
 *                        operation.
 * @param[in]  pIv        Pointer to the buffer that contains the IV or salt,
 *                        if needed for the chosen @p mode, otherwise ignored.
 * @param      ivLength   Number of bytes of data in the @p pIv buffer.
 * @param[in]  pIn        Pointer to the input buffer that contains the encrypted
 *                        data that needs to be decrypted.
 * @param      inLength   Number of bytes of encrypted data in the @p pIn buffer.
 * @param[out] pOut       Pointer to the output buffer where the plain data needs
 *                        to be written.
 * @param[out] pOutLength Will be set to the number of bytes of plain
 *                        data that have been written to the @p pOut buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLCIPHER_STATUS_OK              Cipher operation successful
 * @retval MCUXCLCIPHER_STATUS_ERROR           Error occurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_FAILURE         Functional failure ocurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_INVALID_INPUT   An invalid parameter was given to the function
 * @retval MCUXCLCIPHER_STATUS_FAULT_ATTACK    Fault attack detected */
/**
 * @retval MCUXCLSGI_STATUS_UNWRAP_ERROR       Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains a RFC3394 wrapped key which was not pre-loaded yet, this operation
 * will unwrap the key material. This can potentially lead to a MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @retval MCUXCLCIPHER_STATUS_JOB_STARTED     Non-blocking Cipher operation started successfully
 * @retval MCUXCLCIPHER_STATUS_JOB_COMPLETED   Non-blocking Cipher operation successful
 *
 * @attention For non-blocking modes:
 * The @p inLength has an upper limit of 0x7fff0 bytes.
 * Also, if the @p inLength is small (only a few blocks of data), this
 * function is not guaranteed to return in a non-blocking matter, but might
 * return after all data was already processed. The Cipher status code shall
 * be used as an indicator, where only @ref MCUXCLCIPHER_STATUS_JOB_STARTED
 * indicates that a non-blocking operation has started.
 */
#endif
/**
 * @attention When used with stream modes or RSA modes, the function uses PRNG, which has to be initialized prior to calling the function.
 * @implements{REQ_788206}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_decrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

#ifdef MCUXCL_FEATURE_CIPHER_SELFTEST
/**
 * @brief encryption and decryption selftest function
 * @api
 *
 * This function performs encryption and decryption selftest operation.
 * The algorithm to be used will be determined based on the mode and test that is
 * provided.
 *
 * For example, to perform an SM2 encryption and decryption selftest operation, the
 * following needs to be provided:
 *  - SM2 mode
 *  - mcuxClOsccaSm2_Test for selftest mode
 *
 * @param      session    Handle for the current CL session.
 * @param      mode       Cipher mode that should be used during the selftest
 * @param      test       Cipher selftest mode that should be used during the selftest
 *                        operation.
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_selftest(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Mode_t mode,
  mcuxClCipher_Test_t test
);
#endif /* MCUXCL_FEATURE_CIPHER_SELFTEST */


/**
 * @brief Multi-part encryption initialization function
 * @api
 *
 * This function performs the initialization for a multi part encryption
 * operation. The algorithm to be used will be determined based on the key
 * that is provided. After init operation, a pointer to the whole key handle
 * is stored in context. The user of the Crypto Library needs to keep the
 * keyHandle alive until the mcuxClCipher_finish phase of cipher multipart operation.
 *
 * @param      session  Handle for the current CL session.
 * @param      pContext Cipher context which is used to maintain the state and
 *                      store other relevant information about the operation (word-aligned).
 * @param      key      Key to be used to encrypt the data (word-aligned).
 * @param      mode     Cipher mode that should be used during the encryption
 *                      operation.
 * @param[in]  pIv      Pointer to the buffer that contains the IV, if needed
 *                      for the chosen @p mode, otherwise ignored.
 * @param      ivLength Number of bytes of data in the @p pIv buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLCIPHER_STATUS_OK              Cipher operation successful
 * @retval MCUXCLCIPHER_STATUS_ERROR           Error occurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_FAILURE         Functional failure ocurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_INVALID_INPUT   An invalid parameter was given to the function
 * @retval MCUXCLCIPHER_STATUS_FAULT_ATTACK    Fault attack detected
 */
/**
 * @retval MCUXCLSGI_STATUS_UNWRAP_ERROR       Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains a RFC3394 wrapped key which was not pre-loaded yet, this operation
 * will unwrap the key material. This can potentially lead to a MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
/**
 * 
 * @implements{REQ_788203,REQ_788205}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_init_encrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_init_encrypt(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
); /* init encrypt */

/**
 * @brief Multi-part decryption initialization function
 * @api
 *
 * This function performs the initialization for a multi part decryption
 * operation. The algorithm to be used will be determined based on the key
 * that is provided. After init operation, a pointer to the whole key handle
 * is stored in context. The user of the Crypto Library needs to keep the
 * keyHandle alive until the mcuxClCipher_finish phase of cipher multipart operation.
 *
 * @param      session  Handle for the current CL session.
 * @param      pContext Cipher context which is used to maintain the state and
 *                      store other relevant information about the operation (word-aligned).
 * @param      key      Key to be used to encrypt the data (word-aligned).
 * @param      mode     Cipher mode that should be used during the encryption
 *                      operation.
 * @param[in]  pIv      Pointer to the buffer that contains the IV, if needed
 *                      for the chosen @p mode, otherwise ignored.
 * @param      ivLength Number of bytes of data in the @p pIv buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLCIPHER_STATUS_OK              Cipher operation successful
 * @retval MCUXCLCIPHER_STATUS_ERROR           Error occurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_FAILURE         Functional failure ocurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_INVALID_INPUT   An invalid parameter was given to the function
 * @retval MCUXCLCIPHER_STATUS_FAULT_ATTACK    Fault attack detected
 */
/**
 * @retval MCUXCLSGI_STATUS_UNWRAP_ERROR       Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains a RFC3394 wrapped key which was not pre-loaded yet, this operation
 * will unwrap the key material. This can potentially lead to a MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
/**
 * 
 * @implements{REQ_788203,REQ_788205}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_init_decrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_init_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
); /* init decrypt */

/**
 * @brief Multi-part encryption/decryption processing function
 * @api
 *
 * This function performs the processing of (a part of) a data stream for an
 * encryption/decryption operation. The algorithm and key to be used will be
 * determined based on the context that is provided. The user of the Crypto
 * Library needs to keep the keyHandle alive until the mcuxClCipher_finish phase
 * of cipher multipart operation.
 * Data is processed in full blocks only. Remaining data is stored in the context
 * to be handled in later process or finish calls.
 */
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * This function supports non-blocking operation modes. If a non-blocking mode
 * was used during @ref mcuxClCipher_init, this function starts the operation
 * and returns while coprocessors are still operating, unblocking the CPU in
 * the meantime. Interrupt handlers need to be installed appropriately to retrieve
 * the information that the coprocessors finished processing the data.
 * Call @ref mcuxClResource_handle_interrupt to complete this operation.
 */
#endif
/**
 * @param      session    Handle for the current CL session.
 * @param      pContext   Cipher context which is used to maintain the state and
 *                        store other relevant information about the operation (word-aligned).
 * @param[in]  pIn        Pointer to the input buffer that contains the data that
 *                        needs to be processed.
 * @param      inLength   Number of bytes of data in the @p pIn buffer.
 * @param[out] pOut       Pointer to the output buffer where the processed data
 *                        needs to be written.
 * @param[out] pOutLength Will be set to the number of bytes of processed
 *                        data that have been written to the @p pOut buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLCIPHER_STATUS_OK              Cipher operation successful
 * @retval MCUXCLCIPHER_STATUS_ERROR           Error occurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_FAILURE         Functional failure ocurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_INVALID_INPUT   An invalid parameter was given to the function
 * @retval MCUXCLCIPHER_STATUS_FAULT_ATTACK    Fault attack detected */
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @retval MCUXCLCIPHER_STATUS_JOB_STARTED     Non-blocking Cipher operation started successfully
 * @retval MCUXCLCIPHER_STATUS_JOB_COMPLETED   Non-blocking Cipher operation successful
 *
 * @attention For non-blocking modes:
 * The @p inLength has an upper limit of 0x7fff0 bytes.
 * Also, if the @p inLength is small (only a few blocks of data), this
 * function is not guaranteed to return in a non-blocking matter, but might
 * return after all data was already processed. The Cipher status code shall
 * be used as an indicator, where only @ref MCUXCLCIPHER_STATUS_JOB_STARTED
 * indicates that a non-blocking operation has started.
 * 
 * @implements{REQ_788203,REQ_788205}
 */
#endif
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_process(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
); /* update */

/**
 * @brief Multi-part encryption/decryption finalization function
 * @api
 *
 * This function performs the finalization of an encryption or decryption
 * operation. The algorithm and key to be used will be determined based on the
 * context that is provided. The user of the Crypto Library needs to keep the
 * keyHandle alive until the mcuxClCipher_finish phase of cipher multipart operation.
 * No new data is accepted but remaining data in the context is processed.
 *
 * @param      session    Handle for the current CL session.
 * @param      pContext   Cipher context which is used to maintain the state and
 *                        store other relevant information about the operation (word-aligned).
 * @param[out] pOut       Pointer to the output buffer where the processed data
 *                        needs to be written.
 * @param[out] pOutLength Will be set to the number of bytes of processed
 *                        data that have been written to the @p pOut buffer.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLCIPHER_STATUS_OK              Cipher operation successful
 * @retval MCUXCLCIPHER_STATUS_ERROR           Error occurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_FAILURE         Functional failure ocurred during Cipher operation
 * @retval MCUXCLCIPHER_STATUS_INVALID_INPUT   An invalid parameter was given to the function
 * @retval MCUXCLCIPHER_STATUS_FAULT_ATTACK    Fault attack detected
 *
 * @attention When used with stream modes, the function uses PRNG, which has to be initialized prior to calling the function.
 * 
 * @implements{REQ_788203,REQ_788205}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipher_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_finish(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
); /* finalize */



/** @} */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHER_FUNCTIONS_H_ */
