/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023, 2025 NXP                                            */
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

#ifndef MCUXCLSGI_SFR_SEC_H_
#define MCUXCLSGI_SFR_SEC_H_

#include <mcuxCsslFlowProtection.h>
#include <platform_specific_headers.h>
#include <internal/mcuxClSgi_SfrAccess.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Read the SGI COUNT register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readCount)
static inline uint32_t mcuxClSgi_Sfr_readCount(void)
{

  // TODO CLNS-18218: The SGI_COUNT bit length is 16-bits for certain variants (eg A20), while it is 32-bits for other variants (eg A2ts/W70).
  // This bit differnce for variants will be handled in the ticket together with a feature flag.

  // This workaround shall be only done for when the SGI_COUNT is 16-bits.
  return MCUXCLSGI_SFR_READ(COUNT) & 0xFFFFU;
}

/**
 * Write the SGI COUNT register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_writeCount)
static inline void mcuxClSgi_Sfr_writeCount(uint32_t value)
{
  MCUXCLSGI_SFR_WRITE(COUNT, value);
}

/**
 * Read the SGI KEYCHK register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readKeyChk)
static inline uint32_t mcuxClSgi_Sfr_readKeyChk(void)
{
  return MCUXCLSGI_SFR_READ(KEYCHK);
}

/**
 * Write the SGI KEYCHK register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_writeKeyChk)
static inline void mcuxClSgi_Sfr_writeKeyChk(uint32_t value)
{
  MCUXCLSGI_SFR_WRITE(KEYCHK, value);
}


#ifdef MCUXCL_FEATURE_PRNG_SGI
/**
 * Read the SGI PRNG SW READ register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readPrngSwRead)
static inline uint32_t mcuxClSgi_Sfr_readPrngSwRead(void)
{
  return MCUXCLSGI_SFR_READ(PRNG_SW_READ);
}

/**
 * Write to the SGI PRNG SW SEED register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_writePrngSwSeed)
static inline void mcuxClSgi_Sfr_writePrngSwSeed(uint32_t value)
{
  MCUXCLSGI_SFR_WRITE(PRNG_SW_SEED, value);
}
#endif /* MCUXCL_FEATURE_PRNG_SGI*/

/**
 * Read the SGI SEED register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readSfrSeed)
static inline uint32_t mcuxClSgi_Sfr_readSfrSeed(void)
{
  return MCUXCLSGI_SFR_READ(SFRSEED);
}

/**
 * Write the SGI SEED register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_writeSfrSeed)
static inline void mcuxClSgi_Sfr_writeSfrSeed(uint32_t value)
{
  MCUXCLSGI_SFR_WRITE(SFRSEED, value);
}

/**
 * Read the SGI DUMMY_CTRL register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readDummyCtrl)
static inline uint32_t mcuxClSgi_Sfr_readDummyCtrl(void)
{
  return MCUXCLSGI_SFR_READ(DUMMY_CTRL);
}

/**
 * Write the SGI DUMMY_CTRL register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_setDummyCtrl)
static inline void mcuxClSgi_Sfr_setDummyCtrl(uint32_t value)
{
  MCUXCLSGI_SFR_WRITE(DUMMY_CTRL, value);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSGI_SFR_SEC_H_ */
