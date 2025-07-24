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
 * @file PERI_MIPI_DSI.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI
 */

#if !defined(PERI_MIPI_DSI_H_)
#define PERI_MIPI_DSI_H_                         /**< Symbol preventing repeated inclusion */

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

#define MIPI_DSI_DSI_VERSION_Version_MASK        (0xFFFFFFFFU)
#define MIPI_DSI_DSI_VERSION_Version_SHIFT       (0U)
#define MIPI_DSI_DSI_VERSION_Version(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_VERSION_Version_SHIFT)) & MIPI_DSI_DSI_VERSION_Version_MASK)
/*! @} */

/*! @name DSI_STATUS - Specifies the status register. */
/*! @{ */

#define MIPI_DSI_DSI_STATUS_StopstateDat_MASK    (0xFU)
#define MIPI_DSI_DSI_STATUS_StopstateDat_SHIFT   (0U)
#define MIPI_DSI_DSI_STATUS_StopstateDat(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_StopstateDat_SHIFT)) & MIPI_DSI_DSI_STATUS_StopstateDat_MASK)

#define MIPI_DSI_DSI_STATUS_UlpsDat_MASK         (0xF0U)
#define MIPI_DSI_DSI_STATUS_UlpsDat_SHIFT        (4U)
#define MIPI_DSI_DSI_STATUS_UlpsDat(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_UlpsDat_SHIFT)) & MIPI_DSI_DSI_STATUS_UlpsDat_MASK)

#define MIPI_DSI_DSI_STATUS_StopstateClk_MASK    (0x100U)
#define MIPI_DSI_DSI_STATUS_StopstateClk_SHIFT   (8U)
#define MIPI_DSI_DSI_STATUS_StopstateClk(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_StopstateClk_SHIFT)) & MIPI_DSI_DSI_STATUS_StopstateClk_MASK)

#define MIPI_DSI_DSI_STATUS_UlpsClk_MASK         (0x200U)
#define MIPI_DSI_DSI_STATUS_UlpsClk_SHIFT        (9U)
#define MIPI_DSI_DSI_STATUS_UlpsClk(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_UlpsClk_SHIFT)) & MIPI_DSI_DSI_STATUS_UlpsClk_MASK)

#define MIPI_DSI_DSI_STATUS_TxReadyHsClk_MASK    (0x400U)
#define MIPI_DSI_DSI_STATUS_TxReadyHsClk_SHIFT   (10U)
#define MIPI_DSI_DSI_STATUS_TxReadyHsClk(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_TxReadyHsClk_SHIFT)) & MIPI_DSI_DSI_STATUS_TxReadyHsClk_MASK)

#define MIPI_DSI_DSI_STATUS_Direction_MASK       (0x10000U)
#define MIPI_DSI_DSI_STATUS_Direction_SHIFT      (16U)
#define MIPI_DSI_DSI_STATUS_Direction(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_Direction_SHIFT)) & MIPI_DSI_DSI_STATUS_Direction_MASK)

#define MIPI_DSI_DSI_STATUS_SwRstRls_MASK        (0x100000U)
#define MIPI_DSI_DSI_STATUS_SwRstRls_SHIFT       (20U)
#define MIPI_DSI_DSI_STATUS_SwRstRls(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_SwRstRls_SHIFT)) & MIPI_DSI_DSI_STATUS_SwRstRls_MASK)

#define MIPI_DSI_DSI_STATUS_PllStable_MASK       (0x80000000U)
#define MIPI_DSI_DSI_STATUS_PllStable_SHIFT      (31U)
#define MIPI_DSI_DSI_STATUS_PllStable(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_STATUS_PllStable_SHIFT)) & MIPI_DSI_DSI_STATUS_PllStable_MASK)
/*! @} */

/*! @name DSI_RGB_STATUS - Specifies the RGB FSM status register. */
/*! @{ */

#define MIPI_DSI_DSI_RGB_STATUS_RGBstate_MASK    (0x1FFFU)
#define MIPI_DSI_DSI_RGB_STATUS_RGBstate_SHIFT   (0U)
#define MIPI_DSI_DSI_RGB_STATUS_RGBstate(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_RGB_STATUS_RGBstate_SHIFT)) & MIPI_DSI_DSI_RGB_STATUS_RGBstate_MASK)

#define MIPI_DSI_DSI_RGB_STATUS_CmdMode_InSel_MASK (0x80000000U)
#define MIPI_DSI_DSI_RGB_STATUS_CmdMode_InSel_SHIFT (31U)
#define MIPI_DSI_DSI_RGB_STATUS_CmdMode_InSel(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_RGB_STATUS_CmdMode_InSel_SHIFT)) & MIPI_DSI_DSI_RGB_STATUS_CmdMode_InSel_MASK)
/*! @} */

/*! @name DSI_SWRST - Specifies the software reset register. */
/*! @{ */

#define MIPI_DSI_DSI_SWRST_SwRst_MASK            (0x1U)
#define MIPI_DSI_DSI_SWRST_SwRst_SHIFT           (0U)
#define MIPI_DSI_DSI_SWRST_SwRst(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SWRST_SwRst_SHIFT)) & MIPI_DSI_DSI_SWRST_SwRst_MASK)

#define MIPI_DSI_DSI_SWRST_FuncRst_MASK          (0x10000U)
#define MIPI_DSI_DSI_SWRST_FuncRst_SHIFT         (16U)
#define MIPI_DSI_DSI_SWRST_FuncRst(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SWRST_FuncRst_SHIFT)) & MIPI_DSI_DSI_SWRST_FuncRst_MASK)
/*! @} */

/*! @name DSI_CLKCTRL - Specifies the clock control register. */
/*! @{ */

#define MIPI_DSI_DSI_CLKCTRL_EscPrescaler_MASK   (0xFFFFU)
#define MIPI_DSI_DSI_CLKCTRL_EscPrescaler_SHIFT  (0U)
#define MIPI_DSI_DSI_CLKCTRL_EscPrescaler(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_EscPrescaler_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_EscPrescaler_MASK)

#define MIPI_DSI_DSI_CLKCTRL_LaneEscClkEn_MASK   (0xF80000U)
#define MIPI_DSI_DSI_CLKCTRL_LaneEscClkEn_SHIFT  (19U)
#define MIPI_DSI_DSI_CLKCTRL_LaneEscClkEn(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_LaneEscClkEn_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_LaneEscClkEn_MASK)

#define MIPI_DSI_DSI_CLKCTRL_ByteClkEn_MASK      (0x1000000U)
#define MIPI_DSI_DSI_CLKCTRL_ByteClkEn_SHIFT     (24U)
#define MIPI_DSI_DSI_CLKCTRL_ByteClkEn(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_ByteClkEn_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_ByteClkEn_MASK)

#define MIPI_DSI_DSI_CLKCTRL_ByteClkSrc_MASK     (0x6000000U)
#define MIPI_DSI_DSI_CLKCTRL_ByteClkSrc_SHIFT    (25U)
#define MIPI_DSI_DSI_CLKCTRL_ByteClkSrc(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_ByteClkSrc_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_ByteClkSrc_MASK)

#define MIPI_DSI_DSI_CLKCTRL_PLLBypass_MASK      (0x8000000U)
#define MIPI_DSI_DSI_CLKCTRL_PLLBypass_SHIFT     (27U)
#define MIPI_DSI_DSI_CLKCTRL_PLLBypass(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_PLLBypass_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_PLLBypass_MASK)

#define MIPI_DSI_DSI_CLKCTRL_EscClkEn_MASK       (0x10000000U)
#define MIPI_DSI_DSI_CLKCTRL_EscClkEn_SHIFT      (28U)
#define MIPI_DSI_DSI_CLKCTRL_EscClkEn(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_EscClkEn_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_EscClkEn_MASK)

#define MIPI_DSI_DSI_CLKCTRL_Dphy_sel_MASK       (0x20000000U)
#define MIPI_DSI_DSI_CLKCTRL_Dphy_sel_SHIFT      (29U)
#define MIPI_DSI_DSI_CLKCTRL_Dphy_sel(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_Dphy_sel_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_Dphy_sel_MASK)

#define MIPI_DSI_DSI_CLKCTRL_TxRequestHsClk_MASK (0x80000000U)
#define MIPI_DSI_DSI_CLKCTRL_TxRequestHsClk_SHIFT (31U)
#define MIPI_DSI_DSI_CLKCTRL_TxRequestHsClk(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CLKCTRL_TxRequestHsClk_SHIFT)) & MIPI_DSI_DSI_CLKCTRL_TxRequestHsClk_MASK)
/*! @} */

/*! @name DSI_TIMEOUT - Specifies the time out register. */
/*! @{ */

#define MIPI_DSI_DSI_TIMEOUT_LpdrTout_MASK       (0xFFFFU)
#define MIPI_DSI_DSI_TIMEOUT_LpdrTout_SHIFT      (0U)
#define MIPI_DSI_DSI_TIMEOUT_LpdrTout(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_TIMEOUT_LpdrTout_SHIFT)) & MIPI_DSI_DSI_TIMEOUT_LpdrTout_MASK)

#define MIPI_DSI_DSI_TIMEOUT_BtaTout_MASK        (0xFF0000U)
#define MIPI_DSI_DSI_TIMEOUT_BtaTout_SHIFT       (16U)
#define MIPI_DSI_DSI_TIMEOUT_BtaTout(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_TIMEOUT_BtaTout_SHIFT)) & MIPI_DSI_DSI_TIMEOUT_BtaTout_MASK)
/*! @} */

/*! @name DSI_CONFIG - Specifies the configuration register. */
/*! @{ */

#define MIPI_DSI_DSI_CONFIG_LaneEn_MASK          (0x1FU)
#define MIPI_DSI_DSI_CONFIG_LaneEn_SHIFT         (0U)
#define MIPI_DSI_DSI_CONFIG_LaneEn(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_LaneEn_SHIFT)) & MIPI_DSI_DSI_CONFIG_LaneEn_MASK)

#define MIPI_DSI_DSI_CONFIG_NumOfDatLane_MASK    (0x60U)
#define MIPI_DSI_DSI_CONFIG_NumOfDatLane_SHIFT   (5U)
#define MIPI_DSI_DSI_CONFIG_NumOfDatLane(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_NumOfDatLane_SHIFT)) & MIPI_DSI_DSI_CONFIG_NumOfDatLane_MASK)

#define MIPI_DSI_DSI_CONFIG_SubPixFormat_MASK    (0x700U)
#define MIPI_DSI_DSI_CONFIG_SubPixFormat_SHIFT   (8U)
#define MIPI_DSI_DSI_CONFIG_SubPixFormat(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_SubPixFormat_SHIFT)) & MIPI_DSI_DSI_CONFIG_SubPixFormat_MASK)

#define MIPI_DSI_DSI_CONFIG_MainPixFormat_MASK   (0x7000U)
#define MIPI_DSI_DSI_CONFIG_MainPixFormat_SHIFT  (12U)
#define MIPI_DSI_DSI_CONFIG_MainPixFormat(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_MainPixFormat_SHIFT)) & MIPI_DSI_DSI_CONFIG_MainPixFormat_MASK)

#define MIPI_DSI_DSI_CONFIG_SubVc_MASK           (0x30000U)
#define MIPI_DSI_DSI_CONFIG_SubVc_SHIFT          (16U)
#define MIPI_DSI_DSI_CONFIG_SubVc(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_SubVc_SHIFT)) & MIPI_DSI_DSI_CONFIG_SubVc_MASK)

#define MIPI_DSI_DSI_CONFIG_MainVc_MASK          (0xC0000U)
#define MIPI_DSI_DSI_CONFIG_MainVc_SHIFT         (18U)
#define MIPI_DSI_DSI_CONFIG_MainVc(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_MainVc_SHIFT)) & MIPI_DSI_DSI_CONFIG_MainVc_MASK)

#define MIPI_DSI_DSI_CONFIG_HsaDisableMode_MASK  (0x100000U)
#define MIPI_DSI_DSI_CONFIG_HsaDisableMode_SHIFT (20U)
#define MIPI_DSI_DSI_CONFIG_HsaDisableMode(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HsaDisableMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_HsaDisableMode_MASK)

#define MIPI_DSI_DSI_CONFIG_HbpDisableMode_MASK  (0x200000U)
#define MIPI_DSI_DSI_CONFIG_HbpDisableMode_SHIFT (21U)
#define MIPI_DSI_DSI_CONFIG_HbpDisableMode(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HbpDisableMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_HbpDisableMode_MASK)

#define MIPI_DSI_DSI_CONFIG_HfpDisableMode_MASK  (0x400000U)
#define MIPI_DSI_DSI_CONFIG_HfpDisableMode_SHIFT (22U)
#define MIPI_DSI_DSI_CONFIG_HfpDisableMode(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HfpDisableMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_HfpDisableMode_MASK)

#define MIPI_DSI_DSI_CONFIG_HseDisableMode_MASK  (0x800000U)
#define MIPI_DSI_DSI_CONFIG_HseDisableMode_SHIFT (23U)
#define MIPI_DSI_DSI_CONFIG_HseDisableMode(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_HseDisableMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_HseDisableMode_MASK)

#define MIPI_DSI_DSI_CONFIG_AutoMode_MASK        (0x1000000U)
#define MIPI_DSI_DSI_CONFIG_AutoMode_SHIFT       (24U)
#define MIPI_DSI_DSI_CONFIG_AutoMode(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_AutoMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_AutoMode_MASK)

#define MIPI_DSI_DSI_CONFIG_VideoMode_MASK       (0x2000000U)
#define MIPI_DSI_DSI_CONFIG_VideoMode_SHIFT      (25U)
#define MIPI_DSI_DSI_CONFIG_VideoMode(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_VideoMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_VideoMode_MASK)

#define MIPI_DSI_DSI_CONFIG_BurstMode_MASK       (0x4000000U)
#define MIPI_DSI_DSI_CONFIG_BurstMode_SHIFT      (26U)
#define MIPI_DSI_DSI_CONFIG_BurstMode(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_BurstMode_SHIFT)) & MIPI_DSI_DSI_CONFIG_BurstMode_MASK)

#define MIPI_DSI_DSI_CONFIG_SyncInform_MASK      (0x8000000U)
#define MIPI_DSI_DSI_CONFIG_SyncInform_SHIFT     (27U)
#define MIPI_DSI_DSI_CONFIG_SyncInform(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_SyncInform_SHIFT)) & MIPI_DSI_DSI_CONFIG_SyncInform_MASK)

#define MIPI_DSI_DSI_CONFIG_EoT_r03_MASK         (0x10000000U)
#define MIPI_DSI_DSI_CONFIG_EoT_r03_SHIFT        (28U)
#define MIPI_DSI_DSI_CONFIG_EoT_r03(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_EoT_r03_SHIFT)) & MIPI_DSI_DSI_CONFIG_EoT_r03_MASK)

#define MIPI_DSI_DSI_CONFIG_Mflush_VS_MASK       (0x20000000U)
#define MIPI_DSI_DSI_CONFIG_Mflush_VS_SHIFT      (29U)
#define MIPI_DSI_DSI_CONFIG_Mflush_VS(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_Mflush_VS_SHIFT)) & MIPI_DSI_DSI_CONFIG_Mflush_VS_MASK)

#define MIPI_DSI_DSI_CONFIG_Clklane_Stop_Start_MASK (0x40000000U)
#define MIPI_DSI_DSI_CONFIG_Clklane_Stop_Start_SHIFT (30U)
#define MIPI_DSI_DSI_CONFIG_Clklane_Stop_Start(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_Clklane_Stop_Start_SHIFT)) & MIPI_DSI_DSI_CONFIG_Clklane_Stop_Start_MASK)

#define MIPI_DSI_DSI_CONFIG_Non_Continuous_clock_lane_MASK (0x80000000U)
#define MIPI_DSI_DSI_CONFIG_Non_Continuous_clock_lane_SHIFT (31U)
#define MIPI_DSI_DSI_CONFIG_Non_Continuous_clock_lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_CONFIG_Non_Continuous_clock_lane_SHIFT)) & MIPI_DSI_DSI_CONFIG_Non_Continuous_clock_lane_MASK)
/*! @} */

/*! @name DSI_ESCMODE - Specifies the escape mode register. */
/*! @{ */

#define MIPI_DSI_DSI_ESCMODE_TxUlpsClkExit_MASK  (0x1U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsClkExit_SHIFT (0U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsClkExit(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TxUlpsClkExit_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TxUlpsClkExit_MASK)

#define MIPI_DSI_DSI_ESCMODE_TxUlpsClk_MASK      (0x2U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsClk_SHIFT     (1U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsClk(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TxUlpsClk_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TxUlpsClk_MASK)

#define MIPI_DSI_DSI_ESCMODE_TxUlpsExit_MASK     (0x4U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsExit_SHIFT    (2U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsExit(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TxUlpsExit_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TxUlpsExit_MASK)

#define MIPI_DSI_DSI_ESCMODE_TxUlpsDat_MASK      (0x8U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsDat_SHIFT     (3U)
#define MIPI_DSI_DSI_ESCMODE_TxUlpsDat(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TxUlpsDat_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TxUlpsDat_MASK)

#define MIPI_DSI_DSI_ESCMODE_TxTriggerRst_MASK   (0x10U)
#define MIPI_DSI_DSI_ESCMODE_TxTriggerRst_SHIFT  (4U)
#define MIPI_DSI_DSI_ESCMODE_TxTriggerRst(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TxTriggerRst_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TxTriggerRst_MASK)

#define MIPI_DSI_DSI_ESCMODE_TxLpdt_MASK         (0x40U)
#define MIPI_DSI_DSI_ESCMODE_TxLpdt_SHIFT        (6U)
#define MIPI_DSI_DSI_ESCMODE_TxLpdt(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_TxLpdt_SHIFT)) & MIPI_DSI_DSI_ESCMODE_TxLpdt_MASK)

#define MIPI_DSI_DSI_ESCMODE_CmdLpdt_MASK        (0x80U)
#define MIPI_DSI_DSI_ESCMODE_CmdLpdt_SHIFT       (7U)
#define MIPI_DSI_DSI_ESCMODE_CmdLpdt(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_CmdLpdt_SHIFT)) & MIPI_DSI_DSI_ESCMODE_CmdLpdt_MASK)

#define MIPI_DSI_DSI_ESCMODE_ForceBta_MASK       (0x10000U)
#define MIPI_DSI_DSI_ESCMODE_ForceBta_SHIFT      (16U)
#define MIPI_DSI_DSI_ESCMODE_ForceBta(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_ForceBta_SHIFT)) & MIPI_DSI_DSI_ESCMODE_ForceBta_MASK)

#define MIPI_DSI_DSI_ESCMODE_ForceStopstate__MASK (0x100000U)
#define MIPI_DSI_DSI_ESCMODE_ForceStopstate__SHIFT (20U)
#define MIPI_DSI_DSI_ESCMODE_ForceStopstate_(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_ForceStopstate__SHIFT)) & MIPI_DSI_DSI_ESCMODE_ForceStopstate__MASK)

#define MIPI_DSI_DSI_ESCMODE_STOPstate_Cnt_MASK  (0xFFE00000U)
#define MIPI_DSI_DSI_ESCMODE_STOPstate_Cnt_SHIFT (21U)
#define MIPI_DSI_DSI_ESCMODE_STOPstate_Cnt(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_ESCMODE_STOPstate_Cnt_SHIFT)) & MIPI_DSI_DSI_ESCMODE_STOPstate_Cnt_MASK)
/*! @} */

/*! @name DSI_MDRESOL - Specifies the main display image resolution register. */
/*! @{ */

#define MIPI_DSI_DSI_MDRESOL_MainHResol_MASK     (0xFFFU)
#define MIPI_DSI_DSI_MDRESOL_MainHResol_SHIFT    (0U)
#define MIPI_DSI_DSI_MDRESOL_MainHResol(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MDRESOL_MainHResol_SHIFT)) & MIPI_DSI_DSI_MDRESOL_MainHResol_MASK)

#define MIPI_DSI_DSI_MDRESOL_MainVResol_MASK     (0xFFF0000U)
#define MIPI_DSI_DSI_MDRESOL_MainVResol_SHIFT    (16U)
#define MIPI_DSI_DSI_MDRESOL_MainVResol(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MDRESOL_MainVResol_SHIFT)) & MIPI_DSI_DSI_MDRESOL_MainVResol_MASK)

#define MIPI_DSI_DSI_MDRESOL_MainStandby_MASK    (0x80000000U)
#define MIPI_DSI_DSI_MDRESOL_MainStandby_SHIFT   (31U)
#define MIPI_DSI_DSI_MDRESOL_MainStandby(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MDRESOL_MainStandby_SHIFT)) & MIPI_DSI_DSI_MDRESOL_MainStandby_MASK)
/*! @} */

/*! @name DSI_MVPORCH - Specifies the main display Vporch register. */
/*! @{ */

#define MIPI_DSI_DSI_MVPORCH_MainVbp_MASK        (0x7FFU)
#define MIPI_DSI_DSI_MVPORCH_MainVbp_SHIFT       (0U)
#define MIPI_DSI_DSI_MVPORCH_MainVbp(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MVPORCH_MainVbp_SHIFT)) & MIPI_DSI_DSI_MVPORCH_MainVbp_MASK)

#define MIPI_DSI_DSI_MVPORCH_StableVfp_MASK      (0x7FF0000U)
#define MIPI_DSI_DSI_MVPORCH_StableVfp_SHIFT     (16U)
#define MIPI_DSI_DSI_MVPORCH_StableVfp(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MVPORCH_StableVfp_SHIFT)) & MIPI_DSI_DSI_MVPORCH_StableVfp_MASK)

#define MIPI_DSI_DSI_MVPORCH_CmdAllow_MASK       (0xF0000000U)
#define MIPI_DSI_DSI_MVPORCH_CmdAllow_SHIFT      (28U)
#define MIPI_DSI_DSI_MVPORCH_CmdAllow(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MVPORCH_CmdAllow_SHIFT)) & MIPI_DSI_DSI_MVPORCH_CmdAllow_MASK)
/*! @} */

/*! @name DSI_MHPORCH - Specifies the main display Hporch register. */
/*! @{ */

#define MIPI_DSI_DSI_MHPORCH_MainHbp_MASK        (0xFFFFU)
#define MIPI_DSI_DSI_MHPORCH_MainHbp_SHIFT       (0U)
#define MIPI_DSI_DSI_MHPORCH_MainHbp(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MHPORCH_MainHbp_SHIFT)) & MIPI_DSI_DSI_MHPORCH_MainHbp_MASK)

#define MIPI_DSI_DSI_MHPORCH_MainHfp_MASK        (0xFFFF0000U)
#define MIPI_DSI_DSI_MHPORCH_MainHfp_SHIFT       (16U)
#define MIPI_DSI_DSI_MHPORCH_MainHfp(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MHPORCH_MainHfp_SHIFT)) & MIPI_DSI_DSI_MHPORCH_MainHfp_MASK)
/*! @} */

/*! @name DSI_MSYNC - Specifies the main display Sync Area register. */
/*! @{ */

#define MIPI_DSI_DSI_MSYNC_MainHsa_MASK          (0xFFFFU)
#define MIPI_DSI_DSI_MSYNC_MainHsa_SHIFT         (0U)
#define MIPI_DSI_DSI_MSYNC_MainHsa(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MSYNC_MainHsa_SHIFT)) & MIPI_DSI_DSI_MSYNC_MainHsa_MASK)

#define MIPI_DSI_DSI_MSYNC_MainVsa_MASK          (0xFFC00000U)
#define MIPI_DSI_DSI_MSYNC_MainVsa_SHIFT         (22U)
#define MIPI_DSI_DSI_MSYNC_MainVsa(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MSYNC_MainVsa_SHIFT)) & MIPI_DSI_DSI_MSYNC_MainVsa_MASK)
/*! @} */

/*! @name DSI_SDRESOL - Specifies the sub display image resolution register. */
/*! @{ */

#define MIPI_DSI_DSI_SDRESOL_SubHResol_MASK      (0x7FFU)
#define MIPI_DSI_DSI_SDRESOL_SubHResol_SHIFT     (0U)
#define MIPI_DSI_DSI_SDRESOL_SubHResol(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SDRESOL_SubHResol_SHIFT)) & MIPI_DSI_DSI_SDRESOL_SubHResol_MASK)

#define MIPI_DSI_DSI_SDRESOL_SubVResol_MASK      (0x7FF0000U)
#define MIPI_DSI_DSI_SDRESOL_SubVResol_SHIFT     (16U)
#define MIPI_DSI_DSI_SDRESOL_SubVResol(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SDRESOL_SubVResol_SHIFT)) & MIPI_DSI_DSI_SDRESOL_SubVResol_MASK)

#define MIPI_DSI_DSI_SDRESOL_SubStandby_MASK     (0x80000000U)
#define MIPI_DSI_DSI_SDRESOL_SubStandby_SHIFT    (31U)
#define MIPI_DSI_DSI_SDRESOL_SubStandby(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_SDRESOL_SubStandby_SHIFT)) & MIPI_DSI_DSI_SDRESOL_SubStandby_MASK)
/*! @} */

/*! @name DSI_INTSRC - Specifies the interrupt source register. */
/*! @{ */

#define MIPI_DSI_DSI_INTSRC_ErrContentLP1_MASK   (0x1U)
#define MIPI_DSI_DSI_INTSRC_ErrContentLP1_SHIFT  (0U)
#define MIPI_DSI_DSI_INTSRC_ErrContentLP1(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrContentLP1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrContentLP1_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrContentLP0_MASK   (0x2U)
#define MIPI_DSI_DSI_INTSRC_ErrContentLP0_SHIFT  (1U)
#define MIPI_DSI_DSI_INTSRC_ErrContentLP0(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrContentLP0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrContentLP0_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrControl0_MASK     (0x4U)
#define MIPI_DSI_DSI_INTSRC_ErrControl0_SHIFT    (2U)
#define MIPI_DSI_DSI_INTSRC_ErrControl0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrControl0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrControl0_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrControl1_MASK     (0x8U)
#define MIPI_DSI_DSI_INTSRC_ErrControl1_SHIFT    (3U)
#define MIPI_DSI_DSI_INTSRC_ErrControl1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrControl1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrControl1_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrControl2_MASK     (0x10U)
#define MIPI_DSI_DSI_INTSRC_ErrControl2_SHIFT    (4U)
#define MIPI_DSI_DSI_INTSRC_ErrControl2(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrControl2_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrControl2_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrControl3_MASK     (0x20U)
#define MIPI_DSI_DSI_INTSRC_ErrControl3_SHIFT    (5U)
#define MIPI_DSI_DSI_INTSRC_ErrControl3(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrControl3_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrControl3_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrSync0_MASK        (0x40U)
#define MIPI_DSI_DSI_INTSRC_ErrSync0_SHIFT       (6U)
#define MIPI_DSI_DSI_INTSRC_ErrSync0(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrSync0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrSync0_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrSync1_MASK        (0x80U)
#define MIPI_DSI_DSI_INTSRC_ErrSync1_SHIFT       (7U)
#define MIPI_DSI_DSI_INTSRC_ErrSync1(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrSync1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrSync1_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrSync2_MASK        (0x100U)
#define MIPI_DSI_DSI_INTSRC_ErrSync2_SHIFT       (8U)
#define MIPI_DSI_DSI_INTSRC_ErrSync2(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrSync2_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrSync2_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrSync3_MASK        (0x200U)
#define MIPI_DSI_DSI_INTSRC_ErrSync3_SHIFT       (9U)
#define MIPI_DSI_DSI_INTSRC_ErrSync3(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrSync3_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrSync3_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrEsc0_MASK         (0x400U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc0_SHIFT        (10U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc0(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrEsc0_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrEsc0_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrEsc1_MASK         (0x800U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc1_SHIFT        (11U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc1(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrEsc1_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrEsc1_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrEsc2_MASK         (0x1000U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc2_SHIFT        (12U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc2(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrEsc2_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrEsc2_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrEsc3_MASK         (0x2000U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc3_SHIFT        (13U)
#define MIPI_DSI_DSI_INTSRC_ErrEsc3(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrEsc3_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrEsc3_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrRxCRC_MASK        (0x4000U)
#define MIPI_DSI_DSI_INTSRC_ErrRxCRC_SHIFT       (14U)
#define MIPI_DSI_DSI_INTSRC_ErrRxCRC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrRxCRC_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrRxCRC_MASK)

#define MIPI_DSI_DSI_INTSRC_ErrRxECC_MASK        (0x8000U)
#define MIPI_DSI_DSI_INTSRC_ErrRxECC_SHIFT       (15U)
#define MIPI_DSI_DSI_INTSRC_ErrRxECC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_ErrRxECC_SHIFT)) & MIPI_DSI_DSI_INTSRC_ErrRxECC_MASK)

#define MIPI_DSI_DSI_INTSRC_RxAck_MASK           (0x10000U)
#define MIPI_DSI_DSI_INTSRC_RxAck_SHIFT          (16U)
#define MIPI_DSI_DSI_INTSRC_RxAck(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_RxAck_SHIFT)) & MIPI_DSI_DSI_INTSRC_RxAck_MASK)

#define MIPI_DSI_DSI_INTSRC_RxTE_MASK            (0x20000U)
#define MIPI_DSI_DSI_INTSRC_RxTE_SHIFT           (17U)
#define MIPI_DSI_DSI_INTSRC_RxTE(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_RxTE_SHIFT)) & MIPI_DSI_DSI_INTSRC_RxTE_MASK)

#define MIPI_DSI_DSI_INTSRC_RxDatDone_MASK       (0x40000U)
#define MIPI_DSI_DSI_INTSRC_RxDatDone_SHIFT      (18U)
#define MIPI_DSI_DSI_INTSRC_RxDatDone(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_RxDatDone_SHIFT)) & MIPI_DSI_DSI_INTSRC_RxDatDone_MASK)

#define MIPI_DSI_DSI_INTSRC_TaTout_MASK          (0x100000U)
#define MIPI_DSI_DSI_INTSRC_TaTout_SHIFT         (20U)
#define MIPI_DSI_DSI_INTSRC_TaTout(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_TaTout_SHIFT)) & MIPI_DSI_DSI_INTSRC_TaTout_MASK)

#define MIPI_DSI_DSI_INTSRC_LpdrTout_MASK        (0x200000U)
#define MIPI_DSI_DSI_INTSRC_LpdrTout_SHIFT       (21U)
#define MIPI_DSI_DSI_INTSRC_LpdrTout(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_LpdrTout_SHIFT)) & MIPI_DSI_DSI_INTSRC_LpdrTout_MASK)

#define MIPI_DSI_DSI_INTSRC_FrameDone_MASK       (0x1000000U)
#define MIPI_DSI_DSI_INTSRC_FrameDone_SHIFT      (24U)
#define MIPI_DSI_DSI_INTSRC_FrameDone(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_FrameDone_SHIFT)) & MIPI_DSI_DSI_INTSRC_FrameDone_MASK)

#define MIPI_DSI_DSI_INTSRC_BusTurnOver_MASK     (0x2000000U)
#define MIPI_DSI_DSI_INTSRC_BusTurnOver_SHIFT    (25U)
#define MIPI_DSI_DSI_INTSRC_BusTurnOver(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_BusTurnOver_SHIFT)) & MIPI_DSI_DSI_INTSRC_BusTurnOver_MASK)

#define MIPI_DSI_DSI_INTSRC_SyncOverride_MASK    (0x8000000U)
#define MIPI_DSI_DSI_INTSRC_SyncOverride_SHIFT   (27U)
#define MIPI_DSI_DSI_INTSRC_SyncOverride(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SyncOverride_SHIFT)) & MIPI_DSI_DSI_INTSRC_SyncOverride_MASK)

#define MIPI_DSI_DSI_INTSRC_SFRPHFifoEmpty_MASK  (0x10000000U)
#define MIPI_DSI_DSI_INTSRC_SFRPHFifoEmpty_SHIFT (28U)
#define MIPI_DSI_DSI_INTSRC_SFRPHFifoEmpty(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SFRPHFifoEmpty_SHIFT)) & MIPI_DSI_DSI_INTSRC_SFRPHFifoEmpty_MASK)

#define MIPI_DSI_DSI_INTSRC_SFRPLFifoEmpty_MASK  (0x20000000U)
#define MIPI_DSI_DSI_INTSRC_SFRPLFifoEmpty_SHIFT (29U)
#define MIPI_DSI_DSI_INTSRC_SFRPLFifoEmpty(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SFRPLFifoEmpty_SHIFT)) & MIPI_DSI_DSI_INTSRC_SFRPLFifoEmpty_MASK)

#define MIPI_DSI_DSI_INTSRC_SwRstRelease_MASK    (0x40000000U)
#define MIPI_DSI_DSI_INTSRC_SwRstRelease_SHIFT   (30U)
#define MIPI_DSI_DSI_INTSRC_SwRstRelease(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_SwRstRelease_SHIFT)) & MIPI_DSI_DSI_INTSRC_SwRstRelease_MASK)

#define MIPI_DSI_DSI_INTSRC_PllStable_MASK       (0x80000000U)
#define MIPI_DSI_DSI_INTSRC_PllStable_SHIFT      (31U)
#define MIPI_DSI_DSI_INTSRC_PllStable(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTSRC_PllStable_SHIFT)) & MIPI_DSI_DSI_INTSRC_PllStable_MASK)
/*! @} */

/*! @name DSI_INTMSK - Specifies the interrupt mask register. */
/*! @{ */

#define MIPI_DSI_DSI_INTMSK_MskContentLP1_MASK   (0x1U)
#define MIPI_DSI_DSI_INTMSK_MskContentLP1_SHIFT  (0U)
#define MIPI_DSI_DSI_INTMSK_MskContentLP1(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskContentLP1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskContentLP1_MASK)

#define MIPI_DSI_DSI_INTMSK_MskContentLP0_MASK   (0x2U)
#define MIPI_DSI_DSI_INTMSK_MskContentLP0_SHIFT  (1U)
#define MIPI_DSI_DSI_INTMSK_MskContentLP0(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskContentLP0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskContentLP0_MASK)

#define MIPI_DSI_DSI_INTMSK_MskControl0_MASK     (0x4U)
#define MIPI_DSI_DSI_INTMSK_MskControl0_SHIFT    (2U)
#define MIPI_DSI_DSI_INTMSK_MskControl0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskControl0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskControl0_MASK)

#define MIPI_DSI_DSI_INTMSK_MskControl1_MASK     (0x8U)
#define MIPI_DSI_DSI_INTMSK_MskControl1_SHIFT    (3U)
#define MIPI_DSI_DSI_INTMSK_MskControl1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskControl1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskControl1_MASK)

#define MIPI_DSI_DSI_INTMSK_MskControl2_MASK     (0x10U)
#define MIPI_DSI_DSI_INTMSK_MskControl2_SHIFT    (4U)
#define MIPI_DSI_DSI_INTMSK_MskControl2(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskControl2_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskControl2_MASK)

#define MIPI_DSI_DSI_INTMSK_MskControl3_MASK     (0x20U)
#define MIPI_DSI_DSI_INTMSK_MskControl3_SHIFT    (5U)
#define MIPI_DSI_DSI_INTMSK_MskControl3(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskControl3_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskControl3_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSync0_MASK        (0x40U)
#define MIPI_DSI_DSI_INTMSK_MskSync0_SHIFT       (6U)
#define MIPI_DSI_DSI_INTMSK_MskSync0(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSync0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSync0_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSync1_MASK        (0x80U)
#define MIPI_DSI_DSI_INTMSK_MskSync1_SHIFT       (7U)
#define MIPI_DSI_DSI_INTMSK_MskSync1(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSync1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSync1_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSync2_MASK        (0x100U)
#define MIPI_DSI_DSI_INTMSK_MskSync2_SHIFT       (8U)
#define MIPI_DSI_DSI_INTMSK_MskSync2(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSync2_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSync2_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSync3_MASK        (0x200U)
#define MIPI_DSI_DSI_INTMSK_MskSync3_SHIFT       (9U)
#define MIPI_DSI_DSI_INTMSK_MskSync3(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSync3_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSync3_MASK)

#define MIPI_DSI_DSI_INTMSK_MskEsc0_MASK         (0x400U)
#define MIPI_DSI_DSI_INTMSK_MskEsc0_SHIFT        (10U)
#define MIPI_DSI_DSI_INTMSK_MskEsc0(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskEsc0_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskEsc0_MASK)

#define MIPI_DSI_DSI_INTMSK_MskEsc1_MASK         (0x800U)
#define MIPI_DSI_DSI_INTMSK_MskEsc1_SHIFT        (11U)
#define MIPI_DSI_DSI_INTMSK_MskEsc1(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskEsc1_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskEsc1_MASK)

#define MIPI_DSI_DSI_INTMSK_MskEsc2_MASK         (0x1000U)
#define MIPI_DSI_DSI_INTMSK_MskEsc2_SHIFT        (12U)
#define MIPI_DSI_DSI_INTMSK_MskEsc2(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskEsc2_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskEsc2_MASK)

#define MIPI_DSI_DSI_INTMSK_MskEsc3_MASK         (0x2000U)
#define MIPI_DSI_DSI_INTMSK_MskEsc3_SHIFT        (13U)
#define MIPI_DSI_DSI_INTMSK_MskEsc3(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskEsc3_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskEsc3_MASK)

#define MIPI_DSI_DSI_INTMSK_MskRxCRC_MASK        (0x4000U)
#define MIPI_DSI_DSI_INTMSK_MskRxCRC_SHIFT       (14U)
#define MIPI_DSI_DSI_INTMSK_MskRxCRC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskRxCRC_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskRxCRC_MASK)

#define MIPI_DSI_DSI_INTMSK_MskRxECC_MASK        (0x8000U)
#define MIPI_DSI_DSI_INTMSK_MskRxECC_SHIFT       (15U)
#define MIPI_DSI_DSI_INTMSK_MskRxECC(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskRxECC_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskRxECC_MASK)

#define MIPI_DSI_DSI_INTMSK_MskRxAck_MASK        (0x10000U)
#define MIPI_DSI_DSI_INTMSK_MskRxAck_SHIFT       (16U)
#define MIPI_DSI_DSI_INTMSK_MskRxAck(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskRxAck_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskRxAck_MASK)

#define MIPI_DSI_DSI_INTMSK_MskRxTE_MASK         (0x20000U)
#define MIPI_DSI_DSI_INTMSK_MskRxTE_SHIFT        (17U)
#define MIPI_DSI_DSI_INTMSK_MskRxTE(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskRxTE_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskRxTE_MASK)

#define MIPI_DSI_DSI_INTMSK_MskRxDatDone_MASK    (0x40000U)
#define MIPI_DSI_DSI_INTMSK_MskRxDatDone_SHIFT   (18U)
#define MIPI_DSI_DSI_INTMSK_MskRxDatDone(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskRxDatDone_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskRxDatDone_MASK)

#define MIPI_DSI_DSI_INTMSK_MskTaTout_MASK       (0x100000U)
#define MIPI_DSI_DSI_INTMSK_MskTaTout_SHIFT      (20U)
#define MIPI_DSI_DSI_INTMSK_MskTaTout(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskTaTout_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskTaTout_MASK)

#define MIPI_DSI_DSI_INTMSK_MskLpdrTout_MASK     (0x200000U)
#define MIPI_DSI_DSI_INTMSK_MskLpdrTout_SHIFT    (21U)
#define MIPI_DSI_DSI_INTMSK_MskLpdrTout(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskLpdrTout_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskLpdrTout_MASK)

#define MIPI_DSI_DSI_INTMSK_MskFrameDone_MASK    (0x1000000U)
#define MIPI_DSI_DSI_INTMSK_MskFrameDone_SHIFT   (24U)
#define MIPI_DSI_DSI_INTMSK_MskFrameDone(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskFrameDone_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskFrameDone_MASK)

#define MIPI_DSI_DSI_INTMSK_MskBusTurnOver_MASK  (0x2000000U)
#define MIPI_DSI_DSI_INTMSK_MskBusTurnOver_SHIFT (25U)
#define MIPI_DSI_DSI_INTMSK_MskBusTurnOver(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskBusTurnOver_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskBusTurnOver_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSyncOverride_MASK (0x8000000U)
#define MIPI_DSI_DSI_INTMSK_MskSyncOverride_SHIFT (27U)
#define MIPI_DSI_DSI_INTMSK_MskSyncOverride(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSyncOverride_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSyncOverride_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSFRPHFifoEmpty_MASK (0x10000000U)
#define MIPI_DSI_DSI_INTMSK_MskSFRPHFifoEmpty_SHIFT (28U)
#define MIPI_DSI_DSI_INTMSK_MskSFRPHFifoEmpty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSFRPHFifoEmpty_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSFRPHFifoEmpty_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSFRPLFifoEmpty_MASK (0x20000000U)
#define MIPI_DSI_DSI_INTMSK_MskSFRPLFifoEmpty_SHIFT (29U)
#define MIPI_DSI_DSI_INTMSK_MskSFRPLFifoEmpty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSFRPLFifoEmpty_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSFRPLFifoEmpty_MASK)

#define MIPI_DSI_DSI_INTMSK_MskSwRstRelease_MASK (0x40000000U)
#define MIPI_DSI_DSI_INTMSK_MskSwRstRelease_SHIFT (30U)
#define MIPI_DSI_DSI_INTMSK_MskSwRstRelease(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskSwRstRelease_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskSwRstRelease_MASK)

#define MIPI_DSI_DSI_INTMSK_MskPllStable_MASK    (0x80000000U)
#define MIPI_DSI_DSI_INTMSK_MskPllStable_SHIFT   (31U)
#define MIPI_DSI_DSI_INTMSK_MskPllStable(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_INTMSK_MskPllStable_SHIFT)) & MIPI_DSI_DSI_INTMSK_MskPllStable_MASK)
/*! @} */

/*! @name DSI_PKTHDR - Specifies the packet header FIFO register. */
/*! @{ */

#define MIPI_DSI_DSI_PKTHDR_PacketHeader_MASK    (0xFFFFFFU)
#define MIPI_DSI_DSI_PKTHDR_PacketHeader_SHIFT   (0U)
#define MIPI_DSI_DSI_PKTHDR_PacketHeader(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PKTHDR_PacketHeader_SHIFT)) & MIPI_DSI_DSI_PKTHDR_PacketHeader_MASK)
/*! @} */

/*! @name DSI_PAYLOAD - Specifies the payload FIFO register. */
/*! @{ */

#define MIPI_DSI_DSI_PAYLOAD_Payload_MASK        (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PAYLOAD_Payload_SHIFT       (0U)
#define MIPI_DSI_DSI_PAYLOAD_Payload(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PAYLOAD_Payload_SHIFT)) & MIPI_DSI_DSI_PAYLOAD_Payload_MASK)
/*! @} */

/*! @name DSI_RXFIFO - Specifies the read FIFO register. */
/*! @{ */

#define MIPI_DSI_DSI_RXFIFO_RxDat_MASK           (0xFFFFFFFFU)
#define MIPI_DSI_DSI_RXFIFO_RxDat_SHIFT          (0U)
#define MIPI_DSI_DSI_RXFIFO_RxDat(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_RXFIFO_RxDat_SHIFT)) & MIPI_DSI_DSI_RXFIFO_RxDat_MASK)
/*! @} */

/*! @name DSI_FIFOTHLD - Specifies the FIFO threshold level register. */
/*! @{ */

#define MIPI_DSI_DSI_FIFOTHLD_WfullLevelSfr_MASK (0x1FFU)
#define MIPI_DSI_DSI_FIFOTHLD_WfullLevelSfr_SHIFT (0U)
#define MIPI_DSI_DSI_FIFOTHLD_WfullLevelSfr(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOTHLD_WfullLevelSfr_SHIFT)) & MIPI_DSI_DSI_FIFOTHLD_WfullLevelSfr_MASK)
/*! @} */

/*! @name DSI_FIFOCTRL - Specifies the FIFO status and control register. */
/*! @{ */

#define MIPI_DSI_DSI_FIFOCTRL_nInitMain_MASK     (0x1U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitMain_SHIFT    (0U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitMain(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_nInitMain_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_nInitMain_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_nInitSub_MASK      (0x2U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitSub_SHIFT     (1U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitSub(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_nInitSub_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_nInitSub_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_nInitI80_MASK      (0x4U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitI80_SHIFT     (2U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitI80(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_nInitI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_nInitI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_nInitSfr_MASK      (0x8U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitSfr_SHIFT     (3U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitSfr(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_nInitSfr_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_nInitSfr_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_nInitRx_MASK       (0x10U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitRx_SHIFT      (4U)
#define MIPI_DSI_DSI_FIFOCTRL_nInitRx(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_nInitRx_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_nInitRx_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyLMain_MASK    (0x100U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLMain_SHIFT   (8U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLMain(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyLMain_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyLMain_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullLMain_MASK     (0x200U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLMain_SHIFT    (9U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLMain(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullLMain_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullLMain_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyHMain_MASK    (0x400U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHMain_SHIFT   (10U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHMain(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyHMain_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyHMain_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullHMain_MASK     (0x800U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHMain_SHIFT    (11U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHMain(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullHMain_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullHMain_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyLSub_MASK     (0x1000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLSub_SHIFT    (12U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLSub(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyLSub_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyLSub_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullLSub_MASK      (0x2000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLSub_SHIFT     (13U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLSub(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullLSub_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullLSub_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyHSub_MASK     (0x4000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHSub_SHIFT    (14U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHSub(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyHSub_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyHSub_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullHSub_MASK      (0x8000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHSub_SHIFT     (15U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHSub(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullHSub_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullHSub_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyLI80_MASK     (0x10000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLI80_SHIFT    (16U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLI80(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyLI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyLI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullLI80_MASK      (0x20000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLI80_SHIFT     (17U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLI80(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullLI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullLI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyHI80_MASK     (0x40000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHI80_SHIFT    (18U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHI80(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyHI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyHI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullHI80_MASK      (0x80000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHI80_SHIFT     (19U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHI80(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullHI80_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullHI80_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyLSfr_MASK     (0x100000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLSfr_SHIFT    (20U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyLSfr(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyLSfr_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyLSfr_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullLSfr_MASK      (0x200000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLSfr_SHIFT     (21U)
#define MIPI_DSI_DSI_FIFOCTRL_FullLSfr(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullLSfr_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullLSfr_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyHSfr_MASK     (0x400000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHSfr_SHIFT    (22U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyHSfr(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyHSfr_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyHSfr_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullHSfr_MASK      (0x800000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHSfr_SHIFT     (23U)
#define MIPI_DSI_DSI_FIFOCTRL_FullHSfr(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullHSfr_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullHSfr_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_EmptyRx_MASK       (0x1000000U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyRx_SHIFT      (24U)
#define MIPI_DSI_DSI_FIFOCTRL_EmptyRx(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_EmptyRx_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_EmptyRx_MASK)

#define MIPI_DSI_DSI_FIFOCTRL_FullRx_MASK        (0x2000000U)
#define MIPI_DSI_DSI_FIFOCTRL_FullRx_SHIFT       (25U)
#define MIPI_DSI_DSI_FIFOCTRL_FullRx(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_FIFOCTRL_FullRx_SHIFT)) & MIPI_DSI_DSI_FIFOCTRL_FullRx_MASK)
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

#define MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_Cnt_Ref_MASK (0xFFFFU)
#define MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_Cnt_Ref_SHIFT (0U)
#define MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_Cnt_Ref(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_Cnt_Ref_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_Cnt_Ref_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_PKT_Send_Cnt_Ref_MASK (0xFFF0000U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_Send_Cnt_Ref_SHIFT (16U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_Send_Cnt_Ref(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_PKT_Send_Cnt_Ref_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_PKT_Send_Cnt_Ref_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_PKT_Go_Rdy_MASK   (0x10000000U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_Go_Rdy_SHIFT  (28U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_Go_Rdy(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_PKT_Go_Rdy_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_PKT_Go_Rdy_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_PKT_Go_EN_MASK    (0x20000000U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_Go_EN_SHIFT   (29U)
#define MIPI_DSI_DSI_MULTI_PKT_PKT_Go_EN(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_PKT_Go_EN_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_PKT_Go_EN_MASK)

#define MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_EN_MASK (0x40000000U)
#define MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_EN_SHIFT (30U)
#define MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_EN(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_EN_SHIFT)) & MIPI_DSI_DSI_MULTI_PKT_Multi_PKT_EN_MASK)
/*! @} */

/*! @name DSI_PLLCTRL_1G - Specifies the 1Gbps D-PHY PLL control register. */
/*! @{ */

#define MIPI_DSI_DSI_PLLCTRL_1G_PRPRCtlClk_MASK  (0x7U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PRPRCtlClk_SHIFT (0U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PRPRCtlClk(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_PRPRCtlClk_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_PRPRCtlClk_MASK)

#define MIPI_DSI_DSI_PLLCTRL_1G_PREPRCtl_MASK    (0x70U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PREPRCtl_SHIFT   (4U)
#define MIPI_DSI_DSI_PLLCTRL_1G_PREPRCtl(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_PREPRCtl_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_PREPRCtl_MASK)

#define MIPI_DSI_DSI_PLLCTRL_1G_Freq_Band_MASK   (0xF00U)
#define MIPI_DSI_DSI_PLLCTRL_1G_Freq_Band_SHIFT  (8U)
#define MIPI_DSI_DSI_PLLCTRL_1G_Freq_Band(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_Freq_Band_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_Freq_Band_MASK)

#define MIPI_DSI_DSI_PLLCTRL_1G_HSzeroCtl_MASK   (0xF000U)
#define MIPI_DSI_DSI_PLLCTRL_1G_HSzeroCtl_SHIFT  (12U)
#define MIPI_DSI_DSI_PLLCTRL_1G_HSzeroCtl(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_1G_HSzeroCtl_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_1G_HSzeroCtl_MASK)
/*! @} */

/*! @name DSI_PLLCTRL - Specifies the PLL control register. */
/*! @{ */

#define MIPI_DSI_DSI_PLLCTRL_PMS_MASK            (0xFFFFEU)
#define MIPI_DSI_DSI_PLLCTRL_PMS_SHIFT           (1U)
#define MIPI_DSI_DSI_PLLCTRL_PMS(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_PMS_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_PMS_MASK)

#define MIPI_DSI_DSI_PLLCTRL_PllEn_MASK          (0x800000U)
#define MIPI_DSI_DSI_PLLCTRL_PllEn_SHIFT         (23U)
#define MIPI_DSI_DSI_PLLCTRL_PllEn(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_PllEn_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_PllEn_MASK)

#define MIPI_DSI_DSI_PLLCTRL_DpDnSwap_DAT_MASK   (0x1000000U)
#define MIPI_DSI_DSI_PLLCTRL_DpDnSwap_DAT_SHIFT  (24U)
#define MIPI_DSI_DSI_PLLCTRL_DpDnSwap_DAT(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_DpDnSwap_DAT_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_DpDnSwap_DAT_MASK)

#define MIPI_DSI_DSI_PLLCTRL_DpDnSwap_CLK_MASK   (0x2000000U)
#define MIPI_DSI_DSI_PLLCTRL_DpDnSwap_CLK_SHIFT  (25U)
#define MIPI_DSI_DSI_PLLCTRL_DpDnSwap_CLK(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLCTRL_DpDnSwap_CLK_SHIFT)) & MIPI_DSI_DSI_PLLCTRL_DpDnSwap_CLK_MASK)
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

#define MIPI_DSI_DSI_PLLTMR_PllTimer_MASK        (0xFFFFFFFFU)
#define MIPI_DSI_DSI_PLLTMR_PllTimer_SHIFT       (0U)
#define MIPI_DSI_DSI_PLLTMR_PllTimer(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSI_PLLTMR_PllTimer_SHIFT)) & MIPI_DSI_DSI_PLLTMR_PllTimer_MASK)
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_MIPI_DSI_H_ */

