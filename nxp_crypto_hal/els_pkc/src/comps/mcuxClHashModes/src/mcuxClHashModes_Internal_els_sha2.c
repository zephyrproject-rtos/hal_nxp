/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

#include <mcuxClToolchain.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClEls.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClHashModes_Core_els_sha2.h>
#include <internal/mcuxClSession_Internal.h>
#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
#include <mcuxClPkc_Types.h>
#include <internal/mcuxClPkc_Macros.h>
#endif

/**********************************************************
 * Constants
 **********************************************************/
/* IV taken from: nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf (Big-Endian Representation) */
const static ALIGNED uint8_t mcuxClHashModes_els_sha512_224_iv[MCUXCLHASH_STATE_SIZE_SHA_512] =
{
    0x8cu, 0x3du, 0x37u, 0xc8u, 0x19u, 0x54u, 0x4du, 0xa2u,
    0x73u, 0xe1u, 0x99u, 0x66u, 0x89u, 0xdcu, 0xd4u, 0xd6u,
    0x1du, 0xfau, 0xb7u, 0xaeu, 0x32u, 0xffu, 0x9cu, 0x82u,
    0x67u, 0x9du, 0xd5u, 0x14u, 0x58u, 0x2fu, 0x9fu, 0xcfu,
    0x0fu, 0x6du, 0x2bu, 0x69u, 0x7bu, 0xd4u, 0x4du, 0xa8u,
    0x77u, 0xe3u, 0x6fu, 0x73u, 0x04u, 0xc4u, 0x89u, 0x42u,
    0x3fu, 0x9du, 0x85u, 0xa8u, 0x6au, 0x1du, 0x36u, 0xc8u,
    0x11u, 0x12u, 0xe6u, 0xadu, 0x91u, 0xd6u, 0x92u, 0xa1u
};

/* IV taken from: nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf (Big-Endian Representation) */
const static ALIGNED uint8_t mcuxClHashModes_els_sha512_256_iv[MCUXCLHASH_STATE_SIZE_SHA_512] =
{
    0x22u, 0x31u, 0x21u, 0x94u, 0xfcu, 0x2bu, 0xf7u, 0x2cu,
    0x9fu, 0x55u, 0x5fu, 0xa3u, 0xc8u, 0x4cu, 0x64u, 0xc2u,
    0x23u, 0x93u, 0xb8u, 0x6bu, 0x6fu, 0x53u, 0xb1u, 0x51u,
    0x96u, 0x38u, 0x77u, 0x19u, 0x59u, 0x40u, 0xeau, 0xbdu,
    0x96u, 0x28u, 0x3eu, 0xe2u, 0xa8u, 0x8eu, 0xffu, 0xe3u,
    0xbeu, 0x5eu, 0x1eu, 0x25u, 0x53u, 0x86u, 0x39u, 0x92u,
    0x2bu, 0x01u, 0x99u, 0xfcu, 0x2cu, 0x85u, 0xb8u, 0xaau,
    0x0eu, 0xb7u, 0x2du, 0xdcu, 0x81u, 0xc5u, 0x2cu, 0xa2u
};

/**********************************************************
 * Helper functions
 **********************************************************/

/* Writes the correct RTF flags to the hashOptions struct, based on the rtf parameter */
static inline mcuxClHash_Status_t mcuxClHashModes_els_selectRtfFlags(mcuxClSession_Rtf_t rtf,
                                                              mcuxClEls_HashOption_t *hashOptions)
{
    /* Set RTF processing options */
    if(MCUXCLSESSION_RTF_UPDATE_TRUE == rtf)
    {
        hashOptions->bits.rtfupd = MCUXCLELS_HASH_RTF_UPDATE_ENABLE;
    }
    else if(MCUXCLSESSION_RTF_UPDATE_FALSE == rtf)
    {
        hashOptions->bits.rtfupd = MCUXCLELS_HASH_RTF_UPDATE_DISABLE;
    }
    else
    {
        return MCUXCLHASH_STATUS_FAULT_ATTACK;
    }
    return MCUXCLHASH_STATUS_OK;
}

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_els_dmaProtectionAddressReadback)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_els_dmaProtectionAddressReadback(uint8_t * startAddress,
                                                                                             size_t expectedLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_els_dmaProtectionAddressReadback,
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_CompareDmaFinalOutputAddress));

    MCUX_CSSL_FP_FUNCTION_CALL(result, mcuxClEls_CompareDmaFinalOutputAddress(startAddress, expectedLength));

    if (MCUXCLELS_STATUS_OK != result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_dmaProtectionAddressReadback, MCUXCLHASH_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_dmaProtectionAddressReadback, MCUXCLHASH_STATUS_OK);
}
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

/**
 * @brief Prepare ELS for truncated Sha2 computation
 *
 * For truncated Sha2 algorithms we need to start the ELS computation with hashld enabled and hashini disabled, to load the IV of the truncated algorithm.
 * Such ELS configurations are intended to continue a (multipart) computation, not start a new computation.
 * Without a prior ELS computation with hashini enabled, the output of the ELS is undefined.
 * By hashing a single block of unrelated data and discarding the result with hashini enabled and hashld disabled, we can get the ELS into
 * a defined state, needed to start the actual Sha2_512/224 or Sha2_512/256 computation.
 *
 *
 * @param[in]       session           current session
 * @param[in]       algorithm         contains information about the hash algorithm
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[out]      pOutput           Memory to store the IV
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_Sha2_Prepare_Truncated)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_Sha2_Prepare_Truncated (
                                    mcuxClSession_Handle_t session,
                                    mcuxClHash_Algo_t algorithm,
                                    mcuxClEls_HashOption_t *pHashOptions,
                                    uint8_t *pOutput
                                    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_Sha2_Prepare_Truncated);

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /* Start setting initial options for ELS hash: Warmup parameters */
    pHashOptions->bits.hashoe = MCUXCLELS_HASH_OUTPUT_ENABLE;
    pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_ENABLE;
    pHashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE;
    pHashOptions->bits.rtfupd = MCUXCLELS_HASH_RTF_UPDATE_DISABLE; /* No RTF support for truncated modes */
    pHashOptions->bits.rtfoe = MCUXCLELS_HASH_RTF_OUTPUT_DISABLE; /* No RTF support for truncated modes */

    /* Buffer in CPU WA for ELS warmup input. Does not need to be initialized with meaningful data. */
    uint8_t *pWarmupInput = (uint8_t *) mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
    if(NULL == pWarmupInput)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_Sha2_Prepare_Truncated, MCUXCLHASH_STATUS_FAILURE);
    }

    /* Perform an ELS Hash computation on any block of data and discard the result to get the ELS into a stable state. */
    MCUX_CSSL_FP_FUNCTION_CALL(resultElsCoreWarmup, algorithmDetails->els_core(pHashOptions->word.value,
                                                    pWarmupInput,
                                                    algorithm->blockSize,
                                                    pOutput));  /* pOutput is used as a temp buffer. The result is not used and overwritten later. */
    if (MCUXCLHASH_STATUS_OK != resultElsCoreWarmup)
    {
        /* Free workarea (pWarmupInput) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_Sha2_Prepare_Truncated, resultElsCoreWarmup,
            algorithmDetails->protection_token_els_core);
    }

    /* Free workarea (pWarmupInput) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));

    /* Update options for ELS: Prepare for loading custom IV for truncated modes. */
    pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
    pHashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_ENABLE;

    /* Prepare the IV to be imported by ELS */
    MCUXCLMEMORY_FP_MEMORY_COPY(pOutput, algorithmDetails->standardIV, algorithm->stateSize);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_Sha2_Prepare_Truncated, MCUXCLHASH_STATUS_OK,
            algorithmDetails->protection_token_els_core,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy));
}

/**
 * @brief Processing of full blocks via ELS
 *
 * This function processes full blocks of input data.
 * It is used for both truncated and non-truncated hash algorithms.
 *
 * @param[in]       session           current session
 * @param[in]       algorithm         contains information about the hash algorithm
 * @param[in]       pIn               user input
 * @param[in]       inSize            total size of user input
 * @param[in]       sizeOfFullBlocks  smallest multiple of block size that is not bigger than inSize
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[in]       pIV               pointer to IV, only needed for truncated modes. Might be NULL for non-truncated modes
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_oneShot_Sha2_FullBlocks (
                                    mcuxClSession_Handle_t session,
                                    mcuxClHash_Algo_t algorithm,
                                    mcuxCl_InputBuffer_t pIn,
                                    uint32_t inSize,
                                    size_t sizeOfFullBlocks,
                                    mcuxClEls_HashOption_t *pHashOptions,
                                    uint8_t *pIV
                                    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks);

#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
    const bool isInputInPKC =
         (((uint32_t) pIn + inSize)> (uint32_t) MCUXCLPKC_RAM_START_ADDRESS)
         && ((uint32_t) pIn < ((uint32_t) MCUXCLPKC_RAM_START_ADDRESS + MCUXCLPKC_RAM_SIZE));
#endif

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    if (0u < sizeOfFullBlocks)
    {
        pHashOptions->bits.hashoe = MCUXCLELS_HASH_OUTPUT_DISABLE; /* Disable hash output generation, as we do not need to update an external state in oneshot */
#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
        /* Check if pIn is in PKC workarea. */
        if (false != isInputInPKC)
        {
            /* Allocate buffer in CPU WA to copy the input block of data from PKC WA */
            uint8_t * pInCpu = (uint8_t *) mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
            if(NULL == pInCpu)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks, MCUXCLHASH_STATUS_FAILURE);
            }

            uint32_t processedIn = 0u;
            /* Process all input blocks. processedIn will be increased by the blockSize until all blocks are processed. */
            while(processedIn < sizeOfFullBlocks)
            {
                MCUXCLMEMORY_FP_MEMORY_COPY(pInCpu, &pIn[processedIn], algorithm->blockSize);
                MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("sizeOfFullBlocks is a multiple of algorithm->blockSize, so processedIn cannot overflow by adding the blockSize in this loop.")
                processedIn += algorithm->blockSize;
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
                MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                                pInCpu,
                                                                algorithm->blockSize,
                                                                pIV));  /* pIV is prefilled with IV for truncated modes. If needed and not done before, this will be set as ELS custom IV here. */
                if (MCUXCLHASH_STATUS_OK != resultElsCore)
                {
                    /* Free workarea (pInCpu) and exit */
                    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks, resultElsCore,
                        (processedIn / algorithm->blockSize)  *
                           (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
                            + algorithmDetails->protection_token_els_core)
                        );
                }
                pHashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE; /* Disable custom IV loading, as IV for truncated modes is now loaded. */
                pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE; /* Disable initialization for non-truncated modes */
            }
            /* Free workarea (pInCpu) */
            mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
        }
        else
        {
            MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                           pIn,
                                                           sizeOfFullBlocks,
                                                           pIV)); /* pIV is prefilled with IV for truncated modes. If needed and not done before, this will be set as ELS custom IV here. */
            if (MCUXCLHASH_STATUS_OK != resultElsCore)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks, resultElsCore,
                    algorithmDetails->protection_token_els_core);
            }
            pHashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE; /* Disable custom IV loading, as IV for truncated modes is now loaded. */
            pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE; /* Disable initialization for non-truncated modes */
        }
#else
        MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                       pIn,
                                                       sizeOfFullBlocks,
                                                       pIV)); /* pIV is prefilled with IV for truncated modes. If needed and not done before, this will be set as ELS custom IV here. */
        if (MCUXCLHASH_STATUS_OK != resultElsCore)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks, resultElsCore,
                            algorithmDetails->protection_token_els_core);
        }
        pHashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE; /* Disable custom IV loading, as IV for truncated modes is now loaded. */
        pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE; /* Disable initialization for non-truncated modes */
#endif
    }

    /* Balance FP and exit */
#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((0u != sizeOfFullBlocks),
            MCUX_CSSL_FP_CONDITIONAL(isInputInPKC,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                algorithmDetails->protection_token_els_core)
            * (sizeOfFullBlocks / algorithm->blockSize),
            MCUX_CSSL_FP_CONDITIONAL(!isInputInPKC,
                algorithmDetails->protection_token_els_core))
    );
#else
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((0u != sizeOfFullBlocks),
            algorithmDetails->protection_token_els_core));
#endif
}

/**
 * @brief Performs padding of the last block
 *
 * This function appends padding to the input data.
 * It is used for both truncated and non-truncated hash algorithms.
 *
 * @param[in]       session           current session
 * @param[in]       algorithm         contains information about the hash algorithm
 * @param[in]       pIn               user input
 * @param[in]       inSize            total size of user input
 * @param[in]       sizeOfFullBlocks  smallest multiple of block size that is not bigger than inSize
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[in]       pIV               pointer to IV, only needed for truncated modes. Might be NULL for non-truncated modes
 * @param[out]      shablock          memory to put the padded block
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_oneShot_Sha2_Padding)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_oneShot_Sha2_Padding (
                                    mcuxClSession_Handle_t session,
                                    mcuxClHash_Algo_t algorithm,
                                    mcuxCl_InputBuffer_t pIn,
                                    uint32_t inSize,
                                    size_t sizeOfFullBlocks,
                                    mcuxClEls_HashOption_t *pHashOptions,
                                    uint8_t *pIV,
                                    uint8_t *shablock
                                    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_oneShot_Sha2_Padding);

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(sizeOfFullBlocks, 0u, inSize, MCUXCLHASH_STATUS_FAILURE)
    size_t posdst = inSize - sizeOfFullBlocks;
    size_t buflen = algorithm->blockSize;

    /* Copy the data to the buffer in the workspace. */
    MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(shablock, &pIn[sizeOfFullBlocks], posdst, buflen);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->blockSize, MCUXCLHASH_BLOCK_SIZE_SHA_224, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLHASH_STATUS_FAILURE)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(posdst, 0u, (algorithm->blockSize-1u), MCUXCLHASH_STATUS_FAILURE)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(buflen, MCUXCLHASH_BLOCK_SIZE_SHA_224, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLHASH_STATUS_FAILURE)
    buflen -= posdst;

    /* add first byte of the padding: (remaining) < (block length) so there is space in the buffer */
    shablock[posdst] = 0x80u;
    posdst += 1u;

    buflen -= 1u;

    /* Process partial padded block if needed */
    if ( (algorithm->blockSize - algorithm->counterSize) < posdst ) // need room for 64 bit counter and one additional byte
    {
        MCUXCLMEMORY_FP_MEMORY_SET(&shablock[posdst], 0x00, buflen);

        /* It is currently necessary to set buflen to algorithm->blockSize to distinguish whether this if-branch was taken
         * (for the conditional expectations in the exit statement!). Otherwise we could set it to posdst here and save
         * some performance overhead */
        buflen = algorithm->blockSize;
        posdst = 0u;

        MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                              shablock,
                                                              algorithm->blockSize,
                                                              pIV)); /* pIV is prefilled with IV for truncated modes. If needed and not done before, this will be set as ELS custom IV here. */

        if (MCUXCLHASH_STATUS_OK != resultElsCore)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Padding, resultElsCore,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
                algorithmDetails->protection_token_els_core);
        }

        pHashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE; /* Disable custom IV loading, as IV for truncated modes is now loaded. */
        pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE; /* Disable initialization for non-truncated modes */
    }

    /* Perform padding by adding data counter */
    MCUXCLMEMORY_FP_MEMORY_SET(&shablock[posdst], 0x00, buflen);
    posdst = algorithm->blockSize;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("posdst-4 is always bigger than 1.");
    shablock[--posdst] = (uint8_t)((inSize <<  3u) & 0xFFu);
    shablock[--posdst] = (uint8_t)((inSize >>  5u) & 0xFFu);
    shablock[--posdst] = (uint8_t)((inSize >> 13u) & 0xFFu);
    shablock[--posdst] = (uint8_t)((inSize >> 21u) & 0xFFu);
    shablock[posdst - 1u] = (uint8_t)((inSize >> 29u) & 0xFFu);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* Set output options */
    pHashOptions->bits.hashoe  = MCUXCLELS_HASH_OUTPUT_ENABLE;
    pHashOptions->bits.rtfoe = pHashOptions->bits.rtfupd;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Padding, MCUXCLHASH_STATUS_OK,
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                                MCUX_CSSL_FP_CONDITIONAL((buflen == algorithm->blockSize),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
                                    algorithmDetails->protection_token_els_core),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set));
}

/**********************************************************
 * *INTERNAL* layer functions
 **********************************************************/

/**
 * @brief Performs process full data blocks and pad last blocks
 *
 * Step 2: Process full blocks of input data
 * Step 3: Pad the input data and process last block
 *
 * @pre
 *  - Step 1: Set ELS options for initialization, continuation from external state, or from internal state
 *
 * @post
 *  - Processed all input data
 *  - Allocated memory for last paded block in 'shablock'
 *
 * @param[in]       session           current session
 * @param[in]       algorithm         contains information about the hash algorithm
 * @param[in]       pIn               user input
 * @param[in]       inSize            total size of user input
 * @param[in]       sizeOfFullBlocks  smallest multiple of block size that is not bigger than inSize
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[out]      shablock          memory to put the padded block
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_oneShot_Sha2_ProcessData)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_oneShot_Sha2_ProcessData (
                                    mcuxClSession_Handle_t session,
                                    mcuxClHash_Algo_t algorithm,
                                    mcuxCl_InputBuffer_t pIn,
                                    uint32_t inSize,
                                    size_t sizeOfFullBlocks,
                                    mcuxClEls_HashOption_t *pHashOptions,
                                    uint8_t **shablock
                                    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_oneShot_Sha2_ProcessData);

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /**************************************************************************************
     * Step 2: Process full blocks of input data
     **************************************************************************************/
    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(resultHandleFullBlocks, mcuxClHashModes_Els_oneShot_Sha2_FullBlocks(
                    session,
                    algorithm,
                    pIn,
                    inSize,
                    sizeOfFullBlocks,
                    pHashOptions,
                    NULL)); /* Parameter not needed for non-truncated modes. */
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
    if (MCUXCLHASH_STATUS_OK != resultHandleFullBlocks)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_ProcessData, resultHandleFullBlocks,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks)
        );
    }

    /* Balance SC of step 2 now, for easier balancing of early exits */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks));

    /**************************************************************************************
     * Step 3: Pad the input data and process last block
     **************************************************************************************/

    /* Buffer in CPU WA to store the last block of data in the finalization phase */
    *shablock = (uint8_t *) mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
    if(NULL == *shablock)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_ProcessData, MCUXCLHASH_STATUS_FAILURE);
    }

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(resultHandlePadding, mcuxClHashModes_Els_oneShot_Sha2_Padding(
                    session,
                    algorithm,
                    pIn,
                    inSize,
                    sizeOfFullBlocks,
                    pHashOptions,
                    NULL,   /* Parameter not needed for non-truncated modes. */
                    *shablock));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
    if (MCUXCLHASH_STATUS_OK != resultHandlePadding)
    {
        /* Free workarea (shablock) and exit */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_ProcessData, resultHandlePadding,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding)
        );
    }

    /* Process last block */
    MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                 *shablock,
                                                 algorithm->blockSize,
                                                 *shablock /* shablock is large enough to hold internal state of hash algorithm + RTF */));

    if (MCUXCLHASH_STATUS_OK != resultElsCore)
    {
        /* Free workarea (shablock) and exit */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_ProcessData, resultElsCore,
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding),
                                  algorithmDetails->protection_token_els_core);
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    uint32_t rtfSize = 0u;
    rtfSize = (MCUXCLSESSION_RTF_UPDATE_TRUE == session->rtf) ? algorithmDetails->rtfSize : 0u;
    if(NULL != algorithmDetails->dmaProtection)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(resultDma, algorithmDetails->dmaProtection(*shablock,
                                                                      algorithm->stateSize + rtfSize));

        if (MCUXCLHASH_STATUS_OK != resultDma)
        {
            /* Free workarea (shablock) and exit */
            mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_ProcessData, resultDma,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding),
                algorithmDetails->protection_token_els_core,
                algorithmDetails->protection_token_dma_protection);
        }
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */


    MCUX_CSSL_FP_COUNTER_STMT(uint32_t scBalance = 0u);

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_COUNTER_STMT(scBalance += (algorithmDetails->protection_token_dma_protection));
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */


    /* Set expectations and exit */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_ProcessData, MCUXCLHASH_STATUS_OK,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding),
                scBalance,
                algorithmDetails->protection_token_els_core);
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_oneShot_Sha2, mcuxClHash_AlgoSkeleton_OneShot_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_oneShot_Sha2 (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Algo_t algorithm,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_oneShot_Sha2);

    /* Check on outSize */
    if(*pOutSize > (UINT32_MAX - algorithm->hashSize))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2, MCUXCLHASH_STATUS_INVALID_PARAMS);
    }

    /**************************************************************************************
     * Step 1: Set ELS options for initialization, continuation from external state, or from
     * internal state
     **************************************************************************************/

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /* Start setting initial options for ELS hash */
    mcuxClEls_HashOption_t hashOptions = algorithmDetails->hashOptions;
    hashOptions.bits.hashoe = MCUXCLELS_HASH_OUTPUT_DISABLE;
    hashOptions.bits.hashini = MCUXCLELS_HASH_INIT_ENABLE;
    hashOptions.bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE;

    /* Set RTF processing options */
    if(MCUXCLHASH_STATUS_OK != mcuxClHashModes_els_selectRtfFlags(session->rtf, &hashOptions))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2, MCUXCLHASH_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->blockSize, MCUXCLHASH_BLOCK_SIZE_SHA_224, MCUXCLHASH_BLOCK_SIZE_SHA_512, MCUXCLHASH_STATUS_FAILURE)
    size_t const numberOfFullBlocks = (inSize / algorithm->blockSize);
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(numberOfFullBlocks, 0u, (UINT32_MAX / MCUXCLHASH_BLOCK_SIZE_SHA_224), MCUXCLHASH_STATUS_FAILURE)
    size_t const sizeOfFullBlocks = numberOfFullBlocks * algorithm->blockSize;

    /**************************************************************************************
     * Step 2: Process full blocks of input data
     * Step 3: Pad the input data and process last block
     **************************************************************************************/
    uint8_t *shablock = NULL;
    MCUX_CSSL_FP_FUNCTION_CALL(resultProcessData, mcuxClHashModes_Els_oneShot_Sha2_ProcessData(
            session,
            algorithm,
            pIn,
            inSize,
            sizeOfFullBlocks,
            &hashOptions,
            &shablock
    ));
    if (MCUXCLHASH_STATUS_OK != resultProcessData)
    {
        /* Free workarea (pOutput) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2, resultProcessData,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_ProcessData));
    }
    /**************************************************************************************
     * Step 4: Copy result to output buffers
     **************************************************************************************/

    /* Copy RTF to corresponding buffer */
    if((MCUXCLSESSION_RTF_UPDATE_TRUE == session->rtf) && (NULL != session->pRtf))
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("shablock was properly initialized during function mcuxClHashModes_Els_oneShot_Sha2_ProcessData. It is not NULL.")
        MCUXCLMEMORY_FP_MEMORY_COPY(session->pRtf, &shablock[algorithm->hashSize], algorithmDetails->rtfSize);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
    }

    /* Copy hash digest to output buffer */
    MCUXCLMEMORY_FP_MEMORY_COPY(pOut, shablock, algorithm->hashSize);
    *pOutSize += algorithm->hashSize;

    /* Free workarea (shablock) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));


    MCUX_CSSL_FP_COUNTER_STMT(uint32_t scBalance = 0u);

MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Flow protections checks the result modulo 2^32 so that a potential overflow does not change the result")
    MCUX_CSSL_FP_COUNTER_STMT(scBalance += MCUX_CSSL_FP_CONDITIONAL((MCUXCLSESSION_RTF_UPDATE_TRUE == session->rtf), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)));
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* Set expectations and exit */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2, MCUXCLHASH_STATUS_OK,
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_ProcessData),
                                scBalance,
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_oneShot_Sha2_Truncated, mcuxClHash_AlgoSkeleton_OneShot_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_oneShot_Sha2_Truncated (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Algo_t algorithm,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_oneShot_Sha2_Truncated);

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /* Validate that the given input does not overflow */
    if(*pOutSize > (UINT32_MAX - algorithm->hashSize))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, MCUXCLHASH_STATUS_INVALID_PARAMS);
    }

    /**************************************************************************************
     * Step 1: Prepare the ELS to accept a custom IV for truncated SHA-512/224, SHA512/256
     **************************************************************************************/

    /* Buffer in CPU WA for ELS warmup, to input the IV and to store the digest in the finalization phase */
    uint8_t *pOutput = (uint8_t *) mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
    if(NULL == pOutput)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, MCUXCLHASH_STATUS_FAILURE);
    }

    mcuxClEls_HashOption_t hashOptions = algorithmDetails->hashOptions;

    MCUX_CSSL_FP_FUNCTION_CALL(resultElsPrepare, mcuxClHashModes_Els_Sha2_Prepare_Truncated(
            session,
            algorithm,
            &hashOptions,
            pOutput
    ));
    if (MCUXCLHASH_STATUS_OK != resultElsPrepare)
    {
        /* Free workarea (pOutput) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, resultElsPrepare,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated));
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("False positive, this operation cannot wrap.")
    size_t const sizeOfFullBlocks = (inSize / algorithm->blockSize) * algorithm->blockSize;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /**************************************************************************************
     * Step 2: Process full blocks of input data
     **************************************************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(resultHandleFullBlocks, mcuxClHashModes_Els_oneShot_Sha2_FullBlocks(
                    session,
                    algorithm,
                    pIn,
                    inSize,
                    sizeOfFullBlocks,
                    &hashOptions,
                    pOutput));
    if (MCUXCLHASH_STATUS_OK != resultHandleFullBlocks)
    {
        /* Free workarea (pOutput) and exit */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, resultHandleFullBlocks,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks)
        );
    }

    /* Balance SC of step 1 & 2 now, for easier balancing of early exits */
    MCUX_CSSL_FP_EXPECT(
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_FullBlocks)
    );

    /**************************************************************************************
     * Step 3: Pad the input data and process last block
     **************************************************************************************/

    /* Buffer in CPU WA to store the last block of data in the finalization phase */
    uint8_t *shablock = (uint8_t *) mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
    if(NULL == shablock)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, MCUXCLHASH_STATUS_FAILURE);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(resultHandlePadding, mcuxClHashModes_Els_oneShot_Sha2_Padding(
                    session,
                    algorithm,
                    pIn,
                    inSize,
                    sizeOfFullBlocks,
                    &hashOptions,
                    pOutput,
                    shablock));
    if (MCUXCLHASH_STATUS_OK != resultHandlePadding)
    {
        /* Free workarea (shablock + poutput) and exit */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize) + MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, resultHandlePadding,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding)
        );
    }

    /* Process last block */
    MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(hashOptions.word.value,
                                                 shablock,
                                                 algorithm->blockSize,
                                                 pOutput)); /* pOutput is prefilled with IV for truncated modes. If not done before, this will be set as ELS custom IV here. */

    if (MCUXCLHASH_STATUS_OK != resultElsCore)
    {
        /* Free workarea (shablock + poutput) and exit */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize) + MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, resultElsCore,
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding),
                                  algorithmDetails->protection_token_els_core);
    }

    /* Free workarea (shablock)*/
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    if(NULL != algorithmDetails->dmaProtection)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(resultDma, algorithmDetails->dmaProtection(pOutput,
                                                                      algorithm->stateSize));
        if (MCUXCLHASH_STATUS_OK != resultDma)
        {
            /* Free workarea (pOutput) and exit */
            mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, resultDma, resultDma,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding),
                algorithmDetails->protection_token_els_core,
                algorithmDetails->protection_token_dma_protection);
        }
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    /**************************************************************************************
     * Step 4: Copy result to output buffers
     **************************************************************************************/

    /* Copy truncated hash digest to output buffer */
    MCUXCLMEMORY_FP_MEMORY_COPY(pOut, pOutput, algorithm->hashSize);
    *pOutSize += algorithm->hashSize;

    /* Free workarea (pOutput) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->stateSize));


    MCUX_CSSL_FP_COUNTER_STMT(uint32_t scBalance = 0u);

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_COUNTER_STMT(scBalance +=  (algorithmDetails->protection_token_dma_protection));
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

        /* Set expectations and exit */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_oneShot_Sha2_Truncated, MCUXCLHASH_STATUS_OK,
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Padding),
                                    algorithmDetails->protection_token_els_core,
                                    scBalance,
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy));
}


static uint32_t getProcessContextBuffer_token(mcuxClHash_Context_t context,
                                              uint32_t inSize)
{
    const mcuxClHash_AlgorithmDescriptor_t * algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const size_t algoBlockSize = algorithm->blockSize;
    /* When some data is in context and new data from input can fill entire context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("does not wrap since unprocessedLength in context does not exceed algorithm block size")
    bool isBlockProcessedFromContext = (0u != context->unprocessedLength) && (inSize >= (algoBlockSize - context->unprocessedLength));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Flow protections checks the result modulo 2^32 so that a potential overflow does not change the result")
    #ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        return MCUX_CSSL_FP_CONDITIONAL(isBlockProcessedFromContext,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            algorithmDetails->protection_token_els_core,
            algorithmDetails->protection_token_dma_protection);
    #else
        return MCUX_CSSL_FP_CONDITIONAL(isBlockProcessedFromContext,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            algorithmDetails->protection_token_els_core);
    #endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}


static uint32_t getProcessNewInput_token(mcuxClHash_Context_t context,
                                        mcuxCl_InputBuffer_t pIn,
                                        uint32_t inSize)
{
    const mcuxClHash_AlgorithmDescriptor_t * algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Flow protections checks the result modulo 2^32 so that a potential overflow does not change the result")
#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
    const bool isInputInPKC =
        (((uint32_t) pIn + inSize) > (uint32_t) MCUXCLPKC_RAM_START_ADDRESS)
        && ((uint32_t) pIn < ((uint32_t) MCUXCLPKC_RAM_START_ADDRESS + MCUXCLPKC_RAM_SIZE));
    const size_t algoBlockSize = context->algo->blockSize;
    uint32_t unprocessedInputLength = inSize;
    /* When some data is in context and new data from input can fill entire context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("unprocessedLength in context does not exceed algorithm block size")
    uint32_t unprocessedEmptyLength = algoBlockSize - context->unprocessedLength;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    if((0u != context->unprocessedLength) && (inSize >= unprocessedEmptyLength))
    {
        unprocessedInputLength -= unprocessedEmptyLength;
    }
    /* The amount of unprocessed data that fills complete blocks */
    uint32_t unprocessedCompleteInputBlocks = unprocessedInputLength / algoBlockSize;

    uint32_t processNewInput_token =  MCUX_CSSL_FP_CONDITIONAL(false != isInputInPKC,
                                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                                                algorithmDetails->protection_token_els_core)
                                        * unprocessedCompleteInputBlocks
                                        + MCUX_CSSL_FP_CONDITIONAL(false == isInputInPKC, algorithmDetails->protection_token_els_core);
#else
    (void) pIn;     /* Unused parameter */
    (void) inSize;     /* Unused parameter */
    uint32_t processNewInput_token = algorithmDetails->protection_token_els_core;
#endif

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        processNewInput_token += (MCUX_CSSL_FP_CONDITIONAL(NULL != algorithmDetails->dmaProtection,
            algorithmDetails->protection_token_dma_protection));
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
    return processNewInput_token;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}


/**
 * @brief Processing of full blocks via ELS
 *
 * This function processes full blocks of input data and stores remaining data in context.
 * It is used for both truncated and non-truncated hash algorithms.
 *
 * @param[in,out]   context           current hash context
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[in]       pIn               user input
 * @param[in]       inSize            total size of user input
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_process_Sha2_FullBlocks)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_process_Sha2_FullBlocks(
                        mcuxClHash_Context_t context,
                        mcuxClEls_HashOption_t *pHashOptions,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_process_Sha2_FullBlocks);

    /**************************************************************************************
     * Step 1: Gather information
     **************************************************************************************/
    const mcuxClHash_AlgorithmDescriptor_t * algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const size_t algoBlockSize = context->algo->blockSize;
    uint32_t unprocessedInputLength = inSize;
    /* When some data is in context and new data from input can fill entire context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("does not wrap since unprocessedLength in context does not exceed algorithm block size")
    bool isBlockProcessedFromContext = (0u != context->unprocessedLength) && (inSize >= (algoBlockSize - context->unprocessedLength));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Pointer to unprocessed data buffer */
    uint8_t *pUnprocessed = (uint8_t *)mcuxClHash_getUnprocessedPtr(context);
    /* Input pointer that changes throughout the function */
    const uint8_t *pInput = (const uint8_t *)pIn;
    /* Pointer to the buffer where the state is stored. Either it ends up in the work area, or in the state buffer of the context */
    uint8_t *partialdigest = (uint8_t *)mcuxClHash_getStatePtr(context);

#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
    const bool isInputInPKC =
        (((uint32_t) pIn + inSize) > (uint32_t) MCUXCLPKC_RAM_START_ADDRESS)
        && ((uint32_t) pIn < ((uint32_t) MCUXCLPKC_RAM_START_ADDRESS + MCUXCLPKC_RAM_SIZE));
#endif

    /**************************************************************************************
     * Step 2: Prepare Flow Protection Balancing
     **************************************************************************************/
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t processContextBuffer_token = getProcessContextBuffer_token(context, inSize));

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t processNewInput_token = getProcessNewInput_token(context, pIn, inSize));

    /**************************************************************************************
     * Step 3: Process context buffer
     **************************************************************************************/

    /* The first block can either be completely in `pInput`, or partially in the context buffer. */
    if(isBlockProcessedFromContext)
    {
        /* There is some data in the context buffer. Append enough data from `pInput` to complete a block. */
        uint32_t contextEmptyLength = algoBlockSize - context->unprocessedLength;
        MCUXCLMEMORY_FP_MEMORY_COPY(pUnprocessed + context->unprocessedLength,
                                    pInput,
                                    contextEmptyLength);
        MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                    pUnprocessed,
                                    algoBlockSize,
                                    partialdigest));
        if (MCUXCLHASH_STATUS_OK != resultElsCore)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, resultElsCore,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                algorithmDetails->protection_token_els_core);
        }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        if(NULL != algorithmDetails->dmaProtection)
        {
            MCUX_CSSL_FP_FUNCTION_CALL(resultDma, algorithmDetails->dmaProtection(partialdigest, algorithm->stateSize));
            if (MCUXCLHASH_STATUS_OK != resultDma)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, resultDma,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                    algorithmDetails->protection_token_els_core,
                    algorithmDetails->protection_token_dma_protection);
            }
        }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

        pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
        pHashOptions->bits.hashld = MCUXCLELS_HASH_LOAD_DISABLE;

        context->unprocessedLength = 0u;
        pInput += contextEmptyLength;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("will not wrap since isBlockProcessedFromContext flag implies inSize >= (algoBlockSize - context->unprocessedLength)")
        unprocessedInputLength -= contextEmptyLength;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    /**************************************************************************************
     * Step 4: Process new input
     **************************************************************************************/
    /* The amount of unprocessed data that fills complete blocks */
    uint32_t unprocessedCompleteBlockLength = (unprocessedInputLength / algoBlockSize) * algoBlockSize;

    /* At this point, there is no more data in the context buffer, so remaining blocks can be processed in bulk directly from pIn */
    if (0u != unprocessedCompleteBlockLength)
    {
#ifdef MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND
        /* Check pInput is in PKC workarea. */
        if (false != isInputInPKC)
        {
            size_t processedIn = 0u;
            while(processedIn < unprocessedCompleteBlockLength)
            {
                /* Copy block of the input data in the context buffer. */
                MCUXCLMEMORY_FP_MEMORY_COPY(pUnprocessed,
                                            &pInput[processedIn],
                                            algoBlockSize);

                MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                            pUnprocessed,
                                            algoBlockSize,
                                            partialdigest));
                if (MCUXCLHASH_STATUS_OK != resultElsCore)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, resultElsCore,
                            processContextBuffer_token,
                            (((processedIn + algoBlockSize)  / algoBlockSize) *
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
                                + algorithmDetails->protection_token_els_core));
                }
                processedIn += algoBlockSize;

                pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
                pHashOptions->bits.hashld = MCUXCLELS_HASH_LOAD_DISABLE;
            }
        }
        else
        {
            MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                        pInput,
                                        unprocessedCompleteBlockLength,
                                        partialdigest));
            if (MCUXCLHASH_STATUS_OK != resultElsCore)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, resultElsCore,
                            processContextBuffer_token,
                            algorithmDetails->protection_token_els_core);
            }
        }
#else
        MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                    pInput,
                                    unprocessedCompleteBlockLength,
                                    partialdigest));
        if (MCUXCLHASH_STATUS_OK != resultElsCore)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, resultElsCore,
                            processContextBuffer_token,
                            algorithmDetails->protection_token_els_core);
        }
#endif

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        if(NULL != algorithmDetails->dmaProtection)
        {
            MCUX_CSSL_FP_FUNCTION_CALL(resultDma, algorithmDetails->dmaProtection(partialdigest, algorithm->stateSize));
            if (MCUXCLHASH_STATUS_OK != resultDma)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, resultDma,
                    processContextBuffer_token,
                    processNewInput_token);
            }
        }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

        pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
        pHashOptions->bits.hashld = MCUXCLELS_HASH_LOAD_DISABLE;

        pInput += unprocessedCompleteBlockLength;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("does not wrap since unprocessedCompleteBlockLength = (unprocessedInputLength / algoBlockSize) * algoBlockSize")
        unprocessedInputLength -= unprocessedCompleteBlockLength;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    /**************************************************************************************
     * Step 5: Store incomplete blocks and exit
     **************************************************************************************/
    if(0u < unprocessedInputLength)
    {
        /* Append data from `pInput` to accumulation buffer. */
        MCUXCLMEMORY_FP_MEMORY_COPY(pUnprocessed + context->unprocessedLength,
                                        pInput,
                                        unprocessedInputLength);
        context->unprocessedLength += unprocessedInputLength;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2_FullBlocks, MCUXCLHASH_STATUS_OK,
        processContextBuffer_token,
        MCUX_CSSL_FP_CONDITIONAL((0u != unprocessedCompleteBlockLength), processNewInput_token),
        MCUX_CSSL_FP_CONDITIONAL((0u < unprocessedInputLength),
                    (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy))));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_process_Sha2, mcuxClHash_AlgoSkeleton_Process_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_process_Sha2 (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize)
{

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_process_Sha2);

    /**************************************************************************************
     * Step 1: Initialization - Calculate sizes, set pointers, and set ELS options for
     * initialization, continuation from external state, or from internal state
     **************************************************************************************/

    const mcuxClHash_AlgorithmDescriptor_t * algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /* Pointer to the buffer where the state is stored. Either it ends up in the work area, or in the state buffer of the context */
    uint8_t *partialdigest = (uint8_t *)mcuxClHash_getStatePtr(context);

    /* Start setting initial options for ELS hash */
    mcuxClEls_HashOption_t hashOptions = algorithmDetails->hashOptions;
    hashOptions.bits.hashoe = MCUXCLELS_HASH_OUTPUT_ENABLE;
    hashOptions.bits.hashini = MCUXCLELS_HASH_INIT_ENABLE;
    hashOptions.bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE;


    /**************************************************************************************
     * Step 2: Load state (partial digest), if data had been processed before
     **************************************************************************************/

    /* Set hash init/load flags depending on whether there is a valid state to load or not */
    int32_t processedLengthNotZero = mcuxClHash_processedLength_cmp(context->processedLength, 0u);
    if(0 != processedLengthNotZero)
    {
        /* There is already a valid state in the context -> load state from context */
        hashOptions.bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
        hashOptions.bits.hashld  = MCUXCLELS_HASH_LOAD_ENABLE;
    }
    else if(NULL != algorithmDetails->standardIV)
    {
        /* Else and if truncated, do ELS warmup and load custom IV into context */
        MCUX_CSSL_FP_FUNCTION_CALL(resultElsPrepare, mcuxClHashModes_Els_Sha2_Prepare_Truncated(
                session,
                algorithm,
                &hashOptions,
                partialdigest
        ));
        if (MCUXCLHASH_STATUS_OK != resultElsPrepare)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2, resultElsPrepare,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated));
        }
    }
    else
    {
        /* Intentionally left empty */
    }

    /* Set RTF processing options */
    if(MCUXCLHASH_STATUS_OK != mcuxClHashModes_els_selectRtfFlags(session->rtf, &hashOptions))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2, MCUXCLHASH_STATUS_FAULT_ATTACK);
    }

    /* Perform update of context->processedLength such that special case of
       overflowed inSize + context->unprocessedLength is handled
       but no uint64_t variable is needed */
    uint32_t inputToProcess = inSize;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("does not wrap since unprocessedLength in context does not exceed algorithm block size")
    uint32_t emptyUnprocessed = algorithm->blockSize - context->unprocessedLength;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    if((0u != context->unprocessedLength) && (inputToProcess >= emptyUnprocessed))
    {
        /* Block from context will be processed */
        mcuxClHash_processedLength_add(context->processedLength, algorithm->blockSize);
        inputToProcess -= emptyUnprocessed;
    }

    /* Only full blocks from input will be processed */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("does not wrap since algorithm->blockSize is at least MCUXCLHASH_BLOCK_SIZE_SHA_224")
    inputToProcess = inputToProcess & ~((uint32_t)algorithm->blockSize - 1u);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    mcuxClHash_processedLength_add(context->processedLength, inputToProcess);

    /* Verify that the processed length will not exceed the algorithm's maximum allowed length. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Does not wrap since counterSize is at least  MCUXCLHASH_COUNTER_SIZE_SHA_224, does not overflow since context->processedLength[] overflow is handled")
    uint8_t counterHighestByte = ((uint8_t *) context->processedLength)[algorithm->counterSize - 1u];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    if(0u != (counterHighestByte & algorithm->processedLengthCheckMask))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2, MCUXCLHASH_STATUS_FULL,
                MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
                MCUX_CSSL_FP_CONDITIONAL((0 == processedLengthNotZero) && (NULL != algorithmDetails->standardIV),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated)
                MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()));
    }

    /**************************************************************************************
     * Step 3: Handle full blocks of input
     **************************************************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(resultFullBlocks, mcuxClHashModes_Els_process_Sha2_FullBlocks(
            context,
            &hashOptions,
            pIn,
            inSize
    ));
    if (MCUXCLHASH_STATUS_OK != resultFullBlocks)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2, resultFullBlocks,
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_CONDITIONAL((0 == processedLengthNotZero) && (NULL != algorithmDetails->standardIV),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated))
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT(),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2_FullBlocks));
    }

    /**************************************************************************************
     * Step 5: Exit
     **************************************************************************************/

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_process_Sha2, MCUXCLHASH_STATUS_OK,
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_CONDITIONAL((0 == processedLengthNotZero) && (NULL != algorithmDetails->standardIV),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated))
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT(),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2_FullBlocks));
}

/**
 * @brief Performs padding first block
 *
 * @pre
 *  - Step 1: Set ELS options for initialization, continuation from external state, or from internal state
 *  - Step 2: Process full blocks of input data
 * @post
 *  - Processed first padded block
 *
 * @param[in,out]   context           current hash context
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[in,out]   buflen            number of bytes in buffer
 * @param[in,out]   posdst            position of destination for padding
 * @param[in]       dma_token         token to protect flow of the DMA
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock (
                               mcuxClHash_Context_t context,
                               mcuxClEls_HashOption_t *pHashOptions,
                               size_t *buflen,
                               size_t *posdst,
                               uint32_t dma_token)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock);

    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    uint8_t *shablock = (uint8_t *)mcuxClHash_getUnprocessedPtr(context);
    uint8_t *partialdigest = (uint8_t *)mcuxClHash_getStatePtr(context);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->counterSize, MCUXCLHASH_COUNTER_SIZE_SHA_224, MCUXCLHASH_COUNTER_SIZE_SHA_512, MCUXCLHASH_STATUS_FAILURE)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->blockSize, MCUXCLHASH_BLOCK_SIZE_SHA_224, MCUXCLHASH_BLOCK_SIZE_SHA_512, MCUXCLHASH_STATUS_FAILURE)
    if ((algorithm->blockSize - algorithm->counterSize - 1u) < context->unprocessedLength) // need room for 64 bit counter and one additional byte
    {
        MCUXCLMEMORY_FP_MEMORY_SET(shablock + *posdst, 0x00u, *buflen);
        *buflen = algorithm->blockSize;
        *posdst = 0u;

        MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                         shablock,
                                                         algorithm->blockSize,
                                                         partialdigest));

        if (MCUXCLHASH_STATUS_OK != resultElsCore)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock, resultElsCore,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
                algorithmDetails->protection_token_els_core
            );
        }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        if(NULL != algorithmDetails->dmaProtection)
        {
            MCUX_CSSL_FP_FUNCTION_CALL(resultDma, algorithmDetails->dmaProtection(partialdigest, algorithm->stateSize));

            if (MCUXCLHASH_STATUS_OK != resultDma)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock, resultDma,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
                    algorithmDetails->protection_token_els_core,
                    algorithmDetails->protection_token_dma_protection);
            }
        }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

        pHashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
        pHashOptions->bits.hashld = MCUXCLELS_HASH_LOAD_ENABLE;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock, MCUXCLHASH_STATUS_OK,
                MCUX_CSSL_FP_CONDITIONAL((algorithm->blockSize - algorithm->counterSize - 1u < context->unprocessedLength),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
                    algorithmDetails->protection_token_els_core,
                    dma_token));
}

/**
 * @brief Performs padding second block of data
 *
 * @pre
 *  - Step 1: Set ELS options for initialization, continuation from external state, or from internal state
 *  - Step 2: Process full blocks of input data
 *  - Step 3: Paded first block of padding
 * @post
 *  - Processed second padded block
 *
 * @param[in,out]   context           current hash context
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[in,out]   buflen            number of bytes in buffer
 * @param[in,out]   posdst            position of destinationin buffer for padding
 * @param[in]       pOutput           pointer to store the hashed block
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock (
                               mcuxClHash_Context_t context,
                               mcuxClEls_HashOption_t *pHashOptions,
                               size_t *buflen,
                               size_t *posdst,
                               uint8_t *pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock);

    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    uint8_t *shablock = (uint8_t *)mcuxClHash_getUnprocessedPtr(context);
    uint8_t *partialdigest = (uint8_t *)mcuxClHash_getStatePtr(context);


    /* Perform padding by adding data counter */
    MCUXCLMEMORY_FP_MEMORY_SET(shablock + *posdst, 0x00u, *buflen);

    mcuxClHash_processedLength_add(context->processedLength, context->unprocessedLength);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->counterSize, MCUXCLHASH_COUNTER_SIZE_SHA_224, MCUXCLHASH_COUNTER_SIZE_SHA_512, MCUXCLHASH_STATUS_FAILURE)
    uint8_t counterHighestByte = ((uint8_t *) context->processedLength)[algorithm->counterSize - 1u];
    if(0u != (counterHighestByte & algorithm->processedLengthCheckMask))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock, MCUXCLHASH_STATUS_FULL,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set));
    }

    /* Perform padding by adding data counter - length is added from end of the array; byte-length is converted to bit-length */
    mcuxClHash_processedLength_toBits(context->processedLength);
    for(uint32_t i = 0u; i < algorithm->counterSize; ++i)
    {
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(i, MCUXCLHASH_COUNTER_SIZE_SHA_224, MCUXCLHASH_COUNTER_SIZE_SHA_512, MCUXCLHASH_STATUS_FAILURE)
        shablock[algorithm->blockSize - i - 1u] = ((uint8_t*)context->processedLength)[i];
    }

    pHashOptions->bits.hashoe = MCUXCLELS_HASH_OUTPUT_ENABLE;

    MCUXCLMEMORY_FP_MEMORY_COPY(pOutput, partialdigest, algorithm->stateSize);

    /* Set RTF processing options */
    pHashOptions->bits.rtfoe = pHashOptions->bits.rtfupd;

    /* Process last block */
    MCUX_CSSL_FP_FUNCTION_CALL(resultElsCore, algorithmDetails->els_core(pHashOptions->word.value,
                                                      shablock,
                                                      algorithm->blockSize,
                                                      pOutput));
    if (MCUXCLHASH_STATUS_OK != resultElsCore)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock, resultElsCore,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            algorithmDetails->protection_token_els_core);
    }


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
        algorithmDetails->protection_token_els_core);
}

/**
 * @brief Performs appends padding to the input data
 *
 * This function appends padding to the input data.
 * It is used for both truncated and non-truncated hash algorithms.
 *
 * @param[in]       session           current session
 * @param[in]       context           current hash context
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 * @param[out]      pOutput           pointer to store the hashed block
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_finish_Sha2_Padding)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_finish_Sha2_Padding (
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t context,
    mcuxClEls_HashOption_t *pHashOptions,
    uint8_t **pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_finish_Sha2_Padding);

    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    uint8_t *shablock = (uint8_t *)mcuxClHash_getUnprocessedPtr(context);

    size_t posdst, buflen;

    /* Buffer in CPU WA to store the digest and RTF output in the finalization phase */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithmDetails->rtfSize, 0u, MCUXCLELS_HASH_RTF_OUTPUT_SIZE, MCUXCLHASH_STATUS_FAILURE)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->stateSize, MCUXCLHASH_STATE_SIZE_SHA_224, MCUXCLHASH_STATE_SIZE_SHA_512, MCUXCLHASH_STATUS_FAILURE)
    *pOutput = (uint8_t *) mcuxClSession_allocateWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
    if(NULL == *pOutput)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding, MCUXCLHASH_STATUS_FAILURE);
    }

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->unprocessedLength, 0u, (MCUXCLHASH_BLOCK_SIZE_SHA_512 - 1u), MCUXCLHASH_STATUS_FAILURE)
    buflen = algorithm->blockSize - context->unprocessedLength;
    posdst = context->unprocessedLength;

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t dma_token = 0u);
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_COUNTER_STMT(dma_token = algorithmDetails->protection_token_dma_protection);
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    // add first byte of the padding: (remaining) < (block length) so there is space in the buffer
    shablock[posdst] = 0x80u;
    posdst += 1u;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(buflen, 1u, algorithm->blockSize, MCUXCLHASH_STATUS_FAILURE)
    buflen -= 1u;

    /* Process padding first block
    *  At the end of the buffer it is necessary to write the length of processed data,
    *  if there is no space for it, process the current block. The counter
    *  will be added in the function mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock
    */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_processPartialPaddedFirst, mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock(
        context,
        pHashOptions,
        &buflen,
        &posdst,
        dma_token
    ));
    if(ret_processPartialPaddedFirst != MCUXCLHASH_STATUS_OK)
    {

        /* Free workarea (pOutput) */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot wrap.")
        mcuxClSession_freeWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding, ret_processPartialPaddedFirst,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock));
    }

    /* Process padding second block if needed
    *  If there was no space for the data length in the first padding block,
    *  a second block containing the data length will be created
    */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_processPartialPaddedSecond, mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock(
        context,
        pHashOptions,
        &buflen,
        &posdst,
        *pOutput
    ));
    if(ret_processPartialPaddedSecond != MCUXCLHASH_STATUS_OK)
    {

       /* Free workarea (pOutput) */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot wrap.")
        mcuxClSession_freeWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding, ret_processPartialPaddedSecond,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock)
            );
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    uint32_t rtfSize = 0u;
    rtfSize = (MCUXCLSESSION_RTF_UPDATE_TRUE == session->rtf) ? algorithmDetails->rtfSize : 0u;
    if(NULL != algorithmDetails->dmaProtection)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(resultDma, algorithmDetails->dmaProtection(*pOutput,
                                                                      algorithm->stateSize + rtfSize));
        if (MCUXCLHASH_STATUS_OK != resultDma)
        {

       /* Free workarea (pOutput) */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot wrap.")
        mcuxClSession_freeWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding, resultDma,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock),
                    algorithmDetails->protection_token_dma_protection);
        }
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_Padding, MCUXCLHASH_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_FirstBlock),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding_SecondBlock),
            dma_token);
}

/**
 * @brief Function checks if valid state is loaded and if not loads state from context
 *
 * @param[in]       session
 * @param[in]       context
 * @param[in/out]   hashOptions
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_loadState_Sha2)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_loadState_Sha2 (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxClEls_HashOption_t *hashOptions)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_loadState_Sha2);

    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /* Pointer to the buffer where the state is stored in the state buffer of the context */
    uint8_t *partialdigest = (uint8_t *)mcuxClHash_getStatePtr(context);

    /* Set hash init/load flags depending on whether there is a valid state to load or not */
    int32_t processedLengthNotZero = mcuxClHash_processedLength_cmp(context->processedLength, 0u);
    if(0 != processedLengthNotZero)
    {
        /* There is already a valid state in the context -> load state from context */
        hashOptions->bits.hashini = MCUXCLELS_HASH_INIT_DISABLE;
        hashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_ENABLE;
    }
    else if(NULL != algorithmDetails->standardIV)
    {
        /* Else and if truncated, do ELS warmup and load custom IV into context */
        MCUX_CSSL_FP_FUNCTION_CALL(resultElsPrepare, mcuxClHashModes_Els_Sha2_Prepare_Truncated(
            session,
            algorithm,
            hashOptions,
            partialdigest
        ));
        if (MCUXCLHASH_STATUS_OK != resultElsPrepare)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_loadState_Sha2, resultElsPrepare,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated));
        }
    }
    else
    {
        /* Intentionally left empty */
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_loadState_Sha2, MCUXCLHASH_STATUS_OK
        ,MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_CONDITIONAL((0 == processedLengthNotZero) && (NULL != algorithmDetails->standardIV),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_Sha2_Prepare_Truncated))
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
    );
}

/**
 * @brief Performs inicialzation of the finish operation
 *
 * Step 1: Initialization - Calculate sizes, set pointers, and set ELS options for
 * initialization, continuation from external state, or from internal state
 *
 * @pre
 *  - Step 1: Set ELS options for initialization, continuation from external state, or from internal state
 *
 * @post
 *  - hash options is correct set
 *  - set RTF processing options
 *
 * @param[in]       session           current session
 * @param[in,out]   context           current hash context
 * @param[in]       pOut              buffer for hash
 * @param[out]      pOutSize          stored hash size
 * @param[in,out]   pHashOptions      hash options to be used for ELS
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_finish_Sha2_init)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_finish_Sha2_init (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize,
                        mcuxClEls_HashOption_t *hashOptions)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_finish_Sha2_init);

   /**************************************************************************************
     * Step 1: Initialization - Calculate sizes, set pointers, and set ELS options for
     * initialization, continuation from external state, or from internal state
     **************************************************************************************/

    if(NULL == pOut)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_init, MCUXCLHASH_STATUS_INVALID_PARAMS);
    }

    /* Start setting initial options for ELS hash */
    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    *hashOptions = algorithmDetails->hashOptions;
    hashOptions->bits.hashoe = MCUXCLELS_HASH_OUTPUT_ENABLE;
    hashOptions->bits.hashini = MCUXCLELS_HASH_INIT_ENABLE;
    hashOptions->bits.hashld  = MCUXCLELS_HASH_LOAD_DISABLE;

    if((algorithm->blockSize < MCUXCLHASH_BLOCK_SIZE_SHA_224)||(algorithm->blockSize > MCUXCLHASH_BLOCK_SIZE_SHA_512))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_init, MCUXCLHASH_FAILURE);
    }
    /* Set RTF processing options */
    if(MCUXCLHASH_STATUS_OK != mcuxClHashModes_els_selectRtfFlags(session->rtf, hashOptions))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_init, MCUXCLHASH_STATUS_FAULT_ATTACK);
    }
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2_init, MCUXCLHASH_STATUS_OK);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Els_finish_Sha2, mcuxClHash_AlgoSkeleton_Finish_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Els_finish_Sha2 (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Els_finish_Sha2);

    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;

    /* Check that *pOutSize will not overflow */
    if((UINT32_MAX - *pOutSize) < algorithm->hashSize)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2, MCUXCLHASH_STATUS_INVALID_PARAMS);
    }

   /**************************************************************************************
     * Step 1: Initialization - Calculate sizes, set pointers, and set ELS options for
     * initialization, continuation from external state, or from internal state
     **************************************************************************************/
    /* Start setting initial options for ELS hash */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    mcuxClEls_HashOption_t hashOptions;

    MCUX_CSSL_FP_FUNCTION_CALL(result_Sha2init, mcuxClHashModes_Els_finish_Sha2_init (
                                session,
                                context,
                                pOut,
                                pOutSize,
                                &hashOptions));

    if(MCUXCLHASH_STATUS_OK != result_Sha2init)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2, result_Sha2init,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_init));
    }

    /**************************************************************************************
     * Step 2: Load state (partial digest), if data had been processed before
     **************************************************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(resultLoadState, mcuxClHashModes_Els_loadState_Sha2 (
                                session,
                                context,
                                &hashOptions));

    if(MCUXCLHASH_STATUS_OK != resultLoadState)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2, resultLoadState,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_init),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_loadState_Sha2));
    }

    /**************************************************************************************
     * Step 3: Padd data and process last block
     **************************************************************************************/
    uint8_t *pOutput = NULL;

    MCUX_CSSL_FP_FUNCTION_CALL(resultPadding, mcuxClHashModes_Els_finish_Sha2_Padding(
                    session,
                    context,
                    &hashOptions,
                    &pOutput));
    if (MCUXCLHASH_STATUS_OK != resultPadding)
    {
        /* Free workarea (pOutput) */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot wrap.")
        mcuxClSession_freeWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2, resultPadding,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_init),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_loadState_Sha2),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding));
    }

    /**************************************************************************************
     * Step 4: Copy result to output buffers and clear context
     **************************************************************************************/

    /* Copy RTF to corresponding buffer */
    if((MCUXCLSESSION_RTF_UPDATE_TRUE == session->rtf))
    {
        if (NULL == session->pRtf)
        {
            /* Free workarea (pOutput) */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot wrap.")
            mcuxClSession_freeWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2, MCUXCLHASH_STATUS_INVALID_PARAMS,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_init),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_loadState_Sha2),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding));
        }
        else
        {
            MCUXCLMEMORY_FP_MEMORY_COPY(session->pRtf, pOutput + algorithm->hashSize, algorithmDetails->rtfSize);
        }
    }

    /* Copy hash digest to output buffer */
    MCUXCLMEMORY_FP_MEMORY_COPY(pOut, pOutput, algorithm->hashSize);

    *pOutSize += algorithm->hashSize;

    /* Free workarea (pOutput) */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot wrap.")
    mcuxClSession_freeWords_cpuWa(session, (algorithm->stateSize + algorithmDetails->rtfSize) / sizeof(uint32_t));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* Clear context */
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)context, sizeof(mcuxClHash_ContextDescriptor_t) + context->algo->blockSize + context->algo->stateSize);

    /**************************************************************************************
     * Step 5: Exit
     **************************************************************************************/

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t rtfSC = 0u);
    MCUX_CSSL_FP_COUNTER_STMT(rtfSC = MCUX_CSSL_FP_CONDITIONAL((MCUXCLSESSION_RTF_UPDATE_TRUE == session->rtf),MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Els_finish_Sha2, MCUXCLHASH_STATUS_OK,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_init),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_loadState_Sha2),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2_Padding),
                            rtfSC,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
}


/**********************************************************
 * Algorithm descriptor implementations
 **********************************************************/

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT
static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha224_direct =
{
    .els_core                         = mcuxClHashModes_els_core_sha2_direct,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2_direct),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_224,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = NULL,
    .protection_token_dma_protection  = 0u,
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha224_direct = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_224,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_224,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_224,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_224,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha224_direct
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha224 =
{
    .els_core                         = mcuxClHashModes_els_core_sha2,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_224,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = mcuxClHashModes_els_dmaProtectionAddressReadback,
    .protection_token_dma_protection  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_dmaProtectionAddressReadback),
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha224 = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_224,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_224,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_224,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_224,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha224
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha256_direct =
{
    .els_core                         = mcuxClHashModes_els_core_sha2_direct,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2_direct),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_256,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = NULL,
    .protection_token_dma_protection  = 0u,
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha256_direct = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_256,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_256,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_256,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_256,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha256_direct
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha256 =
{
    .els_core                         = mcuxClHashModes_els_core_sha2,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2),
    .rtfSize                          = MCUXCLELS_HASH_RTF_OUTPUT_SIZE,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_256,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = mcuxClHashModes_els_dmaProtectionAddressReadback,
    .protection_token_dma_protection  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_dmaProtectionAddressReadback),
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha256 = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_256,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_256,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_256,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_256,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha256
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha384_direct =
{
    .els_core                         = mcuxClHashModes_els_core_sha2_direct,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2_direct),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_384,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = NULL,
    .protection_token_dma_protection  = 0u,
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha384_direct = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_384,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_384,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_384,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_384,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha384_direct
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

};
#endif

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha384 =
{
    .els_core                         = mcuxClHashModes_els_core_sha2,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_384,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = mcuxClHashModes_els_dmaProtectionAddressReadback,
    .protection_token_dma_protection  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_dmaProtectionAddressReadback),
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha384 = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_384,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_384,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_384,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_384,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha384
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_direct =
{
    .els_core                         = mcuxClHashModes_els_core_sha2_direct,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2_direct),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_512,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = NULL,
    .protection_token_dma_protection  = 0u,
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_direct = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_512,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_512,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_512,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_direct
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512 =
{
    .els_core                         = mcuxClHashModes_els_core_sha2,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_512,
    .standardIV                       = NULL,
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = mcuxClHashModes_els_dmaProtectionAddressReadback,
    .protection_token_dma_protection  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_dmaProtectionAddressReadback),
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512 = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_512,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_512,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_512,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT
static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_224_direct =
{
    .els_core                         = mcuxClHashModes_els_core_sha2_direct,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2_direct),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positive, mcuxClHashModes_els_sha512_224_iv is forced to 32-bit alignment using the ALIGNED keyword.")
    .standardIV                       = (uint32_t const *)mcuxClHashModes_els_sha512_224_iv,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = NULL,
    .protection_token_dma_protection  = 0u,
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_224_direct = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2_Truncated,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Truncated),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_512,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_512_224,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_512,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_224_direct
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_224 =
{
    .els_core                         = mcuxClHashModes_els_core_sha2,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positive, mcuxClHashModes_els_sha512_224_iv is forced to 32-bit alignment using the ALIGNED keyword.")
    .standardIV                       = (uint32_t const *)mcuxClHashModes_els_sha512_224_iv,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = mcuxClHashModes_els_dmaProtectionAddressReadback,
    .protection_token_dma_protection  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_dmaProtectionAddressReadback),
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_224 = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2_Truncated,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Truncated),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_512,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_512_224,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_512,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_224
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT
static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_256_direct =
{
    .els_core                         = mcuxClHashModes_els_core_sha2_direct,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2_direct),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positive, mcuxClHashModes_els_sha512_256_iv is forced to 32-bit alignment using the ALIGNED keyword.")
    .standardIV                       = (uint32_t const *)mcuxClHashModes_els_sha512_256_iv,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = NULL,
    .protection_token_dma_protection  = 0u,
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_256_direct = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2_Truncated,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Truncated),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_512,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_512_256,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_512,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_256_direct
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
#endif

static const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_256 =
{
    .els_core                         = mcuxClHashModes_els_core_sha2,
    .protection_token_els_core        = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_core_sha2),
    .rtfSize                          = 0u,
    .hashOptions.word.value           = MCUXCLELS_HASH_VALUE_MODE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positive, mcuxClHashModes_els_sha512_256_iv is forced to 32-bit alignment using the ALIGNED keyword.")
    .standardIV                       = (uint32_t const *)mcuxClHashModes_els_sha512_256_iv,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    .dmaProtection                    = mcuxClHashModes_els_dmaProtectionAddressReadback,
    .protection_token_dma_protection  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_els_dmaProtectionAddressReadback),
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
};

const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_256 = {
    .oneShotSkeleton                  = mcuxClHashModes_Els_oneShot_Sha2_Truncated,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_oneShot_Sha2_Truncated),
    .processSkeleton                  = mcuxClHashModes_Els_process_Sha2,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_process_Sha2),
    .finishSkeleton                   = mcuxClHashModes_Els_finish_Sha2,
    .protection_token_finishSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Els_finish_Sha2),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA_512,
    .hashSize                         = MCUXCLHASH_OUTPUT_SIZE_SHA_512_256,
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA_512,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA_512,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.")
    .pAlgorithmDetails                = (void *) &mcuxClHashModes_Internal_AlgorithmDescriptor_Sha512_256
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
