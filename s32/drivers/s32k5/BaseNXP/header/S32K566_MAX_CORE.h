/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MAX_CORE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MAX_CORE
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
#if !defined(S32K566_MAX_CORE_H_)  /* Check if memory map has not been already included */
#define S32K566_MAX_CORE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MAX_CORE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAX_CORE_Peripheral_Access_Layer MAX_CORE Peripheral Access Layer
 * @{
 */

/** MAX_CORE - Size of Registers Arrays */
#define MAX_CORE_PORT_COUNT                       8u

/** MAX_CORE - Register Layout Typedef */
typedef struct MAX_CORE_Struct {
  struct MAX_CORE_PORT {                           /* offset: 0x0, array step: 0x100 */
    __IO uint32_t PRS;                               /**< Priority Slave Registers, array offset: 0x0, array step: 0x100 */
    uint8_t RESERVED_0[12];
    __IO uint32_t CRS;                               /**< Control Register, array offset: 0x10, array step: 0x100 */
    uint8_t RESERVED_1[236];
  } PORT[MAX_CORE_PORT_COUNT];
  __IO uint32_t MGPCR0;                            /**< Master General Purpose Control Register, offset: 0x800 */
  uint8_t RESERVED_0[252];
  __IO uint32_t MGPCR1;                            /**< Master General Purpose Control Register, offset: 0x900 */
  uint8_t RESERVED_1[252];
  __IO uint32_t MGPCR2;                            /**< Master General Purpose Control Register, offset: 0xA00 */
  uint8_t RESERVED_2[252];
  __IO uint32_t MGPCR3;                            /**< Master General Purpose Control Register, offset: 0xB00 */
  uint8_t RESERVED_3[252];
  __IO uint32_t MGPCR4;                            /**< Master General Purpose Control Register, offset: 0xC00 */
  uint8_t RESERVED_4[252];
  __IO uint32_t MGPCR5;                            /**< Master General Purpose Control Register, offset: 0xD00 */
  uint8_t RESERVED_5[252];
  __IO uint32_t MGPCR6;                            /**< Master General Purpose Control Register, offset: 0xE00 */
} MAX_CORE_Type, *MAX_CORE_MemMapPtr;

/** Number of instances of the MAX_CORE module. */
#define MAX_CORE_INSTANCE_COUNT                  (1u)

/* MAX_CORE - Peripheral instance base addresses */
/** Peripheral AXBS_PER base address */
#define IP_AXBS_PER_BASE                         (0x40408000u)
/** Peripheral AXBS_PER base pointer */
#define IP_AXBS_PER                              ((MAX_CORE_Type *)IP_AXBS_PER_BASE)
/** Array initializer of MAX_CORE peripheral base addresses */
#define IP_MAX_CORE_BASE_ADDRS                   { IP_AXBS_PER_BASE }
/** Array initializer of MAX_CORE peripheral base pointers */
#define IP_MAX_CORE_BASE_PTRS                    { IP_AXBS_PER }

/* ----------------------------------------------------------------------------
   -- MAX_CORE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAX_CORE_Register_Masks MAX_CORE Register Masks
 * @{
 */

/*! @name PRS - Priority Slave Registers */
/*! @{ */

#define MAX_CORE_PRS_M0_MASK                     (0x7U)
#define MAX_CORE_PRS_M0_SHIFT                    (0U)
#define MAX_CORE_PRS_M0_WIDTH                    (3U)
#define MAX_CORE_PRS_M0(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M0_SHIFT)) & MAX_CORE_PRS_M0_MASK)

#define MAX_CORE_PRS_M1_MASK                     (0x70U)
#define MAX_CORE_PRS_M1_SHIFT                    (4U)
#define MAX_CORE_PRS_M1_WIDTH                    (3U)
#define MAX_CORE_PRS_M1(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M1_SHIFT)) & MAX_CORE_PRS_M1_MASK)

#define MAX_CORE_PRS_M2_MASK                     (0x700U)
#define MAX_CORE_PRS_M2_SHIFT                    (8U)
#define MAX_CORE_PRS_M2_WIDTH                    (3U)
#define MAX_CORE_PRS_M2(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M2_SHIFT)) & MAX_CORE_PRS_M2_MASK)

#define MAX_CORE_PRS_M3_MASK                     (0x7000U)
#define MAX_CORE_PRS_M3_SHIFT                    (12U)
#define MAX_CORE_PRS_M3_WIDTH                    (3U)
#define MAX_CORE_PRS_M3(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M3_SHIFT)) & MAX_CORE_PRS_M3_MASK)

#define MAX_CORE_PRS_M4_MASK                     (0x70000U)
#define MAX_CORE_PRS_M4_SHIFT                    (16U)
#define MAX_CORE_PRS_M4_WIDTH                    (3U)
#define MAX_CORE_PRS_M4(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M4_SHIFT)) & MAX_CORE_PRS_M4_MASK)

#define MAX_CORE_PRS_M5_MASK                     (0x700000U)
#define MAX_CORE_PRS_M5_SHIFT                    (20U)
#define MAX_CORE_PRS_M5_WIDTH                    (3U)
#define MAX_CORE_PRS_M5(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M5_SHIFT)) & MAX_CORE_PRS_M5_MASK)

#define MAX_CORE_PRS_M6_MASK                     (0x7000000U)
#define MAX_CORE_PRS_M6_SHIFT                    (24U)
#define MAX_CORE_PRS_M6_WIDTH                    (3U)
#define MAX_CORE_PRS_M6(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_PRS_M6_SHIFT)) & MAX_CORE_PRS_M6_MASK)
/*! @} */

/*! @name CRS - Control Register */
/*! @{ */

#define MAX_CORE_CRS_PARK_MASK                   (0x7U)
#define MAX_CORE_CRS_PARK_SHIFT                  (0U)
#define MAX_CORE_CRS_PARK_WIDTH                  (3U)
#define MAX_CORE_CRS_PARK(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_PARK_SHIFT)) & MAX_CORE_CRS_PARK_MASK)

#define MAX_CORE_CRS_PCTL_MASK                   (0x30U)
#define MAX_CORE_CRS_PCTL_SHIFT                  (4U)
#define MAX_CORE_CRS_PCTL_WIDTH                  (2U)
#define MAX_CORE_CRS_PCTL(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_PCTL_SHIFT)) & MAX_CORE_CRS_PCTL_MASK)

#define MAX_CORE_CRS_ARB_MASK                    (0x300U)
#define MAX_CORE_CRS_ARB_SHIFT                   (8U)
#define MAX_CORE_CRS_ARB_WIDTH                   (2U)
#define MAX_CORE_CRS_ARB(x)                      (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_ARB_SHIFT)) & MAX_CORE_CRS_ARB_MASK)

#define MAX_CORE_CRS_HPE0_MASK                   (0x10000U)
#define MAX_CORE_CRS_HPE0_SHIFT                  (16U)
#define MAX_CORE_CRS_HPE0_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE0(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE0_SHIFT)) & MAX_CORE_CRS_HPE0_MASK)

#define MAX_CORE_CRS_HPE1_MASK                   (0x20000U)
#define MAX_CORE_CRS_HPE1_SHIFT                  (17U)
#define MAX_CORE_CRS_HPE1_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE1(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE1_SHIFT)) & MAX_CORE_CRS_HPE1_MASK)

#define MAX_CORE_CRS_HPE2_MASK                   (0x40000U)
#define MAX_CORE_CRS_HPE2_SHIFT                  (18U)
#define MAX_CORE_CRS_HPE2_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE2(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE2_SHIFT)) & MAX_CORE_CRS_HPE2_MASK)

#define MAX_CORE_CRS_HPE3_MASK                   (0x80000U)
#define MAX_CORE_CRS_HPE3_SHIFT                  (19U)
#define MAX_CORE_CRS_HPE3_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE3(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE3_SHIFT)) & MAX_CORE_CRS_HPE3_MASK)

#define MAX_CORE_CRS_HPE4_MASK                   (0x100000U)
#define MAX_CORE_CRS_HPE4_SHIFT                  (20U)
#define MAX_CORE_CRS_HPE4_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE4(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE4_SHIFT)) & MAX_CORE_CRS_HPE4_MASK)

#define MAX_CORE_CRS_HPE5_MASK                   (0x200000U)
#define MAX_CORE_CRS_HPE5_SHIFT                  (21U)
#define MAX_CORE_CRS_HPE5_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE5(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE5_SHIFT)) & MAX_CORE_CRS_HPE5_MASK)

#define MAX_CORE_CRS_HPE6_MASK                   (0x400000U)
#define MAX_CORE_CRS_HPE6_SHIFT                  (22U)
#define MAX_CORE_CRS_HPE6_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE6(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE6_SHIFT)) & MAX_CORE_CRS_HPE6_MASK)

#define MAX_CORE_CRS_HPE7_MASK                   (0x800000U)
#define MAX_CORE_CRS_HPE7_SHIFT                  (23U)
#define MAX_CORE_CRS_HPE7_WIDTH                  (1U)
#define MAX_CORE_CRS_HPE7(x)                     (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HPE7_SHIFT)) & MAX_CORE_CRS_HPE7_MASK)

#define MAX_CORE_CRS_HLP_MASK                    (0x40000000U)
#define MAX_CORE_CRS_HLP_SHIFT                   (30U)
#define MAX_CORE_CRS_HLP_WIDTH                   (1U)
#define MAX_CORE_CRS_HLP(x)                      (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_HLP_SHIFT)) & MAX_CORE_CRS_HLP_MASK)

#define MAX_CORE_CRS_RO_MASK                     (0x80000000U)
#define MAX_CORE_CRS_RO_SHIFT                    (31U)
#define MAX_CORE_CRS_RO_WIDTH                    (1U)
#define MAX_CORE_CRS_RO(x)                       (((uint32_t)(((uint32_t)(x)) << MAX_CORE_CRS_RO_SHIFT)) & MAX_CORE_CRS_RO_MASK)
/*! @} */

/*! @name MGPCR0 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR0_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR0_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR0_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR0_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR0_AULB_SHIFT)) & MAX_CORE_MGPCR0_AULB_MASK)
/*! @} */

/*! @name MGPCR1 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR1_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR1_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR1_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR1_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR1_AULB_SHIFT)) & MAX_CORE_MGPCR1_AULB_MASK)
/*! @} */

/*! @name MGPCR2 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR2_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR2_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR2_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR2_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR2_AULB_SHIFT)) & MAX_CORE_MGPCR2_AULB_MASK)
/*! @} */

/*! @name MGPCR3 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR3_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR3_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR3_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR3_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR3_AULB_SHIFT)) & MAX_CORE_MGPCR3_AULB_MASK)
/*! @} */

/*! @name MGPCR4 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR4_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR4_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR4_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR4_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR4_AULB_SHIFT)) & MAX_CORE_MGPCR4_AULB_MASK)
/*! @} */

/*! @name MGPCR5 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR5_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR5_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR5_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR5_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR5_AULB_SHIFT)) & MAX_CORE_MGPCR5_AULB_MASK)
/*! @} */

/*! @name MGPCR6 - Master General Purpose Control Register */
/*! @{ */

#define MAX_CORE_MGPCR6_AULB_MASK                (0x7U)
#define MAX_CORE_MGPCR6_AULB_SHIFT               (0U)
#define MAX_CORE_MGPCR6_AULB_WIDTH               (3U)
#define MAX_CORE_MGPCR6_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << MAX_CORE_MGPCR6_AULB_SHIFT)) & MAX_CORE_MGPCR6_AULB_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MAX_CORE_Register_Masks */

/*!
 * @}
 */ /* end of group MAX_CORE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MAX_CORE_H_) */
