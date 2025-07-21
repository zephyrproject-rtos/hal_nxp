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
**         CMSIS Peripheral Access Layer for PCC0
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
 * @file PERI_PCC0.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC0
 *
 * CMSIS Peripheral Access Layer for PCC0
 */

#if !defined(PERI_PCC0_H_)
#define PERI_PCC0_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Peripheral_Access_Layer PCC0 Peripheral Access Layer
 * @{
 */

/** PCC0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t PCC_DMA0_MP;                       /**< PCC DMA0_MP Register, offset: 0x4 */
  __IO uint32_t PCC_DMA0_CH0;                      /**< PCC DMA0_CH0 Register, offset: 0x8 */
  __IO uint32_t PCC_DMA0_CH1;                      /**< PCC DMA0_CH1 Register, offset: 0xC */
  __IO uint32_t PCC_DMA0_CH2;                      /**< PCC DMA0_CH2 Register, offset: 0x10 */
  __IO uint32_t PCC_DMA0_CH3;                      /**< PCC DMA0_CH3 Register, offset: 0x14 */
  __IO uint32_t PCC_DMA0_CH4;                      /**< PCC DMA0_CH4 Register, offset: 0x18 */
  __IO uint32_t PCC_DMA0_CH5;                      /**< PCC DMA0_CH5 Register, offset: 0x1C */
  __IO uint32_t PCC_DMA0_CH6;                      /**< PCC DMA0_CH6 Register, offset: 0x20 */
  __IO uint32_t PCC_DMA0_CH7;                      /**< PCC DMA0_CH7 Register, offset: 0x24 */
  __IO uint32_t PCC_DMA0_CH8;                      /**< PCC DMA0_CH8 Register, offset: 0x28 */
  __IO uint32_t PCC_DMA0_CH9;                      /**< PCC DMA0_CH9 Register, offset: 0x2C */
  __IO uint32_t PCC_DMA0_CH10;                     /**< PCC DMA0_CH10 Register, offset: 0x30 */
  __IO uint32_t PCC_DMA0_CH11;                     /**< PCC DMA0_CH11 Register, offset: 0x34 */
  __IO uint32_t PCC_DMA0_CH12;                     /**< PCC DMA0_CH12 Register, offset: 0x38 */
  __IO uint32_t PCC_DMA0_CH13;                     /**< PCC DMA0_CH13 Register, offset: 0x3C */
  __IO uint32_t PCC_DMA0_CH14;                     /**< PCC DMA0_CH14 Register, offset: 0x40 */
  __IO uint32_t PCC_DMA0_CH15;                     /**< PCC DMA0_CH15 Register, offset: 0x44 */
  __IO uint32_t PCC_DMA0_CH16;                     /**< PCC DMA0_CH16 Register, offset: 0x48 */
  __IO uint32_t PCC_DMA0_CH17;                     /**< PCC DMA0_CH17 Register, offset: 0x4C */
  __IO uint32_t PCC_DMA0_CH18;                     /**< PCC DMA0_CH18 Register, offset: 0x50 */
  __IO uint32_t PCC_DMA0_CH19;                     /**< PCC DMA0_CH19 Register, offset: 0x54 */
  __IO uint32_t PCC_DMA0_CH20;                     /**< PCC DMA0_CH20 Register, offset: 0x58 */
  __IO uint32_t PCC_DMA0_CH21;                     /**< PCC DMA0_CH21 Register, offset: 0x5C */
  __IO uint32_t PCC_DMA0_CH22;                     /**< PCC DMA0_CH22 Register, offset: 0x60 */
  __IO uint32_t PCC_DMA0_CH23;                     /**< PCC DMA0_CH23 Register, offset: 0x64 */
  __IO uint32_t PCC_DMA0_CH24;                     /**< PCC DMA0_CH24 Register, offset: 0x68 */
  __IO uint32_t PCC_DMA0_CH25;                     /**< PCC DMA0_CH25 Register, offset: 0x6C */
  __IO uint32_t PCC_DMA0_CH26;                     /**< PCC DMA0_CH26 Register, offset: 0x70 */
  __IO uint32_t PCC_DMA0_CH27;                     /**< PCC DMA0_CH27 Register, offset: 0x74 */
  __IO uint32_t PCC_DMA0_CH28;                     /**< PCC DMA0_CH28 Register, offset: 0x78 */
  __IO uint32_t PCC_DMA0_CH29;                     /**< PCC DMA0_CH29 Register, offset: 0x7C */
  __IO uint32_t PCC_DMA0_CH30;                     /**< PCC DMA0_CH30 Register, offset: 0x80 */
  __IO uint32_t PCC_DMA0_CH31;                     /**< PCC DMA0_CH31 Register, offset: 0x84 */
  __IO uint32_t PCC_MU0_A;                         /**< PCC MU0_A Register, offset: 0x88 */
  __IO uint32_t PCC_MU1_A;                         /**< PCC MU1_A Register, offset: 0x8C */
  __IO uint32_t PCC_MU2_A;                         /**< PCC MU2_A Register, offset: 0x90 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PCC_SYSPM0;                        /**< PCC SYSPM0 Register, offset: 0x98 */
       uint8_t RESERVED_2[4];
  __IO uint32_t PCC_WUU0;                          /**< PCC WUU0 Register, offset: 0xA0 */
  __IO uint32_t PCC_UPOWER_MUA_RTD;                /**< PCC uPower_MUA_RTD Register, offset: 0xA4 */
       uint8_t RESERVED_3[8];
  __IO uint32_t PCC_WDOG0;                         /**< PCC WDOG0 Register, offset: 0xB0 */
  __IO uint32_t PCC_WDOG1;                         /**< PCC WDOG1 Register, offset: 0xB4 */
       uint8_t RESERVED_4[12];
  __IO uint32_t PCC_TRDC_MGR;                      /**< PCC TRDC_MGR Register, offset: 0xC4 */
  __IO uint32_t PCC_TRDC_MBC0;                     /**< PCC TRDC_MBC0 Register, offset: 0xC8 */
  __IO uint32_t PCC_TRDC_MBC1;                     /**< PCC TRDC_MBC1 Register, offset: 0xCC */
  __IO uint32_t PCC_TRDC_MBC2;                     /**< PCC TRDC_MBC2 Register, offset: 0xD0 */
  __IO uint32_t PCC_TRDC_MBC3;                     /**< PCC TRDC_MBC3 Register, offset: 0xD4 */
  __IO uint32_t PCC_TRDC_MRC;                      /**< PCC TRDC_MRC Register, offset: 0xD8 */
  __IO uint32_t PCC_SEMA42_0;                      /**< PCC SEMA42_0 Register, offset: 0xDC */
  __IO uint32_t PCC_BBNSM;                         /**< PCC BBNSM Register, offset: 0xE0 */
  __IO uint32_t PCC_FLEXSPI0;                      /**< PCC FlexSPI0 Register, offset: 0xE4 */
  __IO uint32_t PCC_ROMCP0;                        /**< PCC ROMCP0 Register, offset: 0xE8 */
  __IO uint32_t PCC_LPIT0;                         /**< PCC LPIT0 Register, offset: 0xEC */
  __IO uint32_t PCC_FLEXIO0;                       /**< PCC FlexIO0 Register, offset: 0xF0 */
  __IO uint32_t PCC_I3C0;                          /**< PCC I3C0 Register, offset: 0xF4 */
  __IO uint32_t PCC_LPSPI0;                        /**< PCC LPSPI0 Register, offset: 0xF8 */
  __IO uint32_t PCC_LPSPI1;                        /**< PCC LPSPI1 Register, offset: 0xFC */
  __IO uint32_t PCC_ADC0;                          /**< PCC ADC0 Register, offset: 0x100 */
  __IO uint32_t PCC_CMP0;                          /**< PCC CMP0 Register, offset: 0x104 */
  __IO uint32_t PCC_CMP1;                          /**< PCC CMP1 Register, offset: 0x108 */
  __IO uint32_t PCC_DAC0;                          /**< PCC DAC0 Register, offset: 0x10C */
  __IO uint32_t PCC_DAC1;                          /**< PCC DAC1 Register, offset: 0x110 */
       uint8_t RESERVED_5[4];
  __IO uint32_t PCC_CM33_CACHE_CONTROLLER;         /**< PCC CM33_Cache_Controller Register, offset: 0x118 */
       uint8_t RESERVED_6[20];
  __IO uint32_t PCC_S400_LPUART;                   /**< PCC S400_LPUART Register, offset: 0x130 */
       uint8_t RESERVED_7[4];
  __IO uint32_t PCC_POWERSYS_WDOG;                 /**< PCC Powersys_WDOG Register, offset: 0x138 */
  __IO uint32_t PCC_OCOTP;                         /**< PCC OCOTP Register, offset: 0x13C */
} PCC0_Type;

/* ----------------------------------------------------------------------------
   -- PCC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Register_Masks PCC0 Register Masks
 * @{
 */

/*! @name PCC_DMA0_MP - PCC DMA0_MP Register */
/*! @{ */

#define PCC0_PCC_DMA0_MP_SSADO_MASK              (0xC00000U)
#define PCC0_PCC_DMA0_MP_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_MP_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_MP_SSADO_SHIFT)) & PCC0_PCC_DMA0_MP_SSADO_MASK)

#define PCC0_PCC_DMA0_MP_CGC_MASK                (0x40000000U)
#define PCC0_PCC_DMA0_MP_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_MP_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_MP_CGC_SHIFT)) & PCC0_PCC_DMA0_MP_CGC_MASK)

#define PCC0_PCC_DMA0_MP_PR_MASK                 (0x80000000U)
#define PCC0_PCC_DMA0_MP_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_MP_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_MP_PR_SHIFT)) & PCC0_PCC_DMA0_MP_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH0 - PCC DMA0_CH0 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH0_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH0_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH0_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH0_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH0_SSADO_MASK)

#define PCC0_PCC_DMA0_CH0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH0_CGC_SHIFT)) & PCC0_PCC_DMA0_CH0_CGC_MASK)

#define PCC0_PCC_DMA0_CH0_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH0_PR_SHIFT)) & PCC0_PCC_DMA0_CH0_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH1 - PCC DMA0_CH1 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH1_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH1_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH1_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH1_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH1_SSADO_MASK)

#define PCC0_PCC_DMA0_CH1_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH1_CGC_SHIFT)) & PCC0_PCC_DMA0_CH1_CGC_MASK)

#define PCC0_PCC_DMA0_CH1_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH1_PR_SHIFT)) & PCC0_PCC_DMA0_CH1_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH2 - PCC DMA0_CH2 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH2_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH2_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH2_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH2_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH2_SSADO_MASK)

#define PCC0_PCC_DMA0_CH2_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH2_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH2_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH2_CGC_SHIFT)) & PCC0_PCC_DMA0_CH2_CGC_MASK)

#define PCC0_PCC_DMA0_CH2_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH2_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH2_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH2_PR_SHIFT)) & PCC0_PCC_DMA0_CH2_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH3 - PCC DMA0_CH3 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH3_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH3_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH3_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH3_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH3_SSADO_MASK)

#define PCC0_PCC_DMA0_CH3_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH3_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH3_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH3_CGC_SHIFT)) & PCC0_PCC_DMA0_CH3_CGC_MASK)

#define PCC0_PCC_DMA0_CH3_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH3_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH3_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH3_PR_SHIFT)) & PCC0_PCC_DMA0_CH3_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH4 - PCC DMA0_CH4 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH4_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH4_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH4_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH4_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH4_SSADO_MASK)

#define PCC0_PCC_DMA0_CH4_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH4_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH4_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH4_CGC_SHIFT)) & PCC0_PCC_DMA0_CH4_CGC_MASK)

#define PCC0_PCC_DMA0_CH4_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH4_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH4_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH4_PR_SHIFT)) & PCC0_PCC_DMA0_CH4_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH5 - PCC DMA0_CH5 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH5_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH5_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH5_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH5_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH5_SSADO_MASK)

#define PCC0_PCC_DMA0_CH5_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH5_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH5_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH5_CGC_SHIFT)) & PCC0_PCC_DMA0_CH5_CGC_MASK)

#define PCC0_PCC_DMA0_CH5_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH5_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH5_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH5_PR_SHIFT)) & PCC0_PCC_DMA0_CH5_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH6 - PCC DMA0_CH6 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH6_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH6_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH6_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH6_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH6_SSADO_MASK)

#define PCC0_PCC_DMA0_CH6_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH6_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH6_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH6_CGC_SHIFT)) & PCC0_PCC_DMA0_CH6_CGC_MASK)

#define PCC0_PCC_DMA0_CH6_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH6_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH6_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH6_PR_SHIFT)) & PCC0_PCC_DMA0_CH6_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH7 - PCC DMA0_CH7 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH7_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH7_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH7_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH7_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH7_SSADO_MASK)

#define PCC0_PCC_DMA0_CH7_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH7_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH7_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH7_CGC_SHIFT)) & PCC0_PCC_DMA0_CH7_CGC_MASK)

#define PCC0_PCC_DMA0_CH7_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH7_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH7_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH7_PR_SHIFT)) & PCC0_PCC_DMA0_CH7_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH8 - PCC DMA0_CH8 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH8_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH8_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH8_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH8_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH8_SSADO_MASK)

#define PCC0_PCC_DMA0_CH8_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH8_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH8_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH8_CGC_SHIFT)) & PCC0_PCC_DMA0_CH8_CGC_MASK)

#define PCC0_PCC_DMA0_CH8_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH8_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH8_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH8_PR_SHIFT)) & PCC0_PCC_DMA0_CH8_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH9 - PCC DMA0_CH9 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH9_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_DMA0_CH9_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH9_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH9_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH9_SSADO_MASK)

#define PCC0_PCC_DMA0_CH9_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA0_CH9_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH9_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH9_CGC_SHIFT)) & PCC0_PCC_DMA0_CH9_CGC_MASK)

#define PCC0_PCC_DMA0_CH9_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA0_CH9_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH9_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH9_PR_SHIFT)) & PCC0_PCC_DMA0_CH9_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH10 - PCC DMA0_CH10 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH10_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH10_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH10_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH10_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH10_SSADO_MASK)

#define PCC0_PCC_DMA0_CH10_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH10_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH10_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH10_CGC_SHIFT)) & PCC0_PCC_DMA0_CH10_CGC_MASK)

#define PCC0_PCC_DMA0_CH10_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH10_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH10_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH10_PR_SHIFT)) & PCC0_PCC_DMA0_CH10_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH11 - PCC DMA0_CH11 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH11_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH11_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH11_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH11_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH11_SSADO_MASK)

#define PCC0_PCC_DMA0_CH11_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH11_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH11_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH11_CGC_SHIFT)) & PCC0_PCC_DMA0_CH11_CGC_MASK)

#define PCC0_PCC_DMA0_CH11_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH11_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH11_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH11_PR_SHIFT)) & PCC0_PCC_DMA0_CH11_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH12 - PCC DMA0_CH12 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH12_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH12_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH12_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH12_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH12_SSADO_MASK)

#define PCC0_PCC_DMA0_CH12_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH12_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH12_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH12_CGC_SHIFT)) & PCC0_PCC_DMA0_CH12_CGC_MASK)

#define PCC0_PCC_DMA0_CH12_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH12_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH12_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH12_PR_SHIFT)) & PCC0_PCC_DMA0_CH12_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH13 - PCC DMA0_CH13 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH13_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH13_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH13_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH13_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH13_SSADO_MASK)

#define PCC0_PCC_DMA0_CH13_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH13_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH13_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH13_CGC_SHIFT)) & PCC0_PCC_DMA0_CH13_CGC_MASK)

#define PCC0_PCC_DMA0_CH13_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH13_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH13_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH13_PR_SHIFT)) & PCC0_PCC_DMA0_CH13_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH14 - PCC DMA0_CH14 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH14_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH14_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH14_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH14_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH14_SSADO_MASK)

#define PCC0_PCC_DMA0_CH14_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH14_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH14_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH14_CGC_SHIFT)) & PCC0_PCC_DMA0_CH14_CGC_MASK)

#define PCC0_PCC_DMA0_CH14_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH14_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH14_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH14_PR_SHIFT)) & PCC0_PCC_DMA0_CH14_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH15 - PCC DMA0_CH15 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH15_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH15_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH15_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH15_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH15_SSADO_MASK)

#define PCC0_PCC_DMA0_CH15_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH15_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH15_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH15_CGC_SHIFT)) & PCC0_PCC_DMA0_CH15_CGC_MASK)

#define PCC0_PCC_DMA0_CH15_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH15_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH15_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH15_PR_SHIFT)) & PCC0_PCC_DMA0_CH15_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH16 - PCC DMA0_CH16 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH16_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH16_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH16_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH16_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH16_SSADO_MASK)

#define PCC0_PCC_DMA0_CH16_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH16_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH16_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH16_CGC_SHIFT)) & PCC0_PCC_DMA0_CH16_CGC_MASK)

#define PCC0_PCC_DMA0_CH16_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH16_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH16_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH16_PR_SHIFT)) & PCC0_PCC_DMA0_CH16_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH17 - PCC DMA0_CH17 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH17_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH17_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH17_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH17_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH17_SSADO_MASK)

#define PCC0_PCC_DMA0_CH17_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH17_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH17_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH17_CGC_SHIFT)) & PCC0_PCC_DMA0_CH17_CGC_MASK)

#define PCC0_PCC_DMA0_CH17_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH17_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH17_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH17_PR_SHIFT)) & PCC0_PCC_DMA0_CH17_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH18 - PCC DMA0_CH18 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH18_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH18_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH18_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH18_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH18_SSADO_MASK)

#define PCC0_PCC_DMA0_CH18_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH18_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH18_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH18_CGC_SHIFT)) & PCC0_PCC_DMA0_CH18_CGC_MASK)

#define PCC0_PCC_DMA0_CH18_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH18_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH18_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH18_PR_SHIFT)) & PCC0_PCC_DMA0_CH18_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH19 - PCC DMA0_CH19 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH19_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH19_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH19_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH19_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH19_SSADO_MASK)

#define PCC0_PCC_DMA0_CH19_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH19_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH19_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH19_CGC_SHIFT)) & PCC0_PCC_DMA0_CH19_CGC_MASK)

#define PCC0_PCC_DMA0_CH19_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH19_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH19_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH19_PR_SHIFT)) & PCC0_PCC_DMA0_CH19_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH20 - PCC DMA0_CH20 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH20_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH20_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH20_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH20_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH20_SSADO_MASK)

#define PCC0_PCC_DMA0_CH20_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH20_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH20_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH20_CGC_SHIFT)) & PCC0_PCC_DMA0_CH20_CGC_MASK)

#define PCC0_PCC_DMA0_CH20_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH20_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH20_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH20_PR_SHIFT)) & PCC0_PCC_DMA0_CH20_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH21 - PCC DMA0_CH21 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH21_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH21_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH21_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH21_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH21_SSADO_MASK)

#define PCC0_PCC_DMA0_CH21_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH21_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH21_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH21_CGC_SHIFT)) & PCC0_PCC_DMA0_CH21_CGC_MASK)

#define PCC0_PCC_DMA0_CH21_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH21_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH21_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH21_PR_SHIFT)) & PCC0_PCC_DMA0_CH21_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH22 - PCC DMA0_CH22 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH22_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH22_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH22_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH22_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH22_SSADO_MASK)

#define PCC0_PCC_DMA0_CH22_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH22_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH22_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH22_CGC_SHIFT)) & PCC0_PCC_DMA0_CH22_CGC_MASK)

#define PCC0_PCC_DMA0_CH22_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH22_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH22_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH22_PR_SHIFT)) & PCC0_PCC_DMA0_CH22_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH23 - PCC DMA0_CH23 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH23_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH23_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH23_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH23_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH23_SSADO_MASK)

#define PCC0_PCC_DMA0_CH23_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH23_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH23_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH23_CGC_SHIFT)) & PCC0_PCC_DMA0_CH23_CGC_MASK)

#define PCC0_PCC_DMA0_CH23_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH23_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH23_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH23_PR_SHIFT)) & PCC0_PCC_DMA0_CH23_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH24 - PCC DMA0_CH24 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH24_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH24_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH24_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH24_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH24_SSADO_MASK)

#define PCC0_PCC_DMA0_CH24_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH24_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH24_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH24_CGC_SHIFT)) & PCC0_PCC_DMA0_CH24_CGC_MASK)

#define PCC0_PCC_DMA0_CH24_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH24_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH24_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH24_PR_SHIFT)) & PCC0_PCC_DMA0_CH24_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH25 - PCC DMA0_CH25 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH25_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH25_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH25_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH25_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH25_SSADO_MASK)

#define PCC0_PCC_DMA0_CH25_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH25_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH25_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH25_CGC_SHIFT)) & PCC0_PCC_DMA0_CH25_CGC_MASK)

#define PCC0_PCC_DMA0_CH25_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH25_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH25_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH25_PR_SHIFT)) & PCC0_PCC_DMA0_CH25_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH26 - PCC DMA0_CH26 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH26_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH26_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH26_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH26_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH26_SSADO_MASK)

#define PCC0_PCC_DMA0_CH26_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH26_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH26_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH26_CGC_SHIFT)) & PCC0_PCC_DMA0_CH26_CGC_MASK)

#define PCC0_PCC_DMA0_CH26_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH26_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH26_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH26_PR_SHIFT)) & PCC0_PCC_DMA0_CH26_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH27 - PCC DMA0_CH27 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH27_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH27_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH27_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH27_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH27_SSADO_MASK)

#define PCC0_PCC_DMA0_CH27_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH27_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH27_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH27_CGC_SHIFT)) & PCC0_PCC_DMA0_CH27_CGC_MASK)

#define PCC0_PCC_DMA0_CH27_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH27_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH27_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH27_PR_SHIFT)) & PCC0_PCC_DMA0_CH27_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH28 - PCC DMA0_CH28 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH28_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH28_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH28_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH28_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH28_SSADO_MASK)

#define PCC0_PCC_DMA0_CH28_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH28_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH28_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH28_CGC_SHIFT)) & PCC0_PCC_DMA0_CH28_CGC_MASK)

#define PCC0_PCC_DMA0_CH28_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH28_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH28_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH28_PR_SHIFT)) & PCC0_PCC_DMA0_CH28_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH29 - PCC DMA0_CH29 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH29_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH29_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH29_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH29_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH29_SSADO_MASK)

#define PCC0_PCC_DMA0_CH29_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH29_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH29_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH29_CGC_SHIFT)) & PCC0_PCC_DMA0_CH29_CGC_MASK)

#define PCC0_PCC_DMA0_CH29_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH29_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH29_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH29_PR_SHIFT)) & PCC0_PCC_DMA0_CH29_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH30 - PCC DMA0_CH30 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH30_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH30_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH30_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH30_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH30_SSADO_MASK)

#define PCC0_PCC_DMA0_CH30_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH30_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH30_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH30_CGC_SHIFT)) & PCC0_PCC_DMA0_CH30_CGC_MASK)

#define PCC0_PCC_DMA0_CH30_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH30_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH30_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH30_PR_SHIFT)) & PCC0_PCC_DMA0_CH30_PR_MASK)
/*! @} */

/*! @name PCC_DMA0_CH31 - PCC DMA0_CH31 Register */
/*! @{ */

#define PCC0_PCC_DMA0_CH31_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_DMA0_CH31_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DMA0_CH31_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH31_SSADO_SHIFT)) & PCC0_PCC_DMA0_CH31_SSADO_MASK)

#define PCC0_PCC_DMA0_CH31_CGC_MASK              (0x40000000U)
#define PCC0_PCC_DMA0_CH31_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CH31_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH31_CGC_SHIFT)) & PCC0_PCC_DMA0_CH31_CGC_MASK)

#define PCC0_PCC_DMA0_CH31_PR_MASK               (0x80000000U)
#define PCC0_PCC_DMA0_CH31_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_CH31_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CH31_PR_SHIFT)) & PCC0_PCC_DMA0_CH31_PR_MASK)
/*! @} */

/*! @name PCC_MU0_A - PCC MU0_A Register */
/*! @{ */

#define PCC0_PCC_MU0_A_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_MU0_A_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_MU0_A_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU0_A_SSADO_SHIFT)) & PCC0_PCC_MU0_A_SSADO_MASK)

#define PCC0_PCC_MU0_A_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_MU0_A_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_MU0_A_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU0_A_CGC_SHIFT)) & PCC0_PCC_MU0_A_CGC_MASK)

#define PCC0_PCC_MU0_A_PR_MASK                   (0x80000000U)
#define PCC0_PCC_MU0_A_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_MU0_A_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU0_A_PR_SHIFT)) & PCC0_PCC_MU0_A_PR_MASK)
/*! @} */

/*! @name PCC_MU1_A - PCC MU1_A Register */
/*! @{ */

#define PCC0_PCC_MU1_A_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_MU1_A_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_MU1_A_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU1_A_SSADO_SHIFT)) & PCC0_PCC_MU1_A_SSADO_MASK)

#define PCC0_PCC_MU1_A_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_MU1_A_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_MU1_A_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU1_A_CGC_SHIFT)) & PCC0_PCC_MU1_A_CGC_MASK)

#define PCC0_PCC_MU1_A_PR_MASK                   (0x80000000U)
#define PCC0_PCC_MU1_A_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_MU1_A_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU1_A_PR_SHIFT)) & PCC0_PCC_MU1_A_PR_MASK)
/*! @} */

/*! @name PCC_MU2_A - PCC MU2_A Register */
/*! @{ */

#define PCC0_PCC_MU2_A_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_MU2_A_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_MU2_A_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU2_A_SSADO_SHIFT)) & PCC0_PCC_MU2_A_SSADO_MASK)

#define PCC0_PCC_MU2_A_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_MU2_A_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_MU2_A_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU2_A_CGC_SHIFT)) & PCC0_PCC_MU2_A_CGC_MASK)

#define PCC0_PCC_MU2_A_PR_MASK                   (0x80000000U)
#define PCC0_PCC_MU2_A_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_MU2_A_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU2_A_PR_SHIFT)) & PCC0_PCC_MU2_A_PR_MASK)
/*! @} */

/*! @name PCC_SYSPM0 - PCC SYSPM0 Register */
/*! @{ */

#define PCC0_PCC_SYSPM0_SSADO_MASK               (0xC00000U)
#define PCC0_PCC_SYSPM0_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_SYSPM0_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SYSPM0_SSADO_SHIFT)) & PCC0_PCC_SYSPM0_SSADO_MASK)

#define PCC0_PCC_SYSPM0_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_SYSPM0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_SYSPM0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SYSPM0_CGC_SHIFT)) & PCC0_PCC_SYSPM0_CGC_MASK)

#define PCC0_PCC_SYSPM0_PR_MASK                  (0x80000000U)
#define PCC0_PCC_SYSPM0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_SYSPM0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SYSPM0_PR_SHIFT)) & PCC0_PCC_SYSPM0_PR_MASK)
/*! @} */

/*! @name PCC_WUU0 - PCC WUU0 Register */
/*! @{ */

#define PCC0_PCC_WUU0_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_WUU0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_WUU0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WUU0_SSADO_SHIFT)) & PCC0_PCC_WUU0_SSADO_MASK)

#define PCC0_PCC_WUU0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_WUU0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_WUU0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WUU0_CGC_SHIFT)) & PCC0_PCC_WUU0_CGC_MASK)

#define PCC0_PCC_WUU0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_WUU0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_WUU0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WUU0_PR_SHIFT)) & PCC0_PCC_WUU0_PR_MASK)
/*! @} */

/*! @name PCC_UPOWER_MUA_RTD - PCC uPower_MUA_RTD Register */
/*! @{ */

#define PCC0_PCC_UPOWER_MUA_RTD_SSADO_MASK       (0xC00000U)
#define PCC0_PCC_UPOWER_MUA_RTD_SSADO_SHIFT      (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_UPOWER_MUA_RTD_SSADO(x)         (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_UPOWER_MUA_RTD_SSADO_SHIFT)) & PCC0_PCC_UPOWER_MUA_RTD_SSADO_MASK)

#define PCC0_PCC_UPOWER_MUA_RTD_CGC_MASK         (0x40000000U)
#define PCC0_PCC_UPOWER_MUA_RTD_CGC_SHIFT        (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_UPOWER_MUA_RTD_CGC(x)           (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_UPOWER_MUA_RTD_CGC_SHIFT)) & PCC0_PCC_UPOWER_MUA_RTD_CGC_MASK)

#define PCC0_PCC_UPOWER_MUA_RTD_PR_MASK          (0x80000000U)
#define PCC0_PCC_UPOWER_MUA_RTD_PR_SHIFT         (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_UPOWER_MUA_RTD_PR(x)            (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_UPOWER_MUA_RTD_PR_SHIFT)) & PCC0_PCC_UPOWER_MUA_RTD_PR_MASK)
/*! @} */

/*! @name PCC_WDOG0 - PCC WDOG0 Register */
/*! @{ */

#define PCC0_PCC_WDOG0_PCD_MASK                  (0x7U)
#define PCC0_PCC_WDOG0_PCD_SHIFT                 (0U)
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
#define PCC0_PCC_WDOG0_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_PCD_SHIFT)) & PCC0_PCC_WDOG0_PCD_MASK)

#define PCC0_PCC_WDOG0_FRAC_MASK                 (0x8U)
#define PCC0_PCC_WDOG0_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_WDOG0_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_FRAC_SHIFT)) & PCC0_PCC_WDOG0_FRAC_MASK)

#define PCC0_PCC_WDOG0_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_WDOG0_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_WDOG0_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_SSADO_SHIFT)) & PCC0_PCC_WDOG0_SSADO_MASK)

#define PCC0_PCC_WDOG0_PCS_MASK                  (0x7000000U)
#define PCC0_PCC_WDOG0_PCS_SHIFT                 (24U)
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
#define PCC0_PCC_WDOG0_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_PCS_SHIFT)) & PCC0_PCC_WDOG0_PCS_MASK)

#define PCC0_PCC_WDOG0_SWRST_MASK                (0x10000000U)
#define PCC0_PCC_WDOG0_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_WDOG0_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_SWRST_SHIFT)) & PCC0_PCC_WDOG0_SWRST_MASK)

#define PCC0_PCC_WDOG0_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_WDOG0_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_WDOG0_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_CGC_SHIFT)) & PCC0_PCC_WDOG0_CGC_MASK)

#define PCC0_PCC_WDOG0_PR_MASK                   (0x80000000U)
#define PCC0_PCC_WDOG0_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_WDOG0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_PR_SHIFT)) & PCC0_PCC_WDOG0_PR_MASK)
/*! @} */

/*! @name PCC_WDOG1 - PCC WDOG1 Register */
/*! @{ */

#define PCC0_PCC_WDOG1_PCD_MASK                  (0x7U)
#define PCC0_PCC_WDOG1_PCD_SHIFT                 (0U)
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
#define PCC0_PCC_WDOG1_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_PCD_SHIFT)) & PCC0_PCC_WDOG1_PCD_MASK)

#define PCC0_PCC_WDOG1_FRAC_MASK                 (0x8U)
#define PCC0_PCC_WDOG1_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_WDOG1_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_FRAC_SHIFT)) & PCC0_PCC_WDOG1_FRAC_MASK)

#define PCC0_PCC_WDOG1_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_WDOG1_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_WDOG1_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_SSADO_SHIFT)) & PCC0_PCC_WDOG1_SSADO_MASK)

#define PCC0_PCC_WDOG1_PCS_MASK                  (0x7000000U)
#define PCC0_PCC_WDOG1_PCS_SHIFT                 (24U)
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
#define PCC0_PCC_WDOG1_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_PCS_SHIFT)) & PCC0_PCC_WDOG1_PCS_MASK)

#define PCC0_PCC_WDOG1_SWRST_MASK                (0x10000000U)
#define PCC0_PCC_WDOG1_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_WDOG1_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_SWRST_SHIFT)) & PCC0_PCC_WDOG1_SWRST_MASK)

#define PCC0_PCC_WDOG1_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_WDOG1_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_WDOG1_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_CGC_SHIFT)) & PCC0_PCC_WDOG1_CGC_MASK)

#define PCC0_PCC_WDOG1_PR_MASK                   (0x80000000U)
#define PCC0_PCC_WDOG1_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_WDOG1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG1_PR_SHIFT)) & PCC0_PCC_WDOG1_PR_MASK)
/*! @} */

/*! @name PCC_TRDC_MGR - PCC TRDC_MGR Register */
/*! @{ */

#define PCC0_PCC_TRDC_MGR_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_TRDC_MGR_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_TRDC_MGR_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MGR_SSADO_SHIFT)) & PCC0_PCC_TRDC_MGR_SSADO_MASK)

#define PCC0_PCC_TRDC_MGR_CGC_MASK               (0x40000000U)
#define PCC0_PCC_TRDC_MGR_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRDC_MGR_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MGR_CGC_SHIFT)) & PCC0_PCC_TRDC_MGR_CGC_MASK)

#define PCC0_PCC_TRDC_MGR_PR_MASK                (0x80000000U)
#define PCC0_PCC_TRDC_MGR_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRDC_MGR_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MGR_PR_SHIFT)) & PCC0_PCC_TRDC_MGR_PR_MASK)
/*! @} */

/*! @name PCC_TRDC_MBC0 - PCC TRDC_MBC0 Register */
/*! @{ */

#define PCC0_PCC_TRDC_MBC0_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_TRDC_MBC0_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_TRDC_MBC0_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC0_SSADO_SHIFT)) & PCC0_PCC_TRDC_MBC0_SSADO_MASK)

#define PCC0_PCC_TRDC_MBC0_CGC_MASK              (0x40000000U)
#define PCC0_PCC_TRDC_MBC0_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRDC_MBC0_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC0_CGC_SHIFT)) & PCC0_PCC_TRDC_MBC0_CGC_MASK)

#define PCC0_PCC_TRDC_MBC0_PR_MASK               (0x80000000U)
#define PCC0_PCC_TRDC_MBC0_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRDC_MBC0_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC0_PR_SHIFT)) & PCC0_PCC_TRDC_MBC0_PR_MASK)
/*! @} */

/*! @name PCC_TRDC_MBC1 - PCC TRDC_MBC1 Register */
/*! @{ */

#define PCC0_PCC_TRDC_MBC1_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_TRDC_MBC1_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_TRDC_MBC1_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC1_SSADO_SHIFT)) & PCC0_PCC_TRDC_MBC1_SSADO_MASK)

#define PCC0_PCC_TRDC_MBC1_CGC_MASK              (0x40000000U)
#define PCC0_PCC_TRDC_MBC1_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRDC_MBC1_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC1_CGC_SHIFT)) & PCC0_PCC_TRDC_MBC1_CGC_MASK)

#define PCC0_PCC_TRDC_MBC1_PR_MASK               (0x80000000U)
#define PCC0_PCC_TRDC_MBC1_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRDC_MBC1_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC1_PR_SHIFT)) & PCC0_PCC_TRDC_MBC1_PR_MASK)
/*! @} */

/*! @name PCC_TRDC_MBC2 - PCC TRDC_MBC2 Register */
/*! @{ */

#define PCC0_PCC_TRDC_MBC2_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_TRDC_MBC2_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_TRDC_MBC2_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC2_SSADO_SHIFT)) & PCC0_PCC_TRDC_MBC2_SSADO_MASK)

#define PCC0_PCC_TRDC_MBC2_CGC_MASK              (0x40000000U)
#define PCC0_PCC_TRDC_MBC2_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRDC_MBC2_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC2_CGC_SHIFT)) & PCC0_PCC_TRDC_MBC2_CGC_MASK)

#define PCC0_PCC_TRDC_MBC2_PR_MASK               (0x80000000U)
#define PCC0_PCC_TRDC_MBC2_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRDC_MBC2_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC2_PR_SHIFT)) & PCC0_PCC_TRDC_MBC2_PR_MASK)
/*! @} */

/*! @name PCC_TRDC_MBC3 - PCC TRDC_MBC3 Register */
/*! @{ */

#define PCC0_PCC_TRDC_MBC3_SSADO_MASK            (0xC00000U)
#define PCC0_PCC_TRDC_MBC3_SSADO_SHIFT           (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_TRDC_MBC3_SSADO(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC3_SSADO_SHIFT)) & PCC0_PCC_TRDC_MBC3_SSADO_MASK)

#define PCC0_PCC_TRDC_MBC3_CGC_MASK              (0x40000000U)
#define PCC0_PCC_TRDC_MBC3_CGC_SHIFT             (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRDC_MBC3_CGC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC3_CGC_SHIFT)) & PCC0_PCC_TRDC_MBC3_CGC_MASK)

#define PCC0_PCC_TRDC_MBC3_PR_MASK               (0x80000000U)
#define PCC0_PCC_TRDC_MBC3_PR_SHIFT              (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRDC_MBC3_PR(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MBC3_PR_SHIFT)) & PCC0_PCC_TRDC_MBC3_PR_MASK)
/*! @} */

/*! @name PCC_TRDC_MRC - PCC TRDC_MRC Register */
/*! @{ */

#define PCC0_PCC_TRDC_MRC_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_TRDC_MRC_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_TRDC_MRC_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MRC_SSADO_SHIFT)) & PCC0_PCC_TRDC_MRC_SSADO_MASK)

#define PCC0_PCC_TRDC_MRC_CGC_MASK               (0x40000000U)
#define PCC0_PCC_TRDC_MRC_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRDC_MRC_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MRC_CGC_SHIFT)) & PCC0_PCC_TRDC_MRC_CGC_MASK)

#define PCC0_PCC_TRDC_MRC_PR_MASK                (0x80000000U)
#define PCC0_PCC_TRDC_MRC_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRDC_MRC_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRDC_MRC_PR_SHIFT)) & PCC0_PCC_TRDC_MRC_PR_MASK)
/*! @} */

/*! @name PCC_SEMA42_0 - PCC SEMA42_0 Register */
/*! @{ */

#define PCC0_PCC_SEMA42_0_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_SEMA42_0_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_SEMA42_0_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SEMA42_0_SSADO_SHIFT)) & PCC0_PCC_SEMA42_0_SSADO_MASK)

#define PCC0_PCC_SEMA42_0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_SEMA42_0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_SEMA42_0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SEMA42_0_CGC_SHIFT)) & PCC0_PCC_SEMA42_0_CGC_MASK)

#define PCC0_PCC_SEMA42_0_PR_MASK                (0x80000000U)
#define PCC0_PCC_SEMA42_0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_SEMA42_0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SEMA42_0_PR_SHIFT)) & PCC0_PCC_SEMA42_0_PR_MASK)
/*! @} */

/*! @name PCC_BBNSM - PCC BBNSM Register */
/*! @{ */

#define PCC0_PCC_BBNSM_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_BBNSM_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_BBNSM_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_BBNSM_SSADO_SHIFT)) & PCC0_PCC_BBNSM_SSADO_MASK)

#define PCC0_PCC_BBNSM_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_BBNSM_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_BBNSM_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_BBNSM_CGC_SHIFT)) & PCC0_PCC_BBNSM_CGC_MASK)

#define PCC0_PCC_BBNSM_PR_MASK                   (0x80000000U)
#define PCC0_PCC_BBNSM_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_BBNSM_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_BBNSM_PR_SHIFT)) & PCC0_PCC_BBNSM_PR_MASK)
/*! @} */

/*! @name PCC_FLEXSPI0 - PCC FlexSPI0 Register */
/*! @{ */

#define PCC0_PCC_FLEXSPI0_PCD_MASK               (0x7U)
#define PCC0_PCC_FLEXSPI0_PCD_SHIFT              (0U)
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
#define PCC0_PCC_FLEXSPI0_PCD(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_PCD_SHIFT)) & PCC0_PCC_FLEXSPI0_PCD_MASK)

#define PCC0_PCC_FLEXSPI0_FRAC_MASK              (0x8U)
#define PCC0_PCC_FLEXSPI0_FRAC_SHIFT             (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_FLEXSPI0_FRAC(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_FRAC_SHIFT)) & PCC0_PCC_FLEXSPI0_FRAC_MASK)

#define PCC0_PCC_FLEXSPI0_SSADO_MASK             (0xC00000U)
#define PCC0_PCC_FLEXSPI0_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_FLEXSPI0_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_SSADO_SHIFT)) & PCC0_PCC_FLEXSPI0_SSADO_MASK)

#define PCC0_PCC_FLEXSPI0_PCS_MASK               (0x7000000U)
#define PCC0_PCC_FLEXSPI0_PCS_SHIFT              (24U)
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
#define PCC0_PCC_FLEXSPI0_PCS(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_PCS_SHIFT)) & PCC0_PCC_FLEXSPI0_PCS_MASK)

#define PCC0_PCC_FLEXSPI0_SWRST_MASK             (0x10000000U)
#define PCC0_PCC_FLEXSPI0_SWRST_SHIFT            (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_FLEXSPI0_SWRST(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_SWRST_SHIFT)) & PCC0_PCC_FLEXSPI0_SWRST_MASK)

#define PCC0_PCC_FLEXSPI0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_FLEXSPI0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_FLEXSPI0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_CGC_SHIFT)) & PCC0_PCC_FLEXSPI0_CGC_MASK)

#define PCC0_PCC_FLEXSPI0_PR_MASK                (0x80000000U)
#define PCC0_PCC_FLEXSPI0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_FLEXSPI0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXSPI0_PR_SHIFT)) & PCC0_PCC_FLEXSPI0_PR_MASK)
/*! @} */

/*! @name PCC_ROMCP0 - PCC ROMCP0 Register */
/*! @{ */

#define PCC0_PCC_ROMCP0_SSADO_MASK               (0xC00000U)
#define PCC0_PCC_ROMCP0_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_ROMCP0_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ROMCP0_SSADO_SHIFT)) & PCC0_PCC_ROMCP0_SSADO_MASK)

#define PCC0_PCC_ROMCP0_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_ROMCP0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_ROMCP0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ROMCP0_CGC_SHIFT)) & PCC0_PCC_ROMCP0_CGC_MASK)

#define PCC0_PCC_ROMCP0_PR_MASK                  (0x80000000U)
#define PCC0_PCC_ROMCP0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_ROMCP0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ROMCP0_PR_SHIFT)) & PCC0_PCC_ROMCP0_PR_MASK)
/*! @} */

/*! @name PCC_LPIT0 - PCC LPIT0 Register */
/*! @{ */

#define PCC0_PCC_LPIT0_PCD_MASK                  (0x7U)
#define PCC0_PCC_LPIT0_PCD_SHIFT                 (0U)
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
#define PCC0_PCC_LPIT0_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_PCD_SHIFT)) & PCC0_PCC_LPIT0_PCD_MASK)

#define PCC0_PCC_LPIT0_FRAC_MASK                 (0x8U)
#define PCC0_PCC_LPIT0_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_LPIT0_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_FRAC_SHIFT)) & PCC0_PCC_LPIT0_FRAC_MASK)

#define PCC0_PCC_LPIT0_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_LPIT0_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_LPIT0_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_SSADO_SHIFT)) & PCC0_PCC_LPIT0_SSADO_MASK)

#define PCC0_PCC_LPIT0_PCS_MASK                  (0x7000000U)
#define PCC0_PCC_LPIT0_PCS_SHIFT                 (24U)
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
#define PCC0_PCC_LPIT0_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_PCS_SHIFT)) & PCC0_PCC_LPIT0_PCS_MASK)

#define PCC0_PCC_LPIT0_SWRST_MASK                (0x10000000U)
#define PCC0_PCC_LPIT0_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_LPIT0_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_SWRST_SHIFT)) & PCC0_PCC_LPIT0_SWRST_MASK)

#define PCC0_PCC_LPIT0_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_LPIT0_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPIT0_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_CGC_SHIFT)) & PCC0_PCC_LPIT0_CGC_MASK)

#define PCC0_PCC_LPIT0_PR_MASK                   (0x80000000U)
#define PCC0_PCC_LPIT0_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPIT0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_PR_SHIFT)) & PCC0_PCC_LPIT0_PR_MASK)
/*! @} */

/*! @name PCC_FLEXIO0 - PCC FlexIO0 Register */
/*! @{ */

#define PCC0_PCC_FLEXIO0_PCD_MASK                (0x7U)
#define PCC0_PCC_FLEXIO0_PCD_SHIFT               (0U)
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
#define PCC0_PCC_FLEXIO0_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_PCD_SHIFT)) & PCC0_PCC_FLEXIO0_PCD_MASK)

#define PCC0_PCC_FLEXIO0_FRAC_MASK               (0x8U)
#define PCC0_PCC_FLEXIO0_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_FLEXIO0_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_FRAC_SHIFT)) & PCC0_PCC_FLEXIO0_FRAC_MASK)

#define PCC0_PCC_FLEXIO0_SSADO_MASK              (0xC00000U)
#define PCC0_PCC_FLEXIO0_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_FLEXIO0_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_SSADO_SHIFT)) & PCC0_PCC_FLEXIO0_SSADO_MASK)

#define PCC0_PCC_FLEXIO0_PCS_MASK                (0x7000000U)
#define PCC0_PCC_FLEXIO0_PCS_SHIFT               (24U)
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
#define PCC0_PCC_FLEXIO0_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_PCS_SHIFT)) & PCC0_PCC_FLEXIO0_PCS_MASK)

#define PCC0_PCC_FLEXIO0_SWRST_MASK              (0x10000000U)
#define PCC0_PCC_FLEXIO0_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_FLEXIO0_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_SWRST_SHIFT)) & PCC0_PCC_FLEXIO0_SWRST_MASK)

#define PCC0_PCC_FLEXIO0_CGC_MASK                (0x40000000U)
#define PCC0_PCC_FLEXIO0_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_FLEXIO0_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_CGC_SHIFT)) & PCC0_PCC_FLEXIO0_CGC_MASK)

#define PCC0_PCC_FLEXIO0_PR_MASK                 (0x80000000U)
#define PCC0_PCC_FLEXIO0_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_FLEXIO0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_PR_SHIFT)) & PCC0_PCC_FLEXIO0_PR_MASK)
/*! @} */

/*! @name PCC_I3C0 - PCC I3C0 Register */
/*! @{ */

#define PCC0_PCC_I3C0_PCD_MASK                   (0x7U)
#define PCC0_PCC_I3C0_PCD_SHIFT                  (0U)
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
#define PCC0_PCC_I3C0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_PCD_SHIFT)) & PCC0_PCC_I3C0_PCD_MASK)

#define PCC0_PCC_I3C0_FRAC_MASK                  (0x8U)
#define PCC0_PCC_I3C0_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_I3C0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_FRAC_SHIFT)) & PCC0_PCC_I3C0_FRAC_MASK)

#define PCC0_PCC_I3C0_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_I3C0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_I3C0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_SSADO_SHIFT)) & PCC0_PCC_I3C0_SSADO_MASK)

#define PCC0_PCC_I3C0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_I3C0_PCS_SHIFT                  (24U)
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
#define PCC0_PCC_I3C0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_PCS_SHIFT)) & PCC0_PCC_I3C0_PCS_MASK)

#define PCC0_PCC_I3C0_SWRST_MASK                 (0x10000000U)
#define PCC0_PCC_I3C0_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_I3C0_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_SWRST_SHIFT)) & PCC0_PCC_I3C0_SWRST_MASK)

#define PCC0_PCC_I3C0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_I3C0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_I3C0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_CGC_SHIFT)) & PCC0_PCC_I3C0_CGC_MASK)

#define PCC0_PCC_I3C0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_I3C0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_I3C0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_I3C0_PR_SHIFT)) & PCC0_PCC_I3C0_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI0 - PCC LPSPI0 Register */
/*! @{ */

#define PCC0_PCC_LPSPI0_PCD_MASK                 (0x7U)
#define PCC0_PCC_LPSPI0_PCD_SHIFT                (0U)
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
#define PCC0_PCC_LPSPI0_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_PCD_SHIFT)) & PCC0_PCC_LPSPI0_PCD_MASK)

#define PCC0_PCC_LPSPI0_FRAC_MASK                (0x8U)
#define PCC0_PCC_LPSPI0_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_LPSPI0_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_FRAC_SHIFT)) & PCC0_PCC_LPSPI0_FRAC_MASK)

#define PCC0_PCC_LPSPI0_SSADO_MASK               (0xC00000U)
#define PCC0_PCC_LPSPI0_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_LPSPI0_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_SSADO_SHIFT)) & PCC0_PCC_LPSPI0_SSADO_MASK)

#define PCC0_PCC_LPSPI0_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPSPI0_PCS_SHIFT                (24U)
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
#define PCC0_PCC_LPSPI0_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_PCS_SHIFT)) & PCC0_PCC_LPSPI0_PCS_MASK)

#define PCC0_PCC_LPSPI0_SWRST_MASK               (0x10000000U)
#define PCC0_PCC_LPSPI0_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_LPSPI0_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_SWRST_SHIFT)) & PCC0_PCC_LPSPI0_SWRST_MASK)

#define PCC0_PCC_LPSPI0_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPSPI0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPSPI0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_CGC_SHIFT)) & PCC0_PCC_LPSPI0_CGC_MASK)

#define PCC0_PCC_LPSPI0_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPSPI0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPSPI0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_PR_SHIFT)) & PCC0_PCC_LPSPI0_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI1 - PCC LPSPI1 Register */
/*! @{ */

#define PCC0_PCC_LPSPI1_PCD_MASK                 (0x7U)
#define PCC0_PCC_LPSPI1_PCD_SHIFT                (0U)
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
#define PCC0_PCC_LPSPI1_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_PCD_SHIFT)) & PCC0_PCC_LPSPI1_PCD_MASK)

#define PCC0_PCC_LPSPI1_FRAC_MASK                (0x8U)
#define PCC0_PCC_LPSPI1_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_LPSPI1_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_FRAC_SHIFT)) & PCC0_PCC_LPSPI1_FRAC_MASK)

#define PCC0_PCC_LPSPI1_SSADO_MASK               (0xC00000U)
#define PCC0_PCC_LPSPI1_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_LPSPI1_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_SSADO_SHIFT)) & PCC0_PCC_LPSPI1_SSADO_MASK)

#define PCC0_PCC_LPSPI1_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPSPI1_PCS_SHIFT                (24U)
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
#define PCC0_PCC_LPSPI1_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_PCS_SHIFT)) & PCC0_PCC_LPSPI1_PCS_MASK)

#define PCC0_PCC_LPSPI1_SWRST_MASK               (0x10000000U)
#define PCC0_PCC_LPSPI1_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_LPSPI1_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_SWRST_SHIFT)) & PCC0_PCC_LPSPI1_SWRST_MASK)

#define PCC0_PCC_LPSPI1_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPSPI1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPSPI1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_CGC_SHIFT)) & PCC0_PCC_LPSPI1_CGC_MASK)

#define PCC0_PCC_LPSPI1_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPSPI1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPSPI1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_PR_SHIFT)) & PCC0_PCC_LPSPI1_PR_MASK)
/*! @} */

/*! @name PCC_ADC0 - PCC ADC0 Register */
/*! @{ */

#define PCC0_PCC_ADC0_PCD_MASK                   (0x7U)
#define PCC0_PCC_ADC0_PCD_SHIFT                  (0U)
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
#define PCC0_PCC_ADC0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_PCD_SHIFT)) & PCC0_PCC_ADC0_PCD_MASK)

#define PCC0_PCC_ADC0_FRAC_MASK                  (0x8U)
#define PCC0_PCC_ADC0_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_ADC0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_FRAC_SHIFT)) & PCC0_PCC_ADC0_FRAC_MASK)

#define PCC0_PCC_ADC0_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_ADC0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_ADC0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_SSADO_SHIFT)) & PCC0_PCC_ADC0_SSADO_MASK)

#define PCC0_PCC_ADC0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_ADC0_PCS_SHIFT                  (24U)
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
#define PCC0_PCC_ADC0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_PCS_SHIFT)) & PCC0_PCC_ADC0_PCS_MASK)

#define PCC0_PCC_ADC0_SWRST_MASK                 (0x10000000U)
#define PCC0_PCC_ADC0_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_ADC0_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_SWRST_SHIFT)) & PCC0_PCC_ADC0_SWRST_MASK)

#define PCC0_PCC_ADC0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_ADC0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_ADC0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_CGC_SHIFT)) & PCC0_PCC_ADC0_CGC_MASK)

#define PCC0_PCC_ADC0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_ADC0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_ADC0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_PR_SHIFT)) & PCC0_PCC_ADC0_PR_MASK)
/*! @} */

/*! @name PCC_CMP0 - PCC CMP0 Register */
/*! @{ */

#define PCC0_PCC_CMP0_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_CMP0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_CMP0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP0_SSADO_SHIFT)) & PCC0_PCC_CMP0_SSADO_MASK)

#define PCC0_PCC_CMP0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_CMP0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_CMP0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP0_CGC_SHIFT)) & PCC0_PCC_CMP0_CGC_MASK)

#define PCC0_PCC_CMP0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_CMP0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_CMP0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP0_PR_SHIFT)) & PCC0_PCC_CMP0_PR_MASK)
/*! @} */

/*! @name PCC_CMP1 - PCC CMP1 Register */
/*! @{ */

#define PCC0_PCC_CMP1_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_CMP1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_CMP1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP1_SSADO_SHIFT)) & PCC0_PCC_CMP1_SSADO_MASK)

#define PCC0_PCC_CMP1_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_CMP1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_CMP1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP1_CGC_SHIFT)) & PCC0_PCC_CMP1_CGC_MASK)

#define PCC0_PCC_CMP1_PR_MASK                    (0x80000000U)
#define PCC0_PCC_CMP1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_CMP1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP1_PR_SHIFT)) & PCC0_PCC_CMP1_PR_MASK)
/*! @} */

/*! @name PCC_DAC0 - PCC DAC0 Register */
/*! @{ */

#define PCC0_PCC_DAC0_PCD_MASK                   (0x7U)
#define PCC0_PCC_DAC0_PCD_SHIFT                  (0U)
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
#define PCC0_PCC_DAC0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_PCD_SHIFT)) & PCC0_PCC_DAC0_PCD_MASK)

#define PCC0_PCC_DAC0_FRAC_MASK                  (0x8U)
#define PCC0_PCC_DAC0_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_DAC0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_FRAC_SHIFT)) & PCC0_PCC_DAC0_FRAC_MASK)

#define PCC0_PCC_DAC0_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_DAC0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DAC0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_SSADO_SHIFT)) & PCC0_PCC_DAC0_SSADO_MASK)

#define PCC0_PCC_DAC0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_DAC0_PCS_SHIFT                  (24U)
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
#define PCC0_PCC_DAC0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_PCS_SHIFT)) & PCC0_PCC_DAC0_PCS_MASK)

#define PCC0_PCC_DAC0_SWRST_MASK                 (0x10000000U)
#define PCC0_PCC_DAC0_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_DAC0_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_SWRST_SHIFT)) & PCC0_PCC_DAC0_SWRST_MASK)

#define PCC0_PCC_DAC0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_DAC0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DAC0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_CGC_SHIFT)) & PCC0_PCC_DAC0_CGC_MASK)

#define PCC0_PCC_DAC0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_DAC0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DAC0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_PR_SHIFT)) & PCC0_PCC_DAC0_PR_MASK)
/*! @} */

/*! @name PCC_DAC1 - PCC DAC1 Register */
/*! @{ */

#define PCC0_PCC_DAC1_PCD_MASK                   (0x7U)
#define PCC0_PCC_DAC1_PCD_SHIFT                  (0U)
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
#define PCC0_PCC_DAC1_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_PCD_SHIFT)) & PCC0_PCC_DAC1_PCD_MASK)

#define PCC0_PCC_DAC1_FRAC_MASK                  (0x8U)
#define PCC0_PCC_DAC1_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_DAC1_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_FRAC_SHIFT)) & PCC0_PCC_DAC1_FRAC_MASK)

#define PCC0_PCC_DAC1_SSADO_MASK                 (0xC00000U)
#define PCC0_PCC_DAC1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_DAC1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_SSADO_SHIFT)) & PCC0_PCC_DAC1_SSADO_MASK)

#define PCC0_PCC_DAC1_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_DAC1_PCS_SHIFT                  (24U)
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
#define PCC0_PCC_DAC1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_PCS_SHIFT)) & PCC0_PCC_DAC1_PCS_MASK)

#define PCC0_PCC_DAC1_SWRST_MASK                 (0x10000000U)
#define PCC0_PCC_DAC1_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC0_PCC_DAC1_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_SWRST_SHIFT)) & PCC0_PCC_DAC1_SWRST_MASK)

#define PCC0_PCC_DAC1_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_DAC1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DAC1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_CGC_SHIFT)) & PCC0_PCC_DAC1_CGC_MASK)

#define PCC0_PCC_DAC1_PR_MASK                    (0x80000000U)
#define PCC0_PCC_DAC1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DAC1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_PR_SHIFT)) & PCC0_PCC_DAC1_PR_MASK)
/*! @} */

/*! @name PCC_CM33_CACHE_CONTROLLER - PCC CM33_Cache_Controller Register */
/*! @{ */

#define PCC0_PCC_CM33_CACHE_CONTROLLER_SSADO_MASK (0xC00000U)
#define PCC0_PCC_CM33_CACHE_CONTROLLER_SSADO_SHIFT (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_CM33_CACHE_CONTROLLER_SSADO(x)  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CM33_CACHE_CONTROLLER_SSADO_SHIFT)) & PCC0_PCC_CM33_CACHE_CONTROLLER_SSADO_MASK)

#define PCC0_PCC_CM33_CACHE_CONTROLLER_CGC_MASK  (0x40000000U)
#define PCC0_PCC_CM33_CACHE_CONTROLLER_CGC_SHIFT (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_CM33_CACHE_CONTROLLER_CGC(x)    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CM33_CACHE_CONTROLLER_CGC_SHIFT)) & PCC0_PCC_CM33_CACHE_CONTROLLER_CGC_MASK)

#define PCC0_PCC_CM33_CACHE_CONTROLLER_PR_MASK   (0x80000000U)
#define PCC0_PCC_CM33_CACHE_CONTROLLER_PR_SHIFT  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_CM33_CACHE_CONTROLLER_PR(x)     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CM33_CACHE_CONTROLLER_PR_SHIFT)) & PCC0_PCC_CM33_CACHE_CONTROLLER_PR_MASK)
/*! @} */

/*! @name PCC_S400_LPUART - PCC S400_LPUART Register */
/*! @{ */

#define PCC0_PCC_S400_LPUART_PCD_MASK            (0x7U)
#define PCC0_PCC_S400_LPUART_PCD_SHIFT           (0U)
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
#define PCC0_PCC_S400_LPUART_PCD(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_S400_LPUART_PCD_SHIFT)) & PCC0_PCC_S400_LPUART_PCD_MASK)

#define PCC0_PCC_S400_LPUART_FRAC_MASK           (0x8U)
#define PCC0_PCC_S400_LPUART_FRAC_SHIFT          (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_S400_LPUART_FRAC(x)             (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_S400_LPUART_FRAC_SHIFT)) & PCC0_PCC_S400_LPUART_FRAC_MASK)

#define PCC0_PCC_S400_LPUART_SSADO_MASK          (0xC00000U)
#define PCC0_PCC_S400_LPUART_SSADO_SHIFT         (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_S400_LPUART_SSADO(x)            (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_S400_LPUART_SSADO_SHIFT)) & PCC0_PCC_S400_LPUART_SSADO_MASK)

#define PCC0_PCC_S400_LPUART_PCS_MASK            (0x7000000U)
#define PCC0_PCC_S400_LPUART_PCS_SHIFT           (24U)
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
#define PCC0_PCC_S400_LPUART_PCS(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_S400_LPUART_PCS_SHIFT)) & PCC0_PCC_S400_LPUART_PCS_MASK)

#define PCC0_PCC_S400_LPUART_CGC_MASK            (0x40000000U)
#define PCC0_PCC_S400_LPUART_CGC_SHIFT           (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_S400_LPUART_CGC(x)              (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_S400_LPUART_CGC_SHIFT)) & PCC0_PCC_S400_LPUART_CGC_MASK)

#define PCC0_PCC_S400_LPUART_PR_MASK             (0x80000000U)
#define PCC0_PCC_S400_LPUART_PR_SHIFT            (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_S400_LPUART_PR(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_S400_LPUART_PR_SHIFT)) & PCC0_PCC_S400_LPUART_PR_MASK)
/*! @} */

/*! @name PCC_POWERSYS_WDOG - PCC Powersys_WDOG Register */
/*! @{ */

#define PCC0_PCC_POWERSYS_WDOG_PCD_MASK          (0x7U)
#define PCC0_PCC_POWERSYS_WDOG_PCD_SHIFT         (0U)
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
#define PCC0_PCC_POWERSYS_WDOG_PCD(x)            (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_POWERSYS_WDOG_PCD_SHIFT)) & PCC0_PCC_POWERSYS_WDOG_PCD_MASK)

#define PCC0_PCC_POWERSYS_WDOG_FRAC_MASK         (0x8U)
#define PCC0_PCC_POWERSYS_WDOG_FRAC_SHIFT        (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_POWERSYS_WDOG_FRAC(x)           (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_POWERSYS_WDOG_FRAC_SHIFT)) & PCC0_PCC_POWERSYS_WDOG_FRAC_MASK)

#define PCC0_PCC_POWERSYS_WDOG_SSADO_MASK        (0xC00000U)
#define PCC0_PCC_POWERSYS_WDOG_SSADO_SHIFT       (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_POWERSYS_WDOG_SSADO(x)          (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_POWERSYS_WDOG_SSADO_SHIFT)) & PCC0_PCC_POWERSYS_WDOG_SSADO_MASK)

#define PCC0_PCC_POWERSYS_WDOG_PCS_MASK          (0x7000000U)
#define PCC0_PCC_POWERSYS_WDOG_PCS_SHIFT         (24U)
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
#define PCC0_PCC_POWERSYS_WDOG_PCS(x)            (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_POWERSYS_WDOG_PCS_SHIFT)) & PCC0_PCC_POWERSYS_WDOG_PCS_MASK)

#define PCC0_PCC_POWERSYS_WDOG_CGC_MASK          (0x40000000U)
#define PCC0_PCC_POWERSYS_WDOG_CGC_SHIFT         (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_POWERSYS_WDOG_CGC(x)            (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_POWERSYS_WDOG_CGC_SHIFT)) & PCC0_PCC_POWERSYS_WDOG_CGC_MASK)

#define PCC0_PCC_POWERSYS_WDOG_PR_MASK           (0x80000000U)
#define PCC0_PCC_POWERSYS_WDOG_PR_SHIFT          (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_POWERSYS_WDOG_PR(x)             (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_POWERSYS_WDOG_PR_SHIFT)) & PCC0_PCC_POWERSYS_WDOG_PR_MASK)
/*! @} */

/*! @name PCC_OCOTP - PCC OCOTP Register */
/*! @{ */

#define PCC0_PCC_OCOTP_SSADO_MASK                (0xC00000U)
#define PCC0_PCC_OCOTP_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC0_PCC_OCOTP_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_OCOTP_SSADO_SHIFT)) & PCC0_PCC_OCOTP_SSADO_MASK)

#define PCC0_PCC_OCOTP_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_OCOTP_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_OCOTP_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_OCOTP_CGC_SHIFT)) & PCC0_PCC_OCOTP_CGC_MASK)

#define PCC0_PCC_OCOTP_PR_MASK                   (0x80000000U)
#define PCC0_PCC_OCOTP_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_OCOTP_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_OCOTP_PR_SHIFT)) & PCC0_PCC_OCOTP_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC0_Register_Masks */


/*!
 * @}
 */ /* end of group PCC0_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC0_H_ */

