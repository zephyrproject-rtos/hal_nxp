/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SRC_GENERAL_REG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file SRC_GENERAL_REG.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for SRC_GENERAL_REG
 *
 * CMSIS Peripheral Access Layer for SRC_GENERAL_REG
 */

#if !defined(SRC_GENERAL_REG_H_)
#define SRC_GENERAL_REG_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SRC_GENERAL_REG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GENERAL_REG_Peripheral_Access_Layer SRC_GENERAL_REG Peripheral Access Layer
 * @{
 */

/** SRC_GENERAL_REG - Size of Registers Arrays */
#define SRC_GENERAL_REG_SRMR_ARRAY_COUNT          14u

/** SRC_GENERAL_REG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[12];
  __IO uint32_t SRTMR;                             /**< SRC Reset Trigger Mode Register, offset: 0x14 */
  __IO uint32_t SRMASK;                            /**< SRC Reset Trigger Mode Mask Register, offset: 0x18 */
       uint8_t RESERVED_2[36];
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x40 */
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x44 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SMRSR;                             /**< SRC Mix Slices Reset Status Register, offset: 0x4C */
  __IO uint32_t SRESR;                             /**< SRC Reset Event Status Register, offset: 0x50 */
  __IO uint32_t GPR1;                              /**< SRC General Purpose Register 1, offset: 0x54 */
  __IO uint32_t GPR2;                              /**< SRC General Purpose Register 2, offset: 0x58 */
  __IO uint32_t GPR3;                              /**< SRC General Purpose Register 3, offset: 0x5C */
  __IO uint32_t GPR4;                              /**< SRC General Purpose Register 4, offset: 0x60 */
  __IO uint32_t GPR5;                              /**< SRC General Purpose Register 5, offset: 0x64 */
  __IO uint32_t GPR6;                              /**< SRC General Purpose Register 6, offset: 0x68 */
  __IO uint32_t GPR7;                              /**< SRC General Purpose Register 7, offset: 0x6C */
  __IO uint32_t GPR8;                              /**< SRC General Purpose Register 8, offset: 0x70 */
  __IO uint32_t GPR9;                              /**< SRC General Purpose Register 9, offset: 0x74 */
  __IO uint32_t GPR10;                             /**< SRC General Purpose Register 10, offset: 0x78 */
  __IO uint32_t GPR11;                             /**< SRC General Purpose Register 11, offset: 0x7C */
  __IO uint32_t GPR12;                             /**< SRC General Purpose Register 12, offset: 0x80 */
  __IO uint32_t GPR13;                             /**< SRC General Purpose Register 13, offset: 0x84 */
  __IO uint32_t GPR14;                             /**< SRC General Purpose Register 14, offset: 0x88 */
  __IO uint32_t GPR15;                             /**< SRC General Purpose Register 16, offset: 0x8C */
  __IO uint32_t GPR16;                             /**< SRC General Purpose Register 16, offset: 0x90 */
  __IO uint32_t GPR17;                             /**< SRC General Purpose Register 17, offset: 0x94 */
  __IO uint32_t GPR18;                             /**< SRC General Purpose Register 18, offset: 0x98 */
  __IO uint32_t GPR19;                             /**< SRC General Purpose Register 19, offset: 0x9C */
       uint8_t RESERVED_4[96];
  __IO uint32_t GPR20;                             /**< SRC General Purpose Register 20, offset: 0x100 */
  __IO uint32_t CM_QUIESCE;                        /**< SRC_CORTEX_M_QUIESCE, offset: 0x104 */
  __IO uint32_t COLD_RESET_SSAR_ACK_CTRL;          /**< Cold reset SSAR acknowledge control, offset: 0x108 */
       uint8_t RESERVED_5[4];
  __IO uint32_t ROM_LP_CTRL;                       /**< ROM Low Power Control, offset: 0x110 */
  __I  uint32_t A55_DENY_STAT;                     /**< A55 Q_Channel Deny Status, offset: 0x114 */
  __IO uint32_t EVENT_RESET_SYSMAN_ACK_CTRL;       /**< Event Reset SYSMAN acknowledge control, offset: 0x118 */
       uint8_t RESERVED_6[4];
  __IO uint32_t SRMR[SRC_GENERAL_REG_SRMR_ARRAY_COUNT]; /**< SRC Reset Mode Register (SRMR), array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_7[104];
  __IO uint32_t SRDR;                              /**< SRC Reset Disable Register, offset: 0x1C0 */
} SRC_GENERAL_REG_Type;

/* ----------------------------------------------------------------------------
   -- SRC_GENERAL_REG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GENERAL_REG_Register_Masks SRC_GENERAL_REG Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - Authentication Control */
/*! @{ */

#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..General registers are not locked.
 *  0b1..LOCK_CFG and registers in the list are locked.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_CFG_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_MASK (0x100U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_SHIFT (8U)
/*! TZ_USER - Allow user mode access
 *  0b0..General registers can only be written in privilege mode.
 *  0b1..General registers can be written either in privilege mode or user mode.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_TZ_USER_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_MASK   (0x200U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..General registers can only be written in secure mode.
 *  0b1..General registers can be written either in secure mode or non-secure mode.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_TZ_NS_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_MASK (0x800U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TZ_NS and TZ_USER bits
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER value cannot be changed.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_TZ_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST value cannot be changed.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_LOCK_LIST_MASK)

#define SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write General registers.
 *  0b0000000000000010..Core with domain ID=1 can write General registers.
 *  0b0000000000000100..Core with domain ID=2 can write General registers.
 *  0b0000000000001000..Core with domain ID=3 can write General registers.
 *  0b0000000000010000..Core with domain ID=4 can write General registers.
 *  0b0000000000100000..Core with domain ID=5 can write General registers.
 *  0b0000000001000000..Core with domain ID=6 can write General registers.
 *  0b0000000010000000..Core with domain ID=7 can write General registers.
 *  0b0000000100000000..Core with domain ID=8 can write General registers.
 *  0b0000001000000000..Core with domain ID=9 can write General registers.
 *  0b0000010000000000..Core with domain ID=10 can write General registers.
 *  0b0000100000000000..Core with domain ID=11 can write General registers.
 *  0b0001000000000000..Core with domain ID=12 can write General registers.
 *  0b0010000000000000..Core with domain ID=13 can write General registers.
 *  0b0100000000000000..Core with domain ID=14 can write General registers.
 *  0b1000000000000000..Core with domain ID=16 can write General registers.
 */
#define SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & SRC_GENERAL_REG_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name SRTMR - SRC Reset Trigger Mode Register */
/*! @{ */

#define SRC_GENERAL_REG_SRTMR_RST_EVT_0_MODE_MASK (0x1U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_0_MODE_SHIFT (0U)
/*! RST_EVT_0_MODE - mode configuration bit for reset event CM33_LOCKUP_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM33_LOCKUP_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM33_LOCKUP_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_0_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_0_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_0_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_1_MODE_MASK (0x2U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_1_MODE_SHIFT (1U)
/*! RST_EVT_1_MODE - mode configuration bit for reset event CM33_SYS_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM33_SYS_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM33_SYS_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_1_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_1_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_1_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_2_MODE_MASK (0x4U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_2_MODE_SHIFT (2U)
/*! RST_EVT_2_MODE - mode configuration bit for reset event CM7_LOCKUP_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM7_LOCKUP_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM7_LOCKUP_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_2_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_2_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_2_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_3_MODE_MASK (0x8U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_3_MODE_SHIFT (3U)
/*! RST_EVT_3_MODE - mode configuration bit for reset event CM7_SYS_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM7_SYS_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM7_SYS_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_3_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_3_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_3_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_4_MODE_MASK (0x10U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_4_MODE_SHIFT (4U)
/*! RST_EVT_4_MODE - mode configuration bit for reset event FCCU_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as FCCU_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when FCCU_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_4_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_4_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_4_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_5_MODE_MASK (0x20U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_5_MODE_SHIFT (5U)
/*! RST_EVT_5_MODE - mode configuration bit for reset event JTAG_SW_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as JTAG_SW_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when JTAG_SW_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_5_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_5_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_5_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_6_MODE_MASK (0x40U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_6_MODE_SHIFT (6U)
/*! RST_EVT_6_MODE - mode configuration bit for reset event ELE_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as ELE_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when ELE_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_6_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_6_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_6_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_7_MODE_MASK (0x80U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_7_MODE_SHIFT (7U)
/*! RST_EVT_7_MODE - mode configuration bit for reset event TEMPSENSE_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as TEMPSENSE_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when TEMPSENSE_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_7_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_7_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_7_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_8_MODE_MASK (0x100U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_8_MODE_SHIFT (8U)
/*! RST_EVT_8_MODE - mode configuration bit for reset event WDOG1_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG1_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG1_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_8_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_8_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_8_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_9_MODE_MASK (0x200U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_9_MODE_SHIFT (9U)
/*! RST_EVT_9_MODE - mode configuration bit for reset event WDOG2_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG2_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG2_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_9_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_9_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_9_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_10_MODE_MASK (0x400U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_10_MODE_SHIFT (10U)
/*! RST_EVT_10_MODE - mode configuration bit for reset event WDOG3_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG3_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG3_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_10_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_10_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_10_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_11_MODE_MASK (0x800U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_11_MODE_SHIFT (11U)
/*! RST_EVT_11_MODE - mode configuration bit for reset event WDOG4_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG4_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG4_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_11_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_11_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_11_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_12_MODE_MASK (0x1000U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_12_MODE_SHIFT (12U)
/*! RST_EVT_12_MODE - mode configuration bit for reset event WDOG5_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG5_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG5_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_12_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_12_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_12_MODE_MASK)

#define SRC_GENERAL_REG_SRTMR_RST_EVT_13_MODE_MASK (0x2000U)
#define SRC_GENERAL_REG_SRTMR_RST_EVT_13_MODE_SHIFT (13U)
/*! RST_EVT_13_MODE - mode configuration bit for reset event JTAG_RST_B_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as JTAG_RST_B_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when JTAG_RST_B_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GENERAL_REG_SRTMR_RST_EVT_13_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRTMR_RST_EVT_13_MODE_SHIFT)) & SRC_GENERAL_REG_SRTMR_RST_EVT_13_MODE_MASK)
/*! @} */

/*! @name SRMASK - SRC Reset Trigger Mode Mask Register */
/*! @{ */

#define SRC_GENERAL_REG_SRMASK_RST_EVT_0_MASK_MASK (0x1U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_0_MASK_SHIFT (0U)
/*! RST_EVT_0_MASK - mask bit for reset event CM33_LOCKUP_RST_EVT
 *  0b0..reset event CM33_LOCKUP_RST_EVT is not masked
 *  0b1..reset event CM33_LOCKUP_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_0_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_0_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_1_MASK_MASK (0x2U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_1_MASK_SHIFT (1U)
/*! RST_EVT_1_MASK - mask bit for reset event CM33_SYS_RST_EVT
 *  0b0..reset event CM33_SYS_RST_EVT is not masked
 *  0b1..reset event CM33_SYS_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_1_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_1_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_2_MASK_MASK (0x4U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_2_MASK_SHIFT (2U)
/*! RST_EVT_2_MASK - mask bit for reset event CM7_LOCKUP_RST_EVT
 *  0b0..reset event CM7_LOCKUP_RST_EVT is not masked
 *  0b1..reset event CM7_LOCKUP_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_2_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_2_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_3_MASK_MASK (0x8U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_3_MASK_SHIFT (3U)
/*! RST_EVT_3_MASK - mask bit for reset event CM7_SYS_RST_EVT
 *  0b0..reset event CM7_SYS_RST_EVT is not masked
 *  0b1..reset event CM7_SYS_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_3_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_3_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_4_MASK_MASK (0x10U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_4_MASK_SHIFT (4U)
/*! RST_EVT_4_MASK - mask bit for reset event FCCU_RST_EVT
 *  0b0..reset event FCCU_RST_EVT is not masked
 *  0b1..reset event FCCU_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_4_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_4_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_5_MASK_MASK (0x20U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_5_MASK_SHIFT (5U)
/*! RST_EVT_5_MASK - mask bit for reset event JTAG_SW_RST_EVT
 *  0b0..reset event JTAG_SW_RST_EVT is not masked
 *  0b1..reset event JTAG_SW_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_5_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_5_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_6_MASK_MASK (0x40U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_6_MASK_SHIFT (6U)
/*! RST_EVT_6_MASK - mask bit for reset event ELE_RST_EVT
 *  0b0..reset event ELE_RST_EVT is not masked
 *  0b1..reset event ELE_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_6_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_6_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_7_MASK_MASK (0x80U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_7_MASK_SHIFT (7U)
/*! RST_EVT_7_MASK - mask bit for reset event TEMPSENSE_RST_EVT
 *  0b0..reset event TEMPSENSE_RST_EVT is not masked
 *  0b1..reset event TEMPSENSE_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_7_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_7_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_8_MASK_MASK (0x100U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_8_MASK_SHIFT (8U)
/*! RST_EVT_8_MASK - mask bit for reset event WDOG1_RST_EVT
 *  0b0..reset event WDOG1_RST_EVT is not masked
 *  0b1..reset event WDOG1_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_8_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_8_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_8_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_9_MASK_MASK (0x200U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_9_MASK_SHIFT (9U)
/*! RST_EVT_9_MASK - mask bit for reset event WDOG2_RST_EVT
 *  0b0..reset event WDOG2_RST_EVT is not masked
 *  0b1..reset event WDOG2_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_9_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_9_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_9_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_10_MASK_MASK (0x400U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_10_MASK_SHIFT (10U)
/*! RST_EVT_10_MASK - mask bit for reset event WDOG3_RST_EVT
 *  0b0..reset event WDOG3_RST_EVT is not masked
 *  0b1..reset event WDOG3_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_10_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_10_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_10_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_11_MASK_MASK (0x800U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_11_MASK_SHIFT (11U)
/*! RST_EVT_11_MASK - mask bit for reset event WDOG4_RST_EVT
 *  0b0..reset event WDOG4_RST_EVT is not masked
 *  0b1..reset event WDOG4_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_11_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_11_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_11_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_12_MASK_MASK (0x1000U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_12_MASK_SHIFT (12U)
/*! RST_EVT_12_MASK - mask bit for reset event WDOG5_RST_EVT
 *  0b0..reset event WDOG5_RST_EVT is not masked
 *  0b1..reset event WDOG5_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_12_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_12_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_12_MASK_MASK)

#define SRC_GENERAL_REG_SRMASK_RST_EVT_13_MASK_MASK (0x2000U)
#define SRC_GENERAL_REG_SRMASK_RST_EVT_13_MASK_SHIFT (13U)
/*! RST_EVT_13_MASK - mask bit for reset event JTAG_RST_B_RST_EVT
 *  0b0..reset event JTAG_RST_B_RST_EVT is not masked
 *  0b1..reset event JTAG_RST_B_RST_EVT is masked
 */
#define SRC_GENERAL_REG_SRMASK_RST_EVT_13_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMASK_RST_EVT_13_MASK_SHIFT)) & SRC_GENERAL_REG_SRMASK_RST_EVT_13_MASK_MASK)
/*! @} */

/*! @name SBMR1 - SRC Boot Mode Register 1 */
/*! @{ */

#define SRC_GENERAL_REG_SBMR1_BOOT_CFG0_MASK     (0xFFFFFFFFU)
#define SRC_GENERAL_REG_SBMR1_BOOT_CFG0_SHIFT    (0U)
/*! BOOT_CFG0 - This bit field stores the BOOT_CFG8 fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GENERAL_REG_SBMR1_BOOT_CFG0(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR1_BOOT_CFG0_SHIFT)) & SRC_GENERAL_REG_SBMR1_BOOT_CFG0_MASK)
/*! @} */

/*! @name SBMR2 - SRC Boot Mode Register 2 */
/*! @{ */

#define SRC_GENERAL_REG_SBMR2_BOOT_CFG1_MASK     (0xFFFFU)
#define SRC_GENERAL_REG_SBMR2_BOOT_CFG1_SHIFT    (0U)
/*! BOOT_CFG1 - This bit field stores the BOOT_CFG0[16:0] fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GENERAL_REG_SBMR2_BOOT_CFG1(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_BOOT_CFG1_SHIFT)) & SRC_GENERAL_REG_SBMR2_BOOT_CFG1_MASK)

#define SRC_GENERAL_REG_SBMR2_SDP_DIS_MASK       (0x10000U)
#define SRC_GENERAL_REG_SBMR2_SDP_DIS_SHIFT      (16U)
/*! SDP_DIS - Stores the value of SDP_DIS from fusemap. Please see the fusemap for fuse details. */
#define SRC_GENERAL_REG_SBMR2_SDP_DIS(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_SDP_DIS_SHIFT)) & SRC_GENERAL_REG_SBMR2_SDP_DIS_MASK)

#define SRC_GENERAL_REG_SBMR2_BOOT_CFG2_MASK     (0x3C0000U)
#define SRC_GENERAL_REG_SBMR2_BOOT_CFG2_SHIFT    (18U)
/*! BOOT_CFG2 - This bit field stores the BOOT_CFG0[31:28] fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GENERAL_REG_SBMR2_BOOT_CFG2(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_BOOT_CFG2_SHIFT)) & SRC_GENERAL_REG_SBMR2_BOOT_CFG2_MASK)

#define SRC_GENERAL_REG_SBMR2_CCMSRCGPCMIX_BLK_CTRL_MASK (0xC00000U)
#define SRC_GENERAL_REG_SBMR2_CCMSRCGPCMIX_BLK_CTRL_SHIFT (22U)
/*! CCMSRCGPCMIX_BLK_CTRL - Stores the value of CCMSRCGPCMIX_BLK_CTRL[1:0] from fusemap. Please see the fusemap for fuse details. */
#define SRC_GENERAL_REG_SBMR2_CCMSRCGPCMIX_BLK_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_CCMSRCGPCMIX_BLK_CTRL_SHIFT)) & SRC_GENERAL_REG_SBMR2_CCMSRCGPCMIX_BLK_CTRL_MASK)

#define SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_MASK (0x3F000000U)
#define SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_SHIFT (24U)
/*! IPP_BOOT_MODE - Boot mode from pins */
#define SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_SHIFT)) & SRC_GENERAL_REG_SBMR2_IPP_BOOT_MODE_MASK)

#define SRC_GENERAL_REG_SBMR2_DIR_BT_DIS_MASK    (0x80000000U)
#define SRC_GENERAL_REG_SBMR2_DIR_BT_DIS_SHIFT   (31U)
/*! DIR_BT_DIS - Stores the value of DIR_BT_DIS from fusemap. Please see the fusemap for fuse details. */
#define SRC_GENERAL_REG_SBMR2_DIR_BT_DIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SBMR2_DIR_BT_DIS_SHIFT)) & SRC_GENERAL_REG_SBMR2_DIR_BT_DIS_MASK)
/*! @} */

/*! @name SMRSR - SRC Mix Slices Reset Status Register */
/*! @{ */

#define SRC_GENERAL_REG_SMRSR_RESET_DOMAIN_FLAG_MASK (0x1FFFFFFFU)
#define SRC_GENERAL_REG_SMRSR_RESET_DOMAIN_FLAG_SHIFT (0U)
/*! RESET_DOMAIN_FLAG - Indicates which reset event request asserted the reset */
#define SRC_GENERAL_REG_SMRSR_RESET_DOMAIN_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SMRSR_RESET_DOMAIN_FLAG_SHIFT)) & SRC_GENERAL_REG_SMRSR_RESET_DOMAIN_FLAG_MASK)
/*! @} */

/*! @name SRESR - SRC Reset Event Status Register */
/*! @{ */

#define SRC_GENERAL_REG_SRESR_RST_EVT_0_FLAG_MASK (0x1U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_0_FLAG_SHIFT (0U)
/*! RST_EVT_0_FLAG - CM33_LOCKUP_RST_EVT reset event flag
 *  0b0..CM33_LOCKUP_RST_EVT reset event not occurred
 *  0b1..CM33_LOCKUP_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_0_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_0_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_0_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_1_FLAG_MASK (0x2U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_1_FLAG_SHIFT (1U)
/*! RST_EVT_1_FLAG - CM33_SYS_RST_EVT reset event flag
 *  0b0..CM33_SYS_RST_EVT reset event not occurred
 *  0b1..CM33_SYS_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_1_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_1_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_1_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_2_FLAG_MASK (0x4U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_2_FLAG_SHIFT (2U)
/*! RST_EVT_2_FLAG - CM7_LOCKUP_RST_EVT reset event flag
 *  0b0..CM7_LOCKUP_RST_EVT reset event not occurred
 *  0b1..CM7_LOCKUP_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_2_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_2_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_2_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_3_FLAG_MASK (0x8U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_3_FLAG_SHIFT (3U)
/*! RST_EVT_3_FLAG - CM7_SYS_RST_EVT reset event flag
 *  0b0..CM7_SYS_RST_EVT reset event not occurred
 *  0b1..CM7_SYS_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_3_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_3_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_3_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_4_FLAG_MASK (0x10U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_4_FLAG_SHIFT (4U)
/*! RST_EVT_4_FLAG - FCCU_RST_EVT reset event flag
 *  0b0..FCCU_RST_EVT reset event not occurred
 *  0b1..FCCU_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_4_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_4_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_4_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_5_FLAG_MASK (0x20U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_5_FLAG_SHIFT (5U)
/*! RST_EVT_5_FLAG - JTAG_SW_RST_EVT reset event flag
 *  0b0..JTAG_SW_RST_EVT reset event not occurred
 *  0b1..JTAG_SW_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_5_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_5_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_5_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_6_FLAG_MASK (0x40U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_6_FLAG_SHIFT (6U)
/*! RST_EVT_6_FLAG - ELE_RST_EVT reset event flag
 *  0b0..ELE_RST_EVT reset event not occurred
 *  0b1..ELE_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_6_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_6_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_6_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_7_FLAG_MASK (0x80U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_7_FLAG_SHIFT (7U)
/*! RST_EVT_7_FLAG - TEMPSENSE_RST_EVT reset event flag
 *  0b0..TEMPSENSE_RST_EVT reset event not occurred
 *  0b1..TEMPSENSE_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_7_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_7_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_7_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_8_FLAG_MASK (0x100U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_8_FLAG_SHIFT (8U)
/*! RST_EVT_8_FLAG - WDOG1_RST_EVT reset event flag
 *  0b0..WDOG1_RST_EVT reset event not occurred
 *  0b1..WDOG1_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_8_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_8_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_8_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_9_FLAG_MASK (0x200U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_9_FLAG_SHIFT (9U)
/*! RST_EVT_9_FLAG - WDOG2_RST_EVT reset event flag
 *  0b0..WDOG2_RST_EVT reset event not occurred
 *  0b1..WDOG2_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_9_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_9_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_9_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_10_FLAG_MASK (0x400U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_10_FLAG_SHIFT (10U)
/*! RST_EVT_10_FLAG - WDOG3_RST_EVT reset event flag
 *  0b0..WDOG3_RST_EVT reset event not occurred
 *  0b1..WDOG3_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_10_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_10_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_10_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_11_FLAG_MASK (0x800U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_11_FLAG_SHIFT (11U)
/*! RST_EVT_11_FLAG - WDOG4_RST_EVT reset event flag
 *  0b0..WDOG4_RST_EVT reset event not occurred
 *  0b1..WDOG4_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_11_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_11_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_11_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_12_FLAG_MASK (0x1000U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_12_FLAG_SHIFT (12U)
/*! RST_EVT_12_FLAG - WDOG5_RST_EVT reset event flag
 *  0b0..WDOG5_RST_EVT reset event not occurred
 *  0b1..WDOG5_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_12_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_12_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_12_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_RST_EVT_13_FLAG_MASK (0x2000U)
#define SRC_GENERAL_REG_SRESR_RST_EVT_13_FLAG_SHIFT (13U)
/*! RST_EVT_13_FLAG - JTAG_RST_B_RST_EVT reset event flag
 *  0b0..JTAG_RST_B_RST_EVT reset event not occurred
 *  0b1..JTAG_RST_B_RST_EVT reset event occurred
 */
#define SRC_GENERAL_REG_SRESR_RST_EVT_13_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_RST_EVT_13_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_RST_EVT_13_FLAG_MASK)

#define SRC_GENERAL_REG_SRESR_SOC_POR_B_FLAG_MASK (0x80000000U)
#define SRC_GENERAL_REG_SRESR_SOC_POR_B_FLAG_SHIFT (31U)
/*! SOC_POR_B_FLAG - SOC_POR_B reset flag
 *  0b0..SOC_POR_B reset not occurred
 *  0b1..SOC_POR_B reset occurred
 */
#define SRC_GENERAL_REG_SRESR_SOC_POR_B_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRESR_SOC_POR_B_FLAG_SHIFT)) & SRC_GENERAL_REG_SRESR_SOC_POR_B_FLAG_MASK)
/*! @} */

/*! @name GPR1 - SRC General Purpose Register 1 */
/*! @{ */

#define SRC_GENERAL_REG_GPR1_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR1_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR1_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR1_GPR_SHIFT)) & SRC_GENERAL_REG_GPR1_GPR_MASK)
/*! @} */

/*! @name GPR2 - SRC General Purpose Register 2 */
/*! @{ */

#define SRC_GENERAL_REG_GPR2_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR2_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR2_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR2_GPR_SHIFT)) & SRC_GENERAL_REG_GPR2_GPR_MASK)
/*! @} */

/*! @name GPR3 - SRC General Purpose Register 3 */
/*! @{ */

#define SRC_GENERAL_REG_GPR3_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR3_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR3_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR3_GPR_SHIFT)) & SRC_GENERAL_REG_GPR3_GPR_MASK)
/*! @} */

/*! @name GPR4 - SRC General Purpose Register 4 */
/*! @{ */

#define SRC_GENERAL_REG_GPR4_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR4_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR4_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR4_GPR_SHIFT)) & SRC_GENERAL_REG_GPR4_GPR_MASK)
/*! @} */

/*! @name GPR5 - SRC General Purpose Register 5 */
/*! @{ */

#define SRC_GENERAL_REG_GPR5_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR5_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR5_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR5_GPR_SHIFT)) & SRC_GENERAL_REG_GPR5_GPR_MASK)
/*! @} */

/*! @name GPR6 - SRC General Purpose Register 6 */
/*! @{ */

#define SRC_GENERAL_REG_GPR6_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR6_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR6_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR6_GPR_SHIFT)) & SRC_GENERAL_REG_GPR6_GPR_MASK)
/*! @} */

/*! @name GPR7 - SRC General Purpose Register 7 */
/*! @{ */

#define SRC_GENERAL_REG_GPR7_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR7_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR7_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR7_GPR_SHIFT)) & SRC_GENERAL_REG_GPR7_GPR_MASK)
/*! @} */

/*! @name GPR8 - SRC General Purpose Register 8 */
/*! @{ */

#define SRC_GENERAL_REG_GPR8_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR8_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR8_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR8_GPR_SHIFT)) & SRC_GENERAL_REG_GPR8_GPR_MASK)
/*! @} */

/*! @name GPR9 - SRC General Purpose Register 9 */
/*! @{ */

#define SRC_GENERAL_REG_GPR9_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR9_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR9_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR9_GPR_SHIFT)) & SRC_GENERAL_REG_GPR9_GPR_MASK)
/*! @} */

/*! @name GPR10 - SRC General Purpose Register 10 */
/*! @{ */

#define SRC_GENERAL_REG_GPR10_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR10_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR10_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR10_GPR_SHIFT)) & SRC_GENERAL_REG_GPR10_GPR_MASK)
/*! @} */

/*! @name GPR11 - SRC General Purpose Register 11 */
/*! @{ */

#define SRC_GENERAL_REG_GPR11_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR11_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR11_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR11_GPR_SHIFT)) & SRC_GENERAL_REG_GPR11_GPR_MASK)
/*! @} */

/*! @name GPR12 - SRC General Purpose Register 12 */
/*! @{ */

#define SRC_GENERAL_REG_GPR12_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR12_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR12_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR12_GPR_SHIFT)) & SRC_GENERAL_REG_GPR12_GPR_MASK)
/*! @} */

/*! @name GPR13 - SRC General Purpose Register 13 */
/*! @{ */

#define SRC_GENERAL_REG_GPR13_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR13_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR13_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR13_GPR_SHIFT)) & SRC_GENERAL_REG_GPR13_GPR_MASK)
/*! @} */

/*! @name GPR14 - SRC General Purpose Register 14 */
/*! @{ */

#define SRC_GENERAL_REG_GPR14_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR14_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR14_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR14_GPR_SHIFT)) & SRC_GENERAL_REG_GPR14_GPR_MASK)
/*! @} */

/*! @name GPR15 - SRC General Purpose Register 16 */
/*! @{ */

#define SRC_GENERAL_REG_GPR15_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR15_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR15_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR15_GPR_SHIFT)) & SRC_GENERAL_REG_GPR15_GPR_MASK)
/*! @} */

/*! @name GPR16 - SRC General Purpose Register 16 */
/*! @{ */

#define SRC_GENERAL_REG_GPR16_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR16_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR16_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR16_GPR_SHIFT)) & SRC_GENERAL_REG_GPR16_GPR_MASK)
/*! @} */

/*! @name GPR17 - SRC General Purpose Register 17 */
/*! @{ */

#define SRC_GENERAL_REG_GPR17_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR17_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR17_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR17_GPR_SHIFT)) & SRC_GENERAL_REG_GPR17_GPR_MASK)
/*! @} */

/*! @name GPR18 - SRC General Purpose Register 18 */
/*! @{ */

#define SRC_GENERAL_REG_GPR18_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR18_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR18_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR18_GPR_SHIFT)) & SRC_GENERAL_REG_GPR18_GPR_MASK)
/*! @} */

/*! @name GPR19 - SRC General Purpose Register 19 */
/*! @{ */

#define SRC_GENERAL_REG_GPR19_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR19_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR19_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR19_GPR_SHIFT)) & SRC_GENERAL_REG_GPR19_GPR_MASK)
/*! @} */

/*! @name GPR20 - SRC General Purpose Register 20 */
/*! @{ */

#define SRC_GENERAL_REG_GPR20_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GENERAL_REG_GPR20_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GENERAL_REG_GPR20_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_GPR20_GPR_SHIFT)) & SRC_GENERAL_REG_GPR20_GPR_MASK)
/*! @} */

/*! @name CM_QUIESCE - SRC_CORTEX_M_QUIESCE */
/*! @{ */

#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_MASK (0x1U)
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_SHIFT (0U)
/*! SAFE_CM33_AHB_REQ - CM33 platform safe reset req control
 *  0b0..No effect
 *  0b1..request CM33 platform to be reset at safe state
 */
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_SHIFT)) & SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_REQ_MASK)

#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_MASK (0x2U)
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_SHIFT (1U)
/*! SAFE_CM33_AHB_ACK_STAT - CM33 platform safe reset ahb ack status
 *  0b0..No CM33 platform safe reset req or it could not be placed in safe state for reset sequencing
 *  0b1..CM33 platform is in safe state for reset sequencing
 */
#define SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_SHIFT)) & SRC_GENERAL_REG_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_MASK)
/*! @} */

/*! @name COLD_RESET_SSAR_ACK_CTRL - Cold reset SSAR acknowledge control */
/*! @{ */

#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK (0x3FFFU)
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT (0U)
/*! SSAR_CNT_CFG - ssar count configure. Usage depends on CNT_MODE */
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT)) & SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK)

#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode
 *  0b00..Not use counter, raise done to cold_reset_controller once get EdgeLock Enclave ack
 *  0b01..Delay after receiving EdgeLock Enclave ack, delay cycle number is CNT_CFG
 *  0b10..Ignore EdgeLock Enclave ack, raise done to cold_reset_controller when counting to CNT_CFG value
 *  0b11..Time out mode, raise done to cold_reset_controller when either EdgeLock Enclave ack received or counting to CNT_CFG value
 */
#define SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_GENERAL_REG_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name ROM_LP_CTRL - ROM Low Power Control */
/*! @{ */

#define SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_MASK (0x1U)
#define SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_SHIFT (0U)
/*! AONMIX_ROM_LP_EN - Low power control enable for ROM in AONMIX */
#define SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_SHIFT)) & SRC_GENERAL_REG_ROM_LP_CTRL_AONMIX_ROM_LP_EN_MASK)
/*! @} */

/*! @name A55_DENY_STAT - A55 Q_Channel Deny Status */
/*! @{ */

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_MASK (0x1U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_SHIFT (0U)
/*! A55_CORE0_PWRDN_DENY_STAT - A55 CORE 0 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_MASK (0x2U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_SHIFT (1U)
/*! A55_CORE1_PWRDN_DENY_STAT - A55 CORE 1 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_MASK (0x4U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_SHIFT (2U)
/*! A55_CORE2_PWRDN_DENY_STAT - A55 CORE 2 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_MASK (0x8U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_SHIFT (3U)
/*! A55_CORE3_PWRDN_DENY_STAT - A55 CORE 3 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_MASK (0x10U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_SHIFT (4U)
/*! A55_CORE4_PWRDN_DENY_STAT - A55 CORE 4 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_MASK (0x20U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_SHIFT (5U)
/*! A55_CORE5_PWRDN_DENY_STAT - A55 CORE 5 Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_MASK (0x40U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_SHIFT (6U)
/*! A55_CLUSTER_PWRDN_DENY_STAT - A55 Cluster Q_Channel pwrdn deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_MASK)

#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_MASK (0x80U)
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_SHIFT (7U)
/*! A55_CLUSTER_CLKOFF_DENY_STAT - A55 Cluster Q_Channel clockoff deny status */
#define SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_SHIFT)) & SRC_GENERAL_REG_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_MASK)
/*! @} */

/*! @name EVENT_RESET_SYSMAN_ACK_CTRL - Event Reset SYSMAN acknowledge control */
/*! @{ */

#define SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_MASK (0xFFU)
#define SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_SHIFT (0U)
/*! CNT_CFG - sysman count configure. Usage depends on CNT_MODE */
#define SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_SHIFT)) & SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_MASK)

#define SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode
 *  0b00..Not use counter, raise done to cold_reset_controller once get EdgeLock Enclave ack
 *  0b01..Delay after receiving EdgeLock Enclave ack, delay cycle number is CNT_CFG
 *  0b10..Ignore EdgeLock Enclave ack, raise done to cold_reset_controller when counting to CNT_CFG value
 *  0b11..Time out mode, raise done to cold_reset_controller when either EdgeLock Enclave ack received or counting to CNT_CFG value
 */
#define SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_GENERAL_REG_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name SRMR - SRC Reset Mode Register (SRMR) */
/*! @{ */

#define SRC_GENERAL_REG_SRMR_RSTR_0_MASK         (0x1U)
#define SRC_GENERAL_REG_SRMR_RSTR_0_SHIFT        (0U)
/*! RSTR_0 - configuration bit for independent reset of reset region ANAMIX by event <a>
 *  0b0..independent reset of reset region ANAMIX by event <a> is disabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_0(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_0_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_0_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_1_MASK         (0x2U)
#define SRC_GENERAL_REG_SRMR_RSTR_1_SHIFT        (1U)
/*! RSTR_1 - configuration bit for independent reset of reset region AONMIX_TOP by event <a>
 *  0b0..independent reset of reset region AONMIX_TOP by event <a> is disabled
 *  0b1..independent reset of reset region AONMIX_TOP by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_1(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_1_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_1_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_2_MASK         (0x4U)
#define SRC_GENERAL_REG_SRMR_RSTR_2_SHIFT        (2U)
/*! RSTR_2 - configuration bit for independent reset of reset region AONMIX_M33 by event <a>
 *  0b0..independent reset of reset region AONMIX_M33 by event <a> is disabled
 *  0b1..independent reset of reset region AONMIX_M33 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_2(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_2_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_2_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_3_MASK         (0x8U)
#define SRC_GENERAL_REG_SRMR_RSTR_3_SHIFT        (3U)
/*! RSTR_3 - configuration bit for independent reset of reset region AONMIX_ELE by event <a>
 *  0b0..independent reset of reset region AONMIX_ELE by event <a> is disabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_3(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_3_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_3_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_4_MASK         (0x10U)
#define SRC_GENERAL_REG_SRMR_RSTR_4_SHIFT        (4U)
/*! RSTR_4 - configuration bit for independent reset of reset region BBSMMIX by event <a>
 *  0b0..independent reset of reset region BBSMMIX by event <a> is disabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_4(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_4_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_4_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_5_MASK         (0x20U)
#define SRC_GENERAL_REG_SRMR_RSTR_5_SHIFT        (5U)
/*! RSTR_5 - configuration bit for independent reset of reset region CAMERAMIX by event <a>
 *  0b0..independent reset of reset region CAMERAMIX by event <a> is disabled
 *  0b1..independent reset of reset region CAMERAMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_5(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_5_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_5_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_6_MASK         (0x40U)
#define SRC_GENERAL_REG_SRMR_RSTR_6_SHIFT        (6U)
/*! RSTR_6 - configuration bit for independent reset of reset region CCMSRCGPCMIX by event <a>
 *  0b0..independent reset of reset region CCMSRCGPCMIX by event <a> is disabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_6(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_6_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_6_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_7_MASK         (0x80U)
#define SRC_GENERAL_REG_SRMR_RSTR_7_SHIFT        (7U)
/*! RSTR_7 - configuration bit for independent reset of reset region CORTEXAMIX_CORE0 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE0 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE0 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_7(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_7_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_7_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_8_MASK         (0x100U)
#define SRC_GENERAL_REG_SRMR_RSTR_8_SHIFT        (8U)
/*! RSTR_8 - configuration bit for independent reset of reset region CORTEXAMIX_CORE1 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE1 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE1 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_8(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_8_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_8_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_9_MASK         (0x200U)
#define SRC_GENERAL_REG_SRMR_RSTR_9_SHIFT        (9U)
/*! RSTR_9 - configuration bit for independent reset of reset region CORTEXAMIX_CORE2 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE2 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE2 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_9(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_9_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_9_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_10_MASK        (0x400U)
#define SRC_GENERAL_REG_SRMR_RSTR_10_SHIFT       (10U)
/*! RSTR_10 - configuration bit for independent reset of reset region CORTEXAMIX_CORE3 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE3 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE3 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_10(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_10_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_10_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_11_MASK        (0x800U)
#define SRC_GENERAL_REG_SRMR_RSTR_11_SHIFT       (11U)
/*! RSTR_11 - configuration bit for independent reset of reset region CORTEXAMIX_CORE4 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE4 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE4 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_11(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_11_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_11_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_12_MASK        (0x1000U)
#define SRC_GENERAL_REG_SRMR_RSTR_12_SHIFT       (12U)
/*! RSTR_12 - configuration bit for independent reset of reset region CORTEXAMIX_CORE5 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE5 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE5 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_12(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_12_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_12_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_13_MASK        (0x2000U)
#define SRC_GENERAL_REG_SRMR_RSTR_13_SHIFT       (13U)
/*! RSTR_13 - configuration bit for independent reset of reset region CORTEXAMIX_PLATFORM by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_PLATFORM by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_PLATFORM by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_13(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_13_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_13_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_14_MASK        (0x4000U)
#define SRC_GENERAL_REG_SRMR_RSTR_14_SHIFT       (14U)
/*! RSTR_14 - configuration bit for independent reset of reset region DDRMIX_TOP by event <a>
 *  0b0..independent reset of reset region DDRMIX_TOP by event <a> is disabled
 *  0b1..independent reset of reset region DDRMIX_TOP by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_14(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_14_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_14_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_15_MASK        (0x8000U)
#define SRC_GENERAL_REG_SRMR_RSTR_15_SHIFT       (15U)
/*! RSTR_15 - configuration bit for independent reset of reset region DDRMIX_PHY by event <a>
 *  0b0..independent reset of reset region DDRMIX_PHY by event <a> is disabled
 *  0b1..independent reset of reset region DDRMIX_PHY by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_15(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_15_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_15_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_16_MASK        (0x10000U)
#define SRC_GENERAL_REG_SRMR_RSTR_16_SHIFT       (16U)
/*! RSTR_16 - configuration bit for independent reset of reset region DISPLAYMIX by event <a>
 *  0b0..independent reset of reset region DISPLAYMIX by event <a> is disabled
 *  0b1..independent reset of reset region DISPLAYMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_16(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_16_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_16_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_17_MASK        (0x20000U)
#define SRC_GENERAL_REG_SRMR_RSTR_17_SHIFT       (17U)
/*! RSTR_17 - configuration bit for independent reset of reset region GPUMIX by event <a>
 *  0b0..independent reset of reset region GPUMIX by event <a> is disabled
 *  0b1..independent reset of reset region GPUMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_17(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_17_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_17_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_18_MASK        (0x40000U)
#define SRC_GENERAL_REG_SRMR_RSTR_18_SHIFT       (18U)
/*! RSTR_18 - configuration bit for independent reset of reset region HSIOMIX_TOP by event <a>
 *  0b0..independent reset of reset region HSIOMIX_TOP by event <a> is disabled
 *  0b1..independent reset of reset region HSIOMIX_TOP by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_18(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_18_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_18_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_19_MASK        (0x80000U)
#define SRC_GENERAL_REG_SRMR_RSTR_19_SHIFT       (19U)
/*! RSTR_19 - configuration bit for independent reset of reset region HSIOMIX_WAON by event <a>
 *  0b0..independent reset of reset region HSIOMIX_WAON by event <a> is disabled
 *  0b1..independent reset of reset region HSIOMIX_WAON by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_19(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_19_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_19_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_20_MASK        (0x100000U)
#define SRC_GENERAL_REG_SRMR_RSTR_20_SHIFT       (20U)
/*! RSTR_20 - configuration bit for independent reset of reset region M7MIX by event <a>
 *  0b0..independent reset of reset region M7MIX by event <a> is disabled
 *  0b1..independent reset of reset region M7MIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_20(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_20_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_20_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_21_MASK        (0x200000U)
#define SRC_GENERAL_REG_SRMR_RSTR_21_SHIFT       (21U)
/*! RSTR_21 - configuration bit for independent reset of reset region NETCMIX by event <a>
 *  0b0..independent reset of reset region NETCMIX by event <a> is disabled
 *  0b1..independent reset of reset region NETCMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_21(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_21_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_21_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_22_MASK        (0x400000U)
#define SRC_GENERAL_REG_SRMR_RSTR_22_SHIFT       (22U)
/*! RSTR_22 - configuration bit for independent reset of reset region NOCMIX by event <a>
 *  0b0..independent reset of reset region NOCMIX by event <a> is disabled
 *  0b1..independent reset of reset region NOCMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_22(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_22_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_22_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_23_MASK        (0x800000U)
#define SRC_GENERAL_REG_SRMR_RSTR_23_SHIFT       (23U)
/*! RSTR_23 - configuration bit for independent reset of reset region NPUMIX by event <a>
 *  0b0..independent reset of reset region NPUMIX by event <a> is disabled
 *  0b1..independent reset of reset region NPUMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_23(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_23_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_23_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_24_MASK        (0x1000000U)
#define SRC_GENERAL_REG_SRMR_RSTR_24_SHIFT       (24U)
/*! RSTR_24 - configuration bit for independent reset of reset region VPUMIX by event <a>
 *  0b0..independent reset of reset region VPUMIX by event <a> is disabled
 *  0b1..independent reset of reset region VPUMIX by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_24(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_24_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_24_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_25_MASK        (0x2000000U)
#define SRC_GENERAL_REG_SRMR_RSTR_25_SHIFT       (25U)
/*! RSTR_25 - configuration bit for independent reset of reset region WAKEUPMIX_TOP by event <a>
 *  0b0..independent reset of reset region WAKEUPMIX_TOP by event <a> is disabled
 *  0b1..independent reset of reset region WAKEUPMIX_TOP by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_25(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_25_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_25_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_26_MASK        (0x4000000U)
#define SRC_GENERAL_REG_SRMR_RSTR_26_SHIFT       (26U)
/*! RSTR_26 - configuration bit for independent reset of reset region WAKEUPMIX_JTAG by event <a>
 *  0b0..independent reset of reset region WAKEUPMIX_JTAG by event <a> is disabled
 *  0b1..independent reset of reset region WAKEUPMIX_JTAG by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_26(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_26_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_26_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_27_MASK        (0x8000000U)
#define SRC_GENERAL_REG_SRMR_RSTR_27_SHIFT       (27U)
/*! RSTR_27 - configuration bit for independent reset of reset region WAKEUPMIX_WDOG_3_4 by event <a>
 *  0b0..independent reset of reset region WAKEUPMIX_WDOG_3_4 by event <a> is disabled
 *  0b1..independent reset of reset region WAKEUPMIX_WDOG_3_4 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_27(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_27_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_27_MASK)

#define SRC_GENERAL_REG_SRMR_RSTR_28_MASK        (0x10000000U)
#define SRC_GENERAL_REG_SRMR_RSTR_28_SHIFT       (28U)
/*! RSTR_28 - configuration bit for independent reset of reset region WAKEUPMIX_WDOG_5 by event <a>
 *  0b0..independent reset of reset region WAKEUPMIX_WDOG_5 by event <a> is disabled
 *  0b1..independent reset of reset region WAKEUPMIX_WDOG_5 by event <a> is enabled
 */
#define SRC_GENERAL_REG_SRMR_RSTR_28(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRMR_RSTR_28_SHIFT)) & SRC_GENERAL_REG_SRMR_RSTR_28_MASK)
/*! @} */

/* The count of SRC_GENERAL_REG_SRMR */
#define SRC_GENERAL_REG_SRMR_COUNT               (14U)

/*! @name SRDR - SRC Reset Disable Register */
/*! @{ */

#define SRC_GENERAL_REG_SRDR_RSTR_0_RDIS_MASK    (0x1U)
#define SRC_GENERAL_REG_SRDR_RSTR_0_RDIS_SHIFT   (0U)
/*! RSTR_0_RDIS - configuration bit to disbale reset of reset region ANAMIX by reset event
 *  0b0..reset of reset region ANAMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_0_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_0_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_0_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_1_RDIS_MASK    (0x2U)
#define SRC_GENERAL_REG_SRDR_RSTR_1_RDIS_SHIFT   (1U)
/*! RSTR_1_RDIS - configuration bit to disbale reset of reset region AONMIX_TOP by reset event
 *  0b0..reset of reset region AONMIX_TOP by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_1_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_1_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_1_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_2_RDIS_MASK    (0x4U)
#define SRC_GENERAL_REG_SRDR_RSTR_2_RDIS_SHIFT   (2U)
/*! RSTR_2_RDIS - configuration bit to disbale reset of reset region AONMIX_M33 by reset event
 *  0b0..reset of reset region AONMIX_M33 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_2_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_2_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_2_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_3_RDIS_MASK    (0x8U)
#define SRC_GENERAL_REG_SRDR_RSTR_3_RDIS_SHIFT   (3U)
/*! RSTR_3_RDIS - configuration bit to disbale reset of reset region AONMIX_ELE by reset event
 *  0b0..reset of reset region AONMIX_ELE by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_3_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_3_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_3_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_4_RDIS_MASK    (0x10U)
#define SRC_GENERAL_REG_SRDR_RSTR_4_RDIS_SHIFT   (4U)
/*! RSTR_4_RDIS - configuration bit to disbale reset of reset region BBSMMIX by reset event
 *  0b0..reset of reset region BBSMMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_4_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_4_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_4_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_5_RDIS_MASK    (0x20U)
#define SRC_GENERAL_REG_SRDR_RSTR_5_RDIS_SHIFT   (5U)
/*! RSTR_5_RDIS - configuration bit to disbale reset of reset region CAMERAMIX by reset event
 *  0b0..reset of reset region CAMERAMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_5_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_5_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_5_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_6_RDIS_MASK    (0x40U)
#define SRC_GENERAL_REG_SRDR_RSTR_6_RDIS_SHIFT   (6U)
/*! RSTR_6_RDIS - configuration bit to disbale reset of reset region CCMSRCGPCMIX by reset event
 *  0b0..reset of reset region CCMSRCGPCMIX by reset event is not disabled
 *  0b1..reset of reset region CCMSRCGPCMIX by reset event is disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_6_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_6_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_6_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_7_RDIS_MASK    (0x80U)
#define SRC_GENERAL_REG_SRDR_RSTR_7_RDIS_SHIFT   (7U)
/*! RSTR_7_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_CORE0 by reset event
 *  0b0..reset of reset region CORTEXAMIX_CORE0 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_7_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_7_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_7_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_8_RDIS_MASK    (0x100U)
#define SRC_GENERAL_REG_SRDR_RSTR_8_RDIS_SHIFT   (8U)
/*! RSTR_8_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_CORE1 by reset event
 *  0b0..reset of reset region CORTEXAMIX_CORE1 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_8_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_8_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_8_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_9_RDIS_MASK    (0x200U)
#define SRC_GENERAL_REG_SRDR_RSTR_9_RDIS_SHIFT   (9U)
/*! RSTR_9_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_CORE2 by reset event
 *  0b0..reset of reset region CORTEXAMIX_CORE2 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_9_RDIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_9_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_9_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_10_RDIS_MASK   (0x400U)
#define SRC_GENERAL_REG_SRDR_RSTR_10_RDIS_SHIFT  (10U)
/*! RSTR_10_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_CORE3 by reset event
 *  0b0..reset of reset region CORTEXAMIX_CORE3 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_10_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_10_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_10_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_11_RDIS_MASK   (0x800U)
#define SRC_GENERAL_REG_SRDR_RSTR_11_RDIS_SHIFT  (11U)
/*! RSTR_11_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_CORE4 by reset event
 *  0b0..reset of reset region CORTEXAMIX_CORE4 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_11_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_11_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_11_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_12_RDIS_MASK   (0x1000U)
#define SRC_GENERAL_REG_SRDR_RSTR_12_RDIS_SHIFT  (12U)
/*! RSTR_12_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_CORE5 by reset event
 *  0b0..reset of reset region CORTEXAMIX_CORE5 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_12_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_12_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_12_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_13_RDIS_MASK   (0x2000U)
#define SRC_GENERAL_REG_SRDR_RSTR_13_RDIS_SHIFT  (13U)
/*! RSTR_13_RDIS - configuration bit to disbale reset of reset region CORTEXAMIX_PLATFORM by reset event
 *  0b0..reset of reset region CORTEXAMIX_PLATFORM by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_13_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_13_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_13_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_14_RDIS_MASK   (0x4000U)
#define SRC_GENERAL_REG_SRDR_RSTR_14_RDIS_SHIFT  (14U)
/*! RSTR_14_RDIS - configuration bit to disbale reset of reset region DDRMIX_TOP by reset event
 *  0b0..reset of reset region DDRMIX_TOP by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_14_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_14_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_14_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_15_RDIS_MASK   (0x8000U)
#define SRC_GENERAL_REG_SRDR_RSTR_15_RDIS_SHIFT  (15U)
/*! RSTR_15_RDIS - configuration bit to disbale reset of reset region DDRMIX_PHY by reset event
 *  0b0..reset of reset region DDRMIX_PHY by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_15_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_15_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_15_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_16_RDIS_MASK   (0x10000U)
#define SRC_GENERAL_REG_SRDR_RSTR_16_RDIS_SHIFT  (16U)
/*! RSTR_16_RDIS - configuration bit to disbale reset of reset region DISPLAYMIX by reset event
 *  0b0..reset of reset region DISPLAYMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_16_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_16_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_16_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_17_RDIS_MASK   (0x20000U)
#define SRC_GENERAL_REG_SRDR_RSTR_17_RDIS_SHIFT  (17U)
/*! RSTR_17_RDIS - configuration bit to disbale reset of reset region GPUMIX by reset event
 *  0b0..reset of reset region GPUMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_17_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_17_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_17_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_18_RDIS_MASK   (0x40000U)
#define SRC_GENERAL_REG_SRDR_RSTR_18_RDIS_SHIFT  (18U)
/*! RSTR_18_RDIS - configuration bit to disbale reset of reset region HSIOMIX_TOP by reset event
 *  0b0..reset of reset region HSIOMIX_TOP by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_18_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_18_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_18_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_19_RDIS_MASK   (0x80000U)
#define SRC_GENERAL_REG_SRDR_RSTR_19_RDIS_SHIFT  (19U)
/*! RSTR_19_RDIS - configuration bit to disbale reset of reset region HSIOMIX_WAON by reset event
 *  0b0..reset of reset region HSIOMIX_WAON by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_19_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_19_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_19_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_20_RDIS_MASK   (0x100000U)
#define SRC_GENERAL_REG_SRDR_RSTR_20_RDIS_SHIFT  (20U)
/*! RSTR_20_RDIS - configuration bit to disbale reset of reset region M7MIX by reset event
 *  0b0..reset of reset region M7MIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_20_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_20_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_20_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_21_RDIS_MASK   (0x200000U)
#define SRC_GENERAL_REG_SRDR_RSTR_21_RDIS_SHIFT  (21U)
/*! RSTR_21_RDIS - configuration bit to disbale reset of reset region NETCMIX by reset event
 *  0b0..reset of reset region NETCMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_21_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_21_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_21_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_22_RDIS_MASK   (0x400000U)
#define SRC_GENERAL_REG_SRDR_RSTR_22_RDIS_SHIFT  (22U)
/*! RSTR_22_RDIS - configuration bit to disbale reset of reset region NOCMIX by reset event
 *  0b0..reset of reset region NOCMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_22_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_22_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_22_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_23_RDIS_MASK   (0x800000U)
#define SRC_GENERAL_REG_SRDR_RSTR_23_RDIS_SHIFT  (23U)
/*! RSTR_23_RDIS - configuration bit to disbale reset of reset region NPUMIX by reset event
 *  0b0..reset of reset region NPUMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_23_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_23_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_23_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_24_RDIS_MASK   (0x1000000U)
#define SRC_GENERAL_REG_SRDR_RSTR_24_RDIS_SHIFT  (24U)
/*! RSTR_24_RDIS - configuration bit to disbale reset of reset region VPUMIX by reset event
 *  0b0..reset of reset region VPUMIX by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_24_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_24_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_24_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_25_RDIS_MASK   (0x2000000U)
#define SRC_GENERAL_REG_SRDR_RSTR_25_RDIS_SHIFT  (25U)
/*! RSTR_25_RDIS - configuration bit to disbale reset of reset region WAKEUPMIX_TOP by reset event
 *  0b0..reset of reset region WAKEUPMIX_TOP by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_25_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_25_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_25_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_26_RDIS_MASK   (0x4000000U)
#define SRC_GENERAL_REG_SRDR_RSTR_26_RDIS_SHIFT  (26U)
/*! RSTR_26_RDIS - configuration bit to disbale reset of reset region WAKEUPMIX_JTAG by reset event
 *  0b0..reset of reset region WAKEUPMIX_JTAG by reset event is not disabled
 *  0b1..reset of reset region WAKEUPMIX_JTAG by reset event is disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_26_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_26_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_26_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_27_RDIS_MASK   (0x8000000U)
#define SRC_GENERAL_REG_SRDR_RSTR_27_RDIS_SHIFT  (27U)
/*! RSTR_27_RDIS - configuration bit to disbale reset of reset region WAKEUPMIX_WDOG_3_4 by reset event
 *  0b0..reset of reset region WAKEUPMIX_WDOG_3_4 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_27_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_27_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_27_RDIS_MASK)

#define SRC_GENERAL_REG_SRDR_RSTR_28_RDIS_MASK   (0x10000000U)
#define SRC_GENERAL_REG_SRDR_RSTR_28_RDIS_SHIFT  (28U)
/*! RSTR_28_RDIS - configuration bit to disbale reset of reset region WAKEUPMIX_WDOG_5 by reset event
 *  0b0..reset of reset region WAKEUPMIX_WDOG_5 by reset event is not disabled
 */
#define SRC_GENERAL_REG_SRDR_RSTR_28_RDIS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_REG_SRDR_RSTR_28_RDIS_SHIFT)) & SRC_GENERAL_REG_SRDR_RSTR_28_RDIS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_GENERAL_REG_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_GENERAL_REG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* SRC_GENERAL_REG_H_ */

