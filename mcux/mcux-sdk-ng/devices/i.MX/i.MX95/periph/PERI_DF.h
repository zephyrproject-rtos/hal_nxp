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
**         CMSIS Peripheral Access Layer for DF
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
 * @file DF.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DF
 *
 * CMSIS Peripheral Access Layer for DF
 */

#if !defined(DF_H_)
#define DF_H_                                    /**< Symbol preventing repeated inclusion */

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
   -- DF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DF_Peripheral_Access_Layer DF Peripheral Access Layer
 * @{
 */

/** DF - Size of Registers Arrays */
#define DF_NEO_PIPE2_DF_CONF_COUNT                1u

/** DF - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x14 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 DF Control Register, array offset: 0x0, array step: 0x14 */
    __IO uint32_t TH_SCALE_CAM;                      /**< Camera 0 DF Blending Scale Register, array offset: 0x4, array step: 0x14 */
    __IO uint32_t BLEND_SHIFT_CAM;                   /**< Camera 0 DF Blending Shift Register, array offset: 0x8, array step: 0x14 */
    __IO uint32_t BLEND_TH0_CAM;                     /**< Camera 0 DF Blend Threshold 0 Register, array offset: 0xC, array step: 0x14 */
    __I  uint32_t EDGECNT_CAM;                       /**< Camera 0 DF Edge Count Register, array offset: 0x10, array step: 0x14 */
  } NEO_PIPE2_DF_CONF[DF_NEO_PIPE2_DF_CONF_COUNT];
} DF_Type;

/* ----------------------------------------------------------------------------
   -- DF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DF_Register_Masks DF Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 DF Control Register */
/*! @{ */

#define DF_CTRL_CAM_DEBUG_MASK                   (0x700U)
#define DF_CTRL_CAM_DEBUG_SHIFT                  (8U)
/*! DEBUG - Debug / Tuning view
 *  0b000..off
 *  0b001..filtered+texture
 *  0b010..filtered+white
 *  0b011..horizontal filtered + white
 *  0b100..vertical filtered + white
 *  0b101..diagonal1 filtered + white
 *  0b110..diagonal2 filtered + white
 */
#define DF_CTRL_CAM_DEBUG(x)                     (((uint32_t)(((uint32_t)(x)) << DF_CTRL_CAM_DEBUG_SHIFT)) & DF_CTRL_CAM_DEBUG_MASK)

#define DF_CTRL_CAM_ENABLE_MASK                  (0x80000000U)
#define DF_CTRL_CAM_ENABLE_SHIFT                 (31U)
/*! ENABLE
 *  0b0..off
 *  0b1..on
 */
#define DF_CTRL_CAM_ENABLE(x)                    (((uint32_t)(((uint32_t)(x)) << DF_CTRL_CAM_ENABLE_SHIFT)) & DF_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of DF_CTRL_CAM */
#define DF_CTRL_CAM_COUNT                        (1U)

/*! @name TH_SCALE_CAM - Camera 0 DF Blending Scale Register */
/*! @{ */

#define DF_TH_SCALE_CAM_SCALE_MASK               (0xFFFFFU)
#define DF_TH_SCALE_CAM_SCALE_SHIFT              (0U)
#define DF_TH_SCALE_CAM_SCALE(x)                 (((uint32_t)(((uint32_t)(x)) << DF_TH_SCALE_CAM_SCALE_SHIFT)) & DF_TH_SCALE_CAM_SCALE_MASK)
/*! @} */

/* The count of DF_TH_SCALE_CAM */
#define DF_TH_SCALE_CAM_COUNT                    (1U)

/*! @name BLEND_SHIFT_CAM - Camera 0 DF Blending Shift Register */
/*! @{ */

#define DF_BLEND_SHIFT_CAM_SHIFT_MASK            (0x3FU)
#define DF_BLEND_SHIFT_CAM_SHIFT_SHIFT           (0U)
#define DF_BLEND_SHIFT_CAM_SHIFT(x)              (((uint32_t)(((uint32_t)(x)) << DF_BLEND_SHIFT_CAM_SHIFT_SHIFT)) & DF_BLEND_SHIFT_CAM_SHIFT_MASK)
/*! @} */

/* The count of DF_BLEND_SHIFT_CAM */
#define DF_BLEND_SHIFT_CAM_COUNT                 (1U)

/*! @name BLEND_TH0_CAM - Camera 0 DF Blend Threshold 0 Register */
/*! @{ */

#define DF_BLEND_TH0_CAM_TH_MASK                 (0xFFFFFU)
#define DF_BLEND_TH0_CAM_TH_SHIFT                (0U)
#define DF_BLEND_TH0_CAM_TH(x)                   (((uint32_t)(((uint32_t)(x)) << DF_BLEND_TH0_CAM_TH_SHIFT)) & DF_BLEND_TH0_CAM_TH_MASK)
/*! @} */

/* The count of DF_BLEND_TH0_CAM */
#define DF_BLEND_TH0_CAM_COUNT                   (1U)

/*! @name EDGECNT_CAM - Camera 0 DF Edge Count Register */
/*! @{ */

#define DF_EDGECNT_CAM_EDGE_PIXELS_MASK          (0xFFFFFFU)
#define DF_EDGECNT_CAM_EDGE_PIXELS_SHIFT         (0U)
#define DF_EDGECNT_CAM_EDGE_PIXELS(x)            (((uint32_t)(((uint32_t)(x)) << DF_EDGECNT_CAM_EDGE_PIXELS_SHIFT)) & DF_EDGECNT_CAM_EDGE_PIXELS_MASK)
/*! @} */

/* The count of DF_EDGECNT_CAM */
#define DF_EDGECNT_CAM_COUNT                     (1U)


/*!
 * @}
 */ /* end of group DF_Register_Masks */


/*!
 * @}
 */ /* end of group DF_Peripheral_Access_Layer */


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


#endif  /* DF_H_ */

