/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DISPLAY_DSI_CSR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DISPLAY_DSI_CSR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_DSI_CSR
 *
 * CMSIS Peripheral Access Layer for DISPLAY_DSI_CSR
 */

#if !defined(PERI_DISPLAY_DSI_CSR_H_)
#define PERI_DISPLAY_DSI_CSR_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- DISPLAY_DSI_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_DSI_CSR_Peripheral_Access_Layer DISPLAY_DSI_CSR Peripheral Access Layer
 * @{
 */

/** DISPLAY_DSI_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_CLOCK_CNTL;                    /**< DSI Clock Gating Control, offset: 0x0 */
  __IO uint32_t DSI_PXL_LINK_CNTL;                 /**< DSI Pixel Link Control, offset: 0x4 */
  __IO uint32_t DSI_CLK_SETTING;                   /**< DSI Clock Setting, offset: 0x8 */
  __IO uint32_t DSI_PARITY_ERROR_STATUS;           /**< DSI Parity Error Status, offset: 0xC */
  __IO uint32_t DSI_PARITY_ERROR_THRESHOLD;        /**< DSI Parity Error Threshold, offset: 0x10 */
  __IO uint32_t DSI_HOST_CONFIGURATION;            /**< DSI Host Configuration, offset: 0x14 */
  __IO uint32_t DSI_PHY_MODE_CONTROL;              /**< DSI DPHY Mode Control, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DSI_PHY_TEST_MODE_CONTROL;         /**< Rx DPHY Test Mode Control, offset: 0x20 */
  __I  uint32_t DSI_PHY_TEST_MODE_STATUS;          /**< DSI DPHY Test Mode Status, offset: 0x24 */
  __IO uint32_t DSI_PHY_TEST_IO_CONT;              /**< DSI DPHY Test IO Continuity, offset: 0x28 */
  __IO uint32_t DSI_PLL_CTRL0;                     /**< DSI PLL Control 0, offset: 0x2C */
  __IO uint32_t DSI_PLL_CTRL1;                     /**< DSI PLL Control 1, offset: 0x30 */
  __IO uint32_t DSI_PLL_CTRL2;                     /**< DSI PLL Control 2, offset: 0x34 */
  __IO uint32_t DSI_PLL_CTRL3;                     /**< DSI PLL Control 3, offset: 0x38 */
  __IO uint32_t DSI_PLL_SSC_CTRL0;                 /**< DSI PLL SSC Soft Macro Control 0, offset: 0x3C */
  __IO uint32_t DSI_PLL_SSC_CTRL1;                 /**< DSI PLL SSC Soft Macro Control 1, offset: 0x40 */
  __IO uint32_t DSI_PLL_SSC_CTRL2;                 /**< DSI PLL SSC Soft Macro Control 2, offset: 0x44 */
  __IO uint32_t DSI_PLL_SSC_CTRL3;                 /**< DSI PLL SSC Soft Macro Control 3, offset: 0x48 */
       uint8_t RESERVED_1[4];
  __I  uint32_t DSI_PLL_STATUS1;                   /**< DSI PLL Status 1, offset: 0x50 */
       uint8_t RESERVED_2[52];
  __IO uint32_t DSI_HOST_CFG_EXT;                  /**< DSI Host CFG Extended, offset: 0x88 */
  __I  uint32_t DSI_MON_OUT_STATUS_0;              /**< DSI Host Monitor Bus 0, offset: 0x8C */
  __I  uint32_t DSI_MON_OUT_STATUS_1;              /**< DSI Host Monitor Bus 1, offset: 0x90 */
  __IO uint32_t DSI_REFORMAT_MODE_SEL;             /**< DSI REFORMATTER VSYNC SYNC SELECT, offset: 0x94 */
} DISPLAY_DSI_CSR_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_DSI_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_DSI_CSR_Register_Masks DISPLAY_DSI_CSR Register Masks
 * @{
 */

/*! @name DSI_CLOCK_CNTL - DSI Clock Gating Control */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKIN_MASK (0x4U)
#define DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKIN_SHIFT (2U)
/*! DPHY_CLKIN - DSI DPHY_PLL_CLKIN Control
 *  0b0..Not gated
 *  0b1..Gated
 */
#define DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKIN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKIN_SHIFT)) & DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKIN_MASK)

#define DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKOUT_MASK (0x8U)
#define DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKOUT_SHIFT (3U)
/*! DPHY_CLKOUT - DSI DPHY_PLL_CLKOUT Control
 *  0b0..Not gated
 *  0b1..Gated
 */
#define DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKOUT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKOUT_SHIFT)) & DISPLAY_DSI_CSR_DSI_CLOCK_CNTL_DPHY_CLKOUT_MASK)
/*! @} */

/*! @name DSI_PXL_LINK_CNTL - DSI Pixel Link Control */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PXL_LINK_CNTL_PXL_LINK_SEL_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PXL_LINK_CNTL_PXL_LINK_SEL_SHIFT (0U)
/*! PXL_LINK_SEL - Pixel Link Select
 *  0b0..Pixel link 0
 *  0b1..Pixel link 1
 */
#define DISPLAY_DSI_CSR_DSI_PXL_LINK_CNTL_PXL_LINK_SEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PXL_LINK_CNTL_PXL_LINK_SEL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PXL_LINK_CNTL_PXL_LINK_SEL_MASK)
/*! @} */

/*! @name DSI_CLK_SETTING - DSI Clock Setting */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_DIV_MASK (0xFU)
#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_DIV_SHIFT (0U)
/*! DPHY_REF_CLK_DIV - Pixel Link Clock Division Factor */
#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_DIV(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_DIV_SHIFT)) & DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_DIV_MASK)

#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_SRC_MASK (0x80U)
#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_SRC_SHIFT (7U)
/*! DPHY_REF_CLK_SRC - DPHY PLL Clock Source Select
 *  0b0..24MHz or 25MHz
 *  0b1..Pixel link clock divided by Dphy_ref_clock_div
 */
#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_SRC_SHIFT)) & DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_REF_CLK_SRC_MASK)

#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_PLL_DIV_MASK (0xF00U)
#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_PLL_DIV_SHIFT (8U)
/*! DPHY_PLL_DIV - DPHY_PLL Division Factor */
#define DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_PLL_DIV(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_PLL_DIV_SHIFT)) & DISPLAY_DSI_CSR_DSI_CLK_SETTING_DPHY_PLL_DIV_MASK)
/*! @} */

/*! @name DSI_PARITY_ERROR_STATUS - DSI Parity Error Status */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_SHIFT (0U)
/*! Parity0_error - Parity 0 Error Status
 *  0b0..Not reached
 *  0b1..Reached
 */
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_SHIFT)) & DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_MASK)

#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_MASK (0x2U)
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_SHIFT (1U)
/*! Parity123_error - Parity 123 Error Status
 *  0b0..Not reached
 *  0b1..Reached
 */
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_SHIFT)) & DISPLAY_DSI_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_MASK)
/*! @} */

/*! @name DSI_PARITY_ERROR_THRESHOLD - DSI Parity Error Threshold */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_MASK (0x3FFU)
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_SHIFT (0U)
/*! parity0_error_max - Max Parity 0 Threshold
 *  0b0000000000..Disables the error check for parity 0
 *  0b0000000001-0b1111111111..Maximum number of parity 0 errors
 */
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_SHIFT)) & DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_MASK)

#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_MASK (0x3FF0000U)
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_SHIFT (16U)
/*! parity123_error_max - Max Parity 123 Threshold
 *  0b0000000000..Disables the error check for parity 123
 *  0b0000000001-0b1111111111..Maximum number of parity 123 errors
 */
#define DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_SHIFT)) & DISPLAY_DSI_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_MASK)
/*! @} */

/*! @name DSI_HOST_CONFIGURATION - DSI Host Configuration */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_MASK (0x7U)
#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_SHIFT (0U)
/*! Pixel_link_format - Pixel Link Format
 *  0b000..RGB 24-bit
 *  0b001..RGB 30-bit
 *  0b010..RGB 18-bit
 *  0b011..RGB 16-bit
 *  0b100..20-bit YCbCr, 4:2:2 format
 *  0b101..16-bit YCbCr, 4:2:2 format
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_shutdown_MASK (0x10U)
#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_shutdown_SHIFT (4U)
/*! shutdown - Shutdown
 *  0b0..'1' to '0': Send a Turn ON peripheral command (short packet - 0x32)
 *  0b1..'0' to '1': send a Shutdown peripheral command (short packet - 0x22)
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_shutdown(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_shutdown_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_shutdown_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_colormode_MASK (0x20U)
#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_colormode_SHIFT (5U)
/*! colormode - Color Mode
 *  0b0..'1' to '0': Send a Color Mode Off Command (Short packet - 0x02) which switches a Video Mode display
 *       module from low-color mode to normal color mode for normal display operation.
 *  0b1..'0' to '1': Send a Color Mode On Command (Short packet - 0x12) which switches a Video Mode display module
 *       to low-color mode for power saving.
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_colormode(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_colormode_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CONFIGURATION_colormode_MASK)
/*! @} */

/*! @name DSI_PHY_MODE_CONTROL - DSI DPHY Mode Control */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_ATB_SENSE_SEL_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_ATB_SENSE_SEL_SHIFT (0U)
/*! PLL_ATB_SENSE_SEL - ATB Sense Bus to External Bus */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_ATB_SENSE_SEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_ATB_SENSE_SEL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_ATB_SENSE_SEL_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL_MASK (0x6U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL_SHIFT (1U)
/*! PLL_CLKSEL - PLL Clock Output Selection
 *  0b00..Clocks stopped
 *  0b01..Clock generation
 *  0b10..Buffered clkext
 *  0b11..Forbidden
 */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_CLKSEL_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_GP_CLK_EN_MASK (0x8U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_GP_CLK_EN_SHIFT (3U)
/*! PLL_GP_CLK_EN - clkout_gp Clock Enable Signal */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_GP_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_GP_CLK_EN_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PLL_GP_CLK_EN_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PHY_MODE_MASK (0x200U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PHY_MODE_SHIFT (9U)
/*! PHY_MODE - PHY Mode Select
 *  0b0..Transceiver modules configured as DPHY data lanes plus clock lane
 *  0b1..Transceiver modules configured as CPHY trios
 */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PHY_MODE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PHY_MODE_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_PHY_MODE_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_SHUTDOWN_N_MASK (0x400U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_SHUTDOWN_N_SHIFT (10U)
/*! SHUTDOWN_N - PHY Analog Circuitry Shutdown Control
 *  0b0..Place AFE in shutdown mode
 *  0b1..Mission mode
 */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_SHUTDOWN_N(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_SHUTDOWN_N_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_SHUTDOWN_N_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_TEST_STOP_CLK_EN_MASK (0x800U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_TEST_STOP_CLK_EN_SHIFT (11U)
/*! TEST_STOP_CLK_EN - PHY Test Stop Clock Enable */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_TEST_STOP_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_TEST_STOP_CLK_EN_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_TEST_STOP_CLK_EN_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_RST_N_MASK (0x1000U)
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_RST_N_SHIFT (12U)
/*! RST_N - PHY rst_n Control */
#define DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_RST_N(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_RST_N_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_MODE_CONTROL_RST_N_MASK)
/*! @} */

/*! @name DSI_PHY_TEST_MODE_CONTROL - Rx DPHY Test Mode Control */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_dck_ext_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_dck_ext_SHIFT (0U)
/*! txulpsclk_dck_ext - Ultra-Low Power Status for Clock Lane */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_dck_ext(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_dck_ext_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_dck_ext_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_ext_clk_sel_MASK (0x2U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_ext_clk_sel_SHIFT (1U)
/*! ext_clk_sel - Global select Between PHY-generated and External-generated Clock Signal */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_ext_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_ext_clk_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_ext_clk_sel_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_rxclkesc_sel_MASK (0x8U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_rxclkesc_sel_SHIFT (3U)
/*! rxclkesc_sel - Select Between PHY-generated and External-generated Signal (rxclkesc) */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_rxclkesc_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_rxclkesc_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_rxclkesc_sel_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_turndisable_0_MASK (0x2000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT (13U)
/*! turndisable_0 - Disable Turn Around for Lane 0
 *  0b0..Enables turn around
 *  0b1..Disables turn around
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_turndisable_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_turndisable_0_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txdatahs_sel_MASK (0x10000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txdatahs_sel_SHIFT (16U)
/*! txdatahs_sel - Select Between Controller-generated and External-generated Signal */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txdatahs_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txdatahs_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txdatahs_sel_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_MASK (0x20000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_SHIFT (17U)
/*! txbyteclkhs_sel - Select Between Controller-generated and External-generated Signal (txbyteclkhs) */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_sel_MASK (0x40000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_sel_SHIFT (18U)
/*! txulpsclk_sel - Select Between Controller-generated and External-generated Signal */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsclk_sel_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txclkesc_sel_MASK (0x100000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txclkesc_sel_SHIFT (20U)
/*! txclkesc_sel - Select Between Controller-generated and External-generated Signal (txclkesc) */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txclkesc_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txclkesc_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txclkesc_sel_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_BistOn_MASK (0x200000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_BistOn_SHIFT (21U)
/*! BistOn - Bist Test ON */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_BistOn(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_BistOn_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_BistOn_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsexit_dck_ext_MASK (0x8000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsexit_dck_ext_SHIFT (27U)
/*! txulpsexit_dck_ext - Transmit ULP Exit for Clk Lane */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsexit_dck_ext(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsexit_dck_ext_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_CONTROL_txulpsexit_dck_ext_MASK)
/*! @} */

/*! @name DSI_PHY_TEST_MODE_STATUS - DSI DPHY Test Mode Status */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT (0U)
/*! ulpsactivenot_0 - Lane 0 in ULP State
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK (0x2U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT (1U)
/*! ulpsactivenot_1 - Lane 1 in ULP State
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_2_MASK (0x4U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_2_SHIFT (2U)
/*! ulpsactivenot_2 - Lane 2 in ULP State
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_2_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_2_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_3_MASK (0x8U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_3_SHIFT (3U)
/*! ulpsactivenot_3 - Lane 3 in ULP State
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_3(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_3_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenot_3_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_1_MASK (0x20U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT (5U)
/*! errcontrol_1 - Control Error for Lane 1
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_1_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_2_MASK (0x40U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_2_SHIFT (6U)
/*! errcontrol_2 - Control Error for Lane 2
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_2_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_2_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_3_MASK (0x80U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_3_SHIFT (7U)
/*! errcontrol_3 - Control Error for Lane 3
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_3(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_3_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontrol_3_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK (0x200U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT (9U)
/*! ulpsactivenotclk - No Clock Lane in ULP State
 *  0b0..Clock lane is in ULP state
 *  0b1..Clock lane is not in ULP state
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenotclk(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_PHY_LOCK_MASK (0x800U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_PHY_LOCK_SHIFT (11U)
/*! PHY_LOCK - PLL Lock Signal
 *  0b0..Not lock
 *  0b1..Lock
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_PHY_LOCK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_PHY_LOCK_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_PHY_LOCK_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistDone_MASK (0x1000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistDone_SHIFT (12U)
/*! BistDone - Bist Test Done
 *  0b0..Bist test is running
 *  0b1..Bist test is completed
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistDone(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistDone_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistDone_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistOK_MASK (0x2000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistOK_SHIFT (13U)
/*! BistOK - Bist Test Status
 *  0b0..OK
 *  0b1..Completed with errors
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistOK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistOK_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_BistOK_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_0_MASK (0x4000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_0_SHIFT (14U)
/*! errsyncesc_0 - Low Power Transaction Synchronization Error for Lane 0 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_0_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_0_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_1_MASK (0x8000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_1_SHIFT (15U)
/*! errsyncesc_1 - Low Power Transaction Synchronization Error for Lane 1 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_1_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_1_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_2_MASK (0x10000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_2_SHIFT (16U)
/*! errsyncesc_2 - Low Power Transaction Synchronization Error for Lane 2 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_2_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_2_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_3_MASK (0x20000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_3_SHIFT (17U)
/*! errsyncesc_3 - Low Power Transaction Synchronization Error for Lane 3 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_3(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_3_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errsyncesc_3_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_1_MASK (0x2000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_1_SHIFT (25U)
/*! errcontentionlp0_1 - LP0 Contention Error for Lane 1
 *  0b0..No Contention error detected
 *  0b1..Contention error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_1_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_1_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_2_MASK (0x4000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_2_SHIFT (26U)
/*! errcontentionlp0_2 - LP0 Contention Error for Lane 2
 *  0b0..No Contention error detected
 *  0b1..Contention error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_2_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_2_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_3_MASK (0x8000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_3_SHIFT (27U)
/*! errcontentionlp0_3 - LP0 Contention Error for Lane 3
 *  0b0..No Contention error detected
 *  0b1..Contention error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_3(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_3_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp0_3_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_1_MASK (0x20000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_1_SHIFT (29U)
/*! errcontentionlp1_1 - LP1 Contention Error for Lane 1
 *  0b0..No Contention error detected
 *  0b1..Contention error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_1_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_1_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_2_MASK (0x40000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_2_SHIFT (30U)
/*! errcontentionlp1_2 - LP1 Contention Error for Lane 2
 *  0b0..No Contention error detected
 *  0b1..Contention error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_2_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_2_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_3_MASK (0x80000000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_3_SHIFT (31U)
/*! errcontentionlp1_3 - LP1 Contention Error for Lane 3
 *  0b0..No Contention error detected
 *  0b1..Contention error detected
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_3(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_3_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_MODE_STATUS_errcontentionlp1_3_MASK)
/*! @} */

/*! @name DSI_PHY_TEST_IO_CONT - DSI DPHY Test IO Continuity */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_Cont_en_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_Cont_en_SHIFT (0U)
/*! Phy_Cont_en - IO Continuity Test Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_Cont_en(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_Cont_en_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_Cont_en_MASK)

#define DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_cont_data_MASK (0x7FF0000U)
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_cont_data_SHIFT (16U)
/*! Phy_cont_data - Continuity Data Signals */
#define DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_cont_data(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_cont_data_SHIFT)) & DISPLAY_DSI_CSR_DSI_PHY_TEST_IO_CONT_Phy_cont_data_MASK)
/*! @} */

/*! @name DSI_PLL_CTRL0 - DSI PLL Control 0 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M_MASK     (0xFFFU)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M_SHIFT    (0U)
/*! M - DSI Control for M */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL0_M_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL_MASK (0xFC000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL_SHIFT (14U)
/*! VCO_CNTRL - VCO Control */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL0_VCO_CNTRL_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL_MASK (0x3F00000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL_SHIFT (20U)
/*! PROP_CNTRL - Proportional Charge Pump Control */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL0_PROP_CNTRL_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL_MASK (0xFC000000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL_SHIFT (26U)
/*! INT_CNTRL - Integral Charge Pump Control */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL0_INT_CNTRL_MASK)
/*! @} */

/*! @name DSI_PLL_CTRL1 - DSI PLL Control 1 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL_MASK (0x3U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL_SHIFT (0U)
/*! GMP_CNTRL - Effective Loop-filter Resistance Control */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL1_GMP_CNTRL_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL_MASK (0x1FCU)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL_SHIFT (2U)
/*! CPBIAS_CNTRL - Charge Pump Bias Control */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL1_CPBIAS_CNTRL_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_PLL_MEAS_IV_MASK (0x3FFFF000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_PLL_MEAS_IV_SHIFT (12U)
/*! PLL_MEAS_IV - MIPI CDPHY analog test bus signal selection */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL1_PLL_MEAS_IV(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL1_PLL_MEAS_IV_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL1_PLL_MEAS_IV_MASK)
/*! @} */

/*! @name DSI_PLL_CTRL2 - DSI PLL Control 2 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_OPMODE_MASK (0x1FU)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_OPMODE_SHIFT (0U)
/*! PLL_OPMODE - CDPHY PLL operation */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_OPMODE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_OPMODE_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_OPMODE_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_PRG_MASK (0x3FFFE0U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_PRG_SHIFT (5U)
/*! PLL_PRG - CDPHY PLL program configuration */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_PRG(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_PRG_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_PRG_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N_MASK     (0x3C00000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N_SHIFT    (22U)
/*! N - DSI Control for N */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL2_N_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_GP_CLK_CNTRL_MASK (0x1C000000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_GP_CLK_CNTRL_SHIFT (26U)
/*! PLL_GP_CLK_CNTRL - DSI Control for GP Clock Divider
 *  0b000..division by 1
 *  0b001..division by 2
 *  0b010..division by 4
 *  0b011..division by 8
 *  0b100..division by 16
 */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_GP_CLK_CNTRL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_GP_CLK_CNTRL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL2_PLL_GP_CLK_CNTRL_MASK)
/*! @} */

/*! @name DSI_PLL_CTRL3 - DSI PLL Control 3 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH1_MASK (0x3FFU)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH1_SHIFT (0U)
/*! PLL_TH1 - Lock detector phase error threshold. */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH1_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH1_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH2_MASK (0x3FC00U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH2_SHIFT (10U)
/*! PLL_TH2 - Lock filter length. */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH2_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH2_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH3_MASK (0x3FC0000U)
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH3_SHIFT (18U)
/*! PLL_TH3 - Unlock filter length. */
#define DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH3(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH3_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_CTRL3_PLL_TH3_MASK)
/*! @} */

/*! @name DSI_PLL_SSC_CTRL0 - DSI PLL SSC Soft Macro Control 0 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_UPDATE_EN_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_UPDATE_EN_SHIFT (0U)
/*! PLL_FRACN_UPDATE_EN - Control signal to load setting.
 *  0b0..transparent
 *  0b1..capture mode
 */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_UPDATE_EN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_UPDATE_EN_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_UPDATE_EN_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SSC_EN_MASK (0x2U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SSC_EN_SHIFT (1U)
/*! PLL_SSC_EN - Spread Spectrum Enable. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SSC_EN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SSC_EN_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SSC_EN_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_EN_MASK (0x4U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_EN_SHIFT (2U)
/*! PLL_FRACN_EN - Fractional Mode Enable. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_EN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_EN_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_FRACN_EN_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SPREAD_TYPE_MASK (0x18U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SPREAD_TYPE_SHIFT (3U)
/*! PLL_SPREAD_TYPE - PLL Spread Type. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SPREAD_TYPE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SPREAD_TYPE_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_SPREAD_TYPE_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_STEPSIZE_MASK (0xFFFFF800U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_STEPSIZE_SHIFT (11U)
/*! PLL_STEPSIZE - PLL Step Size. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_STEPSIZE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_STEPSIZE_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL0_PLL_STEPSIZE_MASK)
/*! @} */

/*! @name DSI_PLL_SSC_CTRL1 - DSI PLL SSC Soft Macro Control 1 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_SSC_PEAK_MASK (0xFFFFFU)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_SSC_PEAK_SHIFT (0U)
/*! PLL_SSC_PEAK - Spread Spectrum Peak. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_SSC_PEAK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_SSC_PEAK_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_SSC_PEAK_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_MINT_MASK (0xFFF00000U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_MINT_SHIFT (20U)
/*! PLL_MINT - PLL Mint. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_MINT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_MINT_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL1_PLL_MINT_MASK)
/*! @} */

/*! @name DSI_PLL_SSC_CTRL2 - DSI PLL SSC Soft Macro Control 2 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_QUOT_MASK (0xFFFFU)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_QUOT_SHIFT (0U)
/*! PLL_FRAC_QUOT - PLL Fractional Quotient */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_QUOT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_QUOT_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_QUOT_MASK)

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_REM_MASK (0xFFFF0000U)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_REM_SHIFT (16U)
/*! PLL_FRAC_REM - PLL Fractional Remainder. */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_REM(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_REM_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL2_PLL_FRAC_REM_MASK)
/*! @} */

/*! @name DSI_PLL_SSC_CTRL3 - DSI PLL SSC Soft Macro Control 3 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL3_PLL_FRAC_DEN_MASK (0xFFFFU)
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL3_PLL_FRAC_DEN_SHIFT (0U)
/*! PLL_FRAC_DEN - PLL Fractional Denominator */
#define DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL3_PLL_FRAC_DEN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL3_PLL_FRAC_DEN_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_SSC_CTRL3_PLL_FRAC_DEN_MASK)
/*! @} */

/*! @name DSI_PLL_STATUS1 - DSI PLL Status 1 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_PLL_STATUS1_LOCK_PLL_MASK (0x400U)
#define DISPLAY_DSI_CSR_DSI_PLL_STATUS1_LOCK_PLL_SHIFT (10U)
/*! LOCK_PLL - PLL Lock Status
 *  0b0..Not locked
 *  0b1..Locked
 */
#define DISPLAY_DSI_CSR_DSI_PLL_STATUS1_LOCK_PLL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_PLL_STATUS1_LOCK_PLL_SHIFT)) & DISPLAY_DSI_CSR_DSI_PLL_STATUS1_LOCK_PLL_MASK)
/*! @} */

/*! @name DSI_HOST_CFG_EXT - DSI Host CFG Extended */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_req_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_req_SHIFT (0U)
/*! tear_req - Tear Effect Request
 *  0b0..Clear Tear Effect
 *  0b1..Initiate the Automatic Tear Effect by hardware
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_req(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_req_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_req_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_req_MASK (0x2U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_req_SHIFT (1U)
/*! hibernate_req - Hibernate Request
 *  0b0..Exit Image Pixel Interface Hibernate
 *  0b1..Enter Image Pixel Interface Hibernate
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_req(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_req_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_req_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_MASK (0xCU)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_SHIFT (2U)
/*! ipi_lanes - IPI Lanes */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_cdc_en_MASK (0x10U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_cdc_en_SHIFT (4U)
/*! ipi_lanes_cdc_en - IPI Lanes Enable */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_cdc_en(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_cdc_en_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_ipi_lanes_cdc_en_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_st_MASK (0x10000U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_st_SHIFT (16U)
/*! tear_st - Tear Effect Status
 *  0b0..Tear Effect not detected
 *  0b1..Tear Effect detected
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_st(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_st_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_tear_st_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_st_MASK (0x20000U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_st_SHIFT (17U)
/*! hibernate_st - Hibernate Status
 *  0b0..Not in Hibernate status
 *  0b1..Enter Hibernate status and blocking incoming frames
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_st(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_st_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_hibernate_st_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_halt_MASK (0x40000U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_halt_SHIFT (18U)
/*! halt - Image Pixel Halt
 *  0b0..Image Pixel not halt.
 *  0b1..Image Pixel halt
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_halt(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_halt_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_halt_MASK)

#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_core_busy_MASK (0x80000U)
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_core_busy_SHIFT (19U)
/*! core_busy - DSI Host Busy
 *  0b0..DSI host not busy
 *  0b1..DSI host controller is receiving processing and transmitting data
 */
#define DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_core_busy(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_core_busy_SHIFT)) & DISPLAY_DSI_CSR_DSI_HOST_CFG_EXT_core_busy_MASK)
/*! @} */

/*! @name DSI_MON_OUT_STATUS_0 - DSI Host Monitor Bus 0 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_0_mon_out_MASK (0xFFFFFFFFU)
#define DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_0_mon_out_SHIFT (0U)
/*! mon_out - OCLA Monitor Bus Output Value */
#define DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_0_mon_out(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_0_mon_out_SHIFT)) & DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_0_mon_out_MASK)
/*! @} */

/*! @name DSI_MON_OUT_STATUS_1 - DSI Host Monitor Bus 1 */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_1_mon_out_MASK (0xFFFFFFFFU)
#define DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_1_mon_out_SHIFT (0U)
/*! mon_out - OCLA Monitor Bus Output Value */
#define DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_1_mon_out(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_1_mon_out_SHIFT)) & DISPLAY_DSI_CSR_DSI_MON_OUT_STATUS_1_mon_out_MASK)
/*! @} */

/*! @name DSI_REFORMAT_MODE_SEL - DSI REFORMATTER VSYNC SYNC SELECT */
/*! @{ */

#define DISPLAY_DSI_CSR_DSI_REFORMAT_MODE_SEL_sync_sel_MASK (0x1U)
#define DISPLAY_DSI_CSR_DSI_REFORMAT_MODE_SEL_sync_sel_SHIFT (0U)
/*! sync_sel - VSYNC synchronize mode select
 *  0b0..VSYNC delay and synchronize to HSYNC
 *  0b1..Use original VSYNC
 */
#define DISPLAY_DSI_CSR_DSI_REFORMAT_MODE_SEL_sync_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_DSI_CSR_DSI_REFORMAT_MODE_SEL_sync_sel_SHIFT)) & DISPLAY_DSI_CSR_DSI_REFORMAT_MODE_SEL_sync_sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_DSI_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_DSI_CSR_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_DSI_CSR_H_ */

