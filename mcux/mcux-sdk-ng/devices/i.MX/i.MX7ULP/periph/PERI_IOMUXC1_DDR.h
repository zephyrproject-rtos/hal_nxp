/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC1_DDR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC1_DDR.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC1_DDR
 *
 * CMSIS Peripheral Access Layer for IOMUXC1_DDR
 */

#if !defined(PERI_IOMUXC1_DDR_H_)
#define PERI_IOMUXC1_DDR_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- IOMUXC1_DDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_DDR_Peripheral_Access_Layer IOMUXC1_DDR Peripheral Access Layer
 * @{
 */

/** IOMUXC1_DDR - Size of Registers Arrays */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_COUNT   32u
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_COUNT  4u
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_COUNT  4u
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_COUNT      12u
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_COUNT  2u
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_COUNT   2u

/** IOMUXC1_DDR - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_PAD_CTL_PAD_DDR_DQ[IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_COUNT]; /**< SW_PAD_CTL_PAD_DDR_DQn SW PAD Control Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR_DQS[IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_COUNT]; /**< SW_PAD_CTL_PAD_DDR_DQSn SW PAD Control Register, array offset: 0x80, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR_DQM[IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_COUNT]; /**< SW_PAD_CTL_PAD_DDR_DQMn SW PAD Control Register, array offset: 0x90, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR[IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_COUNT]; /**< SW_PAD_CTL_PAD_DDR_n SW PAD Control Register, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR_CKE[IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_COUNT]; /**< SW_PAD_CTL_PAD_DDR_CKEn SW PAD Control Register, array offset: 0xD0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR_CLK0;           /**< SW_PAD_CTL_PAD_DDR_CLK0 SW PAD Control Register, offset: 0xD8 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR_ODT;            /**< SW_PAD_CTL_PAD_DDR_ODT SW PAD Control Register, offset: 0xDC */
  __IO uint32_t SW_PAD_CTL_PAD_DDR_ZQ[IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_COUNT]; /**< SW_PAD_CTL_PAD_DDR_ZQn SW PAD Control Register, array offset: 0xE0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_HSIC_DATA;          /**< SW_PAD_CTL_PAD_HSIC_DATA SW PAD Control Register, offset: 0xE8 */
  __IO uint32_t SW_PAD_CTL_PAD_HSIC_STROBE;        /**< SW_PAD_CTL_PAD_HSIC_STROBE SW PAD Control Register, offset: 0xEC */
  __IO uint32_t SW_PAD_CTL_GRP_PUE;                /**< SW_PAD_CTL_GRP_PUE SW GRP Register, offset: 0xF0 */
  __IO uint32_t SW_PAD_CTL_GRP_PUE_DAT;            /**< SW_PAD_CTL_GRP_PUE_DAT SW GRP Register, offset: 0xF4 */
  __IO uint32_t SW_PAD_CTL_GRP_PKE;                /**< SW_PAD_CTL_GRP_PKE SW GRP Register, offset: 0xF8 */
  __IO uint32_t SW_PAD_CTL_GRP_PKE_DAT;            /**< SW_PAD_CTL_GRP_PKE_DAT SW GRP Register, offset: 0xFC */
  __IO uint32_t SW_PAD_CTL_GRP_PUS;                /**< SW_PAD_CTL_GRP_PUS SW GRP Register, offset: 0x100 */
  __IO uint32_t SW_PAD_CTL_GRP_DS_ADDR;            /**< SW_PAD_CTL_GRP_DS_ADDR SW GRP Register, offset: 0x104 */
  __IO uint32_t SW_PAD_CTL_GRP_DS_CTRL;            /**< SW_PAD_CTL_GRP_DS_CTRL SW GRP Register, offset: 0x108 */
  __IO uint32_t SW_PAD_CTL_GRP_DS_DAT0;            /**< SW_PAD_CTL_GRP_DS_DAT0 SW GRP Register, offset: 0x10C */
  __IO uint32_t SW_PAD_CTL_GRP_DS_DAT1;            /**< SW_PAD_CTL_GRP_DS_DAT1 SW GRP Register, offset: 0x110 */
  __IO uint32_t SW_PAD_CTL_GRP_DS_DAT2;            /**< SW_PAD_CTL_GRP_DS_DAT2 SW GRP Register, offset: 0x114 */
  __IO uint32_t SW_PAD_CTL_GRP_DS_DAT3;            /**< SW_PAD_CTL_GRP_DS_DAT3 SW GRP Register, offset: 0x118 */
  __IO uint32_t SW_PAD_CTL_GRP_HYS;                /**< SW_PAD_CTL_GRP_HYS SW GRP Register, offset: 0x11C */
  __IO uint32_t SW_PAD_CTL_GRP_INSEL_DAT;          /**< SW_PAD_CTL_GRP_INSEL_DAT SW GRP Register, offset: 0x120 */
  __IO uint32_t SW_PAD_CTL_GRP_INSEL_DQS;          /**< SW_PAD_CTL_GRP_INSEL_DQS SW GRP Register, offset: 0x124 */
  __IO uint32_t SW_PAD_CTL_GRP_DDRTYPE;            /**< SW_PAD_CTL_GRP_DDRTYPE SW GRP Register, offset: 0x128 */
} IOMUXC1_DDR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC1_DDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_DDR_Register_Masks IOMUXC1_DDR Register Masks
 * @{
 */

/*! @name SW_PAD_CTL_PAD_DDR_DQ - SW_PAD_CTL_PAD_DDR_DQn SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQ_DDR_TRIM_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR_DQS - SW_PAD_CTL_PAD_DDR_DQSn SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PKE_MASK (0x8U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PKE_SHIFT (3U)
/*! PKE - Pull Up/Pull Down/Keeper Enable Field
 *  0b0..Pull Up/Down and Keeper Disabled
 *  0b1..Pull Up/Down or Keeper Enabled
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PKE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PKE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUS_MASK (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_PUS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DSE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_CRPOINT_TRIM_MASK (0xC00U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_CRPOINT_TRIM_SHIFT (10U)
/*! CRPOINT_TRIM - Crosspoint Adjustment Field
 *  0b00..no output crosspoint (Vix) change
 *  0b01..100mV Vix shift down
 *  0b10..100mV Vix shift up
 *  0b11..200mV Vix shift up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_CRPOINT_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_CRPOINT_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_CRPOINT_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQS_DCYCLE_TRIM_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR_DQM - SW_PAD_CTL_PAD_DDR_DQMn SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DSE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_HYS_MASK (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_INPUT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DQM_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR - SW_PAD_CTL_PAD_DDR_n SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_HYS_MASK  (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_HYS(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_INPUT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR_CKE - SW_PAD_CTL_PAD_DDR_CKEn SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PKE_MASK (0x8U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PKE_SHIFT (3U)
/*! PKE - Pull Up/Pull Down/Keeper Enable Field
 *  0b0..Pull Up/Down and Keeper Disabled
 *  0b1..Pull Up/Down or Keeper Enabled
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PKE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PKE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUS_MASK (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_PUS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_HYS_MASK (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_INPUT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CKE_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR_CLK0 - SW_PAD_CTL_PAD_DDR_CLK0 SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PKE_MASK (0x8U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PKE_SHIFT (3U)
/*! PKE - Pull Up/Pull Down/Keeper Enable Field
 *  0b0..Pull Up/Down and Keeper Disabled
 *  0b1..Pull Up/Down or Keeper Enabled
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PKE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PKE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUS_MASK (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_PUS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DSE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_HYS_MASK (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_CRPOINT_TRIM_MASK (0xC00U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_CRPOINT_TRIM_SHIFT (10U)
/*! CRPOINT_TRIM - Crosspoint Adjustment Field
 *  0b00..no output crosspoint (Vix) change
 *  0b01..100mV Vix shift down
 *  0b10..100mV Vix shift up
 *  0b11..200mV Vix shift up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_CRPOINT_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_CRPOINT_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_CRPOINT_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_INPUT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_CLK0_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR_ODT - SW_PAD_CTL_PAD_DDR_ODT SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PKE_MASK (0x8U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PKE_SHIFT (3U)
/*! PKE - Pull Up/Pull Down/Keeper Enable Field
 *  0b0..Pull Up/Down and Keeper Disabled
 *  0b1..Pull Up/Down or Keeper Enabled
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PKE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PKE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUS_MASK (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_PUS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DSE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_HYS_MASK (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_INPUT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ODT_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_DDR_ZQ - SW_PAD_CTL_PAD_DDR_ZQn SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_DDR_SELECT_MASK (0x60000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_DDR_SELECT_SHIFT (17U)
/*! DDR_SELECT - DDR Select Field
 *  0b00..DDR3 mode
 *  0b01..reserved
 *  0b10..LPDDR2/LPDDR3 modes
 *  0b11..DDR_SELECT_3_HSIC_USB mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_DDR_SELECT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_DDR_SELECT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_DDR_ZQ_DDR_SELECT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_HSIC_DATA - SW_PAD_CTL_PAD_HSIC_DATA SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUS_MASK (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_PUS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DSE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_HYS_MASK (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_SELECT_MASK (0x60000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_SELECT_SHIFT (17U)
/*! DDR_SELECT - DDR Select Field
 *  0b00..DDR3 mode
 *  0b01..reserved
 *  0b10..LPDDR2/LPDDR3 modes
 *  0b11..DDR_SELECT_3_HSIC_USB mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_SELECT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_SELECT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_SELECT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_DATA_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD_HSIC_STROBE - SW_PAD_CTL_PAD_HSIC_STROBE SW PAD Control Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUS_MASK (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_PUS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DSE_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_HYS_MASK (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_HYS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_HYS_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DCYCLE_TRIM_MASK (0x3000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DCYCLE_TRIM_SHIFT (12U)
/*! DCYCLE_TRIM - Duty Cycle Control Field
 *  0b00..no duty cycle change
 *  0b01..duty cycle increased ~3.7%
 *  0b10..duty cycle decreased ~3.7%
 *  0b11..no duty cycle change
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DCYCLE_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DCYCLE_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DCYCLE_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_TRIM_MASK (0xC000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_TRIM_SHIFT (14U)
/*! DDR_TRIM - Output Driver Delay Trim Field
 *  0b00..0pS
 *  0b01..50pS
 *  0b10..100pS
 *  0b11..150pS
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_TRIM_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_TRIM_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_SELECT_MASK (0x60000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_SELECT_SHIFT (17U)
/*! DDR_SELECT - DDR Select Field
 *  0b00..DDR3 mode
 *  0b01..reserved
 *  0b10..LPDDR2/LPDDR3 modes
 *  0b11..DDR_SELECT_3_HSIC_USB mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_SELECT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_SELECT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_SELECT_MASK)

#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_ODT_MASK (0x380000U)
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_ODT_SHIFT (19U)
/*! DDR_ODT - On Die Termination Select Field
 *  0b000..No Termination
 *  0b001..120 Ohm
 *  0b010..60 Ohm
 *  0b011..40 Ohm
 *  0b100..30 Ohm
 *  0b101..24 Ohm
 *  0b110..20 Ohm
 *  0b111..17 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_ODT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_ODT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_PAD_HSIC_STROBE_DDR_ODT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_PUE - SW_PAD_CTL_GRP_PUE SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_PUE_MASK  (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_PUE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_PUE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_PUE_DAT - SW_PAD_CTL_GRP_PUE_DAT SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_DAT_PUE_MASK (0x4U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_DAT_PUE_SHIFT (2U)
/*! PUE - Pull Up/Down or Keeper Selection Field
 *  0b0..Keeper Selected
 *  0b1..Pull Up/Down Selected
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_DAT_PUE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_DAT_PUE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_PUE_DAT_PUE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_PKE - SW_PAD_CTL_GRP_PKE SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_PKE_MASK  (0x8U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_PKE_SHIFT (3U)
/*! PKE - Pull Up/Pull Down/Keeper Enable Field
 *  0b0..Pull Up/Down and Keeper Disabled
 *  0b1..Pull Up/Down or Keeper Enabled
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_PKE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_PKE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_PKE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_PKE_DAT - SW_PAD_CTL_GRP_PKE_DAT SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_DAT_PKE_MASK (0x8U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_DAT_PKE_SHIFT (3U)
/*! PKE - Pull Up/Pull Down/Keeper Enable Field
 *  0b0..Pull Up/Down and Keeper Disabled
 *  0b1..Pull Up/Down or Keeper Enabled
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_DAT_PKE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_DAT_PKE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_PKE_DAT_PKE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_PUS - SW_PAD_CTL_GRP_PUS SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUS_PUS_MASK  (0x30U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUS_PUS_SHIFT (4U)
/*! PUS - Pull Up/Down Resistance Select Field
 *  0b00..100 kOhm Pull Down
 *  0b01..47 Kohm Pull Up
 *  0b10..100 kOhm Pull Up
 *  0b11..22 kOhm Pull Up
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_PUS_PUS(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_PUS_PUS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_PUS_PUS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DS_ADDR - SW_PAD_CTL_GRP_DS_ADDR SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_ADDR_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_ADDR_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_ADDR_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_ADDR_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_ADDR_DSE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DS_CTRL - SW_PAD_CTL_GRP_DS_CTRL SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_CTRL_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_CTRL_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_CTRL_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_CTRL_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_CTRL_DSE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DS_DAT0 - SW_PAD_CTL_GRP_DS_DAT0 SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT0_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT0_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT0_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT0_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT0_DSE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DS_DAT1 - SW_PAD_CTL_GRP_DS_DAT1 SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT1_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT1_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT1_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT1_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT1_DSE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DS_DAT2 - SW_PAD_CTL_GRP_DS_DAT2 SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT2_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT2_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT2_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT2_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT2_DSE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DS_DAT3 - SW_PAD_CTL_GRP_DS_DAT3 SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT3_DSE_MASK (0x1C0U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT3_DSE_SHIFT (6U)
/*! DSE - Output Drive Strength Select Field
 *  0b000..Driver Disabled
 *  0b001..240 Ohm
 *  0b010..240/2=120 Ohm
 *  0b011..240/3=80 Ohm
 *  0b100..240/4=60 Ohm
 *  0b101..240/5=48 Ohm
 *  0b110..240/6=40 Ohm
 *  0b111..240/7=34 Ohm
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT3_DSE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT3_DSE_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DS_DAT3_DSE_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_HYS - SW_PAD_CTL_GRP_HYS SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_HYS_HYS_MASK  (0x200U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_HYS_HYS_SHIFT (9U)
/*! HYS - Input Hysteresis Field
 *  0b0..CMOS input
 *  0b1..Schmitt trigger input
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_HYS_HYS(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_HYS_HYS_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_HYS_HYS_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_INSEL_DAT - SW_PAD_CTL_GRP_INSEL_DAT SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DAT_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DAT_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DAT_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DAT_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DAT_DDR_INPUT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_INSEL_DQS - SW_PAD_CTL_GRP_INSEL_DQS SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DQS_DDR_INPUT_MASK (0x10000U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DQS_DDR_INPUT_SHIFT (16U)
/*! DDR_INPUT - DDR/CMOS Input Select Field
 *  0b0..CMOS input type
 *  0b1..Differential input mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DQS_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DQS_DDR_INPUT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_INSEL_DQS_DDR_INPUT_MASK)
/*! @} */

/*! @name SW_PAD_CTL_GRP_DDRTYPE - SW_PAD_CTL_GRP_DDRTYPE SW GRP Register */
/*! @{ */

#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DDRTYPE_DDR_SELECT_MASK (0x60000U)
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DDRTYPE_DDR_SELECT_SHIFT (17U)
/*! DDR_SELECT - DDR Select Field
 *  0b00..DDR3 mode
 *  0b01..reserved
 *  0b10..LPDDR2/LPDDR3 modes
 *  0b11..DDR_SELECT_3_HSIC_USB mode
 */
#define IOMUXC1_DDR_SW_PAD_CTL_GRP_DDRTYPE_DDR_SELECT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC1_DDR_SW_PAD_CTL_GRP_DDRTYPE_DDR_SELECT_SHIFT)) & IOMUXC1_DDR_SW_PAD_CTL_GRP_DDRTYPE_DDR_SELECT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC1_DDR_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC1_DDR_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC1_DDR_H_ */

