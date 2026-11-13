/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OPAMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_OPAMP.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for OPAMP
 *
 * CMSIS Peripheral Access Layer for OPAMP
 */

#if !defined(PERI_OPAMP_H_)
#define PERI_OPAMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
       uint8_t RESERVED_0[4];
  __IO uint32_t CTRL;                              /**< OPAMP Control, offset: 0x8 */
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

/*! @name CTRL - OPAMP Control */
/*! @{ */

#define OPAMP_CTRL_IREF_CONFIG_MASK              (0x3U)
#define OPAMP_CTRL_IREF_CONFIG_SHIFT             (0U)
/*! IREF_CONFIG - Iref Configuration
 *  0b00..bias current ratio=1
 *  0b01..bias current ratio=1/4
 *  0b10..bias current ratio=1/2
 *  0b11..bias current ratio=3/2
 */
#define OPAMP_CTRL_IREF_CONFIG(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_CTRL_IREF_CONFIG_SHIFT)) & OPAMP_CTRL_IREF_CONFIG_MASK)

#define OPAMP_CTRL_VOS_TRIM_MASK                 (0xF0U)
#define OPAMP_CTRL_VOS_TRIM_SHIFT                (4U)
/*! VOS_TRIM - Input Offset Voltage Trim
 *  0b0000-0b0111..input offset voltage trim=0v
 *  0b1000..input offset voltage trim=0.0015v
 *  0b1001..input offset voltage trim=0.003v
 *  0b1010..input offset voltage trim=0.0045v
 *  0b1011..input offset voltage trim=0.006v
 *  0b1100..input offset voltage trim=-0.0015v
 *  0b1101..input offset voltage trim=-0.003v
 *  0b1110..input offset voltage trim=-0.0045v
 *  0b1111..input offset voltage trim=-0.006v
 */
#define OPAMP_CTRL_VOS_TRIM(x)                   (((uint32_t)(((uint32_t)(x)) << OPAMP_CTRL_VOS_TRIM_SHIFT)) & OPAMP_CTRL_VOS_TRIM_MASK)

#define OPAMP_CTRL_GAIN_CONFIG_MASK              (0x700U)
#define OPAMP_CTRL_GAIN_CONFIG_SHIFT             (8U)
/*! GAIN_CONFIG - Gain Configuration
 *  0b000..set OPAMP gain to 3
 *  0b001..set OPAMP gain to 4
 *  0b010..set OPAMP gain to 5
 *  0b011..set OPAMP gain to 6.5
 *  0b100..set OPAMP gain to 9
 *  0b101..set OPAMP gain to 11
 *  0b110..set OPAMP gain to 14
 *  0b111..set OPAMP gain to 19
 */
#define OPAMP_CTRL_GAIN_CONFIG(x)                (((uint32_t)(((uint32_t)(x)) << OPAMP_CTRL_GAIN_CONFIG_SHIFT)) & OPAMP_CTRL_GAIN_CONFIG_MASK)

#define OPAMP_CTRL_CC_CONFIG_MASK                (0xF0000U)
#define OPAMP_CTRL_CC_CONFIG_SHIFT               (16U)
/*! CC_CONFIG - Capacitance Compensation Configuration
 *  0b0000-0b0110..Reserved
 *  0b0111..when gain=3
 *  0b1000..when gain=4
 *  0b1001..when gain=5
 *  0b1010..Reserved
 *  0b1011..when gain=6.5
 *  0b1100..when gain=9
 *  0b1101..when gain=11
 *  0b1110..when gain=14
 *  0b1111..when gain=19
 */
#define OPAMP_CTRL_CC_CONFIG(x)                  (((uint32_t)(((uint32_t)(x)) << OPAMP_CTRL_CC_CONFIG_SHIFT)) & OPAMP_CTRL_CC_CONFIG_MASK)

#define OPAMP_CTRL_OFFSET_SEL_MASK               (0x3000000U)
#define OPAMP_CTRL_OFFSET_SEL_SHIFT              (24U)
/*! OFFSET_SEL - Offset Select
 *  0b00..Vref=vdda/2
 *  0b01..Vref=vdda/4
 *  0b10..Vref=vdda/8
 *  0b11..Reserved
 */
#define OPAMP_CTRL_OFFSET_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << OPAMP_CTRL_OFFSET_SEL_SHIFT)) & OPAMP_CTRL_OFFSET_SEL_MASK)

#define OPAMP_CTRL_ENA_MASK                      (0x80000000U)
#define OPAMP_CTRL_ENA_SHIFT                     (31U)
/*! ENA - OPAMP Enable
 *  0b0..Disable OPAMP
 *  0b1..Enable OPAMP
 */
#define OPAMP_CTRL_ENA(x)                        (((uint32_t)(((uint32_t)(x)) << OPAMP_CTRL_ENA_SHIFT)) & OPAMP_CTRL_ENA_MASK)
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

