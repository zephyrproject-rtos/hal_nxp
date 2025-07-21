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
**         CMSIS Peripheral Access Layer for SRC_MIF_LN28FDSOI_SPLLRAM
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
 * @file PERI_SRC_MIF_LN28FDSOI_SPLLRAM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC_MIF_LN28FDSOI_SPLLRAM
 *
 * CMSIS Peripheral Access Layer for SRC_MIF_LN28FDSOI_SPLLRAM
 */

#if !defined(PERI_SRC_MIF_LN28FDSOI_SPLLRAM_H_)
#define PERI_SRC_MIF_LN28FDSOI_SPLLRAM_H_        /**< Symbol preventing repeated inclusion */

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
   -- SRC_MIF_LN28FDSOI_SPLLRAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MIF_LN28FDSOI_SPLLRAM_Peripheral_Access_Layer SRC_MIF_LN28FDSOI_SPLLRAM Peripheral Access Layer
 * @{
 */

/** SRC_MIF_LN28FDSOI_SPLLRAM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t MIF_CTRL;                          /**< MPC Control, offset: 0x4 */
  __I  uint32_t MIF_STAT;                          /**< MIF Status, offset: 0x8 */
       uint8_t RESERVED_1[20];
  __IO uint32_t MIF_MLPL_IG;                       /**< MIF MLPL control of IG, offset: 0x20 */
  __IO uint32_t MIF_DLY_IG;                        /**< MIF Delay of IG, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t MIF_MLPL_WLPD;                     /**< MIF MLPL control of WLPD, offset: 0x30 */
  __IO uint32_t MIF_DLY_WLPD;                      /**< MIF Delay of WLPD, offset: 0x34 */
       uint8_t RESERVED_3[8];
  __IO uint32_t MIF_MLPL_PD_B;                     /**< MIF MLPL control of PD_B, offset: 0x40 */
  __IO uint32_t MIF_DLY_PD_B;                      /**< MIF Delay of PD_B, offset: 0x44 */
} SRC_MIF_LN28FDSOI_SPLLRAM_Type;

/* ----------------------------------------------------------------------------
   -- SRC_MIF_LN28FDSOI_SPLLRAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MIF_LN28FDSOI_SPLLRAM_Register_Masks SRC_MIF_LN28FDSOI_SPLLRAM Register Masks
 * @{
 */

/*! @name MIF_CTRL - MPC Control */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_SW_CTRL_PIN_MASK (0x1U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_SW_CTRL_PIN_SHIFT (0U)
/*! SW_CTRL_PIN - Memory low power pins controlled by SW
 *  0b0..Use CURRENT_MLPL field to select MLPL_CTRL to control low power signal.
 *  0b1..Use SW_* field to control low power signal directly.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_SW_CTRL_PIN(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_SW_CTRL_PIN_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_SW_CTRL_PIN_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_MEM_PWR_ST_EN_MASK (0x2U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_MEM_PWR_ST_EN_SHIFT (1U)
/*! MEM_PWR_ST_EN - Memory power status will be considered when determining slice power status.
 *  0b0..Memory power status will not be considered when determining slice power status.
 *  0b1..Memory power status will be considered when determining slice power status.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_MEM_PWR_ST_EN(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_MEM_PWR_ST_EN_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_MEM_PWR_ST_EN_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_LOCK_CFG_MASK (0x100000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_LOCK_CFG_SHIFT (20U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The fields are not locked.
 *  0b1..The fields are locked.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_LOCK_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_LOCK_CFG_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_CTRL_LOCK_CFG_MASK)
/*! @} */

/*! @name MIF_STAT - MIF Status */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_MLPL_STATE_MASK (0x7U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_MLPL_STATE_SHIFT (0U)
/*! MLPL_STATE - Current state of CURRENT_MLPL */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_MLPL_STATE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_MLPL_STATE_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_MLPL_STATE_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_IG_STATE_MASK (0x8U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_IG_STATE_SHIFT (3U)
/*! IG_STATE - Current state of IG
 *  0b0..IG is 0.
 *  0b1..IG is 1.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_IG_STATE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_IG_STATE_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_IG_STATE_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_WLPD_STATE_MASK (0x10U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_WLPD_STATE_SHIFT (4U)
/*! WLPD_STATE - Current state of WLPD
 *  0b0..WLPD is 0.
 *  0b1..WLPD is 1.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_WLPD_STATE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_WLPD_STATE_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_WLPD_STATE_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_PD_B_STATE_MASK (0x20U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_PD_B_STATE_SHIFT (5U)
/*! PD_B_STATE - Current state of PD_B
 *  0b0..PD_B is 0.
 *  0b1..PD_B is 1.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_PD_B_STATE(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_PD_B_STATE_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_STAT_PD_B_STATE_MASK)
/*! @} */

/*! @name MIF_MLPL_IG - MIF MLPL control of IG */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_MLPL_CTRL_MASK (0xFFU)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_MLPL_CTRL_SHIFT (0U)
/*! MLPL_CTRL - Signal behavior at 8 different MLPL settings */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_MLPL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_MLPL_CTRL_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_MLPL_CTRL_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_SW_IG_MASK (0x10000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_SW_IG_SHIFT (16U)
/*! SW_IG - Software control IG
 *  0b0..IG is 0.
 *  0b1..IG is 1.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_SW_IG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_SW_IG_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_IG_SW_IG_MASK)
/*! @} */

/*! @name MIF_DLY_IG - MIF Delay of IG */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_HI_DLY_MASK (0xFFFFU)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_HI_DLY_SHIFT (0U)
/*! PRE_HI_DLY - Delay before asserting signal to high, locked by LOCK_CFG field */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_HI_DLY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_HI_DLY_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_HI_DLY_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_LO_DLY_MASK (0xFFFF0000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_LO_DLY_SHIFT (16U)
/*! PRE_LO_DLY - Delay before de-asserting signal to low, locked by LOCK_CFG field */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_LO_DLY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_LO_DLY_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_IG_PRE_LO_DLY_MASK)
/*! @} */

/*! @name MIF_MLPL_WLPD - MIF MLPL control of WLPD */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_MLPL_CTRL_MASK (0xFFU)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_MLPL_CTRL_SHIFT (0U)
/*! MLPL_CTRL - Signal behavior at 8 different MLPL settings */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_MLPL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_MLPL_CTRL_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_MLPL_CTRL_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_SW_WLPD_MASK (0x10000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_SW_WLPD_SHIFT (16U)
/*! SW_WLPD - Software control WLPD
 *  0b0..WLPD is 0.
 *  0b1..WLPD is 1.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_SW_WLPD(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_SW_WLPD_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_WLPD_SW_WLPD_MASK)
/*! @} */

/*! @name MIF_DLY_WLPD - MIF Delay of WLPD */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_HI_DLY_MASK (0xFFFFU)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_HI_DLY_SHIFT (0U)
/*! PRE_HI_DLY - Delay before asserting signal to high, locked by LOCK_CFG field */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_HI_DLY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_HI_DLY_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_HI_DLY_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_LO_DLY_MASK (0xFFFF0000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_LO_DLY_SHIFT (16U)
/*! PRE_LO_DLY - Delay before de-asserting signal to low, locked by LOCK_CFG field */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_LO_DLY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_LO_DLY_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_WLPD_PRE_LO_DLY_MASK)
/*! @} */

/*! @name MIF_MLPL_PD_B - MIF MLPL control of PD_B */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_MLPL_CTRL_MASK (0xFFU)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_MLPL_CTRL_SHIFT (0U)
/*! MLPL_CTRL - Signal behavior at 8 different MLPL settings */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_MLPL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_MLPL_CTRL_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_MLPL_CTRL_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_SW_PD_B_MASK (0x10000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_SW_PD_B_SHIFT (16U)
/*! SW_PD_B - software control PD_B
 *  0b0..PD_B is 0.
 *  0b1..PD_B is 1.
 */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_SW_PD_B(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_SW_PD_B_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_MLPL_PD_B_SW_PD_B_MASK)
/*! @} */

/*! @name MIF_DLY_PD_B - MIF Delay of PD_B */
/*! @{ */

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_HI_DLY_MASK (0xFFFFU)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_HI_DLY_SHIFT (0U)
/*! PRE_HI_DLY - Delay before asserting signal to high, locked by LOCK_CFG field */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_HI_DLY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_HI_DLY_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_HI_DLY_MASK)

#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_LO_DLY_MASK (0xFFFF0000U)
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_LO_DLY_SHIFT (16U)
/*! PRE_LO_DLY - Delay before de-asserting signal to low, locked by LOCK_CFG field */
#define SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_LO_DLY(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_LO_DLY_SHIFT)) & SRC_MIF_LN28FDSOI_SPLLRAM_MIF_DLY_PD_B_PRE_LO_DLY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_MIF_LN28FDSOI_SPLLRAM_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_MIF_LN28FDSOI_SPLLRAM_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_MIF_LN28FDSOI_SPLLRAM_H_ */

