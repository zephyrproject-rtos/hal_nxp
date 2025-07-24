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
**         CMSIS Peripheral Access Layer for PCC3
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
 * @file PERI_PCC3.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC3
 *
 * CMSIS Peripheral Access Layer for PCC3
 */

#if !defined(PERI_PCC3_H_)
#define PERI_PCC3_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC3_Peripheral_Access_Layer PCC3 Peripheral Access Layer
 * @{
 */

/** PCC3 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t PCC_DMA1_MP;                       /**< PCC DMA1_MP Register, offset: 0x4 */
  __IO uint32_t PCC_DMA1_CH0;                      /**< PCC DMA1_CH0 Register, offset: 0x8 */
  __IO uint32_t PCC_DMA1_CH1;                      /**< PCC DMA1_CH1 Register, offset: 0xC */
  __IO uint32_t PCC_DMA1_CH2;                      /**< PCC DMA1_CH2 Register, offset: 0x10 */
  __IO uint32_t PCC_DMA1_CH3;                      /**< PCC DMA1_CH3 Register, offset: 0x14 */
  __IO uint32_t PCC_DMA1_CH4;                      /**< PCC DMA1_CH4 Register, offset: 0x18 */
  __IO uint32_t PCC_DMA1_CH5;                      /**< PCC DMA1_CH5 Register, offset: 0x1C */
  __IO uint32_t PCC_DMA1_CH6;                      /**< PCC DMA1_CH6 Register, offset: 0x20 */
  __IO uint32_t PCC_DMA1_CH7;                      /**< PCC DMA1_CH7 Register, offset: 0x24 */
  __IO uint32_t PCC_DMA1_CH8;                      /**< PCC DMA1_CH8 Register, offset: 0x28 */
  __IO uint32_t PCC_DMA1_CH9;                      /**< PCC DMA1_CH9 Register, offset: 0x2C */
  __IO uint32_t PCC_DMA1_CH10;                     /**< PCC DMA1_CH10 Register, offset: 0x30 */
  __IO uint32_t PCC_DMA1_CH11;                     /**< PCC DMA1_CH11 Register, offset: 0x34 */
  __IO uint32_t PCC_DMA1_CH12;                     /**< PCC DMA1_CH12 Register, offset: 0x38 */
  __IO uint32_t PCC_DMA1_CH13;                     /**< PCC DMA1_CH13 Register, offset: 0x3C */
  __IO uint32_t PCC_DMA1_CH14;                     /**< PCC DMA1_CH14 Register, offset: 0x40 */
  __IO uint32_t PCC_DMA1_CH15;                     /**< PCC DMA1_CH15 Register, offset: 0x44 */
  __IO uint32_t PCC_DMA1_CH16;                     /**< PCC DMA1_CH16 Register, offset: 0x48 */
  __IO uint32_t PCC_DMA1_CH17;                     /**< PCC DMA1_CH17 Register, offset: 0x4C */
  __IO uint32_t PCC_DMA1_CH18;                     /**< PCC DMA1_CH18 Register, offset: 0x50 */
  __IO uint32_t PCC_DMA1_CH19;                     /**< PCC DMA1_CH19 Register, offset: 0x54 */
  __IO uint32_t PCC_DMA1_CH20;                     /**< PCC DMA1_CH20 Register, offset: 0x58 */
  __IO uint32_t PCC_DMA1_CH21;                     /**< PCC DMA1_CH21 Register, offset: 0x5C */
  __IO uint32_t PCC_DMA1_CH22;                     /**< PCC DMA1_CH22 Register, offset: 0x60 */
  __IO uint32_t PCC_DMA1_CH23;                     /**< PCC DMA1_CH23 Register, offset: 0x64 */
  __IO uint32_t PCC_DMA1_CH24;                     /**< PCC DMA1_CH24 Register, offset: 0x68 */
  __IO uint32_t PCC_DMA1_CH25;                     /**< PCC DMA1_CH25 Register, offset: 0x6C */
  __IO uint32_t PCC_DMA1_CH26;                     /**< PCC DMA1_CH26 Register, offset: 0x70 */
  __IO uint32_t PCC_DMA1_CH27;                     /**< PCC DMA1_CH27 Register, offset: 0x74 */
  __IO uint32_t PCC_DMA1_CH28;                     /**< PCC DMA1_CH28 Register, offset: 0x78 */
  __IO uint32_t PCC_DMA1_CH29;                     /**< PCC DMA1_CH29 Register, offset: 0x7C */
  __IO uint32_t PCC_DMA1_CH30;                     /**< PCC DMA1_CH30 Register, offset: 0x80 */
  __IO uint32_t PCC_DMA1_CH31;                     /**< PCC DMA1_CH31 Register, offset: 0x84 */
  __IO uint32_t PCC_MU0_B;                         /**< PCC MU0_B Register, offset: 0x88 */
  __IO uint32_t PCC_MU3_A;                         /**< PCC MU3_A Register, offset: 0x8C */
       uint8_t RESERVED_1[8];
  __IO uint32_t PCC_WUU1;                          /**< PCC WUU1 Register, offset: 0x98 */
  __IO uint32_t PCC_SYSPM1;                        /**< PCC SYSPM1 Register, offset: 0x9C */
  __IO uint32_t PCC_UPOWER_MUA_APD;                /**< PCC uPower_MUA_APD Register, offset: 0xA0 */
       uint8_t RESERVED_2[4];
  __IO uint32_t PCC_WDOG3;                         /**< PCC WDOG3 Register, offset: 0xA8 */
  __IO uint32_t PCC_WDOG4;                         /**< PCC WDOG4 Register, offset: 0xAC */
       uint8_t RESERVED_3[8];
  __IO uint32_t PCC_CAAM;                          /**< PCC CAAM Register, offset: 0xB8 */
  __IO uint32_t PCC_XRDC_MGR;                      /**< PCC XRDC_MGR Register, offset: 0xBC */
  __IO uint32_t PCC_SEMA42_1;                      /**< PCC SEMA42_1 Register, offset: 0xC0 */
  __IO uint32_t PCC_ROMCP1;                        /**< PCC ROMCP1 Register, offset: 0xC4 */
  __IO uint32_t PCC_LPIT1;                         /**< PCC LPIT1 Register, offset: 0xC8 */
  __IO uint32_t PCC_TPM4;                          /**< PCC TPM4 Register, offset: 0xCC */
  __IO uint32_t PCC_TPM5;                          /**< PCC TPM5 Register, offset: 0xD0 */
  __IO uint32_t PCC_FLEXIO1;                       /**< PCC FlexIO1 Register, offset: 0xD4 */
  __IO uint32_t PCC_I3C2;                          /**< PCC I3C2 Register, offset: 0xD8 */
  __IO uint32_t PCC_LPI2C4;                        /**< PCC LPI2C4 Register, offset: 0xDC */
  __IO uint32_t PCC_LPI2C5;                        /**< PCC LPI2C5 Register, offset: 0xE0 */
  __IO uint32_t PCC_LPUART4;                       /**< PCC LPUART4 Register, offset: 0xE4 */
  __IO uint32_t PCC_LPUART5;                       /**< PCC LPUART5 Register, offset: 0xE8 */
  __IO uint32_t PCC_LPSPI4;                        /**< PCC LPSPI4 Register, offset: 0xEC */
  __IO uint32_t PCC_LPSPI5;                        /**< PCC LPSPI5 Register, offset: 0xF0 */
} PCC3_Type;

/* ----------------------------------------------------------------------------
   -- PCC3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC3_Register_Masks PCC3 Register Masks
 * @{
 */

/*! @name PCC_DMA1_MP - PCC DMA1_MP Register */
/*! @{ */

#define PCC3_PCC_DMA1_MP_SSADO_MASK              (0xC00000U)
#define PCC3_PCC_DMA1_MP_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_MP_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_MP_SSADO_SHIFT)) & PCC3_PCC_DMA1_MP_SSADO_MASK)

#define PCC3_PCC_DMA1_MP_CGC_MASK                (0x40000000U)
#define PCC3_PCC_DMA1_MP_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_MP_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_MP_CGC_SHIFT)) & PCC3_PCC_DMA1_MP_CGC_MASK)

#define PCC3_PCC_DMA1_MP_PR_MASK                 (0x80000000U)
#define PCC3_PCC_DMA1_MP_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_MP_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_MP_PR_SHIFT)) & PCC3_PCC_DMA1_MP_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH0 - PCC DMA1_CH0 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH0_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH0_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH0_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH0_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH0_SSADO_MASK)

#define PCC3_PCC_DMA1_CH0_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH0_CGC_SHIFT)) & PCC3_PCC_DMA1_CH0_CGC_MASK)

#define PCC3_PCC_DMA1_CH0_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH0_PR_SHIFT)) & PCC3_PCC_DMA1_CH0_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH1 - PCC DMA1_CH1 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH1_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH1_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH1_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH1_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH1_SSADO_MASK)

#define PCC3_PCC_DMA1_CH1_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH1_CGC_SHIFT)) & PCC3_PCC_DMA1_CH1_CGC_MASK)

#define PCC3_PCC_DMA1_CH1_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH1_PR_SHIFT)) & PCC3_PCC_DMA1_CH1_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH2 - PCC DMA1_CH2 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH2_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH2_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH2_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH2_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH2_SSADO_MASK)

#define PCC3_PCC_DMA1_CH2_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH2_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH2_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH2_CGC_SHIFT)) & PCC3_PCC_DMA1_CH2_CGC_MASK)

#define PCC3_PCC_DMA1_CH2_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH2_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH2_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH2_PR_SHIFT)) & PCC3_PCC_DMA1_CH2_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH3 - PCC DMA1_CH3 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH3_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH3_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH3_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH3_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH3_SSADO_MASK)

#define PCC3_PCC_DMA1_CH3_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH3_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH3_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH3_CGC_SHIFT)) & PCC3_PCC_DMA1_CH3_CGC_MASK)

#define PCC3_PCC_DMA1_CH3_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH3_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH3_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH3_PR_SHIFT)) & PCC3_PCC_DMA1_CH3_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH4 - PCC DMA1_CH4 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH4_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH4_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH4_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH4_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH4_SSADO_MASK)

#define PCC3_PCC_DMA1_CH4_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH4_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH4_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH4_CGC_SHIFT)) & PCC3_PCC_DMA1_CH4_CGC_MASK)

#define PCC3_PCC_DMA1_CH4_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH4_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH4_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH4_PR_SHIFT)) & PCC3_PCC_DMA1_CH4_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH5 - PCC DMA1_CH5 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH5_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH5_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH5_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH5_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH5_SSADO_MASK)

#define PCC3_PCC_DMA1_CH5_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH5_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH5_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH5_CGC_SHIFT)) & PCC3_PCC_DMA1_CH5_CGC_MASK)

#define PCC3_PCC_DMA1_CH5_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH5_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH5_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH5_PR_SHIFT)) & PCC3_PCC_DMA1_CH5_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH6 - PCC DMA1_CH6 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH6_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH6_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH6_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH6_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH6_SSADO_MASK)

#define PCC3_PCC_DMA1_CH6_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH6_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH6_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH6_CGC_SHIFT)) & PCC3_PCC_DMA1_CH6_CGC_MASK)

#define PCC3_PCC_DMA1_CH6_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH6_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH6_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH6_PR_SHIFT)) & PCC3_PCC_DMA1_CH6_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH7 - PCC DMA1_CH7 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH7_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH7_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH7_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH7_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH7_SSADO_MASK)

#define PCC3_PCC_DMA1_CH7_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH7_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH7_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH7_CGC_SHIFT)) & PCC3_PCC_DMA1_CH7_CGC_MASK)

#define PCC3_PCC_DMA1_CH7_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH7_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH7_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH7_PR_SHIFT)) & PCC3_PCC_DMA1_CH7_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH8 - PCC DMA1_CH8 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH8_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH8_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH8_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH8_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH8_SSADO_MASK)

#define PCC3_PCC_DMA1_CH8_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH8_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH8_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH8_CGC_SHIFT)) & PCC3_PCC_DMA1_CH8_CGC_MASK)

#define PCC3_PCC_DMA1_CH8_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH8_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH8_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH8_PR_SHIFT)) & PCC3_PCC_DMA1_CH8_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH9 - PCC DMA1_CH9 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH9_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_DMA1_CH9_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH9_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH9_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH9_SSADO_MASK)

#define PCC3_PCC_DMA1_CH9_CGC_MASK               (0x40000000U)
#define PCC3_PCC_DMA1_CH9_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH9_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH9_CGC_SHIFT)) & PCC3_PCC_DMA1_CH9_CGC_MASK)

#define PCC3_PCC_DMA1_CH9_PR_MASK                (0x80000000U)
#define PCC3_PCC_DMA1_CH9_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH9_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH9_PR_SHIFT)) & PCC3_PCC_DMA1_CH9_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH10 - PCC DMA1_CH10 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH10_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH10_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH10_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH10_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH10_SSADO_MASK)

#define PCC3_PCC_DMA1_CH10_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH10_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH10_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH10_CGC_SHIFT)) & PCC3_PCC_DMA1_CH10_CGC_MASK)

#define PCC3_PCC_DMA1_CH10_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH10_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH10_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH10_PR_SHIFT)) & PCC3_PCC_DMA1_CH10_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH11 - PCC DMA1_CH11 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH11_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH11_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH11_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH11_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH11_SSADO_MASK)

#define PCC3_PCC_DMA1_CH11_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH11_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH11_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH11_CGC_SHIFT)) & PCC3_PCC_DMA1_CH11_CGC_MASK)

#define PCC3_PCC_DMA1_CH11_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH11_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH11_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH11_PR_SHIFT)) & PCC3_PCC_DMA1_CH11_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH12 - PCC DMA1_CH12 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH12_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH12_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH12_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH12_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH12_SSADO_MASK)

#define PCC3_PCC_DMA1_CH12_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH12_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH12_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH12_CGC_SHIFT)) & PCC3_PCC_DMA1_CH12_CGC_MASK)

#define PCC3_PCC_DMA1_CH12_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH12_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH12_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH12_PR_SHIFT)) & PCC3_PCC_DMA1_CH12_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH13 - PCC DMA1_CH13 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH13_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH13_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH13_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH13_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH13_SSADO_MASK)

#define PCC3_PCC_DMA1_CH13_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH13_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH13_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH13_CGC_SHIFT)) & PCC3_PCC_DMA1_CH13_CGC_MASK)

#define PCC3_PCC_DMA1_CH13_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH13_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH13_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH13_PR_SHIFT)) & PCC3_PCC_DMA1_CH13_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH14 - PCC DMA1_CH14 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH14_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH14_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH14_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH14_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH14_SSADO_MASK)

#define PCC3_PCC_DMA1_CH14_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH14_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH14_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH14_CGC_SHIFT)) & PCC3_PCC_DMA1_CH14_CGC_MASK)

#define PCC3_PCC_DMA1_CH14_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH14_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH14_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH14_PR_SHIFT)) & PCC3_PCC_DMA1_CH14_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH15 - PCC DMA1_CH15 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH15_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH15_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH15_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH15_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH15_SSADO_MASK)

#define PCC3_PCC_DMA1_CH15_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH15_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH15_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH15_CGC_SHIFT)) & PCC3_PCC_DMA1_CH15_CGC_MASK)

#define PCC3_PCC_DMA1_CH15_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH15_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH15_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH15_PR_SHIFT)) & PCC3_PCC_DMA1_CH15_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH16 - PCC DMA1_CH16 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH16_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH16_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH16_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH16_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH16_SSADO_MASK)

#define PCC3_PCC_DMA1_CH16_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH16_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH16_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH16_CGC_SHIFT)) & PCC3_PCC_DMA1_CH16_CGC_MASK)

#define PCC3_PCC_DMA1_CH16_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH16_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH16_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH16_PR_SHIFT)) & PCC3_PCC_DMA1_CH16_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH17 - PCC DMA1_CH17 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH17_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH17_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH17_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH17_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH17_SSADO_MASK)

#define PCC3_PCC_DMA1_CH17_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH17_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH17_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH17_CGC_SHIFT)) & PCC3_PCC_DMA1_CH17_CGC_MASK)

#define PCC3_PCC_DMA1_CH17_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH17_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH17_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH17_PR_SHIFT)) & PCC3_PCC_DMA1_CH17_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH18 - PCC DMA1_CH18 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH18_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH18_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH18_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH18_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH18_SSADO_MASK)

#define PCC3_PCC_DMA1_CH18_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH18_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH18_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH18_CGC_SHIFT)) & PCC3_PCC_DMA1_CH18_CGC_MASK)

#define PCC3_PCC_DMA1_CH18_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH18_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH18_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH18_PR_SHIFT)) & PCC3_PCC_DMA1_CH18_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH19 - PCC DMA1_CH19 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH19_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH19_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH19_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH19_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH19_SSADO_MASK)

#define PCC3_PCC_DMA1_CH19_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH19_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH19_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH19_CGC_SHIFT)) & PCC3_PCC_DMA1_CH19_CGC_MASK)

#define PCC3_PCC_DMA1_CH19_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH19_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH19_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH19_PR_SHIFT)) & PCC3_PCC_DMA1_CH19_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH20 - PCC DMA1_CH20 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH20_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH20_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH20_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH20_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH20_SSADO_MASK)

#define PCC3_PCC_DMA1_CH20_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH20_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH20_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH20_CGC_SHIFT)) & PCC3_PCC_DMA1_CH20_CGC_MASK)

#define PCC3_PCC_DMA1_CH20_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH20_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH20_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH20_PR_SHIFT)) & PCC3_PCC_DMA1_CH20_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH21 - PCC DMA1_CH21 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH21_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH21_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH21_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH21_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH21_SSADO_MASK)

#define PCC3_PCC_DMA1_CH21_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH21_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH21_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH21_CGC_SHIFT)) & PCC3_PCC_DMA1_CH21_CGC_MASK)

#define PCC3_PCC_DMA1_CH21_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH21_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH21_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH21_PR_SHIFT)) & PCC3_PCC_DMA1_CH21_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH22 - PCC DMA1_CH22 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH22_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH22_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH22_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH22_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH22_SSADO_MASK)

#define PCC3_PCC_DMA1_CH22_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH22_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH22_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH22_CGC_SHIFT)) & PCC3_PCC_DMA1_CH22_CGC_MASK)

#define PCC3_PCC_DMA1_CH22_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH22_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH22_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH22_PR_SHIFT)) & PCC3_PCC_DMA1_CH22_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH23 - PCC DMA1_CH23 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH23_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH23_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH23_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH23_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH23_SSADO_MASK)

#define PCC3_PCC_DMA1_CH23_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH23_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH23_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH23_CGC_SHIFT)) & PCC3_PCC_DMA1_CH23_CGC_MASK)

#define PCC3_PCC_DMA1_CH23_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH23_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH23_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH23_PR_SHIFT)) & PCC3_PCC_DMA1_CH23_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH24 - PCC DMA1_CH24 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH24_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH24_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH24_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH24_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH24_SSADO_MASK)

#define PCC3_PCC_DMA1_CH24_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH24_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH24_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH24_CGC_SHIFT)) & PCC3_PCC_DMA1_CH24_CGC_MASK)

#define PCC3_PCC_DMA1_CH24_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH24_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH24_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH24_PR_SHIFT)) & PCC3_PCC_DMA1_CH24_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH25 - PCC DMA1_CH25 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH25_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH25_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH25_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH25_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH25_SSADO_MASK)

#define PCC3_PCC_DMA1_CH25_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH25_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH25_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH25_CGC_SHIFT)) & PCC3_PCC_DMA1_CH25_CGC_MASK)

#define PCC3_PCC_DMA1_CH25_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH25_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH25_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH25_PR_SHIFT)) & PCC3_PCC_DMA1_CH25_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH26 - PCC DMA1_CH26 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH26_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH26_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH26_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH26_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH26_SSADO_MASK)

#define PCC3_PCC_DMA1_CH26_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH26_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH26_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH26_CGC_SHIFT)) & PCC3_PCC_DMA1_CH26_CGC_MASK)

#define PCC3_PCC_DMA1_CH26_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH26_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH26_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH26_PR_SHIFT)) & PCC3_PCC_DMA1_CH26_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH27 - PCC DMA1_CH27 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH27_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH27_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH27_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH27_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH27_SSADO_MASK)

#define PCC3_PCC_DMA1_CH27_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH27_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH27_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH27_CGC_SHIFT)) & PCC3_PCC_DMA1_CH27_CGC_MASK)

#define PCC3_PCC_DMA1_CH27_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH27_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH27_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH27_PR_SHIFT)) & PCC3_PCC_DMA1_CH27_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH28 - PCC DMA1_CH28 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH28_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH28_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH28_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH28_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH28_SSADO_MASK)

#define PCC3_PCC_DMA1_CH28_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH28_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH28_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH28_CGC_SHIFT)) & PCC3_PCC_DMA1_CH28_CGC_MASK)

#define PCC3_PCC_DMA1_CH28_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH28_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH28_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH28_PR_SHIFT)) & PCC3_PCC_DMA1_CH28_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH29 - PCC DMA1_CH29 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH29_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH29_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH29_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH29_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH29_SSADO_MASK)

#define PCC3_PCC_DMA1_CH29_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH29_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH29_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH29_CGC_SHIFT)) & PCC3_PCC_DMA1_CH29_CGC_MASK)

#define PCC3_PCC_DMA1_CH29_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH29_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH29_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH29_PR_SHIFT)) & PCC3_PCC_DMA1_CH29_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH30 - PCC DMA1_CH30 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH30_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH30_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH30_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH30_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH30_SSADO_MASK)

#define PCC3_PCC_DMA1_CH30_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH30_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH30_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH30_CGC_SHIFT)) & PCC3_PCC_DMA1_CH30_CGC_MASK)

#define PCC3_PCC_DMA1_CH30_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH30_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH30_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH30_PR_SHIFT)) & PCC3_PCC_DMA1_CH30_PR_MASK)
/*! @} */

/*! @name PCC_DMA1_CH31 - PCC DMA1_CH31 Register */
/*! @{ */

#define PCC3_PCC_DMA1_CH31_SSADO_MASK            (0xC00000U)
#define PCC3_PCC_DMA1_CH31_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_DMA1_CH31_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH31_SSADO_SHIFT)) & PCC3_PCC_DMA1_CH31_SSADO_MASK)

#define PCC3_PCC_DMA1_CH31_CGC_MASK              (0x40000000U)
#define PCC3_PCC_DMA1_CH31_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DMA1_CH31_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH31_CGC_SHIFT)) & PCC3_PCC_DMA1_CH31_CGC_MASK)

#define PCC3_PCC_DMA1_CH31_PR_MASK               (0x80000000U)
#define PCC3_PCC_DMA1_CH31_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DMA1_CH31_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DMA1_CH31_PR_SHIFT)) & PCC3_PCC_DMA1_CH31_PR_MASK)
/*! @} */

/*! @name PCC_MU0_B - PCC MU0_B Register */
/*! @{ */

#define PCC3_PCC_MU0_B_SSADO_MASK                (0xC00000U)
#define PCC3_PCC_MU0_B_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_MU0_B_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MU0_B_SSADO_SHIFT)) & PCC3_PCC_MU0_B_SSADO_MASK)

#define PCC3_PCC_MU0_B_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_MU0_B_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_MU0_B_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MU0_B_CGC_SHIFT)) & PCC3_PCC_MU0_B_CGC_MASK)

#define PCC3_PCC_MU0_B_PR_MASK                   (0x80000000U)
#define PCC3_PCC_MU0_B_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_MU0_B_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MU0_B_PR_SHIFT)) & PCC3_PCC_MU0_B_PR_MASK)
/*! @} */

/*! @name PCC_MU3_A - PCC MU3_A Register */
/*! @{ */

#define PCC3_PCC_MU3_A_SSADO_MASK                (0xC00000U)
#define PCC3_PCC_MU3_A_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_MU3_A_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MU3_A_SSADO_SHIFT)) & PCC3_PCC_MU3_A_SSADO_MASK)

#define PCC3_PCC_MU3_A_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_MU3_A_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_MU3_A_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MU3_A_CGC_SHIFT)) & PCC3_PCC_MU3_A_CGC_MASK)

#define PCC3_PCC_MU3_A_PR_MASK                   (0x80000000U)
#define PCC3_PCC_MU3_A_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_MU3_A_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MU3_A_PR_SHIFT)) & PCC3_PCC_MU3_A_PR_MASK)
/*! @} */

/*! @name PCC_WUU1 - PCC WUU1 Register */
/*! @{ */

#define PCC3_PCC_WUU1_SSADO_MASK                 (0xC00000U)
#define PCC3_PCC_WUU1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_WUU1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WUU1_SSADO_SHIFT)) & PCC3_PCC_WUU1_SSADO_MASK)

#define PCC3_PCC_WUU1_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_WUU1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_WUU1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WUU1_CGC_SHIFT)) & PCC3_PCC_WUU1_CGC_MASK)

#define PCC3_PCC_WUU1_PR_MASK                    (0x80000000U)
#define PCC3_PCC_WUU1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_WUU1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WUU1_PR_SHIFT)) & PCC3_PCC_WUU1_PR_MASK)
/*! @} */

/*! @name PCC_SYSPM1 - PCC SYSPM1 Register */
/*! @{ */

#define PCC3_PCC_SYSPM1_SSADO_MASK               (0xC00000U)
#define PCC3_PCC_SYSPM1_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_SYSPM1_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_SYSPM1_SSADO_SHIFT)) & PCC3_PCC_SYSPM1_SSADO_MASK)

#define PCC3_PCC_SYSPM1_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_SYSPM1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_SYSPM1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_SYSPM1_CGC_SHIFT)) & PCC3_PCC_SYSPM1_CGC_MASK)

#define PCC3_PCC_SYSPM1_PR_MASK                  (0x80000000U)
#define PCC3_PCC_SYSPM1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_SYSPM1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_SYSPM1_PR_SHIFT)) & PCC3_PCC_SYSPM1_PR_MASK)
/*! @} */

/*! @name PCC_UPOWER_MUA_APD - PCC uPower_MUA_APD Register */
/*! @{ */

#define PCC3_PCC_UPOWER_MUA_APD_SSADO_MASK       (0xC00000U)
#define PCC3_PCC_UPOWER_MUA_APD_SSADO_SHIFT      (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_UPOWER_MUA_APD_SSADO(x)         (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_UPOWER_MUA_APD_SSADO_SHIFT)) & PCC3_PCC_UPOWER_MUA_APD_SSADO_MASK)

#define PCC3_PCC_UPOWER_MUA_APD_CGC_MASK         (0x40000000U)
#define PCC3_PCC_UPOWER_MUA_APD_CGC_SHIFT        (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_UPOWER_MUA_APD_CGC(x)           (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_UPOWER_MUA_APD_CGC_SHIFT)) & PCC3_PCC_UPOWER_MUA_APD_CGC_MASK)

#define PCC3_PCC_UPOWER_MUA_APD_PR_MASK          (0x80000000U)
#define PCC3_PCC_UPOWER_MUA_APD_PR_SHIFT         (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_UPOWER_MUA_APD_PR(x)            (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_UPOWER_MUA_APD_PR_SHIFT)) & PCC3_PCC_UPOWER_MUA_APD_PR_MASK)
/*! @} */

/*! @name PCC_WDOG3 - PCC WDOG3 Register */
/*! @{ */

#define PCC3_PCC_WDOG3_PCD_MASK                  (0x7U)
#define PCC3_PCC_WDOG3_PCD_SHIFT                 (0U)
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
#define PCC3_PCC_WDOG3_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_PCD_SHIFT)) & PCC3_PCC_WDOG3_PCD_MASK)

#define PCC3_PCC_WDOG3_FRAC_MASK                 (0x8U)
#define PCC3_PCC_WDOG3_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_WDOG3_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_FRAC_SHIFT)) & PCC3_PCC_WDOG3_FRAC_MASK)

#define PCC3_PCC_WDOG3_SSADO_MASK                (0xC00000U)
#define PCC3_PCC_WDOG3_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_WDOG3_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_SSADO_SHIFT)) & PCC3_PCC_WDOG3_SSADO_MASK)

#define PCC3_PCC_WDOG3_PCS_MASK                  (0x7000000U)
#define PCC3_PCC_WDOG3_PCS_SHIFT                 (24U)
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
#define PCC3_PCC_WDOG3_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_PCS_SHIFT)) & PCC3_PCC_WDOG3_PCS_MASK)

#define PCC3_PCC_WDOG3_SWRST_MASK                (0x10000000U)
#define PCC3_PCC_WDOG3_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_WDOG3_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_SWRST_SHIFT)) & PCC3_PCC_WDOG3_SWRST_MASK)

#define PCC3_PCC_WDOG3_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_WDOG3_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_WDOG3_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_CGC_SHIFT)) & PCC3_PCC_WDOG3_CGC_MASK)

#define PCC3_PCC_WDOG3_PR_MASK                   (0x80000000U)
#define PCC3_PCC_WDOG3_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_WDOG3_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG3_PR_SHIFT)) & PCC3_PCC_WDOG3_PR_MASK)
/*! @} */

/*! @name PCC_WDOG4 - PCC WDOG4 Register */
/*! @{ */

#define PCC3_PCC_WDOG4_PCD_MASK                  (0x7U)
#define PCC3_PCC_WDOG4_PCD_SHIFT                 (0U)
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
#define PCC3_PCC_WDOG4_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_PCD_SHIFT)) & PCC3_PCC_WDOG4_PCD_MASK)

#define PCC3_PCC_WDOG4_FRAC_MASK                 (0x8U)
#define PCC3_PCC_WDOG4_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_WDOG4_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_FRAC_SHIFT)) & PCC3_PCC_WDOG4_FRAC_MASK)

#define PCC3_PCC_WDOG4_SSADO_MASK                (0xC00000U)
#define PCC3_PCC_WDOG4_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_WDOG4_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_SSADO_SHIFT)) & PCC3_PCC_WDOG4_SSADO_MASK)

#define PCC3_PCC_WDOG4_PCS_MASK                  (0x7000000U)
#define PCC3_PCC_WDOG4_PCS_SHIFT                 (24U)
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
#define PCC3_PCC_WDOG4_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_PCS_SHIFT)) & PCC3_PCC_WDOG4_PCS_MASK)

#define PCC3_PCC_WDOG4_SWRST_MASK                (0x10000000U)
#define PCC3_PCC_WDOG4_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_WDOG4_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_SWRST_SHIFT)) & PCC3_PCC_WDOG4_SWRST_MASK)

#define PCC3_PCC_WDOG4_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_WDOG4_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_WDOG4_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_CGC_SHIFT)) & PCC3_PCC_WDOG4_CGC_MASK)

#define PCC3_PCC_WDOG4_PR_MASK                   (0x80000000U)
#define PCC3_PCC_WDOG4_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_WDOG4_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_WDOG4_PR_SHIFT)) & PCC3_PCC_WDOG4_PR_MASK)
/*! @} */

/*! @name PCC_CAAM - PCC CAAM Register */
/*! @{ */

#define PCC3_PCC_CAAM_SSADO_MASK                 (0xC00000U)
#define PCC3_PCC_CAAM_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_CAAM_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_CAAM_SSADO_SHIFT)) & PCC3_PCC_CAAM_SSADO_MASK)

#define PCC3_PCC_CAAM_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_CAAM_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_CAAM_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_CAAM_CGC_SHIFT)) & PCC3_PCC_CAAM_CGC_MASK)

#define PCC3_PCC_CAAM_PR_MASK                    (0x80000000U)
#define PCC3_PCC_CAAM_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_CAAM_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_CAAM_PR_SHIFT)) & PCC3_PCC_CAAM_PR_MASK)
/*! @} */

/*! @name PCC_XRDC_MGR - PCC XRDC_MGR Register */
/*! @{ */

#define PCC3_PCC_XRDC_MGR_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_XRDC_MGR_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_XRDC_MGR_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_XRDC_MGR_SSADO_SHIFT)) & PCC3_PCC_XRDC_MGR_SSADO_MASK)

#define PCC3_PCC_XRDC_MGR_CGC_MASK               (0x40000000U)
#define PCC3_PCC_XRDC_MGR_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_XRDC_MGR_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_XRDC_MGR_CGC_SHIFT)) & PCC3_PCC_XRDC_MGR_CGC_MASK)

#define PCC3_PCC_XRDC_MGR_PR_MASK                (0x80000000U)
#define PCC3_PCC_XRDC_MGR_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_XRDC_MGR_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_XRDC_MGR_PR_SHIFT)) & PCC3_PCC_XRDC_MGR_PR_MASK)
/*! @} */

/*! @name PCC_SEMA42_1 - PCC SEMA42_1 Register */
/*! @{ */

#define PCC3_PCC_SEMA42_1_SSADO_MASK             (0xC00000U)
#define PCC3_PCC_SEMA42_1_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_SEMA42_1_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_SEMA42_1_SSADO_SHIFT)) & PCC3_PCC_SEMA42_1_SSADO_MASK)

#define PCC3_PCC_SEMA42_1_CGC_MASK               (0x40000000U)
#define PCC3_PCC_SEMA42_1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_SEMA42_1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_SEMA42_1_CGC_SHIFT)) & PCC3_PCC_SEMA42_1_CGC_MASK)

#define PCC3_PCC_SEMA42_1_PR_MASK                (0x80000000U)
#define PCC3_PCC_SEMA42_1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_SEMA42_1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_SEMA42_1_PR_SHIFT)) & PCC3_PCC_SEMA42_1_PR_MASK)
/*! @} */

/*! @name PCC_ROMCP1 - PCC ROMCP1 Register */
/*! @{ */

#define PCC3_PCC_ROMCP1_SSADO_MASK               (0xC00000U)
#define PCC3_PCC_ROMCP1_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_ROMCP1_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_ROMCP1_SSADO_SHIFT)) & PCC3_PCC_ROMCP1_SSADO_MASK)

#define PCC3_PCC_ROMCP1_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_ROMCP1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_ROMCP1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_ROMCP1_CGC_SHIFT)) & PCC3_PCC_ROMCP1_CGC_MASK)

#define PCC3_PCC_ROMCP1_PR_MASK                  (0x80000000U)
#define PCC3_PCC_ROMCP1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_ROMCP1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_ROMCP1_PR_SHIFT)) & PCC3_PCC_ROMCP1_PR_MASK)
/*! @} */

/*! @name PCC_LPIT1 - PCC LPIT1 Register */
/*! @{ */

#define PCC3_PCC_LPIT1_PCD_MASK                  (0x7U)
#define PCC3_PCC_LPIT1_PCD_SHIFT                 (0U)
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
#define PCC3_PCC_LPIT1_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_PCD_SHIFT)) & PCC3_PCC_LPIT1_PCD_MASK)

#define PCC3_PCC_LPIT1_FRAC_MASK                 (0x8U)
#define PCC3_PCC_LPIT1_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPIT1_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_FRAC_SHIFT)) & PCC3_PCC_LPIT1_FRAC_MASK)

#define PCC3_PCC_LPIT1_SSADO_MASK                (0xC00000U)
#define PCC3_PCC_LPIT1_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPIT1_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_SSADO_SHIFT)) & PCC3_PCC_LPIT1_SSADO_MASK)

#define PCC3_PCC_LPIT1_PCS_MASK                  (0x7000000U)
#define PCC3_PCC_LPIT1_PCS_SHIFT                 (24U)
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
#define PCC3_PCC_LPIT1_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_PCS_SHIFT)) & PCC3_PCC_LPIT1_PCS_MASK)

#define PCC3_PCC_LPIT1_SWRST_MASK                (0x10000000U)
#define PCC3_PCC_LPIT1_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPIT1_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_SWRST_SHIFT)) & PCC3_PCC_LPIT1_SWRST_MASK)

#define PCC3_PCC_LPIT1_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_LPIT1_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPIT1_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_CGC_SHIFT)) & PCC3_PCC_LPIT1_CGC_MASK)

#define PCC3_PCC_LPIT1_PR_MASK                   (0x80000000U)
#define PCC3_PCC_LPIT1_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPIT1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPIT1_PR_SHIFT)) & PCC3_PCC_LPIT1_PR_MASK)
/*! @} */

/*! @name PCC_TPM4 - PCC TPM4 Register */
/*! @{ */

#define PCC3_PCC_TPM4_PCD_MASK                   (0x7U)
#define PCC3_PCC_TPM4_PCD_SHIFT                  (0U)
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
#define PCC3_PCC_TPM4_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_PCD_SHIFT)) & PCC3_PCC_TPM4_PCD_MASK)

#define PCC3_PCC_TPM4_FRAC_MASK                  (0x8U)
#define PCC3_PCC_TPM4_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_TPM4_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_FRAC_SHIFT)) & PCC3_PCC_TPM4_FRAC_MASK)

#define PCC3_PCC_TPM4_SSADO_MASK                 (0xC00000U)
#define PCC3_PCC_TPM4_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_TPM4_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_SSADO_SHIFT)) & PCC3_PCC_TPM4_SSADO_MASK)

#define PCC3_PCC_TPM4_PCS_MASK                   (0x7000000U)
#define PCC3_PCC_TPM4_PCS_SHIFT                  (24U)
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
#define PCC3_PCC_TPM4_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_PCS_SHIFT)) & PCC3_PCC_TPM4_PCS_MASK)

#define PCC3_PCC_TPM4_SWRST_MASK                 (0x10000000U)
#define PCC3_PCC_TPM4_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_TPM4_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_SWRST_SHIFT)) & PCC3_PCC_TPM4_SWRST_MASK)

#define PCC3_PCC_TPM4_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_TPM4_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_TPM4_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_CGC_SHIFT)) & PCC3_PCC_TPM4_CGC_MASK)

#define PCC3_PCC_TPM4_PR_MASK                    (0x80000000U)
#define PCC3_PCC_TPM4_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_TPM4_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM4_PR_SHIFT)) & PCC3_PCC_TPM4_PR_MASK)
/*! @} */

/*! @name PCC_TPM5 - PCC TPM5 Register */
/*! @{ */

#define PCC3_PCC_TPM5_PCD_MASK                   (0x7U)
#define PCC3_PCC_TPM5_PCD_SHIFT                  (0U)
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
#define PCC3_PCC_TPM5_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_PCD_SHIFT)) & PCC3_PCC_TPM5_PCD_MASK)

#define PCC3_PCC_TPM5_FRAC_MASK                  (0x8U)
#define PCC3_PCC_TPM5_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_TPM5_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_FRAC_SHIFT)) & PCC3_PCC_TPM5_FRAC_MASK)

#define PCC3_PCC_TPM5_SSADO_MASK                 (0xC00000U)
#define PCC3_PCC_TPM5_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_TPM5_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_SSADO_SHIFT)) & PCC3_PCC_TPM5_SSADO_MASK)

#define PCC3_PCC_TPM5_PCS_MASK                   (0x7000000U)
#define PCC3_PCC_TPM5_PCS_SHIFT                  (24U)
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
#define PCC3_PCC_TPM5_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_PCS_SHIFT)) & PCC3_PCC_TPM5_PCS_MASK)

#define PCC3_PCC_TPM5_SWRST_MASK                 (0x10000000U)
#define PCC3_PCC_TPM5_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_TPM5_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_SWRST_SHIFT)) & PCC3_PCC_TPM5_SWRST_MASK)

#define PCC3_PCC_TPM5_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_TPM5_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_TPM5_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_CGC_SHIFT)) & PCC3_PCC_TPM5_CGC_MASK)

#define PCC3_PCC_TPM5_PR_MASK                    (0x80000000U)
#define PCC3_PCC_TPM5_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_TPM5_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM5_PR_SHIFT)) & PCC3_PCC_TPM5_PR_MASK)
/*! @} */

/*! @name PCC_FLEXIO1 - PCC FlexIO1 Register */
/*! @{ */

#define PCC3_PCC_FLEXIO1_PCD_MASK                (0x7U)
#define PCC3_PCC_FLEXIO1_PCD_SHIFT               (0U)
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
#define PCC3_PCC_FLEXIO1_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_PCD_SHIFT)) & PCC3_PCC_FLEXIO1_PCD_MASK)

#define PCC3_PCC_FLEXIO1_FRAC_MASK               (0x8U)
#define PCC3_PCC_FLEXIO1_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_FLEXIO1_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_FRAC_SHIFT)) & PCC3_PCC_FLEXIO1_FRAC_MASK)

#define PCC3_PCC_FLEXIO1_SSADO_MASK              (0xC00000U)
#define PCC3_PCC_FLEXIO1_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_FLEXIO1_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_SSADO_SHIFT)) & PCC3_PCC_FLEXIO1_SSADO_MASK)

#define PCC3_PCC_FLEXIO1_PCS_MASK                (0x7000000U)
#define PCC3_PCC_FLEXIO1_PCS_SHIFT               (24U)
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
#define PCC3_PCC_FLEXIO1_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_PCS_SHIFT)) & PCC3_PCC_FLEXIO1_PCS_MASK)

#define PCC3_PCC_FLEXIO1_SWRST_MASK              (0x10000000U)
#define PCC3_PCC_FLEXIO1_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_FLEXIO1_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_SWRST_SHIFT)) & PCC3_PCC_FLEXIO1_SWRST_MASK)

#define PCC3_PCC_FLEXIO1_CGC_MASK                (0x40000000U)
#define PCC3_PCC_FLEXIO1_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_FLEXIO1_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_CGC_SHIFT)) & PCC3_PCC_FLEXIO1_CGC_MASK)

#define PCC3_PCC_FLEXIO1_PR_MASK                 (0x80000000U)
#define PCC3_PCC_FLEXIO1_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_FLEXIO1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_FLEXIO1_PR_SHIFT)) & PCC3_PCC_FLEXIO1_PR_MASK)
/*! @} */

/*! @name PCC_I3C2 - PCC I3C2 Register */
/*! @{ */

#define PCC3_PCC_I3C2_PCD_MASK                   (0x7U)
#define PCC3_PCC_I3C2_PCD_SHIFT                  (0U)
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
#define PCC3_PCC_I3C2_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_PCD_SHIFT)) & PCC3_PCC_I3C2_PCD_MASK)

#define PCC3_PCC_I3C2_FRAC_MASK                  (0x8U)
#define PCC3_PCC_I3C2_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_I3C2_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_FRAC_SHIFT)) & PCC3_PCC_I3C2_FRAC_MASK)

#define PCC3_PCC_I3C2_SSADO_MASK                 (0xC00000U)
#define PCC3_PCC_I3C2_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_I3C2_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_SSADO_SHIFT)) & PCC3_PCC_I3C2_SSADO_MASK)

#define PCC3_PCC_I3C2_PCS_MASK                   (0x7000000U)
#define PCC3_PCC_I3C2_PCS_SHIFT                  (24U)
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
#define PCC3_PCC_I3C2_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_PCS_SHIFT)) & PCC3_PCC_I3C2_PCS_MASK)

#define PCC3_PCC_I3C2_SWRST_MASK                 (0x10000000U)
#define PCC3_PCC_I3C2_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_I3C2_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_SWRST_SHIFT)) & PCC3_PCC_I3C2_SWRST_MASK)

#define PCC3_PCC_I3C2_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_I3C2_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_I3C2_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_CGC_SHIFT)) & PCC3_PCC_I3C2_CGC_MASK)

#define PCC3_PCC_I3C2_PR_MASK                    (0x80000000U)
#define PCC3_PCC_I3C2_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_I3C2_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_I3C2_PR_SHIFT)) & PCC3_PCC_I3C2_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C4 - PCC LPI2C4 Register */
/*! @{ */

#define PCC3_PCC_LPI2C4_PCD_MASK                 (0x7U)
#define PCC3_PCC_LPI2C4_PCD_SHIFT                (0U)
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
#define PCC3_PCC_LPI2C4_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_PCD_SHIFT)) & PCC3_PCC_LPI2C4_PCD_MASK)

#define PCC3_PCC_LPI2C4_FRAC_MASK                (0x8U)
#define PCC3_PCC_LPI2C4_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPI2C4_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_FRAC_SHIFT)) & PCC3_PCC_LPI2C4_FRAC_MASK)

#define PCC3_PCC_LPI2C4_SSADO_MASK               (0xC00000U)
#define PCC3_PCC_LPI2C4_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPI2C4_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_SSADO_SHIFT)) & PCC3_PCC_LPI2C4_SSADO_MASK)

#define PCC3_PCC_LPI2C4_PCS_MASK                 (0x7000000U)
#define PCC3_PCC_LPI2C4_PCS_SHIFT                (24U)
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
#define PCC3_PCC_LPI2C4_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_PCS_SHIFT)) & PCC3_PCC_LPI2C4_PCS_MASK)

#define PCC3_PCC_LPI2C4_SWRST_MASK               (0x10000000U)
#define PCC3_PCC_LPI2C4_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPI2C4_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_SWRST_SHIFT)) & PCC3_PCC_LPI2C4_SWRST_MASK)

#define PCC3_PCC_LPI2C4_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_LPI2C4_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPI2C4_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_CGC_SHIFT)) & PCC3_PCC_LPI2C4_CGC_MASK)

#define PCC3_PCC_LPI2C4_PR_MASK                  (0x80000000U)
#define PCC3_PCC_LPI2C4_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPI2C4_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C4_PR_SHIFT)) & PCC3_PCC_LPI2C4_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C5 - PCC LPI2C5 Register */
/*! @{ */

#define PCC3_PCC_LPI2C5_PCD_MASK                 (0x7U)
#define PCC3_PCC_LPI2C5_PCD_SHIFT                (0U)
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
#define PCC3_PCC_LPI2C5_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_PCD_SHIFT)) & PCC3_PCC_LPI2C5_PCD_MASK)

#define PCC3_PCC_LPI2C5_FRAC_MASK                (0x8U)
#define PCC3_PCC_LPI2C5_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPI2C5_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_FRAC_SHIFT)) & PCC3_PCC_LPI2C5_FRAC_MASK)

#define PCC3_PCC_LPI2C5_SSADO_MASK               (0xC00000U)
#define PCC3_PCC_LPI2C5_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPI2C5_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_SSADO_SHIFT)) & PCC3_PCC_LPI2C5_SSADO_MASK)

#define PCC3_PCC_LPI2C5_PCS_MASK                 (0x7000000U)
#define PCC3_PCC_LPI2C5_PCS_SHIFT                (24U)
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
#define PCC3_PCC_LPI2C5_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_PCS_SHIFT)) & PCC3_PCC_LPI2C5_PCS_MASK)

#define PCC3_PCC_LPI2C5_SWRST_MASK               (0x10000000U)
#define PCC3_PCC_LPI2C5_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPI2C5_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_SWRST_SHIFT)) & PCC3_PCC_LPI2C5_SWRST_MASK)

#define PCC3_PCC_LPI2C5_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_LPI2C5_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPI2C5_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_CGC_SHIFT)) & PCC3_PCC_LPI2C5_CGC_MASK)

#define PCC3_PCC_LPI2C5_PR_MASK                  (0x80000000U)
#define PCC3_PCC_LPI2C5_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPI2C5_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C5_PR_SHIFT)) & PCC3_PCC_LPI2C5_PR_MASK)
/*! @} */

/*! @name PCC_LPUART4 - PCC LPUART4 Register */
/*! @{ */

#define PCC3_PCC_LPUART4_PCD_MASK                (0x7U)
#define PCC3_PCC_LPUART4_PCD_SHIFT               (0U)
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
#define PCC3_PCC_LPUART4_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_PCD_SHIFT)) & PCC3_PCC_LPUART4_PCD_MASK)

#define PCC3_PCC_LPUART4_FRAC_MASK               (0x8U)
#define PCC3_PCC_LPUART4_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPUART4_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_FRAC_SHIFT)) & PCC3_PCC_LPUART4_FRAC_MASK)

#define PCC3_PCC_LPUART4_SSADO_MASK              (0xC00000U)
#define PCC3_PCC_LPUART4_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPUART4_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_SSADO_SHIFT)) & PCC3_PCC_LPUART4_SSADO_MASK)

#define PCC3_PCC_LPUART4_PCS_MASK                (0x7000000U)
#define PCC3_PCC_LPUART4_PCS_SHIFT               (24U)
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
#define PCC3_PCC_LPUART4_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_PCS_SHIFT)) & PCC3_PCC_LPUART4_PCS_MASK)

#define PCC3_PCC_LPUART4_SWRST_MASK              (0x10000000U)
#define PCC3_PCC_LPUART4_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPUART4_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_SWRST_SHIFT)) & PCC3_PCC_LPUART4_SWRST_MASK)

#define PCC3_PCC_LPUART4_CGC_MASK                (0x40000000U)
#define PCC3_PCC_LPUART4_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPUART4_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_CGC_SHIFT)) & PCC3_PCC_LPUART4_CGC_MASK)

#define PCC3_PCC_LPUART4_PR_MASK                 (0x80000000U)
#define PCC3_PCC_LPUART4_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPUART4_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART4_PR_SHIFT)) & PCC3_PCC_LPUART4_PR_MASK)
/*! @} */

/*! @name PCC_LPUART5 - PCC LPUART5 Register */
/*! @{ */

#define PCC3_PCC_LPUART5_PCD_MASK                (0x7U)
#define PCC3_PCC_LPUART5_PCD_SHIFT               (0U)
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
#define PCC3_PCC_LPUART5_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_PCD_SHIFT)) & PCC3_PCC_LPUART5_PCD_MASK)

#define PCC3_PCC_LPUART5_FRAC_MASK               (0x8U)
#define PCC3_PCC_LPUART5_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPUART5_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_FRAC_SHIFT)) & PCC3_PCC_LPUART5_FRAC_MASK)

#define PCC3_PCC_LPUART5_SSADO_MASK              (0xC00000U)
#define PCC3_PCC_LPUART5_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPUART5_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_SSADO_SHIFT)) & PCC3_PCC_LPUART5_SSADO_MASK)

#define PCC3_PCC_LPUART5_PCS_MASK                (0x7000000U)
#define PCC3_PCC_LPUART5_PCS_SHIFT               (24U)
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
#define PCC3_PCC_LPUART5_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_PCS_SHIFT)) & PCC3_PCC_LPUART5_PCS_MASK)

#define PCC3_PCC_LPUART5_SWRST_MASK              (0x10000000U)
#define PCC3_PCC_LPUART5_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPUART5_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_SWRST_SHIFT)) & PCC3_PCC_LPUART5_SWRST_MASK)

#define PCC3_PCC_LPUART5_CGC_MASK                (0x40000000U)
#define PCC3_PCC_LPUART5_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPUART5_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_CGC_SHIFT)) & PCC3_PCC_LPUART5_CGC_MASK)

#define PCC3_PCC_LPUART5_PR_MASK                 (0x80000000U)
#define PCC3_PCC_LPUART5_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPUART5_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART5_PR_SHIFT)) & PCC3_PCC_LPUART5_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI4 - PCC LPSPI4 Register */
/*! @{ */

#define PCC3_PCC_LPSPI4_PCD_MASK                 (0x7U)
#define PCC3_PCC_LPSPI4_PCD_SHIFT                (0U)
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
#define PCC3_PCC_LPSPI4_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_PCD_SHIFT)) & PCC3_PCC_LPSPI4_PCD_MASK)

#define PCC3_PCC_LPSPI4_FRAC_MASK                (0x8U)
#define PCC3_PCC_LPSPI4_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPSPI4_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_FRAC_SHIFT)) & PCC3_PCC_LPSPI4_FRAC_MASK)

#define PCC3_PCC_LPSPI4_SSADO_MASK               (0xC00000U)
#define PCC3_PCC_LPSPI4_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPSPI4_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_SSADO_SHIFT)) & PCC3_PCC_LPSPI4_SSADO_MASK)

#define PCC3_PCC_LPSPI4_PCS_MASK                 (0x7000000U)
#define PCC3_PCC_LPSPI4_PCS_SHIFT                (24U)
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
#define PCC3_PCC_LPSPI4_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_PCS_SHIFT)) & PCC3_PCC_LPSPI4_PCS_MASK)

#define PCC3_PCC_LPSPI4_SWRST_MASK               (0x10000000U)
#define PCC3_PCC_LPSPI4_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPSPI4_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_SWRST_SHIFT)) & PCC3_PCC_LPSPI4_SWRST_MASK)

#define PCC3_PCC_LPSPI4_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_LPSPI4_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPSPI4_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_CGC_SHIFT)) & PCC3_PCC_LPSPI4_CGC_MASK)

#define PCC3_PCC_LPSPI4_PR_MASK                  (0x80000000U)
#define PCC3_PCC_LPSPI4_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPSPI4_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI4_PR_SHIFT)) & PCC3_PCC_LPSPI4_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI5 - PCC LPSPI5 Register */
/*! @{ */

#define PCC3_PCC_LPSPI5_PCD_MASK                 (0x7U)
#define PCC3_PCC_LPSPI5_PCD_SHIFT                (0U)
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
#define PCC3_PCC_LPSPI5_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_PCD_SHIFT)) & PCC3_PCC_LPSPI5_PCD_MASK)

#define PCC3_PCC_LPSPI5_FRAC_MASK                (0x8U)
#define PCC3_PCC_LPSPI5_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LPSPI5_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_FRAC_SHIFT)) & PCC3_PCC_LPSPI5_FRAC_MASK)

#define PCC3_PCC_LPSPI5_SSADO_MASK               (0xC00000U)
#define PCC3_PCC_LPSPI5_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC3_PCC_LPSPI5_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_SSADO_SHIFT)) & PCC3_PCC_LPSPI5_SSADO_MASK)

#define PCC3_PCC_LPSPI5_PCS_MASK                 (0x7000000U)
#define PCC3_PCC_LPSPI5_PCS_SHIFT                (24U)
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
#define PCC3_PCC_LPSPI5_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_PCS_SHIFT)) & PCC3_PCC_LPSPI5_PCS_MASK)

#define PCC3_PCC_LPSPI5_SWRST_MASK               (0x10000000U)
#define PCC3_PCC_LPSPI5_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC3_PCC_LPSPI5_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_SWRST_SHIFT)) & PCC3_PCC_LPSPI5_SWRST_MASK)

#define PCC3_PCC_LPSPI5_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_LPSPI5_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPSPI5_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_CGC_SHIFT)) & PCC3_PCC_LPSPI5_CGC_MASK)

#define PCC3_PCC_LPSPI5_PR_MASK                  (0x80000000U)
#define PCC3_PCC_LPSPI5_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPSPI5_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPSPI5_PR_SHIFT)) & PCC3_PCC_LPSPI5_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC3_Register_Masks */


/*!
 * @}
 */ /* end of group PCC3_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC3_H_ */

