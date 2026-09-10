/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

#ifndef MCUXCLEXAMPLE_KEY_HELPER_H_
#define MCUXCLEXAMPLE_KEY_HELPER_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClKey.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

/**
 * Load key via mcuxClKey_loadMemory or mcuxClKey_loadCopro according to the key_loading_option parameter.
 * [in]      pSession:         Pointer to the session handle.
 * [in,out]  pKey:             Pointer to the key handle.
 * [in]      type:             Define which key type shall be initialized
 * [in]      pData:            Provide pointer to source data of the key
 * [in]      keyDataLength:    Number of bytes available in the pData array.
 * [in]      key_properties:   Pointer to the requested key properties of the destination key. Will be set in key->container.pAuxData
 * [in]      dst:              if MCUXCLEXAMPLE_CONST_EXTERNAL_KEY, Pointer to dstData, if MCUXCLEXAMPLE_CONST_INTERNAL_KEY, Pointer to dstSlot value
 * [in]      key_loading_option:0 = external key, 1 = internal key
 **/
#define MCUXCLEXAMPLE_CONST_EXTERNAL_KEY 0U
#define MCUXCLEXAMPLE_CONST_INTERNAL_KEY 1U
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClExample_Key_Init_And_Load)
static inline bool mcuxClExample_Key_Init_And_Load(mcuxClSession_Handle_t pSession,
                                                  mcuxClKey_Handle_t pKey,
                                                  mcuxClKey_Type_t type,
                                                  const uint8_t * pData,
                                                  uint32_t keyDataLength,
                                                  mcuxClEls_KeyProp_t * key_properties,
                                                  uint32_t * dst,
                                                  uint8_t key_loading_option)
{
    /* Init the key. */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClKey_init(
        /* mcuxClSession_Handle_t session         */ pSession,
        /* mcuxClKey_Handle_t key                 */ pKey,
        /* mcuxClKey_Type_t type                  */ type,
        /* const uint8_t * pKeyData              */ pData,
        /* uint32_t keyDataLength                */ keyDataLength)
    );

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != token) || (MCUXCLKEY_STATUS_OK != result))
    {
        return false;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Set the key properties. */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClKey_setKeyproperties(pKey,
                                                                             key_properties));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_setKeyproperties) != token) || (MCUXCLKEY_STATUS_OK != result))
    {
        return false;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    if(MCUXCLEXAMPLE_CONST_EXTERNAL_KEY == key_loading_option)
    {
        /* load key into destination memory buffer */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClKey_loadMemory(
                                   /* mcuxClSession_Handle_t pSession:   */ pSession,
                                   /* mcuxClKey_Handle_t key:            */ pKey,
                                   /* uint32_t * dstData:               */ dst));

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_loadMemory) != token) || (MCUXCLKEY_STATUS_OK != result))
        {
            return false;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
    }
    else
    {
        /* load key into destination key slot of coprocessor (key_slot = '*dst') */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClKey_loadCopro(
                                  /* mcuxClSession_Handle_t pSession:   */ pSession,
                                  /* mcuxClKey_Handle_t key:            */ pKey,
                                  /* uint32_t dstSlot:                 */ *dst));

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_loadCopro) != token) || (MCUXCLKEY_STATUS_OK != result))
        {
            return false;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
    }
    return true;
}

#endif /* MCUXCLEXAMPLE_KEY_HELPER_H_ */
