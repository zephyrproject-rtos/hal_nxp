/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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
 *
 * This includes the CMSIS for all of the functionality provided by the ELS IP and provides support for external base address linking. */

#ifndef IP_PLATFORM_H
#define IP_PLATFORM_H

#include <MIMXRT798S_cm33_core0.h>

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

// Define base addresses of Glikey instances
#define GLIKEY0_BASEADDRESS        GLIKEY0_BASE  ///< Base address for GLIKEY instance 0, protects AHBSC_COMPUTE
#define GLIKEY1_BASEADDRESS        GLIKEY1_BASE  ///< Base address for GLIKEY instance 1, protects AHBSC_SENSE
#define GLIKEY2_BASEADDRESS        GLIKEY2_BASE  ///< Base address for GLIKEY instance 2, protects AHBSC_MEDIA
#define GLIKEY3_BASEADDRESS        GLIKEY3_BASE  ///< Base address for GLIKEY instance 3, protects SYSCON0
#define GLIKEY4_BASEADDRESS        GLIKEY4_BASE  ///< Base address for GLIKEY instance 4, protects SYSCON_SENSE0 and SYSCON_SENSE1
#define GLIKEY5_BASEADDRESS        GLIKEY5_BASE  ///< Base address for GLIKEY instance 5, protects SYSCON_MEDIA

#define GLIKEY_SFR_BASE(baseAddress)    ((GLIKEY_Type *)baseAddress)    ///< base of GLIKEY SFRs
#define GLIKEY_SFR_NAME(sfr)            sfr                             ///< full name of SFR
#define GLIKEY_SFR_PREFIX               GLIKEY_                         ///< sfr field name prefix
#define GLIKEY_SFR_SUFFIX_MSK           _MASK                           ///< sfr field name suffix for mask
#define GLIKEY_SFR_SUFFIX_POS           _SHIFT                          ///< sfr field name suffix for bit position

// Define number of indexes per Glikey instance
#define GLIKEY0_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 0
#define GLIKEY1_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 1
#define GLIKEY2_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 2
#define GLIKEY3_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 3
#define GLIKEY4_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 4
#define GLIKEY5_NUM_IDX         16  ///< Number of addressable indexes for GLIKEY instance 5

// Define base address of ELS
#define ELS_SFR_BASE            ELS_NS      ///< base of ELS SFRs
#define ELS_SFR_NAME(sfr)       sfr         ///< full name of SFR
#define ELS_SFR_PREFIX          ELS_        ///< sfr field name prefix

// Workaround (RT700 platform header has a bug and defines ELS_KS0 as ELS_K0, but ELS_KS1 etc. are correct)
#define ELS_KS0                 ELS_K0

// Define base address of PKC
#define PKC_SFR_BASE            PKC         ///< base of PKC SFRs
#define PKC_SFR_NAME(sfr)       PKC_ ## sfr ///< full name of SFR
#define PKC_SFR_PREFIX          PKC_PKC_    ///< sfr field name prefix
#define PKC_SFR_SUFFIX_MSK      _MASK       ///< sfr field name suffix for mask
#define PKC_SFR_SUFFIX_POS      _SHIFT      ///< sfr field name suffix for bit position

// PKC_RAM base address is not defined in any header file
#define PKC_RAM_ADDR  ((uint32_t)0x34110000u)
#define PKC_WORD_SIZE  8u

// Define base address of TRNG
#define TRNG_SFR_BASE           TRNG        ///< base of TRNG SFRs
#define TRNG_SFR_NAME(sfr)      sfr         ///< full name of SFR
#define TRNG_SFR_PREFIX         TRNG_       ///< sfr field name prefix
#define TRNG_SFR_SUFFIX_MSK     _MASK       ///< sfr field name suffix for mask
#define TRNG_SFR_SUFFIX_POS     _SHIFT      ///< sfr field name suffix for bit position

// Define base address of SAFO
#define SAFO_SFR_BASE           OSCCA               ///< base of SAFO SFRs
#define SAFO_SFR_NAME(sfr)      SAFO_SGI_ ## sfr    ///< full name of SFR
#define SAFO_SFR_PREFIX         OSCCA_SAFO_SGI_     ///< sfr field name prefix

// CSS interrupt definitions
#define CSS_INTERRUPT_ERR_NUMBER   ELS_IRQn
#define CSS_INTERRUPT_BUSY_NUMBER  ELS_IRQn
#define CSS_INTERRUPT_IRQ_NUMBER   ELS_IRQn

// Glikey interrupt definitions
#define GLIKEY0_INTERRUPT_NUMBER  GLIKEY0_IRQn
//#define GLIKEY1_INTERRUPT_NUMBER  GLIKEY1_IRQn // missing in HW header
#define GLIKEY2_INTERRUPT_NUMBER  GLIKEY2_IRQn
#define GLIKEY3_INTERRUPT_NUMBER  GLIKEY3_IRQn
//#define GLIKEY4_INTERRUPT_NUMBER  GLIKEY4_IRQn // missing in HW header
#define GLIKEY5_INTERRUPT_NUMBER  GLIKEY5_IRQn

// ELS version
#define ELS_HW_VERSION_REVISION            0
#define ELS_HW_VERSION_MINOR               10
#define ELS_HW_VERSION_MAJOR               3
#define ELS_HW_VERSION_FW_REVISION         0
#define ELS_HW_VERSION_FW_MINOR            10
#define ELS_HW_VERSION_FW_MAJOR            2

// Define SYSCON0 ASSERT PROT Address Register
#define SYSCON_ASSERT_PROT                 *(volatile uint32_t*) 0x50002B68


/* If we are supposed to determine the ELS base address at link time, do not use the definitions from the platform header file
 * Redefine ELS_SFR_BASE as an extern pointer.
 */
#undef ELS_SFR_BASE
extern void * ip_css_base;
#define ELS_SFR_BASE           ((ELS_Type *) ip_css_base)

#endif
