/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMU
 *
 * CMSIS Peripheral Access Layer for PMU
 */

#if !defined(PERI_PMU_H_)
#define PERI_PMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[272];
  __IO uint32_t REG_1P1;                           /**< Regulator 1P1 Register, offset: 0x110 */
  __IO uint32_t REG_1P1_SET;                       /**< Regulator 1P1 Register, offset: 0x114 */
  __IO uint32_t REG_1P1_CLR;                       /**< Regulator 1P1 Register, offset: 0x118 */
  __IO uint32_t REG_1P1_TOG;                       /**< Regulator 1P1 Register, offset: 0x11C */
  __IO uint32_t REG_3P0;                           /**< Regulator 3P0 Register, offset: 0x120 */
  __IO uint32_t REG_3P0_SET;                       /**< Regulator 3P0 Register, offset: 0x124 */
  __IO uint32_t REG_3P0_CLR;                       /**< Regulator 3P0 Register, offset: 0x128 */
  __IO uint32_t REG_3P0_TOG;                       /**< Regulator 3P0 Register, offset: 0x12C */
  __IO uint32_t REG_2P5;                           /**< Regulator 2P5 Register, offset: 0x130 */
  __IO uint32_t REG_2P5_SET;                       /**< Regulator 2P5 Register, offset: 0x134 */
  __IO uint32_t REG_2P5_CLR;                       /**< Regulator 2P5 Register, offset: 0x138 */
  __IO uint32_t REG_2P5_TOG;                       /**< Regulator 2P5 Register, offset: 0x13C */
  __IO uint32_t REG_CORE;                          /**< Digital Regulator Core Register, offset: 0x140 */
  __IO uint32_t REG_CORE_SET;                      /**< Digital Regulator Core Register, offset: 0x144 */
  __IO uint32_t REG_CORE_CLR;                      /**< Digital Regulator Core Register, offset: 0x148 */
  __IO uint32_t REG_CORE_TOG;                      /**< Digital Regulator Core Register, offset: 0x14C */
  __IO uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  __IO uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  __IO uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  __IO uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  __IO uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  __IO uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  __IO uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  __IO uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  __IO uint32_t MISC2;                             /**< Miscellaneous Control Register, offset: 0x170 */
  __IO uint32_t MISC2_SET;                         /**< Miscellaneous Control Register, offset: 0x174 */
  __IO uint32_t MISC2_CLR;                         /**< Miscellaneous Control Register, offset: 0x178 */
  __IO uint32_t MISC2_TOG;                         /**< Miscellaneous Control Register, offset: 0x17C */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name REG_1P1 - Regulator 1P1 Register */
/*! @{ */

#define PMU_REG_1P1_ENABLE_LINREG_MASK           (0x1U)
#define PMU_REG_1P1_ENABLE_LINREG_SHIFT          (0U)
#define PMU_REG_1P1_ENABLE_LINREG(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_ENABLE_LINREG_SHIFT)) & PMU_REG_1P1_ENABLE_LINREG_MASK)

#define PMU_REG_1P1_ENABLE_BO_MASK               (0x2U)
#define PMU_REG_1P1_ENABLE_BO_SHIFT              (1U)
#define PMU_REG_1P1_ENABLE_BO(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_ENABLE_BO_SHIFT)) & PMU_REG_1P1_ENABLE_BO_MASK)

#define PMU_REG_1P1_ENABLE_ILIMIT_MASK           (0x4U)
#define PMU_REG_1P1_ENABLE_ILIMIT_SHIFT          (2U)
#define PMU_REG_1P1_ENABLE_ILIMIT(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_ENABLE_ILIMIT_SHIFT)) & PMU_REG_1P1_ENABLE_ILIMIT_MASK)

#define PMU_REG_1P1_ENABLE_PULLDOWN_MASK         (0x8U)
#define PMU_REG_1P1_ENABLE_PULLDOWN_SHIFT        (3U)
#define PMU_REG_1P1_ENABLE_PULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_1P1_ENABLE_PULLDOWN_MASK)

#define PMU_REG_1P1_BO_OFFSET_MASK               (0x70U)
#define PMU_REG_1P1_BO_OFFSET_SHIFT              (4U)
#define PMU_REG_1P1_BO_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_BO_OFFSET_SHIFT)) & PMU_REG_1P1_BO_OFFSET_MASK)

#define PMU_REG_1P1_OUTPUT_TRG_MASK              (0x1F00U)
#define PMU_REG_1P1_OUTPUT_TRG_SHIFT             (8U)
/*! OUTPUT_TRG
 *  0b000x1..1.375V
 *  0b00100..0.8V
 *  0b10000..1.1V
 */
#define PMU_REG_1P1_OUTPUT_TRG(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_OUTPUT_TRG_SHIFT)) & PMU_REG_1P1_OUTPUT_TRG_MASK)

#define PMU_REG_1P1_BO_VDD1P1_MASK               (0x10000U)
#define PMU_REG_1P1_BO_VDD1P1_SHIFT              (16U)
#define PMU_REG_1P1_BO_VDD1P1(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_BO_VDD1P1_SHIFT)) & PMU_REG_1P1_BO_VDD1P1_MASK)

#define PMU_REG_1P1_OK_VDD1P1_MASK               (0x20000U)
#define PMU_REG_1P1_OK_VDD1P1_SHIFT              (17U)
#define PMU_REG_1P1_OK_VDD1P1(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_OK_VDD1P1_SHIFT)) & PMU_REG_1P1_OK_VDD1P1_MASK)

#define PMU_REG_1P1_ENABLE_WEAK_LINREG_MASK      (0x40000U)
#define PMU_REG_1P1_ENABLE_WEAK_LINREG_SHIFT     (18U)
#define PMU_REG_1P1_ENABLE_WEAK_LINREG(x)        (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_ENABLE_WEAK_LINREG_MASK)

#define PMU_REG_1P1_SELREF_WEAK_LINREG_MASK      (0x80000U)
#define PMU_REG_1P1_SELREF_WEAK_LINREG_SHIFT     (19U)
/*! SELREF_WEAK_LINREG
 *  0b0..Weak-linreg output tracks low-power-bandgap voltage
 *  0b1..Weak-linreg output tracks VDD_SOC_IN voltage
 */
#define PMU_REG_1P1_SELREF_WEAK_LINREG(x)        (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SELREF_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_SELREF_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_1P1_SET - Regulator 1P1 Register */
/*! @{ */

#define PMU_REG_1P1_SET_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_1P1_SET_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_1P1_SET_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_ENABLE_LINREG_SHIFT)) & PMU_REG_1P1_SET_ENABLE_LINREG_MASK)

#define PMU_REG_1P1_SET_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_1P1_SET_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_1P1_SET_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_ENABLE_BO_SHIFT)) & PMU_REG_1P1_SET_ENABLE_BO_MASK)

#define PMU_REG_1P1_SET_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_1P1_SET_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_1P1_SET_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_ENABLE_ILIMIT_SHIFT)) & PMU_REG_1P1_SET_ENABLE_ILIMIT_MASK)

#define PMU_REG_1P1_SET_ENABLE_PULLDOWN_MASK     (0x8U)
#define PMU_REG_1P1_SET_ENABLE_PULLDOWN_SHIFT    (3U)
#define PMU_REG_1P1_SET_ENABLE_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_1P1_SET_ENABLE_PULLDOWN_MASK)

#define PMU_REG_1P1_SET_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_1P1_SET_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_1P1_SET_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_BO_OFFSET_SHIFT)) & PMU_REG_1P1_SET_BO_OFFSET_MASK)

#define PMU_REG_1P1_SET_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_1P1_SET_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b000x1..1.375V
 *  0b00100..0.8V
 *  0b10000..1.1V
 */
#define PMU_REG_1P1_SET_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_OUTPUT_TRG_SHIFT)) & PMU_REG_1P1_SET_OUTPUT_TRG_MASK)

#define PMU_REG_1P1_SET_BO_VDD1P1_MASK           (0x10000U)
#define PMU_REG_1P1_SET_BO_VDD1P1_SHIFT          (16U)
#define PMU_REG_1P1_SET_BO_VDD1P1(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_BO_VDD1P1_SHIFT)) & PMU_REG_1P1_SET_BO_VDD1P1_MASK)

#define PMU_REG_1P1_SET_OK_VDD1P1_MASK           (0x20000U)
#define PMU_REG_1P1_SET_OK_VDD1P1_SHIFT          (17U)
#define PMU_REG_1P1_SET_OK_VDD1P1(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_OK_VDD1P1_SHIFT)) & PMU_REG_1P1_SET_OK_VDD1P1_MASK)

#define PMU_REG_1P1_SET_ENABLE_WEAK_LINREG_MASK  (0x40000U)
#define PMU_REG_1P1_SET_ENABLE_WEAK_LINREG_SHIFT (18U)
#define PMU_REG_1P1_SET_ENABLE_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_SET_ENABLE_WEAK_LINREG_MASK)

#define PMU_REG_1P1_SET_SELREF_WEAK_LINREG_MASK  (0x80000U)
#define PMU_REG_1P1_SET_SELREF_WEAK_LINREG_SHIFT (19U)
/*! SELREF_WEAK_LINREG
 *  0b0..Weak-linreg output tracks low-power-bandgap voltage
 *  0b1..Weak-linreg output tracks VDD_SOC_IN voltage
 */
#define PMU_REG_1P1_SET_SELREF_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_SET_SELREF_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_SET_SELREF_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_1P1_CLR - Regulator 1P1 Register */
/*! @{ */

#define PMU_REG_1P1_CLR_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_1P1_CLR_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_1P1_CLR_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_ENABLE_LINREG_SHIFT)) & PMU_REG_1P1_CLR_ENABLE_LINREG_MASK)

#define PMU_REG_1P1_CLR_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_1P1_CLR_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_1P1_CLR_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_ENABLE_BO_SHIFT)) & PMU_REG_1P1_CLR_ENABLE_BO_MASK)

#define PMU_REG_1P1_CLR_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_1P1_CLR_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_1P1_CLR_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_ENABLE_ILIMIT_SHIFT)) & PMU_REG_1P1_CLR_ENABLE_ILIMIT_MASK)

#define PMU_REG_1P1_CLR_ENABLE_PULLDOWN_MASK     (0x8U)
#define PMU_REG_1P1_CLR_ENABLE_PULLDOWN_SHIFT    (3U)
#define PMU_REG_1P1_CLR_ENABLE_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_1P1_CLR_ENABLE_PULLDOWN_MASK)

#define PMU_REG_1P1_CLR_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_1P1_CLR_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_1P1_CLR_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_BO_OFFSET_SHIFT)) & PMU_REG_1P1_CLR_BO_OFFSET_MASK)

#define PMU_REG_1P1_CLR_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_1P1_CLR_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b000x1..1.375V
 *  0b00100..0.8V
 *  0b10000..1.1V
 */
#define PMU_REG_1P1_CLR_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_OUTPUT_TRG_SHIFT)) & PMU_REG_1P1_CLR_OUTPUT_TRG_MASK)

#define PMU_REG_1P1_CLR_BO_VDD1P1_MASK           (0x10000U)
#define PMU_REG_1P1_CLR_BO_VDD1P1_SHIFT          (16U)
#define PMU_REG_1P1_CLR_BO_VDD1P1(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_BO_VDD1P1_SHIFT)) & PMU_REG_1P1_CLR_BO_VDD1P1_MASK)

#define PMU_REG_1P1_CLR_OK_VDD1P1_MASK           (0x20000U)
#define PMU_REG_1P1_CLR_OK_VDD1P1_SHIFT          (17U)
#define PMU_REG_1P1_CLR_OK_VDD1P1(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_OK_VDD1P1_SHIFT)) & PMU_REG_1P1_CLR_OK_VDD1P1_MASK)

#define PMU_REG_1P1_CLR_ENABLE_WEAK_LINREG_MASK  (0x40000U)
#define PMU_REG_1P1_CLR_ENABLE_WEAK_LINREG_SHIFT (18U)
#define PMU_REG_1P1_CLR_ENABLE_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_CLR_ENABLE_WEAK_LINREG_MASK)

#define PMU_REG_1P1_CLR_SELREF_WEAK_LINREG_MASK  (0x80000U)
#define PMU_REG_1P1_CLR_SELREF_WEAK_LINREG_SHIFT (19U)
/*! SELREF_WEAK_LINREG
 *  0b0..Weak-linreg output tracks low-power-bandgap voltage
 *  0b1..Weak-linreg output tracks VDD_SOC_IN voltage
 */
#define PMU_REG_1P1_CLR_SELREF_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_CLR_SELREF_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_CLR_SELREF_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_1P1_TOG - Regulator 1P1 Register */
/*! @{ */

#define PMU_REG_1P1_TOG_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_1P1_TOG_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_1P1_TOG_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_ENABLE_LINREG_SHIFT)) & PMU_REG_1P1_TOG_ENABLE_LINREG_MASK)

#define PMU_REG_1P1_TOG_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_1P1_TOG_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_1P1_TOG_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_ENABLE_BO_SHIFT)) & PMU_REG_1P1_TOG_ENABLE_BO_MASK)

#define PMU_REG_1P1_TOG_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_1P1_TOG_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_1P1_TOG_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_ENABLE_ILIMIT_SHIFT)) & PMU_REG_1P1_TOG_ENABLE_ILIMIT_MASK)

#define PMU_REG_1P1_TOG_ENABLE_PULLDOWN_MASK     (0x8U)
#define PMU_REG_1P1_TOG_ENABLE_PULLDOWN_SHIFT    (3U)
#define PMU_REG_1P1_TOG_ENABLE_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_1P1_TOG_ENABLE_PULLDOWN_MASK)

#define PMU_REG_1P1_TOG_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_1P1_TOG_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_1P1_TOG_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_BO_OFFSET_SHIFT)) & PMU_REG_1P1_TOG_BO_OFFSET_MASK)

#define PMU_REG_1P1_TOG_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_1P1_TOG_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b000x1..1.375V
 *  0b00100..0.8V
 *  0b10000..1.1V
 */
#define PMU_REG_1P1_TOG_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_OUTPUT_TRG_SHIFT)) & PMU_REG_1P1_TOG_OUTPUT_TRG_MASK)

#define PMU_REG_1P1_TOG_BO_VDD1P1_MASK           (0x10000U)
#define PMU_REG_1P1_TOG_BO_VDD1P1_SHIFT          (16U)
#define PMU_REG_1P1_TOG_BO_VDD1P1(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_BO_VDD1P1_SHIFT)) & PMU_REG_1P1_TOG_BO_VDD1P1_MASK)

#define PMU_REG_1P1_TOG_OK_VDD1P1_MASK           (0x20000U)
#define PMU_REG_1P1_TOG_OK_VDD1P1_SHIFT          (17U)
#define PMU_REG_1P1_TOG_OK_VDD1P1(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_OK_VDD1P1_SHIFT)) & PMU_REG_1P1_TOG_OK_VDD1P1_MASK)

#define PMU_REG_1P1_TOG_ENABLE_WEAK_LINREG_MASK  (0x40000U)
#define PMU_REG_1P1_TOG_ENABLE_WEAK_LINREG_SHIFT (18U)
#define PMU_REG_1P1_TOG_ENABLE_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_TOG_ENABLE_WEAK_LINREG_MASK)

#define PMU_REG_1P1_TOG_SELREF_WEAK_LINREG_MASK  (0x80000U)
#define PMU_REG_1P1_TOG_SELREF_WEAK_LINREG_SHIFT (19U)
/*! SELREF_WEAK_LINREG
 *  0b0..Weak-linreg output tracks low-power-bandgap voltage
 *  0b1..Weak-linreg output tracks VDD_SOC_IN voltage
 */
#define PMU_REG_1P1_TOG_SELREF_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_1P1_TOG_SELREF_WEAK_LINREG_SHIFT)) & PMU_REG_1P1_TOG_SELREF_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_3P0 - Regulator 3P0 Register */
/*! @{ */

#define PMU_REG_3P0_ENABLE_LINREG_MASK           (0x1U)
#define PMU_REG_3P0_ENABLE_LINREG_SHIFT          (0U)
#define PMU_REG_3P0_ENABLE_LINREG(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_ENABLE_LINREG_SHIFT)) & PMU_REG_3P0_ENABLE_LINREG_MASK)

#define PMU_REG_3P0_ENABLE_BO_MASK               (0x2U)
#define PMU_REG_3P0_ENABLE_BO_SHIFT              (1U)
#define PMU_REG_3P0_ENABLE_BO(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_ENABLE_BO_SHIFT)) & PMU_REG_3P0_ENABLE_BO_MASK)

#define PMU_REG_3P0_ENABLE_ILIMIT_MASK           (0x4U)
#define PMU_REG_3P0_ENABLE_ILIMIT_SHIFT          (2U)
#define PMU_REG_3P0_ENABLE_ILIMIT(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_ENABLE_ILIMIT_SHIFT)) & PMU_REG_3P0_ENABLE_ILIMIT_MASK)

#define PMU_REG_3P0_BO_OFFSET_MASK               (0x70U)
#define PMU_REG_3P0_BO_OFFSET_SHIFT              (4U)
#define PMU_REG_3P0_BO_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_BO_OFFSET_SHIFT)) & PMU_REG_3P0_BO_OFFSET_MASK)

#define PMU_REG_3P0_VBUS_SEL_MASK                (0x80U)
#define PMU_REG_3P0_VBUS_SEL_SHIFT               (7U)
/*! VBUS_SEL
 *  0b0..Utilize VBUS OTG2 power
 *  0b1..Utilize VBUS OTG1 power
 */
#define PMU_REG_3P0_VBUS_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_VBUS_SEL_SHIFT)) & PMU_REG_3P0_VBUS_SEL_MASK)

#define PMU_REG_3P0_OUTPUT_TRG_MASK              (0x1F00U)
#define PMU_REG_3P0_OUTPUT_TRG_SHIFT             (8U)
/*! OUTPUT_TRG
 *  0b00000..2.625V
 *  0b01111..3.000V
 *  0b11111..3.400V
 */
#define PMU_REG_3P0_OUTPUT_TRG(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_OUTPUT_TRG_SHIFT)) & PMU_REG_3P0_OUTPUT_TRG_MASK)

#define PMU_REG_3P0_BO_VDD3P0_MASK               (0x10000U)
#define PMU_REG_3P0_BO_VDD3P0_SHIFT              (16U)
#define PMU_REG_3P0_BO_VDD3P0(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_BO_VDD3P0_SHIFT)) & PMU_REG_3P0_BO_VDD3P0_MASK)

#define PMU_REG_3P0_OK_VDD3P0_MASK               (0x20000U)
#define PMU_REG_3P0_OK_VDD3P0_SHIFT              (17U)
#define PMU_REG_3P0_OK_VDD3P0(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_OK_VDD3P0_SHIFT)) & PMU_REG_3P0_OK_VDD3P0_MASK)
/*! @} */

/*! @name REG_3P0_SET - Regulator 3P0 Register */
/*! @{ */

#define PMU_REG_3P0_SET_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_3P0_SET_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_3P0_SET_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_ENABLE_LINREG_SHIFT)) & PMU_REG_3P0_SET_ENABLE_LINREG_MASK)

#define PMU_REG_3P0_SET_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_3P0_SET_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_3P0_SET_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_ENABLE_BO_SHIFT)) & PMU_REG_3P0_SET_ENABLE_BO_MASK)

#define PMU_REG_3P0_SET_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_3P0_SET_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_3P0_SET_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_ENABLE_ILIMIT_SHIFT)) & PMU_REG_3P0_SET_ENABLE_ILIMIT_MASK)

#define PMU_REG_3P0_SET_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_3P0_SET_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_3P0_SET_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_BO_OFFSET_SHIFT)) & PMU_REG_3P0_SET_BO_OFFSET_MASK)

#define PMU_REG_3P0_SET_VBUS_SEL_MASK            (0x80U)
#define PMU_REG_3P0_SET_VBUS_SEL_SHIFT           (7U)
/*! VBUS_SEL
 *  0b0..Utilize VBUS OTG2 power
 *  0b1..Utilize VBUS OTG1 power
 */
#define PMU_REG_3P0_SET_VBUS_SEL(x)              (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_VBUS_SEL_SHIFT)) & PMU_REG_3P0_SET_VBUS_SEL_MASK)

#define PMU_REG_3P0_SET_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_3P0_SET_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b00000..2.625V
 *  0b01111..3.000V
 *  0b11111..3.400V
 */
#define PMU_REG_3P0_SET_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_OUTPUT_TRG_SHIFT)) & PMU_REG_3P0_SET_OUTPUT_TRG_MASK)

#define PMU_REG_3P0_SET_BO_VDD3P0_MASK           (0x10000U)
#define PMU_REG_3P0_SET_BO_VDD3P0_SHIFT          (16U)
#define PMU_REG_3P0_SET_BO_VDD3P0(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_BO_VDD3P0_SHIFT)) & PMU_REG_3P0_SET_BO_VDD3P0_MASK)

#define PMU_REG_3P0_SET_OK_VDD3P0_MASK           (0x20000U)
#define PMU_REG_3P0_SET_OK_VDD3P0_SHIFT          (17U)
#define PMU_REG_3P0_SET_OK_VDD3P0(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_SET_OK_VDD3P0_SHIFT)) & PMU_REG_3P0_SET_OK_VDD3P0_MASK)
/*! @} */

/*! @name REG_3P0_CLR - Regulator 3P0 Register */
/*! @{ */

#define PMU_REG_3P0_CLR_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_3P0_CLR_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_3P0_CLR_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_ENABLE_LINREG_SHIFT)) & PMU_REG_3P0_CLR_ENABLE_LINREG_MASK)

#define PMU_REG_3P0_CLR_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_3P0_CLR_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_3P0_CLR_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_ENABLE_BO_SHIFT)) & PMU_REG_3P0_CLR_ENABLE_BO_MASK)

#define PMU_REG_3P0_CLR_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_3P0_CLR_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_3P0_CLR_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_ENABLE_ILIMIT_SHIFT)) & PMU_REG_3P0_CLR_ENABLE_ILIMIT_MASK)

#define PMU_REG_3P0_CLR_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_3P0_CLR_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_3P0_CLR_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_BO_OFFSET_SHIFT)) & PMU_REG_3P0_CLR_BO_OFFSET_MASK)

#define PMU_REG_3P0_CLR_VBUS_SEL_MASK            (0x80U)
#define PMU_REG_3P0_CLR_VBUS_SEL_SHIFT           (7U)
/*! VBUS_SEL
 *  0b0..Utilize VBUS OTG2 power
 *  0b1..Utilize VBUS OTG1 power
 */
#define PMU_REG_3P0_CLR_VBUS_SEL(x)              (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_VBUS_SEL_SHIFT)) & PMU_REG_3P0_CLR_VBUS_SEL_MASK)

#define PMU_REG_3P0_CLR_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_3P0_CLR_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b00000..2.625V
 *  0b01111..3.000V
 *  0b11111..3.400V
 */
#define PMU_REG_3P0_CLR_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_OUTPUT_TRG_SHIFT)) & PMU_REG_3P0_CLR_OUTPUT_TRG_MASK)

#define PMU_REG_3P0_CLR_BO_VDD3P0_MASK           (0x10000U)
#define PMU_REG_3P0_CLR_BO_VDD3P0_SHIFT          (16U)
#define PMU_REG_3P0_CLR_BO_VDD3P0(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_BO_VDD3P0_SHIFT)) & PMU_REG_3P0_CLR_BO_VDD3P0_MASK)

#define PMU_REG_3P0_CLR_OK_VDD3P0_MASK           (0x20000U)
#define PMU_REG_3P0_CLR_OK_VDD3P0_SHIFT          (17U)
#define PMU_REG_3P0_CLR_OK_VDD3P0(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_CLR_OK_VDD3P0_SHIFT)) & PMU_REG_3P0_CLR_OK_VDD3P0_MASK)
/*! @} */

/*! @name REG_3P0_TOG - Regulator 3P0 Register */
/*! @{ */

#define PMU_REG_3P0_TOG_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_3P0_TOG_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_3P0_TOG_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_ENABLE_LINREG_SHIFT)) & PMU_REG_3P0_TOG_ENABLE_LINREG_MASK)

#define PMU_REG_3P0_TOG_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_3P0_TOG_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_3P0_TOG_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_ENABLE_BO_SHIFT)) & PMU_REG_3P0_TOG_ENABLE_BO_MASK)

#define PMU_REG_3P0_TOG_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_3P0_TOG_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_3P0_TOG_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_ENABLE_ILIMIT_SHIFT)) & PMU_REG_3P0_TOG_ENABLE_ILIMIT_MASK)

#define PMU_REG_3P0_TOG_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_3P0_TOG_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_3P0_TOG_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_BO_OFFSET_SHIFT)) & PMU_REG_3P0_TOG_BO_OFFSET_MASK)

#define PMU_REG_3P0_TOG_VBUS_SEL_MASK            (0x80U)
#define PMU_REG_3P0_TOG_VBUS_SEL_SHIFT           (7U)
/*! VBUS_SEL
 *  0b0..Utilize VBUS OTG2 power
 *  0b1..Utilize VBUS OTG1 power
 */
#define PMU_REG_3P0_TOG_VBUS_SEL(x)              (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_VBUS_SEL_SHIFT)) & PMU_REG_3P0_TOG_VBUS_SEL_MASK)

#define PMU_REG_3P0_TOG_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_3P0_TOG_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b00000..2.625V
 *  0b01111..3.000V
 *  0b11111..3.400V
 */
#define PMU_REG_3P0_TOG_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_OUTPUT_TRG_SHIFT)) & PMU_REG_3P0_TOG_OUTPUT_TRG_MASK)

#define PMU_REG_3P0_TOG_BO_VDD3P0_MASK           (0x10000U)
#define PMU_REG_3P0_TOG_BO_VDD3P0_SHIFT          (16U)
#define PMU_REG_3P0_TOG_BO_VDD3P0(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_BO_VDD3P0_SHIFT)) & PMU_REG_3P0_TOG_BO_VDD3P0_MASK)

#define PMU_REG_3P0_TOG_OK_VDD3P0_MASK           (0x20000U)
#define PMU_REG_3P0_TOG_OK_VDD3P0_SHIFT          (17U)
#define PMU_REG_3P0_TOG_OK_VDD3P0(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_3P0_TOG_OK_VDD3P0_SHIFT)) & PMU_REG_3P0_TOG_OK_VDD3P0_MASK)
/*! @} */

/*! @name REG_2P5 - Regulator 2P5 Register */
/*! @{ */

#define PMU_REG_2P5_ENABLE_LINREG_MASK           (0x1U)
#define PMU_REG_2P5_ENABLE_LINREG_SHIFT          (0U)
#define PMU_REG_2P5_ENABLE_LINREG(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_ENABLE_LINREG_SHIFT)) & PMU_REG_2P5_ENABLE_LINREG_MASK)

#define PMU_REG_2P5_ENABLE_BO_MASK               (0x2U)
#define PMU_REG_2P5_ENABLE_BO_SHIFT              (1U)
#define PMU_REG_2P5_ENABLE_BO(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_ENABLE_BO_SHIFT)) & PMU_REG_2P5_ENABLE_BO_MASK)

#define PMU_REG_2P5_ENABLE_ILIMIT_MASK           (0x4U)
#define PMU_REG_2P5_ENABLE_ILIMIT_SHIFT          (2U)
#define PMU_REG_2P5_ENABLE_ILIMIT(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_ENABLE_ILIMIT_SHIFT)) & PMU_REG_2P5_ENABLE_ILIMIT_MASK)

#define PMU_REG_2P5_ENABLE_PULLDOWN_MASK         (0x8U)
#define PMU_REG_2P5_ENABLE_PULLDOWN_SHIFT        (3U)
#define PMU_REG_2P5_ENABLE_PULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_2P5_ENABLE_PULLDOWN_MASK)

#define PMU_REG_2P5_BO_OFFSET_MASK               (0x70U)
#define PMU_REG_2P5_BO_OFFSET_SHIFT              (4U)
#define PMU_REG_2P5_BO_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_BO_OFFSET_SHIFT)) & PMU_REG_2P5_BO_OFFSET_MASK)

#define PMU_REG_2P5_OUTPUT_TRG_MASK              (0x1F00U)
#define PMU_REG_2P5_OUTPUT_TRG_SHIFT             (8U)
/*! OUTPUT_TRG
 *  0b00000..2.10V
 *  0b10000..2.50V
 *  0b11111..2.875V
 */
#define PMU_REG_2P5_OUTPUT_TRG(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_OUTPUT_TRG_SHIFT)) & PMU_REG_2P5_OUTPUT_TRG_MASK)

#define PMU_REG_2P5_BO_VDD2P5_MASK               (0x10000U)
#define PMU_REG_2P5_BO_VDD2P5_SHIFT              (16U)
#define PMU_REG_2P5_BO_VDD2P5(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_BO_VDD2P5_SHIFT)) & PMU_REG_2P5_BO_VDD2P5_MASK)

#define PMU_REG_2P5_OK_VDD2P5_MASK               (0x20000U)
#define PMU_REG_2P5_OK_VDD2P5_SHIFT              (17U)
#define PMU_REG_2P5_OK_VDD2P5(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_OK_VDD2P5_SHIFT)) & PMU_REG_2P5_OK_VDD2P5_MASK)

#define PMU_REG_2P5_ENABLE_WEAK_LINREG_MASK      (0x40000U)
#define PMU_REG_2P5_ENABLE_WEAK_LINREG_SHIFT     (18U)
#define PMU_REG_2P5_ENABLE_WEAK_LINREG(x)        (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_2P5_ENABLE_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_2P5_SET - Regulator 2P5 Register */
/*! @{ */

#define PMU_REG_2P5_SET_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_2P5_SET_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_2P5_SET_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_ENABLE_LINREG_SHIFT)) & PMU_REG_2P5_SET_ENABLE_LINREG_MASK)

#define PMU_REG_2P5_SET_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_2P5_SET_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_2P5_SET_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_ENABLE_BO_SHIFT)) & PMU_REG_2P5_SET_ENABLE_BO_MASK)

#define PMU_REG_2P5_SET_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_2P5_SET_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_2P5_SET_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_ENABLE_ILIMIT_SHIFT)) & PMU_REG_2P5_SET_ENABLE_ILIMIT_MASK)

#define PMU_REG_2P5_SET_ENABLE_PULLDOWN_MASK     (0x8U)
#define PMU_REG_2P5_SET_ENABLE_PULLDOWN_SHIFT    (3U)
#define PMU_REG_2P5_SET_ENABLE_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_2P5_SET_ENABLE_PULLDOWN_MASK)

#define PMU_REG_2P5_SET_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_2P5_SET_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_2P5_SET_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_BO_OFFSET_SHIFT)) & PMU_REG_2P5_SET_BO_OFFSET_MASK)

#define PMU_REG_2P5_SET_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_2P5_SET_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b00000..2.10V
 *  0b10000..2.50V
 *  0b11111..2.875V
 */
#define PMU_REG_2P5_SET_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_OUTPUT_TRG_SHIFT)) & PMU_REG_2P5_SET_OUTPUT_TRG_MASK)

#define PMU_REG_2P5_SET_BO_VDD2P5_MASK           (0x10000U)
#define PMU_REG_2P5_SET_BO_VDD2P5_SHIFT          (16U)
#define PMU_REG_2P5_SET_BO_VDD2P5(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_BO_VDD2P5_SHIFT)) & PMU_REG_2P5_SET_BO_VDD2P5_MASK)

#define PMU_REG_2P5_SET_OK_VDD2P5_MASK           (0x20000U)
#define PMU_REG_2P5_SET_OK_VDD2P5_SHIFT          (17U)
#define PMU_REG_2P5_SET_OK_VDD2P5(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_OK_VDD2P5_SHIFT)) & PMU_REG_2P5_SET_OK_VDD2P5_MASK)

#define PMU_REG_2P5_SET_ENABLE_WEAK_LINREG_MASK  (0x40000U)
#define PMU_REG_2P5_SET_ENABLE_WEAK_LINREG_SHIFT (18U)
#define PMU_REG_2P5_SET_ENABLE_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_SET_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_2P5_SET_ENABLE_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_2P5_CLR - Regulator 2P5 Register */
/*! @{ */

#define PMU_REG_2P5_CLR_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_2P5_CLR_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_2P5_CLR_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_ENABLE_LINREG_SHIFT)) & PMU_REG_2P5_CLR_ENABLE_LINREG_MASK)

#define PMU_REG_2P5_CLR_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_2P5_CLR_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_2P5_CLR_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_ENABLE_BO_SHIFT)) & PMU_REG_2P5_CLR_ENABLE_BO_MASK)

#define PMU_REG_2P5_CLR_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_2P5_CLR_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_2P5_CLR_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_ENABLE_ILIMIT_SHIFT)) & PMU_REG_2P5_CLR_ENABLE_ILIMIT_MASK)

#define PMU_REG_2P5_CLR_ENABLE_PULLDOWN_MASK     (0x8U)
#define PMU_REG_2P5_CLR_ENABLE_PULLDOWN_SHIFT    (3U)
#define PMU_REG_2P5_CLR_ENABLE_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_2P5_CLR_ENABLE_PULLDOWN_MASK)

#define PMU_REG_2P5_CLR_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_2P5_CLR_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_2P5_CLR_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_BO_OFFSET_SHIFT)) & PMU_REG_2P5_CLR_BO_OFFSET_MASK)

#define PMU_REG_2P5_CLR_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_2P5_CLR_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b00000..2.10V
 *  0b10000..2.50V
 *  0b11111..2.875V
 */
#define PMU_REG_2P5_CLR_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_OUTPUT_TRG_SHIFT)) & PMU_REG_2P5_CLR_OUTPUT_TRG_MASK)

#define PMU_REG_2P5_CLR_BO_VDD2P5_MASK           (0x10000U)
#define PMU_REG_2P5_CLR_BO_VDD2P5_SHIFT          (16U)
#define PMU_REG_2P5_CLR_BO_VDD2P5(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_BO_VDD2P5_SHIFT)) & PMU_REG_2P5_CLR_BO_VDD2P5_MASK)

#define PMU_REG_2P5_CLR_OK_VDD2P5_MASK           (0x20000U)
#define PMU_REG_2P5_CLR_OK_VDD2P5_SHIFT          (17U)
#define PMU_REG_2P5_CLR_OK_VDD2P5(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_OK_VDD2P5_SHIFT)) & PMU_REG_2P5_CLR_OK_VDD2P5_MASK)

#define PMU_REG_2P5_CLR_ENABLE_WEAK_LINREG_MASK  (0x40000U)
#define PMU_REG_2P5_CLR_ENABLE_WEAK_LINREG_SHIFT (18U)
#define PMU_REG_2P5_CLR_ENABLE_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_CLR_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_2P5_CLR_ENABLE_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_2P5_TOG - Regulator 2P5 Register */
/*! @{ */

#define PMU_REG_2P5_TOG_ENABLE_LINREG_MASK       (0x1U)
#define PMU_REG_2P5_TOG_ENABLE_LINREG_SHIFT      (0U)
#define PMU_REG_2P5_TOG_ENABLE_LINREG(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_ENABLE_LINREG_SHIFT)) & PMU_REG_2P5_TOG_ENABLE_LINREG_MASK)

#define PMU_REG_2P5_TOG_ENABLE_BO_MASK           (0x2U)
#define PMU_REG_2P5_TOG_ENABLE_BO_SHIFT          (1U)
#define PMU_REG_2P5_TOG_ENABLE_BO(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_ENABLE_BO_SHIFT)) & PMU_REG_2P5_TOG_ENABLE_BO_MASK)

#define PMU_REG_2P5_TOG_ENABLE_ILIMIT_MASK       (0x4U)
#define PMU_REG_2P5_TOG_ENABLE_ILIMIT_SHIFT      (2U)
#define PMU_REG_2P5_TOG_ENABLE_ILIMIT(x)         (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_ENABLE_ILIMIT_SHIFT)) & PMU_REG_2P5_TOG_ENABLE_ILIMIT_MASK)

#define PMU_REG_2P5_TOG_ENABLE_PULLDOWN_MASK     (0x8U)
#define PMU_REG_2P5_TOG_ENABLE_PULLDOWN_SHIFT    (3U)
#define PMU_REG_2P5_TOG_ENABLE_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_ENABLE_PULLDOWN_SHIFT)) & PMU_REG_2P5_TOG_ENABLE_PULLDOWN_MASK)

#define PMU_REG_2P5_TOG_BO_OFFSET_MASK           (0x70U)
#define PMU_REG_2P5_TOG_BO_OFFSET_SHIFT          (4U)
#define PMU_REG_2P5_TOG_BO_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_BO_OFFSET_SHIFT)) & PMU_REG_2P5_TOG_BO_OFFSET_MASK)

#define PMU_REG_2P5_TOG_OUTPUT_TRG_MASK          (0x1F00U)
#define PMU_REG_2P5_TOG_OUTPUT_TRG_SHIFT         (8U)
/*! OUTPUT_TRG
 *  0b00000..2.10V
 *  0b10000..2.50V
 *  0b11111..2.875V
 */
#define PMU_REG_2P5_TOG_OUTPUT_TRG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_OUTPUT_TRG_SHIFT)) & PMU_REG_2P5_TOG_OUTPUT_TRG_MASK)

#define PMU_REG_2P5_TOG_BO_VDD2P5_MASK           (0x10000U)
#define PMU_REG_2P5_TOG_BO_VDD2P5_SHIFT          (16U)
#define PMU_REG_2P5_TOG_BO_VDD2P5(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_BO_VDD2P5_SHIFT)) & PMU_REG_2P5_TOG_BO_VDD2P5_MASK)

#define PMU_REG_2P5_TOG_OK_VDD2P5_MASK           (0x20000U)
#define PMU_REG_2P5_TOG_OK_VDD2P5_SHIFT          (17U)
#define PMU_REG_2P5_TOG_OK_VDD2P5(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_OK_VDD2P5_SHIFT)) & PMU_REG_2P5_TOG_OK_VDD2P5_MASK)

#define PMU_REG_2P5_TOG_ENABLE_WEAK_LINREG_MASK  (0x40000U)
#define PMU_REG_2P5_TOG_ENABLE_WEAK_LINREG_SHIFT (18U)
#define PMU_REG_2P5_TOG_ENABLE_WEAK_LINREG(x)    (((uint32_t)(((uint32_t)(x)) << PMU_REG_2P5_TOG_ENABLE_WEAK_LINREG_SHIFT)) & PMU_REG_2P5_TOG_ENABLE_WEAK_LINREG_MASK)
/*! @} */

/*! @name REG_CORE - Digital Regulator Core Register */
/*! @{ */

#define PMU_REG_CORE_REG0_TARG_MASK              (0x1FU)
#define PMU_REG_CORE_REG0_TARG_SHIFT             (0U)
/*! REG0_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_REG0_TARG(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_REG0_TARG_SHIFT)) & PMU_REG_CORE_REG0_TARG_MASK)

#define PMU_REG_CORE_REG0_ADJ_MASK               (0x1E0U)
#define PMU_REG_CORE_REG0_ADJ_SHIFT              (5U)
/*! REG0_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg0. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_REG0_ADJ(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_REG0_ADJ_SHIFT)) & PMU_REG_CORE_REG0_ADJ_MASK)

#define PMU_REG_CORE_REG1_TARG_MASK              (0x3E00U)
#define PMU_REG_CORE_REG1_TARG_SHIFT             (9U)
/*! REG1_TARG - This bit field defines the target voltage for the vpu/gpu power domain. Single bit
 *    increments reflect 25mV core voltage steps. Not all steps will make sense to use either because
 *    of input supply limitations or load operation.
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_REG1_TARG(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_REG1_TARG_SHIFT)) & PMU_REG_CORE_REG1_TARG_MASK)

#define PMU_REG_CORE_REG1_ADJ_MASK               (0x3C000U)
#define PMU_REG_CORE_REG1_ADJ_SHIFT              (14U)
/*! REG1_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg1. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_REG1_ADJ(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_REG1_ADJ_SHIFT)) & PMU_REG_CORE_REG1_ADJ_MASK)

#define PMU_REG_CORE_REG2_TARG_MASK              (0x7C0000U)
#define PMU_REG_CORE_REG2_TARG_SHIFT             (18U)
/*! REG2_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_REG2_TARG(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_REG2_TARG_SHIFT)) & PMU_REG_CORE_REG2_TARG_MASK)

#define PMU_REG_CORE_REG2_ADJ_MASK               (0x7800000U)
#define PMU_REG_CORE_REG2_ADJ_SHIFT              (23U)
/*! REG2_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg2. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_REG2_ADJ(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_REG2_ADJ_SHIFT)) & PMU_REG_CORE_REG2_ADJ_MASK)

#define PMU_REG_CORE_RAMP_RATE_MASK              (0x18000000U)
#define PMU_REG_CORE_RAMP_RATE_SHIFT             (27U)
/*! RAMP_RATE
 *  0b00..Fast
 *  0b01..Medium Fast
 *  0b10..Medium Slow
 *  0b11..Slow
 */
#define PMU_REG_CORE_RAMP_RATE(x)                (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_RAMP_RATE_SHIFT)) & PMU_REG_CORE_RAMP_RATE_MASK)

#define PMU_REG_CORE_FET_ODRIVE_MASK             (0x20000000U)
#define PMU_REG_CORE_FET_ODRIVE_SHIFT            (29U)
#define PMU_REG_CORE_FET_ODRIVE(x)               (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_FET_ODRIVE_SHIFT)) & PMU_REG_CORE_FET_ODRIVE_MASK)
/*! @} */

/*! @name REG_CORE_SET - Digital Regulator Core Register */
/*! @{ */

#define PMU_REG_CORE_SET_REG0_TARG_MASK          (0x1FU)
#define PMU_REG_CORE_SET_REG0_TARG_SHIFT         (0U)
/*! REG0_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_SET_REG0_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_REG0_TARG_SHIFT)) & PMU_REG_CORE_SET_REG0_TARG_MASK)

#define PMU_REG_CORE_SET_REG0_ADJ_MASK           (0x1E0U)
#define PMU_REG_CORE_SET_REG0_ADJ_SHIFT          (5U)
/*! REG0_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg0. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_SET_REG0_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_REG0_ADJ_SHIFT)) & PMU_REG_CORE_SET_REG0_ADJ_MASK)

#define PMU_REG_CORE_SET_REG1_TARG_MASK          (0x3E00U)
#define PMU_REG_CORE_SET_REG1_TARG_SHIFT         (9U)
/*! REG1_TARG - This bit field defines the target voltage for the vpu/gpu power domain. Single bit
 *    increments reflect 25mV core voltage steps. Not all steps will make sense to use either because
 *    of input supply limitations or load operation.
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_SET_REG1_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_REG1_TARG_SHIFT)) & PMU_REG_CORE_SET_REG1_TARG_MASK)

#define PMU_REG_CORE_SET_REG1_ADJ_MASK           (0x3C000U)
#define PMU_REG_CORE_SET_REG1_ADJ_SHIFT          (14U)
/*! REG1_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg1. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_SET_REG1_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_REG1_ADJ_SHIFT)) & PMU_REG_CORE_SET_REG1_ADJ_MASK)

#define PMU_REG_CORE_SET_REG2_TARG_MASK          (0x7C0000U)
#define PMU_REG_CORE_SET_REG2_TARG_SHIFT         (18U)
/*! REG2_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_SET_REG2_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_REG2_TARG_SHIFT)) & PMU_REG_CORE_SET_REG2_TARG_MASK)

#define PMU_REG_CORE_SET_REG2_ADJ_MASK           (0x7800000U)
#define PMU_REG_CORE_SET_REG2_ADJ_SHIFT          (23U)
/*! REG2_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg2. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_SET_REG2_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_REG2_ADJ_SHIFT)) & PMU_REG_CORE_SET_REG2_ADJ_MASK)

#define PMU_REG_CORE_SET_RAMP_RATE_MASK          (0x18000000U)
#define PMU_REG_CORE_SET_RAMP_RATE_SHIFT         (27U)
/*! RAMP_RATE
 *  0b00..Fast
 *  0b01..Medium Fast
 *  0b10..Medium Slow
 *  0b11..Slow
 */
#define PMU_REG_CORE_SET_RAMP_RATE(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_RAMP_RATE_SHIFT)) & PMU_REG_CORE_SET_RAMP_RATE_MASK)

#define PMU_REG_CORE_SET_FET_ODRIVE_MASK         (0x20000000U)
#define PMU_REG_CORE_SET_FET_ODRIVE_SHIFT        (29U)
#define PMU_REG_CORE_SET_FET_ODRIVE(x)           (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_SET_FET_ODRIVE_SHIFT)) & PMU_REG_CORE_SET_FET_ODRIVE_MASK)
/*! @} */

/*! @name REG_CORE_CLR - Digital Regulator Core Register */
/*! @{ */

#define PMU_REG_CORE_CLR_REG0_TARG_MASK          (0x1FU)
#define PMU_REG_CORE_CLR_REG0_TARG_SHIFT         (0U)
/*! REG0_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_CLR_REG0_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_REG0_TARG_SHIFT)) & PMU_REG_CORE_CLR_REG0_TARG_MASK)

#define PMU_REG_CORE_CLR_REG0_ADJ_MASK           (0x1E0U)
#define PMU_REG_CORE_CLR_REG0_ADJ_SHIFT          (5U)
/*! REG0_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg0. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_CLR_REG0_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_REG0_ADJ_SHIFT)) & PMU_REG_CORE_CLR_REG0_ADJ_MASK)

#define PMU_REG_CORE_CLR_REG1_TARG_MASK          (0x3E00U)
#define PMU_REG_CORE_CLR_REG1_TARG_SHIFT         (9U)
/*! REG1_TARG - This bit field defines the target voltage for the vpu/gpu power domain. Single bit
 *    increments reflect 25mV core voltage steps. Not all steps will make sense to use either because
 *    of input supply limitations or load operation.
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_CLR_REG1_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_REG1_TARG_SHIFT)) & PMU_REG_CORE_CLR_REG1_TARG_MASK)

#define PMU_REG_CORE_CLR_REG1_ADJ_MASK           (0x3C000U)
#define PMU_REG_CORE_CLR_REG1_ADJ_SHIFT          (14U)
/*! REG1_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg1. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_CLR_REG1_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_REG1_ADJ_SHIFT)) & PMU_REG_CORE_CLR_REG1_ADJ_MASK)

#define PMU_REG_CORE_CLR_REG2_TARG_MASK          (0x7C0000U)
#define PMU_REG_CORE_CLR_REG2_TARG_SHIFT         (18U)
/*! REG2_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_CLR_REG2_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_REG2_TARG_SHIFT)) & PMU_REG_CORE_CLR_REG2_TARG_MASK)

#define PMU_REG_CORE_CLR_REG2_ADJ_MASK           (0x7800000U)
#define PMU_REG_CORE_CLR_REG2_ADJ_SHIFT          (23U)
/*! REG2_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg2. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_CLR_REG2_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_REG2_ADJ_SHIFT)) & PMU_REG_CORE_CLR_REG2_ADJ_MASK)

#define PMU_REG_CORE_CLR_RAMP_RATE_MASK          (0x18000000U)
#define PMU_REG_CORE_CLR_RAMP_RATE_SHIFT         (27U)
/*! RAMP_RATE
 *  0b00..Fast
 *  0b01..Medium Fast
 *  0b10..Medium Slow
 *  0b11..Slow
 */
#define PMU_REG_CORE_CLR_RAMP_RATE(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_RAMP_RATE_SHIFT)) & PMU_REG_CORE_CLR_RAMP_RATE_MASK)

#define PMU_REG_CORE_CLR_FET_ODRIVE_MASK         (0x20000000U)
#define PMU_REG_CORE_CLR_FET_ODRIVE_SHIFT        (29U)
#define PMU_REG_CORE_CLR_FET_ODRIVE(x)           (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_CLR_FET_ODRIVE_SHIFT)) & PMU_REG_CORE_CLR_FET_ODRIVE_MASK)
/*! @} */

/*! @name REG_CORE_TOG - Digital Regulator Core Register */
/*! @{ */

#define PMU_REG_CORE_TOG_REG0_TARG_MASK          (0x1FU)
#define PMU_REG_CORE_TOG_REG0_TARG_SHIFT         (0U)
/*! REG0_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_TOG_REG0_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_REG0_TARG_SHIFT)) & PMU_REG_CORE_TOG_REG0_TARG_MASK)

#define PMU_REG_CORE_TOG_REG0_ADJ_MASK           (0x1E0U)
#define PMU_REG_CORE_TOG_REG0_ADJ_SHIFT          (5U)
/*! REG0_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg0. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_TOG_REG0_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_REG0_ADJ_SHIFT)) & PMU_REG_CORE_TOG_REG0_ADJ_MASK)

#define PMU_REG_CORE_TOG_REG1_TARG_MASK          (0x3E00U)
#define PMU_REG_CORE_TOG_REG1_TARG_SHIFT         (9U)
/*! REG1_TARG - This bit field defines the target voltage for the vpu/gpu power domain. Single bit
 *    increments reflect 25mV core voltage steps. Not all steps will make sense to use either because
 *    of input supply limitations or load operation.
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_TOG_REG1_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_REG1_TARG_SHIFT)) & PMU_REG_CORE_TOG_REG1_TARG_MASK)

#define PMU_REG_CORE_TOG_REG1_ADJ_MASK           (0x3C000U)
#define PMU_REG_CORE_TOG_REG1_ADJ_SHIFT          (14U)
/*! REG1_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg1. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_TOG_REG1_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_REG1_ADJ_SHIFT)) & PMU_REG_CORE_TOG_REG1_ADJ_MASK)

#define PMU_REG_CORE_TOG_REG2_TARG_MASK          (0x7C0000U)
#define PMU_REG_CORE_TOG_REG2_TARG_SHIFT         (18U)
/*! REG2_TARG
 *  0b00000..Power gated off
 *  0b00001..Target core voltage = 0.725V
 *  0b00010..Target core voltage = 0.750V
 *  0b00011..Target core voltage = 0.775V
 *  0b10000..Target core voltage = 1.100V
 *  0b11110..Target core voltage = 1.450V
 *  0b11111..Power FET switched full on. No regulation.
 */
#define PMU_REG_CORE_TOG_REG2_TARG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_REG2_TARG_SHIFT)) & PMU_REG_CORE_TOG_REG2_TARG_MASK)

#define PMU_REG_CORE_TOG_REG2_ADJ_MASK           (0x7800000U)
#define PMU_REG_CORE_TOG_REG2_ADJ_SHIFT          (23U)
/*! REG2_ADJ - This bit field defines the adjustment bits to calibrate the target value of Reg2. The
 *    adjustment is applied on top on any adjustment applied to the global reference in the misc0
 *    register.
 *  0b0000..No adjustment
 *  0b0001..+ 0.25%
 *  0b0010..+ 0.50%
 *  0b0011..+ 0.75%
 *  0b0100..+ 1.00%
 *  0b0101..+ 1.25%
 *  0b0110..+ 1.50%
 *  0b0111..+ 1.75%
 *  0b1000..- 0.25%
 *  0b1001..- 0.50%
 *  0b1010..- 0.75%
 *  0b1011..- 1.00%
 *  0b1100..- 1.25%
 *  0b1101..- 1.50%
 *  0b1110..- 1.75%
 *  0b1111..- 2.00%
 */
#define PMU_REG_CORE_TOG_REG2_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_REG2_ADJ_SHIFT)) & PMU_REG_CORE_TOG_REG2_ADJ_MASK)

#define PMU_REG_CORE_TOG_RAMP_RATE_MASK          (0x18000000U)
#define PMU_REG_CORE_TOG_RAMP_RATE_SHIFT         (27U)
/*! RAMP_RATE
 *  0b00..Fast
 *  0b01..Medium Fast
 *  0b10..Medium Slow
 *  0b11..Slow
 */
#define PMU_REG_CORE_TOG_RAMP_RATE(x)            (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_RAMP_RATE_SHIFT)) & PMU_REG_CORE_TOG_RAMP_RATE_MASK)

#define PMU_REG_CORE_TOG_FET_ODRIVE_MASK         (0x20000000U)
#define PMU_REG_CORE_TOG_FET_ODRIVE_SHIFT        (29U)
#define PMU_REG_CORE_TOG_FET_ODRIVE(x)           (((uint32_t)(((uint32_t)(x)) << PMU_REG_CORE_TOG_FET_ODRIVE_SHIFT)) & PMU_REG_CORE_TOG_FET_ODRIVE_MASK)
/*! @} */

/*! @name MISC0 - Miscellaneous Register 0 */
/*! @{ */

#define PMU_MISC0_REFTOP_PWD_MASK                (0x1U)
#define PMU_MISC0_REFTOP_PWD_SHIFT               (0U)
#define PMU_MISC0_REFTOP_PWD(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_REFTOP_PWD_SHIFT)) & PMU_MISC0_REFTOP_PWD_MASK)

#define PMU_MISC0_REFTOP_PWDVBGUP_MASK           (0x2U)
#define PMU_MISC0_REFTOP_PWDVBGUP_SHIFT          (1U)
#define PMU_MISC0_REFTOP_PWDVBGUP(x)             (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_REFTOP_PWDVBGUP_SHIFT)) & PMU_MISC0_REFTOP_PWDVBGUP_MASK)

#define PMU_MISC0_REFTOP_LOWPOWER_MASK           (0x4U)
#define PMU_MISC0_REFTOP_LOWPOWER_SHIFT          (2U)
#define PMU_MISC0_REFTOP_LOWPOWER(x)             (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_REFTOP_LOWPOWER_SHIFT)) & PMU_MISC0_REFTOP_LOWPOWER_MASK)

#define PMU_MISC0_REFTOP_SELFBIASOFF_MASK        (0x8U)
#define PMU_MISC0_REFTOP_SELFBIASOFF_SHIFT       (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define PMU_MISC0_REFTOP_SELFBIASOFF(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_REFTOP_SELFBIASOFF_SHIFT)) & PMU_MISC0_REFTOP_SELFBIASOFF_MASK)

#define PMU_MISC0_REFTOP_VBGADJ_MASK             (0x70U)
#define PMU_MISC0_REFTOP_VBGADJ_SHIFT            (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define PMU_MISC0_REFTOP_VBGADJ(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_REFTOP_VBGADJ_SHIFT)) & PMU_MISC0_REFTOP_VBGADJ_MASK)

#define PMU_MISC0_REFTOP_VBGUP_MASK              (0x80U)
#define PMU_MISC0_REFTOP_VBGUP_SHIFT             (7U)
#define PMU_MISC0_REFTOP_VBGUP(x)                (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_REFTOP_VBGUP_SHIFT)) & PMU_MISC0_REFTOP_VBGUP_MASK)

#define PMU_MISC0_STOP_MODE_CONFIG_MASK          (0xC00U)
#define PMU_MISC0_STOP_MODE_CONFIG_SHIFT         (10U)
/*! STOP_MODE_CONFIG
 *  0b00..SUSPEND (DSM)
 *  0b01..Analog regulators are ON.
 *  0b10..STOP (lower power)
 *  0b11..STOP (very lower power)
 */
#define PMU_MISC0_STOP_MODE_CONFIG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_STOP_MODE_CONFIG_SHIFT)) & PMU_MISC0_STOP_MODE_CONFIG_MASK)

#define PMU_MISC0_DISCON_HIGH_SNVS_MASK          (0x1000U)
#define PMU_MISC0_DISCON_HIGH_SNVS_SHIFT         (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define PMU_MISC0_DISCON_HIGH_SNVS(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_DISCON_HIGH_SNVS_SHIFT)) & PMU_MISC0_DISCON_HIGH_SNVS_MASK)

#define PMU_MISC0_OSC_I_MASK                     (0x6000U)
#define PMU_MISC0_OSC_I_SHIFT                    (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define PMU_MISC0_OSC_I(x)                       (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_OSC_I_SHIFT)) & PMU_MISC0_OSC_I_MASK)

#define PMU_MISC0_OSC_XTALOK_MASK                (0x8000U)
#define PMU_MISC0_OSC_XTALOK_SHIFT               (15U)
#define PMU_MISC0_OSC_XTALOK(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_OSC_XTALOK_SHIFT)) & PMU_MISC0_OSC_XTALOK_MASK)

#define PMU_MISC0_OSC_XTALOK_EN_MASK             (0x10000U)
#define PMU_MISC0_OSC_XTALOK_EN_SHIFT            (16U)
#define PMU_MISC0_OSC_XTALOK_EN(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_OSC_XTALOK_EN_SHIFT)) & PMU_MISC0_OSC_XTALOK_EN_MASK)

#define PMU_MISC0_CLKGATE_CTRL_MASK              (0x2000000U)
#define PMU_MISC0_CLKGATE_CTRL_SHIFT             (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define PMU_MISC0_CLKGATE_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLKGATE_CTRL_SHIFT)) & PMU_MISC0_CLKGATE_CTRL_MASK)

#define PMU_MISC0_CLKGATE_DELAY_MASK             (0x1C000000U)
#define PMU_MISC0_CLKGATE_DELAY_SHIFT            (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define PMU_MISC0_CLKGATE_DELAY(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLKGATE_DELAY_SHIFT)) & PMU_MISC0_CLKGATE_DELAY_MASK)

#define PMU_MISC0_RTC_XTAL_SOURCE_MASK           (0x20000000U)
#define PMU_MISC0_RTC_XTAL_SOURCE_SHIFT          (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define PMU_MISC0_RTC_XTAL_SOURCE(x)             (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_RTC_XTAL_SOURCE_SHIFT)) & PMU_MISC0_RTC_XTAL_SOURCE_MASK)

#define PMU_MISC0_XTAL_24M_PWD_MASK              (0x40000000U)
#define PMU_MISC0_XTAL_24M_PWD_SHIFT             (30U)
#define PMU_MISC0_XTAL_24M_PWD(x)                (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_XTAL_24M_PWD_SHIFT)) & PMU_MISC0_XTAL_24M_PWD_MASK)

#define PMU_MISC0_VID_PLL_PREDIV_MASK            (0x80000000U)
#define PMU_MISC0_VID_PLL_PREDIV_SHIFT           (31U)
/*! VID_PLL_PREDIV
 *  0b0..Divide by 1
 *  0b1..Divide by 2
 */
#define PMU_MISC0_VID_PLL_PREDIV(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_VID_PLL_PREDIV_SHIFT)) & PMU_MISC0_VID_PLL_PREDIV_MASK)
/*! @} */

/*! @name MISC0_SET - Miscellaneous Register 0 */
/*! @{ */

#define PMU_MISC0_SET_REFTOP_PWD_MASK            (0x1U)
#define PMU_MISC0_SET_REFTOP_PWD_SHIFT           (0U)
#define PMU_MISC0_SET_REFTOP_PWD(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_REFTOP_PWD_SHIFT)) & PMU_MISC0_SET_REFTOP_PWD_MASK)

#define PMU_MISC0_SET_REFTOP_PWDVBGUP_MASK       (0x2U)
#define PMU_MISC0_SET_REFTOP_PWDVBGUP_SHIFT      (1U)
#define PMU_MISC0_SET_REFTOP_PWDVBGUP(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_REFTOP_PWDVBGUP_SHIFT)) & PMU_MISC0_SET_REFTOP_PWDVBGUP_MASK)

#define PMU_MISC0_SET_REFTOP_LOWPOWER_MASK       (0x4U)
#define PMU_MISC0_SET_REFTOP_LOWPOWER_SHIFT      (2U)
#define PMU_MISC0_SET_REFTOP_LOWPOWER(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_REFTOP_LOWPOWER_SHIFT)) & PMU_MISC0_SET_REFTOP_LOWPOWER_MASK)

#define PMU_MISC0_SET_REFTOP_SELFBIASOFF_MASK    (0x8U)
#define PMU_MISC0_SET_REFTOP_SELFBIASOFF_SHIFT   (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define PMU_MISC0_SET_REFTOP_SELFBIASOFF(x)      (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_REFTOP_SELFBIASOFF_SHIFT)) & PMU_MISC0_SET_REFTOP_SELFBIASOFF_MASK)

#define PMU_MISC0_SET_REFTOP_VBGADJ_MASK         (0x70U)
#define PMU_MISC0_SET_REFTOP_VBGADJ_SHIFT        (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define PMU_MISC0_SET_REFTOP_VBGADJ(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_REFTOP_VBGADJ_SHIFT)) & PMU_MISC0_SET_REFTOP_VBGADJ_MASK)

#define PMU_MISC0_SET_REFTOP_VBGUP_MASK          (0x80U)
#define PMU_MISC0_SET_REFTOP_VBGUP_SHIFT         (7U)
#define PMU_MISC0_SET_REFTOP_VBGUP(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_REFTOP_VBGUP_SHIFT)) & PMU_MISC0_SET_REFTOP_VBGUP_MASK)

#define PMU_MISC0_SET_STOP_MODE_CONFIG_MASK      (0xC00U)
#define PMU_MISC0_SET_STOP_MODE_CONFIG_SHIFT     (10U)
/*! STOP_MODE_CONFIG
 *  0b00..SUSPEND (DSM)
 *  0b01..Analog regulators are ON.
 *  0b10..STOP (lower power)
 *  0b11..STOP (very lower power)
 */
#define PMU_MISC0_SET_STOP_MODE_CONFIG(x)        (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_STOP_MODE_CONFIG_SHIFT)) & PMU_MISC0_SET_STOP_MODE_CONFIG_MASK)

#define PMU_MISC0_SET_DISCON_HIGH_SNVS_MASK      (0x1000U)
#define PMU_MISC0_SET_DISCON_HIGH_SNVS_SHIFT     (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define PMU_MISC0_SET_DISCON_HIGH_SNVS(x)        (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_DISCON_HIGH_SNVS_SHIFT)) & PMU_MISC0_SET_DISCON_HIGH_SNVS_MASK)

#define PMU_MISC0_SET_OSC_I_MASK                 (0x6000U)
#define PMU_MISC0_SET_OSC_I_SHIFT                (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define PMU_MISC0_SET_OSC_I(x)                   (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_OSC_I_SHIFT)) & PMU_MISC0_SET_OSC_I_MASK)

#define PMU_MISC0_SET_OSC_XTALOK_MASK            (0x8000U)
#define PMU_MISC0_SET_OSC_XTALOK_SHIFT           (15U)
#define PMU_MISC0_SET_OSC_XTALOK(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_OSC_XTALOK_SHIFT)) & PMU_MISC0_SET_OSC_XTALOK_MASK)

#define PMU_MISC0_SET_OSC_XTALOK_EN_MASK         (0x10000U)
#define PMU_MISC0_SET_OSC_XTALOK_EN_SHIFT        (16U)
#define PMU_MISC0_SET_OSC_XTALOK_EN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_OSC_XTALOK_EN_SHIFT)) & PMU_MISC0_SET_OSC_XTALOK_EN_MASK)

#define PMU_MISC0_SET_CLKGATE_CTRL_MASK          (0x2000000U)
#define PMU_MISC0_SET_CLKGATE_CTRL_SHIFT         (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define PMU_MISC0_SET_CLKGATE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_CLKGATE_CTRL_SHIFT)) & PMU_MISC0_SET_CLKGATE_CTRL_MASK)

#define PMU_MISC0_SET_CLKGATE_DELAY_MASK         (0x1C000000U)
#define PMU_MISC0_SET_CLKGATE_DELAY_SHIFT        (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define PMU_MISC0_SET_CLKGATE_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_CLKGATE_DELAY_SHIFT)) & PMU_MISC0_SET_CLKGATE_DELAY_MASK)

#define PMU_MISC0_SET_RTC_XTAL_SOURCE_MASK       (0x20000000U)
#define PMU_MISC0_SET_RTC_XTAL_SOURCE_SHIFT      (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define PMU_MISC0_SET_RTC_XTAL_SOURCE(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_RTC_XTAL_SOURCE_SHIFT)) & PMU_MISC0_SET_RTC_XTAL_SOURCE_MASK)

#define PMU_MISC0_SET_XTAL_24M_PWD_MASK          (0x40000000U)
#define PMU_MISC0_SET_XTAL_24M_PWD_SHIFT         (30U)
#define PMU_MISC0_SET_XTAL_24M_PWD(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_XTAL_24M_PWD_SHIFT)) & PMU_MISC0_SET_XTAL_24M_PWD_MASK)

#define PMU_MISC0_SET_VID_PLL_PREDIV_MASK        (0x80000000U)
#define PMU_MISC0_SET_VID_PLL_PREDIV_SHIFT       (31U)
/*! VID_PLL_PREDIV
 *  0b0..Divide by 1
 *  0b1..Divide by 2
 */
#define PMU_MISC0_SET_VID_PLL_PREDIV(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_SET_VID_PLL_PREDIV_SHIFT)) & PMU_MISC0_SET_VID_PLL_PREDIV_MASK)
/*! @} */

/*! @name MISC0_CLR - Miscellaneous Register 0 */
/*! @{ */

#define PMU_MISC0_CLR_REFTOP_PWD_MASK            (0x1U)
#define PMU_MISC0_CLR_REFTOP_PWD_SHIFT           (0U)
#define PMU_MISC0_CLR_REFTOP_PWD(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_REFTOP_PWD_SHIFT)) & PMU_MISC0_CLR_REFTOP_PWD_MASK)

#define PMU_MISC0_CLR_REFTOP_PWDVBGUP_MASK       (0x2U)
#define PMU_MISC0_CLR_REFTOP_PWDVBGUP_SHIFT      (1U)
#define PMU_MISC0_CLR_REFTOP_PWDVBGUP(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_REFTOP_PWDVBGUP_SHIFT)) & PMU_MISC0_CLR_REFTOP_PWDVBGUP_MASK)

#define PMU_MISC0_CLR_REFTOP_LOWPOWER_MASK       (0x4U)
#define PMU_MISC0_CLR_REFTOP_LOWPOWER_SHIFT      (2U)
#define PMU_MISC0_CLR_REFTOP_LOWPOWER(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_REFTOP_LOWPOWER_SHIFT)) & PMU_MISC0_CLR_REFTOP_LOWPOWER_MASK)

#define PMU_MISC0_CLR_REFTOP_SELFBIASOFF_MASK    (0x8U)
#define PMU_MISC0_CLR_REFTOP_SELFBIASOFF_SHIFT   (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define PMU_MISC0_CLR_REFTOP_SELFBIASOFF(x)      (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_REFTOP_SELFBIASOFF_SHIFT)) & PMU_MISC0_CLR_REFTOP_SELFBIASOFF_MASK)

#define PMU_MISC0_CLR_REFTOP_VBGADJ_MASK         (0x70U)
#define PMU_MISC0_CLR_REFTOP_VBGADJ_SHIFT        (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define PMU_MISC0_CLR_REFTOP_VBGADJ(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_REFTOP_VBGADJ_SHIFT)) & PMU_MISC0_CLR_REFTOP_VBGADJ_MASK)

#define PMU_MISC0_CLR_REFTOP_VBGUP_MASK          (0x80U)
#define PMU_MISC0_CLR_REFTOP_VBGUP_SHIFT         (7U)
#define PMU_MISC0_CLR_REFTOP_VBGUP(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_REFTOP_VBGUP_SHIFT)) & PMU_MISC0_CLR_REFTOP_VBGUP_MASK)

#define PMU_MISC0_CLR_STOP_MODE_CONFIG_MASK      (0xC00U)
#define PMU_MISC0_CLR_STOP_MODE_CONFIG_SHIFT     (10U)
/*! STOP_MODE_CONFIG
 *  0b00..SUSPEND (DSM)
 *  0b01..Analog regulators are ON.
 *  0b10..STOP (lower power)
 *  0b11..STOP (very lower power)
 */
#define PMU_MISC0_CLR_STOP_MODE_CONFIG(x)        (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_STOP_MODE_CONFIG_SHIFT)) & PMU_MISC0_CLR_STOP_MODE_CONFIG_MASK)

#define PMU_MISC0_CLR_DISCON_HIGH_SNVS_MASK      (0x1000U)
#define PMU_MISC0_CLR_DISCON_HIGH_SNVS_SHIFT     (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define PMU_MISC0_CLR_DISCON_HIGH_SNVS(x)        (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_DISCON_HIGH_SNVS_SHIFT)) & PMU_MISC0_CLR_DISCON_HIGH_SNVS_MASK)

#define PMU_MISC0_CLR_OSC_I_MASK                 (0x6000U)
#define PMU_MISC0_CLR_OSC_I_SHIFT                (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define PMU_MISC0_CLR_OSC_I(x)                   (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_OSC_I_SHIFT)) & PMU_MISC0_CLR_OSC_I_MASK)

#define PMU_MISC0_CLR_OSC_XTALOK_MASK            (0x8000U)
#define PMU_MISC0_CLR_OSC_XTALOK_SHIFT           (15U)
#define PMU_MISC0_CLR_OSC_XTALOK(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_OSC_XTALOK_SHIFT)) & PMU_MISC0_CLR_OSC_XTALOK_MASK)

#define PMU_MISC0_CLR_OSC_XTALOK_EN_MASK         (0x10000U)
#define PMU_MISC0_CLR_OSC_XTALOK_EN_SHIFT        (16U)
#define PMU_MISC0_CLR_OSC_XTALOK_EN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_OSC_XTALOK_EN_SHIFT)) & PMU_MISC0_CLR_OSC_XTALOK_EN_MASK)

#define PMU_MISC0_CLR_CLKGATE_CTRL_MASK          (0x2000000U)
#define PMU_MISC0_CLR_CLKGATE_CTRL_SHIFT         (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define PMU_MISC0_CLR_CLKGATE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_CLKGATE_CTRL_SHIFT)) & PMU_MISC0_CLR_CLKGATE_CTRL_MASK)

#define PMU_MISC0_CLR_CLKGATE_DELAY_MASK         (0x1C000000U)
#define PMU_MISC0_CLR_CLKGATE_DELAY_SHIFT        (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define PMU_MISC0_CLR_CLKGATE_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_CLKGATE_DELAY_SHIFT)) & PMU_MISC0_CLR_CLKGATE_DELAY_MASK)

#define PMU_MISC0_CLR_RTC_XTAL_SOURCE_MASK       (0x20000000U)
#define PMU_MISC0_CLR_RTC_XTAL_SOURCE_SHIFT      (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define PMU_MISC0_CLR_RTC_XTAL_SOURCE(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_RTC_XTAL_SOURCE_SHIFT)) & PMU_MISC0_CLR_RTC_XTAL_SOURCE_MASK)

#define PMU_MISC0_CLR_XTAL_24M_PWD_MASK          (0x40000000U)
#define PMU_MISC0_CLR_XTAL_24M_PWD_SHIFT         (30U)
#define PMU_MISC0_CLR_XTAL_24M_PWD(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_XTAL_24M_PWD_SHIFT)) & PMU_MISC0_CLR_XTAL_24M_PWD_MASK)

#define PMU_MISC0_CLR_VID_PLL_PREDIV_MASK        (0x80000000U)
#define PMU_MISC0_CLR_VID_PLL_PREDIV_SHIFT       (31U)
/*! VID_PLL_PREDIV
 *  0b0..Divide by 1
 *  0b1..Divide by 2
 */
#define PMU_MISC0_CLR_VID_PLL_PREDIV(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_CLR_VID_PLL_PREDIV_SHIFT)) & PMU_MISC0_CLR_VID_PLL_PREDIV_MASK)
/*! @} */

/*! @name MISC0_TOG - Miscellaneous Register 0 */
/*! @{ */

#define PMU_MISC0_TOG_REFTOP_PWD_MASK            (0x1U)
#define PMU_MISC0_TOG_REFTOP_PWD_SHIFT           (0U)
#define PMU_MISC0_TOG_REFTOP_PWD(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_REFTOP_PWD_SHIFT)) & PMU_MISC0_TOG_REFTOP_PWD_MASK)

#define PMU_MISC0_TOG_REFTOP_PWDVBGUP_MASK       (0x2U)
#define PMU_MISC0_TOG_REFTOP_PWDVBGUP_SHIFT      (1U)
#define PMU_MISC0_TOG_REFTOP_PWDVBGUP(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_REFTOP_PWDVBGUP_SHIFT)) & PMU_MISC0_TOG_REFTOP_PWDVBGUP_MASK)

#define PMU_MISC0_TOG_REFTOP_LOWPOWER_MASK       (0x4U)
#define PMU_MISC0_TOG_REFTOP_LOWPOWER_SHIFT      (2U)
#define PMU_MISC0_TOG_REFTOP_LOWPOWER(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_REFTOP_LOWPOWER_SHIFT)) & PMU_MISC0_TOG_REFTOP_LOWPOWER_MASK)

#define PMU_MISC0_TOG_REFTOP_SELFBIASOFF_MASK    (0x8U)
#define PMU_MISC0_TOG_REFTOP_SELFBIASOFF_SHIFT   (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define PMU_MISC0_TOG_REFTOP_SELFBIASOFF(x)      (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_REFTOP_SELFBIASOFF_SHIFT)) & PMU_MISC0_TOG_REFTOP_SELFBIASOFF_MASK)

#define PMU_MISC0_TOG_REFTOP_VBGADJ_MASK         (0x70U)
#define PMU_MISC0_TOG_REFTOP_VBGADJ_SHIFT        (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define PMU_MISC0_TOG_REFTOP_VBGADJ(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_REFTOP_VBGADJ_SHIFT)) & PMU_MISC0_TOG_REFTOP_VBGADJ_MASK)

#define PMU_MISC0_TOG_REFTOP_VBGUP_MASK          (0x80U)
#define PMU_MISC0_TOG_REFTOP_VBGUP_SHIFT         (7U)
#define PMU_MISC0_TOG_REFTOP_VBGUP(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_REFTOP_VBGUP_SHIFT)) & PMU_MISC0_TOG_REFTOP_VBGUP_MASK)

#define PMU_MISC0_TOG_STOP_MODE_CONFIG_MASK      (0xC00U)
#define PMU_MISC0_TOG_STOP_MODE_CONFIG_SHIFT     (10U)
/*! STOP_MODE_CONFIG
 *  0b00..SUSPEND (DSM)
 *  0b01..Analog regulators are ON.
 *  0b10..STOP (lower power)
 *  0b11..STOP (very lower power)
 */
#define PMU_MISC0_TOG_STOP_MODE_CONFIG(x)        (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_STOP_MODE_CONFIG_SHIFT)) & PMU_MISC0_TOG_STOP_MODE_CONFIG_MASK)

#define PMU_MISC0_TOG_DISCON_HIGH_SNVS_MASK      (0x1000U)
#define PMU_MISC0_TOG_DISCON_HIGH_SNVS_SHIFT     (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define PMU_MISC0_TOG_DISCON_HIGH_SNVS(x)        (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_DISCON_HIGH_SNVS_SHIFT)) & PMU_MISC0_TOG_DISCON_HIGH_SNVS_MASK)

#define PMU_MISC0_TOG_OSC_I_MASK                 (0x6000U)
#define PMU_MISC0_TOG_OSC_I_SHIFT                (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define PMU_MISC0_TOG_OSC_I(x)                   (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_OSC_I_SHIFT)) & PMU_MISC0_TOG_OSC_I_MASK)

#define PMU_MISC0_TOG_OSC_XTALOK_MASK            (0x8000U)
#define PMU_MISC0_TOG_OSC_XTALOK_SHIFT           (15U)
#define PMU_MISC0_TOG_OSC_XTALOK(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_OSC_XTALOK_SHIFT)) & PMU_MISC0_TOG_OSC_XTALOK_MASK)

#define PMU_MISC0_TOG_OSC_XTALOK_EN_MASK         (0x10000U)
#define PMU_MISC0_TOG_OSC_XTALOK_EN_SHIFT        (16U)
#define PMU_MISC0_TOG_OSC_XTALOK_EN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_OSC_XTALOK_EN_SHIFT)) & PMU_MISC0_TOG_OSC_XTALOK_EN_MASK)

#define PMU_MISC0_TOG_CLKGATE_CTRL_MASK          (0x2000000U)
#define PMU_MISC0_TOG_CLKGATE_CTRL_SHIFT         (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define PMU_MISC0_TOG_CLKGATE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_CLKGATE_CTRL_SHIFT)) & PMU_MISC0_TOG_CLKGATE_CTRL_MASK)

#define PMU_MISC0_TOG_CLKGATE_DELAY_MASK         (0x1C000000U)
#define PMU_MISC0_TOG_CLKGATE_DELAY_SHIFT        (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define PMU_MISC0_TOG_CLKGATE_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_CLKGATE_DELAY_SHIFT)) & PMU_MISC0_TOG_CLKGATE_DELAY_MASK)

#define PMU_MISC0_TOG_RTC_XTAL_SOURCE_MASK       (0x20000000U)
#define PMU_MISC0_TOG_RTC_XTAL_SOURCE_SHIFT      (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define PMU_MISC0_TOG_RTC_XTAL_SOURCE(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_RTC_XTAL_SOURCE_SHIFT)) & PMU_MISC0_TOG_RTC_XTAL_SOURCE_MASK)

#define PMU_MISC0_TOG_XTAL_24M_PWD_MASK          (0x40000000U)
#define PMU_MISC0_TOG_XTAL_24M_PWD_SHIFT         (30U)
#define PMU_MISC0_TOG_XTAL_24M_PWD(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_XTAL_24M_PWD_SHIFT)) & PMU_MISC0_TOG_XTAL_24M_PWD_MASK)

#define PMU_MISC0_TOG_VID_PLL_PREDIV_MASK        (0x80000000U)
#define PMU_MISC0_TOG_VID_PLL_PREDIV_SHIFT       (31U)
/*! VID_PLL_PREDIV
 *  0b0..Divide by 1
 *  0b1..Divide by 2
 */
#define PMU_MISC0_TOG_VID_PLL_PREDIV(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC0_TOG_VID_PLL_PREDIV_SHIFT)) & PMU_MISC0_TOG_VID_PLL_PREDIV_MASK)
/*! @} */

/*! @name MISC1 - Miscellaneous Register 1 */
/*! @{ */

#define PMU_MISC1_LVDS1_CLK_SEL_MASK             (0x1FU)
#define PMU_MISC1_LVDS1_CLK_SEL_SHIFT            (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define PMU_MISC1_LVDS1_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_LVDS1_CLK_SEL_SHIFT)) & PMU_MISC1_LVDS1_CLK_SEL_MASK)

#define PMU_MISC1_LVDS2_CLK_SEL_MASK             (0x3E0U)
#define PMU_MISC1_LVDS2_CLK_SEL_SHIFT            (5U)
/*! LVDS2_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01000..MLB PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01010..PCIe ref clock (125M)
 *  0b01011..SATA ref clock (100M)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 *  0b10011..LVDS1 (loopback)
 *  0b10100..LVDS2 (not useful)
 */
#define PMU_MISC1_LVDS2_CLK_SEL(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_LVDS2_CLK_SEL_SHIFT)) & PMU_MISC1_LVDS2_CLK_SEL_MASK)

#define PMU_MISC1_LVDSCLK1_OBEN_MASK             (0x400U)
#define PMU_MISC1_LVDSCLK1_OBEN_SHIFT            (10U)
#define PMU_MISC1_LVDSCLK1_OBEN(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_LVDSCLK1_OBEN_SHIFT)) & PMU_MISC1_LVDSCLK1_OBEN_MASK)

#define PMU_MISC1_LVDSCLK2_OBEN_MASK             (0x800U)
#define PMU_MISC1_LVDSCLK2_OBEN_SHIFT            (11U)
#define PMU_MISC1_LVDSCLK2_OBEN(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_LVDSCLK2_OBEN_SHIFT)) & PMU_MISC1_LVDSCLK2_OBEN_MASK)

#define PMU_MISC1_LVDSCLK1_IBEN_MASK             (0x1000U)
#define PMU_MISC1_LVDSCLK1_IBEN_SHIFT            (12U)
#define PMU_MISC1_LVDSCLK1_IBEN(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_LVDSCLK1_IBEN_SHIFT)) & PMU_MISC1_LVDSCLK1_IBEN_MASK)

#define PMU_MISC1_LVDSCLK2_IBEN_MASK             (0x2000U)
#define PMU_MISC1_LVDSCLK2_IBEN_SHIFT            (13U)
#define PMU_MISC1_LVDSCLK2_IBEN(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_LVDSCLK2_IBEN_SHIFT)) & PMU_MISC1_LVDSCLK2_IBEN_MASK)

#define PMU_MISC1_PFD_480_AUTOGATE_EN_MASK       (0x10000U)
#define PMU_MISC1_PFD_480_AUTOGATE_EN_SHIFT      (16U)
#define PMU_MISC1_PFD_480_AUTOGATE_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_PFD_480_AUTOGATE_EN_SHIFT)) & PMU_MISC1_PFD_480_AUTOGATE_EN_MASK)

#define PMU_MISC1_PFD_528_AUTOGATE_EN_MASK       (0x20000U)
#define PMU_MISC1_PFD_528_AUTOGATE_EN_SHIFT      (17U)
#define PMU_MISC1_PFD_528_AUTOGATE_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_PFD_528_AUTOGATE_EN_SHIFT)) & PMU_MISC1_PFD_528_AUTOGATE_EN_MASK)

#define PMU_MISC1_IRQ_TEMPPANIC_MASK             (0x8000000U)
#define PMU_MISC1_IRQ_TEMPPANIC_SHIFT            (27U)
#define PMU_MISC1_IRQ_TEMPPANIC(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_IRQ_TEMPPANIC_SHIFT)) & PMU_MISC1_IRQ_TEMPPANIC_MASK)

#define PMU_MISC1_IRQ_TEMPLOW_MASK               (0x10000000U)
#define PMU_MISC1_IRQ_TEMPLOW_SHIFT              (28U)
#define PMU_MISC1_IRQ_TEMPLOW(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_IRQ_TEMPLOW_SHIFT)) & PMU_MISC1_IRQ_TEMPLOW_MASK)

#define PMU_MISC1_IRQ_TEMPHIGH_MASK              (0x20000000U)
#define PMU_MISC1_IRQ_TEMPHIGH_SHIFT             (29U)
#define PMU_MISC1_IRQ_TEMPHIGH(x)                (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_IRQ_TEMPHIGH_SHIFT)) & PMU_MISC1_IRQ_TEMPHIGH_MASK)

#define PMU_MISC1_IRQ_ANA_BO_MASK                (0x40000000U)
#define PMU_MISC1_IRQ_ANA_BO_SHIFT               (30U)
#define PMU_MISC1_IRQ_ANA_BO(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_IRQ_ANA_BO_SHIFT)) & PMU_MISC1_IRQ_ANA_BO_MASK)

#define PMU_MISC1_IRQ_DIG_BO_MASK                (0x80000000U)
#define PMU_MISC1_IRQ_DIG_BO_SHIFT               (31U)
#define PMU_MISC1_IRQ_DIG_BO(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_IRQ_DIG_BO_SHIFT)) & PMU_MISC1_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC1_SET - Miscellaneous Register 1 */
/*! @{ */

#define PMU_MISC1_SET_LVDS1_CLK_SEL_MASK         (0x1FU)
#define PMU_MISC1_SET_LVDS1_CLK_SEL_SHIFT        (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define PMU_MISC1_SET_LVDS1_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_LVDS1_CLK_SEL_SHIFT)) & PMU_MISC1_SET_LVDS1_CLK_SEL_MASK)

#define PMU_MISC1_SET_LVDS2_CLK_SEL_MASK         (0x3E0U)
#define PMU_MISC1_SET_LVDS2_CLK_SEL_SHIFT        (5U)
/*! LVDS2_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01000..MLB PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01010..PCIe ref clock (125M)
 *  0b01011..SATA ref clock (100M)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 *  0b10011..LVDS1 (loopback)
 *  0b10100..LVDS2 (not useful)
 */
#define PMU_MISC1_SET_LVDS2_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_LVDS2_CLK_SEL_SHIFT)) & PMU_MISC1_SET_LVDS2_CLK_SEL_MASK)

#define PMU_MISC1_SET_LVDSCLK1_OBEN_MASK         (0x400U)
#define PMU_MISC1_SET_LVDSCLK1_OBEN_SHIFT        (10U)
#define PMU_MISC1_SET_LVDSCLK1_OBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_LVDSCLK1_OBEN_SHIFT)) & PMU_MISC1_SET_LVDSCLK1_OBEN_MASK)

#define PMU_MISC1_SET_LVDSCLK2_OBEN_MASK         (0x800U)
#define PMU_MISC1_SET_LVDSCLK2_OBEN_SHIFT        (11U)
#define PMU_MISC1_SET_LVDSCLK2_OBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_LVDSCLK2_OBEN_SHIFT)) & PMU_MISC1_SET_LVDSCLK2_OBEN_MASK)

#define PMU_MISC1_SET_LVDSCLK1_IBEN_MASK         (0x1000U)
#define PMU_MISC1_SET_LVDSCLK1_IBEN_SHIFT        (12U)
#define PMU_MISC1_SET_LVDSCLK1_IBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_LVDSCLK1_IBEN_SHIFT)) & PMU_MISC1_SET_LVDSCLK1_IBEN_MASK)

#define PMU_MISC1_SET_LVDSCLK2_IBEN_MASK         (0x2000U)
#define PMU_MISC1_SET_LVDSCLK2_IBEN_SHIFT        (13U)
#define PMU_MISC1_SET_LVDSCLK2_IBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_LVDSCLK2_IBEN_SHIFT)) & PMU_MISC1_SET_LVDSCLK2_IBEN_MASK)

#define PMU_MISC1_SET_PFD_480_AUTOGATE_EN_MASK   (0x10000U)
#define PMU_MISC1_SET_PFD_480_AUTOGATE_EN_SHIFT  (16U)
#define PMU_MISC1_SET_PFD_480_AUTOGATE_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_PFD_480_AUTOGATE_EN_SHIFT)) & PMU_MISC1_SET_PFD_480_AUTOGATE_EN_MASK)

#define PMU_MISC1_SET_PFD_528_AUTOGATE_EN_MASK   (0x20000U)
#define PMU_MISC1_SET_PFD_528_AUTOGATE_EN_SHIFT  (17U)
#define PMU_MISC1_SET_PFD_528_AUTOGATE_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_PFD_528_AUTOGATE_EN_SHIFT)) & PMU_MISC1_SET_PFD_528_AUTOGATE_EN_MASK)

#define PMU_MISC1_SET_IRQ_TEMPPANIC_MASK         (0x8000000U)
#define PMU_MISC1_SET_IRQ_TEMPPANIC_SHIFT        (27U)
#define PMU_MISC1_SET_IRQ_TEMPPANIC(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_IRQ_TEMPPANIC_SHIFT)) & PMU_MISC1_SET_IRQ_TEMPPANIC_MASK)

#define PMU_MISC1_SET_IRQ_TEMPLOW_MASK           (0x10000000U)
#define PMU_MISC1_SET_IRQ_TEMPLOW_SHIFT          (28U)
#define PMU_MISC1_SET_IRQ_TEMPLOW(x)             (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_IRQ_TEMPLOW_SHIFT)) & PMU_MISC1_SET_IRQ_TEMPLOW_MASK)

#define PMU_MISC1_SET_IRQ_TEMPHIGH_MASK          (0x20000000U)
#define PMU_MISC1_SET_IRQ_TEMPHIGH_SHIFT         (29U)
#define PMU_MISC1_SET_IRQ_TEMPHIGH(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_IRQ_TEMPHIGH_SHIFT)) & PMU_MISC1_SET_IRQ_TEMPHIGH_MASK)

#define PMU_MISC1_SET_IRQ_ANA_BO_MASK            (0x40000000U)
#define PMU_MISC1_SET_IRQ_ANA_BO_SHIFT           (30U)
#define PMU_MISC1_SET_IRQ_ANA_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_IRQ_ANA_BO_SHIFT)) & PMU_MISC1_SET_IRQ_ANA_BO_MASK)

#define PMU_MISC1_SET_IRQ_DIG_BO_MASK            (0x80000000U)
#define PMU_MISC1_SET_IRQ_DIG_BO_SHIFT           (31U)
#define PMU_MISC1_SET_IRQ_DIG_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_SET_IRQ_DIG_BO_SHIFT)) & PMU_MISC1_SET_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC1_CLR - Miscellaneous Register 1 */
/*! @{ */

#define PMU_MISC1_CLR_LVDS1_CLK_SEL_MASK         (0x1FU)
#define PMU_MISC1_CLR_LVDS1_CLK_SEL_SHIFT        (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define PMU_MISC1_CLR_LVDS1_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_LVDS1_CLK_SEL_SHIFT)) & PMU_MISC1_CLR_LVDS1_CLK_SEL_MASK)

#define PMU_MISC1_CLR_LVDS2_CLK_SEL_MASK         (0x3E0U)
#define PMU_MISC1_CLR_LVDS2_CLK_SEL_SHIFT        (5U)
/*! LVDS2_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01000..MLB PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01010..PCIe ref clock (125M)
 *  0b01011..SATA ref clock (100M)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 *  0b10011..LVDS1 (loopback)
 *  0b10100..LVDS2 (not useful)
 */
#define PMU_MISC1_CLR_LVDS2_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_LVDS2_CLK_SEL_SHIFT)) & PMU_MISC1_CLR_LVDS2_CLK_SEL_MASK)

#define PMU_MISC1_CLR_LVDSCLK1_OBEN_MASK         (0x400U)
#define PMU_MISC1_CLR_LVDSCLK1_OBEN_SHIFT        (10U)
#define PMU_MISC1_CLR_LVDSCLK1_OBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_LVDSCLK1_OBEN_SHIFT)) & PMU_MISC1_CLR_LVDSCLK1_OBEN_MASK)

#define PMU_MISC1_CLR_LVDSCLK2_OBEN_MASK         (0x800U)
#define PMU_MISC1_CLR_LVDSCLK2_OBEN_SHIFT        (11U)
#define PMU_MISC1_CLR_LVDSCLK2_OBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_LVDSCLK2_OBEN_SHIFT)) & PMU_MISC1_CLR_LVDSCLK2_OBEN_MASK)

#define PMU_MISC1_CLR_LVDSCLK1_IBEN_MASK         (0x1000U)
#define PMU_MISC1_CLR_LVDSCLK1_IBEN_SHIFT        (12U)
#define PMU_MISC1_CLR_LVDSCLK1_IBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_LVDSCLK1_IBEN_SHIFT)) & PMU_MISC1_CLR_LVDSCLK1_IBEN_MASK)

#define PMU_MISC1_CLR_LVDSCLK2_IBEN_MASK         (0x2000U)
#define PMU_MISC1_CLR_LVDSCLK2_IBEN_SHIFT        (13U)
#define PMU_MISC1_CLR_LVDSCLK2_IBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_LVDSCLK2_IBEN_SHIFT)) & PMU_MISC1_CLR_LVDSCLK2_IBEN_MASK)

#define PMU_MISC1_CLR_PFD_480_AUTOGATE_EN_MASK   (0x10000U)
#define PMU_MISC1_CLR_PFD_480_AUTOGATE_EN_SHIFT  (16U)
#define PMU_MISC1_CLR_PFD_480_AUTOGATE_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_PFD_480_AUTOGATE_EN_SHIFT)) & PMU_MISC1_CLR_PFD_480_AUTOGATE_EN_MASK)

#define PMU_MISC1_CLR_PFD_528_AUTOGATE_EN_MASK   (0x20000U)
#define PMU_MISC1_CLR_PFD_528_AUTOGATE_EN_SHIFT  (17U)
#define PMU_MISC1_CLR_PFD_528_AUTOGATE_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_PFD_528_AUTOGATE_EN_SHIFT)) & PMU_MISC1_CLR_PFD_528_AUTOGATE_EN_MASK)

#define PMU_MISC1_CLR_IRQ_TEMPPANIC_MASK         (0x8000000U)
#define PMU_MISC1_CLR_IRQ_TEMPPANIC_SHIFT        (27U)
#define PMU_MISC1_CLR_IRQ_TEMPPANIC(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_IRQ_TEMPPANIC_SHIFT)) & PMU_MISC1_CLR_IRQ_TEMPPANIC_MASK)

#define PMU_MISC1_CLR_IRQ_TEMPLOW_MASK           (0x10000000U)
#define PMU_MISC1_CLR_IRQ_TEMPLOW_SHIFT          (28U)
#define PMU_MISC1_CLR_IRQ_TEMPLOW(x)             (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_IRQ_TEMPLOW_SHIFT)) & PMU_MISC1_CLR_IRQ_TEMPLOW_MASK)

#define PMU_MISC1_CLR_IRQ_TEMPHIGH_MASK          (0x20000000U)
#define PMU_MISC1_CLR_IRQ_TEMPHIGH_SHIFT         (29U)
#define PMU_MISC1_CLR_IRQ_TEMPHIGH(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_IRQ_TEMPHIGH_SHIFT)) & PMU_MISC1_CLR_IRQ_TEMPHIGH_MASK)

#define PMU_MISC1_CLR_IRQ_ANA_BO_MASK            (0x40000000U)
#define PMU_MISC1_CLR_IRQ_ANA_BO_SHIFT           (30U)
#define PMU_MISC1_CLR_IRQ_ANA_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_IRQ_ANA_BO_SHIFT)) & PMU_MISC1_CLR_IRQ_ANA_BO_MASK)

#define PMU_MISC1_CLR_IRQ_DIG_BO_MASK            (0x80000000U)
#define PMU_MISC1_CLR_IRQ_DIG_BO_SHIFT           (31U)
#define PMU_MISC1_CLR_IRQ_DIG_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_CLR_IRQ_DIG_BO_SHIFT)) & PMU_MISC1_CLR_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC1_TOG - Miscellaneous Register 1 */
/*! @{ */

#define PMU_MISC1_TOG_LVDS1_CLK_SEL_MASK         (0x1FU)
#define PMU_MISC1_TOG_LVDS1_CLK_SEL_SHIFT        (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define PMU_MISC1_TOG_LVDS1_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_LVDS1_CLK_SEL_SHIFT)) & PMU_MISC1_TOG_LVDS1_CLK_SEL_MASK)

#define PMU_MISC1_TOG_LVDS2_CLK_SEL_MASK         (0x3E0U)
#define PMU_MISC1_TOG_LVDS2_CLK_SEL_SHIFT        (5U)
/*! LVDS2_CLK_SEL
 *  0b00000..ARM PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01000..MLB PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01010..PCIe ref clock (125M)
 *  0b01011..SATA ref clock (100M)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 *  0b10011..LVDS1 (loopback)
 *  0b10100..LVDS2 (not useful)
 */
#define PMU_MISC1_TOG_LVDS2_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_LVDS2_CLK_SEL_SHIFT)) & PMU_MISC1_TOG_LVDS2_CLK_SEL_MASK)

#define PMU_MISC1_TOG_LVDSCLK1_OBEN_MASK         (0x400U)
#define PMU_MISC1_TOG_LVDSCLK1_OBEN_SHIFT        (10U)
#define PMU_MISC1_TOG_LVDSCLK1_OBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_LVDSCLK1_OBEN_SHIFT)) & PMU_MISC1_TOG_LVDSCLK1_OBEN_MASK)

#define PMU_MISC1_TOG_LVDSCLK2_OBEN_MASK         (0x800U)
#define PMU_MISC1_TOG_LVDSCLK2_OBEN_SHIFT        (11U)
#define PMU_MISC1_TOG_LVDSCLK2_OBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_LVDSCLK2_OBEN_SHIFT)) & PMU_MISC1_TOG_LVDSCLK2_OBEN_MASK)

#define PMU_MISC1_TOG_LVDSCLK1_IBEN_MASK         (0x1000U)
#define PMU_MISC1_TOG_LVDSCLK1_IBEN_SHIFT        (12U)
#define PMU_MISC1_TOG_LVDSCLK1_IBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_LVDSCLK1_IBEN_SHIFT)) & PMU_MISC1_TOG_LVDSCLK1_IBEN_MASK)

#define PMU_MISC1_TOG_LVDSCLK2_IBEN_MASK         (0x2000U)
#define PMU_MISC1_TOG_LVDSCLK2_IBEN_SHIFT        (13U)
#define PMU_MISC1_TOG_LVDSCLK2_IBEN(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_LVDSCLK2_IBEN_SHIFT)) & PMU_MISC1_TOG_LVDSCLK2_IBEN_MASK)

#define PMU_MISC1_TOG_PFD_480_AUTOGATE_EN_MASK   (0x10000U)
#define PMU_MISC1_TOG_PFD_480_AUTOGATE_EN_SHIFT  (16U)
#define PMU_MISC1_TOG_PFD_480_AUTOGATE_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_PFD_480_AUTOGATE_EN_SHIFT)) & PMU_MISC1_TOG_PFD_480_AUTOGATE_EN_MASK)

#define PMU_MISC1_TOG_PFD_528_AUTOGATE_EN_MASK   (0x20000U)
#define PMU_MISC1_TOG_PFD_528_AUTOGATE_EN_SHIFT  (17U)
#define PMU_MISC1_TOG_PFD_528_AUTOGATE_EN(x)     (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_PFD_528_AUTOGATE_EN_SHIFT)) & PMU_MISC1_TOG_PFD_528_AUTOGATE_EN_MASK)

#define PMU_MISC1_TOG_IRQ_TEMPPANIC_MASK         (0x8000000U)
#define PMU_MISC1_TOG_IRQ_TEMPPANIC_SHIFT        (27U)
#define PMU_MISC1_TOG_IRQ_TEMPPANIC(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_IRQ_TEMPPANIC_SHIFT)) & PMU_MISC1_TOG_IRQ_TEMPPANIC_MASK)

#define PMU_MISC1_TOG_IRQ_TEMPLOW_MASK           (0x10000000U)
#define PMU_MISC1_TOG_IRQ_TEMPLOW_SHIFT          (28U)
#define PMU_MISC1_TOG_IRQ_TEMPLOW(x)             (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_IRQ_TEMPLOW_SHIFT)) & PMU_MISC1_TOG_IRQ_TEMPLOW_MASK)

#define PMU_MISC1_TOG_IRQ_TEMPHIGH_MASK          (0x20000000U)
#define PMU_MISC1_TOG_IRQ_TEMPHIGH_SHIFT         (29U)
#define PMU_MISC1_TOG_IRQ_TEMPHIGH(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_IRQ_TEMPHIGH_SHIFT)) & PMU_MISC1_TOG_IRQ_TEMPHIGH_MASK)

#define PMU_MISC1_TOG_IRQ_ANA_BO_MASK            (0x40000000U)
#define PMU_MISC1_TOG_IRQ_ANA_BO_SHIFT           (30U)
#define PMU_MISC1_TOG_IRQ_ANA_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_IRQ_ANA_BO_SHIFT)) & PMU_MISC1_TOG_IRQ_ANA_BO_MASK)

#define PMU_MISC1_TOG_IRQ_DIG_BO_MASK            (0x80000000U)
#define PMU_MISC1_TOG_IRQ_DIG_BO_SHIFT           (31U)
#define PMU_MISC1_TOG_IRQ_DIG_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC1_TOG_IRQ_DIG_BO_SHIFT)) & PMU_MISC1_TOG_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC2 - Miscellaneous Control Register */
/*! @{ */

#define PMU_MISC2_REG0_BO_OFFSET_MASK            (0x7U)
#define PMU_MISC2_REG0_BO_OFFSET_SHIFT           (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_REG0_BO_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG0_BO_OFFSET_SHIFT)) & PMU_MISC2_REG0_BO_OFFSET_MASK)

#define PMU_MISC2_REG0_BO_STATUS_MASK            (0x8U)
#define PMU_MISC2_REG0_BO_STATUS_SHIFT           (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_REG0_BO_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG0_BO_STATUS_SHIFT)) & PMU_MISC2_REG0_BO_STATUS_MASK)

#define PMU_MISC2_REG0_ENABLE_BO_MASK            (0x20U)
#define PMU_MISC2_REG0_ENABLE_BO_SHIFT           (5U)
#define PMU_MISC2_REG0_ENABLE_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG0_ENABLE_BO_SHIFT)) & PMU_MISC2_REG0_ENABLE_BO_MASK)

#define PMU_MISC2_PLL3_disable_MASK              (0x80U)
#define PMU_MISC2_PLL3_disable_SHIFT             (7U)
#define PMU_MISC2_PLL3_disable(x)                (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_PLL3_disable_SHIFT)) & PMU_MISC2_PLL3_disable_MASK)

#define PMU_MISC2_REG1_BO_OFFSET_MASK            (0x700U)
#define PMU_MISC2_REG1_BO_OFFSET_SHIFT           (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_REG1_BO_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG1_BO_OFFSET_SHIFT)) & PMU_MISC2_REG1_BO_OFFSET_MASK)

#define PMU_MISC2_REG1_BO_STATUS_MASK            (0x800U)
#define PMU_MISC2_REG1_BO_STATUS_SHIFT           (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_REG1_BO_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG1_BO_STATUS_SHIFT)) & PMU_MISC2_REG1_BO_STATUS_MASK)

#define PMU_MISC2_REG1_ENABLE_BO_MASK            (0x2000U)
#define PMU_MISC2_REG1_ENABLE_BO_SHIFT           (13U)
#define PMU_MISC2_REG1_ENABLE_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG1_ENABLE_BO_SHIFT)) & PMU_MISC2_REG1_ENABLE_BO_MASK)

#define PMU_MISC2_AUDIO_DIV_LSB_MASK             (0x8000U)
#define PMU_MISC2_AUDIO_DIV_LSB_SHIFT            (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_AUDIO_DIV_LSB(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_AUDIO_DIV_LSB_SHIFT)) & PMU_MISC2_AUDIO_DIV_LSB_MASK)

#define PMU_MISC2_REG2_BO_OFFSET_MASK            (0x70000U)
#define PMU_MISC2_REG2_BO_OFFSET_SHIFT           (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_REG2_BO_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG2_BO_OFFSET_SHIFT)) & PMU_MISC2_REG2_BO_OFFSET_MASK)

#define PMU_MISC2_REG2_BO_STATUS_MASK            (0x80000U)
#define PMU_MISC2_REG2_BO_STATUS_SHIFT           (19U)
#define PMU_MISC2_REG2_BO_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG2_BO_STATUS_SHIFT)) & PMU_MISC2_REG2_BO_STATUS_MASK)

#define PMU_MISC2_REG2_ENABLE_BO_MASK            (0x200000U)
#define PMU_MISC2_REG2_ENABLE_BO_SHIFT           (21U)
#define PMU_MISC2_REG2_ENABLE_BO(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG2_ENABLE_BO_SHIFT)) & PMU_MISC2_REG2_ENABLE_BO_MASK)

#define PMU_MISC2_REG2_OK_MASK                   (0x400000U)
#define PMU_MISC2_REG2_OK_SHIFT                  (22U)
#define PMU_MISC2_REG2_OK(x)                     (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG2_OK_SHIFT)) & PMU_MISC2_REG2_OK_MASK)

#define PMU_MISC2_AUDIO_DIV_MSB_MASK             (0x800000U)
#define PMU_MISC2_AUDIO_DIV_MSB_SHIFT            (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_AUDIO_DIV_MSB(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_AUDIO_DIV_MSB_SHIFT)) & PMU_MISC2_AUDIO_DIV_MSB_MASK)

#define PMU_MISC2_REG0_STEP_TIME_MASK            (0x3000000U)
#define PMU_MISC2_REG0_STEP_TIME_SHIFT           (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_REG0_STEP_TIME(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG0_STEP_TIME_SHIFT)) & PMU_MISC2_REG0_STEP_TIME_MASK)

#define PMU_MISC2_REG1_STEP_TIME_MASK            (0xC000000U)
#define PMU_MISC2_REG1_STEP_TIME_SHIFT           (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_REG1_STEP_TIME(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG1_STEP_TIME_SHIFT)) & PMU_MISC2_REG1_STEP_TIME_MASK)

#define PMU_MISC2_REG2_STEP_TIME_MASK            (0x30000000U)
#define PMU_MISC2_REG2_STEP_TIME_SHIFT           (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_REG2_STEP_TIME(x)              (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_REG2_STEP_TIME_SHIFT)) & PMU_MISC2_REG2_STEP_TIME_MASK)

#define PMU_MISC2_VIDEO_DIV_MASK                 (0xC0000000U)
#define PMU_MISC2_VIDEO_DIV_SHIFT                (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define PMU_MISC2_VIDEO_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_VIDEO_DIV_SHIFT)) & PMU_MISC2_VIDEO_DIV_MASK)
/*! @} */

/*! @name MISC2_SET - Miscellaneous Control Register */
/*! @{ */

#define PMU_MISC2_SET_REG0_BO_OFFSET_MASK        (0x7U)
#define PMU_MISC2_SET_REG0_BO_OFFSET_SHIFT       (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_SET_REG0_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG0_BO_OFFSET_SHIFT)) & PMU_MISC2_SET_REG0_BO_OFFSET_MASK)

#define PMU_MISC2_SET_REG0_BO_STATUS_MASK        (0x8U)
#define PMU_MISC2_SET_REG0_BO_STATUS_SHIFT       (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_SET_REG0_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG0_BO_STATUS_SHIFT)) & PMU_MISC2_SET_REG0_BO_STATUS_MASK)

#define PMU_MISC2_SET_REG0_ENABLE_BO_MASK        (0x20U)
#define PMU_MISC2_SET_REG0_ENABLE_BO_SHIFT       (5U)
#define PMU_MISC2_SET_REG0_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG0_ENABLE_BO_SHIFT)) & PMU_MISC2_SET_REG0_ENABLE_BO_MASK)

#define PMU_MISC2_SET_PLL3_disable_MASK          (0x80U)
#define PMU_MISC2_SET_PLL3_disable_SHIFT         (7U)
#define PMU_MISC2_SET_PLL3_disable(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_PLL3_disable_SHIFT)) & PMU_MISC2_SET_PLL3_disable_MASK)

#define PMU_MISC2_SET_REG1_BO_OFFSET_MASK        (0x700U)
#define PMU_MISC2_SET_REG1_BO_OFFSET_SHIFT       (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_SET_REG1_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG1_BO_OFFSET_SHIFT)) & PMU_MISC2_SET_REG1_BO_OFFSET_MASK)

#define PMU_MISC2_SET_REG1_BO_STATUS_MASK        (0x800U)
#define PMU_MISC2_SET_REG1_BO_STATUS_SHIFT       (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_SET_REG1_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG1_BO_STATUS_SHIFT)) & PMU_MISC2_SET_REG1_BO_STATUS_MASK)

#define PMU_MISC2_SET_REG1_ENABLE_BO_MASK        (0x2000U)
#define PMU_MISC2_SET_REG1_ENABLE_BO_SHIFT       (13U)
#define PMU_MISC2_SET_REG1_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG1_ENABLE_BO_SHIFT)) & PMU_MISC2_SET_REG1_ENABLE_BO_MASK)

#define PMU_MISC2_SET_AUDIO_DIV_LSB_MASK         (0x8000U)
#define PMU_MISC2_SET_AUDIO_DIV_LSB_SHIFT        (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_SET_AUDIO_DIV_LSB(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_AUDIO_DIV_LSB_SHIFT)) & PMU_MISC2_SET_AUDIO_DIV_LSB_MASK)

#define PMU_MISC2_SET_REG2_BO_OFFSET_MASK        (0x70000U)
#define PMU_MISC2_SET_REG2_BO_OFFSET_SHIFT       (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_SET_REG2_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG2_BO_OFFSET_SHIFT)) & PMU_MISC2_SET_REG2_BO_OFFSET_MASK)

#define PMU_MISC2_SET_REG2_BO_STATUS_MASK        (0x80000U)
#define PMU_MISC2_SET_REG2_BO_STATUS_SHIFT       (19U)
#define PMU_MISC2_SET_REG2_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG2_BO_STATUS_SHIFT)) & PMU_MISC2_SET_REG2_BO_STATUS_MASK)

#define PMU_MISC2_SET_REG2_ENABLE_BO_MASK        (0x200000U)
#define PMU_MISC2_SET_REG2_ENABLE_BO_SHIFT       (21U)
#define PMU_MISC2_SET_REG2_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG2_ENABLE_BO_SHIFT)) & PMU_MISC2_SET_REG2_ENABLE_BO_MASK)

#define PMU_MISC2_SET_REG2_OK_MASK               (0x400000U)
#define PMU_MISC2_SET_REG2_OK_SHIFT              (22U)
#define PMU_MISC2_SET_REG2_OK(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG2_OK_SHIFT)) & PMU_MISC2_SET_REG2_OK_MASK)

#define PMU_MISC2_SET_AUDIO_DIV_MSB_MASK         (0x800000U)
#define PMU_MISC2_SET_AUDIO_DIV_MSB_SHIFT        (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_SET_AUDIO_DIV_MSB(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_AUDIO_DIV_MSB_SHIFT)) & PMU_MISC2_SET_AUDIO_DIV_MSB_MASK)

#define PMU_MISC2_SET_REG0_STEP_TIME_MASK        (0x3000000U)
#define PMU_MISC2_SET_REG0_STEP_TIME_SHIFT       (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_SET_REG0_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG0_STEP_TIME_SHIFT)) & PMU_MISC2_SET_REG0_STEP_TIME_MASK)

#define PMU_MISC2_SET_REG1_STEP_TIME_MASK        (0xC000000U)
#define PMU_MISC2_SET_REG1_STEP_TIME_SHIFT       (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_SET_REG1_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG1_STEP_TIME_SHIFT)) & PMU_MISC2_SET_REG1_STEP_TIME_MASK)

#define PMU_MISC2_SET_REG2_STEP_TIME_MASK        (0x30000000U)
#define PMU_MISC2_SET_REG2_STEP_TIME_SHIFT       (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_SET_REG2_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_REG2_STEP_TIME_SHIFT)) & PMU_MISC2_SET_REG2_STEP_TIME_MASK)

#define PMU_MISC2_SET_VIDEO_DIV_MASK             (0xC0000000U)
#define PMU_MISC2_SET_VIDEO_DIV_SHIFT            (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define PMU_MISC2_SET_VIDEO_DIV(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_SET_VIDEO_DIV_SHIFT)) & PMU_MISC2_SET_VIDEO_DIV_MASK)
/*! @} */

/*! @name MISC2_CLR - Miscellaneous Control Register */
/*! @{ */

#define PMU_MISC2_CLR_REG0_BO_OFFSET_MASK        (0x7U)
#define PMU_MISC2_CLR_REG0_BO_OFFSET_SHIFT       (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_CLR_REG0_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG0_BO_OFFSET_SHIFT)) & PMU_MISC2_CLR_REG0_BO_OFFSET_MASK)

#define PMU_MISC2_CLR_REG0_BO_STATUS_MASK        (0x8U)
#define PMU_MISC2_CLR_REG0_BO_STATUS_SHIFT       (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_CLR_REG0_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG0_BO_STATUS_SHIFT)) & PMU_MISC2_CLR_REG0_BO_STATUS_MASK)

#define PMU_MISC2_CLR_REG0_ENABLE_BO_MASK        (0x20U)
#define PMU_MISC2_CLR_REG0_ENABLE_BO_SHIFT       (5U)
#define PMU_MISC2_CLR_REG0_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG0_ENABLE_BO_SHIFT)) & PMU_MISC2_CLR_REG0_ENABLE_BO_MASK)

#define PMU_MISC2_CLR_PLL3_disable_MASK          (0x80U)
#define PMU_MISC2_CLR_PLL3_disable_SHIFT         (7U)
#define PMU_MISC2_CLR_PLL3_disable(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_PLL3_disable_SHIFT)) & PMU_MISC2_CLR_PLL3_disable_MASK)

#define PMU_MISC2_CLR_REG1_BO_OFFSET_MASK        (0x700U)
#define PMU_MISC2_CLR_REG1_BO_OFFSET_SHIFT       (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_CLR_REG1_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG1_BO_OFFSET_SHIFT)) & PMU_MISC2_CLR_REG1_BO_OFFSET_MASK)

#define PMU_MISC2_CLR_REG1_BO_STATUS_MASK        (0x800U)
#define PMU_MISC2_CLR_REG1_BO_STATUS_SHIFT       (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_CLR_REG1_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG1_BO_STATUS_SHIFT)) & PMU_MISC2_CLR_REG1_BO_STATUS_MASK)

#define PMU_MISC2_CLR_REG1_ENABLE_BO_MASK        (0x2000U)
#define PMU_MISC2_CLR_REG1_ENABLE_BO_SHIFT       (13U)
#define PMU_MISC2_CLR_REG1_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG1_ENABLE_BO_SHIFT)) & PMU_MISC2_CLR_REG1_ENABLE_BO_MASK)

#define PMU_MISC2_CLR_AUDIO_DIV_LSB_MASK         (0x8000U)
#define PMU_MISC2_CLR_AUDIO_DIV_LSB_SHIFT        (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_CLR_AUDIO_DIV_LSB(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_AUDIO_DIV_LSB_SHIFT)) & PMU_MISC2_CLR_AUDIO_DIV_LSB_MASK)

#define PMU_MISC2_CLR_REG2_BO_OFFSET_MASK        (0x70000U)
#define PMU_MISC2_CLR_REG2_BO_OFFSET_SHIFT       (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_CLR_REG2_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG2_BO_OFFSET_SHIFT)) & PMU_MISC2_CLR_REG2_BO_OFFSET_MASK)

#define PMU_MISC2_CLR_REG2_BO_STATUS_MASK        (0x80000U)
#define PMU_MISC2_CLR_REG2_BO_STATUS_SHIFT       (19U)
#define PMU_MISC2_CLR_REG2_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG2_BO_STATUS_SHIFT)) & PMU_MISC2_CLR_REG2_BO_STATUS_MASK)

#define PMU_MISC2_CLR_REG2_ENABLE_BO_MASK        (0x200000U)
#define PMU_MISC2_CLR_REG2_ENABLE_BO_SHIFT       (21U)
#define PMU_MISC2_CLR_REG2_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG2_ENABLE_BO_SHIFT)) & PMU_MISC2_CLR_REG2_ENABLE_BO_MASK)

#define PMU_MISC2_CLR_REG2_OK_MASK               (0x400000U)
#define PMU_MISC2_CLR_REG2_OK_SHIFT              (22U)
#define PMU_MISC2_CLR_REG2_OK(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG2_OK_SHIFT)) & PMU_MISC2_CLR_REG2_OK_MASK)

#define PMU_MISC2_CLR_AUDIO_DIV_MSB_MASK         (0x800000U)
#define PMU_MISC2_CLR_AUDIO_DIV_MSB_SHIFT        (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_CLR_AUDIO_DIV_MSB(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_AUDIO_DIV_MSB_SHIFT)) & PMU_MISC2_CLR_AUDIO_DIV_MSB_MASK)

#define PMU_MISC2_CLR_REG0_STEP_TIME_MASK        (0x3000000U)
#define PMU_MISC2_CLR_REG0_STEP_TIME_SHIFT       (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_CLR_REG0_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG0_STEP_TIME_SHIFT)) & PMU_MISC2_CLR_REG0_STEP_TIME_MASK)

#define PMU_MISC2_CLR_REG1_STEP_TIME_MASK        (0xC000000U)
#define PMU_MISC2_CLR_REG1_STEP_TIME_SHIFT       (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_CLR_REG1_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG1_STEP_TIME_SHIFT)) & PMU_MISC2_CLR_REG1_STEP_TIME_MASK)

#define PMU_MISC2_CLR_REG2_STEP_TIME_MASK        (0x30000000U)
#define PMU_MISC2_CLR_REG2_STEP_TIME_SHIFT       (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_CLR_REG2_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_REG2_STEP_TIME_SHIFT)) & PMU_MISC2_CLR_REG2_STEP_TIME_MASK)

#define PMU_MISC2_CLR_VIDEO_DIV_MASK             (0xC0000000U)
#define PMU_MISC2_CLR_VIDEO_DIV_SHIFT            (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define PMU_MISC2_CLR_VIDEO_DIV(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_CLR_VIDEO_DIV_SHIFT)) & PMU_MISC2_CLR_VIDEO_DIV_MASK)
/*! @} */

/*! @name MISC2_TOG - Miscellaneous Control Register */
/*! @{ */

#define PMU_MISC2_TOG_REG0_BO_OFFSET_MASK        (0x7U)
#define PMU_MISC2_TOG_REG0_BO_OFFSET_SHIFT       (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_TOG_REG0_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG0_BO_OFFSET_SHIFT)) & PMU_MISC2_TOG_REG0_BO_OFFSET_MASK)

#define PMU_MISC2_TOG_REG0_BO_STATUS_MASK        (0x8U)
#define PMU_MISC2_TOG_REG0_BO_STATUS_SHIFT       (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_TOG_REG0_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG0_BO_STATUS_SHIFT)) & PMU_MISC2_TOG_REG0_BO_STATUS_MASK)

#define PMU_MISC2_TOG_REG0_ENABLE_BO_MASK        (0x20U)
#define PMU_MISC2_TOG_REG0_ENABLE_BO_SHIFT       (5U)
#define PMU_MISC2_TOG_REG0_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG0_ENABLE_BO_SHIFT)) & PMU_MISC2_TOG_REG0_ENABLE_BO_MASK)

#define PMU_MISC2_TOG_PLL3_disable_MASK          (0x80U)
#define PMU_MISC2_TOG_PLL3_disable_SHIFT         (7U)
#define PMU_MISC2_TOG_PLL3_disable(x)            (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_PLL3_disable_SHIFT)) & PMU_MISC2_TOG_PLL3_disable_MASK)

#define PMU_MISC2_TOG_REG1_BO_OFFSET_MASK        (0x700U)
#define PMU_MISC2_TOG_REG1_BO_OFFSET_SHIFT       (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_TOG_REG1_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG1_BO_OFFSET_SHIFT)) & PMU_MISC2_TOG_REG1_BO_OFFSET_MASK)

#define PMU_MISC2_TOG_REG1_BO_STATUS_MASK        (0x800U)
#define PMU_MISC2_TOG_REG1_BO_STATUS_SHIFT       (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define PMU_MISC2_TOG_REG1_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG1_BO_STATUS_SHIFT)) & PMU_MISC2_TOG_REG1_BO_STATUS_MASK)

#define PMU_MISC2_TOG_REG1_ENABLE_BO_MASK        (0x2000U)
#define PMU_MISC2_TOG_REG1_ENABLE_BO_SHIFT       (13U)
#define PMU_MISC2_TOG_REG1_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG1_ENABLE_BO_SHIFT)) & PMU_MISC2_TOG_REG1_ENABLE_BO_MASK)

#define PMU_MISC2_TOG_AUDIO_DIV_LSB_MASK         (0x8000U)
#define PMU_MISC2_TOG_AUDIO_DIV_LSB_SHIFT        (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_TOG_AUDIO_DIV_LSB(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_AUDIO_DIV_LSB_SHIFT)) & PMU_MISC2_TOG_AUDIO_DIV_LSB_MASK)

#define PMU_MISC2_TOG_REG2_BO_OFFSET_MASK        (0x70000U)
#define PMU_MISC2_TOG_REG2_BO_OFFSET_SHIFT       (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define PMU_MISC2_TOG_REG2_BO_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG2_BO_OFFSET_SHIFT)) & PMU_MISC2_TOG_REG2_BO_OFFSET_MASK)

#define PMU_MISC2_TOG_REG2_BO_STATUS_MASK        (0x80000U)
#define PMU_MISC2_TOG_REG2_BO_STATUS_SHIFT       (19U)
#define PMU_MISC2_TOG_REG2_BO_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG2_BO_STATUS_SHIFT)) & PMU_MISC2_TOG_REG2_BO_STATUS_MASK)

#define PMU_MISC2_TOG_REG2_ENABLE_BO_MASK        (0x200000U)
#define PMU_MISC2_TOG_REG2_ENABLE_BO_SHIFT       (21U)
#define PMU_MISC2_TOG_REG2_ENABLE_BO(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG2_ENABLE_BO_SHIFT)) & PMU_MISC2_TOG_REG2_ENABLE_BO_MASK)

#define PMU_MISC2_TOG_REG2_OK_MASK               (0x400000U)
#define PMU_MISC2_TOG_REG2_OK_SHIFT              (22U)
#define PMU_MISC2_TOG_REG2_OK(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG2_OK_SHIFT)) & PMU_MISC2_TOG_REG2_OK_MASK)

#define PMU_MISC2_TOG_AUDIO_DIV_MSB_MASK         (0x800000U)
#define PMU_MISC2_TOG_AUDIO_DIV_MSB_SHIFT        (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define PMU_MISC2_TOG_AUDIO_DIV_MSB(x)           (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_AUDIO_DIV_MSB_SHIFT)) & PMU_MISC2_TOG_AUDIO_DIV_MSB_MASK)

#define PMU_MISC2_TOG_REG0_STEP_TIME_MASK        (0x3000000U)
#define PMU_MISC2_TOG_REG0_STEP_TIME_SHIFT       (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_TOG_REG0_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG0_STEP_TIME_SHIFT)) & PMU_MISC2_TOG_REG0_STEP_TIME_MASK)

#define PMU_MISC2_TOG_REG1_STEP_TIME_MASK        (0xC000000U)
#define PMU_MISC2_TOG_REG1_STEP_TIME_SHIFT       (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_TOG_REG1_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG1_STEP_TIME_SHIFT)) & PMU_MISC2_TOG_REG1_STEP_TIME_MASK)

#define PMU_MISC2_TOG_REG2_STEP_TIME_MASK        (0x30000000U)
#define PMU_MISC2_TOG_REG2_STEP_TIME_SHIFT       (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define PMU_MISC2_TOG_REG2_STEP_TIME(x)          (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_REG2_STEP_TIME_SHIFT)) & PMU_MISC2_TOG_REG2_STEP_TIME_MASK)

#define PMU_MISC2_TOG_VIDEO_DIV_MASK             (0xC0000000U)
#define PMU_MISC2_TOG_VIDEO_DIV_SHIFT            (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define PMU_MISC2_TOG_VIDEO_DIV(x)               (((uint32_t)(((uint32_t)(x)) << PMU_MISC2_TOG_VIDEO_DIV_SHIFT)) & PMU_MISC2_TOG_VIDEO_DIV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMU_Register_Masks */


/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_PMU_H_ */

