/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RSTCTL1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL1
 *
 * CMSIS Peripheral Access Layer for RSTCTL1
 */

#if !defined(PERI_RSTCTL1_H_)
#define PERI_RSTCTL1_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
  __IO uint32_t SYSRSTSTAT;                        /**< system reset status register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PRSTCTL0;                          /**< peripheral reset control register 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< peripheral reset control register 1, offset: 0x14 */
  __IO uint32_t PRSTCTL2;                          /**< peripheral reset control register 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __O  uint32_t PRSTCTL0_SET;                      /**< peripheral reset set register 0, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< peripheral reset set register 1, offset: 0x44 */
  __O  uint32_t PRSTCTL2_SET;                      /**< peripheral reset set register 2, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __O  uint32_t PRSTCTL0_CLR;                      /**< peripheral reset clear register 0, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< peripheral reset clear register 1, offset: 0x74 */
  __O  uint32_t PRSTCTL2_CLR;                      /**< peripheral reset clear register 2, offset: 0x78 */
} RSTCTL1_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL1_Register_Masks RSTCTL1 Register Masks
 * @{
 */

/*! @name SYSRSTSTAT - system reset status register */
/*! @{ */

#define RSTCTL1_SYSRSTSTAT_VDD_POR_MASK          (0x1U)
#define RSTCTL1_SYSRSTSTAT_VDD_POR_SHIFT         (0U)
/*! VDD_POR - VDD POR Event Detected:
 *  0b0..No event detected.
 *  0b1..VDD POR event detected. (Writing a 1 to this bit clears this status).
 */
#define RSTCTL1_SYSRSTSTAT_VDD_POR(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_VDD_POR_SHIFT)) & RSTCTL1_SYSRSTSTAT_VDD_POR_MASK)

#define RSTCTL1_SYSRSTSTAT_PAD_RESET_MASK        (0x10U)
#define RSTCTL1_SYSRSTSTAT_PAD_RESET_SHIFT       (4U)
/*! PAD_RESET - PAD RESET Event Detected:
 *  0b0..No EVENT Detected.
 *  0b1..RESET Detected. (Write 1 to CLR),
 */
#define RSTCTL1_SYSRSTSTAT_PAD_RESET(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_PAD_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_PAD_RESET_MASK)

#define RSTCTL1_SYSRSTSTAT_ARM_APD_RESET_MASK    (0x20U)
#define RSTCTL1_SYSRSTSTAT_ARM_APD_RESET_SHIFT   (5U)
/*! ARM_APD_RESET - ARM RESET Event Detected:
 *  0b0..No event detected.
 *  0b1..ARM reset event detected. (Writing a 1 to this bit clears this status).
 */
#define RSTCTL1_SYSRSTSTAT_ARM_APD_RESET(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_ARM_APD_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_ARM_APD_RESET_MASK)

#define RSTCTL1_SYSRSTSTAT_WDT0_RESET_MASK       (0x40U)
#define RSTCTL1_SYSRSTSTAT_WDT0_RESET_SHIFT      (6U)
/*! WDT0_RESET - WDT0 RESET Event Detected:
 *  0b0..No EVENT Detected.
 *  0b1..WDT0 reset event detected. (Writing a 1 to this bit clears this status).
 */
#define RSTCTL1_SYSRSTSTAT_WDT0_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_WDT0_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_WDT0_RESET_MASK)

#define RSTCTL1_SYSRSTSTAT_WDT1_RESET_MASK       (0x80U)
#define RSTCTL1_SYSRSTSTAT_WDT1_RESET_SHIFT      (7U)
/*! WDT1_RESET - WDT1 RESET Event Detected:
 *  0b0..No EVENT Detected.
 *  0b1..WDT1 reset event detected. (Writing a 1 to this bit clears this status).
 */
#define RSTCTL1_SYSRSTSTAT_WDT1_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_SYSRSTSTAT_WDT1_RESET_SHIFT)) & RSTCTL1_SYSRSTSTAT_WDT1_RESET_MASK)
/*! @} */

/*! @name PRSTCTL0 - peripheral reset control register 0 */
/*! @{ */

#define RSTCTL1_PRSTCTL0_FLEXCOMM0_RST_MASK      (0x100U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM0_RST_SHIFT     (8U)
/*! FLEXCOMM0_RST - FLEXCOMM0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM0_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM0_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM0_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM1_RST_MASK      (0x200U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM1_RST_SHIFT     (9U)
/*! FLEXCOMM1_RST - FLEXCOMM1 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM1_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM1_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM1_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM2_RST_MASK      (0x400U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM2_RST_SHIFT     (10U)
/*! FLEXCOMM2_RST - FLEXCOMM2 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM2_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM2_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM2_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM3_RST_MASK      (0x800U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM3_RST_SHIFT     (11U)
/*! FLEXCOMM3_RST - FLEXCOMM3 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM3_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM3_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM3_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM4_RST_MASK      (0x1000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM4_RST_SHIFT     (12U)
/*! FLEXCOMM4_RST - FLEXCOMM4 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM4_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM4_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM4_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM5_RST_MASK      (0x2000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM5_RST_SHIFT     (13U)
/*! FLEXCOMM5_RST - FLEXCOMM5 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM5_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM5_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM5_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM6_RST_MASK      (0x4000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM6_RST_SHIFT     (14U)
/*! FLEXCOMM6_RST - FLEXCOMM6 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM6_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM6_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM6_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM7_RST_MASK      (0x8000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM7_RST_SHIFT     (15U)
/*! FLEXCOMM7_RST - FLEXCOMM7 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM7_RST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM7_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM7_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM14_SPI_RST_MASK (0x400000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM14_SPI_RST_SHIFT (22U)
/*! FLEXCOMM14_SPI_RST - FLEXCOMM14 SPI reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM14_SPI_RST(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM14_SPI_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM14_SPI_RST_MASK)

#define RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_RST_MASK (0x800000U)
#define RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_RST_SHIFT (23U)
/*! FLEXCOMM15_I2C_RST - FLEXCOMM15 I2C reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_RST(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_RST_SHIFT)) & RSTCTL1_PRSTCTL0_FLEXCOMM15_I2C_RST_MASK)

#define RSTCTL1_PRSTCTL0_DMIC0_RST_MASK          (0x1000000U)
#define RSTCTL1_PRSTCTL0_DMIC0_RST_SHIFT         (24U)
/*! DMIC0_RST - DMIC0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_DMIC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_DMIC0_RST_SHIFT)) & RSTCTL1_PRSTCTL0_DMIC0_RST_MASK)

#define RSTCTL1_PRSTCTL0_OSEVT_TIMER_RST_MASK    (0x8000000U)
#define RSTCTL1_PRSTCTL0_OSEVT_TIMER_RST_SHIFT   (27U)
/*! OSEVT_TIMER_RST - osevent timer reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL0_OSEVT_TIMER_RST(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_OSEVT_TIMER_RST_SHIFT)) & RSTCTL1_PRSTCTL0_OSEVT_TIMER_RST_MASK)
/*! @} */

/*! @name PRSTCTL1 - peripheral reset control register 1 */
/*! @{ */

#define RSTCTL1_PRSTCTL1_HSGPIO0_RST_MASK        (0x1U)
#define RSTCTL1_PRSTCTL1_HSGPIO0_RST_SHIFT       (0U)
/*! HSGPIO0_RST - HSGPIO0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO0_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO0_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO0_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO1_RST_MASK        (0x2U)
#define RSTCTL1_PRSTCTL1_HSGPIO1_RST_SHIFT       (1U)
/*! HSGPIO1_RST - HSGPIO1 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO1_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO1_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO1_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO2_RST_MASK        (0x4U)
#define RSTCTL1_PRSTCTL1_HSGPIO2_RST_SHIFT       (2U)
/*! HSGPIO2_RST - HSGPIO2 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO2_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO2_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO2_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO3_RST_MASK        (0x8U)
#define RSTCTL1_PRSTCTL1_HSGPIO3_RST_SHIFT       (3U)
/*! HSGPIO3_RST - HSGPIO3 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO3_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO3_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO3_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO4_RST_MASK        (0x10U)
#define RSTCTL1_PRSTCTL1_HSGPIO4_RST_SHIFT       (4U)
/*! HSGPIO4_RST - HSGPIO4 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO4_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO4_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO4_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO5_RST_MASK        (0x20U)
#define RSTCTL1_PRSTCTL1_HSGPIO5_RST_SHIFT       (5U)
/*! HSGPIO5_RST - HSGPIO5 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO5_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO5_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO5_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO6_RST_MASK        (0x40U)
#define RSTCTL1_PRSTCTL1_HSGPIO6_RST_SHIFT       (6U)
/*! HSGPIO6_RST - HSGPIO6 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO6_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO6_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO6_RST_MASK)

#define RSTCTL1_PRSTCTL1_HSGPIO7_RST_MASK        (0x80U)
#define RSTCTL1_PRSTCTL1_HSGPIO7_RST_SHIFT       (7U)
/*! HSGPIO7_RST - HSGPIO7 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_HSGPIO7_RST(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_HSGPIO7_RST_SHIFT)) & RSTCTL1_PRSTCTL1_HSGPIO7_RST_MASK)

#define RSTCTL1_PRSTCTL1_CRC_RST_MASK            (0x10000U)
#define RSTCTL1_PRSTCTL1_CRC_RST_SHIFT           (16U)
/*! CRC_RST - CRC reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_CRC_RST(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CRC_RST_SHIFT)) & RSTCTL1_PRSTCTL1_CRC_RST_MASK)

#define RSTCTL1_PRSTCTL1_DMAC0_RST_MASK          (0x800000U)
#define RSTCTL1_PRSTCTL1_DMAC0_RST_SHIFT         (23U)
/*! DMAC0_RST - DMAC0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_DMAC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_DMAC0_RST_SHIFT)) & RSTCTL1_PRSTCTL1_DMAC0_RST_MASK)

#define RSTCTL1_PRSTCTL1_DMAC1_RST_MASK          (0x1000000U)
#define RSTCTL1_PRSTCTL1_DMAC1_RST_SHIFT         (24U)
/*! DMAC1_RST - DMAC1 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_DMAC1_RST(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_DMAC1_RST_SHIFT)) & RSTCTL1_PRSTCTL1_DMAC1_RST_MASK)

#define RSTCTL1_PRSTCTL1_MU_RST_MASK             (0x10000000U)
#define RSTCTL1_PRSTCTL1_MU_RST_SHIFT            (28U)
/*! MU_RST - MU reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_MU_RST(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_MU_RST_SHIFT)) & RSTCTL1_PRSTCTL1_MU_RST_MASK)

#define RSTCTL1_PRSTCTL1_SEMA_RST_MASK           (0x20000000U)
#define RSTCTL1_PRSTCTL1_SEMA_RST_SHIFT          (29U)
/*! SEMA_RST - SEMA reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_SEMA_RST(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SEMA_RST_SHIFT)) & RSTCTL1_PRSTCTL1_SEMA_RST_MASK)

#define RSTCTL1_PRSTCTL1_FREQME_RST_MASK         (0x80000000U)
#define RSTCTL1_PRSTCTL1_FREQME_RST_SHIFT        (31U)
/*! FREQME_RST - FREQME reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL1_FREQME_RST(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_FREQME_RST_SHIFT)) & RSTCTL1_PRSTCTL1_FREQME_RST_MASK)
/*! @} */

/*! @name PRSTCTL2 - peripheral reset control register 2 */
/*! @{ */

#define RSTCTL1_PRSTCTL2_CT32BIT0_RST_MASK       (0x1U)
#define RSTCTL1_PRSTCTL2_CT32BIT0_RST_SHIFT      (0U)
/*! CT32BIT0_RST - CT32BIT0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT0_RST(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT0_RST_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT0_RST_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT1_RST_MASK       (0x2U)
#define RSTCTL1_PRSTCTL2_CT32BIT1_RST_SHIFT      (1U)
/*! CT32BIT1_RST - CT32BIT1 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT1_RST(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT1_RST_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT1_RST_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT2_RST_MASK       (0x4U)
#define RSTCTL1_PRSTCTL2_CT32BIT2_RST_SHIFT      (2U)
/*! CT32BIT2_RST - CT32BIT2 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT2_RST(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT2_RST_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT2_RST_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT3_RST_MASK       (0x8U)
#define RSTCTL1_PRSTCTL2_CT32BIT3_RST_SHIFT      (3U)
/*! CT32BIT3_RST - CT32BIT3 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT3_RST(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT3_RST_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT3_RST_MASK)

#define RSTCTL1_PRSTCTL2_CT32BIT4_RST_MASK       (0x10U)
#define RSTCTL1_PRSTCTL2_CT32BIT4_RST_SHIFT      (4U)
/*! CT32BIT4_RST - CT32BIT4 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_CT32BIT4_RST(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CT32BIT4_RST_SHIFT)) & RSTCTL1_PRSTCTL2_CT32BIT4_RST_MASK)

#define RSTCTL1_PRSTCTL2_MRT0_RST_MASK           (0x100U)
#define RSTCTL1_PRSTCTL2_MRT0_RST_SHIFT          (8U)
/*! MRT0_RST - MRT0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_MRT0_RST(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_MRT0_RST_SHIFT)) & RSTCTL1_PRSTCTL2_MRT0_RST_MASK)

#define RSTCTL1_PRSTCTL2_WWDT1_RST_MASK          (0x400U)
#define RSTCTL1_PRSTCTL2_WWDT1_RST_SHIFT         (10U)
/*! WWDT1_RST - WWDT1 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_WWDT1_RST(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_WWDT1_RST_SHIFT)) & RSTCTL1_PRSTCTL2_WWDT1_RST_MASK)

#define RSTCTL1_PRSTCTL2_I3C0_RST_MASK           (0x10000U)
#define RSTCTL1_PRSTCTL2_I3C0_RST_SHIFT          (16U)
/*! I3C0_RST - I3C0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_I3C0_RST(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_I3C0_RST_SHIFT)) & RSTCTL1_PRSTCTL2_I3C0_RST_MASK)

#define RSTCTL1_PRSTCTL2_GPIOINTCTL_RST_MASK     (0x40000000U)
#define RSTCTL1_PRSTCTL2_GPIOINTCTL_RST_SHIFT    (30U)
/*! GPIOINTCTL_RST - GPIOINTCTL reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_GPIOINTCTL_RST(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_GPIOINTCTL_RST_SHIFT)) & RSTCTL1_PRSTCTL2_GPIOINTCTL_RST_MASK)

#define RSTCTL1_PRSTCTL2_PIMCTL_RST_MASK         (0x80000000U)
#define RSTCTL1_PRSTCTL2_PIMCTL_RST_SHIFT        (31U)
/*! PIMCTL_RST - PMC reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL1_PRSTCTL2_PIMCTL_RST(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_PIMCTL_RST_SHIFT)) & RSTCTL1_PRSTCTL2_PIMCTL_RST_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - peripheral reset set register 0 */
/*! @{ */

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_RST_SET_MASK (0x100U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_RST_SET_SHIFT (8U)
/*! FLEXCOMM0_RST_SET - FLEXCOMM0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_RST_SET_MASK (0x200U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_RST_SET_SHIFT (9U)
/*! FLEXCOMM1_RST_SET - FLEXCOMM1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM1_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_RST_SET_MASK (0x400U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_RST_SET_SHIFT (10U)
/*! FLEXCOMM2_RST_SET - FLEXCOMM2 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM2_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_RST_SET_MASK (0x800U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_RST_SET_SHIFT (11U)
/*! FLEXCOMM3_RST_SET - FLEXCOMM3 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM3_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_RST_SET_MASK (0x1000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_RST_SET_SHIFT (12U)
/*! FLEXCOMM4_RST_SET - FLEXCOMM4 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM4_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_RST_SET_MASK (0x2000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_RST_SET_SHIFT (13U)
/*! FLEXCOMM5_RST_SET - FLEXCOMM5 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM5_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_RST_SET_MASK (0x4000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_RST_SET_SHIFT (14U)
/*! FLEXCOMM6_RST_SET - FLEXCOMM6 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM6_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_RST_SET_MASK (0x8000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_RST_SET_SHIFT (15U)
/*! FLEXCOMM7_RST_SET - FLEXCOMM7 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM7_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SPI_RST_SET_MASK (0x400000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SPI_RST_SET_SHIFT (22U)
/*! FLEXCOMM14_SPI_RST_SET - FLEXCOMM14 SPI reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SPI_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SPI_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM14_SPI_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_RST_SET_MASK (0x800000U)
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_RST_SET_SHIFT (23U)
/*! FLEXCOMM15_I2C_RST_SET - FLEXCOMM15 I2C reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_FLEXCOMM15_I2C_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_DMIC0_RST_SET_MASK  (0x1000000U)
#define RSTCTL1_PRSTCTL0_SET_DMIC0_RST_SET_SHIFT (24U)
/*! DMIC0_RST_SET - DMIC0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_DMIC0_RST_SET(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_DMIC0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_DMIC0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL0_SET_OSEVT_TIMER_RST_SET_MASK (0x8000000U)
#define RSTCTL1_PRSTCTL0_SET_OSEVT_TIMER_RST_SET_SHIFT (27U)
/*! OSEVT_TIMER_RST_SET - osevent timer reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_SET_OSEVT_TIMER_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_OSEVT_TIMER_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL0_SET_OSEVT_TIMER_RST_SET_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - peripheral reset set register 1 */
/*! @{ */

#define RSTCTL1_PRSTCTL1_SET_HSGPIO0_RST_SET_MASK (0x1U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO0_RST_SET_SHIFT (0U)
/*! HSGPIO0_RST_SET - HSGPIO0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO0_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO1_RST_SET_MASK (0x2U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO1_RST_SET_SHIFT (1U)
/*! HSGPIO1_RST_SET - HSGPIO1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO1_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO1_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO1_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO2_RST_SET_MASK (0x4U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO2_RST_SET_SHIFT (2U)
/*! HSGPIO2_RST_SET - HSGPIO2 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO2_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO2_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO2_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO3_RST_SET_MASK (0x8U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO3_RST_SET_SHIFT (3U)
/*! HSGPIO3_RST_SET - HSGPIO3 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO3_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO3_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO3_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO4_RST_SET_MASK (0x10U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO4_RST_SET_SHIFT (4U)
/*! HSGPIO4_RST_SET - HSGPIO4 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO4_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO4_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO4_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO5_RST_SET_MASK (0x20U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO5_RST_SET_SHIFT (5U)
/*! HSGPIO5_RST_SET - HSGPIO5 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO5_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO5_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO5_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO6_RST_SET_MASK (0x40U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO6_RST_SET_SHIFT (6U)
/*! HSGPIO6_RST_SET - HSGPIO6 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO6_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO6_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO6_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_HSGPIO7_RST_SET_MASK (0x80U)
#define RSTCTL1_PRSTCTL1_SET_HSGPIO7_RST_SET_SHIFT (7U)
/*! HSGPIO7_RST_SET - HSGPIO7 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_HSGPIO7_RST_SET(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_HSGPIO7_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_HSGPIO7_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_CRC_RST_SET_MASK    (0x10000U)
#define RSTCTL1_PRSTCTL1_SET_CRC_RST_SET_SHIFT   (16U)
/*! CRC_RST_SET - CRC reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_CRC_RST_SET(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_CRC_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_CRC_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_DMAC0_RST_SET_MASK  (0x800000U)
#define RSTCTL1_PRSTCTL1_SET_DMAC0_RST_SET_SHIFT (23U)
/*! DMAC0_RST_SET - DMAC0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_DMAC0_RST_SET(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_DMAC0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_DMAC0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_DMAC1_RST_SET_MASK  (0x1000000U)
#define RSTCTL1_PRSTCTL1_SET_DMAC1_RST_SET_SHIFT (24U)
/*! DMAC1_RST_SET - DMAC1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_DMAC1_RST_SET(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_DMAC1_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_DMAC1_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_MU_RST_SET_MASK     (0x10000000U)
#define RSTCTL1_PRSTCTL1_SET_MU_RST_SET_SHIFT    (28U)
/*! MU_RST_SET - MU reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_MU_RST_SET(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_MU_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_MU_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_SEMA_RST_SET_MASK   (0x20000000U)
#define RSTCTL1_PRSTCTL1_SET_SEMA_RST_SET_SHIFT  (29U)
/*! SEMA_RST_SET - SEMA reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_SEMA_RST_SET(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_SEMA_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_SEMA_RST_SET_MASK)

#define RSTCTL1_PRSTCTL1_SET_FREQME_RST_SET_MASK (0x80000000U)
#define RSTCTL1_PRSTCTL1_SET_FREQME_RST_SET_SHIFT (31U)
/*! FREQME_RST_SET - FREQME reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_SET_FREQME_RST_SET(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_SET_FREQME_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL1_SET_FREQME_RST_SET_MASK)
/*! @} */

/*! @name PRSTCTL2_SET - peripheral reset set register 2 */
/*! @{ */

#define RSTCTL1_PRSTCTL2_SET_CT32BIT0_RST_SET_MASK (0x1U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT0_RST_SET_SHIFT (0U)
/*! CT32BIT0_RST_SET - CT32BIT0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT0_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT1_RST_SET_MASK (0x2U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT1_RST_SET_SHIFT (1U)
/*! CT32BIT1_RST_SET - CT32BIT1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT1_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT1_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT1_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT2_RST_SET_MASK (0x4U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT2_RST_SET_SHIFT (2U)
/*! CT32BIT2_RST_SET - CT32BIT2 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT2_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT2_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT2_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT3_RST_SET_MASK (0x8U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT3_RST_SET_SHIFT (3U)
/*! CT32BIT3_RST_SET - CT32BIT3 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT3_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT3_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT3_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_CT32BIT4_RST_SET_MASK (0x10U)
#define RSTCTL1_PRSTCTL2_SET_CT32BIT4_RST_SET_SHIFT (4U)
/*! CT32BIT4_RST_SET - CT32BIT4 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_CT32BIT4_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_CT32BIT4_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_CT32BIT4_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_MRT0_RST_SET_MASK   (0x100U)
#define RSTCTL1_PRSTCTL2_SET_MRT0_RST_SET_SHIFT  (8U)
/*! MRT0_RST_SET - MRT0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_MRT0_RST_SET(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_MRT0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_MRT0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_WWDT1_RST_SET_MASK  (0x400U)
#define RSTCTL1_PRSTCTL2_SET_WWDT1_RST_SET_SHIFT (10U)
/*! WWDT1_RST_SET - WWDT1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_WWDT1_RST_SET(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_WWDT1_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_WWDT1_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_I3C0_RST_SET_MASK   (0x10000U)
#define RSTCTL1_PRSTCTL2_SET_I3C0_RST_SET_SHIFT  (16U)
/*! I3C0_RST_SET - I3C0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_I3C0_RST_SET(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_I3C0_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_I3C0_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_RST_SET_MASK (0x40000000U)
#define RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_RST_SET_SHIFT (30U)
/*! GPIOINTCTL_RST_SET - GPIOINTCTL reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_RST_SET(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_GPIOINTCTL_RST_SET_MASK)

#define RSTCTL1_PRSTCTL2_SET_PIMCTL_RST_SET_MASK (0x80000000U)
#define RSTCTL1_PRSTCTL2_SET_PIMCTL_RST_SET_SHIFT (31U)
/*! PIMCTL_RST_SET - PMC reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_SET_PIMCTL_RST_SET(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_SET_PIMCTL_RST_SET_SHIFT)) & RSTCTL1_PRSTCTL2_SET_PIMCTL_RST_SET_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - peripheral reset clear register 0 */
/*! @{ */

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_RST_CLR_MASK (0x100U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_RST_CLR_SHIFT (8U)
/*! FLEXCOMM0_RST_CLR - FLEXCOMM0 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_RST_CLR_MASK (0x200U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_RST_CLR_SHIFT (9U)
/*! FLEXCOMM1_RST_CLR - FLEXCOMM1 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM1_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_RST_CLR_MASK (0x400U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_RST_CLR_SHIFT (10U)
/*! FLEXCOMM2_RST_CLR - FLEXCOMM2 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM2_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_RST_CLR_MASK (0x800U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_RST_CLR_SHIFT (11U)
/*! FLEXCOMM3_RST_CLR - FLEXCOMM3 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM3_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_RST_CLR_MASK (0x1000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_RST_CLR_SHIFT (12U)
/*! FLEXCOMM4_RST_CLR - FLEXCOMM4 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM4_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_RST_CLR_MASK (0x2000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_RST_CLR_SHIFT (13U)
/*! FLEXCOMM5_RST_CLR - FLEXCOMM5 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM5_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_RST_CLR_MASK (0x4000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_RST_CLR_SHIFT (14U)
/*! FLEXCOMM6_RST_CLR - FLEXCOMM6 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM6_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_RST_CLR_MASK (0x8000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_RST_CLR_SHIFT (15U)
/*! FLEXCOMM7_RST_CLR - FLEXCOMM7 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM7_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SPI_RST_CLR_MASK (0x400000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SPI_RST_CLR_SHIFT (22U)
/*! FLEXCOMM14_SPI_RST_CLR - FLEXCOMM14 SPI reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SPI_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SPI_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM14_SPI_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_RST_CLR_MASK (0x800000U)
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_RST_CLR_SHIFT (23U)
/*! FLEXCOMM15_I2C_RST_CLR - FLEXCOMM15 I2C reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_FLEXCOMM15_I2C_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_DMIC0_RST_CLR_MASK  (0x1000000U)
#define RSTCTL1_PRSTCTL0_CLR_DMIC0_RST_CLR_SHIFT (24U)
/*! DMIC0_RST_CLR - DMIC0 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_DMIC0_RST_CLR(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_DMIC0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_DMIC0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL0_CLR_OSEVT_TIMER_RST_CLR_MASK (0x8000000U)
#define RSTCTL1_PRSTCTL0_CLR_OSEVT_TIMER_RST_CLR_SHIFT (27U)
/*! OSEVT_TIMER_RST_CLR - osevent timer reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL0 Bit
 */
#define RSTCTL1_PRSTCTL0_CLR_OSEVT_TIMER_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_OSEVT_TIMER_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_OSEVT_TIMER_RST_CLR_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - peripheral reset clear register 1 */
/*! @{ */

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO0_RST_CLR_MASK (0x1U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO0_RST_CLR_SHIFT (0U)
/*! HSGPIO0_RST_CLR - HSGPIO0 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO0_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO1_RST_CLR_MASK (0x2U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO1_RST_CLR_SHIFT (1U)
/*! HSGPIO1_RST_CLR - HSGPIO1 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO1_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO1_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO1_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO2_RST_CLR_MASK (0x4U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO2_RST_CLR_SHIFT (2U)
/*! HSGPIO2_RST_CLR - HSGPIO2 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO2_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO2_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO2_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO3_RST_CLR_MASK (0x8U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO3_RST_CLR_SHIFT (3U)
/*! HSGPIO3_RST_CLR - HSGPIO3 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO3_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO3_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO3_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO4_RST_CLR_MASK (0x10U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO4_RST_CLR_SHIFT (4U)
/*! HSGPIO4_RST_CLR - HSGPIO4 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO4_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO4_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO4_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO5_RST_CLR_MASK (0x20U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO5_RST_CLR_SHIFT (5U)
/*! HSGPIO5_RST_CLR - HSGPIO5 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO5_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO5_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO5_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO6_RST_CLR_MASK (0x40U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO6_RST_CLR_SHIFT (6U)
/*! HSGPIO6_RST_CLR - HSGPIO6 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO6_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO6_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO6_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_HSGPIO7_RST_CLR_MASK (0x80U)
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO7_RST_CLR_SHIFT (7U)
/*! HSGPIO7_RST_CLR - HSGPIO7 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_HSGPIO7_RST_CLR(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_HSGPIO7_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_HSGPIO7_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_CRC_RST_CLR_MASK    (0x10000U)
#define RSTCTL1_PRSTCTL1_CLR_CRC_RST_CLR_SHIFT   (16U)
/*! CRC_RST_CLR - CRC reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_CRC_RST_CLR(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_CRC_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_CRC_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_DMAC0_RST_CLR_MASK  (0x800000U)
#define RSTCTL1_PRSTCTL1_CLR_DMAC0_RST_CLR_SHIFT (23U)
/*! DMAC0_RST_CLR - DMAC0 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_DMAC0_RST_CLR(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_DMAC0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_DMAC0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_DMAC1_RST_CLR_MASK  (0x1000000U)
#define RSTCTL1_PRSTCTL1_CLR_DMAC1_RST_CLR_SHIFT (24U)
/*! DMAC1_RST_CLR - DMAC1 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_DMAC1_RST_CLR(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_DMAC1_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_DMAC1_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_MU_RST_CLR_MASK     (0x10000000U)
#define RSTCTL1_PRSTCTL1_CLR_MU_RST_CLR_SHIFT    (28U)
/*! MU_RST_CLR - MU reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_MU_RST_CLR(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_MU_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_MU_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_SEMA_RST_CLR_MASK   (0x20000000U)
#define RSTCTL1_PRSTCTL1_CLR_SEMA_RST_CLR_SHIFT  (29U)
/*! SEMA_RST_CLR - SEMA reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_SEMA_RST_CLR(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_SEMA_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_SEMA_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL1_CLR_FREQME_RST_CLR_MASK (0x80000000U)
#define RSTCTL1_PRSTCTL1_CLR_FREQME_RST_CLR_SHIFT (31U)
/*! FREQME_RST_CLR - FREQME reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL1 Bit
 */
#define RSTCTL1_PRSTCTL1_CLR_FREQME_RST_CLR(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL1_CLR_FREQME_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL1_CLR_FREQME_RST_CLR_MASK)
/*! @} */

/*! @name PRSTCTL2_CLR - peripheral reset clear register 2 */
/*! @{ */

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT0_RST_CLR_MASK (0x1U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT0_RST_CLR_SHIFT (0U)
/*! CT32BIT0_RST_CLR - CT32BIT0 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT0_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT1_RST_CLR_MASK (0x2U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT1_RST_CLR_SHIFT (1U)
/*! CT32BIT1_RST_CLR - CT32BIT1 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT1_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT1_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT1_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT2_RST_CLR_MASK (0x4U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT2_RST_CLR_SHIFT (2U)
/*! CT32BIT2_RST_CLR - CT32BIT2 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT2_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT2_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT2_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT3_RST_CLR_MASK (0x8U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT3_RST_CLR_SHIFT (3U)
/*! CT32BIT3_RST_CLR - CT32BIT3 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT3_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT3_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT3_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_CT32BIT4_RST_CLR_MASK (0x10U)
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT4_RST_CLR_SHIFT (4U)
/*! CT32BIT4_RST_CLR - CT32BIT4 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_CT32BIT4_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_CT32BIT4_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_CT32BIT4_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_MRT0_RST_CLR_MASK   (0x100U)
#define RSTCTL1_PRSTCTL2_CLR_MRT0_RST_CLR_SHIFT  (8U)
/*! MRT0_RST_CLR - MRT0 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_MRT0_RST_CLR(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_MRT0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_MRT0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_WWDT1_RST_CLR_MASK  (0x400U)
#define RSTCTL1_PRSTCTL2_CLR_WWDT1_RST_CLR_SHIFT (10U)
/*! WWDT1_RST_CLR - WWDT1 reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_WWDT1_RST_CLR(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_WWDT1_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_WWDT1_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_I3C0_RST_CLR_MASK   (0x10000U)
#define RSTCTL1_PRSTCTL2_CLR_I3C0_RST_CLR_SHIFT  (16U)
/*! I3C0_RST_CLR - I3C0 reset clear
 *  0b1..Sets the PRSTCTL2 Bit
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_I3C0_RST_CLR(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_I3C0_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_I3C0_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_RST_CLR_MASK (0x40000000U)
#define RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_RST_CLR_SHIFT (30U)
/*! GPIOINTCTL_RST_CLR - GPIOINTCTL reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_RST_CLR(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_GPIOINTCTL_RST_CLR_MASK)

#define RSTCTL1_PRSTCTL2_CLR_PIMCTL_RST_CLR_MASK (0x80000000U)
#define RSTCTL1_PRSTCTL2_CLR_PIMCTL_RST_CLR_SHIFT (31U)
/*! PIMCTL_RST_CLR - PMC reset clear
 *  0b0..No Effect
 *  0b1..clears the PRSTCTL2 Bit
 */
#define RSTCTL1_PRSTCTL2_CLR_PIMCTL_RST_CLR(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL2_CLR_PIMCTL_RST_CLR_SHIFT)) & RSTCTL1_PRSTCTL2_CLR_PIMCTL_RST_CLR_MASK)
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

