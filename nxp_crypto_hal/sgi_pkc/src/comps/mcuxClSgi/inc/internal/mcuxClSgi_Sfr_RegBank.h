/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

#ifndef MCUXCLSGI_SFR_REGBANK_H_
#define MCUXCLSGI_SFR_REGBANK_H_

#include <mcuxCsslAnalysis.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <platform_specific_headers.h>
#include <internal/mcuxClSgi_SfrAccess.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Offset of data input */
#define MCUXCLSGI_SFR_DATIN0_OFFSET    (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(DATIN0A)))
#define MCUXCLSGI_SFR_DATIN1_OFFSET    (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(DATIN1A)))
#define MCUXCLSGI_SFR_DATIN2_OFFSET    (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(DATIN2A)))
// TODO: guard
#define MCUXCLSGI_SFR_DATIN3_OFFSET    (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(DATIN3A)))


/* Translate a data input index (0,1,2,3, where DATIN0: 0, DATIN1: 1, ..) to a data input offset */
#define MCUXCLSGI_SFR_DATIN_INDEX_TO_OFFSET(datinIndex) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("datinIndex is between 0 and 3") \
  (MCUXCLSGI_SFR_DATIN0_OFFSET + (16U * (datinIndex))) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

/* Offset of SHA FIFO input */
#define MCUXCLSGI_SFR_SHAFIFO_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(SHA_FIFO)))

/* Offset of data output */
#define MCUXCLSGI_SFR_DATOUT_OFFSET    (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(DATOUTA)))

/* Offset of key register */
#define MCUXCLSGI_SFR_KEY0_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY0A)))
#define MCUXCLSGI_SFR_KEY1_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY1A)))
#define MCUXCLSGI_SFR_KEY2_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY2A)))
#define MCUXCLSGI_SFR_KEY3_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY3A)))
// TODO: guard
#define MCUXCLSGI_SFR_KEY4_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY4A)))
#define MCUXCLSGI_SFR_KEY5_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY5A)))
#define MCUXCLSGI_SFR_KEY6_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY6A)))
#define MCUXCLSGI_SFR_KEY7_OFFSET   (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY7A)))

/* Index of key registers */
#define MCUXCLSGI_SFR_KEY0_INDEX    (  0UL)
#define MCUXCLSGI_SFR_KEY1_INDEX    (  4UL)
#define MCUXCLSGI_SFR_KEY2_INDEX    (  8UL)
#define MCUXCLSGI_SFR_KEY3_INDEX    ( 12UL)
// TODO: guard
#define MCUXCLSGI_SFR_KEY4_INDEX    ( 16UL)
#define MCUXCLSGI_SFR_KEY5_INDEX    ( 20UL)
#define MCUXCLSGI_SFR_KEY6_INDEX    ( 24UL)
#define MCUXCLSGI_SFR_KEY7_INDEX    ( 28UL)

#ifdef SGI_HAS_KEY_WRAP_UNWRAP
/* Index of the KEY that serves as the location of a KEY_UNWRAP operation */
#define MCUXCLSGI_SFR_KEY_OFFSET_UNWRAP_DEST (MCUXCLSGI_SFR_KEY4_OFFSET)
/* Index of the KEY that serves as the location of a KEY_UNWRAP operation */
#define MCUXCLSGI_SFR_KEY_INDEX_UNWRAP_DEST  (MCUXCLSGI_SFR_KEY4_INDEX)

/* Offset of KEY_WRAP (output of key wrap operation), updated by HW on each read */
#define MCUXCLSGI_SFR_KEY_WRAP_OFFSET        (uint32_t)(offsetof(SGI_STRUCT_NAME,SGI_SFR_NAME(KEY_WRAP)))

#endif /* SGI_HAS_KEY_WRAP_UNWRAP */


/* Translations between key index, offsets and slots:
 *   Key SFR      Offset   Index  Slot
 *   KEY0A        0x240    0      0
 *   KEY1A        0x250    4      1
 *   KEY2A        0x260    8      2
 *   ...
 */
#define MCUXCLSGI_SFR_KEY_INDEX_TO_OFFSET(index)   (MCUXCLSGI_SFR_KEY0_OFFSET + (4U * (index)))
#define MCUXCLSGI_SFR_KEY_INDEX_TO_SLOT(index)     ((index) / 4U)
#define MCUXCLSGI_SFR_KEY_OFFSET_TO_INDEX(offset)  (((offset) - MCUXCLSGI_SFR_KEY0_OFFSET) / 4U)
#define MCUXCLSGI_SFR_KEY_OFFSET_TO_SLOT(offset)   (((offset) - MCUXCLSGI_SFR_KEY0_OFFSET) / 16U)
#define MCUXCLSGI_SFR_KEY_SLOT_TO_OFFSET(slot)     (MCUXCLSGI_SFR_KEY0_OFFSET + (16U * (slot)))
#define MCUXCLSGI_SFR_KEY_SLOT_TO_INDEX(slot)      ((slot) * 4U)


/*******************************************************
 * Static inline functions for SFR register bank access
 *******************************************************/

/** Get the address of an SGI SFR */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_getAddr)
static inline uint32_t * mcuxClSgi_Sfr_getAddr(uint32_t sfrOffset)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_READ()
  MCUX_CSSL_ANALYSIS_START_PATTERN_SFR_ACCESS()
  return (uint32_t *)((uint8_t*)SGI_SFR_BASE + sfrOffset);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SFR_ACCESS()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_READ()
}

/** Get the offset of an SGI SFR w.r.t to the SGI base from its address */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_getOffset)
static inline uint32_t mcuxClSgi_Sfr_getOffset(uint32_t* sfrAddress)
{
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Casting the SGI base address to a pointer happens in hardware headers.")
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(sfrAddress, SGI_SFR_BASE, (SGI_SFR_BASE + 0xffcU /* max SGI offset */), 0U)
  return (uint32_t)sfrAddress - (uint32_t)SGI_SFR_BASE;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
}

/** Write word to a SGI SFR. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_writeWord)
static inline void mcuxClSgi_Sfr_writeWord(uint32_t sfrOffset, uint32_t value)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_WRITE()
  volatile uint32_t *const sgiSfrAddress = mcuxClSgi_Sfr_getAddr(sfrOffset);
  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_REGISTER_INDEXING()
  *sgiSfrAddress = value;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_REGISTER_INDEXING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_WRITE()
}

/** read word from a SGI SFR. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readWord)
static inline uint32_t mcuxClSgi_Sfr_readWord(uint32_t sfrOffset)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_WRITE()
  volatile uint32_t *const sgiSfrAddress = mcuxClSgi_Sfr_getAddr(sfrOffset);
  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_REGISTER_INDEXING()
  return (uint32_t)(*sgiSfrAddress);
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_REGISTER_INDEXING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_WRITE()
}

#ifdef SGI_HAS_KEY_WRAP_UNWRAP
/** Read the KEY_WRAP SFR. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Sfr_readWrappedKeyWord)
static inline uint32_t mcuxClSgi_Sfr_readWrappedKeyWord(void)
{
  /* Read one word of the wrapped key output - the HW updates the register content on each read. */
  volatile uint32_t wrappedKeyWord = (uint32_t) *(mcuxClSgi_Sfr_getAddr(MCUXCLSGI_SFR_KEY_WRAP_OFFSET));
  return wrappedKeyWord;
}
#endif /* SGI_HAS_KEY_WRAP_UNWRAP */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSGI_SFR_REGBANK_H_ */
