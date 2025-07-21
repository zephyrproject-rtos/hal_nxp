/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RSIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RSIM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSIM
 *
 * CMSIS Peripheral Access Layer for RSIM
 */

#if !defined(PERI_RSIM_H_)
#define PERI_RSIM_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
       uint8_t RESERVED_0[12];
  __IO uint32_t MISC;                              /**< Radio Miscellaneous, offset: 0x10 */
  __IO uint32_t POWER;                             /**< RSIM Power Control, offset: 0x14 */
  __IO uint32_t SW_CONFIG;                         /**< Radio Software Configuration, offset: 0x18 */
       uint8_t RESERVED_1[228];
  __I  uint32_t DSM_TIMER;                         /**< Deep Sleep Timer, offset: 0x100 */
  __IO uint32_t DSM_CONTROL;                       /**< Deep Sleep Timer Control, offset: 0x104 */
  __IO uint32_t DSM_WAKEUP;                        /**< Deep Sleep Wakeup Sequence, offset: 0x108 */
  __I  uint32_t WOR_DURATION;                      /**< WOR Deep Sleep Duration, offset: 0x10C */
  __IO uint32_t WOR_WAKE;                          /**< WOR Deep Sleep Wake Time, offset: 0x110 */
       uint8_t RESERVED_2[8];
  __IO uint32_t MAN_SLEEP;                         /**< MAN Deep Sleep Time, offset: 0x11C */
  __IO uint32_t MAN_WAKE;                          /**< MAN Deep Sleep Wake Time, offset: 0x120 */
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

#define RSIM_CONTROL_BLE_RF_POWER_REQ_EN_MASK    (0x1U)
#define RSIM_CONTROL_BLE_RF_POWER_REQ_EN_SHIFT   (0U)
/*! BLE_RF_POWER_REQ_EN - BLE RF Power Request Enable */
#define RSIM_CONTROL_BLE_RF_POWER_REQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_POWER_REQ_EN_SHIFT)) & RSIM_CONTROL_BLE_RF_POWER_REQ_EN_MASK)

#define RSIM_CONTROL_BLE_RF_POWER_REQ_STAT_MASK  (0x2U)
#define RSIM_CONTROL_BLE_RF_POWER_REQ_STAT_SHIFT (1U)
/*! BLE_RF_POWER_REQ_STAT - BLE RF Power Request Status */
#define RSIM_CONTROL_BLE_RF_POWER_REQ_STAT(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_POWER_REQ_STAT_SHIFT)) & RSIM_CONTROL_BLE_RF_POWER_REQ_STAT_MASK)

#define RSIM_CONTROL_BLE_RF_POWER_REQ_INT_EN_MASK (0x10U)
#define RSIM_CONTROL_BLE_RF_POWER_REQ_INT_EN_SHIFT (4U)
/*! BLE_RF_POWER_REQ_INT_EN - BLE RF Power Request Interrupt Enable */
#define RSIM_CONTROL_BLE_RF_POWER_REQ_INT_EN(x)  (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_POWER_REQ_INT_EN_SHIFT)) & RSIM_CONTROL_BLE_RF_POWER_REQ_INT_EN_MASK)

#define RSIM_CONTROL_BLE_RF_POWER_REQ_INT_MASK   (0x20U)
#define RSIM_CONTROL_BLE_RF_POWER_REQ_INT_SHIFT  (5U)
/*! BLE_RF_POWER_REQ_INT - BLE RF Power Request Interrupt Flag */
#define RSIM_CONTROL_BLE_RF_POWER_REQ_INT(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_RF_POWER_REQ_INT_SHIFT)) & RSIM_CONTROL_BLE_RF_POWER_REQ_INT_MASK)

#define RSIM_CONTROL_RF_OSC_EN_MASK              (0x100U)
#define RSIM_CONTROL_RF_OSC_EN_SHIFT             (8U)
/*! RF_OSC_EN - RF Ref Osc Enable */
#define RSIM_CONTROL_RF_OSC_EN(x)                (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RF_OSC_EN_SHIFT)) & RSIM_CONTROL_RF_OSC_EN_MASK)

#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_MASK (0x1000U)
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_SHIFT (12U)
/*! RADIO_GASKET_BYPASS_OVRD_EN - Radio Gasket Bypass Override Enable */
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_SHIFT)) & RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_EN_MASK)

#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_MASK (0x2000U)
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_SHIFT (13U)
/*! RADIO_GASKET_BYPASS_OVRD - Radio Gasket Bypass Override
 *  0b0..XCVR and Link Layer Register Clock is the RF Ref Osc Clock
 *  0b1..XCVR and Link Layer Register Clock is the SoC IPG Clock
 */
#define RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_SHIFT)) & RSIM_CONTROL_RADIO_GASKET_BYPASS_OVRD_MASK)

#define RSIM_CONTROL_IPP_OBE_BLE_EARLY_WARNING_MASK (0x4000U)
#define RSIM_CONTROL_IPP_OBE_BLE_EARLY_WARNING_SHIFT (14U)
/*! IPP_OBE_BLE_EARLY_WARNING - IPP_OBE_BLE_EARLY_WARNING */
#define RSIM_CONTROL_IPP_OBE_BLE_EARLY_WARNING(x) (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_BLE_EARLY_WARNING_SHIFT)) & RSIM_CONTROL_IPP_OBE_BLE_EARLY_WARNING_MASK)

#define RSIM_CONTROL_IPP_OBE_RF_ACTIVE_MASK      (0x8000U)
#define RSIM_CONTROL_IPP_OBE_RF_ACTIVE_SHIFT     (15U)
/*! IPP_OBE_RF_ACTIVE - IPP_OBE_RF_ACTIVE */
#define RSIM_CONTROL_IPP_OBE_RF_ACTIVE(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_RF_ACTIVE_SHIFT)) & RSIM_CONTROL_IPP_OBE_RF_ACTIVE_MASK)

#define RSIM_CONTROL_IPP_OBE_RF_OSC_EN_MASK      (0x10000U)
#define RSIM_CONTROL_IPP_OBE_RF_OSC_EN_SHIFT     (16U)
/*! IPP_OBE_RF_OSC_EN - IPP_OBE_RF_OSC_EN */
#define RSIM_CONTROL_IPP_OBE_RF_OSC_EN(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_RF_OSC_EN_SHIFT)) & RSIM_CONTROL_IPP_OBE_RF_OSC_EN_MASK)

#define RSIM_CONTROL_IPP_OBE_RF_STATUS_MASK      (0x40000U)
#define RSIM_CONTROL_IPP_OBE_RF_STATUS_SHIFT     (18U)
/*! IPP_OBE_RF_STATUS - IPP_OBE_RF_STATUS */
#define RSIM_CONTROL_IPP_OBE_RF_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_RF_STATUS_SHIFT)) & RSIM_CONTROL_IPP_OBE_RF_STATUS_MASK)

#define RSIM_CONTROL_IPP_OBE_RF_PRIORITY_MASK    (0x80000U)
#define RSIM_CONTROL_IPP_OBE_RF_PRIORITY_SHIFT   (19U)
/*! IPP_OBE_RF_PRIORITY - IPP_OBE_RF_PRIORITY */
#define RSIM_CONTROL_IPP_OBE_RF_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_IPP_OBE_RF_PRIORITY_SHIFT)) & RSIM_CONTROL_IPP_OBE_RF_PRIORITY_MASK)

#define RSIM_CONTROL_BLE_DSM_EXIT_MASK           (0x100000U)
#define RSIM_CONTROL_BLE_DSM_EXIT_SHIFT          (20U)
/*! BLE_DSM_EXIT - BLE Force Deep Sleep Mode Exit */
#define RSIM_CONTROL_BLE_DSM_EXIT(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_BLE_DSM_EXIT_SHIFT)) & RSIM_CONTROL_BLE_DSM_EXIT_MASK)

#define RSIM_CONTROL_WOR_DSM_EXIT_MASK           (0x200000U)
#define RSIM_CONTROL_WOR_DSM_EXIT_SHIFT          (21U)
/*! WOR_DSM_EXIT - Wake on Radio Force Deep Sleep Mode Exit */
#define RSIM_CONTROL_WOR_DSM_EXIT(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_WOR_DSM_EXIT_SHIFT)) & RSIM_CONTROL_WOR_DSM_EXIT_MASK)

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

#define RSIM_CONTROL_RSIM_CGC_BLE_EN_MASK        (0x8000000U)
#define RSIM_CONTROL_RSIM_CGC_BLE_EN_SHIFT       (27U)
/*! RSIM_CGC_BLE_EN - BLE Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define RSIM_CONTROL_RSIM_CGC_BLE_EN(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_CGC_BLE_EN_SHIFT)) & RSIM_CONTROL_RSIM_CGC_BLE_EN_MASK)

#define RSIM_CONTROL_RSIM_CGC_XCVR_EN_MASK       (0x10000000U)
#define RSIM_CONTROL_RSIM_CGC_XCVR_EN_SHIFT      (28U)
/*! RSIM_CGC_XCVR_EN - XCVR Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define RSIM_CONTROL_RSIM_CGC_XCVR_EN(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_CGC_XCVR_EN_SHIFT)) & RSIM_CONTROL_RSIM_CGC_XCVR_EN_MASK)

#define RSIM_CONTROL_RSIM_CGC_ZIG_EN_MASK        (0x20000000U)
#define RSIM_CONTROL_RSIM_CGC_ZIG_EN_SHIFT       (29U)
/*! RSIM_CGC_ZIG_EN - ZIG Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define RSIM_CONTROL_RSIM_CGC_ZIG_EN(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_CGC_ZIG_EN_SHIFT)) & RSIM_CONTROL_RSIM_CGC_ZIG_EN_MASK)

#define RSIM_CONTROL_RSIM_CGC_GEN_EN_MASK        (0x80000000U)
#define RSIM_CONTROL_RSIM_CGC_GEN_EN_SHIFT       (31U)
/*! RSIM_CGC_GEN_EN - GEN Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define RSIM_CONTROL_RSIM_CGC_GEN_EN(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_CONTROL_RSIM_CGC_GEN_EN_SHIFT)) & RSIM_CONTROL_RSIM_CGC_GEN_EN_MASK)
/*! @} */

/*! @name MISC - Radio Miscellaneous */
/*! @{ */

#define RSIM_MISC_RADIO_VERSION_MASK             (0xFF000000U)
#define RSIM_MISC_RADIO_VERSION_SHIFT            (24U)
/*! RADIO_VERSION - Radio Version ID number */
#define RSIM_MISC_RADIO_VERSION(x)               (((uint32_t)(((uint32_t)(x)) << RSIM_MISC_RADIO_VERSION_SHIFT)) & RSIM_MISC_RADIO_VERSION_MASK)
/*! @} */

/*! @name POWER - RSIM Power Control */
/*! @{ */

#define RSIM_POWER_RADIO_STOP_MODE_STAT_MASK     (0x7U)
#define RSIM_POWER_RADIO_STOP_MODE_STAT_SHIFT    (0U)
/*! RADIO_STOP_MODE_STAT - Radio Stop Mode Status */
#define RSIM_POWER_RADIO_STOP_MODE_STAT(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_STOP_MODE_STAT_SHIFT)) & RSIM_POWER_RADIO_STOP_MODE_STAT_MASK)

#define RSIM_POWER_SPM_STOP_ACK_STAT_MASK        (0x8U)
#define RSIM_POWER_SPM_STOP_ACK_STAT_SHIFT       (3U)
/*! SPM_STOP_ACK_STAT - SPM Stop Acknowledge Status */
#define RSIM_POWER_SPM_STOP_ACK_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_STOP_ACK_STAT_SHIFT)) & RSIM_POWER_SPM_STOP_ACK_STAT_MASK)

#define RSIM_POWER_RADIO_STOP_MODE_OVRD_MASK     (0x70U)
#define RSIM_POWER_RADIO_STOP_MODE_OVRD_SHIFT    (4U)
/*! RADIO_STOP_MODE_OVRD - Radio Stop Mode Override */
#define RSIM_POWER_RADIO_STOP_MODE_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_STOP_MODE_OVRD_SHIFT)) & RSIM_POWER_RADIO_STOP_MODE_OVRD_MASK)

#define RSIM_POWER_RADIO_STOP_MODE_OVRD_EN_MASK  (0x80U)
#define RSIM_POWER_RADIO_STOP_MODE_OVRD_EN_SHIFT (7U)
/*! RADIO_STOP_MODE_OVRD_EN - Radio Stop Mode Override Enable */
#define RSIM_POWER_RADIO_STOP_MODE_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_STOP_MODE_OVRD_EN_SHIFT)) & RSIM_POWER_RADIO_STOP_MODE_OVRD_EN_MASK)

#define RSIM_POWER_RADIO_STOP_ACK_STAT_MASK      (0x100U)
#define RSIM_POWER_RADIO_STOP_ACK_STAT_SHIFT     (8U)
/*! RADIO_STOP_ACK_STAT - Radio Stop Acknowledge Status */
#define RSIM_POWER_RADIO_STOP_ACK_STAT(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_STOP_ACK_STAT_SHIFT)) & RSIM_POWER_RADIO_STOP_ACK_STAT_MASK)

#define RSIM_POWER_RADIO_STOP_REQ_STAT_MASK      (0x200U)
#define RSIM_POWER_RADIO_STOP_REQ_STAT_SHIFT     (9U)
/*! RADIO_STOP_REQ_STAT - Radio Stop Request Status */
#define RSIM_POWER_RADIO_STOP_REQ_STAT(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_STOP_REQ_STAT_SHIFT)) & RSIM_POWER_RADIO_STOP_REQ_STAT_MASK)

#define RSIM_POWER_RSIM_STOP_REQ_OVRD_MASK       (0x400U)
#define RSIM_POWER_RSIM_STOP_REQ_OVRD_SHIFT      (10U)
/*! RSIM_STOP_REQ_OVRD - Radio Stop Request Override */
#define RSIM_POWER_RSIM_STOP_REQ_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_STOP_REQ_OVRD_SHIFT)) & RSIM_POWER_RSIM_STOP_REQ_OVRD_MASK)

#define RSIM_POWER_RSIM_STOP_REQ_OVRD_EN_MASK    (0x800U)
#define RSIM_POWER_RSIM_STOP_REQ_OVRD_EN_SHIFT   (11U)
/*! RSIM_STOP_REQ_OVRD_EN - Radio Stop Request Override Enable */
#define RSIM_POWER_RSIM_STOP_REQ_OVRD_EN(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_STOP_REQ_OVRD_EN_SHIFT)) & RSIM_POWER_RSIM_STOP_REQ_OVRD_EN_MASK)

#define RSIM_POWER_RF_OSC_EN_OVRD_MASK           (0x1000U)
#define RSIM_POWER_RF_OSC_EN_OVRD_SHIFT          (12U)
/*! RF_OSC_EN_OVRD - Radio Osc Enable Override */
#define RSIM_POWER_RF_OSC_EN_OVRD(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RF_OSC_EN_OVRD_SHIFT)) & RSIM_POWER_RF_OSC_EN_OVRD_MASK)

#define RSIM_POWER_RF_OSC_EN_OVRD_EN_MASK        (0x2000U)
#define RSIM_POWER_RF_OSC_EN_OVRD_EN_SHIFT       (13U)
/*! RF_OSC_EN_OVRD_EN - Radio Osc Enable Override Enable */
#define RSIM_POWER_RF_OSC_EN_OVRD_EN(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RF_OSC_EN_OVRD_EN_SHIFT)) & RSIM_POWER_RF_OSC_EN_OVRD_EN_MASK)

#define RSIM_POWER_RF_POWER_EN_OVRD_MASK         (0x4000U)
#define RSIM_POWER_RF_POWER_EN_OVRD_SHIFT        (14U)
/*! RF_POWER_EN_OVRD - Radio Power Enable Override */
#define RSIM_POWER_RF_POWER_EN_OVRD(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RF_POWER_EN_OVRD_SHIFT)) & RSIM_POWER_RF_POWER_EN_OVRD_MASK)

#define RSIM_POWER_RF_POWER_EN_OVRD_EN_MASK      (0x8000U)
#define RSIM_POWER_RF_POWER_EN_OVRD_EN_SHIFT     (15U)
/*! RF_POWER_EN_OVRD_EN - Radio Power Enable Override Enable */
#define RSIM_POWER_RF_POWER_EN_OVRD_EN(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RF_POWER_EN_OVRD_EN_SHIFT)) & RSIM_POWER_RF_POWER_EN_OVRD_EN_MASK)

#define RSIM_POWER_SPM_ISO_STAT_MASK             (0x10000U)
#define RSIM_POWER_SPM_ISO_STAT_SHIFT            (16U)
/*! SPM_ISO_STAT - SPM ISO Status */
#define RSIM_POWER_SPM_ISO_STAT(x)               (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_ISO_STAT_SHIFT)) & RSIM_POWER_SPM_ISO_STAT_MASK)

#define RSIM_POWER_RADIO_ISO_STAT_MASK           (0x20000U)
#define RSIM_POWER_RADIO_ISO_STAT_SHIFT          (17U)
/*! RADIO_ISO_STAT - Radio Isolation Status */
#define RSIM_POWER_RADIO_ISO_STAT(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_ISO_STAT_SHIFT)) & RSIM_POWER_RADIO_ISO_STAT_MASK)

#define RSIM_POWER_RSIM_ISO_OVRD_MASK            (0x40000U)
#define RSIM_POWER_RSIM_ISO_OVRD_SHIFT           (18U)
/*! RSIM_ISO_OVRD - RSIM ISO Override */
#define RSIM_POWER_RSIM_ISO_OVRD(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_ISO_OVRD_SHIFT)) & RSIM_POWER_RSIM_ISO_OVRD_MASK)

#define RSIM_POWER_RSIM_ISO_OVRD_EN_MASK         (0x80000U)
#define RSIM_POWER_RSIM_ISO_OVRD_EN_SHIFT        (19U)
/*! RSIM_ISO_OVRD_EN - RSIM ISO Override Enable */
#define RSIM_POWER_RSIM_ISO_OVRD_EN(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_ISO_OVRD_EN_SHIFT)) & RSIM_POWER_RSIM_ISO_OVRD_EN_MASK)

#define RSIM_POWER_SPM_RUN_ACK_STAT_MASK         (0x100000U)
#define RSIM_POWER_SPM_RUN_ACK_STAT_SHIFT        (20U)
/*! SPM_RUN_ACK_STAT - SPM Run Request Acknowledge Status */
#define RSIM_POWER_SPM_RUN_ACK_STAT(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_RUN_ACK_STAT_SHIFT)) & RSIM_POWER_SPM_RUN_ACK_STAT_MASK)

#define RSIM_POWER_RADIO_RUN_REQ_STAT_MASK       (0x200000U)
#define RSIM_POWER_RADIO_RUN_REQ_STAT_SHIFT      (21U)
/*! RADIO_RUN_REQ_STAT - Radio Run Request Status */
#define RSIM_POWER_RADIO_RUN_REQ_STAT(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RADIO_RUN_REQ_STAT_SHIFT)) & RSIM_POWER_RADIO_RUN_REQ_STAT_MASK)

#define RSIM_POWER_RSIM_RUN_REQ_OVRD_MASK        (0x400000U)
#define RSIM_POWER_RSIM_RUN_REQ_OVRD_SHIFT       (22U)
/*! RSIM_RUN_REQ_OVRD - RSIM Run Request Override */
#define RSIM_POWER_RSIM_RUN_REQ_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_RUN_REQ_OVRD_SHIFT)) & RSIM_POWER_RSIM_RUN_REQ_OVRD_MASK)

#define RSIM_POWER_RSIM_RUN_REQ_OVRD_EN_MASK     (0x800000U)
#define RSIM_POWER_RSIM_RUN_REQ_OVRD_EN_SHIFT    (23U)
/*! RSIM_RUN_REQ_OVRD_EN - RSIM Run Request Override Enable */
#define RSIM_POWER_RSIM_RUN_REQ_OVRD_EN(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_RUN_REQ_OVRD_EN_SHIFT)) & RSIM_POWER_RSIM_RUN_REQ_OVRD_EN_MASK)

#define RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_MASK    (0x1000000U)
#define RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_SHIFT   (24U)
/*! SPM_STOP_REQ_ACK_OVRD - SPM Stop Request Acknowledge Override */
#define RSIM_POWER_SPM_STOP_REQ_ACK_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_SHIFT)) & RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_MASK)

#define RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_EN_MASK (0x2000000U)
#define RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_EN_SHIFT (25U)
/*! SPM_STOP_REQ_ACK_OVRD_EN - SPM Stop Request Acknowledge Override Enable */
#define RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_EN(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_EN_SHIFT)) & RSIM_POWER_SPM_STOP_REQ_ACK_OVRD_EN_MASK)

#define RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_MASK     (0x4000000U)
#define RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_SHIFT    (26U)
/*! SPM_RUN_REQ_ACK_OVRD - SPM Run Request Acknowledge Override */
#define RSIM_POWER_SPM_RUN_REQ_ACK_OVRD(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_SHIFT)) & RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_MASK)

#define RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_EN_MASK  (0x8000000U)
#define RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_EN_SHIFT (27U)
/*! SPM_RUN_REQ_ACK_OVRD_EN - SPM Run Request Acknowledge Override Enable */
#define RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_EN(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_EN_SHIFT)) & RSIM_POWER_SPM_RUN_REQ_ACK_OVRD_EN_MASK)

#define RSIM_POWER_RSIM_STOP_MODE_MASK           (0x70000000U)
#define RSIM_POWER_RSIM_STOP_MODE_SHIFT          (28U)
/*! RSIM_STOP_MODE - RSIM lowest allowed Stop Mode
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b011..RLLS mode (Radio State Retention mode)
 *  0b111..RVLLS mode (This is the POR setting)
 */
#define RSIM_POWER_RSIM_STOP_MODE(x)             (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_STOP_MODE_SHIFT)) & RSIM_POWER_RSIM_STOP_MODE_MASK)

#define RSIM_POWER_RSIM_RUN_REQUEST_MASK         (0x80000000U)
#define RSIM_POWER_RSIM_RUN_REQUEST_SHIFT        (31U)
/*! RSIM_RUN_REQUEST - RSIM Run Regulator Request */
#define RSIM_POWER_RSIM_RUN_REQUEST(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_POWER_RSIM_RUN_REQUEST_SHIFT)) & RSIM_POWER_RSIM_RUN_REQUEST_MASK)
/*! @} */

/*! @name SW_CONFIG - Radio Software Configuration */
/*! @{ */

#define RSIM_SW_CONFIG_RADIO_CONFIGURED_POR_RESET_MASK (0x1U)
#define RSIM_SW_CONFIG_RADIO_CONFIGURED_POR_RESET_SHIFT (0U)
/*! RADIO_CONFIGURED_POR_RESET - Radio Configuration Bit, cleared by Radio Power On Reset */
#define RSIM_SW_CONFIG_RADIO_CONFIGURED_POR_RESET(x) (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RADIO_CONFIGURED_POR_RESET_SHIFT)) & RSIM_SW_CONFIG_RADIO_CONFIGURED_POR_RESET_MASK)

#define RSIM_SW_CONFIG_RADIO_CONFIGURED_SYS_RESET_MASK (0x2U)
#define RSIM_SW_CONFIG_RADIO_CONFIGURED_SYS_RESET_SHIFT (1U)
/*! RADIO_CONFIGURED_SYS_RESET - Radio Configuration Bit, cleared by Radio System Reset */
#define RSIM_SW_CONFIG_RADIO_CONFIGURED_SYS_RESET(x) (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RADIO_CONFIGURED_SYS_RESET_SHIFT)) & RSIM_SW_CONFIG_RADIO_CONFIGURED_SYS_RESET_MASK)

#define RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_MASK  (0x10U)
#define RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_SHIFT (4U)
/*! RSIM_RF_ACTIVE_OVRD - RF Active Internal Override */
#define RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_SHIFT)) & RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_MASK)

#define RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_EN_MASK (0x20U)
#define RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_EN_SHIFT (5U)
/*! RSIM_RF_ACTIVE_OVRD_EN - RF Active Internal Override Enable */
#define RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_EN_SHIFT)) & RSIM_SW_CONFIG_RSIM_RF_ACTIVE_OVRD_EN_MASK)

#define RSIM_SW_CONFIG_RADIO_POR_BIT_MASK        (0x100U)
#define RSIM_SW_CONFIG_RADIO_POR_BIT_SHIFT       (8U)
/*! RADIO_POR_BIT - Software Power On Reset for the Radio */
#define RSIM_SW_CONFIG_RADIO_POR_BIT(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RADIO_POR_BIT_SHIFT)) & RSIM_SW_CONFIG_RADIO_POR_BIT_MASK)

#define RSIM_SW_CONFIG_RSIM_RADIO_ISO_POR_OVRD_MASK (0x1000U)
#define RSIM_SW_CONFIG_RSIM_RADIO_ISO_POR_OVRD_SHIFT (12U)
/*! RSIM_RADIO_ISO_POR_OVRD - RSIM ISO_POR Override */
#define RSIM_SW_CONFIG_RSIM_RADIO_ISO_POR_OVRD(x) (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RSIM_RADIO_ISO_POR_OVRD_SHIFT)) & RSIM_SW_CONFIG_RSIM_RADIO_ISO_POR_OVRD_MASK)

#define RSIM_SW_CONFIG_RADIO_RESET_BIT_MASK      (0x10000U)
#define RSIM_SW_CONFIG_RADIO_RESET_BIT_SHIFT     (16U)
/*! RADIO_RESET_BIT - Software System Reset for the Radio */
#define RSIM_SW_CONFIG_RADIO_RESET_BIT(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RADIO_RESET_BIT_SHIFT)) & RSIM_SW_CONFIG_RADIO_RESET_BIT_MASK)

#define RSIM_SW_CONFIG_WAKEUP_INTERRUPT_SOURCE_MASK (0x300000U)
#define RSIM_SW_CONFIG_WAKEUP_INTERRUPT_SOURCE_SHIFT (20U)
/*! WAKEUP_INTERRUPT_SOURCE - RSIM Wakeup Interrupt Source Selector
 *  0b00..No Radio Power-On Sequence interrupt will be generated.
 *  0b01..A Power-On Sequence interrupt will be generated when the RF Power Request occurs, including unblocked
 *        requests from an external source to use the RF OSC.
 *  0b10..A Power-On Sequence interrupt will be generated when the RF OSC Request occurs, but not if the RF OSC request was from an external source.
 *  0b11..A Power-On Sequence interrupt will be generated when the RSIM RF Active Warning occurs
 */
#define RSIM_SW_CONFIG_WAKEUP_INTERRUPT_SOURCE(x) (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_WAKEUP_INTERRUPT_SOURCE_SHIFT)) & RSIM_SW_CONFIG_WAKEUP_INTERRUPT_SOURCE_MASK)

#define RSIM_SW_CONFIG_RADIO0_INTERRUPT_EN_MASK  (0x1000000U)
#define RSIM_SW_CONFIG_RADIO0_INTERRUPT_EN_SHIFT (24U)
/*! RADIO0_INTERRUPT_EN - Radio0 Interrupt Enable */
#define RSIM_SW_CONFIG_RADIO0_INTERRUPT_EN(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RADIO0_INTERRUPT_EN_SHIFT)) & RSIM_SW_CONFIG_RADIO0_INTERRUPT_EN_MASK)

#define RSIM_SW_CONFIG_RADIO1_INTERRUPT_EN_MASK  (0x2000000U)
#define RSIM_SW_CONFIG_RADIO1_INTERRUPT_EN_SHIFT (25U)
/*! RADIO1_INTERRUPT_EN - Radio1 Interrupt Enable */
#define RSIM_SW_CONFIG_RADIO1_INTERRUPT_EN(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_RADIO1_INTERRUPT_EN_SHIFT)) & RSIM_SW_CONFIG_RADIO1_INTERRUPT_EN_MASK)

#define RSIM_SW_CONFIG_BLOCK_SOC_RESETS_MASK     (0x10000000U)
#define RSIM_SW_CONFIG_BLOCK_SOC_RESETS_SHIFT    (28U)
/*! BLOCK_SOC_RESETS - Block SoC Resets of the Radio, cleared by Radio System Reset */
#define RSIM_SW_CONFIG_BLOCK_SOC_RESETS(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_BLOCK_SOC_RESETS_SHIFT)) & RSIM_SW_CONFIG_BLOCK_SOC_RESETS_MASK)

#define RSIM_SW_CONFIG_BLOCK_RADIO_OUTPUTS_MASK  (0x20000000U)
#define RSIM_SW_CONFIG_BLOCK_RADIO_OUTPUTS_SHIFT (29U)
/*! BLOCK_RADIO_OUTPUTS - Block Radio Outputs */
#define RSIM_SW_CONFIG_BLOCK_RADIO_OUTPUTS(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_BLOCK_RADIO_OUTPUTS_SHIFT)) & RSIM_SW_CONFIG_BLOCK_RADIO_OUTPUTS_MASK)

#define RSIM_SW_CONFIG_BLOCK_EXT_OSC_PWR_REQ_MASK (0x80000000U)
#define RSIM_SW_CONFIG_BLOCK_EXT_OSC_PWR_REQ_SHIFT (31U)
/*! BLOCK_EXT_OSC_PWR_REQ - Block External Requests for RF OSC from starting a Radio Power Wakeup Sequence */
#define RSIM_SW_CONFIG_BLOCK_EXT_OSC_PWR_REQ(x)  (((uint32_t)(((uint32_t)(x)) << RSIM_SW_CONFIG_BLOCK_EXT_OSC_PWR_REQ_SHIFT)) & RSIM_SW_CONFIG_BLOCK_EXT_OSC_PWR_REQ_MASK)
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

#define RSIM_DSM_CONTROL_DSM_WOR_READY_MASK      (0x1U)
#define RSIM_DSM_CONTROL_DSM_WOR_READY_SHIFT     (0U)
/*! DSM_WOR_READY - WOR Ready for Deep Sleep Mode */
#define RSIM_DSM_CONTROL_DSM_WOR_READY(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_WOR_READY_SHIFT)) & RSIM_DSM_CONTROL_DSM_WOR_READY_MASK)

#define RSIM_DSM_CONTROL_WOR_DEEP_SLEEP_STATUS_MASK (0x2U)
#define RSIM_DSM_CONTROL_WOR_DEEP_SLEEP_STATUS_SHIFT (1U)
/*! WOR_DEEP_SLEEP_STATUS - WOR Deep Sleep Mode Status */
#define RSIM_DSM_CONTROL_WOR_DEEP_SLEEP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WOR_DEEP_SLEEP_STATUS_SHIFT)) & RSIM_DSM_CONTROL_WOR_DEEP_SLEEP_STATUS_MASK)

#define RSIM_DSM_CONTROL_DSM_WOR_FINISHED_MASK   (0x4U)
#define RSIM_DSM_CONTROL_DSM_WOR_FINISHED_SHIFT  (2U)
/*! DSM_WOR_FINISHED - WOR Deep Sleep Time Finished */
#define RSIM_DSM_CONTROL_DSM_WOR_FINISHED(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_WOR_FINISHED_SHIFT)) & RSIM_DSM_CONTROL_DSM_WOR_FINISHED_MASK)

#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQUEST_EN_MASK (0x8U)
#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQUEST_EN_SHIFT (3U)
/*! WOR_WAKEUP_REQUEST_EN - Enable WOR Deep Sleep Module to initiate a Radio Wakeup */
#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQUEST_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WOR_WAKEUP_REQUEST_EN_SHIFT)) & RSIM_DSM_CONTROL_WOR_WAKEUP_REQUEST_EN_MASK)

#define RSIM_DSM_CONTROL_WOR_SLEEP_REQUEST_MASK  (0x10U)
#define RSIM_DSM_CONTROL_WOR_SLEEP_REQUEST_SHIFT (4U)
/*! WOR_SLEEP_REQUEST - WOR Deep Sleep Requested */
#define RSIM_DSM_CONTROL_WOR_SLEEP_REQUEST(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WOR_SLEEP_REQUEST_SHIFT)) & RSIM_DSM_CONTROL_WOR_SLEEP_REQUEST_MASK)

#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_MASK     (0x20U)
#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_SHIFT    (5U)
/*! WOR_WAKEUP_REQ - WOR Deep Sleep Module Radio Wakeup Status */
#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_SHIFT)) & RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_MASK)

#define RSIM_DSM_CONTROL_WOR_WAKEUP_INTERRUPT_EN_MASK (0x40U)
#define RSIM_DSM_CONTROL_WOR_WAKEUP_INTERRUPT_EN_SHIFT (6U)
/*! WOR_WAKEUP_INTERRUPT_EN - WOR Deep Sleep Module Radio Wakeup Interrupt Enable */
#define RSIM_DSM_CONTROL_WOR_WAKEUP_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WOR_WAKEUP_INTERRUPT_EN_SHIFT)) & RSIM_DSM_CONTROL_WOR_WAKEUP_INTERRUPT_EN_MASK)

#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_INT_MASK (0x80U)
#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_INT_SHIFT (7U)
/*! WOR_WAKEUP_REQ_INT - Interrupt Flag from an WOR Deep Sleep Module Radio Wakeup */
#define RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_INT(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_INT_SHIFT)) & RSIM_DSM_CONTROL_WOR_WAKEUP_REQ_INT_MASK)

#define RSIM_DSM_CONTROL_DSM_MAN_READY_MASK      (0x100U)
#define RSIM_DSM_CONTROL_DSM_MAN_READY_SHIFT     (8U)
/*! DSM_MAN_READY - MAN Ready for Deep Sleep Mode */
#define RSIM_DSM_CONTROL_DSM_MAN_READY(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_MAN_READY_SHIFT)) & RSIM_DSM_CONTROL_DSM_MAN_READY_MASK)

#define RSIM_DSM_CONTROL_MAN_DEEP_SLEEP_STATUS_MASK (0x200U)
#define RSIM_DSM_CONTROL_MAN_DEEP_SLEEP_STATUS_SHIFT (9U)
/*! MAN_DEEP_SLEEP_STATUS - MAN Deep Sleep Mode Status */
#define RSIM_DSM_CONTROL_MAN_DEEP_SLEEP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_MAN_DEEP_SLEEP_STATUS_SHIFT)) & RSIM_DSM_CONTROL_MAN_DEEP_SLEEP_STATUS_MASK)

#define RSIM_DSM_CONTROL_DSM_MAN_FINISHED_MASK   (0x400U)
#define RSIM_DSM_CONTROL_DSM_MAN_FINISHED_SHIFT  (10U)
/*! DSM_MAN_FINISHED - MAN Deep Sleep Time Finished */
#define RSIM_DSM_CONTROL_DSM_MAN_FINISHED(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_MAN_FINISHED_SHIFT)) & RSIM_DSM_CONTROL_DSM_MAN_FINISHED_MASK)

#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQUEST_EN_MASK (0x800U)
#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQUEST_EN_SHIFT (11U)
/*! MAN_WAKEUP_REQUEST_EN - Enable MAN Deep Sleep Module to initiate a Radio Wakeup */
#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQUEST_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_MAN_WAKEUP_REQUEST_EN_SHIFT)) & RSIM_DSM_CONTROL_MAN_WAKEUP_REQUEST_EN_MASK)

#define RSIM_DSM_CONTROL_MAN_SLEEP_REQUEST_MASK  (0x1000U)
#define RSIM_DSM_CONTROL_MAN_SLEEP_REQUEST_SHIFT (12U)
/*! MAN_SLEEP_REQUEST - MAN Deep Sleep Requested */
#define RSIM_DSM_CONTROL_MAN_SLEEP_REQUEST(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_MAN_SLEEP_REQUEST_SHIFT)) & RSIM_DSM_CONTROL_MAN_SLEEP_REQUEST_MASK)

#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_MASK     (0x2000U)
#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_SHIFT    (13U)
/*! MAN_WAKEUP_REQ - MAN Deep Sleep Module Radio Wakeup Status */
#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_SHIFT)) & RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_MASK)

#define RSIM_DSM_CONTROL_MAN_WAKEUP_INTERRUPT_EN_MASK (0x4000U)
#define RSIM_DSM_CONTROL_MAN_WAKEUP_INTERRUPT_EN_SHIFT (14U)
/*! MAN_WAKEUP_INTERRUPT_EN - MAN Deep Sleep Module Radio Wakeup Interrupt Enable */
#define RSIM_DSM_CONTROL_MAN_WAKEUP_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_MAN_WAKEUP_INTERRUPT_EN_SHIFT)) & RSIM_DSM_CONTROL_MAN_WAKEUP_INTERRUPT_EN_MASK)

#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_INT_MASK (0x8000U)
#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_INT_SHIFT (15U)
/*! MAN_WAKEUP_REQ_INT - Interrupt Flag from an MAN Deep Sleep Module Radio Wakeup */
#define RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_INT(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_INT_SHIFT)) & RSIM_DSM_CONTROL_MAN_WAKEUP_REQ_INT_MASK)

#define RSIM_DSM_CONTROL_WIFI_COEXIST_1_MASK     (0x10000U)
#define RSIM_DSM_CONTROL_WIFI_COEXIST_1_SHIFT    (16U)
/*! WIFI_COEXIST_1 - RF_ACTIVE Source */
#define RSIM_DSM_CONTROL_WIFI_COEXIST_1(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WIFI_COEXIST_1_SHIFT)) & RSIM_DSM_CONTROL_WIFI_COEXIST_1_MASK)

#define RSIM_DSM_CONTROL_WIFI_COEXIST_2_MASK     (0x20000U)
#define RSIM_DSM_CONTROL_WIFI_COEXIST_2_SHIFT    (17U)
/*! WIFI_COEXIST_2 - RF_STATUS Source */
#define RSIM_DSM_CONTROL_WIFI_COEXIST_2(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WIFI_COEXIST_2_SHIFT)) & RSIM_DSM_CONTROL_WIFI_COEXIST_2_MASK)

#define RSIM_DSM_CONTROL_WIFI_COEXIST_3_MASK     (0x40000U)
#define RSIM_DSM_CONTROL_WIFI_COEXIST_3_SHIFT    (18U)
/*! WIFI_COEXIST_3 - RF_EARLY_WARNING Source */
#define RSIM_DSM_CONTROL_WIFI_COEXIST_3(x)       (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_WIFI_COEXIST_3_SHIFT)) & RSIM_DSM_CONTROL_WIFI_COEXIST_3_MASK)

#define RSIM_DSM_CONTROL_RF_ACTIVE_ENDS_WITH_TSM_MASK (0x100000U)
#define RSIM_DSM_CONTROL_RF_ACTIVE_ENDS_WITH_TSM_SHIFT (20U)
/*! RF_ACTIVE_ENDS_WITH_TSM - RF_ACTIVE clearing mechanism */
#define RSIM_DSM_CONTROL_RF_ACTIVE_ENDS_WITH_TSM(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_RF_ACTIVE_ENDS_WITH_TSM_SHIFT)) & RSIM_DSM_CONTROL_RF_ACTIVE_ENDS_WITH_TSM_MASK)

#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_ENDS_WITH_TSM_MASK (0x200000U)
#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_ENDS_WITH_TSM_SHIFT (21U)
/*! SW_RF_ACTIVE_ENDS_WITH_TSM - Software RF_ACTIVE clearing mechanism */
#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_ENDS_WITH_TSM(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_SW_RF_ACTIVE_ENDS_WITH_TSM_SHIFT)) & RSIM_DSM_CONTROL_SW_RF_ACTIVE_ENDS_WITH_TSM_MASK)

#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_BIT_MASK   (0x400000U)
#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_BIT_SHIFT  (22U)
/*! SW_RF_ACTIVE_BIT - Software RF_ACTIVE Control Bit */
#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_BIT(x)     (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_SW_RF_ACTIVE_BIT_SHIFT)) & RSIM_DSM_CONTROL_SW_RF_ACTIVE_BIT_MASK)

#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_EN_MASK    (0x800000U)
#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_EN_SHIFT   (23U)
/*! SW_RF_ACTIVE_EN - Software RF_ACTIVE Control Enable */
#define RSIM_DSM_CONTROL_SW_RF_ACTIVE_EN(x)      (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_SW_RF_ACTIVE_EN_SHIFT)) & RSIM_DSM_CONTROL_SW_RF_ACTIVE_EN_MASK)

#define RSIM_DSM_CONTROL_DSM_TIMER_CLR_MASK      (0x8000000U)
#define RSIM_DSM_CONTROL_DSM_TIMER_CLR_SHIFT     (27U)
/*! DSM_TIMER_CLR - Deep Sleep Mode Timer Clear */
#define RSIM_DSM_CONTROL_DSM_TIMER_CLR(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_TIMER_CLR_SHIFT)) & RSIM_DSM_CONTROL_DSM_TIMER_CLR_MASK)

#define RSIM_DSM_CONTROL_DSM_TIMER_EN_MASK       (0x80000000U)
#define RSIM_DSM_CONTROL_DSM_TIMER_EN_SHIFT      (31U)
/*! DSM_TIMER_EN - Deep Sleep Mode Timer Enable */
#define RSIM_DSM_CONTROL_DSM_TIMER_EN(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_CONTROL_DSM_TIMER_EN_SHIFT)) & RSIM_DSM_CONTROL_DSM_TIMER_EN_MASK)
/*! @} */

/*! @name DSM_WAKEUP - Deep Sleep Wakeup Sequence */
/*! @{ */

#define RSIM_DSM_WAKEUP_DSM_POWER_OFFSET_TIME_MASK (0x3FFU)
#define RSIM_DSM_WAKEUP_DSM_POWER_OFFSET_TIME_SHIFT (0U)
/*! DSM_POWER_OFFSET_TIME - Deep Sleep Wakeup Power Offset Time */
#define RSIM_DSM_WAKEUP_DSM_POWER_OFFSET_TIME(x) (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_WAKEUP_DSM_POWER_OFFSET_TIME_SHIFT)) & RSIM_DSM_WAKEUP_DSM_POWER_OFFSET_TIME_MASK)

#define RSIM_DSM_WAKEUP_ACTIVE_WARNING_MASK      (0x3F000U)
#define RSIM_DSM_WAKEUP_ACTIVE_WARNING_SHIFT     (12U)
/*! ACTIVE_WARNING - Deep Sleep Wakeup RF Active Warning Time */
#define RSIM_DSM_WAKEUP_ACTIVE_WARNING(x)        (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_WAKEUP_ACTIVE_WARNING_SHIFT)) & RSIM_DSM_WAKEUP_ACTIVE_WARNING_MASK)

#define RSIM_DSM_WAKEUP_FINE_DELAY_MASK          (0x3F00000U)
#define RSIM_DSM_WAKEUP_FINE_DELAY_SHIFT         (20U)
/*! FINE_DELAY - Deep Sleep Wakeup Fine Delay Time */
#define RSIM_DSM_WAKEUP_FINE_DELAY(x)            (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_WAKEUP_FINE_DELAY_SHIFT)) & RSIM_DSM_WAKEUP_FINE_DELAY_MASK)

#define RSIM_DSM_WAKEUP_COARSE_DELAY_MASK        (0xF0000000U)
#define RSIM_DSM_WAKEUP_COARSE_DELAY_SHIFT       (28U)
/*! COARSE_DELAY - Deep Sleep Wakeup Coarse Delay Time */
#define RSIM_DSM_WAKEUP_COARSE_DELAY(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_DSM_WAKEUP_COARSE_DELAY_SHIFT)) & RSIM_DSM_WAKEUP_COARSE_DELAY_MASK)
/*! @} */

/*! @name WOR_DURATION - WOR Deep Sleep Duration */
/*! @{ */

#define RSIM_WOR_DURATION_WOR_DSM_DURATION_MASK  (0xFFFFFFU)
#define RSIM_WOR_DURATION_WOR_DSM_DURATION_SHIFT (0U)
/*! WOR_DSM_DURATION - WOR Deep Sleep Time Elapsed */
#define RSIM_WOR_DURATION_WOR_DSM_DURATION(x)    (((uint32_t)(((uint32_t)(x)) << RSIM_WOR_DURATION_WOR_DSM_DURATION_SHIFT)) & RSIM_WOR_DURATION_WOR_DSM_DURATION_MASK)
/*! @} */

/*! @name WOR_WAKE - WOR Deep Sleep Wake Time */
/*! @{ */

#define RSIM_WOR_WAKE_WOR_WAKE_TIME_MASK         (0xFFFFFFU)
#define RSIM_WOR_WAKE_WOR_WAKE_TIME_SHIFT        (0U)
/*! WOR_WAKE_TIME - WOR Deep Sleep Module Wake Time */
#define RSIM_WOR_WAKE_WOR_WAKE_TIME(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_WOR_WAKE_WOR_WAKE_TIME_SHIFT)) & RSIM_WOR_WAKE_WOR_WAKE_TIME_MASK)

#define RSIM_WOR_WAKE_WOR_FSM_STATE_MASK         (0x70000000U)
#define RSIM_WOR_WAKE_WOR_FSM_STATE_SHIFT        (28U)
/*! WOR_FSM_STATE - WOR Deep Sleep State Machine State */
#define RSIM_WOR_WAKE_WOR_FSM_STATE(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_WOR_WAKE_WOR_FSM_STATE_SHIFT)) & RSIM_WOR_WAKE_WOR_FSM_STATE_MASK)
/*! @} */

/*! @name MAN_SLEEP - MAN Deep Sleep Time */
/*! @{ */

#define RSIM_MAN_SLEEP_MAN_SLEEP_TIME_MASK       (0xFFFFFFU)
#define RSIM_MAN_SLEEP_MAN_SLEEP_TIME_SHIFT      (0U)
/*! MAN_SLEEP_TIME - MAN Deep Sleep Module Sleep Time */
#define RSIM_MAN_SLEEP_MAN_SLEEP_TIME(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_MAN_SLEEP_MAN_SLEEP_TIME_SHIFT)) & RSIM_MAN_SLEEP_MAN_SLEEP_TIME_MASK)
/*! @} */

/*! @name MAN_WAKE - MAN Deep Sleep Wake Time */
/*! @{ */

#define RSIM_MAN_WAKE_MAN_WAKE_TIME_MASK         (0xFFFFFFU)
#define RSIM_MAN_WAKE_MAN_WAKE_TIME_SHIFT        (0U)
/*! MAN_WAKE_TIME - MAN Deep Sleep Module Wake Time */
#define RSIM_MAN_WAKE_MAN_WAKE_TIME(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_MAN_WAKE_MAN_WAKE_TIME_SHIFT)) & RSIM_MAN_WAKE_MAN_WAKE_TIME_MASK)

#define RSIM_MAN_WAKE_MAN_FSM_STATE_MASK         (0x70000000U)
#define RSIM_MAN_WAKE_MAN_FSM_STATE_SHIFT        (28U)
/*! MAN_FSM_STATE - MAN Deep Sleep State Machine State */
#define RSIM_MAN_WAKE_MAN_FSM_STATE(x)           (((uint32_t)(((uint32_t)(x)) << RSIM_MAN_WAKE_MAN_FSM_STATE_SHIFT)) & RSIM_MAN_WAKE_MAN_FSM_STATE_MASK)
/*! @} */

/*! @name RF_OSC_CTRL - Radio Oscillator Control */
/*! @{ */

#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL_MASK (0x3U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_ALC_COUNT_SEL_SHIFT (0U)
/*! BB_XTAL_ALC_COUNT_SEL - rmap_bb_xtal_alc_count_sel_hv[1:0]
 *  0b00..2048 (64 us @ 32 MHz)
 *  0b01..4096 (128 us @ 32 MHz)
 *  0b10..8192 (256 us @ 32 MHz)
 *  0b11..16384 (512 us @ 32 MHz)
 */
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
/*! BB_XTAL_ON_OVRD_ON - rmap_bb_xtal_on_ovrd_on_hv
 *  0b0..rfctrl_bb_xtal_on_hv is asserted
 *  0b1..rfctrl_bb_xtal_on_ovrd_hv is asserted
 */
#define RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON(x)   (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON_SHIFT)) & RSIM_RF_OSC_CTRL_BB_XTAL_ON_OVRD_ON_MASK)

#define RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL_MASK (0x300000U)
#define RSIM_RF_OSC_CTRL_BB_XTAL_READY_COUNT_SEL_SHIFT (20U)
/*! BB_XTAL_READY_COUNT_SEL - rmap_bb_xtal_ready_count_sel_hv[1:0]
 *  0b00..1024 counts (32 us @ 32 MHz)
 *  0b01..2048 (64 us @ 32 MHz)
 *  0b10..4096 (128 us @ 32 MHz)
 *  0b11..8192 (256 us @ 32 MHz)
 */
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

#define RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_MASK (0x40000000U)
#define RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_SHIFT (30U)
/*! RF_NOT_ALLOWED_OVRD - RF Not Allowed Override */
#define RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD(x)  (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_SHIFT)) & RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_MASK)

#define RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_EN_MASK (0x80000000U)
#define RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_EN_SHIFT (31U)
/*! RF_NOT_ALLOWED_OVRD_EN - RF Not Allowed Override Enable */
#define RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_EN_SHIFT)) & RSIM_RF_OSC_CTRL_RF_NOT_ALLOWED_OVRD_EN_MASK)
/*! @} */

/*! @name ANA_TEST - Radio Analog Test Registers */
/*! @{ */

#define RSIM_ANA_TEST_XTAL_OUT_BUF_EN_MASK       (0x10U)
#define RSIM_ANA_TEST_XTAL_OUT_BUF_EN_SHIFT      (4U)
/*! XTAL_OUT_BUF_EN - XTAL Output Buffer Enable */
#define RSIM_ANA_TEST_XTAL_OUT_BUF_EN(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TEST_XTAL_OUT_BUF_EN_SHIFT)) & RSIM_ANA_TEST_XTAL_OUT_BUF_EN_MASK)
/*! @} */

/*! @name ANA_TRIM - Radio Analog Trim Registers */
/*! @{ */

#define RSIM_ANA_TRIM_BB_LDO_LS_SPARE_MASK       (0x3U)
#define RSIM_ANA_TRIM_BB_LDO_LS_SPARE_SHIFT      (0U)
/*! BB_LDO_LS_SPARE - rmap_bb_ldo_ls_spare_hv[1:0] */
#define RSIM_ANA_TRIM_BB_LDO_LS_SPARE(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_LS_SPARE_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_LS_SPARE_MASK)

#define RSIM_ANA_TRIM_BG_1V_TRIM_OVRD_MASK       (0x4U)
#define RSIM_ANA_TRIM_BG_1V_TRIM_OVRD_SHIFT      (2U)
/*! BG_1V_TRIM_OVRD - Bandgap 1V Trim Override */
#define RSIM_ANA_TRIM_BG_1V_TRIM_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BG_1V_TRIM_OVRD_SHIFT)) & RSIM_ANA_TRIM_BG_1V_TRIM_OVRD_MASK)

#define RSIM_ANA_TRIM_BB_LDO_LS_TRIM_MASK        (0x38U)
#define RSIM_ANA_TRIM_BB_LDO_LS_TRIM_SHIFT       (3U)
/*! BB_LDO_LS_TRIM - rmap_bb_ldo_ls_trim_hv[2:0]
 *  0b000..1.20 V (Default)
 *  0b001..1.25 V
 *  0b010..1.28 V
 *  0b011..1.33 V
 *  0b100..1.40 V
 *  0b101..1.44 V
 *  0b110..1.50 V
 *  0b111..1.66 V
 */
#define RSIM_ANA_TRIM_BB_LDO_LS_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_LS_TRIM_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_LS_TRIM_MASK)

#define RSIM_ANA_TRIM_BB_LDO_XO_SPARE_MASK       (0xC0U)
#define RSIM_ANA_TRIM_BB_LDO_XO_SPARE_SHIFT      (6U)
/*! BB_LDO_XO_SPARE - rmap_bb_ldo_xo_spare_hv[1:0] */
#define RSIM_ANA_TRIM_BB_LDO_XO_SPARE(x)         (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BB_LDO_XO_SPARE_SHIFT)) & RSIM_ANA_TRIM_BB_LDO_XO_SPARE_MASK)

#define RSIM_ANA_TRIM_BB_LDO_XO_TRIM_MASK        (0x700U)
#define RSIM_ANA_TRIM_BB_LDO_XO_TRIM_SHIFT       (8U)
/*! BB_LDO_XO_TRIM - rmap_bb_ldo_xo_trim_hv[2:0]
 *  0b000..1.20 V (Default)
 *  0b001..1.25 V
 *  0b010..1.28 V
 *  0b011..1.33 V
 *  0b100..1.40 V
 *  0b101..1.44 V
 *  0b110..1.50 V
 *  0b111..1.66 V
 */
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
/*! BG_1V_TRIM - rmap_bg_1v_trim_hv[3:0]
 *  0b0000..954.14 mV
 *  0b0001..959.26 mV
 *  0b0010..964.38 mV
 *  0b0011..969.5 mV
 *  0b0100..974.6 mV
 *  0b0101..979.7 mV
 *  0b0110..984.8 mV
 *  0b0111..989.9 mV
 *  0b1000..995 mV (Default)
 *  0b1001..1 V
 *  0b1010..1.005 V
 *  0b1011..1.01 V
 *  0b1100..1.015 V
 *  0b1101..1.02 V
 *  0b1110..1.025 V
 *  0b1111..1.031 V
 */
#define RSIM_ANA_TRIM_BG_1V_TRIM(x)              (((uint32_t)(((uint32_t)(x)) << RSIM_ANA_TRIM_BG_1V_TRIM_SHIFT)) & RSIM_ANA_TRIM_BG_1V_TRIM_MASK)

#define RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM_MASK      (0xF0000000U)
#define RSIM_ANA_TRIM_BG_IBIAS_5U_TRIM_SHIFT     (28U)
/*! BG_IBIAS_5U_TRIM - rmap_bg_ibias_5u_trim_hv[3:0]
 *  0b0000..3.55 uA
 *  0b0001..3.73 uA
 *  0b0010..4.04 uA
 *  0b0011..4.22 uA
 *  0b0100..4.39 uA
 *  0b0101..4.57 uA
 *  0b0110..4.89 uA
 *  0b0111..5.06 (Default)
 *  0b1000..5.23 uA
 *  0b1001..5.41 uA
 *  0b1010..5.72 uA
 *  0b1011..5.9 uA
 *  0b1100..6.07 uA
 *  0b1101..6.25 uA
 *  0b1110..6.56 uA
 *  0b1111..6.74 uA
 */
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


#endif  /* PERI_RSIM_H_ */

