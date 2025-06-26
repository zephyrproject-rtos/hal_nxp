/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_MULTICORE_CONFIGURATION.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_MULTICORE_CONFIGURATION
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
#if !defined(S32Z2_MULTICORE_CONFIGURATION_H_)  /* Check if memory map has not been already included */
#define S32Z2_MULTICORE_CONFIGURATION_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MULTICORE_CONFIGURATION Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MULTICORE_CONFIGURATION_Peripheral_Access_Layer MULTICORE_CONFIGURATION Peripheral Access Layer
 * @{
 */

/** MULTICORE_CONFIGURATION - Size of Registers Arrays */
#define MULTICORE_CONFIGURATION_COM_REGX_COUNT    8u

/** MULTICORE_CONFIGURATION - Register Layout Typedef */
typedef struct {
  __IO uint32_t COM_REGX[MULTICORE_CONFIGURATION_COM_REGX_COUNT]; /**< MCCI Message Register, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[96];
  __IO uint32_t COM_STS;                           /**< MCCI Status, offset: 0x80 */
  __IO uint32_t COM_INT_EN;                        /**< MCCI Interrupt Enable, offset: 0x84 */
  uint8_t RESERVED_1[8];
  __IO uint32_t START_ADDR0;                       /**< IDM Snoop Start Address 0, offset: 0x90 */
  __IO uint32_t TOP_ADDR0;                         /**< IDM Snoop End Address 0, offset: 0x94 */
  __IO uint32_t SNOOP_CSR0;                        /**< IDM Snoop Control 0, offset: 0x98 */
  __IO uint32_t START_ADDR1;                       /**< IDM Snoop Start Address 1, offset: 0x9C */
  __IO uint32_t TOP_ADDR1;                         /**< IDM Snoop End Address 1, offset: 0xA0 */
  __IO uint32_t SNOOP_CSR1;                        /**< IDM Snoop Control 1, offset: 0xA4 */
} MULTICORE_CONFIGURATION_Type, *MULTICORE_CONFIGURATION_MemMapPtr;

/** Number of instances of the MULTICORE_CONFIGURATION module. */
#define MULTICORE_CONFIGURATION_INSTANCE_COUNT   (1u)

/* MULTICORE_CONFIGURATION - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__MULTICORE_CONFIGURATION base address */
#define IP_CEVA_SPF2__MULTICORE_CONFIGURATION_BASE (0x24400000u)
/** Peripheral CEVA_SPF2__MULTICORE_CONFIGURATION base pointer */
#define IP_CEVA_SPF2__MULTICORE_CONFIGURATION    ((MULTICORE_CONFIGURATION_Type *)IP_CEVA_SPF2__MULTICORE_CONFIGURATION_BASE)
/** Array initializer of MULTICORE_CONFIGURATION peripheral base addresses */
#define IP_MULTICORE_CONFIGURATION_BASE_ADDRS    { IP_CEVA_SPF2__MULTICORE_CONFIGURATION_BASE }
/** Array initializer of MULTICORE_CONFIGURATION peripheral base pointers */
#define IP_MULTICORE_CONFIGURATION_BASE_PTRS     { IP_CEVA_SPF2__MULTICORE_CONFIGURATION }

/* ----------------------------------------------------------------------------
   -- MULTICORE_CONFIGURATION Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MULTICORE_CONFIGURATION_Register_Masks MULTICORE_CONFIGURATION Register Masks
 * @{
 */

/*! @name COM_REGX - MCCI Message Register */
/*! @{ */

#define MULTICORE_CONFIGURATION_COM_REGX_COM_REG_MASK (0xFFFFFFFFU)
#define MULTICORE_CONFIGURATION_COM_REGX_COM_REG_SHIFT (0U)
#define MULTICORE_CONFIGURATION_COM_REGX_COM_REG_WIDTH (32U)
#define MULTICORE_CONFIGURATION_COM_REGX_COM_REG(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_COM_REGX_COM_REG_SHIFT)) & MULTICORE_CONFIGURATION_COM_REGX_COM_REG_MASK)
/*! @} */

/*! @name COM_STS - MCCI Status */
/*! @{ */

#define MULTICORE_CONFIGURATION_COM_STS_COM_STS_MASK (0xFFU)
#define MULTICORE_CONFIGURATION_COM_STS_COM_STS_SHIFT (0U)
#define MULTICORE_CONFIGURATION_COM_STS_COM_STS_WIDTH (8U)
#define MULTICORE_CONFIGURATION_COM_STS_COM_STS(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_COM_STS_COM_STS_SHIFT)) & MULTICORE_CONFIGURATION_COM_STS_COM_STS_MASK)
/*! @} */

/*! @name COM_INT_EN - MCCI Interrupt Enable */
/*! @{ */

#define MULTICORE_CONFIGURATION_COM_INT_EN_COM_INT_EN_MASK (0xFFU)
#define MULTICORE_CONFIGURATION_COM_INT_EN_COM_INT_EN_SHIFT (0U)
#define MULTICORE_CONFIGURATION_COM_INT_EN_COM_INT_EN_WIDTH (8U)
#define MULTICORE_CONFIGURATION_COM_INT_EN_COM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_COM_INT_EN_COM_INT_EN_SHIFT)) & MULTICORE_CONFIGURATION_COM_INT_EN_COM_INT_EN_MASK)
/*! @} */

/*! @name START_ADDR0 - IDM Snoop Start Address 0 */
/*! @{ */

#define MULTICORE_CONFIGURATION_START_ADDR0_START_ADD_MASK (0x1FFFFFU)
#define MULTICORE_CONFIGURATION_START_ADDR0_START_ADD_SHIFT (0U)
#define MULTICORE_CONFIGURATION_START_ADDR0_START_ADD_WIDTH (21U)
#define MULTICORE_CONFIGURATION_START_ADDR0_START_ADD(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_START_ADDR0_START_ADD_SHIFT)) & MULTICORE_CONFIGURATION_START_ADDR0_START_ADD_MASK)
/*! @} */

/*! @name TOP_ADDR0 - IDM Snoop End Address 0 */
/*! @{ */

#define MULTICORE_CONFIGURATION_TOP_ADDR0_TOP_ADD_MASK (0x1FFFFFU)
#define MULTICORE_CONFIGURATION_TOP_ADDR0_TOP_ADD_SHIFT (0U)
#define MULTICORE_CONFIGURATION_TOP_ADDR0_TOP_ADD_WIDTH (21U)
#define MULTICORE_CONFIGURATION_TOP_ADDR0_TOP_ADD(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_TOP_ADDR0_TOP_ADD_SHIFT)) & MULTICORE_CONFIGURATION_TOP_ADDR0_TOP_ADD_MASK)
/*! @} */

/*! @name SNOOP_CSR0 - IDM Snoop Control 0 */
/*! @{ */

#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_RD_WR_MASK (0x3U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_RD_WR_SHIFT (0U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_RD_WR_WIDTH (2U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_RD_WR(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_RD_WR_SHIFT)) & MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_RD_WR_MASK)

#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_STS_MASK (0x4U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_STS_SHIFT (2U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_STS_WIDTH (1U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_STS(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_STS_SHIFT)) & MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_STS_MASK)

#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_INT_EN_MASK (0x8U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_INT_EN_SHIFT (3U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_INT_EN_WIDTH (1U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_INT_EN_SHIFT)) & MULTICORE_CONFIGURATION_SNOOP_CSR0_SNOOP_EDAP_INT_EN_MASK)
/*! @} */

/*! @name START_ADDR1 - IDM Snoop Start Address 1 */
/*! @{ */

#define MULTICORE_CONFIGURATION_START_ADDR1_START_ADD_MASK (0x1FFFFFU)
#define MULTICORE_CONFIGURATION_START_ADDR1_START_ADD_SHIFT (0U)
#define MULTICORE_CONFIGURATION_START_ADDR1_START_ADD_WIDTH (21U)
#define MULTICORE_CONFIGURATION_START_ADDR1_START_ADD(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_START_ADDR1_START_ADD_SHIFT)) & MULTICORE_CONFIGURATION_START_ADDR1_START_ADD_MASK)
/*! @} */

/*! @name TOP_ADDR1 - IDM Snoop End Address 1 */
/*! @{ */

#define MULTICORE_CONFIGURATION_TOP_ADDR1_TOP_ADD_MASK (0x1FFFFFU)
#define MULTICORE_CONFIGURATION_TOP_ADDR1_TOP_ADD_SHIFT (0U)
#define MULTICORE_CONFIGURATION_TOP_ADDR1_TOP_ADD_WIDTH (21U)
#define MULTICORE_CONFIGURATION_TOP_ADDR1_TOP_ADD(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_TOP_ADDR1_TOP_ADD_SHIFT)) & MULTICORE_CONFIGURATION_TOP_ADDR1_TOP_ADD_MASK)
/*! @} */

/*! @name SNOOP_CSR1 - IDM Snoop Control 1 */
/*! @{ */

#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_RD_WR_MASK (0x3U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_RD_WR_SHIFT (0U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_RD_WR_WIDTH (2U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_RD_WR(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_RD_WR_SHIFT)) & MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_RD_WR_MASK)

#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_STS_MASK (0x4U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_STS_SHIFT (2U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_STS_WIDTH (1U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_STS(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_STS_SHIFT)) & MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_STS_MASK)

#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_INT_EN_MASK (0x8U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_INT_EN_SHIFT (3U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_INT_EN_WIDTH (1U)
#define MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_INT_EN_SHIFT)) & MULTICORE_CONFIGURATION_SNOOP_CSR1_SNOOP_EDAP_INT_EN_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MULTICORE_CONFIGURATION_Register_Masks */

/*!
 * @}
 */ /* end of group MULTICORE_CONFIGURATION_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_MULTICORE_CONFIGURATION_H_) */
