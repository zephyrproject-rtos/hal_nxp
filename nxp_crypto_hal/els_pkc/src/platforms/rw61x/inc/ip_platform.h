/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * This file defines base addresses and types for all IP blocks used by CLNS. */

#ifndef IP_PLATFORM_H
#define IP_PLATFORM_H

#include "fsl_device_registers.h"

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

// Define base address of PUF
#define PUF_SFR_BASE            PUF      ///< base of PUF SFRs
#define PUF_SFR_NAME(sfr)       sfr      ///< full name of SFR
#define PUF_SFR_PREFIX          PUF_     ///< sfr field name prefix
#define PUF_SFR_SUFFIX_MSK     _MASK       ///< sfr field name suffix for mask
#define PUF_SFR_SUFFIX_POS     _SHIFT      ///< sfr field name suffix for bit position


// Define base address of CSS
#define ELS_SFR_BASE            ELS         ///< base of CSS SFRs
#define ELS_SFR_NAME(sfr)       sfr         ///< full name of SFR
#define ELS_SFR_PREFIX          ELS_        ///< sfr field name prefix

// Define base address of PKC
#define PKC_SFR_BASE            PKC         ///< base of PKC SFRs
#define PKC_SFR_NAME(sfr)       PKC_ ## sfr ///< full name of SFR
#define PKC_SFR_PREFIX          PKC_PKC_    ///< sfr field name prefix
#define PKC_SFR_SUFFIX_MSK      _MASK       ///< sfr field name suffix for mask
#define PKC_SFR_SUFFIX_POS      _SHIFT      ///< sfr field name suffix for bit position

// PKC_RAM base address is not defined in any header file
#define PKC_RAM_ADDR ((uint32_t) 0x5015A000)
#define PKC_RAM_SIZE  ((uint32_t)0x2000u)
#define PKC_WORD_SIZE  8u

// Define base address of TRNG
#define TRNG_SFR_BASE           TRNG         ///< base of TRNG SFRs
#define TRNG_SFR_NAME(sfr)      sfr          ///< full name of SFR
#define TRNG_SFR_PREFIX         TRNG_        ///< sfr field name prefix
#define TRNG_SFR_SUFFIX_MSK     _MASK        ///< sfr field name suffix for mask
#define TRNG_SFR_SUFFIX_POS     _SHIFT       ///< sfr field name suffix for bit position

// ELS version
#define ELS_HW_VERSION_REVISION            1
#define ELS_HW_VERSION_MINOR               16
#define ELS_HW_VERSION_MAJOR               2
#define ELS_HW_VERSION_FW_REVISION         1
#define ELS_HW_VERSION_FW_MINOR            2
#define ELS_HW_VERSION_FW_MAJOR            1

// Interrupt definitions
#define CSS_INTERRUPT_BUSY_NUMBER          ELS_IRQn
#define CSS_INTERRUPT_ERR_NUMBER           ELS_IRQn
#define CSS_INTERRUPT_IRQ_NUMBER           ELS_IRQn
#define GDET_INTERRUPT_IRQ_NUMBER          ELS_GDET_IRQ_IRQn
#define GDET_INTERRUPT_ERR_NUMBER          ELS_GDET_ERR_IRQn


/* If we are supposed to determine the CSSv2 base address at link time, do not use the definitions from ip_css.h
 * Redefine CSS as an extern pointer.
 */
#undef CSS_BASE
extern void * ip_css_base;
#define CSS_BASE                     ip_css_base

#endif
