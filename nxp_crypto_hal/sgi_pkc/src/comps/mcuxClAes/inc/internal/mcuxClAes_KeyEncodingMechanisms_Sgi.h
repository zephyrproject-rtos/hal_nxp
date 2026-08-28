/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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
 * @file  mcuxClAes_KeyEncodingMechanisms_Sgi.h
 * @brief Internal function definitions for AES key encoding mechanisms
 *        and associated helpers using the SGI
 */

#ifndef MCUXCLAES_KEYENCODINGMECHANISMS_SGI_H_
#define MCUXCLAES_KEYENCODINGMECHANISMS_SGI_H_

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
 * @brief Key load function into the SGI for encoding RFC3394
 *
 * @param[in]     session  Handle of the current session
 * @param[in]     key      Key handle for the loaded key (word-aligned)
 * @param[in,out] ppDest   Destination address of the key in the SGI.
 * @param[in]     pKeyChecksums  Storing data needed for masked key generation
 * @param[in]     spec     Specifications about the used key
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_keyLoad_rfc3394, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyLoad_rfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint8_t **ppDest,
  mcuxClKey_KeyChecksum_t * pKeyChecksums,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Key store function from the SGI for encoding RFC3394
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Key handle for the store key (word-aligned)
 * @param[in]   pSrc     Source address of the key in the SGI.
 *                       The SFRs of the SGI only support 32 bit access
 * @param[in]   spec     Specifications about the used key
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_keyStore_rfc3394, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyStore_rfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t *pSrc,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Get the key destination for loading a key in the SGI for RFC3394 wrap.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_getKeyDest_rfc3394UnWrap)
static inline uint8_t* mcuxClAes_getKeyDest_rfc3394UnWrap(void)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_WRITE()
  volatile uint32_t* keyDestAddr = (volatile uint32_t*)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_KEY_OFFSET_UNWRAP_DEST);
  return ((uint8_t *)keyDestAddr);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_WRITE()
}

/**
 * @brief Get the key destination for a key that is unwrapped via the SGI RFC3394 feature.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_getKeyDest_rfc3394Wrap)
static inline uint8_t* mcuxClAes_getKeyDest_rfc3394Wrap(void)
{
  return ((uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATIN0_OFFSET));
}

/**
 * @brief Key unwrap function as specified in RFC3394. This uses software algorithm
 *        in combination with SGI AES block decrypt operations.
 *
 * - The unwrapped key material is copied to `pKeyDst` with a special type of SFR masking.
 * - The function unwraps the key in blocks of `RFC3394_BLOCK_SIZE` and the `SfrSeed`
 *   for masking is re-initialized for each block before the unwrapped key is copied from SGI.
 * - When the protected keys are to be used in the SGI later, they had to be loaded in the
 *   same way, with this special SFR masking, for them to be unmasked correctly.
 * - The `mcuxClSgi_Utils_keyWrapRfc3394` is the only function at the moment that can handle
 *   this special type of SFR masking.
 *
 * @post The unwrapped key material is masked and stored in the `pKeyDst`.
 *
 * @param[in]     session     Handle of the current session
 * @param[in]     wrappedKey  Initialized key handle with wrapped key (word-aligned).
 * @param[out]    pKeyDst     Pointer to location where unwrapped key will be stored.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_keyUnwrapRfc3394_swDriven)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyUnwrapRfc3394_swDriven(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t wrappedKey,
  uint32_t *pKeyDst
);


/**
 * @brief Key flush function for AES keys stored in SGI
 *
 * This function flushes the key registers the given @p key is loaded to
 * with random data.
 *
 * @pre The key must be loaded to a valid SGI key slot.
 *
 * @param[in]   session  Handle of the current session
 * @param[in]   key      Key handle for the key to flush (word-aligned)
 * @param[in]   spec     Specifications about the used key - unused
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAes_keyFlush, mcuxClKey_FlushFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyFlush(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClKey_Encoding_Spec_t spec
);

/**
 * @brief Get the default key destination for loading a key in the SGI.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_getKeyDest_default)
static inline uint8_t* mcuxClAes_getKeyDest_default(void)
{
  return ((uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_KEY0_OFFSET));
}




#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAES_KEYENCODINGMECHANISMS_SGI_H_ */
