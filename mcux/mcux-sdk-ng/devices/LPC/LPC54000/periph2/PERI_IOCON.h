/*
** ###################################################################
**     Processors:          LPC54018J2MET180
**                          LPC54018J4MET180
**                          LPC54S018J2MET180
**                          LPC54S018J4MET180
**
**     Version:             rev. 1.2, 2017-06-08
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
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**
** ###################################################################
*/

/*!
 * @file IOCON.h
 * @version 1.2
 * @date 2017-06-08
 * @brief CMSIS Peripheral Access Layer for IOCON
 *
 * CMSIS Peripheral Access Layer for IOCON
 */

#if !defined(IOCON_H_)
#define IOCON_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54018J2MET180) || defined(CPU_LPC54018J4MET180))
#include "LPC54018M_COMMON.h"
#elif (defined(CPU_LPC54S018J2MET180) || defined(CPU_LPC54S018J4MET180))
#include "LPC54S018M_COMMON.h"
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
   -- IOCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Peripheral_Access_Layer IOCON Peripheral Access Layer
 * @{
 */

/** IOCON - Size of Registers Arrays */
#define IOCON_PIO_COUNT                           6u
#define IOCON_PIO_PIO_COUNT                       32u

/** IOCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOCON_PIO_COUNT][IOCON_PIO_PIO_COUNT]; /**< Digital I/O control for port 0 pins PIO0_0..Digital I/O control for port 5 pins PIO5_31, array offset: 0x0, array step: index*0x80, index2*0x4 */
} IOCON_Type;

/* ----------------------------------------------------------------------------
   -- IOCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Register_Masks IOCON Register Masks
 * @{
 */

/*! @name PIO - Digital I/O control for port 0 pins PIO0_0..Digital I/O control for port 5 pins PIO5_31 */
/*! @{ */

#define IOCON_PIO_FUNC_MASK                      (0xFU)
#define IOCON_PIO_FUNC_SHIFT                     (0U)
/*! FUNC - Selects pin function.
 *  0b0000..Alternative connection 0.
 *  0b0001..Alternative connection 1.
 *  0b0010..Alternative connection 2.
 *  0b0011..Alternative connection 3.
 *  0b0100..Alternative connection 4.
 *  0b0101..Alternative connection 5.
 *  0b0110..Alternative connection 6.
 *  0b0111..Alternative connection 7.
 *  0b1000..Alternative connection 8.
 *  0b1001..Alternative connection 9.
 *  0b1010..Alternative connection 10.
 */
#define IOCON_PIO_FUNC(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FUNC_SHIFT)) & IOCON_PIO_FUNC_MASK)

#define IOCON_PIO_MODE_MASK                      (0x30U)
#define IOCON_PIO_MODE_SHIFT                     (4U)
/*! MODE - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define IOCON_PIO_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_MODE_SHIFT)) & IOCON_PIO_MODE_MASK)

#define IOCON_PIO_ANAMODE_MASK                   (0x40U)
#define IOCON_PIO_ANAMODE_SHIFT                  (6U)
/*! ANAMODE - Enables or disables analog mode.
 *  0b0..Enable analog Mode.
 *  0b1..Disable analog Mode.
 */
#define IOCON_PIO_ANAMODE(x)                     (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_ANAMODE_SHIFT)) & IOCON_PIO_ANAMODE_MASK)

#define IOCON_PIO_I2CSLEW_MASK                   (0x40U)
#define IOCON_PIO_I2CSLEW_SHIFT                  (6U)
/*! I2CSLEW - Controls slew rate of I2C pad.
 *  0b0..I2C mode.
 *  0b1..GPIO mode.
 */
#define IOCON_PIO_I2CSLEW(x)                     (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CSLEW_SHIFT)) & IOCON_PIO_I2CSLEW_MASK)

#define IOCON_PIO_INVERT_MASK                    (0x80U)
#define IOCON_PIO_INVERT_SHIFT                   (7U)
/*! INVERT - Input polarity.
 *  0b0..Disabled. Input function is not inverted.
 *  0b1..Enabled. Input is function inverted.
 */
#define IOCON_PIO_INVERT(x)                      (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_INVERT_SHIFT)) & IOCON_PIO_INVERT_MASK)

#define IOCON_PIO_DIGIMODE_MASK                  (0x100U)
#define IOCON_PIO_DIGIMODE_SHIFT                 (8U)
/*! DIGIMODE - Select Analog/Digital mode.
 *  0b0..Analog mode.
 *  0b1..Digital mode.
 */
#define IOCON_PIO_DIGIMODE(x)                    (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_DIGIMODE_SHIFT)) & IOCON_PIO_DIGIMODE_MASK)

#define IOCON_PIO_FILTEROFF_MASK                 (0x200U)
#define IOCON_PIO_FILTEROFF_SHIFT                (9U)
/*! FILTEROFF - Controls input glitch filter.
 *  0b0..Filter enabled. Noise pulses below approximately 10 ns are filtered out.
 *  0b1..Filter disabled. No input filtering is done.
 */
#define IOCON_PIO_FILTEROFF(x)                   (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FILTEROFF_SHIFT)) & IOCON_PIO_FILTEROFF_MASK)

#define IOCON_PIO_I2CDRIVE_MASK                  (0x400U)
#define IOCON_PIO_I2CDRIVE_SHIFT                 (10U)
/*! I2CDRIVE - Controls the current sink capability of the pin.
 *  0b0..Low drive. Output drive sink is 4 mA. This is sufficient for standard and fast mode I2C.
 *  0b1..High drive. Output drive sink is 20 mA. This is needed for Fast Mode Plus I 2C. Refer to the appropriate
 *       specific device data sheet for details.
 */
#define IOCON_PIO_I2CDRIVE(x)                    (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CDRIVE_SHIFT)) & IOCON_PIO_I2CDRIVE_MASK)

#define IOCON_PIO_SLEW_MASK                      (0x400U)
#define IOCON_PIO_SLEW_SHIFT                     (10U)
/*! SLEW - Driver slew rate.
 *  0b0..Standard mode, output slew rate control is enabled. More outputs can be switched simultaneously.
 *  0b1..Fast mode, slew rate control is disabled. Refer to the appropriate specific device data sheet for details.
 */
#define IOCON_PIO_SLEW(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_SLEW_SHIFT)) & IOCON_PIO_SLEW_MASK)

#define IOCON_PIO_I2CFILTEROFF_MASK              (0x800U)
#define IOCON_PIO_I2CFILTEROFF_SHIFT             (11U)
/*! I2CFILTEROFF - Configures I2C features for standard mode, fast mode, and Fast Mode Plus operation.
 *  0b0..Enabled. I2C 50 ns glitch filter enabled.
 *  0b1..Disabled. I2C 50 ns glitch filter disabled.
 */
#define IOCON_PIO_I2CFILTEROFF(x)                (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CFILTEROFF_SHIFT)) & IOCON_PIO_I2CFILTEROFF_MASK)

#define IOCON_PIO_OD_MASK                        (0x800U)
#define IOCON_PIO_OD_SHIFT                       (11U)
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


#endif  /* IOCON_H_ */

