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
**         CMSIS Peripheral Access Layer for MIPI_DSI
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
 * @file PERI_MIPI_DSI.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI
 */

#if !defined(PERI_MIPI_DSI_H_)
#define PERI_MIPI_DSI_H_                         /**< Symbol preventing repeated inclusion */

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
   -- MIPI_DSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_Peripheral_Access_Layer MIPI_DSI Peripheral Access Layer
 * @{
 */

/** MIPI_DSI - Register Layout Typedef */
typedef struct {
  __I  uint32_t DSI_VERSION;                       /**< Specifies the DSI version register., offset: 0x0 */
  __I  uint32_t DSI_STATUS;                        /**< Specifies the status register., offset: 0x4 */
  __I  uint32_t DSI_RGB_STATUS;                    /**< Specifies the RGB FSM status register., offset: 0x8 */
  __IO uint32_t DSI_SWRST;                         /**< Specifies the software reset register., offset: 0xC */
  __IO uint32_t DSI_CLKCTRL;                       /**< Specifies the clock control register., offset: 0x10 */
  __IO uint32_t DSI_TIMEOUT;                       /**< Specifies the time out register., offset: 0x14 */
  __IO uint32_t DSI_CONFIG;                        /**< Specifies the configuration register., offset: 0x18 */
  __IO uint32_t DSI_ESCMODE;                       /**< Specifies the escape mode register., offset: 0x1C */
  __IO uint32_t DSI_MDRESOL;                       /**< Specifies the main display image resolution register., offset: 0x20 */
  __IO uint32_t DSI_MVPORCH;                       /**< Specifies the main display Vporch register., offset: 0x24 */
  __IO uint32_t DSI_MHPORCH;                       /**< Specifies the main display Hporch register., offset: 0x28 */
  __IO uint32_t DSI_MSYNC;                         /**< Specifies the main display Sync Area register., offset: 0x2C */
  __IO uint32_t DSI_SDRESOL;                       /**< Specifies the sub display image resolution register., offset: 0x30 */
  __IO uint32_t DSI_INTSRC;                        /**< Specifies the interrupt source register., offset: 0x34 */
  __IO uint32_t DSI_INTMSK;                        /**< Specifies the interrupt mask register., offset: 0x38 */
  __O  uint32_t DSI_PKTHDR;                        /**< Specifies the packet header FIFO register., offset: 0x3C */
  __O  uint32_t DSI_PAYLOAD;                       /**< Specifies the payload FIFO register., offset: 0x40 */
  __I  uint32_t DSI_RXFIFO;                        /**< Specifies the read FIFO register., offset: 0x44 */
  __IO uint32_t DSI_FIFOTHLD;                      /**< Specifies the FIFO threshold level register., offset: 0x48 */
  __IO uint32_t DSI_FIFOCTRL;                      /**< Specifies the FIFO status and control register., offset: 0x4C */
  __IO uint32_t DSI_MEMACCHR;                      /**< Specifies the FIFO memory AC characteristic register., offset: 0x50 */
       uint8_t RESERVED_0[36];
  __IO uint32_t DSI_MULTI_PKT;                     /**< Specifies the Multi Packet, Packet Go register., offset: 0x78 */
       uint8_t RESERVED_1[20];
  __IO uint32_t DSI_PLLCTRL_1G;                    /**< Specifies the 1Gbps D-PHY PLL control register., offset: 0x90 */
  __IO uint32_t DSI_PLLCTRL;                       /**< Specifies the PLL control register., offset: 0x94 */
  __IO uint32_t DSI_PLLCTRL1;                      /**< Specifies the PLL control register 1., offset: 0x98 */
  __IO uint32_t DSI_PLLCTRL2;                      /**< Specifies the PLL control register 2., offset: 0x9C */
  __IO uint32_t DSI_PLLTMR;                        /**< Specifies the PLL timer register., offset: 0xA0 */
  __IO uint32_t DSI_PHYCTRL_B1;                    /**< Specifies the D-PHY control register 1., offset: 0xA4 */
  __IO uint32_t DSI_PHYCTRL_B2;                    /**< Specifies the D-PHY control register 2., offset: 0xA8 */
  __IO uint32_t DSI_PHYCTRL_M1;                    /**< Specifies the D-PHY control register 1., offset: 0xAC */
  __IO uint32_t DSI_PHYCTRL_M2;                    /**< Specifies the D-PHY control register 2., offset: 0xB0 */
  __IO uint32_t DSI_PHYTIMING;                     /**< Specifies the D-PHY timing register., offset: 0xB4 */
  __IO uint32_t DSI_PHYTIMING1;                    /**< Specifies the D-PHY timing register 1., offset: 0xB8 */
  __IO uint32_t DSI_PHYTIMING2;                    /**< Specifies the D-PHY timing register 2., offset: 0xBC */
} MIPI_DSI_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_Register_Masks MIPI_DSI Register Masks
 * @{
 */

/*! @name DSI_VERSION - Specifies the DSI version register. */
/*! @{ */

#define MIPI_DSI_DSI_VERSION_VERSION_MASK        (0xFFFFFFFFU)
#define MIPI_DSI_DSI_VERSION_VERSION_SHIFT       (0U)
#define MIPI_DSI_DSI_VERSION_VERSION(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_VERSION_VERSION_SHIFT)) & MIPI_DSI_DSI_VERSION_VERSION_MASK)
/*! @} */

/*! @name DSI_STATUS - Specifies the status register. */
/*! @{ */

#define MIPI_DSI_DSI_STATUS_STOPSTATEDAT_MASK    (0xFU)
#define MIPI_DSI_DSI_STATUS_STOPSTATEDAT_SHIFT   (0U)
#define MIPI_DSI_DSI_STATUS_STOPSTATEDAT(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_STOPSTATEDAT_SHIFT)) & MIPI_DSI_DSI_STATUS_STOPSTATEDAT_MASK)

#define MIPI_DSI_DSI_STATUS_ULPSDAT_MASK         (0xF0U)
#define MIPI_DSI_DSI_STATUS_ULPSDAT_SHIFT        (4U)
#define MIPI_DSI_DSI_STATUS_ULPSDAT(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_ULPSDAT_SHIFT)) & MIPI_DSI_DSI_STATUS_ULPSDAT_MASK)

#define MIPI_DSI_DSI_STATUS_STOPSTATECLK_MASK    (0x100U)
#define MIPI_DSI_DSI_STATUS_STOPSTATECLK_SHIFT   (8U)
#define MIPI_DSI_DSI_STATUS_STOPSTATECLK(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_STOPSTATECLK_SHIFT)) & MIPI_DSI_DSI_STATUS_STOPSTATECLK_MASK)

#define MIPI_DSI_DSI_STATUS_ULPSCLK_MASK         (0x200U)
#define MIPI_DSI_DSI_STATUS_ULPSCLK_SHIFT        (9U)
#define MIPI_DSI_DSI_STATUS_ULPSCLK(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_ULPSCLK_SHIFT)) & MIPI_DSI_DSI_STATUS_ULPSCLK_MASK)

#define MIPI_DSI_DSI_STATUS_TXREADYHSCLK_MASK    (0x400U)
#define MIPI_DSI_DSI_STATUS_TXREADYHSCLK_SHIFT   (10U)
#define MIPI_DSI_DSI_STATUS_TXREADYHSCLK(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_TXREADYHSCLK_SHIFT)) & MIPI_DSI_DSI_STATUS_TXREADYHSCLK_MASK)

#define MIPI_DSI_DSI_STATUS_DIRECTION_MASK       (0x10000U)
#define MIPI_DSI_DSI_STATUS_DIRECTION_SHIFT      (16U)
#define MIPI_DSI_DSI_STATUS_DIRECTION(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_DIRECTION_SHIFT)) & MIPI_DSI_DSI_STATUS_DIRECTION_MASK)

#define MIPI_DSI_DSI_STATUS_SWRSTRLS_MASK        (0x100000U)
#define MIPI_DSI_DSI_STATUS_SWRSTRLS_SHIFT       (20U)
#define MIPI_DSI_DSI_STATUS_SWRSTRLS(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_SWRSTRLS_SHIFT)) & MIPI_DSI_DSI_STATUS_SWRSTRLS_MASK)

#define MIPI_DSI_DSI_STATUS_PLLSTABLE_MASK       (0x80000000U)
#define MIPI_DSI_DSI_STATUS_PLLSTABLE_SHIFT      (31U)
#define MIPI_DSI_DSI_STATUS_PLLSTABLE(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_PLLSTABLE_SHIFT)) & MIPI_DSI_DSI_STATUS_PLLSTABLE_MASK)
/*! @} */

/*! @name DSI_RGB_STATUS - Specifies the RGB FSM status register. */
/*! @{ */

#define MIPI_DSI_DSI_RGB_STATUS_RGBSTATE_MASK    (0x1FFFU)
#define MIPI_DSI_DSI_RGB_STATUS_RGBSTATE_SHIFT   (0U)
#define MIPI_DSI_DSI_RGB_STATUS_RGBSTATE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_RGB_STATUS_RGBSTATE_SHIFT)) & MIPI_DSI_DSI_RGB_STATUS_RGBSTATE_MASK)

#define MIPI_DSI_DSI_RGB_STATUS_CMDMODE_INSEL_MASK (0x80000000U)
#define MIPI_DSI_DSI_RGB_STATUS_CMDMODE_INSEL_SHIFT (31U)
#define MIPI_DSI_DSI_RGB_STATUS_CMDMODE_INSEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_RGB_STATUS_CMDMODE_INSEL_SHIFT)) & MIPI_DSI_DSI_RGB_STATUS_CMDMODE_INSEL_MASK)
/*! @} */

/*! @name DSI_SWRST - Specifies the software reset register. */
/*! @{ */

#define MIPI_DSI_DSI_SWRST_SWRST_MASK            (0x1U)
#define MIPI_DSI_DSI_SWRST_SWRST_SHIFT           (0U)
#define MIPI_DSI_DSI_SWRST_SWRST(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SWRST_SWRST_SHIFT)) & MIPI_DSI_DSI_SWRST_SWRST_MASK)

#define MIPI_DSI_DSI_SWRST_FUNCRST_MASK          (0x10000U)
#define MIPI_DSI_DSI_SWRST_FUNCRST_SHIFT         (16U)
#define MIPI_DSI_DSI_SWRST_FUNCRST(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SWRST_FUNCRST_SHIFT)) & MIPI_DSI_DSI_SWRST_FUNCRST_MASK)
/*! @} */

/*! @name DSI_CLKCTRL - Specifies the clock control register. */
/*! @{ */

#define MIPI_DSI_DSI_CLKCTRL_ESCPRESCALER_MASK   (0xFFFFU)
#define MIPI_DSI_DSI_CLKCTRL_ESCPRESCALER_SHIFT  (0U)
#define MIPI_DSI_DSI_CLKCTRL_ESCPRESCALER(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_ESCPRESCALER_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_ESCPRESCALER_MASK)

#define MIPI_DSI_DSI_CLKCTRL_LANEESCCLKEN_MASK   (0xF80000U)
#define MIPI_DSI_DSI_CLKCTRL_LANEESCCLKEN_SHIFT  (19U)
#define MIPI_DSI_DSI_CLKCTRL_LANEESCCLKEN(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_LANEESCCLKEN_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_LANEESCCLKEN_MASK)

#define MIPI_DSI_DSI_CLKCTRL_BYTECLKEN_MASK      (0x1000000U)
#define MIPI_DSI_DSI_CLKCTRL_BYTECLKEN_SHIFT     (24U)
#define MIPI_DSI_DSI_CLKCTRL_BYTECLKEN(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_BYTECLKEN_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_BYTECLKEN_MASK)

#define MIPI_DSI_DSI_CLKCTRL_BYTECLKSRC_MASK     (0x6000000U)
#define MIPI_DSI_DSI_CLKCTRL_BYTECLKSRC_SHIFT    (25U)
#define MIPI_DSI_DSI_CLKCTRL_BYTECLKSRC(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_BYTECLKSRC_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_BYTECLKSRC_MASK)

#define MIPI_DSI_DSI_CLKCTRL_PLLBYPASS_MASK      (0x8000000U)
#define MIPI_DSI_DSI_CLKCTRL_PLLBYPASS_SHIFT     (27U)
#define MIPI_DSI_DSI_CLKCTRL_PLLBYPASS(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_PLLBYPASS_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_PLLBYPASS_MASK)

#define MIPI_DSI_DSI_CLKCTRL_ESCCLKEN_MASK       (0x10000000U)
#define MIPI_DSI_DSI_CLKCTRL_ESCCLKEN_SHIFT      (28U)
#define MIPI_DSI_DSI_CLKCTRL_ESCCLKEN(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_ESCCLKEN_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_ESCCLKEN_MASK)

#define MIPI_DSI_DSI_CLKCTRL_DPHY_SEL_MASK       (0x20000000U)
#define MIPI_DSI_DSI_CLKCTRL_DPHY_SEL_SHIFT      (29U)
#define MIPI_DSI_DSI_CLKCTRL_DPHY_SEL(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_DPHY_SEL_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_DPHY_SEL_MASK)

#define MIPI_DSI_DSI_CLKCTRL_TXREQUESTHSCLK_MASK (0x80000000U)
#define MIPI_DSI_DSI_CLKCTRL_TXREQUESTHSCLK_SHIFT (31U)
#define MIPI_DSI_DSI_CLKCTRL_TXREQUESTHSCLK(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_TXREQUESTHSCLK_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_TXREQUESTHSCLK_MASK)
/*! @} */

/*! @name DSI_TIMEOUT - Specifies the time out register. */
/*! @{ */

#define MIPI_DSI_DSI_TIMEOUT_LPDRTOUT_MASK       (0xFFFFU)
#define MIPI_DSI_DSI_TIMEOUT_LPDRTOUT_SHIFT      (0U)
#define MIPI_DSI_DSI_TIMEOUT_LPDRTOUT(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_TIMEOUT_LPDRTOUT_SHIFT)) & MIPI_DSI_DSI_TIMEOUT_LPDRTOUT_MASK)

#define MIPI_DSI_DSI_TIMEOUT_BTATOUT_MASK        (0xFF0000U)
#define MIPI_DSI_DSI_TIMEOUT_BTATOUT_SHIFT       (16U)
#define MIPI_DSI_DSI_TIMEOUT_BTATOUT(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_TIMEOUT_BTATOUT_SHIFT)) & MIPI_DSI_DSI_TIMEOUT_BTATOUT_MASK)
/*! @} */

/*! @name DSI_CONFIG - Specifies the configuration register. */
/*! @{ */

#define MIPI_DSI_DSI_CONFIG_LANEEN_MASK          (0x1FU)
#define MIPI_DSI_DSI_CONFIG_LANEEN_SHIFT         (0U)
#define MIPI_DSI_DSI_CONFIG_LANEEN(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_LANEEN_SHIFT)) & MIPI_DSI_DSI_CONFIG_LANEEN_MASK)

#define MIPI_DSI_DSI_CONFIG_NUMOFDATLANE_MASK    (0x60U)
#define MIPI_DSI_DSI_CONFIG_NUMOFDATLANE_SHIFT   (5U)
#define MIPI_DSI_DSI_CONFIG_NUMOFDATLANE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_NUMOFDATLANE_SHIFT)) & MIPI_DSI_DSI_CONFIG_NUMOFDATLANE_MASK)

#define MIPI_DSI_DSI_CONFIG_SUBPIXFORMAT_MASK    (0x700U)
#define MIPI_DSI_DSI_CONFIG_SUBPIXFORMAT_SHIFT   (8U)
#define MIPI_DSI_DSI_CONFIG_SUBPIXFORMAT(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_SUBPIXFORMAT_SHIFT)) & MIPI_DSI_DSI_CONFIG_SUBPIXFORMAT_MASK)

#define MIPI_DSI_DSI_CONFIG_MAINPIXFORMAT_MASK   (0x7000U)
#define MIPI_DSI_DSI_CONFIG_MAINPIXFORMAT_SHIFT  (12U)
#define MIPI_DSI_DSI_CONFIG_MAINPIXFORMAT(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_MAINPIXFORMAT_SHIFT)) & MIPI_DSI_DSI_CONFIG_MAINPIXFORMAT_MASK)

#define MIPI_DSI_DSI_CONFIG_SUBVC_MASK           (0x30000U)
#define MIPI_DSI_DSI_CONFIG_SUBVC_SHIFT          (16U)
#define MIPI_DSI_DSI_CONFIG_SUBVC(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_SUBVC_SHIFT)) & MIPI_DSI_DSI_CONFIG_SUBVC_MASK)

#define MIPI_DSI_DSI_CONFIG_MAINVC_MASK          (0xC0000U)
#define MIPI_DSI_DSI_CONFIG_MAINVC_SHIFT         (18U)
#define MIPI_DSI_DSI_CONFIG_MAINVC(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_MAINVC_SHIFT)) & MIPI_DSI_DSI_CONFIG_MAINVC_MASK)

#define MIPI_DSI_DSI_CONFIG_HSADISABLEMODE_MASK  (0x100000U)
#define MIPI_DSI_DSI_CONFIG_HSADISABLEMODE_SHIFT (20U)
#define MIPI_DSI_DSI_CONFIG_HSADISABLEMODE(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HSADISABLEMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_HSADISABLEMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_HBPDISABLEMODE_MASK  (0x200000U)
#define MIPI_DSI_DSI_CONFIG_HBPDISABLEMODE_SHIFT (21U)
#define MIPI_DSI_DSI_CONFIG_HBPDISABLEMODE(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HBPDISABLEMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_HBPDISABLEMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_HFPDISABLEMODE_MASK  (0x400000U)
#define MIPI_DSI_DSI_CONFIG_HFPDISABLEMODE_SHIFT (22U)
#define MIPI_DSI_DSI_CONFIG_HFPDISABLEMODE(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HFPDISABLEMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_HFPDISABLEMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_HSEDISABLEMODE_MASK  (0x800000U)
#define MIPI_DSI_DSI_CONFIG_HSEDISABLEMODE_SHIFT (23U)
#define MIPI_DSI_DSI_CONFIG_HSEDISABLEMODE(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HSEDISABLEMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_HSEDISABLEMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_AUTOMODE_MASK        (0x1000000U)
#define MIPI_DSI_DSI_CONFIG_AUTOMODE_SHIFT       (24U)
#define MIPI_DSI_DSI_CONFIG_AUTOMODE(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_AUTOMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_AUTOMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_VIDEOMODE_MASK       (0x2000000U)
#define MIPI_DSI_DSI_CONFIG_VIDEOMODE_SHIFT      (25U)
#define MIPI_DSI_DSI_CONFIG_VIDEOMODE(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_VIDEOMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_VIDEOMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_BURSTMODE_MASK       (0x4000000U)
#define MIPI_DSI_DSI_CONFIG_BURSTMODE_SHIFT      (26U)
#define MIPI_DSI_DSI_CONFIG_BURSTMODE(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_BURSTMODE_SHIFT)) & MIPI_DSI_DSI_CONFIG_BURSTMODE_MASK)

#define MIPI_DSI_DSI_CONFIG_SYNCINFORM_MASK      (0x8000000U)
#define MIPI_DSI_DSI_CONFIG_SYNCINFORM_SHIFT     (27U)
#define MIPI_DSI_DSI_CONFIG_SYNCINFORM(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_SYNCINFORM_SHIFT)) & MIPI_DSI_DSI_CONFIG_SYNCINFORM_MASK)

#define MIPI_DSI_DSI_CONFIG_EOT_R03_MASK         (0x10000000U)
#define MIPI_DSI_DSI_CONFIG_EOT_R03_SHIFT        (28U)
#define MIPI_DSI_DSI_CONFIG_EOT_R03(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_EOT_R03_SHIFT)) & MIPI_DSI_DSI_CONFIG_EOT_R03_MASK)

#define MIPI_DSI_DSI_CONFIG_MFLUSH_VS_MASK       (0x20000000U)
#define MIPI_DSI_DSI_CONFIG_MFLUSH_VS_SHIFT      (29U)
#define MIPI_DSI_DSI_CONFIG_MFLUSH_VS(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_MFLUSH_VS_SHIFT)) & MIPI_DSI_DSI_CONFIG_MFLUSH_VS_MASK)

#define MIPI_DSI_DSI_CONFIG_CLKLANE_STOP_START_MASK (0x40000000U)
#define MIPI_DSI_DSI_CONFIG_CLKLANE_STOP_START_SHIFT (30U)
#define MIPI_DSI_DSI_CONFIG_CLKLANE_STOP_START(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_CLKLANE_STOP_START_SHIFT)) & MIPI_DSI_DSI_CONFIG_CLKLANE_STOP_START_MASK)

#define MIPI_DSI_DSI_CONFIG_NON_CONTINUOUS_CLOCK_LANE_MASK (0x80000000U)
#define MIPI_DSI_DSI_CONFIG_NON_CONTINUOUS_CLOCK_LANE_SHIFT (31U)
#define MIPI_DSI_DSI_CONFIG_NON_CONTINUOUS_CLOCK_LANE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_NON_CONTINUOUS_CLOCK_LANE_SHIFT)) & MIPI_DSI_DSI_CONFIG_NON_CONTINUOUS_CLOCK_LANE_MASK)
/*! @} */

/*! @name DSI_ESCMODE - Specifies the escape mode register. */
/*! @{ */

#define MIPI_DSI_DSI_ESCMODE_TXULPSCLKEXIT_MASK  (0x1U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSCLKEXIT_SHIFT (0U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSCLKEXIT(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TXULPSCLKEXIT_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TXULPSCLKEXIT_MASK)

#define MIPI_DSI_DSI_ESCMODE_TXULPSCLK_MASK      (0x2U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSCLK_SHIFT     (1U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSCLK(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TXULPSCLK_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TXULPSCLK_MASK)

#define MIPI_DSI_DSI_ESCMODE_TXULPSEXIT_MASK     (0x4U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSEXIT_SHIFT    (2U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSEXIT(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TXULPSEXIT_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TXULPSEXIT_MASK)

#define MIPI_DSI_DSI_ESCMODE_TXULPSDAT_MASK      (0x8U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSDAT_SHIFT     (3U)
#define MIPI_DSI_DSI_ESCMODE_TXULPSDAT(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TXULPSDAT_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TXULPSDAT_MASK)

#define MIPI_DSI_DSI_ESCMODE_TXTRIGGERRST_MASK   (0x10U)
#define MIPI_DSI_DSI_ESCMODE_TXTRIGGERRST_SHIFT  (4U)
#define MIPI_DSI_DSI_ESCMODE_TXTRIGGERRST(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TXTRIGGERRST_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TXTRIGGERRST_MASK)

#define MIPI_DSI_DSI_ESCMODE_TXLPDT_MASK         (0x40U)
#define MIPI_DSI_DSI_ESCMODE_TXLPDT_SHIFT        (6U)
#define MIPI_DSI_DSI_ESCMODE_TXLPDT(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TXLPDT_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TXLPDT_MASK)

#define MIPI_DSI_DSI_ESCMODE_CMDLPDT_MASK        (0x80U)
#define MIPI_DSI_DSI_ESCMODE_CMDLPDT_SHIFT       (7U)
#define MIPI_DSI_DSI_ESCMODE_CMDLPDT(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_CMDLPDT_SHIFT)) & MIPI_DSI_DSI_ESCMODE_CMDLPDT_MASK)

#define MIPI_DSI_DSI_ESCMODE_FORCEBTA_MASK       (0x10000U)
#define MIPI_DSI_DSI_ESCMODE_FORCEBTA_SHIFT      (16U)
#define MIPI_DSI_DSI_ESCMODE_FORCEBTA(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_FORCEBTA_SHIFT)) & MIPI_DSI_DSI_ESCMODE_FORCEBTA_MASK)

#define MIPI_DSI_DSI_ESCMODE_FORCESTOPSTATE__MASK (0x100000U)
#define MIPI_DSI_DSI_ESCMODE_FORCESTOPSTATE__SHIFT (20U)
#define MIPI_DSI_DSI_ESCMODE_FORCESTOPSTATE_(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_FORCESTOPSTATE__SHIFT)) & MIPI_DSI_DSI_ESCMODE_FORCESTOPSTATE__MASK)

#define MIPI_DSI_DSI_ESCMODE_STOPSTATE_CNT_MASK  (0xFFE00000U)
#define MIPI_DSI_DSI_ESCMODE_STOPSTATE_CNT_SHIFT (21U)
#define MIPI_DSI_DSI_ESCMODE_STOPSTATE_CNT(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_STOPSTATE_CNT_SHIFT)) & MIPI_DSI_DSI_ESCMODE_STOPSTATE_CNT_MASK)
/*! @} */

/*! @name DSI_MDRESOL - Specifies the main display image resolution register. */
/*! @{ */

#define MIPI_DSI_DSI_MDRESOL_MAINHRESOL_MASK     (0xFFFU)
#define MIPI_DSI_DSI_MDRESOL_MAINHRESOL_SHIFT    (0U)
#define MIPI_DSI_DSI_MDRESOL_MAINHRESOL(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MDRESOL_MAINHRESOL_SHIFT)) & MIPI_DSI_DSI_MDRESOL_MAINHRESOL_MASK)

#define MIPI_DSI_DSI_MDRESOL_MAINVRESOL_MASK     (0xFFF0000U)
#define MIPI_DSI_DSI_MDRESOL_MAINVRESOL_SHIFT    (16U)
#define MIPI_DSI_DSI_MDRESOL_MAINVRESOL(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MDRESOL_MAINVRESOL_SHIFT)) & MIPI_DSI_DSI_MDRESOL_MAINVRESOL_MASK)

#define MIPI_DSI_DSI_MDRESOL_MAINSTANDBY_MASK    (0x80000000U)
#define MIPI_DSI_DSI_MDRESOL_MAINSTANDBY_SHIFT   (31U)
#define MIPI_DSI_DSI_MDRESOL_MAINSTANDBY(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MDRESOL_MAINSTANDBY_SHIFT)) & MIPI_DSI_DSI_MDRESOL_MAINSTANDBY_MASK)
/*! @} */

/*! @name DSI_MVPORCH - Specifies the main display Vporch register. */
/*! @{ */

#define MIPI_DSI_DSI_MVPORCH_MAINVBP_MASK        (0x7FFU)
#define MIPI_DSI_DSI_MVPORCH_MAINVBP_SHIFT       (0U)
#define MIPI_DSI_DSI_MVPORCH_MAINVBP(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MVPORCH_MAINVBP_SHIFT)) & MIPI_DSI_DSI_MVPORCH_MAINVBP_MASK)

#define MIPI_DSI_DSI_MVPORCH_STABLEVFP_MASK      (0x7FF0000U)
#define MIPI_DSI_DSI_MVPORCH_STABLEVFP_SHIFT     (16U)
#define MIPI_DSI_DSI_MVPORCH_STABLEVFP(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MVPORCH_STABLEVFP_SHIFT)) & MIPI_DSI_DSI_MVPORCH_STABLEVFP_MASK)

#define MIPI_DSI_DSI_MVPORCH_CMDALLOW_MASK       (0xF0000000U)
#define MIPI_DSI_DSI_MVPORCH_CMDALLOW_SHIFT      (28U)
#define MIPI_DSI_DSI_MVPORCH_CMDALLOW(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MVPORCH_CMDALLOW_SHIFT)) & MIPI_DSI_DSI_MVPORCH_CMDALLOW_MASK)
/*! @} */

/*! @name DSI_MHPORCH - Specifies the main display Hporch register. */
/*! @{ */

#define MIPI_DSI_DSI_MHPORCH_MAINHBP_MASK        (0xFFFFU)
#define MIPI_DSI_DSI_MHPORCH_MAINHBP_SHIFT       (0U)
#define MIPI_DSI_DSI_MHPORCH_MAINHBP(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MHPORCH_MAINHBP_SHIFT)) & MIPI_DSI_DSI_MHPORCH_MAINHBP_MASK)

#define MIPI_DSI_DSI_MHPORCH_MAINHFP_MASK        (0xFFFF0000U)
#define MIPI_DSI_DSI_MHPORCH_MAINHFP_SHIFT       (16U)
#define MIPI_DSI_DSI_MHPORCH_MAINHFP(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MHPORCH_MAINHFP_SHIFT)) & MIPI_DSI_DSI_MHPORCH_MAINHFP_MASK)
/*! @} */

/*! @name DSI_MSYNC - Specifies the main display Sync Area register. */
/*! @{ */

#define MIPI_DSI_DSI_MSYNC_MAINHSA_MASK          (0xFFFFU)
#define MIPI_DSI_DSI_MSYNC_MAINHSA_SHIFT         (0U)
#define MIPI_DSI_DSI_MSYNC_MAINHSA(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MSYNC_MAINHSA_SHIFT)) & MIPI_DSI_DSI_MSYNC_MAINHSA_MASK)

#define MIPI_DSI_DSI_MSYNC_MAINVSA_MASK          (0xFFC00000U)
#define MIPI_DSI_DSI_MSYNC_MAINVSA_SHIFT         (22U)
#define MIPI_DSI_DSI_MSYNC_MAINVSA(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MSYNC_MAINVSA_SHIFT)) & MIPI_DSI_DSI_MSYNC_MAINVSA_MASK)
/*! @} */

/*! @name DSI_SDRESOL - Specifies the sub display image resolution register. */
/*! @{ */

#define MIPI_DSI_DSI_SDRESOL_SUBHRESOL_MASK      (0x7FFU)
#define MIPI_DSI_DSI_SDRESOL_SUBHRESOL_SHIFT     (0U)
#define MIPI_DSI_DSI_SDRESOL_SUBHRESOL(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SDRESOL_SUBHRESOL_SHIFT)) & MIPI_DSI_DSI_SDRESOL_SUBHRESOL_MASK)

#define MIPI_DSI_DSI_SDRESOL_SUBVRESOL_MASK      (0x7FF0000U)
#define MIPI_DSI_DSI_SDRESOL_SUBVRESOL_SHIFT     (16U)
#define MIPI_DSI_DSI_SDRESOL_SUBVRESOL(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SDRESOL_SUBVRESOL_SHIFT)) & MIPI_DSI_DSI_SDRESOL_SUBVRESOL_MASK)

#define MIPI_DSI_DSI_SDRESOL_SUBSTANDBY_MASK     (0x80000000U)
#define MIPI_DSI_DSI_SDRESOL_SUBSTANDBY_SHIFT    (31U)
#define MIPI_DSI_DSI_SDRESOL_SUBSTANDBY(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SDRESOL_SUBSTANDBY_SHIFT)) & MIPI_DSI_DSI_SDRESOL_SUBSTANDBY_MASK)
/*! @} */

/*! @name DSI_INTSRC - Specifies the interrupt source register. */
/*! @{ */

#define MIPI_DSI_DSI_INTSRC_ERRCONTENTLP1_MASK   (0x1U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTENTLP1_SHIFT  (0U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTENTLP1(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRCONTENTLP1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRCONTENTLP1_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRCONTENTLP0_MASK   (0x2U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTENTLP0_SHIFT  (1U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTENTLP0(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRCONTENTLP0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRCONTENTLP0_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRCONTROL0_MASK     (0x4U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL0_SHIFT    (2U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRCONTROL0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRCONTROL0_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRCONTROL1_MASK     (0x8U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL1_SHIFT    (3U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRCONTROL1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRCONTROL1_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRCONTROL2_MASK     (0x10U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL2_SHIFT    (4U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL2(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRCONTROL2_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRCONTROL2_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRCONTROL3_MASK     (0x20U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL3_SHIFT    (5U)
#define MIPI_DSI_DSI_INTSRC_ERRCONTROL3(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRCONTROL3_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRCONTROL3_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRSYNC0_MASK        (0x40U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC0_SHIFT       (6U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC0(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRSYNC0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRSYNC0_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRSYNC1_MASK        (0x80U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC1_SHIFT       (7U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC1(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRSYNC1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRSYNC1_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRSYNC2_MASK        (0x100U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC2_SHIFT       (8U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC2(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRSYNC2_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRSYNC2_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRSYNC3_MASK        (0x200U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC3_SHIFT       (9U)
#define MIPI_DSI_DSI_INTSRC_ERRSYNC3(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRSYNC3_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRSYNC3_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRESC0_MASK         (0x400U)
#define MIPI_DSI_DSI_INTSRC_ERRESC0_SHIFT        (10U)
#define MIPI_DSI_DSI_INTSRC_ERRESC0(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRESC0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRESC0_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRESC1_MASK         (0x800U)
#define MIPI_DSI_DSI_INTSRC_ERRESC1_SHIFT        (11U)
#define MIPI_DSI_DSI_INTSRC_ERRESC1(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRESC1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRESC1_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRESC2_MASK         (0x1000U)
#define MIPI_DSI_DSI_INTSRC_ERRESC2_SHIFT        (12U)
#define MIPI_DSI_DSI_INTSRC_ERRESC2(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRESC2_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRESC2_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRESC3_MASK         (0x2000U)
#define MIPI_DSI_DSI_INTSRC_ERRESC3_SHIFT        (13U)
#define MIPI_DSI_DSI_INTSRC_ERRESC3(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRESC3_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRESC3_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRRXCRC_MASK        (0x4000U)
#define MIPI_DSI_DSI_INTSRC_ERRRXCRC_SHIFT       (14U)
#define MIPI_DSI_DSI_INTSRC_ERRRXCRC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRRXCRC_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRRXCRC_MASK)

#define MIPI_DSI_DSI_INTSRC_ERRRXECC_MASK        (0x8000U)
#define MIPI_DSI_DSI_INTSRC_ERRRXECC_SHIFT       (15U)
#define MIPI_DSI_DSI_INTSRC_ERRRXECC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ERRRXECC_SHIFT)) & MIPI_DSI_DSI_INTSRC_ERRRXECC_MASK)

#define MIPI_DSI_DSI_INTSRC_RXACK_MASK           (0x10000U)
#define MIPI_DSI_DSI_INTSRC_RXACK_SHIFT          (16U)
#define MIPI_DSI_DSI_INTSRC_RXACK(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_RXACK_SHIFT)) & MIPI_DSI_DSI_INTSRC_RXACK_MASK)

#define MIPI_DSI_DSI_INTSRC_RXTE_MASK            (0x20000U)
#define MIPI_DSI_DSI_INTSRC_RXTE_SHIFT           (17U)
#define MIPI_DSI_DSI_INTSRC_RXTE(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_RXTE_SHIFT)) & MIPI_DSI_DSI_INTSRC_RXTE_MASK)

#define MIPI_DSI_DSI_INTSRC_RXDATDONE_MASK       (0x40000U)
#define MIPI_DSI_DSI_INTSRC_RXDATDONE_SHIFT      (18U)
#define MIPI_DSI_DSI_INTSRC_RXDATDONE(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_RXDATDONE_SHIFT)) & MIPI_DSI_DSI_INTSRC_RXDATDONE_MASK)

#define MIPI_DSI_DSI_INTSRC_TATOUT_MASK          (0x100000U)
#define MIPI_DSI_DSI_INTSRC_TATOUT_SHIFT         (20U)
#define MIPI_DSI_DSI_INTSRC_TATOUT(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_TATOUT_SHIFT)) & MIPI_DSI_DSI_INTSRC_TATOUT_MASK)

#define MIPI_DSI_DSI_INTSRC_LPDRTOUT_MASK        (0x200000U)
#define MIPI_DSI_DSI_INTSRC_LPDRTOUT_SHIFT       (21U)
#define MIPI_DSI_DSI_INTSRC_LPDRTOUT(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_LPDRTOUT_SHIFT)) & MIPI_DSI_DSI_INTSRC_LPDRTOUT_MASK)

#define MIPI_DSI_DSI_INTSRC_FRAMEDONE_MASK       (0x1000000U)
#define MIPI_DSI_DSI_INTSRC_FRAMEDONE_SHIFT      (24U)
#define MIPI_DSI_DSI_INTSRC_FRAMEDONE(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_FRAMEDONE_SHIFT)) & MIPI_DSI_DSI_INTSRC_FRAMEDONE_MASK)

#define MIPI_DSI_DSI_INTSRC_BUSTURNOVER_MASK     (0x2000000U)
#define MIPI_DSI_DSI_INTSRC_BUSTURNOVER_SHIFT    (25U)
#define MIPI_DSI_DSI_INTSRC_BUSTURNOVER(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_BUSTURNOVER_SHIFT)) & MIPI_DSI_DSI_INTSRC_BUSTURNOVER_MASK)

#define MIPI_DSI_DSI_INTSRC_SYNCOVERRIDE_MASK    (0x8000000U)
#define MIPI_DSI_DSI_INTSRC_SYNCOVERRIDE_SHIFT   (27U)
#define MIPI_DSI_DSI_INTSRC_SYNCOVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SYNCOVERRIDE_SHIFT)) & MIPI_DSI_DSI_INTSRC_SYNCOVERRIDE_MASK)

#define MIPI_DSI_DSI_INTSRC_SFRPHFIFOEMPTY_MASK  (0x10000000U)
#define MIPI_DSI_DSI_INTSRC_SFRPHFIFOEMPTY_SHIFT (28U)
#define MIPI_DSI_DSI_INTSRC_SFRPHFIFOEMPTY(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SFRPHFIFOEMPTY_SHIFT)) & MIPI_DSI_DSI_INTSRC_SFRPHFIFOEMPTY_MASK)

#define MIPI_DSI_DSI_INTSRC_SFRPLFIFOEMPTY_MASK  (0x20000000U)
#define MIPI_DSI_DSI_INTSRC_SFRPLFIFOEMPTY_SHIFT (29U)
#define MIPI_DSI_DSI_INTSRC_SFRPLFIFOEMPTY(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SFRPLFIFOEMPTY_SHIFT)) & MIPI_DSI_DSI_INTSRC_SFRPLFIFOEMPTY_MASK)

#define MIPI_DSI_DSI_INTSRC_SWRSTRELEASE_MASK    (0x40000000U)
#define MIPI_DSI_DSI_INTSRC_SWRSTRELEASE_SHIFT   (30U)
#define MIPI_DSI_DSI_INTSRC_SWRSTRELEASE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SWRSTRELEASE_SHIFT)) & MIPI_DSI_DSI_INTSRC_SWRSTRELEASE_MASK)

#define MIPI_DSI_DSI_INTSRC_PLLSTABLE_MASK       (0x80000000U)
#define MIPI_DSI_DSI_INTSRC_PLLSTABLE_SHIFT      (31U)
#define MIPI_DSI_DSI_INTSRC_PLLSTABLE(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_PLLSTABLE_SHIFT)) & MIPI_DSI_DSI_INTSRC_PLLSTABLE_MASK)
/*! @} */

/*! @name DSI_INTMSK - Specifies the interrupt mask register. */
/*! @{ */

#define MIPI_DSI_DSI_INTMSK_MSKCONTENTLP1_MASK   (0x1U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTENTLP1_SHIFT  (0U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTENTLP1(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKCONTENTLP1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKCONTENTLP1_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKCONTENTLP0_MASK   (0x2U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTENTLP0_SHIFT  (1U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTENTLP0(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKCONTENTLP0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKCONTENTLP0_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKCONTROL0_MASK     (0x4U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL0_SHIFT    (2U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKCONTROL0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKCONTROL0_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKCONTROL1_MASK     (0x8U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL1_SHIFT    (3U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKCONTROL1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKCONTROL1_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKCONTROL2_MASK     (0x10U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL2_SHIFT    (4U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL2(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKCONTROL2_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKCONTROL2_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKCONTROL3_MASK     (0x20U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL3_SHIFT    (5U)
#define MIPI_DSI_DSI_INTMSK_MSKCONTROL3(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKCONTROL3_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKCONTROL3_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSYNC0_MASK        (0x40U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC0_SHIFT       (6U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC0(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSYNC0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSYNC0_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSYNC1_MASK        (0x80U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC1_SHIFT       (7U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC1(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSYNC1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSYNC1_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSYNC2_MASK        (0x100U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC2_SHIFT       (8U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC2(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSYNC2_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSYNC2_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSYNC3_MASK        (0x200U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC3_SHIFT       (9U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNC3(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSYNC3_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSYNC3_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKESC0_MASK         (0x400U)
#define MIPI_DSI_DSI_INTMSK_MSKESC0_SHIFT        (10U)
#define MIPI_DSI_DSI_INTMSK_MSKESC0(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKESC0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKESC0_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKESC1_MASK         (0x800U)
#define MIPI_DSI_DSI_INTMSK_MSKESC1_SHIFT        (11U)
#define MIPI_DSI_DSI_INTMSK_MSKESC1(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKESC1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKESC1_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKESC2_MASK         (0x1000U)
#define MIPI_DSI_DSI_INTMSK_MSKESC2_SHIFT        (12U)
#define MIPI_DSI_DSI_INTMSK_MSKESC2(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKESC2_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKESC2_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKESC3_MASK         (0x2000U)
#define MIPI_DSI_DSI_INTMSK_MSKESC3_SHIFT        (13U)
#define MIPI_DSI_DSI_INTMSK_MSKESC3(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKESC3_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKESC3_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKRXCRC_MASK        (0x4000U)
#define MIPI_DSI_DSI_INTMSK_MSKRXCRC_SHIFT       (14U)
#define MIPI_DSI_DSI_INTMSK_MSKRXCRC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKRXCRC_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKRXCRC_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKRXECC_MASK        (0x8000U)
#define MIPI_DSI_DSI_INTMSK_MSKRXECC_SHIFT       (15U)
#define MIPI_DSI_DSI_INTMSK_MSKRXECC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKRXECC_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKRXECC_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKRXACK_MASK        (0x10000U)
#define MIPI_DSI_DSI_INTMSK_MSKRXACK_SHIFT       (16U)
#define MIPI_DSI_DSI_INTMSK_MSKRXACK(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKRXACK_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKRXACK_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKRXTE_MASK         (0x20000U)
#define MIPI_DSI_DSI_INTMSK_MSKRXTE_SHIFT        (17U)
#define MIPI_DSI_DSI_INTMSK_MSKRXTE(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKRXTE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKRXTE_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKRXDATDONE_MASK    (0x40000U)
#define MIPI_DSI_DSI_INTMSK_MSKRXDATDONE_SHIFT   (18U)
#define MIPI_DSI_DSI_INTMSK_MSKRXDATDONE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKRXDATDONE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKRXDATDONE_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKTATOUT_MASK       (0x100000U)
#define MIPI_DSI_DSI_INTMSK_MSKTATOUT_SHIFT      (20U)
#define MIPI_DSI_DSI_INTMSK_MSKTATOUT(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKTATOUT_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKTATOUT_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKLPDRTOUT_MASK     (0x200000U)
#define MIPI_DSI_DSI_INTMSK_MSKLPDRTOUT_SHIFT    (21U)
#define MIPI_DSI_DSI_INTMSK_MSKLPDRTOUT(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKLPDRTOUT_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKLPDRTOUT_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKFRAMEDONE_MASK    (0x1000000U)
#define MIPI_DSI_DSI_INTMSK_MSKFRAMEDONE_SHIFT   (24U)
#define MIPI_DSI_DSI_INTMSK_MSKFRAMEDONE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKFRAMEDONE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKFRAMEDONE_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKBUSTURNOVER_MASK  (0x2000000U)
#define MIPI_DSI_DSI_INTMSK_MSKBUSTURNOVER_SHIFT (25U)
#define MIPI_DSI_DSI_INTMSK_MSKBUSTURNOVER(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKBUSTURNOVER_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKBUSTURNOVER_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSYNCOVERRIDE_MASK (0x8000000U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNCOVERRIDE_SHIFT (27U)
#define MIPI_DSI_DSI_INTMSK_MSKSYNCOVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSYNCOVERRIDE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSYNCOVERRIDE_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSFRPHFIFOEMPTY_MASK (0x10000000U)
#define MIPI_DSI_DSI_INTMSK_MSKSFRPHFIFOEMPTY_SHIFT (28U)
#define MIPI_DSI_DSI_INTMSK_MSKSFRPHFIFOEMPTY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSFRPHFIFOEMPTY_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSFRPHFIFOEMPTY_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSFRPLFIFOEMPTY_MASK (0x20000000U)
#define MIPI_DSI_DSI_INTMSK_MSKSFRPLFIFOEMPTY_SHIFT (29U)
#define MIPI_DSI_DSI_INTMSK_MSKSFRPLFIFOEMPTY(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSFRPLFIFOEMPTY_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSFRPLFIFOEMPTY_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKSWRSTRELEASE_MASK (0x40000000U)
#define MIPI_DSI_DSI_INTMSK_MSKSWRSTRELEASE_SHIFT (30U)
#define MIPI_DSI_DSI_INTMSK_MSKSWRSTRELEASE(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKSWRSTRELEASE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKSWRSTRELEASE_MASK)

#define MIPI_DSI_DSI_INTMSK_MSKPLLSTABLE_MASK    (0x80000000U)
#define MIPI_DSI_DSI_INTMSK_MSKPLLSTABLE_SHIFT   (31U)
#define MIPI_DSI_DSI_INTMSK_MSKPLLSTABLE(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MSKPLLSTABLE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MSKPLLSTABLE_MASK)
/*! @} */

/*! @name DSI_PKTHDR - Specifies the packet header FIFO register. */
/*! @{ */

#define MIPI_DSI_DSI_PKTHDR_PACKETHEADER_MASK    (0xFFFFFFU)
#define MIPI_DSI_DSI_PKTHDR_PACKETHEADER_SHIFT   (0U)
#define MIPI_DSI_DSI_PKTHDR_PACKETHEADER(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PKTHDR_PACKETHEADER_SHIFT)) & MIPI_DSI_DSI_PKTHDR_PACKETHEADER_MASK)
/*! @} */

/*! @name DSI_PAYLOAD - Specifies the payload FIFO register. */
/*! @{ */

#define MIPI_DSI_DSI_PAYLOAD_PAYLOAD_MASK        (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PAYLOAD_PAYLOAD_SHIFT       (0U)
#define MIPI_DSI_DSI_PAYLOAD_PAYLOAD(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PAYLOAD_PAYLOAD_SHIFT)) & MIPI_DSI_DSI_PAYLOAD_PAYLOAD_MASK)
/*! @} */

/*! @name DSI_RXFIFO - Specifies the read FIFO register. */
/*! @{ */

#define MIPI_DSI_DSI_RXFIFO_RXDAT_MASK           (0xFFFFFFFFU)
#define MIPI_DSI_DSI_RXFIFO_RXDAT_SHIFT          (0U)
#define MIPI_DSI_DSI_RXFIFO_RXDAT(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_RXFIFO_RXDAT_SHIFT)) & MIPI_DSI_DSI_RXFIFO_RXDAT_MASK)
/*! @} */

/*! @name DSI_FIFOTHLD - Specifies the FIFO threshold level register. */
/*! @{ */

#define MIPI_DSI_DSI_FIFOTHLD_WFULLLEVELSFR_MASK (0x1FFU)
#define MIPI_DSI_DSI_FIFOTHLD_WFULLLEVELSFR_SHIFT (0U)
#define MIPI_DSI_DSI_FIFOTHLD_WFULLLEVELSFR(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOTHLD_WFULLLEVELSFR_SHIFT)) & MIPI_DSI_DSI_FIFOTHLD_WFULLLEVELSFR_MASK)
/*! @} */

/*! @name DSI_FIFOCTRL - Specifies the FIFO status and control register. */
/*! @{ */

#define MIPI_DSI_DSI_FIFOCTRL_NINITMAIN_MASK     (0x1U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITMAIN_SHIFT    (0U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITMAIN(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_NINITMAIN_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_NINITMAIN_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_NINITSUB_MASK      (0x2U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITSUB_SHIFT     (1U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITSUB(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_NINITSUB_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_NINITSUB_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_NINITI80_MASK      (0x4U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITI80_SHIFT     (2U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITI80(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_NINITI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_NINITI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_NINITSFR_MASK      (0x8U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITSFR_SHIFT     (3U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITSFR(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_NINITSFR_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_NINITSFR_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_NINITRX_MASK       (0x10U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITRX_SHIFT      (4U)
#define MIPI_DSI_DSI_FIFOCTRL_NINITRX(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_NINITRX_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_NINITRX_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLMAIN_MASK    (0x100U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLMAIN_SHIFT   (8U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLMAIN(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYLMAIN_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYLMAIN_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLLMAIN_MASK     (0x200U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLMAIN_SHIFT    (9U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLMAIN(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLLMAIN_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLLMAIN_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHMAIN_MASK    (0x400U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHMAIN_SHIFT   (10U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHMAIN(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYHMAIN_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYHMAIN_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLHMAIN_MASK     (0x800U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHMAIN_SHIFT    (11U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHMAIN(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLHMAIN_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLHMAIN_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLSUB_MASK     (0x1000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLSUB_SHIFT    (12U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLSUB(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYLSUB_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYLSUB_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLLSUB_MASK      (0x2000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLSUB_SHIFT     (13U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLSUB(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLLSUB_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLLSUB_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHSUB_MASK     (0x4000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHSUB_SHIFT    (14U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHSUB(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYHSUB_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYHSUB_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLHSUB_MASK      (0x8000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHSUB_SHIFT     (15U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHSUB(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLHSUB_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLHSUB_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLI80_MASK     (0x10000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLI80_SHIFT    (16U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLI80(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYLI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYLI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLLI80_MASK      (0x20000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLI80_SHIFT     (17U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLI80(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLLI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLLI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHI80_MASK     (0x40000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHI80_SHIFT    (18U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHI80(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYHI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYHI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLHI80_MASK      (0x80000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHI80_SHIFT     (19U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHI80(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLHI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLHI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLSFR_MASK     (0x100000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLSFR_SHIFT    (20U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYLSFR(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYLSFR_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYLSFR_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLLSFR_MASK      (0x200000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLSFR_SHIFT     (21U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLLSFR(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLLSFR_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLLSFR_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHSFR_MASK     (0x400000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHSFR_SHIFT    (22U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYHSFR(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYHSFR_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYHSFR_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLHSFR_MASK      (0x800000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHSFR_SHIFT     (23U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLHSFR(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLHSFR_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLHSFR_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EMPTYRX_MASK       (0x1000000U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYRX_SHIFT      (24U)
#define MIPI_DSI_DSI_FIFOCTRL_EMPTYRX(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EMPTYRX_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EMPTYRX_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FULLRX_MASK        (0x2000000U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLRX_SHIFT       (25U)
#define MIPI_DSI_DSI_FIFOCTRL_FULLRX(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FULLRX_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FULLRX_MASK)
/*! @} */

/*! @name DSI_MEMACCHR - Specifies the FIFO memory AC characteristic register. */
/*! @{ */

#define MIPI_DSI_DSI_MEMACCHR_EMAA_MD_MASK       (0x7U)
#define MIPI_DSI_DSI_MEMACCHR_EMAA_MD_SHIFT      (0U)
#define MIPI_DSI_DSI_MEMACCHR_EMAA_MD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_EMAA_MD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_EMAA_MD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_EMAB_MD_MASK       (0x38U)
#define MIPI_DSI_DSI_MEMACCHR_EMAB_MD_SHIFT      (3U)
#define MIPI_DSI_DSI_MEMACCHR_EMAB_MD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_EMAB_MD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_EMAB_MD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_RETN_MD_MASK       (0x40U)
#define MIPI_DSI_DSI_MEMACCHR_RETN_MD_SHIFT      (6U)
#define MIPI_DSI_DSI_MEMACCHR_RETN_MD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_RETN_MD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_RETN_MD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_PGEN_MD_MASK       (0x80U)
#define MIPI_DSI_DSI_MEMACCHR_PGEN_MD_SHIFT      (7U)
#define MIPI_DSI_DSI_MEMACCHR_PGEN_MD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_PGEN_MD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_PGEN_MD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_EMAA_SD_MASK       (0x700U)
#define MIPI_DSI_DSI_MEMACCHR_EMAA_SD_SHIFT      (8U)
#define MIPI_DSI_DSI_MEMACCHR_EMAA_SD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_EMAA_SD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_EMAA_SD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_EMAB_SD_MASK       (0x3800U)
#define MIPI_DSI_DSI_MEMACCHR_EMAB_SD_SHIFT      (11U)
#define MIPI_DSI_DSI_MEMACCHR_EMAB_SD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_EMAB_SD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_EMAB_SD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_RETN_SD_MASK       (0x4000U)
#define MIPI_DSI_DSI_MEMACCHR_RETN_SD_SHIFT      (14U)
#define MIPI_DSI_DSI_MEMACCHR_RETN_SD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_RETN_SD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_RETN_SD_MASK)

#define MIPI_DSI_DSI_MEMACCHR_PGEN_SD_MASK       (0x8000U)
#define MIPI_DSI_DSI_MEMACCHR_PGEN_SD_SHIFT      (15U)
#define MIPI_DSI_DSI_MEMACCHR_PGEN_SD(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MEMACCHR_PGEN_SD_SHIFT)) & MIPI_DSI_DSI_MEMACCHR_PGEN_SD_MASK)
/*! @} */

/*! @name DSI_MULTI_PKT - Specifies the Multi Packet, Packet Go register. */
/*! @{ */

#define MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_CNT_REF_MASK (0xFFFFU)
#define MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_CNT_REF_SHIFT (0U)
#define MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_CNT_REF(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_CNT_REF_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_CNT_REF_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_PKT_SEND_CNT_REF_MASK (0xFFF0000U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_SEND_CNT_REF_SHIFT (16U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_SEND_CNT_REF(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_PKT_SEND_CNT_REF_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_PKT_SEND_CNT_REF_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_PKT_GO_RDY_MASK   (0x10000000U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_GO_RDY_SHIFT  (28U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_GO_RDY(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_PKT_GO_RDY_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_PKT_GO_RDY_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_PKT_GO_EN_MASK    (0x20000000U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_GO_EN_SHIFT   (29U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_GO_EN(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_PKT_GO_EN_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_PKT_GO_EN_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_EN_MASK (0x40000000U)
#define MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_EN_SHIFT (30U)
#define MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_EN(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_EN_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_MULTI_PKT_EN_MASK)
/*! @} */

/*! @name DSI_PLLCTRL_1G - Specifies the 1Gbps D-PHY PLL control register. */
/*! @{ */

#define MIPI_DSI_DSI_PLLCTRL_1G_PRPRCTLCLK_MASK  (0x7U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PRPRCTLCLK_SHIFT (0U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PRPRCTLCLK(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_PRPRCTLCLK_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_PRPRCTLCLK_MASK)

#define MIPI_DSI_DSI_PLLCTRL_1G_PREPRCTL_MASK    (0x70U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PREPRCTL_SHIFT   (4U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PREPRCTL(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_PREPRCTL_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_PREPRCTL_MASK)

#define MIPI_DSI_DSI_PLLCTRL_1G_FREQ_BAND_MASK   (0xF00U)
#define MIPI_DSI_DSI_PLLCTRL_1G_FREQ_BAND_SHIFT  (8U)
#define MIPI_DSI_DSI_PLLCTRL_1G_FREQ_BAND(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_FREQ_BAND_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_FREQ_BAND_MASK)

#define MIPI_DSI_DSI_PLLCTRL_1G_HSZEROCTL_MASK   (0xF000U)
#define MIPI_DSI_DSI_PLLCTRL_1G_HSZEROCTL_SHIFT  (12U)
#define MIPI_DSI_DSI_PLLCTRL_1G_HSZEROCTL(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_HSZEROCTL_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_HSZEROCTL_MASK)
/*! @} */

/*! @name DSI_PLLCTRL - Specifies the PLL control register. */
/*! @{ */

#define MIPI_DSI_DSI_PLLCTRL_PMS_MASK            (0xFFFFEU)
#define MIPI_DSI_DSI_PLLCTRL_PMS_SHIFT           (1U)
#define MIPI_DSI_DSI_PLLCTRL_PMS(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_PMS_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_PMS_MASK)

#define MIPI_DSI_DSI_PLLCTRL_PLLEN_MASK          (0x800000U)
#define MIPI_DSI_DSI_PLLCTRL_PLLEN_SHIFT         (23U)
#define MIPI_DSI_DSI_PLLCTRL_PLLEN(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_PLLEN_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_PLLEN_MASK)

#define MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_DAT_MASK   (0x1000000U)
#define MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_DAT_SHIFT  (24U)
#define MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_DAT(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_DAT_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_DAT_MASK)

#define MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_CLK_MASK   (0x2000000U)
#define MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_CLK_SHIFT  (25U)
#define MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_CLK(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_CLK_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_DPDNSWAP_CLK_MASK)
/*! @} */

/*! @name DSI_PLLCTRL1 - Specifies the PLL control register 1. */
/*! @{ */

#define MIPI_DSI_DSI_PLLCTRL1_M_PLLCTL0_MASK     (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PLLCTRL1_M_PLLCTL0_SHIFT    (0U)
#define MIPI_DSI_DSI_PLLCTRL1_M_PLLCTL0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL1_M_PLLCTL0_SHIFT)) & MIPI_DSI_DSI_PLLCTRL1_M_PLLCTL0_MASK)
/*! @} */

/*! @name DSI_PLLCTRL2 - Specifies the PLL control register 2. */
/*! @{ */

#define MIPI_DSI_DSI_PLLCTRL2_M_PLLCTL1_MASK     (0xFFU)
#define MIPI_DSI_DSI_PLLCTRL2_M_PLLCTL1_SHIFT    (0U)
#define MIPI_DSI_DSI_PLLCTRL2_M_PLLCTL1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL2_M_PLLCTL1_SHIFT)) & MIPI_DSI_DSI_PLLCTRL2_M_PLLCTL1_MASK)
/*! @} */

/*! @name DSI_PLLTMR - Specifies the PLL timer register. */
/*! @{ */

#define MIPI_DSI_DSI_PLLTMR_PLLTIMER_MASK        (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PLLTMR_PLLTIMER_SHIFT       (0U)
#define MIPI_DSI_DSI_PLLTMR_PLLTIMER(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLTMR_PLLTIMER_SHIFT)) & MIPI_DSI_DSI_PLLTMR_PLLTIMER_MASK)
/*! @} */

/*! @name DSI_PHYCTRL_B1 - Specifies the D-PHY control register 1. */
/*! @{ */

#define MIPI_DSI_DSI_PHYCTRL_B1_B_DPHYCTL0_MASK  (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PHYCTRL_B1_B_DPHYCTL0_SHIFT (0U)
#define MIPI_DSI_DSI_PHYCTRL_B1_B_DPHYCTL0(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYCTRL_B1_B_DPHYCTL0_SHIFT)) & MIPI_DSI_DSI_PHYCTRL_B1_B_DPHYCTL0_MASK)
/*! @} */

/*! @name DSI_PHYCTRL_B2 - Specifies the D-PHY control register 2. */
/*! @{ */

#define MIPI_DSI_DSI_PHYCTRL_B2_B_DPHYCTL1_MASK  (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PHYCTRL_B2_B_DPHYCTL1_SHIFT (0U)
#define MIPI_DSI_DSI_PHYCTRL_B2_B_DPHYCTL1(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYCTRL_B2_B_DPHYCTL1_SHIFT)) & MIPI_DSI_DSI_PHYCTRL_B2_B_DPHYCTL1_MASK)
/*! @} */

/*! @name DSI_PHYCTRL_M1 - Specifies the D-PHY control register 1. */
/*! @{ */

#define MIPI_DSI_DSI_PHYCTRL_M1_M_DPHYCTL0_MASK  (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PHYCTRL_M1_M_DPHYCTL0_SHIFT (0U)
#define MIPI_DSI_DSI_PHYCTRL_M1_M_DPHYCTL0(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYCTRL_M1_M_DPHYCTL0_SHIFT)) & MIPI_DSI_DSI_PHYCTRL_M1_M_DPHYCTL0_MASK)
/*! @} */

/*! @name DSI_PHYCTRL_M2 - Specifies the D-PHY control register 2. */
/*! @{ */

#define MIPI_DSI_DSI_PHYCTRL_M2_M_DPHYCTL1_MASK  (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PHYCTRL_M2_M_DPHYCTL1_SHIFT (0U)
#define MIPI_DSI_DSI_PHYCTRL_M2_M_DPHYCTL1(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYCTRL_M2_M_DPHYCTL1_SHIFT)) & MIPI_DSI_DSI_PHYCTRL_M2_M_DPHYCTL1_MASK)
/*! @} */

/*! @name DSI_PHYTIMING - Specifies the D-PHY timing register. */
/*! @{ */

#define MIPI_DSI_DSI_PHYTIMING_M_THSEXITCTL_MASK (0xFFU)
#define MIPI_DSI_DSI_PHYTIMING_M_THSEXITCTL_SHIFT (0U)
#define MIPI_DSI_DSI_PHYTIMING_M_THSEXITCTL(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING_M_THSEXITCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING_M_THSEXITCTL_MASK)

#define MIPI_DSI_DSI_PHYTIMING_M_TLPXCTL_MASK    (0xFF00U)
#define MIPI_DSI_DSI_PHYTIMING_M_TLPXCTL_SHIFT   (8U)
#define MIPI_DSI_DSI_PHYTIMING_M_TLPXCTL(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING_M_TLPXCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING_M_TLPXCTL_MASK)
/*! @} */

/*! @name DSI_PHYTIMING1 - Specifies the D-PHY timing register 1. */
/*! @{ */

#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKTRAILCTL_MASK (0xFFU)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKTRAILCTL_SHIFT (0U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKTRAILCTL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING1_M_TCLKTRAILCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING1_M_TCLKTRAILCTL_MASK)

#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKPOSTCTL_MASK (0xFF00U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKPOSTCTL_SHIFT (8U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKPOSTCTL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING1_M_TCLKPOSTCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING1_M_TCLKPOSTCTL_MASK)

#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKZEROCTL_MASK (0xFF0000U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKZEROCTL_SHIFT (16U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKZEROCTL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING1_M_TCLKZEROCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING1_M_TCLKZEROCTL_MASK)

#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKPRPRCTL_MASK (0xFF000000U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKPRPRCTL_SHIFT (24U)
#define MIPI_DSI_DSI_PHYTIMING1_M_TCLKPRPRCTL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING1_M_TCLKPRPRCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING1_M_TCLKPRPRCTL_MASK)
/*! @} */

/*! @name DSI_PHYTIMING2 - Specifies the D-PHY timing register 2. */
/*! @{ */

#define MIPI_DSI_DSI_PHYTIMING2_M_THSTRAILCTL_MASK (0xFFU)
#define MIPI_DSI_DSI_PHYTIMING2_M_THSTRAILCTL_SHIFT (0U)
#define MIPI_DSI_DSI_PHYTIMING2_M_THSTRAILCTL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING2_M_THSTRAILCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING2_M_THSTRAILCTL_MASK)

#define MIPI_DSI_DSI_PHYTIMING2_M_THSZEROCTL_MASK (0xFF00U)
#define MIPI_DSI_DSI_PHYTIMING2_M_THSZEROCTL_SHIFT (8U)
#define MIPI_DSI_DSI_PHYTIMING2_M_THSZEROCTL(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING2_M_THSZEROCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING2_M_THSZEROCTL_MASK)

#define MIPI_DSI_DSI_PHYTIMING2_M_THSPRPRCTL_MASK (0xFF0000U)
#define MIPI_DSI_DSI_PHYTIMING2_M_THSPRPRCTL_SHIFT (16U)
#define MIPI_DSI_DSI_PHYTIMING2_M_THSPRPRCTL(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PHYTIMING2_M_THSPRPRCTL_SHIFT)) & MIPI_DSI_DSI_PHYTIMING2_M_THSPRPRCTL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_H_ */

