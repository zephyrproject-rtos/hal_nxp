/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_CONFIGURATION_GPR.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_CONFIGURATION_GPR
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
#if !defined(S32K39_CONFIGURATION_GPR_H_)  /* Check if memory map has not been already included */
#define S32K39_CONFIGURATION_GPR_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CONFIGURATION_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_GPR_Peripheral_Access_Layer CONFIGURATION_GPR Peripheral Access Layer
 * @{
 */

/** CONFIGURATION_GPR - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[28];
  __I  uint32_t CONFIG_REG0;                       /**< General Purpose Configuration 0, offset: 0x1C */
  uint8_t RESERVED_1[20];
  __I  uint32_t CONFIG_REG6;                       /**< General Purpose Configuration 6, offset: 0x34 */
  uint8_t RESERVED_2[152];
  __I  uint32_t QSPI_SFP_CTRL;                     /**< QuadSPI SFP Control, offset: 0xD0 */
  __I  uint32_t QSPI_SFP_CTRL_ALT;                 /**< QuadSPI SFP Control Alternate, offset: 0xD4 */
} CONFIGURATION_GPR_Type, *CONFIGURATION_GPR_MemMapPtr;

/** Number of instances of the CONFIGURATION_GPR module. */
#define CONFIGURATION_GPR_INSTANCE_COUNT         (1u)

/* CONFIGURATION_GPR - Peripheral instance base addresses */
/** Peripheral CONFIGURATION_GPR base address */
#define IP_CONFIGURATION_GPR_BASE                (0x4039C000u)
/** Peripheral CONFIGURATION_GPR base pointer */
#define IP_CONFIGURATION_GPR                     ((CONFIGURATION_GPR_Type *)IP_CONFIGURATION_GPR_BASE)
/** Array initializer of CONFIGURATION_GPR peripheral base addresses */
#define IP_CONFIGURATION_GPR_BASE_ADDRS          { IP_CONFIGURATION_GPR_BASE }
/** Array initializer of CONFIGURATION_GPR peripheral base pointers */
#define IP_CONFIGURATION_GPR_BASE_PTRS           { IP_CONFIGURATION_GPR }

/* ----------------------------------------------------------------------------
   -- CONFIGURATION_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_GPR_Register_Masks CONFIGURATION_GPR Register Masks
 * @{
 */

/*! @name CONFIG_REG0 - General Purpose Configuration 0 */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG0_EDB_MASK   (0x40U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB_SHIFT  (6U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB_WIDTH  (1U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB(x)     (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG0_EDB_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG0_EDB_MASK)
/*! @} */

/*! @name CONFIG_REG6 - General Purpose Configuration 6 */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_MASK (0x1U)
#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_SHIFT (0U)
#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_MASK (0x4U)
#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_SHIFT (2U)
#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK (0x10U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT (4U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_SHIFT (31U)
#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_MASK)
/*! @} */

/*! @name QSPI_SFP_CTRL - QuadSPI SFP Control */
/*! @{ */

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_MASK (0x3FU)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_SHIFT (0U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_WIDTH (6U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_MASK)

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ADDRESS_SIZE_MASK (0x3FC0U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ADDRESS_SIZE_SHIFT (6U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ADDRESS_SIZE_WIDTH (8U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ADDRESS_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_ADDRESS_SIZE_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_ADDRESS_SIZE_MASK)

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_DXACP_MASK (0x1C000U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_DXACP_SHIFT (14U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_DXACP_WIDTH (3U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_DXACP(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_DXACP_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_DXACP_MASK)

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_VLD_MASK (0x20000U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_VLD_SHIFT (17U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_VLD_WIDTH (1U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_VLD(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_VLD_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_GMID_VLD_MASK)

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_VLD_MASK (0x40000U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_VLD_SHIFT (18U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_VLD_WIDTH (1U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_VLD(x)   (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_VLD_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_VLD_MASK)

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_SOFT_LOCK_MASK (0x40000000U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_SOFT_LOCK_SHIFT (30U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_SOFT_LOCK_WIDTH (1U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_SOFT_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_SOFT_LOCK_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_SOFT_LOCK_MASK)

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_HARD_LOCK_SHIFT (31U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_HARD_LOCK_WIDTH (1U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_HARD_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_HARD_LOCK_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_HARD_LOCK_MASK)
/*! @} */

/*! @name QSPI_SFP_CTRL_ALT - QuadSPI SFP Control Alternate */
/*! @{ */

#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ALT_INVERT_QSPI_SFP_TRL_MASK (0xFFFFFFFFU)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ALT_INVERT_QSPI_SFP_TRL_SHIFT (0U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ALT_INVERT_QSPI_SFP_TRL_WIDTH (32U)
#define CONFIGURATION_GPR_QSPI_SFP_CTRL_ALT_INVERT_QSPI_SFP_TRL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_QSPI_SFP_CTRL_ALT_INVERT_QSPI_SFP_TRL_SHIFT)) & CONFIGURATION_GPR_QSPI_SFP_CTRL_ALT_INVERT_QSPI_SFP_TRL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CONFIGURATION_GPR_Register_Masks */

/*!
 * @}
 */ /* end of group CONFIGURATION_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_CONFIGURATION_GPR_H_) */
