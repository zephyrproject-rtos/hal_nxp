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
 * @file  mcuxClEcc_Weier_GenerateCustomKeyType.c
 * @brief Implementation of the custom key type constructor.
 */


#include <mcuxClKey.h>
#include <mcuxClEcc.h>
#include <internal/mcuxClKey_Types_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_WeierECC_GenerateCustomKeyType)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_GenerateCustomKeyType(
    mcuxClKey_CustomType_t customType,
    mcuxClKey_AlgorithmId_t algoId,
    mcuxClKey_Size_t size,
    void *pCustomParams,
    mcuxClKey_Encoding_t plainEncoding)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_WeierECC_GenerateCustomKeyType);

    /* Extract algo and usage specifiers from the algoId */
    const uint32_t algoSpecifier  = (uint32_t) algoId & MCUXCLKEY_ALGO_ID_ALGO_MASK;
    const uint32_t usageSpecifier = (uint32_t) algoId & MCUXCLKEY_ALGO_ID_USAGE_MASK;

    /* Verify that the algoId is supported. If not, return FAULT_ATTACK */
    if (   (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_EPHEMERAL_CUSTOM != algoSpecifier)
        && (MCUXCLKEY_ALGO_ID_ECC_SHWS_GFP_STATIC_CUSTOM    != algoSpecifier) )
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_GenerateCustomKeyType, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    if (   (MCUXCLKEY_ALGO_ID_PUBLIC_KEY  != usageSpecifier)
        && (MCUXCLKEY_ALGO_ID_PRIVATE_KEY != usageSpecifier)
        && (MCUXCLKEY_ALGO_ID_KEY_PAIR    != usageSpecifier) )
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_WeierECC_GenerateCustomKeyType, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* Fill custom key type descriptor */
    customType->algoId          = algoId;
    customType->size            = size;
    customType->info            = pCustomParams;
    customType->plainEncoding   = plainEncoding;

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(
      mcuxClEcc_WeierECC_GenerateCustomKeyType,
      MCUXCLECC_STATUS_OK,
      MCUXCLECC_STATUS_FAULT_ATTACK
    );
}
