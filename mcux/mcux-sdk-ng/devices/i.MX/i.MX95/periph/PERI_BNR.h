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
**         CMSIS Peripheral Access Layer for BNR
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
 * @file BNR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for BNR
 *
 * CMSIS Peripheral Access Layer for BNR
 */

#if !defined(BNR_H_)
#define BNR_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- BNR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BNR_Peripheral_Access_Layer BNR Peripheral Access Layer
 * @{
 */

/** BNR - Size of Registers Arrays */
#define BNR_NEO_PIPE1_BNR_CONF_COUNT              1u

/** BNR - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x68 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 BNR Control Register, array offset: 0x0, array step: 0x68 */
    __IO uint32_t YPEAK_CAM;                         /**< Camera 0 BNR YPEAK register, array offset: 0x4, array step: 0x68 */
    __IO uint32_t YEDGE_TH0_CAM;                     /**< Camera 0 BNR YEdge Threshold 0 Register, array offset: 0x8, array step: 0x68 */
    __IO uint32_t YEDGE_SCALE_CAM;                   /**< Camera 0 BNR Long YEdge Scale Register, array offset: 0xC, array step: 0x68 */
    __IO uint32_t YEDGES_TH0_CAM;                    /**< Camera 0 BNR Short Y Edge Threshold 0 Register, array offset: 0x10, array step: 0x68 */
    __IO uint32_t YEDGES_SCALE_CAM;                  /**< Camera 0 BNR Short YEdge Scale Register, array offset: 0x14, array step: 0x68 */
    __IO uint32_t YEDGEA_TH0_CAM;                    /**< Camera 0 BNR Alpha Y Edge Threshold 0 Register, array offset: 0x18, array step: 0x68 */
    __IO uint32_t YEDGEA_SCALE_CAM;                  /**< Camera 0 BNR Alpha YEdge Scale Register, array offset: 0x1C, array step: 0x68 */
    __IO uint32_t YLUMA_X_TH0_CAM;                   /**< Camera 0 BNR YLuma X Threshold 0 Register, array offset: 0x20, array step: 0x68 */
    __IO uint32_t YLUMA_Y_TH_CAM;                    /**< Camera 0 BNR YLuma Y Threshold Register, array offset: 0x24, array step: 0x68 */
    __IO uint32_t YLUMA_SCALE_CAM;                   /**< Camera 0 BNR YLuma Scale Register, array offset: 0x28, array step: 0x68 */
    __IO uint32_t YALPHA_GAIN_CAM;                   /**< Camera 0 BNR YAlpha Gain Register, array offset: 0x2C, array step: 0x68 */
    __IO uint32_t CPEAK_CAM;                         /**< Camera 0 BNR CPEAK register, array offset: 0x30, array step: 0x68 */
    __IO uint32_t CEDGE_TH0_CAM;                     /**< Camera 0 BNR CEdge Threshold 0 Register, array offset: 0x34, array step: 0x68 */
    __IO uint32_t CEDGE_SCALE_CAM;                   /**< Camera 0 BNR CEdge Scale Register, array offset: 0x38, array step: 0x68 */
    __IO uint32_t CEDGES_TH0_CAM;                    /**< Camera 0 BNR Short CEdge Threshold 0 Register, array offset: 0x3C, array step: 0x68 */
    __IO uint32_t CEDGES_SCALE_CAM;                  /**< Camera 0 BNR Short CEdge Scale Register, array offset: 0x40, array step: 0x68 */
    __IO uint32_t CEDGEA_TH0_CAM;                    /**< Camera 0 BNR Alpha CEdge Threshold 0 Register, array offset: 0x44, array step: 0x68 */
    __IO uint32_t CEDGEA_SCALE_CAM;                  /**< Camera 0 BNR Alpha CEdge Scale Register, array offset: 0x48, array step: 0x68 */
    __IO uint32_t CLUMA_X_TH0_CAM;                   /**< Camera 0 BNR CLuma X Threshold 0 Register, array offset: 0x4C, array step: 0x68 */
    __IO uint32_t CLUMA_Y_TH_CAM;                    /**< Camera 0 BNR CLuma Y Threshold Register, array offset: 0x50, array step: 0x68 */
    __IO uint32_t CLUMA_SCALE_CAM;                   /**< Camera 0 BNR CLuma Scale Register, array offset: 0x54, array step: 0x68 */
    __IO uint32_t CALPHA_GAIN_CAM;                   /**< Camera 0 BNR CAlpha Gain Register, array offset: 0x58, array step: 0x68 */
    __I  uint32_t EDGE_STAT_CAM;                     /**< Camera 0BNR Edge Pixel Counter Status Register for L Threshold, array offset: 0x5C, array step: 0x68 */
    __I  uint32_t EDGES_STAT_CAM;                    /**< Camera 0BNR Edge Pixel Counter Status Register for S Threshold, array offset: 0x60, array step: 0x68 */
    __IO uint32_t STRETCH_CAM;                       /**< Camera 0 BNR Pixel Stretch (Gain) Register, array offset: 0x64, array step: 0x68 */
  } NEO_PIPE1_BNR_CONF[BNR_NEO_PIPE1_BNR_CONF_COUNT];
} BNR_Type;

/* ----------------------------------------------------------------------------
   -- BNR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BNR_Register_Masks BNR Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 BNR Control Register */
/*! @{ */

#define BNR_CTRL_CAM_OBPP_MASK                   (0xCU)
#define BNR_CTRL_CAM_OBPP_SHIFT                  (2U)
/*! OBPP
 *  0b00..12 bpp
 *  0b01..14 bpp
 *  0b10..16 bpp
 *  0b11..20 bpp
 */
#define BNR_CTRL_CAM_OBPP(x)                     (((uint32_t)(((uint32_t)(x)) << BNR_CTRL_CAM_OBPP_SHIFT)) & BNR_CTRL_CAM_OBPP_MASK)

#define BNR_CTRL_CAM_DEBUG_MASK                  (0x700U)
#define BNR_CTRL_CAM_DEBUG_SHIFT                 (8U)
/*! DEBUG - Debug view for on-target tuning
 *  0b000..Off
 *  0b001..Final edge decision vs texture
 *  0b010..Final edge decision vs black
 *  0b011..Edge pixel decision according to L filter rule
 *  0b100..Edge pixel decision according to S filter rule
 *  0b101..L vs S decision
 */
#define BNR_CTRL_CAM_DEBUG(x)                    (((uint32_t)(((uint32_t)(x)) << BNR_CTRL_CAM_DEBUG_SHIFT)) & BNR_CTRL_CAM_DEBUG_MASK)

#define BNR_CTRL_CAM_NHOOD_MASK                  (0x10000U)
#define BNR_CTRL_CAM_NHOOD_SHIFT                 (16U)
/*! NHOOD
 *  0b0..2x2, NHOOD is 2 pixel positions
 *  0b1..1x1, NHOOD is 1 pixel position
 */
#define BNR_CTRL_CAM_NHOOD(x)                    (((uint32_t)(((uint32_t)(x)) << BNR_CTRL_CAM_NHOOD_SHIFT)) & BNR_CTRL_CAM_NHOOD_MASK)

#define BNR_CTRL_CAM_ENABLE_MASK                 (0x80000000U)
#define BNR_CTRL_CAM_ENABLE_SHIFT                (31U)
/*! ENABLE
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define BNR_CTRL_CAM_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << BNR_CTRL_CAM_ENABLE_SHIFT)) & BNR_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of BNR_CTRL_CAM */
#define BNR_CTRL_CAM_COUNT                       (1U)

/*! @name YPEAK_CAM - Camera 0 BNR YPEAK register */
/*! @{ */

#define BNR_YPEAK_CAM_PEAK_LOW_MASK              (0xFFFU)
#define BNR_YPEAK_CAM_PEAK_LOW_SHIFT             (0U)
#define BNR_YPEAK_CAM_PEAK_LOW(x)                (((uint32_t)(((uint32_t)(x)) << BNR_YPEAK_CAM_PEAK_LOW_SHIFT)) & BNR_YPEAK_CAM_PEAK_LOW_MASK)

#define BNR_YPEAK_CAM_PEAK_SEL_MASK              (0xC000U)
#define BNR_YPEAK_CAM_PEAK_SEL_SHIFT             (14U)
/*! PEAK_SEL
 *  0b00..Select pixel at 1 position away from the extreme
 *  0b01..Select pixel at 2 position away from the extreme
 *  0b10..Select pixel at 3 position away from the extreme
 *  0b11..Select pixel at 4 position from the extreme (that is median value)
 */
#define BNR_YPEAK_CAM_PEAK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << BNR_YPEAK_CAM_PEAK_SEL_SHIFT)) & BNR_YPEAK_CAM_PEAK_SEL_MASK)

#define BNR_YPEAK_CAM_PEAK_HIGH_MASK             (0xFFF0000U)
#define BNR_YPEAK_CAM_PEAK_HIGH_SHIFT            (16U)
#define BNR_YPEAK_CAM_PEAK_HIGH(x)               (((uint32_t)(((uint32_t)(x)) << BNR_YPEAK_CAM_PEAK_HIGH_SHIFT)) & BNR_YPEAK_CAM_PEAK_HIGH_MASK)

#define BNR_YPEAK_CAM_PEAK_OUTSEL_MASK           (0x80000000U)
#define BNR_YPEAK_CAM_PEAK_OUTSEL_SHIFT          (31U)
/*! PEAK_OUTSEL
 *  0b0..No scaling
 *  0b1..Enable scaling. The clipped output is scaled with either lower scale or higher scale value depending on the clipping level
 */
#define BNR_YPEAK_CAM_PEAK_OUTSEL(x)             (((uint32_t)(((uint32_t)(x)) << BNR_YPEAK_CAM_PEAK_OUTSEL_SHIFT)) & BNR_YPEAK_CAM_PEAK_OUTSEL_MASK)
/*! @} */

/* The count of BNR_YPEAK_CAM */
#define BNR_YPEAK_CAM_COUNT                      (1U)

/*! @name YEDGE_TH0_CAM - Camera 0 BNR YEdge Threshold 0 Register */
/*! @{ */

#define BNR_YEDGE_TH0_CAM_EDGE_TH0_MASK          (0xFFFFFU)
#define BNR_YEDGE_TH0_CAM_EDGE_TH0_SHIFT         (0U)
#define BNR_YEDGE_TH0_CAM_EDGE_TH0(x)            (((uint32_t)(((uint32_t)(x)) << BNR_YEDGE_TH0_CAM_EDGE_TH0_SHIFT)) & BNR_YEDGE_TH0_CAM_EDGE_TH0_MASK)
/*! @} */

/* The count of BNR_YEDGE_TH0_CAM */
#define BNR_YEDGE_TH0_CAM_COUNT                  (1U)

/*! @name YEDGE_SCALE_CAM - Camera 0 BNR Long YEdge Scale Register */
/*! @{ */

#define BNR_YEDGE_SCALE_CAM_SCALE_MASK           (0xFFFFU)
#define BNR_YEDGE_SCALE_CAM_SCALE_SHIFT          (0U)
#define BNR_YEDGE_SCALE_CAM_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << BNR_YEDGE_SCALE_CAM_SCALE_SHIFT)) & BNR_YEDGE_SCALE_CAM_SCALE_MASK)

#define BNR_YEDGE_SCALE_CAM_SHIFT_MASK           (0x1F0000U)
#define BNR_YEDGE_SCALE_CAM_SHIFT_SHIFT          (16U)
#define BNR_YEDGE_SCALE_CAM_SHIFT(x)             (((uint32_t)(((uint32_t)(x)) << BNR_YEDGE_SCALE_CAM_SHIFT_SHIFT)) & BNR_YEDGE_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_YEDGE_SCALE_CAM */
#define BNR_YEDGE_SCALE_CAM_COUNT                (1U)

/*! @name YEDGES_TH0_CAM - Camera 0 BNR Short Y Edge Threshold 0 Register */
/*! @{ */

#define BNR_YEDGES_TH0_CAM_EDGE_TH0_MASK         (0xFFFFFU)
#define BNR_YEDGES_TH0_CAM_EDGE_TH0_SHIFT        (0U)
#define BNR_YEDGES_TH0_CAM_EDGE_TH0(x)           (((uint32_t)(((uint32_t)(x)) << BNR_YEDGES_TH0_CAM_EDGE_TH0_SHIFT)) & BNR_YEDGES_TH0_CAM_EDGE_TH0_MASK)
/*! @} */

/* The count of BNR_YEDGES_TH0_CAM */
#define BNR_YEDGES_TH0_CAM_COUNT                 (1U)

/*! @name YEDGES_SCALE_CAM - Camera 0 BNR Short YEdge Scale Register */
/*! @{ */

#define BNR_YEDGES_SCALE_CAM_SCALE_MASK          (0xFFFFU)
#define BNR_YEDGES_SCALE_CAM_SCALE_SHIFT         (0U)
#define BNR_YEDGES_SCALE_CAM_SCALE(x)            (((uint32_t)(((uint32_t)(x)) << BNR_YEDGES_SCALE_CAM_SCALE_SHIFT)) & BNR_YEDGES_SCALE_CAM_SCALE_MASK)

#define BNR_YEDGES_SCALE_CAM_SHIFT_MASK          (0x1F0000U)
#define BNR_YEDGES_SCALE_CAM_SHIFT_SHIFT         (16U)
#define BNR_YEDGES_SCALE_CAM_SHIFT(x)            (((uint32_t)(((uint32_t)(x)) << BNR_YEDGES_SCALE_CAM_SHIFT_SHIFT)) & BNR_YEDGES_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_YEDGES_SCALE_CAM */
#define BNR_YEDGES_SCALE_CAM_COUNT               (1U)

/*! @name YEDGEA_TH0_CAM - Camera 0 BNR Alpha Y Edge Threshold 0 Register */
/*! @{ */

#define BNR_YEDGEA_TH0_CAM_EDGE_TH0_MASK         (0xFFFFFU)
#define BNR_YEDGEA_TH0_CAM_EDGE_TH0_SHIFT        (0U)
#define BNR_YEDGEA_TH0_CAM_EDGE_TH0(x)           (((uint32_t)(((uint32_t)(x)) << BNR_YEDGEA_TH0_CAM_EDGE_TH0_SHIFT)) & BNR_YEDGEA_TH0_CAM_EDGE_TH0_MASK)
/*! @} */

/* The count of BNR_YEDGEA_TH0_CAM */
#define BNR_YEDGEA_TH0_CAM_COUNT                 (1U)

/*! @name YEDGEA_SCALE_CAM - Camera 0 BNR Alpha YEdge Scale Register */
/*! @{ */

#define BNR_YEDGEA_SCALE_CAM_SCALE_MASK          (0xFFFFU)
#define BNR_YEDGEA_SCALE_CAM_SCALE_SHIFT         (0U)
#define BNR_YEDGEA_SCALE_CAM_SCALE(x)            (((uint32_t)(((uint32_t)(x)) << BNR_YEDGEA_SCALE_CAM_SCALE_SHIFT)) & BNR_YEDGEA_SCALE_CAM_SCALE_MASK)

#define BNR_YEDGEA_SCALE_CAM_SHIFT_MASK          (0x1F0000U)
#define BNR_YEDGEA_SCALE_CAM_SHIFT_SHIFT         (16U)
#define BNR_YEDGEA_SCALE_CAM_SHIFT(x)            (((uint32_t)(((uint32_t)(x)) << BNR_YEDGEA_SCALE_CAM_SHIFT_SHIFT)) & BNR_YEDGEA_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_YEDGEA_SCALE_CAM */
#define BNR_YEDGEA_SCALE_CAM_COUNT               (1U)

/*! @name YLUMA_X_TH0_CAM - Camera 0 BNR YLuma X Threshold 0 Register */
/*! @{ */

#define BNR_YLUMA_X_TH0_CAM_TH_MASK              (0xFFFFFU)
#define BNR_YLUMA_X_TH0_CAM_TH_SHIFT             (0U)
#define BNR_YLUMA_X_TH0_CAM_TH(x)                (((uint32_t)(((uint32_t)(x)) << BNR_YLUMA_X_TH0_CAM_TH_SHIFT)) & BNR_YLUMA_X_TH0_CAM_TH_MASK)
/*! @} */

/* The count of BNR_YLUMA_X_TH0_CAM */
#define BNR_YLUMA_X_TH0_CAM_COUNT                (1U)

/*! @name YLUMA_Y_TH_CAM - Camera 0 BNR YLuma Y Threshold Register */
/*! @{ */

#define BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH0_MASK       (0x3FFU)
#define BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH0_SHIFT      (0U)
#define BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH0(x)         (((uint32_t)(((uint32_t)(x)) << BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH0_SHIFT)) & BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH0_MASK)

#define BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH1_MASK       (0x3FF0000U)
#define BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH1_SHIFT      (16U)
#define BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH1(x)         (((uint32_t)(((uint32_t)(x)) << BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH1_SHIFT)) & BNR_YLUMA_Y_TH_CAM_LUMA_Y_TH1_MASK)
/*! @} */

/* The count of BNR_YLUMA_Y_TH_CAM */
#define BNR_YLUMA_Y_TH_CAM_COUNT                 (1U)

/*! @name YLUMA_SCALE_CAM - Camera 0 BNR YLuma Scale Register */
/*! @{ */

#define BNR_YLUMA_SCALE_CAM_SCALE_MASK           (0xFFFFU)
#define BNR_YLUMA_SCALE_CAM_SCALE_SHIFT          (0U)
#define BNR_YLUMA_SCALE_CAM_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << BNR_YLUMA_SCALE_CAM_SCALE_SHIFT)) & BNR_YLUMA_SCALE_CAM_SCALE_MASK)

#define BNR_YLUMA_SCALE_CAM_SHIFT_MASK           (0x1F0000U)
#define BNR_YLUMA_SCALE_CAM_SHIFT_SHIFT          (16U)
#define BNR_YLUMA_SCALE_CAM_SHIFT(x)             (((uint32_t)(((uint32_t)(x)) << BNR_YLUMA_SCALE_CAM_SHIFT_SHIFT)) & BNR_YLUMA_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_YLUMA_SCALE_CAM */
#define BNR_YLUMA_SCALE_CAM_COUNT                (1U)

/*! @name YALPHA_GAIN_CAM - Camera 0 BNR YAlpha Gain Register */
/*! @{ */

#define BNR_YALPHA_GAIN_CAM_GAIN_MASK            (0xFFFFU)
#define BNR_YALPHA_GAIN_CAM_GAIN_SHIFT           (0U)
#define BNR_YALPHA_GAIN_CAM_GAIN(x)              (((uint32_t)(((uint32_t)(x)) << BNR_YALPHA_GAIN_CAM_GAIN_SHIFT)) & BNR_YALPHA_GAIN_CAM_GAIN_MASK)

#define BNR_YALPHA_GAIN_CAM_OFFSET_MASK          (0xFFFF0000U)
#define BNR_YALPHA_GAIN_CAM_OFFSET_SHIFT         (16U)
#define BNR_YALPHA_GAIN_CAM_OFFSET(x)            (((uint32_t)(((uint32_t)(x)) << BNR_YALPHA_GAIN_CAM_OFFSET_SHIFT)) & BNR_YALPHA_GAIN_CAM_OFFSET_MASK)
/*! @} */

/* The count of BNR_YALPHA_GAIN_CAM */
#define BNR_YALPHA_GAIN_CAM_COUNT                (1U)

/*! @name CPEAK_CAM - Camera 0 BNR CPEAK register */
/*! @{ */

#define BNR_CPEAK_CAM_PEAK_LOW_MASK              (0xFFFU)
#define BNR_CPEAK_CAM_PEAK_LOW_SHIFT             (0U)
#define BNR_CPEAK_CAM_PEAK_LOW(x)                (((uint32_t)(((uint32_t)(x)) << BNR_CPEAK_CAM_PEAK_LOW_SHIFT)) & BNR_CPEAK_CAM_PEAK_LOW_MASK)

#define BNR_CPEAK_CAM_PEAK_SEL_MASK              (0xC000U)
#define BNR_CPEAK_CAM_PEAK_SEL_SHIFT             (14U)
/*! PEAK_SEL
 *  0b00..Select pixel at 1 position away from the extreme
 *  0b01..Select pixel at 2 position away from the extreme
 *  0b10..Select pixel at 3 position away from the extreme
 *  0b11..Select pixel at 4 position from the extreme (that is median value)
 */
#define BNR_CPEAK_CAM_PEAK_SEL(x)                (((uint32_t)(((uint32_t)(x)) << BNR_CPEAK_CAM_PEAK_SEL_SHIFT)) & BNR_CPEAK_CAM_PEAK_SEL_MASK)

#define BNR_CPEAK_CAM_PEAK_HIGH_MASK             (0xFFF0000U)
#define BNR_CPEAK_CAM_PEAK_HIGH_SHIFT            (16U)
#define BNR_CPEAK_CAM_PEAK_HIGH(x)               (((uint32_t)(((uint32_t)(x)) << BNR_CPEAK_CAM_PEAK_HIGH_SHIFT)) & BNR_CPEAK_CAM_PEAK_HIGH_MASK)

#define BNR_CPEAK_CAM_PEAK_OUTSEL_MASK           (0x80000000U)
#define BNR_CPEAK_CAM_PEAK_OUTSEL_SHIFT          (31U)
/*! PEAK_OUTSEL
 *  0b0..No scaling
 *  0b1..Enable scaling. The clipped output is scaled with either lower scale or higher scale value depending on the clipping level
 */
#define BNR_CPEAK_CAM_PEAK_OUTSEL(x)             (((uint32_t)(((uint32_t)(x)) << BNR_CPEAK_CAM_PEAK_OUTSEL_SHIFT)) & BNR_CPEAK_CAM_PEAK_OUTSEL_MASK)
/*! @} */

/* The count of BNR_CPEAK_CAM */
#define BNR_CPEAK_CAM_COUNT                      (1U)

/*! @name CEDGE_TH0_CAM - Camera 0 BNR CEdge Threshold 0 Register */
/*! @{ */

#define BNR_CEDGE_TH0_CAM_EDGE_TH0_MASK          (0xFFFFFU)
#define BNR_CEDGE_TH0_CAM_EDGE_TH0_SHIFT         (0U)
#define BNR_CEDGE_TH0_CAM_EDGE_TH0(x)            (((uint32_t)(((uint32_t)(x)) << BNR_CEDGE_TH0_CAM_EDGE_TH0_SHIFT)) & BNR_CEDGE_TH0_CAM_EDGE_TH0_MASK)
/*! @} */

/* The count of BNR_CEDGE_TH0_CAM */
#define BNR_CEDGE_TH0_CAM_COUNT                  (1U)

/*! @name CEDGE_SCALE_CAM - Camera 0 BNR CEdge Scale Register */
/*! @{ */

#define BNR_CEDGE_SCALE_CAM_SCALE_MASK           (0xFFFFU)
#define BNR_CEDGE_SCALE_CAM_SCALE_SHIFT          (0U)
#define BNR_CEDGE_SCALE_CAM_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << BNR_CEDGE_SCALE_CAM_SCALE_SHIFT)) & BNR_CEDGE_SCALE_CAM_SCALE_MASK)

#define BNR_CEDGE_SCALE_CAM_SHIFT_MASK           (0x1F0000U)
#define BNR_CEDGE_SCALE_CAM_SHIFT_SHIFT          (16U)
#define BNR_CEDGE_SCALE_CAM_SHIFT(x)             (((uint32_t)(((uint32_t)(x)) << BNR_CEDGE_SCALE_CAM_SHIFT_SHIFT)) & BNR_CEDGE_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_CEDGE_SCALE_CAM */
#define BNR_CEDGE_SCALE_CAM_COUNT                (1U)

/*! @name CEDGES_TH0_CAM - Camera 0 BNR Short CEdge Threshold 0 Register */
/*! @{ */

#define BNR_CEDGES_TH0_CAM_EDGE_TH0_MASK         (0xFFFFFU)
#define BNR_CEDGES_TH0_CAM_EDGE_TH0_SHIFT        (0U)
#define BNR_CEDGES_TH0_CAM_EDGE_TH0(x)           (((uint32_t)(((uint32_t)(x)) << BNR_CEDGES_TH0_CAM_EDGE_TH0_SHIFT)) & BNR_CEDGES_TH0_CAM_EDGE_TH0_MASK)
/*! @} */

/* The count of BNR_CEDGES_TH0_CAM */
#define BNR_CEDGES_TH0_CAM_COUNT                 (1U)

/*! @name CEDGES_SCALE_CAM - Camera 0 BNR Short CEdge Scale Register */
/*! @{ */

#define BNR_CEDGES_SCALE_CAM_SCALE_MASK          (0xFFFFU)
#define BNR_CEDGES_SCALE_CAM_SCALE_SHIFT         (0U)
#define BNR_CEDGES_SCALE_CAM_SCALE(x)            (((uint32_t)(((uint32_t)(x)) << BNR_CEDGES_SCALE_CAM_SCALE_SHIFT)) & BNR_CEDGES_SCALE_CAM_SCALE_MASK)

#define BNR_CEDGES_SCALE_CAM_SHIFT_MASK          (0x1F0000U)
#define BNR_CEDGES_SCALE_CAM_SHIFT_SHIFT         (16U)
#define BNR_CEDGES_SCALE_CAM_SHIFT(x)            (((uint32_t)(((uint32_t)(x)) << BNR_CEDGES_SCALE_CAM_SHIFT_SHIFT)) & BNR_CEDGES_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_CEDGES_SCALE_CAM */
#define BNR_CEDGES_SCALE_CAM_COUNT               (1U)

/*! @name CEDGEA_TH0_CAM - Camera 0 BNR Alpha CEdge Threshold 0 Register */
/*! @{ */

#define BNR_CEDGEA_TH0_CAM_EDGE_TH0_MASK         (0xFFFFFU)
#define BNR_CEDGEA_TH0_CAM_EDGE_TH0_SHIFT        (0U)
#define BNR_CEDGEA_TH0_CAM_EDGE_TH0(x)           (((uint32_t)(((uint32_t)(x)) << BNR_CEDGEA_TH0_CAM_EDGE_TH0_SHIFT)) & BNR_CEDGEA_TH0_CAM_EDGE_TH0_MASK)
/*! @} */

/* The count of BNR_CEDGEA_TH0_CAM */
#define BNR_CEDGEA_TH0_CAM_COUNT                 (1U)

/*! @name CEDGEA_SCALE_CAM - Camera 0 BNR Alpha CEdge Scale Register */
/*! @{ */

#define BNR_CEDGEA_SCALE_CAM_SCALE_MASK          (0xFFFFU)
#define BNR_CEDGEA_SCALE_CAM_SCALE_SHIFT         (0U)
#define BNR_CEDGEA_SCALE_CAM_SCALE(x)            (((uint32_t)(((uint32_t)(x)) << BNR_CEDGEA_SCALE_CAM_SCALE_SHIFT)) & BNR_CEDGEA_SCALE_CAM_SCALE_MASK)

#define BNR_CEDGEA_SCALE_CAM_SHIFT_MASK          (0x1F0000U)
#define BNR_CEDGEA_SCALE_CAM_SHIFT_SHIFT         (16U)
#define BNR_CEDGEA_SCALE_CAM_SHIFT(x)            (((uint32_t)(((uint32_t)(x)) << BNR_CEDGEA_SCALE_CAM_SHIFT_SHIFT)) & BNR_CEDGEA_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_CEDGEA_SCALE_CAM */
#define BNR_CEDGEA_SCALE_CAM_COUNT               (1U)

/*! @name CLUMA_X_TH0_CAM - Camera 0 BNR CLuma X Threshold 0 Register */
/*! @{ */

#define BNR_CLUMA_X_TH0_CAM_TH_MASK              (0xFFFFFU)
#define BNR_CLUMA_X_TH0_CAM_TH_SHIFT             (0U)
#define BNR_CLUMA_X_TH0_CAM_TH(x)                (((uint32_t)(((uint32_t)(x)) << BNR_CLUMA_X_TH0_CAM_TH_SHIFT)) & BNR_CLUMA_X_TH0_CAM_TH_MASK)
/*! @} */

/* The count of BNR_CLUMA_X_TH0_CAM */
#define BNR_CLUMA_X_TH0_CAM_COUNT                (1U)

/*! @name CLUMA_Y_TH_CAM - Camera 0 BNR CLuma Y Threshold Register */
/*! @{ */

#define BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH0_MASK       (0x3FFU)
#define BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH0_SHIFT      (0U)
#define BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH0(x)         (((uint32_t)(((uint32_t)(x)) << BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH0_SHIFT)) & BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH0_MASK)

#define BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH1_MASK       (0x3FF0000U)
#define BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH1_SHIFT      (16U)
#define BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH1(x)         (((uint32_t)(((uint32_t)(x)) << BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH1_SHIFT)) & BNR_CLUMA_Y_TH_CAM_LUMA_Y_TH1_MASK)
/*! @} */

/* The count of BNR_CLUMA_Y_TH_CAM */
#define BNR_CLUMA_Y_TH_CAM_COUNT                 (1U)

/*! @name CLUMA_SCALE_CAM - Camera 0 BNR CLuma Scale Register */
/*! @{ */

#define BNR_CLUMA_SCALE_CAM_SCALE_MASK           (0xFFFFU)
#define BNR_CLUMA_SCALE_CAM_SCALE_SHIFT          (0U)
#define BNR_CLUMA_SCALE_CAM_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << BNR_CLUMA_SCALE_CAM_SCALE_SHIFT)) & BNR_CLUMA_SCALE_CAM_SCALE_MASK)

#define BNR_CLUMA_SCALE_CAM_SHIFT_MASK           (0x1F0000U)
#define BNR_CLUMA_SCALE_CAM_SHIFT_SHIFT          (16U)
#define BNR_CLUMA_SCALE_CAM_SHIFT(x)             (((uint32_t)(((uint32_t)(x)) << BNR_CLUMA_SCALE_CAM_SHIFT_SHIFT)) & BNR_CLUMA_SCALE_CAM_SHIFT_MASK)
/*! @} */

/* The count of BNR_CLUMA_SCALE_CAM */
#define BNR_CLUMA_SCALE_CAM_COUNT                (1U)

/*! @name CALPHA_GAIN_CAM - Camera 0 BNR CAlpha Gain Register */
/*! @{ */

#define BNR_CALPHA_GAIN_CAM_GAIN_MASK            (0xFFFFU)
#define BNR_CALPHA_GAIN_CAM_GAIN_SHIFT           (0U)
#define BNR_CALPHA_GAIN_CAM_GAIN(x)              (((uint32_t)(((uint32_t)(x)) << BNR_CALPHA_GAIN_CAM_GAIN_SHIFT)) & BNR_CALPHA_GAIN_CAM_GAIN_MASK)

#define BNR_CALPHA_GAIN_CAM_OFFSET_MASK          (0xFFFF0000U)
#define BNR_CALPHA_GAIN_CAM_OFFSET_SHIFT         (16U)
#define BNR_CALPHA_GAIN_CAM_OFFSET(x)            (((uint32_t)(((uint32_t)(x)) << BNR_CALPHA_GAIN_CAM_OFFSET_SHIFT)) & BNR_CALPHA_GAIN_CAM_OFFSET_MASK)
/*! @} */

/* The count of BNR_CALPHA_GAIN_CAM */
#define BNR_CALPHA_GAIN_CAM_COUNT                (1U)

/*! @name EDGE_STAT_CAM - Camera 0BNR Edge Pixel Counter Status Register for L Threshold */
/*! @{ */

#define BNR_EDGE_STAT_CAM_EDGE_PIXELS_MASK       (0xFFFFFFU)
#define BNR_EDGE_STAT_CAM_EDGE_PIXELS_SHIFT      (0U)
#define BNR_EDGE_STAT_CAM_EDGE_PIXELS(x)         (((uint32_t)(((uint32_t)(x)) << BNR_EDGE_STAT_CAM_EDGE_PIXELS_SHIFT)) & BNR_EDGE_STAT_CAM_EDGE_PIXELS_MASK)
/*! @} */

/* The count of BNR_EDGE_STAT_CAM */
#define BNR_EDGE_STAT_CAM_COUNT                  (1U)

/*! @name EDGES_STAT_CAM - Camera 0BNR Edge Pixel Counter Status Register for S Threshold */
/*! @{ */

#define BNR_EDGES_STAT_CAM_EDGE_PIXELS_MASK      (0xFFFFFFU)
#define BNR_EDGES_STAT_CAM_EDGE_PIXELS_SHIFT     (0U)
#define BNR_EDGES_STAT_CAM_EDGE_PIXELS(x)        (((uint32_t)(((uint32_t)(x)) << BNR_EDGES_STAT_CAM_EDGE_PIXELS_SHIFT)) & BNR_EDGES_STAT_CAM_EDGE_PIXELS_MASK)
/*! @} */

/* The count of BNR_EDGES_STAT_CAM */
#define BNR_EDGES_STAT_CAM_COUNT                 (1U)

/*! @name STRETCH_CAM - Camera 0 BNR Pixel Stretch (Gain) Register */
/*! @{ */

#define BNR_STRETCH_CAM_GAIN_MASK                (0xFFFFU)
#define BNR_STRETCH_CAM_GAIN_SHIFT               (0U)
#define BNR_STRETCH_CAM_GAIN(x)                  (((uint32_t)(((uint32_t)(x)) << BNR_STRETCH_CAM_GAIN_SHIFT)) & BNR_STRETCH_CAM_GAIN_MASK)
/*! @} */

/* The count of BNR_STRETCH_CAM */
#define BNR_STRETCH_CAM_COUNT                    (1U)


/*!
 * @}
 */ /* end of group BNR_Register_Masks */


/*!
 * @}
 */ /* end of group BNR_Peripheral_Access_Layer */


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


#endif  /* BNR_H_ */

