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
 * @file  mcuxClEcc_Weier_Internal.h
 * @brief internal header for short Weierstrass curves
 */


#ifndef MCUXCLECC_WEIER_INTERNAL_H_
#define MCUXCLECC_WEIER_INTERNAL_H_


#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClMemory.h>
#include <mcuxClKey_Types.h>
#include <mcuxClMac.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxClEcc_Types.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_FeatureConfig.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Domain parameter structure for ECC functions based on Weierstrass functions.
 */
struct mcuxClEcc_Weier_DomainParams
{
    mcuxClEcc_CommonDomainParams_t common;  ///< structure containing pointers and lengths for common ECC parameters (see Common ECC Domain parameters)
};

/**
 * @brief Common scalar multiplication functions for Weierstrass curves
*/
extern const mcuxClEcc_ScalarMultFunctions_t mcuxClEcc_Weier_ScalarMultFunctions;


/**********************************************************/
/* Helper macros of import/export with flow protection    */
/**********************************************************/

/** Helper macro to call #mcuxClMemory_copy for importing data to PKC workarea with flow protection. */
#define MCUXCLECC_FP_IMPORT_TO_PKC_BUFFER(pOffsetTable, iTarget, pSource, byteLen)  \
    MCUXCLECC_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR((pOffsetTable)[iTarget]), pSource, byteLen)

#define MCUXCLECC_FP_CALLED_MEMORY_COPY  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
#define MCUXCLECC_FP_CALLED_IMPORT_TO_PKC_BUFFER  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)


/**********************************************************/
/* Macros for custom domain parameter generation          */
/**********************************************************/

#define MCUXCLECC_CUSTOMPARAMS_OFFSET_PFULL                   (0u)
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_NFULL(byteLenP)         ((byteLenP) + MCUXCLPKC_WORDSIZE)
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_R2P(byteLenP, byteLenN) (MCUXCLECC_CUSTOMPARAMS_OFFSET_NFULL(byteLenP) + (byteLenN) + MCUXCLPKC_WORDSIZE)
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_R2N(byteLenP, byteLenN) (MCUXCLECC_CUSTOMPARAMS_OFFSET_R2P(byteLenP, byteLenN) + (byteLenP))
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_CP1(byteLenP, byteLenN) (MCUXCLECC_CUSTOMPARAMS_OFFSET_R2N(byteLenP, byteLenN) + (byteLenN))
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_CP2(byteLenP, byteLenN) (MCUXCLECC_CUSTOMPARAMS_OFFSET_CP1(byteLenP, byteLenN) + (byteLenP))
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_GX(byteLenP, byteLenN)  (MCUXCLECC_CUSTOMPARAMS_OFFSET_CP2(byteLenP, byteLenN) + (byteLenP))
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_GY(byteLenP, byteLenN)  (MCUXCLECC_CUSTOMPARAMS_OFFSET_GX(byteLenP, byteLenN) + (byteLenP))
#define MCUXCLECC_CUSTOMPARAMS_OFFSET_PP(byteLenP, byteLenN)  (MCUXCLECC_CUSTOMPARAMS_OFFSET_GY(byteLenP, byteLenN) + (byteLenP))

#define MCUXCLECC_CUSTOMPARAMS_SIZE_FIXED (sizeof(mcuxClEcc_Weier_DomainParams_t) + 2u * MCUXCLPKC_WORDSIZE)
#define MCUXCLECC_CUSTOMPARAMS_SIZE_NO_OF_PLEN (8u /* PFULL, R2P, CP1, CP2, GX, GY, PP */)
#define MCUXCLECC_CUSTOMPARAMS_SIZE_NO_OF_NLEN (2u /* NFULL, R2N */)



/**********************************************************/
/* Internal function declaration - Setup Environment      */
/**********************************************************/

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_WeierECC_SetupEnvironment(
        mcuxClSession_Handle_t pSession,
        mcuxClEcc_Weier_DomainParams_t *pWeierDomainParams,
        uint8_t noOfBuffers
        );

/**********************************************************/
/* Internal function declaration - point/params checks    */
/**********************************************************/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_PointCheckAffineNR)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_PointCheckAffineNR(mcuxClSession_Handle_t pSession);


#if defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_JACOBIAN_POINT_CHECK)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Weier_PointCheckJacMR)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Weier_PointCheckJacMR(mcuxClSession_Handle_t pSession, uint32_t iX, uint32_t iY, uint32_t iZ);
#endif /* defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_JACOBIAN_POINT_CHECK) */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_SecureConvertPoint_JacToAffine(mcuxClSession_Handle_t pSession);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Weier_DomainParamsCheck)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_DomainParamsCheck(mcuxClSession_Handle_t pSession,
                                                                               const uint32_t byteLenP,
                                                                               const uint32_t byteLenN);

/**********************************************************/
/* Internal function declaration - point arithmetic       */
/**********************************************************/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_RepeatPointDouble)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_RepeatPointDouble(uint32_t iteration);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_PointFullAdd)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_PointFullAdd(void);


/**********************************************************/
/* Internal function declaration - point multiplication   */
/**********************************************************/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Int_PointMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Int_PointMult(uint8_t iScalar, uint32_t scalarBitLength);

/**
 * Declaration of function to perform plain (not protected against side-channel attacks) scalar multiplication with the base point on Weierstrass curves
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Weier_PlainFixScalarMult, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_PlainFixScalarMult(
    mcuxClSession_Handle_t pSession,                 ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,   ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                ///<  [in]  iScalar             Pointer table index of scalar
    uint32_t scalarBitLength,                       ///<  [in]  scalarBitLength     Bit length of the scalar
    uint32_t options                                ///<  [in]  options             Parameter to pass options
);



#if defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_SECPOINTMULT)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_SecurePointMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_SecurePointMult(uint8_t iScalar, uint32_t scalarBitLength);
#endif /* defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_SECPOINTMULT) */

/**********************************************************/
/* Internal function declaration - key generation         */
/**********************************************************/

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Weier_BooleanToArithmeticMasking)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_BooleanToArithmeticMasking(void);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Int_CoreKeyGen)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Int_CoreKeyGen(mcuxClSession_Handle_t pSession, uint32_t nByteLength);


#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION

/**********************************************************/
/* Internal function declaration - ArithmeticOperation    */
/**********************************************************/

#if defined(MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD) || defined(MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ArithOp_PointAddSub)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_PointAddSub(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize,
    mcuxClEcc_ArithmeticOperationFunction_t caller);
#endif

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ArithOp_PointAdd, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_PointAdd(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize);
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ArithOp_PointSub, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_PointSub(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize);
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SCALARMULT
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ArithOp_ScalarMult, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_ScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize);
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SCALARMULT */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SECURESCALARMULT
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ArithOp_SecureScalarMult, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_SecureScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize);
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SECURESCALARMULT */

#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION */


/**********************************************************/
/* Internal declarations - Point Decoding                 */
/**********************************************************/

/**
 * Declaration of Weierstrass point decoding function
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_WeierECC_PointDecodingFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) (*mcuxClEcc_WeierECC_PointDecodingFunction_t)(
    mcuxClSession_Handle_t pSession,                         ///<        pSession               Handle for the current CL session
    mcuxCl_InputBuffer_t pEncodedPoint,                      ///<  [in]  pEncodedPoint          Buffer with encoded point
    mcuxCl_Buffer_t pDecodedPoint,                           ///<  [out] pDecodedPoint          Pointer to decoded point
    mcuxClEcc_WeierECC_PointEncType_t pointEncType,          ///<  [in]  pointEncType           Point encoding type specifying all information needed about the applied point encoding format
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams    ///<  [in]  pEccWeierDomainParams  Pointer to Weierstrass domain parameters
));


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_PointDecFct_SEC, mcuxClEcc_WeierECC_PointDecodingFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_PointDecFct_SEC(mcuxClSession_Handle_t pSession,
                                                                                mcuxCl_InputBuffer_t pEncodedPoint,
                                                                                mcuxCl_Buffer_t pDecodedPoint,
                                                                                mcuxClEcc_WeierECC_PointEncType_t pointEncType,
                                                                                mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams);
/**
 * Weierstrass point encoding variant descriptor structure
 */
struct mcuxClEcc_WeierECC_PointEncDescriptor
{
    mcuxClEcc_WeierECC_PointDecodingFunction_t pointDecFct; ///< Weierstrass point decoding function
    uint32_t pointDecFctFPId;                              ///< FP ID of the function pointDecFct
};



/**********************************************************/
/* Internal declarations - Weier key pair generation      */
/**********************************************************/

/**
 * @brief Function implementing WeierECC key pair generation.
 * @api
 *
 * This function generates an ECC key pair for usage within WeierECC protocols such as ECDSA and ECDH.
 *
 * @param      pSession             Handle for the current CL session.
 * @param[in]  generation           Key generation algorithm specifier.
 * @param[out] privKey              Key handle for the generated private key (word-aligned).
 * @param[out] pubKey               Key handle for the generated public key (word-aligned).
 *
 * @attention This function uses DRBG and PRNG. Caller needs to check if DRBG and PRNG are ready.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_WeierECC_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
    );



/**********************************************************/
/* Internal declarations - Weier key Validation           */
/**********************************************************/

/**
 * @brief ECC public key validation function, Key handle must be word-aligned
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_PublicKeyValidation, mcuxClKey_ValidationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClEcc_WeierECC_PublicKeyValidation(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key);

/**
 * @brief ECC private key validation function, Key handle must be word-aligned
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_PrivateKeyValidation, mcuxClKey_ValidationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClEcc_WeierECC_PrivateKeyValidation(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_WEIER_INTERNAL_H_ */
