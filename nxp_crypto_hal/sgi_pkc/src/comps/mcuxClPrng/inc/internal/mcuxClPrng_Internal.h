/*--------------------------------------------------------------------------*/
/* Copyright 2022, 2024-2026 NXP                                            */
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
 * @file mcuxClPrng_Internal.h
 * @brief Top level header of mcuxClPrng component
 *
 * @defgroup mcuxClPrng mcuxClPrng
 * @brief component of Prng generation
 */

#ifndef MCUXCLPRNG_INTERNAL_H_
#define MCUXCLPRNG_INTERNAL_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClPrng_Internal_Types.h>
#include <internal/mcuxClPrng_Internal_Functions.h>

#include <mcuxClCore_Platform.h>
#include <platform_specific_headers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>

#if defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED) || defined(MCUXCL_FEATURE_PRNG_SGI)
#include <internal/mcuxClSgi_Drv.h>
#endif



#ifdef __cplusplus
extern "C" {
#endif

#if defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED)

/*
 * In case of SGi SFRSEED based PRNG, first we must backup SGI_CTRL and SGI_CTRL2.
 * Then  We need to set SMASKSW=0 and SMASKEN=0 to get random from SFRSEED and set SMASKSTEP = 1 to update SFRSEED on read.
 * On other types of PRNG this macro is empty
 */

#define MCUXCLPRNG_INIT() \
  mcuxClSgi_Drv_wait(); \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCtrl)); \
  MCUX_CSSL_FP_FUNCTION_CALL(sgictrl__, mcuxClSgi_Drv_getCtrl()); \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCtrl2)); \
  MCUX_CSSL_FP_FUNCTION_CALL(sgictrl2__, mcuxClSgi_Drv_getCtrl2()); \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init)); \
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_SFR_CTRL2_SMASKSTEP));

/* In case of SGi SFRSEED based PRNG restore SGI_CTRL and SGI_CTRL2. In other types of PRNG do nothing. */
#define MCUXCLPRNG_RESTORE() \
  mcuxClSgi_Drv_wait(); \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setCtrl)); \
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_setCtrl(sgictrl__)); \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setCtrl2)); \
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_setCtrl2(sgictrl2__));

#define MCUXCLPRNG_GET_WORD(ret) \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getSfrSeed)); \
  MCUX_CSSL_FP_FUNCTION_CALL(ret, mcuxClSgi_Drv_getSfrSeed())

#elif defined(MCUXCL_FEATURE_PRNG_SGI)

#define MCUXCLPRNG_INIT()
#define MCUXCLPRNG_RESTORE()

#define MCUXCLPRNG_GET_WORD(ret) \
  MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getPrngWord)); \
  MCUX_CSSL_FP_FUNCTION_CALL(ret, mcuxClSgi_Drv_getPrngWord())


#else
#error Please ensure that the PRNG flags are properly configured
#endif

/**
 * @brief Non-cryptographic PRNG data word generation function.
 *
 * This function returns a non-cryptographic random data word
 * The source of PRNG random number can be SCM or SGI:
 *  - In case of SCM it utilizes SCM_PRNG_OUT
 *  - In cas of SGI, the source is SFRMASK generator.
 *  - If none of above sources are available (PRNG_NONE), it returns fixed number 0xF0F0F0F0u
 *
 * The seeding PRNG sources is not supported.
 *
 * @return 32-bit random data
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPrng_generate_word)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClPrng_generate_word(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPRNG_INTERNAL_H_ */
