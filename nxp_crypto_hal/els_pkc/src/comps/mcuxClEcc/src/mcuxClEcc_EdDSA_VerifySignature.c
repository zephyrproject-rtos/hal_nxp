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
 * @file  mcuxClEcc_EdDSA_VerifySignature.c
 * @brief Implementation of the EdDSA signature verification functionality
 */


#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey.h>
#include <mcuxClPkc.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClMath.h>
#include <mcuxClEcc.h>
#include <mcuxClHash.h>

#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>


/**
 * This function verifies that the signature component S satisfies S < n and in this case performs the scalar multiplication
 * h * S * G of S with the EdDSA base point as part of the EdDSA signature verification process.
 *
 * Input:
 *  - pSession [in]         Handle for the current CL session
 *  - pDomainParams [in]    Pointer to EdDSA domain parameters
 *  - pSignature [in]       Buffer for the signature (Renc,S)
 *  - bitLenN [in]          Bit length of the base point order n
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers ECC_CP0 and ECC_CP1 contain the curve parameters a and d in MR
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - If the function returned OK, then the result of the scalar multiplication h * S * G is stored
 *    in homogeneous coordinates in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
 *    NOTE: This also holds for the neutral point result in case S = 0.
 *
 * Returns:
 *  - MCUXCLECC_STATUS_OK                    if the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_SIGNATURE     if S does not satisfy S < n, i.e. the signature is invalid
 *  - MCUXCLECC_STATUS_FAULT_ATTACK          if a fault attack has been detected
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxCl_InputBuffer_t pSignature,
    uint32_t bitLenN)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult);

    /*
     * Step 1: Import signature component S to buffer ECC_S0 and check if it is smaller than n.
     */
    {  /* TODO: CLNS-11671, workaround for Ed448 */
        const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
        const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
        MCUXCLPKC_WAITFORREADY();
        MCUXCLPKC_PS1_SETLENGTH(0u, bufferSize);

        /* Import S to ECC_S0 */
        const uint32_t encodedLen = (uint32_t) pDomainParams->b / 8u;
        MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult, ECC_S0, pSignature, encodedLen, encodedLen);

        MCUXCLPKC_WAITFORREADY();
        MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);
    }

    /* Check s < n. */
    /* TODO: CLNS-11671, the comparison should include the 57th byte (p8S0[56]) for Ed448 */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_S0, ECC_N);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {   /* s >= n. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFEROFFSET,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
    }

    /*
     * Step 2: Calculate P1' = S * G, and store the result in homogeneous coordinates (X:Y:Z) in MR in buffers
     *         ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     *         NOTE: In case S = 0, the neutral point is correctly computed by the function and stored as (0:Z:Z)
     */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_plainFixScalarMult,
        pDomainParams->common.pScalarMultFunctions->plainFixScalarMultFct(
            pSession,
            (mcuxClEcc_CommonDomainParams_t *)&pDomainParams->common,
            ECC_S0,
            bitLenN,
            MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_OUTPUT));
    if(MCUXCLECC_STATUS_OK != ret_plainFixScalarMult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /*
     * Step 3: Calculate P1 = h * P1' = h * S * G using repeated point doubling, and store the result in homogeneous
     *          coordinates (X:Y:Z) in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_RepeatedDoubling(pDomainParams->c));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFEROFFSET,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        pDomainParams->common.pScalarMultFunctions->plainFixScalarMultFctFPId,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_RepeatedDoubling));
}


/**
 * This function computes the value H(prefix||Renc||Qenc||m') mod n, decodes the public EdDSA key Qenc and performs the scalar multiplication
 * h * H(prefix||Renc||Qenc||m') * Q = (H(prefix||Renc||Qenc||m') mod n) * h * Q with the decoded EdDSA public key Q as part of the
 * EdDSA signature verification process.
 *
 * Input:
 *  - pSession [in]         Handle for the current CL session
 *  - pubKey [in]           Key handle for public key Qenc
 *  - mode [in]             Pointer to signature protocol descriptor specifying the EdDSA variant
 *  - pIn [in]              Buffer for message digest m'
 *  - inSize [in]           Size of message digest m'
 *  - pCpuWorkarea [in]     Pointer to ECC specific CPU workarea struct
 *  - pDomainParams [in]    Pointer to EdDSA domain parameters
 *  - buffSignatureR [in]   Buffer containing the EdDSA signature component Renc
 *  - bitLenN [in]          Bit length of the base point order n
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers ECC_CP0 and ECC_CP1 contain the curve parameters a and d in MR
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - If the function returned OK, then the result of the scalar multiplication h * H(prefix||Renc||Qenc||m') * Q is stored
 *    in homogeneous coordinates in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
 *
 * Returns:
 *  - MCUXCLECC_STATUS_OK                if the function executed successfully
 *  - MCUXCLECC_STATUS_INVALID_PARAMS    if the public key decoding failed, i.e. the point is not on the curve
 *  - MCUXCLECC_STATUS_FAULT_ATTACK      if a fault attack has been detected
 *  - MCUXCLxxx_STATUS_xxx               The function execution failed and the first internal error will be returned
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t pubKey,
    const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxClEcc_CpuWa_t *pCpuWorkarea,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxCl_InputBuffer_t buffSignatureR,
    uint32_t bitLenN)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult);

    /*
     * Step 1: Derive the hash prefix from the mode parameter and calculate H(prefix||Renc||Qenc||m') mod n
     * and store it in buffer ECC_S0.
     */

    /* Generate digest m' from m in case phflag is set */
    const uint8_t *m = NULL;
    uint32_t mLen = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL(retPreHash, mcuxClEcc_EdDSA_PreHashMessage(pSession, pDomainParams, pCpuWorkarea, mode->phflag, pIn, inSize, &m, &mLen));
    if (MCUXCLECC_STATUS_OK != retPreHash)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Initialize hash context */
    uint32_t hashContextSizeInWords = mcuxClHash_getContextWordSize(pDomainParams->algoHash);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Return pointer is 32-bit aligned and satisfies the requirement of mcuxClHash_Context_t");
    mcuxClHash_Context_t pCtx = (mcuxClHash_Context_t) mcuxClSession_allocateWords_cpuWa(pSession, hashContextSizeInWords);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING();
    if (NULL == pCtx)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    const uint8_t *pPubKey = mcuxClKey_getKeyData(pubKey);
    MCUXCLBUFFER_INIT_RO(buffM1, NULL, m, mLen);
    mcuxCl_InputBuffer_t buffM = NULL;
    if (MCUXCLECC_EDDSA_PHFLAG_ONE == mode->phflag)
    {
        buffM = buffM1;
    }
    else if (MCUXCLECC_EDDSA_PHFLAG_ZERO == mode->phflag)
    {
        buffM = pIn;
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(ret_CalcHashModN,
        mcuxClEcc_EdDSA_CalcHashModN(
            pSession, pCtx, pDomainParams,
            mode->pHashPrefix, mode->hashPrefixLen,
            buffSignatureR,
            pPubKey,
            buffM, mLen) );
    if (MCUXCLECC_STATUS_OK != ret_CalcHashModN)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Free the hash context */
    mcuxClSession_freeWords_cpuWa(pSession, hashContextSizeInWords);

    /*
     * Step 2: Call function pDomainParams->pDecodePointFct to decode the public key Qenc and store
     * the homogeneous coordinates of the decoded point Q in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     */

    MCUXCLBUFFER_INIT_RO(buffPubKey, NULL, pPubKey, encodedLen);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_decodePoint,
        pDomainParams->pDecodePointFct(
            pDomainParams,
            buffPubKey) );
    if(MCUXCLECC_STATUS_OK != ret_decodePoint)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult, ret_decodePoint,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_PreHashMessage),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_CalcHashModN),
            pDomainParams->pDecodePoint_FP_FuncId);
    }


    /*
     * Step 3: Calculate P2' = h * Q using repeated point doubling, and store the result in homogeneous
     *         coordinates (X:Y:Z) in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_RepeatedDoubling(pDomainParams->c));

    /*
     * Step 4: Call function pDomainParameters->pPlainVarScalarMultFct to calculate
     *           P2 = (H(prefix||Renc||Qenc||m') mod n) * P2'
     *              = h * H(prefix||Renc||Qenc||m') * Q
     *         and store the result in homogeneous coordinates in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     *
     * NOTES:
     *  - Due to the scalar multiplication by the cofactor h above, P2' is ensured to be in the base point order group
     *    of order n. Therefore, the variable scalar multiplication function, which only works for points for input points
     *    in this group, can be used
     *  - Since the input point P2' has order dividing n, it's fine to use the scalar (H(prefix||Renc||Qenc||m') mod n) instead
     *    of H(prefix||Renc||Qenc||m'). Note that this would not have been the case for the public key which might be a point
     *    of even order such that (H(prefix||Renc||Qenc||m') mod n) * Q is not necessarily the same as H(prefix||Renc||Qenc||m') * Q.
     *  - If either the scalar is zero mod n or P2' is the neutal point, the resulting neutral point is correctly returned in buffers
     *    ECC_COORD00, ECC_COORD01 and ECC_COORD02 by the function.
     */

    MCUX_CSSL_FP_FUNCTION_CALL(ret_plainVarScalarMult,
        pDomainParams->common.pScalarMultFunctions->plainVarScalarMultFct(
            pSession,
            &pDomainParams->common,
            ECC_S0,
            bitLenN,
            MCUXCLECC_SCALARMULT_OPTION_PROJECTIVE_OUTPUT));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult, ret_plainVarScalarMult,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_PreHashMessage),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_CalcHashModN),
        pDomainParams->pDecodePoint_FP_FuncId,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_RepeatedDoubling),
        pDomainParams->common.pScalarMultFunctions->plainVarScalarMultFctFPId);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_VerifySignature_Core)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_VerifySignature_Core(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pSignature,
    uint32_t signatureSize )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_VerifySignature_Core);

    /*
     * Step 1: Set up the environment
     */
    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t * const pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_getCpuWaBuffer(session));
    mcuxClEcc_EdDSA_DomainParams_t * const pDomainParams = (mcuxClEcc_EdDSA_DomainParams_t *) mcuxClKey_getTypeInfo(key);

    MCUX_CSSL_FP_FUNCTION_CALL(retSetupEnvironment,
        mcuxClEcc_EdDSA_SetupEnvironment(session, pDomainParams, ECC_EDDSA_NO_OF_BUFFERS) );
    if (MCUXCLECC_STATUS_OK != retSetupEnvironment)
    {
        MCUXCLECC_HANDLE_HW_UNAVAILABLE(retSetupEnvironment, mcuxClEcc_EdDSA_VerifySignature_Core);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    const uint32_t encodedLen = (uint32_t) pDomainParams->b / 8u;
    const uint32_t sigLength = encodedLen * 2u;
    const mcuxCl_InputBuffer_t buffSignatureR = pSignature;

    /*
     * Step 2: Verify that the passed signatureSize value is as expected.
     */

    if (signatureSize != sigLength)
    {
        mcuxClSession_freeWords_pkcWa(session, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(session, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(session, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment));
    }

    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_FP_FUNCTION_CALL(leadingZerosN, mcuxClMath_LeadingZeros(ECC_N));
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(leadingZerosN, 0u, (operandSize * 8u), MCUXCLECC_STATUS_FAULT_ATTACK)
    uint32_t bitLenN = (operandSize * 8u) - leadingZerosN;

    /*
     * Step 3: Import signature component S and check if S < n holds. If not, return INVALID_SIGNATURE. Otherwise, calculate
     *         P1 = h * S * G, and store the result in homogeneous coordinates in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     *         In case S = 0, the neutral point is also correctly computed by the function.
     */
    MCUX_CSSL_FP_FUNCTION_CALL(retBasePointScalarMult,
        mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult(
            session,
            pDomainParams,
            pSignature,
            bitLenN));
    if (MCUXCLECC_STATUS_OK != retBasePointScalarMult)
    {
        mcuxClSession_freeWords_pkcWa(session, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(session, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(session, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, retBasePointScalarMult,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /*
     * Step 4: Back up the coordinates of P1 in buffers ECC_COORD25, ECC_COORD26 and ECC_COORD27.
     */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD25, ECC_COORD00, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD26, ECC_COORD01, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD27, ECC_COORD02, 0u);

    /*
     * Step 5: Computes the value H(prefix||Renc||Qenc||m') mod n, decode the public EdDSA key Qenc and perform the scalar multiplication
     *         P2 = h * H(prefix||Renc||Qenc||m') * Q = (H(prefix||Renc||Qenc||m') mod n) * (h * Q) with the decoded EdDSA public key Q
     *         and store the result in homogeneous coordinates in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
     *         Even if the scalar is zero mod n or the public key is the neutral point or of even order, the result is correctly computed.
     *         If the public key decoding fails, i.e. when the corresponding point is not on the curve, INVALID_PARAMS will be returned.
     */
    MCUX_CSSL_FP_FUNCTION_CALL(retPubScalarMult,
        mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult(
            session,
            key,
            mode,
            pIn,
            inSize,
            pCpuWorkarea,
            pDomainParams,
            buffSignatureR,
            bitLenN));
    if (MCUXCLECC_STATUS_OK != retPubScalarMult)
    {   /* s >= n. */
        mcuxClSession_freeWords_pkcWa(session, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(session, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(session, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, retPubScalarMult,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult),
            3u * MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /*
     * Step 6: Calculate h * R' = P1-P2, check that it lies on the curve and store the homogeneous coordinates of R' in the buffers
     *         ECC_COORD25, ECC_COORD26 and ECC_COORD27.
     */

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_PointSubtraction,
                        mcuxClEcc_FUP_TwEd_PointSubtraction_LEN);

    /* Verify that h * R' lies on the curve */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_PointValidation_HomMR, mcuxClEcc_FUP_TwEd_PointValidation_HomMR_LEN);

    if (MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Backup h*R' */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD25, ECC_COORD00, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD26, ECC_COORD01, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_COORD27, ECC_COORD02, 0u);


    /*
    * Step 7: Call function pDomainParams->pDecodePointFct to decode Renc and store the homogeneous coordinates of
    * the decoded point R in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02. If the decoding fails, return #MCUXCLECC_STATUS_INVALID_SIGNATURE.
    */

    MCUX_CSSL_FP_FUNCTION_CALL(ret2_decodePoint,
    pDomainParams->pDecodePointFct(
        pDomainParams,
        pSignature));
    if (MCUXCLECC_STATUS_INVALID_PARAMS == ret2_decodePoint)
    {
        mcuxClSession_freeWords_pkcWa(session, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(session, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(session, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_INVALID_SIGNATURE,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE,                                         /* Clean up */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment),                    /* Step 1 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),                             /* Step 2 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult), /* Step 3 */
            3U * MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,                                       /* Step 4 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult),    /* Step 5 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),                                   /* Step 6 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
            3U * MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            pDomainParams->pDecodePoint_FP_FuncId);
    }
    else if(MCUXCLECC_STATUS_OK != ret2_decodePoint)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Intentionally empty */
    }

    /*
    * Step 8: Calculate h*R using repeated point doubling, and store the result in homogeneous
    *         coordinates (X:Y:Z) in MR in buffers ECC_COORD00, ECC_COORD01 and ECC_COORD02.
    */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_RepeatedDoubling(pDomainParams->c));

    /*
    * Step 9: Before finally comparing h*R = (X:Y:Z) with h*R' = (X':Y':Z'), perform a sanity check on the Z-coordinates.
    *         Since both h*R and h*R' are valid points on the curve derived from finite points via complete curve
    *         arithmetic formulas arithmetic, they must also be finite, since for Ed25519 and Ed448
    *         the curve parameter d is a non-square modulo p.
    *         Hence, if one of the two Z-coordinates is zero mod p, FAULT_ATTACK is returned.
    */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_T0, ECC_COORD02, ECC_COORD27, ECC_P); // = Z*Z' in MR
    MCUXCLPKC_FP_CALC_MC1_MR(ECC_T1, ECC_T0, ECC_P); // = Z*Z' in NR in range [0,p]
    MCUXCLPKC_FP_CALC_MC1_MS(ECC_T0, ECC_T1, ECC_P, ECC_P); // = Z*Z' mod p
    if(MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /*
    * Step 10: Bring h*R' and h*R to the same Z-coordinate and compare the coordinates.
    * If the points are not equal, return #MCUXCLECC_STATUS_INVALID_SIGNATURE.
    */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    pOperands[ECC_V0] = pOperands[ECC_COORD25];
    pOperands[ECC_V1] = pOperands[ECC_COORD26];
    pOperands[ECC_V2] = pOperands[ECC_COORD27];

    /* Run the point comparison of P1 = h*R = (X1:Y1:Z1) and P2 = h*R' = (X2:Y2:Z2). The FUP program expects
     *  - the coordinates of h*R (point P1) to be passed via ECC_V0, ECC_V1, ECC_V2.
     *  - the coordinates of h*R' (point P2) to be stored in buffers ECC_COORD00, ECC_COORD01, ECC_COORD02.
     * As a result of the FUP program
     *  - the ZERO flag is set if and only if the PKC comparison of the two points passed
     *  - buffers ECC_S0 and ECC_S1 contain the concatenations X1' || Y1' and X2' || Y2', respectively, where
     *      - (X1':Y1':Z1') = (X1*Z2:Y1*Z2:Z1*Z2) are updated coordinates of P1 and
     *      - (X2':Y2':Z2') = (X2*Z1:Y2*Z1:Z2*Z1) are updated coordinates for P2
     *    sharing the same Z-coordinate for a potential upcoming double comparison by the CPU. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_PointComparisonHom,
                        mcuxClEcc_FUP_PointComparisonHom_LEN);

    mcuxClEcc_Status_t retVerify = MCUXCLECC_STATUS_INVALID_SIGNATURE;

    /* The last result is only zero if and only if R'=R */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        retVerify = MCUXCLECC_STATUS_OK;
    }

    /*
     * Step 11: Return
     */

    /* Clean up and exit */
    mcuxClSession_freeWords_pkcWa(session, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(session, &pCpuWorkarea->pkcStateBackup,
        mcuxClEcc_EdDSA_VerifySignature_Core, MCUXCLECC_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(session, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_VerifySignature_Core, retVerify,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SetupEnvironment),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_LeadingZeros),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_BasePointScalarMult),
        3u * MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_PubKeyScalarMult),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        3U * MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        pDomainParams->pDecodePoint_FP_FuncId,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_RepeatedDoubling),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_VerifySignature)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_VerifySignature(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pSignature,
    uint32_t signatureSize )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_VerifySignature);

    /* Call core function to calculate EdDSA signature */
    MCUX_CSSL_FP_FUNCTION_CALL(verify_result, mcuxClEcc_EdDSA_VerifySignature_Core(
    /* mcuxClSession_Handle_t session:                           */ session,
    /* mcuxClKey_Handle_t key                                    */ key,
    /* const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode */ mode,
    /* mcuxCl_InputBuffer_t pIn                                  */ pIn,
    /* uint32_t inSize                                          */ inSize,
    /* mcuxCl_InputBuffer_t pSignature                           */ pSignature,
    /* uint32_t pSignatureSize                                  */ signatureSize));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClEcc_EdDSA_VerifySignature, verify_result, MCUXCLECC_STATUS_FAULT_ATTACK,
                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature_Core));
}

