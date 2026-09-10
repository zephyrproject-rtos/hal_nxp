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
 * @file  mcuxClEcc_Internal.h
 * @brief internal header of mcuxClEcc functionalities
 */


#ifndef MCUXCLECC_INTERNAL_H_
#define MCUXCLECC_INTERNAL_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClSession.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClBuffer.h>
#include <mcuxClEcc_Types.h>

#include <internal/mcuxClEcc_Internal_UPTRT_access.h>
#include <internal/mcuxClEcc_Internal_PkcWaLayout.h>

#ifdef __cplusplus
extern "C" {
#endif


/**********************************************************/
/*                                                        */
/* Internal return codes of mcuxClEcc                      */
/*                                                        */
/**********************************************************/

#define MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK        ((mcuxClEcc_Status_t) 0x55AAE817u)

/* Rule of ECC return codes:
 * All return codes are of the format: 0x55XXYYTT
 * API         : XX = 55
 * Internal    : XX = AA
 * HammingWeight(YY) = HammingWeight(TT) = 4, according to coding guidelines
 * YY needs to be a balanced byte, and TT = ~YY
 *
 * General  OK  : YYTT = 5555
 * Fault Attack : YYTT = F00F
 */


/**********************************************************/
/*                                                        */
/* Definition of CPU workarea layout of ECC APIs          */
/*                                                        */
/**********************************************************/

MCUX_CSSL_ANALYSIS_START_SUPPRESS_FLEXIBLE_ARRAY("Due to project requirements ECC component needs to handle different usecases. In order to preserve memory flexible array is used. It is user responsibility to provide sufficient memory area using provided macros for each usecase.")
typedef struct
{
    uint32_t wordNumCpuWa;  /* number of words (uint32_t) used in CPU workarea */
    uint32_t wordNumPkcWa;  /* number of words (uint32_t) used in PKC workarea */
    mcuxClPkc_State_t pkcStateBackup;
    uint32_t pOperands32[];
} mcuxClEcc_CpuWa_t;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_FLEXIBLE_ARRAY()

/**
 * @brief Cast a pointer to word-aligned data to a pointer to the mcuxClEcc_CpuWa_t type.
 *
 * @param pCpuWa    The pointer to cast to a proper mcuxClEcc_CpuWa_t* type. Must be aligned.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_castToEccCpuWorkarea)
static inline mcuxClEcc_CpuWa_t* mcuxClEcc_castToEccCpuWorkarea(uint32_t* pCpuWa)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClEcc_CpuWa_t *) pCpuWa;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

/**********************************************************/
/*                                                        */
/* Definition of generic ECC domain parameters            */
/*                                                        */
/**********************************************************/

typedef struct mcuxClEcc_CommonDomainParams mcuxClEcc_CommonDomainParams_t;


/**
 * The scalar multiplication function declaration
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_ScalarMultFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) (*mcuxClEcc_ScalarMultFunction_t)(
    mcuxClSession_Handle_t pSession,                ///< Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,  ///< Pointer to ECC domain parameters structure
    uint8_t iScalar,                               ///< Pointer table index of scalar buffer in PKC RAM
    uint32_t scalarBitLength,                      ///< Bit length of the scalar
    uint32_t options                               ///< Parameter to pass options
    ));

typedef struct mcuxClEcc_ScalarMultFunctions
{
    mcuxClEcc_ScalarMultFunction_t secFixScalarMultFct;    ///< Pointer to secure scalar multiplication function that shall be used to perform a scalar multiplication lambda*G for secret scalar lambda in {1,...,n-1} and base point G
    uint32_t secFixScalarMultFctFPId;                     ///< FP ID of the secFixScalarMultFct function
    mcuxClEcc_ScalarMultFunction_t secVarScalarMultFct;    ///< Pointer to secure scalar multiplication function that shall be used to perform a scalar multiplication lambad*P for secret scalar lambda in {1,...,n-1} and arbitrary point P on the curve
    uint32_t secVarScalarMultFctFPId;                     ///< FP ID of the secVarScalarMultFct function
    mcuxClEcc_ScalarMultFunction_t plainFixScalarMultFct;  ///< Pointer to plain scalar multiplication function that shall be used to perform a scalar multiplication lambda*G for non-secret scalar lambda in {1,...,n-1} and base point G
    uint32_t plainFixScalarMultFctFPId;                   ///< FP ID of the plainFixScalarMultFctFPId function
    mcuxClEcc_ScalarMultFunction_t plainVarScalarMultFct;  ///< Pointer to plain scalar multiplication function that shall be used to perform a scalar multiplication lambda*G for non-secret scalar lambda in {1,...,n-1} and arbitrary point P on the curve
    uint32_t plainVarScalarMultFctFPId;                   ///< FP ID of the plainVarScalarMultFct function
} mcuxClEcc_ScalarMultFunctions_t;

/**
 * Common part of domain parameter structure, shared by all ECC functions.
 */
struct mcuxClEcc_CommonDomainParams
{
    uint16_t byteLenP;       ///< byte length of prime p
    uint16_t byteLenN;       ///< byte length of base point order n
    uint8_t *pFullModulusP;  ///< pointer to p'||p (in little endian format)
    uint8_t *pFullModulusN;  ///< pointer to n'||n (in little endian format)
    uint8_t *pR2P;           ///< pointer to Montgomery parameter R^2 mod p (in little endian format)
    uint8_t *pR2N;           ///< pointer to Montgomery parameter R^2 mod n (in little endian format)
    uint8_t *pCurveParam1;   ///< Pointer to first curve parameter (a for Weierstrass and twisted Edwards curves and A for Montgomery curves)
    uint8_t *pCurveParam2;   ///< Pointer to second curve parameter (b for Weierstrass curves, d for twisted Edwards curves and B for Montgomery curves)
    uint8_t *pGx;            ///< Pointer to x-coordinate Gx of base point G
    uint8_t *pGy;            ///< Pointer to y-coordinate Gy of base point G
    uint8_t *pPrecPoints;    ///< Pointer to pre-computed points for fixed base point scalar multiplication (2^(byteLenN * 4) * G for Weierstrass curves, used in ECDSA signature verification; reserved for other curves)
    uint8_t *pLadderConst;   ///< Pointer to pre-computed Montgomery ladder constant (in little endian format, used for Montgomery and Twisted Edwards curves)
    const mcuxClEcc_ScalarMultFunctions_t *pScalarMultFunctions;  ///< Pointer to struct that contains scalar multiplication function pointers
};


/**********************************************************/
/*                                                        */
/* Definitions related to external ECC arithmetic         */
/* operation function                                     */
/*                                                        */
/**********************************************************/

/**
 * The arithmetic operation function declaration
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_ArithmeticOperationFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) (*mcuxClEcc_ArithmeticOperationFunction_t)(
    mcuxClSession_Handle_t pSession,                       ///< Handle for the current CL session
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams, ///< Pointer to Weierstrass domain parameters of the curve
    mcuxCl_InputBuffer_t pOp1,                             ///< First input operand
    uint32_t op1Size,                                     ///< Size of first input operand
    mcuxCl_InputBuffer_t pOp2,                             ///< Second input operand
    uint32_t op2Size,                                     ///< Size of second input operand
    mcuxCl_Buffer_t pResult,                               ///< Result buffer
    uint32_t * const pResultSize                          ///< Size of result
    ));

struct mcuxClEcc_ArithmeticOperationDescriptor
{
    mcuxClEcc_ArithmeticOperationFunction_t arithOpFct;    ///< arithmetic operation function
    uint32_t arithOpFct_FP_FuncId;                        ///< FP ID of the arithmetic operation function
};


/**********************************************************/
/*                                                        */
/* Miscellanious definitions                              */
/*                                                        */
/**********************************************************/

/**
 * Options to determine whether scalar multiplication input/output are in affine or projective format.
 */
#define MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_INPUT    (0x000000A5u)
#define MCUXCLECC_SCALARMULT_OPTION_AFFINE_INPUT        (0x0000005Au)
#define MCUXCLECC_SCALARMULT_OPTION_INPUT_MASK          (0x000000FFu)
#define MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_OUTPUT   (0x0000C300u)
#define MCUXCLECC_SCALARMULT_OPTION_AFFINE_OUTPUT       (0x00003C00u)
#define MCUXCLECC_SCALARMULT_OPTION_OUTPUT_MASK         (0x0000FF00u)

/**
 * Define specifying the size of the multiplicative scalar blinding bit size
 */
#define MCUXCLECC_SCALARBLINDING_BITSIZE (32u)
#define MCUXCLECC_SCALARBLINDING_BYTELEN (MCUXCLECC_SCALARBLINDING_BITSIZE / 8u)


#define MCUXCLECC_ALL_ONES_WORD (0xFFFFFFFFU)


/**********************************************************/
/*                                                        */
/* Internal function declarations                         */
/*                                                        */
/**********************************************************/

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_InterleaveScalar)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_InterleaveScalar(uint16_t iScalar, uint32_t scalarBitLength, uint32_t numberOfInterleavings);

/** Helper macro to call #mcuxClEcc_InterleaveScalar with flow protection. */
#define MCUXCLECC_FP_INTERLEAVESCALAR(iScalar, bitLenScalar, numberOfInterleavings)  \
    do{ \
        MCUX_CSSL_FP_FUNCTION_CALL(retValTemp, mcuxClEcc_InterleaveScalar(iScalar, bitLenScalar, numberOfInterleavings));  \
        (void) retValTemp;  /* Checking is unnecessary, because it always returns OK. */  \
    } while (false)


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_InterleaveTwoScalars)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_InterleaveTwoScalars(uint16_t iScalar0_iScalar1, uint32_t scalarBitLength);

/** Helper macro to call #mcuxClEcc_InterleaveTwoScalars with flow protection. */
#define MCUXCLECC_FP_INTERLEAVETWOSCALARS(iS0_iS1, bitLenScalar)  \
    do{ \
        MCUX_CSSL_FP_FUNCTION_CALL(retValTemp, mcuxClEcc_InterleaveTwoScalars(iS0_iS1, bitLenScalar));  \
        (void) retValTemp;  /* Checking is unnecessary, because it always returns OK. */  \
    } while (false)


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_GenerateMultiplicativeBlinding)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_GenerateMultiplicativeBlinding(
    mcuxClSession_Handle_t pSession,
    uint8_t scalarIndex
    );



MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_BlindedScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_BlindedScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CommonDomainParams_t *pCommonDomainParams
    );



MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_SetupEnvironment(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CommonDomainParams_t *pCommonDomainParams,
    uint8_t noOfBuffers
    );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_RecodeAndReorderScalar)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_RecodeAndReorderScalar(
    mcuxClSession_Handle_t pSession,
    uint8_t scalarIndex,
    uint8_t f,
    uint32_t scalarBitLength
    );

/** Helper macro to call #mcuxClEcc_RecodeAndReorderScalar with flow protection. */
#define MCUXCLECC_FP_RECODEANDREORDERSCALAR(scalarIndex, f, scalarBitLength)  \
    do{ \
        MCUX_CSSL_FP_FUNCTION_CALL(retValTemp, mcuxClEcc_RecodeAndReorderScalar(pSession, scalarIndex, f, scalarBitLength));  \
        (void) retValTemp;  /* Checking is unnecessary, because it always returns OK. */  \
    } while (false)



    #define MCUXCLECC_HANDLE_HW_UNAVAILABLE(retCodeReceived, callerName) do{} while(false)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_INTERNAL_H_ */
