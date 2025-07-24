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
**         CMSIS Peripheral Access Layer for ANADIG_LDO_SNVS
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
 * @file PERI_ANADIG_LDO_SNVS.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANADIG_LDO_SNVS
 *
 * CMSIS Peripheral Access Layer for ANADIG_LDO_SNVS
 */

#if !defined(PERI_ANADIG_LDO_SNVS_H_)
#define PERI_ANADIG_LDO_SNVS_H_                  /**< Symbol preventing repeated inclusion */

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
   -- ANADIG_LDO_SNVS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_LDO_SNVS_Peripheral_Access_Layer ANADIG_LDO_SNVS Peripheral Access Layer
 * @{
 */

/** ANADIG_LDO_SNVS - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1296];
  __IO uint32_t PMU_LDO_LPSR_ANA;                  /**< PMU_LDO_LPSR_ANA_REGISTER, offset: 0x510 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PMU_LDO_LPSR_DIG_2;                /**< PMU_LDO_LPSR_DIG_2_REGISTER, offset: 0x520 */
       uint8_t RESERVED_2[12];
  __IO uint32_t PMU_LDO_LPSR_DIG;                  /**< PMU_LDO_LPSR_DIG_REGISTER, offset: 0x530 */
} ANADIG_LDO_SNVS_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_LDO_SNVS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_LDO_SNVS_Register_Masks ANADIG_LDO_SNVS Register Masks
 * @{
 */

/*! @name PMU_LDO_LPSR_ANA - PMU_LDO_LPSR_ANA_REGISTER */
/*! @{ */

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_LP_EN_MASK (0x1U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_LP_EN_SHIFT (0U)
/*! REG_LP_EN - reg_lp_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_LP_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_LP_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_DISABLE_MASK (0x4U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_DISABLE_SHIFT (2U)
/*! REG_DISABLE - reg_disable */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_DISABLE_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_REG_DISABLE_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_2MA_EN_MASK (0x8U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_2MA_EN_SHIFT (3U)
/*! PULL_DOWN_2MA_EN - pull_down_2ma_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_2MA_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_2MA_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_2MA_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_LPSR_ANA_CONTROL_MODE_MASK (0x10U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_LPSR_ANA_CONTROL_MODE_SHIFT (4U)
/*! LPSR_ANA_CONTROL_MODE - LPSR_ANA_CONTROL_MODE
 *  0b0..SW Control
 *  0b1..HW Control
 */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_LPSR_ANA_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_LPSR_ANA_CONTROL_MODE_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_LPSR_ANA_CONTROL_MODE_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_BYPASS_MODE_EN_MASK (0x20U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_BYPASS_MODE_EN_SHIFT (5U)
/*! BYPASS_MODE_EN - bypass_mode_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_BYPASS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_BYPASS_MODE_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_BYPASS_MODE_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_STANDBY_EN_MASK (0x40U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_STANDBY_EN_SHIFT (6U)
/*! STANDBY_EN - standby_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_STANDBY_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_STANDBY_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_STANDBY_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_ALWAYS_4MA_PULLDOWN_EN_MASK (0x100U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_ALWAYS_4MA_PULLDOWN_EN_SHIFT (8U)
/*! ALWAYS_4MA_PULLDOWN_EN - always_4ma_pulldown_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_ALWAYS_4MA_PULLDOWN_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_ALWAYS_4MA_PULLDOWN_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_ALWAYS_4MA_PULLDOWN_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_TRACK_MODE_EN_MASK (0x80000U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_TRACK_MODE_EN_SHIFT (19U)
/*! TRACK_MODE_EN - Track Mode Enable
 *  0b0..Normal use
 *  0b1..Switch preparation
 */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_TRACK_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_TRACK_MODE_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_TRACK_MODE_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_20UA_EN_MASK (0x100000U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_20UA_EN_SHIFT (20U)
/*! PULL_DOWN_20UA_EN - pull_down_20ua_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_20UA_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_20UA_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_ANA_PULL_DOWN_20UA_EN_MASK)
/*! @} */

/*! @name PMU_LDO_LPSR_DIG_2 - PMU_LDO_LPSR_DIG_2_REGISTER */
/*! @{ */

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_2_VOLTAGE_STEP_INC_MASK (0x3U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_2_VOLTAGE_STEP_INC_SHIFT (0U)
/*! VOLTAGE_STEP_INC - voltage_step_inc */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_2_VOLTAGE_STEP_INC(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_2_VOLTAGE_STEP_INC_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_2_VOLTAGE_STEP_INC_MASK)
/*! @} */

/*! @name PMU_LDO_LPSR_DIG - PMU_LDO_LPSR_DIG_REGISTER */
/*! @{ */

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_REG_EN_MASK (0x4U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_REG_EN_SHIFT (2U)
/*! REG_EN - ENABLE_ILIMIT */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_REG_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_REG_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_REG_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_LPSR_DIG_CONTROL_MODE_MASK (0x20U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_LPSR_DIG_CONTROL_MODE_SHIFT (5U)
/*! LPSR_DIG_CONTROL_MODE - LPSR_DIG_CONTROL_MODE
 *  0b0..SW Control
 *  0b1..HW Control
 */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_LPSR_DIG_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_LPSR_DIG_CONTROL_MODE_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_LPSR_DIG_CONTROL_MODE_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_STANDBY_EN_MASK (0x40U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_STANDBY_EN_SHIFT (6U)
/*! STANDBY_EN - standby_en */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_STANDBY_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_STANDBY_EN_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_STANDBY_EN_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_TRACKING_MODE_MASK (0x20000U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_TRACKING_MODE_SHIFT (17U)
/*! TRACKING_MODE - tracking_mode */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_TRACKING_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_TRACKING_MODE_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_TRACKING_MODE_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_BYPASS_MODE_MASK (0x40000U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_BYPASS_MODE_SHIFT (18U)
/*! BYPASS_MODE - bypass_mode */
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_BYPASS_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_BYPASS_MODE_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_BYPASS_MODE_MASK)

#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_VOLTAGE_SELECT_MASK (0x1F00000U)
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_VOLTAGE_SELECT_SHIFT (20U)
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
#define ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_VOLTAGE_SELECT(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_VOLTAGE_SELECT_SHIFT)) & ANADIG_LDO_SNVS_PMU_LDO_LPSR_DIG_VOLTAGE_SELECT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_LDO_SNVS_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_LDO_SNVS_Peripheral_Access_Layer */


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


#endif  /* PERI_ANADIG_LDO_SNVS_H_ */

