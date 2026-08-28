/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClEcc_Functions.h
 * @brief Top level APIs of mcuxClEcc component
 */


#ifndef MCUXCLECC_FUNCTIONS_H_
#define MCUXCLECC_FUNCTIONS_H_


#include <mcuxClCore_Platform.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClSignature.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClEcc_Types.h>

#include <mcuxClKey.h>


#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Public APIs of mcuxClEcc                                */
/**********************************************************/
/**
 * @defgroup mcuxClEcc_Functions mcuxClEcc_Functions
 * @brief Defines all functions of @ref mcuxClEcc
 * @ingroup mcuxClEcc
 * @{
 */

#ifdef MCUXCL_FEATURE_ECC_EDDSA
/**
 * @brief This function initializes an EdDSA mode descriptor for EdDSA key pair generation with private key input.
 *
 * @param[in]     pSession              Handle for the current CL session
 * @param[in/out] generationMode        Pointer to mode descriptor to be initialized for EdDSA key pair generation with private key input
 * @param[in]     pPrivKey              Pointer to private key input
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK           EdDSA mode descriptor has been initialized successfully
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK fault attack (unexpected behavior) is detected
 * 
 * \implements{REQ_788267}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_InitPrivKeyInputMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_InitPrivKeyInputMode(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_GenerationDescriptor_t *generationMode,
    const uint8_t *pPrivKey
    );

/**
 * @brief This function implements the signature mode descriptor generation for Ed25519ctx, Ed25519ph, Ed448 and Ed448ph
 *
 * @param[in]  pSession             Handle for the current CL session
 * @param[in]  pDomainParams        Pointer to domain parameters of the used curve
 * @param[in]  pSignatureMode       Mode descriptor specifying the EdDSA variant
 * @param[in]  phflag               Option whether pre-hashing is enabled
 * @param[in]  pContext             User input context for the hash prefix
 * @param[in]  contextLen           Length of the context
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK                EdDSA signature mode descriptor generated successfully
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK      fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_GenerateSignatureModeDescriptor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_GenerateSignatureModeDescriptor(
                                                    mcuxClSession_Handle_t pSession,
                                                    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
                                                    mcuxClSignature_ModeDescriptor_t *pSignatureMode,
                                                    uint32_t phflag,
                                                    mcuxCl_InputBuffer_t pContext,
                                                    uint32_t contextLen);

#endif /* MCUXCL_FEATURE_ECC_EDDSA */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION
/**
 * @brief Function to perform ECC arithmetic operations.
 *
 * From given input operands op1 and op2, this function calculates the result of an ECC arithmetic operation
 * specified by an arithmetic operation specifier passed to the function.
 *
 * For more details regarding the function parameters and return codes, please refer to the definition of the
 * used arithmetic operation type passed via arithmeticOperation.
 *
 * @param[in]  pSession             Handle for the current CL session.
 * @param[in]  arithmeticOperation  arithmetic operand type.
 * @param[in]  pDomainParams        pointer to domain parameters of the used curve.
 * @param[in]  pOp1                 first operand op1.
 * @param[in]  inSize               Number of bytes of data in the \p pOp1 buffer.
 * @param[in]  pOp2                 second operand op2.
 * @param[in]  inSize               Number of bytes of data in the \p pOp2 buffer.
 * @param[out] pResult              result buffer.
 * @param[out] pResultSize          Pointer to CPU word which will be incremented by the number of bytes of data
 *                                  that have been written to the \p pResult buffer.
 *
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK              if the operation finished successfully.
 * @retval #MCUXCLECC_STATUS_INVALID_PARAMS  if the input parameters are invalid.
 * @retval #MCUXCLECC_STATUS_NEUTRAL_POINT   if the result is the neutral point.
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK    if a fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ArithmeticOperation)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithmeticOperation(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_ArithmeticOperation_t arithmeticOperation,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize
    );
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION */


/**
 * @brief ECC Weierstrass custom domain parameter generation function.
 *
 * Given pointers and lengths specifying domain parameters of a custom (short) Weierstrass curve with cofactor 1,
 * this function generates a corresponding optimized custom domain parameter struct.
 *
 * @param      pSession                  Handle for the current CL session.
 * @param[out] pEccWeierDomainParams  Pointer to memory area in which the optimized domain parameters shall be stored.
 * @param[in]  pEccWeierBasicDomainParams      Pointer to struct containing pointers and lengths specifying the custom domain parameters.
 * @param[in]  options                   Parameter specifying whether or not the pre-computed point (2 ^ (byteLenN * 4)) * G corresponding to
 *                                       the base point G shall be calculated or not, If set to
 *                                         - MCUXCLECC_OPTION_GENERATEPRECPOINT_YES, the pre-computed point will be calculated
 *                                         - MCUXCLECC_OPTION_GENERATEPRECPOINT_NO,  the pre-computed point will not be calculated
 *
 * @attention the generated optimized domain parameter cannot be copied or moved,
 *            but shall be used in the original memory address where it is generated.
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK              if optimized domain parameters are generated successfully;
 * @retval #MCUXCLECC_STATUS_INVALID_PARAMS  if parameters are invalid;
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK    if fault attack (unexpected behavior) is detected.
 * 
 * \implements{REQ_788275,REQ_788279,REQ_788273,REQ_788282}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_GenerateDomainParams)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_GenerateDomainParams(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxClEcc_Weier_BasicDomainParams_t *pEccWeierBasicDomainParams,
    uint32_t options
    );

/**
 * @brief Key type constructor.
 * @api
 *
 * This function allows to generate custom key types according to the passed \p algoId.
 *
 * @param[out] customType     Handle for the custom key type.
 * @param[in]  algoId         Algorithm identifier specifying the key type descriptor to be generated. The supported algoIds are
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM | MCUXCLKEY_ALGO_ID_PUBLIC_KEY
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM | MCUXCLKEY_ALGO_ID_PRIVATE_KEY
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM | MCUXCLKEY_ALGO_ID_KEY_PAIR
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM | MCUXCLKEY_ALGO_ID_PUBLIC_KEY
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM | MCUXCLKEY_ALGO_ID_PRIVATE_KEY
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM | MCUXCLKEY_ALGO_ID_KEY_PAIR
 *                            All other values will trigger an error.
 * @param[in]  size           Algorithm based key size.
 * @param[in]  pCustomParams  Pointer to algorithm based custom parameters. If algoId & MCUXCLKEY_ALGO_ID_ALGO_MASK equals
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM, a pointer to an mcuxClEcc_Weier_BasicDomainParams_t struct
 *                                                                                 specifying custom ECC Weierstrass domain parameters
 *                             - MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM, a pointer to an mcuxClEcc_Weier_DomainParams_t struct
 *                                                                              specifying optimized custom ECC Weierstrass domain parameters
 *                            In all other cases, the pointer shall be set to NULL
 * @param[in]  plainEncoding  The plain encoding function for the key.
 * @return status
 * @retval #MCUXCLECC_STATUS_OK              if custom key type is generated successfully;
 * @retval #MCUXCLECC_STATUS_INVALID_PARAMS  if Parameters are invalid.
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK    if fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_GenerateCustomKeyType)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_GenerateCustomKeyType(
    mcuxClKey_CustomType_t customType,
    mcuxClKey_AlgorithmId_t algoId,
    mcuxClKey_Size_t size,
    void *pCustomParams,
    mcuxClKey_Encoding_t plainEncoding
    );


/**
 * @brief Point decoding function.
 * @api
 *
 * Given a point on a short Weierstrass curve defined over the prime p in encoded form, this decoding function derives its plain format
 * given by its x- and y-coordinates.
 *
 * The following encoding variants are supported:
 *  - SEC encoding according to SEC 1: Elliptic Curve Cryptography
 *
 * For each encoding variant dedicated point encoding type descriptors and buffer for the encoded points are available. Please refer
 * to the definition of these descriptors for further information about the respective encoding.
 *
 * @param      pSession                 Handle for the current CL session.
 * @param[in]  pEncodedPoint            Pointer to buffer containing the encoded point. The size of the buffer depends on the encoding variant.
 * @param[out] pDecodedPoint            Pointer to buffer to where the x- and y-coordinates, both elements of GF(p), of the decoded point (x,y)
 *                                      shall be written. The coordinates x and y are written one after another in big endian format with byte length
 *                                      equal to the byte length of p. If #MCUXCLECC_STATUS_NEUTRAL_POINT is returned, nothing is written to this buffer.
 * @param[in]  pointEncType             Point encoding type specifying all information needed about the applied point encoding format.
 * @param[in]  pEccWeierDomainParams    Pointer to short Weierstrass curve custom parameters.
 *
 * @return status
 * @retval #MCUXCLECC_STATUS_OK              if the point decoding was successful;
 * @retval #MCUXCLECC_STATUS_NEUTRAL_POINT   if the encoded point is the neutral point;
 * @retval #MCUXCLECC_STATUS_INVALID_PARAMS  if Parameters are invalid.
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK    if fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_DecodePoint)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_DecodePoint(
    mcuxClSession_Handle_t pSession,
    mcuxCl_InputBuffer_t pEncodedPoint,
    mcuxCl_Buffer_t pDecodedPoint,
    mcuxClEcc_WeierECC_PointEncType_t pointEncType,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams
    );


/**
 * @}
 */ /* mcuxClEcc_Functions */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_FUNCTIONS_H_ */
