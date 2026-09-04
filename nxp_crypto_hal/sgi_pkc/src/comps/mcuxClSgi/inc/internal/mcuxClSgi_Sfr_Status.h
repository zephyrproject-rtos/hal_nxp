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

#ifndef MCUXCLSGI_SFR_STATUS_H_
#define MCUXCLSGI_SFR_STATUS_H_

#include <mcuxCsslFlowProtection.h>
#include <platform_specific_headers.h>
#include <internal/mcuxClSgi_SfrAccess.h>


/* Macros for the SGI_STATUS SFR */
#define MCUXCLSGI_SFR_STATUS_ERROR_NO_ERROR  (0x5U) ///< No errors reported in SGI_STATUS.ERROR bits. All other values indicate an error.

#define MCUXCLSGI_SFR_STATUS_ERROR(status) ((MCUXCLSGI_SFR_STATUS_ERROR_NO_ERROR << MCUXCLSGI_SFR_BITPOS(STATUS,ERROR)) != ((status) & MCUXCLSGI_SFR_BITMSK(STATUS,ERROR)))
#define MCUXCLSGI_SFR_STATUS_SHA_ERROR(status)  (0U != ((status) & MCUXCLSGI_SFR_BITMSK(STATUS,SHA_ERROR)))
#define MCUXCLSGI_SFR_STATUS_BUSY(status)  (0U != ((status) & MCUXCLSGI_SFR_BITMSK(STATUS,BUSY)))

#ifdef SGI_HAS_KEY_WRAP_UNWRAP
#define MCUXCLSGI_SFR_STATUS_HAS_KEY_UNWRAP_ERROR(status) (0U != ((status) & MCUXCLSGI_SFR_BITMSK(STATUS,KEY_UNWRAP_ERR)))
#endif /* SGI_HAS_KEY_WRAP_UNWRAP */

#ifdef SGI_HAS_ACCESS_ERR
/* Macros for the SGI_ACCESS_ERR SFR */
#define MCUXCLSGI_SFR_ACCESS_ERROR(accessErr) (0U != (accessErr))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Read the SGI STATUS register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readStatus)
static inline uint32_t mcuxClSgi_Sfr_readStatus(void)
{
  return MCUXCLSGI_SFR_READ(STATUS);
}

#ifdef SGI_HAS_ACCESS_ERR
/**
 * Read the SGI ACCESS_ERR register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readAccessError)
static inline uint32_t mcuxClSgi_Sfr_readAccessError(void)
{
  return MCUXCLSGI_SFR_READ(ACCESS_ERR);
}
#endif /* SGI_HAS_ACCESS_ERR */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSGI_SFR_STATUS_H_ */
