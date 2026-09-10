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

/** @file  mcuxClEls_Cipher.c
 *  @brief ELS implementation for symmetric ciphers.
 * This file implements the functions declared in mcuxClEls_Cipher.h. */

#include <platform_specific_headers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <stdbool.h>
#include <mcuxClEls.h>
#include <internal/mcuxClEls_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_Cipher_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_Cipher_Async(
    mcuxClEls_CipherOption_t options,
    mcuxClEls_KeyIndex_t keyIdx,
    uint8_t const * pKey,
    size_t keyLength,
    uint8_t const * pInput,
    size_t inputLength,
    uint8_t * pIV,
    uint8_t * pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_Cipher_Async);

    // ignored misra violation -> false positive
    // misra_c_2012_rule_11_9_violation: Literal 0 shall not be used as null pointer constant.

#ifndef MCUXCL_FEATURE_ELS_NO_INTERNAL_STATE_FLAGS
    #define TMP_NO_INTERNAL_STATE_FLAGS (MCUXCLELS_CIPHER_STATE_IN_ENABLE == options.bits.cphsie)
#else
    #define TMP_NO_INTERNAL_STATE_FLAGS ((bool)false)
#endif /* MCUXCL_FEATURE_ELS_NO_INTERNAL_STATE_FLAGS */

    MCUXCLELS_INPUT_PARAM_CHECK_PROTECTED(mcuxClEls_Cipher_Async,
                                          (0U == inputLength) 
                                          || (0U != (inputLength % MCUXCLELS_CIPHER_BLOCK_SIZE_AES))
                                          || ((MCUXCLELS_CIPHER_INTERNAL_KEY == options.bits.extkey) && (ELS_KS_CNT <= keyIdx))
                                          || ((MCUXCLELS_CIPHER_EXTERNAL_KEY == options.bits.extkey) && ((MCUXCLELS_CIPHER_KEY_SIZE_AES_128 != keyLength) && (MCUXCLELS_CIPHER_KEY_SIZE_AES_192 != keyLength) && (MCUXCLELS_CIPHER_KEY_SIZE_AES_256 != keyLength)))
                                          || (MCUXCLELS_CIPHERPARAM_ALGORITHM_AES_CTR < options.bits.cphmde)
            /* ECB doesn't support importing or exporting an IV */
                                          || ((MCUXCLELS_CIPHERPARAM_ALGORITHM_AES_ECB == options.bits.cphmde) && ((MCUXCLELS_CIPHER_STATE_OUT_ENABLE == options.bits.cphsoe) || TMP_NO_INTERNAL_STATE_FLAGS)));
    
#undef TMP_NO_INTERNAL_STATE_FLAGS

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_Cipher_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }
    
    mcuxClEls_setInput0(pInput, inputLength);
    if (0U == options.bits.extkey)
    {
        mcuxClEls_setKeystoreIndex0(keyIdx);
    }
    else
    {
        mcuxClEls_setInput2(pKey, keyLength);
    }
    
    mcuxClEls_setInput1_fixedSize(pIV);
    mcuxClEls_setOutput_fixedSize(pOutput);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_CIPHER, options.word.value, ELS_CMD_BIG_ENDIAN);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_Cipher_Async, MCUXCLELS_STATUS_OK_WAIT);
}
