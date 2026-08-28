/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxClFfdh_Constants.h
 * @brief Constant definitions of mcuxClFfdh component
 */


#ifndef MCUXCLFFDH_CONSTANTS_H
#define MCUXCLFFDH_CONSTANTS_H


#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClFfdh_ParameterSizes mcuxClFfdh_ParameterSizes
 * @brief Defines domain parameter, key and signature sizes of @ref mcuxClFfdh
 * @ingroup mcuxClFfdh
 * @{
 */

/**
 * @addtogroup MCUXCLFFDH_FFDHE2048_SIZE
 * FFDH parameter size definitions for ffdhe2048
 * @{ */
#define MCUXCLFFDH_FFDHE2048_SIZE_PRIMEP                     (256U)
#define MCUXCLFFDH_FFDHE2048_SIZE_PRIMEQ                     (256U)
#define MCUXCLFFDH_FFDHE2048_SIZE_PUBLICKEY                  (MCUXCLFFDH_FFDHE2048_SIZE_PRIMEP)
#define MCUXCLFFDH_FFDHE2048_SIZE_PRIVATEKEY                 (MCUXCLFFDH_FFDHE2048_SIZE_PRIMEQ)
#define MCUXCLFFDH_FFDHE2048_SIZE_SHAREDSECRET               (MCUXCLFFDH_FFDHE2048_SIZE_PRIMEP)
/** @} */  /* MCUXCLFFDH_FFDHE2048_SIZE */

/**
 * @addtogroup MCUXCLFFDH_FFDHE3072_SIZE
 * FFDH parameter size definitions for ffdhe3072
 * @{ */
#define MCUXCLFFDH_FFDHE3072_SIZE_PRIMEP                     (384U)
#define MCUXCLFFDH_FFDHE3072_SIZE_PRIMEQ                     (384U)
#define MCUXCLFFDH_FFDHE3072_SIZE_PUBLICKEY                  (MCUXCLFFDH_FFDHE3072_SIZE_PRIMEP)
#define MCUXCLFFDH_FFDHE3072_SIZE_PRIVATEKEY                 (MCUXCLFFDH_FFDHE3072_SIZE_PRIMEQ)
#define MCUXCLFFDH_FFDHE3072_SIZE_SHAREDSECRET               (MCUXCLFFDH_FFDHE3072_SIZE_PRIMEP)
/** @} */  /* MCUXCLFFDH_FFDHE3072_SIZE */

/**
 * @addtogroup MCUXCLFFDH_FFDHE4096_SIZE
 * FFDH parameter size definitions for ffdhe4096
 * @{ */
#define MCUXCLFFDH_FFDHE4096_SIZE_PRIMEP                     (512U)
#define MCUXCLFFDH_FFDHE4096_SIZE_PRIMEQ                     (512U)
#define MCUXCLFFDH_FFDHE4096_SIZE_PUBLICKEY                  (MCUXCLFFDH_FFDHE4096_SIZE_PRIMEP)
#define MCUXCLFFDH_FFDHE4096_SIZE_PRIVATEKEY                 (MCUXCLFFDH_FFDHE4096_SIZE_PRIMEQ)
#define MCUXCLFFDH_FFDHE4096_SIZE_SHAREDSECRET               (MCUXCLFFDH_FFDHE4096_SIZE_PRIMEP)
/** @} */  /* MCUXCLFFDH_FFDHE4096_SIZE */

#ifdef MCUXCL_FEATURE_FFDH_RFC7919_FFDHE6144
/**
 * @addtogroup MCUXCLFFDH_FFDHE6144_SIZE
 * FFDH parameter size definitions for ffdhe6144
 * @{ */
#define MCUXCLFFDH_FFDHE6144_SIZE_PRIMEP                     (768U)
#define MCUXCLFFDH_FFDHE6144_SIZE_PRIMEQ                     (768U)
#define MCUXCLFFDH_FFDHE6144_SIZE_PUBLICKEY                  (MCUXCLFFDH_FFDHE6144_SIZE_PRIMEP)
#define MCUXCLFFDH_FFDHE6144_SIZE_PRIVATEKEY                 (MCUXCLFFDH_FFDHE6144_SIZE_PRIMEQ)
#define MCUXCLFFDH_FFDHE6144_SIZE_SHAREDSECRET               (MCUXCLFFDH_FFDHE6144_SIZE_PRIMEP)
/** @} */  /* MCUXCLFFDH_FFDHE6144_SIZE */
#endif /* MCUXCL_FEATURE_FFDH_RFC7919_FFDHE6144 */

#ifdef MCUXCL_FEATURE_FFDH_RFC7919_FFDHE8192
/**
 * @addtogroup MCUXCLFFDH_FFDHE8192_SIZE
 * FFDH parameter size definitions for ffdhe8192
 * @{ */
#define MCUXCLFFDH_FFDHE8192_SIZE_PRIMEP                     (1024U)
#define MCUXCLFFDH_FFDHE8192_SIZE_PRIMEQ                     (1024U)
#define MCUXCLFFDH_FFDHE8192_SIZE_PUBLICKEY                  (MCUXCLFFDH_FFDHE8192_SIZE_PRIMEP)
#define MCUXCLFFDH_FFDHE8192_SIZE_PRIVATEKEY                 (MCUXCLFFDH_FFDHE8192_SIZE_PRIMEQ)
#define MCUXCLFFDH_FFDHE8192_SIZE_SHAREDSECRET               (MCUXCLFFDH_FFDHE8192_SIZE_PRIMEP)
/** @} */  /* MCUXCLFFDH_FFDHE8192_SIZE */
#endif /* MCUXCL_FEATURE_FFDH_RFC7919_FFDHE8192 */

/**
 * @}
 */ /* mcuxClFfdh_ParameterSizes */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLFFDH_CONSTANTS_H */
