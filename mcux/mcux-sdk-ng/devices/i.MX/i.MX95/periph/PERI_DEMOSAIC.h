/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DEMOSAIC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DEMOSAIC.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DEMOSAIC
 *
 * CMSIS Peripheral Access Layer for DEMOSAIC
 */

#if !defined(DEMOSAIC_H_)
#define DEMOSAIC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- DEMOSAIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEMOSAIC_Peripheral_Access_Layer DEMOSAIC Peripheral Access Layer
 * @{
 */

/** DEMOSAIC - Size of Registers Arrays */
#define DEMOSAIC_NEO_PIPE2_DEMOSAIC_CONF_COUNT    1u

/** DEMOSAIC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 Demosaic Control Register, array offset: 0x0, array step: 0x10 */
    __IO uint32_t ACTIVITY_CTL_CAM;                  /**< Camera 0 Demosaic Activity Control Register, array offset: 0x4, array step: 0x10 */
    __IO uint32_t DYNAMICS_CTL0_CAM;                 /**< Camera 0 Demosaic Dynamics Control 0 Register, array offset: 0x8, array step: 0x10 */
    __IO uint32_t DYNAMICS_CTL2_CAM;                 /**< Camera 0 Demosaic Dynamics Control 2 Register, array offset: 0xC, array step: 0x10 */
  } NEO_PIPE2_DEMOSAIC_CONF[DEMOSAIC_NEO_PIPE2_DEMOSAIC_CONF_COUNT];
} DEMOSAIC_Type;

/* ----------------------------------------------------------------------------
   -- DEMOSAIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEMOSAIC_Register_Masks DEMOSAIC Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 Demosaic Control Register */
/*! @{ */

#define DEMOSAIC_CTRL_CAM_FMT_MASK               (0x30U)
#define DEMOSAIC_CTRL_CAM_FMT_SHIFT              (4U)
/*! FMT
 *  0b00..Input image is RGGB Bayer image
 *  0b01..Input image is RCCC image
 *  0b10..Input image is Monochrome image
 */
#define DEMOSAIC_CTRL_CAM_FMT(x)                 (((uint32_t)(((uint32_t)(x)) << DEMOSAIC_CTRL_CAM_FMT_SHIFT)) & DEMOSAIC_CTRL_CAM_FMT_MASK)
/*! @} */

/* The count of DEMOSAIC_CTRL_CAM */
#define DEMOSAIC_CTRL_CAM_COUNT                  (1U)

/*! @name ACTIVITY_CTL_CAM - Camera 0 Demosaic Activity Control Register */
/*! @{ */

#define DEMOSAIC_ACTIVITY_CTL_CAM_ALPHA_MASK     (0x1FFU)
#define DEMOSAIC_ACTIVITY_CTL_CAM_ALPHA_SHIFT    (0U)
/*! ALPHA - Blending factor between block (0) and color (256) activity. */
#define DEMOSAIC_ACTIVITY_CTL_CAM_ALPHA(x)       (((uint32_t)(((uint32_t)(x)) << DEMOSAIC_ACTIVITY_CTL_CAM_ALPHA_SHIFT)) & DEMOSAIC_ACTIVITY_CTL_CAM_ALPHA_MASK)

#define DEMOSAIC_ACTIVITY_CTL_CAM_ACT_RATIO_MASK (0xFFFF0000U)
#define DEMOSAIC_ACTIVITY_CTL_CAM_ACT_RATIO_SHIFT (16U)
/*! ACT_RATIO - Ratio from minimum activity to activity of direction for selecting the respective
 *    green value of that direction for interpolation.
 */
#define DEMOSAIC_ACTIVITY_CTL_CAM_ACT_RATIO(x)   (((uint32_t)(((uint32_t)(x)) << DEMOSAIC_ACTIVITY_CTL_CAM_ACT_RATIO_SHIFT)) & DEMOSAIC_ACTIVITY_CTL_CAM_ACT_RATIO_MASK)
/*! @} */

/* The count of DEMOSAIC_ACTIVITY_CTL_CAM */
#define DEMOSAIC_ACTIVITY_CTL_CAM_COUNT          (1U)

/*! @name DYNAMICS_CTL0_CAM - Camera 0 Demosaic Dynamics Control 0 Register */
/*! @{ */

#define DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHG_MASK (0xFFFFU)
#define DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHG_SHIFT (0U)
#define DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHG(x)  (((uint32_t)(((uint32_t)(x)) << DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHG_SHIFT)) & DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHG_MASK)

#define DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHC_MASK (0xFFFF0000U)
#define DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHC_SHIFT (16U)
#define DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHC(x)  (((uint32_t)(((uint32_t)(x)) << DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHC_SHIFT)) & DEMOSAIC_DYNAMICS_CTL0_CAM_STRENGTHC_MASK)
/*! @} */

/* The count of DEMOSAIC_DYNAMICS_CTL0_CAM */
#define DEMOSAIC_DYNAMICS_CTL0_CAM_COUNT         (1U)

/*! @name DYNAMICS_CTL2_CAM - Camera 0 Demosaic Dynamics Control 2 Register */
/*! @{ */

#define DEMOSAIC_DYNAMICS_CTL2_CAM_MAX_IMPACT_MASK (0xFFFFU)
#define DEMOSAIC_DYNAMICS_CTL2_CAM_MAX_IMPACT_SHIFT (0U)
#define DEMOSAIC_DYNAMICS_CTL2_CAM_MAX_IMPACT(x) (((uint32_t)(((uint32_t)(x)) << DEMOSAIC_DYNAMICS_CTL2_CAM_MAX_IMPACT_SHIFT)) & DEMOSAIC_DYNAMICS_CTL2_CAM_MAX_IMPACT_MASK)
/*! @} */

/* The count of DEMOSAIC_DYNAMICS_CTL2_CAM */
#define DEMOSAIC_DYNAMICS_CTL2_CAM_COUNT         (1U)


/*!
 * @}
 */ /* end of group DEMOSAIC_Register_Masks */


/*!
 * @}
 */ /* end of group DEMOSAIC_Peripheral_Access_Layer */


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


#endif  /* DEMOSAIC_H_ */

