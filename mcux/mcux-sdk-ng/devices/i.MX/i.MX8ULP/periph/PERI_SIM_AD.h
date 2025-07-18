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
**         CMSIS Peripheral Access Layer for SIM_AD
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
 * @file PERI_SIM_AD.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM_AD
 *
 * CMSIS Peripheral Access Layer for SIM_AD
 */

#if !defined(PERI_SIM_AD_H_)
#define PERI_SIM_AD_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SIM_AD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_AD_Peripheral_Access_Layer SIM_AD Peripheral Access Layer
 * @{
 */

/** SIM_AD - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t DGO_CTRL0;                         /**< APD SIM DGO Control Register 0, offset: 0x8 */
  __IO uint32_t DGO_CTRL1;                         /**< APD SIM DGO Control Register 1, offset: 0xC */
  __IO uint32_t DGO_GP0;                           /**< APD SIM DGO General Purpose Register 0, offset: 0x10 */
  __IO uint32_t DGO_GP1;                           /**< APD SIM DGO General Purpose Register 1, offset: 0x14 */
  __IO uint32_t DGO_GP2;                           /**< APD SIM DGO General Purpose Register 2, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DGO_GP3;                           /**< RESET1_B pad and Filter Configuration, offset: 0x20 */
  __IO uint32_t DGO_GP4;                           /**< PTE Operating Range Control, offset: 0x24 */
  __IO uint32_t DGO_GP5;                           /**< PTF Operating Range Control, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SYSCTRL0;                          /**< Application Domain System Control Register 0, offset: 0x30 */
       uint8_t RESERVED_3[8];
  __IO uint32_t WKPU0_WAKEUP_EN;                   /**< WKPU0 Wake-up Enable Register, offset: 0x3C */
  __IO uint32_t WKPU1_WAKEUP_EN;                   /**< WKPU1 Wake-up Enable Register 1, offset: 0x40 */
  __IO uint32_t USB_WAKEUP;                        /**< USB Wake-up Control Register (DGO 10), offset: 0x44 */
  __IO uint32_t PTD_COMPCELL;                      /**< PTD Pads Compensation Cell Configuration Register, offset: 0x48 */
  __IO uint32_t TSTMR_CMP0_VAL_L;                  /**< Lower CA35 TS Timer First Compare Value, offset: 0x4C */
  __IO uint32_t TSTMR_CMP0_VAL_H;                  /**< Upper CA35 TS Timer First Compare Value, offset: 0x50 */
  __IO uint32_t TSTMR_CMP1_VAL_L;                  /**< Lower CA35 TS Timer Second Compare value, offset: 0x54 */
  __IO uint32_t TSTMR_CMP1_VAL_H;                  /**< Upper CA35 TS Timer Second Compare Value, offset: 0x58 */
  __IO uint32_t RVBARADDR0;                        /**< CA35 Core0 Reset Vector Base Address (DGO 8), offset: 0x5C */
  __IO uint32_t RVBARADDR1;                        /**< CA35 Core1 Reset Vector Base Address (DGO 9), offset: 0x60 */
  __IO uint32_t MQS1_CF;                           /**< Medium Quality Sound Configuration Register, offset: 0x64 */
  __IO uint32_t SAI_MULTISYNC_ENABLE_SELECTOR;     /**< SAI 4 and 5 Transmitter/Receiver Multi-Synchronous Enable Source, offset: 0x68 */
  __I  uint32_t CORE0_PMU_EVENT;                   /**< A35 Core0 Performance Monitoring Events, offset: 0x6C */
  __I  uint32_t CORE1_PMU_EVENT;                   /**< A35 Core1 Performance Monitoring Events, offset: 0x70 */
  __IO uint32_t DGO_GP6;                           /**< APD SIM DGO General Purpose Register 6, offset: 0x74 */
  __IO uint32_t DGO_GP7;                           /**< APD SIM DGO General Purpose Register 7, offset: 0x78 */
} SIM_AD_Type;

/* ----------------------------------------------------------------------------
   -- SIM_AD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_AD_Register_Masks SIM_AD Register Masks
 * @{
 */

/*! @name DGO_CTRL0 - APD SIM DGO Control Register 0 */
/*! @{ */

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP0_MASK     (0x1U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP0_SHIFT    (0U)
/*! UPDATE_DGO_GP0 - DGO General Purpose Register 0 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP0(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP0_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP0_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP1_MASK     (0x2U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP1_SHIFT    (1U)
/*! UPDATE_DGO_GP1 - DGO General Purpose Register 1 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP1(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP1_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP1_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP2_MASK     (0x4U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP2_SHIFT    (2U)
/*! UPDATE_DGO_GP2 - DGO General Purpose Register 2 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP2(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP2_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP2_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP3_MASK     (0x8U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP3_SHIFT    (3U)
/*! UPDATE_DGO_GP3 - DGO General Purpose Register 3 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP3(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP3_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP3_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP4_MASK     (0x10U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP4_SHIFT    (4U)
/*! UPDATE_DGO_GP4 - DGO General Purpose Register 4 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP4(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP4_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP4_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP5_MASK     (0x20U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP5_SHIFT    (5U)
/*! UPDATE_DGO_GP5 - DGO General Purpose Register 5 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP5(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP5_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP5_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP6_MASK     (0x40U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP6_SHIFT    (6U)
/*! UPDATE_DGO_GP6 - DGO General Purpose Register 6 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP6(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP6_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP6_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP7_MASK     (0x80U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP7_SHIFT    (7U)
/*! UPDATE_DGO_GP7 - DGO General Purpose Register 7 Update */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP7(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP7_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP7_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP0_MASK     (0x100U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP0_SHIFT    (8U)
/*! WR_ACK_DGO_GP0 - DGO General Purpose Register 0 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP0(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP0_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP0_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP1_MASK     (0x200U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP1_SHIFT    (9U)
/*! WR_ACK_DGO_GP1 - DGO General Purpose Register 1 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP1(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP1_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP1_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP2_MASK     (0x400U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP2_SHIFT    (10U)
/*! WR_ACK_DGO_GP2 - DGO General Purpose Register 2 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP2(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP2_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP2_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP3_MASK     (0x800U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP3_SHIFT    (11U)
/*! WR_ACK_DGO_GP3 - DGO General Purpose Register 3 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP3(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP3_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP3_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP4_MASK     (0x1000U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP4_SHIFT    (12U)
/*! WR_ACK_DGO_GP4 - DGO General Purpose Register 2 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP4(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP4_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP4_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP5_MASK     (0x2000U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP5_SHIFT    (13U)
/*! WR_ACK_DGO_GP5 - DGO General Purpose Register 5 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP5(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP5_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP5_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP6_MASK     (0x4000U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP6_SHIFT    (14U)
/*! WR_ACK_DGO_GP6 - DGO General Purpose Register 6 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP6(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP6_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP6_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP7_MASK     (0x8000U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP7_SHIFT    (15U)
/*! WR_ACK_DGO_GP7 - DGO General Purpose Register 7 Write Acknowledge */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP7(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP7_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP7_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK0_MASK        (0x10000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK0_SHIFT       (16U)
/*! INT_EN_ACK0 - DGO General Purpose Register 0 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK0(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK0_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK0_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK1_MASK        (0x20000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK1_SHIFT       (17U)
/*! INT_EN_ACK1 - DGO General Purpose Register 1 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK1(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK1_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK1_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK2_MASK        (0x40000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK2_SHIFT       (18U)
/*! INT_EN_ACK2 - DGO General Purpose Register 2 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK2(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK2_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK2_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK3_MASK        (0x80000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK3_SHIFT       (19U)
/*! INT_EN_ACK3 - DGO General Purpose Register 3 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK3(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK3_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK3_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK4_MASK        (0x100000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK4_SHIFT       (20U)
/*! INT_EN_ACK4 - DGO General Purpose Register 4 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK4(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK4_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK4_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK5_MASK        (0x200000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK5_SHIFT       (21U)
/*! INT_EN_ACK5 - DGO General Purpose Register 5 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK5(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK5_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK5_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK6_MASK        (0x400000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK6_SHIFT       (22U)
/*! INT_EN_ACK6 - DGO General Purpose Register 6 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK6(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK6_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK6_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK7_MASK        (0x800000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK7_SHIFT       (23U)
/*! INT_EN_ACK7 - DGO General Purpose Register 7 Interrupt Acknowledge */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK7(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK7_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK7_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP8_MASK     (0x1000000U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP8_SHIFT    (24U)
/*! UPDATE_DGO_GP8 - DGO General Purpose Register 8 Update (RVBARADDR0) */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP8(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP8_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP8_MASK)

#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP9_MASK     (0x2000000U)
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP9_SHIFT    (25U)
/*! UPDATE_DGO_GP9 - DGO General Purpose Register 9 Update (RVBARADDR1) */
#define SIM_AD_DGO_CTRL0_UPDATE_DGO_GP9(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_UPDATE_DGO_GP9_SHIFT)) & SIM_AD_DGO_CTRL0_UPDATE_DGO_GP9_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP8_MASK     (0x4000000U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP8_SHIFT    (26U)
/*! WR_ACK_DGO_GP8 - DGO General Purpose Register 8 Write Acknowledge (RVBARADDR0) */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP8(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP8_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP8_MASK)

#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP9_MASK     (0x8000000U)
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP9_SHIFT    (27U)
/*! WR_ACK_DGO_GP9 - DGO General Purpose Register 9 Write Acknowledge (RVBARADDR1) */
#define SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP9(x)       (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP9_SHIFT)) & SIM_AD_DGO_CTRL0_WR_ACK_DGO_GP9_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK8_MASK        (0x10000000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK8_SHIFT       (28U)
/*! INT_EN_ACK8 - DGO General Purpose Register 8 Interrupt Acknowledge (RVBARADDR0) */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK8(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK8_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK8_MASK)

#define SIM_AD_DGO_CTRL0_INT_EN_ACK9_MASK        (0x20000000U)
#define SIM_AD_DGO_CTRL0_INT_EN_ACK9_SHIFT       (29U)
/*! INT_EN_ACK9 - DGO General Purpose Register 9 Interrupt Acknowledge (RVBARADDR1) */
#define SIM_AD_DGO_CTRL0_INT_EN_ACK9(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL0_INT_EN_ACK9_SHIFT)) & SIM_AD_DGO_CTRL0_INT_EN_ACK9_MASK)
/*! @} */

/*! @name DGO_CTRL1 - APD SIM DGO Control Register 1 */
/*! @{ */

#define SIM_AD_DGO_CTRL1_UPDATE_DGO_GP10_MASK    (0x1U)
#define SIM_AD_DGO_CTRL1_UPDATE_DGO_GP10_SHIFT   (0U)
/*! UPDATE_DGO_GP10 - DGO General Purpose Register 10 Update (USB_WAKEUP) */
#define SIM_AD_DGO_CTRL1_UPDATE_DGO_GP10(x)      (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL1_UPDATE_DGO_GP10_SHIFT)) & SIM_AD_DGO_CTRL1_UPDATE_DGO_GP10_MASK)

#define SIM_AD_DGO_CTRL1_WR_ACK_DGO_GP10_MASK    (0x2U)
#define SIM_AD_DGO_CTRL1_WR_ACK_DGO_GP10_SHIFT   (1U)
/*! WR_ACK_DGO_GP10 - DGO General Purpose Register 10 Write Acknowledge (USB_WAKEUP) */
#define SIM_AD_DGO_CTRL1_WR_ACK_DGO_GP10(x)      (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL1_WR_ACK_DGO_GP10_SHIFT)) & SIM_AD_DGO_CTRL1_WR_ACK_DGO_GP10_MASK)

#define SIM_AD_DGO_CTRL1_INT_EN_ACK10_MASK       (0x4U)
#define SIM_AD_DGO_CTRL1_INT_EN_ACK10_SHIFT      (2U)
/*! INT_EN_ACK10 - DGO General Purpose Register 10 Interrupt Acknowledge (USB_WAKEUP) */
#define SIM_AD_DGO_CTRL1_INT_EN_ACK10(x)         (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_CTRL1_INT_EN_ACK10_SHIFT)) & SIM_AD_DGO_CTRL1_INT_EN_ACK10_MASK)
/*! @} */

/*! @name DGO_GP0 - APD SIM DGO General Purpose Register 0 */
/*! @{ */

#define SIM_AD_DGO_GP0_SIM_DGO_GP0_MASK          (0xFFFFFFFFU)
#define SIM_AD_DGO_GP0_SIM_DGO_GP0_SHIFT         (0U)
/*! SIM_DGO_GP0 - SIM DGO General purpose register 0 */
#define SIM_AD_DGO_GP0_SIM_DGO_GP0(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP0_SIM_DGO_GP0_SHIFT)) & SIM_AD_DGO_GP0_SIM_DGO_GP0_MASK)
/*! @} */

/*! @name DGO_GP1 - APD SIM DGO General Purpose Register 1 */
/*! @{ */

#define SIM_AD_DGO_GP1_SIM_DGO_GP1_MASK          (0xFFFFFFFFU)
#define SIM_AD_DGO_GP1_SIM_DGO_GP1_SHIFT         (0U)
/*! SIM_DGO_GP1 - SIM DGO General Purpose Register 1 */
#define SIM_AD_DGO_GP1_SIM_DGO_GP1(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP1_SIM_DGO_GP1_SHIFT)) & SIM_AD_DGO_GP1_SIM_DGO_GP1_MASK)
/*! @} */

/*! @name DGO_GP2 - APD SIM DGO General Purpose Register 2 */
/*! @{ */

#define SIM_AD_DGO_GP2_SIM_DGO_GP2_MASK          (0xFFFFFFFFU)
#define SIM_AD_DGO_GP2_SIM_DGO_GP2_SHIFT         (0U)
/*! SIM_DGO_GP2 - SIM DGO General Purpose Register 2 */
#define SIM_AD_DGO_GP2_SIM_DGO_GP2(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP2_SIM_DGO_GP2_SHIFT)) & SIM_AD_DGO_GP2_SIM_DGO_GP2_MASK)
/*! @} */

/*! @name DGO_GP3 - RESET1_B pad and Filter Configuration */
/*! @{ */

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PS_MASK   (0x1U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PS_SHIFT  (0U)
/*! RESET1_B_CONFIG_PS - Weak Pull Select */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PS(x)     (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_PS_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_PS_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PE_MASK   (0x2U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PE_SHIFT  (1U)
/*! RESET1_B_CONFIG_PE - Weak Pull Enable */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PE(x)     (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_PE_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_PE_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_SRE_MASK  (0x4U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_SRE_SHIFT (2U)
/*! RESET1_B_CONFIG_SRE - Slew Rate Enable */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_SRE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_SRE_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_SRE_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PFE_MASK  (0x10U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PFE_SHIFT (4U)
/*! RESET1_B_CONFIG_PFE - Passive Filter Enable */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_PFE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_PFE_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_PFE_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_ODE_MASK  (0x20U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_ODE_SHIFT (5U)
/*! RESET1_B_CONFIG_ODE - Open Drain Enable */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_ODE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_ODE_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_ODE_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DSE_MASK  (0x40U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DSE_SHIFT (6U)
/*! RESET1_B_CONFIG_DSE - Drive Strength Enable */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DSE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_DSE_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_DSE_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_LK_MASK   (0x8000U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_LK_SHIFT  (15U)
/*! RESET1_B_CONFIG_LK - Locks Writes to This Register */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_LK(x)     (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_LK_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_LK_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFE_MASK  (0x100000U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFE_SHIFT (20U)
/*! RESET1_B_CONFIG_DFE - Digital Filter Enable */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFE_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFE_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFCS_MASK (0x200000U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFCS_SHIFT (21U)
/*! RESET1_B_CONFIG_DFCS - Digital Filter Clock Select */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFCS(x)   (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFCS_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFCS_MASK)

#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFD_MASK  (0xFC00000U)
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFD_SHIFT (22U)
/*! RESET1_B_CONFIG_DFD - Digital Filter Duration by Defining Deglitch Count */
#define SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFD(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFD_SHIFT)) & SIM_AD_DGO_GP3_RESET1_B_CONFIG_DFD_MASK)
/*! @} */

/*! @name DGO_GP4 - PTE Operating Range Control */
/*! @{ */

#define SIM_AD_DGO_GP4_PTE_OPERATING_RANGE_MASK  (0x3U)
#define SIM_AD_DGO_GP4_PTE_OPERATING_RANGE_SHIFT (0U)
/*! PTE_OPERATING_RANGE - PTE Operating Range (Write Once) */
#define SIM_AD_DGO_GP4_PTE_OPERATING_RANGE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP4_PTE_OPERATING_RANGE_SHIFT)) & SIM_AD_DGO_GP4_PTE_OPERATING_RANGE_MASK)
/*! @} */

/*! @name DGO_GP5 - PTF Operating Range Control */
/*! @{ */

#define SIM_AD_DGO_GP5_PTF_OPERATING_RANGE_MASK  (0x3U)
#define SIM_AD_DGO_GP5_PTF_OPERATING_RANGE_SHIFT (0U)
/*! PTF_OPERATING_RANGE - PTF Operating Range (Write Once) */
#define SIM_AD_DGO_GP5_PTF_OPERATING_RANGE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP5_PTF_OPERATING_RANGE_SHIFT)) & SIM_AD_DGO_GP5_PTF_OPERATING_RANGE_MASK)
/*! @} */

/*! @name SYSCTRL0 - Application Domain System Control Register 0 */
/*! @{ */

#define SIM_AD_SYSCTRL0_L2_CACHE_CONTROL_MASK    (0x10U)
#define SIM_AD_SYSCTRL0_L2_CACHE_CONTROL_SHIFT   (4U)
/*! L2_CACHE_CONTROL - L2 Cache Control */
#define SIM_AD_SYSCTRL0_L2_CACHE_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_L2_CACHE_CONTROL_SHIFT)) & SIM_AD_SYSCTRL0_L2_CACHE_CONTROL_MASK)

#define SIM_AD_SYSCTRL0_L2_CACHE_RST_DISABLE_MASK (0x20U)
#define SIM_AD_SYSCTRL0_L2_CACHE_RST_DISABLE_SHIFT (5U)
/*! L2_CACHE_RST_DISABLE - L2 Cache Reset Disable */
#define SIM_AD_SYSCTRL0_L2_CACHE_RST_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_L2_CACHE_RST_DISABLE_SHIFT)) & SIM_AD_SYSCTRL0_L2_CACHE_RST_DISABLE_MASK)

#define SIM_AD_SYSCTRL0_A35_SMPEN_MASK           (0xC0U)
#define SIM_AD_SYSCTRL0_A35_SMPEN_SHIFT          (6U)
/*! A35_SMPEN - Status Register to Indicate Whether a Core is Taking Part in Coherency. */
#define SIM_AD_SYSCTRL0_A35_SMPEN(x)             (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_A35_SMPEN_SHIFT)) & SIM_AD_SYSCTRL0_A35_SMPEN_MASK)

#define SIM_AD_SYSCTRL0_WDOG4_RESET_EN_MASK      (0x100U)
#define SIM_AD_SYSCTRL0_WDOG4_RESET_EN_SHIFT     (8U)
/*! WDOG4_RESET_EN - Watchdog 4 Reset Enable */
#define SIM_AD_SYSCTRL0_WDOG4_RESET_EN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_WDOG4_RESET_EN_SHIFT)) & SIM_AD_SYSCTRL0_WDOG4_RESET_EN_MASK)

#define SIM_AD_SYSCTRL0_A35_COLD_RESET_MASK      (0x10000U)
#define SIM_AD_SYSCTRL0_A35_COLD_RESET_SHIFT     (16U)
/*! A35_COLD_RESET - CA35 Cold Reset */
#define SIM_AD_SYSCTRL0_A35_COLD_RESET(x)        (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_A35_COLD_RESET_SHIFT)) & SIM_AD_SYSCTRL0_A35_COLD_RESET_MASK)

#define SIM_AD_SYSCTRL0_AD_SW_RST_MASK           (0x20000U)
#define SIM_AD_SYSCTRL0_AD_SW_RST_SHIFT          (17U)
/*! AD_SW_RST - Enables Application Domain Software Reset */
#define SIM_AD_SYSCTRL0_AD_SW_RST(x)             (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_AD_SW_RST_SHIFT)) & SIM_AD_SYSCTRL0_AD_SW_RST_MASK)

#define SIM_AD_SYSCTRL0_TSTMR_SEL_MASK           (0x8000000U)
#define SIM_AD_SYSCTRL0_TSTMR_SEL_SHIFT          (27U)
/*! TSTMR_SEL - CA35 Timer Select */
#define SIM_AD_SYSCTRL0_TSTMR_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_TSTMR_SEL_SHIFT)) & SIM_AD_SYSCTRL0_TSTMR_SEL_MASK)

#define SIM_AD_SYSCTRL0_TSTMR_COMP0_EN_MASK      (0x10000000U)
#define SIM_AD_SYSCTRL0_TSTMR_COMP0_EN_SHIFT     (28U)
/*! TSTMR_COMP0_EN - Enables the Compare of CA35 TS Timer Versus The First Programmed Value. */
#define SIM_AD_SYSCTRL0_TSTMR_COMP0_EN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_TSTMR_COMP0_EN_SHIFT)) & SIM_AD_SYSCTRL0_TSTMR_COMP0_EN_MASK)

#define SIM_AD_SYSCTRL0_TSTMR_COMP0_IRQ_CTRL_MASK (0x20000000U)
#define SIM_AD_SYSCTRL0_TSTMR_COMP0_IRQ_CTRL_SHIFT (29U)
/*! TSTMR_COMP0_IRQ_CTRL - Controls the First Compare of CA35 Reset as IRQ. */
#define SIM_AD_SYSCTRL0_TSTMR_COMP0_IRQ_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_TSTMR_COMP0_IRQ_CTRL_SHIFT)) & SIM_AD_SYSCTRL0_TSTMR_COMP0_IRQ_CTRL_MASK)

#define SIM_AD_SYSCTRL0_TSTMR_COMP1_EN_MASK      (0x40000000U)
#define SIM_AD_SYSCTRL0_TSTMR_COMP1_EN_SHIFT     (30U)
/*! TSTMR_COMP1_EN - Enables the Compare of CA35 TS Timer Versus Second Programmed Value. */
#define SIM_AD_SYSCTRL0_TSTMR_COMP1_EN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_TSTMR_COMP1_EN_SHIFT)) & SIM_AD_SYSCTRL0_TSTMR_COMP1_EN_MASK)

#define SIM_AD_SYSCTRL0_TSTMR_COMP1_IRQ_CTRL_MASK (0x80000000U)
#define SIM_AD_SYSCTRL0_TSTMR_COMP1_IRQ_CTRL_SHIFT (31U)
/*! TSTMR_COMP1_IRQ_CTRL - Controls the Second Compare of CA35 Reset as IRQ. */
#define SIM_AD_SYSCTRL0_TSTMR_COMP1_IRQ_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SIM_AD_SYSCTRL0_TSTMR_COMP1_IRQ_CTRL_SHIFT)) & SIM_AD_SYSCTRL0_TSTMR_COMP1_IRQ_CTRL_MASK)
/*! @} */

/*! @name WKPU0_WAKEUP_EN - WKPU0 Wake-up Enable Register */
/*! @{ */

#define SIM_AD_WKPU0_WAKEUP_EN_WKPU0_WAKEUP_EN_MASK (0xFFFFFFFFU)
#define SIM_AD_WKPU0_WAKEUP_EN_WKPU0_WAKEUP_EN_SHIFT (0U)
/*! WKPU0_WAKEUP_EN - Wake-up Enable Bits for WKPU0 Channels */
#define SIM_AD_WKPU0_WAKEUP_EN_WKPU0_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_WKPU0_WAKEUP_EN_WKPU0_WAKEUP_EN_SHIFT)) & SIM_AD_WKPU0_WAKEUP_EN_WKPU0_WAKEUP_EN_MASK)
/*! @} */

/*! @name WKPU1_WAKEUP_EN - WKPU1 Wake-up Enable Register 1 */
/*! @{ */

#define SIM_AD_WKPU1_WAKEUP_EN_WKPU1_WAKEUP_EN_MASK (0xFFFFFFFFU)
#define SIM_AD_WKPU1_WAKEUP_EN_WKPU1_WAKEUP_EN_SHIFT (0U)
/*! WKPU1_WAKEUP_EN - Wake-up Enable Bits for WKPU1 Channels */
#define SIM_AD_WKPU1_WAKEUP_EN_WKPU1_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_WKPU1_WAKEUP_EN_WKPU1_WAKEUP_EN_SHIFT)) & SIM_AD_WKPU1_WAKEUP_EN_WKPU1_WAKEUP_EN_MASK)
/*! @} */

/*! @name USB_WAKEUP - USB Wake-up Control Register (DGO 10) */
/*! @{ */

#define SIM_AD_USB_WAKEUP_USB0_PHY_WAKEUP_ISO_DISABLE_MASK (0x1U)
#define SIM_AD_USB_WAKEUP_USB0_PHY_WAKEUP_ISO_DISABLE_SHIFT (0U)
/*! USB0_PHY_WAKEUP_ISO_DISABLE - USB0 Wake-up ISO Disable */
#define SIM_AD_USB_WAKEUP_USB0_PHY_WAKEUP_ISO_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_USB_WAKEUP_USB0_PHY_WAKEUP_ISO_DISABLE_SHIFT)) & SIM_AD_USB_WAKEUP_USB0_PHY_WAKEUP_ISO_DISABLE_MASK)

#define SIM_AD_USB_WAKEUP_USB1_PHY_WAKEUP_ISO_DISABLE_MASK (0x2U)
#define SIM_AD_USB_WAKEUP_USB1_PHY_WAKEUP_ISO_DISABLE_SHIFT (1U)
/*! USB1_PHY_WAKEUP_ISO_DISABLE - USB1 Wake-up ISO Disable */
#define SIM_AD_USB_WAKEUP_USB1_PHY_WAKEUP_ISO_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_USB_WAKEUP_USB1_PHY_WAKEUP_ISO_DISABLE_SHIFT)) & SIM_AD_USB_WAKEUP_USB1_PHY_WAKEUP_ISO_DISABLE_MASK)

#define SIM_AD_USB_WAKEUP_USB0_PHY_NON_DPD_WAKEUP_EN_MASK (0x4U)
#define SIM_AD_USB_WAKEUP_USB0_PHY_NON_DPD_WAKEUP_EN_SHIFT (2U)
/*! USB0_PHY_NON_DPD_WAKEUP_EN - USB0 Non Deep Power Down Wake-up Enable */
#define SIM_AD_USB_WAKEUP_USB0_PHY_NON_DPD_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_USB_WAKEUP_USB0_PHY_NON_DPD_WAKEUP_EN_SHIFT)) & SIM_AD_USB_WAKEUP_USB0_PHY_NON_DPD_WAKEUP_EN_MASK)

#define SIM_AD_USB_WAKEUP_USB1_PHY_NON_DPD_WAKEUP_EN_MASK (0x8U)
#define SIM_AD_USB_WAKEUP_USB1_PHY_NON_DPD_WAKEUP_EN_SHIFT (3U)
/*! USB1_PHY_NON_DPD_WAKEUP_EN - USB1 Non Deep Power Down Wake-up Enable */
#define SIM_AD_USB_WAKEUP_USB1_PHY_NON_DPD_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_USB_WAKEUP_USB1_PHY_NON_DPD_WAKEUP_EN_SHIFT)) & SIM_AD_USB_WAKEUP_USB1_PHY_NON_DPD_WAKEUP_EN_MASK)

#define SIM_AD_USB_WAKEUP_USB0_PHY_DPD_WAKEUP_EN_MASK (0x10U)
#define SIM_AD_USB_WAKEUP_USB0_PHY_DPD_WAKEUP_EN_SHIFT (4U)
/*! USB0_PHY_DPD_WAKEUP_EN - USB0 Deep Power Down Wake-up Enable */
#define SIM_AD_USB_WAKEUP_USB0_PHY_DPD_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_USB_WAKEUP_USB0_PHY_DPD_WAKEUP_EN_SHIFT)) & SIM_AD_USB_WAKEUP_USB0_PHY_DPD_WAKEUP_EN_MASK)

#define SIM_AD_USB_WAKEUP_USB1_PHY_DPD_WAKEUP_EN_MASK (0x20U)
#define SIM_AD_USB_WAKEUP_USB1_PHY_DPD_WAKEUP_EN_SHIFT (5U)
/*! USB1_PHY_DPD_WAKEUP_EN - USB1 Deep Power Down Wake-up Enable */
#define SIM_AD_USB_WAKEUP_USB1_PHY_DPD_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_USB_WAKEUP_USB1_PHY_DPD_WAKEUP_EN_SHIFT)) & SIM_AD_USB_WAKEUP_USB1_PHY_DPD_WAKEUP_EN_MASK)
/*! @} */

/*! @name PTD_COMPCELL - PTD Pads Compensation Cell Configuration Register */
/*! @{ */

#define SIM_AD_PTD_COMPCELL_RASRCN_MASK          (0xFU)
#define SIM_AD_PTD_COMPCELL_RASRCN_SHIFT         (0U)
/*! RASRCN - Defines Pads Driver NMOS Transistors Compensation Code */
#define SIM_AD_PTD_COMPCELL_RASRCN(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_RASRCN_SHIFT)) & SIM_AD_PTD_COMPCELL_RASRCN_MASK)

#define SIM_AD_PTD_COMPCELL_RASRCP_MASK          (0xF0U)
#define SIM_AD_PTD_COMPCELL_RASRCP_SHIFT         (4U)
/*! RASRCP - Defines Pads Driver PMOS Transistors Compensation Code */
#define SIM_AD_PTD_COMPCELL_RASRCP(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_RASRCP_SHIFT)) & SIM_AD_PTD_COMPCELL_RASRCP_MASK)

#define SIM_AD_PTD_COMPCELL_SLEEP_MASK           (0x800U)
#define SIM_AD_PTD_COMPCELL_SLEEP_SHIFT          (11U)
/*! SLEEP - Enables SLEEP mode */
#define SIM_AD_PTD_COMPCELL_SLEEP(x)             (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_SLEEP_SHIFT)) & SIM_AD_PTD_COMPCELL_SLEEP_MASK)

#define SIM_AD_PTD_COMPCELL_FASTFREEZE_MASK      (0x1000U)
#define SIM_AD_PTD_COMPCELL_FASTFREEZE_SHIFT     (12U)
/*! FASTFREEZE - Enables Fast Freeze Mode */
#define SIM_AD_PTD_COMPCELL_FASTFREEZE(x)        (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_FASTFREEZE_SHIFT)) & SIM_AD_PTD_COMPCELL_FASTFREEZE_MASK)

#define SIM_AD_PTD_COMPCELL_FREEZE_MASK          (0x2000U)
#define SIM_AD_PTD_COMPCELL_FREEZE_SHIFT         (13U)
/*! FREEZE - Enables Freeze Mode */
#define SIM_AD_PTD_COMPCELL_FREEZE(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_FREEZE_SHIFT)) & SIM_AD_PTD_COMPCELL_FREEZE_MASK)

#define SIM_AD_PTD_COMPCELL_COMTQ_MASK           (0x4000U)
#define SIM_AD_PTD_COMPCELL_COMTQ_SHIFT          (14U)
/*! COMTQ - Compensation TQ */
#define SIM_AD_PTD_COMPCELL_COMTQ(x)             (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_COMTQ_SHIFT)) & SIM_AD_PTD_COMPCELL_COMTQ_MASK)

#define SIM_AD_PTD_COMPCELL_COMPE_MASK           (0x8000U)
#define SIM_AD_PTD_COMPCELL_COMPE_SHIFT          (15U)
/*! COMPE - Compensation Status */
#define SIM_AD_PTD_COMPCELL_COMPE(x)             (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_COMPE_SHIFT)) & SIM_AD_PTD_COMPCELL_COMPE_MASK)

#define SIM_AD_PTD_COMPCELL_NASRCN_MASK          (0xF0000U)
#define SIM_AD_PTD_COMPCELL_NASRCN_SHIFT         (16U)
/*! NASRCN - Generated Pads Driver NMOS Transistors Compensation Code */
#define SIM_AD_PTD_COMPCELL_NASRCN(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_NASRCN_SHIFT)) & SIM_AD_PTD_COMPCELL_NASRCN_MASK)

#define SIM_AD_PTD_COMPCELL_NASRCP_MASK          (0xF00000U)
#define SIM_AD_PTD_COMPCELL_NASRCP_SHIFT         (20U)
/*! NASRCP - Generated Pads Driver PMOS Transistors Compensation Code */
#define SIM_AD_PTD_COMPCELL_NASRCP(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_NASRCP_SHIFT)) & SIM_AD_PTD_COMPCELL_NASRCP_MASK)

#define SIM_AD_PTD_COMPCELL_COMPOK_MASK          (0x80000000U)
#define SIM_AD_PTD_COMPCELL_COMPOK_SHIFT         (31U)
/*! COMPOK - Compensation OK */
#define SIM_AD_PTD_COMPCELL_COMPOK(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_PTD_COMPCELL_COMPOK_SHIFT)) & SIM_AD_PTD_COMPCELL_COMPOK_MASK)
/*! @} */

/*! @name TSTMR_CMP0_VAL_L - Lower CA35 TS Timer First Compare Value */
/*! @{ */

#define SIM_AD_TSTMR_CMP0_VAL_L_TSTMR_CMP_VAL_L_MASK (0xFFFFFFFFU)
#define SIM_AD_TSTMR_CMP0_VAL_L_TSTMR_CMP_VAL_L_SHIFT (0U)
/*! TSTMR_CMP_VAL_L - Lower CA35 TS Timer Compare Value */
#define SIM_AD_TSTMR_CMP0_VAL_L_TSTMR_CMP_VAL_L(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_TSTMR_CMP0_VAL_L_TSTMR_CMP_VAL_L_SHIFT)) & SIM_AD_TSTMR_CMP0_VAL_L_TSTMR_CMP_VAL_L_MASK)
/*! @} */

/*! @name TSTMR_CMP0_VAL_H - Upper CA35 TS Timer First Compare Value */
/*! @{ */

#define SIM_AD_TSTMR_CMP0_VAL_H_TSTMR_CMP_VAL_H_MASK (0xFFFFFFFFU)
#define SIM_AD_TSTMR_CMP0_VAL_H_TSTMR_CMP_VAL_H_SHIFT (0U)
/*! TSTMR_CMP_VAL_H - Upper CA35 TS Timer Compare value */
#define SIM_AD_TSTMR_CMP0_VAL_H_TSTMR_CMP_VAL_H(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_TSTMR_CMP0_VAL_H_TSTMR_CMP_VAL_H_SHIFT)) & SIM_AD_TSTMR_CMP0_VAL_H_TSTMR_CMP_VAL_H_MASK)
/*! @} */

/*! @name TSTMR_CMP1_VAL_L - Lower CA35 TS Timer Second Compare value */
/*! @{ */

#define SIM_AD_TSTMR_CMP1_VAL_L_TSTMR_CMP_VAL_L_MASK (0xFFFFFFFFU)
#define SIM_AD_TSTMR_CMP1_VAL_L_TSTMR_CMP_VAL_L_SHIFT (0U)
/*! TSTMR_CMP_VAL_L - Lower CA35 TS Timer Compare Value */
#define SIM_AD_TSTMR_CMP1_VAL_L_TSTMR_CMP_VAL_L(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_TSTMR_CMP1_VAL_L_TSTMR_CMP_VAL_L_SHIFT)) & SIM_AD_TSTMR_CMP1_VAL_L_TSTMR_CMP_VAL_L_MASK)
/*! @} */

/*! @name TSTMR_CMP1_VAL_H - Upper CA35 TS Timer Second Compare Value */
/*! @{ */

#define SIM_AD_TSTMR_CMP1_VAL_H_TSTMR_CMP_VAL_H_MASK (0xFFFFFFFFU)
#define SIM_AD_TSTMR_CMP1_VAL_H_TSTMR_CMP_VAL_H_SHIFT (0U)
/*! TSTMR_CMP_VAL_H - Upper CA35 TS Timer Compare Value */
#define SIM_AD_TSTMR_CMP1_VAL_H_TSTMR_CMP_VAL_H(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_TSTMR_CMP1_VAL_H_TSTMR_CMP_VAL_H_SHIFT)) & SIM_AD_TSTMR_CMP1_VAL_H_TSTMR_CMP_VAL_H_MASK)
/*! @} */

/*! @name RVBARADDR0 - CA35 Core0 Reset Vector Base Address (DGO 8) */
/*! @{ */

#define SIM_AD_RVBARADDR0_RVBARADDR0_MASK        (0xFFFFFFFFU)
#define SIM_AD_RVBARADDR0_RVBARADDR0_SHIFT       (0U)
/*! RVBARADDR0 - CA35 Core0 Reset Vector Base Address */
#define SIM_AD_RVBARADDR0_RVBARADDR0(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_RVBARADDR0_RVBARADDR0_SHIFT)) & SIM_AD_RVBARADDR0_RVBARADDR0_MASK)
/*! @} */

/*! @name RVBARADDR1 - CA35 Core1 Reset Vector Base Address (DGO 9) */
/*! @{ */

#define SIM_AD_RVBARADDR1_RVBARADDR1_MASK        (0xFFFFFFFFU)
#define SIM_AD_RVBARADDR1_RVBARADDR1_SHIFT       (0U)
/*! RVBARADDR1 - CA35 Core1 Reset Vector Base Address */
#define SIM_AD_RVBARADDR1_RVBARADDR1(x)          (((uint32_t)(((uint32_t)(x)) << SIM_AD_RVBARADDR1_RVBARADDR1_SHIFT)) & SIM_AD_RVBARADDR1_RVBARADDR1_MASK)
/*! @} */

/*! @name MQS1_CF - Medium Quality Sound Configuration Register */
/*! @{ */

#define SIM_AD_MQS1_CF_MQS1_CLK_DIV_MASK         (0xFF0000U)
#define SIM_AD_MQS1_CF_MQS1_CLK_DIV_SHIFT        (16U)
/*! MQS1_CLK_DIV - Divider Ration Control for mclk from hmclk. */
#define SIM_AD_MQS1_CF_MQS1_CLK_DIV(x)           (((uint32_t)(((uint32_t)(x)) << SIM_AD_MQS1_CF_MQS1_CLK_DIV_SHIFT)) & SIM_AD_MQS1_CF_MQS1_CLK_DIV_MASK)

#define SIM_AD_MQS1_CF_MQS1_SW_RST_MASK          (0x1000000U)
#define SIM_AD_MQS1_CF_MQS1_SW_RST_SHIFT         (24U)
/*! MQS1_SW_RST - MQS Software Reset */
#define SIM_AD_MQS1_CF_MQS1_SW_RST(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_MQS1_CF_MQS1_SW_RST_SHIFT)) & SIM_AD_MQS1_CF_MQS1_SW_RST_MASK)

#define SIM_AD_MQS1_CF_MQS1_EN_MASK              (0x2000000U)
#define SIM_AD_MQS1_CF_MQS1_EN_SHIFT             (25U)
/*! MQS1_EN - Enables MQS */
#define SIM_AD_MQS1_CF_MQS1_EN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_AD_MQS1_CF_MQS1_EN_SHIFT)) & SIM_AD_MQS1_CF_MQS1_EN_MASK)

#define SIM_AD_MQS1_CF_MQS1_OVERSAMPLE_MASK      (0x4000000U)
#define SIM_AD_MQS1_CF_MQS1_OVERSAMPLE_SHIFT     (26U)
/*! MQS1_OVERSAMPLE - PWM Oversampling Rate Selection */
#define SIM_AD_MQS1_CF_MQS1_OVERSAMPLE(x)        (((uint32_t)(((uint32_t)(x)) << SIM_AD_MQS1_CF_MQS1_OVERSAMPLE_SHIFT)) & SIM_AD_MQS1_CF_MQS1_OVERSAMPLE_MASK)

#define SIM_AD_MQS1_CF_MQS1_SDATA_SOURCE_MASK    (0x8000000U)
#define SIM_AD_MQS1_CF_MQS1_SDATA_SOURCE_SHIFT   (27U)
/*! MQS1_SDATA_SOURCE - MQS1s sdata Input Source Selection */
#define SIM_AD_MQS1_CF_MQS1_SDATA_SOURCE(x)      (((uint32_t)(((uint32_t)(x)) << SIM_AD_MQS1_CF_MQS1_SDATA_SOURCE_SHIFT)) & SIM_AD_MQS1_CF_MQS1_SDATA_SOURCE_MASK)
/*! @} */

/*! @name SAI_MULTISYNC_ENABLE_SELECTOR - SAI 4 and 5 Transmitter/Receiver Multi-Synchronous Enable Source */
/*! @{ */

#define SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI4_MULTISYNC_ENABLE_SELECTOR_MASK (0x3U)
#define SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI4_MULTISYNC_ENABLE_SELECTOR_SHIFT (0U)
/*! SAI4_MULTISYNC_ENABLE_SELECTOR - SAI4 Multi-sync Enable Source */
#define SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI4_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI4_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI4_MULTISYNC_ENABLE_SELECTOR_MASK)

#define SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI5_MULTISYNC_ENABLE_SELECTOR_MASK (0x300U)
#define SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI5_MULTISYNC_ENABLE_SELECTOR_SHIFT (8U)
/*! SAI5_MULTISYNC_ENABLE_SELECTOR - SAI5 Multi-sync Enable Source */
#define SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI5_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI5_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_AD_SAI_MULTISYNC_ENABLE_SELECTOR_SAI5_MULTISYNC_ENABLE_SELECTOR_MASK)
/*! @} */

/*! @name CORE0_PMU_EVENT - A35 Core0 Performance Monitoring Events */
/*! @{ */

#define SIM_AD_CORE0_PMU_EVENT_CORE0_PMU_EVENT_MASK (0x3FFFFFFFU)
#define SIM_AD_CORE0_PMU_EVENT_CORE0_PMU_EVENT_SHIFT (0U)
/*! CORE0_PMU_EVENT - A35 Core0 PMU EVENT */
#define SIM_AD_CORE0_PMU_EVENT_CORE0_PMU_EVENT(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_CORE0_PMU_EVENT_CORE0_PMU_EVENT_SHIFT)) & SIM_AD_CORE0_PMU_EVENT_CORE0_PMU_EVENT_MASK)
/*! @} */

/*! @name CORE1_PMU_EVENT - A35 Core1 Performance Monitoring Events */
/*! @{ */

#define SIM_AD_CORE1_PMU_EVENT_CORE1_PMU_EVENT_MASK (0x3FFFFFFFU)
#define SIM_AD_CORE1_PMU_EVENT_CORE1_PMU_EVENT_SHIFT (0U)
/*! CORE1_PMU_EVENT - A35 Core1 PMU EVENT */
#define SIM_AD_CORE1_PMU_EVENT_CORE1_PMU_EVENT(x) (((uint32_t)(((uint32_t)(x)) << SIM_AD_CORE1_PMU_EVENT_CORE1_PMU_EVENT_SHIFT)) & SIM_AD_CORE1_PMU_EVENT_CORE1_PMU_EVENT_MASK)
/*! @} */

/*! @name DGO_GP6 - APD SIM DGO General Purpose Register 6 */
/*! @{ */

#define SIM_AD_DGO_GP6_SIM_DGO_GP6_MASK          (0xFFFFFFFFU)
#define SIM_AD_DGO_GP6_SIM_DGO_GP6_SHIFT         (0U)
/*! SIM_DGO_GP6 - SIM DGO General purpose register 6 */
#define SIM_AD_DGO_GP6_SIM_DGO_GP6(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP6_SIM_DGO_GP6_SHIFT)) & SIM_AD_DGO_GP6_SIM_DGO_GP6_MASK)
/*! @} */

/*! @name DGO_GP7 - APD SIM DGO General Purpose Register 7 */
/*! @{ */

#define SIM_AD_DGO_GP7_SIM_DGO_GP7_MASK          (0xFFFFFFFFU)
#define SIM_AD_DGO_GP7_SIM_DGO_GP7_SHIFT         (0U)
/*! SIM_DGO_GP7 - SIM DGO General Purpose Register 7 */
#define SIM_AD_DGO_GP7_SIM_DGO_GP7(x)            (((uint32_t)(((uint32_t)(x)) << SIM_AD_DGO_GP7_SIM_DGO_GP7_SHIFT)) & SIM_AD_DGO_GP7_SIM_DGO_GP7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_AD_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_AD_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_AD_H_ */

