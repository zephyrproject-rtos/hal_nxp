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
**         CMSIS Peripheral Access Layer for CLKCTL1
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
 * @file PERI_CLKCTL1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL1
 *
 * CMSIS Peripheral Access Layer for CLKCTL1
 */

#if !defined(PERI_CLKCTL1_H_)
#define PERI_CLKCTL1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL1_Peripheral_Access_Layer CLKCTL1 Peripheral Access Layer
 * @{
 */

/** CLKCTL1 - Size of Registers Arrays */
#define CLKCTL1_FLEXCOMM_COUNT                    8u
#define CLKCTL1_CT32BITFCLKSEL_COUNT              5u

/** CLKCTL1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0;                           /**< clock control register 0, offset: 0x10 */
  __IO uint32_t PSCCTL1;                           /**< clock control register 1, offset: 0x14 */
  __IO uint32_t PSCCTL2;                           /**< clock control register 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __O  uint32_t PSCCTL0_SET;                       /**< clock set register 0, offset: 0x40 */
  __O  uint32_t PSCCTL1_SET;                       /**< clock set register 1, offset: 0x44 */
  __O  uint32_t PSCCTL2_SET;                       /**< clock set register 2, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __O  uint32_t PSCCTL0_CLR;                       /**< clock clear register 0, offset: 0x70 */
  __O  uint32_t PSCCTL1_CLR;                       /**< clock clear register 1, offset: 0x74 */
  __O  uint32_t PSCCTL2_CLR;                       /**< clock clear register 2, offset: 0x78 */
       uint8_t RESERVED_3[388];
  __IO uint32_t AUDIOPLL0CLKSEL;                   /**< audio pll0 clock selection, offset: 0x200 */
  __IO uint32_t AUDIOPLL0CTL0;                     /**< audio pll0 control0, offset: 0x204 */
       uint8_t RESERVED_4[4];
  __IO uint32_t AUDIOPLL0LOCKTIMEDIV2;             /**< audio pll0 lock time, offset: 0x20C */
  __IO uint32_t AUDIOPLL0NUM;                      /**< audio pll0 number, offset: 0x210 */
  __IO uint32_t AUDIOPLL0DENOM;                    /**< Audio pll0 denom, offset: 0x214 */
  __IO uint32_t AUDIOPLL0PFD;                      /**< audio pll0 PFD, offset: 0x218 */
       uint8_t RESERVED_5[36];
  __IO uint32_t AUDIOPLLCLKDIV;                    /**< audio pll0 clock divider, offset: 0x240 */
       uint8_t RESERVED_6[444];
  __IO uint32_t DSPCPUCLKDIV;                      /**< DSP cpu clock divider, offset: 0x400 */
  __IO uint32_t DSPMAINRAMCLKDIV;                  /**< DSP main ram clock divider, offset: 0x404 */
       uint8_t RESERVED_7[40];
  __IO uint32_t DSPCPUCLKSELA;                     /**< DSP clock selection A, offset: 0x430 */
  __IO uint32_t DSPCPUCLKSELB;                     /**< DSP clock selection B, offset: 0x434 */
       uint8_t RESERVED_8[72];
  __IO uint32_t OSEVENTFCLKSEL;                    /**< OS EVENT clock selection, offset: 0x480 */
       uint8_t RESERVED_9[124];
  struct {                                         /* offset: 0x500, array step: 0x20 */
    __IO uint32_t FRGCLKSEL;                         /**< FRG clock selection register N, array offset: 0x500, array step: 0x20 */
    __IO uint32_t FRGCTL;                            /**< FRG clock controller, array offset: 0x504, array step: 0x20 */
    __IO uint32_t FCFCLKSEL;                         /**< flexcomm clock selection, array offset: 0x508, array step: 0x20 */
         uint8_t RESERVED_0[20];
  } FLEXCOMM[CLKCTL1_FLEXCOMM_COUNT];
       uint8_t RESERVED_10[192];
  __IO uint32_t FRG14CLKSEL;                       /**< FRG clock selection register 14, offset: 0x6C0 */
  __IO uint32_t FRG14CTL;                          /**< FRG clock controller 14, offset: 0x6C4 */
  __IO uint32_t FC14FCLKSEL;                       /**< flexcomm14 clock selection, offset: 0x6C8 */
       uint8_t RESERVED_11[20];
  __IO uint32_t FRG15CLKSEL;                       /**< FRG clock selection register 15, offset: 0x6E0 */
  __IO uint32_t FRG15CTL;                          /**< FRG clock controller 15, offset: 0x6E4 */
  __IO uint32_t FC15FCLKSEL;                       /**< flexcomm15 clock selection, offset: 0x6E8 */
       uint8_t RESERVED_12[16];
  __IO uint32_t FRGPLLCLKDIV;                      /**< FRG pll clock divider, offset: 0x6FC */
  __IO uint32_t DMIC0FCLKSEL;                      /**< DMIC0 clk selection, offset: 0x700 */
  __IO uint32_t DMIC0FCLKDIV;                      /**< DMIC clock clock divider, offset: 0x704 */
       uint8_t RESERVED_13[24];
  __IO uint32_t CT32BITFCLKSEL[CLKCTL1_CT32BITFCLKSEL_COUNT]; /**< ct32bit timer N clock selection, array offset: 0x720, array step: 0x4 */
       uint8_t RESERVED_14[12];
  __IO uint32_t AUDIOMCLKSEL;                      /**< audio mclock selection, offset: 0x740 */
  __IO uint32_t AUDIOMCLKDIV;                      /**< audio mclock divider, offset: 0x744 */
       uint8_t RESERVED_15[24];
  __IO uint32_t CLKOUTSEL0;                        /**< clock out selection 0, offset: 0x760 */
  __IO uint32_t CLKOUTSEL1;                        /**< clock out selection 1, offset: 0x764 */
  __IO uint32_t CLKOUTDIV;                         /**< clock_out divider, offset: 0x768 */
       uint8_t RESERVED_16[20];
  __IO uint32_t I3C0FCLKSEL;                       /**< I3C0 fclk selection, offset: 0x780 */
  __IO uint32_t I3C0FCLKSTCSEL;                    /**< I3C0 fclk STC selection, offset: 0x784 */
  __IO uint32_t I3C0FCLKSTCDIV;                    /**< I3C0 fclk STC divider, offset: 0x788 */
  __IO uint32_t I3C0FCLKSDIV;                      /**< I3C0 fclks divider, offset: 0x78C */
  __IO uint32_t I3C0FCLKDIV;                       /**< I3C0 fclk divider, offset: 0x790 */
       uint8_t RESERVED_17[12];
  __IO uint32_t WDT1FCLKSEL;                       /**< WDT1 clock selection, offset: 0x7A0 */
       uint8_t RESERVED_18[28];
  __IO uint32_t ACMP0FCLKSEL;                      /**< acomparator 0 clock selection, offset: 0x7C0 */
  __IO uint32_t ACMP0FCLKDIV;                      /**< acomparator 0 fclk divider, offset: 0x7C4 */
} CLKCTL1_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL1_Register_Masks CLKCTL1 Register Masks
 * @{
 */

/*! @name PSCCTL0 - clock control register 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_FC0_CLK_MASK             (0x100U)
#define CLKCTL1_PSCCTL0_FC0_CLK_SHIFT            (8U)
/*! FC0_CLK - flexcomm 0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC0_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC0_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC0_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC1_CLK_MASK             (0x200U)
#define CLKCTL1_PSCCTL0_FC1_CLK_SHIFT            (9U)
/*! FC1_CLK - flexcomm 1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC1_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC1_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC1_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC2_CLK_MASK             (0x400U)
#define CLKCTL1_PSCCTL0_FC2_CLK_SHIFT            (10U)
/*! FC2_CLK - flexcomm 2 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC2_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC2_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC2_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC3_CLK_MASK             (0x800U)
#define CLKCTL1_PSCCTL0_FC3_CLK_SHIFT            (11U)
/*! FC3_CLK - flexcomm 3 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC3_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC3_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC3_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC4_CLK_MASK             (0x1000U)
#define CLKCTL1_PSCCTL0_FC4_CLK_SHIFT            (12U)
/*! FC4_CLK - flexcomm 4 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC4_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC4_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC4_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC5_CLK_MASK             (0x2000U)
#define CLKCTL1_PSCCTL0_FC5_CLK_SHIFT            (13U)
/*! FC5_CLK - flexcomm 5 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC5_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC5_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC5_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC6_CLK_MASK             (0x4000U)
#define CLKCTL1_PSCCTL0_FC6_CLK_SHIFT            (14U)
/*! FC6_CLK - flexcomm 6 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC6_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC6_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC6_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC7_CLK_MASK             (0x8000U)
#define CLKCTL1_PSCCTL0_FC7_CLK_SHIFT            (15U)
/*! FC7_CLK - flexcomm 7 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC7_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC7_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC7_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC14_SPI_CLK_MASK        (0x400000U)
#define CLKCTL1_PSCCTL0_FC14_SPI_CLK_SHIFT       (22U)
/*! FC14_SPI_CLK - flexcomm 14 spi clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC14_SPI_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC14_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC14_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC15_I2C_CLK_MASK        (0x800000U)
#define CLKCTL1_PSCCTL0_FC15_I2C_CLK_SHIFT       (23U)
/*! FC15_I2C_CLK - flexcomm 15 i2c clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC15_I2C_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC15_I2C_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC15_I2C_CLK_MASK)

#define CLKCTL1_PSCCTL0_DMIC0_CLK_MASK           (0x1000000U)
#define CLKCTL1_PSCCTL0_DMIC0_CLK_SHIFT          (24U)
/*! DMIC0_CLK - DMIC0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_DMIC0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_DMIC0_CLK_SHIFT)) & CLKCTL1_PSCCTL0_DMIC0_CLK_MASK)

#define CLKCTL1_PSCCTL0_OSEVENT_TIMER_CLK_MASK   (0x8000000U)
#define CLKCTL1_PSCCTL0_OSEVENT_TIMER_CLK_SHIFT  (27U)
/*! OSEVENT_TIMER_CLK - OS event timer clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_OSEVENT_TIMER_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_OSEVENT_TIMER_CLK_SHIFT)) & CLKCTL1_PSCCTL0_OSEVENT_TIMER_CLK_MASK)
/*! @} */

/*! @name PSCCTL1 - clock control register 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_HSGPIO0_CLK_MASK         (0x1U)
#define CLKCTL1_PSCCTL1_HSGPIO0_CLK_SHIFT        (0U)
/*! HSGPIO0_CLK - HSGPIO0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO0_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO0_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO1_CLK_MASK         (0x2U)
#define CLKCTL1_PSCCTL1_HSGPIO1_CLK_SHIFT        (1U)
/*! HSGPIO1_CLK - HSGPIO1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO1_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO1_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO2_CLK_MASK         (0x4U)
#define CLKCTL1_PSCCTL1_HSGPIO2_CLK_SHIFT        (2U)
/*! HSGPIO2_CLK - HSGPIO2 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO2_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO2_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO2_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO3_CLK_MASK         (0x8U)
#define CLKCTL1_PSCCTL1_HSGPIO3_CLK_SHIFT        (3U)
/*! HSGPIO3_CLK - HSGPIO3 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO3_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO3_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO3_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO4_CLK_MASK         (0x10U)
#define CLKCTL1_PSCCTL1_HSGPIO4_CLK_SHIFT        (4U)
/*! HSGPIO4_CLK - HSGPIO4 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO4_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO4_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO4_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO5_CLK_MASK         (0x20U)
#define CLKCTL1_PSCCTL1_HSGPIO5_CLK_SHIFT        (5U)
/*! HSGPIO5_CLK - HSGPIO5 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO5_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO5_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO5_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO6_CLK_MASK         (0x40U)
#define CLKCTL1_PSCCTL1_HSGPIO6_CLK_SHIFT        (6U)
/*! HSGPIO6_CLK - HSGPIO6 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO6_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO6_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO6_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO7_CLK_MASK         (0x80U)
#define CLKCTL1_PSCCTL1_HSGPIO7_CLK_SHIFT        (7U)
/*! HSGPIO7_CLK - HSGPIO7 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO7_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO7_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO7_CLK_MASK)

#define CLKCTL1_PSCCTL1_CRC_CLK_MASK             (0x10000U)
#define CLKCTL1_PSCCTL1_CRC_CLK_SHIFT            (16U)
/*! CRC_CLK - CRC clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_CRC_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CRC_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CRC_CLK_MASK)

#define CLKCTL1_PSCCTL1_DMAC0_CLK_MASK           (0x800000U)
#define CLKCTL1_PSCCTL1_DMAC0_CLK_SHIFT          (23U)
/*! DMAC0_CLK - DMAC0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_DMAC0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_DMAC0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_DMAC0_CLK_MASK)

#define CLKCTL1_PSCCTL1_DMAC1_CLK_MASK           (0x1000000U)
#define CLKCTL1_PSCCTL1_DMAC1_CLK_SHIFT          (24U)
/*! DMAC1_CLK - DMAC1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_DMAC1_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_DMAC1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_DMAC1_CLK_MASK)

#define CLKCTL1_PSCCTL1_MU_CLK_MASK              (0x10000000U)
#define CLKCTL1_PSCCTL1_MU_CLK_SHIFT             (28U)
/*! MU_CLK - MU clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_MU_CLK(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_MU_CLK_SHIFT)) & CLKCTL1_PSCCTL1_MU_CLK_MASK)

#define CLKCTL1_PSCCTL1_SEMA_CLK_MASK            (0x20000000U)
#define CLKCTL1_PSCCTL1_SEMA_CLK_SHIFT           (29U)
/*! SEMA_CLK - SEMA clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_SEMA_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SEMA_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SEMA_CLK_MASK)

#define CLKCTL1_PSCCTL1_FREQME_CLK_MASK          (0x80000000U)
#define CLKCTL1_PSCCTL1_FREQME_CLK_SHIFT         (31U)
/*! FREQME_CLK - FREQME clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_FREQME_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_FREQME_CLK_SHIFT)) & CLKCTL1_PSCCTL1_FREQME_CLK_MASK)
/*! @} */

/*! @name PSCCTL2 - clock control register 2 */
/*! @{ */

#define CLKCTL1_PSCCTL2_CT32BIT0_CLK_MASK        (0x1U)
#define CLKCTL1_PSCCTL2_CT32BIT0_CLK_SHIFT       (0U)
/*! CT32BIT0_CLK - ct32bit timer 0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT1_CLK_MASK        (0x2U)
#define CLKCTL1_PSCCTL2_CT32BIT1_CLK_SHIFT       (1U)
/*! CT32BIT1_CLK - ct32bit timer 1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT1_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT2_CLK_MASK        (0x4U)
#define CLKCTL1_PSCCTL2_CT32BIT2_CLK_SHIFT       (2U)
/*! CT32BIT2_CLK - ct32bit timer 2 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT2_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT2_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT2_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT3_CLK_MASK        (0x8U)
#define CLKCTL1_PSCCTL2_CT32BIT3_CLK_SHIFT       (3U)
/*! CT32BIT3_CLK - ct32bit timer 3 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT3_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT3_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT3_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT4_CLK_MASK        (0x10U)
#define CLKCTL1_PSCCTL2_CT32BIT4_CLK_SHIFT       (4U)
/*! CT32BIT4_CLK - ct32bit timer 4 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT4_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT4_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT4_CLK_MASK)

#define CLKCTL1_PSCCTL2_RTC_LITE_CLK_MASK        (0x80U)
#define CLKCTL1_PSCCTL2_RTC_LITE_CLK_SHIFT       (7U)
/*! RTC_LITE_CLK - rtc lite clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_RTC_LITE_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_RTC_LITE_CLK_SHIFT)) & CLKCTL1_PSCCTL2_RTC_LITE_CLK_MASK)

#define CLKCTL1_PSCCTL2_MRT0_CLK_MASK            (0x100U)
#define CLKCTL1_PSCCTL2_MRT0_CLK_SHIFT           (8U)
/*! MRT0_CLK - mrt0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_MRT0_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_MRT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_MRT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_WWDT1_CLK_MASK           (0x400U)
#define CLKCTL1_PSCCTL2_WWDT1_CLK_SHIFT          (10U)
/*! WWDT1_CLK - wdt1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_WWDT1_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_WWDT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_WWDT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_I3C0_CLK_MASK            (0x10000U)
#define CLKCTL1_PSCCTL2_I3C0_CLK_SHIFT           (16U)
/*! I3C0_CLK - i3c0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_I3C0_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_I3C0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_I3C0_CLK_MASK)

#define CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_MASK      (0x40000000U)
#define CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_SHIFT     (30U)
/*! GPIOINTCTL_CLK - GPIOINTCTL clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_GPIOINTCTL_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_MASK)

#define CLKCTL1_PSCCTL2_PIMCTL_CLK_MASK          (0x80000000U)
#define CLKCTL1_PSCCTL2_PIMCTL_CLK_SHIFT         (31U)
/*! PIMCTL_CLK - PIMCTL clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_PIMCTL_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_PIMCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_PIMCTL_CLK_MASK)
/*! @} */

/*! @name PSCCTL0_SET - clock set register 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_SET_FC0_CLK_SET_MASK     (0x100U)
#define CLKCTL1_PSCCTL0_SET_FC0_CLK_SET_SHIFT    (8U)
/*! FC0_CLK_SET - flexcomm 0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC0_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC1_CLK_SET_MASK     (0x200U)
#define CLKCTL1_PSCCTL0_SET_FC1_CLK_SET_SHIFT    (9U)
/*! FC1_CLK_SET - flexcomm 1 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC1_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC1_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC1_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC2_CLK_SET_MASK     (0x400U)
#define CLKCTL1_PSCCTL0_SET_FC2_CLK_SET_SHIFT    (10U)
/*! FC2_CLK_SET - flexcomm 2 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC2_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC2_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC2_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC3_CLK_SET_MASK     (0x800U)
#define CLKCTL1_PSCCTL0_SET_FC3_CLK_SET_SHIFT    (11U)
/*! FC3_CLK_SET - flexcomm 3 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC3_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC3_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC3_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC4_CLK_SET_MASK     (0x1000U)
#define CLKCTL1_PSCCTL0_SET_FC4_CLK_SET_SHIFT    (12U)
/*! FC4_CLK_SET - flexcomm 4 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC4_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC4_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC4_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC5_CLK_SET_MASK     (0x2000U)
#define CLKCTL1_PSCCTL0_SET_FC5_CLK_SET_SHIFT    (13U)
/*! FC5_CLK_SET - flexcomm 5 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC5_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC5_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC5_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC6_CLK_SET_MASK     (0x4000U)
#define CLKCTL1_PSCCTL0_SET_FC6_CLK_SET_SHIFT    (14U)
/*! FC6_CLK_SET - flexcomm 6 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC6_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC6_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC6_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC7_CLK_SET_MASK     (0x8000U)
#define CLKCTL1_PSCCTL0_SET_FC7_CLK_SET_SHIFT    (15U)
/*! FC7_CLK_SET - flexcomm 7 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC7_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC7_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC7_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SET_MASK (0x400000U)
#define CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SET_SHIFT (22U)
/*! FC14_SPI_CLK_SET - flexcomm 14 spi clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SET_MASK (0x800000U)
#define CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SET_SHIFT (23U)
/*! FC15_I2C_CLK_SET - flexcomm 15 i2c clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_DMIC0_CLK_SET_MASK   (0x1000000U)
#define CLKCTL1_PSCCTL0_SET_DMIC0_CLK_SET_SHIFT  (24U)
/*! DMIC0_CLK_SET - DMIC0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_DMIC0_CLK_SET(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_DMIC0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_DMIC0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_CLK_SET_MASK (0x8000000U)
#define CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_CLK_SET_SHIFT (27U)
/*! OSEVENT_TIMER_CLK_SET - OS event timer clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_CLK_SET(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_CLK_SET_MASK)
/*! @} */

/*! @name PSCCTL1_SET - clock set register 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SET_MASK (0x1U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SET_SHIFT (0U)
/*! HSGPIO0_CLK_SET - HSGPIO0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SET_MASK (0x2U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SET_SHIFT (1U)
/*! HSGPIO1_CLK_SET - HSGPIO1 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SET_MASK (0x4U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SET_SHIFT (2U)
/*! HSGPIO2_CLK_SET - HSGPIO2 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SET_MASK (0x8U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SET_SHIFT (3U)
/*! HSGPIO3_CLK_SET - HSGPIO3 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SET_MASK (0x10U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SET_SHIFT (4U)
/*! HSGPIO4_CLK_SET - HSGPIO4 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SET_MASK (0x20U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SET_SHIFT (5U)
/*! HSGPIO5_CLK_SET - HSGPIO5 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SET_MASK (0x40U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SET_SHIFT (6U)
/*! HSGPIO6_CLK_SET - HSGPIO6 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SET_MASK (0x80U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SET_SHIFT (7U)
/*! HSGPIO7_CLK_SET - HSGPIO7 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SET(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_CRC_CLK_SET_MASK     (0x10000U)
#define CLKCTL1_PSCCTL1_SET_CRC_CLK_SET_SHIFT    (16U)
/*! CRC_CLK_SET - CRC clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_CRC_CLK_SET(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CRC_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_CRC_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SET_MASK   (0x800000U)
#define CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SET_SHIFT  (23U)
/*! DMAC0_CLK_SET - DMAC0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SET(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SET_MASK   (0x1000000U)
#define CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SET_SHIFT  (24U)
/*! DMAC1_CLK_SET - DMAC1 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SET(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_MU_CLK_SET_MASK      (0x10000000U)
#define CLKCTL1_PSCCTL1_SET_MU_CLK_SET_SHIFT     (28U)
/*! MU_CLK_SET - MU clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_MU_CLK_SET(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_MU_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_MU_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_SEMA_CLK_SET_MASK    (0x20000000U)
#define CLKCTL1_PSCCTL1_SET_SEMA_CLK_SET_SHIFT   (29U)
/*! SEMA_CLK_SET - SEMA clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_SEMA_CLK_SET(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_SEMA_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_SEMA_CLK_SET_MASK)

#define CLKCTL1_PSCCTL1_SET_FREQME_CLK_SET_MASK  (0x80000000U)
#define CLKCTL1_PSCCTL1_SET_FREQME_CLK_SET_SHIFT (31U)
/*! FREQME_CLK_SET - FREQME clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_SET_FREQME_CLK_SET(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_FREQME_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL1_SET_FREQME_CLK_SET_MASK)
/*! @} */

/*! @name PSCCTL2_SET - clock set register 2 */
/*! @{ */

#define CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SET_MASK (0x1U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SET_SHIFT (0U)
/*! CT32BIT0_CLK_SET - ct32bit timer 0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SET_MASK (0x2U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SET_SHIFT (1U)
/*! CT32BIT1_CLK_SET - ct32bit timer 1 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SET_MASK (0x4U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SET_SHIFT (2U)
/*! CT32BIT2_CLK_SET - ct32bit timer 2 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SET_MASK (0x8U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SET_SHIFT (3U)
/*! CT32BIT3_CLK_SET - ct32bit timer 3 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SET_MASK (0x10U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SET_SHIFT (4U)
/*! CT32BIT4_CLK_SET - ct32bit timer 4 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_RTC_LITE_CLK_SET_MASK (0x80U)
#define CLKCTL1_PSCCTL2_SET_RTC_LITE_CLK_SET_SHIFT (7U)
/*! RTC_LITE_CLK_SET - rtc lite clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_RTC_LITE_CLK_SET(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_RTC_LITE_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_RTC_LITE_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_MRT0_CLK_SET_MASK    (0x100U)
#define CLKCTL1_PSCCTL2_SET_MRT0_CLK_SET_SHIFT   (8U)
/*! MRT0_CLK_SET - mrt0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_MRT0_CLK_SET(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_MRT0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_MRT0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SET_MASK   (0x400U)
#define CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SET_SHIFT  (10U)
/*! WWDT1_CLK_SET - wdt1 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SET(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_I3C0_CLK_SET_MASK    (0x10000U)
#define CLKCTL1_PSCCTL2_SET_I3C0_CLK_SET_SHIFT   (16U)
/*! I3C0_CLK_SET - i3c0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_I3C0_CLK_SET(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_I3C0_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_I3C0_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SET_MASK (0x40000000U)
#define CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SET_SHIFT (30U)
/*! GPIOINTCTL_CLK_SET - GPIOINTCTL clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SET(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SET_MASK)

#define CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SET_MASK  (0x80000000U)
#define CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SET_SHIFT (31U)
/*! PIMCTL_CLK_SET - PIMCTL clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SET(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SET_SHIFT)) & CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SET_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - clock clear register 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_CLR_FC0_CLK_CLR_MASK     (0x100U)
#define CLKCTL1_PSCCTL0_CLR_FC0_CLK_CLR_SHIFT    (8U)
/*! FC0_CLK_CLR - flexcomm 0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC0_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC1_CLK_CLR_MASK     (0x200U)
#define CLKCTL1_PSCCTL0_CLR_FC1_CLK_CLR_SHIFT    (9U)
/*! FC1_CLK_CLR - flexcomm 1 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC1_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC1_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC1_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC2_CLK_CLR_MASK     (0x400U)
#define CLKCTL1_PSCCTL0_CLR_FC2_CLK_CLR_SHIFT    (10U)
/*! FC2_CLK_CLR - flexcomm 2 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC2_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC2_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC2_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC3_CLK_CLR_MASK     (0x800U)
#define CLKCTL1_PSCCTL0_CLR_FC3_CLK_CLR_SHIFT    (11U)
/*! FC3_CLK_CLR - flexcomm 3 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC3_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC3_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC3_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC4_CLK_CLR_MASK     (0x1000U)
#define CLKCTL1_PSCCTL0_CLR_FC4_CLK_CLR_SHIFT    (12U)
/*! FC4_CLK_CLR - flexcomm 4 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC4_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC4_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC4_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC5_CLK_CLR_MASK     (0x2000U)
#define CLKCTL1_PSCCTL0_CLR_FC5_CLK_CLR_SHIFT    (13U)
/*! FC5_CLK_CLR - flexcomm 5 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC5_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC5_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC5_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC6_CLK_CLR_MASK     (0x4000U)
#define CLKCTL1_PSCCTL0_CLR_FC6_CLK_CLR_SHIFT    (14U)
/*! FC6_CLK_CLR - flexcomm 6 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC6_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC6_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC6_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC7_CLK_CLR_MASK     (0x8000U)
#define CLKCTL1_PSCCTL0_CLR_FC7_CLK_CLR_SHIFT    (15U)
/*! FC7_CLK_CLR - flexcomm 7 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC7_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC7_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC7_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_CLR_MASK (0x400000U)
#define CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_CLR_SHIFT (22U)
/*! FC14_SPI_CLK_CLR - flexcomm 14 spi clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_CLR_MASK (0x800000U)
#define CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_CLR_SHIFT (23U)
/*! FC15_I2C_CLK_CLR - flexcomm 15 i2c clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_DMIC0_CLK_CLR_MASK   (0x1000000U)
#define CLKCTL1_PSCCTL0_CLR_DMIC0_CLK_CLR_SHIFT  (24U)
/*! DMIC0_CLK_CLR - DMIC0 clock set
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_DMIC0_CLK_CLR(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_DMIC0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_DMIC0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_CLK_CLR_MASK (0x8000000U)
#define CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_CLK_CLR_SHIFT (27U)
/*! OSEVENT_TIMER_CLK_CLR - OS event timer clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_CLK_CLR(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_CLK_CLR_MASK)
/*! @} */

/*! @name PSCCTL1_CLR - clock clear register 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_CLR_MASK (0x1U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_CLR_SHIFT (0U)
/*! HSGPIO0_CLK_CLR - HSGPIO0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_CLR_MASK (0x2U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_CLR_SHIFT (1U)
/*! HSGPIO1_CLK_CLR - HSGPIO1 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_CLR_MASK (0x4U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_CLR_SHIFT (2U)
/*! HSGPIO2_CLK_CLR - HSGPIO2 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_CLR_MASK (0x8U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_CLR_SHIFT (3U)
/*! HSGPIO3_CLK_CLR - HSGPIO3 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_CLR_MASK (0x10U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_CLR_SHIFT (4U)
/*! HSGPIO4_CLK_CLR - HSGPIO4 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_CLR_MASK (0x20U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_CLR_SHIFT (5U)
/*! HSGPIO5_CLK_CLR - HSGPIO5 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_CLR_MASK (0x40U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_CLR_SHIFT (6U)
/*! HSGPIO6_CLK_CLR - HSGPIO6 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_CLR_MASK (0x80U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_CLR_SHIFT (7U)
/*! HSGPIO7_CLK_CLR - HSGPIO7 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_CLR(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_CRC_CLK_CLR_MASK     (0x10000U)
#define CLKCTL1_PSCCTL1_CLR_CRC_CLK_CLR_SHIFT    (16U)
/*! CRC_CLK_CLR - CRC clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_CRC_CLK_CLR(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CRC_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CRC_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_CLR_MASK   (0x800000U)
#define CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_CLR_SHIFT  (23U)
/*! DMAC0_CLK_CLR - DMAC0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_CLR(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_CLR_MASK   (0x1000000U)
#define CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_CLR_SHIFT  (24U)
/*! DMAC1_CLK_CLR - DMAC1 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_CLR(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_MU_CLK_CLR_MASK      (0x10000000U)
#define CLKCTL1_PSCCTL1_CLR_MU_CLK_CLR_SHIFT     (28U)
/*! MU_CLK_CLR - MU clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_MU_CLK_CLR(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_MU_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_MU_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_SEMA_CLK_CLR_MASK    (0x20000000U)
#define CLKCTL1_PSCCTL1_CLR_SEMA_CLK_CLR_SHIFT   (29U)
/*! SEMA_CLK_CLR - SEMA clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_SEMA_CLK_CLR(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_SEMA_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_SEMA_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL1_CLR_FREQME_CLK_CLR_MASK  (0x80000000U)
#define CLKCTL1_PSCCTL1_CLR_FREQME_CLK_CLR_SHIFT (31U)
/*! FREQME_CLK_CLR - FREQME clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL1_PSCCTL1_CLR_FREQME_CLK_CLR(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_FREQME_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL1_CLR_FREQME_CLK_CLR_MASK)
/*! @} */

/*! @name PSCCTL2_CLR - clock clear register 2 */
/*! @{ */

#define CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_CLR_MASK (0x1U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_CLR_SHIFT (0U)
/*! CT32BIT0_CLK_CLR - ct32bit timer 0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_CLR_MASK (0x2U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_CLR_SHIFT (1U)
/*! CT32BIT1_CLK_CLR - ct32bit timer 1 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_CLR_MASK (0x4U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_CLR_SHIFT (2U)
/*! CT32BIT2_CLK_CLR - ct32bit timer 2 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_CLR_MASK (0x8U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_CLR_SHIFT (3U)
/*! CT32BIT3_CLK_CLR - ct32bit timer 3 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_CLR_MASK (0x10U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_CLR_SHIFT (4U)
/*! CT32BIT4_CLK_CLR - ct32bit timer 4 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_RTC_LITE_CLK_CLR_MASK (0x80U)
#define CLKCTL1_PSCCTL2_CLR_RTC_LITE_CLK_CLR_SHIFT (7U)
/*! RTC_LITE_CLK_CLR - rtc lite clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_RTC_LITE_CLK_CLR(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_RTC_LITE_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_RTC_LITE_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_MRT0_CLK_CLR_MASK    (0x100U)
#define CLKCTL1_PSCCTL2_CLR_MRT0_CLK_CLR_SHIFT   (8U)
/*! MRT0_CLK_CLR - mrt0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_MRT0_CLK_CLR(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_MRT0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_MRT0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_CLR_MASK   (0x400U)
#define CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_CLR_SHIFT  (10U)
/*! WWDT1_CLK_CLR - wdt1 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_CLR(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_I3C0_CLK_CLR_MASK    (0x10000U)
#define CLKCTL1_PSCCTL2_CLR_I3C0_CLK_CLR_SHIFT   (16U)
/*! I3C0_CLK_CLR - i3c0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_I3C0_CLK_CLR(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_I3C0_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_I3C0_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_CLR_MASK (0x40000000U)
#define CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_CLR_SHIFT (30U)
/*! GPIOINTCTL_CLK_CLR - GPIOINTCTL clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_CLR(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_CLR_MASK)

#define CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_CLR_MASK  (0x80000000U)
#define CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_CLR_SHIFT (31U)
/*! PIMCTL_CLK_CLR - PIMCTL clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_CLR(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_CLR_SHIFT)) & CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_CLR_MASK)
/*! @} */

/*! @name AUDIOPLL0CLKSEL - audio pll0 clock selection */
/*! @{ */

#define CLKCTL1_AUDIOPLL0CLKSEL_SEL_MASK         (0x7U)
#define CLKCTL1_AUDIOPLL0CLKSEL_SEL_SHIFT        (0U)
/*! SEL - System PLL Clock Source Selection. . .
 *  0b000..SFRO Clock.
 *  0b001..XTALIN Clock.
 *  0b010..FFRO Clock Divided by 2.
 *  0b011..Reserved.
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_AUDIOPLL0CLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CLKSEL_SEL_SHIFT)) & CLKCTL1_AUDIOPLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOPLL0CTL0 - audio pll0 control0 */
/*! @{ */

#define CLKCTL1_AUDIOPLL0CTL0_BYPASS_MASK        (0x1U)
#define CLKCTL1_AUDIOPLL0CTL0_BYPASS_SHIFT       (0U)
/*! BYPASS - AUDIOPLL0 BYPASS Mode
 *  0b0..PFD output is PFD programmed clock.
 *  0b1..PFD output is AUDIOPLL0 reference input clock. (Bypass Mode)
 */
#define CLKCTL1_AUDIOPLL0CTL0_BYPASS(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_BYPASS_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_BYPASS_MASK)

#define CLKCTL1_AUDIOPLL0CTL0_RESET_MASK         (0x2U)
#define CLKCTL1_AUDIOPLL0CTL0_RESET_SHIFT        (1U)
/*! RESET - AUDIOPLL0 Reset:
 *  0b0..AUDIOPLL0 reset is removed.
 *  0b1..AUDIOPLL0 is placed into reset.
 */
#define CLKCTL1_AUDIOPLL0CTL0_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_RESET_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_RESET_MASK)

#define CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_MASK (0x2000U)
#define CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_SHIFT (13U)
/*! HOLDRINGOFF_ENA - Hold Ring Off Control
 *  0b0..disbale
 *  0b1..enable
 */
#define CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_MASK)

#define CLKCTL1_AUDIOPLL0CTL0_MULT_MASK          (0xFF0000U)
#define CLKCTL1_AUDIOPLL0CTL0_MULT_SHIFT         (16U)
/*! MULT - Multiplication Factor for FAUDIOPLL0_OUTPUT:
 *  0b00010000..Div 16
 *  0b00010001..Div 17
 *  0b00010100..Div 20
 *  0b00010110..Div 22
 *  0b00011011..Div 27
 *  0b00100001..Div 33
 */
#define CLKCTL1_AUDIOPLL0CTL0_MULT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_MULT_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_MULT_MASK)
/*! @} */

/*! @name AUDIOPLL0LOCKTIMEDIV2 - audio pll0 lock time */
/*! @{ */

#define CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - AUDIOPLL0 Lock Time Divide by 2: Programmed lock time is in uS (micro-seconds)
 *    and is programmed as half the actual lock time value.
 */
#define CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name AUDIOPLL0NUM - audio pll0 number */
/*! @{ */

#define CLKCTL1_AUDIOPLL0NUM_NUM_MASK            (0x3FFFFFFFU)
#define CLKCTL1_AUDIOPLL0NUM_NUM_SHIFT           (0U)
/*! NUM - This field contains the numerator of the AUDIOPLL0 fractional loop divider. NOTES: 1. The
 *    value of numerator must always be configured to be less than the value of the denominator. 2.
 *    The AUDIOPLL0NUM register can only be changed when the AUDIOPLL0 is disabled.
 */
#define CLKCTL1_AUDIOPLL0NUM_NUM(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0NUM_NUM_SHIFT)) & CLKCTL1_AUDIOPLL0NUM_NUM_MASK)
/*! @} */

/*! @name AUDIOPLL0DENOM - Audio pll0 denom */
/*! @{ */

#define CLKCTL1_AUDIOPLL0DENOM_DENOM_MASK        (0x3FFFFFFFU)
#define CLKCTL1_AUDIOPLL0DENOM_DENOM_SHIFT       (0U)
/*! DENOM - This field contains the denominator of the AUDIOPLL0 fractional loop divider. NOTES: 1.
 *    The value of numerator must always be configured to be less than the value of the denominator.
 *    2. The AUDIOPLL0DENOM register can only be changed when the AUDIOPLL0 is disabled.
 */
#define CLKCTL1_AUDIOPLL0DENOM_DENOM(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0DENOM_DENOM_SHIFT)) & CLKCTL1_AUDIOPLL0DENOM_DENOM_MASK)
/*! @} */

/*! @name AUDIOPLL0PFD - audio pll0 PFD */
/*! @{ */

#define CLKCTL1_AUDIOPLL0PFD_PFD0_MASK           (0x3FU)
#define CLKCTL1_AUDIOPLL0PFD_PFD0_SHIFT          (0U)
/*! PFD0 - PLL Fractional Divider 0: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL1_AUDIOPLL0PFD_PFD0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD0_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD0_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_MASK    (0x40U)
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_SHIFT   (6U)
/*! PFD0_CLKRDY - PFD0 Clock Ready Status Flag: Read as 1 clock ready. Cleared by writing a 1. */
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_MASK   (0x80U)
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_SHIFT  (7U)
/*! PFD0_CLKGATE - PFD0 Clock Gate: 0: PFD0 clock is not gated. 1: PFD0 clock is gated
 *  0b0..PFD0 clock is not gated.
 *  0b1..PFD0 clock is gated.
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD1_MASK           (0x3F00U)
#define CLKCTL1_AUDIOPLL0PFD_PFD1_SHIFT          (8U)
/*! PFD1 - PLL Fractional Divider 1: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL1_AUDIOPLL0PFD_PFD1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD1_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD1_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_MASK    (0x4000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_SHIFT   (14U)
/*! PFD1_CLKRDY - PFD1 Clock Ready Status Flag: Read as 1 clock ready. Cleared by writing a 1. */
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_MASK   (0x8000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_SHIFT  (15U)
/*! PFD1_CLKGATE - PFD1 Clock Gate: 0: PFD1 clock is not gated. 1: PFD1 clock is gated.
 *  0b0..PFD1 clock is not gated.
 *  0b1..PFD1 clock is gated.
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD2_MASK           (0x3F0000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD2_SHIFT          (16U)
/*! PFD2 - PLL Fractional Divider 2: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL1_AUDIOPLL0PFD_PFD2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD2_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD2_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_MASK    (0x400000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_SHIFT   (22U)
/*! PFD2_CLKRDY - PFD2 Clock Ready Status Flag: Read as 1 clock ready. Cleared by writing a 1. */
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_MASK   (0x800000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_SHIFT  (23U)
/*! PFD2_CLKGATE - PFD2 Clock Gate: 0: PFD2 clock is not gated. 1: PFD2 clock is gated.
 *  0b0..PFD2 clock is not gated.
 *  0b1..PFD2 clock is gated.
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD3_MASK           (0x3F000000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD3_SHIFT          (24U)
/*! PFD3 - PLL Fractional Divider 3: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL1_AUDIOPLL0PFD_PFD3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD3_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD3_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_MASK    (0x40000000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_SHIFT   (30U)
/*! PFD3_CLKRDY - PFD3 Clock Ready Status Flag: Read as 1 clock ready. Cleared by writing a 1. */
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_MASK   (0x80000000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_SHIFT  (31U)
/*! PFD3_CLKGATE - PFD3 Clock Gate: 0: PFD3 clock is not gated. 1: PFD3 clock is gated.
 *  0b0..PFD3 clock is not gated.
 *  0b1..PFD3 clock is gated.
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name AUDIOPLLCLKDIV - audio pll0 clock divider */
/*! @{ */

#define CLKCTL1_AUDIOPLLCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL1_AUDIOPLLCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_AUDIOPLLCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_DIV_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_DIV_MASK)

#define CLKCTL1_AUDIOPLLCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL1_AUDIOPLLCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_AUDIOPLLCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_RESET_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_RESET_MASK)

#define CLKCTL1_AUDIOPLLCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL1_AUDIOPLLCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL1_AUDIOPLLCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_HALT_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_HALT_MASK)

#define CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_AUDIOPLLCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPCPUCLKDIV - DSP cpu clock divider */
/*! @{ */

#define CLKCTL1_DSPCPUCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_DSPCPUCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_DSPCPUCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_DIV_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_DIV_MASK)

#define CLKCTL1_DSPCPUCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_DSPCPUCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_DSPCPUCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_RESET_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_RESET_MASK)

#define CLKCTL1_DSPCPUCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_DSPCPUCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL1_DSPCPUCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_HALT_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_HALT_MASK)

#define CLKCTL1_DSPCPUCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_DSPCPUCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_DSPCPUCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPMAINRAMCLKDIV - DSP main ram clock divider */
/*! @{ */

#define CLKCTL1_DSPMAINRAMCLKDIV_DSPMRAMCLKDIV_MASK (0x3U)
#define CLKCTL1_DSPMAINRAMCLKDIV_DSPMRAMCLKDIV_SHIFT (0U)
/*! DSPMRAMCLKDIV - DSP MAINRAM Clock Ratio Control:
 *  0b00..DSP MAINRAM Clk = DSP Core CLK / 1.
 *  0b01..DSP MAINRAM Clk = DSP Core CLK / 2.
 *  0b10..DSP MAINRAM Clk = DSP Core CLK / 3.
 *  0b11..DSP MAINRAM Clk = DSP Core CLK / 4.
 */
#define CLKCTL1_DSPMAINRAMCLKDIV_DSPMRAMCLKDIV(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPMAINRAMCLKDIV_DSPMRAMCLKDIV_SHIFT)) & CLKCTL1_DSPMAINRAMCLKDIV_DSPMRAMCLKDIV_MASK)
/*! @} */

/*! @name DSPCPUCLKSELA - DSP clock selection A */
/*! @{ */

#define CLKCTL1_DSPCPUCLKSELA_SEL_MASK           (0x3U)
#define CLKCTL1_DSPCPUCLKSELA_SEL_SHIFT          (0U)
/*! SEL - Control Main 1st Stage Control Clock Source. . .
 *  0b00..FFRO Clock.
 *  0b01..XTALIN Clock.
 *  0b10..Low Power Oscillator Clock (LPOSC).
 *  0b11..SFRO Clock.
 */
#define CLKCTL1_DSPCPUCLKSELA_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKSELA_SEL_SHIFT)) & CLKCTL1_DSPCPUCLKSELA_SEL_MASK)
/*! @} */

/*! @name DSPCPUCLKSELB - DSP clock selection B */
/*! @{ */

#define CLKCTL1_DSPCPUCLKSELB_SEL_MASK           (0x3U)
#define CLKCTL1_DSPCPUCLKSELB_SEL_SHIFT          (0U)
/*! SEL - Main Clock Source Selection. . .
 *  0b00..MAINCLKSELA 1st Stage Clock.
 *  0b01..Main System PLL Clock.
 *  0b10..DSP System PLL Clock.
 *  0b11..RTC 32KHz Clock.
 */
#define CLKCTL1_DSPCPUCLKSELB_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKSELB_SEL_SHIFT)) & CLKCTL1_DSPCPUCLKSELB_SEL_MASK)
/*! @} */

/*! @name OSEVENTFCLKSEL - OS EVENT clock selection */
/*! @{ */

#define CLKCTL1_OSEVENTFCLKSEL_SEL_MASK          (0x7U)
#define CLKCTL1_OSEVENTFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - OS Event Timer Functional Clock Source Selection. . .
 *  0b000..Low Power Oscillator Clock (LPOSC).
 *  0b001..RTC 32KHz Clock.
 *  0b010..Teal Free Running Clock (Global Time Stamping)
 *  0b011..reserved
 *  0b100..reserved
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_OSEVENTFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_OSEVENTFCLKSEL_SEL_SHIFT)) & CLKCTL1_OSEVENTFCLKSEL_SEL_MASK)
/*! @} */

/*! @name FRGCLKSEL - FRG clock selection register N */
/*! @{ */

#define CLKCTL1_FRGCLKSEL_SEL_MASK               (0x7U)
#define CLKCTL1_FRGCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Fractional Gen. Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..FRG PLL Clock.
 *  0b010..SFRO Clock.
 *  0b011..FFRO Clock.
 *  0b100..reserved
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_FRGCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGCLKSEL_SEL_SHIFT)) & CLKCTL1_FRGCLKSEL_SEL_MASK)
/*! @} */

/* The count of CLKCTL1_FRGCLKSEL */
#define CLKCTL1_FRGCLKSEL_COUNT                  (8U)

/*! @name FRGCTL - FRG clock controller */
/*! @{ */

#define CLKCTL1_FRGCTL_DIV_MASK                  (0xFFU)
#define CLKCTL1_FRGCTL_DIV_SHIFT                 (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define CLKCTL1_FRGCTL_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGCTL_DIV_SHIFT)) & CLKCTL1_FRGCTL_DIV_MASK)

#define CLKCTL1_FRGCTL_MULT_MASK                 (0xFF00U)
#define CLKCTL1_FRGCTL_MULT_SHIFT                (8U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define CLKCTL1_FRGCTL_MULT(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGCTL_MULT_SHIFT)) & CLKCTL1_FRGCTL_MULT_MASK)
/*! @} */

/* The count of CLKCTL1_FRGCTL */
#define CLKCTL1_FRGCTL_COUNT                     (8U)

/*! @name FCFCLKSEL - flexcomm clock selection */
/*! @{ */

#define CLKCTL1_FCFCLKSEL_SEL_MASK               (0x7U)
#define CLKCTL1_FCFCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Flexxcomm Functional Clock Source Selection. . .
 *  0b000..SFRO Clock.
 *  0b001..FFRO Clock.
 *  0b010..Audio PLL Clock.
 *  0b011..Master Clock In.
 *  0b100..FCn FRG Clock.
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_FCFCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKSEL_SEL_SHIFT)) & CLKCTL1_FCFCLKSEL_SEL_MASK)
/*! @} */

/* The count of CLKCTL1_FCFCLKSEL */
#define CLKCTL1_FCFCLKSEL_COUNT                  (8U)

/*! @name FRG14CLKSEL - FRG clock selection register 14 */
/*! @{ */

#define CLKCTL1_FRG14CLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_FRG14CLKSEL_SEL_SHIFT            (0U)
/*! SEL - Fractional Gen. Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..Main System PLL Clock.
 *  0b010..SFRO Clock.
 *  0b011..FFRO Clock.
 *  0b100..reserved
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_FRG14CLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG14CLKSEL_SEL_SHIFT)) & CLKCTL1_FRG14CLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG14CTL - FRG clock controller 14 */
/*! @{ */

#define CLKCTL1_FRG14CTL_DIV_MASK                (0xFFU)
#define CLKCTL1_FRG14CTL_DIV_SHIFT               (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define CLKCTL1_FRG14CTL_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG14CTL_DIV_SHIFT)) & CLKCTL1_FRG14CTL_DIV_MASK)

#define CLKCTL1_FRG14CTL_MULT_MASK               (0xFF00U)
#define CLKCTL1_FRG14CTL_MULT_SHIFT              (8U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define CLKCTL1_FRG14CTL_MULT(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG14CTL_MULT_SHIFT)) & CLKCTL1_FRG14CTL_MULT_MASK)
/*! @} */

/*! @name FC14FCLKSEL - flexcomm14 clock selection */
/*! @{ */

#define CLKCTL1_FC14FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_FC14FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Flexxcomm Functional Clock Source Selection. . .
 *  0b000..SFRO Clock.
 *  0b001..FFRO Clock.
 *  0b010..Audio PLL Clock.
 *  0b011..Master Clock In.
 *  0b100..FCn FRG Clock.
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_FC14FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FC14FCLKSEL_SEL_SHIFT)) & CLKCTL1_FC14FCLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG15CLKSEL - FRG clock selection register 15 */
/*! @{ */

#define CLKCTL1_FRG15CLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_FRG15CLKSEL_SEL_SHIFT            (0U)
/*! SEL - Fractional Gen. Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..Main System PLL Clock.
 *  0b010..SFRO Clock.
 *  0b011..FFRO Clock.
 *  0b100..reserved
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_FRG15CLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG15CLKSEL_SEL_SHIFT)) & CLKCTL1_FRG15CLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG15CTL - FRG clock controller 15 */
/*! @{ */

#define CLKCTL1_FRG15CTL_DIV_MASK                (0xFFU)
#define CLKCTL1_FRG15CTL_DIV_SHIFT               (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define CLKCTL1_FRG15CTL_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG15CTL_DIV_SHIFT)) & CLKCTL1_FRG15CTL_DIV_MASK)

#define CLKCTL1_FRG15CTL_MULT_MASK               (0xFF00U)
#define CLKCTL1_FRG15CTL_MULT_SHIFT              (8U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define CLKCTL1_FRG15CTL_MULT(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG15CTL_MULT_SHIFT)) & CLKCTL1_FRG15CTL_MULT_MASK)
/*! @} */

/*! @name FC15FCLKSEL - flexcomm15 clock selection */
/*! @{ */

#define CLKCTL1_FC15FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_FC15FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Flexxcomm Functional Clock Source Selection. . .
 *  0b000..SFRO Clock.
 *  0b001..FFRO Clock.
 *  0b010..Audio PLL Clock.
 *  0b011..Master Clock In.
 *  0b100..FCn FRG Clock.
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_FC15FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FC15FCLKSEL_SEL_SHIFT)) & CLKCTL1_FC15FCLKSEL_SEL_MASK)
/*! @} */

/*! @name FRGPLLCLKDIV - FRG pll clock divider */
/*! @{ */

#define CLKCTL1_FRGPLLCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_FRGPLLCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_FRGPLLCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_DIV_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_DIV_MASK)

#define CLKCTL1_FRGPLLCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_FRGPLLCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_FRGPLLCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_RESET_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_RESET_MASK)

#define CLKCTL1_FRGPLLCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_FRGPLLCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL1_FRGPLLCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_HALT_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_HALT_MASK)

#define CLKCTL1_FRGPLLCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_FRGPLLCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_FRGPLLCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DMIC0FCLKSEL - DMIC0 clk selection */
/*! @{ */

#define CLKCTL1_DMIC0FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_DMIC0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - DMIC Functional Clock Source Selection. . .
 *  0b000..SFRO Clock.
 *  0b001..FFRO Clock.
 *  0b010..Audio PLL Clock.
 *  0b011..Master Clock In.
 *  0b100..Low Power Oscillator Clock (LPOSC).
 *  0b101..32KHZ Wake Clk.
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_DMIC0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKSEL_SEL_SHIFT)) & CLKCTL1_DMIC0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name DMIC0FCLKDIV - DMIC clock clock divider */
/*! @{ */

#define CLKCTL1_DMIC0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_DMIC0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_DMIC0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_DIV_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_DIV_MASK)

#define CLKCTL1_DMIC0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_DMIC0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_DMIC0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_RESET_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_RESET_MASK)

#define CLKCTL1_DMIC0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_DMIC0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL1_DMIC0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_HALT_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_HALT_MASK)

#define CLKCTL1_DMIC0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_DMIC0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_DMIC0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CT32BITFCLKSEL - ct32bit timer N clock selection */
/*! @{ */

#define CLKCTL1_CT32BITFCLKSEL_SEL_MASK          (0x7U)
#define CLKCTL1_CT32BITFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - CT32Bit Functional Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..SFRO Clock.
 *  0b010..FFRO Clock.
 *  0b011..Audio PLL Clock.
 *  0b100..Master Clock In.
 *  0b101..Low Power Oscillator Clock (LPOSC).
 *  0b110..reserved
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_CT32BITFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CT32BITFCLKSEL_SEL_SHIFT)) & CLKCTL1_CT32BITFCLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOMCLKSEL - audio mclock selection */
/*! @{ */

#define CLKCTL1_AUDIOMCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_AUDIOMCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Audio MCLK Clock Source Selection. . .
 *  0b000..FFRO Clock.
 *  0b001..AUDIO PLL Clock. (Shared Domain)
 *  0b010..reserved
 *  0b011..reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_AUDIOMCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKSEL_SEL_SHIFT)) & CLKCTL1_AUDIOMCLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOMCLKDIV - audio mclock divider */
/*! @{ */

#define CLKCTL1_AUDIOMCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_AUDIOMCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_AUDIOMCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_DIV_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_DIV_MASK)

#define CLKCTL1_AUDIOMCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_AUDIOMCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_AUDIOMCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_RESET_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_RESET_MASK)

#define CLKCTL1_AUDIOMCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_AUDIOMCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL1_AUDIOMCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_HALT_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_HALT_MASK)

#define CLKCTL1_AUDIOMCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_AUDIOMCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_AUDIOMCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLKOUTSEL0 - clock out selection 0 */
/*! @{ */

#define CLKCTL1_CLKOUTSEL0_SEL_MASK              (0x7U)
#define CLKCTL1_CLKOUTSEL0_SEL_SHIFT             (0U)
/*! SEL - Clock Output Select 1st Stage. . .
 *  0b000..SFRO Clock.
 *  0b001..XTALIN Clock.
 *  0b010..Low Power Oscillator Clock (LPOSC).
 *  0b011..FFRO Clock.
 *  0b100..Main Clock.
 *  0b101..reserved
 *  0b110..DSP Main Clock.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_CLKOUTSEL0_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTSEL0_SEL_SHIFT)) & CLKCTL1_CLKOUTSEL0_SEL_MASK)
/*! @} */

/*! @name CLKOUTSEL1 - clock out selection 1 */
/*! @{ */

#define CLKCTL1_CLKOUTSEL1_SEL_MASK              (0x7U)
#define CLKCTL1_CLKOUTSEL1_SEL_SHIFT             (0U)
/*! SEL - Clock out clock Source Selection. . .
 *  0b000..CLKOUTSEL0 Multiplexed Output.
 *  0b001..Main System PLL Clock.
 *  0b010..SYSPLL0 AUX0_PLL_Clock.
 *  0b011..DSP PLL clock.
 *  0b100..SYSPLL0 AUX1_PLL_Clock.
 *  0b101..AUDIO PLL Clock.
 *  0b110..32KHz RTC Clock.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_CLKOUTSEL1_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTSEL1_SEL_SHIFT)) & CLKCTL1_CLKOUTSEL1_SEL_MASK)
/*! @} */

/*! @name CLKOUTDIV - clock_out divider */
/*! @{ */

#define CLKCTL1_CLKOUTDIV_DIV_MASK               (0xFFU)
#define CLKCTL1_CLKOUTDIV_DIV_SHIFT              (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_CLKOUTDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTDIV_DIV_SHIFT)) & CLKCTL1_CLKOUTDIV_DIV_MASK)

#define CLKCTL1_CLKOUTDIV_RESET_MASK             (0x20000000U)
#define CLKCTL1_CLKOUTDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_CLKOUTDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTDIV_RESET_SHIFT)) & CLKCTL1_CLKOUTDIV_RESET_MASK)

#define CLKCTL1_CLKOUTDIV_HALT_MASK              (0x40000000U)
#define CLKCTL1_CLKOUTDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL1_CLKOUTDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTDIV_HALT_SHIFT)) & CLKCTL1_CLKOUTDIV_HALT_MASK)

#define CLKCTL1_CLKOUTDIV_REQFLAG_MASK           (0x80000000U)
#define CLKCTL1_CLKOUTDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_CLKOUTDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTDIV_REQFLAG_SHIFT)) & CLKCTL1_CLKOUTDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C0FCLKSEL - I3C0 fclk selection */
/*! @{ */

#define CLKCTL1_I3C0FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_I3C0FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - I3C0 FClock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..FFRO Clock.
 *  0b010..reserved.
 *  0b011..reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_I3C0FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSEL_SEL_SHIFT)) & CLKCTL1_I3C0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name I3C0FCLKSTCSEL - I3C0 fclk STC selection */
/*! @{ */

#define CLKCTL1_I3C0FCLKSTCSEL_SEL_MASK          (0x7U)
#define CLKCTL1_I3C0FCLKSTCSEL_SEL_SHIFT         (0U)
/*! SEL - I3C0 Clock Source Selection. . .
 *  0b000..I3C0 FCLK Selection.
 *  0b001..Low Power Oscillator Clock (LPOSC).
 *  0b010..Reserved.
 *  0b011..Reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_I3C0FCLKSTCSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSTCSEL_SEL_SHIFT)) & CLKCTL1_I3C0FCLKSTCSEL_SEL_MASK)
/*! @} */

/*! @name I3C0FCLKSTCDIV - I3C0 fclk STC divider */
/*! @{ */

#define CLKCTL1_I3C0FCLKSTCDIV_DIV_MASK          (0xFFU)
#define CLKCTL1_I3C0FCLKSTCDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_I3C0FCLKSTCDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSTCDIV_DIV_SHIFT)) & CLKCTL1_I3C0FCLKSTCDIV_DIV_MASK)

#define CLKCTL1_I3C0FCLKSTCDIV_RESET_MASK        (0x20000000U)
#define CLKCTL1_I3C0FCLKSTCDIV_RESET_SHIFT       (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_I3C0FCLKSTCDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSTCDIV_RESET_SHIFT)) & CLKCTL1_I3C0FCLKSTCDIV_RESET_MASK)

#define CLKCTL1_I3C0FCLKSTCDIV_HALT_MASK         (0x40000000U)
#define CLKCTL1_I3C0FCLKSTCDIV_HALT_SHIFT        (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL1_I3C0FCLKSTCDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSTCDIV_HALT_SHIFT)) & CLKCTL1_I3C0FCLKSTCDIV_HALT_MASK)

#define CLKCTL1_I3C0FCLKSTCDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL1_I3C0FCLKSTCDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_I3C0FCLKSTCDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSTCDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C0FCLKSTCDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C0FCLKSDIV - I3C0 fclks divider */
/*! @{ */

#define CLKCTL1_I3C0FCLKSDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_I3C0FCLKSDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_I3C0FCLKSDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSDIV_DIV_SHIFT)) & CLKCTL1_I3C0FCLKSDIV_DIV_MASK)

#define CLKCTL1_I3C0FCLKSDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_I3C0FCLKSDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_I3C0FCLKSDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSDIV_RESET_SHIFT)) & CLKCTL1_I3C0FCLKSDIV_RESET_MASK)

#define CLKCTL1_I3C0FCLKSDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_I3C0FCLKSDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL1_I3C0FCLKSDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSDIV_HALT_SHIFT)) & CLKCTL1_I3C0FCLKSDIV_HALT_MASK)

#define CLKCTL1_I3C0FCLKSDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_I3C0FCLKSDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_I3C0FCLKSDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKSDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C0FCLKSDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C0FCLKDIV - I3C0 fclk divider */
/*! @{ */

#define CLKCTL1_I3C0FCLKDIV_DIV_MASK             (0xFFU)
#define CLKCTL1_I3C0FCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_I3C0FCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKDIV_DIV_SHIFT)) & CLKCTL1_I3C0FCLKDIV_DIV_MASK)

#define CLKCTL1_I3C0FCLKDIV_RESET_MASK           (0x20000000U)
#define CLKCTL1_I3C0FCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_I3C0FCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKDIV_RESET_SHIFT)) & CLKCTL1_I3C0FCLKDIV_RESET_MASK)

#define CLKCTL1_I3C0FCLKDIV_HALT_MASK            (0x40000000U)
#define CLKCTL1_I3C0FCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL1_I3C0FCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKDIV_HALT_SHIFT)) & CLKCTL1_I3C0FCLKDIV_HALT_MASK)

#define CLKCTL1_I3C0FCLKDIV_REQFLAG_MASK         (0x80000000U)
#define CLKCTL1_I3C0FCLKDIV_REQFLAG_SHIFT        (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_I3C0FCLKDIV_REQFLAG(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name WDT1FCLKSEL - WDT1 clock selection */
/*! @{ */

#define CLKCTL1_WDT1FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_WDT1FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - WDT1 Functional Clock Source Selection. . .
 *  0b000..Low Power Oscillator Clock (LPOSC).
 *  0b001..reserved
 *  0b010..Reserved.
 *  0b011..Reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_WDT1FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_WDT1FCLKSEL_SEL_SHIFT)) & CLKCTL1_WDT1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name ACMP0FCLKSEL - acomparator 0 clock selection */
/*! @{ */

#define CLKCTL1_ACMP0FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_ACMP0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - ACMP0 Fast Functional Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..SFRO Clock.
 *  0b010..FFRO Clock.
 *  0b011..SYSPLL0 AUX0_PLL_Clock.
 *  0b100..SYSPLL0 AUX1_PLL_Clock.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL1_ACMP0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKSEL_SEL_SHIFT)) & CLKCTL1_ACMP0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name ACMP0FCLKDIV - acomparator 0 fclk divider */
/*! @{ */

#define CLKCTL1_ACMP0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_ACMP0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL1_ACMP0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_DIV_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_DIV_MASK)

#define CLKCTL1_ACMP0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_ACMP0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL1_ACMP0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_RESET_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_RESET_MASK)

#define CLKCTL1_ACMP0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_ACMP0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL1_ACMP0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_HALT_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_HALT_MASK)

#define CLKCTL1_ACMP0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_ACMP0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL1_ACMP0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_REQFLAG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL1_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL1_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL1_H_ */

