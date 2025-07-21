/*
** ###################################################################
**     Processors:          MIMXRT1015CAF4A
**                          MIMXRT1015CAF4B
**                          MIMXRT1015DAF5A
**                          MIMXRT1015DAF5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC_SNVS_GPR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-11-05)
**         Initial version.
**     - rev. 1.0 (2019-01-18)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-02-20)
**         Update register SRC_SRSR's bitfield LOCKUP_SYSRESETREQ to LOCKUP.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1015RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC_SNVS_GPR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC_SNVS_GPR
 *
 * CMSIS Peripheral Access Layer for IOMUXC_SNVS_GPR
 */

#if !defined(PERI_IOMUXC_SNVS_GPR_H_)
#define PERI_IOMUXC_SNVS_GPR_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1015CAF4A) || defined(CPU_MIMXRT1015CAF4B) || defined(CPU_MIMXRT1015DAF5A) || defined(CPU_MIMXRT1015DAF5B))
#include "MIMXRT1015_COMMON.h"
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
   -- IOMUXC_SNVS_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_GPR_Peripheral_Access_Layer IOMUXC_SNVS_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_SNVS_GPR - Register Layout Typedef */
typedef struct {
       uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
       uint32_t GPR1;                              /**< GPR1 General Purpose Register, offset: 0x4 */
       uint32_t GPR2;                              /**< GPR2 General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
} IOMUXC_SNVS_GPR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_SNVS_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_SNVS_GPR_Register_Masks IOMUXC_SNVS_GPR Register Masks
 * @{
 */

/*! @name GPR3 - GPR3 General Purpose Register */
/*! @{ */

#define IOMUXC_SNVS_GPR_GPR3_LPSR_MODE_ENABLE_MASK (0x1U)
#define IOMUXC_SNVS_GPR_GPR3_LPSR_MODE_ENABLE_SHIFT (0U)
/*! LPSR_MODE_ENABLE
 *  0b0..SNVS domain will reset when system reset happens
 *  0b1..SNVS domain will only reset with SNVS POR
 */
#define IOMUXC_SNVS_GPR_GPR3_LPSR_MODE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_LPSR_MODE_ENABLE_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_LPSR_MODE_ENABLE_MASK)

#define IOMUXC_SNVS_GPR_GPR3_DCDC_STATUS_CAPT_CLR_MASK (0x2U)
#define IOMUXC_SNVS_GPR_GPR3_DCDC_STATUS_CAPT_CLR_SHIFT (1U)
/*! DCDC_STATUS_CAPT_CLR - DCDC captured status clear */
#define IOMUXC_SNVS_GPR_GPR3_DCDC_STATUS_CAPT_CLR(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_DCDC_STATUS_CAPT_CLR_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_DCDC_STATUS_CAPT_CLR_MASK)

#define IOMUXC_SNVS_GPR_GPR3_POR_PULL_TYPE_MASK  (0xCU)
#define IOMUXC_SNVS_GPR_GPR3_POR_PULL_TYPE_SHIFT (2U)
/*! POR_PULL_TYPE
 *  0b00..100 Ohm pull up enabled for POR_B always
 *  0b01..Disable pull in SNVS mode, 100 Ohm pull up enabled otherwise
 *  0b10..Disable pull of POR_B always
 *  0b11..100 Ohm pull down enabled in SNVS mode, 100 Ohm pull up enabled otherwise
 */
#define IOMUXC_SNVS_GPR_GPR3_POR_PULL_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_POR_PULL_TYPE_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_POR_PULL_TYPE_MASK)

#define IOMUXC_SNVS_GPR_GPR3_DCDC_IN_LOW_VOL_MASK (0x10000U)
#define IOMUXC_SNVS_GPR_GPR3_DCDC_IN_LOW_VOL_SHIFT (16U)
/*! DCDC_IN_LOW_VOL
 *  0b0..DCDC_IN is ok
 *  0b1..DCDC_IN is too low
 */
#define IOMUXC_SNVS_GPR_GPR3_DCDC_IN_LOW_VOL(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_DCDC_IN_LOW_VOL_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_DCDC_IN_LOW_VOL_MASK)

#define IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_CUR_MASK  (0x20000U)
#define IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_CUR_SHIFT (17U)
/*! DCDC_OVER_CUR
 *  0b0..No over current detected
 *  0b1..Over current detected
 */
#define IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_CUR(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_CUR_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_CUR_MASK)

#define IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_VOL_MASK  (0x40000U)
#define IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_VOL_SHIFT (18U)
/*! DCDC_OVER_VOL
 *  0b0..No over voltage detected
 *  0b1..Over voltage detected
 */
#define IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_VOL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_VOL_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_DCDC_OVER_VOL_MASK)

#define IOMUXC_SNVS_GPR_GPR3_DCDC_STS_DC_OK_MASK (0x80000U)
#define IOMUXC_SNVS_GPR_GPR3_DCDC_STS_DC_OK_SHIFT (19U)
/*! DCDC_STS_DC_OK
 *  0b0..DCDC is ramping up and not ready
 *  0b1..DCDC is ready
 */
#define IOMUXC_SNVS_GPR_GPR3_DCDC_STS_DC_OK(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_SNVS_GPR_GPR3_DCDC_STS_DC_OK_SHIFT)) & IOMUXC_SNVS_GPR_GPR3_DCDC_STS_DC_OK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_SNVS_GPR_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_SNVS_GPR_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC_SNVS_GPR_H_ */

