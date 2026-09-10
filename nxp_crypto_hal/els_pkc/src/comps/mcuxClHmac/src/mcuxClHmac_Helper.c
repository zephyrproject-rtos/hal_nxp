/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClHmac_Helper.c
 *  @brief Helper functions of mcuxClHmac
 */

#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClMac.h>
#include <mcuxClMemory.h>
#include <mcuxClKey.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClHmac_Functions.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClHmac_Internal_Functions.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClHash_Internal.h>
#include <mcuxClEls_Hmac.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_createHmacMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_createHmacMode(
    mcuxClMac_CustomMode_t mode,
    mcuxClHash_Algo_t hashAlgorithm)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_createHmacMode);

    /* copy the common HMAC mode descriptor into the mode */
    MCUXCLMEMORY_FP_MEMORY_COPY((uint8_t *) &mode->common, (uint8_t const *) &mcuxClHmac_CommonModeDescriptor_Sw, sizeof(mcuxClHmac_CommonModeDescriptor_Sw));

    /* Insert hashSize from the hashAlgorithm into the macByteSize field */
    mode->common.macByteSize = hashAlgorithm->hashSize;

    /* pCustom points to the end of the mode descriptor in memory,
       assumes user allocated sufficient memory with MCUXCLMAC_HMAC_MODE_DESCRIPTOR_SIZE */
    uintptr_t pCustomLocation = (uintptr_t)mode + sizeof(mcuxClMac_ModeDescriptor_t);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Reinterpreting a properly calculated address to a pointer is allowed.")
    mode->pCustom = (void *) (mcuxClHmac_ModeDescriptor_t *) pCustomLocation;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

    mcuxClHmac_ModeDescriptor_t * hmacModeDescriptor = (mcuxClHmac_ModeDescriptor_t *) mode->pCustom;
    hmacModeDescriptor->hashAlgorithm = (const mcuxClHash_AlgorithmDescriptor_t *) hashAlgorithm;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_createHmacMode, MCUXCLMAC_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_prepareHMACKey)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_prepareHMACKey(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    uint32_t * preparedHmacKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_prepareHMACKey);

    size_t alreadyFilledKeyDataSize = 0u;
    uint8_t *pPreparedHmacKey = (uint8_t *) preparedHmacKey;
    uint8_t *pKeyData = mcuxClKey_getLoadedKeyData(key);
    uint32_t keySize = mcuxClKey_getSize(key);

    if(mcuxClKey_getSize(key) <= MCUXCLELS_HMAC_PADDED_KEY_SIZE)
    {
        /* Given key must be zero-padded up to MCUXCLELS_HMAC_PADDED_KEY_SIZE */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pPreparedHmacKey,
                                             pKeyData,
                                             keySize,
                                             MCUXCLELS_HMAC_PADDED_KEY_SIZE);

        alreadyFilledKeyDataSize = keySize;
    }
    else
    {
        uint32_t hashOutputSize = 0u;
        /* Given key must be hashed and then zero-padded up to MCUXCLELS_HMAC_PADDED_KEY_SIZE */
        MCUX_CSSL_FP_FUNCTION_CALL(hashResult, mcuxClHash_compute(session,
                                                                mcuxClHash_Algorithm_Sha256,
                                                                pKeyData,
                                                                (uint32_t) keySize,
                                                                pPreparedHmacKey,
                                                                &hashOutputSize));

        if(MCUXCLHASH_STATUS_OK != hashResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_prepareHMACKey, MCUXCLMAC_STATUS_ERROR,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute));
        }

        alreadyFilledKeyDataSize = MCUXCLHASH_OUTPUT_SIZE_SHA_256;
    }

    /* Zero-pad the key */
    MCUXCLMEMORY_FP_MEMORY_SET(pPreparedHmacKey + alreadyFilledKeyDataSize, 0u, MCUXCLELS_HMAC_PADDED_KEY_SIZE - alreadyFilledKeyDataSize);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_prepareHMACKey, MCUXCLMAC_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((mcuxClKey_getSize(key) <= MCUXCLELS_HMAC_PADDED_KEY_SIZE),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
        ),
        MCUX_CSSL_FP_CONDITIONAL((mcuxClKey_getSize(key) > MCUXCLELS_HMAC_PADDED_KEY_SIZE),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute)
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set)
    );
}
