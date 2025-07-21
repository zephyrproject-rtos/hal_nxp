/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ATX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ATX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ATX
 *
 * CMSIS Peripheral Access Layer for ATX
 */

#if !defined(PERI_ATX_H_)
#define PERI_ATX_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- ATX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ATX_Peripheral_Access_Layer ATX Peripheral Access Layer
 * @{
 */

/** ATX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Analog Test Annex Control, offset: 0x0 */
  __I  uint32_t CUT_CNT;                           /**< Analog Test Annex Clock Under Test Counter, offset: 0x4 */
  __I  uint32_t REF_CNT;                           /**< Analog Test Annex Reference Clock Counter, offset: 0x8 */
  __IO uint32_t CUT_TARGET;                        /**< Analog Test Annex Clock Under Test Target Count, offset: 0xC */
  __IO uint32_t REF_TARGET;                        /**< Analog Test Annex Reference Clock Target Count, offset: 0x10 */
  __I  uint32_t CNT_STAT;                          /**< Analog Test Annex Count Status Register, offset: 0x14 */
       uint8_t RESERVED_0[4];
  __I  uint32_t REF_CNT_SAVED;                     /**< Analog Test Annex Reference Clock Count Saved Register, offset: 0x1C */
} ATX_Type;

/* ----------------------------------------------------------------------------
   -- ATX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ATX_Register_Masks ATX Register Masks
 * @{
 */

/*! @name CTRL - Analog Test Annex Control */
/*! @{ */

#define ATX_CTRL_CUT_PREDIV_MASK                 (0xFFU)
#define ATX_CTRL_CUT_PREDIV_SHIFT                (0U)
/*! CUT_PREDIV - CUT_PREDIV */
#define ATX_CTRL_CUT_PREDIV(x)                   (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_CUT_PREDIV_SHIFT)) & ATX_CTRL_CUT_PREDIV_MASK)

#define ATX_CTRL_CUT_SEL_MASK                    (0x7F00U)
#define ATX_CTRL_CUT_SEL_SHIFT                   (8U)
/*! CUT_SEL - CUT_SEL */
#define ATX_CTRL_CUT_SEL(x)                      (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_CUT_SEL_SHIFT)) & ATX_CTRL_CUT_SEL_MASK)

#define ATX_CTRL_CUT_PIN_EN_MASK                 (0x8000U)
#define ATX_CTRL_CUT_PIN_EN_SHIFT                (15U)
/*! CUT_PIN_EN - CUT_PIN_EN */
#define ATX_CTRL_CUT_PIN_EN(x)                   (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_CUT_PIN_EN_SHIFT)) & ATX_CTRL_CUT_PIN_EN_MASK)

#define ATX_CTRL_SENSE_PIN_EN_MASK               (0x20000U)
#define ATX_CTRL_SENSE_PIN_EN_SHIFT              (17U)
/*! SENSE_PIN_EN - SENSE_PIN_EN
 *  0b0..Sense bus not connected to external pin.
 *  0b1..Sense bus connected to external pin.
 */
#define ATX_CTRL_SENSE_PIN_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_SENSE_PIN_EN_SHIFT)) & ATX_CTRL_SENSE_PIN_EN_MASK)

#define ATX_CTRL_SENSE_SEL_MASK                  (0xFC0000U)
#define ATX_CTRL_SENSE_SEL_SHIFT                 (18U)
/*! SENSE_SEL - SENSE_SEL */
#define ATX_CTRL_SENSE_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_SENSE_SEL_SHIFT)) & ATX_CTRL_SENSE_SEL_MASK)

#define ATX_CTRL_DACFORCE_EN_MASK                (0x1000000U)
#define ATX_CTRL_DACFORCE_EN_SHIFT               (24U)
/*! DACFORCE_EN - DACFORCE_EN
 *  0b0..DAC output not connected to the force bus.
 *  0b1..DAC output connected to the force bus.
 */
#define ATX_CTRL_DACFORCE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_DACFORCE_EN_SHIFT)) & ATX_CTRL_DACFORCE_EN_MASK)

#define ATX_CTRL_FORCE_PIN_EN_MASK               (0x2000000U)
#define ATX_CTRL_FORCE_PIN_EN_SHIFT              (25U)
/*! FORCE_PIN_EN - FORCE_PIN_EN
 *  0b0..Force bus not connected to external pin.
 *  0b1..Force bus connected to external pin.
 */
#define ATX_CTRL_FORCE_PIN_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_FORCE_PIN_EN_SHIFT)) & ATX_CTRL_FORCE_PIN_EN_MASK)

#define ATX_CTRL_FORCE_SEL_MASK                  (0xFC000000U)
#define ATX_CTRL_FORCE_SEL_SHIFT                 (26U)
/*! FORCE_SEL - FORCE_SEL */
#define ATX_CTRL_FORCE_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_FORCE_SEL_SHIFT)) & ATX_CTRL_FORCE_SEL_MASK)
/*! @} */

/*! @name CUT_CNT - Analog Test Annex Clock Under Test Counter */
/*! @{ */

#define ATX_CUT_CNT_CUT_CNT_MASK                 (0xFFFFFFFFU)
#define ATX_CUT_CNT_CUT_CNT_SHIFT                (0U)
/*! CUT_CNT - CUT_CNT */
#define ATX_CUT_CNT_CUT_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << ATX_CUT_CNT_CUT_CNT_SHIFT)) & ATX_CUT_CNT_CUT_CNT_MASK)
/*! @} */

/*! @name REF_CNT - Analog Test Annex Reference Clock Counter */
/*! @{ */

#define ATX_REF_CNT_REF_CNT_MASK                 (0xFFFFFFFFU)
#define ATX_REF_CNT_REF_CNT_SHIFT                (0U)
/*! REF_CNT - REF_CNT */
#define ATX_REF_CNT_REF_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << ATX_REF_CNT_REF_CNT_SHIFT)) & ATX_REF_CNT_REF_CNT_MASK)
/*! @} */

/*! @name CUT_TARGET - Analog Test Annex Clock Under Test Target Count */
/*! @{ */

#define ATX_CUT_TARGET_CUT_TARGET_MASK           (0xFFFFFFFFU)
#define ATX_CUT_TARGET_CUT_TARGET_SHIFT          (0U)
/*! CUT_TARGET - CUT_TARGET */
#define ATX_CUT_TARGET_CUT_TARGET(x)             (((uint32_t)(((uint32_t)(x)) << ATX_CUT_TARGET_CUT_TARGET_SHIFT)) & ATX_CUT_TARGET_CUT_TARGET_MASK)
/*! @} */

/*! @name REF_TARGET - Analog Test Annex Reference Clock Target Count */
/*! @{ */

#define ATX_REF_TARGET_REF_TARGET_MASK           (0xFFFFFFFFU)
#define ATX_REF_TARGET_REF_TARGET_SHIFT          (0U)
/*! REF_TARGET - REF_TARGET */
#define ATX_REF_TARGET_REF_TARGET(x)             (((uint32_t)(((uint32_t)(x)) << ATX_REF_TARGET_REF_TARGET_SHIFT)) & ATX_REF_TARGET_REF_TARGET_MASK)
/*! @} */

/*! @name CNT_STAT - Analog Test Annex Count Status Register */
/*! @{ */

#define ATX_CNT_STAT_REF_STOPPED_MASK            (0x1U)
#define ATX_CNT_STAT_REF_STOPPED_SHIFT           (0U)
/*! REF_STOPPED - REF_STOPPED */
#define ATX_CNT_STAT_REF_STOPPED(x)              (((uint32_t)(((uint32_t)(x)) << ATX_CNT_STAT_REF_STOPPED_SHIFT)) & ATX_CNT_STAT_REF_STOPPED_MASK)

#define ATX_CNT_STAT_CUT_STOPPED_MASK            (0x2U)
#define ATX_CNT_STAT_CUT_STOPPED_SHIFT           (1U)
/*! CUT_STOPPED - CUT_STOPPED */
#define ATX_CNT_STAT_CUT_STOPPED(x)              (((uint32_t)(((uint32_t)(x)) << ATX_CNT_STAT_CUT_STOPPED_SHIFT)) & ATX_CNT_STAT_CUT_STOPPED_MASK)

#define ATX_CNT_STAT_CUT_STARTED_MASK            (0x4U)
#define ATX_CNT_STAT_CUT_STARTED_SHIFT           (2U)
/*! CUT_STARTED - CUT_STARTED */
#define ATX_CNT_STAT_CUT_STARTED(x)              (((uint32_t)(((uint32_t)(x)) << ATX_CNT_STAT_CUT_STARTED_SHIFT)) & ATX_CNT_STAT_CUT_STARTED_MASK)
/*! @} */

/*! @name REF_CNT_SAVED - Analog Test Annex Reference Clock Count Saved Register */
/*! @{ */

#define ATX_REF_CNT_SAVED_REF_CNT_SAVED_MASK     (0xFFFFFFFFU)
#define ATX_REF_CNT_SAVED_REF_CNT_SAVED_SHIFT    (0U)
/*! REF_CNT_SAVED - REF_CNT_SAVED */
#define ATX_REF_CNT_SAVED_REF_CNT_SAVED(x)       (((uint32_t)(((uint32_t)(x)) << ATX_REF_CNT_SAVED_REF_CNT_SAVED_SHIFT)) & ATX_REF_CNT_SAVED_REF_CNT_SAVED_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ATX_Register_Masks */


/*!
 * @}
 */ /* end of group ATX_Peripheral_Access_Layer */


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


#endif  /* PERI_ATX_H_ */

