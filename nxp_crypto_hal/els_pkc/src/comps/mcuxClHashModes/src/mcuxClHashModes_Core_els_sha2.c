/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

#include <mcuxClHash.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Core_els_sha2.h>
#include <mcuxClEls.h>
#include <internal/mcuxClEls_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_els_core_sha2, mcuxClHashModes_els_AlgoCore_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_els_core_sha2(
                        uint32_t options,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_els_core_sha2,
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Hash_Async));

    mcuxClEls_HashOption_t hash_options;
    hash_options.word.value = options;

    MCUX_CSSL_FP_FUNCTION_CALL(result_hash, mcuxClEls_Hash_Async(hash_options,
                                                               pIn,
                                                               inSize,
                                                               pOut));

    if (MCUXCLELS_STATUS_OK_WAIT != result_hash)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_core_sha2, MCUXCLHASH_STATUS_FAILURE);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(result, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (MCUXCLELS_STATUS_OK != result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_core_sha2, MCUXCLHASH_STATUS_FAILURE,
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_core_sha2, MCUXCLHASH_STATUS_OK,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
}

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_els_core_sha2_direct, mcuxClHashModes_els_AlgoCore_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_els_core_sha2_direct(
                        uint32_t options,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_Buffer_t pOut)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_els_core_sha2_direct, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Hash_ShaDirect));

    mcuxClEls_HashOption_t hash_options;
    hash_options.word.value = options;

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(result, mcuxClEls_Hash_ShaDirect(hash_options,
                                                              pIn,
                                                              inSize,
                                                              pOut,
                                                              NULL,
                                                              NULL));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if(MCUXCLELS_STATUS_SW_INVALID_PARAM == result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_core_sha2_direct, MCUXCLHASH_STATUS_INVALID_PARAMS);
    }
    else if (MCUXCLELS_STATUS_OK != result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_core_sha2_direct, MCUXCLHASH_STATUS_FAILURE);
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_els_core_sha2_direct, MCUXCLHASH_STATUS_OK);
    }
}
#endif
