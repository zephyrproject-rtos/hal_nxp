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
**         CMSIS Peripheral Access Layer for PMC
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
 * @file PERI_PMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Power Management Control, offset: 0x0 */
  __I  uint32_t STATUS;                            /**< PMC status, offset: 0x4 */
  __IO uint32_t RESETCTRL;                         /**< Reset Control, offset: 0x8 */
  __IO uint32_t RESETCAUSE;                        /**< Reset Cause, offset: 0xC */
  __IO uint32_t DCDC0;                             /**< DCDC (first) control, offset: 0x10 */
  __IO uint32_t DCDC1;                             /**< DCDC (second) control register, offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t LDOPMU;                            /**< LDO control, offset: 0x1C */
  __IO uint32_t LDOMEM;                            /**< Memory LDO control, offset: 0x20 */
  __IO uint32_t LDOCORE0;                          /**< LDO CORE control 0, offset: 0x24 */
  __IO uint32_t LDOFLASHNV;                        /**< LDO Flash High Voltage control, offset: 0x28 */
  __IO uint32_t LDOEFUSEPROG;                      /**< OTP-eFUSE (One Time Programmable Memory) Programming LDO control, offset: 0x2C */
  __IO uint32_t BODVDDMAIN;                        /**< VDDMAIN Brown Out Dectector control, offset: 0x30 */
       uint8_t RESERVED_1[4];
  __IO uint32_t BODCORE;                           /**< Digital Core logic Brown Out Dectector control, offset: 0x38 */
       uint8_t RESERVED_2[4];
  __IO uint32_t REFFASTWKUP;                       /**< Analog References fast wake-up Control, offset: 0x40 */
       uint8_t RESERVED_3[8];
  __IO uint32_t XTAL32K;                           /**< 32 KHz Crystal oscillator (XTAL) control, offset: 0x4C */
  __IO uint32_t COMP;                              /**< Analog Comparator control, offset: 0x50 */
       uint8_t RESERVED_4[12];
  __O  uint32_t CMD;                               /**< DCDC and LDOCORE power state (enable/disable) control., offset: 0x60 */
  __IO uint32_t WAKEUPIOCTRL;                      /**< Wake-up IO control, offset: 0x64 */
  __IO uint32_t WAKEIOCAUSE;                       /**< Wake-up I/O source, offset: 0x68 */
  __IO uint32_t LIFECYCLESTATE;                    /**< Life Cycle State, offset: 0x6C */
  __I  uint32_t STATUSPWR;                         /**< Power status, offset: 0x70 */
  __IO uint32_t STATUSCLK;                         /**< Clock status, offset: 0x74 */
       uint8_t RESERVED_5[8];
  __IO uint32_t AOREG0;                            /**< Always-on 0, offset: 0x80 */
  __IO uint32_t AOREG1;                            /**< Always-on 1, offset: 0x84 */
       uint8_t RESERVED_6[8];
  __IO uint32_t MISCCTRL;                          /**< Miscellaneous control, offset: 0x90 */
       uint8_t RESERVED_7[4];
  __IO uint32_t RTCOSC32K;                         /**< 32 KHz clocks source control, offset: 0x98 */
  __IO uint32_t OSEVENTTIMER;                      /**< OS Event Timer control, offset: 0x9C */
  __IO uint32_t PDSLEEPCFG1;                       /**< Power down sleep configuration 1, offset: 0xA0 */
  __IO uint32_t TIMEOUTEVENTS;                     /**< Time-out events, offset: 0xA4 */
       uint8_t RESERVED_8[8];
  __IO uint32_t PDSLEEPCFG0;                       /**< Power down sleep configuration 0, offset: 0xB0 */
  __IO uint32_t SRAMRETCTRL;                       /**< SRAM control, offset: 0xB4 */
  __IO uint32_t PDRUNCFG0;                         /**< Power down run configuration 0, offset: 0xB8 */
  __IO uint32_t PDRUNCFG1;                         /**< Power down run configuration 1, offset: 0xBC */
  __O  uint32_t PDRUNCFGSET0;                      /**< Power down run configuration set 0, offset: 0xC0 */
  __O  uint32_t PDRUNCFGSET1;                      /**< Power down run configuration set 1, offset: 0xC4 */
  __O  uint32_t PDRUNCFGCLR0;                      /**< Power down run configuration clear 0, offset: 0xC8 */
  __O  uint32_t PDRUNCFGCLR1;                      /**< Power down run configuration clear 1, offset: 0xCC */
       uint8_t RESERVED_9[4];
  __IO uint32_t SRAMCTRL;                          /**< SRAM control, offset: 0xD4 */
  __IO uint32_t SRAMCTRL0;                         /**< SRAM control 0, offset: 0xD8 */
  __IO uint32_t SRAMCTRL1;                         /**< SRAM control 1, offset: 0xDC */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name CTRL - Power Management Control */
/*! @{ */

#define PMC_CTRL_LPMODE_MASK                     (0x3U)
#define PMC_CTRL_LPMODE_SHIFT                    (0U)
/*! LPMODE - Power Mode Control.
 *  0b00..ACTIVE power mode.
 *  0b01..DEEP-SLEEP low power mode.
 *  0b10..POWER-DOWN low power mode.
 *  0b11..DEEP-POWER-DOWN low power mode.
 */
#define PMC_CTRL_LPMODE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LPMODE_SHIFT)) & PMC_CTRL_LPMODE_MASK)

#define PMC_CTRL_SELCLOCK_MASK                   (0x4U)
#define PMC_CTRL_SELCLOCK_SHIFT                  (2U)
/*! SELCLOCK - Select the Power Management Controller (PMC) functional clock :
 *  0b0..1 MHz Free Running Oscillator.
 *  0b1..12 MHz Free Running Oscillator.
 */
#define PMC_CTRL_SELCLOCK(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_SELCLOCK_SHIFT)) & PMC_CTRL_SELCLOCK_MASK)

#define PMC_CTRL_SELMEMSUPPLY_MASK               (0x8U)
#define PMC_CTRL_SELMEMSUPPLY_SHIFT              (3U)
/*! SELMEMSUPPLY - Select Memories supply source in DEEP-SLEEP low power mode: Note: in POWER-DOWN
 *    and DEEP-POWER-DOWN, memories are always supplied by LDO_MEM.
 *  0b0..Memories are supplied by LDO_MEM in 'DEEP-SLEEP' low power mode.
 *  0b1..Memories are supplied by DCDC/LDO_CORE in 'DEEP-SLEEP' low power mode.
 */
#define PMC_CTRL_SELMEMSUPPLY(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_SELMEMSUPPLY_SHIFT)) & PMC_CTRL_SELMEMSUPPLY_MASK)

#define PMC_CTRL_SELCORESUPPLYWK_MASK            (0x10U)
#define PMC_CTRL_SELCORESUPPLYWK_SHIFT           (4U)
/*! SELCORESUPPLYWK - Select Core Logic supply source when waking up from DEEP-SLEEP and POWER-DOWN low power modes :
 *  0b0..Core Logic is supplied by DCDC Converter.
 *  0b1..Core Logic is supplied by LDO CORE (configured in High Power mode).
 */
#define PMC_CTRL_SELCORESUPPLYWK(x)              (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_SELCORESUPPLYWK_SHIFT)) & PMC_CTRL_SELCORESUPPLYWK_MASK)

#define PMC_CTRL_DEEPSLEEPCORESUPPLY_MASK        (0x60U)
#define PMC_CTRL_DEEPSLEEPCORESUPPLY_SHIFT       (5U)
/*! DEEPSLEEPCORESUPPLY - Select Core Logic supply source during DEEP-SLEEP low power mode :
 *  0b00..LDO CORE in Low Power Mode.
 *  0b01..LDO CORE in High Power Mode.
 *  0b10..DCDC Converter.
 */
#define PMC_CTRL_DEEPSLEEPCORESUPPLY(x)          (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_DEEPSLEEPCORESUPPLY_SHIFT)) & PMC_CTRL_DEEPSLEEPCORESUPPLY_MASK)
/*! @} */

/*! @name STATUS - PMC status */
/*! @{ */

#define PMC_STATUS_BOOTMODE_MASK                 (0xC0000U)
#define PMC_STATUS_BOOTMODE_SHIFT                (18U)
/*! BOOTMODE - Latest IC Boot cause:.
 *  0b00..Latest IC boot was a Full power cycle boot sequence (PoR, Pin Reset, Brown Out Detectors Reset, Software Reset).
 *  0b01..Latest IC boot was from DEEP-SLEEP low power mode.
 *  0b10..Latest IC boot was from POWER-DOWN low power mode.
 *  0b11..Latest IC boot was from DEEP-POWER-DOWN low power mode.
 */
#define PMC_STATUS_BOOTMODE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_BOOTMODE_SHIFT)) & PMC_STATUS_BOOTMODE_MASK)

#define PMC_STATUS_FSMDCDCENABLE_MASK            (0x100000U)
#define PMC_STATUS_FSMDCDCENABLE_SHIFT           (20U)
/*! FSMDCDCENABLE - Indicates the power status of the DCDC (enabled or disabled) as driven by the Hardware Finite State Machines (FSM).
 *  0b0..DCDC is currently disabled by the Hardware Finite State Machine (FSM).
 *  0b1..DCDC is currently enabled by the Hardware Finite State Machine (FSM).
 */
#define PMC_STATUS_FSMDCDCENABLE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMDCDCENABLE_SHIFT)) & PMC_STATUS_FSMDCDCENABLE_MASK)

#define PMC_STATUS_FSMLDOCOREHPENABLE_MASK       (0x200000U)
#define PMC_STATUS_FSMLDOCOREHPENABLE_SHIFT      (21U)
/*! FSMLDOCOREHPENABLE - Indicates the power status of the LDO CORE High Power Mode (enabled or
 *    disabled) as driven by the Hardware Finite State Machines (FSM).
 *  0b0..LDO CORE High Power Mode is currently disabled by the Hardware Finite State Machine (FSM).
 *  0b1..LDO CORE High Power Mode is currently enabled by the Hardware Finite State Machine (FSM).
 */
#define PMC_STATUS_FSMLDOCOREHPENABLE(x)         (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMLDOCOREHPENABLE_SHIFT)) & PMC_STATUS_FSMLDOCOREHPENABLE_MASK)

#define PMC_STATUS_FSMLDOCORELPENABLE_MASK       (0x400000U)
#define PMC_STATUS_FSMLDOCORELPENABLE_SHIFT      (22U)
/*! FSMLDOCORELPENABLE - Indicates the power status of the LDO CORE Low Power Mode (enabled or
 *    disabled) as driven by the Hardware Finite State Machines (FSM).
 *  0b0..LDO CORE Low Power Mode is currently disabled by the Hardware Finite State Machine (FSM).
 *  0b1..LDO CORE Low Power Mode is currently enabled by the Hardware Finite State Machine (FSM).
 */
#define PMC_STATUS_FSMLDOCORELPENABLE(x)         (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMLDOCORELPENABLE_SHIFT)) & PMC_STATUS_FSMLDOCORELPENABLE_MASK)

#define PMC_STATUS_FSMLDOCOREEXPTMRENABLE_MASK   (0x800000U)
#define PMC_STATUS_FSMLDOCOREEXPTMRENABLE_SHIFT  (23U)
/*! FSMLDOCOREEXPTMRENABLE - Indicates the status of the LDO CORE Exponential Timer (enabled or
 *    disabled) as driven by the Hardware Finite State Machines (FSM).
 */
#define PMC_STATUS_FSMLDOCOREEXPTMRENABLE(x)     (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMLDOCOREEXPTMRENABLE_SHIFT)) & PMC_STATUS_FSMLDOCOREEXPTMRENABLE_MASK)
/*! @} */

/*! @name RESETCTRL - Reset Control */
/*! @{ */

#define PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK  (0x1U)
#define PMC_RESETCTRL_DPDWAKEUPRESETENABLE_SHIFT (0U)
/*! DPDWAKEUPRESETENABLE - Wake-up from DEEP-POWER-DOWN reset event (either from wake up I/O or RTC or OS Event Timer).
 *  0b0..Reset event from DEEP-POWER-DOWN mode is disabled.
 *  0b1..Reset event from DEEP-POWER-DOWN mode is enabled.
 */
#define PMC_RESETCTRL_DPDWAKEUPRESETENABLE(x)    (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_DPDWAKEUPRESETENABLE_SHIFT)) & PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK)

#define PMC_RESETCTRL_SWRRESETENABLE_MASK        (0x8U)
#define PMC_RESETCTRL_SWRRESETENABLE_SHIFT       (3U)
/*! SWRRESETENABLE - Software reset enable.
 *  0b0..Software reset is disabled.
 *  0b1..Software reset is enabled.
 */
#define PMC_RESETCTRL_SWRRESETENABLE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_SWRRESETENABLE_SHIFT)) & PMC_RESETCTRL_SWRRESETENABLE_MASK)

#define PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_MASK (0x30U)
#define PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_SHIFT (4U)
/*! BODVDDMAINRESETENA_SECURE - BOD_VDDMAIN reset enabled.
 *  0b01..And any other value than b10: BOD_VDDMAIN reset is enabled.
 *  0b10..BOD_VDDMAIN reset is disabled.
 */
#define PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE(x) (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_SHIFT)) & PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_MASK)

#define PMC_RESETCTRL_BODCORERESETENA_SECURE_MASK (0xC0U)
#define PMC_RESETCTRL_BODCORERESETENA_SECURE_SHIFT (6U)
/*! BODCORERESETENA_SECURE - BOD_CORE reset enabled.
 *  0b01..And any other value than b10: BOD_CORE reset is enabled.
 *  0b10..BODCORE reset is disabled.
 */
#define PMC_RESETCTRL_BODCORERESETENA_SECURE(x)  (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BODCORERESETENA_SECURE_SHIFT)) & PMC_RESETCTRL_BODCORERESETENA_SECURE_MASK)

#define PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_DP_MASK (0x30000000U)
#define PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_DP_SHIFT (28U)
/*! BODVDDMAINRESETENA_SECURE_DP - BOD_VDDMAIN reset enabled.
 *  0b01..And any other value than b10: BOD_VDDMAIN reset is enabled.
 *  0b10..BOD_VDDMAIN reset is disabled.
 */
#define PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_DP(x) (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_DP_SHIFT)) & PMC_RESETCTRL_BODVDDMAINRESETENA_SECURE_DP_MASK)

#define PMC_RESETCTRL_BODCORERESETENA_SECURE_DP_MASK (0xC0000000U)
#define PMC_RESETCTRL_BODCORERESETENA_SECURE_DP_SHIFT (30U)
/*! BODCORERESETENA_SECURE_DP - BOD_CORE reset enable.
 *  0b01..And any other value than b10: BOD_CORE reset is enabled.
 *  0b10..BOD_CORE reset is disabled.
 */
#define PMC_RESETCTRL_BODCORERESETENA_SECURE_DP(x) (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BODCORERESETENA_SECURE_DP_SHIFT)) & PMC_RESETCTRL_BODCORERESETENA_SECURE_DP_MASK)
/*! @} */

/*! @name RESETCAUSE - Reset Cause */
/*! @{ */

#define PMC_RESETCAUSE_POR_MASK                  (0x1U)
#define PMC_RESETCAUSE_POR_SHIFT                 (0U)
/*! POR - 1 : The last chip reset was caused by a Power On Reset. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_POR(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_POR_SHIFT)) & PMC_RESETCAUSE_POR_MASK)

#define PMC_RESETCAUSE_PADRESET_MASK             (0x2U)
#define PMC_RESETCAUSE_PADRESET_SHIFT            (1U)
/*! PADRESET - 1 : The last chip reset was caused by a Pin Reset. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_PADRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_PADRESET_SHIFT)) & PMC_RESETCAUSE_PADRESET_MASK)

#define PMC_RESETCAUSE_BODRESET_MASK             (0x4U)
#define PMC_RESETCAUSE_BODRESET_SHIFT            (2U)
/*! BODRESET - 1 : The last chip reset was caused by a Brown Out Detector (BoD), either BOD_VDDMAIN
 *    or BOD_CORE. Write '1' to clear this bit.
 */
#define PMC_RESETCAUSE_BODRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_BODRESET_SHIFT)) & PMC_RESETCAUSE_BODRESET_MASK)

#define PMC_RESETCAUSE_SYSTEMRESET_MASK          (0x8U)
#define PMC_RESETCAUSE_SYSTEMRESET_SHIFT         (3U)
/*! SYSTEMRESET - 1 : The last chip reset was caused by a System Reset requested by the ARM CPU. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_SYSTEMRESET(x)            (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_SYSTEMRESET_SHIFT)) & PMC_RESETCAUSE_SYSTEMRESET_MASK)

#define PMC_RESETCAUSE_WDTRESET_MASK             (0x10U)
#define PMC_RESETCAUSE_WDTRESET_SHIFT            (4U)
/*! WDTRESET - 1 : The last chip reset was caused by the Watchdog Timer. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_WDTRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_WDTRESET_SHIFT)) & PMC_RESETCAUSE_WDTRESET_MASK)

#define PMC_RESETCAUSE_SWRRESET_MASK             (0x20U)
#define PMC_RESETCAUSE_SWRRESET_SHIFT            (5U)
/*! SWRRESET - 1 : The last chip reset was caused by a Software. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_SWRRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_SWRRESET_SHIFT)) & PMC_RESETCAUSE_SWRRESET_MASK)

#define PMC_RESETCAUSE_DPDRESET_WAKEUPIO_MASK    (0x40U)
#define PMC_RESETCAUSE_DPDRESET_WAKEUPIO_SHIFT   (6U)
/*! DPDRESET_WAKEUPIO - 1 : A Wake-up I/O reset event occured during DEEP-POWER-DOWN mode. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_DPDRESET_WAKEUPIO(x)      (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPDRESET_WAKEUPIO_SHIFT)) & PMC_RESETCAUSE_DPDRESET_WAKEUPIO_MASK)

#define PMC_RESETCAUSE_DPDRESET_RTC_MASK         (0x80U)
#define PMC_RESETCAUSE_DPDRESET_RTC_SHIFT        (7U)
/*! DPDRESET_RTC - 1 : A RTC (either RTC Alarm or RTC wake up) reset event occured during
 *    DEEP-POWER-DOWN mode. Write '1' to clear this bit.
 */
#define PMC_RESETCAUSE_DPDRESET_RTC(x)           (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPDRESET_RTC_SHIFT)) & PMC_RESETCAUSE_DPDRESET_RTC_MASK)

#define PMC_RESETCAUSE_DPDRESET_OSTIMER_MASK     (0x100U)
#define PMC_RESETCAUSE_DPDRESET_OSTIMER_SHIFT    (8U)
/*! DPDRESET_OSTIMER - 1 : A OS Event Timer reset event occured during DEEP-POWER-DOWN mode. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_DPDRESET_OSTIMER(x)       (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPDRESET_OSTIMER_SHIFT)) & PMC_RESETCAUSE_DPDRESET_OSTIMER_MASK)

#define PMC_RESETCAUSE_CDOGRESET_MASK            (0x200U)
#define PMC_RESETCAUSE_CDOGRESET_SHIFT           (9U)
/*! CDOGRESET - 1 : The last chip reset was caused by the code Watchdog. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_CDOGRESET(x)              (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_CDOGRESET_SHIFT)) & PMC_RESETCAUSE_CDOGRESET_MASK)

#define PMC_RESETCAUSE_DPD_EVENTS_ORDER_MASK     (0x1C00U)
#define PMC_RESETCAUSE_DPD_EVENTS_ORDER_SHIFT    (10U)
/*! DPD_EVENTS_ORDER - In DEEP-POWER-DOWN mode, indicates which reset event occured first between
 *    DPDRESET_WAKEUPIO, DPDRESET_RTC and DPDRESET_OSTIMER. Write 'b001' to clear these bit field.
 *  0b000..No event
 *  0b001..WAKEUPIO
 *  0b010..RTC
 *  0b011..Both WAKEUPIO and RTC events occured at the same time (less than 1 nano-second from each other)
 *  0b100..OSTIMER
 *  0b101..Both WAKEUPIO and OSTIMER events occured at the same time (less than 1 nano-second from each other)
 *  0b110..Both RTC and OSTIMER events occured at the same time (less than 1 nano-second from each other)
 *  0b111..WAKEUPIO, RTC and OSTIMER events occured at the same time (less than 1 nano-second from each other)
 */
#define PMC_RESETCAUSE_DPD_EVENTS_ORDER(x)       (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPD_EVENTS_ORDER_SHIFT)) & PMC_RESETCAUSE_DPD_EVENTS_ORDER_MASK)
/*! @} */

/*! @name DCDC0 - DCDC (first) control */
/*! @{ */

#define PMC_DCDC0_RC_MASK                        (0x3FU)
#define PMC_DCDC0_RC_SHIFT                       (0U)
/*! RC - Constant On-Time calibration. */
#define PMC_DCDC0_RC(x)                          (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_RC_SHIFT)) & PMC_DCDC0_RC_MASK)

#define PMC_DCDC0_ICOMP_MASK                     (0xC0U)
#define PMC_DCDC0_ICOMP_SHIFT                    (6U)
/*! ICOMP - Select the type of ZCD comparator. */
#define PMC_DCDC0_ICOMP(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_ICOMP_SHIFT)) & PMC_DCDC0_ICOMP_MASK)

#define PMC_DCDC0_ISEL_MASK                      (0x300U)
#define PMC_DCDC0_ISEL_SHIFT                     (8U)
/*! ISEL - Alter Internal biasing currents. */
#define PMC_DCDC0_ISEL(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_ISEL_SHIFT)) & PMC_DCDC0_ISEL_MASK)

#define PMC_DCDC0_ICENABLE_MASK                  (0x400U)
#define PMC_DCDC0_ICENABLE_SHIFT                 (10U)
/*! ICENABLE - Selection of auto scaling of COT period with variations in VDD. */
#define PMC_DCDC0_ICENABLE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_ICENABLE_SHIFT)) & PMC_DCDC0_ICENABLE_MASK)

#define PMC_DCDC0_TMOS_MASK                      (0xF800U)
#define PMC_DCDC0_TMOS_SHIFT                     (11U)
/*! TMOS - One-shot generator reference current trimming signal. */
#define PMC_DCDC0_TMOS(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_TMOS_SHIFT)) & PMC_DCDC0_TMOS_MASK)

#define PMC_DCDC0_DISABLEISENSE_MASK             (0x10000U)
#define PMC_DCDC0_DISABLEISENSE_SHIFT            (16U)
/*! DISABLEISENSE - Disable Current sensing. */
#define PMC_DCDC0_DISABLEISENSE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_DISABLEISENSE_SHIFT)) & PMC_DCDC0_DISABLEISENSE_MASK)

#define PMC_DCDC0_VOUT_MASK                      (0x1E0000U)
#define PMC_DCDC0_VOUT_SHIFT                     (17U)
/*! VOUT - Set output regulation voltage.
 *  0b0000..0.95 V.
 *  0b0001..0.975 V.
 *  0b0010..1 V.
 *  0b0011..1.025 V.
 *  0b0100..1.05 V.
 *  0b0101..1.075 V.
 *  0b0110..1.1 V.
 *  0b0111..1.125 V.
 *  0b1000..1.15 V.
 *  0b1001..1.175 V.
 *  0b1010..1.2 V.
 */
#define PMC_DCDC0_VOUT(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_VOUT_SHIFT)) & PMC_DCDC0_VOUT_MASK)

#define PMC_DCDC0_SLICINGENABLE_MASK             (0x200000U)
#define PMC_DCDC0_SLICINGENABLE_SHIFT            (21U)
/*! SLICINGENABLE - Enable staggered switching of power switches. */
#define PMC_DCDC0_SLICINGENABLE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_SLICINGENABLE_SHIFT)) & PMC_DCDC0_SLICINGENABLE_MASK)

#define PMC_DCDC0_INDUCTORCLAMPENABLE_MASK       (0x400000U)
#define PMC_DCDC0_INDUCTORCLAMPENABLE_SHIFT      (22U)
/*! INDUCTORCLAMPENABLE - Enable shorting of Inductor during PFM idle time. */
#define PMC_DCDC0_INDUCTORCLAMPENABLE(x)         (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_INDUCTORCLAMPENABLE_SHIFT)) & PMC_DCDC0_INDUCTORCLAMPENABLE_MASK)

#define PMC_DCDC0_VOUT_PWD_MASK                  (0x7800000U)
#define PMC_DCDC0_VOUT_PWD_SHIFT                 (23U)
/*! VOUT_PWD - Set output regulation voltage during Deep Sleep. */
#define PMC_DCDC0_VOUT_PWD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_VOUT_PWD_SHIFT)) & PMC_DCDC0_VOUT_PWD_MASK)
/*! @} */

/*! @name DCDC1 - DCDC (second) control register */
/*! @{ */

#define PMC_DCDC1_RTRIMOFFET_MASK                (0xFU)
#define PMC_DCDC1_RTRIMOFFET_SHIFT               (0U)
/*! RTRIMOFFET - Adjust the offset voltage of BJT based comparator. */
#define PMC_DCDC1_RTRIMOFFET(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_RTRIMOFFET_SHIFT)) & PMC_DCDC1_RTRIMOFFET_MASK)

#define PMC_DCDC1_RSENSETRIM_MASK                (0xF0U)
#define PMC_DCDC1_RSENSETRIM_SHIFT               (4U)
/*! RSENSETRIM - Adjust Max inductor peak current limiting. */
#define PMC_DCDC1_RSENSETRIM(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_RSENSETRIM_SHIFT)) & PMC_DCDC1_RSENSETRIM_MASK)

#define PMC_DCDC1_DTESTENABLE_MASK               (0x100U)
#define PMC_DCDC1_DTESTENABLE_SHIFT              (8U)
/*! DTESTENABLE - Enable Digital test signals. */
#define PMC_DCDC1_DTESTENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_DTESTENABLE_SHIFT)) & PMC_DCDC1_DTESTENABLE_MASK)

#define PMC_DCDC1_SETCURVE_MASK                  (0x600U)
#define PMC_DCDC1_SETCURVE_SHIFT                 (9U)
/*! SETCURVE - Bandgap calibration parameter. */
#define PMC_DCDC1_SETCURVE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_SETCURVE_SHIFT)) & PMC_DCDC1_SETCURVE_MASK)

#define PMC_DCDC1_SETDC_MASK                     (0x7800U)
#define PMC_DCDC1_SETDC_SHIFT                    (11U)
/*! SETDC - Bandgap calibration parameter. */
#define PMC_DCDC1_SETDC(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_SETDC_SHIFT)) & PMC_DCDC1_SETDC_MASK)

#define PMC_DCDC1_DTESTSEL_MASK                  (0x38000U)
#define PMC_DCDC1_DTESTSEL_SHIFT                 (15U)
/*! DTESTSEL - Select the output signal for test. */
#define PMC_DCDC1_DTESTSEL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_DTESTSEL_SHIFT)) & PMC_DCDC1_DTESTSEL_MASK)

#define PMC_DCDC1_ISCALEENABLE_MASK              (0x40000U)
#define PMC_DCDC1_ISCALEENABLE_SHIFT             (18U)
/*! ISCALEENABLE - Modify COT behavior. */
#define PMC_DCDC1_ISCALEENABLE(x)                (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_ISCALEENABLE_SHIFT)) & PMC_DCDC1_ISCALEENABLE_MASK)

#define PMC_DCDC1_FORCEBYPASS_MASK               (0x80000U)
#define PMC_DCDC1_FORCEBYPASS_SHIFT              (19U)
/*! FORCEBYPASS - Force bypass mode. */
#define PMC_DCDC1_FORCEBYPASS(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_FORCEBYPASS_SHIFT)) & PMC_DCDC1_FORCEBYPASS_MASK)

#define PMC_DCDC1_TRIMAUTOCOT_MASK               (0xF00000U)
#define PMC_DCDC1_TRIMAUTOCOT_SHIFT              (20U)
/*! TRIMAUTOCOT - Change the scaling ratio of the feedforward compensation. */
#define PMC_DCDC1_TRIMAUTOCOT(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_TRIMAUTOCOT_SHIFT)) & PMC_DCDC1_TRIMAUTOCOT_MASK)

#define PMC_DCDC1_FORCEFULLCYCLE_MASK            (0x1000000U)
#define PMC_DCDC1_FORCEFULLCYCLE_SHIFT           (24U)
/*! FORCEFULLCYCLE - Force full PFM PMOS and NMOS cycle. */
#define PMC_DCDC1_FORCEFULLCYCLE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_FORCEFULLCYCLE_SHIFT)) & PMC_DCDC1_FORCEFULLCYCLE_MASK)

#define PMC_DCDC1_LCENABLE_MASK                  (0x2000000U)
#define PMC_DCDC1_LCENABLE_SHIFT                 (25U)
/*! LCENABLE - Change the range of the peak detector of current inside the inductor. */
#define PMC_DCDC1_LCENABLE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_LCENABLE_SHIFT)) & PMC_DCDC1_LCENABLE_MASK)

#define PMC_DCDC1_TOFF_MASK                      (0x7C000000U)
#define PMC_DCDC1_TOFF_SHIFT                     (26U)
/*! TOFF - Constant Off-Time calibration input. */
#define PMC_DCDC1_TOFF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_TOFF_SHIFT)) & PMC_DCDC1_TOFF_MASK)

#define PMC_DCDC1_TOFFENABLE_MASK                (0x80000000U)
#define PMC_DCDC1_TOFFENABLE_SHIFT               (31U)
/*! TOFFENABLE - Enable Constant Off-Time feature. */
#define PMC_DCDC1_TOFFENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_DCDC1_TOFFENABLE_SHIFT)) & PMC_DCDC1_TOFFENABLE_MASK)
/*! @} */

/*! @name LDOPMU - LDO control */
/*! @{ */

#define PMC_LDOPMU_VADJ_MASK                     (0x1FU)
#define PMC_LDOPMU_VADJ_SHIFT                    (0U)
/*! VADJ - Sets the Always-On domain LDO output level.
 *  0b00000..1.22 V.
 *  0b00001..0.7 V.
 *  0b00010..0.725 V.
 *  0b00011..0.75 V.
 *  0b00100..0.775 V.
 *  0b00101..0.8 V.
 *  0b00110..0.825 V.
 *  0b00111..0.85 V.
 *  0b01000..0.875 V.
 *  0b01001..0.9 V.
 *  0b01010..0.96 V.
 *  0b01011..0.97 V.
 *  0b01100..0.98 V.
 *  0b01101..0.99 V.
 *  0b01110..1 V.
 *  0b01111..1.01 V.
 *  0b10000..1.02 V.
 *  0b10001..1.03 V.
 *  0b10010..1.04 V.
 *  0b10011..1.05 V.
 *  0b10100..1.06 V.
 *  0b10101..1.07 V.
 *  0b10110..1.08 V.
 *  0b10111..1.09 V.
 *  0b11000..1.1 V.
 *  0b11001..1.11 V.
 *  0b11010..1.12 V.
 *  0b11011..1.13 V.
 *  0b11100..1.14 V.
 *  0b11101..1.15 V.
 *  0b11110..1.16 V.
 *  0b11111..1.22 V.
 */
#define PMC_LDOPMU_VADJ(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LDOPMU_VADJ_SHIFT)) & PMC_LDOPMU_VADJ_MASK)

#define PMC_LDOPMU_VADJ_PWD_MASK                 (0x3E0U)
#define PMC_LDOPMU_VADJ_PWD_SHIFT                (5U)
/*! VADJ_PWD - Sets the Always-On domain LDO output level in all power down modes. */
#define PMC_LDOPMU_VADJ_PWD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_LDOPMU_VADJ_PWD_SHIFT)) & PMC_LDOPMU_VADJ_PWD_MASK)

#define PMC_LDOPMU_VADJ_BOOST_MASK               (0x7C00U)
#define PMC_LDOPMU_VADJ_BOOST_SHIFT              (10U)
/*! VADJ_BOOST - Sets the Always-On domain LDO Boost output level. */
#define PMC_LDOPMU_VADJ_BOOST(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOPMU_VADJ_BOOST_SHIFT)) & PMC_LDOPMU_VADJ_BOOST_MASK)

#define PMC_LDOPMU_VADJ_BOOST_PWD_MASK           (0xF8000U)
#define PMC_LDOPMU_VADJ_BOOST_PWD_SHIFT          (15U)
/*! VADJ_BOOST_PWD - Sets the Always-On domain LDO Boost output level in all power down modes. */
#define PMC_LDOPMU_VADJ_BOOST_PWD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_LDOPMU_VADJ_BOOST_PWD_SHIFT)) & PMC_LDOPMU_VADJ_BOOST_PWD_MASK)
/*! @} */

/*! @name LDOMEM - Memory LDO control */
/*! @{ */

#define PMC_LDOMEM_VADJ_MASK                     (0x1FU)
#define PMC_LDOMEM_VADJ_SHIFT                    (0U)
/*! VADJ - Sets the Memories LDO output level.
 *  0b00000..1.22 V.
 *  0b00001..0.7 V.
 *  0b00010..0.725 V.
 *  0b00011..0.75 V.
 *  0b00100..0.775 V.
 *  0b00101..0.8 V.
 *  0b00110..0.825 V.
 *  0b00111..0.85 V.
 *  0b01000..0.875 V.
 *  0b01001..0.9 V.
 *  0b01010..0.96 V.
 *  0b01011..0.97 V.
 *  0b01100..0.98 V.
 *  0b01101..0.99 V.
 *  0b01110..1 V.
 *  0b01111..1.01 V.
 *  0b10000..1.02 V.
 *  0b10001..1.03 V.
 *  0b10010..1.04 V.
 *  0b10011..1.05 V.
 *  0b10100..1.06 V.
 *  0b10101..1.07 V.
 *  0b10110..1.08 V.
 *  0b10111..1.09 V.
 *  0b11000..1.1 V.
 *  0b11001..1.11 V.
 *  0b11010..1.12 V.
 *  0b11011..1.13 V.
 *  0b11100..1.14 V.
 *  0b11101..1.15 V.
 *  0b11110..1.16 V.
 *  0b11111..1.22 V.
 */
#define PMC_LDOMEM_VADJ(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LDOMEM_VADJ_SHIFT)) & PMC_LDOMEM_VADJ_MASK)

#define PMC_LDOMEM_VADJ_PWD_MASK                 (0x3E0U)
#define PMC_LDOMEM_VADJ_PWD_SHIFT                (5U)
/*! VADJ_PWD - Sets the Memories LDO output level in all power down modes. */
#define PMC_LDOMEM_VADJ_PWD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_LDOMEM_VADJ_PWD_SHIFT)) & PMC_LDOMEM_VADJ_PWD_MASK)

#define PMC_LDOMEM_VADJ_BOOST_MASK               (0x7C00U)
#define PMC_LDOMEM_VADJ_BOOST_SHIFT              (10U)
/*! VADJ_BOOST - Sets the Memories LDO Boost output level. */
#define PMC_LDOMEM_VADJ_BOOST(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOMEM_VADJ_BOOST_SHIFT)) & PMC_LDOMEM_VADJ_BOOST_MASK)

#define PMC_LDOMEM_VADJ_BOOST_PWD_MASK           (0xF8000U)
#define PMC_LDOMEM_VADJ_BOOST_PWD_SHIFT          (15U)
/*! VADJ_BOOST_PWD - Sets the Memories LDO Boost output level in all power down modes. */
#define PMC_LDOMEM_VADJ_BOOST_PWD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_LDOMEM_VADJ_BOOST_PWD_SHIFT)) & PMC_LDOMEM_VADJ_BOOST_PWD_MASK)
/*! @} */

/*! @name LDOCORE0 - LDO CORE control 0 */
/*! @{ */

#define PMC_LDOCORE0_LPREGREFSEL_MASK            (0x60000U)
#define PMC_LDOCORE0_LPREGREFSEL_SHIFT           (17U)
/*! LPREGREFSEL - Low Power regulation point select.
 *  0b00..900 mV.
 *  0b01..850 mV.
 *  0b10..800 mV.
 *  0b11..750 mV.
 */
#define PMC_LDOCORE0_LPREGREFSEL(x)              (((uint32_t)(((uint32_t)(x)) << PMC_LDOCORE0_LPREGREFSEL_SHIFT)) & PMC_LDOCORE0_LPREGREFSEL_MASK)

#define PMC_LDOCORE0_REGREFTRIM_MASK             (0x7F000000U)
#define PMC_LDOCORE0_REGREFTRIM_SHIFT            (24U)
/*! REGREFTRIM - High Power regulation point select. */
#define PMC_LDOCORE0_REGREFTRIM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_LDOCORE0_REGREFTRIM_SHIFT)) & PMC_LDOCORE0_REGREFTRIM_MASK)
/*! @} */

/*! @name LDOFLASHNV - LDO Flash High Voltage control */
/*! @{ */

#define PMC_LDOFLASHNV_VADJ_MASK                 (0x7U)
#define PMC_LDOFLASHNV_VADJ_SHIFT                (0U)
/*! VADJ - Sets the LDO output level.
 *  0b000..1.650 V.
 *  0b001..1.700 V.
 *  0b010..1.750 V.
 *  0b011..1.800 V.
 *  0b100..1.850 V.
 *  0b101..1.900 V.
 *  0b110..1.950 V.
 *  0b111..2.0 V.
 */
#define PMC_LDOFLASHNV_VADJ(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_LDOFLASHNV_VADJ_SHIFT)) & PMC_LDOFLASHNV_VADJ_MASK)
/*! @} */

/*! @name LDOEFUSEPROG - OTP-eFUSE (One Time Programmable Memory) Programming LDO control */
/*! @{ */

#define PMC_LDOEFUSEPROG_VADJ_MASK               (0x7U)
#define PMC_LDOEFUSEPROG_VADJ_SHIFT              (0U)
/*! VADJ - Sets the LDO output level.
 *  0b000..1.650 V.
 *  0b001..1.700 V.
 *  0b010..1.750 V.
 *  0b011..1.800 V.
 *  0b100..1.850 V.
 *  0b101..1.900 V.
 *  0b110..1.950 V.
 *  0b111..2.0 V.
 */
#define PMC_LDOEFUSEPROG_VADJ(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOEFUSEPROG_VADJ_SHIFT)) & PMC_LDOEFUSEPROG_VADJ_MASK)
/*! @} */

/*! @name BODVDDMAIN - VDDMAIN Brown Out Dectector control */
/*! @{ */

#define PMC_BODVDDMAIN_TRIGLVL_MASK              (0x1FU)
#define PMC_BODVDDMAIN_TRIGLVL_SHIFT             (0U)
/*! TRIGLVL - BoD trigger level.
 *  0b00000-0b01000..
 *  0b01001..1.75 V.
 *  0b01010..1.80 V.
 *  0b01011..1.90 V.
 *  0b01100..2.00 V.
 *  0b01101..2.10 V.
 *  0b01110..2.20 V.
 *  0b01111..2.30 V.
 *  0b10000..2.40 V.
 *  0b10001..2.50 V.
 *  0b10010..2.60 V.
 *  0b10011..2.70 V.
 *  0b10100..2.80 V.
 *  0b10101..2.90 V.
 *  0b10110..3.00 V.
 *  0b10111..3.10 V.
 *  0b11000..3.20 V.
 *  0b11001..3.30 V.
 *  0b11010..3.30 V.
 *  0b11011..3.30 V.
 *  0b11100..3.30 V.
 *  0b11101..3.30 V.
 *  0b11110..3.30 V.
 *  0b11111..3.30 V.
 */
#define PMC_BODVDDMAIN_TRIGLVL(x)                (((uint32_t)(((uint32_t)(x)) << PMC_BODVDDMAIN_TRIGLVL_SHIFT)) & PMC_BODVDDMAIN_TRIGLVL_MASK)

#define PMC_BODVDDMAIN_HYST_MASK                 (0x60U)
#define PMC_BODVDDMAIN_HYST_SHIFT                (5U)
/*! HYST - BoD Hysteresis control.
 *  0b00..25 mV.
 *  0b01..50 mV.
 *  0b10..75 mV.
 *  0b11..100 mV.
 */
#define PMC_BODVDDMAIN_HYST(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_BODVDDMAIN_HYST_SHIFT)) & PMC_BODVDDMAIN_HYST_MASK)
/*! @} */

/*! @name BODCORE - Digital Core logic Brown Out Dectector control */
/*! @{ */

#define PMC_BODCORE_TRIGLVL_MASK                 (0x7U)
#define PMC_BODCORE_TRIGLVL_SHIFT                (0U)
/*! TRIGLVL - BoD trigger level.
 *  0b000-0b101..
 *  0b110..0.90 V.
 *  0b111..0.95 V.
 */
#define PMC_BODCORE_TRIGLVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_BODCORE_TRIGLVL_SHIFT)) & PMC_BODCORE_TRIGLVL_MASK)

#define PMC_BODCORE_HYST_MASK                    (0x30U)
#define PMC_BODCORE_HYST_SHIFT                   (4U)
/*! HYST - BOD_CORE Hysteresis control.
 *  0b00..25 mV.
 *  0b01..50 mV.
 *  0b10..75 mV.
 *  0b11..100 mV.
 */
#define PMC_BODCORE_HYST(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_BODCORE_HYST_SHIFT)) & PMC_BODCORE_HYST_MASK)
/*! @} */

/*! @name REFFASTWKUP - Analog References fast wake-up Control */
/*! @{ */

#define PMC_REFFASTWKUP_LPWKUP_MASK              (0x1U)
#define PMC_REFFASTWKUP_LPWKUP_SHIFT             (0U)
/*! LPWKUP - Analog References fast wake-up in case of wake-up from a low power mode (DEEP-SLEEP, POWER-DOWN and DEEP-POWER-DOWN):
 *  0b0..Analog References fast wake-up feature is disabled in case of wake-up from any Low power mode.
 *  0b1..Analog References fast wake-up feature is enabled in case of wake-up from any Low power mode.
 */
#define PMC_REFFASTWKUP_LPWKUP(x)                (((uint32_t)(((uint32_t)(x)) << PMC_REFFASTWKUP_LPWKUP_SHIFT)) & PMC_REFFASTWKUP_LPWKUP_MASK)

#define PMC_REFFASTWKUP_HWWKUP_MASK              (0x2U)
#define PMC_REFFASTWKUP_HWWKUP_SHIFT             (1U)
/*! HWWKUP - Analog References fast wake-up in case of Hardware Pin reset:
 *  0b0..Analog References fast wake-up feature is disabled in case of Hardware Pin reset.
 *  0b1..Analog References fast wake-up feature is enabled in case of Hardware Pin reset.
 */
#define PMC_REFFASTWKUP_HWWKUP(x)                (((uint32_t)(((uint32_t)(x)) << PMC_REFFASTWKUP_HWWKUP_SHIFT)) & PMC_REFFASTWKUP_HWWKUP_MASK)
/*! @} */

/*! @name XTAL32K - 32 KHz Crystal oscillator (XTAL) control */
/*! @{ */

#define PMC_XTAL32K_TEST_MASK                    (0x8U)
#define PMC_XTAL32K_TEST_SHIFT                   (3U)
/*! TEST - Oscillator Bypass Test Mode control.
 *  0b0..Oscillation mode.
 *  0b1..Bypass test mode is enabled.
 */
#define PMC_XTAL32K_TEST(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_TEST_SHIFT)) & PMC_XTAL32K_TEST_MASK)

#define PMC_XTAL32K_CAPBANKIN_MASK               (0x7F00U)
#define PMC_XTAL32K_CAPBANKIN_SHIFT              (8U)
/*! CAPBANKIN - Capa bank setting input. */
#define PMC_XTAL32K_CAPBANKIN(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_CAPBANKIN_SHIFT)) & PMC_XTAL32K_CAPBANKIN_MASK)

#define PMC_XTAL32K_CAPBANKOUT_MASK              (0x3F8000U)
#define PMC_XTAL32K_CAPBANKOUT_SHIFT             (15U)
/*! CAPBANKOUT - Capa bank setting output. */
#define PMC_XTAL32K_CAPBANKOUT(x)                (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_CAPBANKOUT_SHIFT)) & PMC_XTAL32K_CAPBANKOUT_MASK)
/*! @} */

/*! @name COMP - Analog Comparator control */
/*! @{ */

#define PMC_COMP_HYST_MASK                       (0x2U)
#define PMC_COMP_HYST_SHIFT                      (1U)
/*! HYST - Hysteris when hyst = '1'.
 *  0b0..Hysteresis is disabled.
 *  0b1..Hysteresis is enabled.
 */
#define PMC_COMP_HYST(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_COMP_HYST_SHIFT)) & PMC_COMP_HYST_MASK)

#define PMC_COMP_VREFINPUT_MASK                  (0x4U)
#define PMC_COMP_VREFINPUT_SHIFT                 (2U)
/*! VREFINPUT - Dedicated control bit to select between internal VREF and VDDA (for the resistive ladder).
 *  0b0..Select internal VREF.
 *  0b1..Select VDDA.
 */
#define PMC_COMP_VREFINPUT(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_COMP_VREFINPUT_SHIFT)) & PMC_COMP_VREFINPUT_MASK)

#define PMC_COMP_LOWPOWER_MASK                   (0x8U)
#define PMC_COMP_LOWPOWER_SHIFT                  (3U)
/*! LOWPOWER - Low power mode.
 *  0b0..High speed mode.
 *  0b1..Low power mode (Low speed).
 */
#define PMC_COMP_LOWPOWER(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_COMP_LOWPOWER_SHIFT)) & PMC_COMP_LOWPOWER_MASK)

#define PMC_COMP_PMUX_MASK                       (0x70U)
#define PMC_COMP_PMUX_SHIFT                      (4U)
/*! PMUX - Control word for P multiplexer:.
 *  0b000..VREF (See field VREFINPUT).
 *  0b001..Pin P0_0.
 *  0b010..Pin P0_9.
 *  0b011..Pin P0_18.
 *  0b100..Pin P1_14.
 *  0b101..Reserved.
 */
#define PMC_COMP_PMUX(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_COMP_PMUX_SHIFT)) & PMC_COMP_PMUX_MASK)

#define PMC_COMP_NMUX_MASK                       (0x380U)
#define PMC_COMP_NMUX_SHIFT                      (7U)
/*! NMUX - Control word for N multiplexer:.
 *  0b000..VREF (See field VREFINPUT).
 *  0b001..Pin P0_0.
 *  0b010..Pin P0_9.
 *  0b011..Pin P0_18.
 *  0b100..Pin P1_14.
 *  0b101..Reserved.
 */
#define PMC_COMP_NMUX(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_COMP_NMUX_SHIFT)) & PMC_COMP_NMUX_MASK)

#define PMC_COMP_VREF_MASK                       (0x7C00U)
#define PMC_COMP_VREF_SHIFT                      (10U)
/*! VREF - Control reference voltage step, per steps of (VREFINPUT/31). */
#define PMC_COMP_VREF(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_COMP_VREF_SHIFT)) & PMC_COMP_VREF_MASK)

#define PMC_COMP_FILTERCGF_SAMPLEMODE_MASK       (0x30000U)
#define PMC_COMP_FILTERCGF_SAMPLEMODE_SHIFT      (16U)
/*! FILTERCGF_SAMPLEMODE - Control the filtering of the Analog Comparator output.
 *  0b00..Bypass mode.
 *  0b01..Filter 1 clock period.
 *  0b10..Filter 2 clock period.
 *  0b11..Filter 3 clock period.
 */
#define PMC_COMP_FILTERCGF_SAMPLEMODE(x)         (((uint32_t)(((uint32_t)(x)) << PMC_COMP_FILTERCGF_SAMPLEMODE_SHIFT)) & PMC_COMP_FILTERCGF_SAMPLEMODE_MASK)

#define PMC_COMP_FILTERCGF_CLKDIV_MASK           (0x1C0000U)
#define PMC_COMP_FILTERCGF_CLKDIV_SHIFT          (18U)
/*! FILTERCGF_CLKDIV - Filter Clock divider.
 *  0b000..Filter clock period duration equals 1 Analog Comparator clock period.
 *  0b001..Filter clock period duration equals 2 Analog Comparator clock period.
 *  0b010..Filter clock period duration equals 4 Analog Comparator clock period.
 *  0b011..Filter clock period duration equals 8 Analog Comparator clock period.
 *  0b100..Filter clock period duration equals 16 Analog Comparator clock period.
 *  0b101..Filter clock period duration equals 32 Analog Comparator clock period.
 *  0b110..Filter clock period duration equals 64 Analog Comparator clock period.
 *  0b111..Filter clock period duration equals 128 Analog Comparator clock period.
 */
#define PMC_COMP_FILTERCGF_CLKDIV(x)             (((uint32_t)(((uint32_t)(x)) << PMC_COMP_FILTERCGF_CLKDIV_SHIFT)) & PMC_COMP_FILTERCGF_CLKDIV_MASK)
/*! @} */

/*! @name CMD - DCDC and LDOCORE power state (enable/disable) control. */
/*! @{ */

#define PMC_CMD_DCDCENABLE_MASK                  (0x1U)
#define PMC_CMD_DCDCENABLE_SHIFT                 (0U)
/*! DCDCENABLE - Enable DCDC (self clearing bit).
 *  0b0..No effect.
 *  0b1..Enable DCDC. Automatically reset to '0' by the Hardware.
 */
#define PMC_CMD_DCDCENABLE(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CMD_DCDCENABLE_SHIFT)) & PMC_CMD_DCDCENABLE_MASK)

#define PMC_CMD_DCDCDISABLE_MASK                 (0x2U)
#define PMC_CMD_DCDCDISABLE_SHIFT                (1U)
/*! DCDCDISABLE - Disable DCDC (self clearing bit).
 *  0b0..No effect.
 *  0b1..Disbale DCDC. Automatically reset to '0' by the Hardware.
 */
#define PMC_CMD_DCDCDISABLE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_CMD_DCDCDISABLE_SHIFT)) & PMC_CMD_DCDCDISABLE_MASK)

#define PMC_CMD_LDOCOREHIGHPWRENABLE_MASK        (0x4U)
#define PMC_CMD_LDOCOREHIGHPWRENABLE_SHIFT       (2U)
/*! LDOCOREHIGHPWRENABLE - Enable LDO CORE High Power Mode (self clearing bit).
 *  0b0..No effect.
 *  0b1..Enable LDO CORE High Power Mode. Automatically reset to '0' by the Hardware.
 */
#define PMC_CMD_LDOCOREHIGHPWRENABLE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_CMD_LDOCOREHIGHPWRENABLE_SHIFT)) & PMC_CMD_LDOCOREHIGHPWRENABLE_MASK)

#define PMC_CMD_LDOCOREHIGHPWRDISABLE_MASK       (0x8U)
#define PMC_CMD_LDOCOREHIGHPWRDISABLE_SHIFT      (3U)
/*! LDOCOREHIGHPWRDISABLE - Disable LDO CORE High Power Mode (self clearing bit).
 *  0b0..No effect.
 *  0b1..Disable LDO CORE High Power Mode. Automatically reset to '0' by the Hardware.
 */
#define PMC_CMD_LDOCOREHIGHPWRDISABLE(x)         (((uint32_t)(((uint32_t)(x)) << PMC_CMD_LDOCOREHIGHPWRDISABLE_SHIFT)) & PMC_CMD_LDOCOREHIGHPWRDISABLE_MASK)

#define PMC_CMD_LDOCORELOWPWRENABLE_MASK         (0x10U)
#define PMC_CMD_LDOCORELOWPWRENABLE_SHIFT        (4U)
/*! LDOCORELOWPWRENABLE - Enable LDO CORE Low Power Mode (self clearing bit).
 *  0b0..No effect.
 *  0b1..Enable LDO CORE Low Power Mode. Automatically reset to '0' by the Hardware.
 */
#define PMC_CMD_LDOCORELOWPWRENABLE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_CMD_LDOCORELOWPWRENABLE_SHIFT)) & PMC_CMD_LDOCORELOWPWRENABLE_MASK)

#define PMC_CMD_LDOCORELOWPWRDISABLE_MASK        (0x20U)
#define PMC_CMD_LDOCORELOWPWRDISABLE_SHIFT       (5U)
/*! LDOCORELOWPWRDISABLE - Disable LDO CORE Low Power Mode (self clearing bit).
 *  0b0..No effect.
 *  0b1..Disable LDO CORE Low Power Mode. Automatically reset to '0' by the Hardware.
 */
#define PMC_CMD_LDOCORELOWPWRDISABLE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_CMD_LDOCORELOWPWRDISABLE_SHIFT)) & PMC_CMD_LDOCORELOWPWRDISABLE_MASK)
/*! @} */

/*! @name WAKEUPIOCTRL - Wake-up IO control */
/*! @{ */

#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP0_MASK  (0x1U)
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP0_SHIFT (0U)
/*! RISINGEDGEWAKEUP0 - Enable / disable detection of rising edge events on Wake Up 0 pin in Deep Power Down modes:.
 *  0b0..Rising edge detection is disabled.
 *  0b1..Rising edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP0(x)    (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP0_SHIFT)) & PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP0_MASK)

#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP0_MASK (0x2U)
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP0_SHIFT (1U)
/*! FALLINGEDGEWAKEUP0 - Enable / disable detection of falling edge events on Wake Up 0 pin in Deep Power Down modes:.
 *  0b0..Falling edge detection is disabled.
 *  0b1..Falling edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP0(x)   (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP0_SHIFT)) & PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP0_MASK)

#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP1_MASK  (0x4U)
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP1_SHIFT (2U)
/*! RISINGEDGEWAKEUP1 - Enable / disable detection of rising edge events on Wake Up 1 pin in Deep Power Down modes:.
 *  0b0..Rising edge detection is disabled.
 *  0b1..Rising edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP1(x)    (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP1_SHIFT)) & PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP1_MASK)

#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP1_MASK (0x8U)
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP1_SHIFT (3U)
/*! FALLINGEDGEWAKEUP1 - Enable / disable detection of falling edge events on Wake Up 1 pin in Deep Power Down modes:.
 *  0b0..Falling edge detection is disabled.
 *  0b1..Falling edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP1(x)   (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP1_SHIFT)) & PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP1_MASK)

#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP2_MASK  (0x10U)
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP2_SHIFT (4U)
/*! RISINGEDGEWAKEUP2 - Enable / disable detection of rising edge events on Wake Up 2 pin in Deep Power Down modes:.
 *  0b0..Rising edge detection is disabled.
 *  0b1..Rising edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP2(x)    (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP2_SHIFT)) & PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP2_MASK)

#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP2_MASK (0x20U)
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP2_SHIFT (5U)
/*! FALLINGEDGEWAKEUP2 - Enable / disable detection of falling edge events on Wake Up 2 pin in Deep Power Down modes:.
 *  0b0..Falling edge detection is disabled.
 *  0b1..Falling edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP2(x)   (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP2_SHIFT)) & PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP2_MASK)

#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP3_MASK  (0x40U)
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP3_SHIFT (6U)
/*! RISINGEDGEWAKEUP3 - Enable / disable detection of rising edge events on Wake Up 3 pin in Deep Power Down modes:
 *  0b0..Rising edge detection is disabled.
 *  0b1..Rising edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP3(x)    (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP3_SHIFT)) & PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP3_MASK)

#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP3_MASK (0x80U)
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP3_SHIFT (7U)
/*! FALLINGEDGEWAKEUP3 - Enable / disable detection of falling edge events on Wake Up 3 pin in Deep Power Down modes:
 *  0b0..Falling edge detection is disabled.
 *  0b1..Falling edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP3(x)   (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP3_SHIFT)) & PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP3_MASK)

#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP4_MASK  (0x100U)
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP4_SHIFT (8U)
/*! RISINGEDGEWAKEUP4 - Enable / disable detection of rising edge events on Wake Up 4 pin in Deep Power Down modes:
 *  0b0..Rising edge detection is disabled.
 *  0b1..Rising edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP4(x)    (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP4_SHIFT)) & PMC_WAKEUPIOCTRL_RISINGEDGEWAKEUP4_MASK)

#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP4_MASK (0x200U)
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP4_SHIFT (9U)
/*! FALLINGEDGEWAKEUP4 - Enable / disable detection of falling edge events on Wake Up 4 pin in Deep Power Down modes:
 *  0b0..Falling edge detection is disabled.
 *  0b1..Falling edge detection is enabled.
 */
#define PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP4(x)   (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP4_SHIFT)) & PMC_WAKEUPIOCTRL_FALLINGEDGEWAKEUP4_MASK)

#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD0_MASK   (0xC00U)
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD0_SHIFT  (10U)
/*! MODEWAKEUPIOPAD0 - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD0(x)     (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD0_SHIFT)) & PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD0_MASK)

#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD1_MASK   (0x3000U)
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD1_SHIFT  (12U)
/*! MODEWAKEUPIOPAD1 - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD1(x)     (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD1_SHIFT)) & PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD1_MASK)

#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD2_MASK   (0xC000U)
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD2_SHIFT  (14U)
/*! MODEWAKEUPIOPAD2 - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD2(x)     (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD2_SHIFT)) & PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD2_MASK)

#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD3_MASK   (0x30000U)
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD3_SHIFT  (16U)
/*! MODEWAKEUPIOPAD3 - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD3(x)     (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD3_SHIFT)) & PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD3_MASK)

#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD4_MASK   (0xC0000U)
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD4_SHIFT  (18U)
/*! MODEWAKEUPIOPAD4 - Selects function mode (on-chip pull-up/pull-down resistor control).
 *  0b00..Inactive. Inactive (no pull-down/pull-up resistor enabled).
 *  0b01..Pull-down. Pull-down resistor enabled.
 *  0b10..Pull-up. Pull-up resistor enabled.
 *  0b11..Repeater. Repeater mode.
 */
#define PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD4(x)     (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD4_SHIFT)) & PMC_WAKEUPIOCTRL_MODEWAKEUPIOPAD4_MASK)

#define PMC_WAKEUPIOCTRL_WAKEUPIO_ENABLE_CTRL_MASK (0x100000U)
#define PMC_WAKEUPIOCTRL_WAKEUPIO_ENABLE_CTRL_SHIFT (20U)
/*! WAKEUPIO_ENABLE_CTRL - Enable WAKEUP IO PAD control from MODEWAKEUPIOPAD (bits 10 to 19).
 *  0b0..WAKEUP IO PAD mode control comes from IOCON.
 *  0b1..WAKEUP IO PAD mode control comes from MODEWAKEUPIOPAD (bits 10 to 19).
 */
#define PMC_WAKEUPIOCTRL_WAKEUPIO_ENABLE_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_WAKEUPIO_ENABLE_CTRL_SHIFT)) & PMC_WAKEUPIOCTRL_WAKEUPIO_ENABLE_CTRL_MASK)

#define PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_MASK      (0x200000U)
#define PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_SHIFT     (21U)
/*! WAKEUPIO_RSTN - WAKEUP IO event detector reset control.
 *  0b0..Bloc is reset.
 *  0b1..Bloc is not reset.
 */
#define PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN(x)        (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_SHIFT)) & PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_MASK)
/*! @} */

/*! @name WAKEIOCAUSE - Wake-up I/O source */
/*! @{ */

#define PMC_WAKEIOCAUSE_WAKEUP0_MASK             (0x1U)
#define PMC_WAKEIOCAUSE_WAKEUP0_SHIFT            (0U)
/*! WAKEUP0 - Allows to identify Wake up I/O 0 as the wake-up source from Deep Power Down mode.
 *  0b0..Last wake up from Deep Power down mode was NOT triggred by wake up I/O 0.
 *  0b1..Last wake up from Deep Power down mode was triggred by wake up I/O 0.
 */
#define PMC_WAKEIOCAUSE_WAKEUP0(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUP0_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUP0_MASK)

#define PMC_WAKEIOCAUSE_WAKEUP1_MASK             (0x2U)
#define PMC_WAKEIOCAUSE_WAKEUP1_SHIFT            (1U)
/*! WAKEUP1 - Allows to identify Wake up I/O 1 as the wake-up source from Deep Power Down mode.
 *  0b0..Last wake up from Deep Power down mode was NOT triggred by wake up I/O 1.
 *  0b1..Last wake up from Deep Power down mode was triggred by wake up I/O 1.
 */
#define PMC_WAKEIOCAUSE_WAKEUP1(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUP1_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUP1_MASK)

#define PMC_WAKEIOCAUSE_WAKEUP2_MASK             (0x4U)
#define PMC_WAKEIOCAUSE_WAKEUP2_SHIFT            (2U)
/*! WAKEUP2 - Allows to identify Wake up I/O 2 as the wake-up source from Deep Power Down mode.
 *  0b0..Last wake up from Deep Power down mode was NOT triggred by wake up I/O 2.
 *  0b1..Last wake up from Deep Power down mode was triggred by wake up I/O 2.
 */
#define PMC_WAKEIOCAUSE_WAKEUP2(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUP2_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUP2_MASK)

#define PMC_WAKEIOCAUSE_WAKEUP3_MASK             (0x8U)
#define PMC_WAKEIOCAUSE_WAKEUP3_SHIFT            (3U)
/*! WAKEUP3 - Allows to identify Wake up I/O 3 as the wake-up source from Deep Power Down mode.
 *  0b0..Last wake up from Deep Power down mode was NOT triggred by wake up I/O 3.
 *  0b1..Last wake up from Deep Power down mode was triggred by wake up I/O 3.
 */
#define PMC_WAKEIOCAUSE_WAKEUP3(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUP3_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUP3_MASK)

#define PMC_WAKEIOCAUSE_WAKEUP4_MASK             (0x10U)
#define PMC_WAKEIOCAUSE_WAKEUP4_SHIFT            (4U)
/*! WAKEUP4 - Allows to identify Wake up I/O 4 as the wake-up source from Deep Power Down mode.
 *  0b0..Last wake up from Deep Power down mode was NOT triggred by wake up I/O 4.
 *  0b1..Last wake up from Deep Power down mode was triggred by wake up I/O 4.
 */
#define PMC_WAKEIOCAUSE_WAKEUP4(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUP4_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUP4_MASK)

#define PMC_WAKEIOCAUSE_WAKEUPIO_EVENTS_ORDER_MASK (0x3E0U)
#define PMC_WAKEIOCAUSE_WAKEUPIO_EVENTS_ORDER_SHIFT (5U)
/*! WAKEUPIO_EVENTS_ORDER - In DEEP-POWER-DOWN mode, indicates which wake up I/O event occured first when several wake up I/Os are enabled.
 *  0b00000..None
 *  0b00001..Wake up I/O 0
 *  0b00010..Wake up I/O 1
 *  0b00100..Wake up I/O 2
 *  0b01000..Wake up I/O 3
 *  0b10000..Wake up I/O 4
 */
#define PMC_WAKEIOCAUSE_WAKEUPIO_EVENTS_ORDER(x) (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUPIO_EVENTS_ORDER_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUPIO_EVENTS_ORDER_MASK)
/*! @} */

/*! @name LIFECYCLESTATE - Life Cycle State */
/*! @{ */

#define PMC_LIFECYCLESTATE_LC_MASK               (0xFFU)
#define PMC_LIFECYCLESTATE_LC_SHIFT              (0U)
/*! LC - Life Cycle state */
#define PMC_LIFECYCLESTATE_LC(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LIFECYCLESTATE_LC_SHIFT)) & PMC_LIFECYCLESTATE_LC_MASK)
/*! @} */

/*! @name STATUSPWR - Power status */
/*! @{ */

#define PMC_STATUSPWR_DCDCPWROK_MASK             (0x1U)
#define PMC_STATUSPWR_DCDCPWROK_SHIFT            (0U)
/*! DCDCPWROK - DCDC converter power OK. */
#define PMC_STATUSPWR_DCDCPWROK(x)               (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_DCDCPWROK_SHIFT)) & PMC_STATUSPWR_DCDCPWROK_MASK)

#define PMC_STATUSPWR_LDOCOREPWROK_MASK          (0x10U)
#define PMC_STATUSPWR_LDOCOREPWROK_SHIFT         (4U)
/*! LDOCOREPWROK - CORE LDO power OK. */
#define PMC_STATUSPWR_LDOCOREPWROK(x)            (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_LDOCOREPWROK_SHIFT)) & PMC_STATUSPWR_LDOCOREPWROK_MASK)
/*! @} */

/*! @name STATUSCLK - Clock status */
/*! @{ */

#define PMC_STATUSCLK_XTAL32KOK_MASK             (0x1U)
#define PMC_STATUSCLK_XTAL32KOK_SHIFT            (0U)
/*! XTAL32KOK - XTAL oscillator 32 K OK signal. */
#define PMC_STATUSCLK_XTAL32KOK(x)               (((uint32_t)(((uint32_t)(x)) << PMC_STATUSCLK_XTAL32KOK_SHIFT)) & PMC_STATUSCLK_XTAL32KOK_MASK)

#define PMC_STATUSCLK_XTAL32KOSCFAILURE_MASK     (0x4U)
#define PMC_STATUSCLK_XTAL32KOSCFAILURE_SHIFT    (2U)
/*! XTAL32KOSCFAILURE - XTAL32 KHZ oscillator oscillation failure detection indicator.
 *  0b0..No oscillation failure has been detetced since the last time this bit has been cleared.
 *  0b1..At least one oscillation failure has been detetced since the last time this bit has been cleared.
 */
#define PMC_STATUSCLK_XTAL32KOSCFAILURE(x)       (((uint32_t)(((uint32_t)(x)) << PMC_STATUSCLK_XTAL32KOSCFAILURE_SHIFT)) & PMC_STATUSCLK_XTAL32KOSCFAILURE_MASK)
/*! @} */

/*! @name AOREG0 - Always-on 0 */
/*! @{ */

#define PMC_AOREG0_DATA_15_0_MASK                (0xFFFFU)
#define PMC_AOREG0_DATA_15_0_SHIFT               (0U)
/*! DATA_15_0 - General purpose always on domain data storage. */
#define PMC_AOREG0_DATA_15_0(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_AOREG0_DATA_15_0_SHIFT)) & PMC_AOREG0_DATA_15_0_MASK)
/*! @} */

/*! @name AOREG1 - Always-on 1 */
/*! @{ */

#define PMC_AOREG1_POR_MASK                      (0x10U)
#define PMC_AOREG1_POR_SHIFT                     (4U)
/*! POR - The last chip reset was caused by a Power On Reset. */
#define PMC_AOREG1_POR(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_POR_SHIFT)) & PMC_AOREG1_POR_MASK)

#define PMC_AOREG1_PADRESET_MASK                 (0x20U)
#define PMC_AOREG1_PADRESET_SHIFT                (5U)
/*! PADRESET - The last chip reset was caused by a Pin Reset. */
#define PMC_AOREG1_PADRESET(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_PADRESET_SHIFT)) & PMC_AOREG1_PADRESET_MASK)

#define PMC_AOREG1_BODRESET_MASK                 (0x40U)
#define PMC_AOREG1_BODRESET_SHIFT                (6U)
/*! BODRESET - The last chip reset was caused by a Brown Out Detector (BoD), either BOD_VDDMAIN or BOD_CORE. */
#define PMC_AOREG1_BODRESET(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_BODRESET_SHIFT)) & PMC_AOREG1_BODRESET_MASK)

#define PMC_AOREG1_SYSTEMRESET_MASK              (0x80U)
#define PMC_AOREG1_SYSTEMRESET_SHIFT             (7U)
/*! SYSTEMRESET - The last chip reset was caused by a System Reset requested by the ARM CPU. */
#define PMC_AOREG1_SYSTEMRESET(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_SYSTEMRESET_SHIFT)) & PMC_AOREG1_SYSTEMRESET_MASK)

#define PMC_AOREG1_WDTRESET_MASK                 (0x100U)
#define PMC_AOREG1_WDTRESET_SHIFT                (8U)
/*! WDTRESET - The last chip reset was caused by the Watchdog Timer. */
#define PMC_AOREG1_WDTRESET(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_WDTRESET_SHIFT)) & PMC_AOREG1_WDTRESET_MASK)

#define PMC_AOREG1_SWRRESET_MASK                 (0x200U)
#define PMC_AOREG1_SWRRESET_SHIFT                (9U)
/*! SWRRESET - The last chip reset was caused by a Software event. */
#define PMC_AOREG1_SWRRESET(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_SWRRESET_SHIFT)) & PMC_AOREG1_SWRRESET_MASK)

#define PMC_AOREG1_DPDRESET_WAKEUPIO_MASK        (0x400U)
#define PMC_AOREG1_DPDRESET_WAKEUPIO_SHIFT       (10U)
/*! DPDRESET_WAKEUPIO - A Wake-up I/O reset event occured during DEEP-POWER-DOWN mode. */
#define PMC_AOREG1_DPDRESET_WAKEUPIO(x)          (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_DPDRESET_WAKEUPIO_SHIFT)) & PMC_AOREG1_DPDRESET_WAKEUPIO_MASK)

#define PMC_AOREG1_DPDRESET_RTC_MASK             (0x800U)
#define PMC_AOREG1_DPDRESET_RTC_SHIFT            (11U)
/*! DPDRESET_RTC - A RTC event occured during DEEP-POWER-DOWN mode. */
#define PMC_AOREG1_DPDRESET_RTC(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_DPDRESET_RTC_SHIFT)) & PMC_AOREG1_DPDRESET_RTC_MASK)

#define PMC_AOREG1_DPDRESET_OSTIMER_MASK         (0x1000U)
#define PMC_AOREG1_DPDRESET_OSTIMER_SHIFT        (12U)
/*! DPDRESET_OSTIMER - An OS Timer event occured during a DEEP-POWER-DOWN mode. */
#define PMC_AOREG1_DPDRESET_OSTIMER(x)           (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_DPDRESET_OSTIMER_SHIFT)) & PMC_AOREG1_DPDRESET_OSTIMER_MASK)

#define PMC_AOREG1_CDOGRESET_MASK                (0x2000U)
#define PMC_AOREG1_CDOGRESET_SHIFT               (13U)
/*! CDOGRESET - The last chip reset was caused by the code Watchdog. */
#define PMC_AOREG1_CDOGRESET(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_CDOGRESET_SHIFT)) & PMC_AOREG1_CDOGRESET_MASK)

#define PMC_AOREG1_DPD_EVENTS_ORDER_MASK         (0x1C000U)
#define PMC_AOREG1_DPD_EVENTS_ORDER_SHIFT        (14U)
/*! DPD_EVENTS_ORDER - In DEEP-POWER-DOWN mode, indicates which reset event occured first, between a
 *    wake up I/O event (in DEEP-POWER-DOWN), a RTC event (in DEEP-POWER-DOWN) and a OS Timer event
 *    (in DEEP-POWER-DOWN). May be usefull when several reset events are enabled during
 *    DEEP-POWER-DOWN.
 *  0b000..No event
 *  0b001..WAKEUPIO
 *  0b010..RTC
 *  0b011..Both WAKEUPIO and RTC events occured at the same time (the 2 events occured within 1 nano-second of each other)
 *  0b100..OSTIMER
 *  0b101..Both WAKEUPIO and OSTIMER events occured at the same time (the 2 events occured within 1 nano-second of each other)
 *  0b110..Both RTC and OSTIMER events occured at the same time (the 2 events occured within 1 nano-second of each other)
 *  0b111..WAKEUPIO, RTC and OSTIMER events occured at the same time (the 3 events occured within 1 nano-second of each other)
 */
#define PMC_AOREG1_DPD_EVENTS_ORDER(x)           (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_DPD_EVENTS_ORDER_SHIFT)) & PMC_AOREG1_DPD_EVENTS_ORDER_MASK)

#define PMC_AOREG1_BOOTERRORCOUNTER_MASK         (0xF000000U)
#define PMC_AOREG1_BOOTERRORCOUNTER_SHIFT        (24U)
/*! BOOTERRORCOUNTER - ROM Boot Fatal Error Counter. */
#define PMC_AOREG1_BOOTERRORCOUNTER(x)           (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_BOOTERRORCOUNTER_SHIFT)) & PMC_AOREG1_BOOTERRORCOUNTER_MASK)
/*! @} */

/*! @name MISCCTRL - Miscellaneous control */
/*! @{ */

#define PMC_MISCCTRL_VREF_ISO_MASK               (0x10000U)
#define PMC_MISCCTRL_VREF_ISO_SHIFT              (16U)
/*! VREF_ISO - VREF isolation control.
 *  0b0..VREF module isolation is disabled.
 *  0b1..VREF module isolation is enabled.
 */
#define PMC_MISCCTRL_VREF_ISO(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_MISCCTRL_VREF_ISO_SHIFT)) & PMC_MISCCTRL_VREF_ISO_MASK)
/*! @} */

/*! @name RTCOSC32K - 32 KHz clocks source control */
/*! @{ */

#define PMC_RTCOSC32K_SEL_MASK                   (0x1U)
#define PMC_RTCOSC32K_SEL_SHIFT                  (0U)
/*! SEL - Select the 32K oscillator to be used in for the RTC, the OS Event Timer and the rest of
 *    the SoC (either XTAL32KHz or FRO32KHz) .
 *  0b0..FRO 32 KHz.
 *  0b1..XTAL 32KHz.
 */
#define PMC_RTCOSC32K_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_SEL_SHIFT)) & PMC_RTCOSC32K_SEL_MASK)
/*! @} */

/*! @name OSEVENTTIMER - OS Event Timer control */
/*! @{ */

#define PMC_OSEVENTTIMER_SOFTRESET_MASK          (0x1U)
#define PMC_OSEVENTTIMER_SOFTRESET_SHIFT         (0U)
/*! SOFTRESET - Active high reset. */
#define PMC_OSEVENTTIMER_SOFTRESET(x)            (((uint32_t)(((uint32_t)(x)) << PMC_OSEVENTTIMER_SOFTRESET_SHIFT)) & PMC_OSEVENTTIMER_SOFTRESET_MASK)

#define PMC_OSEVENTTIMER_CLOCKENABLE_MASK        (0x2U)
#define PMC_OSEVENTTIMER_CLOCKENABLE_SHIFT       (1U)
/*! CLOCKENABLE - Enable OSTIMER 32 KHz clock. */
#define PMC_OSEVENTTIMER_CLOCKENABLE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_OSEVENTTIMER_CLOCKENABLE_SHIFT)) & PMC_OSEVENTTIMER_CLOCKENABLE_MASK)

#define PMC_OSEVENTTIMER_DPDWAKEUPENABLE_MASK    (0x4U)
#define PMC_OSEVENTTIMER_DPDWAKEUPENABLE_SHIFT   (2U)
/*! DPDWAKEUPENABLE - Wake up enable in Deep Power Down mode (To be used in Enable Deep Power Down mode). */
#define PMC_OSEVENTTIMER_DPDWAKEUPENABLE(x)      (((uint32_t)(((uint32_t)(x)) << PMC_OSEVENTTIMER_DPDWAKEUPENABLE_SHIFT)) & PMC_OSEVENTTIMER_DPDWAKEUPENABLE_MASK)

#define PMC_OSEVENTTIMER_SELCLOCK_MASK           (0x18U)
#define PMC_OSEVENTTIMER_SELCLOCK_SHIFT          (3U)
/*! SELCLOCK - Select OS Event Timer Clock source
 *  0b00..32-KHz Free Running Oscillator (FRO)
 *  0b01..32-KHz Crystal Oscillator (XTAL)
 *  0b10..1-MHz FRO
 *  0b11..System Bus clock
 */
#define PMC_OSEVENTTIMER_SELCLOCK(x)             (((uint32_t)(((uint32_t)(x)) << PMC_OSEVENTTIMER_SELCLOCK_SHIFT)) & PMC_OSEVENTTIMER_SELCLOCK_MASK)
/*! @} */

/*! @name PDSLEEPCFG1 - Power down sleep configuration 1 */
/*! @{ */

#define PMC_PDSLEEPCFG1_PDEN_CMPBIAS_MASK        (0x1U)
#define PMC_PDSLEEPCFG1_PDEN_CMPBIAS_SHIFT       (0U)
/*! PDEN_CMPBIAS - Controls Comparators 1/2/3 Bias power during DEEP-SLEEP (always shut down during POWER-DOWN & DEEP-POWER-DOWN).
 *  0b0..Analog Bias is powered on during low power mode.
 *  0b1..Analog Bias is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_CMPBIAS(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_CMPBIAS_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_CMPBIAS_MASK)

#define PMC_PDSLEEPCFG1_PDEN_HSCMP0_DAC_MASK     (0x2U)
#define PMC_PDSLEEPCFG1_PDEN_HSCMP0_DAC_SHIFT    (1U)
/*! PDEN_HSCMP0_DAC - Controls High Speed Comparator0 DAC power during DEEP-SLEEP (always shut down during POWER-DOWN & DEEP-POWER-DOWN).
 *  0b0..High Speed Comparator0 DAC is powered on during low power mode.
 *  0b1..High Speed Comparator0 DAC is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_HSCMP0_DAC(x)       (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_HSCMP0_DAC_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_HSCMP0_DAC_MASK)

#define PMC_PDSLEEPCFG1_PDEN_HSCMP1_DAC_MASK     (0x4U)
#define PMC_PDSLEEPCFG1_PDEN_HSCMP1_DAC_SHIFT    (2U)
/*! PDEN_HSCMP1_DAC - Controls High Speed Comparator1 DAC power during DEEP-SLEEP (always shut down during POWER-DOWN & DEEP-POWER-DOWN).
 *  0b0..High Speed Comparator1 DAC is powered on during low power mode.
 *  0b1..High Speed Comparator1 DAC is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_HSCMP1_DAC(x)       (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_HSCMP1_DAC_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_HSCMP1_DAC_MASK)

#define PMC_PDSLEEPCFG1_PDEN_HSCMP2_DAC_MASK     (0x8U)
#define PMC_PDSLEEPCFG1_PDEN_HSCMP2_DAC_SHIFT    (3U)
/*! PDEN_HSCMP2_DAC - Controls High Speed Comparator2 DAC power during DEEP-SLEEP (always shut down during POWER-DOWN & DEEP-POWER-DOWN).
 *  0b0..High Speed Comparator2 DAC is powered on during low power mode.
 *  0b1..High Speed Comparator2 DAC is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_HSCMP2_DAC(x)       (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_HSCMP2_DAC_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_HSCMP2_DAC_MASK)

#define PMC_PDSLEEPCFG1_PDEN_DAC0_MASK           (0x10U)
#define PMC_PDSLEEPCFG1_PDEN_DAC0_SHIFT          (4U)
/*! PDEN_DAC0 - Controls DAC0 power during DEEP-SLEEP & POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..DAC0 is powered on during low power mode.
 *  0b1..DAC0 is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_DAC0(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_DAC0_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_DAC0_MASK)

#define PMC_PDSLEEPCFG1_PDEN_DAC1_MASK           (0x20U)
#define PMC_PDSLEEPCFG1_PDEN_DAC1_SHIFT          (5U)
/*! PDEN_DAC1 - Controls DAC1 power during DEEP-SLEEP & POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..DAC1 is powered on during low power mode.
 *  0b1..DAC1 is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_DAC1(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_DAC1_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_DAC1_MASK)

#define PMC_PDSLEEPCFG1_PDEN_DAC2_MASK           (0x40U)
#define PMC_PDSLEEPCFG1_PDEN_DAC2_SHIFT          (6U)
/*! PDEN_DAC2 - Controls DAC2 power during DEEP-SLEEP & POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..DAC2 is powered on during low power mode.
 *  0b1..DAC2 is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG1_PDEN_DAC2(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PDEN_DAC2_SHIFT)) & PMC_PDSLEEPCFG1_PDEN_DAC2_MASK)

#define PMC_PDSLEEPCFG1_STOPEN_DAC0_MASK         (0x80U)
#define PMC_PDSLEEPCFG1_STOPEN_DAC0_SHIFT        (7U)
/*! STOPEN_DAC0 - Controls DAC0 Stop mode during DEEP-SLEEP & POWER-DOWN (DAC stop mode is always disabled in DEEP-POWER-DOWN).
 *  0b0..DAC Stop Mode is disabled.
 *  0b1..DAC Stop Mode is enabled.
 */
#define PMC_PDSLEEPCFG1_STOPEN_DAC0(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_STOPEN_DAC0_SHIFT)) & PMC_PDSLEEPCFG1_STOPEN_DAC0_MASK)

#define PMC_PDSLEEPCFG1_STOPEN_DAC1_MASK         (0x100U)
#define PMC_PDSLEEPCFG1_STOPEN_DAC1_SHIFT        (8U)
/*! STOPEN_DAC1 - Controls DAC1 Stop mode during DEEP-SLEEP & POWER-DOWN (DAC stop mode is always disabled in DEEP-POWER-DOWN).
 *  0b0..DAC Stop Mode is disabled.
 *  0b1..DAC Stop Mode is enabled.
 */
#define PMC_PDSLEEPCFG1_STOPEN_DAC1(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_STOPEN_DAC1_SHIFT)) & PMC_PDSLEEPCFG1_STOPEN_DAC1_MASK)

#define PMC_PDSLEEPCFG1_STOPEN_DAC2_MASK         (0x200U)
#define PMC_PDSLEEPCFG1_STOPEN_DAC2_SHIFT        (9U)
/*! STOPEN_DAC2 - Controls DAC2 Stop mode during DEEP-SLEEP & POWER-DOWN (DAC stop mode is always disabled in DEEP-POWER-DOWN).
 *  0b0..DAC Stop Mode is disabled.
 *  0b1..DAC Stop Mode is enabled.
 */
#define PMC_PDSLEEPCFG1_STOPEN_DAC2(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_STOPEN_DAC2_SHIFT)) & PMC_PDSLEEPCFG1_STOPEN_DAC2_MASK)
/*! @} */

/*! @name TIMEOUTEVENTS - Time-out events */
/*! @{ */

#define PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_MASK      (0x1U)
#define PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_SHIFT     (0U)
/*! PWUP_DCDC_OK - 1: a time out event occured during power up when waiting for DCDC to become functional. */
#define PMC_TIMEOUTEVENTS_PWUP_DCDC_OK(x)        (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_LDOFLASHNV_OK_MASK (0x2U)
#define PMC_TIMEOUTEVENTS_PWUP_LDOFLASHNV_OK_SHIFT (1U)
/*! PWUP_LDOFLASHNV_OK - 1: a time out event occured during power up when waiting for LDO Flash NV to become functional. */
#define PMC_TIMEOUTEVENTS_PWUP_LDOFLASHNV_OK(x)  (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_LDOFLASHNV_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_LDOFLASHNV_OK_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_SRAM_WAKEUP_MASK  (0x4U)
#define PMC_TIMEOUTEVENTS_PWUP_SRAM_WAKEUP_SHIFT (2U)
/*! PWUP_SRAM_WAKEUP - 1: a time out event occured during power up when waiting for SRAM to become functional. */
#define PMC_TIMEOUTEVENTS_PWUP_SRAM_WAKEUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_SRAM_WAKEUP_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_SRAM_WAKEUP_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_MASK (0x8U)
#define PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_SHIFT (3U)
/*! PWUP_FLASHINIT_DONE - 1: a time out event occured during power up when waiting for Flash initialization. */
#define PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_LDOFLASH_SRAM_OFF_MASK (0x10U)
#define PMC_TIMEOUTEVENTS_DSLP_LDOFLASH_SRAM_OFF_SHIFT (4U)
/*! DSLP_LDOFLASH_SRAM_OFF - 1: a time out event occured during deep sleep when waiting for LDO Flash NV or SRAM shut off. */
#define PMC_TIMEOUTEVENTS_DSLP_LDOFLASH_SRAM_OFF(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_LDOFLASH_SRAM_OFF_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_LDOFLASH_SRAM_OFF_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_MASK      (0x20U)
#define PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_SHIFT     (5U)
/*! DSLP_DCDC_OK - 1: a time out event occured during deep sleep when waiting for DCDC to become functional. */
#define PMC_TIMEOUTEVENTS_DSLP_DCDC_OK(x)        (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_LDOFLASHNV_OK_MASK (0x40U)
#define PMC_TIMEOUTEVENTS_DSLP_LDOFLASHNV_OK_SHIFT (6U)
/*! DSLP_LDOFLASHNV_OK - 1: a time out event occured during deep sleep when waiting for LDO Flash NV to become functional. */
#define PMC_TIMEOUTEVENTS_DSLP_LDOFLASHNV_OK(x)  (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_LDOFLASHNV_OK_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_LDOFLASHNV_OK_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_MASK  (0x80U)
#define PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_SHIFT (7U)
/*! DSLP_SRAM_WAKEUP - 1: a time out event occured during deep sleep when waiting for SRAM to become functional. */
#define PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_LDOFLASH_SRAM_OFF_MASK (0x100U)
#define PMC_TIMEOUTEVENTS_PDWN_LDOFLASH_SRAM_OFF_SHIFT (8U)
/*! PDWN_LDOFLASH_SRAM_OFF - 1: a time out event occured during power down when waiting for for LDO Flash NV or SRAM shut off. */
#define PMC_TIMEOUTEVENTS_PDWN_LDOFLASH_SRAM_OFF(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_LDOFLASH_SRAM_OFF_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_LDOFLASH_SRAM_OFF_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_DCDC_BODVDDMAIN_OK_MASK (0x200U)
#define PMC_TIMEOUTEVENTS_PDWN_DCDC_BODVDDMAIN_OK_SHIFT (9U)
/*! PDWN_DCDC_BODVDDMAIN_OK - 1: a time out event occured during power down when waiting for DCDC or BOD_VDDMAIN to become functional. */
#define PMC_TIMEOUTEVENTS_PDWN_DCDC_BODVDDMAIN_OK(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_DCDC_BODVDDMAIN_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_DCDC_BODVDDMAIN_OK_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_LDOFLASHNV_OK_MASK (0x400U)
#define PMC_TIMEOUTEVENTS_PDWN_LDOFLASHNV_OK_SHIFT (10U)
/*! PDWN_LDOFLASHNV_OK - 1: a time out event occured during power down when waiting for LDO Flash NV to become functional. */
#define PMC_TIMEOUTEVENTS_PDWN_LDOFLASHNV_OK(x)  (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_LDOFLASHNV_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_LDOFLASHNV_OK_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_SRAM_WAKEUP_MASK  (0x800U)
#define PMC_TIMEOUTEVENTS_PDWN_SRAM_WAKEUP_SHIFT (11U)
/*! PDWN_SRAM_WAKEUP - 1: a time out event occured during power down when waiting for SRAM to become functional. */
#define PMC_TIMEOUTEVENTS_PDWN_SRAM_WAKEUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_SRAM_WAKEUP_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_SRAM_WAKEUP_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_MASK (0x1000U)
#define PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_SHIFT (12U)
/*! PDWN_FLASHINIT_DONE - 1: a time out event occured during power down when waiting for Flash initialization. */
#define PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_MASK)
/*! @} */

/*! @name PDSLEEPCFG0 - Power down sleep configuration 0 */
/*! @{ */

#define PMC_PDSLEEPCFG0_PDEN_BIAS_MASK           (0x2U)
#define PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT          (1U)
/*! PDEN_BIAS - Controls Analog Bias power during DEEP-SLEEP and POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..Analog Bias is powered on during low power mode.
 *  0b1..Analog Bias is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BIAS(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BIAS_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BODCORE_MASK        (0x4U)
#define PMC_PDSLEEPCFG0_PDEN_BODCORE_SHIFT       (2U)
/*! PDEN_BODCORE - Controls Core Logic BoD power during DEEP-SLEEP and POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..BOD_CORE is powered on during low power mode.
 *  0b1..BOD_CORE is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BODCORE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BODCORE_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BODCORE_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BODVDDMAIN_MASK     (0x8U)
#define PMC_PDSLEEPCFG0_PDEN_BODVDDMAIN_SHIFT    (3U)
/*! PDEN_BODVDDMAIN - Controls BOD_VDDMAIN power during DEEP-SLEEP and POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..BOD_VDDMAIN is powered on during low power mode.
 *  0b1..BOD_VDDMAIN is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BODVDDMAIN(x)       (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BODVDDMAIN_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BODVDDMAIN_MASK)

#define PMC_PDSLEEPCFG0_PDEN_FRO1M_MASK          (0x10U)
#define PMC_PDSLEEPCFG0_PDEN_FRO1M_SHIFT         (4U)
/*! PDEN_FRO1M - Controls 1 MHz Free Running Oscillator power during DEEP-SLEEP, POWER-DOWN and DEEP-POWER-DOWN.
 *  0b0..FRO 1MHz is powered on during low power mode.
 *  0b1..FRO 1MHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_FRO1M(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_FRO1M_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_FRO1M_MASK)

#define PMC_PDSLEEPCFG0_PDEN_FRO192M_MASK        (0x20U)
#define PMC_PDSLEEPCFG0_PDEN_FRO192M_SHIFT       (5U)
/*! PDEN_FRO192M - Controls 192MHz Free Running Oscillator power during DEEP-SLEEP (always shut down
 *    during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..FRO 192 MHz is powered on during low power mode.
 *  0b1..FRO 192 MHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_FRO192M(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_FRO192M_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_FRO192M_MASK)

#define PMC_PDSLEEPCFG0_PDEN_FRO32K_MASK         (0x40U)
#define PMC_PDSLEEPCFG0_PDEN_FRO32K_SHIFT        (6U)
/*! PDEN_FRO32K - Controls power during DEEP-SLEEP, POWER-DOWN and DEEP-POWER-DOWN.
 *  0b0..FRO 32 KHz is powered on during low power mode.
 *  0b1..FRO 32 KHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_FRO32K(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_FRO32K_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_FRO32K_MASK)

#define PMC_PDSLEEPCFG0_PDEN_XTAL32K_MASK        (0x80U)
#define PMC_PDSLEEPCFG0_PDEN_XTAL32K_SHIFT       (7U)
/*! PDEN_XTAL32K - Controls crystal 32 KHz power during DEEP-SLEEP, POWER-DOWN and DEEP-POWER-DOWN.
 *  0b0..crystal 32 KHz is powered on during low power mode.
 *  0b1..crystal 32 KHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_XTAL32K(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_XTAL32K_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_XTAL32K_MASK)

#define PMC_PDSLEEPCFG0_PDEN_XTALHF_MASK         (0x100U)
#define PMC_PDSLEEPCFG0_PDEN_XTALHF_SHIFT        (8U)
/*! PDEN_XTALHF - Controls high speed crystal power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..High speed crystal is powered on during low power mode.
 *  0b1..High speed crystal is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_XTALHF(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_XTALHF_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_XTALHF_MASK)

#define PMC_PDSLEEPCFG0_PDEN_PLL0_MASK           (0x200U)
#define PMC_PDSLEEPCFG0_PDEN_PLL0_SHIFT          (9U)
/*! PDEN_PLL0 - Controls System PLL (also refered as PLL0) power during DEEP-SLEEP (always shut down
 *    during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..System PLL (also refered as PLL0) is powered on during low power mode.
 *  0b1..System PLL (also refered as PLL0) is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_PLL0(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_PLL0_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_PLL0_MASK)

#define PMC_PDSLEEPCFG0_PDEN_PLL1_MASK           (0x400U)
#define PMC_PDSLEEPCFG0_PDEN_PLL1_SHIFT          (10U)
/*! PDEN_PLL1 - Controls USB PLL (also refered as PLL1) power during DEEP-SLEEP (always shut down
 *    during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..USB PLL (also refered as PLL1) is powered on during low power mode.
 *  0b1..USB PLL (also refered as PLL1) is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_PLL1(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_PLL1_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_PLL1_MASK)

#define PMC_PDSLEEPCFG0_PDEN_USBFSPHY_MASK       (0x800U)
#define PMC_PDSLEEPCFG0_PDEN_USBFSPHY_SHIFT      (11U)
/*! PDEN_USBFSPHY - Controls USB Full Speed phy power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..USB Full Speed phy is powered on during low power mode.
 *  0b1..USB Full Speed phy is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_USBFSPHY(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_USBFSPHY_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_USBFSPHY_MASK)

#define PMC_PDSLEEPCFG0_PDEN_COMP_MASK           (0x2000U)
#define PMC_PDSLEEPCFG0_PDEN_COMP_SHIFT          (13U)
/*! PDEN_COMP - Controls Analog Comparator power during DEEP-SLEEP and POWER-DOWN (always shut down during DEEP-POWER-DOWN).
 *  0b0..Analog Comparator is powered on during low power mode.
 *  0b1..Analog Comparator is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_COMP(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_COMP_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_COMP_MASK)

#define PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK         (0x10000U)
#define PMC_PDSLEEPCFG0_PDEN_LDOMEM_SHIFT        (16U)
/*! PDEN_LDOMEM - Controls Memories LDO power during DEEP-SLEEP, POWER-DOWN and DEEP-POWER-DOWN.
 *  0b0..Memories LDO is powered on during low power mode.
 *  0b1..Memories LDO is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_LDOMEM(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_LDOMEM_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK)

#define PMC_PDSLEEPCFG0_PDEN_LDOEFUSEPROG_MASK   (0x40000U)
#define PMC_PDSLEEPCFG0_PDEN_LDOEFUSEPROG_SHIFT  (18U)
/*! PDEN_LDOEFUSEPROG - Controls USB high speed LDO power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..USB high speed LDO is powered on during low power mode.
 *  0b1..USB high speed LDO is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_LDOEFUSEPROG(x)     (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_LDOEFUSEPROG_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_LDOEFUSEPROG_MASK)

#define PMC_PDSLEEPCFG0_PDEN_LDOXTALHF_MASK      (0x100000U)
#define PMC_PDSLEEPCFG0_PDEN_LDOXTALHF_SHIFT     (20U)
/*! PDEN_LDOXTALHF - Controls High speed crystal LDO power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..High speed crystal LDO is powered on during low power mode.
 *  0b1..High speed crystal LDO is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_LDOXTALHF(x)        (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_LDOXTALHF_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_LDOXTALHF_MASK)

#define PMC_PDSLEEPCFG0_PDEN_LDOFLASHNV_MASK     (0x200000U)
#define PMC_PDSLEEPCFG0_PDEN_LDOFLASHNV_SHIFT    (21U)
/*! PDEN_LDOFLASHNV - Controls Flash NV (high voltage) LDO power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..Flash NV (high voltage) is powered on during low power mode.
 *  0b1..Flash NV (high voltage) is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_LDOFLASHNV(x)       (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_LDOFLASHNV_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_LDOFLASHNV_MASK)

#define PMC_PDSLEEPCFG0_PDEN_PLL0_SSCG_MASK      (0x800000U)
#define PMC_PDSLEEPCFG0_PDEN_PLL0_SSCG_SHIFT     (23U)
/*! PDEN_PLL0_SSCG - Controls PLL0 Spread Sprectrum module power during DEEP-SLEEP (PLL0 Spread
 *    Spectrum is always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..PLL0 Spread Sprectrum module is powered on during low power mode.
 *  0b1..PLL0 Spread Sprectrum module is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_PLL0_SSCG(x)        (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_PLL0_SSCG_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_PLL0_SSCG_MASK)

#define PMC_PDSLEEPCFG0_PDEN_ROM_MASK            (0x1000000U)
#define PMC_PDSLEEPCFG0_PDEN_ROM_SHIFT           (24U)
/*! PDEN_ROM - Controls ROM power during DEEP-SLEEP (ROM is always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..ROM is powered on during low power mode.
 *  0b1..ROM is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_ROM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_ROM_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_ROM_MASK)

#define PMC_PDSLEEPCFG0_PDEN_HSCMP0_MASK         (0x2000000U)
#define PMC_PDSLEEPCFG0_PDEN_HSCMP0_SHIFT        (25U)
/*! PDEN_HSCMP0 - Controls High Speed Comparator0 power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..High Speed Comparator is powered on during low power mode.
 *  0b1..High Speed Comparator is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_HSCMP0(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_HSCMP0_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_HSCMP0_MASK)

#define PMC_PDSLEEPCFG0_PDEN_HSCMP1_MASK         (0x4000000U)
#define PMC_PDSLEEPCFG0_PDEN_HSCMP1_SHIFT        (26U)
/*! PDEN_HSCMP1 - Controls High Speed Comparator1 power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..High Speed Comparator is powered on during low power mode.
 *  0b1..High Speed Comparator is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_HSCMP1(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_HSCMP1_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_HSCMP1_MASK)

#define PMC_PDSLEEPCFG0_PDEN_HSCMP2_MASK         (0x8000000U)
#define PMC_PDSLEEPCFG0_PDEN_HSCMP2_SHIFT        (27U)
/*! PDEN_HSCMP2 - Controls High Speed Comparator2 power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..High Speed Comparator is powered on during low power mode.
 *  0b1..High Speed Comparator is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_HSCMP2(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_HSCMP2_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_HSCMP2_MASK)

#define PMC_PDSLEEPCFG0_PDEN_OPAMP0_MASK         (0x10000000U)
#define PMC_PDSLEEPCFG0_PDEN_OPAMP0_SHIFT        (28U)
/*! PDEN_OPAMP0 - Controls Operational Amplifier0 power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..Operational Amplifier is powered on during low power mode.
 *  0b1..Operational Amplifier is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_OPAMP0(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_OPAMP0_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_OPAMP0_MASK)

#define PMC_PDSLEEPCFG0_PDEN_OPAMP1_MASK         (0x20000000U)
#define PMC_PDSLEEPCFG0_PDEN_OPAMP1_SHIFT        (29U)
/*! PDEN_OPAMP1 - Controls Operational Amplifier1 power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..Operational Amplifier is powered on during low power mode.
 *  0b1..Operational Amplifier is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_OPAMP1(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_OPAMP1_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_OPAMP1_MASK)

#define PMC_PDSLEEPCFG0_PDEN_OPAMP2_MASK         (0x40000000U)
#define PMC_PDSLEEPCFG0_PDEN_OPAMP2_SHIFT        (30U)
/*! PDEN_OPAMP2 - Controls Operational Amplifier2 power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..Operational Amplifier is powered on during low power mode.
 *  0b1..Operational Amplifier is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_OPAMP2(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_OPAMP2_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_OPAMP2_MASK)

#define PMC_PDSLEEPCFG0_PDEN_VREF_MASK           (0x80000000U)
#define PMC_PDSLEEPCFG0_PDEN_VREF_SHIFT          (31U)
/*! PDEN_VREF - Controls VREF power during DEEP-SLEEP (always shut down during POWER-DOWN and DEEP-POWER-DOWN).
 *  0b0..VREF is powered on during low power mode.
 *  0b1..VREF is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_VREF(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_VREF_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_VREF_MASK)
/*! @} */

/*! @name SRAMRETCTRL - SRAM control */
/*! @{ */

#define PMC_SRAMRETCTRL_RETEN_RAM_X0_MASK        (0x1U)
#define PMC_SRAMRETCTRL_RETEN_RAM_X0_SHIFT       (0U)
/*! RETEN_RAM_X0 - Controls RAM_X0 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_X0(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_X0_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_X0_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_00_MASK        (0x2U)
#define PMC_SRAMRETCTRL_RETEN_RAM_00_SHIFT       (1U)
/*! RETEN_RAM_00 - Controls RAM_00 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_00(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_00_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_00_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_01_MASK        (0x4U)
#define PMC_SRAMRETCTRL_RETEN_RAM_01_SHIFT       (2U)
/*! RETEN_RAM_01 - Controls RAM_01 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_01(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_01_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_01_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_02_MASK        (0x8U)
#define PMC_SRAMRETCTRL_RETEN_RAM_02_SHIFT       (3U)
/*! RETEN_RAM_02 - Controls RAM_02 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_02(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_02_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_02_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_03_MASK        (0x10U)
#define PMC_SRAMRETCTRL_RETEN_RAM_03_SHIFT       (4U)
/*! RETEN_RAM_03 - Controls RAM_03 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_03(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_03_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_03_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_10_MASK        (0x20U)
#define PMC_SRAMRETCTRL_RETEN_RAM_10_SHIFT       (5U)
/*! RETEN_RAM_10 - Controls RAM_10 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, whatever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_10(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_10_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_10_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_20_MASK        (0x40U)
#define PMC_SRAMRETCTRL_RETEN_RAM_20_SHIFT       (6U)
/*! RETEN_RAM_20 - Controls RAM_20 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, whatever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_20(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_20_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_20_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_30_MASK        (0x80U)
#define PMC_SRAMRETCTRL_RETEN_RAM_30_SHIFT       (7U)
/*! RETEN_RAM_30 - Controls RAM_30 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, whatever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_30(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_30_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_30_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_40_MASK        (0x100U)
#define PMC_SRAMRETCTRL_RETEN_RAM_40_SHIFT       (8U)
/*! RETEN_RAM_40 - Controls RAM_40 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_40(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_40_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_40_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_41_MASK        (0x200U)
#define PMC_SRAMRETCTRL_RETEN_RAM_41_SHIFT       (9U)
/*! RETEN_RAM_41 - Controls RAM_41 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_41(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_41_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_41_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_42_MASK        (0x400U)
#define PMC_SRAMRETCTRL_RETEN_RAM_42_SHIFT       (10U)
/*! RETEN_RAM_42 - Controls RAM_42 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_42(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_42_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_42_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_43_MASK        (0x800U)
#define PMC_SRAMRETCTRL_RETEN_RAM_43_SHIFT       (11U)
/*! RETEN_RAM_43 - Controls RAM_43 power down modes during low power modes.
 *  0b0..DEEP-SLEEP: the SRAM instance keeps the configuration it has before entering DEEP-SLEEP, what evere it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER-DOWN and DEEP-POWER-DOWN: the SRAM
 *       instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM is in 'Deep Sleep' mode (In this mode there is data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_RAM_43(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_43_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_43_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_FLASHLPCACHE_MASK (0x1000U)
#define PMC_SRAMRETCTRL_RETEN_RAM_FLASHLPCACHE_SHIFT (12U)
/*! RETEN_RAM_FLASHLPCACHE - Controls Embedded Flash Cache SRAM power down modes during low power modes. */
#define PMC_SRAMRETCTRL_RETEN_RAM_FLASHLPCACHE(x) (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_FLASHLPCACHE_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_FLASHLPCACHE_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM_FLEXSPILPCACHE_MASK (0x2000U)
#define PMC_SRAMRETCTRL_RETEN_RAM_FLEXSPILPCACHE_SHIFT (13U)
/*! RETEN_RAM_FLEXSPILPCACHE - Controls FlexSPI Cache SRAM power down modes during low power modes. */
#define PMC_SRAMRETCTRL_RETEN_RAM_FLEXSPILPCACHE(x) (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM_FLEXSPILPCACHE_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM_FLEXSPILPCACHE_MASK)

#define PMC_SRAMRETCTRL_RETEN_H2PREG_FLEXSPI_MASK (0x4000U)
#define PMC_SRAMRETCTRL_RETEN_H2PREG_FLEXSPI_SHIFT (14U)
/*! RETEN_H2PREG_FLEXSPI - Controls FlexSPI Dual Port Register Files power down modes during deep
 *    sleep. In power-down and deep power-down modes, FlexSPI Dual Port Register Files are always
 *    shutoff.
 *  0b0..DEEP-SLEEP: all FlexSPI dual port register files keep the configuration they had before entering
 *       DEEP-SLEEP. POWER-DOWN and DEEP-POWER-DOWN: all FlexSPI dual port register instances are shut off (In this mode
 *       there is no data retention).
 *  0b1..DEEP-SLEEP: all FlexSPI Dual Port egister files are in 'Power Down' mode (In this mode there is data
 *       retention). POWER-DOWN and DEEP-POWER-DOWN: all FlexSPI dual port register instances are shut off (In this
 *       mode there is no data retention).
 */
#define PMC_SRAMRETCTRL_RETEN_H2PREG_FLEXSPI(x)  (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_H2PREG_FLEXSPI_SHIFT)) & PMC_SRAMRETCTRL_RETEN_H2PREG_FLEXSPI_MASK)
/*! @} */

/*! @name PDRUNCFG0 - Power down run configuration 0 */
/*! @{ */

#define PMC_PDRUNCFG0_PDEN_DCDC_MASK             (0x1U)
#define PMC_PDRUNCFG0_PDEN_DCDC_SHIFT            (0U)
/*! PDEN_DCDC - Controls power to Bulk DCDC Converter.
 *  0b0..DCDC is powered.
 *  0b1..DCDC is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_DCDC(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_DCDC_SHIFT)) & PMC_PDRUNCFG0_PDEN_DCDC_MASK)

#define PMC_PDRUNCFG0_PDEN_BIAS_MASK             (0x2U)
#define PMC_PDRUNCFG0_PDEN_BIAS_SHIFT            (1U)
/*! PDEN_BIAS - Controls power to .
 *  0b0..Analog Bias is powered.
 *  0b1..Analog Bias is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_BIAS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BIAS_SHIFT)) & PMC_PDRUNCFG0_PDEN_BIAS_MASK)

#define PMC_PDRUNCFG0_PDEN_BODCORE_MASK          (0x4U)
#define PMC_PDRUNCFG0_PDEN_BODCORE_SHIFT         (2U)
/*! PDEN_BODCORE - Controls power to Core Brown Out Detector (BOD_CORE).
 *  0b0..BOD_CORE is powered.
 *  0b1..BOD_CORE is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_BODCORE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BODCORE_SHIFT)) & PMC_PDRUNCFG0_PDEN_BODCORE_MASK)

#define PMC_PDRUNCFG0_PDEN_BODVDDMAIN_MASK       (0x8U)
#define PMC_PDRUNCFG0_PDEN_BODVDDMAIN_SHIFT      (3U)
/*! PDEN_BODVDDMAIN - Controls power to VDDMAIN Brown Out Detector (BOD_VDDMAIN).
 *  0b0..BOD_VDDMAIN is powered.
 *  0b1..BOD_VDDMAIN is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_BODVDDMAIN(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BODVDDMAIN_SHIFT)) & PMC_PDRUNCFG0_PDEN_BODVDDMAIN_MASK)

#define PMC_PDRUNCFG0_PDEN_FRO192M_MASK          (0x20U)
#define PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT         (5U)
/*! PDEN_FRO192M - Controls power to the Free Running Oscillator (FRO) 192 MHz; The 12MHz, 48 MHz
 *    and 96 MHz clocks are derived from this FRO.
 *  0b0..FRO 192MHz is powered.
 *  0b1..FRO 192MHz is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_FRO192M(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT)) & PMC_PDRUNCFG0_PDEN_FRO192M_MASK)

#define PMC_PDRUNCFG0_PDEN_FRO32K_MASK           (0x40U)
#define PMC_PDRUNCFG0_PDEN_FRO32K_SHIFT          (6U)
/*! PDEN_FRO32K - Controls power to the Free Running Oscillator (FRO) 32 KHz.
 *  0b0..FRO32KHz is powered.
 *  0b1..FRO32KHz is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_FRO32K(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_FRO32K_SHIFT)) & PMC_PDRUNCFG0_PDEN_FRO32K_MASK)

#define PMC_PDRUNCFG0_PDEN_XTAL32K_MASK          (0x80U)
#define PMC_PDRUNCFG0_PDEN_XTAL32K_SHIFT         (7U)
/*! PDEN_XTAL32K - Controls power to crystal 32 KHz.
 *  0b0..Crystal 32KHz is powered.
 *  0b1..Crystal 32KHz is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_XTAL32K(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_XTAL32K_SHIFT)) & PMC_PDRUNCFG0_PDEN_XTAL32K_MASK)

#define PMC_PDRUNCFG0_PDEN_XTALHF_MASK           (0x100U)
#define PMC_PDRUNCFG0_PDEN_XTALHF_SHIFT          (8U)
/*! PDEN_XTALHF - Controls power to high speed crystal.
 *  0b0..High speed crystal is powered.
 *  0b1..High speed crystal is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_XTALHF(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_XTALHF_SHIFT)) & PMC_PDRUNCFG0_PDEN_XTALHF_MASK)

#define PMC_PDRUNCFG0_PDEN_PLL0_MASK             (0x200U)
#define PMC_PDRUNCFG0_PDEN_PLL0_SHIFT            (9U)
/*! PDEN_PLL0 - Controls power to System PLL (also refered as PLL0).
 *  0b0..PLL0 is powered.
 *  0b1..PLL0 is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_PLL0(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_PLL0_SHIFT)) & PMC_PDRUNCFG0_PDEN_PLL0_MASK)

#define PMC_PDRUNCFG0_PDEN_PLL1_MASK             (0x400U)
#define PMC_PDRUNCFG0_PDEN_PLL1_SHIFT            (10U)
/*! PDEN_PLL1 - Controls power to USB PLL (also refered as PLL1).
 *  0b0..PLL1 is powered.
 *  0b1..PLL1 is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_PLL1(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_PLL1_SHIFT)) & PMC_PDRUNCFG0_PDEN_PLL1_MASK)

#define PMC_PDRUNCFG0_PDEN_USBFSPHY_MASK         (0x800U)
#define PMC_PDRUNCFG0_PDEN_USBFSPHY_SHIFT        (11U)
/*! PDEN_USBFSPHY - Controls power to USB Full Speed phy.
 *  0b0..USB Full Speed phy is powered.
 *  0b1..USB Full Speed phy is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_USBFSPHY(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_USBFSPHY_SHIFT)) & PMC_PDRUNCFG0_PDEN_USBFSPHY_MASK)

#define PMC_PDRUNCFG0_PDEN_COMP_MASK             (0x2000U)
#define PMC_PDRUNCFG0_PDEN_COMP_SHIFT            (13U)
/*! PDEN_COMP - Controls power to Analog Comparator.
 *  0b0..Analog Comparator is powered.
 *  0b1..Analog Comparator is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_COMP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_COMP_SHIFT)) & PMC_PDRUNCFG0_PDEN_COMP_MASK)

#define PMC_PDRUNCFG0_PDEN_LDOMEM_MASK           (0x10000U)
#define PMC_PDRUNCFG0_PDEN_LDOMEM_SHIFT          (16U)
/*! PDEN_LDOMEM - Controls power to Memories LDO.
 *  0b0..Memories LDO is powered.
 *  0b1..Memories LDO is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_LDOMEM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_LDOMEM_SHIFT)) & PMC_PDRUNCFG0_PDEN_LDOMEM_MASK)

#define PMC_PDRUNCFG0_PDEN_LDOEFUSEPROG_MASK     (0x40000U)
#define PMC_PDRUNCFG0_PDEN_LDOEFUSEPROG_SHIFT    (18U)
/*! PDEN_LDOEFUSEPROG - Controls power to OTP-eFUSE Programming LDO.
 *  0b0..USB high speed LDO is powered.
 *  0b1..USB high speed LDO is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_LDOEFUSEPROG(x)       (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_LDOEFUSEPROG_SHIFT)) & PMC_PDRUNCFG0_PDEN_LDOEFUSEPROG_MASK)

#define PMC_PDRUNCFG0_PDEN_LDOXTALHF_MASK        (0x100000U)
#define PMC_PDRUNCFG0_PDEN_LDOXTALHF_SHIFT       (20U)
/*! PDEN_LDOXTALHF - Controls power to high speed crystal LDO.
 *  0b0..High speed crystal LDO is powered.
 *  0b1..High speed crystal LDO is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_LDOXTALHF(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_LDOXTALHF_SHIFT)) & PMC_PDRUNCFG0_PDEN_LDOXTALHF_MASK)

#define PMC_PDRUNCFG0_PDEN_LDOFLASHNV_MASK       (0x200000U)
#define PMC_PDRUNCFG0_PDEN_LDOFLASHNV_SHIFT      (21U)
/*! PDEN_LDOFLASHNV - Controls power to Flasn NV (high voltage) LDO.
 *  0b0..Flash NV LDO is powered.
 *  0b1..Flash NV LDO is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_LDOFLASHNV(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_LDOFLASHNV_SHIFT)) & PMC_PDRUNCFG0_PDEN_LDOFLASHNV_MASK)

#define PMC_PDRUNCFG0_PDEN_PLL0_SSCG_MASK        (0x800000U)
#define PMC_PDRUNCFG0_PDEN_PLL0_SSCG_SHIFT       (23U)
/*! PDEN_PLL0_SSCG - Controls power to System PLL (PLL0) Spread Spectrum module.
 *  0b0..PLL0 Sread spectrum module is powered.
 *  0b1..PLL0 Sread spectrum module is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_PLL0_SSCG(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_PLL0_SSCG_SHIFT)) & PMC_PDRUNCFG0_PDEN_PLL0_SSCG_MASK)

#define PMC_PDRUNCFG0_PDEN_HSCMP0_MASK           (0x2000000U)
#define PMC_PDRUNCFG0_PDEN_HSCMP0_SHIFT          (25U)
/*! PDEN_HSCMP0 - Controls power to High Speed Comparator0
 *  0b0..High Speed Comparator0 is powered on.
 *  0b1..High Speed Comparator0 is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_HSCMP0(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_HSCMP0_SHIFT)) & PMC_PDRUNCFG0_PDEN_HSCMP0_MASK)

#define PMC_PDRUNCFG0_PDEN_HSCMP1_MASK           (0x4000000U)
#define PMC_PDRUNCFG0_PDEN_HSCMP1_SHIFT          (26U)
/*! PDEN_HSCMP1 - Controls power to High Speed Comparator1
 *  0b0..High Speed Comparator1 is powered on
 *  0b1..High Speed Comparator1 is powered down
 */
#define PMC_PDRUNCFG0_PDEN_HSCMP1(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_HSCMP1_SHIFT)) & PMC_PDRUNCFG0_PDEN_HSCMP1_MASK)

#define PMC_PDRUNCFG0_PDEN_HSCMP2_MASK           (0x8000000U)
#define PMC_PDRUNCFG0_PDEN_HSCMP2_SHIFT          (27U)
/*! PDEN_HSCMP2 - Controls power to High Speed Comparator2
 *  0b0..High Speed Comparator2 is powered on
 *  0b1..High Speed Comparator2 is powered down
 */
#define PMC_PDRUNCFG0_PDEN_HSCMP2(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_HSCMP2_SHIFT)) & PMC_PDRUNCFG0_PDEN_HSCMP2_MASK)

#define PMC_PDRUNCFG0_PDEN_OPAMP0_MASK           (0x10000000U)
#define PMC_PDRUNCFG0_PDEN_OPAMP0_SHIFT          (28U)
/*! PDEN_OPAMP0 - Controls power to Operational Amplifier0
 *  0b0..Operational Amplifier0 is powered on.
 *  0b1..Operational Amplifier0 is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_OPAMP0(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_OPAMP0_SHIFT)) & PMC_PDRUNCFG0_PDEN_OPAMP0_MASK)

#define PMC_PDRUNCFG0_PDEN_OPAMP1_MASK           (0x20000000U)
#define PMC_PDRUNCFG0_PDEN_OPAMP1_SHIFT          (29U)
/*! PDEN_OPAMP1 - Controls power to Operational Amplifier1
 *  0b0..Operational Amplifier1 is powered on
 *  0b1..Operational Amplifier1 is powered down
 */
#define PMC_PDRUNCFG0_PDEN_OPAMP1(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_OPAMP1_SHIFT)) & PMC_PDRUNCFG0_PDEN_OPAMP1_MASK)

#define PMC_PDRUNCFG0_PDEN_OPAMP2_MASK           (0x40000000U)
#define PMC_PDRUNCFG0_PDEN_OPAMP2_SHIFT          (30U)
/*! PDEN_OPAMP2 - Controls power to Operational Amplifier2
 *  0b0..Operational Amplifier2 is powered on
 *  0b1..Operational Amplifier2 is powered down
 */
#define PMC_PDRUNCFG0_PDEN_OPAMP2(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_OPAMP2_SHIFT)) & PMC_PDRUNCFG0_PDEN_OPAMP2_MASK)

#define PMC_PDRUNCFG0_PDEN_VREF_MASK             (0x80000000U)
#define PMC_PDRUNCFG0_PDEN_VREF_SHIFT            (31U)
/*! PDEN_VREF - Controls power to VREF module
 *  0b0..VREF is powered on.
 *  0b1..VREF is powered down.
 */
#define PMC_PDRUNCFG0_PDEN_VREF(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_VREF_SHIFT)) & PMC_PDRUNCFG0_PDEN_VREF_MASK)
/*! @} */

/*! @name PDRUNCFG1 - Power down run configuration 1 */
/*! @{ */

#define PMC_PDRUNCFG1_PDEN_CMPBIAS_MASK          (0x1U)
#define PMC_PDRUNCFG1_PDEN_CMPBIAS_SHIFT         (0U)
/*! PDEN_CMPBIAS - Controls power of Comparators 1/2/3 bias.
 *  0b0..Comparators 1/2/3 bias is powered.
 *  0b1..Comparators 1/2/3 bias is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_CMPBIAS(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_CMPBIAS_SHIFT)) & PMC_PDRUNCFG1_PDEN_CMPBIAS_MASK)

#define PMC_PDRUNCFG1_PDEN_HSCMP0_DAC_MASK       (0x2U)
#define PMC_PDRUNCFG1_PDEN_HSCMP0_DAC_SHIFT      (1U)
/*! PDEN_HSCMP0_DAC - Controls power to High Speed Comparator0 DAC.
 *  0b0..High Speed Comparator0 DAC is powered.
 *  0b1..High Speed Comparator0 DAC is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_HSCMP0_DAC(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_HSCMP0_DAC_SHIFT)) & PMC_PDRUNCFG1_PDEN_HSCMP0_DAC_MASK)

#define PMC_PDRUNCFG1_PDEN_HSCMP1_DAC_MASK       (0x4U)
#define PMC_PDRUNCFG1_PDEN_HSCMP1_DAC_SHIFT      (2U)
/*! PDEN_HSCMP1_DAC - Controls power to High Speed Comparator1 DAC.
 *  0b0..High Speed Comparator1 DAC is powered.
 *  0b1..High Speed Comparator1 DAC is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_HSCMP1_DAC(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_HSCMP1_DAC_SHIFT)) & PMC_PDRUNCFG1_PDEN_HSCMP1_DAC_MASK)

#define PMC_PDRUNCFG1_PDEN_HSCMP2_DAC_MASK       (0x8U)
#define PMC_PDRUNCFG1_PDEN_HSCMP2_DAC_SHIFT      (3U)
/*! PDEN_HSCMP2_DAC - Controls power to High Speed Comparator2 DAC.
 *  0b0..High Speed Comparator2 DAC is powered.
 *  0b1..High Speed Comparator2 DAC is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_HSCMP2_DAC(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_HSCMP2_DAC_SHIFT)) & PMC_PDRUNCFG1_PDEN_HSCMP2_DAC_MASK)

#define PMC_PDRUNCFG1_PDEN_DAC0_MASK             (0x10U)
#define PMC_PDRUNCFG1_PDEN_DAC0_SHIFT            (4U)
/*! PDEN_DAC0 - Controls power to DAC0.
 *  0b0..DAC0 is powered.
 *  0b1..DAC0 is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_DAC0_SHIFT)) & PMC_PDRUNCFG1_PDEN_DAC0_MASK)

#define PMC_PDRUNCFG1_PDEN_DAC1_MASK             (0x20U)
#define PMC_PDRUNCFG1_PDEN_DAC1_SHIFT            (5U)
/*! PDEN_DAC1 - Controls power to DAC1.
 *  0b0..DAC1 is powered.
 *  0b1..DAC1 is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_DAC1(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_DAC1_SHIFT)) & PMC_PDRUNCFG1_PDEN_DAC1_MASK)

#define PMC_PDRUNCFG1_PDEN_DAC2_MASK             (0x40U)
#define PMC_PDRUNCFG1_PDEN_DAC2_SHIFT            (6U)
/*! PDEN_DAC2 - Controls power to DAC2.
 *  0b0..DAC2 is powered.
 *  0b1..DAC2 is powered down.
 */
#define PMC_PDRUNCFG1_PDEN_DAC2(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PDEN_DAC2_SHIFT)) & PMC_PDRUNCFG1_PDEN_DAC2_MASK)

#define PMC_PDRUNCFG1_STOPEN_DAC0_MASK           (0x80U)
#define PMC_PDRUNCFG1_STOPEN_DAC0_SHIFT          (7U)
/*! STOPEN_DAC0 - Controls DAC0 Stop mode.
 *  0b0..DAC0 Stop mode is disabled.
 *  0b1..DAC0 Stop mode is enabled.
 */
#define PMC_PDRUNCFG1_STOPEN_DAC0(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_STOPEN_DAC0_SHIFT)) & PMC_PDRUNCFG1_STOPEN_DAC0_MASK)

#define PMC_PDRUNCFG1_STOPEN_DAC1_MASK           (0x100U)
#define PMC_PDRUNCFG1_STOPEN_DAC1_SHIFT          (8U)
/*! STOPEN_DAC1 - Controls DAC1 Stop mode.
 *  0b0..DAC1 Stop mode is disabled.
 *  0b1..DAC1 Stop mode is enabled.
 */
#define PMC_PDRUNCFG1_STOPEN_DAC1(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_STOPEN_DAC1_SHIFT)) & PMC_PDRUNCFG1_STOPEN_DAC1_MASK)

#define PMC_PDRUNCFG1_STOPEN_DAC2_MASK           (0x200U)
#define PMC_PDRUNCFG1_STOPEN_DAC2_SHIFT          (9U)
/*! STOPEN_DAC2 - Controls DAC2 Stop mode.
 *  0b0..DAC2 Stop mode is disabled.
 *  0b1..DAC2 Stop mode is enabled.
 */
#define PMC_PDRUNCFG1_STOPEN_DAC2(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_STOPEN_DAC2_SHIFT)) & PMC_PDRUNCFG1_STOPEN_DAC2_MASK)
/*! @} */

/*! @name PDRUNCFGSET0 - Power down run configuration set 0 */
/*! @{ */

#define PMC_PDRUNCFGSET0_PDRUNCFGSET0_MASK       (0xFFFFFFFFU)
#define PMC_PDRUNCFGSET0_PDRUNCFGSET0_SHIFT      (0U)
/*! PDRUNCFGSET0 - Writing ones to this register sets the corresponding bit or bits in the PDRUNCFG0 register, if they are implemented. */
#define PMC_PDRUNCFGSET0_PDRUNCFGSET0(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFGSET0_PDRUNCFGSET0_SHIFT)) & PMC_PDRUNCFGSET0_PDRUNCFGSET0_MASK)
/*! @} */

/*! @name PDRUNCFGSET1 - Power down run configuration set 1 */
/*! @{ */

#define PMC_PDRUNCFGSET1_PDRUNCFGSET1_MASK       (0x3FFU)
#define PMC_PDRUNCFGSET1_PDRUNCFGSET1_SHIFT      (0U)
/*! PDRUNCFGSET1 - Writing ones to this register sets the corresponding bit or bits in the PDRUNCFG0 register, if they are implemented. */
#define PMC_PDRUNCFGSET1_PDRUNCFGSET1(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFGSET1_PDRUNCFGSET1_SHIFT)) & PMC_PDRUNCFGSET1_PDRUNCFGSET1_MASK)
/*! @} */

/*! @name PDRUNCFGCLR0 - Power down run configuration clear 0 */
/*! @{ */

#define PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_MASK       (0xFFFFFFFFU)
#define PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_SHIFT      (0U)
/*! PDRUNCFGCLR0 - Writing ones to this register clears the corresponding bit or bits in the PDRUNCFG0 register, if they are implemented. */
#define PMC_PDRUNCFGCLR0_PDRUNCFGCLR0(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_SHIFT)) & PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_MASK)
/*! @} */

/*! @name PDRUNCFGCLR1 - Power down run configuration clear 1 */
/*! @{ */

#define PMC_PDRUNCFGCLR1_PDRUNCFGCLR1_MASK       (0x3FFU)
#define PMC_PDRUNCFGCLR1_PDRUNCFGCLR1_SHIFT      (0U)
/*! PDRUNCFGCLR1 - Writing ones to this register clears the corresponding bit or bits in the PDRUNCFG0 register, if they are implemented. */
#define PMC_PDRUNCFGCLR1_PDRUNCFGCLR1(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFGCLR1_PDRUNCFGCLR1_SHIFT)) & PMC_PDRUNCFGCLR1_PDRUNCFGCLR1_MASK)
/*! @} */

/*! @name SRAMCTRL - SRAM control */
/*! @{ */

#define PMC_SRAMCTRL_SMB_MASK                    (0x3U)
#define PMC_SRAMCTRL_SMB_SHIFT                   (0U)
/*! SMB - Source Biasing voltage.
 *  0b00..Low leakage.
 *  0b01..Medium leakage.
 *  0b10..Highest leakage.
 *  0b11..Disable.
 */
#define PMC_SRAMCTRL_SMB(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL_SMB_SHIFT)) & PMC_SRAMCTRL_SMB_MASK)
/*! @} */

/*! @name SRAMCTRL0 - SRAM control 0 */
/*! @{ */

#define PMC_SRAMCTRL0_RAM_X0_LS_MASK             (0x1U)
#define PMC_SRAMCTRL0_RAM_X0_LS_SHIFT            (0U)
/*! RAM_X0_LS - RAM_X0 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_X0_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_X0_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_X0_LS_MASK)

#define PMC_SRAMCTRL0_RAM_X0_DSB_MASK            (0x2U)
#define PMC_SRAMCTRL0_RAM_X0_DSB_SHIFT           (1U)
/*! RAM_X0_DSB - RAM_X0 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_X0_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_X0_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_X0_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_X0_DSBDEL_MASK         (0x4U)
#define PMC_SRAMCTRL0_RAM_X0_DSBDEL_SHIFT        (2U)
/*! RAM_X0_DSBDEL - RAM_X0 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_X0_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_X0_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_X0_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_X0_LSDEL_MASK          (0x8U)
#define PMC_SRAMCTRL0_RAM_X0_LSDEL_SHIFT         (3U)
/*! RAM_X0_LSDEL - RAM_X0 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_X0_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_X0_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_X0_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_00_LS_MASK             (0x10U)
#define PMC_SRAMCTRL0_RAM_00_LS_SHIFT            (4U)
/*! RAM_00_LS - RAM_00 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_00_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_00_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_00_LS_MASK)

#define PMC_SRAMCTRL0_RAM_00_DSB_MASK            (0x20U)
#define PMC_SRAMCTRL0_RAM_00_DSB_SHIFT           (5U)
/*! RAM_00_DSB - RAM_00 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_00_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_00_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_00_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_00_DSBDEL_MASK         (0x40U)
#define PMC_SRAMCTRL0_RAM_00_DSBDEL_SHIFT        (6U)
/*! RAM_00_DSBDEL - RAM_00 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_00_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_00_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_00_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_00_LSDEL_MASK          (0x80U)
#define PMC_SRAMCTRL0_RAM_00_LSDEL_SHIFT         (7U)
/*! RAM_00_LSDEL - RAM_00 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_00_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_00_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_00_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_01_LS_MASK             (0x100U)
#define PMC_SRAMCTRL0_RAM_01_LS_SHIFT            (8U)
/*! RAM_01_LS - RAM_01 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_01_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_01_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_01_LS_MASK)

#define PMC_SRAMCTRL0_RAM_01_DSB_MASK            (0x200U)
#define PMC_SRAMCTRL0_RAM_01_DSB_SHIFT           (9U)
/*! RAM_01_DSB - RAM_01 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_01_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_01_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_01_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_01_DSBDEL_MASK         (0x400U)
#define PMC_SRAMCTRL0_RAM_01_DSBDEL_SHIFT        (10U)
/*! RAM_01_DSBDEL - RAM_01 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_01_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_01_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_01_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_01_LSDEL_MASK          (0x800U)
#define PMC_SRAMCTRL0_RAM_01_LSDEL_SHIFT         (11U)
/*! RAM_01_LSDEL - RAM_01 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_01_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_01_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_01_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_02_LS_MASK             (0x1000U)
#define PMC_SRAMCTRL0_RAM_02_LS_SHIFT            (12U)
/*! RAM_02_LS - RAM_02 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_02_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_02_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_02_LS_MASK)

#define PMC_SRAMCTRL0_RAM_02_DSB_MASK            (0x2000U)
#define PMC_SRAMCTRL0_RAM_02_DSB_SHIFT           (13U)
/*! RAM_02_DSB - RAM_02 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_02_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_02_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_02_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_02_DSBDEL_MASK         (0x4000U)
#define PMC_SRAMCTRL0_RAM_02_DSBDEL_SHIFT        (14U)
/*! RAM_02_DSBDEL - RAM_02 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_02_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_02_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_02_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_02_LSDEL_MASK          (0x8000U)
#define PMC_SRAMCTRL0_RAM_02_LSDEL_SHIFT         (15U)
/*! RAM_02_LSDEL - RAM_02 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_02_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_02_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_02_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_03_LS_MASK             (0x10000U)
#define PMC_SRAMCTRL0_RAM_03_LS_SHIFT            (16U)
/*! RAM_03_LS - RAM_03 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_03_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_03_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_03_LS_MASK)

#define PMC_SRAMCTRL0_RAM_03_DSB_MASK            (0x20000U)
#define PMC_SRAMCTRL0_RAM_03_DSB_SHIFT           (17U)
/*! RAM_03_DSB - RAM_03 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_03_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_03_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_03_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_03_DSBDEL_MASK         (0x40000U)
#define PMC_SRAMCTRL0_RAM_03_DSBDEL_SHIFT        (18U)
/*! RAM_03_DSBDEL - RAM_03 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_03_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_03_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_03_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_03_LSDEL_MASK          (0x80000U)
#define PMC_SRAMCTRL0_RAM_03_LSDEL_SHIFT         (19U)
/*! RAM_03_LSDEL - RAM_03 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_03_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_03_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_03_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_10_LS_MASK             (0x100000U)
#define PMC_SRAMCTRL0_RAM_10_LS_SHIFT            (20U)
/*! RAM_10_LS - RAM_10 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_10_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_10_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_10_LS_MASK)

#define PMC_SRAMCTRL0_RAM_10_DSB_MASK            (0x200000U)
#define PMC_SRAMCTRL0_RAM_10_DSB_SHIFT           (21U)
/*! RAM_10_DSB - RAM_10 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_10_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_10_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_10_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_10_DSBDEL_MASK         (0x400000U)
#define PMC_SRAMCTRL0_RAM_10_DSBDEL_SHIFT        (22U)
/*! RAM_10_DSBDEL - RAM_10 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_10_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_10_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_10_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_10_LSDEL_MASK          (0x800000U)
#define PMC_SRAMCTRL0_RAM_10_LSDEL_SHIFT         (23U)
/*! RAM_10_LSDEL - RAM_10 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_10_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_10_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_10_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_20_LS_MASK             (0x1000000U)
#define PMC_SRAMCTRL0_RAM_20_LS_SHIFT            (24U)
/*! RAM_20_LS - RAM_20 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_20_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_20_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_20_LS_MASK)

#define PMC_SRAMCTRL0_RAM_20_DSB_MASK            (0x2000000U)
#define PMC_SRAMCTRL0_RAM_20_DSB_SHIFT           (25U)
/*! RAM_20_DSB - RAM_20 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_20_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_20_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_20_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_20_DSBDEL_MASK         (0x4000000U)
#define PMC_SRAMCTRL0_RAM_20_DSBDEL_SHIFT        (26U)
/*! RAM_20_DSBDEL - RAM_20 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_20_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_20_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_20_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_20_LSDEL_MASK          (0x8000000U)
#define PMC_SRAMCTRL0_RAM_20_LSDEL_SHIFT         (27U)
/*! RAM_20_LSDEL - RAM_20 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM_20_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_20_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_20_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM_30_LS_MASK             (0x10000000U)
#define PMC_SRAMCTRL0_RAM_30_LS_SHIFT            (28U)
/*! RAM_30_LS - RAM_30 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM_30_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_30_LS_SHIFT)) & PMC_SRAMCTRL0_RAM_30_LS_MASK)

#define PMC_SRAMCTRL0_RAM_30_DSB_MASK            (0x20000000U)
#define PMC_SRAMCTRL0_RAM_30_DSB_SHIFT           (29U)
/*! RAM_30_DSB - RAM_30 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM_30_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_30_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM_30_DSB_MASK)

#define PMC_SRAMCTRL0_RAM_30_DSBDEL_MASK         (0x40000000U)
#define PMC_SRAMCTRL0_RAM_30_DSBDEL_SHIFT        (30U)
/*! RAM_30_DSBDEL - RAM_30 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM_30_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_30_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_30_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM_30_LSDEL_MASK          (0x80000000U)
#define PMC_SRAMCTRL0_RAM_30_LSDEL_SHIFT         (31U)
/*! RAM_30_LSDEL - RAM_30 Light Sleep mode delayed. */
#define PMC_SRAMCTRL0_RAM_30_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM_30_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM_30_LSDEL_MASK)
/*! @} */

/*! @name SRAMCTRL1 - SRAM control 1 */
/*! @{ */

#define PMC_SRAMCTRL1_RAM_40_LS_MASK             (0x1U)
#define PMC_SRAMCTRL1_RAM_40_LS_SHIFT            (0U)
/*! RAM_40_LS - RAM_40 Light Sleep mode. */
#define PMC_SRAMCTRL1_RAM_40_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_40_LS_SHIFT)) & PMC_SRAMCTRL1_RAM_40_LS_MASK)

#define PMC_SRAMCTRL1_RAM_40_DSB_MASK            (0x2U)
#define PMC_SRAMCTRL1_RAM_40_DSB_SHIFT           (1U)
/*! RAM_40_DSB - RAM_40 Deep sleep mode. */
#define PMC_SRAMCTRL1_RAM_40_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_40_DSB_SHIFT)) & PMC_SRAMCTRL1_RAM_40_DSB_MASK)

#define PMC_SRAMCTRL1_RAM_40_DSBDEL_MASK         (0x4U)
#define PMC_SRAMCTRL1_RAM_40_DSBDEL_SHIFT        (2U)
/*! RAM_40_DSBDEL - RAM_40 Deep sleep delayed. */
#define PMC_SRAMCTRL1_RAM_40_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_40_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_40_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAM_40_LSDEL_MASK          (0x8U)
#define PMC_SRAMCTRL1_RAM_40_LSDEL_SHIFT         (3U)
/*! RAM_40_LSDEL - RAM_40 Sleep mode disable. */
#define PMC_SRAMCTRL1_RAM_40_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_40_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_40_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAM_41_LS_MASK             (0x10U)
#define PMC_SRAMCTRL1_RAM_41_LS_SHIFT            (4U)
/*! RAM_41_LS - RAM_41 Light Sleep mode. */
#define PMC_SRAMCTRL1_RAM_41_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_41_LS_SHIFT)) & PMC_SRAMCTRL1_RAM_41_LS_MASK)

#define PMC_SRAMCTRL1_RAM_41_DSB_MASK            (0x20U)
#define PMC_SRAMCTRL1_RAM_41_DSB_SHIFT           (5U)
/*! RAM_41_DSB - RAM_41 Deep sleep mode. */
#define PMC_SRAMCTRL1_RAM_41_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_41_DSB_SHIFT)) & PMC_SRAMCTRL1_RAM_41_DSB_MASK)

#define PMC_SRAMCTRL1_RAM_41_DSBDEL_MASK         (0x40U)
#define PMC_SRAMCTRL1_RAM_41_DSBDEL_SHIFT        (6U)
/*! RAM_41_DSBDEL - RAM_41 Deep sleep delayed. */
#define PMC_SRAMCTRL1_RAM_41_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_41_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_41_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAM_41_LSDEL_MASK          (0x80U)
#define PMC_SRAMCTRL1_RAM_41_LSDEL_SHIFT         (7U)
/*! RAM_41_LSDEL - RAM_41 Sleep mode disable. */
#define PMC_SRAMCTRL1_RAM_41_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_41_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_41_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAM_42_LS_MASK             (0x100U)
#define PMC_SRAMCTRL1_RAM_42_LS_SHIFT            (8U)
/*! RAM_42_LS - RAM_42 Light Sleep mode. */
#define PMC_SRAMCTRL1_RAM_42_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_42_LS_SHIFT)) & PMC_SRAMCTRL1_RAM_42_LS_MASK)

#define PMC_SRAMCTRL1_RAM_42_DSB_MASK            (0x200U)
#define PMC_SRAMCTRL1_RAM_42_DSB_SHIFT           (9U)
/*! RAM_42_DSB - RAM_42 Deep sleep mode. */
#define PMC_SRAMCTRL1_RAM_42_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_42_DSB_SHIFT)) & PMC_SRAMCTRL1_RAM_42_DSB_MASK)

#define PMC_SRAMCTRL1_RAM_42_DSBDEL_MASK         (0x400U)
#define PMC_SRAMCTRL1_RAM_42_DSBDEL_SHIFT        (10U)
/*! RAM_42_DSBDEL - RAM_42 Deep sleep delayed. */
#define PMC_SRAMCTRL1_RAM_42_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_42_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_42_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAM_42_LSDEL_MASK          (0x800U)
#define PMC_SRAMCTRL1_RAM_42_LSDEL_SHIFT         (11U)
/*! RAM_42_LSDEL - RAM_42 Sleep mode disable. */
#define PMC_SRAMCTRL1_RAM_42_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_42_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_42_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAM_43_LS_MASK             (0x1000U)
#define PMC_SRAMCTRL1_RAM_43_LS_SHIFT            (12U)
/*! RAM_43_LS - RAM_43 Light Sleep mode. */
#define PMC_SRAMCTRL1_RAM_43_LS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_43_LS_SHIFT)) & PMC_SRAMCTRL1_RAM_43_LS_MASK)

#define PMC_SRAMCTRL1_RAM_43_DSB_MASK            (0x2000U)
#define PMC_SRAMCTRL1_RAM_43_DSB_SHIFT           (13U)
/*! RAM_43_DSB - RAM_43 Deep sleep mode. */
#define PMC_SRAMCTRL1_RAM_43_DSB(x)              (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_43_DSB_SHIFT)) & PMC_SRAMCTRL1_RAM_43_DSB_MASK)

#define PMC_SRAMCTRL1_RAM_43_DSBDEL_MASK         (0x4000U)
#define PMC_SRAMCTRL1_RAM_43_DSBDEL_SHIFT        (14U)
/*! RAM_43_DSBDEL - RAM_43 Deep sleep delayed. */
#define PMC_SRAMCTRL1_RAM_43_DSBDEL(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_43_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_43_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAM_43_LSDEL_MASK          (0x8000U)
#define PMC_SRAMCTRL1_RAM_43_LSDEL_SHIFT         (15U)
/*! RAM_43_LSDEL - RAM_43 Sleep mode disable. */
#define PMC_SRAMCTRL1_RAM_43_LSDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_43_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_43_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LS_MASK   (0x10000U)
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LS_SHIFT  (16U)
/*! RAM_FLASHLPCACHE_LS - Flash Cache RAM Light Sleep mode. */
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LS(x)     (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LS_SHIFT)) & PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LS_MASK)

#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSB_MASK  (0x20000U)
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSB_SHIFT (17U)
/*! RAM_FLASHLPCACHE_DSB - Flash Cache RAM Deep sleep mode. */
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSB(x)    (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSB_SHIFT)) & PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSB_MASK)

#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSBDEL_MASK (0x40000U)
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSBDEL_SHIFT (18U)
/*! RAM_FLASHLPCACHE_DSBDEL - Flash Cache RAM Deep sleep delayed. */
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSBDEL(x) (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_FLASHLPCACHE_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LSDEL_MASK (0x80000U)
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LSDEL_SHIFT (19U)
/*! RAM_FLASHLPCACHE_LSDEL - Flash Cache RAM Sleep mode disable. */
#define PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LSDEL(x)  (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_FLASHLPCACHE_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LS_MASK (0x100000U)
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LS_SHIFT (20U)
/*! RAM_FLEXSPILPCACHE_LS - Flex SPI Cache RAM Light Sleep mode. */
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LS(x)   (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LS_SHIFT)) & PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LS_MASK)

#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSB_MASK (0x200000U)
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSB_SHIFT (21U)
/*! RAM_FLEXSPILPCACHE_DSB - Flex SPI Cache RAM Deep sleep mode. */
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSB(x)  (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSB_SHIFT)) & PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSB_MASK)

#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSBDEL_MASK (0x400000U)
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSBDEL_SHIFT (22U)
/*! RAM_FLEXSPILPCACHE_DSBDEL - Flex SPI Cache RAM Deep sleep delayed. */
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSBDEL(x) (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LSDEL_MASK (0x800000U)
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LSDEL_SHIFT (23U)
/*! RAM_FLEXSPILPCACHE_LSDEL - Flex SPI Cache RAM Sleep mode disable. */
#define PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LSDEL(x) (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAM_FLEXSPILPCACHE_LSDEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC_H_ */

