/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_S_AONMIX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 */

#if !defined(PERI_BLK_CTRL_S_AONMIX_H_)
#define PERI_BLK_CTRL_S_AONMIX_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- BLK_CTRL_S_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Peripheral_Access_Layer BLK_CTRL_S_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_S_AONMIX - Size of Registers Arrays */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_COUNT          8u
#define BLK_CTRL_S_AONMIX_CM7_IRQ_COUNT           8u

/** BLK_CTRL_S_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CM33_IRQ_MASK[BLK_CTRL_S_AONMIX_CM33_IRQ_COUNT]; /**< CM33_IRQ_MASK0..CM33_IRQ_MASK7, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CM7_IRQ_MASK[BLK_CTRL_S_AONMIX_CM7_IRQ_COUNT]; /**< CM7_IRQ_MASK0..CM7_IRQ_MASK7, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t EDGELOCK_RESET_REQ_MASK;           /**< EdgeLock reset request mask, offset: 0x58 */
  __IO uint32_t EDGELOCK_IRQ_MASK;                 /**< EdgeLock IRQ request mask, offset: 0x5C */
  __IO uint32_t M33_CFG;                           /**< M33 Configuration, offset: 0x60 */
  __IO uint32_t M33_INITSVTOR;                     /**< M33 INITSVTOR, offset: 0x64 */
  __IO uint32_t M33_INITNSVTOR;                    /**< M33 INITNSVTOR, offset: 0x68 */
       uint8_t RESERVED_1[20];
  __IO uint32_t M7_CFG;                            /**< M7 Configuration, offset: 0x80 */
       uint8_t RESERVED_2[12];
  __IO uint32_t AXBS_AON_CTRL;                     /**< AXBS_AON_CTRL, offset: 0x90 */
       uint8_t RESERVED_3[108];
  __IO uint32_t DAP_ACCESS_STKYBIT;                /**< DAP Access Sticky Bit, offset: 0x100 */
       uint8_t RESERVED_4[12];
  __IO uint32_t LP_HANDSHAKE;                      /**< Low power handshake enable, offset: 0x110 */
  __IO uint32_t EDGELOCK_HALT_ST;                  /**< EdgeLock halt status, offset: 0x114 */
       uint8_t RESERVED_5[8];
  __I  uint32_t ECC_MEM_INIT;                      /**< ECC memory hardware initialization, offset: 0x120 */
       uint8_t RESERVED_6[36];
  __IO uint32_t IOMUXC_DOMAIN_CFG;                 /**< IOMUXC domain configure, offset: 0x148 */
  __IO uint32_t IOMUXC_AON_DOMAIN_CFG;             /**< IOMUXC_AON domain configure, offset: 0x14C */
       uint8_t RESERVED_7[4];
  __IO uint32_t NMI_CTRL;                          /**< NMI control, offset: 0x154 */
  __IO uint32_t S401_NOCLK_CLEAR_CTRL;             /**< s401_ipi_noclk_ref1 clear control, offset: 0x158 */
} BLK_CTRL_S_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_S_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Register_Masks BLK_CTRL_S_AONMIX Register Masks
 * @{
 */

/*! @name CM33_IRQ_MASK - CM33_IRQ_MASK0..CM33_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_SHIFT  (0U)
/*! M - CM33 IRQ MASK
 *  0b00000000000000000000000000000000..Mask IRQ
 *  0b00000000000000000000000000000001..No Mask IRQ
 */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CM33_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_COUNT    (8U)

/*! @name CM7_IRQ_MASK - CM7_IRQ_MASK0..CM7_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_MASK    (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_SHIFT   (0U)
/*! M - CM7 IRQ MASK
 *  0b00000000000000000000000000000000..Mask IRQ
 *  0b00000000000000000000000000000001..No Mask IRQ
 */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CM7_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_COUNT     (8U)

/*! @name EDGELOCK_RESET_REQ_MASK - EdgeLock reset request mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_WDG_RESET_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_WDG_RESET_SHIFT (0U)
/*! WDG_RESET - EdgeLock Wdog reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_WDG_RESET_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_PUF_RESET_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_PUF_RESET_SHIFT (1U)
/*! PUF_RESET - EdgeLock PUF reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_PUF_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_PUF_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_PUF_RESET_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LC_BRICKED_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LC_BRICKED_SHIFT (2U)
/*! LC_BRICKED - EdgeLock LMDA life cycle bricked reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_SYS_FAIL_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_SYS_FAIL_SHIFT (3U)
/*! LMDA_SYS_FAIL - EdgeLock system failure reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_32K_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_32K_SHIFT (4U)
/*! NOCLK_32K - EdgeLock 32k clock loss reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_32K(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_32K_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_32K_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_RESET_REQ_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_RESET_REQ_SHIFT (5U)
/*! LMDA_RESET_REQ - EdgeLock LMDA reset request mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_32K_RESET_REQ_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_32K_RESET_REQ_SHIFT (6U)
/*! LMDA_32K_RESET_REQ - EdgeLock LMDA reset request from 32k clock domain mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF1_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF1_SHIFT (7U)
/*! NOCLK_REF1 - EdgeLock CM33 root clock loss reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF1_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF1_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF2_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF2_SHIFT (8U)
/*! NOCLK_REF2 - EdgeLock OSC 24Mhz clock loss reset mask
 *  0b0..Unmask reset
 *  0b1..Mask reset
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF2_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_RESET_REQ_MASK_NOCLK_REF2_MASK)
/*! @} */

/*! @name EDGELOCK_IRQ_MASK - EdgeLock IRQ request mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_WDG_RESET_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_WDG_RESET_SHIFT (0U)
/*! WDG_RESET - EdgeLock Wdog reset interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_WDG_RESET_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_PUF_RESET_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_PUF_RESET_SHIFT (1U)
/*! PUF_RESET - EdgeLock PUF reset interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_PUF_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_PUF_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_PUF_RESET_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LC_BRICKED_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LC_BRICKED_SHIFT (2U)
/*! LC_BRICKED - EdgeLock LMDA life cycle bricked interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_SYS_FAIL_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_SYS_FAIL_SHIFT (3U)
/*! LMDA_SYS_FAIL - EdgeLock system failure interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_32K_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_32K_SHIFT (4U)
/*! NOCLK_32K - EdgeLock 32k clock loss interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_32K(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_32K_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_32K_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_RESET_REQ_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_RESET_REQ_SHIFT (5U)
/*! LMDA_RESET_REQ - EdgeLock LMDA reset request interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_32K_RESET_REQ_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_32K_RESET_REQ_SHIFT (6U)
/*! LMDA_32K_RESET_REQ - EdgeLock LMDA reset request from 32k clock domain interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF1_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF1_SHIFT (7U)
/*! NOCLK_REF1 - EdgeLock cm33 root clock loss interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF1_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF1_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF2_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF2_SHIFT (8U)
/*! NOCLK_REF2 - EdgeLock OSC 24Mhz clock loss interrupt mask
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF2_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_IRQ_MASK_NOCLK_REF2_MASK)
/*! @} */

/*! @name M33_CFG - M33 Configuration */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK      (0x4U)
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT     (2U)
/*! WAIT - M33 CPU WAIT */
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK  (0x18U)
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT (3U)
/*! TCM_SIZE - M33 TCM SIZE
 *  0b00..Regular TCM, 128KB Code TCM and 128KB Sys TCM
 *  0b01..Double Code TCM, 256KB Code TCM
 *  0b10..Double Sys TCM, 256KB Sys TCM
 *  0b11..Reserved
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK)

#define BLK_CTRL_S_AONMIX_M33_CFG_CORECLK_FORCE_ON_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_M33_CFG_CORECLK_FORCE_ON_SHIFT (5U)
/*! CORECLK_FORCE_ON - Force CM33 core clock on in WAIT mode
 *  0b0..CM33 core clock is off in WAIT mode
 *  0b1..CM33 core clock is on in WAIT mode
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_CORECLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_CORECLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_CORECLK_FORCE_ON_MASK)
/*! @} */

/*! @name M33_INITSVTOR - M33 INITSVTOR */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_INITSVTOR_INITSVTOR_MASK (0x1FFFFFFU)
#define BLK_CTRL_S_AONMIX_M33_INITSVTOR_INITSVTOR_SHIFT (0U)
/*! INITSVTOR - M33 INITSVTOR */
#define BLK_CTRL_S_AONMIX_M33_INITSVTOR_INITSVTOR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_INITSVTOR_INITSVTOR_SHIFT)) & BLK_CTRL_S_AONMIX_M33_INITSVTOR_INITSVTOR_MASK)
/*! @} */

/*! @name M33_INITNSVTOR - M33 INITNSVTOR */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_INITNSVTOR_INITNSVTOR_MASK (0x1FFFFFFU)
#define BLK_CTRL_S_AONMIX_M33_INITNSVTOR_INITNSVTOR_SHIFT (0U)
/*! INITNSVTOR - M33 INITNSVTOR */
#define BLK_CTRL_S_AONMIX_M33_INITNSVTOR_INITNSVTOR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_INITNSVTOR_INITNSVTOR_SHIFT)) & BLK_CTRL_S_AONMIX_M33_INITNSVTOR_INITNSVTOR_MASK)
/*! @} */

/*! @name M7_CFG - M7 Configuration */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK   (0x7U)
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT  (0U)
/*! TCM_SIZE - M7 TCM SIZE
 *  0b000..Regular TCM, 256KB ITCM and 256KB DTCM
 *  0b001..Double ITCM, 512KB ITCM
 *  0b010..Double DTCM, 512KB DTCM
 *  0b100..HALF ITCM, 128KB ITCM and 384KB DTCM
 *  0b101..HALF DTCM, 384KB ITCM and 128KB DTCM
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK       (0x10U)
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT      (4U)
/*! WAIT - M7 CPUWAIT */
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_SHIFT (5U)
/*! CORECLK_FORCE_ON - Force CM7 core clock on in WAIT mode
 *  0b0..CM7 core clock is off in WAIT mode
 *  0b1..CM7 core clock is on in WAIT mode
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_SHIFT (6U)
/*! HCLK_FORCE_ON - CM7 platform AHB clock enable */
#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_INITVTOR_MASK   (0xFFFFFF80U)
#define BLK_CTRL_S_AONMIX_M7_CFG_INITVTOR_SHIFT  (7U)
#define BLK_CTRL_S_AONMIX_M7_CFG_INITVTOR(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_INITVTOR_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_INITVTOR_MASK)
/*! @} */

/*! @name AXBS_AON_CTRL - AXBS_AON_CTRL */
/*! @{ */

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_SHIFT (0U)
/*! FORCE_ROUND_ROBIN - AXBS_AON Force Round Robin
 *  0b0..Enable force round robin(default)
 *  0b1..Disable force round robin
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_SHIFT (1U)
/*! M0_HIGH_PRIORITY - M0 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_SHIFT (2U)
/*! M1_HIGH_PRIORITY - M1 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_SHIFT (3U)
/*! M2_HIGH_PRIORITY - M2 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_SHIFT (4U)
/*! M3_HIGH_PRIORITY - M3 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_SHIFT (5U)
/*! M4_HIGH_PRIORITY - M4 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_SHIFT (6U)
/*! M5_HIGH_PRIORITY - M5 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_SHIFT (7U)
/*! M6_HIGH_PRIORITY - M6 High Priority Control Bit
 *  0b0..Default Priority
 *  0b1..High Priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_MASK)
/*! @} */

/*! @name DAP_ACCESS_STKYBIT - DAP Access Sticky Bit */
/*! @{ */

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_DAP_CTR_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_DAP_CTR_SHIFT (0U)
/*! DAP_CTR - DAP access grant bit controlled by Cortex-M33 ROM, once set "1" will kept "1" unless there is a reset.
 *  0b0..DAP access is not granted by ROM
 *  0b1..DAP access is granted by ROM
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_DAP_CTR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_DAP_CTR_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_DAP_CTR_MASK)
/*! @} */

/*! @name LP_HANDSHAKE - Low power handshake enable */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_RESET_HS_EN_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_RESET_HS_EN_SHIFT (0U)
/*! CM33_RESET_HS_EN - CM33 reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_RESET_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_RESET_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_RESET_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_RESET_HS_EN_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_RESET_HS_EN_SHIFT (1U)
/*! CM7_RESET_HS_EN - CM7 reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_RESET_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_RESET_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_RESET_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_SUSPEND_HS_EN_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_SUSPEND_HS_EN_SHIFT (2U)
/*! CM7_SUSPEND_HS_EN - CM7 suspend exit reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_SUSPEND_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_SUSPEND_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_SUSPEND_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_RESET_HS_EN_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_RESET_HS_EN_SHIFT (3U)
/*! AONMIX_RESET_HS_EN - AONMIX reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_RESET_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_RESET_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_AONMIX_RESET_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_RESET_HS_EN_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_RESET_HS_EN_SHIFT (4U)
/*! WAKEUPMIX_RESET_HS_EN - Wakeupmix reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_RESET_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_RESET_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_WAKEUPMIX_RESET_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_RESET_HS_EN_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_RESET_HS_EN_SHIFT (5U)
/*! MEGAMIX_RESET_HS_EN - Megamix reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_RESET_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_RESET_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_RESET_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_LPM_HS_EN_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_LPM_HS_EN_SHIFT (6U)
/*! MEGAMIX_LPM_HS_EN - Megamix low power mode exit reset handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_LPM_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_LPM_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_MEGAMIX_LPM_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_OFF_HS_EN_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_OFF_HS_EN_SHIFT (7U)
/*! EDGELOCK_CLK_OFF_HS_EN - EDGELOCK clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_SHIFT (8U)
/*! CM33_CLK_OFF_HS_EN - CM33 clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_OFF_HS_EN_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_OFF_HS_EN_SHIFT (9U)
/*! CM7_CLK_OFF_HS_EN - CM7 clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_OFF_HS_EN_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_OFF_HS_EN_SHIFT (10U)
/*! TRDC_CLK_OFF_HS_EN - TRDC clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_OFF_HS_EN_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_OFF_HS_EN_SHIFT (11U)
/*! IEE_CLK_OFF_HS_EN - IEE clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_OFF_HS_EN_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_OFF_HS_EN_SHIFT (12U)
/*! OTFAD1_CLK_OFF_HS_EN - OTFAD1 clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_OFF_HS_EN_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_OFF_HS_EN_SHIFT (13U)
/*! OTFAD2_CLK_OFF_HS_EN - OTFAD2 clock off handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_OFF_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_OFF_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_OFF_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_ON_HS_EN_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_ON_HS_EN_SHIFT (14U)
/*! EDGELOCK_CLK_ON_HS_EN - EDGELOCK clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_EDGELOCK_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_SHIFT (15U)
/*! CM33_CLK_ON_HS_EN - CM33 clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM33_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_ON_HS_EN_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_ON_HS_EN_SHIFT (16U)
/*! CM7_CLK_ON_HS_EN - CM7 clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_CM7_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_ON_HS_EN_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_ON_HS_EN_SHIFT (17U)
/*! TRDC_CLK_ON_HS_EN - TRDC clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_TRDC_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_ON_HS_EN_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_ON_HS_EN_SHIFT (18U)
/*! IEE_CLK_ON_HS_EN - IEE clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_IEE_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_ON_HS_EN_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_ON_HS_EN_SHIFT (19U)
/*! OTFAD1_CLK_ON_HS_EN - OTFAD1 clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD1_CLK_ON_HS_EN_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_ON_HS_EN_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_ON_HS_EN_SHIFT (20U)
/*! OTFAD2_CLK_ON_HS_EN - OTFAD2 clock on handshake enable
 *  0b0..Handshake is not enabled
 *  0b1..Handshake is enabled
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_ON_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_ON_HS_EN_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_OTFAD2_CLK_ON_HS_EN_MASK)
/*! @} */

/*! @name EDGELOCK_HALT_ST - EdgeLock halt status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_ACK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_ACK_SHIFT (0U)
/*! EDGELOCK_HALT_ACK - EdgeLock halt and clock status
 *  0b0..EdgeLock is not fully halted and its clocks must be enabled
 *  0b1..EdgeLock is fully halted indicating clocks may be removed
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_ACK_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_ACK_MASK)

#define BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_EXIT_IRQ_CLR_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_EXIT_IRQ_CLR_SHIFT (8U)
/*! EDGELOCK_HALT_EXIT_IRQ_CLR - EdgeLock halt exit interrupt clear
 *  0b0..Remove the clear signal. This bit is not self-clearing and need SW to clear.
 *  0b1..Clear EdgeLock halt exit interrupt
 */
#define BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_EXIT_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_EXIT_IRQ_CLR_SHIFT)) & BLK_CTRL_S_AONMIX_EDGELOCK_HALT_ST_EDGELOCK_HALT_EXIT_IRQ_CLR_MASK)
/*! @} */

/*! @name ECC_MEM_INIT - ECC memory hardware initialization */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM1_INIT_DONE_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM1_INIT_DONE_SHIFT (16U)
/*! OCRAM1_INIT_DONE - OCRAM1 initialization status
 *  0b0..OCRAM1 memory is under initialization
 *  0b1..OCRAM1 memory initialization is complete
 */
#define BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM1_INIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM1_INIT_DONE_SHIFT)) & BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM1_INIT_DONE_MASK)

#define BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM2_INIT_DONE_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM2_INIT_DONE_SHIFT (24U)
/*! OCRAM2_INIT_DONE - OCRAM2 initialization status
 *  0b0..OCRAM2 memory is under initialization
 *  0b1..OCRAM2 memory initialization is complete
 */
#define BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM2_INIT_DONE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM2_INIT_DONE_SHIFT)) & BLK_CTRL_S_AONMIX_ECC_MEM_INIT_OCRAM2_INIT_DONE_MASK)
/*! @} */

/*! @name IOMUXC_DOMAIN_CFG - IOMUXC domain configure */
/*! @{ */

#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID0_MASK (0xFU)
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID0_SHIFT (0U)
/*! DID0 - Domain ID 0 */
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID0_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID0_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID1_MASK (0xF0U)
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID1_SHIFT (4U)
/*! DID1 - Domain ID 1 */
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID1_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID1_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID2_MASK (0xF00U)
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID2_SHIFT (8U)
/*! DID2 - Domain ID 2 */
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID2_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID2_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID3_MASK (0xF000U)
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID3_SHIFT (12U)
/*! DID3 - Domain ID 3 */
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID3_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_DID3_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_LOCK_MASK (0x80000000U)
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_LOCK_SHIFT (31U)
/*! LOCK - Lock bit */
#define BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_LOCK_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_DOMAIN_CFG_LOCK_MASK)
/*! @} */

/*! @name IOMUXC_AON_DOMAIN_CFG - IOMUXC_AON domain configure */
/*! @{ */

#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID0_MASK (0xFU)
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID0_SHIFT (0U)
/*! DID0 - Domain ID 0 */
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID0_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID0_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID1_MASK (0xF0U)
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID1_SHIFT (4U)
/*! DID1 - Domain ID 1 */
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID1_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID1_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID2_MASK (0xF00U)
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID2_SHIFT (8U)
/*! DID2 - Domain ID 2 */
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID2_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID2_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID3_MASK (0xF000U)
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID3_SHIFT (12U)
/*! DID3 - Domain ID 3 */
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID3_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_DID3_MASK)

#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_LOCK_MASK (0x80000000U)
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_LOCK_SHIFT (31U)
/*! LOCK - Lock bit */
#define BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_LOCK_SHIFT)) & BLK_CTRL_S_AONMIX_IOMUXC_AON_DOMAIN_CFG_LOCK_MASK)
/*! @} */

/*! @name NMI_CTRL - NMI control */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_CTRL_M7_NMI_MASK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_CTRL_M7_NMI_MASK_SHIFT (0U)
/*! M7_NMI_MASK - Mask CM7 NMI pin input
 *  0b0..NMI input from IO to CM7 is not blocked
 *  0b1..NMI input from IO to CM7 is blocked
 */
#define BLK_CTRL_S_AONMIX_NMI_CTRL_M7_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CTRL_M7_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CTRL_M7_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_CTRL_M33_NMI_MASK_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_CTRL_M33_NMI_MASK_SHIFT (1U)
/*! M33_NMI_MASK - Mask CM33 NMI pin input
 *  0b0..NMI input from IO to CM33 is not blocked
 *  0b1..NMI input from IO to CM33 is blocked
 */
#define BLK_CTRL_S_AONMIX_NMI_CTRL_M33_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CTRL_M33_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CTRL_M33_NMI_MASK_MASK)
/*! @} */

/*! @name S401_NOCLK_CLEAR_CTRL - s401_ipi_noclk_ref1 clear control */
/*! @{ */

#define BLK_CTRL_S_AONMIX_S401_NOCLK_CLEAR_CTRL_ref1_slow_clear_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_S401_NOCLK_CLEAR_CTRL_ref1_slow_clear_SHIFT (0U)
/*! ref1_slow_clear - clear the interrupt or reset source */
#define BLK_CTRL_S_AONMIX_S401_NOCLK_CLEAR_CTRL_ref1_slow_clear(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_NOCLK_CLEAR_CTRL_ref1_slow_clear_SHIFT)) & BLK_CTRL_S_AONMIX_S401_NOCLK_CLEAR_CTRL_ref1_slow_clear_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_S_AONMIX_H_ */

