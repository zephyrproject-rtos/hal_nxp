/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CLKCTL2
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CLKCTL2.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL2
 *
 * CMSIS Peripheral Access Layer for CLKCTL2
 */

#if !defined(PERI_CLKCTL2_H_)
#define PERI_CLKCTL2_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- CLKCTL2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL2_Peripheral_Access_Layer CLKCTL2 Peripheral Access Layer
 * @{
 */

/** CLKCTL2 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0;                           /**< VDDN_COM Peripheral clock 0, offset: 0x10 */
       uint8_t RESERVED_1[44];
  __IO uint32_t PSCCTL0_SET;                       /**< VDDN_COM Peripheral Clock 0 Set, offset: 0x40 */
       uint8_t RESERVED_2[44];
  __IO uint32_t PSCCTL0_CLR;                       /**< VDDN_COM Peripheral Clock 0 Clear, offset: 0x70 */
       uint8_t RESERVED_3[48];
  __IO uint32_t COMMONVDDNCLKSEL;                  /**< VDDN_COM Clock Source Select, offset: 0xA4 */
       uint8_t RESERVED_4[4];
  __IO uint32_t COMMONVDDNCLKDIV;                  /**< VDDN_COM Clock Divider, offset: 0xAC */
       uint8_t RESERVED_5[80];
  __IO uint32_t SYSOSCCTL0;                        /**< XTAL Oscillator Control 0, offset: 0x100 */
       uint8_t RESERVED_6[4];
  __IO uint32_t SYSOSCBYPASS;                      /**< OSC Bypass Clock Source Select, offset: 0x108 */
  __IO uint32_t USBCLKSRC24MCLKSEL;                /**< USB0 Clock Source Select, offset: 0x10C */
  __IO uint32_t COMNBASECLKSEL;                    /**< VDDN_COM Base Clock Source Select, offset: 0x110 */
       uint8_t RESERVED_7[8];
  __IO uint32_t EUSBCLKSRC24MCLKSEL;               /**< USB1 (eUSB) Clock Source Select, offset: 0x11C */
       uint8_t RESERVED_8[224];
  __IO uint32_t MAINPLL0CLKSEL;                    /**< Main PLL0 Clock Source Select, offset: 0x200 */
  __IO uint32_t MAINPLL0CTL0;                      /**< Main PLL0 Control 0, offset: 0x204 */
       uint8_t RESERVED_9[4];
  __IO uint32_t MAINPLL0LOCKTIMEDIV2;              /**< Main PLL0 Lock Time Div2, offset: 0x20C */
  __IO uint32_t MAINPLL0NUM;                       /**< Main PLL0 Numerator, offset: 0x210 */
  __IO uint32_t MAINPLL0DENOM;                     /**< Main PLL0 Denominator, offset: 0x214 */
  __IO uint32_t MAINPLL0PFD;                       /**< Main PLL0 PFD, offset: 0x218 */
       uint8_t RESERVED_10[4];
  __IO uint32_t MAINPLL0PFDDOMAINEN;               /**< Main PLL0 PFD Clock Domain Enable, offset: 0x220 */
       uint8_t RESERVED_11[476];
  __IO uint32_t AUDIOPLL0CLKSEL;                   /**< Audio PLL0 Clock Source Select, offset: 0x400 */
  __IO uint32_t AUDIOPLL0CTL0;                     /**< Audio PLL0 Control 0, offset: 0x404 */
       uint8_t RESERVED_12[4];
  __IO uint32_t AUDIOPLL0LOCKTIMEDIV2;             /**< Audio PLL0 Lock Time Divide-by-2, offset: 0x40C */
  __IO uint32_t AUDIOPLL0NUM;                      /**< Audio PLL0 Numerator, offset: 0x410 */
  __IO uint32_t AUDIOPLL0DENOM;                    /**< Audio PLL0 Denominator, offset: 0x414 */
  __IO uint32_t AUDIOPLL0PFD;                      /**< Audio PLL0 PFD, offset: 0x418 */
       uint8_t RESERVED_13[4];
  __IO uint32_t AUDIOPLL0PFDDOMAINEN;              /**< Audio PLL0 PFD Clock Enable, offset: 0x420 */
  __IO uint32_t AUDIOPLL0VCODOMAINEN;              /**< Audio PLL0 VCO Clock Enable, offset: 0x424 */
       uint8_t RESERVED_14[472];
  __IO uint32_t CKIL_32K_GATE;                     /**< CKIL 32kHz Clock Gate, offset: 0x600 */
} CLKCTL2_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL2_Register_Masks CLKCTL2 Register Masks
 * @{
 */

/*! @name PSCCTL0 - VDDN_COM Peripheral clock 0 */
/*! @{ */

#define CLKCTL2_PSCCTL0_SYSCON2_MASK             (0x8U)
#define CLKCTL2_PSCCTL0_SYSCON2_SHIFT            (3U)
/*! SYSCON2 - SYSCON2 clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_PSCCTL0_SYSCON2(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL2_PSCCTL0_SYSCON2_SHIFT)) & CLKCTL2_PSCCTL0_SYSCON2_MASK)

#define CLKCTL2_PSCCTL0_IOPCTL2_MASK             (0x10U)
#define CLKCTL2_PSCCTL0_IOPCTL2_SHIFT            (4U)
/*! IOPCTL2 - IOPCTL2 clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_PSCCTL0_IOPCTL2(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL2_PSCCTL0_IOPCTL2_SHIFT)) & CLKCTL2_PSCCTL0_IOPCTL2_MASK)
/*! @} */

/*! @name PSCCTL0_SET - VDDN_COM Peripheral Clock 0 Set */
/*! @{ */

#define CLKCTL2_PSCCTL0_SET_SYSCON2_MASK         (0x8U)
#define CLKCTL2_PSCCTL0_SET_SYSCON2_SHIFT        (3U)
/*! SYSCON2 - SYSCON2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL2_PSCCTL0_SET_SYSCON2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_PSCCTL0_SET_SYSCON2_SHIFT)) & CLKCTL2_PSCCTL0_SET_SYSCON2_MASK)

#define CLKCTL2_PSCCTL0_SET_IOPCTL2_MASK         (0x10U)
#define CLKCTL2_PSCCTL0_SET_IOPCTL2_SHIFT        (4U)
/*! IOPCTL2 - IOPCTL2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL2_PSCCTL0_SET_IOPCTL2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_PSCCTL0_SET_IOPCTL2_SHIFT)) & CLKCTL2_PSCCTL0_SET_IOPCTL2_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - VDDN_COM Peripheral Clock 0 Clear */
/*! @{ */

#define CLKCTL2_PSCCTL0_CLR_SYSCON2_MASK         (0x8U)
#define CLKCTL2_PSCCTL0_CLR_SYSCON2_SHIFT        (3U)
/*! SYSCON2 - SYSCON2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL2_PSCCTL0_CLR_SYSCON2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_PSCCTL0_CLR_SYSCON2_SHIFT)) & CLKCTL2_PSCCTL0_CLR_SYSCON2_MASK)

#define CLKCTL2_PSCCTL0_CLR_IOPCTL2_MASK         (0x10U)
#define CLKCTL2_PSCCTL0_CLR_IOPCTL2_SHIFT        (4U)
/*! IOPCTL2 - IOPCTL2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL2_PSCCTL0_CLR_IOPCTL2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_PSCCTL0_CLR_IOPCTL2_SHIFT)) & CLKCTL2_PSCCTL0_CLR_IOPCTL2_MASK)
/*! @} */

/*! @name COMMONVDDNCLKSEL - VDDN_COM Clock Source Select */
/*! @{ */

#define CLKCTL2_COMMONVDDNCLKSEL_SEL_MASK        (0x3U)
#define CLKCTL2_COMMONVDDNCLKSEL_SEL_SHIFT       (0U)
/*! SEL - VDDN_COM Clock Source Select
 *  0b00..baseclk_comn
 *  0b01..main_pll_pfd3
 *  0b10..fro1_max
 *  0b11..osc_clk
 */
#define CLKCTL2_COMMONVDDNCLKSEL_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL2_COMMONVDDNCLKSEL_SEL_SHIFT)) & CLKCTL2_COMMONVDDNCLKSEL_SEL_MASK)
/*! @} */

/*! @name COMMONVDDNCLKDIV - VDDN_COM Clock Divider */
/*! @{ */

#define CLKCTL2_COMMONVDDNCLKDIV_DIV_MASK        (0xFFU)
#define CLKCTL2_COMMONVDDNCLKDIV_DIV_SHIFT       (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL2_COMMONVDDNCLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL2_COMMONVDDNCLKDIV_DIV_SHIFT)) & CLKCTL2_COMMONVDDNCLKDIV_DIV_MASK)

#define CLKCTL2_COMMONVDDNCLKDIV_BUSY_MASK       (0x10000000U)
#define CLKCTL2_COMMONVDDNCLKDIV_BUSY_SHIFT      (28U)
/*! BUSY - Busy Flag
 *  0b0..The clkout is outputed with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL2_COMMONVDDNCLKDIV_BUSY(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL2_COMMONVDDNCLKDIV_BUSY_SHIFT)) & CLKCTL2_COMMONVDDNCLKDIV_BUSY_MASK)

#define CLKCTL2_COMMONVDDNCLKDIV_REQFLAG_MASK    (0x80000000U)
#define CLKCTL2_COMMONVDDNCLKDIV_REQFLAG_SHIFT   (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL2_COMMONVDDNCLKDIV_REQFLAG(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_COMMONVDDNCLKDIV_REQFLAG_SHIFT)) & CLKCTL2_COMMONVDDNCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SYSOSCCTL0 - XTAL Oscillator Control 0 */
/*! @{ */

#define CLKCTL2_SYSOSCCTL0_LP_ENABLE_MASK        (0x1U)
#define CLKCTL2_SYSOSCCTL0_LP_ENABLE_SHIFT       (0U)
/*! LP_ENABLE - Low Power Mode Enable
 *  0b0..Enables High Gain mode (HP)
 *  0b1..Enables Low Power mode (LP)
 */
#define CLKCTL2_SYSOSCCTL0_LP_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL2_SYSOSCCTL0_LP_ENABLE_SHIFT)) & CLKCTL2_SYSOSCCTL0_LP_ENABLE_MASK)

#define CLKCTL2_SYSOSCCTL0_BYPASS_ENABLE_MASK    (0x2U)
#define CLKCTL2_SYSOSCCTL0_BYPASS_ENABLE_SHIFT   (1U)
/*! BYPASS_ENABLE - Bypass Enable
 *  0b0..Enables normal mode.
 *  0b1..Enables bypass mode. In this mode a clock can be directly inputted into the XTALIN pin.
 */
#define CLKCTL2_SYSOSCCTL0_BYPASS_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_SYSOSCCTL0_BYPASS_ENABLE_SHIFT)) & CLKCTL2_SYSOSCCTL0_BYPASS_ENABLE_MASK)
/*! @} */

/*! @name SYSOSCBYPASS - OSC Bypass Clock Source Select */
/*! @{ */

#define CLKCTL2_SYSOSCBYPASS_SEL_MASK            (0x3U)
#define CLKCTL2_SYSOSCBYPASS_SEL_SHIFT           (0U)
/*! SEL - SYSOSC Bypass Clock Select Source
 *  0b00..osc_out
 *  0b01..CLKIN
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL2_SYSOSCBYPASS_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL2_SYSOSCBYPASS_SEL_SHIFT)) & CLKCTL2_SYSOSCBYPASS_SEL_MASK)
/*! @} */

/*! @name USBCLKSRC24MCLKSEL - USB0 Clock Source Select */
/*! @{ */

#define CLKCTL2_USBCLKSRC24MCLKSEL_SEL_MASK      (0x3U)
#define CLKCTL2_USBCLKSRC24MCLKSEL_SEL_SHIFT     (0U)
/*! SEL - USB0 24M Input Clock Select Source
 *  0b00..osc_clk
 *  0b01..fro_div8
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL2_USBCLKSRC24MCLKSEL_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL2_USBCLKSRC24MCLKSEL_SEL_SHIFT)) & CLKCTL2_USBCLKSRC24MCLKSEL_SEL_MASK)
/*! @} */

/*! @name COMNBASECLKSEL - VDDN_COM Base Clock Source Select */
/*! @{ */

#define CLKCTL2_COMNBASECLKSEL_SEL_MASK          (0x3U)
#define CLKCTL2_COMNBASECLKSEL_SEL_SHIFT         (0U)
/*! SEL - Common Base Clock Source Select
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro0_div3
 *  0b11..1m_lposc
 */
#define CLKCTL2_COMNBASECLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL2_COMNBASECLKSEL_SEL_SHIFT)) & CLKCTL2_COMNBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name EUSBCLKSRC24MCLKSEL - USB1 (eUSB) Clock Source Select */
/*! @{ */

#define CLKCTL2_EUSBCLKSRC24MCLKSEL_SEL_MASK     (0x3U)
#define CLKCTL2_EUSBCLKSRC24MCLKSEL_SEL_SHIFT    (0U)
/*! SEL - 24M USB1 (eUSB) Input Clock Source
 *  0b00..osc_clk
 *  0b01..fro1_div8
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL2_EUSBCLKSRC24MCLKSEL_SEL(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL2_EUSBCLKSRC24MCLKSEL_SEL_SHIFT)) & CLKCTL2_EUSBCLKSRC24MCLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINPLL0CLKSEL - Main PLL0 Clock Source Select */
/*! @{ */

#define CLKCTL2_MAINPLL0CLKSEL_SEL_MASK          (0x3U)
#define CLKCTL2_MAINPLL0CLKSEL_SEL_SHIFT         (0U)
/*! SEL - Main PLL0 Clock Select Source
 *  0b00..fro1_div8
 *  0b01..osc_clk
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL2_MAINPLL0CLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0CLKSEL_SEL_SHIFT)) & CLKCTL2_MAINPLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINPLL0CTL0 - Main PLL0 Control 0 */
/*! @{ */

#define CLKCTL2_MAINPLL0CTL0_BYPASS_MASK         (0x1U)
#define CLKCTL2_MAINPLL0CTL0_BYPASS_SHIFT        (0U)
/*! BYPASS - MAINPLL0 BYPASS
 *  0b0..PFD outputs are PFD-programmed clocks.
 *  0b1..Bypass mode: PFD outputs are sourced directly from the reference input clock.
 */
#define CLKCTL2_MAINPLL0CTL0_BYPASS(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0CTL0_BYPASS_SHIFT)) & CLKCTL2_MAINPLL0CTL0_BYPASS_MASK)

#define CLKCTL2_MAINPLL0CTL0_RESET_MASK          (0x2U)
#define CLKCTL2_MAINPLL0CTL0_RESET_SHIFT         (1U)
/*! RESET - MAINPLL0 Reset
 *  0b0..MAINPLL0 reset is removed.
 *  0b1..MAINPLL0 is placed into reset.
 */
#define CLKCTL2_MAINPLL0CTL0_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0CTL0_RESET_SHIFT)) & CLKCTL2_MAINPLL0CTL0_RESET_MASK)

#define CLKCTL2_MAINPLL0CTL0_HOLD_RING_OFF_ENA_MASK (0x2000U)
#define CLKCTL2_MAINPLL0CTL0_HOLD_RING_OFF_ENA_SHIFT (13U)
/*! HOLD_RING_OFF_ENA - Hold Ring Off Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0CTL0_HOLD_RING_OFF_ENA(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0CTL0_HOLD_RING_OFF_ENA_SHIFT)) & CLKCTL2_MAINPLL0CTL0_HOLD_RING_OFF_ENA_MASK)

#define CLKCTL2_MAINPLL0CTL0_MULT_MASK           (0xFF0000U)
#define CLKCTL2_MAINPLL0CTL0_MULT_SHIFT          (16U)
/*! MULT - Multiplication Factor
 *  0b00010000..Divide by 16
 *  0b00010001..Divided by 17
 *  0b00010010..Divided by 18
 *  0b00010011..Divided by 19
 *  0b00010100..Divided by 20
 *  0b00010101..Divided by 21
 *  0b00010110..Divided by 22
 */
#define CLKCTL2_MAINPLL0CTL0_MULT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0CTL0_MULT_SHIFT)) & CLKCTL2_MAINPLL0CTL0_MULT_MASK)
/*! @} */

/*! @name MAINPLL0LOCKTIMEDIV2 - Main PLL0 Lock Time Div2 */
/*! @{ */

#define CLKCTL2_MAINPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define CLKCTL2_MAINPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - MAINPLL0 Lock Time Divide-by-2 */
#define CLKCTL2_MAINPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & CLKCTL2_MAINPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name MAINPLL0NUM - Main PLL0 Numerator */
/*! @{ */

#define CLKCTL2_MAINPLL0NUM_NUM_MASK             (0x3FFFFFFFU)
#define CLKCTL2_MAINPLL0NUM_NUM_SHIFT            (0U)
/*! NUM - Numerator */
#define CLKCTL2_MAINPLL0NUM_NUM(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0NUM_NUM_SHIFT)) & CLKCTL2_MAINPLL0NUM_NUM_MASK)
/*! @} */

/*! @name MAINPLL0DENOM - Main PLL0 Denominator */
/*! @{ */

#define CLKCTL2_MAINPLL0DENOM_DENOM_MASK         (0x3FFFFFFFU)
#define CLKCTL2_MAINPLL0DENOM_DENOM_SHIFT        (0U)
/*! DENOM - Denominator */
#define CLKCTL2_MAINPLL0DENOM_DENOM(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0DENOM_DENOM_SHIFT)) & CLKCTL2_MAINPLL0DENOM_DENOM_MASK)
/*! @} */

/*! @name MAINPLL0PFD - Main PLL0 PFD */
/*! @{ */

#define CLKCTL2_MAINPLL0PFD_PFD0_MASK            (0x3FU)
#define CLKCTL2_MAINPLL0PFD_PFD0_SHIFT           (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CLKCTL2_MAINPLL0PFD_PFD0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD0_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD0_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD0_CLKRDY_MASK     (0x40U)
#define CLKCTL2_MAINPLL0PFD_PFD0_CLKRDY_SHIFT    (6U)
/*! PFD0_CLKRDY - PFD0 Clock Ready
 *  0b0..PFD0 clock is not ready.
 *  0b1..PFD0 clock is ready.
 */
#define CLKCTL2_MAINPLL0PFD_PFD0_CLKRDY(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD0_CLKRDY_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD0_CLKRDY_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD0_CLKGATE_MASK    (0x80U)
#define CLKCTL2_MAINPLL0PFD_PFD0_CLKGATE_SHIFT   (7U)
/*! PFD0_CLKGATE - PFD0 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFD_PFD0_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD0_CLKGATE_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD0_CLKGATE_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD1_MASK            (0x3F00U)
#define CLKCTL2_MAINPLL0PFD_PFD1_SHIFT           (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CLKCTL2_MAINPLL0PFD_PFD1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD1_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD1_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD1_CLKRDY_MASK     (0x4000U)
#define CLKCTL2_MAINPLL0PFD_PFD1_CLKRDY_SHIFT    (14U)
/*! PFD1_CLKRDY - PFD1 Clock Ready
 *  0b0..PFD1 clock is not ready.
 *  0b1..PFD1 clock is ready.
 */
#define CLKCTL2_MAINPLL0PFD_PFD1_CLKRDY(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD1_CLKRDY_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD1_CLKRDY_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD1_CLKGATE_MASK    (0x8000U)
#define CLKCTL2_MAINPLL0PFD_PFD1_CLKGATE_SHIFT   (15U)
/*! PFD1_CLKGATE - PFD1 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFD_PFD1_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD1_CLKGATE_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD1_CLKGATE_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD2_MASK            (0x3F0000U)
#define CLKCTL2_MAINPLL0PFD_PFD2_SHIFT           (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CLKCTL2_MAINPLL0PFD_PFD2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD2_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD2_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD2_CLKRDY_MASK     (0x400000U)
#define CLKCTL2_MAINPLL0PFD_PFD2_CLKRDY_SHIFT    (22U)
/*! PFD2_CLKRDY - PFD2 Clock Ready
 *  0b0..PFD2 clock is not ready.
 *  0b1..PFD2 clock is ready.
 */
#define CLKCTL2_MAINPLL0PFD_PFD2_CLKRDY(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD2_CLKRDY_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD2_CLKRDY_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD2_CLKGATE_MASK    (0x800000U)
#define CLKCTL2_MAINPLL0PFD_PFD2_CLKGATE_SHIFT   (23U)
/*! PFD2_CLKGATE - PFD2 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFD_PFD2_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD2_CLKGATE_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD2_CLKGATE_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD3_MASK            (0x3F000000U)
#define CLKCTL2_MAINPLL0PFD_PFD3_SHIFT           (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CLKCTL2_MAINPLL0PFD_PFD3(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD3_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD3_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD3_CLKRDY_MASK     (0x40000000U)
#define CLKCTL2_MAINPLL0PFD_PFD3_CLKRDY_SHIFT    (30U)
/*! PFD3_CLKRDY - PFD3 Clock Ready
 *  0b0..PFD3 clock is not ready.
 *  0b1..PFD3 clock is ready.
 */
#define CLKCTL2_MAINPLL0PFD_PFD3_CLKRDY(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD3_CLKRDY_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD3_CLKRDY_MASK)

#define CLKCTL2_MAINPLL0PFD_PFD3_CLKGATE_MASK    (0x80000000U)
#define CLKCTL2_MAINPLL0PFD_PFD3_CLKGATE_SHIFT   (31U)
/*! PFD3_CLKGATE - PFD3 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFD_PFD3_CLKGATE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFD_PFD3_CLKGATE_SHIFT)) & CLKCTL2_MAINPLL0PFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name MAINPLL0PFDDOMAINEN - Main PLL0 PFD Clock Domain Enable */
/*! @{ */

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_CMPT_MASK (0x1U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_CMPT_SHIFT (0U)
/*! PFD0_OF_CMPT - PFD0 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_CMPT_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_CMPT_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_MASK (0x2U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_SHIFT (1U)
/*! PFD0_OF_VDD1_SENSE - PFD0 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_MASK (0x4U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_SHIFT (2U)
/*! PFD0_OF_VDD2_DSP - PFD0 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MD2_MASK (0x8U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MD2_SHIFT (3U)
/*! PFD0_OF_MD2 - PFD0 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MD2_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MD2_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MDN_MASK (0x10U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MDN_SHIFT (4U)
/*! PFD0_OF_MDN - PFD0 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MDN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_MDN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_MASK (0x20U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_SHIFT (5U)
/*! PFD0_OF_VDD2_COM - PFD0 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_COMN_MASK (0x40U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_COMN_SHIFT (6U)
/*! PFD0_OF_COMN - PFD0 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_COMN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD0_OF_COMN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_CMPT_MASK (0x100U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_CMPT_SHIFT (8U)
/*! PFD1_OF_CMPT - PFD1 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_CMPT_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_CMPT_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_MASK (0x200U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_SHIFT (9U)
/*! PFD1_OF_VDD1_SENSE - PFD1 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_MASK (0x400U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_SHIFT (10U)
/*! PFD1_OF_VDD2_DSP - PFD1 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MD2_MASK (0x800U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MD2_SHIFT (11U)
/*! PFD1_OF_MD2 - PFD1 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MD2_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MD2_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MDN_MASK (0x1000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MDN_SHIFT (12U)
/*! PFD1_OF_MDN - PFD1 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MDN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_MDN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_MASK (0x2000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_SHIFT (13U)
/*! PFD1_OF_VDD2_COM - PFD1 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_COMN_MASK (0x4000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_COMN_SHIFT (14U)
/*! PFD1_OF_COMN - PFD1 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_COMN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD1_OF_COMN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_CMPT_MASK (0x10000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_CMPT_SHIFT (16U)
/*! PFD2_OF_CMPT - PFD2 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_CMPT_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_CMPT_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_MASK (0x20000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_SHIFT (17U)
/*! PFD2_OF_VDD1_SENSE - PFD2 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_MASK (0x40000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_SHIFT (18U)
/*! PFD2_OF_VDD2_DSP - PFD2 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MD2_MASK (0x80000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MD2_SHIFT (19U)
/*! PFD2_OF_MD2 - PFD2 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MD2_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MD2_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MDN_MASK (0x100000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MDN_SHIFT (20U)
/*! PFD2_OF_MDN - PFD2 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MDN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_MDN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_MASK (0x200000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_SHIFT (21U)
/*! PFD2_OF_VDD2_COM - PFD2 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_COMN_MASK (0x400000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_COMN_SHIFT (22U)
/*! PFD2_OF_COMN - PFD2 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_COMN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD2_OF_COMN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_CMPT_MASK (0x1000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_CMPT_SHIFT (24U)
/*! PFD3_OF_CMPT - PFD3 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_CMPT_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_CMPT_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_MASK (0x2000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_SHIFT (25U)
/*! PFD3_OF_VDD1_SENSE - PFD3 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_MASK (0x4000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_SHIFT (26U)
/*! PFD3_OF_VDD2_DSP - PFD3 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MD2_MASK (0x8000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MD2_SHIFT (27U)
/*! PFD3_OF_MD2 - PFD3 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MD2_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MD2_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MDN_MASK (0x10000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MDN_SHIFT (28U)
/*! PFD3_OF_MDN - PFD3 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MDN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_MDN_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_MASK (0x20000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_SHIFT (29U)
/*! PFD3_OF_VDD2_COM - PFD3 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_MASK)

#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_COMN_MASK (0x40000000U)
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_COMN_SHIFT (30U)
/*! PFD3_OF_COMN - PFD3 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_COMN_SHIFT)) & CLKCTL2_MAINPLL0PFDDOMAINEN_PFD3_OF_COMN_MASK)
/*! @} */

/*! @name AUDIOPLL0CLKSEL - Audio PLL0 Clock Source Select */
/*! @{ */

#define CLKCTL2_AUDIOPLL0CLKSEL_SEL_MASK         (0x3U)
#define CLKCTL2_AUDIOPLL0CLKSEL_SEL_SHIFT        (0U)
/*! SEL - Audio PLL0 Clock Source Select
 *  0b00..fro1_div8
 *  0b01..osc_clk (User-Selectable)
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL2_AUDIOPLL0CLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0CLKSEL_SEL_SHIFT)) & CLKCTL2_AUDIOPLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDIOPLL0CTL0 - Audio PLL0 Control 0 */
/*! @{ */

#define CLKCTL2_AUDIOPLL0CTL0_BYPASS_MASK        (0x1U)
#define CLKCTL2_AUDIOPLL0CTL0_BYPASS_SHIFT       (0U)
/*! BYPASS - Bypass Mode
 *  0b0..PFD outputs are PFD-programmed clocks.
 *  0b1..Bypass mode. PFD outputs are sourced directly from the reference input clock.
 */
#define CLKCTL2_AUDIOPLL0CTL0_BYPASS(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0CTL0_BYPASS_SHIFT)) & CLKCTL2_AUDIOPLL0CTL0_BYPASS_MASK)

#define CLKCTL2_AUDIOPLL0CTL0_RESET_MASK         (0x2U)
#define CLKCTL2_AUDIOPLL0CTL0_RESET_SHIFT        (1U)
/*! RESET - AUDIOPLL0 Reset
 *  0b0..Audio PLL0 reset is removed.
 *  0b1..Audio PLL0 is placed into reset.
 */
#define CLKCTL2_AUDIOPLL0CTL0_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0CTL0_RESET_SHIFT)) & CLKCTL2_AUDIOPLL0CTL0_RESET_MASK)

#define CLKCTL2_AUDIOPLL0CTL0_HOLD_RING_OFF_ENA_MASK (0x2000U)
#define CLKCTL2_AUDIOPLL0CTL0_HOLD_RING_OFF_ENA_SHIFT (13U)
/*! HOLD_RING_OFF_ENA - Hold Ring Off Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0CTL0_HOLD_RING_OFF_ENA(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0CTL0_HOLD_RING_OFF_ENA_SHIFT)) & CLKCTL2_AUDIOPLL0CTL0_HOLD_RING_OFF_ENA_MASK)

#define CLKCTL2_AUDIOPLL0CTL0_MULT_MASK          (0xFF0000U)
#define CLKCTL2_AUDIOPLL0CTL0_MULT_SHIFT         (16U)
/*! MULT - Multiplication Factor
 *  0b00010000..Divided by 16
 *  0b00010001..Divided by 17
 *  0b00010010..Divided by 18
 *  0b00010011..Divided by 19
 *  0b00010100..Divided by 20
 *  0b00010101..Divided by 21
 *  0b00010110..Divided by 22
 */
#define CLKCTL2_AUDIOPLL0CTL0_MULT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0CTL0_MULT_SHIFT)) & CLKCTL2_AUDIOPLL0CTL0_MULT_MASK)

#define CLKCTL2_AUDIOPLL0CTL0_VCO_OUT_ENABLE_MASK (0x1000000U)
#define CLKCTL2_AUDIOPLL0CTL0_VCO_OUT_ENABLE_SHIFT (24U)
/*! VCO_OUT_ENABLE - VCO Output Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0CTL0_VCO_OUT_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0CTL0_VCO_OUT_ENABLE_SHIFT)) & CLKCTL2_AUDIOPLL0CTL0_VCO_OUT_ENABLE_MASK)
/*! @} */

/*! @name AUDIOPLL0LOCKTIMEDIV2 - Audio PLL0 Lock Time Divide-by-2 */
/*! @{ */

#define CLKCTL2_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define CLKCTL2_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - AUDIOPLL0 Lock Time Divide-by-2 */
#define CLKCTL2_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & CLKCTL2_AUDIOPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name AUDIOPLL0NUM - Audio PLL0 Numerator */
/*! @{ */

#define CLKCTL2_AUDIOPLL0NUM_NUM_MASK            (0x3FFFFFFFU)
#define CLKCTL2_AUDIOPLL0NUM_NUM_SHIFT           (0U)
/*! NUM - Numerator */
#define CLKCTL2_AUDIOPLL0NUM_NUM(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0NUM_NUM_SHIFT)) & CLKCTL2_AUDIOPLL0NUM_NUM_MASK)
/*! @} */

/*! @name AUDIOPLL0DENOM - Audio PLL0 Denominator */
/*! @{ */

#define CLKCTL2_AUDIOPLL0DENOM_DENOM_MASK        (0x3FFFFFFFU)
#define CLKCTL2_AUDIOPLL0DENOM_DENOM_SHIFT       (0U)
/*! DENOM - Denominator */
#define CLKCTL2_AUDIOPLL0DENOM_DENOM(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0DENOM_DENOM_SHIFT)) & CLKCTL2_AUDIOPLL0DENOM_DENOM_MASK)
/*! @} */

/*! @name AUDIOPLL0PFD - Audio PLL0 PFD */
/*! @{ */

#define CLKCTL2_AUDIOPLL0PFD_PFD0_MASK           (0x3FU)
#define CLKCTL2_AUDIOPLL0PFD_PFD0_SHIFT          (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define CLKCTL2_AUDIOPLL0PFD_PFD0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD0_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD0_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD0_CLKRDY_MASK    (0x40U)
#define CLKCTL2_AUDIOPLL0PFD_PFD0_CLKRDY_SHIFT   (6U)
/*! PFD0_CLKRDY - PFD0 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD0_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD0_CLKRDY_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD0_CLKRDY_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD0_CLKGATE_MASK   (0x80U)
#define CLKCTL2_AUDIOPLL0PFD_PFD0_CLKGATE_SHIFT  (7U)
/*! PFD0_CLKGATE - PFD0 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD0_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD0_CLKGATE_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD0_CLKGATE_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD1_MASK           (0x3F00U)
#define CLKCTL2_AUDIOPLL0PFD_PFD1_SHIFT          (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define CLKCTL2_AUDIOPLL0PFD_PFD1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD1_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD1_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD1_CLKRDY_MASK    (0x4000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD1_CLKRDY_SHIFT   (14U)
/*! PFD1_CLKRDY - PFD1 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD1_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD1_CLKRDY_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD1_CLKRDY_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD1_CLKGATE_MASK   (0x8000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD1_CLKGATE_SHIFT  (15U)
/*! PFD1_CLKGATE - PFD1 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD1_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD1_CLKGATE_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD1_CLKGATE_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD2_MASK           (0x3F0000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD2_SHIFT          (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define CLKCTL2_AUDIOPLL0PFD_PFD2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD2_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD2_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD2_CLKRDY_MASK    (0x400000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD2_CLKRDY_SHIFT   (22U)
/*! PFD2_CLKRDY - PFD2 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD2_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD2_CLKRDY_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD2_CLKRDY_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD2_CLKGATE_MASK   (0x800000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD2_CLKGATE_SHIFT  (23U)
/*! PFD2_CLKGATE - PFD2 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD2_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD2_CLKGATE_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD2_CLKGATE_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD3_MASK           (0x3F000000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD3_SHIFT          (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define CLKCTL2_AUDIOPLL0PFD_PFD3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD3_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD3_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD3_CLKRDY_MASK    (0x40000000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD3_CLKRDY_SHIFT   (30U)
/*! PFD3_CLKRDY - PFD3 Clock Ready Status Flag
 *  0b0..Not ready
 *  0b1..Ready
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD3_CLKRDY(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD3_CLKRDY_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD3_CLKRDY_MASK)

#define CLKCTL2_AUDIOPLL0PFD_PFD3_CLKGATE_MASK   (0x80000000U)
#define CLKCTL2_AUDIOPLL0PFD_PFD3_CLKGATE_SHIFT  (31U)
/*! PFD3_CLKGATE - PFD3 Clock Gate
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFD_PFD3_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFD_PFD3_CLKGATE_SHIFT)) & CLKCTL2_AUDIOPLL0PFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name AUDIOPLL0PFDDOMAINEN - Audio PLL0 PFD Clock Enable */
/*! @{ */

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_CMPT_MASK (0x1U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_CMPT_SHIFT (0U)
/*! PFD0_OF_CMPT - PFD0 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_CMPT_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_CMPT_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_MASK (0x2U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_SHIFT (1U)
/*! PFD0_OF_VDD1_SENSE - PFD0 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD1_SENSE_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_MASK (0x4U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_SHIFT (2U)
/*! PFD0_OF_VDD2_DSP - PFD0 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_DSP_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MD2_MASK (0x8U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MD2_SHIFT (3U)
/*! PFD0_OF_MD2 - PFD0 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MD2_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MD2_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MDN_MASK (0x10U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MDN_SHIFT (4U)
/*! PFD0_OF_MDN - PFD0 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MDN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_MDN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_MASK (0x20U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_SHIFT (5U)
/*! PFD0_OF_VDD2_COM - PFD0 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_VDD2_COM_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_COMN_MASK (0x40U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_COMN_SHIFT (6U)
/*! PFD0_OF_COMN - PFD0 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_COMN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD0_OF_COMN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_CMPT_MASK (0x100U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_CMPT_SHIFT (8U)
/*! PFD1_OF_CMPT - PFD1 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_CMPT_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_CMPT_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_MASK (0x200U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_SHIFT (9U)
/*! PFD1_OF_VDD1_SENSE - PFD1 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD1_SENSE_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_MASK (0x400U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_SHIFT (10U)
/*! PFD1_OF_VDD2_DSP - PFD1 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_DSP_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MD2_MASK (0x800U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MD2_SHIFT (11U)
/*! PFD1_OF_MD2 - PFD1 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MD2_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MD2_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MDN_MASK (0x1000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MDN_SHIFT (12U)
/*! PFD1_OF_MDN - PFD1 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MDN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_MDN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_MASK (0x2000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_SHIFT (13U)
/*! PFD1_OF_VDD2_COM - PFD1 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_VDD2_COM_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_COMN_MASK (0x4000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_COMN_SHIFT (14U)
/*! PFD1_OF_COMN - PFD1 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_COMN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD1_OF_COMN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_CMPT_MASK (0x10000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_CMPT_SHIFT (16U)
/*! PFD2_OF_CMPT - PFD2 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_CMPT_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_CMPT_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_MASK (0x20000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_SHIFT (17U)
/*! PFD2_OF_VDD1_SENSE - PFD2 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD1_SENSE_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_MASK (0x40000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_SHIFT (18U)
/*! PFD2_OF_VDD2_DSP - PFD2 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_DSP_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MD2_MASK (0x80000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MD2_SHIFT (19U)
/*! PFD2_OF_MD2 - PFD2 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MD2_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MD2_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MDN_MASK (0x100000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MDN_SHIFT (20U)
/*! PFD2_OF_MDN - PFD2 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MDN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_MDN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_MASK (0x200000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_SHIFT (21U)
/*! PFD2_OF_VDD2_COM - PFD2 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_VDD2_COM_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_COMN_MASK (0x400000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_COMN_SHIFT (22U)
/*! PFD2_OF_COMN - PFD2 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_COMN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD2_OF_COMN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_CMPT_MASK (0x1000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_CMPT_SHIFT (24U)
/*! PFD3_OF_CMPT - PFD3 of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_CMPT_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_CMPT_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_MASK (0x2000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_SHIFT (25U)
/*! PFD3_OF_VDD1_SENSE - PFD3 of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD1_SENSE_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_MASK (0x4000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_SHIFT (26U)
/*! PFD3_OF_VDD2_DSP - PFD3 of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_DSP_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MD2_MASK (0x8000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MD2_SHIFT (27U)
/*! PFD3_OF_MD2 - PFD3 of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MD2_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MD2_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MDN_MASK (0x10000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MDN_SHIFT (28U)
/*! PFD3_OF_MDN - PFD3 of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MDN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_MDN_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_MASK (0x20000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_SHIFT (29U)
/*! PFD3_OF_VDD2_COM - PFD3 of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_VDD2_COM_MASK)

#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_COMN_MASK (0x40000000U)
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_COMN_SHIFT (30U)
/*! PFD3_OF_COMN - PFD3 of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_COMN_SHIFT)) & CLKCTL2_AUDIOPLL0PFDDOMAINEN_PFD3_OF_COMN_MASK)
/*! @} */

/*! @name AUDIOPLL0VCODOMAINEN - Audio PLL0 VCO Clock Enable */
/*! @{ */

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_CMPT_MASK (0x1U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_CMPT_SHIFT (0U)
/*! VCO_OF_CMPT - VCO of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_CMPT_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_CMPT_MASK)

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD1_SENSE_MASK (0x2U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD1_SENSE_SHIFT (1U)
/*! VCO_OF_VDD1_SENSE - VCO of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD1_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD1_SENSE_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD1_SENSE_MASK)

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_DSP_MASK (0x4U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_DSP_SHIFT (2U)
/*! VCO_OF_VDD2_DSP - VCO of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_DSP_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_DSP_MASK)

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MD2_MASK (0x8U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MD2_SHIFT (3U)
/*! VCO_OF_MD2 - VCO of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MD2_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MD2_MASK)

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MDN_MASK (0x10U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MDN_SHIFT (4U)
/*! VCO_OF_MDN - VCO of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MDN_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_MDN_MASK)

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_COM_MASK (0x20U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_COM_SHIFT (5U)
/*! VCO_OF_VDD2_COM - VCO of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_COM_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_VDD2_COM_MASK)

#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_COMN_MASK (0x40U)
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_COMN_SHIFT (6U)
/*! VCO_OF_COMN - VCO of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_COMN_SHIFT)) & CLKCTL2_AUDIOPLL0VCODOMAINEN_VCO_OF_COMN_MASK)
/*! @} */

/*! @name CKIL_32K_GATE - CKIL 32kHz Clock Gate */
/*! @{ */

#define CLKCTL2_CKIL_32K_GATE_CKIL_32K_EN_MASK   (0x1U)
#define CLKCTL2_CKIL_32K_GATE_CKIL_32K_EN_SHIFT  (0U)
/*! CKIL_32K_EN - CKIL 32 kHz Clock Enable
 *  0b0..Gates CKIL 32 kHz clock. You need to read GATED_FLAG field with the value of 1b to confirm the clock is already gated before going ahead.
 *  0b1..Enables CKIL 32 kHz clock.
 */
#define CLKCTL2_CKIL_32K_GATE_CKIL_32K_EN(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL2_CKIL_32K_GATE_CKIL_32K_EN_SHIFT)) & CLKCTL2_CKIL_32K_GATE_CKIL_32K_EN_MASK)

#define CLKCTL2_CKIL_32K_GATE_GATED_FLAG_MASK    (0x2U)
#define CLKCTL2_CKIL_32K_GATE_GATED_FLAG_SHIFT   (1U)
/*! GATED_FLAG - Gated Flag
 *  0b0..The CKIL 32 kHz clock is not gated.
 *  0b1..The CKIL 32 kHz clock is gated.
 */
#define CLKCTL2_CKIL_32K_GATE_GATED_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL2_CKIL_32K_GATE_GATED_FLAG_SHIFT)) & CLKCTL2_CKIL_32K_GATE_GATED_FLAG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL2_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL2_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL2_H_ */

