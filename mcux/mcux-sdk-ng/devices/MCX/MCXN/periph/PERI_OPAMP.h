/*
** ###################################################################
**     Processors:          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 2.0, 2023-02-01
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OPAMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**
** ###################################################################
*/

/*!
 * @file OPAMP.h
 * @version 2.0
 * @date 2023-02-01
 * @brief CMSIS Peripheral Access Layer for OPAMP
 *
 * CMSIS Peripheral Access Layer for OPAMP
 */

#if !defined(OPAMP_H_)
#define OPAMP_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- OPAMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OPAMP_Peripheral_Access_Layer OPAMP Peripheral Access Layer
 * @{
 */

/** OPAMP - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t OPAMP_CTR;                         /**< OPAMP Control, offset: 0x8 */
} OPAMP_Type;

/* ----------------------------------------------------------------------------
   -- OPAMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OPAMP_Register_Masks OPAMP Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define OPAMP_VERID_FEATURE_MASK                 (0xFFFFU)
#define OPAMP_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Specification Number */
#define OPAMP_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << OPAMP_VERID_FEATURE_SHIFT)) & OPAMP_VERID_FEATURE_MASK)

#define OPAMP_VERID_MINOR_MASK                   (0xFF0000U)
#define OPAMP_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define OPAMP_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << OPAMP_VERID_MINOR_SHIFT)) & OPAMP_VERID_MINOR_MASK)

#define OPAMP_VERID_MAJOR_MASK                   (0xFF000000U)
#define OPAMP_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define OPAMP_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << OPAMP_VERID_MAJOR_SHIFT)) & OPAMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define OPAMP_PARAM_PGA_FUNCTION_MASK            (0x1U)
#define OPAMP_PARAM_PGA_FUNCTION_SHIFT           (0U)
/*! PGA_FUNCTION - PGA Function Option
 *  0b0..Core amplifier enabled
 *  0b1..PGA function enabled
 */
#define OPAMP_PARAM_PGA_FUNCTION(x)              (((uint32_t)(((uint32_t)(x)) << OPAMP_PARAM_PGA_FUNCTION_SHIFT)) & OPAMP_PARAM_PGA_FUNCTION_MASK)
/*! @} */

/*! @name OPAMP_CTR - OPAMP Control */
/*! @{ */

#define OPAMP_OPAMP_CTR_EN_MASK                  (0x1U)
#define OPAMP_OPAMP_CTR_EN_SHIFT                 (0U)
/*! EN - OPAMP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define OPAMP_OPAMP_CTR_EN(x)                    (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_EN_SHIFT)) & OPAMP_OPAMP_CTR_EN_MASK)

#define OPAMP_OPAMP_CTR_MODE_MASK                (0x2U)
#define OPAMP_OPAMP_CTR_MODE_SHIFT               (1U)
/*! MODE - Mode Selection
 *  0b0..High performance mode
 *  0b1..Low power mode
 */
#define OPAMP_OPAMP_CTR_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_MODE_SHIFT)) & OPAMP_OPAMP_CTR_MODE_MASK)

#define OPAMP_OPAMP_CTR_BIASC_MASK               (0xCU)
#define OPAMP_OPAMP_CTR_BIASC_SHIFT              (2U)
/*! BIASC - Bias Current Trim Selection
 *  0b00..Default
 *  0b01..Increase current
 *  0b10..Decrease current
 *  0b11..Further decrease current
 */
#define OPAMP_OPAMP_CTR_BIASC(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_BIASC_SHIFT)) & OPAMP_OPAMP_CTR_BIASC_MASK)

#define OPAMP_OPAMP_CTR_INTREF_MASK              (0x30U)
#define OPAMP_OPAMP_CTR_INTREF_SHIFT             (4U)
/*! INTREF - Provide OPAMP rail to rail voltage selection
 *  0b00..Select OPAMP input rail to rail voltage from 0 to VDD_ANA
 *  0b01..Select OPAMP input rail to rail voltage from 0 to VDD_ANA-0.8V
 *  0b10..Select OPAMP input rail to rail voltage from 0.8V to VDD_ANA
 *  0b11..Not allowed
 */
#define OPAMP_OPAMP_CTR_INTREF(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_INTREF_SHIFT)) & OPAMP_OPAMP_CTR_INTREF_MASK)

#define OPAMP_OPAMP_CTR_TRIGMD_MASK              (0x100U)
#define OPAMP_OPAMP_CTR_TRIGMD_SHIFT             (8U)
/*! TRIGMD - Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define OPAMP_OPAMP_CTR_TRIGMD(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_TRIGMD_SHIFT)) & OPAMP_OPAMP_CTR_TRIGMD_MASK)

#define OPAMP_OPAMP_CTR_INPSEL_MASK              (0x200U)
#define OPAMP_OPAMP_CTR_INPSEL_SHIFT             (9U)
/*! INPSEL - Positive Input Channel Selection
 *  0b0..When OPAMP is not in trigger mode, select positive input 0 (INP0)
 *  0b1..When OPAMP is not in trigger mode, select positive input 1 (INP1)
 */
#define OPAMP_OPAMP_CTR_INPSEL(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_INPSEL_SHIFT)) & OPAMP_OPAMP_CTR_INPSEL_MASK)

#define OPAMP_OPAMP_CTR_INPF_MASK                (0x1000U)
#define OPAMP_OPAMP_CTR_INPF_SHIFT               (12U)
/*! INPF - Positive Input Connection Status
 *  0b0..Positive input 0 (INP0)
 *  0b1..Positive input 1 (INP1)
 */
#define OPAMP_OPAMP_CTR_INPF(x)                  (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_INPF_SHIFT)) & OPAMP_OPAMP_CTR_INPF_MASK)

#define OPAMP_OPAMP_CTR_BUFEN_MASK               (0x10000U)
#define OPAMP_OPAMP_CTR_BUFEN_SHIFT              (16U)
/*! BUFEN - Reference Buffer
 *  0b0..Disables
 *  0b1..Enables
 */
#define OPAMP_OPAMP_CTR_BUFEN(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_BUFEN_SHIFT)) & OPAMP_OPAMP_CTR_BUFEN_MASK)

#define OPAMP_OPAMP_CTR_PREF_MASK                (0x60000U)
#define OPAMP_OPAMP_CTR_PREF_SHIFT               (17U)
/*! PREF - Positive Reference Voltage Selection
 *  0b00..Input 0
 *  0b01..Input 1
 *  0b10..Input 2
 *  0b11..Input 3
 */
#define OPAMP_OPAMP_CTR_PREF(x)                  (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_PREF_SHIFT)) & OPAMP_OPAMP_CTR_PREF_MASK)

#define OPAMP_OPAMP_CTR_ADCSW1_MASK              (0x100000U)
#define OPAMP_OPAMP_CTR_ADCSW1_SHIFT             (20U)
/*! ADCSW1 - Measure Switch 1
 *  0b0..Measure negative gain resistor ladder voltage switch off
 *  0b1..Measure negative gain resistor ladder voltage switch on
 */
#define OPAMP_OPAMP_CTR_ADCSW1(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_ADCSW1_SHIFT)) & OPAMP_OPAMP_CTR_ADCSW1_MASK)

#define OPAMP_OPAMP_CTR_ADCSW2_MASK              (0x200000U)
#define OPAMP_OPAMP_CTR_ADCSW2_SHIFT             (21U)
/*! ADCSW2 - Measure Switch 2
 *  0b0..Measure positive gain resistor ladder reference voltage switch off
 *  0b1..Measure positive gain resistor ladder reference voltage switch on
 */
#define OPAMP_OPAMP_CTR_ADCSW2(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_ADCSW2_SHIFT)) & OPAMP_OPAMP_CTR_ADCSW2_MASK)

#define OPAMP_OPAMP_CTR_OUTSW_MASK               (0x400000U)
#define OPAMP_OPAMP_CTR_OUTSW_SHIFT              (22U)
/*! OUTSW - Output Switch
 *  0b0..OPAMP out to negative gain resistor ladder switch off
 *  0b1..OPAMP out to negative gain resistor ladder switch on
 */
#define OPAMP_OPAMP_CTR_OUTSW(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_OUTSW_SHIFT)) & OPAMP_OPAMP_CTR_OUTSW_MASK)

#define OPAMP_OPAMP_CTR_PGAIN_MASK               (0x7000000U)
#define OPAMP_OPAMP_CTR_PGAIN_SHIFT              (24U)
/*! PGAIN - Positive PGA Selection
 *  0b000..Positive input 1 (INP1)
 *  0b001..Pgain=1
 *  0b010..Pgain=2
 *  0b011..Pgain=4
 *  0b100..Pgain=8
 *  0b101..Pgain=16
 *  0b110..Pgain=33
 *  0b111..Pgain=64
 */
#define OPAMP_OPAMP_CTR_PGAIN(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_PGAIN_SHIFT)) & OPAMP_OPAMP_CTR_PGAIN_MASK)

#define OPAMP_OPAMP_CTR_NGAIN_MASK               (0x70000000U)
#define OPAMP_OPAMP_CTR_NGAIN_SHIFT              (28U)
/*! NGAIN - Negative PGA Selection
 *  0b000..Buffer
 *  0b001..Ngain=1
 *  0b010..Ngain=2
 *  0b011..Ngain=4
 *  0b100..Ngain=8
 *  0b101..Ngain=16
 *  0b110..Ngain=33
 *  0b111..Ngain=64
 */
#define OPAMP_OPAMP_CTR_NGAIN(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_NGAIN_SHIFT)) & OPAMP_OPAMP_CTR_NGAIN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OPAMP_Register_Masks */


/*!
 * @}
 */ /* end of group OPAMP_Peripheral_Access_Layer */


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


#endif  /* OPAMP_H_ */

