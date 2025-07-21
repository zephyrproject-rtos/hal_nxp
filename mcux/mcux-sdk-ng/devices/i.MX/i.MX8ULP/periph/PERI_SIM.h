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
**         CMSIS Peripheral Access Layer for SIM
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
 * @file PERI_SIM.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t SYSCTRL0;                          /**< Realtime Domains System Control Register 0, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __I  uint32_t JTAG_ID_REG;                       /**< Mirror of JTAG ID Register, offset: 0x10 */
       uint8_t RESERVED_2[8];
  __IO uint32_t SSRAM_SAVE_POWER;                  /**< System Shared RAM Access Disable Register, offset: 0x1C */
  __IO uint32_t PTC_COMPCELL;                      /**< Configures PTC Pads Compensation Cell operation, offset: 0x20 */
  __IO uint32_t MQS0_CF;                           /**< Medium Quality Sound Configuration Register, offset: 0x24 */
  __IO uint32_t M33_CFGNSSTCALIB;                  /**< Non-Secure SysTick Calibration Configuration, offset: 0x28 */
       uint8_t RESERVED_3[44];
  __IO uint32_t SAI_MULTISYNC_ENABLE_SELECTOR;     /**< SAI 0 to 3 Transmitter/Receiver Multi-Synchronous Enable Source, offset: 0x58 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SYSCTRL0 - Realtime Domains System Control Register 0 */
/*! @{ */

#define SIM_SYSCTRL0_CM33_RST_ACK_MASK           (0x8U)
#define SIM_SYSCTRL0_CM33_RST_ACK_SHIFT          (3U)
/*! CM33_RST_ACK - CM33 Core is in safe state for reset sequencing */
#define SIM_SYSCTRL0_CM33_RST_ACK(x)             (((uint32_t)(((uint32_t)(x)) << SIM_SYSCTRL0_CM33_RST_ACK_SHIFT)) & SIM_SYSCTRL0_CM33_RST_ACK_MASK)

#define SIM_SYSCTRL0_FLEXCAN_TICK_FREQ_CONFIG_MASK (0x3FF0000U)
#define SIM_SYSCTRL0_FLEXCAN_TICK_FREQ_CONFIG_SHIFT (16U)
/*! FLEXCAN_TICK_FREQ_CONFIG - FlexCAN Timer Frequency Configuration Register */
#define SIM_SYSCTRL0_FLEXCAN_TICK_FREQ_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << SIM_SYSCTRL0_FLEXCAN_TICK_FREQ_CONFIG_SHIFT)) & SIM_SYSCTRL0_FLEXCAN_TICK_FREQ_CONFIG_MASK)
/*! @} */

/*! @name JTAG_ID_REG - Mirror of JTAG ID Register */
/*! @{ */

#define SIM_JTAG_ID_REG_JTAG_INIT_BIT_MASK       (0x1U)
#define SIM_JTAG_ID_REG_JTAG_INIT_BIT_SHIFT      (0U)
/*! JTAG_INIT_BIT - JTAG ID Initial Bit */
#define SIM_JTAG_ID_REG_JTAG_INIT_BIT(x)         (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_JTAG_INIT_BIT_SHIFT)) & SIM_JTAG_ID_REG_JTAG_INIT_BIT_MASK)

#define SIM_JTAG_ID_REG_COMPANY_IDCODE_MASK      (0xFFEU)
#define SIM_JTAG_ID_REG_COMPANY_IDCODE_SHIFT     (1U)
/*! COMPANY_IDCODE - Company ID Code */
#define SIM_JTAG_ID_REG_COMPANY_IDCODE(x)        (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_COMPANY_IDCODE_SHIFT)) & SIM_JTAG_ID_REG_COMPANY_IDCODE_MASK)

#define SIM_JTAG_ID_REG_PIN_PLUG_MASK            (0x3FF000U)
#define SIM_JTAG_ID_REG_PIN_PLUG_SHIFT           (12U)
/*! PIN_PLUG - Part Identification Number */
#define SIM_JTAG_ID_REG_PIN_PLUG(x)              (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_PIN_PLUG_SHIFT)) & SIM_JTAG_ID_REG_PIN_PLUG_MASK)

#define SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_MASK (0xFC00000U)
#define SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_SHIFT (22U)
/*! DESIGN_CENTER_IDCODE - Design Center ID Code */
#define SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_SHIFT)) & SIM_JTAG_ID_REG_DESIGN_CENTER_IDCODE_MASK)

#define SIM_JTAG_ID_REG_PRN_PLUG_MASK            (0xF0000000U)
#define SIM_JTAG_ID_REG_PRN_PLUG_SHIFT           (28U)
/*! PRN_PLUG - Part Revision Number */
#define SIM_JTAG_ID_REG_PRN_PLUG(x)              (((uint32_t)(((uint32_t)(x)) << SIM_JTAG_ID_REG_PRN_PLUG_SHIFT)) & SIM_JTAG_ID_REG_PRN_PLUG_MASK)
/*! @} */

/*! @name SSRAM_SAVE_POWER - System Shared RAM Access Disable Register */
/*! @{ */

#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_AUTO_CLOCK_GATING_MASK (0xFFU)
#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_AUTO_CLOCK_GATING_SHIFT (0U)
/*! SSRAM_DISABLE_AUTO_CLOCK_GATING - Disable Automatic Clock Gating */
#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_AUTO_CLOCK_GATING(x) (((uint32_t)(((uint32_t)(x)) << SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_AUTO_CLOCK_GATING_SHIFT)) & SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_AUTO_CLOCK_GATING_MASK)

#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_INPUTS_MASK (0xFF00U)
#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_INPUTS_SHIFT (8U)
/*! SSRAM_DISABLE_ARRAYS_INPUTS - System Shared RAM Input Gate (IG) Disable */
#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_INPUTS(x) (((uint32_t)(((uint32_t)(x)) << SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_INPUTS_SHIFT)) & SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_INPUTS_MASK)

#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_WORDLINES_MASK (0xFF0000U)
#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_WORDLINES_SHIFT (16U)
/*! SSRAM_DISABLE_ARRAYS_WORDLINES - System Shared RAM Arrays Wordlines Disable */
#define SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_WORDLINES(x) (((uint32_t)(((uint32_t)(x)) << SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_WORDLINES_SHIFT)) & SIM_SSRAM_SAVE_POWER_SSRAM_DISABLE_ARRAYS_WORDLINES_MASK)
/*! @} */

/*! @name PTC_COMPCELL - Configures PTC Pads Compensation Cell operation */
/*! @{ */

#define SIM_PTC_COMPCELL_RASRCN_MASK             (0xFU)
#define SIM_PTC_COMPCELL_RASRCN_SHIFT            (0U)
/*! RASRCN - Defines Pads Driver NMOS transistors Compensation Code */
#define SIM_PTC_COMPCELL_RASRCN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_RASRCN_SHIFT)) & SIM_PTC_COMPCELL_RASRCN_MASK)

#define SIM_PTC_COMPCELL_RASRCP_MASK             (0xF0U)
#define SIM_PTC_COMPCELL_RASRCP_SHIFT            (4U)
/*! RASRCP - Defines Pads Driver PMOS Transistors Compensation Code */
#define SIM_PTC_COMPCELL_RASRCP(x)               (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_RASRCP_SHIFT)) & SIM_PTC_COMPCELL_RASRCP_MASK)

#define SIM_PTC_COMPCELL_SLEEP_MASK              (0x800U)
#define SIM_PTC_COMPCELL_SLEEP_SHIFT             (11U)
/*! SLEEP - Enables SLEEP Mode */
#define SIM_PTC_COMPCELL_SLEEP(x)                (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_SLEEP_SHIFT)) & SIM_PTC_COMPCELL_SLEEP_MASK)

#define SIM_PTC_COMPCELL_FASTFREEZE_MASK         (0x1000U)
#define SIM_PTC_COMPCELL_FASTFREEZE_SHIFT        (12U)
/*! FASTFREEZE - Enables Fast Freeze Mode */
#define SIM_PTC_COMPCELL_FASTFREEZE(x)           (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_FASTFREEZE_SHIFT)) & SIM_PTC_COMPCELL_FASTFREEZE_MASK)

#define SIM_PTC_COMPCELL_FREEZE_MASK             (0x2000U)
#define SIM_PTC_COMPCELL_FREEZE_SHIFT            (13U)
/*! FREEZE - Enables Freeze Mode */
#define SIM_PTC_COMPCELL_FREEZE(x)               (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_FREEZE_SHIFT)) & SIM_PTC_COMPCELL_FREEZE_MASK)

#define SIM_PTC_COMPCELL_COMTQ_MASK              (0x4000U)
#define SIM_PTC_COMPCELL_COMTQ_SHIFT             (14U)
/*! COMTQ - Compensation TQ */
#define SIM_PTC_COMPCELL_COMTQ(x)                (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_COMTQ_SHIFT)) & SIM_PTC_COMPCELL_COMTQ_MASK)

#define SIM_PTC_COMPCELL_COMPE_MASK              (0x8000U)
#define SIM_PTC_COMPCELL_COMPE_SHIFT             (15U)
/*! COMPE - Compensation Status */
#define SIM_PTC_COMPCELL_COMPE(x)                (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_COMPE_SHIFT)) & SIM_PTC_COMPCELL_COMPE_MASK)

#define SIM_PTC_COMPCELL_NASRCN_MASK             (0xF0000U)
#define SIM_PTC_COMPCELL_NASRCN_SHIFT            (16U)
/*! NASRCN - Generated Pads Driver NMOS transistors Compensation Code */
#define SIM_PTC_COMPCELL_NASRCN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_NASRCN_SHIFT)) & SIM_PTC_COMPCELL_NASRCN_MASK)

#define SIM_PTC_COMPCELL_NASRCP_MASK             (0xF00000U)
#define SIM_PTC_COMPCELL_NASRCP_SHIFT            (20U)
/*! NASRCP - Generated Pads Driver PMOS transistors Compensation Code */
#define SIM_PTC_COMPCELL_NASRCP(x)               (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_NASRCP_SHIFT)) & SIM_PTC_COMPCELL_NASRCP_MASK)

#define SIM_PTC_COMPCELL_COMPOK_MASK             (0x80000000U)
#define SIM_PTC_COMPCELL_COMPOK_SHIFT            (31U)
/*! COMPOK - Compensation OK */
#define SIM_PTC_COMPCELL_COMPOK(x)               (((uint32_t)(((uint32_t)(x)) << SIM_PTC_COMPCELL_COMPOK_SHIFT)) & SIM_PTC_COMPCELL_COMPOK_MASK)
/*! @} */

/*! @name MQS0_CF - Medium Quality Sound Configuration Register */
/*! @{ */

#define SIM_MQS0_CF_MQS0_CLK_DIV_MASK            (0xFF0000U)
#define SIM_MQS0_CF_MQS0_CLK_DIV_SHIFT           (16U)
/*! MQS0_CLK_DIV - Divider Ration Control for MCLK from HMCLK. */
#define SIM_MQS0_CF_MQS0_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SIM_MQS0_CF_MQS0_CLK_DIV_SHIFT)) & SIM_MQS0_CF_MQS0_CLK_DIV_MASK)

#define SIM_MQS0_CF_MQS0_SW_RST_MASK             (0x1000000U)
#define SIM_MQS0_CF_MQS0_SW_RST_SHIFT            (24U)
/*! MQS0_SW_RST - MQS Software Reset */
#define SIM_MQS0_CF_MQS0_SW_RST(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MQS0_CF_MQS0_SW_RST_SHIFT)) & SIM_MQS0_CF_MQS0_SW_RST_MASK)

#define SIM_MQS0_CF_MQS0_EN_MASK                 (0x2000000U)
#define SIM_MQS0_CF_MQS0_EN_SHIFT                (25U)
/*! MQS0_EN - Enables MQS */
#define SIM_MQS0_CF_MQS0_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_MQS0_CF_MQS0_EN_SHIFT)) & SIM_MQS0_CF_MQS0_EN_MASK)

#define SIM_MQS0_CF_MQS0_OVERSAMPLE_MASK         (0x4000000U)
#define SIM_MQS0_CF_MQS0_OVERSAMPLE_SHIFT        (26U)
/*! MQS0_OVERSAMPLE - PWM Oversampling Rate Selection */
#define SIM_MQS0_CF_MQS0_OVERSAMPLE(x)           (((uint32_t)(((uint32_t)(x)) << SIM_MQS0_CF_MQS0_OVERSAMPLE_SHIFT)) & SIM_MQS0_CF_MQS0_OVERSAMPLE_MASK)

#define SIM_MQS0_CF_MQS0_SDATA_SOURCE_MASK       (0x8000000U)
#define SIM_MQS0_CF_MQS0_SDATA_SOURCE_SHIFT      (27U)
/*! MQS0_SDATA_SOURCE - MQS1s Sdata Input Source Selection */
#define SIM_MQS0_CF_MQS0_SDATA_SOURCE(x)         (((uint32_t)(((uint32_t)(x)) << SIM_MQS0_CF_MQS0_SDATA_SOURCE_SHIFT)) & SIM_MQS0_CF_MQS0_SDATA_SOURCE_MASK)
/*! @} */

/*! @name M33_CFGNSSTCALIB - Non-Secure SysTick Calibration Configuration */
/*! @{ */

#define SIM_M33_CFGNSSTCALIB_CFGNSSTCALIB_MASK   (0x3FFFFFFU)
#define SIM_M33_CFGNSSTCALIB_CFGNSSTCALIB_SHIFT  (0U)
/*! CFGNSSTCALIB - Non-Secure SysTick Calibration Configuration */
#define SIM_M33_CFGNSSTCALIB_CFGNSSTCALIB(x)     (((uint32_t)(((uint32_t)(x)) << SIM_M33_CFGNSSTCALIB_CFGNSSTCALIB_SHIFT)) & SIM_M33_CFGNSSTCALIB_CFGNSSTCALIB_MASK)
/*! @} */

/*! @name SAI_MULTISYNC_ENABLE_SELECTOR - SAI 0 to 3 Transmitter/Receiver Multi-Synchronous Enable Source */
/*! @{ */

#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI0_MULTISYNC_ENABLE_SELECTOR_MASK (0x7U)
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI0_MULTISYNC_ENABLE_SELECTOR_SHIFT (0U)
/*! SAI0_MULTISYNC_ENABLE_SELECTOR - SAI0 Multi-sync Enable Source */
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI0_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI0_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI0_MULTISYNC_ENABLE_SELECTOR_MASK)

#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI1_MULTISYNC_ENABLE_SELECTOR_MASK (0x700U)
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI1_MULTISYNC_ENABLE_SELECTOR_SHIFT (8U)
/*! SAI1_MULTISYNC_ENABLE_SELECTOR - SAI1 Multi-Sync Enable Source */
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI1_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI1_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI1_MULTISYNC_ENABLE_SELECTOR_MASK)

#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI2_MULTISYNC_ENABLE_SELECTOR_MASK (0x70000U)
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI2_MULTISYNC_ENABLE_SELECTOR_SHIFT (16U)
/*! SAI2_MULTISYNC_ENABLE_SELECTOR - SAI2 Multi-Sync Enable Source */
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI2_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI2_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI2_MULTISYNC_ENABLE_SELECTOR_MASK)

#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI3_MULTISYNC_ENABLE_SELECTOR_MASK (0x7000000U)
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI3_MULTISYNC_ENABLE_SELECTOR_SHIFT (24U)
/*! SAI3_MULTISYNC_ENABLE_SELECTOR - SAI3 Multi-sync Enable Source */
#define SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI3_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI3_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_SAI_MULTISYNC_ENABLE_SELECTOR_SAI3_MULTISYNC_ENABLE_SELECTOR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_H_ */

