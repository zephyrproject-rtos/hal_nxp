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

/** @file  mcuxClRsa_Internal_Functions.h
 *  @brief Internal functions of the mcuxClRsa component
 */

#ifndef MCUXCLRSA_INTERNAL_FUNCTIONS_H_
#define MCUXCLRSA_INTERNAL_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClHash.h>
#include <mcuxClRsa_Types.h>
#include <mcuxClKey.h>
#include <internal/mcuxClKey_Types_Internal.h>

#include <mcuxClSignature.h>
#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <mcuxClCipher.h>
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClRsa_Internal_Functions mcuxClRsa_Internal_Functions
 * @brief Defines all internal functions of @ref mcuxClRsa
 * @ingroup mcuxClRsa
 * @{
 */

/**
 * @brief RSA public operation
 *
 * This function performs an RSA public key operation according to PKCS #1 v2.2.
 * The supported bit-lengths of the modulus range from 512 to 8192 in multiples of 8.
 * The public exponent is limited to 2 <= e < N.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                  Key handle for the input key (word-aligned)
 * @param[in]  pInput               Buffer which contains the input
 * @param[out] pOutput              Pointer to result
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key entries meet the following conditions:
 *              - A valid public key should be provided;
 *              - The supported bit-lengths of the modulus range from 512 to 8192 in multiples of 8;
 *              - It is required that e is greater or equal to 2 and smaller than n.
 *      <dt>pInput:</dt>
 *          <dd>The input must meet the following conditions:
 *               - It is provided in big-endian byte order;
 *               - The input length is determined by the modulus length.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - It is located in PKC RAM;
 *               - A buffer of MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(modulus length) + 2U * MCUXCLRSA_PKC_WORDSIZE bytes has to be allocated;
 *               - The result is stored in little-endian byte order in the buffer pointed to by pOutput with modulus length.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_public, mcuxClRsa_PublicExpEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_public(
  mcuxClSession_Handle_t      pSession,
  mcuxClKey_Handle_t          key,
  mcuxCl_InputBuffer_t        pInput,
  uint8_t                   *pOutput
);

/**
 * @brief RSA Public key operation with blinding applied to the modulus
 *
 * Data Integrity: Expunge(byteLenExp + pExp), due to the call to mcuxClMath_ModExp_SqrMultL2R
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  iR_iX_iN_iT1         PKC operand index
 * @param[in]  iT2_iT3_iT4          PKC operand index
 * @param[in]  byteLenExp           length of the exponent
 * @param[in]  pExp                 Pointer to the exponent
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>iR_iX_iN_iT1:</dt>
 *        <dd><code>iR</code> (bits 24~31): index of result (PKC operand).
 *        <br>Its size shall be at least operandSize + 2U * MCUXCLRSA_PKC_WORDSIZE
 *        <dd><code>iN</code> (bits 16~23): index of modulus, will be destroy (PKC operand).
 *        <br>Its size shall be at least operandSize + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindingSize=4), reserve one MCUXCLRSA_PKC_WORDSIZE before it
 *        <dd><code>iX</code> (bits 8~15): index of base number in Normal representation (PKC operand).
 *        <br>Its size shall be at least operandSize + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindingSize=4)
 *        <dd><code>iT1</code> (bits 0~7):index of temp1 (PKC operand).
 *        <br>Its size shall be at least operandSize + MCUXCLRSA_PKC_WORDSIZE + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindingSize=4)
 *      <dt>iT2_iT3_iT4:</dt>
 *        <dd><code>iT2</code> (bits 16~23):index of temp2 (PKC operand).
 *        <br>Its size shall be at least operandSize + MCUXCLRSA_PKC_WORDSIZE + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindingSize=4)
 *        <br>iX can be equal to iT2 if its size is big enough, in which case iX will be destroyed
 *        <dd><code>iT3</code> (bits 8~15): index of temp3(PKC operand).
 *        <br>Its size shall be at least operandSize + MCUXCLRSA_PKC_WORDSIZE + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindingSize=4)
 *        <dd><code>iT4</code> (bits 0~7): index of temp4 (PKC operand).
 *        <br>Its size shall be at least MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(blindingSize=4)
 *      <dt>byteLenExp:</dt>
 *        <dd>the length of exponent in byte.</dd>
 *      <dt>pExp:</dt>
 *        <dd>the exponent is a big-endian octet string and shall be non-zero.</dd>
 *  </dl></dd>
 * </dl>
 *
 * <dl>
 *   <dt>PKC properties</dt>
 *   <dd><dl>
 *     <dt>PS1 lengths</dt>
 *       <dd>PS1 OPLEN defines operandSize = nPkcByteLength (length of modulus N).</dd>
 *       <dd>PS1 OPLEN and MCLEN will be modified, and original values will be restored.</dd>
 *     <dt>PS2 lengths</dt>
 *       <dd>PS2 OPLEN and MCLEN will be modified, and original values will not be restored.</dd>
 *     <dt>ACTIV/GOANY</dt>
 *       <dd>#MCUXCLPKC_WAITFORFINISH will be called before returning to caller.</dd>
 *   </dl></dd>
 * </dl>
 *
 * @retval void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_publicExp)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_publicExp(
  mcuxClSession_Handle_t      pSession,
  uint32_t iR_iX_iN_iT1,
  uint32_t iT2_iT3_iT4,
  uint32_t byteLenExp,
  const uint8_t* const pExp
);


/**
 * @brief RSA private plain operation
 *
 * This function performs an RSA private plain key operation according to PKCS #1 v2.2.
 * The supported bit-lengths of the modulus range from 512 to 8192 in multiples of 8.
 * The private exponent is limited to d < N.
 *
 * Data Integrity: Expunge(MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                  Key handle for the input key (word-aligned)
 * @param[in]  pInput               Pointer to input
 * @param[out] pOutput              Buffer to hold the result
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key entries meet the following conditions:
 *              - A valid private key in plain format should be provided;
 *              - The supported bit-lengths of the modulus range from 512 to 8192 in multiples of 8;
 *              - It is required that d is smaller than n.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is located in PKC RAM;
 *               - It is provided in little-endian byte order;
 *               - The input buffer length should be:
 *                 MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(modulus length) = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(modulus length) + 2*MCUXCLRSA_PKC_WORDSIZE.
 *                 Inside this buffer, the input has the same byte length as the modulus, while upper bytes are used as temporary buffer for internal operations.
 *               - It is overwritten by the function.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - A buffer of modulus length bytes has to be allocated;
 *               - The result is stored in big-endian byte order in the buffer pointed to by pOutput.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses PRNG which has to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_privatePlain)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_privatePlain(
  mcuxClSession_Handle_t      pSession,
  mcuxClKey_Handle_t          key,
  uint8_t                   *pInput,
  mcuxCl_Buffer_t             pOutput
);


/**
 * @brief RSA private CRT operation
 *
 * This function performs an RSA private CRT key operation according to PKCS #1 v2.2.
 * The supported bit-lengths of the modulus range from 512 to 8192 in multiples of 8.
 * The length of the primes is limited to: size(p) = size(q) = 1/2 size(n).
 * The private exponent is limited to d < N.
 *
 * Data Integrity: Expunge(MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT) for pKey->keyType == MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT,
 *              or Expunge(MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA) for pKey->keyType == MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                  Key handle for the input key (word-aligned)
 * @param[in]  pInput               Pointer to input
 * @param[out] pOutput              Buffer to hold the result
 *
 ** <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key entries meet the following conditions:
 *              - A valid private key in CRT format should be provided; its type shall be
 *                MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT or MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA;
 *              - The supported bit-lengths of the modulus range from 512 to 8192 in multiples of 8;
 *              - The length of the primes is limited to: size(p) = size(q) = 1/2 size(n);
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is located in PKC RAM;
 *               - It is provided in little-endian byte order;
 *               - The input length is determined by the modulus length.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - A buffer of modulus length bytes has to be allocated;
 *               - The result is stored in big-endian byte order in the buffer pointed to by pOutput.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses PRNG which has to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_privateCRT)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_privateCRT(
  mcuxClSession_Handle_t      pSession,
  mcuxClKey_Handle_t          key,
  uint8_t                   *pInput,
  mcuxCl_Buffer_t             pOutput
);

// TODO CLNS-15273: Move this block higher in the file above mcuxClRsa_privateCRT and below mcuxClRsa_privatePlain.



/**
 * @brief RSA mask generation function
 *
 * This function is used to implement the mask generation function MGF1 of PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pInput               Pointer to seed, of which the mask is generated
 * @param[in]  inputLength          Length of seed, of which mask is generated
 * @param[in]  outputLength         Length of mask to be generated
 * @param[out] pOutput              Pointer to result
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the mask generation function operation.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is located in PKC RAM.
 *      <dt>inputLength:</dt>
 *          <dd>Byte-length of the seed, of which the mask is generated.
 *      <dt>outputLength:</dt>
 *          <dd>Byte-length of mask, which is generated.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - A buffer of outputLength bytes has to be allocated.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through the session parameter.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_mgf1)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_mgf1(
  mcuxClSession_Handle_t       pSession,
  mcuxClHash_Algo_t            pHashAlgo,
  const uint8_t *             pInput,
  const uint32_t              inputLength,
  const uint32_t              outputLength,
  uint8_t *                   pOutput
);

/**
 * @brief RSA PSS Encoding operation
 *
 * This function performs an RSA PSS encoding operation according to EMSA-PSS-ENCODE of PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pInput               Input-Buffer, which contains the message digest to be encoded
 * @param[in]  inputLength          RFU: please set to zero
 * @param[in]  pVerificationInput   RFU: please set to NULL
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pLabel               RFU: please set to NULL
 * @param[in]  saltlabelLength      Byte-length of salt
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message).  Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              RFU: please set to zero
 * @param[out] pOutput              Buffer to hold the result
 * @param[out] pOutLength           RFU: please set to NULL
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the mask generation function operation.
 *      <dt>saltlabelLength:</dt>
 *          <dd>Byte-length salt.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - A buffer of modulus length bytes has to be allocated in PKC RAM;
 *               - The result is stored in little-endian byte order in the buffer pointed to by pOutput.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_pssEncode operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK          The function executed successfully.
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention DRBG and PKC have to be initialized prior to calling the function because DRBG and PKC RAM are used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pssEncode, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssEncode(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);


/**
 * @brief RSA PSS verification operation
 *
 * This function performs an RSA PSS verification operation according to EMSA-PSS-VERIFY of PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pInput               Buffer, which contains the message digest to be verified
 * @param[in]  inputLength          RFU: please set to zero
 * @param[in]  pVerificationInput   Pointer to buffer, which contains the encoded message digest to be verified. The content of the buffer is destroyed.
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pLabel               RFU: please set to NULL
 * @param[in]  saltlabelLength      Byte-length of salt
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message).  Note: This function only supports moduli, whose bit-length is a multiple of 8.
 * @param[in]  options              Options field
 * @param[out] pOutput              RFU: please set to NULL
 * @param[out] pOutLength           RFU: please set to NULL
 *
 *<dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *     <dt>pVerificationInput:</dt>
 *          <dd>The padded message meets the following conditions:
 *               - It is located in PKC RAM;
 *               - It is provided in little-endian byte order;
 *               - The buffer size is aligned to PKC words;
 *               - The content of the buffer is destroyed.
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the mask generation function operation.
 *      <dt>saltlabelLength:</dt>
 *          <dd>Byte-length salt.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>options:</dt>
 *          <dd> This field is used to select options of the sign operation:
 *                - bits 31-8: specify whether HW acceleration can be used
 *                - bits 7-0:  RFU; please set to zero
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_pssVerify operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_VERIFY_OK                   The function executed successfully.
 * @retval #MCUXCLRSA_STATUS_VERIFY_FAILED               The verification failed.
 *
 * @attention PKC has to be initialized prior to calling the function because PKC RAM is used.
 * @attention Data Integrity:
 *            Expunge(pInput + pVerificationInput)
 *            Record(returnCode)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pssVerify, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssVerify(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);


/**
 * @brief RSA PKCS1-v1_5 Encoding operation for signature generation
 *
 * This function performs an RSA PKCS1-v1_5 encoding operation according to EMSA-PKCS1-v1_5-ENCODE of PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pInput               Input-Buffer, which contains the message digest to be encoded
 * @param[in]  inputLength          RFU: please set to zero
 * @param[in]  pVerificationInput   RFU: please set to NULL
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pLabel               RFU: please set to NULL
 * @param[in]  saltlabelLength      RFU: please set to zero
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message).  Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              RFU: please set to zero
 * @param[out] pOutput              Buffer to hold the result
 * @param[out] pOutLength           RFU: please set to NULL
 *
 *<dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the mask generation function operation.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - A buffer of modulus length bytes has to be allocated in PKC RAM;
 *               - The result is stored in little-endian byte order in the buffer pointed to by pOutput.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_pkcs1v15Encode_sign operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK          The function executed successfully.
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention PKC has to be initialized prior to calling the function because PKC RAM is used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pkcs1v15Encode_sign, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Encode_sign(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);

/**
 * @brief RSA PKCS1-v1_5 verification operation
 *
 * This function performs an RSA PKCS1-v1_5 verification operation according to PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pInput               Input-Buffer, which contains the message digest to be verified
 * @param[in]  inputLength          RFU: please set to zero
 * @param[in]  pVerificationInput   Pointer to buffer, which contains the encoded message digest to be verified. The content of the buffer is destroyed.
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pLabel               RFU: please set to NULL.
 * @param[in]  saltlabelLength      RFU: please set to zero.
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message). Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              Options field
 * @param[out] pOutput              RFU: please set to NULL
 * @param[out] pOutLength           RFU: please set to NULL
 *
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>pVerificationInput:</dt>
 *          <dd>The padded message meets the following conditions:
 *               - It is provided in little-endian byte order;
 *               - It is located in PKC RAM;
 *               - The buffer size is aligned to PKC words;
 *               - The content of the buffer is destroyed.
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the mask generation function operation.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>options:</dt>
 *          <dd> This field is used to select options of the sign operation:
 *                - bits 31-8: specify whether HW acceleration can be usedo
 *                - bits 7-0:  RFU; please set to zero
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_pkcs1v15Verify operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_VERIFY_OK                   The function executed successfully.
 * @retval #MCUXCLRSA_STATUS_VERIFY_FAILED               The verification failed.
 *
 * @attention PKC has to be initialized prior to calling the function because PKC RAM is used.
 * @attention Data Integrity:
 *            Expunge(pInput + pVerificationInput)
 *            Record(returnCode)
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pkcs1v15Verify, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Verify(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);


/**
 * @brief Remove modulus blinding operation
 *
 * This function removes modulus blinding from the result of the exponentiation.
 *
 * @param[in] pSession            pointer to #mcuxClSession_Descriptor
 * @param[in] iR_iX_iNb_iB        indices of PKC operands
 * @param[in] iT2_iT1             indices of PKC operands
 * @param[in] nbPkcByteLength     length of Nb aligned to PKC word
 * @param[in] bPkcByteLength      length of B aligned to PKC word
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>iR_iX_iNb_iB:</dt>
 *        <dd><code>iB</code> (bits 0~7): index of blinding value with size bPkcByteLength (PKC operand).
 *        <br>Its size shall be at least bPkcByteLength.
 *        <br>The most significant PKC word of B shall be nonzero.
 *        <br>The blinding value must be odd.
 *        <br><code>iNb</code> (bits 8~15): index of blinded modulus Nb (PKC operand).
 *        <br>Its size shall be at least nbPkcByteLength.
 *        <br>The NbDash of modulus shall be stored in the PKC word before modulus.
 *        <br><code>iX</code> (bits 16~23): index of input X in Montgomery representation (PKC operand).
 *        <br>Its size shall be at least nbPkcByteLength.
 *        <br><code>iR</code> (bits 16~23: index of result R in normal representation (PKC operand)
 *        <br>Its buffer size shall be at least (nbPkcByteLength - bPkcByteLength + 2 * MCUXCLRSA_PKC_WORDSIZE).
 *        <br>The result fits in size = (nbPkcByteLength - bPkcByteLength + MCUXCLRSA_PKC_WORDSIZE).</dd>
 *      <dt>iT2_iT1:</dt>
 *       <dd><code>iT1</code> (bits 0~7): index of temp1 (PKC operand).
 *       <br>Its buffer size shall be at least (nbPkcByteLength + MCUXCLRSA_PKC_WORDSIZE).
 *       <br><code>iT2</code> (bits 8~15): index of temp2 (PKC operand).
 *       <br>Its buffer size shall be at least MAX(nbPkcByteLength, 3 * MCUXCLRSA_PKC_WORDSIZE).</dd>
 *     <dt>@p nbPkcByteLength</dt>
 *       <dd>Length of modulus Nb. It shall be a multiple of MCUXCLRSA_PKC_WORDSIZE.</dd>
 *     <dt>@p bPkcByteLength</dt>
 *       <dd>Length of blinding value B. It shall be a multiple of MCUXCLRSA_PKC_WORDSIZE.</dd>
 *  </dl></dd>
 * </dl>
 *
 * <dl>
 *   <dt>PKC properties</dt>
 *   <dd><dl>
 *     <dt>PS1 lengths</dt>
 *       <dd>PS1 OPLEN = MCLEN defines operandSize = nbPkcByteLength (length of modulus Nb).</dd>
 *     <dt>PS2 lengths</dt>
 *       <dd>PS2 OPLEN and MCLEN will be modified, and original values will not be restored.</dd>
 *     <dt>ACTIV/GOANY</dt>
 *       <dd>#MCUXCLPKC_WAITFORREADY will be called before returning to caller.
 *       <br>The PKC calculation might be still on-going,
 *           call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.</dd>
 *   </dl></dd>
 * </dl>
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_RemoveBlinding)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_RemoveBlinding(
     mcuxClSession_Handle_t pSession,
     uint32_t iR_iX_iNb_iB,
     uint16_t iT2_iT1,
     uint32_t nbPkcByteLength,
     uint32_t bPkcByteLength);

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) && defined(MCUXCL_FEATURE_RSA_RSAES_OAEP)
/**
 * @brief RSA OAEP Encoding operation
 *
 * This function performs an RSA OAEP Encoding operation according to PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pInput               Input-Buffer, which contains the message
 * @param[in]  inputLength          Size of Input
 * @param[in]  pVerificationInput   RFU: please set to NULL
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pLabel               Buffer, which contains the input label
 * @param[in]  saltlabelLength      Length of the input label
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message). Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              RFU: please set to zero.
 * @param[out] pOutput              Buffer to hold the output encoded message
 * @param[out] pOutLength           RFU: please set to NULL
 *
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>inputLength:</dt>
 *          <dd>Specifies the size of the buffer pointed to by pInput. It meets the following condition:
 *               - inputLength <= (8*keyBitLength) - (2*hLen) - 2
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the MGF1 and the lHash.
 *      <dt>pLabel:</dt>
 *          <dd>The label meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>saltlabelLength:</dt>
 *          <dd>Specifies the size of the buffer pointed to by label.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - The result is stored in big-endian byte order in the buffer pointed to by pOutput.
 *
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_oaepEncode operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK          The function executed successfully.
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT               The function failed due to invalid input parameters.
 * @retval #MCUXCLRSA_STATUS_ERROR                       An error occurred during the execution. In that case, expectations for the flow protection are not balanced.
 *
 * @attention DRBG and PKC have to be initialized prior to calling the function because DRBG and PKC RAM are used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_oaepEncode, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_oaepEncode(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) && defined(MCUXCL_FEATURE_RSA_RSAES_OAEP) */

#if defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) && defined(MCUXCL_FEATURE_RSA_RSAES_OAEP)
/**
 * @brief RSA OAEP Decoding operation
 *
 * This function performs an RSA OAEP Decoding operation according to PKCS #1 v2.2.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pInput               Input-Buffer, which contains the encoded message to be decoded
 * @param[in]  inputLength          Size of Input
 * @param[in]  pVerificationInput   RFU: please set to NULL.
 * @param[in]  pHashAlgo            Pointer to hash algorithm information
 * @param[in]  pLabel               Buffer, which contains the input label
 * @param[in]  saltlabelLength      Length of the input label
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message). Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              RFU: please set to zero.
 * @param[out] pOutput              Buffer to hold output decoded plaintext
 * @param[out] pOutLength           Length of output in bytes.
 *
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>inputLength:</dt>
 *          <dd>Specifies the size of the buffer pointed to by pInput.
 *      <dt>pHashAlgo:</dt>
 *          <dd>Specifies the targeted hash algorithm, to be used for the mask generation function operation.
 *      <dt>pLabel:</dt>
 *          <dd>The label meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>saltlabelLength:</dt>
 *          <dd>Specifies the size of the buffer pointed to by label.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - The result is stored in big-endian byte order in the buffer pointed to by pOutput.
 *
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_oaepDecode operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK          The function executed successfully.
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT               The decoding failed due to invalid input parameters or invalid encoding.
 * @retval #MCUXCLRSA_STATUS_ERROR                       An error occurred during the execution. In that case, expectations for the flow protection are not balanced.
 *
 * @attention PKC has to be initialized prior to calling the function because PKC RAM is used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_oaepDecode, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_oaepDecode(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) && defined(MCUXCL_FEATURE_RSA_RSAES_OAEP) */

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT)
/**
 * @brief RSA PKCS1-v1_5 Encoding operation for encryption
 *
 * This function performs an RSA PKCS1-v1_5 Encoding operation for encryption (EME-PKCS1-v1_5 encoding
 * inlcuding length checking of the input message) according to PKCS #1 v2.2.
 *
 * @param[in]  pSession             Not used
 * @param[in]  pInput               Input-Buffer, which contains the message
 * @param[in]  inputLength          Size of Input
 * @param[in]  pVerificationInput   Not used
 * @param[in]  pHashAlgo            Not used
 * @param[in]  pLabel               Not used
 * @param[in]  saltlabelLength      Not used
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message). Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              Not used
 * @param[out] pOutput              Buffer to hold the output encoded message
 * @param[out] pOutLength           Not used
 *
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>inputLength:</dt>
 *          <dd>Specifies the size of the buffer pointed to by pInput. It meets the following condition:
 *               - inputLength <= (8*keyBitLength) - 11
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - The result is stored in big-endian byte order in the buffer pointed to by pOutput.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_pkcs1v15Encode_encrypt operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK        The function executed successfully.
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT             The function failed due to invalid input parameters.
 * @retval #MCUXCLRSA_STATUS_ERROR                     An error occurred during the execution. In that case, expectations for the flow protection are not balanced.
 *
 * @attention This function uses DRBG which has to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pkcs1v15Encode_encrypt, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Encode_encrypt(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) && defined(MCUXCL_FEATURE_RSA_RSAES_PKCS1v15) */


#if defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
/**
 * @brief RSA PKCS1-v1_5 Decoding operation for decryption
 *
 * This function performs an RSA PKCS1-v1_5 Decoding operation for decryption (EME-PKCS1-v1_5 decoding)
 * according to PKCS #1 v2.2.
 *
 * @param[in]  pSession             Not used
 * @param[in]  pInput               Input-Buffer, which contains the encoded message to be decoded
 * @param[in]  inputLength          Not used
 * @param[in]  pVerificationInput   Not used
 * @param[in]  pHashAlgo            Not used
 * @param[in]  pLabel               Not used
 * @param[in]  saltlabelLength      Not used
 * @param[in]  keyBitLength         Bit-length of key (bit-length of encoded message). Note: This function only supports moduli, whose bit-length is a multiple of 8
 * @param[in]  options              Not used
 * @param[out] pOutput              Buffer to hold the output decoded plaintext
 * @param[out] pOutLength           Length of output in bytes.
 *
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pInput:</dt>
 *          <dd>The input meets the following conditions:
 *               - It is provided in big-endian byte order.
 *      <dt>keyBitLength:</dt>
 *          <dd>The key bit-length meets the following conditions:
 *               - This function only supports moduli, whose bit-length is a multiple of 8.
 *      <dt>pOutput:</dt>
 *          <dd>The output meets the following conditions:
 *               - The result is stored in big-endian byte order in the buffer pointed to by pOutput.
 *      <dt>pOutLength:</dt>
 *          <dd>Length of output in bytes.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_pkcs1v15Decode_decrypt operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK          The function executed successfully.
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT               The function failed due to invalid input parameters.
 * @retval #MCUXCLRSA_STATUS_ERROR                       An error occurred during the execution. In that case, expectations for the flow protection are not balanced.
 *
 * @attention PRNG and PKC have to be initialized prior to calling the function because PRNG and PKC RAM are used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_pkcs1v15Decode_decrypt, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Decode_decrypt(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength
);
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) && defined(MCUXCL_FEATURE_RSA_RSAES_PKCS1v15) */



/**
 * @brief RSA key generation of probable prime number p or q
 *
 * This function performs a generation of probable prime number based on the method specified in the FIPS 186-5, Appendix A.1.3.
 * The provided RNG (through the session) should be initialized (i.e., set the value of security_strength in accordance with
 * the key size as specified in SP 800-57, Part 1 and in SP 800-56B REV. 2, Table 2) before this function call.
 *
 * The main differences in comparison to method specified in the FIPS 186-5, Appendix A.1.3:
 * - Primes p and q are chosen to be congruent 3 mod 4 (this deviation has been approved).
 * - Check preformed in step 4.4 and 5.4 of this method is done using only 64 most significant bits
 *   of sqrt(2)(2^(nlen/2)–1) rounded up, this is 0xb504f333f9de6485 (this deviation has been approved).
 * - The check if |p - q| <= 2^(nlen/2 - 100) (check performed in step 5.5 of the FIPS method) is done after generating
 *   p and q (after checking GCD(q−1, e)). If this FIPS requirement is not met, a new prime q is generated.
 * - The pre-check against products of small primes was added before the Miller-Rabin test.
 *
 * Data Integrity: Expunge(pPrimeCandidate->pKeyEntryData + pPrimeCandidate->keyEntryLength)
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pE                   Pointer to data, which contains public exponent e
 * @param[out] pPrimeCandidate      Pointer to data, which contains the generated probable prime number
 * @param[in]  keyBitLength         Bit-length of key
 * @param[in]  maxIter              maxIter*keyBitLength is the maximum number of iterations to find value for p or q
 *
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of keyBitLength, as specified in SP 800-57, Part 1.
 *      <dt>pE:</dt>
 *          <dd>The public exponent e meets the following conditions:
 *              - The public exponent e shall be FIPS 186-5 compliant;
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - Data in this buffer shall be stored in little-endian byte order;
 *              - The keyEntryLength shall be exact length of e (without leading zeros).
 *      <dt>pPrimeCandidate:</dt>
 *          <dd>Pointer to data, which contains the generated probable prime number. It meets the following conditions:
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - One additional PKC word shall be reserved before pPrimeCandidate->pKeyEntryData for the NDash calculated in the mcuxClRsa_GenerateProbablePrime
 *              - Probable prime number will be stored in little-endian byte order;
 *              - Length of the probable prime number will be keyBitLength/2.
 *      <dt>keyBitLength:</dt>
 *          <dd>Specifies the size of the generated key, it shall be even value.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG (directly and indirectly) which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_GenerateProbablePrime)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_GenerateProbablePrime(
  mcuxClSession_Handle_t           pSession,
  mcuxClRsa_KeyEntry_t *           pE,
  mcuxClRsa_KeyEntry_t *           pPrimeCandidate,
  const uint32_t                  keyBitLength,
  const uint32_t                  maxIter);

/**
 * @brief Test prime candidate for RSA key generation
 *
 * This function performs a test of probable prime number based on the method specified in the FIPS 186-5, Appendix A.1.3.
 *
 * The main differences in comparison to method specified in the FIPS 186-5, Appendix A.1.3:
 * - Primes p and q are chosen to be congruent 3 mod 4 (this deviation has been approved).
 * - Check preformed in step 4.4 and 5.4 of this method is done using only 64 most significant bits
 *   of sqrt(2)(2^(nlen/2)–1) rounded up, this is 0xb504f333f9de6485 (this deviation has been approved).
 * - The check if |p - q| <= 2^(nlen/2 - 100) (check performed in step 5.5 of the FIPS method) is done after generating
 *   p and q (after checking GCD(q−1, e)). If this FIPS requirement is not met, a new prime q is generated.
 * - The pre-check against products of small primes was added before the Miller-Rabin test.
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pE                   Pointer to data, which contains public exponent e
 * @param[out] pProbablePrime       Pointer to data, which contains the generated probable prime number
 * @param[in]  keyBitLength         Bit-length of key
 * @param[in]  numberTestIterations Number of Miller-Rabin test iterations
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of keyBitLength, as specified in SP 800-57, Part 1.
 *      <dt>pE:</dt>
 *          <dd>The public exponent e meets the following conditions:
 *              - The public exponent e shall be FIPS 186-5 compliant;
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - Data in this buffer shall be stored in little-endian byte order;
 *              - The keyEntryLength shall be exact length of e (without leading zeros).
 *      <dt>pProbablePrime:</dt>
 *          <dd>Pointer to data, which contains the generated probable prime number. It meets the following conditions:
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - One additional PKC word shall be reserved before pPrimeCandidate->pKeyEntryData for the NDash calculated in this function;
 *              - Probable prime number will be stored in little-endian byte order;
 *              - Length of the probable prime number will be keyBitLength/2.
 *      <dt>keyBitLength:</dt>
 *          <dd>Specifies the size of the generated key, it shall be even value.
 *      <dt>iNumToCmp_iA0:</dt>
 *          <dd> iNumToCmp: index of the buffer to store 0xb504f333f9de6485, which is 64 most significant bits of sqrt(2)(2^(nlen/2)-1) rounded up.
 *          <br> iA0: index of the buffer to store 0xC0CFD797, which is the product of the first 9 prime numbers starting from 3.
 *      <dt>numberTestIterations:</dt>
 *          <dd>Specifies the number of Miller-Rabin test iterations.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_TestPrimeCandidate operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_CMP_FAILED       prime candidate < sqrt(2)(2^((nlen/2)-1)), only 64 most significant bits are compared.
 * @retval #MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_GCDA0_FAILED     prime candidate is not coprime to A0 - product of the first 9 prime numbers.
 * @retval #MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_GCDE_FAILED      prime candidate - 1 is not coprime to the public exponent e.
 * @retval #MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_MRT_FAILED       The prime candidate did not pass the Miller-Rabin test.
 * @retval #MCUXCLRSA_STATUS_KEYGENERATION_OK                    The prime candidate is probably prime.
 *
 * @attention This function uses DRBG and PRNG (indirectly) which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_TestPrimeCandidate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_TestPrimeCandidate(
  mcuxClSession_Handle_t           pSession,
  mcuxClRsa_KeyEntry_t *           pE,
  mcuxClRsa_KeyEntry_t *           pPrimeCandidate,
  const uint32_t                  keyBitLength,
  const uint32_t                  iNumToCmp_iA0,
  const uint32_t                  numberTestIterations
);

/**
 * @brief RSA Miller-Rabin probabilistic primality test function
 *
 * This function is used to test prime candidate for primality using Miller-Rabin
 * probabilistic primality tests described in FIPS 186-5, Appendices B.3.1.
 *
 * <dt>Assumptions:</dt>
 * Prime candidate is congruent 3 mod 4. Taking this into account, the Miller-Rabin
 * algorithm gets simplified (due to fact that a=1 the step 4.5 is skipped);
 *
 * @param[in]  pSession                Pointer to #mcuxClSession_Descriptor
 * @param[in]  iP_iT                   Pointer table indices of parameters
 * @param[in]  keyBitLength            Bit-length of key
 * @param[in]  numberTestIterations    Number of Miller-Rabin test iterations
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of primeLength, as specified in SP 800-57, Part 1.
 *      <dt>iP_iT:</dt>
 *          <dd> iP: index of prime candidate buffer, of which the size should be at least MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenPrimeCandidate).
 *                   Additionally one PKC word shall be reserved before P for the NDash calculated in mcuxClRsa_MillerRabinTest.
 *                   Prime candidate length shall be keyBitLength/2.
 *          <br> iT: index of temp buffer, of which the size should be at least 9 * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenPrimeCandidate) + 10 * PKC wordsize.
 *      <dt>keyBitLength:</dt>
 *          <dd>Specifies the size of the generated key, it shall be even value.
 *      <dt>numberTestIterations:</dt>
 *          <dd>Specifies the number of Miller-Rabin test iterations.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_MillerRabinTest operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_KEYGENERATION_OK               The prime candidate is probably prime.
 * @retval #MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_MRT_FAILED  The prime candidate did not pass the Miller-Rabin test.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_MillerRabinTest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_MillerRabinTest(
  mcuxClSession_Handle_t           pSession,
  uint32_t                        iP_iT,
  uint32_t                        keyBitLength,
  const uint32_t                  numberTestIterations
);


/**
 * @brief RSA function which computes private exponent d compliant with FIPS 186-5
 *
 * This function is used to compute private exponent d for given p, q and e.
 * The d is calculated as d = e^(–1) mod (LCM(p–1, q–1)),
 * where: LCM(a,b) = (ab)/gcd(a,b).
 *
 * Data Integrity: Expunge(pP->pKeyEntryData + pQ->pKeyEntryData + pD->pKeyEntryData + keyBitLength)
 *
 * @param[in]  pSession             Pointer to #mcuxClSession_Descriptor
 * @param[in]  pE                   Pointer to buffer, which contains public exponent e
 * @param[in]  pP                   Pointer to buffer, which contains prime p
 * @param[in]  pQ                   Pointer to buffer, which contains prime q
 * @param[out] pD                   Pointer to buffer, which contains the computed private exponent d
 * @param[in]  keyBitLength         Bit-length of key
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>pE:</dt>
 *          <dd>The public exponent e meets the following conditions:
 *              - The public exponent e shall be FIPS 186-5 compliant;
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - Data in this buffer shall be stored in little-endian byte order;
 *              - The keyEntryLength shall be exact length of e (without leading zeros).
 *      <dt>pP:</dt>
 *          <dd>The prime p meets the following conditions:
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - Data in this buffer shall be stored in little-endian byte order;
 *              - Prime p length shall be keyBitLength/2.
 *      <dt>pQ:</dt>
 *          <dd>The prime q meets the following conditions:
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *              - Data in this buffer shall be stored in little-endian byte order;
 *              - Prime q length shall be keyBitLength/2.
 *      <dt>pD:</dt>
 *          <dd>The private exponent d meets the following conditions:
 *              - A buffer pointed by pKeyEntryData shall be located in PKC RAM, its address and length shall be aligned to PKC word;
 *                Size of the buffer should be at least keyBitLength/8 + double PKC wordsizes.
 *              - Data in this buffer shall be stored in little-endian byte order;
 *              - The private exponent d length is  not greater than keyBitLength.
 *      <dt>keyBitLength:</dt>
 *          <dd>Specifies the size of the generated key, it shall be even value.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_ComputeD operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_KEYGENERATION_OK            The prime candidate is probably prime.
 * @retval #MCUXCLRSA_STATUS_INTERNAL_PRIVEXP_INVALID    For a given input (it means p, q and e) the computed D does not meet
 *                                                      the requirements specified in the FIPS 186-5, Appendix A.1.1.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_ComputeD)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_ComputeD(
  mcuxClSession_Handle_t           pSession,
  mcuxClRsa_KeyEntry_t *           pE,
  mcuxClRsa_KeyEntry_t *           pP,
  mcuxClRsa_KeyEntry_t *           pQ,
  mcuxClRsa_KeyEntry_t *           pD,
  const uint32_t                  keyBitLength
);

/**
 * @brief RSA function which tests if |p–q| <= 2^(nlen/2–100).
 *
 * This function is used to test if |p–q| <= 2^(nlen/2–100).
 * This is a verification required by FIPS 186-5 (Appendix A.1.3, step 5.5).
 *
 * @param[in]  iP_iQ_iT1          Pointer table indices of parameters
 * @param[in]  primeByteLength    Bytelength of parameters p and q
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>iP_iQ_iT1:</dt>
 *          <dd> iP: index of p prime buffer. The size shall be a multiple of PKC word and at least primeByteLength.
 *          <br> iQ: index of q prime buffer. The size shall be a multiple of PKC word and at least primeByteLength.
 *          <br> iT: index of temporary buffer. The size shall be at least 3 * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(16).
 *      <dt>primeByteLength:</dt>
 *          <dd>The length of primes p and q. It must be a multiple of the PKC word.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_TestPQDistance operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_KEYGENERATION_OK     The p and q primes meet the FIPS requirements.
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT        The p and q primes do not meet the FIPS requirements.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_TestPQDistance)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_TestPQDistance(uint32_t iP_iQ_iT, uint32_t primeByteLength);


/**
 * @brief RSA function which calculates modular inversion, X^(-1) mod N in a blinded way
 *
 * Data Integrity: Expunge(pR), where pR is the pointer corresponding to the index of PKC operand iR
 *
 * @param[in]  pSession       pointer to #mcuxClSession_Descriptor
 * @param[in] iR_iX_iNb_iRnd  indices of PKC operands
 * @param[in] iT1_iT0         indices of PKC operands
 * @param[in] lenX            byte length of X
 * @param[in] lenNb           byte length of blinded N
 *
 * <dt>Assumptions:</dt>
 *  - If X and N are not coprime, the result will be incorrect
 *  - N is congruent 2 mod 4
 *  - size of Rnd = MCUXCLRSA_PKC_WORDSIZE
 *  - Nb = N * Rnd
 *  - lenX <= lenNb - MCUXCLRSA_PKC_WORDSIZE
 *  - The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>iR_iX_iNb_iRnd:</dt>
 *          <dd> iR: index of result buffer. The size shall be at least (lenNb + PKC wordsize).
 *          <br> iX: index of X buffer, The size shall be at least (lenNb + PKC wordsize).
 *                   X will be destroyed by this function.
 *          <br> iNb: index of buffer for blinded N. The size shall be at least (lenNb + PKC wordsize).
 *                   Nb will be destroyed by this function.
 *          <br> iRnd: index of buffer for random data. The size shall be PKC wordsize.
 *      <dt>iT1_iT0:</dt>
 *          <dd> indices of temporary buffers. The size shall be at least (lenNb + PKC wordsize).
 *      <dt>lenX:</dt>
 *          <dd>The length of X. It must be a multiple of the PKC wordsize and not bigger than (lenNb - MCUXCLRSA_PKC_WORDSIZE).
 *      <dt>lenNb:</dt>
 *          <dd>The length of Nb. It must be a multiple of the PKC wordsize.
 *  </dl></dd>
 * </dl>
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_ModInv)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_ModInv(mcuxClSession_Handle_t pSession, uint32_t iR_iX_iNb_iRnd, uint32_t iT1_iT0, uint32_t lenX, uint32_t lenNb);

/**
 * @brief RSA function which verifies whether RSA public exponent is FIPS compliant (i.e., is odd value
 *  in the range 2^16 < e < 2^256) and determines its length without leading zeros.
 *
 * @param[in]  pSession       Pointer to #mcuxClSession_Descriptor
 * @param[in]  pE             Pointer to RSA key entry for the public exponent e
 * @param[out] exactLength    Pointer to data where the exact length of public exponent e will be set
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pE:</dt>
 *          <dd>The public exponent e in a big endian order
 *      <dt>exactLength:</dt>
 *          <dd>Exact length of public exponent e
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_VerifyE)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_VerifyE(mcuxClSession_Handle_t pSession, mcuxClRsa_KeyEntry_t *pE, uint32_t *exactLength);

/**
 * @brief RSA function which returns the minimum number of Miller-Rabin test iterations for given
 * prime bit length and error probability lower than 2^(-125).
 *
 * The number of Miller-Rabin test iterations are determined for the prime lengths of 512, 1024, 1536, 2048,
 * 3072, 4096 bits based on Table 1 of SOGIS Agreed Cryptographic Mechanisms version 1.2 (it is following
 * the Appendix C.1 of FIPS PUB 186-5).
 *
 * @param[in]  primeBitLength   The prime bit length
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>primeBitLength:</dt>
 *          <dd>The prime bit length
 *  </dl></dd>
 * </dl>
 *
 * @return Minimum number of Miller-Rabin test iterations for given prime bit length.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_getMillerRabinTestIterations)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClRsa_getMillerRabinTestIterations(const uint32_t primeBitLength);

/**
 * @brief RSA key-pair generation function.
 *
 * This function can be used to perform an RSA key-pair generation operation.
 *
 * Note: the key handles @p privKey and @p pubKey must already be initialized
 * and contain a proper key type (matching to the @p generation algorithm),
 * protection mechanism and enough space for key data buffers.
 *
 * This function supports the generation of the following key sizes: 1k, 2k, 3k, 4k, 6k, 8k.
 *
 * The two key handles are linked with each other using mcuxClKey_linkKeyPair.
 *
 * @param         pSession     Handle for the current CL session.
 * @param         generation   RSA Key generation algorithm that determines the key
 *                             data stored in @p privKey and @p pubKey.
 * @param[in/out] privKey      Key handle for the private key (word-aligned).
 * @param[in/out] pubKey       Key handle for the public key (word-aligned).
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyGeneration_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyGeneration_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey);


/**
 * @brief Environment initialization for RSA key generation
 *
 * This function checks the entropy provided by the RNG and if E is FIPS compliant.
 * It also determines the length of E without leading zeros.
 * After that the function checks whether the public key data container has enough space.
 *
 * @param[in]      pSession              Pointer to #mcuxClSession_Descriptor
 * @param[in]      pubKey                Key handle for the generated public key (word-aligned)
 * @param[in]      generation            RSA Key generation algorithm that determines the key
 *                                       data stored in @p pubKey.
 * @param[out]     pByteLenE             Pointer to data were the exact length of public exponent e will be set
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of bitLenKey, as specified in SP 800-57, Part 1.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_KeyGeneration_Init_Common)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_Util_KeyGeneration_Init_Common(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Handle_t pubKey,
  mcuxClKey_Generation_t generation,
  uint32_t *pByteLenE);


/**
 * @brief This function calls mcuxClRsa_Util_KeyGeneration_Init_Common in order to initialize RSA key generation.
 * After that the function checks whether the private key data container in CRT or CRT-DFA format has enough space.
 *
 * @param[in]      pSession              Pointer to #mcuxClSession_Descriptor
 * @param[in]      pubKey                Key handle for the generated public key (word-aligned)
 * @param[in]      generation            RSA Key generation algorithm that determines the key
 *                                       data stored in @p privKey and @p pubKey.
 * @param[out]     pbyteLenE             Pointer to data were the exact length of public exponent e will be set
 * @param[in]      privKey               Key handle for the generated private key (word-aligned)
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of type.size, as specified in SP 800-57, Part 1.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_KeyGeneration_Init_CrtKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_Util_KeyGeneration_Init_CrtKey(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Handle_t pubKey,
  mcuxClKey_Generation_t generation,
  uint32_t * pByteLenE,
  mcuxClKey_Handle_t privKey);


/**
 * @brief This function calls mcuxClRsa_Util_KeyGeneration_Init_Common in order to initialize RSA key generation.
 * After that the function checks whether the private key data container in plain format has enough space.
 *
 * @param[in]      pSession              Pointer to #mcuxClSession_Descriptor
 * @param[in]      pubKey                Key handle for the generated public key (word-aligned)
 * @param[in]      generation            RSA Key generation algorithm that determines the key
 *                                       data stored in @p privKey and @p pubKey.
 * @param[out]     pbyteLenE             Pointer to data were the exact length of public exponent e will be set
 * @param[in]      privKey               Key handle for the generated private key (word-aligned)
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of type.size, as specified in SP 800-57, Part 1.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_KeyGeneration_Init_PlainKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_Util_KeyGeneration_Init_PlainKey(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Handle_t pubKey,
  mcuxClKey_Generation_t generation,
  uint32_t * pByteLenE,
  mcuxClKey_Handle_t privKey);


/**
 * @brief This function verifies the correctness of a private key.
 *
 * This function verifies the correctness of a private key based on its type and
 * the state of security option MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_ENABLE.
 * If MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_ENABLE is set, the function calls appropriate verification function
 * to verify private key in CRT format, CRT-DFA format or plain format.
 * If MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_ENABLE is not set, the PKC WA at pPkcWorkarea will be cleared.

 * In case the key is correct or the security option is not set, the function returns to the caller.
 * Otherwise the function clears the exported private key data and exits through SESSION_FAULT.
 *
 * Data Integrity: Expunge(pSession->securityOptions & MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_MASK)
 *
 * @param[in] pSession         Pointer to #mcuxClSession_Descriptor
 * @param[in] privKey          Key handle for the generated private key (word-aligned)
 * @param[in] pubKey           Key handle for the generated public key (word-aligned)
 * @param[in] pPublicExponent  Pointer to RSA key entry for the public exponent e, used only for keys in CRT format
 * @param[in] pPkcWorkarea     Pointer to PKC WA (word-aligned) to be cleared, used only if key verification is disabled.
 *
 * @post
 *  - PKC WA used in the calling function will be overwritten if key verification is enabled, and cleared if it is disabled.
 *  - PS1 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - UPTR table entry 0 of the calling function will be modified by this function, and will not be restored.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_VerifyKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_VerifyKey(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey,
    mcuxClRsa_KeyEntry_t * pPublicExponent,
    uint8_t * pPkcWorkarea);


/**
 * @brief Generates an RSA key in CRT format
 *
 * This function for given public exponent and key size generates an RSA private key
 * in CRT representation (p, q, dp, dq, qInv) and computes the modulus n.
 *
 * Primes p and q are generated based on the method specified in the FIPS 186-5, Appendix A.1.3 using probabilistic
 * primality test with the probability of not being prime less than 2^(-125).
 * The public exponent is restricted to (FIPS compliant) odd values in the range 2^16 < e < 2^256 (i.e. including 0x10001).
 * The bit-length of the key size is limited to 2048, 3072 and 4096.
 * The keys generated by this function are FIPS 186-5 compliant provided their length is greater than or equal to 2048 bits
 * and the exponent value is an odd integer between 2^16 and 2^256.
 *
 * The two key handles are linked with each other using mcuxClKey_linkKeyPair.
 *
 * Data Integrity: Expunge(pSession->securityOptions & MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_MASK)
 *
 * @param[in]      pSession              Pointer to #mcuxClSession_Descriptor
 * @param[in]      generation            RSA Key generation algorithm that determines the key
 *                                       data stored in @p privKey and @p pubKey.
 * @param[in/out]  privKey               Key handle for the generated private key (word-aligned)
 * @param[in/out]  pubKey                Key handle for the generated public key (word-aligned)
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of type.size, as specified in SP 800-57, Part 1.
 *      <dt>generation:</dt>
 *          <dd>RSA Key generation algorithm that determines the key data stored in @p privKey and @p pubKey.
 *      <dt>privKey:</dt>
 *          <dd>Key handle for the generated private key.
 *      <dt>pubKey:</dt>
 *          <dd>Key handle for the generated public key.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_KeyGeneration_Crt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_Util_KeyGeneration_Crt(
   mcuxClSession_Handle_t pSession,
   mcuxClKey_Generation_t generation,
   mcuxClKey_Handle_t privKey,
   mcuxClKey_Handle_t pubKey
 );


/**
 * @brief RSA key generation of private plain key operation.
 *
 * This function for given public exponent and key size generates RSA private key in in plain from (d, n).
 *
 * Private exponent d is computed with the requirements specified in the FIPS 186-5, Appendix A.1.1.
 * Primes p and q are generated based on the method specified in the FIPS 186-5, Appendix A.1.3 using probabilistic
 * primality test with the probability of not being prime less than 2^(-125).
 * The public exponent is restricted to (FIPS compliant) odd values in the range 2^16 < e < 2^256 (i.e. including 0x10001).
 * The bit-length of the key size is limited to 2048, 3072 and 4096.
 * The keys generated by this function are FIPS 186-5 compliant provided their length is either 2048 or 3072 bits
 * and the exponent value is an odd integer between 2^16 and 2^256.
 *
 * The two key handles are linked with each other using mcuxClKey_linkKeyPair.
 *
 * Data Integrity: Expunge(pSession->securityOptions & MCUXCLSESSION_SECURITYOPTIONS_VERIFY_GENERATED_KEY_MASK)
 *
 * @param[in]      pSession              Pointer to #mcuxClSession_Descriptor
 * @param[in]      generation            RSA Key generation algorithm that determines the key
 *                                       data stored in @p privKey and @p pubKey.
 * @param[in/out]  privKey               Key handle for the generated private key (word-aligned)
 * @param[in/out]  pubKey                Key handle for the generated public key (word-aligned)
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function. The RNG shall be initialized
 *              with the entropy level (security strength) in accordance with the value of type.size, as specified in SP 800-57, Part 1.
 *      <dt>generation:</dt>
 *          <dd>RSA Key generation algorithm that determines the key data stored in @p privKey and @p pubKey.
 *      <dt>privKey:</dt>
 *          <dd>Key handle for the generated private key.
 *      <dt>pubKey:</dt>
 *          <dd>Key handle for the generated public key.
 *  </dl></dd>
 * </dl>
 *
 * @return void
 *
 * @note
 *    Other errors are returned through session parameter.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_KeyGeneration_Plain)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_Util_KeyGeneration_Plain(
   mcuxClSession_Handle_t pSession,
   mcuxClKey_Generation_t generation,
   mcuxClKey_Handle_t privKey,
   mcuxClKey_Handle_t pubKey
 );


/**
 * @brief RSA sign operation
 *
 * This function performs an RSA signature generation according to RSASSA-PSS-SIGN or RSASSA-PKCS1-v1_5-SIGN
 * of PKCS #1 v2.2. Based on the passed key type, it is selected, whether to perform this operation using a private
 * plain, a private CRT key, or whether to use a private CRT key and protect the operation against perturbation attacks.
 * Based on the selection of the padding mode, it is determined, whether to perform one of the supported paddings based
 * on one of the supported hash functions.
 *
 * @param[in]  pSession                  Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key (word-aligned)
 * @param[in]  mode                      Signature mode descriptor
 * @param[in]  pMessageOrDigest          Pointer to buffer, which contains the input to the sign operation
 * @param[in]  messageLength             RFU
 * @param[out] pSignature                Pointer to buffer, which contains the result (signature)
 * @param[out] pSignatureSize            Size of the signature
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key handle should be properly set up before calling the RSA function.
 *              The following bit-lengths of the modulus are supported: 1024, 2048, 3072, 4096, 6144 and 8192.
 *      <dt>mode:</dt>
 *          <dd>The mode should be properly set up before calling the RSA function, and contain a pointer to a valid protocol descriptor.
 *      <dt>pMessageOrDigest:</dt>
 *          <dd>This should be a pointer to a message digest.
 *      <dt>messageLength:</dt>
 *          <dd>RFU: This is currently not used by RSA sign.
 *      <dt>pSignature:</dt>
 *          <dd>The output is returned in in big-endian byte order.
 *      <dt>pSignatureSize:</dt>
 *          <dd>This is always equal to the modulus byte length.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_Util_sign operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_SIGN_OK                             Sign operation executed successfully.
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT                       The input parameters are not valid.
 * @retval #MCUXCLRSA_STATUS_ERROR                               An error occurred during the execution. In that case, expectations for the flow protection are not balanced.
 *
 * @attention This function uses DRBG (for PSS encoding only) and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_sign, mcuxClSignature_SignFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClRsa_Util_sign(
  mcuxClSession_Handle_t           pSession,
  mcuxClKey_Handle_t               key,
  mcuxClSignature_Mode_t           mode,
  mcuxCl_InputBuffer_t             pMessageOrDigest,
  uint32_t                        messageLength,
  mcuxCl_Buffer_t                  pSignature,
  uint32_t * const                pSignatureSize
);

/**
 * @brief RSA verify operation
 *
 * This function performs an RSA signature verification according to RSASSA-PSS-VERIFY or RSASSA-PKCS1-v1_5-VERIFY
 * of PKCS #1 v2.2. Based on the selection of the padding mode, it is determined, whether to perform one of the supported
 * padding verifications based on one of the supported hash functions.
 *
 * @param[in]  pSession                  Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key (word-aligned)
 * @param[in]  mode                      Signature mode descriptor
 * @param[in]  pMessageOrDigest          Pointer to buffer, which contains the input to the verify operation
 * @param[in]  messageLength             RFU
 * @param[in]  pSignature                Pointer to buffer, which contains the signature
 * @param[out] signatureSize             RFU
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key handle should be properly set up before calling the RSA function.
 *              The following bit-lengths of the modulus are supported: 1024, 2048, 3072, 4096, 6144 and 8192.
 *      <dt>mode:</dt>
 *          <dd>The mode should be properly set up before calling the RSA function, and contain a pointer to a valid protocol descriptor.
 *      <dt>pMessageOrDigest:</dt>
 *          <dd>This should be a pointer to a message digest.
 *      <dt>messageLength:</dt>
 *          <dd>RFU: This is currently not used by RSA signature verification.
 *      <dt>pSignature:</dt>
 *          <dd>Input signature that will be verified. The signature length is determined by the modulus length (bytelength(n))
 *      <dt>signatureSize:</dt>
 *          <dd>RFU: This is currently not used by RSA signature verification.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_Util_verify operation (see @ref MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t))
 * @retval #MCUXCLRSA_STATUS_VERIFY_OK                           Verify operation executed successfully.
 * @retval #MCUXCLRSA_STATUS_VERIFY_FAILED                       The signature verification failed.
 *
 * @note
 *    Other errors are returned through session parameter.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_verify, mcuxClSignature_VerifyFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClRsa_Util_verify(
  mcuxClSession_Handle_t           pSession,
  mcuxClKey_Handle_t               key,
  mcuxClSignature_Mode_t           mode,
  mcuxCl_InputBuffer_t             pMessageOrDigest,
  uint32_t                        messageLength,
  mcuxCl_InputBuffer_t             pSignature,
  uint32_t                        signatureSize
);

#ifdef MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT
/**
 * @brief RSA Encrypt operation
 *
 * This function performs an RSA encryption according to RSAES-OAEP-ENCRYPT or RSAES-PKCS1-V1_5-ENCRYPT of PKCS #1 v2.2.
 * Based on the selection of the padding mode and hash function, one of the supported encoding operations is performed.
 *
 * @param[in]  pSession                  Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key (word-aligned)
 * @param[in]  mode                      Cipher mode descriptor
 * @param[in]  pLabel                    Pointer to the label.
 * @param[in]  labelLength               Byte length of the label.
 * @param[in]  pIn                       Pointer to the input buffer that contains the plain data that needs to be encrypted.
 * @param[in]  inLength                  Number of bytes of plain data in the pIn buffer.
 * @param[in]  pOut                      Pointer to the output buffer where the encrypted data needs to be written.
 * @param[out] pOutLength                Will contain the number of bytes of encrypted data that have been written to the pOut buffer.
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key handle should be properly set up before calling the RSA function.
 *              The following bit-lengths of the modulus are supported: 1024, 2048, 3072, 4096, 6144 and 8192.
 *      <dt>mode:</dt>
 *          <dd>The mode should be properly set up before calling the RSA function, and contain a pointer to a valid protocol descriptor.
 *      <dt>pLabel:</dt>
 *          <dd>The label is used only used for OAEP encoding.
 *      <dt>inLength:</dt>
 *          <dd>The input length should be compliant with the limitations of the selected encoding mode (PKCS#1v1.5 or OAEP)
 *      <dt>pOutLength:</dt>
 *          <dd>Always equal to the modulus byte length.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_Util_encrypt operation.
 * The return codes should match those of @ref mcuxClCipher
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_encrypt, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClRsa_Util_encrypt(
    mcuxClSession_Handle_t           pSession,
    mcuxClKey_Handle_t               key,
    mcuxClCipher_Mode_t              mode,
    mcuxCl_InputBuffer_t             pLabel,
    uint32_t                        labelLength,
    mcuxCl_InputBuffer_t             pIn,
    uint32_t                        inLength,
    mcuxCl_Buffer_t                  pOut,
    uint32_t * const                pOutLength
);
#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT */

#ifdef MCUXCL_FEATURE_CIPHER_RSA_DECRYPT
/**
 * @brief RSA Decrypt operation
 *
 * This function performs an RSA decryption according to RSAES-OAEP-DECRYPT or RSAES-PKCS1-V1_5-DECRYPT of PKCS #1 v2.2.
 * Based on the selection of the padding mode and hash function, one of the supported decoding operations is performed.
 *
 * @param[in]  pSession                  Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key (word-aligned)
 * @param[in]  mode                      Cipher mode descriptor
 * @param[in]  pLabel                    Pointer to the label.
 * @param[in]  labelLength               Byte length of the label.
 * @param[in]  pIn                       Pointer to the input buffer that contains the encrypted data that needs to be decrypted.
 * @param[in]  inLength                  RFU
 * @param[in]  pOut                      Pointer to the output buffer where the plain data needs to be written.
 * @param[out] pOutLength                Will contain the number of bytes of encrypted data that have been written to the pOut buffer.
 *
 *  <dd><dl>
 *      <dt>pSession:</dt>
 *          <dd>The session pointed to by pSession has to be initialized prior to a call to this function.
 *      <dt>key:</dt>
 *          <dd>The key handle should be properly set up before calling the RSA function.
 *              The following bit-lengths of the modulus are supported: 1024, 2048, 3072, 4096, 6144 and 8192.
 *      <dt>mode:</dt>
 *          <dd>The mode should be properly set up before calling the RSA function, and contain a pointer to a valid protocol descriptor.
 *      <dt>pLabel:</dt>
 *          <dd>The label is used only used for OAEP encoding.
 *      <dt>inLength:</dt>
 *          <dd>RFU: Number of bytes of encrypted data in the pIn buffer. For RSA this is ignored, and it is considered that this
 *              is always equal to the modulus byte length.
 *  </dl></dd>
 * </dl>
 *
 * @return Status of the mcuxClRsa_Util_decrypt operation.
 * The return codes should match those of @ref mcuxClCipher
 *
 * @attention This function uses PRNG which has to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Util_decrypt, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClRsa_Util_decrypt(
    mcuxClSession_Handle_t           pSession,
    mcuxClKey_Handle_t               key,
    mcuxClCipher_Mode_t              mode,
    mcuxCl_InputBuffer_t             pLabel,
    uint32_t                        labelLength,
    mcuxCl_InputBuffer_t             pIn,
    uint32_t                        inLength,
    mcuxCl_Buffer_t                  pOut,
    uint32_t * const                pOutLength
);
#endif /* MCUXCL_FEATURE_CIPHER_RSA_DECRYPT  */


/**
 * @brief Key load function with plain encoding, for RSA keys in plain format.
 * It loads a single key element, depending on the input specification: the modulus,
 * or the private exponent.
 * Note that the public exponent is never loaded into internal memory, but directly read
 * word-wise from the key data.
 *
 * Data Integrity: Expunge(key + ppDest + (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Handle to the key to be loaded (word-aligned)
 * @param[out]  ppDest   Pointer-pointer to the destination key location
 * @param[in]   pKeyChecksums  Storing data needed for key checksum generation
 * @param[in]   spec     Specification of the load operation
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyLoad_PlainKey_Plain, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyLoad_PlainKey_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint8_t **ppDest,
  mcuxClKey_KeyChecksum_t * pKeyChecksums,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Key store function with plain encoding, for RSA private plain keys.
 * It stores all key elements.
 *
 * Data Integrity: Expunge(key)
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Key handle that provides information to store the key (word-aligned)
 * @param[in]   pSrc     Pointer to the source key location
 * @param[in]   spec     Specifications about the used key
 *
 * @pre
 * - pSrc must be set up by the caller to contain a struct mcuxClRsa_KeyData_Plain_t, that provides pointers and lengths
 *   for the private key elements in PKC RAM.
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyStore_PrivPlainKey_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyStore_PrivPlainKey_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t *pSrc,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Key store function with plain encoding, for RSA public keys.
 * It stores all key elements.
 *
 * Data Integrity: Expunge(key)
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Key handle that provides information to store the key (word-aligned)
 * @param[in]   pSrc     Pointer to the source key location
 * @param[in]   spec     Specifications about the used key
 *
 * @pre
 * - pSrc must be set up by the caller to contain a struct mcuxClRsa_KeyData_Plain_t, that provides pointers and lengths
 *   for the public key elements in PKC RAM.
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyStore_PublicKey_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyStore_PublicKey_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t *pSrc,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Key load function with plain encoding, for RSA keys in CRT format.
 * It loads a single key element, depending on the input specification: p, q,
 * dp, dq or qInv.
 * Note that the public exponent is never loaded into internal memory, but directly read
 * word-wise from the key data.
 *
 * Data Integrity: Expunge(key + ppDest + (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Handle to the key to be loaded (word-aligned)
 * @param[out]  ppDest   Pointer-pointer to the destination key location
 * @param[in]   pKeyChecksums  Storing data needed for key checksum generation
 * @param[in]   spec     Specification of the load operation
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyLoad_CrtKey_Plain, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyLoad_CrtKey_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint8_t **ppDest,
  mcuxClKey_KeyChecksum_t * pKeyChecksums,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Key store function with plain encoding, for RSA private CRT keys.
 * It stores all key elements, including: p, q, dp, dq or qInv.
 *
 * Data Integrity: Expunge(key)
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Key handle that provides information to store the key (word-aligned)
 * @param[in]   pSrc     Pointer to the source key location
 * @param[in]   spec     Specifications about the used key
 *
 * @pre
 * - pSrc must be set up by the caller to contain a struct mcuxClRsa_KeyData_Crt_t, that provides pointers and lengths
 *   for the private key elements in PKC RAM.
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyStore_PrivCrtKey_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyStore_PrivCrtKey_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t *pSrc,
  mcuxClKey_Encoding_Spec_t spec
);
/**
 * @}
 */ /* mcuxClRsa_Internal_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_INTERNAL_FUNCTIONS_H_ */

