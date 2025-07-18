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
**         CMSIS Peripheral Access Layer for MAINCONTROLLER
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
 * @file PERI_MAINCONTROLLER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MAINCONTROLLER
 *
 * CMSIS Peripheral Access Layer for MAINCONTROLLER
 */

#if !defined(PERI_MAINCONTROLLER_H_)
#define PERI_MAINCONTROLLER_H_                   /**< Symbol preventing repeated inclusion */

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
   -- MAINCONTROLLER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAINCONTROLLER_Peripheral_Access_Layer MAINCONTROLLER Peripheral Access Layer
 * @{
 */

/** MAINCONTROLLER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1];
  __IO uint8_t MC_CLKDIS;                          /**< Main Controller Synchronous Clock Domain Disable Register, offset: 0x1 */
  __IO uint8_t MC_SWRSTZREQ_1;                     /**< Main Controller Software Reset Register Main controller software reset request per clock domain., offset: 0x2 */
  __IO uint8_t MC_OPCTRL;                          /**< Main Controller HDCP Bypass Control Register, offset: 0x3 */
  __IO uint8_t MC_FLOWCTRL;                        /**< Main Controller Feed Through Control Register, offset: 0x4 */
  __IO uint8_t MC_PHYRSTZ;                         /**< Main Controller PHY Reset Register, offset: 0x5 */
  __IO uint8_t MC_LOCKONCLOCK_1;                   /**< Main Controller Clock Present Register, offset: 0x6 */
} MAINCONTROLLER_Type;

/* ----------------------------------------------------------------------------
   -- MAINCONTROLLER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAINCONTROLLER_Register_Masks MAINCONTROLLER Register Masks
 * @{
 */

/*! @name MC_CLKDIS - Main Controller Synchronous Clock Domain Disable Register */
/*! @{ */

#define MAINCONTROLLER_MC_CLKDIS_PIXELCLK_DISABLE_MASK (0x1U)
#define MAINCONTROLLER_MC_CLKDIS_PIXELCLK_DISABLE_SHIFT (0U)
/*! pixelclk_disable - Pixel clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_PIXELCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_PIXELCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_PIXELCLK_DISABLE_MASK)

#define MAINCONTROLLER_MC_CLKDIS_TMDSCLK_DISABLE_MASK (0x2U)
#define MAINCONTROLLER_MC_CLKDIS_TMDSCLK_DISABLE_SHIFT (1U)
/*! tmdsclk_disable - TMDS clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_TMDSCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_TMDSCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_TMDSCLK_DISABLE_MASK)

#define MAINCONTROLLER_MC_CLKDIS_PREPCLK_DISABLE_MASK (0x4U)
#define MAINCONTROLLER_MC_CLKDIS_PREPCLK_DISABLE_SHIFT (2U)
/*! prepclk_disable - Pixel Repetition clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_PREPCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_PREPCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_PREPCLK_DISABLE_MASK)

#define MAINCONTROLLER_MC_CLKDIS_AUDCLK_DISABLE_MASK (0x8U)
#define MAINCONTROLLER_MC_CLKDIS_AUDCLK_DISABLE_SHIFT (3U)
/*! audclk_disable - Audio Sampler clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_AUDCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_AUDCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_AUDCLK_DISABLE_MASK)

#define MAINCONTROLLER_MC_CLKDIS_CSCCLK_DISABLE_MASK (0x10U)
#define MAINCONTROLLER_MC_CLKDIS_CSCCLK_DISABLE_SHIFT (4U)
/*! cscclk_disable - Color Space Converter clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_CSCCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_CSCCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_CSCCLK_DISABLE_MASK)

#define MAINCONTROLLER_MC_CLKDIS_CECCLK_DISABLE_MASK (0x20U)
#define MAINCONTROLLER_MC_CLKDIS_CECCLK_DISABLE_SHIFT (5U)
/*! cecclk_disable - CEC Engine clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_CECCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_CECCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_CECCLK_DISABLE_MASK)

#define MAINCONTROLLER_MC_CLKDIS_HDCPCLK_DISABLE_MASK (0x40U)
#define MAINCONTROLLER_MC_CLKDIS_HDCPCLK_DISABLE_SHIFT (6U)
/*! hdcpclk_disable - HDCP clock synchronous disable signal. */
#define MAINCONTROLLER_MC_CLKDIS_HDCPCLK_DISABLE(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_CLKDIS_HDCPCLK_DISABLE_SHIFT)) & MAINCONTROLLER_MC_CLKDIS_HDCPCLK_DISABLE_MASK)
/*! @} */

/*! @name MC_SWRSTZREQ_1 - Main Controller Software Reset Register Main controller software reset request per clock domain. */
/*! @{ */

#define MAINCONTROLLER_MC_SWRSTZREQ_1_PIXELSWRST_REQ_MASK (0x1U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_PIXELSWRST_REQ_SHIFT (0U)
/*! pixelswrst_req - Pixel software reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_PIXELSWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_PIXELSWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_PIXELSWRST_REQ_MASK)

#define MAINCONTROLLER_MC_SWRSTZREQ_1_TMDSSWRST_REQ_MASK (0x2U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_TMDSSWRST_REQ_SHIFT (1U)
/*! tmdsswrst_req - TMDS software reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_TMDSSWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_TMDSSWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_TMDSSWRST_REQ_MASK)

#define MAINCONTROLLER_MC_SWRSTZREQ_1_PREPSWRST_REQ_MASK (0x4U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_PREPSWRST_REQ_SHIFT (2U)
/*! prepswrst_req - Pixel Repetition software reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_PREPSWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_PREPSWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_PREPSWRST_REQ_MASK)

#define MAINCONTROLLER_MC_SWRSTZREQ_1_II2SSWRST_REQ_MASK (0x8U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_II2SSWRST_REQ_SHIFT (3U)
/*! ii2sswrst_req - I2S audio software reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_II2SSWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_II2SSWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_II2SSWRST_REQ_MASK)

#define MAINCONTROLLER_MC_SWRSTZREQ_1_ISPDIFSWRST_REQ_MASK (0x10U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_ISPDIFSWRST_REQ_SHIFT (4U)
/*! ispdifswrst_req - SPDIF audio software reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_ISPDIFSWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_ISPDIFSWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_ISPDIFSWRST_REQ_MASK)

#define MAINCONTROLLER_MC_SWRSTZREQ_1_CECSWRST_REQ_MASK (0x40U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_CECSWRST_REQ_SHIFT (6U)
/*! cecswrst_req - CEC software reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_CECSWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_CECSWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_CECSWRST_REQ_MASK)

#define MAINCONTROLLER_MC_SWRSTZREQ_1_IGPASWRST_REQ_MASK (0x80U)
#define MAINCONTROLLER_MC_SWRSTZREQ_1_IGPASWRST_REQ_SHIFT (7U)
/*! igpaswrst_req - GPAUD interface soft reset request. */
#define MAINCONTROLLER_MC_SWRSTZREQ_1_IGPASWRST_REQ(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_SWRSTZREQ_1_IGPASWRST_REQ_SHIFT)) & MAINCONTROLLER_MC_SWRSTZREQ_1_IGPASWRST_REQ_MASK)
/*! @} */

/*! @name MC_OPCTRL - Main Controller HDCP Bypass Control Register */
/*! @{ */

#define MAINCONTROLLER_MC_OPCTRL_HDCP_BLOCK_BYP_MASK (0x1U)
#define MAINCONTROLLER_MC_OPCTRL_HDCP_BLOCK_BYP_SHIFT (0U)
/*! hdcp_block_byp - Block HDCP bypass mechanism - 1'b0: This is the default value. */
#define MAINCONTROLLER_MC_OPCTRL_HDCP_BLOCK_BYP(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_OPCTRL_HDCP_BLOCK_BYP_SHIFT)) & MAINCONTROLLER_MC_OPCTRL_HDCP_BLOCK_BYP_MASK)
/*! @} */

/*! @name MC_FLOWCTRL - Main Controller Feed Through Control Register */
/*! @{ */

#define MAINCONTROLLER_MC_FLOWCTRL_FEED_THROUGH_OFF_MASK (0x1U)
#define MAINCONTROLLER_MC_FLOWCTRL_FEED_THROUGH_OFF_SHIFT (0U)
/*! Feed_through_off - Video path Feed Through enable bit: - 1b: Color Space Converter is in the video data path. */
#define MAINCONTROLLER_MC_FLOWCTRL_FEED_THROUGH_OFF(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_FLOWCTRL_FEED_THROUGH_OFF_SHIFT)) & MAINCONTROLLER_MC_FLOWCTRL_FEED_THROUGH_OFF_MASK)
/*! @} */

/*! @name MC_PHYRSTZ - Main Controller PHY Reset Register */
/*! @{ */

#define MAINCONTROLLER_MC_PHYRSTZ_PHYRSTZ_MASK   (0x1U)
#define MAINCONTROLLER_MC_PHYRSTZ_PHYRSTZ_SHIFT  (0U)
/*! phyrstz - HDMI Source PHY active low reset control for PHY GEN1, active high reset control for PHY GEN2. */
#define MAINCONTROLLER_MC_PHYRSTZ_PHYRSTZ(x)     (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_PHYRSTZ_PHYRSTZ_SHIFT)) & MAINCONTROLLER_MC_PHYRSTZ_PHYRSTZ_MASK)
/*! @} */

/*! @name MC_LOCKONCLOCK_1 - Main Controller Clock Present Register */
/*! @{ */

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_CECCLK_MASK (0x1U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_CECCLK_SHIFT (0U)
/*! cecclk - CEC clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_CECCLK(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_CECCLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_CECCLK_MASK)

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_AUDIOSPDIFCLK_MASK (0x4U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_AUDIOSPDIFCLK_SHIFT (2U)
/*! audiospdifclk - SPDIF clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_AUDIOSPDIFCLK(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_AUDIOSPDIFCLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_AUDIOSPDIFCLK_MASK)

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_I2SCLK_MASK (0x8U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_I2SCLK_SHIFT (3U)
/*! i2sclk - I2S clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_I2SCLK(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_I2SCLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_I2SCLK_MASK)

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_PREPCLK_MASK (0x10U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_PREPCLK_SHIFT (4U)
/*! prepclk - Pixel Repetition clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_PREPCLK(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_PREPCLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_PREPCLK_MASK)

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_TCLK_MASK (0x20U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_TCLK_SHIFT (5U)
/*! tclk - TMDS clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_TCLK(x)  (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_TCLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_TCLK_MASK)

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_PCLK_MASK (0x40U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_PCLK_SHIFT (6U)
/*! pclk - Pixel clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_PCLK(x)  (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_PCLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_PCLK_MASK)

#define MAINCONTROLLER_MC_LOCKONCLOCK_1_IGPACLK_MASK (0x80U)
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_IGPACLK_SHIFT (7U)
/*! igpaclk - GPAUD interface clock status. */
#define MAINCONTROLLER_MC_LOCKONCLOCK_1_IGPACLK(x) (((uint8_t)(((uint8_t)(x)) << MAINCONTROLLER_MC_LOCKONCLOCK_1_IGPACLK_SHIFT)) & MAINCONTROLLER_MC_LOCKONCLOCK_1_IGPACLK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MAINCONTROLLER_Register_Masks */


/*!
 * @}
 */ /* end of group MAINCONTROLLER_Peripheral_Access_Layer */


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


#endif  /* PERI_MAINCONTROLLER_H_ */

