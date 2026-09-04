/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClAes_Internal_Functions.h
 * @brief Internal helper function definitions for the mcuxClAes component
 */

#ifndef MCUXCLAES_INTERNAL_FUNCTIONS_H_
#define MCUXCLAES_INTERNAL_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClKey.h>
#include <mcuxClSgi_Types.h>
#include <mcuxClSgi_Constants.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClAes_Wa.h>
#include <internal/mcuxClAes_Ctx.h>
#include <mcuxClAes_Types.h>
#include <internal/mcuxClKey_Types_Internal.h>

#include <mcuxClResource_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Internal function, which loads a given key and stores it in the SGI.
 * The function evaluates the key type and size and can handle protected keys.
 *
 * This function is an SGI specific function and acts as a wrapper to the
 * key->encoding.loadFunc function, and also sets fields for key details in the
 * workarea, if needed.
 *
 * @post If the key is not preloaded, the key data is loaded to the SGI,
 *       and the key's loadStatus location is updated to @ref MCUXCLKEY_LOADSTATUS_LOCATION_COPRO.
 *       The workarea is updated to reflect the key status and details.
 *
 * @param[in]  session             Current session handle.
 * @param[in]  key                 Handle for the key to be loaded to SGI (word-aligned).
 * @param[in]  pWa                 Pointer to the common workarea fields for Cipher/Mac/Aead (word-aligned).
 *                                 Can also be NULL if not needed.
 * @param[in]  keyOffset           Offset of the target KEY SGI SFR,
 *                                 can be either of these values:
 *                                   #MCUXCLSGI_DRV_KEY0_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY1_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY2_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY3_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY4_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY5_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY6_OFFSET
 *                                   #MCUXCLSGI_DRV_KEY7_OFFSET
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_loadKey_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_loadKey_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClAes_Workarea_Sgi_t* pWa,
  uint32_t keyOffset
);

/**
 * @brief Internal function to store the key from the SGI to the AES key context.
 *
 * Stores the key handle in the context.
 *
 * @pre Function @ref mcuxClAes_loadKey_Sgi was called to load the key and initialize the workarea.
 * @post The context is updated to reflect the key storage.
 *
 * @param[in]  session   Current session handle.
 * @param[in]  key       Handle for the key to be loaded to SGI (word-aligned).
 * @param[in]  pContext  Pointer to the context, where the key will be stored (word-aligned).
 * @param[in]  pWa       Pointer to the common workarea fields for Cipher/Mac/Aead (word-aligned).
 *                       Can also be NULL if not needed, e.g. when storing Clib internal keys.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_storeKeyInCtx_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_storeKeyInCtx_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClAes_KeyContext_Sgi_t * const pContext,
  mcuxClAes_Workarea_Sgi_t* pWa);

/**
 * @brief Internal function to store subkey from the SGI to the AES subkey context.
 *
 * Store subkey SFR-masked in the context.
 * This function implements masked key storage according to SREQI_BCIPHER_2.
 *
 * @param[in]  session   Current session handle.
 * @param[in]  pContext  Pointer to the context, where the key will be stored (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_storeMaskedSubKeyInCtx_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_storeMaskedSubKeyInCtx_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClAes_HKeyContext_Sgi_t * const pContext);

/**
 * @brief Internal function to load the key from the AES key context to the SGI.
 *
 * This function implements key loading according to SREQI_BCIPHER_2.
 * It shall also be used for re-loading keys that could not be stored in context due to
 * WRITE_ONLY SGI key registers (rfc3394).
 *
 * Loads the key into the SGI with the key handle in the context.
 *
 * @pre Function @ref mcuxClAes_storeKeyInCtx_Sgi was called to store the key and
 *      update the context.
 * @post The context and/or workarea are updated to reflect the key load status and details.
 *
 * @param[in]  session   Current session handle.
 * @param[in]  pContext  Pointer to the context, from which the key will be loaded (word-aligned).
 * @param[in]  pWa       Pointer to the common workarea fields for Cipher/Mac/Aead (word-aligned).
 *                       Can also be NULL if not needed, e.g. when loading Clib internal keys.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_loadKeyFromCtx_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_loadKeyFromCtx_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClAes_KeyContext_Sgi_t * const pContext,
  mcuxClAes_Workarea_Sgi_t* pWa);

/**
 * @brief Internal function to load the key from the AES key context to the SGI.
 *
 * This function implements masked key loading according to SREQI_BCIPHER_2.
 * Used for loading H-Key.
 *
 * Subkey was stored SFR masked in the context, copy it back to SGI. This implements
 * masked key loading from context according to SREQI_BCIPHER_2.
 *
 * @param[in]  session   Current session handle.
 * @param[in]  pContext  Pointer to the context, from which the key will be loaded (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_loadMaskedSubKeyFromCtx_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_loadMaskedSubKeyFromCtx_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClAes_HKeyContext_Sgi_t * const pContext);

/**
 * @brief Internal function to flush the key in the context from its SGI key slot.
 *
 * This function flushes the key in the context from the SGI in case the key was
 * not preloaded by the customer.
 * If the key is preloaded (see @ref MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED),
 * the flush is skipped.
 *
 * @post: If the key is not preloaded, the key in the context is flushed from the SGI, and
 *        the key's loadStatus is updated to @ref MCUXCLKEY_LOADSTATUS_NOT_LOADED.
 *        The context is updated to reflect the changes.
 *
 * @param[in]  session   Current session handle.
 * @param[in]  pContext  Pointer to the context, from which the key will be loaded (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_flushKeyInSgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_flushKeyInSgi(
  mcuxClSession_Handle_t session,
  mcuxClAes_KeyContext_Sgi_t * const pContext);

/**
 * @brief Internal function to flush the subkey from its SGI key slot.
 *
 * This function flushes the subkey from SGI if pContext indicates it needs flushing.
 *
 * @post: The H-Key in key slot 2 is flushed from the SGI.
 *
 * @param[in]  session   Current session handle.
 * @param[in]  pContext  Pointer to the context, which indicates if subkey needs flushing (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_flushSubKeyInSgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_flushSubKeyInSgi(
  mcuxClSession_Handle_t session,
  mcuxClAes_HKeyContext_Sgi_t * const pContext);






#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAES_INTERNAL_FUNCTIONS_H_ */
