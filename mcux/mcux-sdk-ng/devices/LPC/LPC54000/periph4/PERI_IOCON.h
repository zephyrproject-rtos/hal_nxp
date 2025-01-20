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
**         CMSIS Peripheral Access Layer for IOCON
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
 * @file IOCON.h
 * @version 1.0
 * @date 2016-04-29
 * @brief CMSIS Peripheral Access Layer for IOCON
 *
 * CMSIS Peripheral Access Layer for IOCON
 */

#if !defined(IOCON_H_)
#define IOCON_H_                                 /**< Symbol preventing repeated inclusion */

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
   -- IOCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Peripheral_Access_Layer IOCON Peripheral Access Layer
 * @{
 */

/** IOCON - Size of Registers Arrays */
#define IOCON_PIO_COUNT                           2u
#define IOCON_PIO_PIO_COUNT                       32u

/** IOCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOCON_PIO_COUNT][IOCON_PIO_PIO_COUNT]; /**< Digital I/O control for port 0 pins PIO0_0..Digital I/O control for port 1 pins PIO1_31, array offset: 0x0, array step: index*0x80, index2*0x4 */
} IOCON_Type;

/* ----------------------------------------------------------------------------
   -- IOCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Register_Masks IOCON Register Masks
 * @{
 */

/*! @name PIO - Digital I/O control for port 0 pins PIO0_0..Digital I/O control for port 1 pins PIO1_31 */
/*! @{ */

#define IOCON_PIO_FUNC_MASK                      (0x7U)
#define IOCON_PIO_FUNC_SHIFT                     (0U)
/*! FUNC - Selects pin function.
 *  0b000..Alternative connection 0.
 *  0b001..Alternative connection 1.
 *  0b010..Alternative connection 2.
 *  0b011..Alternative connection 3.
 *  0b100..Alternative connection 4.
 *  0b101..Alternative connection 5.
 *  0b110..Alternative connection 6.
 *  0b111..Alternative connection 7.
 */
#define IOCON_PIO_FUNC(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FUNC_SHIFT)) & IOCON_PIO_FUNC_MASK)

#define IOCON_PIO_MODE_MASK                      (0x18U)
#define IOCON_PIO_MODE_SHIFT                     (3U)
/*! MODE - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define IOCON_PIO_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_MODE_SHIFT)) & IOCON_PIO_MODE_MASK)

#define IOCON_PIO_I2CSLEW_MASK                   (0x20U)
#define IOCON_PIO_I2CSLEW_SHIFT                  (5U)
/*! I2CSLEW - Controls slew rate of I2C pad.
 *  0b0..I2C mode.
 *  0b1..GPIO mode.
 */
#define IOCON_PIO_I2CSLEW(x)                     (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CSLEW_SHIFT)) & IOCON_PIO_I2CSLEW_MASK)

#define IOCON_PIO_INVERT_MASK                    (0x40U)
#define IOCON_PIO_INVERT_SHIFT                   (6U)
/*! INVERT - Input polarity.
 *  0b0..Disabled. Input function is not inverted.
 *  0b1..Enabled. Input is function inverted.
 */
#define IOCON_PIO_INVERT(x)                      (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_INVERT_SHIFT)) & IOCON_PIO_INVERT_MASK)

#define IOCON_PIO_DIGIMODE_MASK                  (0x80U)
#define IOCON_PIO_DIGIMODE_SHIFT                 (7U)
/*! DIGIMODE - Select Analog/Digital mode.
 *  0b0..Analog mode.
 *  0b1..Digital mode.
 */
#define IOCON_PIO_DIGIMODE(x)                    (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_DIGIMODE_SHIFT)) & IOCON_PIO_DIGIMODE_MASK)

#define IOCON_PIO_FILTEROFF_MASK                 (0x100U)
#define IOCON_PIO_FILTEROFF_SHIFT                (8U)
/*! FILTEROFF - Controls input glitch filter.
 *  0b0..Filter enabled. Noise pulses below approximately 10 ns are filtered out.
 *  0b1..Filter disabled. No input filtering is done.
 */
#define IOCON_PIO_FILTEROFF(x)                   (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FILTEROFF_SHIFT)) & IOCON_PIO_FILTEROFF_MASK)

#define IOCON_PIO_I2CDRIVE_MASK                  (0x200U)
#define IOCON_PIO_I2CDRIVE_SHIFT                 (9U)
/*! I2CDRIVE - Controls the current sink capability of the pin.
 *  0b0..Low drive. Output drive sink is 4 mA. This is sufficient for standard and fast mode I2C.
 *  0b1..High drive. Output drive sink is 20 mA. This is needed for Fast Mode Plus I 2C. Refer to the appropriate
 *       specific device data sheet for details.
 */
#define IOCON_PIO_I2CDRIVE(x)                    (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CDRIVE_SHIFT)) & IOCON_PIO_I2CDRIVE_MASK)

#define IOCON_PIO_SLEW_MASK                      (0x200U)
#define IOCON_PIO_SLEW_SHIFT                     (9U)
/*! SLEW - Driver slew rate.
 *  0b0..Standard mode, output slew rate control is enabled. More outputs can be switched simultaneously.
 *  0b1..Fast mode, slew rate control is disabled. Refer to the appropriate specific device data sheet for details.
 */
#define IOCON_PIO_SLEW(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_SLEW_SHIFT)) & IOCON_PIO_SLEW_MASK)

#define IOCON_PIO_I2CFILTER_MASK                 (0x400U)
#define IOCON_PIO_I2CFILTER_SHIFT                (10U)
/*! I2CFILTER - Configures I2C features for standard mode, fast mode, and Fast Mode Plus operation.
 *  0b0..Enabled. I2C 50 ns glitch filter enabled.
 *  0b1..Disabled. I2C 50 ns glitch filter disabled.
 */
#define IOCON_PIO_I2CFILTER(x)                   (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CFILTER_SHIFT)) & IOCON_PIO_I2CFILTER_MASK)

#define IOCON_PIO_OD_MASK                        (0x400U)
#define IOCON_PIO_OD_SHIFT                       (10U)
/*! OD - Controls open-drain mode.
 *  0b0..Normal. Normal push-pull output
 *  0b1..Open-drain. Simulated open-drain output (high drive disabled).
 */
#define IOCON_PIO_OD(x)                          (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_OD_SHIFT)) & IOCON_PIO_OD_MASK)
/*! @} */

/* The count of IOCON_PIO */
#define IOCON_PIO_COUNT2                         (32U)


/*!
 * @}
 */ /* end of group IOCON_Register_Masks */


/*!
 * @}
 */ /* end of group IOCON_Peripheral_Access_Layer */


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


#endif  /* IOCON_H_ */

