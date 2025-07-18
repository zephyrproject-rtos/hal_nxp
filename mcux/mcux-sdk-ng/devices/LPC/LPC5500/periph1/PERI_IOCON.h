/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOCON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOCON
 *
 * CMSIS Peripheral Access Layer for IOCON
 */

#if !defined(PERI_IOCON_H_)
#define PERI_IOCON_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
#define IOCON_PIO_COUNT                           4u
#define IOCON_PIO_PIO_COUNT                       32u

/** IOCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOCON_PIO_COUNT][IOCON_PIO_PIO_COUNT]; /**< Analog/Digital I/O control for port..Digital I/O control for port, array offset: 0x0, array step: index*0x80, index2*0x4 */
} IOCON_Type;

/* ----------------------------------------------------------------------------
   -- IOCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOCON_Register_Masks IOCON Register Masks
 * @{
 */

/*! @name PIO - Analog/Digital I/O control for port..Digital I/O control for port */
/*! @{ */

#define IOCON_PIO_FUNC_MASK                      (0xFU)
#define IOCON_PIO_FUNC_SHIFT                     (0U)
/*! FUNC - Signal(function) select */
#define IOCON_PIO_FUNC(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FUNC_SHIFT)) & IOCON_PIO_FUNC_MASK)

#define IOCON_PIO_MODE_MASK                      (0x30U)
#define IOCON_PIO_MODE_SHIFT                     (4U)
/*! MODE - Mode select (on-chip pull-up/pull-down resistor control)
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define IOCON_PIO_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_MODE_SHIFT)) & IOCON_PIO_MODE_MASK)

#define IOCON_PIO_SLEW_MASK                      (0x40U)
#define IOCON_PIO_SLEW_SHIFT                     (6U)
/*! SLEW - Driver slew rate
 *  0b0..Standard-mode, output slew rate is slower. More outputs can be switched simultaneously.
 *  0b1..Fast-mode, output slew rate is faster. Refer to the appropriate specific device data sheet for details.
 */
#define IOCON_PIO_SLEW(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_SLEW_SHIFT)) & IOCON_PIO_SLEW_MASK)

#define IOCON_PIO_INVERT_MASK                    (0x80U)
#define IOCON_PIO_INVERT_SHIFT                   (7U)
/*! INVERT - Invert polarity of input signal
 *  0b0..Don't invert the signal.
 *  0b1..Invert the signal.
 */
#define IOCON_PIO_INVERT(x)                      (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_INVERT_SHIFT)) & IOCON_PIO_INVERT_MASK)

#define IOCON_PIO_DIGIMODE_MASK                  (0x100U)
#define IOCON_PIO_DIGIMODE_SHIFT                 (8U)
/*! DIGIMODE - Select Digital mode
 *  0b0..Disable digital mode. Digital input set to 0.
 *  0b1..Enable Digital mode. Digital input is enabled.
 */
#define IOCON_PIO_DIGIMODE(x)                    (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_DIGIMODE_SHIFT)) & IOCON_PIO_DIGIMODE_MASK)

#define IOCON_PIO_OD_MASK                        (0x200U)
#define IOCON_PIO_OD_SHIFT                       (9U)
/*! OD - Controls open-drain mode
 *  0b0..Normal. Normal push-pull output
 *  0b1..Open-drain. Simulated open-drain output (high drive disabled).
 */
#define IOCON_PIO_OD(x)                          (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_OD_SHIFT)) & IOCON_PIO_OD_MASK)

#define IOCON_PIO_ASW0_MASK                      (0x400U)
#define IOCON_PIO_ASW0_SHIFT                     (10U)
/*! ASW0 - Analog switch input control
 *  0b0..Analog switch is open. (disable)
 *  0b1..Analog switch is closed. (enable)
 */
#define IOCON_PIO_ASW0(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_ASW0_SHIFT)) & IOCON_PIO_ASW0_MASK)

#define IOCON_PIO_ASW1_MASK                      (0x800U)
#define IOCON_PIO_ASW1_SHIFT                     (11U)
/*! ASW1 - Analog switch input control
 *  0b0..Analog switch is open. (disable)
 *  0b1..Analog switch is closed. (enable)
 */
#define IOCON_PIO_ASW1(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_ASW1_SHIFT)) & IOCON_PIO_ASW1_MASK)

#define IOCON_PIO_SSEL_MASK                      (0x800U)
#define IOCON_PIO_SSEL_SHIFT                     (11U)
/*! SSEL - Supply Selection bit.
 *  0b0..3V3 Signaling in I2C Mode.
 *  0b1..1V8 Signaling in I2C Mode.
 */
#define IOCON_PIO_SSEL(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_SSEL_SHIFT)) & IOCON_PIO_SSEL_MASK)

#define IOCON_PIO_FILTEROFF_MASK                 (0x1000U)
#define IOCON_PIO_FILTEROFF_SHIFT                (12U)
/*! FILTEROFF - Controls input glitch filter
 *  0b0..Filter enabled.
 *  0b1..Filter disabled.
 */
#define IOCON_PIO_FILTEROFF(x)                   (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FILTEROFF_SHIFT)) & IOCON_PIO_FILTEROFF_MASK)

#define IOCON_PIO_ECS_MASK                       (0x2000U)
#define IOCON_PIO_ECS_SHIFT                      (13U)
/*! ECS - Pull-up current source enable in I2C mode
 *  0b0..Disabled. IO is in open drain cell.
 *  0b1..Enabled. Pull resistor is conencted.
 */
#define IOCON_PIO_ECS(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_ECS_SHIFT)) & IOCON_PIO_ECS_MASK)

#define IOCON_PIO_EGP_MASK                       (0x4000U)
#define IOCON_PIO_EGP_SHIFT                      (14U)
/*! EGP - Switch between GPIO mode and I2C mode
 *  0b0..I2C mode
 *  0b1..GPIO mode.
 */
#define IOCON_PIO_EGP(x)                         (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_EGP_SHIFT)) & IOCON_PIO_EGP_MASK)

#define IOCON_PIO_I2CFILTER_MASK                 (0x8000U)
#define IOCON_PIO_I2CFILTER_SHIFT                (15U)
/*! I2CFILTER - Configures I2C features for standard mode, fast mode, and Fast Mode Plus operation and High-Speed mode operation.
 *  0b0..I2C 50 ns glitch filter enabled. Typically used for Standard-mode, Fast-mode and Fast-mode Plus I2C.
 *  0b1..I2C 10 ns glitch filter enabled. Typically used for High-speed mode I2C.
 */
#define IOCON_PIO_I2CFILTER(x)                   (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_I2CFILTER_SHIFT)) & IOCON_PIO_I2CFILTER_MASK)
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


#endif  /* PERI_IOCON_H_ */

