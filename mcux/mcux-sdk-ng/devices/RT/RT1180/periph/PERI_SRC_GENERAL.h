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
**         CMSIS Peripheral Access Layer for SRC_GENERAL
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
 * @file PERI_SRC_GENERAL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC_GENERAL
 *
 * CMSIS Peripheral Access Layer for SRC_GENERAL
 */

#if !defined(PERI_SRC_GENERAL_H_)
#define PERI_SRC_GENERAL_H_                      /**< Symbol preventing repeated inclusion */

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
   -- SRC_GENERAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GENERAL_Peripheral_Access_Layer SRC_GENERAL Peripheral Access Layer
 * @{
 */

/** SRC_GENERAL - Size of Registers Arrays */
#define SRC_GENERAL_GPR_COUNT                     20u

/** SRC_GENERAL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SCR;                               /**< SRC Control Register, offset: 0x10 */
  __IO uint32_t SRTMR;                             /**< SRC Reset Trigger Mode Register, offset: 0x14 */
  __IO uint32_t SRMASK;                            /**< SRC Reset Mask Register, offset: 0x18 */
       uint8_t RESERVED_2[36];
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x40 */
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x44 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SRSR_BBSM;                         /**< SRC Reset Status Register backup in BBSM domain, offset: 0x4C */
  __IO uint32_t SRSR;                              /**< SRC Reset Status Register, offset: 0x50 */
  __IO uint32_t GPR[SRC_GENERAL_GPR_COUNT];        /**< SRC General Purpose Register, array offset: 0x54, array step: 0x4 */
} SRC_GENERAL_Type;

/* ----------------------------------------------------------------------------
   -- SRC_GENERAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GENERAL_Register_Masks SRC_GENERAL Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - Authentication Control */
/*! @{ */

#define SRC_GENERAL_AUTHEN_CTRL_LOCK_CFG_MASK    (0x80U)
#define SRC_GENERAL_AUTHEN_CTRL_LOCK_CFG_SHIFT   (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..General registers are not locked.
 *  0b1..LOCK_CFG and registers in the list are locked.
 */
#define SRC_GENERAL_AUTHEN_CTRL_LOCK_CFG(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & SRC_GENERAL_AUTHEN_CTRL_LOCK_CFG_MASK)

#define SRC_GENERAL_AUTHEN_CTRL_TZ_USER_MASK     (0x100U)
#define SRC_GENERAL_AUTHEN_CTRL_TZ_USER_SHIFT    (8U)
/*! TZ_USER - Allow user mode write
 *  0b0..General registers can only be written in privilege mode.
 *  0b1..General registers can be written either in privilege mode or user mode.
 */
#define SRC_GENERAL_AUTHEN_CTRL_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_AUTHEN_CTRL_TZ_USER_SHIFT)) & SRC_GENERAL_AUTHEN_CTRL_TZ_USER_MASK)

#define SRC_GENERAL_AUTHEN_CTRL_TZ_NS_MASK       (0x200U)
#define SRC_GENERAL_AUTHEN_CTRL_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..General registers can only be written in secure mode.
 *  0b1..General registers can be written either in secure mode or non-secure mode.
 */
#define SRC_GENERAL_AUTHEN_CTRL_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_AUTHEN_CTRL_TZ_NS_SHIFT)) & SRC_GENERAL_AUTHEN_CTRL_TZ_NS_MASK)

#define SRC_GENERAL_AUTHEN_CTRL_LOCK_TZ_MASK     (0x800U)
#define SRC_GENERAL_AUTHEN_CTRL_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock Trust Zone Non Secure(TZ_NS) and Trust Zone User(TZ_USER) bits
 *  0b0..TZ_NS and TZ_USER values can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER values cannot be changed.
 */
#define SRC_GENERAL_AUTHEN_CTRL_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_AUTHEN_CTRL_LOCK_TZ_SHIFT)) & SRC_GENERAL_AUTHEN_CTRL_LOCK_TZ_MASK)

#define SRC_GENERAL_AUTHEN_CTRL_LOCK_LIST_MASK   (0x8000U)
#define SRC_GENERAL_AUTHEN_CTRL_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST values cannot be changed.
 */
#define SRC_GENERAL_AUTHEN_CTRL_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & SRC_GENERAL_AUTHEN_CTRL_LOCK_LIST_MASK)

#define SRC_GENERAL_AUTHEN_CTRL_WHITE_LIST_MASK  (0xFFFF0000U)
#define SRC_GENERAL_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write General registers.
 *  0b0000000000000010..Core with domain ID=1 can write General registers.
 *  0b0000000000000100..Core with domain ID=2 can write General registers.
 *  0b0000000000001000..Core with domain ID=3 can write General registers.
 *  0b0000000000010000..Core with domain ID=4 can write General registers.
 *  0b0000000000100000..Core with domain ID=5 can write General registers.
 *  0b0000000001000000..Core with domain ID=6 can write General registers.
 *  0b0000000010000000..Core with domain ID=7 can write General registers.
 *  0b0000000100000000..Core with domain ID=8 can write General registers.
 *  0b0000001000000000..Core with domain ID=9 can write General registers.
 *  0b0000010000000000..Core with domain ID=10 can write General registers.
 *  0b0000100000000000..Core with domain ID=11 can write General registers.
 *  0b0001000000000000..Core with domain ID=12 can write General registers.
 *  0b0010000000000000..Core with domain ID=13 can write General registers.
 *  0b0100000000000000..Core with domain ID=14 can write General registers.
 *  0b1000000000000000..Core with domain ID=15 can write General registers.
 */
#define SRC_GENERAL_AUTHEN_CTRL_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & SRC_GENERAL_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name SCR - SRC Control Register */
/*! @{ */

#define SRC_GENERAL_SCR_BT_RELEASE_M7_MASK       (0x1U)
#define SRC_GENERAL_SCR_BT_RELEASE_M7_SHIFT      (0U)
/*! BT_RELEASE_M7 - Boot release M7
 *  0b0..Holds M7 Core reset.
 *  0b1..Releases M7 Core reset and let it run. After this bit is set, it cannot be cleared by SW write.
 */
#define SRC_GENERAL_SCR_BT_RELEASE_M7(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SCR_BT_RELEASE_M7_SHIFT)) & SRC_GENERAL_SCR_BT_RELEASE_M7_MASK)
/*! @} */

/*! @name SRTMR - SRC Reset Trigger Mode Register */
/*! @{ */

#define SRC_GENERAL_SRTMR_WDOG1_TRIG_MODE_MASK   (0x1U)
#define SRC_GENERAL_SRTMR_WDOG1_TRIG_MODE_SHIFT  (0U)
/*! WDOG1_TRIG_MODE - Wdog1 reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_WDOG1_TRIG_MODE(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_WDOG1_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_WDOG1_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_WDOG2_TRIG_MODE_MASK   (0x2U)
#define SRC_GENERAL_SRTMR_WDOG2_TRIG_MODE_SHIFT  (1U)
/*! WDOG2_TRIG_MODE - Wdog2 reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_WDOG2_TRIG_MODE(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_WDOG2_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_WDOG2_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_WDOG3_TRIG_MODE_MASK   (0x4U)
#define SRC_GENERAL_SRTMR_WDOG3_TRIG_MODE_SHIFT  (2U)
/*! WDOG3_TRIG_MODE - Wdog3 reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_WDOG3_TRIG_MODE(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_WDOG3_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_WDOG3_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_WDOG4_TRIG_MODE_MASK   (0x8U)
#define SRC_GENERAL_SRTMR_WDOG4_TRIG_MODE_SHIFT  (3U)
/*! WDOG4_TRIG_MODE - Wdog4 reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_WDOG4_TRIG_MODE(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_WDOG4_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_WDOG4_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_WDOG5_TRIG_MODE_MASK   (0x10U)
#define SRC_GENERAL_SRTMR_WDOG5_TRIG_MODE_SHIFT  (4U)
/*! WDOG5_TRIG_MODE - Wdog5 reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_WDOG5_TRIG_MODE(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_WDOG5_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_WDOG5_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_TEMPSENSE_TRIG_MODE_MASK (0x20U)
#define SRC_GENERAL_SRTMR_TEMPSENSE_TRIG_MODE_SHIFT (5U)
/*! TEMPSENSE_TRIG_MODE - TempSense reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_TEMPSENSE_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_TEMPSENSE_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_TEMPSENSE_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_EDGELOCK_TRIG_MODE_MASK (0x40U)
#define SRC_GENERAL_SRTMR_EDGELOCK_TRIG_MODE_SHIFT (6U)
/*! EDGELOCK_TRIG_MODE - Edgelock reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_EDGELOCK_TRIG_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_EDGELOCK_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_EDGELOCK_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_JTAGSW_TRIG_MODE_MASK  (0x80U)
#define SRC_GENERAL_SRTMR_JTAGSW_TRIG_MODE_SHIFT (7U)
/*! JTAGSW_TRIG_MODE - Jtagsw reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_JTAGSW_TRIG_MODE(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_JTAGSW_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_JTAGSW_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_CM33_RESET_TRIG_MODE_MASK (0x100U)
#define SRC_GENERAL_SRTMR_CM33_RESET_TRIG_MODE_SHIFT (8U)
/*! CM33_RESET_TRIG_MODE - CM33 reset trigger mode configuration, locked by LOCK_CFG field.
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_CM33_RESET_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_CM33_RESET_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_CM33_RESET_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_CM33_LOCKUP_TRIG_MODE_MASK (0x200U)
#define SRC_GENERAL_SRTMR_CM33_LOCKUP_TRIG_MODE_SHIFT (9U)
/*! CM33_LOCKUP_TRIG_MODE - CM33 lockup trigger mode configuration, locked by LOCK_CFG field.
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_CM33_LOCKUP_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_CM33_LOCKUP_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_CM33_LOCKUP_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_CM7_RESET_TRIG_MODE_MASK (0x400U)
#define SRC_GENERAL_SRTMR_CM7_RESET_TRIG_MODE_SHIFT (10U)
/*! CM7_RESET_TRIG_MODE - CM7 reset trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_CM7_RESET_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_CM7_RESET_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_CM7_RESET_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_CM7_LOCKUP_TRIG_MODE_MASK (0x800U)
#define SRC_GENERAL_SRTMR_CM7_LOCKUP_TRIG_MODE_SHIFT (11U)
/*! CM7_LOCKUP_TRIG_MODE - CM7 lockup trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_CM7_LOCKUP_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_CM7_LOCKUP_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_CM7_LOCKUP_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_DCDC_OVVT_TRIG_MODE_MASK (0x1000U)
#define SRC_GENERAL_SRTMR_DCDC_OVVT_TRIG_MODE_SHIFT (12U)
/*! DCDC_OVVT_TRIG_MODE - DCDC over voltage trigger mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_DCDC_OVVT_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_DCDC_OVVT_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_DCDC_OVVT_TRIG_MODE_MASK)

#define SRC_GENERAL_SRTMR_ECAT_RSTO_TRIG_MODE_MASK (0x2000U)
#define SRC_GENERAL_SRTMR_ECAT_RSTO_TRIG_MODE_SHIFT (13U)
/*! ECAT_RSTO_TRIG_MODE - ECAT reset output mode configuration, locked by LOCK_CFG field
 *  0b0..Level-sensitive: System stays in reset until the reset source deasserts.
 *  0b1..Edge-sensitive: System resets once, even if the reset source remains asserted.
 */
#define SRC_GENERAL_SRTMR_ECAT_RSTO_TRIG_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRTMR_ECAT_RSTO_TRIG_MODE_SHIFT)) & SRC_GENERAL_SRTMR_ECAT_RSTO_TRIG_MODE_MASK)
/*! @} */

/*! @name SRMASK - SRC Reset Mask Register */
/*! @{ */

#define SRC_GENERAL_SRMASK_WDOG1_MASK_MASK       (0x1U)
#define SRC_GENERAL_SRMASK_WDOG1_MASK_SHIFT      (0U)
/*! WDOG1_MASK - WDOG1 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_WDOG1_MASK(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG1_MASK_SHIFT)) & SRC_GENERAL_SRMASK_WDOG1_MASK_MASK)

#define SRC_GENERAL_SRMASK_WDOG2_MASK_MASK       (0x2U)
#define SRC_GENERAL_SRMASK_WDOG2_MASK_SHIFT      (1U)
/*! WDOG2_MASK - WDOG2 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_WDOG2_MASK(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG2_MASK_SHIFT)) & SRC_GENERAL_SRMASK_WDOG2_MASK_MASK)

#define SRC_GENERAL_SRMASK_WDOG3_MASK_MASK       (0x4U)
#define SRC_GENERAL_SRMASK_WDOG3_MASK_SHIFT      (2U)
/*! WDOG3_MASK - WDOG3 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_WDOG3_MASK(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG3_MASK_SHIFT)) & SRC_GENERAL_SRMASK_WDOG3_MASK_MASK)

#define SRC_GENERAL_SRMASK_WDOG4_MASK_MASK       (0x8U)
#define SRC_GENERAL_SRMASK_WDOG4_MASK_SHIFT      (3U)
/*! WDOG4_MASK - WDOG4 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_WDOG4_MASK(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG4_MASK_SHIFT)) & SRC_GENERAL_SRMASK_WDOG4_MASK_MASK)

#define SRC_GENERAL_SRMASK_WDOG5_MASK_MASK       (0x10U)
#define SRC_GENERAL_SRMASK_WDOG5_MASK_SHIFT      (4U)
/*! WDOG5_MASK - WDOG5 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_WDOG5_MASK(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG5_MASK_SHIFT)) & SRC_GENERAL_SRMASK_WDOG5_MASK_MASK)

#define SRC_GENERAL_SRMASK_TEMPSENSE_MASK_MASK   (0x20U)
#define SRC_GENERAL_SRMASK_TEMPSENSE_MASK_SHIFT  (5U)
/*! TEMPSENSE_MASK - TempSense reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_TEMPSENSE_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_TEMPSENSE_MASK_SHIFT)) & SRC_GENERAL_SRMASK_TEMPSENSE_MASK_MASK)

#define SRC_GENERAL_SRMASK_EDGELOCK_MASK_MASK    (0x40U)
#define SRC_GENERAL_SRMASK_EDGELOCK_MASK_SHIFT   (6U)
/*! EDGELOCK_MASK - Edgelock reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_EDGELOCK_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_EDGELOCK_MASK_SHIFT)) & SRC_GENERAL_SRMASK_EDGELOCK_MASK_MASK)

#define SRC_GENERAL_SRMASK_JTAGSW_MASK_MASK      (0x80U)
#define SRC_GENERAL_SRMASK_JTAGSW_MASK_SHIFT     (7U)
/*! JTAGSW_MASK - JTAGSW reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_JTAGSW_MASK(x)        (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_JTAGSW_MASK_SHIFT)) & SRC_GENERAL_SRMASK_JTAGSW_MASK_MASK)

#define SRC_GENERAL_SRMASK_CM33_RESET_MASK_MASK  (0x100U)
#define SRC_GENERAL_SRMASK_CM33_RESET_MASK_SHIFT (8U)
/*! CM33_RESET_MASK - CM33 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_CM33_RESET_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM33_RESET_MASK_SHIFT)) & SRC_GENERAL_SRMASK_CM33_RESET_MASK_MASK)

#define SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_MASK (0x200U)
#define SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_SHIFT (9U)
/*! CM33_LOCKUP_MASK - CM33 lockup mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_SHIFT)) & SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_MASK)

#define SRC_GENERAL_SRMASK_CM7_RESET_MASK_MASK   (0x400U)
#define SRC_GENERAL_SRMASK_CM7_RESET_MASK_SHIFT  (10U)
/*! CM7_RESET_MASK - CM7 reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_CM7_RESET_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM7_RESET_MASK_SHIFT)) & SRC_GENERAL_SRMASK_CM7_RESET_MASK_MASK)

#define SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_MASK  (0x800U)
#define SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_SHIFT (11U)
/*! CM7_LOCKUP_MASK - CM7 lockup reset mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_SHIFT)) & SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_MASK)

#define SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_MASK   (0x1000U)
#define SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_SHIFT  (12U)
/*! DCDC_OVVT_MASK - DCDC over voltage mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_DCDC_OVVT_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_SHIFT)) & SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_MASK)

#define SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_MASK   (0x2000U)
#define SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_SHIFT  (13U)
/*! ECAT_RSTO_MASK - ECAT reset output mask
 *  0b0..The reset source can work
 *  0b1..The reset source is masked, cannot work
 */
#define SRC_GENERAL_SRMASK_ECAT_RSTO_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_SHIFT)) & SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_MASK)

#define SRC_GENERAL_SRMASK_WDOG1_MASK_LOCKED_MASK (0x10000U)
#define SRC_GENERAL_SRMASK_WDOG1_MASK_LOCKED_SHIFT (16U)
/*! WDOG1_MASK_LOCKED - Lock WDOG1_MASK
 *  0b0..This bit and WDOG1_MASK's value can be changed.
 *  0b1..This bit and WDOG1_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_WDOG1_MASK_LOCKED(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG1_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_WDOG1_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_WDOG2_MASK_LOCKED_MASK (0x20000U)
#define SRC_GENERAL_SRMASK_WDOG2_MASK_LOCKED_SHIFT (17U)
/*! WDOG2_MASK_LOCKED - Lock WDOG2_MASK
 *  0b0..This bit and WDOG2_MASK's value can be changed.
 *  0b1..This bit and WDOG2_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_WDOG2_MASK_LOCKED(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG2_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_WDOG2_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_WDOG3_MASK_LOCKED_MASK (0x40000U)
#define SRC_GENERAL_SRMASK_WDOG3_MASK_LOCKED_SHIFT (18U)
/*! WDOG3_MASK_LOCKED - Lock WDOG3_MASK
 *  0b0..This bit and WDOG3_MASK's value can be changed.
 *  0b1..This bit and WDOG3_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_WDOG3_MASK_LOCKED(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG3_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_WDOG3_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_WDOG4_MASK_LOCKED_MASK (0x80000U)
#define SRC_GENERAL_SRMASK_WDOG4_MASK_LOCKED_SHIFT (19U)
/*! WDOG4_MASK_LOCKED - Lock WDOG4_MASK
 *  0b0..This bit and WDOG4_MASK's value can be changed.
 *  0b1..This bit and WDOG4_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_WDOG4_MASK_LOCKED(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG4_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_WDOG4_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_WDOG5_MASK_LOCKED_MASK (0x100000U)
#define SRC_GENERAL_SRMASK_WDOG5_MASK_LOCKED_SHIFT (20U)
/*! WDOG5_MASK_LOCKED - Lock WDOG5_MASK
 *  0b0..This bit and WDOG5_MASK's value can be changed.
 *  0b1..This bit and WDOG5_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_WDOG5_MASK_LOCKED(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_WDOG5_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_WDOG5_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_TEMPSENSE_MASK_LOCKED_MASK (0x200000U)
#define SRC_GENERAL_SRMASK_TEMPSENSE_MASK_LOCKED_SHIFT (21U)
/*! TEMPSENSE_MASK_LOCKED - Lock TEMPSENSE_MASK
 *  0b0..TEMPSENSE_MASK's value can be changed.
 *  0b1..This bit and TEMPSENSE_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_TEMPSENSE_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_TEMPSENSE_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_TEMPSENSE_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_EDGELOCK_MASK_LOCKED_MASK (0x400000U)
#define SRC_GENERAL_SRMASK_EDGELOCK_MASK_LOCKED_SHIFT (22U)
/*! EDGELOCK_MASK_LOCKED - Lock EDGELOCK_MASK
 *  0b0..EDGELOCK_MASK's value can be changed.
 *  0b1..This bit and EDGELOCK_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_EDGELOCK_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_EDGELOCK_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_EDGELOCK_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_JTAGSW_MASK_LOCKED_MASK (0x800000U)
#define SRC_GENERAL_SRMASK_JTAGSW_MASK_LOCKED_SHIFT (23U)
/*! JTAGSW_MASK_LOCKED - Lock JTAGSW_MASK
 *  0b0..JTAGSW_MASK's value can be changed.
 *  0b1..This bit and JTAGSW_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_JTAGSW_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_JTAGSW_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_JTAGSW_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_CM33_RESET_MASK_LOCKED_MASK (0x1000000U)
#define SRC_GENERAL_SRMASK_CM33_RESET_MASK_LOCKED_SHIFT (24U)
/*! CM33_RESET_MASK_LOCKED - Lock CM33_RESET_MASK
 *  0b0..CM33_RESET_MASK's value can be changed.
 *  0b1..This bit and CM33_RESET_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_CM33_RESET_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM33_RESET_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_CM33_RESET_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_LOCKED_MASK (0x2000000U)
#define SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_LOCKED_SHIFT (25U)
/*! CM33_LOCKUP_MASK_LOCKED - Lock CM33_LOCKUP_MASK
 *  0b0..CM33_LOCKUP_MASK's value can be changed.
 *  0b1..This bit and CM33_LOCKUP_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_CM33_LOCKUP_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_CM7_RESET_MASK_LOCKED_MASK (0x4000000U)
#define SRC_GENERAL_SRMASK_CM7_RESET_MASK_LOCKED_SHIFT (26U)
/*! CM7_RESET_MASK_LOCKED - Lock CM7 reset mask bit
 *  0b0..CM7_RESET_MASK's value can be changed.
 *  0b1..This bit and CM7_RESET_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_CM7_RESET_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM7_RESET_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_CM7_RESET_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_LOCKED_MASK (0x8000000U)
#define SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_LOCKED_SHIFT (27U)
/*! CM7_LOCKUP_MASK_LOCKED - Lock CM7_LOCKUP_MASK
 *  0b0..CM7_LOCKUP_MASK's value can be changed.
 *  0b1..This bit and CM7_LOCKUP_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_CM7_LOCKUP_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_LOCKED_MASK (0x10000000U)
#define SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_LOCKED_SHIFT (28U)
/*! DCDC_OVVT_MASK_LOCKED - Lock DCDC_OVVT_MASK
 *  0b0..DCDC_OVVT_MASK's value can be changed.
 *  0b1..This bit and DCDC_OVVT_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_DCDC_OVVT_MASK_LOCKED_MASK)

#define SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_LOCKED_MASK (0x20000000U)
#define SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_LOCKED_SHIFT (29U)
/*! ECAT_RSTO_MASK_LOCKED - Lock ECAT_RSTO_MASK
 *  0b0..ECAT_RSTO_MASK's value can be changed.
 *  0b1..This bit and ECAT_RSTO_MASK's value cannot be changed.
 */
#define SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_LOCKED_SHIFT)) & SRC_GENERAL_SRMASK_ECAT_RSTO_MASK_LOCKED_MASK)
/*! @} */

/*! @name SBMR1 - SRC Boot Mode Register 1 */
/*! @{ */

#define SRC_GENERAL_SBMR1_BOOT_CFG1_MASK         (0xFFU)
#define SRC_GENERAL_SBMR1_BOOT_CFG1_SHIFT        (0U)
/*! BOOT_CFG1 - Reserved. */
#define SRC_GENERAL_SBMR1_BOOT_CFG1(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SBMR1_BOOT_CFG1_SHIFT)) & SRC_GENERAL_SBMR1_BOOT_CFG1_MASK)

#define SRC_GENERAL_SBMR1_BOOT_CFG2_MASK         (0xFF00U)
#define SRC_GENERAL_SBMR1_BOOT_CFG2_SHIFT        (8U)
/*! BOOT_CFG2 - Reserved. */
#define SRC_GENERAL_SBMR1_BOOT_CFG2(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SBMR1_BOOT_CFG2_SHIFT)) & SRC_GENERAL_SBMR1_BOOT_CFG2_MASK)

#define SRC_GENERAL_SBMR1_BOOT_CFG3_MASK         (0xFF0000U)
#define SRC_GENERAL_SBMR1_BOOT_CFG3_SHIFT        (16U)
/*! BOOT_CFG3 - Reserved. */
#define SRC_GENERAL_SBMR1_BOOT_CFG3(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SBMR1_BOOT_CFG3_SHIFT)) & SRC_GENERAL_SBMR1_BOOT_CFG3_MASK)

#define SRC_GENERAL_SBMR1_BOOT_CFG4_MASK         (0xFF000000U)
#define SRC_GENERAL_SBMR1_BOOT_CFG4_SHIFT        (24U)
/*! BOOT_CFG4 - Reserved. */
#define SRC_GENERAL_SBMR1_BOOT_CFG4(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SBMR1_BOOT_CFG4_SHIFT)) & SRC_GENERAL_SBMR1_BOOT_CFG4_MASK)
/*! @} */

/*! @name SBMR2 - SRC Boot Mode Register 2 */
/*! @{ */

#define SRC_GENERAL_SBMR2_IPP_BOOT_MODE_MASK     (0x3F000000U)
#define SRC_GENERAL_SBMR2_IPP_BOOT_MODE_SHIFT    (24U)
/*! IPP_BOOT_MODE
 *  0b000000..Boot from internal Fuses
 *  0b000001..Serial Downloader: USB1 or LPUART1
 *  0b000010..USDHC1 8-bit eMMC 5.1
 *  0b000011..USDHC2 4-bit SD 3.0
 *  0b000100..FlexSPI Serial NOR with SFDP (JESD-216) discoverable parameters
 *  0b000101..FlexSPI Serial NAND 2k page
 *  0b000110..FlexSPI Serial NAND 4k page
 *  0b000111..Test mode/Infinite loop mode
 */
#define SRC_GENERAL_SBMR2_IPP_BOOT_MODE(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SBMR2_IPP_BOOT_MODE_SHIFT)) & SRC_GENERAL_SBMR2_IPP_BOOT_MODE_MASK)
/*! @} */

/*! @name SRSR_BBSM - SRC Reset Status Register backup in BBSM domain */
/*! @{ */

#define SRC_GENERAL_SRSR_BBSM_POR_RST_MASK       (0x1U)
#define SRC_GENERAL_SRSR_BBSM_POR_RST_SHIFT      (0U)
/*! POR_RST - Indicates whether the reset was the result of power up or chip PAD POR_B.
 *  0b0..Reset is not a result of power up or chip PAD POR_B.
 *  0b1..Reset is a result of power up or chip PAD POR_B.
 */
#define SRC_GENERAL_SRSR_BBSM_POR_RST(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_POR_RST_SHIFT)) & SRC_GENERAL_SRSR_BBSM_POR_RST_MASK)

#define SRC_GENERAL_SRSR_BBSM_WDOG1_RST_B_MASK   (0x2U)
#define SRC_GENERAL_SRSR_BBSM_WDOG1_RST_B_SHIFT  (1U)
/*! WDOG1_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog1 time-out event.
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_BBSM_WDOG1_RST_B(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_WDOG1_RST_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_WDOG1_RST_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_WDOG2_RST_B_MASK   (0x4U)
#define SRC_GENERAL_SRSR_BBSM_WDOG2_RST_B_SHIFT  (2U)
/*! WDOG2_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog2 time-out event.
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_BBSM_WDOG2_RST_B(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_WDOG2_RST_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_WDOG2_RST_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_WDOG3_RST_B_MASK   (0x8U)
#define SRC_GENERAL_SRSR_BBSM_WDOG3_RST_B_SHIFT  (3U)
/*! WDOG3_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog3 time-out
 *  0b0..Reset is not a result of the watchdog3 time-out event.
 *  0b1..Reset is a result of the watchdog3 time-out event.
 */
#define SRC_GENERAL_SRSR_BBSM_WDOG3_RST_B(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_WDOG3_RST_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_WDOG3_RST_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_WDOG4_RST_B_MASK   (0x10U)
#define SRC_GENERAL_SRSR_BBSM_WDOG4_RST_B_SHIFT  (4U)
/*! WDOG4_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog4 time-out
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_BBSM_WDOG4_RST_B(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_WDOG4_RST_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_WDOG4_RST_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_WDOG5_RST_B_MASK   (0x20U)
#define SRC_GENERAL_SRSR_BBSM_WDOG5_RST_B_SHIFT  (5U)
/*! WDOG5_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog5 time-out
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_BBSM_WDOG5_RST_B(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_WDOG5_RST_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_WDOG5_RST_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_TEMPSENSE_RST_B_MASK (0x40U)
#define SRC_GENERAL_SRSR_BBSM_TEMPSENSE_RST_B_SHIFT (6U)
/*! TEMPSENSE_RST_B - TempSensor software reset. Indicates whether the reset was the result of software reset from on-chip Temperature Sensor.
 *  0b0..Reset is not a result of software reset from Temperature Sensor.
 *  0b1..Reset is a result of software reset from Temperature Sensor.
 */
#define SRC_GENERAL_SRSR_BBSM_TEMPSENSE_RST_B(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_TEMPSENSE_RST_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_TEMPSENSE_RST_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_EDGELOCK_RESET_B_MASK (0x80U)
#define SRC_GENERAL_SRSR_BBSM_EDGELOCK_RESET_B_SHIFT (7U)
/*! EDGELOCK_RESET_B - Indicates whether the reset was the result of the Edgelock's reset input.
 *  0b0..Reset is not a result of the Edgelock's reset event.
 *  0b1..Reset is a result of the Edgelock's reset event.
 */
#define SRC_GENERAL_SRSR_BBSM_EDGELOCK_RESET_B(x) (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_EDGELOCK_RESET_B_SHIFT)) & SRC_GENERAL_SRSR_BBSM_EDGELOCK_RESET_B_MASK)

#define SRC_GENERAL_SRSR_BBSM_JTAG_SW_RST_MASK   (0x100U)
#define SRC_GENERAL_SRSR_BBSM_JTAG_SW_RST_SHIFT  (8U)
/*! JTAG_SW_RST - JTAG software reset. Indicates whether the reset was the result of software reset from JTAG.
 *  0b0..Reset is not a result of software reset from JTAG.
 *  0b1..Reset is a result of software reset from JTAG.
 */
#define SRC_GENERAL_SRSR_BBSM_JTAG_SW_RST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_JTAG_SW_RST_SHIFT)) & SRC_GENERAL_SRSR_BBSM_JTAG_SW_RST_MASK)

#define SRC_GENERAL_SRSR_BBSM_CM33_REQUEST_MASK  (0x200U)
#define SRC_GENERAL_SRSR_BBSM_CM33_REQUEST_SHIFT (9U)
/*! CM33_REQUEST - Indicates whether reset was the result of cm33 reset request
 *  0b0..Reset is not a result of cm33 reset request.
 *  0b1..Reset is a result of cm33 reset request.
 */
#define SRC_GENERAL_SRSR_BBSM_CM33_REQUEST(x)    (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_CM33_REQUEST_SHIFT)) & SRC_GENERAL_SRSR_BBSM_CM33_REQUEST_MASK)

#define SRC_GENERAL_SRSR_BBSM_CM33_LOCKUP_MASK   (0x400U)
#define SRC_GENERAL_SRSR_BBSM_CM33_LOCKUP_SHIFT  (10U)
/*! CM33_LOCKUP - Indicates a reset has been caused by cm33 CPU lockup
 *  0b0..Reset is not a result of the cm33 lockup.
 *  0b1..Reset is a result of the cm33 lockup.
 */
#define SRC_GENERAL_SRSR_BBSM_CM33_LOCKUP(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_CM33_LOCKUP_SHIFT)) & SRC_GENERAL_SRSR_BBSM_CM33_LOCKUP_MASK)

#define SRC_GENERAL_SRSR_BBSM_CM7_REQUEST_MASK   (0x800U)
#define SRC_GENERAL_SRSR_BBSM_CM7_REQUEST_SHIFT  (11U)
/*! CM7_REQUEST - Indicates whether reset was the result of cm7 reset request
 *  0b0..Reset is not a result of cm7 reset request.
 *  0b1..Reset is a result of cm7 reset request.
 */
#define SRC_GENERAL_SRSR_BBSM_CM7_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_CM7_REQUEST_SHIFT)) & SRC_GENERAL_SRSR_BBSM_CM7_REQUEST_MASK)

#define SRC_GENERAL_SRSR_BBSM_CM7_LOCKUP_MASK    (0x1000U)
#define SRC_GENERAL_SRSR_BBSM_CM7_LOCKUP_SHIFT   (12U)
/*! CM7_LOCKUP - Indicates a reset has been caused by CM7 CPU
 *  0b0..Reset is not a result of the cm7 lockup.
 *  0b1..Reset is a result of the cm7 lockup.
 */
#define SRC_GENERAL_SRSR_BBSM_CM7_LOCKUP(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_CM7_LOCKUP_SHIFT)) & SRC_GENERAL_SRSR_BBSM_CM7_LOCKUP_MASK)

#define SRC_GENERAL_SRSR_BBSM_DCDC_OVVT_MASK     (0x2000U)
#define SRC_GENERAL_SRSR_BBSM_DCDC_OVVT_SHIFT    (13U)
/*! DCDC_OVVT - Indicates a reset has been caused by DCDC over voltage
 *  0b0..Reset is not a result of the DCDC over voltage.
 *  0b1..Reset is a result of the DCDC over voltage.
 */
#define SRC_GENERAL_SRSR_BBSM_DCDC_OVVT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_DCDC_OVVT_SHIFT)) & SRC_GENERAL_SRSR_BBSM_DCDC_OVVT_MASK)

#define SRC_GENERAL_SRSR_BBSM_ECAT_RSTO_MASK     (0x4000U)
#define SRC_GENERAL_SRSR_BBSM_ECAT_RSTO_SHIFT    (14U)
/*! ECAT_RSTO - Indicates a reset has been caused by ECAT reset output
 *  0b0..Reset is not a result of the ECAT reset output.
 *  0b1..Reset is a result of the ECAT reset output.
 */
#define SRC_GENERAL_SRSR_BBSM_ECAT_RSTO(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_BBSM_ECAT_RSTO_SHIFT)) & SRC_GENERAL_SRSR_BBSM_ECAT_RSTO_MASK)
/*! @} */

/*! @name SRSR - SRC Reset Status Register */
/*! @{ */

#define SRC_GENERAL_SRSR_POR_RST_MASK            (0x1U)
#define SRC_GENERAL_SRSR_POR_RST_SHIFT           (0U)
/*! POR_RST - Indicates whether the reset was the result of POR.
 *  0b0..Reset is not a result of POR.
 *  0b1..Reset is a result of POR.
 */
#define SRC_GENERAL_SRSR_POR_RST(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_POR_RST_SHIFT)) & SRC_GENERAL_SRSR_POR_RST_MASK)

#define SRC_GENERAL_SRSR_WDOG1_RST_B_MASK        (0x2U)
#define SRC_GENERAL_SRSR_WDOG1_RST_B_SHIFT       (1U)
/*! WDOG1_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog1 time-out event.
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_WDOG1_RST_B(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_WDOG1_RST_B_SHIFT)) & SRC_GENERAL_SRSR_WDOG1_RST_B_MASK)

#define SRC_GENERAL_SRSR_WDOG2_RST_B_MASK        (0x4U)
#define SRC_GENERAL_SRSR_WDOG2_RST_B_SHIFT       (2U)
/*! WDOG2_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog2 time-out event.
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_WDOG2_RST_B(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_WDOG2_RST_B_SHIFT)) & SRC_GENERAL_SRSR_WDOG2_RST_B_MASK)

#define SRC_GENERAL_SRSR_WDOG3_RST_B_MASK        (0x8U)
#define SRC_GENERAL_SRSR_WDOG3_RST_B_SHIFT       (3U)
/*! WDOG3_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog3 time-out
 *  0b0..Reset is not a result of the watchdog3 time-out event.
 *  0b1..Reset is a result of the watchdog3 time-out event.
 */
#define SRC_GENERAL_SRSR_WDOG3_RST_B(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_WDOG3_RST_B_SHIFT)) & SRC_GENERAL_SRSR_WDOG3_RST_B_MASK)

#define SRC_GENERAL_SRSR_WDOG4_RST_B_MASK        (0x10U)
#define SRC_GENERAL_SRSR_WDOG4_RST_B_SHIFT       (4U)
/*! WDOG4_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog4 time-out
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_WDOG4_RST_B(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_WDOG4_RST_B_SHIFT)) & SRC_GENERAL_SRSR_WDOG4_RST_B_MASK)

#define SRC_GENERAL_SRSR_WDOG5_RST_B_MASK        (0x20U)
#define SRC_GENERAL_SRSR_WDOG5_RST_B_SHIFT       (5U)
/*! WDOG5_RST_B - Time-out reset. Indicates whether the reset was the result of the watchdog5 time-out
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_GENERAL_SRSR_WDOG5_RST_B(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_WDOG5_RST_B_SHIFT)) & SRC_GENERAL_SRSR_WDOG5_RST_B_MASK)

#define SRC_GENERAL_SRSR_TEMPSENSE_RST_B_MASK    (0x40U)
#define SRC_GENERAL_SRSR_TEMPSENSE_RST_B_SHIFT   (6U)
/*! TEMPSENSE_RST_B - Temper Sensor software reset. Indicates whether the reset was the result of
 *    software reset from on-chip Temperature Sensor.
 *  0b0..Reset is not a result of software reset from Temperature Sensor.
 *  0b1..Reset is a result of software reset from Temperature Sensor.
 */
#define SRC_GENERAL_SRSR_TEMPSENSE_RST_B(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_TEMPSENSE_RST_B_SHIFT)) & SRC_GENERAL_SRSR_TEMPSENSE_RST_B_MASK)

#define SRC_GENERAL_SRSR_EDGELOCK_RESET_B_MASK   (0x80U)
#define SRC_GENERAL_SRSR_EDGELOCK_RESET_B_SHIFT  (7U)
/*! EDGELOCK_RESET_B - Indicates whether the reset was the result of the Edgelock's reset input.
 *  0b0..Reset is not a result of the Edgelock's reset event.
 *  0b1..Reset is a result of the Edgelock's reset event.
 */
#define SRC_GENERAL_SRSR_EDGELOCK_RESET_B(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_EDGELOCK_RESET_B_SHIFT)) & SRC_GENERAL_SRSR_EDGELOCK_RESET_B_MASK)

#define SRC_GENERAL_SRSR_JTAG_SW_RST_MASK        (0x100U)
#define SRC_GENERAL_SRSR_JTAG_SW_RST_SHIFT       (8U)
/*! JTAG_SW_RST - JTAG software reset. Indicates whether the reset was the result of software reset from JTAG.
 *  0b0..Reset is not a result of software reset from JTAG.
 *  0b1..Reset is a result of software reset from JTAG.
 */
#define SRC_GENERAL_SRSR_JTAG_SW_RST(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_JTAG_SW_RST_SHIFT)) & SRC_GENERAL_SRSR_JTAG_SW_RST_MASK)

#define SRC_GENERAL_SRSR_CM33_REQUEST_MASK       (0x200U)
#define SRC_GENERAL_SRSR_CM33_REQUEST_SHIFT      (9U)
/*! CM33_REQUEST - Indicates whether reset was the result of cm33 reset request
 *  0b0..Reset is not a result of cm33 reset request.
 *  0b1..Reset is a result of cm33 reset request.
 */
#define SRC_GENERAL_SRSR_CM33_REQUEST(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_CM33_REQUEST_SHIFT)) & SRC_GENERAL_SRSR_CM33_REQUEST_MASK)

#define SRC_GENERAL_SRSR_CM33_LOCKUP_MASK        (0x400U)
#define SRC_GENERAL_SRSR_CM33_LOCKUP_SHIFT       (10U)
/*! CM33_LOCKUP - Indicates a reset has been caused by cm33 CPU lockup
 *  0b0..Reset is not a result of the cm33 lockup.
 *  0b1..Reset is a result of the cm33 lockup.
 */
#define SRC_GENERAL_SRSR_CM33_LOCKUP(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_CM33_LOCKUP_SHIFT)) & SRC_GENERAL_SRSR_CM33_LOCKUP_MASK)

#define SRC_GENERAL_SRSR_CM7_REQUEST_MASK        (0x800U)
#define SRC_GENERAL_SRSR_CM7_REQUEST_SHIFT       (11U)
/*! CM7_REQUEST - Indicates whether reset was the result of cm7 reset request
 *  0b0..Reset is not a result of cm7 reset request.
 *  0b1..Reset is a result of cm7 reset request.
 */
#define SRC_GENERAL_SRSR_CM7_REQUEST(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_CM7_REQUEST_SHIFT)) & SRC_GENERAL_SRSR_CM7_REQUEST_MASK)

#define SRC_GENERAL_SRSR_CM7_LOCKUP_MASK         (0x1000U)
#define SRC_GENERAL_SRSR_CM7_LOCKUP_SHIFT        (12U)
/*! CM7_LOCKUP - Indicates a reset has been caused by CM7 CPU
 *  0b0..Reset is not a result of the cm7 lockup.
 *  0b1..Reset is a result of the cm7 lockup.
 */
#define SRC_GENERAL_SRSR_CM7_LOCKUP(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_CM7_LOCKUP_SHIFT)) & SRC_GENERAL_SRSR_CM7_LOCKUP_MASK)

#define SRC_GENERAL_SRSR_DCDC_OVVT_MASK          (0x2000U)
#define SRC_GENERAL_SRSR_DCDC_OVVT_SHIFT         (13U)
/*! DCDC_OVVT - Indicates a reset has been caused by DCDC over voltage
 *  0b0..Reset is not a result of the DCDC over voltage.
 *  0b1..Reset is a result of the DCDC over voltage.
 */
#define SRC_GENERAL_SRSR_DCDC_OVVT(x)            (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_DCDC_OVVT_SHIFT)) & SRC_GENERAL_SRSR_DCDC_OVVT_MASK)

#define SRC_GENERAL_SRSR_ECAT_RSTO_MASK          (0x4000U)
#define SRC_GENERAL_SRSR_ECAT_RSTO_SHIFT         (14U)
/*! ECAT_RSTO - Indicates a reset has been caused by ECAT reset output
 *  0b0..Reset is not a result of the ECAT reset output.
 *  0b1..Reset is a result of the ECAT reset output.
 */
#define SRC_GENERAL_SRSR_ECAT_RSTO(x)            (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_ECAT_RSTO_SHIFT)) & SRC_GENERAL_SRSR_ECAT_RSTO_MASK)

#define SRC_GENERAL_SRSR_IPP_POR_B_MASK          (0x10000U)
#define SRC_GENERAL_SRSR_IPP_POR_B_SHIFT         (16U)
/*! IPP_POR_B - Indicates whether the reset was the result of chip PAD POR_B.
 *  0b0..Reset is not a result of chip PAD POR_B.
 *  0b1..Reset is a result of chip PAD POR_B.
 */
#define SRC_GENERAL_SRSR_IPP_POR_B(x)            (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_SRSR_IPP_POR_B_SHIFT)) & SRC_GENERAL_SRSR_IPP_POR_B_MASK)
/*! @} */

/*! @name GPR - SRC General Purpose Register */
/*! @{ */

#define SRC_GENERAL_GPR_GPR_MASK                 (0xFFFFFFFFU)
#define SRC_GENERAL_GPR_GPR_SHIFT                (0U)
/*! GPR - General Purpose Register. */
#define SRC_GENERAL_GPR_GPR(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_GENERAL_GPR_GPR_SHIFT)) & SRC_GENERAL_GPR_GPR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_GENERAL_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_GENERAL_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_GENERAL_H_ */

