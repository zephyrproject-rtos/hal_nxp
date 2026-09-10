/*--------------------------------------------------------------------------*/
/* Copyright 2022 NXP                                                       */
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
 * @file  mcuxClEls_Internal_mapping.h
 * @brief Header providing mapping for legacy definitions (with CSS)
 */

#ifndef MCUXCLELS_INTERNAL_MAPPING_H_
#define MCUXCLELS_INTERNAL_MAPPING_H_

#if !defined(ELS_KS_CNT)
#define ELS_KS_CNT  CSS_KS_CNT
#endif

#if !defined(ID_CFG_ELS_CMD_AUTH_CIPHER)
#define ID_CFG_ELS_CMD_AUTH_CIPHER  ID_CFG_CSS_CMD_AUTH_CIPHER
#endif
#if !defined(ID_CFG_ELS_CMD_CHAL_RESP_GEN)
#define ID_CFG_ELS_CMD_CHAL_RESP_GEN  ID_CFG_CSS_CMD_CHAL_RESP_GEN
#endif
#if !defined(ID_CFG_ELS_CMD_CIPHER)
#define ID_CFG_ELS_CMD_CIPHER  ID_CFG_CSS_CMD_CIPHER
#endif
#if !defined(ID_CFG_ELS_CMD_CKDF)
#define ID_CFG_ELS_CMD_CKDF  ID_CFG_CSS_CMD_CKDF
#endif
#if !defined(ID_CFG_ELS_CMD_CMAC)
#define ID_CFG_ELS_CMD_CMAC  ID_CFG_CSS_CMD_CMAC
#endif
#if !defined(ID_CFG_ELS_CMD_DRBG_TEST)
#define ID_CFG_ELS_CMD_DRBG_TEST  ID_CFG_CSS_CMD_DRBG_TEST
#endif
#if !defined(ID_CFG_ELS_CMD_DTRNG_CFG_LOAD)
#define ID_CFG_ELS_CMD_DTRNG_CFG_LOAD  ID_CFG_CSS_CMD_DTRNG_CFG_LOAD
#endif
#if !defined(ID_CFG_ELS_CMD_DTRNG_EVAL)
#define ID_CFG_ELS_CMD_DTRNG_EVAL  ID_CFG_CSS_CMD_DTRNG_EVAL
#endif
#if !defined(ID_CFG_ELS_CMD_DTRNG_PRVL_CFG_LOAD)
#define ID_CFG_ELS_CMD_DTRNG_PRVL_CFG_LOAD  ID_CFG_CSS_CMD_DTRNG_PRVL_CFG_LOAD
#endif
#if !defined(ID_CFG_ELS_CMD_ECKXH)
#define ID_CFG_ELS_CMD_ECKXH  ID_CFG_CSS_CMD_ECKXH
#endif
#if !defined(ID_CFG_ELS_CMD_ECSIGN)
#define ID_CFG_ELS_CMD_ECSIGN  ID_CFG_CSS_CMD_ECSIGN
#endif
#if !defined(ID_CFG_ELS_CMD_ECVFY)
#define ID_CFG_ELS_CMD_ECVFY  ID_CFG_CSS_CMD_ECVFY
#endif
#if !defined(ID_CFG_ELS_CMD_GDET_CFG_LOAD)
#define ID_CFG_ELS_CMD_GDET_CFG_LOAD  ID_CFG_CSS_CMD_GDET_CFG_LOAD
#endif
#if !defined(ID_CFG_ELS_CMD_GDET_TRIM)
#define ID_CFG_ELS_CMD_GDET_TRIM  ID_CFG_CSS_CMD_GDET_TRIM
#endif
#if !defined(ID_CFG_ELS_CMD_HASH)
#define ID_CFG_ELS_CMD_HASH  ID_CFG_CSS_CMD_HASH
#endif
#if !defined(ID_CFG_ELS_CMD_HKDF)
#define ID_CFG_ELS_CMD_HKDF  ID_CFG_CSS_CMD_HKDF
#endif
#if !defined(ID_CFG_ELS_CMD_HMAC)
#define ID_CFG_ELS_CMD_HMAC  ID_CFG_CSS_CMD_HMAC
#endif
#if !defined(ID_CFG_ELS_CMD_KDELETE)
#define ID_CFG_ELS_CMD_KDELETE  ID_CFG_CSS_CMD_KDELETE
#endif
#if !defined(ID_CFG_ELS_CMD_KEYGEN)
#define ID_CFG_ELS_CMD_KEYGEN  ID_CFG_CSS_CMD_KEYGEN
#endif
#if !defined(ID_CFG_ELS_CMD_KEYIN)
#define ID_CFG_ELS_CMD_KEYIN  ID_CFG_CSS_CMD_KEYIN
#endif
#if !defined(ID_CFG_ELS_CMD_KEYOUT)
#define ID_CFG_ELS_CMD_KEYOUT  ID_CFG_CSS_CMD_KEYOUT
#endif
#if !defined(ID_CFG_ELS_CMD_KEYPROV)
#define ID_CFG_ELS_CMD_KEYPROV  ID_CFG_CSS_CMD_KEYPROV
#endif
#if !defined(ID_CFG_ELS_CMD_TLS)
#define ID_CFG_ELS_CMD_TLS  ID_CFG_CSS_CMD_TLS
#endif

#if (!defined(ID_CFG_ELS_CMD_RND_REQ)) && defined(ID_CFG_CSS_CMD_RND_REQ)
#define ID_CFG_ELS_CMD_RND_REQ  ID_CFG_CSS_CMD_RND_REQ
#endif

#if (!defined(ID_CFG_ELS_CMD_DRBG_REQ)) && defined(ID_CFG_CSS_CMD_DRBG_REQ)
#define ID_CFG_ELS_CMD_DRBG_REQ  ID_CFG_CSS_CMD_DRBG_REQ
#endif


#endif /* MCUXCLELS_INTERNAL_MAPPING_H_ */
