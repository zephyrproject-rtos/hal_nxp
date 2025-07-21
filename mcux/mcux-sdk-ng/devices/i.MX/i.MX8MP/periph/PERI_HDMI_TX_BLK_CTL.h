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
**         CMSIS Peripheral Access Layer for HDMI_TX_BLK_CTL
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
 * @file PERI_HDMI_TX_BLK_CTL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HDMI_TX_BLK_CTL
 *
 * CMSIS Peripheral Access Layer for HDMI_TX_BLK_CTL
 */

#if !defined(PERI_HDMI_TX_BLK_CTL_H_)
#define PERI_HDMI_TX_BLK_CTL_H_                  /**< Symbol preventing repeated inclusion */

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
   -- HDMI_TX_BLK_CTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDMI_TX_BLK_CTL_Peripheral_Access_Layer HDMI_TX_BLK_CTL Peripheral Access Layer
 * @{
 */

/** HDMI_TX_BLK_CTL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< HDMI_RTX_GENERAL CONFIG, offset: 0x0 */
    __IO uint32_t SET;                               /**< HDMI_RTX_GENERAL CONFIG, offset: 0x4 */
    __IO uint32_t CLR;                               /**< HDMI_RTX_GENERAL CONFIG, offset: 0x8 */
    __IO uint32_t TOG;                               /**< HDMI_RTX_GENERAL CONFIG, offset: 0xC */
  } RTX_GENERAL;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< HDMI_RTX_GENERAL CONFIG, offset: 0x10 */
    __IO uint32_t SET;                               /**< HDMI_RTX_GENERAL CONFIG, offset: 0x14 */
    __IO uint32_t CLR;                               /**< HDMI_RTX_GENERAL CONFIG, offset: 0x18 */
    __IO uint32_t TOG;                               /**< HDMI_RTX_GENERAL CONFIG, offset: 0x1C */
  } RTX_GENERAL_1;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< HDMI_RTX_RESET_CTL0, offset: 0x20 */
    __IO uint32_t SET;                               /**< HDMI_RTX_RESET_CTL0, offset: 0x24 */
    __IO uint32_t CLR;                               /**< HDMI_RTX_RESET_CTL0, offset: 0x28 */
    __IO uint32_t TOG;                               /**< HDMI_RTX_RESET_CTL0, offset: 0x2C */
  } RTX_RESET_CTL0;
       uint8_t RESERVED_0[16];
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< HDMI_RTX_CLK_CTL0, offset: 0x40 */
    __IO uint32_t SET;                               /**< HDMI_RTX_CLK_CTL0, offset: 0x44 */
    __IO uint32_t CLR;                               /**< HDMI_RTX_CLK_CTL0, offset: 0x48 */
    __IO uint32_t TOG;                               /**< HDMI_RTX_CLK_CTL0, offset: 0x4C */
  } RTX_CLK_CTL0;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< HDMI_RTX_CLK_CTL1, offset: 0x50 */
    __IO uint32_t SET;                               /**< HDMI_RTX_CLK_CTL1, offset: 0x54 */
    __IO uint32_t CLR;                               /**< HDMI_RTX_CLK_CTL1, offset: 0x58 */
    __IO uint32_t TOG;                               /**< HDMI_RTX_CLK_CTL1, offset: 0x5C */
  } RTX_CLK_CTL1;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< RTX_CLK_CTL2, offset: 0x60 */
    __IO uint32_t SET;                               /**< RTX_CLK_CTL2, offset: 0x64 */
    __IO uint32_t CLR;                               /**< RTX_CLK_CTL2, offset: 0x68 */
    __IO uint32_t TOG;                               /**< RTX_CLK_CTL2, offset: 0x6C */
  } RTX_CLK_CTL2;
  struct {                                         /* offset: 0x70 */
    __IO uint32_t RW;                                /**< RTX_CLK_CTL3, offset: 0x70 */
    __IO uint32_t SET;                               /**< RTX_CLK_CTL3, offset: 0x74 */
    __IO uint32_t CLR;                               /**< RTX_CLK_CTL3, offset: 0x78 */
    __IO uint32_t TOG;                               /**< RTX_CLK_CTL3, offset: 0x7C */
  } RTX_CLK_CTL3;
  struct {                                         /* offset: 0x80 */
    __IO uint32_t RW;                                /**< RTX_CLK_CTL4, offset: 0x80 */
    __IO uint32_t SET;                               /**< RTX_CLK_CTL4, offset: 0x84 */
    __IO uint32_t CLR;                               /**< RTX_CLK_CTL4, offset: 0x88 */
    __IO uint32_t TOG;                               /**< RTX_CLK_CTL4, offset: 0x8C */
  } RTX_CLK_CTL4;
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< HDMI_RX_Control, offset: 0x90 */
    __IO uint32_t SET;                               /**< HDMI_RX_Control, offset: 0x94 */
    __IO uint32_t CLR;                               /**< HDMI_RX_Control, offset: 0x98 */
    __IO uint32_t TOG;                               /**< HDMI_RX_Control, offset: 0x9C */
  } RTX_IRQ_MASK;
  struct {                                         /* offset: 0xA0 */
    __I  uint32_t RW;                                /**< HDMI_TX Masked Interrupt status, offset: 0xA0 */
    __I  uint32_t SET;                               /**< HDMI_TX Masked Interrupt status, offset: 0xA4 */
    __I  uint32_t CLR;                               /**< HDMI_TX Masked Interrupt status, offset: 0xA8 */
    __I  uint32_t TOG;                               /**< HDMI_TX Masked Interrupt status, offset: 0xAC */
  } RTX_IRQ_MASKED_STATUS;
  struct {                                         /* offset: 0xB0 */
    __IO uint32_t RW;                                /**< HDMI_RX_Control, offset: 0xB0 */
    __IO uint32_t SET;                               /**< HDMI_RX_Control, offset: 0xB4 */
    __IO uint32_t CLR;                               /**< HDMI_RX_Control, offset: 0xB8 */
    __IO uint32_t TOG;                               /**< HDMI_RX_Control, offset: 0xBC */
  } RTX_IRQ_NONMASK_STATUS;
       uint8_t RESERVED_1[320];
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Miscellaneous Controls for the HDMI TX Controller, offset: 0x200 */
    __IO uint32_t SET;                               /**< Miscellaneous Controls for the HDMI TX Controller, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Miscellaneous Controls for the HDMI TX Controller, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Miscellaneous Controls for the HDMI TX Controller, offset: 0x20C */
  } TX_CONTROL0;
       uint8_t RESERVED_2[16];
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< TX Control, offset: 0x220 */
    __IO uint32_t SET;                               /**< TX Control, offset: 0x224 */
    __IO uint32_t CLR;                               /**< TX Control, offset: 0x228 */
    __IO uint32_t TOG;                               /**< TX Control, offset: 0x22C */
  } TX_CONTROL2;
  struct {                                         /* offset: 0x230 */
    __I  uint32_t RW;                                /**< Status, offset: 0x230 */
    __I  uint32_t SET;                               /**< Status, offset: 0x234 */
    __I  uint32_t CLR;                               /**< Status, offset: 0x238 */
    __I  uint32_t TOG;                               /**< Status, offset: 0x23C */
  } TX_STATUS0;
       uint8_t RESERVED_3[3456];
  struct {                                         /* offset: 0xFC0 */
    __IO uint32_t RW;                                /**< Spare Config, offset: 0xFC0 */
    __IO uint32_t SET;                               /**< Spare Config, offset: 0xFC4 */
    __IO uint32_t CLR;                               /**< Spare Config, offset: 0xFC8 */
    __IO uint32_t TOG;                               /**< Spare Config, offset: 0xFCC */
  } SPARE_CONFIG0;
       uint8_t RESERVED_4[32];
  struct {                                         /* offset: 0xFF0 */
    __I  uint32_t RW;                                /**< Spare Status0, offset: 0xFF0 */
    __I  uint32_t SET;                               /**< Spare Status0, offset: 0xFF4 */
    __I  uint32_t CLR;                               /**< Spare Status0, offset: 0xFF8 */
    __I  uint32_t TOG;                               /**< Spare Status0, offset: 0xFFC */
  } SPARE_STATUS0;
} HDMI_TX_BLK_CTL_Type;

/* ----------------------------------------------------------------------------
   -- HDMI_TX_BLK_CTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDMI_TX_BLK_CTL_Register_Masks HDMI_TX_BLK_CTL Register Masks
 * @{
 */

/*! @name RTX_GENERAL - HDMI_RTX_GENERAL CONFIG */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_GENERAL_DEBUG_LOCKOUT_EN_MASK (0x1U)
#define HDMI_TX_BLK_CTL_RTX_GENERAL_DEBUG_LOCKOUT_EN_SHIFT (0U)
/*! DEBUG_LOCKOUT_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_GENERAL_DEBUG_LOCKOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_GENERAL_DEBUG_LOCKOUT_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_GENERAL_DEBUG_LOCKOUT_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_GENERAL_HDCP_AXI_ADDR_EXTN_MASK (0x30U)
#define HDMI_TX_BLK_CTL_RTX_GENERAL_HDCP_AXI_ADDR_EXTN_SHIFT (4U)
/*! HDCP_AXI_ADDR_EXTN - HDCP_AXI_ADDR_EXTN control */
#define HDMI_TX_BLK_CTL_RTX_GENERAL_HDCP_AXI_ADDR_EXTN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_GENERAL_HDCP_AXI_ADDR_EXTN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_GENERAL_HDCP_AXI_ADDR_EXTN_MASK)

#define HDMI_TX_BLK_CTL_RTX_GENERAL_LCDIF_AXI_LIMIT_EN_MASK (0x100U)
#define HDMI_TX_BLK_CTL_RTX_GENERAL_LCDIF_AXI_LIMIT_EN_SHIFT (8U)
/*! LCDIF_AXI_LIMIT_EN - Enables the AXI Read Beat count limiter; the beat limit value is given by the 16b value LCDIF_AXI_BEAT_LIMIT */
#define HDMI_TX_BLK_CTL_RTX_GENERAL_LCDIF_AXI_LIMIT_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_GENERAL_LCDIF_AXI_LIMIT_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_GENERAL_LCDIF_AXI_LIMIT_EN_MASK)
/*! @} */

/*! @name RTX_GENERAL_1 - HDMI_RTX_GENERAL CONFIG */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_GENERAL_1_LCDIF_AXI_BEAT_LIMIT_MASK (0xFFFFU)
#define HDMI_TX_BLK_CTL_RTX_GENERAL_1_LCDIF_AXI_BEAT_LIMIT_SHIFT (0U)
/*! LCDIF_AXI_BEAT_LIMIT - LCDIF_AXI_BEAT_LIMIT */
#define HDMI_TX_BLK_CTL_RTX_GENERAL_1_LCDIF_AXI_BEAT_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_GENERAL_1_LCDIF_AXI_BEAT_LIMIT_SHIFT)) & HDMI_TX_BLK_CTL_RTX_GENERAL_1_LCDIF_AXI_BEAT_LIMIT_MASK)
/*! @} */

/*! @name RTX_RESET_CTL0 - HDMI_RTX_RESET_CTL0 */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_NOC_RESET_N_MASK (0x1U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_NOC_RESET_N_SHIFT (0U)
/*! NOC_RESET_N - NOC_RESET_N control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_NOC_RESET_N(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_NOC_RESET_N_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_NOC_RESET_N_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_ASYNC_RESET_N_MASK (0x10U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_ASYNC_RESET_N_SHIFT (4U)
/*! LCDIF_ASYNC_RESET_N - LCDIF_ASYNC_RESET_N control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_ASYNC_RESET_N(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_ASYNC_RESET_N_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_ASYNC_RESET_N_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_APB_RESET_N_MASK (0x20U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_APB_RESET_N_SHIFT (5U)
/*! LCDIF_APB_RESET_N - LCDIF_APB_RESET_N control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_APB_RESET_N(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_APB_RESET_N_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_LCDIF_APB_RESET_N_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_RESETN_MASK (0x40U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_RESETN_SHIFT (6U)
/*! FDCC_RESETN - FDCC_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_HDMI_RESETN_MASK (0x80U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_HDMI_RESETN_SHIFT (7U)
/*! FDCC_HDMI_RESETN - FDCC_HDMI_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_HDMI_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_HDMI_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_FDCC_HDMI_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_RSTZ_MASK (0x400U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_RSTZ_SHIFT (10U)
/*! TX_RSTZ - TX_RSTZ control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_RSTZ(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_RSTZ_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_RSTZ_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_APBRSTZ_MASK (0x800U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_APBRSTZ_SHIFT (11U)
/*! TX_APBRSTZ - TX_APBRSTZ control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_APBRSTZ(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_APBRSTZ_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_APBRSTZ_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_PHY_PRESETN_MASK (0x1000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_PHY_PRESETN_SHIFT (12U)
/*! TX_PHY_PRESETN - TX_PHY_PRESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_PHY_PRESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_PHY_PRESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_PHY_PRESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_KSV_MEM_RESETN_MASK (0x2000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_KSV_MEM_RESETN_SHIFT (13U)
/*! TX_KSV_MEM_RESETN - KSV Mem reset control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_KSV_MEM_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_KSV_MEM_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_KSV_MEM_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_SEC_MEM_RESETN_MASK (0x4000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_SEC_MEM_RESETN_SHIFT (14U)
/*! TX_SEC_MEM_RESETN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_SEC_MEM_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_SEC_MEM_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_SEC_MEM_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_HRV_MWR_RESETN_MASK (0x8000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_HRV_MWR_RESETN_SHIFT (15U)
/*! HRV_MWR_RESETN - HRV_MWR_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_HRV_MWR_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_HRV_MWR_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_HRV_MWR_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_IRQ_RESETN_MASK (0x10000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_IRQ_RESETN_SHIFT (16U)
/*! IRQ_RESETN - IRQ_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_IRQ_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_IRQ_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_IRQ_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_PAI_RESETN_MASK (0x40000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_PAI_RESETN_SHIFT (18U)
/*! PAI_RESETN - PAI_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_PAI_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_PAI_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_PAI_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_TRNG_RESETN_MASK (0x100000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_TRNG_RESETN_SHIFT (20U)
/*! TX_TRNG_RESETN - TX_TRNG_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_TRNG_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_TRNG_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_TX_TRNG_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VID_LINK_SLV_RESETN_MASK (0x400000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VID_LINK_SLV_RESETN_SHIFT (22U)
/*! VID_LINK_SLV_RESETN - VID_LINK_SLV_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VID_LINK_SLV_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VID_LINK_SLV_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VID_LINK_SLV_RESETN_MASK)

#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VSFD_RESETN_MASK (0x800000U)
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VSFD_RESETN_SHIFT (23U)
/*! VSFD_RESETN - VSFD_RESETN control */
#define HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VSFD_RESETN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VSFD_RESETN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_RESET_CTL0_VSFD_RESETN_MASK)
/*! @} */

/*! @name RTX_CLK_CTL0 - HDMI_RTX_CLK_CTL0 */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_APB_CLK_EN_MASK (0x1U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_APB_CLK_EN_SHIFT (0U)
/*! GLOBAL_APB_CLK_EN - GLOBAL_APB_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_APB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_APB_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_APB_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_B_CLK_EN_MASK (0x2U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_B_CLK_EN_SHIFT (1U)
/*! GLOBAL_B_CLK_EN - GLOBAL_B_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_B_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_B_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_B_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_REF266M_CLK_EN_MASK (0x4U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_REF266M_CLK_EN_SHIFT (2U)
/*! GLOBAL_REF266M_CLK_EN - GLOBAL_REF266M_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_REF266M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_REF266M_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_REF266M_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL27M_CLK_EN_MASK (0x8U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL27M_CLK_EN_SHIFT (3U)
/*! GLOBAL_XTAL27M_CLK_EN - GLOBAL_XTAL27M_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL27M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL27M_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL27M_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL24M_CLK_EN_MASK (0x10U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL24M_CLK_EN_SHIFT (4U)
/*! GLOBAL_XTAL24M_CLK_EN - GLOBAL_XTAL24M_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL24M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL24M_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL24M_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL32K_CLK_EN_MASK (0x20U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL32K_CLK_EN_SHIFT (5U)
/*! GLOBAL_XTAL32K_CLK_EN - GLOBAL_XTAL32K_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL32K_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL32K_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_XTAL32K_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_AUD_PLL_CLK_EN_MASK (0x40U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_AUD_PLL_CLK_EN_SHIFT (6U)
/*! GLOBAL_AUD_PLL_CLK_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_AUD_PLL_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_AUD_PLL_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_AUD_PLL_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_TX_PIX_CLK_EN_MASK (0x80U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_TX_PIX_CLK_EN_SHIFT (7U)
/*! GLOBAL_TX_PIX_CLK_EN - TX pix clk control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_TX_PIX_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_TX_PIX_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_GLOBAL_TX_PIX_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_PD1_CLK_EN_MASK (0x100U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_PD1_CLK_EN_SHIFT (8U)
/*! PD1_CLK_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_PD1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_PD1_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_PD1_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_IRQS_CLK_EN_MASK (0x200U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_IRQS_CLK_EN_SHIFT (9U)
/*! IRQS_CLK_EN - clock control for the irq_steer block */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_IRQS_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_IRQS_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_IRQS_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDMI_CLK_EN_MASK (0x400U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDMI_CLK_EN_SHIFT (10U)
/*! NOC_HDMI_CLK_EN - clock enable for the NOC bus_clk enable */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDMI_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDMI_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDMI_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDCP_CLK_EN_MASK (0x800U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDCP_CLK_EN_SHIFT (11U)
/*! NOC_HDCP_CLK_EN - clock enable for the NOC hdcp_clk */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDCP_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDCP_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_NOC_HDCP_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_APB_CLK_EN_MASK (0x10000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_APB_CLK_EN_SHIFT (16U)
/*! LCDIF_APB_CLK_EN - clock enable for lcdif apb_clk input */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_APB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_APB_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_APB_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_B_CLK_EN_MASK (0x20000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_B_CLK_EN_SHIFT (17U)
/*! LCDIF_B_CLK_EN - clock enable for lcdif bus_clk input */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_B_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_B_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_B_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PDI_CLK_EN_MASK (0x40000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PDI_CLK_EN_SHIFT (18U)
/*! LCDIF_PDI_CLK_EN - clock enable for lcdif pdi_clk input */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PDI_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PDI_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PDI_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PIX_CLK_EN_MASK (0x80000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PIX_CLK_EN_SHIFT (19U)
/*! LCDIF_PIX_CLK_EN - clock enable for lcdif pix_clk input */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PIX_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PIX_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_PIX_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_SPU_CLK_EN_MASK (0x100000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_SPU_CLK_EN_SHIFT (20U)
/*! LCDIF_SPU_CLK_EN - clock enable for lcdif spu_clk input */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_SPU_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_SPU_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL0_LCDIF_SPU_CLK_EN_MASK)
/*! @} */

/*! @name RTX_CLK_CTL1 - HDMI_RTX_CLK_CTL1 */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_IHDMI_CLK_EN_MASK (0x2U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_IHDMI_CLK_EN_SHIFT (1U)
/*! FDCC_IHDMI_CLK_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_IHDMI_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_IHDMI_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_IHDMI_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_REF_CLK_EN_MASK (0x4U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_REF_CLK_EN_SHIFT (2U)
/*! FDCC_REF_CLK_EN - FDCC_REF_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_REF_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_REF_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_FDCC_REF_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_APB_CLK_EN_MASK (0x8U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_APB_CLK_EN_SHIFT (3U)
/*! HRV_MWR_APB_CLK_EN - HRV_MWR_APB_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_APB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_APB_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_APB_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_B_CLK_EN_MASK (0x10U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_B_CLK_EN_SHIFT (4U)
/*! HRV_MWR_B_CLK_EN - HRV_MWR_B_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_B_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_B_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_B_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_CEA_CLK_EN_MASK (0x20U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_CEA_CLK_EN_SHIFT (5U)
/*! HRV_MWR_CEA_CLK_EN - HRV_MWR_CEA_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_CEA_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_CEA_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HRV_MWR_CEA_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_VSFD_CEA_CLK_EN_MASK (0x40U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_VSFD_CEA_CLK_EN_SHIFT (6U)
/*! VSFD_CEA_CLK_EN - VSFD_CEA_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_VSFD_CEA_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_VSFD_CEA_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_VSFD_CEA_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_vpll_clk_sel_MASK (0x100U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_vpll_clk_sel_SHIFT (8U)
/*! vpll_clk_sel - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_vpll_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_vpll_clk_sel_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_vpll_clk_sel_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_fdcc_clk_sel_MASK (0x200U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_fdcc_clk_sel_SHIFT (9U)
/*! fdcc_clk_sel - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_fdcc_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_fdcc_clk_sel_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_fdcc_clk_sel_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_htxphy_clk_sel_MASK (0x400U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_htxphy_clk_sel_SHIFT (10U)
/*! htxphy_clk_sel - htxphy_clk_sel control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_htxphy_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_htxphy_clk_sel_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_htxphy_clk_sel_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_lcdif_clk_sel_MASK (0x800U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_lcdif_clk_sel_SHIFT (11U)
/*! lcdif_clk_sel - lcdif_clk_sel control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_lcdif_clk_sel(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_lcdif_clk_sel_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_lcdif_clk_sel_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HTX_PIPE_CLK_SEL_MASK (0x1000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HTX_PIPE_CLK_SEL_SHIFT (12U)
/*! HTX_PIPE_CLK_SEL - HTX_PIPE_CLK_SEL control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HTX_PIPE_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HTX_PIPE_CLK_SEL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_HTX_PIPE_CLK_SEL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_HPI_CLK_EN_MASK (0x2000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_HPI_CLK_EN_SHIFT (13U)
/*! TX_HPI_CLK_EN - TX_HPI_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_HPI_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_HPI_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_HPI_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_APB_CLK_EN_MASK (0x4000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_APB_CLK_EN_SHIFT (14U)
/*! TX_APB_CLK_EN - TX_APB_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_APB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_APB_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_APB_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_CEC_CLK_EN_MASK (0x8000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_CEC_CLK_EN_SHIFT (15U)
/*! TX_CEC_CLK_EN - TX_CEC_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_CEC_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_CEC_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_CEC_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_ESM_CLK_EN_MASK (0x10000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_ESM_CLK_EN_SHIFT (16U)
/*! TX_ESM_CLK_EN - TX_ESM_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_ESM_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_ESM_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_ESM_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_GPA_CLK_EN_MASK (0x20000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_GPA_CLK_EN_SHIFT (17U)
/*! TX_GPA_CLK_EN - TX_GPA_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_GPA_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_GPA_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_GPA_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PIXEL_CLK_EN_MASK (0x40000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PIXEL_CLK_EN_SHIFT (18U)
/*! TX_PIXEL_CLK_EN - TX_PIXEL_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PIXEL_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PIXEL_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PIXEL_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SFR_CLK_EN_MASK (0x80000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SFR_CLK_EN_SHIFT (19U)
/*! TX_SFR_CLK_EN - TX_SFR_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SFR_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SFR_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SFR_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SKP_CLK_EN_MASK (0x100000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SKP_CLK_EN_SHIFT (20U)
/*! TX_SKP_CLK_EN - TX_SKP_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SKP_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SKP_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SKP_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PREP_CLK_EN_MASK (0x200000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PREP_CLK_EN_SHIFT (21U)
/*! TX_PREP_CLK_EN - TX_PREP_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PREP_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PREP_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PREP_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_APB_CLK_EN_MASK (0x400000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_APB_CLK_EN_SHIFT (22U)
/*! TX_PHY_APB_CLK_EN - TX_PHY_APB_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_APB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_APB_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_APB_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_PIXEL_CLK_EN_MASK (0x800000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_PIXEL_CLK_EN_SHIFT (23U)
/*! TX_PHY_PIXEL_CLK_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_PIXEL_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_PIXEL_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_PIXEL_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_INT_CLK_EN_MASK (0x1000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_INT_CLK_EN_SHIFT (24U)
/*! TX_PHY_INT_CLK_EN - TX_PHY_INT_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_INT_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_INT_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_PHY_INT_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SEC_MEM_CLK_EN_MASK (0x2000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SEC_MEM_CLK_EN_SHIFT (25U)
/*! TX_SEC_MEM_CLK_EN - TX_SEC_MEM_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SEC_MEM_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SEC_MEM_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_SEC_MEM_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_PAI_CLK_EN_MASK (0x4000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_PAI_CLK_EN_SHIFT (26U)
/*! PAI_CLK_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_PAI_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_PAI_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_PAI_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_SKP_CLK_EN_MASK (0x8000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_SKP_CLK_EN_SHIFT (27U)
/*! TX_TRNG_SKP_CLK_EN - TX_TRNG_SKP_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_SKP_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_SKP_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_SKP_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_VID_LINK_PIX_CLK_EN_MASK (0x10000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_VID_LINK_PIX_CLK_EN_SHIFT (28U)
/*! TX_VID_LINK_PIX_CLK_EN - TX_VID_LINK_PIX_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_VID_LINK_PIX_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_VID_LINK_PIX_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_VID_LINK_PIX_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_MEM_266M_CLK_EN_MASK (0x20000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_MEM_266M_CLK_EN_SHIFT (29U)
/*! TX_MEM_266M_CLK_EN - RESERVED */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_MEM_266M_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_MEM_266M_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_MEM_266M_CLK_EN_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_APB_CLK_EN_MASK (0x40000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_APB_CLK_EN_SHIFT (30U)
/*! TX_TRNG_APB_CLK_EN - TX_TRNG_APB_CLK_EN control */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_APB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_APB_CLK_EN_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL1_TX_TRNG_APB_CLK_EN_MASK)
/*! @} */

/*! @name RTX_CLK_CTL2 - RTX_CLK_CTL2 */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_IRQS_CLK_CTL_MASK (0x3U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_IRQS_CLK_CTL_SHIFT (0U)
/*! IRQS_CLK_CTL - Used to bypass the programmable clock controls for IRQ_STEER */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_IRQS_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_IRQS_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_IRQS_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_APB_CLK_CTL_MASK (0xCU)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_APB_CLK_CTL_SHIFT (2U)
/*! FDCC_APB_CLK_CTL - Used to bypass the programmable clock controls for FDCC apb clock */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_REF_CLK_CTL_MASK (0x30U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_REF_CLK_CTL_SHIFT (4U)
/*! FDCC_REF_CLK_CTL - Used to bypass the programmable clock controls for FDCC ref clock */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_REF_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_REF_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_FDCC_REF_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_HPI_CLK_CTL_MASK (0xC0U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_HPI_CLK_CTL_SHIFT (6U)
/*! HDMI_TX_HPI_CLK_CTL - Used to bypass the programmable clock controls for hpi_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_HPI_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_HPI_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_HPI_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_APB_CLK_CTL_MASK (0x300U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_APB_CLK_CTL_SHIFT (8U)
/*! HDMI_TX_APB_CLK_CTL - Used to bypass the programmable clock controls for apb_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_CEC_CLK_CTL_MASK (0xC00U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_CEC_CLK_CTL_SHIFT (10U)
/*! HDMI_TX_CEC_CLK_CTL - Used to bypass the programmable clock controls for cec_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_CEC_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_CEC_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_CEC_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_ESM_CLK_CTL_MASK (0x3000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_ESM_CLK_CTL_SHIFT (12U)
/*! HDMI_TX_ESM_CLK_CTL - Used to bypass the programmable clock controls for esm_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_ESM_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_ESM_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_ESM_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_GPA_CLK_CTL_MASK (0xC000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_GPA_CLK_CTL_SHIFT (14U)
/*! HDMI_TX_GPA_CLK_CTL - Used to bypass the programmable clock controls for gpa_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_GPA_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_GPA_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_GPA_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PIX_CLK_CTL_MASK (0x30000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PIX_CLK_CTL_SHIFT (16U)
/*! HDMI_TX_PIX_CLK_CTL - Used to bypass the programmable clock controls for ipixel_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PIX_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PIX_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PIX_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SFR_CLK_CTL_MASK (0xC0000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SFR_CLK_CTL_SHIFT (18U)
/*! HDMI_TX_SFR_CLK_CTL - Used to bypass the programmable clock controls for sfr_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SFR_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SFR_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SFR_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SKP_CLK_CTL_MASK (0x300000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SKP_CLK_CTL_SHIFT (20U)
/*! HDMI_TX_SKP_CLK_CTL - Used to bypass the programmable clock controls for skp_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SKP_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SKP_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_SKP_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PREP_CLK_CTL_MASK (0xC00000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PREP_CLK_CTL_SHIFT (22U)
/*! HDMI_TX_PREP_CLK_CTL - Used to bypass the programmable clock controls for prep_clk input of HDMI TX */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PREP_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PREP_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_HDMI_TX_PREP_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_APB_CLK_CTL_MASK (0x3000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_APB_CLK_CTL_SHIFT (24U)
/*! TX_PHY_APB_CLK_CTL - Used to bypass the programmable clock controls for apb_clk input of the HDMI TX PHY */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_INT_CLK_CTL_MASK (0xC000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_INT_CLK_CTL_SHIFT (26U)
/*! TX_PHY_INT_CLK_CTL - Used to bypass the programmable clock controls for int_clk input of the HDMI TX PHY */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_INT_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_INT_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_TX_PHY_INT_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_APB_CLK_CTL_MASK (0x30000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_APB_CLK_CTL_SHIFT (28U)
/*! PAI_APB_CLK_CTL - Used to bypass the programmable clock controls for apb_clk input of HTX_PAI */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_AUD_CLK_CTL_MASK (0xC0000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_AUD_CLK_CTL_SHIFT (30U)
/*! PAI_AUD_CLK_CTL - Used to bypass the programmable clock controls for aud_clk input of HTX_PAI */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_AUD_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_AUD_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL2_PAI_AUD_CLK_CTL_MASK)
/*! @} */

/*! @name RTX_CLK_CTL3 - RTX_CLK_CTL3 */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_APB_CLK_CTL_MASK (0x3U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_APB_CLK_CTL_SHIFT (0U)
/*! TRNG_APB_CLK_CTL - Used to bypass the programmable clock controls for apb_clk input of TRNG */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_SKP_CLK_CTL_MASK (0xCU)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_SKP_CLK_CTL_SHIFT (2U)
/*! TRNG_SKP_CLK_CTL - Used to bypass the programmable clock controls for skp_clk input of TRNG */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_SKP_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_SKP_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_TRNG_SKP_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_APB_CLK_CTL_MASK (0x30U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_APB_CLK_CTL_SHIFT (4U)
/*! VID_SLV_APB_CLK_CTL - Used to bypass the programmable clock controls for apb_clk input of video link slave */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_PIX_CLK_CTL_MASK (0xC0U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_PIX_CLK_CTL_SHIFT (6U)
/*! VID_SLV_PIX_CLK_CTL - Used to bypass the programmable clock controls for pix_clk input of video link slave */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_PIX_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_PIX_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VID_SLV_PIX_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_B_CLK_CTL_MASK (0x300U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_B_CLK_CTL_SHIFT (8U)
/*! HRV_MWR_B_CLK_CTL - Used to bypass the programmable clock controls for b_clk input of HRV_MWR */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_B_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_B_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_B_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_CEA_CLK_CTL_MASK (0xC00U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_CEA_CLK_CTL_SHIFT (10U)
/*! HRV_MWR_CEA_CLK_CTL - Used to bypass the programmable clock controls for cea_clk input of HRV_MWR */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_CEA_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_CEA_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_HRV_MWR_CEA_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_APB_CLK_CTL_MASK (0x3000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_APB_CLK_CTL_SHIFT (12U)
/*! VSFD_HTX_APB_CLK_CTL - Used to bypass the programmable clock controls for the apb clk input of VSFD (including portions of HRV_MWR logic) */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_P_CLK_CTL_MASK (0xC000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_P_CLK_CTL_SHIFT (14U)
/*! VSFD_HTX_P_CLK_CTL - Used to bypass the programmable clock controls for the htx_p_clk input used
 *    in VSFD (including portions of HRV_MWR logic)
 */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_P_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_P_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_HTX_P_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_CEA_CLK_CTL_MASK (0x30000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_CEA_CLK_CTL_SHIFT (16U)
/*! VSFD_CEA_CLK_CTL - Used to bypass the programmable clock controls for cea_clk input of vsfd */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_CEA_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_CEA_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_VSFD_CEA_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_APB_CLK_CTL_MASK (0xC0000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_APB_CLK_CTL_SHIFT (18U)
/*! LCDIF_APB_CLK_CTL - Used to bypass the programmable clock controls for apb_clk input of LCDIF */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_APB_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_APB_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_APB_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_B_CLK_CTL_MASK (0x300000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_B_CLK_CTL_SHIFT (20U)
/*! LCDIF_B_CLK_CTL - Used to bypass the programmable clock controls for b_clk input of LCDIF */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_B_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_B_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_B_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PDI_CLK_CTL_MASK (0xC00000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PDI_CLK_CTL_SHIFT (22U)
/*! LCDIF_PDI_CLK_CTL - Used to bypass the programmable clock controls for pdi_clk input of LCDIF */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PDI_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PDI_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PDI_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PIX_CLK_CTL_MASK (0x3000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PIX_CLK_CTL_SHIFT (24U)
/*! LCDIF_PIX_CLK_CTL - Used to bypass the programmable clock controls for pix_clk input of LCDIF */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PIX_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PIX_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_PIX_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_SPU_CLK_CTL_MASK (0xC000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_SPU_CLK_CTL_SHIFT (26U)
/*! LCDIF_SPU_CLK_CTL - Used to bypass the programmable clock controls for spu_clk input of LCDIF */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_SPU_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_SPU_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_LCDIF_SPU_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_HDCP_CLK_CTL_MASK (0x30000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_HDCP_CLK_CTL_SHIFT (28U)
/*! NOC_HDCP_CLK_CTL - Used to bypass the programmable clock controls for hdcp clock input of the HDMI NOC */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_HDCP_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_HDCP_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_HDCP_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_B_CLK_CTL_MASK (0xC0000000U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_B_CLK_CTL_SHIFT (30U)
/*! NOC_B_CLK_CTL - Used to bypass the programmable clock controls for bus clock input of the HDMI NOC */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_B_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_B_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL3_NOC_B_CLK_CTL_MASK)
/*! @} */

/*! @name RTX_CLK_CTL4 - RTX_CLK_CTL4 */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL4_REVOCMEM_CLK_CTL_MASK (0x3U)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL4_REVOCMEM_CLK_CTL_SHIFT (0U)
/*! REVOCMEM_CLK_CTL - Used to bypass the request based clock gating on revocmem */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL4_REVOCMEM_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL4_REVOCMEM_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL4_REVOCMEM_CLK_CTL_MASK)

#define HDMI_TX_BLK_CTL_RTX_CLK_CTL4_TX_SEC_MEM_CLK_CTL_MASK (0xCU)
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL4_TX_SEC_MEM_CLK_CTL_SHIFT (2U)
/*! TX_SEC_MEM_CLK_CTL - Used to bypass the request based clock gating on tx_sec_mem */
#define HDMI_TX_BLK_CTL_RTX_CLK_CTL4_TX_SEC_MEM_CLK_CTL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_CLK_CTL4_TX_SEC_MEM_CLK_CTL_SHIFT)) & HDMI_TX_BLK_CTL_RTX_CLK_CTL4_TX_SEC_MEM_CLK_CTL_MASK)
/*! @} */

/*! @name RTX_IRQ_MASK - HDMI_RX_Control */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_HIGH2LOW_MASK (0x1000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_HIGH2LOW_SHIFT (12U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_HIGH2LOW(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_HIGH2LOW_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_HIGH2LOW_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_LOW2HIGH_MASK (0x2000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_LOW2HIGH_SHIFT (13U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_LOW2HIGH(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_LOW2HIGH_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_HPD_LOW2HIGH_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_HIGH2LOW_MASK (0x4000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_HIGH2LOW_SHIFT (14U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_HIGH2LOW(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_HIGH2LOW_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_HIGH2LOW_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_LOW2HIGH_MASK (0x8000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_LOW2HIGH_SHIFT (15U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_LOW2HIGH(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_LOW2HIGH_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASK_TX_READY_LOW2HIGH_MASK)
/*! @} */

/*! @name RTX_IRQ_MASKED_STATUS - HDMI_TX Masked Interrupt status */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_HIGH2LOW_MASK (0x1000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_HIGH2LOW_SHIFT (12U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_HIGH2LOW(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_HIGH2LOW_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_HIGH2LOW_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_LOW2HIGH_MASK (0x2000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_LOW2HIGH_SHIFT (13U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_LOW2HIGH(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_LOW2HIGH_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_HPD_LOW2HIGH_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_HIGH2LOW_MASK (0x4000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_HIGH2LOW_SHIFT (14U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_HIGH2LOW(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_HIGH2LOW_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_HIGH2LOW_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_LOW2HIGH_MASK (0x8000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_LOW2HIGH_SHIFT (15U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_LOW2HIGH(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_LOW2HIGH_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_MASKED_STATUS_TX_READY_LOW2HIGH_MASK)
/*! @} */

/*! @name RTX_IRQ_NONMASK_STATUS - HDMI_RX_Control */
/*! @{ */

#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_HIGH2LOW_MASK (0x1000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_HIGH2LOW_SHIFT (12U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_HIGH2LOW(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_HIGH2LOW_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_HIGH2LOW_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_LOW2HIGH_MASK (0x2000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_LOW2HIGH_SHIFT (13U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_LOW2HIGH(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_LOW2HIGH_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_HPD_LOW2HIGH_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_HIGH2LOW_MASK (0x4000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_HIGH2LOW_SHIFT (14U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_HIGH2LOW(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_HIGH2LOW_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_HIGH2LOW_MASK)

#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_LOW2HIGH_MASK (0x8000U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_LOW2HIGH_SHIFT (15U)
#define HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_LOW2HIGH(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_LOW2HIGH_SHIFT)) & HDMI_TX_BLK_CTL_RTX_IRQ_NONMASK_STATUS_TX_READY_LOW2HIGH_MASK)
/*! @} */

/*! @name TX_CONTROL0 - Miscellaneous Controls for the HDMI TX Controller */
/*! @{ */

#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_KEY_MEM_WR_LOCK_MASK (0x1U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_KEY_MEM_WR_LOCK_SHIFT (0U)
/*! TX_KEY_MEM_WR_LOCK - TX_KEY_MEM_WR_LOCK control */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_KEY_MEM_WR_LOCK(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_TX_KEY_MEM_WR_LOCK_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_TX_KEY_MEM_WR_LOCK_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CEC_EN_MASK (0x2U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CEC_EN_SHIFT (1U)
/*! TX_CEC_EN - TX_CEC_EN control */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CEC_EN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CEC_EN_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CEC_EN_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_SKP_KEYS_VALID_MASK (0x4U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_SKP_KEYS_VALID_SHIFT (2U)
/*! TX_SKP_KEYS_VALID - RESERVED */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_SKP_KEYS_VALID(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_TX_SKP_KEYS_VALID_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_TX_SKP_KEYS_VALID_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_PHY_PDOWN_MASK (0x8U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_PHY_PDOWN_SHIFT (3U)
/*! TX_PHY_PDOWN - TX_PHY_PDOWN control */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_PHY_PDOWN(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_TX_PHY_PDOWN_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_TX_PHY_PDOWN_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CTL_CLK_DIV_CNT_MASK (0x1F0U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CTL_CLK_DIV_CNT_SHIFT (4U)
/*! TX_CTL_CLK_DIV_CNT - RESERVED */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CTL_CLK_DIV_CNT(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CTL_CLK_DIV_CNT_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_TX_CTL_CLK_DIV_CNT_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_LCDIF_NOC_HURRY_MASK (0x7000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_LCDIF_NOC_HURRY_SHIFT (12U)
/*! LCDIF_NOC_HURRY - LCDIF_NOC_HURRY */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_LCDIF_NOC_HURRY(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_LCDIF_NOC_HURRY_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_LCDIF_NOC_HURRY_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_HRV_MWR_NOC_HURRY_MASK (0x70000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_HRV_MWR_NOC_HURRY_SHIFT (16U)
/*! HRV_MWR_NOC_HURRY - HRV_MWR_NOC_HURRY */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_HRV_MWR_NOC_HURRY(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_HRV_MWR_NOC_HURRY_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_HRV_MWR_NOC_HURRY_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_HPD_FILT_BYP_MASK (0x100000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_HPD_FILT_BYP_SHIFT (20U)
/*! HPD_FILT_BYP - HPD_FILT_BYP */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_HPD_FILT_BYP(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_HPD_FILT_BYP_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_HPD_FILT_BYP_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_CECIN_FILT_BYP_MASK (0x200000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_CECIN_FILT_BYP_SHIFT (21U)
/*! CECIN_FILT_BYP - CECIN_FILT_BYP */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_CECIN_FILT_BYP(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_CECIN_FILT_BYP_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_CECIN_FILT_BYP_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SCLIN_FILT_BYP_MASK (0x400000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SCLIN_FILT_BYP_SHIFT (22U)
/*! DDC_SCLIN_FILT_BYP - DDC_SCLIN_FILT_BYP */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SCLIN_FILT_BYP(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SCLIN_FILT_BYP_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SCLIN_FILT_BYP_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SDAIN_FILT_BYP_MASK (0x800000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SDAIN_FILT_BYP_SHIFT (23U)
/*! DDC_SDAIN_FILT_BYP - DDC_SDAIN_FILT_BYP */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SDAIN_FILT_BYP(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SDAIN_FILT_BYP_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_DDC_SDAIN_FILT_BYP_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL0_TRNG_LOCK_MASK (0x1000000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TRNG_LOCK_SHIFT (24U)
/*! TRNG_LOCK - TRNG_LOCK control */
#define HDMI_TX_BLK_CTL_TX_CONTROL0_TRNG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL0_TRNG_LOCK_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL0_TRNG_LOCK_MASK)
/*! @} */

/*! @name TX_CONTROL2 - TX Control */
/*! @{ */

#define HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_TOT_COUNT_MASK (0x3FF0U)
#define HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_TOT_COUNT_SHIFT (4U)
/*! TX_PREPCLK_TOT_COUNT - TX_PREPCLK_TOT_COUNT control */
#define HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_TOT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_TOT_COUNT_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_TOT_COUNT_MASK)

#define HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_ACTCYC_COUNT_MASK (0x3FF0000U)
#define HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_ACTCYC_COUNT_SHIFT (16U)
/*! TX_PREPCLK_ACTCYC_COUNT - TX_PREPCLK_ACTCYC_COUNT control */
#define HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_ACTCYC_COUNT(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_ACTCYC_COUNT_SHIFT)) & HDMI_TX_BLK_CTL_TX_CONTROL2_TX_PREPCLK_ACTCYC_COUNT_MASK)
/*! @} */

/*! @name TX_STATUS0 - Status */
/*! @{ */

#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_AFC_CODE_MASK (0x1FU)
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_AFC_CODE_SHIFT (0U)
/*! TX_PHY_AFC_CODE - TX_PHY_AFC_CODE status */
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_AFC_CODE(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_AFC_CODE_SHIFT)) & HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_AFC_CODE_MASK)

#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_CLK_RDY_MASK (0x20U)
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_CLK_RDY_SHIFT (5U)
/*! TX_PHY_CLK_RDY - TX_PHY_CLK_RDY status */
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_CLK_RDY(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_CLK_RDY_SHIFT)) & HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_CLK_RDY_MASK)

#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_RDY_MASK (0x40U)
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_RDY_SHIFT (6U)
/*! TX_PHY_RDY - TX_PHY_RDY status */
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_RDY(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_RDY_SHIFT)) & HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_RDY_MASK)

#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_PLL_LOCK_MASK (0x80U)
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_PLL_LOCK_SHIFT (7U)
/*! TX_PHY_PLL_LOCK - TX_PHY_PLL_LOCK status */
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_PLL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_PLL_LOCK_SHIFT)) & HDMI_TX_BLK_CTL_TX_STATUS0_TX_PHY_PLL_LOCK_MASK)

#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_HPD_STATUS_MASK (0x100U)
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_HPD_STATUS_SHIFT (8U)
/*! TX_HPD_STATUS - TX_HPD_STATUS status */
#define HDMI_TX_BLK_CTL_TX_STATUS0_TX_HPD_STATUS(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_TX_STATUS0_TX_HPD_STATUS_SHIFT)) & HDMI_TX_BLK_CTL_TX_STATUS0_TX_HPD_STATUS_MASK)
/*! @} */

/*! @name SPARE_CONFIG0 - Spare Config */
/*! @{ */

#define HDMI_TX_BLK_CTL_SPARE_CONFIG0_SPARE_CONFIG_MASK (0xFFFFFFFFU)
#define HDMI_TX_BLK_CTL_SPARE_CONFIG0_SPARE_CONFIG_SHIFT (0U)
#define HDMI_TX_BLK_CTL_SPARE_CONFIG0_SPARE_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_SPARE_CONFIG0_SPARE_CONFIG_SHIFT)) & HDMI_TX_BLK_CTL_SPARE_CONFIG0_SPARE_CONFIG_MASK)
/*! @} */

/*! @name SPARE_STATUS0 - Spare Status0 */
/*! @{ */

#define HDMI_TX_BLK_CTL_SPARE_STATUS0_SPARE_STATUS_MASK (0xFFFFFFFFU)
#define HDMI_TX_BLK_CTL_SPARE_STATUS0_SPARE_STATUS_SHIFT (0U)
/*! SPARE_STATUS - SPARE Control */
#define HDMI_TX_BLK_CTL_SPARE_STATUS0_SPARE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TX_BLK_CTL_SPARE_STATUS0_SPARE_STATUS_SHIFT)) & HDMI_TX_BLK_CTL_SPARE_STATUS0_SPARE_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HDMI_TX_BLK_CTL_Register_Masks */


/*!
 * @}
 */ /* end of group HDMI_TX_BLK_CTL_Peripheral_Access_Layer */


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


#endif  /* PERI_HDMI_TX_BLK_CTL_H_ */

