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
**         CMSIS Peripheral Access Layer for SIM_SEC
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
 * @file PERI_SIM_SEC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM_SEC
 *
 * CMSIS Peripheral Access Layer for SIM_SEC
 */

#if !defined(PERI_SIM_SEC_H_)
#define PERI_SIM_SEC_H_                          /**< Symbol preventing repeated inclusion */

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
   -- SIM_SEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_SEC_Peripheral_Access_Layer SIM_SEC Peripheral Access Layer
 * @{
 */

/** SIM_SEC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR0;                              /**< HW RGeneral Purpose Register 0, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DGO_CTRL0;                         /**< RTD SIM DGO Control Register 0, offset: 0x8 */
  __IO uint32_t DGO_CTRL1;                         /**< RTD SIM DGO Control Register 0, offset: 0xC */
  __IO uint32_t DGO_GP0;                           /**< RTD SIM DGO General Purpose Register 0, offset: 0x10 */
  __IO uint32_t DGO_GP1;                           /**< RTD SIM DGO General Purpose Register 1, offset: 0x14 */
  __IO uint32_t DGO_GP2;                           /**< RTD SIM DGO General Purpose Register 2, offset: 0x18 */
  __IO uint32_t DGO_GP3;                           /**< RTD SIM DGO General Purpose Register 3, offset: 0x1C */
  __IO uint32_t DGO_GP4;                           /**< RTD SIM DGO General Purpose Register 4, offset: 0x20 */
  __IO uint32_t DGO_GP5;                           /**< RTD SIM DGO General Purpose Register 5, offset: 0x24 */
  __IO uint32_t DGO_GP6;                           /**< RTD SIM DGO General Purpose Register 6, offset: 0x28 */
  __IO uint32_t DGO_GP7;                           /**< RTD SIM DGO General Purpose Register 7, offset: 0x2C */
  __IO uint32_t DGO_GP8;                           /**< RTD SIM DGO General Purpose Register 8, offset: 0x30 */
  __IO uint32_t DGO_GP9;                           /**< RESET0_B Pad and Filter Configuration, offset: 0x34 */
  __IO uint32_t DGO_GP10;                          /**< PTA Operating Range Control, offset: 0x38 */
  __IO uint32_t DGO_GP11;                          /**< PTB Operating Range Control, offset: 0x3C */
  __IO uint32_t DGO_GP12;                          /**< Low Power Debug Mux, offset: 0x40 */
  __IO uint32_t SYSCTRL0;                          /**< Realtime Domains System Control Register 0, offset: 0x44 */
  __IO uint32_t SSRAM_ACCESS_DISABLE;              /**< System Shared RAM Access Disable Register, offset: 0x48 */
  __IO uint32_t LPAV_MASTER_ALLOC_CTRL;            /**< LPAV Master Allocation Control Register, offset: 0x4C */
  __IO uint32_t LPAV_SLAVE_ALLOC_CTRL;             /**< LPAV Slave Allocation Control Register, offset: 0x50 */
  __IO uint32_t LPAV_DMA2_CH_ALLOC_CTRL;           /**< LPAV DMA2 CH Allocation Control Register, offset: 0x54 */
  __IO uint32_t LPAV_DMA2_REQ_ALLOC_CTRL;          /**< LPAV DMA2 Request Allocation Control Register, offset: 0x58 */
  __IO uint32_t M33_CFGSSTCALIB;                   /**< Secure SysTick Calibration Configuration, offset: 0x5C */
  __IO uint32_t FUSION_GPR0;                       /**< Fusion DSP General Purpose Register, offset: 0x60 */
  __I  uint32_t FUSION_GPR1;                       /**< Fusion DSP General Purpose Register, offset: 0x64 */
  __I  uint32_t FUSION_GPR2;                       /**< Fusion DSP General Purpose Register, offset: 0x68 */
  __IO uint32_t RTD_INTERRUPT_MASK0;               /**< Realtime Domain Interrupt Mask 0, offset: 0x6C */
  __IO uint32_t APD_INTERRUPT_MASK0;               /**< Application Domain Interrupt Mask 0, offset: 0x70 */
  __IO uint32_t AVD_INTERRUPT_MASK0;               /**< Audio-Video Domain Interrupt Mask 0, offset: 0x74 */
  __IO uint32_t WRITE_ASSIST_CTRL;                 /**< RTD Memories Write-Assist Control, offset: 0x78 */
  __IO uint32_t SYSCTRL1;                          /**< Realtime Domains System Control Register 1, offset: 0x7C */
  __IO uint32_t SYSCTRL2;                          /**< Realtime Domains System Control Register 2, offset: 0x80 */
  __IO uint32_t SYSCTRL3;                          /**< Realtime Domains System Control Register 3, offset: 0x84 */
  __IO uint32_t SYSCTRL4;                          /**< Realtime Domains System Control Register 4, offset: 0x88 */
} SIM_SEC_Type;

/* ----------------------------------------------------------------------------
   -- SIM_SEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_SEC_Register_Masks SIM_SEC Register Masks
 * @{
 */

/*! @name GPR0 - HW RGeneral Purpose Register 0 */
/*! @{ */

#define SIM_SEC_GPR0_GPR0_MASK                   (0xFFFFFFFFU)
#define SIM_SEC_GPR0_GPR0_SHIFT                  (0U)
/*! GPR0 - General Purpose Read/Write Register */
#define SIM_SEC_GPR0_GPR0(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_GPR0_GPR0_SHIFT)) & SIM_SEC_GPR0_GPR0_MASK)
/*! @} */

/*! @name DGO_CTRL0 - RTD SIM DGO Control Register 0 */
/*! @{ */

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP0_MASK    (0x1U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP0_SHIFT   (0U)
/*! UPDATE_DGO_GP0 - DGO General Purpose Register 0 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP0_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP0_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP1_MASK    (0x2U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP1_SHIFT   (1U)
/*! UPDATE_DGO_GP1 - DGO General Purpose Register 1 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP1_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP1_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP2_MASK    (0x4U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP2_SHIFT   (2U)
/*! UPDATE_DGO_GP2 - DGO General Purpose Register 2 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP2(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP2_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP2_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP3_MASK    (0x8U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP3_SHIFT   (3U)
/*! UPDATE_DGO_GP3 - DGO General Purpose Register 3 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP3(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP3_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP3_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP4_MASK    (0x10U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP4_SHIFT   (4U)
/*! UPDATE_DGO_GP4 - DGO General Purpose Register 4 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP4(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP4_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP4_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP5_MASK    (0x20U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP5_SHIFT   (5U)
/*! UPDATE_DGO_GP5 - DGO General Purpose Register 5 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP5(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP5_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP5_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP6_MASK    (0x40U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP6_SHIFT   (6U)
/*! UPDATE_DGO_GP6 - DGO General Purpose Register 6 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP6(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP6_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP6_MASK)

#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP7_MASK    (0x80U)
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP7_SHIFT   (7U)
/*! UPDATE_DGO_GP7 - DGO General Purpose Register 7 Update */
#define SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP7(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP7_SHIFT)) & SIM_SEC_DGO_CTRL0_UPDATE_DGO_GP7_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP0_MASK    (0x100U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP0_SHIFT   (8U)
/*! WR_ACK_DGO_GP0 - DGO General Purpose Register 0 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP0_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP0_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP1_MASK    (0x200U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP1_SHIFT   (9U)
/*! WR_ACK_DGO_GP1 - DGO General Purpose Register 1 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP1_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP1_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP2_MASK    (0x400U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP2_SHIFT   (10U)
/*! WR_ACK_DGO_GP2 - DGO General Purpose Register 2 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP2(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP2_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP2_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP3_MASK    (0x800U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP3_SHIFT   (11U)
/*! WR_ACK_DGO_GP3 - DGO General Purpose Register 3 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP3(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP3_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP3_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP4_MASK    (0x1000U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP4_SHIFT   (12U)
/*! WR_ACK_DGO_GP4 - DGO General Purpose Register 4 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP4(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP4_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP4_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP5_MASK    (0x2000U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP5_SHIFT   (13U)
/*! WR_ACK_DGO_GP5 - DGO General Purpose Register 5 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP5(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP5_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP5_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP6_MASK    (0x4000U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP6_SHIFT   (14U)
/*! WR_ACK_DGO_GP6 - DGO General Purpose Register 6 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP6(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP6_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP6_MASK)

#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP7_MASK    (0x8000U)
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP7_SHIFT   (15U)
/*! WR_ACK_DGO_GP7 - DGO General Purpose Register 7 Write Acknowledge */
#define SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP7(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP7_SHIFT)) & SIM_SEC_DGO_CTRL0_WR_ACK_DGO_GP7_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK0_MASK       (0x10000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK0_SHIFT      (16U)
/*! INT_EN_ACK0 - DGO General Purpose Register 0 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK0(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK0_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK0_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK1_MASK       (0x20000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK1_SHIFT      (17U)
/*! INT_EN_ACK1 - DGO General Purpose Register 1 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK1(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK1_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK1_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK2_MASK       (0x40000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK2_SHIFT      (18U)
/*! INT_EN_ACK2 - DGO General Purpose Register 2 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK2(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK2_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK2_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK3_MASK       (0x80000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK3_SHIFT      (19U)
/*! INT_EN_ACK3 - DGO General Purpose Register 3 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK3(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK3_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK3_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK4_MASK       (0x100000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK4_SHIFT      (20U)
/*! INT_EN_ACK4 - DGO General Purpose Register 4 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK4(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK4_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK4_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK5_MASK       (0x200000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK5_SHIFT      (21U)
/*! INT_EN_ACK5 - DGO General Purpose Register 5 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK5(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK5_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK5_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK6_MASK       (0x400000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK6_SHIFT      (22U)
/*! INT_EN_ACK6 - DGO General Purpose Register 6 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK6(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK6_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK6_MASK)

#define SIM_SEC_DGO_CTRL0_INT_EN_ACK7_MASK       (0x800000U)
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK7_SHIFT      (23U)
/*! INT_EN_ACK7 - DGO General Purpose Register 7 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL0_INT_EN_ACK7(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL0_INT_EN_ACK7_SHIFT)) & SIM_SEC_DGO_CTRL0_INT_EN_ACK7_MASK)
/*! @} */

/*! @name DGO_CTRL1 - RTD SIM DGO Control Register 0 */
/*! @{ */

#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP8_MASK    (0x1U)
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP8_SHIFT   (0U)
/*! UPDATE_DGO_GP8 - DGO General Purpose Register 8 Update */
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP8(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP8_SHIFT)) & SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP8_MASK)

#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP9_MASK    (0x2U)
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP9_SHIFT   (1U)
/*! UPDATE_DGO_GP9 - DGO General Purpose Register 9 Update */
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP9(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP9_SHIFT)) & SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP9_MASK)

#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP10_MASK   (0x4U)
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP10_SHIFT  (2U)
/*! UPDATE_DGO_GP10 - DGO General Purpose Register 10 Update */
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP10(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP10_SHIFT)) & SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP10_MASK)

#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP11_MASK   (0x8U)
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP11_SHIFT  (3U)
/*! UPDATE_DGO_GP11 - DGO General Purpose Register 11 Update */
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP11(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP11_SHIFT)) & SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP11_MASK)

#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP12_MASK   (0x10U)
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP12_SHIFT  (4U)
/*! UPDATE_DGO_GP12 - DGO General Purpose Register 12 Update */
#define SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP12(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP12_SHIFT)) & SIM_SEC_DGO_CTRL1_UPDATE_DGO_GP12_MASK)

#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP8_MASK    (0x100U)
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP8_SHIFT   (8U)
/*! WR_ACK_DGO_GP8 - DGO General Purpose Register 8 Write Acknowledge */
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP8(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP8_SHIFT)) & SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP8_MASK)

#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP9_MASK    (0x200U)
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP9_SHIFT   (9U)
/*! WR_ACK_DGO_GP9 - DGO General Purpose Register 9 Write Acknowledge */
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP9(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP9_SHIFT)) & SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP9_MASK)

#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP10_MASK   (0x400U)
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP10_SHIFT  (10U)
/*! WR_ACK_DGO_GP10 - DGO General Purpose Register 10 Write Acknowledge */
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP10(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP10_SHIFT)) & SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP10_MASK)

#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP11_MASK   (0x800U)
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP11_SHIFT  (11U)
/*! WR_ACK_DGO_GP11 - DGO General Purpose Register 11 Write Acknowledge */
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP11(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP11_SHIFT)) & SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP11_MASK)

#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP12_MASK   (0x1000U)
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP12_SHIFT  (12U)
/*! WR_ACK_DGO_GP12 - DGO General Purpose Register 12 Write Acknowledge */
#define SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP12(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP12_SHIFT)) & SIM_SEC_DGO_CTRL1_WR_ACK_DGO_GP12_MASK)

#define SIM_SEC_DGO_CTRL1_INT_EN_ACK8_MASK       (0x10000U)
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK8_SHIFT      (16U)
/*! INT_EN_ACK8 - DGO General Purpose Register 8 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK8(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_INT_EN_ACK8_SHIFT)) & SIM_SEC_DGO_CTRL1_INT_EN_ACK8_MASK)

#define SIM_SEC_DGO_CTRL1_INT_EN_ACK9_MASK       (0x20000U)
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK9_SHIFT      (17U)
/*! INT_EN_ACK9 - DGO General Purpose Register 9 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK9(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_INT_EN_ACK9_SHIFT)) & SIM_SEC_DGO_CTRL1_INT_EN_ACK9_MASK)

#define SIM_SEC_DGO_CTRL1_INT_EN_ACK10_MASK      (0x40000U)
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK10_SHIFT     (18U)
/*! INT_EN_ACK10 - DGO General Purpose Register 10 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK10(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_INT_EN_ACK10_SHIFT)) & SIM_SEC_DGO_CTRL1_INT_EN_ACK10_MASK)

#define SIM_SEC_DGO_CTRL1_INT_EN_ACK11_MASK      (0x80000U)
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK11_SHIFT     (19U)
/*! INT_EN_ACK11 - DGO General Purpose Register 11 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK11(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_INT_EN_ACK11_SHIFT)) & SIM_SEC_DGO_CTRL1_INT_EN_ACK11_MASK)

#define SIM_SEC_DGO_CTRL1_INT_EN_ACK12_MASK      (0x100000U)
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK12_SHIFT     (20U)
/*! INT_EN_ACK12 - DGO General Purpose Register 12 Interrupt Acknowledge */
#define SIM_SEC_DGO_CTRL1_INT_EN_ACK12(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_CTRL1_INT_EN_ACK12_SHIFT)) & SIM_SEC_DGO_CTRL1_INT_EN_ACK12_MASK)
/*! @} */

/*! @name DGO_GP0 - RTD SIM DGO General Purpose Register 0 */
/*! @{ */

#define SIM_SEC_DGO_GP0_SIM_DGO_GP0_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP0_SIM_DGO_GP0_SHIFT        (0U)
/*! SIM_DGO_GP0 - SIM DGO General purpose register 0 */
#define SIM_SEC_DGO_GP0_SIM_DGO_GP0(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP0_SIM_DGO_GP0_SHIFT)) & SIM_SEC_DGO_GP0_SIM_DGO_GP0_MASK)
/*! @} */

/*! @name DGO_GP1 - RTD SIM DGO General Purpose Register 1 */
/*! @{ */

#define SIM_SEC_DGO_GP1_SIM_DGO_GP1_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP1_SIM_DGO_GP1_SHIFT        (0U)
/*! SIM_DGO_GP1 - SIM DGO General purpose register 1 */
#define SIM_SEC_DGO_GP1_SIM_DGO_GP1(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP1_SIM_DGO_GP1_SHIFT)) & SIM_SEC_DGO_GP1_SIM_DGO_GP1_MASK)
/*! @} */

/*! @name DGO_GP2 - RTD SIM DGO General Purpose Register 2 */
/*! @{ */

#define SIM_SEC_DGO_GP2_SIM_DGO_GP2_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP2_SIM_DGO_GP2_SHIFT        (0U)
/*! SIM_DGO_GP2 - SIM DGO General purpose register 2 */
#define SIM_SEC_DGO_GP2_SIM_DGO_GP2(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP2_SIM_DGO_GP2_SHIFT)) & SIM_SEC_DGO_GP2_SIM_DGO_GP2_MASK)
/*! @} */

/*! @name DGO_GP3 - RTD SIM DGO General Purpose Register 3 */
/*! @{ */

#define SIM_SEC_DGO_GP3_SIM_DGO_GP3_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP3_SIM_DGO_GP3_SHIFT        (0U)
/*! SIM_DGO_GP3 - SIM DGO General purpose register 3 */
#define SIM_SEC_DGO_GP3_SIM_DGO_GP3(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP3_SIM_DGO_GP3_SHIFT)) & SIM_SEC_DGO_GP3_SIM_DGO_GP3_MASK)
/*! @} */

/*! @name DGO_GP4 - RTD SIM DGO General Purpose Register 4 */
/*! @{ */

#define SIM_SEC_DGO_GP4_SIM_DGO_GP4_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP4_SIM_DGO_GP4_SHIFT        (0U)
/*! SIM_DGO_GP4 - SIM DGO General purpose register 4 */
#define SIM_SEC_DGO_GP4_SIM_DGO_GP4(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP4_SIM_DGO_GP4_SHIFT)) & SIM_SEC_DGO_GP4_SIM_DGO_GP4_MASK)
/*! @} */

/*! @name DGO_GP5 - RTD SIM DGO General Purpose Register 5 */
/*! @{ */

#define SIM_SEC_DGO_GP5_SIM_DGO_GP5_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP5_SIM_DGO_GP5_SHIFT        (0U)
/*! SIM_DGO_GP5 - SIM DGO General purpose register 5 */
#define SIM_SEC_DGO_GP5_SIM_DGO_GP5(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP5_SIM_DGO_GP5_SHIFT)) & SIM_SEC_DGO_GP5_SIM_DGO_GP5_MASK)
/*! @} */

/*! @name DGO_GP6 - RTD SIM DGO General Purpose Register 6 */
/*! @{ */

#define SIM_SEC_DGO_GP6_SIM_DGO_GP6_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP6_SIM_DGO_GP6_SHIFT        (0U)
/*! SIM_DGO_GP6 - SIM DGO General purpose register 6 */
#define SIM_SEC_DGO_GP6_SIM_DGO_GP6(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP6_SIM_DGO_GP6_SHIFT)) & SIM_SEC_DGO_GP6_SIM_DGO_GP6_MASK)
/*! @} */

/*! @name DGO_GP7 - RTD SIM DGO General Purpose Register 7 */
/*! @{ */

#define SIM_SEC_DGO_GP7_SIM_DGO_GP7_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP7_SIM_DGO_GP7_SHIFT        (0U)
/*! SIM_DGO_GP7 - SIM DGO General purpose register 7 */
#define SIM_SEC_DGO_GP7_SIM_DGO_GP7(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP7_SIM_DGO_GP7_SHIFT)) & SIM_SEC_DGO_GP7_SIM_DGO_GP7_MASK)
/*! @} */

/*! @name DGO_GP8 - RTD SIM DGO General Purpose Register 8 */
/*! @{ */

#define SIM_SEC_DGO_GP8_SIM_DGO_GP8_MASK         (0xFFFFFFFFU)
#define SIM_SEC_DGO_GP8_SIM_DGO_GP8_SHIFT        (0U)
/*! SIM_DGO_GP8 - SIM DGO General purpose register 8 */
#define SIM_SEC_DGO_GP8_SIM_DGO_GP8(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP8_SIM_DGO_GP8_SHIFT)) & SIM_SEC_DGO_GP8_SIM_DGO_GP8_MASK)
/*! @} */

/*! @name DGO_GP9 - RESET0_B Pad and Filter Configuration */
/*! @{ */

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PS_MASK  (0x1U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PS_SHIFT (0U)
/*! RESET0_B_CONFIG_PS - Weak Pull Select */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PS(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PS_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PS_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PE_MASK  (0x2U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PE_SHIFT (1U)
/*! RESET0_B_CONFIG_PE - Weak Pull Enable */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PE_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PE_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_SRE_MASK (0x4U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_SRE_SHIFT (2U)
/*! RESET0_B_CONFIG_SRE - Slew Rate Enable */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_SRE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_SRE_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_SRE_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PFE_MASK (0x10U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PFE_SHIFT (4U)
/*! RESET0_B_CONFIG_PFE - Passive Filter Enable */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PFE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PFE_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_PFE_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_ODE_MASK (0x20U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_ODE_SHIFT (5U)
/*! RESET0_B_CONFIG_ODE - Open Drain Enable */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_ODE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_ODE_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_ODE_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DSE_MASK (0x40U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DSE_SHIFT (6U)
/*! RESET0_B_CONFIG_DSE - Drive Strength Enable */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DSE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DSE_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DSE_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_LK_MASK  (0x8000U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_LK_SHIFT (15U)
/*! RESET0_B_CONFIG_LK - Lock: Locks writes to this register */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_LK(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_LK_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_LK_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFE_MASK (0x100000U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFE_SHIFT (20U)
/*! RESET0_B_CONFIG_DFE - Digital Filter Enable */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFE_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFE_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFCS_MASK (0x200000U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFCS_SHIFT (21U)
/*! RESET0_B_CONFIG_DFCS - Digital Filter Clock Select */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFCS(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFCS_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFCS_MASK)

#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFD_MASK (0xFC00000U)
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFD_SHIFT (22U)
/*! RESET0_B_CONFIG_DFD - Digital Filter duration: Defines deglitch count */
#define SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFD(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFD_SHIFT)) & SIM_SEC_DGO_GP9_RESET0_B_CONFIG_DFD_MASK)
/*! @} */

/*! @name DGO_GP10 - PTA Operating Range Control */
/*! @{ */

#define SIM_SEC_DGO_GP10_PTA_OPERATING_RANGE_MASK (0x3U)
#define SIM_SEC_DGO_GP10_PTA_OPERATING_RANGE_SHIFT (0U)
/*! PTA_OPERATING_RANGE - PTA Operating Range (Write Once) */
#define SIM_SEC_DGO_GP10_PTA_OPERATING_RANGE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP10_PTA_OPERATING_RANGE_SHIFT)) & SIM_SEC_DGO_GP10_PTA_OPERATING_RANGE_MASK)
/*! @} */

/*! @name DGO_GP11 - PTB Operating Range Control */
/*! @{ */

#define SIM_SEC_DGO_GP11_PTB_OPERATING_RANGE_MASK (0x1U)
#define SIM_SEC_DGO_GP11_PTB_OPERATING_RANGE_SHIFT (0U)
/*! PTB_OPERATING_RANGE - PTB Operating Range (Write Once) */
#define SIM_SEC_DGO_GP11_PTB_OPERATING_RANGE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP11_PTB_OPERATING_RANGE_SHIFT)) & SIM_SEC_DGO_GP11_PTB_OPERATING_RANGE_MASK)
/*! @} */

/*! @name DGO_GP12 - Low Power Debug Mux */
/*! @{ */

#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_APD_MASK (0xFFU)
#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_APD_SHIFT (0U)
/*! LP_DEBUG_MUX_LV_SEL_APD - Low Voltage Select Application Domain */
#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_APD(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_APD_SHIFT)) & SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_APD_MASK)

#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_RTD_MASK (0xFF00U)
#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_RTD_SHIFT (8U)
/*! LP_DEBUG_MUX_LV_SEL_RTD - Low Voltage Select Realtime Domain */
#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_RTD(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_RTD_SHIFT)) & SIM_SEC_DGO_GP12_LP_DEBUG_MUX_LV_SEL_RTD_MASK)

#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_HV_SEL_MASK (0x7FF0000U)
#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_HV_SEL_SHIFT (16U)
/*! LP_DEBUG_MUX_HV_SEL - High Voltage Select */
#define SIM_SEC_DGO_GP12_LP_DEBUG_MUX_HV_SEL(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_DGO_GP12_LP_DEBUG_MUX_HV_SEL_SHIFT)) & SIM_SEC_DGO_GP12_LP_DEBUG_MUX_HV_SEL_MASK)
/*! @} */

/*! @name SYSCTRL0 - Realtime Domains System Control Register 0 */
/*! @{ */

#define SIM_SEC_SYSCTRL0_CM33_RST_REQ_MASK       (0x4U)
#define SIM_SEC_SYSCTRL0_CM33_RST_REQ_SHIFT      (2U)
/*! CM33_RST_REQ - Request to reset CM33 core, CM33 cache controller, watchdog0 and watchdog1 */
#define SIM_SEC_SYSCTRL0_CM33_RST_REQ(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_CM33_RST_REQ_SHIFT)) & SIM_SEC_SYSCTRL0_CM33_RST_REQ_MASK)

#define SIM_SEC_SYSCTRL0_CM33_RST_ACK_MASK       (0x8U)
#define SIM_SEC_SYSCTRL0_CM33_RST_ACK_SHIFT      (3U)
/*! CM33_RST_ACK - CM33 Core is in safe state for reset sequencing */
#define SIM_SEC_SYSCTRL0_CM33_RST_ACK(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_CM33_RST_ACK_SHIFT)) & SIM_SEC_SYSCTRL0_CM33_RST_ACK_MASK)

#define SIM_SEC_SYSCTRL0_CAAM_RTIC_MODE_MASK     (0x10U)
#define SIM_SEC_SYSCTRL0_CAAM_RTIC_MODE_SHIFT    (4U)
/*! CAAM_RTIC_MODE - CAAM RTIC Run Time Mode Control */
#define SIM_SEC_SYSCTRL0_CAAM_RTIC_MODE(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_CAAM_RTIC_MODE_SHIFT)) & SIM_SEC_SYSCTRL0_CAAM_RTIC_MODE_MASK)

#define SIM_SEC_SYSCTRL0_M33_FPU_DISABLE_MASK    (0x20U)
#define SIM_SEC_SYSCTRL0_M33_FPU_DISABLE_SHIFT   (5U)
/*! M33_FPU_DISABLE - M33 FPU Disable */
#define SIM_SEC_SYSCTRL0_M33_FPU_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_M33_FPU_DISABLE_SHIFT)) & SIM_SEC_SYSCTRL0_M33_FPU_DISABLE_MASK)

#define SIM_SEC_SYSCTRL0_M33_DSP_DISABLE_MASK    (0x40U)
#define SIM_SEC_SYSCTRL0_M33_DSP_DISABLE_SHIFT   (6U)
/*! M33_DSP_DISABLE - M33 DSP Disable */
#define SIM_SEC_SYSCTRL0_M33_DSP_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_M33_DSP_DISABLE_SHIFT)) & SIM_SEC_SYSCTRL0_M33_DSP_DISABLE_MASK)

#define SIM_SEC_SYSCTRL0_LPAV_MASTER_CTRL_MASK   (0x80U)
#define SIM_SEC_SYSCTRL0_LPAV_MASTER_CTRL_SHIFT  (7U)
/*! LPAV_MASTER_CTRL - Low-Power Audio-Video Master Control */
#define SIM_SEC_SYSCTRL0_LPAV_MASTER_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_LPAV_MASTER_CTRL_SHIFT)) & SIM_SEC_SYSCTRL0_LPAV_MASTER_CTRL_MASK)

#define SIM_SEC_SYSCTRL0_NSSYSTICK_CLK_SEL_MASK  (0x100U)
#define SIM_SEC_SYSCTRL0_NSSYSTICK_CLK_SEL_SHIFT (8U)
/*! NSSYSTICK_CLK_SEL - Non-Secure Systick Clock Select */
#define SIM_SEC_SYSCTRL0_NSSYSTICK_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_NSSYSTICK_CLK_SEL_SHIFT)) & SIM_SEC_SYSCTRL0_NSSYSTICK_CLK_SEL_MASK)

#define SIM_SEC_SYSCTRL0_SSYSTICK_CLK_SEL_MASK   (0x200U)
#define SIM_SEC_SYSCTRL0_SSYSTICK_CLK_SEL_SHIFT  (9U)
/*! SSYSTICK_CLK_SEL - Secure Systick Clock Select */
#define SIM_SEC_SYSCTRL0_SSYSTICK_CLK_SEL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_SSYSTICK_CLK_SEL_SHIFT)) & SIM_SEC_SYSCTRL0_SSYSTICK_CLK_SEL_MASK)

#define SIM_SEC_SYSCTRL0_WDOG1_RESET_EN_MASK     (0x400U)
#define SIM_SEC_SYSCTRL0_WDOG1_RESET_EN_SHIFT    (10U)
/*! WDOG1_RESET_EN - Watchdog 1 reset enable */
#define SIM_SEC_SYSCTRL0_WDOG1_RESET_EN(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_WDOG1_RESET_EN_SHIFT)) & SIM_SEC_SYSCTRL0_WDOG1_RESET_EN_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_PLAT_HCLK_EN_MASK (0x800U)
#define SIM_SEC_SYSCTRL0_FUSION_PLAT_HCLK_EN_SHIFT (11U)
/*! FUSION_PLAT_HCLK_EN - fusion_plat_hclk Clock Enable */
#define SIM_SEC_SYSCTRL0_FUSION_PLAT_HCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_PLAT_HCLK_EN_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_PLAT_HCLK_EN_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_CLK_EN_MASK      (0x1000U)
#define SIM_SEC_SYSCTRL0_FUSION_CLK_EN_SHIFT     (12U)
/*! FUSION_CLK_EN - fusion_clk Clock Enable */
#define SIM_SEC_SYSCTRL0_FUSION_CLK_EN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_CLK_EN_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_CLK_EN_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_BCLK_EN_MASK     (0x2000U)
#define SIM_SEC_SYSCTRL0_FUSION_BCLK_EN_SHIFT    (13U)
/*! FUSION_BCLK_EN - fusion_bclk Clock Enable */
#define SIM_SEC_SYSCTRL0_FUSION_BCLK_EN(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_BCLK_EN_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_BCLK_EN_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_PBCLK_EN_MASK    (0x8000U)
#define SIM_SEC_SYSCTRL0_FUSION_PBCLK_EN_SHIFT   (15U)
/*! FUSION_PBCLK_EN - fusion_PBCLK Clock Enable */
#define SIM_SEC_SYSCTRL0_FUSION_PBCLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_PBCLK_EN_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_PBCLK_EN_MASK)

#define SIM_SEC_SYSCTRL0_CASPER_RST_MASK         (0x10000U)
#define SIM_SEC_SYSCTRL0_CASPER_RST_SHIFT        (16U)
/*! CASPER_RST - Controls the Casper Co-Processor Reset */
#define SIM_SEC_SYSCTRL0_CASPER_RST(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_CASPER_RST_SHIFT)) & SIM_SEC_SYSCTRL0_CASPER_RST_MASK)

#define SIM_SEC_SYSCTRL0_POWERQUAD_RST_MASK      (0x20000U)
#define SIM_SEC_SYSCTRL0_POWERQUAD_RST_SHIFT     (17U)
/*! POWERQUAD_RST - Controls the PowerQuad Co-Processor Reset */
#define SIM_SEC_SYSCTRL0_POWERQUAD_RST(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_POWERQUAD_RST_SHIFT)) & SIM_SEC_SYSCTRL0_POWERQUAD_RST_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_DSP_RST_MASK     (0x40000U)
#define SIM_SEC_SYSCTRL0_FUSION_DSP_RST_SHIFT    (18U)
/*! FUSION_DSP_RST - Controls the Fusion DSP Reset */
#define SIM_SEC_SYSCTRL0_FUSION_DSP_RST(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_DSP_RST_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_DSP_RST_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_MODE_MASK (0x100000U)
#define SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_MODE_SHIFT (20U)
/*! FUSION_DSP_DBG_MODE - Fusion DSP in OCD Halt or Other Debug Mode */
#define SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_MODE_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_MODE_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_RST_MASK (0x200000U)
#define SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_RST_SHIFT (21U)
/*! FUSION_DSP_DBG_RST - Reset Fusion DSP Debug logic */
#define SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_RST(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_RST_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_DSP_DBG_RST_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_DSP_OCD_HALT_MASK (0x400000U)
#define SIM_SEC_SYSCTRL0_FUSION_DSP_OCD_HALT_SHIFT (22U)
/*! FUSION_DSP_OCD_HALT - Fusion DSP in OCD Halt or Other Debug Mode */
#define SIM_SEC_SYSCTRL0_FUSION_DSP_OCD_HALT(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_DSP_OCD_HALT_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_DSP_OCD_HALT_MASK)

#define SIM_SEC_SYSCTRL0_FUSION_DSP_STALL_MASK   (0x800000U)
#define SIM_SEC_SYSCTRL0_FUSION_DSP_STALL_SHIFT  (23U)
/*! FUSION_DSP_STALL - Stall Fusion DSP Execution */
#define SIM_SEC_SYSCTRL0_FUSION_DSP_STALL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_FUSION_DSP_STALL_SHIFT)) & SIM_SEC_SYSCTRL0_FUSION_DSP_STALL_MASK)

#define SIM_SEC_SYSCTRL0_RGPIOA_TZ_DISABLE_MASK  (0x1000000U)
#define SIM_SEC_SYSCTRL0_RGPIOA_TZ_DISABLE_SHIFT (24U)
/*! RGPIOA_TZ_DISABLE - RGPIOA Trust Zone Disable */
#define SIM_SEC_SYSCTRL0_RGPIOA_TZ_DISABLE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_RGPIOA_TZ_DISABLE_SHIFT)) & SIM_SEC_SYSCTRL0_RGPIOA_TZ_DISABLE_MASK)

#define SIM_SEC_SYSCTRL0_RGPIOB_TZ_DISABLE_MASK  (0x2000000U)
#define SIM_SEC_SYSCTRL0_RGPIOB_TZ_DISABLE_SHIFT (25U)
/*! RGPIOB_TZ_DISABLE - RGPIOB Trust Zone Disable */
#define SIM_SEC_SYSCTRL0_RGPIOB_TZ_DISABLE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_RGPIOB_TZ_DISABLE_SHIFT)) & SIM_SEC_SYSCTRL0_RGPIOB_TZ_DISABLE_MASK)

#define SIM_SEC_SYSCTRL0_RGPIOC_TZ_DISABLE_MASK  (0x4000000U)
#define SIM_SEC_SYSCTRL0_RGPIOC_TZ_DISABLE_SHIFT (26U)
/*! RGPIOC_TZ_DISABLE - RGPIOC Trust Zone Disable */
#define SIM_SEC_SYSCTRL0_RGPIOC_TZ_DISABLE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL0_RGPIOC_TZ_DISABLE_SHIFT)) & SIM_SEC_SYSCTRL0_RGPIOC_TZ_DISABLE_MASK)
/*! @} */

/*! @name SSRAM_ACCESS_DISABLE - System Shared RAM Access Disable Register */
/*! @{ */

#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AHB_ACCESS_DISABLE_MASK (0xFFU)
#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AHB_ACCESS_DISABLE_SHIFT (0U)
/*! SSRAM_AHB_ACCESS_DISABLE - System Shared RAM AHB Access Disable */
#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AHB_ACCESS_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AHB_ACCESS_DISABLE_SHIFT)) & SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AHB_ACCESS_DISABLE_MASK)

#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AXI_ACCESS_DISABLE_MASK (0xFF00U)
#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AXI_ACCESS_DISABLE_SHIFT (8U)
/*! SSRAM_AXI_ACCESS_DISABLE - System Shared RAM AXI Access Disable */
#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AXI_ACCESS_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AXI_ACCESS_DISABLE_SHIFT)) & SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_AXI_ACCESS_DISABLE_MASK)

#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_DSP_ACCESS_DISABLE_MASK (0xFF0000U)
#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_DSP_ACCESS_DISABLE_SHIFT (16U)
/*! SSRAM_DSP_ACCESS_DISABLE - System Shared RAM DSP Access Disable */
#define SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_DSP_ACCESS_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_DSP_ACCESS_DISABLE_SHIFT)) & SIM_SEC_SSRAM_ACCESS_DISABLE_SSRAM_DSP_ACCESS_DISABLE_MASK)
/*! @} */

/*! @name LPAV_MASTER_ALLOC_CTRL - LPAV Master Allocation Control Register */
/*! @{ */

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_PXP_MASK  (0x1U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_PXP_SHIFT (0U)
/*! PXP - PXP */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_PXP(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_PXP_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_PXP_MASK)

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU2D_MASK (0x2U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU2D_SHIFT (1U)
/*! GPU2D - GPU2D */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU2D(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU2D_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU2D_MASK)

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU3D_MASK (0x4U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU3D_SHIFT (2U)
/*! GPU3D - GPU3D */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU3D(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU3D_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_GPU3D_MASK)

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_DCNANO_MASK (0x8U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_DCNANO_SHIFT (3U)
/*! DCNANO - DCNANO */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_DCNANO(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_DCNANO_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_DCNANO_MASK)

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_MIPI_DSI_MASK (0x10U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_MIPI_DSI_SHIFT (4U)
/*! MIPI_DSI - MIPI_DSI */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_MIPI_DSI(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_MIPI_DSI_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_MIPI_DSI_MASK)

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_EPDC_MASK (0x20U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_EPDC_SHIFT (5U)
/*! EPDC - EPDC */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_EPDC(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_EPDC_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_EPDC_MASK)

#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_HIFI4_MASK (0x40U)
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_HIFI4_SHIFT (6U)
/*! HIFI4 - HIFI4 */
#define SIM_SEC_LPAV_MASTER_ALLOC_CTRL_HIFI4(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_MASTER_ALLOC_CTRL_HIFI4_SHIFT)) & SIM_SEC_LPAV_MASTER_ALLOC_CTRL_HIFI4_MASK)
/*! @} */

/*! @name LPAV_SLAVE_ALLOC_CTRL - LPAV Slave Allocation Control Register */
/*! @{ */

#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI6_MASK  (0x1U)
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI6_SHIFT (0U)
/*! SAI6 - SAI6 */
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI6(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI6_SHIFT)) & SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI6_MASK)

#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI7_MASK  (0x2U)
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI7_SHIFT (1U)
/*! SAI7 - SAI7 */
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI7(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI7_SHIFT)) & SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SAI7_MASK)

#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SEMA42_MASK (0x4U)
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SEMA42_SHIFT (2U)
/*! SEMA42 - SEMA42 */
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SEMA42(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SEMA42_SHIFT)) & SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SEMA42_MASK)

#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_LPTPM8_MASK (0x8U)
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_LPTPM8_SHIFT (3U)
/*! LPTPM8 - LPTPM8 */
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_LPTPM8(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_LPTPM8_SHIFT)) & SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_LPTPM8_MASK)

#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SPDIF_MASK (0x10U)
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SPDIF_SHIFT (4U)
/*! SPDIF - SPDIF */
#define SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SPDIF(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SPDIF_SHIFT)) & SIM_SEC_LPAV_SLAVE_ALLOC_CTRL_SPDIF_MASK)
/*! @} */

/*! @name LPAV_DMA2_CH_ALLOC_CTRL - LPAV DMA2 CH Allocation Control Register */
/*! @{ */

#define SIM_SEC_LPAV_DMA2_CH_ALLOC_CTRL_LPAV_DMA2_CH_ALLOC_CTRL_MASK (0xFFFFFFFFU)
#define SIM_SEC_LPAV_DMA2_CH_ALLOC_CTRL_LPAV_DMA2_CH_ALLOC_CTRL_SHIFT (0U)
/*! LPAV_DMA2_CH_ALLOC_CTRL - LPAV DMA2 CH Allocation Control Register */
#define SIM_SEC_LPAV_DMA2_CH_ALLOC_CTRL_LPAV_DMA2_CH_ALLOC_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_CH_ALLOC_CTRL_LPAV_DMA2_CH_ALLOC_CTRL_SHIFT)) & SIM_SEC_LPAV_DMA2_CH_ALLOC_CTRL_LPAV_DMA2_CH_ALLOC_CTRL_MASK)
/*! @} */

/*! @name LPAV_DMA2_REQ_ALLOC_CTRL - LPAV DMA2 Request Allocation Control Register */
/*! @{ */

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPTPM8_MASK (0x1U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPTPM8_SHIFT (0U)
/*! LPTPM8 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPTPM8(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPTPM8_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPTPM8_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI0_MASK (0x2U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI0_SHIFT (1U)
/*! FLEXSPI0 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI0_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI0_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI1_MASK (0x4U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI1_SHIFT (2U)
/*! FLEXSPI1 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI1_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI1_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI2_MASK (0x8U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI2_SHIFT (3U)
/*! FLEXSPI2 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI2(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI2_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXSPI2_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO0_MASK (0x10U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO0_SHIFT (4U)
/*! FLEXIO0 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO0_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO0_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO1_MASK (0x20U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO1_SHIFT (5U)
/*! FLEXIO1 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO1_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_FLEXIO1_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C3_MASK (0x40U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C3_SHIFT (6U)
/*! LPI2C3 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C3_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C3_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C5_MASK (0x80U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C5_SHIFT (7U)
/*! LPI2C5 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C5_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPI2C5_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C1_MASK (0x100U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C1_SHIFT (8U)
/*! I3C1 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C1_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C1_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C2_MASK (0x200U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C2_SHIFT (9U)
/*! I3C2 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C2(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C2_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_I3C2_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI3_MASK (0x400U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI3_SHIFT (10U)
/*! LPSPI3 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI3_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI3_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI5_MASK (0x800U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI5_SHIFT (11U)
/*! LPSPI5 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI5_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPSPI5_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART3_MASK (0x1000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART3_SHIFT (12U)
/*! LPUART3 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART3(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART3_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART3_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART5_MASK (0x2000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART5_SHIFT (13U)
/*! LPUART5 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART5(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART5_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_LPUART5_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI0_MASK (0x4000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI0_SHIFT (14U)
/*! SAI0 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI0_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI0_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI1_MASK (0x8000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI1_SHIFT (15U)
/*! SAI1 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI1_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI1_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI4_MASK (0x10000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI4_SHIFT (16U)
/*! SAI4 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI4(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI4_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI4_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI5_MASK (0x20000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI5_SHIFT (17U)
/*! SAI5 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI5(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI5_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI5_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI6_MASK (0x40000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI6_SHIFT (18U)
/*! SAI6 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI6(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI6_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI6_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI7_MASK (0x80000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI7_SHIFT (19U)
/*! SAI7 - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI7(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI7_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SAI7_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SPDIF_MASK (0x100000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SPDIF_SHIFT (20U)
/*! SPDIF - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SPDIF(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SPDIF_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_SPDIF_MASK)

#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_GPIOD_MASK (0x200000U)
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_GPIOD_SHIFT (21U)
/*! GPIOD - DMA2 Request Allocation */
#define SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_GPIOD(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_GPIOD_SHIFT)) & SIM_SEC_LPAV_DMA2_REQ_ALLOC_CTRL_GPIOD_MASK)
/*! @} */

/*! @name M33_CFGSSTCALIB - Secure SysTick Calibration Configuration */
/*! @{ */

#define SIM_SEC_M33_CFGSSTCALIB_CFGSSTCALIB_MASK (0x3FFFFFFU)
#define SIM_SEC_M33_CFGSSTCALIB_CFGSSTCALIB_SHIFT (0U)
/*! CFGSSTCALIB - Secure SysTick calibration configuration */
#define SIM_SEC_M33_CFGSSTCALIB_CFGSSTCALIB(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_M33_CFGSSTCALIB_CFGSSTCALIB_SHIFT)) & SIM_SEC_M33_CFGSSTCALIB_CFGSSTCALIB_MASK)
/*! @} */

/*! @name FUSION_GPR0 - Fusion DSP General Purpose Register */
/*! @{ */

#define SIM_SEC_FUSION_GPR0_VECTOR_REMAP_MASK    (0x1FFFU)
#define SIM_SEC_FUSION_GPR0_VECTOR_REMAP_SHIFT   (0U)
/*! VECTOR_REMAP - Fusion Vector Remap Register
 *  0b0000000000000..For bit [11:0]: The reset vector address is 0
 *  0b0000000000001..For bit [12]: Reserved
 */
#define SIM_SEC_FUSION_GPR0_VECTOR_REMAP(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_FUSION_GPR0_VECTOR_REMAP_SHIFT)) & SIM_SEC_FUSION_GPR0_VECTOR_REMAP_MASK)

#define SIM_SEC_FUSION_GPR0_DOUBLEEXCEPTIONERROR_MASK (0x10000U)
#define SIM_SEC_FUSION_GPR0_DOUBLEEXCEPTIONERROR_SHIFT (16U)
/*! DOUBLEEXCEPTIONERROR - Double Exception Error */
#define SIM_SEC_FUSION_GPR0_DOUBLEEXCEPTIONERROR(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_FUSION_GPR0_DOUBLEEXCEPTIONERROR_SHIFT)) & SIM_SEC_FUSION_GPR0_DOUBLEEXCEPTIONERROR_MASK)

#define SIM_SEC_FUSION_GPR0_PFATALERROR_MASK     (0x20000U)
#define SIM_SEC_FUSION_GPR0_PFATALERROR_SHIFT    (17U)
/*! PFATALERROR - Fatal Error */
#define SIM_SEC_FUSION_GPR0_PFATALERROR(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SEC_FUSION_GPR0_PFATALERROR_SHIFT)) & SIM_SEC_FUSION_GPR0_PFATALERROR_MASK)

#define SIM_SEC_FUSION_GPR0_PFAULTINFOVALID_MASK (0x40000U)
#define SIM_SEC_FUSION_GPR0_PFAULTINFOVALID_SHIFT (18U)
/*! PFAULTINFOVALID - Fault Info Valid */
#define SIM_SEC_FUSION_GPR0_PFAULTINFOVALID(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_FUSION_GPR0_PFAULTINFOVALID_SHIFT)) & SIM_SEC_FUSION_GPR0_PFAULTINFOVALID_MASK)
/*! @} */

/*! @name FUSION_GPR1 - Fusion DSP General Purpose Register */
/*! @{ */

#define SIM_SEC_FUSION_GPR1_PFAULTINFO_MASK      (0xFFFFFFFFU)
#define SIM_SEC_FUSION_GPR1_PFAULTINFO_SHIFT     (0U)
/*! PFAULTINFO - Fault information Register */
#define SIM_SEC_FUSION_GPR1_PFAULTINFO(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_FUSION_GPR1_PFAULTINFO_SHIFT)) & SIM_SEC_FUSION_GPR1_PFAULTINFO_MASK)
/*! @} */

/*! @name FUSION_GPR2 - Fusion DSP General Purpose Register */
/*! @{ */

#define SIM_SEC_FUSION_GPR2_TIE_EXPSTATE_MASK    (0xFFFFFFFFU)
#define SIM_SEC_FUSION_GPR2_TIE_EXPSTATE_SHIFT   (0U)
/*! TIE_EXPSTATE - GPIO32 option TIE output state */
#define SIM_SEC_FUSION_GPR2_TIE_EXPSTATE(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_FUSION_GPR2_TIE_EXPSTATE_SHIFT)) & SIM_SEC_FUSION_GPR2_TIE_EXPSTATE_MASK)
/*! @} */

/*! @name RTD_INTERRUPT_MASK0 - Realtime Domain Interrupt Mask 0 */
/*! @{ */

#define SIM_SEC_RTD_INTERRUPT_MASK0_EWM_MASK     (0x1U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_EWM_SHIFT    (0U)
/*! EWM - EWM Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_EWM(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_EWM_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_EWM_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_DMA0_MASK    (0x1FEU)
#define SIM_SEC_RTD_INTERRUPT_MASK0_DMA0_SHIFT   (1U)
/*! DMA0 - DMA0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_DMA0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_DMA0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_DMA0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_WUU0_MASK    (0x200U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_WUU0_SHIFT   (9U)
/*! WUU0 - WUU0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_WUU0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_WUU0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_WUU0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_WDOG0_MASK   (0x400U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_WDOG0_SHIFT  (10U)
/*! WDOG0 - WDOG0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_WDOG0(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_WDOG0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_WDOG0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_WDOG1_MASK   (0x800U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_WDOG1_SHIFT  (11U)
/*! WDOG1 - WDOG1 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_WDOG1(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_WDOG1_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_WDOG1_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_POWERSYS_MASK (0x1000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_POWERSYS_SHIFT (12U)
/*! POWERSYS - POWERSYS Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_POWERSYS(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_POWERSYS_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_POWERSYS_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_CMC0_MASK    (0x2000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_CMC0_SHIFT   (13U)
/*! CMC0 - CMC0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_CMC0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_CMC0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_CMC0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_CGC0_MASK    (0x4000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_CGC0_SHIFT   (14U)
/*! CGC0 - CGC0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_CGC0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_CGC0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_CGC0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXIO0_MASK (0x8000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXIO0_SHIFT (15U)
/*! FLEXIO0 - FlexIO0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXIO0(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_FLEXIO0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_FLEXIO0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI0_MASK (0x10000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI0_SHIFT (16U)
/*! FLEXSPI0 - FlexSPI0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI0(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI1_MASK (0x20000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI1_SHIFT (17U)
/*! FLEXSPI1 - FlexSPI1 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI1(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI1_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_FLEXSPI1_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_CMP0_MASK    (0x40000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_CMP0_SHIFT   (18U)
/*! CMP0 - CMP0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_CMP0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_CMP0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_CMP0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_CMP1_MASK    (0x80000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_CMP1_SHIFT   (19U)
/*! CMP1 - CMP1 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_CMP1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_CMP1_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_CMP1_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR0_MASK  (0x100000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR0_SHIFT (20U)
/*! LPTMR0 - LPTMR0 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR0(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR0_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR0_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR1_MASK  (0x200000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR1_SHIFT (21U)
/*! LPTMR1 - LPTMR1 Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR1(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR1_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_LPTMR1_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_TRDC_MASK    (0x400000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_TRDC_SHIFT   (22U)
/*! TRDC - TRDC Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_TRDC(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_TRDC_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_TRDC_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_BBNSM_MASK   (0x800000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_BBNSM_SHIFT  (23U)
/*! BBNSM - BBNSM Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_BBNSM(x)     (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_BBNSM_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_BBNSM_MASK)

#define SIM_SEC_RTD_INTERRUPT_MASK0_SE_MASK      (0x7000000U)
#define SIM_SEC_RTD_INTERRUPT_MASK0_SE_SHIFT     (24U)
/*! SE - Secure Enclave Interrupt Mask */
#define SIM_SEC_RTD_INTERRUPT_MASK0_SE(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_RTD_INTERRUPT_MASK0_SE_SHIFT)) & SIM_SEC_RTD_INTERRUPT_MASK0_SE_MASK)
/*! @} */

/*! @name APD_INTERRUPT_MASK0 - Application Domain Interrupt Mask 0 */
/*! @{ */

#define SIM_SEC_APD_INTERRUPT_MASK0_DMA1_MASK    (0xFFU)
#define SIM_SEC_APD_INTERRUPT_MASK0_DMA1_SHIFT   (0U)
/*! DMA1 - DMA1 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_DMA1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_DMA1_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_DMA1_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_FLEXIO1_MASK (0x100U)
#define SIM_SEC_APD_INTERRUPT_MASK0_FLEXIO1_SHIFT (8U)
/*! FLEXIO1 - FlexIO1 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_FLEXIO1(x)   (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_FLEXIO1_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_FLEXIO1_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC0_MASK  (0x200U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC0_SHIFT (9U)
/*! USDHC0 - uSDHC0 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC0(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USDHC0_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USDHC0_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC1_MASK  (0x400U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC1_SHIFT (10U)
/*! USDHC1 - uSDHC1 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC1(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USDHC1_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USDHC1_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC2_MASK  (0x800U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC2_SHIFT (11U)
/*! USDHC2 - uSDHC2 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USDHC2(x)    (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USDHC2_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USDHC2_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_FLEXSPI2_MASK (0x1000U)
#define SIM_SEC_APD_INTERRUPT_MASK0_FLEXSPI2_SHIFT (12U)
/*! FLEXSPI2 - FlexSPI2 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_FLEXSPI2(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_FLEXSPI2_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_FLEXSPI2_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_XRDC_MASK    (0x2000U)
#define SIM_SEC_APD_INTERRUPT_MASK0_XRDC_SHIFT   (13U)
/*! XRDC - XRDC Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_XRDC(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_XRDC_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_XRDC_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY0_MASK (0x4000U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY0_SHIFT (14U)
/*! USB_PHY0 - USB PHY0 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY0(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY0_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY0_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY1_MASK (0x8000U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY1_SHIFT (15U)
/*! USB_PHY1 - USB PHY1 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY1(x)  (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY1_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USB_PHY1_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USB0_MASK    (0x10000U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USB0_SHIFT   (16U)
/*! USB0 - USB0 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USB0(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USB0_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USB0_MASK)

#define SIM_SEC_APD_INTERRUPT_MASK0_USB1_MASK    (0x20000U)
#define SIM_SEC_APD_INTERRUPT_MASK0_USB1_SHIFT   (17U)
/*! USB1 - USB1 Interrupt Mask */
#define SIM_SEC_APD_INTERRUPT_MASK0_USB1(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_APD_INTERRUPT_MASK0_USB1_SHIFT)) & SIM_SEC_APD_INTERRUPT_MASK0_USB1_MASK)
/*! @} */

/*! @name AVD_INTERRUPT_MASK0 - Audio-Video Domain Interrupt Mask 0 */
/*! @{ */

#define SIM_SEC_AVD_INTERRUPT_MASK0_MDDR_MASK    (0x1U)
#define SIM_SEC_AVD_INTERRUPT_MASK0_MDDR_SHIFT   (0U)
/*! MDDR - MDDR Interrupt Mask */
#define SIM_SEC_AVD_INTERRUPT_MASK0_MDDR(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SEC_AVD_INTERRUPT_MASK0_MDDR_SHIFT)) & SIM_SEC_AVD_INTERRUPT_MASK0_MDDR_MASK)
/*! @} */

/*! @name WRITE_ASSIST_CTRL - RTD Memories Write-Assist Control */
/*! @{ */

#define SIM_SEC_WRITE_ASSIST_CTRL_WR_ASSIST_EN_B_MASK (0x3U)
#define SIM_SEC_WRITE_ASSIST_CTRL_WR_ASSIST_EN_B_SHIFT (0U)
/*! WR_ASSIST_EN_B - Write-Assist Enable */
#define SIM_SEC_WRITE_ASSIST_CTRL_WR_ASSIST_EN_B(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_WRITE_ASSIST_CTRL_WR_ASSIST_EN_B_SHIFT)) & SIM_SEC_WRITE_ASSIST_CTRL_WR_ASSIST_EN_B_MASK)

#define SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_BELOW_B_MASK (0x4U)
#define SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_BELOW_B_SHIFT (2U)
/*! WRAST_MUX_SEL_BELOW_B - Write-Assist Mux Select - Memories with Row x Block below threshold */
#define SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_BELOW_B(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_BELOW_B_SHIFT)) & SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_BELOW_B_MASK)

#define SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_ABOVE_B_MASK (0x8U)
#define SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_ABOVE_B_SHIFT (3U)
/*! WRAST_MUX_SEL_ABOVE_B - Write-Assist Mux Select - Memories with Row x Block below threshold */
#define SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_ABOVE_B(x) (((uint32_t)(((uint32_t)(x)) << SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_ABOVE_B_SHIFT)) & SIM_SEC_WRITE_ASSIST_CTRL_WRAST_MUX_SEL_ABOVE_B_MASK)
/*! @} */

/*! @name SYSCTRL1 - Realtime Domains System Control Register 1 */
/*! @{ */

#define SIM_SEC_SYSCTRL1_AA64NAA32_MASK          (0x3U)
#define SIM_SEC_SYSCTRL1_AA64NAA32_SHIFT         (0U)
/*! AA64NAA32 - Architecture Mode Select Bits */
#define SIM_SEC_SYSCTRL1_AA64NAA32(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL1_AA64NAA32_SHIFT)) & SIM_SEC_SYSCTRL1_AA64NAA32_MASK)
/*! @} */

/*! @name SYSCTRL2 - Realtime Domains System Control Register 2 */
/*! @{ */

#define SIM_SEC_SYSCTRL2_TZM_CONTROL_MASK        (0x1U)
#define SIM_SEC_SYSCTRL2_TZM_CONTROL_SHIFT       (0U)
/*! TZM_CONTROL - CM33 Trust Zone Mode Control Bit */
#define SIM_SEC_SYSCTRL2_TZM_CONTROL(x)          (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL2_TZM_CONTROL_SHIFT)) & SIM_SEC_SYSCTRL2_TZM_CONTROL_MASK)
/*! @} */

/*! @name SYSCTRL3 - Realtime Domains System Control Register 3 */
/*! @{ */

#define SIM_SEC_SYSCTRL3_CP15SDISABLE2_MASK      (0x3U)
#define SIM_SEC_SYSCTRL3_CP15SDISABLE2_SHIFT     (0U)
/*! CP15SDISABLE2 - Disable write access to some Secure CP15 registers */
#define SIM_SEC_SYSCTRL3_CP15SDISABLE2(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL3_CP15SDISABLE2_SHIFT)) & SIM_SEC_SYSCTRL3_CP15SDISABLE2_MASK)
/*! @} */

/*! @name SYSCTRL4 - Realtime Domains System Control Register 4 */
/*! @{ */

#define SIM_SEC_SYSCTRL4_LMDA_RESET_EN_MASK      (0x1U)
#define SIM_SEC_SYSCTRL4_LMDA_RESET_EN_SHIFT     (0U)
/*! LMDA_RESET_EN - Enables LMDA reset source */
#define SIM_SEC_SYSCTRL4_LMDA_RESET_EN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_SEC_SYSCTRL4_LMDA_RESET_EN_SHIFT)) & SIM_SEC_SYSCTRL4_LMDA_RESET_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_SEC_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_SEC_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_SEC_H_ */

