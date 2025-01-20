/*
** ###################################################################
**     Processors:          MCXA165VLH
**                          MCXA165VLL
**                          MCXA165VLQ
**                          MCXA165VPN
**                          MCXA166VLH
**                          MCXA166VLL
**                          MCXA166VLQ
**                          MCXA166VPN
**                          MCXA175VLH
**                          MCXA175VLL
**                          MCXA175VLQ
**                          MCXA175VPN
**                          MCXA176VLH
**                          MCXA176VLL
**                          MCXA176VLQ
**                          MCXA176VPN
**                          MCXA275VLH
**                          MCXA275VLL
**                          MCXA275VLQ
**                          MCXA275VPN
**                          MCXA276VLH
**                          MCXA276VLL
**                          MCXA276VLQ
**                          MCXA276VPN
**
**     Version:             rev. 1.0, 2024-03-26
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FREQME
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**
** ###################################################################
*/

/*!
 * @file FREQME.h
 * @version 1.0
 * @date 2024-03-26
 * @brief CMSIS Peripheral Access Layer for FREQME
 *
 * CMSIS Peripheral Access Layer for FREQME
 */

#if !defined(FREQME_H_)
#define FREQME_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA165VLH) || defined(CPU_MCXA165VLL) || defined(CPU_MCXA165VLQ) || defined(CPU_MCXA165VPN))
#include "MCXA165_COMMON.h"
#elif (defined(CPU_MCXA166VLH) || defined(CPU_MCXA166VLL) || defined(CPU_MCXA166VLQ) || defined(CPU_MCXA166VPN))
#include "MCXA166_COMMON.h"
#elif (defined(CPU_MCXA175VLH) || defined(CPU_MCXA175VLL) || defined(CPU_MCXA175VLQ) || defined(CPU_MCXA175VPN))
#include "MCXA175_COMMON.h"
#elif (defined(CPU_MCXA176VLH) || defined(CPU_MCXA176VLL) || defined(CPU_MCXA176VLQ) || defined(CPU_MCXA176VPN))
#include "MCXA176_COMMON.h"
#elif (defined(CPU_MCXA275VLH) || defined(CPU_MCXA275VLL) || defined(CPU_MCXA275VLQ) || defined(CPU_MCXA275VPN))
#include "MCXA275_COMMON.h"
#elif (defined(CPU_MCXA276VLH) || defined(CPU_MCXA276VLL) || defined(CPU_MCXA276VLQ) || defined(CPU_MCXA276VPN))
#include "MCXA276_COMMON.h"
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
   -- FREQME Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FREQME_Peripheral_Access_Layer FREQME Peripheral Access Layer
 * @{
 */

/** FREQME - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __I  uint32_t CTRL_R;                            /**< Control (in Read mode), offset: 0x0 */
    __O  uint32_t CTRL_W;                            /**< Control (in Write mode), offset: 0x0 */
  };
  __IO uint32_t CTRLSTAT;                          /**< Control Status, offset: 0x4 */
  __IO uint32_t MIN;                               /**< Minimum, offset: 0x8 */
  __IO uint32_t MAX;                               /**< Maximum, offset: 0xC */
} FREQME_Type;

/* ----------------------------------------------------------------------------
   -- FREQME Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FREQME_Register_Masks FREQME Register Masks
 * @{
 */

/*! @name CTRL_R - Control (in Read mode) */
/*! @{ */

#define FREQME_CTRL_R_RESULT_MASK                (0x7FFFFFFFU)
#define FREQME_CTRL_R_RESULT_SHIFT               (0U)
#define FREQME_CTRL_R_RESULT(x)                  (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_R_RESULT_SHIFT)) & FREQME_CTRL_R_RESULT_MASK)

#define FREQME_CTRL_R_MEASURE_IN_PROGRESS_MASK   (0x80000000U)
#define FREQME_CTRL_R_MEASURE_IN_PROGRESS_SHIFT  (31U)
/*! MEASURE_IN_PROGRESS - Measurement In Progress
 *  0b0..Complete
 *  0b1..In progress
 */
#define FREQME_CTRL_R_MEASURE_IN_PROGRESS(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_R_MEASURE_IN_PROGRESS_SHIFT)) & FREQME_CTRL_R_MEASURE_IN_PROGRESS_MASK)
/*! @} */

/*! @name CTRL_W - Control (in Write mode) */
/*! @{ */

#define FREQME_CTRL_W_REF_SCALE_MASK             (0x1FU)
#define FREQME_CTRL_W_REF_SCALE_SHIFT            (0U)
/*! REF_SCALE - Reference Clock Scaling Factor */
#define FREQME_CTRL_W_REF_SCALE(x)               (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_REF_SCALE_SHIFT)) & FREQME_CTRL_W_REF_SCALE_MASK)

#define FREQME_CTRL_W_PULSE_MODE_MASK            (0x100U)
#define FREQME_CTRL_W_PULSE_MODE_SHIFT           (8U)
/*! PULSE_MODE - Pulse Width Measurement Mode Select
 *  0b0..Frequency Measurement mode
 *  0b1..Pulse Width Measurement mode
 */
#define FREQME_CTRL_W_PULSE_MODE(x)              (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_PULSE_MODE_SHIFT)) & FREQME_CTRL_W_PULSE_MODE_MASK)

#define FREQME_CTRL_W_PULSE_POL_MASK             (0x200U)
#define FREQME_CTRL_W_PULSE_POL_SHIFT            (9U)
/*! PULSE_POL - Pulse Polarity
 *  0b0..High period
 *  0b1..Low period
 */
#define FREQME_CTRL_W_PULSE_POL(x)               (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_PULSE_POL_SHIFT)) & FREQME_CTRL_W_PULSE_POL_MASK)

#define FREQME_CTRL_W_LT_MIN_INT_EN_MASK         (0x1000U)
#define FREQME_CTRL_W_LT_MIN_INT_EN_SHIFT        (12U)
/*! LT_MIN_INT_EN - Less Than Minimum Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_LT_MIN_INT_EN(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_LT_MIN_INT_EN_SHIFT)) & FREQME_CTRL_W_LT_MIN_INT_EN_MASK)

#define FREQME_CTRL_W_GT_MAX_INT_EN_MASK         (0x2000U)
#define FREQME_CTRL_W_GT_MAX_INT_EN_SHIFT        (13U)
/*! GT_MAX_INT_EN - Greater Than Maximum Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_GT_MAX_INT_EN(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_GT_MAX_INT_EN_SHIFT)) & FREQME_CTRL_W_GT_MAX_INT_EN_MASK)

#define FREQME_CTRL_W_RESULT_READY_INT_EN_MASK   (0x4000U)
#define FREQME_CTRL_W_RESULT_READY_INT_EN_SHIFT  (14U)
/*! RESULT_READY_INT_EN - Result Ready Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_RESULT_READY_INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_RESULT_READY_INT_EN_SHIFT)) & FREQME_CTRL_W_RESULT_READY_INT_EN_MASK)

#define FREQME_CTRL_W_CONTINUOUS_MODE_EN_MASK    (0x40000000U)
#define FREQME_CTRL_W_CONTINUOUS_MODE_EN_SHIFT   (30U)
/*! CONTINUOUS_MODE_EN - Continuous Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_CONTINUOUS_MODE_EN(x)      (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_CONTINUOUS_MODE_EN_SHIFT)) & FREQME_CTRL_W_CONTINUOUS_MODE_EN_MASK)

#define FREQME_CTRL_W_MEASURE_IN_PROGRESS_MASK   (0x80000000U)
#define FREQME_CTRL_W_MEASURE_IN_PROGRESS_SHIFT  (31U)
/*! MEASURE_IN_PROGRESS - Measurement In Progress
 *  0b0..Terminates measurement
 *  0b1..Initiates measurement
 */
#define FREQME_CTRL_W_MEASURE_IN_PROGRESS(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_MEASURE_IN_PROGRESS_SHIFT)) & FREQME_CTRL_W_MEASURE_IN_PROGRESS_MASK)
/*! @} */

/*! @name CTRLSTAT - Control Status */
/*! @{ */

#define FREQME_CTRLSTAT_REF_SCALE_MASK           (0x1FU)
#define FREQME_CTRLSTAT_REF_SCALE_SHIFT          (0U)
/*! REF_SCALE - Reference Scale */
#define FREQME_CTRLSTAT_REF_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_REF_SCALE_SHIFT)) & FREQME_CTRLSTAT_REF_SCALE_MASK)

#define FREQME_CTRLSTAT_PULSE_MODE_MASK          (0x100U)
#define FREQME_CTRLSTAT_PULSE_MODE_SHIFT         (8U)
/*! PULSE_MODE - Pulse Mode
 *  0b0..Frequency Measurement mode
 *  0b1..Pulse Width Measurement mode
 */
#define FREQME_CTRLSTAT_PULSE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_PULSE_MODE_SHIFT)) & FREQME_CTRLSTAT_PULSE_MODE_MASK)

#define FREQME_CTRLSTAT_PULSE_POL_MASK           (0x200U)
#define FREQME_CTRLSTAT_PULSE_POL_SHIFT          (9U)
/*! PULSE_POL - Pulse Polarity
 *  0b0..High period
 *  0b1..Low period
 */
#define FREQME_CTRLSTAT_PULSE_POL(x)             (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_PULSE_POL_SHIFT)) & FREQME_CTRLSTAT_PULSE_POL_MASK)

#define FREQME_CTRLSTAT_LT_MIN_INT_EN_MASK       (0x1000U)
#define FREQME_CTRLSTAT_LT_MIN_INT_EN_SHIFT      (12U)
/*! LT_MIN_INT_EN - Less Than Minimum Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_LT_MIN_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_LT_MIN_INT_EN_SHIFT)) & FREQME_CTRLSTAT_LT_MIN_INT_EN_MASK)

#define FREQME_CTRLSTAT_GT_MAX_INT_EN_MASK       (0x2000U)
#define FREQME_CTRLSTAT_GT_MAX_INT_EN_SHIFT      (13U)
/*! GT_MAX_INT_EN - Greater Than Maximum Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_GT_MAX_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_GT_MAX_INT_EN_SHIFT)) & FREQME_CTRLSTAT_GT_MAX_INT_EN_MASK)

#define FREQME_CTRLSTAT_RESULT_READY_INT_EN_MASK (0x4000U)
#define FREQME_CTRLSTAT_RESULT_READY_INT_EN_SHIFT (14U)
/*! RESULT_READY_INT_EN - Result Ready Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_RESULT_READY_INT_EN(x)   (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_RESULT_READY_INT_EN_SHIFT)) & FREQME_CTRLSTAT_RESULT_READY_INT_EN_MASK)

#define FREQME_CTRLSTAT_LT_MIN_STAT_MASK         (0x1000000U)
#define FREQME_CTRLSTAT_LT_MIN_STAT_SHIFT        (24U)
/*! LT_MIN_STAT - Less Than Minimum Results Status
 *  0b0..Greater than MIN[MIN_VALUE]
 *  0b1..Less than MIN[MIN_VALUE]
 */
#define FREQME_CTRLSTAT_LT_MIN_STAT(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_LT_MIN_STAT_SHIFT)) & FREQME_CTRLSTAT_LT_MIN_STAT_MASK)

#define FREQME_CTRLSTAT_GT_MAX_STAT_MASK         (0x2000000U)
#define FREQME_CTRLSTAT_GT_MAX_STAT_SHIFT        (25U)
/*! GT_MAX_STAT - Greater Than Maximum Result Status
 *  0b0..Less than MAX[MAX_VALUE]
 *  0b1..Greater than MAX[MAX_VALUE]
 */
#define FREQME_CTRLSTAT_GT_MAX_STAT(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_GT_MAX_STAT_SHIFT)) & FREQME_CTRLSTAT_GT_MAX_STAT_MASK)

#define FREQME_CTRLSTAT_RESULT_READY_STAT_MASK   (0x4000000U)
#define FREQME_CTRLSTAT_RESULT_READY_STAT_SHIFT  (26U)
/*! RESULT_READY_STAT - Result Ready Status
 *  0b0..Not complete
 *  0b1..Complete
 */
#define FREQME_CTRLSTAT_RESULT_READY_STAT(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_RESULT_READY_STAT_SHIFT)) & FREQME_CTRLSTAT_RESULT_READY_STAT_MASK)

#define FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_MASK  (0x40000000U)
#define FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_SHIFT (30U)
/*! CONTINUOUS_MODE_EN - Continuous Mode Enable Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_CONTINUOUS_MODE_EN(x)    (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_SHIFT)) & FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_MASK)

#define FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_MASK (0x80000000U)
#define FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_SHIFT (31U)
/*! MEASURE_IN_PROGRESS - Measurement in Progress Status
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define FREQME_CTRLSTAT_MEASURE_IN_PROGRESS(x)   (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_SHIFT)) & FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_MASK)
/*! @} */

/*! @name MIN - Minimum */
/*! @{ */

#define FREQME_MIN_MIN_VALUE_MASK                (0x7FFFFFFFU)
#define FREQME_MIN_MIN_VALUE_SHIFT               (0U)
/*! MIN_VALUE - Minimum Value */
#define FREQME_MIN_MIN_VALUE(x)                  (((uint32_t)(((uint32_t)(x)) << FREQME_MIN_MIN_VALUE_SHIFT)) & FREQME_MIN_MIN_VALUE_MASK)
/*! @} */

/*! @name MAX - Maximum */
/*! @{ */

#define FREQME_MAX_MAX_VALUE_MASK                (0x7FFFFFFFU)
#define FREQME_MAX_MAX_VALUE_SHIFT               (0U)
/*! MAX_VALUE - Maximum Value */
#define FREQME_MAX_MAX_VALUE(x)                  (((uint32_t)(((uint32_t)(x)) << FREQME_MAX_MAX_VALUE_SHIFT)) & FREQME_MAX_MAX_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FREQME_Register_Masks */


/*!
 * @}
 */ /* end of group FREQME_Peripheral_Access_Layer */


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


#endif  /* FREQME_H_ */

