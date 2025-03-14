/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RSIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file RSIM.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for RSIM
 *
 * CMSIS Peripheral Access Layer for RSIM
 */

#if !defined(RSIM_H_)
#define RSIM_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- RSIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSIM_Peripheral_Access_Layer RSIM Peripheral Access Layer
 * @{
 */

/** RSIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONTROL;                           /**< Radio System Control, offset: 0x0 */
  __IO uint32_t ACTIVE_DELAY;                      /**< Radio Active Early Warning, offset: 0x4 */
  __I  uint32_t MAC_MSB;                           /**< Radio MAC Address, offset: 0x8 */
  __I  uint32_t MAC_LSB;                           /**< Radio MAC Address, offset: 0xC */
  __IO uint32_t MISC;                              /**< Radio Miscellaneous, offset: 0x10 */
       uint8_t RESERVED_0[236];
  __I  uint32_t DSM_TIMER;                         /**< Deep Sleep Timer, offset: 0x100 */
  __IO uint32_t DSM_CONTROL;                       /**< Deep Sleep Timer Control, offset: 0x104 */
  __IO uint32_t DSM_OSC_OFFSET;                    /**< Deep Sleep Wakeup Time Offset, offset: 0x108 */
  __IO uint32_t ANT_SLEEP;                         /**< ANT Link Layer Sleep Time, offset: 0x10C */
  __IO uint32_t ANT_WAKE;                          /**< ANT Link Layer Wake Time, offset: 0x110 */
  __IO uint32_t ZIG_SLEEP;                         /**< 802.15.4 Link Layer Sleep Time, offset: 0x114 */
  __IO uint32_t ZIG_WAKE;                          /**< 802.15.4 Link Layer Wake Time, offset: 0x118 */
  __IO uint32_t GEN_SLEEP;                         /**< Generic FSK Link Layer Sleep Time, offset: 0x11C */
  __IO uint32_t GEN_WAKE;                          /**< Generic FSK Link Layer Wake Time, offset: 0x120 */
  __IO uint32_t RF_OSC_CTRL;                       /**< Radio Oscillator Control, offset: 0x124 */
  __IO uint32_t ANA_TEST;                          /**< Radio Analog Test Registers, offset: 0x128 */
  __IO uint32_t ANA_TRIM;                          /**< Radio Analog Trim Registers, offset: 0x12C */
} RSIM_Type;

/* ----------------------------------------------------------------------------
   -- RSIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSIM_Register_Masks RSIM Register Masks
 * @{
 */

/*! @name CONTROL - Radio System Control */
/*! @{ */

#define RSIM_CONTROL_BLE_RF_OSC_REQ_EN_MASK      (0x1U)
#define RSIM_CONTROL_BLE_RF_OSC_REQ_EN_SHIFT     (0U)
/*! BLE_RF_OSC_REQ_EN - BLE Ref Osc (Sysclk) Request Enable */
#define RSIM_CONTROL_BLE_RF_OSC_REQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_OSC_REQ_EN_SHIFT)) & RSIM_CONTROL_BLE_RF_OSC_REQ_EN_MASK)

#define RSIM_CONTROL_BLE_RF_OSC_REQ_STAT_MASK    (0x2U)
#define RSIM_CONTROL_BLE_RF_OSC_REQ_STAT_SHIFT   (1U)
/*! BLE_RF_OSC_REQ_STAT - BLE Ref Osc (Sysclk) Request Status */
#define RSIM_CONTROL_BLE_RF_OSC_REQ_STAT(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_OSC_REQ_STAT_SHIFT)) & RSIM_CONTROL_BLE_RF_OSC_REQ_STAT_MASK)

#define RSIM_CONTROL_BLE_RF_OSC_REQ_INT_EN_MASK  (0x10U)
#define RSIM_CONTROL_BLE_RF_OSC_REQ_INT_EN_SHIFT (4U)
/*! BLE_RF_OSC_REQ_INT_EN - BLE Ref Osc (Sysclk) Request Interrupt Enable */
#define RSIM_CONTROL_BLE_RF_OSC_REQ_INT_EN(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_OSC_REQ_INT_EN_SHIFT)) & RSIM_CONTROL_BLE_RF_OSC_REQ_INT_EN_MASK)

#define RSIM_CONTROL_BLE_RF_OSC_REQ_INT_MASK     (0x20U)
#define RSIM_CONTROL_BLE_RF_OSC_REQ_INT_SHIFT    (5U)
/*! BLE_RF_OSC_REQ_INT - BLE Ref Osc (Sysclk) Request Interrupt Flag */
#define RSIM_CONTROL_BLE_RF_OSC_REQ_INT(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_OSC_REQ_INT_SHIFT)) & RSIM_CONTROL_BLE_RF_OSC_REQ_INT_MASK)

#define RSIM_CONTROL_RF_OSC_EN_MASK              (0xF00U)
#define RSIM_CONTROL_RF_OSC_EN_SHIFT             (8U)
/*! RF_OSC_EN - RF Ref Osc Enable Select
 *  0b0000..RF Ref Osc will be controlled by the SoC, external pin, or a link layer
 *  0b0001..RF Ref Osc on in Run/Wait
 *  0b0011..RF Ref Osc on in Stop
 *  0b0111..RF Ref Osc on in VLPR/VLPW
 *  0b1111..RF Ref Osc on in VLPS
 */
#define RSIM_CONTROL_RF_OSC_EN(x)                (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RF_OSC_EN_SHIFT)) & RSIM_CONTROL_RF_OSC_EN_MASK)

#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_MASK (0x1000U)
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_SHIFT (12U)
/*! RADIO_GASKET_BYPASS_OVRD_EN - Radio Gasket Bypass Override Enable */
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_SHIFT)) & RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_MASK)

#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_MASK (0x2000U)
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_SHIFT (13U)
/*! RADIO_GASKET_BYPASS_OVRD - Radio Gasket Bypass Override */
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_SHIFT)) & RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_MASK)

#define RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_1_MASK (0x10000U)
#define RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_1_SHIFT (16U)
/*! IPP_OBE_3V_BLE_ACTIVE_1 - IPP_OBE_3V_BLE_ACTIVE_1 */
#define RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_1(x)  (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_1_SHIFT)) & RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_1_MASK)

#define RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_2_MASK (0x20000U)
#define RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_2_SHIFT (17U)
/*! IPP_OBE_3V_BLE_ACTIVE_2 - IPP_OBE_3V_BLE_ACTIVE_2 */
#define RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_2(x)  (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_2_SHIFT)) & RSIM_CONTROL_IPP_OBE_3V_BLE_ACTIVE_2_MASK)

#define RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_EN_MASK (0x40000U)
#define RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_EN_SHIFT (18U)
/*! RADIO_RAM_ACCESS_OVRD_EN - Radio RAM Access Override Enable */
#define RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_EN_SHIFT)) & RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_EN_MASK)

#define RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_MASK  (0x80000U)
#define RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_SHIFT (19U)
/*! RADIO_RAM_ACCESS_OVRD - Radio RAM Access Override */
#define RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_SHIFT)) & RSIM_CONTROL_RADIO_RAM_ACCESS_OVRD_MASK)

#define RSIM_CONTROL_RSIM_DSM_EXIT_MASK          (0x100000U)
#define RSIM_CONTROL_RSIM_DSM_EXIT_SHIFT         (20U)
/*! RSIM_DSM_EXIT - BLE Force Deep Sleep Mode Exit */
#define RSIM_CONTROL_RSIM_DSM_EXIT(x)            (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_DSM_EXIT_SHIFT)) & RSIM_CONTROL_RSIM_DSM_EXIT_MASK)

#define RSIM_CONTROL_RSIM_STOP_ACK_OVRD_EN_MASK  (0x400000U)
#define RSIM_CONTROL_RSIM_STOP_ACK_OVRD_EN_SHIFT (22U)
/*! RSIM_STOP_ACK_OVRD_EN - Stop Acknowledge Override Enable */
#define RSIM_CONTROL_RSIM_STOP_ACK_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_STOP_ACK_OVRD_EN_SHIFT)) & RSIM_CONTROL_RSIM_STOP_ACK_OVRD_EN_MASK)

#define RSIM_CONTROL_RSIM_STOP_ACK_OVRD_MASK     (0x800000U)
#define RSIM_CONTROL_RSIM_STOP_ACK_OVRD_SHIFT    (23U)
/*! RSIM_STOP_ACK_OVRD - Stop Acknowledge Override */
#define RSIM_CONTROL_RSIM_STOP_ACK_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_STOP_ACK_OVRD_SHIFT)) & RSIM_CONTROL_RSIM_STOP_ACK_OVRD_MASK)

#define RSIM_CONTROL_RF_OSC_READY_MASK           (0x1000000U)
#define RSIM_CONTROL_RF_OSC_READY_SHIFT          (24U)
/*! RF_OSC_READY - RF Ref Osc Ready */
#define RSIM_CONTROL_RF_OSC_READY(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RF_OSC_READY_SHIFT)) & RSIM_CONTROL_RF_OSC_READY_MASK)

#define RSIM_CONTROL_RF_OSC_READY_OVRD_EN_MASK   (0x2000000U)
#define RSIM_CONTROL_RF_OSC_READY_OVRD_EN_SHIFT  (25U)
/*! RF_OSC_READY_OVRD_EN - RF Ref Osc Ready Override Enable */
#define RSIM_CONTROL_RF_OSC_READY_OVRD_EN(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RF_OSC_READY_OVRD_EN_SHIFT)) & RSIM_CONTROL_RF_OSC_READY_OVRD_EN_MASK)

#define RSIM_CONTROL_RF_OSC_READY_OVRD_MASK      (0x4000000U)
#define RSIM_CONTROL_RF_OSC_READY_OVRD_SHIFT     (26U)
/*! RF_OSC_READY_OVRD - RF Ref Osc Ready Override */
#define RSIM_CONTROL_RF_OSC_READY_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RF_OSC_READY_OVRD_SHIFT)) & RSIM_CONTROL_RF_OSC_READY_OVRD_MASK)

#define RSIM_CONTROL_BLOCK_SOC_RESETS_MASK       (0x10000000U)
#define RSIM_CONTROL_BLOCK_SOC_RESETS_SHIFT      (28U)
/*! BLOCK_SOC_RESETS - Block SoC Resets of the Radio */
#define RSIM_CONTROL_BLOCK_SOC_RESETS(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLOCK_SOC_RESETS_SHIFT)) & RSIM_CONTROL_BLOCK_SOC_RESETS_MASK)

#define RSIM_CONTROL_BLOCK_RADIO_OUTPUTS_MASK    (0x20000000U)
#define RSIM_CONTROL_BLOCK_RADIO_OUTPUTS_SHIFT   (29U)
/*! BLOCK_RADIO_OUTPUTS - Block Radio Outputs */
#define RSIM_CONTROL_BLOCK_RADIO_OUTPUTS(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLOCK_RADIO_OUTPUTS_SHIFT)) & RSIM_CONTROL_BLOCK_RADIO_OUTPUTS_MASK)

#define RSIM_CONTROL_ALLOW_DFT_RESETS_MASK       (0x40000000U)
#define RSIM_CONTROL_ALLOW_DFT_RESETS_SHIFT      (30U)
/*! ALLOW_DFT_RESETS - Allow the DFT Reset Pin to Reset the Radio */
#define RSIM_CONTROL_ALLOW_DFT_RESETS(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_ALLOW_DFT_RESETS_SHIFT)) & RSIM_CONTROL_ALLOW_DFT_RESETS_MASK)

#define RSIM_CONTROL_RADIO_RESET_BIT_MASK        (0x80000000U)
#define RSIM_CONTROL_RADIO_RESET_BIT_SHIFT       (31U)
/*! RADIO_RESET_BIT - Software Reset for the Radio */
#define RSIM_CONTROL_RADIO_RESET_BIT(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_RESET_BIT_SHIFT)) & RSIM_CONTROL_RADIO_RESET_BIT_MASK)
/*! @} */

/*! @name ACTIVE_DELAY - Radio Active Early Warning */
/*! @{ */

#define RSIM_ACTIVE_DELAY_BLE_FINE_DELAY_MASK    (0x3FU)
#define RSIM_ACTIVE_DELAY_BLE_FINE_DELAY_SHIFT   (0U)
/*! BLE_FINE_DELAY - BLE Active Fine Delay */
#define RSIM_ACTIVE_DELAY_BLE_FINE_DELAY(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_ACTIVE_DELAY_BLE_FINE_DELAY_SHIFT)) & RSIM_ACTIVE_DELAY_BLE_FINE_DELAY_MASK)

#define RSIM_ACTIVE_DELAY_BLE_COARSE_DELAY_MASK  (0xF0000U)
#define RSIM_ACTIVE_DELAY_BLE_COARSE_DELAY_SHIFT (16U)
/*! BLE_COARSE_DELAY - BLE Active Coarse Delay */
#define RSIM_ACTIVE_DELAY_BLE_COARSE_DELAY(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_ACTIVE_DELAY_BLE_COARSE_DELAY_SHIFT)) & RSIM_ACTIVE_DELAY_BLE_COARSE_DELAY_MASK)
/*! @} */

/*! @name MAC_MSB - Radio MAC Address */
/*! @{ */

#define RSIM_MAC_MSB_MAC_ADDR_MSB_MASK           (0xFFU)
#define RSIM_MAC_MSB_MAC_ADDR_MSB_SHIFT          (0U)
/*! MAC_ADDR_MSB - Radio MAC Address MSB */
#define RSIM_MAC_MSB_MAC_ADDR_MSB(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_MAC_MSB_MAC_ADDR_MSB_SHIFT)) & RSIM_MAC_MSB_MAC_ADDR_MSB_MASK)
/*! @} */

/*! @name MAC_LSB - Radio MAC Address */
/*! @{ */

#define RSIM_MAC_LSB_MAC_ADDR_LSB_MASK           (0xFFFFFFFFU)
#define RSIM_MAC_LSB_MAC_ADDR_LSB_SHIFT          (0U)
/*! MAC_ADDR_LSB - Radio MAC Address LSB */
#define RSIM_MAC_LSB_MAC_ADDR_LSB(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_MAC_LSB_MAC_ADDR_LSB_SHIFT)) & RSIM_MAC_LSB_MAC_ADDR_LSB_MASK)
/*! @} */

/*! @name MISC - Radio Miscellaneous */
/*! @{ */

#define RSIM_MISC_ANALOG_TEST_EN_MASK            (0x1FU)
#define RSIM_MISC_ANALOG_TEST_EN_SHIFT           (0U)
/*! ANALOG_TEST_EN - RSIM Analog Test Mux Enables */
#define RSIM_MISC_ANALOG_TEST_EN(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_MISC_ANALOG_TEST_EN_SHIFT)) & RSIM_MISC_ANALOG_TEST_EN_MASK)

#define RSIM_MISC_RADIO_VERSION_MASK             (0xFF000000U)
#define RSIM_MISC_RADIO_VERSION_SHIFT            (24U)
/*! RADIO_VERSION - Radio Version ID number */
#define RSIM_MISC_RADIO_VERSION(x)               (((uint32_t)(((uint32_t)(x)) << RSIM_MISC_RADIO_VERSION_SHIFT)) & RSIM_MISC_RADIO_VERSION_MASK)
/*! @} */

/*! @name DSM_TIMER - Deep Sleep Timer */
/*! @{ */

#define RSIM_DSM_TIMER_DSM_TIMER_MASK            (0xFFFFFFU)
#define RSIM_DSM_TIMER_DSM_TIMER_SHIFT           (0U)
/*! DSM_TIMER - Deep Sleep Mode Timer */
#define RSIM_DSM_TIMER_DSM_TIMER(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_TIMER_DSM_TIMER_SHIFT)) & RSIM_DSM_TIMER_DSM_TIMER_MASK)
/*! @} */

/*! @name DSM_CONTROL - Deep Sleep Timer Control */
/*! @{ */

#define RSIM_DSM_CONTROL_DSM_ANT_READY_MASK      (0x1U)
#define RSIM_DSM_CONTROL_DSM_ANT_READY_SHIFT     (0U)
/*! DSM_ANT_READY - ANT Ready for Deep Sleep Mode */
#define RSIM_DSM_CONTROL_DSM_ANT_READY(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_ANT_READY_SHIFT)) & RSIM_DSM_CONTROL_DSM_ANT_READY_MASK)

#define RSIM_DSM_CONTROL_ANT_DEEP_SLEEP_STATUS_MASK (0x2U)
#define RSIM_DSM_CONTROL_ANT_DEEP_SLEEP_STATUS_SHIFT (1U)
/*! ANT_DEEP_SLEEP_STATUS - ANT Link Layer Deep Sleep Mode Status */
#define RSIM_DSM_CONTROL_ANT_DEEP_SLEEP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ANT_DEEP_SLEEP_STATUS_SHIFT)) & RSIM_DSM_CONTROL_ANT_DEEP_SLEEP_STATUS_MASK)

#define RSIM_DSM_CONTROL_DSM_ANT_FINISHED_MASK   (0x4U)
#define RSIM_DSM_CONTROL_DSM_ANT_FINISHED_SHIFT  (2U)
/*! DSM_ANT_FINISHED - ANT Deep Sleep Time Finished */
#define RSIM_DSM_CONTROL_DSM_ANT_FINISHED(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_ANT_FINISHED_SHIFT)) & RSIM_DSM_CONTROL_DSM_ANT_FINISHED_MASK)

#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQUEST_EN_MASK (0x8U)
#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQUEST_EN_SHIFT (3U)
/*! ANT_SYSCLK_REQUEST_EN - Enable ANT Link Layer to Request RF OSC */
#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQUEST_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ANT_SYSCLK_REQUEST_EN_SHIFT)) & RSIM_DSM_CONTROL_ANT_SYSCLK_REQUEST_EN_MASK)

#define RSIM_DSM_CONTROL_ANT_SLEEP_REQUEST_MASK  (0x10U)
#define RSIM_DSM_CONTROL_ANT_SLEEP_REQUEST_SHIFT (4U)
/*! ANT_SLEEP_REQUEST - ANT Link Layer Deep Sleep Requested */
#define RSIM_DSM_CONTROL_ANT_SLEEP_REQUEST(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ANT_SLEEP_REQUEST_SHIFT)) & RSIM_DSM_CONTROL_ANT_SLEEP_REQUEST_MASK)

#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_MASK     (0x20U)
#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_SHIFT    (5U)
/*! ANT_SYSCLK_REQ - ANT Link Layer RF OSC Request Status */
#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQ(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_SHIFT)) & RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_MASK)

#define RSIM_DSM_CONTROL_ANT_SYSCLK_INTERRUPT_EN_MASK (0x40U)
#define RSIM_DSM_CONTROL_ANT_SYSCLK_INTERRUPT_EN_SHIFT (6U)
/*! ANT_SYSCLK_INTERRUPT_EN - ANT Link Layer RF OSC Request Interrupt Enable */
#define RSIM_DSM_CONTROL_ANT_SYSCLK_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ANT_SYSCLK_INTERRUPT_EN_SHIFT)) & RSIM_DSM_CONTROL_ANT_SYSCLK_INTERRUPT_EN_MASK)

#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_INT_MASK (0x80U)
#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_INT_SHIFT (7U)
/*! ANT_SYSCLK_REQ_INT - Interrupt Flag from an ANT Link Layer RF OSC Request */
#define RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_INT(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_INT_SHIFT)) & RSIM_DSM_CONTROL_ANT_SYSCLK_REQ_INT_MASK)

#define RSIM_DSM_CONTROL_DSM_GEN_READY_MASK      (0x100U)
#define RSIM_DSM_CONTROL_DSM_GEN_READY_SHIFT     (8U)
/*! DSM_GEN_READY - Generic FSK Ready for Deep Sleep Mode */
#define RSIM_DSM_CONTROL_DSM_GEN_READY(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_GEN_READY_SHIFT)) & RSIM_DSM_CONTROL_DSM_GEN_READY_MASK)

#define RSIM_DSM_CONTROL_GEN_DEEP_SLEEP_STATUS_MASK (0x200U)
#define RSIM_DSM_CONTROL_GEN_DEEP_SLEEP_STATUS_SHIFT (9U)
/*! GEN_DEEP_SLEEP_STATUS - Generic FSK Link Layer Deep Sleep Mode Status */
#define RSIM_DSM_CONTROL_GEN_DEEP_SLEEP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_GEN_DEEP_SLEEP_STATUS_SHIFT)) & RSIM_DSM_CONTROL_GEN_DEEP_SLEEP_STATUS_MASK)

#define RSIM_DSM_CONTROL_DSM_GEN_FINISHED_MASK   (0x400U)
#define RSIM_DSM_CONTROL_DSM_GEN_FINISHED_SHIFT  (10U)
/*! DSM_GEN_FINISHED - Generic FSK Deep Sleep Time Finished */
#define RSIM_DSM_CONTROL_DSM_GEN_FINISHED(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_GEN_FINISHED_SHIFT)) & RSIM_DSM_CONTROL_DSM_GEN_FINISHED_MASK)

#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQUEST_EN_MASK (0x800U)
#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQUEST_EN_SHIFT (11U)
/*! GEN_SYSCLK_REQUEST_EN - Enable Generic FSK Link Layer to Request RF OSC */
#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQUEST_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_GEN_SYSCLK_REQUEST_EN_SHIFT)) & RSIM_DSM_CONTROL_GEN_SYSCLK_REQUEST_EN_MASK)

#define RSIM_DSM_CONTROL_GEN_SLEEP_REQUEST_MASK  (0x1000U)
#define RSIM_DSM_CONTROL_GEN_SLEEP_REQUEST_SHIFT (12U)
/*! GEN_SLEEP_REQUEST - Generic FSK Link Layer Deep Sleep Requested */
#define RSIM_DSM_CONTROL_GEN_SLEEP_REQUEST(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_GEN_SLEEP_REQUEST_SHIFT)) & RSIM_DSM_CONTROL_GEN_SLEEP_REQUEST_MASK)

#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_MASK     (0x2000U)
#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_SHIFT    (13U)
/*! GEN_SYSCLK_REQ - Generic FSK Link Layer RF OSC Request Status */
#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQ(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_SHIFT)) & RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_MASK)

#define RSIM_DSM_CONTROL_GEN_SYSCLK_INTERRUPT_EN_MASK (0x4000U)
#define RSIM_DSM_CONTROL_GEN_SYSCLK_INTERRUPT_EN_SHIFT (14U)
/*! GEN_SYSCLK_INTERRUPT_EN - Generic FSK Link Layer RF OSC Request Interrupt Enable */
#define RSIM_DSM_CONTROL_GEN_SYSCLK_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_GEN_SYSCLK_INTERRUPT_EN_SHIFT)) & RSIM_DSM_CONTROL_GEN_SYSCLK_INTERRUPT_EN_MASK)

#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_INT_MASK (0x8000U)
#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_INT_SHIFT (15U)
/*! GEN_SYSCLK_REQ_INT - Interrupt Flag from an Generic FSK Link Layer RF OSC Request */
#define RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_INT(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_INT_SHIFT)) & RSIM_DSM_CONTROL_GEN_SYSCLK_REQ_INT_MASK)

#define RSIM_DSM_CONTROL_DSM_ZIG_READY_MASK      (0x10000U)
#define RSIM_DSM_CONTROL_DSM_ZIG_READY_SHIFT     (16U)
/*! DSM_ZIG_READY - 802.15.4 Ready for Deep Sleep Mode */
#define RSIM_DSM_CONTROL_DSM_ZIG_READY(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_ZIG_READY_SHIFT)) & RSIM_DSM_CONTROL_DSM_ZIG_READY_MASK)

#define RSIM_DSM_CONTROL_ZIG_DEEP_SLEEP_STATUS_MASK (0x20000U)
#define RSIM_DSM_CONTROL_ZIG_DEEP_SLEEP_STATUS_SHIFT (17U)
/*! ZIG_DEEP_SLEEP_STATUS - 802.15.4 Link Layer Deep Sleep Mode Status */
#define RSIM_DSM_CONTROL_ZIG_DEEP_SLEEP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ZIG_DEEP_SLEEP_STATUS_SHIFT)) & RSIM_DSM_CONTROL_ZIG_DEEP_SLEEP_STATUS_MASK)

#define RSIM_DSM_CONTROL_DSM_ZIG_FINISHED_MASK   (0x40000U)
#define RSIM_DSM_CONTROL_DSM_ZIG_FINISHED_SHIFT  (18U)
/*! DSM_ZIG_FINISHED - 802.15.4 Deep Sleep Time Finished */
#define RSIM_DSM_CONTROL_DSM_ZIG_FINISHED(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_ZIG_FINISHED_SHIFT)) & RSIM_DSM_CONTROL_DSM_ZIG_FINISHED_MASK)

#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQUEST_EN_MASK (0x80000U)
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQUEST_EN_SHIFT (19U)
/*! ZIG_SYSCLK_REQUEST_EN - Enable 802.15.4 Link Layer to Request RF OSC */
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQUEST_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ZIG_SYSCLK_REQUEST_EN_SHIFT)) & RSIM_DSM_CONTROL_ZIG_SYSCLK_REQUEST_EN_MASK)

#define RSIM_DSM_CONTROL_ZIG_SLEEP_REQUEST_MASK  (0x100000U)
#define RSIM_DSM_CONTROL_ZIG_SLEEP_REQUEST_SHIFT (20U)
/*! ZIG_SLEEP_REQUEST - 802.15.4 Link Layer Deep Sleep Requested */
#define RSIM_DSM_CONTROL_ZIG_SLEEP_REQUEST(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ZIG_SLEEP_REQUEST_SHIFT)) & RSIM_DSM_CONTROL_ZIG_SLEEP_REQUEST_MASK)

#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_MASK     (0x200000U)
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_SHIFT    (21U)
/*! ZIG_SYSCLK_REQ - 802.15.4 Link Layer RF OSC Request Status */
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_SHIFT)) & RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_MASK)

#define RSIM_DSM_CONTROL_ZIG_SYSCLK_INTERRUPT_EN_MASK (0x400000U)
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_INTERRUPT_EN_SHIFT (22U)
/*! ZIG_SYSCLK_INTERRUPT_EN - 802.15.4 Link Layer RF OSC Request Interrupt Enable */
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ZIG_SYSCLK_INTERRUPT_EN_SHIFT)) & RSIM_DSM_CONTROL_ZIG_SYSCLK_INTERRUPT_EN_MASK)

#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_INT_MASK (0x800000U)
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_INT_SHIFT (23U)
/*! ZIG_SYSCLK_REQ_INT - Interrupt Flag from an 802.15.4 Link Layer RF OSC Request */
#define RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_INT(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_INT_SHIFT)) & RSIM_DSM_CONTROL_ZIG_SYSCLK_REQ_INT_MASK)

#define RSIM_DSM_CONTROL_DSM_TIMER_CLR_MASK      (0x8000000U)
#define RSIM_DSM_CONTROL_DSM_TIMER_CLR_SHIFT     (27U)
/*! DSM_TIMER_CLR - Deep Sleep Mode Timer Clear */
#define RSIM_DSM_CONTROL_DSM_TIMER_CLR(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_TIMER_CLR_SHIFT)) & RSIM_DSM_CONTROL_DSM_TIMER_CLR_MASK)

#define RSIM_DSM_CONTROL_DSM_TIMER_EN_MASK       (0x80000000U)
#define RSIM_DSM_CONTROL_DSM_TIMER_EN_SHIFT      (31U)
/*! DSM_TIMER_EN - Deep Sleep Mode Timer Enable */
#define RSIM_DSM_CONTROL_DSM_TIMER_EN(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_TIMER_EN_SHIFT)) & RSIM_DSM_CONTROL_DSM_TIMER_EN_MASK)
/*! @} */

/*! @name DSM_OSC_OFFSET - Deep Sleep Wakeup Time Offset */
/*! @{ */

#define RSIM_DSM_OSC_OFFSET_DSM_OSC_STABILIZE_TIME_MASK (0x3FFU)
#define RSIM_DSM_OSC_OFFSET_DSM_OSC_STABILIZE_TIME_SHIFT (0U)
/*! DSM_OSC_STABILIZE_TIME - Deep Sleep Wakeup RF OSC Stabilize Time */
#define RSIM_DSM_OSC_OFFSET_DSM_OSC_STABILIZE_TIME(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_OSC_OFFSET_DSM_OSC_STABILIZE_TIME_SHIFT)) & RSIM_DSM_OSC_OFFSET_DSM_OSC_STABILIZE_TIME_MASK)
/*! @} */

/*! @name ANT_SLEEP - ANT Link Layer Sleep Time */
/*! @{ */

#define RSIM_ANT_SLEEP_ANT_SLEEP_TIME_MASK       (0xFFFFFFU)
#define RSIM_ANT_SLEEP_ANT_SLEEP_TIME_SHIFT      (0U)
/*! ANT_SLEEP_TIME - ANT Link Layer Sleep Time */
#define RSIM_ANT_SLEEP_ANT_SLEEP_TIME(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANT_SLEEP_ANT_SLEEP_TIME_SHIFT)) & RSIM_ANT_SLEEP_ANT_SLEEP_TIME_MASK)
/*! @} */

/*! @name ANT_WAKE - ANT Link Layer Wake Time */
/*! @{ */

#define RSIM_ANT_WAKE_ANT_WAKE_TIME_MASK         (0xFFFFFFU)
#define RSIM_ANT_WAKE_ANT_WAKE_TIME_SHIFT        (0U)
/*! ANT_WAKE_TIME - ANT Link Layer Wake Time */
#define RSIM_ANT_WAKE_ANT_WAKE_TIME(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_ANT_WAKE_ANT_WAKE_TIME_SHIFT)) & RSIM_ANT_WAKE_ANT_WAKE_TIME_MASK)
/*! @} */

/*! @name ZIG_SLEEP - 802.15.4 Link Layer Sleep Time */
/*! @{ */

#define RSIM_ZIG_SLEEP_ZIG_SLEEP_TIME_MASK       (0xFFFFFFU)
#define RSIM_ZIG_SLEEP_ZIG_SLEEP_TIME_SHIFT      (0U)
/*! ZIG_SLEEP_TIME - 802.15.4 Link Layer Sleep Time */
#define RSIM_ZIG_SLEEP_ZIG_SLEEP_TIME(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ZIG_SLEEP_ZIG_SLEEP_TIME_SHIFT)) & RSIM_ZIG_SLEEP_ZIG_SLEEP_TIME_MASK)
/*! @} */

/*! @name ZIG_WAKE - 802.15.4 Link Layer Wake Time */
/*! @{ */

#define RSIM_ZIG_WAKE_ZIG_WAKE_TIME_MASK         (0xFFFFFFU)
#define RSIM_ZIG_WAKE_ZIG_WAKE_TIME_SHIFT        (0U)
/*! ZIG_WAKE_TIME - 802.15.4 Link Layer Wake Time */
#define RSIM_ZIG_WAKE_ZIG_WAKE_TIME(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_ZIG_WAKE_ZIG_WAKE_TIME_SHIFT)) & RSIM_ZIG_WAKE_ZIG_WAKE_TIME_MASK)
/*! @} */

/*! @name GEN_SLEEP - Generic FSK Link Layer Sleep Time */
/*! @{ */

#define RSIM_GEN_SLEEP_GEN_SLEEP_TIME_MASK       (0xFFFFFFU)
#define RSIM_GEN_SLEEP_GEN_SLEEP_TIME_SHIFT      (0U)
/*! GEN_SLEEP_TIME - Generic FSK Link Layer Sleep Time */
#define RSIM_GEN_SLEEP_GEN_SLEEP_TIME(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_GEN_SLEEP_GEN_SLEEP_TIME_SHIFT)) & RSIM_GEN_SLEEP_GEN_SLEEP_TIME_MASK)
/*! @} */

/*! @name GEN_WAKE - Generic FSK Link Layer Wake Time */
/*! @{ */

#define RSIM_GEN_WAKE_GEN_WAKE_TIME_MASK         (0xFFFFFFU)
#define RSIM_GEN_WAKE_GEN_WAKE_TIME_SHIFT        (0U)
/*! GEN_WAKE_TIME - Generic FSK Link Layer Wake Time */
#define RSIM_GEN_WAKE_GEN_WAKE_TIME(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_GEN_WAKE_GEN_WAKE_TIME_SHIFT)) & RSIM_GEN_WAKE_GEN_WAKE_TIME_MASK)
/*! @} */

/*! @name RF_OSC_CTRL - Radio Oscillator Control */
/*! @{ */

#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL_MASK (0x3U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL_SHIFT (0U)
/*! BB_XTAL_ALC_COUNT_SEL - rmap_bb_xtal_alc_count_sel_hv[1:0] */
#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_ON_MASK     (0x4U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_ON_SHIFT    (2U)
/*! BB_XTAL_ALC_ON - rmap_bb_xtal_alc_on_hv */
#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_ON(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_ALC_ON_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_ALC_ON_MASK)

#define RSIM_RF_OSC_CTRL_RF_OSC_BYPASS_EN_MASK   (0x8U)
#define RSIM_RF_OSC_CTRL_RF_OSC_BYPASS_EN_SHIFT  (3U)
/*! RF_OSC_BYPASS_EN - RF Ref Osc Bypass Enable */
#define RSIM_RF_OSC_CTRL_RF_OSC_BYPASS_EN(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RF_OSC_BYPASS_EN_SHIFT)) & RSIM_RF_OSC_CTRL_RF_OSC_BYPASS_EN_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_COMP_BIAS_MASK  (0x1F0U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_COMP_BIAS_SHIFT (4U)
/*! BB_XTAL_COMP_BIAS - rmap_bb_xtal_comp_bias_hv[4:0] */
#define RSIM_RF_OSC_CTRL_BB_XTAL_COMP_BIAS(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_COMP_BIAS_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_COMP_BIAS_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_DC_COUP_MODE_EN_MASK (0x200U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_DC_COUP_MODE_EN_SHIFT (9U)
/*! BB_XTAL_DC_COUP_MODE_EN - rmap_bb_xtal_dc_coup_mode_en_hv */
#define RSIM_RF_OSC_CTRL_BB_XTAL_DC_COUP_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_DC_COUP_MODE_EN_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_DC_COUP_MODE_EN_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_DIAGSEL_MASK    (0x400U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_DIAGSEL_SHIFT   (10U)
/*! BB_XTAL_DIAGSEL - rmap_bb_xtal_diagsel_hv */
#define RSIM_RF_OSC_CTRL_BB_XTAL_DIAGSEL(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_DIAGSEL_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_DIAGSEL_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_DIG_CLK_ON_MASK (0x800U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_DIG_CLK_ON_SHIFT (11U)
/*! BB_XTAL_DIG_CLK_ON - rmap_bb_xtal_dig_clk_on_hv */
#define RSIM_RF_OSC_CTRL_BB_XTAL_DIG_CLK_ON(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_DIG_CLK_ON_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_DIG_CLK_ON_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_GM_MASK         (0x1F000U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_GM_SHIFT        (12U)
/*! BB_XTAL_GM - rmap_bb_xtal_gm_hv[4:0] */
#define RSIM_RF_OSC_CTRL_BB_XTAL_GM(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_GM_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_GM_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_MASK    (0x20000U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_SHIFT   (17U)
/*! BB_XTAL_ON_OVRD - rmap_bb_xtal_on_ovrd_hv */
#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON_MASK (0x40000U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON_SHIFT (18U)
/*! BB_XTAL_ON_OVRD_ON - rmap_bb_xtal_on_ovrd_on_hv */
#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL_MASK (0x300000U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL_SHIFT (20U)
/*! BB_XTAL_READY_COUNT_SEL - rmap_bb_xtal_ready_count_sel_hv[1:0] */
#define RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL_MASK)

#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_RF_EN_SEL_MASK (0x8000000U)
#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_RF_EN_SEL_SHIFT (27U)
/*! RADIO_EXT_OSC_RF_EN_SEL - Radio External Request for RF OSC Select */
#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_RF_EN_SEL(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_RF_EN_SEL_SHIFT)) & RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_RF_EN_SEL_MASK)

#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_MASK (0x10000000U)
#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_SHIFT (28U)
/*! RADIO_EXT_OSC_OVRD - Radio External Request for RF OSC Override */
#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_SHIFT)) & RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_MASK)

#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_EN_MASK (0x20000000U)
#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_EN_SHIFT (29U)
/*! RADIO_EXT_OSC_OVRD_EN - Radio External Request for RF OSC Override Enable */
#define RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_EN_SHIFT)) & RSIM_RF_OSC_CTRL_RADIO_EXT_OSC_OVRD_EN_MASK)

#define RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_MASK (0x40000000U)
#define RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_SHIFT (30U)
/*! RADIO_RF_ABORT_OVRD - Radio RF Abort Override */
#define RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD(x)  (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_SHIFT)) & RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_MASK)

#define RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_EN_MASK (0x80000000U)
#define RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_EN_SHIFT (31U)
/*! RADIO_RF_ABORT_OVRD_EN - Radio RF Abort Override Enable */
#define RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_EN_SHIFT)) & RSIM_RF_OSC_CTRL_RADIO_RF_ABORT_OVRD_EN_MASK)
/*! @} */

/*! @name ANA_TEST - Radio Analog Test Registers */
/*! @{ */

#define RSIM_ANA_TEST_BB_LDO_LS_BYP_MASK         (0x1U)
#define RSIM_ANA_TEST_BB_LDO_LS_BYP_SHIFT        (0U)
/*! BB_LDO_LS_BYP - rmap_bb_ldo_ls_byp_hv */
#define RSIM_ANA_TEST_BB_LDO_LS_BYP(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BB_LDO_LS_BYP_SHIFT)) & RSIM_ANA_TEST_BB_LDO_LS_BYP_MASK)

#define RSIM_ANA_TEST_BB_LDO_LS_DIAGSEL_MASK     (0x2U)
#define RSIM_ANA_TEST_BB_LDO_LS_DIAGSEL_SHIFT    (1U)
/*! BB_LDO_LS_DIAGSEL - rmap_bb_ldo_ls_diagsel_hv */
#define RSIM_ANA_TEST_BB_LDO_LS_DIAGSEL(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BB_LDO_LS_DIAGSEL_SHIFT)) & RSIM_ANA_TEST_BB_LDO_LS_DIAGSEL_MASK)

#define RSIM_ANA_TEST_BB_LDO_XO_BYP_ON_MASK      (0x4U)
#define RSIM_ANA_TEST_BB_LDO_XO_BYP_ON_SHIFT     (2U)
/*! BB_LDO_XO_BYP_ON - rmap_bb_ldo_xo_byp_on_hv */
#define RSIM_ANA_TEST_BB_LDO_XO_BYP_ON(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BB_LDO_XO_BYP_ON_SHIFT)) & RSIM_ANA_TEST_BB_LDO_XO_BYP_ON_MASK)

#define RSIM_ANA_TEST_BB_LDO_XO_DIAGSEL_MASK     (0x8U)
#define RSIM_ANA_TEST_BB_LDO_XO_DIAGSEL_SHIFT    (3U)
/*! BB_LDO_XO_DIAGSEL - rmap_bb_ldo_xo_diagsel_hv */
#define RSIM_ANA_TEST_BB_LDO_XO_DIAGSEL(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BB_LDO_XO_DIAGSEL_SHIFT)) & RSIM_ANA_TEST_BB_LDO_XO_DIAGSEL_MASK)

#define RSIM_ANA_TEST_BB_XTAL_TEST_MASK          (0x10U)
#define RSIM_ANA_TEST_BB_XTAL_TEST_SHIFT         (4U)
/*! BB_XTAL_TEST - rmap_bb_xtal_test_en_hv */
#define RSIM_ANA_TEST_BB_XTAL_TEST(x)            (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BB_XTAL_TEST_SHIFT)) & RSIM_ANA_TEST_BB_XTAL_TEST_MASK)

#define RSIM_ANA_TEST_BG_DIAGBUF_MASK            (0x20U)
#define RSIM_ANA_TEST_BG_DIAGBUF_SHIFT           (5U)
/*! BG_DIAGBUF - rmap_bg_diagbuf_hv */
#define RSIM_ANA_TEST_BG_DIAGBUF(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BG_DIAGBUF_SHIFT)) & RSIM_ANA_TEST_BG_DIAGBUF_MASK)

#define RSIM_ANA_TEST_BG_DIAGSEL_MASK            (0x40U)
#define RSIM_ANA_TEST_BG_DIAGSEL_SHIFT           (6U)
/*! BG_DIAGSEL - rmap_bg_diagsel_hv */
#define RSIM_ANA_TEST_BG_DIAGSEL(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BG_DIAGSEL_SHIFT)) & RSIM_ANA_TEST_BG_DIAGSEL_MASK)

#define RSIM_ANA_TEST_BG_STARTUPFORCE_MASK       (0x80U)
#define RSIM_ANA_TEST_BG_STARTUPFORCE_SHIFT      (7U)
/*! BG_STARTUPFORCE - rmap_bg_startupforce_hv */
#define RSIM_ANA_TEST_BG_STARTUPFORCE(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_BG_STARTUPFORCE_SHIFT)) & RSIM_ANA_TEST_BG_STARTUPFORCE_MASK)

#define RSIM_ANA_TEST_DIAG_1234_ON_MASK          (0x100U)
#define RSIM_ANA_TEST_DIAG_1234_ON_SHIFT         (8U)
/*! DIAG_1234_ON - rmap_diag_1234_on_hv */
#define RSIM_ANA_TEST_DIAG_1234_ON(x)            (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_DIAG_1234_ON_SHIFT)) & RSIM_ANA_TEST_DIAG_1234_ON_MASK)

#define RSIM_ANA_TEST_DIAG2SOCADC_DEC_MASK       (0x600U)
#define RSIM_ANA_TEST_DIAG2SOCADC_DEC_SHIFT      (9U)
/*! DIAG2SOCADC_DEC - rmap_diag2socadc_dec_hv[1:0] */
#define RSIM_ANA_TEST_DIAG2SOCADC_DEC(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_DIAG2SOCADC_DEC_SHIFT)) & RSIM_ANA_TEST_DIAG2SOCADC_DEC_MASK)

#define RSIM_ANA_TEST_DIAG2SOCADC_DEC_ON_MASK    (0x800U)
#define RSIM_ANA_TEST_DIAG2SOCADC_DEC_ON_SHIFT   (11U)
/*! DIAG2SOCADC_DEC_ON - rmap_diag2socadc_dec_on_hv */
#define RSIM_ANA_TEST_DIAG2SOCADC_DEC_ON(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_DIAG2SOCADC_DEC_ON_SHIFT)) & RSIM_ANA_TEST_DIAG2SOCADC_DEC_ON_MASK)

#define RSIM_ANA_TEST_DIAGCODE_MASK              (0x7000U)
#define RSIM_ANA_TEST_DIAGCODE_SHIFT             (12U)
/*! DIAGCODE - rmap_diagcode_hv[2:0] */
#define RSIM_ANA_TEST_DIAGCODE(x)                (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_DIAGCODE_SHIFT)) & RSIM_ANA_TEST_DIAGCODE_MASK)
/*! @} */

/*! @name ANA_TRIM - Radio Analog Trim Registers */
/*! @{ */

#define RSIM_ANA_TRIM_BB_LDO_LS_SPARE_MASK       (0x3U)
#define RSIM_ANA_TRIM_BB_LDO_LS_SPARE_SHIFT      (0U)
/*! BB_LDO_LS_SPARE - rmap_bb_ldo_ls_spare_hv[1:0] */
#define RSIM_ANA_TRIM_BB_LDO_LS_SPARE(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_LS_SPARE_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_LS_SPARE_MASK)

#define RSIM_ANA_TRIM_BB_LDO_LS_TRIM_MASK        (0x38U)
#define RSIM_ANA_TRIM_BB_LDO_LS_TRIM_SHIFT       (3U)
/*! BB_LDO_LS_TRIM - rmap_bb_ldo_ls_trim_hv[2:0] */
#define RSIM_ANA_TRIM_BB_LDO_LS_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_LS_TRIM_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_LS_TRIM_MASK)

#define RSIM_ANA_TRIM_BB_LDO_XO_SPARE_MASK       (0xC0U)
#define RSIM_ANA_TRIM_BB_LDO_XO_SPARE_SHIFT      (6U)
/*! BB_LDO_XO_SPARE - rmap_bb_ldo_xo_spare_hv[1:0] */
#define RSIM_ANA_TRIM_BB_LDO_XO_SPARE(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_XO_SPARE_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_XO_SPARE_MASK)

#define RSIM_ANA_TRIM_BB_LDO_XO_TRIM_MASK        (0x700U)
#define RSIM_ANA_TRIM_BB_LDO_XO_TRIM_SHIFT       (8U)
/*! BB_LDO_XO_TRIM - rmap_bb_ldo_xo_trim_hv[2:0] */
#define RSIM_ANA_TRIM_BB_LDO_XO_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_XO_TRIM_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_XO_TRIM_MASK)

#define RSIM_ANA_TRIM_BB_XTAL_SPARE_MASK         (0xF800U)
#define RSIM_ANA_TRIM_BB_XTAL_SPARE_SHIFT        (11U)
/*! BB_XTAL_SPARE - rmap_bb_xtal_spare_hv[4:0] */
#define RSIM_ANA_TRIM_BB_XTAL_SPARE(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_XTAL_SPARE_SHIFT)) & RSIM_ANA_TRIM_BB_XTAL_SPARE_MASK)

#define RSIM_ANA_TRIM_BB_XTAL_TRIM_MASK          (0xFF0000U)
#define RSIM_ANA_TRIM_BB_XTAL_TRIM_SHIFT         (16U)
/*! BB_XTAL_TRIM - rmap_bb_xtal_trim_hv[7:0] */
#define RSIM_ANA_TRIM_BB_XTAL_TRIM(x)            (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_XTAL_TRIM_SHIFT)) & RSIM_ANA_TRIM_BB_XTAL_TRIM_MASK)

#define RSIM_ANA_TRIM_BG_1V_TRIM_MASK            (0xF000000U)
#define RSIM_ANA_TRIM_BG_1V_TRIM_SHIFT           (24U)
/*! BG_1V_TRIM - rmap_bg_1v_trim_hv[3:0] */
#define RSIM_ANA_TRIM_BG_1V_TRIM(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BG_1V_TRIM_SHIFT)) & RSIM_ANA_TRIM_BG_1V_TRIM_MASK)

#define RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM_MASK      (0xF0000000U)
#define RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM_SHIFT     (28U)
/*! BG_IBIAS_5U_TRIM - rmap_bg_ibias_5u_trim_hv[3:0] */
#define RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM_SHIFT)) & RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSIM_Register_Masks */


/*!
 * @}
 */ /* end of group RSIM_Peripheral_Access_Layer */


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


#endif  /* RSIM_H_ */

