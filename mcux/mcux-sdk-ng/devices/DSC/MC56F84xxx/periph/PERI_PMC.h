/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< Control Register, offset: 0x0 */
  __IO uint16_t STS;                               /**< Status Register, offset: 0x1 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define PMC_CTRL_LV22IE_MASK                     (0x1U)
#define PMC_CTRL_LV22IE_SHIFT                    (0U)
/*! LV22IE - 2.2 V Low Voltage Interrupt Enable
 *  0b0..Disable setting the low voltage interrupt.
 *  0b1..Enable setting the low voltage interrupt.
 */
#define PMC_CTRL_LV22IE(x)                       (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_LV22IE_SHIFT)) & PMC_CTRL_LV22IE_MASK)

#define PMC_CTRL_LV27IE_MASK                     (0x2U)
#define PMC_CTRL_LV27IE_SHIFT                    (1U)
/*! LV27IE - 2.7 V Low Voltage Interrupt Enable
 *  0b0..Disable setting the low voltage interrupt.
 *  0b1..Enable setting the low voltage interrupt.
 */
#define PMC_CTRL_LV27IE(x)                       (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_LV27IE_SHIFT)) & PMC_CTRL_LV27IE_MASK)

#define PMC_CTRL_HV22IE_MASK                     (0x4U)
#define PMC_CTRL_HV22IE_SHIFT                    (2U)
/*! HV22IE - 2.2 V High Voltage Interrupt Enable
 *  0b0..Disable setting the high voltage interrupt.
 *  0b1..Enable setting the high voltage interrupt.
 */
#define PMC_CTRL_HV22IE(x)                       (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_HV22IE_SHIFT)) & PMC_CTRL_HV22IE_MASK)

#define PMC_CTRL_HV27IE_MASK                     (0x8U)
#define PMC_CTRL_HV27IE_SHIFT                    (3U)
/*! HV27IE - 2.7 V High Voltage Interrupt Enable
 *  0b0..Disable setting the high voltage interrupt.
 *  0b1..Enable setting the high voltage interrupt.
 */
#define PMC_CTRL_HV27IE(x)                       (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_HV27IE_SHIFT)) & PMC_CTRL_HV27IE_MASK)

#define PMC_CTRL_VRBEN_MASK                      (0x80U)
#define PMC_CTRL_VRBEN_SHIFT                     (7U)
/*! VRBEN - Voltage Reference Buffer Enable
 *  0b0..Disable voltage reference buffering.
 *  0b1..Enable voltage reference buffering.
 */
#define PMC_CTRL_VRBEN(x)                        (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_VRBEN_SHIFT)) & PMC_CTRL_VRBEN_MASK)

#define PMC_CTRL_TRIM_MASK                       (0xF000U)
#define PMC_CTRL_TRIM_SHIFT                      (12U)
/*! TRIM - Bandgap Trim */
#define PMC_CTRL_TRIM(x)                         (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_TRIM_SHIFT)) & PMC_CTRL_TRIM_MASK)
/*! @} */

/*! @name STS - Status Register */
/*! @{ */

#define PMC_STS_LV22F_MASK                       (0x1U)
#define PMC_STS_LV22F_SHIFT                      (0U)
/*! LV22F - 2.2 V Low Voltage Flag
 *  0b0..3.3 V supply is not below the 2.2 V threshold.
 *  0b1..3.3 V supply is below the 2.2 V threshold.
 */
#define PMC_STS_LV22F(x)                         (((uint16_t)(((uint16_t)(x)) << PMC_STS_LV22F_SHIFT)) & PMC_STS_LV22F_MASK)

#define PMC_STS_LV27F_MASK                       (0x2U)
#define PMC_STS_LV27F_SHIFT                      (1U)
/*! LV27F - 2.7 V Low Voltage Flag
 *  0b0..3.3 V supply is not below the 2.7 V threshold.
 *  0b1..3.3 V supply is below the 2.7 V threshold.
 */
#define PMC_STS_LV27F(x)                         (((uint16_t)(((uint16_t)(x)) << PMC_STS_LV27F_SHIFT)) & PMC_STS_LV27F_MASK)

#define PMC_STS_SLV22F_MASK                      (0x4U)
#define PMC_STS_SLV22F_SHIFT                     (2U)
/*! SLV22F - Sticky 2.2 V Low Voltage Flag
 *  0b0..3.3 V supply has not dropped below the 2.2 V threshold.
 *  0b1..3.3 V supply has dropped below the 2.2 V threshold.
 */
#define PMC_STS_SLV22F(x)                        (((uint16_t)(((uint16_t)(x)) << PMC_STS_SLV22F_SHIFT)) & PMC_STS_SLV22F_MASK)

#define PMC_STS_SLV27F_MASK                      (0x8U)
#define PMC_STS_SLV27F_SHIFT                     (3U)
/*! SLV27F - Sticky 2.7 V Low Voltage Flag
 *  0b0..3.3 V supply has not dropped below the 2.7 V threshold.
 *  0b1..3.3 V supply has dropped below the 2.7 V threshold.
 */
#define PMC_STS_SLV27F(x)                        (((uint16_t)(((uint16_t)(x)) << PMC_STS_SLV27F_SHIFT)) & PMC_STS_SLV27F_MASK)

#define PMC_STS_LVI_MASK                         (0x10U)
#define PMC_STS_LVI_SHIFT                        (4U)
/*! LVI - Low Voltage Interrupt
 *  0b0..Low voltage interrupt cleared.
 *  0b1..Low voltage interrupt asserted.
 */
#define PMC_STS_LVI(x)                           (((uint16_t)(((uint16_t)(x)) << PMC_STS_LVI_SHIFT)) & PMC_STS_LVI_MASK)

#define PMC_STS_SR27_MASK                        (0x20U)
#define PMC_STS_SR27_SHIFT                       (5U)
/*! SR27 - Small Regulator 2.7 V Active Flag
 *  0b0..The small regulator 2.7 V supply is not ready to be used.
 *  0b1..The small regulator 2.7 V supply is ready to be used.
 */
#define PMC_STS_SR27(x)                          (((uint16_t)(((uint16_t)(x)) << PMC_STS_SR27_SHIFT)) & PMC_STS_SR27_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PMC_H_ */

