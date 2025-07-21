/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC_GPR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC_GPR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC_GPR
 *
 * CMSIS Peripheral Access Layer for IOMUXC_GPR
 */

#if !defined(PERI_IOMUXC_GPR_H_)
#define PERI_IOMUXC_GPR_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1011CAE4A) || defined(CPU_MIMXRT1011DAE5A))
#include "MIMXRT1011_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Peripheral_Access_Layer IOMUXC_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_GPR - Register Layout Typedef */
typedef struct {
       uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
  __IO uint32_t GPR1;                              /**< GPR1 General Purpose Register, offset: 0x4 */
  __IO uint32_t GPR2;                              /**< GPR2 General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
  __IO uint32_t GPR4;                              /**< GPR4 General Purpose Register, offset: 0x10 */
  __IO uint32_t GPR5;                              /**< GPR5 General Purpose Register, offset: 0x14 */
  __IO uint32_t GPR6;                              /**< GPR6 General Purpose Register, offset: 0x18 */
  __IO uint32_t GPR7;                              /**< GPR7 General Purpose Register, offset: 0x1C */
  __IO uint32_t GPR8;                              /**< GPR8 General Purpose Register, offset: 0x20 */
       uint32_t GPR9;                              /**< GPR9 General Purpose Register, offset: 0x24 */
  __IO uint32_t GPR10;                             /**< GPR10 General Purpose Register, offset: 0x28 */
  __IO uint32_t GPR11;                             /**< GPR11 General Purpose Register, offset: 0x2C */
  __IO uint32_t GPR12;                             /**< GPR12 General Purpose Register, offset: 0x30 */
  __IO uint32_t GPR13;                             /**< GPR13 General Purpose Register, offset: 0x34 */
       uint32_t GPR14;                             /**< GPR14 General Purpose Register, offset: 0x38 */
       uint32_t GPR15;                             /**< GPR15 General Purpose Register, offset: 0x3C */
  __IO uint32_t GPR16;                             /**< GPR16 General Purpose Register, offset: 0x40 */
  __IO uint32_t GPR17;                             /**< GPR17 General Purpose Register, offset: 0x44 */
  __IO uint32_t GPR18;                             /**< GPR18 General Purpose Register, offset: 0x48 */
  __IO uint32_t GPR19;                             /**< GPR19 General Purpose Register, offset: 0x4C */
  __IO uint32_t GPR20;                             /**< GPR20 General Purpose Register, offset: 0x50 */
  __IO uint32_t GPR21;                             /**< GPR21 General Purpose Register, offset: 0x54 */
  __IO uint32_t GPR22;                             /**< GPR22 General Purpose Register, offset: 0x58 */
  __IO uint32_t GPR23;                             /**< GPR23 General Purpose Register, offset: 0x5C */
  __IO uint32_t GPR24;                             /**< GPR24 General Purpose Register, offset: 0x60 */
  __IO uint32_t GPR25;                             /**< GPR25 General Purpose Register, offset: 0x64 */
  __IO uint32_t GPR26;                             /**< GPR26 General Purpose Register, offset: 0x68 */
  __IO uint32_t GPR27;                             /**< GPR27 General Purpose Register, offset: 0x6C */
  __IO uint32_t GPR28;                             /**< GPR28 General Purpose Register, offset: 0x70 */
  __IO uint32_t GPR29;                             /**< GPR29 General Purpose Register, offset: 0x74 */
} IOMUXC_GPR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Register_Masks IOMUXC_GPR Register Masks
 * @{
 */

/*! @name GPR1 - GPR1 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_MASK      (0x7U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_SHIFT     (0U)
/*! SAI1_MCLK1_SEL - SAI1 MCLK1 source select
 *  0b000..ccm.ssi1_clk_root
 *  0b001..Reserved
 *  0b010..ccm.ssi3_clk_root
 *  0b011..iomux.sai1_ipg_clk_sai_mclk
 *  0b100..Reserved
 *  0b101..iomux.sai3_ipg_clk_sai_mclk
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_MASK      (0x38U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_SHIFT     (3U)
/*! SAI1_MCLK2_SEL - SAI1 MCLK2 source select
 *  0b000..ccm.ssi1_clk_root
 *  0b001..Reserved
 *  0b010..ccm.ssi3_clk_root
 *  0b011..iomux.sai1_ipg_clk_sai_mclk
 *  0b100..Reserved
 *  0b101..iomux.sai3_ipg_clk_sai_mclk
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_MASK      (0xC0U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_SHIFT     (6U)
/*! SAI1_MCLK3_SEL - SAI1 MCLK3 source select
 *  0b00..ccm.spdif0_clk_root
 *  0b01..SPDIF_EXT_CLK
 *  0b10..spdif.spdif_srclk
 *  0b11..spdif.spdif_outclock
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL_MASK)

#define IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_MASK      (0xC00U)
#define IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_SHIFT     (10U)
/*! SAI3_MCLK3_SEL - SAI3 MCLK3 source select
 *  0b00..ccm.spdif0_clk_root
 *  0b01..SPDIF_EXT_CLK
 *  0b10..spdif.spdif_srclk
 *  0b11..spdif.spdif_outclock
 */
#define IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_SHIFT)) & IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL_MASK)

#define IOMUXC_GPR_GPR1_GINT_MASK                (0x1000U)
#define IOMUXC_GPR_GPR1_GINT_SHIFT               (12U)
/*! GINT - Global Interrupt
 *  0b0..Global interrupt request is not asserted.
 *  0b1..Global interrupt request is asserted.
 */
#define IOMUXC_GPR_GPR1_GINT(x)                  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_GINT_SHIFT)) & IOMUXC_GPR_GPR1_GINT_MASK)

#define IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK       (0x80000U)
#define IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_SHIFT      (19U)
/*! SAI1_MCLK_DIR - sai1.MCLK signal direction control
 *  0b0..sai1.MCLK is input signal
 *  0b1..sai1.MCLK is output signal
 */
#define IOMUXC_GPR_GPR1_SAI1_MCLK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_MASK       (0x200000U)
#define IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_SHIFT      (21U)
/*! SAI3_MCLK_DIR - sai3.MCLK signal direction control
 *  0b0..sai3.MCLK is input signal
 *  0b1..sai3.MCLK is output signal
 */
#define IOMUXC_GPR_GPR1_SAI3_MCLK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_SHIFT)) & IOMUXC_GPR_GPR1_SAI3_MCLK_DIR_MASK)

#define IOMUXC_GPR_GPR1_EXC_MON_MASK             (0x400000U)
#define IOMUXC_GPR_GPR1_EXC_MON_SHIFT            (22U)
/*! EXC_MON - Exclusive monitor response select of illegal command
 *  0b0..OKAY response
 *  0b1..SLVError response
 */
#define IOMUXC_GPR_GPR1_EXC_MON(x)               (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_EXC_MON_SHIFT)) & IOMUXC_GPR_GPR1_EXC_MON_MASK)

#define IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_MASK   (0x80000000U)
#define IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_SHIFT  (31U)
/*! CM7_FORCE_HCLK_EN - Arm CM7 platform AHB clock enable
 *  0b0..AHB clock is not running (gated) when CM7 is sleeping and TCM is not accessible.
 *  0b1..AHB clock is running (enabled) when CM7 is sleeping and TCM is accessible.
 */
#define IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_SHIFT)) & IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN_MASK)
/*! @} */

/*! @name GPR2 - GPR2 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_MASK (0x8U)
#define IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_SHIFT (3U)
/*! AXBS_P_M0_HIGH_PRIORITY
 *  0b0..AXBS_P M0 master doesn't have high priority
 *  0b1..AXBS_P M0 master has high priority
 */
#define IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY_MASK)

#define IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_MASK (0x10U)
#define IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_SHIFT (4U)
/*! AXBS_P_M1_HIGH_PRIORITY
 *  0b0..AXBS_P M1 master does not have high priority
 *  0b1..AXBS_P M1 master has high priority
 */
#define IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY_MASK)

#define IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_MASK (0x20U)
#define IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_SHIFT (5U)
/*! AXBS_P_FORCE_ROUND_ROBIN
 *  0b0..AXBS_P masters are not arbitored in round robin, depending on M0/M1 master priority settings.
 *  0b1..AXBS_P masters are arbitored in round robin
 */
#define IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_SHIFT)) & IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN_MASK)

#define IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_MASK (0x1000U)
#define IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_SHIFT (12U)
/*! L2_MEM_EN_POWERSAVING - Enable power saving features on L2 memory
 *  0b0..Enters power saving mode only when chip is in SUSPEND mode
 *  0b1..Controlled by L2_MEM_DEEPSLEEP bitfield
 */
#define IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_SHIFT)) & IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING_MASK)

#define IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_MASK (0x2000U)
#define IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_SHIFT (13U)
/*! RAM_AUTO_CLK_GATING_EN
 *  0b0..disable automatically gate off RAM clock
 *  0b1..enable automatically gate off RAM clock
 */
#define IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_SHIFT)) & IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN_MASK)

#define IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_MASK    (0x4000U)
#define IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_SHIFT   (14U)
/*! L2_MEM_DEEPSLEEP
 *  0b0..No force sleep control supported, memory deep sleep mode only entered when whole system in stop mode (OCRAM in normal mode)
 *  0b1..Force memory into deep sleep mode (OCRAM in power saving mode)
 */
#define IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_SHIFT)) & IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP_MASK)

#define IOMUXC_GPR_GPR2_MQS_CLK_DIV_MASK         (0xFF0000U)
#define IOMUXC_GPR_GPR2_MQS_CLK_DIV_SHIFT        (16U)
/*! MQS_CLK_DIV
 *  0b00000000..mclk frequency = hmclk frequency
 *  0b00000001..mclk frequency = 1/2 * hmclk frequency
 *  0b00000010..mclk frequency = 1/3 * hmclk frequency
 *  0b11111111..mclk frequency = 1/256 * hmclk frequency
 */
#define IOMUXC_GPR_GPR2_MQS_CLK_DIV(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_CLK_DIV_SHIFT)) & IOMUXC_GPR_GPR2_MQS_CLK_DIV_MASK)

#define IOMUXC_GPR_GPR2_MQS_SW_RST_MASK          (0x1000000U)
#define IOMUXC_GPR_GPR2_MQS_SW_RST_SHIFT         (24U)
/*! MQS_SW_RST
 *  0b0..Exit software reset for MQS
 *  0b1..Enable software reset for MQS
 */
#define IOMUXC_GPR_GPR2_MQS_SW_RST(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_SW_RST_SHIFT)) & IOMUXC_GPR_GPR2_MQS_SW_RST_MASK)

#define IOMUXC_GPR_GPR2_MQS_EN_MASK              (0x2000000U)
#define IOMUXC_GPR_GPR2_MQS_EN_SHIFT             (25U)
/*! MQS_EN
 *  0b0..Disable MQS
 *  0b1..Enable MQS
 */
#define IOMUXC_GPR_GPR2_MQS_EN(x)                (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_EN_SHIFT)) & IOMUXC_GPR_GPR2_MQS_EN_MASK)

#define IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_MASK      (0x4000000U)
#define IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_SHIFT     (26U)
/*! MQS_OVERSAMPLE - Medium Quality Sound (MQS) Oversample
 *  0b0..32
 *  0b1..64
 */
#define IOMUXC_GPR_GPR2_MQS_OVERSAMPLE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_SHIFT)) & IOMUXC_GPR_GPR2_MQS_OVERSAMPLE_MASK)
/*! @} */

/*! @name GPR3 - GPR3 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR3_DCP_KEY_SEL_MASK         (0x10U)
#define IOMUXC_GPR_GPR3_DCP_KEY_SEL_SHIFT        (4U)
/*! DCP_KEY_SEL - Select 128-bit DCP key from 256-bit key from SNVS Master Key
 *  0b0..Select [127:0] from SNVS Master Key as DCP key
 *  0b1..Select [255:128] from SNVS Master Key as DCP key
 */
#define IOMUXC_GPR_GPR3_DCP_KEY_SEL(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_DCP_KEY_SEL_SHIFT)) & IOMUXC_GPR_GPR3_DCP_KEY_SEL_MASK)
/*! @} */

/*! @name GPR4 - GPR4 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR4_EDMA_STOP_REQ_MASK       (0x1U)
#define IOMUXC_GPR_GPR4_EDMA_STOP_REQ_SHIFT      (0U)
/*! EDMA_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_EDMA_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_EDMA_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_EDMA_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_TRNG_STOP_REQ_MASK       (0x8U)
#define IOMUXC_GPR_GPR4_TRNG_STOP_REQ_SHIFT      (3U)
/*! TRNG_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_TRNG_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_TRNG_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_TRNG_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_SAI1_STOP_REQ_MASK       (0x20U)
#define IOMUXC_GPR_GPR4_SAI1_STOP_REQ_SHIFT      (5U)
/*! SAI1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_SAI1_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_SAI1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_SAI3_STOP_REQ_MASK       (0x80U)
#define IOMUXC_GPR_GPR4_SAI3_STOP_REQ_SHIFT      (7U)
/*! SAI3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_SAI3_STOP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_SAI3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_PIT_STOP_REQ_MASK        (0x400U)
#define IOMUXC_GPR_GPR4_PIT_STOP_REQ_SHIFT       (10U)
/*! PIT_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_PIT_STOP_REQ(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_PIT_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_PIT_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_MASK    (0x800U)
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_SHIFT   (11U)
/*! FLEXSPI_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_MASK    (0x1000U)
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_SHIFT   (12U)
/*! FLEXIO1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR4_EDMA_STOP_ACK_MASK       (0x10000U)
#define IOMUXC_GPR_GPR4_EDMA_STOP_ACK_SHIFT      (16U)
/*! EDMA_STOP_ACK
 *  0b0..EDMA stop acknowledge is not asserted
 *  0b1..EDMA stop acknowledge is asserted (EDMA is in STOP mode).
 */
#define IOMUXC_GPR_GPR4_EDMA_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_EDMA_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_EDMA_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_TRNG_STOP_ACK_MASK       (0x80000U)
#define IOMUXC_GPR_GPR4_TRNG_STOP_ACK_SHIFT      (19U)
/*! TRNG_STOP_ACK
 *  0b0..TRNG stop acknowledge is not asserted
 *  0b1..TRNG stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_TRNG_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_TRNG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_TRNG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI1_STOP_ACK_MASK       (0x200000U)
#define IOMUXC_GPR_GPR4_SAI1_STOP_ACK_SHIFT      (21U)
/*! SAI1_STOP_ACK
 *  0b0..SAI1 stop acknowledge is not asserted
 *  0b1..SAI1 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_SAI1_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI3_STOP_ACK_MASK       (0x800000U)
#define IOMUXC_GPR_GPR4_SAI3_STOP_ACK_SHIFT      (23U)
/*! SAI3_STOP_ACK
 *  0b0..SAI3 stop acknowledge is not asserted
 *  0b1..SAI3 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_SAI3_STOP_ACK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_PIT_STOP_ACK_MASK        (0x4000000U)
#define IOMUXC_GPR_GPR4_PIT_STOP_ACK_SHIFT       (26U)
/*! PIT_STOP_ACK
 *  0b0..PIT stop acknowledge is not asserted
 *  0b1..PIT stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_PIT_STOP_ACK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_PIT_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_PIT_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_MASK    (0x8000000U)
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_SHIFT   (27U)
/*! FLEXSPI_STOP_ACK
 *  0b0..FLEXSPI stop acknowledge is not asserted
 *  0b1..FLEXSPI stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_MASK    (0x10000000U)
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_SHIFT   (28U)
/*! FLEXIO1_STOP_ACK
 *  0b0..FLEXIO1 stop acknowledge is not asserted
 *  0b1..FLEXIO1 stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK_MASK)
/*! @} */

/*! @name GPR5 - GPR5 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR5_WDOG1_MASK_MASK          (0x40U)
#define IOMUXC_GPR_GPR5_WDOG1_MASK_SHIFT         (6U)
/*! WDOG1_MASK
 *  0b0..WDOG1 Timeout behaves normally
 *  0b1..WDOG1 Timeout is masked
 */
#define IOMUXC_GPR_GPR5_WDOG1_MASK(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_WDOG1_MASK_SHIFT)) & IOMUXC_GPR_GPR5_WDOG1_MASK_MASK)

#define IOMUXC_GPR_GPR5_WDOG2_MASK_MASK          (0x80U)
#define IOMUXC_GPR_GPR5_WDOG2_MASK_SHIFT         (7U)
/*! WDOG2_MASK
 *  0b0..WDOG2 Timeout behaves normally
 *  0b1..WDOG2 Timeout is masked
 */
#define IOMUXC_GPR_GPR5_WDOG2_MASK(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_WDOG2_MASK_SHIFT)) & IOMUXC_GPR_GPR5_WDOG2_MASK_MASK)

#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_MASK    (0x10000000U)
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_SHIFT   (28U)
/*! VREF_1M_CLK_GPT1
 *  0b0..GPT1 ipg_clk_highfreq driven by IPG_PERCLK
 *  0b1..GPT1 ipg_clk_highfreq driven by anatop 1 MHz clock
 */
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_SHIFT)) & IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1_MASK)

#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_MASK    (0x20000000U)
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_SHIFT   (29U)
/*! VREF_1M_CLK_GPT2
 *  0b0..GPT2 ipg_clk_highfreq driven by IPG_PERCLK
 *  0b1..GPT2 ipg_clk_highfreq driven by anatop 1 MHz clock
 */
#define IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_SHIFT)) & IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2_MASK)
/*! @} */

/*! @name GPR6 - GPR6 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_2_MASK (0x10000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_2_SHIFT (16U)
/*! IOMUXC_XBAR_DIR_SEL_2
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_2(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_2_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_2_MASK)

#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_3_MASK (0x20000U)
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_3_SHIFT (17U)
/*! IOMUXC_XBAR_DIR_SEL_3
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_3(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_3_SHIFT)) & IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_3_MASK)
/*! @} */

/*! @name GPR7 - GPR7 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_MASK     (0x1U)
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_SHIFT    (0U)
/*! LPI2C1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_MASK     (0x2U)
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_SHIFT    (1U)
/*! LPI2C2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_MASK     (0x10U)
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_SHIFT    (4U)
/*! LPSPI1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_MASK     (0x20U)
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_SHIFT    (5U)
/*! LPSPI2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_MASK    (0x100U)
#define IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_SHIFT   (8U)
/*! LPUART1_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART1_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART1_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_MASK    (0x200U)
#define IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_SHIFT   (9U)
/*! LPUART2_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART2_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART2_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_MASK    (0x400U)
#define IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_SHIFT   (10U)
/*! LPUART3_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART3_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART3_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_MASK    (0x800U)
#define IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_SHIFT   (11U)
/*! LPUART4_STOP_REQ
 *  0b0..stop request off
 *  0b1..stop request on
 */
#define IOMUXC_GPR_GPR7_LPUART4_STOP_REQ(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_SHIFT)) & IOMUXC_GPR_GPR7_LPUART4_STOP_REQ_MASK)

#define IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_MASK     (0x10000U)
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_SHIFT    (16U)
/*! LPI2C1_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted (the module is in Stop mode)
 */
#define IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_MASK     (0x20000U)
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_SHIFT    (17U)
/*! LPI2C2_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_MASK     (0x100000U)
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_SHIFT    (20U)
/*! LPSPI1_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_MASK     (0x200000U)
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_SHIFT    (21U)
/*! LPSPI2_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_MASK    (0x1000000U)
#define IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_SHIFT   (24U)
/*! LPUART1_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART1_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART1_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_MASK    (0x2000000U)
#define IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_SHIFT   (25U)
/*! LPUART2_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART2_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART2_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_MASK    (0x4000000U)
#define IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_SHIFT   (26U)
/*! LPUART3_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART3_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART3_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_MASK    (0x8000000U)
#define IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_SHIFT   (27U)
/*! LPUART4_STOP_ACK
 *  0b0..stop acknowledge is not asserted
 *  0b1..stop acknowledge is asserted
 */
#define IOMUXC_GPR_GPR7_LPUART4_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR7_LPUART4_STOP_ACK_MASK)
/*! @} */

/*! @name GPR8 - GPR8 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_MASK (0x1U)
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_SHIFT (0U)
/*! LPI2C1_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_MASK     (0x2U)
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_SHIFT    (1U)
/*! LPI2C1_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_MASK (0x4U)
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_SHIFT (2U)
/*! LPI2C2_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_MASK     (0x8U)
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_SHIFT    (3U)
/*! LPI2C2_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_MASK (0x100U)
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_SHIFT (8U)
/*! LPSPI1_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_MASK     (0x200U)
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_SHIFT    (9U)
/*! LPSPI1_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_MASK (0x400U)
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_SHIFT (10U)
/*! LPSPI2_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_MASK     (0x800U)
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_SHIFT    (11U)
/*! LPSPI2_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_MASK (0x10000U)
#define IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_SHIFT (16U)
/*! LPUART1_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_MASK    (0x20000U)
#define IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_SHIFT   (17U)
/*! LPUART1_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_MASK (0x40000U)
#define IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_SHIFT (18U)
/*! LPUART2_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_MASK    (0x80000U)
#define IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_SHIFT   (19U)
/*! LPUART2_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_MASK (0x100000U)
#define IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_SHIFT (20U)
/*! LPUART3_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_MASK    (0x200000U)
#define IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_SHIFT   (21U)
/*! LPUART3_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE_MASK)

#define IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_MASK (0x400000U)
#define IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_SHIFT (22U)
/*! LPUART4_IPG_STOP_MODE
 *  0b0..the module is functional in Stop mode
 *  0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
 */
#define IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_MASK    (0x800000U)
#define IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_SHIFT   (23U)
/*! LPUART4_IPG_DOZE
 *  0b0..not in doze mode
 *  0b1..in doze mode
 */
#define IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE_MASK)
/*! @} */

/*! @name GPR10 - GPR10 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR10_NIDEN_MASK              (0x1U)
#define IOMUXC_GPR_GPR10_NIDEN_SHIFT             (0U)
/*! NIDEN
 *  0b0..Debug turned off.
 *  0b1..Debug enabled (default).
 */
#define IOMUXC_GPR_GPR10_NIDEN(x)                (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_NIDEN_SHIFT)) & IOMUXC_GPR_GPR10_NIDEN_MASK)

#define IOMUXC_GPR_GPR10_DBG_EN_MASK             (0x2U)
#define IOMUXC_GPR_GPR10_DBG_EN_SHIFT            (1U)
/*! DBG_EN
 *  0b0..Debug turned off.
 *  0b1..Debug enabled (default).
 */
#define IOMUXC_GPR_GPR10_DBG_EN(x)               (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_DBG_EN_SHIFT)) & IOMUXC_GPR_GPR10_DBG_EN_MASK)

#define IOMUXC_GPR_GPR10_SEC_ERR_RESP_MASK       (0x4U)
#define IOMUXC_GPR_GPR10_SEC_ERR_RESP_SHIFT      (2U)
/*! SEC_ERR_RESP
 *  0b0..OKEY response
 *  0b1..SLVError (default)
 */
#define IOMUXC_GPR_GPR10_SEC_ERR_RESP(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_SEC_ERR_RESP_SHIFT)) & IOMUXC_GPR_GPR10_SEC_ERR_RESP_MASK)

#define IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_MASK (0x10U)
#define IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_SHIFT (4U)
/*! DCPKEY_OCOTP_OR_KEYMUX
 *  0b0..Select key from SNVS Master Key.
 *  0b1..Select key from OCOTP (SW_GP2).
 */
#define IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_SHIFT)) & IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX_MASK)

#define IOMUXC_GPR_GPR10_OCRAM_TZ_EN_MASK        (0x100U)
#define IOMUXC_GPR_GPR10_OCRAM_TZ_EN_SHIFT       (8U)
/*! OCRAM_TZ_EN
 *  0b0..The TrustZone feature is disabled. Entire OCRAM space is available for all access types (secure/non-secure/user/supervisor).
 *  0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
 *       the execution mode access policy described in CSU chapter.
 */
#define IOMUXC_GPR_GPR10_OCRAM_TZ_EN(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_OCRAM_TZ_EN_SHIFT)) & IOMUXC_GPR_GPR10_OCRAM_TZ_EN_MASK)

#define IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_MASK      (0x3E00U)
#define IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_SHIFT     (9U)
#define IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_SHIFT)) & IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR_MASK)

#define IOMUXC_GPR_GPR10_LOCK_NIDEN_MASK         (0x10000U)
#define IOMUXC_GPR_GPR10_LOCK_NIDEN_SHIFT        (16U)
/*! LOCK_NIDEN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_NIDEN(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_NIDEN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_NIDEN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_DBG_EN_MASK        (0x20000U)
#define IOMUXC_GPR_GPR10_LOCK_DBG_EN_SHIFT       (17U)
/*! LOCK_DBG_EN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_DBG_EN(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_DBG_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_DBG_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_MASK  (0x40000U)
#define IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_SHIFT (18U)
/*! LOCK_SEC_ERR_RESP
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP_MASK)

#define IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_MASK (0x100000U)
#define IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_SHIFT (20U)
/*! LOCK_DCPKEY_OCOTP_OR_KEYMUX
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX_MASK)

#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_MASK   (0x1000000U)
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_SHIFT  (24U)
/*! LOCK_OCRAM_TZ_EN
 *  0b0..Field is not locked
 *  0b1..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_MASK (0x3E000000U)
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_SHIFT (25U)
/*! LOCK_OCRAM_TZ_ADDR
 *  0b00000..Field is not locked
 *  0b00001..Field is locked (read access only)
 */
#define IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR_MASK)
/*! @} */

/*! @name GPR11 - GPR11 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_MASK  (0x3U)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_SHIFT (0U)
/*! M7_APC_AC_R0_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL_MASK)

#define IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_MASK  (0xCU)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_SHIFT (2U)
/*! M7_APC_AC_R1_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL_MASK)

#define IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_MASK  (0x30U)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_SHIFT (4U)
/*! M7_APC_AC_R2_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL_MASK)

#define IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_MASK  (0xC0U)
#define IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_SHIFT (6U)
/*! M7_APC_AC_R3_CTRL
 *  0b00..No access protection
 *  0b01..M7 debug protection enabled
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL_MASK)

#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R0_CTRL_MASK (0x30000U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R0_CTRL_SHIFT (16U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R0_CTRL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R0_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R0_CTRL_MASK)

#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R1_CTRL_MASK (0xC0000U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R1_CTRL_SHIFT (18U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R1_CTRL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R1_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R1_CTRL_MASK)

#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R2_CTRL_MASK (0x300000U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R2_CTRL_SHIFT (20U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R2_CTRL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R2_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R2_CTRL_MASK)

#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R3_CTRL_MASK (0xC00000U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R3_CTRL_SHIFT (22U)
#define IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R3_CTRL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R3_CTRL_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_M7_APC_AC_R3_CTRL_MASK)
/*! @} */

/*! @name GPR12 - GPR12 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_MASK (0x1U)
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_SHIFT (0U)
/*! FLEXIO1_IPG_STOP_MODE
 *  0b0..FlexIO1 is functional in Stop mode.
 *  0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO1 is not functional in Stop mode.
 */
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE_MASK)

#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_MASK   (0x2U)
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_SHIFT  (1U)
/*! FLEXIO1_IPG_DOZE
 *  0b0..FLEXIO1 is not in doze mode
 *  0b1..FLEXIO1 is in doze mode
 */
#define IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_SHIFT)) & IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE_MASK)
/*! @} */

/*! @name GPR13 - GPR13 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR13_CACHE_USB_MASK          (0x2000U)
#define IOMUXC_GPR_GPR13_CACHE_USB_SHIFT         (13U)
/*! CACHE_USB
 *  0b0..Cacheable attribute is off for read/write transactions.
 *  0b1..Cacheable attribute is on for read/write transactions.
 */
#define IOMUXC_GPR_GPR13_CACHE_USB(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_CACHE_USB_SHIFT)) & IOMUXC_GPR_GPR13_CACHE_USB_MASK)
/*! @} */

/*! @name GPR16 - GPR16 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_MASK (0x4U)
#define IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_SHIFT (2U)
/*! FLEXRAM_BANK_CFG_SEL
 *  0b0..use fuse value to config
 *  0b1..use FLEXRAM_BANK_CFG to config
 */
#define IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_SHIFT)) & IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL_MASK)

#define IOMUXC_GPR_GPR16_LOCK_VTOR_MASK          (0x40U)
#define IOMUXC_GPR_GPR16_LOCK_VTOR_SHIFT         (6U)
/*! LOCK_VTOR
 *  0b0..CM7_INIT_VTOR field is not locked.
 *  0b1..CM7_INIT_VTOR field is locked (read access only).
 */
#define IOMUXC_GPR_GPR16_LOCK_VTOR(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR16_LOCK_VTOR_SHIFT)) & IOMUXC_GPR_GPR16_LOCK_VTOR_MASK)

#define IOMUXC_GPR_GPR16_CM7_INIT_VTOR_MASK      (0xFFFFFF80U)
#define IOMUXC_GPR_GPR16_CM7_INIT_VTOR_SHIFT     (7U)
#define IOMUXC_GPR_GPR16_CM7_INIT_VTOR(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR16_CM7_INIT_VTOR_SHIFT)) & IOMUXC_GPR_GPR16_CM7_INIT_VTOR_MASK)
/*! @} */

/*! @name GPR17 - GPR17 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_MASK   (0xFFU)
#define IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_SHIFT  (0U)
/*! FLEXRAM_BANK_CFG - FlexRAM bank config value */
#define IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_SHIFT)) & IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG_MASK)
/*! @} */

/*! @name GPR18 - GPR18 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R0_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_SHIFT)) & IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT_MASK)

#define IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_SHIFT)) & IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT_MASK)
/*! @} */

/*! @name GPR19 - GPR19 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R0_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_SHIFT)) & IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP_MASK)

#define IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_SHIFT)) & IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP_MASK)
/*! @} */

/*! @name GPR20 - GPR20 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R1_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_SHIFT)) & IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT_MASK)

#define IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_SHIFT)) & IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT_MASK)
/*! @} */

/*! @name GPR21 - GPR21 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R1_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_SHIFT)) & IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP_MASK)

#define IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_SHIFT)) & IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP_MASK)
/*! @} */

/*! @name GPR22 - GPR22 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R2_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_SHIFT)) & IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT_MASK)

#define IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_SHIFT)) & IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT_MASK)
/*! @} */

/*! @name GPR23 - GPR23 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R2_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_SHIFT)) & IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP_MASK)

#define IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_SHIFT)) & IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP_MASK)
/*! @} */

/*! @name GPR24 - GPR24 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_MASK (0x1U)
#define IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_SHIFT (0U)
/*! LOCK_M7_APC_AC_R3_BOT
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_SHIFT)) & IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT_MASK)

#define IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_SHIFT  (3U)
#define IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_SHIFT)) & IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT_MASK)
/*! @} */

/*! @name GPR25 - GPR25 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_MASK (0x1U)
#define IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_SHIFT (0U)
/*! LOCK_M7_APC_AC_R3_TOP
 *  0b0..Register field [31:1] is not locked
 *  0b1..Register field [31:1] is locked (read access only)
 */
#define IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_SHIFT)) & IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP_MASK)

#define IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_MASK   (0xFFFFFFF8U)
#define IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_SHIFT  (3U)
#define IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_SHIFT)) & IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP_MASK)
/*! @} */

/*! @name GPR26 - GPR26 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR26_GPIO_SEL_MASK           (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR26_GPIO_SEL_SHIFT          (0U)
#define IOMUXC_GPR_GPR26_GPIO_SEL(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR26_GPIO_SEL_SHIFT)) & IOMUXC_GPR_GPR26_GPIO_SEL_MASK)
/*! @} */

/*! @name GPR27 - GPR27 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR27_FLEXSPI_REMAP_ADDR_START_MASK (0xFFFFF000U)
#define IOMUXC_GPR_GPR27_FLEXSPI_REMAP_ADDR_START_SHIFT (12U)
#define IOMUXC_GPR_GPR27_FLEXSPI_REMAP_ADDR_START(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR27_FLEXSPI_REMAP_ADDR_START_SHIFT)) & IOMUXC_GPR_GPR27_FLEXSPI_REMAP_ADDR_START_MASK)
/*! @} */

/*! @name GPR28 - GPR28 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR28_FLEXSPI_REMAP_ADDR_END_MASK (0xFFFFF000U)
#define IOMUXC_GPR_GPR28_FLEXSPI_REMAP_ADDR_END_SHIFT (12U)
#define IOMUXC_GPR_GPR28_FLEXSPI_REMAP_ADDR_END(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR28_FLEXSPI_REMAP_ADDR_END_SHIFT)) & IOMUXC_GPR_GPR28_FLEXSPI_REMAP_ADDR_END_MASK)
/*! @} */

/*! @name GPR29 - GPR29 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR29_FLEXSPI_REMAP_ADDR_OFFSET_MASK (0xFFFFF000U)
#define IOMUXC_GPR_GPR29_FLEXSPI_REMAP_ADDR_OFFSET_SHIFT (12U)
#define IOMUXC_GPR_GPR29_FLEXSPI_REMAP_ADDR_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR29_FLEXSPI_REMAP_ADDR_OFFSET_SHIFT)) & IOMUXC_GPR_GPR29_FLEXSPI_REMAP_ADDR_OFFSET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_IOMUXC_GPR_H_ */

