/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file GPC.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for GPC
 *
 * CMSIS Peripheral Access Layer for GPC
 */

#if !defined(GPC_H_)
#define GPC_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- GPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Peripheral_Access_Layer GPC Peripheral Access Layer
 * @{
 */

/** GPC - Size of Registers Arrays */
#define GPC_CMC_IRQ_WAKEUP_MASK_ARRAY_COUNT       12u
#define GPC_CMC_IRQ_WAKEUP_STAT_ARRAY_COUNT       12u

/** GPC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CMC_AUTHEN_CTRL;                   /**< CMC Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMC_MISC;                          /**< Miscellaneous, offset: 0xC */
  __IO uint32_t CMC_MODE_CTRL;                     /**< CPU mode control, offset: 0x10 */
  __I  uint32_t CMC_MODE_STAT;                     /**< CPU mode Status, offset: 0x14 */
  __I  uint32_t CMC_PIN_STAT;                      /**< CMC pin Status, offset: 0x18 */
       uint8_t RESERVED_2[228];
  __IO uint32_t CMC_IRQ_WAKEUP_MASK[GPC_CMC_IRQ_WAKEUP_MASK_ARRAY_COUNT]; /**< IRQ wake-up mask register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t CMC_NON_IRQ_WAKEUP_MASK;           /**< CMC non-IRQ wakeup mask, offset: 0x140 */
       uint8_t RESERVED_4[12];
  __I  uint32_t CMC_IRQ_WAKEUP_STAT[GPC_CMC_IRQ_WAKEUP_STAT_ARRAY_COUNT]; /**< IRQ status register, array offset: 0x150, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __I  uint32_t CMC_NON_IRQ_WAKEUP_STAT;           /**< CMC non-IRQ wakeup status, offset: 0x190 */
       uint8_t RESERVED_6[108];
  __IO uint32_t CMC_SLEEP_A55_HDSK_CTRL;           /**< CMC sleep A55_HDSK control, offset: 0x200 */
  __I  uint32_t CMC_SLEEP_A55_HDSK_STAT;           /**< CMC sleep A55_HDSK status, offset: 0x204 */
  __IO uint32_t CMC_SLEEP_SSAR_CTRL;               /**< CMC sleep SSAR control, offset: 0x208 */
  __I  uint32_t CMC_SLEEP_SSAR_STAT;               /**< CMC sleep SSAR status, offset: 0x20C */
       uint8_t RESERVED_7[32];
  __IO uint32_t CMC_SLEEP_RESET_CTRL;              /**< CMC sleep reset control, offset: 0x230 */
  __I  uint32_t CMC_SLEEP_RESET_STAT;              /**< CMC sleep reset status, offset: 0x234 */
       uint8_t RESERVED_8[16];
  __IO uint32_t CMC_SLEEP_SYSMAN_CTRL;             /**< CMC sleep Sysman control, offset: 0x248 */
  __I  uint32_t CMC_SLEEP_SYSMAN_STAT;             /**< CMC Sleep Sysman status, offset: 0x24C */
       uint8_t RESERVED_9[64];
  __IO uint32_t CMC_WAKEUP_POWER_CTRL;             /**< CMC wakeup power control, offset: 0x290 */
  __I  uint32_t CMC_WAKEUP_POWER_STAT;             /**< CMC wakeup power status, offset: 0x294 */
       uint8_t RESERVED_10[48];
  __IO uint32_t CMC_WAKEUP_SSAR_CTRL;              /**< CMC wakeup SSAR control, offset: 0x2C8 */
  __I  uint32_t CMC_WAKEUP_SSAR_STAT;              /**< CMC wakeup SSAR status, offset: 0x2CC */
  __IO uint32_t CMC_WAKEUP_A55_HDSK_CTRL;          /**< CMC wakeup A55_HDSK control, offset: 0x2D0 */
  __I  uint32_t CMC_WAKEUP_A55_HDSK_STAT;          /**< CMC wakeup A55_HDSK status, offset: 0x2D4 */
  __IO uint32_t CMC_WAKEUP_SYSMAN_CTRL;            /**< CMC wakeup Sysman control, offset: 0x2D8 */
  __I  uint32_t CMC_WAKEUP_SYSMAN_STAT;            /**< CMC wakeup Sysman status, offset: 0x2DC */
       uint8_t RESERVED_11[160];
  __IO uint32_t CMC_SYS_SLEEP_CTRL;                /**< CMC system sleep control, offset: 0x380 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CMC_DEBUG;                         /**< CMC debug, offset: 0x390 */
} GPC_Type;

/* ----------------------------------------------------------------------------
   -- GPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Register_Masks GPC Register Masks
 * @{
 */

/*! @name CMC_AUTHEN_CTRL - CMC Authentication Control */
/*! @{ */

#define GPC_CMC_AUTHEN_CTRL_LOCK_CFG_MASK        (0x80U)
#define GPC_CMC_AUTHEN_CTRL_LOCK_CFG_SHIFT       (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. It locks the CPUx_CM registers which are marked
 *       as "Locked by LOCK_CFG field" in the function field.
 */
#define GPC_CMC_AUTHEN_CTRL_LOCK_CFG(x)          (((uint32_t)(((uint32_t)(x)) << GPC_CMC_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_CMC_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_CMC_AUTHEN_CTRL_USER_MASK            (0x100U)
#define GPC_CMC_AUTHEN_CTRL_USER_SHIFT           (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_CMC_AUTHEN_CTRL_USER(x)              (((uint32_t)(((uint32_t)(x)) << GPC_CMC_AUTHEN_CTRL_USER_SHIFT)) & GPC_CMC_AUTHEN_CTRL_USER_MASK)

#define GPC_CMC_AUTHEN_CTRL_NONSECURE_MASK       (0x200U)
#define GPC_CMC_AUTHEN_CTRL_NONSECURE_SHIFT      (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode control
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers
 */
#define GPC_CMC_AUTHEN_CTRL_NONSECURE(x)         (((uint32_t)(((uint32_t)(x)) << GPC_CMC_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_CMC_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_CMC_AUTHEN_CTRL_LOCK_SETTING_MASK    (0x800U)
#define GPC_CMC_AUTHEN_CTRL_LOCK_SETTING_SHIFT   (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_CMC_AUTHEN_CTRL_LOCK_SETTING(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_CMC_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_CMC_AUTHEN_CTRL_LOCK_LIST_MASK       (0x8000U)
#define GPC_CMC_AUTHEN_CTRL_LOCK_LIST_SHIFT      (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_CMC_AUTHEN_CTRL_LOCK_LIST(x)         (((uint32_t)(((uint32_t)(x)) << GPC_CMC_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_CMC_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_CMC_AUTHEN_CTRL_WHITE_LIST_MASK      (0xFFFF0000U)
#define GPC_CMC_AUTHEN_CTRL_WHITE_LIST_SHIFT     (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_CMC_AUTHEN_CTRL_WHITE_LIST(x)        (((uint32_t)(((uint32_t)(x)) << GPC_CMC_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_CMC_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name CMC_MISC - Miscellaneous */
/*! @{ */

#define GPC_CMC_MISC_NMI_STAT_MASK               (0x1U)
#define GPC_CMC_MISC_NMI_STAT_SHIFT              (0U)
/*! NMI_STAT - Non-masked interrupt status
 *  0b0..NMI is not asserted
 *  0b1..NMI is asserted
 */
#define GPC_CMC_MISC_NMI_STAT(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MISC_NMI_STAT_SHIFT)) & GPC_CMC_MISC_NMI_STAT_MASK)

#define GPC_CMC_MISC_SLEEP_HOLD_EN_MASK          (0x2U)
#define GPC_CMC_MISC_SLEEP_HOLD_EN_SHIFT         (1U)
/*! SLEEP_HOLD_EN - Allow cpu_sleep_hold_req assert during CPU low power status
 *  0b0..Disable cpu_sleep_hold_req
 *  0b1..Allow cpu_sleep_hold_req to assert during CPU low power status
 */
#define GPC_CMC_MISC_SLEEP_HOLD_EN(x)            (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MISC_SLEEP_HOLD_EN_SHIFT)) & GPC_CMC_MISC_SLEEP_HOLD_EN_MASK)

#define GPC_CMC_MISC_SLEEP_HOLD_STAT_MASK        (0x4U)
#define GPC_CMC_MISC_SLEEP_HOLD_STAT_SHIFT       (2U)
/*! SLEEP_HOLD_STAT - Status of cpu_sleep_hold_ack_b
 *  0b0..CPU sleep hold is acknowledged
 *  0b1..CPU is not in sleep hold
 */
#define GPC_CMC_MISC_SLEEP_HOLD_STAT(x)          (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MISC_SLEEP_HOLD_STAT_SHIFT)) & GPC_CMC_MISC_SLEEP_HOLD_STAT_MASK)

#define GPC_CMC_MISC_GIC_WAKEUP_STAT_MASK        (0x10U)
#define GPC_CMC_MISC_GIC_WAKEUP_STAT_SHIFT       (4U)
/*! GIC_WAKEUP_STAT - GIC wakeup request status
 *  0b0..GIC wakeup is not asserted
 *  0b1..GIC wakeup is asserted
 */
#define GPC_CMC_MISC_GIC_WAKEUP_STAT(x)          (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MISC_GIC_WAKEUP_STAT_SHIFT)) & GPC_CMC_MISC_GIC_WAKEUP_STAT_MASK)

#define GPC_CMC_MISC_IRQ_MUX_MASK                (0x20U)
#define GPC_CMC_MISC_IRQ_MUX_SHIFT               (5U)
/*! IRQ_MUX - IRQ select
 *  0b0..From raw IRQ
 *  0b1..From GIC
 */
#define GPC_CMC_MISC_IRQ_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MISC_IRQ_MUX_SHIFT)) & GPC_CMC_MISC_IRQ_MUX_MASK)

#define GPC_CMC_MISC_SW_WAKEUP_MASK              (0x40U)
#define GPC_CMC_MISC_SW_WAKEUP_SHIFT             (6U)
/*! SW_WAKEUP - Software wakeup. Used for CPU hotplug.
 *  0b0..Software wakeup is not asserted
 *  0b1..Software wakeup is asserted
 */
#define GPC_CMC_MISC_SW_WAKEUP(x)                (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MISC_SW_WAKEUP_SHIFT)) & GPC_CMC_MISC_SW_WAKEUP_MASK)
/*! @} */

/*! @name CMC_MODE_CTRL - CPU mode control */
/*! @{ */

#define GPC_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK   (0x3U)
#define GPC_CMC_MODE_CTRL_CPU_MODE_TARGET_SHIFT  (0U)
/*! CPU_MODE_TARGET - The CPU mode the CPU platform should transit to on next sleep event
 *  0b00..Stay in RUN mode
 *  0b01..Transit to WAIT mode
 *  0b10..Transit to STOP mode
 *  0b11..Transit to SUSPEND mode
 */
#define GPC_CMC_MODE_CTRL_CPU_MODE_TARGET(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_CTRL_CPU_MODE_TARGET_SHIFT)) & GPC_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK)

#define GPC_CMC_MODE_CTRL_WFE_EN_MASK            (0x10U)
#define GPC_CMC_MODE_CTRL_WFE_EN_SHIFT           (4U)
/*! WFE_EN - WFE assertion can be sleep event
 *  0b0..WFE assertion can not trigger low power
 *  0b1..WFE assertion can trigger low power
 */
#define GPC_CMC_MODE_CTRL_WFE_EN(x)              (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_CTRL_WFE_EN_SHIFT)) & GPC_CMC_MODE_CTRL_WFE_EN_MASK)
/*! @} */

/*! @name CMC_MODE_STAT - CPU mode Status */
/*! @{ */

#define GPC_CMC_MODE_STAT_CPU_MODE_CURRENT_MASK  (0x3U)
#define GPC_CMC_MODE_STAT_CPU_MODE_CURRENT_SHIFT (0U)
/*! CPU_MODE_CURRENT - Current CPU mode
 *  0b00..CPU is currently in RUN mode
 *  0b01..CPU is currently in WAIT mode
 *  0b10..CPU is currently in STOP mode
 *  0b11..CPU is currently in SUSPEND mode
 */
#define GPC_CMC_MODE_STAT_CPU_MODE_CURRENT(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_CPU_MODE_CURRENT_SHIFT)) & GPC_CMC_MODE_STAT_CPU_MODE_CURRENT_MASK)

#define GPC_CMC_MODE_STAT_CPU_MODE_PREVIOUS_MASK (0xCU)
#define GPC_CMC_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT (2U)
/*! CPU_MODE_PREVIOUS - Previous CPU mode
 *  0b00..CPU was previously in RUN mode
 *  0b01..CPU was previously in WAIT mode
 *  0b10..CPU was previously in STOP mode
 *  0b11..CPU was previously in SUSPEND mode
 */
#define GPC_CMC_MODE_STAT_CPU_MODE_PREVIOUS(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT)) & GPC_CMC_MODE_STAT_CPU_MODE_PREVIOUS_MASK)

#define GPC_CMC_MODE_STAT_SLEEP_TRANS_BUSY_MASK  (0x100U)
#define GPC_CMC_MODE_STAT_SLEEP_TRANS_BUSY_SHIFT (8U)
/*! SLEEP_TRANS_BUSY - Busy on CPU mode transition of sleep, not include set point trans busy.
 *  0b0..Sleep transition not busy
 *  0b1..Sleep transition busy
 */
#define GPC_CMC_MODE_STAT_SLEEP_TRANS_BUSY(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_SLEEP_TRANS_BUSY_SHIFT)) & GPC_CMC_MODE_STAT_SLEEP_TRANS_BUSY_MASK)

#define GPC_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_MASK (0x200U)
#define GPC_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_SHIFT (9U)
/*! WAKEUP_TRANS_BUSY - Busy on CPU mode transition of wakeup, not include set point trans busy.
 *  0b1..Wakeup transition busy
 *  0b0..Wakeup transition not busy
 */
#define GPC_CMC_MODE_STAT_WAKEUP_TRANS_BUSY(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_SHIFT)) & GPC_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_MASK)

#define GPC_CMC_MODE_STAT_SLEEPING_IDLE_MASK     (0x400U)
#define GPC_CMC_MODE_STAT_SLEEPING_IDLE_SHIFT    (10U)
/*! SLEEPING_IDLE - Completed CPU mode and set point transition of sleep sequence, in a sleeping_idle state.
 *  0b1..In sleeping idle state
 *  0b0..Not in sleeping idle state
 */
#define GPC_CMC_MODE_STAT_SLEEPING_IDLE(x)       (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_SLEEPING_IDLE_SHIFT)) & GPC_CMC_MODE_STAT_SLEEPING_IDLE_MASK)

#define GPC_CMC_MODE_STAT_SLEEP_REQUEST_MASK     (0x10000U)
#define GPC_CMC_MODE_STAT_SLEEP_REQUEST_SHIFT    (16U)
/*! SLEEP_REQUEST - Status of sleep_request input port
 *  0b1..Sleep request is asserted
 *  0b0..Sleep request is not asserted
 */
#define GPC_CMC_MODE_STAT_SLEEP_REQUEST(x)       (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_SLEEP_REQUEST_SHIFT)) & GPC_CMC_MODE_STAT_SLEEP_REQUEST_MASK)

#define GPC_CMC_MODE_STAT_WFE_REQUEST_MASK       (0x20000U)
#define GPC_CMC_MODE_STAT_WFE_REQUEST_SHIFT      (17U)
/*! WFE_REQUEST - Status of standby_wfe input port
 *  0b0..WFE request is not asserted
 *  0b1..WFE request is asserted
 */
#define GPC_CMC_MODE_STAT_WFE_REQUEST(x)         (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_WFE_REQUEST_SHIFT)) & GPC_CMC_MODE_STAT_WFE_REQUEST_MASK)

#define GPC_CMC_MODE_STAT_WAKEUP_REQUEST_MASK    (0x40000U)
#define GPC_CMC_MODE_STAT_WAKEUP_REQUEST_SHIFT   (18U)
/*! WAKEUP_REQUEST - "ORed" of all unmasked IRQ */
#define GPC_CMC_MODE_STAT_WAKEUP_REQUEST(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_WAKEUP_REQUEST_SHIFT)) & GPC_CMC_MODE_STAT_WAKEUP_REQUEST_MASK)

#define GPC_CMC_MODE_STAT_FSM_STATE_MASK         (0x1F000000U)
#define GPC_CMC_MODE_STAT_FSM_STATE_SHIFT        (24U)
/*! FSM_STATE - CPU mode trans FSM state.
 *  0b00010..SLEEP_SYSMAN
 *  0b00000..IDLE_RUN
 *  0b00001..SLEEP_A55_HDSK
 *  0b00011..SLEEP_SSAR
 *  0b01000..SLEEP_RESET
 *  0b01011..SLEEP_SYS
 *  0b01100..IDLE_SLEEP
 *  0b01101..WAKEUP_SYS
 *  0b01111..WAKEUP_POWER
 *  0b10110..WAKEUP_SSAR
 *  0b10111..WAKEUP_SYSMAN
 *  0b11000..WAKEUP_A55_HDSK
 */
#define GPC_CMC_MODE_STAT_FSM_STATE(x)           (((uint32_t)(((uint32_t)(x)) << GPC_CMC_MODE_STAT_FSM_STATE_SHIFT)) & GPC_CMC_MODE_STAT_FSM_STATE_MASK)
/*! @} */

/*! @name CMC_PIN_STAT - CMC pin Status */
/*! @{ */

#define GPC_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_MASK (0x1U)
#define GPC_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_SHIFT (0U)
/*! A55_HDSK_REQUEST_STAT - cpu_mode_trans_a55_hdsk_request pin status */
#define GPC_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_SHIFT)) & GPC_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_MASK)

#define GPC_CMC_PIN_STAT_SSAR_REQUEST_STAT_MASK  (0x2U)
#define GPC_CMC_PIN_STAT_SSAR_REQUEST_STAT_SHIFT (1U)
/*! SSAR_REQUEST_STAT - cpu_mode_trans_ssar_request pin status */
#define GPC_CMC_PIN_STAT_SSAR_REQUEST_STAT(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_SSAR_REQUEST_STAT_SHIFT)) & GPC_CMC_PIN_STAT_SSAR_REQUEST_STAT_MASK)

#define GPC_CMC_PIN_STAT_RESET_REQUEST_STAT_MASK (0x40U)
#define GPC_CMC_PIN_STAT_RESET_REQUEST_STAT_SHIFT (6U)
/*! RESET_REQUEST_STAT - cpu_mode_trans_reset_request pin status */
#define GPC_CMC_PIN_STAT_RESET_REQUEST_STAT(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_RESET_REQUEST_STAT_SHIFT)) & GPC_CMC_PIN_STAT_RESET_REQUEST_STAT_MASK)

#define GPC_CMC_PIN_STAT_POWER_REQUEST_STAT_MASK (0x80U)
#define GPC_CMC_PIN_STAT_POWER_REQUEST_STAT_SHIFT (7U)
/*! POWER_REQUEST_STAT - cpu_mode_trans_power_request pin status */
#define GPC_CMC_PIN_STAT_POWER_REQUEST_STAT(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_POWER_REQUEST_STAT_SHIFT)) & GPC_CMC_PIN_STAT_POWER_REQUEST_STAT_MASK)

#define GPC_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_MASK (0x200U)
#define GPC_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_SHIFT (9U)
/*! SYSMAN_REQUEST_STAT - cpu_mode_trans_sysman_request pin status */
#define GPC_CMC_PIN_STAT_SYSMAN_REQUEST_STAT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_SHIFT)) & GPC_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_MASK)

#define GPC_CMC_PIN_STAT_A55_HDSK_DONE_STAT_MASK (0x10000U)
#define GPC_CMC_PIN_STAT_A55_HDSK_DONE_STAT_SHIFT (16U)
/*! A55_HDSK_DONE_STAT - cpu_mode_trans_a55_hdsk_done pin status */
#define GPC_CMC_PIN_STAT_A55_HDSK_DONE_STAT(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_A55_HDSK_DONE_STAT_SHIFT)) & GPC_CMC_PIN_STAT_A55_HDSK_DONE_STAT_MASK)

#define GPC_CMC_PIN_STAT_SSAR_DONE_STAT_MASK     (0x20000U)
#define GPC_CMC_PIN_STAT_SSAR_DONE_STAT_SHIFT    (17U)
/*! SSAR_DONE_STAT - cpu_mode_trans_ssar_done pin status */
#define GPC_CMC_PIN_STAT_SSAR_DONE_STAT(x)       (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_SSAR_DONE_STAT_SHIFT)) & GPC_CMC_PIN_STAT_SSAR_DONE_STAT_MASK)

#define GPC_CMC_PIN_STAT_RESET_DONE_STAT_MASK    (0x400000U)
#define GPC_CMC_PIN_STAT_RESET_DONE_STAT_SHIFT   (22U)
/*! RESET_DONE_STAT - cpu_mode_trans_reset_done pin status */
#define GPC_CMC_PIN_STAT_RESET_DONE_STAT(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_RESET_DONE_STAT_SHIFT)) & GPC_CMC_PIN_STAT_RESET_DONE_STAT_MASK)

#define GPC_CMC_PIN_STAT_POWER_DONE_STAT_MASK    (0x800000U)
#define GPC_CMC_PIN_STAT_POWER_DONE_STAT_SHIFT   (23U)
/*! POWER_DONE_STAT - cpu_mode_trans_power_done pin status */
#define GPC_CMC_PIN_STAT_POWER_DONE_STAT(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_POWER_DONE_STAT_SHIFT)) & GPC_CMC_PIN_STAT_POWER_DONE_STAT_MASK)

#define GPC_CMC_PIN_STAT_SYSMAN_DONE_STAT_MASK   (0x2000000U)
#define GPC_CMC_PIN_STAT_SYSMAN_DONE_STAT_SHIFT  (25U)
/*! SYSMAN_DONE_STAT - cpu_mode_trans_sysman_done pin status. */
#define GPC_CMC_PIN_STAT_SYSMAN_DONE_STAT(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_SYSMAN_DONE_STAT_SHIFT)) & GPC_CMC_PIN_STAT_SYSMAN_DONE_STAT_MASK)

#define GPC_CMC_PIN_STAT_CPU_MODE_STAT_MASK      (0x60000000U)
#define GPC_CMC_PIN_STAT_CPU_MODE_STAT_SHIFT     (29U)
/*! CPU_MODE_STAT - cpu_power_mode pin status
 *  0b00..RUN mode
 *  0b01..WAIT mode
 *  0b10..STOP mode
 *  0b11..SUSPEND mode
 */
#define GPC_CMC_PIN_STAT_CPU_MODE_STAT(x)        (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_CPU_MODE_STAT_SHIFT)) & GPC_CMC_PIN_STAT_CPU_MODE_STAT_MASK)

#define GPC_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_MASK (0x80000000U)
#define GPC_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_SHIFT (31U)
/*! DEBUG_WAKEUP_ACK_STAT - Debug wakeup acknowledge pin status */
#define GPC_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_SHIFT)) & GPC_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_MASK)
/*! @} */

/*! @name CMC_IRQ_WAKEUP_MASK - IRQ wake-up mask register */
/*! @{ */

#define GPC_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_MASK (0xFFFFFFFFU)
#define GPC_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_SHIFT (0U)
/*! IRQ_WAKEUP_MASK - IRQ Wake-up mask */
#define GPC_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_SHIFT)) & GPC_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_MASK)
/*! @} */

/* The count of GPC_CMC_IRQ_WAKEUP_MASK */
#define GPC_CMC_IRQ_WAKEUP_MASK_COUNT            (12U)

/*! @name CMC_NON_IRQ_WAKEUP_MASK - CMC non-IRQ wakeup mask */
/*! @{ */

#define GPC_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_MASK (0x1U)
#define GPC_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_SHIFT (0U)
/*! EVENT_WAKEUP_MASK - "1" means the event cannot wakeup CPU platform */
#define GPC_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_SHIFT)) & GPC_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_MASK)

#define GPC_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK (0x2U)
#define GPC_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT (1U)
/*! DEBUG_WAKEUP_MASK - "1" means the debug_wakeup_request cannot wakeup CPU platform */
#define GPC_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT)) & GPC_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK)
/*! @} */

/*! @name CMC_IRQ_WAKEUP_STAT - IRQ status register */
/*! @{ */

#define GPC_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_MASK (0xFFFFFFFFU)
#define GPC_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_SHIFT (0U)
/*! IRQ_WAKEUP_STAT - IRQ status */
#define GPC_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_SHIFT)) & GPC_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_MASK)
/*! @} */

/* The count of GPC_CMC_IRQ_WAKEUP_STAT */
#define GPC_CMC_IRQ_WAKEUP_STAT_COUNT            (12U)

/*! @name CMC_NON_IRQ_WAKEUP_STAT - CMC non-IRQ wakeup status */
/*! @{ */

#define GPC_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_MASK (0x1U)
#define GPC_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_SHIFT (0U)
/*! EVENT_WAKEUP_STAT - Event wakeup status
 *  0b0..No event wakeup is requested
 *  0b1..Event wakeup is requested
 */
#define GPC_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_SHIFT)) & GPC_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_MASK)

#define GPC_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK (0x2U)
#define GPC_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT (1U)
/*! DEBUG_WAKEUP_STAT - Debug wakeup status
 *  0b0..No debug wakeup is requested
 *  0b1..Debug wakeup is requested
 */
#define GPC_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT)) & GPC_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK)
/*! @} */

/*! @name CMC_SLEEP_A55_HDSK_CTRL - CMC sleep A55_HDSK control */
/*! @{ */

#define GPC_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE. */
#define GPC_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_MASK)

#define GPC_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_MASK)

#define GPC_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_SLEEP_A55_HDSK_CTRL_DISABLE(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_SHIFT)) & GPC_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_A55_HDSK_STAT - CMC sleep A55_HDSK status */
/*! @{ */

#define GPC_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_SHIFT)) & GPC_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_SSAR_CTRL - CMC sleep SSAR control */
/*! @{ */

#define GPC_CMC_SLEEP_SSAR_CTRL_STEP_CNT_MASK    (0xFFFFFFU)
#define GPC_CMC_SLEEP_SSAR_CTRL_STEP_CNT_SHIFT   (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE. */
#define GPC_CMC_SLEEP_SSAR_CTRL_STEP_CNT(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SSAR_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_SLEEP_SSAR_CTRL_STEP_CNT_MASK)

#define GPC_CMC_SLEEP_SSAR_CTRL_CNT_MODE_MASK    (0x30000000U)
#define GPC_CMC_SLEEP_SSAR_CTRL_CNT_MODE_SHIFT   (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_SLEEP_SSAR_CTRL_CNT_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SSAR_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_SLEEP_SSAR_CTRL_CNT_MODE_MASK)

#define GPC_CMC_SLEEP_SSAR_CTRL_DISABLE_MASK     (0x80000000U)
#define GPC_CMC_SLEEP_SSAR_CTRL_DISABLE_SHIFT    (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_SLEEP_SSAR_CTRL_DISABLE(x)       (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CMC_SLEEP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_SSAR_STAT - CMC sleep SSAR status */
/*! @{ */

#define GPC_CMC_SLEEP_SSAR_STAT_RSP_CNT_MASK     (0xFFFFFFU)
#define GPC_CMC_SLEEP_SSAR_STAT_RSP_CNT_SHIFT    (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_SLEEP_SSAR_STAT_RSP_CNT(x)       (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SSAR_STAT_RSP_CNT_SHIFT)) & GPC_CMC_SLEEP_SSAR_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_RESET_CTRL - CMC sleep reset control */
/*! @{ */

#define GPC_CMC_SLEEP_RESET_CTRL_STEP_CNT_MASK   (0xFFFFFFU)
#define GPC_CMC_SLEEP_RESET_CTRL_STEP_CNT_SHIFT  (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE */
#define GPC_CMC_SLEEP_RESET_CTRL_STEP_CNT(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_RESET_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_SLEEP_RESET_CTRL_STEP_CNT_MASK)

#define GPC_CMC_SLEEP_RESET_CTRL_CNT_MODE_MASK   (0x30000000U)
#define GPC_CMC_SLEEP_RESET_CTRL_CNT_MODE_SHIFT  (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_SLEEP_RESET_CTRL_CNT_MODE(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_RESET_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_SLEEP_RESET_CTRL_CNT_MODE_MASK)

#define GPC_CMC_SLEEP_RESET_CTRL_DISABLE_MASK    (0x80000000U)
#define GPC_CMC_SLEEP_RESET_CTRL_DISABLE_SHIFT   (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_SLEEP_RESET_CTRL_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CMC_SLEEP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_RESET_STAT - CMC sleep reset status */
/*! @{ */

#define GPC_CMC_SLEEP_RESET_STAT_RSP_CNT_MASK    (0xFFFFFFU)
#define GPC_CMC_SLEEP_RESET_STAT_RSP_CNT_SHIFT   (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_SLEEP_RESET_STAT_RSP_CNT(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_RESET_STAT_RSP_CNT_SHIFT)) & GPC_CMC_SLEEP_RESET_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_SYSMAN_CTRL - CMC sleep Sysman control */
/*! @{ */

#define GPC_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_MASK  (0xFFFFFFU)
#define GPC_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE. */
#define GPC_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_MASK)

#define GPC_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_MASK  (0x30000000U)
#define GPC_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_MASK)

#define GPC_CMC_SLEEP_SYSMAN_CTRL_DISABLE_MASK   (0x80000000U)
#define GPC_CMC_SLEEP_SYSMAN_CTRL_DISABLE_SHIFT  (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_SLEEP_SYSMAN_CTRL_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SYSMAN_CTRL_DISABLE_SHIFT)) & GPC_CMC_SLEEP_SYSMAN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_SYSMAN_STAT - CMC Sleep Sysman status */
/*! @{ */

#define GPC_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_MASK   (0xFFFFFFU)
#define GPC_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_SHIFT  (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_SLEEP_SYSMAN_STAT_RSP_CNT(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_SHIFT)) & GPC_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_POWER_CTRL - CMC wakeup power control */
/*! @{ */

#define GPC_CMC_WAKEUP_POWER_CTRL_STEP_CNT_MASK  (0xFFFFFFU)
#define GPC_CMC_WAKEUP_POWER_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE */
#define GPC_CMC_WAKEUP_POWER_CTRL_STEP_CNT(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_POWER_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_WAKEUP_POWER_CTRL_STEP_CNT_MASK)

#define GPC_CMC_WAKEUP_POWER_CTRL_CNT_MODE_MASK  (0x30000000U)
#define GPC_CMC_WAKEUP_POWER_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_WAKEUP_POWER_CTRL_CNT_MODE(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_POWER_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_WAKEUP_POWER_CTRL_CNT_MODE_MASK)

#define GPC_CMC_WAKEUP_POWER_CTRL_DISABLE_MASK   (0x80000000U)
#define GPC_CMC_WAKEUP_POWER_CTRL_DISABLE_SHIFT  (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_WAKEUP_POWER_CTRL_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CMC_WAKEUP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_POWER_STAT - CMC wakeup power status */
/*! @{ */

#define GPC_CMC_WAKEUP_POWER_STAT_RSP_CNT_MASK   (0xFFFFFFU)
#define GPC_CMC_WAKEUP_POWER_STAT_RSP_CNT_SHIFT  (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_WAKEUP_POWER_STAT_RSP_CNT(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_POWER_STAT_RSP_CNT_SHIFT)) & GPC_CMC_WAKEUP_POWER_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SSAR_CTRL - CMC wakeup SSAR control */
/*! @{ */

#define GPC_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_MASK   (0xFFFFFFU)
#define GPC_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_SHIFT  (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE */
#define GPC_CMC_WAKEUP_SSAR_CTRL_STEP_CNT(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_MASK)

#define GPC_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_MASK   (0x30000000U)
#define GPC_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_SHIFT  (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_WAKEUP_SSAR_CTRL_CNT_MODE(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_MASK)

#define GPC_CMC_WAKEUP_SSAR_CTRL_DISABLE_MASK    (0x80000000U)
#define GPC_CMC_WAKEUP_SSAR_CTRL_DISABLE_SHIFT   (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_WAKEUP_SSAR_CTRL_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CMC_WAKEUP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SSAR_STAT - CMC wakeup SSAR status */
/*! @{ */

#define GPC_CMC_WAKEUP_SSAR_STAT_RSP_CNT_MASK    (0xFFFFFFU)
#define GPC_CMC_WAKEUP_SSAR_STAT_RSP_CNT_SHIFT   (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_WAKEUP_SSAR_STAT_RSP_CNT(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SSAR_STAT_RSP_CNT_SHIFT)) & GPC_CMC_WAKEUP_SSAR_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_A55_HDSK_CTRL - CMC wakeup A55_HDSK control */
/*! @{ */

#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE */
#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_MASK)

#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_MASK)

#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_SHIFT)) & GPC_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_A55_HDSK_STAT - CMC wakeup A55_HDSK status */
/*! @{ */

#define GPC_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_SHIFT)) & GPC_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SYSMAN_CTRL - CMC wakeup Sysman control */
/*! @{ */

#define GPC_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - (invalid when CNT_MODE==0 and invisible on customer RM)Step count, usage depends on CNT_MODE */
#define GPC_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_SHIFT)) & GPC_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_MASK)

#define GPC_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - (keep==0 and invisible on customer RM)Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_SHIFT)) & GPC_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_MASK)

#define GPC_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_MASK  (0x80000000U)
#define GPC_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CMC_WAKEUP_SYSMAN_CTRL_DISABLE(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_SHIFT)) & GPC_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SYSMAN_STAT - CMC wakeup Sysman status */
/*! @{ */

#define GPC_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_MASK  (0xFFFFFFU)
#define GPC_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_SHIFT)) & GPC_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SYS_SLEEP_CTRL - CMC system sleep control */
/*! @{ */

#define GPC_CMC_SYS_SLEEP_CTRL_SS_WAIT_MASK      (0x1U)
#define GPC_CMC_SYS_SLEEP_CTRL_SS_WAIT_SHIFT     (0U)
/*! SS_WAIT - Request system sleep when CPU is in WAIT mode
 *  0b0..Do not request system sleep when CPU is in WAIT mode
 *  0b1..Request system sleep when CPU is in WAIT mode
 */
#define GPC_CMC_SYS_SLEEP_CTRL_SS_WAIT(x)        (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SYS_SLEEP_CTRL_SS_WAIT_SHIFT)) & GPC_CMC_SYS_SLEEP_CTRL_SS_WAIT_MASK)

#define GPC_CMC_SYS_SLEEP_CTRL_SS_STOP_MASK      (0x2U)
#define GPC_CMC_SYS_SLEEP_CTRL_SS_STOP_SHIFT     (1U)
/*! SS_STOP - Request system sleep when CPU is in STOP mode
 *  0b0..Do not request system sleep when CPU is in STOP mode
 *  0b1..Request system sleep when CPU is in STOP mode
 */
#define GPC_CMC_SYS_SLEEP_CTRL_SS_STOP(x)        (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SYS_SLEEP_CTRL_SS_STOP_SHIFT)) & GPC_CMC_SYS_SLEEP_CTRL_SS_STOP_MASK)

#define GPC_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK   (0x4U)
#define GPC_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT  (2U)
/*! SS_SUSPEND - Request system sleep when CPU is in SUSPEND mode
 *  0b0..Do not request system sleep when CPU is in SUSPEND mode
 *  0b1..Request system sleep when CPU is in SUSPEND mode
 */
#define GPC_CMC_SYS_SLEEP_CTRL_SS_SUSPEND(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT)) & GPC_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK)

#define GPC_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_MASK (0x10000U)
#define GPC_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_SHIFT (16U)
/*! SYS_SLEEP_BUSY - Indicates the CPU is busy entering system sleep mode. */
#define GPC_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_SHIFT)) & GPC_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_MASK)

#define GPC_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_MASK (0x20000U)
#define GPC_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_SHIFT (17U)
/*! SYS_WAKEUP_BUSY - Indicates the CPU is busy exiting system sleep mode. */
#define GPC_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_SHIFT)) & GPC_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_MASK)
/*! @} */

/*! @name CMC_DEBUG - CMC debug */
/*! @{ */

#define GPC_CMC_DEBUG_PRETEND_SLEEP_MASK         (0x1U)
#define GPC_CMC_DEBUG_PRETEND_SLEEP_SHIFT        (0U)
/*! PRETEND_SLEEP - Write 1 to force CMC into sleep. Used to debug GPC status. Locked by LOCK_CFG field. */
#define GPC_CMC_DEBUG_PRETEND_SLEEP(x)           (((uint32_t)(((uint32_t)(x)) << GPC_CMC_DEBUG_PRETEND_SLEEP_SHIFT)) & GPC_CMC_DEBUG_PRETEND_SLEEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_Peripheral_Access_Layer */


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


#endif  /* GPC_H_ */

