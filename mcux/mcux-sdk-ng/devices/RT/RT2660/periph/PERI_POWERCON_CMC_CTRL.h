/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for POWERCON_CMC_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_POWERCON_CMC_CTRL.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for POWERCON_CMC_CTRL
 *
 * CMSIS Peripheral Access Layer for POWERCON_CMC_CTRL
 */

#if !defined(PERI_POWERCON_CMC_CTRL_H_)
#define PERI_POWERCON_CMC_CTRL_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- POWERCON_CMC_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERCON_CMC_CTRL_Peripheral_Access_Layer POWERCON_CMC_CTRL Peripheral Access Layer
 * @{
 */

/** POWERCON_CMC_CTRL - Size of Registers Arrays */
#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_COUNT   2u
#define POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_COUNT   12u

/** POWERCON_CMC_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t ACCESS_CTRL;                       /**< Global Access Control, offset: 0x0 */
  __IO uint32_t CMC_CTRL;                          /**< CPU Mode Control, offset: 0x4 */
  __I  uint32_t CMC_STATUS;                        /**< CMC Status, offset: 0x8 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CMC_STEP_CNT_MODE;                 /**< CMC Step Counter Mode, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMC_STEP_CNT;                      /**< Step Counter Setting, offset: 0x1C */
       uint8_t RESERVED_2[96];
  __IO uint32_t DMA_WAKEUP_MASK[POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_COUNT]; /**< DMA Wake-Up Mask 0..DMA Wake-Up Mask 1, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_3[120];
  __IO uint32_t IRQ_WAKEUP_MASK[POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_COUNT]; /**< IRQ Wake-Up Mask 0..IRQ Wake-Up Mask 11, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_4[16];
  __IO uint32_t NON_IRQ_CS;                        /**< Non-IRQ Wake-Up Control and Status, offset: 0x140 */
} POWERCON_CMC_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- POWERCON_CMC_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERCON_CMC_CTRL_Register_Masks POWERCON_CMC_CTRL Register Masks
 * @{
 */

/*! @name ACCESS_CTRL - Global Access Control */
/*! @{ */

#define POWERCON_CMC_CTRL_ACCESS_CTRL_ALLOW_ACCESS_MASK (0xFU)
#define POWERCON_CMC_CTRL_ACCESS_CTRL_ALLOW_ACCESS_SHIFT (0U)
/*! ALLOW_ACCESS - Configuration Lock */
#define POWERCON_CMC_CTRL_ACCESS_CTRL_ALLOW_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_ACCESS_CTRL_ALLOW_ACCESS_SHIFT)) & POWERCON_CMC_CTRL_ACCESS_CTRL_ALLOW_ACCESS_MASK)

#define POWERCON_CMC_CTRL_ACCESS_CTRL_USER_MASK  (0x10000U)
#define POWERCON_CMC_CTRL_ACCESS_CTRL_USER_SHIFT (16U)
/*! USER - User Mode Access
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_CMC_CTRL_ACCESS_CTRL_USER(x)    (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_ACCESS_CTRL_USER_SHIFT)) & POWERCON_CMC_CTRL_ACCESS_CTRL_USER_MASK)

#define POWERCON_CMC_CTRL_ACCESS_CTRL_NONSECURE_MASK (0x20000U)
#define POWERCON_CMC_CTRL_ACCESS_CTRL_NONSECURE_SHIFT (17U)
/*! NONSECURE - Non-Secure Mode Access
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_CMC_CTRL_ACCESS_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_ACCESS_CTRL_NONSECURE_SHIFT)) & POWERCON_CMC_CTRL_ACCESS_CTRL_NONSECURE_MASK)

#define POWERCON_CMC_CTRL_ACCESS_CTRL_LOCK_MASK  (0x80000000U)
#define POWERCON_CMC_CTRL_ACCESS_CTRL_LOCK_SHIFT (31U)
/*! LOCK - White List Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define POWERCON_CMC_CTRL_ACCESS_CTRL_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_ACCESS_CTRL_LOCK_SHIFT)) & POWERCON_CMC_CTRL_ACCESS_CTRL_LOCK_MASK)
/*! @} */

/*! @name CMC_CTRL - CPU Mode Control */
/*! @{ */

#define POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK (0x1U)
#define POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_SHIFT (0U)
/*! SLEEP_HOLD_EN - Sleep Hold Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_SHIFT)) & POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK)

#define POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP_MASK (0x2U)
#define POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP_SHIFT (1U)
/*! PRETEND_SLEEP - Pretend Sleep
 *  0b0..Disables
 *  0b1..Forces CMC into sleep
 */
#define POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP_SHIFT)) & POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP_MASK)

#define POWERCON_CMC_CTRL_CMC_CTRL_TRIGGER_SS_MASK (0x4U)
#define POWERCON_CMC_CTRL_CMC_CTRL_TRIGGER_SS_SHIFT (2U)
/*! TRIGGER_SS - Trigger Sleep
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_CMC_CTRL_CMC_CTRL_TRIGGER_SS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_CTRL_TRIGGER_SS_SHIFT)) & POWERCON_CMC_CTRL_CMC_CTRL_TRIGGER_SS_MASK)

#define POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP_MASK (0x8U)
#define POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP_SHIFT (3U)
/*! SW_ALLOW_LP - Software Low-Power
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP_SHIFT)) & POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP_MASK)
/*! @} */

/*! @name CMC_STATUS - CMC Status */
/*! @{ */

#define POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_HOLD_STAT_MASK (0x1U)
#define POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_HOLD_STAT_SHIFT (0U)
/*! SLEEP_HOLD_STAT - CPU Sleep Hold State
 *  0b0..Not in Sleep Hold state
 *  0b1..In Sleep Hold state
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_HOLD_STAT(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_HOLD_STAT_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_HOLD_STAT_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_NMI_STAT_MASK (0x2U)
#define POWERCON_CMC_CTRL_CMC_STATUS_NMI_STAT_SHIFT (1U)
/*! NMI_STAT - Non-Masked Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_NMI_STAT(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_NMI_STAT_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_NMI_STAT_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_BUSY_MASK (0x100U)
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_BUSY_SHIFT (8U)
/*! CMC_SLEEP_BUSY - CMC Sleep Busy
 *  0b0..Not busy
 *  0b1..Busy
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_BUSY_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_BUSY_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_WAKEUP_BUSY_MASK (0x200U)
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_WAKEUP_BUSY_SHIFT (9U)
/*! CMC_WAKEUP_BUSY - CMC Wake-Up Busy
 *  0b0..Not busy
 *  0b1..Busy
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_WAKEUP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_CMC_WAKEUP_BUSY_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_CMC_WAKEUP_BUSY_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_IDLE_MASK (0x400U)
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_IDLE_SHIFT (10U)
/*! CMC_SLEEP_IDLE - CMC Sleep Idle
 *  0b0..Not in Sleep Idle state
 *  0b1..In Sleep Idle state
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_IDLE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_IDLE_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_IDLE_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_POWER_MODE_MASK (0x800U)
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_POWER_MODE_SHIFT (11U)
/*! CMC_POWER_MODE - CMC Power Mode
 *  0b0..Active state
 *  0b1..Standby state
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_CMC_POWER_MODE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_CMC_POWER_MODE_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_CMC_POWER_MODE_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_REQUEST_MASK (0x10000U)
#define POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_REQUEST_SHIFT (16U)
/*! SLEEP_REQUEST - Sleep Request */
#define POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_REQUEST_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_SLEEP_REQUEST_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_WAKEUP_REQUEST_MASK (0x20000U)
#define POWERCON_CMC_CTRL_CMC_STATUS_WAKEUP_REQUEST_SHIFT (17U)
/*! WAKEUP_REQUEST - Wake-Up Request
 *  0b0..No wake-up event
 *  0b1..Wake-Up event occurred
 */
#define POWERCON_CMC_CTRL_CMC_STATUS_WAKEUP_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_WAKEUP_REQUEST_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_WAKEUP_REQUEST_MASK)

#define POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE_MASK (0x1F000000U)
#define POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE_SHIFT (24U)
/*! FSM_STATE - CMC/DMC FSM State */
#define POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE_SHIFT)) & POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE_MASK)
/*! @} */

/*! @name CMC_STEP_CNT_MODE - CMC Step Counter Mode */
/*! @{ */

#define POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_SLEEP_COUNT_MODE_MASK (0x1FU)
#define POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_SLEEP_COUNT_MODE_SHIFT (0U)
/*! SLEEP_COUNT_MODE - Sleep Count Mode */
#define POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_SLEEP_COUNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_SLEEP_COUNT_MODE_SHIFT)) & POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_SLEEP_COUNT_MODE_MASK)

#define POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_WAKEUP_COUNT_MODE_MASK (0x1F0000U)
#define POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_WAKEUP_COUNT_MODE_SHIFT (16U)
/*! WAKEUP_COUNT_MODE - Wake-Up Count Mode */
#define POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_WAKEUP_COUNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_WAKEUP_COUNT_MODE_SHIFT)) & POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_WAKEUP_COUNT_MODE_MASK)
/*! @} */

/*! @name CMC_STEP_CNT - Step Counter Setting */
/*! @{ */

#define POWERCON_CMC_CTRL_CMC_STEP_CNT_COUNT_MASK (0xFFFFFFU)
#define POWERCON_CMC_CTRL_CMC_STEP_CNT_COUNT_SHIFT (0U)
/*! COUNT - Step Counter Settings */
#define POWERCON_CMC_CTRL_CMC_STEP_CNT_COUNT(x)  (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_CMC_STEP_CNT_COUNT_SHIFT)) & POWERCON_CMC_CTRL_CMC_STEP_CNT_COUNT_MASK)
/*! @} */

/*! @name DMA_WAKEUP_MASK - DMA Wake-Up Mask 0..DMA Wake-Up Mask 1 */
/*! @{ */

#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_31_0_MASK (0xFFFFFFFFU)
#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_31_0_SHIFT (0U)
/*! DMA_WAKEUP_MASK_31_0 - DMA Wake-Up Mask Bits [31:0] */
#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_31_0(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_31_0_SHIFT)) & POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_31_0_MASK)

#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_63_32_MASK (0xFFFFFFFFU)
#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_63_32_SHIFT (0U)
/*! DMA_WAKEUP_MASK_63_32 - DMA Wake-Up Mask Bits [63:32] */
#define POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_63_32(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_63_32_SHIFT)) & POWERCON_CMC_CTRL_DMA_WAKEUP_MASK_DMA_WAKEUP_MASK_63_32_MASK)
/*! @} */

/*! @name IRQ_WAKEUP_MASK - IRQ Wake-Up Mask 0..IRQ Wake-Up Mask 11 */
/*! @{ */

#define POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_31_0_MASK (0xFFFFFFFFU)
#define POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_31_0_SHIFT (0U)
/*! IRQ_WAKEUP_MASK_31_0 - IRQ Wake-Up Mask Bits */
#define POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_31_0(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_31_0_SHIFT)) & POWERCON_CMC_CTRL_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_31_0_MASK)
/*! @} */

/*! @name NON_IRQ_CS - Non-IRQ Wake-Up Control and Status */
/*! @{ */

#define POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN_MASK (0x4U)
#define POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN_SHIFT (2U)
/*! DBG_EN - Debug Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN(x)   (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN_SHIFT)) & POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN_MASK)

#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK (0x8U)
#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_SHIFT (3U)
/*! CSSI_EN - CSSI Enable
 *  0b0..Bypass CSSI control
 *  0b1..Enables CSSI control low-power entry
 */
#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN(x)  (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_SHIFT)) & POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK)

#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_ALLOW_LP_STS_MASK (0x20000U)
#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_ALLOW_LP_STS_SHIFT (17U)
/*! CSSI_ALLOW_LP_STS - CSSI Allow Low-Power Status
 *  0b0..Not allow
 *  0b1..Allows
 */
#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_ALLOW_LP_STS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_ALLOW_LP_STS_SHIFT)) & POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_ALLOW_LP_STS_MASK)

#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_CTRL_LOCK_MASK (0x80000000U)
#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_CTRL_LOCK_SHIFT (31U)
/*! CSSI_CTRL_LOCK - CSSI Control Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_CTRL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_CTRL_LOCK_SHIFT)) & POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_CTRL_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group POWERCON_CMC_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group POWERCON_CMC_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_POWERCON_CMC_CTRL_H_ */

