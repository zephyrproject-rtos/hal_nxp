/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_AXBS.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_AXBS
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
#if !defined(S32Z2_AXBS_H_)  /* Check if memory map has not been already included */
#define S32Z2_AXBS_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- AXBS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Peripheral_Access_Layer AXBS Peripheral Access Layer
 * @{
 */

/** AXBS - Size of Registers Arrays */
#define AXBS_PORT_COUNT                           8u

/** AXBS - Register Layout Typedef */
typedef struct {
  struct AXBS_PORT {                               /* offset: 0x0, array step: 0x100 */
    __IO uint32_t PRS;                               /**< Priority Slave Registers, array offset: 0x0, array step: 0x100, irregular array, not all indices are valid */
    uint8_t RESERVED_0[12];
    __IO uint32_t CRS;                               /**< Control Register, array offset: 0x10, array step: 0x100, irregular array, not all indices are valid */
    uint8_t RESERVED_1[236];
  } PORT[AXBS_PORT_COUNT];
  __IO uint32_t MGPCR0;                            /**< Master General Purpose Control Register, offset: 0x800 */
  uint8_t RESERVED_0[252];
  __IO uint32_t MGPCR1;                            /**< Master General Purpose Control Register, offset: 0x900 */
  uint8_t RESERVED_1[252];
  __IO uint32_t MGPCR2;                            /**< Master General Purpose Control Register, offset: 0xA00 */
  uint8_t RESERVED_2[252];
  __IO uint32_t MGPCR3;                            /**< Master General Purpose Control Register, offset: 0xB00 */
  uint8_t RESERVED_3[252];
  __IO uint32_t MGPCR4;                            /**< Master General Purpose Control Register, offset: 0xC00, available only on: CE_AXBS (missing on SMU.AXBS/SMU__AXBS) */
  uint8_t RESERVED_4[252];
  __IO uint32_t MGPCR5;                            /**< Master General Purpose Control Register, offset: 0xD00, available only on: CE_AXBS (missing on SMU.AXBS/SMU__AXBS) */
} AXBS_Type, *AXBS_MemMapPtr;

/** Number of instances of the AXBS module. */
#define AXBS_INSTANCE_COUNT                      (2u)

/* AXBS - Peripheral instance base addresses */
/** Peripheral CE_AXBS base address */
#define IP_CE_AXBS_BASE                          (0x44860000u)
/** Peripheral CE_AXBS base pointer */
#define IP_CE_AXBS                               ((AXBS_Type *)IP_CE_AXBS_BASE)
/** Peripheral SMU__AXBS base address */
#define IP_SMU__AXBS_BASE                        (0x45060000u)
/** Peripheral SMU__AXBS base pointer */
#define IP_SMU__AXBS                             ((AXBS_Type *)IP_SMU__AXBS_BASE)
/** Array initializer of AXBS peripheral base addresses */
#define IP_AXBS_BASE_ADDRS                       { IP_CE_AXBS_BASE, IP_SMU__AXBS_BASE }
/** Array initializer of AXBS peripheral base pointers */
#define IP_AXBS_BASE_PTRS                        { IP_CE_AXBS, IP_SMU__AXBS }

/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/*! @name PRS - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS_M0_MASK                         (0x7U)
#define AXBS_PRS_M0_SHIFT                        (0U)
#define AXBS_PRS_M0_WIDTH                        (3U)
#define AXBS_PRS_M0(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M0_SHIFT)) & AXBS_PRS_M0_MASK)

#define AXBS_PRS_M1_MASK                         (0x70U)
#define AXBS_PRS_M1_SHIFT                        (4U)
#define AXBS_PRS_M1_WIDTH                        (3U)
#define AXBS_PRS_M1(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M1_SHIFT)) & AXBS_PRS_M1_MASK)

#define AXBS_PRS_M2_MASK                         (0x700U)
#define AXBS_PRS_M2_SHIFT                        (8U)
#define AXBS_PRS_M2_WIDTH                        (3U)
#define AXBS_PRS_M2(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M2_SHIFT)) & AXBS_PRS_M2_MASK)

#define AXBS_PRS_M3_MASK                         (0x7000U)
#define AXBS_PRS_M3_SHIFT                        (12U)
#define AXBS_PRS_M3_WIDTH                        (3U)
#define AXBS_PRS_M3(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M3_SHIFT)) & AXBS_PRS_M3_MASK)

#define AXBS_PRS_M4_MASK                         (0x70000U)
#define AXBS_PRS_M4_SHIFT                        (16U)
#define AXBS_PRS_M4_WIDTH                        (3U)
#define AXBS_PRS_M4(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M4_SHIFT)) & AXBS_PRS_M4_MASK)

#define AXBS_PRS_M5_MASK                         (0x700000U)
#define AXBS_PRS_M5_SHIFT                        (20U)
#define AXBS_PRS_M5_WIDTH                        (3U)
#define AXBS_PRS_M5(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M5_SHIFT)) & AXBS_PRS_M5_MASK)
/*! @} */

/*! @name CRS - Control Register */
/*! @{ */

#define AXBS_CRS_PARK_MASK                       (0x7U)
#define AXBS_CRS_PARK_SHIFT                      (0U)
#define AXBS_CRS_PARK_WIDTH                      (3U)
#define AXBS_CRS_PARK(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_PARK_SHIFT)) & AXBS_CRS_PARK_MASK)

#define AXBS_CRS_PCTL_MASK                       (0x30U)
#define AXBS_CRS_PCTL_SHIFT                      (4U)
#define AXBS_CRS_PCTL_WIDTH                      (2U)
#define AXBS_CRS_PCTL(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_PCTL_SHIFT)) & AXBS_CRS_PCTL_MASK)

#define AXBS_CRS_ARB_MASK                        (0x300U)
#define AXBS_CRS_ARB_SHIFT                       (8U)
#define AXBS_CRS_ARB_WIDTH                       (2U)
#define AXBS_CRS_ARB(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_ARB_SHIFT)) & AXBS_CRS_ARB_MASK)

#define AXBS_CRS_HPE0_MASK                       (0x10000U)
#define AXBS_CRS_HPE0_SHIFT                      (16U)
#define AXBS_CRS_HPE0_WIDTH                      (1U)
#define AXBS_CRS_HPE0(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE0_SHIFT)) & AXBS_CRS_HPE0_MASK)

#define AXBS_CRS_HPE1_MASK                       (0x20000U)
#define AXBS_CRS_HPE1_SHIFT                      (17U)
#define AXBS_CRS_HPE1_WIDTH                      (1U)
#define AXBS_CRS_HPE1(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE1_SHIFT)) & AXBS_CRS_HPE1_MASK)

#define AXBS_CRS_HPE2_MASK                       (0x40000U)
#define AXBS_CRS_HPE2_SHIFT                      (18U)
#define AXBS_CRS_HPE2_WIDTH                      (1U)
#define AXBS_CRS_HPE2(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE2_SHIFT)) & AXBS_CRS_HPE2_MASK)

#define AXBS_CRS_HPE3_MASK                       (0x80000U)
#define AXBS_CRS_HPE3_SHIFT                      (19U)
#define AXBS_CRS_HPE3_WIDTH                      (1U)
#define AXBS_CRS_HPE3(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE3_SHIFT)) & AXBS_CRS_HPE3_MASK)

#define AXBS_CRS_HPE4_MASK                       (0x100000U)
#define AXBS_CRS_HPE4_SHIFT                      (20U)
#define AXBS_CRS_HPE4_WIDTH                      (1U)
#define AXBS_CRS_HPE4(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE4_SHIFT)) & AXBS_CRS_HPE4_MASK)

#define AXBS_CRS_HPE5_MASK                       (0x200000U)
#define AXBS_CRS_HPE5_SHIFT                      (21U)
#define AXBS_CRS_HPE5_WIDTH                      (1U)
#define AXBS_CRS_HPE5(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE5_SHIFT)) & AXBS_CRS_HPE5_MASK)

#define AXBS_CRS_HPE6_MASK                       (0x400000U)
#define AXBS_CRS_HPE6_SHIFT                      (22U)
#define AXBS_CRS_HPE6_WIDTH                      (1U)
#define AXBS_CRS_HPE6(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE6_SHIFT)) & AXBS_CRS_HPE6_MASK)

#define AXBS_CRS_HPE7_MASK                       (0x800000U)
#define AXBS_CRS_HPE7_SHIFT                      (23U)
#define AXBS_CRS_HPE7_WIDTH                      (1U)
#define AXBS_CRS_HPE7(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE7_SHIFT)) & AXBS_CRS_HPE7_MASK)

#define AXBS_CRS_HLP_MASK                        (0x40000000U)
#define AXBS_CRS_HLP_SHIFT                       (30U)
#define AXBS_CRS_HLP_WIDTH                       (1U)
#define AXBS_CRS_HLP(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HLP_SHIFT)) & AXBS_CRS_HLP_MASK)

#define AXBS_CRS_RO_MASK                         (0x80000000U)
#define AXBS_CRS_RO_SHIFT                        (31U)
#define AXBS_CRS_RO_WIDTH                        (1U)
#define AXBS_CRS_RO(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_RO_SHIFT)) & AXBS_CRS_RO_MASK)
/*! @} */

/*! @name MGPCR0 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR0_AULB_MASK                    (0x7U)
#define AXBS_MGPCR0_AULB_SHIFT                   (0U)
#define AXBS_MGPCR0_AULB_WIDTH                   (3U)
#define AXBS_MGPCR0_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR0_AULB_SHIFT)) & AXBS_MGPCR0_AULB_MASK)
/*! @} */

/*! @name MGPCR1 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR1_AULB_MASK                    (0x7U)
#define AXBS_MGPCR1_AULB_SHIFT                   (0U)
#define AXBS_MGPCR1_AULB_WIDTH                   (3U)
#define AXBS_MGPCR1_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR1_AULB_SHIFT)) & AXBS_MGPCR1_AULB_MASK)
/*! @} */

/*! @name MGPCR2 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR2_AULB_MASK                    (0x7U)
#define AXBS_MGPCR2_AULB_SHIFT                   (0U)
#define AXBS_MGPCR2_AULB_WIDTH                   (3U)
#define AXBS_MGPCR2_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR2_AULB_SHIFT)) & AXBS_MGPCR2_AULB_MASK)
/*! @} */

/*! @name MGPCR3 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR3_AULB_MASK                    (0x7U)
#define AXBS_MGPCR3_AULB_SHIFT                   (0U)
#define AXBS_MGPCR3_AULB_WIDTH                   (3U)
#define AXBS_MGPCR3_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR3_AULB_SHIFT)) & AXBS_MGPCR3_AULB_MASK)
/*! @} */

/*! @name MGPCR4 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR4_AULB_MASK                    (0x7U)
#define AXBS_MGPCR4_AULB_SHIFT                   (0U)
#define AXBS_MGPCR4_AULB_WIDTH                   (3U)
#define AXBS_MGPCR4_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR4_AULB_SHIFT)) & AXBS_MGPCR4_AULB_MASK)
/*! @} */

/*! @name MGPCR5 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR5_AULB_MASK                    (0x7U)
#define AXBS_MGPCR5_AULB_SHIFT                   (0U)
#define AXBS_MGPCR5_AULB_WIDTH                   (3U)
#define AXBS_MGPCR5_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR5_AULB_SHIFT)) & AXBS_MGPCR5_AULB_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group AXBS_Register_Masks */

/*!
 * @}
 */ /* end of group AXBS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_AXBS_H_) */
