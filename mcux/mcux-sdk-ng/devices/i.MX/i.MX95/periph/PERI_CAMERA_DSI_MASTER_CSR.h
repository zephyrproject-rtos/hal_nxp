/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAMERA_DSI_MASTER_CSR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file CAMERA_DSI_MASTER_CSR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAMERA_DSI_MASTER_CSR
 *
 * CMSIS Peripheral Access Layer for CAMERA_DSI_MASTER_CSR
 */

#if !defined(CAMERA_DSI_MASTER_CSR_H_)
#define CAMERA_DSI_MASTER_CSR_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- CAMERA_DSI_MASTER_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_MASTER_CSR_Peripheral_Access_Layer CAMERA_DSI_MASTER_CSR Peripheral Access Layer
 * @{
 */

/** CAMERA_DSI_MASTER_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_CLOCK_GATING_CONTROL;          /**< DSI Clock Gating Control, offset: 0x0 */
  __IO uint32_t DSI_PIXEL_LINK_CONTROL;            /**< DSI Pixel Link Control, offset: 0x4 */
  __IO uint32_t DSI_CLOCK_SETTING;                 /**< DSI Clock Setting, offset: 0x8 */
} CAMERA_DSI_MASTER_CSR_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_DSI_MASTER_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_MASTER_CSR_Register_Masks CAMERA_DSI_MASTER_CSR Register Masks
 * @{
 */

/*! @name DSI_CLOCK_GATING_CONTROL - DSI Clock Gating Control */
/*! @{ */

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_0_async_fifo_MASK (0x1U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_0_async_fifo_SHIFT (0U)
/*! Display_0_async_fifo - Controls the gating of the processing clock (pixel clock) of Pixel link slave.
 *  0b1..Pixel clock is disabled (gated)
 *  0b0..Pixel clock is enabled
 */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_0_async_fifo(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_0_async_fifo_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_0_async_fifo_MASK)

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_1_async_fifo_MASK (0x2U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_1_async_fifo_SHIFT (1U)
/*! Display_1_async_fifo - Controls the gating of the processing clock (pixel clock) of Pixel link slave.
 *  0b0..Pixel clock is enabled
 *  0b1..Pixel clock is disabled (gated)
 */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_1_async_fifo(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_1_async_fifo_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Display_1_async_fifo_MASK)

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkin_MASK (0x4U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkin_SHIFT (2U)
/*! Dphy_pll_clkin - Controls the clock gating of the DPHY PLL clkin.
 *  0b1..clkin is disabled (gated)
 *  0b0..clkin is enabled
 */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkin(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkin_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkin_MASK)

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkout_MASK (0x8U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkout_SHIFT (3U)
/*! Dphy_pll_clkout - Controls the clock gating of the DPHY PLL clkout.
 *  0b1..clkout is disabled (gated)
 *  0b0..clkout is enabled
 */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkout(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkout_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkout_MASK)

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkext_MASK (0x10U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkext_SHIFT (4U)
/*! Dphy_pll_clkext - Controls the clock gating of the DPHY PLL clkext.
 *  0b0..clkext is enabled
 *  0b1..clkext is disabled (gated)
 */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkext(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkext_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_GATING_CONTROL_Dphy_pll_clkext_MASK)
/*! @} */

/*! @name DSI_PIXEL_LINK_CONTROL - DSI Pixel Link Control */
/*! @{ */

#define CAMERA_DSI_MASTER_CSR_DSI_PIXEL_LINK_CONTROL_Pixel_link_sel_MASK (0x1U)
#define CAMERA_DSI_MASTER_CSR_DSI_PIXEL_LINK_CONTROL_Pixel_link_sel_SHIFT (0U)
/*! Pixel_link_sel - Selects the pixel link connected to the DSI host controller.
 *  0b0..Pixel Link 0
 *  0b1..Pixel Link 1
 */
#define CAMERA_DSI_MASTER_CSR_DSI_PIXEL_LINK_CONTROL_Pixel_link_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_PIXEL_LINK_CONTROL_Pixel_link_sel_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_PIXEL_LINK_CONTROL_Pixel_link_sel_MASK)
/*! @} */

/*! @name DSI_CLOCK_SETTING - DSI Clock Setting */
/*! @{ */

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_div_MASK (0xFU)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_div_SHIFT (0U)
/*! Dphy_ref_clock_div - Defines the division factor of the Pixel link clock (when used as PLL clock source). */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_div(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_div_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_div_MASK)

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_source_MASK (0x80U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_source_SHIFT (7U)
/*! Dphy_ref_clock_source - Select the DPHY PLL clock source
 *  0b0..24 MHz
 *  0b1..Pixel link clock divided by 'Dphy_ref_clock_div'
 */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_source(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_source_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_ref_clock_source_MASK)

#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_pll_div_MASK (0xF00U)
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_pll_div_SHIFT (8U)
/*! Dphy_pll_div - Defines the division factor of the DPHY_PLL clkout when used as display engine clock source. */
#define CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_pll_div(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_pll_div_SHIFT)) & CAMERA_DSI_MASTER_CSR_DSI_CLOCK_SETTING_Dphy_pll_div_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_DSI_MASTER_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_DSI_MASTER_CSR_Peripheral_Access_Layer */


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


#endif  /* CAMERA_DSI_MASTER_CSR_H_ */

