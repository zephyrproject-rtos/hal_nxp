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
 * @file  mcuxClEcc_Weier_Internal.h
 * @brief internal header for short Weierstrass curves
 */


#ifndef MCUXCLECC_WEIER_INTERNAL_H_
#define MCUXCLECC_WEIER_INTERNAL_H_


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
/* Internal function declaration - Setup Environment      */
/**********************************************************/

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Weier_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Weier_SetupEnvironment(
        mcuxClSession_Handle_t pSession,
        const mcuxClEcc_DomainParam_t *pWeierDomainParams,
        uint8_t noOfBuffers
        );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_SetupEnvironment(
        mcuxClSession_Handle_t pSession,
        mcuxClEcc_Weier_DomainParams_t *pWeierDomainParams,
        uint8_t noOfBuffers
        );

/**********************************************************/
/* Internal function declaration - point/params checks    */
/**********************************************************/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_PointCheckAffineNR)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_PointCheckAffineNR(void);


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

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_SecurePointMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_SecurePointMult(mcuxClSession_Handle_t pSession,
                                                                       uint8_t iScalar,
                                                                       uint32_t scalarBitLength);

/**********************************************************/
/* Internal function declaration - key generation         */
/**********************************************************/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_WeierECC_BlindedSecretKeyGen_RandomWithExtraBits)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_BlindedSecretKeyGen_RandomWithExtraBits(
    mcuxClSession_Handle_t pSession,
    uint32_t byteLenN);



/**********************************************************/
/* Internal function declaration - ArithmeticOperation    */
/**********************************************************/

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





#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_WEIER_INTERNAL_H_ */
