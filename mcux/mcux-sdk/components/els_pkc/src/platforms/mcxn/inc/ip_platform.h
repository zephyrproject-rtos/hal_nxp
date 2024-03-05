/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
/*                                                                          */
/* NXP Confidential. This software is owned or controlled by NXP and may    */
/* only be used strictly in accordance with the applicable license terms.   */
/* By expressly accepting such terms or by downloading, installing,         */
/* activating and/or otherwise using the software, you are agreeing that    */
/* you have read, and that you agree to comply with and are bound by, such  */
/* license terms. If you do not agree to be bound by the applicable license */
/* terms, then you may not retain, install, activate or otherwise use the   */
/* software.                                                                */
/*--------------------------------------------------------------------------*/

/** @file  ip_platform.h
 *  @brief Include file for the IP.
 *
 * This includes the CMSIS for all of the functionality provided by the ELS IP and provides support for external base address linking. */

#ifndef IP_PLATFORM_H
#define IP_PLATFORM_H

#include "fsl_device_registers.h"

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

// Define base address of ELS
#define ELS_SFR_BASE            ELS         ///< base of ELS SFRs
#define ELS_SFR_NAME(sfr)       sfr         ///< full name of SFR
#define ELS_SFR_PREFIX          S50_        ///< sfr field name prefix

// Define base address of PKC
#define PKC_SFR_BASE            PKC0        ///< base of PKC SFRs
#define PKC_SFR_NAME(sfr)       PKC_ ## sfr ///< full name of SFR
#define PKC_SFR_PREFIX          PKC_PKC_    ///< sfr field name prefix
#define PKC_SFR_SUFFIX_MSK      _MASK       ///< sfr field name suffix for mask
#define PKC_SFR_SUFFIX_POS      _SHIFT      ///< sfr field name suffix for bit position

// PKC_RAM base address is not defined in any header file
#define PKC_RAM_ADDR  ((uint32_t)0x400B3000u)
#define PKC_WORD_SIZE  8u
#define PKC_RAM_SIZE  ((uint32_t)0x1000u)

// Define base address of TRNG
#define TRNG_SFR_BASE           TRNG0       ///< base of TRNG SFRs
#define TRNG_SFR_NAME(sfr)      sfr         ///< full name of SFR
#define TRNG_SFR_PREFIX         TRNG_       ///< sfr field name prefix
#define TRNG_SFR_SUFFIX_MSK     _MASK       ///< sfr field name suffix for mask
#define TRNG_SFR_SUFFIX_POS     _SHIFT      ///< sfr field name suffix for bit position

// Define base address of SAFO
#define SAFO_SFR_BASE           SM3_0       ///< base of SAFO SFRs
#define SAFO_SFR_NAME(sfr)      sfr         ///< full name of SFR
#define SAFO_SFR_PREFIX         SM3_        ///< sfr field name prefix

// ELS interrupt definitions
#define CSS_INTERRUPT_ERR_NUMBER   ELS_ERR_IRQn
#define CSS_INTERRUPT_IRQ_NUMBER   ELS_IRQn
#define CSS_INTERRUPT_BUSY_NUMBER  ELS_IRQn


#define IP_PUF_BASE      0x5002C000UL
#define PUF_SRAM_CFG     *(volatile uint32_t *) (IP_PUF_BASE + 0x300)
#define PUF_SR           *(volatile uint32_t *) (IP_PUF_BASE + 0x8)
#define PUF_OR           *(volatile uint32_t *) (IP_PUF_BASE + 0x4)
#define PUF_CR           *(volatile uint32_t *) (IP_PUF_BASE + 0x0)
#define PUF_KEY_DEST     *(volatile uint32_t *) (IP_PUF_BASE + 0x20)
#define PUF_DIR          *(volatile uint32_t *) (IP_PUF_BASE + 0xA0)
#define PUF_DOR          *(volatile uint32_t *) (IP_PUF_BASE + 0xA8)

// ELS version
#define ELS_HW_VERSION_REVISION            0
#define ELS_HW_VERSION_MINOR               4
#define ELS_HW_VERSION_MAJOR               3
#define ELS_HW_VERSION_FW_REVISION         0
#define ELS_HW_VERSION_FW_MINOR            4
#define ELS_HW_VERSION_FW_MAJOR            2

#ifdef NXPCL_FEATURE_ELS_LINK_BASE_ADDRESS
/* If we are supposed to determine the CSSv2 base address at link time, do not use the definitions from the platform header file
 * Redefine IP_CSS as an extern pointer.
 */
#undef ELS_SFR_BASE
extern void * ip_css_base;
#define ELS_SFR_BASE           ((S50_Type *) ip_css_base)
#endif /* NXPCL_FEATURE_ELS_LINK_BASE_ADDRESS */

#endif
