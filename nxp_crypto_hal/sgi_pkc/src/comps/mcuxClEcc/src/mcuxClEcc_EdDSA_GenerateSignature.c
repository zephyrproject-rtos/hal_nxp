/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClEcc_EdDSA_GenerateSignature.c
 * @brief Implementation of the EdDSA signature generation functionality
 */


#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxClBuffer.h>
#include <mcuxClSignature.h>
#include <mcuxClRandom.h>
#include <mcuxClHash.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClEcc_Internal_KeyHelper.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClSignature_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#include <internal/mcuxClEcc_EdDSA_Internal_Hash.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClPrng_Internal_Functions.h>


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateSignature, mcuxClSignature_SignFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClEcc_EdDSA_GenerateSignature(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key,
    mcuxClSignature_Mode_t signatureMode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_Buffer_t pSignature,
    uint32_t * const pSignatureSize )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_GenerateSignature);

    const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode = (const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *) signatureMode->pProtocolDescriptor;
    /*
     * Step 1: Set up the environment
     */

    /* Derive the pointer to the public key handle and verify that the key handles are correctly initialized for the EdDSA use case */
    mcuxClKey_Handle_t pubKey = (mcuxClKey_Handle_t) mcuxClKey_getLinkedData(key);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_KeyPairSanityCheck(pSession, key, pubKey));

    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));

    mcuxClEcc_EdDSA_DomainParams_t * const pDomainParams = (mcuxClEcc_EdDSA_DomainParams_t *) mcuxClKey_getTypeInfo(key);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_SetupEnvironment(pSession, pDomainParams, ECC_EDDSA_NO_OF_BUFFERS));

    /*
     * Step 2: Derive the hash prefix from the mode parameter and calculate the secret scalar
     *
     *           r = H(prefix || (h_b,...,h_{2b-1}) || m')
     *
     *         using
     *           - the hash function algoSecHash to hash the blocks containing the secret (h_b,\dots,h_{2b-1}), and
     *           - the hash function algoHash to hash the remaining part of the hash input
     *         and store the hash output in buffers ECC_S2 and ECC_T2.
     */

    /* Generate digest m' from m in case phflag is set */
    const uint8_t *pMessage = NULL;
    uint32_t messageSize = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_PreHashMessage(pSession, pDomainParams, pCpuWorkarea, mode->phflag, pIn, inSize, &pMessage, &messageSize));

    /* Calculate 2b-bit hash H(prefix || (h_b,\dots,h_{2b-1}) || m') and store it in the concatenated buffers ECC_S2 and ECC_T2. */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pS2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);
    const uint32_t keyLength = (uint32_t) pDomainParams->b / 8u;

    MCUXCLBUFFER_INIT_RO(buffMessage1, NULL, pMessage, messageSize);
    mcuxCl_InputBuffer_t buffMessage = NULL;
    if (MCUXCLECC_EDDSA_PHFLAG_ONE == mode->phflag)
    {
        buffMessage = buffMessage1;
    }
    else if (MCUXCLECC_EDDSA_PHFLAG_ZERO == mode->phflag)
    {
        buffMessage = pIn;
    }
    else
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClEcc_EdDSA_CalcSecretScalar(pSession, pDomainParams, mode, key, buffMessage, messageSize, pS2)
    );

    mcuxClEcc_CommonDomainParams_t *pCommonDomainParams = (mcuxClEcc_CommonDomainParams_t *) &pDomainParams->common;
    const uint32_t byteLenP = (uint32_t) pCommonDomainParams->byteLenP;
    const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenP); /* Note that n < p for EdDSA */
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;

    /*
     * Step 3: Perform a blinded scalar multiplication R = r*G and store the resulting point in encoded form R^enc in buffer ECC_COORD02.
     */

    /* Call the BlindedScalarMult function.
     * If the function returns OK, ECC_COORD00 and ECC_COORD01 contain the affine x- and y-coordinates of R.
     * If the function returns SCALAR_ZERO, ECC_COORD00 and ECC_COORD01 are set to the coordinates of the neutral point (0,1). */
    MCUX_CSSL_FP_BRANCH_DECL(blindedScalarMultBranch);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_BlindedScalarMult, mcuxClEcc_BlindedFixScalarMult(pSession, pCommonDomainParams, 2u * keyLength));
    if (MCUXCLECC_INTSTATUS_SCALAR_ZERO == ret_BlindedScalarMult)
    {
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_COORD00, 0u);
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_COORD01, 0u);
        MCUXCLPKC_FP_CALC_OP1_ADD_CONST(ECC_COORD01, ECC_COORD00, 1u);

        MCUX_CSSL_FP_BRANCH_POSITIVE(blindedScalarMultBranch,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_ADD_CONST);
    }
    else if (MCUXCLECC_STATUS_OK != ret_BlindedScalarMult)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Intentionally left empty */
        MCUX_CSSL_FP_BRANCH_NEGATIVE(blindedScalarMultBranch);
    }

    /* Derive the encoding R_enc of R and store it in buffer ECC_COORD02.
     *
     * NOTE: PS2 lengths are still set to (0u, keyLengthPkc) */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_EncodePoint(keyLength));

    /*
     * Step 4: Calculate H(prefix || R^{enc} || Q^{enc} || m') mod n using the hash function algoHash specified in the EdDSA domain parameters
     *         and store it in buffer ECC_S2.
     */

    /* Calculate H(prefix || R^{enc} || Q^{enc} || m') mod n */
    const uint8_t *pSignatureR = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_COORD02]);
    MCUXCLBUFFER_INIT_RO(buffSignatureR, NULL, pSignatureR, keyLength);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_CalcHashModN(
      pSession,
      pDomainParams,
      mode->pHashPrefix,
      mode->hashPrefixLen,
      buffSignatureR,
      pubKey,
      buffMessage,
      messageSize
    ));

    /*
     * Step 5: Securely import the secret scalar s and securely calculate signature component
     *
     *           S = r + H(prefix || R^{enc} || Q^{enc} || m') * s mod n
     *
     *         and store it in buffer ECC_T0.
     */

    /* Generate an additive blinding rndS in ECC_T2 for blinding the secret scalar s and r of byte size bufferSize - 1.
     *
     * NOTE: In the following, we will consider s and rndS as values of byte length 2*operandSize as this allows to
     *       use a plain addition for the additive blinding and makes it easier to compensate for Montgomery factors added by Montgomery multiplication.
     */

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(bufferSize, operandSize + MCUXCLPKC_WORDSIZE, operandSize + MCUXCLPKC_WORDSIZE, MCUXCLSIGNATURE_STATUS_INVALID_PARAMS)

    /* Clear a byte on top of additive blinding rndS */
    MCUXCLPKC_WAITFORFINISH();
    uint8_t *pT2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T2]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &pT2[bufferSize-1u]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, 1u);
    MCUXCLMEMORY_CLEAR_INT(&pT2[bufferSize - 1u], 1u);

    /* Generate additive blinding rndS*/
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pT2, bufferSize - 1u));

    /* Copy sigma to ECC_S1 */
    uint8_t *pS0 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);
    pOperands[ECC_V0] = MCUXCLPKC_PTR2OFFSET(&pS0[MCUXCLECC_SCALARBLINDING_BYTELEN]);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_S1, ECC_V0, 0u);
    MCUXCLPKC_WAITFORFINISH();

    /* Clear buffer on top of phi */
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &pS0[MCUXCLECC_SCALARBLINDING_BYTELEN]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, bufferSize-MCUXCLECC_SCALARBLINDING_BYTELEN);
    MCUXCLMEMORY_CLEAR_INT(&pS0[MCUXCLECC_SCALARBLINDING_BYTELEN], bufferSize - MCUXCLECC_SCALARBLINDING_BYTELEN);

    /* Clear buffer on top of sigma */
    uint8_t *pS1 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S1]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &pS1[operandSize]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, bufferSize-operandSize);
    MCUXCLMEMORY_CLEAR_INT(&pS1[operandSize], bufferSize - operandSize);

    /* Clear buffer on top of secret scalar s */
    uint8_t *pT3 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T3]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &pT3[operandSize]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, bufferSize - operandSize);
    MCUXCLMEMORY_CLEAR_INT(&pT3[operandSize], bufferSize - operandSize);

    /* Securely import the secret scalar s to ECC_T3. */
    uint8_t *pScalarDest = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T3]);
    MCUXCLKEY_LOAD_FP(
      pSession,
      key,
      &pScalarDest,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
      NULL,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
      MCUXCLECC_ENCODING_SPEC_EDDSA_SUBPRIVKEY_LOAD_SECURE);

    MCUXCLPKC_PS2_SETLENGTH(0u, bufferSize);

    /* Calculate S = r + H(prefix || R^{enc} || Q^{enc} || m') * s mod n in a blinded way and store the result in ECC_T0. */
    MCUXCLPKC_FP_CALC_OP2_ADD(ECC_S1, ECC_S1, ECC_T2);           /* ECC_S1 = sigma + rndS */
    MCUXCLPKC_FP_CALC_OP2_ADD(ECC_T3, ECC_T3, ECC_T2);           /* ECC_S2 = s + rndS */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS2_SETLENGTH(bufferSize, operandSize);

    uint8_t *pT0 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T0]);
    pOperands[ECC_V0] = MCUXCLPKC_PTR2OFFSET(&pT0[MCUXCLPKC_WORDSIZE]);
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S,
                        mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S_LEN);

    /* Clear the result S after operandSize with 0's, so ECC_T0 will only contain S and afterwards halfSignatureSize bytes
     * can be copied.
     *
     * NOTE: This will clear potential data in ECC_T0 after S, but for Ed448 it is needed because
     *       mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S returns S (of operandSize) 1 byte smaller than keyLength and
     *       S will be copied in Step 7 with keyLength. */
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, (uint32_t)&pT0[operandSize] + 1u);
    MCUXCLMEMORY_CLEAR_INT(&pT0[operandSize], 1u);

    /*
     * Step 6: Copy
     *           - the signature component R^{enc} to the beginning of buffer pSignature
     *           - the signature component S behind R^{enc} in the pSignature buffer
     *
     * NOTE: No need to wait for the PKC here, as this will be done in the export functions. */
    uint32_t halfSignatureSize = keyLength;
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_BUFFER_DI_BALANCED(pSignature, ECC_COORD02, halfSignatureSize);
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_BUFFEROFFSET_DI_BALANCED(pSignature, ECC_T0, halfSignatureSize, halfSignatureSize);

    /*
     * Step 7: Set the size *pSignatureSize to the size of the generated signature.
     */
    *pSignatureSize = 2u * halfSignatureSize;

    /* Import prime p and order n again, and check (compare with) existing one. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParams->common));

    /* Clean up and exit */
    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateSignature, MCUXCLSIGNATURE_STATUS_OK,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(blindedScalarMultBranch, MCUXCLECC_INTSTATUS_SCALAR_ZERO == ret_BlindedScalarMult),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(blindedScalarMultBranch, MCUXCLECC_INTSTATUS_SCALAR_ZERO != ret_BlindedScalarMult),
        MCUXCLECC_FP_EDDSA_GENERATESIGNATURE_FINAL
    );
}

