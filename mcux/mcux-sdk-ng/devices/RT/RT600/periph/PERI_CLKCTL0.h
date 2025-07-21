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
**         CMSIS Peripheral Access Layer for CLKCTL0
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
 * @file PERI_CLKCTL0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL0
 *
 * CMSIS Peripheral Access Layer for CLKCTL0
 */

#if !defined(PERI_CLKCTL0_H_)
#define PERI_CLKCTL0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL0_Peripheral_Access_Layer CLKCTL0 Peripheral Access Layer
 * @{
 */

/** CLKCTL0 - Size of Registers Arrays */
#define CLKCTL0_PFCDIV_COUNT                      2u

/** CLKCTL0 - Register Layout Typedef */
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
       uint8_t RESERVED_3[132];
  __IO uint32_t FFROCTL0;                          /**< FFRO control 0, offset: 0x100 */
  __IO uint32_t FFROCTL1;                          /**< FFRO control 1, offset: 0x104 */
       uint8_t RESERVED_4[88];
  __IO uint32_t SYSOSCCTL0;                        /**< system oscillator control 0, offset: 0x160 */
       uint8_t RESERVED_5[4];
  __IO uint32_t SYSOSCBYPASS;                      /**< system oscillator bypass, offset: 0x168 */
       uint8_t RESERVED_6[36];
  __IO uint32_t LPOSCCTL0;                         /**< low power oscillator control 0, offset: 0x190 */
       uint8_t RESERVED_7[44];
  __IO uint32_t OSC32KHZCTL0;                      /**< 32k oscillator control0, offset: 0x1C0 */
       uint8_t RESERVED_8[60];
  __IO uint32_t SYSPLL0CLKSEL;                     /**< system pll0 clock selection, offset: 0x200 */
  __IO uint32_t SYSPLL0CTL0;                       /**< system pll0 control0, offset: 0x204 */
       uint8_t RESERVED_9[4];
  __IO uint32_t SYSPLL0LOCKTIMEDIV2;               /**< system pll0 lock time, offset: 0x20C */
  __IO uint32_t SYSPLL0NUM;                        /**< system pll0 number, offset: 0x210 */
  __IO uint32_t SYSPLL0DENOM;                      /**< system pll0 denom, offset: 0x214 */
  __IO uint32_t SYSPLL0PFD;                        /**< sys pll0 PFD, offset: 0x218 */
       uint8_t RESERVED_10[36];
  __IO uint32_t MAINPLLCLKDIV;                     /**< main pll clk divider, offset: 0x240 */
  __IO uint32_t DSPPLLCLKDIV;                      /**< dsp pll clk divider, offset: 0x244 */
  __IO uint32_t AUX0PLLCLKDIV;                     /**< aux0 pll clk divider, offset: 0x248 */
  __IO uint32_t AUX1PLLCLKDIV;                     /**< aux1 pll clk divider, offset: 0x24C */
       uint8_t RESERVED_11[432];
  __IO uint32_t SYSCPUAHBCLKDIV;                   /**< system cpu AHB clock divider, offset: 0x400 */
       uint8_t RESERVED_12[44];
  __IO uint32_t MAINCLKSELA;                       /**< main clock selection A, offset: 0x430 */
  __IO uint32_t MAINCLKSELB;                       /**< main clock selection B, offset: 0x434 */
       uint8_t RESERVED_13[200];
  __IO uint32_t PFCDIV[CLKCTL0_PFCDIV_COUNT];      /**< PFC divider register N, array offset: 0x500, array step: 0x4 */
       uint8_t RESERVED_14[280];
  __IO uint32_t FLEXSPIFCLKSEL;                    /**< FlexSPI FCLK selection, offset: 0x620 */
  __IO uint32_t FLEXSPIFCLKDIV;                    /**< FlexSPI FCLK divider, offset: 0x624 */
       uint8_t RESERVED_15[24];
  __IO uint32_t SCTFCLKSEL;                        /**< SCT FCLK selection, offset: 0x640 */
  __IO uint32_t SCTFCLKDIV;                        /**< SCT fclk divider, offset: 0x644 */
       uint8_t RESERVED_16[24];
  __IO uint32_t USBHSFCLKSEL;                      /**< USBHS Fclk selection, offset: 0x660 */
  __IO uint32_t USBHSFCLKDIV;                      /**< USBHS Fclk divider, offset: 0x664 */
       uint8_t RESERVED_17[24];
  __IO uint32_t SDIO0FCLKSEL;                      /**< SDIO0 FCLK selection, offset: 0x680 */
  __IO uint32_t SDIO0FCLKDIV;                      /**< SDIO0 FCLK divider, offset: 0x684 */
       uint8_t RESERVED_18[8];
  __IO uint32_t SDIO1FCLKSEL;                      /**< SDIO1 FCLK selection, offset: 0x690 */
  __IO uint32_t SDIO1FCLKDIV;                      /**< SDIO1 FCLK divider, offset: 0x694 */
       uint8_t RESERVED_19[8];
  __IO uint32_t ESPIFCLKSEL0;                      /**< ESPI clock selection, offset: 0x6A0 */
       uint8_t RESERVED_20[44];
  __IO uint32_t ADC0FCLKSEL0;                      /**< ADC0 fclk selection 0, offset: 0x6D0 */
  __IO uint32_t ADC0FCLKSEL1;                      /**< ADC0 fclk selection 1, offset: 0x6D4 */
  __IO uint32_t ADC0FCLKDIV;                       /**< ADC0 fclk divider, offset: 0x6D8 */
       uint8_t RESERVED_21[36];
  __IO uint32_t UTICKFCLKSEL;                      /**< UTICK fclk selection, offset: 0x700 */
       uint8_t RESERVED_22[28];
  __IO uint32_t WDT0FCLKSEL;                       /**< wdt clock selection, offset: 0x720 */
       uint8_t RESERVED_23[12];
  __IO uint32_t WAKECLK32KHZSEL;                   /**< 32k wake clock selection, offset: 0x730 */
  __IO uint32_t WAKECLK32KHZDIV;                   /**< 32k wake clock divider, offset: 0x734 */
       uint8_t RESERVED_24[40];
  __IO uint32_t SYSTICKFCLKSEL;                    /**< system tick fclk selection, offset: 0x760 */
  __IO uint32_t SYSTICKFCLKDIV;                    /**< system tick fclk divider, offset: 0x764 */
} CLKCTL0_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL0_Register_Masks CLKCTL0 Register Masks
 * @{
 */

/*! @name PSCCTL0 - clock control register 0 */
/*! @{ */

#define CLKCTL0_PSCCTL0_ROM_CTL_128KB_MASK       (0x4U)
#define CLKCTL0_PSCCTL0_ROM_CTL_128KB_SHIFT      (2U)
/*! ROM_CTL_128KB - 128KB ROM control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_ROM_CTL_128KB(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_ROM_CTL_128KB_SHIFT)) & CLKCTL0_PSCCTL0_ROM_CTL_128KB_MASK)

#define CLKCTL0_PSCCTL0_POWERQUAD_CLK_MASK       (0x100U)
#define CLKCTL0_PSCCTL0_POWERQUAD_CLK_SHIFT      (8U)
/*! POWERQUAD_CLK - powerquad clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_POWERQUAD_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_POWERQUAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_POWERQUAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_CASPER_CLK_MASK          (0x200U)
#define CLKCTL0_PSCCTL0_CASPER_CLK_SHIFT         (9U)
/*! CASPER_CLK - CAPSER clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_CASPER_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CASPER_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CASPER_CLK_MASK)

#define CLKCTL0_PSCCTL0_HASHCRYPT_CLK_MASK       (0x400U)
#define CLKCTL0_PSCCTL0_HASHCRYPT_CLK_SHIFT      (10U)
/*! HASHCRYPT_CLK - HASHCRYPT clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_HASHCRYPT_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_HASHCRYPT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_HASHCRYPT_CLK_MASK)

#define CLKCTL0_PSCCTL0_PUF_CLK_MASK             (0x800U)
#define CLKCTL0_PSCCTL0_PUF_CLK_SHIFT            (11U)
/*! PUF_CLK - PUF clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_PUF_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_PUF_CLK_SHIFT)) & CLKCTL0_PSCCTL0_PUF_CLK_MASK)

#define CLKCTL0_PSCCTL0_RNG_CLK_MASK             (0x1000U)
#define CLKCTL0_PSCCTL0_RNG_CLK_SHIFT            (12U)
/*! RNG_CLK - RNG clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_RNG_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_RNG_CLK_SHIFT)) & CLKCTL0_PSCCTL0_RNG_CLK_MASK)

#define CLKCTL0_PSCCTL0_FLEXSPI_OTFAD_CLK_MASK   (0x10000U)
#define CLKCTL0_PSCCTL0_FLEXSPI_OTFAD_CLK_SHIFT  (16U)
/*! FLEXSPI_OTFAD_CLK - FLEXSPI clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_FLEXSPI_OTFAD_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_FLEXSPI_OTFAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_FLEXSPI_OTFAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_OTP_CLK_MASK             (0x20000U)
#define CLKCTL0_PSCCTL0_OTP_CLK_SHIFT            (17U)
/*! OTP_CLK - OTP clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_OTP_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_OTP_CLK_SHIFT)) & CLKCTL0_PSCCTL0_OTP_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_PHY_CLK_MASK       (0x100000U)
#define CLKCTL0_PSCCTL0_USBHS_PHY_CLK_SHIFT      (20U)
/*! USBHS_PHY_CLK - USB PHY clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_USBHS_PHY_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_PHY_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_PHY_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_MASK    (0x200000U)
#define CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_SHIFT   (21U)
/*! USBHS_DEVICE_CLK - USB DEVICE clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_HOST_CLK_MASK      (0x400000U)
#define CLKCTL0_PSCCTL0_USBHS_HOST_CLK_SHIFT     (22U)
/*! USBHS_HOST_CLK - USB HOST clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_USBHS_HOST_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_HOST_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_HOST_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_MASK      (0x800000U)
#define CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_SHIFT     (23U)
/*! USBHS_SRAM_CLK - USBHS RAM clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_USBHS_SRAM_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_MASK)

#define CLKCTL0_PSCCTL0_SCT_CLK_MASK             (0x1000000U)
#define CLKCTL0_PSCCTL0_SCT_CLK_SHIFT            (24U)
/*! SCT_CLK - SCT clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL0_SCT_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SCT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SCT_CLK_MASK)
/*! @} */

/*! @name PSCCTL1 - clock control register 1 */
/*! @{ */

#define CLKCTL0_PSCCTL1_SDIO0_CLK_MASK           (0x4U)
#define CLKCTL0_PSCCTL1_SDIO0_CLK_SHIFT          (2U)
/*! SDIO0_CLK - SDIO0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL1_SDIO0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SDIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SDIO0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SDIO1_CLK_MASK           (0x8U)
#define CLKCTL0_PSCCTL1_SDIO1_CLK_SHIFT          (3U)
/*! SDIO1_CLK - SDIO1 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL1_SDIO1_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SDIO1_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SDIO1_CLK_MASK)

#define CLKCTL0_PSCCTL1_ACMP0_CLK_MASK           (0x8000U)
#define CLKCTL0_PSCCTL1_ACMP0_CLK_SHIFT          (15U)
/*! ACMP0_CLK - Analog comparator clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL1_ACMP0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_ACMP0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_ACMP0_CLK_MASK)

#define CLKCTL0_PSCCTL1_ADC0_CLK_MASK            (0x10000U)
#define CLKCTL0_PSCCTL1_ADC0_CLK_SHIFT           (16U)
/*! ADC0_CLK - ADC clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL1_ADC0_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_ADC0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_ADC0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SHSGPIO0_CLK_MASK        (0x1000000U)
#define CLKCTL0_PSCCTL1_SHSGPIO0_CLK_SHIFT       (24U)
/*! SHSGPIO0_CLK - SHSGPIO0 clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL1_SHSGPIO0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SHSGPIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SHSGPIO0_CLK_MASK)
/*! @} */

/*! @name PSCCTL2 - clock control register 2 */
/*! @{ */

#define CLKCTL0_PSCCTL2_UTICK0_CLK_MASK          (0x1U)
#define CLKCTL0_PSCCTL2_UTICK0_CLK_SHIFT         (0U)
/*! UTICK0_CLK - utick clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL2_UTICK0_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_UTICK0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_UTICK0_CLK_MASK)

#define CLKCTL0_PSCCTL2_WWDT0_CLK_MASK           (0x2U)
#define CLKCTL0_PSCCTL2_WWDT0_CLK_SHIFT          (1U)
/*! WWDT0_CLK - wdt clock control
 *  0b0..Disable Clock
 *  0b1..Enable Clock
 */
#define CLKCTL0_PSCCTL2_WWDT0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_WWDT0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_WWDT0_CLK_MASK)
/*! @} */

/*! @name PSCCTL0_SET - clock set register 0 */
/*! @{ */

#define CLKCTL0_PSCCTL0_SET_ROM_CTL_128KB_CLK_MASK (0x4U)
#define CLKCTL0_PSCCTL0_SET_ROM_CTL_128KB_CLK_SHIFT (2U)
/*! ROM_CTL_128KB_CLK - 128KB ROM controller clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_ROM_CTL_128KB_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_ROM_CTL_128KB_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_ROM_CTL_128KB_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_MASK   (0x100U)
#define CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_SHIFT  (8U)
/*! POWERQUAD_CLK - powerquad clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_CASPER_CLK_MASK      (0x200U)
#define CLKCTL0_PSCCTL0_SET_CASPER_CLK_SHIFT     (9U)
/*! CASPER_CLK - CAPSER clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_CASPER_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_CASPER_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_CASPER_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_MASK   (0x400U)
#define CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_SHIFT  (10U)
/*! HASHCRYPT_CLK - HASHCRYPT clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_PUF_CLK_MASK         (0x800U)
#define CLKCTL0_PSCCTL0_SET_PUF_CLK_SHIFT        (11U)
/*! PUF_CLK - PUF clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_PUF_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_PUF_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_PUF_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_RNG_CLK_MASK         (0x1000U)
#define CLKCTL0_PSCCTL0_SET_RNG_CLK_SHIFT        (12U)
/*! RNG_CLK - RNG clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_RNG_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_RNG_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_RNG_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_FLEXSPI_OTFAD_CLK_MASK (0x10000U)
#define CLKCTL0_PSCCTL0_SET_FLEXSPI_OTFAD_CLK_SHIFT (16U)
/*! FLEXSPI_OTFAD_CLK - FLEXSPI clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_FLEXSPI_OTFAD_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_FLEXSPI_OTFAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_FLEXSPI_OTFAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_OTP_CLK_MASK         (0x20000U)
#define CLKCTL0_PSCCTL0_SET_OTP_CLK_SHIFT        (17U)
/*! OTP_CLK - OTP clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_OTP_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_OTP_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_OTP_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_MASK   (0x100000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_SHIFT  (20U)
/*! USBHS_PHY_CLK - USB PHY clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_MASK (0x200000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_SHIFT (21U)
/*! USBHS_DEVICE_CLK - USB DEVICE clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_MASK  (0x400000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_SHIFT (22U)
/*! USBHS_HOST_CLK - USB HOST clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_MASK  (0x800000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_SHIFT (23U)
/*! USBHS_SRAM_CLK - USBHS RAM clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_SCT_CLK_MASK         (0x1000000U)
#define CLKCTL0_PSCCTL0_SET_SCT_CLK_SHIFT        (24U)
/*! SCT_CLK - SCT clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_SET_SCT_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_SCT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_SCT_CLK_MASK)
/*! @} */

/*! @name PSCCTL1_SET - clock set register 1 */
/*! @{ */

#define CLKCTL0_PSCCTL1_SET_SDIO0_CLK_MASK       (0x4U)
#define CLKCTL0_PSCCTL1_SET_SDIO0_CLK_SHIFT      (2U)
/*! SDIO0_CLK - SDIO0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_SET_SDIO0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SDIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_SDIO0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_SDIO1_CLK_MASK       (0x8U)
#define CLKCTL0_PSCCTL1_SET_SDIO1_CLK_SHIFT      (3U)
/*! SDIO1_CLK - SDIO1 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_SET_SDIO1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SDIO1_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_SDIO1_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_ACMP0_CLK_MASK       (0x8000U)
#define CLKCTL0_PSCCTL1_SET_ACMP0_CLK_SHIFT      (15U)
/*! ACMP0_CLK - Analog comparator clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_SET_ACMP0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_ACMP0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_ACMP0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_ADC0_CLK_MASK        (0x10000U)
#define CLKCTL0_PSCCTL1_SET_ADC0_CLK_SHIFT       (16U)
/*! ADC0_CLK - ADC clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_SET_ADC0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_ADC0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_ADC0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_MASK    (0x1000000U)
#define CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_SHIFT   (24U)
/*! SHSGPIO0_CLK - SHSGPIO0 clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_MASK)
/*! @} */

/*! @name PSCCTL2_SET - clock set register 2 */
/*! @{ */

#define CLKCTL0_PSCCTL2_SET_UTICK0_CLK_MASK      (0x1U)
#define CLKCTL0_PSCCTL2_SET_UTICK0_CLK_SHIFT     (0U)
/*! UTICK0_CLK - utick clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL0_PSCCTL2_SET_UTICK0_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_UTICK0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_SET_UTICK0_CLK_MASK)

#define CLKCTL0_PSCCTL2_SET_WWDT0_CLK_MASK       (0x2U)
#define CLKCTL0_PSCCTL2_SET_WWDT0_CLK_SHIFT      (1U)
/*! WWDT0_CLK - wdt clock set
 *  0b0..No Effect
 *  0b1..Sets the PSCCTL2 Bit
 */
#define CLKCTL0_PSCCTL2_SET_WWDT0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_WWDT0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_SET_WWDT0_CLK_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - clock clear register 0 */
/*! @{ */

#define CLKCTL0_PSCCTL0_CLR_ROM_CTL_128KB_CLK_MASK (0x4U)
#define CLKCTL0_PSCCTL0_CLR_ROM_CTL_128KB_CLK_SHIFT (2U)
/*! ROM_CTL_128KB_CLK - ROM controller clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_ROM_CTL_128KB_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_ROM_CTL_128KB_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_ROM_CTL_128KB_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_MASK   (0x100U)
#define CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_SHIFT  (8U)
/*! POWERQUAD_CLK - powerquad clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_CASPER_CLK_MASK      (0x200U)
#define CLKCTL0_PSCCTL0_CLR_CASPER_CLK_SHIFT     (9U)
/*! CASPER_CLK - CAPSER clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_CASPER_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_CASPER_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_CASPER_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_MASK   (0x400U)
#define CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_SHIFT  (10U)
/*! HASHCRYPT_CLK - HASHCRYPT clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_PUF_CLK_MASK         (0x800U)
#define CLKCTL0_PSCCTL0_CLR_PUF_CLK_SHIFT        (11U)
/*! PUF_CLK - PUF clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_PUF_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_PUF_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_PUF_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_RNG_CLK_MASK         (0x1000U)
#define CLKCTL0_PSCCTL0_CLR_RNG_CLK_SHIFT        (12U)
/*! RNG_CLK - RNG clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_RNG_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_RNG_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_RNG_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_FLEXSPI_OTFAD_CLK_MASK (0x10000U)
#define CLKCTL0_PSCCTL0_CLR_FLEXSPI_OTFAD_CLK_SHIFT (16U)
/*! FLEXSPI_OTFAD_CLK - FLEXSPI clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_FLEXSPI_OTFAD_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_FLEXSPI_OTFAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_FLEXSPI_OTFAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_OTP_CLK_MASK         (0x20000U)
#define CLKCTL0_PSCCTL0_CLR_OTP_CLK_SHIFT        (17U)
/*! OTP_CLK - OTP clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_OTP_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_OTP_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_OTP_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_MASK   (0x100000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_SHIFT  (20U)
/*! USBHS_PHY_CLK - USB PHY clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_MASK (0x200000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_SHIFT (21U)
/*! USBHS_DEVICE_CLK - USB DEVICE clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_MASK  (0x400000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_SHIFT (22U)
/*! USBHS_HOST_CLK - USB HOST clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_MASK  (0x800000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_SHIFT (23U)
/*! USBHS_SRAM_CLK - USBHS RAM clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_SCT_CLK_MASK         (0x1000000U)
#define CLKCTL0_PSCCTL0_CLR_SCT_CLK_SHIFT        (24U)
/*! SCT_CLK - SCT clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL0 Bit
 */
#define CLKCTL0_PSCCTL0_CLR_SCT_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_SCT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_SCT_CLK_MASK)
/*! @} */

/*! @name PSCCTL1_CLR - clock clear register 1 */
/*! @{ */

#define CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_MASK       (0x4U)
#define CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_SHIFT      (2U)
/*! SDIO0_CLK - SDIO0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_CLR_SDIO0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_MASK       (0x8U)
#define CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_SHIFT      (3U)
/*! SDIO1_CLK - SDIO1 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_CLR_SDIO1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_MASK       (0x8000U)
#define CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_SHIFT      (15U)
/*! ACMP0_CLK - Analog comparator clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_CLR_ACMP0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_ADC0_CLK_MASK        (0x10000U)
#define CLKCTL0_PSCCTL1_CLR_ADC0_CLK_SHIFT       (16U)
/*! ADC0_CLK - ADC clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_CLR_ADC0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_ADC0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_ADC0_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_MASK    (0x1000000U)
#define CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_SHIFT   (24U)
/*! SHSGPIO0_CLK - SHSGPIO0 clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL1 Bit
 */
#define CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_MASK)
/*! @} */

/*! @name PSCCTL2_CLR - clock clear register 2 */
/*! @{ */

#define CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_MASK      (0x1U)
#define CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_SHIFT     (0U)
/*! UTICK0_CLK - utick clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL0_PSCCTL2_CLR_UTICK0_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_MASK)

#define CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_MASK       (0x2U)
#define CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_SHIFT      (1U)
/*! WWDT0_CLK - wdt clock clear
 *  0b0..No Effect
 *  0b1..Clears the PSCCTL2 Bit
 */
#define CLKCTL0_PSCCTL2_CLR_WWDT0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_MASK)
/*! @} */

/*! @name FFROCTL0 - FFRO control 0 */
/*! @{ */

#define CLKCTL0_FFROCTL0_TRIM_TEMPCO_MASK        (0x1FU)
#define CLKCTL0_FFROCTL0_TRIM_TEMPCO_SHIFT       (0U)
/*! TRIM_TEMPCO - Trims temperature compensation of FFRO. */
#define CLKCTL0_FFROCTL0_TRIM_TEMPCO(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FFROCTL0_TRIM_TEMPCO_SHIFT)) & CLKCTL0_FFROCTL0_TRIM_TEMPCO_MASK)

#define CLKCTL0_FFROCTL0_TRIM_COARSE_MASK        (0x7E0U)
#define CLKCTL0_FFROCTL0_TRIM_COARSE_SHIFT       (5U)
/*! TRIM_COARSE - Trims coarse frequency of FFRO. */
#define CLKCTL0_FFROCTL0_TRIM_COARSE(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FFROCTL0_TRIM_COARSE_SHIFT)) & CLKCTL0_FFROCTL0_TRIM_COARSE_MASK)

#define CLKCTL0_FFROCTL0_TRIM_FINE_MASK          (0x3F800U)
#define CLKCTL0_FFROCTL0_TRIM_FINE_SHIFT         (11U)
/*! TRIM_FINE - Trims fine frequency of FFRO. */
#define CLKCTL0_FFROCTL0_TRIM_FINE(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FFROCTL0_TRIM_FINE_SHIFT)) & CLKCTL0_FFROCTL0_TRIM_FINE_MASK)

#define CLKCTL0_FFROCTL0_TRIM_RANGE_MASK         (0xC0000U)
#define CLKCTL0_FFROCTL0_TRIM_RANGE_SHIFT        (18U)
/*! TRIM_RANGE - Trims frequency range of FFRO.
 *  0b00..48MHz.
 *  0b01..RESERVED.
 *  0b10..RESERVED.
 *  0b11..60MHz.
 */
#define CLKCTL0_FFROCTL0_TRIM_RANGE(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FFROCTL0_TRIM_RANGE_SHIFT)) & CLKCTL0_FFROCTL0_TRIM_RANGE_MASK)
/*! @} */

/*! @name FFROCTL1 - FFRO control 1 */
/*! @{ */

#define CLKCTL0_FFROCTL1_UPDATE_MASK             (0x1U)
#define CLKCTL0_FFROCTL1_UPDATE_SHIFT            (0U)
/*! UPDATE - Update Safe Mode Control. In order to change any of the TRIM values, the user first
 *    needs to set the update safe mode bit, then proceed to change the respective TRIM values needed,
 *    followed by clearing the update safe mode bit.
 *  0b0..Normal Mode.
 *  0b1..Update Safe Mode.
 */
#define CLKCTL0_FFROCTL1_UPDATE(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FFROCTL1_UPDATE_SHIFT)) & CLKCTL0_FFROCTL1_UPDATE_MASK)
/*! @} */

/*! @name SYSOSCCTL0 - system oscillator control 0 */
/*! @{ */

#define CLKCTL0_SYSOSCCTL0_LP_ENABLE_MASK        (0x1U)
#define CLKCTL0_SYSOSCCTL0_LP_ENABLE_SHIFT       (0U)
/*! LP_ENABLE - Enable signal for low power mode. . .
 *  0b0..High Gain Mode(HP).
 *  0b1..Low Power mode (LP).
 */
#define CLKCTL0_SYSOSCCTL0_LP_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSOSCCTL0_LP_ENABLE_SHIFT)) & CLKCTL0_SYSOSCCTL0_LP_ENABLE_MASK)

#define CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_MASK    (0x2U)
#define CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_SHIFT   (1U)
/*! BYPASS_ENABLE - Enable signal for external bypass clock. . .
 *  0b0..Normal Mode.
 *  0b1..Bypass Mode.
 */
#define CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_SHIFT)) & CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_MASK)
/*! @} */

/*! @name SYSOSCBYPASS - system oscillator bypass */
/*! @{ */

#define CLKCTL0_SYSOSCBYPASS_SEL_MASK            (0x7U)
#define CLKCTL0_SYSOSCBYPASS_SEL_SHIFT           (0U)
/*! SEL - Extenal Clock Source Selection.
 *  0b000..External XTAL Clock.
 *  0b001..Clock IN Clock.
 *  0b010..Reserved.
 *  0b011..Reserved.
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..NONE.this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_SYSOSCBYPASS_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSOSCBYPASS_SEL_SHIFT)) & CLKCTL0_SYSOSCBYPASS_SEL_MASK)
/*! @} */

/*! @name LPOSCCTL0 - low power oscillator control 0 */
/*! @{ */

#define CLKCTL0_LPOSCCTL0_CLKRDY_MASK            (0x80000000U)
#define CLKCTL0_LPOSCCTL0_CLKRDY_SHIFT           (31U)
/*! CLKRDY - Clock ready flag status. LPOSC clock ready takes 64uS. */
#define CLKCTL0_LPOSCCTL0_CLKRDY(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_LPOSCCTL0_CLKRDY_SHIFT)) & CLKCTL0_LPOSCCTL0_CLKRDY_MASK)
/*! @} */

/*! @name OSC32KHZCTL0 - 32k oscillator control0 */
/*! @{ */

#define CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK       (0x1U)
#define CLKCTL0_OSC32KHZCTL0_ENA32KHZ_SHIFT      (0U)
/*! ENA32KHZ - 32KHz Enable.
 *  0b0..disable
 *  0b1..enable
 */
#define CLKCTL0_OSC32KHZCTL0_ENA32KHZ(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_OSC32KHZCTL0_ENA32KHZ_SHIFT)) & CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK)
/*! @} */

/*! @name SYSPLL0CLKSEL - system pll0 clock selection */
/*! @{ */

#define CLKCTL0_SYSPLL0CLKSEL_SEL_MASK           (0x7U)
#define CLKCTL0_SYSPLL0CLKSEL_SEL_SHIFT          (0U)
/*! SEL - System PLL Clock Source Selection. . .
 *  0b000..SFRO Clock.
 *  0b001..SYSXTALIN Clock.
 *  0b010..FFRO Clock Divided by 2.
 *  0b011..Reserved.
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_SYSPLL0CLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CLKSEL_SEL_SHIFT)) & CLKCTL0_SYSPLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSPLL0CTL0 - system pll0 control0 */
/*! @{ */

#define CLKCTL0_SYSPLL0CTL0_BYPASS_MASK          (0x1U)
#define CLKCTL0_SYSPLL0CTL0_BYPASS_SHIFT         (0U)
/*! BYPASS - SYSPLL0 BYPASS Mode
 *  0b0..PFD output is PFD programmed clock.
 *  0b1..PFD output is PLL Input clock. (Bypass)
 */
#define CLKCTL0_SYSPLL0CTL0_BYPASS(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_BYPASS_SHIFT)) & CLKCTL0_SYSPLL0CTL0_BYPASS_MASK)

#define CLKCTL0_SYSPLL0CTL0_RESET_MASK           (0x2U)
#define CLKCTL0_SYSPLL0CTL0_RESET_SHIFT          (1U)
/*! RESET - SYSPLL0 Reset:
 *  0b0..SYSPLL0 reset is removed.
 *  0b1..SYSPLL0 is placed into reset.
 */
#define CLKCTL0_SYSPLL0CTL0_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_RESET_SHIFT)) & CLKCTL0_SYSPLL0CTL0_RESET_MASK)

#define CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_MASK (0x2000U)
#define CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_SHIFT (13U)
/*! HOLDRINGOFF_ENA - Hold Ring Off Control: This bit is used to avoid multi wave within the VCO.
 *  0b0..disbale
 *  0b1..enable
 */
#define CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_SHIFT)) & CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_MASK)

#define CLKCTL0_SYSPLL0CTL0_MULT_MASK            (0xFF0000U)
#define CLKCTL0_SYSPLL0CTL0_MULT_SHIFT           (16U)
/*! MULT - Multiplication Factor for FSYSPLL0_OUTPUT:
 *  0b00010000..Div 16
 *  0b00010001..Div 17
 *  0b00010100..Div 20
 *  0b00010110..Div 22
 *  0b00011011..Div 27
 *  0b00100001..Div 33
 */
#define CLKCTL0_SYSPLL0CTL0_MULT(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_MULT_SHIFT)) & CLKCTL0_SYSPLL0CTL0_MULT_MASK)
/*! @} */

/*! @name SYSPLL0LOCKTIMEDIV2 - system pll0 lock time */
/*! @{ */

#define CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - SYSPLL0 Lock Time Divide by 2: Programmed lock time is in uS (micro-seconds) and
 *    is programmed as half the actual lock time value.
 */
#define CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name SYSPLL0NUM - system pll0 number */
/*! @{ */

#define CLKCTL0_SYSPLL0NUM_NUM_MASK              (0x3FFFFFFFU)
#define CLKCTL0_SYSPLL0NUM_NUM_SHIFT             (0U)
/*! NUM - This field contains the numerator of the SYSPLL0 fractional loop divider. */
#define CLKCTL0_SYSPLL0NUM_NUM(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0NUM_NUM_SHIFT)) & CLKCTL0_SYSPLL0NUM_NUM_MASK)
/*! @} */

/*! @name SYSPLL0DENOM - system pll0 denom */
/*! @{ */

#define CLKCTL0_SYSPLL0DENOM_DENOM_MASK          (0x3FFFFFFFU)
#define CLKCTL0_SYSPLL0DENOM_DENOM_SHIFT         (0U)
/*! DENOM - This field contains the denominator of the SYSPLL0 fractional loop divider. */
#define CLKCTL0_SYSPLL0DENOM_DENOM(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0DENOM_DENOM_SHIFT)) & CLKCTL0_SYSPLL0DENOM_DENOM_MASK)
/*! @} */

/*! @name SYSPLL0PFD - sys pll0 PFD */
/*! @{ */

#define CLKCTL0_SYSPLL0PFD_PFD0_MASK             (0x3FU)
#define CLKCTL0_SYSPLL0PFD_PFD0_SHIFT            (0U)
/*! PFD0 - PLL Fractional Divider 0: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL0_SYSPLL0PFD_PFD0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD0_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD0_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_MASK      (0x40U)
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_SHIFT     (6U)
/*! PFD0_CLKRDY - PFD0 Clock Ready Status Flag: Read as '1' clock ready. Cleared by writing a '1'. */
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_MASK     (0x80U)
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_SHIFT    (7U)
/*! PFD0_CLKGATE - PFD0 Clock Gate: 0: PFD0 clock is not gated. 1: PFD0 clock is gated
 *  0b0..PFD0 clock is not gated.
 *  0b1..PFD0 clock is gated.
 */
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD1_MASK             (0x3F00U)
#define CLKCTL0_SYSPLL0PFD_PFD1_SHIFT            (8U)
/*! PFD1 - PLL Fractional Divider 1: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL0_SYSPLL0PFD_PFD1(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD1_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD1_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_MASK      (0x4000U)
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_SHIFT     (14U)
/*! PFD1_CLKRDY - PFD1 Clock Ready Status Flag: Read as '1' clock ready. Cleared by writing a '1'. */
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_MASK     (0x8000U)
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_SHIFT    (15U)
/*! PFD1_CLKGATE - PFD1 Clock Gate: 0: PFD1 clock is not gated. 1: PFD1 clock is gated.
 *  0b0..PFD1 clock is not gated.
 *  0b1..PFD1 clock is gated.
 */
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD2_MASK             (0x3F0000U)
#define CLKCTL0_SYSPLL0PFD_PFD2_SHIFT            (16U)
/*! PFD2 - PLL Fractional Divider 2: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL0_SYSPLL0PFD_PFD2(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD2_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD2_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_MASK      (0x400000U)
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_SHIFT     (22U)
/*! PFD2_CLKRDY - PFD2 Clock Ready Status Flag: Read as '1' clock ready. Cleared by writing a '1'. */
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_MASK     (0x800000U)
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_SHIFT    (23U)
/*! PFD2_CLKGATE - PFD2 Clock Gate: 0: PFD2 clock is not gated. 1: PFD2 clock is gated.
 *  0b0..PFD2 clock is not gated.
 *  0b1..PFD2 clock is gated.
 */
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD3_MASK             (0x3F000000U)
#define CLKCTL0_SYSPLL0PFD_PFD3_SHIFT            (24U)
/*! PFD3 - PLL Fractional Divider 3: Controls the fractional divider value. Valid PFD values are decimal 12-35. */
#define CLKCTL0_SYSPLL0PFD_PFD3(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD3_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD3_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_MASK      (0x40000000U)
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_SHIFT     (30U)
/*! PFD3_CLKRDY - PFD3 Clock Ready Status Flag: Read as '1' clock ready. Cleared by writing a '1'. */
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_MASK     (0x80000000U)
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_SHIFT    (31U)
/*! PFD3_CLKGATE - PFD3 Clock Gate: 0: PFD3 clock is not gated. 1: PFD3 clock is gated.
 *  0b0..PFD3 clock is not gated.
 *  0b1..PFD3 clock is gated.
 */
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name MAINPLLCLKDIV - main pll clk divider */
/*! @{ */

#define CLKCTL0_MAINPLLCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_MAINPLLCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_MAINPLLCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_DIV_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_DIV_MASK)

#define CLKCTL0_MAINPLLCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_MAINPLLCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_MAINPLLCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_RESET_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_RESET_MASK)

#define CLKCTL0_MAINPLLCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_MAINPLLCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_MAINPLLCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_HALT_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_HALT_MASK)

#define CLKCTL0_MAINPLLCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_MAINPLLCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_MAINPLLCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPPLLCLKDIV - dsp pll clk divider */
/*! @{ */

#define CLKCTL0_DSPPLLCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_DSPPLLCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_DSPPLLCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_DIV_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_DIV_MASK)

#define CLKCTL0_DSPPLLCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_DSPPLLCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_DSPPLLCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_RESET_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_RESET_MASK)

#define CLKCTL0_DSPPLLCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_DSPPLLCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_DSPPLLCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_HALT_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_HALT_MASK)

#define CLKCTL0_DSPPLLCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_DSPPLLCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_DSPPLLCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name AUX0PLLCLKDIV - aux0 pll clk divider */
/*! @{ */

#define CLKCTL0_AUX0PLLCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_AUX0PLLCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_AUX0PLLCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_DIV_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_DIV_MASK)

#define CLKCTL0_AUX0PLLCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_AUX0PLLCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_AUX0PLLCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_RESET_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_RESET_MASK)

#define CLKCTL0_AUX0PLLCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_AUX0PLLCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_AUX0PLLCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_HALT_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_HALT_MASK)

#define CLKCTL0_AUX0PLLCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_AUX0PLLCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_AUX0PLLCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name AUX1PLLCLKDIV - aux1 pll clk divider */
/*! @{ */

#define CLKCTL0_AUX1PLLCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_AUX1PLLCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_AUX1PLLCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_DIV_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_DIV_MASK)

#define CLKCTL0_AUX1PLLCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_AUX1PLLCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_AUX1PLLCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_RESET_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_RESET_MASK)

#define CLKCTL0_AUX1PLLCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_AUX1PLLCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_AUX1PLLCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_HALT_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_HALT_MASK)

#define CLKCTL0_AUX1PLLCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_AUX1PLLCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_AUX1PLLCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SYSCPUAHBCLKDIV - system cpu AHB clock divider */
/*! @{ */

#define CLKCTL0_SYSCPUAHBCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL0_SYSCPUAHBCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_SYSCPUAHBCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSCPUAHBCLKDIV_DIV_SHIFT)) & CLKCTL0_SYSCPUAHBCLKDIV_DIV_MASK)

#define CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MAINCLKSELA - main clock selection A */
/*! @{ */

#define CLKCTL0_MAINCLKSELA_SEL_MASK             (0x3U)
#define CLKCTL0_MAINCLKSELA_SEL_SHIFT            (0U)
/*! SEL - Control Main 1st Stage Control Clock Source. . .
 *  0b00..FFRO Clock Divided by 4.
 *  0b01..SYSXTALIN Clock.
 *  0b10..Low Power Oscillator Clock (LPOSC).
 *  0b11..FFRO Clock.
 */
#define CLKCTL0_MAINCLKSELA_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKSELA_SEL_SHIFT)) & CLKCTL0_MAINCLKSELA_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELB - main clock selection B */
/*! @{ */

#define CLKCTL0_MAINCLKSELB_SEL_MASK             (0x3U)
#define CLKCTL0_MAINCLKSELB_SEL_SHIFT            (0U)
/*! SEL - Main Clock Source Selection. . .
 *  0b00..MAINCLKSELA 1st Stage Clock.
 *  0b01..SFRO Clock.
 *  0b10..Main System PLL Clock.
 *  0b11..RTC 32KHz Clock.
 */
#define CLKCTL0_MAINCLKSELB_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKSELB_SEL_SHIFT)) & CLKCTL0_MAINCLKSELB_SEL_MASK)
/*! @} */

/*! @name PFCDIV - PFC divider register N */
/*! @{ */

#define CLKCTL0_PFCDIV_DIV_MASK                  (0xFFU)
#define CLKCTL0_PFCDIV_DIV_SHIFT                 (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_PFCDIV_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_DIV_SHIFT)) & CLKCTL0_PFCDIV_DIV_MASK)

#define CLKCTL0_PFCDIV_RESET_MASK                (0x20000000U)
#define CLKCTL0_PFCDIV_RESET_SHIFT               (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_PFCDIV_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_RESET_SHIFT)) & CLKCTL0_PFCDIV_RESET_MASK)

#define CLKCTL0_PFCDIV_HALT_MASK                 (0x40000000U)
#define CLKCTL0_PFCDIV_HALT_SHIFT                (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL0_PFCDIV_HALT(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_HALT_SHIFT)) & CLKCTL0_PFCDIV_HALT_MASK)

#define CLKCTL0_PFCDIV_REQFLAG_MASK              (0x80000000U)
#define CLKCTL0_PFCDIV_REQFLAG_SHIFT             (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_PFCDIV_REQFLAG(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_REQFLAG_SHIFT)) & CLKCTL0_PFCDIV_REQFLAG_MASK)
/*! @} */

/*! @name FLEXSPIFCLKSEL - FlexSPI FCLK selection */
/*! @{ */

#define CLKCTL0_FLEXSPIFCLKSEL_SEL_MASK          (0x7U)
#define CLKCTL0_FLEXSPIFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - FlexSPI Functional Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..Main System PLL Clock.
 *  0b010..SYSPLL0 AUX0_PLL_Clock.
 *  0b011..FFRO Clock.
 *  0b100..SYSPLL0 AUX1_PLL_Clock.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_FLEXSPIFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPIFCLKSEL_SEL_SHIFT)) & CLKCTL0_FLEXSPIFCLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXSPIFCLKDIV - FlexSPI FCLK divider */
/*! @{ */

#define CLKCTL0_FLEXSPIFCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL0_FLEXSPIFCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_FLEXSPIFCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPIFCLKDIV_DIV_SHIFT)) & CLKCTL0_FLEXSPIFCLKDIV_DIV_MASK)

#define CLKCTL0_FLEXSPIFCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL0_FLEXSPIFCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_FLEXSPIFCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPIFCLKDIV_RESET_SHIFT)) & CLKCTL0_FLEXSPIFCLKDIV_RESET_MASK)

#define CLKCTL0_FLEXSPIFCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL0_FLEXSPIFCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_FLEXSPIFCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPIFCLKDIV_HALT_SHIFT)) & CLKCTL0_FLEXSPIFCLKDIV_HALT_MASK)

#define CLKCTL0_FLEXSPIFCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL0_FLEXSPIFCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_FLEXSPIFCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPIFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_FLEXSPIFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SCTFCLKSEL - SCT FCLK selection */
/*! @{ */

#define CLKCTL0_SCTFCLKSEL_SEL_MASK              (0x7U)
#define CLKCTL0_SCTFCLKSEL_SEL_SHIFT             (0U)
/*! SEL - SCT Functional Clock Source Selection. . .
 *  0b000..Main Clock.
 *  0b001..Main System PLL Clock.
 *  0b010..SYSPLL0 AUX0_PLL_Clock.
 *  0b011..FFRO Clock.
 *  0b100..SYSPLL0 AUX1_PLL_Clock.
 *  0b101..AUDIO PLL Clock
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_SCTFCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKSEL_SEL_SHIFT)) & CLKCTL0_SCTFCLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTFCLKDIV - SCT fclk divider */
/*! @{ */

#define CLKCTL0_SCTFCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL0_SCTFCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_SCTFCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_DIV_SHIFT)) & CLKCTL0_SCTFCLKDIV_DIV_MASK)

#define CLKCTL0_SCTFCLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL0_SCTFCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_SCTFCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_RESET_SHIFT)) & CLKCTL0_SCTFCLKDIV_RESET_MASK)

#define CLKCTL0_SCTFCLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL0_SCTFCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL0_SCTFCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_HALT_SHIFT)) & CLKCTL0_SCTFCLKDIV_HALT_MASK)

#define CLKCTL0_SCTFCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL0_SCTFCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_SCTFCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SCTFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name USBHSFCLKSEL - USBHS Fclk selection */
/*! @{ */

#define CLKCTL0_USBHSFCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_USBHSFCLKSEL_SEL_SHIFT           (0U)
/*! SEL - USB HS Functional Clock Source Selection. . .
 *  0b000..XTALIN Clock.
 *  0b001..Main Clock.
 *  0b010..Reserved.
 *  0b011..Reserved.
 *  0b100..reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_USBHSFCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKSEL_SEL_SHIFT)) & CLKCTL0_USBHSFCLKSEL_SEL_MASK)
/*! @} */

/*! @name USBHSFCLKDIV - USBHS Fclk divider */
/*! @{ */

#define CLKCTL0_USBHSFCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_USBHSFCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_USBHSFCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_DIV_SHIFT)) & CLKCTL0_USBHSFCLKDIV_DIV_MASK)

#define CLKCTL0_USBHSFCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_USBHSFCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_USBHSFCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_RESET_SHIFT)) & CLKCTL0_USBHSFCLKDIV_RESET_MASK)

#define CLKCTL0_USBHSFCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_USBHSFCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL0_USBHSFCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_HALT_SHIFT)) & CLKCTL0_USBHSFCLKDIV_HALT_MASK)

#define CLKCTL0_USBHSFCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_USBHSFCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_USBHSFCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_USBHSFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDIO0FCLKSEL - SDIO0 FCLK selection */
/*! @{ */

#define CLKCTL0_SDIO0FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_SDIO0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - SDIO0 Functional Clock Source Selection. .
 *  0b000..Main Clock.
 *  0b001..Main System PLL Clock.
 *  0b010..SYSPLL0 AUX0_PLL_Clock.
 *  0b011..FFRO Clock.
 *  0b100..SYSPLL0 AUX1_PLL_Clock.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_SDIO0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKSEL_SEL_SHIFT)) & CLKCTL0_SDIO0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name SDIO0FCLKDIV - SDIO0 FCLK divider */
/*! @{ */

#define CLKCTL0_SDIO0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_SDIO0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_SDIO0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_DIV_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_DIV_MASK)

#define CLKCTL0_SDIO0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_SDIO0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_SDIO0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_RESET_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_RESET_MASK)

#define CLKCTL0_SDIO0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_SDIO0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define CLKCTL0_SDIO0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_HALT_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_HALT_MASK)

#define CLKCTL0_SDIO0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_SDIO0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_SDIO0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDIO1FCLKSEL - SDIO1 FCLK selection */
/*! @{ */

#define CLKCTL0_SDIO1FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_SDIO1FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - SDIO1 Functional Clock Source Selection. .
 *  0b000..Main Clock.
 *  0b001..Main System PLL Clock.
 *  0b010..SYSPLL0 AUX0_PLL_Clock.
 *  0b011..FFRO Clock.
 *  0b100..SYSPLL0 AUX1_PLL_Clock.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_SDIO1FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKSEL_SEL_SHIFT)) & CLKCTL0_SDIO1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name SDIO1FCLKDIV - SDIO1 FCLK divider */
/*! @{ */

#define CLKCTL0_SDIO1FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_SDIO1FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_SDIO1FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_DIV_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_DIV_MASK)

#define CLKCTL0_SDIO1FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_SDIO1FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_SDIO1FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_RESET_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_RESET_MASK)

#define CLKCTL0_SDIO1FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_SDIO1FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_SDIO1FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_HALT_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_HALT_MASK)

#define CLKCTL0_SDIO1FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_SDIO1FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_SDIO1FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name ESPIFCLKSEL0 - ESPI clock selection */
/*! @{ */

#define CLKCTL0_ESPIFCLKSEL0_SEL_MASK            (0x7U)
#define CLKCTL0_ESPIFCLKSEL0_SEL_SHIFT           (0U)
/*! SEL - eSPI Functional Clock Source Selection.
 *  0b000..FFRO Clock (48/60m_irc).
 *  0b001..Reserved.
 *  0b010..Reserved.
 *  0b011..Reserved.
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_ESPIFCLKSEL0_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ESPIFCLKSEL0_SEL_SHIFT)) & CLKCTL0_ESPIFCLKSEL0_SEL_MASK)
/*! @} */

/*! @name ADC0FCLKSEL0 - ADC0 fclk selection 0 */
/*! @{ */

#define CLKCTL0_ADC0FCLKSEL0_SEL_MASK            (0x7U)
#define CLKCTL0_ADC0FCLKSEL0_SEL_SHIFT           (0U)
/*! SEL - Clock Output Select 1st Stage. . .
 *  0b000..SFRO Clock.
 *  0b001..XTALIN Clock.
 *  0b010..Low Power Oscillator Clock (LPOSC).
 *  0b011..FFRO Clock.
 *  0b100..reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_ADC0FCLKSEL0_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKSEL0_SEL_SHIFT)) & CLKCTL0_ADC0FCLKSEL0_SEL_MASK)
/*! @} */

/*! @name ADC0FCLKSEL1 - ADC0 fclk selection 1 */
/*! @{ */

#define CLKCTL0_ADC0FCLKSEL1_SEL_MASK            (0x7U)
#define CLKCTL0_ADC0FCLKSEL1_SEL_SHIFT           (0U)
/*! SEL - ADC Functional Clock Source Selection. . .
 *  0b000..ADC0FCLKSEL0 Multiplexed Output.
 *  0b001..SYSPLL0 MAIN_CLK (PFD0 Output)
 *  0b010..reserved.
 *  0b011..SYSPLL0 AUX0_PLL_Clock.
 *  0b100..reserved.
 *  0b101..SYSPLL0 AUX1_PLL_Clock.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_ADC0FCLKSEL1_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKSEL1_SEL_SHIFT)) & CLKCTL0_ADC0FCLKSEL1_SEL_MASK)
/*! @} */

/*! @name ADC0FCLKDIV - ADC0 fclk divider */
/*! @{ */

#define CLKCTL0_ADC0FCLKDIV_DIV_MASK             (0xFFU)
#define CLKCTL0_ADC0FCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_ADC0FCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_DIV_SHIFT)) & CLKCTL0_ADC0FCLKDIV_DIV_MASK)

#define CLKCTL0_ADC0FCLKDIV_RESET_MASK           (0x20000000U)
#define CLKCTL0_ADC0FCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_ADC0FCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_RESET_SHIFT)) & CLKCTL0_ADC0FCLKDIV_RESET_MASK)

#define CLKCTL0_ADC0FCLKDIV_HALT_MASK            (0x40000000U)
#define CLKCTL0_ADC0FCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_ADC0FCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_HALT_SHIFT)) & CLKCTL0_ADC0FCLKDIV_HALT_MASK)

#define CLKCTL0_ADC0FCLKDIV_REQFLAG_MASK         (0x80000000U)
#define CLKCTL0_ADC0FCLKDIV_REQFLAG_SHIFT        (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_ADC0FCLKDIV_REQFLAG(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_ADC0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name UTICKFCLKSEL - UTICK fclk selection */
/*! @{ */

#define CLKCTL0_UTICKFCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_UTICKFCLKSEL_SEL_SHIFT           (0U)
/*! SEL - uTICK Functional Clock Source Selection. .
 *  0b000..Low Power Oscillator Clock (LPOSC).
 *  0b001..reserved.
 *  0b010..reserved.
 *  0b011..reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_UTICKFCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICKFCLKSEL_SEL_SHIFT)) & CLKCTL0_UTICKFCLKSEL_SEL_MASK)
/*! @} */

/*! @name WDT0FCLKSEL - wdt clock selection */
/*! @{ */

#define CLKCTL0_WDT0FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL0_WDT0FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - WDT0 Functional Clock Source Selection. .
 *  0b000..Low Power Oscillator Clock (LPOSC).
 *  0b001..reserved.
 *  0b010..reserved.
 *  0b011..reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_WDT0FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WDT0FCLKSEL_SEL_SHIFT)) & CLKCTL0_WDT0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name WAKECLK32KHZSEL - 32k wake clock selection */
/*! @{ */

#define CLKCTL0_WAKECLK32KHZSEL_SEL_MASK         (0x7U)
#define CLKCTL0_WAKECLK32KHZSEL_SEL_SHIFT        (0U)
/*! SEL - 32KHz Wake Clock Low Power Functional Clock Source Selection. . .
 *  0b000..32KHz
 *  0b001..LPOSC (Divided by 32 by default).
 *  0b010..reserved.
 *  0b011..reserved.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_WAKECLK32KHZSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WAKECLK32KHZSEL_SEL_SHIFT)) & CLKCTL0_WAKECLK32KHZSEL_SEL_MASK)
/*! @} */

/*! @name WAKECLK32KHZDIV - 32k wake clock divider */
/*! @{ */

#define CLKCTL0_WAKECLK32KHZDIV_HALT_MASK        (0x40000000U)
#define CLKCTL0_WAKECLK32KHZDIV_HALT_SHIFT       (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_WAKECLK32KHZDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WAKECLK32KHZDIV_HALT_SHIFT)) & CLKCTL0_WAKECLK32KHZDIV_HALT_MASK)
/*! @} */

/*! @name SYSTICKFCLKSEL - system tick fclk selection */
/*! @{ */

#define CLKCTL0_SYSTICKFCLKSEL_SEL_MASK          (0x7U)
#define CLKCTL0_SYSTICKFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - SYSTICK Functional Clock Source Selection. . .
 *  0b000..Systick Divider Output Clock.
 *  0b001..Low Power Oscillator Clock (LPOSC).
 *  0b010..32KHz RTC Clock.
 *  0b011..SFRO Clock.
 *  0b100..reserved.
 *  0b101..reserved.
 *  0b110..Reserved.
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define CLKCTL0_SYSTICKFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKSEL_SEL_SHIFT)) & CLKCTL0_SYSTICKFCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKFCLKDIV - system tick fclk divider */
/*! @{ */

#define CLKCTL0_SYSTICKFCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL0_SYSTICKFCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Selection. . . 0: Divide by 1. ... 255: Divide by 256. */
#define CLKCTL0_SYSTICKFCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_DIV_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_DIV_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL0_SYSTICKFCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define CLKCTL0_SYSTICKFCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_RESET_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_RESET_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL0_SYSTICKFCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider's clock source to be
 *    changed without the risk of a glitch at the output.
 */
#define CLKCTL0_SYSTICKFCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_HALT_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_HALT_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Divider status flag. Set when a change is made to the divider value, cleared when the change is complete. */
#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_REQFLAG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL0_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL0_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL0_H_ */

