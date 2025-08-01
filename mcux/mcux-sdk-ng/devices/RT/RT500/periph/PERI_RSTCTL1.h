/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RSTCTL1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RSTCTL1.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL1
 *
 * CMSIS Peripheral Access Layer for RSTCTL1
 */

#if !defined(PERI_RSTCTL1_H_)
#define PERI_RSTCTL1_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- RSTCTL1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL1_Peripheral_Access_Layer RSTCTL1 Peripheral Access Layer
 * @{
 */

/** RSTCTL1 - Register Layout Typedef */
typedef struct {
  __I  uint32_t SYSRSTSTAT;                        /**< System Reset Status Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PRSTCTL0;                          /**< Peripheral Reset Control Register 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< Peripheral Reset Control Register 1, offset: 0x14 */
  __IO uint32_t PRSTCTL2;                          /**< Peripheral Reset Control Register 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __O  uint32_t PRSTCTL0_SET;                      /**< Peripheral Reset Control Register 0 SET, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< Peripheral Reset Control Register 1 SET, offset: 0x44 */
  __O  uint32_t PRSTCTL2_SET;                      /**< Peripheral Reset Control Register 2 SET, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __O  uint32_t PRSTCTL0_CLR;                      /**< Peripheral Reset Control Register 0 CLR, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< Peripheral Reset Control Register 1 CLR, offset: 0x74 */
  __O  uint32_t PRSTCTL2_CLR;                      /**< Peripheral Reset Control Register 2 CLR, offset: 0x78 */
} RSTCTL1_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL1_Register_Masks RSTCTL1 Register Masks
 * @{
 */

/*! @name SYSRSTSTAT - System Reset Status Register */
/*! @{ */

#define RSTCTL1_SYSRSTSTAT_VDD_POR_MASK          (0x1U)
#define RSTCTL1_SYSRSTSTAT_VDD_POR_SHIFT         (0U)
/*! VDD_POR - VDD Power-On Reset (POR) was detected
 *  0b0..No VDD POR event is detected
 *  0b1..VDD POR event was detected
 */
#define RSTCTL1_SYSRSTSTAT_VDD_POR(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_VDD_POR_SHIFT)) & RSTCTL1_SYSRSTSTAT_VDD_POR_MASK)

#define RSTCTL1_SYSRSTSTAT_PAD_RESET_MASK        (0x10U)
#define RSTCTL1_SYSRSTSTAT_PAD_RESET_SHIFT       (4U)
/*! PAD_RESET - RESETN pin reset was detected
 *  0b0..No RESETN pin event is detected
 *  0b1..RESETN pin reset event was detected
 */
#define RSTCTL1_SYSRSTSTAT_PAD_RESET(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_PAD_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_PAD_RESET_MASK)

#define RSTCTL1_SYSRSTSTAT_ARM_RESET_MASK        (0x20U)
#define RSTCTL1_SYSRSTSTAT_ARM_RESET_SHIFT       (5U)
/*! ARM_RESET - ARM reset was detected
 *  0b0..No ARM reset event is detected
 *  0b1..ARM reset was detected
 */
#define RSTCTL1_SYSRSTSTAT_ARM_RESET(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_ARM_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_ARM_RESET_MASK)

#define RSTCTL1_SYSRSTSTAT_WDT0_RESET_MASK       (0x40U)
#define RSTCTL1_SYSRSTSTAT_WDT0_RESET_SHIFT      (6U)
/*! WDT0_RESET - WDT0 reset was detected
 *  0b0..No WDT0 reset event is detected
 *  0b1..WDT0 reset was detected
 */
#define RSTCTL1_SYSRSTSTAT_WDT0_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_WDT0_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_WDT0_RESET_MASK)

#define RSTCTL1_SYSRSTSTAT_WDT1_RESET_MASK       (0x80U)
#define RSTCTL1_SYSRSTSTAT_WDT1_RESET_SHIFT      (7U)
/*! WDT1_RESET - WDT1 reset was detected
 *  0b0..No WDT1 reset event is detected
 *  0b1..WDT1 reset was detected
 */
#define RSTCTL1_SYSRSTSTAT_WDT1_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_WDT1_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_WDT1_RESET_MASK)
/*! @} */

/*! @name PRSTCTL0 - Peripheral Reset Control Register 0 */
/*! @{ */

#define RSTCTL1_PRSTCTL0_FLEXCOMM0_MASK          (0x100U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM0_SHIFT         (8U)
/*! FLEXCOMM0 - Flexcomm0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM0_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM0_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM1_MASK          (0x200U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM1_SHIFT         (9U)
/*! FLEXCOMM1 - Flexcomm1 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM1_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM1_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM2_MASK          (0x400U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM2_SHIFT         (10U)
/*! FLEXCOMM2 - Flexcomm2 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM2_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM2_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM3_MASK          (0x800U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM3_SHIFT         (11U)
/*! FLEXCOMM3 - Flexcomm3 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM3(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM3_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM3_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM4_MASK          (0x1000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM4_SHIFT         (12U)
/*! FLEXCOMM4 - Flexcomm4 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM4(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM4_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM4_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM5_MASK          (0x2000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM5_SHIFT         (13U)
/*! FLEXCOMM5 - Flexcomm5 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM5(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM5_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM5_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM6_MASK          (0x4000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM6_SHIFT         (14U)
/*! FLEXCOMM6 - Flexcomm6 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM6(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM6_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM6_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM7_MASK          (0x8000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM7_SHIFT         (15U)
/*! FLEXCOMM7 - Flexcomm7 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM7(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM7_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM7_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM8_MASK          (0x10000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM8_SHIFT         (16U)
/*! FLEXCOMM8 - Flexcomm8 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM8(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM8_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM8_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM9_MASK          (0x20000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM9_SHIFT         (17U)
/*! FLEXCOMM9 - Flexcomm9 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM9(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM9_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM9_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM10_MASK         (0x40000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM10_SHIFT        (18U)
/*! FLEXCOMM10 - Flexcomm10 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM10(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM10_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM10_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM11_MASK         (0x80000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM11_SHIFT        (19U)
/*! FLEXCOMM11 - Flexcomm11 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM11(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM11_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM11_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM12_MASK         (0x100000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM12_SHIFT        (20U)
/*! FLEXCOMM12 - Flexcomm12 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM12(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM12_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM12_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM13_MASK         (0x200000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM13_SHIFT        (21U)
/*! FLEXCOMM13 - Flexcomm13 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM13(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM13_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM13_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM14_MASK         (0x400000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM14_SHIFT        (22U)
/*! FLEXCOMM14 - Flexcomm14 SPI0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM14(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM14_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM14_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_MASK     (0x800000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_SHIFT    (23U)
/*! FLEXCOMM15_I2C - Flexcomm15 I2C reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_MASK)

#define RSTCTL1_PRSTCTL0_DMIC0_MASK              (0x1000000U)
#define RSTCTL1_PRSTCTL0_DMIC0_SHIFT             (24U)
/*! DMIC0 - DMIC0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_DMIC0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_DMIC0_SHIFT)) & RSTCTL1_PRSTCTL0_DMIC0_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM16_MASK         (0x2000000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM16_SHIFT        (25U)
/*! FLEXCOMM16 - Flexcomm SPI reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM16(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM16_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM16_MASK)

#define RSTCTL1_PRSTCTL0_OSEVENT_TIMER_MASK      (0x8000000U)
#define RSTCTL1_PRSTCTL0_OSEVENT_TIMER_SHIFT     (27U)
/*! OSEVENT_TIMER - OSEVENT Timer reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_OSEVENT_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_OSEVENT_TIMER_SHIFT)) & RSTCTL1_PRSTCTL0_OSEVENT_TIMER_MASK)

#define RSTCTL1_PRSTCTL0_FLEXIO_MASK             (0x20000000U)
#define RSTCTL1_PRSTCTL0_FLEXIO_SHIFT            (29U)
/*! FLEXIO - FLEXIO reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL0_FLEXIO(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXIO_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXIO_MASK)
/*! @} */

/*! @name PRSTCTL1 - Peripheral Reset Control Register 1 */
/*! @{ */

#define RSTCTL1_PRSTCTL1_HSGPIO0_MASK            (0x1U)
#define RSTCTL1_PRSTCTL1_HSGPIO0_SHIFT           (0U)
/*! HSGPIO0 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO0_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO0_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO1_MASK            (0x2U)
#define RSTCTL1_PRSTCTL1_HSGPIO1_SHIFT           (1U)
/*! HSGPIO1 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO1(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO1_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO1_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO2_MASK            (0x4U)
#define RSTCTL1_PRSTCTL1_HSGPIO2_SHIFT           (2U)
/*! HSGPIO2 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO2(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO2_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO2_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO3_MASK            (0x8U)
#define RSTCTL1_PRSTCTL1_HSGPIO3_SHIFT           (3U)
/*! HSGPIO3 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO3(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO3_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO3_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO4_MASK            (0x10U)
#define RSTCTL1_PRSTCTL1_HSGPIO4_SHIFT           (4U)
/*! HSGPIO4 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO4(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO4_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO4_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO5_MASK            (0x20U)
#define RSTCTL1_PRSTCTL1_HSGPIO5_SHIFT           (5U)
/*! HSGPIO5 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO5(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO5_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO5_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO6_MASK            (0x40U)
#define RSTCTL1_PRSTCTL1_HSGPIO6_SHIFT           (6U)
/*! HSGPIO6 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO6(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO6_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO6_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO7_MASK            (0x80U)
#define RSTCTL1_PRSTCTL1_HSGPIO7_SHIFT           (7U)
/*! HSGPIO7 - HSGPIO[7:0] reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO7(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO7_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO7_MASK)

#define RSTCTL1_PRSTCTL1_CRC_MASK                (0x10000U)
#define RSTCTL1_PRSTCTL1_CRC_SHIFT               (16U)
/*! CRC - CRC reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_CRC(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CRC_SHIFT)) & RSTCTL1_PRSTCTL1_CRC_MASK)

#define RSTCTL1_PRSTCTL1_DMAC0_MASK              (0x800000U)
#define RSTCTL1_PRSTCTL1_DMAC0_SHIFT             (23U)
/*! DMAC0 - DMAC reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_DMAC0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_DMAC0_SHIFT)) & RSTCTL1_PRSTCTL1_DMAC0_MASK)

#define RSTCTL1_PRSTCTL1_DMAC1_MASK              (0x1000000U)
#define RSTCTL1_PRSTCTL1_DMAC1_SHIFT             (24U)
/*! DMAC1 - DMAC reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_DMAC1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_DMAC1_SHIFT)) & RSTCTL1_PRSTCTL1_DMAC1_MASK)

#define RSTCTL1_PRSTCTL1_MU_MASK                 (0x10000000U)
#define RSTCTL1_PRSTCTL1_MU_SHIFT                (28U)
/*! MU - MU reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_MU(x)                   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_MU_SHIFT)) & RSTCTL1_PRSTCTL1_MU_MASK)

#define RSTCTL1_PRSTCTL1_SEMA_MASK               (0x20000000U)
#define RSTCTL1_PRSTCTL1_SEMA_SHIFT              (29U)
/*! SEMA - SEMA reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_SEMA(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SEMA_SHIFT)) & RSTCTL1_PRSTCTL1_SEMA_MASK)

#define RSTCTL1_PRSTCTL1_FREQME_MASK             (0x80000000U)
#define RSTCTL1_PRSTCTL1_FREQME_SHIFT            (31U)
/*! FREQME - FREQME reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL1_FREQME(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_FREQME_SHIFT)) & RSTCTL1_PRSTCTL1_FREQME_MASK)
/*! @} */

/*! @name PRSTCTL2 - Peripheral Reset Control Register 2 */
/*! @{ */

#define RSTCTL1_PRSTCTL2_CT32BIT0_MASK           (0x1U)
#define RSTCTL1_PRSTCTL2_CT32BIT0_SHIFT          (0U)
/*! CT32BIT0
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT0_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT0_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT1_MASK           (0x2U)
#define RSTCTL1_PRSTCTL2_CT32BIT1_SHIFT          (1U)
/*! CT32BIT1
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT1_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT1_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT2_MASK           (0x4U)
#define RSTCTL1_PRSTCTL2_CT32BIT2_SHIFT          (2U)
/*! CT32BIT2
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT2(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT2_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT2_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT3_MASK           (0x8U)
#define RSTCTL1_PRSTCTL2_CT32BIT3_SHIFT          (3U)
/*! CT32BIT3
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT3(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT3_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT3_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT4_MASK           (0x10U)
#define RSTCTL1_PRSTCTL2_CT32BIT4_SHIFT          (4U)
/*! CT32BIT4
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT4(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT4_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT4_MASK)

#define RSTCTL1_PRSTCTL2_MRT0_MASK               (0x100U)
#define RSTCTL1_PRSTCTL2_MRT0_SHIFT              (8U)
/*! MRT0 - MRT0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_MRT0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_MRT0_SHIFT)) & RSTCTL1_PRSTCTL2_MRT0_MASK)

#define RSTCTL1_PRSTCTL2_WWDT1_MASK              (0x400U)
#define RSTCTL1_PRSTCTL2_WWDT1_SHIFT             (10U)
/*! WWDT1 - WWDT1 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_WWDT1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_WWDT1_SHIFT)) & RSTCTL1_PRSTCTL2_WWDT1_MASK)

#define RSTCTL1_PRSTCTL2_I3C0_MASK               (0x10000U)
#define RSTCTL1_PRSTCTL2_I3C0_SHIFT              (16U)
/*! I3C0 - I3C0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_I3C0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_I3C0_SHIFT)) & RSTCTL1_PRSTCTL2_I3C0_MASK)

#define RSTCTL1_PRSTCTL2_I3C1_MASK               (0x20000U)
#define RSTCTL1_PRSTCTL2_I3C1_SHIFT              (17U)
/*! I3C1 - I3C1 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_I3C1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_I3C1_SHIFT)) & RSTCTL1_PRSTCTL2_I3C1_MASK)

#define RSTCTL1_PRSTCTL2_GPIOINTCTL_MASK         (0x40000000U)
#define RSTCTL1_PRSTCTL2_GPIOINTCTL_SHIFT        (30U)
/*! GPIOINTCTL - GPIOINTCTL reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_GPIOINTCTL(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_GPIOINTCTL_SHIFT)) & RSTCTL1_PRSTCTL2_GPIOINTCTL_MASK)

#define RSTCTL1_PRSTCTL2_PIMCTL_MASK             (0x80000000U)
#define RSTCTL1_PRSTCTL2_PIMCTL_SHIFT            (31U)
/*! PIMCTL - INPUTMUX reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL1_PRSTCTL2_PIMCTL(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_PIMCTL_SHIFT)) & RSTCTL1_PRSTCTL2_PIMCTL_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - Peripheral Reset Control Register 0 SET */
/*! @{ */

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_MASK      (0x100U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_SHIFT     (8U)
/*! FLEXCOMM0 - Flexcomm0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM0(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_MASK      (0x200U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_SHIFT     (9U)
/*! FLEXCOMM1 - Flexcomm1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM1(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_MASK      (0x400U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_SHIFT     (10U)
/*! FLEXCOMM2 - Flexcomm2 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM2(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_MASK      (0x800U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_SHIFT     (11U)
/*! FLEXCOMM3 - Flexcomm3 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM3(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_MASK      (0x1000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_SHIFT     (12U)
/*! FLEXCOMM4 - Flexcomm4 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM4(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_MASK      (0x2000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_SHIFT     (13U)
/*! FLEXCOMM5 - Flexcomm5 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM5(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_MASK      (0x4000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_SHIFT     (14U)
/*! FLEXCOMM6 - Flexcomm6 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM6(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_MASK      (0x8000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_SHIFT     (15U)
/*! FLEXCOMM7 - Flexcomm7 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM7(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM8_MASK      (0x10000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM8_SHIFT     (16U)
/*! FLEXCOMM8 - Flexcomm8 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM8(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM8_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM8_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM9_MASK      (0x20000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM9_SHIFT     (17U)
/*! FLEXCOMM9 - Flexcomm9 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM9(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM9_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM9_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM10_MASK     (0x40000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM10_SHIFT    (18U)
/*! FLEXCOMM10 - Flexcomm10 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM10(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM10_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM10_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM11_MASK     (0x80000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM11_SHIFT    (19U)
/*! FLEXCOMM11 - Flexcomm11 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM11(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM11_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM11_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM12_MASK     (0x100000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM12_SHIFT    (20U)
/*! FLEXCOMM12 - Flexcomm12 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM12(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM12_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM12_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM13_MASK     (0x200000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM13_SHIFT    (21U)
/*! FLEXCOMM13 - Flexcomm13 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM13(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM13_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM13_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_MASK     (0x400000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SHIFT    (22U)
/*! FLEXCOMM14 - Flexcomm14 SPI0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM14(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_MASK (0x800000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_SHIFT (23U)
/*! FLEXCOMM15_I2C - Flexcomm15 I2C reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_MASK)

#define RSTCTL1_PRSTCTL0_SET_DMIC0_MASK          (0x1000000U)
#define RSTCTL1_PRSTCTL0_SET_DMIC0_SHIFT         (24U)
/*! DMIC0 - DMIC0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_DMIC0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_DMIC0_SHIFT)) & RSTCTL1_PRSTCTL0_SET_DMIC0_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM16_MASK     (0x2000000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM16_SHIFT    (25U)
/*! FLEXCOMM16 - Flexcomm16 SPI1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM16(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM16_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM16_MASK)

#define RSTCTL1_PRSTCTL0_SET_OSEVENT_TIMER_MASK  (0x8000000U)
#define RSTCTL1_PRSTCTL0_SET_OSEVENT_TIMER_SHIFT (27U)
/*! OSEVENT_TIMER - OSEVENT Timer reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_OSEVENT_TIMER(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_OSEVENT_TIMER_SHIFT)) & RSTCTL1_PRSTCTL0_SET_OSEVENT_TIMER_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXIO_MASK         (0x20000000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXIO_SHIFT        (29U)
/*! FLEXIO - FEXIO reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXIO(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXIO_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXIO_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - Peripheral Reset Control Register 1 SET */
/*! @{ */

#define RSTCTL1_PRSTCTL1_SET_HSGPIO0_MASK        (0x1U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO0_SHIFT       (0U)
/*! HSGPIO0 - HSGPIO0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO0_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO0_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO1_MASK        (0x2U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO1_SHIFT       (1U)
/*! HSGPIO1 - HSGPIO1 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO1(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO1_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO1_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO2_MASK        (0x4U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO2_SHIFT       (2U)
/*! HSGPIO2 - HSGPIO2 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO2(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO2_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO2_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO3_MASK        (0x8U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO3_SHIFT       (3U)
/*! HSGPIO3 - HSGPIO3 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO3(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO3_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO3_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO4_MASK        (0x10U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO4_SHIFT       (4U)
/*! HSGPIO4 - HSGPIO4 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO4(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO4_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO4_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO5_MASK        (0x20U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO5_SHIFT       (5U)
/*! HSGPIO5 - HSGPIO5 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO5(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO5_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO5_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO6_MASK        (0x40U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO6_SHIFT       (6U)
/*! HSGPIO6 - HSGPIO6 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO6(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO6_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO6_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO7_MASK        (0x80U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO7_SHIFT       (7U)
/*! HSGPIO7 - HSGPIO7 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO7(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO7_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO7_MASK)

#define RSTCTL1_PRSTCTL1_SET_CRC_MASK            (0x10000U)
#define RSTCTL1_PRSTCTL1_SET_CRC_SHIFT           (16U)
/*! CRC - CRC reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_CRC(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_CRC_SHIFT)) & RSTCTL1_PRSTCTL1_SET_CRC_MASK)

#define RSTCTL1_PRSTCTL1_SET_DMAC0_MASK          (0x800000U)
#define RSTCTL1_PRSTCTL1_SET_DMAC0_SHIFT         (23U)
/*! DMAC0 - DMAC0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_DMAC0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_DMAC0_SHIFT)) & RSTCTL1_PRSTCTL1_SET_DMAC0_MASK)

#define RSTCTL1_PRSTCTL1_SET_DMAC1_MASK          (0x1000000U)
#define RSTCTL1_PRSTCTL1_SET_DMAC1_SHIFT         (24U)
/*! DMAC1 - DMAC1 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_DMAC1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_DMAC1_SHIFT)) & RSTCTL1_PRSTCTL1_SET_DMAC1_MASK)

#define RSTCTL1_PRSTCTL1_SET_MU_MASK             (0x10000000U)
#define RSTCTL1_PRSTCTL1_SET_MU_SHIFT            (28U)
/*! MU - MU reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_MU(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_MU_SHIFT)) & RSTCTL1_PRSTCTL1_SET_MU_MASK)

#define RSTCTL1_PRSTCTL1_SET_SEMA_MASK           (0x20000000U)
#define RSTCTL1_PRSTCTL1_SET_SEMA_SHIFT          (29U)
/*! SEMA - SEMA reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_SEMA(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_SEMA_SHIFT)) & RSTCTL1_PRSTCTL1_SET_SEMA_MASK)

#define RSTCTL1_PRSTCTL1_SET_FREQME_MASK         (0x80000000U)
#define RSTCTL1_PRSTCTL1_SET_FREQME_SHIFT        (31U)
/*! FREQME - FREQME reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_FREQME(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_FREQME_SHIFT)) & RSTCTL1_PRSTCTL1_SET_FREQME_MASK)
/*! @} */

/*! @name PRSTCTL2_SET - Peripheral Reset Control Register 2 SET */
/*! @{ */

#define RSTCTL1_PRSTCTL2_SET_CT32BIT0_MASK       (0x1U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT0_SHIFT      (0U)
/*! CT32BIT0 - CT32BIT0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT0_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT0_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT1_MASK       (0x2U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT1_SHIFT      (1U)
/*! CT32BIT1 - CT32BIT1 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT1(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT1_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT1_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT2_MASK       (0x4U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT2_SHIFT      (2U)
/*! CT32BIT2 - CT32BIT2 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT2(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT2_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT2_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT3_MASK       (0x8U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT3_SHIFT      (3U)
/*! CT32BIT3 - CT32BIT3 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT3(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT3_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT3_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT4_MASK       (0x10U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT4_SHIFT      (4U)
/*! CT32BIT4 - CT32BIT4 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT4(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT4_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT4_MASK)

#define RSTCTL1_PRSTCTL2_SET_MRT0_MASK           (0x100U)
#define RSTCTL1_PRSTCTL2_SET_MRT0_SHIFT          (8U)
/*! MRT0 - MRT0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_MRT0_SHIFT)) & RSTCTL1_PRSTCTL2_SET_MRT0_MASK)

#define RSTCTL1_PRSTCTL2_SET_WWDT1_MASK          (0x400U)
#define RSTCTL1_PRSTCTL2_SET_WWDT1_SHIFT         (10U)
/*! WWDT1 - WWDT1 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_WWDT1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_WWDT1_SHIFT)) & RSTCTL1_PRSTCTL2_SET_WWDT1_MASK)

#define RSTCTL1_PRSTCTL2_SET_I3C0_MASK           (0x10000U)
#define RSTCTL1_PRSTCTL2_SET_I3C0_SHIFT          (16U)
/*! I3C0 - I3C0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_I3C0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_I3C0_SHIFT)) & RSTCTL1_PRSTCTL2_SET_I3C0_MASK)

#define RSTCTL1_PRSTCTL2_SET_I3C1_MASK           (0x20000U)
#define RSTCTL1_PRSTCTL2_SET_I3C1_SHIFT          (17U)
/*! I3C1 - I3C1 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_I3C1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_I3C1_SHIFT)) & RSTCTL1_PRSTCTL2_SET_I3C1_MASK)

#define RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_MASK     (0x40000000U)
#define RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_SHIFT    (30U)
/*! GPIOINTCTL - GPIOINTCTL reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_GPIOINTCTL(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_SHIFT)) & RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_MASK)

#define RSTCTL1_PRSTCTL2_SET_PIMCTL_MASK         (0x80000000U)
#define RSTCTL1_PRSTCTL2_SET_PIMCTL_SHIFT        (31U)
/*! PIMCTL - PIMCTL reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_PIMCTL(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_PIMCTL_SHIFT)) & RSTCTL1_PRSTCTL2_SET_PIMCTL_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - Peripheral Reset Control Register 0 CLR */
/*! @{ */

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_MASK      (0x100U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_SHIFT     (8U)
/*! FLEXCOMM0 - Flexcomm0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_MASK      (0x200U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_SHIFT     (9U)
/*! FLEXCOMM1 - Flexcomm1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_MASK      (0x400U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_SHIFT     (10U)
/*! FLEXCOMM2 - Flexcomm2 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_MASK      (0x800U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_SHIFT     (11U)
/*! FLEXCOMM3 - Flexcomm3 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_MASK      (0x1000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_SHIFT     (12U)
/*! FLEXCOMM4 - Flexcomm4 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_MASK      (0x2000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_SHIFT     (13U)
/*! FLEXCOMM5 - Flexcomm5 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_MASK      (0x4000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_SHIFT     (14U)
/*! FLEXCOMM6 - Flexcomm6 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_MASK      (0x8000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_SHIFT     (15U)
/*! FLEXCOMM7 - Flexcomm7 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM8_MASK      (0x10000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM8_SHIFT     (16U)
/*! FLEXCOMM8 - Flexcomm8 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM8(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM8_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM8_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM9_MASK      (0x20000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM9_SHIFT     (17U)
/*! FLEXCOMM9 - Flexcomm9 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM9(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM9_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM9_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM10_MASK     (0x40000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM10_SHIFT    (18U)
/*! FLEXCOMM10 - Flexcomm10 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM10(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM10_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM10_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM11_MASK     (0x80000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM11_SHIFT    (19U)
/*! FLEXCOMM11 - Flexcomm11 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM11(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM11_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM11_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM12_MASK     (0x100000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM12_SHIFT    (20U)
/*! FLEXCOMM12 - Flexcomm12 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM12(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM12_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM12_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM13_MASK     (0x200000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM13_SHIFT    (21U)
/*! FLEXCOMM13 - Flexcomm13 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM13(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM13_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM13_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_MASK     (0x400000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SHIFT    (22U)
/*! FLEXCOMM14 - FLexcomm SPI0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_MASK (0x800000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_SHIFT (23U)
/*! FLEXCOMM15_I2C - Flexcomm I2C reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_MASK)

#define RSTCTL1_PRSTCTL0_CLR_DMIC0_MASK          (0x1000000U)
#define RSTCTL1_PRSTCTL0_CLR_DMIC0_SHIFT         (24U)
/*! DMIC0 - DMIC0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_DMIC0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_DMIC0_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_DMIC0_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM16_MASK     (0x2000000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM16_SHIFT    (25U)
/*! FLEXCOMM16 - Flexcomm SPI1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM16(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM16_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM16_MASK)

#define RSTCTL1_PRSTCTL0_CLR_OSEVENT_TIMER_MASK  (0x8000000U)
#define RSTCTL1_PRSTCTL0_CLR_OSEVENT_TIMER_SHIFT (27U)
/*! OSEVENT_TIMER - OSEVENT Timer reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_OSEVENT_TIMER(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_OSEVENT_TIMER_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_OSEVENT_TIMER_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXIO_MASK         (0x20000000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXIO_SHIFT        (29U)
/*! FLEXIO - FLEXIO reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXIO(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXIO_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXIO_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - Peripheral Reset Control Register 1 CLR */
/*! @{ */

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO0_MASK        (0x1U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO0_SHIFT       (0U)
/*! HSGPIO0 - HSGPIO0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO0_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO0_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO1_MASK        (0x2U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO1_SHIFT       (1U)
/*! HSGPIO1 - HSGPIO1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO1(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO1_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO1_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO2_MASK        (0x4U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO2_SHIFT       (2U)
/*! HSGPIO2 - HSGPIO2 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO2(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO2_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO2_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO3_MASK        (0x8U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO3_SHIFT       (3U)
/*! HSGPIO3 - HSGPIO3 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO3(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO3_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO3_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO4_MASK        (0x10U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO4_SHIFT       (4U)
/*! HSGPIO4 - HSGPIO4 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO4(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO4_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO4_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO5_MASK        (0x20U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO5_SHIFT       (5U)
/*! HSGPIO5 - HSGPIO5 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO5(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO5_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO5_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO6_MASK        (0x40U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO6_SHIFT       (6U)
/*! HSGPIO6 - HSGPIO6 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO6(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO6_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO6_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO7_MASK        (0x80U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO7_SHIFT       (7U)
/*! HSGPIO7 - HSGPIO7 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO7(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO7_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO7_MASK)

#define RSTCTL1_PRSTCTL1_CLR_CRC_MASK            (0x10000U)
#define RSTCTL1_PRSTCTL1_CLR_CRC_SHIFT           (16U)
/*! CRC - CRC reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_CRC(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_CRC_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_CRC_MASK)

#define RSTCTL1_PRSTCTL1_CLR_DMAC0_MASK          (0x800000U)
#define RSTCTL1_PRSTCTL1_CLR_DMAC0_SHIFT         (23U)
/*! DMAC0 - DMAC0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_DMAC0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_DMAC0_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_DMAC0_MASK)

#define RSTCTL1_PRSTCTL1_CLR_DMAC1_MASK          (0x1000000U)
#define RSTCTL1_PRSTCTL1_CLR_DMAC1_SHIFT         (24U)
/*! DMAC1 - DMAC1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_DMAC1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_DMAC1_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_DMAC1_MASK)

#define RSTCTL1_PRSTCTL1_CLR_MU_MASK             (0x10000000U)
#define RSTCTL1_PRSTCTL1_CLR_MU_SHIFT            (28U)
/*! MU - MU reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_MU(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_MU_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_MU_MASK)

#define RSTCTL1_PRSTCTL1_CLR_SEMA_MASK           (0x20000000U)
#define RSTCTL1_PRSTCTL1_CLR_SEMA_SHIFT          (29U)
/*! SEMA - SMEA reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_SEMA(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_SEMA_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_SEMA_MASK)

#define RSTCTL1_PRSTCTL1_CLR_FREQME_MASK         (0x80000000U)
#define RSTCTL1_PRSTCTL1_CLR_FREQME_SHIFT        (31U)
/*! FREQME - FREQME reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_FREQME(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_FREQME_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_FREQME_MASK)
/*! @} */

/*! @name PRSTCTL2_CLR - Peripheral Reset Control Register 2 CLR */
/*! @{ */

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT0_MASK       (0x1U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT0_SHIFT      (0U)
/*! CT32BIT0 - CT32BIT0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT0_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT0_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT1_MASK       (0x2U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT1_SHIFT      (1U)
/*! CT32BIT1 - CT32BIT1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT1(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT1_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT1_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT2_MASK       (0x4U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT2_SHIFT      (2U)
/*! CT32BIT2 - CT32BIT2 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT2(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT2_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT2_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT3_MASK       (0x8U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT3_SHIFT      (3U)
/*! CT32BIT3 - CT32BIT3 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT3(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT3_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT3_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT4_MASK       (0x10U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT4_SHIFT      (4U)
/*! CT32BIT4 - CT32BIT4 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT4(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT4_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT4_MASK)

#define RSTCTL1_PRSTCTL2_CLR_MRT0_MASK           (0x100U)
#define RSTCTL1_PRSTCTL2_CLR_MRT0_SHIFT          (8U)
/*! MRT0 - MRT0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_MRT0_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_MRT0_MASK)

#define RSTCTL1_PRSTCTL2_CLR_WWDT1_MASK          (0x400U)
#define RSTCTL1_PRSTCTL2_CLR_WWDT1_SHIFT         (10U)
/*! WWDT1 - WWDT1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_WWDT1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_WWDT1_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_WWDT1_MASK)

#define RSTCTL1_PRSTCTL2_CLR_I3C0_MASK           (0x10000U)
#define RSTCTL1_PRSTCTL2_CLR_I3C0_SHIFT          (16U)
/*! I3C0 - I3C[1:0] reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_I3C0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_I3C0_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_I3C0_MASK)

#define RSTCTL1_PRSTCTL2_CLR_I3C1_MASK           (0x20000U)
#define RSTCTL1_PRSTCTL2_CLR_I3C1_SHIFT          (17U)
/*! I3C1 - I3C[1:0] reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_I3C1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_I3C1_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_I3C1_MASK)

#define RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_MASK     (0x40000000U)
#define RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_SHIFT    (30U)
/*! GPIOINTCTL - GPIOINTCTL reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_MASK)

#define RSTCTL1_PRSTCTL2_CLR_PIMCTL_MASK         (0x80000000U)
#define RSTCTL1_PRSTCTL2_CLR_PIMCTL_SHIFT        (31U)
/*! PIMCTL
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_PIMCTL(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_PIMCTL_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_PIMCTL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL1_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL1_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_RSTCTL1_H_ */

