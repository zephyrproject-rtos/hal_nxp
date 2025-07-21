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
**         CMSIS Peripheral Access Layer for ANADIG_LDO_BBSM
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
 * @file PERI_ANADIG_LDO_BBSM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANADIG_LDO_BBSM
 *
 * CMSIS Peripheral Access Layer for ANADIG_LDO_BBSM
 */

#if !defined(PERI_ANADIG_LDO_BBSM_H_)
#define PERI_ANADIG_LDO_BBSM_H_                  /**< Symbol preventing repeated inclusion */

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
   -- ANADIG_LDO_BBSM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_LDO_BBSM_Peripheral_Access_Layer ANADIG_LDO_BBSM Peripheral Access Layer
 * @{
 */

/** ANADIG_LDO_BBSM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[18240];
  __IO uint32_t PMU_LDO_AON_ANA;                   /**< PMU_LDO_AON_ANA_REGISTER, offset: 0x4740 */
       uint8_t RESERVED_1[28];
  __IO uint32_t PMU_LDO_AON_DIG;                   /**< PMU_LDO_AON_DIG_REGISTER, offset: 0x4760 */
} ANADIG_LDO_BBSM_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_LDO_BBSM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_LDO_BBSM_Register_Masks ANADIG_LDO_BBSM Register Masks
 * @{
 */

/*! @name PMU_LDO_AON_ANA - PMU_LDO_AON_ANA_REGISTER */
/*! @{ */

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_LP_EN_MASK (0x1U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_LP_EN_SHIFT (0U)
/*! REG_LP_EN - reg_lp_en
 *  0b0..Enable
 *  0b1..Disable
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_LP_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_LP_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_DISABLE_MASK (0x4U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_DISABLE_SHIFT (2U)
/*! REG_DISABLE - reg_disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_DISABLE_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_REG_DISABLE_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_2MA_EN_MASK (0x8U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_2MA_EN_SHIFT (3U)
/*! PULL_DOWN_2MA_EN - pull_down_2ma_en
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_2MA_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_2MA_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_2MA_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_STANDBY_EN_MASK (0x40U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_STANDBY_EN_SHIFT (6U)
/*! STANDBY_EN - standby_en
 *  0b0..Standby mode disable
 *  0b1..Standby mode enable
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_STANDBY_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_STANDBY_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_STANDBY_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_ALWAYS_4MA_PULLDOWN_EN_MASK (0x100U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_ALWAYS_4MA_PULLDOWN_EN_SHIFT (8U)
/*! ALWAYS_4MA_PULLDOWN_EN - always_4ma_pulldown_en */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_ALWAYS_4MA_PULLDOWN_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_ALWAYS_4MA_PULLDOWN_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_ALWAYS_4MA_PULLDOWN_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_TRACK_MODE_EN_MASK (0x80000U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_TRACK_MODE_EN_SHIFT (19U)
/*! TRACK_MODE_EN - Track Mode Enable
 *  0b0..Normal use
 *  0b1..Switch preparation
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_TRACK_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_TRACK_MODE_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_TRACK_MODE_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_20UA_EN_MASK (0x100000U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_20UA_EN_SHIFT (20U)
/*! PULL_DOWN_20UA_EN - pull_down_20ua_en
 *  0b0..Disable 20uA loading
 *  0b1..Enable 20uA loading
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_20UA_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_20UA_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_ANA_PULL_DOWN_20UA_EN_MASK)
/*! @} */

/*! @name PMU_LDO_AON_DIG - PMU_LDO_AON_DIG_REGISTER */
/*! @{ */

#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_REG_EN_MASK (0x4U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_REG_EN_SHIFT (2U)
/*! REG_EN - ENABLE_ILIMIT
 *  0b0..LDO_AON_DIG disable
 *  0b1..LDO_AON_DIG enable
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_REG_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_REG_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_REG_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_STANDBY_EN_MASK (0x40U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_STANDBY_EN_SHIFT (6U)
/*! STANDBY_EN - standby_en
 *  0b0..Standby disable
 *  0b1..Standby enable
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_STANDBY_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_STANDBY_EN_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_STANDBY_EN_MASK)

#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_VOLTAGE_SELECT_MASK (0x1F00000U)
#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_VOLTAGE_SELECT_SHIFT (20U)
/*! VOLTAGE_SELECT - VOLTAGE_SELECT
 *  0b00000..Stable Voltage (range)
 *  0b00001..Stable Voltage (range)
 *  0b00010..Stable Voltage (range)
 *  0b00011..Stable Voltage (range)
 *  0b00100..Stable Voltage (range)
 *  0b00101..Stable Voltage (range)
 *  0b00110..Stable Voltage (range)
 *  0b00111..Stable Voltage (range)
 *  0b01000..Stable Voltage (range)
 *  0b01001..Stable Voltage (range)
 *  0b01010..Stable Voltage (range)
 *  0b01011..Stable Voltage (range)
 *  0b01100..Stable Voltage (range)
 *  0b01101..Stable Voltage (range)
 *  0b01110..Stable Voltage (range)
 *  0b01111..Stable Voltage (range)
 *  0b10000..Stable Voltage (range)
 *  0b10001..Stable Voltage (range)
 *  0b10010..Stable Voltage (range)
 *  0b10011..Stable Voltage (range)
 *  0b10100..Stable Voltage (range)
 *  0b10101..Stable Voltage (range)
 *  0b10110..Stable Voltage (range)
 *  0b10111..Stable Voltage (range)
 *  0b11000..Stable Voltage (range)
 *  0b11001..Stable Voltage (range)
 *  0b11010..Stable Voltage (range)
 *  0b11011..Stable Voltage (range)
 *  0b11100..Stable Voltage (range)
 *  0b11101..Stable Voltage (range)
 *  0b11110..Stable Voltage (range)
 *  0b11111..Stable Voltage (range)
 */
#define ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_VOLTAGE_SELECT(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_VOLTAGE_SELECT_SHIFT)) & ANADIG_LDO_BBSM_PMU_LDO_AON_DIG_VOLTAGE_SELECT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_LDO_BBSM_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_LDO_BBSM_Peripheral_Access_Layer */


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


#endif  /* PERI_ANADIG_LDO_BBSM_H_ */

