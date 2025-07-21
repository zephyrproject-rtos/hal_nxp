/*
** ###################################################################
**     Processors:          LPC51U68JBD48
**                          LPC51U68JBD64
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ASYNC_SYSCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-12-15)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ASYNC_SYSCON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ASYNC_SYSCON
 *
 * CMSIS Peripheral Access Layer for ASYNC_SYSCON
 */

#if !defined(PERI_ASYNC_SYSCON_H_)
#define PERI_ASYNC_SYSCON_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC51U68JBD48) || defined(CPU_LPC51U68JBD64))
#include "LPC51U68_COMMON.h"
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

#define ASYNC_SYSCON_ASYNCPRESETCTRL_CTIMER3_MASK (0x2000U)
#define ASYNC_SYSCON_ASYNCPRESETCTRL_CTIMER3_SHIFT (13U)
/*! CTIMER3 - Standard counter/timer CTIMER3 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define ASYNC_SYSCON_ASYNCPRESETCTRL_CTIMER3(x)  (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCPRESETCTRL_CTIMER3_SHIFT)) & ASYNC_SYSCON_ASYNCPRESETCTRL_CTIMER3_MASK)
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

#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CTIMER3_MASK (0x2000U)
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CTIMER3_SHIFT (13U)
/*! CTIMER3 - Controls the clock for CTIMER3. 0 = Disable; 1 = Enable. */
#define ASYNC_SYSCON_ASYNCAPBCLKCTRL_CTIMER3(x)  (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKCTRL_CTIMER3_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKCTRL_CTIMER3_MASK)
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
 *  0b00..Main clock
 *  0b01..FRO 12 MHz
 *  0b10..Reserved setting
 *  0b11..Reserved setting
 */
#define ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL(x)      (((uint32_t)(((uint32_t)(x)) << ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL_SHIFT)) & ASYNC_SYSCON_ASYNCAPBCLKSELA_SEL_MASK)
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


#endif  /* PERI_ASYNC_SYSCON_H_ */

