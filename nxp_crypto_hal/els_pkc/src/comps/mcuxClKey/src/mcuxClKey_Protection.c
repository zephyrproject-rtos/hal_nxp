/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClKey_Protection.c
 *  @brief Implementation of the Key protection functions that are supported
 *  by component. */

#include <mcuxClEls.h>
#include <mcuxClKey.h>
#include <mcuxClMemory.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClKey_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_protect_fct_none, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_protect_fct_none(mcuxClKey_Handle_t key)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_protect_fct_none);

    if(MCUXCLKEY_LOADSTATUS_MEMORY == mcuxClKey_getLoadStatus(key))
    {
        // copy key source to destination memory buffer
        uint32_t len = mcuxClKey_getSize(key);

        MCUXCLMEMORY_FP_MEMORY_COPY(mcuxClKey_getLoadedKeyData(key), mcuxClKey_getKeyData(key), len);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_protect_fct_none, MCUXCLKEY_STATUS_OK, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy));
    }
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_protect_fct_none, MCUXCLKEY_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_protect_fct_ckdf, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_protect_fct_ckdf(mcuxClKey_Handle_t key)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_protect_fct_ckdf);

    if(NULL == key->container.parentKey)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_protect_fct_ckdf, MCUXCLKEY_STATUS_ERROR);
    }

    mcuxClEls_KeyIndex_t key_idx_sk     = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(mcuxClKey_getParentKey(key));
    mcuxClEls_KeyIndex_t key_idx_mack   = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(key);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Auxularity data is properly aligned with key_properties type structure")
    mcuxClEls_KeyProp_t  key_properties = *((mcuxClEls_KeyProp_t*) mcuxClKey_getAuxData(key));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    MCUX_CSSL_FP_FUNCTION_CALL(resultCkdf, mcuxClEls_Ckdf_Sp800108_Async(
                                 key_idx_sk,
                                 key_idx_mack,
                                 key_properties,
                                 mcuxClKey_getKeyData(key)
    ));
    // mcuxClEls_Ckdf_Sp800108_Async is a flow-protected function: Check the protection token and the return value
    if (MCUXCLELS_STATUS_OK_WAIT != resultCkdf)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_protect_fct_ckdf, MCUXCLKEY_STATUS_ERROR,
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Ckdf_Sp800108_Async)); // Expect that no error occurred, meaning that the mcuxClEls_Ckdf_Sp800108_Async operation was started.
    }

    MCUX_CSSL_FP_FUNCTION_CALL(resultWait, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (MCUXCLELS_STATUS_OK != resultWait)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_protect_fct_ckdf, MCUXCLKEY_STATUS_ERROR,
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Ckdf_Sp800108_Async),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_protect_fct_ckdf, MCUXCLKEY_STATUS_OK,
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Ckdf_Sp800108_Async),
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
}

const mcuxClKey_ProtectionDescriptor_t mcuxClKey_ProtectionDescriptor_None = {&mcuxClKey_protect_fct_none,
                                                                            NULL,
                                                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_protect_fct_none),
                                                                            0u};

const mcuxClKey_ProtectionDescriptor_t mcuxClKey_ProtectionDescriptor_Ckdf = {&mcuxClKey_protect_fct_ckdf,
                                                                            NULL,
                                                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_protect_fct_ckdf),
                                                                            0u};


