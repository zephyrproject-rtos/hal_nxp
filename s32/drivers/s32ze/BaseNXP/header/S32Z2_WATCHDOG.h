/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_WATCHDOG.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_WATCHDOG
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
#if !defined(S32Z2_WATCHDOG_H_)  /* Check if memory map has not been already included */
#define S32Z2_WATCHDOG_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- WATCHDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WATCHDOG_Peripheral_Access_Layer WATCHDOG Peripheral Access Layer
 * @{
 */

/** WATCHDOG - Register Layout Typedef */
typedef struct {
  __O  uint32_t WDOGACS;                           /**< Watchdog Access Control, offset: 0x0 */
  __IO uint32_t WDOGCFG;                           /**< System Watchdog Configuration, offset: 0x4 */
  __IO uint32_t WDOGMIN;                           /**< System Watchdog Minimum Threshold Configuration, offset: 0x8 */
  __IO uint32_t WDOGMAX;                           /**< System Watchdog Maximum Threshold Configuration, offset: 0xC */
  uint8_t RESERVED_0[8];
  __I  uint32_t WDOGCNT;                           /**< System Watchdog Count Value, offset: 0x18 */
  __IO uint32_t MPWDOGCFG;                         /**< Master Port Watchdog Control, offset: 0x1C */
  __IO uint32_t MPWDOGT;                           /**< DMSS Master Port Watchdog Threshold, offset: 0x20 */
  __I  uint32_t EPPWDOGC;                          /**< PMSS Master Port Watchdog Threshold, offset: 0x24 */
  __I  uint32_t EDPWDOGC;                          /**< EDP Master Port Count Value, offset: 0x28 */
  uint8_t RESERVED_1[20];
  __IO uint32_t ICUWDOGCFG;                        /**< ICU Watchdog Configuration, offset: 0x40 */
  __IO uint32_t ICUWDOGT;                          /**< ICU Watchdog Threshold Configuration, offset: 0x44 */
  __IO uint32_t SYSWDOGSIG;                        /**< System Watchdog Signal, offset: 0x48 */
  __I  uint32_t ICUWDOGC;                          /**< ICU Watchdog Count Value, offset: 0x4C */
} WATCHDOG_Type, *WATCHDOG_MemMapPtr;

/** Number of instances of the WATCHDOG module. */
#define WATCHDOG_INSTANCE_COUNT                  (1u)

/* WATCHDOG - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__WATCHDOG base address */
#define IP_CEVA_SPF2__WATCHDOG_BASE              (0x24400700u)
/** Peripheral CEVA_SPF2__WATCHDOG base pointer */
#define IP_CEVA_SPF2__WATCHDOG                   ((WATCHDOG_Type *)IP_CEVA_SPF2__WATCHDOG_BASE)
/** Array initializer of WATCHDOG peripheral base addresses */
#define IP_WATCHDOG_BASE_ADDRS                   { IP_CEVA_SPF2__WATCHDOG_BASE }
/** Array initializer of WATCHDOG peripheral base pointers */
#define IP_WATCHDOG_BASE_PTRS                    { IP_CEVA_SPF2__WATCHDOG }

/* ----------------------------------------------------------------------------
   -- WATCHDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WATCHDOG_Register_Masks WATCHDOG Register Masks
 * @{
 */

/*! @name WDOGACS - Watchdog Access Control */
/*! @{ */

#define WATCHDOG_WDOGACS_WDOG_ACS_MASK           (0xFFFFU)
#define WATCHDOG_WDOGACS_WDOG_ACS_SHIFT          (0U)
#define WATCHDOG_WDOGACS_WDOG_ACS_WIDTH          (16U)
#define WATCHDOG_WDOGACS_WDOG_ACS(x)             (((uint32_t)(((uint32_t)(x)) << WATCHDOG_WDOGACS_WDOG_ACS_SHIFT)) & WATCHDOG_WDOGACS_WDOG_ACS_MASK)
/*! @} */

/*! @name WDOGCFG - System Watchdog Configuration */
/*! @{ */

#define WATCHDOG_WDOGCFG_WDOG_EN_MASK            (0x1U)
#define WATCHDOG_WDOGCFG_WDOG_EN_SHIFT           (0U)
#define WATCHDOG_WDOGCFG_WDOG_EN_WIDTH           (1U)
#define WATCHDOG_WDOGCFG_WDOG_EN(x)              (((uint32_t)(((uint32_t)(x)) << WATCHDOG_WDOGCFG_WDOG_EN_SHIFT)) & WATCHDOG_WDOGCFG_WDOG_EN_MASK)
/*! @} */

/*! @name WDOGMIN - System Watchdog Minimum Threshold Configuration */
/*! @{ */

#define WATCHDOG_WDOGMIN_WDOGMIN_MASK            (0xFFFFFFFFU)
#define WATCHDOG_WDOGMIN_WDOGMIN_SHIFT           (0U)
#define WATCHDOG_WDOGMIN_WDOGMIN_WIDTH           (32U)
#define WATCHDOG_WDOGMIN_WDOGMIN(x)              (((uint32_t)(((uint32_t)(x)) << WATCHDOG_WDOGMIN_WDOGMIN_SHIFT)) & WATCHDOG_WDOGMIN_WDOGMIN_MASK)
/*! @} */

/*! @name WDOGMAX - System Watchdog Maximum Threshold Configuration */
/*! @{ */

#define WATCHDOG_WDOGMAX_WDOGMAX_MASK            (0xFFFFFFFFU)
#define WATCHDOG_WDOGMAX_WDOGMAX_SHIFT           (0U)
#define WATCHDOG_WDOGMAX_WDOGMAX_WIDTH           (32U)
#define WATCHDOG_WDOGMAX_WDOGMAX(x)              (((uint32_t)(((uint32_t)(x)) << WATCHDOG_WDOGMAX_WDOGMAX_SHIFT)) & WATCHDOG_WDOGMAX_WDOGMAX_MASK)
/*! @} */

/*! @name WDOGCNT - System Watchdog Count Value */
/*! @{ */

#define WATCHDOG_WDOGCNT_WDOGCNT_MASK            (0xFFFFFFFFU)
#define WATCHDOG_WDOGCNT_WDOGCNT_SHIFT           (0U)
#define WATCHDOG_WDOGCNT_WDOGCNT_WIDTH           (32U)
#define WATCHDOG_WDOGCNT_WDOGCNT(x)              (((uint32_t)(((uint32_t)(x)) << WATCHDOG_WDOGCNT_WDOGCNT_SHIFT)) & WATCHDOG_WDOGCNT_WDOGCNT_MASK)
/*! @} */

/*! @name MPWDOGCFG - Master Port Watchdog Control */
/*! @{ */

#define WATCHDOG_MPWDOGCFG_EPPWDOG_EN_MASK       (0x2U)
#define WATCHDOG_MPWDOGCFG_EPPWDOG_EN_SHIFT      (1U)
#define WATCHDOG_MPWDOGCFG_EPPWDOG_EN_WIDTH      (1U)
#define WATCHDOG_MPWDOGCFG_EPPWDOG_EN(x)         (((uint32_t)(((uint32_t)(x)) << WATCHDOG_MPWDOGCFG_EPPWDOG_EN_SHIFT)) & WATCHDOG_MPWDOGCFG_EPPWDOG_EN_MASK)

#define WATCHDOG_MPWDOGCFG_EDPWDOG_EN_MASK       (0x4U)
#define WATCHDOG_MPWDOGCFG_EDPWDOG_EN_SHIFT      (2U)
#define WATCHDOG_MPWDOGCFG_EDPWDOG_EN_WIDTH      (1U)
#define WATCHDOG_MPWDOGCFG_EDPWDOG_EN(x)         (((uint32_t)(((uint32_t)(x)) << WATCHDOG_MPWDOGCFG_EDPWDOG_EN_SHIFT)) & WATCHDOG_MPWDOGCFG_EDPWDOG_EN_MASK)
/*! @} */

/*! @name MPWDOGT - DMSS Master Port Watchdog Threshold */
/*! @{ */

#define WATCHDOG_MPWDOGT_MPWDOGT_MASK            (0xFFFFFFFFU)
#define WATCHDOG_MPWDOGT_MPWDOGT_SHIFT           (0U)
#define WATCHDOG_MPWDOGT_MPWDOGT_WIDTH           (32U)
#define WATCHDOG_MPWDOGT_MPWDOGT(x)              (((uint32_t)(((uint32_t)(x)) << WATCHDOG_MPWDOGT_MPWDOGT_SHIFT)) & WATCHDOG_MPWDOGT_MPWDOGT_MASK)
/*! @} */

/*! @name EPPWDOGC - PMSS Master Port Watchdog Threshold */
/*! @{ */

#define WATCHDOG_EPPWDOGC_EPPWDOGC_MASK          (0xFFFFFFFFU)
#define WATCHDOG_EPPWDOGC_EPPWDOGC_SHIFT         (0U)
#define WATCHDOG_EPPWDOGC_EPPWDOGC_WIDTH         (32U)
#define WATCHDOG_EPPWDOGC_EPPWDOGC(x)            (((uint32_t)(((uint32_t)(x)) << WATCHDOG_EPPWDOGC_EPPWDOGC_SHIFT)) & WATCHDOG_EPPWDOGC_EPPWDOGC_MASK)
/*! @} */

/*! @name EDPWDOGC - EDP Master Port Count Value */
/*! @{ */

#define WATCHDOG_EDPWDOGC_EDPWDOGC_MASK          (0xFFFFFFFFU)
#define WATCHDOG_EDPWDOGC_EDPWDOGC_SHIFT         (0U)
#define WATCHDOG_EDPWDOGC_EDPWDOGC_WIDTH         (32U)
#define WATCHDOG_EDPWDOGC_EDPWDOGC(x)            (((uint32_t)(((uint32_t)(x)) << WATCHDOG_EDPWDOGC_EDPWDOGC_SHIFT)) & WATCHDOG_EDPWDOGC_EDPWDOGC_MASK)
/*! @} */

/*! @name ICUWDOGCFG - ICU Watchdog Configuration */
/*! @{ */

#define WATCHDOG_ICUWDOGCFG_ICUWDOG_EN_MASK      (0x1U)
#define WATCHDOG_ICUWDOGCFG_ICUWDOG_EN_SHIFT     (0U)
#define WATCHDOG_ICUWDOGCFG_ICUWDOG_EN_WIDTH     (1U)
#define WATCHDOG_ICUWDOGCFG_ICUWDOG_EN(x)        (((uint32_t)(((uint32_t)(x)) << WATCHDOG_ICUWDOGCFG_ICUWDOG_EN_SHIFT)) & WATCHDOG_ICUWDOGCFG_ICUWDOG_EN_MASK)
/*! @} */

/*! @name ICUWDOGT - ICU Watchdog Threshold Configuration */
/*! @{ */

#define WATCHDOG_ICUWDOGT_ICUWDOGT_MASK          (0xFFFFFFFFU)
#define WATCHDOG_ICUWDOGT_ICUWDOGT_SHIFT         (0U)
#define WATCHDOG_ICUWDOGT_ICUWDOGT_WIDTH         (32U)
#define WATCHDOG_ICUWDOGT_ICUWDOGT(x)            (((uint32_t)(((uint32_t)(x)) << WATCHDOG_ICUWDOGT_ICUWDOGT_SHIFT)) & WATCHDOG_ICUWDOGT_ICUWDOGT_MASK)
/*! @} */

/*! @name SYSWDOGSIG - System Watchdog Signal */
/*! @{ */

#define WATCHDOG_SYSWDOGSIG_TASK0_STATE_MASK     (0x3U)
#define WATCHDOG_SYSWDOGSIG_TASK0_STATE_SHIFT    (0U)
#define WATCHDOG_SYSWDOGSIG_TASK0_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK0_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK0_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK0_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK1_STATE_MASK     (0xCU)
#define WATCHDOG_SYSWDOGSIG_TASK1_STATE_SHIFT    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK1_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK1_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK1_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK1_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK2_STATE_MASK     (0x30U)
#define WATCHDOG_SYSWDOGSIG_TASK2_STATE_SHIFT    (4U)
#define WATCHDOG_SYSWDOGSIG_TASK2_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK2_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK2_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK2_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK3_STATE_MASK     (0xC0U)
#define WATCHDOG_SYSWDOGSIG_TASK3_STATE_SHIFT    (6U)
#define WATCHDOG_SYSWDOGSIG_TASK3_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK3_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK3_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK3_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK4_STATE_MASK     (0x300U)
#define WATCHDOG_SYSWDOGSIG_TASK4_STATE_SHIFT    (8U)
#define WATCHDOG_SYSWDOGSIG_TASK4_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK4_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK4_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK4_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK5_STATE_MASK     (0xC00U)
#define WATCHDOG_SYSWDOGSIG_TASK5_STATE_SHIFT    (10U)
#define WATCHDOG_SYSWDOGSIG_TASK5_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK5_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK5_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK5_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK6_STATE_MASK     (0x3000U)
#define WATCHDOG_SYSWDOGSIG_TASK6_STATE_SHIFT    (12U)
#define WATCHDOG_SYSWDOGSIG_TASK6_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK6_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK6_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK6_STATE_MASK)

#define WATCHDOG_SYSWDOGSIG_TASK7_STATE_MASK     (0xC000U)
#define WATCHDOG_SYSWDOGSIG_TASK7_STATE_SHIFT    (14U)
#define WATCHDOG_SYSWDOGSIG_TASK7_STATE_WIDTH    (2U)
#define WATCHDOG_SYSWDOGSIG_TASK7_STATE(x)       (((uint32_t)(((uint32_t)(x)) << WATCHDOG_SYSWDOGSIG_TASK7_STATE_SHIFT)) & WATCHDOG_SYSWDOGSIG_TASK7_STATE_MASK)
/*! @} */

/*! @name ICUWDOGC - ICU Watchdog Count Value */
/*! @{ */

#define WATCHDOG_ICUWDOGC_ICUWDOGC_MASK          (0xFFFFFFFFU)
#define WATCHDOG_ICUWDOGC_ICUWDOGC_SHIFT         (0U)
#define WATCHDOG_ICUWDOGC_ICUWDOGC_WIDTH         (32U)
#define WATCHDOG_ICUWDOGC_ICUWDOGC(x)            (((uint32_t)(((uint32_t)(x)) << WATCHDOG_ICUWDOGC_ICUWDOGC_SHIFT)) & WATCHDOG_ICUWDOGC_ICUWDOGC_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group WATCHDOG_Register_Masks */

/*!
 * @}
 */ /* end of group WATCHDOG_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_WATCHDOG_H_) */
