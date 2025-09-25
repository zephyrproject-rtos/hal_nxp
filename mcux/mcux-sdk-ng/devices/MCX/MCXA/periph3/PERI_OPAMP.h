/*
** ###################################################################
**     Processors:          MCXA343VFM
**                          MCXA343VLF
**                          MCXA343VLH
**                          MCXA343VLL
**                          MCXA344VFM
**                          MCXA344VLF
**                          MCXA344VLH
**                          MCXA344VLL
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250806
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
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
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

#if (defined(CPU_MCXA343VFM) || defined(CPU_MCXA343VLF) || defined(CPU_MCXA343VLH) || defined(CPU_MCXA343VLL))
#include "MCXA343_COMMON.h"
#elif (defined(CPU_MCXA344VFM) || defined(CPU_MCXA344VLF) || defined(CPU_MCXA344VLH) || defined(CPU_MCXA344VLL))
#include "MCXA344_COMMON.h"
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
 *  0b11..Increase power consumption to 3/2
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

