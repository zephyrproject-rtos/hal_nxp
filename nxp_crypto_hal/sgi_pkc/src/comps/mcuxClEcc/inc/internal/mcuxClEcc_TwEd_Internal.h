/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal.h
 * @brief internal header of mcuxClEcc Twisted Edward's functionalities
 */


#ifndef MCUXCLECC_TWED_INTERNAL_H_
#define MCUXCLECC_TWED_INTERNAL_H_

#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Internal return codes of mcuxClEcc_TwEd                 */
/**********************************************************/

// None


/**********************************************************/
/* Internal mcuxClEcc_TwEd function defines                */
/**********************************************************/

#define MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE (4u)
#define MCUXCLECC_TWED_FIXSCALARMULT_DIGITMASK (0xFu)
#define MCUXCLECC_TWED_FIXSCALARMULT_NOOFPRECPOINTS (8u)
#define MCUXCLECC_TWED_FIXSCALARMULT_POINT_RANDOMIZE_PER_BITS (64u)
#define MCUXCLECC_TWED_VARSCALARMULT_POINT_RANDOMIZE_PER_BITS (8u)

#define MCUXCLECC_TWED_PPTABLE_ENTRY_SIZE_LOG2 (3u)
#define MCUXCLECC_TWED_PPTABLE_ENTRY_SIZE (1u << MCUXCLECC_TWED_PPTABLE_ENTRY_SIZE_LOG2)
#define MCUXCLECC_TWED_PPTABLE_INDEX_BITSIZE (4u)
#define MCUXCLECC_TWED_PPTABLE_ENTRY_NUMS (1u << MCUXCLECC_TWED_PPTABLE_INDEX_BITSIZE)
#define MCUXCLECC_TWED_PPTABLE_SIZE (MCUXCLECC_TWED_PPTABLE_ENTRY_NUMS * MCUXCLECC_TWED_PPTABLE_ENTRY_SIZE)
#define MCUXCLECC_TWED_PPTABLE_ENTRY_MASK (((uint32_t) 1u << 12) - 1u)
#define MCUXCLECC_TWED_PPTABLE_ENTRY_UPDATE_MASK ((((uint64_t) 1u << 28u) - 1u) << 36u)

#define MCUXCLECC_TWED_PPTABLE_PACK_ENTRY(pOperands, iX, iY, iT, iXNEG, iTNEG) ( \
                                    (((uint64_t)(pOperands)[iX]    >> 3u) <<  0u) | \
                                    (((uint64_t)(pOperands)[iY]    >> 3u) << 12u) | \
                                    (((uint64_t)(pOperands)[iT]    >> 3u) << 24u) | \
                                    (((uint64_t)(pOperands)[iXNEG] >> 3u) << 36u) | \
                                    (((uint64_t)(pOperands)[iTNEG] >> 3u) << 48u))

#define MCUXCLECC_TWED_PPTABLE_ENTRY_UPDATE(tableEntry, pOperands, iX, iY, iT) ( \
                                    ((uint64_t) (tableEntry) & MCUXCLECC_TWED_PPTABLE_ENTRY_UPDATE_MASK) | \
                                    (((uint64_t)(pOperands)[iX]    >> 3u) <<  0u) | \
                                    (((uint64_t)(pOperands)[iY]    >> 3u) << 12u) | \
                                    (((uint64_t)(pOperands)[iT]    >> 3u) << 24u))

#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY(maskedTableEntry, X, Y, T, XNEG, TNEG)   \
do { \
    X = (uint16_t)((((maskedTableEntry) >>  0u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ); \
    Y = (uint16_t)((((maskedTableEntry) >> 12u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ); \
    T = (uint16_t)((((maskedTableEntry) >> 24u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ); \
    XNEG = (uint16_t)((((maskedTableEntry) >> 36u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ); \
    TNEG = (uint16_t)((((maskedTableEntry) >> 48u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ); \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
} while(false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_MASKED_X(maskedTableEntry)    ((uint16_t)((((maskedTableEntry) >>  0u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_MASKED_Y(maskedTableEntry)    ((uint16_t)((((maskedTableEntry) >> 12u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_MASKED_T(maskedTableEntry)    ((uint16_t)((((maskedTableEntry) >> 24u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_MASKED_XNEG(maskedTableEntry) ((uint16_t)((((maskedTableEntry) >> 36u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_MASKED_TNEG(maskedTableEntry) ((uint16_t)((((maskedTableEntry) >> 48u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))

#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_X_MASK(tableEntryMask)    ((uint16_t)((((tableEntryMask) >>  0u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_Y_MASK(tableEntryMask)    ((uint16_t)((((tableEntryMask) >> 12u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_T_MASK(tableEntryMask)    ((uint16_t)((((tableEntryMask) >> 24u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_XNEG_MASK(tableEntryMask) ((uint16_t)((((tableEntryMask) >> 36u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))
#define MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY_TNEG_MASK(tableEntryMask) ((uint16_t)((((tableEntryMask) >> 48u) & MCUXCLECC_TWED_PPTABLE_ENTRY_MASK) << 3u ))


/**********************************************************/
/* Internal mcuxClEcc_TwEd type definitions                */
/**********************************************************/

/* CPU workarea used by TwEd_SecureFixScalarMult function
 *
 * NOTE: For security reasons, the CPU workarea used SHALL be 64 bit aligned */
typedef struct
{
    uint64_t precPointTable[MCUXCLECC_TWED_PPTABLE_SIZE / sizeof(uint64_t)];
    uint64_t shuffleBuffer1[MCUXCLECC_TWED_PPTABLE_SIZE / sizeof(uint64_t)];
    uint64_t shuffleBuffer2[MCUXCLECC_TWED_PPTABLE_SIZE / sizeof(uint64_t)];
    uint64_t precPointTableMask;
} mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t;

/** Inline function to convert word-aligned pointer to specific CPU workarea. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_inline_PointerToCpuWa)
static inline mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t* mcuxClEcc_TwEd_inline_PointerToCpuWa(uint32_t *pCpuWa64BitAligned)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("MISRA Ex. 9 to Rule 11.3 - pCpuWa64BitAligned and mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t 64 bit aligned")
    mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *pCpuWa = (mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *)pCpuWa64BitAligned;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

    return pCpuWa;
}

/**********************************************************/
/* Internal mcuxClEcc_TwEd functions                       */
/**********************************************************/

/**
 * Declaration of function to perform plain (not protected against side-channel attacks) scalar multiplication with variable input point
 *
 * Data Integrity: Expunge(MCUXCLECC_SCALARMULT_OPTION_PLAIN * scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainVarScalarMult, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainVarScalarMult(
    mcuxClSession_Handle_t pSession,                          ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,            ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                         ///<  [in]  iScalar             Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                                ///<  [in]  scalarBitLength     Bit length of the scalar
    uint32_t options                                         ///<  [in]  options             Parameter to pass options
 );

/**
 * Declaration of function to perform secure (protected against side-channel attacks) scalar multiplication with variable input point
 *
 * Data Integrity: Expunge(MCUXCLECC_SCALARMULT_OPTION_SECURE * scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_SecureVarScalarMult, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_SecureVarScalarMult(
    mcuxClSession_Handle_t pSession,                          ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,            ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                         ///<  [in]  iScalar             Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                                ///<  [in]  scalarBitLength     Bit length of the scalar
    uint32_t options                                         ///<  [in]  options             Parameter to pass options
 );

/**
 * Declaration of the point addition function
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_TwEd_PointAddFunction_t,
    typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClEcc_TwEd_PointAddFunction_t)(void));

/**
 * Declaration of the point doubling function
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_TwEd_PointDoubleFunction_t,
    typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClEcc_TwEd_PointDoubleFunction_t)(void));

/**
 * Declaration of the plain (not protected against side-channel attacks) comb method pointer selection function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainPtrSelectComb)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainPtrSelectComb(
    mcuxClSession_Handle_t pSession, ///<  [in]  pSession            Handle for the current CL session
    uint32_t scalarWord,            ///<  [in]  scalarWord          CPU word containing the digit (i3i2i1i0)_2
    uint8_t scalarDigitOffset       ///<  [in]  scalarDigitOffset   Bit offset in scalarWord of the digit (i3i2i1i0)_2
);

/**
 * Declaration of the secure comb method pointer selection function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_SecurePtrSelectComb)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_SecurePtrSelectComb(
    mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *pCpuWa,
    uint32_t scalarWord0,
    uint32_t scalarWord1,
    uint32_t scalarDigitOffset
);

/**
 * Declaration of the plain (not protected against side-channel attacks) Montgomery ladder pointer selection function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainPtrSelectML)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainPtrSelectML(
    mcuxClSession_Handle_t pSession, ///<  [in]  pSession            Handle for the current CL session
    uint32_t scalarWord,            ///<  [in]  scalarWord          CPU word containing the current scalar bit b
    uint8_t scalarBitOffset         ///<  [in]  scalarBitOffset     Offset in scalarWord of scalar bit b
);

/**
 * Declaration of function to perform scalar multiplication with the base point
 *
 * Data Integrity: Expunge((MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options) * scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_FixScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_FixScalarMult(
    mcuxClSession_Handle_t pSession,                                     ///<  [in]  pSession              Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,                       ///<  [in]  pDomainParams         Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                                    ///<  [in]  iScalar               Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                                           ///<  [in]  scalarBitLength       Bit length of the scalar; must be a multiple of 4
    mcuxClEcc_TwEd_PointAddFunction_t pointAddFct,                       ///<  [in]  pointAddFct           Curve dependent function to perform mixed point addition on twisted Edwards curve
    mcuxClEcc_TwEd_PointDoubleFunction_t pointDoubleFct,                 ///<  [in]  pointDoubleFct        Curve dependent function to perform point doubling on twisted Edwards curve
    uint32_t options                                                    ///<  [in]  options               Parameter to pass options
 );

/**
 * Declaration of function to perform scalar multiplication with variable input point
 *
 * Data Integrity: Expunge((MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options) * scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_VarScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_VarScalarMult(
    mcuxClSession_Handle_t pSession,                                ///<  [in]  pSession           Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,                  ///<  [in]  pDomainParams      Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                               ///<  [in]  iScalar            Pointer table index of scalar
    uint32_t scalarBitLength,                                      ///<  [in]  scalarBitLength    Bit length of the scalar
    uint32_t options                                               ///<  [in]  options            Parameter to pass options
 );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_CreatePPTable)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_CreatePPTable(
    uint64_t *pPrecPointTable                                       ///<  [in]  pPrecPointTable   Pointer to CPU workarea buffer as a table to store PKC offset
);

/**
 * Declaration of function to perform repeated doublings of twisted Edwards curve points in homogeneous coordinates
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_RepeatedDoubling)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_RepeatedDoubling(
    uint16_t noOfDoubles        ///<  [in]  noOfDoubles     Number of double operations to be performed
);


/**********************************************************/
/* Internal mcuxClEcc_TwEd functions for Ed25519           */
/**********************************************************/

/**
 * Declaration of the point doubling function on Ed25519
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PointDoubleEd25519, mcuxClEcc_TwEd_PointDoubleFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PointDoubleEd25519(void);

/**
 * Declaration of the mixed point addition function on Ed25519
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_MixedPointAddEd25519, mcuxClEcc_TwEd_PointAddFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_MixedPointAddEd25519(void);

/**
 * Declaration of the point addition function on Ed25519
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PointAddEd25519, mcuxClEcc_TwEd_PointAddFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PointAddEd25519(void);

/**
 * Declaration of function to perform plain (not protected against side-channel attacks) scalar multiplication with the base point on Ed25519
 *
 * Data Integrity: Expunge(MCUXCLECC_SCALARMULT_OPTION_PLAIN + scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainFixScalarMult25519, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainFixScalarMult25519(
    mcuxClSession_Handle_t pSession,                 ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,   ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                ///<  [in]  iScalar             Pointer table index of scalar
    uint32_t scalarBitLength,                       ///<  [in]  scalarBitLength     Bit length of the scalar; must be a multiple of 4
    uint32_t options                                ///<  [in]  options             Parameter to pass options
);

/**
 * Declaration of function to perform secure scalar multiplication with the base point on Ed25519
 *
 * Data Integrity: Expunge(MCUXCLECC_SCALARMULT_OPTION_SECURE + scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_SecureFixScalarMult25519, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_SecureFixScalarMult25519(
    mcuxClSession_Handle_t pSession,                 ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,   ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                ///<  [in]  iScalar             Pointer table index of scalar
    uint32_t scalarBitLength,                       ///<  [in]  scalarBitLength     Bit length of the scalar; must be a multiple of 4
    uint32_t options                                ///<  [in]  options             Parameter to pass options
);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_TWED_INTERNAL_H_ */
