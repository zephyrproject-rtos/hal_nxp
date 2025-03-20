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
**         CMSIS Peripheral Access Layer for DRC
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
 * @file DRC.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DRC
 *
 * CMSIS Peripheral Access Layer for DRC
 */

#if !defined(DRC_H_)
#define DRC_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- DRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DRC_Peripheral_Access_Layer DRC Peripheral Access Layer
 * @{
 */

/** DRC - Size of Registers Arrays */
#define DRC_NEO_PIPE2_DRC_CONF_COUNT              1u

/** DRC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x58 */
    __IO uint32_t ROI0_POS_CAM;                      /**< Camera 0 DRC Region of Interest 0 Position Register, array offset: 0x0, array step: 0x58 */
    __IO uint32_t ROI0_SIZE_CAM;                     /**< Camera 0 DRC Region of Interest 0 Size Register, array offset: 0x4, array step: 0x58 */
    __IO uint32_t ROI1_POS_CAM;                      /**< Camera 0 DRC Region of Interest 1 Position Register, array offset: 0x8, array step: 0x58 */
    __IO uint32_t ROI1_SIZE_CAM;                     /**< Camera 0 DRC Region of Interest 1 Size Register, array offset: 0xC, array step: 0x58 */
    __IO uint32_t GROI_SUM_SHIFT_CAM;                /**< Camera 0 DRC Global ROI 0,1 Sum Shift Register, array offset: 0x10, array step: 0x58 */
    __IO uint32_t GBL_GAIN_CAM;                      /**< Camera 0 DRC Global Gain Register, array offset: 0x14, array step: 0x58 */
         uint8_t RESERVED_0[8];
    __IO uint32_t LCL_BLK_SIZE_CAM;                  /**< Camera 0 DRC Local Block Size Register, array offset: 0x20, array step: 0x58 */
    __IO uint32_t LCL_STRETCH_CAM;                   /**< Camera 0 DRC Local Stretch and Offset Register, array offset: 0x24, array step: 0x58 */
    __IO uint32_t LCL_BLK_STEPY_CAM;                 /**< Camera 0 DRC Local Block Y Step Register, array offset: 0x28, array step: 0x58 */
    __IO uint32_t LCL_BLK_STEPX_CAM;                 /**< Camera 0 DRC Local Block X Step Register, array offset: 0x2C, array step: 0x58 */
    __IO uint32_t LCL_SUM_SHIFT_CAM;                 /**< Camera 0 DRC Local Sum Shift Register, array offset: 0x30, array step: 0x58 */
    __IO uint32_t ALPHA_CAM;                         /**< Camera 0 DRC Alpha Blending Register, array offset: 0x34, array step: 0x58 */
         uint8_t RESERVED_1[8];
    __I  uint32_t GROI0_SUM_CAM;                     /**< Camera 0 DRC Global ROI0 Sum Register, array offset: 0x40, array step: 0x58 */
    __I  uint32_t GROI1_SUM_CAM;                     /**< Camera 0 DRC Global ROI1 Sum Register, array offset: 0x44, array step: 0x58 */
         uint8_t RESERVED_2[8];
    __I  uint32_t STAT_BLK_Y_CAM;                    /**< Camera 0 DRC Current Local Block Y Status, array offset: 0x50, array step: 0x58 */
    __I  uint32_t CURR_YFRACT_CAM;                   /**< Camera 0 DRC Current Local Block Y Fraction, array offset: 0x54, array step: 0x58 */
  } NEO_PIPE2_DRC_CONF[DRC_NEO_PIPE2_DRC_CONF_COUNT];
} DRC_Type;

/* ----------------------------------------------------------------------------
   -- DRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DRC_Register_Masks DRC Register Masks
 * @{
 */

/*! @name ROI0_POS_CAM - Camera 0 DRC Region of Interest 0 Position Register */
/*! @{ */

#define DRC_ROI0_POS_CAM_XPOS_MASK               (0xFFFFU)
#define DRC_ROI0_POS_CAM_XPOS_SHIFT              (0U)
#define DRC_ROI0_POS_CAM_XPOS(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_ROI0_POS_CAM_XPOS_SHIFT)) & DRC_ROI0_POS_CAM_XPOS_MASK)

#define DRC_ROI0_POS_CAM_YPOS_MASK               (0xFFFF0000U)
#define DRC_ROI0_POS_CAM_YPOS_SHIFT              (16U)
#define DRC_ROI0_POS_CAM_YPOS(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_ROI0_POS_CAM_YPOS_SHIFT)) & DRC_ROI0_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of DRC_ROI0_POS_CAM */
#define DRC_ROI0_POS_CAM_COUNT                   (1U)

/*! @name ROI0_SIZE_CAM - Camera 0 DRC Region of Interest 0 Size Register */
/*! @{ */

#define DRC_ROI0_SIZE_CAM_WIDTH_MASK             (0xFFFFU)
#define DRC_ROI0_SIZE_CAM_WIDTH_SHIFT            (0U)
#define DRC_ROI0_SIZE_CAM_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << DRC_ROI0_SIZE_CAM_WIDTH_SHIFT)) & DRC_ROI0_SIZE_CAM_WIDTH_MASK)

#define DRC_ROI0_SIZE_CAM_HEIGHT_MASK            (0xFFFF0000U)
#define DRC_ROI0_SIZE_CAM_HEIGHT_SHIFT           (16U)
#define DRC_ROI0_SIZE_CAM_HEIGHT(x)              (((uint32_t)(((uint32_t)(x)) << DRC_ROI0_SIZE_CAM_HEIGHT_SHIFT)) & DRC_ROI0_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of DRC_ROI0_SIZE_CAM */
#define DRC_ROI0_SIZE_CAM_COUNT                  (1U)

/*! @name ROI1_POS_CAM - Camera 0 DRC Region of Interest 1 Position Register */
/*! @{ */

#define DRC_ROI1_POS_CAM_XPOS_MASK               (0xFFFFU)
#define DRC_ROI1_POS_CAM_XPOS_SHIFT              (0U)
#define DRC_ROI1_POS_CAM_XPOS(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_ROI1_POS_CAM_XPOS_SHIFT)) & DRC_ROI1_POS_CAM_XPOS_MASK)

#define DRC_ROI1_POS_CAM_YPOS_MASK               (0xFFFF0000U)
#define DRC_ROI1_POS_CAM_YPOS_SHIFT              (16U)
#define DRC_ROI1_POS_CAM_YPOS(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_ROI1_POS_CAM_YPOS_SHIFT)) & DRC_ROI1_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of DRC_ROI1_POS_CAM */
#define DRC_ROI1_POS_CAM_COUNT                   (1U)

/*! @name ROI1_SIZE_CAM - Camera 0 DRC Region of Interest 1 Size Register */
/*! @{ */

#define DRC_ROI1_SIZE_CAM_WIDTH_MASK             (0xFFFFU)
#define DRC_ROI1_SIZE_CAM_WIDTH_SHIFT            (0U)
#define DRC_ROI1_SIZE_CAM_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << DRC_ROI1_SIZE_CAM_WIDTH_SHIFT)) & DRC_ROI1_SIZE_CAM_WIDTH_MASK)

#define DRC_ROI1_SIZE_CAM_HEIGHT_MASK            (0xFFFF0000U)
#define DRC_ROI1_SIZE_CAM_HEIGHT_SHIFT           (16U)
#define DRC_ROI1_SIZE_CAM_HEIGHT(x)              (((uint32_t)(((uint32_t)(x)) << DRC_ROI1_SIZE_CAM_HEIGHT_SHIFT)) & DRC_ROI1_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of DRC_ROI1_SIZE_CAM */
#define DRC_ROI1_SIZE_CAM_COUNT                  (1U)

/*! @name GROI_SUM_SHIFT_CAM - Camera 0 DRC Global ROI 0,1 Sum Shift Register */
/*! @{ */

#define DRC_GROI_SUM_SHIFT_CAM_SHIFT0_MASK       (0x1FU)
#define DRC_GROI_SUM_SHIFT_CAM_SHIFT0_SHIFT      (0U)
#define DRC_GROI_SUM_SHIFT_CAM_SHIFT0(x)         (((uint32_t)(((uint32_t)(x)) << DRC_GROI_SUM_SHIFT_CAM_SHIFT0_SHIFT)) & DRC_GROI_SUM_SHIFT_CAM_SHIFT0_MASK)

#define DRC_GROI_SUM_SHIFT_CAM_SHIFT1_MASK       (0x1F0000U)
#define DRC_GROI_SUM_SHIFT_CAM_SHIFT1_SHIFT      (16U)
#define DRC_GROI_SUM_SHIFT_CAM_SHIFT1(x)         (((uint32_t)(((uint32_t)(x)) << DRC_GROI_SUM_SHIFT_CAM_SHIFT1_SHIFT)) & DRC_GROI_SUM_SHIFT_CAM_SHIFT1_MASK)
/*! @} */

/* The count of DRC_GROI_SUM_SHIFT_CAM */
#define DRC_GROI_SUM_SHIFT_CAM_COUNT             (1U)

/*! @name GBL_GAIN_CAM - Camera 0 DRC Global Gain Register */
/*! @{ */

#define DRC_GBL_GAIN_CAM_GAIN_MASK               (0xFFFFU)
#define DRC_GBL_GAIN_CAM_GAIN_SHIFT              (0U)
#define DRC_GBL_GAIN_CAM_GAIN(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_GBL_GAIN_CAM_GAIN_SHIFT)) & DRC_GBL_GAIN_CAM_GAIN_MASK)
/*! @} */

/* The count of DRC_GBL_GAIN_CAM */
#define DRC_GBL_GAIN_CAM_COUNT                   (1U)

/*! @name LCL_BLK_SIZE_CAM - Camera 0 DRC Local Block Size Register */
/*! @{ */

#define DRC_LCL_BLK_SIZE_CAM_XSIZE_MASK          (0xFFFFU)
#define DRC_LCL_BLK_SIZE_CAM_XSIZE_SHIFT         (0U)
#define DRC_LCL_BLK_SIZE_CAM_XSIZE(x)            (((uint32_t)(((uint32_t)(x)) << DRC_LCL_BLK_SIZE_CAM_XSIZE_SHIFT)) & DRC_LCL_BLK_SIZE_CAM_XSIZE_MASK)

#define DRC_LCL_BLK_SIZE_CAM_YSIZE_MASK          (0xFFFF0000U)
#define DRC_LCL_BLK_SIZE_CAM_YSIZE_SHIFT         (16U)
#define DRC_LCL_BLK_SIZE_CAM_YSIZE(x)            (((uint32_t)(((uint32_t)(x)) << DRC_LCL_BLK_SIZE_CAM_YSIZE_SHIFT)) & DRC_LCL_BLK_SIZE_CAM_YSIZE_MASK)
/*! @} */

/* The count of DRC_LCL_BLK_SIZE_CAM */
#define DRC_LCL_BLK_SIZE_CAM_COUNT               (1U)

/*! @name LCL_STRETCH_CAM - Camera 0 DRC Local Stretch and Offset Register */
/*! @{ */

#define DRC_LCL_STRETCH_CAM_STRETCH_MASK         (0xFFFFU)
#define DRC_LCL_STRETCH_CAM_STRETCH_SHIFT        (0U)
#define DRC_LCL_STRETCH_CAM_STRETCH(x)           (((uint32_t)(((uint32_t)(x)) << DRC_LCL_STRETCH_CAM_STRETCH_SHIFT)) & DRC_LCL_STRETCH_CAM_STRETCH_MASK)

#define DRC_LCL_STRETCH_CAM_OFFSET_MASK          (0xFFFF0000U)
#define DRC_LCL_STRETCH_CAM_OFFSET_SHIFT         (16U)
#define DRC_LCL_STRETCH_CAM_OFFSET(x)            (((uint32_t)(((uint32_t)(x)) << DRC_LCL_STRETCH_CAM_OFFSET_SHIFT)) & DRC_LCL_STRETCH_CAM_OFFSET_MASK)
/*! @} */

/* The count of DRC_LCL_STRETCH_CAM */
#define DRC_LCL_STRETCH_CAM_COUNT                (1U)

/*! @name LCL_BLK_STEPY_CAM - Camera 0 DRC Local Block Y Step Register */
/*! @{ */

#define DRC_LCL_BLK_STEPY_CAM_STEP_MASK          (0xFFFFU)
#define DRC_LCL_BLK_STEPY_CAM_STEP_SHIFT         (0U)
#define DRC_LCL_BLK_STEPY_CAM_STEP(x)            (((uint32_t)(((uint32_t)(x)) << DRC_LCL_BLK_STEPY_CAM_STEP_SHIFT)) & DRC_LCL_BLK_STEPY_CAM_STEP_MASK)
/*! @} */

/* The count of DRC_LCL_BLK_STEPY_CAM */
#define DRC_LCL_BLK_STEPY_CAM_COUNT              (1U)

/*! @name LCL_BLK_STEPX_CAM - Camera 0 DRC Local Block X Step Register */
/*! @{ */

#define DRC_LCL_BLK_STEPX_CAM_STEP_MASK          (0xFFFFU)
#define DRC_LCL_BLK_STEPX_CAM_STEP_SHIFT         (0U)
#define DRC_LCL_BLK_STEPX_CAM_STEP(x)            (((uint32_t)(((uint32_t)(x)) << DRC_LCL_BLK_STEPX_CAM_STEP_SHIFT)) & DRC_LCL_BLK_STEPX_CAM_STEP_MASK)
/*! @} */

/* The count of DRC_LCL_BLK_STEPX_CAM */
#define DRC_LCL_BLK_STEPX_CAM_COUNT              (1U)

/*! @name LCL_SUM_SHIFT_CAM - Camera 0 DRC Local Sum Shift Register */
/*! @{ */

#define DRC_LCL_SUM_SHIFT_CAM_SHIFT_MASK         (0x1FU)
#define DRC_LCL_SUM_SHIFT_CAM_SHIFT_SHIFT        (0U)
#define DRC_LCL_SUM_SHIFT_CAM_SHIFT(x)           (((uint32_t)(((uint32_t)(x)) << DRC_LCL_SUM_SHIFT_CAM_SHIFT_SHIFT)) & DRC_LCL_SUM_SHIFT_CAM_SHIFT_MASK)
/*! @} */

/* The count of DRC_LCL_SUM_SHIFT_CAM */
#define DRC_LCL_SUM_SHIFT_CAM_COUNT              (1U)

/*! @name ALPHA_CAM - Camera 0 DRC Alpha Blending Register */
/*! @{ */

#define DRC_ALPHA_CAM_ALPHA_MASK                 (0x1FFU)
#define DRC_ALPHA_CAM_ALPHA_SHIFT                (0U)
#define DRC_ALPHA_CAM_ALPHA(x)                   (((uint32_t)(((uint32_t)(x)) << DRC_ALPHA_CAM_ALPHA_SHIFT)) & DRC_ALPHA_CAM_ALPHA_MASK)
/*! @} */

/* The count of DRC_ALPHA_CAM */
#define DRC_ALPHA_CAM_COUNT                      (1U)

/*! @name GROI0_SUM_CAM - Camera 0 DRC Global ROI0 Sum Register */
/*! @{ */

#define DRC_GROI0_SUM_CAM_VAL_MASK               (0xFFFFFFFFU)
#define DRC_GROI0_SUM_CAM_VAL_SHIFT              (0U)
#define DRC_GROI0_SUM_CAM_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_GROI0_SUM_CAM_VAL_SHIFT)) & DRC_GROI0_SUM_CAM_VAL_MASK)
/*! @} */

/* The count of DRC_GROI0_SUM_CAM */
#define DRC_GROI0_SUM_CAM_COUNT                  (1U)

/*! @name GROI1_SUM_CAM - Camera 0 DRC Global ROI1 Sum Register */
/*! @{ */

#define DRC_GROI1_SUM_CAM_VAL_MASK               (0xFFFFFFFFU)
#define DRC_GROI1_SUM_CAM_VAL_SHIFT              (0U)
#define DRC_GROI1_SUM_CAM_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << DRC_GROI1_SUM_CAM_VAL_SHIFT)) & DRC_GROI1_SUM_CAM_VAL_MASK)
/*! @} */

/* The count of DRC_GROI1_SUM_CAM */
#define DRC_GROI1_SUM_CAM_COUNT                  (1U)

/*! @name STAT_BLK_Y_CAM - Camera 0 DRC Current Local Block Y Status */
/*! @{ */

#define DRC_STAT_BLK_Y_CAM_BLKLNE_MASK           (0xFFFFU)
#define DRC_STAT_BLK_Y_CAM_BLKLNE_SHIFT          (0U)
#define DRC_STAT_BLK_Y_CAM_BLKLNE(x)             (((uint32_t)(((uint32_t)(x)) << DRC_STAT_BLK_Y_CAM_BLKLNE_SHIFT)) & DRC_STAT_BLK_Y_CAM_BLKLNE_MASK)

#define DRC_STAT_BLK_Y_CAM_BLKROW_MASK           (0xFF0000U)
#define DRC_STAT_BLK_Y_CAM_BLKROW_SHIFT          (16U)
#define DRC_STAT_BLK_Y_CAM_BLKROW(x)             (((uint32_t)(((uint32_t)(x)) << DRC_STAT_BLK_Y_CAM_BLKROW_SHIFT)) & DRC_STAT_BLK_Y_CAM_BLKROW_MASK)
/*! @} */

/* The count of DRC_STAT_BLK_Y_CAM */
#define DRC_STAT_BLK_Y_CAM_COUNT                 (1U)

/*! @name CURR_YFRACT_CAM - Camera 0 DRC Current Local Block Y Fraction */
/*! @{ */

#define DRC_CURR_YFRACT_CAM_FRACT_MASK           (0xFFFFFFFFU)
#define DRC_CURR_YFRACT_CAM_FRACT_SHIFT          (0U)
#define DRC_CURR_YFRACT_CAM_FRACT(x)             (((uint32_t)(((uint32_t)(x)) << DRC_CURR_YFRACT_CAM_FRACT_SHIFT)) & DRC_CURR_YFRACT_CAM_FRACT_MASK)
/*! @} */

/* The count of DRC_CURR_YFRACT_CAM */
#define DRC_CURR_YFRACT_CAM_COUNT                (1U)


/*!
 * @}
 */ /* end of group DRC_Register_Masks */


/*!
 * @}
 */ /* end of group DRC_Peripheral_Access_Layer */


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


#endif  /* DRC_H_ */

