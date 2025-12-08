/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_F16ASM.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_F16ASM
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K566_F16ASM_H_)  /* Check if memory map has not been already included */
#define S32K566_F16ASM_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- F16ASM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup F16ASM_Peripheral_Access_Layer F16ASM Peripheral Access Layer
 * @{
 */

/** F16ASM - Size of Registers Arrays */
#define F16ASM_UMISR08_COUNT                      9u
#define F16ASM_UD07_COUNT                         8u
#define F16ASM_UD916_COUNT                        8u

/** F16ASM - Register Layout Typedef */
typedef struct F16ASM_Struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
  __IO uint32_t MCRS;                              /**< Module Configuration Status, offset: 0x4 */
  uint8_t RESERVED_0[4];
  __IO uint32_t RADR;                              /**< Read Address Logging, offset: 0xC */
  __I  uint32_t WADR;                              /**< Write Address Logging, offset: 0x10 */
  __I  uint32_t LOCK0;                             /**< Partition Lock 0, offset: 0x14 */
  __I  uint32_t LOCK1;                             /**< Partition Lock 1, offset: 0x18 */
  __IO uint32_t UT0;                               /**< UTest 0, offset: 0x1C */
  __IO uint32_t UMISR[F16ASM_UMISR08_COUNT];       /**< UTest Multiple Input Signature 0..UTest Multiple Input Signature 8, array offset: 0x20, array step: 0x4 */
  __IO uint32_t UMISR9;                            /**< UTest Multiple Input Signature 9, offset: 0x44 */
  __IO uint32_t UD_0_TO_7[F16ASM_UD07_COUNT];      /**< UTest Data 0..UTest Data 7, array offset: 0x48, array step: 0x4 */
  __IO uint32_t UD8;                               /**< UTest Data 8, offset: 0x68 */
  __IO uint32_t UD_9_TO_16[F16ASM_UD916_COUNT];    /**< UTest Data 9..UTest Data 16, array offset: 0x6C, array step: 0x4 */
  __IO uint32_t UD17;                              /**< UTest Data 17, offset: 0x8C */
  uint8_t RESERVED_1[4];
  __IO uint32_t UA0;                               /**< UTest Address 0, offset: 0x94 */
  __IO uint32_t UA1;                               /**< UTest Address 1, offset: 0x98 */
} F16ASM_Type, *F16ASM_MemMapPtr;

/** Number of instances of the F16ASM module. */
#define F16ASM_INSTANCE_COUNT                    (1u)

/* F16ASM - Peripheral instance base addresses */
/** Peripheral MRAM base address */
#define IP_MRAM_BASE                             (0x404A0000u)
/** Peripheral MRAM base pointer */
#define IP_MRAM                                  ((F16ASM_Type *)IP_MRAM_BASE)
/** Array initializer of F16ASM peripheral base addresses */
#define IP_F16ASM_BASE_ADDRS                     { IP_MRAM_BASE }
/** Array initializer of F16ASM peripheral base pointers */
#define IP_F16ASM_BASE_PTRS                      { IP_MRAM }

/* ----------------------------------------------------------------------------
   -- F16ASM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup F16ASM_Register_Masks F16ASM Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define F16ASM_MCR_RWSC_MASK                     (0xFU)
#define F16ASM_MCR_RWSC_SHIFT                    (0U)
#define F16ASM_MCR_RWSC_WIDTH                    (4U)
#define F16ASM_MCR_RWSC(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCR_RWSC_SHIFT)) & F16ASM_MCR_RWSC_MASK)

#define F16ASM_MCR_RWSL_MASK                     (0x80U)
#define F16ASM_MCR_RWSL_SHIFT                    (7U)
#define F16ASM_MCR_RWSL_WIDTH                    (1U)
#define F16ASM_MCR_RWSL(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCR_RWSL_SHIFT)) & F16ASM_MCR_RWSL_MASK)

#define F16ASM_MCR_WPL_MASK                      (0x8000000U)
#define F16ASM_MCR_WPL_SHIFT                     (27U)
#define F16ASM_MCR_WPL_WIDTH                     (1U)
#define F16ASM_MCR_WPL(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_MCR_WPL_SHIFT)) & F16ASM_MCR_WPL_MASK)

#define F16ASM_MCR_CVE_MASK                      (0x20000000U)
#define F16ASM_MCR_CVE_SHIFT                     (29U)
#define F16ASM_MCR_CVE_WIDTH                     (1U)
#define F16ASM_MCR_CVE(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_MCR_CVE_SHIFT)) & F16ASM_MCR_CVE_MASK)

#define F16ASM_MCR_OWC_MASK                      (0x80000000U)
#define F16ASM_MCR_OWC_SHIFT                     (31U)
#define F16ASM_MCR_OWC_WIDTH                     (1U)
#define F16ASM_MCR_OWC(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_MCR_OWC_SHIFT)) & F16ASM_MCR_OWC_MASK)
/*! @} */

/*! @name MCRS - Module Configuration Status */
/*! @{ */

#define F16ASM_MCRS_SIZE_MASK                    (0xFU)
#define F16ASM_MCRS_SIZE_SHIFT                   (0U)
#define F16ASM_MCRS_SIZE_WIDTH                   (4U)
#define F16ASM_MCRS_SIZE(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_SIZE_SHIFT)) & F16ASM_MCRS_SIZE_MASK)

#define F16ASM_MCRS_SSIZE_MASK                   (0x30U)
#define F16ASM_MCRS_SSIZE_SHIFT                  (4U)
#define F16ASM_MCRS_SSIZE_WIDTH                  (2U)
#define F16ASM_MCRS_SSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_SSIZE_SHIFT)) & F16ASM_MCRS_SSIZE_MASK)

#define F16ASM_MCRS_OMR_MASK                     (0x100U)
#define F16ASM_MCRS_OMR_SHIFT                    (8U)
#define F16ASM_MCRS_OMR_WIDTH                    (1U)
#define F16ASM_MCRS_OMR(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_OMR_SHIFT)) & F16ASM_MCRS_OMR_MASK)

#define F16ASM_MCRS_OMA_MASK                     (0x200U)
#define F16ASM_MCRS_OMA_SHIFT                    (9U)
#define F16ASM_MCRS_OMA_WIDTH                    (1U)
#define F16ASM_MCRS_OMA(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_OMA_SHIFT)) & F16ASM_MCRS_OMA_MASK)

#define F16ASM_MCRS_LPR_MASK                     (0x400U)
#define F16ASM_MCRS_LPR_SHIFT                    (10U)
#define F16ASM_MCRS_LPR_WIDTH                    (1U)
#define F16ASM_MCRS_LPR(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_LPR_SHIFT)) & F16ASM_MCRS_LPR_MASK)

#define F16ASM_MCRS_LPA_MASK                     (0x800U)
#define F16ASM_MCRS_LPA_SHIFT                    (11U)
#define F16ASM_MCRS_LPA_WIDTH                    (1U)
#define F16ASM_MCRS_LPA(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_LPA_SHIFT)) & F16ASM_MCRS_LPA_MASK)

#define F16ASM_MCRS_REWSC_MASK                   (0xF000U)
#define F16ASM_MCRS_REWSC_SHIFT                  (12U)
#define F16ASM_MCRS_REWSC_WIDTH                  (4U)
#define F16ASM_MCRS_REWSC(x)                     (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_REWSC_SHIFT)) & F16ASM_MCRS_REWSC_MASK)

#define F16ASM_MCRS_DONE_MASK                    (0x10000U)
#define F16ASM_MCRS_DONE_SHIFT                   (16U)
#define F16ASM_MCRS_DONE_WIDTH                   (1U)
#define F16ASM_MCRS_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_DONE_SHIFT)) & F16ASM_MCRS_DONE_MASK)

#define F16ASM_MCRS_RSE_MASK                     (0x40000U)
#define F16ASM_MCRS_RSE_SHIFT                    (18U)
#define F16ASM_MCRS_RSE_WIDTH                    (1U)
#define F16ASM_MCRS_RSE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_RSE_SHIFT)) & F16ASM_MCRS_RSE_MASK)

#define F16ASM_MCRS_WTE_MASK                     (0x80000U)
#define F16ASM_MCRS_WTE_SHIFT                    (19U)
#define F16ASM_MCRS_WTE_WIDTH                    (1U)
#define F16ASM_MCRS_WTE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_WTE_SHIFT)) & F16ASM_MCRS_WTE_MASK)

#define F16ASM_MCRS_WAE_MASK                     (0x100000U)
#define F16ASM_MCRS_WAE_SHIFT                    (20U)
#define F16ASM_MCRS_WAE_WIDTH                    (1U)
#define F16ASM_MCRS_WAE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_WAE_SHIFT)) & F16ASM_MCRS_WAE_MASK)

#define F16ASM_MCRS_WRP_MASK                     (0x200000U)
#define F16ASM_MCRS_WRP_SHIFT                    (21U)
#define F16ASM_MCRS_WRP_WIDTH                    (1U)
#define F16ASM_MCRS_WRP(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_WRP_SHIFT)) & F16ASM_MCRS_WRP_MASK)

#define F16ASM_MCRS_WCE_MASK                     (0x400000U)
#define F16ASM_MCRS_WCE_SHIFT                    (22U)
#define F16ASM_MCRS_WCE_WIDTH                    (1U)
#define F16ASM_MCRS_WCE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_WCE_SHIFT)) & F16ASM_MCRS_WCE_MASK)

#define F16ASM_MCRS_WRE_MASK                     (0x800000U)
#define F16ASM_MCRS_WRE_SHIFT                    (23U)
#define F16ASM_MCRS_WRE_WIDTH                    (1U)
#define F16ASM_MCRS_WRE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_WRE_SHIFT)) & F16ASM_MCRS_WRE_MASK)

#define F16ASM_MCRS_RE_MASK                      (0x1000000U)
#define F16ASM_MCRS_RE_SHIFT                     (24U)
#define F16ASM_MCRS_RE_WIDTH                     (1U)
#define F16ASM_MCRS_RE(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_RE_SHIFT)) & F16ASM_MCRS_RE_MASK)

#define F16ASM_MCRS_EEE_MASK                     (0x2000000U)
#define F16ASM_MCRS_EEE_SHIFT                    (25U)
#define F16ASM_MCRS_EEE_WIDTH                    (1U)
#define F16ASM_MCRS_EEE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_EEE_SHIFT)) & F16ASM_MCRS_EEE_MASK)

#define F16ASM_MCRS_AEE_MASK                     (0x4000000U)
#define F16ASM_MCRS_AEE_SHIFT                    (26U)
#define F16ASM_MCRS_AEE_WIDTH                    (1U)
#define F16ASM_MCRS_AEE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_AEE_SHIFT)) & F16ASM_MCRS_AEE_MASK)

#define F16ASM_MCRS_SBC_MASK                     (0x10000000U)
#define F16ASM_MCRS_SBC_SHIFT                    (28U)
#define F16ASM_MCRS_SBC_WIDTH                    (1U)
#define F16ASM_MCRS_SBC(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_SBC_SHIFT)) & F16ASM_MCRS_SBC_MASK)

#define F16ASM_MCRS_DBC_MASK                     (0x20000000U)
#define F16ASM_MCRS_DBC_SHIFT                    (29U)
#define F16ASM_MCRS_DBC_WIDTH                    (1U)
#define F16ASM_MCRS_DBC(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_DBC_SHIFT)) & F16ASM_MCRS_DBC_MASK)

#define F16ASM_MCRS_TBC_MASK                     (0x40000000U)
#define F16ASM_MCRS_TBC_SHIFT                    (30U)
#define F16ASM_MCRS_TBC_WIDTH                    (1U)
#define F16ASM_MCRS_TBC(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_TBC_SHIFT)) & F16ASM_MCRS_TBC_MASK)

#define F16ASM_MCRS_EER_MASK                     (0x80000000U)
#define F16ASM_MCRS_EER_SHIFT                    (31U)
#define F16ASM_MCRS_EER_WIDTH                    (1U)
#define F16ASM_MCRS_EER(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_MCRS_EER_SHIFT)) & F16ASM_MCRS_EER_MASK)
/*! @} */

/*! @name RADR - Read Address Logging */
/*! @{ */

#define F16ASM_RADR_RADDR_MASK                   (0x1FFFFE0U)
#define F16ASM_RADR_RADDR_SHIFT                  (5U)
#define F16ASM_RADR_RADDR_WIDTH                  (20U)
#define F16ASM_RADR_RADDR(x)                     (((uint32_t)(((uint32_t)(x)) << F16ASM_RADR_RADDR_SHIFT)) & F16ASM_RADR_RADDR_MASK)

#define F16ASM_RADR_RUL_MASK                     (0x2000000U)
#define F16ASM_RADR_RUL_SHIFT                    (25U)
#define F16ASM_RADR_RUL_WIDTH                    (1U)
#define F16ASM_RADR_RUL(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_RADR_RUL_SHIFT)) & F16ASM_RADR_RUL_MASK)

#define F16ASM_RADR_SPR_MASK                     (0x4000000U)
#define F16ASM_RADR_SPR_SHIFT                    (26U)
#define F16ASM_RADR_SPR_WIDTH                    (1U)
#define F16ASM_RADR_SPR(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_RADR_SPR_SHIFT)) & F16ASM_RADR_SPR_MASK)

#define F16ASM_RADR_OTPR_MASK                    (0x8000000U)
#define F16ASM_RADR_OTPR_SHIFT                   (27U)
#define F16ASM_RADR_OTPR_WIDTH                   (1U)
#define F16ASM_RADR_OTPR(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_RADR_OTPR_SHIFT)) & F16ASM_RADR_OTPR_MASK)

#define F16ASM_RADR_UTRR_MASK                    (0x10000000U)
#define F16ASM_RADR_UTRR_SHIFT                   (28U)
#define F16ASM_RADR_UTRR_WIDTH                   (1U)
#define F16ASM_RADR_UTRR(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_RADR_UTRR_SHIFT)) & F16ASM_RADR_UTRR_MASK)
/*! @} */

/*! @name WADR - Write Address Logging */
/*! @{ */

#define F16ASM_WADR_WADDR_MASK                   (0x1FFFFE0U)
#define F16ASM_WADR_WADDR_SHIFT                  (5U)
#define F16ASM_WADR_WADDR_WIDTH                  (20U)
#define F16ASM_WADR_WADDR(x)                     (((uint32_t)(((uint32_t)(x)) << F16ASM_WADR_WADDR_SHIFT)) & F16ASM_WADR_WADDR_MASK)

#define F16ASM_WADR_WUL_MASK                     (0x2000000U)
#define F16ASM_WADR_WUL_SHIFT                    (25U)
#define F16ASM_WADR_WUL_WIDTH                    (1U)
#define F16ASM_WADR_WUL(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_WADR_WUL_SHIFT)) & F16ASM_WADR_WUL_MASK)

#define F16ASM_WADR_SPW_MASK                     (0x4000000U)
#define F16ASM_WADR_SPW_SHIFT                    (26U)
#define F16ASM_WADR_SPW_WIDTH                    (1U)
#define F16ASM_WADR_SPW(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_WADR_SPW_SHIFT)) & F16ASM_WADR_SPW_MASK)

#define F16ASM_WADR_OTPW_MASK                    (0x8000000U)
#define F16ASM_WADR_OTPW_SHIFT                   (27U)
#define F16ASM_WADR_OTPW_WIDTH                   (1U)
#define F16ASM_WADR_OTPW(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_WADR_OTPW_SHIFT)) & F16ASM_WADR_OTPW_MASK)

#define F16ASM_WADR_UTRW_MASK                    (0x10000000U)
#define F16ASM_WADR_UTRW_SHIFT                   (28U)
#define F16ASM_WADR_UTRW_WIDTH                   (1U)
#define F16ASM_WADR_UTRW(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_WADR_UTRW_SHIFT)) & F16ASM_WADR_UTRW_MASK)
/*! @} */

/*! @name LOCK0 - Partition Lock 0 */
/*! @{ */

#define F16ASM_LOCK0_LPLOCKL_MASK                (0xFFFFU)
#define F16ASM_LOCK0_LPLOCKL_SHIFT               (0U)
#define F16ASM_LOCK0_LPLOCKL_WIDTH               (16U)
#define F16ASM_LOCK0_LPLOCKL(x)                  (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK0_LPLOCKL_SHIFT)) & F16ASM_LOCK0_LPLOCKL_MASK)

#define F16ASM_LOCK0_LPLOCKU_MASK                (0xFFFF0000U)
#define F16ASM_LOCK0_LPLOCKU_SHIFT               (16U)
#define F16ASM_LOCK0_LPLOCKU_WIDTH               (16U)
#define F16ASM_LOCK0_LPLOCKU(x)                  (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK0_LPLOCKU_SHIFT)) & F16ASM_LOCK0_LPLOCKU_MASK)
/*! @} */

/*! @name LOCK1 - Partition Lock 1 */
/*! @{ */

#define F16ASM_LOCK1_SPLOCKL_MASK                (0x3U)
#define F16ASM_LOCK1_SPLOCKL_SHIFT               (0U)
#define F16ASM_LOCK1_SPLOCKL_WIDTH               (2U)
#define F16ASM_LOCK1_SPLOCKL(x)                  (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK1_SPLOCKL_SHIFT)) & F16ASM_LOCK1_SPLOCKL_MASK)

#define F16ASM_LOCK1_SPLOCKU_MASK                (0xCU)
#define F16ASM_LOCK1_SPLOCKU_SHIFT               (2U)
#define F16ASM_LOCK1_SPLOCKU_WIDTH               (2U)
#define F16ASM_LOCK1_SPLOCKU(x)                  (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK1_SPLOCKU_SHIFT)) & F16ASM_LOCK1_SPLOCKU_MASK)

#define F16ASM_LOCK1_OLOCKL_MASK                 (0x10U)
#define F16ASM_LOCK1_OLOCKL_SHIFT                (4U)
#define F16ASM_LOCK1_OLOCKL_WIDTH                (1U)
#define F16ASM_LOCK1_OLOCKL(x)                   (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK1_OLOCKL_SHIFT)) & F16ASM_LOCK1_OLOCKL_MASK)

#define F16ASM_LOCK1_OLOCKU_MASK                 (0x20U)
#define F16ASM_LOCK1_OLOCKU_SHIFT                (5U)
#define F16ASM_LOCK1_OLOCKU_WIDTH                (1U)
#define F16ASM_LOCK1_OLOCKU(x)                   (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK1_OLOCKU_SHIFT)) & F16ASM_LOCK1_OLOCKU_MASK)

#define F16ASM_LOCK1_UTLOCKL_MASK                (0x40U)
#define F16ASM_LOCK1_UTLOCKL_SHIFT               (6U)
#define F16ASM_LOCK1_UTLOCKL_WIDTH               (1U)
#define F16ASM_LOCK1_UTLOCKL(x)                  (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK1_UTLOCKL_SHIFT)) & F16ASM_LOCK1_UTLOCKL_MASK)

#define F16ASM_LOCK1_UTLOCKU_MASK                (0x80U)
#define F16ASM_LOCK1_UTLOCKU_SHIFT               (7U)
#define F16ASM_LOCK1_UTLOCKU_WIDTH               (1U)
#define F16ASM_LOCK1_UTLOCKU(x)                  (((uint32_t)(((uint32_t)(x)) << F16ASM_LOCK1_UTLOCKU_SHIFT)) & F16ASM_LOCK1_UTLOCKU_MASK)
/*! @} */

/*! @name UT0 - UTest 0 */
/*! @{ */

#define F16ASM_UT0_AID_MASK                      (0x1U)
#define F16ASM_UT0_AID_SHIFT                     (0U)
#define F16ASM_UT0_AID_WIDTH                     (1U)
#define F16ASM_UT0_AID(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AID_SHIFT)) & F16ASM_UT0_AID_MASK)

#define F16ASM_UT0_AIE_MASK                      (0x2U)
#define F16ASM_UT0_AIE_SHIFT                     (1U)
#define F16ASM_UT0_AIE_WIDTH                     (1U)
#define F16ASM_UT0_AIE(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AIE_SHIFT)) & F16ASM_UT0_AIE_MASK)

#define F16ASM_UT0_AIS_MASK                      (0x4U)
#define F16ASM_UT0_AIS_SHIFT                     (2U)
#define F16ASM_UT0_AIS_WIDTH                     (1U)
#define F16ASM_UT0_AIS(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AIS_SHIFT)) & F16ASM_UT0_AIS_MASK)

#define F16ASM_UT0_AISUS_MASK                    (0x40U)
#define F16ASM_UT0_AISUS_SHIFT                   (6U)
#define F16ASM_UT0_AISUS_WIDTH                   (1U)
#define F16ASM_UT0_AISUS(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AISUS_SHIFT)) & F16ASM_UT0_AISUS_MASK)

#define F16ASM_UT0_AIBPE_MASK                    (0x100U)
#define F16ASM_UT0_AIBPE_SHIFT                   (8U)
#define F16ASM_UT0_AIBPE_WIDTH                   (1U)
#define F16ASM_UT0_AIBPE(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AIBPE_SHIFT)) & F16ASM_UT0_AIBPE_MASK)

#define F16ASM_UT0_NAIBP_MASK                    (0x200U)
#define F16ASM_UT0_NAIBP_SHIFT                   (9U)
#define F16ASM_UT0_NAIBP_WIDTH                   (1U)
#define F16ASM_UT0_NAIBP(x)                      (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_NAIBP_SHIFT)) & F16ASM_UT0_NAIBP_MASK)

#define F16ASM_UT0_EIE_MASK                      (0x1000U)
#define F16ASM_UT0_EIE_SHIFT                     (12U)
#define F16ASM_UT0_EIE_WIDTH                     (1U)
#define F16ASM_UT0_EIE(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_EIE_SHIFT)) & F16ASM_UT0_EIE_MASK)

#define F16ASM_UT0_EDIE_MASK                     (0x2000U)
#define F16ASM_UT0_EDIE_SHIFT                    (13U)
#define F16ASM_UT0_EDIE_WIDTH                    (1U)
#define F16ASM_UT0_EDIE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_EDIE_SHIFT)) & F16ASM_UT0_EDIE_MASK)

#define F16ASM_UT0_AEIE_MASK                     (0x4000U)
#define F16ASM_UT0_AEIE_SHIFT                    (14U)
#define F16ASM_UT0_AEIE_WIDTH                    (1U)
#define F16ASM_UT0_AEIE(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AEIE_SHIFT)) & F16ASM_UT0_AEIE_MASK)

#define F16ASM_UT0_AILL_MASK                     (0x3000000U)
#define F16ASM_UT0_AILL_SHIFT                    (24U)
#define F16ASM_UT0_AILL_WIDTH                    (2U)
#define F16ASM_UT0_AILL(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AILL_SHIFT)) & F16ASM_UT0_AILL_MASK)

#define F16ASM_UT0_AILU_MASK                     (0xC000000U)
#define F16ASM_UT0_AILU_SHIFT                    (26U)
#define F16ASM_UT0_AILU_WIDTH                    (2U)
#define F16ASM_UT0_AILU(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_AILU_SHIFT)) & F16ASM_UT0_AILU_MASK)

#define F16ASM_UT0_FW_MASK                       (0x10000000U)
#define F16ASM_UT0_FW_SHIFT                      (28U)
#define F16ASM_UT0_FW_WIDTH                      (1U)
#define F16ASM_UT0_FW(x)                         (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_FW_SHIFT)) & F16ASM_UT0_FW_MASK)

#define F16ASM_UT0_RRE_MASK                      (0x40000000U)
#define F16ASM_UT0_RRE_SHIFT                     (30U)
#define F16ASM_UT0_RRE_WIDTH                     (1U)
#define F16ASM_UT0_RRE(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_RRE_SHIFT)) & F16ASM_UT0_RRE_MASK)

#define F16ASM_UT0_UTE_MASK                      (0x80000000U)
#define F16ASM_UT0_UTE_SHIFT                     (31U)
#define F16ASM_UT0_UTE_WIDTH                     (1U)
#define F16ASM_UT0_UTE(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UT0_UTE_SHIFT)) & F16ASM_UT0_UTE_MASK)
/*! @} */

/*! @name UMISR - UTest Multiple Input Signature 0..UTest Multiple Input Signature 8 */
/*! @{ */

#define F16ASM_UMISR_MISR_MASK                   (0xFFFFFFFFU)
#define F16ASM_UMISR_MISR_SHIFT                  (0U)
#define F16ASM_UMISR_MISR_WIDTH                  (32U)
#define F16ASM_UMISR_MISR(x)                     (((uint32_t)(((uint32_t)(x)) << F16ASM_UMISR_MISR_SHIFT)) & F16ASM_UMISR_MISR_MASK)
/*! @} */

/*! @name UMISR9 - UTest Multiple Input Signature 9 */
/*! @{ */

#define F16ASM_UMISR9_MISR_MASK                  (0x1U)
#define F16ASM_UMISR9_MISR_SHIFT                 (0U)
#define F16ASM_UMISR9_MISR_WIDTH                 (1U)
#define F16ASM_UMISR9_MISR(x)                    (((uint32_t)(((uint32_t)(x)) << F16ASM_UMISR9_MISR_SHIFT)) & F16ASM_UMISR9_MISR_MASK)
/*! @} */

/*! @name UD_0_TO_7 - UTest Data 0..UTest Data 7 */
/*! @{ */

#define F16ASM_UD_0_TO_7_EDATA_MASK              (0xFFFFFFFFU)
#define F16ASM_UD_0_TO_7_EDATA_SHIFT             (0U)
#define F16ASM_UD_0_TO_7_EDATA_WIDTH             (32U)
#define F16ASM_UD_0_TO_7_EDATA(x)                (((uint32_t)(((uint32_t)(x)) << F16ASM_UD_0_TO_7_EDATA_SHIFT)) & F16ASM_UD_0_TO_7_EDATA_MASK)
/*! @} */

/*! @name UD8 - UTest Data 8 */
/*! @{ */

#define F16ASM_UD8_EDATAC_MASK                   (0xFFFFFFFU)
#define F16ASM_UD8_EDATAC_SHIFT                  (0U)
#define F16ASM_UD8_EDATAC_WIDTH                  (28U)
#define F16ASM_UD8_EDATAC(x)                     (((uint32_t)(((uint32_t)(x)) << F16ASM_UD8_EDATAC_SHIFT)) & F16ASM_UD8_EDATAC_MASK)
/*! @} */

/*! @name UD_9_TO_16 - UTest Data 9..UTest Data 16 */
/*! @{ */

#define F16ASM_UD_9_TO_16_EDDATA_MASK            (0xFFFFFFFFU)
#define F16ASM_UD_9_TO_16_EDDATA_SHIFT           (0U)
#define F16ASM_UD_9_TO_16_EDDATA_WIDTH           (32U)
#define F16ASM_UD_9_TO_16_EDDATA(x)              (((uint32_t)(((uint32_t)(x)) << F16ASM_UD_9_TO_16_EDDATA_SHIFT)) & F16ASM_UD_9_TO_16_EDDATA_MASK)
/*! @} */

/*! @name UD17 - UTest Data 17 */
/*! @{ */

#define F16ASM_UD17_EDDATAC_MASK                 (0xFFFFFFFU)
#define F16ASM_UD17_EDDATAC_SHIFT                (0U)
#define F16ASM_UD17_EDDATAC_WIDTH                (28U)
#define F16ASM_UD17_EDDATAC(x)                   (((uint32_t)(((uint32_t)(x)) << F16ASM_UD17_EDDATAC_SHIFT)) & F16ASM_UD17_EDDATAC_MASK)
/*! @} */

/*! @name UA0 - UTest Address 0 */
/*! @{ */

#define F16ASM_UA0_AEI_MASK                      (0xFFFFFFU)
#define F16ASM_UA0_AEI_SHIFT                     (0U)
#define F16ASM_UA0_AEI_WIDTH                     (24U)
#define F16ASM_UA0_AEI(x)                        (((uint32_t)(((uint32_t)(x)) << F16ASM_UA0_AEI_SHIFT)) & F16ASM_UA0_AEI_MASK)

#define F16ASM_UA0_AEIS_MASK                     (0xF0000000U)
#define F16ASM_UA0_AEIS_SHIFT                    (28U)
#define F16ASM_UA0_AEIS_WIDTH                    (4U)
#define F16ASM_UA0_AEIS(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UA0_AEIS_SHIFT)) & F16ASM_UA0_AEIS_MASK)
/*! @} */

/*! @name UA1 - UTest Address 1 */
/*! @{ */

#define F16ASM_UA1_AEIO_MASK                     (0x7FFFFFU)
#define F16ASM_UA1_AEIO_SHIFT                    (0U)
#define F16ASM_UA1_AEIO_WIDTH                    (23U)
#define F16ASM_UA1_AEIO(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UA1_AEIO_SHIFT)) & F16ASM_UA1_AEIO_MASK)

#define F16ASM_UA1_AEIC_MASK                     (0xFF000000U)
#define F16ASM_UA1_AEIC_SHIFT                    (24U)
#define F16ASM_UA1_AEIC_WIDTH                    (8U)
#define F16ASM_UA1_AEIC(x)                       (((uint32_t)(((uint32_t)(x)) << F16ASM_UA1_AEIC_SHIFT)) & F16ASM_UA1_AEIC_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group F16ASM_Register_Masks */

/*!
 * @}
 */ /* end of group F16ASM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_F16ASM_H_) */
