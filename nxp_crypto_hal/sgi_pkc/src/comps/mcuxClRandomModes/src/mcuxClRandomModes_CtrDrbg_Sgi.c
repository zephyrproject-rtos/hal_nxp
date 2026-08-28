/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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
#include <mcuxClAes.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <internal/mcuxClRandomModes_Private_ExitGates.h>
#include <internal/mcuxClResource_Internal_Types.h>
#include <internal/mcuxClResource_Internal_Functions.h>

/* ctr drbg defines */
#define MCUXCLRANDOMMODES_CTR_DRBG_SGI_MODE_GENERAL (MCUXCLSGI_DRV_CTRL_DATOUT_RES_END_UP | \
                                              MCUXCLSGI_DRV_CTRL_INKEYSEL(0u)            | \
                                              MCUXCLSGI_DRV_CTRL_INSEL_DATIN0            | \
                                              MCUXCLSGI_DRV_CTRL_ENC                     | \
                                              MCUXCLSGI_DRV_CTRL_AES_EN)

#define MCUXCLRANDOMMODES_CTR_DRBG_MODE_AES128_ENCRYPT (MCUXCLRANDOMMODES_CTR_DRBG_SGI_MODE_GENERAL |      \
                                                    MCUXCLSGI_DRV_CTRL_OUTSEL_RES                  |      \
                                                    MCUXCLSGI_DRV_CTRL_AES128)

#define MCUXCLRANDOMMODES_CTR_DRBG_MODE_AES192_ENCRYPT (MCUXCLRANDOMMODES_CTR_DRBG_SGI_MODE_GENERAL |      \
                                                    MCUXCLSGI_DRV_CTRL_OUTSEL_RES                  |      \
                                                    MCUXCLSGI_DRV_CTRL_AES192)

#define MCUXCLRANDOMMODES_CTR_DRBG_MODE_AES256_ENCRYPT (MCUXCLRANDOMMODES_CTR_DRBG_SGI_MODE_GENERAL |      \
                                                    MCUXCLSGI_DRV_CTRL_OUTSEL_RES                  |      \
                                                    MCUXCLSGI_DRV_CTRL_AES256)

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_requestHW)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_requestHW(mcuxClSession_Handle_t pSession)
{
 MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_requestHW);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(pSession, MCUXCLRESOURCE_HWID_SGI, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));


    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_requestHW,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_releaseHW)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_releaseHW(mcuxClSession_Handle_t pSession)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_releaseHW);


    /* Uninitialize (and release) the SGI hardware */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(pSession));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_releaseHW,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_cleanUpHW)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_cleanUpHW(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_cleanUpHW);

    // TODO CLNS-16291: FLUSH_KEY for SGI is not usable anymore with preloaded keys
    // mcuxClSgi_Drv_enableFlush(MCUXCLSGI_DRV_FLUSH_ALL);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_cleanUpHW);
}

/* Data Integrity: RECORD(MCUXCLAES_BLOCK_SIZE_IN_WORDS) */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadInput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadInput(
    uint32_t *pInputBlock
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadInput);
    /* Load input Block into SGI_DATIN0 */
    for(uint32_t i = 0u; i < (MCUXCLAES_BLOCK_SIZE_IN_WORDS); i++)
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN0_OFFSET + (4u*i), pInputBlock[i]));
        MCUX_CSSL_DI_RECORD(inputBlockLoads, 1U);
    }
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadInput,
        (MCUXCLAES_BLOCK_SIZE_IN_WORDS * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_loadWord))
    );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadKey(
    uint32_t const *pKey,
    uint32_t keyLength
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadKey);
    /* Record input data for mcuxClSgi_Utils_loadKey_secure() */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_MODIFY_STRING_LITERALS("False positive: The constant string literal pKey is not being modified");
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_loadKey_secure, pKey);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_MODIFY_STRING_LITERALS();
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_loadKey_secure, MCUXCLSGI_DRV_KEY0_OFFSET);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_loadKey_secure, keyLength);
    /* Load key into the SGI_KEY0 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClSgi_Utils_loadKey_secure(MCUXCLSGI_DRV_KEY0_OFFSET, (const uint8_t*)pKey, keyLength)
    );
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_AES_BlockEncrypt_LoadKey,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadKey_secure));
}

/* This function expects the block to start to encrypt in SGI DAT0 register. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt(
    mcuxClSession_Handle_t pSession,
    uint32_t keyLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt);

#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128) || (defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192) && defined(MCUXCL_FEATURE_AES192)) || defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256)
    MCUX_CSSL_FP_SWITCH_DECL(switchProtector);
#endif /* (defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128) && defined(MCUXCL_FEATURE_AES128)) || (defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192) && defined(MCUXCL_FEATURE_AES192)) || (defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256) && defined(MCUXCL_FEATURE_AES256)) */
    MCUX_CSSL_ANALYSIS_START_PATTERN_SWITCH_STATEMENT_RETURN_TERMINATION()
    switch(keyLength)
    {
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128)
        case MCUXCLAES_AES128_KEY_SIZE:
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLRANDOMMODES_CTR_DRBG_MODE_AES128_ENCRYPT));
            MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLAES_AES128_KEY_SIZE);
            MCUX_CSSL_DI_RECORD(switchKeySize, MCUXCLAES_AES128_KEY_SIZE);
        break;
#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128) && defined(MCUXCL_FEATURE_AES128) */
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192) && defined(MCUXCL_FEATURE_AES192)
        case MCUXCLAES_AES192_KEY_SIZE:
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLRANDOMMODES_CTR_DRBG_MODE_AES192_ENCRYPT));
            MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLAES_AES192_KEY_SIZE);
            MCUX_CSSL_DI_RECORD(switchKeySize, MCUXCLAES_AES192_KEY_SIZE);
        break;
#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192) && defined(MCUXCL_FEATURE_AES192) */
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256)
        case MCUXCLAES_AES256_KEY_SIZE:
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLRANDOMMODES_CTR_DRBG_MODE_AES256_ENCRYPT));
            MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLAES_AES256_KEY_SIZE);
            MCUX_CSSL_DI_RECORD(switchKeySize, MCUXCLAES_AES256_KEY_SIZE);
        break;
#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256) && defined(MCUXCL_FEATURE_AES256) */
        default:
            MCUXCLSESSION_FAULT(pSession, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_SWITCH_STATEMENT_RETURN_TERMINATION()

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_AES_StartBlockEncrypt,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start) /* Every non-default switch case calls mcuxClSgi_Drv_start */
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128)
        , MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLAES_AES128_KEY_SIZE, MCUXCLAES_AES128_KEY_SIZE == keyLength)
#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128) && defined(MCUXCL_FEATURE_AES128) */
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192) && defined(MCUXCL_FEATURE_AES192)
        , MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLAES_AES192_KEY_SIZE, MCUXCLAES_AES192_KEY_SIZE == keyLength)
#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192) && defined(MCUXCL_FEATURE_AES192) */
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256)
        , MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLAES_AES256_KEY_SIZE, MCUXCLAES_AES256_KEY_SIZE == keyLength)
#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256) && defined(MCUXCL_FEATURE_AES256) */
        );
}


/* This function get encrypt result. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt(
    mcuxClSession_Handle_t pSession,
    uint8_t*  pOut,
    const uint32_t *pXorMask,
    uint32_t keyLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt);

    mcuxClSgi_Drv_wait();

    if(pXorMask != NULL)
    {
        MCUX_CSSL_DI_RECORD(bufferReadDI, (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET));
        MCUX_CSSL_DI_RECORD(bufferReadDI, pXorMask);
        MCUX_CSSL_DI_RECORD(bufferReadDI, pOut);

        /* copy out result */
        /* Write to buffer from SGI, src pointer is calculated from sgiSfrDatIndex */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storeMasked128BitBlock(pSession,
                                                                               MCUXCLSGI_DRV_DATOUT_OFFSET,
                                                                               pOut,
                                                                               0u,
                                                                               pXorMask));
    }
    else
    {
        /* copy out result */
        MCUX_CSSL_DI_RECORD(bufferReadDI, (uint32_t)pOut + 0u + (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET) + MCUXCLAES_BLOCK_SIZE);
        /* Write to buffer from SGI, src pointer is calculated from sgiSfrDatIndex */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pOut));
    }

    MCUX_CSSL_DI_EXPUNGE(switchKeySize, keyLength);
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_AES_CompleteBlockEncrypt,
        MCUX_CSSL_FP_CONDITIONAL(pXorMask != NULL,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storeMasked128BitBlock)),
        MCUX_CSSL_FP_CONDITIONAL(pXorMask == NULL,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_CtrDrbg_incV)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_CtrDrbg_incV(mcuxClSession_Handle_t pSession)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_CtrDrbg_incV);

    /* Record for mcuxClSgi_Drv_incrementData call */
    MCUX_CSSL_DI_RECORD(inputParam, MCUXCLSGI_DRV_DATIN0_OFFSET);
    MCUX_CSSL_DI_RECORD(incLength, MCUXCLAES_BLOCK_SIZE);

    uint32_t vBeforeIncrement[MCUXCLAES_BLOCK_SIZE_IN_WORDS] = {0};
    MCUXCLBUFFER_INIT(vBeforeIncrementBuf, NULL, (uint8_t *)&vBeforeIncrement[0], MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_DI_RECORD(bufferWriteDI, (uint32_t)vBeforeIncrementBuf + 0u + (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET) + MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, vBeforeIncrementBuf));

    /* Increment SGI DATIN0 register */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_incrementData(MCUXCLSGI_DRV_DATIN0_OFFSET, MCUXCLAES_BLOCK_SIZE));

    uint32_t vAfterIncrement[MCUXCLAES_BLOCK_SIZE_IN_WORDS] = {0};
    MCUXCLBUFFER_INIT(vAfterIncrementBuf, NULL, (uint8_t *)&vAfterIncrement[0], MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_DI_RECORD(bufferWriteDI, (uint32_t)vAfterIncrementBuf + 0u + (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET) + MCUXCLAES_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, vAfterIncrementBuf));

    /* Check whether at the least the least significant word was updated or not */
    if(vBeforeIncrement[MCUXCLAES_BLOCK_SIZE_IN_WORDS-1u] == vAfterIncrement[MCUXCLAES_BLOCK_SIZE_IN_WORDS-1u])
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_CtrDrbg_incV,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_incrementData),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock));
}
