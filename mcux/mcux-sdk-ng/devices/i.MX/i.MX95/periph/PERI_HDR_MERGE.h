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
**         CMSIS Peripheral Access Layer for HDR_MERGE
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
 * @file HDR_MERGE.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for HDR_MERGE
 *
 * CMSIS Peripheral Access Layer for HDR_MERGE
 */

#if !defined(HDR_MERGE_H_)
#define HDR_MERGE_H_                             /**< Symbol preventing repeated inclusion */

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
   -- HDR_MERGE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDR_MERGE_Peripheral_Access_Layer HDR_MERGE Peripheral Access Layer
 * @{
 */

/** HDR_MERGE - Size of Registers Arrays */
#define HDR_MERGE_NEO_PIPE1_HDR_MERGE_CONF_COUNT  1u

/** HDR_MERGE - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x24 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 HDR Merge Control Register, array offset: 0x0, array step: 0x24 */
    __IO uint32_t GAIN_OFFSET_CAM;                   /**< Camera 0 HDR Merge Gain Offset Register, array offset: 0x4, array step: 0x24 */
    __IO uint32_t GAIN_SCALE_CAM;                    /**< Camera 0 HDR Merge Gain Scale Register, array offset: 0x8, array step: 0x24 */
    __IO uint32_t GAIN_SHIFT_CAM;                    /**< Camera 0 HDR Merge Gain Shift Register, array offset: 0xC, array step: 0x24 */
    __IO uint32_t LUMA_TH_CAM;                       /**< Camera 0 HDR Merge Luma Threshold Register, array offset: 0x10, array step: 0x24 */
    __IO uint32_t LUMA_SCALE_CAM;                    /**< Camera 0 HDR Merge Luma Scale Register, array offset: 0x14, array step: 0x24 */
    __IO uint32_t DOWNSCALE_CAM;                     /**< Camera 0 HDR Merge Down Scale Register, array offset: 0x18, array step: 0x24 */
    __IO uint32_t UPSCALE_CAM;                       /**< Camera 0 HDR Merge Up Scale Register, array offset: 0x1C, array step: 0x24 */
    __IO uint32_t POST_SCALE_CAM;                    /**< Camera 0 HDR Merge Post Scale Register, array offset: 0x20, array step: 0x24 */
  } NEO_PIPE1_HDR_MERGE_CONF[HDR_MERGE_NEO_PIPE1_HDR_MERGE_CONF_COUNT];
} HDR_MERGE_Type;

/* ----------------------------------------------------------------------------
   -- HDR_MERGE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDR_MERGE_Register_Masks HDR_MERGE Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 HDR Merge Control Register */
/*! @{ */

#define HDR_MERGE_CTRL_CAM_OBPP_MASK             (0xCU)
#define HDR_MERGE_CTRL_CAM_OBPP_SHIFT            (2U)
/*! OBPP
 *  0b00..12 bpp
 *  0b01..14 bpp
 *  0b10..16 bpp
 *  0b11..20 bpp
 */
#define HDR_MERGE_CTRL_CAM_OBPP(x)               (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_OBPP_SHIFT)) & HDR_MERGE_CTRL_CAM_OBPP_MASK)

#define HDR_MERGE_CTRL_CAM_SAFETY_ON_MASK        (0x10U)
#define HDR_MERGE_CTRL_CAM_SAFETY_ON_SHIFT       (4U)
/*! SAFETY_ON
 *  0b0..Off
 *  0b1..On
 */
#define HDR_MERGE_CTRL_CAM_SAFETY_ON(x)          (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_SAFETY_ON_SHIFT)) & HDR_MERGE_CTRL_CAM_SAFETY_ON_MASK)

#define HDR_MERGE_CTRL_CAM_MOTION_FIX_EN_MASK    (0x100U)
#define HDR_MERGE_CTRL_CAM_MOTION_FIX_EN_SHIFT   (8U)
/*! MOTION_FIX_EN - Enable fixing of HDR artifacts due to motion
 *  0b0..Off
 *  0b1..On
 */
#define HDR_MERGE_CTRL_CAM_MOTION_FIX_EN(x)      (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_MOTION_FIX_EN_SHIFT)) & HDR_MERGE_CTRL_CAM_MOTION_FIX_EN_MASK)

#define HDR_MERGE_CTRL_CAM_BLEND_3X3_MASK        (0x200U)
#define HDR_MERGE_CTRL_CAM_BLEND_3X3_SHIFT       (9U)
/*! BLEND_3X3 - Selects the HDR blending mode
 *  0b0..1x1
 *  0b1..3x3
 */
#define HDR_MERGE_CTRL_CAM_BLEND_3X3(x)          (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_BLEND_3X3_SHIFT)) & HDR_MERGE_CTRL_CAM_BLEND_3X3_MASK)

#define HDR_MERGE_CTRL_CAM_GAIN0BPP_MASK         (0x30000U)
#define HDR_MERGE_CTRL_CAM_GAIN0BPP_SHIFT        (16U)
/*! GAIN0BPP
 *  0b00..12 bpp
 *  0b01..14 bpp
 *  0b10..16 bpp
 *  0b11..20 bpp
 */
#define HDR_MERGE_CTRL_CAM_GAIN0BPP(x)           (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_GAIN0BPP_SHIFT)) & HDR_MERGE_CTRL_CAM_GAIN0BPP_MASK)

#define HDR_MERGE_CTRL_CAM_GAIN1BPP_MASK         (0xC0000U)
#define HDR_MERGE_CTRL_CAM_GAIN1BPP_SHIFT        (18U)
/*! GAIN1BPP
 *  0b00..12 bpp
 *  0b01..14 bpp
 *  0b10..16 bpp
 *  0b11..20 bpp
 */
#define HDR_MERGE_CTRL_CAM_GAIN1BPP(x)           (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_GAIN1BPP_SHIFT)) & HDR_MERGE_CTRL_CAM_GAIN1BPP_MASK)

#define HDR_MERGE_CTRL_CAM_ENABLE_MASK           (0x80000000U)
#define HDR_MERGE_CTRL_CAM_ENABLE_SHIFT          (31U)
/*! ENABLE - HDR Enable
 *  0b0..off
 *  0b1..on
 */
#define HDR_MERGE_CTRL_CAM_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_CTRL_CAM_ENABLE_SHIFT)) & HDR_MERGE_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of HDR_MERGE_CTRL_CAM */
#define HDR_MERGE_CTRL_CAM_COUNT                 (1U)

/*! @name GAIN_OFFSET_CAM - Camera 0 HDR Merge Gain Offset Register */
/*! @{ */

#define HDR_MERGE_GAIN_OFFSET_CAM_OFFSET0_MASK   (0xFFFFU)
#define HDR_MERGE_GAIN_OFFSET_CAM_OFFSET0_SHIFT  (0U)
#define HDR_MERGE_GAIN_OFFSET_CAM_OFFSET0(x)     (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_GAIN_OFFSET_CAM_OFFSET0_SHIFT)) & HDR_MERGE_GAIN_OFFSET_CAM_OFFSET0_MASK)

#define HDR_MERGE_GAIN_OFFSET_CAM_OFFSET1_MASK   (0xFFFF0000U)
#define HDR_MERGE_GAIN_OFFSET_CAM_OFFSET1_SHIFT  (16U)
#define HDR_MERGE_GAIN_OFFSET_CAM_OFFSET1(x)     (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_GAIN_OFFSET_CAM_OFFSET1_SHIFT)) & HDR_MERGE_GAIN_OFFSET_CAM_OFFSET1_MASK)
/*! @} */

/* The count of HDR_MERGE_GAIN_OFFSET_CAM */
#define HDR_MERGE_GAIN_OFFSET_CAM_COUNT          (1U)

/*! @name GAIN_SCALE_CAM - Camera 0 HDR Merge Gain Scale Register */
/*! @{ */

#define HDR_MERGE_GAIN_SCALE_CAM_SCALE0_MASK     (0xFFFFU)
#define HDR_MERGE_GAIN_SCALE_CAM_SCALE0_SHIFT    (0U)
#define HDR_MERGE_GAIN_SCALE_CAM_SCALE0(x)       (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_GAIN_SCALE_CAM_SCALE0_SHIFT)) & HDR_MERGE_GAIN_SCALE_CAM_SCALE0_MASK)

#define HDR_MERGE_GAIN_SCALE_CAM_SCALE1_MASK     (0xFFFF0000U)
#define HDR_MERGE_GAIN_SCALE_CAM_SCALE1_SHIFT    (16U)
#define HDR_MERGE_GAIN_SCALE_CAM_SCALE1(x)       (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_GAIN_SCALE_CAM_SCALE1_SHIFT)) & HDR_MERGE_GAIN_SCALE_CAM_SCALE1_MASK)
/*! @} */

/* The count of HDR_MERGE_GAIN_SCALE_CAM */
#define HDR_MERGE_GAIN_SCALE_CAM_COUNT           (1U)

/*! @name GAIN_SHIFT_CAM - Camera 0 HDR Merge Gain Shift Register */
/*! @{ */

#define HDR_MERGE_GAIN_SHIFT_CAM_SHIFT0_MASK     (0x1FU)
#define HDR_MERGE_GAIN_SHIFT_CAM_SHIFT0_SHIFT    (0U)
#define HDR_MERGE_GAIN_SHIFT_CAM_SHIFT0(x)       (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_GAIN_SHIFT_CAM_SHIFT0_SHIFT)) & HDR_MERGE_GAIN_SHIFT_CAM_SHIFT0_MASK)

#define HDR_MERGE_GAIN_SHIFT_CAM_SHIFT1_MASK     (0x1F0000U)
#define HDR_MERGE_GAIN_SHIFT_CAM_SHIFT1_SHIFT    (16U)
#define HDR_MERGE_GAIN_SHIFT_CAM_SHIFT1(x)       (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_GAIN_SHIFT_CAM_SHIFT1_SHIFT)) & HDR_MERGE_GAIN_SHIFT_CAM_SHIFT1_MASK)
/*! @} */

/* The count of HDR_MERGE_GAIN_SHIFT_CAM */
#define HDR_MERGE_GAIN_SHIFT_CAM_COUNT           (1U)

/*! @name LUMA_TH_CAM - Camera 0 HDR Merge Luma Threshold Register */
/*! @{ */

#define HDR_MERGE_LUMA_TH_CAM_TH0_MASK           (0xFFFFU)
#define HDR_MERGE_LUMA_TH_CAM_TH0_SHIFT          (0U)
#define HDR_MERGE_LUMA_TH_CAM_TH0(x)             (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_LUMA_TH_CAM_TH0_SHIFT)) & HDR_MERGE_LUMA_TH_CAM_TH0_MASK)
/*! @} */

/* The count of HDR_MERGE_LUMA_TH_CAM */
#define HDR_MERGE_LUMA_TH_CAM_COUNT              (1U)

/*! @name LUMA_SCALE_CAM - Camera 0 HDR Merge Luma Scale Register */
/*! @{ */

#define HDR_MERGE_LUMA_SCALE_CAM_SCALE_MASK      (0xFFFFU)
#define HDR_MERGE_LUMA_SCALE_CAM_SCALE_SHIFT     (0U)
#define HDR_MERGE_LUMA_SCALE_CAM_SCALE(x)        (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_LUMA_SCALE_CAM_SCALE_SHIFT)) & HDR_MERGE_LUMA_SCALE_CAM_SCALE_MASK)

#define HDR_MERGE_LUMA_SCALE_CAM_SHIFT_MASK      (0x1F0000U)
#define HDR_MERGE_LUMA_SCALE_CAM_SHIFT_SHIFT     (16U)
#define HDR_MERGE_LUMA_SCALE_CAM_SHIFT(x)        (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_LUMA_SCALE_CAM_SHIFT_SHIFT)) & HDR_MERGE_LUMA_SCALE_CAM_SHIFT_MASK)

#define HDR_MERGE_LUMA_SCALE_CAM_THSHIFT_MASK    (0x1F000000U)
#define HDR_MERGE_LUMA_SCALE_CAM_THSHIFT_SHIFT   (24U)
#define HDR_MERGE_LUMA_SCALE_CAM_THSHIFT(x)      (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_LUMA_SCALE_CAM_THSHIFT_SHIFT)) & HDR_MERGE_LUMA_SCALE_CAM_THSHIFT_MASK)
/*! @} */

/* The count of HDR_MERGE_LUMA_SCALE_CAM */
#define HDR_MERGE_LUMA_SCALE_CAM_COUNT           (1U)

/*! @name DOWNSCALE_CAM - Camera 0 HDR Merge Down Scale Register */
/*! @{ */

#define HDR_MERGE_DOWNSCALE_CAM_IMGSCALE0_MASK   (0x1FU)
#define HDR_MERGE_DOWNSCALE_CAM_IMGSCALE0_SHIFT  (0U)
#define HDR_MERGE_DOWNSCALE_CAM_IMGSCALE0(x)     (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_DOWNSCALE_CAM_IMGSCALE0_SHIFT)) & HDR_MERGE_DOWNSCALE_CAM_IMGSCALE0_MASK)

#define HDR_MERGE_DOWNSCALE_CAM_IMGSCALE1_MASK   (0x1F0000U)
#define HDR_MERGE_DOWNSCALE_CAM_IMGSCALE1_SHIFT  (16U)
#define HDR_MERGE_DOWNSCALE_CAM_IMGSCALE1(x)     (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_DOWNSCALE_CAM_IMGSCALE1_SHIFT)) & HDR_MERGE_DOWNSCALE_CAM_IMGSCALE1_MASK)
/*! @} */

/* The count of HDR_MERGE_DOWNSCALE_CAM */
#define HDR_MERGE_DOWNSCALE_CAM_COUNT            (1U)

/*! @name UPSCALE_CAM - Camera 0 HDR Merge Up Scale Register */
/*! @{ */

#define HDR_MERGE_UPSCALE_CAM_IMGSCALE0_MASK     (0xFU)
#define HDR_MERGE_UPSCALE_CAM_IMGSCALE0_SHIFT    (0U)
#define HDR_MERGE_UPSCALE_CAM_IMGSCALE0(x)       (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_UPSCALE_CAM_IMGSCALE0_SHIFT)) & HDR_MERGE_UPSCALE_CAM_IMGSCALE0_MASK)

#define HDR_MERGE_UPSCALE_CAM_IMGSCALE1_MASK     (0xF0000U)
#define HDR_MERGE_UPSCALE_CAM_IMGSCALE1_SHIFT    (16U)
#define HDR_MERGE_UPSCALE_CAM_IMGSCALE1(x)       (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_UPSCALE_CAM_IMGSCALE1_SHIFT)) & HDR_MERGE_UPSCALE_CAM_IMGSCALE1_MASK)
/*! @} */

/* The count of HDR_MERGE_UPSCALE_CAM */
#define HDR_MERGE_UPSCALE_CAM_COUNT              (1U)

/*! @name POST_SCALE_CAM - Camera 0 HDR Merge Post Scale Register */
/*! @{ */

#define HDR_MERGE_POST_SCALE_CAM_SCALE_MASK      (0x1FU)
#define HDR_MERGE_POST_SCALE_CAM_SCALE_SHIFT     (0U)
#define HDR_MERGE_POST_SCALE_CAM_SCALE(x)        (((uint32_t)(((uint32_t)(x)) << HDR_MERGE_POST_SCALE_CAM_SCALE_SHIFT)) & HDR_MERGE_POST_SCALE_CAM_SCALE_MASK)
/*! @} */

/* The count of HDR_MERGE_POST_SCALE_CAM */
#define HDR_MERGE_POST_SCALE_CAM_COUNT           (1U)


/*!
 * @}
 */ /* end of group HDR_MERGE_Register_Masks */


/*!
 * @}
 */ /* end of group HDR_MERGE_Peripheral_Access_Layer */


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


#endif  /* HDR_MERGE_H_ */

