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
**         CMSIS Peripheral Access Layer for GLUE_USB
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
 * @file PERI_GLUE_USB.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GLUE_USB
 *
 * CMSIS Peripheral Access Layer for GLUE_USB
 */

#if !defined(PERI_GLUE_USB_H_)
#define PERI_GLUE_USB_H_                         /**< Symbol preventing repeated inclusion */

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
   -- GLUE_USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GLUE_USB_Peripheral_Access_Layer GLUE_USB Peripheral Access Layer
 * @{
 */

/** GLUE_USB - Register Layout Typedef */
typedef struct {
  __IO uint32_t USB_CTL0_ADDR;                     /**< USB_CTL0_ADDR, offset: 0x0 */
  __IO uint32_t USB_CTL1_ADDR;                     /**< USB_CTL1_ADDR, offset: 0x4 */
       uint8_t RESERVED_0[24];
  __I  uint32_t USB_STS0_ADDR;                     /**< USB_STS0_ADDR, offset: 0x20 */
       uint8_t RESERVED_1[28];
  __IO uint32_t PHY_CTL0_ADDR;                     /**< PHY_CTL0_ADDR, offset: 0x40 */
  __IO uint32_t PHY_CTL1_ADDR;                     /**< PHY_CTL1_ADDR, offset: 0x44 */
  __IO uint32_t PHY_CTL2_ADDR;                     /**< PHY_CTL2_ADDR, offset: 0x48 */
  __IO uint32_t PHY_CTL3_ADDR;                     /**< PHY_CTL3_ADDR, offset: 0x4C */
  __IO uint32_t PHY_CTL4_ADDR;                     /**< PHY_CTL4_ADDR, offset: 0x50 */
  __IO uint32_t PHY_CTL5_ADDR;                     /**< PHY_CTL5_ADDR, offset: 0x54 */
  __IO uint32_t PHY_CTL6_ADDR;                     /**< PHY_CTL6_ADDR, offset: 0x58 */
       uint8_t RESERVED_2[36];
  __IO uint32_t PHY_STS0_ADDR;                     /**< PHY_STS0_ADDR, offset: 0x80 */
} GLUE_USB_Type;

/* ----------------------------------------------------------------------------
   -- GLUE_USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GLUE_USB_Register_Masks GLUE_USB Register Masks
 * @{
 */

/*! @name USB_CTL0_ADDR - USB_CTL0_ADDR */
/*! @{ */

#define GLUE_USB_USB_CTL0_ADDR_HOST_U2_PORT_DISABLE_MASK (0x40U)
#define GLUE_USB_USB_CTL0_ADDR_HOST_U2_PORT_DISABLE_SHIFT (6U)
/*! host_u2_port_disable - USB 2.0 Port Disable control.
 *  0b0..Port Enabled
 *  0b1..Port Disabled. When '1', this signal stops reporting connect/disconnect events the port and keeps the port in disabled state.
 */
#define GLUE_USB_USB_CTL0_ADDR_HOST_U2_PORT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_HOST_U2_PORT_DISABLE_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_HOST_U2_PORT_DISABLE_MASK)

#define GLUE_USB_USB_CTL0_ADDR_HOST_U3_PORT_DISABLE_MASK (0x80U)
#define GLUE_USB_USB_CTL0_ADDR_HOST_U3_PORT_DISABLE_SHIFT (7U)
/*! host_u3_port_disable - USB 3.0 SS Port Disable control.
 *  0b0..Port Enabled
 *  0b1..Port Disabled
 */
#define GLUE_USB_USB_CTL0_ADDR_HOST_U3_PORT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_HOST_U3_PORT_DISABLE_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_HOST_U3_PORT_DISABLE_MASK)

#define GLUE_USB_USB_CTL0_ADDR_BUS_FILTER_BYPASS_MASK (0xF00U)
#define GLUE_USB_USB_CTL0_ADDR_BUS_FILTER_BYPASS_SHIFT (8U)
/*! bus_filter_bypass - Bus Filter Bypass. */
#define GLUE_USB_USB_CTL0_ADDR_BUS_FILTER_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_BUS_FILTER_BYPASS_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_BUS_FILTER_BYPASS_MASK)

#define GLUE_USB_USB_CTL0_ADDR_HOST_PORT_POWER_CONTROL_PRESENT_MASK (0x1000U)
#define GLUE_USB_USB_CTL0_ADDR_HOST_PORT_POWER_CONTROL_PRESENT_SHIFT (12U)
/*! host_port_power_control_present - This port defines the bit [3] of Capability Parameters (HCCPARAMS).
 *  0b0..Indicates that the port does not have port power switches.
 *  0b1..Indicates that the port has port power switches.
 */
#define GLUE_USB_USB_CTL0_ADDR_HOST_PORT_POWER_CONTROL_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_HOST_PORT_POWER_CONTROL_PRESENT_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_HOST_PORT_POWER_CONTROL_PRESENT_MASK)

#define GLUE_USB_USB_CTL0_ADDR_XHC_BME_MASK      (0x4000U)
#define GLUE_USB_USB_CTL0_ADDR_XHC_BME_SHIFT     (14U)
/*! xhc_bme - Disable the bus mastering capability of the xHC
 *  0b0..Bus mastering capability is disabled. The host controller cannot use the bus master interface.
 *  0b1..Bus mastering capability is enabled.
 */
#define GLUE_USB_USB_CTL0_ADDR_XHC_BME(x)        (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_XHC_BME_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_XHC_BME_MASK)

#define GLUE_USB_USB_CTL0_ADDR_FLADJ_30MHZ_REG_MASK (0x3F0000U)
#define GLUE_USB_USB_CTL0_ADDR_FLADJ_30MHZ_REG_SHIFT (16U)
/*! fladj_30mhz_reg - HS Jitter Adjustment. */
#define GLUE_USB_USB_CTL0_ADDR_FLADJ_30MHZ_REG(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_FLADJ_30MHZ_REG_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_FLADJ_30MHZ_REG_MASK)

#define GLUE_USB_USB_CTL0_ADDR_HUB_PORT_PERM_ATTACH_MASK (0xC00000U)
#define GLUE_USB_USB_CTL0_ADDR_HUB_PORT_PERM_ATTACH_SHIFT (22U)
/*! hub_port_perm_attach - Indicates if the device attached to a downstream port is permanently attached or not.
 *  0b00..Not permanently attached
 *  0b01..Permanently attached
 */
#define GLUE_USB_USB_CTL0_ADDR_HUB_PORT_PERM_ATTACH(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_HUB_PORT_PERM_ATTACH_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_HUB_PORT_PERM_ATTACH_MASK)

#define GLUE_USB_USB_CTL0_ADDR_UTMI_IDDIG_SEL_MASK (0x1000000U)
#define GLUE_USB_USB_CTL0_ADDR_UTMI_IDDIG_SEL_SHIFT (24U)
/*! utmi_iddig_sel - iddig source select signal
 *  0b0..USB PHY ID0
 *  0b1..GPIO PAD
 */
#define GLUE_USB_USB_CTL0_ADDR_UTMI_IDDIG_SEL(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_UTMI_IDDIG_SEL_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_UTMI_IDDIG_SEL_MASK)

#define GLUE_USB_USB_CTL0_ADDR_STARTRXDETU3RXDET_MASK (0x2000000U)
#define GLUE_USB_USB_CTL0_ADDR_STARTRXDETU3RXDET_SHIFT (25U)
/*! StartRxDetU3RxDet - StartRxdetU3RxDet of USB 3.0 SS Ports */
#define GLUE_USB_USB_CTL0_ADDR_STARTRXDETU3RXDET(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_STARTRXDETU3RXDET_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_STARTRXDETU3RXDET_MASK)

#define GLUE_USB_USB_CTL0_ADDR_DISRXDETU3RXDET_MASK (0x4000000U)
#define GLUE_USB_USB_CTL0_ADDR_DISRXDETU3RXDET_SHIFT (26U)
/*! DisRxDetU3RxDet - DisRxDetU3RxDet of USB 3.0 SS Ports */
#define GLUE_USB_USB_CTL0_ADDR_DISRXDETU3RXDET(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL0_ADDR_DISRXDETU3RXDET_SHIFT)) & GLUE_USB_USB_CTL0_ADDR_DISRXDETU3RXDET_MASK)
/*! @} */

/*! @name USB_CTL1_ADDR - USB_CTL1_ADDR */
/*! @{ */

#define GLUE_USB_USB_CTL1_ADDR_OC_POLARITY_MASK  (0x10000U)
#define GLUE_USB_USB_CTL1_ADDR_OC_POLARITY_SHIFT (16U)
/*! oc_polarity - Overcurrent polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define GLUE_USB_USB_CTL1_ADDR_OC_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL1_ADDR_OC_POLARITY_SHIFT)) & GLUE_USB_USB_CTL1_ADDR_OC_POLARITY_MASK)

#define GLUE_USB_USB_CTL1_ADDR_POWER_POLARITY_MASK (0x20000U)
#define GLUE_USB_USB_CTL1_ADDR_POWER_POLARITY_SHIFT (17U)
/*! power_polarity - Power polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define GLUE_USB_USB_CTL1_ADDR_POWER_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_CTL1_ADDR_POWER_POLARITY_SHIFT)) & GLUE_USB_USB_CTL1_ADDR_POWER_POLARITY_MASK)
/*! @} */

/*! @name USB_STS0_ADDR - USB_STS0_ADDR */
/*! @{ */

#define GLUE_USB_USB_STS0_ADDR_HOST_CURRENT_BELT_MASK (0xFFFU)
#define GLUE_USB_USB_STS0_ADDR_HOST_CURRENT_BELT_SHIFT (0U)
/*! host_current_belt - Current BELT Value */
#define GLUE_USB_USB_STS0_ADDR_HOST_CURRENT_BELT(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_STS0_ADDR_HOST_CURRENT_BELT_SHIFT)) & GLUE_USB_USB_STS0_ADDR_HOST_CURRENT_BELT_MASK)

#define GLUE_USB_USB_STS0_ADDR_HOST_SYSTEM_ERR_MASK (0x1000U)
#define GLUE_USB_USB_STS0_ADDR_HOST_SYSTEM_ERR_SHIFT (12U)
/*! host_system_err - Host System Error */
#define GLUE_USB_USB_STS0_ADDR_HOST_SYSTEM_ERR(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_STS0_ADDR_HOST_SYSTEM_ERR_SHIFT)) & GLUE_USB_USB_STS0_ADDR_HOST_SYSTEM_ERR_MASK)

#define GLUE_USB_USB_STS0_ADDR_BC_CHIRP_ON_MASK  (0x2000U)
#define GLUE_USB_USB_STS0_ADDR_BC_CHIRP_ON_SHIFT (13U)
/*! bc_chirp_on - When asserted indicates an imminent chirp signal. */
#define GLUE_USB_USB_STS0_ADDR_BC_CHIRP_ON(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_STS0_ADDR_BC_CHIRP_ON_SHIFT)) & GLUE_USB_USB_STS0_ADDR_BC_CHIRP_ON_MASK)

#define GLUE_USB_USB_STS0_ADDR_PME_GENERATION_MASK (0x4000U)
#define GLUE_USB_USB_STS0_ADDR_PME_GENERATION_SHIFT (14U)
/*! pme_generation - PME# Generation. */
#define GLUE_USB_USB_STS0_ADDR_PME_GENERATION(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_STS0_ADDR_PME_GENERATION_SHIFT)) & GLUE_USB_USB_STS0_ADDR_PME_GENERATION_MASK)

#define GLUE_USB_USB_STS0_ADDR_IDDIG_MASK        (0x8000U)
#define GLUE_USB_USB_STS0_ADDR_IDDIG_SHIFT       (15U)
/*! IDDIG - This controller signal indicates whether the connected plug is a mini-A or mini-B plug.
 *  0b0..Connected plug is a mini-A plug.
 *  0b1..Connected plug is a mini-B plug.
 */
#define GLUE_USB_USB_STS0_ADDR_IDDIG(x)          (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_STS0_ADDR_IDDIG_SHIFT)) & GLUE_USB_USB_STS0_ADDR_IDDIG_MASK)

#define GLUE_USB_USB_STS0_ADDR_DISRXDETU3RXDET_ACK_MASK (0x10000U)
#define GLUE_USB_USB_STS0_ADDR_DISRXDETU3RXDET_ACK_SHIFT (16U)
/*! DisRxDetU3RxDet_ack - DisRxDetU3RxDet_ack of USB 3.0 SS Ports */
#define GLUE_USB_USB_STS0_ADDR_DISRXDETU3RXDET_ACK(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_USB_STS0_ADDR_DISRXDETU3RXDET_ACK_SHIFT)) & GLUE_USB_USB_STS0_ADDR_DISRXDETU3RXDET_ACK_MASK)
/*! @} */

/*! @name PHY_CTL0_ADDR - PHY_CTL0_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL0_ADDR_REF_SSP_EN_MASK   (0x4U)
#define GLUE_USB_PHY_CTL0_ADDR_REF_SSP_EN_SHIFT  (2U)
/*! ref_ssp_en - Reference Clock Enable for SS function. */
#define GLUE_USB_PHY_CTL0_ADDR_REF_SSP_EN(x)     (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL0_ADDR_REF_SSP_EN_SHIFT)) & GLUE_USB_PHY_CTL0_ADDR_REF_SSP_EN_MASK)

#define GLUE_USB_PHY_CTL0_ADDR_FSEL_MASK         (0x7E0U)
#define GLUE_USB_PHY_CTL0_ADDR_FSEL_SHIFT        (5U)
/*! fsel - fsel
 *  0b100111..100MHz ref clock
 *  0b101010..24MHz ref clock
 */
#define GLUE_USB_PHY_CTL0_ADDR_FSEL(x)           (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL0_ADDR_FSEL_SHIFT)) & GLUE_USB_PHY_CTL0_ADDR_FSEL_MASK)

#define GLUE_USB_PHY_CTL0_ADDR_SSC_EN_MASK       (0x800U)
#define GLUE_USB_PHY_CTL0_ADDR_SSC_EN_SHIFT      (11U)
/*! ssc_en - Spread Spectrum Enable */
#define GLUE_USB_PHY_CTL0_ADDR_SSC_EN(x)         (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL0_ADDR_SSC_EN_SHIFT)) & GLUE_USB_PHY_CTL0_ADDR_SSC_EN_MASK)

#define GLUE_USB_PHY_CTL0_ADDR_SSC_REF_CLK_SEL_MASK (0x1FF000U)
#define GLUE_USB_PHY_CTL0_ADDR_SSC_REF_CLK_SEL_SHIFT (12U)
/*! ssc_ref_clk_sel - Spread Spectrum Reference Clock Shifting */
#define GLUE_USB_PHY_CTL0_ADDR_SSC_REF_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL0_ADDR_SSC_REF_CLK_SEL_SHIFT)) & GLUE_USB_PHY_CTL0_ADDR_SSC_REF_CLK_SEL_MASK)

#define GLUE_USB_PHY_CTL0_ADDR_SSC_RANGE_MASK    (0xE00000U)
#define GLUE_USB_PHY_CTL0_ADDR_SSC_RANGE_SHIFT   (21U)
/*! ssc_range - Spread Spectrum Clock Range
 *  0b000..4980
 *  0b001..4492
 *  0b010..4003
 */
#define GLUE_USB_PHY_CTL0_ADDR_SSC_RANGE(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL0_ADDR_SSC_RANGE_SHIFT)) & GLUE_USB_PHY_CTL0_ADDR_SSC_RANGE_MASK)
/*! @} */

/*! @name PHY_CTL1_ADDR - PHY_CTL1_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL1_ADDR_PHY_RESET_MASK    (0x1U)
#define GLUE_USB_PHY_CTL1_ADDR_PHY_RESET_SHIFT   (0U)
/*! phy_reset - USB3.0 PHY Signal */
#define GLUE_USB_PHY_CTL1_ADDR_PHY_RESET(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_PHY_RESET_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_PHY_RESET_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_COMMONONN_MASK    (0x2U)
#define GLUE_USB_PHY_CTL1_ADDR_COMMONONN_SHIFT   (1U)
/*! COMMONONN - Common Block Power-Down Control */
#define GLUE_USB_PHY_CTL1_ADDR_COMMONONN(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_COMMONONN_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_COMMONONN_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_RTUNE_REQ_MASK    (0x8000U)
#define GLUE_USB_PHY_CTL1_ADDR_RTUNE_REQ_SHIFT   (15U)
/*! rtune_req - Resistor Tune Request */
#define GLUE_USB_PHY_CTL1_ADDR_RTUNE_REQ(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_RTUNE_REQ_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_RTUNE_REQ_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_ACAENB0_MASK      (0x10000U)
#define GLUE_USB_PHY_CTL1_ADDR_ACAENB0_SHIFT     (16U)
/*! ACAENB0 - Battery Charging Source Select */
#define GLUE_USB_PHY_CTL1_ADDR_ACAENB0(x)        (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_ACAENB0_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_ACAENB0_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_DCDENB0_MASK      (0x20000U)
#define GLUE_USB_PHY_CTL1_ADDR_DCDENB0_SHIFT     (17U)
/*! DCDENB0 - Data Contact Detection Enable */
#define GLUE_USB_PHY_CTL1_ADDR_DCDENB0(x)        (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_DCDENB0_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_DCDENB0_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_CHRGSEL0_MASK     (0x40000U)
#define GLUE_USB_PHY_CTL1_ADDR_CHRGSEL0_SHIFT    (18U)
/*! CHRGSEL0 - Battery Charging Source Select */
#define GLUE_USB_PHY_CTL1_ADDR_CHRGSEL0(x)       (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_CHRGSEL0_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_CHRGSEL0_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_VDATSRCENB0_MASK  (0x80000U)
#define GLUE_USB_PHY_CTL1_ADDR_VDATSRCENB0_SHIFT (19U)
/*! VDATSRCENB0 - Battery Charging Sourcing Select */
#define GLUE_USB_PHY_CTL1_ADDR_VDATSRCENB0(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_VDATSRCENB0_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_VDATSRCENB0_MASK)

#define GLUE_USB_PHY_CTL1_ADDR_VDATDETENB0_MASK  (0x100000U)
#define GLUE_USB_PHY_CTL1_ADDR_VDATDETENB0_SHIFT (20U)
/*! VDATDETENB0 - Battery Charging Attach/Connect Detection Enable */
#define GLUE_USB_PHY_CTL1_ADDR_VDATDETENB0(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL1_ADDR_VDATDETENB0_SHIFT)) & GLUE_USB_PHY_CTL1_ADDR_VDATDETENB0_MASK)
/*! @} */

/*! @name PHY_CTL2_ADDR - PHY_CTL2_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL2_ADDR_FSDATAEXT0_MASK   (0x20U)
#define GLUE_USB_PHY_CTL2_ADDR_FSDATAEXT0_SHIFT  (5U)
/*! FSDATAEXT0 - USB 1.1 SE0 Generation */
#define GLUE_USB_PHY_CTL2_ADDR_FSDATAEXT0(x)     (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_FSDATAEXT0_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_FSDATAEXT0_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_FSSE0EXT0_MASK    (0x40U)
#define GLUE_USB_PHY_CTL2_ADDR_FSSE0EXT0_SHIFT   (6U)
/*! FSSE0EXT0 - USB 1.1 Transmit Data */
#define GLUE_USB_PHY_CTL2_ADDR_FSSE0EXT0(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_FSSE0EXT0_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_FSSE0EXT0_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_FSXCVROWNER0_MASK (0x80U)
#define GLUE_USB_PHY_CTL2_ADDR_FSXCVROWNER0_SHIFT (7U)
/*! FSXCVROWNER0 - UTMI+/Serial Interface Select */
#define GLUE_USB_PHY_CTL2_ADDR_FSXCVROWNER0(x)   (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_FSXCVROWNER0_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_FSXCVROWNER0_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_TXENABLEN0_MASK   (0x100U)
#define GLUE_USB_PHY_CTL2_ADDR_TXENABLEN0_SHIFT  (8U)
/*! TXENABLEN0 - USB 1.1 Data Enable */
#define GLUE_USB_PHY_CTL2_ADDR_TXENABLEN0(x)     (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_TXENABLEN0_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_TXENABLEN0_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXT0_MASK  (0x400U)
#define GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXT0_SHIFT (10U)
/*! VBUSVLDEXT0 - External VBUS Valid Indicator */
#define GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXT0(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXT0_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXT0_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXTSEL0_MASK (0x800U)
#define GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXTSEL0_SHIFT (11U)
/*! VBUSVLDEXTSEL0 - Selects the VBUSVLDEXTn input or the internal Session Valid comparator to
 *    indicate when the VBUSn signal on the USB cable is valid.
 */
#define GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXTSEL0(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXTSEL0_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_VBUSVLDEXTSEL0_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_UTMI_IDPULLUP_MASK (0x4000U)
#define GLUE_USB_PHY_CTL2_ADDR_UTMI_IDPULLUP_SHIFT (14U)
/*! utmi_idpullup - Analog ID Input Sample Enable */
#define GLUE_USB_PHY_CTL2_ADDR_UTMI_IDPULLUP(x)  (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_UTMI_IDPULLUP_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_UTMI_IDPULLUP_MASK)

#define GLUE_USB_PHY_CTL2_ADDR_RX0LOSLFPSEN_MASK (0x10000U)
#define GLUE_USB_PHY_CTL2_ADDR_RX0LOSLFPSEN_SHIFT (16U)
/*! rx0loslfpsen - RX LOS LFPS Filter Enable */
#define GLUE_USB_PHY_CTL2_ADDR_RX0LOSLFPSEN(x)   (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL2_ADDR_RX0LOSLFPSEN_SHIFT)) & GLUE_USB_PHY_CTL2_ADDR_RX0LOSLFPSEN_MASK)
/*! @} */

/*! @name PHY_CTL3_ADDR - PHY_CTL3_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL3_ADDR_COMPIDISTUNE_MASK (0x7U)
#define GLUE_USB_PHY_CTL3_ADDR_COMPIDISTUNE_SHIFT (0U)
/*! COMPIDISTUNE - Disconnect Threshold Adjustment.
 *  0b000..- 9.01%
 *  0b001..- 6.5%
 *  0b010..- 3.04%
 *  0b011..0 (default)
 *  0b100..+ 4.08
 *  0b101..+ 7.52%
 *  0b110..+ 11.86%
 *  0b111..+ 15.54%
 */
#define GLUE_USB_PHY_CTL3_ADDR_COMPIDISTUNE(x)   (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_COMPIDISTUNE_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_COMPIDISTUNE_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TUNE0_MASK        (0x38U)
#define GLUE_USB_PHY_CTL3_ADDR_TUNE0_SHIFT       (3U)
/*! TUNE0 - VBUS Valid Threshold Adjustment */
#define GLUE_USB_PHY_CTL3_ADDR_TUNE0(x)          (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_SQRXTUNE0_MASK    (0x1C0U)
#define GLUE_USB_PHY_CTL3_ADDR_SQRXTUNE0_SHIFT   (6U)
/*! SQRXTUNE0 - Squelch Threshold Adjustment
 *  0b000..+ 16.07%
 *  0b001..+ 10.71%
 *  0b010..+ 5.36%
 *  0b011..0 (default)
 *  0b100..- 5.36%
 *  0b101..- 10.71%
 *  0b110..- 16.07%
 *  0b111..- 22.32%
 */
#define GLUE_USB_PHY_CTL3_ADDR_SQRXTUNE0(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_SQRXTUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_SQRXTUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXFSLSTUNE0_MASK  (0x1E00U)
#define GLUE_USB_PHY_CTL3_ADDR_TXFSLSTUNE0_SHIFT (9U)
/*! TXFSLSTUNE0 - FS/LS Source Impedance Adjustment
 *  0b0000..+ 3.5%
 *  0b0001..+ 1.8%
 *  0b0011..0 (default)
 *  0b0111..- 1.7%
 *  0b1111..- 3.5%
 */
#define GLUE_USB_PHY_CTL3_ADDR_TXFSLSTUNE0(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXFSLSTUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXFSLSTUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXSHXSTUNE0_MASK  (0x6000U)
#define GLUE_USB_PHY_CTL3_ADDR_TXSHXSTUNE0_SHIFT (13U)
/*! TXSHXSTUNE0 - Transmitter High-Speed Crossover Adjustment.
 *  0b00..Reserved
 *  0b01..- 16 mV
 *  0b10..+ 14 mV
 *  0b11..0 (default)
 */
#define GLUE_USB_PHY_CTL3_ADDR_TXSHXSTUNE0(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXSHXSTUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXSHXSTUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXPREEMPMPTUNE0_MASK (0x18000U)
#define GLUE_USB_PHY_CTL3_ADDR_TXPREEMPMPTUNE0_SHIFT (15U)
/*! TXPREEMPMPTUNE0 - HS Transmitter Pre-Emphasis Current Control
 *  0b00..Disabled (default)
 *  0b01..1x pre-emphasis current
 *  0b10..2x pre-emphasis current
 *  0b11..3x pre-emphasis current
 */
#define GLUE_USB_PHY_CTL3_ADDR_TXPREEMPMPTUNE0(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXPREEMPMPTUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXPREEMPMPTUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXPREEMPULSETUNE0_MASK (0x20000U)
#define GLUE_USB_PHY_CTL3_ADDR_TXPREEMPULSETUNE0_SHIFT (17U)
#define GLUE_USB_PHY_CTL3_ADDR_TXPREEMPULSETUNE0(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXPREEMPULSETUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXPREEMPULSETUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXRESTUNE0_MASK   (0xC0000U)
#define GLUE_USB_PHY_CTL3_ADDR_TXRESTUNE0_SHIFT  (18U)
#define GLUE_USB_PHY_CTL3_ADDR_TXRESTUNE0(x)     (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXRESTUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXRESTUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXRISETUNE0_MASK  (0x300000U)
#define GLUE_USB_PHY_CTL3_ADDR_TXRISETUNE0_SHIFT (20U)
/*! TXRISETUNE0 - HS Transmitter Rise/Fall Time Adjustment
 *  0b00..+ 3%
 *  0b01..0 (default)
 *  0b10..- 1%
 *  0b11..- 3%
 */
#define GLUE_USB_PHY_CTL3_ADDR_TXRISETUNE0(x)    (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXRISETUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXRISETUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TXREFTUNE0_MASK   (0x3C00000U)
#define GLUE_USB_PHY_CTL3_ADDR_TXREFTUNE0_SHIFT  (22U)
/*! TXREFTUNE0 - HS DC Voltage Level Adjustment
 *  0b0000..- 6%
 *  0b0001..- 4%
 *  0b0010..- 2%
 *  0b0011..0 (default)
 *  0b0100..+ 2%
 *  0b0101..+ 4%
 *  0b0110..+ 6%
 *  0b0111..+ 8%
 *  0b1000..+ 10
 *  0b1001..+ 12%
 *  0b1010..+ 14%
 *  0b1011..+ 16%
 *  0b1100..+ 18%
 *  0b1101..+ 20%
 *  0b1110..+ 22%
 *  0b1111..+ 24%
 */
#define GLUE_USB_PHY_CTL3_ADDR_TXREFTUNE0(x)     (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TXREFTUNE0_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TXREFTUNE0_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_IOS_BIAS_MASK     (0x1C000000U)
#define GLUE_USB_PHY_CTL3_ADDR_IOS_BIAS_SHIFT    (26U)
/*! ios_bias - Loss-of-Signal Detector Threshold Level Control */
#define GLUE_USB_PHY_CTL3_ADDR_IOS_BIAS(x)       (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_IOS_BIAS_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_IOS_BIAS_MASK)

#define GLUE_USB_PHY_CTL3_ADDR_TX_VBOOST_LVL_MASK (0xE0000000U)
#define GLUE_USB_PHY_CTL3_ADDR_TX_VBOOST_LVL_SHIFT (29U)
/*! tx_vboost_lvl - TX Voltage Boost Level */
#define GLUE_USB_PHY_CTL3_ADDR_TX_VBOOST_LVL(x)  (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL3_ADDR_TX_VBOOST_LVL_SHIFT)) & GLUE_USB_PHY_CTL3_ADDR_TX_VBOOST_LVL_MASK)
/*! @} */

/*! @name PHY_CTL4_ADDR - PHY_CTL4_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL4_ADDR_PCS_RX_LOS_MSK_VAL_MASK (0x7FE0U)
#define GLUE_USB_PHY_CTL4_ADDR_PCS_RX_LOS_MSK_VAL_SHIFT (5U)
/*! pcs_rx_los_msk_val - Configurable Loss-of-Signal Mask Width */
#define GLUE_USB_PHY_CTL4_ADDR_PCS_RX_LOS_MSK_VAL(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL4_ADDR_PCS_RX_LOS_MSK_VAL_SHIFT)) & GLUE_USB_PHY_CTL4_ADDR_PCS_RX_LOS_MSK_VAL_MASK)

#define GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_3B5DB_MASK (0x1F8000U)
#define GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_3B5DB_SHIFT (15U)
/*! pcs_tx_deemph_3b5db - TX De-Emphasis at 3.5 dB */
#define GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_3B5DB(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_3B5DB_SHIFT)) & GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_3B5DB_MASK)

#define GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_6DB_MASK (0x7E00000U)
#define GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_6DB_SHIFT (21U)
/*! pcs_tx_deemph_6db - TX De-Emphasis at 6 dB */
#define GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_6DB(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_6DB_SHIFT)) & GLUE_USB_PHY_CTL4_ADDR_PCS_TX_DEEMPH_6DB_MASK)
/*! @} */

/*! @name PHY_CTL5_ADDR - PHY_CTL5_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL5_ADDR_PCS_TX_SWING_FULL_MASK (0x7FU)
#define GLUE_USB_PHY_CTL5_ADDR_PCS_TX_SWING_FULL_SHIFT (0U)
/*! pcs_tx_swing_full - TX Amplitude (Full Swing Mode) */
#define GLUE_USB_PHY_CTL5_ADDR_PCS_TX_SWING_FULL(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL5_ADDR_PCS_TX_SWING_FULL_SHIFT)) & GLUE_USB_PHY_CTL5_ADDR_PCS_TX_SWING_FULL_MASK)
/*! @} */

/*! @name PHY_CTL6_ADDR - PHY_CTL6_ADDR */
/*! @{ */

#define GLUE_USB_PHY_CTL6_ADDR_LANE0_TX2RX_LOOPBK_MASK (0x4U)
#define GLUE_USB_PHY_CTL6_ADDR_LANE0_TX2RX_LOOPBK_SHIFT (2U)
/*! lane0_tx2rx_loopbk - Loopback */
#define GLUE_USB_PHY_CTL6_ADDR_LANE0_TX2RX_LOOPBK(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL6_ADDR_LANE0_TX2RX_LOOPBK_SHIFT)) & GLUE_USB_PHY_CTL6_ADDR_LANE0_TX2RX_LOOPBK_MASK)

#define GLUE_USB_PHY_CTL6_ADDR_LANE0_EXT_PCLK_REQ_MASK (0x8U)
#define GLUE_USB_PHY_CTL6_ADDR_LANE0_EXT_PCLK_REQ_SHIFT (3U)
/*! lane0_ext_pclk_req - External PIPE Clock Enable Request */
#define GLUE_USB_PHY_CTL6_ADDR_LANE0_EXT_PCLK_REQ(x) (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_CTL6_ADDR_LANE0_EXT_PCLK_REQ_SHIFT)) & GLUE_USB_PHY_CTL6_ADDR_LANE0_EXT_PCLK_REQ_MASK)
/*! @} */

/*! @name PHY_STS0_ADDR - PHY_STS0_ADDR */
/*! @{ */

#define GLUE_USB_PHY_STS0_ADDR_CHGDET0_MASK      (0x10U)
#define GLUE_USB_PHY_STS0_ADDR_CHGDET0_SHIFT     (4U)
/*! CHGDET0 - Battery Charger Detection Output */
#define GLUE_USB_PHY_STS0_ADDR_CHGDET0(x)        (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_STS0_ADDR_CHGDET0_SHIFT)) & GLUE_USB_PHY_STS0_ADDR_CHGDET0_MASK)

#define GLUE_USB_PHY_STS0_ADDR_RTUNE_ACK_MASK    (0x40U)
#define GLUE_USB_PHY_STS0_ADDR_RTUNE_ACK_SHIFT   (6U)
/*! rtune_ack - Resistor Tune Acknowledge. While asserted, indicates that a resistor tune is still in progress. */
#define GLUE_USB_PHY_STS0_ADDR_RTUNE_ACK(x)      (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_STS0_ADDR_RTUNE_ACK_SHIFT)) & GLUE_USB_PHY_STS0_ADDR_RTUNE_ACK_MASK)

#define GLUE_USB_PHY_STS0_ADDR_PIPE_CLK_VLD_MASK (0x40000000U)
#define GLUE_USB_PHY_STS0_ADDR_PIPE_CLK_VLD_SHIFT (30U)
/*! pipe_clk_vld - USB3.0 PHY Signal synchronised by USB bus clock.After PHY and core reset pipe clock is stable if this bit is set. */
#define GLUE_USB_PHY_STS0_ADDR_PIPE_CLK_VLD(x)   (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_STS0_ADDR_PIPE_CLK_VLD_SHIFT)) & GLUE_USB_PHY_STS0_ADDR_PIPE_CLK_VLD_MASK)

#define GLUE_USB_PHY_STS0_ADDR_UTMI_CLK_VLD_MASK (0x80000000U)
#define GLUE_USB_PHY_STS0_ADDR_UTMI_CLK_VLD_SHIFT (31U)
/*! utmi_clk_vld - USB3.0 PHY Signal synchronised by USB bus clock.After PHY and core reset pipe clock is stable if this bit is set. */
#define GLUE_USB_PHY_STS0_ADDR_UTMI_CLK_VLD(x)   (((uint32_t)(((uint32_t)(x)) << GLUE_USB_PHY_STS0_ADDR_UTMI_CLK_VLD_SHIFT)) & GLUE_USB_PHY_STS0_ADDR_UTMI_CLK_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GLUE_USB_Register_Masks */


/*!
 * @}
 */ /* end of group GLUE_USB_Peripheral_Access_Layer */


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


#endif  /* PERI_GLUE_USB_H_ */

