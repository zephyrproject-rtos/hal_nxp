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

/** @file  mcuxClOsccaAeadModes_EngineCcm.c
 *  @brief implementation of the AES CCM Engine functions of the mcuxClAead component */

#include <mcuxClToolchain.h>
#include <mcuxClAead.h>
#include <mcuxClOsccaAeadModes.h>
#include <mcuxClMac.h>
#include <mcuxClOsccaMacModes.h>
#include <mcuxClSession.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Types.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Functions.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Algorithms.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaAeadModes_EngineCcm, mcuxClOsccaAeadModes_Engine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_EngineCcm (
  mcuxClSession_Handle_t session,
  mcuxClOsccaAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength UNUSED_PARAM,
  uint32_t options  //!< options is a bitmask with one bit reserved for each of the operations
  )
{
    /* [Design]

        - Note:
            - options is a bitmask:  1: auth, 2: enc, 3: aead, 4: init, 8: finish
            - processing is done in this particular order such that in-place encryption/decryption is supported

        - Preconditions
            - mode in context has been initialized
            - inLength is a multiple of the block size (16 bytes)

        - Initialization
            - set pData equal to pIn

        - Decryption  (options == enc / aead AND direction = decryption)
            - set pData equal to pOut
            - use SM4 in CTR mode to decrypt the data pIn and store the output at pOut

        - Authentication (options == auth / aead)
            - use SM4 in CBC-MAC mode to update the state in the context with the contents of pData

        - Encryption  (options == enc / aead AND direction = encryption)
            - use SM4 in CTR mode to encrypt the data pIn and store the output at pOut

        - exit
    */

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaAeadModes_EngineCcm);
    mcuxClOsccaAeadModes_Context_t * pCtx = (mcuxClOsccaAeadModes_Context_t *) pContext;
    uint32_t roundKeys[128];
    MCUX_CSSL_FP_FUNCTION_CALL(setupResult, mcuxClOsccaSm4_ScheduleSM4Key(roundKeys, pCtx->key->container.pData, MCUXCLOSCCASM4_ENCRYPT));
    if(MCUXCLOSCCASM4_STATUS_LOADKEY_OK != setupResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_EngineCcm, MCUXCLAEAD_STATUS_ERROR);
    }

    if(options == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_INIT)
    {

    }

    if(((options & MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC) == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC)
        && (MCUXCLOSCCASM4_DECRYPT == pCtx->direction))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(ctrRet, mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr(
                                                                roundKeys,
                                                                pIn,
                                                                inLength,
                                                                &pCtx->state[48],
                                                                pOut));

        if(MCUXCLAEAD_STATUS_OK != ctrRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_EngineCcm, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if((options & MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AUTH) == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AUTH)
    {
        if((options == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AEAD) && (MCUXCLOSCCASM4_DECRYPT == pCtx->direction))
        {
            uint32_t cbcmac_data_size = 0u;
            MCUX_CSSL_FP_FUNCTION_CALL(cmacResult, mcuxClMac_compute(
            /* mcuxClSession_Handle_t session, */ session,
            /* mcuxClKey_Handle_t key,         */ pCtx->key,
            /* mcuxClCipher_Mode_t mode,       */ mcuxClOsccaMac_Mode_CBCMAC_NoPadding,
            /* const uint8_t * const pIn,     */ pOut,
            /* uint32_t inLength,             */ inLength,
            /* uint8_t * const pOut,          */ pCtx->state,
            /* uint32_t * const pOutLength    */ &cbcmac_data_size
            ));
            if( MCUXCLMAC_STATUS_OK != cmacResult)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_EngineCcm, MCUXCLAEAD_STATUS_ERROR);
            }
        }
        else
        {
            uint32_t cbcmac_data_size = 0u;
            MCUX_CSSL_FP_FUNCTION_CALL(cmacResult, mcuxClMac_compute(
            /* mcuxClSession_Handle_t session, */ session,
            /* mcuxClKey_Handle_t key,         */ pCtx->key,
            /* mcuxClCipher_Mode_t mode,       */ mcuxClOsccaMac_Mode_CBCMAC_NoPadding,
            /* const uint8_t * const pIn,     */ pIn,
            /* uint32_t inLength,             */ inLength,
            /* uint8_t * const pOut,          */ pCtx->state,
            /* uint32_t * const pOutLength    */ &cbcmac_data_size
            ));
            if( MCUXCLMAC_STATUS_OK != cmacResult)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_EngineCcm, MCUXCLAEAD_STATUS_ERROR);
            }
        }
    }

    if(((options & MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC) == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC)
      && (MCUXCLOSCCASM4_ENCRYPT == pCtx->direction))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(ctrRet, mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr(
                                                                roundKeys,
                                                                pIn,
                                                                inLength,
                                                                &pCtx->state[48],
                                                                pOut));
        if(MCUXCLAEAD_STATUS_OK != ctrRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_EngineCcm, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_EngineCcm, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_ScheduleSM4Key),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC) == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC)
                                && (MCUXCLOSCCASM4_DECRYPT == pCtx->direction),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr)
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AUTH) == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_AUTH),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute)
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC) == MCUXCLOSCCAAEADMODES_ENGINE_OPTION_ENC)
                                && (MCUXCLOSCCASM4_ENCRYPT == pCtx->direction),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr)
        )
    );
}

const mcuxClOsccaAeadModes_algorithm_t mcuxClOsccaAead_algorithm_CCM_ENC = {
    .pSkeleton = mcuxClOsccaAeadModes_SkeletonCcm,
    .pEngine = mcuxClOsccaAeadModes_EngineCcm,
    .protection_token_skeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_SkeletonCcm),
    .protection_token_engine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_EngineCcm),
    .direction = MCUXCLOSCCASM4_ENCRYPT
};

const mcuxClOsccaAeadModes_algorithm_t mcuxClOsccaAead_algorithm_CCM_DEC = {
    .pSkeleton = mcuxClOsccaAeadModes_SkeletonCcm,
    .pEngine = mcuxClOsccaAeadModes_EngineCcm,
    .protection_token_skeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_SkeletonCcm),
    .protection_token_engine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaAeadModes_EngineCcm),
    .direction = MCUXCLOSCCASM4_DECRYPT
};

