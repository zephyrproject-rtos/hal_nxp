/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DBG.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DBG
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
#if !defined(S32Z2_DBG_H_)  /* Check if memory map has not been already included */
#define S32Z2_DBG_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DBG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DBG_Peripheral_Access_Layer DBG Peripheral Access Layer
 * @{
 */

/** DBG - Register Layout Typedef */
typedef struct {
  __IO uint32_t DBG_DDAM;                          /**< DDMA Breakpoint Register, offset: 0x0 */
  __O  uint32_t DBGACS;                            /**< Error Access Control Register, offset: 0x4 */
  __IO uint32_t DBG_DDC;                           /**< DDMA Breakpoint Control Register, offset: 0x8 */
  __IO uint32_t DBG_DDS;                           /**< DDMA Breakpoint Status Register, offset: 0xC */
  __IO uint32_t CENSIRQ;                           /**< Critical Error Interrupt Requests Register, offset: 0x10 */
  __IO uint32_t CENSIRQ2;                          /**< Critical Errors Interrupt 2 Register, offset: 0x14 */
  __IO uint32_t CWDOGIRQ;                          /**< Critical Error Interrupt Requests Register, offset: 0x18 */
  __IO uint32_t NENSIRQ;                           /**< Normal Error Interrupt Requests Register, offset: 0x1C */
  __IO uint32_t TIMER_IRQ;                         /**< Timer Interrupt Source Register, offset: 0x20 */
  __IO uint32_t DMA_IRQ;                           /**< DMA Interrupt Source Register, offset: 0x24 */
  __IO uint32_t POSCINT;                           /**< Posted Core Interrupt Register, offset: 0x28 */
  uint8_t RESERVED_0[4];
  __I  uint32_t NQBIRQ;                            /**< Normal QMAN and Buffers Interrupt Register, offset: 0x30 */
  uint8_t RESERVED_1[8];
  __IO uint32_t NENSIRQ_M;                         /**< Normal Error Interrupt Request Mask Register, offset: 0x3C */
  __IO uint32_t TIMER_IRQ_M;                       /**< Timer Interrupt Mask Register, offset: 0x40 */
  __IO uint32_t NQBIRQ_M;                          /**< Normal QMAN and Buffers Interrupt Mask Register, offset: 0x44 */
  uint8_t RESERVED_2[8];
  __IO uint32_t DBG_STACK_START;                   /**< Stack Violation Start Address Register, offset: 0x50 */
  __IO uint32_t DBG_STACK_END;                     /**< Stack Violation End Address Register, offset: 0x54 */
  __IO uint32_t DBG_DUNMPD_MSK;                    /**< DBG DMSS Unmapped Access Mask Register, offset: 0x58 */
  __IO uint32_t DBG_DUNMPD;                        /**< DMSS Unmapped Access Status Register, offset: 0x5C */
  __O  uint32_t CENSIRQ_S;                         /**< Critical Error Interrupt Request Shadow Register, offset: 0x60 */
  __O  uint32_t CENSIRQ2_S;                        /**< Critical Error Interrupt Request 2 Shadow Register, offset: 0x64 */
  __O  uint32_t CWDOGIRQ_S;                        /**< Critical Error Interrupt Request Shadow Register, offset: 0x68 */
  __O  uint32_t NENSIRQ_S;                         /**< Normal Error Interrupt Requests Shadow Register, offset: 0x6C */
  __O  uint32_t TIMER_IRQ_S;                       /**< Timer Interrupt Shadow Register, offset: 0x70 */
  __O  uint32_t DMA_IRQ_S;                         /**< DMA Interrupt Shadow Register, offset: 0x74 */
  uint8_t RESERVED_3[56];
  __IO uint32_t DBG_DESC_ID;                       /**< DBG DESC ID Register, offset: 0xB0 */
  __IO uint32_t DBG_QMAN_ID;                       /**< DBG QMAN ID Register, offset: 0xB4 */
  uint8_t RESERVED_4[8];
  __IO uint32_t XCI_COR;                           /**< MSS Acknowledge Control Register, offset: 0xC0 */
} DBG_Type, *DBG_MemMapPtr;

/** Number of instances of the DBG module. */
#define DBG_INSTANCE_COUNT                       (1u)

/* DBG - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__DBG base address */
#define IP_CEVA_SPF2__DBG_BASE                   (0x24400D00u)
/** Peripheral CEVA_SPF2__DBG base pointer */
#define IP_CEVA_SPF2__DBG                        ((DBG_Type *)IP_CEVA_SPF2__DBG_BASE)
/** Array initializer of DBG peripheral base addresses */
#define IP_DBG_BASE_ADDRS                        { IP_CEVA_SPF2__DBG_BASE }
/** Array initializer of DBG peripheral base pointers */
#define IP_DBG_BASE_PTRS                         { IP_CEVA_SPF2__DBG }

/* ----------------------------------------------------------------------------
   -- DBG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DBG_Register_Masks DBG Register Masks
 * @{
 */

/*! @name DBG_DDAM - DDMA Breakpoint Register */
/*! @{ */

#define DBG_DBG_DDAM_DMADAM_MASK                 (0xFFFFFFFFU)
#define DBG_DBG_DDAM_DMADAM_SHIFT                (0U)
#define DBG_DBG_DDAM_DMADAM_WIDTH                (32U)
#define DBG_DBG_DDAM_DMADAM(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DDAM_DMADAM_SHIFT)) & DBG_DBG_DDAM_DMADAM_MASK)
/*! @} */

/*! @name DBGACS - Error Access Control Register */
/*! @{ */

#define DBG_DBGACS_DBG_ACS_MASK                  (0xFFFFU)
#define DBG_DBGACS_DBG_ACS_SHIFT                 (0U)
#define DBG_DBGACS_DBG_ACS_WIDTH                 (16U)
#define DBG_DBGACS_DBG_ACS(x)                    (((uint32_t)(((uint32_t)(x)) << DBG_DBGACS_DBG_ACS_SHIFT)) & DBG_DBGACS_DBG_ACS_MASK)
/*! @} */

/*! @name DBG_DDC - DDMA Breakpoint Control Register */
/*! @{ */

#define DBG_DBG_DDC_DMADAMS_MASK                 (0x7U)
#define DBG_DBG_DDC_DMADAMS_SHIFT                (0U)
#define DBG_DBG_DDC_DMADAMS_WIDTH                (3U)
#define DBG_DBG_DDC_DMADAMS(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DDC_DMADAMS_SHIFT)) & DBG_DBG_DDC_DMADAMS_MASK)
/*! @} */

/*! @name DBG_DDS - DDMA Breakpoint Status Register */
/*! @{ */

#define DBG_DBG_DDS_DMADAMST_MASK                (0x7U)
#define DBG_DBG_DDS_DMADAMST_SHIFT               (0U)
#define DBG_DBG_DDS_DMADAMST_WIDTH               (3U)
#define DBG_DBG_DDS_DMADAMST(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DDS_DMADAMST_SHIFT)) & DBG_DBG_DDS_DMADAMST_MASK)
/*! @} */

/*! @name CENSIRQ - Critical Error Interrupt Requests Register */
/*! @{ */

#define DBG_CENSIRQ_CNSE_MASK                    (0x1U)
#define DBG_CENSIRQ_CNSE_SHIFT                   (0U)
#define DBG_CENSIRQ_CNSE_WIDTH                   (1U)
#define DBG_CENSIRQ_CNSE(x)                      (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_CNSE_SHIFT)) & DBG_CENSIRQ_CNSE_MASK)

#define DBG_CENSIRQ_CNSIPV_MASK                  (0x2U)
#define DBG_CENSIRQ_CNSIPV_SHIFT                 (1U)
#define DBG_CENSIRQ_CNSIPV_WIDTH                 (1U)
#define DBG_CENSIRQ_CNSIPV(x)                    (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_CNSIPV_SHIFT)) & DBG_CENSIRQ_CNSIPV_MASK)

#define DBG_CENSIRQ_CNSILOP_MASK                 (0x4U)
#define DBG_CENSIRQ_CNSILOP_SHIFT                (2U)
#define DBG_CENSIRQ_CNSILOP_WIDTH                (1U)
#define DBG_CENSIRQ_CNSILOP(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_CNSILOP_SHIFT)) & DBG_CENSIRQ_CNSILOP_MASK)

#define DBG_CENSIRQ_CNSIRE_MASK                  (0x10U)
#define DBG_CENSIRQ_CNSIRE_SHIFT                 (4U)
#define DBG_CENSIRQ_CNSIRE_WIDTH                 (1U)
#define DBG_CENSIRQ_CNSIRE(x)                    (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_CNSIRE_SHIFT)) & DBG_CENSIRQ_CNSIRE_MASK)

#define DBG_CENSIRQ_IN_PRIV_MASK                 (0x100U)
#define DBG_CENSIRQ_IN_PRIV_SHIFT                (8U)
#define DBG_CENSIRQ_IN_PRIV_WIDTH                (1U)
#define DBG_CENSIRQ_IN_PRIV(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_IN_PRIV_SHIFT)) & DBG_CENSIRQ_IN_PRIV_MASK)

#define DBG_CENSIRQ_OUT_PRIV_MASK                (0x200U)
#define DBG_CENSIRQ_OUT_PRIV_SHIFT               (9U)
#define DBG_CENSIRQ_OUT_PRIV_WIDTH               (1U)
#define DBG_CENSIRQ_OUT_PRIV(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_OUT_PRIV_SHIFT)) & DBG_CENSIRQ_OUT_PRIV_MASK)

#define DBG_CENSIRQ_LD_PRIV_ACC_MASK             (0x400U)
#define DBG_CENSIRQ_LD_PRIV_ACC_SHIFT            (10U)
#define DBG_CENSIRQ_LD_PRIV_ACC_WIDTH            (1U)
#define DBG_CENSIRQ_LD_PRIV_ACC(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_LD_PRIV_ACC_SHIFT)) & DBG_CENSIRQ_LD_PRIV_ACC_MASK)

#define DBG_CENSIRQ_ST_PRIV_ACC_MASK             (0x800U)
#define DBG_CENSIRQ_ST_PRIV_ACC_SHIFT            (11U)
#define DBG_CENSIRQ_ST_PRIV_ACC_WIDTH            (1U)
#define DBG_CENSIRQ_ST_PRIV_ACC(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_ST_PRIV_ACC_SHIFT)) & DBG_CENSIRQ_ST_PRIV_ACC_MASK)

#define DBG_CENSIRQ_LD_BLANK_ACC_MASK            (0x1000U)
#define DBG_CENSIRQ_LD_BLANK_ACC_SHIFT           (12U)
#define DBG_CENSIRQ_LD_BLANK_ACC_WIDTH           (1U)
#define DBG_CENSIRQ_LD_BLANK_ACC(x)              (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_LD_BLANK_ACC_SHIFT)) & DBG_CENSIRQ_LD_BLANK_ACC_MASK)

#define DBG_CENSIRQ_ST_BLANK_ACC_MASK            (0x2000U)
#define DBG_CENSIRQ_ST_BLANK_ACC_SHIFT           (13U)
#define DBG_CENSIRQ_ST_BLANK_ACC_WIDTH           (1U)
#define DBG_CENSIRQ_ST_BLANK_ACC(x)              (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_ST_BLANK_ACC_SHIFT)) & DBG_CENSIRQ_ST_BLANK_ACC_MASK)

#define DBG_CENSIRQ_LD_RG_CROS_MASK              (0x4000U)
#define DBG_CENSIRQ_LD_RG_CROS_SHIFT             (14U)
#define DBG_CENSIRQ_LD_RG_CROS_WIDTH             (1U)
#define DBG_CENSIRQ_LD_RG_CROS(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_LD_RG_CROS_SHIFT)) & DBG_CENSIRQ_LD_RG_CROS_MASK)

#define DBG_CENSIRQ_ST_RG_CROS_MASK              (0x8000U)
#define DBG_CENSIRQ_ST_RG_CROS_SHIFT             (15U)
#define DBG_CENSIRQ_ST_RG_CROS_WIDTH             (1U)
#define DBG_CENSIRQ_ST_RG_CROS(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_ST_RG_CROS_SHIFT)) & DBG_CENSIRQ_ST_RG_CROS_MASK)

#define DBG_CENSIRQ_UNMAPPED_EXCPTN_MASK         (0x10000U)
#define DBG_CENSIRQ_UNMAPPED_EXCPTN_SHIFT        (16U)
#define DBG_CENSIRQ_UNMAPPED_EXCPTN_WIDTH        (1U)
#define DBG_CENSIRQ_UNMAPPED_EXCPTN(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_UNMAPPED_EXCPTN_SHIFT)) & DBG_CENSIRQ_UNMAPPED_EXCPTN_MASK)

#define DBG_CENSIRQ_STACK_VIOL_EXCPTN_MASK       (0x20000U)
#define DBG_CENSIRQ_STACK_VIOL_EXCPTN_SHIFT      (17U)
#define DBG_CENSIRQ_STACK_VIOL_EXCPTN_WIDTH      (1U)
#define DBG_CENSIRQ_STACK_VIOL_EXCPTN(x)         (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_STACK_VIOL_EXCPTN_SHIFT)) & DBG_CENSIRQ_STACK_VIOL_EXCPTN_MASK)

#define DBG_CENSIRQ_EXC_E_MASK                   (0x40000U)
#define DBG_CENSIRQ_EXC_E_SHIFT                  (18U)
#define DBG_CENSIRQ_EXC_E_WIDTH                  (1U)
#define DBG_CENSIRQ_EXC_E(x)                     (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_EXC_E_SHIFT)) & DBG_CENSIRQ_EXC_E_MASK)

#define DBG_CENSIRQ_ER_EXOK_MASK                 (0x80000U)
#define DBG_CENSIRQ_ER_EXOK_SHIFT                (19U)
#define DBG_CENSIRQ_ER_EXOK_WIDTH                (1U)
#define DBG_CENSIRQ_ER_EXOK(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_ER_EXOK_SHIFT)) & DBG_CENSIRQ_ER_EXOK_MASK)

#define DBG_CENSIRQ_LD_IDM_CROS_MASK             (0x100000U)
#define DBG_CENSIRQ_LD_IDM_CROS_SHIFT            (20U)
#define DBG_CENSIRQ_LD_IDM_CROS_WIDTH            (1U)
#define DBG_CENSIRQ_LD_IDM_CROS(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_LD_IDM_CROS_SHIFT)) & DBG_CENSIRQ_LD_IDM_CROS_MASK)

#define DBG_CENSIRQ_ST_IDM_CROS_MASK             (0x200000U)
#define DBG_CENSIRQ_ST_IDM_CROS_SHIFT            (21U)
#define DBG_CENSIRQ_ST_IDM_CROS_WIDTH            (1U)
#define DBG_CENSIRQ_ST_IDM_CROS(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_ST_IDM_CROS_SHIFT)) & DBG_CENSIRQ_ST_IDM_CROS_MASK)

#define DBG_CENSIRQ_VLD_ADR_ERR_MASK             (0x400000U)
#define DBG_CENSIRQ_VLD_ADR_ERR_SHIFT            (22U)
#define DBG_CENSIRQ_VLD_ADR_ERR_WIDTH            (1U)
#define DBG_CENSIRQ_VLD_ADR_ERR(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_VLD_ADR_ERR_SHIFT)) & DBG_CENSIRQ_VLD_ADR_ERR_MASK)

#define DBG_CENSIRQ_VST_ADR_ERR_MASK             (0x800000U)
#define DBG_CENSIRQ_VST_ADR_ERR_SHIFT            (23U)
#define DBG_CENSIRQ_VST_ADR_ERR_WIDTH            (1U)
#define DBG_CENSIRQ_VST_ADR_ERR(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_VST_ADR_ERR_SHIFT)) & DBG_CENSIRQ_VST_ADR_ERR_MASK)

#define DBG_CENSIRQ_HIST_IDM_CROS_MASK           (0x1000000U)
#define DBG_CENSIRQ_HIST_IDM_CROS_SHIFT          (24U)
#define DBG_CENSIRQ_HIST_IDM_CROS_WIDTH          (1U)
#define DBG_CENSIRQ_HIST_IDM_CROS(x)             (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_HIST_IDM_CROS_SHIFT)) & DBG_CENSIRQ_HIST_IDM_CROS_MASK)
/*! @} */

/*! @name CENSIRQ2 - Critical Errors Interrupt 2 Register */
/*! @{ */

#define DBG_CENSIRQ2_DDMA_ERR_ACC_MASK           (0x2U)
#define DBG_CENSIRQ2_DDMA_ERR_ACC_SHIFT          (1U)
#define DBG_CENSIRQ2_DDMA_ERR_ACC_WIDTH          (1U)
#define DBG_CENSIRQ2_DDMA_ERR_ACC(x)             (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_DDMA_ERR_ACC_SHIFT)) & DBG_CENSIRQ2_DDMA_ERR_ACC_MASK)

#define DBG_CENSIRQ2_QMAN_ERR_ACC_MASK           (0x4U)
#define DBG_CENSIRQ2_QMAN_ERR_ACC_SHIFT          (2U)
#define DBG_CENSIRQ2_QMAN_ERR_ACC_WIDTH          (1U)
#define DBG_CENSIRQ2_QMAN_ERR_ACC(x)             (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_QMAN_ERR_ACC_SHIFT)) & DBG_CENSIRQ2_QMAN_ERR_ACC_MASK)

#define DBG_CENSIRQ2_QMAN_IDM_CROS_MASK          (0x8U)
#define DBG_CENSIRQ2_QMAN_IDM_CROS_SHIFT         (3U)
#define DBG_CENSIRQ2_QMAN_IDM_CROS_WIDTH         (1U)
#define DBG_CENSIRQ2_QMAN_IDM_CROS(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_QMAN_IDM_CROS_SHIFT)) & DBG_CENSIRQ2_QMAN_IDM_CROS_MASK)

#define DBG_CENSIRQ2_DDMA_RG_CROS_MASK           (0x80U)
#define DBG_CENSIRQ2_DDMA_RG_CROS_SHIFT          (7U)
#define DBG_CENSIRQ2_DDMA_RG_CROS_WIDTH          (1U)
#define DBG_CENSIRQ2_DDMA_RG_CROS(x)             (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_DDMA_RG_CROS_SHIFT)) & DBG_CENSIRQ2_DDMA_RG_CROS_MASK)

#define DBG_CENSIRQ2_DDMA_IDM_CROS_MASK          (0x100U)
#define DBG_CENSIRQ2_DDMA_IDM_CROS_SHIFT         (8U)
#define DBG_CENSIRQ2_DDMA_IDM_CROS_WIDTH         (1U)
#define DBG_CENSIRQ2_DDMA_IDM_CROS(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_DDMA_IDM_CROS_SHIFT)) & DBG_CENSIRQ2_DDMA_IDM_CROS_MASK)

#define DBG_CENSIRQ2_ER_IOP_MASK                 (0x400U)
#define DBG_CENSIRQ2_ER_IOP_SHIFT                (10U)
#define DBG_CENSIRQ2_ER_IOP_WIDTH                (1U)
#define DBG_CENSIRQ2_ER_IOP(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_ER_IOP_SHIFT)) & DBG_CENSIRQ2_ER_IOP_MASK)

#define DBG_CENSIRQ2_ER_EDP_MASK                 (0x1000U)
#define DBG_CENSIRQ2_ER_EDP_SHIFT                (12U)
#define DBG_CENSIRQ2_ER_EDP_WIDTH                (1U)
#define DBG_CENSIRQ2_ER_EDP(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_ER_EDP_SHIFT)) & DBG_CENSIRQ2_ER_EDP_MASK)

#define DBG_CENSIRQ2_D_UCSERR_MASK               (0x40000000U)
#define DBG_CENSIRQ2_D_UCSERR_SHIFT              (30U)
#define DBG_CENSIRQ2_D_UCSERR_WIDTH              (1U)
#define DBG_CENSIRQ2_D_UCSERR(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_D_UCSERR_SHIFT)) & DBG_CENSIRQ2_D_UCSERR_MASK)

#define DBG_CENSIRQ2_P_UCSERR_MASK               (0x80000000U)
#define DBG_CENSIRQ2_P_UCSERR_SHIFT              (31U)
#define DBG_CENSIRQ2_P_UCSERR_WIDTH              (1U)
#define DBG_CENSIRQ2_P_UCSERR(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_P_UCSERR_SHIFT)) & DBG_CENSIRQ2_P_UCSERR_MASK)
/*! @} */

/*! @name CWDOGIRQ - Critical Error Interrupt Requests Register */
/*! @{ */

#define DBG_CWDOGIRQ_CNSE_MASK                   (0x1U)
#define DBG_CWDOGIRQ_CNSE_SHIFT                  (0U)
#define DBG_CWDOGIRQ_CNSE_WIDTH                  (1U)
#define DBG_CWDOGIRQ_CNSE(x)                     (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_CNSE_SHIFT)) & DBG_CWDOGIRQ_CNSE_MASK)

#define DBG_CWDOGIRQ_WDOG_MAX_MASK               (0x10000U)
#define DBG_CWDOGIRQ_WDOG_MAX_SHIFT              (16U)
#define DBG_CWDOGIRQ_WDOG_MAX_WIDTH              (1U)
#define DBG_CWDOGIRQ_WDOG_MAX(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_WDOG_MAX_SHIFT)) & DBG_CWDOGIRQ_WDOG_MAX_MASK)

#define DBG_CWDOGIRQ_WDOG_MIN_MASK               (0x20000U)
#define DBG_CWDOGIRQ_WDOG_MIN_SHIFT              (17U)
#define DBG_CWDOGIRQ_WDOG_MIN_WIDTH              (1U)
#define DBG_CWDOGIRQ_WDOG_MIN(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_WDOG_MIN_SHIFT)) & DBG_CWDOGIRQ_WDOG_MIN_MASK)

#define DBG_CWDOGIRQ_ICUWD_MASK                  (0x100000U)
#define DBG_CWDOGIRQ_ICUWD_SHIFT                 (20U)
#define DBG_CWDOGIRQ_ICUWD_WIDTH                 (1U)
#define DBG_CWDOGIRQ_ICUWD(x)                    (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_ICUWD_SHIFT)) & DBG_CWDOGIRQ_ICUWD_MASK)

#define DBG_CWDOGIRQ_IOPWDOG_V_MASK              (0x20000000U)
#define DBG_CWDOGIRQ_IOPWDOG_V_SHIFT             (29U)
#define DBG_CWDOGIRQ_IOPWDOG_V_WIDTH             (1U)
#define DBG_CWDOGIRQ_IOPWDOG_V(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_IOPWDOG_V_SHIFT)) & DBG_CWDOGIRQ_IOPWDOG_V_MASK)

#define DBG_CWDOGIRQ_EDPWDOG_V_MASK              (0x40000000U)
#define DBG_CWDOGIRQ_EDPWDOG_V_SHIFT             (30U)
#define DBG_CWDOGIRQ_EDPWDOG_V_WIDTH             (1U)
#define DBG_CWDOGIRQ_EDPWDOG_V(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_EDPWDOG_V_SHIFT)) & DBG_CWDOGIRQ_EDPWDOG_V_MASK)

#define DBG_CWDOGIRQ_EPPWDOG_V_MASK              (0x80000000U)
#define DBG_CWDOGIRQ_EPPWDOG_V_SHIFT             (31U)
#define DBG_CWDOGIRQ_EPPWDOG_V_WIDTH             (1U)
#define DBG_CWDOGIRQ_EPPWDOG_V(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_EPPWDOG_V_SHIFT)) & DBG_CWDOGIRQ_EPPWDOG_V_MASK)
/*! @} */

/*! @name NENSIRQ - Normal Error Interrupt Requests Register */
/*! @{ */

#define DBG_NENSIRQ_NNSE_MASK                    (0x1U)
#define DBG_NENSIRQ_NNSE_SHIFT                   (0U)
#define DBG_NENSIRQ_NNSE_WIDTH                   (1U)
#define DBG_NENSIRQ_NNSE(x)                      (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_NNSE_SHIFT)) & DBG_NENSIRQ_NNSE_MASK)

#define DBG_NENSIRQ_DIV_0_V_MASK                 (0x2U)
#define DBG_NENSIRQ_DIV_0_V_SHIFT                (1U)
#define DBG_NENSIRQ_DIV_0_V_WIDTH                (1U)
#define DBG_NENSIRQ_DIV_0_V(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_DIV_0_V_SHIFT)) & DBG_NENSIRQ_DIV_0_V_MASK)

#define DBG_NENSIRQ_OVRFLW_EXCPTN_MASK           (0x4U)
#define DBG_NENSIRQ_OVRFLW_EXCPTN_SHIFT          (2U)
#define DBG_NENSIRQ_OVRFLW_EXCPTN_WIDTH          (1U)
#define DBG_NENSIRQ_OVRFLW_EXCPTN(x)             (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_OVRFLW_EXCPTN_SHIFT)) & DBG_NENSIRQ_OVRFLW_EXCPTN_MASK)

#define DBG_NENSIRQ_EDAP_R_OOR_MASK              (0x4000U)
#define DBG_NENSIRQ_EDAP_R_OOR_SHIFT             (14U)
#define DBG_NENSIRQ_EDAP_R_OOR_WIDTH             (1U)
#define DBG_NENSIRQ_EDAP_R_OOR(x)                (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_EDAP_R_OOR_SHIFT)) & DBG_NENSIRQ_EDAP_R_OOR_MASK)

#define DBG_NENSIRQ_EDAP_W_OOR_MASK              (0x8000U)
#define DBG_NENSIRQ_EDAP_W_OOR_SHIFT             (15U)
#define DBG_NENSIRQ_EDAP_W_OOR_WIDTH             (1U)
#define DBG_NENSIRQ_EDAP_W_OOR(x)                (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_EDAP_W_OOR_SHIFT)) & DBG_NENSIRQ_EDAP_W_OOR_MASK)

#define DBG_NENSIRQ_EPP_CF_ERR_MASK              (0x40000U)
#define DBG_NENSIRQ_EPP_CF_ERR_SHIFT             (18U)
#define DBG_NENSIRQ_EPP_CF_ERR_WIDTH             (1U)
#define DBG_NENSIRQ_EPP_CF_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_EPP_CF_ERR_SHIFT)) & DBG_NENSIRQ_EPP_CF_ERR_MASK)

#define DBG_NENSIRQ_D_CSERR_MASK                 (0x40000000U)
#define DBG_NENSIRQ_D_CSERR_SHIFT                (30U)
#define DBG_NENSIRQ_D_CSERR_WIDTH                (1U)
#define DBG_NENSIRQ_D_CSERR(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_D_CSERR_SHIFT)) & DBG_NENSIRQ_D_CSERR_MASK)

#define DBG_NENSIRQ_P_CSERR_MASK                 (0x80000000U)
#define DBG_NENSIRQ_P_CSERR_SHIFT                (31U)
#define DBG_NENSIRQ_P_CSERR_WIDTH                (1U)
#define DBG_NENSIRQ_P_CSERR(x)                   (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_P_CSERR_SHIFT)) & DBG_NENSIRQ_P_CSERR_MASK)
/*! @} */

/*! @name TIMER_IRQ - Timer Interrupt Source Register */
/*! @{ */

#define DBG_TIMER_IRQ_TIMER0_IRQ_MASK            (0x1U)
#define DBG_TIMER_IRQ_TIMER0_IRQ_SHIFT           (0U)
#define DBG_TIMER_IRQ_TIMER0_IRQ_WIDTH           (1U)
#define DBG_TIMER_IRQ_TIMER0_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_TIMER0_IRQ_SHIFT)) & DBG_TIMER_IRQ_TIMER0_IRQ_MASK)

#define DBG_TIMER_IRQ_TIMER1_IRQ_MASK            (0x2U)
#define DBG_TIMER_IRQ_TIMER1_IRQ_SHIFT           (1U)
#define DBG_TIMER_IRQ_TIMER1_IRQ_WIDTH           (1U)
#define DBG_TIMER_IRQ_TIMER1_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_TIMER1_IRQ_SHIFT)) & DBG_TIMER_IRQ_TIMER1_IRQ_MASK)

#define DBG_TIMER_IRQ_TIMER2_IRQ_MASK            (0x4U)
#define DBG_TIMER_IRQ_TIMER2_IRQ_SHIFT           (2U)
#define DBG_TIMER_IRQ_TIMER2_IRQ_WIDTH           (1U)
#define DBG_TIMER_IRQ_TIMER2_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_TIMER2_IRQ_SHIFT)) & DBG_TIMER_IRQ_TIMER2_IRQ_MASK)

#define DBG_TIMER_IRQ_TIMER3_IRQ_MASK            (0x8U)
#define DBG_TIMER_IRQ_TIMER3_IRQ_SHIFT           (3U)
#define DBG_TIMER_IRQ_TIMER3_IRQ_WIDTH           (1U)
#define DBG_TIMER_IRQ_TIMER3_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_TIMER3_IRQ_SHIFT)) & DBG_TIMER_IRQ_TIMER3_IRQ_MASK)
/*! @} */

/*! @name DMA_IRQ - DMA Interrupt Source Register */
/*! @{ */

#define DBG_DMA_IRQ_DDMA_IRQ_MASK                (0x1U)
#define DBG_DMA_IRQ_DDMA_IRQ_SHIFT               (0U)
#define DBG_DMA_IRQ_DDMA_IRQ_WIDTH               (1U)
#define DBG_DMA_IRQ_DDMA_IRQ(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_DMA_IRQ_DDMA_IRQ_SHIFT)) & DBG_DMA_IRQ_DDMA_IRQ_MASK)

#define DBG_DMA_IRQ_PDMA_IRQ_MASK                (0x2U)
#define DBG_DMA_IRQ_PDMA_IRQ_SHIFT               (1U)
#define DBG_DMA_IRQ_PDMA_IRQ_WIDTH               (1U)
#define DBG_DMA_IRQ_PDMA_IRQ(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_DMA_IRQ_PDMA_IRQ_SHIFT)) & DBG_DMA_IRQ_PDMA_IRQ_MASK)
/*! @} */

/*! @name POSCINT - Posted Core Interrupt Register */
/*! @{ */

#define DBG_POSCINT_PCINT0EN_MASK                (0x1U)
#define DBG_POSCINT_PCINT0EN_SHIFT               (0U)
#define DBG_POSCINT_PCINT0EN_WIDTH               (1U)
#define DBG_POSCINT_PCINT0EN(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT0EN_SHIFT)) & DBG_POSCINT_PCINT0EN_MASK)

#define DBG_POSCINT_PCINT1EN_MASK                (0x2U)
#define DBG_POSCINT_PCINT1EN_SHIFT               (1U)
#define DBG_POSCINT_PCINT1EN_WIDTH               (1U)
#define DBG_POSCINT_PCINT1EN(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT1EN_SHIFT)) & DBG_POSCINT_PCINT1EN_MASK)

#define DBG_POSCINT_PCINT2EN_MASK                (0x4U)
#define DBG_POSCINT_PCINT2EN_SHIFT               (2U)
#define DBG_POSCINT_PCINT2EN_WIDTH               (1U)
#define DBG_POSCINT_PCINT2EN(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT2EN_SHIFT)) & DBG_POSCINT_PCINT2EN_MASK)

#define DBG_POSCINT_PCINT3EN_MASK                (0x8U)
#define DBG_POSCINT_PCINT3EN_SHIFT               (3U)
#define DBG_POSCINT_PCINT3EN_WIDTH               (1U)
#define DBG_POSCINT_PCINT3EN(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT3EN_SHIFT)) & DBG_POSCINT_PCINT3EN_MASK)

#define DBG_POSCINT_PCINT0ST_MASK                (0x100U)
#define DBG_POSCINT_PCINT0ST_SHIFT               (8U)
#define DBG_POSCINT_PCINT0ST_WIDTH               (1U)
#define DBG_POSCINT_PCINT0ST(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT0ST_SHIFT)) & DBG_POSCINT_PCINT0ST_MASK)

#define DBG_POSCINT_PCINT1ST_MASK                (0x200U)
#define DBG_POSCINT_PCINT1ST_SHIFT               (9U)
#define DBG_POSCINT_PCINT1ST_WIDTH               (1U)
#define DBG_POSCINT_PCINT1ST(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT1ST_SHIFT)) & DBG_POSCINT_PCINT1ST_MASK)

#define DBG_POSCINT_PCINT2ST_MASK                (0x400U)
#define DBG_POSCINT_PCINT2ST_SHIFT               (10U)
#define DBG_POSCINT_PCINT2ST_WIDTH               (1U)
#define DBG_POSCINT_PCINT2ST(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT2ST_SHIFT)) & DBG_POSCINT_PCINT2ST_MASK)

#define DBG_POSCINT_PCINT3ST_MASK                (0x800U)
#define DBG_POSCINT_PCINT3ST_SHIFT               (11U)
#define DBG_POSCINT_PCINT3ST_WIDTH               (1U)
#define DBG_POSCINT_PCINT3ST(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_POSCINT_PCINT3ST_SHIFT)) & DBG_POSCINT_PCINT3ST_MASK)
/*! @} */

/*! @name NQBIRQ - Normal QMAN and Buffers Interrupt Register */
/*! @{ */

#define DBG_NQBIRQ_NQBIRQ_MASK                   (0x1U)
#define DBG_NQBIRQ_NQBIRQ_SHIFT                  (0U)
#define DBG_NQBIRQ_NQBIRQ_WIDTH                  (1U)
#define DBG_NQBIRQ_NQBIRQ(x)                     (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_NQBIRQ_SHIFT)) & DBG_NQBIRQ_NQBIRQ_MASK)

#define DBG_NQBIRQ_QMAN_IRQ_STATUS_MASK          (0x2U)
#define DBG_NQBIRQ_QMAN_IRQ_STATUS_SHIFT         (1U)
#define DBG_NQBIRQ_QMAN_IRQ_STATUS_WIDTH         (1U)
#define DBG_NQBIRQ_QMAN_IRQ_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_QMAN_IRQ_STATUS_SHIFT)) & DBG_NQBIRQ_QMAN_IRQ_STATUS_MASK)

#define DBG_NQBIRQ_QMAN_QFULL_MASK               (0x4U)
#define DBG_NQBIRQ_QMAN_QFULL_SHIFT              (2U)
#define DBG_NQBIRQ_QMAN_QFULL_WIDTH              (1U)
#define DBG_NQBIRQ_QMAN_QFULL(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_QMAN_QFULL_SHIFT)) & DBG_NQBIRQ_QMAN_QFULL_MASK)

#define DBG_NQBIRQ_SNOOP_CSR0_MASK               (0x100U)
#define DBG_NQBIRQ_SNOOP_CSR0_SHIFT              (8U)
#define DBG_NQBIRQ_SNOOP_CSR0_WIDTH              (1U)
#define DBG_NQBIRQ_SNOOP_CSR0(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_SNOOP_CSR0_SHIFT)) & DBG_NQBIRQ_SNOOP_CSR0_MASK)

#define DBG_NQBIRQ_SNOOP_CSR1_MASK               (0x200U)
#define DBG_NQBIRQ_SNOOP_CSR1_SHIFT              (9U)
#define DBG_NQBIRQ_SNOOP_CSR1_WIDTH              (1U)
#define DBG_NQBIRQ_SNOOP_CSR1(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_SNOOP_CSR1_SHIFT)) & DBG_NQBIRQ_SNOOP_CSR1_MASK)
/*! @} */

/*! @name NENSIRQ_M - Normal Error Interrupt Request Mask Register */
/*! @{ */

#define DBG_NENSIRQ_M_NNSE_M_MASK                (0x1U)
#define DBG_NENSIRQ_M_NNSE_M_SHIFT               (0U)
#define DBG_NENSIRQ_M_NNSE_M_WIDTH               (1U)
#define DBG_NENSIRQ_M_NNSE_M(x)                  (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_M_NNSE_M_SHIFT)) & DBG_NENSIRQ_M_NNSE_M_MASK)

#define DBG_NENSIRQ_M_DIV_0_V_M_MASK             (0x2U)
#define DBG_NENSIRQ_M_DIV_0_V_M_SHIFT            (1U)
#define DBG_NENSIRQ_M_DIV_0_V_M_WIDTH            (1U)
#define DBG_NENSIRQ_M_DIV_0_V_M(x)               (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_M_DIV_0_V_M_SHIFT)) & DBG_NENSIRQ_M_DIV_0_V_M_MASK)

#define DBG_NENSIRQ_M_OVRFLW_EXCPTN_M_MASK       (0x4U)
#define DBG_NENSIRQ_M_OVRFLW_EXCPTN_M_SHIFT      (2U)
#define DBG_NENSIRQ_M_OVRFLW_EXCPTN_M_WIDTH      (1U)
#define DBG_NENSIRQ_M_OVRFLW_EXCPTN_M(x)         (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_M_OVRFLW_EXCPTN_M_SHIFT)) & DBG_NENSIRQ_M_OVRFLW_EXCPTN_M_MASK)

#define DBG_NENSIRQ_M_EDAP_R_OOR_M_MASK          (0x4000U)
#define DBG_NENSIRQ_M_EDAP_R_OOR_M_SHIFT         (14U)
#define DBG_NENSIRQ_M_EDAP_R_OOR_M_WIDTH         (1U)
#define DBG_NENSIRQ_M_EDAP_R_OOR_M(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_M_EDAP_R_OOR_M_SHIFT)) & DBG_NENSIRQ_M_EDAP_R_OOR_M_MASK)

#define DBG_NENSIRQ_M_EDAP_W_OOR_M_MASK          (0x8000U)
#define DBG_NENSIRQ_M_EDAP_W_OOR_M_SHIFT         (15U)
#define DBG_NENSIRQ_M_EDAP_W_OOR_M_WIDTH         (1U)
#define DBG_NENSIRQ_M_EDAP_W_OOR_M(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_M_EDAP_W_OOR_M_SHIFT)) & DBG_NENSIRQ_M_EDAP_W_OOR_M_MASK)

#define DBG_NENSIRQ_M_EPP_CF_ERR_M_MASK          (0x40000U)
#define DBG_NENSIRQ_M_EPP_CF_ERR_M_SHIFT         (18U)
#define DBG_NENSIRQ_M_EPP_CF_ERR_M_WIDTH         (1U)
#define DBG_NENSIRQ_M_EPP_CF_ERR_M(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_M_EPP_CF_ERR_M_SHIFT)) & DBG_NENSIRQ_M_EPP_CF_ERR_M_MASK)
/*! @} */

/*! @name TIMER_IRQ_M - Timer Interrupt Mask Register */
/*! @{ */

#define DBG_TIMER_IRQ_M_TIMER0_MASK_MASK         (0x1U)
#define DBG_TIMER_IRQ_M_TIMER0_MASK_SHIFT        (0U)
#define DBG_TIMER_IRQ_M_TIMER0_MASK_WIDTH        (1U)
#define DBG_TIMER_IRQ_M_TIMER0_MASK(x)           (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_M_TIMER0_MASK_SHIFT)) & DBG_TIMER_IRQ_M_TIMER0_MASK_MASK)

#define DBG_TIMER_IRQ_M_TIMER1_MASK_MASK         (0x2U)
#define DBG_TIMER_IRQ_M_TIMER1_MASK_SHIFT        (1U)
#define DBG_TIMER_IRQ_M_TIMER1_MASK_WIDTH        (1U)
#define DBG_TIMER_IRQ_M_TIMER1_MASK(x)           (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_M_TIMER1_MASK_SHIFT)) & DBG_TIMER_IRQ_M_TIMER1_MASK_MASK)

#define DBG_TIMER_IRQ_M_TIMER2_MASK_MASK         (0x4U)
#define DBG_TIMER_IRQ_M_TIMER2_MASK_SHIFT        (2U)
#define DBG_TIMER_IRQ_M_TIMER2_MASK_WIDTH        (1U)
#define DBG_TIMER_IRQ_M_TIMER2_MASK(x)           (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_M_TIMER2_MASK_SHIFT)) & DBG_TIMER_IRQ_M_TIMER2_MASK_MASK)

#define DBG_TIMER_IRQ_M_TIMER3_MASK_MASK         (0x8U)
#define DBG_TIMER_IRQ_M_TIMER3_MASK_SHIFT        (3U)
#define DBG_TIMER_IRQ_M_TIMER3_MASK_WIDTH        (1U)
#define DBG_TIMER_IRQ_M_TIMER3_MASK(x)           (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_M_TIMER3_MASK_SHIFT)) & DBG_TIMER_IRQ_M_TIMER3_MASK_MASK)
/*! @} */

/*! @name NQBIRQ_M - Normal QMAN and Buffers Interrupt Mask Register */
/*! @{ */

#define DBG_NQBIRQ_M_NQBIRQ_M_MASK               (0x1U)
#define DBG_NQBIRQ_M_NQBIRQ_M_SHIFT              (0U)
#define DBG_NQBIRQ_M_NQBIRQ_M_WIDTH              (1U)
#define DBG_NQBIRQ_M_NQBIRQ_M(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_M_NQBIRQ_M_SHIFT)) & DBG_NQBIRQ_M_NQBIRQ_M_MASK)

#define DBG_NQBIRQ_M_QMAN_IRQ_STATUS_M_MASK      (0x2U)
#define DBG_NQBIRQ_M_QMAN_IRQ_STATUS_M_SHIFT     (1U)
#define DBG_NQBIRQ_M_QMAN_IRQ_STATUS_M_WIDTH     (1U)
#define DBG_NQBIRQ_M_QMAN_IRQ_STATUS_M(x)        (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_M_QMAN_IRQ_STATUS_M_SHIFT)) & DBG_NQBIRQ_M_QMAN_IRQ_STATUS_M_MASK)

#define DBG_NQBIRQ_M_QMAN_QFULL_M_MASK           (0x4U)
#define DBG_NQBIRQ_M_QMAN_QFULL_M_SHIFT          (2U)
#define DBG_NQBIRQ_M_QMAN_QFULL_M_WIDTH          (1U)
#define DBG_NQBIRQ_M_QMAN_QFULL_M(x)             (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_M_QMAN_QFULL_M_SHIFT)) & DBG_NQBIRQ_M_QMAN_QFULL_M_MASK)

#define DBG_NQBIRQ_M_SNOOP_CSR0_M_MASK           (0x100U)
#define DBG_NQBIRQ_M_SNOOP_CSR0_M_SHIFT          (8U)
#define DBG_NQBIRQ_M_SNOOP_CSR0_M_WIDTH          (1U)
#define DBG_NQBIRQ_M_SNOOP_CSR0_M(x)             (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_M_SNOOP_CSR0_M_SHIFT)) & DBG_NQBIRQ_M_SNOOP_CSR0_M_MASK)

#define DBG_NQBIRQ_M_SNOOP_CSR1_M_MASK           (0x200U)
#define DBG_NQBIRQ_M_SNOOP_CSR1_M_SHIFT          (9U)
#define DBG_NQBIRQ_M_SNOOP_CSR1_M_WIDTH          (1U)
#define DBG_NQBIRQ_M_SNOOP_CSR1_M(x)             (((uint32_t)(((uint32_t)(x)) << DBG_NQBIRQ_M_SNOOP_CSR1_M_SHIFT)) & DBG_NQBIRQ_M_SNOOP_CSR1_M_MASK)
/*! @} */

/*! @name DBG_STACK_START - Stack Violation Start Address Register */
/*! @{ */

#define DBG_DBG_STACK_START_STK_VIOLTN_START_ADD_MASK (0xFFFFFFFFU)
#define DBG_DBG_STACK_START_STK_VIOLTN_START_ADD_SHIFT (0U)
#define DBG_DBG_STACK_START_STK_VIOLTN_START_ADD_WIDTH (32U)
#define DBG_DBG_STACK_START_STK_VIOLTN_START_ADD(x) (((uint32_t)(((uint32_t)(x)) << DBG_DBG_STACK_START_STK_VIOLTN_START_ADD_SHIFT)) & DBG_DBG_STACK_START_STK_VIOLTN_START_ADD_MASK)
/*! @} */

/*! @name DBG_STACK_END - Stack Violation End Address Register */
/*! @{ */

#define DBG_DBG_STACK_END_STACK_VIOLTN_END_ADD_MASK (0xFFFFFFFFU)
#define DBG_DBG_STACK_END_STACK_VIOLTN_END_ADD_SHIFT (0U)
#define DBG_DBG_STACK_END_STACK_VIOLTN_END_ADD_WIDTH (32U)
#define DBG_DBG_STACK_END_STACK_VIOLTN_END_ADD(x) (((uint32_t)(((uint32_t)(x)) << DBG_DBG_STACK_END_STACK_VIOLTN_END_ADD_SHIFT)) & DBG_DBG_STACK_END_STACK_VIOLTN_END_ADD_MASK)
/*! @} */

/*! @name DBG_DUNMPD_MSK - DBG DMSS Unmapped Access Mask Register */
/*! @{ */

#define DBG_DBG_DUNMPD_MSK_DEXCPTN_UNMAPD_MASK_MASK (0xFFFFFFFFU)
#define DBG_DBG_DUNMPD_MSK_DEXCPTN_UNMAPD_MASK_SHIFT (0U)
#define DBG_DBG_DUNMPD_MSK_DEXCPTN_UNMAPD_MASK_WIDTH (32U)
#define DBG_DBG_DUNMPD_MSK_DEXCPTN_UNMAPD_MASK(x) (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DUNMPD_MSK_DEXCPTN_UNMAPD_MASK_SHIFT)) & DBG_DBG_DUNMPD_MSK_DEXCPTN_UNMAPD_MASK_MASK)
/*! @} */

/*! @name DBG_DUNMPD - DMSS Unmapped Access Status Register */
/*! @{ */

#define DBG_DBG_DUNMPD_DEXCPTN_UNMAPD_MASK       (0xFFFFFFFFU)
#define DBG_DBG_DUNMPD_DEXCPTN_UNMAPD_SHIFT      (0U)
#define DBG_DBG_DUNMPD_DEXCPTN_UNMAPD_WIDTH      (32U)
#define DBG_DBG_DUNMPD_DEXCPTN_UNMAPD(x)         (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DUNMPD_DEXCPTN_UNMAPD_SHIFT)) & DBG_DBG_DUNMPD_DEXCPTN_UNMAPD_MASK)
/*! @} */

/*! @name CENSIRQ_S - Critical Error Interrupt Request Shadow Register */
/*! @{ */

#define DBG_CENSIRQ_S_CNSIPV_S_MASK              (0x2U)
#define DBG_CENSIRQ_S_CNSIPV_S_SHIFT             (1U)
#define DBG_CENSIRQ_S_CNSIPV_S_WIDTH             (1U)
#define DBG_CENSIRQ_S_CNSIPV_S(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_CNSIPV_S_SHIFT)) & DBG_CENSIRQ_S_CNSIPV_S_MASK)

#define DBG_CENSIRQ_S_CNSILOP_S_MASK             (0x4U)
#define DBG_CENSIRQ_S_CNSILOP_S_SHIFT            (2U)
#define DBG_CENSIRQ_S_CNSILOP_S_WIDTH            (1U)
#define DBG_CENSIRQ_S_CNSILOP_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_CNSILOP_S_SHIFT)) & DBG_CENSIRQ_S_CNSILOP_S_MASK)

#define DBG_CENSIRQ_S_CNSIRE_S_MASK              (0x10U)
#define DBG_CENSIRQ_S_CNSIRE_S_SHIFT             (4U)
#define DBG_CENSIRQ_S_CNSIRE_S_WIDTH             (1U)
#define DBG_CENSIRQ_S_CNSIRE_S(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_CNSIRE_S_SHIFT)) & DBG_CENSIRQ_S_CNSIRE_S_MASK)

#define DBG_CENSIRQ_S_IN_PRIV_S_MASK             (0x100U)
#define DBG_CENSIRQ_S_IN_PRIV_S_SHIFT            (8U)
#define DBG_CENSIRQ_S_IN_PRIV_S_WIDTH            (1U)
#define DBG_CENSIRQ_S_IN_PRIV_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_IN_PRIV_S_SHIFT)) & DBG_CENSIRQ_S_IN_PRIV_S_MASK)

#define DBG_CENSIRQ_S_OUT_PRIV_S_MASK            (0x200U)
#define DBG_CENSIRQ_S_OUT_PRIV_S_SHIFT           (9U)
#define DBG_CENSIRQ_S_OUT_PRIV_S_WIDTH           (1U)
#define DBG_CENSIRQ_S_OUT_PRIV_S(x)              (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_OUT_PRIV_S_SHIFT)) & DBG_CENSIRQ_S_OUT_PRIV_S_MASK)

#define DBG_CENSIRQ_S_LD_PRIV_ACC_S_MASK         (0x400U)
#define DBG_CENSIRQ_S_LD_PRIV_ACC_S_SHIFT        (10U)
#define DBG_CENSIRQ_S_LD_PRIV_ACC_S_WIDTH        (1U)
#define DBG_CENSIRQ_S_LD_PRIV_ACC_S(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_LD_PRIV_ACC_S_SHIFT)) & DBG_CENSIRQ_S_LD_PRIV_ACC_S_MASK)

#define DBG_CENSIRQ_S_ST_PRIV_ACC_S_MASK         (0x800U)
#define DBG_CENSIRQ_S_ST_PRIV_ACC_S_SHIFT        (11U)
#define DBG_CENSIRQ_S_ST_PRIV_ACC_S_WIDTH        (1U)
#define DBG_CENSIRQ_S_ST_PRIV_ACC_S(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_ST_PRIV_ACC_S_SHIFT)) & DBG_CENSIRQ_S_ST_PRIV_ACC_S_MASK)

#define DBG_CENSIRQ_S_LD_BLANK_ACC_S_MASK        (0x1000U)
#define DBG_CENSIRQ_S_LD_BLANK_ACC_S_SHIFT       (12U)
#define DBG_CENSIRQ_S_LD_BLANK_ACC_S_WIDTH       (1U)
#define DBG_CENSIRQ_S_LD_BLANK_ACC_S(x)          (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_LD_BLANK_ACC_S_SHIFT)) & DBG_CENSIRQ_S_LD_BLANK_ACC_S_MASK)

#define DBG_CENSIRQ_S_ST_BLANK_ACC_S_MASK        (0x2000U)
#define DBG_CENSIRQ_S_ST_BLANK_ACC_S_SHIFT       (13U)
#define DBG_CENSIRQ_S_ST_BLANK_ACC_S_WIDTH       (1U)
#define DBG_CENSIRQ_S_ST_BLANK_ACC_S(x)          (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_ST_BLANK_ACC_S_SHIFT)) & DBG_CENSIRQ_S_ST_BLANK_ACC_S_MASK)

#define DBG_CENSIRQ_S_LD_RG_CROS_S_MASK          (0x4000U)
#define DBG_CENSIRQ_S_LD_RG_CROS_S_SHIFT         (14U)
#define DBG_CENSIRQ_S_LD_RG_CROS_S_WIDTH         (1U)
#define DBG_CENSIRQ_S_LD_RG_CROS_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_LD_RG_CROS_S_SHIFT)) & DBG_CENSIRQ_S_LD_RG_CROS_S_MASK)

#define DBG_CENSIRQ_S_ST_RG_CROS_S_MASK          (0x8000U)
#define DBG_CENSIRQ_S_ST_RG_CROS_S_SHIFT         (15U)
#define DBG_CENSIRQ_S_ST_RG_CROS_S_WIDTH         (1U)
#define DBG_CENSIRQ_S_ST_RG_CROS_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_ST_RG_CROS_S_SHIFT)) & DBG_CENSIRQ_S_ST_RG_CROS_S_MASK)

#define DBG_CENSIRQ_S_STACK_VIOL_EXCPTN_S_MASK   (0x20000U)
#define DBG_CENSIRQ_S_STACK_VIOL_EXCPTN_S_SHIFT  (17U)
#define DBG_CENSIRQ_S_STACK_VIOL_EXCPTN_S_WIDTH  (1U)
#define DBG_CENSIRQ_S_STACK_VIOL_EXCPTN_S(x)     (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_STACK_VIOL_EXCPTN_S_SHIFT)) & DBG_CENSIRQ_S_STACK_VIOL_EXCPTN_S_MASK)

#define DBG_CENSIRQ_S_EXC_E_S_MASK               (0x40000U)
#define DBG_CENSIRQ_S_EXC_E_S_SHIFT              (18U)
#define DBG_CENSIRQ_S_EXC_E_S_WIDTH              (1U)
#define DBG_CENSIRQ_S_EXC_E_S(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_EXC_E_S_SHIFT)) & DBG_CENSIRQ_S_EXC_E_S_MASK)

#define DBG_CENSIRQ_S_ER_EXOK_S_MASK             (0x80000U)
#define DBG_CENSIRQ_S_ER_EXOK_S_SHIFT            (19U)
#define DBG_CENSIRQ_S_ER_EXOK_S_WIDTH            (1U)
#define DBG_CENSIRQ_S_ER_EXOK_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_ER_EXOK_S_SHIFT)) & DBG_CENSIRQ_S_ER_EXOK_S_MASK)

#define DBG_CENSIRQ_S_LD_IDM_CROS_S_MASK         (0x100000U)
#define DBG_CENSIRQ_S_LD_IDM_CROS_S_SHIFT        (20U)
#define DBG_CENSIRQ_S_LD_IDM_CROS_S_WIDTH        (1U)
#define DBG_CENSIRQ_S_LD_IDM_CROS_S(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_LD_IDM_CROS_S_SHIFT)) & DBG_CENSIRQ_S_LD_IDM_CROS_S_MASK)

#define DBG_CENSIRQ_S_ST_IDM_CROS_S_MASK         (0x200000U)
#define DBG_CENSIRQ_S_ST_IDM_CROS_S_SHIFT        (21U)
#define DBG_CENSIRQ_S_ST_IDM_CROS_S_WIDTH        (1U)
#define DBG_CENSIRQ_S_ST_IDM_CROS_S(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_ST_IDM_CROS_S_SHIFT)) & DBG_CENSIRQ_S_ST_IDM_CROS_S_MASK)

#define DBG_CENSIRQ_S_VLD_ADR_ERR_S_MASK         (0x400000U)
#define DBG_CENSIRQ_S_VLD_ADR_ERR_S_SHIFT        (22U)
#define DBG_CENSIRQ_S_VLD_ADR_ERR_S_WIDTH        (1U)
#define DBG_CENSIRQ_S_VLD_ADR_ERR_S(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_VLD_ADR_ERR_S_SHIFT)) & DBG_CENSIRQ_S_VLD_ADR_ERR_S_MASK)

#define DBG_CENSIRQ_S_VST_ADR_ERR_S_MASK         (0x800000U)
#define DBG_CENSIRQ_S_VST_ADR_ERR_S_SHIFT        (23U)
#define DBG_CENSIRQ_S_VST_ADR_ERR_S_WIDTH        (1U)
#define DBG_CENSIRQ_S_VST_ADR_ERR_S(x)           (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_VST_ADR_ERR_S_SHIFT)) & DBG_CENSIRQ_S_VST_ADR_ERR_S_MASK)

#define DBG_CENSIRQ_S_HIST_IDM_CROS_S_MASK       (0x1000000U)
#define DBG_CENSIRQ_S_HIST_IDM_CROS_S_SHIFT      (24U)
#define DBG_CENSIRQ_S_HIST_IDM_CROS_S_WIDTH      (1U)
#define DBG_CENSIRQ_S_HIST_IDM_CROS_S(x)         (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ_S_HIST_IDM_CROS_S_SHIFT)) & DBG_CENSIRQ_S_HIST_IDM_CROS_S_MASK)
/*! @} */

/*! @name CENSIRQ2_S - Critical Error Interrupt Request 2 Shadow Register */
/*! @{ */

#define DBG_CENSIRQ2_S_DDMA_RG_CROS_S_MASK       (0x80U)
#define DBG_CENSIRQ2_S_DDMA_RG_CROS_S_SHIFT      (7U)
#define DBG_CENSIRQ2_S_DDMA_RG_CROS_S_WIDTH      (1U)
#define DBG_CENSIRQ2_S_DDMA_RG_CROS_S(x)         (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_S_DDMA_RG_CROS_S_SHIFT)) & DBG_CENSIRQ2_S_DDMA_RG_CROS_S_MASK)

#define DBG_CENSIRQ2_S_DDMA_IDM_CROS_S_MASK      (0x100U)
#define DBG_CENSIRQ2_S_DDMA_IDM_CROS_S_SHIFT     (8U)
#define DBG_CENSIRQ2_S_DDMA_IDM_CROS_S_WIDTH     (1U)
#define DBG_CENSIRQ2_S_DDMA_IDM_CROS_S(x)        (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_S_DDMA_IDM_CROS_S_SHIFT)) & DBG_CENSIRQ2_S_DDMA_IDM_CROS_S_MASK)

#define DBG_CENSIRQ2_S_ER_IOP_S_MASK             (0x400U)
#define DBG_CENSIRQ2_S_ER_IOP_S_SHIFT            (10U)
#define DBG_CENSIRQ2_S_ER_IOP_S_WIDTH            (1U)
#define DBG_CENSIRQ2_S_ER_IOP_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_S_ER_IOP_S_SHIFT)) & DBG_CENSIRQ2_S_ER_IOP_S_MASK)

#define DBG_CENSIRQ2_S_ER_EPP_S_MASK             (0x800U)
#define DBG_CENSIRQ2_S_ER_EPP_S_SHIFT            (11U)
#define DBG_CENSIRQ2_S_ER_EPP_S_WIDTH            (1U)
#define DBG_CENSIRQ2_S_ER_EPP_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_S_ER_EPP_S_SHIFT)) & DBG_CENSIRQ2_S_ER_EPP_S_MASK)

#define DBG_CENSIRQ2_S_ER_EDP_S_MASK             (0x1000U)
#define DBG_CENSIRQ2_S_ER_EDP_S_SHIFT            (12U)
#define DBG_CENSIRQ2_S_ER_EDP_S_WIDTH            (1U)
#define DBG_CENSIRQ2_S_ER_EDP_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_CENSIRQ2_S_ER_EDP_S_SHIFT)) & DBG_CENSIRQ2_S_ER_EDP_S_MASK)
/*! @} */

/*! @name CWDOGIRQ_S - Critical Error Interrupt Request Shadow Register */
/*! @{ */

#define DBG_CWDOGIRQ_S_WDOG_MAX_S_MASK           (0x10000U)
#define DBG_CWDOGIRQ_S_WDOG_MAX_S_SHIFT          (16U)
#define DBG_CWDOGIRQ_S_WDOG_MAX_S_WIDTH          (1U)
#define DBG_CWDOGIRQ_S_WDOG_MAX_S(x)             (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_S_WDOG_MAX_S_SHIFT)) & DBG_CWDOGIRQ_S_WDOG_MAX_S_MASK)

#define DBG_CWDOGIRQ_S_WDOG_MIN_S_MASK           (0x20000U)
#define DBG_CWDOGIRQ_S_WDOG_MIN_S_SHIFT          (17U)
#define DBG_CWDOGIRQ_S_WDOG_MIN_S_WIDTH          (1U)
#define DBG_CWDOGIRQ_S_WDOG_MIN_S(x)             (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_S_WDOG_MIN_S_SHIFT)) & DBG_CWDOGIRQ_S_WDOG_MIN_S_MASK)

#define DBG_CWDOGIRQ_S_ICUWD_S_MASK              (0x100000U)
#define DBG_CWDOGIRQ_S_ICUWD_S_SHIFT             (20U)
#define DBG_CWDOGIRQ_S_ICUWD_S_WIDTH             (1U)
#define DBG_CWDOGIRQ_S_ICUWD_S(x)                (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_S_ICUWD_S_SHIFT)) & DBG_CWDOGIRQ_S_ICUWD_S_MASK)

#define DBG_CWDOGIRQ_S_IOPWDOG_V_S_MASK          (0x20000000U)
#define DBG_CWDOGIRQ_S_IOPWDOG_V_S_SHIFT         (29U)
#define DBG_CWDOGIRQ_S_IOPWDOG_V_S_WIDTH         (1U)
#define DBG_CWDOGIRQ_S_IOPWDOG_V_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_S_IOPWDOG_V_S_SHIFT)) & DBG_CWDOGIRQ_S_IOPWDOG_V_S_MASK)

#define DBG_CWDOGIRQ_S_EDPWDOG_V_S_MASK          (0x40000000U)
#define DBG_CWDOGIRQ_S_EDPWDOG_V_S_SHIFT         (30U)
#define DBG_CWDOGIRQ_S_EDPWDOG_V_S_WIDTH         (1U)
#define DBG_CWDOGIRQ_S_EDPWDOG_V_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_S_EDPWDOG_V_S_SHIFT)) & DBG_CWDOGIRQ_S_EDPWDOG_V_S_MASK)

#define DBG_CWDOGIRQ_S_EPPWDOG_V_S_MASK          (0x80000000U)
#define DBG_CWDOGIRQ_S_EPPWDOG_V_S_SHIFT         (31U)
#define DBG_CWDOGIRQ_S_EPPWDOG_V_S_WIDTH         (1U)
#define DBG_CWDOGIRQ_S_EPPWDOG_V_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_CWDOGIRQ_S_EPPWDOG_V_S_SHIFT)) & DBG_CWDOGIRQ_S_EPPWDOG_V_S_MASK)
/*! @} */

/*! @name NENSIRQ_S - Normal Error Interrupt Requests Shadow Register */
/*! @{ */

#define DBG_NENSIRQ_S_DIV_0_V_S_MASK             (0x2U)
#define DBG_NENSIRQ_S_DIV_0_V_S_SHIFT            (1U)
#define DBG_NENSIRQ_S_DIV_0_V_S_WIDTH            (1U)
#define DBG_NENSIRQ_S_DIV_0_V_S(x)               (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_S_DIV_0_V_S_SHIFT)) & DBG_NENSIRQ_S_DIV_0_V_S_MASK)

#define DBG_NENSIRQ_S_OVRFLW_EXCPTN_S_MASK       (0x4U)
#define DBG_NENSIRQ_S_OVRFLW_EXCPTN_S_SHIFT      (2U)
#define DBG_NENSIRQ_S_OVRFLW_EXCPTN_S_WIDTH      (1U)
#define DBG_NENSIRQ_S_OVRFLW_EXCPTN_S(x)         (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_S_OVRFLW_EXCPTN_S_SHIFT)) & DBG_NENSIRQ_S_OVRFLW_EXCPTN_S_MASK)

#define DBG_NENSIRQ_S_EDAP_R_OOR_S_MASK          (0x4000U)
#define DBG_NENSIRQ_S_EDAP_R_OOR_S_SHIFT         (14U)
#define DBG_NENSIRQ_S_EDAP_R_OOR_S_WIDTH         (1U)
#define DBG_NENSIRQ_S_EDAP_R_OOR_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_S_EDAP_R_OOR_S_SHIFT)) & DBG_NENSIRQ_S_EDAP_R_OOR_S_MASK)

#define DBG_NENSIRQ_S_EDAP_W_OOR_S_MASK          (0x8000U)
#define DBG_NENSIRQ_S_EDAP_W_OOR_S_SHIFT         (15U)
#define DBG_NENSIRQ_S_EDAP_W_OOR_S_WIDTH         (1U)
#define DBG_NENSIRQ_S_EDAP_W_OOR_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_S_EDAP_W_OOR_S_SHIFT)) & DBG_NENSIRQ_S_EDAP_W_OOR_S_MASK)

#define DBG_NENSIRQ_S_EPP_CF_ERR_S_MASK          (0x40000U)
#define DBG_NENSIRQ_S_EPP_CF_ERR_S_SHIFT         (18U)
#define DBG_NENSIRQ_S_EPP_CF_ERR_S_WIDTH         (1U)
#define DBG_NENSIRQ_S_EPP_CF_ERR_S(x)            (((uint32_t)(((uint32_t)(x)) << DBG_NENSIRQ_S_EPP_CF_ERR_S_SHIFT)) & DBG_NENSIRQ_S_EPP_CF_ERR_S_MASK)
/*! @} */

/*! @name TIMER_IRQ_S - Timer Interrupt Shadow Register */
/*! @{ */

#define DBG_TIMER_IRQ_S_TIMER0_IRQ_S_MASK        (0x1U)
#define DBG_TIMER_IRQ_S_TIMER0_IRQ_S_SHIFT       (0U)
#define DBG_TIMER_IRQ_S_TIMER0_IRQ_S_WIDTH       (1U)
#define DBG_TIMER_IRQ_S_TIMER0_IRQ_S(x)          (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_S_TIMER0_IRQ_S_SHIFT)) & DBG_TIMER_IRQ_S_TIMER0_IRQ_S_MASK)

#define DBG_TIMER_IRQ_S_TIMER1_IRQ_S_MASK        (0x2U)
#define DBG_TIMER_IRQ_S_TIMER1_IRQ_S_SHIFT       (1U)
#define DBG_TIMER_IRQ_S_TIMER1_IRQ_S_WIDTH       (1U)
#define DBG_TIMER_IRQ_S_TIMER1_IRQ_S(x)          (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_S_TIMER1_IRQ_S_SHIFT)) & DBG_TIMER_IRQ_S_TIMER1_IRQ_S_MASK)

#define DBG_TIMER_IRQ_S_TIMER2_IRQ_S_MASK        (0x4U)
#define DBG_TIMER_IRQ_S_TIMER2_IRQ_S_SHIFT       (2U)
#define DBG_TIMER_IRQ_S_TIMER2_IRQ_S_WIDTH       (1U)
#define DBG_TIMER_IRQ_S_TIMER2_IRQ_S(x)          (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_S_TIMER2_IRQ_S_SHIFT)) & DBG_TIMER_IRQ_S_TIMER2_IRQ_S_MASK)

#define DBG_TIMER_IRQ_S_TIMER3_IRQ_S_MASK        (0x8U)
#define DBG_TIMER_IRQ_S_TIMER3_IRQ_S_SHIFT       (3U)
#define DBG_TIMER_IRQ_S_TIMER3_IRQ_S_WIDTH       (1U)
#define DBG_TIMER_IRQ_S_TIMER3_IRQ_S(x)          (((uint32_t)(((uint32_t)(x)) << DBG_TIMER_IRQ_S_TIMER3_IRQ_S_SHIFT)) & DBG_TIMER_IRQ_S_TIMER3_IRQ_S_MASK)
/*! @} */

/*! @name DMA_IRQ_S - DMA Interrupt Shadow Register */
/*! @{ */

#define DBG_DMA_IRQ_S_DDMA_IRQ_S_MASK            (0x1U)
#define DBG_DMA_IRQ_S_DDMA_IRQ_S_SHIFT           (0U)
#define DBG_DMA_IRQ_S_DDMA_IRQ_S_WIDTH           (1U)
#define DBG_DMA_IRQ_S_DDMA_IRQ_S(x)              (((uint32_t)(((uint32_t)(x)) << DBG_DMA_IRQ_S_DDMA_IRQ_S_SHIFT)) & DBG_DMA_IRQ_S_DDMA_IRQ_S_MASK)

#define DBG_DMA_IRQ_S_PDMA_IRQ_S_MASK            (0x2U)
#define DBG_DMA_IRQ_S_PDMA_IRQ_S_SHIFT           (1U)
#define DBG_DMA_IRQ_S_PDMA_IRQ_S_WIDTH           (1U)
#define DBG_DMA_IRQ_S_PDMA_IRQ_S(x)              (((uint32_t)(((uint32_t)(x)) << DBG_DMA_IRQ_S_PDMA_IRQ_S_SHIFT)) & DBG_DMA_IRQ_S_PDMA_IRQ_S_MASK)
/*! @} */

/*! @name DBG_DESC_ID - DBG DESC ID Register */
/*! @{ */

#define DBG_DBG_DESC_ID_Q0_BLANK_ACC_MASK        (0x1U)
#define DBG_DBG_DESC_ID_Q0_BLANK_ACC_SHIFT       (0U)
#define DBG_DBG_DESC_ID_Q0_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_DESC_ID_Q0_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DESC_ID_Q0_BLANK_ACC_SHIFT)) & DBG_DBG_DESC_ID_Q0_BLANK_ACC_MASK)

#define DBG_DBG_DESC_ID_Q1_BLANK_ACC_MASK        (0x2U)
#define DBG_DBG_DESC_ID_Q1_BLANK_ACC_SHIFT       (1U)
#define DBG_DBG_DESC_ID_Q1_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_DESC_ID_Q1_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DESC_ID_Q1_BLANK_ACC_SHIFT)) & DBG_DBG_DESC_ID_Q1_BLANK_ACC_MASK)

#define DBG_DBG_DESC_ID_Q2_BLANK_ACC_MASK        (0x4U)
#define DBG_DBG_DESC_ID_Q2_BLANK_ACC_SHIFT       (2U)
#define DBG_DBG_DESC_ID_Q2_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_DESC_ID_Q2_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DESC_ID_Q2_BLANK_ACC_SHIFT)) & DBG_DBG_DESC_ID_Q2_BLANK_ACC_MASK)

#define DBG_DBG_DESC_ID_Q3_BLANK_ACC_MASK        (0x8U)
#define DBG_DBG_DESC_ID_Q3_BLANK_ACC_SHIFT       (3U)
#define DBG_DBG_DESC_ID_Q3_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_DESC_ID_Q3_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DESC_ID_Q3_BLANK_ACC_SHIFT)) & DBG_DBG_DESC_ID_Q3_BLANK_ACC_MASK)

#define DBG_DBG_DESC_ID_MSTR_BLANK_ACC_MASK      (0x10000U)
#define DBG_DBG_DESC_ID_MSTR_BLANK_ACC_SHIFT     (16U)
#define DBG_DBG_DESC_ID_MSTR_BLANK_ACC_WIDTH     (1U)
#define DBG_DBG_DESC_ID_MSTR_BLANK_ACC(x)        (((uint32_t)(((uint32_t)(x)) << DBG_DBG_DESC_ID_MSTR_BLANK_ACC_SHIFT)) & DBG_DBG_DESC_ID_MSTR_BLANK_ACC_MASK)
/*! @} */

/*! @name DBG_QMAN_ID - DBG QMAN ID Register */
/*! @{ */

#define DBG_DBG_QMAN_ID_Q0_BLANK_ACC_MASK        (0x1U)
#define DBG_DBG_QMAN_ID_Q0_BLANK_ACC_SHIFT       (0U)
#define DBG_DBG_QMAN_ID_Q0_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_QMAN_ID_Q0_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_QMAN_ID_Q0_BLANK_ACC_SHIFT)) & DBG_DBG_QMAN_ID_Q0_BLANK_ACC_MASK)

#define DBG_DBG_QMAN_ID_Q1_BLANK_ACC_MASK        (0x2U)
#define DBG_DBG_QMAN_ID_Q1_BLANK_ACC_SHIFT       (1U)
#define DBG_DBG_QMAN_ID_Q1_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_QMAN_ID_Q1_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_QMAN_ID_Q1_BLANK_ACC_SHIFT)) & DBG_DBG_QMAN_ID_Q1_BLANK_ACC_MASK)

#define DBG_DBG_QMAN_ID_Q2_BLANK_ACC_MASK        (0x4U)
#define DBG_DBG_QMAN_ID_Q2_BLANK_ACC_SHIFT       (2U)
#define DBG_DBG_QMAN_ID_Q2_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_QMAN_ID_Q2_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_QMAN_ID_Q2_BLANK_ACC_SHIFT)) & DBG_DBG_QMAN_ID_Q2_BLANK_ACC_MASK)

#define DBG_DBG_QMAN_ID_Q3_BLANK_ACC_MASK        (0x8U)
#define DBG_DBG_QMAN_ID_Q3_BLANK_ACC_SHIFT       (3U)
#define DBG_DBG_QMAN_ID_Q3_BLANK_ACC_WIDTH       (1U)
#define DBG_DBG_QMAN_ID_Q3_BLANK_ACC(x)          (((uint32_t)(((uint32_t)(x)) << DBG_DBG_QMAN_ID_Q3_BLANK_ACC_SHIFT)) & DBG_DBG_QMAN_ID_Q3_BLANK_ACC_MASK)
/*! @} */

/*! @name XCI_COR - MSS Acknowledge Control Register */
/*! @{ */

#define DBG_XCI_COR_INT_COUNT_MASK               (0xFU)
#define DBG_XCI_COR_INT_COUNT_SHIFT              (0U)
#define DBG_XCI_COR_INT_COUNT_WIDTH              (4U)
#define DBG_XCI_COR_INT_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << DBG_XCI_COR_INT_COUNT_SHIFT)) & DBG_XCI_COR_INT_COUNT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DBG_Register_Masks */

/*!
 * @}
 */ /* end of group DBG_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DBG_H_) */
