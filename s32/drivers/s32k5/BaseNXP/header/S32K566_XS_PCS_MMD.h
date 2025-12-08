/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_XS_PCS_MMD.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_XS_PCS_MMD
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K566_XS_PCS_MMD_H_)  /* Check if memory map has not been already included */
#define S32K566_XS_PCS_MMD_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- XS_PCS_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XS_PCS_MMD_Peripheral_Access_Layer XS_PCS_MMD Peripheral Access Layer
 * @{
 */

/** XS_PCS_MMD - Register Layout Typedef */
typedef struct XS_PCS_MMD_Struct {
  __IO uint16_t SR_XS_PCS_CTRL1;                   /**< SR XS or PCS MMD Control1 Register, offset: 0x0 */
  __I  uint16_t SR_XS_PCS_STS1;                    /**< SR XS or PCS MMD Status1 Register, offset: 0x2 */
  __I  uint16_t SR_XS_PCS_DEV_ID1;                 /**< SR XS or PCS MMD Device Identifier 1 Register, offset: 0x4 */
  __I  uint16_t SR_XS_PCS_DEV_ID2;                 /**< SR XS or PCS MMD Device Identifier 2 Register, offset: 0x6 */
  __I  uint16_t SR_XS_PCS_SPD_ABL;                 /**< SR XS or PCS MMD Speed Ability Register, offset: 0x8 */
  __I  uint16_t SR_XS_PCS_DEV_PKG1;                /**< SR XS or PCS MMD Devices in Package 1 Register, offset: 0xA */
  __I  uint16_t SR_XS_PCS_DEV_PKG2;                /**< SR XS or PCS MMD Devices in Package 2 Register, offset: 0xC */
  __IO uint16_t SR_XS_PCS_CTRL2;                   /**< SR PCS Control2 Register This register is applicable only for the PCS MMD., offset: 0xE */
  __I  uint16_t SR_XS_PCS_STS2;                    /**< SR XS or PCS MMD Status2 Register, offset: 0x10 */
  __I  uint16_t SR_XS_PCS_STS3;                    /**< SR PCS MMD Status3 Register This register is applicable only for the PCS MMD, offset: 0x12 */
  uint8_t RESERVED_0[8];
  __I  uint16_t SR_XS_PCS_PKG1;                    /**< SR XS or PCS MMD Package Identifier 1 Register, offset: 0x1C */
  __I  uint16_t SR_XS_PCS_PKG2;                    /**< SR XS or PCS MMD Package Identifier 2 Register, offset: 0x1E */
  uint8_t RESERVED_1[8];
  __I  uint16_t SR_XS_PCS_EEE_ABL;                 /**< SR XS or PCS MMD EEE Capability Register, offset: 0x28 */
  __I  uint16_t SR_XS_PCS_EEE_ABL2;                /**< SR PCS MMD EEE Control and Capability2 Register, offset: 0x2A */
  __I  uint16_t SR_XS_PCS_EEE_WKERR;               /**< SR XS or PCS MMD EEE Wake Error Counter Register This register is present only when EEE_EN = Enabled., offset: 0x2C */
  uint8_t RESERVED_2[2];
  __I  uint16_t SR_XS_PCS_LSTS;                    /**< SR XS or PCS MMD 10GBASE-X Lane Status Register This register is applicable only for the XS and PCS MMDs when the DWC_xpcs is not configured in the following modes: - 10GBASE-R PCS - KR_Only, offset: 0x30 */
  __IO uint16_t SR_XS_PCS_TCTRL;                   /**< SR XS or PCS MMD 10GBASE-X Test Control Register This register is present only with the XS and PCS MMDs when DWC_xpcs is not configured in the following modes: - 10GBASE-R PCS - KR_Only, offset: 0x32 */
  uint8_t RESERVED_3[3548];
  __I  uint16_t SR_PCS_TIME_SYNC_PCS_ABL;          /**< SR PCS MMD Time Sync Capability Register, offset: 0xE10 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR;   /**< SR PCS MMD Time Sync Tx Max Delay Lower Register, offset: 0xE12 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR;   /**< SR PCS MMD Time Sync Tx Max Delay Upper Register, offset: 0xE14 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR;   /**< SR PCS MMD Time Sync Tx Min Delay Lower Register, offset: 0xE16 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR;   /**< SR PCS MMD Time Sync Tx Min Delay Upper Register, offset: 0xE18 */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR;   /**< SR PCS MMD Time Sync Rx Max Delay Lower Register, offset: 0xE1A */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR;   /**< SR PCS MMD Time Sync Rx Max Delay Upper Register, offset: 0xE1C */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR;   /**< SR PCS MMD Time Sync Rx Min Delay Lower Register, offset: 0xE1E */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR;   /**< SR PCS MMD Time Sync Rx Min Delay Upper Register, offset: 0xE20 */
  uint8_t RESERVED_4[61918];
  __IO uint16_t VR_XS_PCS_DIG_CTRL1;               /**< VR XS or PCS MMD Digital Control1 Register, offset: 0x10000 */
  __IO uint16_t VR_XS_PCS_DIG_CTRL2;               /**< VR XS or PCS MMD Digital Control2 Register, offset: 0x10002 */
  __IO uint16_t VR_XS_PCS_DIG_ERRCNT_SEL;          /**< VR XS or PCS MMD Digital Error Count Select Register., offset: 0x10004 */
  uint8_t RESERVED_5[2];
  __I  uint16_t VR_XS_PCS_XAUI_CTRL;               /**< VR XS or PCS MMD XAUI Mode Control Register This register is present only when the DWC_xpcs is configured for RXAUI., offset: 0x10008 */
  __IO uint16_t VR_XS_PCS_DEBUG_CTRL;              /**< VR XS or PCS MMD Debug Control Register, offset: 0x1000A */
  __IO uint16_t VR_XS_PCS_EEE_MCTRL0;              /**< VR XS or PCS MMD EEE Mode Control Register This register enables or disables the Energy Efficient Ethernet (EEE) support., offset: 0x1000C */
  uint8_t RESERVED_6[2];
  __IO uint16_t VR_XS_PCS_EEE_TXTIMER;             /**< VR XS or PCS MMD EEE Tx Timer Register This register is present only if EEE_EN = Enabled., offset: 0x10010 */
  __IO uint16_t VR_XS_PCS_EEE_RXTIMER;             /**< VR XS or PCS MMD EEE Rx Timer Register This register is present only if EEE_EN = Enabled., offset: 0x10012 */
  uint8_t RESERVED_7[2];
  __IO uint16_t VR_XS_PCS_EEE_MCTRL1;              /**< VR XS or PCS MMD EEE Mode Control 1 Register This register also controls the Energy Efficient Ethernet (EEE) related settings of DWC_xpcs ., offset: 0x10016 */
  uint8_t RESERVED_8[8];
  __I  uint16_t VR_XS_PCS_DIG_STS;                 /**< VR XS or PCS MMD Digital Status Register, offset: 0x10020 */
  __I  uint16_t VR_XS_PCS_ICG_ERRCNT1;             /**< VR XS or PCS MMD Invalid Code Group Error Count1 Register The seven error counters EC0-EC6 do not overflow., offset: 0x10022 */
  uint8_t RESERVED_9[12];
  __I  uint16_t VR_XS_PCS_CDT_STS;                 /**< VR XS or PCS MMD Comma-Detect Status Register, offset: 0x10030 */
  __I  uint16_t VR_XS_PCS_MISC_STS;                /**< VR XS or PCS MMD Miscellaneous Status Register, offset: 0x10032 */
} XS_PCS_MMD_Type, *XS_PCS_MMD_MemMapPtr;

/** Number of instances of the XS_PCS_MMD module. */
#define XS_PCS_MMD_INSTANCE_COUNT                (1u)

/* XS_PCS_MMD - Peripheral instance base addresses */
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD base address */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD_BASE (0x860000u)
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD base pointer */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD ((XS_PCS_MMD_Type *)IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD_BASE)
/** Array initializer of XS_PCS_MMD peripheral base addresses */
#define IP_XS_PCS_MMD_BASE_ADDRS                 { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD_BASE }
/** Array initializer of XS_PCS_MMD peripheral base pointers */
#define IP_XS_PCS_MMD_BASE_PTRS                  { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__XS_PCS_MMD }

/* ----------------------------------------------------------------------------
   -- XS_PCS_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XS_PCS_MMD_Register_Masks XS_PCS_MMD Register Masks
 * @{
 */

/*! @name SR_XS_PCS_CTRL1 - SR XS or PCS MMD Control1 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_MASK   (0x3CU)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_SHIFT  (2U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_WIDTH  (4U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2(x)     (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_MASK      (0x40U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_SHIFT     (6U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_WIDTH     (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6(x)        (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_XAUI_STOP_MASK (0x200U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_XAUI_STOP_SHIFT (9U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_XAUI_STOP_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_XAUI_STOP(x)  (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_XAUI_STOP_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_XAUI_STOP_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_MASK    (0x400U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_SHIFT   (10U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_MASK      (0x800U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_SHIFT     (11U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_WIDTH     (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM(x)        (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_MASK     (0x2000U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_SHIFT    (13U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_WIDTH    (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13(x)       (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LBE_MASK      (0x4000U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LBE_SHIFT     (14U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LBE_WIDTH     (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_LBE(x)        (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_LBE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_LBE_MASK)

#define XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_MASK      (0x8000U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_SHIFT     (15U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_WIDTH     (1U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL1_RST(x)        (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_MASK)
/*! @} */

/*! @name SR_XS_PCS_STS1 - SR XS or PCS MMD Status1 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_MASK      (0x2U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_SHIFT     (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_WIDTH     (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_LPMS(x)        (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_RLU_MASK       (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RLU_SHIFT      (2U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RLU_WIDTH      (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RLU(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_RLU_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_RLU_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_CSC_MASK       (0x40U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_CSC_SHIFT      (6U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_CSC_WIDTH      (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_CSC(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_CSC_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_CSC_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_FLT_MASK       (0x80U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_FLT_SHIFT      (7U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_FLT_WIDTH      (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_FLT(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_FLT_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_FLT_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_MASK    (0x100U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_SHIFT   (8U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_MASK    (0x200U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_SHIFT   (9U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_MASK    (0x400U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_SHIFT   (10U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_MASK    (0x800U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_SHIFT   (11U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_ID1 - SR XS or PCS MMD Device Identifier 1 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_WIDTH (16U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_ID2 - SR XS or PCS MMD Device Identifier 2 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_MASK (0xFU)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_WIDTH (4U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_MASK (0x3F0U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_SHIFT (4U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_WIDTH (6U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_MASK (0xFC00U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_SHIFT (10U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_WIDTH (6U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_XS_PCS_SPD_ABL - SR XS or PCS MMD Speed Ability Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_MASK    (0x1U)
#define XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_SHIFT   (0U)
#define XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_PKG1 - SR XS or PCS MMD Devices in Package 1 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_MASK (0x1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_MASK (0x2U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_SHIFT (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_MASK   (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_SHIFT  (2U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_WIDTH  (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS(x)     (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_MASK   (0x8U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_SHIFT  (3U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_WIDTH  (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS(x)     (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_MASK (0x10U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_SHIFT (4U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_MASK (0x20U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_SHIFT (5U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_MASK    (0x40U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_SHIFT   (6U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_MASK    (0x80U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_SHIFT   (7U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_PKG2 - SR XS or PCS MMD Devices in Package 2 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_MASK  (0x4000U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_SHIFT (14U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_MASK)

#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_MASK  (0x8000U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_SHIFT (15U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_MASK)
/*! @} */

/*! @name SR_XS_PCS_CTRL2 - SR PCS Control2 Register This register is applicable only for the PCS MMD. */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_MASK (0xFU)
#define XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_WIDTH (4U)
#define XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_MASK)
/*! @} */

/*! @name SR_XS_PCS_STS2 - SR XS or PCS MMD Status2 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_MASK    (0x1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_SHIFT   (0U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_WIDTH   (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN(x)      (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_MASK (0x2U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_SHIFT (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC(x)  (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_MASK (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_SHIFT (2U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_MASK (0x8U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_SHIFT (3U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS2_RF_MASK        (0x400U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_RF_SHIFT       (10U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_RF_WIDTH       (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_RF(x)          (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_RF_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_RF_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS2_TF_MASK        (0x800U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_TF_SHIFT       (11U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_TF_WIDTH       (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_TF(x)          (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_TF_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_TF_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS2_DS_MASK        (0xC000U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_DS_SHIFT       (14U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_DS_WIDTH       (2U)
#define XS_PCS_MMD_SR_XS_PCS_STS2_DS(x)          (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS2_DS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS2_DS_MASK)
/*! @} */

/*! @name SR_XS_PCS_STS3 - SR PCS MMD Status3 Register This register is applicable only for the PCS MMD */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_MASK (0x1U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_MASK (0x2U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_SHIFT (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_MASK (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_SHIFT (2U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX(x)  (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_MASK)

#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_MASK   (0x8U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_SHIFT  (3U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_WIDTH  (1U)
#define XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR(x)     (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_MASK)
/*! @} */

/*! @name SR_XS_PCS_PKG1 - SR XS or PCS MMD Package Identifier 1 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_WIDTH (16U)
#define XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_MASK)
/*! @} */

/*! @name SR_XS_PCS_PKG2 - SR XS or PCS MMD Package Identifier 2 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_MASK (0xFU)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_WIDTH (4U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_MASK)

#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_MASK (0x3F0U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_SHIFT (4U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_WIDTH (6U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_MASK)

#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_MASK (0xFC00U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_SHIFT (10U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_WIDTH (6U)
#define XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_MASK)
/*! @} */

/*! @name SR_XS_PCS_EEE_ABL - SR XS or PCS MMD EEE Capability Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_XS_MASK     (0x1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_XS_SHIFT    (0U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_XS_WIDTH    (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_XS(x)       (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_XS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_XS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_MASK (0x2U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_SHIFT (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_MASK (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_SHIFT (2U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_MASK   (0x8U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_SHIFT  (3U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_WIDTH  (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE(x)     (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_MASK  (0x10U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_SHIFT (4U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_MASK (0x20U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_SHIFT (5U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_MASK  (0x40U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_SHIFT (6U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_MASK)
/*! @} */

/*! @name SR_XS_PCS_EEE_ABL2 - SR PCS MMD EEE Control and Capability2 Register */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_MASK (0x1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_MASK (0x2U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_SHIFT (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_MASK (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_SHIFT (2U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GKX_MASK (0x80U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GKX_SHIFT (7U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GKX_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GKX(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GKX_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GKX_MASK)

#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GKR_MASK (0x100U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GKR_SHIFT (8U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GKR_WIDTH (1U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GKR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GKR_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GKR_MASK)
/*! @} */

/*! @name SR_XS_PCS_EEE_WKERR - SR XS or PCS MMD EEE Wake Error Counter Register This register is present only when EEE_EN = Enabled. */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_SHIFT (0U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_WIDTH (16U)
#define XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_MASK)
/*! @} */

/*! @name SR_XS_PCS_LSTS - SR XS or PCS MMD 10GBASE-X Lane Status Register This register is applicable only for the XS and PCS MMDs when the DWC_xpcs is not configured in the following modes: - 10GBASE-R PCS - KR_Only */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_MASK       (0xFU)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_SHIFT      (0U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_WIDTH      (4U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LNS(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_MASK)

#define XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_MASK       (0x400U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_SHIFT      (10U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_WIDTH      (1U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LBA(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_MASK)

#define XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_MASK       (0x800U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_SHIFT      (11U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_WIDTH      (1U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_TPA(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_MASK)

#define XS_PCS_MMD_SR_XS_PCS_LSTS_LA_MASK        (0x1000U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LA_SHIFT       (12U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LA_WIDTH       (1U)
#define XS_PCS_MMD_SR_XS_PCS_LSTS_LA(x)          (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_LSTS_LA_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_LSTS_LA_MASK)
/*! @} */

/*! @name SR_XS_PCS_TCTRL - SR XS or PCS MMD 10GBASE-X Test Control Register This register is present only with the XS and PCS MMDs when DWC_xpcs is not configured in the following modes: - 10GBASE-R PCS - KR_Only */
/*! @{ */

#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_MASK       (0x3U)
#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_SHIFT      (0U)
#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_WIDTH      (2U)
#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TP(x)         (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_MASK)

#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_MASK      (0x4U)
#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_SHIFT     (2U)
#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_WIDTH     (1U)
#define XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE(x)        (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_SHIFT)) & XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_PCS_ABL - SR PCS MMD Time Sync Capability Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_RX_DLY_ABL_MASK (0x1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_RX_DLY_ABL_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_RX_DLY_ABL_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_RX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_RX_DLY_ABL_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_RX_DLY_ABL_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TX_DLY_ABL_MASK (0x2U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TX_DLY_ABL_SHIFT (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TX_DLY_ABL_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TX_DLY_ABL_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TX_DLY_ABL_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_RX_DLY_MASK (0x4U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_RX_DLY_SHIFT (2U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_RX_DLY_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_RX_DLY(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_RX_DLY_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_RX_DLY_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_TX_DLY_MASK (0x8U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_TX_DLY_SHIFT (3U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_TX_DLY_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_TX_DLY(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_TX_DLY_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_FINE_TX_DLY_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_NUC_MASK (0x400U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_NUC_SHIFT (10U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_NUC_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_NUC(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_NUC_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_NUC_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_MLS_MASK (0x800U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_MLS_SHIFT (11U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_MLS_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_MLS(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_MLS_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_MLS_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_FS_MASK (0x1000U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_FS_SHIFT (12U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_FS_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_FS(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_FS_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_FS_MASK)

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_SFD_MASK (0x2000U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_SFD_SHIFT (13U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_SFD_WIDTH (1U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_SFD(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_SFD_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_TREF_SFD_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR - SR PCS MMD Time Sync Tx Max Delay Lower Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR - SR PCS MMD Time Sync Tx Max Delay Upper Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR - SR PCS MMD Time Sync Tx Min Delay Lower Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR - SR PCS MMD Time Sync Tx Min Delay Upper Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR - SR PCS MMD Time Sync Rx Max Delay Lower Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR - SR PCS MMD Time Sync Rx Max Delay Upper Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR - SR PCS MMD Time Sync Rx Min Delay Lower Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR - SR PCS MMD Time Sync Rx Min Delay Upper Register */
/*! @{ */

#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_MASK (0xFFFFU)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_SHIFT (0U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_WIDTH (16U)
#define XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_SHIFT)) & XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_CTRL1 - VR XS or PCS MMD Digital Control1 Register */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_MASK (0x2U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_MASK (0x4U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_SHIFT (2U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_3_1_MASK (0xE0U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_3_1_SHIFT (5U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_3_1_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_3_1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_3_1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_3_1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_MASK (0x100U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT(x)   (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_MASK (0x200U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_SHIFT (9U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_MASK (0x400U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_SHIFT (10U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_MASK (0x800U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_SHIFT (11U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV(x)  (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_CL37_BP_MASK (0x1000U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_CL37_BP_SHIFT (12U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_CL37_BP_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_CL37_BP(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_CL37_BP_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_CL37_BP_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_MASK (0x2000U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_SHIFT (13U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_MASK (0x4000U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_SHIFT (14U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_MASK (0x8000U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_SHIFT (15U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_CTRL2 - VR XS or PCS MMD Digital Control2 Register */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_3_1_MASK (0xEU)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_3_1_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_3_1_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_3_1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_3_1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_3_1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_MASK (0x10U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_SHIFT (4U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_3_1_MASK (0xE0U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_3_1_SHIFT (5U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_3_1_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_3_1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_3_1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_3_1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PRX_LN_DIS_3_1_MASK (0xE00U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PRX_LN_DIS_3_1_SHIFT (9U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PRX_LN_DIS_3_1_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PRX_LN_DIS_3_1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PRX_LN_DIS_3_1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PRX_LN_DIS_3_1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PTX_LN_DIS_3_1_MASK (0xE000U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PTX_LN_DIS_3_1_SHIFT (13U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PTX_LN_DIS_3_1_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PTX_LN_DIS_3_1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PTX_LN_DIS_3_1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_PTX_LN_DIS_3_1_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_ERRCNT_SEL - VR XS or PCS MMD Digital Error Count Select Register. */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_MASK (0x10U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_SHIFT (4U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_CHKEND_EC_EN_MASK (0x20U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_CHKEND_EC_EN_SHIFT (5U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_CHKEND_EC_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_CHKEND_EC_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_CHKEND_EC_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_CHKEND_EC_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_DSKW_EC_EN_MASK (0x40U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_DSKW_EC_EN_SHIFT (6U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_DSKW_EC_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_DSKW_EC_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_DSKW_EC_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_DSKW_EC_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_TP_MIS_EN_MASK (0x80U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_TP_MIS_EN_SHIFT (7U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_TP_MIS_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_TP_MIS_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_TP_MIS_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_TP_MIS_EN_MASK)
/*! @} */

/*! @name VR_XS_PCS_XAUI_CTRL - VR XS or PCS MMD XAUI Mode Control Register This register is present only when the DWC_xpcs is configured for RXAUI. */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_MASK)

#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_MASK (0x2U)
#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_MASK)
/*! @} */

/*! @name VR_XS_PCS_DEBUG_CTRL - VR XS or PCS MMD Debug Control Register */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_3_1_MASK (0xEU)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_3_1_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_3_1_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_3_1(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_3_1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_3_1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_MASK (0x10U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_SHIFT (4U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_MASK (0x20U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_SHIFT (5U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_MASK (0x40U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_SHIFT (6U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_MASK (0x80U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_SHIFT (7U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_MASK (0x100U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_MASK (0x200U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_SHIFT (9U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SS_CORE_EN_MASK (0x400U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SS_CORE_EN_SHIFT (10U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SS_CORE_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SS_CORE_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SS_CORE_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SS_CORE_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_LOS_SEL_MASK (0x2000U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_LOS_SEL_SHIFT (13U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_LOS_SEL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_LOS_SEL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_LOS_SEL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_LOS_SEL_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_MCTRL0 - VR XS or PCS MMD EEE Mode Control Register This register enables or disables the Energy Efficient Ethernet (EEE) support. */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_MASK (0x2U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_MASK (0x4U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_SHIFT (2U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_MASK (0x8U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_SHIFT (3U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_MASK (0x10U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_SHIFT (4U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_MASK (0x20U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_SHIFT (5U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_MASK (0x40U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_SHIFT (6U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_MASK (0x80U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_SHIFT (7U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_MASK (0xF00U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_WIDTH (4U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_MASK (0xF000U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_SHIFT (12U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_WIDTH (4U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_TXTIMER - VR XS or PCS MMD EEE Tx Timer Register This register is present only if EEE_EN = Enabled. */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_MASK (0x3FU)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_WIDTH (6U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_MASK (0xC0U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_SHIFT (6U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_WIDTH (2U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_MASK (0x1F00U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_WIDTH (5U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_RXTIMER - VR XS or PCS MMD EEE Rx Timer Register This register is present only if EEE_EN = Enabled. */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_MASK (0xFFU)
#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_WIDTH (8U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_MASK (0x3F00U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_WIDTH (6U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_MCTRL1 - VR XS or PCS MMD EEE Mode Control 1 Register This register also controls the Energy Efficient Ethernet (EEE) related settings of DWC_xpcs . */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_MASK (0x1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TXEN_EA_TMR_MASK (0x7EU)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TXEN_EA_TMR_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TXEN_EA_TMR_WIDTH (6U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TXEN_EA_TMR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TXEN_EA_TMR_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TXEN_EA_TMR_MASK)

#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_RXLPI_MASK (0x100U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_RXLPI_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_RXLPI_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_RXLPI(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_RXLPI_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_RXLPI_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_STS - VR XS or PCS MMD Digital Status Register */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LB_ACTIVE_MASK (0x2U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LB_ACTIVE_SHIFT (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LB_ACTIVE_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LB_ACTIVE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_LB_ACTIVE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_LB_ACTIVE_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_MASK (0x1CU)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_SHIFT (2U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_MASK (0x20U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_SHIFT (5U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_MASK (0x40U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_SHIFT (6U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_MASK (0x80U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_SHIFT (7U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_MASK (0x100U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_MASK (0x200U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_SHIFT (9U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_WIDTH (1U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_MASK (0x1C00U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_SHIFT (10U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_MASK)

#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_MASK (0xE000U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_SHIFT (13U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_WIDTH (3U)
#define XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE(x) (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_MASK)
/*! @} */

/*! @name VR_XS_PCS_ICG_ERRCNT1 - VR XS or PCS MMD Invalid Code Group Error Count1 Register The seven error counters EC0-EC6 do not overflow. */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_MASK (0xFFU)
#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_WIDTH (8U)
#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0(x)  (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_MASK)

#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC1_MASK (0xFF00U)
#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC1_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC1_WIDTH (8U)
#define XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC1(x)  (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC1_MASK)
/*! @} */

/*! @name VR_XS_PCS_CDT_STS - VR XS or PCS MMD Comma-Detect Status Register */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH0_MASK  (0xFU)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH0_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH0_WIDTH (4U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH0(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH0_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH0_MASK)

#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH1_MASK  (0xF0U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH1_SHIFT (4U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH1_WIDTH (4U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH1(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH1_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH1_MASK)

#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH2_MASK  (0xF00U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH2_SHIFT (8U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH2_WIDTH (4U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH2(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH2_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH2_MASK)

#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH3_MASK  (0xF000U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH3_SHIFT (12U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH3_WIDTH (4U)
#define XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH3(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH3_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_CDT_STS_CMSH3_MASK)
/*! @} */

/*! @name VR_XS_PCS_MISC_STS - VR XS or PCS MMD Miscellaneous Status Register */
/*! @{ */

#define XS_PCS_MMD_VR_XS_PCS_MISC_STS_BKSH_MASK  (0x7FU)
#define XS_PCS_MMD_VR_XS_PCS_MISC_STS_BKSH_SHIFT (0U)
#define XS_PCS_MMD_VR_XS_PCS_MISC_STS_BKSH_WIDTH (7U)
#define XS_PCS_MMD_VR_XS_PCS_MISC_STS_BKSH(x)    (((uint16_t)(((uint16_t)(x)) << XS_PCS_MMD_VR_XS_PCS_MISC_STS_BKSH_SHIFT)) & XS_PCS_MMD_VR_XS_PCS_MISC_STS_BKSH_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group XS_PCS_MMD_Register_Masks */

/*!
 * @}
 */ /* end of group XS_PCS_MMD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_XS_PCS_MMD_H_) */
