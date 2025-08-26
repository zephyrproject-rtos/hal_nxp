/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250624
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
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
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

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
  __IO uint32_t CTRL;                              /**< Power Management Control [Reset by: PoR, Pin Reset, Software Reset], offset: 0x0 */
  __I  uint32_t STATUS;                            /**< Power Management Controller FSM (Finite State Machines) status, offset: 0x4 */
  __IO uint32_t RESETCTRL;                         /**< Reset Control [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0x8 */
  __IO uint32_t RESETCAUSE;                        /**< Reset Cause register [Reset by: PoR], offset: 0xC */
  __IO uint32_t DCDC0;                             /**< DCDC control register [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t BIAS;                              /**< Bias current source control register [Reset by: PoR, Pin Reset, Software Reset], offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t LDOMEM;                            /**< LDOMEM, offset: 0x20 */
  __IO uint32_t LDODIG;                            /**< LDODIG, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t BOD1;                              /**< BOD1, offset: 0x30 */
  __IO uint32_t BOD2;                              /**< BOD2, offset: 0x34 */
       uint8_t RESERVED_3[8];
  __IO uint32_t FRO192M;                           /**< FRO192M, offset: 0x40 */
  __IO uint32_t FRO1M;                             /**< 1 MHz Free Running Oscillator control register, offset: 0x44 */
  __IO uint32_t FRO32K;                            /**< 32 KHz Free Running Oscillator (FRO) control register, offset: 0x48 */
  __IO uint32_t XTAL32K;                           /**< 32 KHz Crystal oscillator (XTAL) control register, offset: 0x4C */
       uint8_t RESERVED_4[4];
  __IO uint32_t XTALBLE;                           /**< BLE XTAL overrule, offset: 0x54 */
       uint8_t RESERVED_5[12];
  __IO uint32_t WAKEUPIOCTRL;                      /**< WAKEUPIOCTRL, offset: 0x64 */
  __I  uint32_t WAKEIOCAUSE;                       /**< Allows to identify the Wake-up I/O source from Deep Power Down mode, offset: 0x68 */
       uint8_t RESERVED_6[4];
  __I  uint32_t STATUSPWR;                         /**< STATUSPWR, offset: 0x70 */
  __I  uint32_t STATUSCLK;                         /**< FRO and XTAL status register [Reset by: PoR, Brown Out Detectors Reset], offset: 0x74 */
       uint8_t RESERVED_7[8];
  __IO uint32_t AOREG0;                            /**< Write-once general purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset], offset: 0x80 */
  __IO uint32_t AOREG1;                            /**< General purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset], offset: 0x84 */
  __IO uint32_t AOREG2;                            /**< AOREG2, offset: 0x88 */
       uint8_t RESERVED_8[12];
  __IO uint32_t RTCOSC32K;                         /**< RTC 1 KHZ and 1 Hz clocks source control register [Reset by: PoR, Brown Out Detectors Reset], offset: 0x98 */
  __IO uint32_t OSTIMERr;                          /**< OS Timer control register [Reset by: PoR, Brown Out Detectors Reset], offset: 0x9C, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'OSTIMER' */
       uint8_t RESERVED_9[4];
  __IO uint32_t TIMEOUTEVENTS;                     /**< Record time-out errors that might occur at different stages during IC power up, offset: 0xA4 */
  __IO uint32_t TIMEOUT;                           /**< TIMEOUT, offset: 0xA8 */
       uint8_t RESERVED_10[4];
  __IO uint32_t PDSLEEPCFG0;                       /**< Controls the power to various modules during Low Power modes - DEEP SLEEP, POWER DOWN and DEEP POWER DOWN [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Software Reset], offset: 0xB0 */
  __IO uint32_t SRAMRETCTRL;                       /**< SRAMRETCTRL, offset: 0xB4 */
  __IO uint32_t PDRUNCFG0;                         /**< PDRUNCFG0, offset: 0xB8 */
       uint8_t RESERVED_11[4];
  __O  uint32_t PDRUNCFGSET0;                      /**< Controls the power to various analog blocks [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0xC0 */
       uint8_t RESERVED_12[4];
  __O  uint32_t PDRUNCFGCLR0;                      /**< Controls the power to various analog blocks [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0xC8 */
       uint8_t RESERVED_13[4];
  __IO uint32_t ROMCTRL;                           /**< ROM control [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0xD0 */
  __IO uint32_t SRAMCTRL;                          /**< All SRAMs common control signals [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Software Reset], offset: 0xD4 */
  __IO uint32_t SRAMCTRL0;                         /**< RAMX0 to RAM20 power modes controls [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] When [LS, LSDEL, DSB, DSBDEL] is: 0011 : Normal Mode 1111 : Light sleep mode 0100 : Deep-sleep mode 1100 : Shut down Mode, offset: 0xD8 */
  __IO uint32_t SRAMCTRL1;                         /**< BLE RAM power mode controls, offset: 0xDC */
  __IO uint32_t SRAMASSISTCTRL0;                   /**< SRAMASSISTCTRL0, offset: 0xE0 */
  __IO uint32_t SRAMASSISTCTRL1;                   /**< SRAMASSISTCTRL1, offset: 0xE4 */
       uint8_t RESERVED_14[16];
  __IO uint32_t DFTENDIS;                          /**< DFTENDIS, offset: 0xF8 */
  __IO uint32_t DFTDCDC;                           /**< DFTDCDC, offset: 0xFC */
  __IO uint32_t DFTCAPTEST;                        /**< DFTCAPTEST, offset: 0x100 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name CTRL - Power Management Control [Reset by: PoR, Pin Reset, Software Reset] */
/*! @{ */

#define PMC_CTRL_LPMODE_MASK                     (0x3U)
#define PMC_CTRL_LPMODE_SHIFT                    (0U)
/*! LPMODE - Power Mode Control.
 *  0b00..ACTIVE power mode.
 *  0b01..DEEP SLEEP low power mode.
 *  0b10..POWER DOWN low power mode.
 *  0b11..DEEP POWER DOWN low power mode.
 */
#define PMC_CTRL_LPMODE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LPMODE_SHIFT)) & PMC_CTRL_LPMODE_MASK)

#define PMC_CTRL_SELCLOCK_MASK                   (0xCU)
#define PMC_CTRL_SELCLOCK_SHIFT                  (2U)
/*! SELCLOCK - Select the Power Management Controller (PMC) functional clock : .
 *  0b00..1 MHz Free Running Oscillator.
 *  0b01..12 MHz Free Running Oscillator.
 *  0b10..32kHz RTC clock.
 */
#define PMC_CTRL_SELCLOCK(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_SELCLOCK_SHIFT)) & PMC_CTRL_SELCLOCK_MASK)

#define PMC_CTRL_POFFMODE_MASK                   (0x10U)
#define PMC_CTRL_POFFMODE_SHIFT                  (4U)
/*! POFFMODE - Power Off Mode Control
 *  0b0..Power Mode defined by LPMODE
 *  0b1..PowerOff
 */
#define PMC_CTRL_POFFMODE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_POFFMODE_SHIFT)) & PMC_CTRL_POFFMODE_MASK)
/*! @} */

/*! @name STATUS - Power Management Controller FSM (Finite State Machines) status */
/*! @{ */

#define PMC_STATUS_FSMMAIN_MASK                  (0x7U)
#define PMC_STATUS_FSMMAIN_SHIFT                 (0U)
/*! FSMMAIN - Power Management Controller Main Finite State Machine (FSM) status
 *  0b000..POWER UP : The IC is powering up.
 *  0b001..ACTIVE : Power up is completed. The IC is in normal functional operation mode..
 *  0b010..DEEP SLEEP: The IC has entered DEEP SLEEP mode.
 *  0b011..SLEEP : the IC has entered SLEEP mode.
 *  0b100..IC Structural TEST Mode : The IC has entered in IC Test mode.
 *  0b101..POWERDOWN: The IC has entered POWER OFF mode.
 *  0b110..POWERDOWN: The IC has entered POWER DOWN mode.
 *  0b111..DEEP POWER DOWN : The IC entred DEEP POWER DOWN mode.
 */
#define PMC_STATUS_FSMMAIN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMMAIN_SHIFT)) & PMC_STATUS_FSMMAIN_MASK)

#define PMC_STATUS_FSMPWUP_MASK                  (0x78U)
#define PMC_STATUS_FSMPWUP_SHIFT                 (3U)
/*! FSMPWUP - POWER UP Finite State Machine (FSM) status
 *  0b0000..RESET : The IC is powering up - reset state.
 *  0b0001..ENABLE_DCDC : The IC is powering up - enable DCDC.
 *  0b0010..SWITCH_DOMAINS : The IC is powering up - switch domains.
 *  0b0011..ENABLE_LDO : The IC is powering up - enable LDO.
 *  0b0100..ACTIVATE_MEM : The IC is powering up - activate memories
 *  0b0101..RELEASE_ISOLATIONS : The IC is powering up - release isolations
 *  0b0110..ENA_FLASH : The IC is powering up - enable flash
 *  0b0111..WAIT_FRO192M : The IC is powering up - wait on FRO192M
 *  0b1010..DONE : The IC is powering up - done
 *  0b1100..RELEASE_RESET : The IC is powering up - release reset
 *  0b1101..TRANSFER_TRIM : The IC is powering up - transfer trim
 *  0b1110..SWITCH_CLOCK : The IC is powering up - switch clock
 *  0b1111..RELEASE_CPU : The IC is powering up - release CPU
 */
#define PMC_STATUS_FSMPWUP(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMPWUP_SHIFT)) & PMC_STATUS_FSMPWUP_MASK)

#define PMC_STATUS_FSMDSLP_MASK                  (0x780U)
#define PMC_STATUS_FSMDSLP_SHIFT                 (7U)
/*! FSMDSLP - DEEP SLEEP Finite State Machine (FSM) status
 *  0b0000..IDLE : The IC is entering deep sleep - idle state.
 *  0b0001..PREPARE : The IC is entering deep sleep - prepare.
 *  0b0010..DISABLE_FRO : The IC is entering deep sleep - disable FRO.
 *  0b0011..SWITCH_TO_DEEPSLEEP : The IC is entering deep sleep - switch to deepsleep.
 *  0b0100..ENABLE_LDO : The IC is exiting deep sleep - enable LDO.
 *  0b0101..ENABLE_DCDC : The IC is exiting deep sleep - enable DCDC.
 *  0b0110..DONE : The IC is entering deep sleep - done.
 *  0b0111..PWRUP_BG : The IC is exiting deep sleep - power-up bandgap.
 *  0b1010..PWRUP_DONE : The IC is exiting deep sleep - power-up done.
 *  0b1100..SWITCH_DOMAINS : The IC is exiting deep sleep - switch domains.
 *  0b1101..ENABLE_FLASH : The IC is exiting deep sleep - enable flash.
 *  0b1110..ACTIVATE_SRAM : The IC is exiting deep sleep - activate SRAM.
 *  0b1111..PWUP_WAIT_FRO192M : The IC is exiting deep sleep - wait on FRO192M.
 */
#define PMC_STATUS_FSMDSLP(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMDSLP_SHIFT)) & PMC_STATUS_FSMDSLP_MASK)

#define PMC_STATUS_FSMPWDN_MASK                  (0x7800U)
#define PMC_STATUS_FSMPWDN_SHIFT                 (11U)
/*! FSMPWDN - POWER DOWN Finite State Machine (FSM) status
 *  0b0000..IDLE : The IC is entering power down - idle state.
 *  0b0001..DISABLE : The IC is entering power down - disable.
 *  0b0010..POWER_SHUTOFF : The IC is entering power down - power shutoff.
 *  0b0011..SHUTOFF : The IC is entering power down - shutoff.
 *  0b0100..PWRUP_ENABLE_DCDC : The IC is exiting power down - enable DCDC.
 *  0b0101..PWRUP_BG : The IC is exiting power down - power-up bandgap.
 *  0b0110..DISABLE_FRO : The IC is entering power down - disable FRO.
 *  0b0111..DONE : The IC is entering power down - done.
 *  0b1010..PWRUP_INIT_FLASH : The IC is exiting power down - power-up flash initialization.
 *  0b1011..PWRUP_DONE : The IC is exiting deep sleep - power-up done.
 *  0b1100..PWRUP_ENABLE_LDO : The IC is exiting power down - enable LDO.
 *  0b1101..PWUP_SWITCH_DOMAINS : The IC is exiting power down - power-up switch domains.
 *  0b1110..PWRUP_RELEASE_ISOLATION : The IC is exiting power down - power-up release isolation.
 *  0b1111..PWRUP_WAIT_FRO192M : The IC is exiting power down - power-up wait for FRO192M.
 */
#define PMC_STATUS_FSMPWDN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMPWDN_SHIFT)) & PMC_STATUS_FSMPWDN_MASK)

#define PMC_STATUS_FSMDPWD_MASK                  (0x38000U)
#define PMC_STATUS_FSMDPWD_SHIFT                 (15U)
/*! FSMDPWD - DEEP POWER DOWN Finite State Machine (FSM) status
 *  0b000..INIT : The IC is entering deep power down - initialization.
 *  0b001..POWER_SHUTOFF : The IC is entering deep power down - power shutoff.
 *  0b010..DONE : The IC is entering deep power down - done.
 *  0b011..DISABLE_FRO : The IC is entering deep power down - disable FRO.
 */
#define PMC_STATUS_FSMDPWD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMDPWD_SHIFT)) & PMC_STATUS_FSMDPWD_MASK)

#define PMC_STATUS_BOOTMODE_MASK                 (0xC0000U)
#define PMC_STATUS_BOOTMODE_SHIFT                (18U)
/*! BOOTMODE - Latest IC Boot cause:.
 *  0b00..Latest IC boot was a Full power cycle boot sequence (PoR, Pin Reset, Brown Out Detectors Reset, Software Reset).
 *  0b01..Latest IC boot was from DEEP SLEEP low power mode.
 *  0b10..Latest IC boot was from POWER DOWN low power mode.
 *  0b11..Latest IC boot was from DEEP POWER DOWN low power mode.
 */
#define PMC_STATUS_BOOTMODE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_BOOTMODE_SHIFT)) & PMC_STATUS_BOOTMODE_MASK)

#define PMC_STATUS_FSMBLESTATE_MASK              (0x1F00000U)
#define PMC_STATUS_FSMBLESTATE_SHIFT             (20U)
/*! FSMBLESTATE - Bluetooth Low Energy Finite State Machine (FSM) status
 *  0b00000..BLE Power FSM : Reset
 *  0b00001..BLE Power FSM : Link layer and memory enable
 *  0b00010..BLE Power FSM : Enable clock out
 *  0b00011..BLE Power FSM : Enable oscillator
 *  0b00100..BLE Power FSM : Low Power Mode - link Layer deep sleep and phy shutdown
 *  0b00101..BLE Power FSM : Low Power Mode disable oscillator
 *  0b00110..BLE Power FSM : Radio active
 *  0b00111..BLE Power FSM : Low Power Mode assert isolations and resets
 *  0b01000..BLE Power FSM : Power off mode - trigger hresetn
 *  0b01001..BLE Power FSM : Power off mode - radio restart
 *  0b01010..BLE Power FSM : Power off mode - remove power
 *  0b01011..BLE Power FSM : Power off mode - radio off
 *  0b01100..BLE Power FSM : Low Power Mode - radio restart
 *  0b01101..BLE Power FSM : Low Power Mode - enable oscillator
 *  0b01110..BLE Power FSM : Power off mode - assert isolation and resets
 *  0b01111..BLE Power FSM : Low Power Mode - enable clock output
 *  0b11000..BLE Power FSM : Power off mode - enable oscillator
 *  0b11001..BLE Power FSM : Power off mode - enable clock out
 */
#define PMC_STATUS_FSMBLESTATE(x)                (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_FSMBLESTATE_SHIFT)) & PMC_STATUS_FSMBLESTATE_MASK)
/*! @} */

/*! @name RESETCTRL - Reset Control [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] */
/*! @{ */

#define PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK  (0x1U)
#define PMC_RESETCTRL_DPDWAKEUPRESETENABLE_SHIFT (0U)
/*! DPDWAKEUPRESETENABLE - Wake-up from DEEP POWER DOWN reset event (either from wake up I/O or RTC enable).
 *  0b0..Reset event from DEEP POWER DOWN mode is disable.
 *  0b1..Reset event from DEEP POWER DOWN mode is enable.
 */
#define PMC_RESETCTRL_DPDWAKEUPRESETENABLE(x)    (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_DPDWAKEUPRESETENABLE_SHIFT)) & PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK)

#define PMC_RESETCTRL_SWRRESETENABLE_MASK        (0x8U)
#define PMC_RESETCTRL_SWRRESETENABLE_SHIFT       (3U)
/*! SWRRESETENABLE - Software reset enable.
 *  0b0..Software reset is disable.
 *  0b1..Software reset is enable.
 */
#define PMC_RESETCTRL_SWRRESETENABLE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_SWRRESETENABLE_SHIFT)) & PMC_RESETCTRL_SWRRESETENABLE_MASK)

#define PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK   (0x30U)
#define PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT  (4U)
/*! BOD1RESETENA_SECURE - BOD1 reset enable.
 *  0b01..Any other value than b10, BOD1 reset is enable.
 *  0b10..BOD1 reset is disable.
 */
#define PMC_RESETCTRL_BOD1RESETENA_SECURE(x)     (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT)) & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK)

#define PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK   (0xC0U)
#define PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT  (6U)
/*! BOD2RESETENA_SECURE - BOD2 reset enable.
 *  0b01..Any other value than b10, BOD2 reset is enable.
 *  0b10..BOD2 reset is disable.
 */
#define PMC_RESETCTRL_BOD2RESETENA_SECURE(x)     (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT)) & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK)

#define PMC_RESETCTRL_CRCERRORRESETENABLE_MASK   (0x100U)
#define PMC_RESETCTRL_CRCERRORRESETENABLE_SHIFT  (8U)
/*! CRCERRORRESETENABLE - CPU retention CRC error reset enable.
 *  0b0..CPU retention CRC error reset is disable.
 *  0b1..CPU retention CRC error reset is enable.
 */
#define PMC_RESETCTRL_CRCERRORRESETENABLE(x)     (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_CRCERRORRESETENABLE_SHIFT)) & PMC_RESETCTRL_CRCERRORRESETENABLE_MASK)

#define PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK (0x30000000U)
#define PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT (28U)
/*! BOD1RESETENA_SECURE_DP - BOD1 reset enable.
 *  0b01..Any other value than b10, BOD1 reset is enable.
 *  0b10..BOD1 reset is disable.
 */
#define PMC_RESETCTRL_BOD1RESETENA_SECURE_DP(x)  (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT)) & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK)

#define PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK (0xC0000000U)
#define PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT (30U)
/*! BOD2RESETENA_SECURE_DP - BOD2 reset enable.
 *  0b01..Any other value than b10, BOD2 reset is enable.
 *  0b10..BOD2 reset is disable.
 */
#define PMC_RESETCTRL_BOD2RESETENA_SECURE_DP(x)  (((uint32_t)(((uint32_t)(x)) << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT)) & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK)
/*! @} */

/*! @name RESETCAUSE - Reset Cause register [Reset by: PoR] */
/*! @{ */

#define PMC_RESETCAUSE_POR_MASK                  (0x1U)
#define PMC_RESETCAUSE_POR_SHIFT                 (0U)
/*! POR - 1 : The last chip reset was caused by a Power On Reset. Write '1' to clear this bit. */
#define PMC_RESETCAUSE_POR(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_POR_SHIFT)) & PMC_RESETCAUSE_POR_MASK)

#define PMC_RESETCAUSE_PADRESET_MASK             (0x2U)
#define PMC_RESETCAUSE_PADRESET_SHIFT            (1U)
/*! PADRESET - 1 : The last chip reset was caused by a Pin Reset. */
#define PMC_RESETCAUSE_PADRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_PADRESET_SHIFT)) & PMC_RESETCAUSE_PADRESET_MASK)

#define PMC_RESETCAUSE_BODRESET_MASK             (0x4U)
#define PMC_RESETCAUSE_BODRESET_SHIFT            (2U)
/*! BODRESET - 1 : The last chip reset was caused by a Brown Out Detector. */
#define PMC_RESETCAUSE_BODRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_BODRESET_SHIFT)) & PMC_RESETCAUSE_BODRESET_MASK)

#define PMC_RESETCAUSE_SYSTEMRESET_MASK          (0x8U)
#define PMC_RESETCAUSE_SYSTEMRESET_SHIFT         (3U)
/*! SYSTEMRESET - 1 : The last chip reset was caused by a System Reset requested by the ARM CPU. */
#define PMC_RESETCAUSE_SYSTEMRESET(x)            (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_SYSTEMRESET_SHIFT)) & PMC_RESETCAUSE_SYSTEMRESET_MASK)

#define PMC_RESETCAUSE_WDTRESET_MASK             (0x10U)
#define PMC_RESETCAUSE_WDTRESET_SHIFT            (4U)
/*! WDTRESET - 1 : The last chip reset was caused by the Watchdog Timer. */
#define PMC_RESETCAUSE_WDTRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_WDTRESET_SHIFT)) & PMC_RESETCAUSE_WDTRESET_MASK)

#define PMC_RESETCAUSE_SWRRESET_MASK             (0x20U)
#define PMC_RESETCAUSE_SWRRESET_SHIFT            (5U)
/*! SWRRESET - 1 : The last chip reset was caused by a Software reset. */
#define PMC_RESETCAUSE_SWRRESET(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_SWRRESET_SHIFT)) & PMC_RESETCAUSE_SWRRESET_MASK)

#define PMC_RESETCAUSE_DPDRESET_WAKEUPIO_MASK    (0x40U)
#define PMC_RESETCAUSE_DPDRESET_WAKEUPIO_SHIFT   (6U)
/*! DPDRESET_WAKEUPIO - 1 : The last chip reset was caused by a Wake-up I/O reset event during DEEP POWER DOWN mode. */
#define PMC_RESETCAUSE_DPDRESET_WAKEUPIO(x)      (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPDRESET_WAKEUPIO_SHIFT)) & PMC_RESETCAUSE_DPDRESET_WAKEUPIO_MASK)

#define PMC_RESETCAUSE_DPDRESET_RTC_MASK         (0x80U)
#define PMC_RESETCAUSE_DPDRESET_RTC_SHIFT        (7U)
/*! DPDRESET_RTC - 1 : The last chip reset was caused by RTC. */
#define PMC_RESETCAUSE_DPDRESET_RTC(x)           (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPDRESET_RTC_SHIFT)) & PMC_RESETCAUSE_DPDRESET_RTC_MASK)

#define PMC_RESETCAUSE_DPDRESET_OSTIMER_MASK     (0x100U)
#define PMC_RESETCAUSE_DPDRESET_OSTIMER_SHIFT    (8U)
/*! DPDRESET_OSTIMER - 1 : The last chip reset was caused by OS Event Timer reset event during DEEP POWER DOWN mode. */
#define PMC_RESETCAUSE_DPDRESET_OSTIMER(x)       (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_DPDRESET_OSTIMER_SHIFT)) & PMC_RESETCAUSE_DPDRESET_OSTIMER_MASK)

#define PMC_RESETCAUSE_CDOGRESET_MASK            (0x200U)
#define PMC_RESETCAUSE_CDOGRESET_SHIFT           (9U)
/*! CDOGRESET - 1 : The last chip reset was caused by the code Watchdog. */
#define PMC_RESETCAUSE_CDOGRESET(x)              (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_CDOGRESET_SHIFT)) & PMC_RESETCAUSE_CDOGRESET_MASK)

#define PMC_RESETCAUSE_BLEWUP_MASK               (0x400U)
#define PMC_RESETCAUSE_BLEWUP_SHIFT              (10U)
/*! BLEWUP - 1 : The last chip wakeup was caused by the BLE Timer wakeup. */
#define PMC_RESETCAUSE_BLEWUP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_BLEWUP_SHIFT)) & PMC_RESETCAUSE_BLEWUP_MASK)

#define PMC_RESETCAUSE_CRCERROR_MASK             (0x800U)
#define PMC_RESETCAUSE_CRCERROR_SHIFT            (11U)
/*! CRCERROR - 1 : The last chip reset was caused by a CRC error during CPU state retention restore. */
#define PMC_RESETCAUSE_CRCERROR(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RESETCAUSE_CRCERROR_SHIFT)) & PMC_RESETCAUSE_CRCERROR_MASK)
/*! @} */

/*! @name DCDC0 - DCDC control register [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] */
/*! @{ */

#define PMC_DCDC0_VOLTAGE_MASK                   (0xFU)
#define PMC_DCDC0_VOLTAGE_SHIFT                  (0U)
/*! VOLTAGE - DCDC output voltage level */
#define PMC_DCDC0_VOLTAGE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_VOLTAGE_SHIFT)) & PMC_DCDC0_VOLTAGE_MASK)

#define PMC_DCDC0_RC_MASK                        (0xF0U)
#define PMC_DCDC0_RC_SHIFT                       (4U)
/*! RC - Calibration RC time for Buck mode */
#define PMC_DCDC0_RC(x)                          (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_RC_SHIFT)) & PMC_DCDC0_RC_MASK)

#define PMC_DCDC0_INDUCTOR_MASK                  (0x3000U)
#define PMC_DCDC0_INDUCTOR_SHIFT                 (12U)
/*! INDUCTOR - Scale current mirror
 *  0b00..1.0 uH
 *  0b01..2.2 uH
 *  0b10..4.7 uH
 */
#define PMC_DCDC0_INDUCTOR(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_INDUCTOR_SHIFT)) & PMC_DCDC0_INDUCTOR_MASK)

#define PMC_DCDC0_PASSTHROUGH_EN_MASK            (0x4000U)
#define PMC_DCDC0_PASSTHROUGH_EN_SHIFT           (14U)
/*! PASSTHROUGH_EN - Enable pass through 0: disabled 1: enabled */
#define PMC_DCDC0_PASSTHROUGH_EN(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_PASSTHROUGH_EN_SHIFT)) & PMC_DCDC0_PASSTHROUGH_EN_MASK)

#define PMC_DCDC0_TRIMNZCD_MASK                  (0x38000U)
#define PMC_DCDC0_TRIMNZCD_SHIFT                 (15U)
/*! TRIMNZCD - Trim bits N-ZCD */
#define PMC_DCDC0_TRIMNZCD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_TRIMNZCD_SHIFT)) & PMC_DCDC0_TRIMNZCD_MASK)

#define PMC_DCDC0_TRIMPZCD_MASK                  (0x1C0000U)
#define PMC_DCDC0_TRIMPZCD_SHIFT                 (18U)
/*! TRIMPZCD - Trim bits P-ZCD */
#define PMC_DCDC0_TRIMPZCD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_TRIMPZCD_SHIFT)) & PMC_DCDC0_TRIMPZCD_MASK)

#define PMC_DCDC0_ENABLE_BYPASS_MASK             (0x200000U)
#define PMC_DCDC0_ENABLE_BYPASS_SHIFT            (21U)
/*! ENABLE_BYPASS - Enable low power bypass switch */
#define PMC_DCDC0_ENABLE_BYPASS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_ENABLE_BYPASS_SHIFT)) & PMC_DCDC0_ENABLE_BYPASS_MASK)

#define PMC_DCDC0_ROBUST_STARTUP_DISABLE_MASK    (0x400000U)
#define PMC_DCDC0_ROBUST_STARTUP_DISABLE_SHIFT   (22U)
/*! ROBUST_STARTUP_DISABLE - Block BOD controlled DCDC buck and boost control */
#define PMC_DCDC0_ROBUST_STARTUP_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << PMC_DCDC0_ROBUST_STARTUP_DISABLE_SHIFT)) & PMC_DCDC0_ROBUST_STARTUP_DISABLE_MASK)
/*! @} */

/*! @name BIAS - Bias current source control register [Reset by: PoR, Pin Reset, Software Reset] */
/*! @{ */

#define PMC_BIAS_DCSHIFT_MASK                    (0x1FU)
#define PMC_BIAS_DCSHIFT_SHIFT                   (0U)
/*! DCSHIFT - Trimming bits to adjust DC shift */
#define PMC_BIAS_DCSHIFT(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_BIAS_DCSHIFT_SHIFT)) & PMC_BIAS_DCSHIFT_MASK)

#define PMC_BIAS_CURVE_MASK                      (0x60U)
#define PMC_BIAS_CURVE_SHIFT                     (5U)
/*! CURVE - Trimming bits to adjust deviations in curvature on silicon */
#define PMC_BIAS_CURVE(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_BIAS_CURVE_SHIFT)) & PMC_BIAS_CURVE_MASK)

#define PMC_BIAS_IREFTRIM_MASK                   (0xF80U)
#define PMC_BIAS_IREFTRIM_SHIFT                  (7U)
/*! IREFTRIM - Bias current trimming */
#define PMC_BIAS_IREFTRIM(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_BIAS_IREFTRIM_SHIFT)) & PMC_BIAS_IREFTRIM_MASK)

#define PMC_BIAS_LPDCSHIFT_MASK                  (0xF000U)
#define PMC_BIAS_LPDCSHIFT_SHIFT                 (12U)
/*! LPDCSHIFT - Trimming bits to adjust DC shift in low power mode */
#define PMC_BIAS_LPDCSHIFT(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_BIAS_LPDCSHIFT_SHIFT)) & PMC_BIAS_LPDCSHIFT_MASK)
/*! @} */

/*! @name LDOMEM - LDOMEM */
/*! @{ */

#define PMC_LDOMEM_VADJ_MASK                     (0xFU)
#define PMC_LDOMEM_VADJ_SHIFT                    (0U)
/*! VADJ - Sets the LDO output level (4 bit, only 2 LSB used). */
#define PMC_LDOMEM_VADJ(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LDOMEM_VADJ_SHIFT)) & PMC_LDOMEM_VADJ_MASK)

#define PMC_LDOMEM_VADJ_PWD_MASK                 (0x10U)
#define PMC_LDOMEM_VADJ_PWD_SHIFT                (4U)
/*! VADJ_PWD - Sets the LDO output level to 0.63V or 0.66V in low power mode */
#define PMC_LDOMEM_VADJ_PWD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_LDOMEM_VADJ_PWD_SHIFT)) & PMC_LDOMEM_VADJ_PWD_MASK)
/*! @} */

/*! @name LDODIG - LDODIG */
/*! @{ */

#define PMC_LDODIG_VADJ_MASK                     (0xFU)
#define PMC_LDODIG_VADJ_SHIFT                    (0U)
/*! VADJ - Sets the LDO output level (4 bit, only 2 LSB used). */
#define PMC_LDODIG_VADJ(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LDODIG_VADJ_SHIFT)) & PMC_LDODIG_VADJ_MASK)

#define PMC_LDODIG_VADJ_PWD_MASK                 (0x10U)
#define PMC_LDODIG_VADJ_PWD_SHIFT                (4U)
/*! VADJ_PWD - Sets the LDO output level to 0.63V or 0.66V in low power mode */
#define PMC_LDODIG_VADJ_PWD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_LDODIG_VADJ_PWD_SHIFT)) & PMC_LDODIG_VADJ_PWD_MASK)
/*! @} */

/*! @name BOD1 - BOD1 */
/*! @{ */

#define PMC_BOD1_TRIGLVL_MASK                    (0x1FU)
#define PMC_BOD1_TRIGLVL_SHIFT                   (0U)
/*! TRIGLVL - BOD Trigger level
 *  0b00000..1.00 V.
 *  0b00001..1.05 V.
 *  0b00010..1.10 V.
 *  0b00011..1.15 V.
 *  0b00100..1.20 V.
 *  0b00101..1.25 V.
 *  0b00110..1.30 V.
 *  0b00111..1.35 V.
 *  0b01000..1.40 V.
 *  0b01001..1.45 V.
 *  0b01010..1.50 V.
 *  0b01011..1.60 V.
 *  0b01100..1.70 V.
 *  0b01101..1.80 V.
 *  0b01110..1.90 V.
 *  0b01111..2.00 V.
 *  0b10000..2.10 V.
 *  0b10001..2.20 V.
 *  0b10010..2.30 V.
 *  0b10011..2.40 V.
 *  0b10100..2.50 V.
 *  0b10101..2.60 V.
 *  0b10110..2.70 V.
 *  0b10111..2.80 V.
 *  0b11000..2.90 V.
 *  0b11001..3.00 V.
 *  0b11010..3.10 V.
 */
#define PMC_BOD1_TRIGLVL(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_BOD1_TRIGLVL_SHIFT)) & PMC_BOD1_TRIGLVL_MASK)

#define PMC_BOD1_HYST_MASK                       (0x60U)
#define PMC_BOD1_HYST_SHIFT                      (5U)
/*! HYST - BOD Hysteresis control
 *  0b00..25 mV.
 *  0b01..50 mV.
 *  0b10..75 mV.
 *  0b11..100 mV.
 */
#define PMC_BOD1_HYST(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_BOD1_HYST_SHIFT)) & PMC_BOD1_HYST_MASK)

#define PMC_BOD1_MODE_MASK                       (0x80U)
#define PMC_BOD1_MODE_SHIFT                      (7U)
/*! MODE - BOD Operation mode select
 *  0b0..Level detector mode
 *  0b1..BOD mode
 */
#define PMC_BOD1_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_BOD1_MODE_SHIFT)) & PMC_BOD1_MODE_MASK)

#define PMC_BOD1_LVLSEL_MASK                     (0x100U)
#define PMC_BOD1_LVLSEL_SHIFT                    (8U)
/*! LVLSEL - BOD Level select when mode is set to zero
 *  0b0..Reference is sum of threshold plus hysteresis
 *  0b1..Reference is threshold
 */
#define PMC_BOD1_LVLSEL(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_BOD1_LVLSEL_SHIFT)) & PMC_BOD1_LVLSEL_MASK)
/*! @} */

/*! @name BOD2 - BOD2 */
/*! @{ */

#define PMC_BOD2_TRIGLVL_MASK                    (0x1FU)
#define PMC_BOD2_TRIGLVL_SHIFT                   (0U)
/*! TRIGLVL - BOD Trigger level
 *  0b00000..1.00 V.
 *  0b00001..1.05 V.
 *  0b00010..1.10 V.
 *  0b00011..1.15 V.
 *  0b00100..1.20 V.
 *  0b00101..1.25 V.
 *  0b00110..1.30 V.
 *  0b00111..1.35 V.
 *  0b01000..1.40 V.
 *  0b01001..1.45 V.
 *  0b01010..1.50 V.
 *  0b01011..1.60 V.
 *  0b01100..1.70 V.
 *  0b01101..1.80 V.
 *  0b01110..1.90 V.
 *  0b01111..2.00 V.
 *  0b10000..2.10 V.
 *  0b10001..2.20 V.
 *  0b10010..2.30 V.
 *  0b10011..2.40 V.
 *  0b10100..2.50 V.
 *  0b10101..2.60 V.
 *  0b10110..2.70 V.
 *  0b10111..2.80 V.
 *  0b11000..2.90 V.
 *  0b11001..3.00 V.
 *  0b11010..3.10 V.
 */
#define PMC_BOD2_TRIGLVL(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_BOD2_TRIGLVL_SHIFT)) & PMC_BOD2_TRIGLVL_MASK)

#define PMC_BOD2_HYST_MASK                       (0x60U)
#define PMC_BOD2_HYST_SHIFT                      (5U)
/*! HYST - BOD Hysteresis control
 *  0b00..25 mV.
 *  0b01..50 mV.
 *  0b10..75 mV.
 *  0b11..100 mV.
 */
#define PMC_BOD2_HYST(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_BOD2_HYST_SHIFT)) & PMC_BOD2_HYST_MASK)

#define PMC_BOD2_MODE_MASK                       (0x80U)
#define PMC_BOD2_MODE_SHIFT                      (7U)
/*! MODE - BOD Operation mode select
 *  0b0..Level detector mode
 *  0b1..BOD mode
 */
#define PMC_BOD2_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_BOD2_MODE_SHIFT)) & PMC_BOD2_MODE_MASK)

#define PMC_BOD2_LVLSEL_MASK                     (0x100U)
#define PMC_BOD2_LVLSEL_SHIFT                    (8U)
/*! LVLSEL - BOD Level select when mode is set to zero
 *  0b0..Reference is sum of threshold plus hysteresis
 *  0b1..Reference is threshold
 */
#define PMC_BOD2_LVLSEL(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_BOD2_LVLSEL_SHIFT)) & PMC_BOD2_LVLSEL_MASK)
/*! @} */

/*! @name FRO192M - FRO192M */
/*! @{ */

#define PMC_FRO192M_BIAS_MASK                    (0x3FU)
#define PMC_FRO192M_BIAS_SHIFT                   (0U)
/*! BIAS - Coarse frequency trimming */
#define PMC_FRO192M_BIAS(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_FRO192M_BIAS_SHIFT)) & PMC_FRO192M_BIAS_MASK)

#define PMC_FRO192M_CUR_DAC_MASK                 (0x3FC0U)
#define PMC_FRO192M_CUR_DAC_SHIFT                (6U)
/*! CUR_DAC - Fine frequency trimming */
#define PMC_FRO192M_CUR_DAC(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_FRO192M_CUR_DAC_SHIFT)) & PMC_FRO192M_CUR_DAC_MASK)

#define PMC_FRO192M_TC_MASK                      (0xFC000U)
#define PMC_FRO192M_TC_SHIFT                     (14U)
/*! TC - Temperature compensation */
#define PMC_FRO192M_TC(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_FRO192M_TC_SHIFT)) & PMC_FRO192M_TC_MASK)
/*! @} */

/*! @name FRO1M - 1 MHz Free Running Oscillator control register */
/*! @{ */

#define PMC_FRO1M_FREQSEL_MASK                   (0x7FU)
#define PMC_FRO1M_FREQSEL_SHIFT                  (0U)
/*! FREQSEL - Frequency trimming bits */
#define PMC_FRO1M_FREQSEL(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FRO1M_FREQSEL_SHIFT)) & PMC_FRO1M_FREQSEL_MASK)

#define PMC_FRO1M_DIVSEL_MASK                    (0x3E00U)
#define PMC_FRO1M_DIVSEL_SHIFT                   (9U)
/*! DIVSEL - Divider selection bits.
 *  0b00000..2.0.
 *  0b00001..4.0.
 *  0b00010..6.0.
 *  0b00011..8.0.
 *  0b00100..10.0.
 *  0b00101..12.0.
 *  0b00110..14.0.
 *  0b00111..16.0.
 *  0b01000..18.0.
 *  0b01001..20.0.
 *  0b01010..22.0.
 *  0b01011..24.0.
 *  0b01100..26.0.
 *  0b01101..28.0.
 *  0b01110..30.0.
 *  0b01111..32.0.
 *  0b10000..34.0.
 *  0b10001..36.0.
 *  0b10010..38.0.
 *  0b10011..40.0.
 *  0b10100..42.0.
 *  0b10101..44.0.
 *  0b10110..46.0.
 *  0b10111..48.0.
 *  0b11000..50.0.
 *  0b11001..52.0.
 *  0b11010..54.0.
 *  0b11011..56.0.
 *  0b11100..58.0.
 *  0b11101..60.0.
 *  0b11110..62.0.
 *  0b11111..1.0.
 */
#define PMC_FRO1M_DIVSEL(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_FRO1M_DIVSEL_SHIFT)) & PMC_FRO1M_DIVSEL_MASK)
/*! @} */

/*! @name FRO32K - 32 KHz Free Running Oscillator (FRO) control register */
/*! @{ */

#define PMC_FRO32K_NTAT_MASK                     (0xEU)
#define PMC_FRO32K_NTAT_SHIFT                    (1U)
/*! NTAT - Temperature coefficient trimming bits. */
#define PMC_FRO32K_NTAT(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_FRO32K_NTAT_SHIFT)) & PMC_FRO32K_NTAT_MASK)

#define PMC_FRO32K_PTAT_MASK                     (0x70U)
#define PMC_FRO32K_PTAT_SHIFT                    (4U)
/*! PTAT - Bias trimming bits (coarse frequency trimming). */
#define PMC_FRO32K_PTAT(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_FRO32K_PTAT_SHIFT)) & PMC_FRO32K_PTAT_MASK)

#define PMC_FRO32K_CAPCAL_MASK                   (0xFF80U)
#define PMC_FRO32K_CAPCAL_SHIFT                  (7U)
/*! CAPCAL - Capacitive dac calibration bits (fine frequency trimming). */
#define PMC_FRO32K_CAPCAL(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FRO32K_CAPCAL_SHIFT)) & PMC_FRO32K_CAPCAL_MASK)
/*! @} */

/*! @name XTAL32K - 32 KHz Crystal oscillator (XTAL) control register */
/*! @{ */

#define PMC_XTAL32K_GM_MASK                      (0x6U)
#define PMC_XTAL32K_GM_SHIFT                     (1U)
/*! GM - Reference output current selection inputs */
#define PMC_XTAL32K_GM(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_GM_SHIFT)) & PMC_XTAL32K_GM_MASK)

#define PMC_XTAL32K_XTM_MASK                     (0x8U)
#define PMC_XTAL32K_XTM_SHIFT                    (3U)
/*! XTM - Oscillator bypass mode */
#define PMC_XTAL32K_XTM(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_XTM_SHIFT)) & PMC_XTAL32K_XTM_MASK)

#define PMC_XTAL32K_AMPL_MASK                    (0xC0U)
#define PMC_XTAL32K_AMPL_SHIFT                   (6U)
/*! AMPL - Oscillator amplitude selection inputs */
#define PMC_XTAL32K_AMPL(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_AMPL_SHIFT)) & PMC_XTAL32K_AMPL_MASK)

#define PMC_XTAL32K_CAP_OSCIN_MASK               (0xF00U)
#define PMC_XTAL32K_CAP_OSCIN_SHIFT              (8U)
/*! CAP_OSCIN - osc_in capacitorbank selection inputs */
#define PMC_XTAL32K_CAP_OSCIN(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_CAP_OSCIN_SHIFT)) & PMC_XTAL32K_CAP_OSCIN_MASK)

#define PMC_XTAL32K_CAP_OSCOUT_MASK              (0xF000U)
#define PMC_XTAL32K_CAP_OSCOUT_SHIFT             (12U)
/*! CAP_OSCOUT - osc_out capacitorbank selection inputs */
#define PMC_XTAL32K_CAP_OSCOUT(x)                (((uint32_t)(((uint32_t)(x)) << PMC_XTAL32K_CAP_OSCOUT_SHIFT)) & PMC_XTAL32K_CAP_OSCOUT_MASK)
/*! @} */

/*! @name XTALBLE - BLE XTAL overrule */
/*! @{ */

#define PMC_XTALBLE_CKO_UNGATE_OVERRULE_MASK     (0x1U)
#define PMC_XTALBLE_CKO_UNGATE_OVERRULE_SHIFT    (0U)
/*! CKO_UNGATE_OVERRULE - Defines whether the Link Layer HW gets a clock
 *  0b0..The clock going to the Link Layer HW is disabled
 *  0b1..The clock going to the Link Layer HW is enabled
 */
#define PMC_XTALBLE_CKO_UNGATE_OVERRULE(x)       (((uint32_t)(((uint32_t)(x)) << PMC_XTALBLE_CKO_UNGATE_OVERRULE_SHIFT)) & PMC_XTALBLE_CKO_UNGATE_OVERRULE_MASK)
/*! @} */

/*! @name WAKEUPIOCTRL - WAKEUPIOCTRL */
/*! @{ */

#define PMC_WAKEUPIOCTRL_ENABLE_MASK             (0x1U)
#define PMC_WAKEUPIOCTRL_ENABLE_SHIFT            (0U)
/*! ENABLE - Enable / disable wake up on Wake Up pin in Deep Power Down modes */
#define PMC_WAKEUPIOCTRL_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_ENABLE_SHIFT)) & PMC_WAKEUPIOCTRL_ENABLE_MASK)

#define PMC_WAKEUPIOCTRL_PUP_EN_MASK             (0x100U)
#define PMC_WAKEUPIOCTRL_PUP_EN_SHIFT            (8U)
/*! PUP_EN - Enable/disable Wakeup pin Pull-up in PowerOff mode
 *  0b0..Disable pull-up
 *  0b1..Enable pull-up
 */
#define PMC_WAKEUPIOCTRL_PUP_EN(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_PUP_EN_SHIFT)) & PMC_WAKEUPIOCTRL_PUP_EN_MASK)

#define PMC_WAKEUPIOCTRL_PDN_EN_MASK             (0x200U)
#define PMC_WAKEUPIOCTRL_PDN_EN_SHIFT            (9U)
/*! PDN_EN - Enable/disable Wakeup pin Pull-down in PowerOff mode
 *  0b0..Disable pull-down
 *  0b1..Enable pull-down
 */
#define PMC_WAKEUPIOCTRL_PDN_EN(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_PDN_EN_SHIFT)) & PMC_WAKEUPIOCTRL_PDN_EN_MASK)

#define PMC_WAKEUPIOCTRL_LVL_MASK                (0x400U)
#define PMC_WAKEUPIOCTRL_LVL_SHIFT               (10U)
/*! LVL - Select Wakeup pin event level in PowerOff
 *  0b0..Wakeup on low level
 *  0b1..Wakeup on high level
 */
#define PMC_WAKEUPIOCTRL_LVL(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_LVL_SHIFT)) & PMC_WAKEUPIOCTRL_LVL_MASK)

#define PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_MASK      (0x200000U)
#define PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_SHIFT     (21U)
/*! WAKEUPIO_RSTN - WAKEUP IO event detector reset control. When this bit is, the RESETCAUSE
 *    register is updated when the wakeup IO causes a wakeup event.
 *  0b0..Bloc is reset.
 *  0b1..Bloc is not reset.
 */
#define PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN(x)        (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_SHIFT)) & PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_MASK)
/*! @} */

/*! @name WAKEIOCAUSE - Allows to identify the Wake-up I/O source from Deep Power Down mode */
/*! @{ */

#define PMC_WAKEIOCAUSE_WAKEUP0_MASK             (0x1U)
#define PMC_WAKEIOCAUSE_WAKEUP0_SHIFT            (0U)
/*! WAKEUP0 - Allows to identify Wake up I/O 0 as the wake-up source from Deep Power Down mode.
 *  0b0..Last wake up from Deep Power down mode was NOT triggred by wake up I/O 0.
 *  0b1..Last wake up from Deep Power down mode was triggred by wake up I/O 0.
 */
#define PMC_WAKEIOCAUSE_WAKEUP0(x)               (((uint32_t)(((uint32_t)(x)) << PMC_WAKEIOCAUSE_WAKEUP0_SHIFT)) & PMC_WAKEIOCAUSE_WAKEUP0_MASK)
/*! @} */

/*! @name STATUSPWR - STATUSPWR */
/*! @{ */

#define PMC_STATUSPWR_DCDCMODE_MASK              (0x3U)
#define PMC_STATUSPWR_DCDCMODE_SHIFT             (0U)
/*! DCDCMODE - DCDC Mode 01: Buck mode 10: Boost mode */
#define PMC_STATUSPWR_DCDCMODE(x)                (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_DCDCMODE_SHIFT)) & PMC_STATUSPWR_DCDCMODE_MASK)

#define PMC_STATUSPWR_DCDCOK_MASK                (0x4U)
#define PMC_STATUSPWR_DCDCOK_SHIFT               (2U)
/*! DCDCOK - DCDC power OK */
#define PMC_STATUSPWR_DCDCOK(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_DCDCOK_SHIFT)) & PMC_STATUSPWR_DCDCOK_MASK)

#define PMC_STATUSPWR_LDODIGOK_MASK              (0x8U)
#define PMC_STATUSPWR_LDODIGOK_SHIFT             (3U)
/*! LDODIGOK - LDODIG power OK */
#define PMC_STATUSPWR_LDODIGOK(x)                (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_LDODIGOK_SHIFT)) & PMC_STATUSPWR_LDODIGOK_MASK)

#define PMC_STATUSPWR_LDOMEMOK_MASK              (0x10U)
#define PMC_STATUSPWR_LDOMEMOK_SHIFT             (4U)
/*! LDOMEMOK - LDOMEM power OK */
#define PMC_STATUSPWR_LDOMEMOK(x)                (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_LDOMEMOK_SHIFT)) & PMC_STATUSPWR_LDOMEMOK_MASK)

#define PMC_STATUSPWR_DURATION_MASK              (0x1FFFE0U)
#define PMC_STATUSPWR_DURATION_SHIFT             (5U)
/*! DURATION - DCDC Startup duration in us. */
#define PMC_STATUSPWR_DURATION(x)                (((uint32_t)(((uint32_t)(x)) << PMC_STATUSPWR_DURATION_SHIFT)) & PMC_STATUSPWR_DURATION_MASK)
/*! @} */

/*! @name STATUSCLK - FRO and XTAL status register [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

#define PMC_STATUSCLK_XTAL32KOK_MASK             (0x1U)
#define PMC_STATUSCLK_XTAL32KOK_SHIFT            (0U)
/*! XTAL32KOK - XTAL oscillator 32K OK signal. Note : Bit not working as expected. See artf872570 */
#define PMC_STATUSCLK_XTAL32KOK(x)               (((uint32_t)(((uint32_t)(x)) << PMC_STATUSCLK_XTAL32KOK_SHIFT)) & PMC_STATUSCLK_XTAL32KOK_MASK)

#define PMC_STATUSCLK_FRO1MCLKVALID_MASK         (0x2U)
#define PMC_STATUSCLK_FRO1MCLKVALID_SHIFT        (1U)
/*! FRO1MCLKVALID - FRO 1 MHz CCO voltage detector output */
#define PMC_STATUSCLK_FRO1MCLKVALID(x)           (((uint32_t)(((uint32_t)(x)) << PMC_STATUSCLK_FRO1MCLKVALID_SHIFT)) & PMC_STATUSCLK_FRO1MCLKVALID_MASK)

#define PMC_STATUSCLK_XTAL32KOSCFAILURE_MASK     (0x4U)
#define PMC_STATUSCLK_XTAL32KOSCFAILURE_SHIFT    (2U)
/*! XTAL32KOSCFAILURE - XTAL32 KHZ oscillator oscillation failure detection indicator.
 *  0b0..No oscillation failure has been detetced since the last time this bit has been cleared..
 *  0b1..At least one oscillation failure has been detetced since the last time this bit has been cleared..
 */
#define PMC_STATUSCLK_XTAL32KOSCFAILURE(x)       (((uint32_t)(((uint32_t)(x)) << PMC_STATUSCLK_XTAL32KOSCFAILURE_SHIFT)) & PMC_STATUSCLK_XTAL32KOSCFAILURE_MASK)
/*! @} */

/*! @name AOREG0 - Write-once general purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

#define PMC_AOREG0_DATA31_0_MASK                 (0xFFFFFFFFU)
#define PMC_AOREG0_DATA31_0_SHIFT                (0U)
/*! DATA31_0 - General purpose always on domain data storage. */
#define PMC_AOREG0_DATA31_0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG0_DATA31_0_SHIFT)) & PMC_AOREG0_DATA31_0_MASK)
/*! @} */

/*! @name AOREG1 - General purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

#define PMC_AOREG1_DATA31_0_MASK                 (0xFFFFFFFFU)
#define PMC_AOREG1_DATA31_0_SHIFT                (0U)
/*! DATA31_0 - Write-once general purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset] */
#define PMC_AOREG1_DATA31_0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_DATA31_0_SHIFT)) & PMC_AOREG1_DATA31_0_MASK)
/*! @} */

/*! @name AOREG2 - AOREG2 */
/*! @{ */

#define PMC_AOREG2_DATA31_0_MASK                 (0xFFFFFFFFU)
#define PMC_AOREG2_DATA31_0_SHIFT                (0U)
/*! DATA31_0 - General purpose always on domain data storage. */
#define PMC_AOREG2_DATA31_0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG2_DATA31_0_SHIFT)) & PMC_AOREG2_DATA31_0_MASK)
/*! @} */

/*! @name RTCOSC32K - RTC 1 KHZ and 1 Hz clocks source control register [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

#define PMC_RTCOSC32K_SEL_MASK                   (0x1U)
#define PMC_RTCOSC32K_SEL_SHIFT                  (0U)
/*! SEL - Selects either the XTAL32K or FRO32K as the 32.768kHz clock source for the whole system.
 *  0b0..FRO 32.768 KHz.
 *  0b1..XTAL 32.768 KHz.
 */
#define PMC_RTCOSC32K_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_SEL_SHIFT)) & PMC_RTCOSC32K_SEL_MASK)

#define PMC_RTCOSC32K_CLK1KHZDIV_MASK            (0xEU)
#define PMC_RTCOSC32K_CLK1KHZDIV_SHIFT           (1U)
/*! CLK1KHZDIV - Actual division ratio is : 28 + CLK1KHZDIV. */
#define PMC_RTCOSC32K_CLK1KHZDIV(x)              (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_CLK1KHZDIV_SHIFT)) & PMC_RTCOSC32K_CLK1KHZDIV_MASK)

#define PMC_RTCOSC32K_CLK1KHZDIVUPDATEREQ_MASK   (0x8000U)
#define PMC_RTCOSC32K_CLK1KHZDIVUPDATEREQ_SHIFT  (15U)
/*! CLK1KHZDIVUPDATEREQ - RTC 1KHz clock Divider status flag. */
#define PMC_RTCOSC32K_CLK1KHZDIVUPDATEREQ(x)     (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_CLK1KHZDIVUPDATEREQ_SHIFT)) & PMC_RTCOSC32K_CLK1KHZDIVUPDATEREQ_MASK)

#define PMC_RTCOSC32K_CLK1HZDIV_MASK             (0x7FF0000U)
#define PMC_RTCOSC32K_CLK1HZDIV_SHIFT            (16U)
/*! CLK1HZDIV - Actual division ratio is : 31744 + CLK1HZDIV. */
#define PMC_RTCOSC32K_CLK1HZDIV(x)               (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_CLK1HZDIV_SHIFT)) & PMC_RTCOSC32K_CLK1HZDIV_MASK)

#define PMC_RTCOSC32K_CLK1HZDIVHALT_MASK         (0x40000000U)
#define PMC_RTCOSC32K_CLK1HZDIVHALT_SHIFT        (30U)
/*! CLK1HZDIVHALT - Halts the divider counter. */
#define PMC_RTCOSC32K_CLK1HZDIVHALT(x)           (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_CLK1HZDIVHALT_SHIFT)) & PMC_RTCOSC32K_CLK1HZDIVHALT_MASK)

#define PMC_RTCOSC32K_CLK1HZDIVUPDATEREQ_MASK    (0x80000000U)
#define PMC_RTCOSC32K_CLK1HZDIVUPDATEREQ_SHIFT   (31U)
/*! CLK1HZDIVUPDATEREQ - RTC 1Hz Divider status flag. */
#define PMC_RTCOSC32K_CLK1HZDIVUPDATEREQ(x)      (((uint32_t)(((uint32_t)(x)) << PMC_RTCOSC32K_CLK1HZDIVUPDATEREQ_SHIFT)) & PMC_RTCOSC32K_CLK1HZDIVUPDATEREQ_MASK)
/*! @} */

/*! @name OSTIMER - OS Timer control register [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

#define PMC_OSTIMER_SOFTRESET_MASK               (0x1U)
#define PMC_OSTIMER_SOFTRESET_SHIFT              (0U)
/*! SOFTRESET - Active high reset. */
#define PMC_OSTIMER_SOFTRESET(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_OSTIMER_SOFTRESET_SHIFT)) & PMC_OSTIMER_SOFTRESET_MASK)

#define PMC_OSTIMER_CLOCKENABLE_MASK             (0x2U)
#define PMC_OSTIMER_CLOCKENABLE_SHIFT            (1U)
/*! CLOCKENABLE - Enable OS event timer clock. */
#define PMC_OSTIMER_CLOCKENABLE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_OSTIMER_CLOCKENABLE_SHIFT)) & PMC_OSTIMER_CLOCKENABLE_MASK)

#define PMC_OSTIMER_DPDWAKEUPENABLE_MASK         (0x4U)
#define PMC_OSTIMER_DPDWAKEUPENABLE_SHIFT        (2U)
/*! DPDWAKEUPENABLE - Wake up enable in Deep Power Down mode (To be used in Enable Deep Power Down mode). */
#define PMC_OSTIMER_DPDWAKEUPENABLE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_OSTIMER_DPDWAKEUPENABLE_SHIFT)) & PMC_OSTIMER_DPDWAKEUPENABLE_MASK)

#define PMC_OSTIMER_OSC_PD_MASK                  (0x8U)
#define PMC_OSTIMER_OSC_PD_SHIFT                 (3U)
/*! OSC_PD - Oscilator 32.768 kHz power down control. */
#define PMC_OSTIMER_OSC_PD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_OSTIMER_OSC_PD_SHIFT)) & PMC_OSTIMER_OSC_PD_MASK)

#define PMC_OSTIMER_OSTIMERCLKSEL_MASK           (0x30U)
#define PMC_OSTIMER_OSTIMERCLKSEL_SHIFT          (4U)
/*! OSTIMERCLKSEL - OS event timer clock select.
 *  0b00..32.768kHz clock - FRO32K or XTAL32K (determined by RTCOSC32K.SEL bit)
 *  0b01..FRO 1MHz clock.
 *  0b10..Reserved - do not select this value
 *  0b11..No clock.
 */
#define PMC_OSTIMER_OSTIMERCLKSEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_OSTIMER_OSTIMERCLKSEL_SHIFT)) & PMC_OSTIMER_OSTIMERCLKSEL_MASK)
/*! @} */

/*! @name TIMEOUTEVENTS - Record time-out errors that might occur at different stages during IC power up */
/*! @{ */

#define PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_MASK      (0x1U)
#define PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_SHIFT     (0U)
/*! PWUP_DCDC_OK - 1: a time out event occured during power up when waiting for DCDC to become functional. */
#define PMC_TIMEOUTEVENTS_PWUP_DCDC_OK(x)        (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_DCDC_OK_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_LDO_OK_MASK       (0x2U)
#define PMC_TIMEOUTEVENTS_PWUP_LDO_OK_SHIFT      (1U)
/*! PWUP_LDO_OK - 1: a time out event occured during power up when waiting for LDO_MEM or LDO_DIG to become functional. */
#define PMC_TIMEOUTEVENTS_PWUP_LDO_OK(x)         (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_LDO_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_LDO_OK_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_MASK (0x8U)
#define PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_SHIFT (3U)
/*! PWUP_FLASHINIT_DONE - 1: a time out event occured during power up when waiting for Flash initialization. */
#define PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_FLASHINIT_DONE_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_SRAM_OFF_MASK     (0x10U)
#define PMC_TIMEOUTEVENTS_DSLP_SRAM_OFF_SHIFT    (4U)
/*! DSLP_SRAM_OFF - 1: a time out event occured during deep sleep when waiting for SRAM shut off. */
#define PMC_TIMEOUTEVENTS_DSLP_SRAM_OFF(x)       (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_SRAM_OFF_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_SRAM_OFF_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_MASK      (0x20U)
#define PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_SHIFT     (5U)
/*! DSLP_DCDC_OK - 1: a time out event occured during deep sleep when waiting for DCDC to become functional. */
#define PMC_TIMEOUTEVENTS_DSLP_DCDC_OK(x)        (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_DCDC_OK_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_FLASHINIT_DONE_MASK (0x40U)
#define PMC_TIMEOUTEVENTS_DSLP_FLASHINIT_DONE_SHIFT (6U)
/*! DSLP_FLASHINIT_DONE - 1: a time out event occured during deep sleep when waiting for Flash initialization. */
#define PMC_TIMEOUTEVENTS_DSLP_FLASHINIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_FLASHINIT_DONE_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_FLASHINIT_DONE_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_MASK  (0x80U)
#define PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_SHIFT (7U)
/*! DSLP_SRAM_WAKEUP - 1: a time out event occured during deep sleep when waiting for SRAM to become functional. */
#define PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_SRAM_WAKEUP_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_SRAM_OFF_MASK     (0x100U)
#define PMC_TIMEOUTEVENTS_PDWN_SRAM_OFF_SHIFT    (8U)
/*! PDWN_SRAM_OFF - 1: a time out event occured during power down when waiting for SRAM shut off. */
#define PMC_TIMEOUTEVENTS_PDWN_SRAM_OFF(x)       (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_SRAM_OFF_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_SRAM_OFF_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_DCDC_OK_MASK      (0x200U)
#define PMC_TIMEOUTEVENTS_PDWN_DCDC_OK_SHIFT     (9U)
/*! PDWN_DCDC_OK - 1: a time out event occured during power down when waiting for DCDC to become functional. */
#define PMC_TIMEOUTEVENTS_PDWN_DCDC_OK(x)        (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_DCDC_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_DCDC_OK_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_MASK (0x1000U)
#define PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_SHIFT (12U)
/*! PDWN_FLASHINIT_DONE - 1: a time out event occured during power down when waiting for flash initialization to become functional. */
#define PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_FLASHINIT_DONE_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_BLE_SHUTDOWN_MASK (0x2000U)
#define PMC_TIMEOUTEVENTS_DSLP_BLE_SHUTDOWN_SHIFT (13U)
/*! DSLP_BLE_SHUTDOWN - 1: a time out event occured during deep sleep when waiting for BLE powerdown ack. */
#define PMC_TIMEOUTEVENTS_DSLP_BLE_SHUTDOWN(x)   (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_BLE_SHUTDOWN_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_BLE_SHUTDOWN_MASK)

#define PMC_TIMEOUTEVENTS_PDWN_BLE_SHUTDOWN_MASK (0x4000U)
#define PMC_TIMEOUTEVENTS_PDWN_BLE_SHUTDOWN_SHIFT (14U)
/*! PDWN_BLE_SHUTDOWN - 1: a time out event occured during power down when waiting for BLE powerdown ack. */
#define PMC_TIMEOUTEVENTS_PDWN_BLE_SHUTDOWN(x)   (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PDWN_BLE_SHUTDOWN_SHIFT)) & PMC_TIMEOUTEVENTS_PDWN_BLE_SHUTDOWN_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_CLK192MHZ_OK_MASK (0x8000U)
#define PMC_TIMEOUTEVENTS_PWUP_CLK192MHZ_OK_SHIFT (15U)
/*! PWUP_CLK192MHZ_OK - 1: a time out event occured during power up when waiting for oscillator startup. */
#define PMC_TIMEOUTEVENTS_PWUP_CLK192MHZ_OK(x)   (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_CLK192MHZ_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_CLK192MHZ_OK_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_CLK192MHZ_OK_MASK (0x10000U)
#define PMC_TIMEOUTEVENTS_DSLP_CLK192MHZ_OK_SHIFT (16U)
/*! DSLP_CLK192MHZ_OK - 1: a time out event occured during power up from low power state when waiting for oscillator startup. */
#define PMC_TIMEOUTEVENTS_DSLP_CLK192MHZ_OK(x)   (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_CLK192MHZ_OK_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_CLK192MHZ_OK_MASK)

#define PMC_TIMEOUTEVENTS_PWDN_CLK192MHZ_OK_MASK (0x20000U)
#define PMC_TIMEOUTEVENTS_PWDN_CLK192MHZ_OK_SHIFT (17U)
/*! PWDN_CLK192MHZ_OK - 1: a time out event occured during power up from power down state when waiting for oscillator startup. */
#define PMC_TIMEOUTEVENTS_PWDN_CLK192MHZ_OK(x)   (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWDN_CLK192MHZ_OK_SHIFT)) & PMC_TIMEOUTEVENTS_PWDN_CLK192MHZ_OK_MASK)

#define PMC_TIMEOUTEVENTS_PWUP_BLE_STARTUP_MASK  (0x40000U)
#define PMC_TIMEOUTEVENTS_PWUP_BLE_STARTUP_SHIFT (18U)
/*! PWUP_BLE_STARTUP - 1: a time out event occured during power up when waiting for BLE. */
#define PMC_TIMEOUTEVENTS_PWUP_BLE_STARTUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWUP_BLE_STARTUP_SHIFT)) & PMC_TIMEOUTEVENTS_PWUP_BLE_STARTUP_MASK)

#define PMC_TIMEOUTEVENTS_DSLP_BLE_STARTUP_MASK  (0x80000U)
#define PMC_TIMEOUTEVENTS_DSLP_BLE_STARTUP_SHIFT (19U)
/*! DSLP_BLE_STARTUP - 1: a time out event occured during power up from deepsleep state when waiting for BLE. */
#define PMC_TIMEOUTEVENTS_DSLP_BLE_STARTUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_DSLP_BLE_STARTUP_SHIFT)) & PMC_TIMEOUTEVENTS_DSLP_BLE_STARTUP_MASK)

#define PMC_TIMEOUTEVENTS_PWDN_BLE_STARTUP_MASK  (0x100000U)
#define PMC_TIMEOUTEVENTS_PWDN_BLE_STARTUP_SHIFT (20U)
/*! PWDN_BLE_STARTUP - 1: a time out event occured during power up from power down state when waiting for BLE. */
#define PMC_TIMEOUTEVENTS_PWDN_BLE_STARTUP(x)    (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUTEVENTS_PWDN_BLE_STARTUP_SHIFT)) & PMC_TIMEOUTEVENTS_PWDN_BLE_STARTUP_MASK)
/*! @} */

/*! @name TIMEOUT - TIMEOUT */
/*! @{ */

#define PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT_MASK (0xF0000U)
#define PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT_SHIFT (16U)
/*! BLE_RESTART_OSCEN_TIME_OUT - Time out value for BLE restart. Resolution is 32 us. Default is 160us */
#define PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT(x) (((uint32_t)(((uint32_t)(x)) << PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT_SHIFT)) & PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT_MASK)
/*! @} */

/*! @name PDSLEEPCFG0 - Controls the power to various modules during Low Power modes - DEEP SLEEP, POWER DOWN and DEEP POWER DOWN [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Software Reset] */
/*! @{ */

#define PMC_PDSLEEPCFG0_PDEN_DCDC_MASK           (0x1U)
#define PMC_PDSLEEPCFG0_PDEN_DCDC_SHIFT          (0U)
/*! PDEN_DCDC - Controls DCDC power during low power mode (DCDC is always shut down during POWEROFF).
 *  0b0..DCDC is powered on during low power mode..
 *  0b1..DCDC is powered off during low power mode..
 */
#define PMC_PDSLEEPCFG0_PDEN_DCDC(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_DCDC_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_DCDC_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BIAS_MASK           (0x6U)
#define PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT          (1U)
/*! PDEN_BIAS - Enable or disable bandgap in high or low power mode.
 *  0b00..Bias 0.66V low power mode enabled. This is intended to be used for retention mode of memory or digital
 *  0b01..Bias 0.63V high accuracy mode enabled. During active mode, the bias must be set in high accuracy mode
 *  0b1x..Bias disabled.
 */
#define PMC_PDSLEEPCFG0_PDEN_BIAS(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BIAS_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BOD1_MASK           (0x8U)
#define PMC_PDSLEEPCFG0_PDEN_BOD1_SHIFT          (3U)
/*! PDEN_BOD1 - Controls BoD 1 power during low power mode. (BOD1 is always shut down during POWEROFF)
 *  0b0..BOD1 is powered on during low power mode.
 *  0b1..BOD1 is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BOD1(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BOD1_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BOD1_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BOD2_MASK           (0x10U)
#define PMC_PDSLEEPCFG0_PDEN_BOD2_SHIFT          (4U)
/*! PDEN_BOD2 - Controls BoD 2 power during low power mode. (BOD2 is always shut down during POWEROFF)
 *  0b0..BOD2 is powered on during low power mode.
 *  0b1..BOD2 is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BOD2(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BOD2_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BOD2_MASK)

#define PMC_PDSLEEPCFG0_PDEN_FRO192M_MASK        (0x20U)
#define PMC_PDSLEEPCFG0_PDEN_FRO192M_SHIFT       (5U)
/*! PDEN_FRO192M - Controls 192MHz Free Running Oscillator power during DEEP SLEEP (always shut down
 *    during POWER DOWN, DEEP POWER DOWN and POWEROFF).
 *  0b0..FRO 192 MHz is powered on during low power mode.
 *  0b1..FRO 192 MHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_FRO192M(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_FRO192M_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_FRO192M_MASK)

#define PMC_PDSLEEPCFG0_PDEN_FRO32K_MASK         (0x40U)
#define PMC_PDSLEEPCFG0_PDEN_FRO32K_SHIFT        (6U)
/*! PDEN_FRO32K - Controls power during DEEP SLEEP, POWER DOWN and DEEP POWER DOWN. (FRO32K is always shut down during POWEROFF)
 *  0b0..FRO 32 KHz is powered on during low power mode.
 *  0b1..FRO 32 KHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_FRO32K(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_FRO32K_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_FRO32K_MASK)

#define PMC_PDSLEEPCFG0_PDEN_XTAL32K_MASK        (0x80U)
#define PMC_PDSLEEPCFG0_PDEN_XTAL32K_SHIFT       (7U)
/*! PDEN_XTAL32K - Controls crystal 32 KHz power during DEEP SLEEP, POWER DOWN and DEEP POWER DOWN.
 *    (XTAL32K is always shut down during POWEROFF)
 *  0b0..crystal 32 KHz is powered on during low power mode.
 *  0b1..crystal 32 KHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_XTAL32K(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_XTAL32K_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_XTAL32K_MASK)

#define PMC_PDSLEEPCFG0_PDEN_FRO1M_MASK          (0x100U)
#define PMC_PDSLEEPCFG0_PDEN_FRO1M_SHIFT         (8U)
/*! PDEN_FRO1M - Controls power during DEEP SLEEP and POWER DOWN . (FRO1M is always shut down during DEEP POWER DOWN and POWEROFF)
 *  0b0..FRO 1 MHz is powered on during low power mode.
 *  0b1..FRO 1 MHz is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_FRO1M(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_FRO1M_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_FRO1M_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BLE_MASK            (0x400U)
#define PMC_PDSLEEPCFG0_PDEN_BLE_SHIFT           (10U)
/*! PDEN_BLE - Enable power down of BLE retention domain in low power mode
 *  0b0..BLE retention domain is powered on during low power mode.
 *  0b1..BLE retention domain is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BLE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BLE_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BLE_MASK)

#define PMC_PDSLEEPCFG0_PDEN_CORE_MASK           (0x2000U)
#define PMC_PDSLEEPCFG0_PDEN_CORE_SHIFT          (13U)
/*! PDEN_CORE - Enable power down of core domain in deepsleep
 *  0b0..Digital core power domain is powered on during deep sleep mode.
 *  0b1..Digital core power domain is powered off during deep sleep mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_CORE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_CORE_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_CORE_MASK)

#define PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK         (0x10000U)
#define PMC_PDSLEEPCFG0_PDEN_LDOMEM_SHIFT        (16U)
/*! PDEN_LDOMEM - Enable power down of LDO MEM power domain in low power mode
 *  0b0..LDO MEM power domain is powered on during low power mode.
 *  0b1..LDO MEM power domain is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_LDOMEM(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_LDOMEM_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK)

#define PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK         (0x20000U)
#define PMC_PDSLEEPCFG0_PDEN_LDODIG_SHIFT        (17U)
/*! PDEN_LDODIG - Enable power down of LDO_DIG in low power mode
 *  0b0..LDO DIG power domain is powered on during low power mode.
 *  0b1..LDO DIG power domain is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_LDODIG(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_LDODIG_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK)

#define PMC_PDSLEEPCFG0_PDEN_BLE_XO32M_MASK      (0x100000U)
#define PMC_PDSLEEPCFG0_PDEN_BLE_XO32M_SHIFT     (20U)
/*! PDEN_BLE_XO32M - Enable power down of BLE 32MHz XO in low power mode
 *  0b0..32MHz crystal oscillator is powered on during low power mode.
 *  0b1..32MHz crystal oscillator is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_BLE_XO32M(x)        (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_BLE_XO32M_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_BLE_XO32M_MASK)

#define PMC_PDSLEEPCFG0_PDEN_RNG_MASK            (0x400000U)
#define PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT           (22U)
/*! PDEN_RNG - Enable power down of RNG block in low power mode
 *  0b0..RNG module is powered on during low power mode.
 *  0b1..RNG module is powered off during low power mode.
 */
#define PMC_PDSLEEPCFG0_PDEN_RNG(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT)) & PMC_PDSLEEPCFG0_PDEN_RNG_MASK)
/*! @} */

/*! @name SRAMRETCTRL - SRAMRETCTRL */
/*! @{ */

#define PMC_SRAMRETCTRL_RETEN_RAMX0_MASK         (0x1U)
#define PMC_SRAMRETCTRL_RETEN_RAMX0_SHIFT        (0U)
/*! RETEN_RAMX0 - Controls RAMX0 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAMX0(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAMX0_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAMX0_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAMX1_MASK         (0x2U)
#define PMC_SRAMRETCTRL_RETEN_RAMX1_SHIFT        (1U)
/*! RETEN_RAMX1 - Controls RAMX1 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAMX1(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAMX1_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAMX1_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAMX2_MASK         (0x4U)
#define PMC_SRAMRETCTRL_RETEN_RAMX2_SHIFT        (2U)
/*! RETEN_RAMX2 - Controls RAMX2 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAMX2(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAMX2_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAMX2_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAMX3_MASK         (0x8U)
#define PMC_SRAMRETCTRL_RETEN_RAMX3_SHIFT        (3U)
/*! RETEN_RAMX3 - Controls RAMX3 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAMX3(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAMX3_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAMX3_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM00_MASK         (0x10U)
#define PMC_SRAMRETCTRL_RETEN_RAM00_SHIFT        (4U)
/*! RETEN_RAM00 - Controls RAM00 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAM00(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM00_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM00_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM10_MASK         (0x20U)
#define PMC_SRAMRETCTRL_RETEN_RAM10_SHIFT        (5U)
/*! RETEN_RAM10 - Controls RAM10 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAM10(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM10_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM10_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAM20_MASK         (0x40U)
#define PMC_SRAMRETCTRL_RETEN_RAM20_SHIFT        (6U)
/*! RETEN_RAM20 - Controls RAM20 power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAM20(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAM20_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAM20_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAMBLEDATA_MASK    (0x80U)
#define PMC_SRAMRETCTRL_RETEN_RAMBLEDATA_SHIFT   (7U)
/*! RETEN_RAMBLEDATA - Controls BLE Data RAM power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAMBLEDATA(x)      (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAMBLEDATA_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAMBLEDATA_MASK)

#define PMC_SRAMRETCTRL_RETEN_RAMBLESEQL_MASK    (0x100U)
#define PMC_SRAMRETCTRL_RETEN_RAMBLESEQL_SHIFT   (8U)
/*! RETEN_RAMBLESEQL - Controls BLE Sequencer/List RAM power down modes during low power modes.
 *  0b0..DEEP SLEEP: the SRAM instance keeps the configuration it has before entering DEEP SLEEP, what ever it is
 *       (Normal, Light Sleep, Deep-Sleep mode and Shut down modes) POWER DOWN, DEEP POWER DOWN and POWEREDOFF: the
 *       SRAM instance is in 'Shutdown mode' (In this mode there is no data retention).
 *  0b1..The SRAM will go to DEEPSLEEP mode during DEEPSLEEP and POWERDOWN state (In this mode there is data
 *       retention), except when it was already in SHUTDOWN state during ACTIVE mode. If it was already in SHUTDOWN
 *       during ACTIVE mode, the SRAM will remain in SHUTDOWN.
 */
#define PMC_SRAMRETCTRL_RETEN_RAMBLESEQL(x)      (((uint32_t)(((uint32_t)(x)) << PMC_SRAMRETCTRL_RETEN_RAMBLESEQL_SHIFT)) & PMC_SRAMRETCTRL_RETEN_RAMBLESEQL_MASK)
/*! @} */

/*! @name PDRUNCFG0 - PDRUNCFG0 */
/*! @{ */

#define PMC_PDRUNCFG0_PDEN_DCDC_MASK             (0x1U)
#define PMC_PDRUNCFG0_PDEN_DCDC_SHIFT            (0U)
/*! PDEN_DCDC - Controls power to DCDC Converter.
 *  0b0..DCDC is powered
 *  0b1..DCDC is powered down
 */
#define PMC_PDRUNCFG0_PDEN_DCDC(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_DCDC_SHIFT)) & PMC_PDRUNCFG0_PDEN_DCDC_MASK)

#define PMC_PDRUNCFG0_PDEN_BIAS_MASK             (0x6U)
#define PMC_PDRUNCFG0_PDEN_BIAS_SHIFT            (1U)
/*! PDEN_BIAS - Enable or disable bandgap in high or low power mode.
 *  0b00..Bias 0.66V low power mode enabled. This is intended to be used for retention mode of memory or digital
 *  0b01..Bias 0.63V high accuracy mode enabled. During active mode, the bias must be set in high accuracy mode
 *  0b1x..Bias disabled.
 */
#define PMC_PDRUNCFG0_PDEN_BIAS(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BIAS_SHIFT)) & PMC_PDRUNCFG0_PDEN_BIAS_MASK)

#define PMC_PDRUNCFG0_PDEN_BOD1_MASK             (0x8U)
#define PMC_PDRUNCFG0_PDEN_BOD1_SHIFT            (3U)
/*! PDEN_BOD1 - Controls power to Brown Out Detector 1 (BOD1)
 *  0b0..BOD1 is powered
 *  0b1..BOD1 is powered down
 */
#define PMC_PDRUNCFG0_PDEN_BOD1(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BOD1_SHIFT)) & PMC_PDRUNCFG0_PDEN_BOD1_MASK)

#define PMC_PDRUNCFG0_PDEN_BOD2_MASK             (0x10U)
#define PMC_PDRUNCFG0_PDEN_BOD2_SHIFT            (4U)
/*! PDEN_BOD2 - Controls power to Brown Out Detector 2 (BOD2)
 *  0b0..BOD2 is powered
 *  0b1..BOD2 is powered down
 */
#define PMC_PDRUNCFG0_PDEN_BOD2(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BOD2_SHIFT)) & PMC_PDRUNCFG0_PDEN_BOD2_MASK)

#define PMC_PDRUNCFG0_PDEN_FRO192M_MASK          (0x20U)
#define PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT         (5U)
/*! PDEN_FRO192M - Controls power to 192MHz Free Running Oscillator
 *  0b0..FRO 192 MHz is powered
 *  0b1..FRO 192 MHz is powered down
 */
#define PMC_PDRUNCFG0_PDEN_FRO192M(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT)) & PMC_PDRUNCFG0_PDEN_FRO192M_MASK)

#define PMC_PDRUNCFG0_PDEN_FRO32K_MASK           (0x40U)
#define PMC_PDRUNCFG0_PDEN_FRO32K_SHIFT          (6U)
/*! PDEN_FRO32K - Controls power to FRO 32 KHz
 *  0b0..FRO 32 KHz is powered
 *  0b1..FRO 32 KHz is powered down
 */
#define PMC_PDRUNCFG0_PDEN_FRO32K(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_FRO32K_SHIFT)) & PMC_PDRUNCFG0_PDEN_FRO32K_MASK)

#define PMC_PDRUNCFG0_PDEN_XTAL32K_MASK          (0x80U)
#define PMC_PDRUNCFG0_PDEN_XTAL32K_SHIFT         (7U)
/*! PDEN_XTAL32K - Controls power to crystal 32 KHz
 *  0b0..crystal 32 KHz is powered
 *  0b1..crystal 32 KHz is powered down
 */
#define PMC_PDRUNCFG0_PDEN_XTAL32K(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_XTAL32K_SHIFT)) & PMC_PDRUNCFG0_PDEN_XTAL32K_MASK)

#define PMC_PDRUNCFG0_PDEN_FRO1M_MASK            (0x100U)
#define PMC_PDRUNCFG0_PDEN_FRO1M_SHIFT           (8U)
/*! PDEN_FRO1M - Controls power to FRO 1 MHz
 *  0b0..FRO 1 MHz is powered
 *  0b1..FRO 1 MHz is powered down
 */
#define PMC_PDRUNCFG0_PDEN_FRO1M(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_FRO1M_SHIFT)) & PMC_PDRUNCFG0_PDEN_FRO1M_MASK)

#define PMC_PDRUNCFG0_PDEN_BLE_MASK              (0x400U)
#define PMC_PDRUNCFG0_PDEN_BLE_SHIFT             (10U)
/*! PDEN_BLE - Control power to BLE
 *  0b0..BLE retention domain is powered
 *  0b1..BLE retention domain is powered down
 */
#define PMC_PDRUNCFG0_PDEN_BLE(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_BLE_SHIFT)) & PMC_PDRUNCFG0_PDEN_BLE_MASK)

#define PMC_PDRUNCFG0_PDEN_LDOMEM_MASK           (0x10000U)
#define PMC_PDRUNCFG0_PDEN_LDOMEM_SHIFT          (16U)
/*! PDEN_LDOMEM - Control power to LDO MEM power domain
 *  0b0..LDO MEM power domain is powered
 *  0b1..LDO MEM power domain is powered down
 */
#define PMC_PDRUNCFG0_PDEN_LDOMEM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_LDOMEM_SHIFT)) & PMC_PDRUNCFG0_PDEN_LDOMEM_MASK)

#define PMC_PDRUNCFG0_PDEN_LDODIG_MASK           (0x20000U)
#define PMC_PDRUNCFG0_PDEN_LDODIG_SHIFT          (17U)
/*! PDEN_LDODIG - Control power to LDO_DIG power domain
 *  0b0..LDO DIG power domain is powered
 *  0b1..LDO DIG power domain is powered down
 */
#define PMC_PDRUNCFG0_PDEN_LDODIG(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_LDODIG_SHIFT)) & PMC_PDRUNCFG0_PDEN_LDODIG_MASK)

#define PMC_PDRUNCFG0_PDEN_FLASH_MASK            (0x200000U)
#define PMC_PDRUNCFG0_PDEN_FLASH_SHIFT           (21U)
/*! PDEN_FLASH - Control power to Flash block
 *  0b0..Flash module is powered
 *  0b1..Flash module is powered down
 */
#define PMC_PDRUNCFG0_PDEN_FLASH(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_FLASH_SHIFT)) & PMC_PDRUNCFG0_PDEN_FLASH_MASK)

#define PMC_PDRUNCFG0_PDEN_RNG_MASK              (0x400000U)
#define PMC_PDRUNCFG0_PDEN_RNG_SHIFT             (22U)
/*! PDEN_RNG - Control power to RNG block
 *  0b0..RNG module is powered
 *  0b1..RNG module is powered down
 */
#define PMC_PDRUNCFG0_PDEN_RNG(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PDEN_RNG_SHIFT)) & PMC_PDRUNCFG0_PDEN_RNG_MASK)
/*! @} */

/*! @name PDRUNCFGSET0 - Controls the power to various analog blocks [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] */
/*! @{ */

#define PMC_PDRUNCFGSET0_PDRUNCFGSET0_MASK       (0xFFFFFFFFU)
#define PMC_PDRUNCFGSET0_PDRUNCFGSET0_SHIFT      (0U)
/*! PDRUNCFGSET0 - Writing ones to this register sets the corresponding bit or bits in the PDRUNCFG0 register, if they are implemented. */
#define PMC_PDRUNCFGSET0_PDRUNCFGSET0(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFGSET0_PDRUNCFGSET0_SHIFT)) & PMC_PDRUNCFGSET0_PDRUNCFGSET0_MASK)
/*! @} */

/*! @name PDRUNCFGCLR0 - Controls the power to various analog blocks [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] */
/*! @{ */

#define PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_MASK       (0xFFFFFFFFU)
#define PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_SHIFT      (0U)
/*! PDRUNCFGCLR0 - Writing ones to this register clears the corresponding bit or bits in the PDRUNCFG0 register, if they are implemented. */
#define PMC_PDRUNCFGCLR0_PDRUNCFGCLR0(x)         (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_SHIFT)) & PMC_PDRUNCFGCLR0_PDRUNCFGCLR0_MASK)
/*! @} */

/*! @name ROMCTRL - ROM control [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] */
/*! @{ */

#define PMC_ROMCTRL_SDB_MASK                     (0x1U)
#define PMC_ROMCTRL_SDB_SHIFT                    (0U)
/*! SDB - Shutdown pin (active low). This bit is only used during DfT. */
#define PMC_ROMCTRL_SDB(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_ROMCTRL_SDB_SHIFT)) & PMC_ROMCTRL_SDB_MASK)

#define PMC_ROMCTRL_LS_MASK                      (0x2U)
#define PMC_ROMCTRL_LS_SHIFT                     (1U)
/*! LS - Light sleep (active high). This bit is only used during DfT. */
#define PMC_ROMCTRL_LS(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_ROMCTRL_LS_SHIFT)) & PMC_ROMCTRL_LS_MASK)

#define PMC_ROMCTRL_RME_MASK                     (0x4U)
#define PMC_ROMCTRL_RME_SHIFT                    (2U)
/*! RME - Read Margin Enable */
#define PMC_ROMCTRL_RME(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_ROMCTRL_RME_SHIFT)) & PMC_ROMCTRL_RME_MASK)

#define PMC_ROMCTRL_RM_MASK                      (0x78U)
#define PMC_ROMCTRL_RM_SHIFT                     (3U)
/*! RM - read margin control setting */
#define PMC_ROMCTRL_RM(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_ROMCTRL_RM_SHIFT)) & PMC_ROMCTRL_RM_MASK)
/*! @} */

/*! @name SRAMCTRL - All SRAMs common control signals [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Software Reset] */
/*! @{ */

#define PMC_SRAMCTRL_SMB_MASK                    (0x7U)
#define PMC_SRAMCTRL_SMB_SHIFT                   (0U)
/*! SMB - Source Biasing voltage.
 *  0b000..Low leakage.
 *  0b001..Medium leakage.
 *  0b010..Highest leakage.
 *  0b011..Disable.
 */
#define PMC_SRAMCTRL_SMB(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL_SMB_SHIFT)) & PMC_SRAMCTRL_SMB_MASK)

#define PMC_SRAMCTRL_RM_MASK                     (0xF8U)
#define PMC_SRAMCTRL_RM_SHIFT                    (3U)
/*! RM - Read Margin control settings */
#define PMC_SRAMCTRL_RM(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL_RM_SHIFT)) & PMC_SRAMCTRL_RM_MASK)

#define PMC_SRAMCTRL_WM_MASK                     (0x700U)
#define PMC_SRAMCTRL_WM_SHIFT                    (8U)
/*! WM - Write Margin control settings */
#define PMC_SRAMCTRL_WM(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL_WM_SHIFT)) & PMC_SRAMCTRL_WM_MASK)
/*! @} */

/*! @name SRAMCTRL0 - RAMX0 to RAM20 power modes controls [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset] When [LS, LSDEL, DSB, DSBDEL] is: 0011 : Normal Mode 1111 : Light sleep mode 0100 : Deep-sleep mode 1100 : Shut down Mode */
/*! @{ */

#define PMC_SRAMCTRL0_RAMX0_LS_MASK              (0x1U)
#define PMC_SRAMCTRL0_RAMX0_LS_SHIFT             (0U)
/*! RAMX0_LS - RAMX0 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAMX0_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX0_LS_SHIFT)) & PMC_SRAMCTRL0_RAMX0_LS_MASK)

#define PMC_SRAMCTRL0_RAMX0_DSB_MASK             (0x2U)
#define PMC_SRAMCTRL0_RAMX0_DSB_SHIFT            (1U)
/*! RAMX0_DSB - RAMX0 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAMX0_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX0_DSB_SHIFT)) & PMC_SRAMCTRL0_RAMX0_DSB_MASK)

#define PMC_SRAMCTRL0_RAMX0_DSBDEL_MASK          (0x4U)
#define PMC_SRAMCTRL0_RAMX0_DSBDEL_SHIFT         (2U)
/*! RAMX0_DSBDEL - RAMX0 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAMX0_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX0_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX0_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAMX0_LSDEL_MASK           (0x8U)
#define PMC_SRAMCTRL0_RAMX0_LSDEL_SHIFT          (3U)
/*! RAMX0_LSDEL - RAMX0 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAMX0_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX0_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX0_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAMX1_LS_MASK              (0x10U)
#define PMC_SRAMCTRL0_RAMX1_LS_SHIFT             (4U)
/*! RAMX1_LS - RAMX1 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAMX1_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX1_LS_SHIFT)) & PMC_SRAMCTRL0_RAMX1_LS_MASK)

#define PMC_SRAMCTRL0_RAMX1_DSB_MASK             (0x20U)
#define PMC_SRAMCTRL0_RAMX1_DSB_SHIFT            (5U)
/*! RAMX1_DSB - RAMX1 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAMX1_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX1_DSB_SHIFT)) & PMC_SRAMCTRL0_RAMX1_DSB_MASK)

#define PMC_SRAMCTRL0_RAMX1_DSBDEL_MASK          (0x40U)
#define PMC_SRAMCTRL0_RAMX1_DSBDEL_SHIFT         (6U)
/*! RAMX1_DSBDEL - RAMX1 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAMX1_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX1_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX1_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAMX1_LSDEL_MASK           (0x80U)
#define PMC_SRAMCTRL0_RAMX1_LSDEL_SHIFT          (7U)
/*! RAMX1_LSDEL - RAMX1 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAMX1_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX1_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX1_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAMX2_LS_MASK              (0x100U)
#define PMC_SRAMCTRL0_RAMX2_LS_SHIFT             (8U)
/*! RAMX2_LS - RAMX2 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAMX2_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX2_LS_SHIFT)) & PMC_SRAMCTRL0_RAMX2_LS_MASK)

#define PMC_SRAMCTRL0_RAMX2_DSB_MASK             (0x200U)
#define PMC_SRAMCTRL0_RAMX2_DSB_SHIFT            (9U)
/*! RAMX2_DSB - RAMX2 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAMX2_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX2_DSB_SHIFT)) & PMC_SRAMCTRL0_RAMX2_DSB_MASK)

#define PMC_SRAMCTRL0_RAMX2_DSBDEL_MASK          (0x400U)
#define PMC_SRAMCTRL0_RAMX2_DSBDEL_SHIFT         (10U)
/*! RAMX2_DSBDEL - RAMX2 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAMX2_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX2_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX2_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAMX2_LSDEL_MASK           (0x800U)
#define PMC_SRAMCTRL0_RAMX2_LSDEL_SHIFT          (11U)
/*! RAMX2_LSDEL - RAMX2 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAMX2_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX2_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX2_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAMX3_LS_MASK              (0x1000U)
#define PMC_SRAMCTRL0_RAMX3_LS_SHIFT             (12U)
/*! RAMX3_LS - RAMX3 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAMX3_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX3_LS_SHIFT)) & PMC_SRAMCTRL0_RAMX3_LS_MASK)

#define PMC_SRAMCTRL0_RAMX3_DSB_MASK             (0x2000U)
#define PMC_SRAMCTRL0_RAMX3_DSB_SHIFT            (13U)
/*! RAMX3_DSB - RAMX3 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAMX3_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX3_DSB_SHIFT)) & PMC_SRAMCTRL0_RAMX3_DSB_MASK)

#define PMC_SRAMCTRL0_RAMX3_DSBDEL_MASK          (0x4000U)
#define PMC_SRAMCTRL0_RAMX3_DSBDEL_SHIFT         (14U)
/*! RAMX3_DSBDEL - RAMX3 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAMX3_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX3_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX3_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAMX3_LSDEL_MASK           (0x8000U)
#define PMC_SRAMCTRL0_RAMX3_LSDEL_SHIFT          (15U)
/*! RAMX3_LSDEL - RAMX3 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAMX3_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAMX3_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAMX3_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM00_LS_MASK              (0x10000U)
#define PMC_SRAMCTRL0_RAM00_LS_SHIFT             (16U)
/*! RAM00_LS - RAM00 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM00_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM00_LS_SHIFT)) & PMC_SRAMCTRL0_RAM00_LS_MASK)

#define PMC_SRAMCTRL0_RAM00_DSB_MASK             (0x20000U)
#define PMC_SRAMCTRL0_RAM00_DSB_SHIFT            (17U)
/*! RAM00_DSB - RAM00 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM00_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM00_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM00_DSB_MASK)

#define PMC_SRAMCTRL0_RAM00_DSBDEL_MASK          (0x40000U)
#define PMC_SRAMCTRL0_RAM00_DSBDEL_SHIFT         (18U)
/*! RAM00_DSBDEL - RAM00 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM00_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM00_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM00_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM00_LSDEL_MASK           (0x80000U)
#define PMC_SRAMCTRL0_RAM00_LSDEL_SHIFT          (19U)
/*! RAM00_LSDEL - RAM00 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM00_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM00_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM00_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM10_LS_MASK              (0x100000U)
#define PMC_SRAMCTRL0_RAM10_LS_SHIFT             (20U)
/*! RAM10_LS - RAM10 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM10_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM10_LS_SHIFT)) & PMC_SRAMCTRL0_RAM10_LS_MASK)

#define PMC_SRAMCTRL0_RAM10_DSB_MASK             (0x200000U)
#define PMC_SRAMCTRL0_RAM10_DSB_SHIFT            (21U)
/*! RAM10_DSB - RAM10 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM10_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM10_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM10_DSB_MASK)

#define PMC_SRAMCTRL0_RAM10_DSBDEL_MASK          (0x400000U)
#define PMC_SRAMCTRL0_RAM10_DSBDEL_SHIFT         (22U)
/*! RAM10_DSBDEL - RAM10 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM10_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM10_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM10_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM10_LSDEL_MASK           (0x800000U)
#define PMC_SRAMCTRL0_RAM10_LSDEL_SHIFT          (23U)
/*! RAM10_LSDEL - RAM10 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM10_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM10_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM10_LSDEL_MASK)

#define PMC_SRAMCTRL0_RAM20_LS_MASK              (0x1000000U)
#define PMC_SRAMCTRL0_RAM20_LS_SHIFT             (24U)
/*! RAM20_LS - RAM20 Light Sleep mode. */
#define PMC_SRAMCTRL0_RAM20_LS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM20_LS_SHIFT)) & PMC_SRAMCTRL0_RAM20_LS_MASK)

#define PMC_SRAMCTRL0_RAM20_DSB_MASK             (0x2000000U)
#define PMC_SRAMCTRL0_RAM20_DSB_SHIFT            (25U)
/*! RAM20_DSB - RAM20 Deep sleep mode. */
#define PMC_SRAMCTRL0_RAM20_DSB(x)               (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM20_DSB_SHIFT)) & PMC_SRAMCTRL0_RAM20_DSB_MASK)

#define PMC_SRAMCTRL0_RAM20_DSBDEL_MASK          (0x4000000U)
#define PMC_SRAMCTRL0_RAM20_DSBDEL_SHIFT         (26U)
/*! RAM20_DSBDEL - RAM20 Deep sleep delayed. */
#define PMC_SRAMCTRL0_RAM20_DSBDEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM20_DSBDEL_SHIFT)) & PMC_SRAMCTRL0_RAM20_DSBDEL_MASK)

#define PMC_SRAMCTRL0_RAM20_LSDEL_MASK           (0x8000000U)
#define PMC_SRAMCTRL0_RAM20_LSDEL_SHIFT          (27U)
/*! RAM20_LSDEL - RAM20 Sleep mode disable. */
#define PMC_SRAMCTRL0_RAM20_LSDEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL0_RAM20_LSDEL_SHIFT)) & PMC_SRAMCTRL0_RAM20_LSDEL_MASK)
/*! @} */

/*! @name SRAMCTRL1 - BLE RAM power mode controls */
/*! @{ */

#define PMC_SRAMCTRL1_RAMBLEDATA_LS_MASK         (0x1U)
#define PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT        (0U)
/*! RAMBLEDATA_LS - RAM BLE Data Light Sleep mode */
#define PMC_SRAMCTRL1_RAMBLEDATA_LS(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT)) & PMC_SRAMCTRL1_RAMBLEDATA_LS_MASK)

#define PMC_SRAMCTRL1_RAMBLEDATA_DSB_MASK        (0x2U)
#define PMC_SRAMCTRL1_RAMBLEDATA_DSB_SHIFT       (1U)
/*! RAMBLEDATA_DSB - RAM BLE Data Deep sleep mode */
#define PMC_SRAMCTRL1_RAMBLEDATA_DSB(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLEDATA_DSB_SHIFT)) & PMC_SRAMCTRL1_RAMBLEDATA_DSB_MASK)

#define PMC_SRAMCTRL1_RAMBLEDATA_DSBDEL_MASK     (0x4U)
#define PMC_SRAMCTRL1_RAMBLEDATA_DSBDEL_SHIFT    (2U)
/*! RAMBLEDATA_DSBDEL - RAM BLE Data Deep sleep delayed */
#define PMC_SRAMCTRL1_RAMBLEDATA_DSBDEL(x)       (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLEDATA_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAMBLEDATA_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAMBLEDATA_LSDEL_MASK      (0x8U)
#define PMC_SRAMCTRL1_RAMBLEDATA_LSDEL_SHIFT     (3U)
/*! RAMBLEDATA_LSDEL - RAM BLE Data Sleep mode disable */
#define PMC_SRAMCTRL1_RAMBLEDATA_LSDEL(x)        (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLEDATA_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAMBLEDATA_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAMBLESEQL_LS_MASK         (0x10U)
#define PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT        (4U)
/*! RAMBLESEQL_LS - RAM BLE Sequencer Light Sleep mode */
#define PMC_SRAMCTRL1_RAMBLESEQL_LS(x)           (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT)) & PMC_SRAMCTRL1_RAMBLESEQL_LS_MASK)

#define PMC_SRAMCTRL1_RAMBLESEQL_DSB_MASK        (0x20U)
#define PMC_SRAMCTRL1_RAMBLESEQL_DSB_SHIFT       (5U)
/*! RAMBLESEQL_DSB - RAM BLE Sequencer Deep sleep mode */
#define PMC_SRAMCTRL1_RAMBLESEQL_DSB(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLESEQL_DSB_SHIFT)) & PMC_SRAMCTRL1_RAMBLESEQL_DSB_MASK)

#define PMC_SRAMCTRL1_RAMBLESEQL_DSBDEL_MASK     (0x40U)
#define PMC_SRAMCTRL1_RAMBLESEQL_DSBDEL_SHIFT    (6U)
/*! RAMBLESEQL_DSBDEL - RAM BLE Sequencer Deep sleep delayed */
#define PMC_SRAMCTRL1_RAMBLESEQL_DSBDEL(x)       (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLESEQL_DSBDEL_SHIFT)) & PMC_SRAMCTRL1_RAMBLESEQL_DSBDEL_MASK)

#define PMC_SRAMCTRL1_RAMBLESEQL_LSDEL_MASK      (0x80U)
#define PMC_SRAMCTRL1_RAMBLESEQL_LSDEL_SHIFT     (7U)
/*! RAMBLESEQL_LSDEL - RAMBLE Sequencer Sleep mode disable */
#define PMC_SRAMCTRL1_RAMBLESEQL_LSDEL(x)        (((uint32_t)(((uint32_t)(x)) << PMC_SRAMCTRL1_RAMBLESEQL_LSDEL_SHIFT)) & PMC_SRAMCTRL1_RAMBLESEQL_LSDEL_MASK)
/*! @} */

/*! @name SRAMASSISTCTRL0 - SRAMASSISTCTRL0 */
/*! @{ */

#define PMC_SRAMASSISTCTRL0_RAM_SRAM_MASK        (0x6U)
#define PMC_SRAMASSISTCTRL0_RAM_SRAM_SHIFT       (1U)
/*! RAM_SRAM - Read Assist Margin */
#define PMC_SRAMASSISTCTRL0_RAM_SRAM(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMASSISTCTRL0_RAM_SRAM_SHIFT)) & PMC_SRAMASSISTCTRL0_RAM_SRAM_MASK)

#define PMC_SRAMASSISTCTRL0_WAM_SRAM_MASK        (0x38U)
#define PMC_SRAMASSISTCTRL0_WAM_SRAM_SHIFT       (3U)
/*! WAM_SRAM - Write Assist Margin */
#define PMC_SRAMASSISTCTRL0_WAM_SRAM(x)          (((uint32_t)(((uint32_t)(x)) << PMC_SRAMASSISTCTRL0_WAM_SRAM_SHIFT)) & PMC_SRAMASSISTCTRL0_WAM_SRAM_MASK)
/*! @} */

/*! @name SRAMASSISTCTRL1 - SRAMASSISTCTRL1 */
/*! @{ */

#define PMC_SRAMASSISTCTRL1_RAM_SRAM_BLE_MASK    (0x6U)
#define PMC_SRAMASSISTCTRL1_RAM_SRAM_BLE_SHIFT   (1U)
/*! RAM_SRAM_BLE - Read Assist Margin */
#define PMC_SRAMASSISTCTRL1_RAM_SRAM_BLE(x)      (((uint32_t)(((uint32_t)(x)) << PMC_SRAMASSISTCTRL1_RAM_SRAM_BLE_SHIFT)) & PMC_SRAMASSISTCTRL1_RAM_SRAM_BLE_MASK)

#define PMC_SRAMASSISTCTRL1_WAM_SRAM_BLE_MASK    (0x38U)
#define PMC_SRAMASSISTCTRL1_WAM_SRAM_BLE_SHIFT   (3U)
/*! WAM_SRAM_BLE - Write Assist Margin */
#define PMC_SRAMASSISTCTRL1_WAM_SRAM_BLE(x)      (((uint32_t)(((uint32_t)(x)) << PMC_SRAMASSISTCTRL1_WAM_SRAM_BLE_SHIFT)) & PMC_SRAMASSISTCTRL1_WAM_SRAM_BLE_MASK)
/*! @} */

/*! @name DFTENDIS - DFTENDIS */
/*! @{ */

#define PMC_DFTENDIS_CORE_OK_MASK                (0x1U)
#define PMC_DFTENDIS_CORE_OK_SHIFT               (0U)
/*! CORE_OK - Accessible only through DFT */
#define PMC_DFTENDIS_CORE_OK(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_CORE_OK_SHIFT)) & PMC_DFTENDIS_CORE_OK_MASK)

#define PMC_DFTENDIS_WUP_TEST_MASK               (0x2U)
#define PMC_DFTENDIS_WUP_TEST_SHIFT              (1U)
/*! WUP_TEST - Accessible only through DFT */
#define PMC_DFTENDIS_WUP_TEST(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_WUP_TEST_SHIFT)) & PMC_DFTENDIS_WUP_TEST_MASK)

#define PMC_DFTENDIS_WUP_TEST_SEL_MASK           (0x4U)
#define PMC_DFTENDIS_WUP_TEST_SEL_SHIFT          (2U)
/*! WUP_TEST_SEL - Accessible only through DFT */
#define PMC_DFTENDIS_WUP_TEST_SEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_WUP_TEST_SEL_SHIFT)) & PMC_DFTENDIS_WUP_TEST_SEL_MASK)

#define PMC_DFTENDIS_BG_TEST_EN_MASK             (0x8U)
#define PMC_DFTENDIS_BG_TEST_EN_SHIFT            (3U)
/*! BG_TEST_EN - Accessible only through DFT */
#define PMC_DFTENDIS_BG_TEST_EN(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BG_TEST_EN_SHIFT)) & PMC_DFTENDIS_BG_TEST_EN_MASK)

#define PMC_DFTENDIS_LDOAO_TEST_DIS_MASK         (0x10U)
#define PMC_DFTENDIS_LDOAO_TEST_DIS_SHIFT        (4U)
/*! LDOAO_TEST_DIS - Accessible only through DFT */
#define PMC_DFTENDIS_LDOAO_TEST_DIS(x)           (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_LDOAO_TEST_DIS_SHIFT)) & PMC_DFTENDIS_LDOAO_TEST_DIS_MASK)

#define PMC_DFTENDIS_BUFFER_EN_MASK              (0x20U)
#define PMC_DFTENDIS_BUFFER_EN_SHIFT             (5U)
/*! BUFFER_EN - Accessible only through DFT */
#define PMC_DFTENDIS_BUFFER_EN(x)                (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BUFFER_EN_SHIFT)) & PMC_DFTENDIS_BUFFER_EN_MASK)

#define PMC_DFTENDIS_PD_PMC_MASK                 (0x40U)
#define PMC_DFTENDIS_PD_PMC_SHIFT                (6U)
/*! PD_PMC - Accessible only through DFT */
#define PMC_DFTENDIS_PD_PMC(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_PD_PMC_SHIFT)) & PMC_DFTENDIS_PD_PMC_MASK)

#define PMC_DFTENDIS_SWCTRL_S4_MASK              (0x80U)
#define PMC_DFTENDIS_SWCTRL_S4_SHIFT             (7U)
/*! SWCTRL_S4 - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S4(x)                (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S4_SHIFT)) & PMC_DFTENDIS_SWCTRL_S4_MASK)

#define PMC_DFTENDIS_SWCTRL_S5a_MASK             (0x100U)
#define PMC_DFTENDIS_SWCTRL_S5a_SHIFT            (8U)
/*! SWCTRL_S5a - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S5a(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S5a_SHIFT)) & PMC_DFTENDIS_SWCTRL_S5a_MASK)

#define PMC_DFTENDIS_SWCTRL_S5b_MASK             (0x200U)
#define PMC_DFTENDIS_SWCTRL_S5b_SHIFT            (9U)
/*! SWCTRL_S5b - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S5b(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S5b_SHIFT)) & PMC_DFTENDIS_SWCTRL_S5b_MASK)

#define PMC_DFTENDIS_SWCTRL_S9_MASK              (0x400U)
#define PMC_DFTENDIS_SWCTRL_S9_SHIFT             (10U)
/*! SWCTRL_S9 - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S9(x)                (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S9_SHIFT)) & PMC_DFTENDIS_SWCTRL_S9_MASK)

#define PMC_DFTENDIS_SWCTRL_S10_MASK             (0x800U)
#define PMC_DFTENDIS_SWCTRL_S10_SHIFT            (11U)
/*! SWCTRL_S10 - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S10(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S10_SHIFT)) & PMC_DFTENDIS_SWCTRL_S10_MASK)

#define PMC_DFTENDIS_SWCTRL_S11_MASK             (0x1000U)
#define PMC_DFTENDIS_SWCTRL_S11_SHIFT            (12U)
/*! SWCTRL_S11 - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S11(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S11_SHIFT)) & PMC_DFTENDIS_SWCTRL_S11_MASK)

#define PMC_DFTENDIS_SWCTRL_S12_MASK             (0x2000U)
#define PMC_DFTENDIS_SWCTRL_S12_SHIFT            (13U)
/*! SWCTRL_S12 - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S12(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S12_SHIFT)) & PMC_DFTENDIS_SWCTRL_S12_MASK)

#define PMC_DFTENDIS_SWCTRL_S12rom_MASK          (0x4000U)
#define PMC_DFTENDIS_SWCTRL_S12rom_SHIFT         (14U)
/*! SWCTRL_S12rom - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S12rom(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S12rom_SHIFT)) & PMC_DFTENDIS_SWCTRL_S12rom_MASK)

#define PMC_DFTENDIS_SWCTRL_S13_MASK             (0x8000U)
#define PMC_DFTENDIS_SWCTRL_S13_SHIFT            (15U)
/*! SWCTRL_S13 - Accessible only through DFT */
#define PMC_DFTENDIS_SWCTRL_S13(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_SWCTRL_S13_SHIFT)) & PMC_DFTENDIS_SWCTRL_S13_MASK)

#define PMC_DFTENDIS_LP_MODE_FORCE_MASK          (0x10000U)
#define PMC_DFTENDIS_LP_MODE_FORCE_SHIFT         (16U)
/*! LP_MODE_FORCE - Accessible only through DFT */
#define PMC_DFTENDIS_LP_MODE_FORCE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_LP_MODE_FORCE_SHIFT)) & PMC_DFTENDIS_LP_MODE_FORCE_MASK)

#define PMC_DFTENDIS_BLE_DIGCLKEN_MASK           (0x20000U)
#define PMC_DFTENDIS_BLE_DIGCLKEN_SHIFT          (17U)
/*! BLE_DIGCLKEN - Accessible only through DFT */
#define PMC_DFTENDIS_BLE_DIGCLKEN(x)             (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BLE_DIGCLKEN_SHIFT)) & PMC_DFTENDIS_BLE_DIGCLKEN_MASK)

#define PMC_DFTENDIS_BLE_STBYEN_MASK             (0x40000U)
#define PMC_DFTENDIS_BLE_STBYEN_SHIFT            (18U)
/*! BLE_STBYEN - Accessible only through DFT */
#define PMC_DFTENDIS_BLE_STBYEN(x)               (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BLE_STBYEN_SHIFT)) & PMC_DFTENDIS_BLE_STBYEN_MASK)

#define PMC_DFTENDIS_PORHV_VSTRESS_EN_MASK       (0x80000U)
#define PMC_DFTENDIS_PORHV_VSTRESS_EN_SHIFT      (19U)
/*! PORHV_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_PORHV_VSTRESS_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_PORHV_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_PORHV_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_PORLV_VSTRESS_EN_MASK       (0x100000U)
#define PMC_DFTENDIS_PORLV_VSTRESS_EN_SHIFT      (20U)
/*! PORLV_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_PORLV_VSTRESS_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_PORLV_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_PORLV_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_BG_STRESS_EN_MASK           (0x200000U)
#define PMC_DFTENDIS_BG_STRESS_EN_SHIFT          (21U)
/*! BG_STRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_BG_STRESS_EN(x)             (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BG_STRESS_EN_SHIFT)) & PMC_DFTENDIS_BG_STRESS_EN_MASK)

#define PMC_DFTENDIS_BOD1_VSTRESS_EN_MASK        (0x400000U)
#define PMC_DFTENDIS_BOD1_VSTRESS_EN_SHIFT       (22U)
/*! BOD1_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_BOD1_VSTRESS_EN(x)          (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BOD1_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_BOD1_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_BOD2_VSTRESS_EN_MASK        (0x800000U)
#define PMC_DFTENDIS_BOD2_VSTRESS_EN_SHIFT       (23U)
/*! BOD2_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_BOD2_VSTRESS_EN(x)          (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BOD2_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_BOD2_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_DCDC_VSTRESS_EN_MASK        (0x1000000U)
#define PMC_DFTENDIS_DCDC_VSTRESS_EN_SHIFT       (24U)
/*! DCDC_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_DCDC_VSTRESS_EN(x)          (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_DCDC_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_DCDC_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_FRO1M_VSTRESS_EN_MASK       (0x2000000U)
#define PMC_DFTENDIS_FRO1M_VSTRESS_EN_SHIFT      (25U)
/*! FRO1M_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_FRO1M_VSTRESS_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_FRO1M_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_FRO1M_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_FRO32K_VSTRESS_EN_MASK      (0x4000000U)
#define PMC_DFTENDIS_FRO32K_VSTRESS_EN_SHIFT     (26U)
/*! FRO32K_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_FRO32K_VSTRESS_EN(x)        (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_FRO32K_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_FRO32K_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_XO32_CAPTEST_VSTRESS_EN_MASK (0x8000000U)
#define PMC_DFTENDIS_XO32_CAPTEST_VSTRESS_EN_SHIFT (27U)
/*! XO32_CAPTEST_VSTRESS_EN - Accessible only through DFT */
#define PMC_DFTENDIS_XO32_CAPTEST_VSTRESS_EN(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_XO32_CAPTEST_VSTRESS_EN_SHIFT)) & PMC_DFTENDIS_XO32_CAPTEST_VSTRESS_EN_MASK)

#define PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_0_MASK (0x10000000U)
#define PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_0_SHIFT (28U)
/*! FRO192M_VSTRESS_CTRL_0 - Accessible only through DFT */
#define PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_0(x)   (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_0_SHIFT)) & PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_0_MASK)

#define PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_1_MASK (0x20000000U)
#define PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_1_SHIFT (29U)
/*! FRO192M_VSTRESS_CTRL_1 - Accessible only through DFT */
#define PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_1(x)   (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_1_SHIFT)) & PMC_DFTENDIS_FRO192M_VSTRESS_CTRL_1_MASK)

#define PMC_DFTENDIS_BLE_EXT_SPI_SEL_MASK        (0x40000000U)
#define PMC_DFTENDIS_BLE_EXT_SPI_SEL_SHIFT       (30U)
/*! BLE_EXT_SPI_SEL - Accessible only through DFT */
#define PMC_DFTENDIS_BLE_EXT_SPI_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BLE_EXT_SPI_SEL_SHIFT)) & PMC_DFTENDIS_BLE_EXT_SPI_SEL_MASK)

#define PMC_DFTENDIS_BLE_OSCTSTEN_MASK           (0x80000000U)
#define PMC_DFTENDIS_BLE_OSCTSTEN_SHIFT          (31U)
/*! BLE_OSCTSTEN - Accessible only through DFT */
#define PMC_DFTENDIS_BLE_OSCTSTEN(x)             (((uint32_t)(((uint32_t)(x)) << PMC_DFTENDIS_BLE_OSCTSTEN_SHIFT)) & PMC_DFTENDIS_BLE_OSCTSTEN_MASK)
/*! @} */

/*! @name DFTDCDC - DFTDCDC */
/*! @{ */

#define PMC_DFTDCDC_DCDC_SW_EN_MASK              (0x1U)
#define PMC_DFTDCDC_DCDC_SW_EN_SHIFT             (0U)
/*! DCDC_SW_EN - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_SW_EN(x)                (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_SW_EN_SHIFT)) & PMC_DFTDCDC_DCDC_SW_EN_MASK)

#define PMC_DFTDCDC_DCDC0_TEST_EN_MASK           (0x2U)
#define PMC_DFTDCDC_DCDC0_TEST_EN_SHIFT          (1U)
/*! DCDC0_TEST_EN - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC0_TEST_EN(x)             (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC0_TEST_EN_SHIFT)) & PMC_DFTDCDC_DCDC0_TEST_EN_MASK)

#define PMC_DFTDCDC_DCDC_TEST_SEL_0_MASK         (0x4U)
#define PMC_DFTDCDC_DCDC_TEST_SEL_0_SHIFT        (2U)
/*! DCDC_TEST_SEL_0 - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_TEST_SEL_0(x)           (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_TEST_SEL_0_SHIFT)) & PMC_DFTDCDC_DCDC_TEST_SEL_0_MASK)

#define PMC_DFTDCDC_DCDC_TEST_SEL_1_MASK         (0x8U)
#define PMC_DFTDCDC_DCDC_TEST_SEL_1_SHIFT        (3U)
/*! DCDC_TEST_SEL_1 - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_TEST_SEL_1(x)           (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_TEST_SEL_1_SHIFT)) & PMC_DFTDCDC_DCDC_TEST_SEL_1_MASK)

#define PMC_DFTDCDC_DCDC_TEST_SEL_2_MASK         (0x10U)
#define PMC_DFTDCDC_DCDC_TEST_SEL_2_SHIFT        (4U)
/*! DCDC_TEST_SEL_2 - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_TEST_SEL_2(x)           (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_TEST_SEL_2_SHIFT)) & PMC_DFTDCDC_DCDC_TEST_SEL_2_MASK)

#define PMC_DFTDCDC_DCDC_SPARE_0_MASK            (0x20U)
#define PMC_DFTDCDC_DCDC_SPARE_0_SHIFT           (5U)
/*! DCDC_SPARE_0 - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_SPARE_0(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_SPARE_0_SHIFT)) & PMC_DFTDCDC_DCDC_SPARE_0_MASK)

#define PMC_DFTDCDC_DCDC_SPARE_1_MASK            (0x40U)
#define PMC_DFTDCDC_DCDC_SPARE_1_SHIFT           (6U)
/*! DCDC_SPARE_1 - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_SPARE_1(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_SPARE_1_SHIFT)) & PMC_DFTDCDC_DCDC_SPARE_1_MASK)

#define PMC_DFTDCDC_DCDC_SPARE_2_MASK            (0x80U)
#define PMC_DFTDCDC_DCDC_SPARE_2_SHIFT           (7U)
/*! DCDC_SPARE_2 - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_SPARE_2(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_SPARE_2_SHIFT)) & PMC_DFTDCDC_DCDC_SPARE_2_MASK)

#define PMC_DFTDCDC_DCDC_INRUSH_BYP_LV_MASK      (0x100U)
#define PMC_DFTDCDC_DCDC_INRUSH_BYP_LV_SHIFT     (8U)
/*! DCDC_INRUSH_BYP_LV - Accessible only through DFT */
#define PMC_DFTDCDC_DCDC_INRUSH_BYP_LV(x)        (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_DCDC_INRUSH_BYP_LV_SHIFT)) & PMC_DFTDCDC_DCDC_INRUSH_BYP_LV_MASK)

#define PMC_DFTDCDC_BOD_CONNECT1_MASK            (0x200U)
#define PMC_DFTDCDC_BOD_CONNECT1_SHIFT           (9U)
/*! BOD_CONNECT1 - Accessible only through DFT */
#define PMC_DFTDCDC_BOD_CONNECT1(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_BOD_CONNECT1_SHIFT)) & PMC_DFTDCDC_BOD_CONNECT1_MASK)

#define PMC_DFTDCDC_BOD_CONNECT2_MASK            (0x400U)
#define PMC_DFTDCDC_BOD_CONNECT2_SHIFT           (10U)
/*! BOD_CONNECT2 - Accessible only through DFT */
#define PMC_DFTDCDC_BOD_CONNECT2(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_BOD_CONNECT2_SHIFT)) & PMC_DFTDCDC_BOD_CONNECT2_MASK)

#define PMC_DFTDCDC_LDOD_ENA_HPM_MASK            (0x800U)
#define PMC_DFTDCDC_LDOD_ENA_HPM_SHIFT           (11U)
/*! LDOD_ENA_HPM - Accessible only through DFT */
#define PMC_DFTDCDC_LDOD_ENA_HPM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_LDOD_ENA_HPM_SHIFT)) & PMC_DFTDCDC_LDOD_ENA_HPM_MASK)

#define PMC_DFTDCDC_LDOD_ENA_LPM_MASK            (0x1000U)
#define PMC_DFTDCDC_LDOD_ENA_LPM_SHIFT           (12U)
/*! LDOD_ENA_LPM - Accessible only through DFT */
#define PMC_DFTDCDC_LDOD_ENA_LPM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_LDOD_ENA_LPM_SHIFT)) & PMC_DFTDCDC_LDOD_ENA_LPM_MASK)

#define PMC_DFTDCDC_LDOM_ENA_HPM_MASK            (0x2000U)
#define PMC_DFTDCDC_LDOM_ENA_HPM_SHIFT           (13U)
/*! LDOM_ENA_HPM - Accessible only through DFT */
#define PMC_DFTDCDC_LDOM_ENA_HPM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_LDOM_ENA_HPM_SHIFT)) & PMC_DFTDCDC_LDOM_ENA_HPM_MASK)

#define PMC_DFTDCDC_LDOM_ENA_LPM_MASK            (0x4000U)
#define PMC_DFTDCDC_LDOM_ENA_LPM_SHIFT           (14U)
/*! LDOM_ENA_LPM - Accessible only through DFT */
#define PMC_DFTDCDC_LDOM_ENA_LPM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_LDOM_ENA_LPM_SHIFT)) & PMC_DFTDCDC_LDOM_ENA_LPM_MASK)

#define PMC_DFTDCDC_BG_EN_MASK                   (0x8000U)
#define PMC_DFTDCDC_BG_EN_SHIFT                  (15U)
/*! BG_EN - Accessible only through DFT */
#define PMC_DFTDCDC_BG_EN(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_BG_EN_SHIFT)) & PMC_DFTDCDC_BG_EN_MASK)

#define PMC_DFTDCDC_BG_LP_VREF_SW_MASK           (0x10000U)
#define PMC_DFTDCDC_BG_LP_VREF_SW_SHIFT          (16U)
/*! BG_LP_VREF_SW - Accessible only through DFT */
#define PMC_DFTDCDC_BG_LP_VREF_SW(x)             (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_BG_LP_VREF_SW_SHIFT)) & PMC_DFTDCDC_BG_LP_VREF_SW_MASK)

#define PMC_DFTDCDC_BG_HP_EN_MASK                (0x20000U)
#define PMC_DFTDCDC_BG_HP_EN_SHIFT               (17U)
/*! BG_HP_EN - Accessible only through DFT */
#define PMC_DFTDCDC_BG_HP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_BG_HP_EN_SHIFT)) & PMC_DFTDCDC_BG_HP_EN_MASK)

#define PMC_DFTDCDC_BLE_DSLP_MASK                (0x40000U)
#define PMC_DFTDCDC_BLE_DSLP_SHIFT               (18U)
/*! BLE_DSLP - Accessible only through DFT */
#define PMC_DFTDCDC_BLE_DSLP(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_DFTDCDC_BLE_DSLP_SHIFT)) & PMC_DFTDCDC_BLE_DSLP_MASK)
/*! @} */

/*! @name DFTCAPTEST - DFTCAPTEST */
/*! @{ */

#define PMC_DFTCAPTEST_XO32_CAPTEST_EN_MASK      (0x1U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_EN_SHIFT     (0U)
/*! XO32_CAPTEST_EN - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_EN(x)        (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_EN_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_EN_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_OSC_IN_MASK  (0x2U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_OSC_IN_SHIFT (1U)
/*! XO32_CAPTEST_OSC_IN - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_OSC_IN(x)    (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_OSC_IN_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_OSC_IN_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_0_MASK (0x8U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_0_SHIFT (3U)
/*! XO32_CAPTEST_CNTVAL_0 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_0(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_0_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_0_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_1_MASK (0x10U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_1_SHIFT (4U)
/*! XO32_CAPTEST_CNTVAL_1 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_1(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_1_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_1_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_2_MASK (0x20U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_2_SHIFT (5U)
/*! XO32_CAPTEST_CNTVAL_2 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_2(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_2_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_2_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_3_MASK (0x40U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_3_SHIFT (6U)
/*! XO32_CAPTEST_CNTVAL_3 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_3(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_3_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_3_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_4_MASK (0x80U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_4_SHIFT (7U)
/*! XO32_CAPTEST_CNTVAL_4 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_4(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_4_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_4_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_5_MASK (0x100U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_5_SHIFT (8U)
/*! XO32_CAPTEST_CNTVAL_5 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_5(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_5_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_5_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_6_MASK (0x200U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_6_SHIFT (9U)
/*! XO32_CAPTEST_CNTVAL_6 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_6(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_6_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_6_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_7_MASK (0x400U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_7_SHIFT (10U)
/*! XO32_CAPTEST_CNTVAL_7 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_7(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_7_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_7_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_8_MASK (0x800U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_8_SHIFT (11U)
/*! XO32_CAPTEST_CNTVAL_8 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_8(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_8_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_8_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_9_MASK (0x1000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_9_SHIFT (12U)
/*! XO32_CAPTEST_CNTVAL_9 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_9(x)  (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_9_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_9_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_10_MASK (0x2000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_10_SHIFT (13U)
/*! XO32_CAPTEST_CNTVAL_10 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_10(x) (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_10_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_10_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_11_MASK (0x4000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_11_SHIFT (14U)
/*! XO32_CAPTEST_CNTVAL_11 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_11(x) (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_11_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_11_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_12_MASK (0x8000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_12_SHIFT (15U)
/*! XO32_CAPTEST_CNTVAL_12 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_12(x) (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_12_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_12_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_13_MASK (0x10000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_13_SHIFT (16U)
/*! XO32_CAPTEST_CNTVAL_13 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_13(x) (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_13_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_13_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_14_MASK (0x20000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_14_SHIFT (17U)
/*! XO32_CAPTEST_CNTVAL_14 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_14(x) (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_14_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_14_MASK)

#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_15_MASK (0x40000U)
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_15_SHIFT (18U)
/*! XO32_CAPTEST_CNTVAL_15 - Accessible only through DFT */
#define PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_15(x) (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_15_SHIFT)) & PMC_DFTCAPTEST_XO32_CAPTEST_CNTVAL_15_MASK)

#define PMC_DFTCAPTEST_COT_VALUE_0_MASK          (0x100000U)
#define PMC_DFTCAPTEST_COT_VALUE_0_SHIFT         (20U)
/*! COT_VALUE_0 - Accessible only through DFT */
#define PMC_DFTCAPTEST_COT_VALUE_0(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_COT_VALUE_0_SHIFT)) & PMC_DFTCAPTEST_COT_VALUE_0_MASK)

#define PMC_DFTCAPTEST_COT_VALUE_1_MASK          (0x200000U)
#define PMC_DFTCAPTEST_COT_VALUE_1_SHIFT         (21U)
/*! COT_VALUE_1 - Accessible only through DFT */
#define PMC_DFTCAPTEST_COT_VALUE_1(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_COT_VALUE_1_SHIFT)) & PMC_DFTCAPTEST_COT_VALUE_1_MASK)

#define PMC_DFTCAPTEST_COT_VALUE_2_MASK          (0x400000U)
#define PMC_DFTCAPTEST_COT_VALUE_2_SHIFT         (22U)
/*! COT_VALUE_2 - Accessible only through DFT */
#define PMC_DFTCAPTEST_COT_VALUE_2(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_COT_VALUE_2_SHIFT)) & PMC_DFTCAPTEST_COT_VALUE_2_MASK)

#define PMC_DFTCAPTEST_COT_VALUE_3_MASK          (0x800000U)
#define PMC_DFTCAPTEST_COT_VALUE_3_SHIFT         (23U)
/*! COT_VALUE_3 - Accessible only through DFT */
#define PMC_DFTCAPTEST_COT_VALUE_3(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_COT_VALUE_3_SHIFT)) & PMC_DFTCAPTEST_COT_VALUE_3_MASK)

#define PMC_DFTCAPTEST_COT_VALUE_4_MASK          (0x1000000U)
#define PMC_DFTCAPTEST_COT_VALUE_4_SHIFT         (24U)
/*! COT_VALUE_4 - Accessible only through DFT */
#define PMC_DFTCAPTEST_COT_VALUE_4(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_COT_VALUE_4_SHIFT)) & PMC_DFTCAPTEST_COT_VALUE_4_MASK)

#define PMC_DFTCAPTEST_COT_VALUE_5_MASK          (0x2000000U)
#define PMC_DFTCAPTEST_COT_VALUE_5_SHIFT         (25U)
/*! COT_VALUE_5 - Accessible only through DFT */
#define PMC_DFTCAPTEST_COT_VALUE_5(x)            (((uint32_t)(((uint32_t)(x)) << PMC_DFTCAPTEST_COT_VALUE_5_SHIFT)) & PMC_DFTCAPTEST_COT_VALUE_5_MASK)
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

