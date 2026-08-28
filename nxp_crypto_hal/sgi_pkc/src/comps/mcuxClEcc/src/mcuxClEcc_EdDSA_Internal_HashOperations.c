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
 * @file  mcuxClEcc_EdDSA_Internal_HashOperations.c
 * @brief Functions to perform hash operations involved in the EdDSA protocol
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClHash.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClEcc_Internal_KeyHelper.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#include <internal/mcuxClEcc_EdDSA_Internal_Hash.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_KeyGen_HashPrivKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_KeyGen_HashPrivKey(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxCl_InputBuffer_t buffPrivKey,
    mcuxCl_Buffer_t buffPrivKeyHash,
    uint32_t privKeyLen)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_KeyGen_HashPrivKey);

    uint32_t outLength = 0u;

    /* DI balancing of Hash_compute_internal */
    MCUX_CSSL_DI_RECORD(hashComputeInternalParams, &outLength);
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL(retHash,
        mcuxClHash_compute_internal(pSession,
                          pDomainParams->algoHash,
                          buffPrivKey,
                          privKeyLen,
                          buffPrivKeyHash,
                          &outLength));

    if ((pDomainParams->algoHash->hashSize != outLength) || (MCUXCLHASH_STATUS_OK != retHash))
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_KeyGen_HashPrivKey,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute_internal));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_SignVerify_CalcHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_SignVerify_CalcHash(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxClHash_Context_t pCtx,
    const uint8_t *pHashPrefix,
    uint32_t hashPrefixLen,
    mcuxCl_InputBuffer_t buffSignatureR,
    uint32_t signatureRLen,
    const uint8_t *pPubKey,
    uint32_t pubKeyLen,
    mcuxCl_InputBuffer_t buffIn,
    uint32_t inSize,
    mcuxCl_Buffer_t buffOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_SignVerify_CalcHash);

    uint32_t outLength = 0u;

    MCUX_CSSL_DI_RECORD(hashParams, 5U * (uint32_t)pCtx);
    MCUX_CSSL_DI_RECORD(hashProcess1Params, hashPrefixLen);
    MCUX_CSSL_DI_RECORD(hashProcess2Params, buffSignatureR);
    MCUX_CSSL_DI_RECORD(hashProcess2Params, signatureRLen);
    MCUX_CSSL_DI_RECORD(hashProcess3Params, pubKeyLen);
    MCUX_CSSL_DI_RECORD(hashProcess4Params, buffIn);
    MCUX_CSSL_DI_RECORD(hashProcess4Params, inSize);
    MCUX_CSSL_DI_RECORD(hashFinishParams, buffOutput);
    MCUX_CSSL_DI_RECORD(hashFinishParams, &outLength);

    /* Initialize the hash context */
    MCUX_CSSL_FP_FUNCTION_CALL(retInitHash,
        mcuxClHash_init(pSession,
                       pCtx,
                       pDomainParams->algoHash));
    if (MCUXCLHASH_STATUS_OK != retInitHash)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Update hash context with prefix */
    {
        MCUXCLBUFFER_INIT_RO(buffHashPrefix, NULL, pHashPrefix, hashPrefixLen);
        MCUX_CSSL_DI_RECORD(hashProcess1Params, buffHashPrefix);
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess1Hash,
            mcuxClHash_process_internal(pSession,
                                       pCtx,
                                       buffHashPrefix,
                                       hashPrefixLen));
        if (MCUXCLHASH_STATUS_OK != retProcess1Hash)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }

    /* Update hash context with Renc */
    MCUX_CSSL_FP_FUNCTION_CALL(retProcess2Hash,
        mcuxClHash_process_internal(pSession,
                                   pCtx,
                                   buffSignatureR,
                                   signatureRLen));
    if (MCUXCLHASH_STATUS_OK != retProcess2Hash)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Update hash context with Qenc */
    {
        MCUXCLBUFFER_INIT_RO(buffPubKey, NULL, pPubKey, pubKeyLen);
        MCUX_CSSL_DI_RECORD(hashProcess3Params, buffPubKey);
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess3Hash,
            mcuxClHash_process_internal(pSession,
                                       pCtx,
                                       buffPubKey,
                                       pubKeyLen));
        if (MCUXCLHASH_STATUS_OK != retProcess3Hash)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }

    /* Update hash context with m' */
    MCUX_CSSL_FP_FUNCTION_CALL(retProcess4Hash,
        mcuxClHash_process_internal(pSession,
                                   pCtx,
                                   buffIn,
                                   inSize));
    if (MCUXCLHASH_STATUS_OK != retProcess4Hash)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUXCLPKC_WAITFORFINISH();

    /* Finalize hash computation */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        mcuxClHash_finish_internal(pSession,
                                  pCtx,
                                  buffOutput,
                                  &outLength));
    if (pDomainParams->algoHash->hashSize != outLength)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_SignVerify_CalcHash,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish_internal));
}

/**
 * This function calculates the secret scalar H(prefix || (h_b,\dots,h_{2b-1}) || m') for EdDSA signature generation
 * using the hash function algoSecHash specified in the EdDSA domain parameters and stores the result in the concatenated
 * buffers ECC_S3 and ECC_T3 in a way that the first b bits of the hash are stored at the end of buffer ECC_S3.
 *
 * Input:
 *  - pSession          Handle for the current CL session
 *  - pDomainParams     Pointer to EdDSA domain parameters structure
 *  - mode              Pointer to EdDSA signature protocol descriptor
 *  - privKey           Private key handle
 *  - buffMessage       Buffer for message digest m'
 *  - messageSize       Size of m'
 *  - pOutput           Pointer to output of hash operation
 *
 * Result:
 *  - The result H(prefix || (h_b,\dots,h_{2b-1}) || m') is stored in the concatenated buffers ECC_S3 and ECC_T3
 *    with negative offset (-b/8) relative to the start of ECC_T3.
 *
 * NOTE: For Ed448, the hash output is of size MCUXCLHASH_OUTPUT_SIZE_SHA3_SHAKE_256, which is longer than the
 *       required 2b bits. The not needed upper part of the output shall be ignored or cleared by the caller.
 *
 * CPU workarea usage:
 * This function allocates and later frees CPU workarea memory for
 *  - a secure hash context
 *  - a hash context
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_CalcSecretScalar)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_CalcSecretScalar(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode,
    mcuxClKey_Handle_t privKey,
    mcuxCl_InputBuffer_t buffMessage,
    uint32_t messageSize,
    uint8_t *pOutput
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_CalcSecretScalar);

    uint32_t outLength = 0u;
    uint32_t privKeyHalfHashLength = (uint32_t) pDomainParams->b / 8u;

    MCUX_CSSL_DI_RECORD(hashProcess1Params, mode->hashPrefixLen);
    MCUX_CSSL_DI_RECORD(hashProcess2Params, privKeyHalfHashLength);
    MCUX_CSSL_DI_RECORD(hashProcess3Params, buffMessage);
    MCUX_CSSL_DI_RECORD(hashProcess3and4Params, messageSize);
    MCUX_CSSL_DI_RECORD(hashFinishParams, &outLength);


    /* Allocate context large enough for secure or non-secure hash operations */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Return pointer is 32-bit aligned and satisfies the requirement of mcuxClHash_Context_t");
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClHash_Context_t, pGenericHashCtx, mcuxClSession_allocateWords_cpuWa(pSession, mcuxClHash_getContextWordSize(pDomainParams->algoSecHash)));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()


    MCUX_CSSL_DI_RECORD(hashProcess1Params, pGenericHashCtx);
    MCUX_CSSL_DI_RECORD(hashProcess2Params, pGenericHashCtx);
    MCUX_CSSL_DI_RECORD(hashProcess3Params, pGenericHashCtx);

    /* Initialize the secure hash context */
    MCUX_CSSL_FP_FUNCTION_CALL(retInitHash, mcuxClHash_init(pSession, pGenericHashCtx, pDomainParams->algoSecHash) );
    if (MCUXCLHASH_STATUS_OK != retInitHash)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Update hash context with prefix */
    {
        MCUXCLBUFFER_INIT_RO(buffHashPrefix, NULL, mode->pHashPrefix, mode->hashPrefixLen);
        MCUX_CSSL_DI_RECORD(hashProcess1Params, buffHashPrefix);
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess1Hash, mcuxClHash_process_internal(pSession, pGenericHashCtx, buffHashPrefix, mode->hashPrefixLen) );
        if (MCUXCLHASH_STATUS_OK != retProcess1Hash)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }

    /* Update hash context with the private key half hash (h_b,...,h_{2b-1}) */
    uint8_t *pPrivKeyHalfHash = NULL;
    MCUXCLKEY_LOAD_FP(
      pSession,
      privKey,
      &pPrivKeyHalfHash,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
      NULL,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
      MCUXCLECC_ENCODING_SPEC_EDDSA_PRIVKEYHALFHASH_PTR);

    {
        MCUXCLBUFFER_INIT_RO(buffPrivKeyHalfHash, NULL, pPrivKeyHalfHash, privKeyHalfHashLength);
        MCUX_CSSL_DI_RECORD(hashProcess2Params, buffPrivKeyHalfHash);
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess2Hash, mcuxClHash_process_internal(pSession, pGenericHashCtx, buffPrivKeyHalfHash, privKeyHalfHashLength) );
        if (MCUXCLHASH_STATUS_OK != retProcess2Hash)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }

    /* Update hash context with m' */
    uint32_t messageSizeRemaining = messageSize;

    /* If the processed size so far is not a multiple of the effective secHash blocksize,
       process parts of m' in the secure hash context to clear the unprocessedBuffer in the context. */
    uint32_t blockSize = pDomainParams->algoSecHash->blockSize;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Addition cannot wrap, as mode->hashPrefixLen has at most a value of 10, and privKeyHalfHashLength has at most a value 57.")
    uint32_t numBytesInSecHashCtx = (mode->hashPrefixLen + privKeyHalfHashLength) % blockSize;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Subtraction cannot wrap as blockSize is in range [0, numBytesInSecHashCtx-1], and numBytesInSecHashCtx is not an overflowed value.")
    uint32_t sizeToProcessSecHash = MCUXCLCORE_MIN(((blockSize - numBytesInSecHashCtx) % blockSize), messageSizeRemaining);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* sizeToProcessSecHash is in [0, blockSize-1], so mcuxClHash_process_internal might be called with an inLength of 0 to avoid additional branching. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Variable sizeToProcessSecHash is not an overflowed value, all involed operations were save.")
    MCUX_CSSL_FP_FUNCTION_CALL(retProcess3Hash, mcuxClHash_process_internal(pSession, pGenericHashCtx, buffMessage, sizeToProcessSecHash) );
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    if (MCUXCLHASH_STATUS_OK != retProcess3Hash)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Variable sizeToProcessSecHash is not an overflowed value, all involed operations were save. Subtraction cannot overflow.")
    messageSizeRemaining -= sizeToProcessSecHash;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    mcuxClHash_ContextDescriptor_t *pCurrentHashContext = pGenericHashCtx;
    if(messageSizeRemaining > 0u)
    {

        /* Process the remaining bytes in m', if any left */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Variable sizeToProcessSecHash is not an overflowed value, all involed operations were save.")
        MCUXCLBUFFER_DERIVE_RO(buffMessageWithOffset, buffMessage, sizeToProcessSecHash);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_DI_RECORD(hashProcess4Params, pCurrentHashContext);
        MCUX_CSSL_DI_RECORD(hashProcess4Params, buffMessageWithOffset);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Variable messageSizeRemaining is not an overflowed value, all involved operations were save")
        MCUX_CSSL_FP_FUNCTION_CALL(retProcess4Hash, mcuxClHash_process_internal(pSession, pCurrentHashContext, buffMessageWithOffset, messageSizeRemaining) );
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        if (MCUXCLHASH_STATUS_OK != retProcess4Hash)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }

    MCUXCLPKC_WAITFORFINISH();
    {
        /* Create hash output buffer of size 2*bufferSize which is large enough for the use cases
         *  - Ed25519, in which 64 bytes are needes
         *  - Ed448, in which case MCUXCLHASH_OUTPUT_SIZE_SHA3_SHAKE_256 are needed. */
        const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
        const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
        MCUXCLBUFFER_INIT(buffOutput, NULL, pOutput, 2u * bufferSize);
        (void) bufferSize;
        MCUX_CSSL_DI_RECORD(hashFinishParams, buffOutput);
        MCUX_CSSL_DI_RECORD(hashFinishParams, pCurrentHashContext);

        /* Finalite hash computation */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHash_finish_internal(pSession, pCurrentHashContext, buffOutput, &outLength) );
        if(pDomainParams->algoSecHash->hashSize != outLength)
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }

    /* Free the hash contexts */
    mcuxClSession_freeWords_cpuWa(pSession, mcuxClHash_getContextWordSize(pDomainParams->algoSecHash));


    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_CalcSecretScalar,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),
        MCUXCLKEY_LOAD_FP_CALLED(privKey),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal),
        MCUX_CSSL_FP_CONDITIONAL((messageSizeRemaining > 0u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish_internal));
}


/**
 * This function calculates the hash H(prefix||Renc||Qenc||m') mod n using the hash function algoHash
 * specified in the EdDSA domain parameters.
 *
 * Input:
 *  - pSession          Handle for the current CL session
 *  - pDomainParams     Pointer to ECC common domain parameters structure
 *  - pHashPrefix       Pointer to prefix
 *  - hashPrefixLen     Byte length of prefix
 *  - pSignatureR       Buffer for Renc
 *  - pubKey            Key handle for public key Qenc
 *  - pIn               Buffer for input for hash algorithm
 *  - inSize            Size of pIn
 *
 * Prerequisites:
 * - ps1Len = (operandSize, operandSize)
 * - Buffer ECC_NFULL contains n'||n
 * - Buffer ECC_N contains n
 *
 * Result:
 *  - The result H(prefix||Renc||Qenc||m') mod n is stored in buffer ECC_S2 in NR
 *
 * CPU workarea usage:
 * This function allocates and later frees CPU workarea memory for
 *  - a hash context
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_CalcHashModN)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_CalcHashModN(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    const uint8_t *pHashPrefix,
    uint32_t hashPrefixLen,
    mcuxCl_InputBuffer_t pSignatureR,
    mcuxClKey_Handle_t pubKey,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_CalcHashModN);

    /* Step 1: Calculate the hash value H(prefix||Renc||Qenc||m') and store it in the consecutive buffers ECC_S2 and ECC_T2. */
    /* Encoded length = M = 32-byte for Ed25519 (b = 256 = 32*8) */
    /*                   or 57-byte for Ed448 (b = 456 = 57*8).  */
    const uint32_t encodedLen = (uint32_t) pDomainParams->b / 8u;
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pS2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);

    /* Derive the pointer to the public key data */
    uint8_t *pPubKey = NULL;
    MCUXCLKEY_LOAD_FP(
      pSession,
      pubKey,
      &pPubKey,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
      NULL,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
      MCUXCLKEY_ENCODING_SPEC_ACTION_PTR);

    /* Allocate space for hash context buffer in CPU workarea */
    uint32_t hashContextSizeInWords = mcuxClHash_getContextWordSize(pDomainParams->algoHash);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Return pointer is 32-bit aligned and satisfies the requirement of mcuxClHash_Context_t");
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClHash_Context_t, pHashCtx, mcuxClSession_allocateWords_cpuWa(pSession, mcuxClHash_getContextWordSize(pDomainParams->algoHash)));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Calculate 2b-bit hash of (prefix||Renc||Qenc||m'). */
    MCUXCLBUFFER_INIT(buffS2, NULL, pS2, 2u * encodedLen);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_SignVerify_CalcHash(pSession,
                                              pDomainParams,
                                pHashCtx,
                                pHashPrefix, hashPrefixLen,
                                pSignatureR, encodedLen,
                                pPubKey, encodedLen,
                                pIn, inSize,
                                buffS2));

    /* Free the hash context */
    mcuxClSession_freeWords_cpuWa(pSession, hashContextSizeInWords);

    /* Clear after byteLen(h) counting from ECC_S2 with 0's, so ECC_S2 and ECC_T2 will only contain h and afterwards
     * modular reduction can be done.
     *
     * NOTE: This will clear potential data in memory after the hash,
     *       but for Ed448 it is needed because SHAKE256 returns a hash larger than 114 bytes. */
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
    uint32_t byteLenH = (uint32_t) pDomainParams->b/4u;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("bytesToClear will be in the range [0 ~ bufferSize].")
    const uint32_t bytesToClear = bufferSize - (byteLenH % bufferSize);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, (uint32_t)&pS2[byteLenH] + bytesToClear);
    MCUXCLMEMORY_CLEAR_INT(&pS2[byteLenH], bytesToClear);

    /* Step 2: Use the PKC to calculate H(prefix||Renc||Qenc||m') mod n, and store the result in ECC_S2. */
    /* Calculate the Montgomery parameter Q' = 2 ^ (8*(operandSize + bufferSize)) mod n and store it in ECC_T1
     *
     * NOTE: The scalar r is of byte length b/4, i.e. we have, irrespective of the underlying PKC word size
     *        - for Ed25519: byteLen(h) = 64  = 2*operandSize < operandSize + bufferSize
     *        - for Ed448:   byteLen(h) = 114 < operandSize + bufferSize.
     *       Thus, we can obtain h mod n by a multiplication of h (considered as operand of size
     *       (operandSize + bufferSize)) with Q' modulo n
     *      Which is:
     *      MM(H(..), 2^(8*(operandSize(H(..)))), n) = H(..) * 2^(8*(operandSize(H(..)))) * 2^(-8*(operandSize(H(..)))) mod n
     *                                               = H(..) mod n
     *      with: operandSize(H(..)) = operandSize + bufferSize = operandSize + operandSize + PKC_WORDSIZE */
    const uint8_t *pT1 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T1]);
    MCUXCLPKC_WAITFORREADY();
    pOperands[ECC_V0] = MCUXCLPKC_PTR2OFFSET(&pT1[MCUXCLPKC_WORDSIZE]);
    MCUXCLPKC_PS2_SETLENGTH(operandSize + bufferSize, operandSize);
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN,
                        mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN_LEN);

    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_CalcHashModN,
        MCUXCLKEY_LOAD_FP_CALLED(pubKey),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_SignVerify_CalcHash),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}
