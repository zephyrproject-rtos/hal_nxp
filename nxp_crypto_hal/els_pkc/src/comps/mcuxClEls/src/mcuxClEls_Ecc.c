/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * @file  mcuxClEls_Ecc.c
 * @brief ELS implementation for elliptic curve cryptography.
 * This file implements the functions declared in mcuxClEls_Ecc.h.
 */

#include <platform_specific_headers.h>
#include <mcuxClEls_Ecc.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <stdbool.h>
#include <mcuxClEls.h>
#include <internal/mcuxClEls_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_EccKeyGen_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_EccKeyGen_Async(
    mcuxClEls_EccKeyGenOption_t options,
    mcuxClEls_KeyIndex_t signingKeyIdx,
    mcuxClEls_KeyIndex_t privateKeyIdx,
    mcuxClEls_KeyProp_t generatedKeyProperties,
    uint8_t const * pRandomData,
    uint8_t * pPublicKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_EccKeyGen_Async);

    MCUXCLELS_INPUT_PARAM_CHECK_PROTECTED(mcuxClEls_EccKeyGen_Async, (ELS_KS_CNT <= signingKeyIdx) || (ELS_KS_CNT <= privateKeyIdx));

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccKeyGen_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    options.bits.revf = MCUXCLELS_ECC_REVERSEFETCH_ENABLE;

#ifdef MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING
    if(MCUXCLELS_ECC_OUTPUTKEY_RANDOM == options.bits.kgsrc)
    {
        /* If the DRBG was used, increment drbg_block_counter. If the counter overflowed, the interrupt handler will
         * reseed the DRBG and reset the counter after the upcoming ELS operation. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Overflow handled in interrupt handler")
        mcuxClEls_rng_drbg_block_counter += MCUXCLELS_RNG_DRBG_ECCKEYGEN_INCREASE;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
#endif /* MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING */

    mcuxClEls_setKeystoreIndex0(privateKeyIdx);
    mcuxClEls_setKeystoreIndex1(signingKeyIdx);
    mcuxClEls_setRequestedKeyProperties(generatedKeyProperties.word.value);
    mcuxClEls_setInput0_fixedSize(pRandomData);
    mcuxClEls_setOutput_fixedSize(pPublicKey);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_KEYGEN, options.word.value, ELS_CMD_BIG_ENDIAN);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccKeyGen_Async, MCUXCLELS_STATUS_OK_WAIT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_EccKeyExchange_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_EccKeyExchange_Async(
        mcuxClEls_KeyIndex_t privateKeyIdx,
        uint8_t const * pPublicKey,
        mcuxClEls_KeyIndex_t sharedSecretIdx,
        mcuxClEls_KeyProp_t sharedSecretProperties)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_EccKeyExchange_Async);

    MCUXCLELS_INPUT_PARAM_CHECK_PROTECTED(mcuxClEls_EccKeyExchange_Async, (ELS_KS_CNT <= privateKeyIdx) || (ELS_KS_CNT <= sharedSecretIdx));

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccKeyExchange_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }
    
    mcuxClEls_EccKeyExchOption_t options = {0};
    options.bits.revf = MCUXCLELS_ECC_REVERSEFETCH_ENABLE;
#ifdef MCUXCL_FEATURE_ELS_PUK_INTERNAL_BIT
    options.bits.extkey = MCUXCLELS_ECC_EXTKEY_EXTERNAL;
#endif /* MCUXCL_FEATURE_ELS_PUK_INTERNAL_BIT */

    mcuxClEls_setKeystoreIndex0(privateKeyIdx);
    mcuxClEls_setInput1_fixedSize(pPublicKey);
    mcuxClEls_setKeystoreIndex1(sharedSecretIdx);
    mcuxClEls_setRequestedKeyProperties(sharedSecretProperties.word.value);

    mcuxClEls_startCommand(ID_CFG_ELS_CMD_ECKXH, options.word.value, ELS_CMD_BIG_ENDIAN);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccKeyExchange_Async, MCUXCLELS_STATUS_OK_WAIT);
}

#ifdef MCUXCL_FEATURE_ELS_PUK_INTERNAL

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_EccKeyExchangeInt_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_EccKeyExchangeInt_Async(
    mcuxClEls_KeyIndex_t privateKeyIdx,
    mcuxClEls_KeyIndex_t publicKeyIdx,
    mcuxClEls_KeyIndex_t sharedSecretIdx,
    mcuxClEls_KeyProp_t sharedSecretProperties)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_EccKeyExchangeInt_Async);

    MCUXCLELS_INPUT_PARAM_CHECK_PROTECTED(mcuxClEls_EccKeyExchangeInt_Async, (ELS_KS_CNT <= privateKeyIdx)
                                                                        || (ELS_KS_CNT <= publicKeyIdx)
                                                                        || (ELS_KS_CNT <= sharedSecretIdx));

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccKeyExchangeInt_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    mcuxClEls_EccKeyExchOption_t options = {0};
    options.bits.revf = MCUXCLELS_ECC_REVERSEFETCH_ENABLE;
    options.bits.extkey = MCUXCLELS_ECC_EXTKEY_INTERNAL;

    mcuxClEls_setKeystoreIndex0(privateKeyIdx);
    mcuxClEls_setKeystoreIndex2(publicKeyIdx);
    mcuxClEls_setKeystoreIndex1(sharedSecretIdx);
    mcuxClEls_setRequestedKeyProperties(sharedSecretProperties.word.value);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_ECKXH, options.word.value, ELS_CMD_BIG_ENDIAN);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccKeyExchangeInt_Async, MCUXCLELS_STATUS_OK_WAIT);
}
#endif /* MCUXCL_FEATURE_ELS_PUK_INTERNAL */


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_EccSign_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_EccSign_Async(
    mcuxClEls_EccSignOption_t options,
    mcuxClEls_KeyIndex_t keyIdx,
    uint8_t const * pInputHash,
    uint8_t const * pInputMessage,
    size_t inputMessageLength,
    uint8_t * pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_EccSign_Async);

    MCUXCLELS_INPUT_PARAM_CHECK_PROTECTED(mcuxClEls_EccSign_Async, (ELS_KS_CNT <= keyIdx));

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccSign_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    options.bits.revf = MCUXCLELS_ECC_REVERSEFETCH_ENABLE;

#ifdef MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING
    /* Increment drbg_block_counter. If the counter overflowed, the interrupt handler will
     * reseed the DRBG and reset the counter after the upcoming ELS operation. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Overflow handled in interrupt handler")
    mcuxClEls_rng_drbg_block_counter += MCUXCLELS_RNG_DRBG_ECCSIGN_INCREASE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
#endif /* MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING */

    mcuxClEls_setKeystoreIndex0(keyIdx);
    mcuxClEls_setInput0((options.bits.echashchl == 0u) ? pInputHash : pInputMessage, inputMessageLength);
    mcuxClEls_setOutput_fixedSize(pOutput);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_ECSIGN, options.word.value, ELS_CMD_BIG_ENDIAN);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccSign_Async, MCUXCLELS_STATUS_OK_WAIT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_EccVerify_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_EccVerify_Async(
    mcuxClEls_EccVerifyOption_t options,
    uint8_t const * pInputHash,
    uint8_t const * pInputMessage,
    size_t inputMessageLength,
    uint8_t const * pSignatureAndPubKey,
    uint8_t * pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_EccVerify_Async);

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccVerify_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    options.bits.revf = MCUXCLELS_ECC_REVERSEFETCH_ENABLE;
#ifdef MCUXCL_FEATURE_ELS_PUK_INTERNAL_BIT
    options.bits.extkey = MCUXCLELS_ECC_EXTKEY_EXTERNAL;
#endif /* MCUXCL_FEATURE_ELS_PUK_INTERNAL_BIT */

#ifdef MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING
    /* Increment drbg_block_counter. If the counter overflowed, the interrupt handler will
     * reseed the DRBG and reset the counter after the upcoming ELS operation. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Overflow handled in interrupt handler")
    mcuxClEls_rng_drbg_block_counter += MCUXCLELS_RNG_DRBG_ECCVERIFY_INCREASE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
#endif /* MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING */

    mcuxClEls_setInput0((options.bits.echashchl == 0u) ? pInputHash : pInputMessage, inputMessageLength);
    mcuxClEls_setInput1_fixedSize(pSignatureAndPubKey);
    mcuxClEls_setOutput_fixedSize(pOutput);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_ECVFY, options.word.value, ELS_CMD_BIG_ENDIAN);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccVerify_Async, MCUXCLELS_STATUS_OK_WAIT);
}

#ifdef MCUXCL_FEATURE_ELS_PUK_INTERNAL
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_EccVerifyInt_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_EccVerifyInt_Async(
    mcuxClEls_EccVerifyOption_t options,
    mcuxClEls_KeyIndex_t publicKeyIdx,
    uint8_t const * pInputHash,
    uint8_t const * pInputMessage,
    size_t inputMessageLength,
    uint8_t const * pSignature,
    uint8_t * pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_EccVerifyInt_Async);

    MCUXCLELS_INPUT_PARAM_CHECK_PROTECTED(mcuxClEls_EccVerifyInt_Async, (ELS_KS_CNT <= publicKeyIdx));

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccVerifyInt_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    options.bits.revf   = MCUXCLELS_ECC_REVERSEFETCH_ENABLE;
    options.bits.extkey = MCUXCLELS_ECC_EXTKEY_INTERNAL;

#ifdef MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING
    /* Increment drbg_block_counter. If the counter overflowed, the interrupt handler will
     * reseed the DRBG and reset the counter after the upcoming ELS operation. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Overflow handled in interrupt handler")
    mcuxClEls_rng_drbg_block_counter += MCUXCLELS_RNG_DRBG_ECCVERIFY_INCREASE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
#endif /* MCUXCL_FEATURE_ELS_ITERATIVE_SEEDING */

    mcuxClEls_setInput0((options.bits.echashchl == 0u) ? pInputHash : pInputMessage, inputMessageLength);
    mcuxClEls_setInput1_fixedSize(pSignature);
    mcuxClEls_setOutput_fixedSize(pOutput);
    mcuxClEls_setKeystoreIndex2(publicKeyIdx);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_ECVFY, options.word.value, ELS_CMD_BIG_ENDIAN);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_EccVerifyInt_Async, MCUXCLELS_STATUS_OK_WAIT);
}
#endif /* MCUXCL_FEATURE_ELS_PUK_INTERNAL */
