/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCC5
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCC5.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC5
 *
 * CMSIS Peripheral Access Layer for PCC5
 */

#if !defined(PERI_PCC5_H_)
#define PERI_PCC5_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- PCC5 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC5_Peripheral_Access_Layer PCC5 Peripheral Access Layer
 * @{
 */

/** PCC5 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCC_DMA2_MP;                       /**< PCC DMA2_MP Register, offset: 0x0 */
  __IO uint32_t PCC_DMA2_CH0;                      /**< PCC DMA2_CH0 Register, offset: 0x4 */
  __IO uint32_t PCC_DMA2_CH1;                      /**< PCC DMA2_CH1 Register, offset: 0x8 */
  __IO uint32_t PCC_DMA2_CH2;                      /**< PCC DMA2_CH2 Register, offset: 0xC */
  __IO uint32_t PCC_DMA2_CH3;                      /**< PCC DMA2_CH3 Register, offset: 0x10 */
  __IO uint32_t PCC_DMA2_CH4;                      /**< PCC DMA2_CH4 Register, offset: 0x14 */
  __IO uint32_t PCC_DMA2_CH5;                      /**< PCC DMA2_CH5 Register, offset: 0x18 */
  __IO uint32_t PCC_DMA2_CH6;                      /**< PCC DMA2_CH6 Register, offset: 0x1C */
  __IO uint32_t PCC_DMA2_CH7;                      /**< PCC DMA2_CH7 Register, offset: 0x20 */
  __IO uint32_t PCC_DMA2_CH8;                      /**< PCC DMA2_CH8 Register, offset: 0x24 */
  __IO uint32_t PCC_DMA2_CH9;                      /**< PCC DMA2_CH9 Register, offset: 0x28 */
  __IO uint32_t PCC_DMA2_CH10;                     /**< PCC DMA2_CH10 Register, offset: 0x2C */
  __IO uint32_t PCC_DMA2_CH11;                     /**< PCC DMA2_CH11 Register, offset: 0x30 */
  __IO uint32_t PCC_DMA2_CH12;                     /**< PCC DMA2_CH12 Register, offset: 0x34 */
  __IO uint32_t PCC_DMA2_CH13;                     /**< PCC DMA2_CH13 Register, offset: 0x38 */
  __IO uint32_t PCC_DMA2_CH14;                     /**< PCC DMA2_CH14 Register, offset: 0x3C */
  __IO uint32_t PCC_DMA2_CH15;                     /**< PCC DMA2_CH15 Register, offset: 0x40 */
  __IO uint32_t PCC_DMA2_CH16;                     /**< PCC DMA2_CH16 Register, offset: 0x44 */
  __IO uint32_t PCC_DMA2_CH17;                     /**< PCC DMA2_CH17 Register, offset: 0x48 */
  __IO uint32_t PCC_DMA2_CH18;                     /**< PCC DMA2_CH18 Register, offset: 0x4C */
  __IO uint32_t PCC_DMA2_CH19;                     /**< PCC DMA2_CH19 Register, offset: 0x50 */
  __IO uint32_t PCC_DMA2_CH20;                     /**< PCC DMA2_CH20 Register, offset: 0x54 */
  __IO uint32_t PCC_DMA2_CH21;                     /**< PCC DMA2_CH21 Register, offset: 0x58 */
  __IO uint32_t PCC_DMA2_CH22;                     /**< PCC DMA2_CH22 Register, offset: 0x5C */
  __IO uint32_t PCC_DMA2_CH23;                     /**< PCC DMA2_CH23 Register, offset: 0x60 */
  __IO uint32_t PCC_DMA2_CH24;                     /**< PCC DMA2_CH24 Register, offset: 0x64 */
  __IO uint32_t PCC_DMA2_CH25;                     /**< PCC DMA2_CH25 Register, offset: 0x68 */
  __IO uint32_t PCC_DMA2_CH26;                     /**< PCC DMA2_CH26 Register, offset: 0x6C */
  __IO uint32_t PCC_DMA2_CH27;                     /**< PCC DMA2_CH27 Register, offset: 0x70 */
  __IO uint32_t PCC_DMA2_CH28;                     /**< PCC DMA2_CH28 Register, offset: 0x74 */
  __IO uint32_t PCC_DMA2_CH29;                     /**< PCC DMA2_CH29 Register, offset: 0x78 */
  __IO uint32_t PCC_DMA2_CH30;                     /**< PCC DMA2_CH30 Register, offset: 0x7C */
  __IO uint32_t PCC_DMA2_CH31;                     /**< PCC DMA2_CH31 Register, offset: 0x80 */
  __IO uint32_t PCC_MU2_B;                         /**< PCC MU2_B Register, offset: 0x84 */
  __IO uint32_t PCC_MU3_B;                         /**< PCC MU3_B Register, offset: 0x88 */
  __IO uint32_t PCC_SEMA42_2;                      /**< PCC SEMA42_2 Register, offset: 0x8C */
       uint8_t RESERVED_0[16];
  __IO uint32_t PCC_TPM8;                          /**< PCC TPM8 Register, offset: 0xA0 */
  __IO uint32_t PCC_SAI6;                          /**< PCC SAI6 Register, offset: 0xA4 */
  __IO uint32_t PCC_SAI7;                          /**< PCC SAI7 Register, offset: 0xA8 */
  __IO uint32_t PCC_SPDIF;                         /**< PCC SPDIF Register, offset: 0xAC */
  __IO uint32_t PCC_ISI;                           /**< PCC ISI Register, offset: 0xB0 */
  __IO uint32_t PCC_CSI_REGS;                      /**< PCC CSI_REGS Register, offset: 0xB4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PCC_CSI;                           /**< PCC CSI Register, offset: 0xBC */
  __IO uint32_t PCC_DSI;                           /**< PCC DSI Register, offset: 0xC0 */
       uint8_t RESERVED_2[4];
  __IO uint32_t PCC_WDOG5;                         /**< PCC WDOG5 Register, offset: 0xC8 */
  __IO uint32_t PCC_EPDC;                          /**< PCC EPDC Register, offset: 0xCC */
  __IO uint32_t PCC_PXP;                           /**< PCC PXP Register, offset: 0xD0 */
       uint8_t RESERVED_3[28];
  __IO uint32_t PCC_GPU2D;                         /**< PCC GPU2D Register, offset: 0xF0 */
  __IO uint32_t PCC_GPU3D;                         /**< PCC GPU3D Register, offset: 0xF4 */
  __IO uint32_t PCC_DC_NANO;                       /**< PCC DC_Nano Register, offset: 0xF8 */
       uint8_t RESERVED_4[12];
  __IO uint32_t PCC_LPDDR4;                        /**< PCC LPDDR4 Register, offset: 0x108 */
  __IO uint32_t PCC_CSI_CLK_UI;                    /**< PCC CSI_clk_ui Register, offset: 0x10C */
  __IO uint32_t PCC_CSI_CLK_ESC;                   /**< PCC CSI_clk_esc Register, offset: 0x110 */
  __IO uint32_t PCC_RGPIOD;                        /**< PCC RGPIOD Register, offset: 0x114 */
} PCC5_Type;

/* ----------------------------------------------------------------------------
   -- PCC5 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC5_Register_Masks PCC5 Register Masks
 * @{
 */

/*! @name PCC_DMA2_MP - PCC DMA2_MP Register */
/*! @{ */

#define PCC5_PCC_DMA2_MP_SSADO_MASK              (0xC00000U)
#define PCC5_PCC_DMA2_MP_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_MP_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_MP_SSADO_SHIFT)) & PCC5_PCC_DMA2_MP_SSADO_MASK)

#define PCC5_PCC_DMA2_MP_CGC_MASK                (0x40000000U)
#define PCC5_PCC_DMA2_MP_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_MP_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_MP_CGC_SHIFT)) & PCC5_PCC_DMA2_MP_CGC_MASK)

#define PCC5_PCC_DMA2_MP_PR_MASK                 (0x80000000U)
#define PCC5_PCC_DMA2_MP_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_MP_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_MP_PR_SHIFT)) & PCC5_PCC_DMA2_MP_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH0 - PCC DMA2_CH0 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH0_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH0_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH0_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH0_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH0_SSADO_MASK)

#define PCC5_PCC_DMA2_CH0_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH0_CGC_SHIFT)) & PCC5_PCC_DMA2_CH0_CGC_MASK)

#define PCC5_PCC_DMA2_CH0_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH0_PR_SHIFT)) & PCC5_PCC_DMA2_CH0_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH1 - PCC DMA2_CH1 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH1_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH1_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH1_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH1_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH1_SSADO_MASK)

#define PCC5_PCC_DMA2_CH1_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH1_CGC_SHIFT)) & PCC5_PCC_DMA2_CH1_CGC_MASK)

#define PCC5_PCC_DMA2_CH1_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH1_PR_SHIFT)) & PCC5_PCC_DMA2_CH1_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH2 - PCC DMA2_CH2 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH2_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH2_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH2_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH2_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH2_SSADO_MASK)

#define PCC5_PCC_DMA2_CH2_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH2_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH2_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH2_CGC_SHIFT)) & PCC5_PCC_DMA2_CH2_CGC_MASK)

#define PCC5_PCC_DMA2_CH2_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH2_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH2_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH2_PR_SHIFT)) & PCC5_PCC_DMA2_CH2_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH3 - PCC DMA2_CH3 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH3_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH3_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH3_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH3_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH3_SSADO_MASK)

#define PCC5_PCC_DMA2_CH3_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH3_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH3_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH3_CGC_SHIFT)) & PCC5_PCC_DMA2_CH3_CGC_MASK)

#define PCC5_PCC_DMA2_CH3_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH3_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH3_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH3_PR_SHIFT)) & PCC5_PCC_DMA2_CH3_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH4 - PCC DMA2_CH4 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH4_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH4_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH4_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH4_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH4_SSADO_MASK)

#define PCC5_PCC_DMA2_CH4_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH4_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH4_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH4_CGC_SHIFT)) & PCC5_PCC_DMA2_CH4_CGC_MASK)

#define PCC5_PCC_DMA2_CH4_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH4_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH4_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH4_PR_SHIFT)) & PCC5_PCC_DMA2_CH4_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH5 - PCC DMA2_CH5 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH5_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH5_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH5_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH5_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH5_SSADO_MASK)

#define PCC5_PCC_DMA2_CH5_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH5_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH5_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH5_CGC_SHIFT)) & PCC5_PCC_DMA2_CH5_CGC_MASK)

#define PCC5_PCC_DMA2_CH5_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH5_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH5_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH5_PR_SHIFT)) & PCC5_PCC_DMA2_CH5_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH6 - PCC DMA2_CH6 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH6_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH6_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH6_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH6_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH6_SSADO_MASK)

#define PCC5_PCC_DMA2_CH6_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH6_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH6_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH6_CGC_SHIFT)) & PCC5_PCC_DMA2_CH6_CGC_MASK)

#define PCC5_PCC_DMA2_CH6_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH6_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH6_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH6_PR_SHIFT)) & PCC5_PCC_DMA2_CH6_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH7 - PCC DMA2_CH7 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH7_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH7_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH7_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH7_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH7_SSADO_MASK)

#define PCC5_PCC_DMA2_CH7_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH7_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH7_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH7_CGC_SHIFT)) & PCC5_PCC_DMA2_CH7_CGC_MASK)

#define PCC5_PCC_DMA2_CH7_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH7_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH7_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH7_PR_SHIFT)) & PCC5_PCC_DMA2_CH7_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH8 - PCC DMA2_CH8 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH8_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH8_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH8_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH8_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH8_SSADO_MASK)

#define PCC5_PCC_DMA2_CH8_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH8_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH8_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH8_CGC_SHIFT)) & PCC5_PCC_DMA2_CH8_CGC_MASK)

#define PCC5_PCC_DMA2_CH8_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH8_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH8_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH8_PR_SHIFT)) & PCC5_PCC_DMA2_CH8_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH9 - PCC DMA2_CH9 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH9_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_DMA2_CH9_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH9_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH9_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH9_SSADO_MASK)

#define PCC5_PCC_DMA2_CH9_CGC_MASK               (0x40000000U)
#define PCC5_PCC_DMA2_CH9_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH9_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH9_CGC_SHIFT)) & PCC5_PCC_DMA2_CH9_CGC_MASK)

#define PCC5_PCC_DMA2_CH9_PR_MASK                (0x80000000U)
#define PCC5_PCC_DMA2_CH9_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH9_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH9_PR_SHIFT)) & PCC5_PCC_DMA2_CH9_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH10 - PCC DMA2_CH10 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH10_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH10_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH10_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH10_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH10_SSADO_MASK)

#define PCC5_PCC_DMA2_CH10_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH10_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH10_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH10_CGC_SHIFT)) & PCC5_PCC_DMA2_CH10_CGC_MASK)

#define PCC5_PCC_DMA2_CH10_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH10_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH10_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH10_PR_SHIFT)) & PCC5_PCC_DMA2_CH10_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH11 - PCC DMA2_CH11 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH11_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH11_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH11_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH11_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH11_SSADO_MASK)

#define PCC5_PCC_DMA2_CH11_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH11_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH11_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH11_CGC_SHIFT)) & PCC5_PCC_DMA2_CH11_CGC_MASK)

#define PCC5_PCC_DMA2_CH11_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH11_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH11_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH11_PR_SHIFT)) & PCC5_PCC_DMA2_CH11_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH12 - PCC DMA2_CH12 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH12_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH12_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH12_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH12_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH12_SSADO_MASK)

#define PCC5_PCC_DMA2_CH12_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH12_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH12_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH12_CGC_SHIFT)) & PCC5_PCC_DMA2_CH12_CGC_MASK)

#define PCC5_PCC_DMA2_CH12_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH12_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH12_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH12_PR_SHIFT)) & PCC5_PCC_DMA2_CH12_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH13 - PCC DMA2_CH13 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH13_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH13_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH13_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH13_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH13_SSADO_MASK)

#define PCC5_PCC_DMA2_CH13_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH13_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH13_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH13_CGC_SHIFT)) & PCC5_PCC_DMA2_CH13_CGC_MASK)

#define PCC5_PCC_DMA2_CH13_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH13_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH13_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH13_PR_SHIFT)) & PCC5_PCC_DMA2_CH13_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH14 - PCC DMA2_CH14 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH14_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH14_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH14_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH14_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH14_SSADO_MASK)

#define PCC5_PCC_DMA2_CH14_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH14_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH14_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH14_CGC_SHIFT)) & PCC5_PCC_DMA2_CH14_CGC_MASK)

#define PCC5_PCC_DMA2_CH14_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH14_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH14_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH14_PR_SHIFT)) & PCC5_PCC_DMA2_CH14_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH15 - PCC DMA2_CH15 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH15_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH15_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH15_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH15_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH15_SSADO_MASK)

#define PCC5_PCC_DMA2_CH15_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH15_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH15_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH15_CGC_SHIFT)) & PCC5_PCC_DMA2_CH15_CGC_MASK)

#define PCC5_PCC_DMA2_CH15_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH15_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH15_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH15_PR_SHIFT)) & PCC5_PCC_DMA2_CH15_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH16 - PCC DMA2_CH16 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH16_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH16_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH16_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH16_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH16_SSADO_MASK)

#define PCC5_PCC_DMA2_CH16_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH16_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH16_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH16_CGC_SHIFT)) & PCC5_PCC_DMA2_CH16_CGC_MASK)

#define PCC5_PCC_DMA2_CH16_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH16_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH16_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH16_PR_SHIFT)) & PCC5_PCC_DMA2_CH16_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH17 - PCC DMA2_CH17 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH17_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH17_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH17_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH17_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH17_SSADO_MASK)

#define PCC5_PCC_DMA2_CH17_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH17_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH17_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH17_CGC_SHIFT)) & PCC5_PCC_DMA2_CH17_CGC_MASK)

#define PCC5_PCC_DMA2_CH17_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH17_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH17_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH17_PR_SHIFT)) & PCC5_PCC_DMA2_CH17_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH18 - PCC DMA2_CH18 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH18_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH18_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH18_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH18_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH18_SSADO_MASK)

#define PCC5_PCC_DMA2_CH18_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH18_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH18_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH18_CGC_SHIFT)) & PCC5_PCC_DMA2_CH18_CGC_MASK)

#define PCC5_PCC_DMA2_CH18_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH18_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH18_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH18_PR_SHIFT)) & PCC5_PCC_DMA2_CH18_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH19 - PCC DMA2_CH19 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH19_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH19_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH19_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH19_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH19_SSADO_MASK)

#define PCC5_PCC_DMA2_CH19_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH19_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH19_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH19_CGC_SHIFT)) & PCC5_PCC_DMA2_CH19_CGC_MASK)

#define PCC5_PCC_DMA2_CH19_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH19_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH19_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH19_PR_SHIFT)) & PCC5_PCC_DMA2_CH19_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH20 - PCC DMA2_CH20 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH20_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH20_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH20_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH20_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH20_SSADO_MASK)

#define PCC5_PCC_DMA2_CH20_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH20_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH20_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH20_CGC_SHIFT)) & PCC5_PCC_DMA2_CH20_CGC_MASK)

#define PCC5_PCC_DMA2_CH20_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH20_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH20_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH20_PR_SHIFT)) & PCC5_PCC_DMA2_CH20_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH21 - PCC DMA2_CH21 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH21_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH21_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH21_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH21_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH21_SSADO_MASK)

#define PCC5_PCC_DMA2_CH21_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH21_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH21_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH21_CGC_SHIFT)) & PCC5_PCC_DMA2_CH21_CGC_MASK)

#define PCC5_PCC_DMA2_CH21_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH21_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH21_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH21_PR_SHIFT)) & PCC5_PCC_DMA2_CH21_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH22 - PCC DMA2_CH22 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH22_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH22_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH22_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH22_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH22_SSADO_MASK)

#define PCC5_PCC_DMA2_CH22_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH22_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH22_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH22_CGC_SHIFT)) & PCC5_PCC_DMA2_CH22_CGC_MASK)

#define PCC5_PCC_DMA2_CH22_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH22_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH22_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH22_PR_SHIFT)) & PCC5_PCC_DMA2_CH22_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH23 - PCC DMA2_CH23 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH23_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH23_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH23_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH23_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH23_SSADO_MASK)

#define PCC5_PCC_DMA2_CH23_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH23_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH23_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH23_CGC_SHIFT)) & PCC5_PCC_DMA2_CH23_CGC_MASK)

#define PCC5_PCC_DMA2_CH23_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH23_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH23_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH23_PR_SHIFT)) & PCC5_PCC_DMA2_CH23_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH24 - PCC DMA2_CH24 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH24_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH24_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH24_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH24_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH24_SSADO_MASK)

#define PCC5_PCC_DMA2_CH24_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH24_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH24_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH24_CGC_SHIFT)) & PCC5_PCC_DMA2_CH24_CGC_MASK)

#define PCC5_PCC_DMA2_CH24_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH24_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH24_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH24_PR_SHIFT)) & PCC5_PCC_DMA2_CH24_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH25 - PCC DMA2_CH25 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH25_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH25_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH25_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH25_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH25_SSADO_MASK)

#define PCC5_PCC_DMA2_CH25_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH25_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH25_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH25_CGC_SHIFT)) & PCC5_PCC_DMA2_CH25_CGC_MASK)

#define PCC5_PCC_DMA2_CH25_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH25_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH25_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH25_PR_SHIFT)) & PCC5_PCC_DMA2_CH25_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH26 - PCC DMA2_CH26 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH26_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH26_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH26_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH26_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH26_SSADO_MASK)

#define PCC5_PCC_DMA2_CH26_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH26_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH26_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH26_CGC_SHIFT)) & PCC5_PCC_DMA2_CH26_CGC_MASK)

#define PCC5_PCC_DMA2_CH26_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH26_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH26_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH26_PR_SHIFT)) & PCC5_PCC_DMA2_CH26_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH27 - PCC DMA2_CH27 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH27_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH27_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH27_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH27_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH27_SSADO_MASK)

#define PCC5_PCC_DMA2_CH27_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH27_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH27_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH27_CGC_SHIFT)) & PCC5_PCC_DMA2_CH27_CGC_MASK)

#define PCC5_PCC_DMA2_CH27_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH27_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH27_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH27_PR_SHIFT)) & PCC5_PCC_DMA2_CH27_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH28 - PCC DMA2_CH28 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH28_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH28_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH28_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH28_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH28_SSADO_MASK)

#define PCC5_PCC_DMA2_CH28_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH28_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH28_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH28_CGC_SHIFT)) & PCC5_PCC_DMA2_CH28_CGC_MASK)

#define PCC5_PCC_DMA2_CH28_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH28_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH28_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH28_PR_SHIFT)) & PCC5_PCC_DMA2_CH28_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH29 - PCC DMA2_CH29 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH29_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH29_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH29_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH29_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH29_SSADO_MASK)

#define PCC5_PCC_DMA2_CH29_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH29_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH29_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH29_CGC_SHIFT)) & PCC5_PCC_DMA2_CH29_CGC_MASK)

#define PCC5_PCC_DMA2_CH29_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH29_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH29_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH29_PR_SHIFT)) & PCC5_PCC_DMA2_CH29_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH30 - PCC DMA2_CH30 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH30_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH30_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH30_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH30_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH30_SSADO_MASK)

#define PCC5_PCC_DMA2_CH30_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH30_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH30_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH30_CGC_SHIFT)) & PCC5_PCC_DMA2_CH30_CGC_MASK)

#define PCC5_PCC_DMA2_CH30_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH30_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH30_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH30_PR_SHIFT)) & PCC5_PCC_DMA2_CH30_PR_MASK)
/*! @} */

/*! @name PCC_DMA2_CH31 - PCC DMA2_CH31 Register */
/*! @{ */

#define PCC5_PCC_DMA2_CH31_SSADO_MASK            (0xC00000U)
#define PCC5_PCC_DMA2_CH31_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DMA2_CH31_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH31_SSADO_SHIFT)) & PCC5_PCC_DMA2_CH31_SSADO_MASK)

#define PCC5_PCC_DMA2_CH31_CGC_MASK              (0x40000000U)
#define PCC5_PCC_DMA2_CH31_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DMA2_CH31_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH31_CGC_SHIFT)) & PCC5_PCC_DMA2_CH31_CGC_MASK)

#define PCC5_PCC_DMA2_CH31_PR_MASK               (0x80000000U)
#define PCC5_PCC_DMA2_CH31_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DMA2_CH31_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DMA2_CH31_PR_SHIFT)) & PCC5_PCC_DMA2_CH31_PR_MASK)
/*! @} */

/*! @name PCC_MU2_B - PCC MU2_B Register */
/*! @{ */

#define PCC5_PCC_MU2_B_SSADO_MASK                (0xC00000U)
#define PCC5_PCC_MU2_B_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_MU2_B_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_MU2_B_SSADO_SHIFT)) & PCC5_PCC_MU2_B_SSADO_MASK)

#define PCC5_PCC_MU2_B_CGC_MASK                  (0x40000000U)
#define PCC5_PCC_MU2_B_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_MU2_B_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_MU2_B_CGC_SHIFT)) & PCC5_PCC_MU2_B_CGC_MASK)

#define PCC5_PCC_MU2_B_PR_MASK                   (0x80000000U)
#define PCC5_PCC_MU2_B_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_MU2_B_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_MU2_B_PR_SHIFT)) & PCC5_PCC_MU2_B_PR_MASK)
/*! @} */

/*! @name PCC_MU3_B - PCC MU3_B Register */
/*! @{ */

#define PCC5_PCC_MU3_B_SSADO_MASK                (0xC00000U)
#define PCC5_PCC_MU3_B_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_MU3_B_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_MU3_B_SSADO_SHIFT)) & PCC5_PCC_MU3_B_SSADO_MASK)

#define PCC5_PCC_MU3_B_CGC_MASK                  (0x40000000U)
#define PCC5_PCC_MU3_B_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_MU3_B_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_MU3_B_CGC_SHIFT)) & PCC5_PCC_MU3_B_CGC_MASK)

#define PCC5_PCC_MU3_B_PR_MASK                   (0x80000000U)
#define PCC5_PCC_MU3_B_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_MU3_B_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_MU3_B_PR_SHIFT)) & PCC5_PCC_MU3_B_PR_MASK)
/*! @} */

/*! @name PCC_SEMA42_2 - PCC SEMA42_2 Register */
/*! @{ */

#define PCC5_PCC_SEMA42_2_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_SEMA42_2_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_SEMA42_2_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SEMA42_2_SSADO_SHIFT)) & PCC5_PCC_SEMA42_2_SSADO_MASK)

#define PCC5_PCC_SEMA42_2_CGC_MASK               (0x40000000U)
#define PCC5_PCC_SEMA42_2_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_SEMA42_2_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SEMA42_2_CGC_SHIFT)) & PCC5_PCC_SEMA42_2_CGC_MASK)

#define PCC5_PCC_SEMA42_2_PR_MASK                (0x80000000U)
#define PCC5_PCC_SEMA42_2_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_SEMA42_2_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SEMA42_2_PR_SHIFT)) & PCC5_PCC_SEMA42_2_PR_MASK)
/*! @} */

/*! @name PCC_TPM8 - PCC TPM8 Register */
/*! @{ */

#define PCC5_PCC_TPM8_PCD_MASK                   (0x7U)
#define PCC5_PCC_TPM8_PCD_SHIFT                  (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_TPM8_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_PCD_SHIFT)) & PCC5_PCC_TPM8_PCD_MASK)

#define PCC5_PCC_TPM8_FRAC_MASK                  (0x8U)
#define PCC5_PCC_TPM8_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_TPM8_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_FRAC_SHIFT)) & PCC5_PCC_TPM8_FRAC_MASK)

#define PCC5_PCC_TPM8_SSADO_MASK                 (0xC00000U)
#define PCC5_PCC_TPM8_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_TPM8_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_SSADO_SHIFT)) & PCC5_PCC_TPM8_SSADO_MASK)

#define PCC5_PCC_TPM8_PCS_MASK                   (0x7000000U)
#define PCC5_PCC_TPM8_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_TPM8_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_PCS_SHIFT)) & PCC5_PCC_TPM8_PCS_MASK)

#define PCC5_PCC_TPM8_SWRST_MASK                 (0x10000000U)
#define PCC5_PCC_TPM8_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_TPM8_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_SWRST_SHIFT)) & PCC5_PCC_TPM8_SWRST_MASK)

#define PCC5_PCC_TPM8_CGC_MASK                   (0x40000000U)
#define PCC5_PCC_TPM8_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_TPM8_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_CGC_SHIFT)) & PCC5_PCC_TPM8_CGC_MASK)

#define PCC5_PCC_TPM8_PR_MASK                    (0x80000000U)
#define PCC5_PCC_TPM8_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_TPM8_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_TPM8_PR_SHIFT)) & PCC5_PCC_TPM8_PR_MASK)
/*! @} */

/*! @name PCC_SAI6 - PCC SAI6 Register */
/*! @{ */

#define PCC5_PCC_SAI6_SSADO_MASK                 (0xC00000U)
#define PCC5_PCC_SAI6_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_SAI6_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI6_SSADO_SHIFT)) & PCC5_PCC_SAI6_SSADO_MASK)

#define PCC5_PCC_SAI6_SWRST_MASK                 (0x10000000U)
#define PCC5_PCC_SAI6_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_SAI6_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI6_SWRST_SHIFT)) & PCC5_PCC_SAI6_SWRST_MASK)

#define PCC5_PCC_SAI6_CGC_MASK                   (0x40000000U)
#define PCC5_PCC_SAI6_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_SAI6_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI6_CGC_SHIFT)) & PCC5_PCC_SAI6_CGC_MASK)

#define PCC5_PCC_SAI6_PR_MASK                    (0x80000000U)
#define PCC5_PCC_SAI6_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_SAI6_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI6_PR_SHIFT)) & PCC5_PCC_SAI6_PR_MASK)
/*! @} */

/*! @name PCC_SAI7 - PCC SAI7 Register */
/*! @{ */

#define PCC5_PCC_SAI7_SSADO_MASK                 (0xC00000U)
#define PCC5_PCC_SAI7_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_SAI7_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI7_SSADO_SHIFT)) & PCC5_PCC_SAI7_SSADO_MASK)

#define PCC5_PCC_SAI7_SWRST_MASK                 (0x10000000U)
#define PCC5_PCC_SAI7_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_SAI7_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI7_SWRST_SHIFT)) & PCC5_PCC_SAI7_SWRST_MASK)

#define PCC5_PCC_SAI7_CGC_MASK                   (0x40000000U)
#define PCC5_PCC_SAI7_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_SAI7_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI7_CGC_SHIFT)) & PCC5_PCC_SAI7_CGC_MASK)

#define PCC5_PCC_SAI7_PR_MASK                    (0x80000000U)
#define PCC5_PCC_SAI7_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_SAI7_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SAI7_PR_SHIFT)) & PCC5_PCC_SAI7_PR_MASK)
/*! @} */

/*! @name PCC_SPDIF - PCC SPDIF Register */
/*! @{ */

#define PCC5_PCC_SPDIF_SSADO_MASK                (0xC00000U)
#define PCC5_PCC_SPDIF_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_SPDIF_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SPDIF_SSADO_SHIFT)) & PCC5_PCC_SPDIF_SSADO_MASK)

#define PCC5_PCC_SPDIF_SWRST_MASK                (0x10000000U)
#define PCC5_PCC_SPDIF_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_SPDIF_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SPDIF_SWRST_SHIFT)) & PCC5_PCC_SPDIF_SWRST_MASK)

#define PCC5_PCC_SPDIF_CGC_MASK                  (0x40000000U)
#define PCC5_PCC_SPDIF_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_SPDIF_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SPDIF_CGC_SHIFT)) & PCC5_PCC_SPDIF_CGC_MASK)

#define PCC5_PCC_SPDIF_PR_MASK                   (0x80000000U)
#define PCC5_PCC_SPDIF_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_SPDIF_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_SPDIF_PR_SHIFT)) & PCC5_PCC_SPDIF_PR_MASK)
/*! @} */

/*! @name PCC_ISI - PCC ISI Register */
/*! @{ */

#define PCC5_PCC_ISI_SSADO_MASK                  (0xC00000U)
#define PCC5_PCC_ISI_SSADO_SHIFT                 (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_ISI_SSADO(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_ISI_SSADO_SHIFT)) & PCC5_PCC_ISI_SSADO_MASK)

#define PCC5_PCC_ISI_SWRST_MASK                  (0x10000000U)
#define PCC5_PCC_ISI_SWRST_SHIFT                 (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_ISI_SWRST(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_ISI_SWRST_SHIFT)) & PCC5_PCC_ISI_SWRST_MASK)

#define PCC5_PCC_ISI_CGC_MASK                    (0x40000000U)
#define PCC5_PCC_ISI_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_ISI_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_ISI_CGC_SHIFT)) & PCC5_PCC_ISI_CGC_MASK)

#define PCC5_PCC_ISI_PR_MASK                     (0x80000000U)
#define PCC5_PCC_ISI_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_ISI_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_ISI_PR_SHIFT)) & PCC5_PCC_ISI_PR_MASK)
/*! @} */

/*! @name PCC_CSI_REGS - PCC CSI_REGS Register */
/*! @{ */

#define PCC5_PCC_CSI_REGS_SSADO_MASK             (0xC00000U)
#define PCC5_PCC_CSI_REGS_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_CSI_REGS_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_REGS_SSADO_SHIFT)) & PCC5_PCC_CSI_REGS_SSADO_MASK)

#define PCC5_PCC_CSI_REGS_SWRST_MASK             (0x10000000U)
#define PCC5_PCC_CSI_REGS_SWRST_SHIFT            (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_CSI_REGS_SWRST(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_REGS_SWRST_SHIFT)) & PCC5_PCC_CSI_REGS_SWRST_MASK)

#define PCC5_PCC_CSI_REGS_CGC_MASK               (0x40000000U)
#define PCC5_PCC_CSI_REGS_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_CSI_REGS_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_REGS_CGC_SHIFT)) & PCC5_PCC_CSI_REGS_CGC_MASK)

#define PCC5_PCC_CSI_REGS_PR_MASK                (0x80000000U)
#define PCC5_PCC_CSI_REGS_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_CSI_REGS_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_REGS_PR_SHIFT)) & PCC5_PCC_CSI_REGS_PR_MASK)
/*! @} */

/*! @name PCC_CSI - PCC CSI Register */
/*! @{ */

#define PCC5_PCC_CSI_PCD_MASK                    (0x7U)
#define PCC5_PCC_CSI_PCD_SHIFT                   (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_CSI_PCD(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_PCD_SHIFT)) & PCC5_PCC_CSI_PCD_MASK)

#define PCC5_PCC_CSI_FRAC_MASK                   (0x8U)
#define PCC5_PCC_CSI_FRAC_SHIFT                  (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_CSI_FRAC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_FRAC_SHIFT)) & PCC5_PCC_CSI_FRAC_MASK)

#define PCC5_PCC_CSI_SSADO_MASK                  (0xC00000U)
#define PCC5_PCC_CSI_SSADO_SHIFT                 (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_CSI_SSADO(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_SSADO_SHIFT)) & PCC5_PCC_CSI_SSADO_MASK)

#define PCC5_PCC_CSI_PCS_MASK                    (0x7000000U)
#define PCC5_PCC_CSI_PCS_SHIFT                   (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_CSI_PCS(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_PCS_SHIFT)) & PCC5_PCC_CSI_PCS_MASK)

#define PCC5_PCC_CSI_SWRST_MASK                  (0x10000000U)
#define PCC5_PCC_CSI_SWRST_SHIFT                 (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_CSI_SWRST(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_SWRST_SHIFT)) & PCC5_PCC_CSI_SWRST_MASK)

#define PCC5_PCC_CSI_CGC_MASK                    (0x40000000U)
#define PCC5_PCC_CSI_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_CSI_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CGC_SHIFT)) & PCC5_PCC_CSI_CGC_MASK)

#define PCC5_PCC_CSI_PR_MASK                     (0x80000000U)
#define PCC5_PCC_CSI_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_CSI_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_PR_SHIFT)) & PCC5_PCC_CSI_PR_MASK)
/*! @} */

/*! @name PCC_DSI - PCC DSI Register */
/*! @{ */

#define PCC5_PCC_DSI_PCD_MASK                    (0x7U)
#define PCC5_PCC_DSI_PCD_SHIFT                   (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_DSI_PCD(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_PCD_SHIFT)) & PCC5_PCC_DSI_PCD_MASK)

#define PCC5_PCC_DSI_FRAC_MASK                   (0x8U)
#define PCC5_PCC_DSI_FRAC_SHIFT                  (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_DSI_FRAC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_FRAC_SHIFT)) & PCC5_PCC_DSI_FRAC_MASK)

#define PCC5_PCC_DSI_SSADO_MASK                  (0xC00000U)
#define PCC5_PCC_DSI_SSADO_SHIFT                 (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DSI_SSADO(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_SSADO_SHIFT)) & PCC5_PCC_DSI_SSADO_MASK)

#define PCC5_PCC_DSI_PCS_MASK                    (0x7000000U)
#define PCC5_PCC_DSI_PCS_SHIFT                   (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_DSI_PCS(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_PCS_SHIFT)) & PCC5_PCC_DSI_PCS_MASK)

#define PCC5_PCC_DSI_SWRST_MASK                  (0x10000000U)
#define PCC5_PCC_DSI_SWRST_SHIFT                 (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_DSI_SWRST(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_SWRST_SHIFT)) & PCC5_PCC_DSI_SWRST_MASK)

#define PCC5_PCC_DSI_CGC_MASK                    (0x40000000U)
#define PCC5_PCC_DSI_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DSI_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_CGC_SHIFT)) & PCC5_PCC_DSI_CGC_MASK)

#define PCC5_PCC_DSI_PR_MASK                     (0x80000000U)
#define PCC5_PCC_DSI_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DSI_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DSI_PR_SHIFT)) & PCC5_PCC_DSI_PR_MASK)
/*! @} */

/*! @name PCC_WDOG5 - PCC WDOG5 Register */
/*! @{ */

#define PCC5_PCC_WDOG5_PCD_MASK                  (0x7U)
#define PCC5_PCC_WDOG5_PCD_SHIFT                 (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_WDOG5_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_PCD_SHIFT)) & PCC5_PCC_WDOG5_PCD_MASK)

#define PCC5_PCC_WDOG5_FRAC_MASK                 (0x8U)
#define PCC5_PCC_WDOG5_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_WDOG5_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_FRAC_SHIFT)) & PCC5_PCC_WDOG5_FRAC_MASK)

#define PCC5_PCC_WDOG5_SSADO_MASK                (0xC00000U)
#define PCC5_PCC_WDOG5_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_WDOG5_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_SSADO_SHIFT)) & PCC5_PCC_WDOG5_SSADO_MASK)

#define PCC5_PCC_WDOG5_PCS_MASK                  (0x7000000U)
#define PCC5_PCC_WDOG5_PCS_SHIFT                 (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_WDOG5_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_PCS_SHIFT)) & PCC5_PCC_WDOG5_PCS_MASK)

#define PCC5_PCC_WDOG5_SWRST_MASK                (0x10000000U)
#define PCC5_PCC_WDOG5_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_WDOG5_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_SWRST_SHIFT)) & PCC5_PCC_WDOG5_SWRST_MASK)

#define PCC5_PCC_WDOG5_CGC_MASK                  (0x40000000U)
#define PCC5_PCC_WDOG5_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_WDOG5_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_CGC_SHIFT)) & PCC5_PCC_WDOG5_CGC_MASK)

#define PCC5_PCC_WDOG5_PR_MASK                   (0x80000000U)
#define PCC5_PCC_WDOG5_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_WDOG5_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_WDOG5_PR_SHIFT)) & PCC5_PCC_WDOG5_PR_MASK)
/*! @} */

/*! @name PCC_EPDC - PCC EPDC Register */
/*! @{ */

#define PCC5_PCC_EPDC_PCD_MASK                   (0x7U)
#define PCC5_PCC_EPDC_PCD_SHIFT                  (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_EPDC_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_PCD_SHIFT)) & PCC5_PCC_EPDC_PCD_MASK)

#define PCC5_PCC_EPDC_FRAC_MASK                  (0x8U)
#define PCC5_PCC_EPDC_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_EPDC_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_FRAC_SHIFT)) & PCC5_PCC_EPDC_FRAC_MASK)

#define PCC5_PCC_EPDC_SSADO_MASK                 (0xC00000U)
#define PCC5_PCC_EPDC_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_EPDC_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_SSADO_SHIFT)) & PCC5_PCC_EPDC_SSADO_MASK)

#define PCC5_PCC_EPDC_PCS_MASK                   (0x7000000U)
#define PCC5_PCC_EPDC_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_EPDC_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_PCS_SHIFT)) & PCC5_PCC_EPDC_PCS_MASK)

#define PCC5_PCC_EPDC_SWRST_MASK                 (0x10000000U)
#define PCC5_PCC_EPDC_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_EPDC_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_SWRST_SHIFT)) & PCC5_PCC_EPDC_SWRST_MASK)

#define PCC5_PCC_EPDC_CGC_MASK                   (0x40000000U)
#define PCC5_PCC_EPDC_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_EPDC_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_CGC_SHIFT)) & PCC5_PCC_EPDC_CGC_MASK)

#define PCC5_PCC_EPDC_PR_MASK                    (0x80000000U)
#define PCC5_PCC_EPDC_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_EPDC_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_EPDC_PR_SHIFT)) & PCC5_PCC_EPDC_PR_MASK)
/*! @} */

/*! @name PCC_PXP - PCC PXP Register */
/*! @{ */

#define PCC5_PCC_PXP_SSADO_MASK                  (0xC00000U)
#define PCC5_PCC_PXP_SSADO_SHIFT                 (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_PXP_SSADO(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_PXP_SSADO_SHIFT)) & PCC5_PCC_PXP_SSADO_MASK)

#define PCC5_PCC_PXP_SWRST_MASK                  (0x10000000U)
#define PCC5_PCC_PXP_SWRST_SHIFT                 (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_PXP_SWRST(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_PXP_SWRST_SHIFT)) & PCC5_PCC_PXP_SWRST_MASK)

#define PCC5_PCC_PXP_CGC_MASK                    (0x40000000U)
#define PCC5_PCC_PXP_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_PXP_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_PXP_CGC_SHIFT)) & PCC5_PCC_PXP_CGC_MASK)

#define PCC5_PCC_PXP_PR_MASK                     (0x80000000U)
#define PCC5_PCC_PXP_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_PXP_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_PXP_PR_SHIFT)) & PCC5_PCC_PXP_PR_MASK)
/*! @} */

/*! @name PCC_GPU2D - PCC GPU2D Register */
/*! @{ */

#define PCC5_PCC_GPU2D_PCD_MASK                  (0x7U)
#define PCC5_PCC_GPU2D_PCD_SHIFT                 (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_GPU2D_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_PCD_SHIFT)) & PCC5_PCC_GPU2D_PCD_MASK)

#define PCC5_PCC_GPU2D_FRAC_MASK                 (0x8U)
#define PCC5_PCC_GPU2D_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_GPU2D_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_FRAC_SHIFT)) & PCC5_PCC_GPU2D_FRAC_MASK)

#define PCC5_PCC_GPU2D_SSADO_MASK                (0xC00000U)
#define PCC5_PCC_GPU2D_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_GPU2D_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_SSADO_SHIFT)) & PCC5_PCC_GPU2D_SSADO_MASK)

#define PCC5_PCC_GPU2D_PCS_MASK                  (0x7000000U)
#define PCC5_PCC_GPU2D_PCS_SHIFT                 (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_GPU2D_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_PCS_SHIFT)) & PCC5_PCC_GPU2D_PCS_MASK)

#define PCC5_PCC_GPU2D_SWRST_MASK                (0x10000000U)
#define PCC5_PCC_GPU2D_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_GPU2D_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_SWRST_SHIFT)) & PCC5_PCC_GPU2D_SWRST_MASK)

#define PCC5_PCC_GPU2D_CGC_MASK                  (0x40000000U)
#define PCC5_PCC_GPU2D_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_GPU2D_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_CGC_SHIFT)) & PCC5_PCC_GPU2D_CGC_MASK)

#define PCC5_PCC_GPU2D_PR_MASK                   (0x80000000U)
#define PCC5_PCC_GPU2D_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_GPU2D_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU2D_PR_SHIFT)) & PCC5_PCC_GPU2D_PR_MASK)
/*! @} */

/*! @name PCC_GPU3D - PCC GPU3D Register */
/*! @{ */

#define PCC5_PCC_GPU3D_PCD_MASK                  (0x7U)
#define PCC5_PCC_GPU3D_PCD_SHIFT                 (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_GPU3D_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_PCD_SHIFT)) & PCC5_PCC_GPU3D_PCD_MASK)

#define PCC5_PCC_GPU3D_FRAC_MASK                 (0x8U)
#define PCC5_PCC_GPU3D_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_GPU3D_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_FRAC_SHIFT)) & PCC5_PCC_GPU3D_FRAC_MASK)

#define PCC5_PCC_GPU3D_SSADO_MASK                (0xC00000U)
#define PCC5_PCC_GPU3D_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_GPU3D_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_SSADO_SHIFT)) & PCC5_PCC_GPU3D_SSADO_MASK)

#define PCC5_PCC_GPU3D_PCS_MASK                  (0x7000000U)
#define PCC5_PCC_GPU3D_PCS_SHIFT                 (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_GPU3D_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_PCS_SHIFT)) & PCC5_PCC_GPU3D_PCS_MASK)

#define PCC5_PCC_GPU3D_SWRST_MASK                (0x10000000U)
#define PCC5_PCC_GPU3D_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_GPU3D_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_SWRST_SHIFT)) & PCC5_PCC_GPU3D_SWRST_MASK)

#define PCC5_PCC_GPU3D_CGC_MASK                  (0x40000000U)
#define PCC5_PCC_GPU3D_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_GPU3D_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_CGC_SHIFT)) & PCC5_PCC_GPU3D_CGC_MASK)

#define PCC5_PCC_GPU3D_PR_MASK                   (0x80000000U)
#define PCC5_PCC_GPU3D_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_GPU3D_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_GPU3D_PR_SHIFT)) & PCC5_PCC_GPU3D_PR_MASK)
/*! @} */

/*! @name PCC_DC_NANO - PCC DC_Nano Register */
/*! @{ */

#define PCC5_PCC_DC_NANO_PCD_MASK                (0x7U)
#define PCC5_PCC_DC_NANO_PCD_SHIFT               (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_DC_NANO_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_PCD_SHIFT)) & PCC5_PCC_DC_NANO_PCD_MASK)

#define PCC5_PCC_DC_NANO_FRAC_MASK               (0x8U)
#define PCC5_PCC_DC_NANO_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_DC_NANO_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_FRAC_SHIFT)) & PCC5_PCC_DC_NANO_FRAC_MASK)

#define PCC5_PCC_DC_NANO_SSADO_MASK              (0xC00000U)
#define PCC5_PCC_DC_NANO_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_DC_NANO_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_SSADO_SHIFT)) & PCC5_PCC_DC_NANO_SSADO_MASK)

#define PCC5_PCC_DC_NANO_PCS_MASK                (0x7000000U)
#define PCC5_PCC_DC_NANO_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_DC_NANO_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_PCS_SHIFT)) & PCC5_PCC_DC_NANO_PCS_MASK)

#define PCC5_PCC_DC_NANO_SWRST_MASK              (0x10000000U)
#define PCC5_PCC_DC_NANO_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_DC_NANO_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_SWRST_SHIFT)) & PCC5_PCC_DC_NANO_SWRST_MASK)

#define PCC5_PCC_DC_NANO_CGC_MASK                (0x40000000U)
#define PCC5_PCC_DC_NANO_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_DC_NANO_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_CGC_SHIFT)) & PCC5_PCC_DC_NANO_CGC_MASK)

#define PCC5_PCC_DC_NANO_PR_MASK                 (0x80000000U)
#define PCC5_PCC_DC_NANO_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_DC_NANO_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_DC_NANO_PR_SHIFT)) & PCC5_PCC_DC_NANO_PR_MASK)
/*! @} */

/*! @name PCC_LPDDR4 - PCC LPDDR4 Register */
/*! @{ */

#define PCC5_PCC_LPDDR4_SSADO_MASK               (0xC00000U)
#define PCC5_PCC_LPDDR4_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_LPDDR4_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_LPDDR4_SSADO_SHIFT)) & PCC5_PCC_LPDDR4_SSADO_MASK)

#define PCC5_PCC_LPDDR4_SWRST_MASK               (0x10000000U)
#define PCC5_PCC_LPDDR4_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC5_PCC_LPDDR4_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_LPDDR4_SWRST_SHIFT)) & PCC5_PCC_LPDDR4_SWRST_MASK)

#define PCC5_PCC_LPDDR4_CGC_MASK                 (0x40000000U)
#define PCC5_PCC_LPDDR4_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_LPDDR4_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_LPDDR4_CGC_SHIFT)) & PCC5_PCC_LPDDR4_CGC_MASK)

#define PCC5_PCC_LPDDR4_PR_MASK                  (0x80000000U)
#define PCC5_PCC_LPDDR4_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_LPDDR4_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_LPDDR4_PR_SHIFT)) & PCC5_PCC_LPDDR4_PR_MASK)
/*! @} */

/*! @name PCC_CSI_CLK_UI - PCC CSI_clk_ui Register */
/*! @{ */

#define PCC5_PCC_CSI_CLK_UI_PCD_MASK             (0x7U)
#define PCC5_PCC_CSI_CLK_UI_PCD_SHIFT            (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_CSI_CLK_UI_PCD(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_UI_PCD_SHIFT)) & PCC5_PCC_CSI_CLK_UI_PCD_MASK)

#define PCC5_PCC_CSI_CLK_UI_FRAC_MASK            (0x8U)
#define PCC5_PCC_CSI_CLK_UI_FRAC_SHIFT           (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_CSI_CLK_UI_FRAC(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_UI_FRAC_SHIFT)) & PCC5_PCC_CSI_CLK_UI_FRAC_MASK)

#define PCC5_PCC_CSI_CLK_UI_SSADO_MASK           (0xC00000U)
#define PCC5_PCC_CSI_CLK_UI_SSADO_SHIFT          (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_CSI_CLK_UI_SSADO(x)             (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_UI_SSADO_SHIFT)) & PCC5_PCC_CSI_CLK_UI_SSADO_MASK)

#define PCC5_PCC_CSI_CLK_UI_PCS_MASK             (0x7000000U)
#define PCC5_PCC_CSI_CLK_UI_PCS_SHIFT            (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_CSI_CLK_UI_PCS(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_UI_PCS_SHIFT)) & PCC5_PCC_CSI_CLK_UI_PCS_MASK)

#define PCC5_PCC_CSI_CLK_UI_CGC_MASK             (0x40000000U)
#define PCC5_PCC_CSI_CLK_UI_CGC_SHIFT            (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_CSI_CLK_UI_CGC(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_UI_CGC_SHIFT)) & PCC5_PCC_CSI_CLK_UI_CGC_MASK)

#define PCC5_PCC_CSI_CLK_UI_PR_MASK              (0x80000000U)
#define PCC5_PCC_CSI_CLK_UI_PR_SHIFT             (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_CSI_CLK_UI_PR(x)                (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_UI_PR_SHIFT)) & PCC5_PCC_CSI_CLK_UI_PR_MASK)
/*! @} */

/*! @name PCC_CSI_CLK_ESC - PCC CSI_clk_esc Register */
/*! @{ */

#define PCC5_PCC_CSI_CLK_ESC_PCD_MASK            (0x7U)
#define PCC5_PCC_CSI_CLK_ESC_PCD_SHIFT           (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC5_PCC_CSI_CLK_ESC_PCD(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_ESC_PCD_SHIFT)) & PCC5_PCC_CSI_CLK_ESC_PCD_MASK)

#define PCC5_PCC_CSI_CLK_ESC_FRAC_MASK           (0x8U)
#define PCC5_PCC_CSI_CLK_ESC_FRAC_SHIFT          (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC5_PCC_CSI_CLK_ESC_FRAC(x)             (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_ESC_FRAC_SHIFT)) & PCC5_PCC_CSI_CLK_ESC_FRAC_MASK)

#define PCC5_PCC_CSI_CLK_ESC_SSADO_MASK          (0xC00000U)
#define PCC5_PCC_CSI_CLK_ESC_SSADO_SHIFT         (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_CSI_CLK_ESC_SSADO(x)            (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_ESC_SSADO_SHIFT)) & PCC5_PCC_CSI_CLK_ESC_SSADO_MASK)

#define PCC5_PCC_CSI_CLK_ESC_PCS_MASK            (0x7000000U)
#define PCC5_PCC_CSI_CLK_ESC_PCS_SHIFT           (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC5_PCC_CSI_CLK_ESC_PCS(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_ESC_PCS_SHIFT)) & PCC5_PCC_CSI_CLK_ESC_PCS_MASK)

#define PCC5_PCC_CSI_CLK_ESC_CGC_MASK            (0x40000000U)
#define PCC5_PCC_CSI_CLK_ESC_CGC_SHIFT           (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_CSI_CLK_ESC_CGC(x)              (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_ESC_CGC_SHIFT)) & PCC5_PCC_CSI_CLK_ESC_CGC_MASK)

#define PCC5_PCC_CSI_CLK_ESC_PR_MASK             (0x80000000U)
#define PCC5_PCC_CSI_CLK_ESC_PR_SHIFT            (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_CSI_CLK_ESC_PR(x)               (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_CSI_CLK_ESC_PR_SHIFT)) & PCC5_PCC_CSI_CLK_ESC_PR_MASK)
/*! @} */

/*! @name PCC_RGPIOD - PCC RGPIOD Register */
/*! @{ */

#define PCC5_PCC_RGPIOD_SSADO_MASK               (0xC00000U)
#define PCC5_PCC_RGPIOD_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC5_PCC_RGPIOD_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_RGPIOD_SSADO_SHIFT)) & PCC5_PCC_RGPIOD_SSADO_MASK)

#define PCC5_PCC_RGPIOD_CGC_MASK                 (0x40000000U)
#define PCC5_PCC_RGPIOD_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC5_PCC_RGPIOD_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_RGPIOD_CGC_SHIFT)) & PCC5_PCC_RGPIOD_CGC_MASK)

#define PCC5_PCC_RGPIOD_PR_MASK                  (0x80000000U)
#define PCC5_PCC_RGPIOD_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC5_PCC_RGPIOD_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC5_PCC_RGPIOD_PR_SHIFT)) & PCC5_PCC_RGPIOD_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC5_Register_Masks */


/*!
 * @}
 */ /* end of group PCC5_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PCC5_H_ */

