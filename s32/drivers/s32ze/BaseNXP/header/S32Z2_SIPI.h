/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SIPI.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SIPI
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
#if !defined(S32Z2_SIPI_H_)  /* Check if memory map has not been already included */
#define S32Z2_SIPI_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SIPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIPI_Peripheral_Access_Layer SIPI Peripheral Access Layer
 * @{
 */

/** SIPI - Size of Registers Arrays */
#define SIPI_CDR2_COUNT                           8u

/** SIPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCR0;                              /**< SIPI Channel Control Register 0, offset: 0x0 */
  __IO uint32_t CSR0;                              /**< SIPI Channel Status Register 0, offset: 0x4 */
  uint8_t RESERVED_0[4];
  __IO uint32_t CIR0;                              /**< SIPI Channel Interrupt Register 0, offset: 0xC */
  __IO uint32_t CTOR0;                             /**< SIPI Channel Timeout Register 0, offset: 0x10 */
  __I  uint32_t CCRC0;                             /**< SIPI Channel CRC Register 0, offset: 0x14 */
  __IO uint32_t CAR0;                              /**< SIPI Channel Address Register 0, offset: 0x18 */
  __IO uint32_t CDR0;                              /**< SIPI Channel Data Register 0, offset: 0x1C */
  __IO uint32_t CCR1;                              /**< SIPI Channel Control Register 1, offset: 0x20 */
  __IO uint32_t CSR1;                              /**< SIPI Channel Status Register 1, offset: 0x24 */
  uint8_t RESERVED_1[4];
  __IO uint32_t CIR1;                              /**< SIPI Channel Interrupt Register 1, offset: 0x2C */
  __IO uint32_t CTOR1;                             /**< SIPI Channel Timeout Register 1, offset: 0x30 */
  __I  uint32_t CCRC1;                             /**< SIPI Channel CRC Register 1, offset: 0x34 */
  __IO uint32_t CAR1;                              /**< SIPI Channel Address Register 1, offset: 0x38 */
  __IO uint32_t CDR1;                              /**< SIPI Channel Data Register 1, offset: 0x3C */
  __IO uint32_t CCR2;                              /**< SIPI Channel Control Register 2, offset: 0x40 */
  __IO uint32_t CSR2;                              /**< SIPI Channel Status Register 2, offset: 0x44 */
  uint8_t RESERVED_2[4];
  __IO uint32_t CIR2;                              /**< SIPI Channel Interrupt Register 2, offset: 0x4C */
  __IO uint32_t CTOR2;                             /**< SIPI Channel Timeout Register 2, offset: 0x50 */
  __I  uint32_t CCRC2;                             /**< SIPI Channel CRC Register 2, offset: 0x54 */
  __IO uint32_t CAR2;                              /**< SIPI Channel Address Register 2, offset: 0x58 */
  __IO uint32_t CDR2[SIPI_CDR2_COUNT];             /**< SIPI Channel Data Register 2, array offset: 0x5C, array step: 0x4 */
  __IO uint32_t CCR3;                              /**< SIPI Channel Control Register 3, offset: 0x7C */
  __IO uint32_t CSR3;                              /**< SIPI Channel Status Register 3, offset: 0x80 */
  uint8_t RESERVED_3[4];
  __IO uint32_t CIR3;                              /**< SIPI Channel Interrupt Register 3, offset: 0x88 */
  __IO uint32_t CTOR3;                             /**< SIPI Channel Timeout Register 3, offset: 0x8C */
  __I  uint32_t CCRC3;                             /**< SIPI Channel CRC Register 3, offset: 0x90 */
  __IO uint32_t CAR3;                              /**< SIPI Channel Address Register 3, offset: 0x94 */
  __IO uint32_t CDR3;                              /**< SIPI Channel Data Register 3, offset: 0x98 */
  __IO uint32_t MCR;                               /**< SIPI Module Configuration Register, offset: 0x9C */
  __IO uint32_t SR;                                /**< SIPI Status Register, offset: 0xA0 */
  __IO uint32_t MAXCR;                             /**< SIPI Max Count Register, offset: 0xA4 */
  __IO uint32_t ARR;                               /**< SIPI Address Reload Register, offset: 0xA8 */
  __IO uint32_t ACR;                               /**< SIPI Address Count Register, offset: 0xAC */
  __IO uint32_t ERR;                               /**< SIPI Error Register, offset: 0xB0 */
  __I  uint32_t DEBUGr;                            /**< SIPI Debug Register, offset: 0xB4, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
  __I  uint32_t PMR;                               /**< SIPI Performance Monitor register, offset: 0xB8 */
} SIPI_Type, *SIPI_MemMapPtr;

/** Number of instances of the SIPI module. */
#define SIPI_INSTANCE_COUNT                      (2u)

/* SIPI - Peripheral instance base addresses */
/** Peripheral SIPI_0 base address */
#define IP_SIPI_0_BASE                           (0x40A20000u)
/** Peripheral SIPI_0 base pointer */
#define IP_SIPI_0                                ((SIPI_Type *)IP_SIPI_0_BASE)
/** Peripheral SIPI_1 base address */
#define IP_SIPI_1_BASE                           (0x40A40000u)
/** Peripheral SIPI_1 base pointer */
#define IP_SIPI_1                                ((SIPI_Type *)IP_SIPI_1_BASE)
/** Array initializer of SIPI peripheral base addresses */
#define IP_SIPI_BASE_ADDRS                       { IP_SIPI_0_BASE, IP_SIPI_1_BASE }
/** Array initializer of SIPI peripheral base pointers */
#define IP_SIPI_BASE_PTRS                        { IP_SIPI_0, IP_SIPI_1 }

/* ----------------------------------------------------------------------------
   -- SIPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIPI_Register_Masks SIPI Register Masks
 * @{
 */

/*! @name CCR0 - SIPI Channel Control Register 0 */
/*! @{ */

#define SIPI_CCR0_DEN_MASK                       (0x1U)
#define SIPI_CCR0_DEN_SHIFT                      (0U)
#define SIPI_CCR0_DEN_WIDTH                      (1U)
#define SIPI_CCR0_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_DEN_SHIFT)) & SIPI_CCR0_DEN_MASK)

#define SIPI_CCR0_WRT_MASK                       (0x2U)
#define SIPI_CCR0_WRT_SHIFT                      (1U)
#define SIPI_CCR0_WRT_WIDTH                      (1U)
#define SIPI_CCR0_WRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_WRT_SHIFT)) & SIPI_CCR0_WRT_MASK)

#define SIPI_CCR0_RRT_MASK                       (0x4U)
#define SIPI_CCR0_RRT_SHIFT                      (2U)
#define SIPI_CCR0_RRT_WIDTH                      (1U)
#define SIPI_CCR0_RRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_RRT_SHIFT)) & SIPI_CCR0_RRT_MASK)

#define SIPI_CCR0_IDT_MASK                       (0x8U)
#define SIPI_CCR0_IDT_SHIFT                      (3U)
#define SIPI_CCR0_IDT_WIDTH                      (1U)
#define SIPI_CCR0_IDT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_IDT_SHIFT)) & SIPI_CCR0_IDT_MASK)

#define SIPI_CCR0_CHEN_MASK                      (0x20U)
#define SIPI_CCR0_CHEN_SHIFT                     (5U)
#define SIPI_CCR0_CHEN_WIDTH                     (1U)
#define SIPI_CCR0_CHEN(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_CHEN_SHIFT)) & SIPI_CCR0_CHEN_MASK)

#define SIPI_CCR0_WL_MASK                        (0xC0U)
#define SIPI_CCR0_WL_SHIFT                       (6U)
#define SIPI_CCR0_WL_WIDTH                       (2U)
#define SIPI_CCR0_WL(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_WL_SHIFT)) & SIPI_CCR0_WL_MASK)

#define SIPI_CCR0_TC_MASK                        (0x10000U)
#define SIPI_CCR0_TC_SHIFT                       (16U)
#define SIPI_CCR0_TC_WIDTH                       (1U)
#define SIPI_CCR0_TC(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR0_TC_SHIFT)) & SIPI_CCR0_TC_MASK)
/*! @} */

/*! @name CSR0 - SIPI Channel Status Register 0 */
/*! @{ */

#define SIPI_CSR0_CB_MASK                        (0x4U)
#define SIPI_CSR0_CB_SHIFT                       (2U)
#define SIPI_CSR0_CB_WIDTH                       (1U)
#define SIPI_CSR0_CB(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CSR0_CB_SHIFT)) & SIPI_CSR0_CB_MASK)

#define SIPI_CSR0_ACKR_MASK                      (0x8U)
#define SIPI_CSR0_ACKR_SHIFT                     (3U)
#define SIPI_CSR0_ACKR_WIDTH                     (1U)
#define SIPI_CSR0_ACKR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CSR0_ACKR_SHIFT)) & SIPI_CSR0_ACKR_MASK)

#define SIPI_CSR0_TID_MASK                       (0x70U)
#define SIPI_CSR0_TID_SHIFT                      (4U)
#define SIPI_CSR0_TID_WIDTH                      (3U)
#define SIPI_CSR0_TID(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR0_TID_SHIFT)) & SIPI_CSR0_TID_MASK)

#define SIPI_CSR0_RAR_MASK                       (0x80U)
#define SIPI_CSR0_RAR_SHIFT                      (7U)
#define SIPI_CSR0_RAR_WIDTH                      (1U)
#define SIPI_CSR0_RAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR0_RAR_SHIFT)) & SIPI_CSR0_RAR_MASK)

#define SIPI_CSR0_READ_RX_MASK                   (0x100U)
#define SIPI_CSR0_READ_RX_SHIFT                  (8U)
#define SIPI_CSR0_READ_RX_WIDTH                  (1U)
#define SIPI_CSR0_READ_RX(x)                     (((uint32_t)(((uint32_t)(x)) << SIPI_CSR0_READ_RX_SHIFT)) & SIPI_CSR0_READ_RX_MASK)

#define SIPI_CSR0_WRITE_RX_MASK                  (0x200U)
#define SIPI_CSR0_WRITE_RX_SHIFT                 (9U)
#define SIPI_CSR0_WRITE_RX_WIDTH                 (1U)
#define SIPI_CSR0_WRITE_RX(x)                    (((uint32_t)(((uint32_t)(x)) << SIPI_CSR0_WRITE_RX_SHIFT)) & SIPI_CSR0_WRITE_RX_MASK)
/*! @} */

/*! @name CIR0 - SIPI Channel Interrupt Register 0 */
/*! @{ */

#define SIPI_CIR0_ACKIE_MASK                     (0x1U)
#define SIPI_CIR0_ACKIE_SHIFT                    (0U)
#define SIPI_CIR0_ACKIE_WIDTH                    (1U)
#define SIPI_CIR0_ACKIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR0_ACKIE_SHIFT)) & SIPI_CIR0_ACKIE_MASK)

#define SIPI_CIR0_TIDIE_MASK                     (0x2U)
#define SIPI_CIR0_TIDIE_SHIFT                    (1U)
#define SIPI_CIR0_TIDIE_WIDTH                    (1U)
#define SIPI_CIR0_TIDIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR0_TIDIE_SHIFT)) & SIPI_CIR0_TIDIE_MASK)

#define SIPI_CIR0_TOIE_MASK                      (0x4U)
#define SIPI_CIR0_TOIE_SHIFT                     (2U)
#define SIPI_CIR0_TOIE_WIDTH                     (1U)
#define SIPI_CIR0_TOIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR0_TOIE_SHIFT)) & SIPI_CIR0_TOIE_MASK)

#define SIPI_CIR0_TCIE_MASK                      (0x8U)
#define SIPI_CIR0_TCIE_SHIFT                     (3U)
#define SIPI_CIR0_TCIE_WIDTH                     (1U)
#define SIPI_CIR0_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR0_TCIE_SHIFT)) & SIPI_CIR0_TCIE_MASK)

#define SIPI_CIR0_RAIE_MASK                      (0x10U)
#define SIPI_CIR0_RAIE_SHIFT                     (4U)
#define SIPI_CIR0_RAIE_WIDTH                     (1U)
#define SIPI_CIR0_RAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR0_RAIE_SHIFT)) & SIPI_CIR0_RAIE_MASK)

#define SIPI_CIR0_WAIE_MASK                      (0x20U)
#define SIPI_CIR0_WAIE_SHIFT                     (5U)
#define SIPI_CIR0_WAIE_WIDTH                     (1U)
#define SIPI_CIR0_WAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR0_WAIE_SHIFT)) & SIPI_CIR0_WAIE_MASK)
/*! @} */

/*! @name CTOR0 - SIPI Channel Timeout Register 0 */
/*! @{ */

#define SIPI_CTOR0_TOR_MASK                      (0xFFFFFFFFU)
#define SIPI_CTOR0_TOR_SHIFT                     (0U)
#define SIPI_CTOR0_TOR_WIDTH                     (32U)
#define SIPI_CTOR0_TOR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CTOR0_TOR_SHIFT)) & SIPI_CTOR0_TOR_MASK)
/*! @} */

/*! @name CCRC0 - SIPI Channel CRC Register 0 */
/*! @{ */

#define SIPI_CCRC0_CRCT_MASK                     (0xFFFFU)
#define SIPI_CCRC0_CRCT_SHIFT                    (0U)
#define SIPI_CCRC0_CRCT_WIDTH                    (16U)
#define SIPI_CCRC0_CRCT(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC0_CRCT_SHIFT)) & SIPI_CCRC0_CRCT_MASK)

#define SIPI_CCRC0_CRCI_MASK                     (0xFFFF0000U)
#define SIPI_CCRC0_CRCI_SHIFT                    (16U)
#define SIPI_CCRC0_CRCI_WIDTH                    (16U)
#define SIPI_CCRC0_CRCI(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC0_CRCI_SHIFT)) & SIPI_CCRC0_CRCI_MASK)
/*! @} */

/*! @name CAR0 - SIPI Channel Address Register 0 */
/*! @{ */

#define SIPI_CAR0_CAR_MASK                       (0xFFFFFFFFU)
#define SIPI_CAR0_CAR_SHIFT                      (0U)
#define SIPI_CAR0_CAR_WIDTH                      (32U)
#define SIPI_CAR0_CAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CAR0_CAR_SHIFT)) & SIPI_CAR0_CAR_MASK)
/*! @} */

/*! @name CDR0 - SIPI Channel Data Register 0 */
/*! @{ */

#define SIPI_CDR0_CDR_MASK                       (0xFFFFFFFFU)
#define SIPI_CDR0_CDR_SHIFT                      (0U)
#define SIPI_CDR0_CDR_WIDTH                      (32U)
#define SIPI_CDR0_CDR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CDR0_CDR_SHIFT)) & SIPI_CDR0_CDR_MASK)
/*! @} */

/*! @name CCR1 - SIPI Channel Control Register 1 */
/*! @{ */

#define SIPI_CCR1_DEN_MASK                       (0x1U)
#define SIPI_CCR1_DEN_SHIFT                      (0U)
#define SIPI_CCR1_DEN_WIDTH                      (1U)
#define SIPI_CCR1_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_DEN_SHIFT)) & SIPI_CCR1_DEN_MASK)

#define SIPI_CCR1_WRT_MASK                       (0x2U)
#define SIPI_CCR1_WRT_SHIFT                      (1U)
#define SIPI_CCR1_WRT_WIDTH                      (1U)
#define SIPI_CCR1_WRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_WRT_SHIFT)) & SIPI_CCR1_WRT_MASK)

#define SIPI_CCR1_RRT_MASK                       (0x4U)
#define SIPI_CCR1_RRT_SHIFT                      (2U)
#define SIPI_CCR1_RRT_WIDTH                      (1U)
#define SIPI_CCR1_RRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_RRT_SHIFT)) & SIPI_CCR1_RRT_MASK)

#define SIPI_CCR1_IDT_MASK                       (0x8U)
#define SIPI_CCR1_IDT_SHIFT                      (3U)
#define SIPI_CCR1_IDT_WIDTH                      (1U)
#define SIPI_CCR1_IDT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_IDT_SHIFT)) & SIPI_CCR1_IDT_MASK)

#define SIPI_CCR1_CHEN_MASK                      (0x20U)
#define SIPI_CCR1_CHEN_SHIFT                     (5U)
#define SIPI_CCR1_CHEN_WIDTH                     (1U)
#define SIPI_CCR1_CHEN(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_CHEN_SHIFT)) & SIPI_CCR1_CHEN_MASK)

#define SIPI_CCR1_WL_MASK                        (0xC0U)
#define SIPI_CCR1_WL_SHIFT                       (6U)
#define SIPI_CCR1_WL_WIDTH                       (2U)
#define SIPI_CCR1_WL(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_WL_SHIFT)) & SIPI_CCR1_WL_MASK)

#define SIPI_CCR1_TC_MASK                        (0x10000U)
#define SIPI_CCR1_TC_SHIFT                       (16U)
#define SIPI_CCR1_TC_WIDTH                       (1U)
#define SIPI_CCR1_TC(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR1_TC_SHIFT)) & SIPI_CCR1_TC_MASK)
/*! @} */

/*! @name CSR1 - SIPI Channel Status Register 1 */
/*! @{ */

#define SIPI_CSR1_CB_MASK                        (0x4U)
#define SIPI_CSR1_CB_SHIFT                       (2U)
#define SIPI_CSR1_CB_WIDTH                       (1U)
#define SIPI_CSR1_CB(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CSR1_CB_SHIFT)) & SIPI_CSR1_CB_MASK)

#define SIPI_CSR1_ACKR_MASK                      (0x8U)
#define SIPI_CSR1_ACKR_SHIFT                     (3U)
#define SIPI_CSR1_ACKR_WIDTH                     (1U)
#define SIPI_CSR1_ACKR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CSR1_ACKR_SHIFT)) & SIPI_CSR1_ACKR_MASK)

#define SIPI_CSR1_TID_MASK                       (0x70U)
#define SIPI_CSR1_TID_SHIFT                      (4U)
#define SIPI_CSR1_TID_WIDTH                      (3U)
#define SIPI_CSR1_TID(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR1_TID_SHIFT)) & SIPI_CSR1_TID_MASK)

#define SIPI_CSR1_RAR_MASK                       (0x80U)
#define SIPI_CSR1_RAR_SHIFT                      (7U)
#define SIPI_CSR1_RAR_WIDTH                      (1U)
#define SIPI_CSR1_RAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR1_RAR_SHIFT)) & SIPI_CSR1_RAR_MASK)

#define SIPI_CSR1_READ_RX_MASK                   (0x100U)
#define SIPI_CSR1_READ_RX_SHIFT                  (8U)
#define SIPI_CSR1_READ_RX_WIDTH                  (1U)
#define SIPI_CSR1_READ_RX(x)                     (((uint32_t)(((uint32_t)(x)) << SIPI_CSR1_READ_RX_SHIFT)) & SIPI_CSR1_READ_RX_MASK)

#define SIPI_CSR1_WRITE_RX_MASK                  (0x200U)
#define SIPI_CSR1_WRITE_RX_SHIFT                 (9U)
#define SIPI_CSR1_WRITE_RX_WIDTH                 (1U)
#define SIPI_CSR1_WRITE_RX(x)                    (((uint32_t)(((uint32_t)(x)) << SIPI_CSR1_WRITE_RX_SHIFT)) & SIPI_CSR1_WRITE_RX_MASK)
/*! @} */

/*! @name CIR1 - SIPI Channel Interrupt Register 1 */
/*! @{ */

#define SIPI_CIR1_ACKIE_MASK                     (0x1U)
#define SIPI_CIR1_ACKIE_SHIFT                    (0U)
#define SIPI_CIR1_ACKIE_WIDTH                    (1U)
#define SIPI_CIR1_ACKIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR1_ACKIE_SHIFT)) & SIPI_CIR1_ACKIE_MASK)

#define SIPI_CIR1_TIDIE_MASK                     (0x2U)
#define SIPI_CIR1_TIDIE_SHIFT                    (1U)
#define SIPI_CIR1_TIDIE_WIDTH                    (1U)
#define SIPI_CIR1_TIDIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR1_TIDIE_SHIFT)) & SIPI_CIR1_TIDIE_MASK)

#define SIPI_CIR1_TOIE_MASK                      (0x4U)
#define SIPI_CIR1_TOIE_SHIFT                     (2U)
#define SIPI_CIR1_TOIE_WIDTH                     (1U)
#define SIPI_CIR1_TOIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR1_TOIE_SHIFT)) & SIPI_CIR1_TOIE_MASK)

#define SIPI_CIR1_TCIE_MASK                      (0x8U)
#define SIPI_CIR1_TCIE_SHIFT                     (3U)
#define SIPI_CIR1_TCIE_WIDTH                     (1U)
#define SIPI_CIR1_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR1_TCIE_SHIFT)) & SIPI_CIR1_TCIE_MASK)

#define SIPI_CIR1_RAIE_MASK                      (0x10U)
#define SIPI_CIR1_RAIE_SHIFT                     (4U)
#define SIPI_CIR1_RAIE_WIDTH                     (1U)
#define SIPI_CIR1_RAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR1_RAIE_SHIFT)) & SIPI_CIR1_RAIE_MASK)

#define SIPI_CIR1_WAIE_MASK                      (0x20U)
#define SIPI_CIR1_WAIE_SHIFT                     (5U)
#define SIPI_CIR1_WAIE_WIDTH                     (1U)
#define SIPI_CIR1_WAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR1_WAIE_SHIFT)) & SIPI_CIR1_WAIE_MASK)
/*! @} */

/*! @name CTOR1 - SIPI Channel Timeout Register 1 */
/*! @{ */

#define SIPI_CTOR1_TOR_MASK                      (0xFFFFFFFFU)
#define SIPI_CTOR1_TOR_SHIFT                     (0U)
#define SIPI_CTOR1_TOR_WIDTH                     (32U)
#define SIPI_CTOR1_TOR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CTOR1_TOR_SHIFT)) & SIPI_CTOR1_TOR_MASK)
/*! @} */

/*! @name CCRC1 - SIPI Channel CRC Register 1 */
/*! @{ */

#define SIPI_CCRC1_CRCT_MASK                     (0xFFFFU)
#define SIPI_CCRC1_CRCT_SHIFT                    (0U)
#define SIPI_CCRC1_CRCT_WIDTH                    (16U)
#define SIPI_CCRC1_CRCT(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC1_CRCT_SHIFT)) & SIPI_CCRC1_CRCT_MASK)

#define SIPI_CCRC1_CRCI_MASK                     (0xFFFF0000U)
#define SIPI_CCRC1_CRCI_SHIFT                    (16U)
#define SIPI_CCRC1_CRCI_WIDTH                    (16U)
#define SIPI_CCRC1_CRCI(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC1_CRCI_SHIFT)) & SIPI_CCRC1_CRCI_MASK)
/*! @} */

/*! @name CAR1 - SIPI Channel Address Register 1 */
/*! @{ */

#define SIPI_CAR1_CAR_MASK                       (0xFFFFFFFFU)
#define SIPI_CAR1_CAR_SHIFT                      (0U)
#define SIPI_CAR1_CAR_WIDTH                      (32U)
#define SIPI_CAR1_CAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CAR1_CAR_SHIFT)) & SIPI_CAR1_CAR_MASK)
/*! @} */

/*! @name CDR1 - SIPI Channel Data Register 1 */
/*! @{ */

#define SIPI_CDR1_CDR_MASK                       (0xFFFFFFFFU)
#define SIPI_CDR1_CDR_SHIFT                      (0U)
#define SIPI_CDR1_CDR_WIDTH                      (32U)
#define SIPI_CDR1_CDR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CDR1_CDR_SHIFT)) & SIPI_CDR1_CDR_MASK)
/*! @} */

/*! @name CCR2 - SIPI Channel Control Register 2 */
/*! @{ */

#define SIPI_CCR2_DEN_MASK                       (0x1U)
#define SIPI_CCR2_DEN_SHIFT                      (0U)
#define SIPI_CCR2_DEN_WIDTH                      (1U)
#define SIPI_CCR2_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_DEN_SHIFT)) & SIPI_CCR2_DEN_MASK)

#define SIPI_CCR2_WRT_MASK                       (0x2U)
#define SIPI_CCR2_WRT_SHIFT                      (1U)
#define SIPI_CCR2_WRT_WIDTH                      (1U)
#define SIPI_CCR2_WRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_WRT_SHIFT)) & SIPI_CCR2_WRT_MASK)

#define SIPI_CCR2_RRT_MASK                       (0x4U)
#define SIPI_CCR2_RRT_SHIFT                      (2U)
#define SIPI_CCR2_RRT_WIDTH                      (1U)
#define SIPI_CCR2_RRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_RRT_SHIFT)) & SIPI_CCR2_RRT_MASK)

#define SIPI_CCR2_IDT_MASK                       (0x8U)
#define SIPI_CCR2_IDT_SHIFT                      (3U)
#define SIPI_CCR2_IDT_WIDTH                      (1U)
#define SIPI_CCR2_IDT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_IDT_SHIFT)) & SIPI_CCR2_IDT_MASK)

#define SIPI_CCR2_ST_MASK                        (0x10U)
#define SIPI_CCR2_ST_SHIFT                       (4U)
#define SIPI_CCR2_ST_WIDTH                       (1U)
#define SIPI_CCR2_ST(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_ST_SHIFT)) & SIPI_CCR2_ST_MASK)

#define SIPI_CCR2_CHEN_MASK                      (0x20U)
#define SIPI_CCR2_CHEN_SHIFT                     (5U)
#define SIPI_CCR2_CHEN_WIDTH                     (1U)
#define SIPI_CCR2_CHEN(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_CHEN_SHIFT)) & SIPI_CCR2_CHEN_MASK)

#define SIPI_CCR2_WL_MASK                        (0xC0U)
#define SIPI_CCR2_WL_SHIFT                       (6U)
#define SIPI_CCR2_WL_WIDTH                       (2U)
#define SIPI_CCR2_WL(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_WL_SHIFT)) & SIPI_CCR2_WL_MASK)

#define SIPI_CCR2_TC_MASK                        (0x10000U)
#define SIPI_CCR2_TC_SHIFT                       (16U)
#define SIPI_CCR2_TC_WIDTH                       (1U)
#define SIPI_CCR2_TC(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR2_TC_SHIFT)) & SIPI_CCR2_TC_MASK)
/*! @} */

/*! @name CSR2 - SIPI Channel Status Register 2 */
/*! @{ */

#define SIPI_CSR2_CB_MASK                        (0x4U)
#define SIPI_CSR2_CB_SHIFT                       (2U)
#define SIPI_CSR2_CB_WIDTH                       (1U)
#define SIPI_CSR2_CB(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_CB_SHIFT)) & SIPI_CSR2_CB_MASK)

#define SIPI_CSR2_ACKR_MASK                      (0x8U)
#define SIPI_CSR2_ACKR_SHIFT                     (3U)
#define SIPI_CSR2_ACKR_WIDTH                     (1U)
#define SIPI_CSR2_ACKR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_ACKR_SHIFT)) & SIPI_CSR2_ACKR_MASK)

#define SIPI_CSR2_TID_MASK                       (0x70U)
#define SIPI_CSR2_TID_SHIFT                      (4U)
#define SIPI_CSR2_TID_WIDTH                      (3U)
#define SIPI_CSR2_TID(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_TID_SHIFT)) & SIPI_CSR2_TID_MASK)

#define SIPI_CSR2_RAR_MASK                       (0x80U)
#define SIPI_CSR2_RAR_SHIFT                      (7U)
#define SIPI_CSR2_RAR_WIDTH                      (1U)
#define SIPI_CSR2_RAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_RAR_SHIFT)) & SIPI_CSR2_RAR_MASK)

#define SIPI_CSR2_READ_RX_MASK                   (0x100U)
#define SIPI_CSR2_READ_RX_SHIFT                  (8U)
#define SIPI_CSR2_READ_RX_WIDTH                  (1U)
#define SIPI_CSR2_READ_RX(x)                     (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_READ_RX_SHIFT)) & SIPI_CSR2_READ_RX_MASK)

#define SIPI_CSR2_WRITE_RX_MASK                  (0x200U)
#define SIPI_CSR2_WRITE_RX_SHIFT                 (9U)
#define SIPI_CSR2_WRITE_RX_WIDTH                 (1U)
#define SIPI_CSR2_WRITE_RX(x)                    (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_WRITE_RX_SHIFT)) & SIPI_CSR2_WRITE_RX_MASK)

#define SIPI_CSR2_WRITE_STR_RX_MASK              (0x400U)
#define SIPI_CSR2_WRITE_STR_RX_SHIFT             (10U)
#define SIPI_CSR2_WRITE_STR_RX_WIDTH             (1U)
#define SIPI_CSR2_WRITE_STR_RX(x)                (((uint32_t)(((uint32_t)(x)) << SIPI_CSR2_WRITE_STR_RX_SHIFT)) & SIPI_CSR2_WRITE_STR_RX_MASK)
/*! @} */

/*! @name CIR2 - SIPI Channel Interrupt Register 2 */
/*! @{ */

#define SIPI_CIR2_ACKIE_MASK                     (0x1U)
#define SIPI_CIR2_ACKIE_SHIFT                    (0U)
#define SIPI_CIR2_ACKIE_WIDTH                    (1U)
#define SIPI_CIR2_ACKIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR2_ACKIE_SHIFT)) & SIPI_CIR2_ACKIE_MASK)

#define SIPI_CIR2_TIDIE_MASK                     (0x2U)
#define SIPI_CIR2_TIDIE_SHIFT                    (1U)
#define SIPI_CIR2_TIDIE_WIDTH                    (1U)
#define SIPI_CIR2_TIDIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR2_TIDIE_SHIFT)) & SIPI_CIR2_TIDIE_MASK)

#define SIPI_CIR2_TOIE_MASK                      (0x4U)
#define SIPI_CIR2_TOIE_SHIFT                     (2U)
#define SIPI_CIR2_TOIE_WIDTH                     (1U)
#define SIPI_CIR2_TOIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR2_TOIE_SHIFT)) & SIPI_CIR2_TOIE_MASK)

#define SIPI_CIR2_TCIE_MASK                      (0x8U)
#define SIPI_CIR2_TCIE_SHIFT                     (3U)
#define SIPI_CIR2_TCIE_WIDTH                     (1U)
#define SIPI_CIR2_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR2_TCIE_SHIFT)) & SIPI_CIR2_TCIE_MASK)

#define SIPI_CIR2_RAIE_MASK                      (0x10U)
#define SIPI_CIR2_RAIE_SHIFT                     (4U)
#define SIPI_CIR2_RAIE_WIDTH                     (1U)
#define SIPI_CIR2_RAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR2_RAIE_SHIFT)) & SIPI_CIR2_RAIE_MASK)

#define SIPI_CIR2_WAIE_MASK                      (0x20U)
#define SIPI_CIR2_WAIE_SHIFT                     (5U)
#define SIPI_CIR2_WAIE_WIDTH                     (1U)
#define SIPI_CIR2_WAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR2_WAIE_SHIFT)) & SIPI_CIR2_WAIE_MASK)
/*! @} */

/*! @name CTOR2 - SIPI Channel Timeout Register 2 */
/*! @{ */

#define SIPI_CTOR2_TOR_MASK                      (0xFFFFFFFFU)
#define SIPI_CTOR2_TOR_SHIFT                     (0U)
#define SIPI_CTOR2_TOR_WIDTH                     (32U)
#define SIPI_CTOR2_TOR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CTOR2_TOR_SHIFT)) & SIPI_CTOR2_TOR_MASK)
/*! @} */

/*! @name CCRC2 - SIPI Channel CRC Register 2 */
/*! @{ */

#define SIPI_CCRC2_CRCT_MASK                     (0xFFFFU)
#define SIPI_CCRC2_CRCT_SHIFT                    (0U)
#define SIPI_CCRC2_CRCT_WIDTH                    (16U)
#define SIPI_CCRC2_CRCT(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC2_CRCT_SHIFT)) & SIPI_CCRC2_CRCT_MASK)

#define SIPI_CCRC2_CRCI_MASK                     (0xFFFF0000U)
#define SIPI_CCRC2_CRCI_SHIFT                    (16U)
#define SIPI_CCRC2_CRCI_WIDTH                    (16U)
#define SIPI_CCRC2_CRCI(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC2_CRCI_SHIFT)) & SIPI_CCRC2_CRCI_MASK)
/*! @} */

/*! @name CAR2 - SIPI Channel Address Register 2 */
/*! @{ */

#define SIPI_CAR2_CAR_MASK                       (0xFFFFFFFFU)
#define SIPI_CAR2_CAR_SHIFT                      (0U)
#define SIPI_CAR2_CAR_WIDTH                      (32U)
#define SIPI_CAR2_CAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CAR2_CAR_SHIFT)) & SIPI_CAR2_CAR_MASK)
/*! @} */

/*! @name CDR2 - SIPI Channel Data Register 2 */
/*! @{ */

#define SIPI_CDR2_CDR2_MASK                      (0xFFFFFFFFU)
#define SIPI_CDR2_CDR2_SHIFT                     (0U)
#define SIPI_CDR2_CDR2_WIDTH                     (32U)
#define SIPI_CDR2_CDR2(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CDR2_CDR2_SHIFT)) & SIPI_CDR2_CDR2_MASK)
/*! @} */

/*! @name CCR3 - SIPI Channel Control Register 3 */
/*! @{ */

#define SIPI_CCR3_DEN_MASK                       (0x1U)
#define SIPI_CCR3_DEN_SHIFT                      (0U)
#define SIPI_CCR3_DEN_WIDTH                      (1U)
#define SIPI_CCR3_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_DEN_SHIFT)) & SIPI_CCR3_DEN_MASK)

#define SIPI_CCR3_WRT_MASK                       (0x2U)
#define SIPI_CCR3_WRT_SHIFT                      (1U)
#define SIPI_CCR3_WRT_WIDTH                      (1U)
#define SIPI_CCR3_WRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_WRT_SHIFT)) & SIPI_CCR3_WRT_MASK)

#define SIPI_CCR3_RRT_MASK                       (0x4U)
#define SIPI_CCR3_RRT_SHIFT                      (2U)
#define SIPI_CCR3_RRT_WIDTH                      (1U)
#define SIPI_CCR3_RRT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_RRT_SHIFT)) & SIPI_CCR3_RRT_MASK)

#define SIPI_CCR3_IDT_MASK                       (0x8U)
#define SIPI_CCR3_IDT_SHIFT                      (3U)
#define SIPI_CCR3_IDT_WIDTH                      (1U)
#define SIPI_CCR3_IDT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_IDT_SHIFT)) & SIPI_CCR3_IDT_MASK)

#define SIPI_CCR3_CHEN_MASK                      (0x20U)
#define SIPI_CCR3_CHEN_SHIFT                     (5U)
#define SIPI_CCR3_CHEN_WIDTH                     (1U)
#define SIPI_CCR3_CHEN(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_CHEN_SHIFT)) & SIPI_CCR3_CHEN_MASK)

#define SIPI_CCR3_WL_MASK                        (0xC0U)
#define SIPI_CCR3_WL_SHIFT                       (6U)
#define SIPI_CCR3_WL_WIDTH                       (2U)
#define SIPI_CCR3_WL(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_WL_SHIFT)) & SIPI_CCR3_WL_MASK)

#define SIPI_CCR3_TC_MASK                        (0x10000U)
#define SIPI_CCR3_TC_SHIFT                       (16U)
#define SIPI_CCR3_TC_WIDTH                       (1U)
#define SIPI_CCR3_TC(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CCR3_TC_SHIFT)) & SIPI_CCR3_TC_MASK)
/*! @} */

/*! @name CSR3 - SIPI Channel Status Register 3 */
/*! @{ */

#define SIPI_CSR3_CB_MASK                        (0x4U)
#define SIPI_CSR3_CB_SHIFT                       (2U)
#define SIPI_CSR3_CB_WIDTH                       (1U)
#define SIPI_CSR3_CB(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_CSR3_CB_SHIFT)) & SIPI_CSR3_CB_MASK)

#define SIPI_CSR3_ACKR_MASK                      (0x8U)
#define SIPI_CSR3_ACKR_SHIFT                     (3U)
#define SIPI_CSR3_ACKR_WIDTH                     (1U)
#define SIPI_CSR3_ACKR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CSR3_ACKR_SHIFT)) & SIPI_CSR3_ACKR_MASK)

#define SIPI_CSR3_TID_MASK                       (0x70U)
#define SIPI_CSR3_TID_SHIFT                      (4U)
#define SIPI_CSR3_TID_WIDTH                      (3U)
#define SIPI_CSR3_TID(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR3_TID_SHIFT)) & SIPI_CSR3_TID_MASK)

#define SIPI_CSR3_RAR_MASK                       (0x80U)
#define SIPI_CSR3_RAR_SHIFT                      (7U)
#define SIPI_CSR3_RAR_WIDTH                      (1U)
#define SIPI_CSR3_RAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CSR3_RAR_SHIFT)) & SIPI_CSR3_RAR_MASK)

#define SIPI_CSR3_READ_RX_MASK                   (0x100U)
#define SIPI_CSR3_READ_RX_SHIFT                  (8U)
#define SIPI_CSR3_READ_RX_WIDTH                  (1U)
#define SIPI_CSR3_READ_RX(x)                     (((uint32_t)(((uint32_t)(x)) << SIPI_CSR3_READ_RX_SHIFT)) & SIPI_CSR3_READ_RX_MASK)

#define SIPI_CSR3_WRITE_RX_MASK                  (0x200U)
#define SIPI_CSR3_WRITE_RX_SHIFT                 (9U)
#define SIPI_CSR3_WRITE_RX_WIDTH                 (1U)
#define SIPI_CSR3_WRITE_RX(x)                    (((uint32_t)(((uint32_t)(x)) << SIPI_CSR3_WRITE_RX_SHIFT)) & SIPI_CSR3_WRITE_RX_MASK)
/*! @} */

/*! @name CIR3 - SIPI Channel Interrupt Register 3 */
/*! @{ */

#define SIPI_CIR3_ACKIE_MASK                     (0x1U)
#define SIPI_CIR3_ACKIE_SHIFT                    (0U)
#define SIPI_CIR3_ACKIE_WIDTH                    (1U)
#define SIPI_CIR3_ACKIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR3_ACKIE_SHIFT)) & SIPI_CIR3_ACKIE_MASK)

#define SIPI_CIR3_TIDIE_MASK                     (0x2U)
#define SIPI_CIR3_TIDIE_SHIFT                    (1U)
#define SIPI_CIR3_TIDIE_WIDTH                    (1U)
#define SIPI_CIR3_TIDIE(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CIR3_TIDIE_SHIFT)) & SIPI_CIR3_TIDIE_MASK)

#define SIPI_CIR3_TOIE_MASK                      (0x4U)
#define SIPI_CIR3_TOIE_SHIFT                     (2U)
#define SIPI_CIR3_TOIE_WIDTH                     (1U)
#define SIPI_CIR3_TOIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR3_TOIE_SHIFT)) & SIPI_CIR3_TOIE_MASK)

#define SIPI_CIR3_TCIE_MASK                      (0x8U)
#define SIPI_CIR3_TCIE_SHIFT                     (3U)
#define SIPI_CIR3_TCIE_WIDTH                     (1U)
#define SIPI_CIR3_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR3_TCIE_SHIFT)) & SIPI_CIR3_TCIE_MASK)

#define SIPI_CIR3_RAIE_MASK                      (0x10U)
#define SIPI_CIR3_RAIE_SHIFT                     (4U)
#define SIPI_CIR3_RAIE_WIDTH                     (1U)
#define SIPI_CIR3_RAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR3_RAIE_SHIFT)) & SIPI_CIR3_RAIE_MASK)

#define SIPI_CIR3_WAIE_MASK                      (0x20U)
#define SIPI_CIR3_WAIE_SHIFT                     (5U)
#define SIPI_CIR3_WAIE_WIDTH                     (1U)
#define SIPI_CIR3_WAIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CIR3_WAIE_SHIFT)) & SIPI_CIR3_WAIE_MASK)
/*! @} */

/*! @name CTOR3 - SIPI Channel Timeout Register 3 */
/*! @{ */

#define SIPI_CTOR3_TOR_MASK                      (0xFFFFFFFFU)
#define SIPI_CTOR3_TOR_SHIFT                     (0U)
#define SIPI_CTOR3_TOR_WIDTH                     (32U)
#define SIPI_CTOR3_TOR(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_CTOR3_TOR_SHIFT)) & SIPI_CTOR3_TOR_MASK)
/*! @} */

/*! @name CCRC3 - SIPI Channel CRC Register 3 */
/*! @{ */

#define SIPI_CCRC3_CRCT_MASK                     (0xFFFFU)
#define SIPI_CCRC3_CRCT_SHIFT                    (0U)
#define SIPI_CCRC3_CRCT_WIDTH                    (16U)
#define SIPI_CCRC3_CRCT(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC3_CRCT_SHIFT)) & SIPI_CCRC3_CRCT_MASK)

#define SIPI_CCRC3_CRCI_MASK                     (0xFFFF0000U)
#define SIPI_CCRC3_CRCI_SHIFT                    (16U)
#define SIPI_CCRC3_CRCI_WIDTH                    (16U)
#define SIPI_CCRC3_CRCI(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_CCRC3_CRCI_SHIFT)) & SIPI_CCRC3_CRCI_MASK)
/*! @} */

/*! @name CAR3 - SIPI Channel Address Register 3 */
/*! @{ */

#define SIPI_CAR3_CAR_MASK                       (0xFFFFFFFFU)
#define SIPI_CAR3_CAR_SHIFT                      (0U)
#define SIPI_CAR3_CAR_WIDTH                      (32U)
#define SIPI_CAR3_CAR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CAR3_CAR_SHIFT)) & SIPI_CAR3_CAR_MASK)
/*! @} */

/*! @name CDR3 - SIPI Channel Data Register 3 */
/*! @{ */

#define SIPI_CDR3_CDR_MASK                       (0xFFFFFFFFU)
#define SIPI_CDR3_CDR_SHIFT                      (0U)
#define SIPI_CDR3_CDR_WIDTH                      (32U)
#define SIPI_CDR3_CDR(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_CDR3_CDR_SHIFT)) & SIPI_CDR3_CDR_MASK)
/*! @} */

/*! @name MCR - SIPI Module Configuration Register */
/*! @{ */

#define SIPI_MCR_SR_MASK                         (0x1U)
#define SIPI_MCR_SR_SHIFT                        (0U)
#define SIPI_MCR_SR_WIDTH                        (1U)
#define SIPI_MCR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_SR_SHIFT)) & SIPI_MCR_SR_MASK)

#define SIPI_MCR_MOEN_MASK                       (0x2U)
#define SIPI_MCR_MOEN_SHIFT                      (1U)
#define SIPI_MCR_MOEN_WIDTH                      (1U)
#define SIPI_MCR_MOEN(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_MOEN_SHIFT)) & SIPI_MCR_MOEN_MASK)

#define SIPI_MCR_INIT_MASK                       (0x4U)
#define SIPI_MCR_INIT_SHIFT                      (2U)
#define SIPI_MCR_INIT_WIDTH                      (1U)
#define SIPI_MCR_INIT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_INIT_SHIFT)) & SIPI_MCR_INIT_MASK)

#define SIPI_MCR_TEN_MASK                        (0x8U)
#define SIPI_MCR_TEN_SHIFT                       (3U)
#define SIPI_MCR_TEN_WIDTH                       (1U)
#define SIPI_MCR_TEN(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_TEN_SHIFT)) & SIPI_MCR_TEN_MASK)

#define SIPI_MCR_CHNSB_MASK                      (0x10U)
#define SIPI_MCR_CHNSB_SHIFT                     (4U)
#define SIPI_MCR_CHNSB_WIDTH                     (1U)
#define SIPI_MCR_CHNSB(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_CHNSB_SHIFT)) & SIPI_MCR_CHNSB_MASK)

#define SIPI_MCR_LEGACY_MODE_BIT_MASK            (0x20U)
#define SIPI_MCR_LEGACY_MODE_BIT_SHIFT           (5U)
#define SIPI_MCR_LEGACY_MODE_BIT_WIDTH           (1U)
#define SIPI_MCR_LEGACY_MODE_BIT(x)              (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_LEGACY_MODE_BIT_SHIFT)) & SIPI_MCR_LEGACY_MODE_BIT_MASK)

#define SIPI_MCR_MCRIE_MASK                      (0x200U)
#define SIPI_MCR_MCRIE_SHIFT                     (9U)
#define SIPI_MCR_MCRIE_WIDTH                     (1U)
#define SIPI_MCR_MCRIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_MCRIE_SHIFT)) & SIPI_MCR_MCRIE_MASK)

#define SIPI_MCR_CRCIE_MASK                      (0x400U)
#define SIPI_MCR_CRCIE_SHIFT                     (10U)
#define SIPI_MCR_CRCIE_WIDTH                     (1U)
#define SIPI_MCR_CRCIE(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_CRCIE_SHIFT)) & SIPI_MCR_CRCIE_MASK)

#define SIPI_MCR_AID_MASK                        (0xC000U)
#define SIPI_MCR_AID_SHIFT                       (14U)
#define SIPI_MCR_AID_WIDTH                       (2U)
#define SIPI_MCR_AID(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_AID_SHIFT)) & SIPI_MCR_AID_MASK)

#define SIPI_MCR_PRSCLR_MASK                     (0x7FF0000U)
#define SIPI_MCR_PRSCLR_SHIFT                    (16U)
#define SIPI_MCR_PRSCLR_WIDTH                    (11U)
#define SIPI_MCR_PRSCLR(x)                       (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_PRSCLR_SHIFT)) & SIPI_MCR_PRSCLR_MASK)

#define SIPI_MCR_HALT_MASK                       (0x20000000U)
#define SIPI_MCR_HALT_SHIFT                      (29U)
#define SIPI_MCR_HALT_WIDTH                      (1U)
#define SIPI_MCR_HALT(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_HALT_SHIFT)) & SIPI_MCR_HALT_MASK)

#define SIPI_MCR_FRZ_MASK                        (0x80000000U)
#define SIPI_MCR_FRZ_SHIFT                       (31U)
#define SIPI_MCR_FRZ_WIDTH                       (1U)
#define SIPI_MCR_FRZ(x)                          (((uint32_t)(((uint32_t)(x)) << SIPI_MCR_FRZ_SHIFT)) & SIPI_MCR_FRZ_MASK)
/*! @} */

/*! @name SR - SIPI Status Register */
/*! @{ */

#define SIPI_SR_STATE_MASK                       (0xFU)
#define SIPI_SR_STATE_SHIFT                      (0U)
#define SIPI_SR_STATE_WIDTH                      (4U)
#define SIPI_SR_STATE(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_SR_STATE_SHIFT)) & SIPI_SR_STATE_MASK)

#define SIPI_SR_TE_MASK                          (0xF0U)
#define SIPI_SR_TE_SHIFT                         (4U)
#define SIPI_SR_TE_WIDTH                         (4U)
#define SIPI_SR_TE(x)                            (((uint32_t)(((uint32_t)(x)) << SIPI_SR_TE_SHIFT)) & SIPI_SR_TE_MASK)

#define SIPI_SR_FRAME_TX_MASK                    (0x100U)
#define SIPI_SR_FRAME_TX_SHIFT                   (8U)
#define SIPI_SR_FRAME_TX_WIDTH                   (1U)
#define SIPI_SR_FRAME_TX(x)                      (((uint32_t)(((uint32_t)(x)) << SIPI_SR_FRAME_TX_SHIFT)) & SIPI_SR_FRAME_TX_MASK)

#define SIPI_SR_MCR_MASK                         (0x200U)
#define SIPI_SR_MCR_SHIFT                        (9U)
#define SIPI_SR_MCR_WIDTH                        (1U)
#define SIPI_SR_MCR(x)                           (((uint32_t)(((uint32_t)(x)) << SIPI_SR_MCR_SHIFT)) & SIPI_SR_MCR_MASK)

#define SIPI_SR_GCRCE_MASK                       (0x400U)
#define SIPI_SR_GCRCE_SHIFT                      (10U)
#define SIPI_SR_GCRCE_WIDTH                      (1U)
#define SIPI_SR_GCRCE(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_SR_GCRCE_SHIFT)) & SIPI_SR_GCRCE_MASK)

#define SIPI_SR_ACK_TX_MASK                      (0x800U)
#define SIPI_SR_ACK_TX_SHIFT                     (11U)
#define SIPI_SR_ACK_TX_WIDTH                     (1U)
#define SIPI_SR_ACK_TX(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_SR_ACK_TX_SHIFT)) & SIPI_SR_ACK_TX_MASK)

#define SIPI_SR_READ_OK_TX_MASK                  (0x1000U)
#define SIPI_SR_READ_OK_TX_SHIFT                 (12U)
#define SIPI_SR_READ_OK_TX_WIDTH                 (1U)
#define SIPI_SR_READ_OK_TX(x)                    (((uint32_t)(((uint32_t)(x)) << SIPI_SR_READ_OK_TX_SHIFT)) & SIPI_SR_READ_OK_TX_MASK)

#define SIPI_SR_INVALID_FRAME_RX_MASK            (0x2000U)
#define SIPI_SR_INVALID_FRAME_RX_SHIFT           (13U)
#define SIPI_SR_INVALID_FRAME_RX_WIDTH           (1U)
#define SIPI_SR_INVALID_FRAME_RX(x)              (((uint32_t)(((uint32_t)(x)) << SIPI_SR_INVALID_FRAME_RX_SHIFT)) & SIPI_SR_INVALID_FRAME_RX_MASK)

#define SIPI_SR_LPMACK_MASK                      (0x40000000U)
#define SIPI_SR_LPMACK_SHIFT                     (30U)
#define SIPI_SR_LPMACK_WIDTH                     (1U)
#define SIPI_SR_LPMACK(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_SR_LPMACK_SHIFT)) & SIPI_SR_LPMACK_MASK)

#define SIPI_SR_FRZACK_MASK                      (0x80000000U)
#define SIPI_SR_FRZACK_SHIFT                     (31U)
#define SIPI_SR_FRZACK_WIDTH                     (1U)
#define SIPI_SR_FRZACK(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_SR_FRZACK_SHIFT)) & SIPI_SR_FRZACK_MASK)
/*! @} */

/*! @name MAXCR - SIPI Max Count Register */
/*! @{ */

#define SIPI_MAXCR_MXCNT_MASK                    (0xFFFFFFFCU)
#define SIPI_MAXCR_MXCNT_SHIFT                   (2U)
#define SIPI_MAXCR_MXCNT_WIDTH                   (30U)
#define SIPI_MAXCR_MXCNT(x)                      (((uint32_t)(((uint32_t)(x)) << SIPI_MAXCR_MXCNT_SHIFT)) & SIPI_MAXCR_MXCNT_MASK)
/*! @} */

/*! @name ARR - SIPI Address Reload Register */
/*! @{ */

#define SIPI_ARR_ADRLD_MASK                      (0xFFFFFFFCU)
#define SIPI_ARR_ADRLD_SHIFT                     (2U)
#define SIPI_ARR_ADRLD_WIDTH                     (30U)
#define SIPI_ARR_ADRLD(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ARR_ADRLD_SHIFT)) & SIPI_ARR_ADRLD_MASK)
/*! @} */

/*! @name ACR - SIPI Address Count Register */
/*! @{ */

#define SIPI_ACR_ADCNT_MASK                      (0xFFFFFFFCU)
#define SIPI_ACR_ADCNT_SHIFT                     (2U)
#define SIPI_ACR_ADCNT_WIDTH                     (30U)
#define SIPI_ACR_ADCNT(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ACR_ADCNT_SHIFT)) & SIPI_ACR_ADCNT_MASK)
/*! @} */

/*! @name ERR - SIPI Error Register */
/*! @{ */

#define SIPI_ERR_ACKE0_MASK                      (0x1U)
#define SIPI_ERR_ACKE0_SHIFT                     (0U)
#define SIPI_ERR_ACKE0_WIDTH                     (1U)
#define SIPI_ERR_ACKE0(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_ACKE0_SHIFT)) & SIPI_ERR_ACKE0_MASK)

#define SIPI_ERR_TIDE0_MASK                      (0x2U)
#define SIPI_ERR_TIDE0_SHIFT                     (1U)
#define SIPI_ERR_TIDE0_WIDTH                     (1U)
#define SIPI_ERR_TIDE0(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TIDE0_SHIFT)) & SIPI_ERR_TIDE0_MASK)

#define SIPI_ERR_TOE0_MASK                       (0x4U)
#define SIPI_ERR_TOE0_SHIFT                      (2U)
#define SIPI_ERR_TOE0_WIDTH                      (1U)
#define SIPI_ERR_TOE0(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TOE0_SHIFT)) & SIPI_ERR_TOE0_MASK)

#define SIPI_ERR_ACKE1_MASK                      (0x100U)
#define SIPI_ERR_ACKE1_SHIFT                     (8U)
#define SIPI_ERR_ACKE1_WIDTH                     (1U)
#define SIPI_ERR_ACKE1(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_ACKE1_SHIFT)) & SIPI_ERR_ACKE1_MASK)

#define SIPI_ERR_TIDE1_MASK                      (0x200U)
#define SIPI_ERR_TIDE1_SHIFT                     (9U)
#define SIPI_ERR_TIDE1_WIDTH                     (1U)
#define SIPI_ERR_TIDE1(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TIDE1_SHIFT)) & SIPI_ERR_TIDE1_MASK)

#define SIPI_ERR_TOE1_MASK                       (0x400U)
#define SIPI_ERR_TOE1_SHIFT                      (10U)
#define SIPI_ERR_TOE1_WIDTH                      (1U)
#define SIPI_ERR_TOE1(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TOE1_SHIFT)) & SIPI_ERR_TOE1_MASK)

#define SIPI_ERR_ACKE2_MASK                      (0x10000U)
#define SIPI_ERR_ACKE2_SHIFT                     (16U)
#define SIPI_ERR_ACKE2_WIDTH                     (1U)
#define SIPI_ERR_ACKE2(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_ACKE2_SHIFT)) & SIPI_ERR_ACKE2_MASK)

#define SIPI_ERR_TIDE2_MASK                      (0x20000U)
#define SIPI_ERR_TIDE2_SHIFT                     (17U)
#define SIPI_ERR_TIDE2_WIDTH                     (1U)
#define SIPI_ERR_TIDE2(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TIDE2_SHIFT)) & SIPI_ERR_TIDE2_MASK)

#define SIPI_ERR_TOE2_MASK                       (0x40000U)
#define SIPI_ERR_TOE2_SHIFT                      (18U)
#define SIPI_ERR_TOE2_WIDTH                      (1U)
#define SIPI_ERR_TOE2(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TOE2_SHIFT)) & SIPI_ERR_TOE2_MASK)

#define SIPI_ERR_ACKE3_MASK                      (0x1000000U)
#define SIPI_ERR_ACKE3_SHIFT                     (24U)
#define SIPI_ERR_ACKE3_WIDTH                     (1U)
#define SIPI_ERR_ACKE3(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_ACKE3_SHIFT)) & SIPI_ERR_ACKE3_MASK)

#define SIPI_ERR_TIDE3_MASK                      (0x2000000U)
#define SIPI_ERR_TIDE3_SHIFT                     (25U)
#define SIPI_ERR_TIDE3_WIDTH                     (1U)
#define SIPI_ERR_TIDE3(x)                        (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TIDE3_SHIFT)) & SIPI_ERR_TIDE3_MASK)

#define SIPI_ERR_TOE3_MASK                       (0x4000000U)
#define SIPI_ERR_TOE3_SHIFT                      (26U)
#define SIPI_ERR_TOE3_WIDTH                      (1U)
#define SIPI_ERR_TOE3(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_ERR_TOE3_SHIFT)) & SIPI_ERR_TOE3_MASK)
/*! @} */

/*! @name DEBUG - SIPI Debug Register */
/*! @{ */

#define SIPI_DEBUG_STATE_MASK                    (0xFFFFU)
#define SIPI_DEBUG_STATE_SHIFT                   (0U)
#define SIPI_DEBUG_STATE_WIDTH                   (16U)
#define SIPI_DEBUG_STATE(x)                      (((uint32_t)(((uint32_t)(x)) << SIPI_DEBUG_STATE_SHIFT)) & SIPI_DEBUG_STATE_MASK)

#define SIPI_DEBUG_OUTSTANDING_MASK              (0xF0000U)
#define SIPI_DEBUG_OUTSTANDING_SHIFT             (16U)
#define SIPI_DEBUG_OUTSTANDING_WIDTH             (4U)
#define SIPI_DEBUG_OUTSTANDING(x)                (((uint32_t)(((uint32_t)(x)) << SIPI_DEBUG_OUTSTANDING_SHIFT)) & SIPI_DEBUG_OUTSTANDING_MASK)
/*! @} */

/*! @name PMR - SIPI Performance Monitor register */
/*! @{ */

#define SIPI_PMR_BIN0_MASK                       (0xFFU)
#define SIPI_PMR_BIN0_SHIFT                      (0U)
#define SIPI_PMR_BIN0_WIDTH                      (8U)
#define SIPI_PMR_BIN0(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_PMR_BIN0_SHIFT)) & SIPI_PMR_BIN0_MASK)

#define SIPI_PMR_BIN1_MASK                       (0xFF00U)
#define SIPI_PMR_BIN1_SHIFT                      (8U)
#define SIPI_PMR_BIN1_WIDTH                      (8U)
#define SIPI_PMR_BIN1(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_PMR_BIN1_SHIFT)) & SIPI_PMR_BIN1_MASK)

#define SIPI_PMR_BIN2_MASK                       (0xFF0000U)
#define SIPI_PMR_BIN2_SHIFT                      (16U)
#define SIPI_PMR_BIN2_WIDTH                      (8U)
#define SIPI_PMR_BIN2(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_PMR_BIN2_SHIFT)) & SIPI_PMR_BIN2_MASK)

#define SIPI_PMR_BIN3_MASK                       (0xFF000000U)
#define SIPI_PMR_BIN3_SHIFT                      (24U)
#define SIPI_PMR_BIN3_WIDTH                      (8U)
#define SIPI_PMR_BIN3(x)                         (((uint32_t)(((uint32_t)(x)) << SIPI_PMR_BIN3_SHIFT)) & SIPI_PMR_BIN3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SIPI_Register_Masks */

/*!
 * @}
 */ /* end of group SIPI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SIPI_H_) */
