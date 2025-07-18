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
**         CMSIS Peripheral Access Layer for HSIO_BLK_CTRL
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
 * @file PERI_HSIO_BLK_CTRL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HSIO_BLK_CTRL
 *
 * CMSIS Peripheral Access Layer for HSIO_BLK_CTRL
 */

#if !defined(PERI_HSIO_BLK_CTRL_H_)
#define PERI_HSIO_BLK_CTRL_H_                    /**< Symbol preventing repeated inclusion */

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
   -- HSIO_BLK_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSIO_BLK_CTRL_Peripheral_Access_Layer HSIO_BLK_CTRL Peripheral Access Layer
 * @{
 */

/** HSIO_BLK_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR_REG0;                          /**< Clock select reset and debug info select, offset: 0x0 */
  __I  uint32_t GPR_REG1;                          /**< PCIE controller status, offset: 0x4 */
  __IO uint32_t GPR_REG2;                          /**< PLL configuration 0, offset: 0x8 */
  __IO uint32_t GPR_REG3;                          /**< PLL configuration 1, offset: 0xC */
  __IO uint32_t GPR_REG4;                          /**< PCIE PME message and error detect register, offset: 0x10 */
  __IO uint32_t GPR_REG5;                          /**< PCIE PME message and error detect interrupt enable register, offset: 0x14 */
  __IO uint32_t GPR_REG6;                          /**< PCIE PME message and error detect interrupt detect disable register, offset: 0x18 */
  __IO uint32_t GPR_REG7;                          /**< USB1 beat limit and enable, offset: 0x1C */
  __IO uint32_t GPR_REG8;                          /**< USB2 beat limit and enable, offset: 0x20 */
  __IO uint32_t GPR_REG9;                          /**< PCIE beat limit and enable, offset: 0x24 */
       uint8_t RESERVED_0[216];
  __IO uint32_t USB1_WAKEUP_CTRL;                  /**< Register for USB1 wakeup, offset: 0x100 */
  __I  uint32_t USB1_WAKEUP_STATUS;                /**< Status of USB1 wakeup, offset: 0x104 */
  __IO uint32_t USB2_WAKEUP_CTRL;                  /**< Register for USB2 wakeup, offset: 0x108 */
  __I  uint32_t USB2_WAKEUP_STATUS;                /**< Status of USB2 wakeup, offset: 0x10C */
} HSIO_BLK_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- HSIO_BLK_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSIO_BLK_CTRL_Register_Masks HSIO_BLK_CTRL Register Masks
 * @{
 */

/*! @name GPR_REG0 - Clock select reset and debug info select */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG0_PCIE_CLOCK_MODULE_EN_MASK (0x1U)
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_CLOCK_MODULE_EN_SHIFT (0U)
/*! PCIE_CLOCK_MODULE_EN - PCIE related clock enable */
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_CLOCK_MODULE_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_PCIE_CLOCK_MODULE_EN_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_PCIE_CLOCK_MODULE_EN_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_USB_CLOCK_MODULE_EN_MASK (0x2U)
#define HSIO_BLK_CTRL_GPR_REG0_USB_CLOCK_MODULE_EN_SHIFT (1U)
/*! USB_CLOCK_MODULE_EN - USB related clock enable */
#define HSIO_BLK_CTRL_GPR_REG0_USB_CLOCK_MODULE_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_USB_CLOCK_MODULE_EN_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_USB_CLOCK_MODULE_EN_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_PCIE_USB_DEBUG_INFO_SEL_MASK (0xCU)
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_USB_DEBUG_INFO_SEL_SHIFT (2U)
/*! PCIE_USB_DEBUG_INFO_SEL - PCIE USB debug information selection */
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_USB_DEBUG_INFO_SEL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_PCIE_USB_DEBUG_INFO_SEL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_PCIE_USB_DEBUG_INFO_SEL_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_APB_RESETN_INTERNAL_MASK (0x10U)
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_APB_RESETN_INTERNAL_SHIFT (4U)
/*! PCIE_PHY_APB_RESETN_INTERNAL - PCIE PHY APB interface reset */
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_APB_RESETN_INTERNAL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_APB_RESETN_INTERNAL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_APB_RESETN_INTERNAL_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_INIT_RESETN_INTERNAL_MASK (0x20U)
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_INIT_RESETN_INTERNAL_SHIFT (5U)
/*! PCIE_PHY_INIT_RESETN_INTERNAL - PCIE PHY init reset */
#define HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_INIT_RESETN_INTERNAL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_INIT_RESETN_INTERNAL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_PCIE_PHY_INIT_RESETN_INTERNAL_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_USB_PHY_REF_CLK_SEL_MASK (0x40U)
#define HSIO_BLK_CTRL_GPR_REG0_USB_PHY_REF_CLK_SEL_SHIFT (6U)
/*! USB_PHY_REF_CLK_SEL - USB PHY ref clock selection
 *  0b0..24Mhz exteral osc
 *  0b1..100Mhz high performace PLL
 */
#define HSIO_BLK_CTRL_GPR_REG0_USB_PHY_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_USB_PHY_REF_CLK_SEL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_USB_PHY_REF_CLK_SEL_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_CFG_READY_MASK    (0x80U)
#define HSIO_BLK_CTRL_GPR_REG0_CFG_READY_SHIFT   (7U)
/*! CFG_READY - Configuration ready */
#define HSIO_BLK_CTRL_GPR_REG0_CFG_READY(x)      (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_CFG_READY_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_CFG_READY_MASK)

#define HSIO_BLK_CTRL_GPR_REG0_CRS_CLEAR_MASK    (0x100U)
#define HSIO_BLK_CTRL_GPR_REG0_CRS_CLEAR_SHIFT   (8U)
/*! CRS_CLEAR - Clear CSR interrupt */
#define HSIO_BLK_CTRL_GPR_REG0_CRS_CLEAR(x)      (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG0_CRS_CLEAR_SHIFT)) & HSIO_BLK_CTRL_GPR_REG0_CRS_CLEAR_MASK)
/*! @} */

/*! @name GPR_REG1 - PCIE controller status */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG1_PM_EN_CORE_CLK_MASK (0x1U)
#define HSIO_BLK_CTRL_GPR_REG1_PM_EN_CORE_CLK_SHIFT (0U)
/*! PM_EN_CORE_CLK - pm_en_core_clk pin status of pcie ctrl */
#define HSIO_BLK_CTRL_GPR_REG1_PM_EN_CORE_CLK(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_PM_EN_CORE_CLK_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_PM_EN_CORE_CLK_MASK)

#define HSIO_BLK_CTRL_GPR_REG1_SMLH_LTSSM_STATE_MASK (0x7EU)
#define HSIO_BLK_CTRL_GPR_REG1_SMLH_LTSSM_STATE_SHIFT (1U)
/*! SMLH_LTSSM_STATE - PCIE link state */
#define HSIO_BLK_CTRL_GPR_REG1_SMLH_LTSSM_STATE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_SMLH_LTSSM_STATE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_SMLH_LTSSM_STATE_MASK)

#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1SUB_MASK (0x80U)
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1SUB_SHIFT (7U)
/*! PCIE_CTRL_PM_LINKST_IN_L1SUB - PCIE ctrl link in l1sub state */
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1SUB(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1SUB_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1SUB_MASK)

#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1_MASK (0x100U)
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1_SHIFT (8U)
/*! PCIE_CTRL_PM_LINKST_IN_L1 - PCIE ctrl link in l1 state */
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L1_MASK)

#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L0S_MASK (0x200U)
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L0S_SHIFT (9U)
/*! PCIE_CTRL_PM_LINKST_IN_L0S - PCIE ctrl link in l0s state */
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L0S(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L0S_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_LINKST_IN_L0S_MASK)

#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_DSTATE_MASK (0x1C00U)
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_DSTATE_SHIFT (10U)
/*! PCIE_CTRL_PM_DSTATE - PCIE ctrl's pm dstate */
#define HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_DSTATE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_DSTATE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_PCIE_CTRL_PM_DSTATE_MASK)

#define HSIO_BLK_CTRL_GPR_REG1_PLL_LOCK_MASK     (0x2000U)
#define HSIO_BLK_CTRL_GPR_REG1_PLL_LOCK_SHIFT    (13U)
/*! PLL_LOCK - High performance PLL lock status */
#define HSIO_BLK_CTRL_GPR_REG1_PLL_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG1_PLL_LOCK_SHIFT)) & HSIO_BLK_CTRL_GPR_REG1_PLL_LOCK_MASK)
/*! @} */

/*! @name GPR_REG2 - PLL configuration 0 */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG2_P_PLL_MASK        (0x3FU)
#define HSIO_BLK_CTRL_GPR_REG2_P_PLL_SHIFT       (0U)
/*! P_PLL - P pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_P_PLL(x)          (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_P_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_P_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_M_PLL_MASK        (0xFFC0U)
#define HSIO_BLK_CTRL_GPR_REG2_M_PLL_SHIFT       (6U)
/*! M_PLL - M pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_M_PLL(x)          (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_M_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_M_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_S_PLL_MASK        (0x70000U)
#define HSIO_BLK_CTRL_GPR_REG2_S_PLL_SHIFT       (16U)
/*! S_PLL - S pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_S_PLL(x)          (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_S_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_S_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_ICP_PLL_MASK      (0x180000U)
#define HSIO_BLK_CTRL_GPR_REG2_ICP_PLL_SHIFT     (19U)
/*! ICP_PLL - ICP pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_ICP_PLL(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_ICP_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_ICP_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_BYPASS_PLL_MASK   (0x200000U)
#define HSIO_BLK_CTRL_GPR_REG2_BYPASS_PLL_SHIFT  (21U)
/*! BYPASS_PLL - Bypass pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_BYPASS_PLL(x)     (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_BYPASS_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_BYPASS_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_LOCK_EN_PLL_MASK  (0x400000U)
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_EN_PLL_SHIFT (22U)
/*! LOCK_EN_PLL - locken pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_EN_PLL(x)    (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_LOCK_EN_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_LOCK_EN_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_IN_PLL_MASK (0x1800000U)
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_IN_PLL_SHIFT (23U)
/*! LOCK_CON_IN_PLL - Lock con in pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_IN_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_IN_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_IN_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_OUT_PLL_MASK (0x6000000U)
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_OUT_PLL_SHIFT (25U)
/*! LOCK_CON_OUT_PLL - Lock con input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_OUT_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_OUT_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_OUT_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_DLY_PLL_MASK (0x18000000U)
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_DLY_PLL_SHIFT (27U)
/*! LOCK_CON_DLY_PLL - Lock con delay input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_DLY_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_DLY_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_DLY_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_REV_PLL_MASK (0x60000000U)
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_REV_PLL_SHIFT (29U)
/*! LOCK_CON_REV_PLL - Lock con rev pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_REV_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_REV_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_LOCK_CON_REV_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG2_AFC_ENB_PLL_MASK  (0x80000000U)
#define HSIO_BLK_CTRL_GPR_REG2_AFC_ENB_PLL_SHIFT (31U)
/*! AFC_ENB_PLL - AFC_ENB input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG2_AFC_ENB_PLL(x)    (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG2_AFC_ENB_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG2_AFC_ENB_PLL_MASK)
/*! @} */

/*! @name GPR_REG3 - PLL configuration 1 */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG3_EXTAFC_PLL_MASK   (0x1FU)
#define HSIO_BLK_CTRL_GPR_REG3_EXTAFC_PLL_SHIFT  (0U)
/*! EXTAFC_PLL - Extafc pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_EXTAFC_PLL(x)     (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_EXTAFC_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_EXTAFC_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_FEED_EN_PLL_MASK  (0x20U)
#define HSIO_BLK_CTRL_GPR_REG3_FEED_EN_PLL_SHIFT (5U)
/*! FEED_EN_PLL - Feed en pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_FEED_EN_PLL(x)    (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_FEED_EN_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_FEED_EN_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_FSEL_PLL_MASK     (0x40U)
#define HSIO_BLK_CTRL_GPR_REG3_FSEL_PLL_SHIFT    (6U)
/*! FSEL_PLL - FSEL pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_FSEL_PLL(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_FSEL_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_FSEL_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_AFCINIT_SEL_PLL_MASK (0x80U)
#define HSIO_BLK_CTRL_GPR_REG3_AFCINIT_SEL_PLL_SHIFT (7U)
/*! AFCINIT_SEL_PLL - AFCINT SEL input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_AFCINIT_SEL_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_AFCINIT_SEL_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_AFCINIT_SEL_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_FOUT_MASK_PLL_MASK (0x100U)
#define HSIO_BLK_CTRL_GPR_REG3_FOUT_MASK_PLL_SHIFT (8U)
/*! FOUT_MASK_PLL - FOUT MASK pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_FOUT_MASK_PLL(x)  (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_FOUT_MASK_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_FOUT_MASK_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_VCO_BOOST_PLL_MASK (0x200U)
#define HSIO_BLK_CTRL_GPR_REG3_VCO_BOOST_PLL_SHIFT (9U)
/*! VCO_BOOST_PLL - VCO BOOST pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_VCO_BOOST_PLL(x)  (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_VCO_BOOST_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_VCO_BOOST_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_EN_PLL_MASK (0x400U)
#define HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_EN_PLL_SHIFT (10U)
/*! PBIAS_CTRL_EN_PLL - PBIAS CTRL EN pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_EN_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_EN_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_EN_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_PLL_MASK (0x800U)
#define HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_PLL_SHIFT (11U)
/*! PBIAS_CTRL_PLL - PBIAS CTRL pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_PLL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_PBIAS_CTRL_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_LRD_EN_PLL_MASK   (0x1000U)
#define HSIO_BLK_CTRL_GPR_REG3_LRD_EN_PLL_SHIFT  (12U)
/*! LRD_EN_PLL - LRD EN pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_LRD_EN_PLL(x)     (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_LRD_EN_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_LRD_EN_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_RSEL_PLL_MASK     (0x1E000U)
#define HSIO_BLK_CTRL_GPR_REG3_RSEL_PLL_SHIFT    (13U)
/*! RSEL_PLL - RSEL pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_RSEL_PLL(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_RSEL_PLL_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_RSEL_PLL_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_PLL_CKE_MASK      (0x20000U)
#define HSIO_BLK_CTRL_GPR_REG3_PLL_CKE_SHIFT     (17U)
/*! PLL_CKE - PLL cke pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_PLL_CKE(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_PLL_CKE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_PLL_CKE_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_PLL_EXT_BYPASS_MASK (0x40000U)
#define HSIO_BLK_CTRL_GPR_REG3_PLL_EXT_BYPASS_SHIFT (18U)
/*! PLL_EXT_BYPASS - PLL ext bypass pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_PLL_EXT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_PLL_EXT_BYPASS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_PLL_EXT_BYPASS_MASK)

#define HSIO_BLK_CTRL_GPR_REG3_PLL_RESETB_MASK   (0x80000000U)
#define HSIO_BLK_CTRL_GPR_REG3_PLL_RESETB_SHIFT  (31U)
/*! PLL_RESETB - reset pin input of high performance PLL */
#define HSIO_BLK_CTRL_GPR_REG3_PLL_RESETB(x)     (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG3_PLL_RESETB_SHIFT)) & HSIO_BLK_CTRL_GPR_REG3_PLL_RESETB_MASK)
/*! @} */

/*! @name GPR_REG4 - PCIE PME message and error detect register */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG4_LUD_MASK          (0x1U)
#define HSIO_BLK_CTRL_GPR_REG4_LUD_SHIFT         (0U)
/*! LUD - Indicates a link up was detected */
#define HSIO_BLK_CTRL_GPR_REG4_LUD(x)            (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_LUD_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_LUD_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_LDD_MASK          (0x2U)
#define HSIO_BLK_CTRL_GPR_REG4_LDD_SHIFT         (1U)
/*! LDD - Indicates a link down was detected */
#define HSIO_BLK_CTRL_GPR_REG4_LDD(x)            (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_LDD_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_LDD_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_HRD_MASK          (0x4U)
#define HSIO_BLK_CTRL_GPR_REG4_HRD_SHIFT         (2U)
/*! HRD - Indicates a hot reset was detected */
#define HSIO_BLK_CTRL_GPR_REG4_HRD(x)            (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_HRD_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_HRD_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_PTO_MASK          (0x8U)
#define HSIO_BLK_CTRL_GPR_REG4_PTO_SHIFT         (3U)
/*! PTO - Indicates that PME turn off was detected */
#define HSIO_BLK_CTRL_GPR_REG4_PTO(x)            (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_PTO_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_PTO_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_UREP_MASK         (0x10U)
#define HSIO_BLK_CTRL_GPR_REG4_UREP_SHIFT        (4U)
/*! UREP - Indicates an unsupported request completion was detected */
#define HSIO_BLK_CTRL_GPR_REG4_UREP(x)           (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_UREP_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_UREP_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_CDNSC_MASK        (0x20U)
#define HSIO_BLK_CTRL_GPR_REG4_CDNSC_SHIFT       (5U)
/*! CDNSC - Completion with data not succsessful was detected. */
#define HSIO_BLK_CTRL_GPR_REG4_CDNSC(x)          (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_CDNSC_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_CDNSC_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_PCAC_MASK         (0x40U)
#define HSIO_BLK_CTRL_GPR_REG4_PCAC_SHIFT        (6U)
/*! PCAC - Completer abort was detected. */
#define HSIO_BLK_CTRL_GPR_REG4_PCAC(x)           (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_PCAC_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_PCAC_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_PCT_MASK          (0x80U)
#define HSIO_BLK_CTRL_GPR_REG4_PCT_SHIFT         (7U)
/*! PCT - Indicates completion timeout */
#define HSIO_BLK_CTRL_GPR_REG4_PCT(x)            (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_PCT_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_PCT_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_ME_MASK           (0x100U)
#define HSIO_BLK_CTRL_GPR_REG4_ME_SHIFT          (8U)
/*! ME - Indicates Multiple errors of same type. If any of the detectable errors in PEX_ERR_DET
 *    register is detected more than one time the ME bit will be set
 */
#define HSIO_BLK_CTRL_GPR_REG4_ME(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_ME_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_ME_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_INTE_MASK         (0x40000000U)
#define HSIO_BLK_CTRL_GPR_REG4_INTE_SHIFT        (30U)
/*! INTE - Per PF dependent error interrupt is pending. */
#define HSIO_BLK_CTRL_GPR_REG4_INTE(x)           (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_INTE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_INTE_MASK)

#define HSIO_BLK_CTRL_GPR_REG4_INTM_MASK         (0x80000000U)
#define HSIO_BLK_CTRL_GPR_REG4_INTM_SHIFT        (31U)
/*! INTM - Per PF dependent message interrupt is pending */
#define HSIO_BLK_CTRL_GPR_REG4_INTM(x)           (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG4_INTM_SHIFT)) & HSIO_BLK_CTRL_GPR_REG4_INTM_MASK)
/*! @} */

/*! @name GPR_REG5 - PCIE PME message and error detect interrupt enable register */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG5_LUD_IE_MASK       (0x1U)
#define HSIO_BLK_CTRL_GPR_REG5_LUD_IE_SHIFT      (0U)
/*! LUD_IE - Link up detect interrupt enable */
#define HSIO_BLK_CTRL_GPR_REG5_LUD_IE(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_LUD_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_LUD_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_LDD_IE_MASK       (0x2U)
#define HSIO_BLK_CTRL_GPR_REG5_LDD_IE_SHIFT      (1U)
/*! LDD_IE - Link down detect interrupt enable */
#define HSIO_BLK_CTRL_GPR_REG5_LDD_IE(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_LDD_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_LDD_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_HRD_IE_MASK       (0x4U)
#define HSIO_BLK_CTRL_GPR_REG5_HRD_IE_SHIFT      (2U)
/*! HRD_IE - Hot reset detect interrupt enable. */
#define HSIO_BLK_CTRL_GPR_REG5_HRD_IE(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_HRD_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_HRD_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_PTO_IE_MASK       (0x8U)
#define HSIO_BLK_CTRL_GPR_REG5_PTO_IE_SHIFT      (3U)
/*! PTO_IE - PME turn off detect interrupt enable */
#define HSIO_BLK_CTRL_GPR_REG5_PTO_IE(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_PTO_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_PTO_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_UREP_IE_MASK      (0x10U)
#define HSIO_BLK_CTRL_GPR_REG5_UREP_IE_SHIFT     (4U)
/*! UREP_IE - Unsupported request in EP mode interrupt enable. */
#define HSIO_BLK_CTRL_GPR_REG5_UREP_IE(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_UREP_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_UREP_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_CDNSC_IE_MASK     (0x20U)
#define HSIO_BLK_CTRL_GPR_REG5_CDNSC_IE_SHIFT    (5U)
/*! CDNSC_IE - Completion with data not succsessful interrupt enable */
#define HSIO_BLK_CTRL_GPR_REG5_CDNSC_IE(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_CDNSC_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_CDNSC_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_PCAC_IE_MASK      (0x40U)
#define HSIO_BLK_CTRL_GPR_REG5_PCAC_IE_SHIFT     (6U)
/*! PCAC_IE - Completer abort interrupt enable. */
#define HSIO_BLK_CTRL_GPR_REG5_PCAC_IE(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_PCAC_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_PCAC_IE_MASK)

#define HSIO_BLK_CTRL_GPR_REG5_PCT_IE_MASK       (0x80U)
#define HSIO_BLK_CTRL_GPR_REG5_PCT_IE_SHIFT      (7U)
/*! PCT_IE - completion timeout interrupt enable */
#define HSIO_BLK_CTRL_GPR_REG5_PCT_IE(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG5_PCT_IE_SHIFT)) & HSIO_BLK_CTRL_GPR_REG5_PCT_IE_MASK)
/*! @} */

/*! @name GPR_REG6 - PCIE PME message and error detect interrupt detect disable register */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG6_LUD_DIS_MASK      (0x1U)
#define HSIO_BLK_CTRL_GPR_REG6_LUD_DIS_SHIFT     (0U)
/*! LUD_DIS - Link up detect disable */
#define HSIO_BLK_CTRL_GPR_REG6_LUD_DIS(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_LUD_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_LUD_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_LDD_DIS_MASK      (0x2U)
#define HSIO_BLK_CTRL_GPR_REG6_LDD_DIS_SHIFT     (1U)
/*! LDD_DIS - Link down detect disable */
#define HSIO_BLK_CTRL_GPR_REG6_LDD_DIS(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_LDD_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_LDD_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_HRD_DIS_MASK      (0x4U)
#define HSIO_BLK_CTRL_GPR_REG6_HRD_DIS_SHIFT     (2U)
/*! HRD_DIS - Hot reset detect disable */
#define HSIO_BLK_CTRL_GPR_REG6_HRD_DIS(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_HRD_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_HRD_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_PTO_DIS_MASK      (0x8U)
#define HSIO_BLK_CTRL_GPR_REG6_PTO_DIS_SHIFT     (3U)
/*! PTO_DIS - PME turn off detect disabled. */
#define HSIO_BLK_CTRL_GPR_REG6_PTO_DIS(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_PTO_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_PTO_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_UREP_DIS_MASK     (0x10U)
#define HSIO_BLK_CTRL_GPR_REG6_UREP_DIS_SHIFT    (4U)
/*! UREP_DIS - Unsupported request in EP mode detection disable */
#define HSIO_BLK_CTRL_GPR_REG6_UREP_DIS(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_UREP_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_UREP_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_CDNSC_DIS_MASK    (0x20U)
#define HSIO_BLK_CTRL_GPR_REG6_CDNSC_DIS_SHIFT   (5U)
/*! CDNSC_DIS - Completion with data not succsessful detection disable */
#define HSIO_BLK_CTRL_GPR_REG6_CDNSC_DIS(x)      (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_CDNSC_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_CDNSC_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_PCAC_DIS_MASK     (0x40U)
#define HSIO_BLK_CTRL_GPR_REG6_PCAC_DIS_SHIFT    (6U)
/*! PCAC_DIS - Completer abort detection disable. */
#define HSIO_BLK_CTRL_GPR_REG6_PCAC_DIS(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_PCAC_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_PCAC_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_PCT_DIS_MASK      (0x80U)
#define HSIO_BLK_CTRL_GPR_REG6_PCT_DIS_SHIFT     (7U)
/*! PCT_DIS - completion detection disable */
#define HSIO_BLK_CTRL_GPR_REG6_PCT_DIS(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_PCT_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_PCT_DIS_MASK)

#define HSIO_BLK_CTRL_GPR_REG6_ME_DIS_MASK       (0x100U)
#define HSIO_BLK_CTRL_GPR_REG6_ME_DIS_SHIFT      (8U)
/*! ME_DIS - Multiple errors of same type detection disable */
#define HSIO_BLK_CTRL_GPR_REG6_ME_DIS(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG6_ME_DIS_SHIFT)) & HSIO_BLK_CTRL_GPR_REG6_ME_DIS_MASK)
/*! @} */

/*! @name GPR_REG7 - USB1 beat limit and enable */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_MASK (0xFFFFU)
#define HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_SHIFT (0U)
/*! USB1_BEAT_LIMIT - USB1 beat limit number */
#define HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_SHIFT)) & HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_MASK)

#define HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_EN_MASK (0x10000U)
#define HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_EN_SHIFT (16U)
/*! USB1_BEAT_LIMIT_EN - USB1 beat limit enable */
#define HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_EN_SHIFT)) & HSIO_BLK_CTRL_GPR_REG7_USB1_BEAT_LIMIT_EN_MASK)
/*! @} */

/*! @name GPR_REG8 - USB2 beat limit and enable */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_MASK (0xFFFFU)
#define HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_SHIFT (0U)
/*! USB2_BEAT_LIMIT - USB2 beat limit number */
#define HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_SHIFT)) & HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_MASK)

#define HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_EN_MASK (0x10000U)
#define HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_EN_SHIFT (16U)
/*! USB2_BEAT_LIMIT_EN - USB2 beat limit enable */
#define HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_EN_SHIFT)) & HSIO_BLK_CTRL_GPR_REG8_USB2_BEAT_LIMIT_EN_MASK)
/*! @} */

/*! @name GPR_REG9 - PCIE beat limit and enable */
/*! @{ */

#define HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_MASK (0xFFFFU)
#define HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_SHIFT (0U)
/*! PCIE_BEAT_LIMIT - PCIE beat limit number */
#define HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_SHIFT)) & HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_MASK)

#define HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_EN_MASK (0x10000U)
#define HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_EN_SHIFT (16U)
/*! PCIE_BEAT_LIMIT_EN - PCIE beat limit enable */
#define HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_EN_SHIFT)) & HSIO_BLK_CTRL_GPR_REG9_PCIE_BEAT_LIMIT_EN_MASK)
/*! @} */

/*! @name USB1_WAKEUP_CTRL - Register for USB1 wakeup */
/*! @{ */

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_MASK (0x1U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_SHIFT (0U)
/*! OTG_WKDPDMCHG_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WKDPDMCHG_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_MASK (0x2U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_SHIFT (1U)
/*! OTG_VBUS_WAKE_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_WAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_MASK (0x4U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_SHIFT (2U)
/*! OTG_ID_WAKEUP_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_ID_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_U3_WAKE_EN_MASK (0x8U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_U3_WAKE_EN_SHIFT (3U)
/*! OTG_U3_WAKE_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_U3_WAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_U3_WAKE_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_U3_WAKE_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_MASK (0x10U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_SHIFT (4U)
/*! OTG_VBUS_SOURCE_SEL
 *  0b0..select vbus_valid
 *  0b1..select sessvld
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_MASK (0x20U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_SHIFT (5U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_EN_MASK (0x100U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_EN_SHIFT (8U)
/*! AUTORESUME_EN
 *  0b0..disable.
 *  0b1..enable.
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_DATADLY_MASK (0x200U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_DATADLY_SHIFT (9U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_DATADLY(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_DATADLY_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_DATADLY_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_ENDLY_MASK (0x400U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_ENDLY_SHIFT (10U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_ENDLY(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_ENDLY_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_AUTORESUME_ENDLY_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_LOWSPEED_EN_MASK (0x800U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_LOWSPEED_EN_SHIFT (11U)
/*! LOWSPEED_EN
 *  0b0..full/high speed
 *  0b1..lowspeed
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_LOWSPEED_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_LOWSPEED_EN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_LOWSPEED_EN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMDATA_MASK (0x1000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMDATA_SHIFT (12U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMDATA(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMDATA_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMDATA_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMEN_MASK (0x2000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMEN_SHIFT (13U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMEN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMEN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDMEN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPDATA_MASK (0x4000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPDATA_SHIFT (14U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPDATA(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPDATA_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPDATA_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPEN_MASK (0x8000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPEN_SHIFT (15U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPEN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPEN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSDPEN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSSEL_MASK (0x10000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSSEL_SHIFT (16U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSSEL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSSEL_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_PHY_BYPASSSEL_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WAKE_ENABLE_MASK (0x80000000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WAKE_ENABLE_SHIFT (31U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WAKE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WAKE_ENABLE_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_CTRL_OTG_WAKE_ENABLE_MASK)
/*! @} */

/*! @name USB1_WAKEUP_STATUS - Status of USB1 wakeup */
/*! @{ */

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_MASK (0x1U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_SHIFT (0U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_MASK (0x2U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_SHIFT (1U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_MASK (0x4U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_SHIFT (2U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_MASK (0x8U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_SHIFT (3U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_MASK (0x10U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_SHIFT (4U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_MASK (0x20U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_SHIFT (5U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_IDDIG0_MASK (0x40U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_IDDIG0_SHIFT (6U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_IDDIG0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_IDDIG0_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_IDDIG0_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_MASK (0x80U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_SHIFT (7U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_VBUSVALID0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_MASK (0x100U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_SHIFT (8U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE_RXELECIDLE_MASK (0x200U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE_RXELECIDLE_SHIFT (9U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE_RXELECIDLE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE_RXELECIDLE_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE_RXELECIDLE_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_HOST_MODE_MASK (0x400U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_HOST_MODE_SHIFT (10U)
/*! OTG_HOST_MODE
 *  0b0..device mode
 *  0b1..host mode
 */
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_HOST_MODE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_HOST_MODE_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_HOST_MODE_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE3_POWERDOWN_MASK (0x1800U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE3_POWERDOWN_SHIFT (11U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE3_POWERDOWN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE3_POWERDOWN_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_PIPE3_POWERDOWN_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_MASK (0x2000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_SHIFT (13U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_MASK (0x80000000U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_SHIFT (31U)
#define HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB1_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_MASK)
/*! @} */

/*! @name USB2_WAKEUP_CTRL - Register for USB2 wakeup */
/*! @{ */

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_MASK (0x1U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_SHIFT (0U)
/*! OTG_WKDPDMCHG_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WKDPDMCHG_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WKDPDMCHG_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_MASK (0x2U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_SHIFT (1U)
/*! OTG_VBUS_WAKE_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_WAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_WAKE_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_MASK (0x4U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_SHIFT (2U)
/*! OTG_ID_WAKEUP_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_ID_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_ID_WAKEUP_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_U3_WAKE_EN_MASK (0x8U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_U3_WAKE_EN_SHIFT (3U)
/*! OTG_U3_WAKE_EN
 *  0b0..disable
 *  0b1..enable
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_U3_WAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_U3_WAKE_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_U3_WAKE_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_MASK (0x10U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_SHIFT (4U)
/*! OTG_VBUS_SOURCE_SEL
 *  0b0..select vbus_valid
 *  0b1..select sessvld
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_VBUS_SOURCE_SEL_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_MASK (0x20U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_SHIFT (5U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_CONN_WAKEUP_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_EN_MASK (0x100U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_EN_SHIFT (8U)
/*! AUTORESUME_EN
 *  0b0..disable.
 *  0b1..enable.
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_DATADLY_MASK (0x200U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_DATADLY_SHIFT (9U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_DATADLY(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_DATADLY_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_DATADLY_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_ENDLY_MASK (0x400U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_ENDLY_SHIFT (10U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_ENDLY(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_ENDLY_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_AUTORESUME_ENDLY_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_LOWSPEED_EN_MASK (0x800U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_LOWSPEED_EN_SHIFT (11U)
/*! LOWSPEED_EN
 *  0b0..full/high speed
 *  0b1..lowspeed
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_LOWSPEED_EN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_LOWSPEED_EN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_LOWSPEED_EN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMDATA_MASK (0x1000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMDATA_SHIFT (12U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMDATA(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMDATA_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMDATA_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMEN_MASK (0x2000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMEN_SHIFT (13U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMEN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMEN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDMEN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPDATA_MASK (0x4000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPDATA_SHIFT (14U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPDATA(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPDATA_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPDATA_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPEN_MASK (0x8000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPEN_SHIFT (15U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPEN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPEN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSDPEN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSSEL_MASK (0x10000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSSEL_SHIFT (16U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSSEL(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSSEL_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_PHY_BYPASSSEL_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WAKE_ENABLE_MASK (0x80000000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WAKE_ENABLE_SHIFT (31U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WAKE_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WAKE_ENABLE_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_CTRL_OTG_WAKE_ENABLE_MASK)
/*! @} */

/*! @name USB2_WAKEUP_STATUS - Status of USB2 wakeup */
/*! @{ */

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_MASK (0x1U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_SHIFT (0U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_DP_DM_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_MASK (0x2U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_SHIFT (1U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_VBUS_SESSVLD_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_MASK (0x4U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_SHIFT (2U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_ID_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_MASK (0x8U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_SHIFT (3U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_U3_WAKEUP_INTERRUP_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_MASK (0x10U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_SHIFT (4U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_0_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_MASK (0x20U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_SHIFT (5U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_LINESTATE0_1_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_IDDIG0_MASK (0x40U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_IDDIG0_SHIFT (6U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_IDDIG0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_IDDIG0_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_IDDIG0_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_MASK (0x80U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_SHIFT (7U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_VBUSVALID0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_VBUSVALID0_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_MASK (0x100U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_SHIFT (8U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_PHY_OTGSESSVLD0_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE_RXELECIDLE_MASK (0x200U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE_RXELECIDLE_SHIFT (9U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE_RXELECIDLE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE_RXELECIDLE_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE_RXELECIDLE_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_HOST_MODE_MASK (0x400U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_HOST_MODE_SHIFT (10U)
/*! OTG_HOST_MODE
 *  0b0..device mode
 *  0b1..host mode
 */
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_HOST_MODE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_HOST_MODE_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_HOST_MODE_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE3_POWERDOWN_MASK (0x1800U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE3_POWERDOWN_SHIFT (11U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE3_POWERDOWN(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE3_POWERDOWN_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_PIPE3_POWERDOWN_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_MASK (0x2000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_SHIFT (13U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_CONN_WAKEUP_INTERRUPT_MASK)

#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_MASK (0x80000000U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_SHIFT (31U)
#define HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT(x) (((uint32_t)(((uint32_t)(x)) << HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_SHIFT)) & HSIO_BLK_CTRL_USB2_WAKEUP_STATUS_OTG_WAKEUP_INTERRUPT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HSIO_BLK_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group HSIO_BLK_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_HSIO_BLK_CTRL_H_ */

