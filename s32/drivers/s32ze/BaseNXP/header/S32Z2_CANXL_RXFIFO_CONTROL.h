/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CANXL_RXFIFO_CONTROL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CANXL_RXFIFO_CONTROL
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
#if !defined(S32Z2_CANXL_RXFIFO_CONTROL_H_)  /* Check if memory map has not been already included */
#define S32Z2_CANXL_RXFIFO_CONTROL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL_RXFIFO_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_RXFIFO_CONTROL_Peripheral_Access_Layer CANXL_RXFIFO_CONTROL Peripheral Access Layer
 * @{
 */

/** CANXL_RXFIFO_CONTROL - Register Layout Typedef */
typedef struct {
  __I  uint32_t RXFCSTA;                           /**< RxFIFO Control Status, offset: 0x0 */
  __IO uint32_t RXFSYSPOP;                         /**< RxFIFO POP Control, offset: 0x4 */
  __IO uint32_t RXFSYSLOCK;                        /**< RxFIFO System Lock Control, offset: 0x8 */
  uint8_t RESERVED_0[8];
  __IO uint32_t RXFSYSACT;                         /**< RxFIFO Activation, offset: 0x14 */
  uint8_t RESERVED_1[8];
  __IO uint32_t RXFIEN;                            /**< RxFIFO Interrupt Enable, offset: 0x20 */
  __IO uint32_t RXFS;                              /**< RxFIFO Status, offset: 0x24 */
  __IO uint32_t RXFC;                              /**< RxFIFO Configuration, offset: 0x28 */
} CANXL_RXFIFO_CONTROL_Type, *CANXL_RXFIFO_CONTROL_MemMapPtr;

/** Number of instances of the CANXL_RXFIFO_CONTROL module. */
#define CANXL_RXFIFO_CONTROL_INSTANCE_COUNT      (2u)

/* CANXL_RXFIFO_CONTROL - Peripheral instance base addresses */
/** Peripheral CANXL_0__RXFIFO_CONTROL base address */
#define IP_CANXL_0__RXFIFO_CONTROL_BASE          (0x47425000u)
/** Peripheral CANXL_0__RXFIFO_CONTROL base pointer */
#define IP_CANXL_0__RXFIFO_CONTROL               ((CANXL_RXFIFO_CONTROL_Type *)IP_CANXL_0__RXFIFO_CONTROL_BASE)
/** Peripheral CANXL_1__RXFIFO_CONTROL base address */
#define IP_CANXL_1__RXFIFO_CONTROL_BASE          (0x47525000u)
/** Peripheral CANXL_1__RXFIFO_CONTROL base pointer */
#define IP_CANXL_1__RXFIFO_CONTROL               ((CANXL_RXFIFO_CONTROL_Type *)IP_CANXL_1__RXFIFO_CONTROL_BASE)
/** Array initializer of CANXL_RXFIFO_CONTROL peripheral base addresses */
#define IP_CANXL_RXFIFO_CONTROL_BASE_ADDRS       { IP_CANXL_0__RXFIFO_CONTROL_BASE, IP_CANXL_1__RXFIFO_CONTROL_BASE }
/** Array initializer of CANXL_RXFIFO_CONTROL peripheral base pointers */
#define IP_CANXL_RXFIFO_CONTROL_BASE_PTRS        { IP_CANXL_0__RXFIFO_CONTROL, IP_CANXL_1__RXFIFO_CONTROL }

/* ----------------------------------------------------------------------------
   -- CANXL_RXFIFO_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_RXFIFO_CONTROL_Register_Masks CANXL_RXFIFO_CONTROL Register Masks
 * @{
 */

/*! @name RXFCSTA - RxFIFO Control Status */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFCSTA_STATE_MASK  (0x7U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_STATE_SHIFT (0U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_STATE_WIDTH (3U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_STATE(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFCSTA_STATE_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFCSTA_STATE_MASK)

#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWLOCK_MASK (0x40U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWLOCK_SHIFT (6U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWLOCK_WIDTH (1U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWLOCK(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFCSTA_HWLOCK_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFCSTA_HWLOCK_MASK)

#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK (0x80U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_SHIFT (7U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_WIDTH (1U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK)

#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_MASK (0x3F00U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_SHIFT (8U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_WIDTH (6U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER(x) (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_MASK)

#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSPOINTER_MASK (0x3F0000U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSPOINTER_SHIFT (16U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSPOINTER_WIDTH (6U)
#define CANXL_RXFIFO_CONTROL_RXFCSTA_SYSPOINTER(x) (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFCSTA_SYSPOINTER_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFCSTA_SYSPOINTER_MASK)
/*! @} */

/*! @name RXFSYSPOP - RxFIFO POP Control */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFSYSPOP_RXPOP_MASK (0x1FU)
#define CANXL_RXFIFO_CONTROL_RXFSYSPOP_RXPOP_SHIFT (0U)
#define CANXL_RXFIFO_CONTROL_RXFSYSPOP_RXPOP_WIDTH (5U)
#define CANXL_RXFIFO_CONTROL_RXFSYSPOP_RXPOP(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFSYSPOP_RXPOP_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFSYSPOP_RXPOP_MASK)
/*! @} */

/*! @name RXFSYSLOCK - RxFIFO System Lock Control */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK (0x1U)
#define CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_SHIFT (0U)
#define CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_WIDTH (1U)
#define CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK(x) (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK)
/*! @} */

/*! @name RXFSYSACT - RxFIFO Activation */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK  (0x1U)
#define CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_SHIFT (0U)
#define CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_WIDTH (1U)
#define CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK)
/*! @} */

/*! @name RXFIEN - RxFIFO Interrupt Enable */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK   (0x1U)
#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_SHIFT  (0U)
#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_WIDTH  (1U)
#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK)

#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK  (0x2U)
#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_SHIFT (1U)
#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_WIDTH (1U)
#define CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK)
/*! @} */

/*! @name RXFS - RxFIFO Status */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK      (0x1U)
#define CANXL_RXFIFO_CONTROL_RXFS_RXFF_SHIFT     (0U)
#define CANXL_RXFIFO_CONTROL_RXFS_RXFF_WIDTH     (1U)
#define CANXL_RXFIFO_CONTROL_RXFS_RXFF(x)        (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFS_RXFF_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK)

#define CANXL_RXFIFO_CONTROL_RXFS_RXFEF_MASK     (0x2U)
#define CANXL_RXFIFO_CONTROL_RXFS_RXFEF_SHIFT    (1U)
#define CANXL_RXFIFO_CONTROL_RXFS_RXFEF_WIDTH    (1U)
#define CANXL_RXFIFO_CONTROL_RXFS_RXFEF(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFS_RXFEF_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFS_RXFEF_MASK)
/*! @} */

/*! @name RXFC - RxFIFO Configuration */
/*! @{ */

#define CANXL_RXFIFO_CONTROL_RXFC_RXFD_MASK      (0x1FU)
#define CANXL_RXFIFO_CONTROL_RXFC_RXFD_SHIFT     (0U)
#define CANXL_RXFIFO_CONTROL_RXFC_RXFD_WIDTH     (5U)
#define CANXL_RXFIFO_CONTROL_RXFC_RXFD(x)        (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFC_RXFD_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFC_RXFD_MASK)

#define CANXL_RXFIFO_CONTROL_RXFC_RXFWTM_MASK    (0x1F00U)
#define CANXL_RXFIFO_CONTROL_RXFC_RXFWTM_SHIFT   (8U)
#define CANXL_RXFIFO_CONTROL_RXFC_RXFWTM_WIDTH   (5U)
#define CANXL_RXFIFO_CONTROL_RXFC_RXFWTM(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_RXFIFO_CONTROL_RXFC_RXFWTM_SHIFT)) & CANXL_RXFIFO_CONTROL_RXFC_RXFWTM_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_RXFIFO_CONTROL_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_RXFIFO_CONTROL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CANXL_RXFIFO_CONTROL_H_) */
