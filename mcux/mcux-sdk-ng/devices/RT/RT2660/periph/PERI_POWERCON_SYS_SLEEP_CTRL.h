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
**         CMSIS Peripheral Access Layer for POWERCON_SYS_SLEEP_CTRL
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
 * @file PERI_POWERCON_SYS_SLEEP_CTRL.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for POWERCON_SYS_SLEEP_CTRL
 *
 * CMSIS Peripheral Access Layer for POWERCON_SYS_SLEEP_CTRL
 */

#if !defined(PERI_POWERCON_SYS_SLEEP_CTRL_H_)
#define PERI_POWERCON_SYS_SLEEP_CTRL_H_          /**< Symbol preventing repeated inclusion */

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
   -- POWERCON_SYS_SLEEP_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERCON_SYS_SLEEP_CTRL_Peripheral_Access_Layer POWERCON_SYS_SLEEP_CTRL Peripheral Access Layer
 * @{
 */

/** POWERCON_SYS_SLEEP_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t ACCESS_CTRL;                       /**< Global Access Control, offset: 0x0 */
  __IO uint32_t SYS_SLEEP_CTRL;                    /**< System Sleep Control, offset: 0x4 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SYS_SLEEP_STEP_CNT_MODE;           /**< System Sleep Step Counter Mode, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SYS_SLEEP_STEP_CNT;                /**< Step Counter Setting, offset: 0x1C */
} POWERCON_SYS_SLEEP_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- POWERCON_SYS_SLEEP_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERCON_SYS_SLEEP_CTRL_Register_Masks POWERCON_SYS_SLEEP_CTRL Register Masks
 * @{
 */

/*! @name ACCESS_CTRL - Global Access Control */
/*! @{ */

#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_ALLOW_ACCESS_MASK (0xFU)
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_ALLOW_ACCESS_SHIFT (0U)
/*! ALLOW_ACCESS - Configuration Lock */
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_ALLOW_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_ALLOW_ACCESS_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_ALLOW_ACCESS_MASK)

#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_USER_MASK (0x10000U)
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_USER_SHIFT (16U)
/*! USER - User Mode Access
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_USER(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_USER_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_USER_MASK)

#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_NONSECURE_MASK (0x20000U)
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_NONSECURE_SHIFT (17U)
/*! NONSECURE - Non-Secure Mode Access
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_NONSECURE_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_NONSECURE_MASK)

#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_LOCK_MASK (0x80000000U)
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_LOCK_SHIFT (31U)
/*! LOCK - White List Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_LOCK_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_ACCESS_CTRL_LOCK_MASK)
/*! @} */

/*! @name SYS_SLEEP_CTRL - System Sleep Control */
/*! @{ */

#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS_MASK (0x7U)
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS_SHIFT (0U)
/*! FORCE_SS - Force SSC Low-Power Entry
 *  0b1xx..Trigger for DMC1 (CMC2)
 *  0bx1x..Trigger for DMC0 (CMC1)
 *  0bxx1..Trigger for CMC0
 */
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS_MASK)

#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS_MASK (0x38U)
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS_SHIFT (3U)
/*! WKMASK_SS - Mask SSC Low-Power exit when wake-up
 *  0b1xx..DMC1 (CMC2) exit low-power will disable SSC wake-up
 *  0bx1x..DMC0 (CMC1) exit low-power will disable SSC wake-up
 *  0bxx1..CMC0 exit low-power will disable SSC wake-up
 */
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS_MASK)
/*! @} */

/*! @name SYS_SLEEP_STEP_CNT_MODE - System Sleep Step Counter Mode */
/*! @{ */

#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_SLEEP_COUNT_MODE_MASK (0x3U)
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_SLEEP_COUNT_MODE_SHIFT (0U)
/*! SLEEP_COUNT_MODE - Count mode for sleep steps of system sleep FSM */
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_SLEEP_COUNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_SLEEP_COUNT_MODE_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_SLEEP_COUNT_MODE_MASK)

#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_WAKEUP_COUNT_MODE_MASK (0x30000U)
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_WAKEUP_COUNT_MODE_SHIFT (16U)
/*! WAKEUP_COUNT_MODE - Count mode for wake-up steps of system sleep FSM */
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_WAKEUP_COUNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_WAKEUP_COUNT_MODE_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_WAKEUP_COUNT_MODE_MASK)
/*! @} */

/*! @name SYS_SLEEP_STEP_CNT - Step Counter Setting */
/*! @{ */

#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_COUNT_MASK (0xFFFFFFU)
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_COUNT_SHIFT (0U)
/*! COUNT - Step counter settings */
#define POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_COUNT_SHIFT)) & POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group POWERCON_SYS_SLEEP_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group POWERCON_SYS_SLEEP_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_POWERCON_SYS_SLEEP_CTRL_H_ */

