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
**         CMSIS Peripheral Access Layer for GPC_CPU_CTRL
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
 * @file PERI_GPC_CPU_CTRL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_CPU_CTRL
 *
 * CMSIS Peripheral Access Layer for GPC_CPU_CTRL
 */

#if !defined(PERI_GPC_CPU_CTRL_H_)
#define PERI_GPC_CPU_CTRL_H_                     /**< Symbol preventing repeated inclusion */

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
   -- GPC_CPU_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_CPU_CTRL_Peripheral_Access_Layer GPC_CPU_CTRL Peripheral Access Layer
 * @{
 */

/** GPC_CPU_CTRL - Size of Registers Arrays */
#define GPC_CPU_CTRL_AUTHEN_CM_IRQ_WAKEUP_MASK_COUNT 8u
#define GPC_CPU_CTRL_AUTHEN_CM_IRQ_WAKEUP_STAT_COUNT 8u
#define GPC_CPU_CTRL_AUTHEN_COUNT                 2u

/** GPC_CPU_CTRL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x800 */
         uint8_t RESERVED_0[4];
    __IO uint32_t CM_AUTHEN_CTRL;                    /**< CM Authentication Control, array offset: 0x4, array step: 0x800 */
         uint8_t RESERVED_1[4];
    __IO uint32_t CM_MISC;                           /**< Miscellaneous, array offset: 0xC, array step: 0x800 */
    __IO uint32_t CM_MODE_CTRL;                      /**< CPU mode control, array offset: 0x10, array step: 0x800 */
    __I  uint32_t CM_MODE_STAT;                      /**< CM CPU mode Status, array offset: 0x14, array step: 0x800 */
         uint8_t RESERVED_2[232];
    __IO uint32_t CM_IRQ_WAKEUP_MASK[GPC_CPU_CTRL_AUTHEN_CM_IRQ_WAKEUP_MASK_COUNT];   /**< CM IRQ0~31 wakeup mask..CM IRQ224~255 wakeup mask, array offset: 0x100, array step: index*0x800, index2*0x4 */
         uint8_t RESERVED_3[32];
    __IO uint32_t CM_NON_IRQ_WAKEUP_MASK;            /**< CM non-IRQ wakeup mask, array offset: 0x140, array step: 0x800 */
         uint8_t RESERVED_4[12];
    __I  uint32_t CM_IRQ_WAKEUP_STAT[GPC_CPU_CTRL_AUTHEN_CM_IRQ_WAKEUP_STAT_COUNT];   /**< CM IRQ0~31 wakeup status..CM IRQ224~255 wakeup status, array offset: 0x150, array step: index*0x800, index2*0x4 */
         uint8_t RESERVED_5[32];
    __I  uint32_t CM_NON_IRQ_WAKEUP_STAT;            /**< CM non-irq wakeup status, array offset: 0x190, array step: 0x800 */
         uint8_t RESERVED_6[108];
    __IO uint32_t CM_SLEEP_SSAR_CTRL;                /**< CM sleep SSAR control, array offset: 0x200, array step: 0x800 */
         uint8_t RESERVED_7[4];
    __IO uint32_t CM_SLEEP_LPCG_CTRL;                /**< CM sleep LPCG control, array offset: 0x208, array step: 0x800 */
         uint8_t RESERVED_8[4];
    __IO uint32_t CM_SLEEP_PLL_CTRL;                 /**< CM sleep PLL control, array offset: 0x210, array step: 0x800 */
         uint8_t RESERVED_9[4];
    __IO uint32_t CM_SLEEP_ISO_CTRL;                 /**< CM sleep isolation control, array offset: 0x218, array step: 0x800 */
         uint8_t RESERVED_10[4];
    __IO uint32_t CM_SLEEP_RESET_CTRL;               /**< CM sleep reset control, array offset: 0x220, array step: 0x800 */
         uint8_t RESERVED_11[4];
    __IO uint32_t CM_SLEEP_POWER_CTRL;               /**< CM sleep power control, array offset: 0x228, array step: 0x800 */
         uint8_t RESERVED_12[100];
    __IO uint32_t CM_WAKEUP_POWER_CTRL;              /**< CM wakeup power control, array offset: 0x290, array step: 0x800 */
         uint8_t RESERVED_13[4];
    __IO uint32_t CM_WAKEUP_RESET_CTRL;              /**< CM wakeup reset control, array offset: 0x298, array step: 0x800 */
         uint8_t RESERVED_14[4];
    __IO uint32_t CM_WAKEUP_ISO_CTRL;                /**< CM wakeup isolation control, array offset: 0x2A0, array step: 0x800 */
         uint8_t RESERVED_15[4];
    __IO uint32_t CM_WAKEUP_PLL_CTRL;                /**< CM wakeup PLL control, array offset: 0x2A8, array step: 0x800 */
         uint8_t RESERVED_16[4];
    __IO uint32_t CM_WAKEUP_LPCG_CTRL;               /**< CM wakeup LPCG control, array offset: 0x2B0, array step: 0x800 */
         uint8_t RESERVED_17[12];
    __IO uint32_t CM_WAKEUP_SSAR_CTRL;               /**< CM wakeup SSAR control, array offset: 0x2C0, array step: 0x800 */
         uint8_t RESERVED_18[188];
    __IO uint32_t CM_SYS_SLEEP_CTRL;                 /**< CM system sleep control, array offset: 0x380, array step: 0x800 */
         uint8_t RESERVED_19[1148];
  } AUTHEN[GPC_CPU_CTRL_AUTHEN_COUNT];
} GPC_CPU_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_CPU_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_CPU_CTRL_Register_Masks GPC_CPU_CTRL Register Masks
 * @{
 */

/*! @name CM_AUTHEN_CTRL - CM Authentication Control */
/*! @{ */

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. It locks the CPUx_CM registers which are marked
 *       as "Locked by LOCK_CFG field" in the function field.
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_MASK    (0x100U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_SHIFT   (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_USER_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_MASK (0x200U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_SHIFT (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode control
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_MASK (0x800U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_SHIFT (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_CPU_CTRL_CM_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_AUTHEN_CTRL */
#define GPC_CPU_CTRL_CM_AUTHEN_CTRL_COUNT        (2U)

/*! @name CM_MISC - Miscellaneous */
/*! @{ */

#define GPC_CPU_CTRL_CM_MISC_NMI_STAT_MASK       (0x1U)
#define GPC_CPU_CTRL_CM_MISC_NMI_STAT_SHIFT      (0U)
/*! NMI_STAT - Non-masked interrupt status
 *  0b0..NMI is not asserted
 *  0b1..NMI is asserted
 */
#define GPC_CPU_CTRL_CM_MISC_NMI_STAT(x)         (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_NMI_STAT_SHIFT)) & GPC_CPU_CTRL_CM_MISC_NMI_STAT_MASK)

#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_MASK  (0x2U)
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_SHIFT (1U)
/*! SLEEP_HOLD_EN - Allow cpu_sleep_hold_req to assert during CPU low power status
 *  0b0..Disable cpu_sleep_hold_req
 *  0b1..Allow cpu_sleep_hold_req to assert during CPU low power status
 */
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN(x)    (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_SHIFT)) & GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_EN_MASK)

#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_MASK (0x4U)
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_SHIFT (2U)
/*! SLEEP_HOLD_STAT - CPU sleep hold status
 *  0b0..CPU sleep hold is acknowledged
 *  0b1..CPU is not in sleep hold
 */
#define GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_SHIFT)) & GPC_CPU_CTRL_CM_MISC_SLEEP_HOLD_STAT_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_MISC */
#define GPC_CPU_CTRL_CM_MISC_COUNT               (2U)

/*! @name CM_MODE_CTRL - CPU mode control */
/*! @{ */

#define GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_MASK (0x3U)
#define GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_SHIFT (0U)
/*! CPU_MODE_TARGET - The CPU mode the CPU platform should transit to on next sleep event
 *  0b00..Stay in RUN mode
 *  0b01..Transit to WAIT mode
 *  0b10..Transit to STOP mode
 *  0b11..Transit to SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_SHIFT)) & GPC_CPU_CTRL_CM_MODE_CTRL_CPU_MODE_TARGET_MASK)

#define GPC_CPU_CTRL_CM_MODE_CTRL_WFE_EN_MASK    (0x10U)
#define GPC_CPU_CTRL_CM_MODE_CTRL_WFE_EN_SHIFT   (4U)
/*! WFE_EN - WFE assertion can be sleep event
 *  0b0..WFE assertion can not trigger low power
 *  0b1..WFE assertion can trigger low power
 */
#define GPC_CPU_CTRL_CM_MODE_CTRL_WFE_EN(x)      (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_CTRL_WFE_EN_SHIFT)) & GPC_CPU_CTRL_CM_MODE_CTRL_WFE_EN_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_MODE_CTRL */
#define GPC_CPU_CTRL_CM_MODE_CTRL_COUNT          (2U)

/*! @name CM_MODE_STAT - CM CPU mode Status */
/*! @{ */

#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_MASK (0x3U)
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_SHIFT (0U)
/*! CPU_MODE_CURRENT - Current CPU mode
 *  0b00..CPU is currently in RUN mode
 *  0b01..CPU is currently in WAIT mode
 *  0b10..CPU is currently in STOP mode
 *  0b11..CPU is currently in SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_CURRENT_MASK)

#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_MASK (0xCU)
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT (2U)
/*! CPU_MODE_PREVIOUS - Previous CPU mode
 *  0b00..CPU was previously in RUN mode
 *  0b01..CPU was previously in WAIT mode
 *  0b10..CPU was previously in STOP mode
 *  0b11..CPU was previously in SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT)) & GPC_CPU_CTRL_CM_MODE_STAT_CPU_MODE_PREVIOUS_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_MODE_STAT */
#define GPC_CPU_CTRL_CM_MODE_STAT_COUNT          (2U)

/*! @name CM_IRQ_WAKEUP_MASK - CM IRQ0~31 wakeup mask..CM IRQ224~255 wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_0_31_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_0_31_SHIFT (0U)
/*! MASK_0_31 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_0_31(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_0_31_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_0_31_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_32_63_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_32_63_SHIFT (0U)
/*! MASK_32_63 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_32_63(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_32_63_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_32_63_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_64_95_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_64_95_SHIFT (0U)
/*! MASK_64_95 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_64_95(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_64_95_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_64_95_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_96_127_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_96_127_SHIFT (0U)
/*! MASK_96_127 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_96_127(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_96_127_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_96_127_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_128_159_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_128_159_SHIFT (0U)
/*! MASK_128_159 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_128_159(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_128_159_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_128_159_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_160_191_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_160_191_SHIFT (0U)
/*! MASK_160_191 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_160_191(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_160_191_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_160_191_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_192_223_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_192_223_SHIFT (0U)
/*! MASK_192_223 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_192_223(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_192_223_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_192_223_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_224_255_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_224_255_SHIFT (0U)
/*! MASK_224_255 - "1" means the IRQ cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_224_255(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_224_255_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_MASK_224_255_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_COUNT    (2U)

/* The count of GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_MASK_COUNT2   (8U)

/*! @name CM_NON_IRQ_WAKEUP_MASK - CM non-IRQ wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK (0x2U)
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT (1U)
/*! DEBUG_WAKEUP_MASK - "1" means the debug_wakeup_request cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT)) & GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_MASK_COUNT (2U)

/*! @name CM_IRQ_WAKEUP_STAT - CM IRQ0~31 wakeup status..CM IRQ224~255 wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_0_31_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_0_31_SHIFT (0U)
/*! STAT_0_31 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_0_31(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_0_31_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_0_31_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_32_63_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_32_63_SHIFT (0U)
/*! STAT_32_63 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_32_63(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_32_63_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_32_63_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_64_95_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_64_95_SHIFT (0U)
/*! STAT_64_95 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_64_95(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_64_95_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_64_95_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_96_127_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_96_127_SHIFT (0U)
/*! STAT_96_127 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_96_127(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_96_127_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_96_127_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_128_159_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_128_159_SHIFT (0U)
/*! STAT_128_159 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_128_159(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_128_159_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_128_159_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_160_191_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_160_191_SHIFT (0U)
/*! STAT_160_191 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_160_191(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_160_191_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_160_191_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_192_223_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_192_223_SHIFT (0U)
/*! STAT_192_223 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_192_223(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_192_223_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_192_223_MASK)

#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_224_255_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_224_255_SHIFT (0U)
/*! STAT_224_255 - IRQ status */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_224_255(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_224_255_SHIFT)) & GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_STAT_224_255_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_COUNT    (2U)

/* The count of GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT */
#define GPC_CPU_CTRL_CM_IRQ_WAKEUP_STAT_COUNT2   (8U)

/*! @name CM_NON_IRQ_WAKEUP_STAT - CM non-irq wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK (0x2U)
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT (1U)
/*! DEBUG_WAKEUP_STAT - Debug wakeup status
 *  0b0..No debug wakeup is requested
 *  0b1..Debug wakeup is requested
 */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT */
#define GPC_CPU_CTRL_CM_NON_IRQ_WAKEUP_STAT_COUNT (2U)

/*! @name CM_SLEEP_SSAR_CTRL - CM sleep SSAR control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL */
#define GPC_CPU_CTRL_CM_SLEEP_SSAR_CTRL_COUNT    (2U)

/*! @name CM_SLEEP_LPCG_CTRL - CM sleep LPCG control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL */
#define GPC_CPU_CTRL_CM_SLEEP_LPCG_CTRL_COUNT    (2U)

/*! @name CM_SLEEP_PLL_CTRL - CM sleep PLL control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL */
#define GPC_CPU_CTRL_CM_SLEEP_PLL_CTRL_COUNT     (2U)

/*! @name CM_SLEEP_ISO_CTRL - CM sleep isolation control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL */
#define GPC_CPU_CTRL_CM_SLEEP_ISO_CTRL_COUNT     (2U)

/*! @name CM_SLEEP_RESET_CTRL - CM sleep reset control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL */
#define GPC_CPU_CTRL_CM_SLEEP_RESET_CTRL_COUNT   (2U)

/*! @name CM_SLEEP_POWER_CTRL - CM sleep power control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL */
#define GPC_CPU_CTRL_CM_SLEEP_POWER_CTRL_COUNT   (2U)

/*! @name CM_WAKEUP_POWER_CTRL - CM wakeup power control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL */
#define GPC_CPU_CTRL_CM_WAKEUP_POWER_CTRL_COUNT  (2U)

/*! @name CM_WAKEUP_RESET_CTRL - CM wakeup reset control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL */
#define GPC_CPU_CTRL_CM_WAKEUP_RESET_CTRL_COUNT  (2U)

/*! @name CM_WAKEUP_ISO_CTRL - CM wakeup isolation control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL */
#define GPC_CPU_CTRL_CM_WAKEUP_ISO_CTRL_COUNT    (2U)

/*! @name CM_WAKEUP_PLL_CTRL - CM wakeup PLL control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL */
#define GPC_CPU_CTRL_CM_WAKEUP_PLL_CTRL_COUNT    (2U)

/*! @name CM_WAKEUP_LPCG_CTRL - CM wakeup LPCG control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL */
#define GPC_CPU_CTRL_CM_WAKEUP_LPCG_CTRL_COUNT   (2U)

/*! @name CM_WAKEUP_SSAR_CTRL - CM wakeup SSAR control */
/*! @{ */

#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL */
#define GPC_CPU_CTRL_CM_WAKEUP_SSAR_CTRL_COUNT   (2U)

/*! @name CM_SYS_SLEEP_CTRL - CM system sleep control */
/*! @{ */

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_MASK (0x1U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_SHIFT (0U)
/*! SS_WAIT - Request system sleep when CPU is in WAIT mode
 *  0b0..Do not request system sleep when CPU is in WAIT mode
 *  0b1..Request system sleep when CPU is in WAIT mode
 */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_WAIT_MASK)

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_MASK (0x2U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_SHIFT (1U)
/*! SS_STOP - Request system sleep when CPU is in STOP mode
 *  0b0..Do not request system sleep when CPU is in STOP mode
 *  0b1..Request system sleep when CPU is in STOP mode
 */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_STOP_MASK)

#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_MASK (0x4U)
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT (2U)
/*! SS_SUSPEND - Request system sleep when CPU is in SUSPEND mode
 *  0b0..Do not request system sleep when CPU is in SUSPEND mode
 *  0b1..Request system sleep when CPU is in SUSPEND mode
 */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT)) & GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_SS_SUSPEND_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL */
#define GPC_CPU_CTRL_CM_SYS_SLEEP_CTRL_COUNT     (2U)


/*!
 * @}
 */ /* end of group GPC_CPU_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_CPU_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_CPU_CTRL_H_ */

