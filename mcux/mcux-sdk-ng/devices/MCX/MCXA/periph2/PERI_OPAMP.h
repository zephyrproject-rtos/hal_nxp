/*
** ###################################################################
**     Processors:          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**                          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**                          MCXA346VLH
**                          MCXA346VLL
**                          MCXA346VLQ
**                          MCXA346VPN
**                          MCXA366VLH
**                          MCXA366VLL
**                          MCXA366VLQ
**                          MCXA366VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250729
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
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_OPAMP.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for OPAMP
 *
 * CMSIS Peripheral Access Layer for OPAMP
 */

#if !defined(PERI_OPAMP_H_)
#define PERI_OPAMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
#elif (defined(CPU_MCXA345VLH) || defined(CPU_MCXA345VLL) || defined(CPU_MCXA345VLQ) || defined(CPU_MCXA345VPN))
#include "MCXA345_COMMON.h"
#elif (defined(CPU_MCXA346VLH) || defined(CPU_MCXA346VLL) || defined(CPU_MCXA346VLQ) || defined(CPU_MCXA346VPN))
#include "MCXA346_COMMON.h"
#elif (defined(CPU_MCXA366VLH) || defined(CPU_MCXA366VLL) || defined(CPU_MCXA366VLQ) || defined(CPU_MCXA366VPN))
#include "MCXA366_COMMON.h"
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
  __IO uint32_t OPAMP_CTRL;                        /**< OPAMP Control, offset: 0x8 */
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

#define OPAMP_PARAM_PARAM_MASK                   (0xFFFFFFFFU)
#define OPAMP_PARAM_PARAM_SHIFT                  (0U)
/*! PARAM - Parameters */
#define OPAMP_PARAM_PARAM(x)                     (((uint32_t)(((uint32_t)(x)) << OPAMP_PARAM_PARAM_SHIFT)) & OPAMP_PARAM_PARAM_MASK)
/*! @} */

/*! @name OPAMP_CTRL - OPAMP Control */
/*! @{ */

#define OPAMP_OPAMP_CTRL_OPA_EN_MASK             (0x1U)
#define OPAMP_OPAMP_CTRL_OPA_EN_SHIFT            (0U)
/*! OPA_EN - OPAMP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define OPAMP_OPAMP_CTRL_OPA_EN(x)               (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTRL_OPA_EN_SHIFT)) & OPAMP_OPAMP_CTRL_OPA_EN_MASK)

#define OPAMP_OPAMP_CTRL_OPA_CC_SEL_MASK         (0x30U)
#define OPAMP_OPAMP_CTRL_OPA_CC_SEL_SHIFT        (4U)
/*! OPA_CC_SEL - Compensation capcitor config selection
 *  0b00..Fit 2X gains
 *  0b01..Fit 4X gains
 *  0b10..Fit 8X gains
 *  0b11..Fit 16X gains
 */
#define OPAMP_OPAMP_CTRL_OPA_CC_SEL(x)           (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTRL_OPA_CC_SEL_SHIFT)) & OPAMP_OPAMP_CTRL_OPA_CC_SEL_MASK)

#define OPAMP_OPAMP_CTRL_OPA_BC_SEL_MASK         (0xC0U)
#define OPAMP_OPAMP_CTRL_OPA_BC_SEL_SHIFT        (6U)
/*! OPA_BC_SEL - Bias current config selection
 *  0b00..Default value. Keep power consumption constant
 *  0b01..Reduce power consumption to 1/4
 *  0b10..Reduce power consumption to 1/2
 *  0b11..Double the power consumption
 */
#define OPAMP_OPAMP_CTRL_OPA_BC_SEL(x)           (((uint32_t)(((uint32_t)(x)) << OPAMP_OPAMP_CTRL_OPA_BC_SEL_SHIFT)) & OPAMP_OPAMP_CTRL_OPA_BC_SEL_MASK)
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

