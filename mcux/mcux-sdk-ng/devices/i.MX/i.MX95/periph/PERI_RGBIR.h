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
**         CMSIS Peripheral Access Layer for RGBIR
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
 * @file RGBIR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for RGBIR
 *
 * CMSIS Peripheral Access Layer for RGBIR
 */

#if !defined(RGBIR_H_)
#define RGBIR_H_                                 /**< Symbol preventing repeated inclusion */

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
   -- RGBIR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RGBIR_Peripheral_Access_Layer RGBIR Peripheral Access Layer
 * @{
 */

/** RGBIR - Size of Registers Arrays */
#define RGBIR_NEO_PIPE1_RGBIR_CONF_HIST_COUNT     2u
#define RGBIR_NEO_PIPE1_RGBIR_CONF_COUNT          1u

/** RGBIR - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x40 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 RGBIR Control Register, array offset: 0x0, array step: 0x40 */
    __IO uint32_t CCM0_CAM;                          /**< Camera 0 Color 0 Correction Register, array offset: 0x4, array step: 0x40 */
    __IO uint32_t CCM1_CAM;                          /**< Camera 0 Color 1/2 Correction Register, array offset: 0x8, array step: 0x40 */
    __IO uint32_t CCM2_CAM;                          /**< Camera 0 Color 2 Correction Register, array offset: 0xC, array step: 0x40 */
    __IO uint32_t CCM0_TH_CAM;                       /**< Camera 0 channel 3 (IR) to channel 0 (Red) Crosstalk Threshold Register, array offset: 0x10, array step: 0x40 */
    __IO uint32_t CCM1_TH_CAM;                       /**< Camera 0 channel 3 (IR) to channel 1 (Green) Crosstalk Threshold Register, array offset: 0x14, array step: 0x40 */
    __IO uint32_t CCM2_TH_CAM;                       /**< Camera 0 channel 3 (IR) to channel 2 (Blue) Crosstalk Threshold Register, array offset: 0x18, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t ROI0_POS_CAM;                      /**< Camera 0 Statistics Region of Interest 0 Position Register, array offset: 0x20, array step: 0x40 */
    __IO uint32_t ROI0_SIZE_CAM;                     /**< Camera 0 Statistics Region of Interest 0 Size Register, array offset: 0x24, array step: 0x40 */
    __IO uint32_t ROI1_POS_CAM;                      /**< Camera 0 Statistics Region of Interest 1 Position Register, array offset: 0x28, array step: 0x40 */
    __IO uint32_t ROI1_SIZE_CAM;                     /**< Camera 0 Statistics Region of Interest 1 Size Register, array offset: 0x2C, array step: 0x40 */
    struct {                                         /* offset: 0x30, array step: index*0x40, index2*0x8 */
      __IO uint32_t CTRL_CAM;                          /**< Camera 0 RGBIR Histogram 0 Control Register..Camera 0 RGBIR Histogram 1 Control Register, array offset: 0x30, array step: index*0x40, index2*0x8 */
      __IO uint32_t SCALE_CAM;                         /**< Camera 0 RGBIR Histogram 0 Scale Register..Camera 0 RGBIR Histogram 1 Scale Register, array offset: 0x34, array step: index*0x40, index2*0x8 */
    } HIST[RGBIR_NEO_PIPE1_RGBIR_CONF_HIST_COUNT];
  } NEO_PIPE1_RGBIR_CONF[RGBIR_NEO_PIPE1_RGBIR_CONF_COUNT];
} RGBIR_Type;

/* ----------------------------------------------------------------------------
   -- RGBIR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RGBIR_Register_Masks RGBIR Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 RGBIR Control Register */
/*! @{ */

#define RGBIR_CTRL_CAM_ENABLE_MASK               (0x80000000U)
#define RGBIR_CTRL_CAM_ENABLE_SHIFT              (31U)
/*! ENABLE
 *  0b0..Disabled, RGBIR output is same format is input
 *  0b1..Enabled
 */
#define RGBIR_CTRL_CAM_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << RGBIR_CTRL_CAM_ENABLE_SHIFT)) & RGBIR_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of RGBIR_CTRL_CAM */
#define RGBIR_CTRL_CAM_COUNT                     (1U)

/*! @name CCM0_CAM - Camera 0 Color 0 Correction Register */
/*! @{ */

#define RGBIR_CCM0_CAM_CCM_MASK                  (0xFFFFU)
#define RGBIR_CCM0_CAM_CCM_SHIFT                 (0U)
#define RGBIR_CCM0_CAM_CCM(x)                    (((uint32_t)(((uint32_t)(x)) << RGBIR_CCM0_CAM_CCM_SHIFT)) & RGBIR_CCM0_CAM_CCM_MASK)
/*! @} */

/* The count of RGBIR_CCM0_CAM */
#define RGBIR_CCM0_CAM_COUNT                     (1U)

/*! @name CCM1_CAM - Camera 0 Color 1/2 Correction Register */
/*! @{ */

#define RGBIR_CCM1_CAM_CCM_MASK                  (0xFFFFU)
#define RGBIR_CCM1_CAM_CCM_SHIFT                 (0U)
#define RGBIR_CCM1_CAM_CCM(x)                    (((uint32_t)(((uint32_t)(x)) << RGBIR_CCM1_CAM_CCM_SHIFT)) & RGBIR_CCM1_CAM_CCM_MASK)
/*! @} */

/* The count of RGBIR_CCM1_CAM */
#define RGBIR_CCM1_CAM_COUNT                     (1U)

/*! @name CCM2_CAM - Camera 0 Color 2 Correction Register */
/*! @{ */

#define RGBIR_CCM2_CAM_CCM_MASK                  (0xFFFFU)
#define RGBIR_CCM2_CAM_CCM_SHIFT                 (0U)
#define RGBIR_CCM2_CAM_CCM(x)                    (((uint32_t)(((uint32_t)(x)) << RGBIR_CCM2_CAM_CCM_SHIFT)) & RGBIR_CCM2_CAM_CCM_MASK)
/*! @} */

/* The count of RGBIR_CCM2_CAM */
#define RGBIR_CCM2_CAM_COUNT                     (1U)

/*! @name CCM0_TH_CAM - Camera 0 channel 3 (IR) to channel 0 (Red) Crosstalk Threshold Register */
/*! @{ */

#define RGBIR_CCM0_TH_CAM_THRESHOLD_MASK         (0xFFFFFU)
#define RGBIR_CCM0_TH_CAM_THRESHOLD_SHIFT        (0U)
#define RGBIR_CCM0_TH_CAM_THRESHOLD(x)           (((uint32_t)(((uint32_t)(x)) << RGBIR_CCM0_TH_CAM_THRESHOLD_SHIFT)) & RGBIR_CCM0_TH_CAM_THRESHOLD_MASK)
/*! @} */

/* The count of RGBIR_CCM0_TH_CAM */
#define RGBIR_CCM0_TH_CAM_COUNT                  (1U)

/*! @name CCM1_TH_CAM - Camera 0 channel 3 (IR) to channel 1 (Green) Crosstalk Threshold Register */
/*! @{ */

#define RGBIR_CCM1_TH_CAM_THRESHOLD_MASK         (0xFFFFFU)
#define RGBIR_CCM1_TH_CAM_THRESHOLD_SHIFT        (0U)
#define RGBIR_CCM1_TH_CAM_THRESHOLD(x)           (((uint32_t)(((uint32_t)(x)) << RGBIR_CCM1_TH_CAM_THRESHOLD_SHIFT)) & RGBIR_CCM1_TH_CAM_THRESHOLD_MASK)
/*! @} */

/* The count of RGBIR_CCM1_TH_CAM */
#define RGBIR_CCM1_TH_CAM_COUNT                  (1U)

/*! @name CCM2_TH_CAM - Camera 0 channel 3 (IR) to channel 2 (Blue) Crosstalk Threshold Register */
/*! @{ */

#define RGBIR_CCM2_TH_CAM_THRESHOLD_MASK         (0xFFFFFU)
#define RGBIR_CCM2_TH_CAM_THRESHOLD_SHIFT        (0U)
#define RGBIR_CCM2_TH_CAM_THRESHOLD(x)           (((uint32_t)(((uint32_t)(x)) << RGBIR_CCM2_TH_CAM_THRESHOLD_SHIFT)) & RGBIR_CCM2_TH_CAM_THRESHOLD_MASK)
/*! @} */

/* The count of RGBIR_CCM2_TH_CAM */
#define RGBIR_CCM2_TH_CAM_COUNT                  (1U)

/*! @name ROI0_POS_CAM - Camera 0 Statistics Region of Interest 0 Position Register */
/*! @{ */

#define RGBIR_ROI0_POS_CAM_XPOS_MASK             (0xFFFFU)
#define RGBIR_ROI0_POS_CAM_XPOS_SHIFT            (0U)
#define RGBIR_ROI0_POS_CAM_XPOS(x)               (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI0_POS_CAM_XPOS_SHIFT)) & RGBIR_ROI0_POS_CAM_XPOS_MASK)

#define RGBIR_ROI0_POS_CAM_YPOS_MASK             (0xFFFF0000U)
#define RGBIR_ROI0_POS_CAM_YPOS_SHIFT            (16U)
#define RGBIR_ROI0_POS_CAM_YPOS(x)               (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI0_POS_CAM_YPOS_SHIFT)) & RGBIR_ROI0_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of RGBIR_ROI0_POS_CAM */
#define RGBIR_ROI0_POS_CAM_COUNT                 (1U)

/*! @name ROI0_SIZE_CAM - Camera 0 Statistics Region of Interest 0 Size Register */
/*! @{ */

#define RGBIR_ROI0_SIZE_CAM_WIDTH_MASK           (0xFFFFU)
#define RGBIR_ROI0_SIZE_CAM_WIDTH_SHIFT          (0U)
#define RGBIR_ROI0_SIZE_CAM_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI0_SIZE_CAM_WIDTH_SHIFT)) & RGBIR_ROI0_SIZE_CAM_WIDTH_MASK)

#define RGBIR_ROI0_SIZE_CAM_HEIGHT_MASK          (0xFFFF0000U)
#define RGBIR_ROI0_SIZE_CAM_HEIGHT_SHIFT         (16U)
#define RGBIR_ROI0_SIZE_CAM_HEIGHT(x)            (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI0_SIZE_CAM_HEIGHT_SHIFT)) & RGBIR_ROI0_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of RGBIR_ROI0_SIZE_CAM */
#define RGBIR_ROI0_SIZE_CAM_COUNT                (1U)

/*! @name ROI1_POS_CAM - Camera 0 Statistics Region of Interest 1 Position Register */
/*! @{ */

#define RGBIR_ROI1_POS_CAM_XPOS_MASK             (0xFFFFU)
#define RGBIR_ROI1_POS_CAM_XPOS_SHIFT            (0U)
#define RGBIR_ROI1_POS_CAM_XPOS(x)               (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI1_POS_CAM_XPOS_SHIFT)) & RGBIR_ROI1_POS_CAM_XPOS_MASK)

#define RGBIR_ROI1_POS_CAM_YPOS_MASK             (0xFFFF0000U)
#define RGBIR_ROI1_POS_CAM_YPOS_SHIFT            (16U)
#define RGBIR_ROI1_POS_CAM_YPOS(x)               (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI1_POS_CAM_YPOS_SHIFT)) & RGBIR_ROI1_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of RGBIR_ROI1_POS_CAM */
#define RGBIR_ROI1_POS_CAM_COUNT                 (1U)

/*! @name ROI1_SIZE_CAM - Camera 0 Statistics Region of Interest 1 Size Register */
/*! @{ */

#define RGBIR_ROI1_SIZE_CAM_WIDTH_MASK           (0xFFFFU)
#define RGBIR_ROI1_SIZE_CAM_WIDTH_SHIFT          (0U)
#define RGBIR_ROI1_SIZE_CAM_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI1_SIZE_CAM_WIDTH_SHIFT)) & RGBIR_ROI1_SIZE_CAM_WIDTH_MASK)

#define RGBIR_ROI1_SIZE_CAM_HEIGHT_MASK          (0xFFFF0000U)
#define RGBIR_ROI1_SIZE_CAM_HEIGHT_SHIFT         (16U)
#define RGBIR_ROI1_SIZE_CAM_HEIGHT(x)            (((uint32_t)(((uint32_t)(x)) << RGBIR_ROI1_SIZE_CAM_HEIGHT_SHIFT)) & RGBIR_ROI1_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of RGBIR_ROI1_SIZE_CAM */
#define RGBIR_ROI1_SIZE_CAM_COUNT                (1U)

/*! @name CTRL_CAM - Camera 0 RGBIR Histogram 0 Control Register..Camera 0 RGBIR Histogram 1 Control Register */
/*! @{ */

#define RGBIR_CTRL_CAM_LIN_VS_LOG_MASK           (0x1U)
#define RGBIR_CTRL_CAM_LIN_VS_LOG_SHIFT          (0U)
/*! LIN_VS_LOG
 *  0b0..Linear: Scaled pixel value provides the bin number.
 *  0b1..Logarithmic: Log operation is performed scaled pixel value for providing the bin number.
 */
#define RGBIR_CTRL_CAM_LIN_VS_LOG(x)             (((uint32_t)(((uint32_t)(x)) << RGBIR_CTRL_CAM_LIN_VS_LOG_SHIFT)) & RGBIR_CTRL_CAM_LIN_VS_LOG_MASK)

#define RGBIR_CTRL_CAM_DIR_VS_DIF_MASK           (0x2U)
#define RGBIR_CTRL_CAM_DIR_VS_DIF_SHIFT          (1U)
/*! DIR_VS_DIF
 *  0b0..Direct: After correcting the black level offset, use the pixel value as is for scaling.
 *  0b1..Difference: After correcting the black level offset, use the difference with neighbouring pixel for scaling.
 */
#define RGBIR_CTRL_CAM_DIR_VS_DIF(x)             (((uint32_t)(((uint32_t)(x)) << RGBIR_CTRL_CAM_DIR_VS_DIF_SHIFT)) & RGBIR_CTRL_CAM_DIR_VS_DIF_MASK)

#define RGBIR_CTRL_CAM_PATTERN_MASK              (0x4U)
#define RGBIR_CTRL_CAM_PATTERN_SHIFT             (2U)
/*! PATTERN
 *  0b0..1x1: Neighbouring pixel is 1 position to the left
 *  0b1..2x2: Neighbouring pixel is 2 position to the left
 */
#define RGBIR_CTRL_CAM_PATTERN(x)                (((uint32_t)(((uint32_t)(x)) << RGBIR_CTRL_CAM_PATTERN_SHIFT)) & RGBIR_CTRL_CAM_PATTERN_MASK)

#define RGBIR_CTRL_CAM_CHANNEL_MASK              (0xF00U)
#define RGBIR_CTRL_CAM_CHANNEL_SHIFT             (8U)
/*! CHANNEL
 *  0b0001..1st channel of a 2x2 window of input image.
 *  0b0010..2nd channel of a 2x2 window of input image.
 *  0b0100..3rd channel of a 2x2 window of input image. This channel is only enabled when the 1st channel is disabled.
 *  0b1000..4th channel of a 2x2 window of input image. This channel is only enabled when the 2nd channel is disabled.
 */
#define RGBIR_CTRL_CAM_CHANNEL(x)                (((uint32_t)(((uint32_t)(x)) << RGBIR_CTRL_CAM_CHANNEL_SHIFT)) & RGBIR_CTRL_CAM_CHANNEL_MASK)

#define RGBIR_CTRL_CAM_OFFSET_MASK               (0xFFFF0000U)
#define RGBIR_CTRL_CAM_OFFSET_SHIFT              (16U)
#define RGBIR_CTRL_CAM_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << RGBIR_CTRL_CAM_OFFSET_SHIFT)) & RGBIR_CTRL_CAM_OFFSET_MASK)
/*! @} */

/* The count of RGBIR_CTRL_CAM */
#define RGBIR_NEO_PIPE1_RGBIR_CONF_HIST_CTRL_CAM_COUNT (1U)

/* The count of RGBIR_CTRL_CAM */
#define RGBIR_CTRL_CAM_COUNT2                    (2U)

/*! @name SCALE_CAM - Camera 0 RGBIR Histogram 0 Scale Register..Camera 0 RGBIR Histogram 1 Scale Register */
/*! @{ */

#define RGBIR_SCALE_CAM_SCALE_MASK               (0xFFFFFFU)
#define RGBIR_SCALE_CAM_SCALE_SHIFT              (0U)
#define RGBIR_SCALE_CAM_SCALE(x)                 (((uint32_t)(((uint32_t)(x)) << RGBIR_SCALE_CAM_SCALE_SHIFT)) & RGBIR_SCALE_CAM_SCALE_MASK)
/*! @} */

/* The count of RGBIR_SCALE_CAM */
#define RGBIR_SCALE_CAM_COUNT                    (1U)

/* The count of RGBIR_SCALE_CAM */
#define RGBIR_SCALE_CAM_COUNT2                   (2U)


/*!
 * @}
 */ /* end of group RGBIR_Register_Masks */


/*!
 * @}
 */ /* end of group RGBIR_Peripheral_Access_Layer */


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


#endif  /* RGBIR_H_ */

