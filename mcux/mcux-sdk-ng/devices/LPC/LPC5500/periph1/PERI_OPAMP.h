/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OPAMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OPAMP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OPAMP
 *
 * CMSIS Peripheral Access Layer for OPAMP
 */

#if !defined(PERI_OPAMP_H_)
#define PERI_OPAMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t OPAMP_CTR;                         /**< OPAMP control register, offset: 0x8 */
} OPAMP_Type;

/* ----------------------------------------------------------------------------
   -- OPAMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OPAMP_Register_Masks OPAMP Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
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

/*! @name PARAM - Parameter Register */
/*! @{ */

#define OPAMP_PARAM_PGA_FUNCTION_MASK            (0x1U)
#define OPAMP_PARAM_PGA_FUNCTION_SHIFT           (0U)
/*! PGA_FUNCTION - PGA Function Option
 *  0b0..Core amplifier is enabled.
 *  0b1..PGA function is enabled.
 */
#define OPAMP_PARAM_PGA_FUNCTION(x)              (((uint32_t)(((uint32_t)(x)) << OPAMP_PARAM_PGA_FUNCTION_SHIFT)) & OPAMP_PARAM_PGA_FUNCTION_MASK)
/*! @} */

/*! @name OPAMP_CTR - OPAMP control register */
/*! @{ */

#define OPAMP_OPAMP_CTR_EN_MASK                  (0x1U)
#define OPAMP_OPAMP_CTR_EN_SHIFT                 (0U)
/*! EN - OPAMP Enable
 *  0b0..OPAMP is disabled
 *  0b1..OPAMP is enabled
 */
#define OPAMP_OPAMP_CTR_EN(x)                    (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_EN_SHIFT)) & OPAMP_OPAMP_CTR_EN_MASK)

#define OPAMP_OPAMP_CTR_MODE_MASK                (0x2U)
#define OPAMP_OPAMP_CTR_MODE_SHIFT               (1U)
/*! MODE - Mode Selection
 *  0b0..Low noise mode.
 *  0b1..High speed mode.
 */
#define OPAMP_OPAMP_CTR_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_MODE_SHIFT)) & OPAMP_OPAMP_CTR_MODE_MASK)

#define OPAMP_OPAMP_CTR_BIASC_MASK               (0xCU)
#define OPAMP_OPAMP_CTR_BIASC_SHIFT              (2U)
/*! BIASC - Bias Current Trim Selection
 *  0b00..Default.
 *  0b01..Increase current.
 *  0b10..Decrease current.
 *  0b11..Further decrease current.
 */
#define OPAMP_OPAMP_CTR_BIASC(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_BIASC_SHIFT)) & OPAMP_OPAMP_CTR_BIASC_MASK)

#define OPAMP_OPAMP_CTR_INTREF_MASK              (0x30U)
#define OPAMP_OPAMP_CTR_INTREF_SHIFT             (4U)
/*! INTREF - Internal Reference Voltage Selection
 *  0b00..Select vdda/2.
 *  0b01..Select vdda_3v.
 *  0b10..Select vssa_3v.
 *  0b11..Not allowed.
 */
#define OPAMP_OPAMP_CTR_INTREF(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_INTREF_SHIFT)) & OPAMP_OPAMP_CTR_INTREF_MASK)

#define OPAMP_OPAMP_CTR_ADCSW_MASK               (0x10000U)
#define OPAMP_OPAMP_CTR_ADCSW_SHIFT              (16U)
/*! ADCSW - ADC Channel Switch */
#define OPAMP_OPAMP_CTR_ADCSW(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_ADCSW_SHIFT)) & OPAMP_OPAMP_CTR_ADCSW_MASK)

#define OPAMP_OPAMP_CTR_PREF_MASK                (0x60000U)
#define OPAMP_OPAMP_CTR_PREF_SHIFT               (17U)
/*! PREF - Positive Reference Voltage Selection
 *  0b00..Select vrefh3.
 *  0b01..Select vrefh0.
 *  0b10..Select vrefh1.
 *  0b11..Reserved.
 */
#define OPAMP_OPAMP_CTR_PREF(x)                  (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_PREF_SHIFT)) & OPAMP_OPAMP_CTR_PREF_MASK)

#define OPAMP_OPAMP_CTR_PGAIN_MASK               (0x700000U)
#define OPAMP_OPAMP_CTR_PGAIN_SHIFT              (20U)
/*! PGAIN - Positive PGA Selection.
 *  0b000..Reserved.
 *  0b001..Ratio 1:1
 *  0b010..Ratio 1:2
 *  0b011..Ratio 1:4
 *  0b100..Ratio 1:8
 *  0b101..Ratio 1:16
 *  0b110..Ratio 1:33
 *  0b111..Ratio 1:64
 */
#define OPAMP_OPAMP_CTR_PGAIN(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTR_PGAIN_SHIFT)) & OPAMP_OPAMP_CTR_PGAIN_MASK)

#define OPAMP_OPAMP_CTR_NGAIN_MASK               (0x7000000U)
#define OPAMP_OPAMP_CTR_NGAIN_SHIFT              (24U)
/*! NGAIN - Negative PGA selection
 *  0b000..Buffer.
 *  0b001..Ratio 1:1
 *  0b010..Ratio 1:2
 *  0b011..Ratio 1:4
 *  0b100..Ratio 1:8
 *  0b101..Ratio 1:16
 *  0b110..Ratio 1:33
 *  0b111..Ratio 1:64
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


#endif  /* PERI_OPAMP_H_ */

