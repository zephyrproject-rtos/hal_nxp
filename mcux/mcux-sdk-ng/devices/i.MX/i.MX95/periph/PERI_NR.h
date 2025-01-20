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
**         CMSIS Peripheral Access Layer for NR
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
 * @file NR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NR
 *
 * CMSIS Peripheral Access Layer for NR
 */

#if !defined(NR_H_)
#define NR_H_                                    /**< Symbol preventing repeated inclusion */

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
   -- NR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NR_Peripheral_Access_Layer NR Peripheral Access Layer
 * @{
 */

/** NR - Size of Registers Arrays */
#define NR_NEO_PIPE2_NR_CONF_COUNT                1u

/** NR - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x14 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 NR Control Register, array offset: 0x0, array step: 0x14 */
    __IO uint32_t BLEND_SCALE_CAM;                   /**< Camera 0 NR Blending Scale Register, array offset: 0x4, array step: 0x14 */
    __IO uint32_t BLEND_TH0_CAM;                     /**< Camera 0 NR Blend Threshold 0 Register, array offset: 0x8, array step: 0x14 */
         uint8_t RESERVED_0[4];
    __I  uint32_t EDGECNT_CAM;                       /**< Camera 0 NR Edge Count Register, array offset: 0x10, array step: 0x14 */
  } NEO_PIPE2_NR_CONF[NR_NEO_PIPE2_NR_CONF_COUNT];
} NR_Type;

/* ----------------------------------------------------------------------------
   -- NR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NR_Register_Masks NR Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 NR Control Register */
/*! @{ */

#define NR_CTRL_CAM_DEBUG_MASK                   (0x300U)
#define NR_CTRL_CAM_DEBUG_SHIFT                  (8U)
/*! DEBUG - Debug / Tuning view
 *  0b00..off
 *  0b01..non-filtered+texture
 *  0b10..non-filtered+black
 */
#define NR_CTRL_CAM_DEBUG(x)                     (((uint32_t)(((uint32_t)(x)) << NR_CTRL_CAM_DEBUG_SHIFT)) & NR_CTRL_CAM_DEBUG_MASK)

#define NR_CTRL_CAM_ENABLE_MASK                  (0x80000000U)
#define NR_CTRL_CAM_ENABLE_SHIFT                 (31U)
/*! ENABLE
 *  0b0..off
 *  0b1..on
 */
#define NR_CTRL_CAM_ENABLE(x)                    (((uint32_t)(((uint32_t)(x)) << NR_CTRL_CAM_ENABLE_SHIFT)) & NR_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of NR_CTRL_CAM */
#define NR_CTRL_CAM_COUNT                        (1U)

/*! @name BLEND_SCALE_CAM - Camera 0 NR Blending Scale Register */
/*! @{ */

#define NR_BLEND_SCALE_CAM_SCALE_MASK            (0xFFFFU)
#define NR_BLEND_SCALE_CAM_SCALE_SHIFT           (0U)
#define NR_BLEND_SCALE_CAM_SCALE(x)              (((uint32_t)(((uint32_t)(x)) << NR_BLEND_SCALE_CAM_SCALE_SHIFT)) & NR_BLEND_SCALE_CAM_SCALE_MASK)

#define NR_BLEND_SCALE_CAM_SHIFT_MASK            (0xFF0000U)
#define NR_BLEND_SCALE_CAM_SHIFT_SHIFT           (16U)
#define NR_BLEND_SCALE_CAM_SHIFT(x)              (((uint32_t)(((uint32_t)(x)) << NR_BLEND_SCALE_CAM_SHIFT_SHIFT)) & NR_BLEND_SCALE_CAM_SHIFT_MASK)

#define NR_BLEND_SCALE_CAM_GAIN_MASK             (0xFF000000U)
#define NR_BLEND_SCALE_CAM_GAIN_SHIFT            (24U)
#define NR_BLEND_SCALE_CAM_GAIN(x)               (((uint32_t)(((uint32_t)(x)) << NR_BLEND_SCALE_CAM_GAIN_SHIFT)) & NR_BLEND_SCALE_CAM_GAIN_MASK)
/*! @} */

/* The count of NR_BLEND_SCALE_CAM */
#define NR_BLEND_SCALE_CAM_COUNT                 (1U)

/*! @name BLEND_TH0_CAM - Camera 0 NR Blend Threshold 0 Register */
/*! @{ */

#define NR_BLEND_TH0_CAM_TH_MASK                 (0xFFFFFU)
#define NR_BLEND_TH0_CAM_TH_SHIFT                (0U)
#define NR_BLEND_TH0_CAM_TH(x)                   (((uint32_t)(((uint32_t)(x)) << NR_BLEND_TH0_CAM_TH_SHIFT)) & NR_BLEND_TH0_CAM_TH_MASK)
/*! @} */

/* The count of NR_BLEND_TH0_CAM */
#define NR_BLEND_TH0_CAM_COUNT                   (1U)

/*! @name EDGECNT_CAM - Camera 0 NR Edge Count Register */
/*! @{ */

#define NR_EDGECNT_CAM_EDGE_PIXELS_MASK          (0xFFFFFFU)
#define NR_EDGECNT_CAM_EDGE_PIXELS_SHIFT         (0U)
#define NR_EDGECNT_CAM_EDGE_PIXELS(x)            (((uint32_t)(((uint32_t)(x)) << NR_EDGECNT_CAM_EDGE_PIXELS_SHIFT)) & NR_EDGECNT_CAM_EDGE_PIXELS_MASK)
/*! @} */

/* The count of NR_EDGECNT_CAM */
#define NR_EDGECNT_CAM_COUNT                     (1U)


/*!
 * @}
 */ /* end of group NR_Register_Masks */


/*!
 * @}
 */ /* end of group NR_Peripheral_Access_Layer */


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


#endif  /* NR_H_ */

