/*
** ###################################################################
**     Processors:          MCXC041VFG
**                          MCXC041VFK
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MCG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCG
 *
 * CMSIS Peripheral Access Layer for MCG
 */

#if !defined(PERI_MCG_H_)
#define PERI_MCG_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC041VFG) || defined(CPU_MCXC041VFK))
#include "MCXC041_COMMON.h"
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
   -- MCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Peripheral_Access_Layer MCG Peripheral Access Layer
 * @{
 */

/** MCG - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< MCG Control Register 1, offset: 0x0 */
  __IO uint8_t C2;                                 /**< MCG Control Register 2, offset: 0x1 */
       uint8_t RESERVED_0[4];
  __I  uint8_t S;                                  /**< MCG Status Register, offset: 0x6 */
       uint8_t RESERVED_1[1];
  __IO uint8_t SC;                                 /**< MCG Status and Control Register, offset: 0x8 */
       uint8_t RESERVED_2[15];
  __IO uint8_t MC;                                 /**< MCG Miscellaneous Control Register, offset: 0x18 */
} MCG_Type;

/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/*! @name C1 - MCG Control Register 1 */
/*! @{ */

#define MCG_C1_IREFSTEN_MASK                     (0x1U)
#define MCG_C1_IREFSTEN_SHIFT                    (0U)
/*! IREFSTEN - Internal Reference Stop Enable
 *  0b0..LIRC is disabled in Stop mode.
 *  0b1..LIRC is enabled in Stop mode, if IRCLKEN is set.
 */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFSTEN_SHIFT)) & MCG_C1_IREFSTEN_MASK)

#define MCG_C1_IRCLKEN_MASK                      (0x2U)
#define MCG_C1_IRCLKEN_SHIFT                     (1U)
/*! IRCLKEN - Internal Reference Clock Enable
 *  0b0..LIRC is disabled.
 *  0b1..LIRC is enabled.
 */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C1_IRCLKEN_SHIFT)) & MCG_C1_IRCLKEN_MASK)

#define MCG_C1_CLKS_MASK                         (0xC0U)
#define MCG_C1_CLKS_SHIFT                        (6U)
/*! CLKS - Clock Source Select
 *  0b00..Selects HIRC clock as the main clock source. This is HIRC mode.
 *  0b01..Selects LIRC clock as the main clock source. This is LIRC2M or LIRC8M mode.
 *  0b10..Selects external clock as the main clock source. This is EXT mode.
 *  0b11..Reserved. Writing 11 takes no effect.
 */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C1_CLKS_SHIFT)) & MCG_C1_CLKS_MASK)
/*! @} */

/*! @name C2 - MCG Control Register 2 */
/*! @{ */

#define MCG_C2_IRCS_MASK                         (0x1U)
#define MCG_C2_IRCS_SHIFT                        (0U)
/*! IRCS - Low-frequency Internal Reference Clock Select
 *  0b0..LIRC is in 2 MHz mode.
 *  0b1..LIRC is in 8 MHz mode.
 */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C2_IRCS_SHIFT)) & MCG_C2_IRCS_MASK)

#define MCG_C2_EREFS0_MASK                       (0x4U)
#define MCG_C2_EREFS0_SHIFT                      (2U)
/*! EREFS0 - External Clock Source Select
 *  0b0..External clock requested.
 *  0b1..Oscillator requested.
 */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C2_EREFS0_SHIFT)) & MCG_C2_EREFS0_MASK)
/*! @} */

/*! @name S - MCG Status Register */
/*! @{ */

#define MCG_S_OSCINIT0_MASK                      (0x2U)
#define MCG_S_OSCINIT0_SHIFT                     (1U)
/*! OSCINIT0 - OSC Initialization Status
 *  0b0..OSC is not ready.
 *  0b1..OSC clock is ready.
 */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_S_OSCINIT0_SHIFT)) & MCG_S_OSCINIT0_MASK)

#define MCG_S_CLKST_MASK                         (0xCU)
#define MCG_S_CLKST_SHIFT                        (2U)
/*! CLKST - Clock Mode Status
 *  0b00..HIRC clock is selected as the main clock source, and MCG_Lite works at HIRC mode.
 *  0b01..LIRC clock is selected as the main clock source, and MCG_Lite works at LIRC2M or LIRC8M mode.
 *  0b10..External clock is selected as the main clock source, and MCG_Lite works at EXT mode.
 *  0b11..Reserved.
 */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_CLKST_SHIFT)) & MCG_S_CLKST_MASK)
/*! @} */

/*! @name SC - MCG Status and Control Register */
/*! @{ */

#define MCG_SC_FCRDIV_MASK                       (0xEU)
#define MCG_SC_FCRDIV_SHIFT                      (1U)
/*! FCRDIV - Low-frequency Internal Reference Clock Divider
 *  0b000..Division factor is 1.
 *  0b001..Division factor is 2.
 *  0b010..Division factor is 4.
 *  0b011..Division factor is 8.
 *  0b100..Division factor is 16.
 *  0b101..Division factor is 32.
 *  0b110..Division factor is 64.
 *  0b111..Division factor is 128.
 */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_SC_FCRDIV_SHIFT)) & MCG_SC_FCRDIV_MASK)
/*! @} */

/*! @name MC - MCG Miscellaneous Control Register */
/*! @{ */

#define MCG_MC_LIRC_DIV2_MASK                    (0x7U)
#define MCG_MC_LIRC_DIV2_SHIFT                   (0U)
/*! LIRC_DIV2 - Second Low-frequency Internal Reference Clock Divider
 *  0b000..Division factor is 1.
 *  0b001..Division factor is 2.
 *  0b010..Division factor is 4.
 *  0b011..Division factor is 8.
 *  0b100..Division factor is 16.
 *  0b101..Division factor is 32.
 *  0b110..Division factor is 64.
 *  0b111..Division factor is 128.
 */
#define MCG_MC_LIRC_DIV2(x)                      (((uint8_t)(((uint8_t)(x)) << MCG_MC_LIRC_DIV2_SHIFT)) & MCG_MC_LIRC_DIV2_MASK)

#define MCG_MC_HIRCEN_MASK                       (0x80U)
#define MCG_MC_HIRCEN_SHIFT                      (7U)
/*! HIRCEN - High-frequency IRC Enable
 *  0b0..HIRC source is not enabled.
 *  0b1..HIRC source is enabled.
 */
#define MCG_MC_HIRCEN(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_MC_HIRCEN_SHIFT)) & MCG_MC_HIRCEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MCG_Register_Masks */


/*!
 * @}
 */ /* end of group MCG_Peripheral_Access_Layer */


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


#endif  /* PERI_MCG_H_ */

