/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PGMC_BPC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PGMC_BPC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PGMC_BPC
 *
 * CMSIS Peripheral Access Layer for PGMC_BPC
 */

#if !defined(PERI_PGMC_BPC_H_)
#define PERI_PGMC_BPC_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PGMC_BPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGMC_BPC_Peripheral_Access_Layer PGMC_BPC Peripheral Access Layer
 * @{
 */

/** PGMC_BPC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t BPC_AUTHEN_CTRL;                   /**< BPC Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t BPC_MODE;                          /**< BPC Mode, offset: 0x10 */
  __IO uint32_t BPC_POWER_CTRL;                    /**< BPC power control, offset: 0x14 */
       uint8_t RESERVED_2[20];
  __IO uint32_t BPC_FLAG;                          /**< BPC flag, offset: 0x2C */
       uint8_t RESERVED_3[16];
  __IO uint32_t BPC_SSAR_SAVE_CTRL;                /**< BPC SSAR save control, offset: 0x40 */
  __IO uint32_t BPC_SSAR_RESTORE_CTRL;             /**< BPC SSAR restore control, offset: 0x44 */
} PGMC_BPC_Type;

/* ----------------------------------------------------------------------------
   -- PGMC_BPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGMC_BPC_Register_Masks PGMC_BPC Register Masks
 * @{
 */

/*! @name BPC_AUTHEN_CTRL - BPC Authentication Control */
/*! @{ */

#define PGMC_BPC_BPC_AUTHEN_CTRL_USER_MASK       (0x1U)
#define PGMC_BPC_BPC_AUTHEN_CTRL_USER_SHIFT      (0U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access basic power control registers
 *  0b1..Allow both privilege and user mode to access basic power control registers
 */
#define PGMC_BPC_BPC_AUTHEN_CTRL_USER(x)         (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_AUTHEN_CTRL_USER_SHIFT)) & PGMC_BPC_BPC_AUTHEN_CTRL_USER_MASK)

#define PGMC_BPC_BPC_AUTHEN_CTRL_NONSECURE_MASK  (0x2U)
#define PGMC_BPC_BPC_AUTHEN_CTRL_NONSECURE_SHIFT (1U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access basic power control registers
 *  0b1..Allow both secure and non-secure mode to access basic power control registers
 */
#define PGMC_BPC_BPC_AUTHEN_CTRL_NONSECURE(x)    (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_AUTHEN_CTRL_NONSECURE_SHIFT)) & PGMC_BPC_BPC_AUTHEN_CTRL_NONSECURE_MASK)

#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_SETTING_MASK (0x10U)
#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_SETTING_SHIFT (4U)
/*! LOCK_SETTING - Lock NONSECURE and USER */
#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_SETTING(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define PGMC_BPC_BPC_AUTHEN_CTRL_WHITE_LIST_MASK (0xF00U)
#define PGMC_BPC_BPC_AUTHEN_CTRL_WHITE_LIST_SHIFT (8U)
/*! WHITE_LIST - Domain ID white list */
#define PGMC_BPC_BPC_AUTHEN_CTRL_WHITE_LIST(x)   (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & PGMC_BPC_BPC_AUTHEN_CTRL_WHITE_LIST_MASK)

#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_LIST_MASK  (0x1000U)
#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_LIST_SHIFT (12U)
/*! LOCK_LIST - White list lock */
#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_LIST(x)    (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_LIST_MASK)

#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_CFG_MASK   (0x100000U)
#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_CFG_SHIFT  (20U)
/*! LOCK_CFG - Configuration lock */
#define PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_CFG(x)     (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & PGMC_BPC_BPC_AUTHEN_CTRL_LOCK_CFG_MASK)
/*! @} */

/*! @name BPC_MODE - BPC Mode */
/*! @{ */

#define PGMC_BPC_BPC_MODE_CTRL_MODE_MASK         (0x3U)
#define PGMC_BPC_BPC_MODE_CTRL_MODE_SHIFT        (0U)
/*! CTRL_MODE - Control mode. This field is locked by AUTHEN_CTRL[LOCK_CFG] field.
 *  0b00..Not affected by any low power mode
 *  0b01..Controlled by CPU power mode of the domain
 *  0b10..Controlled by Setpoint
 *  0b11..Reserved
 */
#define PGMC_BPC_BPC_MODE_CTRL_MODE(x)           (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_MODE_CTRL_MODE_SHIFT)) & PGMC_BPC_BPC_MODE_CTRL_MODE_MASK)

#define PGMC_BPC_BPC_MODE_DOMAIN_ASSIGN_MASK     (0x30U)
#define PGMC_BPC_BPC_MODE_DOMAIN_ASSIGN_SHIFT    (4U)
/*! DOMAIN_ASSIGN - Domain assignment of the BPC
 *  0b00..Domain 0
 *  0b01..Domain 1
 *  0b10..Domain 2
 *  0b11..Domain 3
 */
#define PGMC_BPC_BPC_MODE_DOMAIN_ASSIGN(x)       (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_MODE_DOMAIN_ASSIGN_SHIFT)) & PGMC_BPC_BPC_MODE_DOMAIN_ASSIGN_MASK)
/*! @} */

/*! @name BPC_POWER_CTRL - BPC power control */
/*! @{ */

#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_WAIT_MASK (0x2U)
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_WAIT_SHIFT (1U)
/*! PWR_OFF_AT_WAIT - 0x1: Power off when domain enters WAIT mode */
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_WAIT(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_WAIT_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_WAIT_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_STOP_MASK (0x4U)
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_STOP_SHIFT (2U)
/*! PWR_OFF_AT_STOP - 0x1: Power off when domain enters STOP mode */
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_STOP(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_STOP_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_STOP_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SUSPEND_MASK (0x8U)
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SUSPEND_SHIFT (3U)
/*! PWR_OFF_AT_SUSPEND - 0x1: Power off when domain enters SUSPEND mode */
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SUSPEND(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SUSPEND_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SUSPEND_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_ISO_ON_SOFT_MASK (0x100U)
#define PGMC_BPC_BPC_POWER_CTRL_ISO_ON_SOFT_SHIFT (8U)
/*! ISO_ON_SOFT - Software isolation on trigger */
#define PGMC_BPC_BPC_POWER_CTRL_ISO_ON_SOFT(x)   (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_ISO_ON_SOFT_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_ISO_ON_SOFT_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_PSW_OFF_SOFT_MASK (0x200U)
#define PGMC_BPC_BPC_POWER_CTRL_PSW_OFF_SOFT_SHIFT (9U)
/*! PSW_OFF_SOFT - Software power off trigger */
#define PGMC_BPC_BPC_POWER_CTRL_PSW_OFF_SOFT(x)  (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_PSW_OFF_SOFT_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_PSW_OFF_SOFT_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_PSW_ON_SOFT_MASK (0x400U)
#define PGMC_BPC_BPC_POWER_CTRL_PSW_ON_SOFT_SHIFT (10U)
/*! PSW_ON_SOFT - Software power on trigger */
#define PGMC_BPC_BPC_POWER_CTRL_PSW_ON_SOFT(x)   (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_PSW_ON_SOFT_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_PSW_ON_SOFT_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_ISO_OFF_SOFT_MASK (0x800U)
#define PGMC_BPC_BPC_POWER_CTRL_ISO_OFF_SOFT_SHIFT (11U)
/*! ISO_OFF_SOFT - Software isolation off trigger */
#define PGMC_BPC_BPC_POWER_CTRL_ISO_OFF_SOFT(x)  (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_ISO_OFF_SOFT_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_ISO_OFF_SOFT_MASK)

#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SP_MASK (0xFFFF0000U)
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SP_SHIFT (16U)
/*! PWR_OFF_AT_SP - Power off when system enters Setpoint number */
#define PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SP(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SP_SHIFT)) & PGMC_BPC_BPC_POWER_CTRL_PWR_OFF_AT_SP_MASK)
/*! @} */

/*! @name BPC_FLAG - BPC flag */
/*! @{ */

#define PGMC_BPC_BPC_FLAG_PDN_FLAG_MASK          (0x1U)
#define PGMC_BPC_BPC_FLAG_PDN_FLAG_SHIFT         (0U)
/*! PDN_FLAG - set to 1 after power switch off, cleared by writing 1 */
#define PGMC_BPC_BPC_FLAG_PDN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_FLAG_PDN_FLAG_SHIFT)) & PGMC_BPC_BPC_FLAG_PDN_FLAG_MASK)
/*! @} */

/*! @name BPC_SSAR_SAVE_CTRL - BPC SSAR save control */
/*! @{ */

#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_RUN_MASK (0x1U)
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_RUN_SHIFT (0U)
/*! SAVE_AT_RUN - Save data at RUN mode, software writting 0x1 to trigger SSARC to execute save process */
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_RUN(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_RUN_SHIFT)) & PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_RUN_MASK)

#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_WAIT_MASK (0x2U)
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_WAIT_SHIFT (1U)
/*! SAVE_AT_WAIT - Save data when domain enters WAIT mode */
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_WAIT(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_WAIT_SHIFT)) & PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_WAIT_MASK)

#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_STOP_MASK (0x4U)
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_STOP_SHIFT (2U)
/*! SAVE_AT_STOP - Save data when domain enters STOP mode */
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_STOP(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_STOP_SHIFT)) & PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_STOP_MASK)

#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SUSPEND_MASK (0x8U)
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SUSPEND_SHIFT (3U)
/*! SAVE_AT_SUSPEND - Save data when domain enters SUSPEND mode */
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SUSPEND(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SUSPEND_SHIFT)) & PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SUSPEND_MASK)

#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SP_MASK (0xFFFF0000U)
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SP_SHIFT (16U)
/*! SAVE_AT_SP - Save data when system enters a Setpoint. */
#define PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SP(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SP_SHIFT)) & PGMC_BPC_BPC_SSAR_SAVE_CTRL_SAVE_AT_SP_MASK)
/*! @} */

/*! @name BPC_SSAR_RESTORE_CTRL - BPC SSAR restore control */
/*! @{ */

#define PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_RUN_MASK (0x1U)
#define PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_RUN_SHIFT (0U)
/*! RESTORE_AT_RUN - Restore data at RUN mode */
#define PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_RUN(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_RUN_SHIFT)) & PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_RUN_MASK)

#define PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_SP_MASK (0xFFFF0000U)
#define PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_SP_SHIFT (16U)
/*! RESTORE_AT_SP - Restore data when system enters a Setpoint. */
#define PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_SP(x) (((uint32_t)(((uint32_t)(x)) << PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_SP_SHIFT)) & PGMC_BPC_BPC_SSAR_RESTORE_CTRL_RESTORE_AT_SP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PGMC_BPC_Register_Masks */


/*!
 * @}
 */ /* end of group PGMC_BPC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_PGMC_BPC_H_ */

