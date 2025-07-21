/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MEDIA_BLK_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MEDIA_BLK_CTRL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MEDIA_BLK_CTRL
 *
 * CMSIS Peripheral Access Layer for MEDIA_BLK_CTRL
 */

#if !defined(PERI_MEDIA_BLK_CTRL_H_)
#define PERI_MEDIA_BLK_CTRL_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- MEDIA_BLK_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEDIA_BLK_CTRL_Peripheral_Access_Layer MEDIA_BLK_CTRL Peripheral Access Layer
 * @{
 */

/** MEDIA_BLK_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t SFT_RSTN;                          /**< Media Mix Software Reset Register, offset: 0x0 */
  __IO uint32_t CLK_EN;                            /**< Media Mix Clock Enable Register, offset: 0x4 */
  __IO uint32_t MIPI_RESET_DIV;                    /**< MIPI PHY Control Register, offset: 0x8 */
  __IO uint32_t MIPI_M_PLLPMS;                     /**< Master PLL PMS Value setting Register, offset: 0xC */
  __IO uint32_t MIPI_M_PLLCTL_LOW;                 /**< Master PLL Control Low Register, offset: 0x10 */
  __IO uint32_t MIPI_M_PLLCTL_HIGH;                /**< Master PLL Control High Register, offset: 0x14 */
  __IO uint32_t MIPI_B_DPHYCTL_LOW;                /**< Master and Slave DPHY Control Low Register, offset: 0x18 */
  __IO uint32_t MIPI_B_DPHYCTL_HIGH;               /**< Master and Slave DPHY Control High Register, offset: 0x1C */
  __IO uint32_t MIPI_M_DPHYCTL_LOW;                /**< Master and Slave DPHY Control Low Register, offset: 0x20 */
  __IO uint32_t MIPI_M_DPHYCTL_HIGH;               /**< Master and Slave DPHY Control High Register, offset: 0x24 */
  __IO uint32_t MIPI_S_DPHYCTL_LOW;                /**< Master and Slave DPHY Control Low Register, offset: 0x28 */
  __IO uint32_t MIPI_S_DPHYCTL_HIGH;               /**< Master and Slave DPHY Control High Register, offset: 0x2C */
       uint8_t RESERVED_0[28];
  __IO uint32_t LCDIF_ARCACHE_CTRL;                /**< LCDIF ARCACHE Control Register, offset: 0x4C */
  __IO uint32_t ISI_CACHE_CTRL;                    /**< ISI CACHE Control Register, offset: 0x50 */
  __IO uint32_t LDO_CTRL;                          /**< LDO Control Register, offset: 0x54 */
  __IO uint32_t LDO_TRIM;                          /**< LDO Trim Register, offset: 0x58 */
  __IO uint32_t LDB_CTRL;                          /**< LDB Control Register, offset: 0x5C */
  __IO uint32_t GASKET_0_CTRL;                     /**< Gasket 0 Control Register, offset: 0x60 */
  __IO uint32_t GASKET_0_HSIZE;                    /**< Gasket 0 Video Horizontal Size Register, offset: 0x64 */
  __IO uint32_t GASKET_0_VSIZE;                    /**< Gasket 0 Video Vertical Size Register, offset: 0x68 */
  __IO uint32_t GASKET_0_HFP;                      /**< Gasket 0 Video Horizontal Front Porch Register, offset: 0x6C */
  __IO uint32_t GASKET_0_HBP;                      /**< Gasket 0 Video Horizontal Back Porch Register, offset: 0x70 */
  __IO uint32_t GASKET_0_VFP;                      /**< Gasket 0 Video Vertical Front Porch Register, offset: 0x74 */
  __IO uint32_t GASKET_0_VBP;                      /**< Gasket 0 Video Vertical Back Porch Register, offset: 0x78 */
  __IO uint32_t GASKET_0_ISI_PIXEL_CNT;            /**< Gasket 0 ISI Pixel Count Register, offset: 0x7C */
  __IO uint32_t GASKET_0_ISI_LINE_CNT;             /**< Gasket 0 ISI Line Count Register, offset: 0x80 */
  __IO uint32_t GASKET_0_ISI_PIXEL_CTRL;           /**< Gasket 0 ISI Pixel Control Information Register, offset: 0x84 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GASKET_1_CTRL;                     /**< Gasket 1 Control Register, offset: 0x90 */
  __IO uint32_t GASKET_1_HSIZE;                    /**< Gasket 1 Video Horizontal Size Register, offset: 0x94 */
  __IO uint32_t GASKET_1_VSIZE;                    /**< Gasket 1 Video Vertical Size Register, offset: 0x98 */
  __IO uint32_t GASKET_1_HFP;                      /**< Gasket 1 Video Horizontal Front Porch Register, offset: 0x9C */
  __IO uint32_t GASKET_1_HBP;                      /**< Gasket 1 Video Horizontal Back Porch Register, offset: 0xA0 */
  __IO uint32_t GASKET_1_VFP;                      /**< Gasket 1 Video Vertical Front Porch Register, offset: 0xA4 */
  __IO uint32_t GASKET_1_VBP;                      /**< Gasket 1 Video Vertical Back Porch Register, offset: 0xA8 */
  __IO uint32_t GASKET_1_ISI_PIXEL_CNT;            /**< Gasket 1 ISI Pixel Count Register, offset: 0xAC */
  __IO uint32_t GASKET_1_ISI_LINE_CNT;             /**< Gasket 1 ISI Line Count Register, offset: 0xB0 */
  __IO uint32_t GASKET_1_ISI_PIXEL_CTRL;           /**< Gasket 1 ISI Pixel Control Information Register, offset: 0xB4 */
       uint8_t RESERVED_2[104];
  __IO uint32_t MIPI_B2_DPHYCTL_LOW;               /**< Master and Slave DPHY Control Low Register, offset: 0x120 */
  __IO uint32_t MIPI_B2_DPHYCTL_HIGH;              /**< Master and Slave DPHY Control High Register, offset: 0x124 */
  __IO uint32_t LVDS_CTRL;                         /**< LVDS Control Register, offset: 0x128 */
  __IO uint32_t AXI_LIMIT_CONTROL;                 /**< AXI Limit Control Register, offset: 0x12C */
  __IO uint32_t AXI_LIMIT_THRESH0;                 /**< AXI Limit Threshold Register 0, offset: 0x130 */
  __IO uint32_t AXI_LIMIT_THRESH1;                 /**< AXI Limit Threshold Register 1, offset: 0x134 */
  __IO uint32_t ISP_DEWARP_CONTROL;                /**< ISP Dewarp Control Register, offset: 0x138 */
} MEDIA_BLK_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- MEDIA_BLK_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEDIA_BLK_CTRL_Register_Masks MEDIA_BLK_CTRL Register Masks
 * @{
 */

/*! @name SFT_RSTN - Media Mix Software Reset Register */
/*! @{ */

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_PCLK_RESETN_MASK (0x1U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_PCLK_RESETN_SHIFT (0U)
/*! SFT_EN_MIPI_DSI_PCLK_RESETN - sft_en_mipi_dsi_pclk_resetn
 *  0b0..software reset enable for mipi_dsi_pclk
 *  0b1..software reset disable for mipi_dsi_pclk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_PCLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_PCLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_PCLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_CLKREF_RESETN_MASK (0x2U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_CLKREF_RESETN_SHIFT (1U)
/*! SFT_EN_MIPI_DSI_CLKREF_RESETN - sft_en_mipi_dsi_CLKREF_resetn
 *  0b0..software reset enable for mipi_dsi_CLKREF
 *  0b1..software reset disable for mipi_dsi_CLKREF
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_CLKREF_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_CLKREF_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI_CLKREF_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_PCLK_RESETN_MASK (0x4U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_PCLK_RESETN_SHIFT (2U)
/*! SFT_EN_MIPI_CSI_PCLK_RESETN - sft_en_mipi_csi_pclk_resetn
 *  0b0..software reset enable for mipi_csi_pclk
 *  0b1..software reset disable for mipi_csi_pclk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_PCLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_PCLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_PCLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_ACLK_RESETN_MASK (0x8U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_ACLK_RESETN_SHIFT (3U)
/*! SFT_EN_MIPI_CSI_ACLK_RESETN - sft_en_mipi_csi_aclk_resetn
 *  0b0..software reset enable for mipi_csi_aclk
 *  0b1..software reset disable for mipi_csi_aclk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_ACLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_ACLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI_ACLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_PIXEL_CLK_RESETN_MASK (0x10U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_PIXEL_CLK_RESETN_SHIFT (4U)
/*! SFT_EN_LCDIF_PIXEL_CLK_RESETN - sft_en_lcdif_pixel_clk_resetn
 *  0b0..software reset enable for lcdif_pixel_clk
 *  0b1..software reset disable for lcdif_pixel_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_PIXEL_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_PIXEL_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_PIXEL_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_APB_CLK_RESETN_MASK (0x20U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_APB_CLK_RESETN_SHIFT (5U)
/*! SFT_EN_LCDIF_APB_CLK_RESETN - sft_en_lcdif_apb_clk_resetn
 *  0b0..software reset enable for lcdif_apb_clk
 *  0b1..software reset disable for lcdif_apb_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_APB_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_APB_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_APB_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_PROC_CLK_RESETN_MASK (0x40U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_PROC_CLK_RESETN_SHIFT (6U)
/*! SFT_EN_ISI_PROC_CLK_RESETN - sft_en_isi_proc_clk_resetn
 *  0b0..software reset enable for isi_proc_clk
 *  0b1..software reset disable for isi_proc_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_PROC_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_PROC_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_PROC_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_APB_CLK_RESETN_MASK (0x80U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_APB_CLK_RESETN_SHIFT (7U)
/*! SFT_EN_ISI_APB_CLK_RESETN - sft_en_isi_apb_clk_resetn
 *  0b0..software reset enable for isi_apb_clk
 *  0b1..software reset disable for isi_apb_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_APB_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_APB_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISI_APB_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_BUS_BLK_CLK_RESETN_MASK (0x100U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_BUS_BLK_CLK_RESETN_SHIFT (8U)
/*! SFT_EN_BUS_BLK_CLK_RESETN - sft_en_bus_blk_clk_resetn
 *  0b0..software reset enable for bus_blk_clk
 *  0b1..software reset disable for bus_blk_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_BUS_BLK_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_BUS_BLK_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_BUS_BLK_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_PCLK_RESETN_MASK (0x200U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_PCLK_RESETN_SHIFT (9U)
/*! SFT_EN_MIPI_CSI2_PCLK_RESETN - sft_en_mipi_csi2_pclk_resetn
 *  0b0..software reset enable for mipi_csi2_pclk
 *  0b1..software reset disable for mipi_csi2_pclk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_PCLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_PCLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_PCLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_ACLK_RESETN_MASK (0x400U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_ACLK_RESETN_SHIFT (10U)
/*! SFT_EN_MIPI_CSI2_ACLK_RESETN - sft_en_mipi_csi2_aclk_resetn
 *  0b0..software reset enable for mipi_csi2_aclk
 *  0b1..software reset disable for mipi_csi2_aclk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_ACLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_ACLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_CSI2_ACLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_PIXEL_CLK_RESETN_MASK (0x800U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_PIXEL_CLK_RESETN_SHIFT (11U)
/*! SFT_EN_LCDIF2_PIXEL_CLK_RESETN - sft_en_lcdif2_pixel_clk_resetn
 *  0b0..software reset enable for lcdif2_pixel_clk
 *  0b1..software reset disable for lcdif2_pixel_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_PIXEL_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_PIXEL_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_PIXEL_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_APB_CLK_RESETN_MASK (0x1000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_APB_CLK_RESETN_SHIFT (12U)
/*! SFT_EN_LCDIF2_APB_CLK_RESETN - sft_en_lcdif2_apb_clk_resetn
 *  0b0..software reset enable for lcdif2_apb_clk
 *  0b1..software reset disable for lcdif2_apb_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_APB_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_APB_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_APB_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_COR_CLK_RESETN_MASK (0x10000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_COR_CLK_RESETN_SHIFT (16U)
/*! SFT_EN_ISP_COR_CLK_RESETN - sft_en_isp_cor_clk_resetn;
 *  0b0..software reset enable for isp_cor_clk
 *  0b1..software reset disable for isp_cor_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_COR_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_COR_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_COR_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AXI_CLK_RESETN_MASK (0x20000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AXI_CLK_RESETN_SHIFT (17U)
/*! SFT_EN_ISP_AXI_CLK_RESETN - sft_en_isp_axi_clk_resetn;
 *  0b0..software reset enable for isp_axi_clk
 *  0b1..software reset disable for isp_axi_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AXI_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AXI_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AXI_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AHB_CLK_RESETN_MASK (0x40000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AHB_CLK_RESETN_SHIFT (18U)
/*! SFT_EN_ISP_AHB_CLK_RESETN - sft_en_isp_ahb_clk_resetn;
 *  0b0..software reset enable for isp_ahb_clk
 *  0b1..software reset disable for isp_ahb_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AHB_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AHB_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_ISP_AHB_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_COR_CLK_RESETN_MASK (0x80000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_COR_CLK_RESETN_SHIFT (19U)
/*! SFT_EN_DWE_COR_CLK_RESETN - sft_en_dwe_cor_clk_resetn;
 *  0b0..software reset enable for dwe_cor_clk
 *  0b1..software reset disable for dwe_cor_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_COR_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_COR_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_COR_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AXI_CLK_RESETN_MASK (0x100000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AXI_CLK_RESETN_SHIFT (20U)
/*! SFT_EN_DWE_AXI_CLK_RESETN - sft_en_dwe_axi_clk_resetn;
 *  0b0..software reset enable for dwe_axi_clk
 *  0b1..software reset disable for dwe_axi_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AXI_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AXI_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AXI_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AHB_CLK_RESETN_MASK (0x200000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AHB_CLK_RESETN_SHIFT (21U)
/*! SFT_EN_DWE_AHB_CLK_RESETN - sft_en_dwe_ahb_clk_resetn;
 *  0b0..software reset enable for dwe_ahb_clk
 *  0b1..software reset disable for dwe_ahb_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AHB_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AHB_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_DWE_AHB_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI2_CLKREF_RESETN_MASK (0x400000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI2_CLKREF_RESETN_SHIFT (22U)
/*! SFT_EN_MIPI_DSI2_CLKREF_RESETN - sft_en_mipi_dsi2_CLKREF_resetn
 *  0b0..software reset enable for mipi_dsi2_CLKREF
 *  0b1..software reset disable for mipi_dsi2_CLKREF
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI2_CLKREF_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI2_CLKREF_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_MIPI_DSI2_CLKREF_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_AXI_CLK_RESETN_MASK (0x800000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_AXI_CLK_RESETN_SHIFT (23U)
/*! SFT_EN_LCDIF_AXI_CLK_RESETN - sft_en_lcdif_axi_clk_resetn
 *  0b0..software reset enable for lcdif_axi_clk
 *  0b1..software reset disable for lcdif_axi_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_AXI_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_AXI_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF_AXI_CLK_RESETN_MASK)

#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_AXI_CLK_RESETN_MASK (0x1000000U)
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_AXI_CLK_RESETN_SHIFT (24U)
/*! SFT_EN_LCDIF2_AXI_CLK_RESETN - sft_en_lcdif2_axi_clk_resetn
 *  0b0..software reset enable for lcdif2_axi_clk
 *  0b1..software reset disable for lcdif2_axi_clk
 */
#define MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_AXI_CLK_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_AXI_CLK_RESETN_SHIFT)) & MEDIA_BLK_CTRL_SFT_RSTN_SFT_EN_LCDIF2_AXI_CLK_RESETN_MASK)
/*! @} */

/*! @name CLK_EN - Media Mix Clock Enable Register */
/*! @{ */

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_PCLK_MASK (0x1U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_PCLK_SHIFT (0U)
/*! SFT_EN_MIPI_DSI_PCLK - sft_en_mipi_dsi_pclk
 *  0b0..clock disable (gated) for mipi_dsi_pclk
 *  0b1..clock enable for mipi_dsi_pclk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_PCLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_PCLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_PCLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_CLKREF_MASK (0x2U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_CLKREF_SHIFT (1U)
/*! SFT_EN_MIPI_DSI_CLKREF - sft_en_mipi_dsi_CLKREF
 *  0b0..clock disable (gated) for mipi_dsi_CLKREF
 *  0b1..clock enable for mipi_dsi_CLKREF
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_CLKREF(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_CLKREF_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI_CLKREF_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_PCLK_MASK (0x4U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_PCLK_SHIFT (2U)
/*! SFT_EN_MIPI_CSI_PCLK - sft_en_mipi_csi_pclk
 *  0b0..clock disable (gated) for mipi_csi_pclk
 *  0b1..clock enable for mipi_csi_pclk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_PCLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_PCLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_PCLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_ACLK_MASK (0x8U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_ACLK_SHIFT (3U)
/*! SFT_EN_MIPI_CSI_ACLK - sft_en_mipi_csi_aclk
 *  0b0..clock disable (gated) for mipi_csi_aclk
 *  0b1..clock enable for mipi_csi_aclk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_ACLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_ACLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI_ACLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_PIXEL_CLK_MASK (0x10U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_PIXEL_CLK_SHIFT (4U)
/*! SFT_EN_LCDIF_PIXEL_CLK - sft_en_lcdif_pixel_clk
 *  0b0..clock disable (gated) for lcdif_pixel_clk
 *  0b1..clock enable for lcdif_pixel_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_PIXEL_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_PIXEL_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_PIXEL_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_APB_CLK_MASK (0x20U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_APB_CLK_SHIFT (5U)
/*! SFT_EN_LCDIF_APB_CLK - sft_en_lcdif_apb_clk
 *  0b0..clock disable (gated) for lcdif_apb_clk
 *  0b1..clock enable for lcdif_apb_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_APB_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_APB_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_APB_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_PROC_CLK_MASK (0x40U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_PROC_CLK_SHIFT (6U)
/*! SFT_EN_ISI_PROC_CLK - sft_en_isi_proc_clk
 *  0b0..clock disable (gated) for isi_proc_clk
 *  0b1..clock enable for isi_proc_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_PROC_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_PROC_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_PROC_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_APB_CLK_MASK (0x80U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_APB_CLK_SHIFT (7U)
/*! SFT_EN_ISI_APB_CLK - sft_en_isi_apb_clk
 *  0b0..clock disable (gated) for isi_apb_clk
 *  0b1..clock enable for isi_apb_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_APB_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_APB_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISI_APB_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_BUS_BLK_CLK_MASK (0x100U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_BUS_BLK_CLK_SHIFT (8U)
/*! SFT_EN_BUS_BLK_CLK - sft_en_bus_blk_clk
 *  0b0..clock disable (gated) for bus_blk_clk
 *  0b1..clock enable for bus_blk_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_BUS_BLK_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_BUS_BLK_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_BUS_BLK_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_PCLK_MASK (0x200U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_PCLK_SHIFT (9U)
/*! SFT_EN_MIPI_CSI2_PCLK - sft_en_mipi_csi2_pclk
 *  0b0..clock disable (gated) for mipi_csi2_pclk
 *  0b1..clock enable for mipi_csi2_pclk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_PCLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_PCLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_PCLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_ACLK_MASK (0x400U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_ACLK_SHIFT (10U)
/*! SFT_EN_MIPI_CSI2_ACLK - sft_en_mipi_csi2_aclk
 *  0b0..clock disable (gated) for mipi_csi2_aclk
 *  0b1..clock enable for mipi_csi2_aclk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_ACLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_ACLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_CSI2_ACLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_PIXEL_CLK_MASK (0x800U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_PIXEL_CLK_SHIFT (11U)
/*! SFT_EN_LCDIF2_PIXEL_CLK - sft_en_lcdif2_pixel_clk
 *  0b0..clock disable (gated) for lcdif2_pixel_clk
 *  0b1..clock enable for lcdif2_pixel_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_PIXEL_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_PIXEL_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_PIXEL_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_APB_CLK_MASK (0x1000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_APB_CLK_SHIFT (12U)
/*! SFT_EN_LCDIF2_APB_CLK - sft_en_lcdif2_apb_clk
 *  0b0..clock disable (gated) for lcdif2_apb_clk
 *  0b1..clock enable for lcdif2_apb_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_APB_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_APB_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_APB_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_COR_CLK_MASK (0x10000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_COR_CLK_SHIFT (16U)
/*! SFT_EN_ISP_COR_CLK - sft_en_isp_cor_clk
 *  0b0..clock disable (gated) for isp_cor_clk
 *  0b1..clock enable for isp_cor_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_COR_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_COR_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_COR_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AXI_CLK_MASK (0x20000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AXI_CLK_SHIFT (17U)
/*! SFT_EN_ISP_AXI_CLK - sft_en_isp_axi_clk
 *  0b0..clock disable (gated) for isp_axi_clk
 *  0b1..clock enable for isp_axi_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AXI_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AXI_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AXI_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AHB_CLK_MASK (0x40000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AHB_CLK_SHIFT (18U)
/*! SFT_EN_ISP_AHB_CLK - sft_en_isp_ahb_clk
 *  0b0..clock disable (gated) for isp_ahb_clk
 *  0b1..clock enable for isp_ahb_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AHB_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AHB_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_ISP_AHB_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_COR_CLK_MASK (0x80000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_COR_CLK_SHIFT (19U)
/*! SFT_EN_DWE_COR_CLK - sft_en_dwe_cor_clk
 *  0b0..clock disable (gated) for dwe_cor_clk
 *  0b1..clock enable for dwe_cor_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_COR_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_COR_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_COR_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AXI_CLK_MASK (0x100000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AXI_CLK_SHIFT (20U)
/*! SFT_EN_DWE_AXI_CLK - sft_en_dwe_axi_clk
 *  0b0..clock disable (gated) for dwe_axi_clk
 *  0b1..clock enable for dwe_axi_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AXI_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AXI_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AXI_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AHB_CLK_MASK (0x200000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AHB_CLK_SHIFT (21U)
/*! SFT_EN_DWE_AHB_CLK - sft_en_dwe_ahb_clk
 *  0b0..clock disable (gated) for dwe_ahb_clk
 *  0b1..clock enable for dwe_ahb_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AHB_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AHB_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_DWE_AHB_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI2_CLKREF_MASK (0x400000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI2_CLKREF_SHIFT (22U)
/*! SFT_EN_MIPI_DSI2_CLKREF - sft_en_mipi_dsi2_CLKREF
 *  0b0..clock disable (gated) for mipi_dsi2_CLKREF
 *  0b1..clock enable for mipi_dsi2_CLKREF
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI2_CLKREF(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI2_CLKREF_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_MIPI_DSI2_CLKREF_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_AXI_CLK_MASK (0x800000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_AXI_CLK_SHIFT (23U)
/*! SFT_EN_LCDIF_AXI_CLK - sft_en_lcdif_axi_clk
 *  0b0..clock disable (gated) for lcdif_axi_clk
 *  0b1..clock enable for lcdif_axi_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_AXI_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_AXI_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF_AXI_CLK_MASK)

#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_AXI_CLK_MASK (0x1000000U)
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_AXI_CLK_SHIFT (24U)
/*! SFT_EN_LCDIF2_AXI_CLK - sft_en_lcdif2_axi_clk
 *  0b0..clock disable (gated) for lcdif2_axi_clk
 *  0b1..clock enable for lcdif2_axi_clk
 */
#define MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_AXI_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_AXI_CLK_SHIFT)) & MEDIA_BLK_CTRL_CLK_EN_SFT_EN_LCDIF2_AXI_CLK_MASK)
/*! @} */

/*! @name MIPI_RESET_DIV - MIPI PHY Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_RESETN_MASK (0x10000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_RESETN_SHIFT (16U)
/*! GPR_MIPI_S_RESETN - GPR_MIPI_S_RESETN
 *  0b0..MIPI DPHY S_RESETN reset enable
 *  0b1..MIPI DPHY S_RESETN reset disable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_RESETN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_RESETN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_RESETN_MASK (0x20000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_RESETN_SHIFT (17U)
/*! GPR_MIPI_M_RESETN - GPR_MIPI_M_RESETN
 *  0b0..MIPI DPHY M_RESETN reset enable
 *  0b1..MIPI DPHY M_RESETN reset disable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_RESETN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_RESETN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S3_BIASEN_MASK (0x40000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S3_BIASEN_SHIFT (18U)
/*! GPR_CTRL_S3_BIASEN - GPR_CTRL_S3_BIASEN. Used in MIPI PHY
 *  0b0..S3_BIASEN disable
 *  0b1..S3_BIASEN active
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S3_BIASEN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S3_BIASEN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S3_BIASEN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S2_BIASEN_MASK (0x80000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S2_BIASEN_SHIFT (19U)
/*! GPR_CTRL_S2_BIASEN - GPR_CTRL_S2_BIASEN. Used in MIPI PHY
 *  0b0..S2_BIASEN disable
 *  0b1..S2_BIASEN active
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S2_BIASEN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S2_BIASEN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S2_BIASEN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S1_BIASEN_MASK (0x100000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S1_BIASEN_SHIFT (20U)
/*! GPR_CTRL_S1_BIASEN - GPR_CTRL_S1_BIASEN. Used in MIPI PHY
 *  0b0..S1_BIASEN disable
 *  0b1..S1_BIASEN active
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S1_BIASEN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S1_BIASEN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_S1_BIASEN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M2_BIASEN_MASK (0x200000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M2_BIASEN_SHIFT (21U)
/*! GPR_CTRL_M2_BIASEN - GPR_CTRL_M2_BIASEN. Used in MIPI PHY
 *  0b0..M2_BIASEN disable
 *  0b1..M2_BIASEN active
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M2_BIASEN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M2_BIASEN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M2_BIASEN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M1_BIASEN_MASK (0x400000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M1_BIASEN_SHIFT (22U)
/*! GPR_CTRL_M1_BIASEN - GPR_CTRL_M1_BIASEN. Used in MIPI PHY
 *  0b0..M1_BIASEN disable
 *  0b1..M1_BIASEN active
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M1_BIASEN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M1_BIASEN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_CTRL_M1_BIASEN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_DAT_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_DAT_SHIFT (23U)
/*! GPR_MIPI_S_DPDN_SWAP_DAT - GPR_MIPI_S_DPDN_SWAP_DAT
 *  0b0..Master DPHY data lane DP and DN swap disable
 *  0b1..Master DPHY data lane DP and DN swap enable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_DAT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_DAT_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_DAT_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_CLK_MASK (0x1000000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_CLK_SHIFT (24U)
/*! GPR_MIPI_S_DPDN_SWAP_CLK - GPR_MIPI_S_DPDN_SWAP_CLK
 *  0b0..Slave DPHY clock lane DP and DN swap disable
 *  0b1..Slave DPHY clock lane DP and DN swap enable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_CLK_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S_DPDN_SWAP_CLK_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_DAT_MASK (0x2000000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_DAT_SHIFT (25U)
/*! GPR_MIPI_M_DPDN_SWAP_DAT - GPR_MIPI_M_DPDN_SWAP_DAT
 *  0b0..Master DPHY data lane DP and DN swap disable
 *  0b1..Master DPHY data lane DP and DN swap enable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_DAT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_DAT_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_DAT_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_CLK_MASK (0x4000000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_CLK_SHIFT (26U)
/*! GPR_MIPI_M_DPDN_SWAP_CLK - GPR_MIPI_M_DPDN_SWAP_CLK
 *  0b0..Master DPHY clock lane DP and DN swap disable
 *  0b1..Master DPHY clock lane DP and DN swap enable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_CLK(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_CLK_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M_DPDN_SWAP_CLK_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M2_RESETN_MASK (0x20000000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M2_RESETN_SHIFT (29U)
/*! GPR_MIPI_M2_RESETN - GPR_MIPI_M2_RESETN
 *  0b0..MIPI DPHY M2_RESETN reset enable
 *  0b1..MIPI DPHY M2_RESETN reset disable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M2_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M2_RESETN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_M2_RESETN_MASK)

#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S2_RESETN_MASK (0x40000000U)
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S2_RESETN_SHIFT (30U)
/*! GPR_MIPI_S2_RESETN - GPR_MIPI_S2_RESETN
 *  0b0..MIPI DPHY S2_RESETN reset enable
 *  0b1..MIPI DPHY S2_RESETN reset disable
 */
#define MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S2_RESETN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S2_RESETN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_RESET_DIV_GPR_MIPI_S2_RESETN_MASK)
/*! @} */

/*! @name MIPI_M_PLLPMS - Master PLL PMS Value setting Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_S_MASK  (0x6U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_S_SHIFT (1U)
/*! PMS_S - PMS_S
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 4
 *  0b11..Divide by 8
 */
#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_S(x)    (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_S_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_S_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_M_MASK  (0x1FF0U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_M_SHIFT (4U)
/*! PMS_M - PMS_M
 *  0b000000000..Do not program, can cause malfunction
 *  0b000011001..Divide by 25
 *  0b000011010..Divide by 26
 *  0b000011011..Divide by 27
 *  0b000011100..Divide by 28
 *  0b000011101..Divide by 29
 *  0b001111010..Divide by 122
 *  0b001111011..Divide by 123
 *  0b001111100..Divide by 124
 *  0b001111101..Divide by 125
 */
#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_M(x)    (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_M_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_M_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_P_MASK  (0x7E000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_P_SHIFT (13U)
/*! PMS_P - PMS_P
 *  0b000000..Do not program, can cause malfunction
 *  0b000001..Divide by 1
 *  0b000010..Divide by 2
 *  0b000011..Divide by 3
 *  0b000100..Divide by 4
 *  0b000101..Divide by 5
 *  0b011110..Divide by 30
 *  0b011111..Divide by 31
 *  0b100000..Divide by 32
 *  0b100001..Divide by 33
 */
#define MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_P(x)    (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_P_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLPMS_PMS_P_MASK)
/*! @} */

/*! @name MIPI_M_PLLCTL_LOW - Master PLL Control Low Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_ENB_MASK (0x1U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_ENB_SHIFT (0U)
/*! AFC_ENB - Automatic Frequency Control Enable/Disable
 *  0b0..AFC is enabled
 *  0b1..AFC is disabled
 */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_ENB(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_ENB_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_ENB_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_EXTAFC_MASK (0x3EU)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_EXTAFC_SHIFT (1U)
/*! EXTAFC - EXTAFC */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_EXTAFC(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_EXTAFC_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_EXTAFC_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFCINIT_SEL_MASK (0x40U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFCINIT_SEL_SHIFT (6U)
/*! AFCINIT_SEL - AFC initial delay select pin */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFCINIT_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFCINIT_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFCINIT_SEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_ICP_MASK (0x300000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_ICP_SHIFT (20U)
/*! ICP - Controls the charge-pump current */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_ICP(x)  (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_ICP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_ICP_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_BYPASS_MASK (0x400000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_BYPASS_SHIFT (22U)
/*! BYPASS - BYPASS */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_BYPASS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_BYPASS_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FSEL_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FSEL_SHIFT (23U)
/*! FSEL - Monitoring frequency select pin */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FSEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FSEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FSEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_EN_MASK (0x8000000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_EN_SHIFT (27U)
/*! PBIAS_CTRL_EN - PBIAS voltage pull-down enable pin (active-high) */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_MASK (0x10000000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_SHIFT (28U)
/*! PBIAS_CTRL - PBIAS pull-down initial voltage control pin */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_PBIAS_CTRL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FEED_EN_MASK (0x20000000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FEED_EN_SHIFT (29U)
/*! FEED_EN - FEED_OUT enable pin (active-high) */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FEED_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FEED_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_FEED_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_SEL_MASK (0x40000000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_SEL_SHIFT (30U)
/*! AFC_SEL - AFC operation mode select pin */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_AFC_SEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_SSCG_EN_MASK (0x80000000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_SSCG_EN_SHIFT (31U)
/*! SSCG_EN - Enable pin for dithered mode. (Active-high) */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_SSCG_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_SSCG_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_LOW_SSCG_EN_MASK)
/*! @} */

/*! @name MIPI_M_PLLCTL_HIGH - Master PLL Control High Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MFR_MASK (0xFFU)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MFR_SHIFT (0U)
/*! MFR - Value of 8-bit Modulation Frequency (MF) control */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MFR(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MFR_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MFR_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MRR_MASK (0x3F00U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MRR_SHIFT (8U)
/*! MRR - Value of 6-bit Modulation Rate (MR) control */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MRR(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MRR_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_MRR_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_SEL_PF_MASK (0xC000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_SEL_PF_SHIFT (14U)
/*! SEL_PF - Value of 2-bit modulation method control */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_SEL_PF(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_SEL_PF_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_SEL_PF_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_K_MASK (0xFFFF0000U)
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_K_SHIFT (16U)
/*! K - Value of 16-bit Delta-Sigma Modulator (DSM) */
#define MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_K(x)   (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_K_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_PLLCTL_HIGH_K_MASK)
/*! @} */

/*! @name MIPI_B_DPHYCTL_LOW - Master and Slave DPHY Control Low Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ULPS_EXIT_COUNTER_MASK (0x3FFU)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ULPS_EXIT_COUNTER_SHIFT (0U)
/*! ULPS_EXIT_COUNTER - ULPS_EXIT_COUNTER
 *  0b0000000000..0.01 MHz
 *  0b0000000011..0.10 MHz
 *  0b0000011001..1.00 MHz
 *  0b0000110010..2.00 MHz
 *  0b0001001011..3.00 MHz
 *  0b0001100100..4.00 MHz
 *  0b0001111101..5.00 MHz
 *  0b0010010110..6.00 MHz
 *  0b0010101111..7.00 MHz
 *  0b0011001000..8.00 MHz
 *  0b0011100001..9.00 MHz
 *  0b0011111010..10.00 MHz
 *  0b0100010011..11.00 MHz
 *  0b0100101100..12.00 MHz
 *  0b0101000101..13.00 MHz
 *  0b0101011110..14.00 MHz
 *  0b0101110111..15.00 MHz
 *  0b0110010000..16.00 MHz
 *  0b0110101001..17.00 MHz
 *  0b0111000010..18.00 MHz
 *  0b0111011011..19.00 MHz
 *  0b0111110100..20.00 MHz
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ULPS_EXIT_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ULPS_EXIT_COUNTER_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ULPS_EXIT_COUNTER_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_MASK (0x400U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_SHIFT (10U)
/*! TX_TRIGGER_CLK_EN - TX_TRIGGER_CLK_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_TX_TRIGGER_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ERR_CONT_LP_EN_MASK (0x800U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ERR_CONT_LP_EN_SHIFT (11U)
/*! ERR_CONT_LP_EN - ERR_CONT_LP_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ERR_CONT_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ERR_CONT_LP_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_ERR_CONT_LP_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_EN_MASK (0x1000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_EN_SHIFT (12U)
/*! BGR_CHOPPER_EN - BGR_CHOPPER_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_CD_HYS_MASK (0x2000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_CD_HYS_SHIFT (13U)
/*! LP_CD_HYS - LP_CD_HYS
 *  0b0..60mV
 *  0b1..70mV
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_CD_HYS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_CD_HYS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_CD_HYS_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_MASK (0x4000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_SHIFT (14U)
/*! MSTR_CLK_SLEW_RATE_UP - MSTR_CLK_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_MASK (0x18000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_SHIFT (15U)
/*! MSTR_CLK_SLEW_RATE_DOWN - MSTR_CLK_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_PULSE_REJ_MASK (0x20000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_PULSE_REJ_SHIFT (17U)
/*! LP_RX_PULSE_REJ - LP_RX_PULSE_REJ
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_PULSE_REJ(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_PULSE_REJ_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_PULSE_REJ_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_VREF_LVL_MASK (0xC0000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_VREF_LVL_SHIFT (18U)
/*! LP_RX_VREF_LVL - LP_RX_VREF_LVL
 *  0b00..715mV
 *  0b01..743mV
 *  0b10..650mV
 *  0b11..682mV
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_VREF_LVL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_VREF_LVL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_VREF_LVL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_VREF_SRC_SEL_MASK (0x100000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_VREF_SRC_SEL_SHIFT (20U)
/*! VREF_SRC_SEL - VREF_SRC_SEL
 *  0b0..Generated from the BGR
 *  0b1..Generated from the current mirror
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_VREF_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_VREF_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_VREF_SRC_SEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_HYS_CTL_MASK (0x600000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_HYS_CTL_SHIFT (21U)
/*! LP_RX_HYS_CTL - LP_RX_HYS_CTL
 *  0b00..80mV
 *  0b01..100mV
 *  0b10..120mV
 *  0b11..140mV
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_HYS_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_HYS_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_LP_RX_HYS_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_1_2_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_1_2_SHIFT (23U)
/*! REG_VALID_1_2 - REG_VALID_1_2
 *  0b0..Use "ulps_en" signal
 *  0b1..Use valid signal from 1.2V regulator
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_1_2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_1_2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_1_2_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_LVL_CTL_1_2_MASK (0x3000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_LVL_CTL_1_2_SHIFT (24U)
/*! REG_LVL_CTL_1_2 - REG_LVL_CTL_1_2
 *  0b00..1.2V
 *  0b01..1.23V
 *  0b10..1.27V
 *  0b11..1.26V
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_LVL_CTL_1_2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_LVL_CTL_1_2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_LVL_CTL_1_2_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_CTL_1_2_MASK (0x4000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_CTL_1_2_SHIFT (26U)
/*! REG_VALID_CTL_1_2 - REG_VALID_CTL_1_2
 *  0b0..Internal 1.2V regulator
 *  0b1..External 1.2V power
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_CTL_1_2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_CTL_1_2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_REG_VALID_CTL_1_2_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_MASK (0x8000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_SHIFT (27U)
/*! BGR_CHOPPER_FREQ_CTL - BGR_CHOPPER_FREQ_CTL
 *  0b0..3MHz
 *  0b1..1.5MHz
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_MASK (0x30000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_SHIFT (28U)
/*! BIAS_REF_VOLT_CTL - BIAS_REF_VOLT_CTL
 *  0b00..712mV
 *  0b01..724mV
 *  0b10..733mV
 *  0b11..706mV
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BIAS_REF_VOLT_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_USER_DATA_HS_MASK (0xC0000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_USER_DATA_HS_SHIFT (30U)
/*! USER_DATA_HS - User Data Pattern for HS Loopback mode */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_USER_DATA_HS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_USER_DATA_HS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_LOW_USER_DATA_HS_MASK)
/*! @} */

/*! @name MIPI_B_DPHYCTL_HIGH - Master and Slave DPHY Control High Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_USER_DATA_HS_MASK (0x3FU)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_USER_DATA_HS_SHIFT (0U)
/*! USER_DATA_HS - User Data Pattern for HS Loopback mode */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_USER_DATA_HS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_USER_DATA_HS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_USER_DATA_HS_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_HS_MODE_CTL_MASK (0xC0U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_HS_MODE_CTL_SHIFT (6U)
/*! HS_MODE_CTL - HS_MODE_CTL
 *  0b00..Designated Pattern
 *  0b01..PRBS7
 *  0b10..All zero
 *  0b11..User Data Pattern
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_HS_MODE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_HS_MODE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_HS_MODE_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_MASK (0x300U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_SHIFT (8U)
/*! BGR_VOLT_TUNING_CTL - BGR_VOLT_TUNING_CTL
 *  0b00..820mV
 *  0b01..760mV
 *  0b10..800mV
 *  0b11..840mV
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_DCC_DONE_CTL_MASK (0x800U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_DCC_DONE_CTL_SHIFT (11U)
/*! DCC_DONE_CTL - DCC_DONE_CTL
 *  0b0.."DONE" from DCC block
 *  0b1..U"DONE" is always 1
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_DCC_DONE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_DCC_DONE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_DCC_DONE_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_MASK (0x2000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_SHIFT (13U)
/*! RX_SKEW_CALIB_FIX_CODE_EN - RX_SKEW_CALIB_FIX_CODE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_MASK (0x4000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_SHIFT (14U)
/*! LP_VREF_REG_SRC_SEL - LP_VREF_REG_SRC_SEL
 *  0b0..Generated from BGR
 *  0b1..Generated from Current Mirror
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_MASK (0x100000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_SHIFT (20U)
/*! MSTR_DATA0_SLEW_RATE_UP - MSTR_DATA0_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_MASK (0x600000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_SHIFT (21U)
/*! MSTR_DATA0_SLEW_RATE_DOWN - MSTR_DATA0_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_SHIFT (23U)
/*! MSTR_DATA1_SLEW_RATE_UP - MSTR_DATA1_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_MASK (0x3000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_SHIFT (24U)
/*! MSTR_DATA1_SLEW_RATE_DOWN - MSTR_DATA1_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_MASK (0x4000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_SHIFT (26U)
/*! MSTR_DATA2_SLEW_RATE_UP - MSTR_DATA2_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_MASK (0x18000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_SHIFT (27U)
/*! MSTR_DATA2_SLEW_RATE_DOWN - MSTR_DATA2_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_MASK (0x20000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_SHIFT (29U)
/*! MSTR_DATA3_SLEW_RATE_UP - MSTR_DATA3_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_MASK (0xC0000000U)
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_SHIFT (30U)
/*! MSTR_DATA3_SLEW_RATE_DOWN - MSTR_DATA3_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_MASK)
/*! @} */

/*! @name MIPI_M_DPHYCTL_LOW - Master and Slave DPHY Control Low Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_HS_TX_DELAY_CTL_MASK (0x3U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_HS_TX_DELAY_CTL_SHIFT (0U)
/*! DATA_HS_TX_DELAY_CTL - DATA_HS_TX_DELAY_CTL
 *  0b00..No change
 *  0b01..25 ps
 *  0b10..55 ps
 *  0b11..90 ps
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_HS_TX_DELAY_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_HS_TX_DELAY_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_HS_TX_DELAY_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_AMP_CTL_MASK (0xCU)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_AMP_CTL_SHIFT (2U)
/*! HS_TX_REG_AMP_CTL - HS_TX_REG_AMP_CTL
 *  0b00..No Change
 *  0b01..12.5 uA
 *  0b10..50 uA
 *  0b11..16.6 uA
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_AMP_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_AMP_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_AMP_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_TURN_ON_CTL_MASK (0x10U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_TURN_ON_CTL_SHIFT (4U)
/*! HS_TX_REG_TURN_ON_CTL - HS_TX_REG_TURN_ON_CTL
 *  0b0..No Change
 *  0b1..Always Turn-On the HS Regulator
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_TURN_ON_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_TURN_ON_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_TURN_ON_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_HS_TX_DELAY_CTL_MASK (0x60U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_HS_TX_DELAY_CTL_SHIFT (5U)
/*! CLK_HS_TX_DELAY_CTL - CLK_HS_TX_DELAY_CTL
 *  0b00..No change
 *  0b01..25 ps
 *  0b10..55 ps
 *  0b11..90 ps
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_HS_TX_DELAY_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_HS_TX_DELAY_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_HS_TX_DELAY_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_CTL_MASK (0x380U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_CTL_SHIFT (7U)
/*! HS_TX_SLEW_RATE_CTL - HS_TX_SLEW_RATE_CTL */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_EN_MASK (0x400U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_EN_SHIFT (10U)
/*! HS_TX_SLEW_RATE_EN - HS_TX_SLEW_RATE_EN
 *  0b0..SRC Disable
 *  0b1..SRC Enable
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_SLEW_RATE_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_LANE_CAP_CTL_MASK (0x1800U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_LANE_CAP_CTL_SHIFT (11U)
/*! CLK_LANE_CAP_CTL - CLK_LANE_CAP_CTL
 *  0b00..No change
 *  0b01..-6.6%
 *  0b10..13.3%
 *  0b11..6.6%
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_LANE_CAP_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_LANE_CAP_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_LANE_CAP_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_LANE_CAP_CTL_MASK (0x6000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_LANE_CAP_CTL_SHIFT (13U)
/*! DATA_LANE_CAP_CTL - DATA_LANE_CAP_CTL
 *  0b00..No change
 *  0b01..-6.6%
 *  0b10..13.3%
 *  0b11..6.6%
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_LANE_CAP_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_LANE_CAP_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_DATA_LANE_CAP_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_MASK (0x18000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_SHIFT (15U)
/*! ANA_TIMER_HYS_CTL - ANA_TIMER_HYS_CTL
 *  0b00..70mV
 *  0b01..95mV
 *  0b10..95mV
 *  0b11..110mV
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_ANA_TIMER_HYS_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_UP_CTL_MASK (0xE0000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_UP_CTL_SHIFT (17U)
/*! HS_TX_TERM_IMP_UP_CTL - HS_TX_TERM_IMP_UP_CTL
 *  0b000..50 ohm
 *  0b001..52 ohm
 *  0b010..54 ohm
 *  0b011..56 ohm
 *  0b100..44 ohm
 *  0b101..46 ohm
 *  0b110..47 ohm
 *  0b111..48 ohm
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_UP_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_UP_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_UP_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_DOWN_CTL_MASK (0x700000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_DOWN_CTL_SHIFT (20U)
/*! HS_TX_TERM_IMP_DOWN_CTL - HS_TX_TERM_IMP_DOWN_CTL
 *  0b000..50 ohm
 *  0b001..52 ohm
 *  0b010..54 ohm
 *  0b011..56 ohm
 *  0b100..44 ohm
 *  0b101..46 ohm
 *  0b110..47 ohm
 *  0b111..48 ohm
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_DOWN_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_DOWN_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_TERM_IMP_DOWN_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_CURRENT_CTL_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_CURRENT_CTL_SHIFT (23U)
/*! HS_TX_REG_CURRENT_CTL - HS_TX_REG_CURRENT_CTL
 *  0b0..No change
 *  0b1..2.5 uA
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_CURRENT_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_CURRENT_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_CURRENT_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_OUT_CTL_MASK (0x7000000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_OUT_CTL_SHIFT (24U)
/*! HS_TX_REG_OUT_CTL - HS_TX_REG_OUT_CTL
 *  0b000..400mV
 *  0b001..410mV
 *  0b010..420mV
 *  0b011..440mV
 *  0b100..200mV
 *  0b101..360mV
 *  0b110..380mV
 *  0b111..390mV
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_OUT_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_OUT_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_REG_OUT_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_RISE_FALL_TIME_CTL_MASK (0x38000000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_RISE_FALL_TIME_CTL_SHIFT (27U)
/*! HS_TX_RISE_FALL_TIME_CTL - HS_TX_RISE_FALL_TIME_CTL
 *  0b000..135mV
 *  0b001..130mV
 *  0b010..125mV
 *  0b011..120mV
 *  0b100..230mV
 *  0b101..225mV
 *  0b110..220mV
 *  0b111..215mV
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_RISE_FALL_TIME_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_RISE_FALL_TIME_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_TX_RISE_FALL_TIME_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_BUFFER_EN_CTL_MASK (0x40000000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_BUFFER_EN_CTL_SHIFT (30U)
/*! CLK_BUFFER_EN_CTL - CLK_BUFFER_EN_CTL
 *  0b0..HS_TX enable
 *  0b1..PLL lock
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_BUFFER_EN_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_BUFFER_EN_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_CLK_BUFFER_EN_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_REG_VREF_SRC_SEL_MASK (0x80000000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_REG_VREF_SRC_SEL_SHIFT (31U)
/*! HS_REG_VREF_SRC_SEL - HS_REG_VREF_SRC_SEL
 *  0b0..Generated from BGR
 *  0b1..Generated from Current Mirror
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_REG_VREF_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_REG_VREF_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_LOW_HS_REG_VREF_SRC_SEL_MASK)
/*! @} */

/*! @name MIPI_M_DPHYCTL_HIGH - Master and Slave DPHY Control High Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_CLK_SEL_CTL_MASK (0x1U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_CLK_SEL_CTL_SHIFT (0U)
/*! CLK_SEL_CTL - CLK_SEL_CTL
 *  0b0..Generated from Internal PLL
 *  0b1..Generated from External PLL
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_CLK_SEL_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_CLK_SEL_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_CLK_SEL_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_CTL_MASK (0xF00U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_CTL_SHIFT (8U)
/*! TXSKEWCALHS_CTL - TXSKEWCALHS_CTL */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_INIT_CTL_MASK (0xF000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_INIT_CTL_SHIFT (12U)
/*! TXSKEWCALHS_INIT_CTL - TXSKEWCALHS_INIT_CTL */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_INIT_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_INIT_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_INIT_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_WAIT_CTL_MASK (0xF0000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_WAIT_CTL_SHIFT (16U)
/*! TXSKEWCALHS_WAIT_CTL - TXSKEWCALHS_WAIT_CTL */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_WAIT_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_WAIT_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_TXSKEWCALHS_WAIT_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_PLL_CLK_OUT_SEL_MASK (0x10000000U)
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_PLL_CLK_OUT_SEL_SHIFT (28U)
/*! PLL_CLK_OUT_SEL - PLL_CLK_OUT_SEL
 *  0b0..Disable OUT to Other lane
 *  0b1..Enable OUT to Other lane
 */
#define MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_PLL_CLK_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_PLL_CLK_OUT_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_M_DPHYCTL_HIGH_PLL_CLK_OUT_SEL_MASK)
/*! @} */

/*! @name MIPI_S_DPHYCTL_LOW - Master and Slave DPHY Control Low Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_BIAS_CTL_MASK (0x3U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_BIAS_CTL_SHIFT (0U)
/*! HS_RX_BIAS_CTL - HS_RX_BIAS_CTL
 *  0b00..25 uA
 *  0b01..30 uA
 *  0b10..37.5 uA
 *  0b11..50 uA
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_BIAS_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_BIAS_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_BIAS_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_DELAY_CTRL_MASK (0xCU)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_DELAY_CTRL_SHIFT (2U)
/*! HS_RX_DELAY_CTRL - HS_RX_DELAY_CTRL
 *  0b00..0 ps
 *  0b01..30 ps
 *  0b10..60 ps
 *  0b11..90 ps
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_DELAY_CTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_DELAY_CTRL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_DELAY_CTRL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_XXX_MASK (0x30U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_XXX_SHIFT (4U)
/*! XXX - xxx
 *  0b00..-
 *  0b01..30 ps
 *  0b10..60 ps
 *  0b11..90 ps
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_XXX(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_XXX_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_XXX_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_TERM_IMP_CTL_MASK (0xC0U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_TERM_IMP_CTL_SHIFT (6U)
/*! HS_RX_TERM_IMP_CTL - HS_RX_TERM_IMP_CTL
 *  0b00..98 ohm
 *  0b01..106 ohm
 *  0b10..85 ohm
 *  0b11..91 ohm
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_TERM_IMP_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_TERM_IMP_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_HS_RX_TERM_IMP_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_SETTLE_MASK (0x300U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_SETTLE_SHIFT (8U)
/*! CLK_LANE_CAP_CTL_TCLK_SETTLE - CLK_LANE_CAP_CTL_TCLK_SETTLE
 *  0b00..No change
 *  0b01..3.45%
 *  0b10..6.9%
 *  0b11..10.35%
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_SETTLE_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_SETTLE_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_MISS_MASK (0xC00U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_MISS_SHIFT (10U)
/*! CLK_LANE_CAP_CTL_TCLK_MISS - CLK_LANE_CAP_CTL_TCLK_MISS
 *  0b00..No change
 *  0b01..6.6%
 *  0b10..13.2%
 *  0b11..19.8%
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_MISS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_MISS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_LANE_CAP_CTL_TCLK_MISS_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_MISS_EN_MASK (0x1000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_MISS_EN_SHIFT (12U)
/*! CLK_MISS_EN - CLK_MISS_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_MISS_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_MISS_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_CLK_MISS_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_MASK (0x6000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_SHIFT (13U)
/*! ANA_TIMER_HYS_CTL - ANA_TIMER_HYS_CTL
 *  0b00..70mV
 *  0b01..95mV
 *  0b10..95mV
 *  0b11..110mV
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_ANA_TIMER_HYS_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_ANA_TIMER_HYS_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_CCO_GAIN_CTL_MASK (0x30000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_CCO_GAIN_CTL_SHIFT (16U)
/*! DCC_CCO_GAIN_CTL - DCC_CCO_GAIN_CTL
 *  0b00..1/1
 *  0b01..1/4
 *  0b10..1/0.66
 *  0b11..1/1.33
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_CCO_GAIN_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_CCO_GAIN_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_CCO_GAIN_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG1_MASK (0x7C0000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG1_SHIFT (18U)
/*! DCC_BYPASS_UP_CODE_CTL_DBG1 - DCC_BYPASS_UP_CODE_CTL_DBG1 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG1(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG1_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG1_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG2_MASK (0xF800000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG2_SHIFT (23U)
/*! DCC_BYPASS_UP_CODE_CTL_DBG2 - DCC_BYPASS_UP_CODE_CTL_DBG2 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_BYPASS_UP_CODE_CTL_DBG2_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_INIT_TOLERANCE_MASK (0x70000000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_INIT_TOLERANCE_SHIFT (28U)
/*! DCC_INIT_TOLERANCE - DCC_INIT_TOLERANCE
 *  0b000..4
 *  0b001..5
 *  0b010..6
 *  0b011..7
 *  0b100..0
 *  0b101..1
 *  0b110..2
 *  0b111..3
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_INIT_TOLERANCE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_INIT_TOLERANCE_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_INIT_TOLERANCE_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_STABLE_CTL_MASK (0x80000000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_STABLE_CTL_SHIFT (31U)
/*! DCC_STABLE_CTL - DCC_STABLE_CTL
 *  0b0..1 number counter running
 *  0b1..2 number counter running
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_STABLE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_STABLE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_LOW_DCC_STABLE_CTL_MASK)
/*! @} */

/*! @name MIPI_S_DPHYCTL_HIGH - Master and Slave DPHY Control High Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_DCC_EN_MASK (0x1U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_DCC_EN_SHIFT (0U)
/*! DCC_EN - DCC_EN
 *  0b0..DCC Disable
 *  0b1..DCC Enable
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_DCC_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_DCC_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_DCC_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_EN_MASK (0x2U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_EN_SHIFT (1U)
/*! SKEW_CALIB_EN - SKEW_CALIB_EN
 *  0b0..Skew Calibration Disable
 *  0b1..Skew Calibration Enable
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_MAX_CODE_CTL_MASK (0xFCU)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_MAX_CODE_CTL_SHIFT (2U)
/*! SKEW_CALIB_MAX_CODE_CTL - SKEW_CALIB_MAX_CODE_CTL */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_MAX_CODE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_MAX_CODE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_MAX_CODE_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_MIN_CTL_MASK (0x3F00U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_MIN_CTL_SHIFT (8U)
/*! SKEW_CALIB_FAIL_MIN_CTL - SKEW_CALIB_FAIL_MIN_CTL */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_MIN_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_MIN_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_MIN_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_PASS_MIN_CTL_MASK (0x3F0000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_PASS_MIN_CTL_SHIFT (16U)
/*! SKEW_CALIB_PASS_MIN_CTL - SKEW_CALIB_PASS_MIN_CTL */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_PASS_MIN_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_PASS_MIN_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_PASS_MIN_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_TOL_CTL_MASK (0x3000000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_TOL_CTL_SHIFT (24U)
/*! SKEW_CALIB_FAIL_TOL_CTL - SKEW_CALIB_FAIL_TOL_CTL
 *  0b00..Recognizes the pass although fail appears 3 times
 *  0b01..Recognizes the pass although fail appears 2 times
 *  0b10..Recognizes the pass although fail appears 1 time
 *  0b11..Reserved
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_TOL_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_TOL_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_FAIL_TOL_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_WAIT_TIME_CTL_MASK (0xC000000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_WAIT_TIME_CTL_SHIFT (26U)
/*! SKEW_CALIB_CMP_WAIT_TIME_CTL - SKEW_CALIB_CMP_WAIT_TIME_CTL
 *  0b00..Min (Fast)
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Mx (Slow)
 */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_WAIT_TIME_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_WAIT_TIME_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_WAIT_TIME_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_RUN_TIME_CTL_MASK (0xF0000000U)
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_RUN_TIME_CTL_SHIFT (28U)
/*! SKEW_CALIB_CMP_RUN_TIME_CTL - SKEW_CALIB_CMP_RUN_TIME_CTL */
#define MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_RUN_TIME_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_RUN_TIME_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_S_DPHYCTL_HIGH_SKEW_CALIB_CMP_RUN_TIME_CTL_MASK)
/*! @} */

/*! @name LCDIF_ARCACHE_CTRL - LCDIF ARCACHE Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_EN_MASK (0x1U)
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_EN_SHIFT (0U)
/*! GPR_ARCACHE_LCDIF_EN - AXI master ARCACHE control enable
 *  0b0..disable LCDIF AXI master ARCACHE control
 *  0b1..enable LCDIF AXI master ARCACHE control
 */
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_EN_SHIFT)) & MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_EN_MASK)

#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_MASK (0x1EU)
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_SHIFT (1U)
/*! GPR_ARCACHE_LCDIF - Control LCDIF AXI master ARCACHE type */
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_SHIFT)) & MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF_MASK)

#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_EN_MASK (0x20U)
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_EN_SHIFT (5U)
/*! GPR_ARCACHE_LCDIF2_EN - AXI master ARCACHE control enable
 *  0b0..disable LCDIF2 AXI master ARCACHE control
 *  0b1..enable LCDIF2 AXI master ARCACHE control
 */
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_EN_SHIFT)) & MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_EN_MASK)

#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_MASK (0x3C0U)
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_SHIFT (6U)
/*! GPR_ARCACHE_LCDIF2 - Control LCDIF2 AXI master ARCACHE type */
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_SHIFT)) & MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_ARCACHE_LCDIF2_MASK)

#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_0_RD_HURRY_MASK (0x1C00U)
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_0_RD_HURRY_SHIFT (10U)
/*! GPR_LCDIF_0_RD_HURRY - GPR_lcdif_0_rd_hurry */
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_0_RD_HURRY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_0_RD_HURRY_SHIFT)) & MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_0_RD_HURRY_MASK)

#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_1_RD_HURRY_MASK (0xE000U)
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_1_RD_HURRY_SHIFT (13U)
/*! GPR_LCDIF_1_RD_HURRY - GPR_lcdif_1_rd_hurry */
#define MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_1_RD_HURRY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_1_RD_HURRY_SHIFT)) & MEDIA_BLK_CTRL_LCDIF_ARCACHE_CTRL_GPR_LCDIF_1_RD_HURRY_MASK)
/*! @} */

/*! @name ISI_CACHE_CTRL - ISI CACHE Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_EN_MASK (0x1U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_EN_SHIFT (0U)
/*! GPR_ARCACHE_ISI_Y_EN - ISI Y channel AXI master ARCACHE control enable
 *  0b0..disable
 *  0b1..enable
 */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_EN_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_EN_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_MASK (0x1EU)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_SHIFT (1U)
/*! GPR_ARCACHE_ISI_Y - Control ISI Y channel AXI master ARCACHE type */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ARCACHE_ISI_Y_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_EN_MASK (0x20U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_EN_SHIFT (5U)
/*! GPR_AWCACHE_ISI_Y_EN - ISI Y channel AXI master AWCACHE control enable
 *  0b0..disable
 *  0b1..enable
 */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_EN_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_EN_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_MASK (0x3C0U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_SHIFT (6U)
/*! GPR_AWCACHE_ISI_Y - Control ISI Y channel AXI master AWCACHE type */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_Y_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_EN_MASK (0x400U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_EN_SHIFT (10U)
/*! GPR_AWCACHE_ISI_U_EN - ISI U channel AXI master AWCACHE control enable
 *  0b0..disable
 *  0b1..enable
 */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_EN_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_EN_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_MASK (0x7800U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_SHIFT (11U)
/*! GPR_AWCACHE_ISI_U - Control ISI U channel AXI master AWCACHE type */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_U_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_EN_MASK (0x8000U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_EN_SHIFT (15U)
/*! GPR_AWCACHE_ISI_V_EN - ISI V channel AXI master AWCACHE control enable
 *  0b0..disable
 *  0b1..enable
 */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_EN_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_EN_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_MASK (0xF0000U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_SHIFT (16U)
/*! GPR_AWCACHE_ISI_V - Control ISI V channel AXI master AWCACHE type */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_AWCACHE_ISI_V_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_Y_WR_HURRY_MASK (0x700000U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_Y_WR_HURRY_SHIFT (20U)
/*! GPR_ISI_Y_WR_HURRY - GPR_ISI_y_wr_hurry */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_Y_WR_HURRY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_Y_WR_HURRY_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_Y_WR_HURRY_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_U_WR_HURRY_MASK (0x3800000U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_U_WR_HURRY_SHIFT (23U)
/*! GPR_ISI_U_WR_HURRY - GPR_ISI_u_wr_hurry */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_U_WR_HURRY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_U_WR_HURRY_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_U_WR_HURRY_MASK)

#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_V_WR_HURRY_MASK (0x1C000000U)
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_V_WR_HURRY_SHIFT (26U)
/*! GPR_ISI_V_WR_HURRY - GPR_ISI_v_wr_hurry */
#define MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_V_WR_HURRY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_V_WR_HURRY_SHIFT)) & MEDIA_BLK_CTRL_ISI_CACHE_CTRL_GPR_ISI_V_WR_HURRY_MASK)
/*! @} */

/*! @name LDO_CTRL - LDO Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_LDO_CTRL_MIPI_DPHY_LDO_VOUT_CTRL_MASK (0x1FU)
#define MEDIA_BLK_CTRL_LDO_CTRL_MIPI_DPHY_LDO_VOUT_CTRL_SHIFT (0U)
/*! MIPI_DPHY_LDO_VOUT_CTRL - LDO output control port(high level 0.8v,low level 0v) */
#define MEDIA_BLK_CTRL_LDO_CTRL_MIPI_DPHY_LDO_VOUT_CTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDO_CTRL_MIPI_DPHY_LDO_VOUT_CTRL_SHIFT)) & MEDIA_BLK_CTRL_LDO_CTRL_MIPI_DPHY_LDO_VOUT_CTRL_MASK)
/*! @} */

/*! @name LDO_TRIM - LDO Trim Register */
/*! @{ */

#define MEDIA_BLK_CTRL_LDO_TRIM_MIPI_DPHY_LDO_VOUT_TRIM_MASK (0x1FU)
#define MEDIA_BLK_CTRL_LDO_TRIM_MIPI_DPHY_LDO_VOUT_TRIM_SHIFT (0U)
/*! MIPI_DPHY_LDO_VOUT_TRIM - LDO output trimming port(high level 0.8v,low level 0v) */
#define MEDIA_BLK_CTRL_LDO_TRIM_MIPI_DPHY_LDO_VOUT_TRIM(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDO_TRIM_MIPI_DPHY_LDO_VOUT_TRIM_SHIFT)) & MEDIA_BLK_CTRL_LDO_TRIM_MIPI_DPHY_LDO_VOUT_TRIM_MASK)
/*! @} */

/*! @name LDB_CTRL - LDB Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_ENABLE_MASK  (0x1U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_ENABLE_SHIFT (0U)
/*! CH0_ENABLE - ch0_enable */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH0_ENABLE_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH0_ENABLE_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_DI_SELECT_MASK (0x2U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_DI_SELECT_SHIFT (1U)
/*! CH0_DI_SELECT - ch0_di_select
 *  0b0..LDB data from source 0
 *  0b1..LDB data from source 1
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_DI_SELECT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH0_DI_SELECT_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH0_DI_SELECT_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_ENABLE_MASK  (0x4U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_ENABLE_SHIFT (2U)
/*! CH1_ENABLE - ch1_enable */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH1_ENABLE_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH1_ENABLE_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_DI_SELECT_MASK (0x8U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_DI_SELECT_SHIFT (3U)
/*! CH1_DI_SELECT - ch1_di_select
 *  0b0..LDB data from source 0
 *  0b1..LDB data from source 1
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_DI_SELECT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH1_DI_SELECT_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH1_DI_SELECT_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_SPLIT_MODE_MASK  (0x10U)
#define MEDIA_BLK_CTRL_LDB_CTRL_SPLIT_MODE_SHIFT (4U)
/*! SPLIT_MODE - split_mode */
#define MEDIA_BLK_CTRL_LDB_CTRL_SPLIT_MODE(x)    (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_SPLIT_MODE_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_SPLIT_MODE_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_MASK (0x20U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_SHIFT (5U)
/*! CH0_DATA_WIDTH - ch0_data_width
 *  0b0..18bits
 *  0b1..24bits
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH0_DATA_WIDTH_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_MASK (0x40U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_SHIFT (6U)
/*! CH0_BIT_MAPPING - ch0_bit_mapping
 *  0b0..SPWG mapping
 *  0b1..JEIDA mapping
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH0_BIT_MAPPING_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_DATA_WIDTH_MASK (0x80U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_DATA_WIDTH_SHIFT (7U)
/*! CH1_DATA_WIDTH - ch1_data_width */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH1_DATA_WIDTH_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH1_DATA_WIDTH_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_BIT_MAPPING_MASK (0x100U)
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_BIT_MAPPING_SHIFT (8U)
/*! CH1_BIT_MAPPING - ch1_bit_mapping
 *  0b0..SPWG mapping
 *  0b1..JEIDA mapping
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_CH1_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_CH1_BIT_MAPPING_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_CH1_BIT_MAPPING_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_DI0_VSYNC_POLARITY_MASK (0x200U)
#define MEDIA_BLK_CTRL_LDB_CTRL_DI0_VSYNC_POLARITY_SHIFT (9U)
/*! DI0_VSYNC_POLARITY - di0 VSYNC polarity select
 *  0b0..negative polarity
 *  0b1..positive polarity
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_DI0_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_DI0_VSYNC_POLARITY_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_DI0_VSYNC_POLARITY_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_DI1_VSYNC_POLARITY_MASK (0x400U)
#define MEDIA_BLK_CTRL_LDB_CTRL_DI1_VSYNC_POLARITY_SHIFT (10U)
/*! DI1_VSYNC_POLARITY - di1 VSYNC polarity select
 *  0b0..negative polarity
 *  0b1..positive polarity
 */
#define MEDIA_BLK_CTRL_LDB_CTRL_DI1_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_DI1_VSYNC_POLARITY_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_DI1_VSYNC_POLARITY_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_REG_CH0_FIFO_RESET_MASK (0x800U)
#define MEDIA_BLK_CTRL_LDB_CTRL_REG_CH0_FIFO_RESET_SHIFT (11U)
/*! REG_CH0_FIFO_RESET - reg_ch0_fifo_reset */
#define MEDIA_BLK_CTRL_LDB_CTRL_REG_CH0_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_REG_CH0_FIFO_RESET_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_REG_CH0_FIFO_RESET_MASK)

#define MEDIA_BLK_CTRL_LDB_CTRL_REG_CH1_FIFO_RESET_MASK (0x1000U)
#define MEDIA_BLK_CTRL_LDB_CTRL_REG_CH1_FIFO_RESET_SHIFT (12U)
/*! REG_CH1_FIFO_RESET - reg_ch1_fifo_reset */
#define MEDIA_BLK_CTRL_LDB_CTRL_REG_CH1_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LDB_CTRL_REG_CH1_FIFO_RESET_SHIFT)) & MEDIA_BLK_CTRL_LDB_CTRL_REG_CH1_FIFO_RESET_MASK)
/*! @} */

/*! @name GASKET_0_CTRL - Gasket 0 Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_ENABLE_MASK (0x1U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_ENABLE_SHIFT (0U)
/*! GASKET_0_ENABLE - Gasket 0 enable
 *  0b0..Gasket output disable
 *  0b1..Gasket 0 output enable
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_ENABLE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_ENABLE_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DOUBLE_COMP_MASK (0x2U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DOUBLE_COMP_SHIFT (1U)
/*! GASKET_0_DOUBLE_COMP - Gasket 0 double component enable
 *  0b0..Gasket 0 input single component per pixel clock for YUV422
 *  0b1..Gasket 0 input double component per pixel clock for YUV422
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DOUBLE_COMP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DOUBLE_COMP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DOUBLE_COMP_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LEFT_JUST_MODE_MASK (0x4U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LEFT_JUST_MODE_SHIFT (2U)
/*! GASKET_0_LEFT_JUST_MODE - Gasket 0 Left justified mode
 *  0b0..unused LSB equal lease significant bit of valid data
 *  0b1..unused LSB equal most significant bit of valid data
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LEFT_JUST_MODE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LEFT_JUST_MODE_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_YUV420_LINE_SEL_MASK (0x8U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_YUV420_LINE_SEL_SHIFT (3U)
/*! GASKET_0_YUV420_LINE_SEL - Gasket 0 YUV420 ODD/EVEN line first select
 *  0b0..Gasket 0 ODD line first for YUV420 data type
 *  0b1..Gasket 0 EVEN line first for YUV420 data type
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_YUV420_LINE_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_YUV420_LINE_SEL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_YUV420_LINE_SEL_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_VC_ID_MASK (0x30U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_VC_ID_SHIFT (4U)
/*! GASKET_0_VC_ID - Gasket 0 Virtual channel identifier, */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_VC_ID(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_VC_ID_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_VC_ID_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_INTER_MODE_MASK (0xC0U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_INTER_MODE_SHIFT (6U)
/*! GASKET_0_INTER_MODE - Gasket 0 interlace mode
 *  0b00..not interlaced
 *  0b01..interlaced left
 *  0b10..interlaced right
 *  0b11..reserved
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_INTER_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_INTER_MODE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_INTER_MODE_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DATA_TYPE_MASK (0x3F00U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DATA_TYPE_SHIFT (8U)
/*! GASKET_0_DATA_TYPE - Gasket 0 data type
 *  0b011000..YUV420 8-bit
 *  0b011001..YUV420 10-bit
 *  0b011010..Legacy YUV420 8-bit
 *  0b011100..YUV420 8-bit(Chroma Shifted Pixel Sampling)
 *  0b011101..YUV420 10-bit(Chroma Shifted Pixel Sampling)
 *  0b011110..YUV422 8-bit
 *  0b011111..YUV422 10-bit
 *  0b100010..RGB565
 *  0b100011..RGB666
 *  0b100100..RGB888
 *  0b101000..RAW6
 *  0b101001..RAW7
 *  0b101010..RAW8
 *  0b101011..RAW10
 *  0b101100..RAW12
 *  0b101101..RAW14
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DATA_TYPE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_DATA_TYPE_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_SRC_SEL_MASK (0xC000U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_SRC_SEL_SHIFT (14U)
/*! GASKET_0_SRC_SEL - Gasket 0 source when support ISI de-interlace line_doubling mode
 *  0b00..source from mipi_csi channel 0
 *  0b01..source from mipi_csi channel 1
 *  0b10..source from mipi_csi channel 2
 *  0b11..source from mipi_csi channel 3
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_SRC_SEL_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LINE_DOUBLING_EN_MASK (0x10000U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LINE_DOUBLING_EN_SHIFT (16U)
/*! GASKET_0_LINE_DOUBLING_EN - Gasket 0 output for ISI de-interlace line_doubling mode enable
 *  0b0..Gasket 0 not output for ISI de-interlace line_doubling mode
 *  0b1..Gasket 0 output for ISI de-interlace line_doubling mode
 */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LINE_DOUBLING_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LINE_DOUBLING_EN_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_GASKET_0_LINE_DOUBLING_EN_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_ISP_LEFT_JUST_MODE_MASK (0x20000U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_ISP_LEFT_JUST_MODE_SHIFT (17U)
/*! MIPI_ISP_LEFT_JUST_MODE - mipi_isp_left_just_mode */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_ISP_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_ISP_LEFT_JUST_MODE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_ISP_LEFT_JUST_MODE_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_VS_SEL_MASK (0xC0000U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_VS_SEL_SHIFT (18U)
/*! MIPI_CSI_VS_SEL - mipi_csi_vs_sel */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_VS_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_VS_SEL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_VS_SEL_MASK)

#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_HS_POLARITY_MASK (0x100000U)
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_HS_POLARITY_SHIFT (20U)
/*! MIPI_CSI_HS_POLARITY - mipi_csi_hs_polarity */
#define MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_HS_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_HS_POLARITY_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_CTRL_MIPI_CSI_HS_POLARITY_MASK)
/*! @} */

/*! @name GASKET_0_HSIZE - Gasket 0 Video Horizontal Size Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_HSIZE_GASKET_0_HSIZE_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_HSIZE_GASKET_0_HSIZE_SHIFT (0U)
/*! GASKET_0_HSIZE - Gasket 0 video Horizontal size(count in pixel) */
#define MEDIA_BLK_CTRL_GASKET_0_HSIZE_GASKET_0_HSIZE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_HSIZE_GASKET_0_HSIZE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_HSIZE_GASKET_0_HSIZE_MASK)
/*! @} */

/*! @name GASKET_0_VSIZE - Gasket 0 Video Vertical Size Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_VSIZE_GASKET_0_VSIZE_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_VSIZE_GASKET_0_VSIZE_SHIFT (0U)
/*! GASKET_0_VSIZE - Gasket 0 video Vertical size(count in line) */
#define MEDIA_BLK_CTRL_GASKET_0_VSIZE_GASKET_0_VSIZE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_VSIZE_GASKET_0_VSIZE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_VSIZE_GASKET_0_VSIZE_MASK)
/*! @} */

/*! @name GASKET_0_HFP - Gasket 0 Video Horizontal Front Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_HFP_GASKET_0_HFP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_HFP_GASKET_0_HFP_SHIFT (0U)
/*! GASKET_0_HFP - Gasket 0 video Horizontal front porch(count in pixel) */
#define MEDIA_BLK_CTRL_GASKET_0_HFP_GASKET_0_HFP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_HFP_GASKET_0_HFP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_HFP_GASKET_0_HFP_MASK)
/*! @} */

/*! @name GASKET_0_HBP - Gasket 0 Video Horizontal Back Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_HBP_GASKET_0_HBP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_HBP_GASKET_0_HBP_SHIFT (0U)
/*! GASKET_0_HBP - Gasket 0 video Horizontal back porch(count in pixel) */
#define MEDIA_BLK_CTRL_GASKET_0_HBP_GASKET_0_HBP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_HBP_GASKET_0_HBP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_HBP_GASKET_0_HBP_MASK)
/*! @} */

/*! @name GASKET_0_VFP - Gasket 0 Video Vertical Front Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_VFP_GASKET_0_VFP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_VFP_GASKET_0_VFP_SHIFT (0U)
/*! GASKET_0_VFP - Gasket 0 video Vertical front porch(count in line) */
#define MEDIA_BLK_CTRL_GASKET_0_VFP_GASKET_0_VFP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_VFP_GASKET_0_VFP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_VFP_GASKET_0_VFP_MASK)
/*! @} */

/*! @name GASKET_0_VBP - Gasket 0 Video Vertical Back Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_VBP_GASKET_0_VBP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_VBP_GASKET_0_VBP_SHIFT (0U)
/*! GASKET_0_VBP - Gasket 0 video Vertical back porch(count in line) */
#define MEDIA_BLK_CTRL_GASKET_0_VBP_GASKET_0_VBP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_VBP_GASKET_0_VBP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_VBP_GASKET_0_VBP_MASK)
/*! @} */

/*! @name GASKET_0_ISI_PIXEL_CNT - Gasket 0 ISI Pixel Count Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CNT_GASKET_0_ISI_PIXEL_CNT_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CNT_GASKET_0_ISI_PIXEL_CNT_SHIFT (0U)
/*! GASKET_0_ISI_PIXEL_CNT - Gasket 0 output to ISI pixel count status */
#define MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CNT_GASKET_0_ISI_PIXEL_CNT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CNT_GASKET_0_ISI_PIXEL_CNT_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CNT_GASKET_0_ISI_PIXEL_CNT_MASK)
/*! @} */

/*! @name GASKET_0_ISI_LINE_CNT - Gasket 0 ISI Line Count Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_ISI_LINE_CNT_GASKET_0_ISI_LINE_CNT_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_ISI_LINE_CNT_GASKET_0_ISI_LINE_CNT_SHIFT (0U)
/*! GASKET_0_ISI_LINE_CNT - Gasket 0 output to ISI line count status */
#define MEDIA_BLK_CTRL_GASKET_0_ISI_LINE_CNT_GASKET_0_ISI_LINE_CNT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_ISI_LINE_CNT_GASKET_0_ISI_LINE_CNT_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_ISI_LINE_CNT_GASKET_0_ISI_LINE_CNT_MASK)
/*! @} */

/*! @name GASKET_0_ISI_PIXEL_CTRL - Gasket 0 ISI Pixel Control Information Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CTRL_GASKET_0_ISI_PIXEL_CTRL_MASK (0xFFFU)
#define MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CTRL_GASKET_0_ISI_PIXEL_CTRL_SHIFT (0U)
/*! GASKET_0_ISI_PIXEL_CTRL - Gasket 0 output to ISI pixel control information status */
#define MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CTRL_GASKET_0_ISI_PIXEL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CTRL_GASKET_0_ISI_PIXEL_CTRL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_0_ISI_PIXEL_CTRL_GASKET_0_ISI_PIXEL_CTRL_MASK)
/*! @} */

/*! @name GASKET_1_CTRL - Gasket 1 Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_ENABLE_MASK (0x1U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_ENABLE_SHIFT (0U)
/*! GASKET_1_ENABLE - Gasket 1 enable
 *  0b0..Gasket output disable
 *  0b1..Gasket 1 output enable;
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_ENABLE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_ENABLE_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DOUBLE_COMP_MASK (0x2U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DOUBLE_COMP_SHIFT (1U)
/*! GASKET_1_DOUBLE_COMP - Gasket 1 double component enable
 *  0b0..Gasket 1 input single component per pixel clock for YUV422
 *  0b1..Gasket 1 input double component per pixel clock for YUV422
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DOUBLE_COMP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DOUBLE_COMP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DOUBLE_COMP_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LEFT_JUST_MODE_MASK (0x4U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LEFT_JUST_MODE_SHIFT (2U)
/*! GASKET_1_LEFT_JUST_MODE - Gasket 1 Left justified mode
 *  0b0..unused LSB equal lease significant bit of valid data
 *  0b1..unused LSB equal most significant bit of valid data
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LEFT_JUST_MODE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LEFT_JUST_MODE_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_YUV420_LINE_SEL_MASK (0x8U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_YUV420_LINE_SEL_SHIFT (3U)
/*! GASKET_1_YUV420_LINE_SEL - Gasket 1 YUV420 ODD/EVEN line first select
 *  0b0..Gasket 1 ODD line first for YUV420 data type
 *  0b1..Gasket 1 EVEN line first for YUV420 data type
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_YUV420_LINE_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_YUV420_LINE_SEL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_YUV420_LINE_SEL_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_VC_ID_MASK (0x30U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_VC_ID_SHIFT (4U)
/*! GASKET_1_VC_ID - Gasket 1 Virtual channel identifier, */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_VC_ID(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_VC_ID_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_VC_ID_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_INTER_MODE_MASK (0xC0U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_INTER_MODE_SHIFT (6U)
/*! GASKET_1_INTER_MODE - Gasket 1 interlace mode
 *  0b00..not interlaced
 *  0b01..interlaced left
 *  0b10..interlaced right
 *  0b11..reserved
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_INTER_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_INTER_MODE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_INTER_MODE_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DATA_TYPE_MASK (0x3F00U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DATA_TYPE_SHIFT (8U)
/*! GASKET_1_DATA_TYPE - Gasket 1 data type
 *  0b011000..YUV420 8-bit
 *  0b011001..YUV420 10-bit
 *  0b011010..Legacy YUV420 8-bit
 *  0b011100..YUV420 8-bit(Chroma Shifted Pixel Sampling)
 *  0b011101..YUV420 10-bit(Chroma Shifted Pixel Sampling)
 *  0b011110..YUV422 8-bit
 *  0b011111..YUV422 10-bit
 *  0b100010..RGB565
 *  0b100011..RGB666
 *  0b100100..RGB888
 *  0b101000..RAW6
 *  0b101001..RAW7
 *  0b101010..RAW8
 *  0b101011..RAW10
 *  0b101100..RAW12
 *  0b101101..RAW14
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DATA_TYPE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_DATA_TYPE_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_SRC_SEL_MASK (0xC000U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_SRC_SEL_SHIFT (14U)
/*! GASKET_1_SRC_SEL - Gasket 1 source when support ISI de-interlace line_doubling mode
 *  0b00..source from mipi_csi channel 0
 *  0b01..source from mipi_csi channel 1
 *  0b10..source from mipi_csi channel 2
 *  0b11..source from mipi_csi channel 3
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_SRC_SEL_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LINE_DOUBLING_EN_MASK (0x10000U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LINE_DOUBLING_EN_SHIFT (16U)
/*! GASKET_1_LINE_DOUBLING_EN - Gasket 1 output for ISI de-interlace line_doubling mode enable
 *  0b0..Gasket 0 not output for ISI de-interlace line_doubling mode
 *  0b1..Gasket 1 output for ISI de-interlace line_doubling mode
 */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LINE_DOUBLING_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LINE_DOUBLING_EN_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_GASKET_1_LINE_DOUBLING_EN_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_ISP2_LEFT_JUST_MODE_MASK (0x20000U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_ISP2_LEFT_JUST_MODE_SHIFT (17U)
/*! MIPI_ISP2_LEFT_JUST_MODE - mipi_isp2_left_just_mode */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_ISP2_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_ISP2_LEFT_JUST_MODE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_ISP2_LEFT_JUST_MODE_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_VS_SEL_MASK (0xC0000U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_VS_SEL_SHIFT (18U)
/*! MIPI_CSI2_VS_SEL - mipi_csi2_vs_sel */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_VS_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_VS_SEL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_VS_SEL_MASK)

#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_HS_POLARITY_MASK (0x100000U)
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_HS_POLARITY_SHIFT (20U)
/*! MIPI_CSI2_HS_POLARITY - mipi_csi2_hs_polarity */
#define MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_HS_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_HS_POLARITY_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_CTRL_MIPI_CSI2_HS_POLARITY_MASK)
/*! @} */

/*! @name GASKET_1_HSIZE - Gasket 1 Video Horizontal Size Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_HSIZE_GP0_MASK   (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_HSIZE_GP0_SHIFT  (0U)
/*! GP0 - Gasket 1 video Horizontal size(count in pixel) */
#define MEDIA_BLK_CTRL_GASKET_1_HSIZE_GP0(x)     (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_HSIZE_GP0_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_HSIZE_GP0_MASK)
/*! @} */

/*! @name GASKET_1_VSIZE - Gasket 1 Video Vertical Size Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_VSIZE_GASKET_1_VSIZE_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_VSIZE_GASKET_1_VSIZE_SHIFT (0U)
/*! GASKET_1_VSIZE - Gasket 1 video Vertical size(count in line) */
#define MEDIA_BLK_CTRL_GASKET_1_VSIZE_GASKET_1_VSIZE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_VSIZE_GASKET_1_VSIZE_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_VSIZE_GASKET_1_VSIZE_MASK)
/*! @} */

/*! @name GASKET_1_HFP - Gasket 1 Video Horizontal Front Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_HFP_GASKET_1_HFP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_HFP_GASKET_1_HFP_SHIFT (0U)
/*! GASKET_1_HFP - Gasket 1 video Horizontal front porch(count in pixel) */
#define MEDIA_BLK_CTRL_GASKET_1_HFP_GASKET_1_HFP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_HFP_GASKET_1_HFP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_HFP_GASKET_1_HFP_MASK)
/*! @} */

/*! @name GASKET_1_HBP - Gasket 1 Video Horizontal Back Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_HBP_GASKET_1_HBP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_HBP_GASKET_1_HBP_SHIFT (0U)
/*! GASKET_1_HBP - Gasket 1 video Horizontal back porch(count in pixel) */
#define MEDIA_BLK_CTRL_GASKET_1_HBP_GASKET_1_HBP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_HBP_GASKET_1_HBP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_HBP_GASKET_1_HBP_MASK)
/*! @} */

/*! @name GASKET_1_VFP - Gasket 1 Video Vertical Front Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_VFP_GASKET_1_VFP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_VFP_GASKET_1_VFP_SHIFT (0U)
/*! GASKET_1_VFP - Gasket 1 video Vertical front porch(count in line) */
#define MEDIA_BLK_CTRL_GASKET_1_VFP_GASKET_1_VFP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_VFP_GASKET_1_VFP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_VFP_GASKET_1_VFP_MASK)
/*! @} */

/*! @name GASKET_1_VBP - Gasket 1 Video Vertical Back Porch Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_VBP_GASKET_1_VBP_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_VBP_GASKET_1_VBP_SHIFT (0U)
/*! GASKET_1_VBP - Gasket 1 video Vertical back porch(count in line) */
#define MEDIA_BLK_CTRL_GASKET_1_VBP_GASKET_1_VBP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_VBP_GASKET_1_VBP_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_VBP_GASKET_1_VBP_MASK)
/*! @} */

/*! @name GASKET_1_ISI_PIXEL_CNT - Gasket 1 ISI Pixel Count Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CNT_GASKET_1_ISI_PIXEL_CNT_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CNT_GASKET_1_ISI_PIXEL_CNT_SHIFT (0U)
/*! GASKET_1_ISI_PIXEL_CNT - Gasket 1 output to ISI pixel count status */
#define MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CNT_GASKET_1_ISI_PIXEL_CNT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CNT_GASKET_1_ISI_PIXEL_CNT_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CNT_GASKET_1_ISI_PIXEL_CNT_MASK)
/*! @} */

/*! @name GASKET_1_ISI_LINE_CNT - Gasket 1 ISI Line Count Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_ISI_LINE_CNT_GASKET_1_ISI_LINE_CNT_MASK (0xFFFFFFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_ISI_LINE_CNT_GASKET_1_ISI_LINE_CNT_SHIFT (0U)
/*! GASKET_1_ISI_LINE_CNT - Gasket 1 output to ISI line count status */
#define MEDIA_BLK_CTRL_GASKET_1_ISI_LINE_CNT_GASKET_1_ISI_LINE_CNT(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_ISI_LINE_CNT_GASKET_1_ISI_LINE_CNT_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_ISI_LINE_CNT_GASKET_1_ISI_LINE_CNT_MASK)
/*! @} */

/*! @name GASKET_1_ISI_PIXEL_CTRL - Gasket 1 ISI Pixel Control Information Register */
/*! @{ */

#define MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CTRL_GASKET_1_ISI_PIXEL_CTRL_MASK (0xFFFU)
#define MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CTRL_GASKET_1_ISI_PIXEL_CTRL_SHIFT (0U)
/*! GASKET_1_ISI_PIXEL_CTRL - Gasket 1 output to ISI pixel control information status */
#define MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CTRL_GASKET_1_ISI_PIXEL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CTRL_GASKET_1_ISI_PIXEL_CTRL_SHIFT)) & MEDIA_BLK_CTRL_GASKET_1_ISI_PIXEL_CTRL_GASKET_1_ISI_PIXEL_CTRL_MASK)
/*! @} */

/*! @name MIPI_B2_DPHYCTL_LOW - Master and Slave DPHY Control Low Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ULPS_EXIT_COUNTER_MASK (0x3FFU)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ULPS_EXIT_COUNTER_SHIFT (0U)
/*! ULPS_EXIT_COUNTER - ULPS_EXIT_COUNTER
 *  0b0000000000..0.01 MHz
 *  0b0000000011..0.10 MHz
 *  0b0000011001..1.00 MHz
 *  0b0000110010..2.00 MHz
 *  0b0001001011..3.00 MHz
 *  0b0001100100..4.00 MHz
 *  0b0001111101..5.00 MHz
 *  0b0010010110..6.00 MHz
 *  0b0010101111..7.00 MHz
 *  0b0011001000..8.00 MHz
 *  0b0011100001..9.00 MHz
 *  0b0011111010..10.00 MHz
 *  0b0100010011..11.00 MHz
 *  0b0100101100..12.00 MHz
 *  0b0101000101..13.00 MHz
 *  0b0101011110..14.00 MHz
 *  0b0101110111..15.00 MHz
 *  0b0110010000..16.00 MHz
 *  0b0110101001..17.00 MHz
 *  0b0111000010..18.00 MHz
 *  0b0111011011..19.00 MHz
 *  0b0111110100..20.00 MHz
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ULPS_EXIT_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ULPS_EXIT_COUNTER_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ULPS_EXIT_COUNTER_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_MASK (0x400U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_SHIFT (10U)
/*! TX_TRIGGER_CLK_EN - TX_TRIGGER_CLK_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_TX_TRIGGER_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_TX_TRIGGER_CLK_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ERR_CONT_LP_EN_MASK (0x800U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ERR_CONT_LP_EN_SHIFT (11U)
/*! ERR_CONT_LP_EN - ERR_CONT_LP_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ERR_CONT_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ERR_CONT_LP_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_ERR_CONT_LP_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_EN_MASK (0x1000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_EN_SHIFT (12U)
/*! BGR_CHOPPER_EN - BGR_CHOPPER_EN
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_CD_HYS_MASK (0x2000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_CD_HYS_SHIFT (13U)
/*! LP_CD_HYS - LP_CD_HYS
 *  0b0..60mV
 *  0b1..70mV
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_CD_HYS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_CD_HYS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_CD_HYS_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_MASK (0x4000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_SHIFT (14U)
/*! MSTR_CLK_SLEW_RATE_UP - MSTR_CLK_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_MASK (0x18000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_SHIFT (15U)
/*! MSTR_CLK_SLEW_RATE_DOWN - MSTR_CLK_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_MSTR_CLK_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_PULSE_REJ_MASK (0x20000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_PULSE_REJ_SHIFT (17U)
/*! LP_RX_PULSE_REJ - LP_RX_PULSE_REJ
 *  0b0..Enable
 *  0b1..Disable
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_PULSE_REJ(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_PULSE_REJ_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_PULSE_REJ_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_VREF_LVL_MASK (0xC0000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_VREF_LVL_SHIFT (18U)
/*! LP_RX_VREF_LVL - LP_RX_VREF_LVL
 *  0b00..715mV
 *  0b01..743mV
 *  0b10..650mV
 *  0b11..682mV
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_VREF_LVL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_VREF_LVL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_VREF_LVL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_VREF_SRC_SEL_MASK (0x100000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_VREF_SRC_SEL_SHIFT (20U)
/*! VREF_SRC_SEL - VREF_SRC_SEL
 *  0b0..Generated from the BGR
 *  0b1..Generated from the current mirror
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_VREF_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_VREF_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_VREF_SRC_SEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_HYS_CTL_MASK (0x600000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_HYS_CTL_SHIFT (21U)
/*! LP_RX_HYS_CTL - LP_RX_HYS_CTL
 *  0b00..80mV
 *  0b01..100mV
 *  0b10..120mV
 *  0b11..140mV
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_HYS_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_HYS_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_LP_RX_HYS_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_1_2_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_1_2_SHIFT (23U)
/*! REG_VALID_1_2 - REG_VALID_1_2
 *  0b0..Use "ulps_en" signal
 *  0b1..Use valid signal from 1.2V regulator
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_1_2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_1_2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_1_2_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_LVL_CTL_1_2_MASK (0x3000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_LVL_CTL_1_2_SHIFT (24U)
/*! REG_LVL_CTL_1_2 - REG_LVL_CTL_1_2
 *  0b00..1.2V
 *  0b01..1.23V
 *  0b10..1.27V
 *  0b11..1.26V
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_LVL_CTL_1_2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_LVL_CTL_1_2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_LVL_CTL_1_2_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_CTL_1_2_MASK (0x4000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_CTL_1_2_SHIFT (26U)
/*! REG_VALID_CTL_1_2 - REG_VALID_CTL_1_2
 *  0b0..Internal 1.2V regulator
 *  0b1..External 1.2V power
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_CTL_1_2(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_CTL_1_2_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_REG_VALID_CTL_1_2_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_MASK (0x8000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_SHIFT (27U)
/*! BGR_CHOPPER_FREQ_CTL - BGR_CHOPPER_FREQ_CTL
 *  0b0..3MHz
 *  0b1..1.5MHz
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BGR_CHOPPER_FREQ_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_MASK (0x30000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_SHIFT (28U)
/*! BIAS_REF_VOLT_CTL - BIAS_REF_VOLT_CTL
 *  0b00..712mV
 *  0b01..724mV
 *  0b10..733mV
 *  0b11..706mV
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BIAS_REF_VOLT_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_BIAS_REF_VOLT_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_USER_DATA_HS_MASK (0xC0000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_USER_DATA_HS_SHIFT (30U)
/*! USER_DATA_HS - User Data Pattern for HS Loopback mode */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_USER_DATA_HS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_USER_DATA_HS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_LOW_USER_DATA_HS_MASK)
/*! @} */

/*! @name MIPI_B2_DPHYCTL_HIGH - Master and Slave DPHY Control High Register */
/*! @{ */

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_USER_DATA_HS_MASK (0x3FU)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_USER_DATA_HS_SHIFT (0U)
/*! USER_DATA_HS - User Data Pattern for HS Loopback mode */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_USER_DATA_HS(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_USER_DATA_HS_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_USER_DATA_HS_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_HS_MODE_CTL_MASK (0xC0U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_HS_MODE_CTL_SHIFT (6U)
/*! HS_MODE_CTL - HS_MODE_CTL
 *  0b00..Designated Pattern
 *  0b01..PRBS7
 *  0b10..All zero
 *  0b11..User Data Pattern
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_HS_MODE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_HS_MODE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_HS_MODE_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_MASK (0x300U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_SHIFT (8U)
/*! BGR_VOLT_TUNING_CTL - BGR_VOLT_TUNING_CTL
 *  0b00..820mV
 *  0b01..760mV
 *  0b10..800mV
 *  0b11..840mV
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_BGR_VOLT_TUNING_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_DCC_DONE_CTL_MASK (0x800U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_DCC_DONE_CTL_SHIFT (11U)
/*! DCC_DONE_CTL - DCC_DONE_CTL
 *  0b0.."DONE" from DCC block
 *  0b1..U"DONE" is always 1
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_DCC_DONE_CTL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_DCC_DONE_CTL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_DCC_DONE_CTL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_MASK (0x2000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_SHIFT (13U)
/*! RX_SKEW_CALIB_FIX_CODE_EN - RX_SKEW_CALIB_FIX_CODE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_RX_SKEW_CALIB_FIX_CODE_EN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_MASK (0x4000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_SHIFT (14U)
/*! LP_VREF_REG_SRC_SEL - LP_VREF_REG_SRC_SEL
 *  0b0..Generated from BGR
 *  0b1..Generated from Current Mirror
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_LP_VREF_REG_SRC_SEL_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_MASK (0x100000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_SHIFT (20U)
/*! MSTR_DATA0_SLEW_RATE_UP - MSTR_DATA0_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_MASK (0x600000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_SHIFT (21U)
/*! MSTR_DATA0_SLEW_RATE_DOWN - MSTR_DATA0_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA0_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_MASK (0x800000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_SHIFT (23U)
/*! MSTR_DATA1_SLEW_RATE_UP - MSTR_DATA1_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_MASK (0x3000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_SHIFT (24U)
/*! MSTR_DATA1_SLEW_RATE_DOWN - MSTR_DATA1_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA1_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_MASK (0x4000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_SHIFT (26U)
/*! MSTR_DATA2_SLEW_RATE_UP - MSTR_DATA2_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_MASK (0x18000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_SHIFT (27U)
/*! MSTR_DATA2_SLEW_RATE_DOWN - MSTR_DATA2_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA2_SLEW_RATE_DOWN_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_MASK (0x20000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_SHIFT (29U)
/*! MSTR_DATA3_SLEW_RATE_UP - MSTR_DATA3_SLEW_RATE_UP
 *  0b0..No change
 *  0b1..Slew Rate UP
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_UP_MASK)

#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_MASK (0xC0000000U)
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_SHIFT (30U)
/*! MSTR_DATA3_SLEW_RATE_DOWN - MSTR_DATA3_SLEW_RATE_DOWN
 *  0b00..No change
 *  0b01..Decrease the slew rate by about 15%
 *  0b10..Decrease the slew rate by about 15%
 *  0b11..Decrease the slew rate by about 30%
 */
#define MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_SHIFT)) & MEDIA_BLK_CTRL_MIPI_B2_DPHYCTL_HIGH_MSTR_DATA3_SLEW_RATE_DOWN_MASK)
/*! @} */

/*! @name LVDS_CTRL - LVDS Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_LVDS_CTRL_CH0_EN_MASK     (0x1U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_CH0_EN_SHIFT    (0U)
/*! CH0_EN - channel0 enable */
#define MEDIA_BLK_CTRL_LVDS_CTRL_CH0_EN(x)       (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_CH0_EN_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_CH0_EN_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_CH1_EN_MASK     (0x2U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_CH1_EN_SHIFT    (1U)
/*! CH1_EN - channel1 enable */
#define MEDIA_BLK_CTRL_LVDS_CTRL_CH1_EN(x)       (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_CH1_EN_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_CH1_EN_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_VBG_EN_MASK     (0x4U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_VBG_EN_SHIFT    (2U)
/*! VBG_EN - Bandgap enable. */
#define MEDIA_BLK_CTRL_LVDS_CTRL_VBG_EN(x)       (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_VBG_EN_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_VBG_EN_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_HS_EN_MASK      (0x8U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_HS_EN_SHIFT     (3U)
/*! HS_EN - hs_en
 *  0b1..enable the 100 Ohm terminated resistor in the chip, at the same time, the power dissipation will also be double.
 */
#define MEDIA_BLK_CTRL_LVDS_CTRL_HS_EN(x)        (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_HS_EN_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_HS_EN_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_EN_MASK (0x10U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_EN_SHIFT (4U)
/*! PRE_EMPH_EN - Enable pre-emphasis */
#define MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_EN(x)  (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_EN_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_EN_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_ADJ_MASK (0xE0U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_ADJ_SHIFT (5U)
/*! PRE_EMPH_ADJ - Pre-emphasis adjustment. */
#define MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_ADJ(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_ADJ_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_PRE_EMPH_ADJ_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_CM_ADJ_MASK     (0x700U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_CM_ADJ_SHIFT    (8U)
/*! CM_ADJ - Output common mode(Vos) adjustment. */
#define MEDIA_BLK_CTRL_LVDS_CTRL_CM_ADJ(x)       (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_CM_ADJ_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_CM_ADJ_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_CC_ADJ_MASK     (0x3800U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_CC_ADJ_SHIFT    (11U)
/*! CC_ADJ - Output current adjustment. */
#define MEDIA_BLK_CTRL_LVDS_CTRL_CC_ADJ(x)       (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_CC_ADJ_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_CC_ADJ_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_SLEW_ADJ_MASK   (0x1C000U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_SLEW_ADJ_SHIFT  (14U)
/*! SLEW_ADJ - Output transition time adjustment. */
#define MEDIA_BLK_CTRL_LVDS_CTRL_SLEW_ADJ(x)     (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_SLEW_ADJ_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_SLEW_ADJ_MASK)

#define MEDIA_BLK_CTRL_LVDS_CTRL_VBG_ADJ_MASK    (0xE0000U)
#define MEDIA_BLK_CTRL_LVDS_CTRL_VBG_ADJ_SHIFT   (17U)
/*! VBG_ADJ - Bandgap adjustment. */
#define MEDIA_BLK_CTRL_LVDS_CTRL_VBG_ADJ(x)      (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_LVDS_CTRL_VBG_ADJ_SHIFT)) & MEDIA_BLK_CTRL_LVDS_CTRL_VBG_ADJ_MASK)
/*! @} */

/*! @name AXI_LIMIT_CONTROL - AXI Limit Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF0_EN_MASK (0x1U)
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF0_EN_SHIFT (0U)
/*! GPR_AXI_LIMIT_LCDIF0_EN - gpr_axi_limit_lcdif0_en */
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF0_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF0_EN_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF0_EN_MASK)

#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF1_EN_MASK (0x2U)
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF1_EN_SHIFT (1U)
/*! GPR_AXI_LIMIT_LCDIF1_EN - gpr_axi_limit_lcdif1_en */
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF1_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF1_EN_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_LCDIF1_EN_MASK)

#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_ISI_EN_MASK (0x4U)
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_ISI_EN_SHIFT (2U)
/*! GPR_AXI_LIMIT_ISI_EN - gpr_axi_limit_isi_en */
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_ISI_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_ISI_EN_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_ISI_EN_MASK)

#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_DEWARP_EN_MASK (0x8U)
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_DEWARP_EN_SHIFT (3U)
/*! GPR_AXI_LIMIT_DEWARP_EN - gpr_axi_limit_dewarp_en */
#define MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_DEWARP_EN(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_DEWARP_EN_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_CONTROL_GPR_AXI_LIMIT_DEWARP_EN_MASK)
/*! @} */

/*! @name AXI_LIMIT_THRESH0 - AXI Limit Threshold Register 0 */
/*! @{ */

#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF0_THRESH_MASK (0xFFFFU)
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF0_THRESH_SHIFT (0U)
/*! GPR_AXI_LIMIT_LCDIF0_THRESH - gpr_axi_limit_lcdif0_thresh */
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF0_THRESH(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF0_THRESH_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF0_THRESH_MASK)

#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF1_THRESH_MASK (0xFFFF0000U)
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF1_THRESH_SHIFT (16U)
/*! GPR_AXI_LIMIT_LCDIF1_THRESH - gpr_axi_limit_lcdif1_thresh */
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF1_THRESH(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF1_THRESH_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_THRESH0_GPR_AXI_LIMIT_LCDIF1_THRESH_MASK)
/*! @} */

/*! @name AXI_LIMIT_THRESH1 - AXI Limit Threshold Register 1 */
/*! @{ */

#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_ISI_THRESH_MASK (0xFFFFU)
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_ISI_THRESH_SHIFT (0U)
/*! GPR_AXI_LIMIT_ISI_THRESH - gpr_axi_limit_isi_thresh */
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_ISI_THRESH(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_ISI_THRESH_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_ISI_THRESH_MASK)

#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_DEWARP_THRESH_MASK (0xFFFF0000U)
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_DEWARP_THRESH_SHIFT (16U)
/*! GPR_AXI_LIMIT_DEWARP_THRESH - gpr_axi_limit_dewarp_thresh */
#define MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_DEWARP_THRESH(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_DEWARP_THRESH_SHIFT)) & MEDIA_BLK_CTRL_AXI_LIMIT_THRESH1_GPR_AXI_LIMIT_DEWARP_THRESH_MASK)
/*! @} */

/*! @name ISP_DEWARP_CONTROL - ISP Dewarp Control Register */
/*! @{ */

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_0_DISABLE_MASK (0x1U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_0_DISABLE_SHIFT (0U)
/*! GPR_ISP_0_DISABLE - gpr_isp_0_disable */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_0_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_0_DISABLE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_0_DISABLE_MASK)

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_1_DISABLE_MASK (0x2U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_1_DISABLE_SHIFT (1U)
/*! GPR_ISP_1_DISABLE - gpr_isp_1_disable */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_1_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_1_DISABLE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_GPR_ISP_1_DISABLE_MASK)

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_DATA_TYPE_MASK (0x1F8U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_DATA_TYPE_SHIFT (3U)
/*! MIPI_ISP_DATA_TYPE - mipi_isp_data_type
 *  0b101000..RAW6
 *  0b101001..RAW7
 *  0b101010..RAW8
 *  0b101011..RAW10
 *  0b101100..RAW12
 *  0b101101..RAW14
 */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_DATA_TYPE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_DATA_TYPE_MASK)

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_LEFT_JUST_MODE_MASK (0x200U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_LEFT_JUST_MODE_SHIFT (9U)
/*! MIPI_ISP_LEFT_JUST_MODE - mipi_isp_left_just_mode */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_LEFT_JUST_MODE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP_LEFT_JUST_MODE_MASK)

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_DATA_TYPE_MASK (0x7E000U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_DATA_TYPE_SHIFT (13U)
/*! MIPI_ISP2_DATA_TYPE - mipi_isp2_data_type
 *  0b101000..RAW6
 *  0b101001..RAW7
 *  0b101010..RAW8
 *  0b101011..RAW10
 *  0b101100..RAW12
 *  0b101101..RAW14
 */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_DATA_TYPE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_DATA_TYPE_MASK)

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_LEFT_JUST_MODE_MASK (0x80000U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_LEFT_JUST_MODE_SHIFT (19U)
/*! MIPI_ISP2_LEFT_JUST_MODE - mipi_isp2_left_just_mode */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_LEFT_JUST_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_LEFT_JUST_MODE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_MIPI_ISP2_LEFT_JUST_MODE_MASK)

#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_ISP_ID_MODE_MASK (0x1800000U)
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_ISP_ID_MODE_SHIFT (23U)
/*! ISP_ID_MODE - isp_id_mode
 *  0b00..vc_id_disable; ID will not toggle during no data transmit;
 *  0b01..vc_id_012 toggle 0,2 during no data transmit;
 *  0b10..vc_id_01 toggle 0,1 during no data transmit;
 *  0b11..vc_id_02 toggle 0,1,2 during no data transmit;
 */
#define MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_ISP_ID_MODE(x) (((uint32_t)(((uint32_t)(x)) << MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_ISP_ID_MODE_SHIFT)) & MEDIA_BLK_CTRL_ISP_DEWARP_CONTROL_ISP_ID_MODE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MEDIA_BLK_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group MEDIA_BLK_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_MEDIA_BLK_CTRL_H_ */

