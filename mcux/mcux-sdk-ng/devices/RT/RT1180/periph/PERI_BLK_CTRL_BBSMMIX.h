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
**         CMSIS Peripheral Access Layer for BLK_CTRL_BBSMMIX
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
 * @file PERI_BLK_CTRL_BBSMMIX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_BBSMMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_BBSMMIX
 */

#if !defined(PERI_BLK_CTRL_BBSMMIX_H_)
#define PERI_BLK_CTRL_BBSMMIX_H_                 /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_BBSMMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_BBSMMIX_Peripheral_Access_Layer BLK_CTRL_BBSMMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_BBSMMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t BBSM_MISC;                         /**< BBSM miscellaneous register, offset: 0x0 */
  __IO uint32_t BBSM_TRIM;                         /**< BBSM TRIM register, offset: 0x4 */
} BLK_CTRL_BBSMMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_BBSMMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_BBSMMIX_Register_Masks BLK_CTRL_BBSMMIX Register Masks
 * @{
 */

/*! @name BBSM_MISC - BBSM miscellaneous register */
/*! @{ */

#define BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_BYPASS_EN_MASK (0x4U)
#define BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_BYPASS_EN_SHIFT (2U)
/*! BBSM_BYPASS_EN - LDO_BBSM_ANA bypass enable
 *  0b0..Disable bypass
 *  0b1..Enable bypass
 */
#define BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_BYPASS_EN_SHIFT)) & BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_BYPASS_EN_MASK)

#define BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_XTAL_CLK_OK_MASK (0x100000U)
#define BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_XTAL_CLK_OK_SHIFT (20U)
/*! BBSM_XTAL_CLK_OK - 32K OSC ok flag
 *  0b0..32K oscillator is NOT stable into normal operation
 *  0b1..32K oscillator is stable into normal operation
 */
#define BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_XTAL_CLK_OK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_XTAL_CLK_OK_SHIFT)) & BLK_CTRL_BBSMMIX_BBSM_MISC_BBSM_XTAL_CLK_OK_MASK)
/*! @} */

/*! @name BBSM_TRIM - BBSM TRIM register */
/*! @{ */

#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SEL_MASK (0x2U)
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SEL_SHIFT (1U)
/*! BBSM_CORE_VOLT_DET_TRIM_SEL - BBSM core voltage detect trim select
 *  0b0..The trimming codes are selected from eFuse
 *  0b1..The trimming codes of core voltage detectors used to change the voltage falling trip point are selected from BBSM_CORE_VOLT_DET_TRIM
 */
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SEL_SHIFT)) & BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SEL_MASK)

#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_MASK (0xCU)
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SHIFT (2U)
/*! BBSM_CORE_VOLT_DET_TRIM - BBSM core voltage detect trim */
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_SHIFT)) & BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CORE_VOLT_DET_TRIM_MASK)

#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CAP_TRIM_SEL_MASK (0x800000U)
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CAP_TRIM_SEL_SHIFT (23U)
/*! BBSM_CAP_TRIM_SEL - BBSM OSC load capacitor trim select
 *  0b0..The trimming codes are selected from eFuse
 *  0b1..The trimming codes are used from BBSM_OSC_CAP_TRIM (osc32k's load capacitor)
 */
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CAP_TRIM_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CAP_TRIM_SEL_SHIFT)) & BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_CAP_TRIM_SEL_MASK)

#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_OSC_CAP_TRIM_MASK (0xF000000U)
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_OSC_CAP_TRIM_SHIFT (24U)
/*! BBSM_OSC_CAP_TRIM - BBSM OSC load capacitor trim */
#define BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_OSC_CAP_TRIM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_OSC_CAP_TRIM_SHIFT)) & BLK_CTRL_BBSMMIX_BBSM_TRIM_BBSM_OSC_CAP_TRIM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_BBSMMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_BBSMMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_BBSMMIX_H_ */

