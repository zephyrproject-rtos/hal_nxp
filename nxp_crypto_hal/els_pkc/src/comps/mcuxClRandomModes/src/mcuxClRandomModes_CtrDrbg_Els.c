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

#include <mcuxClRandom.h>
#include <mcuxClSession.h>
#include <mcuxClEls.h>
#include <mcuxClMemory.h>
#include <mcuxClAes.h>

#include <mcuxClEls.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg_BlockCipher.h>
#include <internal/mcuxClRandomModes_Private_NormalMode.h>
#include <internal/mcuxClTrng_Internal.h>
#include <internal/mcuxClEls_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_DRBG_AES_Internal_blockcipher)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_DRBG_AES_Internal_blockcipher(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    uint32_t const *pV,
    uint32_t const *pKey,
    mcuxCl_Buffer_t pOut,
    uint32_t keyLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_DRBG_AES_Internal_blockcipher);

    uint8_t elsOut[MCUXCLAES_BLOCK_SIZE];

    mcuxClEls_CipherOption_t cipher_options = {0};
    cipher_options.bits.cphmde = MCUXCLELS_CIPHERPARAM_ALGORITHM_AES_ECB;
    cipher_options.bits.dcrpt = MCUXCLELS_CIPHER_ENCRYPT;
    cipher_options.bits.extkey = MCUXCLELS_CIPHER_EXTERNAL_KEY;
    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_ANALYSIS_START_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
    MCUX_CSSL_FP_FUNCTION_CALL(result_cipher, mcuxClEls_Cipher_Async(
                cipher_options,
                (mcuxClEls_KeyIndex_t)0U,
                (uint8_t const *)pKey,
                keyLength,
                (uint8_t const *)pV,
                MCUXCLAES_BLOCK_SIZE,
                NULL,
                elsOut));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
    if (MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT == result_cipher)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_DRBG_AES_Internal_blockcipher, MCUXCLRANDOM_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async));
    }
    else if (MCUXCLELS_STATUS_OK_WAIT != result_cipher)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_DRBG_AES_Internal_blockcipher, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Intentionally left empty */
    }

    MCUX_CSSL_FP_FUNCTION_CALL(result_wait, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));
    if(MCUXCLELS_LEVEL1_ERROR(result_wait))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_DRBG_AES_Internal_blockcipher, MCUXCLRANDOM_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async));
    }
    else if (MCUXCLELS_STATUS_OK != result_wait)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_DRBG_AES_Internal_blockcipher, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Intentionally left empty */
    }

    /* Copy the bytes from the buffer to output. */
    MCUX_CSSL_FP_FUNCTION_CALL(copy_result, mcuxCsslMemory_Copy(
        mcuxCsslParamIntegrity_Protect(4u, elsOut, MCUXCLBUFFER_GET(pOut), MCUXCLAES_BLOCK_SIZE, MCUXCLAES_BLOCK_SIZE),
            elsOut,
            pOut,
            MCUXCLAES_BLOCK_SIZE,
            MCUXCLAES_BLOCK_SIZE)
    );

    if(MCUXCSSLMEMORY_STATUS_OK != copy_result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_DRBG_AES_Internal_blockcipher, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_DRBG_AES_Internal_blockcipher, MCUXCLRANDOM_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Copy),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async));
}
