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
 * @file  mcuxClEcc_EdDSA_GenerateKeyPair.c
 * @brief Implementation of EdDSA key pair generation functionality
 */


#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClKey.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClMemory.h>
#include <mcuxClEcc.h>
#include <mcuxCsslDataIntegrity.h>

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
#include <internal/mcuxClEcc_Internal_Random.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#include <internal/mcuxClEcc_EdDSA_Internal_Hash.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>
#include <internal/mcuxClPrng_Internal_Functions.h>

/**
 * This function determines whether the EdDSA private key is supposed to be generated within or is passed to the
 * EdDSA key generation function.
 *  - If the private key is supposed to be generated, the function generates the private key using the DRBG into
 *    the CPU workarea and sets the pointer *ppPrivKey to this location.
 *  - If the private key is passed, then the pointer *ppPrivKey is set to its location.
 *
 * Input:
 *  - pSession     [in]     Handle for the current CL session
 *  - generation   [in]     Generation descriptor specifying the EdDSA GenerateKeyPair variant
 *  - pCpuWorkarea [in]     Pointer to the ECC specific CPU workarea struct
 *  - keyLength    [in]     Byte length of the private key
 *  - ppPrivKey    [out]    pointer to a pointer variable which shall be set to the private key location
 *
 * Data Integrity: This function RECORDs pPrivKey for DI protection. The corresponding EXPUNGE must be done in the caller.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClEcc_CpuWa_t *pCpuWorkarea,
    uint32_t keyLength,
    const uint8_t **ppPrivKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey);

    const mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t *mode = (const mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t *) generation->pProtocolDescriptor;
    uint32_t options = mode->options;
    /* SREQI_EDDSA_8 - DI protection for branch execution */
    MCUX_CSSL_DI_RECORD(keyGenBranchProtection, options);

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(keyLength, 0U, UINT32_MAX / 8U /* keyLength is divided by 8 before being passed, so cannot overflow in the following arithmetic */);

    if (MCUXCLECC_EDDSA_PRIVKEY_GENERATE == options)
    {
        /* Derive the security strength required for the RNG from (keyLength * 8) / 2 and check whether it can be provided. */
        MCUX_CSSL_FP_FUNCTION_CALL(ret_checkSecurityStrength, mcuxClRandom_checkSecurityStrength(pSession, (keyLength * 8u) / 2u));
        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_checkSecurityStrength);
        /* Reserve space on CPU workarea for the private key. */
        const uint32_t privKeyWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(keyLength);
        MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPrivKeyTemp, mcuxClSession_allocateWords_cpuWa(pSession, privKeyWords));

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("wordNumCpuWa is properly initialized in mcuxClEcc_Internal_SetupEnvironment and keyLength is bounded by 57 bytes, so it does not overflow")
        pCpuWorkarea->wordNumCpuWa += privKeyWords;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* SREQI_EDDSA_8 - Init pPrivKeyTemp with low entropy before filling with high quality randomness as an FA countermeasure */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pPrivKeyTemp,
                                                                   keyLength));

        /* SREQI_EDDSA_8 - Use HQRNG to generate the private key */
        MCUXCLECC_FP_RANDOM_HQRNG(mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey, pSession, pPrivKeyTemp, keyLength, ((uint32_t*)NULL));


        *ppPrivKey = pPrivKeyTemp;
        /* SREQI_EDDSA_8 - DI protect pPrivKey */
        MCUX_CSSL_DI_RECORD(privKeyStore, *ppPrivKey);

        /* SREQI_EDDSA_8 - DI protection for branch execution */
        MCUX_CSSL_DI_EXPUNGE(keyGenBranchProtection, MCUXCLECC_EDDSA_PRIVKEY_GENERATE);
    }
    else if (MCUXCLECC_EDDSA_PRIVKEY_INPUT == options)
    {
        /* Determine pointer to private key input. */
        // TODO CLNS-12064: Update once the private key input case is handled by the Key_derivation API.
        *ppPrivKey = mode->pPrivKeyInput;
        /* SREQI_EDDSA_8 - DI protect pPrivKey */
        MCUX_CSSL_DI_RECORD(privKeyStore, *ppPrivKey);

        /* SREQI_EDDSA_8 - DI protection for branch execution */
        MCUX_CSSL_DI_EXPUNGE(keyGenBranchProtection, MCUXCLECC_EDDSA_PRIVKEY_INPUT);
    }
    else
    {
        /* invalid option */
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey,
        MCUX_CSSL_FP_CONDITIONAL(MCUXCLECC_EDDSA_PRIVKEY_GENERATE == options,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
            MCUXCLECC_FP_CALLED_RANDOM_HQRNG_PKCWA));
}


/**
 * This function stores the
 *  - generated or imported private EdDSA key into the private key handle
 *  - computed sub-private key s and private key half hash (h_b,...,h_{2b-1}) into the private key handle
 *  - computed public key into the public key handle
 * by calling the associated key storing function via a call to MCUXCLKEY_STORE_FP.
 * Further the private and public key handles are being linked by this function.
 *
 * Input:
 *  - pSession [in]     Handle for the current CL session
 *  - privKey  [out]    Private EdDSA key handle
 *  - pPrivKey [in]     Pointer to private EdDSA key to be stored into the private key handle
 *  - pubKey   [out]    Public EdDSA key handle
 *
 * Data Integrity: This function EXPUNGEs pPrivKey for DI protection. The corresponding RECORD must be done in the caller.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t privKey,
    const uint8_t *pPrivKey,
    mcuxClKey_Handle_t pubKey )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys);

    /* Securely store private key in the key handle */
    MCUXCLKEY_STORE_FP(
      pSession,
      privKey,
      pPrivKey,
      MCUXCLECC_ENCODING_SPEC_EDDSA_PRIVKEY_STORE_SECURE);

    /* SREQI_EDDSA_8 - DI protect pPrivKey */
    MCUX_CSSL_DI_EXPUNGE(privKeyStore, pPrivKey);

    /* Securely store the sub-private key s (contained in PKC buffer ECC_S2) in the key handle.
     *
     * NOTE: No DI RESTORE/EXPUNGE added here for pSubPrivKey, because it is used directly after initialization. */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pSubPrivKey = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);
    MCUXCLKEY_STORE_FP(pSession, privKey, pSubPrivKey, MCUXCLECC_ENCODING_SPEC_EDDSA_SUBPRIVKEY_STORE_SECURE);

    /* Securely store the private key half hash (h_b,...,h_{2b-1}) (contained in PKC buffer ECC_S3) in the key handle.
     *
     * NOTE: No DI RESTORE/EXPUNGE added here for pPrivKeyHalfHash, because it is used directly after initialization.*/
    uint8_t *pPrivKeyHalfHash = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
    MCUXCLKEY_STORE_FP(
      pSession,
      privKey,
      pPrivKeyHalfHash,
      MCUXCLECC_ENCODING_SPEC_EDDSA_PRIVKEYHALFHASH_STORE_SECURE);

    /* Store public key into key handle
     *
     * NOTE: No DI RESTORE/EXPUNGE added here for pPubKeySrc, because it is used directly after initialization. */
    uint8_t *pPubKeySrc = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_COORD02]);
    MCUXCLKEY_STORE_FP(
      pSession,
      pubKey,
      pPubKeySrc,
      MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

    /* Create link between private and public key handles */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_linkKeyPair(pSession, privKey, pubKey));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys,
      MCUXCLKEY_STORE_FP_CALLED(privKey),
      MCUXCLKEY_STORE_FP_CALLED(privKey),
      MCUXCLKEY_STORE_FP_CALLED(privKey),
      MCUXCLKEY_STORE_FP_CALLED(pubKey),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_linkKeyPair));
}



#define MCUXCLECC_FP_GENKEYPAIR_SECSTRENGTH  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength)

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_GenerateKeyPair);

    /*
     * Step 1: Set up the environment
     */

    /* Verify that the key handles are correctly initialized for the EdDSA use case */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_KeyPairSanityCheck(pSession, privKey, pubKey));

    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));

    mcuxClEcc_EdDSA_DomainParams_t * const pDomainParams = (mcuxClEcc_EdDSA_DomainParams_t *) (privKey->type.info);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_SetupEnvironment(pSession, pDomainParams, ECC_EDDSA_NO_OF_BUFFERS));

    /* private and public key length = M = 32-byte for Ed25519 (b = 256 = 32*8) */
    /*                                  or 57-byte for Ed448 (b = 456 = 57*8).  */
    const uint32_t keyLength = (uint32_t) pDomainParams->b / 8u;
    MCUX_CSSL_DI_RECORD(hashPrivkeyParams, keyLength);


    /*
     * Step 2: Determine whether the private key is passed to the function or needs to be generated. In the latter case, generate the private key d.
     */

    /* Initialize a pointer to the private key (to be determined) for later usage */
    const uint8_t * pPrivKey = NULL;

    /* Either set pPrivKey to the passed private key input or set it to some CPU workarea location and generate the private key in this memory area. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey(pSession,
                                                                             generation,
                                                                             pCpuWorkarea,
                                                                             keyLength,
                                                                             &pPrivKey));

    /*
     * Step 3: Hash the private key using the hash function specified in the EdDSA domain parameters and store
     *         the hash result (h_0,...,h_{2b-1}) in buffers ECC_T2 and ECC_S3 with offset such that the second half
     *         (h_b,...,h_{2b-1}) is stored at the beginning of ECC_S3.
     */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pS3 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S3]);
    uint8_t *pPrivKeyHashPkc = pS3 - keyLength;
    MCUXCLBUFFER_INIT_RO(buffPrivKey, NULL, pPrivKey, keyLength);
    MCUX_CSSL_DI_RECORD(hashPrivkeyParams, buffPrivKey);
    MCUXCLBUFFER_INIT(buffPrivKeyHashPkc, NULL, pPrivKeyHashPkc, 2u * keyLength);
    MCUX_CSSL_DI_RECORD(hashPrivkeyParams, buffPrivKeyHashPkc);
    /* SREQI_EDDSA_8 - Init pPrivKeyHashPkc with low entropy before filling it with the hash result */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pPrivKeyHashPkc,
                                                               2u * keyLength));

    /* SREQI_EDDSA_8 - Calculate 2b-bit hash of private key. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("buffPrivKey != NULL, because it's set in mcuxClEcc_EdDSA_GenerateKeyPair_GetPrivKey")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_KeyGen_HashPrivKey(pSession,
                                          pDomainParams,
                                          buffPrivKey, buffPrivKeyHashPkc,
                                          keyLength));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()


    /*
     * Step 4: Derive the secret scalar s from the first half (h_b,..,h_{2b-1}) of the private key hash and store it in buffer ECC_S2.
     */

    /* The bits 0~(b-1) of private key hash is placed before and adjacent to PKC operand S3. */
    const uint32_t b = pDomainParams->b;  /* = 256 (Ed25519); 456 (Ed448) */
    const uint32_t c = pDomainParams->c;  /* =   3 (Ed25519);   2 (Ed448) */
    const uint32_t t = pDomainParams->t;  /* = 254 (Ed25519); 447 (Ed448) */
    const uint32_t offsetS3 = (uint32_t) pOperands[ECC_S3];
    /* V0 = PKC operand containing the first half of private key hash.       */
    /* V1 = V0 for Ed25519 (64/128-bit PkcWord) and Ed448 (128-bit PkcWord); */
    /*    = V0 + 64-bit for Ed448 (64-bit PkcWord).                          */
    /* ps, PKC will ignore non-aligned part of offsets.                      */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("the results are in range of uint16")
    pOperands[ECC_V0] = (uint16_t) (offsetS3 - (b/8u));
    pOperands[ECC_V1] = (uint16_t) (offsetS3 - (t/8u));
    /* V2/V3/V4 are shift/rotate amounts used in FUP program below. */
    /* V2 = 2 (Ed25519); 9 (Ed448). */
    /* V3 = -252 \equiv  4 (Ed25519);                */
    /*      -446 \equiv  2 (Ed448, 64-bit PkcWord)   */
    /*               or 66 (Ed448, 128-bit PkcWord). */
    pOperands[ECC_V2] = (uint16_t) (b - t);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("c - 1 won't wrapbecause c = 3 (Ed25519) or c = 2 (Ed448).")
    pOperands[ECC_V3] = (uint16_t) (c - 1u - t);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    pOperands[ECC_V4] = (uint16_t) c;

    /* Calculate mask offset to have mask and key correct aligned when demasking */
    /* For Ed448 one PKC word offest is needed */
    /* For Ed25519 no offest is needed */
    pOperands[ECC_V5] = pOperands[ECC_S1] + ((uint8_t) (b - t)); // ED25519
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA()

    /* SREQI_EDDSA_8 - DI record virtual pointer table entries */
    MCUX_CSSL_DI_RECORD(vPointerTableProtection, (uint32_t)pOperands[ECC_V0]);
    MCUX_CSSL_DI_RECORD(vPointerTableProtection, (uint32_t)pOperands[ECC_V1]);
    MCUX_CSSL_DI_RECORD(vPointerTableProtection, (uint32_t)pOperands[ECC_V2]);
    MCUX_CSSL_DI_RECORD(vPointerTableProtection, (uint32_t)pOperands[ECC_V3]);
    MCUX_CSSL_DI_RECORD(vPointerTableProtection, (uint32_t)pOperands[ECC_V4]);
    MCUX_CSSL_DI_RECORD(vPointerTableProtection, (uint32_t)pOperands[ECC_V5]);

    /* SREQI_EDDSA_8 - Initialize XOR mask with LQRNG and pre-initialize parts of the output buffer */
    uint8_t *pS2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUX_CSSL_DI_RECORD(pkcLengthSfrProtection, operandSize);
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pS2,
                                                               bufferSize));

    uint32_t keyLengthPkc = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(keyLength);
    MCUX_CSSL_DI_RECORD(pkcLengthSfrProtection, keyLengthPkc);
    MCUXCLPKC_PS2_SETLENGTH(0u, keyLengthPkc);

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S,
                       mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S_LEN);

    /* SREQI_EDDSA_8 - DI expunge virtual pointer table entries */
    MCUX_CSSL_DI_EXPUNGE(vPointerTableProtection, (uint32_t)pOperands[ECC_V0]);
    MCUX_CSSL_DI_EXPUNGE(vPointerTableProtection, (uint32_t)pOperands[ECC_V1]);
    MCUX_CSSL_DI_EXPUNGE(vPointerTableProtection, (uint32_t)pOperands[ECC_V2]);
    MCUX_CSSL_DI_EXPUNGE(vPointerTableProtection, (uint32_t)pOperands[ECC_V3]);
    MCUX_CSSL_DI_EXPUNGE(vPointerTableProtection, (uint32_t)pOperands[ECC_V4]);
    MCUX_CSSL_DI_EXPUNGE(vPointerTableProtection, (uint32_t)pOperands[ECC_V5]);
    /* SREQI_EDDSA_8 - DI expunge PKC length SFR values */
    const uint32_t ps1LenAfterFup = MCUXCLPKC_PS1_GETOPLEN();
    const uint32_t ps2LenAfterFup = MCUXCLPKC_PS2_GETOPLEN();
    MCUX_CSSL_DI_EXPUNGE(pkcLengthSfrProtection, ps1LenAfterFup);
    MCUX_CSSL_DI_EXPUNGE(pkcLengthSfrProtection, ps2LenAfterFup);

    /*
     * Step 5: Perform a blinded scalar multiplication Q = s*G and store the resulting point in encoded form Q_enc in buffer ECC_COORD02.
     */

    /* Call the BlindedScalarMult function.
     * If the function returns OK, ECC_COORD00 and ECC_COORD01 contain the affine x- and y-coordinates of Q.
     * If the function returns SCALAR_ZERO, ECC_COORD00 and ECC_COORD01 are set to the coordinates of the neutral point (0,1). */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_BlindedScalarMult, mcuxClEcc_BlindedFixScalarMult(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParams->common, pDomainParams->common.byteLenN) );
    if(MCUXCLECC_STATUS_OK != ret_BlindedScalarMult)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Intentionally left empty */
    }

    /* Derive the encoding Q_enc of Q and store it in buffer ECC_COORD02.
     *
     * NOTE: PS2 lengths are still set to (0u, keyLengthPkc) */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_EncodePoint(keyLength));

    /*
     * Step 6: (Securely) store the key data in the key handles and link the key pair.
     */

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys(pSession, privKey, pPrivKey, pubKey));

    /* SREQI_EDDSA_8 - DI protect pPrivKey
     *
     * NOTE: The call to mcuxClEcc_EdDSA_GenerateKeyPair_StoreAndLinkKeys expunges pPrivKey which has been recorded above */


    /* Import prime p and order n again, and check (compare with) existing one. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pDomainParams->common));


    /* Clean up and exit */
    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_GenerateKeyPair,
        MCUXCLECC_FP_EDDSA_GENERATEKEYPAIR_FINAL);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_EdDSA_GeneratePrivKey =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .pKeyGenFct = mcuxClEcc_EdDSA_GenerateKeyPair,
    .protectionTokenKeyGenFct = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateKeyPair),
    .pProtocolDescriptor = (const void *) &mcuxClEcc_EdDsa_GeneratePrivKeyDescriptor
};
