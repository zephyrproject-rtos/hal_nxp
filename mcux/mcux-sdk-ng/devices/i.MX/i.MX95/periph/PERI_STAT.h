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
**         CMSIS Peripheral Access Layer for STAT
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
 * @file STAT.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for STAT
 *
 * CMSIS Peripheral Access Layer for STAT
 */

#if !defined(STAT_H_)
#define STAT_H_                                  /**< Symbol preventing repeated inclusion */

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
   -- STAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STAT_Peripheral_Access_Layer STAT Peripheral Access Layer
 * @{
 */

/** STAT - Size of Registers Arrays */
#define STAT_NEO_PIPE1_STAT_HIST_COUNT            4u
#define STAT_NEO_PIPE1_STAT_COUNT                 1u

/** STAT - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x40 */
    __IO uint32_t ROI0_POS_CAM;                      /**< Camera 0 Statistics Region of Interest 0 Position Register, array offset: 0x0, array step: 0x40 */
    __IO uint32_t ROI0_SIZE_CAM;                     /**< Camera 0 Statistics Region of Interest 0 Size Register, array offset: 0x4, array step: 0x40 */
    __IO uint32_t ROI1_POS_CAM;                      /**< Camera 0 Statistics Region of Interest 1 Position Register, array offset: 0x8, array step: 0x40 */
    __IO uint32_t ROI1_SIZE_CAM;                     /**< Camera 0 Statistics Region of Interest 1 Size Register, array offset: 0xC, array step: 0x40 */
         uint8_t RESERVED_0[16];
    struct {                                         /* offset: 0x20, array step: index*0x40, index2*0x8 */
      __IO uint32_t CTRL_CAM;                          /**< Camera 0 Histogram 0 Control Register..Camera 0 Histogram 3 Control Register, array offset: 0x20, array step: index*0x40, index2*0x8 */
      __IO uint32_t SCALE_CAM;                         /**< Camera 0 Histogram 0 Scale Register..Camera 0 Histogram 3 Scale Register, array offset: 0x24, array step: index*0x40, index2*0x8 */
    } HIST[STAT_NEO_PIPE1_STAT_HIST_COUNT];
  } NEO_PIPE1_STAT[STAT_NEO_PIPE1_STAT_COUNT];
} STAT_Type;

/* ----------------------------------------------------------------------------
   -- STAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STAT_Register_Masks STAT Register Masks
 * @{
 */

/*! @name ROI0_POS_CAM - Camera 0 Statistics Region of Interest 0 Position Register */
/*! @{ */

#define STAT_ROI0_POS_CAM_XPOS_MASK              (0xFFFFU)
#define STAT_ROI0_POS_CAM_XPOS_SHIFT             (0U)
#define STAT_ROI0_POS_CAM_XPOS(x)                (((uint32_t)(((uint32_t)(x)) << STAT_ROI0_POS_CAM_XPOS_SHIFT)) & STAT_ROI0_POS_CAM_XPOS_MASK)

#define STAT_ROI0_POS_CAM_YPOS_MASK              (0xFFFF0000U)
#define STAT_ROI0_POS_CAM_YPOS_SHIFT             (16U)
#define STAT_ROI0_POS_CAM_YPOS(x)                (((uint32_t)(((uint32_t)(x)) << STAT_ROI0_POS_CAM_YPOS_SHIFT)) & STAT_ROI0_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of STAT_ROI0_POS_CAM */
#define STAT_ROI0_POS_CAM_COUNT                  (1U)

/*! @name ROI0_SIZE_CAM - Camera 0 Statistics Region of Interest 0 Size Register */
/*! @{ */

#define STAT_ROI0_SIZE_CAM_WIDTH_MASK            (0xFFFFU)
#define STAT_ROI0_SIZE_CAM_WIDTH_SHIFT           (0U)
#define STAT_ROI0_SIZE_CAM_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << STAT_ROI0_SIZE_CAM_WIDTH_SHIFT)) & STAT_ROI0_SIZE_CAM_WIDTH_MASK)

#define STAT_ROI0_SIZE_CAM_HEIGHT_MASK           (0xFFFF0000U)
#define STAT_ROI0_SIZE_CAM_HEIGHT_SHIFT          (16U)
#define STAT_ROI0_SIZE_CAM_HEIGHT(x)             (((uint32_t)(((uint32_t)(x)) << STAT_ROI0_SIZE_CAM_HEIGHT_SHIFT)) & STAT_ROI0_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of STAT_ROI0_SIZE_CAM */
#define STAT_ROI0_SIZE_CAM_COUNT                 (1U)

/*! @name ROI1_POS_CAM - Camera 0 Statistics Region of Interest 1 Position Register */
/*! @{ */

#define STAT_ROI1_POS_CAM_XPOS_MASK              (0xFFFFU)
#define STAT_ROI1_POS_CAM_XPOS_SHIFT             (0U)
#define STAT_ROI1_POS_CAM_XPOS(x)                (((uint32_t)(((uint32_t)(x)) << STAT_ROI1_POS_CAM_XPOS_SHIFT)) & STAT_ROI1_POS_CAM_XPOS_MASK)

#define STAT_ROI1_POS_CAM_YPOS_MASK              (0xFFFF0000U)
#define STAT_ROI1_POS_CAM_YPOS_SHIFT             (16U)
#define STAT_ROI1_POS_CAM_YPOS(x)                (((uint32_t)(((uint32_t)(x)) << STAT_ROI1_POS_CAM_YPOS_SHIFT)) & STAT_ROI1_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of STAT_ROI1_POS_CAM */
#define STAT_ROI1_POS_CAM_COUNT                  (1U)

/*! @name ROI1_SIZE_CAM - Camera 0 Statistics Region of Interest 1 Size Register */
/*! @{ */

#define STAT_ROI1_SIZE_CAM_WIDTH_MASK            (0xFFFFU)
#define STAT_ROI1_SIZE_CAM_WIDTH_SHIFT           (0U)
#define STAT_ROI1_SIZE_CAM_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << STAT_ROI1_SIZE_CAM_WIDTH_SHIFT)) & STAT_ROI1_SIZE_CAM_WIDTH_MASK)

#define STAT_ROI1_SIZE_CAM_HEIGHT_MASK           (0xFFFF0000U)
#define STAT_ROI1_SIZE_CAM_HEIGHT_SHIFT          (16U)
#define STAT_ROI1_SIZE_CAM_HEIGHT(x)             (((uint32_t)(((uint32_t)(x)) << STAT_ROI1_SIZE_CAM_HEIGHT_SHIFT)) & STAT_ROI1_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of STAT_ROI1_SIZE_CAM */
#define STAT_ROI1_SIZE_CAM_COUNT                 (1U)

/*! @name CTRL_CAM - Camera 0 Histogram 0 Control Register..Camera 0 Histogram 3 Control Register */
/*! @{ */

#define STAT_CTRL_CAM_LIN_VS_LOG_MASK            (0x1U)
#define STAT_CTRL_CAM_LIN_VS_LOG_SHIFT           (0U)
/*! LIN_VS_LOG
 *  0b0..Linear: Scaled pixel value provides the bin number.
 *  0b1..Logarithmic: Log operation is performed scaled pixel value for providing the bin number.
 */
#define STAT_CTRL_CAM_LIN_VS_LOG(x)              (((uint32_t)(((uint32_t)(x)) << STAT_CTRL_CAM_LIN_VS_LOG_SHIFT)) & STAT_CTRL_CAM_LIN_VS_LOG_MASK)

#define STAT_CTRL_CAM_DIR_VS_DIF_MASK            (0x2U)
#define STAT_CTRL_CAM_DIR_VS_DIF_SHIFT           (1U)
/*! DIR_VS_DIF
 *  0b0..Direct: Use pixel value for correcting the black level offset & scaling.
 *  0b1..Difference: Use difference with left neighboring pixel of same channel for the black level offset & scaling.
 */
#define STAT_CTRL_CAM_DIR_VS_DIF(x)              (((uint32_t)(((uint32_t)(x)) << STAT_CTRL_CAM_DIR_VS_DIF_SHIFT)) & STAT_CTRL_CAM_DIR_VS_DIF_MASK)

#define STAT_CTRL_CAM_PATTERN_MASK               (0x4U)
#define STAT_CTRL_CAM_PATTERN_SHIFT              (2U)
/*! PATTERN
 *  0b0..1x1: Neighboring pixel is 1 position to the left
 *  0b1..2x2: Neighboring pixel is 2 position to the left
 */
#define STAT_CTRL_CAM_PATTERN(x)                 (((uint32_t)(((uint32_t)(x)) << STAT_CTRL_CAM_PATTERN_SHIFT)) & STAT_CTRL_CAM_PATTERN_MASK)

#define STAT_CTRL_CAM_CHANNEL_MASK               (0xF00U)
#define STAT_CTRL_CAM_CHANNEL_SHIFT              (8U)
/*! CHANNEL
 *  0b0001..Position of 1 indicates, Red (R) pixels of a RGGB Bayer pattern
 *  0b0010..Position of 1 indicates, Green (Gr) pixels of a RGGB Bayer pattern
 *  0b0100..Position of 1 indicates, Green (Gb) pixels of a RGGB Bayer pattern
 *  0b1000..Position of 1 indicates, Blue (B) pixels of a RGGB Bayer pattern
 */
#define STAT_CTRL_CAM_CHANNEL(x)                 (((uint32_t)(((uint32_t)(x)) << STAT_CTRL_CAM_CHANNEL_SHIFT)) & STAT_CTRL_CAM_CHANNEL_MASK)

#define STAT_CTRL_CAM_OFFSET_MASK                (0xFFFF0000U)
#define STAT_CTRL_CAM_OFFSET_SHIFT               (16U)
#define STAT_CTRL_CAM_OFFSET(x)                  (((uint32_t)(((uint32_t)(x)) << STAT_CTRL_CAM_OFFSET_SHIFT)) & STAT_CTRL_CAM_OFFSET_MASK)
/*! @} */

/* The count of STAT_CTRL_CAM */
#define STAT_CTRL_CAM_COUNT                      (1U)

/* The count of STAT_CTRL_CAM */
#define STAT_CTRL_CAM_COUNT2                     (4U)

/*! @name SCALE_CAM - Camera 0 Histogram 0 Scale Register..Camera 0 Histogram 3 Scale Register */
/*! @{ */

#define STAT_SCALE_CAM_SCALE_MASK                (0xFFFFFFU)
#define STAT_SCALE_CAM_SCALE_SHIFT               (0U)
#define STAT_SCALE_CAM_SCALE(x)                  (((uint32_t)(((uint32_t)(x)) << STAT_SCALE_CAM_SCALE_SHIFT)) & STAT_SCALE_CAM_SCALE_MASK)
/*! @} */

/* The count of STAT_SCALE_CAM */
#define STAT_SCALE_CAM_COUNT                     (1U)

/* The count of STAT_SCALE_CAM */
#define STAT_SCALE_CAM_COUNT2                    (4U)


/*!
 * @}
 */ /* end of group STAT_Register_Masks */


/*!
 * @}
 */ /* end of group STAT_Peripheral_Access_Layer */


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


#endif  /* STAT_H_ */

