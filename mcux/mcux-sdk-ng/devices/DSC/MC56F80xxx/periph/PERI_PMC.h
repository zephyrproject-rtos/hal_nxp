/*
** ###################################################################
**     Processors:          MC56F80623VLC
**                          MC56F80626VLF
**                          MC56F80643VLC
**                          MC56F80646VLF
**                          MC56F80648VLH
**                          MC56F80723VLC
**                          MC56F80726VLF
**                          MC56F80733VFM
**                          MC56F80736VLF
**                          MC56F80738VLH
**                          MC56F80743VFM
**                          MC56F80743VLC
**                          MC56F80746MLF
**                          MC56F80746VLF
**                          MC56F80748MLH
**                          MC56F80748VLH
**
**     Version:             rev. 1.0, 2024-10-29
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
**     - rev. 0.1 (2022-01-12)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F80623VLC))
#include "MC56F80623_COMMON.h"
#elif (defined(CPU_MC56F80626VLF))
#include "MC56F80626_COMMON.h"
#elif (defined(CPU_MC56F80643VLC))
#include "MC56F80643_COMMON.h"
#elif (defined(CPU_MC56F80646VLF))
#include "MC56F80646_COMMON.h"
#elif (defined(CPU_MC56F80648VLH))
#include "MC56F80648_COMMON.h"
#elif (defined(CPU_MC56F80723VLC))
#include "MC56F80723_COMMON.h"
#elif (defined(CPU_MC56F80726VLF))
#include "MC56F80726_COMMON.h"
#elif (defined(CPU_MC56F80733VFM))
#include "MC56F80733_COMMON.h"
#elif (defined(CPU_MC56F80736VLF))
#include "MC56F80736_COMMON.h"
#elif (defined(CPU_MC56F80738VLH))
#include "MC56F80738_COMMON.h"
#elif (defined(CPU_MC56F80743VFM) || defined(CPU_MC56F80743VLC))
#include "MC56F80743_COMMON.h"
#elif (defined(CPU_MC56F80746MLF) || defined(CPU_MC56F80746VLF))
#include "MC56F80746_COMMON.h"
#elif (defined(CPU_MC56F80748MLH) || defined(CPU_MC56F80748VLH))
#include "MC56F80748_COMMON.h"
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
  __IO uint16_t TRIM;                              /**< Trim Register, offset: 0x2 */
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

#define PMC_CTRL_LV265IE_MASK                    (0x2U)
#define PMC_CTRL_LV265IE_SHIFT                   (1U)
/*! LV265IE - 2.65 V Low Voltage Interrupt Enable
 *  0b0..Disable setting the low voltage interrupt.
 *  0b1..Enable setting the low voltage interrupt.
 */
#define PMC_CTRL_LV265IE(x)                      (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_LV265IE_SHIFT)) & PMC_CTRL_LV265IE_MASK)

#define PMC_CTRL_HV22IE_MASK                     (0x4U)
#define PMC_CTRL_HV22IE_SHIFT                    (2U)
/*! HV22IE - 2.2 V High Voltage Interrupt Enable
 *  0b0..Disable setting the high voltage interrupt.
 *  0b1..Enable setting the high voltage interrupt.
 */
#define PMC_CTRL_HV22IE(x)                       (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_HV22IE_SHIFT)) & PMC_CTRL_HV22IE_MASK)

#define PMC_CTRL_HV265IE_MASK                    (0x8U)
#define PMC_CTRL_HV265IE_SHIFT                   (3U)
/*! HV265IE - 2.65 V High Voltage Interrupt Enable
 *  0b0..Disable setting the high voltage interrupt.
 *  0b1..Enable setting the high voltage interrupt.
 */
#define PMC_CTRL_HV265IE(x)                      (((uint16_t)(((uint16_t)(x)) << PMC_CTRL_HV265IE_SHIFT)) & PMC_CTRL_HV265IE_MASK)

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

#define PMC_STS_LV265F_MASK                      (0x2U)
#define PMC_STS_LV265F_SHIFT                     (1U)
/*! LV265F - 2.65 V Low Voltage Flag
 *  0b0..3.3 V supply is not below the 2.65 V threshold.
 *  0b1..3.3 V supply is below the 2.65 V threshold.
 */
#define PMC_STS_LV265F(x)                        (((uint16_t)(((uint16_t)(x)) << PMC_STS_LV265F_SHIFT)) & PMC_STS_LV265F_MASK)

#define PMC_STS_SLV22F_MASK                      (0x4U)
#define PMC_STS_SLV22F_SHIFT                     (2U)
/*! SLV22F - Sticky 2.2 V Low Voltage Flag
 *  0b0..3.3 V supply has not dropped below the 2.2 V threshold.
 *  0b1..3.3 V supply has dropped below the 2.2 V threshold.
 */
#define PMC_STS_SLV22F(x)                        (((uint16_t)(((uint16_t)(x)) << PMC_STS_SLV22F_SHIFT)) & PMC_STS_SLV22F_MASK)

#define PMC_STS_SLV265F_MASK                     (0x8U)
#define PMC_STS_SLV265F_SHIFT                    (3U)
/*! SLV265F - Sticky 2.65 V Low Voltage Flag
 *  0b0..3.3 V supply has not dropped below the 2.65 V threshold.
 *  0b1..3.3 V supply has dropped below the 2.65 V threshold.
 */
#define PMC_STS_SLV265F(x)                       (((uint16_t)(((uint16_t)(x)) << PMC_STS_SLV265F_SHIFT)) & PMC_STS_SLV265F_MASK)

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

/*! @name TRIM - Trim Register */
/*! @{ */

#define PMC_TRIM_VCAP_MASK                       (0xFU)
#define PMC_TRIM_VCAP_SHIFT                      (0U)
/*! VCAP - Vcap voltage trim */
#define PMC_TRIM_VCAP(x)                         (((uint16_t)(((uint16_t)(x)) << PMC_TRIM_VCAP_SHIFT)) & PMC_TRIM_VCAP_MASK)

#define PMC_TRIM_VREF_MASK                       (0x1F00U)
#define PMC_TRIM_VREF_SHIFT                      (8U)
/*! VREF - Vref voltage trim */
#define PMC_TRIM_VREF(x)                         (((uint16_t)(((uint16_t)(x)) << PMC_TRIM_VREF_SHIFT)) & PMC_TRIM_VREF_MASK)
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

