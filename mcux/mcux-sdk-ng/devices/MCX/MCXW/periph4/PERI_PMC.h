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
       uint8_t RESERVED_0[4];
  __I  uint32_t STATUS;                            /**< Power Management Controller FSM (Finite State Machines) status, offset: 0x4 */
  __IO uint32_t RESETCTRL;                         /**< Reset Control [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0x8 */
  __IO uint32_t RESETCAUSE;                        /**< Reset Cause register [Reset by: PoR], offset: 0xC */
       uint8_t RESERVED_1[52];
  __IO uint32_t FRO1M;                             /**< 1 MHz Free Running Oscillator control register, offset: 0x44 */
       uint8_t RESERVED_2[28];
  __IO uint32_t WAKEUPIOCTRL;                      /**< WAKEUPIOCTRL, offset: 0x64 */
  __I  uint32_t WAKEIOCAUSE;                       /**< Allows to identify the Wake-up I/O source from Deep Power Down mode, offset: 0x68 */
       uint8_t RESERVED_3[8];
  __I  uint32_t STATUSCLK;                         /**< FRO and XTAL status register [Reset by: PoR, Brown Out Detectors Reset], offset: 0x74 */
       uint8_t RESERVED_4[12];
  __IO uint32_t AOREG1;                            /**< General purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset], offset: 0x84 */
       uint8_t RESERVED_5[16];
  __IO uint32_t RTCOSC32K;                         /**< RTC 1 KHZ and 1 Hz clocks source control register [Reset by: PoR, Brown Out Detectors Reset], offset: 0x98 */
  __IO uint32_t OSTIMERr;                          /**< OS Timer control register [Reset by: PoR, Brown Out Detectors Reset], offset: 0x9C, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'OSTIMER' */
       uint8_t RESERVED_6[16];
  __IO uint32_t PDSLEEPCFG0;                       /**< Controls the power to various modules during Low Power modes - DEEP SLEEP, POWER DOWN and DEEP POWER DOWN [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Software Reset], offset: 0xB0 */
       uint8_t RESERVED_7[4];
  __IO uint32_t PDRUNCFG0;                         /**< PDRUNCFG0, offset: 0xB8 */
       uint8_t RESERVED_8[4];
  __O  uint32_t PDRUNCFGSET0;                      /**< Controls the power to various analog blocks [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0xC0 */
       uint8_t RESERVED_9[4];
  __O  uint32_t PDRUNCFGCLR0;                      /**< Controls the power to various analog blocks [Reset by: PoR, Pin Reset, Brown Out Detectors Reset, Deep Power Down Reset, Software Reset], offset: 0xC8 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

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

/*! @name FRO1M - 1 MHz Free Running Oscillator control register */
/*! @{ */

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

/*! @name STATUSCLK - FRO and XTAL status register [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

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

/*! @name AOREG1 - General purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset] */
/*! @{ */

#define PMC_AOREG1_DATA31_0_MASK                 (0xFFFFFFFFU)
#define PMC_AOREG1_DATA31_0_SHIFT                (0U)
/*! DATA31_0 - Write-once general purpose always on domain data storage [Reset by: PoR, Brown Out Detectors Reset] */
#define PMC_AOREG1_DATA31_0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AOREG1_DATA31_0_SHIFT)) & PMC_AOREG1_DATA31_0_MASK)
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

