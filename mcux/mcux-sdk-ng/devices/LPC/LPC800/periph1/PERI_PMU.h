/*
** ###################################################################
**     Processors:          LPC822M101JDH20
**                          LPC822M101JHI33
**                          LPC824M201JDH20
**                          LPC824M201JHI33
**                          LPC832M101FDH20
**                          LPC834M101FHI33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-02-09)
**         Initial version.
**     - rev. 1.1 (2018-02-25)
**         Update some registers according to UM rev 1.2
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMU
 *
 * CMSIS Peripheral Access Layer for PMU
 */

#if !defined(PERI_PMU_H_)
#define PERI_PMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC822M101JDH20) || defined(CPU_LPC822M101JHI33))
#include "LPC822_COMMON.h"
#elif (defined(CPU_LPC824M201JDH20) || defined(CPU_LPC824M201JHI33))
#include "LPC824_COMMON.h"
#elif (defined(CPU_LPC832M101FDH20))
#include "LPC832_COMMON.h"
#elif (defined(CPU_LPC834M101FHI33))
#include "LPC834_COMMON.h"
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
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Size of Registers Arrays */
#define PMU_GPREG_COUNT                           4u

/** PMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCON;                              /**< Power control register, offset: 0x0 */
  __IO uint32_t GPREG[PMU_GPREG_COUNT];            /**< General purpose register N, array offset: 0x4, array step: 0x4 */
  __IO uint32_t DPDCTRL;                           /**< Deep power-down control register. Also includes bits for general purpose storage., offset: 0x14 */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name PCON - Power control register */
/*! @{ */

#define PMU_PCON_PM_MASK                         (0x7U)
#define PMU_PCON_PM_SHIFT                        (0U)
/*! PM - Power mode
 *  0b000..Default. The part is in active or sleep mode.
 *  0b001..Deep-sleep mode. ARM WFI will enter Deep-sleep mode.
 *  0b010..Power-down mode. ARM WFI will enter Power-down mode.
 *  0b011..Deep power-down mode. ARM WFI will enter Deep-power down mode (ARM Cortex-M0+ core powered-down).
 */
#define PMU_PCON_PM(x)                           (((uint32_t)(((uint32_t)(x)) << PMU_PCON_PM_SHIFT)) & PMU_PCON_PM_MASK)

#define PMU_PCON_NODPD_MASK                      (0x8U)
#define PMU_PCON_NODPD_SHIFT                     (3U)
/*! NODPD - A 1 in this bit prevents entry to Deep power-down mode when 0x3 is written to the PM
 *    field above, the SLEEPDEEP bit is set, and a WFI is executed. This bit is cleared only by
 *    power-on reset, so writing a one to this bit locks the part in a mode in which Deep power-down mode
 *    is blocked.
 */
#define PMU_PCON_NODPD(x)                        (((uint32_t)(((uint32_t)(x)) << PMU_PCON_NODPD_SHIFT)) & PMU_PCON_NODPD_MASK)

#define PMU_PCON_SLEEPFLAG_MASK                  (0x100U)
#define PMU_PCON_SLEEPFLAG_SHIFT                 (8U)
/*! SLEEPFLAG - Sleep mode flag
 *  0b0..Active mode. Read: No power-down mode entered. Part is in Active mode. Write: No effect.
 *  0b1..Low power mode. Read: Sleep, Deep-sleep or Power-down mode entered. Write: Writing a 1 clears the SLEEPFLAG bit to 0.
 */
#define PMU_PCON_SLEEPFLAG(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_PCON_SLEEPFLAG_SHIFT)) & PMU_PCON_SLEEPFLAG_MASK)

#define PMU_PCON_DPDFLAG_MASK                    (0x800U)
#define PMU_PCON_DPDFLAG_SHIFT                   (11U)
/*! DPDFLAG - Deep power-down flag
 *  0b0..Not Deep power-down. Read: Deep power-down mode not entered. Write: No effect.
 *  0b1..Deep power-down. Read: Deep power-down mode entered. Write: Clear the Deep power-down flag.
 */
#define PMU_PCON_DPDFLAG(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PCON_DPDFLAG_SHIFT)) & PMU_PCON_DPDFLAG_MASK)
/*! @} */

/*! @name GPREG - General purpose register N */
/*! @{ */

#define PMU_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)
#define PMU_GPREG_GPDATA_SHIFT                   (0U)
/*! GPDATA - Data retained during Deep power-down mode. */
#define PMU_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_GPREG_GPDATA_SHIFT)) & PMU_GPREG_GPDATA_MASK)
/*! @} */

/*! @name DPDCTRL - Deep power-down control register. Also includes bits for general purpose storage. */
/*! @{ */

#define PMU_DPDCTRL_WAKEUPHYS_MASK               (0x1U)
#define PMU_DPDCTRL_WAKEUPHYS_SHIFT              (0U)
/*! WAKEUPHYS - WAKEUP pin hysteresis enable
 *  0b0..Disabled. Hysteresis for WAKEUP pin disabled.
 *  0b1..Enabled. Hysteresis for WAKEUP pin enabled.
 */
#define PMU_DPDCTRL_WAKEUPHYS(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_WAKEUPHYS_SHIFT)) & PMU_DPDCTRL_WAKEUPHYS_MASK)

#define PMU_DPDCTRL_WAKEPAD_DISABLE_MASK         (0x2U)
#define PMU_DPDCTRL_WAKEPAD_DISABLE_SHIFT        (1U)
/*! WAKEPAD_DISABLE - WAKEUP pin disable. Setting this bit disables the wake-up pin, so it can be
 *    used for other purposes. Remark: Never set this bit if you intend to use a pin to wake up the
 *    part from Deep power-down mode. You can only disable the wake-up pin if the self wake-up timer
 *    is enabled and configured. Remark: Setting this bit is not necessary if Deep power-down mode is
 *    not used.
 *  0b0..Enabled. The wake-up function is enabled on pin PIO0_4.
 *  0b1..Disabled. Setting this bit disables the wake-up function on pin PIO0_4.
 */
#define PMU_DPDCTRL_WAKEPAD_DISABLE(x)           (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_WAKEPAD_DISABLE_SHIFT)) & PMU_DPDCTRL_WAKEPAD_DISABLE_MASK)

#define PMU_DPDCTRL_LPOSCEN_MASK                 (0x4U)
#define PMU_DPDCTRL_LPOSCEN_SHIFT                (2U)
/*! LPOSCEN - Enable the low-power oscillator for use with the 10 kHz self wake-up timer clock. You
 *    must set this bit if the CLKSEL bit in the self wake-up timer CTRL bit is set. Do not enable
 *    the low-power oscillator if the self wake-up timer is clocked by the divided IRC or the
 *    external clock input.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define PMU_DPDCTRL_LPOSCEN(x)                   (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_LPOSCEN_SHIFT)) & PMU_DPDCTRL_LPOSCEN_MASK)

#define PMU_DPDCTRL_LPOSCDPDEN_MASK              (0x8U)
#define PMU_DPDCTRL_LPOSCDPDEN_SHIFT             (3U)
/*! LPOSCDPDEN - causes the low-power oscillator to remain running during Deep power-down mode
 *    provided that bit 2 in this register is set as well. You must set this bit for the self wake-up
 *    timer to be able to wake up the part from Deep power-down mode. Remark: Do not set this bit
 *    unless you use the self wake-up timer with the low-power oscillator clock source to wake up from
 *    Deep power-down mode.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define PMU_DPDCTRL_LPOSCDPDEN(x)                (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_LPOSCDPDEN_SHIFT)) & PMU_DPDCTRL_LPOSCDPDEN_MASK)

#define PMU_DPDCTRL_WAKEUPCLKHYS_MASK            (0x10U)
#define PMU_DPDCTRL_WAKEUPCLKHYS_SHIFT           (4U)
/*! WAKEUPCLKHYS - External clock input for the self wake-up timer WKTCLKIN hysteresis enable.
 *  0b0..Disabled. Hysteresis for WAKEUP clock pin disabled.
 *  0b1..Enabled. Hysteresis for WAKEUP clock pin enabled.
 */
#define PMU_DPDCTRL_WAKEUPCLKHYS(x)              (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_WAKEUPCLKHYS_SHIFT)) & PMU_DPDCTRL_WAKEUPCLKHYS_MASK)

#define PMU_DPDCTRL_WAKECLKPAD_DISABLE_MASK      (0x20U)
#define PMU_DPDCTRL_WAKECLKPAD_DISABLE_SHIFT     (5U)
/*! WAKECLKPAD_DISABLE - Disable the external clock input for the self wake-up timer. Setting this
 *    bit enables the self wake-up timer clock pin WKTCLKLIN. To minimize power consumption,
 *    especially in deep power-down mode, disable this clock input when not using the external clock option
 *    for the self wake-up timer.
 *  0b0..Disabled. Setting this bit disables external clock input on pin PIO0_28.
 *  0b1..Enabled. The external clock input for the self wake-up timer is enabled on pin PIO0_28.
 */
#define PMU_DPDCTRL_WAKECLKPAD_DISABLE(x)        (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_WAKECLKPAD_DISABLE_SHIFT)) & PMU_DPDCTRL_WAKECLKPAD_DISABLE_MASK)

#define PMU_DPDCTRL_GPDATA_MASK                  (0xFFFFFFC0U)
#define PMU_DPDCTRL_GPDATA_SHIFT                 (6U)
/*! GPDATA - Data retained during Deep power-down mode. */
#define PMU_DPDCTRL_GPDATA(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_DPDCTRL_GPDATA_SHIFT)) & PMU_DPDCTRL_GPDATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMU_Register_Masks */


/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


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


#endif  /* PERI_PMU_H_ */

