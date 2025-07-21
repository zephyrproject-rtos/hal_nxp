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
 * @file PERI_CLKCTL0.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL0
 *
 * CMSIS Peripheral Access Layer for CLKCTL0
 */

#if !defined(PERI_CLKCTL0_H_)
#define PERI_CLKCTL0_H_                          /**< Symbol preventing repeated inclusion */

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
  __IO uint32_t PSCCTL0;                           /**< Clock Control 0, offset: 0x10 */
  __IO uint32_t PSCCTL1;                           /**< Clock Control 1, offset: 0x14 */
  __IO uint32_t PSCCTL2;                           /**< Clock Control 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __O  uint32_t PSCCTL0_SET;                       /**< Clock Control 0 Set, offset: 0x40 */
  __O  uint32_t PSCCTL1_SET;                       /**< Clock Control 1 Set, offset: 0x44 */
  __O  uint32_t PSCCTL2_SET;                       /**< Clock Control 2 Set, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __O  uint32_t PSCCTL0_CLR;                       /**< Clock Control 0 Clear, offset: 0x70 */
  __O  uint32_t PSCCTL1_CLR;                       /**< Clock Control 1 Clear, offset: 0x74 */
  __O  uint32_t PSCCTL2_CLR;                       /**< Clock Control 2 Clear, offset: 0x78 */
       uint8_t RESERVED_3[4];
  __IO uint32_t FRO_CONTROL;                       /**< Free Running Oscillator Control, offset: 0x80 */
  __I  uint32_t FRO_CAPVAL;                        /**< Free Running Oscillator Captured Value, offset: 0x84 */
       uint8_t RESERVED_4[4];
  __IO uint32_t FRO_RDTRIM;                        /**< Free Running Oscillator Trim, offset: 0x8C */
  __IO uint32_t FRO_SCTRIM;                        /**< Free Running OscillatorSC Trim, offset: 0x90 */
       uint8_t RESERVED_5[116];
  __IO uint32_t FRODIVSEL;                         /**< FRO Clock Divider, offset: 0x108 */
  __I  uint32_t FROCLKSTATUS;                      /**< FRO Clock Status, offset: 0x10C */
  __IO uint32_t FRODIVOEN;                         /**< FRO Enable Register, offset: 0x110 */
       uint8_t RESERVED_6[28];
  __IO uint32_t LOWFREQCLKDIV;                     /**< Low Frequency Clock Divider, offset: 0x130 */
       uint8_t RESERVED_7[44];
  __IO uint32_t SYSOSCCTL0;                        /**< System Oscillator Control 0, offset: 0x160 */
       uint8_t RESERVED_8[4];
  __IO uint32_t SYSOSCBYPASS;                      /**< OSC Clock Source Select, offset: 0x168 */
       uint8_t RESERVED_9[36];
  __IO uint32_t LPOSCCTL0;                         /**< Low Power Oscillator Control 0, offset: 0x190 */
       uint8_t RESERVED_10[44];
  __IO uint32_t OSC32KHZCTL0;                      /**< 32 KHz Oscillator Control 0, offset: 0x1C0 */
       uint8_t RESERVED_11[60];
  __IO uint32_t SYSPLL0CLKSEL;                     /**< System PLL 0 Clock Select, offset: 0x200 */
  __IO uint32_t SYSPLL0CTL0;                       /**< System PLL0 Control 0, offset: 0x204 */
       uint8_t RESERVED_12[4];
  __IO uint32_t SYSPLL0LOCKTIMEDIV2;               /**< System PLL0 Lock Time Div2, offset: 0x20C */
  __IO uint32_t SYSPLL0NUM;                        /**< System PLL0 Numerator, offset: 0x210 */
  __IO uint32_t SYSPLL0DENOM;                      /**< System PLL0 Denominator, offset: 0x214 */
  __IO uint32_t SYSPLL0PFD;                        /**< System PLL0 PFD, offset: 0x218 */
       uint8_t RESERVED_13[36];
  __IO uint32_t MAINPLLCLKDIV;                     /**< Main PLL Clock Divider, offset: 0x240 */
  __IO uint32_t DSPPLLCLKDIV;                      /**< DSP PLL Clock Divider, offset: 0x244 */
  __IO uint32_t AUX0PLLCLKDIV;                     /**< AUX0 PLL Clock Divider, offset: 0x248 */
  __IO uint32_t AUX1PLLCLKDIV;                     /**< AUX1 PLL Clock Divider, offset: 0x24C */
       uint8_t RESERVED_14[432];
  __IO uint32_t SYSCPUAHBCLKDIV;                   /**< System CPU AHB Clock Divider, offset: 0x400 */
       uint8_t RESERVED_15[44];
  __IO uint32_t MAINCLKSELA;                       /**< Main Clock Select A, offset: 0x430 */
  __IO uint32_t MAINCLKSELB;                       /**< Main Clock Select B, offset: 0x434 */
       uint8_t RESERVED_16[200];
  __IO uint32_t PFCDIV[CLKCTL0_PFCDIV_COUNT];      /**< PFC divider 0 (trace clock)..PFC divider 1 (USB HS PHY bus clock), array offset: 0x500, array step: 0x4 */
       uint8_t RESERVED_17[280];
  __IO uint32_t FLEXSPI0FCLKSEL;                   /**< FlexSPI0 Functional Clock Select, offset: 0x620 */
  __IO uint32_t FLEXSPI0FCLKDIV;                   /**< FlexSPI0 Functional Clock Divider, offset: 0x624 */
       uint8_t RESERVED_18[8];
  __IO uint32_t FLEXSPI1FCLKSEL;                   /**< FlexSPI1 Functional Clock Select, offset: 0x630 */
  __IO uint32_t FLEXSPI1FCLKDIV;                   /**< FlexSPI1 Functional Clock Divider, offset: 0x634 */
       uint8_t RESERVED_19[8];
  __IO uint32_t SCTFCLKSEL;                        /**< SCT Functional Clock Select, offset: 0x640 */
  __IO uint32_t SCTIN7CLKDIV;                      /**< SCT Functional Clock Divider, offset: 0x644 */
       uint8_t RESERVED_20[24];
  __IO uint32_t USBHSFCLKSEL;                      /**< High Speed USB Functional Clock Select, offset: 0x660 */
  __IO uint32_t USBHSFCLKDIV;                      /**< High Speed USB Functional Clock Divider, offset: 0x664 */
       uint8_t RESERVED_21[24];
  __IO uint32_t SDIO0FCLKSEL;                      /**< SDIO0 Functional Clock Select, offset: 0x680 */
  __IO uint32_t SDIO0FCLKDIV;                      /**< SDIO0 Functional Clock Divider, offset: 0x684 */
       uint8_t RESERVED_22[8];
  __IO uint32_t SDIO1FCLKSEL;                      /**< SDIO1 Functional Clock Select, offset: 0x690 */
  __IO uint32_t SDIO1FCLKDIV;                      /**< SDIO1 Functional Clock Divider, offset: 0x694 */
       uint8_t RESERVED_23[56];
  __IO uint32_t ADC0FCLKSEL0;                      /**< ADC0 Functional Clock Select 0, offset: 0x6D0 */
  __IO uint32_t ADC0FCLKSEL1;                      /**< ADC0 Functional Clock Select 1, offset: 0x6D4 */
  __IO uint32_t ADC0FCLKDIV;                       /**< ADC0 Functional Clock Divider, offset: 0x6D8 */
       uint8_t RESERVED_24[36];
  __IO uint32_t UTICKFCLKSEL;                      /**< UTICK Functional Clock Select, offset: 0x700 */
       uint8_t RESERVED_25[28];
  __IO uint32_t WDT0FCLKSEL;                       /**< WDT0 Functional Clock Select, offset: 0x720 */
       uint8_t RESERVED_26[12];
  __IO uint32_t A32KHZWAKECLKSEL;                  /**< 32 KHz Wake Clock Source Select, offset: 0x730 */
  __IO uint32_t A32KHZWAKECLKDIV;                  /**< 32 KHz Wake Clock Divider, offset: 0x734 */
       uint8_t RESERVED_27[40];
  __IO uint32_t SYSTICKFCLKSEL;                    /**< SYSTICK Functional Clock Select, offset: 0x760 */
  __IO uint32_t SYSTICKFCLKDIV;                    /**< SYSTICK Functional Clock Divider, offset: 0x764 */
       uint8_t RESERVED_28[8];
  __IO uint32_t DPHYCLKSEL;                        /**< MIPI-DSI PHY Clock Select, offset: 0x770 */
  __IO uint32_t DPHYCLKDIV;                        /**< MIPI-DSI PHY Clock Divider, offset: 0x774 */
  __IO uint32_t DPHYESCCLKSEL;                     /**< MIPI-DSI DPHY Escape Mode Clock Select, offset: 0x778 */
  __IO uint32_t DPHYESCRXCLKDIV;                   /**< MIPI-DSI DPHY Escape Mode Receive Clock Divider, offset: 0x77C */
  __IO uint32_t DPHYESCTXCLKDIV;                   /**< MIPI-DSI DPHY Escape Mode Tramsmit Clock Divider, offset: 0x780 */
       uint8_t RESERVED_29[12];
  __IO uint32_t GPUCLKSEL;                         /**< GPU Clock Select, offset: 0x790 */
  __IO uint32_t GPUCLKDIV;                         /**< GPU Clock Divider, offset: 0x794 */
       uint8_t RESERVED_30[8];
  __IO uint32_t DCPIXELCLKSEL;                     /**< LCDIF Pixel Clock Select, offset: 0x7A0 */
  __IO uint32_t DCPIXELCLKDIV;                     /**< LCDIF Pixel Clock Divider, offset: 0x7A4 */
} CLKCTL0_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL0_Register_Masks CLKCTL0 Register Masks
 * @{
 */

/*! @name PSCCTL0 - Clock Control 0 */
/*! @{ */

#define CLKCTL0_PSCCTL0_DSP_CLK_MASK             (0x2U)
#define CLKCTL0_PSCCTL0_DSP_CLK_SHIFT            (1U)
/*! DSP_CLK - DSP clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_DSP_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_DSP_CLK_SHIFT)) & CLKCTL0_PSCCTL0_DSP_CLK_MASK)

#define CLKCTL0_PSCCTL0_ROM_CTRLR_CLK_MASK       (0x4U)
#define CLKCTL0_PSCCTL0_ROM_CTRLR_CLK_SHIFT      (2U)
/*! ROM_CTRLR_CLK - 128KB ROM Controller clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_ROM_CTRLR_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_ROM_CTRLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_ROM_CTRLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_AXI_SWITCH_CLK_MASK      (0x8U)
#define CLKCTL0_PSCCTL0_AXI_SWITCH_CLK_SHIFT     (3U)
/*! AXI_SWITCH_CLK - AXI Switch clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_AXI_SWITCH_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_AXI_SWITCH_CLK_SHIFT)) & CLKCTL0_PSCCTL0_AXI_SWITCH_CLK_MASK)

#define CLKCTL0_PSCCTL0_AXI_CTLR_CLK_MASK        (0x10U)
#define CLKCTL0_PSCCTL0_AXI_CTLR_CLK_SHIFT       (4U)
/*! AXI_CTLR_CLK - AXI Controller clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_AXI_CTLR_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_AXI_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_AXI_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_POWERQUAD_CLK_MASK       (0x100U)
#define CLKCTL0_PSCCTL0_POWERQUAD_CLK_SHIFT      (8U)
/*! POWERQUAD_CLK - POWERQUAD clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_POWERQUAD_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_POWERQUAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_POWERQUAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_CASPER_CLK_MASK          (0x200U)
#define CLKCTL0_PSCCTL0_CASPER_CLK_SHIFT         (9U)
/*! CASPER_CLK - CASPER clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_CASPER_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CASPER_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CASPER_CLK_MASK)

#define CLKCTL0_PSCCTL0_HASHCRYPT_CLK_MASK       (0x400U)
#define CLKCTL0_PSCCTL0_HASHCRYPT_CLK_SHIFT      (10U)
/*! HASHCRYPT_CLK - HASHCRYPT clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_HASHCRYPT_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_HASHCRYPT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_HASHCRYPT_CLK_MASK)

#define CLKCTL0_PSCCTL0_PUF_CLK_MASK             (0x800U)
#define CLKCTL0_PSCCTL0_PUF_CLK_SHIFT            (11U)
/*! PUF_CLK - PUF clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_PUF_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_PUF_CLK_SHIFT)) & CLKCTL0_PSCCTL0_PUF_CLK_MASK)

#define CLKCTL0_PSCCTL0_RNG_CLK_MASK             (0x1000U)
#define CLKCTL0_PSCCTL0_RNG_CLK_SHIFT            (12U)
/*! RNG_CLK - Random Number Generator (RNG) clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_RNG_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_RNG_CLK_SHIFT)) & CLKCTL0_PSCCTL0_RNG_CLK_MASK)

#define CLKCTL0_PSCCTL0_FLEXSPI0_OTFAD_CLK_MASK  (0x10000U)
#define CLKCTL0_PSCCTL0_FLEXSPI0_OTFAD_CLK_SHIFT (16U)
/*! FLEXSPI0_OTFAD_CLK - FLEXSPI0 / OTFAD clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_FLEXSPI0_OTFAD_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_FLEXSPI0_OTFAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_FLEXSPI0_OTFAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_OTP_CTLR_CLK_MASK        (0x20000U)
#define CLKCTL0_PSCCTL0_OTP_CTLR_CLK_SHIFT       (17U)
/*! OTP_CTLR_CLK - OTP Controller clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_OTP_CTLR_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_OTP_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_OTP_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_FLEXSPI1_CLK_MASK        (0x40000U)
#define CLKCTL0_PSCCTL0_FLEXSPI1_CLK_SHIFT       (18U)
/*! FLEXSPI1_CLK - FLEXSPI1 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_FLEXSPI1_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_FLEXSPI1_CLK_SHIFT)) & CLKCTL0_PSCCTL0_FLEXSPI1_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_PHY_CLK_MASK       (0x100000U)
#define CLKCTL0_PSCCTL0_USBHS_PHY_CLK_SHIFT      (20U)
/*! USBHS_PHY_CLK - USB HS PHY clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_USBHS_PHY_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_PHY_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_PHY_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_MASK    (0x200000U)
#define CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_SHIFT   (21U)
/*! USBHS_DEVICE_CLK - USB HS Device clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_DEVICE_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_HOST_CLK_MASK      (0x400000U)
#define CLKCTL0_PSCCTL0_USBHS_HOST_CLK_SHIFT     (22U)
/*! USBHS_HOST_CLK - USB HS Host clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_USBHS_HOST_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_HOST_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_HOST_CLK_MASK)

#define CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_MASK      (0x800000U)
#define CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_SHIFT     (23U)
/*! USBHS_SRAM_CLK - USB HS SRAM clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_USBHS_SRAM_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_SHIFT)) & CLKCTL0_PSCCTL0_USBHS_SRAM_CLK_MASK)

#define CLKCTL0_PSCCTL0_SCT_CLK_MASK             (0x1000000U)
#define CLKCTL0_PSCCTL0_SCT_CLK_SHIFT            (24U)
/*! SCT_CLK - SCT clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_SCT_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SCT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SCT_CLK_MASK)

#define CLKCTL0_PSCCTL0_GPU_CLK_MASK             (0x4000000U)
#define CLKCTL0_PSCCTL0_GPU_CLK_SHIFT            (26U)
/*! GPU_CLK - GPU clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_GPU_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_GPU_CLK_SHIFT)) & CLKCTL0_PSCCTL0_GPU_CLK_MASK)

#define CLKCTL0_PSCCTL0_DISPLAY_CTLR_CLK_MASK    (0x8000000U)
#define CLKCTL0_PSCCTL0_DISPLAY_CTLR_CLK_SHIFT   (27U)
/*! DISPLAY_CTLR_CLK - Display Controller clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_DISPLAY_CTLR_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_DISPLAY_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_DISPLAY_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_MIPI_DSI_CTLR_CLK_MASK   (0x10000000U)
#define CLKCTL0_PSCCTL0_MIPI_DSI_CTLR_CLK_SHIFT  (28U)
/*! MIPI_DSI_CTLR_CLK - MIPI-DSI Controller clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_MIPI_DSI_CTLR_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_MIPI_DSI_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_MIPI_DSI_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_SMARTDMA_CLK_MASK        (0x40000000U)
#define CLKCTL0_PSCCTL0_SMARTDMA_CLK_SHIFT       (30U)
/*! SMARTDMA_CLK - Smart DMA clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL0_SMARTDMA_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SMARTDMA_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SMARTDMA_CLK_MASK)
/*! @} */

/*! @name PSCCTL1 - Clock Control 1 */
/*! @{ */

#define CLKCTL0_PSCCTL1_SDIO0_CLK_MASK           (0x4U)
#define CLKCTL0_PSCCTL1_SDIO0_CLK_SHIFT          (2U)
/*! SDIO0_CLK - SDIO0 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL1_SDIO0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SDIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SDIO0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SDIO1_CLK_MASK           (0x8U)
#define CLKCTL0_PSCCTL1_SDIO1_CLK_SHIFT          (3U)
/*! SDIO1_CLK - SDIO1 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL1_SDIO1_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SDIO1_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SDIO1_CLK_MASK)

#define CLKCTL0_PSCCTL1_ACMP0_CLK_MASK           (0x8000U)
#define CLKCTL0_PSCCTL1_ACMP0_CLK_SHIFT          (15U)
/*! ACMP0_CLK - ACMP0 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL1_ACMP0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_ACMP0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_ACMP0_CLK_MASK)

#define CLKCTL0_PSCCTL1_ADC0_CLK_MASK            (0x10000U)
#define CLKCTL0_PSCCTL1_ADC0_CLK_SHIFT           (16U)
/*! ADC0_CLK - ADC0 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL1_ADC0_CLK(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_ADC0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_ADC0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SHSGPIO0_CLK_MASK        (0x1000000U)
#define CLKCTL0_PSCCTL1_SHSGPIO0_CLK_SHIFT       (24U)
/*! SHSGPIO0_CLK - SHSGPIO0 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL1_SHSGPIO0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SHSGPIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SHSGPIO0_CLK_MASK)
/*! @} */

/*! @name PSCCTL2 - Clock Control 2 */
/*! @{ */

#define CLKCTL0_PSCCTL2_UTICK0_CLK_MASK          (0x1U)
#define CLKCTL0_PSCCTL2_UTICK0_CLK_SHIFT         (0U)
/*! UTICK0_CLK - Micro-Tick Timer 0 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL2_UTICK0_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_UTICK0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_UTICK0_CLK_MASK)

#define CLKCTL0_PSCCTL2_WWDT0_CLK_MASK           (0x2U)
#define CLKCTL0_PSCCTL2_WWDT0_CLK_SHIFT          (1U)
/*! WWDT0_CLK - Watchdog Timer 0 clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL2_WWDT0_CLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_WWDT0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_WWDT0_CLK_MASK)

#define CLKCTL0_PSCCTL2_PMC_CLK_MASK             (0x20000000U)
#define CLKCTL0_PSCCTL2_PMC_CLK_SHIFT            (29U)
/*! PMC_CLK - Power Management Controller clock control
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_PSCCTL2_PMC_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_PMC_CLK_SHIFT)) & CLKCTL0_PSCCTL2_PMC_CLK_MASK)
/*! @} */

/*! @name PSCCTL0_SET - Clock Control 0 Set */
/*! @{ */

#define CLKCTL0_PSCCTL0_SET_DSP_CLK_MASK         (0x2U)
#define CLKCTL0_PSCCTL0_SET_DSP_CLK_SHIFT        (1U)
/*! DSP_CLK - DSP clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_DSP_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_DSP_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_DSP_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_ROM_CTRLR_CLK_MASK   (0x4U)
#define CLKCTL0_PSCCTL0_SET_ROM_CTRLR_CLK_SHIFT  (2U)
/*! ROM_CTRLR_CLK - 128KB ROM Controller clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_ROM_CTRLR_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_ROM_CTRLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_ROM_CTRLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_AXI_SWITCH_CLK_MASK  (0x8U)
#define CLKCTL0_PSCCTL0_SET_AXI_SWITCH_CLK_SHIFT (3U)
/*! AXI_SWITCH_CLK - AXI Switch clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_AXI_SWITCH_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_AXI_SWITCH_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_AXI_SWITCH_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_AXI_CTLR_CLK_MASK    (0x10U)
#define CLKCTL0_PSCCTL0_SET_AXI_CTLR_CLK_SHIFT   (4U)
/*! AXI_CTLR_CLK - AXI Controller clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_AXI_CTLR_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_AXI_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_AXI_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_MASK   (0x100U)
#define CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_SHIFT  (8U)
/*! POWERQUAD_CLK - POWERQUAD clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_POWERQUAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_CASPER_CLK_MASK      (0x200U)
#define CLKCTL0_PSCCTL0_SET_CASPER_CLK_SHIFT     (9U)
/*! CASPER_CLK - CASPER clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_CASPER_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_CASPER_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_CASPER_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_MASK   (0x400U)
#define CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_SHIFT  (10U)
/*! HASHCRYPT_CLK - HASHCRYPT clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_HASHCRYPT_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_PUF_CLK_MASK         (0x800U)
#define CLKCTL0_PSCCTL0_SET_PUF_CLK_SHIFT        (11U)
/*! PUF_CLK - PUF clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_PUF_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_PUF_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_PUF_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_RNG_CLK_MASK         (0x1000U)
#define CLKCTL0_PSCCTL0_SET_RNG_CLK_SHIFT        (12U)
/*! RNG_CLK - Random Number Generator (RNG) clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_RNG_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_RNG_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_RNG_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_FLEXSPI0_OTFAD_CLK_MASK (0x10000U)
#define CLKCTL0_PSCCTL0_SET_FLEXSPI0_OTFAD_CLK_SHIFT (16U)
/*! FLEXSPI0_OTFAD_CLK - FLEXSPI0 / OTFAD clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_FLEXSPI0_OTFAD_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_FLEXSPI0_OTFAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_FLEXSPI0_OTFAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_OTP_CTLR_CLK_MASK    (0x20000U)
#define CLKCTL0_PSCCTL0_SET_OTP_CTLR_CLK_SHIFT   (17U)
/*! OTP_CTLR_CLK - OTP Controller clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_OTP_CTLR_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_OTP_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_OTP_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_FLEXSPI1_CLK_MASK    (0x40000U)
#define CLKCTL0_PSCCTL0_SET_FLEXSPI1_CLK_SHIFT   (18U)
/*! FLEXSPI1_CLK - FLEXSPI1 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_FLEXSPI1_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_FLEXSPI1_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_FLEXSPI1_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_MASK   (0x100000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_SHIFT  (20U)
/*! USBHS_PHY_CLK - USB HS PHY clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_PHY_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_MASK (0x200000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_SHIFT (21U)
/*! USBHS_DEVICE_CLK - USB HS Device clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_DEVICE_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_MASK  (0x400000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_SHIFT (22U)
/*! USBHS_HOST_CLK - USB HS Host clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_HOST_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_MASK  (0x800000U)
#define CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_SHIFT (23U)
/*! USBHS_SRAM_CLK - USB HS SRAM clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_USBHS_SRAM_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_SCT_CLK_MASK         (0x1000000U)
#define CLKCTL0_PSCCTL0_SET_SCT_CLK_SHIFT        (24U)
/*! SCT_CLK - SCT clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_SCT_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_SCT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_SCT_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_GPU_CLK_MASK         (0x4000000U)
#define CLKCTL0_PSCCTL0_SET_GPU_CLK_SHIFT        (26U)
/*! GPU_CLK - GPU clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_GPU_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_GPU_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_GPU_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_DISPLAY_CTLR_CLK_MASK (0x8000000U)
#define CLKCTL0_PSCCTL0_SET_DISPLAY_CTLR_CLK_SHIFT (27U)
/*! DISPLAY_CTLR_CLK - Display Controller clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_DISPLAY_CTLR_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_DISPLAY_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_DISPLAY_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_MIPI_DSI_CTLR_CLK_MASK (0x10000000U)
#define CLKCTL0_PSCCTL0_SET_MIPI_DSI_CTLR_CLK_SHIFT (28U)
/*! MIPI_DSI_CTLR_CLK - MIPI-DSI Controller clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_MIPI_DSI_CTLR_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_MIPI_DSI_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_MIPI_DSI_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_SET_SMARTDMA_CLK_MASK    (0x40000000U)
#define CLKCTL0_PSCCTL0_SET_SMARTDMA_CLK_SHIFT   (30U)
/*! SMARTDMA_CLK - Smart DMA clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_SET_SMARTDMA_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_SMARTDMA_CLK_SHIFT)) & CLKCTL0_PSCCTL0_SET_SMARTDMA_CLK_MASK)
/*! @} */

/*! @name PSCCTL1_SET - Clock Control 1 Set */
/*! @{ */

#define CLKCTL0_PSCCTL1_SET_SDIO0_CLK_MASK       (0x4U)
#define CLKCTL0_PSCCTL1_SET_SDIO0_CLK_SHIFT      (2U)
/*! SDIO0_CLK - SDIO0 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_SET_SDIO0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SDIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_SDIO0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_SDIO1_CLK_MASK       (0x8U)
#define CLKCTL0_PSCCTL1_SET_SDIO1_CLK_SHIFT      (3U)
/*! SDIO1_CLK - SDIO1 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_SET_SDIO1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SDIO1_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_SDIO1_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_ACMP0_CLK_MASK       (0x8000U)
#define CLKCTL0_PSCCTL1_SET_ACMP0_CLK_SHIFT      (15U)
/*! ACMP0_CLK - ACMP0 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_SET_ACMP0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_ACMP0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_ACMP0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_ADC0_CLK_MASK        (0x10000U)
#define CLKCTL0_PSCCTL1_SET_ADC0_CLK_SHIFT       (16U)
/*! ADC0_CLK - ADC0 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_SET_ADC0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_ADC0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_ADC0_CLK_MASK)

#define CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_MASK    (0x1000000U)
#define CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_SHIFT   (24U)
/*! SHSGPIO0_CLK - SHSGPIO0 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_SHSGPIO0_CLK_MASK)
/*! @} */

/*! @name PSCCTL2_SET - Clock Control 2 Set */
/*! @{ */

#define CLKCTL0_PSCCTL2_SET_UTICK0_CLK_MASK      (0x1U)
#define CLKCTL0_PSCCTL2_SET_UTICK0_CLK_SHIFT     (0U)
/*! UTICK0_CLK - Micro-Tick Timer 0 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL2 register
 */
#define CLKCTL0_PSCCTL2_SET_UTICK0_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_UTICK0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_SET_UTICK0_CLK_MASK)

#define CLKCTL0_PSCCTL2_SET_WWDT0_CLK_MASK       (0x2U)
#define CLKCTL0_PSCCTL2_SET_WWDT0_CLK_SHIFT      (1U)
/*! WWDT0_CLK - Watchdog Timer 0 clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL2 register
 */
#define CLKCTL0_PSCCTL2_SET_WWDT0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_WWDT0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_SET_WWDT0_CLK_MASK)

#define CLKCTL0_PSCCTL2_SET_PMC_MASK             (0x20000000U)
#define CLKCTL0_PSCCTL2_SET_PMC_SHIFT            (29U)
/*! PMC - Power Management Controller clock set
 *  0b0..No effect
 *  0b1..Sets the corresponding bit in PSCCTL2 register
 */
#define CLKCTL0_PSCCTL2_SET_PMC(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_PMC_SHIFT)) & CLKCTL0_PSCCTL2_SET_PMC_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - Clock Control 0 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL0_CLR_DSP_CLK_MASK         (0x2U)
#define CLKCTL0_PSCCTL0_CLR_DSP_CLK_SHIFT        (1U)
/*! DSP_CLK - DSP clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_DSP_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_DSP_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_DSP_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_ROM_CTRLR_CLK_MASK   (0x4U)
#define CLKCTL0_PSCCTL0_CLR_ROM_CTRLR_CLK_SHIFT  (2U)
/*! ROM_CTRLR_CLK - 128KB ROM Controller clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_ROM_CTRLR_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_ROM_CTRLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_ROM_CTRLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_AXI_SWITCH_CLK_MASK  (0x8U)
#define CLKCTL0_PSCCTL0_CLR_AXI_SWITCH_CLK_SHIFT (3U)
/*! AXI_SWITCH_CLK - AXI Switch clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_AXI_SWITCH_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_AXI_SWITCH_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_AXI_SWITCH_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_AXI_CTLR_CLK_MASK    (0x10U)
#define CLKCTL0_PSCCTL0_CLR_AXI_CTLR_CLK_SHIFT   (4U)
/*! AXI_CTLR_CLK - AXI Controller clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_AXI_CTLR_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_AXI_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_AXI_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_MASK   (0x100U)
#define CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_SHIFT  (8U)
/*! POWERQUAD_CLK - POWERQUAD clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_POWERQUAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_CASPER_CLK_MASK      (0x200U)
#define CLKCTL0_PSCCTL0_CLR_CASPER_CLK_SHIFT     (9U)
/*! CASPER_CLK - CASPER clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_CASPER_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_CASPER_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_CASPER_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_MASK   (0x400U)
#define CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_SHIFT  (10U)
/*! HASHCRYPT_CLK - HASHCRYPT clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_HASHCRYPT_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_PUF_CLK_MASK         (0x800U)
#define CLKCTL0_PSCCTL0_CLR_PUF_CLK_SHIFT        (11U)
/*! PUF_CLK - PUF clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_PUF_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_PUF_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_PUF_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_RNG_CLK_MASK         (0x1000U)
#define CLKCTL0_PSCCTL0_CLR_RNG_CLK_SHIFT        (12U)
/*! RNG_CLK - RNG clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_RNG_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_RNG_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_RNG_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_FLEXSPI0_OTFAD_CLK_MASK (0x10000U)
#define CLKCTL0_PSCCTL0_CLR_FLEXSPI0_OTFAD_CLK_SHIFT (16U)
/*! FLEXSPI0_OTFAD_CLK - FLEXSPI0 / OTFAD clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_FLEXSPI0_OTFAD_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_FLEXSPI0_OTFAD_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_FLEXSPI0_OTFAD_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_OTP_CTLR_CLK_MASK    (0x20000U)
#define CLKCTL0_PSCCTL0_CLR_OTP_CTLR_CLK_SHIFT   (17U)
/*! OTP_CTLR_CLK - OTP Controller clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_OTP_CTLR_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_OTP_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_OTP_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_FLEXSPI1_CLK_MASK    (0x40000U)
#define CLKCTL0_PSCCTL0_CLR_FLEXSPI1_CLK_SHIFT   (18U)
/*! FLEXSPI1_CLK - FLEXSPI1 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_FLEXSPI1_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_FLEXSPI1_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_FLEXSPI1_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_MASK   (0x100000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_SHIFT  (20U)
/*! USBHS_PHY_CLK - USB HS PHY clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_PHY_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_MASK (0x200000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_SHIFT (21U)
/*! USBHS_DEVICE_CLK - USB HS Device clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_DEVICE_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_MASK  (0x400000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_SHIFT (22U)
/*! USBHS_HOST_CLK - USB HS Host clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_HOST_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_MASK  (0x800000U)
#define CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_SHIFT (23U)
/*! USBHS_SRAM_CLK - USB HS SRAM clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_USBHS_SRAM_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_SCT_CLK_MASK         (0x1000000U)
#define CLKCTL0_PSCCTL0_CLR_SCT_CLK_SHIFT        (24U)
/*! SCT_CLK - SCT clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_SCT_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_SCT_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_SCT_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_GPU_CLK_MASK         (0x4000000U)
#define CLKCTL0_PSCCTL0_CLR_GPU_CLK_SHIFT        (26U)
/*! GPU_CLK - GPU clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_GPU_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_GPU_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_GPU_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_DISPLAY_CTLR_CLK_MASK (0x8000000U)
#define CLKCTL0_PSCCTL0_CLR_DISPLAY_CTLR_CLK_SHIFT (27U)
/*! DISPLAY_CTLR_CLK - Display Controller clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_DISPLAY_CTLR_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_DISPLAY_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_DISPLAY_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_MIPI_DSI_CTLR_CLK_MASK (0x10000000U)
#define CLKCTL0_PSCCTL0_CLR_MIPI_DSI_CTLR_CLK_SHIFT (28U)
/*! MIPI_DSI_CTLR_CLK - MIPI-DSI Controller clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_MIPI_DSI_CTLR_CLK(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_MIPI_DSI_CTLR_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_MIPI_DSI_CTLR_CLK_MASK)

#define CLKCTL0_PSCCTL0_CLR_SMARTDMA_CLK_MASK    (0x40000000U)
#define CLKCTL0_PSCCTL0_CLR_SMARTDMA_CLK_SHIFT   (30U)
/*! SMARTDMA_CLK - Smart DMA clock set
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL0 register
 */
#define CLKCTL0_PSCCTL0_CLR_SMARTDMA_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_SMARTDMA_CLK_SHIFT)) & CLKCTL0_PSCCTL0_CLR_SMARTDMA_CLK_MASK)
/*! @} */

/*! @name PSCCTL1_CLR - Clock Control 1 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_MASK       (0x4U)
#define CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_SHIFT      (2U)
/*! SDIO0_CLK - SDIO0 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_CLR_SDIO0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SDIO0_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_MASK       (0x8U)
#define CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_SHIFT      (3U)
/*! SDIO1_CLK - SDIO1 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_CLR_SDIO1_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SDIO1_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_MASK       (0x8000U)
#define CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_SHIFT      (15U)
/*! ACMP0_CLK - ACMP0 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_CLR_ACMP0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_ACMP0_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_ADC0_CLK_MASK        (0x10000U)
#define CLKCTL0_PSCCTL1_CLR_ADC0_CLK_SHIFT       (16U)
/*! ADC0_CLK - ADC0 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_CLR_ADC0_CLK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_ADC0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_ADC0_CLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_MASK    (0x1000000U)
#define CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_SHIFT   (24U)
/*! SHSGPIO0_CLK - SHSGPIO0 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL1 register
 */
#define CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SHSGPIO0_CLK_MASK)
/*! @} */

/*! @name PSCCTL2_CLR - Clock Control 2 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_MASK      (0x1U)
#define CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_SHIFT     (0U)
/*! UTICK0_CLK - Micro-Tick Timer 0 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL2 register
 */
#define CLKCTL0_PSCCTL2_CLR_UTICK0_CLK(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_CLR_UTICK0_CLK_MASK)

#define CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_MASK       (0x2U)
#define CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_SHIFT      (1U)
/*! WWDT0_CLK - Watchdog Timer 0 clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL2 register
 */
#define CLKCTL0_PSCCTL2_CLR_WWDT0_CLK(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_SHIFT)) & CLKCTL0_PSCCTL2_CLR_WWDT0_CLK_MASK)

#define CLKCTL0_PSCCTL2_CLR_PMC_CLK_MASK         (0x20000000U)
#define CLKCTL0_PSCCTL2_CLR_PMC_CLK_SHIFT        (29U)
/*! PMC_CLK - Power Management Controller clock clear
 *  0b0..No effect
 *  0b1..Clears the corresponding bit in PSCCTL2 register
 */
#define CLKCTL0_PSCCTL2_CLR_PMC_CLK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_PMC_CLK_SHIFT)) & CLKCTL0_PSCCTL2_CLR_PMC_CLK_MASK)
/*! @} */

/*! @name FRO_CONTROL - Free Running Oscillator Control */
/*! @{ */

#define CLKCTL0_FRO_CONTROL_EXP_COUNT_MASK       (0xFFFFU)
#define CLKCTL0_FRO_CONTROL_EXP_COUNT_SHIFT      (0U)
/*! EXP_COUNT - Expected Count */
#define CLKCTL0_FRO_CONTROL_EXP_COUNT(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_CONTROL_EXP_COUNT_SHIFT)) & CLKCTL0_FRO_CONTROL_EXP_COUNT_MASK)

#define CLKCTL0_FRO_CONTROL_THRESH_RANGE_UP_MASK (0x1F0000U)
#define CLKCTL0_FRO_CONTROL_THRESH_RANGE_UP_SHIFT (16U)
/*! THRESH_RANGE_UP - Threshold Range Upper Limit */
#define CLKCTL0_FRO_CONTROL_THRESH_RANGE_UP(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_CONTROL_THRESH_RANGE_UP_SHIFT)) & CLKCTL0_FRO_CONTROL_THRESH_RANGE_UP_MASK)

#define CLKCTL0_FRO_CONTROL_THRESH_RANGE_LOW_MASK (0x3E00000U)
#define CLKCTL0_FRO_CONTROL_THRESH_RANGE_LOW_SHIFT (21U)
/*! THRESH_RANGE_LOW - Threshold Range Lower Limit */
#define CLKCTL0_FRO_CONTROL_THRESH_RANGE_LOW(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_CONTROL_THRESH_RANGE_LOW_SHIFT)) & CLKCTL0_FRO_CONTROL_THRESH_RANGE_LOW_MASK)

#define CLKCTL0_FRO_CONTROL_ENA_TUNE_MASK        (0x80000000U)
#define CLKCTL0_FRO_CONTROL_ENA_TUNE_SHIFT       (31U)
/*! ENA_TUNE - Enable Tuning
 *  0b0..Stop tuning
 *  0b1..Start tuning
 */
#define CLKCTL0_FRO_CONTROL_ENA_TUNE(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_CONTROL_ENA_TUNE_SHIFT)) & CLKCTL0_FRO_CONTROL_ENA_TUNE_MASK)
/*! @} */

/*! @name FRO_CAPVAL - Free Running Oscillator Captured Value */
/*! @{ */

#define CLKCTL0_FRO_CAPVAL_CAPVAL_MASK           (0xFFFFU)
#define CLKCTL0_FRO_CAPVAL_CAPVAL_SHIFT          (0U)
/*! CAPVAL - Captured Value */
#define CLKCTL0_FRO_CAPVAL_CAPVAL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_CAPVAL_CAPVAL_SHIFT)) & CLKCTL0_FRO_CAPVAL_CAPVAL_MASK)

#define CLKCTL0_FRO_CAPVAL_DATA_VALID_MASK       (0x80000000U)
#define CLKCTL0_FRO_CAPVAL_DATA_VALID_SHIFT      (31U)
/*! DATA_VALID - Data Valid
 *  0b0..CAPVAL data is not valid
 *  0b1..CAPVAL data is valid
 */
#define CLKCTL0_FRO_CAPVAL_DATA_VALID(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_CAPVAL_DATA_VALID_SHIFT)) & CLKCTL0_FRO_CAPVAL_DATA_VALID_MASK)
/*! @} */

/*! @name FRO_RDTRIM - Free Running Oscillator Trim */
/*! @{ */

#define CLKCTL0_FRO_RDTRIM_TRIM_MASK             (0x7FFU)
#define CLKCTL0_FRO_RDTRIM_TRIM_SHIFT            (0U)
/*! TRIM - It is the trim value supplied to the oscillator */
#define CLKCTL0_FRO_RDTRIM_TRIM(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_RDTRIM_TRIM_SHIFT)) & CLKCTL0_FRO_RDTRIM_TRIM_MASK)
/*! @} */

/*! @name FRO_SCTRIM - Free Running OscillatorSC Trim */
/*! @{ */

#define CLKCTL0_FRO_SCTRIM_TRIM_MASK             (0x3FU)
#define CLKCTL0_FRO_SCTRIM_TRIM_SHIFT            (0U)
/*! TRIM - sc_trim value for the oscillator. */
#define CLKCTL0_FRO_SCTRIM_TRIM(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO_SCTRIM_TRIM_SHIFT)) & CLKCTL0_FRO_SCTRIM_TRIM_MASK)
/*! @} */

/*! @name FRODIVSEL - FRO Clock Divider */
/*! @{ */

#define CLKCTL0_FRODIVSEL_SEL_MASK               (0x3U)
#define CLKCTL0_FRODIVSEL_SEL_SHIFT              (0U)
/*! SEL - Select clock
 *  0b00..FRO_DIV2
 *  0b01..FRO_DIV4
 *  0b10..FRO_DIV8
 *  0b11..FRO_DIV16
 */
#define CLKCTL0_FRODIVSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRODIVSEL_SEL_SHIFT)) & CLKCTL0_FRODIVSEL_SEL_MASK)
/*! @} */

/*! @name FROCLKSTATUS - FRO Clock Status */
/*! @{ */

#define CLKCTL0_FROCLKSTATUS_CLK_OK_MASK         (0x1U)
#define CLKCTL0_FROCLKSTATUS_CLK_OK_SHIFT        (0U)
/*! CLK_OK - FRO Clock OK
 *  0b0..FRO clock has not yet reached 10% frequency accuracy
 *  0b1..FRO clock has reached 10% frequency accuracy
 */
#define CLKCTL0_FROCLKSTATUS_CLK_OK(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FROCLKSTATUS_CLK_OK_SHIFT)) & CLKCTL0_FROCLKSTATUS_CLK_OK_MASK)
/*! @} */

/*! @name FRODIVOEN - FRO Enable Register */
/*! @{ */

#define CLKCTL0_FRODIVOEN_FRO_DIV1_O_EN_MASK     (0x1U)
#define CLKCTL0_FRODIVOEN_FRO_DIV1_O_EN_SHIFT    (0U)
/*! FRO_DIV1_O_EN - FRO Divided-by-1 Clock Enable
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_FRODIVOEN_FRO_DIV1_O_EN(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRODIVOEN_FRO_DIV1_O_EN_SHIFT)) & CLKCTL0_FRODIVOEN_FRO_DIV1_O_EN_MASK)

#define CLKCTL0_FRODIVOEN_FRO_DIV2_O_EN_MASK     (0x2U)
#define CLKCTL0_FRODIVOEN_FRO_DIV2_O_EN_SHIFT    (1U)
/*! FRO_DIV2_O_EN - FRO Divided-by-2 Clock Enable
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_FRODIVOEN_FRO_DIV2_O_EN(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRODIVOEN_FRO_DIV2_O_EN_SHIFT)) & CLKCTL0_FRODIVOEN_FRO_DIV2_O_EN_MASK)

#define CLKCTL0_FRODIVOEN_FRO_DIV4_O_EN_MASK     (0x4U)
#define CLKCTL0_FRODIVOEN_FRO_DIV4_O_EN_SHIFT    (2U)
/*! FRO_DIV4_O_EN - FRO Divided-by-4 Clock Enable
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_FRODIVOEN_FRO_DIV4_O_EN(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRODIVOEN_FRO_DIV4_O_EN_SHIFT)) & CLKCTL0_FRODIVOEN_FRO_DIV4_O_EN_MASK)

#define CLKCTL0_FRODIVOEN_FRO_DIV8_O_EN_MASK     (0x8U)
#define CLKCTL0_FRODIVOEN_FRO_DIV8_O_EN_SHIFT    (3U)
/*! FRO_DIV8_O_EN - FRO Divided-by-8 Clock Enable
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_FRODIVOEN_FRO_DIV8_O_EN(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRODIVOEN_FRO_DIV8_O_EN_SHIFT)) & CLKCTL0_FRODIVOEN_FRO_DIV8_O_EN_MASK)

#define CLKCTL0_FRODIVOEN_FRO_DIV16_O_EN_MASK    (0x10U)
#define CLKCTL0_FRODIVOEN_FRO_DIV16_O_EN_SHIFT   (4U)
/*! FRO_DIV16_O_EN - FRO Divided-by-16 Clock Enable
 *  0b0..Disable clock
 *  0b1..Enable clock
 */
#define CLKCTL0_FRODIVOEN_FRO_DIV16_O_EN(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRODIVOEN_FRO_DIV16_O_EN_SHIFT)) & CLKCTL0_FRODIVOEN_FRO_DIV16_O_EN_MASK)
/*! @} */

/*! @name LOWFREQCLKDIV - Low Frequency Clock Divider */
/*! @{ */

#define CLKCTL0_LOWFREQCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_LOWFREQCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Low Frequency Clock Divider Value */
#define CLKCTL0_LOWFREQCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_LOWFREQCLKDIV_DIV_SHIFT)) & CLKCTL0_LOWFREQCLKDIV_DIV_MASK)

#define CLKCTL0_LOWFREQCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_LOWFREQCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_LOWFREQCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_LOWFREQCLKDIV_RESET_SHIFT)) & CLKCTL0_LOWFREQCLKDIV_RESET_MASK)

#define CLKCTL0_LOWFREQCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_LOWFREQCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_LOWFREQCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_LOWFREQCLKDIV_HALT_SHIFT)) & CLKCTL0_LOWFREQCLKDIV_HALT_MASK)

#define CLKCTL0_LOWFREQCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_LOWFREQCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider Status Flag
 *  0b0..The Divider change has finished
 *  0b1..The Divider value has changed
 */
#define CLKCTL0_LOWFREQCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_LOWFREQCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_LOWFREQCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SYSOSCCTL0 - System Oscillator Control 0 */
/*! @{ */

#define CLKCTL0_SYSOSCCTL0_LP_ENABLE_MASK        (0x1U)
#define CLKCTL0_SYSOSCCTL0_LP_ENABLE_SHIFT       (0U)
/*! LP_ENABLE - Low Power Mode Enable
 *  0b0..Enable High Gain Mode (HP)
 *  0b1..Enable Low Power mode (LP)
 */
#define CLKCTL0_SYSOSCCTL0_LP_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSOSCCTL0_LP_ENABLE_SHIFT)) & CLKCTL0_SYSOSCCTL0_LP_ENABLE_MASK)

#define CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_MASK    (0x2U)
#define CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_SHIFT   (1U)
/*! BYPASS_ENABLE - Bypass Enable
 *  0b0..Enable Normal mode. Oscillation with crystal connected.
 *  0b1..Enable Bypass mode. In this mode a clock can be directly input into the XTALIN pin.
 */
#define CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_SHIFT)) & CLKCTL0_SYSOSCCTL0_BYPASS_ENABLE_MASK)
/*! @} */

/*! @name SYSOSCBYPASS - OSC Clock Source Select */
/*! @{ */

#define CLKCTL0_SYSOSCBYPASS_SEL_MASK            (0x7U)
#define CLKCTL0_SYSOSCBYPASS_SEL_SHIFT           (0U)
/*! SEL - Select SYSOSC Bypass
 *  0b000..Select OSC Clock
 *  0b001..Select Clock IN clock
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed
 */
#define CLKCTL0_SYSOSCBYPASS_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSOSCBYPASS_SEL_SHIFT)) & CLKCTL0_SYSOSCBYPASS_SEL_MASK)
/*! @} */

/*! @name LPOSCCTL0 - Low Power Oscillator Control 0 */
/*! @{ */

#define CLKCTL0_LPOSCCTL0_CLKRDY_MASK            (0x80000000U)
#define CLKCTL0_LPOSCCTL0_CLKRDY_SHIFT           (31U)
/*! CLKRDY - LPOSC Clock Ready
 *  0b0..LPOSC clock is not ready
 *  0b1..LPOSC clock is ready
 */
#define CLKCTL0_LPOSCCTL0_CLKRDY(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_LPOSCCTL0_CLKRDY_SHIFT)) & CLKCTL0_LPOSCCTL0_CLKRDY_MASK)
/*! @} */

/*! @name OSC32KHZCTL0 - 32 KHz Oscillator Control 0 */
/*! @{ */

#define CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK       (0x1U)
#define CLKCTL0_OSC32KHZCTL0_ENA32KHZ_SHIFT      (0U)
/*! ENA32KHZ - 32 KHz Oscillator Enable
 *  0b0..Disable oscillator
 *  0b1..Enable oscillator
 */
#define CLKCTL0_OSC32KHZCTL0_ENA32KHZ(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_OSC32KHZCTL0_ENA32KHZ_SHIFT)) & CLKCTL0_OSC32KHZCTL0_ENA32KHZ_MASK)
/*! @} */

/*! @name SYSPLL0CLKSEL - System PLL 0 Clock Select */
/*! @{ */

#define CLKCTL0_SYSPLL0CLKSEL_SEL_MASK           (0x7U)
#define CLKCTL0_SYSPLL0CLKSEL_SEL_SHIFT          (0U)
/*! SEL - System PLL0 Reference Input Clock Source
 *  0b000..FRO_DIV8 Clock
 *  0b001..OSC_CLK clock
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None, output gated to reduce power
 */
#define CLKCTL0_SYSPLL0CLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CLKSEL_SEL_SHIFT)) & CLKCTL0_SYSPLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSPLL0CTL0 - System PLL0 Control 0 */
/*! @{ */

#define CLKCTL0_SYSPLL0CTL0_BYPASS_MASK          (0x1U)
#define CLKCTL0_SYSPLL0CTL0_BYPASS_SHIFT         (0U)
/*! BYPASS - SYSPLL0 BYPASS Mode
 *  0b0..PFD outputs are PFD-programmed clocks
 *  0b1..Bypass Mode: PFD outputs are sourced directly from rhe reference input clock
 */
#define CLKCTL0_SYSPLL0CTL0_BYPASS(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_BYPASS_SHIFT)) & CLKCTL0_SYSPLL0CTL0_BYPASS_MASK)

#define CLKCTL0_SYSPLL0CTL0_RESET_MASK           (0x2U)
#define CLKCTL0_SYSPLL0CTL0_RESET_SHIFT          (1U)
/*! RESET - SYSPLL0 Reset
 *  0b0..SYSPLL0 reset is removed
 *  0b1..SYSPLL0 is placed into reset
 */
#define CLKCTL0_SYSPLL0CTL0_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_RESET_SHIFT)) & CLKCTL0_SYSPLL0CTL0_RESET_MASK)

#define CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_MASK (0x2000U)
#define CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_SHIFT (13U)
/*! HOLDRINGOFF_ENA - Hold Ring Off Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_SHIFT)) & CLKCTL0_SYSPLL0CTL0_HOLDRINGOFF_ENA_MASK)

#define CLKCTL0_SYSPLL0CTL0_MULT_MASK            (0xFF0000U)
#define CLKCTL0_SYSPLL0CTL0_MULT_SHIFT           (16U)
/*! MULT - Multiplication Factor
 *  0b00010000..Multiply by 16
 *  0b00010001..Multiply by 17
 *  0b00010010..Multiply by 18
 *  0b00010011..Multiply by 19
 *  0b00010100..Multiply by 20
 *  0b00010101..Multiply by 21
 *  0b00010110..Multiply by 22
 */
#define CLKCTL0_SYSPLL0CTL0_MULT(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0CTL0_MULT_SHIFT)) & CLKCTL0_SYSPLL0CTL0_MULT_MASK)
/*! @} */

/*! @name SYSPLL0LOCKTIMEDIV2 - System PLL0 Lock Time Div2 */
/*! @{ */

#define CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - SYSPLL0 Lock Time Divide-by-2 */
#define CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & CLKCTL0_SYSPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name SYSPLL0NUM - System PLL0 Numerator */
/*! @{ */

#define CLKCTL0_SYSPLL0NUM_NUM_MASK              (0x3FFFFFFFU)
#define CLKCTL0_SYSPLL0NUM_NUM_SHIFT             (0U)
/*! NUM - Numerator of the SYSPLL0 fractional loop divider */
#define CLKCTL0_SYSPLL0NUM_NUM(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0NUM_NUM_SHIFT)) & CLKCTL0_SYSPLL0NUM_NUM_MASK)
/*! @} */

/*! @name SYSPLL0DENOM - System PLL0 Denominator */
/*! @{ */

#define CLKCTL0_SYSPLL0DENOM_DENOM_MASK          (0x3FFFFFFFU)
#define CLKCTL0_SYSPLL0DENOM_DENOM_SHIFT         (0U)
/*! DENOM - Denominator of the SYSPLL0 fractional loop divider */
#define CLKCTL0_SYSPLL0DENOM_DENOM(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0DENOM_DENOM_SHIFT)) & CLKCTL0_SYSPLL0DENOM_DENOM_MASK)
/*! @} */

/*! @name SYSPLL0PFD - System PLL0 PFD */
/*! @{ */

#define CLKCTL0_SYSPLL0PFD_PFD0_MASK             (0x3FU)
#define CLKCTL0_SYSPLL0PFD_PFD0_SHIFT            (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CLKCTL0_SYSPLL0PFD_PFD0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD0_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD0_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_MASK      (0x40U)
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_SHIFT     (6U)
/*! PFD0_CLKRDY - PFD0 Clock Ready Status Flag
 *  0b0..PFD0 clock is not ready
 *  0b1..PFD0 clock is ready
 */
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD0_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_MASK     (0x80U)
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_SHIFT    (7U)
/*! PFD0_CLKGATE - PFD0 Clock Gate
 *  0b0..PFD0 clock is not gated
 *  0b1..PFD0 clock is gated
 */
#define CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD0_CLKGATE_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD1_MASK             (0x3F00U)
#define CLKCTL0_SYSPLL0PFD_PFD1_SHIFT            (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CLKCTL0_SYSPLL0PFD_PFD1(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD1_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD1_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_MASK      (0x4000U)
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_SHIFT     (14U)
/*! PFD1_CLKRDY - PFD1 Clock Ready Status Flag
 *  0b0..PFD1 clock is not ready
 *  0b1..PFD1 clock is ready
 */
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD1_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_MASK     (0x8000U)
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_SHIFT    (15U)
/*! PFD1_CLKGATE - PFD1 Clock Gate
 *  0b0..PFD1 clock is not gated
 *  0b1..PFD1 clock is gated
 */
#define CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD1_CLKGATE_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD2_MASK             (0x3F0000U)
#define CLKCTL0_SYSPLL0PFD_PFD2_SHIFT            (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CLKCTL0_SYSPLL0PFD_PFD2(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD2_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD2_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_MASK      (0x400000U)
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_SHIFT     (22U)
/*! PFD2_CLKRDY - PFD2 Clock Ready Status Flag
 *  0b0..PFD2 clock is not ready
 *  0b1..PFD2 clock is ready
 */
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD2_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_MASK     (0x800000U)
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_SHIFT    (23U)
/*! PFD2_CLKGATE - PFD2 Clock Gate
 *  0b0..PFD2 clock is not gated
 *  0b1..PFD2 clock is gated
 */
#define CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD2_CLKGATE_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD3_MASK             (0x3F000000U)
#define CLKCTL0_SYSPLL0PFD_PFD3_SHIFT            (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CLKCTL0_SYSPLL0PFD_PFD3(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD3_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD3_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_MASK      (0x40000000U)
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_SHIFT     (30U)
/*! PFD3_CLKRDY - PFD3 Clock Ready Status Flag
 *  0b0..PFD3 clock is not ready
 *  0b1..PFD3 clock is ready
 */
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD3_CLKRDY_MASK)

#define CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_MASK     (0x80000000U)
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_SHIFT    (31U)
/*! PFD3_CLKGATE - PFD3 Clock Gate
 *  0b0..PFD3 clock is not gated
 *  0b1..PFD3 clock is gated
 */
#define CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_SHIFT)) & CLKCTL0_SYSPLL0PFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name MAINPLLCLKDIV - Main PLL Clock Divider */
/*! @{ */

#define CLKCTL0_MAINPLLCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_MAINPLLCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Low Frequency Clock Divider Value */
#define CLKCTL0_MAINPLLCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_DIV_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_DIV_MASK)

#define CLKCTL0_MAINPLLCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_MAINPLLCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter */
#define CLKCTL0_MAINPLLCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_RESET_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_RESET_MASK)

#define CLKCTL0_MAINPLLCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_MAINPLLCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter */
#define CLKCTL0_MAINPLLCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_HALT_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_HALT_MASK)

#define CLKCTL0_MAINPLLCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_MAINPLLCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag */
#define CLKCTL0_MAINPLLCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_MAINPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPPLLCLKDIV - DSP PLL Clock Divider */
/*! @{ */

#define CLKCTL0_DSPPLLCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_DSPPLLCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Low Frequency Clock Divider Value */
#define CLKCTL0_DSPPLLCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_DIV_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_DIV_MASK)

#define CLKCTL0_DSPPLLCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_DSPPLLCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter */
#define CLKCTL0_DSPPLLCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_RESET_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_RESET_MASK)

#define CLKCTL0_DSPPLLCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_DSPPLLCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter */
#define CLKCTL0_DSPPLLCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_HALT_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_HALT_MASK)

#define CLKCTL0_DSPPLLCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_DSPPLLCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag */
#define CLKCTL0_DSPPLLCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPPLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DSPPLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name AUX0PLLCLKDIV - AUX0 PLL Clock Divider */
/*! @{ */

#define CLKCTL0_AUX0PLLCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_AUX0PLLCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Low Frequency Clock Divider Value */
#define CLKCTL0_AUX0PLLCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_DIV_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_DIV_MASK)

#define CLKCTL0_AUX0PLLCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_AUX0PLLCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter */
#define CLKCTL0_AUX0PLLCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_RESET_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_RESET_MASK)

#define CLKCTL0_AUX0PLLCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_AUX0PLLCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter */
#define CLKCTL0_AUX0PLLCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_HALT_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_HALT_MASK)

#define CLKCTL0_AUX0PLLCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_AUX0PLLCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag */
#define CLKCTL0_AUX0PLLCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX0PLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_AUX0PLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name AUX1PLLCLKDIV - AUX1 PLL Clock Divider */
/*! @{ */

#define CLKCTL0_AUX1PLLCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_AUX1PLLCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Low Frequency Clock Divider Value */
#define CLKCTL0_AUX1PLLCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_DIV_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_DIV_MASK)

#define CLKCTL0_AUX1PLLCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_AUX1PLLCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter */
#define CLKCTL0_AUX1PLLCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_RESET_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_RESET_MASK)

#define CLKCTL0_AUX1PLLCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_AUX1PLLCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter */
#define CLKCTL0_AUX1PLLCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_HALT_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_HALT_MASK)

#define CLKCTL0_AUX1PLLCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_AUX1PLLCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag */
#define CLKCTL0_AUX1PLLCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUX1PLLCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_AUX1PLLCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SYSCPUAHBCLKDIV - System CPU AHB Clock Divider */
/*! @{ */

#define CLKCTL0_SYSCPUAHBCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL0_SYSCPUAHBCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_SYSCPUAHBCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSCPUAHBCLKDIV_DIV_SHIFT)) & CLKCTL0_SYSCPUAHBCLKDIV_DIV_MASK)

#define CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SYSCPUAHBCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MAINCLKSELA - Main Clock Select A */
/*! @{ */

#define CLKCTL0_MAINCLKSELA_SEL_MASK             (0x3U)
#define CLKCTL0_MAINCLKSELA_SEL_SHIFT            (0U)
/*! SEL - Control Main 1st Stage Control Clock Source
 *  0b00..Low Power Oscillator Clock (LPOSC)
 *  0b01..FRODIV which is the output of the FRODIVSEL mux
 *  0b10..OSC_CLK clock
 *  0b11..FRO_DIV1 clock
 */
#define CLKCTL0_MAINCLKSELA_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKSELA_SEL_SHIFT)) & CLKCTL0_MAINCLKSELA_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELB - Main Clock Select B */
/*! @{ */

#define CLKCTL0_MAINCLKSELB_SEL_MASK             (0x3U)
#define CLKCTL0_MAINCLKSELB_SEL_SHIFT            (0U)
/*! SEL - Main Clock Source Selection
 *  0b00..MAINCLKSELA 1st Stage Clock
 *  0b01..Main System PLL Clock
 *  0b10..RTC 32 KHz Clock
 *  0b11..Reserved
 */
#define CLKCTL0_MAINCLKSELB_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKSELB_SEL_SHIFT)) & CLKCTL0_MAINCLKSELB_SEL_MASK)
/*! @} */

/*! @name PFCDIV - PFC divider 0 (trace clock)..PFC divider 1 (USB HS PHY bus clock) */
/*! @{ */

#define CLKCTL0_PFCDIV_DIV_MASK                  (0xFFU)
#define CLKCTL0_PFCDIV_DIV_SHIFT                 (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_PFCDIV_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_DIV_SHIFT)) & CLKCTL0_PFCDIV_DIV_MASK)

#define CLKCTL0_PFCDIV_RESET_MASK                (0x20000000U)
#define CLKCTL0_PFCDIV_RESET_SHIFT               (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_PFCDIV_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_RESET_SHIFT)) & CLKCTL0_PFCDIV_RESET_MASK)

#define CLKCTL0_PFCDIV_HALT_MASK                 (0x40000000U)
#define CLKCTL0_PFCDIV_HALT_SHIFT                (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_PFCDIV_HALT(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_HALT_SHIFT)) & CLKCTL0_PFCDIV_HALT_MASK)

#define CLKCTL0_PFCDIV_REQFLAG_MASK              (0x80000000U)
#define CLKCTL0_PFCDIV_REQFLAG_SHIFT             (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_PFCDIV_REQFLAG(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PFCDIV_REQFLAG_SHIFT)) & CLKCTL0_PFCDIV_REQFLAG_MASK)
/*! @} */

/*! @name FLEXSPI0FCLKSEL - FlexSPI0 Functional Clock Select */
/*! @{ */

#define CLKCTL0_FLEXSPI0FCLKSEL_SEL_MASK         (0x7U)
#define CLKCTL0_FLEXSPI0FCLKSEL_SEL_SHIFT        (0U)
/*! SEL - Select Clock Source
 *  0b000..Main Clock
 *  0b001..Main System PLL Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..FRO_DIV1 Clock
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_FLEXSPI0FCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI0FCLKSEL_SEL_SHIFT)) & CLKCTL0_FLEXSPI0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXSPI0FCLKDIV - FlexSPI0 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_FLEXSPI0FCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL0_FLEXSPI0FCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_FLEXSPI0FCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI0FCLKDIV_DIV_SHIFT)) & CLKCTL0_FLEXSPI0FCLKDIV_DIV_MASK)

#define CLKCTL0_FLEXSPI0FCLKDIV_RESET_MASK       (0x20000000U)
#define CLKCTL0_FLEXSPI0FCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_FLEXSPI0FCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI0FCLKDIV_RESET_SHIFT)) & CLKCTL0_FLEXSPI0FCLKDIV_RESET_MASK)

#define CLKCTL0_FLEXSPI0FCLKDIV_HALT_MASK        (0x40000000U)
#define CLKCTL0_FLEXSPI0FCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_FLEXSPI0FCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI0FCLKDIV_HALT_SHIFT)) & CLKCTL0_FLEXSPI0FCLKDIV_HALT_MASK)

#define CLKCTL0_FLEXSPI0FCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL0_FLEXSPI0FCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_FLEXSPI0FCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_FLEXSPI0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name FLEXSPI1FCLKSEL - FlexSPI1 Functional Clock Select */
/*! @{ */

#define CLKCTL0_FLEXSPI1FCLKSEL_SEL_MASK         (0x7U)
#define CLKCTL0_FLEXSPI1FCLKSEL_SEL_SHIFT        (0U)
/*! SEL - Select Clock Source
 *  0b000..Main Clock
 *  0b001..Main System PLL Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..FRO_DIV1 Clock
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_FLEXSPI1FCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI1FCLKSEL_SEL_SHIFT)) & CLKCTL0_FLEXSPI1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXSPI1FCLKDIV - FlexSPI1 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_FLEXSPI1FCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL0_FLEXSPI1FCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_FLEXSPI1FCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI1FCLKDIV_DIV_SHIFT)) & CLKCTL0_FLEXSPI1FCLKDIV_DIV_MASK)

#define CLKCTL0_FLEXSPI1FCLKDIV_RESET_MASK       (0x20000000U)
#define CLKCTL0_FLEXSPI1FCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_FLEXSPI1FCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI1FCLKDIV_RESET_SHIFT)) & CLKCTL0_FLEXSPI1FCLKDIV_RESET_MASK)

#define CLKCTL0_FLEXSPI1FCLKDIV_HALT_MASK        (0x40000000U)
#define CLKCTL0_FLEXSPI1FCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_FLEXSPI1FCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI1FCLKDIV_HALT_SHIFT)) & CLKCTL0_FLEXSPI1FCLKDIV_HALT_MASK)

#define CLKCTL0_FLEXSPI1FCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL0_FLEXSPI1FCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_FLEXSPI1FCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FLEXSPI1FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_FLEXSPI1FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SCTFCLKSEL - SCT Functional Clock Select */
/*! @{ */

#define CLKCTL0_SCTFCLKSEL_SEL_MASK              (0x7U)
#define CLKCTL0_SCTFCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Select Clock Source
 *  0b000..Main Clock
 *  0b001..Main System PLL Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..FRO_DIV1 Clock
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..AUDIO PLL Clock
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_SCTFCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKSEL_SEL_SHIFT)) & CLKCTL0_SCTFCLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTIN7CLKDIV - SCT Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SCTIN7CLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_SCTIN7CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_SCTIN7CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTIN7CLKDIV_DIV_SHIFT)) & CLKCTL0_SCTIN7CLKDIV_DIV_MASK)

#define CLKCTL0_SCTIN7CLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_SCTIN7CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_SCTIN7CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTIN7CLKDIV_RESET_SHIFT)) & CLKCTL0_SCTIN7CLKDIV_RESET_MASK)

#define CLKCTL0_SCTIN7CLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_SCTIN7CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_SCTIN7CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTIN7CLKDIV_HALT_SHIFT)) & CLKCTL0_SCTIN7CLKDIV_HALT_MASK)

#define CLKCTL0_SCTIN7CLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_SCTIN7CLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_SCTIN7CLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTIN7CLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SCTIN7CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name USBHSFCLKSEL - High Speed USB Functional Clock Select */
/*! @{ */

#define CLKCTL0_USBHSFCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_USBHSFCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b000..OSC_CLK Clock
 *  0b001..Main Clock
 *  0b010..Reserved
 *  0b011..AUX0_PLL_CLOCK
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_USBHSFCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKSEL_SEL_SHIFT)) & CLKCTL0_USBHSFCLKSEL_SEL_MASK)
/*! @} */

/*! @name USBHSFCLKDIV - High Speed USB Functional Clock Divider */
/*! @{ */

#define CLKCTL0_USBHSFCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_USBHSFCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_USBHSFCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_DIV_SHIFT)) & CLKCTL0_USBHSFCLKDIV_DIV_MASK)

#define CLKCTL0_USBHSFCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_USBHSFCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_USBHSFCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_RESET_SHIFT)) & CLKCTL0_USBHSFCLKDIV_RESET_MASK)

#define CLKCTL0_USBHSFCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_USBHSFCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_USBHSFCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_HALT_SHIFT)) & CLKCTL0_USBHSFCLKDIV_HALT_MASK)

#define CLKCTL0_USBHSFCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_USBHSFCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_USBHSFCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_USBHSFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_USBHSFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDIO0FCLKSEL - SDIO0 Functional Clock Select */
/*! @{ */

#define CLKCTL0_SDIO0FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_SDIO0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b000..Main Clock
 *  0b001..System PLL Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..FRO_DIV2
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_SDIO0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKSEL_SEL_SHIFT)) & CLKCTL0_SDIO0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name SDIO0FCLKDIV - SDIO0 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SDIO0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_SDIO0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_SDIO0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_DIV_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_DIV_MASK)

#define CLKCTL0_SDIO0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_SDIO0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_SDIO0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_RESET_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_RESET_MASK)

#define CLKCTL0_SDIO0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_SDIO0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_SDIO0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_HALT_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_HALT_MASK)

#define CLKCTL0_SDIO0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_SDIO0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_SDIO0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SDIO0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDIO1FCLKSEL - SDIO1 Functional Clock Select */
/*! @{ */

#define CLKCTL0_SDIO1FCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_SDIO1FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b000..Main Clock
 *  0b001..Main System PLL Clock
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..FRO_DIV2
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_SDIO1FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKSEL_SEL_SHIFT)) & CLKCTL0_SDIO1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name SDIO1FCLKDIV - SDIO1 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SDIO1FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_SDIO1FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_SDIO1FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_DIV_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_DIV_MASK)

#define CLKCTL0_SDIO1FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_SDIO1FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_SDIO1FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_RESET_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_RESET_MASK)

#define CLKCTL0_SDIO1FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_SDIO1FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_SDIO1FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_HALT_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_HALT_MASK)

#define CLKCTL0_SDIO1FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_SDIO1FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_SDIO1FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SDIO1FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SDIO1FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name ADC0FCLKSEL0 - ADC0 Functional Clock Select 0 */
/*! @{ */

#define CLKCTL0_ADC0FCLKSEL0_SEL_MASK            (0x7U)
#define CLKCTL0_ADC0FCLKSEL0_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b000..OSC_CLK Clock
 *  0b001..Low Power Oscillator Clock (LPOSC)
 *  0b010..FRO_DIV4
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_ADC0FCLKSEL0_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKSEL0_SEL_SHIFT)) & CLKCTL0_ADC0FCLKSEL0_SEL_MASK)
/*! @} */

/*! @name ADC0FCLKSEL1 - ADC0 Functional Clock Select 1 */
/*! @{ */

#define CLKCTL0_ADC0FCLKSEL1_SEL_MASK            (0x7U)
#define CLKCTL0_ADC0FCLKSEL1_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b000..ADC0FCLKSEL0 Multiplexed Output
 *  0b001..SYSPLL0 MAIN_CLK (PFD0 Output)
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..SYSPLL0 AUX1_PLL_Clock
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_ADC0FCLKSEL1_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKSEL1_SEL_SHIFT)) & CLKCTL0_ADC0FCLKSEL1_SEL_MASK)
/*! @} */

/*! @name ADC0FCLKDIV - ADC0 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_ADC0FCLKDIV_DIV_MASK             (0xFFU)
#define CLKCTL0_ADC0FCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_ADC0FCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_DIV_SHIFT)) & CLKCTL0_ADC0FCLKDIV_DIV_MASK)

#define CLKCTL0_ADC0FCLKDIV_RESET_MASK           (0x20000000U)
#define CLKCTL0_ADC0FCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_ADC0FCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_RESET_SHIFT)) & CLKCTL0_ADC0FCLKDIV_RESET_MASK)

#define CLKCTL0_ADC0FCLKDIV_HALT_MASK            (0x40000000U)
#define CLKCTL0_ADC0FCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_ADC0FCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_HALT_SHIFT)) & CLKCTL0_ADC0FCLKDIV_HALT_MASK)

#define CLKCTL0_ADC0FCLKDIV_REQFLAG_MASK         (0x80000000U)
#define CLKCTL0_ADC0FCLKDIV_REQFLAG_SHIFT        (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_ADC0FCLKDIV_REQFLAG(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ADC0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_ADC0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name UTICKFCLKSEL - UTICK Functional Clock Select */
/*! @{ */

#define CLKCTL0_UTICKFCLKSEL_SEL_MASK            (0x7U)
#define CLKCTL0_UTICKFCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b000..Low Power Oscillator Clock (LPOSC)
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_UTICKFCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICKFCLKSEL_SEL_SHIFT)) & CLKCTL0_UTICKFCLKSEL_SEL_MASK)
/*! @} */

/*! @name WDT0FCLKSEL - WDT0 Functional Clock Select */
/*! @{ */

#define CLKCTL0_WDT0FCLKSEL_SEL_MASK             (0x7U)
#define CLKCTL0_WDT0FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Select Clock Source
 *  0b000..Low Power Oscillator Clock (LPOSC)
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_WDT0FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WDT0FCLKSEL_SEL_SHIFT)) & CLKCTL0_WDT0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name A32KHZWAKECLKSEL - 32 KHz Wake Clock Source Select */
/*! @{ */

#define CLKCTL0_A32KHZWAKECLKSEL_SEL_MASK        (0x7U)
#define CLKCTL0_A32KHZWAKECLKSEL_SEL_SHIFT       (0U)
/*! SEL - Select Clock Source
 *  0b000..32 KHz
 *  0b001..Low Power Oscillator Clock (LPOSC); divided by 32 by default
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_A32KHZWAKECLKSEL_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_A32KHZWAKECLKSEL_SEL_SHIFT)) & CLKCTL0_A32KHZWAKECLKSEL_SEL_MASK)
/*! @} */

/*! @name A32KHZWAKECLKDIV - 32 KHz Wake Clock Divider */
/*! @{ */

#define CLKCTL0_A32KHZWAKECLKDIV_DIV_MASK        (0xFFU)
#define CLKCTL0_A32KHZWAKECLKDIV_DIV_SHIFT       (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_A32KHZWAKECLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_A32KHZWAKECLKDIV_DIV_SHIFT)) & CLKCTL0_A32KHZWAKECLKDIV_DIV_MASK)

#define CLKCTL0_A32KHZWAKECLKDIV_RESET_MASK      (0x20000000U)
#define CLKCTL0_A32KHZWAKECLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_A32KHZWAKECLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_A32KHZWAKECLKDIV_RESET_SHIFT)) & CLKCTL0_A32KHZWAKECLKDIV_RESET_MASK)

#define CLKCTL0_A32KHZWAKECLKDIV_HALT_MASK       (0x40000000U)
#define CLKCTL0_A32KHZWAKECLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_A32KHZWAKECLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_A32KHZWAKECLKDIV_HALT_SHIFT)) & CLKCTL0_A32KHZWAKECLKDIV_HALT_MASK)

#define CLKCTL0_A32KHZWAKECLKDIV_REQFLAG_MASK    (0x80000000U)
#define CLKCTL0_A32KHZWAKECLKDIV_REQFLAG_SHIFT   (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_A32KHZWAKECLKDIV_REQFLAG(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_A32KHZWAKECLKDIV_REQFLAG_SHIFT)) & CLKCTL0_A32KHZWAKECLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SYSTICKFCLKSEL - SYSTICK Functional Clock Select */
/*! @{ */

#define CLKCTL0_SYSTICKFCLKSEL_SEL_MASK          (0x7U)
#define CLKCTL0_SYSTICKFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - Select Clock Source
 *  0b000..Systick Divider Output Clock
 *  0b001..Low Power Oscillator Clock (LPOSC)
 *  0b010..32 KHz RTC Clock
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_SYSTICKFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKSEL_SEL_SHIFT)) & CLKCTL0_SYSTICKFCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKFCLKDIV - SYSTICK Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SYSTICKFCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL0_SYSTICKFCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_SYSTICKFCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_DIV_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_DIV_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL0_SYSTICKFCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_SYSTICKFCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_RESET_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_RESET_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL0_SYSTICKFCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_SYSTICKFCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_HALT_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_HALT_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DPHYCLKSEL - MIPI-DSI PHY Clock Select */
/*! @{ */

#define CLKCTL0_DPHYCLKSEL_SEL_MASK              (0x7U)
#define CLKCTL0_DPHYCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Select Clock Source
 *  0b000..FRO_DIV1 Clock
 *  0b001..SYSPLL0 MAIN_CLK (PFD0 Output)
 *  0b010..SYSPLL0 AUX0_PLL_Clock
 *  0b011..SYSPLL0 AUX1_PLL_Clock
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_DPHYCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYCLKSEL_SEL_SHIFT)) & CLKCTL0_DPHYCLKSEL_SEL_MASK)
/*! @} */

/*! @name DPHYCLKDIV - MIPI-DSI PHY Clock Divider */
/*! @{ */

#define CLKCTL0_DPHYCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL0_DPHYCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_DPHYCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYCLKDIV_DIV_SHIFT)) & CLKCTL0_DPHYCLKDIV_DIV_MASK)

#define CLKCTL0_DPHYCLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL0_DPHYCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_DPHYCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYCLKDIV_RESET_SHIFT)) & CLKCTL0_DPHYCLKDIV_RESET_MASK)

#define CLKCTL0_DPHYCLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL0_DPHYCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_DPHYCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYCLKDIV_HALT_SHIFT)) & CLKCTL0_DPHYCLKDIV_HALT_MASK)

#define CLKCTL0_DPHYCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL0_DPHYCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_DPHYCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DPHYCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DPHYESCCLKSEL - MIPI-DSI DPHY Escape Mode Clock Select */
/*! @{ */

#define CLKCTL0_DPHYESCCLKSEL_SEL_MASK           (0x7U)
#define CLKCTL0_DPHYESCCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Select Clock Source
 *  0b000..FRO_DIV1 clock
 *  0b001..FRO_DIV16 Clock
 *  0b010..AUX0_PLL_CLK
 *  0b011..AUX1_PLL_CLK
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_DPHYESCCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCCLKSEL_SEL_SHIFT)) & CLKCTL0_DPHYESCCLKSEL_SEL_MASK)
/*! @} */

/*! @name DPHYESCRXCLKDIV - MIPI-DSI DPHY Escape Mode Receive Clock Divider */
/*! @{ */

#define CLKCTL0_DPHYESCRXCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL0_DPHYESCRXCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_DPHYESCRXCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCRXCLKDIV_DIV_SHIFT)) & CLKCTL0_DPHYESCRXCLKDIV_DIV_MASK)

#define CLKCTL0_DPHYESCRXCLKDIV_RESET_MASK       (0x20000000U)
#define CLKCTL0_DPHYESCRXCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_DPHYESCRXCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCRXCLKDIV_RESET_SHIFT)) & CLKCTL0_DPHYESCRXCLKDIV_RESET_MASK)

#define CLKCTL0_DPHYESCRXCLKDIV_HALT_MASK        (0x40000000U)
#define CLKCTL0_DPHYESCRXCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_DPHYESCRXCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCRXCLKDIV_HALT_SHIFT)) & CLKCTL0_DPHYESCRXCLKDIV_HALT_MASK)

#define CLKCTL0_DPHYESCRXCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL0_DPHYESCRXCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_DPHYESCRXCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCRXCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DPHYESCRXCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DPHYESCTXCLKDIV - MIPI-DSI DPHY Escape Mode Tramsmit Clock Divider */
/*! @{ */

#define CLKCTL0_DPHYESCTXCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL0_DPHYESCTXCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_DPHYESCTXCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCTXCLKDIV_DIV_SHIFT)) & CLKCTL0_DPHYESCTXCLKDIV_DIV_MASK)

#define CLKCTL0_DPHYESCTXCLKDIV_RESET_MASK       (0x20000000U)
#define CLKCTL0_DPHYESCTXCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_DPHYESCTXCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCTXCLKDIV_RESET_SHIFT)) & CLKCTL0_DPHYESCTXCLKDIV_RESET_MASK)

#define CLKCTL0_DPHYESCTXCLKDIV_HALT_MASK        (0x40000000U)
#define CLKCTL0_DPHYESCTXCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_DPHYESCTXCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCTXCLKDIV_HALT_SHIFT)) & CLKCTL0_DPHYESCTXCLKDIV_HALT_MASK)

#define CLKCTL0_DPHYESCTXCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL0_DPHYESCTXCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_DPHYESCTXCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DPHYESCTXCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DPHYESCTXCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name GPUCLKSEL - GPU Clock Select */
/*! @{ */

#define CLKCTL0_GPUCLKSEL_SEL_MASK               (0x7U)
#define CLKCTL0_GPUCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Select Clock Source
 *  0b000..Main Clock
 *  0b001..FRO_DIV1 clock
 *  0b010..SYSPLL0 MAIN_CLK (PFD0 Output)
 *  0b011..SYSPLL0 AUX0_PLL_Clock
 *  0b100..SYSPLL0 AUX1_PLL_Clock
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_GPUCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_GPUCLKSEL_SEL_SHIFT)) & CLKCTL0_GPUCLKSEL_SEL_MASK)
/*! @} */

/*! @name GPUCLKDIV - GPU Clock Divider */
/*! @{ */

#define CLKCTL0_GPUCLKDIV_DIV_MASK               (0xFFU)
#define CLKCTL0_GPUCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_GPUCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_GPUCLKDIV_DIV_SHIFT)) & CLKCTL0_GPUCLKDIV_DIV_MASK)

#define CLKCTL0_GPUCLKDIV_RESET_MASK             (0x20000000U)
#define CLKCTL0_GPUCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_GPUCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_GPUCLKDIV_RESET_SHIFT)) & CLKCTL0_GPUCLKDIV_RESET_MASK)

#define CLKCTL0_GPUCLKDIV_HALT_MASK              (0x40000000U)
#define CLKCTL0_GPUCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_GPUCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_GPUCLKDIV_HALT_SHIFT)) & CLKCTL0_GPUCLKDIV_HALT_MASK)

#define CLKCTL0_GPUCLKDIV_REQFLAG_MASK           (0x80000000U)
#define CLKCTL0_GPUCLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_GPUCLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_GPUCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_GPUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DCPIXELCLKSEL - LCDIF Pixel Clock Select */
/*! @{ */

#define CLKCTL0_DCPIXELCLKSEL_SEL_MASK           (0x7U)
#define CLKCTL0_DCPIXELCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Select Clock Source
 *  0b000..MIPI-DSI PHY Clock
 *  0b001..Main Clock
 *  0b010..FRO_DIV1 Clock
 *  0b011..SYSPLL0 MAIN_CLK (PFD0 Output)
 *  0b100..SYSPLL0 AUX0_PLL_Clock
 *  0b101..SYSPLL0 AUX1_PLL_Clock
 *  0b110..Reserved
 *  0b111..None; this may be selected to reduce power when no output is needed.
 */
#define CLKCTL0_DCPIXELCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DCPIXELCLKSEL_SEL_SHIFT)) & CLKCTL0_DCPIXELCLKSEL_SEL_MASK)
/*! @} */

/*! @name DCPIXELCLKDIV - LCDIF Pixel Clock Divider */
/*! @{ */

#define CLKCTL0_DCPIXELCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_DCPIXELCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_DCPIXELCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DCPIXELCLKDIV_DIV_SHIFT)) & CLKCTL0_DCPIXELCLKDIV_DIV_MASK)

#define CLKCTL0_DCPIXELCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_DCPIXELCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_DCPIXELCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DCPIXELCLKDIV_RESET_SHIFT)) & CLKCTL0_DCPIXELCLKDIV_RESET_MASK)

#define CLKCTL0_DCPIXELCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_DCPIXELCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt the Divider Counter
 *  0b0..No effect
 *  0b1..Halt (stop) the Divider Counter
 */
#define CLKCTL0_DCPIXELCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DCPIXELCLKDIV_HALT_SHIFT)) & CLKCTL0_DCPIXELCLKDIV_HALT_MASK)

#define CLKCTL0_DCPIXELCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_DCPIXELCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag
 *  0b0..The change to the divider value has finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL0_DCPIXELCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DCPIXELCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DCPIXELCLKDIV_REQFLAG_MASK)
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

