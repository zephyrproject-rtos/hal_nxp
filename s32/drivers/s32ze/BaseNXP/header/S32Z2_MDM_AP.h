/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_MDM_AP.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_MDM_AP
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
#if !defined(S32Z2_MDM_AP_H_)  /* Check if memory map has not been already included */
#define S32Z2_MDM_AP_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MDM_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MDM_AP_Peripheral_Access_Layer MDM_AP Peripheral Access Layer
 * @{
 */

/** MDM_AP - Register Layout Typedef */
typedef struct {
  __I  uint32_t STATUS;                            /**< MDM_AP status, offset: 0x0 */
  __IO uint32_t CONTROL;                           /**< MDM_AP control, offset: 0x4 */
  uint8_t RESERVED_0[56];
  __I  uint32_t STATUS2;                           /**< MDM_AP status 2, offset: 0x40 */
  __IO uint32_t CONTROL2;                          /**< MDM_AP Control 2, offset: 0x44 */
  uint8_t RESERVED_1[4];
  __IO uint32_t CONTROL3;                          /**< MDM_AP Control 3, offset: 0x4C */
  uint8_t RESERVED_2[32];
  __IO uint32_t RTU0_CORE_0_IP_DBG;                /**< RTU0 core 0 debug, offset: 0x70 */
  __IO uint32_t RTU0_CORE_1_IP_DBG;                /**< RTU0 core 1 debug, offset: 0x74 */
  __IO uint32_t RTU0_CORE_2_IP_DBG;                /**< RTU0 core 2 debug, offset: 0x78 */
  __IO uint32_t RTU0_CORE_3_IP_DBG;                /**< RTU0 core 3 debug, offset: 0x7C */
  __IO uint32_t RTU1_CORE_0_IP_DBG;                /**< RTU1 core 0 debug, offset: 0x80 */
  __IO uint32_t RTU1_CORE_1_IP_DBG;                /**< RTU1 core 1 debug, offset: 0x84 */
  __IO uint32_t RTU1_CORE_2_IP_DBG;                /**< RTU1 core 2 debug, offset: 0x88 */
  __IO uint32_t RTU1_CORE_3_IP_DBG;                /**< RTU1 core 3 debug, offset: 0x8C */
  __IO uint32_t SMU_CORTEX_M33_IP_DBG;             /**< Cortex-M33 Core Debug, offset: 0x90 */
  __IO uint32_t CE_CORTEX_M33_0_IP_DBG;            /**< CE Cortex-M33 Core 0 Debug, offset: 0x94 */
  __IO uint32_t CE_CORTEX_M33_1_IP_DBG;            /**< CE Cortex-M33 Core 1 Debug, offset: 0x98 */
  uint8_t RESERVED_3[4];
  __IO uint32_t RTU0_SWTMASK_IP_DBG;               /**< RTU0 SWT debug mask register, offset: 0xA0 */
  __IO uint32_t RTU1_SWTMASK_IP_DBG;               /**< RTU1 SWT debug mask register, offset: 0xA4 */
  uint8_t RESERVED_4[8];
  __IO uint32_t RTU0_STMMASK_IP_DBG;               /**< RTU0 STM debug mask register, offset: 0xB0 */
  __IO uint32_t RTU1_STMMASK_IP_DBG;               /**< RTU1 STM debug mask register, offset: 0xB4 */
  uint8_t RESERVED_5[8];
  __IO uint32_t DBGENCNTRL;                        /**< Debug enable control, offset: 0xC0 */
  uint8_t RESERVED_6[4];
  __IO uint32_t DBGENCNTRL2;                       /**< Debug enable control 2, offset: 0xC8 */
  uint8_t RESERVED_7[4];
  __IO uint32_t DBGENCNTRL3;                       /**< Debug enable control 3, offset: 0xD0 */
  uint8_t RESERVED_8[44];
  __IO uint32_t DTS_ENABLE;                        /**< DTS output enable register, offset: 0x100 */
  uint8_t RESERVED_9[12];
  __IO uint32_t DTS_STARTUP;                       /**< DTS startup register, offset: 0x110 */
  __IO uint32_t DTS_STARTUP_B;                     /**< DTS startup register B, offset: 0x114 */
  __IO uint32_t DTS_STARTUP_C;                     /**< DTS startup register C, offset: 0x118 */
  __IO uint32_t DTS_STARTUP_D;                     /**< DTS startup register D, offset: 0x11C */
  __IO uint32_t DTS_SEMAPHORE;                     /**< DTS SEMAPHORE register, offset: 0x120 */
  uint8_t RESERVED_10[12];
  __IO uint32_t DTS_SEMAPHORE_B;                   /**< DTS SEMAPHORE_B register, offset: 0x130 */
  uint8_t RESERVED_11[12];
  __IO uint32_t DTS_SEMAPHORE_C;                   /**< DTS SEMAPHORE_C register, offset: 0x140 */
  uint8_t RESERVED_12[12];
  __IO uint32_t DTS_SEMAPHORE_D;                   /**< DTS SEMAPHORE_D register, offset: 0x150 */
  uint8_t RESERVED_13[3240];
  __I  uint32_t IDR;                               /**< Identification Register, offset: 0xDFC */
  uint8_t RESERVED_14[444];
  __I  uint32_t DEVARCH;                           /**< CoreSight Device Architecture Register, offset: 0xFBC */
  uint8_t RESERVED_15[12];
  __I  uint32_t DEVTYPE;                           /**< CoreSight Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PIDR4;                             /**< CoreSight Peripheral Identification Register 4, offset: 0xFD0 */
  uint8_t RESERVED_16[12];
  __I  uint32_t PIDR0;                             /**< CoreSight Peripheral Identification Register 0, offset: 0xFE0 */
  __I  uint32_t PIDR1;                             /**< CoreSight Peripheral Identification Register 1, offset: 0xFE4 */
  __I  uint32_t PIDR2;                             /**< CoreSight Peripheral Identification Register 2, offset: 0xFE8 */
  __I  uint32_t PIDR3;                             /**< CoreSight Peripheral Identification Register 3, offset: 0xFEC */
  __I  uint32_t CIDR0;                             /**< CoreSight Component Identification Register 0, offset: 0xFF0 */
  __I  uint32_t CIDR1;                             /**< CoreSight Component Identification Register 1, offset: 0xFF4 */
  __I  uint32_t CIDR2;                             /**< CoreSight Component Identification Register 2, offset: 0xFF8 */
  __I  uint32_t CIDR3;                             /**< CoreSight Component Identification Register 3, offset: 0xFFC */
} MDM_AP_Type, *MDM_AP_MemMapPtr;

/** Number of instances of the MDM_AP module. */
#define MDM_AP_INSTANCE_COUNT                    (1u)

/* MDM_AP - Peripheral instance base addresses */
/** Peripheral MDM_AP base address */
#define IP_MDM_AP_BASE                           (0x4DC11000u)
/** Peripheral MDM_AP base pointer */
#define IP_MDM_AP                                ((MDM_AP_Type *)IP_MDM_AP_BASE)
/** Array initializer of MDM_AP peripheral base addresses */
#define IP_MDM_AP_BASE_ADDRS                     { IP_MDM_AP_BASE }
/** Array initializer of MDM_AP peripheral base pointers */
#define IP_MDM_AP_BASE_PTRS                      { IP_MDM_AP }

/* ----------------------------------------------------------------------------
   -- MDM_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MDM_AP_Register_Masks MDM_AP Register Masks
 * @{
 */

/*! @name STATUS - MDM_AP status */
/*! @{ */

#define MDM_AP_STATUS_SYSTEM_RESET_MASK          (0x4U)
#define MDM_AP_STATUS_SYSTEM_RESET_SHIFT         (2U)
#define MDM_AP_STATUS_SYSTEM_RESET_WIDTH         (1U)
#define MDM_AP_STATUS_SYSTEM_RESET(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_SYSTEM_RESET_SHIFT)) & MDM_AP_STATUS_SYSTEM_RESET_MASK)

#define MDM_AP_STATUS_CSYSPWRUPREQ_MASK          (0x40U)
#define MDM_AP_STATUS_CSYSPWRUPREQ_SHIFT         (6U)
#define MDM_AP_STATUS_CSYSPWRUPREQ_WIDTH         (1U)
#define MDM_AP_STATUS_CSYSPWRUPREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CSYSPWRUPREQ_SHIFT)) & MDM_AP_STATUS_CSYSPWRUPREQ_MASK)

#define MDM_AP_STATUS_CDBGPWRUPREQ_MASK          (0x80U)
#define MDM_AP_STATUS_CDBGPWRUPREQ_SHIFT         (7U)
#define MDM_AP_STATUS_CDBGPWRUPREQ_WIDTH         (1U)
#define MDM_AP_STATUS_CDBGPWRUPREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CDBGPWRUPREQ_SHIFT)) & MDM_AP_STATUS_CDBGPWRUPREQ_MASK)

#define MDM_AP_STATUS_JTAG_ACTIVE_MASK           (0x100U)
#define MDM_AP_STATUS_JTAG_ACTIVE_SHIFT          (8U)
#define MDM_AP_STATUS_JTAG_ACTIVE_WIDTH          (1U)
#define MDM_AP_STATUS_JTAG_ACTIVE(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_JTAG_ACTIVE_SHIFT)) & MDM_AP_STATUS_JTAG_ACTIVE_MASK)

#define MDM_AP_STATUS_SMU_HALTED_MASK            (0x1000U)
#define MDM_AP_STATUS_SMU_HALTED_SHIFT           (12U)
#define MDM_AP_STATUS_SMU_HALTED_WIDTH           (1U)
#define MDM_AP_STATUS_SMU_HALTED(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_SMU_HALTED_SHIFT)) & MDM_AP_STATUS_SMU_HALTED_MASK)

#define MDM_AP_STATUS_CE_A_HALTED_MASK           (0x2000U)
#define MDM_AP_STATUS_CE_A_HALTED_SHIFT          (13U)
#define MDM_AP_STATUS_CE_A_HALTED_WIDTH          (1U)
#define MDM_AP_STATUS_CE_A_HALTED(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_A_HALTED_SHIFT)) & MDM_AP_STATUS_CE_A_HALTED_MASK)

#define MDM_AP_STATUS_CE_B_HALTED_MASK           (0x4000U)
#define MDM_AP_STATUS_CE_B_HALTED_SHIFT          (14U)
#define MDM_AP_STATUS_CE_B_HALTED_WIDTH          (1U)
#define MDM_AP_STATUS_CE_B_HALTED(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_B_HALTED_SHIFT)) & MDM_AP_STATUS_CE_B_HALTED_MASK)

#define MDM_AP_STATUS_SMU_SLEEPDEEP_MASK         (0x10000U)
#define MDM_AP_STATUS_SMU_SLEEPDEEP_SHIFT        (16U)
#define MDM_AP_STATUS_SMU_SLEEPDEEP_WIDTH        (1U)
#define MDM_AP_STATUS_SMU_SLEEPDEEP(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_SMU_SLEEPDEEP_SHIFT)) & MDM_AP_STATUS_SMU_SLEEPDEEP_MASK)

#define MDM_AP_STATUS_CE_A_SLEEPDEEP_MASK        (0x20000U)
#define MDM_AP_STATUS_CE_A_SLEEPDEEP_SHIFT       (17U)
#define MDM_AP_STATUS_CE_A_SLEEPDEEP_WIDTH       (1U)
#define MDM_AP_STATUS_CE_A_SLEEPDEEP(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_A_SLEEPDEEP_SHIFT)) & MDM_AP_STATUS_CE_A_SLEEPDEEP_MASK)

#define MDM_AP_STATUS_CE_B_SLEEPDEEP_MASK        (0x40000U)
#define MDM_AP_STATUS_CE_B_SLEEPDEEP_SHIFT       (18U)
#define MDM_AP_STATUS_CE_B_SLEEPDEEP_WIDTH       (1U)
#define MDM_AP_STATUS_CE_B_SLEEPDEEP(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_B_SLEEPDEEP_SHIFT)) & MDM_AP_STATUS_CE_B_SLEEPDEEP_MASK)

#define MDM_AP_STATUS_SMU_SLEEPING_MASK          (0x100000U)
#define MDM_AP_STATUS_SMU_SLEEPING_SHIFT         (20U)
#define MDM_AP_STATUS_SMU_SLEEPING_WIDTH         (1U)
#define MDM_AP_STATUS_SMU_SLEEPING(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_SMU_SLEEPING_SHIFT)) & MDM_AP_STATUS_SMU_SLEEPING_MASK)

#define MDM_AP_STATUS_CE_A_SLEEPING_MASK         (0x200000U)
#define MDM_AP_STATUS_CE_A_SLEEPING_SHIFT        (21U)
#define MDM_AP_STATUS_CE_A_SLEEPING_WIDTH        (1U)
#define MDM_AP_STATUS_CE_A_SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_A_SLEEPING_SHIFT)) & MDM_AP_STATUS_CE_A_SLEEPING_MASK)

#define MDM_AP_STATUS_CE_B_SLEEPING_MASK         (0x400000U)
#define MDM_AP_STATUS_CE_B_SLEEPING_SHIFT        (22U)
#define MDM_AP_STATUS_CE_B_SLEEPING_WIDTH        (1U)
#define MDM_AP_STATUS_CE_B_SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_B_SLEEPING_SHIFT)) & MDM_AP_STATUS_CE_B_SLEEPING_MASK)

#define MDM_AP_STATUS_SMU_DBGRSTRTS_MASK         (0x10000000U)
#define MDM_AP_STATUS_SMU_DBGRSTRTS_SHIFT        (28U)
#define MDM_AP_STATUS_SMU_DBGRSTRTS_WIDTH        (1U)
#define MDM_AP_STATUS_SMU_DBGRSTRTS(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_SMU_DBGRSTRTS_SHIFT)) & MDM_AP_STATUS_SMU_DBGRSTRTS_MASK)

#define MDM_AP_STATUS_CE_A_DBGRSTRTS_MASK        (0x20000000U)
#define MDM_AP_STATUS_CE_A_DBGRSTRTS_SHIFT       (29U)
#define MDM_AP_STATUS_CE_A_DBGRSTRTS_WIDTH       (1U)
#define MDM_AP_STATUS_CE_A_DBGRSTRTS(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_A_DBGRSTRTS_SHIFT)) & MDM_AP_STATUS_CE_A_DBGRSTRTS_MASK)

#define MDM_AP_STATUS_CE_B_DBGRSTRTS_MASK        (0x40000000U)
#define MDM_AP_STATUS_CE_B_DBGRSTRTS_SHIFT       (30U)
#define MDM_AP_STATUS_CE_B_DBGRSTRTS_WIDTH       (1U)
#define MDM_AP_STATUS_CE_B_DBGRSTRTS(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS_CE_B_DBGRSTRTS_SHIFT)) & MDM_AP_STATUS_CE_B_DBGRSTRTS_MASK)
/*! @} */

/*! @name CONTROL - MDM_AP control */
/*! @{ */

#define MDM_AP_CONTROL_ETR_HANDSHAKE_0_MASK      (0x40U)
#define MDM_AP_CONTROL_ETR_HANDSHAKE_0_SHIFT     (6U)
#define MDM_AP_CONTROL_ETR_HANDSHAKE_0_WIDTH     (1U)
#define MDM_AP_CONTROL_ETR_HANDSHAKE_0(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_ETR_HANDSHAKE_0_SHIFT)) & MDM_AP_CONTROL_ETR_HANDSHAKE_0_MASK)

#define MDM_AP_CONTROL_ETR_HANDSHAKE_1_MASK      (0x80U)
#define MDM_AP_CONTROL_ETR_HANDSHAKE_1_SHIFT     (7U)
#define MDM_AP_CONTROL_ETR_HANDSHAKE_1_WIDTH     (1U)
#define MDM_AP_CONTROL_ETR_HANDSHAKE_1(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_ETR_HANDSHAKE_1_SHIFT)) & MDM_AP_CONTROL_ETR_HANDSHAKE_1_MASK)

#define MDM_AP_CONTROL_SMU_EDBGREQ_MASK          (0x100U)
#define MDM_AP_CONTROL_SMU_EDBGREQ_SHIFT         (8U)
#define MDM_AP_CONTROL_SMU_EDBGREQ_WIDTH         (1U)
#define MDM_AP_CONTROL_SMU_EDBGREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_SMU_EDBGREQ_SHIFT)) & MDM_AP_CONTROL_SMU_EDBGREQ_MASK)

#define MDM_AP_CONTROL_COMMS_0_EDBGREQ_MASK      (0x200U)
#define MDM_AP_CONTROL_COMMS_0_EDBGREQ_SHIFT     (9U)
#define MDM_AP_CONTROL_COMMS_0_EDBGREQ_WIDTH     (1U)
#define MDM_AP_CONTROL_COMMS_0_EDBGREQ(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_COMMS_0_EDBGREQ_SHIFT)) & MDM_AP_CONTROL_COMMS_0_EDBGREQ_MASK)

#define MDM_AP_CONTROL_COMMS_1_EDBGREQ_MASK      (0x400U)
#define MDM_AP_CONTROL_COMMS_1_EDBGREQ_SHIFT     (10U)
#define MDM_AP_CONTROL_COMMS_1_EDBGREQ_WIDTH     (1U)
#define MDM_AP_CONTROL_COMMS_1_EDBGREQ(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_COMMS_1_EDBGREQ_SHIFT)) & MDM_AP_CONTROL_COMMS_1_EDBGREQ_MASK)

#define MDM_AP_CONTROL_DIS_POR_WDOG_MSK_MASK     (0x8000U)
#define MDM_AP_CONTROL_DIS_POR_WDOG_MSK_SHIFT    (15U)
#define MDM_AP_CONTROL_DIS_POR_WDOG_MSK_WIDTH    (1U)
#define MDM_AP_CONTROL_DIS_POR_WDOG_MSK(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_DIS_POR_WDOG_MSK_SHIFT)) & MDM_AP_CONTROL_DIS_POR_WDOG_MSK_MASK)

#define MDM_AP_CONTROL_TPIU_OVERRIDE_MASK        (0x100000U)
#define MDM_AP_CONTROL_TPIU_OVERRIDE_SHIFT       (20U)
#define MDM_AP_CONTROL_TPIU_OVERRIDE_WIDTH       (1U)
#define MDM_AP_CONTROL_TPIU_OVERRIDE(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_TPIU_OVERRIDE_SHIFT)) & MDM_AP_CONTROL_TPIU_OVERRIDE_MASK)

#define MDM_AP_CONTROL_ETR_OVERRIDE_SMU_MASK     (0x200000U)
#define MDM_AP_CONTROL_ETR_OVERRIDE_SMU_SHIFT    (21U)
#define MDM_AP_CONTROL_ETR_OVERRIDE_SMU_WIDTH    (1U)
#define MDM_AP_CONTROL_ETR_OVERRIDE_SMU(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_ETR_OVERRIDE_SMU_SHIFT)) & MDM_AP_CONTROL_ETR_OVERRIDE_SMU_MASK)

#define MDM_AP_CONTROL_MSK_DBG_FAULT_MASK        (0x800000U)
#define MDM_AP_CONTROL_MSK_DBG_FAULT_SHIFT       (23U)
#define MDM_AP_CONTROL_MSK_DBG_FAULT_WIDTH       (1U)
#define MDM_AP_CONTROL_MSK_DBG_FAULT(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_MSK_DBG_FAULT_SHIFT)) & MDM_AP_CONTROL_MSK_DBG_FAULT_MASK)

#define MDM_AP_CONTROL_MSK_FCCU_RST_TRIGGER_MASK (0x1000000U)
#define MDM_AP_CONTROL_MSK_FCCU_RST_TRIGGER_SHIFT (24U)
#define MDM_AP_CONTROL_MSK_FCCU_RST_TRIGGER_WIDTH (1U)
#define MDM_AP_CONTROL_MSK_FCCU_RST_TRIGGER(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_MSK_FCCU_RST_TRIGGER_SHIFT)) & MDM_AP_CONTROL_MSK_FCCU_RST_TRIGGER_MASK)

#define MDM_AP_CONTROL_SMU_DBGRSTRT_MASK         (0x10000000U)
#define MDM_AP_CONTROL_SMU_DBGRSTRT_SHIFT        (28U)
#define MDM_AP_CONTROL_SMU_DBGRSTRT_WIDTH        (1U)
#define MDM_AP_CONTROL_SMU_DBGRSTRT(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_SMU_DBGRSTRT_SHIFT)) & MDM_AP_CONTROL_SMU_DBGRSTRT_MASK)

#define MDM_AP_CONTROL_CE_A_DBGRSTRT_MASK        (0x20000000U)
#define MDM_AP_CONTROL_CE_A_DBGRSTRT_SHIFT       (29U)
#define MDM_AP_CONTROL_CE_A_DBGRSTRT_WIDTH       (1U)
#define MDM_AP_CONTROL_CE_A_DBGRSTRT(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_CE_A_DBGRSTRT_SHIFT)) & MDM_AP_CONTROL_CE_A_DBGRSTRT_MASK)

#define MDM_AP_CONTROL_CE_B_DBGRSTRT_MASK        (0x40000000U)
#define MDM_AP_CONTROL_CE_B_DBGRSTRT_SHIFT       (30U)
#define MDM_AP_CONTROL_CE_B_DBGRSTRT_WIDTH       (1U)
#define MDM_AP_CONTROL_CE_B_DBGRSTRT(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL_CE_B_DBGRSTRT_SHIFT)) & MDM_AP_CONTROL_CE_B_DBGRSTRT_MASK)
/*! @} */

/*! @name STATUS2 - MDM_AP status 2 */
/*! @{ */

#define MDM_AP_STATUS2_CR52_RTU0_0_DBGMODE_MASK  (0x1U)
#define MDM_AP_STATUS2_CR52_RTU0_0_DBGMODE_SHIFT (0U)
#define MDM_AP_STATUS2_CR52_RTU0_0_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU0_0_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_0_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_0_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_1_DBGMODE_MASK  (0x2U)
#define MDM_AP_STATUS2_CR52_RTU0_1_DBGMODE_SHIFT (1U)
#define MDM_AP_STATUS2_CR52_RTU0_1_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU0_1_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_1_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_1_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_2_DBGMODE_MASK  (0x4U)
#define MDM_AP_STATUS2_CR52_RTU0_2_DBGMODE_SHIFT (2U)
#define MDM_AP_STATUS2_CR52_RTU0_2_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU0_2_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_2_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_2_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_3_DBGMODE_MASK  (0x8U)
#define MDM_AP_STATUS2_CR52_RTU0_3_DBGMODE_SHIFT (3U)
#define MDM_AP_STATUS2_CR52_RTU0_3_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU0_3_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_3_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_3_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_0_WFI_MASK      (0x10U)
#define MDM_AP_STATUS2_CR52_RTU0_0_WFI_SHIFT     (4U)
#define MDM_AP_STATUS2_CR52_RTU0_0_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_0_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_0_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_0_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_1_WFI_MASK      (0x20U)
#define MDM_AP_STATUS2_CR52_RTU0_1_WFI_SHIFT     (5U)
#define MDM_AP_STATUS2_CR52_RTU0_1_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_1_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_1_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_1_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_2_WFI_MASK      (0x40U)
#define MDM_AP_STATUS2_CR52_RTU0_2_WFI_SHIFT     (6U)
#define MDM_AP_STATUS2_CR52_RTU0_2_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_2_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_2_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_2_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_3_WFI_MASK      (0x80U)
#define MDM_AP_STATUS2_CR52_RTU0_3_WFI_SHIFT     (7U)
#define MDM_AP_STATUS2_CR52_RTU0_3_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_3_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_3_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_3_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_0_WFE_MASK      (0x100U)
#define MDM_AP_STATUS2_CR52_RTU0_0_WFE_SHIFT     (8U)
#define MDM_AP_STATUS2_CR52_RTU0_0_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_0_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_0_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_0_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_1_WFE_MASK      (0x200U)
#define MDM_AP_STATUS2_CR52_RTU0_1_WFE_SHIFT     (9U)
#define MDM_AP_STATUS2_CR52_RTU0_1_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_1_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_1_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_1_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_2_WFE_MASK      (0x400U)
#define MDM_AP_STATUS2_CR52_RTU0_2_WFE_SHIFT     (10U)
#define MDM_AP_STATUS2_CR52_RTU0_2_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_2_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_2_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_2_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU0_3_WFE_MASK      (0x800U)
#define MDM_AP_STATUS2_CR52_RTU0_3_WFE_SHIFT     (11U)
#define MDM_AP_STATUS2_CR52_RTU0_3_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU0_3_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU0_3_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU0_3_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_0_DBGMODE_MASK  (0x10000U)
#define MDM_AP_STATUS2_CR52_RTU1_0_DBGMODE_SHIFT (16U)
#define MDM_AP_STATUS2_CR52_RTU1_0_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU1_0_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_0_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_0_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_1_DBGMODE_MASK  (0x20000U)
#define MDM_AP_STATUS2_CR52_RTU1_1_DBGMODE_SHIFT (17U)
#define MDM_AP_STATUS2_CR52_RTU1_1_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU1_1_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_1_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_1_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_2_DBGMODE_MASK  (0x40000U)
#define MDM_AP_STATUS2_CR52_RTU1_2_DBGMODE_SHIFT (18U)
#define MDM_AP_STATUS2_CR52_RTU1_2_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU1_2_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_2_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_2_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_3_DBGMODE_MASK  (0x80000U)
#define MDM_AP_STATUS2_CR52_RTU1_3_DBGMODE_SHIFT (19U)
#define MDM_AP_STATUS2_CR52_RTU1_3_DBGMODE_WIDTH (1U)
#define MDM_AP_STATUS2_CR52_RTU1_3_DBGMODE(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_3_DBGMODE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_3_DBGMODE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_0_WFI_MASK      (0x100000U)
#define MDM_AP_STATUS2_CR52_RTU1_0_WFI_SHIFT     (20U)
#define MDM_AP_STATUS2_CR52_RTU1_0_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_0_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_0_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_0_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_1_WFI_MASK      (0x200000U)
#define MDM_AP_STATUS2_CR52_RTU1_1_WFI_SHIFT     (21U)
#define MDM_AP_STATUS2_CR52_RTU1_1_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_1_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_1_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_1_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_2_WFI_MASK      (0x400000U)
#define MDM_AP_STATUS2_CR52_RTU1_2_WFI_SHIFT     (22U)
#define MDM_AP_STATUS2_CR52_RTU1_2_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_2_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_2_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_2_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_3_WFI_MASK      (0x800000U)
#define MDM_AP_STATUS2_CR52_RTU1_3_WFI_SHIFT     (23U)
#define MDM_AP_STATUS2_CR52_RTU1_3_WFI_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_3_WFI(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_3_WFI_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_3_WFI_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_0_WFE_MASK      (0x1000000U)
#define MDM_AP_STATUS2_CR52_RTU1_0_WFE_SHIFT     (24U)
#define MDM_AP_STATUS2_CR52_RTU1_0_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_0_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_0_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_0_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_1_WFE_MASK      (0x2000000U)
#define MDM_AP_STATUS2_CR52_RTU1_1_WFE_SHIFT     (25U)
#define MDM_AP_STATUS2_CR52_RTU1_1_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_1_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_1_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_1_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_2_WFE_MASK      (0x4000000U)
#define MDM_AP_STATUS2_CR52_RTU1_2_WFE_SHIFT     (26U)
#define MDM_AP_STATUS2_CR52_RTU1_2_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_2_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_2_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_2_WFE_MASK)

#define MDM_AP_STATUS2_CR52_RTU1_3_WFE_MASK      (0x8000000U)
#define MDM_AP_STATUS2_CR52_RTU1_3_WFE_SHIFT     (27U)
#define MDM_AP_STATUS2_CR52_RTU1_3_WFE_WIDTH     (1U)
#define MDM_AP_STATUS2_CR52_RTU1_3_WFE(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_STATUS2_CR52_RTU1_3_WFE_SHIFT)) & MDM_AP_STATUS2_CR52_RTU1_3_WFE_MASK)
/*! @} */

/*! @name CONTROL2 - MDM_AP Control 2 */
/*! @{ */

#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_0_MASK (0x40U)
#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_0_SHIFT (6U)
#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_0_WIDTH (1U)
#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_0(x)  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_0_SHIFT)) & MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_0_MASK)

#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_1_MASK (0x80U)
#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_1_SHIFT (7U)
#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_1_WIDTH (1U)
#define MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_1(x)  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_1_SHIFT)) & MDM_AP_CONTROL2_RTU0_ETR_HANDSHAKE_1_MASK)

#define MDM_AP_CONTROL2_CR52_RTU0_0_EDBGREQ_MASK (0x10000U)
#define MDM_AP_CONTROL2_CR52_RTU0_0_EDBGREQ_SHIFT (16U)
#define MDM_AP_CONTROL2_CR52_RTU0_0_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL2_CR52_RTU0_0_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL2_CR52_RTU0_0_EDBGREQ_SHIFT)) & MDM_AP_CONTROL2_CR52_RTU0_0_EDBGREQ_MASK)

#define MDM_AP_CONTROL2_CR52_RTU0_1_EDBGREQ_MASK (0x20000U)
#define MDM_AP_CONTROL2_CR52_RTU0_1_EDBGREQ_SHIFT (17U)
#define MDM_AP_CONTROL2_CR52_RTU0_1_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL2_CR52_RTU0_1_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL2_CR52_RTU0_1_EDBGREQ_SHIFT)) & MDM_AP_CONTROL2_CR52_RTU0_1_EDBGREQ_MASK)

#define MDM_AP_CONTROL2_CR52_RTU0_2_EDBGREQ_MASK (0x40000U)
#define MDM_AP_CONTROL2_CR52_RTU0_2_EDBGREQ_SHIFT (18U)
#define MDM_AP_CONTROL2_CR52_RTU0_2_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL2_CR52_RTU0_2_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL2_CR52_RTU0_2_EDBGREQ_SHIFT)) & MDM_AP_CONTROL2_CR52_RTU0_2_EDBGREQ_MASK)

#define MDM_AP_CONTROL2_CR52_RTU0_3_EDBGREQ_MASK (0x80000U)
#define MDM_AP_CONTROL2_CR52_RTU0_3_EDBGREQ_SHIFT (19U)
#define MDM_AP_CONTROL2_CR52_RTU0_3_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL2_CR52_RTU0_3_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL2_CR52_RTU0_3_EDBGREQ_SHIFT)) & MDM_AP_CONTROL2_CR52_RTU0_3_EDBGREQ_MASK)
/*! @} */

/*! @name CONTROL3 - MDM_AP Control 3 */
/*! @{ */

#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_0_MASK (0x40U)
#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_0_SHIFT (6U)
#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_0_WIDTH (1U)
#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_0(x)  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_0_SHIFT)) & MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_0_MASK)

#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_1_MASK (0x80U)
#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_1_SHIFT (7U)
#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_1_WIDTH (1U)
#define MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_1(x)  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_1_SHIFT)) & MDM_AP_CONTROL3_RTU1_ETR_HANDSHAKE_1_MASK)

#define MDM_AP_CONTROL3_CR52_RTU1_0_EDBGREQ_MASK (0x10000U)
#define MDM_AP_CONTROL3_CR52_RTU1_0_EDBGREQ_SHIFT (16U)
#define MDM_AP_CONTROL3_CR52_RTU1_0_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL3_CR52_RTU1_0_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL3_CR52_RTU1_0_EDBGREQ_SHIFT)) & MDM_AP_CONTROL3_CR52_RTU1_0_EDBGREQ_MASK)

#define MDM_AP_CONTROL3_CR52_RTU1_1_EDBGREQ_MASK (0x20000U)
#define MDM_AP_CONTROL3_CR52_RTU1_1_EDBGREQ_SHIFT (17U)
#define MDM_AP_CONTROL3_CR52_RTU1_1_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL3_CR52_RTU1_1_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL3_CR52_RTU1_1_EDBGREQ_SHIFT)) & MDM_AP_CONTROL3_CR52_RTU1_1_EDBGREQ_MASK)

#define MDM_AP_CONTROL3_CR52_RTU1_2_EDBGREQ_MASK (0x40000U)
#define MDM_AP_CONTROL3_CR52_RTU1_2_EDBGREQ_SHIFT (18U)
#define MDM_AP_CONTROL3_CR52_RTU1_2_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL3_CR52_RTU1_2_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL3_CR52_RTU1_2_EDBGREQ_SHIFT)) & MDM_AP_CONTROL3_CR52_RTU1_2_EDBGREQ_MASK)

#define MDM_AP_CONTROL3_CR52_RTU1_3_EDBGREQ_MASK (0x80000U)
#define MDM_AP_CONTROL3_CR52_RTU1_3_EDBGREQ_SHIFT (19U)
#define MDM_AP_CONTROL3_CR52_RTU1_3_EDBGREQ_WIDTH (1U)
#define MDM_AP_CONTROL3_CR52_RTU1_3_EDBGREQ(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_CONTROL3_CR52_RTU1_3_EDBGREQ_SHIFT)) & MDM_AP_CONTROL3_CR52_RTU1_3_EDBGREQ_MASK)
/*! @} */

/*! @name RTU0_CORE_0_IP_DBG - RTU0 core 0 debug */
/*! @{ */

#define MDM_AP_RTU0_CORE_0_IP_DBG_RTU0_0_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU0_CORE_0_IP_DBG_RTU0_0_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU0_CORE_0_IP_DBG_RTU0_0_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU0_CORE_0_IP_DBG_RTU0_0_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_CORE_0_IP_DBG_RTU0_0_IP_DBGDIS_SHIFT)) & MDM_AP_RTU0_CORE_0_IP_DBG_RTU0_0_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU0_CORE_1_IP_DBG - RTU0 core 1 debug */
/*! @{ */

#define MDM_AP_RTU0_CORE_1_IP_DBG_RTU0_1_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU0_CORE_1_IP_DBG_RTU0_1_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU0_CORE_1_IP_DBG_RTU0_1_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU0_CORE_1_IP_DBG_RTU0_1_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_CORE_1_IP_DBG_RTU0_1_IP_DBGDIS_SHIFT)) & MDM_AP_RTU0_CORE_1_IP_DBG_RTU0_1_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU0_CORE_2_IP_DBG - RTU0 core 2 debug */
/*! @{ */

#define MDM_AP_RTU0_CORE_2_IP_DBG_RTU0_2_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU0_CORE_2_IP_DBG_RTU0_2_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU0_CORE_2_IP_DBG_RTU0_2_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU0_CORE_2_IP_DBG_RTU0_2_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_CORE_2_IP_DBG_RTU0_2_IP_DBGDIS_SHIFT)) & MDM_AP_RTU0_CORE_2_IP_DBG_RTU0_2_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU0_CORE_3_IP_DBG - RTU0 core 3 debug */
/*! @{ */

#define MDM_AP_RTU0_CORE_3_IP_DBG_RTU0_3_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU0_CORE_3_IP_DBG_RTU0_3_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU0_CORE_3_IP_DBG_RTU0_3_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU0_CORE_3_IP_DBG_RTU0_3_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_CORE_3_IP_DBG_RTU0_3_IP_DBGDIS_SHIFT)) & MDM_AP_RTU0_CORE_3_IP_DBG_RTU0_3_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU1_CORE_0_IP_DBG - RTU1 core 0 debug */
/*! @{ */

#define MDM_AP_RTU1_CORE_0_IP_DBG_RTU1_0_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU1_CORE_0_IP_DBG_RTU1_0_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU1_CORE_0_IP_DBG_RTU1_0_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU1_CORE_0_IP_DBG_RTU1_0_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_CORE_0_IP_DBG_RTU1_0_IP_DBGDIS_SHIFT)) & MDM_AP_RTU1_CORE_0_IP_DBG_RTU1_0_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU1_CORE_1_IP_DBG - RTU1 core 1 debug */
/*! @{ */

#define MDM_AP_RTU1_CORE_1_IP_DBG_RTU1_1_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU1_CORE_1_IP_DBG_RTU1_1_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU1_CORE_1_IP_DBG_RTU1_1_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU1_CORE_1_IP_DBG_RTU1_1_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_CORE_1_IP_DBG_RTU1_1_IP_DBGDIS_SHIFT)) & MDM_AP_RTU1_CORE_1_IP_DBG_RTU1_1_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU1_CORE_2_IP_DBG - RTU1 core 2 debug */
/*! @{ */

#define MDM_AP_RTU1_CORE_2_IP_DBG_RTU1_2_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU1_CORE_2_IP_DBG_RTU1_2_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU1_CORE_2_IP_DBG_RTU1_2_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU1_CORE_2_IP_DBG_RTU1_2_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_CORE_2_IP_DBG_RTU1_2_IP_DBGDIS_SHIFT)) & MDM_AP_RTU1_CORE_2_IP_DBG_RTU1_2_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU1_CORE_3_IP_DBG - RTU1 core 3 debug */
/*! @{ */

#define MDM_AP_RTU1_CORE_3_IP_DBG_RTU1_3_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_RTU1_CORE_3_IP_DBG_RTU1_3_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_RTU1_CORE_3_IP_DBG_RTU1_3_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_RTU1_CORE_3_IP_DBG_RTU1_3_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_CORE_3_IP_DBG_RTU1_3_IP_DBGDIS_SHIFT)) & MDM_AP_RTU1_CORE_3_IP_DBG_RTU1_3_IP_DBGDIS_MASK)
/*! @} */

/*! @name SMU_CORTEX_M33_IP_DBG - Cortex-M33 Core Debug */
/*! @{ */

#define MDM_AP_SMU_CORTEX_M33_IP_DBG_CM33_SMU_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_SMU_CORTEX_M33_IP_DBG_CM33_SMU_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_SMU_CORTEX_M33_IP_DBG_CM33_SMU_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_SMU_CORTEX_M33_IP_DBG_CM33_SMU_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_SMU_CORTEX_M33_IP_DBG_CM33_SMU_IP_DBGDIS_SHIFT)) & MDM_AP_SMU_CORTEX_M33_IP_DBG_CM33_SMU_IP_DBGDIS_MASK)
/*! @} */

/*! @name CE_CORTEX_M33_0_IP_DBG - CE Cortex-M33 Core 0 Debug */
/*! @{ */

#define MDM_AP_CE_CORTEX_M33_0_IP_DBG_CE_CM33_0_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_CE_CORTEX_M33_0_IP_DBG_CE_CM33_0_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_CE_CORTEX_M33_0_IP_DBG_CE_CM33_0_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_CE_CORTEX_M33_0_IP_DBG_CE_CM33_0_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_CE_CORTEX_M33_0_IP_DBG_CE_CM33_0_IP_DBGDIS_SHIFT)) & MDM_AP_CE_CORTEX_M33_0_IP_DBG_CE_CM33_0_IP_DBGDIS_MASK)
/*! @} */

/*! @name CE_CORTEX_M33_1_IP_DBG - CE Cortex-M33 Core 1 Debug */
/*! @{ */

#define MDM_AP_CE_CORTEX_M33_1_IP_DBG_CE_CM33_1_IP_DBGDIS_MASK (0x1U)
#define MDM_AP_CE_CORTEX_M33_1_IP_DBG_CE_CM33_1_IP_DBGDIS_SHIFT (0U)
#define MDM_AP_CE_CORTEX_M33_1_IP_DBG_CE_CM33_1_IP_DBGDIS_WIDTH (1U)
#define MDM_AP_CE_CORTEX_M33_1_IP_DBG_CE_CM33_1_IP_DBGDIS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_CE_CORTEX_M33_1_IP_DBG_CE_CM33_1_IP_DBGDIS_SHIFT)) & MDM_AP_CE_CORTEX_M33_1_IP_DBG_CE_CM33_1_IP_DBGDIS_MASK)
/*! @} */

/*! @name RTU0_SWTMASK_IP_DBG - RTU0 SWT debug mask register */
/*! @{ */

#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT0_MASK_DBG_MASK (0x1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT0_MASK_DBG_SHIFT (0U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT0_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT0_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_SWTMASK_IP_DBG_SWT0_MASK_DBG_SHIFT)) & MDM_AP_RTU0_SWTMASK_IP_DBG_SWT0_MASK_DBG_MASK)

#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT1_MASK_DBG_MASK (0x2U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT1_MASK_DBG_SHIFT (1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT1_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT1_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_SWTMASK_IP_DBG_SWT1_MASK_DBG_SHIFT)) & MDM_AP_RTU0_SWTMASK_IP_DBG_SWT1_MASK_DBG_MASK)

#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT2_MASK_DBG_MASK (0x4U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT2_MASK_DBG_SHIFT (2U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT2_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT2_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_SWTMASK_IP_DBG_SWT2_MASK_DBG_SHIFT)) & MDM_AP_RTU0_SWTMASK_IP_DBG_SWT2_MASK_DBG_MASK)

#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT3_MASK_DBG_MASK (0x8U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT3_MASK_DBG_SHIFT (3U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT3_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT3_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_SWTMASK_IP_DBG_SWT3_MASK_DBG_SHIFT)) & MDM_AP_RTU0_SWTMASK_IP_DBG_SWT3_MASK_DBG_MASK)

#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT4_MASK_DBG_MASK (0x10U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT4_MASK_DBG_SHIFT (4U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT4_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_SWTMASK_IP_DBG_SWT4_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_SWTMASK_IP_DBG_SWT4_MASK_DBG_SHIFT)) & MDM_AP_RTU0_SWTMASK_IP_DBG_SWT4_MASK_DBG_MASK)
/*! @} */

/*! @name RTU1_SWTMASK_IP_DBG - RTU1 SWT debug mask register */
/*! @{ */

#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT0_MASK_DBG_MASK (0x1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT0_MASK_DBG_SHIFT (0U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT0_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT0_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_SWTMASK_IP_DBG_SWT0_MASK_DBG_SHIFT)) & MDM_AP_RTU1_SWTMASK_IP_DBG_SWT0_MASK_DBG_MASK)

#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT1_MASK_DBG_MASK (0x2U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT1_MASK_DBG_SHIFT (1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT1_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT1_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_SWTMASK_IP_DBG_SWT1_MASK_DBG_SHIFT)) & MDM_AP_RTU1_SWTMASK_IP_DBG_SWT1_MASK_DBG_MASK)

#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT2_MASK_DBG_MASK (0x4U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT2_MASK_DBG_SHIFT (2U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT2_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT2_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_SWTMASK_IP_DBG_SWT2_MASK_DBG_SHIFT)) & MDM_AP_RTU1_SWTMASK_IP_DBG_SWT2_MASK_DBG_MASK)

#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT3_MASK_DBG_MASK (0x8U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT3_MASK_DBG_SHIFT (3U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT3_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT3_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_SWTMASK_IP_DBG_SWT3_MASK_DBG_SHIFT)) & MDM_AP_RTU1_SWTMASK_IP_DBG_SWT3_MASK_DBG_MASK)

#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT4_MASK_DBG_MASK (0x10U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT4_MASK_DBG_SHIFT (4U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT4_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_SWTMASK_IP_DBG_SWT4_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_SWTMASK_IP_DBG_SWT4_MASK_DBG_SHIFT)) & MDM_AP_RTU1_SWTMASK_IP_DBG_SWT4_MASK_DBG_MASK)
/*! @} */

/*! @name RTU0_STMMASK_IP_DBG - RTU0 STM debug mask register */
/*! @{ */

#define MDM_AP_RTU0_STMMASK_IP_DBG_STM0_MASK_DBG_MASK (0x1U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM0_MASK_DBG_SHIFT (0U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM0_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM0_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_STMMASK_IP_DBG_STM0_MASK_DBG_SHIFT)) & MDM_AP_RTU0_STMMASK_IP_DBG_STM0_MASK_DBG_MASK)

#define MDM_AP_RTU0_STMMASK_IP_DBG_STM1_MASK_DBG_MASK (0x2U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM1_MASK_DBG_SHIFT (1U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM1_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM1_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_STMMASK_IP_DBG_STM1_MASK_DBG_SHIFT)) & MDM_AP_RTU0_STMMASK_IP_DBG_STM1_MASK_DBG_MASK)

#define MDM_AP_RTU0_STMMASK_IP_DBG_STM2_MASK_DBG_MASK (0x4U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM2_MASK_DBG_SHIFT (2U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM2_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM2_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_STMMASK_IP_DBG_STM2_MASK_DBG_SHIFT)) & MDM_AP_RTU0_STMMASK_IP_DBG_STM2_MASK_DBG_MASK)

#define MDM_AP_RTU0_STMMASK_IP_DBG_STM3_MASK_DBG_MASK (0x8U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM3_MASK_DBG_SHIFT (3U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM3_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU0_STMMASK_IP_DBG_STM3_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU0_STMMASK_IP_DBG_STM3_MASK_DBG_SHIFT)) & MDM_AP_RTU0_STMMASK_IP_DBG_STM3_MASK_DBG_MASK)
/*! @} */

/*! @name RTU1_STMMASK_IP_DBG - RTU1 STM debug mask register */
/*! @{ */

#define MDM_AP_RTU1_STMMASK_IP_DBG_STM0_MASK_DBG_MASK (0x1U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM0_MASK_DBG_SHIFT (0U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM0_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM0_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_STMMASK_IP_DBG_STM0_MASK_DBG_SHIFT)) & MDM_AP_RTU1_STMMASK_IP_DBG_STM0_MASK_DBG_MASK)

#define MDM_AP_RTU1_STMMASK_IP_DBG_STM1_MASK_DBG_MASK (0x2U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM1_MASK_DBG_SHIFT (1U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM1_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM1_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_STMMASK_IP_DBG_STM1_MASK_DBG_SHIFT)) & MDM_AP_RTU1_STMMASK_IP_DBG_STM1_MASK_DBG_MASK)

#define MDM_AP_RTU1_STMMASK_IP_DBG_STM2_MASK_DBG_MASK (0x4U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM2_MASK_DBG_SHIFT (2U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM2_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM2_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_STMMASK_IP_DBG_STM2_MASK_DBG_SHIFT)) & MDM_AP_RTU1_STMMASK_IP_DBG_STM2_MASK_DBG_MASK)

#define MDM_AP_RTU1_STMMASK_IP_DBG_STM3_MASK_DBG_MASK (0x8U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM3_MASK_DBG_SHIFT (3U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM3_MASK_DBG_WIDTH (1U)
#define MDM_AP_RTU1_STMMASK_IP_DBG_STM3_MASK_DBG(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_RTU1_STMMASK_IP_DBG_STM3_MASK_DBG_SHIFT)) & MDM_AP_RTU1_STMMASK_IP_DBG_STM3_MASK_DBG_MASK)
/*! @} */

/*! @name DBGENCNTRL - Debug enable control */
/*! @{ */

#define MDM_AP_DBGENCNTRL_RTU0_HIDEN3_MASK       (0x100U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN3_SHIFT      (8U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN3_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN3(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HIDEN3_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HIDEN3_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN3_MASK      (0x200U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN3_SHIFT     (9U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN3_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN3(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HNIDEN3_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HNIDEN3_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_DBGEN3_MASK       (0x400U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN3_SHIFT      (10U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN3_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN3(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_DBGEN3_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_DBGEN3_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_NIDEN3_MASK       (0x800U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN3_SHIFT      (11U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN3_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN3(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_NIDEN3_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_NIDEN3_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HIDEN2_MASK       (0x4000U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN2_SHIFT      (14U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN2_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN2(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HIDEN2_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HIDEN2_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN2_MASK      (0x8000U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN2_SHIFT     (15U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN2_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN2(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HNIDEN2_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HNIDEN2_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_DBGEN2_MASK       (0x10000U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN2_SHIFT      (16U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN2_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN2(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_DBGEN2_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_DBGEN2_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_NIDEN2_MASK       (0x20000U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN2_SHIFT      (17U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN2_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN2(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_NIDEN2_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_NIDEN2_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HIDEN1_MASK       (0x100000U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN1_SHIFT      (20U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN1_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN1(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HIDEN1_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HIDEN1_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN1_MASK      (0x200000U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN1_SHIFT     (21U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN1_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN1(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HNIDEN1_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HNIDEN1_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_DBGEN1_MASK       (0x400000U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN1_SHIFT      (22U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN1_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN1(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_DBGEN1_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_DBGEN1_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_NIDEN1_MASK       (0x800000U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN1_SHIFT      (23U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN1_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN1(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_NIDEN1_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_NIDEN1_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HIDEN0_MASK       (0x4000000U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN0_SHIFT      (26U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN0_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HIDEN0(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HIDEN0_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HIDEN0_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN0_MASK      (0x8000000U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN0_SHIFT     (27U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN0_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL_RTU0_HNIDEN0(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_HNIDEN0_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_HNIDEN0_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_DBGEN0_MASK       (0x10000000U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN0_SHIFT      (28U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN0_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_DBGEN0(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_DBGEN0_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_DBGEN0_MASK)

#define MDM_AP_DBGENCNTRL_RTU0_NIDEN0_MASK       (0x20000000U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN0_SHIFT      (29U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN0_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL_RTU0_NIDEN0(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL_RTU0_NIDEN0_SHIFT)) & MDM_AP_DBGENCNTRL_RTU0_NIDEN0_MASK)
/*! @} */

/*! @name DBGENCNTRL2 - Debug enable control 2 */
/*! @{ */

#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN3_MASK      (0x100U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN3_SHIFT     (8U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN3_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN3(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HIDEN3_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HIDEN3_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN3_MASK     (0x200U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN3_SHIFT    (9U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN3_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN3(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HNIDEN3_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HNIDEN3_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN3_MASK      (0x400U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN3_SHIFT     (10U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN3_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN3(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_DBGEN3_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_DBGEN3_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN3_MASK      (0x800U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN3_SHIFT     (11U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN3_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN3(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_NIDEN3_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_NIDEN3_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN2_MASK      (0x4000U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN2_SHIFT     (14U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN2_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN2(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HIDEN2_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HIDEN2_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN2_MASK     (0x8000U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN2_SHIFT    (15U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN2_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN2(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HNIDEN2_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HNIDEN2_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN2_MASK      (0x10000U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN2_SHIFT     (16U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN2_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN2(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_DBGEN2_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_DBGEN2_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN2_MASK      (0x20000U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN2_SHIFT     (17U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN2_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN2(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_NIDEN2_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_NIDEN2_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN1_MASK      (0x100000U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN1_SHIFT     (20U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN1_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN1(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HIDEN1_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HIDEN1_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN1_MASK     (0x200000U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN1_SHIFT    (21U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN1_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN1(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HNIDEN1_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HNIDEN1_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN1_MASK      (0x400000U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN1_SHIFT     (22U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN1_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN1(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_DBGEN1_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_DBGEN1_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN1_MASK      (0x800000U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN1_SHIFT     (23U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN1_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN1(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_NIDEN1_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_NIDEN1_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN0_MASK      (0x4000000U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN0_SHIFT     (26U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN0_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HIDEN0(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HIDEN0_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HIDEN0_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN0_MASK     (0x8000000U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN0_SHIFT    (27U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN0_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_HNIDEN0(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_HNIDEN0_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_HNIDEN0_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN0_MASK      (0x10000000U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN0_SHIFT     (28U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN0_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_DBGEN0(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_DBGEN0_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_DBGEN0_MASK)

#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN0_MASK      (0x20000000U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN0_SHIFT     (29U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN0_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL2_RTU1_NIDEN0(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL2_RTU1_NIDEN0_SHIFT)) & MDM_AP_DBGENCNTRL2_RTU1_NIDEN0_MASK)
/*! @} */

/*! @name DBGENCNTRL3 - Debug enable control 3 */
/*! @{ */

#define MDM_AP_DBGENCNTRL3_GDBGEN_MASK           (0x10U)
#define MDM_AP_DBGENCNTRL3_GDBGEN_SHIFT          (4U)
#define MDM_AP_DBGENCNTRL3_GDBGEN_WIDTH          (1U)
#define MDM_AP_DBGENCNTRL3_GDBGEN(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_GDBGEN_SHIFT)) & MDM_AP_DBGENCNTRL3_GDBGEN_MASK)

#define MDM_AP_DBGENCNTRL3_GNIDEN_MASK           (0x20U)
#define MDM_AP_DBGENCNTRL3_GNIDEN_SHIFT          (5U)
#define MDM_AP_DBGENCNTRL3_GNIDEN_WIDTH          (1U)
#define MDM_AP_DBGENCNTRL3_GNIDEN(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_GNIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_GNIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_GSPIDEN_MASK          (0x40U)
#define MDM_AP_DBGENCNTRL3_GSPIDEN_SHIFT         (6U)
#define MDM_AP_DBGENCNTRL3_GSPIDEN_WIDTH         (1U)
#define MDM_AP_DBGENCNTRL3_GSPIDEN(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_GSPIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_GSPIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_GSPNIDEN_MASK         (0x80U)
#define MDM_AP_DBGENCNTRL3_GSPNIDEN_SHIFT        (7U)
#define MDM_AP_DBGENCNTRL3_GSPNIDEN_WIDTH        (1U)
#define MDM_AP_DBGENCNTRL3_GSPNIDEN(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_GSPNIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_GSPNIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_DBGEN_MASK  (0x400U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_DBGEN_SHIFT (10U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_DBGEN_WIDTH (1U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CEVA_SPF2_DBGEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CEVA_SPF2_DBGEN_MASK)

#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_NIDEN_MASK  (0x800U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_NIDEN_SHIFT (11U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_NIDEN_WIDTH (1U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_NIDEN(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CEVA_SPF2_NIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CEVA_SPF2_NIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPIDEN_MASK (0x1000U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPIDEN_SHIFT (12U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPIDEN_WIDTH (1U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPIDEN(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPNIDEN_MASK (0x2000U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPNIDEN_SHIFT (13U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPNIDEN_WIDTH (1U)
#define MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPNIDEN(x)  (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPNIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CEVA_SPF2_SPNIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_GTM_DBGEN_MASK        (0x8000U)
#define MDM_AP_DBGENCNTRL3_GTM_DBGEN_SHIFT       (15U)
#define MDM_AP_DBGENCNTRL3_GTM_DBGEN_WIDTH       (1U)
#define MDM_AP_DBGENCNTRL3_GTM_DBGEN(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_GTM_DBGEN_SHIFT)) & MDM_AP_DBGENCNTRL3_GTM_DBGEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_A_DBGEN_MASK       (0x100000U)
#define MDM_AP_DBGENCNTRL3_CE_A_DBGEN_SHIFT      (20U)
#define MDM_AP_DBGENCNTRL3_CE_A_DBGEN_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL3_CE_A_DBGEN(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_A_DBGEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_A_DBGEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_A_NIDEN_MASK       (0x200000U)
#define MDM_AP_DBGENCNTRL3_CE_A_NIDEN_SHIFT      (21U)
#define MDM_AP_DBGENCNTRL3_CE_A_NIDEN_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL3_CE_A_NIDEN(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_A_NIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_A_NIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_A_SPIDEN_MASK      (0x400000U)
#define MDM_AP_DBGENCNTRL3_CE_A_SPIDEN_SHIFT     (22U)
#define MDM_AP_DBGENCNTRL3_CE_A_SPIDEN_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL3_CE_A_SPIDEN(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_A_SPIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_A_SPIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_A_SPNIDEN_MASK     (0x800000U)
#define MDM_AP_DBGENCNTRL3_CE_A_SPNIDEN_SHIFT    (23U)
#define MDM_AP_DBGENCNTRL3_CE_A_SPNIDEN_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL3_CE_A_SPNIDEN(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_A_SPNIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_A_SPNIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_B_DBGEN_MASK       (0x1000000U)
#define MDM_AP_DBGENCNTRL3_CE_B_DBGEN_SHIFT      (24U)
#define MDM_AP_DBGENCNTRL3_CE_B_DBGEN_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL3_CE_B_DBGEN(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_B_DBGEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_B_DBGEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_B_NIDEN_MASK       (0x2000000U)
#define MDM_AP_DBGENCNTRL3_CE_B_NIDEN_SHIFT      (25U)
#define MDM_AP_DBGENCNTRL3_CE_B_NIDEN_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL3_CE_B_NIDEN(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_B_NIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_B_NIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_B_SPIDEN_MASK      (0x4000000U)
#define MDM_AP_DBGENCNTRL3_CE_B_SPIDEN_SHIFT     (26U)
#define MDM_AP_DBGENCNTRL3_CE_B_SPIDEN_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL3_CE_B_SPIDEN(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_B_SPIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_B_SPIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_CE_B_SPNIDEN_MASK     (0x8000000U)
#define MDM_AP_DBGENCNTRL3_CE_B_SPNIDEN_SHIFT    (27U)
#define MDM_AP_DBGENCNTRL3_CE_B_SPNIDEN_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL3_CE_B_SPNIDEN(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_CE_B_SPNIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_CE_B_SPNIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_SYSM_DBGEN_MASK       (0x10000000U)
#define MDM_AP_DBGENCNTRL3_SYSM_DBGEN_SHIFT      (28U)
#define MDM_AP_DBGENCNTRL3_SYSM_DBGEN_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL3_SYSM_DBGEN(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_SYSM_DBGEN_SHIFT)) & MDM_AP_DBGENCNTRL3_SYSM_DBGEN_MASK)

#define MDM_AP_DBGENCNTRL3_SYSM_NIDEN_MASK       (0x20000000U)
#define MDM_AP_DBGENCNTRL3_SYSM_NIDEN_SHIFT      (29U)
#define MDM_AP_DBGENCNTRL3_SYSM_NIDEN_WIDTH      (1U)
#define MDM_AP_DBGENCNTRL3_SYSM_NIDEN(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_SYSM_NIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_SYSM_NIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_SYSM_SPIDEN_MASK      (0x40000000U)
#define MDM_AP_DBGENCNTRL3_SYSM_SPIDEN_SHIFT     (30U)
#define MDM_AP_DBGENCNTRL3_SYSM_SPIDEN_WIDTH     (1U)
#define MDM_AP_DBGENCNTRL3_SYSM_SPIDEN(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_SYSM_SPIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_SYSM_SPIDEN_MASK)

#define MDM_AP_DBGENCNTRL3_SYSM_SPNIDEN_MASK     (0x80000000U)
#define MDM_AP_DBGENCNTRL3_SYSM_SPNIDEN_SHIFT    (31U)
#define MDM_AP_DBGENCNTRL3_SYSM_SPNIDEN_WIDTH    (1U)
#define MDM_AP_DBGENCNTRL3_SYSM_SPNIDEN(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_DBGENCNTRL3_SYSM_SPNIDEN_SHIFT)) & MDM_AP_DBGENCNTRL3_SYSM_SPNIDEN_MASK)
/*! @} */

/*! @name DTS_ENABLE - DTS output enable register */
/*! @{ */

#define MDM_AP_DTS_ENABLE_DTS_EN_MASK            (0x1U)
#define MDM_AP_DTS_ENABLE_DTS_EN_SHIFT           (0U)
#define MDM_AP_DTS_ENABLE_DTS_EN_WIDTH           (1U)
#define MDM_AP_DTS_ENABLE_DTS_EN(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_ENABLE_DTS_EN_SHIFT)) & MDM_AP_DTS_ENABLE_DTS_EN_MASK)

#define MDM_AP_DTS_ENABLE_DTS_EN_B_MASK          (0x2U)
#define MDM_AP_DTS_ENABLE_DTS_EN_B_SHIFT         (1U)
#define MDM_AP_DTS_ENABLE_DTS_EN_B_WIDTH         (1U)
#define MDM_AP_DTS_ENABLE_DTS_EN_B(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_ENABLE_DTS_EN_B_SHIFT)) & MDM_AP_DTS_ENABLE_DTS_EN_B_MASK)

#define MDM_AP_DTS_ENABLE_DTS_EN_C_MASK          (0x4U)
#define MDM_AP_DTS_ENABLE_DTS_EN_C_SHIFT         (2U)
#define MDM_AP_DTS_ENABLE_DTS_EN_C_WIDTH         (1U)
#define MDM_AP_DTS_ENABLE_DTS_EN_C(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_ENABLE_DTS_EN_C_SHIFT)) & MDM_AP_DTS_ENABLE_DTS_EN_C_MASK)

#define MDM_AP_DTS_ENABLE_DTS_EN_D_MASK          (0x8U)
#define MDM_AP_DTS_ENABLE_DTS_EN_D_SHIFT         (3U)
#define MDM_AP_DTS_ENABLE_DTS_EN_D_WIDTH         (1U)
#define MDM_AP_DTS_ENABLE_DTS_EN_D(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_ENABLE_DTS_EN_D_SHIFT)) & MDM_AP_DTS_ENABLE_DTS_EN_D_MASK)
/*! @} */

/*! @name DTS_STARTUP - DTS startup register */
/*! @{ */

#define MDM_AP_DTS_STARTUP_AD_MASK               (0xFFFFFFFFU)
#define MDM_AP_DTS_STARTUP_AD_SHIFT              (0U)
#define MDM_AP_DTS_STARTUP_AD_WIDTH              (32U)
#define MDM_AP_DTS_STARTUP_AD(x)                 (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_STARTUP_AD_SHIFT)) & MDM_AP_DTS_STARTUP_AD_MASK)
/*! @} */

/*! @name DTS_STARTUP_B - DTS startup register B */
/*! @{ */

#define MDM_AP_DTS_STARTUP_B_AD_MASK             (0xFFFFFFFFU)
#define MDM_AP_DTS_STARTUP_B_AD_SHIFT            (0U)
#define MDM_AP_DTS_STARTUP_B_AD_WIDTH            (32U)
#define MDM_AP_DTS_STARTUP_B_AD(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_STARTUP_B_AD_SHIFT)) & MDM_AP_DTS_STARTUP_B_AD_MASK)
/*! @} */

/*! @name DTS_STARTUP_C - DTS startup register C */
/*! @{ */

#define MDM_AP_DTS_STARTUP_C_AD_MASK             (0xFFFFFFFFU)
#define MDM_AP_DTS_STARTUP_C_AD_SHIFT            (0U)
#define MDM_AP_DTS_STARTUP_C_AD_WIDTH            (32U)
#define MDM_AP_DTS_STARTUP_C_AD(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_STARTUP_C_AD_SHIFT)) & MDM_AP_DTS_STARTUP_C_AD_MASK)
/*! @} */

/*! @name DTS_STARTUP_D - DTS startup register D */
/*! @{ */

#define MDM_AP_DTS_STARTUP_D_AD_MASK             (0xFFFFFFFFU)
#define MDM_AP_DTS_STARTUP_D_AD_SHIFT            (0U)
#define MDM_AP_DTS_STARTUP_D_AD_WIDTH            (32U)
#define MDM_AP_DTS_STARTUP_D_AD(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_STARTUP_D_AD_SHIFT)) & MDM_AP_DTS_STARTUP_D_AD_MASK)
/*! @} */

/*! @name DTS_SEMAPHORE - DTS SEMAPHORE register */
/*! @{ */

#define MDM_AP_DTS_SEMAPHORE_ST_MASK             (0xFFFFFFFFU)
#define MDM_AP_DTS_SEMAPHORE_ST_SHIFT            (0U)
#define MDM_AP_DTS_SEMAPHORE_ST_WIDTH            (32U)
#define MDM_AP_DTS_SEMAPHORE_ST(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_SEMAPHORE_ST_SHIFT)) & MDM_AP_DTS_SEMAPHORE_ST_MASK)
/*! @} */

/*! @name DTS_SEMAPHORE_B - DTS SEMAPHORE_B register */
/*! @{ */

#define MDM_AP_DTS_SEMAPHORE_B_ST_B_MASK         (0xFFFFFFFFU)
#define MDM_AP_DTS_SEMAPHORE_B_ST_B_SHIFT        (0U)
#define MDM_AP_DTS_SEMAPHORE_B_ST_B_WIDTH        (32U)
#define MDM_AP_DTS_SEMAPHORE_B_ST_B(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_SEMAPHORE_B_ST_B_SHIFT)) & MDM_AP_DTS_SEMAPHORE_B_ST_B_MASK)
/*! @} */

/*! @name DTS_SEMAPHORE_C - DTS SEMAPHORE_C register */
/*! @{ */

#define MDM_AP_DTS_SEMAPHORE_C_ST_C_MASK         (0xFFFFFFFFU)
#define MDM_AP_DTS_SEMAPHORE_C_ST_C_SHIFT        (0U)
#define MDM_AP_DTS_SEMAPHORE_C_ST_C_WIDTH        (32U)
#define MDM_AP_DTS_SEMAPHORE_C_ST_C(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_SEMAPHORE_C_ST_C_SHIFT)) & MDM_AP_DTS_SEMAPHORE_C_ST_C_MASK)
/*! @} */

/*! @name DTS_SEMAPHORE_D - DTS SEMAPHORE_D register */
/*! @{ */

#define MDM_AP_DTS_SEMAPHORE_D_ST_D_MASK         (0xFFFFFFFFU)
#define MDM_AP_DTS_SEMAPHORE_D_ST_D_SHIFT        (0U)
#define MDM_AP_DTS_SEMAPHORE_D_ST_D_WIDTH        (32U)
#define MDM_AP_DTS_SEMAPHORE_D_ST_D(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_DTS_SEMAPHORE_D_ST_D_SHIFT)) & MDM_AP_DTS_SEMAPHORE_D_ST_D_MASK)
/*! @} */

/*! @name IDR - Identification Register */
/*! @{ */

#define MDM_AP_IDR_Type_MASK                     (0xFU)
#define MDM_AP_IDR_Type_SHIFT                    (0U)
#define MDM_AP_IDR_Type_WIDTH                    (4U)
#define MDM_AP_IDR_Type(x)                       (((uint32_t)(((uint32_t)(x)) << MDM_AP_IDR_Type_SHIFT)) & MDM_AP_IDR_Type_MASK)

#define MDM_AP_IDR_Variant_MASK                  (0xF0U)
#define MDM_AP_IDR_Variant_SHIFT                 (4U)
#define MDM_AP_IDR_Variant_WIDTH                 (4U)
#define MDM_AP_IDR_Variant(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_IDR_Variant_SHIFT)) & MDM_AP_IDR_Variant_MASK)

#define MDM_AP_IDR_Class_MASK                    (0x1E000U)
#define MDM_AP_IDR_Class_SHIFT                   (13U)
#define MDM_AP_IDR_Class_WIDTH                   (4U)
#define MDM_AP_IDR_Class(x)                      (((uint32_t)(((uint32_t)(x)) << MDM_AP_IDR_Class_SHIFT)) & MDM_AP_IDR_Class_MASK)

#define MDM_AP_IDR_JEDEC_code_MASK               (0xFE0000U)
#define MDM_AP_IDR_JEDEC_code_SHIFT              (17U)
#define MDM_AP_IDR_JEDEC_code_WIDTH              (7U)
#define MDM_AP_IDR_JEDEC_code(x)                 (((uint32_t)(((uint32_t)(x)) << MDM_AP_IDR_JEDEC_code_SHIFT)) & MDM_AP_IDR_JEDEC_code_MASK)

#define MDM_AP_IDR_JEDEC_bank_MASK               (0xF000000U)
#define MDM_AP_IDR_JEDEC_bank_SHIFT              (24U)
#define MDM_AP_IDR_JEDEC_bank_WIDTH              (4U)
#define MDM_AP_IDR_JEDEC_bank(x)                 (((uint32_t)(((uint32_t)(x)) << MDM_AP_IDR_JEDEC_bank_SHIFT)) & MDM_AP_IDR_JEDEC_bank_MASK)

#define MDM_AP_IDR_REVISION_MASK                 (0xF0000000U)
#define MDM_AP_IDR_REVISION_SHIFT                (28U)
#define MDM_AP_IDR_REVISION_WIDTH                (4U)
#define MDM_AP_IDR_REVISION(x)                   (((uint32_t)(((uint32_t)(x)) << MDM_AP_IDR_REVISION_SHIFT)) & MDM_AP_IDR_REVISION_MASK)
/*! @} */

/*! @name DEVARCH - CoreSight Device Architecture Register */
/*! @{ */

#define MDM_AP_DEVARCH_ARCHID_MASK               (0xFFFFU)
#define MDM_AP_DEVARCH_ARCHID_SHIFT              (0U)
#define MDM_AP_DEVARCH_ARCHID_WIDTH              (16U)
#define MDM_AP_DEVARCH_ARCHID(x)                 (((uint32_t)(((uint32_t)(x)) << MDM_AP_DEVARCH_ARCHID_SHIFT)) & MDM_AP_DEVARCH_ARCHID_MASK)

#define MDM_AP_DEVARCH_REVISION_MASK             (0xF0000U)
#define MDM_AP_DEVARCH_REVISION_SHIFT            (16U)
#define MDM_AP_DEVARCH_REVISION_WIDTH            (4U)
#define MDM_AP_DEVARCH_REVISION(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_DEVARCH_REVISION_SHIFT)) & MDM_AP_DEVARCH_REVISION_MASK)

#define MDM_AP_DEVARCH_PRESENT_MASK              (0x100000U)
#define MDM_AP_DEVARCH_PRESENT_SHIFT             (20U)
#define MDM_AP_DEVARCH_PRESENT_WIDTH             (1U)
#define MDM_AP_DEVARCH_PRESENT(x)                (((uint32_t)(((uint32_t)(x)) << MDM_AP_DEVARCH_PRESENT_SHIFT)) & MDM_AP_DEVARCH_PRESENT_MASK)

#define MDM_AP_DEVARCH_ARCHITECT_MASK            (0xFFE00000U)
#define MDM_AP_DEVARCH_ARCHITECT_SHIFT           (21U)
#define MDM_AP_DEVARCH_ARCHITECT_WIDTH           (11U)
#define MDM_AP_DEVARCH_ARCHITECT(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_DEVARCH_ARCHITECT_SHIFT)) & MDM_AP_DEVARCH_ARCHITECT_MASK)
/*! @} */

/*! @name DEVTYPE - CoreSight Device Type Identifier Register */
/*! @{ */

#define MDM_AP_DEVTYPE_MAJOR_MASK                (0xFU)
#define MDM_AP_DEVTYPE_MAJOR_SHIFT               (0U)
#define MDM_AP_DEVTYPE_MAJOR_WIDTH               (4U)
#define MDM_AP_DEVTYPE_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << MDM_AP_DEVTYPE_MAJOR_SHIFT)) & MDM_AP_DEVTYPE_MAJOR_MASK)

#define MDM_AP_DEVTYPE_SUB_MASK                  (0xF0U)
#define MDM_AP_DEVTYPE_SUB_SHIFT                 (4U)
#define MDM_AP_DEVTYPE_SUB_WIDTH                 (4U)
#define MDM_AP_DEVTYPE_SUB(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_DEVTYPE_SUB_SHIFT)) & MDM_AP_DEVTYPE_SUB_MASK)
/*! @} */

/*! @name PIDR4 - CoreSight Peripheral Identification Register 4 */
/*! @{ */

#define MDM_AP_PIDR4_DES_2_MASK                  (0xFU)
#define MDM_AP_PIDR4_DES_2_SHIFT                 (0U)
#define MDM_AP_PIDR4_DES_2_WIDTH                 (4U)
#define MDM_AP_PIDR4_DES_2(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR4_DES_2_SHIFT)) & MDM_AP_PIDR4_DES_2_MASK)

#define MDM_AP_PIDR4_SIZE_MASK                   (0xF0U)
#define MDM_AP_PIDR4_SIZE_SHIFT                  (4U)
#define MDM_AP_PIDR4_SIZE_WIDTH                  (4U)
#define MDM_AP_PIDR4_SIZE(x)                     (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR4_SIZE_SHIFT)) & MDM_AP_PIDR4_SIZE_MASK)
/*! @} */

/*! @name PIDR0 - CoreSight Peripheral Identification Register 0 */
/*! @{ */

#define MDM_AP_PIDR0_PART_0_MASK                 (0xFFU)
#define MDM_AP_PIDR0_PART_0_SHIFT                (0U)
#define MDM_AP_PIDR0_PART_0_WIDTH                (8U)
#define MDM_AP_PIDR0_PART_0(x)                   (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR0_PART_0_SHIFT)) & MDM_AP_PIDR0_PART_0_MASK)
/*! @} */

/*! @name PIDR1 - CoreSight Peripheral Identification Register 1 */
/*! @{ */

#define MDM_AP_PIDR1_PART_1_MASK                 (0xFU)
#define MDM_AP_PIDR1_PART_1_SHIFT                (0U)
#define MDM_AP_PIDR1_PART_1_WIDTH                (4U)
#define MDM_AP_PIDR1_PART_1(x)                   (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR1_PART_1_SHIFT)) & MDM_AP_PIDR1_PART_1_MASK)

#define MDM_AP_PIDR1_DES_0_MASK                  (0xF0U)
#define MDM_AP_PIDR1_DES_0_SHIFT                 (4U)
#define MDM_AP_PIDR1_DES_0_WIDTH                 (4U)
#define MDM_AP_PIDR1_DES_0(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR1_DES_0_SHIFT)) & MDM_AP_PIDR1_DES_0_MASK)
/*! @} */

/*! @name PIDR2 - CoreSight Peripheral Identification Register 2 */
/*! @{ */

#define MDM_AP_PIDR2_DES_1_MASK                  (0x7U)
#define MDM_AP_PIDR2_DES_1_SHIFT                 (0U)
#define MDM_AP_PIDR2_DES_1_WIDTH                 (3U)
#define MDM_AP_PIDR2_DES_1(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR2_DES_1_SHIFT)) & MDM_AP_PIDR2_DES_1_MASK)

#define MDM_AP_PIDR2_JEDEC_MASK                  (0x8U)
#define MDM_AP_PIDR2_JEDEC_SHIFT                 (3U)
#define MDM_AP_PIDR2_JEDEC_WIDTH                 (1U)
#define MDM_AP_PIDR2_JEDEC(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR2_JEDEC_SHIFT)) & MDM_AP_PIDR2_JEDEC_MASK)

#define MDM_AP_PIDR2_REVISION_MASK               (0xF0U)
#define MDM_AP_PIDR2_REVISION_SHIFT              (4U)
#define MDM_AP_PIDR2_REVISION_WIDTH              (4U)
#define MDM_AP_PIDR2_REVISION(x)                 (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR2_REVISION_SHIFT)) & MDM_AP_PIDR2_REVISION_MASK)
/*! @} */

/*! @name PIDR3 - CoreSight Peripheral Identification Register 3 */
/*! @{ */

#define MDM_AP_PIDR3_CMOD_MASK                   (0xFU)
#define MDM_AP_PIDR3_CMOD_SHIFT                  (0U)
#define MDM_AP_PIDR3_CMOD_WIDTH                  (4U)
#define MDM_AP_PIDR3_CMOD(x)                     (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR3_CMOD_SHIFT)) & MDM_AP_PIDR3_CMOD_MASK)

#define MDM_AP_PIDR3_REVAND_MASK                 (0xF0U)
#define MDM_AP_PIDR3_REVAND_SHIFT                (4U)
#define MDM_AP_PIDR3_REVAND_WIDTH                (4U)
#define MDM_AP_PIDR3_REVAND(x)                   (((uint32_t)(((uint32_t)(x)) << MDM_AP_PIDR3_REVAND_SHIFT)) & MDM_AP_PIDR3_REVAND_MASK)
/*! @} */

/*! @name CIDR0 - CoreSight Component Identification Register 0 */
/*! @{ */

#define MDM_AP_CIDR0_PRMBL_0_MASK                (0xFFU)
#define MDM_AP_CIDR0_PRMBL_0_SHIFT               (0U)
#define MDM_AP_CIDR0_PRMBL_0_WIDTH               (8U)
#define MDM_AP_CIDR0_PRMBL_0(x)                  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CIDR0_PRMBL_0_SHIFT)) & MDM_AP_CIDR0_PRMBL_0_MASK)
/*! @} */

/*! @name CIDR1 - CoreSight Component Identification Register 1 */
/*! @{ */

#define MDM_AP_CIDR1_PRMBL_1_MASK                (0xFU)
#define MDM_AP_CIDR1_PRMBL_1_SHIFT               (0U)
#define MDM_AP_CIDR1_PRMBL_1_WIDTH               (4U)
#define MDM_AP_CIDR1_PRMBL_1(x)                  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CIDR1_PRMBL_1_SHIFT)) & MDM_AP_CIDR1_PRMBL_1_MASK)

#define MDM_AP_CIDR1_CLASS_MASK                  (0xF0U)
#define MDM_AP_CIDR1_CLASS_SHIFT                 (4U)
#define MDM_AP_CIDR1_CLASS_WIDTH                 (4U)
#define MDM_AP_CIDR1_CLASS(x)                    (((uint32_t)(((uint32_t)(x)) << MDM_AP_CIDR1_CLASS_SHIFT)) & MDM_AP_CIDR1_CLASS_MASK)
/*! @} */

/*! @name CIDR2 - CoreSight Component Identification Register 2 */
/*! @{ */

#define MDM_AP_CIDR2_PRMBL_2_MASK                (0xFFU)
#define MDM_AP_CIDR2_PRMBL_2_SHIFT               (0U)
#define MDM_AP_CIDR2_PRMBL_2_WIDTH               (8U)
#define MDM_AP_CIDR2_PRMBL_2(x)                  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CIDR2_PRMBL_2_SHIFT)) & MDM_AP_CIDR2_PRMBL_2_MASK)
/*! @} */

/*! @name CIDR3 - CoreSight Component Identification Register 3 */
/*! @{ */

#define MDM_AP_CIDR3_PRMBL_3_MASK                (0xFFU)
#define MDM_AP_CIDR3_PRMBL_3_SHIFT               (0U)
#define MDM_AP_CIDR3_PRMBL_3_WIDTH               (8U)
#define MDM_AP_CIDR3_PRMBL_3(x)                  (((uint32_t)(((uint32_t)(x)) << MDM_AP_CIDR3_PRMBL_3_SHIFT)) & MDM_AP_CIDR3_PRMBL_3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MDM_AP_Register_Masks */

/*!
 * @}
 */ /* end of group MDM_AP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_MDM_AP_H_) */
