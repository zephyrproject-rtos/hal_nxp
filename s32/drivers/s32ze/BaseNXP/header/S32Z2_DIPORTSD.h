/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DIPORTSD.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DIPORTSD
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
#if !defined(S32Z2_DIPORTSD_H_)  /* Check if memory map has not been already included */
#define S32Z2_DIPORTSD_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DIPORTSD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIPORTSD_Peripheral_Access_Layer DIPORTSD Peripheral Access Layer
 * @{
 */

/** DIPORTSD - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[256];
  __IO uint32_t ECR;                               /**< Error and Control Register, offset: 0x100 */
  __IO uint32_t SESR;                              /**< Error Status Register, offset: 0x104 */
  __IO uint32_t QOS;                               /**< Quality Of Service, offset: 0x108 */
  __IO uint32_t SIGEN;                             /**< Signaling Enable, offset: 0x10C */
  uint8_t RESERVED_1[8];
       uint32_t RSRV0;                             /**< Reserved 0, offset: 0x118 */
  uint8_t RESERVED_2[12];
  __IO uint32_t LAR0;                              /**< Logical Address Region 0, offset: 0x128 */
  __IO uint32_t PAR0;                              /**< Physical Address Region 0, offset: 0x12C */
  __IO uint32_t RS0;                               /**< Region Size 0, offset: 0x130 */
  __IO uint32_t LAR1;                              /**< Logical Address Region 1, offset: 0x134 */
  __IO uint32_t PAR1;                              /**< Physical Address Region 1, offset: 0x138 */
  __IO uint32_t RS1;                               /**< Region Size 1, offset: 0x13C */
  __IO uint32_t LAR2;                              /**< Logical Address Region 2, offset: 0x140 */
  __IO uint32_t PAR2;                              /**< Physical Address Region 2, offset: 0x144 */
  __IO uint32_t RS2;                               /**< Region Size 2, offset: 0x148 */
  __IO uint32_t LAR3;                              /**< Logical Address Region 3, offset: 0x14C */
  __IO uint32_t PAR3;                              /**< Physical Address Region 3, offset: 0x150 */
  __IO uint32_t RS3;                               /**< Region Size 3, offset: 0x154 */
  __IO uint32_t LAR4;                              /**< Logical Address Region 4, offset: 0x158 */
  __IO uint32_t PAR4;                              /**< Physical Address Region 4, offset: 0x15C */
  __IO uint32_t RS4;                               /**< Region Size 4, offset: 0x160 */
  __IO uint32_t LAR5;                              /**< Logical Address Region 5, offset: 0x164 */
  __IO uint32_t PAR5;                              /**< Physical Address Region 5, offset: 0x168 */
  __IO uint32_t RS5;                               /**< Region Size 5, offset: 0x16C */
  __IO uint32_t LAR6;                              /**< Logical Address Region 6, offset: 0x170 */
  __IO uint32_t PAR6;                              /**< Physical Address Region 6, offset: 0x174 */
  __IO uint32_t RS6;                               /**< Region Size 6, offset: 0x178 */
  __IO uint32_t LAR7;                              /**< Logical Address Region 7, offset: 0x17C */
  __IO uint32_t PAR7;                              /**< Physical Address Region 7, offset: 0x180 */
  __IO uint32_t RS7;                               /**< Region Size 7, offset: 0x184 */
  uint8_t RESERVED_3[120];
       uint32_t RSRV1;                             /**< Reserved 1, offset: 0x200 */
       uint32_t RSRV2;                             /**< Reserved 2, offset: 0x204 */
       uint32_t RSRV3;                             /**< Reserved 3, offset: 0x208 */
       uint32_t RSRV4;                             /**< Reserved 4, offset: 0x20C */
       uint32_t RSRV5;                             /**< Reserved 5, offset: 0x210 */
} DIPORTSD_Type, *DIPORTSD_MemMapPtr;

/** Number of instances of the DIPORTSD module. */
#define DIPORTSD_INSTANCE_COUNT                  (1u)

/* DIPORTSD - Peripheral instance base addresses */
/** Peripheral DIPORTSD base address */
#define IP_DIPORTSD_BASE                         (0x42960000u)
/** Peripheral DIPORTSD base pointer */
#define IP_DIPORTSD                              ((DIPORTSD_Type *)IP_DIPORTSD_BASE)
/** Array initializer of DIPORTSD peripheral base addresses */
#define IP_DIPORTSD_BASE_ADDRS                   { IP_DIPORTSD_BASE }
/** Array initializer of DIPORTSD peripheral base pointers */
#define IP_DIPORTSD_BASE_PTRS                    { IP_DIPORTSD }

/* ----------------------------------------------------------------------------
   -- DIPORTSD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIPORTSD_Register_Masks DIPORTSD Register Masks
 * @{
 */

/*! @name ECR - Error and Control Register */
/*! @{ */

#define DIPORTSD_ECR_NCRC_ERR_EN_MASK            (0x1U)
#define DIPORTSD_ECR_NCRC_ERR_EN_SHIFT           (0U)
#define DIPORTSD_ECR_NCRC_ERR_EN_WIDTH           (1U)
#define DIPORTSD_ECR_NCRC_ERR_EN(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_NCRC_ERR_EN_SHIFT)) & DIPORTSD_ECR_NCRC_ERR_EN_MASK)

#define DIPORTSD_ECR_MFRM_ERR_EN_MASK            (0x2U)
#define DIPORTSD_ECR_MFRM_ERR_EN_SHIFT           (1U)
#define DIPORTSD_ECR_MFRM_ERR_EN_WIDTH           (1U)
#define DIPORTSD_ECR_MFRM_ERR_EN(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_MFRM_ERR_EN_SHIFT)) & DIPORTSD_ECR_MFRM_ERR_EN_MASK)

#define DIPORTSD_ECR_MID_ERR_EN_MASK             (0x4U)
#define DIPORTSD_ECR_MID_ERR_EN_SHIFT            (2U)
#define DIPORTSD_ECR_MID_ERR_EN_WIDTH            (1U)
#define DIPORTSD_ECR_MID_ERR_EN(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_MID_ERR_EN_SHIFT)) & DIPORTSD_ECR_MID_ERR_EN_MASK)

#define DIPORTSD_ECR_MPRC_ERR_EN_MASK            (0x8U)
#define DIPORTSD_ECR_MPRC_ERR_EN_SHIFT           (3U)
#define DIPORTSD_ECR_MPRC_ERR_EN_WIDTH           (1U)
#define DIPORTSD_ECR_MPRC_ERR_EN(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_MPRC_ERR_EN_SHIFT)) & DIPORTSD_ECR_MPRC_ERR_EN_MASK)

#define DIPORTSD_ECR_MADD_ERR_EN_MASK            (0x10U)
#define DIPORTSD_ECR_MADD_ERR_EN_SHIFT           (4U)
#define DIPORTSD_ECR_MADD_ERR_EN_WIDTH           (1U)
#define DIPORTSD_ECR_MADD_ERR_EN(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_MADD_ERR_EN_SHIFT)) & DIPORTSD_ECR_MADD_ERR_EN_MASK)

#define DIPORTSD_ECR_RSP_ERR_EN_MASK             (0x20U)
#define DIPORTSD_ECR_RSP_ERR_EN_SHIFT            (5U)
#define DIPORTSD_ECR_RSP_ERR_EN_WIDTH            (1U)
#define DIPORTSD_ECR_RSP_ERR_EN(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_RSP_ERR_EN_SHIFT)) & DIPORTSD_ECR_RSP_ERR_EN_MASK)

#define DIPORTSD_ECR_REG_LOCK_MASK               (0x80000000U)
#define DIPORTSD_ECR_REG_LOCK_SHIFT              (31U)
#define DIPORTSD_ECR_REG_LOCK_WIDTH              (1U)
#define DIPORTSD_ECR_REG_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << DIPORTSD_ECR_REG_LOCK_SHIFT)) & DIPORTSD_ECR_REG_LOCK_MASK)
/*! @} */

/*! @name SESR - Error Status Register */
/*! @{ */

#define DIPORTSD_SESR_NCRC_ERR_MASK              (0x1U)
#define DIPORTSD_SESR_NCRC_ERR_SHIFT             (0U)
#define DIPORTSD_SESR_NCRC_ERR_WIDTH             (1U)
#define DIPORTSD_SESR_NCRC_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SESR_NCRC_ERR_SHIFT)) & DIPORTSD_SESR_NCRC_ERR_MASK)

#define DIPORTSD_SESR_MFRM_ERR_MASK              (0x2U)
#define DIPORTSD_SESR_MFRM_ERR_SHIFT             (1U)
#define DIPORTSD_SESR_MFRM_ERR_WIDTH             (1U)
#define DIPORTSD_SESR_MFRM_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SESR_MFRM_ERR_SHIFT)) & DIPORTSD_SESR_MFRM_ERR_MASK)

#define DIPORTSD_SESR_MID_ERR_MASK               (0x4U)
#define DIPORTSD_SESR_MID_ERR_SHIFT              (2U)
#define DIPORTSD_SESR_MID_ERR_WIDTH              (1U)
#define DIPORTSD_SESR_MID_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SESR_MID_ERR_SHIFT)) & DIPORTSD_SESR_MID_ERR_MASK)

#define DIPORTSD_SESR_MPRC_ERR_MASK              (0x8U)
#define DIPORTSD_SESR_MPRC_ERR_SHIFT             (3U)
#define DIPORTSD_SESR_MPRC_ERR_WIDTH             (1U)
#define DIPORTSD_SESR_MPRC_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SESR_MPRC_ERR_SHIFT)) & DIPORTSD_SESR_MPRC_ERR_MASK)

#define DIPORTSD_SESR_MADD_ERR_MASK              (0x10U)
#define DIPORTSD_SESR_MADD_ERR_SHIFT             (4U)
#define DIPORTSD_SESR_MADD_ERR_WIDTH             (1U)
#define DIPORTSD_SESR_MADD_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SESR_MADD_ERR_SHIFT)) & DIPORTSD_SESR_MADD_ERR_MASK)

#define DIPORTSD_SESR_RSP_ERR_MASK               (0x20U)
#define DIPORTSD_SESR_RSP_ERR_SHIFT              (5U)
#define DIPORTSD_SESR_RSP_ERR_WIDTH              (1U)
#define DIPORTSD_SESR_RSP_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SESR_RSP_ERR_SHIFT)) & DIPORTSD_SESR_RSP_ERR_MASK)
/*! @} */

/*! @name QOS - Quality Of Service */
/*! @{ */

#define DIPORTSD_QOS_SQOS_MASK                   (0x3U)
#define DIPORTSD_QOS_SQOS_SHIFT                  (0U)
#define DIPORTSD_QOS_SQOS_WIDTH                  (2U)
#define DIPORTSD_QOS_SQOS(x)                     (((uint32_t)(((uint32_t)(x)) << DIPORTSD_QOS_SQOS_SHIFT)) & DIPORTSD_QOS_SQOS_MASK)

#define DIPORTSD_QOS_AABW_MASK                   (0x1F00U)
#define DIPORTSD_QOS_AABW_SHIFT                  (8U)
#define DIPORTSD_QOS_AABW_WIDTH                  (5U)
#define DIPORTSD_QOS_AABW(x)                     (((uint32_t)(((uint32_t)(x)) << DIPORTSD_QOS_AABW_SHIFT)) & DIPORTSD_QOS_AABW_MASK)
/*! @} */

/*! @name SIGEN - Signaling Enable */
/*! @{ */

#define DIPORTSD_SIGEN_SIGEN_MASK                (0xFFU)
#define DIPORTSD_SIGEN_SIGEN_SHIFT               (0U)
#define DIPORTSD_SIGEN_SIGEN_WIDTH               (8U)
#define DIPORTSD_SIGEN_SIGEN(x)                  (((uint32_t)(((uint32_t)(x)) << DIPORTSD_SIGEN_SIGEN_SHIFT)) & DIPORTSD_SIGEN_SIGEN_MASK)
/*! @} */

/*! @name LAR0 - Logical Address Region 0 */
/*! @{ */

#define DIPORTSD_LAR0_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR0_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR0_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR0_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR0_START_ADDR_SHIFT)) & DIPORTSD_LAR0_START_ADDR_MASK)
/*! @} */

/*! @name PAR0 - Physical Address Region 0 */
/*! @{ */

#define DIPORTSD_PAR0_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR0_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR0_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR0_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR0_START_ADDR_SHIFT)) & DIPORTSD_PAR0_START_ADDR_MASK)
/*! @} */

/*! @name RS0 - Region Size 0 */
/*! @{ */

#define DIPORTSD_RS0_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS0_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS0_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS0_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS0_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS0_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR1 - Logical Address Region 1 */
/*! @{ */

#define DIPORTSD_LAR1_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR1_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR1_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR1_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR1_START_ADDR_SHIFT)) & DIPORTSD_LAR1_START_ADDR_MASK)
/*! @} */

/*! @name PAR1 - Physical Address Region 1 */
/*! @{ */

#define DIPORTSD_PAR1_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR1_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR1_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR1_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR1_START_ADDR_SHIFT)) & DIPORTSD_PAR1_START_ADDR_MASK)
/*! @} */

/*! @name RS1 - Region Size 1 */
/*! @{ */

#define DIPORTSD_RS1_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS1_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS1_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS1_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS1_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS1_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR2 - Logical Address Region 2 */
/*! @{ */

#define DIPORTSD_LAR2_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR2_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR2_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR2_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR2_START_ADDR_SHIFT)) & DIPORTSD_LAR2_START_ADDR_MASK)
/*! @} */

/*! @name PAR2 - Physical Address Region 2 */
/*! @{ */

#define DIPORTSD_PAR2_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR2_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR2_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR2_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR2_START_ADDR_SHIFT)) & DIPORTSD_PAR2_START_ADDR_MASK)
/*! @} */

/*! @name RS2 - Region Size 2 */
/*! @{ */

#define DIPORTSD_RS2_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS2_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS2_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS2_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS2_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS2_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR3 - Logical Address Region 3 */
/*! @{ */

#define DIPORTSD_LAR3_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR3_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR3_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR3_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR3_START_ADDR_SHIFT)) & DIPORTSD_LAR3_START_ADDR_MASK)
/*! @} */

/*! @name PAR3 - Physical Address Region 3 */
/*! @{ */

#define DIPORTSD_PAR3_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR3_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR3_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR3_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR3_START_ADDR_SHIFT)) & DIPORTSD_PAR3_START_ADDR_MASK)
/*! @} */

/*! @name RS3 - Region Size 3 */
/*! @{ */

#define DIPORTSD_RS3_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS3_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS3_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS3_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS3_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS3_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR4 - Logical Address Region 4 */
/*! @{ */

#define DIPORTSD_LAR4_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR4_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR4_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR4_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR4_START_ADDR_SHIFT)) & DIPORTSD_LAR4_START_ADDR_MASK)
/*! @} */

/*! @name PAR4 - Physical Address Region 4 */
/*! @{ */

#define DIPORTSD_PAR4_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR4_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR4_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR4_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR4_START_ADDR_SHIFT)) & DIPORTSD_PAR4_START_ADDR_MASK)
/*! @} */

/*! @name RS4 - Region Size 4 */
/*! @{ */

#define DIPORTSD_RS4_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS4_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS4_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS4_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS4_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS4_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR5 - Logical Address Region 5 */
/*! @{ */

#define DIPORTSD_LAR5_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR5_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR5_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR5_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR5_START_ADDR_SHIFT)) & DIPORTSD_LAR5_START_ADDR_MASK)
/*! @} */

/*! @name PAR5 - Physical Address Region 5 */
/*! @{ */

#define DIPORTSD_PAR5_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR5_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR5_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR5_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR5_START_ADDR_SHIFT)) & DIPORTSD_PAR5_START_ADDR_MASK)
/*! @} */

/*! @name RS5 - Region Size 5 */
/*! @{ */

#define DIPORTSD_RS5_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS5_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS5_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS5_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS5_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS5_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR6 - Logical Address Region 6 */
/*! @{ */

#define DIPORTSD_LAR6_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR6_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR6_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR6_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR6_START_ADDR_SHIFT)) & DIPORTSD_LAR6_START_ADDR_MASK)
/*! @} */

/*! @name PAR6 - Physical Address Region 6 */
/*! @{ */

#define DIPORTSD_PAR6_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR6_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR6_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR6_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR6_START_ADDR_SHIFT)) & DIPORTSD_PAR6_START_ADDR_MASK)
/*! @} */

/*! @name RS6 - Region Size 6 */
/*! @{ */

#define DIPORTSD_RS6_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS6_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS6_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS6_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS6_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS6_BLOCK_SIZE_MASK)
/*! @} */

/*! @name LAR7 - Logical Address Region 7 */
/*! @{ */

#define DIPORTSD_LAR7_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_LAR7_START_ADDR_SHIFT           (12U)
#define DIPORTSD_LAR7_START_ADDR_WIDTH           (20U)
#define DIPORTSD_LAR7_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_LAR7_START_ADDR_SHIFT)) & DIPORTSD_LAR7_START_ADDR_MASK)
/*! @} */

/*! @name PAR7 - Physical Address Region 7 */
/*! @{ */

#define DIPORTSD_PAR7_START_ADDR_MASK            (0xFFFFF000U)
#define DIPORTSD_PAR7_START_ADDR_SHIFT           (12U)
#define DIPORTSD_PAR7_START_ADDR_WIDTH           (20U)
#define DIPORTSD_PAR7_START_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << DIPORTSD_PAR7_START_ADDR_SHIFT)) & DIPORTSD_PAR7_START_ADDR_MASK)
/*! @} */

/*! @name RS7 - Region Size 7 */
/*! @{ */

#define DIPORTSD_RS7_BLOCK_SIZE_MASK             (0x1FU)
#define DIPORTSD_RS7_BLOCK_SIZE_SHIFT            (0U)
#define DIPORTSD_RS7_BLOCK_SIZE_WIDTH            (5U)
#define DIPORTSD_RS7_BLOCK_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DIPORTSD_RS7_BLOCK_SIZE_SHIFT)) & DIPORTSD_RS7_BLOCK_SIZE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DIPORTSD_Register_Masks */

/*!
 * @}
 */ /* end of group DIPORTSD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DIPORTSD_H_) */
