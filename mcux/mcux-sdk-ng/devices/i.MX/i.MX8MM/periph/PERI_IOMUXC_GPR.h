/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC_GPR.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC_GPR
 *
 * CMSIS Peripheral Access Layer for IOMUXC_GPR
 */

#if !defined(PERI_IOMUXC_GPR_H_)
#define PERI_IOMUXC_GPR_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- IOMUXC_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Peripheral_Access_Layer IOMUXC_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_GPR - Size of Registers Arrays */
#define IOMUXC_GPR_GPR_COUNT                      25u

/** IOMUXC_GPR - Register Layout Typedef */
typedef struct {
       uint32_t GPR0;                              /**< General Purpose Register 0, offset: 0x0 */
  __IO uint32_t GPR1;                              /**< General Purpose Register 1, offset: 0x4 */
  __IO uint32_t GPR2;                              /**< General Purpose Register 2, offset: 0x8 */
  __IO uint32_t GPR3;                              /**< General Purpose Register 3, offset: 0xC */
  __IO uint32_t GPR4;                              /**< General Purpose Register 4, offset: 0x10 */
  __IO uint32_t GPR5;                              /**< General Purpose Register 5, offset: 0x14 */
  __IO uint32_t GPR6;                              /**< General Purpose Register 6, offset: 0x18 */
  __IO uint32_t GPR7;                              /**< General Purpose Register 7, offset: 0x1C */
  __IO uint32_t GPR8;                              /**< General Purpose Register 8, offset: 0x20 */
       uint32_t GPR9;                              /**< General Purpose Register 9, offset: 0x24 */
  __IO uint32_t GPR10;                             /**< General Purpose Register 10, offset: 0x28 */
  __IO uint32_t GPR11;                             /**< General Purpose Register 11, offset: 0x2C */
  __IO uint32_t GPR12;                             /**< General Purpose Register 12, offset: 0x30 */
  __IO uint32_t GPR13;                             /**< General Purpose Register 13, offset: 0x34 */
  __IO uint32_t GPR14;                             /**< General Purpose Register 14, offset: 0x38 */
       uint32_t GPR15;                             /**< General Purpose Register 15, offset: 0x3C */
       uint32_t GPR16;                             /**< General Purpose Register 16, offset: 0x40 */
       uint32_t GPR17;                             /**< General Purpose Register 17, offset: 0x44 */
       uint32_t GPR18;                             /**< General Purpose Register 18, offset: 0x48 */
  __I  uint32_t GPR19;                             /**< General Purpose Register 19, offset: 0x4C */
       uint32_t GPR20;                             /**< General Purpose Register 20, offset: 0x50 */
       uint32_t GPR21;                             /**< General Purpose Register 21, offset: 0x54 */
  __I  uint32_t GPR22;                             /**< General Purpose Register 22, offset: 0x58 */
       uint32_t GPR[IOMUXC_GPR_GPR_COUNT];         /**< General Purpose Register, array offset: 0x5C, array step: 0x4 */
} IOMUXC_GPR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Register_Masks IOMUXC_GPR Register Masks
 * @{
 */

/*! @name GPR1 - General Purpose Register 1 */
/*! @{ */

#define IOMUXC_GPR_GPR1_GPR_IRQ_MASK             (0x1000U)
#define IOMUXC_GPR_GPR1_GPR_IRQ_SHIFT            (12U)
#define IOMUXC_GPR_GPR1_GPR_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_GPR_IRQ_SHIFT)) & IOMUXC_GPR_GPR1_GPR_IRQ_MASK)

#define IOMUXC_GPR_GPR1_GPR_ENET1_TX_CLK_SEL_MASK (0x2000U)
#define IOMUXC_GPR_GPR1_GPR_ENET1_TX_CLK_SEL_SHIFT (13U)
/*! GPR_ENET1_TX_CLK_SEL
 *  0b0..ENET1 RMII clock comes from external PHY or OSC
 *  0b1..ENET1 RMII clock comes from CCM->pad->loopback. SOI bit for the pad (IOMUXC_SW_INPUT_ON_PAD_ENET_TD2) should be set also.
 */
#define IOMUXC_GPR_GPR1_GPR_ENET1_TX_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_GPR_ENET1_TX_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR1_GPR_ENET1_TX_CLK_SEL_MASK)

#define IOMUXC_GPR_GPR1_GPR_TZASC1_SECURE_BOOT_LOCK_MASK (0x800000U)
#define IOMUXC_GPR_GPR1_GPR_TZASC1_SECURE_BOOT_LOCK_SHIFT (23U)
#define IOMUXC_GPR_GPR1_GPR_TZASC1_SECURE_BOOT_LOCK(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_GPR_TZASC1_SECURE_BOOT_LOCK_SHIFT)) & IOMUXC_GPR_GPR1_GPR_TZASC1_SECURE_BOOT_LOCK_MASK)

#define IOMUXC_GPR_GPR1_GPR_DBG_ACK_MASK         (0xF0000000U)
#define IOMUXC_GPR_GPR1_GPR_DBG_ACK_SHIFT        (28U)
#define IOMUXC_GPR_GPR1_GPR_DBG_ACK(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR1_GPR_DBG_ACK_SHIFT)) & IOMUXC_GPR_GPR1_GPR_DBG_ACK_MASK)
/*! @} */

/*! @name GPR2 - General Purpose Register 2 */
/*! @{ */

#define IOMUXC_GPR_GPR2_GPR_SAI1_EXT_MCLK_EN_MASK (0x1U)
#define IOMUXC_GPR_GPR2_GPR_SAI1_EXT_MCLK_EN_SHIFT (0U)
#define IOMUXC_GPR_GPR2_GPR_SAI1_EXT_MCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_SAI1_EXT_MCLK_EN_SHIFT)) & IOMUXC_GPR_GPR2_GPR_SAI1_EXT_MCLK_EN_MASK)

#define IOMUXC_GPR_GPR2_GPR_SAI2_EXT_MCLK_EN_MASK (0x2U)
#define IOMUXC_GPR_GPR2_GPR_SAI2_EXT_MCLK_EN_SHIFT (1U)
#define IOMUXC_GPR_GPR2_GPR_SAI2_EXT_MCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_SAI2_EXT_MCLK_EN_SHIFT)) & IOMUXC_GPR_GPR2_GPR_SAI2_EXT_MCLK_EN_MASK)

#define IOMUXC_GPR_GPR2_GPR_SAI3_EXT_MCLK_EN_MASK (0x4U)
#define IOMUXC_GPR_GPR2_GPR_SAI3_EXT_MCLK_EN_SHIFT (2U)
#define IOMUXC_GPR_GPR2_GPR_SAI3_EXT_MCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_SAI3_EXT_MCLK_EN_SHIFT)) & IOMUXC_GPR_GPR2_GPR_SAI3_EXT_MCLK_EN_MASK)

#define IOMUXC_GPR_GPR2_GPR_SAI5_EXT_MCLK_EN_MASK (0x10U)
#define IOMUXC_GPR_GPR2_GPR_SAI5_EXT_MCLK_EN_SHIFT (4U)
#define IOMUXC_GPR_GPR2_GPR_SAI5_EXT_MCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_SAI5_EXT_MCLK_EN_SHIFT)) & IOMUXC_GPR_GPR2_GPR_SAI5_EXT_MCLK_EN_MASK)

#define IOMUXC_GPR_GPR2_GPR_SAI6_EXT_MCLK_EN_MASK (0x20U)
#define IOMUXC_GPR_GPR2_GPR_SAI6_EXT_MCLK_EN_SHIFT (5U)
#define IOMUXC_GPR_GPR2_GPR_SAI6_EXT_MCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_SAI6_EXT_MCLK_EN_SHIFT)) & IOMUXC_GPR_GPR2_GPR_SAI6_EXT_MCLK_EN_MASK)

#define IOMUXC_GPR_GPR2_GPR_GPT4_EXT_CLK_SEL_MASK (0xF00U)
#define IOMUXC_GPR_GPR2_GPR_GPT4_EXT_CLK_SEL_SHIFT (8U)
/*! GPR_GPT4_EXT_CLK_SEL
 *  0b0000..SAI1_TX_SYNC
 *  0b0001..SAI2_TX_SYNC
 *  0b0010..SAI3_TX_SYNC
 *  0b0011..Reserved
 *  0b0100..SAI5_TX_SYNC
 *  0b0101..SAI6_TX_SYNC
 *  0b0110..SAI1_RX_SYNC
 *  0b0111..SAI2_RX_SYNC
 *  0b1000..SAI3_RX_SYNC
 *  0b1001..Reserved
 *  0b1010..SAI5_RX_SYNC
 */
#define IOMUXC_GPR_GPR2_GPR_GPT4_EXT_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_GPT4_EXT_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR2_GPR_GPT4_EXT_CLK_SEL_MASK)

#define IOMUXC_GPR_GPR2_GPR_GPT5_EXT_CLK_SEL_MASK (0xF000U)
#define IOMUXC_GPR_GPR2_GPR_GPT5_EXT_CLK_SEL_SHIFT (12U)
/*! GPR_GPT5_EXT_CLK_SEL
 *  0b0000..SAI1_TX_SYNC
 *  0b0001..SAI2_TX_SYNC
 *  0b0010..SAI3_TX_SYNC
 *  0b0011..Reserved
 *  0b0100..SAI5_TX_SYNC
 *  0b0101..SAI6_TX_SYNC
 *  0b0110..SAI1_RX_SYNC
 *  0b0111..SAI2_RX_SYNC
 *  0b1000..SAI3_RX_SYNC
 *  0b1001..Reserved
 *  0b1010..SAI5_RX_SYNC
 */
#define IOMUXC_GPR_GPR2_GPR_GPT5_EXT_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_GPT5_EXT_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR2_GPR_GPT5_EXT_CLK_SEL_MASK)

#define IOMUXC_GPR_GPR2_GPR_GPT6_EXT_CLK_SEL_MASK (0xF0000U)
#define IOMUXC_GPR_GPR2_GPR_GPT6_EXT_CLK_SEL_SHIFT (16U)
/*! GPR_GPT6_EXT_CLK_SEL
 *  0b0000..SAI1_TX_SYNC
 *  0b0001..SAI2_TX_SYNC
 *  0b0010..SAI3_TX_SYNC
 *  0b0011..Reserved
 *  0b0100..SAI5_TX_SYNC
 *  0b0101..SAI6_TX_SYNC
 *  0b0110..SAI1_RX_SYNC
 *  0b0111..SAI2_RX_SYNC
 *  0b1000..SAI3_RX_SYNC
 *  0b1001..Reserved
 *  0b1010..SAI5_RX_SYNC
 */
#define IOMUXC_GPR_GPR2_GPR_GPT6_EXT_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR2_GPR_GPT6_EXT_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR2_GPR_GPT6_EXT_CLK_SEL_MASK)
/*! @} */

/*! @name GPR3 - General Purpose Register 3 */
/*! @{ */

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_DATA_WAIT_EN_MASK (0x1U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_DATA_WAIT_EN_SHIFT (0U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_DATA_WAIT_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_DATA_WAIT_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_DATA_WAIT_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_ADDR_PIPELINE_EN_MASK (0x2U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_ADDR_PIPELINE_EN_SHIFT (1U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_ADDR_PIPELINE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_ADDR_PIPELINE_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_READ_ADDR_PIPELINE_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_DATA_PIPELINE_EN_MASK (0x4U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_DATA_PIPELINE_EN_SHIFT (2U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_DATA_PIPELINE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_DATA_PIPELINE_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_DATA_PIPELINE_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_ADDR_PIPELINE_EN_MASK (0x8U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_ADDR_PIPELINE_EN_SHIFT (3U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_ADDR_PIPELINE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_ADDR_PIPELINE_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_WRITE_ADDR_PIPELINE_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_DATA_WAIT_EN_MASK (0x10U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_DATA_WAIT_EN_SHIFT (4U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_DATA_WAIT_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_DATA_WAIT_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_DATA_WAIT_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_ADDR_PIPELINE_EN_MASK (0x20U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_ADDR_PIPELINE_EN_SHIFT (5U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_ADDR_PIPELINE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_ADDR_PIPELINE_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_S_READ_ADDR_PIPELINE_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_DATA_PIPELINE_EN_MASK (0x40U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_DATA_PIPELINE_EN_SHIFT (6U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_DATA_PIPELINE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_DATA_PIPELINE_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_DATA_PIPELINE_EN_MASK)

#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_ADDR_PIPELINE_EN_MASK (0x80U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_ADDR_PIPELINE_EN_SHIFT (7U)
#define IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_ADDR_PIPELINE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_ADDR_PIPELINE_EN_SHIFT)) & IOMUXC_GPR_GPR3_OCRAM_CTRL_S_WRITE_ADDR_PIPELINE_EN_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_read_data_wait_en_pndg_MASK (0x10000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_read_data_wait_en_pndg_SHIFT (16U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_read_data_wait_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_read_data_wait_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_read_data_wait_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_read_addr_pipeline_en_pndg_MASK (0x20000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_read_addr_pipeline_en_pndg_SHIFT (17U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_read_addr_pipeline_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_read_addr_pipeline_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_read_addr_pipeline_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_write_data_pipeline_en_pndg_MASK (0x40000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_write_data_pipeline_en_pndg_SHIFT (18U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_write_data_pipeline_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_write_data_pipeline_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_write_data_pipeline_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_write_addr_pipeline_en_pndg_MASK (0x80000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_write_addr_pipeline_en_pndg_SHIFT (19U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_write_addr_pipeline_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_write_addr_pipeline_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_write_addr_pipeline_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_s_read_data_wait_en_pndg_MASK (0x100000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_read_data_wait_en_pndg_SHIFT (20U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_read_data_wait_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_s_read_data_wait_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_s_read_data_wait_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_s_read_addr_pipeline_en_pndg_MASK (0x200000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_read_addr_pipeline_en_pndg_SHIFT (21U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_read_addr_pipeline_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_s_read_addr_pipeline_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_s_read_addr_pipeline_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_s_write_data_pipeline_en_pndg_MASK (0x400000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_write_data_pipeline_en_pndg_SHIFT (22U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_write_data_pipeline_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_s_write_data_pipeline_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_s_write_data_pipeline_en_pndg_MASK)

#define IOMUXC_GPR_GPR3_ocram_ctrl_s_write_addr_pipeline_en_pndg_MASK (0x800000U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_write_addr_pipeline_en_pndg_SHIFT (23U)
#define IOMUXC_GPR_GPR3_ocram_ctrl_s_write_addr_pipeline_en_pndg(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR3_ocram_ctrl_s_write_addr_pipeline_en_pndg_SHIFT)) & IOMUXC_GPR_GPR3_ocram_ctrl_s_write_addr_pipeline_en_pndg_MASK)
/*! @} */

/*! @name GPR4 - General Purpose Register 4 */
/*! @{ */

#define IOMUXC_GPR_GPR4_GPR_SDMA1_IPG_STOP_MASK  (0x1U)
#define IOMUXC_GPR_GPR4_GPR_SDMA1_IPG_STOP_SHIFT (0U)
#define IOMUXC_GPR_GPR4_GPR_SDMA1_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_GPR_SDMA1_IPG_STOP_SHIFT)) & IOMUXC_GPR_GPR4_GPR_SDMA1_IPG_STOP_MASK)

#define IOMUXC_GPR_GPR4_GPR_ENET1_IPG_STOP_MASK  (0x8U)
#define IOMUXC_GPR_GPR4_GPR_ENET1_IPG_STOP_SHIFT (3U)
#define IOMUXC_GPR_GPR4_GPR_ENET1_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_GPR_ENET1_IPG_STOP_SHIFT)) & IOMUXC_GPR_GPR4_GPR_ENET1_IPG_STOP_MASK)

#define IOMUXC_GPR_GPR4_GPR_SDMA2_IPG_STOP_MASK  (0x10U)
#define IOMUXC_GPR_GPR4_GPR_SDMA2_IPG_STOP_SHIFT (4U)
#define IOMUXC_GPR_GPR4_GPR_SDMA2_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_GPR_SDMA2_IPG_STOP_SHIFT)) & IOMUXC_GPR_GPR4_GPR_SDMA2_IPG_STOP_MASK)

#define IOMUXC_GPR_GPR4_GPR_SDMA3_IPG_STOP_MASK  (0x1000U)
#define IOMUXC_GPR_GPR4_GPR_SDMA3_IPG_STOP_SHIFT (12U)
#define IOMUXC_GPR_GPR4_GPR_SDMA3_IPG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_GPR_SDMA3_IPG_STOP_SHIFT)) & IOMUXC_GPR_GPR4_GPR_SDMA3_IPG_STOP_MASK)

#define IOMUXC_GPR_GPR4_SDMA1_IPG_STOP_ACK_MASK  (0x10000U)
#define IOMUXC_GPR_GPR4_SDMA1_IPG_STOP_ACK_SHIFT (16U)
#define IOMUXC_GPR_GPR4_SDMA1_IPG_STOP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SDMA1_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SDMA1_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SDMA3_IPG_STOP_ACK_MASK  (0x40000U)
#define IOMUXC_GPR_GPR4_SDMA3_IPG_STOP_ACK_SHIFT (18U)
#define IOMUXC_GPR_GPR4_SDMA3_IPG_STOP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SDMA3_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SDMA3_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_ENET1_IPG_STOP_ACK_MASK  (0x80000U)
#define IOMUXC_GPR_GPR4_ENET1_IPG_STOP_ACK_SHIFT (19U)
#define IOMUXC_GPR_GPR4_ENET1_IPG_STOP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_ENET1_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_ENET1_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SDMA2_IPG_STOP_ACK_MASK  (0x100000U)
#define IOMUXC_GPR_GPR4_SDMA2_IPG_STOP_ACK_SHIFT (20U)
#define IOMUXC_GPR_GPR4_SDMA2_IPG_STOP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SDMA2_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SDMA2_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI1_IPG_STOP_ACK_MASK   (0x200000U)
#define IOMUXC_GPR_GPR4_SAI1_IPG_STOP_ACK_SHIFT  (21U)
#define IOMUXC_GPR_GPR4_SAI1_IPG_STOP_ACK(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI1_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI1_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI2_IPG_STOP_ACK_MASK   (0x400000U)
#define IOMUXC_GPR_GPR4_SAI2_IPG_STOP_ACK_SHIFT  (22U)
#define IOMUXC_GPR_GPR4_SAI2_IPG_STOP_ACK(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI2_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI2_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI3_IPG_STOP_ACK_MASK   (0x800000U)
#define IOMUXC_GPR_GPR4_SAI3_IPG_STOP_ACK_SHIFT  (23U)
#define IOMUXC_GPR_GPR4_SAI3_IPG_STOP_ACK(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI3_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI3_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI5_IPG_STOP_ACK_MASK   (0x2000000U)
#define IOMUXC_GPR_GPR4_SAI5_IPG_STOP_ACK_SHIFT  (25U)
#define IOMUXC_GPR_GPR4_SAI5_IPG_STOP_ACK(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI5_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI5_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_SAI6_IPG_STOP_ACK_MASK   (0x4000000U)
#define IOMUXC_GPR_GPR4_SAI6_IPG_STOP_ACK_SHIFT  (26U)
#define IOMUXC_GPR_GPR4_SAI6_IPG_STOP_ACK(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_SAI6_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_SAI6_IPG_STOP_ACK_MASK)

#define IOMUXC_GPR_GPR4_PDM_IPG_STOP_ACK_MASK    (0x8000000U)
#define IOMUXC_GPR_GPR4_PDM_IPG_STOP_ACK_SHIFT   (27U)
#define IOMUXC_GPR_GPR4_PDM_IPG_STOP_ACK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR4_PDM_IPG_STOP_ACK_SHIFT)) & IOMUXC_GPR_GPR4_PDM_IPG_STOP_ACK_MASK)
/*! @} */

/*! @name GPR5 - General Purpose Register 5 */
/*! @{ */

#define IOMUXC_GPR_GPR5_GPR_WDOG1_MASK_MASK      (0x40U)
#define IOMUXC_GPR_GPR5_GPR_WDOG1_MASK_SHIFT     (6U)
/*! GPR_WDOG1_MASK
 *  0b0..WDOG1 low will make the GPIO1_IO02.ALT5_OUT low
 *  0b1..WDOG1 low will not impact the GPIO1_IO02.ALT5_OUT
 */
#define IOMUXC_GPR_GPR5_GPR_WDOG1_MASK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_GPR_WDOG1_MASK_SHIFT)) & IOMUXC_GPR_GPR5_GPR_WDOG1_MASK_MASK)

#define IOMUXC_GPR_GPR5_GPR_WDOG2_MASK_MASK      (0x80U)
#define IOMUXC_GPR_GPR5_GPR_WDOG2_MASK_SHIFT     (7U)
/*! GPR_WDOG2_MASK
 *  0b0..WDOG2 low will make the GPIO1_IO02.ALT5_OUT low
 *  0b1..WDOG2 low will not impact the GPIO1_IO02.ALT5_OUT
 */
#define IOMUXC_GPR_GPR5_GPR_WDOG2_MASK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_GPR_WDOG2_MASK_SHIFT)) & IOMUXC_GPR_GPR5_GPR_WDOG2_MASK_MASK)

#define IOMUXC_GPR_GPR5_GPR_WDOG3_MASK_MASK      (0x100000U)
#define IOMUXC_GPR_GPR5_GPR_WDOG3_MASK_SHIFT     (20U)
/*! GPR_WDOG3_MASK
 *  0b0..WDOG3 low will make the GPIO1_IO02.ALT5_OUT low
 *  0b1..WDOG3 low will not impact the GPIO1_IO02.ALT5_OUT
 */
#define IOMUXC_GPR_GPR5_GPR_WDOG3_MASK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR5_GPR_WDOG3_MASK_SHIFT)) & IOMUXC_GPR_GPR5_GPR_WDOG3_MASK_MASK)
/*! @} */

/*! @name GPR6 - General Purpose Register 6 */
/*! @{ */

#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL3_MASK       (0x1FU)
#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL3_SHIFT      (0U)
/*! GPR_SAI1_SEL3
 *  0b00000..SAI1_CLK_ROOT
 *  0b00001..SAI2_CLK_ROOT
 *  0b00010..SAI3_CLK_ROOT
 *  0b00011..Reserved
 *  0b00100..SAI5_CLK_ROOT
 *  0b00101..SAI6_CLK_ROOT
 *  0b00110..SAI1.MCLK
 *  0b00111..SAI2.MCLK
 *  0b01000..SAI3.MCLK
 *  0b01001..Reserved
 *  0b01010..SAI5.MCLK
 *  0b01011..SAI6.MCLK
 *  0b01100..SPDIF1_CLK_ROOT
 *  0b01101..Reserved
 *  0b01110..SPDIF1.EXTCLK
 *  0b01111..SPDIF1.SRCCLK
 *  0b10000..SPDIF1.OUTCLK
 *  0b10001..Reserved
 */
#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL3(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI1_SEL3_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI1_SEL3_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL1_MASK       (0x20U)
#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL1_SHIFT      (5U)
#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL1(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI1_SEL1_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI1_SEL1_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL2_MASK       (0x1F00U)
#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL2_SHIFT      (8U)
/*! GPR_SAI1_SEL2
 *  0b00000..SAI1_CLK_ROOT
 *  0b00001..SAI2_CLK_ROOT
 *  0b00010..SAI3_CLK_ROOT
 *  0b00011..Reserved
 *  0b00100..SAI5_CLK_ROOT
 *  0b00101..SAI6_CLK_ROOT
 *  0b00110..SAI1.MCLK
 *  0b00111..SAI2.MCLK
 *  0b01000..SAI3.MCLK
 *  0b01001..Reserved
 *  0b01010..SAI5.MCLK
 *  0b01011..SAI6.MCLK
 *  0b01100..SPDIF1_CLK_ROOT
 *  0b01101..Reserved
 *  0b01110..SPDIF1.EXTCLK
 *  0b01111..SPDIF1.SRCCLK
 *  0b10000..SPDIF1.OUTCLK
 *  0b10001..Reserved
 */
#define IOMUXC_GPR_GPR6_GPR_SAI1_SEL2(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI1_SEL2_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI1_SEL2_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI1_MCLK_OUT_SEL_MASK (0x2000U)
#define IOMUXC_GPR_GPR6_GPR_SAI1_MCLK_OUT_SEL_SHIFT (13U)
#define IOMUXC_GPR_GPR6_GPR_SAI1_MCLK_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI1_MCLK_OUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI1_MCLK_OUT_SEL_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL3_MASK       (0x1F0000U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL3_SHIFT      (16U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL3(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI2_SEL3_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI2_SEL3_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL1_MASK       (0x200000U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL1_SHIFT      (21U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL1(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI2_SEL1_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI2_SEL1_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL2_MASK       (0x1F000000U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL2_SHIFT      (24U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_SEL2(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI2_SEL2_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI2_SEL2_MASK)

#define IOMUXC_GPR_GPR6_GPR_SAI2_MCLK_OUT_SEL_MASK (0x20000000U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_MCLK_OUT_SEL_SHIFT (29U)
#define IOMUXC_GPR_GPR6_GPR_SAI2_MCLK_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR6_GPR_SAI2_MCLK_OUT_SEL_SHIFT)) & IOMUXC_GPR_GPR6_GPR_SAI2_MCLK_OUT_SEL_MASK)
/*! @} */

/*! @name GPR7 - General Purpose Register 7 */
/*! @{ */

#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL3_MASK       (0x1FU)
#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL3_SHIFT      (0U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL3(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_GPR_SAI3_SEL3_SHIFT)) & IOMUXC_GPR_GPR7_GPR_SAI3_SEL3_MASK)

#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL1_MASK       (0x20U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL1_SHIFT      (5U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL1(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_GPR_SAI3_SEL1_SHIFT)) & IOMUXC_GPR_GPR7_GPR_SAI3_SEL1_MASK)

#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL2_MASK       (0x1F00U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL2_SHIFT      (8U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_SEL2(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_GPR_SAI3_SEL2_SHIFT)) & IOMUXC_GPR_GPR7_GPR_SAI3_SEL2_MASK)

#define IOMUXC_GPR_GPR7_GPR_SAI3_MCLK_OUT_SEL_MASK (0x2000U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_MCLK_OUT_SEL_SHIFT (13U)
#define IOMUXC_GPR_GPR7_GPR_SAI3_MCLK_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR7_GPR_SAI3_MCLK_OUT_SEL_SHIFT)) & IOMUXC_GPR_GPR7_GPR_SAI3_MCLK_OUT_SEL_MASK)
/*! @} */

/*! @name GPR8 - General Purpose Register 8 */
/*! @{ */

#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL3_MASK       (0x1FU)
#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL3_SHIFT      (0U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL3(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI5_SEL3_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI5_SEL3_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL1_MASK       (0x20U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL1_SHIFT      (5U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL1(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI5_SEL1_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI5_SEL1_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL2_MASK       (0x1F00U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL2_SHIFT      (8U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_SEL2(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI5_SEL2_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI5_SEL2_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI5_MCLK_OUT_SEL_MASK (0x2000U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_MCLK_OUT_SEL_SHIFT (13U)
#define IOMUXC_GPR_GPR8_GPR_SAI5_MCLK_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI5_MCLK_OUT_SEL_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI5_MCLK_OUT_SEL_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL3_MASK       (0x1F0000U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL3_SHIFT      (16U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL3(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI6_SEL3_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI6_SEL3_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL1_MASK       (0x200000U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL1_SHIFT      (21U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL1(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI6_SEL1_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI6_SEL1_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL2_MASK       (0x1F000000U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL2_SHIFT      (24U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_SEL2(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI6_SEL2_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI6_SEL2_MASK)

#define IOMUXC_GPR_GPR8_GPR_SAI6_MCLK_OUT_SEL_MASK (0x20000000U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_MCLK_OUT_SEL_SHIFT (29U)
#define IOMUXC_GPR_GPR8_GPR_SAI6_MCLK_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR8_GPR_SAI6_MCLK_OUT_SEL_SHIFT)) & IOMUXC_GPR_GPR8_GPR_SAI6_MCLK_OUT_SEL_MASK)
/*! @} */

/*! @name GPR10 - General Purpose Register 10 */
/*! @{ */

#define IOMUXC_GPR_GPR10_GPR_TZASC_EN_MASK       (0x1U)
#define IOMUXC_GPR_GPR10_GPR_TZASC_EN_SHIFT      (0U)
/*! GPR_TZASC_EN
 *  0b0..Do not use the TZASC module. All transactions are routed around the TZASC block.
 *  0b1..Enable the TZASC module. All transactions are processed by this block as per the TZASC TRM describes.
 */
#define IOMUXC_GPR_GPR10_GPR_TZASC_EN(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_GPR_TZASC_EN_SHIFT)) & IOMUXC_GPR_GPR10_GPR_TZASC_EN_MASK)

#define IOMUXC_GPR_GPR10_GPR_SEC_ERR_RESP_EN_MASK (0x4U)
#define IOMUXC_GPR_GPR10_GPR_SEC_ERR_RESP_EN_SHIFT (2U)
#define IOMUXC_GPR_GPR10_GPR_SEC_ERR_RESP_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_GPR_SEC_ERR_RESP_EN_SHIFT)) & IOMUXC_GPR_GPR10_GPR_SEC_ERR_RESP_EN_MASK)

#define IOMUXC_GPR_GPR10_GPR_EXC_ERR_RESP_EN_MASK (0x8U)
#define IOMUXC_GPR_GPR10_GPR_EXC_ERR_RESP_EN_SHIFT (3U)
#define IOMUXC_GPR_GPR10_GPR_EXC_ERR_RESP_EN(x)  (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_GPR_EXC_ERR_RESP_EN_SHIFT)) & IOMUXC_GPR_GPR10_GPR_EXC_ERR_RESP_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_GPR_TZASC_EN_MASK  (0x10000U)
#define IOMUXC_GPR_GPR10_LOCK_GPR_TZASC_EN_SHIFT (16U)
#define IOMUXC_GPR_GPR10_LOCK_GPR_TZASC_EN(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_GPR_TZASC_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_GPR_TZASC_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_GPR_SEC_ERR_RESP_EN_MASK (0x40000U)
#define IOMUXC_GPR_GPR10_LOCK_GPR_SEC_ERR_RESP_EN_SHIFT (18U)
#define IOMUXC_GPR_GPR10_LOCK_GPR_SEC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_GPR_SEC_ERR_RESP_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_GPR_SEC_ERR_RESP_EN_MASK)

#define IOMUXC_GPR_GPR10_LOCK_GPR_EXC_ERR_RESP_EN_MASK (0x80000U)
#define IOMUXC_GPR_GPR10_LOCK_GPR_EXC_ERR_RESP_EN_SHIFT (19U)
#define IOMUXC_GPR_GPR10_LOCK_GPR_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR10_LOCK_GPR_EXC_ERR_RESP_EN_SHIFT)) & IOMUXC_GPR_GPR10_LOCK_GPR_EXC_ERR_RESP_EN_MASK)
/*! @} */

/*! @name GPR11 - General Purpose Register 11 */
/*! @{ */

#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_MASK (0x1U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_SHIFT (0U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_SHIFT)) & IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_MASK)

#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_MASK (0x3EU)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_SHIFT (1U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_SHIFT)) & IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_MASK)

#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_MASK (0x400U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_SHIFT (10U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_SHIFT)) & IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_MASK)

#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_MASK (0x3800U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_SHIFT (11U)
#define IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_SHIFT)) & IOMUXC_GPR_GPR11_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_MASK)

#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_MASK (0x10000U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_SHIFT (16U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION0_MASK)

#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_MASK (0x3E0000U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_SHIFT (17U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_OCRAM_TZ_SECURE_REGION1_MASK)

#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_MASK (0x4000000U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_SHIFT (26U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION0_MASK)

#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_MASK (0x38000000U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_SHIFT (27U)
#define IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_SHIFT)) & IOMUXC_GPR_GPR11_LOCK_GPR_OCRAM_CTRL_S_OCRAM_TZ_SECURE_REGION1_MASK)
/*! @} */

/*! @name GPR12 - General Purpose Register 12 */
/*! @{ */

#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_MASK (0xF000U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_SHIFT (12U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_SHIFT)) & IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DEVICE_TYPE_MASK)

#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_MASK (0x1E0000U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_SHIFT (17U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_SHIFT)) & IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_STATUS_BUS_SELECT_MASK)

#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_MASK (0x600000U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_SHIFT (21U)
#define IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_SHIFT)) & IOMUXC_GPR_GPR12_GPR_PCIE1_CTRL_DIAG_CTRL_BUS_MASK)
/*! @} */

/*! @name GPR13 - General Purpose Register 13 */
/*! @{ */

#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USDHC_MASK  (0x1U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USDHC_SHIFT (0U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USDHC(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_ARCACHE_USDHC_SHIFT)) & IOMUXC_GPR_GPR13_GPR_ARCACHE_USDHC_MASK)

#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USDHC_MASK  (0x2U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USDHC_SHIFT (1U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USDHC(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_AWCACHE_USDHC_SHIFT)) & IOMUXC_GPR_GPR13_GPR_AWCACHE_USDHC_MASK)

#define IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_MASK  (0x10U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_SHIFT (4U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_SHIFT)) & IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_MASK)

#define IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_MASK  (0x20U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_SHIFT (5U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_SHIFT)) & IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_MASK)

#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USB1_MASK   (0x80U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USB1_SHIFT  (7U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USB1(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_ARCACHE_USB1_SHIFT)) & IOMUXC_GPR_GPR13_GPR_ARCACHE_USB1_MASK)

#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USB1_MASK   (0x100U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USB1_SHIFT  (8U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USB1(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_AWCACHE_USB1_SHIFT)) & IOMUXC_GPR_GPR13_GPR_AWCACHE_USB1_MASK)

#define IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_EN_MASK (0x400U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_EN_SHIFT (10U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_EN_SHIFT)) & IOMUXC_GPR_GPR13_GPR_ARCACHE_PCIE1_EN_MASK)

#define IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_EN_MASK (0x800U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_EN_SHIFT (11U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_EN_SHIFT)) & IOMUXC_GPR_GPR13_GPR_AWCACHE_PCIE1_EN_MASK)

#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USB2_MASK   (0x2000U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USB2_SHIFT  (13U)
#define IOMUXC_GPR_GPR13_GPR_ARCACHE_USB2(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_ARCACHE_USB2_SHIFT)) & IOMUXC_GPR_GPR13_GPR_ARCACHE_USB2_MASK)

#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USB2_MASK   (0x4000U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USB2_SHIFT  (14U)
#define IOMUXC_GPR_GPR13_GPR_AWCACHE_USB2(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR13_GPR_AWCACHE_USB2_SHIFT)) & IOMUXC_GPR_GPR13_GPR_AWCACHE_USB2_MASK)
/*! @} */

/*! @name GPR14 - General Purpose Register 14 */
/*! @{ */

#define IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN_MASK (0x100U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN_SHIFT (8U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_APP_CLK_PM_EN_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN_MASK (0x200U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN_SHIFT (9U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_I_AUX_EN_OVERRIDE_EN_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_MASK (0x400U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_SHIFT (10U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_EN_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_MASK (0x800U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_SHIFT (11U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_CLKREQ_B_OVERRIDE_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN_MASK (0x10000U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN_SHIFT (16U)
/*! GPR_PCIE1_PHY_FUNC_I_SSC_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_SSC_EN_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF_MASK (0x20000U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF_SHIFT (17U)
/*! GPR_PCIE1_PHY_FUNC_I_POWER_OFF
 *  0b0..Power Up
 *  0b1..Power Down
 */
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_POWER_OFF_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN_MASK (0x40000U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN_SHIFT (18U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_CMN_RSTN_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN_MASK (0x80000U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN_SHIFT (19U)
/*! GPR_PCIE1_PHY_FUNC_I_AUX_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_AUX_EN_MASK)

#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_MASK (0x3000000U)
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_SHIFT (24U)
/*! GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL
 *  0b00..N/A
 *  0b01..Selects reference clock from XO (pll_refclk_from_xo)
 *  0b10..Selects reference clock from IO (ext_ref_clkp/n)
 *  0b11..Selects reference clock from SOC PLL (pll_refclk_from_syspll)
 */
#define IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_SHIFT)) & IOMUXC_GPR_GPR14_GPR_PCIE1_PHY_FUNC_I_PLL_REF_CLK_SEL_MASK)
/*! @} */

/*! @name GPR19 - General Purpose Register 19 */
/*! @{ */

#define IOMUXC_GPR_GPR19_PCIE_DIAG_STATUS_MASK   (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR19_PCIE_DIAG_STATUS_SHIFT  (0U)
#define IOMUXC_GPR_GPR19_PCIE_DIAG_STATUS(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR19_PCIE_DIAG_STATUS_SHIFT)) & IOMUXC_GPR_GPR19_PCIE_DIAG_STATUS_MASK)
/*! @} */

/*! @name GPR22 - General Purpose Register 22 */
/*! @{ */

#define IOMUXC_GPR_GPR22_CPU_STANDBYWFI_MASK     (0xF0000U)
#define IOMUXC_GPR_GPR22_CPU_STANDBYWFI_SHIFT    (16U)
#define IOMUXC_GPR_GPR22_CPU_STANDBYWFI(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR22_CPU_STANDBYWFI_SHIFT)) & IOMUXC_GPR_GPR22_CPU_STANDBYWFI_MASK)

#define IOMUXC_GPR_GPR22_CPU_STANDBYWFE_MASK     (0xF00000U)
#define IOMUXC_GPR_GPR22_CPU_STANDBYWFE_SHIFT    (20U)
#define IOMUXC_GPR_GPR22_CPU_STANDBYWFE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR22_CPU_STANDBYWFE_SHIFT)) & IOMUXC_GPR_GPR22_CPU_STANDBYWFE_MASK)
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

