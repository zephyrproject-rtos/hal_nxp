/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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


/**********************************************************/
/* Internal mcuxClEcc_TwEd functions                       */
/**********************************************************/

/**
 * Declaration of function to perform plain (not protected against side-channel attacks) scalar multiplication with variable input point
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainVarScalarMult, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_PlainVarScalarMult(
    mcuxClSession_Handle_t pSession,                          ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,            ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                         ///<  [in]  iScalar             Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                                ///<  [in]  scalarBitLength     Bit length of the scalar
    uint32_t options                                         ///<  [in]  options             Parameter to pass options
 );

/**
 * Declaration of the mixed point addition function
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_TwEd_MixedPointAddFunction_t,
    typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClEcc_TwEd_MixedPointAddFunction_t)(void));

/**
 * Declaration of the point doubling function
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_TwEd_PointDoubleFunction_t,
    typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClEcc_TwEd_PointDoubleFunction_t)(void));

/**
 * Declaration of the comb method pointer selection function
 * and structure containing the function pointer and its associated flow protection ID.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_TwEd_PtrSelectFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClEcc_TwEd_PtrSelectFunction_t)(
    mcuxClSession_Handle_t pSession, ///<  [in]  pSession            Handle for the current CL session
    uint32_t scalarWord,            ///<  [in]  scalarWord          CPU word containing the scalar bits to be processed
    uint8_t scalarOffset            ///<  [in]  scalarDigitOffset   Offset in scalarWord of scalar bit(s) to be processed
));

/**
 * Declaration of the plain (not protected against side-channel attacks) comb method pointer selection function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainPtrSelectComb, mcuxClEcc_TwEd_PtrSelectFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainPtrSelectComb(
    mcuxClSession_Handle_t pSession, ///<  [in]  pSession            Handle for the current CL session
    uint32_t scalarWord,            ///<  [in]  scalarWord          CPU word containing the digit (i3i2i1i0)_2
    uint8_t scalarDigitOffset       ///<  [in]  scalarDigitOffset   Bit offset in scalarWord of the digit (i3i2i1i0)_2
);

/**
 * Declaration of the plain (not protected against side-channel attacks) Montgomery ladder pointer selection function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainPtrSelectML, mcuxClEcc_TwEd_PtrSelectFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainPtrSelectML(
    mcuxClSession_Handle_t pSession, ///<  [in]  pSession            Handle for the current CL session
    uint32_t scalarWord,            ///<  [in]  scalarWord          CPU word containing the current scalar bit b
    uint8_t scalarBitOffset         ///<  [in]  scalarBitOffset     Offset in scalarWord of scalar bit b
);

/**
 * Declaration of function to import, convert and validate pre-computed points
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PrecPointImportAndValidate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_PrecPointImportAndValidate(
    mcuxClSession_Handle_t pSession, ///<  [in]  pSession            Handle for the current CL session
    uint8_t iDst,                   ///<  [in]  iDst                Pointer table index of buffer to which the x-coordinate shall be copied
    uint8_t *pSrc,                  ///<  [in]  pSrc                Pointer to the pre-computed point x-coordinate
    uint16_t byteLenP               ///<  [in]  byteLenP            Byte length of P
);

/**
 * Declaration of function to perform scalar multiplication with the base point
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_FixScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_FixScalarMult(
    mcuxClSession_Handle_t pSession,                          			///<  [in]  pSession           Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,            			///<  [in]  pDomainParams      Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                         			///<  [in]  iScalar            Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                                			///<  [in]  scalarBitLength    Bit length of the scalar; must be a multiple of 4
    mcuxClEcc_TwEd_MixedPointAddFunction_t mixedPointAddFct,             ///<  [in]  mixedPointAddFct      Curve dependent function to perform mixed point addition on twisted Edwards curve
    uint32_t mixedPointAddFctFPId,                                      ///<  [in]  mixedPointAddFctFPId  FP ID of the function mixedPointAddFct
    mcuxClEcc_TwEd_PointDoubleFunction_t pointDoubleFct,                 ///<  [in]  pointDoubleFct        Curve dependent function to perform point doubling on twisted Edwards curve
    uint32_t pointDoubleFctFPId,                                        ///<  [in]  pointDoubleFctFPId    FP ID of the function pointDoubleFct
    mcuxClEcc_TwEd_PtrSelectFunction_t ptrSelectFct,                     ///<  [in]  ptrSelectFct          Function to select pre-computed point to be added
    uint32_t ptrSelectFctFPId                                           ///<  [in]  ptrSelectFctFPId      FP ID of the function ptrSelectFct
 );


/**
 * Declaration of function to perform scalar multiplication with variable input point
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_VarScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_VarScalarMult(
    mcuxClSession_Handle_t pSession,                                ///<  [in]  pSession           Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,                  ///<  [in]  pDomainParams      Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                               ///<  [in]  iScalar            Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                                      ///<  [in]  scalarBitLength    Bit length of the scalar
    uint32_t options,                                              ///<  [in]  options            Parameter to pass options
    mcuxClEcc_TwEd_PtrSelectFunction_t ptrSelectFct,                ///<  [in]  ptrSelectFct       Function to select accumulated ladder points
    uint32_t ptrSelectFctFPId                                      ///<  [in]  ptrSelectFctFPId   FP ID of the function ptrSelectFct
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
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_MixedPointAddEd25519, mcuxClEcc_TwEd_MixedPointAddFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_MixedPointAddEd25519(void);

/**
 * Declaration of function to perform plain (not protected against side-channel attacks) scalar multiplication with the base point on Ed25519
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_TwEd_PlainFixScalarMult25519, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_PlainFixScalarMult25519(
    mcuxClSession_Handle_t pSession,                 ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,   ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                ///<  [in]  iScalar             Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                       ///<  [in]  scalarBitLength     Bit length of the scalar; must be a multiple of 4
    uint32_t options                                ///<  [in]  options             Parameter to pass options
);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_TWED_INTERNAL_H_ */
