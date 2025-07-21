/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPC_SYS_SLEEP_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPC_SYS_SLEEP_CTRL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_SYS_SLEEP_CTRL
 *
 * CMSIS Peripheral Access Layer for GPC_SYS_SLEEP_CTRL
 */

#if !defined(PERI_GPC_SYS_SLEEP_CTRL_H_)
#define PERI_GPC_SYS_SLEEP_CTRL_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- GPC_SYS_SLEEP_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_SYS_SLEEP_CTRL_Peripheral_Access_Layer GPC_SYS_SLEEP_CTRL Peripheral Access Layer
 * @{
 */

/** GPC_SYS_SLEEP_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t SS_AUTHEN_CTRL;                    /**< System Sleep Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SS_MISC;                           /**< System Sleep Misc, offset: 0xC */
       uint8_t RESERVED_2[48];
  __IO uint32_t PMIC_CTRL;                         /**< PMIC standby control, offset: 0x40 */
       uint8_t RESERVED_3[172];
  __IO uint32_t SS_STEP0_IN_CTRL;                  /**< System Sleep STEP0 (BIAS) in control, offset: 0xF0 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SS_STEP1_IN_CTRL;                  /**< System Sleep STEP1 (PLDO) in control, offset: 0x100 */
       uint8_t RESERVED_5[12];
  __IO uint32_t SS_STEP2_IN_CTRL;                  /**< System Sleep STEP2 (BANDGAP) in control, offset: 0x110 */
       uint8_t RESERVED_6[12];
  __IO uint32_t SS_STEP3_IN_CTRL;                  /**< System Sleep STEP3 (LDO) in control, offset: 0x120 */
       uint8_t RESERVED_7[28];
  __IO uint32_t SS_DCDC_IN_CTRL;                   /**< System Sleep DCDC in control, offset: 0x140 */
       uint8_t RESERVED_8[12];
  __IO uint32_t SS_PMIC_IN_CTRL;                   /**< System Sleep PMIC in control, offset: 0x150 */
       uint8_t RESERVED_9[172];
  __IO uint32_t SS_PMIC_OUT_CTRL;                  /**< System Sleep PMIC out control, offset: 0x200 */
       uint8_t RESERVED_10[12];
  __IO uint32_t SS_DCDC_OUT_CTRL;                  /**< System Sleep DCDC out control, offset: 0x210 */
       uint8_t RESERVED_11[36];
  __IO uint32_t SS_STEP3_OUT_CTRL;                 /**< System Sleep STEP3 (LDO) out control, offset: 0x238 */
       uint8_t RESERVED_12[4];
  __IO uint32_t SS_STEP2_OUT_CTRL;                 /**< System Sleep STEP2 (BANDGAP) out control, offset: 0x240 */
       uint8_t RESERVED_13[12];
  __IO uint32_t SS_STEP1_OUT_CTRL;                 /**< System Sleep STEP1 (PLDO) out control, offset: 0x250 */
       uint8_t RESERVED_14[12];
  __IO uint32_t SS_STEP0_OUT_CTRL;                 /**< System Sleep STEP0 (BIAS) out control, offset: 0x260 */
} GPC_SYS_SLEEP_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_SYS_SLEEP_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_SYS_SLEEP_CTRL_Register_Masks GPC_SYS_SLEEP_CTRL Register Masks
 * @{
 */

/*! @name SS_AUTHEN_CTRL - System Sleep Authentication Control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_AUTHEN_CTRL_LOCK_CFG_MASK (0x100000U)
#define GPC_SYS_SLEEP_CTRL_SS_AUTHEN_CTRL_LOCK_CFG_SHIFT (20U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. Refer to the function field of each gpc_sys_sleep_ctrl registers.
 */
#define GPC_SYS_SLEEP_CTRL_SS_AUTHEN_CTRL_LOCK_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_AUTHEN_CTRL_LOCK_CFG_MASK)
/*! @} */

/*! @name SS_MISC - System Sleep Misc */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU0_SYS_SLEEP_MASK (0x1U)
#define GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU0_SYS_SLEEP_SHIFT (0U)
/*! FORCE_CPU0_SYS_SLEEP - Force CPU0 to request system sleep mode
 *  0b0..Do not force CPU0 to request system sleep mode
 *  0b1..Force CPU0 to request system sleep mode
 */
#define GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU0_SYS_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU0_SYS_SLEEP_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU0_SYS_SLEEP_MASK)

#define GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU1_SYS_SLEEP_MASK (0x2U)
#define GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU1_SYS_SLEEP_SHIFT (1U)
/*! FORCE_CPU1_SYS_SLEEP - Force CPU1 to request system sleep mode
 *  0b0..Do not force CPU1 to request system sleep mode
 *  0b1..Force CPU1 to request system sleep mode
 */
#define GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU1_SYS_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU1_SYS_SLEEP_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_MISC_FORCE_CPU1_SYS_SLEEP_MASK)
/*! @} */

/*! @name PMIC_CTRL - PMIC standby control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_EN_MASK (0x1U)
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_EN_SHIFT (0U)
/*! PMIC_STBY_EN - Assert the PMIC standby request when system sleep
 *  0b0..Do not assert PMIC_STBY_REQ when system sleep is entered
 *  0b1..Assert PMIC_STBY_REQ when system sleep is entered
 */
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_EN(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_EN_SHIFT)) & GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_EN_MASK)

#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_MASK (0x2U)
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_SHIFT (1U)
/*! PMIC_READY - PMIC_READY pin status
 *  0b0..PMIC_READY not asserted
 *  0b1..PMIC_READY asserted
 */
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_SHIFT)) & GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_MASK)

#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_EXIST_MASK (0x4U)
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_EXIST_SHIFT (2U)
/*! PMIC_READY_EXIST - PMIC_READY is driven from pad
 *  0b0..PMIC_READY is not driven.
 *  0b1..PMIC_READY is driven from pad. If PMIC_READY_EXIST = 1, PMIC_READY = 1 means external PMIC drives PMIC_READY pin.
 */
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_EXIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_EXIST_SHIFT)) & GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_READY_EXIST_MASK)

#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_SOFT_MASK (0x10U)
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_SOFT_SHIFT (4U)
/*! PMIC_STBY_SOFT - Software PMIC standby trigger
 *  0b0..Exit PMIC standby
 *  0b1..Trigger PMIC standby
 */
#define GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_SOFT(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_SOFT_SHIFT)) & GPC_SYS_SLEEP_CTRL_PMIC_CTRL_PMIC_STBY_SOFT_MASK)
/*! @} */

/*! @name SS_STEP0_IN_CTRL - System Sleep STEP0 (BIAS) in control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP0_IN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP0_IN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP0_IN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP0_IN_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP0_IN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP1_IN_CTRL - System Sleep STEP1 (PLDO) in control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP1_IN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP1_IN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP1_IN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP1_IN_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP1_IN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP2_IN_CTRL - System Sleep STEP2 (BANDGAP) in control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP2_IN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP2_IN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP2_IN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP2_IN_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP2_IN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP3_IN_CTRL - System Sleep STEP3 (LDO) in control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP3_IN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP3_IN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP3_IN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP3_IN_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP3_IN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_DCDC_IN_CTRL - System Sleep DCDC in control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_DCDC_IN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_DCDC_IN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_DCDC_IN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_DCDC_IN_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_DCDC_IN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_PMIC_IN_CTRL - System Sleep PMIC in control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_PMIC_IN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_PMIC_IN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_PMIC_IN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_PMIC_IN_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_PMIC_IN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_PMIC_OUT_CTRL - System Sleep PMIC out control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_PMIC_OUT_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_PMIC_OUT_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_PMIC_OUT_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_PMIC_OUT_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_PMIC_OUT_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_DCDC_OUT_CTRL - System Sleep DCDC out control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_DCDC_OUT_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_DCDC_OUT_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_DCDC_OUT_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_DCDC_OUT_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_DCDC_OUT_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP3_OUT_CTRL - System Sleep STEP3 (LDO) out control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP3_OUT_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP3_OUT_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP3_OUT_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP3_OUT_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP3_OUT_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP2_OUT_CTRL - System Sleep STEP2 (BANDGAP) out control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP2_OUT_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP2_OUT_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP2_OUT_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP2_OUT_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP2_OUT_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP1_OUT_CTRL - System Sleep STEP1 (PLDO) out control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP1_OUT_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP1_OUT_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP1_OUT_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP1_OUT_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP1_OUT_CTRL_DISABLE_MASK)
/*! @} */

/*! @name SS_STEP0_OUT_CTRL - System Sleep STEP0 (BIAS) out control */
/*! @{ */

#define GPC_SYS_SLEEP_CTRL_SS_STEP0_OUT_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_SYS_SLEEP_CTRL_SS_STEP0_OUT_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_SYS_SLEEP_CTRL_SS_STEP0_OUT_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_SYS_SLEEP_CTRL_SS_STEP0_OUT_CTRL_DISABLE_SHIFT)) & GPC_SYS_SLEEP_CTRL_SS_STEP0_OUT_CTRL_DISABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_SYS_SLEEP_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_SYS_SLEEP_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_SYS_SLEEP_CTRL_H_ */

