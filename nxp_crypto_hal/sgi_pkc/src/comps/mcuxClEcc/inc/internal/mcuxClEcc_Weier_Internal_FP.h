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
 * @file  mcuxClEcc_Weier_Internal_FP.h
 * @brief flow protection definitions
 */


#ifndef MCUXCLECC_WEIER_INTERNAL_FP_H_
#define MCUXCLECC_WEIER_INTERNAL_FP_H_

#include <mcuxClCore_Platform.h>


/**********************************************************/
/* mcuxClEcc_WeierECC_GenerateKeyPair                      */
/**********************************************************/

/* Initialization */
#define MCUXCLECC_FP_GENERATEKEYPAIR_INIT  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa)

/* Import/check base point */
#define MCUXCLECC_FP_GENERATEKEYPAIR_BASE_POINT  \
    MCUXCLECC_FP_GENERATEKEYPAIR_INIT,  \
    MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

/* Generate private key */
#define MCUXCLECC_FP_GENERATEKEYPAIR_GENERATE_PRIKEY  \
    MCUXCLECC_FP_GENERATEKEYPAIR_BASE_POINT,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_CoreKeyGen)

/* Calculate public key */
#define MCUXCLECC_FP_GENERATEKEYPAIR_CALC_PUBKEY  \
    MCUXCLECC_FP_GENERATEKEYPAIR_GENERATE_PRIKEY,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_LSB0s,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult)

/* Convert/check public key */
#define MCUXCLECC_FP_GENERATEKEYPAIR_CONVERT_PUBKEY  \
    MCUXCLECC_FP_GENERATEKEYPAIR_CALC_PUBKEY,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

/* Check n/p and export */
#define MCUXCLECC_FP_GENERATEKEYPAIR_FINAL(privKey, pubKey)  \
    MCUXCLECC_FP_GENERATEKEYPAIR_CONVERT_PUBKEY,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN),  \
    MCUXCLKEY_STORE_FP_CALLED(privKey),  \
    MCUXCLKEY_STORE_FP_CALLED(pubKey),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_linkKeyPair),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_ECDSA_GenerateSignature                       */
/**********************************************************/

/* Initialization */
#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_INIT  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa)

#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_BEFORE_LOOP  \
    MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_INIT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT)

/* Mail loop - first part, until checking r */
#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_LOOP_R_0  \
    MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_LOOP_R_1  \
    MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_LOOP_R_0,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_CoreKeyGen)

#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_LOOP_R  \
    MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_LOOP_R_1,  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_LSB0s,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MS

/* Mail loop - second part, checking s */
#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_LOOP_S  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate_Internal),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_PrepareMessageDigest),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MS

#define MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_FINAL  \
   	MCUXCLECC_FP_ECDSA_GENERATESIGNATURE_BEFORE_LOOP, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN),  \
    MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_ECDH_KeyAgreement                             */
/**********************************************************/

/* Initialization */
#define MCUXCLECC_FP_ECDH_KEYAGREEMENT_INIT  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa)

/* Import/check base point */
#define MCUXCLECC_FP_ECDH_KEYAGREEMENT_BASE_POINT(otherKey)  \
    MCUXCLECC_FP_ECDH_KEYAGREEMENT_INIT,  \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUXCLKEY_LOAD_FP_CALLED(otherKey), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)


/* Import scalar */
#define MCUXCLECC_FP_ECDH_KEYAGREEMENT_SCALAR(key, otherKey)  \
    MCUXCLECC_FP_ECDH_KEYAGREEMENT_BASE_POINT(otherKey), \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal), \
    MCUXCLKEY_LOAD_FP_CALLED(key), \
	MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_BlindedVarScalarMult)

/* Calculate scalar multiplication */
#define MCUXCLECC_FP_ECDH_KEYAGREEMENT_SCALAR_MULTIPLICATION(key, otherKey)  \
    MCUXCLECC_FP_ECDH_KEYAGREEMENT_SCALAR(key, otherKey),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_PointCheckJacMR)

/* Convert/check result of scalar multiplication */
#define MCUXCLECC_FP_ECDH_KEYAGREEMENT_CONVERT_POINT(key, otherKey)  \
    MCUXCLECC_FP_ECDH_KEYAGREEMENT_SCALAR_MULTIPLICATION(key, otherKey),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine)

/* Check n/p and export */
#define MCUXCLECC_FP_ECDH_KEYAGREEMENT_FINAL(key, otherKey)  \
    MCUXCLECC_FP_ECDH_KEYAGREEMENT_CONVERT_POINT(key, otherKey),  \
	MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportBigEndianFromPkc), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_ECDSA_VerifySignature                         */
/**********************************************************/

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_INIT \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_IMPORT1 \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_Import)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_IMPORT2 \
        MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST, \
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS, \
        MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_Import)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CHECK_IMPORTS \
        MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST, \
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS, \
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_S1 \
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P1 \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_Calculate_P1)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P2(key) \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUXCLKEY_LOAD_FP_CALLED(key), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_RepeatPointDouble), \
        MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_PointMult)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_PREPARE_AND_CHECK \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_INIT, \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_IMPORT1, \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_IMPORT2, \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CHECK_IMPORTS, \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_S1, \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P1, \
        MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P2(key), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature_Calculate)

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_CALC_P1_ADD_P2 \
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLPKC_FLAG_ZERO != checkHashZero), \
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd), \
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd), \
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR), \
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLPKC_FLAG_ZERO == checkHashZero), \
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST), \
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR), \
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP

#define MCUXCLECC_FP_ECDSA_VERIFYSIGNATURE_FINAL \
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_computeAndSetCrcForExternalVerification), \
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_WeierECC_GenerateDomainParams                 */
/**********************************************************/

#define MCUXCLECC_FP_WEIERECC_GENERATEDOMAINPARAMS_INIT_AND_VERIFY  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_InitializeEnvironment), \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER, \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared), \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER, \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM, \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER, \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER, \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_DomainParamsCheck),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QDash),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

#define MCUXCLECC_FP_WEIERECC_GENERATEDOMAINPARAMS_FINAL(options)  \
    MCUXCLECC_FP_WEIERECC_GENERATEDOMAINPARAMS_INIT_AND_VERIFY,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportBigEndianToPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE

#define MCUXCLECC_FP_WEIERECC_DOMAINPARAMSCHECK_INTERMEDIATE \
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP, \
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP

#define MCUXCLECC_FP_WEIERECC_DOMAINPARAMSCHECK_FINAL \
            MCUXCLECC_FP_WEIERECC_DOMAINPARAMSCHECK_INTERMEDIATE, \
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

#ifdef MCUXCL_FEATURE_ECC_EDDSA

/**********************************************************/
/* mcuxClEcc_EdDSA_VerifySignature                         */
/**********************************************************/

/* Step 2: Set up the environment */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_SETUP_ENVIRONMENT \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment)

/* Step 3: Import signature component */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_IMPORT_SIGNATURE_COMPONENT \
    MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_SETUP_ENVIRONMENT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult)

/* Step 4: Back up coordinates */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_BACK_UP_COORDINATES \
    MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_IMPORT_SIGNATURE_COMPONENT, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST

/* Step 5: Compute hash */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_COMPUTE_HASH \
    MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_BACK_UP_COORDINATES, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult)

/* Step 6: Check point */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_CHECK_POINT \
    MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_COMPUTE_HASH, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST

/* Step 7: Final verification */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_FINAL_VERIFICATION \
    MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_CHECK_POINT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_CheckSignatureEquation)

/* Step 8: Final */
#define MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_FINAL \
    MCUXCLECC_FP_EDDSA_VERIFYSIGNATURE_FINAL_VERIFICATION, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN)

/**********************************************************/
/* mcuxClEcc_EdDSA_GenerateSignature                       */
/**********************************************************/

#define MCUXCLECC_FP_EDDSA_GENERATESIGNATURE_FINAL \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_KeyPairSanityCheck), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_PreHashMessage), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_CalcSecretScalar), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_BlindedFixScalarMult), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_EncodePoint), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_CalcHashModN), \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal), \
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUXCLKEY_LOAD_FP_CALLED(key), \
        MCUXCLPKC_FP_CALLED_CALC_OP2_ADD, \
        MCUXCLPKC_FP_CALLED_CALC_OP2_ADD, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
        MCUXCLPKC_FP_CALLED_EXPORTLITTLEENDIANFROMPKC_BUFFER, \
        MCUXCLPKC_FP_CALLED_EXPORTLITTLEENDIANFROMPKC_BUFFEROFFSET, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN), \
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE

/**********************************************************/
/* mcuxClEcc_EdDSA_GenerateKeyPair                         */
/**********************************************************/

#define MCUXCLECC_FP_EDDSA_GENERATEKEYPAIR_FINAL \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_KeyPairSanityCheck), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_KeyGen_HashPrivKey), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_BlindedFixScalarMult), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_EncodePoint), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN), \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE

#endif /* MCUXCL_FEATURE_ECC_EDDSA */

/**********************************************************/
/* mcuxClEcc_Int_CoreKeyGen                                */
/**********************************************************/

/* Step 1 */
#define MCUXCLECC_FP_INT_COREKEYGEN_STEP1 \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate_Internal), \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength), \
    MCUXCLECC_FP_CALLED_RANDOM_HQRNG_PKCWA

/* Step 2 */
#define MCUXCLECC_FP_INT_COREKEYGEN_STEP2 \
    MCUXCLECC_FP_INT_COREKEYGEN_STEP1, \
    MCUXCLPKC_FP_CALLED_CALC_OP2_CONST, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_BooleanToArithmeticMasking), \
    MCUXCLPKC_FP_CALLED_CALC_OP2_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP2_SUB

/* Step 3 */
#define MCUXCLECC_FP_INT_COREKEYGEN_STEP3 \
    MCUXCLECC_FP_INT_COREKEYGEN_STEP2, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_SUB_CONST, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ReduceModEven), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ReduceModEven)

/* Step 4 */
#define MCUXCLECC_FP_INT_COREKEYGEN_STEP4 \
    MCUXCLECC_FP_INT_COREKEYGEN_STEP3, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate_Internal), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv)

/* Step 6 */
#define MCUXCLECC_FP_INT_COREKEYGEN_STEP6 \
    MCUXCLECC_FP_INT_COREKEYGEN_STEP4, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

/* Final step */
#define MCUXCLECC_FP_INT_COREKEYGEN_FINAL \
    MCUXCLECC_FP_INT_COREKEYGEN_STEP6, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
#if defined(MCUXCL_FEATURE_ECC_EDDSA) || defined(MCUXCL_FEATURE_ECC_MONTDH)

/**********************************************************/
/* mcuxClEcc_GenerateMultiplicativeBlinding                */
/**********************************************************/

/* Final step */
#define MCUXCLECC_FP_GENERATEMULTIPLICATIVEBLINDING_FINAL \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate_Internal), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR, \
    MCUXCLPKC_FP_CALLED_CALC_MC2_MR, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv), \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate_Internal), \
    MCUXCLPKC_FP_CALLED_CALC_MC2_MM, \
    MCUXCLPKC_FP_CALLED_CALC_OP2_ADD, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

#endif /* defined(MCUXCL_FEATURE_ECC_EDDSA) || defined(MCUXCL_FEATURE_ECC_MONTDH) || defined(MCUXCL_FEATURE_ECC_WEIERECC_KEYDERIVATION) */

/**********************************************************/
/* mcuxClEcc_BlindedVarScalarMult                          */
/**********************************************************/

#define MCUXCLECC_FP_BLINDEDVARSCALARMULT_CHECK_IF_SCALAR_IS_ZERO \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QDash), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate), \
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_SHR, \
    MCUXCLPKC_FP_CALLED_CALC_OP1_ADD, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

#define MCUXCLECC_FP_BLINDEDVARSCALARMULT_FINAL \
    MCUXCLECC_FP_BLINDEDVARSCALARMULT_CHECK_IF_SCALAR_IS_ZERO, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult), \
    MCUXCLPKC_FP_CALLED_CALC_OP1_LSB0s, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult)

#endif /* MCUXCLECC_WEIER_INTERNAL_FP_H_ */
