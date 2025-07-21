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
 * @file PERI_CLKCTL1.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL1
 *
 * CMSIS Peripheral Access Layer for CLKCTL1
 */

#if !defined(PERI_CLKCTL1_H_)
#define PERI_CLKCTL1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL1_Peripheral_Access_Layer CLKCTL1 Peripheral Access Layer
 * @{
 */

/** CLKCTL1 - Size of Registers Arrays */
#define CLKCTL1_FLEXCOMM_COUNT                    17u
#define CLKCTL1_CT32BITFCLKSEL_COUNT              5u

/** CLKCTL1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0;                           /**< Clock Control 0, offset: 0x10 */
  __IO uint32_t PSCCTL1;                           /**< Clock Control 1, offset: 0x14 */
  __IO uint32_t PSCCTL2;                           /**< Clock Control 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __IO uint32_t PSCCTL0_SET;                       /**< Clock Set 0, offset: 0x40 */
  __IO uint32_t PSCCTL1_SET;                       /**< Clock Set 1, offset: 0x44 */
  __IO uint32_t PSCCTL2_SET;                       /**< Clock Set 2, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __IO uint32_t PSCCTL0_CLR;                       /**< Clock Clear 0, offset: 0x70 */
  __IO uint32_t PSCCTL1_CLR;                       /**< Clock Clear 1, offset: 0x74 */
  __IO uint32_t PSCCTL2_CLR;                       /**< Clock Clear 2, offset: 0x78 */
       uint8_t RESERVED_3[388];
  __IO uint32_t AUDIOPLL0CLKSEL;                   /**< Audio PLL0 Clock Select, offset: 0x200 */
  __IO uint32_t AUDIOPLL0CTL0;                     /**< Audio PLL0 Control 0, offset: 0x204 */
       uint8_t RESERVED_4[4];
  __IO uint32_t AUDIOPLL0LOCKTIMEDIV2;             /**< Audio PLL0 Lock Time Divide-by-2, offset: 0x20C */
  __IO uint32_t AUDIOPLL0NUM;                      /**< Audio PLL0 Numerator, offset: 0x210 */
  __IO uint32_t AUDIOPLL0DENOM;                    /**< Audio PLL0 Denominator, offset: 0x214 */
  __IO uint32_t AUDIOPLL0PFD;                      /**< Audio PLL0 PFD, offset: 0x218 */
       uint8_t RESERVED_5[36];
  __IO uint32_t AUDIOPLLCLKDIV;                    /**< Audio PLL Clock Divider, offset: 0x240 */
       uint8_t RESERVED_6[444];
  __IO uint32_t DSPCPUCLKDIV;                      /**< DSP CPU Clock Divider, offset: 0x400 */
       uint8_t RESERVED_7[44];
  __IO uint32_t DSPCPUCLKSELA;                     /**< DSP CPU Clock Select A, offset: 0x430 */
  __IO uint32_t DSPCPUCLKSELB;                     /**< DSP CPU Clock Select B, offset: 0x434 */
       uint8_t RESERVED_8[72];
  __IO uint32_t OSEVENTTFCLKSEL;                   /**< OS Event Timer Functional Clock Select, offset: 0x480 */
       uint8_t RESERVED_9[124];
  struct {                                         /* offset: 0x500, array step: 0x20 */
    __IO uint32_t FRGCLKSEL;                         /**< Fractional Rate Generator 0 Clock Select..Fractional Rate Generator 16 Clock Select, array offset: 0x500, array step: 0x20 */
    __IO uint32_t FRGCTL;                            /**< Fractional Rate Generator 0 Control..Fractional Rate Generator 16 Control, array offset: 0x504, array step: 0x20 */
    __IO uint32_t FCFCLKSEL;                         /**< Flexcomm0 Clock Select..Flexcomm16 Clock Select, array offset: 0x508, array step: 0x20 */
         uint8_t RESERVED_0[20];
  } FLEXCOMM[CLKCTL1_FLEXCOMM_COUNT];
  __IO uint32_t FRG17CLKSEL;                       /**< Fractional Rate Generator 17 Clock Select, offset: 0x720 */
  __IO uint32_t FRG17CTL;                          /**< Fractional Rate Generator 17 Control, offset: 0x724 */
  __IO uint32_t FLEXIOCLKSEL;                      /**< FlexIO Clock Select, offset: 0x728 */
       uint8_t RESERVED_10[20];
  __IO uint32_t FLEXIOCLKDIV;                      /**< FlexIO Clock Divider, offset: 0x740 */
       uint8_t RESERVED_11[28];
  __IO uint32_t FRGPLLCLKDIV;                      /**< Fractional Rate Generator PLL Clock Divider, offset: 0x760 */
       uint8_t RESERVED_12[28];
  __IO uint32_t DMIC0FCLKSEL;                      /**< DMIC0 Functional Clock Select, offset: 0x780 */
  __IO uint32_t DMIC0FCLKDIV;                      /**< DMIC0 Functional Clock Divider, offset: 0x784 */
       uint8_t RESERVED_13[24];
  __IO uint32_t CT32BITFCLKSEL[CLKCTL1_CT32BITFCLKSEL_COUNT]; /**< CT32BIT bit timer 0 Functional Clock Select..CT32BIT bit timer 4 Functional Clock Select, array offset: 0x7A0, array step: 0x4 */
       uint8_t RESERVED_14[12];
  __IO uint32_t AUDIOMCLKSEL;                      /**< Audio MCLK Clock Select, offset: 0x7C0 */
  __IO uint32_t AUDIOMCLKDIV;                      /**< Audio MCLK Clock Divider, offset: 0x7C4 */
       uint8_t RESERVED_15[24];
  __IO uint32_t CLKOUTSEL0;                        /**< CLKOUT Clock Select 0, offset: 0x7E0 */
  __IO uint32_t CLKOUTSEL1;                        /**< CLKOUT Clock Select 1, offset: 0x7E4 */
  __IO uint32_t CLKOUTFCLKDIV;                     /**< CLKOUT Functional Clock Divider, offset: 0x7E8 */
       uint8_t RESERVED_16[20];
  __IO uint32_t I3C01FCLKSEL;                      /**< I3C0, I3C1 Functional Clock Select, offset: 0x800 */
  __IO uint32_t I3C01FCLKSTCSEL;                   /**< I3C0, I3C1 Functional Slow Time Control Clock Select, offset: 0x804 */
  __IO uint32_t I3C01FCLKSTCDIV;                   /**< I3C0, I3C1 Functional Slow Time Control Clock Divider, offset: 0x808 */
  __IO uint32_t I3C01FCLKSDIV;                     /**< I3C0, I3C1 Functional Slow Clock Divider, offset: 0x80C */
  __IO uint32_t I3C01FCLKDIV;                      /**< I3C0, I3C1 Functional Clock Divider, offset: 0x810 */
  __IO uint32_t I3C01FCLKSTSTCLKSEL;               /**< I3C01 Functional Clock Select, offset: 0x814 */
       uint8_t RESERVED_17[8];
  __IO uint32_t WDT1FCLKSEL;                       /**< Watchdog Timer 1 Functional Clock Select, offset: 0x820 */
       uint8_t RESERVED_18[12];
  __IO uint32_t ACMP0FCLKSEL;                      /**< Analog Comparator 0 Clock Select, offset: 0x830 */
  __IO uint32_t ACMP0FCLKDIV;                      /**< Analog comparator 0 FCLK divider, offset: 0x834 */
} CLKCTL1_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL1_Register_Masks CLKCTL1 Register Masks
 * @{
 */

/*! @name PSCCTL0 - Clock Control 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_FC0_CLK_MASK             (0x100U)
#define CLKCTL1_PSCCTL0_FC0_CLK_SHIFT            (8U)
/*! FC0_CLK - Flexcomm Interface 0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC0_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC0_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC0_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC1_CLK_MASK             (0x200U)
#define CLKCTL1_PSCCTL0_FC1_CLK_SHIFT            (9U)
/*! FC1_CLK - Flexcomm Interface 1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC1_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC1_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC1_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC2_CLK_MASK             (0x400U)
#define CLKCTL1_PSCCTL0_FC2_CLK_SHIFT            (10U)
/*! FC2_CLK - Flexcomm Interface 2 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC2_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC2_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC2_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC3_CLK_MASK             (0x800U)
#define CLKCTL1_PSCCTL0_FC3_CLK_SHIFT            (11U)
/*! FC3_CLK - Flexcomm Interface 3 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC3_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC3_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC3_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC4_CLK_MASK             (0x1000U)
#define CLKCTL1_PSCCTL0_FC4_CLK_SHIFT            (12U)
/*! FC4_CLK - Flexcomm Interface 4 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC4_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC4_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC4_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC5_CLK_MASK             (0x2000U)
#define CLKCTL1_PSCCTL0_FC5_CLK_SHIFT            (13U)
/*! FC5_CLK - Flexcomm Interface 5 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC5_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC5_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC5_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC6_CLK_MASK             (0x4000U)
#define CLKCTL1_PSCCTL0_FC6_CLK_SHIFT            (14U)
/*! FC6_CLK - Flexcomm Interface 6 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC6_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC6_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC6_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC7_CLK_MASK             (0x8000U)
#define CLKCTL1_PSCCTL0_FC7_CLK_SHIFT            (15U)
/*! FC7_CLK - Flexcomm Interface 7 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC7_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC7_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC7_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC8_CLK_MASK             (0x10000U)
#define CLKCTL1_PSCCTL0_FC8_CLK_SHIFT            (16U)
/*! FC8_CLK - Flexcomm Interface 8 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC8_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC8_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC8_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC9_CLK_MASK             (0x20000U)
#define CLKCTL1_PSCCTL0_FC9_CLK_SHIFT            (17U)
/*! FC9_CLK - Flexcomm Interface 9 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC9_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC9_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC9_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC10_CLK_MASK            (0x40000U)
#define CLKCTL1_PSCCTL0_FC10_CLK_SHIFT           (18U)
/*! FC10_CLK - Flexcomm Interface 10 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC10_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC10_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC10_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC11_CLK_MASK            (0x80000U)
#define CLKCTL1_PSCCTL0_FC11_CLK_SHIFT           (19U)
/*! FC11_CLK - Flexcomm Interface 11 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC11_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC11_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC11_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC12_CLK_MASK            (0x100000U)
#define CLKCTL1_PSCCTL0_FC12_CLK_SHIFT           (20U)
/*! FC12_CLK - Flexcomm Interface 12 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC12_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC12_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC12_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC13_CLK_MASK            (0x200000U)
#define CLKCTL1_PSCCTL0_FC13_CLK_SHIFT           (21U)
/*! FC13_CLK - Flexcomm Interface 13 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC13_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC13_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC13_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC14_SPI_CLK_MASK        (0x400000U)
#define CLKCTL1_PSCCTL0_FC14_SPI_CLK_SHIFT       (22U)
/*! FC14_SPI_CLK - Flexcomm Interface 14 SPI clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC14_SPI_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC14_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC14_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_FC15_I2C_CLK_MASK        (0x800000U)
#define CLKCTL1_PSCCTL0_FC15_I2C_CLK_SHIFT       (23U)
/*! FC15_I2C_CLK - Flexcomm Interface 15 I2C clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC15_I2C_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC15_I2C_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC15_I2C_CLK_MASK)

#define CLKCTL1_PSCCTL0_DMIC0_MASK               (0x1000000U)
#define CLKCTL1_PSCCTL0_DMIC0_SHIFT              (24U)
/*! DMIC0 - DMIC0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_DMIC0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_DMIC0_SHIFT)) & CLKCTL1_PSCCTL0_DMIC0_MASK)

#define CLKCTL1_PSCCTL0_FC16_SPI_CLK_MASK        (0x2000000U)
#define CLKCTL1_PSCCTL0_FC16_SPI_CLK_SHIFT       (25U)
/*! FC16_SPI_CLK - Flexcomm Interface 16 SPI clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FC16_SPI_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FC16_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_FC16_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_OSEVENT_TIMER_MASK       (0x8000000U)
#define CLKCTL1_PSCCTL0_OSEVENT_TIMER_SHIFT      (27U)
/*! OSEVENT_TIMER - OS event timer bus clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_OSEVENT_TIMER(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_OSEVENT_TIMER_SHIFT)) & CLKCTL1_PSCCTL0_OSEVENT_TIMER_MASK)

#define CLKCTL1_PSCCTL0_FlexIO_MASK              (0x20000000U)
#define CLKCTL1_PSCCTL0_FlexIO_SHIFT             (29U)
/*! FlexIO - FlexIO clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL0_FlexIO(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_FlexIO_SHIFT)) & CLKCTL1_PSCCTL0_FlexIO_MASK)
/*! @} */

/*! @name PSCCTL1 - Clock Control 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_HSGPIO0_CLK_MASK         (0x1U)
#define CLKCTL1_PSCCTL1_HSGPIO0_CLK_SHIFT        (0U)
/*! HSGPIO0_CLK - Non-secure GPIO0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO0_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO0_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO1_CLK_MASK         (0x2U)
#define CLKCTL1_PSCCTL1_HSGPIO1_CLK_SHIFT        (1U)
/*! HSGPIO1_CLK - Non-secure GPIO1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO1_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO1_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO2_CLK_MASK         (0x4U)
#define CLKCTL1_PSCCTL1_HSGPIO2_CLK_SHIFT        (2U)
/*! HSGPIO2_CLK - Non-secure GPIO2 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO2_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO2_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO2_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO3_CLK_MASK         (0x8U)
#define CLKCTL1_PSCCTL1_HSGPIO3_CLK_SHIFT        (3U)
/*! HSGPIO3_CLK - Non-secure GPIO3 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO3_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO3_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO3_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO4_CLK_MASK         (0x10U)
#define CLKCTL1_PSCCTL1_HSGPIO4_CLK_SHIFT        (4U)
/*! HSGPIO4_CLK - Non-secure GPIO4 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO4_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO4_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO4_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO5_CLK_MASK         (0x20U)
#define CLKCTL1_PSCCTL1_HSGPIO5_CLK_SHIFT        (5U)
/*! HSGPIO5_CLK - Non-secure GPIO5 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO5_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO5_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO5_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO6_CLK_MASK         (0x40U)
#define CLKCTL1_PSCCTL1_HSGPIO6_CLK_SHIFT        (6U)
/*! HSGPIO6_CLK - Non-secure GPIO6 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_HSGPIO6_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HSGPIO6_CLK_SHIFT)) & CLKCTL1_PSCCTL1_HSGPIO6_CLK_MASK)

#define CLKCTL1_PSCCTL1_HSGPIO7_CLK_MASK         (0x80U)
#define CLKCTL1_PSCCTL1_HSGPIO7_CLK_SHIFT        (7U)
/*! HSGPIO7_CLK - Non-secure GPIO7 clock control
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
/*! MU_CLK - Messaging Unit clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_MU_CLK(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_MU_CLK_SHIFT)) & CLKCTL1_PSCCTL1_MU_CLK_MASK)

#define CLKCTL1_PSCCTL1_SEMA_CLK_MASK            (0x20000000U)
#define CLKCTL1_PSCCTL1_SEMA_CLK_SHIFT           (29U)
/*! SEMA_CLK - Semaphore clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_SEMA_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SEMA_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SEMA_CLK_MASK)

#define CLKCTL1_PSCCTL1_FREQME_CLK_MASK          (0x80000000U)
#define CLKCTL1_PSCCTL1_FREQME_CLK_SHIFT         (31U)
/*! FREQME_CLK - Frequency Measurement clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL1_FREQME_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_FREQME_CLK_SHIFT)) & CLKCTL1_PSCCTL1_FREQME_CLK_MASK)
/*! @} */

/*! @name PSCCTL2 - Clock Control 2 */
/*! @{ */

#define CLKCTL1_PSCCTL2_CT32BIT0_CLK_MASK        (0x1U)
#define CLKCTL1_PSCCTL2_CT32BIT0_CLK_SHIFT       (0U)
/*! CT32BIT0_CLK - CT32BIT bit timer 0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT1_CLK_MASK        (0x2U)
#define CLKCTL1_PSCCTL2_CT32BIT1_CLK_SHIFT       (1U)
/*! CT32BIT1_CLK - CT32BIT bit timer 1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT1_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT2_CLK_MASK        (0x4U)
#define CLKCTL1_PSCCTL2_CT32BIT2_CLK_SHIFT       (2U)
/*! CT32BIT2_CLK - CT32BIT bit timer 2 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT2_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT2_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT2_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT3_CLK_MASK        (0x8U)
#define CLKCTL1_PSCCTL2_CT32BIT3_CLK_SHIFT       (3U)
/*! CT32BIT3_CLK - CT32BIT bit timer 3 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT3_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT3_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT3_CLK_MASK)

#define CLKCTL1_PSCCTL2_CT32BIT4_CLK_MASK        (0x10U)
#define CLKCTL1_PSCCTL2_CT32BIT4_CLK_SHIFT       (4U)
/*! CT32BIT4_CLK - CT32BIT bit timer 4 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CT32BIT4_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CT32BIT4_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CT32BIT4_CLK_MASK)

#define CLKCTL1_PSCCTL2_RTCLITE_CLK_MASK         (0x80U)
#define CLKCTL1_PSCCTL2_RTCLITE_CLK_SHIFT        (7U)
/*! RTCLITE_CLK - RTC clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_RTCLITE_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_RTCLITE_CLK_SHIFT)) & CLKCTL1_PSCCTL2_RTCLITE_CLK_MASK)

#define CLKCTL1_PSCCTL2_MRT0_CLK_MASK            (0x100U)
#define CLKCTL1_PSCCTL2_MRT0_CLK_SHIFT           (8U)
/*! MRT0_CLK - Multi-Rate Timer 0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_MRT0_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_MRT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_MRT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_WWDT1_CLK_MASK           (0x400U)
#define CLKCTL1_PSCCTL2_WWDT1_CLK_SHIFT          (10U)
/*! WWDT1_CLK - Watchdog Timer 1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_WWDT1_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_WWDT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_WWDT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_I3C0_CLK_MASK            (0x10000U)
#define CLKCTL1_PSCCTL2_I3C0_CLK_SHIFT           (16U)
/*! I3C0_CLK - I3C0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_I3C0_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_I3C0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_I3C0_CLK_MASK)

#define CLKCTL1_PSCCTL2_I3C1_CLK_MASK            (0x20000U)
#define CLKCTL1_PSCCTL2_I3C1_CLK_SHIFT           (17U)
/*! I3C1_CLK - I3C1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_I3C1_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_I3C1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_I3C1_CLK_MASK)

#define CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_MASK      (0x40000000U)
#define CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_SHIFT     (30U)
/*! GPIOINTCTL_CLK - PINT clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_GPIOINTCTL_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_GPIOINTCTL_CLK_MASK)

#define CLKCTL1_PSCCTL2_PIMCTL_CLK_MASK          (0x80000000U)
#define CLKCTL1_PSCCTL2_PIMCTL_CLK_SHIFT         (31U)
/*! PIMCTL_CLK - INPUTMUX clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_PIMCTL_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_PIMCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_PIMCTL_CLK_MASK)
/*! @} */

/*! @name PSCCTL0_SET - Clock Set 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_SET_FC0_CLK_MASK         (0x100U)
#define CLKCTL1_PSCCTL0_SET_FC0_CLK_SHIFT        (8U)
/*! FC0_CLK - Flexcomm Interface 0 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC0_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC0_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC0_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC1_CLK_MASK         (0x200U)
#define CLKCTL1_PSCCTL0_SET_FC1_CLK_SHIFT        (9U)
/*! FC1_CLK - Flexcomm Interface 1 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC1_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC1_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC1_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC2_CLK_MASK         (0x400U)
#define CLKCTL1_PSCCTL0_SET_FC2_CLK_SHIFT        (10U)
/*! FC2_CLK - Flexcomm Interface 2 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC2_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC2_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC2_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC3_CLK_MASK         (0x800U)
#define CLKCTL1_PSCCTL0_SET_FC3_CLK_SHIFT        (11U)
/*! FC3_CLK - Flexcomm Interface 3 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC3_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC3_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC3_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC4_CLK_MASK         (0x1000U)
#define CLKCTL1_PSCCTL0_SET_FC4_CLK_SHIFT        (12U)
/*! FC4_CLK - Flexcomm Interface 4 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC4_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC4_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC4_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC5_CLK_MASK         (0x2000U)
#define CLKCTL1_PSCCTL0_SET_FC5_CLK_SHIFT        (13U)
/*! FC5_CLK - Flexcomm Interface 5 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC5_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC5_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC5_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC6_CLK_MASK         (0x4000U)
#define CLKCTL1_PSCCTL0_SET_FC6_CLK_SHIFT        (14U)
/*! FC6_CLK - Flexcomm Interface 6 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC6_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC6_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC6_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC7_CLK_MASK         (0x8000U)
#define CLKCTL1_PSCCTL0_SET_FC7_CLK_SHIFT        (15U)
/*! FC7_CLK - Flexcomm Interface 7 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC7_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC7_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC7_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC8_CLK_MASK         (0x10000U)
#define CLKCTL1_PSCCTL0_SET_FC8_CLK_SHIFT        (16U)
/*! FC8_CLK - Flexcomm Interface 8 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC8_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC8_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC8_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC9_CLK_MASK         (0x20000U)
#define CLKCTL1_PSCCTL0_SET_FC9_CLK_SHIFT        (17U)
/*! FC9_CLK - Flexcomm Interface 9 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC9_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC9_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC9_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC10_CLK_MASK        (0x40000U)
#define CLKCTL1_PSCCTL0_SET_FC10_CLK_SHIFT       (18U)
/*! FC10_CLK - Flexcomm Interface 10 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC10_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC10_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC10_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC11_CLK_MASK        (0x80000U)
#define CLKCTL1_PSCCTL0_SET_FC11_CLK_SHIFT       (19U)
/*! FC11_CLK - Flexcomm Interface 11 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC11_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC11_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC11_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC12_CLK_MASK        (0x100000U)
#define CLKCTL1_PSCCTL0_SET_FC12_CLK_SHIFT       (20U)
/*! FC12_CLK - Flexcomm Interface 12 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC12_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC12_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC12_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC13_CLK_MASK        (0x200000U)
#define CLKCTL1_PSCCTL0_SET_FC13_CLK_SHIFT       (21U)
/*! FC13_CLK - Flexcomm Interface 13 clock set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC13_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC13_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC13_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_MASK    (0x400000U)
#define CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SHIFT   (22U)
/*! FC14_SPI_CLK - Flexcomm Interface 14 SPI clock control
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC14_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_MASK    (0x800000U)
#define CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SHIFT   (23U)
/*! FC15_I2C_CLK - Flexcomm Interface 15 I2C clock control
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC15_I2C_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_DMIC0_MASK           (0x1000000U)
#define CLKCTL1_PSCCTL0_SET_DMIC0_SHIFT          (24U)
/*! DMIC0 - DMIC0 clock control
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_DMIC0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_DMIC0_SHIFT)) & CLKCTL1_PSCCTL0_SET_DMIC0_MASK)

#define CLKCTL1_PSCCTL0_SET_FC16_SPI_CLK_MASK    (0x2000000U)
#define CLKCTL1_PSCCTL0_SET_FC16_SPI_CLK_SHIFT   (25U)
/*! FC16_SPI_CLK - Flexcomm Interface 16 SPI clock control
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FC16_SPI_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FC16_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_SET_FC16_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_MASK   (0x8000000U)
#define CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_SHIFT  (27U)
/*! OSEVENT_TIMER - OS event timer bus clock control
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_SHIFT)) & CLKCTL1_PSCCTL0_SET_OSEVENT_TIMER_MASK)

#define CLKCTL1_PSCCTL0_SET_FlexIO_MASK          (0x20000000U)
#define CLKCTL1_PSCCTL0_SET_FlexIO_SHIFT         (29U)
/*! FlexIO - FlexIO clock control
 *  0b0..No effect
 *  0b1..Sets the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_SET_FlexIO(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_FlexIO_SHIFT)) & CLKCTL1_PSCCTL0_SET_FlexIO_MASK)
/*! @} */

/*! @name PSCCTL1_SET - Clock Set 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_MASK     (0x1U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SHIFT    (0U)
/*! HSGPIO0_CLK - Non-secure GPIO0 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO0_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_MASK     (0x2U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SHIFT    (1U)
/*! HSGPIO1_CLK - Non-secure GPIO1 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO1_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_MASK     (0x4U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SHIFT    (2U)
/*! HSGPIO2_CLK - Non-secure GPIO2 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO2_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_MASK     (0x8U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SHIFT    (3U)
/*! HSGPIO3_CLK - Non-secure GPIO3 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO3_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_MASK     (0x10U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SHIFT    (4U)
/*! HSGPIO4_CLK - Non-secure GPIO4 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO4_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_MASK     (0x20U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SHIFT    (5U)
/*! HSGPIO5_CLK - Non-secure GPIO5 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO5_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_MASK     (0x40U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SHIFT    (6U)
/*! HSGPIO6_CLK - Non-secure GPIO6 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO6_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_MASK     (0x80U)
#define CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SHIFT    (7U)
/*! HSGPIO7_CLK - Non-secure GPIO7 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_HSGPIO7_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_CRC_CLK_MASK         (0x10000U)
#define CLKCTL1_PSCCTL1_SET_CRC_CLK_SHIFT        (16U)
/*! CRC_CLK - CRC clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_CRC_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CRC_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_CRC_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_DMAC0_CLK_MASK       (0x800000U)
#define CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SHIFT      (23U)
/*! DMAC0_CLK - DMAC0 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_DMAC0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_DMAC0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_DMAC0_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_DMAC1_CLK_MASK       (0x1000000U)
#define CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SHIFT      (24U)
/*! DMAC1_CLK - DMAC1 clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_DMAC1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_DMAC1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_DMAC1_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_MU_CLK_MASK          (0x10000000U)
#define CLKCTL1_PSCCTL1_SET_MU_CLK_SHIFT         (28U)
/*! MU_CLK - Messaging Unit clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_MU_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_MU_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_MU_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_SEMA_CLK_MASK        (0x20000000U)
#define CLKCTL1_PSCCTL1_SET_SEMA_CLK_SHIFT       (29U)
/*! SEMA_CLK - Semaphore clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_SEMA_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_SEMA_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_SEMA_CLK_MASK)

#define CLKCTL1_PSCCTL1_SET_FREQME_CLK_MASK      (0x80000000U)
#define CLKCTL1_PSCCTL1_SET_FREQME_CLK_SHIFT     (31U)
/*! FREQME_CLK - Frequency Measurement clock control set
 *  0b0..No effect
 *  0b1..Sets the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_SET_FREQME_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_FREQME_CLK_SHIFT)) & CLKCTL1_PSCCTL1_SET_FREQME_CLK_MASK)
/*! @} */

/*! @name PSCCTL2_SET - Clock Set 2 */
/*! @{ */

#define CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_MASK    (0x1U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SHIFT   (0U)
/*! CT32BIT0_CLK - CT32BIT bit timer 0 clock set
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_MASK    (0x2U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SHIFT   (1U)
/*! CT32BIT1_CLK - CT32BIT bit timer 1 clock set
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_MASK    (0x4U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SHIFT   (2U)
/*! CT32BIT2_CLK - CT32BIT bit timer 2 clock set
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT2_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_MASK    (0x8U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SHIFT   (3U)
/*! CT32BIT3_CLK - CT32BIT bit timer 3 clock set
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT3_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_MASK    (0x10U)
#define CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SHIFT   (4U)
/*! CT32BIT4_CLK - CT32BIT bit timer 4 clock set
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_CT32BIT4_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_RTCLITE_CLK_MASK     (0x80U)
#define CLKCTL1_PSCCTL2_SET_RTCLITE_CLK_SHIFT    (7U)
/*! RTCLITE_CLK - RTC clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_RTCLITE_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_RTCLITE_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_RTCLITE_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_MRT0_CLK_MASK        (0x100U)
#define CLKCTL1_PSCCTL2_SET_MRT0_CLK_SHIFT       (8U)
/*! MRT0_CLK - Multi-Rate Timer 0 clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_MRT0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_MRT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_MRT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_WWDT1_CLK_MASK       (0x400U)
#define CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SHIFT      (10U)
/*! WWDT1_CLK - Watchdog Timer 1 clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_WWDT1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_WWDT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_WWDT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_I3C0_CLK_MASK        (0x10000U)
#define CLKCTL1_PSCCTL2_SET_I3C0_CLK_SHIFT       (16U)
/*! I3C0_CLK - I3C0 clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_I3C0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_I3C0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_I3C0_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_I3C1_CLK_MASK        (0x20000U)
#define CLKCTL1_PSCCTL2_SET_I3C1_CLK_SHIFT       (17U)
/*! I3C1_CLK - I3C1 clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_I3C1_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_I3C1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_I3C1_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_MASK  (0x40000000U)
#define CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SHIFT (30U)
/*! GPIOINTCTL_CLK - PINT clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_GPIOINTCTL_CLK_MASK)

#define CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_MASK      (0x80000000U)
#define CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SHIFT     (31U)
/*! PIMCTL_CLK - INPUTMUX clock control set
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_SET_PIMCTL_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_SET_PIMCTL_CLK_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - Clock Clear 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_CLR_FC0_CLK_MASK         (0x100U)
#define CLKCTL1_PSCCTL0_CLR_FC0_CLK_SHIFT        (8U)
/*! FC0_CLK - Flexcomm Interface 0 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC0_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC0_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC0_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC1_CLK_MASK         (0x200U)
#define CLKCTL1_PSCCTL0_CLR_FC1_CLK_SHIFT        (9U)
/*! FC1_CLK - Flexcomm Interface 1 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC1_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC1_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC1_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC2_CLK_MASK         (0x400U)
#define CLKCTL1_PSCCTL0_CLR_FC2_CLK_SHIFT        (10U)
/*! FC2_CLK - Flexcomm Interface 2 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC2_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC2_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC2_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC3_CLK_MASK         (0x800U)
#define CLKCTL1_PSCCTL0_CLR_FC3_CLK_SHIFT        (11U)
/*! FC3_CLK - Flexcomm Interface 3 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC3_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC3_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC3_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC4_CLK_MASK         (0x1000U)
#define CLKCTL1_PSCCTL0_CLR_FC4_CLK_SHIFT        (12U)
/*! FC4_CLK - Flexcomm Interface 4 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC4_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC4_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC4_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC5_CLK_MASK         (0x2000U)
#define CLKCTL1_PSCCTL0_CLR_FC5_CLK_SHIFT        (13U)
/*! FC5_CLK - Flexcomm Interface 5 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC5_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC5_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC5_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC6_CLK_MASK         (0x4000U)
#define CLKCTL1_PSCCTL0_CLR_FC6_CLK_SHIFT        (14U)
/*! FC6_CLK - Flexcomm Interface 6 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC6_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC6_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC6_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC7_CLK_MASK         (0x8000U)
#define CLKCTL1_PSCCTL0_CLR_FC7_CLK_SHIFT        (15U)
/*! FC7_CLK - Flexcomm Interface 7 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC7_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC7_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC7_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC8_CLK_MASK         (0x10000U)
#define CLKCTL1_PSCCTL0_CLR_FC8_CLK_SHIFT        (16U)
/*! FC8_CLK - Flexcomm Interface 8 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC8_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC8_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC8_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC9_CLK_MASK         (0x20000U)
#define CLKCTL1_PSCCTL0_CLR_FC9_CLK_SHIFT        (17U)
/*! FC9_CLK - Flexcomm Interface 9 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC9_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC9_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC9_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC10_CLK_MASK        (0x40000U)
#define CLKCTL1_PSCCTL0_CLR_FC10_CLK_SHIFT       (18U)
/*! FC10_CLK - Flexcomm Interface 10 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC10_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC10_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC10_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC11_CLK_MASK        (0x80000U)
#define CLKCTL1_PSCCTL0_CLR_FC11_CLK_SHIFT       (19U)
/*! FC11_CLK - Flexcomm Interface 11 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC11_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC11_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC11_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC12_CLK_MASK        (0x100000U)
#define CLKCTL1_PSCCTL0_CLR_FC12_CLK_SHIFT       (20U)
/*! FC12_CLK - Flexcomm Interface 12 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC12_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC12_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC12_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC13_CLK_MASK        (0x200000U)
#define CLKCTL1_PSCCTL0_CLR_FC13_CLK_SHIFT       (21U)
/*! FC13_CLK - Flexcomm Interface 13 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC13_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC13_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC13_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_MASK    (0x400000U)
#define CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_SHIFT   (22U)
/*! FC14_SPI_CLK - Flexcomm Interface 14 SPI clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC14_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_MASK    (0x800000U)
#define CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_SHIFT   (23U)
/*! FC15_I2C_CLK - Flexcomm Interface 15 I2C clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC15_I2C_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_DMIC0_MASK           (0x1000000U)
#define CLKCTL1_PSCCTL0_CLR_DMIC0_SHIFT          (24U)
/*! DMIC0 - DMIC0 clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_DMIC0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_DMIC0_SHIFT)) & CLKCTL1_PSCCTL0_CLR_DMIC0_MASK)

#define CLKCTL1_PSCCTL0_CLR_FC16_SPI_CLK_MASK    (0x2000000U)
#define CLKCTL1_PSCCTL0_CLR_FC16_SPI_CLK_SHIFT   (25U)
/*! FC16_SPI_CLK - Flexcomm Interface 16 SPI clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FC16_SPI_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FC16_SPI_CLK_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FC16_SPI_CLK_MASK)

#define CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_MASK   (0x8000000U)
#define CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_SHIFT  (27U)
/*! OSEVENT_TIMER - OS event timer bus clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_SHIFT)) & CLKCTL1_PSCCTL0_CLR_OSEVENT_TIMER_MASK)

#define CLKCTL1_PSCCTL0_CLR_FlexIO_MASK          (0x20000000U)
#define CLKCTL1_PSCCTL0_CLR_FlexIO_SHIFT         (29U)
/*! FlexIO - FlexIO clock control clear
 *  0b0..No effect
 *  0b1..Clears the PSCCTL0 bit
 */
#define CLKCTL1_PSCCTL0_CLR_FlexIO(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_FlexIO_SHIFT)) & CLKCTL1_PSCCTL0_CLR_FlexIO_MASK)
/*! @} */

/*! @name PSCCTL1_CLR - Clock Clear 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_MASK     (0x1U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_SHIFT    (0U)
/*! HSGPIO0_CLK - Non-secure GPIO0 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO0_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_MASK     (0x2U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_SHIFT    (1U)
/*! HSGPIO1_CLK - Non-secure GPIO1 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO1_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_MASK     (0x4U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_SHIFT    (2U)
/*! HSGPIO2_CLK - Non-secure GPIO2 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO2_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_MASK     (0x8U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_SHIFT    (3U)
/*! HSGPIO3_CLK - Non-secure GPIO3 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO3_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_MASK     (0x10U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_SHIFT    (4U)
/*! HSGPIO4_CLK - Non-secure GPIO4 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO4_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_MASK     (0x20U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_SHIFT    (5U)
/*! HSGPIO5_CLK - Non-secure GPIO5 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO5_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_MASK     (0x40U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_SHIFT    (6U)
/*! HSGPIO6_CLK - Non-secure GPIO6 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO6_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_MASK     (0x80U)
#define CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_SHIFT    (7U)
/*! HSGPIO7_CLK - Non-secure GPIO7 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HSGPIO7_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_CRC_CLK_MASK         (0x10000U)
#define CLKCTL1_PSCCTL1_CLR_CRC_CLK_SHIFT        (16U)
/*! CRC_CLK - CRC clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_CRC_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CRC_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CRC_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_MASK       (0x800000U)
#define CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_SHIFT      (23U)
/*! DMAC0_CLK - DMAC0 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_DMAC0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_DMAC0_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_MASK       (0x1000000U)
#define CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_SHIFT      (24U)
/*! DMAC1_CLK - DMAC1 clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_DMAC1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_DMAC1_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_MU_CLK_MASK          (0x10000000U)
#define CLKCTL1_PSCCTL1_CLR_MU_CLK_SHIFT         (28U)
/*! MU_CLK - Messaging Unit clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_MU_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_MU_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_MU_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_SEMA_CLK_MASK        (0x20000000U)
#define CLKCTL1_PSCCTL1_CLR_SEMA_CLK_SHIFT       (29U)
/*! SEMA_CLK - Semaphore clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_SEMA_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_SEMA_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_SEMA_CLK_MASK)

#define CLKCTL1_PSCCTL1_CLR_FREQME_CLK_MASK      (0x80000000U)
#define CLKCTL1_PSCCTL1_CLR_FREQME_CLK_SHIFT     (31U)
/*! FREQME_CLK - Frequency Measurement clock control
 *  0b0..No effect
 *  0b1..Clears the PSCCTL1 bit
 */
#define CLKCTL1_PSCCTL1_CLR_FREQME_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_FREQME_CLK_SHIFT)) & CLKCTL1_PSCCTL1_CLR_FREQME_CLK_MASK)
/*! @} */

/*! @name PSCCTL2_CLR - Clock Clear 2 */
/*! @{ */

#define CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_MASK    (0x1U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_SHIFT   (0U)
/*! CT32BIT0_CLK - CT32BIT bit timer 0 clock clear
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_MASK    (0x2U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_SHIFT   (1U)
/*! CT32BIT1_CLK - CT32BIT bit timer 1 clock clear
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_MASK    (0x4U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_SHIFT   (2U)
/*! CT32BIT2_CLK - CT32BIT bit timer 2 clock clear
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT2_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_MASK    (0x8U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_SHIFT   (3U)
/*! CT32BIT3_CLK - CT32BIT bit timer 3 clock clear
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT3_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_MASK    (0x10U)
#define CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_SHIFT   (4U)
/*! CT32BIT4_CLK - CT32BIT bit timer 4 clock clear
 *  0b0..No Effect
 *  0b1..Set Bit
 */
#define CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_CT32BIT4_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_RTCLITE_CLK_MASK     (0x80U)
#define CLKCTL1_PSCCTL2_CLR_RTCLITE_CLK_SHIFT    (7U)
/*! RTCLITE_CLK - RTC clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_RTCLITE_CLK(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_RTCLITE_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_RTCLITE_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_MRT0_CLK_MASK        (0x100U)
#define CLKCTL1_PSCCTL2_CLR_MRT0_CLK_SHIFT       (8U)
/*! MRT0_CLK - Multi-Rate Timer 0 clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_MRT0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_MRT0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_MRT0_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_MASK       (0x400U)
#define CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_SHIFT      (10U)
/*! WWDT1_CLK - Watchdog Timer 1 clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_WWDT1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_WWDT1_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_I3C0_CLK_MASK        (0x10000U)
#define CLKCTL1_PSCCTL2_CLR_I3C0_CLK_SHIFT       (16U)
/*! I3C0_CLK - I3C0 clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_I3C0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_I3C0_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_I3C0_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_I3C1_CLK_MASK        (0x20000U)
#define CLKCTL1_PSCCTL2_CLR_I3C1_CLK_SHIFT       (17U)
/*! I3C1_CLK - I3C1 clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_I3C1_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_I3C1_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_I3C1_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_MASK  (0x40000000U)
#define CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_SHIFT (30U)
/*! GPIOINTCTL_CLK - PINT clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_GPIOINTCTL_CLK_MASK)

#define CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_MASK      (0x80000000U)
#define CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_SHIFT     (31U)
/*! PIMCTL_CLK - INPUTMUX clock control clear
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_SHIFT)) & CLKCTL1_PSCCTL2_CLR_PIMCTL_CLK_MASK)
/*! @} */

/*! @name AUDIOPLL0CLKSEL - Audio PLL0 Clock Select */
/*! @{ */

#define CLKCTL1_AUDIOPLL0CLKSEL_SEL_MASK         (0x7U)
#define CLKCTL1_AUDIOPLL0CLKSEL_SEL_SHIFT        (0U)
/*! SEL - Audio PLL0 Clock Select
 *  0b000..FRO_DIV8
 *  0b001..OSC_CLK clock (User-Selectable)
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_AUDIOPLL0CLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CLKSEL_SEL_SHIFT)) & CLKCTL1_AUDIOPLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOPLL0CTL0 - Audio PLL0 Control 0 */
/*! @{ */

#define CLKCTL1_AUDIOPLL0CTL0_BYPASS_MASK        (0x1U)
#define CLKCTL1_AUDIOPLL0CTL0_BYPASS_SHIFT       (0U)
/*! BYPASS - AUDIOPLL0 BYPASS Mode
 *  0b0..PFD outputs are PFD-programmed clocks
 *  0b1..Bypass Mode. PFD outputs are sourced directly from the reference input clock
 */
#define CLKCTL1_AUDIOPLL0CTL0_BYPASS(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_BYPASS_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_BYPASS_MASK)

#define CLKCTL1_AUDIOPLL0CTL0_RESET_MASK         (0x2U)
#define CLKCTL1_AUDIOPLL0CTL0_RESET_SHIFT        (1U)
/*! RESET - AUDIOPLL0 Reset
 *  0b0..AUDIOPLL0 reset is removed
 *  0b1..AUDIOPLL0 is placed into reset
 */
#define CLKCTL1_AUDIOPLL0CTL0_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_RESET_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_RESET_MASK)

#define CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_MASK (0x2000U)
#define CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_SHIFT (13U)
/*! HOLDRINGOFF_ENA - Hold Ring Off Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_HOLDRINGOFF_ENA_MASK)

#define CLKCTL1_AUDIOPLL0CTL0_MULT_MASK          (0xFF0000U)
#define CLKCTL1_AUDIOPLL0CTL0_MULT_SHIFT         (16U)
/*! MULT - Multiplication Factor
 *  0b00010000..Multiply by 16
 *  0b00010001..Multiply by 17
 *  0b00010010..Multiply by 18
 *  0b00010011..Multiply by 19
 *  0b00010100..Multiply by 20
 *  0b00010101..Multiply by 21
 *  0b00010110..Multiply by 22
 */
#define CLKCTL1_AUDIOPLL0CTL0_MULT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0CTL0_MULT_SHIFT)) & CLKCTL1_AUDIOPLL0CTL0_MULT_MASK)
/*! @} */

/*! @name AUDIOPLL0LOCKTIMEDIV2 - Audio PLL0 Lock Time Divide-by-2 */
/*! @{ */

#define CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - AUDIOPLL0 Lock Time Divide-by-2 */
#define CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & CLKCTL1_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name AUDIOPLL0NUM - Audio PLL0 Numerator */
/*! @{ */

#define CLKCTL1_AUDIOPLL0NUM_NUM_MASK            (0x3FFFFFFFU)
#define CLKCTL1_AUDIOPLL0NUM_NUM_SHIFT           (0U)
/*! NUM - Numerator */
#define CLKCTL1_AUDIOPLL0NUM_NUM(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0NUM_NUM_SHIFT)) & CLKCTL1_AUDIOPLL0NUM_NUM_MASK)
/*! @} */

/*! @name AUDIOPLL0DENOM - Audio PLL0 Denominator */
/*! @{ */

#define CLKCTL1_AUDIOPLL0DENOM_DENOM_MASK        (0x3FFFFFFFU)
#define CLKCTL1_AUDIOPLL0DENOM_DENOM_SHIFT       (0U)
/*! DENOM - Denominator */
#define CLKCTL1_AUDIOPLL0DENOM_DENOM(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0DENOM_DENOM_SHIFT)) & CLKCTL1_AUDIOPLL0DENOM_DENOM_MASK)
/*! @} */

/*! @name AUDIOPLL0PFD - Audio PLL0 PFD */
/*! @{ */

#define CLKCTL1_AUDIOPLL0PFD_PFD0_MASK           (0x3FU)
#define CLKCTL1_AUDIOPLL0PFD_PFD0_SHIFT          (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CLKCTL1_AUDIOPLL0PFD_PFD0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD0_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD0_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_MASK    (0x40U)
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_SHIFT   (6U)
/*! PFD0_CLKRDY - PFD0 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD0_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_MASK   (0x80U)
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_SHIFT  (7U)
/*! PFD0_CLKGATE - PFD0 Clock Gate
 *  0b0..PFD0 clock is not gated
 *  0b1..PFD0 clock is gated
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD0_CLKGATE_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD1_MASK           (0x3F00U)
#define CLKCTL1_AUDIOPLL0PFD_PFD1_SHIFT          (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CLKCTL1_AUDIOPLL0PFD_PFD1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD1_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD1_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_MASK    (0x4000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_SHIFT   (14U)
/*! PFD1_CLKRDY - PFD1 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD1_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_MASK   (0x8000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_SHIFT  (15U)
/*! PFD1_CLKGATE - PFD1 Clock Gate
 *  0b0..PFD1 clock is not gated
 *  0b1..PFD1 clock is gated
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD1_CLKGATE_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD2_MASK           (0x3F0000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD2_SHIFT          (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CLKCTL1_AUDIOPLL0PFD_PFD2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD2_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD2_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_MASK    (0x400000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_SHIFT   (22U)
/*! PFD2_CLKRDY - PFD2 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD2_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_MASK   (0x800000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_SHIFT  (23U)
/*! PFD2_CLKGATE - PFD2 Clock Gate
 *  0b0..PFD2 clock is not gated
 *  0b1..PFD2 clock is gated
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD2_CLKGATE_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD3_MASK           (0x3F000000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD3_SHIFT          (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CLKCTL1_AUDIOPLL0PFD_PFD3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD3_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD3_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_MASK    (0x40000000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_SHIFT   (30U)
/*! PFD3_CLKRDY - PFD3 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD3_CLKRDY_MASK)

#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_MASK   (0x80000000U)
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_SHIFT  (31U)
/*! PFD3_CLKGATE - PFD3 Clock Gate
 *  0b0..PFD3 clock is not gated
 *  0b1..PFD3 clock is gated
 */
#define CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_SHIFT)) & CLKCTL1_AUDIOPLL0PFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name AUDIOPLLCLKDIV - Audio PLL Clock Divider */
/*! @{ */

#define CLKCTL1_AUDIOPLLCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL1_AUDIOPLLCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Audio PLL Clock Divider Value */
#define CLKCTL1_AUDIOPLLCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_DIV_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_DIV_MASK)

#define CLKCTL1_AUDIOPLLCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL1_AUDIOPLLCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_AUDIOPLLCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_RESET_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_RESET_MASK)

#define CLKCTL1_AUDIOPLLCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL1_AUDIOPLLCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_AUDIOPLLCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_HALT_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_HALT_MASK)

#define CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished
 *  0b1..The Divider value has changed
 */
#define CLKCTL1_AUDIOPLLCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_AUDIOPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPCPUCLKDIV - DSP CPU Clock Divider */
/*! @{ */

#define CLKCTL1_DSPCPUCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_DSPCPUCLKDIV_DIV_SHIFT           (0U)
/*! DIV - DSP Clock Divider Value */
#define CLKCTL1_DSPCPUCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_DIV_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_DIV_MASK)

#define CLKCTL1_DSPCPUCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_DSPCPUCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_DSPCPUCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_RESET_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_RESET_MASK)

#define CLKCTL1_DSPCPUCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_DSPCPUCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_DSPCPUCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_HALT_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_HALT_MASK)

#define CLKCTL1_DSPCPUCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_DSPCPUCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_DSPCPUCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_DSPCPUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPCPUCLKSELA - DSP CPU Clock Select A */
/*! @{ */

#define CLKCTL1_DSPCPUCLKSELA_SEL_MASK           (0x3U)
#define CLKCTL1_DSPCPUCLKSELA_SEL_SHIFT          (0U)
/*! SEL - DSP Main 1st Stage Control Clock Source
 *  0b00..FRO_DIV1 Clock
 *  0b01..OSC_CLK Clock
 *  0b10..Low Power Oscillator Clock (LPOSC)
 *  0b11..Reserved
 */
#define CLKCTL1_DSPCPUCLKSELA_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKSELA_SEL_SHIFT)) & CLKCTL1_DSPCPUCLKSELA_SEL_MASK)
/*! @} */

/*! @name DSPCPUCLKSELB - DSP CPU Clock Select B */
/*! @{ */

#define CLKCTL1_DSPCPUCLKSELB_SEL_MASK           (0x3U)
#define CLKCTL1_DSPCPUCLKSELB_SEL_SHIFT          (0U)
/*! SEL - Main Clock Source
 *  0b00..MAINCLKSELA 1st Stage Clock
 *  0b01..Main System PLL Clock
 *  0b10..DSP System PLL Clock
 *  0b11..RTC 32 KHz Clock
 */
#define CLKCTL1_DSPCPUCLKSELB_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DSPCPUCLKSELB_SEL_SHIFT)) & CLKCTL1_DSPCPUCLKSELB_SEL_MASK)
/*! @} */

/*! @name OSEVENTTFCLKSEL - OS Event Timer Functional Clock Select */
/*! @{ */

#define CLKCTL1_OSEVENTTFCLKSEL_SEL_MASK         (0x7U)
#define CLKCTL1_OSEVENTTFCLKSEL_SEL_SHIFT        (0U)
/*! SEL - OS Event Timer Functional Clock Source
 *  0b000..Low Power Oscillator Clock (LPOSC)
 *  0b001..RTC 32 KHz Clock
 *  0b010..HCLK Free-Running Clock (Global Time Stamping)
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_OSEVENTTFCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_OSEVENTTFCLKSEL_SEL_SHIFT)) & CLKCTL1_OSEVENTTFCLKSEL_SEL_MASK)
/*! @} */

/*! @name FRGCLKSEL - Fractional Rate Generator 0 Clock Select..Fractional Rate Generator 16 Clock Select */
/*! @{ */

#define CLKCTL1_FRGCLKSEL_SEL_MASK               (0x7U)
#define CLKCTL1_FRGCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Fractional Generator 16 Clock Source
 *  0b000..Main Clock
 *  0b001..FRG PLL Clock
 *  0b010..FRO_DIV4 clock
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_FRGCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGCLKSEL_SEL_SHIFT)) & CLKCTL1_FRGCLKSEL_SEL_MASK)
/*! @} */

/* The count of CLKCTL1_FRGCLKSEL */
#define CLKCTL1_FRGCLKSEL_COUNT                  (17U)

/*! @name FRGCTL - Fractional Rate Generator 0 Control..Fractional Rate Generator 16 Control */
/*! @{ */

#define CLKCTL1_FRGCTL_DIV_MASK                  (0xFFU)
#define CLKCTL1_FRGCTL_DIV_SHIFT                 (0U)
#define CLKCTL1_FRGCTL_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGCTL_DIV_SHIFT)) & CLKCTL1_FRGCTL_DIV_MASK)

#define CLKCTL1_FRGCTL_MULT_MASK                 (0xFF00U)
#define CLKCTL1_FRGCTL_MULT_SHIFT                (8U)
#define CLKCTL1_FRGCTL_MULT(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGCTL_MULT_SHIFT)) & CLKCTL1_FRGCTL_MULT_MASK)
/*! @} */

/* The count of CLKCTL1_FRGCTL */
#define CLKCTL1_FRGCTL_COUNT                     (17U)

/*! @name FCFCLKSEL - Flexcomm0 Clock Select..Flexcomm16 Clock Select */
/*! @{ */

#define CLKCTL1_FCFCLKSEL_SEL_MASK               (0x7U)
#define CLKCTL1_FCFCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Flexcomm Functional Clock Source
 *  0b000..FRO_DIV4 clock
 *  0b001..Audio PLL Clock
 *  0b010..Master Clock In
 *  0b011..FCn FRG Clock
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_FCFCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKSEL_SEL_SHIFT)) & CLKCTL1_FCFCLKSEL_SEL_MASK)
/*! @} */

/* The count of CLKCTL1_FCFCLKSEL */
#define CLKCTL1_FCFCLKSEL_COUNT                  (17U)

/*! @name FRG17CLKSEL - Fractional Rate Generator 17 Clock Select */
/*! @{ */

#define CLKCTL1_FRG17CLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_FRG17CLKSEL_SEL_SHIFT            (0U)
/*! SEL - Fractional Generator 17 Clock Source
 *  0b000..Main Clock
 *  0b001..FRG PLL Clock
 *  0b010..FRO_DIV4 clock
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_FRG17CLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG17CLKSEL_SEL_SHIFT)) & CLKCTL1_FRG17CLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG17CTL - Fractional Rate Generator 17 Control */
/*! @{ */

#define CLKCTL1_FRG17CTL_DIV_MASK                (0xFFU)
#define CLKCTL1_FRG17CTL_DIV_SHIFT               (0U)
#define CLKCTL1_FRG17CTL_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG17CTL_DIV_SHIFT)) & CLKCTL1_FRG17CTL_DIV_MASK)

#define CLKCTL1_FRG17CTL_MULT_MASK               (0xFF00U)
#define CLKCTL1_FRG17CTL_MULT_SHIFT              (8U)
#define CLKCTL1_FRG17CTL_MULT(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRG17CTL_MULT_SHIFT)) & CLKCTL1_FRG17CTL_MULT_MASK)
/*! @} */

/*! @name FLEXIOCLKSEL - FlexIO Clock Select */
/*! @{ */

#define CLKCTL1_FLEXIOCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_FLEXIOCLKSEL_SEL_SHIFT           (0U)
/*! SEL - FlexIO Functional Clock Source
 *  0b000..FRO_DIV2 Clock
 *  0b001..Audio PLL Clock
 *  0b010..Master Clock In
 *  0b011..FC17 FRG Clock
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_FLEXIOCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FLEXIOCLKSEL_SEL_SHIFT)) & CLKCTL1_FLEXIOCLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXIOCLKDIV - FlexIO Clock Divider */
/*! @{ */

#define CLKCTL1_FLEXIOCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_FLEXIOCLKDIV_DIV_SHIFT           (0U)
/*! DIV - FLEXIO Clock Divider Value */
#define CLKCTL1_FLEXIOCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FLEXIOCLKDIV_DIV_SHIFT)) & CLKCTL1_FLEXIOCLKDIV_DIV_MASK)

#define CLKCTL1_FLEXIOCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_FLEXIOCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_FLEXIOCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FLEXIOCLKDIV_RESET_SHIFT)) & CLKCTL1_FLEXIOCLKDIV_RESET_MASK)

#define CLKCTL1_FLEXIOCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_FLEXIOCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_FLEXIOCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FLEXIOCLKDIV_HALT_SHIFT)) & CLKCTL1_FLEXIOCLKDIV_HALT_MASK)

#define CLKCTL1_FLEXIOCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_FLEXIOCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed
 */
#define CLKCTL1_FLEXIOCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FLEXIOCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_FLEXIOCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name FRGPLLCLKDIV - Fractional Rate Generator PLL Clock Divider */
/*! @{ */

#define CLKCTL1_FRGPLLCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_FRGPLLCLKDIV_DIV_SHIFT           (0U)
/*! DIV - FRG PLL Clock Divider Value */
#define CLKCTL1_FRGPLLCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_DIV_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_DIV_MASK)

#define CLKCTL1_FRGPLLCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_FRGPLLCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_FRGPLLCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_RESET_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_RESET_MASK)

#define CLKCTL1_FRGPLLCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_FRGPLLCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_FRGPLLCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_HALT_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_HALT_MASK)

#define CLKCTL1_FRGPLLCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_FRGPLLCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_FRGPLLCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FRGPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_FRGPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DMIC0FCLKSEL - DMIC0 Functional Clock Select */
/*! @{ */

#define CLKCTL1_DMIC0FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_DMIC0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - DMIC Functional Clock Source
 *  0b000..FRO Clock (Divided-by-4 selection)
 *  0b001..Audio PLL Clock
 *  0b010..Master Clock In
 *  0b011..Low Power Oscillator Clock (LPOSC)
 *  0b100..32 KHz Wake Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_DMIC0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKSEL_SEL_SHIFT)) & CLKCTL1_DMIC0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name DMIC0FCLKDIV - DMIC0 Functional Clock Divider */
/*! @{ */

#define CLKCTL1_DMIC0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_DMIC0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - 32 KHz Wake Clock Divider Value */
#define CLKCTL1_DMIC0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_DIV_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_DIV_MASK)

#define CLKCTL1_DMIC0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_DMIC0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_DMIC0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_RESET_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_RESET_MASK)

#define CLKCTL1_DMIC0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_DMIC0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_DMIC0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_HALT_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_HALT_MASK)

#define CLKCTL1_DMIC0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_DMIC0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_DMIC0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_DMIC0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_DMIC0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CT32BITFCLKSEL - CT32BIT bit timer 0 Functional Clock Select..CT32BIT bit timer 4 Functional Clock Select */
/*! @{ */

#define CLKCTL1_CT32BITFCLKSEL_SEL_MASK          (0x7U)
#define CLKCTL1_CT32BITFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - CT32BIT bit timer 4 Functional Clock Source
 *  0b000..Main Clock
 *  0b001..FRO_DIV1 Clock
 *  0b010..Audio PLL Clock
 *  0b011..Master Clock In
 *  0b100..32 KHZ Wake Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_CT32BITFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CT32BITFCLKSEL_SEL_SHIFT)) & CLKCTL1_CT32BITFCLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOMCLKSEL - Audio MCLK Clock Select */
/*! @{ */

#define CLKCTL1_AUDIOMCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_AUDIOMCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Audio MCLK Clock Source Select
 *  0b000..FRO_DIV8 Clock
 *  0b001..AUDIO PLL Clock (Shared Domain)
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_AUDIOMCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKSEL_SEL_SHIFT)) & CLKCTL1_AUDIOMCLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOMCLKDIV - Audio MCLK Clock Divider */
/*! @{ */

#define CLKCTL1_AUDIOMCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_AUDIOMCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Audio MCLK Clock Divider Value */
#define CLKCTL1_AUDIOMCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_DIV_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_DIV_MASK)

#define CLKCTL1_AUDIOMCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_AUDIOMCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_AUDIOMCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_RESET_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_RESET_MASK)

#define CLKCTL1_AUDIOMCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_AUDIOMCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_AUDIOMCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_HALT_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_HALT_MASK)

#define CLKCTL1_AUDIOMCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_AUDIOMCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_AUDIOMCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOMCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_AUDIOMCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLKOUTSEL0 - CLKOUT Clock Select 0 */
/*! @{ */

#define CLKCTL1_CLKOUTSEL0_SEL_MASK              (0x7U)
#define CLKCTL1_CLKOUTSEL0_SEL_SHIFT             (0U)
/*! SEL - Clock Output Select 1st Stage
 *  0b000..OSC_CLK Clock
 *  0b001..Low Power Oscillator Clock (LPOSC)
 *  0b010..FRO_DIV2 Clock
 *  0b011..Main Clock
 *  0b100..DSP Main Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_CLKOUTSEL0_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTSEL0_SEL_SHIFT)) & CLKCTL1_CLKOUTSEL0_SEL_MASK)
/*! @} */

/*! @name CLKOUTSEL1 - CLKOUT Clock Select 1 */
/*! @{ */

#define CLKCTL1_CLKOUTSEL1_SEL_MASK              (0x7U)
#define CLKCTL1_CLKOUTSEL1_SEL_SHIFT             (0U)
/*! SEL - Clock Out Source
 *  0b000..CLKOUTSEL0 Multiplexed Output
 *  0b001..Main System PLL Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..DSP PLL Clock
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..AUDIO PLL Clock
 *  0b110..32 KHz RTC Clock
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_CLKOUTSEL1_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTSEL1_SEL_SHIFT)) & CLKCTL1_CLKOUTSEL1_SEL_MASK)
/*! @} */

/*! @name CLKOUTFCLKDIV - CLKOUT Functional Clock Divider */
/*! @{ */

#define CLKCTL1_CLKOUTFCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL1_CLKOUTFCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock-Out Clock Divider Value */
#define CLKCTL1_CLKOUTFCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTFCLKDIV_DIV_SHIFT)) & CLKCTL1_CLKOUTFCLKDIV_DIV_MASK)

#define CLKCTL1_CLKOUTFCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL1_CLKOUTFCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_CLKOUTFCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTFCLKDIV_RESET_SHIFT)) & CLKCTL1_CLKOUTFCLKDIV_RESET_MASK)

#define CLKCTL1_CLKOUTFCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL1_CLKOUTFCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_CLKOUTFCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTFCLKDIV_HALT_SHIFT)) & CLKCTL1_CLKOUTFCLKDIV_HALT_MASK)

#define CLKCTL1_CLKOUTFCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL1_CLKOUTFCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed
 */
#define CLKCTL1_CLKOUTFCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CLKOUTFCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_CLKOUTFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C01FCLKSEL - I3C0, I3C1 Functional Clock Select */
/*! @{ */

#define CLKCTL1_I3C01FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_I3C01FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - I3C0, I3C1 Clock Source
 *  0b000..Main Clock
 *  0b001..FRO_DIV8 Clock
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_I3C01FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSEL_SEL_SHIFT)) & CLKCTL1_I3C01FCLKSEL_SEL_MASK)
/*! @} */

/*! @name I3C01FCLKSTCSEL - I3C0, I3C1 Functional Slow Time Control Clock Select */
/*! @{ */

#define CLKCTL1_I3C01FCLKSTCSEL_SEL_MASK         (0x7U)
#define CLKCTL1_I3C01FCLKSTCSEL_SEL_SHIFT        (0U)
/*! SEL - I3C0, I3C1 Clock Source
 *  0b000..I3C0 FCLK
 *  0b001..Low Power Oscillator Clock (LPOSC)
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_I3C01FCLKSTCSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSTCSEL_SEL_SHIFT)) & CLKCTL1_I3C01FCLKSTCSEL_SEL_MASK)
/*! @} */

/*! @name I3C01FCLKSTCDIV - I3C0, I3C1 Functional Slow Time Control Clock Divider */
/*! @{ */

#define CLKCTL1_I3C01FCLKSTCDIV_DIV_MASK         (0xFFU)
#define CLKCTL1_I3C01FCLKSTCDIV_DIV_SHIFT        (0U)
/*! DIV - I3C0, I3C1 Clock Divider Value */
#define CLKCTL1_I3C01FCLKSTCDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSTCDIV_DIV_SHIFT)) & CLKCTL1_I3C01FCLKSTCDIV_DIV_MASK)

#define CLKCTL1_I3C01FCLKSTCDIV_RESET_MASK       (0x20000000U)
#define CLKCTL1_I3C01FCLKSTCDIV_RESET_SHIFT      (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_I3C01FCLKSTCDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSTCDIV_RESET_SHIFT)) & CLKCTL1_I3C01FCLKSTCDIV_RESET_MASK)

#define CLKCTL1_I3C01FCLKSTCDIV_HALT_MASK        (0x40000000U)
#define CLKCTL1_I3C01FCLKSTCDIV_HALT_SHIFT       (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_I3C01FCLKSTCDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSTCDIV_HALT_SHIFT)) & CLKCTL1_I3C01FCLKSTCDIV_HALT_MASK)

#define CLKCTL1_I3C01FCLKSTCDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL1_I3C01FCLKSTCDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_I3C01FCLKSTCDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSTCDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C01FCLKSTCDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C01FCLKSDIV - I3C0, I3C1 Functional Slow Clock Divider */
/*! @{ */

#define CLKCTL1_I3C01FCLKSDIV_DIV_MASK           (0xFFU)
#define CLKCTL1_I3C01FCLKSDIV_DIV_SHIFT          (0U)
/*! DIV - I3C0, I3C1 Clock Divider Value */
#define CLKCTL1_I3C01FCLKSDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSDIV_DIV_SHIFT)) & CLKCTL1_I3C01FCLKSDIV_DIV_MASK)

#define CLKCTL1_I3C01FCLKSDIV_RESET_MASK         (0x20000000U)
#define CLKCTL1_I3C01FCLKSDIV_RESET_SHIFT        (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_I3C01FCLKSDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSDIV_RESET_SHIFT)) & CLKCTL1_I3C01FCLKSDIV_RESET_MASK)

#define CLKCTL1_I3C01FCLKSDIV_HALT_MASK          (0x40000000U)
#define CLKCTL1_I3C01FCLKSDIV_HALT_SHIFT         (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_I3C01FCLKSDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSDIV_HALT_SHIFT)) & CLKCTL1_I3C01FCLKSDIV_HALT_MASK)

#define CLKCTL1_I3C01FCLKSDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL1_I3C01FCLKSDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_I3C01FCLKSDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C01FCLKSDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C01FCLKDIV - I3C0, I3C1 Functional Clock Divider */
/*! @{ */

#define CLKCTL1_I3C01FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_I3C01FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - I3C0, I3C1 Clock Divider Value */
#define CLKCTL1_I3C01FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKDIV_DIV_SHIFT)) & CLKCTL1_I3C01FCLKDIV_DIV_MASK)

#define CLKCTL1_I3C01FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_I3C01FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_I3C01FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKDIV_RESET_SHIFT)) & CLKCTL1_I3C01FCLKDIV_RESET_MASK)

#define CLKCTL1_I3C01FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_I3C01FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_I3C01FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKDIV_HALT_SHIFT)) & CLKCTL1_I3C01FCLKDIV_HALT_MASK)

#define CLKCTL1_I3C01FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_I3C01FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
#define CLKCTL1_I3C01FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C01FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C01FCLKSTSTCLKSEL - I3C01 Functional Clock Select */
/*! @{ */

#define CLKCTL1_I3C01FCLKSTSTCLKSEL_SEL_MASK     (0x7U)
#define CLKCTL1_I3C01FCLKSTSTCLKSEL_SEL_SHIFT    (0U)
/*! SEL - I3C0, I3C1 FCLK Test Clock Source
 *  0b000..Low Power Oscillator Clock (LPOSC)
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_I3C01FCLKSTSTCLKSEL_SEL(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C01FCLKSTSTCLKSEL_SEL_SHIFT)) & CLKCTL1_I3C01FCLKSTSTCLKSEL_SEL_MASK)
/*! @} */

/*! @name WDT1FCLKSEL - Watchdog Timer 1 Functional Clock Select */
/*! @{ */

#define CLKCTL1_WDT1FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL1_WDT1FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - WDT1 Functional Clock Source
 *  0b000..Low Power Oscillator Clock (LPOSC)
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_WDT1FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_WDT1FCLKSEL_SEL_SHIFT)) & CLKCTL1_WDT1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name ACMP0FCLKSEL - Analog Comparator 0 Clock Select */
/*! @{ */

#define CLKCTL1_ACMP0FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL1_ACMP0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - ACMP0 Fast Functional Clock Source
 *  0b000..Main Clock
 *  0b001..FRO_DIV4 Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..SYSPLL0 AUX1_PLL_Clock
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL1_ACMP0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKSEL_SEL_SHIFT)) & CLKCTL1_ACMP0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name ACMP0FCLKDIV - Analog comparator 0 FCLK divider */
/*! @{ */

#define CLKCTL1_ACMP0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_ACMP0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Out Clock Divider Value */
#define CLKCTL1_ACMP0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_DIV_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_DIV_MASK)

#define CLKCTL1_ACMP0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_ACMP0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL1_ACMP0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_RESET_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_RESET_MASK)

#define CLKCTL1_ACMP0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_ACMP0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL1_ACMP0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_ACMP0FCLKDIV_HALT_SHIFT)) & CLKCTL1_ACMP0FCLKDIV_HALT_MASK)

#define CLKCTL1_ACMP0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_ACMP0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value has changed.
 */
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

