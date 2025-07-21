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
**         CMSIS Peripheral Access Layer for SRC_MIX_SLICE
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
 * @file PERI_SRC_MIX_SLICE.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC_MIX_SLICE
 *
 * CMSIS Peripheral Access Layer for SRC_MIX_SLICE
 */

#if !defined(PERI_SRC_MIX_SLICE_H_)
#define PERI_SRC_MIX_SLICE_H_                    /**< Symbol preventing repeated inclusion */

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
   -- SRC_MIX_SLICE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MIX_SLICE_Peripheral_Access_Layer SRC_MIX_SLICE Peripheral Access Layer
 * @{
 */

/** SRC_MIX_SLICE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SLICE_SW_CTRL;                     /**< SLICE Software Control, offset: 0x10 */
  __I  uint32_t FUNC_STAT;                         /**< Function Status, offset: 0x14 */
       uint8_t RESERVED_2[8];
  __I  uint32_t UPI_STAT_0;                        /**< UPI Status 0, offset: 0x20 */
  __I  uint32_t UPI_STAT_1;                        /**< UPI Status 1, offset: 0x24 */
       uint8_t RESERVED_3[8];
  __IO uint32_t LPM_SETTING_0;                     /**< Low Power Mode Setting 0, offset: 0x30 */
  __IO uint32_t LPM_SETTING_1;                     /**< Low Power Mode Setting 1, offset: 0x34 */
  __IO uint32_t LPM_SETTING_2;                     /**< Low Power Mode Setting 2, offset: 0x38 */
       uint8_t RESERVED_4[4];
  __IO uint32_t EDGELOCK_HDSK_CTRL;                /**< Edgelock Handshake Control, offset: 0x40 */
  __I  uint32_t EDGELOCK_HDSK_STAT;                /**< Edgelock Handshake Status, offset: 0x44 */
  __IO uint32_t EDGELOCK_HDSK_CNT_CFG;             /**< Edgelock Handshake Counter Config, offset: 0x48 */
  __I  uint32_t EDGELOCK_HDSK_CNT_STAT;            /**< Edgelock Handshake Counter Status, offset: 0x4C */
  __IO uint32_t ISO_DLY_PRE;                       /**< ISO Delay Pre control, offset: 0x50 */
  __IO uint32_t PSW_DLY_PRE_HF;                    /**< PSW Delay Pre for HF, offset: 0x54 */
  __IO uint32_t PSW_DLY_PRE_LF;                    /**< PSW Delay Pre for LF, offset: 0x58 */
  __IO uint32_t PSW_CTRL;                          /**< PSW Control, offset: 0x5C */
  __I  uint32_t PSW_STAT;                          /**< PSW Status, offset: 0x60 */
  __IO uint32_t PSW_CNT_CFG_HF;                    /**< PSW Counter Config for HF, offset: 0x64 */
  __I  uint32_t PSW_CNT_STAT_HF;                   /**< PSW Counter Status for HF, offset: 0x68 */
  __IO uint32_t PSW_CNT_CFG_LF;                    /**< PSW Counter Config for LF, offset: 0x6C */
  __I  uint32_t PSW_CNT_STAT_LF;                   /**< PSW Counter Status for LF, offset: 0x70 */
       uint8_t RESERVED_5[12];
  __IO uint32_t MLPL_TRIG_CTRL;                    /**< Memory Low Power Level Trigger Control, offset: 0x80 */
  __IO uint32_t MLPL_CFG;                          /**< Memory Low Power Level Config, offset: 0x84 */
  __I  uint32_t MLPL_STAT;                         /**< Memory Low Power Level Status, offset: 0x88 */
} SRC_MIX_SLICE_Type;

/* ----------------------------------------------------------------------------
   -- SRC_MIX_SLICE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MIX_SLICE_Register_Masks SRC_MIX_SLICE Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - Authentication Control */
/*! @{ */

#define SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_MASK  (0x4U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_SHIFT (2U)
/*! LPM_MODE - HW low power mode
 *  0b0..Low power mode controlled by software. SLICE_SW_CTRL register can be updated. LPM_SETTING_0 register cannot be updated.
 *  0b1..Low power mode controlled by GPC. SLICE_SW_CTRL register cannot be updated. LPM_SETTING_0 register can be updated.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LPM_MODE_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_MASK  (0x80U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..Registers are not locked.
 *  0b1..Fields and registers in the list are locked.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_CFG_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_MASK   (0x100U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_SHIFT  (8U)
/*! TZ_USER - Allow user mode write
 *  0b0..The MIX SLICE registers and its MEM Type I/II registers can only be written in privilege mode.
 *  0b1..The MIX SLICE registers and its MEM Type I/II registers can be written either in privilege mode or user mode.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_TZ_USER_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_MASK     (0x200U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_SHIFT    (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..The MIX SLICE registers and its MEM Type I/II registers can only be written in secure mode.
 *  0b1..The MIX SLICE registers and its MEM Type I/II registers can be written either in secure mode or non-secure mode.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_TZ_NS_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_MASK   (0x800U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_SHIFT  (11U)
/*! LOCK_TZ - Lock TZ_NS and TZ_USER
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER value cannot be changed.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_TZ_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST value cannot be changed.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_LOCK_LIST_MASK)

#define SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write SRC MIX SLICE registers.
 *  0b0000000000000010..Core with domain ID=1 can write SRC MIX SLICE registers.
 *  0b0000000000000100..Core with domain ID=2 can write SRC MIX SLICE registers.
 *  0b0000000000001000..Core with domain ID=3 can write SRC MIX SLICE registers.
 *  0b0000000000010000..Core with domain ID=4 can write SRC MIX SLICE registers.
 *  0b0000000000100000..Core with domain ID=5 can write SRC MIX SLICE registers.
 *  0b0000000001000000..Core with domain ID=6 can write SRC MIX SLICE registers.
 *  0b0000000010000000..Core with domain ID=7 can write SRC MIX SLICE registers.
 *  0b0000000100000000..Core with domain ID=8 can write SRC MIX SLICE registers.
 *  0b0000001000000000..Core with domain ID=9 can write SRC MIX SLICE registers.
 *  0b0000010000000000..Core with domain ID=10 can write SRC MIX SLICE registers.
 *  0b0000100000000000..Core with domain ID=11 can write SRC MIX SLICE registers.
 *  0b0001000000000000..Core with domain ID=12 can write SRC MIX SLICE registers.
 *  0b0010000000000000..Core with domain ID=13 can write SRC MIX SLICE registers.
 *  0b0100000000000000..Core with domain ID=14 can write SRC MIX SLICE registers.
 *  0b1000000000000000..Core with domain ID=15 can write SRC MIX SLICE registers.
 */
#define SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & SRC_MIX_SLICE_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name SLICE_SW_CTRL - SLICE Software Control */
/*! @{ */

#define SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_OFF_SOFT_MASK (0x1U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_OFF_SOFT_SHIFT (0U)
/*! PSW_OFF_SOFT - Software power off control. This field can only be updated while LPM_MODE=0.
 *  0b0..Clear to 0 to trigger power switch on
 *  0b1..Write 1 to trigger power switch off
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_OFF_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_OFF_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_PSW_OFF_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_MASK (0x4U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_SHIFT (2U)
/*! RST_CTRL_SOFT - Software reset control. This field can only be updated while LPM_MODE=0.
 *  0b0..Clear to 0 to trigger reset deassert
 *  0b1..Write 1 to trigger reset assert
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_RST_CTRL_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_ON_SOFT_MASK (0x10U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_ON_SOFT_SHIFT (4U)
/*! ISO_ON_SOFT - Software isolation on control. This field can only be updated while LPM_MODE=0.
 *  0b0..Clear to 0 to trigger isolation off
 *  0b1..Write 1 to trigger isolation on
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_ON_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_ON_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_ISO_ON_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_EDGELOCK_HDSK_SOFT_MASK (0x40U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_EDGELOCK_HDSK_SOFT_SHIFT (6U)
/*! EDGELOCK_HDSK_SOFT - Software Edgelock handshake control. This field can only be updated while LPM_MODE=0.
 *  0b0..Clear to 0 to trigger Edgelock handshake for power on.
 *  0b1..Write to 1 to trigger Edgelock handshake for power off.
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_EDGELOCK_HDSK_SOFT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_EDGELOCK_HDSK_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_EDGELOCK_HDSK_SOFT_MASK)

#define SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_MASK (0x80000000U)
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_SHIFT (31U)
/*! PDN_SOFT - By flow sequence, Software power down sequence includes Edgelock handshake for power
 *    down, isolation on, reset assert, power off; Software power up sequence includes power up,
 *    reset deassert, isolation off, Edgelock handshake for power up. This bit can only be updated
 *    while LPM_MODE=0.
 *  0b0..Clear to 0 to trigger a power up sequence.
 *  0b1..Write 1 to trigger a power down sequence.
 */
#define SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_SHIFT)) & SRC_MIX_SLICE_SLICE_SW_CTRL_PDN_SOFT_MASK)
/*! @} */

/*! @name FUNC_STAT - Function Status */
/*! @{ */

#define SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_MASK    (0x1U)
#define SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_SHIFT   (0U)
/*! PSW_STAT - power switch status
 *  0b0..power switch on
 *  0b1..power switch off
 */
#define SRC_MIX_SLICE_FUNC_STAT_PSW_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_PSW_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_RST_STAT_MASK    (0x4U)
#define SRC_MIX_SLICE_FUNC_STAT_RST_STAT_SHIFT   (2U)
/*! RST_STAT - reset status
 *  0b0..reset asserted
 *  0b1..reset released
 */
#define SRC_MIX_SLICE_FUNC_STAT_RST_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_RST_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_RST_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_MASK    (0x10U)
#define SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_SHIFT   (4U)
/*! ISO_STAT - isolation status
 *  0b0..isolation off
 *  0b1..isolation on
 */
#define SRC_MIX_SLICE_FUNC_STAT_ISO_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_ISO_STAT_MASK)

#define SRC_MIX_SLICE_FUNC_STAT_EDGELOCK_HDSK_STAT_MASK (0x40U)
#define SRC_MIX_SLICE_FUNC_STAT_EDGELOCK_HDSK_STAT_SHIFT (6U)
/*! EDGELOCK_HDSK_STAT - Edgelock handshake status
 *  0b0..no effect or power up handshake with Edgelock done
 *  0b1..power down handshake with Edgelock done
 */
#define SRC_MIX_SLICE_FUNC_STAT_EDGELOCK_HDSK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_FUNC_STAT_EDGELOCK_HDSK_STAT_SHIFT)) & SRC_MIX_SLICE_FUNC_STAT_EDGELOCK_HDSK_STAT_MASK)
/*! @} */

/*! @name UPI_STAT_0 - UPI Status 0 */
/*! @{ */

#define SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_MASK (0xFFFFU)
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_SHIFT (0U)
/*! UPI_ISO_REQUEST - CPU mode transfer to trigger isolation change request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_0_UPI_ISO_REQUEST_MASK)

#define SRC_MIX_SLICE_UPI_STAT_0_UPI_EDGELOCK_HDSK_REQUEST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_EDGELOCK_HDSK_REQUEST_SHIFT (16U)
/*! UPI_EDGELOCK_HDSK_REQUEST - CPU mode transfer to trigger Edgelock handshake request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_0_UPI_EDGELOCK_HDSK_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_0_UPI_EDGELOCK_HDSK_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_0_UPI_EDGELOCK_HDSK_REQUEST_MASK)
/*! @} */

/*! @name UPI_STAT_1 - UPI Status 1 */
/*! @{ */

#define SRC_MIX_SLICE_UPI_STAT_1_UPI_POWER_REQUEST_MASK (0xFFFFU)
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_POWER_REQUEST_SHIFT (0U)
/*! UPI_POWER_REQUEST - CPU mode transfer to trigger power switch request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_POWER_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_1_UPI_POWER_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_1_UPI_POWER_REQUEST_MASK)

#define SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_SHIFT (16U)
/*! UPI_RESET_REQUEST - CPU mode transfer to trigger reset change request of 16 domains */
#define SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_SHIFT)) & SRC_MIX_SLICE_UPI_STAT_1_UPI_RESET_REQUEST_MASK)
/*! @} */

/*! @name LPM_SETTING_0 - Low Power Mode Setting 0 */
/*! @{ */

#define SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_MASK (0x7U)
#define SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_SHIFT (0U)
/*! LPM_SETTING_CD - LPM setting of current domain */
#define SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_0_LPM_SETTING_CD_MASK)
/*! @} */

/*! @name LPM_SETTING_1 - Low Power Mode Setting 1 */
/*! @{ */

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_MASK (0x7U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_SHIFT (0U)
/*! LPM_SETTING_D0 - LPM setting of domain 0
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D0_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_MASK (0x70U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_SHIFT (4U)
/*! LPM_SETTING_D1 - LPM setting of domain 1
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D1_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_MASK (0x700U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_SHIFT (8U)
/*! LPM_SETTING_D2 - LPM setting of domain 2
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D2_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_MASK (0x7000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_SHIFT (12U)
/*! LPM_SETTING_D3 - LPM setting of domain 3
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D3_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_MASK (0x70000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_SHIFT (16U)
/*! LPM_SETTING_D4 - LPM setting of domain 4
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D4_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_MASK (0x700000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_SHIFT (20U)
/*! LPM_SETTING_D5 - LPM setting of domain 5
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D5_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_MASK (0x7000000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_SHIFT (24U)
/*! LPM_SETTING_D6 - LPM setting of domain 6
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D6_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_MASK (0x70000000U)
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_SHIFT (28U)
/*! LPM_SETTING_D7 - LPM setting of domain 7
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_1_LPM_SETTING_D7_MASK)
/*! @} */

/*! @name LPM_SETTING_2 - Low Power Mode Setting 2 */
/*! @{ */

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_MASK (0x7U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_SHIFT (0U)
/*! LPM_SETTING_D8 - LPM setting of domain 8
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D8_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_MASK (0x70U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_SHIFT (4U)
/*! LPM_SETTING_D9 - LPM setting of domain 9
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D9_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_MASK (0x700U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_SHIFT (8U)
/*! LPM_SETTING_D10 - LPM setting of domain 10
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D10_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_MASK (0x7000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_SHIFT (12U)
/*! LPM_SETTING_D11 - LPM setting of domain 11
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D11_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_MASK (0x70000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_SHIFT (16U)
/*! LPM_SETTING_D12 - LPM setting of domain 12
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D12_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_MASK (0x700000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_SHIFT (20U)
/*! LPM_SETTING_D13 - LPM setting of domain 13
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D13_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_MASK (0x7000000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_SHIFT (24U)
/*! LPM_SETTING_D14 - LPM setting of domain 14
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D14_MASK)

#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_MASK (0x70000000U)
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_SHIFT (28U)
/*! LPM_SETTING_D15 - LPM setting of domain 15
 *  0b000..Not used. Do not write this value.
 *  0b001..power on when domain n is in RUN, off in WAIT/STOP/SUSPEND
 *  0b010..power on when domain n is in RUN/WAIT, off in STOP/SUSPEND
 *  0b011..power on when domain n is in RUN/WAIT/STOP, off in SUSPEND
 *  0b100-0b111..power always on
 */
#define SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_SHIFT)) & SRC_MIX_SLICE_LPM_SETTING_2_LPM_SETTING_D15_MASK)
/*! @} */

/*! @name EDGELOCK_HDSK_CTRL - Edgelock Handshake Control */
/*! @{ */

#define SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_PON_CNT_MODE_MASK (0xC000U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_PON_CNT_MODE_SHIFT (14U)
/*! PON_CNT_MODE - Configures the acknowledge counter for power up working mode, locked by LOCK_CFG field
 *  0b00..Not use counter, raise Edgelock handshake done to GPC once get Edgelock ack
 *  0b01..Delay after receiving Edgelock ack, delay cycle number is PON_CNT_CFG
 *  0b10..Ignore Edgelock ack, raise Edgelock handshake done to GPC when counting to PON_CNT_CFG value
 *  0b11..Time out mode, raise Edgelock handshake done to GPC when either Edgelock ack received or counting to PON_CNT_CFG value
 */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_PON_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_PON_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_PON_CNT_MODE_MASK)

#define SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_POFF_CNT_MODE_MASK (0xC0000000U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_POFF_CNT_MODE_SHIFT (30U)
/*! POFF_CNT_MODE - Configures the acknowledge counter for power down working mode, locked by LOCK_CFG field
 *  0b00..Not use counter, raise Edgelock handshake done to GPC once get Edgelock ack
 *  0b01..Delay after receiving Edgelock ack, delay cycle number is POFF_CNT_CFG
 *  0b10..Ignore Edgelock ack, raise Edgelock handshake done to GPC when counting to POFF_CNT_CFG value
 *  0b11..Time out mode, raise Edgelock handshake done to GPC when either Edgelock ack received or counting to POFF_CNT_CFG value
 */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_POFF_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_POFF_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_CTRL_POFF_CNT_MODE_MASK)
/*! @} */

/*! @name EDGELOCK_HDSK_STAT - Edgelock Handshake Status */
/*! @{ */

#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_ACK_MASK (0x1U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_ACK_SHIFT (0U)
/*! PON_ACK - Indicates this mix power up sequence has accepted Edgelock ack
 *  0b0..Does not get Edgelock ack for power up.
 *  0b1..Gets Edgelock ack for power up.
 */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_ACK(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_ACK_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_ACK_MASK)

#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_BUSY_MASK (0x2U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_BUSY_SHIFT (1U)
/*! PON_BUSY - Busy requesting Edgelock handshake for power up
 *  0b0..Does not send Edgelock handshake for power up.
 *  0b1..Sends Edgelock handshake for power up.
 */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_BUSY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_BUSY_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_PON_BUSY_MASK)

#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_ACK_MASK (0x10000U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_ACK_SHIFT (16U)
/*! POFF_ACK - Indicates this mix power down sequence has accepted Edgelock ack
 *  0b0..Does not get Edgelock ack for power down.
 *  0b1..Gets Edgelock ack for power down.
 */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_ACK(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_ACK_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_ACK_MASK)

#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_BUSY_MASK (0x20000U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_BUSY_SHIFT (17U)
/*! POFF_BUSY - Busy requesting Edgelock handshake for power down
 *  0b0..Does not send Edgelock handshake for power down.
 *  0b1..Sends Edgelock handshake for power down.
 */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_BUSY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_BUSY_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_STAT_POFF_BUSY_MASK)
/*! @} */

/*! @name EDGELOCK_HDSK_CNT_CFG - Edgelock Handshake Counter Config */
/*! @{ */

#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_PON_CNT_CFG_MASK (0xFFFFU)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_PON_CNT_CFG_SHIFT (0U)
/*! PON_CNT_CFG - Edgelock handshake ack count for power up config: usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_PON_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_PON_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_PON_CNT_CFG_MASK)

#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_POFF_CNT_CFG_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_POFF_CNT_CFG_SHIFT (16U)
/*! POFF_CNT_CFG - Edgelock handshake ack count for power down config: usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_POFF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_POFF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_CFG_POFF_CNT_CFG_MASK)
/*! @} */

/*! @name EDGELOCK_HDSK_CNT_STAT - Edgelock Handshake Counter Status */
/*! @{ */

#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_PON_CNT_MASK (0xFFFFU)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_PON_CNT_SHIFT (0U)
/*! PON_CNT - Edgelock handshake for power up acknowledge count, record the delay from stat change to acknowledge received */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_PON_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_PON_CNT_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_PON_CNT_MASK)

#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_POFF_CNT_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_POFF_CNT_SHIFT (16U)
/*! POFF_CNT - Edgelock handshake for power down acknowledge count, record the delay from stat change to acknowledge received */
#define SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_POFF_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_POFF_CNT_SHIFT)) & SRC_MIX_SLICE_EDGELOCK_HDSK_CNT_STAT_POFF_CNT_MASK)
/*! @} */

/*! @name ISO_DLY_PRE - ISO Delay Pre control */
/*! @{ */

#define SRC_MIX_SLICE_ISO_DLY_PRE_ISO_OFF_CNT_MASK (0xFFFFU)
#define SRC_MIX_SLICE_ISO_DLY_PRE_ISO_OFF_CNT_SHIFT (0U)
/*! ISO_OFF_CNT - Delay from receiving iso off request to isolation disable, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_ISO_DLY_PRE_ISO_OFF_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_ISO_DLY_PRE_ISO_OFF_CNT_SHIFT)) & SRC_MIX_SLICE_ISO_DLY_PRE_ISO_OFF_CNT_MASK)

#define SRC_MIX_SLICE_ISO_DLY_PRE_ISO_ON_CNT_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_ISO_DLY_PRE_ISO_ON_CNT_SHIFT (16U)
/*! ISO_ON_CNT - Delay from receiving iso_on request to isolation enable, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_ISO_DLY_PRE_ISO_ON_CNT(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_ISO_DLY_PRE_ISO_ON_CNT_SHIFT)) & SRC_MIX_SLICE_ISO_DLY_PRE_ISO_ON_CNT_MASK)
/*! @} */

/*! @name PSW_DLY_PRE_HF - PSW Delay Pre for HF */
/*! @{ */

#define SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_ON_MASK (0xFFFFU)
#define SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_ON_SHIFT (0U)
/*! PSW_ON - Delay from receiving power on hf request to power switch turn on, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_ON(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_ON_SHIFT)) & SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_ON_MASK)

#define SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_OFF_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_OFF_SHIFT (16U)
/*! PSW_OFF - Delay from receiving power off hf request to power switch shut off, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_OFF(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_OFF_SHIFT)) & SRC_MIX_SLICE_PSW_DLY_PRE_HF_PSW_OFF_MASK)
/*! @} */

/*! @name PSW_DLY_PRE_LF - PSW Delay Pre for LF */
/*! @{ */

#define SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_ON_MASK (0xFFFFU)
#define SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_ON_SHIFT (0U)
/*! PSW_ON - Delay from receiving power on lf request to power switch turn on, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_ON(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_ON_SHIFT)) & SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_ON_MASK)

#define SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_OFF_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_OFF_SHIFT (16U)
/*! PSW_OFF - Delay from receiving power off lf request to power switch shut off, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_OFF(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_OFF_SHIFT)) & SRC_MIX_SLICE_PSW_DLY_PRE_LF_PSW_OFF_MASK)
/*! @} */

/*! @name PSW_CTRL - PSW Control */
/*! @{ */

#define SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_LF_MASK (0x1U)
#define SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_LF_SHIFT (0U)
/*! ACK_INVERT_LF - Acknowledge for low fanout value is inverted from power switch control, locked by LOCK_CFG field
 *  0b0..Use original signal as ack
 *  0b1..Use inverted original signal as ack
 */
#define SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_LF(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_LF_SHIFT)) & SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_LF_MASK)

#define SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_HF_MASK (0x2U)
#define SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_HF_SHIFT (1U)
/*! ACK_INVERT_HF - Acknowledge for high fanout value is inverted from power switch control, locked by LOCK_CFG field
 *  0b0..Use original signal as ack
 *  0b1..Use inverted original signal as ack
 */
#define SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_HF(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_HF_SHIFT)) & SRC_MIX_SLICE_PSW_CTRL_ACK_INVERT_HF_MASK)

#define SRC_MIX_SLICE_PSW_CTRL_PON_CNT_MODE_MASK (0xC000U)
#define SRC_MIX_SLICE_PSW_CTRL_PON_CNT_MODE_SHIFT (14U)
/*! PON_CNT_MODE - Configure the acknowledge counter for power up working mode, locked by LOCK_CFG field
 *  0b00..Not use counter, raise power_on/off done to GPC once get psw ack
 *  0b01..Delay after receiving psw ack, delay cycle number is PON_CNT_CFG
 *  0b10..Ignore psw ack, raise power_on/off done to GPC when counting to PON_CNT_CFG value
 *  0b11..Time out mode, raise power_on/off done to GPC when either psw ack received or counting to PON_CNT_CFG value
 */
#define SRC_MIX_SLICE_PSW_CTRL_PON_CNT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CTRL_PON_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_PSW_CTRL_PON_CNT_MODE_MASK)

#define SRC_MIX_SLICE_PSW_CTRL_POFF_CNT_MODE_MASK (0xC0000000U)
#define SRC_MIX_SLICE_PSW_CTRL_POFF_CNT_MODE_SHIFT (30U)
/*! POFF_CNT_MODE - Configures the acknowledge counter for power down working mode, locked by LOCK_CFG field
 *  0b00..Not use counter, raise power_on/off done to GPC once get psw ack
 *  0b01..Delay after receiving psw ack, delay cycle number is POFF_CNT_CFG. When POFF_CNT_CFG value in HF/LF is different, bigger value will be used.
 *  0b10..Ignore psw ack, raise power_on/off done to GPC when counting to POFF_CNT_CFG value. When POFF_CNT_CFG
 *        value in HF/LF is different, bigger value will be used.
 *  0b11..Time out mode, raise power_on/off done to GPC when either psw ack received or counting to POFF_CNT_CFG
 *        value. When POFF_CNT_CFG value in HF/LF is different, bigger value will be used.
 */
#define SRC_MIX_SLICE_PSW_CTRL_POFF_CNT_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CTRL_POFF_CNT_MODE_SHIFT)) & SRC_MIX_SLICE_PSW_CTRL_POFF_CNT_MODE_MASK)
/*! @} */

/*! @name PSW_STAT - PSW Status */
/*! @{ */

#define SRC_MIX_SLICE_PSW_STAT_ACK_STAT_LF_MASK  (0x1U)
#define SRC_MIX_SLICE_PSW_STAT_ACK_STAT_LF_SHIFT (0U)
/*! ACK_STAT_LF - Power switch acknowledge status for low fanout
 *  0b0..Does not get ack for power switch
 *  0b1..Gets ack for power switch
 */
#define SRC_MIX_SLICE_PSW_STAT_ACK_STAT_LF(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_STAT_ACK_STAT_LF_SHIFT)) & SRC_MIX_SLICE_PSW_STAT_ACK_STAT_LF_MASK)

#define SRC_MIX_SLICE_PSW_STAT_ACK_STAT_HF_MASK  (0x2U)
#define SRC_MIX_SLICE_PSW_STAT_ACK_STAT_HF_SHIFT (1U)
/*! ACK_STAT_HF - Power switch acknowledge status for high fanout
 *  0b0..Does not get ack for power switch
 *  0b1..Gets ack for power switch
 */
#define SRC_MIX_SLICE_PSW_STAT_ACK_STAT_HF(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_STAT_ACK_STAT_HF_SHIFT)) & SRC_MIX_SLICE_PSW_STAT_ACK_STAT_HF_MASK)
/*! @} */

/*! @name PSW_CNT_CFG_HF - PSW Counter Config for HF */
/*! @{ */

#define SRC_MIX_SLICE_PSW_CNT_CFG_HF_PON_CNT_CFG_MASK (0xFFFFU)
#define SRC_MIX_SLICE_PSW_CNT_CFG_HF_PON_CNT_CFG_SHIFT (0U)
/*! PON_CNT_CFG - PUP HF Count config: usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_CNT_CFG_HF_PON_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_CFG_HF_PON_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_CFG_HF_PON_CNT_CFG_MASK)

#define SRC_MIX_SLICE_PSW_CNT_CFG_HF_POFF_CNT_CFG_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_PSW_CNT_CFG_HF_POFF_CNT_CFG_SHIFT (16U)
/*! POFF_CNT_CFG - PDN HF Count config: usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_CNT_CFG_HF_POFF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_CFG_HF_POFF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_CFG_HF_POFF_CNT_CFG_MASK)
/*! @} */

/*! @name PSW_CNT_STAT_HF - PSW Counter Status for HF */
/*! @{ */

#define SRC_MIX_SLICE_PSW_CNT_STAT_HF_PON_CNT_MASK (0xFFFFU)
#define SRC_MIX_SLICE_PSW_CNT_STAT_HF_PON_CNT_SHIFT (0U)
/*! PON_CNT - HF PSW acknowledge count for power up, record the delay from power switch change to acknowledge received */
#define SRC_MIX_SLICE_PSW_CNT_STAT_HF_PON_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_STAT_HF_PON_CNT_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_STAT_HF_PON_CNT_MASK)

#define SRC_MIX_SLICE_PSW_CNT_STAT_HF_POFF_CNT_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_PSW_CNT_STAT_HF_POFF_CNT_SHIFT (16U)
/*! POFF_CNT - HF PSW acknowledge count for power down, record the delay from power switch change to acknowledge received */
#define SRC_MIX_SLICE_PSW_CNT_STAT_HF_POFF_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_STAT_HF_POFF_CNT_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_STAT_HF_POFF_CNT_MASK)
/*! @} */

/*! @name PSW_CNT_CFG_LF - PSW Counter Config for LF */
/*! @{ */

#define SRC_MIX_SLICE_PSW_CNT_CFG_LF_PON_CNT_CFG_MASK (0xFFFFU)
#define SRC_MIX_SLICE_PSW_CNT_CFG_LF_PON_CNT_CFG_SHIFT (0U)
/*! PON_CNT_CFG - PUP LF Count config: usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_CNT_CFG_LF_PON_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_CFG_LF_PON_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_CFG_LF_PON_CNT_CFG_MASK)

#define SRC_MIX_SLICE_PSW_CNT_CFG_LF_POFF_CNT_CFG_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_PSW_CNT_CFG_LF_POFF_CNT_CFG_SHIFT (16U)
/*! POFF_CNT_CFG - PDN LF Count config: usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_MIX_SLICE_PSW_CNT_CFG_LF_POFF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_CFG_LF_POFF_CNT_CFG_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_CFG_LF_POFF_CNT_CFG_MASK)
/*! @} */

/*! @name PSW_CNT_STAT_LF - PSW Counter Status for LF */
/*! @{ */

#define SRC_MIX_SLICE_PSW_CNT_STAT_LF_PON_CNT_MASK (0xFFFFU)
#define SRC_MIX_SLICE_PSW_CNT_STAT_LF_PON_CNT_SHIFT (0U)
/*! PON_CNT - LF PSW acknowledge count for power up, record the delay from power switch change to acknowledge received */
#define SRC_MIX_SLICE_PSW_CNT_STAT_LF_PON_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_STAT_LF_PON_CNT_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_STAT_LF_PON_CNT_MASK)

#define SRC_MIX_SLICE_PSW_CNT_STAT_LF_POFF_CNT_MASK (0xFFFF0000U)
#define SRC_MIX_SLICE_PSW_CNT_STAT_LF_POFF_CNT_SHIFT (16U)
/*! POFF_CNT - LF PSW acknowledge count for power down, record the delay from power switch change to acknowledge received */
#define SRC_MIX_SLICE_PSW_CNT_STAT_LF_POFF_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_PSW_CNT_STAT_LF_POFF_CNT_SHIFT)) & SRC_MIX_SLICE_PSW_CNT_STAT_LF_POFF_CNT_MASK)
/*! @} */

/*! @name MLPL_TRIG_CTRL - Memory Low Power Level Trigger Control */
/*! @{ */

#define SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_LMEM_MLPL_TRANS_MASK (0x10000U)
#define SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_LMEM_MLPL_TRANS_SHIFT (16U)
/*! SW_TRIG_LMEM_MLPL_TRANS - Software trigger local memory (MEM Type I with PSW or MEM Type I
 *    except for CM33PLATFORM_CACHE or CM7PLATFORM_CACHE, depending on which MIX of the register) update
 *    low power level
 *  0b0..No trigger
 *  0b1..Software trigger local memory update low power level
 */
#define SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_LMEM_MLPL_TRANS(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_LMEM_MLPL_TRANS_SHIFT)) & SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_LMEM_MLPL_TRANS_MASK)

#define SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_CACHE_MLPL_TRANS_MASK (0x20000U)
#define SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_CACHE_MLPL_TRANS_SHIFT (17U)
/*! SW_TRIG_CACHE_MLPL_TRANS - Software trigger CACHE memory (MEM Type II or MEM Type I's
 *    CM33PLATFORM_CACHE or CM7PLATFORM_CACHE, depending on which MIX of the register) update low power level
 *  0b0..No trigger
 *  0b1..Software trigger CACHE memory update low power level
 */
#define SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_CACHE_MLPL_TRANS(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_CACHE_MLPL_TRANS_SHIFT)) & SRC_MIX_SLICE_MLPL_TRIG_CTRL_SW_TRIG_CACHE_MLPL_TRANS_MASK)
/*! @} */

/*! @name MLPL_CFG - Memory Low Power Level Config */
/*! @{ */

#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_LMEM_MASK (0x7U)
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_LMEM_SHIFT (0U)
/*! MLPL_HW_PDN_LMEM - Memory(MEM Type I with PSW or MEM Type I except for CM33PLATFORM_CACHE or
 *    CM7PLATFORM_CACHE, depending on which MIX of the register) low power level when hw power down
 */
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_LMEM(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_LMEM_SHIFT)) & SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_LMEM_MASK)

#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_LMEM_MASK (0x70U)
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_LMEM_SHIFT (4U)
/*! MLPL_HW_PUP_LMEM - Memory(MEM Type I with PSW or MEM Type I except for CM33PLATFORM_CACHE or
 *    CM7PLATFORM_CACHE, depending on which MIX of the register) low power level when hw power up
 */
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_LMEM(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_LMEM_SHIFT)) & SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_LMEM_MASK)

#define SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_LMEM_MASK (0x7000U)
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_LMEM_SHIFT (12U)
/*! MLPL_SW_LMEM - Memory(MEM Type I with PSW or MEM Type I except for CM33PLATFORM_CACHE or
 *    CM7PLATFORM_CACHE, depending on which MIX of the register) low power level when sw trigger memory
 *    update power level
 */
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_LMEM(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_LMEM_SHIFT)) & SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_LMEM_MASK)

#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_CACHE_MASK (0x70000U)
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_CACHE_SHIFT (16U)
/*! MLPL_HW_PDN_CACHE - Memory(MEM Type II or MEM Type I's CM33PLATFORM_CACHE or CM7PLATFORM_CACHE,
 *    depending on which MIX of the register) low power level when hw power down
 */
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_CACHE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_CACHE_SHIFT)) & SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PDN_CACHE_MASK)

#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_CACHE_MASK (0x700000U)
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_CACHE_SHIFT (20U)
/*! MLPL_HW_PUP_CACHE - Memory(MEM Type II or MEM Type I's CM33PLATFORM_CACHE or CM7PLATFORM_CACHE,
 *    depending on which MIX of the register) low power level when hw power up
 */
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_CACHE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_CACHE_SHIFT)) & SRC_MIX_SLICE_MLPL_CFG_MLPL_HW_PUP_CACHE_MASK)

#define SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_CACHE_MASK (0x70000000U)
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_CACHE_SHIFT (28U)
/*! MLPL_SW_CACHE - Memory(MEM Type II or MEM Type I's CM33PLATFORM_CACHE or CM7PLATFORM_CACHE,
 *    depending on which MIX of the register) low power level when sw trigger memory update power level
 */
#define SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_CACHE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_CACHE_SHIFT)) & SRC_MIX_SLICE_MLPL_CFG_MLPL_SW_CACHE_MASK)
/*! @} */

/*! @name MLPL_STAT - Memory Low Power Level Status */
/*! @{ */

#define SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_LMEM_MASK (0x7U)
#define SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_LMEM_SHIFT (0U)
/*! CURRENT_MLPL_LMEM - Current memory (MEM Type I with PSW or MEM Type I except for
 *    CM33PLATFORM_CACHE or CM7PLATFORM_CACHE, depending on which MIX of the register) low power level
 */
#define SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_LMEM(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_LMEM_SHIFT)) & SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_LMEM_MASK)

#define SRC_MIX_SLICE_MLPL_STAT_LMEM_BUSY_MASK   (0x8U)
#define SRC_MIX_SLICE_MLPL_STAT_LMEM_BUSY_SHIFT  (3U)
/*! LMEM_BUSY - Busy requesting low power level of memory (MEM Type I with PSW or MEM Type I except
 *    for CM33PLATFORM_CACHE or CM7PLATFORM_CACHE, depending on which MIX of the register)
 */
#define SRC_MIX_SLICE_MLPL_STAT_LMEM_BUSY(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_STAT_LMEM_BUSY_SHIFT)) & SRC_MIX_SLICE_MLPL_STAT_LMEM_BUSY_MASK)

#define SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_CACHE_MASK (0x70U)
#define SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_CACHE_SHIFT (4U)
/*! CURRENT_MLPL_CACHE - Current memory (MEM Type II or MEM Type I's CM33PLATFORM_CACHE or
 *    CM7PLATFORM_CACHE, depending on which MIX of the register) low power level
 */
#define SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_CACHE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_CACHE_SHIFT)) & SRC_MIX_SLICE_MLPL_STAT_CURRENT_MLPL_CACHE_MASK)

#define SRC_MIX_SLICE_MLPL_STAT_CACHE_BUSY_MASK  (0x80U)
#define SRC_MIX_SLICE_MLPL_STAT_CACHE_BUSY_SHIFT (7U)
/*! CACHE_BUSY - Busy requesting low power level of memory (MEM Type II or MEM Type I's
 *    CM33PLATFORM_CACHE or CM7PLATFORM_CACHE, depending on which MIX of the register)
 */
#define SRC_MIX_SLICE_MLPL_STAT_CACHE_BUSY(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MIX_SLICE_MLPL_STAT_CACHE_BUSY_SHIFT)) & SRC_MIX_SLICE_MLPL_STAT_CACHE_BUSY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_MIX_SLICE_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_MIX_SLICE_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_MIX_SLICE_H_ */

