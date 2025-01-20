/*
** ###################################################################
**     Processors:          LPC54101J256BD64
**                          LPC54101J256UK49
**                          LPC54101J512BD64
**                          LPC54101J512UK49
**                          LPC54102J256BD64_cm0plus
**                          LPC54102J256BD64_cm4
**                          LPC54102J256UK49_cm0plus
**                          LPC54102J256UK49_cm4
**                          LPC54102J512BD64_cm0plus
**                          LPC54102J512BD64_cm4
**                          LPC54102J512UK49_cm0plus
**                          LPC54102J512UK49_cm4
**
**     Version:             rev. 1.0, 2016-04-29
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ASYNC_SYSCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-29)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ASYNC_SYSCON.h
 * @version 1.0
 * @date 2016-04-29
 * @brief CMSIS Peripheral Access Layer for ASYNC_SYSCON
 *
 * CMSIS Peripheral Access Layer for ASYNC_SYSCON
 */

#if !defined(ASYNC_SYSCON_H_)
#define ASYNC_SYSCON_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54101J256BD64) || defined(CPU_LPC54101J256UK49) || defined(CPU_LPC54101J512BD64) || defined(CPU_LPC54101J512UK49))
#include "LPC54101_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm0plus) || defined(CPU_LPC54102J256UK49_cm0plus) || defined(CPU_LPC54102J512BD64_cm0plus) || defined(CPU_LPC54102J512UK49_cm0plus))
#include "LPC54102_cm0plus_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm4) || defined(CPU_LPC54102J256UK49_cm4) || defined(CPU_LPC54102J512BD64_cm4) || defined(CPU_LPC54102J512UK49_cm4))
#include "LPC54102_cm4_COMMON.h"
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ASYNC_SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ASYNC_SYSCON_Peripheral_Access_Layer ASYNC_SYSCON Peripheral Access Layer
 * @{
 */

/** ASYNC_SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t ASYNCPRESETCTRL;                   /**< Async peripheral reset control, offset: 0x0 */
  __O  uint32_t ASYNCPRESETCTRLSET;                /**< Set bits in ASYNCPRESETCTRL, offset: 0x4 */
  __O  uint32_t ASYNCPRESETCTRLCLR;                /**< Clear bits in ASYNCPRESETCTRL, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ASYNCAPBCLKCTRL;                   /**< Async peripheral clock control, offset: 0x10 */
  __O  uint32_t ASYNCAPBCLKCTRLSET;                /**< Set bits in ASYNCAPBCLKCTRL, offset: 0x14 */
  __O  uint32_t ASYNCAPBCLKCTRLCLR;                /**< Clear bits in ASYNCAPBCLKCTRL, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ASYNCAPBCLKSELA;                   /**< Async APB clock source select A, offset: 0x20 */
  __IO uint32_t ASYNCAPBCLKSELB;                   /**< Async APB clock source select B, offset: 0x24 */
  __IO uint32_t ASYNCCLKDIV;                       /**< Async APB clock divider, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FRGCTRL;                           /**< USART fractional rate generator control, offset: 0x30 */
} ASYNC_SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- ASYNC_SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ASYNC_SYSCON_Register_Masks ASYNC_SYSCON Register Masks
 * @{
 */

/*! @name ASYNCPRESETCTRL - Async peripheral reset control */
/*! @{ */

#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART0_MASK (0x2U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART0_SHIFT (1U)
/*! USART0 - USART0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART0(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_USART0_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_USART0_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART1_MASK (0x4U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART1_SHIFT (2U)
/*! USART1 - USART1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART1(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_USART1_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_USART1_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART2_MASK (0x8U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART2_SHIFT (3U)
/*! USART2 - USART2 reset control.0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART2(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_USART2_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_USART2_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART3_MASK (0x10U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART3_SHIFT (4U)
/*! USART3 - USART3 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_USART3(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_USART3_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_USART3_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C0_MASK   (0x20U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C0_SHIFT  (5U)
/*! I2C0 - I2C0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C0(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_I2C0_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_I2C0_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C1_MASK   (0x40U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C1_SHIFT  (6U)
/*! I2C1 - I2C1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C1(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_I2C1_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_I2C1_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C2_MASK   (0x80U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C2_SHIFT  (7U)
/*! I2C2 - I2C2 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_I2C2(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_I2C2_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_I2C2_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_SPI0_MASK   (0x200U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_SPI0_SHIFT  (9U)
/*! SPI0 - SPI0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_SPI0(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_SPI0_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_SPI0_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_SPI1_MASK   (0x400U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_SPI1_SHIFT  (10U)
/*! SPI1 - SPI1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_SPI1(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_SPI1_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_SPI1_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B0_MASK (0x2000U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B0_SHIFT (13U)
/*! CT32B0 - CT32B 0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B0(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B0_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B0_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B1_MASK (0x4000U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B1_SHIFT (14U)
/*! CT32B1 - CT32B 1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B1(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B1_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_CT32B1_MASK)

#define ASYNC_SYSCON_ASYNCPRESETCTRL_FRG0_MASK   (0x8000U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_FRG0_SHIFT  (15U)
/*! FRG0 - FRG reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_FRG0(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_FRG0_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_FRG0_MASK)
/*! @} */

/*! @name ASYNCPRESETCTRLSET - Set bits in ASYNCPRESETCTRL */
/*! @{ */

#define ASYNC_SYSCON_ASYNCPRESETCTRLSET_ARST_SET_MASK (0xFFFFFFFFU)
#define ASYNC_SYSCON_ASYNCPRESETCTRLSET_ARST_SET_SHIFT (0U)
/*! ARST_SET - Writing ones to this register sets the corresponding bit or bits in the
 *    ASYNCPRESETCTRL register, if they are implemented. Bits that do not correspond to defined bits in
 *    ASYNCPRESETCTRL are reserved and only zeroes should be written to them.
 */
#define ASYNC_SYSCON_ASYNCPRESETCTRLSET_ARST_SET(x) (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRLSET_ARST_SET_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRLSET_ARST_SET_MASK)
/*! @} */

/*! @name ASYNCPRESETCTRLCLR - Clear bits in ASYNCPRESETCTRL */
/*! @{ */

#define ASYNC_SYSCON_ASYNCPRESETCTRLCLR_ARST_CLR_MASK (0xFFFFFFFFU)
#define ASYNC_SYSCON_ASYNCPRESETCTRLCLR_ARST_CLR_SHIFT (0U)
/*! ARST_CLR - Writing ones to this register clears the corresponding bit or bits in the
 *    ASYNCPRESETCTRL register, if they are implemented. Bits that do not correspond to defined bits in
 *    ASYNCPRESETCTRL are reserved and only zeroes should be written to them.
 */
#define ASYNC_SYSCON_ASYNCPRESETCTRLCLR_ARST_CLR(x) (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRLCLR_ARST_CLR_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRLCLR_ARST_CLR_MASK)
/*! @} */

/*! @name ASYNCAPBCLKCTRL - Async peripheral clock control */
/*! @{ */

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART0_MASK (0x2U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART0_SHIFT (1U)
/*! USART0 - Controls the clock for USART0. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART0(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART0_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART0_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART1_MASK (0x4U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART1_SHIFT (2U)
/*! USART1 - Controls the clock for USART1. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART1(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART1_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART1_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART2_MASK (0x8U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART2_SHIFT (3U)
/*! USART2 - Controls the clock for USART2. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART2(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART2_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART2_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART3_MASK (0x10U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART3_SHIFT (4U)
/*! USART3 - Controls the clock for USART3. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART3(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART3_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_USART3_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C0_MASK   (0x20U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C0_SHIFT  (5U)
/*! I2C0 - Controls the clock for I2C0. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C0(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C0_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C0_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C1_MASK   (0x40U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C1_SHIFT  (6U)
/*! I2C1 - Controls the clock for I2C1. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C1(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C1_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C1_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C2_MASK   (0x80U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C2_SHIFT  (7U)
/*! I2C2 - Controls the clock for I2C2. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C2(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C2_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_I2C2_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI0_MASK   (0x200U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI0_SHIFT  (9U)
/*! SPI0 - Controls the clock for SPI0. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI0(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI0_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI0_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI1_MASK   (0x400U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI1_SHIFT  (10U)
/*! SPI1 - Controls the clock for SPI1. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI1(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI1_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_SPI1_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B0_MASK (0x2000U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B0_SHIFT (13U)
/*! CT32B0 - Controls the clock for CT32B0. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B0(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B0_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B0_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B1_MASK (0x4000U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B1_SHIFT (14U)
/*! CT32B1 - Controls the clock for CT32B1. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B1(x)   (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B1_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_CT32B1_MASK)

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_FRG0_MASK   (0x8000U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_FRG0_SHIFT  (15U)
/*! FRG0 - Controls the clock for the Fractional Rate Generator used with the USARTs. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_FRG0(x)     (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_FRG0_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_FRG0_MASK)
/*! @} */

/*! @name ASYNCAPBCLKCTRLSET - Set bits in ASYNCAPBCLKCTRL */
/*! @{ */

#define ASYNC_SYSCON_ASYNCAPBCLKCTRLSET_ACLK_SET_MASK (0xFFFFFFFFU)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRLSET_ACLK_SET_SHIFT (0U)
/*! ACLK_SET - Writing ones to this register sets the corresponding bit or bits in the
 *    ASYNCAPBCLKCTRL register, if they are implemented. Bits that do not correspond to defined bits in
 *    ASYNCPRESETCTRL are reserved and only zeroes should be written to them.
 */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRLSET_ACLK_SET(x) (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRLSET_ACLK_SET_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRLSET_ACLK_SET_MASK)
/*! @} */

/*! @name ASYNCAPBCLKCTRLCLR - Clear bits in ASYNCAPBCLKCTRL */
/*! @{ */

#define ASYNC_SYSCON_ASYNCAPBCLKCTRLCLR_ACLK_CLR_MASK (0xFFFFFFFFU)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRLCLR_ACLK_CLR_SHIFT (0U)
/*! ACLK_CLR - Writing ones to this register clears the corresponding bit or bits in the
 *    ASYNCAPBCLKCTRL register, if they are implemented. Bits that do not correspond to defined bits in
 *    ASYNCAPBCLKCTRL are reserved and only zeroes should be written to them.
 */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRLCLR_ACLK_CLR(x) (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRLCLR_ACLK_CLR_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRLCLR_ACLK_CLR_MASK)
/*! @} */

/*! @name ASYNCAPBCLKSELA - Async APB clock source select A */
/*! @{ */

#define ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL_MASK    (0x3U)
#define ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL_SHIFT   (0U)
/*! SEL - Clock source for asynchronous clock source selector A
 *  0b00..IRC Oscillator
 *  0b01..Watchdog oscillator
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL(x)      (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL_MASK)
/*! @} */

/*! @name ASYNCAPBCLKSELB - Async APB clock source select B */
/*! @{ */

#define ASYNC_SYSCON_ASYNCAPBCLKSELB_SEL_MASK    (0x3U)
#define ASYNC_SYSCON_ASYNCAPBCLKSELB_SEL_SHIFT   (0U)
/*! SEL - Clock source for asynchronous clock source selector B.
 *  0b00..Main clock
 *  0b01..CLKIN
 *  0b10..System PLL output.
 *  0b11..ASYNCAPBCLKSELA. Clock selected by the ASYNCAPBCLKSELA register.
 */
#define ASYNC_SYSCON_ASYNCAPBCLKSELB_SEL(x)      (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKSELB_SEL_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKSELB_SEL_MASK)
/*! @} */

/*! @name ASYNCCLKDIV - Async APB clock divider */
/*! @{ */

#define ASYNC_SYSCON_ASYNCCLKDIV_DIV_MASK        (0xFFU)
#define ASYNC_SYSCON_ASYNCCLKDIV_DIV_SHIFT       (0U)
/*! DIV - Asynchronous APB clock divider value. 0: Clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define ASYNC_SYSCON_ASYNCCLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCCLKDIV_DIV_SHIFT)) & ASYNC_SYSCON_ASYNCCLKDIV_DIV_MASK)
/*! @} */

/*! @name FRGCTRL - USART fractional rate generator control */
/*! @{ */

#define ASYNC_SYSCON_FRGCTRL_DIV_MASK            (0xFFU)
#define ASYNC_SYSCON_FRGCTRL_DIV_SHIFT           (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define ASYNC_SYSCON_FRGCTRL_DIV(x)              (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_FRGCTRL_DIV_SHIFT)) & ASYNC_SYSCON_FRGCTRL_DIV_MASK)

#define ASYNC_SYSCON_FRGCTRL_MULT_MASK           (0xFF00U)
#define ASYNC_SYSCON_FRGCTRL_MULT_SHIFT          (8U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define ASYNC_SYSCON_FRGCTRL_MULT(x)             (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_FRGCTRL_MULT_SHIFT)) & ASYNC_SYSCON_FRGCTRL_MULT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ASYNC_SYSCON_Register_Masks */


/*!
 * @}
 */ /* end of group ASYNC_SYSCON_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* ASYNC_SYSCON_H_ */

