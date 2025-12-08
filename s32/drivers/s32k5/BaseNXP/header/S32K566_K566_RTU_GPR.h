/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_K566_RTU_GPR.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_K566_RTU_GPR
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
#if !defined(S32K566_K566_RTU_GPR_H_)  /* Check if memory map has not been already included */
#define S32K566_K566_RTU_GPR_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- K566_RTU_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup K566_RTU_GPR_Peripheral_Access_Layer K566_RTU_GPR Peripheral Access Layer
 * @{
 */

/** K566_RTU_GPR - Register Layout Typedef */
typedef struct K566_RTU_GPR_Struct {
  __IO uint32_t R52_CLUSTER0;                      /**< R52 Cluster0 Configuration, offset: 0x0 */
  __IO uint32_t FD_EN;                             /**< Fence And Drain Enable, offset: 0x4 */
  __IO uint32_t CR52_CNT_DIV;                      /**< Generic Timer Counter Divider Control, offset: 0x8 */
  __IO uint32_t CR52_HALT;                         /**< Core Halt Control, offset: 0xC */
  __I  uint32_t STAT_FD;                           /**< Fence And Drain Status, offset: 0x10 */
  __I  uint32_t GASKET_IDLE_STAT;                  /**< Gasket Idle Status, offset: 0x14 */
  __I  uint32_t CR52_STANDBYWFI;                   /**< R52 Standby Wait For Interrupt (WFI) Status, offset: 0x18 */
  __I  uint32_t CR52_STANDBYWFE;                   /**< R52 Standby Wait For Event (WFE) Status, offset: 0x1C */
  __I  uint32_t CR52_RESETREQ;                     /**< R52 Reset Request, offset: 0x20 */
  __IO uint32_t PMCMBISTDIS;                       /**< Programmable MBIST Controller (PMC) Disable, offset: 0x24 */
  __IO uint32_t MBUSPARDIS;                        /**< Bus Parity Error Disable Group 0, offset: 0x28 */
  __IO uint32_t NBUSPARDIS;                        /**< Bus Parity Error Disable Group 1, offset: 0x2C */
  uint8_t RESERVED_0[36];
  __IO uint32_t R52_CORE_0_SW_FAULT;               /**< Software Fault Control 0, offset: 0x54 */
  __IO uint32_t R52_CORE_1_SW_FAULT;               /**< Software Fault Control 1, offset: 0x58 */
  uint8_t RESERVED_1[56];
  __IO uint32_t PLL_PD_RGM_REQ;                    /**< PLL Power Down Request, offset: 0x94 */
  __I  uint32_t PLL_PD_RGM_ACK;                    /**< PLL Power Down Acknowledgement, offset: 0x98 */
  uint8_t RESERVED_2[8];
  __IO uint32_t R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION; /**< R52_PMC TO CPE_PERIPH_BRIDGE Isolation, offset: 0xA4 */
} K566_RTU_GPR_Type, *K566_RTU_GPR_MemMapPtr;

/** Number of instances of the K566_RTU_GPR module. */
#define K566_RTU_GPR_INSTANCE_COUNT              (1u)

/* K566_RTU_GPR - Peripheral instance base addresses */
/** Peripheral CPE_GPR base address */
#define IP_CPE_GPR_BASE                          (0x41004000u)
/** Peripheral CPE_GPR base pointer */
#define IP_CPE_GPR                               ((K566_RTU_GPR_Type *)IP_CPE_GPR_BASE)
/** Array initializer of K566_RTU_GPR peripheral base addresses */
#define IP_K566_RTU_GPR_BASE_ADDRS               { IP_CPE_GPR_BASE }
/** Array initializer of K566_RTU_GPR peripheral base pointers */
#define IP_K566_RTU_GPR_BASE_PTRS                { IP_CPE_GPR }

/* ----------------------------------------------------------------------------
   -- K566_RTU_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup K566_RTU_GPR_Register_Masks K566_RTU_GPR Register Masks
 * @{
 */

/*! @name R52_CLUSTER0 - R52 Cluster0 Configuration */
/*! @{ */

#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT0_MASK  (0x1U)
#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT0_SHIFT (0U)
#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT0_WIDTH (1U)
#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT0(x)    (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_TCMBOOT0_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_TCMBOOT0_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT1_MASK  (0x2U)
#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT1_SHIFT (1U)
#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT1_WIDTH (1U)
#define K566_RTU_GPR_R52_CLUSTER0_TCMBOOT1(x)    (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_TCMBOOT1_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_TCMBOOT1_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_THUMB0_MASK    (0x4U)
#define K566_RTU_GPR_R52_CLUSTER0_THUMB0_SHIFT   (2U)
#define K566_RTU_GPR_R52_CLUSTER0_THUMB0_WIDTH   (1U)
#define K566_RTU_GPR_R52_CLUSTER0_THUMB0(x)      (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_THUMB0_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_THUMB0_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_THUMB1_MASK    (0x8U)
#define K566_RTU_GPR_R52_CLUSTER0_THUMB1_SHIFT   (3U)
#define K566_RTU_GPR_R52_CLUSTER0_THUMB1_WIDTH   (1U)
#define K566_RTU_GPR_R52_CLUSTER0_THUMB1(x)      (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_THUMB1_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_THUMB1_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_CAINV0_MASK    (0x10U)
#define K566_RTU_GPR_R52_CLUSTER0_CAINV0_SHIFT   (4U)
#define K566_RTU_GPR_R52_CLUSTER0_CAINV0_WIDTH   (1U)
#define K566_RTU_GPR_R52_CLUSTER0_CAINV0(x)      (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_CAINV0_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_CAINV0_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_CAINV1_MASK    (0x20U)
#define K566_RTU_GPR_R52_CLUSTER0_CAINV1_SHIFT   (5U)
#define K566_RTU_GPR_R52_CLUSTER0_CAINV1_WIDTH   (1U)
#define K566_RTU_GPR_R52_CLUSTER0_CAINV1(x)      (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_CAINV1_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_CAINV1_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_INITREG_MASK   (0x40U)
#define K566_RTU_GPR_R52_CLUSTER0_INITREG_SHIFT  (6U)
#define K566_RTU_GPR_R52_CLUSTER0_INITREG_WIDTH  (1U)
#define K566_RTU_GPR_R52_CLUSTER0_INITREG(x)     (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_INITREG_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_INITREG_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS0_MASK (0x80U)
#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS0_SHIFT (7U)
#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS0_WIDTH (1U)
#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS0(x)  (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_ENDIANESS0_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_ENDIANESS0_MASK)

#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS1_MASK (0x100U)
#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS1_SHIFT (8U)
#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS1_WIDTH (1U)
#define K566_RTU_GPR_R52_CLUSTER0_ENDIANESS1(x)  (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CLUSTER0_ENDIANESS1_SHIFT)) & K566_RTU_GPR_R52_CLUSTER0_ENDIANESS1_MASK)
/*! @} */

/*! @name FD_EN - Fence And Drain Enable */
/*! @{ */

#define K566_RTU_GPR_FD_EN_MFDEN0_MASK           (0x1U)
#define K566_RTU_GPR_FD_EN_MFDEN0_SHIFT          (0U)
#define K566_RTU_GPR_FD_EN_MFDEN0_WIDTH          (1U)
#define K566_RTU_GPR_FD_EN_MFDEN0(x)             (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_MFDEN0_SHIFT)) & K566_RTU_GPR_FD_EN_MFDEN0_MASK)

#define K566_RTU_GPR_FD_EN_MFDEN1_MASK           (0x2U)
#define K566_RTU_GPR_FD_EN_MFDEN1_SHIFT          (1U)
#define K566_RTU_GPR_FD_EN_MFDEN1_WIDTH          (1U)
#define K566_RTU_GPR_FD_EN_MFDEN1(x)             (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_MFDEN1_SHIFT)) & K566_RTU_GPR_FD_EN_MFDEN1_MASK)

#define K566_RTU_GPR_FD_EN_LFDEN0_MASK           (0x4U)
#define K566_RTU_GPR_FD_EN_LFDEN0_SHIFT          (2U)
#define K566_RTU_GPR_FD_EN_LFDEN0_WIDTH          (1U)
#define K566_RTU_GPR_FD_EN_LFDEN0(x)             (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_LFDEN0_SHIFT)) & K566_RTU_GPR_FD_EN_LFDEN0_MASK)

#define K566_RTU_GPR_FD_EN_LFDEN1_MASK           (0x8U)
#define K566_RTU_GPR_FD_EN_LFDEN1_SHIFT          (3U)
#define K566_RTU_GPR_FD_EN_LFDEN1_WIDTH          (1U)
#define K566_RTU_GPR_FD_EN_LFDEN1(x)             (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_LFDEN1_SHIFT)) & K566_RTU_GPR_FD_EN_LFDEN1_MASK)

#define K566_RTU_GPR_FD_EN_SFDEN_MASK            (0x10U)
#define K566_RTU_GPR_FD_EN_SFDEN_SHIFT           (4U)
#define K566_RTU_GPR_FD_EN_SFDEN_WIDTH           (1U)
#define K566_RTU_GPR_FD_EN_SFDEN(x)              (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_SFDEN_SHIFT)) & K566_RTU_GPR_FD_EN_SFDEN_MASK)

#define K566_RTU_GPR_FD_EN_ISOLEN0_MASK          (0x20U)
#define K566_RTU_GPR_FD_EN_ISOLEN0_SHIFT         (5U)
#define K566_RTU_GPR_FD_EN_ISOLEN0_WIDTH         (1U)
#define K566_RTU_GPR_FD_EN_ISOLEN0(x)            (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_ISOLEN0_SHIFT)) & K566_RTU_GPR_FD_EN_ISOLEN0_MASK)

#define K566_RTU_GPR_FD_EN_ISOLEN1_MASK          (0x40U)
#define K566_RTU_GPR_FD_EN_ISOLEN1_SHIFT         (6U)
#define K566_RTU_GPR_FD_EN_ISOLEN1_WIDTH         (1U)
#define K566_RTU_GPR_FD_EN_ISOLEN1(x)            (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_FD_EN_ISOLEN1_SHIFT)) & K566_RTU_GPR_FD_EN_ISOLEN1_MASK)
/*! @} */

/*! @name CR52_CNT_DIV - Generic Timer Counter Divider Control */
/*! @{ */

#define K566_RTU_GPR_CR52_CNT_DIV_CNTDV_MASK     (0x7U)
#define K566_RTU_GPR_CR52_CNT_DIV_CNTDV_SHIFT    (0U)
#define K566_RTU_GPR_CR52_CNT_DIV_CNTDV_WIDTH    (3U)
#define K566_RTU_GPR_CR52_CNT_DIV_CNTDV(x)       (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_CNT_DIV_CNTDV_SHIFT)) & K566_RTU_GPR_CR52_CNT_DIV_CNTDV_MASK)
/*! @} */

/*! @name CR52_HALT - Core Halt Control */
/*! @{ */

#define K566_RTU_GPR_CR52_HALT_HALT0_MASK        (0x1U)
#define K566_RTU_GPR_CR52_HALT_HALT0_SHIFT       (0U)
#define K566_RTU_GPR_CR52_HALT_HALT0_WIDTH       (1U)
#define K566_RTU_GPR_CR52_HALT_HALT0(x)          (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_HALT_HALT0_SHIFT)) & K566_RTU_GPR_CR52_HALT_HALT0_MASK)

#define K566_RTU_GPR_CR52_HALT_HALT1_MASK        (0x2U)
#define K566_RTU_GPR_CR52_HALT_HALT1_SHIFT       (1U)
#define K566_RTU_GPR_CR52_HALT_HALT1_WIDTH       (1U)
#define K566_RTU_GPR_CR52_HALT_HALT1(x)          (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_HALT_HALT1_SHIFT)) & K566_RTU_GPR_CR52_HALT_HALT1_MASK)
/*! @} */

/*! @name STAT_FD - Fence And Drain Status */
/*! @{ */

#define K566_RTU_GPR_STAT_FD_MFDID0_MASK         (0x1U)
#define K566_RTU_GPR_STAT_FD_MFDID0_SHIFT        (0U)
#define K566_RTU_GPR_STAT_FD_MFDID0_WIDTH        (1U)
#define K566_RTU_GPR_STAT_FD_MFDID0(x)           (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_STAT_FD_MFDID0_SHIFT)) & K566_RTU_GPR_STAT_FD_MFDID0_MASK)

#define K566_RTU_GPR_STAT_FD_MFDID1_MASK         (0x2U)
#define K566_RTU_GPR_STAT_FD_MFDID1_SHIFT        (1U)
#define K566_RTU_GPR_STAT_FD_MFDID1_WIDTH        (1U)
#define K566_RTU_GPR_STAT_FD_MFDID1(x)           (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_STAT_FD_MFDID1_SHIFT)) & K566_RTU_GPR_STAT_FD_MFDID1_MASK)

#define K566_RTU_GPR_STAT_FD_LFDID0_MASK         (0x4U)
#define K566_RTU_GPR_STAT_FD_LFDID0_SHIFT        (2U)
#define K566_RTU_GPR_STAT_FD_LFDID0_WIDTH        (1U)
#define K566_RTU_GPR_STAT_FD_LFDID0(x)           (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_STAT_FD_LFDID0_SHIFT)) & K566_RTU_GPR_STAT_FD_LFDID0_MASK)

#define K566_RTU_GPR_STAT_FD_LFDID1_MASK         (0x8U)
#define K566_RTU_GPR_STAT_FD_LFDID1_SHIFT        (3U)
#define K566_RTU_GPR_STAT_FD_LFDID1_WIDTH        (1U)
#define K566_RTU_GPR_STAT_FD_LFDID1(x)           (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_STAT_FD_LFDID1_SHIFT)) & K566_RTU_GPR_STAT_FD_LFDID1_MASK)

#define K566_RTU_GPR_STAT_FD_SFDID1_MASK         (0x10U)
#define K566_RTU_GPR_STAT_FD_SFDID1_SHIFT        (4U)
#define K566_RTU_GPR_STAT_FD_SFDID1_WIDTH        (1U)
#define K566_RTU_GPR_STAT_FD_SFDID1(x)           (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_STAT_FD_SFDID1_SHIFT)) & K566_RTU_GPR_STAT_FD_SFDID1_MASK)
/*! @} */

/*! @name GASKET_IDLE_STAT - Gasket Idle Status */
/*! @{ */

#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_0_MASK (0x1U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_0_SHIFT (0U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_0_WIDTH (1U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_0(x)  (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_GASKET_IDLE_STAT_STAT_0_SHIFT)) & K566_RTU_GPR_GASKET_IDLE_STAT_STAT_0_MASK)

#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_1_MASK (0x2U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_1_SHIFT (1U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_1_WIDTH (1U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_1(x)  (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_GASKET_IDLE_STAT_STAT_1_SHIFT)) & K566_RTU_GPR_GASKET_IDLE_STAT_STAT_1_MASK)

#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_2_MASK (0x4U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_2_SHIFT (2U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_2_WIDTH (1U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_2(x)  (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_GASKET_IDLE_STAT_STAT_2_SHIFT)) & K566_RTU_GPR_GASKET_IDLE_STAT_STAT_2_MASK)

#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_3_MASK (0x8U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_3_SHIFT (3U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_3_WIDTH (1U)
#define K566_RTU_GPR_GASKET_IDLE_STAT_STAT_3(x)  (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_GASKET_IDLE_STAT_STAT_3_SHIFT)) & K566_RTU_GPR_GASKET_IDLE_STAT_STAT_3_MASK)
/*! @} */

/*! @name CR52_STANDBYWFI - R52 Standby Wait For Interrupt (WFI) Status */
/*! @{ */

#define K566_RTU_GPR_CR52_STANDBYWFI_WFI0_MASK   (0x1U)
#define K566_RTU_GPR_CR52_STANDBYWFI_WFI0_SHIFT  (0U)
#define K566_RTU_GPR_CR52_STANDBYWFI_WFI0_WIDTH  (1U)
#define K566_RTU_GPR_CR52_STANDBYWFI_WFI0(x)     (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_STANDBYWFI_WFI0_SHIFT)) & K566_RTU_GPR_CR52_STANDBYWFI_WFI0_MASK)

#define K566_RTU_GPR_CR52_STANDBYWFI_WFI1_MASK   (0x2U)
#define K566_RTU_GPR_CR52_STANDBYWFI_WFI1_SHIFT  (1U)
#define K566_RTU_GPR_CR52_STANDBYWFI_WFI1_WIDTH  (1U)
#define K566_RTU_GPR_CR52_STANDBYWFI_WFI1(x)     (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_STANDBYWFI_WFI1_SHIFT)) & K566_RTU_GPR_CR52_STANDBYWFI_WFI1_MASK)
/*! @} */

/*! @name CR52_STANDBYWFE - R52 Standby Wait For Event (WFE) Status */
/*! @{ */

#define K566_RTU_GPR_CR52_STANDBYWFE_WFE0_MASK   (0x1U)
#define K566_RTU_GPR_CR52_STANDBYWFE_WFE0_SHIFT  (0U)
#define K566_RTU_GPR_CR52_STANDBYWFE_WFE0_WIDTH  (1U)
#define K566_RTU_GPR_CR52_STANDBYWFE_WFE0(x)     (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_STANDBYWFE_WFE0_SHIFT)) & K566_RTU_GPR_CR52_STANDBYWFE_WFE0_MASK)

#define K566_RTU_GPR_CR52_STANDBYWFE_WFE1_MASK   (0x2U)
#define K566_RTU_GPR_CR52_STANDBYWFE_WFE1_SHIFT  (1U)
#define K566_RTU_GPR_CR52_STANDBYWFE_WFE1_WIDTH  (1U)
#define K566_RTU_GPR_CR52_STANDBYWFE_WFE1(x)     (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_STANDBYWFE_WFE1_SHIFT)) & K566_RTU_GPR_CR52_STANDBYWFE_WFE1_MASK)
/*! @} */

/*! @name CR52_RESETREQ - R52 Reset Request */
/*! @{ */

#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ0_MASK (0x1U)
#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ0_SHIFT (0U)
#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ0_WIDTH (1U)
#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ0(x) (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ0_SHIFT)) & K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ0_MASK)

#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ1_MASK (0x2U)
#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ1_SHIFT (1U)
#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ1_WIDTH (1U)
#define K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ1(x) (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ1_SHIFT)) & K566_RTU_GPR_CR52_RESETREQ_WARMRSTREQ1_MASK)
/*! @} */

/*! @name PMCMBISTDIS - Programmable MBIST Controller (PMC) Disable */
/*! @{ */

#define K566_RTU_GPR_PMCMBISTDIS_DIS_MASK        (0x1U)
#define K566_RTU_GPR_PMCMBISTDIS_DIS_SHIFT       (0U)
#define K566_RTU_GPR_PMCMBISTDIS_DIS_WIDTH       (1U)
#define K566_RTU_GPR_PMCMBISTDIS_DIS(x)          (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_PMCMBISTDIS_DIS_SHIFT)) & K566_RTU_GPR_PMCMBISTDIS_DIS_MASK)
/*! @} */

/*! @name MBUSPARDIS - Bus Parity Error Disable Group 0 */
/*! @{ */

#define K566_RTU_GPR_MBUSPARDIS_BUPERR0_MASK     (0x1U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR0_SHIFT    (0U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR0_WIDTH    (1U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR0(x)       (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_MBUSPARDIS_BUPERR0_SHIFT)) & K566_RTU_GPR_MBUSPARDIS_BUPERR0_MASK)

#define K566_RTU_GPR_MBUSPARDIS_BUPERR1_MASK     (0x2U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR1_SHIFT    (1U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR1_WIDTH    (1U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR1(x)       (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_MBUSPARDIS_BUPERR1_SHIFT)) & K566_RTU_GPR_MBUSPARDIS_BUPERR1_MASK)

#define K566_RTU_GPR_MBUSPARDIS_BUPERR2_MASK     (0x4U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR2_SHIFT    (2U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR2_WIDTH    (1U)
#define K566_RTU_GPR_MBUSPARDIS_BUPERR2(x)       (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_MBUSPARDIS_BUPERR2_SHIFT)) & K566_RTU_GPR_MBUSPARDIS_BUPERR2_MASK)
/*! @} */

/*! @name NBUSPARDIS - Bus Parity Error Disable Group 1 */
/*! @{ */

#define K566_RTU_GPR_NBUSPARDIS_BUPERR0_MASK     (0x1U)
#define K566_RTU_GPR_NBUSPARDIS_BUPERR0_SHIFT    (0U)
#define K566_RTU_GPR_NBUSPARDIS_BUPERR0_WIDTH    (1U)
#define K566_RTU_GPR_NBUSPARDIS_BUPERR0(x)       (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_NBUSPARDIS_BUPERR0_SHIFT)) & K566_RTU_GPR_NBUSPARDIS_BUPERR0_MASK)
/*! @} */

/*! @name R52_CORE_0_SW_FAULT - Software Fault Control 0 */
/*! @{ */

#define K566_RTU_GPR_R52_CORE_0_SW_FAULT_trig_MASK (0x1U)
#define K566_RTU_GPR_R52_CORE_0_SW_FAULT_trig_SHIFT (0U)
#define K566_RTU_GPR_R52_CORE_0_SW_FAULT_trig_WIDTH (1U)
#define K566_RTU_GPR_R52_CORE_0_SW_FAULT_trig(x) (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CORE_0_SW_FAULT_trig_SHIFT)) & K566_RTU_GPR_R52_CORE_0_SW_FAULT_trig_MASK)
/*! @} */

/*! @name R52_CORE_1_SW_FAULT - Software Fault Control 1 */
/*! @{ */

#define K566_RTU_GPR_R52_CORE_1_SW_FAULT_trig_MASK (0x1U)
#define K566_RTU_GPR_R52_CORE_1_SW_FAULT_trig_SHIFT (0U)
#define K566_RTU_GPR_R52_CORE_1_SW_FAULT_trig_WIDTH (1U)
#define K566_RTU_GPR_R52_CORE_1_SW_FAULT_trig(x) (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_CORE_1_SW_FAULT_trig_SHIFT)) & K566_RTU_GPR_R52_CORE_1_SW_FAULT_trig_MASK)
/*! @} */

/*! @name PLL_PD_RGM_REQ - PLL Power Down Request */
/*! @{ */

#define K566_RTU_GPR_PLL_PD_RGM_REQ_CFG_MASK     (0x1U)
#define K566_RTU_GPR_PLL_PD_RGM_REQ_CFG_SHIFT    (0U)
#define K566_RTU_GPR_PLL_PD_RGM_REQ_CFG_WIDTH    (1U)
#define K566_RTU_GPR_PLL_PD_RGM_REQ_CFG(x)       (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_PLL_PD_RGM_REQ_CFG_SHIFT)) & K566_RTU_GPR_PLL_PD_RGM_REQ_CFG_MASK)
/*! @} */

/*! @name PLL_PD_RGM_ACK - PLL Power Down Acknowledgement */
/*! @{ */

#define K566_RTU_GPR_PLL_PD_RGM_ACK_STAT_MASK    (0x1U)
#define K566_RTU_GPR_PLL_PD_RGM_ACK_STAT_SHIFT   (0U)
#define K566_RTU_GPR_PLL_PD_RGM_ACK_STAT_WIDTH   (1U)
#define K566_RTU_GPR_PLL_PD_RGM_ACK_STAT(x)      (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_PLL_PD_RGM_ACK_STAT_SHIFT)) & K566_RTU_GPR_PLL_PD_RGM_ACK_STAT_MASK)
/*! @} */

/*! @name R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION - R52_PMC TO CPE_PERIPH_BRIDGE Isolation */
/*! @{ */

#define K566_RTU_GPR_R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION_CFG_MASK (0x1U)
#define K566_RTU_GPR_R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION_CFG_SHIFT (0U)
#define K566_RTU_GPR_R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION_CFG_WIDTH (1U)
#define K566_RTU_GPR_R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION_CFG(x) (((uint32_t)(((uint32_t)(x)) << K566_RTU_GPR_R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION_CFG_SHIFT)) & K566_RTU_GPR_R52_PMC_CPE_PERIPH_BRIDGE_ISOLATION_CFG_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group K566_RTU_GPR_Register_Masks */

/*!
 * @}
 */ /* end of group K566_RTU_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_K566_RTU_GPR_H_) */
