/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_Boot.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_Boot
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
#if !defined(S32Z2_Boot_H_)  /* Check if memory map has not been already included */
#define S32Z2_Boot_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- Boot Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Boot_Peripheral_Access_Layer Boot Peripheral Access Layer
 * @{
 */

/** Boot - Register Layout Typedef */
typedef struct {
  __I  uint32_t BOOT_GPR_BMR1;                     /**< Boot Configuration 1, offset: 0x0, available only on: BMR (missing on POR) */
  __I  uint32_t BOOT_GPR_BMR2;                     /**< Boot Configuration 2, offset: 0x4, available only on: BMR (missing on POR) */
  uint8_t RESERVED_0[100];
  __IO uint32_t BOOT_POR_CTRL_REG;                 /**< Boot POR Control, offset: 0x6C, available only on: POR (missing on BMR) */
  __IO uint32_t BOOT_POR_C1_REG;                   /**< BOOT POR Control 1 Register, offset: 0x70, available only on: POR (missing on BMR) */
  uint8_t RESERVED_1[4];
  __IO uint32_t BOOT_DEST_C0_REG;                  /**< BOOT DEST Control 0 Register, offset: 0x78, available only on: POR (missing on BMR) */
  uint8_t RESERVED_2[8];
  __IO uint32_t BOOT_FUNC_C0_REG;                  /**< BOOT FUNC Control 0 Register, offset: 0x84, available only on: POR (missing on BMR) */
} Boot_Type, *Boot_MemMapPtr;

/** Number of instances of the Boot module. */
#define Boot_INSTANCE_COUNT                      (2u)

/* Boot - Peripheral instance base addresses */
/** Peripheral BMR base address */
#define IP_BMR_BASE                              (0x42280000u)
/** Peripheral BMR base pointer */
#define IP_BMR                                   ((Boot_Type *)IP_BMR_BASE)
/** Peripheral POR base address */
#define IP_POR_BASE                              (0x42060000u)
/** Peripheral POR base pointer */
#define IP_POR                                   ((Boot_Type *)IP_POR_BASE)
/** Array initializer of Boot peripheral base addresses */
#define IP_Boot_BASE_ADDRS                       { IP_BMR_BASE, IP_POR_BASE }
/** Array initializer of Boot peripheral base pointers */
#define IP_Boot_BASE_PTRS                        { IP_BMR, IP_POR }

/* ----------------------------------------------------------------------------
   -- Boot Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Boot_Register_Masks Boot Register Masks
 * @{
 */

/*! @name BOOT_GPR_BMR1 - Boot Configuration 1 */
/*! @{ */

#define Boot_BOOT_GPR_BMR1_BOOT_CFG_MASK         (0xFFFFFFFFU)
#define Boot_BOOT_GPR_BMR1_BOOT_CFG_SHIFT        (0U)
#define Boot_BOOT_GPR_BMR1_BOOT_CFG_WIDTH        (32U)
#define Boot_BOOT_GPR_BMR1_BOOT_CFG(x)           (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_GPR_BMR1_BOOT_CFG_SHIFT)) & Boot_BOOT_GPR_BMR1_BOOT_CFG_MASK)
/*! @} */

/*! @name BOOT_GPR_BMR2 - Boot Configuration 2 */
/*! @{ */

#define Boot_BOOT_GPR_BMR2_FUSE_SEL_MASK         (0x10U)
#define Boot_BOOT_GPR_BMR2_FUSE_SEL_SHIFT        (4U)
#define Boot_BOOT_GPR_BMR2_FUSE_SEL_WIDTH        (1U)
#define Boot_BOOT_GPR_BMR2_FUSE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_GPR_BMR2_FUSE_SEL_SHIFT)) & Boot_BOOT_GPR_BMR2_FUSE_SEL_MASK)

#define Boot_BOOT_GPR_BMR2_BOOTMODE2_MASK        (0x1000000U)
#define Boot_BOOT_GPR_BMR2_BOOTMODE2_SHIFT       (24U)
#define Boot_BOOT_GPR_BMR2_BOOTMODE2_WIDTH       (1U)
#define Boot_BOOT_GPR_BMR2_BOOTMODE2(x)          (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_GPR_BMR2_BOOTMODE2_SHIFT)) & Boot_BOOT_GPR_BMR2_BOOTMODE2_MASK)

#define Boot_BOOT_GPR_BMR2_BOOTMODE1_MASK        (0x2000000U)
#define Boot_BOOT_GPR_BMR2_BOOTMODE1_SHIFT       (25U)
#define Boot_BOOT_GPR_BMR2_BOOTMODE1_WIDTH       (1U)
#define Boot_BOOT_GPR_BMR2_BOOTMODE1(x)          (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_GPR_BMR2_BOOTMODE1_SHIFT)) & Boot_BOOT_GPR_BMR2_BOOTMODE1_MASK)
/*! @} */

/*! @name BOOT_POR_CTRL_REG - Boot POR Control */
/*! @{ */

#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_A_MASK (0xFFU)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_A_SHIFT (0U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_A_WIDTH (8U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_A(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_A_SHIFT)) & Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_A_MASK)

#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_B_MASK (0xFF00U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_B_SHIFT (8U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_B_WIDTH (8U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_B(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_B_SHIFT)) & Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_COUNT_B_MASK)

#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_MARKER_MASK (0xFFFF0000U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_MARKER_SHIFT (16U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_MARKER_WIDTH (16U)
#define Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_MARKER(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_MARKER_SHIFT)) & Boot_BOOT_POR_CTRL_REG_HSE_FW_ROLLBACK_MARKER_MASK)
/*! @} */

/*! @name BOOT_POR_C1_REG - BOOT POR Control 1 Register */
/*! @{ */

#define Boot_BOOT_POR_C1_REG_SELF_TEST_DCD_IMAGE_MASK (0xFFU)
#define Boot_BOOT_POR_C1_REG_SELF_TEST_DCD_IMAGE_SHIFT (0U)
#define Boot_BOOT_POR_C1_REG_SELF_TEST_DCD_IMAGE_WIDTH (8U)
#define Boot_BOOT_POR_C1_REG_SELF_TEST_DCD_IMAGE(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_C1_REG_SELF_TEST_DCD_IMAGE_SHIFT)) & Boot_BOOT_POR_C1_REG_SELF_TEST_DCD_IMAGE_MASK)

#define Boot_BOOT_POR_C1_REG_DCD_IMAGE_SELECT_MASK (0xFF00U)
#define Boot_BOOT_POR_C1_REG_DCD_IMAGE_SELECT_SHIFT (8U)
#define Boot_BOOT_POR_C1_REG_DCD_IMAGE_SELECT_WIDTH (8U)
#define Boot_BOOT_POR_C1_REG_DCD_IMAGE_SELECT(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_C1_REG_DCD_IMAGE_SELECT_SHIFT)) & Boot_BOOT_POR_C1_REG_DCD_IMAGE_SELECT_MASK)

#define Boot_BOOT_POR_C1_REG_APP_IMAGE_MASK      (0xFF0000U)
#define Boot_BOOT_POR_C1_REG_APP_IMAGE_SHIFT     (16U)
#define Boot_BOOT_POR_C1_REG_APP_IMAGE_WIDTH     (8U)
#define Boot_BOOT_POR_C1_REG_APP_IMAGE(x)        (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_C1_REG_APP_IMAGE_SHIFT)) & Boot_BOOT_POR_C1_REG_APP_IMAGE_MASK)

#define Boot_BOOT_POR_C1_REG_DDRC_IIA_IMAGE_MASK (0xFF000000U)
#define Boot_BOOT_POR_C1_REG_DDRC_IIA_IMAGE_SHIFT (24U)
#define Boot_BOOT_POR_C1_REG_DDRC_IIA_IMAGE_WIDTH (8U)
#define Boot_BOOT_POR_C1_REG_DDRC_IIA_IMAGE(x)   (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_POR_C1_REG_DDRC_IIA_IMAGE_SHIFT)) & Boot_BOOT_POR_C1_REG_DDRC_IIA_IMAGE_MASK)
/*! @} */

/*! @name BOOT_DEST_C0_REG - BOOT DEST Control 0 Register */
/*! @{ */

#define Boot_BOOT_DEST_C0_REG_LPDDR4_FUNC_RESET_COUNTER_MASK (0x7U)
#define Boot_BOOT_DEST_C0_REG_LPDDR4_FUNC_RESET_COUNTER_SHIFT (0U)
#define Boot_BOOT_DEST_C0_REG_LPDDR4_FUNC_RESET_COUNTER_WIDTH (3U)
#define Boot_BOOT_DEST_C0_REG_LPDDR4_FUNC_RESET_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_DEST_C0_REG_LPDDR4_FUNC_RESET_COUNTER_SHIFT)) & Boot_BOOT_DEST_C0_REG_LPDDR4_FUNC_RESET_COUNTER_MASK)
/*! @} */

/*! @name BOOT_FUNC_C0_REG - BOOT FUNC Control 0 Register */
/*! @{ */

#define Boot_BOOT_FUNC_C0_REG_DDRC_IIA_STATUS_MASK (0xFFFFFFFFU)
#define Boot_BOOT_FUNC_C0_REG_DDRC_IIA_STATUS_SHIFT (0U)
#define Boot_BOOT_FUNC_C0_REG_DDRC_IIA_STATUS_WIDTH (32U)
#define Boot_BOOT_FUNC_C0_REG_DDRC_IIA_STATUS(x) (((uint32_t)(((uint32_t)(x)) << Boot_BOOT_FUNC_C0_REG_DDRC_IIA_STATUS_SHIFT)) & Boot_BOOT_FUNC_C0_REG_DDRC_IIA_STATUS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group Boot_Register_Masks */

/*!
 * @}
 */ /* end of group Boot_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_Boot_H_) */
