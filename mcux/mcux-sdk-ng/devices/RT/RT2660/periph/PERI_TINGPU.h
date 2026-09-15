/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TINGPU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_TINGPU.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for TINGPU
 *
 * CMSIS Peripheral Access Layer for TINGPU
 */

#if !defined(PERI_TINGPU_H_)
#define PERI_TINGPU_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- TINGPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TINGPU_Peripheral_Access_Layer TINGPU Peripheral Access Layer
 * @{
 */

/** TINGPU - Size of Registers Arrays */
#define TINGPU_COLOR_LUT_COUNT                    256u
#define TINGPU_DST_ADDR_COUNT                     4u
#define TINGPU_DST_STRIDE_COUNT                   4u
#define TINGPU_S1_ADDR_COUNT                      4u
#define TINGPU_S1_STRIDE_COUNT                    4u
#define TINGPU_S1_CLRKEY_LOW_COUNT                4u
#define TINGPU_S1_CLRKEY_HIGH_COUNT               4u
#define TINGPU_S2_ADDR_COUNT                      4u
#define TINGPU_S2_STRIDE_COUNT                    4u
#define TINGPU_S2_CLRKEY_LOW_COUNT                4u
#define TINGPU_S2_CLRKEY_HIGH_COUNT               4u
#define TINGPU_S2_PROJ_TF_COUNT                   9u
#define TINGPU_S2_SCISSOR_CTRL_COUNT              4u
#define TINGPU_S2_SCISSOR_SIZE_COUNT              4u

/** TINGPU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t GPU_CTRL;                          /**< GPU Control, offset: 0x4 */
  __IO uint32_t INTEN;                             /**< Interrupt Enable, offset: 0x8 */
  __IO uint32_t CCDMA_CTRL0;                       /**< Command/Control DMA Register 0, offset: 0xC */
  __O  uint32_t CCDMA_CTRL1;                       /**< Command/Control DMA Register 1, offset: 0x10 */
  __IO uint32_t CCDMA_WAIT;                        /**< Command/Control Wait, offset: 0x14 */
  __IO uint32_t LPR;                               /**< Low Power, offset: 0x18 */
       uint8_t RESERVED_0[36];
  __IO uint32_t INTR;                              /**< Interrupt, offset: 0x40 */
  __I  uint32_t CCDMA_STAT;                        /**< Command/Control Status, offset: 0x44 */
  __I  uint32_t CCDMA_EVT;                         /**< Command/Control Event, offset: 0x48 */
  __I  uint32_t CCDMA_CTX;                         /**< Command/Control CTX, offset: 0x4C */
  __IO uint32_t STS0;                              /**< Status Register 0, offset: 0x50 */
       uint8_t RESERVED_1[172];
  __IO uint32_t COLOR_LUT[TINGPU_COLOR_LUT_COUNT]; /**< Color LUT, array offset: 0x100, array step: 0x4 */
  __IO uint32_t DST_FILL_DATA;                     /**< Destination Fill Data, offset: 0x500 */
  __IO uint32_t DST_CTRL;                          /**< Destination Control, offset: 0x504 */
  __IO uint32_t DST_COLOR_SHIFT;                   /**< Destination Color Shift, offset: 0x508 */
  __IO uint32_t DST_COLOR_BITS;                    /**< Destination Color Bits, offset: 0x50C */
  __IO uint32_t DST_SIZE;                          /**< Destination Size, offset: 0x510 */
  __IO uint32_t DST_ADDR[TINGPU_DST_ADDR_COUNT];   /**< Destination Address, array offset: 0x514, array step: 0x4 */
  __IO uint32_t DST_STRIDE[TINGPU_DST_STRIDE_COUNT]; /**< Destination Stride, array offset: 0x524, array step: 0x4 */
  __IO uint32_t DST_SIGN0;                         /**< Destination Signed 0, offset: 0x534 */
  __IO uint32_t DST_SIGN1;                         /**< Destination Signed 1, offset: 0x538 */
  __IO uint32_t DST_CSC0;                          /**< Destination Color Space Conversion 0, offset: 0x53C */
  __IO uint32_t DST_CSC1;                          /**< Destination Color Space Conversion 1, offset: 0x540 */
  __IO uint32_t DST_CSC2;                          /**< Destination Color Space Conversion 2, offset: 0x544 */
  __IO uint32_t DST_CSC3;                          /**< Destination Color Space Conversion 3, offset: 0x548 */
  __IO uint32_t DST_CSC4;                          /**< Destination Color Space Conversion 4, offset: 0x54C */
  __IO uint32_t DST_CSC5;                          /**< Destination Color Space Conversion 5, offset: 0x550 */
  __IO uint32_t DITHER_CTRL;                       /**< Dithering Control, offset: 0x554 */
  __IO uint32_t S1_CTRL;                           /**< S1 Control, offset: 0x558 */
  __IO uint32_t S1_COLOR_SHIFT;                    /**< S1 Color Shift, offset: 0x55C */
  __IO uint32_t S1_COLOR_BITS;                     /**< S1 Color Bits, offset: 0x560 */
  __IO uint32_t S1_SIZE;                           /**< S1 Size, offset: 0x564 */
  __IO uint32_t S1_ADDR[TINGPU_S1_ADDR_COUNT];     /**< S1 Address, array offset: 0x568, array step: 0x4 */
  __IO uint32_t S1_STRIDE[TINGPU_S1_STRIDE_COUNT]; /**< S1 stride, array offset: 0x578, array step: 0x4 */
  __IO uint32_t S1_BKGND;                          /**< S1 Background, offset: 0x588 */
  __IO uint32_t S1_CSC0;                           /**< S1 Color Space Conversion 0, offset: 0x58C */
  __IO uint32_t S1_CSC1;                           /**< S1 Color Space Conversion 1, offset: 0x590 */
  __IO uint32_t S1_CSC2;                           /**< S1 Color Space Conversion 2, offset: 0x594 */
  __IO uint32_t S1_CLRKEY_LOW[TINGPU_S1_CLRKEY_LOW_COUNT]; /**< S1 Color Key Low, array offset: 0x598, array step: 0x4 */
  __IO uint32_t S1_CLRKEY_HIGH[TINGPU_S1_CLRKEY_HIGH_COUNT]; /**< S1 Color Key High, array offset: 0x5A8, array step: 0x4 */
  __IO uint32_t MASK_CTRL;                         /**< Mask Control, offset: 0x5B8 */
  __IO uint32_t MASK_ADDR;                         /**< Mask Address, offset: 0x5BC */
  __IO uint32_t MASK_STRIDE;                       /**< Mask Stride, offset: 0x5C0 */
  __IO uint32_t S2_CTRL;                           /**< S2 Control, offset: 0x5C4 */
  __IO uint32_t S2_COLOR_SHIFT;                    /**< S2 Color Shift, offset: 0x5C8 */
  __IO uint32_t S2_COLOR_BITS;                     /**< S2 Color Bits, offset: 0x5CC */
  __IO uint32_t S2_SIZE;                           /**< S2 Size, offset: 0x5D0 */
  __IO uint32_t S2_ADDR[TINGPU_S2_ADDR_COUNT];     /**< S2 Address, array offset: 0x5D4, array step: 0x4 */
  __IO uint32_t S2_STRIDE[TINGPU_S2_STRIDE_COUNT]; /**< S2 Stride, array offset: 0x5E4, array step: 0x4 */
  __IO uint32_t S2_BKGND;                          /**< S2 Background, offset: 0x5F4 */
  __IO uint32_t ALPHA_CTRL;                        /**< Alpha Control, offset: 0x5F8 */
  __IO uint32_t BLEND_CTRL;                        /**< Blending Control, offset: 0x5FC */
  __IO uint32_t S2_CLRKEY_LOW[TINGPU_S2_CLRKEY_LOW_COUNT]; /**< S2 Color Key Low, array offset: 0x600, array step: 0x4 */
  __IO uint32_t S2_CLRKEY_HIGH[TINGPU_S2_CLRKEY_HIGH_COUNT]; /**< S2 Color Key High, array offset: 0x610, array step: 0x4 */
  __IO uint32_t S2_TRANSFORM_CTRL;                 /**< S2 Transform Control, offset: 0x620 */
  __IO uint32_t S2_PROJ_TF[TINGPU_S2_PROJ_TF_COUNT]; /**< S2 Projective Transform, array offset: 0x624, array step: 0x4 */
  __IO uint32_t S2_SCISSOR_CTRL[TINGPU_S2_SCISSOR_CTRL_COUNT]; /**< S2 Scissor Control, array offset: 0x648, array step: 0x4 */
  __IO uint32_t S2_SCISSOR_SIZE[TINGPU_S2_SCISSOR_SIZE_COUNT]; /**< S2 Scissor Size, array offset: 0x658, array step: 0x4 */
  __IO uint32_t COLOR_TRANSFORM_CTRL;              /**< Color Transform Control, offset: 0x668 */
  __IO uint32_t COLOR_TRANSFORM0;                  /**< Color Transform 0, offset: 0x66C */
  __IO uint32_t COLOR_TRANSFORM1;                  /**< Color Transform 1, offset: 0x670 */
  __IO uint32_t COLOR_TRANSFORM2;                  /**< Color Transform 2, offset: 0x674 */
  __IO uint32_t COLOR_TRANSFORM3;                  /**< Color Transform 3, offset: 0x678 */
  __IO uint32_t S2_CSC0;                           /**< S2 Color Space Conversion 0, offset: 0x67C */
  __IO uint32_t S2_CSC1;                           /**< S2 Color Space Conversion 1, offset: 0x680 */
  __IO uint32_t S2_CSC2;                           /**< S2 Color Space Conversion 2, offset: 0x684 */
  __IO uint32_t AXI_CACHE_CTRL;                    /**< AXI Cache Control, offset: 0x688 */
} TINGPU_Type;

/* ----------------------------------------------------------------------------
   -- TINGPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TINGPU_Register_Masks TINGPU Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define TINGPU_VERID_FEATURE_MASK                (0xFFFFU)
#define TINGPU_VERID_FEATURE_SHIFT               (0U)
/*! FEATURE - Feature Specification Number */
#define TINGPU_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_VERID_FEATURE_SHIFT)) & TINGPU_VERID_FEATURE_MASK)

#define TINGPU_VERID_MINOR_MASK                  (0xFF0000U)
#define TINGPU_VERID_MINOR_SHIFT                 (16U)
/*! MINOR - Minor Version Number */
#define TINGPU_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_VERID_MINOR_SHIFT)) & TINGPU_VERID_MINOR_MASK)

#define TINGPU_VERID_MAJOR_MASK                  (0xFF000000U)
#define TINGPU_VERID_MAJOR_SHIFT                 (24U)
/*! MAJOR - Major Version Number */
#define TINGPU_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_VERID_MAJOR_SHIFT)) & TINGPU_VERID_MAJOR_MASK)
/*! @} */

/*! @name GPU_CTRL - GPU Control */
/*! @{ */

#define TINGPU_GPU_CTRL_ENABLE_MASK              (0x1U)
#define TINGPU_GPU_CTRL_ENABLE_SHIFT             (0U)
/*! ENABLE - GPU Enable
 *  0b0..No operation.
 *  0b1..GPU operation is enabled.
 */
#define TINGPU_GPU_CTRL_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_GPU_CTRL_ENABLE_SHIFT)) & TINGPU_GPU_CTRL_ENABLE_MASK)

#define TINGPU_GPU_CTRL_SW_RST_MASK              (0x2U)
#define TINGPU_GPU_CTRL_SW_RST_SHIFT             (1U)
/*! SW_RST - Software Reset
 *  0b0..No reset.
 *  0b1..GPU is under software reset.
 */
#define TINGPU_GPU_CTRL_SW_RST(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_GPU_CTRL_SW_RST_SHIFT)) & TINGPU_GPU_CTRL_SW_RST_MASK)

#define TINGPU_GPU_CTRL_CTO_EN_MASK              (0x10000U)
#define TINGPU_GPU_CTRL_CTO_EN_SHIFT             (16U)
/*! CTO_EN - Command Execution Timeout Enable
 *  0b0..Disable timeout counter
 *  0b1..Enable timeout counter
 */
#define TINGPU_GPU_CTRL_CTO_EN(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_GPU_CTRL_CTO_EN_SHIFT)) & TINGPU_GPU_CTRL_CTO_EN_MASK)

#define TINGPU_GPU_CTRL_CTO_MASK                 (0x3E0000U)
#define TINGPU_GPU_CTRL_CTO_SHIFT                (17U)
/*! CTO - Command Timeout Cycles
 *  0b00000-0b11111..Timeout is 255*1, 255*2^1, 255*2^2, ..., 255*2^31 clock cycles.
 */
#define TINGPU_GPU_CTRL_CTO(x)                   (((uint32_t)(((uint32_t)(x)) << TINGPU_GPU_CTRL_CTO_SHIFT)) & TINGPU_GPU_CTRL_CTO_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable */
/*! @{ */

#define TINGPU_INTEN_IMP_OP_DONE_EN_MASK         (0x1U)
#define TINGPU_INTEN_IMP_OP_DONE_EN_SHIFT        (0U)
/*! IMP_OP_DONE_EN - Image Pipeline Operation Done Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define TINGPU_INTEN_IMP_OP_DONE_EN(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_INTEN_IMP_OP_DONE_EN_SHIFT)) & TINGPU_INTEN_IMP_OP_DONE_EN_MASK)

#define TINGPU_INTEN_CCDMA_EVENT_EN_MASK         (0x2U)
#define TINGPU_INTEN_CCDMA_EVENT_EN_SHIFT        (1U)
/*! CCDMA_EVENT_EN - CCDMA Event Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define TINGPU_INTEN_CCDMA_EVENT_EN(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_INTEN_CCDMA_EVENT_EN_SHIFT)) & TINGPU_INTEN_CCDMA_EVENT_EN_MASK)

#define TINGPU_INTEN_CCDMA_CMD_ERR_EN_MASK       (0x4U)
#define TINGPU_INTEN_CCDMA_CMD_ERR_EN_SHIFT      (2U)
/*! CCDMA_CMD_ERR_EN - CCDMA Command Error Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define TINGPU_INTEN_CCDMA_CMD_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_INTEN_CCDMA_CMD_ERR_EN_SHIFT)) & TINGPU_INTEN_CCDMA_CMD_ERR_EN_MASK)

#define TINGPU_INTEN_AXI_ERR_EN_MASK             (0x10U)
#define TINGPU_INTEN_AXI_ERR_EN_SHIFT            (4U)
/*! AXI_ERR_EN - AXI Error Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define TINGPU_INTEN_AXI_ERR_EN(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_INTEN_AXI_ERR_EN_SHIFT)) & TINGPU_INTEN_AXI_ERR_EN_MASK)

#define TINGPU_INTEN_CTO_ERR_EN_MASK             (0x20U)
#define TINGPU_INTEN_CTO_ERR_EN_SHIFT            (5U)
/*! CTO_ERR_EN - Command Timeout Error Interrupt Enable
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define TINGPU_INTEN_CTO_ERR_EN(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_INTEN_CTO_ERR_EN_SHIFT)) & TINGPU_INTEN_CTO_ERR_EN_MASK)
/*! @} */

/*! @name CCDMA_CTRL0 - Command/Control DMA Register 0 */
/*! @{ */

#define TINGPU_CCDMA_CTRL0_ENA_MASK              (0x1U)
#define TINGPU_CCDMA_CTRL0_ENA_SHIFT             (0U)
/*! ENA - Enable
 *  0b0..Disable CCDMA
 *  0b1..Enable CCDMA
 */
#define TINGPU_CCDMA_CTRL0_ENA(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_CTRL0_ENA_SHIFT)) & TINGPU_CCDMA_CTRL0_ENA_MASK)

#define TINGPU_CCDMA_CTRL0_ADDR_MASK             (0xFFFFFFF8U)
#define TINGPU_CCDMA_CTRL0_ADDR_SHIFT            (3U)
/*! ADDR - Address */
#define TINGPU_CCDMA_CTRL0_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_CTRL0_ADDR_SHIFT)) & TINGPU_CCDMA_CTRL0_ADDR_MASK)
/*! @} */

/*! @name CCDMA_CTRL1 - Command/Control DMA Register 1 */
/*! @{ */

#define TINGPU_CCDMA_CTRL1_HALT_MASK             (0x1U)
#define TINGPU_CCDMA_CTRL1_HALT_SHIFT            (0U)
/*! HALT - Halt
 *  0b0..No action
 *  0b1..Halt CCDMA running
 */
#define TINGPU_CCDMA_CTRL1_HALT(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_CTRL1_HALT_SHIFT)) & TINGPU_CCDMA_CTRL1_HALT_MASK)
/*! @} */

/*! @name CCDMA_WAIT - Command/Control Wait */
/*! @{ */

#define TINGPU_CCDMA_WAIT_DELAY_MASK             (0xFFFFU)
#define TINGPU_CCDMA_WAIT_DELAY_SHIFT            (0U)
/*! DELAY - Delay */
#define TINGPU_CCDMA_WAIT_DELAY(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_WAIT_DELAY_SHIFT)) & TINGPU_CCDMA_WAIT_DELAY_MASK)

#define TINGPU_CCDMA_WAIT_FFWD_MASK              (0x10000U)
#define TINGPU_CCDMA_WAIT_FFWD_SHIFT             (16U)
/*! FFWD - FFWD
 *  0b0..No action
 *  0b1..Expire WAIT timer and read the next command.
 */
#define TINGPU_CCDMA_WAIT_FFWD(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_WAIT_FFWD_SHIFT)) & TINGPU_CCDMA_WAIT_FFWD_MASK)
/*! @} */

/*! @name LPR - Low Power */
/*! @{ */

#define TINGPU_LPR_QREQ_MASK                     (0x1U)
#define TINGPU_LPR_QREQ_SHIFT                    (0U)
/*! QREQ - Q-Channel Request
 *  0b0..No action
 *  0b1..Quiescence request
 */
#define TINGPU_LPR_QREQ(x)                       (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_QREQ_SHIFT)) & TINGPU_LPR_QREQ_MASK)

#define TINGPU_LPR_QACCEPT_MASK                  (0x2U)
#define TINGPU_LPR_QACCEPT_SHIFT                 (1U)
/*! QACCEPT - Q-Channel Accept
 *  0b0..Q-Channel quiescence request is not accepted.
 *  0b1..Q-Channel quiescence request is accepted.
 */
#define TINGPU_LPR_QACCEPT(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_QACCEPT_SHIFT)) & TINGPU_LPR_QACCEPT_MASK)

#define TINGPU_LPR_QDENY_MASK                    (0x4U)
#define TINGPU_LPR_QDENY_SHIFT                   (2U)
/*! QDENY - Q-Channel Deny
 *  0b0..Q-Channel quiescence request is not denied.
 *  0b1..Q-Channel quiescence request is denied.
 */
#define TINGPU_LPR_QDENY(x)                      (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_QDENY_SHIFT)) & TINGPU_LPR_QDENY_MASK)

#define TINGPU_LPR_QACTIVE_MASK                  (0x8U)
#define TINGPU_LPR_QACTIVE_SHIFT                 (3U)
/*! QACTIVE - Q-Channel Active
 *  0b0..When QACTIVE is driven LOW it is a hint, not a guarantee, that the device might accept a quiescence request.
 *  0b1..When QACTIVE is driven HIGH in any state to indicate that it has operations to perform.
 */
#define TINGPU_LPR_QACTIVE(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_QACTIVE_SHIFT)) & TINGPU_LPR_QACTIVE_MASK)

#define TINGPU_LPR_CLK_GATE_EN_MASK              (0x10U)
#define TINGPU_LPR_CLK_GATE_EN_SHIFT             (4U)
/*! CLK_GATE_EN - Clock Gating Enable
 *  0b0..Clock gating is disabled
 *  0b1..Clock gating is enabled
 */
#define TINGPU_LPR_CLK_GATE_EN(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_CLK_GATE_EN_SHIFT)) & TINGPU_LPR_CLK_GATE_EN_MASK)

#define TINGPU_LPR_QCHAN_SEL_MASK                (0x20U)
#define TINGPU_LPR_QCHAN_SEL_SHIFT               (5U)
/*! QCHAN_SEL - Q-Channel Select
 *  0b0..Selects SoC interface signals for Q-Channel.
 *  0b1..Selects register signals for Q-Channel.
 */
#define TINGPU_LPR_QCHAN_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_QCHAN_SEL_SHIFT)) & TINGPU_LPR_QCHAN_SEL_MASK)

#define TINGPU_LPR_QDENY_DIS_MASK                (0x40U)
#define TINGPU_LPR_QDENY_DIS_SHIFT               (6U)
/*! QDENY_DIS - QDENY Disable
 *  0b0..Supports QDENY signal. If QREQ asserts, GPU can enter Q_DENIED state when it is busy, and asserts QDENY.
 *       SoC need to deassert QREQ to abort from Q_DENIED state before next operation.
 *  0b1..QDENY keeps low, and no Q_DENIED state inside.
 */
#define TINGPU_LPR_QDENY_DIS(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_QDENY_DIS_SHIFT)) & TINGPU_LPR_QDENY_DIS_MASK)

#define TINGPU_LPR_IPS_CG_DIS_MASK               (0x100U)
#define TINGPU_LPR_IPS_CG_DIS_SHIFT              (8U)
/*! IPS_CG_DIS - IPS Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_IPS_CG_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_IPS_CG_DIS_SHIFT)) & TINGPU_LPR_IPS_CG_DIS_MASK)

#define TINGPU_LPR_CCDMA_CG_DIS_MASK             (0x200U)
#define TINGPU_LPR_CCDMA_CG_DIS_SHIFT            (9U)
/*! CCDMA_CG_DIS - CCDMA Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_CCDMA_CG_DIS(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_CCDMA_CG_DIS_SHIFT)) & TINGPU_LPR_CCDMA_CG_DIS_MASK)

#define TINGPU_LPR_MASK_CG_DIS_MASK              (0x400U)
#define TINGPU_LPR_MASK_CG_DIS_SHIFT             (10U)
/*! MASK_CG_DIS - Mask Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_MASK_CG_DIS(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_MASK_CG_DIS_SHIFT)) & TINGPU_LPR_MASK_CG_DIS_MASK)

#define TINGPU_LPR_S1_CG_DIS_MASK                (0x800U)
#define TINGPU_LPR_S1_CG_DIS_SHIFT               (11U)
/*! S1_CG_DIS - S1 Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_S1_CG_DIS(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_S1_CG_DIS_SHIFT)) & TINGPU_LPR_S1_CG_DIS_MASK)

#define TINGPU_LPR_S2_CG_DIS_MASK                (0x1000U)
#define TINGPU_LPR_S2_CG_DIS_SHIFT               (12U)
/*! S2_CG_DIS - S2 Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_S2_CG_DIS(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_S2_CG_DIS_SHIFT)) & TINGPU_LPR_S2_CG_DIS_MASK)

#define TINGPU_LPR_DST_CG_DIS_MASK               (0x2000U)
#define TINGPU_LPR_DST_CG_DIS_SHIFT              (13U)
/*! DST_CG_DIS - DST Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_DST_CG_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_DST_CG_DIS_SHIFT)) & TINGPU_LPR_DST_CG_DIS_MASK)

#define TINGPU_LPR_AXI_CG_DIS_MASK               (0x4000U)
#define TINGPU_LPR_AXI_CG_DIS_SHIFT              (14U)
/*! AXI_CG_DIS - AXI Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_AXI_CG_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_AXI_CG_DIS_SHIFT)) & TINGPU_LPR_AXI_CG_DIS_MASK)

#define TINGPU_LPR_IBCRAM_CG_DIS_MASK            (0x10000U)
#define TINGPU_LPR_IBCRAM_CG_DIS_SHIFT           (16U)
/*! IBCRAM_CG_DIS - IBCRAM Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_IBCRAM_CG_DIS(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_IBCRAM_CG_DIS_SHIFT)) & TINGPU_LPR_IBCRAM_CG_DIS_MASK)

#define TINGPU_LPR_LUTRAM_CG_DIS_MASK            (0x20000U)
#define TINGPU_LPR_LUTRAM_CG_DIS_SHIFT           (17U)
/*! LUTRAM_CG_DIS - LUTRAM Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_LUTRAM_CG_DIS(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_LUTRAM_CG_DIS_SHIFT)) & TINGPU_LPR_LUTRAM_CG_DIS_MASK)

#define TINGPU_LPR_MASKRAM_CG_DIS_MASK           (0x40000U)
#define TINGPU_LPR_MASKRAM_CG_DIS_SHIFT          (18U)
/*! MASKRAM_CG_DIS - MASKRAM Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_MASKRAM_CG_DIS(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_MASKRAM_CG_DIS_SHIFT)) & TINGPU_LPR_MASKRAM_CG_DIS_MASK)

#define TINGPU_LPR_S1RAM_CG_DIS_MASK             (0x80000U)
#define TINGPU_LPR_S1RAM_CG_DIS_SHIFT            (19U)
/*! S1RAM_CG_DIS - S1RAM Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_S1RAM_CG_DIS(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_S1RAM_CG_DIS_SHIFT)) & TINGPU_LPR_S1RAM_CG_DIS_MASK)

#define TINGPU_LPR_DSTRAM_CG_DIS_MASK            (0x100000U)
#define TINGPU_LPR_DSTRAM_CG_DIS_SHIFT           (20U)
/*! DSTRAM_CG_DIS - DSTRAM Clock Gating Disable
 *  0b0..The clock gating is controlled by CLK_GATE_EN.
 *  0b1..The clock gating is disabled, which means clock is always on.
 */
#define TINGPU_LPR_DSTRAM_CG_DIS(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_LPR_DSTRAM_CG_DIS_SHIFT)) & TINGPU_LPR_DSTRAM_CG_DIS_MASK)
/*! @} */

/*! @name INTR - Interrupt */
/*! @{ */

#define TINGPU_INTR_IMP_OP_DONE_MASK             (0x1U)
#define TINGPU_INTR_IMP_OP_DONE_SHIFT            (0U)
/*! IMP_OP_DONE - Image Pipeline Operation Done Interrupt
 *  0b0..Frame is not done.
 *  0b1..Frame is done.
 */
#define TINGPU_INTR_IMP_OP_DONE(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_INTR_IMP_OP_DONE_SHIFT)) & TINGPU_INTR_IMP_OP_DONE_MASK)

#define TINGPU_INTR_CCDMA_EVENT_MASK             (0x2U)
#define TINGPU_INTR_CCDMA_EVENT_SHIFT            (1U)
/*! CCDMA_EVENT - CCDMA Event Interrupt
 *  0b0..No event
 *  0b1..Event occurs
 */
#define TINGPU_INTR_CCDMA_EVENT(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_INTR_CCDMA_EVENT_SHIFT)) & TINGPU_INTR_CCDMA_EVENT_MASK)

#define TINGPU_INTR_CCDMA_CMD_ERR_MASK           (0x4U)
#define TINGPU_INTR_CCDMA_CMD_ERR_SHIFT          (2U)
/*! CCDMA_CMD_ERR - CCDMA Command Error Interrupt
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_INTR_CCDMA_CMD_ERR(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_INTR_CCDMA_CMD_ERR_SHIFT)) & TINGPU_INTR_CCDMA_CMD_ERR_MASK)

#define TINGPU_INTR_AXI_ERR_MASK                 (0x10U)
#define TINGPU_INTR_AXI_ERR_SHIFT                (4U)
/*! AXI_ERR - AXI Error Interrupt
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_INTR_AXI_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << TINGPU_INTR_AXI_ERR_SHIFT)) & TINGPU_INTR_AXI_ERR_MASK)

#define TINGPU_INTR_CTO_ERR_MASK                 (0x20U)
#define TINGPU_INTR_CTO_ERR_SHIFT                (5U)
/*! CTO_ERR - Command Timeout Interrupt
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_INTR_CTO_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << TINGPU_INTR_CTO_ERR_SHIFT)) & TINGPU_INTR_CTO_ERR_MASK)
/*! @} */

/*! @name CCDMA_STAT - Command/Control Status */
/*! @{ */

#define TINGPU_CCDMA_STAT_STATE_MASK             (0x7U)
#define TINGPU_CCDMA_STAT_STATE_SHIFT            (0U)
/*! STATE - CCDMA States
 *  0b000..IDLE: not yet enabled or finished (END executed)
 *  0b001..RUN: normal operating condition fetching a command, or executing a simple command, like LINK, RUN, or EVENT
 *  0b010..WAITING: executed a wait command, waiting until timer expires to read next command
 *  0b011..LOAD: in process of reading AXI and writing to GPU register(s)
 *  0b100..SAVE: in process of reading GPU register(s) and writing to AXI
 *  0b101..PAUSED: waiting until IMG pipeline has completed before continuing execution
 *  0b110..HALTED: command execution suspended until the HALT bit is negated
 *  0b111..reserved
 */
#define TINGPU_CCDMA_STAT_STATE(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_STAT_STATE_SHIFT)) & TINGPU_CCDMA_STAT_STATE_MASK)

#define TINGPU_CCDMA_STAT_LCE_MASK               (0xFFFFFFF8U)
#define TINGPU_CCDMA_STAT_LCE_SHIFT              (3U)
/*! LCE - Last Command Execution */
#define TINGPU_CCDMA_STAT_LCE(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_STAT_LCE_SHIFT)) & TINGPU_CCDMA_STAT_LCE_MASK)
/*! @} */

/*! @name CCDMA_EVT - Command/Control Event */
/*! @{ */

#define TINGPU_CCDMA_EVT_MSG_MASK                (0xFFFFFFFFU)
#define TINGPU_CCDMA_EVT_MSG_SHIFT               (0U)
/*! MSG - Message */
#define TINGPU_CCDMA_EVT_MSG(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_EVT_MSG_SHIFT)) & TINGPU_CCDMA_EVT_MSG_MASK)
/*! @} */

/*! @name CCDMA_CTX - Command/Control CTX */
/*! @{ */

#define TINGPU_CCDMA_CTX_PARTIAL_MASK            (0x1U)
#define TINGPU_CCDMA_CTX_PARTIAL_SHIFT           (0U)
/*! PARTIAL - Partial
 *  0b0..A command was not executed after the last LOADNREG command.
 *  0b1..A command was executed after the last LOADNREG command.
 */
#define TINGPU_CCDMA_CTX_PARTIAL(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_CTX_PARTIAL_SHIFT)) & TINGPU_CCDMA_CTX_PARTIAL_MASK)

#define TINGPU_CCDMA_CTX_LAST_CTX_MASK           (0xFFFFFFFCU)
#define TINGPU_CCDMA_CTX_LAST_CTX_SHIFT          (2U)
/*! LAST_CTX - Last CTX */
#define TINGPU_CCDMA_CTX_LAST_CTX(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_CCDMA_CTX_LAST_CTX_SHIFT)) & TINGPU_CCDMA_CTX_LAST_CTX_MASK)
/*! @} */

/*! @name STS0 - Status Register 0 */
/*! @{ */

#define TINGPU_STS0_CCDMA_READ_ERR_MASK          (0x1U)
#define TINGPU_STS0_CCDMA_READ_ERR_SHIFT         (0U)
/*! CCDMA_READ_ERR - CCDMA Read Error
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_STS0_CCDMA_READ_ERR(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_CCDMA_READ_ERR_SHIFT)) & TINGPU_STS0_CCDMA_READ_ERR_MASK)

#define TINGPU_STS0_S1_READ_ERR_MASK             (0x2U)
#define TINGPU_STS0_S1_READ_ERR_SHIFT            (1U)
/*! S1_READ_ERR - S1 Read Error
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_STS0_S1_READ_ERR(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_S1_READ_ERR_SHIFT)) & TINGPU_STS0_S1_READ_ERR_MASK)

#define TINGPU_STS0_S2_READ_ERR_MASK             (0x4U)
#define TINGPU_STS0_S2_READ_ERR_SHIFT            (2U)
/*! S2_READ_ERR - S2 Read Error
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_STS0_S2_READ_ERR(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_S2_READ_ERR_SHIFT)) & TINGPU_STS0_S2_READ_ERR_MASK)

#define TINGPU_STS0_MASK_READ_ERR_MASK           (0x8U)
#define TINGPU_STS0_MASK_READ_ERR_SHIFT          (3U)
/*! MASK_READ_ERR - Mask Read Error
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_STS0_MASK_READ_ERR(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_MASK_READ_ERR_SHIFT)) & TINGPU_STS0_MASK_READ_ERR_MASK)

#define TINGPU_STS0_CCDMA_WRITE_ERR_MASK         (0x10U)
#define TINGPU_STS0_CCDMA_WRITE_ERR_SHIFT        (4U)
/*! CCDMA_WRITE_ERR - CCDMA Write Error
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_STS0_CCDMA_WRITE_ERR(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_CCDMA_WRITE_ERR_SHIFT)) & TINGPU_STS0_CCDMA_WRITE_ERR_MASK)

#define TINGPU_STS0_DST_WRITE_ERR_MASK           (0x20U)
#define TINGPU_STS0_DST_WRITE_ERR_SHIFT          (5U)
/*! DST_WRITE_ERR - Destination Write Error
 *  0b0..No error
 *  0b1..Error occurs
 */
#define TINGPU_STS0_DST_WRITE_ERR(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_DST_WRITE_ERR_SHIFT)) & TINGPU_STS0_DST_WRITE_ERR_MASK)

#define TINGPU_STS0_WRITE_PENDING_MASK           (0x1F0000U)
#define TINGPU_STS0_WRITE_PENDING_SHIFT          (16U)
/*! WRITE_PENDING - Write Pending */
#define TINGPU_STS0_WRITE_PENDING(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_STS0_WRITE_PENDING_SHIFT)) & TINGPU_STS0_WRITE_PENDING_MASK)
/*! @} */

/*! @name COLOR_LUT - Color LUT */
/*! @{ */

#define TINGPU_COLOR_LUT_COLOR_MASK              (0xFFFFFFFFU)
#define TINGPU_COLOR_LUT_COLOR_SHIFT             (0U)
/*! COLOR - Color in LUT */
#define TINGPU_COLOR_LUT_COLOR(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_LUT_COLOR_SHIFT)) & TINGPU_COLOR_LUT_COLOR_MASK)
/*! @} */

/*! @name DST_FILL_DATA - Destination Fill Data */
/*! @{ */

#define TINGPU_DST_FILL_DATA_COLOR_MASK          (0xFFFFFFFFU)
#define TINGPU_DST_FILL_DATA_COLOR_SHIFT         (0U)
/*! COLOR - Color */
#define TINGPU_DST_FILL_DATA_COLOR(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_FILL_DATA_COLOR_SHIFT)) & TINGPU_DST_FILL_DATA_COLOR_MASK)
/*! @} */

/*! @name DST_CTRL - Destination Control */
/*! @{ */

#define TINGPU_DST_CTRL_FILL_EN_MASK             (0x1U)
#define TINGPU_DST_CTRL_FILL_EN_SHIFT            (0U)
/*! FILL_EN - Fill Enable
 *  0b0..No fill operation
 *  0b1..Fill operation is enabled
 */
#define TINGPU_DST_CTRL_FILL_EN(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_FILL_EN_SHIFT)) & TINGPU_DST_CTRL_FILL_EN_MASK)

#define TINGPU_DST_CTRL_PREMULTIPLY_MASK         (0x2U)
#define TINGPU_DST_CTRL_PREMULTIPLY_SHIFT        (1U)
/*! PREMULTIPLY - Premultiply
 *  0b0..Destination channel is not premultiplied.
 *  0b1..Destination channel is premultiplied.
 */
#define TINGPU_DST_CTRL_PREMULTIPLY(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_PREMULTIPLY_SHIFT)) & TINGPU_DST_CTRL_PREMULTIPLY_MASK)

#define TINGPU_DST_CTRL_GAMMA_MASK               (0x4U)
#define TINGPU_DST_CTRL_GAMMA_SHIFT              (2U)
/*! GAMMA - Enable Gamma Correction Function
 *  0b0..DST gamma correction function is disabled.
 *  0b1..DST gamma correction function is enabled.
 */
#define TINGPU_DST_CTRL_GAMMA(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_GAMMA_SHIFT)) & TINGPU_DST_CTRL_GAMMA_MASK)

#define TINGPU_DST_CTRL_WBUF_BYPASS_MASK         (0x8U)
#define TINGPU_DST_CTRL_WBUF_BYPASS_SHIFT        (3U)
/*! WBUF_BYPASS - Write Buffer Bypass
 *  0b0..Write buffer is enabled.
 *  0b1..Write buffer is bypassed.
 */
#define TINGPU_DST_CTRL_WBUF_BYPASS(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_WBUF_BYPASS_SHIFT)) & TINGPU_DST_CTRL_WBUF_BYPASS_MASK)

#define TINGPU_DST_CTRL_WORD_WIDTH_MASK          (0x70U)
#define TINGPU_DST_CTRL_WORD_WIDTH_SHIFT         (4U)
/*! WORD_WIDTH - Pixel Word Width
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..24
 *  0b110..32
 *  0b111..Reserved
 */
#define TINGPU_DST_CTRL_WORD_WIDTH(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_WORD_WIDTH_SHIFT)) & TINGPU_DST_CTRL_WORD_WIDTH_MASK)

#define TINGPU_DST_CTRL_TYPE2_MASK               (0xF00U)
#define TINGPU_DST_CTRL_TYPE2_SHIFT              (8U)
/*! TYPE2 - Color Format Type 2 */
#define TINGPU_DST_CTRL_TYPE2(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_TYPE2_SHIFT)) & TINGPU_DST_CTRL_TYPE2_MASK)

#define TINGPU_DST_CTRL_TYPE1_MASK               (0x3000U)
#define TINGPU_DST_CTRL_TYPE1_SHIFT              (12U)
/*! TYPE1 - Color Format Type 1
 *  0b00..RGBA
 *  0b01..reserved
 *  0b10..YUV
 *  0b11..COMPRESSED
 */
#define TINGPU_DST_CTRL_TYPE1(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CTRL_TYPE1_SHIFT)) & TINGPU_DST_CTRL_TYPE1_MASK)
/*! @} */

/*! @name DST_COLOR_SHIFT - Destination Color Shift */
/*! @{ */

#define TINGPU_DST_COLOR_SHIFT_A_SHIFT_MASK      (0x1FU)
#define TINGPU_DST_COLOR_SHIFT_A_SHIFT_SHIFT     (0U)
/*! A_SHIFT - Alpha Shift */
#define TINGPU_DST_COLOR_SHIFT_A_SHIFT(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_SHIFT_A_SHIFT_SHIFT)) & TINGPU_DST_COLOR_SHIFT_A_SHIFT_MASK)

#define TINGPU_DST_COLOR_SHIFT_B_SHIFT_MASK      (0x1F00U)
#define TINGPU_DST_COLOR_SHIFT_B_SHIFT_SHIFT     (8U)
/*! B_SHIFT - Blue Shift */
#define TINGPU_DST_COLOR_SHIFT_B_SHIFT(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_SHIFT_B_SHIFT_SHIFT)) & TINGPU_DST_COLOR_SHIFT_B_SHIFT_MASK)

#define TINGPU_DST_COLOR_SHIFT_G_SHIFT_MASK      (0x1F0000U)
#define TINGPU_DST_COLOR_SHIFT_G_SHIFT_SHIFT     (16U)
/*! G_SHIFT - Green Shift */
#define TINGPU_DST_COLOR_SHIFT_G_SHIFT(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_SHIFT_G_SHIFT_SHIFT)) & TINGPU_DST_COLOR_SHIFT_G_SHIFT_MASK)

#define TINGPU_DST_COLOR_SHIFT_R_SHIFT_MASK      (0x1F000000U)
#define TINGPU_DST_COLOR_SHIFT_R_SHIFT_SHIFT     (24U)
/*! R_SHIFT - Red Shift */
#define TINGPU_DST_COLOR_SHIFT_R_SHIFT(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_SHIFT_R_SHIFT_SHIFT)) & TINGPU_DST_COLOR_SHIFT_R_SHIFT_MASK)
/*! @} */

/*! @name DST_COLOR_BITS - Destination Color Bits */
/*! @{ */

#define TINGPU_DST_COLOR_BITS_A_WIDTH_MASK       (0xFU)
#define TINGPU_DST_COLOR_BITS_A_WIDTH_SHIFT      (0U)
/*! A_WIDTH - Alpha Width */
#define TINGPU_DST_COLOR_BITS_A_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_BITS_A_WIDTH_SHIFT)) & TINGPU_DST_COLOR_BITS_A_WIDTH_MASK)

#define TINGPU_DST_COLOR_BITS_B_WIDTH_MASK       (0xF00U)
#define TINGPU_DST_COLOR_BITS_B_WIDTH_SHIFT      (8U)
/*! B_WIDTH - Blue Width */
#define TINGPU_DST_COLOR_BITS_B_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_BITS_B_WIDTH_SHIFT)) & TINGPU_DST_COLOR_BITS_B_WIDTH_MASK)

#define TINGPU_DST_COLOR_BITS_G_WIDTH_MASK       (0xF0000U)
#define TINGPU_DST_COLOR_BITS_G_WIDTH_SHIFT      (16U)
/*! G_WIDTH - Green Width */
#define TINGPU_DST_COLOR_BITS_G_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_BITS_G_WIDTH_SHIFT)) & TINGPU_DST_COLOR_BITS_G_WIDTH_MASK)

#define TINGPU_DST_COLOR_BITS_R_WIDTH_MASK       (0xF000000U)
#define TINGPU_DST_COLOR_BITS_R_WIDTH_SHIFT      (24U)
/*! R_WIDTH - Red Width */
#define TINGPU_DST_COLOR_BITS_R_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_COLOR_BITS_R_WIDTH_SHIFT)) & TINGPU_DST_COLOR_BITS_R_WIDTH_MASK)
/*! @} */

/*! @name DST_SIZE - Destination Size */
/*! @{ */

#define TINGPU_DST_SIZE_WIDTH_MASK               (0x1FFFU)
#define TINGPU_DST_SIZE_WIDTH_SHIFT              (0U)
/*! WIDTH - Width */
#define TINGPU_DST_SIZE_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_SIZE_WIDTH_SHIFT)) & TINGPU_DST_SIZE_WIDTH_MASK)

#define TINGPU_DST_SIZE_HEIGHT_MASK              (0x1FFF0000U)
#define TINGPU_DST_SIZE_HEIGHT_SHIFT             (16U)
/*! HEIGHT - Height */
#define TINGPU_DST_SIZE_HEIGHT(x)                (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_SIZE_HEIGHT_SHIFT)) & TINGPU_DST_SIZE_HEIGHT_MASK)
/*! @} */

/*! @name DST_ADDR - Destination Address */
/*! @{ */

#define TINGPU_DST_ADDR_ADDR_MASK                (0xFFFFFFFFU)
#define TINGPU_DST_ADDR_ADDR_SHIFT               (0U)
/*! ADDR - Destination Plane Address */
#define TINGPU_DST_ADDR_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_ADDR_ADDR_SHIFT)) & TINGPU_DST_ADDR_ADDR_MASK)
/*! @} */

/*! @name DST_STRIDE - Destination Stride */
/*! @{ */

#define TINGPU_DST_STRIDE_STRIDE_MASK            (0xFFFFU)
#define TINGPU_DST_STRIDE_STRIDE_SHIFT           (0U)
/*! STRIDE - Destination Plane Stride */
#define TINGPU_DST_STRIDE_STRIDE(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_STRIDE_STRIDE_SHIFT)) & TINGPU_DST_STRIDE_STRIDE_MASK)
/*! @} */

/*! @name DST_SIGN0 - Destination Signed 0 */
/*! @{ */

#define TINGPU_DST_SIGN0_OUTPUT_SIGNED_EN_MASK   (0x1U)
#define TINGPU_DST_SIGN0_OUTPUT_SIGNED_EN_SHIFT  (0U)
/*! OUTPUT_SIGNED_EN - Output Signed Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TINGPU_DST_SIGN0_OUTPUT_SIGNED_EN(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_SIGN0_OUTPUT_SIGNED_EN_SHIFT)) & TINGPU_DST_SIGN0_OUTPUT_SIGNED_EN_MASK)

#define TINGPU_DST_SIGN0_ZERO_POINT_MASK         (0xFFFF0000U)
#define TINGPU_DST_SIGN0_ZERO_POINT_SHIFT        (16U)
/*! ZERO_POINT - Zero Point */
#define TINGPU_DST_SIGN0_ZERO_POINT(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_SIGN0_ZERO_POINT_SHIFT)) & TINGPU_DST_SIGN0_ZERO_POINT_MASK)
/*! @} */

/*! @name DST_SIGN1 - Destination Signed 1 */
/*! @{ */

#define TINGPU_DST_SIGN1_INV_SCALE_INT_MASK      (0x3FFFFU)
#define TINGPU_DST_SIGN1_INV_SCALE_INT_SHIFT     (0U)
/*! INV_SCALE_INT - Inv Scale Int */
#define TINGPU_DST_SIGN1_INV_SCALE_INT(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_SIGN1_INV_SCALE_INT_SHIFT)) & TINGPU_DST_SIGN1_INV_SCALE_INT_MASK)
/*! @} */

/*! @name DST_CSC0 - Destination Color Space Conversion 0 */
/*! @{ */

#define TINGPU_DST_CSC0_A1_MASK                  (0x7FFU)
#define TINGPU_DST_CSC0_A1_SHIFT                 (0U)
/*! A1 - A1 */
#define TINGPU_DST_CSC0_A1(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC0_A1_SHIFT)) & TINGPU_DST_CSC0_A1_MASK)

#define TINGPU_DST_CSC0_A2_MASK                  (0x7FF0000U)
#define TINGPU_DST_CSC0_A2_SHIFT                 (16U)
/*! A2 - A2 */
#define TINGPU_DST_CSC0_A2(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC0_A2_SHIFT)) & TINGPU_DST_CSC0_A2_MASK)
/*! @} */

/*! @name DST_CSC1 - Destination Color Space Conversion 1 */
/*! @{ */

#define TINGPU_DST_CSC1_A3_MASK                  (0x7FFU)
#define TINGPU_DST_CSC1_A3_SHIFT                 (0U)
/*! A3 - A3 */
#define TINGPU_DST_CSC1_A3(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC1_A3_SHIFT)) & TINGPU_DST_CSC1_A3_MASK)

#define TINGPU_DST_CSC1_B1_MASK                  (0x7FF0000U)
#define TINGPU_DST_CSC1_B1_SHIFT                 (16U)
/*! B1 - B1 */
#define TINGPU_DST_CSC1_B1(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC1_B1_SHIFT)) & TINGPU_DST_CSC1_B1_MASK)
/*! @} */

/*! @name DST_CSC2 - Destination Color Space Conversion 2 */
/*! @{ */

#define TINGPU_DST_CSC2_B2_MASK                  (0x7FFU)
#define TINGPU_DST_CSC2_B2_SHIFT                 (0U)
/*! B2 - B2 */
#define TINGPU_DST_CSC2_B2(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC2_B2_SHIFT)) & TINGPU_DST_CSC2_B2_MASK)

#define TINGPU_DST_CSC2_B3_MASK                  (0x7FF0000U)
#define TINGPU_DST_CSC2_B3_SHIFT                 (16U)
/*! B3 - B3 */
#define TINGPU_DST_CSC2_B3(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC2_B3_SHIFT)) & TINGPU_DST_CSC2_B3_MASK)
/*! @} */

/*! @name DST_CSC3 - Destination Color Space Conversion 3 */
/*! @{ */

#define TINGPU_DST_CSC3_C1_MASK                  (0x7FFU)
#define TINGPU_DST_CSC3_C1_SHIFT                 (0U)
/*! C1 - C1 */
#define TINGPU_DST_CSC3_C1(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC3_C1_SHIFT)) & TINGPU_DST_CSC3_C1_MASK)

#define TINGPU_DST_CSC3_C2_MASK                  (0x7FF0000U)
#define TINGPU_DST_CSC3_C2_SHIFT                 (16U)
/*! C2 - C2 */
#define TINGPU_DST_CSC3_C2(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC3_C2_SHIFT)) & TINGPU_DST_CSC3_C2_MASK)
/*! @} */

/*! @name DST_CSC4 - Destination Color Space Conversion 4 */
/*! @{ */

#define TINGPU_DST_CSC4_C3_MASK                  (0x7FFU)
#define TINGPU_DST_CSC4_C3_SHIFT                 (0U)
/*! C3 - C3 */
#define TINGPU_DST_CSC4_C3(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC4_C3_SHIFT)) & TINGPU_DST_CSC4_C3_MASK)

#define TINGPU_DST_CSC4_D1_MASK                  (0x1FF0000U)
#define TINGPU_DST_CSC4_D1_SHIFT                 (16U)
/*! D1 - D1 */
#define TINGPU_DST_CSC4_D1(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC4_D1_SHIFT)) & TINGPU_DST_CSC4_D1_MASK)
/*! @} */

/*! @name DST_CSC5 - Destination Color Space Conversion 5 */
/*! @{ */

#define TINGPU_DST_CSC5_D2_MASK                  (0x1FFU)
#define TINGPU_DST_CSC5_D2_SHIFT                 (0U)
/*! D2 - D2 */
#define TINGPU_DST_CSC5_D2(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC5_D2_SHIFT)) & TINGPU_DST_CSC5_D2_MASK)

#define TINGPU_DST_CSC5_D3_MASK                  (0x1FF0000U)
#define TINGPU_DST_CSC5_D3_SHIFT                 (16U)
/*! D3 - D3 */
#define TINGPU_DST_CSC5_D3(x)                    (((uint32_t)(((uint32_t)(x)) << TINGPU_DST_CSC5_D3_SHIFT)) & TINGPU_DST_CSC5_D3_MASK)
/*! @} */

/*! @name DITHER_CTRL - Dithering Control */
/*! @{ */

#define TINGPU_DITHER_CTRL_DITHER_EN_MASK        (0x1U)
#define TINGPU_DITHER_CTRL_DITHER_EN_SHIFT       (0U)
/*! DITHER_EN - Dithering Enable
 *  0b0..Dithering mode is disabled.
 *  0b1..Dithering mode is enabled.
 */
#define TINGPU_DITHER_CTRL_DITHER_EN(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_DITHER_EN_SHIFT)) & TINGPU_DITHER_CTRL_DITHER_EN_MASK)

#define TINGPU_DITHER_CTRL_ORDER_MATRIX_TYPE_MASK (0x30U)
#define TINGPU_DITHER_CTRL_ORDER_MATRIX_TYPE_SHIFT (4U)
/*! ORDER_MATRIX_TYPE - Order Matrix Type
 *  0b00..2x2 matrix.
 *  0b01..4x4 matrix.
 *  0b10..8x8 matrix.
 *  0b11..16x16 matrix.
 */
#define TINGPU_DITHER_CTRL_ORDER_MATRIX_TYPE(x)  (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_ORDER_MATRIX_TYPE_SHIFT)) & TINGPU_DITHER_CTRL_ORDER_MATRIX_TYPE_MASK)

#define TINGPU_DITHER_CTRL_ORDER_SCALE_FACTOR_BW_MASK (0xC000U)
#define TINGPU_DITHER_CTRL_ORDER_SCALE_FACTOR_BW_SHIFT (14U)
/*! ORDER_SCALE_FACTOR_BW - Order Scale Factor BW */
#define TINGPU_DITHER_CTRL_ORDER_SCALE_FACTOR_BW(x) (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_ORDER_SCALE_FACTOR_BW_SHIFT)) & TINGPU_DITHER_CTRL_ORDER_SCALE_FACTOR_BW_MASK)

#define TINGPU_DITHER_CTRL_ORDER_SCALE_A_MASK    (0xF0000U)
#define TINGPU_DITHER_CTRL_ORDER_SCALE_A_SHIFT   (16U)
/*! ORDER_SCALE_A - Order Scale Alpha */
#define TINGPU_DITHER_CTRL_ORDER_SCALE_A(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_ORDER_SCALE_A_SHIFT)) & TINGPU_DITHER_CTRL_ORDER_SCALE_A_MASK)

#define TINGPU_DITHER_CTRL_ORDER_SCALE_B_MASK    (0xF00000U)
#define TINGPU_DITHER_CTRL_ORDER_SCALE_B_SHIFT   (20U)
/*! ORDER_SCALE_B - Order Scale Blue */
#define TINGPU_DITHER_CTRL_ORDER_SCALE_B(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_ORDER_SCALE_B_SHIFT)) & TINGPU_DITHER_CTRL_ORDER_SCALE_B_MASK)

#define TINGPU_DITHER_CTRL_ORDER_SCALE_G_MASK    (0xF000000U)
#define TINGPU_DITHER_CTRL_ORDER_SCALE_G_SHIFT   (24U)
/*! ORDER_SCALE_G - Order Scale Green */
#define TINGPU_DITHER_CTRL_ORDER_SCALE_G(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_ORDER_SCALE_G_SHIFT)) & TINGPU_DITHER_CTRL_ORDER_SCALE_G_MASK)

#define TINGPU_DITHER_CTRL_ORDER_SCALE_R_MASK    (0xF0000000U)
#define TINGPU_DITHER_CTRL_ORDER_SCALE_R_SHIFT   (28U)
/*! ORDER_SCALE_R - Order Scale Red
 *  0b0000..1/128
 *  0b0001..1/64
 *  0b0010..1/32
 *  0b0011..1/16
 *  0b0100..1/8
 *  0b0101..1/4
 *  0b0110..1/2
 *  0b0111..1
 *  0b1000..2
 *  0b1001..4
 *  0b1010..8
 *  0b1011..16
 *  0b1100-0b1111..32
 */
#define TINGPU_DITHER_CTRL_ORDER_SCALE_R(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_DITHER_CTRL_ORDER_SCALE_R_SHIFT)) & TINGPU_DITHER_CTRL_ORDER_SCALE_R_MASK)
/*! @} */

/*! @name S1_CTRL - S1 Control */
/*! @{ */

#define TINGPU_S1_CTRL_EN_MASK                   (0x1U)
#define TINGPU_S1_CTRL_EN_SHIFT                  (0U)
/*! EN - Enable S1 channel
 *  0b0..S1 channel is disabled.
 *  0b1..S1 channel is enabled.
 */
#define TINGPU_S1_CTRL_EN(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_EN_SHIFT)) & TINGPU_S1_CTRL_EN_MASK)

#define TINGPU_S1_CTRL_PREMULTIPLY_MASK          (0x2U)
#define TINGPU_S1_CTRL_PREMULTIPLY_SHIFT         (1U)
/*! PREMULTIPLY - Premultiply
 *  0b0..S1 channel is not premultiplied.
 *  0b1..S1 channel is premultiplied.
 */
#define TINGPU_S1_CTRL_PREMULTIPLY(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_PREMULTIPLY_SHIFT)) & TINGPU_S1_CTRL_PREMULTIPLY_MASK)

#define TINGPU_S1_CTRL_GAMMA_MASK                (0x4U)
#define TINGPU_S1_CTRL_GAMMA_SHIFT               (2U)
/*! GAMMA - Enable Gamma Correction Function
 *  0b0..S1 gamma correction function is disabled.
 *  0b1..S1 gamma correction function is enabled.
 */
#define TINGPU_S1_CTRL_GAMMA(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_GAMMA_SHIFT)) & TINGPU_S1_CTRL_GAMMA_MASK)

#define TINGPU_S1_CTRL_WORD_WIDTH_MASK           (0x70U)
#define TINGPU_S1_CTRL_WORD_WIDTH_SHIFT          (4U)
/*! WORD_WIDTH - Pixel Word Width
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..24
 *  0b110..32
 *  0b111..Reserved
 */
#define TINGPU_S1_CTRL_WORD_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_WORD_WIDTH_SHIFT)) & TINGPU_S1_CTRL_WORD_WIDTH_MASK)

#define TINGPU_S1_CTRL_TYPE2_MASK                (0xF00U)
#define TINGPU_S1_CTRL_TYPE2_SHIFT               (8U)
/*! TYPE2 - Color Format Type 2 */
#define TINGPU_S1_CTRL_TYPE2(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_TYPE2_SHIFT)) & TINGPU_S1_CTRL_TYPE2_MASK)

#define TINGPU_S1_CTRL_TYPE1_MASK                (0x3000U)
#define TINGPU_S1_CTRL_TYPE1_SHIFT               (12U)
/*! TYPE1 - Color Format Type 1
 *  0b00..RGBA
 *  0b01..INDEX
 *  0b10..YUV
 *  0b11..COMPRESSED
 */
#define TINGPU_S1_CTRL_TYPE1(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_TYPE1_SHIFT)) & TINGPU_S1_CTRL_TYPE1_MASK)

#define TINGPU_S1_CTRL_ONE_TILE_MASK             (0x10000U)
#define TINGPU_S1_CTRL_ONE_TILE_SHIFT            (16U)
/*! ONE_TILE - One Tile
 *  0b0..Configures fetch number to maximum tiles.
 *  0b1..Configures fetch number to one tile.
 */
#define TINGPU_S1_CTRL_ONE_TILE(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CTRL_ONE_TILE_SHIFT)) & TINGPU_S1_CTRL_ONE_TILE_MASK)
/*! @} */

/*! @name S1_COLOR_SHIFT - S1 Color Shift */
/*! @{ */

#define TINGPU_S1_COLOR_SHIFT_A_SHIFT_MASK       (0x1FU)
#define TINGPU_S1_COLOR_SHIFT_A_SHIFT_SHIFT      (0U)
/*! A_SHIFT - Alpha Shift */
#define TINGPU_S1_COLOR_SHIFT_A_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_SHIFT_A_SHIFT_SHIFT)) & TINGPU_S1_COLOR_SHIFT_A_SHIFT_MASK)

#define TINGPU_S1_COLOR_SHIFT_B_SHIFT_MASK       (0x1F00U)
#define TINGPU_S1_COLOR_SHIFT_B_SHIFT_SHIFT      (8U)
/*! B_SHIFT - Blue Shift */
#define TINGPU_S1_COLOR_SHIFT_B_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_SHIFT_B_SHIFT_SHIFT)) & TINGPU_S1_COLOR_SHIFT_B_SHIFT_MASK)

#define TINGPU_S1_COLOR_SHIFT_G_SHIFT_MASK       (0x1F0000U)
#define TINGPU_S1_COLOR_SHIFT_G_SHIFT_SHIFT      (16U)
/*! G_SHIFT - Green Shift */
#define TINGPU_S1_COLOR_SHIFT_G_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_SHIFT_G_SHIFT_SHIFT)) & TINGPU_S1_COLOR_SHIFT_G_SHIFT_MASK)

#define TINGPU_S1_COLOR_SHIFT_R_SHIFT_MASK       (0x1F000000U)
#define TINGPU_S1_COLOR_SHIFT_R_SHIFT_SHIFT      (24U)
/*! R_SHIFT - Red Shift */
#define TINGPU_S1_COLOR_SHIFT_R_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_SHIFT_R_SHIFT_SHIFT)) & TINGPU_S1_COLOR_SHIFT_R_SHIFT_MASK)
/*! @} */

/*! @name S1_COLOR_BITS - S1 Color Bits */
/*! @{ */

#define TINGPU_S1_COLOR_BITS_A_WIDTH_MASK        (0xFU)
#define TINGPU_S1_COLOR_BITS_A_WIDTH_SHIFT       (0U)
/*! A_WIDTH - Alpha Width */
#define TINGPU_S1_COLOR_BITS_A_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_BITS_A_WIDTH_SHIFT)) & TINGPU_S1_COLOR_BITS_A_WIDTH_MASK)

#define TINGPU_S1_COLOR_BITS_B_WIDTH_MASK        (0xF00U)
#define TINGPU_S1_COLOR_BITS_B_WIDTH_SHIFT       (8U)
/*! B_WIDTH - Blue Width */
#define TINGPU_S1_COLOR_BITS_B_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_BITS_B_WIDTH_SHIFT)) & TINGPU_S1_COLOR_BITS_B_WIDTH_MASK)

#define TINGPU_S1_COLOR_BITS_G_WIDTH_MASK        (0xF0000U)
#define TINGPU_S1_COLOR_BITS_G_WIDTH_SHIFT       (16U)
/*! G_WIDTH - Green Width */
#define TINGPU_S1_COLOR_BITS_G_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_BITS_G_WIDTH_SHIFT)) & TINGPU_S1_COLOR_BITS_G_WIDTH_MASK)

#define TINGPU_S1_COLOR_BITS_R_WIDTH_MASK        (0xF000000U)
#define TINGPU_S1_COLOR_BITS_R_WIDTH_SHIFT       (24U)
/*! R_WIDTH - Red Width */
#define TINGPU_S1_COLOR_BITS_R_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_COLOR_BITS_R_WIDTH_SHIFT)) & TINGPU_S1_COLOR_BITS_R_WIDTH_MASK)
/*! @} */

/*! @name S1_SIZE - S1 Size */
/*! @{ */

#define TINGPU_S1_SIZE_WIDTH_MASK                (0x1FFFU)
#define TINGPU_S1_SIZE_WIDTH_SHIFT               (0U)
/*! WIDTH - Width */
#define TINGPU_S1_SIZE_WIDTH(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_SIZE_WIDTH_SHIFT)) & TINGPU_S1_SIZE_WIDTH_MASK)

#define TINGPU_S1_SIZE_HEIGHT_MASK               (0x1FFF0000U)
#define TINGPU_S1_SIZE_HEIGHT_SHIFT              (16U)
/*! HEIGHT - Height */
#define TINGPU_S1_SIZE_HEIGHT(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_SIZE_HEIGHT_SHIFT)) & TINGPU_S1_SIZE_HEIGHT_MASK)
/*! @} */

/*! @name S1_ADDR - S1 Address */
/*! @{ */

#define TINGPU_S1_ADDR_ADDR_MASK                 (0xFFFFFFFFU)
#define TINGPU_S1_ADDR_ADDR_SHIFT                (0U)
/*! ADDR - S1 Plane Address */
#define TINGPU_S1_ADDR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_ADDR_ADDR_SHIFT)) & TINGPU_S1_ADDR_ADDR_MASK)
/*! @} */

/*! @name S1_STRIDE - S1 stride */
/*! @{ */

#define TINGPU_S1_STRIDE_STRIDE_MASK             (0xFFFFU)
#define TINGPU_S1_STRIDE_STRIDE_SHIFT            (0U)
/*! STRIDE - S1 plane stride */
#define TINGPU_S1_STRIDE_STRIDE(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_STRIDE_STRIDE_SHIFT)) & TINGPU_S1_STRIDE_STRIDE_MASK)
/*! @} */

/*! @name S1_BKGND - S1 Background */
/*! @{ */

#define TINGPU_S1_BKGND_COLOR_MASK               (0xFFFFFFFFU)
#define TINGPU_S1_BKGND_COLOR_SHIFT              (0U)
/*! COLOR - Background Color */
#define TINGPU_S1_BKGND_COLOR(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_BKGND_COLOR_SHIFT)) & TINGPU_S1_BKGND_COLOR_MASK)
/*! @} */

/*! @name S1_CSC0 - S1 Color Space Conversion 0 */
/*! @{ */

#define TINGPU_S1_CSC0_Y_OFFSET_MASK             (0x1FFU)
#define TINGPU_S1_CSC0_Y_OFFSET_SHIFT            (0U)
/*! Y_OFFSET - Y Offset */
#define TINGPU_S1_CSC0_Y_OFFSET(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC0_Y_OFFSET_SHIFT)) & TINGPU_S1_CSC0_Y_OFFSET_MASK)

#define TINGPU_S1_CSC0_UV_OFFSET_MASK            (0x3FE00U)
#define TINGPU_S1_CSC0_UV_OFFSET_SHIFT           (9U)
/*! UV_OFFSET - UV Offset */
#define TINGPU_S1_CSC0_UV_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC0_UV_OFFSET_SHIFT)) & TINGPU_S1_CSC0_UV_OFFSET_MASK)

#define TINGPU_S1_CSC0_C0_MASK                   (0x1FFC0000U)
#define TINGPU_S1_CSC0_C0_SHIFT                  (18U)
/*! C0 - C0 */
#define TINGPU_S1_CSC0_C0(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC0_C0_SHIFT)) & TINGPU_S1_CSC0_C0_MASK)

#define TINGPU_S1_CSC0_YCBCR_MODE_MASK           (0x80000000U)
#define TINGPU_S1_CSC0_YCBCR_MODE_SHIFT          (31U)
/*! YCBCR_MODE - YCbCr Mode
 *  0b0..YUV to RGB conversion.
 *  0b1..YCbCr to RGB conversion.
 */
#define TINGPU_S1_CSC0_YCBCR_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC0_YCBCR_MODE_SHIFT)) & TINGPU_S1_CSC0_YCBCR_MODE_MASK)
/*! @} */

/*! @name S1_CSC1 - S1 Color Space Conversion 1 */
/*! @{ */

#define TINGPU_S1_CSC1_C4_MASK                   (0x7FFU)
#define TINGPU_S1_CSC1_C4_SHIFT                  (0U)
/*! C4 - C4 */
#define TINGPU_S1_CSC1_C4(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC1_C4_SHIFT)) & TINGPU_S1_CSC1_C4_MASK)

#define TINGPU_S1_CSC1_C1_MASK                   (0x7FF0000U)
#define TINGPU_S1_CSC1_C1_SHIFT                  (16U)
/*! C1 - C1 */
#define TINGPU_S1_CSC1_C1(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC1_C1_SHIFT)) & TINGPU_S1_CSC1_C1_MASK)
/*! @} */

/*! @name S1_CSC2 - S1 Color Space Conversion 2 */
/*! @{ */

#define TINGPU_S1_CSC2_C3_MASK                   (0x7FFU)
#define TINGPU_S1_CSC2_C3_SHIFT                  (0U)
/*! C3 - C3 */
#define TINGPU_S1_CSC2_C3(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC2_C3_SHIFT)) & TINGPU_S1_CSC2_C3_MASK)

#define TINGPU_S1_CSC2_C2_MASK                   (0x7FF0000U)
#define TINGPU_S1_CSC2_C2_SHIFT                  (16U)
/*! C2 - C2 */
#define TINGPU_S1_CSC2_C2(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CSC2_C2_SHIFT)) & TINGPU_S1_CSC2_C2_MASK)
/*! @} */

/*! @name S1_CLRKEY_LOW - S1 Color Key Low */
/*! @{ */

#define TINGPU_S1_CLRKEY_LOW_PIXEL_MASK          (0xFFFFFFU)
#define TINGPU_S1_CLRKEY_LOW_PIXEL_SHIFT         (0U)
/*! PIXEL - Pixel */
#define TINGPU_S1_CLRKEY_LOW_PIXEL(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CLRKEY_LOW_PIXEL_SHIFT)) & TINGPU_S1_CLRKEY_LOW_PIXEL_MASK)

#define TINGPU_S1_CLRKEY_LOW_EN_MASK             (0x80000000U)
#define TINGPU_S1_CLRKEY_LOW_EN_SHIFT            (31U)
/*! EN - Color Key Enable
 *  0b0..Color key operation is disabled.
 *  0b1..Color key operation is enabled.
 */
#define TINGPU_S1_CLRKEY_LOW_EN(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CLRKEY_LOW_EN_SHIFT)) & TINGPU_S1_CLRKEY_LOW_EN_MASK)
/*! @} */

/*! @name S1_CLRKEY_HIGH - S1 Color Key High */
/*! @{ */

#define TINGPU_S1_CLRKEY_HIGH_PIXEL_MASK         (0xFFFFFFU)
#define TINGPU_S1_CLRKEY_HIGH_PIXEL_SHIFT        (0U)
/*! PIXEL - Pixel */
#define TINGPU_S1_CLRKEY_HIGH_PIXEL(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CLRKEY_HIGH_PIXEL_SHIFT)) & TINGPU_S1_CLRKEY_HIGH_PIXEL_MASK)

#define TINGPU_S1_CLRKEY_HIGH_ALPHA_MASK         (0xFF000000U)
#define TINGPU_S1_CLRKEY_HIGH_ALPHA_SHIFT        (24U)
/*! ALPHA - Alpha */
#define TINGPU_S1_CLRKEY_HIGH_ALPHA(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_S1_CLRKEY_HIGH_ALPHA_SHIFT)) & TINGPU_S1_CLRKEY_HIGH_ALPHA_MASK)
/*! @} */

/*! @name MASK_CTRL - Mask Control */
/*! @{ */

#define TINGPU_MASK_CTRL_EN_MASK                 (0x1U)
#define TINGPU_MASK_CTRL_EN_SHIFT                (0U)
/*! EN - Enable Mask channel
 *  0b0..Mask channel is disabled.
 *  0b1..Mask channel is enabled.
 */
#define TINGPU_MASK_CTRL_EN(x)                   (((uint32_t)(((uint32_t)(x)) << TINGPU_MASK_CTRL_EN_SHIFT)) & TINGPU_MASK_CTRL_EN_MASK)

#define TINGPU_MASK_CTRL_MASK_FMT_MASK           (0x6U)
#define TINGPU_MASK_CTRL_MASK_FMT_SHIFT          (1U)
/*! MASK_FMT - Mask Format
 *  0b00..Mask format is A4.
 *  0b01..Mask format is A8.
 *  0b10..Mask format is A1.
 *  0b11..Reserved
 */
#define TINGPU_MASK_CTRL_MASK_FMT(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_MASK_CTRL_MASK_FMT_SHIFT)) & TINGPU_MASK_CTRL_MASK_FMT_MASK)

#define TINGPU_MASK_CTRL_ONE_TILE_MASK           (0x10000U)
#define TINGPU_MASK_CTRL_ONE_TILE_SHIFT          (16U)
/*! ONE_TILE - One Tile
 *  0b0..Configures fetch number to maximum tiles.
 *  0b1..Configures fetch number to one tile.
 */
#define TINGPU_MASK_CTRL_ONE_TILE(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_MASK_CTRL_ONE_TILE_SHIFT)) & TINGPU_MASK_CTRL_ONE_TILE_MASK)
/*! @} */

/*! @name MASK_ADDR - Mask Address */
/*! @{ */

#define TINGPU_MASK_ADDR_ADDR_MASK               (0xFFFFFFFFU)
#define TINGPU_MASK_ADDR_ADDR_SHIFT              (0U)
/*! ADDR - Address */
#define TINGPU_MASK_ADDR_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_MASK_ADDR_ADDR_SHIFT)) & TINGPU_MASK_ADDR_ADDR_MASK)
/*! @} */

/*! @name MASK_STRIDE - Mask Stride */
/*! @{ */

#define TINGPU_MASK_STRIDE_STRIDE_MASK           (0xFFFFU)
#define TINGPU_MASK_STRIDE_STRIDE_SHIFT          (0U)
/*! STRIDE - Configure Mask stride */
#define TINGPU_MASK_STRIDE_STRIDE(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_MASK_STRIDE_STRIDE_SHIFT)) & TINGPU_MASK_STRIDE_STRIDE_MASK)
/*! @} */

/*! @name S2_CTRL - S2 Control */
/*! @{ */

#define TINGPU_S2_CTRL_EN_MASK                   (0x1U)
#define TINGPU_S2_CTRL_EN_SHIFT                  (0U)
/*! EN - Enable
 *  0b0..S2 channel is disabled.
 *  0b1..S2 channel is enabled.
 */
#define TINGPU_S2_CTRL_EN(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_EN_SHIFT)) & TINGPU_S2_CTRL_EN_MASK)

#define TINGPU_S2_CTRL_PREMULTIPLY_MASK          (0x2U)
#define TINGPU_S2_CTRL_PREMULTIPLY_SHIFT         (1U)
/*! PREMULTIPLY - Premultiply
 *  0b0..S2 channel is not premultiplied.
 *  0b1..S2 channel is premultiplied.
 */
#define TINGPU_S2_CTRL_PREMULTIPLY(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_PREMULTIPLY_SHIFT)) & TINGPU_S2_CTRL_PREMULTIPLY_MASK)

#define TINGPU_S2_CTRL_GAMMA_MASK                (0x4U)
#define TINGPU_S2_CTRL_GAMMA_SHIFT               (2U)
/*! GAMMA - Gamma
 *  0b0..S2 gamma correction function is disabled.
 *  0b1..S2 gamma correction function is enabled.
 */
#define TINGPU_S2_CTRL_GAMMA(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_GAMMA_SHIFT)) & TINGPU_S2_CTRL_GAMMA_MASK)

#define TINGPU_S2_CTRL_RECT_MODE_MASK            (0x8U)
#define TINGPU_S2_CTRL_RECT_MODE_SHIFT           (3U)
/*! RECT_MODE - Mode of Pixels Outside of Scissoring Rectangles
 *  0b0..S2 pixels outside of scissoring rectangles are marked as invalid.
 *  0b1..S2 pixels outside of scissoring rectangles are marked as out-of-bounds.
 */
#define TINGPU_S2_CTRL_RECT_MODE(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_RECT_MODE_SHIFT)) & TINGPU_S2_CTRL_RECT_MODE_MASK)

#define TINGPU_S2_CTRL_WORD_WIDTH_MASK           (0x70U)
#define TINGPU_S2_CTRL_WORD_WIDTH_SHIFT          (4U)
/*! WORD_WIDTH - Pixel Word Width
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..24
 *  0b110..32
 *  0b111..Reserved
 */
#define TINGPU_S2_CTRL_WORD_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_WORD_WIDTH_SHIFT)) & TINGPU_S2_CTRL_WORD_WIDTH_MASK)

#define TINGPU_S2_CTRL_TYPE2_MASK                (0xF00U)
#define TINGPU_S2_CTRL_TYPE2_SHIFT               (8U)
/*! TYPE2 - Color Format Type 2 */
#define TINGPU_S2_CTRL_TYPE2(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_TYPE2_SHIFT)) & TINGPU_S2_CTRL_TYPE2_MASK)

#define TINGPU_S2_CTRL_TYPE1_MASK                (0x3000U)
#define TINGPU_S2_CTRL_TYPE1_SHIFT               (12U)
/*! TYPE1 - Color Format Type 1
 *  0b00..RGBA
 *  0b01..INDEX
 *  0b10..YUV
 *  0b11..COMPRESSED
 */
#define TINGPU_S2_CTRL_TYPE1(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_TYPE1_SHIFT)) & TINGPU_S2_CTRL_TYPE1_MASK)

#define TINGPU_S2_CTRL_IMAGE_QUALITY_MASK        (0xC000U)
#define TINGPU_S2_CTRL_IMAGE_QUALITY_SHIFT       (14U)
/*! IMAGE_QUALITY - Image Quality
 *  0b00..Image quality is non-antialiased.
 *  0b01..Image quality is faster mode.
 *  0b10..Image quality is better mode.
 *  0b11..Reserved.
 */
#define TINGPU_S2_CTRL_IMAGE_QUALITY(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CTRL_IMAGE_QUALITY_SHIFT)) & TINGPU_S2_CTRL_IMAGE_QUALITY_MASK)
/*! @} */

/*! @name S2_COLOR_SHIFT - S2 Color Shift */
/*! @{ */

#define TINGPU_S2_COLOR_SHIFT_A_SHIFT_MASK       (0x1FU)
#define TINGPU_S2_COLOR_SHIFT_A_SHIFT_SHIFT      (0U)
/*! A_SHIFT - Alpha Shift */
#define TINGPU_S2_COLOR_SHIFT_A_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_SHIFT_A_SHIFT_SHIFT)) & TINGPU_S2_COLOR_SHIFT_A_SHIFT_MASK)

#define TINGPU_S2_COLOR_SHIFT_B_SHIFT_MASK       (0x1F00U)
#define TINGPU_S2_COLOR_SHIFT_B_SHIFT_SHIFT      (8U)
/*! B_SHIFT - Blue Shift */
#define TINGPU_S2_COLOR_SHIFT_B_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_SHIFT_B_SHIFT_SHIFT)) & TINGPU_S2_COLOR_SHIFT_B_SHIFT_MASK)

#define TINGPU_S2_COLOR_SHIFT_G_SHIFT_MASK       (0x1F0000U)
#define TINGPU_S2_COLOR_SHIFT_G_SHIFT_SHIFT      (16U)
/*! G_SHIFT - Green Shift */
#define TINGPU_S2_COLOR_SHIFT_G_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_SHIFT_G_SHIFT_SHIFT)) & TINGPU_S2_COLOR_SHIFT_G_SHIFT_MASK)

#define TINGPU_S2_COLOR_SHIFT_R_SHIFT_MASK       (0x1F000000U)
#define TINGPU_S2_COLOR_SHIFT_R_SHIFT_SHIFT      (24U)
/*! R_SHIFT - Red Shift */
#define TINGPU_S2_COLOR_SHIFT_R_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_SHIFT_R_SHIFT_SHIFT)) & TINGPU_S2_COLOR_SHIFT_R_SHIFT_MASK)
/*! @} */

/*! @name S2_COLOR_BITS - S2 Color Bits */
/*! @{ */

#define TINGPU_S2_COLOR_BITS_A_WIDTH_MASK        (0xFU)
#define TINGPU_S2_COLOR_BITS_A_WIDTH_SHIFT       (0U)
/*! A_WIDTH - Alpha Width */
#define TINGPU_S2_COLOR_BITS_A_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_BITS_A_WIDTH_SHIFT)) & TINGPU_S2_COLOR_BITS_A_WIDTH_MASK)

#define TINGPU_S2_COLOR_BITS_B_WIDTH_MASK        (0xF00U)
#define TINGPU_S2_COLOR_BITS_B_WIDTH_SHIFT       (8U)
/*! B_WIDTH - Blue Width */
#define TINGPU_S2_COLOR_BITS_B_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_BITS_B_WIDTH_SHIFT)) & TINGPU_S2_COLOR_BITS_B_WIDTH_MASK)

#define TINGPU_S2_COLOR_BITS_G_WIDTH_MASK        (0xF0000U)
#define TINGPU_S2_COLOR_BITS_G_WIDTH_SHIFT       (16U)
/*! G_WIDTH - Green Width */
#define TINGPU_S2_COLOR_BITS_G_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_BITS_G_WIDTH_SHIFT)) & TINGPU_S2_COLOR_BITS_G_WIDTH_MASK)

#define TINGPU_S2_COLOR_BITS_R_WIDTH_MASK        (0xF000000U)
#define TINGPU_S2_COLOR_BITS_R_WIDTH_SHIFT       (24U)
/*! R_WIDTH - Red Width */
#define TINGPU_S2_COLOR_BITS_R_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_COLOR_BITS_R_WIDTH_SHIFT)) & TINGPU_S2_COLOR_BITS_R_WIDTH_MASK)
/*! @} */

/*! @name S2_SIZE - S2 Size */
/*! @{ */

#define TINGPU_S2_SIZE_WIDTH_MASK                (0x1FFFU)
#define TINGPU_S2_SIZE_WIDTH_SHIFT               (0U)
/*! WIDTH - Width */
#define TINGPU_S2_SIZE_WIDTH(x)                  (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SIZE_WIDTH_SHIFT)) & TINGPU_S2_SIZE_WIDTH_MASK)

#define TINGPU_S2_SIZE_HEIGHT_MASK               (0x1FFF0000U)
#define TINGPU_S2_SIZE_HEIGHT_SHIFT              (16U)
/*! HEIGHT - Height */
#define TINGPU_S2_SIZE_HEIGHT(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SIZE_HEIGHT_SHIFT)) & TINGPU_S2_SIZE_HEIGHT_MASK)
/*! @} */

/*! @name S2_ADDR - S2 Address */
/*! @{ */

#define TINGPU_S2_ADDR_ADDR_MASK                 (0xFFFFFFFFU)
#define TINGPU_S2_ADDR_ADDR_SHIFT                (0U)
/*! ADDR - S2 Plane Address */
#define TINGPU_S2_ADDR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_ADDR_ADDR_SHIFT)) & TINGPU_S2_ADDR_ADDR_MASK)
/*! @} */

/*! @name S2_STRIDE - S2 Stride */
/*! @{ */

#define TINGPU_S2_STRIDE_STRIDE_MASK             (0xFFFFU)
#define TINGPU_S2_STRIDE_STRIDE_SHIFT            (0U)
/*! STRIDE - S2 Plane Stride */
#define TINGPU_S2_STRIDE_STRIDE(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_STRIDE_STRIDE_SHIFT)) & TINGPU_S2_STRIDE_STRIDE_MASK)
/*! @} */

/*! @name S2_BKGND - S2 Background */
/*! @{ */

#define TINGPU_S2_BKGND_COLOR_MASK               (0xFFFFFFFFU)
#define TINGPU_S2_BKGND_COLOR_SHIFT              (0U)
/*! COLOR - Background Color */
#define TINGPU_S2_BKGND_COLOR(x)                 (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_BKGND_COLOR_SHIFT)) & TINGPU_S2_BKGND_COLOR_MASK)
/*! @} */

/*! @name ALPHA_CTRL - Alpha Control */
/*! @{ */

#define TINGPU_ALPHA_CTRL_S1_ALPHA_MODE_MASK     (0x1U)
#define TINGPU_ALPHA_CTRL_S1_ALPHA_MODE_SHIFT    (0U)
/*! S1_ALPHA_MODE - S1_ALPHA_MODE
 *  0b0..straight mode for S1 alpha
 *  0b1..inversed mode for S1 alpha
 */
#define TINGPU_ALPHA_CTRL_S1_ALPHA_MODE(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_ALPHA_CTRL_S1_ALPHA_MODE_SHIFT)) & TINGPU_ALPHA_CTRL_S1_ALPHA_MODE_MASK)

#define TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MODE_MASK (0x6U)
#define TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MODE_SHIFT (1U)
/*! S1_GLOBAL_ALPHA_MODE - S1_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha.
 *  0b01..using local alpha.
 *  0b10..using scaled alpha.
 *  0b11..using scaled alpha.
 */
#define TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MODE_SHIFT)) & TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MODE_MASK)

#define TINGPU_ALPHA_CTRL_S2_ALPHA_MODE_MASK     (0x100U)
#define TINGPU_ALPHA_CTRL_S2_ALPHA_MODE_SHIFT    (8U)
/*! S2_ALPHA_MODE - S2_ALPHA_MODE
 *  0b0..straight mode for S2 alpha
 *  0b1..inversed mode for S2 alpha
 */
#define TINGPU_ALPHA_CTRL_S2_ALPHA_MODE(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_ALPHA_CTRL_S2_ALPHA_MODE_SHIFT)) & TINGPU_ALPHA_CTRL_S2_ALPHA_MODE_MASK)

#define TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MODE_MASK (0x600U)
#define TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MODE_SHIFT (9U)
/*! S2_GLOBAL_ALPHA_MODE - S2_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha.
 *  0b01..using local alpha.
 *  0b10..using scaled alpha.
 *  0b11..using scaled alpha.
 */
#define TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MODE_SHIFT)) & TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MODE_MASK)

#define TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MASK   (0xFF0000U)
#define TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_SHIFT  (16U)
/*! S1_GLOBAL_ALPHA - S1_GLOBAL_ALPHA */
#define TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_SHIFT)) & TINGPU_ALPHA_CTRL_S1_GLOBAL_ALPHA_MASK)

#define TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MASK   (0xFF000000U)
#define TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_SHIFT  (24U)
/*! S2_GLOBAL_ALPHA - S2_GLOBAL_ALPHA */
#define TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_SHIFT)) & TINGPU_ALPHA_CTRL_S2_GLOBAL_ALPHA_MASK)
/*! @} */

/*! @name BLEND_CTRL - Blending Control */
/*! @{ */

#define TINGPU_BLEND_CTRL_BLENDING_MODE_MASK     (0x3U)
#define TINGPU_BLEND_CTRL_BLENDING_MODE_SHIFT    (0U)
/*! BLENDING_MODE - Blending Mode
 *  0b00..Porter-Duff blending mode is selected.
 *  0b01..Additional blending mode is selected.
 *  0b10..Additive blending mode is selected.
 *  0b11..Special blending mode is selected.
 */
#define TINGPU_BLEND_CTRL_BLENDING_MODE(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_BLEND_CTRL_BLENDING_MODE_SHIFT)) & TINGPU_BLEND_CTRL_BLENDING_MODE_MASK)

#define TINGPU_BLEND_CTRL_ADDITIONAL_MODE_MASK   (0xCU)
#define TINGPU_BLEND_CTRL_ADDITIONAL_MODE_SHIFT  (2U)
/*! ADDITIONAL_MODE - Additional Mode
 *  0b00..Additional blending is darken mode.
 *  0b01..Additional blending lighten mode.
 *  0b10..Additional blending is multiply mode.
 *  0b11..Additional blending is screen mode.
 */
#define TINGPU_BLEND_CTRL_ADDITIONAL_MODE(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_BLEND_CTRL_ADDITIONAL_MODE_SHIFT)) & TINGPU_BLEND_CTRL_ADDITIONAL_MODE_MASK)

#define TINGPU_BLEND_CTRL_S1_FACTOR_MODE_MASK    (0x30U)
#define TINGPU_BLEND_CTRL_S1_FACTOR_MODE_SHIFT   (4U)
/*! S1_FACTOR_MODE - S1 Factor Mode
 *  0b00..using 1.
 *  0b01..using 0.
 *  0b10..using straight alpha.
 *  0b11..using inverse alpha.
 */
#define TINGPU_BLEND_CTRL_S1_FACTOR_MODE(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_BLEND_CTRL_S1_FACTOR_MODE_SHIFT)) & TINGPU_BLEND_CTRL_S1_FACTOR_MODE_MASK)

#define TINGPU_BLEND_CTRL_S2_FACTOR_MODE_MASK    (0xC0U)
#define TINGPU_BLEND_CTRL_S2_FACTOR_MODE_SHIFT   (6U)
/*! S2_FACTOR_MODE - S2 Factor Mode
 *  0b00..using 1.
 *  0b01..using 0.
 *  0b10..using straight alpha.
 *  0b11..using inverse alpha.
 */
#define TINGPU_BLEND_CTRL_S2_FACTOR_MODE(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_BLEND_CTRL_S2_FACTOR_MODE_SHIFT)) & TINGPU_BLEND_CTRL_S2_FACTOR_MODE_MASK)
/*! @} */

/*! @name S2_CLRKEY_LOW - S2 Color Key Low */
/*! @{ */

#define TINGPU_S2_CLRKEY_LOW_PIXEL_MASK          (0xFFFFFFU)
#define TINGPU_S2_CLRKEY_LOW_PIXEL_SHIFT         (0U)
/*! PIXEL - Pixel */
#define TINGPU_S2_CLRKEY_LOW_PIXEL(x)            (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CLRKEY_LOW_PIXEL_SHIFT)) & TINGPU_S2_CLRKEY_LOW_PIXEL_MASK)

#define TINGPU_S2_CLRKEY_LOW_EN_MASK             (0x80000000U)
#define TINGPU_S2_CLRKEY_LOW_EN_SHIFT            (31U)
/*! EN - Color Key Enable
 *  0b0..Color key operation is disabled.
 *  0b1..Color key operation is enabled.
 */
#define TINGPU_S2_CLRKEY_LOW_EN(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CLRKEY_LOW_EN_SHIFT)) & TINGPU_S2_CLRKEY_LOW_EN_MASK)
/*! @} */

/*! @name S2_CLRKEY_HIGH - S2 Color Key High */
/*! @{ */

#define TINGPU_S2_CLRKEY_HIGH_PIXEL_MASK         (0xFFFFFFU)
#define TINGPU_S2_CLRKEY_HIGH_PIXEL_SHIFT        (0U)
/*! PIXEL - Pixel */
#define TINGPU_S2_CLRKEY_HIGH_PIXEL(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CLRKEY_HIGH_PIXEL_SHIFT)) & TINGPU_S2_CLRKEY_HIGH_PIXEL_MASK)

#define TINGPU_S2_CLRKEY_HIGH_ALPHA_MASK         (0xFF000000U)
#define TINGPU_S2_CLRKEY_HIGH_ALPHA_SHIFT        (24U)
/*! ALPHA - Alpha */
#define TINGPU_S2_CLRKEY_HIGH_ALPHA(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CLRKEY_HIGH_ALPHA_SHIFT)) & TINGPU_S2_CLRKEY_HIGH_ALPHA_MASK)
/*! @} */

/*! @name S2_TRANSFORM_CTRL - S2 Transform Control */
/*! @{ */

#define TINGPU_S2_TRANSFORM_CTRL_MODE_MASK       (0x1U)
#define TINGPU_S2_TRANSFORM_CTRL_MODE_SHIFT      (0U)
/*! MODE - Transform Mode
 *  0b0..Transform is affine mode.
 *  0b1..Transform is perspective mode.
 */
#define TINGPU_S2_TRANSFORM_CTRL_MODE(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_TRANSFORM_CTRL_MODE_SHIFT)) & TINGPU_S2_TRANSFORM_CTRL_MODE_MASK)
/*! @} */

/*! @name S2_PROJ_TF - S2 Projective Transform */
/*! @{ */

#define TINGPU_S2_PROJ_TF_MATRIX_VALUE_MASK      (0xFFFFFFFFU)
#define TINGPU_S2_PROJ_TF_MATRIX_VALUE_SHIFT     (0U)
/*! MATRIX_VALUE - Matrix Value */
#define TINGPU_S2_PROJ_TF_MATRIX_VALUE(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_PROJ_TF_MATRIX_VALUE_SHIFT)) & TINGPU_S2_PROJ_TF_MATRIX_VALUE_MASK)
/*! @} */

/*! @name S2_SCISSOR_CTRL - S2 Scissor Control */
/*! @{ */

#define TINGPU_S2_SCISSOR_CTRL_MINX_MASK         (0x1FFFU)
#define TINGPU_S2_SCISSOR_CTRL_MINX_SHIFT        (0U)
/*! MINX - Scissor Rectangle Minx */
#define TINGPU_S2_SCISSOR_CTRL_MINX(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SCISSOR_CTRL_MINX_SHIFT)) & TINGPU_S2_SCISSOR_CTRL_MINX_MASK)

#define TINGPU_S2_SCISSOR_CTRL_MINY_MASK         (0x1FFF0000U)
#define TINGPU_S2_SCISSOR_CTRL_MINY_SHIFT        (16U)
/*! MINY - Scissor Rectangle Miny */
#define TINGPU_S2_SCISSOR_CTRL_MINY(x)           (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SCISSOR_CTRL_MINY_SHIFT)) & TINGPU_S2_SCISSOR_CTRL_MINY_MASK)

#define TINGPU_S2_SCISSOR_CTRL_SCISSOR_EN_MASK   (0x80000000U)
#define TINGPU_S2_SCISSOR_CTRL_SCISSOR_EN_SHIFT  (31U)
/*! SCISSOR_EN - Scissor Enable
 *  0b0..Scissor function is disabled.
 *  0b1..Scissor function is enabled.
 */
#define TINGPU_S2_SCISSOR_CTRL_SCISSOR_EN(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SCISSOR_CTRL_SCISSOR_EN_SHIFT)) & TINGPU_S2_SCISSOR_CTRL_SCISSOR_EN_MASK)
/*! @} */

/*! @name S2_SCISSOR_SIZE - S2 Scissor Size */
/*! @{ */

#define TINGPU_S2_SCISSOR_SIZE_WIDTH_MASK        (0x1FFFU)
#define TINGPU_S2_SCISSOR_SIZE_WIDTH_SHIFT       (0U)
/*! WIDTH - Scissor Rectangle Width */
#define TINGPU_S2_SCISSOR_SIZE_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SCISSOR_SIZE_WIDTH_SHIFT)) & TINGPU_S2_SCISSOR_SIZE_WIDTH_MASK)

#define TINGPU_S2_SCISSOR_SIZE_HEIGHT_MASK       (0x1FFF0000U)
#define TINGPU_S2_SCISSOR_SIZE_HEIGHT_SHIFT      (16U)
/*! HEIGHT - Scissor Rectangle Height */
#define TINGPU_S2_SCISSOR_SIZE_HEIGHT(x)         (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_SCISSOR_SIZE_HEIGHT_SHIFT)) & TINGPU_S2_SCISSOR_SIZE_HEIGHT_MASK)
/*! @} */

/*! @name COLOR_TRANSFORM_CTRL - Color Transform Control */
/*! @{ */

#define TINGPU_COLOR_TRANSFORM_CTRL_CT_EN_MASK   (0x1U)
#define TINGPU_COLOR_TRANSFORM_CTRL_CT_EN_SHIFT  (0U)
/*! CT_EN - Color Transform Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TINGPU_COLOR_TRANSFORM_CTRL_CT_EN(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM_CTRL_CT_EN_SHIFT)) & TINGPU_COLOR_TRANSFORM_CTRL_CT_EN_MASK)
/*! @} */

/*! @name COLOR_TRANSFORM0 - Color Transform 0 */
/*! @{ */

#define TINGPU_COLOR_TRANSFORM0_SCALE_R_MASK     (0xFFFFU)
#define TINGPU_COLOR_TRANSFORM0_SCALE_R_SHIFT    (0U)
/*! SCALE_R - Scale R */
#define TINGPU_COLOR_TRANSFORM0_SCALE_R(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM0_SCALE_R_SHIFT)) & TINGPU_COLOR_TRANSFORM0_SCALE_R_MASK)

#define TINGPU_COLOR_TRANSFORM0_BIAS_R_MASK      (0x1FF0000U)
#define TINGPU_COLOR_TRANSFORM0_BIAS_R_SHIFT     (16U)
/*! BIAS_R - Bias R */
#define TINGPU_COLOR_TRANSFORM0_BIAS_R(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM0_BIAS_R_SHIFT)) & TINGPU_COLOR_TRANSFORM0_BIAS_R_MASK)
/*! @} */

/*! @name COLOR_TRANSFORM1 - Color Transform 1 */
/*! @{ */

#define TINGPU_COLOR_TRANSFORM1_SCALE_G_MASK     (0xFFFFU)
#define TINGPU_COLOR_TRANSFORM1_SCALE_G_SHIFT    (0U)
/*! SCALE_G - Scale G */
#define TINGPU_COLOR_TRANSFORM1_SCALE_G(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM1_SCALE_G_SHIFT)) & TINGPU_COLOR_TRANSFORM1_SCALE_G_MASK)

#define TINGPU_COLOR_TRANSFORM1_BIAS_G_MASK      (0x1FF0000U)
#define TINGPU_COLOR_TRANSFORM1_BIAS_G_SHIFT     (16U)
/*! BIAS_G - Bias G */
#define TINGPU_COLOR_TRANSFORM1_BIAS_G(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM1_BIAS_G_SHIFT)) & TINGPU_COLOR_TRANSFORM1_BIAS_G_MASK)
/*! @} */

/*! @name COLOR_TRANSFORM2 - Color Transform 2 */
/*! @{ */

#define TINGPU_COLOR_TRANSFORM2_SCALE_B_MASK     (0xFFFFU)
#define TINGPU_COLOR_TRANSFORM2_SCALE_B_SHIFT    (0U)
/*! SCALE_B - Scale B */
#define TINGPU_COLOR_TRANSFORM2_SCALE_B(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM2_SCALE_B_SHIFT)) & TINGPU_COLOR_TRANSFORM2_SCALE_B_MASK)

#define TINGPU_COLOR_TRANSFORM2_BIAS_B_MASK      (0x1FF0000U)
#define TINGPU_COLOR_TRANSFORM2_BIAS_B_SHIFT     (16U)
/*! BIAS_B - Bias B */
#define TINGPU_COLOR_TRANSFORM2_BIAS_B(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM2_BIAS_B_SHIFT)) & TINGPU_COLOR_TRANSFORM2_BIAS_B_MASK)
/*! @} */

/*! @name COLOR_TRANSFORM3 - Color Transform 3 */
/*! @{ */

#define TINGPU_COLOR_TRANSFORM3_SCALE_A_MASK     (0xFFFFU)
#define TINGPU_COLOR_TRANSFORM3_SCALE_A_SHIFT    (0U)
/*! SCALE_A - Scale A */
#define TINGPU_COLOR_TRANSFORM3_SCALE_A(x)       (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM3_SCALE_A_SHIFT)) & TINGPU_COLOR_TRANSFORM3_SCALE_A_MASK)

#define TINGPU_COLOR_TRANSFORM3_BIAS_A_MASK      (0x1FF0000U)
#define TINGPU_COLOR_TRANSFORM3_BIAS_A_SHIFT     (16U)
/*! BIAS_A - Bias A */
#define TINGPU_COLOR_TRANSFORM3_BIAS_A(x)        (((uint32_t)(((uint32_t)(x)) << TINGPU_COLOR_TRANSFORM3_BIAS_A_SHIFT)) & TINGPU_COLOR_TRANSFORM3_BIAS_A_MASK)
/*! @} */

/*! @name S2_CSC0 - S2 Color Space Conversion 0 */
/*! @{ */

#define TINGPU_S2_CSC0_Y_OFFSET_MASK             (0x1FFU)
#define TINGPU_S2_CSC0_Y_OFFSET_SHIFT            (0U)
/*! Y_OFFSET - Y Offset */
#define TINGPU_S2_CSC0_Y_OFFSET(x)               (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC0_Y_OFFSET_SHIFT)) & TINGPU_S2_CSC0_Y_OFFSET_MASK)

#define TINGPU_S2_CSC0_UV_OFFSET_MASK            (0x3FE00U)
#define TINGPU_S2_CSC0_UV_OFFSET_SHIFT           (9U)
/*! UV_OFFSET - UV Offset */
#define TINGPU_S2_CSC0_UV_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC0_UV_OFFSET_SHIFT)) & TINGPU_S2_CSC0_UV_OFFSET_MASK)

#define TINGPU_S2_CSC0_C0_MASK                   (0x1FFC0000U)
#define TINGPU_S2_CSC0_C0_SHIFT                  (18U)
/*! C0 - C0 */
#define TINGPU_S2_CSC0_C0(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC0_C0_SHIFT)) & TINGPU_S2_CSC0_C0_MASK)

#define TINGPU_S2_CSC0_YCBCR_MODE_MASK           (0x80000000U)
#define TINGPU_S2_CSC0_YCBCR_MODE_SHIFT          (31U)
/*! YCBCR_MODE - YCbCr Mode
 *  0b0..YUV to RGB conversion.
 *  0b1..YCbCr to RGB conversion.
 */
#define TINGPU_S2_CSC0_YCBCR_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC0_YCBCR_MODE_SHIFT)) & TINGPU_S2_CSC0_YCBCR_MODE_MASK)
/*! @} */

/*! @name S2_CSC1 - S2 Color Space Conversion 1 */
/*! @{ */

#define TINGPU_S2_CSC1_C4_MASK                   (0x7FFU)
#define TINGPU_S2_CSC1_C4_SHIFT                  (0U)
/*! C4 - C4 */
#define TINGPU_S2_CSC1_C4(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC1_C4_SHIFT)) & TINGPU_S2_CSC1_C4_MASK)

#define TINGPU_S2_CSC1_C1_MASK                   (0x7FF0000U)
#define TINGPU_S2_CSC1_C1_SHIFT                  (16U)
/*! C1 - C1 */
#define TINGPU_S2_CSC1_C1(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC1_C1_SHIFT)) & TINGPU_S2_CSC1_C1_MASK)
/*! @} */

/*! @name S2_CSC2 - S2 Color Space Conversion 2 */
/*! @{ */

#define TINGPU_S2_CSC2_C3_MASK                   (0x7FFU)
#define TINGPU_S2_CSC2_C3_SHIFT                  (0U)
/*! C3 - C3 */
#define TINGPU_S2_CSC2_C3(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC2_C3_SHIFT)) & TINGPU_S2_CSC2_C3_MASK)

#define TINGPU_S2_CSC2_C2_MASK                   (0x7FF0000U)
#define TINGPU_S2_CSC2_C2_SHIFT                  (16U)
/*! C2 - C2 */
#define TINGPU_S2_CSC2_C2(x)                     (((uint32_t)(((uint32_t)(x)) << TINGPU_S2_CSC2_C2_SHIFT)) & TINGPU_S2_CSC2_C2_MASK)
/*! @} */

/*! @name AXI_CACHE_CTRL - AXI Cache Control */
/*! @{ */

#define TINGPU_AXI_CACHE_CTRL_CCDMA_ARCACHE_MASK (0xFU)
#define TINGPU_AXI_CACHE_CTRL_CCDMA_ARCACHE_SHIFT (0U)
/*! CCDMA_ARCACHE - CCDMA Arcache */
#define TINGPU_AXI_CACHE_CTRL_CCDMA_ARCACHE(x)   (((uint32_t)(((uint32_t)(x)) << TINGPU_AXI_CACHE_CTRL_CCDMA_ARCACHE_SHIFT)) & TINGPU_AXI_CACHE_CTRL_CCDMA_ARCACHE_MASK)

#define TINGPU_AXI_CACHE_CTRL_MASK_ARCACHE_MASK  (0xF0U)
#define TINGPU_AXI_CACHE_CTRL_MASK_ARCACHE_SHIFT (4U)
/*! MASK_ARCACHE - Mask Arcache */
#define TINGPU_AXI_CACHE_CTRL_MASK_ARCACHE(x)    (((uint32_t)(((uint32_t)(x)) << TINGPU_AXI_CACHE_CTRL_MASK_ARCACHE_SHIFT)) & TINGPU_AXI_CACHE_CTRL_MASK_ARCACHE_MASK)

#define TINGPU_AXI_CACHE_CTRL_S1_ARCACHE_MASK    (0xF00U)
#define TINGPU_AXI_CACHE_CTRL_S1_ARCACHE_SHIFT   (8U)
/*! S1_ARCACHE - S1 Arcache */
#define TINGPU_AXI_CACHE_CTRL_S1_ARCACHE(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_AXI_CACHE_CTRL_S1_ARCACHE_SHIFT)) & TINGPU_AXI_CACHE_CTRL_S1_ARCACHE_MASK)

#define TINGPU_AXI_CACHE_CTRL_S2_ARCACHE_MASK    (0xF000U)
#define TINGPU_AXI_CACHE_CTRL_S2_ARCACHE_SHIFT   (12U)
/*! S2_ARCACHE - S2 Arcache */
#define TINGPU_AXI_CACHE_CTRL_S2_ARCACHE(x)      (((uint32_t)(((uint32_t)(x)) << TINGPU_AXI_CACHE_CTRL_S2_ARCACHE_SHIFT)) & TINGPU_AXI_CACHE_CTRL_S2_ARCACHE_MASK)

#define TINGPU_AXI_CACHE_CTRL_DST_AWCACHE_MASK   (0xF0000U)
#define TINGPU_AXI_CACHE_CTRL_DST_AWCACHE_SHIFT  (16U)
/*! DST_AWCACHE - Destination Awcache */
#define TINGPU_AXI_CACHE_CTRL_DST_AWCACHE(x)     (((uint32_t)(((uint32_t)(x)) << TINGPU_AXI_CACHE_CTRL_DST_AWCACHE_SHIFT)) & TINGPU_AXI_CACHE_CTRL_DST_AWCACHE_MASK)

#define TINGPU_AXI_CACHE_CTRL_CCDMA_AWCACHE_MASK (0xF00000U)
#define TINGPU_AXI_CACHE_CTRL_CCDMA_AWCACHE_SHIFT (20U)
/*! CCDMA_AWCACHE - CCDMA Awcache */
#define TINGPU_AXI_CACHE_CTRL_CCDMA_AWCACHE(x)   (((uint32_t)(((uint32_t)(x)) << TINGPU_AXI_CACHE_CTRL_CCDMA_AWCACHE_SHIFT)) & TINGPU_AXI_CACHE_CTRL_CCDMA_AWCACHE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TINGPU_Register_Masks */


/*!
 * @}
 */ /* end of group TINGPU_Peripheral_Access_Layer */


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


#endif  /* PERI_TINGPU_H_ */

