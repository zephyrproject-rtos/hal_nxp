/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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

/** @file  ip_platform.h
 *  @brief Include file for the IP.
 */

#ifndef IP_PLATFORM_H
#define IP_PLATFORM_H

#include "fsl_device_registers.h"
/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define DMA_MP_SFR_BASE   (DMA0)   ///< Base of the DMA MP SFR structure
#define DMA_CH_SFR_BASE   (DMA0)  ///< Base of the DMA Channel SFR structure
#define DMA_TCD_SFR_BASE  (DMA0)  ///< Base of the DMA TCD SFR structure

/**
 * Definitions for accessing DMA MP SFRs via, e.g., DMA_MP_SFR_BASE->MP_CSR, or DMA_MP_SFR_BASE->CH_GRPRI[0]
 * and for constructing the mask and shift values for a corresponding SFR field, e.g., eDMA_MP_CSR_EDBG_MASK
 */
#define DMA_MP_SFR_NAME(sfr)         MP_ ## sfr ///< DMA MP SFR full name
#define DMA_MP_CH_SFR_NAME(ch,sfr)   sfr[(ch)]  ///< DMA MP SFR full name (for a channel-specific SFR)
#define DMA_MP_SFR_PREFIX            DMA_MP_    ///< DMA MP SFR field name prefix

/**
 * Definitions for accessing DMA channel-specific SFRs, e.g., DMA_CH_SFR_BASE->CH[0].CH_CSR,
 * and for constructing the mask and shift values for a corresponding SFR field, e.g., eDMA_CH_CSR_ERQ_MASK
 */
#define DMA_CH_SFR_NAME(ch,sfr)      CH[(ch)].CH_ ## sfr  ///< DMA channel-specific SFR full name for a given channel
#define DMA_CH_SFR_PREFIX            DMA_CH_              ///< DMA channel-specific SFR field name prefix

/**
 * Definitions for accessing DMA TCD-specific SFRs, e.g., DMA_TCD_SFR_BASE->CH[0].TCD_CSR,
 * and for constructing the mask and shift values for a corresponding SFR field, e.g., eDMA_TCD_CSR_ERQ_MASK
 */
#define DMA_TCD_SFR_NAME(ch,sfr)      CH[(ch)].TCD_ ## sfr  ///< DMA TCD-specific SFR full name for a given channel
#define DMA_TCD_SFR_PREFIX            DMA_TCD_              ///< DMA channel-specific SFR field name prefix

/**
 * Helper macro for constructing SFR field name constants
 */
#define DMA_PASTE(a,b)        a ## b
#define DMA_CONCAT(a,b)       DMA_PASTE(a,b)

#define DMA_SFR_FIELD(prefix,sfr,field)  DMA_CONCAT(prefix,sfr ## _ ## field) ///< DMA SFR field name
#define DMA_SFR_SUFFIX_MSK  _MASK   ///< DMA SFR field name suffix for mask
#define DMA_SFR_SUFFIX_POS  _SHIFT  ///< DMA SFR field name suffix for bit position

#define SGI_IRQ_NUMBER      SGI_IRQn
#define PKC_IRQ_NUMBER      PKC_IRQn

#define DMA_CH0_IRQ_NUMBER            ((uint32_t)DMA0_CH0_IRQn)
#define GET_DMA_CHX_IRQ_NUMBER(x)     ((DMA_CH0_IRQ_NUMBER) + (x))
#define DMA_CH_TOTAL  12u

/**
 *  Defines/Macros for the CH_MUX (Channel Multiplexor) register fields.
 */
#define DMA_REQ_SRC_DISABLED  (kDma0RequestDisabled)    ///< DMA handshake source for disabling handshakes
#define DMA_REQ_SRC_SGI_IN    (kDma0RequestSGI0Datain)  ///< DMA handshake source for SGI DATIN
#define DMA_REQ_SRC_SGI_OUT   (kDma0RequestSGI0Dataout) ///< DMA handshake source for SGI DATOUT

/**
 * Helper macro for constructing SFR field name constants
 */

#define DMA_PASTE(a,b)        a ## b
#define DMA_CONCAT(a,b)       DMA_PASTE(a,b)

#define DMA_SFR_FIELD(prefix,sfr,field)  DMA_CONCAT(prefix,sfr ## _ ## field) ///< DMA SFR field name
#define DMA_SFR_SUFFIX_MSK  _MASK   ///< DMA SFR field name suffix for mask
#define DMA_SFR_SUFFIX_POS  _SHIFT  ///< DMA SFR field name suffix for bit position

#define SGI_DATIN_CNT                 16UL
#define SGI_DATOUT_CNT                4UL
#define SGI_KEY_CNT                   32UL
#define SGI_KEY_WRITEONLY_START       16UL  ///< first compile-time WO key index
#define SGI_UNWRAP_KEY_REGISTER_BANK  4UL   ///< Sgi key register bank where the UNWRAP key will be written to
#define SGI_SFR_BASE           SGI0                                   ///< base of SGI SFRs
#define SGI_SFR_MACRO_PREFIX   SGI_SGI_                               ///< sfr macro name prefix
#define SGI_SFR_PREFIX         SGI_                                   ///< sfr field name prefix
#define SGI_SFR_NAME1(sfr)     DMA_CONCAT(SGI_SFR_PREFIX, sfr)        ///< full name of SFR
#define SGI_SFR_NAME(sfr)      SGI_SFR_NAME1(sfr)                     ///< full name of SFR
#define SGI_SFR_SUFFIX_MSK     _MASK                                  ///< sfr field name suffix for mask
#define SGI_SFR_SUFFIX_POS     _SHIFT                                 ///< sfr field name suffix for bit position
#define SGI_STRUCT_NAME        SGI_Type
#define SGI_HAS_ACCESS_ERR           1      ///< "feature" flag for existence of SGI ACCESS_ERR SFR
#define SGI_HAS_AES_AUTO_MODE        1      ///< "feature" flag for existence of SGI AES AUTO mode
#define SGI_HAS_WRITEONLY_KEYS       1      ///< "feature" flag for existence of SGI write-only keys
#define SGI_HAS_KEY_WRAP_UNWRAP      1      ///< "feature" flag for existence of SGI key wrap/unwrap
// #define SGI_HAS_FLUSHWR            1    ///<  Not available on A2TS, because of HYBRID SGI
#define SGI_HAS_PRNG_SW_READ         1      ///< "feature" flag for existance of the SGI PRNG

// Define base address of PKC
#define PKC_SFR_BASE            PKC0        ///< base of PKC SFRs
#define PKC_SFR_NAME(sfr)       PKC_ ## sfr ///< full name of SFR
#define PKC_SFR_PREFIX          PKC_PKC_    ///< sfr field name prefix
#define PKC_SFR_SUFFIX_MSK      _MASK       ///< sfr field name suffix for mask
#define PKC_SFR_SUFFIX_POS      _SHIFT      ///< sfr field name suffix for bit position

#define TRNG_SFR_BASE           TRNG0       ///< base of TRNG SFRs
#define TRNG_SFR_NAME1(sfr)     sfr         ///< full name of SFR
#define TRNG_SFR_NAME(sfr)      TRNG_SFR_NAME1(sfr)     ///< full name of SFR
#define TRNG_SFR_SUFFIX_MSK     _MASK       ///< sfr field name suffix for mask
#define TRNG_SFR_SUFFIX_POS     _SHIFT      ///< sfr field name suffix for bit position
#define TRNG_SFR_PREFIX         TRNG_   ///< sfr field name prefix

/*
#if defined ( __ICCARM__ )
extern const uint32_t __ICFEDIT_region_RAM_PKC_start__;
#define PKC_RAM_ADDR  (&__ICFEDIT_region_RAM_PKC_start__)

#else

extern const uint32_t Image$$PKC_RAM_BUF_ADDRESS$$Base;
#define PKC_RAM_ADDR ((uint32_t) &Image$$PKC_RAM_BUF_ADDRESS$$Base)
#define PKC_WORD_SIZE  8u

#endif  __ICCARM__ */

// PKC_RAM base address is not defined in any header file
#define PKC_RAM_ADDR  ((uint32_t)0x20002000UL)
#define PKC_WORD_SIZE  8u
#define PKC_RAM_SIZE  ((uint32_t)0x1000u)

#define NXPCL_CACHE_FLUSH(addr, len)
#define NXPCL_CACHE_CLEAR(addr, len)
#ifndef NXPCL_CACHE_ALIGNED
/* NXPCL_CACHE_ALIGNED should be defined externally */
#define NXPCL_CACHE_ALIGNED
#endif

// Define base address of Glikey
#define GLIKEY0_BASEADDRESS        GLIKEY0_BASE  ///< Base address for GLIKEY instance 0
#define GLIKEY1_BASEADDRESS        GLIKEY0_BASE  ///< Base address for GLIKEY instance 1

// TODO: Remove this workaround from COSIM targets. This was added due to missing data for Glikey1 on rt700 sample
#define GLIKEY2_BASEADDRESS        GLIKEY0_BASE  ///< Base address for GLIKEY instance 1

#define GLIKEY_SFR_BASE(baseAddress)    ((GLIKEY_Type *)baseAddress)    ///< base of GLIKEY SFRs
#define GLIKEY_SFR_NAME(sfr)            sfr                             ///< full name of SFR
#define GLIKEY_SFR_PREFIX               GLIKEY_                         ///< sfr field name prefix
#define GLIKEY_SFR_SUFFIX_MSK           _MASK                           ///< sfr field name suffix for mask
#define GLIKEY_SFR_SUFFIX_POS           _SHIFT                          ///< sfr field name suffix for bit position

// Define number of indexes per Glikey instance
#define GLIKEY0_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 0
#define GLIKEY1_NUM_IDX         0  ///< Number of addressable indexes for GLIKEY instance 1
// TODO: Remove this workaround from COSIM targets. This was added due to missing data for Glikey1 on rt700 sample
#define GLIKEY2_NUM_IDX         0  ///< Number of addressable indexes for GLIKEY instance 1

// Glikey interrupt number
#define GLIKEY0_INTERRUPT_NUMBER   GLIKEY0_IRQn  // GLIKEY instance 0 with 16 indexes
#define GLIKEY1_INTERRUPT_NUMBER   GLIKEY0_IRQn  // GLIKEY instance 1 with 64 indexes
// TODO: Remove this workaround from COSIM targets. This was added due to missing data for Glikey1 on rt700 sample
#define GLIKEY2_INTERRUPT_NUMBER   GLIKEY0_IRQn  // GLIKEY instance 1 with 64 indexes

/* Fix for typo in system header file */
#ifndef PKC_PKC_ZRPTR2_ZPTR_MASK
#define PKC_PKC_ZRPTR2_ZPTR_MASK  PKC_PKC_ZRPTR2_ZPT_MASK
#define PKC_PKC_ZRPTR2_ZPTR_SHIFT PKC_PKC_ZRPTR2_ZPT_SHIFT
#define PKC_PKC_ZRPTR2_ZPTR(x)    PKC_PKC_ZRPTR2_ZPT(x)
#endif

#endif
